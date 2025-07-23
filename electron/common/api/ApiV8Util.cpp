// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/api/RemoteCallbackFreer.h"
#include "electron/common/api/RemoteObjectFreer.h"
#include "electron/common/api/ApiKeyWeakMap.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include <string>
#include <utility>

namespace std {

// The hash function used by DoubleIDWeakMap.
// template <typename Type1, typename Type2>
// struct hash<std::pair<Type1, Type2>> {
//   std::size_t operator()(std::pair<Type1, Type2> value) const {
//     return base::HashInts<Type1, Type2>(value.first, value.second);
//   }
// };

} // namespace std

// v8::Persistent<v8::Function> atom::api::KeyWeakMap<int32_t>::constructor;
// v8::Persistent<v8::Function> atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::constructor;
template <> DWORD atom::api::KeyWeakMap<int32_t>::constructorTlsKey = 0;
template <> DWORD atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::constructorTlsKey = 0;

template <> gin_helper::WrapperInfo atom::api::KeyWeakMap<int32_t>::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
template <> gin_helper::WrapperInfo atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

namespace gin_helper {

template <typename Type1, typename Type2> struct Converter<std::pair<Type1, Type2>> {
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::pair<Type1, Type2>* out)
    {
        if (!val->IsArray())
            return false;

        v8::Local<v8::Array> array(v8::Local<v8::Array>::Cast(val));
        if (array->Length() != 2)
            return false;
        v8::MaybeLocal<v8::Context> contextMaybe = array->GetCreationContext();
        if (contextMaybe.IsEmpty())
            return false;
        v8::Local<v8::Context> context = contextMaybe.ToLocalChecked();
        return Converter<Type1>::FromV8(isolate, array->Get(context, 0).ToLocalChecked(), &out->first)
            && Converter<Type2>::FromV8(isolate, array->Get(context, 1).ToLocalChecked(), &out->second);
    }
};

} // namespace gin_helper

namespace {

v8::Local<v8::Value> getHiddenValue(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::String> key)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
    v8::Local<v8::Value> value;
    v8::Maybe<bool> result = object->HasPrivate(context, privateKey);
    if (!(result.IsJust() && result.FromJust()))
        return v8::Local<v8::Value>();
    if (object->GetPrivate(context, privateKey).ToLocal(&value))
        return value;
    return v8::Local<v8::Value>();
}

void setHiddenValue(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::String> key, v8::Local<v8::Value> value)
{
    if (value.IsEmpty())
        return;
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
    object->SetPrivate(context, privateKey, value);
}

void deleteHiddenValue(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::String> key)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
    // Actually deleting the value would make force the object into
    // dictionary mode which is unnecessarily slow. Instead, we replace
    // the hidden value with "undefined".
    object->SetPrivate(context, privateKey, v8::Undefined(isolate));
}

int32_t getObjectHash(v8::Local<v8::Object> object)
{
    return object->GetIdentityHash();
}

void takeHeapSnapshot(v8::Isolate* isolate)
{
    //isolate->GetHeapProfiler()->TakeHeapSnapshot();
}

void newV8UtilFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    //v8::Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(args.This());
}

void initializeCommonV8UtilApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    v8::Isolate* isolate = context->GetIsolate();

    atom::api::KeyWeakMap<int32_t>::init(isolate);
    atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::init(isolate);

    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newV8UtilFunction);
    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "V8Util").ToLocalChecked());
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("getHiddenValue", &getHiddenValue);
    builder.SetMethod("setHiddenValue", &setHiddenValue);
    builder.SetMethod("deleteHiddenValue", &deleteHiddenValue);
    builder.SetMethod("getObjectHash", &getObjectHash);
    builder.SetMethod("takeHeapSnapshot", &takeHeapSnapshot);
    builder.SetMethod("setRemoteCallbackFreer", &atom::RemoteCallbackFreer::bindTo);
    builder.SetMethod("setRemoteObjectFreer", &atom::RemoteObjectFreer::bindTo);
    builder.SetMethod("createIDWeakMap", &atom::api::KeyWeakMap<int32_t>::create);
    builder.SetMethod("createDoubleIDWeakMap", &atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::create);

    exports->Set(context, v8::String::NewFromUtf8(isolate, "v8Util").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
}

} // namespace

static const char CommonV8UtilSricpt[] = "exports = {};";

static NodeNative nativeCommonV8UtilNative { "v8Util", CommonV8UtilSricpt, sizeof(CommonV8UtilSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_v8_util, initializeCommonV8UtilApi, &nativeCommonV8UtilNative)
