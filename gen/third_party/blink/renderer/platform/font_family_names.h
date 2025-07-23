// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/fonts/font_family_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONT_FAMILY_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONT_FAMILY_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/platform_export.h"

namespace blink {
namespace font_family_names {

PLATFORM_EXPORT extern const WTF::AtomicString& kArial;
PLATFORM_EXPORT extern const WTF::AtomicString& kBlinkMacSystemFont;
PLATFORM_EXPORT extern const WTF::AtomicString& kCalibri;
PLATFORM_EXPORT extern const WTF::AtomicString& kCourier;
PLATFORM_EXPORT extern const WTF::AtomicString& kCourierNew;
PLATFORM_EXPORT extern const WTF::AtomicString& kCursive;
PLATFORM_EXPORT extern const WTF::AtomicString& kFantasy;
PLATFORM_EXPORT extern const WTF::AtomicString& kHelvetica;
PLATFORM_EXPORT extern const WTF::AtomicString& kHelveticaNeue;
PLATFORM_EXPORT extern const WTF::AtomicString& kLucidaGrande;
PLATFORM_EXPORT extern const WTF::AtomicString& kMSSansSerif;
PLATFORM_EXPORT extern const WTF::AtomicString& kMSSerif;
PLATFORM_EXPORT extern const WTF::AtomicString& kMSUIGothic;
PLATFORM_EXPORT extern const WTF::AtomicString& kMath;
PLATFORM_EXPORT extern const WTF::AtomicString& kMicrosoftSansSerif;
PLATFORM_EXPORT extern const WTF::AtomicString& kMonospace;
PLATFORM_EXPORT extern const WTF::AtomicString& kRoboto;
PLATFORM_EXPORT extern const WTF::AtomicString& kSans;
PLATFORM_EXPORT extern const WTF::AtomicString& kSansSerif;
PLATFORM_EXPORT extern const WTF::AtomicString& kSegoeUI;
PLATFORM_EXPORT extern const WTF::AtomicString& kSerif;
PLATFORM_EXPORT extern const WTF::AtomicString& kSystemUi;
PLATFORM_EXPORT extern const WTF::AtomicString& kTimes;
PLATFORM_EXPORT extern const WTF::AtomicString& kTimesNewRoman;
PLATFORM_EXPORT extern const WTF::AtomicString& kWebkitStandard;

constexpr unsigned kNamesCount = 25;

PLATFORM_EXPORT void Init();

} // namespace font_family_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONT_FAMILY_NAMES_H_
