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

class V8Util : public gin_helper::Wrappable<V8Util> {
public:
    explicit V8Util(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<V8Util>::InitWith(isolate, wrapper);
    }

    static v8::Local<v8::Value> getHiddenValue(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::String> key)
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

    static void setHiddenValue(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::String> key, v8::Local<v8::Value> value)
    {
        if (value.IsEmpty())
            return;
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
        object->SetPrivate(context, privateKey, value);
    }

    static void deleteHiddenValue(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::String> key)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::Private> privateKey = v8::Private::ForApi(isolate, key);
        // Actually deleting the value would make force the object into
        // dictionary mode which is unnecessarily slow. Instead, we replace
        // the hidden value with "undefined".
        object->SetPrivate(context, privateKey, v8::Undefined(isolate));
    }

    static int32_t getObjectHash(v8::Local<v8::Object> object)
    {
        return object->GetIdentityHash();
    }

    static void takeHeapSnapshot(v8::Isolate* isolate)
    {
        //isolate->GetHeapProfiler()->TakeHeapSnapshot();
    }

    static gin_helper::WrapperInfo kWrapperInfo;
};
gin_helper::WrapperInfo V8Util::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

void newV8UtilFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    new V8Util(args.GetIsolate(), args.This());
    args.GetReturnValue().Set(args.This());
}

template <class T>
static void buildMethod(T* builder)
{
    builder->SetMethodT("getHiddenValue", &V8Util::getHiddenValue);
    builder->SetMethodT("setHiddenValue", &V8Util::setHiddenValue);
    builder->SetMethodT("deleteHiddenValue", &V8Util::deleteHiddenValue);
    builder->SetMethodT("getObjectHash", &V8Util::getObjectHash);
    builder->SetMethodT("takeHeapSnapshot", &V8Util::takeHeapSnapshot);
    builder->SetMethodT("setRemoteCallbackFreer", &atom::RemoteCallbackFreer::bindTo);
    builder->SetMethodT("setRemoteObjectFreer", &atom::RemoteObjectFreer::bindTo);
    builder->SetMethodT("createIDWeakMap", &atom::api::KeyWeakMap<int32_t>::create);
    builder->SetMethodT("createDoubleIDWeakMap", &atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::create);
}

void initializeCommonV8UtilApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    v8::Isolate* isolate = context->GetIsolate();

    atom::api::KeyWeakMap<int32_t>::init(isolate);
    atom::api::KeyWeakMap<std::pair<int32_t, int32_t>>::init(isolate);

    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newV8UtilFunction);
    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "V8Util").ToLocalChecked());
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    buildMethod(&builder);
    exports->Set(context, v8::String::NewFromUtf8(isolate, "v8Util").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());

    // 支持两种写法：
    // var v8UtilClass = process._linkedBinding('electron_common_v8_util').v8Util;
    // const v8Util = new v8UtilClass();
    // 
    // const v8Util2 = process._linkedBinding('electron_common_v8_util');
    // v8Util2.getHiddenValue();
    gin_helper::Dictionary builder2(isolate, exports);
    buildMethod(&builder2);
}

} // namespace

static const char CommonV8UtilSricpt[] = "exports = {};";

static NodeNative nativeCommonV8UtilNative { "v8Util", CommonV8UtilSricpt, sizeof(CommonV8UtilSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_v8_util, initializeCommonV8UtilApi, &nativeCommonV8UtilNative)
