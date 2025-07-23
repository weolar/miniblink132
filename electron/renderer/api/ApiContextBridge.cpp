// Copyright (c) 2019 Slack Technologies, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/renderer/api/ApiContextBridge.h"

#include "electron/common/WorldIDs.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/mbexport.h"
#include "electron/nodeblink.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "mbvip/core/mb.h"
#include "electron/common/gin_helper/converter.h"
#include "electron/common/gin_helper/arguments.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/promise.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include <windows.h>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

BOOL MB_CALL_TYPE mbGetContextByV8Object(void* isolate, void* obj, int worldID, v8ContextPtr cxtOut);
BOOL MB_CALL_TYPE mbPassWebElementValueToOtherContext(void* val, void* destCtx, void* outVal);

namespace features {
//const base::Feature kContextBridgeMutability{ "ContextBridgeMutability", base::FEATURE_DISABLED_BY_DEFAULT };
}

namespace content {
void printCallstackIsolate(v8::Isolate* isolate);
}

namespace atom {

extern int testEventEmitter;

//content::RenderFrame* GetRenderFrame(v8::Local<v8::Object> value);

namespace api {

namespace context_bridge {

const char* const kProxyFunctionPrivateKey = "electron_contextBridge_proxy_fn";
const char* const kSupportsDynamicPropertiesPrivateKey = "electron_contextBridge_supportsDynamicProperties";
const char* const kOriginalFunctionPrivateKey = "electron_contextBridge_original_fn";

} // namespace context_bridge

namespace {

static int kMaxRecursion = 1000;

// Returns true if |maybe| is both a value, and that value is true.
inline bool IsTrue(v8::Maybe<bool> maybe)
{
    return maybe.IsJust() && maybe.FromJust();
}

// Sourced from "extensions/renderer/v8_schema_registry.cc"
// Recursively freezes every v8 object on |object|.
bool DeepFreeze(const v8::Local<v8::Object>& object, const v8::Local<v8::Context>& context, std::set<int> frozen = std::set<int>())
{
    int hash = object->GetIdentityHash();
    if (frozen.find(hash) != frozen.end())
        return true;
    frozen.insert(hash);

    v8::Local<v8::Array> property_names = object->GetOwnPropertyNames(context).ToLocalChecked();
    for (uint32_t i = 0; i < property_names->Length(); ++i) {
        v8::Local<v8::Value> child = object->Get(context, property_names->Get(context, i).ToLocalChecked()).ToLocalChecked();
        if (child->IsObject() && !child->IsTypedArray()) {
            if (!DeepFreeze(child.As<v8::Object>(), context, frozen))
                return false;
        }
    }
    return IsTrue(object->SetIntegrityLevel(context, v8::IntegrityLevel::kFrozen));
}

bool IsPlainObject(const v8::Local<v8::Value>& object)
{
    if (!object->IsObject())
        return false;

    return !(object->IsNullOrUndefined() || object->IsDate() || object->IsArgumentsObject() || object->IsBigIntObject() || object->IsBooleanObject()
        || object->IsNumberObject() || object->IsStringObject() || object->IsSymbolObject() || object->IsNativeError() || object->IsRegExp()
        || object->IsPromise() || object->IsMap() || object->IsSet() || object->IsMapIterator() || object->IsSetIterator() || object->IsWeakMap()
        || object->IsWeakSet() || object->IsArrayBuffer() || object->IsArrayBufferView() || object->IsArray() || object->IsDataView()
        || object->IsSharedArrayBuffer() || object->IsProxy() ||
        //object->IsWasmModuleObject() || object->IsWasmMemoryObject() ||
        object->IsModuleNamespaceObject());
}

bool IsPlainArray(const v8::Local<v8::Value>& arr)
{
    if (!arr->IsArray())
        return false;

    return !arr->IsTypedArray();
}

void SetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Object> target, const std::string& key, v8::Local<v8::Value> value)
{
    target->SetPrivate(context, v8::Private::ForApi(context->GetIsolate(), gin_helper::StringToV8(context->GetIsolate(), key)), value).Check();
}

v8::MaybeLocal<v8::Value> GetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Object> target, const std::string& key)
{
    return target->GetPrivate(context, v8::Private::ForApi(context->GetIsolate(), gin_helper::StringToV8(context->GetIsolate(), key)));
}

class ThenOrCatchCb {
public:
    ThenOrCatchCb(v8::Isolate* isolate, std::shared_ptr<gin_helper::Promise<v8::Local<v8::Value>>> proxied_promise,
        v8::Global<v8::Context>&& global_source_context, v8::Global<v8::Context>&& global_destination_context, bool isThen)
        : m_isolate(isolate)
        , m_proxied_promise(proxied_promise)
        , m_global_source_context(std::move(global_source_context))
        , m_global_destination_context(std::move(global_destination_context))
        , m_isThen(isThen)
    {
    }

    static void onCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ThenOrCatchCb* self = (ThenOrCatchCb*)(v8::Local<v8::External>::Cast(info.Data())->Value());
        v8::Local<v8::Value> result;
        if (info.Length() >= 1)
            result = info[0];
        self->onCallbackImpl(result);
        delete self;
    }

    void onCallbackImpl(v8::Local<v8::Value> result)
    {
        if (m_global_source_context.IsEmpty() || m_global_destination_context.IsEmpty())
            return;

        context_bridge::ObjectCache object_cache;
        v8::MaybeLocal<v8::Value> val
            = PassValueToOtherContext(m_global_source_context.Get(m_isolate), m_global_destination_context.Get(m_isolate), result, &object_cache, false, 0);
        if (val.IsEmpty())
            return;

        if (m_isThen)
            m_proxied_promise->Resolve(val.ToLocalChecked());
        else
            m_proxied_promise->Reject(val.ToLocalChecked());
    }

    v8::Local<v8::Function> create(/*v8::Local<v8::Context> context*/)
    {
        v8::Local<v8::Context> context = m_isolate->GetCurrentContext();
        v8::Local<v8::Value> cbdata = v8::External::New(m_isolate, this);
        v8::Local<v8::Function> ret = v8::Function::New(context, onCallback, cbdata, 0).ToLocalChecked();
        return ret;
    }

private:
    v8::Isolate* m_isolate;
    std::shared_ptr<gin_helper::Promise<v8::Local<v8::Value>>> m_proxied_promise;
    v8::Global<v8::Context> m_global_source_context;
    v8::Global<v8::Context> m_global_destination_context;
    bool m_isThen;
};

} // namespace

v8::MaybeLocal<v8::Value> PassValueToOtherContext(v8::Local<v8::Context> source_context, v8::Local<v8::Context> destination_context, v8::Local<v8::Value> value,
    context_bridge::ObjectCache* object_cache, bool support_dynamic_properties, int recursion_depth, BridgeErrorTarget error_target)
{
    //TRACE_EVENT0("electron", "ContextBridge::PassValueToOtherContext");
    if (recursion_depth >= kMaxRecursion) {
        v8::Context::Scope error_scope(error_target == BridgeErrorTarget::kSource ? source_context : destination_context);
        source_context->GetIsolate()->ThrowException(v8::Exception::TypeError(gin_helper::StringToV8(
            source_context->GetIsolate(), "Electron contextBridge recursion depth exceeded. Nested objects deeper than 1000 are not supported.")));
        return v8::MaybeLocal<v8::Value>();
    }

    // Certain primitives always use the current contexts prototype and we can
    // pass these through directly which is significantly more performant than
    // copying them. This list of primitives is based on the classification of
    // "primitive value" as defined in the ECMA262 spec
    // https://tc39.es/ecma262/#sec-primitive-value
    if (value->IsString() || value->IsNumber() || value->IsNullOrUndefined() || value->IsBoolean() || value->IsSymbol() || value->IsBigInt()) {
        return v8::MaybeLocal<v8::Value>(value);
    }

    // Check Cache
    v8::MaybeLocal<v8::Value> cached_value = object_cache->GetCachedProxiedObject(value);
    if (!cached_value.IsEmpty()) {
        return cached_value;
    }

    // Proxy functions and monitor the lifetime in the new context to release
    // the global handle at the right time.
    if (value->IsFunction()) {
        v8::Local<v8::Function> func = value.As<v8::Function>();
        v8::MaybeLocal<v8::Value> maybe_original_fn = GetPrivate(source_context, func, context_bridge::kOriginalFunctionPrivateKey);

        {
            v8::Context::Scope destination_scope(destination_context);
            v8::Local<v8::Value> proxy_func;

            // If this function has already been sent over the bridge,
            // then it is being sent _back_ over the bridge and we can
            // simply return the original method here for performance reasons

            // For safety reasons we check if the destination context is the
            // creation context of the original method.  If it's not we proceed
            // with the proxy logic
            if (maybe_original_fn.ToLocal(&proxy_func) && proxy_func->IsFunction()
                && proxy_func.As<v8::Object>()->GetCreationContext().ToLocalChecked() == destination_context) {
                return v8::MaybeLocal<v8::Value>(proxy_func);
            }

            v8::Local<v8::Object> state = v8::Object::New(destination_context->GetIsolate());
            SetPrivate(destination_context, state, context_bridge::kProxyFunctionPrivateKey, func);
            SetPrivate(destination_context, state, context_bridge::kSupportsDynamicPropertiesPrivateKey,
                gin_helper::ConvertToV8(destination_context->GetIsolate(), support_dynamic_properties));

            if (!v8::Function::New(destination_context, ProxyFunctionWrapper, state).ToLocal(&proxy_func))
                return v8::MaybeLocal<v8::Value>();

            SetPrivate(destination_context, proxy_func.As<v8::Object>(), context_bridge::kOriginalFunctionPrivateKey, func);
            object_cache->CacheProxiedObject(value, proxy_func);
            return v8::MaybeLocal<v8::Value>(proxy_func);
        }
    }

    // Proxy promises as they have a safe and guaranteed memory lifecycle
    if (value->IsPromise()) {
        v8::Context::Scope destination_scope(destination_context);
        v8::Local<v8::Promise> source_promise = value.As<v8::Promise>();

        // Make the promise a shared_ptr so that when the original promise is
        // freed the proxy promise is correctly freed as well instead of being
        // left dangling
        std::shared_ptr<gin_helper::Promise<v8::Local<v8::Value>>> proxied_promise(
            new gin_helper::Promise<v8::Local<v8::Value>>(destination_context->GetIsolate()));
        v8::Local<v8::Promise> proxied_promise_handle = proxied_promise->GetHandle();

        v8::Global<v8::Context> global_then_source_context(source_context->GetIsolate(), source_context);
        v8::Global<v8::Context> global_then_destination_context(destination_context->GetIsolate(), destination_context);
        global_then_source_context.SetWeak();
        global_then_destination_context.SetWeak();

        v8::Isolate* isolate = destination_context->GetIsolate();
        ThenOrCatchCb* then_cb
            = new ThenOrCatchCb(isolate, proxied_promise, std::move(global_then_source_context), std::move(global_then_destination_context), true);

        v8::Global<v8::Context> global_catch_source_context(source_context->GetIsolate(), source_context);
        v8::Global<v8::Context> global_catch_destination_context(destination_context->GetIsolate(), destination_context);
        global_catch_source_context.SetWeak();
        global_catch_destination_context.SetWeak();
        ThenOrCatchCb* catch_cb
            = new ThenOrCatchCb(isolate, proxied_promise, std::move(global_then_source_context), std::move(global_then_destination_context), false);

        /*ignore_result*/ (source_promise->Then(source_context, then_cb->create(), catch_cb->create()));

        object_cache->CacheProxiedObject(value, proxied_promise_handle);
        return v8::MaybeLocal<v8::Value>(proxied_promise_handle);
    }

    // Errors aren't serializable currently, we need to pull the message out and
    // re-construct in the destination context
    if (value->IsNativeError()) {
        v8::Context::Scope destination_context_scope(destination_context);
        // We should try to pull "message" straight off of the error as a
        // v8::Message includes some pretext that can get duplicated each time it
        // crosses the bridge we fallback to the v8::Message approach if we can't
        // pull "message" for some reason
        v8::MaybeLocal<v8::Value> maybe_message = value.As<v8::Object>()->Get(source_context, gin_helper::ConvertToV8(source_context->GetIsolate(), "message"));
        v8::Local<v8::Value> message;
        if (maybe_message.ToLocal(&message) && message->IsString()) {
            return v8::MaybeLocal<v8::Value>(v8::Exception::Error(message.As<v8::String>()));
        }
        return v8::MaybeLocal<v8::Value>(v8::Exception::Error(v8::Exception::CreateMessage(destination_context->GetIsolate(), value)->Get()));
    }

    // Manually go through the array and pass each value individually into a new
    // array so that functions deep inside arrays get proxied or arrays of
    // promises are proxied correctly.
    if (IsPlainArray(value)) {
        v8::Context::Scope destination_context_scope(destination_context);
        v8::Local<v8::Array> arr = value.As<v8::Array>();
        size_t length = arr->Length();
        v8::Local<v8::Array> cloned_arr = v8::Array::New(destination_context->GetIsolate(), length);
        for (size_t i = 0; i < length; i++) {
            v8::MaybeLocal<v8::Value> value_for_array = PassValueToOtherContext(source_context, destination_context,
                arr->Get(source_context, i).ToLocalChecked(), object_cache, support_dynamic_properties, recursion_depth + 1);
            if (value_for_array.IsEmpty())
                return v8::MaybeLocal<v8::Value>();

            if (!IsTrue(cloned_arr->Set(destination_context, static_cast<int>(i), value_for_array.ToLocalChecked()))) {
                return v8::MaybeLocal<v8::Value>();
            }
        }
        object_cache->CacheProxiedObject(value, cloned_arr);
        return v8::MaybeLocal<v8::Value>(cloned_arr);
    }

    // Custom logic to "clone" Element references
    v8::Local<v8::Value> otherContextValue;
    if (mbPassWebElementValueToOtherContext(&value, &destination_context, &otherContextValue))
        return v8::MaybeLocal<v8::Value>(otherContextValue);

    // Proxy all objects
    if (IsPlainObject(value)) {
        v8::Local<v8::Object> object_value = value.As<v8::Object>();
        v8::MaybeLocal<v8::Object> passed_value
            = CreateProxyForAPI(object_value, source_context, destination_context, object_cache, support_dynamic_properties, recursion_depth + 1);
        if (passed_value.IsEmpty())
            return v8::MaybeLocal<v8::Value>();

        return v8::MaybeLocal<v8::Value>(passed_value.ToLocalChecked());
    }

    // Serializable objects
    blink::CloneableMessage ret;
    {
        v8::Local<v8::Context> error_context = error_target == BridgeErrorTarget::kSource ? source_context : destination_context;
        v8::Context::Scope error_scope(error_context);

        // V8 serializer will throw an error if required
        if (!gin_helper::ConvertFromV8(error_context->GetIsolate(), value, &ret))
            return v8::MaybeLocal<v8::Value>();
    }

    {
        v8::Context::Scope destination_context_scope(destination_context);
        v8::Local<v8::Value> cloned_value = gin_helper::ConvertToV8(destination_context->GetIsolate(), std::move(ret));
        object_cache->CacheProxiedObject(value, cloned_value);
        return v8::MaybeLocal<v8::Value>(cloned_value);
    }
    DebugBreak();
    return v8::MaybeLocal<v8::Value>();
}

void ProxyFunctionWrapper(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    //TRACE_EVENT0("electron", "ContextBridge::ProxyFunctionWrapper");
    CHECK(info.Data()->IsObject());
    v8::Local<v8::Object> data = info.Data().As<v8::Object>();
    bool support_dynamic_properties = false;
    gin_helper::Arguments args(info);
    // Context the proxy function was called from
    v8::Local<v8::Context> calling_context = args.isolate()->GetCurrentContext();

    // Pull the original function and its context off of the data private key
    v8::MaybeLocal<v8::Value> sdp_value = GetPrivate(calling_context, data, context_bridge::kSupportsDynamicPropertiesPrivateKey);
    v8::MaybeLocal<v8::Value> maybe_func = GetPrivate(calling_context, data, context_bridge::kProxyFunctionPrivateKey);
    v8::Local<v8::Value> func_value;
    if (sdp_value.IsEmpty() || maybe_func.IsEmpty() || !gin_helper::ConvertFromV8(args.isolate(), sdp_value.ToLocalChecked(), &support_dynamic_properties)
        || !maybe_func.ToLocal(&func_value))
        return;

    v8::Local<v8::Function> func = func_value.As<v8::Function>();
    v8::Local<v8::Context> func_owning_context = func->GetCreationContextChecked();

    {
        v8::Context::Scope func_owning_context_scope(func_owning_context);
        context_bridge::ObjectCache object_cache;

        std::vector<v8::Local<v8::Value>> original_args;
        std::vector<v8::Local<v8::Value>> proxied_args;
        args.GetRemaining(&original_args);

        for (auto value : original_args) {
            v8::MaybeLocal<v8::Value> arg = PassValueToOtherContext(calling_context, func_owning_context, value, &object_cache, support_dynamic_properties, 0);
            if (arg.IsEmpty())
                return;
            proxied_args.push_back(arg.ToLocalChecked());
        }

        v8::MaybeLocal<v8::Value> maybe_return_value;
        bool did_error = false;
        v8::Local<v8::Value> error_message;
        {
            v8::TryCatch try_catch(args.isolate());
            maybe_return_value = func->Call(func_owning_context, func, proxied_args.size(), proxied_args.data());
            if (testEventEmitter) {
                content::printCallstackIsolate(args.isolate());
            }

            if (try_catch.HasCaught()) {
                did_error = true;
                v8::Local<v8::Value> exception = try_catch.Exception();

                const char* err_msg = "An unknown exception occurred in the isolated context, an error "
                                      "occurred but a valid exception was not thrown.";

                if (!exception->IsNull() && exception->IsObject()) {
                    v8::MaybeLocal<v8::Value> maybe_message
                        = exception.As<v8::Object>()->Get(func_owning_context, gin_helper::ConvertToV8(args.isolate(), "message"));

                    if (!maybe_message.ToLocal(&error_message) || !error_message->IsString()) {
                        error_message = gin_helper::StringToV8(args.isolate(), err_msg);
                    }
                } else {
                    error_message = gin_helper::StringToV8(args.isolate(), err_msg);
                }
            }
        }

        if (did_error) {
            v8::Context::Scope calling_context_scope(calling_context);
            args.isolate()->ThrowException(v8::Exception::Error(error_message.As<v8::String>()));
            return;
        }

        if (maybe_return_value.IsEmpty())
            return;

        v8::MaybeLocal<v8::Value> ret = PassValueToOtherContext(func_owning_context, calling_context, maybe_return_value.ToLocalChecked(), &object_cache,
            support_dynamic_properties, 0, BridgeErrorTarget::kDestination);
        if (ret.IsEmpty())
            return;
        info.GetReturnValue().Set(ret.ToLocalChecked());
    }
}

v8::MaybeLocal<v8::Object> CreateProxyForAPI(const v8::Local<v8::Object>& api_object, const v8::Local<v8::Context>& source_context,
    const v8::Local<v8::Context>& destination_context, context_bridge::ObjectCache* object_cache, bool support_dynamic_properties, int recursion_depth)
{
    gin_helper::Dictionary api(source_context->GetIsolate(), api_object);

    {
        v8::Context::Scope destination_context_scope(destination_context);
        gin_helper::Dictionary proxy = gin_helper::Dictionary::CreateEmpty(destination_context->GetIsolate());
        object_cache->CacheProxiedObject(api.GetHandle(), proxy.GetHandle());
        v8::MaybeLocal<v8::Array> maybe_keys = api.GetHandle()->GetOwnPropertyNames(source_context, static_cast<v8::PropertyFilter>(v8::ONLY_ENUMERABLE));
        if (maybe_keys.IsEmpty())
            return v8::MaybeLocal<v8::Object>(proxy.GetHandle());

        v8::Local<v8::Array> keys = maybe_keys.ToLocalChecked();

        uint32_t length = keys->Length();
        for (uint32_t i = 0; i < length; i++) {
            v8::Local<v8::Value> key = keys->Get(destination_context, i).ToLocalChecked();

            if (support_dynamic_properties) {
                v8::Context::Scope source_context_scope(source_context);
                v8::MaybeLocal<v8::Value> maybe_desc = api.GetHandle()->GetOwnPropertyDescriptor(source_context, key.As<v8::Name>());
                v8::Local<v8::Value> desc_value;
                if (!maybe_desc.ToLocal(&desc_value) || !desc_value->IsObject())
                    continue;
                gin_helper::Dictionary desc(api.isolate(), desc_value.As<v8::Object>());
                if (desc.Has("get") || desc.Has("set")) {
                    v8::Local<v8::Value> getter;
                    v8::Local<v8::Value> setter;
                    desc.Get("get", &getter);
                    desc.Get("set", &setter);

                    {
                        v8::Context::Scope destination_context_scope(destination_context);
                        v8::Local<v8::Value> getter_proxy;
                        v8::Local<v8::Value> setter_proxy;
                        if (!getter.IsEmpty()) {
                            if (!PassValueToOtherContext(source_context, destination_context, getter, object_cache, support_dynamic_properties, 1)
                                     .ToLocal(&getter_proxy))
                                continue;
                        }
                        if (!setter.IsEmpty()) {
                            if (!PassValueToOtherContext(source_context, destination_context, setter, object_cache, support_dynamic_properties, 1)
                                     .ToLocal(&setter_proxy))
                                continue;
                        }

                        v8::PropertyDescriptor desc(getter_proxy, setter_proxy);
                        /*ignore_result*/ (proxy.GetHandle()->DefineProperty(destination_context, key.As<v8::Name>(), desc));
                    }
                    continue;
                }
            }

            v8::Local<v8::Value> value;
            std::string keyStr;
            if (!gin_helper::ConvertFromV8(api.isolate(), key, &keyStr) || !api.Get(keyStr, &value)) {
                if (!api.Get(key, &value))
                    continue;
            }

            v8::MaybeLocal<v8::Value> passed_value
                = PassValueToOtherContext(source_context, destination_context, value, object_cache, support_dynamic_properties, recursion_depth + 1);
            if (passed_value.IsEmpty())
                return v8::MaybeLocal<v8::Object>();
            proxy.Set(keyStr, passed_value.ToLocalChecked());
        }

        return proxy.GetHandle();
    }
}

static v8::Local<v8::Context> GetContextByV8Object(v8::Isolate* isolate, v8::Local<v8::Object> obj, WorldIDs id)
{
    v8::Local<v8::Context> context;
    //v8::Local<v8::Object> global = isolate->GetCurrentContext()->Global();
    if (!mbGetContextByV8Object(isolate, &obj /*global*/, id, &context))
        return v8::Local<v8::Context>();
    return context;
}

blink::WebLocalFrame* getRenderFrame(v8::Local<v8::Object> value)
{
    v8::Local<v8::Context> context = value->GetCreationContextChecked();
    if (context.IsEmpty())
        return nullptr;
    blink::WebLocalFrame* frame = blink::WebLocalFrame::FrameForContext(context);
    return frame;
}

void exposeAPIInMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    if (info.Length() != 2) {
        OutputDebugStringA("exposeAPIInMainWorld fail 1\n");
        return;
    }
    std::string key;
    if (!gin_helper::ConvertFromV8(isolate, info[0], &key)) {
        OutputDebugStringA("exposeAPIInMainWorld fail 2\n");
        return;
    }
    v8::Local<v8::Value> api = info[1];
    //     TRACE_EVENT1("electron", "ContextBridge::exposeAPIInMainWorld", "key", key);
    //     auto* render_frame = GetRenderFrame(isolate->GetCurrentContext()->Global());
    //     CHECK(render_frame);
    //     auto* frame = render_frame->GetWebFrame();
    //     CHECK(frame);
    blink::WebLocalFrame* frame = getRenderFrame(isolate->GetCurrentContext()->Global());
    CHECK(frame);

    v8::Local<v8::Context> mainContext = frame->MainWorldScriptContext();
    //v8::Local<v8::Context> mainContext = GetContextByV8Object(isolate, isolate->GetCurrentContext()->Global(), WorldIDs::MAIN_WORLD_ID);

    gin_helper::Dictionary global(mainContext->GetIsolate(), mainContext->Global());

    if (global.Has(key)) {
        OutputDebugStringA("exposeAPIInMainWorld fail 3\n");
        const char* error_message = "Cannot bind an API on top of an existing property on the window object";
        isolate->ThrowException(v8::Exception::TypeError(gin_helper::StringToV8(isolate, error_message)));
        return;
    }

    v8::Local<v8::Context> isolatedContext = frame->GetScriptContextFromWorldId(isolate, WorldIDs::ISOLATED_WORLD_ID);
    //v8::Local<v8::Context> isolatedContext = GetContextByV8Object(isolate, isolate->GetCurrentContext()->Global(), WorldIDs::ISOLATED_WORLD_ID);

    {
        context_bridge::ObjectCache objectCache;
        v8::Context::Scope main_context_scope(mainContext);

        v8::MaybeLocal<v8::Value> maybeProxy = PassValueToOtherContext(isolatedContext, mainContext, api, &objectCache, false, 0);
        if (maybeProxy.IsEmpty()) {
            OutputDebugStringA("exposeAPIInMainWorld fail 4\n");
            return;
        }
        v8::Local<v8::Value> proxy = maybeProxy.ToLocalChecked();

        //         if (base::FeatureList::IsEnabled(features::kContextBridgeMutability)) {
        //             global.Set(key, proxy);
        //             return;
        //         }

        if (proxy->IsObject() && !proxy->IsTypedArray() && !DeepFreeze(proxy.As<v8::Object>(), mainContext)) {
            OutputDebugStringA("exposeAPIInMainWorld fail 5\n");
            return;
        }

        char* output = (char*)malloc(400 + key.size());
        sprintf(output, "exposeAPIInMainWorld: %s\n", key.c_str());
        OutputDebugStringA(output);
        free(output);

        global.SetReadOnlyNonConfigurable(key, proxy);
    }
}

gin_helper::Dictionary TraceKeyPath(const gin_helper::Dictionary& start, const std::vector<std::string>& key_path)
{
    gin_helper::Dictionary current = start;
    for (size_t i = 0; i < key_path.size() - 1; i++) {
        CHECK(current.Get(key_path[i], &current));
    }
    return current;
}

void OverrideGlobalValueFromIsolatedWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    if (info.Length() != 3)
        return;
    std::vector<std::string> key_path;
    if (gin_helper::ConvertFromV8(isolate, info[0], &key_path))
        return;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> valueMaybe = info[1]->ToObject(context);
    if (valueMaybe.IsEmpty())
        return;
    v8::Local<v8::Object> value = valueMaybe.ToLocalChecked();
    bool support_dynamic_properties = false;
    gin_helper::ConvertFromV8(isolate, info[2], &support_dynamic_properties);

    if (key_path.empty())
        return;

    //     auto* render_frame = GetRenderFrame(value);
    //     CHECK(render_frame);
    //     auto* frame = render_frame->GetWebFrame();
    //     CHECK(frame);
    //     v8::Local<v8::Context> main_context = frame->MainWorldScriptContext();
    v8::Local<v8::Context> main_context = GetContextByV8Object(isolate, value, WorldIDs::MAIN_WORLD_ID);
    gin_helper::Dictionary global(main_context->GetIsolate(), main_context->Global());

    const std::string final_key = key_path[key_path.size() - 1];
    gin_helper::Dictionary target_object = TraceKeyPath(global, key_path);

    {
        v8::Context::Scope main_context_scope(main_context);
        context_bridge::ObjectCache object_cache;
        v8::MaybeLocal<v8::Value> maybe_proxy
            = PassValueToOtherContext(value->GetCreationContextChecked(), main_context, value, &object_cache, support_dynamic_properties, 1);
        DCHECK(!maybe_proxy.IsEmpty());
        auto proxy = maybe_proxy.ToLocalChecked();

        target_object.Set(final_key, proxy);
    }
}

bool OverrideGlobalPropertyFromIsolatedWorld(
    const std::vector<std::string>& key_path, v8::Local<v8::Object> getter, v8::Local<v8::Value> setter, gin_helper::Arguments* args)
{
    if (key_path.empty())
        return false;

    //     auto* render_frame = GetRenderFrame(getter);
    //     CHECK(render_frame);
    //     auto* frame = render_frame->GetWebFrame();
    //     CHECK(frame);
    //     v8::Local<v8::Context> main_context = frame->MainWorldScriptContext();
    v8::Local<v8::Context> main_context = GetContextByV8Object(v8::Isolate::GetCurrent(), getter, WorldIDs::MAIN_WORLD_ID);
    gin_helper::Dictionary global(main_context->GetIsolate(), main_context->Global());

    const std::string final_key = key_path[key_path.size() - 1];
    v8::Local<v8::Object> target_object = TraceKeyPath(global, key_path).GetHandle();

    {
        v8::Context::Scope main_context_scope(main_context);
        context_bridge::ObjectCache object_cache;
        v8::Local<v8::Value> getter_proxy;
        v8::Local<v8::Value> setter_proxy;
        if (!getter->IsNullOrUndefined()) {
            v8::MaybeLocal<v8::Value> maybe_getter_proxy
                = PassValueToOtherContext(getter->GetCreationContextChecked(), main_context, getter, &object_cache, false, 1);
            DCHECK(!maybe_getter_proxy.IsEmpty());
            getter_proxy = maybe_getter_proxy.ToLocalChecked();
        }
        if (!setter->IsNullOrUndefined() && setter->IsObject()) {
            v8::MaybeLocal<v8::Value> maybe_setter_proxy
                = PassValueToOtherContext(getter->GetCreationContextChecked(), main_context, setter, &object_cache, false, 1);
            DCHECK(!maybe_setter_proxy.IsEmpty());
            setter_proxy = maybe_setter_proxy.ToLocalChecked();
        }

        v8::PropertyDescriptor desc(getter_proxy, setter_proxy);
        bool success = IsTrue(target_object->DefineProperty(main_context, gin_helper::StringToV8(args->isolate(), final_key), desc));
        DCHECK(success);
        return success;
    }
}

bool IsCalledFromMainWorld(v8::Isolate* isolate)
{
    //     auto* render_frame = GetRenderFrame(isolate->GetCurrentContext()->Global());
    //     CHECK(render_frame);
    //     auto* frame = render_frame->GetWebFrame();
    //     CHECK(frame);
    //     v8::Local<v8::Context> main_context = frame->MainWorldScriptContext();
    v8::Local<v8::Context> main_context = GetContextByV8Object(isolate, isolate->GetCurrentContext()->Global(), WorldIDs::MAIN_WORLD_ID);
    return isolate->GetCurrentContext() == main_context;
}

} // namespace api

} // namespace atom

static void initializeContextBridgeApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    v8::Isolate* isolate = context->GetIsolate();
    gin_helper::Dictionary dict(isolate, exports);
    dict.SetMethod("exposeInMainWorld", &atom::api::exposeAPIInMainWorld);
    //     dict.SetMethod("_overrideGlobalValueFromIsolatedWorld", &atom::api::OverrideGlobalValueFromIsolatedWorld);
    //     dict.SetMethod("_overrideGlobalPropertyFromIsolatedWorld", &atom::api::OverrideGlobalPropertyFromIsolatedWorld);
    //     dict.SetMethod("_isCalledFromMainWorld", &atom::api::IsCalledFromMainWorld);
#if DCHECK_IS_ON()
    dict.Set("_isDebug", true);
#endif
}

static const char ContextBridgeSricpt[] = "exports = {};";
static NodeNative nativeRendererContextBridgeNative { "ContextBridge", ContextBridgeSricpt, sizeof(ContextBridgeSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_renderer_contextbridge, initializeContextBridgeApi, &nativeRendererContextBridgeNative)
