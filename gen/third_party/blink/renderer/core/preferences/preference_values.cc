// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/preferences/preference_values.json5

#include "third_party/blink/renderer/core/preferences/preference_values.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace preference_values {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kCustom = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kDark = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kLess = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kLight = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kMore = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kNoPreference = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kReduce = reinterpret_cast<AtomicString*>(&names_storage)[6];

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
        { "custom", 6 },
        { "dark", 4 },
        { "less", 4 },
        { "light", 5 },
        { "more", 4 },
        { "no-preference", 13 },
        { "reduce", 6 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace preference_values
} // namespace blink
