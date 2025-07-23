
#include "electron/browser/api/ApiWebFrameMain.h"

#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/gin_helper/error_thrower.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/promise.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/converter.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/public/mojom/page/page_visibility_state.mojom-shared.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/browser/WebFrameMain.h"
#include "mbvip/core/mb.h"
#include "base/process/process_handle.h"
#include "base/values.h"
#include "base/no_destructor.h"

namespace blink {
LocalFrame* FromFrameTokenHash(const size_t& frameTokenHash);
}

namespace atom {

gin_helper::WrapperInfo ApiWebFrameMain::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> s_WebFrameMainConstructor;

ApiWebFrameMain::ApiWebFrameMain(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, intptr_t frameId)
{
    Wrappable::InitWith(isolate, wrapper);
    m_frameId = frameId;
}

ApiWebFrameMain::~ApiWebFrameMain()
{
}

ApiWebFrameMain* ApiWebFrameMain::createOrGet(intptr_t frameId)
{
    content::WebFrameMain* webFrameMain = content::WebFrameMain::fromFrameId(frameId);
    if (webFrameMain)
        return create(webFrameMain->m_frameId);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Value> arg0 = gin_helper::Converter<intptr_t>::ToV8(isolate, frameId);
    //gin_helper::Dictionary options(isolate, arg0);
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { arg0 }; // { gin_helper::ConvertToV8(isolate, options) };
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_WebFrameMainConstructor);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into ApiWebFrameMain::ApiWebFrameMain
    if (obj.IsEmpty())
        return nullptr;

    gin_helper::WrappableBase* wrap = gin_helper::WrappableBase::GetNativePtr(obj.ToLocalChecked(), &ApiWebFrameMain::kWrapperInfo);
    return (ApiWebFrameMain*)wrap;
}

ApiWebFrameMain* ApiWebFrameMain::create(intptr_t frameId)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Value> arg0 = gin_helper::Converter<intptr_t>::ToV8(isolate, frameId);
    //gin_helper::Dictionary options(isolate, arg0);
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { arg0 }; // { gin_helper::ConvertToV8(isolate, options) };
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_WebFrameMainConstructor);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into ApiWebFrameMain::ApiWebFrameMain
    if (obj.IsEmpty())
        return nullptr;

    gin_helper::WrappableBase* wrap = gin_helper::WrappableBase::GetNativePtr(obj.ToLocalChecked(), &ApiWebFrameMain::kWrapperInfo);
    return (ApiWebFrameMain*)wrap;
}

void ApiWebFrameMain::newFunction(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();

    CHECK(info.IsConstructCall());
    if (info.Length() != 1)
        return;

    intptr_t frameId = 0;
    gin_helper::Converter<intptr_t>::FromV8(isolate, info[0], &frameId);

    new ApiWebFrameMain(isolate, info.This(), frameId); // v8管理内存回收
    info.GetReturnValue().Set(info.This());
}

static blink::WebLocalFrameImpl* getWebLocalFrameImplById(intptr_t frameId)
{
    blink::LocalFrame* blinkFrame = blink::FromFrameTokenHash((size_t)(frameId));
    if (!blinkFrame)
        return nullptr;
    blink::WebLocalFrameImpl* frame = blink::WebLocalFrameImpl::FromFrame(blinkFrame);
    if (!frame)
        return nullptr;
    return frame;
}

void ApiWebFrameMain::reloadApi()
{
    blink::WebLocalFrameImpl* frame = getWebLocalFrameImplById(m_frameId);
    if (!frame)
        return;
    frame->StartReload(blink::WebFrameLoadType::kReload);
}

v8::Local<v8::Promise> ApiWebFrameMain::executeJavaScriptApi(gin_helper::Arguments* args, const std::string& code)
{
    gin_helper::Promise<base::Value> promise(args->isolate());
    v8::Local<v8::Promise> handle = promise.GetHandle();

    blink::WebLocalFrameImpl* frame = getWebLocalFrameImplById(m_frameId);
    if (!frame) {
        args->ThrowTypeError("userGesture must be a boolean");
        return handle;
    }
    content::WebLocalFrameClientImpl* client = (content::WebLocalFrameClientImpl*)(frame->Client());
    mojo::Remote<blink::mojom::blink::LocalFrame>& mojoLocalFrame = client->getLocalFrameRemote();

    // Optional userGesture parameter
    bool isUserGesture;
    if (!args->PeekNext().IsEmpty()) {
        if (args->PeekNext()->IsBoolean()) {
            args->GetNext(&isUserGesture);
        } else {
            args->ThrowTypeError("userGesture must be a boolean");
            return handle;
        }
    } else {
        isUserGesture = false;
    }

    //     if (render_frame_disposed_) {
    //         promise.RejectWithErrorMessage("Render frame was disposed before WebFrameMain could be accessed");
    //         return handle;
    //     }

    mojoLocalFrame->JavaScriptExecuteRequestForTests(
        ::WTF::String::FromUTF8(code),
        isUserGesture, 
        true /* resolve_promises */,
        true /*honor_js_content_settings*/,
        0 /*content::ISOLATED_WORLD_ID_GLOBAL*/,
        base::BindOnce(
            [](gin_helper::Promise<base::Value> promise, blink::mojom::JavaScriptExecutionResultType type, base::Value value) {
                v8::Isolate* isolate = v8::Isolate::GetCurrent();
                v8::HandleScope scope(isolate);
                if (type == blink::mojom::JavaScriptExecutionResultType::kSuccess) {
                    promise.Resolve(std::move(value));
                } else {
                    promise.Reject(gin_helper::ConvertToV8(isolate, value));
                }
            },
            std::move(promise)));
    return handle;
}

intptr_t ApiWebFrameMain::getFrameTreeNodeIdApi() const
{
    return m_frameId;
}

std::string ApiWebFrameMain::getNameApi() const
{
    return content::WebFrameMain::getName(m_frameId);
}

intptr_t ApiWebFrameMain::getOSProcessIdApi() const
{
    return base::GetCurrentProcId();
}

intptr_t ApiWebFrameMain::getRoutingIdApi() const
{
    return base::GetCurrentProcId();
}

std::string ApiWebFrameMain::getUrlApi() const
{
    return content::WebFrameMain::getUrl(m_frameId);
}

std::string ApiWebFrameMain::getPageVisibilityStateApi() const
{
    blink::mojom::blink::PageVisibilityState state = content::WebFrameMain::getPageVisibilityState(m_frameId);
    std::string visibility;
    switch (state) {
    case blink::mojom::PageVisibilityState::kVisible:
        visibility = "visible";
        break;
    case blink::mojom::PageVisibilityState::kHidden:
    case blink::mojom::PageVisibilityState::kHiddenButPainting:
        visibility = "hidden";
        break;
    }
    return visibility;
}

v8::Local<v8::Value> ApiWebFrameMain::getTopApi() const
{
    intptr_t ret = content::WebFrameMain::getTopFrameId(m_frameId);
    return gin_helper::ConvertToV8(v8::Isolate::GetCurrent(), ret);
}

v8::Local<v8::Value> ApiWebFrameMain::getParentApi() const
{
    intptr_t ret = content::WebFrameMain::getParentFrameId(m_frameId);
    return gin_helper::ConvertToV8(v8::Isolate::GetCurrent(), ret);
}

v8::Local<v8::Value> ApiWebFrameMain::getFramesApi() const
{
    std::vector<v8::Local<v8::Value>> elements;
    std::vector<content::WebFrameMain*> ret = content::WebFrameMain::getChildrenFrames(m_frameId);
    for (size_t i = 0; i < ret.size(); ++i) {
        elements.push_back(createOrGet(ret[i]->m_frameId)->GetWrapper(isolate()));
    }
    return v8::Array::New(isolate(), elements.data(), elements.size());
}

v8::Local<v8::Value> ApiWebFrameMain::getFramesInSubtreeApi() const
{
    std::vector<v8::Local<v8::Value>> elements;
    std::vector<content::WebFrameMain*> ret = content::WebFrameMain::getFramesInSubtree(m_frameId);
    for (size_t i = 0; i < ret.size(); ++i) {
        elements.push_back(createOrGet(ret[i]->m_frameId)->GetWrapper(isolate()));
    }
    return v8::Array::New(isolate(), elements.data(), elements.size());
}

void ApiWebFrameMain::fromIdApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (2 != info.Length())
        return;

    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
    v8::Local<v8::Value> arg0 = info[0];
    if (!arg0->IsNumber())
        return;
    int64_t renderProcessId = arg0->IntegerValue(context).ToChecked();

    v8::Local<v8::Value> arg1 = info[1];
    if (!arg1->IsNumber())
        return;
    int64_t renderFrameId = arg1->IntegerValue(context).ToChecked();

    content::WebFrameMain* frame = content::WebFrameMain::fromFrameId((intptr_t)renderFrameId);
    if (!frame)
        return;
    ApiWebFrameMain* frameApi = ApiWebFrameMain::createOrGet(renderFrameId);
    if (!frameApi)
        return;
    info.GetReturnValue().Set(frameApi->GetWrapper(info.GetIsolate()));
}

void ApiWebFrameMain::fromIDOrNullApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    fromIdApi(info);
}

void ApiWebFrameMain::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, ApiWebFrameMain::newFunction);
    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "WebFrameMain").ToLocalChecked());

    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("executeJavaScript", &ApiWebFrameMain::executeJavaScriptApi);
    builder.SetMethod("reload", &ApiWebFrameMain::reloadApi);
    //     builder.SetMethod("_send", &ApiWebFrameMain::Send);
    //     builder.SetMethod("_postMessage", &ApiWebFrameMain::PostMessage);
    builder.SetProperty("frameTreeNodeId", &ApiWebFrameMain::getFrameTreeNodeIdApi);
    builder.SetProperty("name", &ApiWebFrameMain::getNameApi);
    builder.SetProperty("osProcessId", &ApiWebFrameMain::getOSProcessIdApi);
    builder.SetProperty("processId", &ApiWebFrameMain::getOSProcessIdApi);
    builder.SetProperty("routingId", &ApiWebFrameMain::getRoutingIdApi);
    builder.SetProperty("url", &ApiWebFrameMain::getUrlApi);
    //     builder.SetProperty("origin", &ApiWebFrameMain::Origin);
    builder.SetProperty("visibilityState", &ApiWebFrameMain::getPageVisibilityStateApi);
    builder.SetProperty("top", &ApiWebFrameMain::getTopApi);
    builder.SetProperty("parent", &ApiWebFrameMain::getParentApi);
    builder.SetProperty("frames", &ApiWebFrameMain::getFramesApi);
    builder.SetProperty("framesInSubtree", &ApiWebFrameMain::getFramesInSubtreeApi);

    //gin_helper::Dictionary dict(isolate, target);
    //dict.SetMethod("_fork", &ApiWebFrameMain::create);

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();
    target->Set(context, v8::String::NewFromUtf8(isolate, "WebFrameMain").ToLocalChecked(), prototypFunc);

    gin_helper::Dictionary dict(isolate, target); // 导出静态函数
    dict.SetMethod("fromId", &fromIdApi);
    dict.SetMethod("fromIdOrNull", &fromIDOrNullApi);

    s_WebFrameMainConstructor.Reset(isolate, prototypFunc);
}

static void initializeApiWebFrameMain(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    ApiWebFrameMain::init(context->GetIsolate(), target, nullptr);
}

static const char ApiWebFrameMainSricpt[] = "exports = {};";
static NodeNative nativeApiWebFrameMainNative { "WebFrameMain", ApiWebFrameMainSricpt, sizeof(ApiWebFrameMainSricpt) - 1 };
NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_web_frame_main, initializeApiWebFrameMain, &nativeApiWebFrameMainNative)

} // atom