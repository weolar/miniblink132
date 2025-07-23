// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/modules/indexeddb/indexed_db_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_INDEXED_DB_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_INDEXED_DB_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/platform_export.h"

namespace blink {
namespace indexed_db_names {

extern const WTF::AtomicString& kDefault;
extern const WTF::AtomicString& kDone;
extern const WTF::AtomicString& kIndexedDB;
extern const WTF::AtomicString& kNext;
extern const WTF::AtomicString& kNextunique;
extern const WTF::AtomicString& kNone;
extern const WTF::AtomicString& kPending;
extern const WTF::AtomicString& kPrev;
extern const WTF::AtomicString& kPrevunique;
extern const WTF::AtomicString& kReadonly;
extern const WTF::AtomicString& kReadwrite;
extern const WTF::AtomicString& kRelaxed;
extern const WTF::AtomicString& kStrict;
extern const WTF::AtomicString& kTotal;
extern const WTF::AtomicString& kVersionchange;

constexpr unsigned kNamesCount = 15;

void Init();

} // namespace indexed_db_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_MODULES_INDEXED_DB_NAMES_H_
