// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/forms/input_type_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_INPUT_TYPE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_INPUT_TYPE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace input_type_names {

CORE_EXPORT extern const WTF::AtomicString& kButton;
CORE_EXPORT extern const WTF::AtomicString& kCheckbox;
CORE_EXPORT extern const WTF::AtomicString& kColor;
CORE_EXPORT extern const WTF::AtomicString& kDate;
CORE_EXPORT extern const WTF::AtomicString& kDatetime;
CORE_EXPORT extern const WTF::AtomicString& kDatetimeLocal;
CORE_EXPORT extern const WTF::AtomicString& kEmail;
CORE_EXPORT extern const WTF::AtomicString& kFile;
CORE_EXPORT extern const WTF::AtomicString& kHidden;
CORE_EXPORT extern const WTF::AtomicString& kImage;
CORE_EXPORT extern const WTF::AtomicString& kMonth;
CORE_EXPORT extern const WTF::AtomicString& kNumber;
CORE_EXPORT extern const WTF::AtomicString& kPassword;
CORE_EXPORT extern const WTF::AtomicString& kRadio;
CORE_EXPORT extern const WTF::AtomicString& kRange;
CORE_EXPORT extern const WTF::AtomicString& kReset;
CORE_EXPORT extern const WTF::AtomicString& kSearch;
CORE_EXPORT extern const WTF::AtomicString& kSubmit;
CORE_EXPORT extern const WTF::AtomicString& kTel;
CORE_EXPORT extern const WTF::AtomicString& kText;
CORE_EXPORT extern const WTF::AtomicString& kTime;
CORE_EXPORT extern const WTF::AtomicString& kUrl;
CORE_EXPORT extern const WTF::AtomicString& kWeek;

constexpr unsigned kNamesCount = 23;

CORE_EXPORT void Init();

} // namespace input_type_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_INPUT_TYPE_NAMES_H_
