// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   gen/third_party/blink/renderer/modules/event_interface_modules_names.json5

#include "third_party/blink/renderer/modules/event_interface_modules_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace event_interface_names {

void* modulesnames_storage[kModulesNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAbortPaymentEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[0];
const AtomicString& kAudioProcessingEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[1];
const AtomicString& kBackgroundFetchEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[2];
const AtomicString& kBackgroundFetchUpdateUIEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[3];
const AtomicString& kBeforeInstallPromptEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[4];
const AtomicString& kBlobEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[5];
const AtomicString& kBluetoothAdvertisingEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[6];
const AtomicString& kCanMakePaymentEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[7];
const AtomicString& kCapturedMouseEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[8];
const AtomicString& kCloseEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[9];
const AtomicString& kContentIndexEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[10];
const AtomicString& kCookieChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[11];
const AtomicString& kDeviceMotionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[12];
const AtomicString& kDeviceOrientationEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[13];
const AtomicString& kDocumentPictureInPictureEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[14];
const AtomicString& kExtendableCookieChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[15];
const AtomicString& kExtendableEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[16];
const AtomicString& kExtendableMessageEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[17];
const AtomicString& kFetchEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[18];
const AtomicString& kGPUUncapturedErrorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[19];
const AtomicString& kGamepadEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[20];
const AtomicString& kHIDConnectionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[21];
const AtomicString& kHIDInputReportEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[22];
const AtomicString& kIDBVersionChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[23];
const AtomicString& kInstallEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[24];
const AtomicString& kMIDIConnectionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[25];
const AtomicString& kMIDIMessageEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[26];
const AtomicString& kMediaEncryptedEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[27];
const AtomicString& kMediaKeyMessageEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[28];
const AtomicString& kMediaStreamEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[29];
const AtomicString& kMediaStreamTrackEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[30];
const AtomicString& kNDEFReadingEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[31];
const AtomicString& kNotificationEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[32];
const AtomicString& kOfflineAudioCompletionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[33];
const AtomicString& kPaymentMethodChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[34];
const AtomicString& kPaymentRequestEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[35];
const AtomicString& kPaymentRequestUpdateEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[36];
const AtomicString& kPeriodicSyncEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[37];
const AtomicString& kPictureInPictureEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[38];
const AtomicString& kPresentationConnectionAvailableEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[39];
const AtomicString& kPresentationConnectionCloseEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[40];
const AtomicString& kPushEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[41];
const AtomicString& kPushSubscriptionChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[42];
const AtomicString& kRTCDTMFToneChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[43];
const AtomicString& kRTCDataChannelEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[44];
const AtomicString& kRTCErrorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[45];
const AtomicString& kRTCPeerConnectionIceErrorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[46];
const AtomicString& kRTCPeerConnectionIceEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[47];
const AtomicString& kRTCRtpTransportProcessorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[48];
const AtomicString& kRTCTrackEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[49];
const AtomicString& kRTCTransformEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[50];
const AtomicString& kSensorErrorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[51];
const AtomicString& kSpeechRecognitionErrorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[52];
const AtomicString& kSpeechRecognitionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[53];
const AtomicString& kSpeechSynthesisErrorEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[54];
const AtomicString& kSpeechSynthesisEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[55];
const AtomicString& kStorageEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[56];
const AtomicString& kSyncEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[57];
const AtomicString& kUSBConnectionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[58];
const AtomicString& kVirtualKeyboardGeometryChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[59];
const AtomicString& kWebGLContextEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[60];
const AtomicString& kWindowControlsOverlayGeometryChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[61];
const AtomicString& kXRInputSourceEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[62];
const AtomicString& kXRInputSourcesChangeEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[63];
const AtomicString& kXRReferenceSpaceEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[64];
const AtomicString& kXRSessionEvent = reinterpret_cast<AtomicString*>(&modulesnames_storage)[65];

void InitModules()
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
        { "AbortPaymentEvent", 17 },
        { "AudioProcessingEvent", 20 },
        { "BackgroundFetchEvent", 20 },
        { "BackgroundFetchUpdateUIEvent", 28 },
        { "BeforeInstallPromptEvent", 24 },
        { "BlobEvent", 9 },
        { "BluetoothAdvertisingEvent", 25 },
        { "CanMakePaymentEvent", 19 },
        { "CapturedMouseEvent", 18 },
        { "CloseEvent", 10 },
        { "ContentIndexEvent", 17 },
        { "CookieChangeEvent", 17 },
        { "DeviceMotionEvent", 17 },
        { "DeviceOrientationEvent", 22 },
        { "DocumentPictureInPictureEvent", 29 },
        { "ExtendableCookieChangeEvent", 27 },
        { "ExtendableEvent", 15 },
        { "ExtendableMessageEvent", 22 },
        { "FetchEvent", 10 },
        { "GPUUncapturedErrorEvent", 23 },
        { "GamepadEvent", 12 },
        { "HIDConnectionEvent", 18 },
        { "HIDInputReportEvent", 19 },
        { "IDBVersionChangeEvent", 21 },
        { "InstallEvent", 12 },
        { "MIDIConnectionEvent", 19 },
        { "MIDIMessageEvent", 16 },
        { "MediaEncryptedEvent", 19 },
        { "MediaKeyMessageEvent", 20 },
        { "MediaStreamEvent", 16 },
        { "MediaStreamTrackEvent", 21 },
        { "NDEFReadingEvent", 16 },
        { "NotificationEvent", 17 },
        { "OfflineAudioCompletionEvent", 27 },
        { "PaymentMethodChangeEvent", 24 },
        { "PaymentRequestEvent", 19 },
        { "PaymentRequestUpdateEvent", 25 },
        { "PeriodicSyncEvent", 17 },
        { "PictureInPictureEvent", 21 },
        { "PresentationConnectionAvailableEvent", 36 },
        { "PresentationConnectionCloseEvent", 32 },
        { "PushEvent", 9 },
        { "PushSubscriptionChangeEvent", 27 },
        { "RTCDTMFToneChangeEvent", 22 },
        { "RTCDataChannelEvent", 19 },
        { "RTCErrorEvent", 13 },
        { "RTCPeerConnectionIceErrorEvent", 30 },
        { "RTCPeerConnectionIceEvent", 25 },
        { "RTCRtpTransportProcessorEvent", 29 },
        { "RTCTrackEvent", 13 },
        { "RTCTransformEvent", 17 },
        { "SensorErrorEvent", 16 },
        { "SpeechRecognitionErrorEvent", 27 },
        { "SpeechRecognitionEvent", 22 },
        { "SpeechSynthesisErrorEvent", 25 },
        { "SpeechSynthesisEvent", 20 },
        { "StorageEvent", 12 },
        { "SyncEvent", 9 },
        { "USBConnectionEvent", 18 },
        { "VirtualKeyboardGeometryChangeEvent", 34 },
        { "WebGLContextEvent", 17 },
        { "WindowControlsOverlayGeometryChangeEvent", 40 },
        { "XRInputSourceEvent", 18 },
        { "XRInputSourcesChangeEvent", 25 },
        { "XRReferenceSpaceEvent", 21 },
        { "XRSessionEvent", 14 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&modulesnames_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace event_interface_names
} // namespace blink
