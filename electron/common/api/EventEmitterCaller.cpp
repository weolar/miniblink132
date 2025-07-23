// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/api/EventEmitterCaller.h"

#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include "base/values.h"

namespace gin_helper {
void testValIsTypeArray(v8::Local<v8::Value> value);
}

namespace mate {

namespace internal {

v8::Local<v8::Value> callEmitWithArgs(v8::Isolate* isolate, v8::Local<v8::Object> obj, ValueVector* args)
{
#if V8_MAJOR_VERSION == 5
    // Perform microtask checkpoint after running JavaScript.
    v8::MicrotasksScope script_scope(isolate, v8::MicrotasksScope::kRunMicrotasks);
#endif
    // Use node::MakeCallback to call the callback, and it will also run pending
    // tasks in Node.js.
    return node::MakeCallback(isolate, obj, "emit", args->size(), &args->front());
}

v8::Local<v8::Value> emitEventImpl(
    v8::Isolate* isolate, v8::Local<v8::Object> obj, internal::ValueVector& converted_args, v8::Local<v8::Object> event, const base::Value::List& args)
{
    std::optional<bool> boolVal;
    std::optional<int> intVal;
    std::optional<double> doubleVal;
    const std::string* strVal = nullptr;
    const base::Value::List* listValue = nullptr;
    const base::Value::Dict* dictionaryValue = nullptr;
    for (size_t i = 0; i < args.size(); ++i) {
        const base::Value& outValue = args[i];

        base::Value::Type type = outValue.type();
        switch (type) {
        case base::Value::Type::BOOLEAN:
            boolVal = outValue.GetIfBool();
            converted_args.push_back(v8::Boolean::New(isolate, boolVal.value()));
            break;
        case base::Value::Type::INTEGER:
            intVal = outValue.GetIfInt();
            converted_args.push_back(v8::Integer::New(isolate, intVal.value()));
            break;
        case base::Value::Type::DOUBLE:
            doubleVal = outValue.GetIfDouble();
            converted_args.push_back(v8::Number::New(isolate, doubleVal.value()));
            break;
        case base::Value::Type::STRING:
            strVal = outValue.GetIfString();
            if (!strVal->empty())
                converted_args.push_back(v8::String::NewFromUtf8(isolate, strVal->c_str(), v8::NewStringType::kNormal, strVal->size()).ToLocalChecked());
            break;
        case base::Value::Type::LIST:
            listValue = outValue.GetIfList();
            converted_args.push_back(gin_helper::Converter<base::Value::List>::ToV8(isolate, *listValue));
            break;
        case base::Value::Type::DICT:
            dictionaryValue = outValue.GetIfDict();
            converted_args.push_back(gin_helper::Converter<base::Value::Dict>::ToV8(isolate, *dictionaryValue));
            break;
        case base::Value::Type::BINARY: {
            const base::Value::BlobStorage& blob = outValue.GetBlob();
            blink::CloneableMessage ret;
            ret.encoded_message = blob;
            v8::Local<v8::Value> clonedValue = gin_helper::ConvertToV8(isolate, std::move(ret));
            gin_helper::testValIsTypeArray(clonedValue);
            converted_args.push_back(clonedValue);
        }
        case base::Value::Type::NONE:
            converted_args.push_back(v8::Null(isolate));
            break;
        default:
            *(int*)1 = 1;
            converted_args.push_back(v8::Null(isolate));
            break;
        }
    }

    return callEmitWithArgs(isolate, obj, &converted_args);
}

} // namespace internal

} // namespace mate
