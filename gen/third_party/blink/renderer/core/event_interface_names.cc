// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   gen/third_party/blink/renderer/core/event_interface_names.json5

#include "third_party/blink/renderer/core/event_interface_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace event_interface_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAnimationEvent = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kAnimationPlaybackEvent = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kBeforeCreatePolicyEvent = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kBeforeUnloadEvent = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kCharacterBoundsUpdateEvent = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kClipboardEvent = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kCommandEvent = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kCompositionEvent = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kContentVisibilityAutoStateChangeEvent = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kCustomEvent = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kDragEvent = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kErrorEvent = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kEvent = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kFocusEvent = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kFontFaceSetLoadEvent = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kFormDataEvent = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kHashChangeEvent = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kHighlightPointerEvent = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kInputEvent = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kInterestEvent = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kKeyboardEvent = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kMediaQueryListEvent = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kMessageEvent = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kMojoInterfaceRequestEvent = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kMouseEvent = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kMutationEvent = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kNavigateEvent = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kNavigationCurrentEntryChangeEvent = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kOverscrollEvent = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kPageRevealEvent = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kPageSwapEvent = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kPageTransitionEvent = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kPointerEvent = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kPopStateEvent = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kProgressEvent = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kPromiseRejectionEvent = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kResourceProgressEvent = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kSecurityPolicyViolationEvent = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kSnapEvent = reinterpret_cast<AtomicString*>(&names_storage)[38];
const AtomicString& kSubmitEvent = reinterpret_cast<AtomicString*>(&names_storage)[39];
const AtomicString& kTaskPriorityChangeEvent = reinterpret_cast<AtomicString*>(&names_storage)[40];
const AtomicString& kTextEvent = reinterpret_cast<AtomicString*>(&names_storage)[41];
const AtomicString& kTextFormatUpdateEvent = reinterpret_cast<AtomicString*>(&names_storage)[42];
const AtomicString& kTextUpdateEvent = reinterpret_cast<AtomicString*>(&names_storage)[43];
const AtomicString& kToggleEvent = reinterpret_cast<AtomicString*>(&names_storage)[44];
const AtomicString& kTouchEvent = reinterpret_cast<AtomicString*>(&names_storage)[45];
const AtomicString& kTrackEvent = reinterpret_cast<AtomicString*>(&names_storage)[46];
const AtomicString& kTransitionEvent = reinterpret_cast<AtomicString*>(&names_storage)[47];
const AtomicString& kUIEvent = reinterpret_cast<AtomicString*>(&names_storage)[48];
const AtomicString& kWheelEvent = reinterpret_cast<AtomicString*>(&names_storage)[49];

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
        { "AnimationEvent", 14 },
        { "AnimationPlaybackEvent", 22 },
        { "BeforeCreatePolicyEvent", 23 },
        { "BeforeUnloadEvent", 17 },
        { "CharacterBoundsUpdateEvent", 26 },
        { "ClipboardEvent", 14 },
        { "CommandEvent", 12 },
        { "CompositionEvent", 16 },
        { "ContentVisibilityAutoStateChangeEvent", 37 },
        { "CustomEvent", 11 },
        { "DragEvent", 9 },
        { "ErrorEvent", 10 },
        { "Event", 5 },
        { "FocusEvent", 10 },
        { "FontFaceSetLoadEvent", 20 },
        { "FormDataEvent", 13 },
        { "HashChangeEvent", 15 },
        { "HighlightPointerEvent", 21 },
        { "InputEvent", 10 },
        { "InterestEvent", 13 },
        { "KeyboardEvent", 13 },
        { "MediaQueryListEvent", 19 },
        { "MessageEvent", 12 },
        { "MojoInterfaceRequestEvent", 25 },
        { "MouseEvent", 10 },
        { "MutationEvent", 13 },
        { "NavigateEvent", 13 },
        { "NavigationCurrentEntryChangeEvent", 33 },
        { "OverscrollEvent", 15 },
        { "PageRevealEvent", 15 },
        { "PageSwapEvent", 13 },
        { "PageTransitionEvent", 19 },
        { "PointerEvent", 12 },
        { "PopStateEvent", 13 },
        { "ProgressEvent", 13 },
        { "PromiseRejectionEvent", 21 },
        { "ResourceProgressEvent", 21 },
        { "SecurityPolicyViolationEvent", 28 },
        { "SnapEvent", 9 },
        { "SubmitEvent", 11 },
        { "TaskPriorityChangeEvent", 23 },
        { "TextEvent", 9 },
        { "TextFormatUpdateEvent", 21 },
        { "TextUpdateEvent", 15 },
        { "ToggleEvent", 11 },
        { "TouchEvent", 10 },
        { "TrackEvent", 10 },
        { "TransitionEvent", 15 },
        { "UIEvent", 7 },
        { "WheelEvent", 10 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace event_interface_names
} // namespace blink
