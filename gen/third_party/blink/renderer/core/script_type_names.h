// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/script/script_type_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SCRIPT_TYPE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SCRIPT_TYPE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace script_type_names {

CORE_EXPORT extern const WTF::AtomicString& kClassic;
CORE_EXPORT extern const WTF::AtomicString& kImportmap;
CORE_EXPORT extern const WTF::AtomicString& kModule;
CORE_EXPORT extern const WTF::AtomicString& kSpeculationrules;
CORE_EXPORT extern const WTF::AtomicString& kWebbundle;

constexpr unsigned kNamesCount = 5;

CORE_EXPORT void Init();

} // namespace script_type_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_SCRIPT_TYPE_NAMES_H_
