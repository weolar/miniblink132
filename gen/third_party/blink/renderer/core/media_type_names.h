// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/media_type_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_MEDIA_TYPE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_MEDIA_TYPE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace media_type_names {

CORE_EXPORT extern const WTF::AtomicString& kAll;
CORE_EXPORT extern const WTF::AtomicString& kBraille;
CORE_EXPORT extern const WTF::AtomicString& kEmbossed;
CORE_EXPORT extern const WTF::AtomicString& kHandheld;
CORE_EXPORT extern const WTF::AtomicString& kPrint;
CORE_EXPORT extern const WTF::AtomicString& kProjection;
CORE_EXPORT extern const WTF::AtomicString& kScreen;
CORE_EXPORT extern const WTF::AtomicString& kSpeech;
CORE_EXPORT extern const WTF::AtomicString& kTty;
CORE_EXPORT extern const WTF::AtomicString& kTv;

constexpr unsigned kNamesCount = 10;

CORE_EXPORT void Init();

} // namespace media_type_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_MEDIA_TYPE_NAMES_H_
