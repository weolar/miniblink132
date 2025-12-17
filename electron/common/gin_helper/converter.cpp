// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "electron/common/gin_helper/converter.h"

#include "electron/common/V8Util.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "v8.h"

#include <windows.h>
#include "base/memory/ptr_util.h"

using v8::ArrayBuffer;
using v8::Boolean;
using v8::External;
using v8::Function;
using v8::Int32;
using v8::Integer;
using v8::Isolate;
using v8::Local;
using v8::Maybe;
using v8::MaybeLocal;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Uint32;
using v8::Value;

namespace content {
void printCallstack();
}

namespace {

template <typename T, typename U> bool FromMaybe(v8::Maybe<T> maybe, U* out)
{
    if (maybe.IsNothing())
        return false;
    *out = static_cast<U>(maybe.FromJust());
    return true;
}

} // namespace

namespace gin_helper {

v8::Local<v8::Value> Converter<bool>::ToV8(v8::Isolate* isolate, bool val)
{
    return v8::Boolean::New(isolate, val).As<v8::Value>();
}

bool Converter<bool>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, bool* out)
{
    //return FromMaybe(val->BooleanValue(isolate), out);
    *out = val->BooleanValue(isolate);
    return true;
}

v8::Local<v8::Value> Converter<int32_t>::ToV8(v8::Isolate* isolate, int32_t val)
{
    return Integer::New(isolate, val).As<v8::Value>();
}

bool Converter<int32_t>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, int32_t* out)
{
    if (!val->IsInt32())
        return false;
    *out = val.As<Int32>()->Value();
    return true;
}

v8::Local<v8::Value> Converter<uint32_t>::ToV8(v8::Isolate* isolate, uint32_t val)
{
    return Integer::NewFromUnsigned(isolate, val).As<Value>();
}

bool Converter<uint32_t>::FromV8(Isolate* isolate, v8::Local<v8::Value> val, uint32_t* out)
{
    if (!val->IsUint32())
        return false;
    *out = val.As<Uint32>()->Value();
    return true;
}

v8::Local<v8::Value> Converter<int64_t>::ToV8(v8::Isolate* isolate, int64_t val)
{
    return v8::Number::New(isolate, static_cast<double>(val)).As<v8::Value>();
}

bool Converter<int64_t>::FromV8(Isolate* isolate, Local<Value> val, int64_t* out)
{
    if (!val->IsNumber()) {
        content::printCallstack();
        return false;
    }
    // Even though IntegerValue returns int64_t, JavaScript cannot represent
    // the full precision of int64_t, which means some rounding might occur.
    return FromMaybe(val->IntegerValue(isolate->GetCurrentContext()), out);
}

Local<Value> Converter<uint64_t>::ToV8(Isolate* isolate, uint64_t val)
{
    return Number::New(isolate, static_cast<double>(val)).As<Value>();
}

// Local<Value> Converter<unsigned long long>::ToV8(Isolate* isolate, unsigned long long val)
// {
//     return Number::New(isolate, static_cast<double>(val)).As<Value>();
// }

bool Converter<uint64_t>::FromV8(Isolate* isolate, v8::Local<v8::Value> val, uint64_t* out)
{
    if (!val->IsNumber())
        return false;
    return FromMaybe(val->IntegerValue(isolate->GetCurrentContext()), out);
}

Local<Value> Converter<float>::ToV8(Isolate* isolate, float val)
{
    return Number::New(isolate, val).As<Value>();
}

bool Converter<float>::FromV8(Isolate* isolate, v8::Local<v8::Value> val, float* out)
{
    if (!val->IsNumber())
        return false;
    *out = static_cast<float>(val.As<v8::Number>()->Value());
    return true;
}

v8::Local<v8::Value> Converter<double>::ToV8(v8::Isolate* isolate, double val)
{
    return Number::New(isolate, val).As<v8::Value>();
}

bool Converter<double>::FromV8(Isolate* isolate, Local<Value> val, double* out)
{
    if (!val->IsNumber())
        return false;
    *out = val.As<Number>()->Value();
    return true;
}

Local<Value> Converter<base::StringPiece>::ToV8(v8::Isolate* isolate, const base::StringPiece& val)
{
    return v8::String::NewFromUtf8(isolate, val.data(), v8::NewStringType::kNormal, static_cast<uint32_t>(val.length())).ToLocalChecked();
}

v8::Local<v8::Value> Converter<const char*>::ToV8(v8::Isolate* isolate, const char* val)
{
    return Converter<base::StringPiece>::ToV8(isolate, val);
}

v8::Local<v8::Value> Converter<std::string>::ToV8(v8::Isolate* isolate, const std::string& val)
{
    return Converter<base::StringPiece>::ToV8(isolate, val);
}

bool Converter<std::string>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::string* out)
{
    if (val->IsNumber()) {
        double d = val.As<Number>()->Value();
        char temp[64] = { 0 };
        sprintf(temp, "%f\n", d);
        *out = temp;
        return true;
    }

    if (val->IsSymbol() || val->IsSymbolObject())
        return false;

    if (!val->IsString()) {
        v8::Local<v8::String> ty = val->TypeOf(isolate);
        int length = ty->Utf8Length(isolate);
        std::vector<char> temp;
        temp.resize(length);
        ty->WriteUtf8(isolate, temp.data(), length, NULL, v8::String::NO_NULL_TERMINATION);
        temp.push_back('\n');
        temp.push_back('\0');
        OutputDebugStringA("Converter<std::string>::FromV8:\n");
        OutputDebugStringA(temp.data());

        return false;
    }
    v8::Local<v8::String> str = v8::Local<v8::String>::Cast(val);
    int length = str->Utf8Length(isolate);
    out->resize(length);
    str->WriteUtf8(isolate, &(*out)[0], length, NULL, v8::String::NO_NULL_TERMINATION);
    return true;
}

#if defined(_WIN32)
v8::Local<v8::Value> Converter<std::u16string>::ToV8(v8::Isolate* isolate, const std::u16string& val)
{
    v8::Local<v8::String> ret = v8::String::NewFromTwoByte(isolate, (const uint16_t*)val.c_str(), v8::NewStringType::kNormal, val.length()).ToLocalChecked();
    return ret;
}

bool Converter<std::u16string>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::u16string* out)
{
    if (!val->IsString())
        return false;
    v8::Local<v8::String> str = v8::Local<v8::String>::Cast(val);
    int length = str->Length();
    out->resize(length);
    str->Write(isolate, (uint16_t*)(out->data()), 0, length, v8::String::NO_OPTIONS);
    return true;
}
#endif

Local<Value> Converter<v8::Local<v8::String>>::ToV8(v8::Isolate* isolate, v8::Local<v8::String> val)
{
    return val.As<Value>();
}

bool Converter<v8::Local<v8::String>>::FromV8(Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::String>* out)
{
    if (!val->IsString())
        return false;
    *out = v8::Local<v8::String>::Cast(val);
    return true;
}

bool Converter<v8::Local<v8::Function>>::FromV8(v8::Isolate* isolate, Local<Value> val, v8::Local<v8::Function>* out)
{
    if (!val->IsFunction())
        return false;
    *out = v8::Local<v8::Function>::Cast(val);
    return true;
}

v8::Local<v8::Value> Converter<v8::Local<v8::Object>>::ToV8(v8::Isolate* isolate, v8::Local<v8::Object> val)
{
    return val.As<Value>();
}

v8::Local<v8::Value> Converter<v8::Local<v8::Primitive>>::ToV8(v8::Isolate* isolate, v8::Local<v8::Primitive> val)
{
    return val.As<Value>();
}

bool Converter<v8::Local<v8::Object>>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::Object>* out)
{
    if (!val->IsObject())
        return false;
    *out = Local<Object>::Cast(val);
    return true;
}

Local<Value> Converter<Local<ArrayBuffer>>::ToV8(Isolate* isolate, Local<ArrayBuffer> val)
{
    return val.As<Value>();
}

bool Converter<Local<ArrayBuffer>>::FromV8(Isolate* isolate, Local<Value> val, Local<ArrayBuffer>* out)
{
    if (!val->IsArrayBuffer())
        return false;
    *out = Local<ArrayBuffer>::Cast(val);
    return true;
}

Local<Value> Converter<Local<External>>::ToV8(Isolate* isolate, Local<External> val)
{
    return val.As<Value>();
}

bool Converter<Local<External>>::FromV8(Isolate* isolate, v8::Local<Value> val, Local<External>* out)
{
    if (!val->IsExternal())
        return false;
    *out = Local<External>::Cast(val);
    return true;
}

Local<Value> Converter<Local<Value>>::ToV8(Isolate* isolate, Local<Value> val)
{
    return val;
}

bool Converter<Local<Value>>::FromV8(Isolate* isolate, Local<Value> val, Local<Value>* out)
{
    *out = val;
    return true;
}

Local<Value> Converter<Local<v8::Array>>::ToV8(Isolate* isolate, Local<v8::Array> val)
{
    return val.As<Value>();
}

bool Converter<v8::Local<v8::Array>>::FromV8(Isolate* isolate, v8::Local<v8::Value> val, v8::Local<v8::Array>* out)
{
    if (!val->IsArray())
        return false;
    *out = Local<v8::Array>::Cast(val);
    return true;
}

int v8ValueToType(v8::Local<v8::Value> v)
{
    int type = 0;
    bool b = false;
    b = v->IsUndefined();
    if (b)
        return 0;
    b = v->IsNull();
    if (b)
        return 1;
    b = v->IsTrue();
    if (b)
        return 2;
    b = v->IsFalse();
    if (b)
        return 3;
    b = v->IsName();
    if (b)
        return 4;
    b = v->IsString();
    if (b)
        return 5;
    b = v->IsSymbol();
    if (b)
        return 6;
    b = v->IsFunction();
    if (b)
        return 7;
    b = v->IsArray();
    if (b)
        return 8;
    b = v->IsObject();
    if (b)
        return 9;
    b = v->IsBoolean();
    if (b)
        return 10;
    b = v->IsNumber();
    if (b)
        return 11;
    b = v->IsExternal();
    if (b)
        return 12;
    b = v->IsInt32();
    if (b)
        return 13;
    b = v->IsUint32();
    if (b)
        return 14;
    b = v->IsDate();
    if (b)
        return 15;
    b = v->IsArgumentsObject();
    if (b)
        return 16;
    b = v->IsBooleanObject();
    if (b)
        return 17;
    b = v->IsNumberObject();
    if (b)
        return 18;
    b = v->IsStringObject();
    if (b)
        return 19;
    b = v->IsSymbolObject();
    if (b)
        return 20;
    b = v->IsNativeError();
    if (b)
        return 21;
    b = v->IsRegExp();
    if (b)
        return 22;
    b = v->IsGeneratorFunction();
    if (b)
        return 23;
    b = v->IsGeneratorObject();
    if (b)
        return 24;
    b = v->IsPromise();
    if (b)
        return 25;
    b = v->IsMap();
    if (b)
        return 26;
    b = v->IsSet();
    if (b)
        return 27;
    b = v->IsMapIterator();
    if (b)
        return 28;
    b = v->IsSetIterator();
    if (b)
        return 29;
    b = v->IsWeakMap();
    if (b)
        return 30;
    b = v->IsWeakSet();
    if (b)
        return 31;
    b = v->IsArrayBuffer();
    if (b)
        return 32;
    b = v->IsArrayBufferView();
    if (b)
        return 33;
    b = v->IsTypedArray();
    if (b)
        return 34;
    b = v->IsUint8Array();
    if (b)
        return 35;
    b = v->IsUint8ClampedArray();
    if (b)
        return 36;
    b = v->IsInt8Array();
    if (b)
        return 37;
    b = v->IsUint16Array();
    if (b)
        return 38;
    b = v->IsInt16Array();
    if (b)
        return 39;
    b = v->IsUint32Array();
    if (b)
        return 40;
    b = v->IsInt32Array();
    if (b)
        return 41;
    b = v->IsFloat32Array();
    if (b)
        return 42;
    b = v->IsFloat64Array();
    if (b)
        return 43;
    b = v->IsDataView();
    if (b)
        return 44;
    b = v->IsSharedArrayBuffer();
    if (b)
        return 45;
    return -1;
}

v8::Local<v8::Value> Converter<base::Value::Dict>::ToV8(v8::Isolate* isolate, const base::Value::Dict& val)
{
    size_t size = val.size();
    v8::Local<v8::Object> v8Ojb = v8::Object::New(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    std::optional<bool> boolVal;
    std::optional<int> intVal;
    std::optional<double> doubleVal = 0;
    const std::string* strVal;
    const base::Value::List* listValue = nullptr;
    const base::Value::Dict* dictionaryValue = nullptr;
    //base::Value::Dict::Iterator it(val);
    //for (size_t i = 0; !it.IsAtEnd(); ++i, it.Advance()) {
    for (base::Value::Dict::const_iterator it = val.begin(); it != val.end(); ++it) {
        //const base::Value* outValue = &it.value();
        const base::Value& outValue = it->second;
        std::string key = it->first;
        if (key.empty())
            key = "noElementToV8";

        Local<Value> v8Key = Converter<std::string>::ToV8(isolate, key);
        base::Value::Type type = outValue.type();
        switch (type) {
        case base::Value::Type::BOOLEAN:
            boolVal = outValue.GetIfBool();
            v8Ojb->Set(context, v8Key, v8::Boolean::New(isolate, boolVal.value()));
            break;
        case base::Value::Type::INTEGER:
            intVal = outValue.GetIfInt();
            v8Ojb->Set(context, v8Key, v8::Integer::New(isolate, intVal.value()));
            break;
        case base::Value::Type::DOUBLE:
            doubleVal = outValue.GetIfDouble();
            v8Ojb->Set(context, v8Key, v8::Number::New(isolate, doubleVal.value()));
            break;
        case base::Value::Type::STRING:
            strVal = outValue.GetIfString();
            v8Ojb->Set(context, v8Key, v8::String::NewFromUtf8(isolate, strVal->c_str(), v8::NewStringType::kNormal, strVal->size()).ToLocalChecked());
            break;
        case base::Value::Type::LIST:
            listValue = outValue.GetIfList();
            v8Ojb->Set(context, v8Key, Converter<base::Value::List>::ToV8(isolate, *listValue));
            break;
        case base::Value::Type::DICT:
            dictionaryValue = outValue.GetIfDict();
            v8Ojb->Set(context, v8Key, Converter<base::Value::Dict>::ToV8(isolate, *dictionaryValue));
            break;
        case base::Value::Type::NONE:
            v8Ojb->Set(context, v8Key, v8::Null(isolate));
            break;
        default:
            DebugBreak();
            v8Ojb->Set(context, v8Key, v8::Null(isolate));
            break;
        }
    }

    return v8Ojb.As<Value>();
}

bool Converter<base::Value::Dict>::FromV8(Isolate* isolate, v8::Local<v8::Value> val, base::Value::Dict* out)
{
    if (!val->IsObject())
        return false;

    v8::Object* v8Obj = v8::Object::Cast(*val);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Array> v8ObjProps = v8Obj->GetOwnPropertyNames(context).ToLocalChecked();
    size_t size = v8ObjProps->Length();

    for (size_t i = 0; i < size; ++i) {
        v8::Local<v8::Value> keyNameValue = v8ObjProps->Get(context, i).ToLocalChecked();
        v8::Local<v8::Value> outValue = v8Obj->Get(context, keyNameValue).ToLocalChecked();

        std::string keyNameStr;
        if (!Converter<std::string>::FromV8(isolate, keyNameValue, &keyNameStr))
            return false;
        if (keyNameStr.empty())
            keyNameStr = "noElementFromV8";

        if (outValue->IsBoolean()) {
            v8::Local<v8::Boolean> boolVal = outValue->ToBoolean(isolate);
            out->Set(keyNameStr, boolVal->Value());
        } else if (outValue->IsInt32()) {
            v8::Local<v8::Int32> intVal = outValue->ToInt32(context).ToLocalChecked();
            out->Set(keyNameStr, intVal->Value());
        } else if (outValue->IsUint32()) {
            Local<v8::Uint32> intVal = outValue->ToUint32(context).ToLocalChecked();
            out->Set(keyNameStr, (int)intVal->Value());
        } else if (outValue->IsNumber()) {
            Local<v8::Number> doubleVal = outValue->ToNumber(context).ToLocalChecked();
            out->Set(keyNameStr, doubleVal->Value());
        } else if (outValue->IsString()) {
            v8::Local<v8::String> strVal = outValue->ToString(context).ToLocalChecked();
            v8::String::Utf8Value utf8(isolate, strVal);
            out->Set(keyNameStr, std::string(*utf8));
        } else if (outValue->IsArray()) {
            base::Value::List arrayOut;
            if (!Converter<base::Value::List>::FromV8(isolate, outValue, &arrayOut)) {
                return false;
            }
            out->Set(keyNameStr, std::move(arrayOut));
        } else if (outValue->IsObject()) {
            base::Value::Dict dictionaryOut;
            if (!Converter<base::Value::Dict>::FromV8(isolate, outValue, &dictionaryOut)) {
                return false;
            }
            out->Set(keyNameStr, std::move(dictionaryOut));
        } else if (outValue->IsUndefined()) {
            out->Set(keyNameStr, base::Value());
        } else if (outValue->IsNull()) {
            out->Set(keyNameStr, base::Value());
        } else {
            DebugBreak();
            int type = v8ValueToType(outValue);
            out->Set(keyNameStr, base::Value());
            return false;
        }
    }
    return true;
}

void testValIsTypeArray(v8::Local<v8::Value> value)
{
    bool b1 = value->IsArrayBuffer();
    bool b2 = value->IsArrayBufferView();
    bool b3 = value->IsUint8Array();
    bool b4 = value->IsUint8ClampedArray();
    bool b5 = value->IsInt8Array();
    bool b6 = value->IsUint16Array();
    bool b7 = value->IsInt16Array();
    bool b8 = value->IsUint32Array();
    bool b9 = value->IsInt32Array();
    bool b10 = value->IsFloat16Array();
    bool b11 = value->IsFloat32Array();
    bool b12 = value->IsFloat64Array();
    bool b13 = value->IsBigInt64Array();
    bool b14 = value->IsBigUint64Array();

    bool b200 = value->IsNull();
    bool b201 = value->IsUndefined();
    OutputDebugStringA("");
}

v8::Local<v8::Value> Converter<base::Value::List>::ToV8(v8::Isolate* isolate, const base::Value::List& val)
{
    size_t size = val.size();
    v8::Local<v8::Array> v8Arr = v8::Array::New(isolate, size);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    std::optional<bool> boolVal = false;
    std::optional<int> intVal = 0;
    std::optional<double> doubleVal = 0;
    const std::string* strVal = nullptr;
    const base::Value::List* listValue = nullptr;
    const base::Value::Dict* dictionaryValue = nullptr;

    for (size_t i = 0; i < size; ++i) {
        const base::Value& outValue = val[i];
        base::Value::Type type = outValue.type();
        switch (type) {
        case base::Value::Type::BOOLEAN:
            boolVal = outValue.GetIfBool();
            v8Arr->Set(context, i, v8::Boolean::New(isolate, boolVal.value()));
            break;
        case base::Value::Type::INTEGER:
            intVal = outValue.GetIfInt();
            v8Arr->Set(context, i, v8::Integer::New(isolate, intVal.value()));
            break;
        case base::Value::Type::DOUBLE:
            doubleVal = outValue.GetIfDouble();
            v8Arr->Set(context, i, v8::Number::New(isolate, doubleVal.value()));
            break;
        case base::Value::Type::STRING:
            strVal = outValue.GetIfString();
            v8Arr->Set(context, i, v8::String::NewFromUtf8(isolate, strVal->c_str(), v8::NewStringType::kNormal, strVal->size()).ToLocalChecked());
            break;
        case base::Value::Type::LIST:
            listValue = outValue.GetIfList();
            v8Arr->Set(context, i, Converter<base::Value::List>::ToV8(isolate, *listValue));
            break;
        case base::Value::Type::DICT:
            dictionaryValue = outValue.GetIfDict();
            v8Arr->Set(context, i, Converter<base::Value::Dict>::ToV8(isolate, *dictionaryValue));
            break;
        case base::Value::Type::BINARY: {
            const base::Value::BlobStorage& blob = outValue.GetBlob();
            blink::CloneableMessage ret;
            ret.encoded_message = blob;
            v8::Local<v8::Value> clonedValue = ConvertToV8(isolate, std::move(ret));
            testValIsTypeArray(clonedValue);
            v8Arr->Set(context, i, clonedValue);
        }
            break;
        case base::Value::Type::NONE:
            v8Arr->Set(context, i, v8::Null(isolate));
            break;
        default:
            DebugBreak();
            v8Arr->Set(context, i, v8::Null(isolate));
            break;
        }
    }

    return v8Arr.As<Value>();
}

bool Converter<base::Value::List>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, base::Value::List* out)
{
    if (!val->IsArray())
        return false;

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Array* v8Arr = v8::Array::Cast(*val);
    size_t size = v8Arr->Length();
    for (size_t i = 0; i < size; ++i) {
        v8::Local<v8::Value> itVal = v8Arr->Get(context, i).ToLocalChecked();
        if (itVal->IsBoolean()) {
            v8::Local<v8::Boolean> boolVal = itVal->ToBoolean(isolate);
            out->Append(boolVal->Value());
        } else if (itVal->IsInt32()) {
            v8::Local<v8::Int32> intVal = itVal->ToInt32(context).ToLocalChecked();
            out->Append(intVal->Value());
        } else if (itVal->IsUint32()) {
            v8::Local<v8::Uint32> uintVal = itVal->ToUint32(context).ToLocalChecked();
            out->Append((int)(uintVal->Value()));
        } else if (itVal->IsNumber()) {
            Local<v8::Number> doubleVal = itVal->ToNumber(context).ToLocalChecked();
            out->Append(doubleVal->Value());
        } else if (itVal->IsString()) {
            v8::Local<v8::String> strVal = itVal->ToString(context).ToLocalChecked();
            v8::String::Utf8Value utf8(isolate, strVal);
            out->Append(std::string(*utf8));
        } else if (itVal->IsArray()) {
            base::Value::List arrayOut;
            if (!FromV8(isolate, itVal, &arrayOut)) {
                return false;
            }
            out->Append(std::move(arrayOut));
        } else if (itVal->IsNull() || itVal->IsUndefined()) {
            out->Append(base::Value());
        } else if (itVal->IsArrayBuffer() || itVal->IsArrayBufferView() || itVal->IsTypedArray()) {
            testValIsTypeArray(itVal);

            blink::CloneableMessage ret;
            if (!ConvertFromV8(isolate, itVal, &ret)) {
                out->Append(base::Value());
                continue;
            }
            out->Append(base::Value(ret.encoded_message));
        } else if (itVal->IsObject()) {
            base::Value::Dict dictionaryOut;
            if (!Converter<base::Value::Dict>::FromV8(isolate, itVal, &dictionaryOut)) {
                return false;
            }
            out->Append(std::move(dictionaryOut));
        } else {
            DebugBreak();
            int type = v8ValueToType(itVal);
            out->Append(base::Value());
            return false;
        }
    }
    return true;
}

v8::Local<v8::String> StringToSymbol(v8::Isolate* isolate, const base::StringPiece& val)
{
    return v8::String::NewFromUtf8(isolate, val.data(), v8::NewStringType::kInternalized, static_cast<uint32_t>(val.length())).ToLocalChecked();
}

std::string V8ToString(v8::Local<v8::Value> value)
{
    if (value.IsEmpty())
        return std::string();
    std::string result;
    if (!ConvertFromV8(NULL, value, &result))
        return std::string();
    return result;
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const std::vector<intptr_t>& input)
{
    std::vector<Local<Value>> elements;
    for (size_t i = 0; i < input.size(); ++i) {
        intptr_t element = input[i];
        elements.push_back(ConvertToV8(isolate, element));
    }
    v8::Local<v8::Array> ret = v8::Array::New(isolate, elements.data(), input.size());
    return ret;
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const base::Value::List& input)
{
    return Converter<base::Value::List>::ToV8(isolate, input);
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const base::Value& input)
{
    std::optional<bool> boolVal = false;
    std::optional<int> intVal = 0;
    std::optional<double> doubleVal = 0;
    const std::string* strVal = nullptr;
    const base::Value::List* listValue = nullptr;
    const base::Value::Dict* dictionaryValue = nullptr;

    base::Value::Type type = input.type();
    switch (type) {
    case base::Value::Type::BOOLEAN:
        boolVal = input.GetIfBool();
        return v8::Boolean::New(isolate, boolVal.value());
        break;
    case base::Value::Type::INTEGER:
        intVal = input.GetIfInt();
        return v8::Integer::New(isolate, intVal.value());
        break;
    case base::Value::Type::DOUBLE:
        doubleVal = input.GetIfDouble();
        return v8::Number::New(isolate, doubleVal.value());
        break;
    case base::Value::Type::STRING:
        strVal = input.GetIfString();
        return v8::String::NewFromUtf8(isolate, strVal->c_str(), v8::NewStringType::kNormal, strVal->size()).ToLocalChecked();
        break;
    case base::Value::Type::LIST:
        listValue = input.GetIfList();
        return Converter<base::Value::List>::ToV8(isolate, *listValue);
    case base::Value::Type::DICT:
        dictionaryValue = input.GetIfDict();
        return Converter<base::Value::Dict>::ToV8(isolate, *dictionaryValue);
        break;
    case base::Value::Type::NONE:
        break;
    case base::Value::Type::BINARY: {
        const base::Value::BlobStorage& blob = input.GetBlob();
        blink::CloneableMessage ret;
        ret.encoded_message = blob;
        v8::Local<v8::Value> clonedValue = ConvertToV8(isolate, std::move(ret));
        testValIsTypeArray(clonedValue);
        return clonedValue;
    }
        break;
    default:
        DebugBreak();
        return v8::Null(isolate);
        break;
    }
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const blink::CloneableMessage& in)
{
    return Converter<blink::CloneableMessage>::ToV8(isolate, in);
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, const std::vector<blink::CloneableMessage>& input)
{
    return Converter<std::vector<blink::CloneableMessage>>::ToV8(isolate, input);
}

v8::Local<v8::Value> Converter<std::vector<blink::CloneableMessage>>::ToV8(v8::Isolate* isolate, const std::vector<blink::CloneableMessage>& val)
{
    std::vector<v8::Local<v8::Value>> retTemp;
    for (size_t i = 0; i < val.size(); ++i) {
        v8::Local<v8::Value> it = Converter<blink::CloneableMessage>::ToV8(isolate, val[i]);
        retTemp.push_back(it);
    }

    return v8::Array::New(isolate, retTemp.data(), retTemp.size());
}

bool Converter<std::vector<blink::CloneableMessage>>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, std::vector<blink::CloneableMessage>* out)
{
    DebugBreak();
    return false;
}


v8::Local<v8::Value> Converter<std::unique_ptr<std::vector<blink::CloneableMessage>>>::ToV8(
    v8::Isolate* isolate, 
    const std::unique_ptr<std::vector<blink::CloneableMessage>>& val)
{
    DebugBreak();
    return v8::Local<v8::Value>();
}

bool Converter<std::unique_ptr<std::vector<blink::CloneableMessage>>>::FromV8(
    v8::Isolate* isolate, 
    v8::Local<v8::Value> val, 
    std::unique_ptr<std::vector<blink::CloneableMessage>>* out)
{
    return false;
}

struct TranslaterHolder {
    explicit TranslaterHolder(v8::Isolate* isolate)
        : handle(isolate, v8::External::New(isolate, this))
    {
        handle.SetWeak(this, &GC, v8::WeakCallbackType::kParameter /*kFinalizer*/);
    }
    ~TranslaterHolder()
    {
        if (!handle.IsEmpty()) {
            handle.ClearWeak();
            handle.Reset();
        }
    }

    static void GC(const v8::WeakCallbackInfo<TranslaterHolder>& data)
    {
        delete data.GetParameter();
    }

    v8::Global<v8::External> handle;
    std::function<void(const v8::FunctionCallbackInfo<v8::Value>&)> translater;
};

void CallTranslater(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TranslaterHolder* holder = (TranslaterHolder*)(v8::External::Cast(*info.Data())->Value());
    holder->translater(info);
}

v8::Local<v8::Value> ConvertToV8(v8::Isolate* isolate, std::function<void(const v8::FunctionCallbackInfo<v8::Value>& info)>&& cb)
{
    TranslaterHolder* holder = new TranslaterHolder(isolate);
    holder->translater = std::move(cb);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::FunctionTemplate> tmpl = v8::FunctionTemplate::New(isolate);
    v8::Local<v8::Value> data = v8::External::New(isolate, holder);
    tmpl->SetCallHandler(CallTranslater, data);
    v8::Local<v8::Function> func = tmpl->GetFunction(context).FromMaybe(v8::Local<v8::Function>());
    return func;
}

v8::Local<v8::Value> Converter<blink::CloneableMessage>::ToV8(v8::Isolate* isolate, const blink::CloneableMessage& in)
{
    return atom::deserializeV8Value(isolate, in);
}

bool Converter<blink::CloneableMessage>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, blink::CloneableMessage* out) 
{
    return atom::serializeV8Value(isolate, val, out);
}

} // namespace gin_helper
