// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/events/securitypolicyviolation_disposition_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SECURITYPOLICYVIOLATION_DISPOSITION_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SECURITYPOLICYVIOLATION_DISPOSITION_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/core/core_export.h"

namespace blink {
namespace securitypolicyviolation_disposition_names {

CORE_EXPORT extern const WTF::AtomicString& kEnforce;
CORE_EXPORT extern const WTF::AtomicString& kReport;

constexpr unsigned kNamesCount = 2;

CORE_EXPORT void Init();

} // namespace securitypolicyviolation_disposition_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_SECURITYPOLICYVIOLATION_DISPOSITION_NAMES_H_
