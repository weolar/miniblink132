// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/fonts/font_family_names.json5

#include "third_party/blink/renderer/platform/font_family_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace font_family_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kWebkitStandard = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kArial = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kBlinkMacSystemFont = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kCalibri = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kCourier = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kCourierNew = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kHelvetica = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kHelveticaNeue = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kLucidaGrande = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kMSSansSerif = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kMSSerif = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kMSUIGothic = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kMicrosoftSansSerif = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kRoboto = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kSans = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kSegoeUI = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kTimes = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kTimesNewRoman = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kCursive = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kFantasy = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kMath = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kMonospace = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kSansSerif = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kSerif = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kSystemUi = reinterpret_cast<AtomicString*>(&names_storage)[24];

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
        { "-webkit-standard", 16 },
        { "Arial", 5 },
        { "BlinkMacSystemFont", 18 },
        { "Calibri", 7 },
        { "Courier", 7 },
        { "Courier New", 11 },
        { "Helvetica", 9 },
        { "Helvetica Neue", 14 },
        { "Lucida Grande", 13 },
        { "MS Sans Serif", 13 },
        { "MS Serif", 8 },
        { "MS UI Gothic", 12 },
        { "Microsoft Sans Serif", 20 },
        { "Roboto", 6 },
        { "Sans", 4 },
        { "Segoe UI", 8 },
        { "Times", 5 },
        { "Times New Roman", 15 },
        { "cursive", 7 },
        { "fantasy", 7 },
        { "math", 4 },
        { "monospace", 9 },
        { "sans-serif", 10 },
        { "serif", 5 },
        { "system-ui", 9 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace font_family_names
} // namespace blink
