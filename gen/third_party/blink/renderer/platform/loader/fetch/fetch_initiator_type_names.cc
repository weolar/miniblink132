// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/loader/fetch/fetch_initiator_type_names.json5

#include "third_party/blink/renderer/platform/loader/fetch/fetch_initiator_type_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace fetch_initiator_type_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAttributionsrc = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kAudio = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kBeacon = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kCSS = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kDocument = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kFetch = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kIcon = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kInternal = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kLink = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kOther = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kPing = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kProcessinginstruction = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kScript = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kTrack = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kUacss = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kUse = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kVideo = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kViolationreport = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kXml = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kXmlhttprequest = reinterpret_cast<AtomicString*>(&names_storage)[19];

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
        { "attributionsrc", 14 },
        { "audio", 5 },
        { "beacon", 6 },
        { "css", 3 },
        { "document", 8 },
        { "fetch", 5 },
        { "icon", 4 },
        { "internal", 8 },
        { "link", 4 },
        { "other", 5 },
        { "ping", 4 },
        { "processinginstruction", 21 },
        { "script", 6 },
        { "track", 5 },
        { "uacss", 5 },
        { "use", 3 },
        { "video", 5 },
        { "violationreport", 15 },
        { "xml", 3 },
        { "xmlhttprequest", 14 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace fetch_initiator_type_names
} // namespace blink
