// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GIN_HELPER_CONVERTER_H_
#define GIN_HELPER_CONVERTER_H_

#include <string>
#include <xstring>
#include <vector>
#include <functional>

#include "base/logging.h"
#include "base/strings/string_piece.h"
#include "base/values.h"
#include "gin/gin_export.h"
#include "v8.h"

namespace blink {
struct CloneableMessage;
}

namespace mojo {
class Message;
}

namespace gin_helper {

template <typename KeyType> bool SetProperty(v8::Isolate* isolate, v8::Local<v8::Object> object, KeyType key, v8::Local<v8::Value> value)
{
    auto maybe = object->Set(isolate->GetCurrentContext(), key, value);
    return !maybe.IsNothing() && maybe.FromJust();
}

template <typename T> struct ToV8ReturnsMaybe {
    static const bool value = false;
};

template <typename T, typename Enable = void> struct Converter { };

template <> struct GIN_EXPORT Converter<bool> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, bool val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, bool* out);
};

template <> struct GIN_EXPORT Converter<int32_t> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, int32_t val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, int32_t* out);
};

template <> struct GIN_EXPORT Converter<uint32_t> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, uint32_t val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, uint32_t* out);
};

template <> struct GIN_EXPORT Converter<int64_t> {
    // Warning: JavaScript cannot represent 64 integers precisely.
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, int64_t val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, int64_t* out);
};

template <> struct GIN_EXPORT Converter<uint64_t> {
    // Warning: JavaScript cannot represent 64 integers precisely.
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, uint64_t val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, uint64_t* out);
};

// template<>
// struct GIN_EXPORT Converter<unsigned long long> {
//     // Warning: JavaScript cannot represent 64 integers precisely.
//     static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, unsigned long long val);
//     static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, unsigned long long* out);
// };

template <> struct GIN_EXPORT Converter<float> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, float val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, float* out);
};

template <> struct GIN_EXPORT Converter<double> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, double val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, double* out);
};

template <> struct GIN_EXPORT Converter<base::StringPiece> {
    // This crashes when val.size() > v8::String::kMaxLength.
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const base::StringPiece& val);
    // No conversion out is possible because StringPiece does not contain storage.
};

template <> struct GIN_EXPORT Converter<std::string> {
    // This crashes when val.size() > v8::String::kMaxLength.
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const std::string& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::string* out);
};

template <> struct GIN_EXPORT Converter<std::u16string> {
    // This crashes when val.size() > v8::String::kMaxLength.
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const std::u16string& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::u16string* out);
};

#if defined(_WIN32)
template <> struct GIN_EXPORT Converter<std::wstring> {
    // This crashes when val.size() > v8::String::kMaxLength.
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const std::wstring& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::wstring* out);
};
#endif

template <> struct GIN_EXPORT Converter<const char*> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const char* val);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::Function>> {
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::Function>* out);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::Object>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::Object> val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::Object>* out);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::Primitive>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::Primitive> val);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::ArrayBuffer>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::ArrayBuffer> val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::ArrayBuffer>* out);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::External>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::External> val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::External>* out);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::Value>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::Value> val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::Value>* out);
};

// template<>
// struct GIN_EXPORT Converter<v8::Function> {
//     static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const v8::Function* val);
//     static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Function** out);
// };

template <> struct GIN_EXPORT Converter<v8::Local<v8::String>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::String> val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::String>* out);
};

template <> struct GIN_EXPORT Converter<v8::Local<v8::Array>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, v8::Local<v8::Array> val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::Array>* out);
};

template <> struct GIN_EXPORT Converter<mojo::Message> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const mojo::Message& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, mojo::Message* out);
};

template <> struct GIN_EXPORT Converter<base::Value::List> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const base::Value::List& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, base::Value::List* out);
};

template <> struct GIN_EXPORT Converter<base::Value::Dict> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const base::Value::Dict& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, base::Value::Dict* out);
};

template <> struct GIN_EXPORT Converter<base::Value> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, base::Value&& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, base::Value* out);
};

template <typename T> struct Converter<std::vector<T>> {
    static v8::MaybeLocal<v8::Value> ToV8(v8::Local<v8::Context> context, const std::vector<T>& val)
    {
        v8::Isolate* isolate = context->GetIsolate();
        v8::Local<v8::Array> result(v8::Array::New(isolate, static_cast<int>(val.size())));

        for (uint32_t i = 0; i < val.size(); ++i) {
            auto maybe = result->Set(context, i, Converter<T>::ToV8(isolate, val[i]));
            if (maybe.IsNothing() || !maybe.FromJust())
                return v8::MaybeLocal<v8::Value>();
        }
        return result;
    }

    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const std::vector<T>& val)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::Array> result(v8::Array::New(isolate, static_cast<int>(val.size())));

        for (uint32_t i = 0; i < val.size(); ++i) {
            auto maybe = result->Set(context, i, Converter<T>::ToV8(isolate, val[i]));
            if (maybe.IsNothing() || !maybe.FromJust())
                return v8::Local<v8::Value>();
        }
        return result;
    }

    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::vector<T>* out)
    {
        if (!val->IsArray())
            return false;

        std::vector<T> result;
        v8::Local<v8::Array> array(v8::Local<v8::Array>::Cast(val));
        uint32_t length = array->Length();
        for (uint32_t i = 0; i < length; ++i) {
            v8::Local<v8::Value> v8_item;
            if (!array->Get(isolate->GetCurrentContext(), i).ToLocal(&v8_item))
                return false;
            T item;
            if (!Converter<T>::FromV8(isolate, v8_item, &item))
                return false;
            result.push_back(item);
        }

        out->swap(result);
        return true;
    }
};

template <typename T> struct ToV8ReturnsMaybe<std::vector<T>> {
    static const bool value = true;
};

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const base::Value& input);

// Convenience functions that deduce T.
template <typename T> v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, T input)
{
    return Converter<T>::ToV8(isolate, input);
}

template <typename T> v8::MaybeLocal<v8::Value> ConvertToV8(v8::Local<v8::Context> context, T input)
{
    return Converter<T>::ToV8(context, input);
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const std::vector<intptr_t>& input);

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const base::Value::List& input);

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const blink::CloneableMessage& input);

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const std::vector<blink::CloneableMessage>& input);

template <typename T, bool = ToV8ReturnsMaybe<T>::value> struct ToV8Traits;

template <typename T> struct ToV8Traits<T, true> {
    static bool TryConvertToV8(v8::Isolate* isolate, T input, v8::Local<v8::Value>* output)
    {
        auto maybe = ConvertToV8(isolate->GetCurrentContext(), input);
        if (maybe.IsEmpty())
            return false;
        *output = maybe.ToLocalChecked();
        return true;
    }
};

template <typename T> struct ToV8Traits<T, false> {
    static bool TryConvertToV8(v8::Isolate* isolate, T input, v8::Local<v8::Value>* output)
    {
        *output = ConvertToV8(isolate, input);
        return true;
    }
};

template <typename T> bool TryConvertToV8(v8::Isolate* isolate, T input, v8::Local<v8::Value>* output)
{
    return ToV8Traits<T>::TryConvertToV8(isolate, input, output);
}

// This crashes when input.size() > v8::String::kMaxLength.
GIN_EXPORT inline v8::Local<v8::String> StringToV8(v8::Isolate* isolate, const base::StringPiece& input)
{
    return ConvertToV8(isolate, input).As<v8::String>();
}

// This crashes when input.size() > v8::String::kMaxLength.
GIN_EXPORT v8::Local<v8::String> StringToSymbol(v8::Isolate* isolate, const base::StringPiece& val);

template <typename T> bool ConvertFromV8(v8::Isolate* isolate, v8::Local<v8::Value> input, T* result)
{
    return Converter<T>::FromV8(isolate, input, result);
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, std::function<void(const v8::FunctionCallbackInfo<v8::Value>& info)>&& cb);

GIN_EXPORT std::string V8ToString(v8::Local<v8::Value> value);

template <> struct GIN_EXPORT Converter<blink::CloneableMessage> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const blink::CloneableMessage& in);

    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, blink::CloneableMessage* out);
};

template <> struct GIN_EXPORT Converter<std::vector<blink::CloneableMessage>> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const std::vector<blink::CloneableMessage>& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::vector<blink::CloneableMessage>* out);
};

template <> struct GIN_EXPORT Converter<std::unique_ptr<std::vector<blink::CloneableMessage>> > {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const std::unique_ptr<std::vector<blink::CloneableMessage>>& val);
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::unique_ptr<std::vector<blink::CloneableMessage>>* out);
};

} // namespace gin_helper 

#endif // GIN_CONVERTER_H_
