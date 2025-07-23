// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/preferences/preference_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_PREFERENCES_PREFERENCE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_PREFERENCES_PREFERENCE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace preference_names {

CORE_EXPORT extern const WTF::AtomicString& kColorScheme;
CORE_EXPORT extern const WTF::AtomicString& kContrast;
CORE_EXPORT extern const WTF::AtomicString& kReducedData;
CORE_EXPORT extern const WTF::AtomicString& kReducedMotion;
CORE_EXPORT extern const WTF::AtomicString& kReducedTransparency;

constexpr unsigned kNamesCount = 5;

CORE_EXPORT void Init();

} // namespace preference_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_PREFERENCES_PREFERENCE_NAMES_H_
