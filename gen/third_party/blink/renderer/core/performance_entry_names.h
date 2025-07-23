// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/timing/performance_entry_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_PERFORMANCE_ENTRY_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_PERFORMANCE_ENTRY_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace performance_entry_names {

CORE_EXPORT extern const WTF::AtomicString& kBackForwardCacheRestoration;
CORE_EXPORT extern const WTF::AtomicString& kElement;
CORE_EXPORT extern const WTF::AtomicString& kEvent;
CORE_EXPORT extern const WTF::AtomicString& kFirstInput;
CORE_EXPORT extern const WTF::AtomicString& kLargestContentfulPaint;
CORE_EXPORT extern const WTF::AtomicString& kLayoutShift;
CORE_EXPORT extern const WTF::AtomicString& kLongAnimationFrame;
CORE_EXPORT extern const WTF::AtomicString& kLongtask;
CORE_EXPORT extern const WTF::AtomicString& kMark;
CORE_EXPORT extern const WTF::AtomicString& kMeasure;
CORE_EXPORT extern const WTF::AtomicString& kNavigation;
CORE_EXPORT extern const WTF::AtomicString& kPaint;
CORE_EXPORT extern const WTF::AtomicString& kResource;
CORE_EXPORT extern const WTF::AtomicString& kScript;
CORE_EXPORT extern const WTF::AtomicString& kSoftNavigation;
CORE_EXPORT extern const WTF::AtomicString& kTaskattribution;
CORE_EXPORT extern const WTF::AtomicString& kUnknown;
CORE_EXPORT extern const WTF::AtomicString& kVisibilityState;
CORE_EXPORT extern const WTF::AtomicString& kWindow;

constexpr unsigned kNamesCount = 19;

CORE_EXPORT void Init();

} // namespace performance_entry_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_PERFORMANCE_ENTRY_NAMES_H_
