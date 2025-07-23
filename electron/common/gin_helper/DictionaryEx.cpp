// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "electron/common/gin_helper/DictionaryEx.h"

#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"

namespace gin {

DictionaryEx::DictionaryEx(v8::Isolate* isolate)
    : isolate_(isolate)
{
}

DictionaryEx::DictionaryEx(v8::Isolate* isolate, v8::Local<v8::Object> object)
    : isolate_(isolate)
    , object_(object)
{
}

DictionaryEx::~DictionaryEx()
{
}

DictionaryEx DictionaryEx::CreateEmpty(v8::Isolate* isolate)
{
    DictionaryEx dictionary(isolate);
    dictionary.object_ = v8::Object::New(isolate);
    return dictionary;
}

v8::Local<v8::Value> Converter<DictionaryEx>::ToV8(v8::Isolate* isolate, DictionaryEx val)
{
    return val.object_;
}

bool Converter<DictionaryEx>::FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, DictionaryEx* out)
{
    if (!val->IsObject())
        return false;
    *out = DictionaryEx(isolate, v8::Local<v8::Object>::Cast(val));
    return true;
}

void DictionaryEx::GetBydefaultVal(const char* name, bool defaultVal, bool* outResult) const
{
    v8::Local<v8::Value> result;
    if (!this->Get(name, &result) || !result->IsBoolean()) {
        *outResult = defaultVal;
        return;
    }
    *outResult = result->ToBoolean()->BooleanValue();
}

void DictionaryEx::GetBydefaultVal(const char* name, int defaultVal, int* outResult) const
{
    v8::Local<v8::Value> result;
    if (!this->Get(name, &result) || !result->IsInt32()) {
        *outResult = defaultVal;
        return;
    }

    v8::Local<v8::Context> context = this->isolate()->GetCurrentContext();
    v8::Local<v8::Int32> v = result->ToInt32(context).ToLocalChecked();
    *outResult = v->Value();
}

void DictionaryEx::GetBydefaultVal(const char* name, double defaultVal, double* outResult) const
{
    v8::Local<v8::Value> result;
    if (!this->Get(name, &result) || !result->IsNumber()) {
        *outResult = defaultVal;
        return;
    }

    v8::Local<v8::Context> context = this->isolate()->GetCurrentContext();
    v8::Local<v8::Number> v = result->ToNumber(context).ToLocalChecked();
    *outResult = v->Value();
}

void DictionaryEx::GetBydefaultVal(const char* name, const std::string& defaultVal, std::string* outResult) const
{
    v8::Local<v8::Value> result;
    if (!this->Get(name, &result) || !result->IsString()) {
        *outResult = defaultVal;
        return;
    }

    v8::Local<v8::Context> context = this->isolate()->GetCurrentContext();
    v8::Local<v8::String> v = result->ToString(context).ToLocalChecked();

    int length = v->Length();
    if (0 > length) {
        *outResult = defaultVal;
        return;
    }

    v8::String::Utf8Value str(v);
    *outResult = *str;
}

void DictionaryEx::GetBydefaultVal(const char* name, const base::string16& defaultVal, base::string16* outResult) const
{
    std::string defaultValA = base::UTF16ToUTF8(defaultVal);
    std::string outResultA;
    GetBydefaultVal(name, defaultValA, &outResultA);

    *outResult = base::UTF8ToUTF16(outResultA);
}

} // namespace gin
