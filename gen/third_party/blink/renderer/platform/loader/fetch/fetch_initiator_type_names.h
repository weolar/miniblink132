// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/loader/fetch/fetch_initiator_type_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_LOADER_FETCH_FETCH_INITIATOR_TYPE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_LOADER_FETCH_FETCH_INITIATOR_TYPE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/platform_export.h"

namespace blink {
namespace fetch_initiator_type_names {

PLATFORM_EXPORT extern const WTF::AtomicString& kAttributionsrc;
PLATFORM_EXPORT extern const WTF::AtomicString& kAudio;
PLATFORM_EXPORT extern const WTF::AtomicString& kBeacon;
PLATFORM_EXPORT extern const WTF::AtomicString& kCSS;
PLATFORM_EXPORT extern const WTF::AtomicString& kDocument;
PLATFORM_EXPORT extern const WTF::AtomicString& kFetch;
PLATFORM_EXPORT extern const WTF::AtomicString& kIcon;
PLATFORM_EXPORT extern const WTF::AtomicString& kInternal;
PLATFORM_EXPORT extern const WTF::AtomicString& kLink;
PLATFORM_EXPORT extern const WTF::AtomicString& kOther;
PLATFORM_EXPORT extern const WTF::AtomicString& kPing;
PLATFORM_EXPORT extern const WTF::AtomicString& kProcessinginstruction;
PLATFORM_EXPORT extern const WTF::AtomicString& kScript;
PLATFORM_EXPORT extern const WTF::AtomicString& kTrack;
PLATFORM_EXPORT extern const WTF::AtomicString& kUacss;
PLATFORM_EXPORT extern const WTF::AtomicString& kUse;
PLATFORM_EXPORT extern const WTF::AtomicString& kVideo;
PLATFORM_EXPORT extern const WTF::AtomicString& kViolationreport;
PLATFORM_EXPORT extern const WTF::AtomicString& kXml;
PLATFORM_EXPORT extern const WTF::AtomicString& kXmlhttprequest;

constexpr unsigned kNamesCount = 20;

PLATFORM_EXPORT void Init();

} // namespace fetch_initiator_type_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_LOADER_FETCH_FETCH_INITIATOR_TYPE_NAMES_H_
