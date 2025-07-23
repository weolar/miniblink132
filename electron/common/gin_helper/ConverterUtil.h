// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef common_ConverterUtil_h
#define common_ConverterUtil_h

#include <string>
#include <vector>
#include <functional>

#include "base/values.h"
//#include "electron/common/UndefCheck.h"
#include "electron/common/gin_helper/converter.h"
#include "gin/gin_export.h"
#include "v8.h"

// namespace gin_helper {
//
// template<>
// struct GIN_EXPORT Converter<base::Value::List> {
//     static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const base::Value::List& val);
//     static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, base::Value::List* out);
// };
//
// template<>
// struct GIN_EXPORT Converter<base::Value::Dict> {
//     static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const base::Value::Dict& val);
//     static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, base::Value::Dict* out);
// };
//
// }  // namespace gin

#endif // GIN_CONVERTER_H_
