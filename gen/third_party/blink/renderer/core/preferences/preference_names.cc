// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/preferences/preference_names.json5

#include "third_party/blink/renderer/core/preferences/preference_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace preference_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kColorScheme = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kContrast = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kReducedData = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kReducedMotion = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kReducedTransparency = reinterpret_cast<AtomicString*>(&names_storage)[4];

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
        { "colorScheme", 11 },
        { "contrast", 8 },
        { "reducedData", 11 },
        { "reducedMotion", 13 },
        { "reducedTransparency", 19 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace preference_names
} // namespace blink
