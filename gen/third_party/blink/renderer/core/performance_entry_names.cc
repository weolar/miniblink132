// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/timing/performance_entry_names.json5

#include "third_party/blink/renderer/core/performance_entry_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace performance_entry_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kBackForwardCacheRestoration = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kElement = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kEvent = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kFirstInput = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kLargestContentfulPaint = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kLayoutShift = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kLongAnimationFrame = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kLongtask = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kMark = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kMeasure = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kNavigation = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kPaint = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kResource = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kScript = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kSoftNavigation = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kTaskattribution = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kUnknown = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kVisibilityState = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kWindow = reinterpret_cast<AtomicString*>(&names_storage)[18];

void Init()
{
    static bool is_loaded = false;
    if (is_loaded)
        return;
    is_loaded = true;

    struct NameEntry {
        const char* name;
        unsigned char length;
    };

    static const NameEntry kNames[] = {
        { "back-forward-cache-restoration", 30 },
        { "element", 7 },
        { "event", 5 },
        { "first-input", 11 },
        { "largest-contentful-paint", 24 },
        { "layout-shift", 12 },
        { "long-animation-frame", 20 },
        { "longtask", 8 },
        { "mark", 4 },
        { "measure", 7 },
        { "navigation", 10 },
        { "paint", 5 },
        { "resource", 8 },
        { "script", 6 },
        { "soft-navigation", 15 },
        { "taskattribution", 15 },
        { "unknown", 7 },
        { "visibility-state", 16 },
        { "window", 6 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace performance_entry_names
} // namespace blink
