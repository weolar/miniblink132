// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/events/event_target_names.json5

#include "third_party/blink/renderer/core/event_target_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace event_target_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAbortSignal = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kAnimation = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kApplicationCache = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kAudioTrackList = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kBroadcastChannel = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kClipboard = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kCloseWatcher = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kDedicatedWorkerGlobalScope = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kEditContext = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kEventSource = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kEventTargetImpl = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kFileReader = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kFontFaceSet = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kInputMethodContext = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kMediaQueryList = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kMessagePort = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kMojoInterfaceInterceptor = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kNavigation = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kNavigationHistoryEntry = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kNode = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kOffscreenCanvas = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kPerformance = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kPreferenceObject = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kProfiler = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kScreen = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kShadowRealmGlobalScope = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kSharedWorker = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kSharedWorkerGlobalScope = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kTextTrack = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kTextTrackCue = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kTextTrackList = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kTrustedTypePolicyFactory = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kVideoTrackList = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kVisualViewport = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kWebPrintJob = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kWindow = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kWorker = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kXMLHttpRequest = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kXMLHttpRequestUpload = reinterpret_cast<AtomicString*>(&names_storage)[38];

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
        { "AbortSignal", 11 },
        { "Animation", 9 },
        { "ApplicationCache", 16 },
        { "AudioTrackList", 14 },
        { "BroadcastChannel", 16 },
        { "Clipboard", 9 },
        { "CloseWatcher", 12 },
        { "DedicatedWorkerGlobalScope", 26 },
        { "EditContext", 11 },
        { "EventSource", 11 },
        { "EventTargetImpl", 15 },
        { "FileReader", 10 },
        { "FontFaceSet", 11 },
        { "InputMethodContext", 18 },
        { "MediaQueryList", 14 },
        { "MessagePort", 11 },
        { "MojoInterfaceInterceptor", 24 },
        { "Navigation", 10 },
        { "NavigationHistoryEntry", 22 },
        { "Node", 4 },
        { "OffscreenCanvas", 15 },
        { "Performance", 11 },
        { "PreferenceObject", 16 },
        { "Profiler", 8 },
        { "Screen", 6 },
        { "ShadowRealmGlobalScope", 22 },
        { "SharedWorker", 12 },
        { "SharedWorkerGlobalScope", 23 },
        { "TextTrack", 9 },
        { "TextTrackCue", 12 },
        { "TextTrackList", 13 },
        { "TrustedTypePolicyFactory", 24 },
        { "VideoTrackList", 14 },
        { "DOMVisualViewport", 17 },
        { "WebPrintJob", 11 },
        { "DOMWindow", 9 },
        { "Worker", 6 },
        { "XMLHttpRequest", 14 },
        { "XMLHttpRequestUpload", 20 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace event_target_names
} // namespace blink
