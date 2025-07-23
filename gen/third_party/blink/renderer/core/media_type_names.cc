// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/media_type_names.json5

#include "third_party/blink/renderer/core/media_type_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace media_type_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAll = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kBraille = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kEmbossed = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kHandheld = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kPrint = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kProjection = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kScreen = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kSpeech = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kTty = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kTv = reinterpret_cast<AtomicString*>(&names_storage)[9];

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
        { "all", 3 },
        { "braille", 7 },
        { "embossed", 8 },
        { "handheld", 8 },
        { "print", 5 },
        { "projection", 10 },
        { "screen", 6 },
        { "speech", 6 },
        { "tty", 3 },
        { "tv", 2 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace media_type_names
} // namespace blink
