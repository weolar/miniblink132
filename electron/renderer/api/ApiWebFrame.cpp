// Copyright (c) 2017 weolar, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/nodeblink.h"
#include "mbvip/core/mb.h"
#include "content/renderer/V8ValueConverterImpl.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/promise.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/arguments.h"
#include "electron/common/gin_helper/CallbackConverter.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/renderer/api/ApiContextBridge.h"
#include "electron/renderer/api/ObjectCache.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/web_script_source.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/renderer/platform/bindings/dom_wrapper_world.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include <vector>

namespace gin_helper {

template <> struct Converter<blink::WebCssOrigin> {
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, blink::WebCssOrigin* out)
    {
        std::string cssOrigin;
        if (!ConvertFromV8(isolate, val, &cssOrigin))
            return false;
        if (cssOrigin == "user") {
            *out = blink::WebCssOrigin::kUser;
        } else if (cssOrigin == "author") {
            *out = blink::WebCssOrigin::kAuthor;
        } else {
            return false;
        }
        return true;
    }
};

}

namespace atom {

namespace {

class ScriptExecutionCallback {
public:
    // for compatibility with the older version of this, error is after result
    using CompletionCallback = base::OnceCallback<void(const v8::Local<v8::Value>& result, const v8::Local<v8::Value>& error)>;

    explicit ScriptExecutionCallback(gin_helper::Promise<v8::Local<v8::Value>> promise, CompletionCallback callback)
        : m_promise(std::move(promise))
        , m_callback(std::move(callback))
    {
    }

    ~ScriptExecutionCallback() = default;

    ScriptExecutionCallback(const ScriptExecutionCallback&) = delete;
    ScriptExecutionCallback& operator=(const ScriptExecutionCallback&) = delete;

    void opyResultToCallingContextAndFinalize(v8::Isolate* isolate, const v8::Local<v8::Object>& result)
    {
        v8::MaybeLocal<v8::Value> maybeResult;
        bool success = true;
        std::string errorMessage = "An unknown exception occurred while getting the result of the script";
        {
            v8::TryCatch tryCatch(isolate);
            api::context_bridge::ObjectCache object_cache;
            maybeResult = api::PassValueToOtherContext(result->GetCreationContextChecked(), m_promise.GetContext(), result, &object_cache, false, 0);
            if (maybeResult.IsEmpty() || tryCatch.HasCaught()) {
                success = false;
            }
            if (tryCatch.HasCaught()) {
                auto message = tryCatch.Message();

                if (!message.IsEmpty()) {
                    gin_helper::ConvertFromV8(isolate, message->Get(), &errorMessage);
                }
            }
        }
        if (!success) {
            // Failed convert so we send undefined everywhere
            if (m_callback) {
                std::move(m_callback)
                    .Run(v8::Undefined(isolate), v8::Exception::Error(v8::String::NewFromUtf8(isolate, errorMessage.c_str()).ToLocalChecked()));
            }
            m_promise.RejectWithErrorMessage(errorMessage);
        } else {
            v8::Local<v8::Context> context = m_promise.GetContext();
            v8::Context::Scope context_scope(context);
            v8::Local<v8::Value> clonedValue = maybeResult.ToLocalChecked();

            if (m_callback)
                std::move(m_callback).Run(clonedValue, v8::Undefined(isolate));
            m_promise.Resolve(clonedValue);
        }
    }

    void completed(v8::Local<v8::Context> context, std::optional<base::Value> result, base::TimeTicks)
    {
        v8::Isolate* isolate = m_promise.isolate();
        if (result.has_value()) {
            if (/*!result[0].IsEmpty()*/true) {
                //v8::Local<v8::Value> value = result.value();
                const base::Value& valueTemp = result.value();
                std::unique_ptr<content::V8ValueConverter> converter = content::V8ValueConverter::Create();
                v8::Local<v8::Value> value = converter->ToV8Value(base::ValueView(valueTemp), context);

                // Either the result was created in the same world as the caller
                // or the result is not an object and therefore does not have a
                // prototype chain to protect
                bool shouldCloneValue
                    = !(value->IsObject() && m_promise.GetContext() == context/*value.As<v8::Object>()->GetCreationContextChecked()*/) 
                    && value->IsObject();
                if (shouldCloneValue) {
                    opyResultToCallingContextAndFinalize(isolate, value.As<v8::Object>());
                } else {
                    // Right now only single results per frame is supported.
                    if (m_callback)
                        std::move(m_callback).Run(value, v8::Undefined(isolate));
                    m_promise.Resolve(value);
                }
            } else {
                const char errorMessage[] = "Script failed to execute, this normally means an error "
                                            "was thrown. Check the renderer console for the error.";
                if (!m_callback.is_null()) {
                    v8::Local<v8::Context> context = m_promise.GetContext();
                    v8::Context::Scope context_scope(context);
                    std::move(m_callback).Run(v8::Undefined(isolate), v8::Exception::Error(v8::String::NewFromUtf8(isolate, errorMessage).ToLocalChecked()));
                }
                m_promise.RejectWithErrorMessage(errorMessage);
            }
        } else {
            const char errorMessage[] = "WebFrame was removed before script could run. This normally means the underlying frame was destroyed";
            if (!m_callback.is_null()) {
                v8::Local<v8::Context> context = m_promise.GetContext();
                v8::Context::Scope context_scope(context);
                std::move(m_callback).Run(v8::Undefined(isolate), v8::Exception::Error(v8::String::NewFromUtf8(isolate, errorMessage).ToLocalChecked()));
            }
            m_promise.RejectWithErrorMessage(errorMessage);
        }
        delete this;
    }

private:
    gin_helper::Promise<v8::Local<v8::Value>> m_promise;
    CompletionCallback m_callback;
};

} // namespace

class WebFrame : public mate::EventEmitter<WebFrame> {
public:
    explicit WebFrame(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<WebFrame>::InitWith(isolate, wrapper);

        m_zoomLevel = 0;
        m_zoomFactor = 1;
    }

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);

        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "WebFrame").ToLocalChecked());
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("registerEmbedderCustomElement", &WebFrame::registerEmbedderCustomElementApi);
        builder.SetMethod("setZoomFactor", &WebFrame::setZoomFactorApi);
        builder.SetMethod("getZoomFactor", &WebFrame::getZoomFactorApi);
        builder.SetMethod("getZoomLevel", &WebFrame::getZoomLevelApi);
        builder.SetMethod("setZoomLevel", &WebFrame::setZoomLevelApi);
        builder.SetMethod("setZoomLevelLimits", &WebFrame::setZoomLevelLimitsApi);
        builder.SetMethod("setSpellCheckProvider", &WebFrame::setSpellCheckProviderApi);
        builder.SetMethod("registerURLSchemeAsSecure", &WebFrame::registerURLSchemeAsSecureApi);
        builder.SetMethod("registerURLSchemeAsBypassingCSP", &WebFrame::registerURLSchemeAsBypassingCSPApi);
        builder.SetMethod("registerURLSchemeAsPrivileged", &WebFrame::registerURLSchemeAsPrivilegedApi);
        builder.SetMethod("insertText", &WebFrame::insertTextApi);
        builder.SetMethod("executeJavaScript", &WebFrame::executeJavaScriptApi);
        builder.SetMethod("setMaxListeners", &WebFrame::setMaxListenersApi);
        builder.SetMethod("setVisualZoomLevelLimits", &WebFrame::setVisualZoomLevelLimitsApi);
        builder.SetMethod("setLayoutZoomLevelLimits", &WebFrame::setLayoutZoomLevelLimitsApi);
        builder.SetMethod("removeInsertedCSS", &WebFrame::removeInsertedCSSApi);
        builder.SetMethod("insertCSS", &WebFrame::insertCSSApi);

        constructor.Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "WebFrame").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

    v8::Local<v8::Value> registerEmbedderCustomElementApi(const std::string& name, v8::Local<v8::Object> options)
    {
        mbWebView webview = mbGetWebViewForCurrentContext();
        mbWebFrameHandle mainFrame = mbWebFrameGetMainFrame(webview);

        v8::Persistent<v8::Value> result;
        mbRegisterEmbedderCustomElement(webview, mainFrame, name.c_str(), &options, &result);
        v8::Local<v8::Value> elementConstructor = result.Get(isolate());
        result.Reset();
        return elementConstructor;
    }

    void registerElementResizeCallbackApi(/*int element_instance_id, const GuestViewContainer::ResizeCallback& callback*/)
    {
        //         auto guest_view_container = GuestViewContainer::FromID(element_instance_id);
        //         if (guest_view_container)
        //             guest_view_container->RegisterElementResizeCallback(callback);
    }

    void setVisualZoomLevelLimitsApi(int Level1, int Level2)
    {
    }

    void setLayoutZoomLevelLimitsApi(int Level1, int Level2)
    {
    }

    void setZoomFactorApi(float factor)
    {
        m_zoomFactor = factor;
    }

    float getZoomFactorApi() const
    {
        return m_zoomFactor;
    }

    void setZoomLevelLimitsApi(float minimumLevel, float maximumLevel)
    {
        OutputDebugStringA("setZoomLevelLimitsApi\n");
    }

    void setZoomLevelApi(float level)
    {
        m_zoomLevel = level;
    }

    float getZoomLevelApi() const
    {
        return m_zoomLevel;
    }

    void setSpellCheckProviderApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        OutputDebugStringA("setSpellCheckProviderApi\n");
    }

    void registerURLSchemeAsSecureApi(const std::string& scheme)
    {
        OutputDebugStringA("registerURLSchemeAsSecureApi\n");
    }

    void registerURLSchemeAsBypassingCSPApi(const std::string& scheme)
    {
        OutputDebugStringA("registerURLSchemeAsBypassingCSPApi\n");
    }
    void registerURLSchemeAsPrivilegedApi(const std::string& scheme)
    {
        OutputDebugStringA("registerURLSchemeAsPrivilegedApi\n");
    }

    void insertTextApi(const std::string& text)
    {
        OutputDebugStringA("insertTextApi\n");
    }

    std::string insertCSSApi(const std::string& css, gin_helper::Arguments* args)
    {
        blink::WebCssOrigin cssOrigin = blink::WebCssOrigin::kAuthor;
        gin_helper::Dictionary options(isolate());
        if (args->GetNext(&options))
            options.Get("cssOrigin", &cssOrigin);

        v8::Local<v8::Context> context = isolate()->GetCurrentContext();

        blink::WebLocalFrame* webFrame = blink::WebLocalFrame::FrameForContext(context);
        if (webFrame)
            return webFrame->GetDocument().InsertStyleSheet(blink::WebString::FromUTF8(css), nullptr, (blink::WebCssOrigin)cssOrigin).Utf8();
        return std::string();
    }

    void removeInsertedCSSApi(const std::string& key)
    {
        v8::Local<v8::Context> context = isolate()->GetCurrentContext();
        blink::WebLocalFrame* webFrame = blink::WebLocalFrame::FrameForContext(context);
        if (webFrame) {
            webFrame->GetDocument().RemoveInsertedStyleSheet(blink::WebString::FromUTF8(key));
        }
    }

    v8::Local<v8::Promise> executeJavaScriptApi(gin_helper::Arguments* gin_args, const std::string& code)
    {
        gin_helper::Arguments* args = static_cast<gin_helper::Arguments*>(gin_args);

        gin_helper::Promise<v8::Local<v8::Value>> promise(isolate());
        v8::Local<v8::Promise> handle = promise.GetHandle();

        v8::Local<v8::Context> context = isolate()->GetCurrentContext();
        blink::WebLocalFrame* webFrame = blink::WebLocalFrame::FrameForContext(context);

        const blink::WebScriptSource source(blink::WebString::FromUTF8(code));

        bool has_user_gesture = false;
        args->GetNext(&has_user_gesture);

        ScriptExecutionCallback::CompletionCallback completionCallback;
        args->GetNext(&completionCallback);

        ScriptExecutionCallback* self = new ScriptExecutionCallback(std::move(promise), std::move(completionCallback));

        std::vector<blink::WebScriptSource> sourcesTemp;
        sourcesTemp.push_back(source);
        base::span<const blink::WebScriptSource> sources(sourcesTemp.begin(), sourcesTemp.end());
        webFrame->RequestExecuteScript(
            blink::DOMWrapperWorld::kMainWorldId, 
            sources,
            has_user_gesture ? blink::mojom::UserActivationOption::kActivate : blink::mojom::UserActivationOption::kDoNotActivate,
            blink::mojom::EvaluationTiming::kSynchronous, 
            blink::mojom::LoadEventBlockingOption::kDoNotBlock, 
            //base::NullCallback(),
            base::BindOnce(&ScriptExecutionCallback::completed, base::Unretained(self), context),
            blink::BackForwardCacheAware::kAllow,
            blink::mojom::WantResultOption::kWantResult, 
            blink::mojom::PromiseResultOption::kDoNotWait);

        return handle;
    }

    // callback, code, hasUserGesture
    void executeJavaScriptApi2(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Local<v8::Context> context = isolate()->GetCurrentContext();
        if (3 != args.Length())
            return;

        std::string codeString;
        if (args[0]->IsString()) {
            v8::String::Utf8Value code(isolate(), args[0]);
            codeString = *code;
        }

        bool hasUserGesture = false;
        if (args[1]->IsBoolean()) {
            v8::Local<v8::Boolean> hasUserGestureValue = args[1]->ToBoolean(isolate());
            hasUserGesture = hasUserGestureValue->Value();
        }

        v8::Persistent<v8::Value> executeJavaScriptCallback;
        if (args[2]->IsFunction())
            executeJavaScriptCallback.Reset(args.GetIsolate(), args[2]);
        else
            executeJavaScriptCallback.Reset();

        v8::HandleScope handleScope(isolate());
        v8::Function* callback = nullptr;
        v8::Local<v8::Value> f;
        if (codeString.empty() && !executeJavaScriptCallback.IsEmpty()) {
            f = executeJavaScriptCallback.Get(isolate());
            callback = v8::Function::Cast(*(f));
            callback->Call(context, v8::Undefined(isolate()), 0, nullptr);
            return;
        }

        blink::WebScriptSource code(blink::WebString::FromUTF8(codeString));
        v8::Local<v8::Value> result;

        blink::WebLocalFrame* mainFrame = blink::WebLocalFrame::FrameForContext(context);
        context = mainFrame->MainWorldScriptContext();
        v8::Context::Scope contextScope(context);
        result = mainFrame->ExecuteScriptAndReturnValue(code);

        if (executeJavaScriptCallback.IsEmpty())
            return;

        v8::Local<v8::Value> argv[1];
        f = executeJavaScriptCallback.Get(isolate());
        callback = v8::Function::Cast(*(f));
        callback->Call(context, v8::Undefined(isolate()), 0, nullptr);

        argv[0] = result;
        callback->Call(context, v8::Undefined(isolate()), 1, argv);
    }

    void setMaxListenersApi(int number)
    {
        //OutputDebugStringA("setMaxListenersApi\n");
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (args.IsConstructCall()) {
            new WebFrame(isolate, args.This());
            args.GetReturnValue().Set(args.This());
            return;
        }
    }

public:
    static gin::WrapperInfo kWrapperInfo;
    static v8::Persistent<v8::Function> constructor;

    float m_zoomFactor;
    float m_zoomLevel;
};

v8::Persistent<v8::Function> WebFrame::constructor;
gin_helper::WrapperInfo WebFrame::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

void initializeWebFrameApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> target, v8::Local<v8::Context> context, void* priv)
{
    WebFrame::init(context->GetIsolate(), exports);
}

} // namespace

static const char RenererWebFrameNative[] = "console.log('RenererWebFrameNative');;";
static NodeNative nativeRenererWebFrameNative { "WebFrame", RenererWebFrameNative, sizeof(RenererWebFrameNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_renerer_webframe, atom::initializeWebFrameApi, &nativeRenererWebFrameNative)
