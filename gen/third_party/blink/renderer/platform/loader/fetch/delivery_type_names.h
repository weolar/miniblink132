// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/loader/fetch/delivery_type_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_LOADER_FETCH_DELIVERY_TYPE_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_LOADER_FETCH_DELIVERY_TYPE_NAMES_H_

#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/platform_export.h"

namespace blink {
namespace delivery_type_names {

PLATFORM_EXPORT extern const WTF::AtomicString& kCache;
PLATFORM_EXPORT extern const WTF::AtomicString& kCacheStorage;
PLATFORM_EXPORT extern const WTF::AtomicString& kNavigationalPrefetch;

constexpr unsigned kNamesCount = 3;

PLATFORM_EXPORT void Init();

} // namespace delivery_type_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_LOADER_FETCH_DELIVERY_TYPE_NAMES_H_
