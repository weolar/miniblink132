// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/modules/event_target_modules_names.json5

#include "third_party/blink/renderer/modules/event_target_modules_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace event_target_names {

void* modulesnames_storage[kModulesNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAICreateMonitor = reinterpret_cast<AtomicString*>(&modulesnames_storage)[0];
const AtomicString& kAILanguageModel = reinterpret_cast<AtomicString*>(&modulesnames_storage)[1];
const AtomicString& kAudioContext = reinterpret_cast<AtomicString*>(&modulesnames_storage)[2];
const AtomicString& kAudioDecoder = reinterpret_cast<AtomicString*>(&modulesnames_storage)[3];
const AtomicString& kAudioEncoder = reinterpret_cast<AtomicString*>(&modulesnames_storage)[4];
const AtomicString& kAudioNode = reinterpret_cast<AtomicString*>(&modulesnames_storage)[5];
const AtomicString& kBackgroundFetchRegistration = reinterpret_cast<AtomicString*>(&modulesnames_storage)[6];
const AtomicString& kBatteryManager = reinterpret_cast<AtomicString*>(&modulesnames_storage)[7];
const AtomicString& kBluetooth = reinterpret_cast<AtomicString*>(&modulesnames_storage)[8];
const AtomicString& kBluetoothDevice = reinterpret_cast<AtomicString*>(&modulesnames_storage)[9];
const AtomicString& kBluetoothRemoteGATTCharacteristic = reinterpret_cast<AtomicString*>(&modulesnames_storage)[10];
const AtomicString& kCaptureController = reinterpret_cast<AtomicString*>(&modulesnames_storage)[11];
const AtomicString& kCookieStore = reinterpret_cast<AtomicString*>(&modulesnames_storage)[12];
const AtomicString& kDelegatedInkTrail = reinterpret_cast<AtomicString*>(&modulesnames_storage)[13];
const AtomicString& kDevicePosture = reinterpret_cast<AtomicString*>(&modulesnames_storage)[14];
const AtomicString& kDocumentPictureInPicture = reinterpret_cast<AtomicString*>(&modulesnames_storage)[15];
const AtomicString& kEyeDropper = reinterpret_cast<AtomicString*>(&modulesnames_storage)[16];
const AtomicString& kFileWriter = reinterpret_cast<AtomicString*>(&modulesnames_storage)[17];
const AtomicString& kGPUDevice = reinterpret_cast<AtomicString*>(&modulesnames_storage)[18];
const AtomicString& kHID = reinterpret_cast<AtomicString*>(&modulesnames_storage)[19];
const AtomicString& kHIDDevice = reinterpret_cast<AtomicString*>(&modulesnames_storage)[20];
const AtomicString& kHTMLVideoElementPictureInPicture = reinterpret_cast<AtomicString*>(&modulesnames_storage)[21];
const AtomicString& kIDBDatabase = reinterpret_cast<AtomicString*>(&modulesnames_storage)[22];
const AtomicString& kIDBOpenDBRequest = reinterpret_cast<AtomicString*>(&modulesnames_storage)[23];
const AtomicString& kIDBRequest = reinterpret_cast<AtomicString*>(&modulesnames_storage)[24];
const AtomicString& kIDBTransaction = reinterpret_cast<AtomicString*>(&modulesnames_storage)[25];
const AtomicString& kIdleDetector = reinterpret_cast<AtomicString*>(&modulesnames_storage)[26];
const AtomicString& kImageCapture = reinterpret_cast<AtomicString*>(&modulesnames_storage)[27];
const AtomicString& kMIDIAccess = reinterpret_cast<AtomicString*>(&modulesnames_storage)[28];
const AtomicString& kMIDIInput = reinterpret_cast<AtomicString*>(&modulesnames_storage)[29];
const AtomicString& kMIDIPort = reinterpret_cast<AtomicString*>(&modulesnames_storage)[30];
const AtomicString& kMediaDevices = reinterpret_cast<AtomicString*>(&modulesnames_storage)[31];
const AtomicString& kMediaKeySession = reinterpret_cast<AtomicString*>(&modulesnames_storage)[32];
const AtomicString& kMediaRecorder = reinterpret_cast<AtomicString*>(&modulesnames_storage)[33];
const AtomicString& kMediaSource = reinterpret_cast<AtomicString*>(&modulesnames_storage)[34];
const AtomicString& kMediaStream = reinterpret_cast<AtomicString*>(&modulesnames_storage)[35];
const AtomicString& kMediaStreamTrack = reinterpret_cast<AtomicString*>(&modulesnames_storage)[36];
const AtomicString& kNDEFReader = reinterpret_cast<AtomicString*>(&modulesnames_storage)[37];
const AtomicString& kNavigatorManagedData = reinterpret_cast<AtomicString*>(&modulesnames_storage)[38];
const AtomicString& kNetworkInformation = reinterpret_cast<AtomicString*>(&modulesnames_storage)[39];
const AtomicString& kNotification = reinterpret_cast<AtomicString*>(&modulesnames_storage)[40];
const AtomicString& kPaymentRequest = reinterpret_cast<AtomicString*>(&modulesnames_storage)[41];
const AtomicString& kPermissionStatus = reinterpret_cast<AtomicString*>(&modulesnames_storage)[42];
const AtomicString& kPictureInPictureWindow = reinterpret_cast<AtomicString*>(&modulesnames_storage)[43];
const AtomicString& kPresentationAvailability = reinterpret_cast<AtomicString*>(&modulesnames_storage)[44];
const AtomicString& kPresentationConnection = reinterpret_cast<AtomicString*>(&modulesnames_storage)[45];
const AtomicString& kPresentationConnectionList = reinterpret_cast<AtomicString*>(&modulesnames_storage)[46];
const AtomicString& kPresentationRequest = reinterpret_cast<AtomicString*>(&modulesnames_storage)[47];
const AtomicString& kRTCDTMFSender = reinterpret_cast<AtomicString*>(&modulesnames_storage)[48];
const AtomicString& kRTCDataChannel = reinterpret_cast<AtomicString*>(&modulesnames_storage)[49];
const AtomicString& kRTCDtlsTransport = reinterpret_cast<AtomicString*>(&modulesnames_storage)[50];
const AtomicString& kRTCIceTransport = reinterpret_cast<AtomicString*>(&modulesnames_storage)[51];
const AtomicString& kRTCPeerConnection = reinterpret_cast<AtomicString*>(&modulesnames_storage)[52];
const AtomicString& kRTCSctpTransport = reinterpret_cast<AtomicString*>(&modulesnames_storage)[53];
const AtomicString& kRemotePlayback = reinterpret_cast<AtomicString*>(&modulesnames_storage)[54];
const AtomicString& kScreenDetails = reinterpret_cast<AtomicString*>(&modulesnames_storage)[55];
const AtomicString& kScreenOrientation = reinterpret_cast<AtomicString*>(&modulesnames_storage)[56];
const AtomicString& kSensor = reinterpret_cast<AtomicString*>(&modulesnames_storage)[57];
const AtomicString& kSerial = reinterpret_cast<AtomicString*>(&modulesnames_storage)[58];
const AtomicString& kSerialPort = reinterpret_cast<AtomicString*>(&modulesnames_storage)[59];
const AtomicString& kServiceWorker = reinterpret_cast<AtomicString*>(&modulesnames_storage)[60];
const AtomicString& kServiceWorkerContainer = reinterpret_cast<AtomicString*>(&modulesnames_storage)[61];
const AtomicString& kServiceWorkerGlobalScope = reinterpret_cast<AtomicString*>(&modulesnames_storage)[62];
const AtomicString& kServiceWorkerRegistration = reinterpret_cast<AtomicString*>(&modulesnames_storage)[63];
const AtomicString& kSmartCardReader = reinterpret_cast<AtomicString*>(&modulesnames_storage)[64];
const AtomicString& kSmartCardReaderPresenceObserver = reinterpret_cast<AtomicString*>(&modulesnames_storage)[65];
const AtomicString& kSourceBuffer = reinterpret_cast<AtomicString*>(&modulesnames_storage)[66];
const AtomicString& kSourceBufferList = reinterpret_cast<AtomicString*>(&modulesnames_storage)[67];
const AtomicString& kSpeechRecognition = reinterpret_cast<AtomicString*>(&modulesnames_storage)[68];
const AtomicString& kSpeechSynthesis = reinterpret_cast<AtomicString*>(&modulesnames_storage)[69];
const AtomicString& kSpeechSynthesisUtterance = reinterpret_cast<AtomicString*>(&modulesnames_storage)[70];
const AtomicString& kUSB = reinterpret_cast<AtomicString*>(&modulesnames_storage)[71];
const AtomicString& kVideoDecoder = reinterpret_cast<AtomicString*>(&modulesnames_storage)[72];
const AtomicString& kVideoEncoder = reinterpret_cast<AtomicString*>(&modulesnames_storage)[73];
const AtomicString& kVirtualKeyboard = reinterpret_cast<AtomicString*>(&modulesnames_storage)[74];
const AtomicString& kWakeLockSentinel = reinterpret_cast<AtomicString*>(&modulesnames_storage)[75];
const AtomicString& kWebOTPService = reinterpret_cast<AtomicString*>(&modulesnames_storage)[76];
const AtomicString& kWebSocket = reinterpret_cast<AtomicString*>(&modulesnames_storage)[77];
const AtomicString& kWindowControlsOverlay = reinterpret_cast<AtomicString*>(&modulesnames_storage)[78];
const AtomicString& kXR = reinterpret_cast<AtomicString*>(&modulesnames_storage)[79];
const AtomicString& kXRLayer = reinterpret_cast<AtomicString*>(&modulesnames_storage)[80];
const AtomicString& kXRLightProbe = reinterpret_cast<AtomicString*>(&modulesnames_storage)[81];
const AtomicString& kXRSession = reinterpret_cast<AtomicString*>(&modulesnames_storage)[82];
const AtomicString& kXRSpace = reinterpret_cast<AtomicString*>(&modulesnames_storage)[83];

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
        { "AICreateMonitor", 15 },
        { "AILanguageModel", 15 },
        { "AudioContext", 12 },
        { "AudioDecoder", 12 },
        { "AudioEncoder", 12 },
        { "AudioNode", 9 },
        { "BackgroundFetchRegistration", 27 },
        { "BatteryManager", 14 },
        { "Bluetooth", 9 },
        { "BluetoothDevice", 15 },
        { "BluetoothRemoteGATTCharacteristic", 33 },
        { "CaptureController", 17 },
        { "CookieStore", 11 },
        { "DelegatedInkTrail", 17 },
        { "DevicePosture", 13 },
        { "DocumentPictureInPicture", 24 },
        { "EyeDropper", 10 },
        { "FileWriter", 10 },
        { "GPUDevice", 9 },
        { "HID", 3 },
        { "HIDDevice", 9 },
        { "HTMLVideoElementPictureInPicture", 32 },
        { "IDBDatabase", 11 },
        { "IDBOpenDBRequest", 16 },
        { "IDBRequest", 10 },
        { "IDBTransaction", 14 },
        { "IdleDetector", 12 },
        { "ImageCapture", 12 },
        { "MIDIAccess", 10 },
        { "MIDIInput", 9 },
        { "MIDIPort", 8 },
        { "MediaDevices", 12 },
        { "MediaKeySession", 15 },
        { "MediaRecorder", 13 },
        { "MediaSource", 11 },
        { "MediaStream", 11 },
        { "MediaStreamTrack", 16 },
        { "NDEFReader", 10 },
        { "NavigatorManagedData", 20 },
        { "NetworkInformation", 18 },
        { "Notification", 12 },
        { "PaymentRequest", 14 },
        { "PermissionStatus", 16 },
        { "PictureInPictureWindow", 22 },
        { "PresentationAvailability", 24 },
        { "PresentationConnection", 22 },
        { "PresentationConnectionList", 26 },
        { "PresentationRequest", 19 },
        { "RTCDTMFSender", 13 },
        { "RTCDataChannel", 14 },
        { "RTCDtlsTransport", 16 },
        { "RTCIceTransport", 15 },
        { "RTCPeerConnection", 17 },
        { "RTCSctpTransport", 16 },
        { "RemotePlayback", 14 },
        { "ScreenDetails", 13 },
        { "ScreenOrientation", 17 },
        { "Sensor", 6 },
        { "Serial", 6 },
        { "SerialPort", 10 },
        { "ServiceWorker", 13 },
        { "ServiceWorkerContainer", 22 },
        { "ServiceWorkerGlobalScope", 24 },
        { "ServiceWorkerRegistration", 25 },
        { "SmartCardReader", 15 },
        { "SmartCardReaderPresenceObserver", 31 },
        { "SourceBuffer", 12 },
        { "SourceBufferList", 16 },
        { "SpeechRecognition", 17 },
        { "SpeechSynthesis", 15 },
        { "SpeechSynthesisUtterance", 24 },
        { "USB", 3 },
        { "VideoDecoder", 12 },
        { "VideoEncoder", 12 },
        { "VirtualKeyboard", 15 },
        { "WakeLockSentinel", 16 },
        { "WebOTPService", 13 },
        { "DOMWebSocket", 12 },
        { "WindowControlsOverlay", 21 },
        { "XR", 2 },
        { "XRLayer", 7 },
        { "XRLightProbe", 12 },
        { "XRSession", 9 },
        { "XRSpace", 7 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&modulesnames_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace event_target_names
} // namespace blink
