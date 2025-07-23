// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/preferences/preference_values.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_PREFERENCES_PREFERENCE_VALUES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_PREFERENCES_PREFERENCE_VALUES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace preference_values {

CORE_EXPORT extern const WTF::AtomicString& kCustom;
CORE_EXPORT extern const WTF::AtomicString& kDark;
CORE_EXPORT extern const WTF::AtomicString& kLess;
CORE_EXPORT extern const WTF::AtomicString& kLight;
CORE_EXPORT extern const WTF::AtomicString& kMore;
CORE_EXPORT extern const WTF::AtomicString& kNoPreference;
CORE_EXPORT extern const WTF::AtomicString& kReduce;

constexpr unsigned kNamesCount = 7;

CORE_EXPORT void Init();

} // namespace preference_values
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_PREFERENCES_PREFERENCE_VALUES_H_
