// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/keywords.json5

#include "third_party/blink/renderer/core/keywords.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace keywords {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kArrowDown = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kArrowLeft = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kArrowRight = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kArrowUp = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kEnd = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kCapitalEnter = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kEscape = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kHome = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kPageDown = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kPageUp = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kTab = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kAnonymous = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kAny = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kApplicationXml = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kAsync = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kAuto = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kCircle = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kClose = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kClosed = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kCloserequest = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kCol = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kColgroup = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kColorScheme = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kDecimal = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kDisc = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kDisclosureClosed = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kDisclosureOpen = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kDone = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kEager = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kEmail = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kEnter = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kExitFullscreen = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kFalse = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kFetch = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kFont = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kGo = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kHidden = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kHide = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kHidePopover = reinterpret_cast<AtomicString*>(&names_storage)[38];
const AtomicString& kHigh = reinterpret_cast<AtomicString*>(&names_storage)[39];
const AtomicString& kHint = reinterpret_cast<AtomicString*>(&names_storage)[40];
const AtomicString& kHover = reinterpret_cast<AtomicString*>(&names_storage)[41];
const AtomicString& kImage = reinterpret_cast<AtomicString*>(&names_storage)[42];
const AtomicString& kInherit = reinterpret_cast<AtomicString*>(&names_storage)[43];
const AtomicString& kInvisible = reinterpret_cast<AtomicString*>(&names_storage)[44];
const AtomicString& kLazy = reinterpret_cast<AtomicString*>(&names_storage)[45];
const AtomicString& kLow = reinterpret_cast<AtomicString*>(&names_storage)[46];
const AtomicString& kLowerAlpha = reinterpret_cast<AtomicString*>(&names_storage)[47];
const AtomicString& kLowerRoman = reinterpret_cast<AtomicString*>(&names_storage)[48];
const AtomicString& kManual = reinterpret_cast<AtomicString*>(&names_storage)[49];
const AtomicString& kNext = reinterpret_cast<AtomicString*>(&names_storage)[50];
const AtomicString& kNoReferrer = reinterpret_cast<AtomicString*>(&names_storage)[51];
const AtomicString& kNoReferrerWhenDowngrade = reinterpret_cast<AtomicString*>(&names_storage)[52];
const AtomicString& kNodownload = reinterpret_cast<AtomicString*>(&names_storage)[53];
const AtomicString& kNofullscreen = reinterpret_cast<AtomicString*>(&names_storage)[54];
const AtomicString& kNone = reinterpret_cast<AtomicString*>(&names_storage)[55];
const AtomicString& kNoplaybackrate = reinterpret_cast<AtomicString*>(&names_storage)[56];
const AtomicString& kNoremoteplayback = reinterpret_cast<AtomicString*>(&names_storage)[57];
const AtomicString& kNumeric = reinterpret_cast<AtomicString*>(&names_storage)[58];
const AtomicString& kOff = reinterpret_cast<AtomicString*>(&names_storage)[59];
const AtomicString& kOn = reinterpret_cast<AtomicString*>(&names_storage)[60];
const AtomicString& kOpen = reinterpret_cast<AtomicString*>(&names_storage)[61];
const AtomicString& kOrigin = reinterpret_cast<AtomicString*>(&names_storage)[62];
const AtomicString& kOriginWhenCrossOrigin = reinterpret_cast<AtomicString*>(&names_storage)[63];
const AtomicString& kPause = reinterpret_cast<AtomicString*>(&names_storage)[64];
const AtomicString& kPlaintextOnly = reinterpret_cast<AtomicString*>(&names_storage)[65];
const AtomicString& kPlay = reinterpret_cast<AtomicString*>(&names_storage)[66];
const AtomicString& kPlayPause = reinterpret_cast<AtomicString*>(&names_storage)[67];
const AtomicString& kPrevious = reinterpret_cast<AtomicString*>(&names_storage)[68];
const AtomicString& kRender = reinterpret_cast<AtomicString*>(&names_storage)[69];
const AtomicString& kRequestFullscreen = reinterpret_cast<AtomicString*>(&names_storage)[70];
const AtomicString& kRow = reinterpret_cast<AtomicString*>(&names_storage)[71];
const AtomicString& kRowgroup = reinterpret_cast<AtomicString*>(&names_storage)[72];
const AtomicString& kSameOrigin = reinterpret_cast<AtomicString*>(&names_storage)[73];
const AtomicString& kScript = reinterpret_cast<AtomicString*>(&names_storage)[74];
const AtomicString& kSearch = reinterpret_cast<AtomicString*>(&names_storage)[75];
const AtomicString& kSend = reinterpret_cast<AtomicString*>(&names_storage)[76];
const AtomicString& kShow = reinterpret_cast<AtomicString*>(&names_storage)[77];
const AtomicString& kShowModal = reinterpret_cast<AtomicString*>(&names_storage)[78];
const AtomicString& kShowPicker = reinterpret_cast<AtomicString*>(&names_storage)[79];
const AtomicString& kShowPopover = reinterpret_cast<AtomicString*>(&names_storage)[80];
const AtomicString& kSquare = reinterpret_cast<AtomicString*>(&names_storage)[81];
const AtomicString& kStatic = reinterpret_cast<AtomicString*>(&names_storage)[82];
const AtomicString& kStepDown = reinterpret_cast<AtomicString*>(&names_storage)[83];
const AtomicString& kStepUp = reinterpret_cast<AtomicString*>(&names_storage)[84];
const AtomicString& kStrictOrigin = reinterpret_cast<AtomicString*>(&names_storage)[85];
const AtomicString& kStrictOriginWhenCrossOrigin = reinterpret_cast<AtomicString*>(&names_storage)[86];
const AtomicString& kStyle = reinterpret_cast<AtomicString*>(&names_storage)[87];
const AtomicString& kSync = reinterpret_cast<AtomicString*>(&names_storage)[88];
const AtomicString& kTel = reinterpret_cast<AtomicString*>(&names_storage)[89];
const AtomicString& kText = reinterpret_cast<AtomicString*>(&names_storage)[90];
const AtomicString& kTextHtml = reinterpret_cast<AtomicString*>(&names_storage)[91];
const AtomicString& kToggle = reinterpret_cast<AtomicString*>(&names_storage)[92];
const AtomicString& kToggleFullscreen = reinterpret_cast<AtomicString*>(&names_storage)[93];
const AtomicString& kToggleMuted = reinterpret_cast<AtomicString*>(&names_storage)[94];
const AtomicString& kTogglePopover = reinterpret_cast<AtomicString*>(&names_storage)[95];
const AtomicString& kTrack = reinterpret_cast<AtomicString*>(&names_storage)[96];
const AtomicString& kTrue = reinterpret_cast<AtomicString*>(&names_storage)[97];
const AtomicString& kUnsafeUrl = reinterpret_cast<AtomicString*>(&names_storage)[98];
const AtomicString& kUpperAlpha = reinterpret_cast<AtomicString*>(&names_storage)[99];
const AtomicString& kUpperRoman = reinterpret_cast<AtomicString*>(&names_storage)[100];
const AtomicString& kUrl = reinterpret_cast<AtomicString*>(&names_storage)[101];
const AtomicString& kUseCredentials = reinterpret_cast<AtomicString*>(&names_storage)[102];
const AtomicString& kVisible = reinterpret_cast<AtomicString*>(&names_storage)[103];

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
        { "ArrowDown", 9 },
        { "ArrowLeft", 9 },
        { "ArrowRight", 10 },
        { "ArrowUp", 7 },
        { "End", 3 },
        { "Enter", 5 },
        { "Escape", 6 },
        { "Home", 4 },
        { "PageDown", 8 },
        { "PageUp", 6 },
        { "Tab", 3 },
        { "anonymous", 9 },
        { "any", 3 },
        { "application/xml", 15 },
        { "async", 5 },
        { "auto", 4 },
        { "circle", 6 },
        { "close", 5 },
        { "closed", 6 },
        { "closerequest", 12 },
        { "col", 3 },
        { "colgroup", 8 },
        { "color-scheme", 12 },
        { "decimal", 7 },
        { "disc", 4 },
        { "disclosure-closed", 17 },
        { "disclosure-open", 15 },
        { "done", 4 },
        { "eager", 5 },
        { "email", 5 },
        { "enter", 5 },
        { "exit-fullscreen", 15 },
        { "false", 5 },
        { "fetch", 5 },
        { "font", 4 },
        { "go", 2 },
        { "hidden", 6 },
        { "hide", 4 },
        { "hide-popover", 12 },
        { "high", 4 },
        { "hint", 4 },
        { "hover", 5 },
        { "image", 5 },
        { "inherit", 7 },
        { "invisible", 9 },
        { "lazy", 4 },
        { "low", 3 },
        { "lower-alpha", 11 },
        { "lower-roman", 11 },
        { "manual", 6 },
        { "next", 4 },
        { "no-referrer", 11 },
        { "no-referrer-when-downgrade", 26 },
        { "nodownload", 10 },
        { "nofullscreen", 12 },
        { "none", 4 },
        { "noplaybackrate", 14 },
        { "noremoteplayback", 16 },
        { "numeric", 7 },
        { "off", 3 },
        { "on", 2 },
        { "open", 4 },
        { "origin", 6 },
        { "origin-when-cross-origin", 24 },
        { "pause", 5 },
        { "plaintext-only", 14 },
        { "play", 4 },
        { "play-pause", 10 },
        { "previous", 8 },
        { "render", 6 },
        { "request-fullscreen", 18 },
        { "row", 3 },
        { "rowgroup", 8 },
        { "same-origin", 11 },
        { "script", 6 },
        { "search", 6 },
        { "send", 4 },
        { "show", 4 },
        { "show-modal", 10 },
        { "show-picker", 11 },
        { "show-popover", 12 },
        { "square", 6 },
        { "static", 6 },
        { "step-down", 9 },
        { "step-up", 7 },
        { "strict-origin", 13 },
        { "strict-origin-when-cross-origin", 31 },
        { "style", 5 },
        { "sync", 4 },
        { "tel", 3 },
        { "text", 4 },
        { "text/html", 9 },
        { "toggle", 6 },
        { "toggle-fullscreen", 17 },
        { "toggle-muted", 12 },
        { "toggle-popover", 14 },
        { "track", 5 },
        { "true", 4 },
        { "unsafe-url", 10 },
        { "upper-alpha", 11 },
        { "upper-roman", 11 },
        { "url", 3 },
        { "use-credentials", 15 },
        { "visible", 7 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace keywords
} // namespace blink
