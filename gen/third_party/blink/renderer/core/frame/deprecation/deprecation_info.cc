// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/deprecation_info.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/frame/deprecation/deprecation.json5

#include "third_party/blink/renderer/core/frame/deprecation/deprecation_info.h"

#include "third_party/blink/renderer/core/frame/web_feature.h"

namespace blink {

const char kNotDeprecated[] = "NotDeprecated";

const DeprecationInfo GetDeprecationInfo(WebFeature feature)
{
    switch (feature) {
    case WebFeature::kAuthorizationCoveredByWildcard:
        return DeprecationInfo::Create(feature, "AuthorizationCoveredByWildcard",
            "Authorization will not be covered by the wildcard symbol (*) in CORS `Access-Control-Allow-Headers` handling.");
    case WebFeature::kCanRequestURLHTTPContainingNewline:
        return DeprecationInfo::Create(feature, "CanRequestURLHTTPContainingNewline",
            "Resource requests whose URLs contained both removed whitespace `\\(n|r|t)` characters and less-than characters (`<`) are blocked. Please remove "
            "newlines and encode less-than characters from places like element attribute values in order to load these resources.");
    case WebFeature::kChromeLoadTimesCommitLoadTime:
    case WebFeature::kChromeLoadTimesConnectionInfo:
    case WebFeature::kChromeLoadTimesFinishDocumentLoadTime:
    case WebFeature::kChromeLoadTimesFinishLoadTime:
    case WebFeature::kChromeLoadTimesNavigationType:
    case WebFeature::kChromeLoadTimesRequestTime:
    case WebFeature::kChromeLoadTimesStartLoadTime:
        return DeprecationInfo::Create(
            feature, "ChromeLoadTimesConnectionInfo", "`chrome.loadTimes()` is deprecated, instead use standardized API: Navigation Timing 2.");
    case WebFeature::kChromeLoadTimesFirstPaintAfterLoadTime:
    case WebFeature::kChromeLoadTimesFirstPaintTime:
        return DeprecationInfo::Create(
            feature, "ChromeLoadTimesFirstPaintAfterLoadTime", "`chrome.loadTimes()` is deprecated, instead use standardized API: Paint Timing.");
    case WebFeature::kChromeLoadTimesNpnNegotiatedProtocol:
    case WebFeature::kChromeLoadTimesWasAlternateProtocolAvailable:
    case WebFeature::kChromeLoadTimesWasFetchedViaSpdy:
    case WebFeature::kChromeLoadTimesWasNpnNegotiated:
        return DeprecationInfo::Create(feature, "ChromeLoadTimesWasAlternateProtocolAvailable",
            "`chrome.loadTimes()` is deprecated, instead use standardized API: `nextHopProtocol` in Navigation Timing 2.");
    case WebFeature::kCookieWithTruncatingChar:
        return DeprecationInfo::Create(
            feature, "CookieWithTruncatingChar", "Cookies containing a `\\(0|r|n)` character will be rejected instead of truncated.");
    case WebFeature::kCrossOriginAccessBasedOnDocumentDomain:
        return DeprecationInfo::Create(feature, "CrossOriginAccessBasedOnDocumentDomain",
            "Relaxing the same-origin policy by setting `document.domain` is deprecated, and will be disabled by default. This deprecation warning is for a "
            "cross-origin access that was enabled by setting `document.domain`.");
    case WebFeature::kCrossOriginWindowAlert:
        return DeprecationInfo::Create(
            feature, "CrossOriginWindowAlert", "Triggering window.alert from cross origin iframes has been deprecated and will be removed in the future.");
    case WebFeature::kCrossOriginWindowConfirm:
        return DeprecationInfo::Create(
            feature, "CrossOriginWindowConfirm", "Triggering window.confirm from cross origin iframes has been deprecated and will be removed in the future.");
    case WebFeature::kCSSCustomStateDeprecatedSyntax:
        return DeprecationInfo::Create(
            feature, "CSSCustomStateDeprecatedSyntax", "`:--customstatename` is deprecated. Please use the `:state(customstatename)` syntax instead.");
    case WebFeature::kCSSInsetAreaProperty:
        return DeprecationInfo::Create(
            feature, "CSSInsetAreaProperty", "The `inset-area` property is deprecated. Please use the `position-area` property instead.");
    case WebFeature::kCSSSelectorInternalMediaControlsOverlayCastButton:
        return DeprecationInfo::Create(feature, "CSSSelectorInternalMediaControlsOverlayCastButton",
            "The `disableRemotePlayback` attribute should be used in order to disable the default Cast integration instead of using "
            "`-internal-media-controls-overlay-cast-button` selector.");
    case WebFeature::kCSSValueAppearanceSliderVertical:
        return DeprecationInfo::Create(
            feature, "CSSValueAppearanceSliderVertical", "CSS appearance value `slider-vertical` is not standardized and will be removed.");
    case WebFeature::kDataUrlInSvgUse:
        return DeprecationInfo::Create(
            feature, "DataUrlInSvgUse", "Support for data: URLs in SVGUseElement is deprecated and it will be removed in the future.");
    case WebFeature::kDOMCharacterDataModifiedEvent:
    case WebFeature::kDOMNodeInsertedEvent:
    case WebFeature::kDOMNodeInsertedIntoDocumentEvent:
    case WebFeature::kDOMNodeRemovedEvent:
    case WebFeature::kDOMNodeRemovedFromDocumentEvent:
    case WebFeature::kDOMSubtreeModifiedEvent:
        return DeprecationInfo::Create(feature, "DOMMutationEvents",
            "DOM Mutation Events, including `DOMSubtreeModified`, `DOMNodeInserted`, `DOMNodeRemoved`, `DOMNodeRemovedFromDocument`, "
            "`DOMNodeInsertedIntoDocument`, and `DOMCharacterDataModified` are deprecated (https://w3c.github.io/uievents/#legacy-event-types) and will be "
            "removed. Please use `MutationObserver` instead.");
    case WebFeature::kGeolocationInsecureOrigin:
    case WebFeature::kGeolocationInsecureOriginIframe:
        return DeprecationInfo::Create(feature, "GeolocationInsecureOrigin",
            "`getCurrentPosition()` and `watchPosition()` no longer work on insecure origins. To use this feature, you should consider switching your "
            "application to a secure origin, such as HTTPS. See https://goo.gle/chrome-insecure-origins for more details.");
    case WebFeature::kGeolocationInsecureOriginDeprecatedNotRemoved:
    case WebFeature::kGeolocationInsecureOriginIframeDeprecatedNotRemoved:
        return DeprecationInfo::Create(feature, "GeolocationInsecureOriginDeprecatedNotRemoved",
            "`getCurrentPosition()` and `watchPosition()` are deprecated on insecure origins. To use this feature, you should consider switching your "
            "application to a secure origin, such as HTTPS. See https://goo.gle/chrome-insecure-origins for more details.");
    case WebFeature::kElementGetInnerHTML:
        return DeprecationInfo::Create(feature, "GetInnerHTML",
            "The getInnerHTML() function is deprecated, and will be removed from this browser very soon. Please use getHTML() instead.");
    case WebFeature::kGetUserMediaInsecureOrigin:
    case WebFeature::kGetUserMediaInsecureOriginIframe:
        return DeprecationInfo::Create(feature, "GetUserMediaInsecureOrigin",
            "`getUserMedia()` no longer works on insecure origins. To use this feature, you should consider switching your application to a secure origin, "
            "such as HTTPS. See https://goo.gle/chrome-insecure-origins for more details.");
    case WebFeature::kHostCandidateAttributeGetter:
        return DeprecationInfo::Create(feature, "HostCandidateAttributeGetter",
            "`RTCPeerConnectionIceErrorEvent.hostCandidate` is deprecated. Please use `RTCPeerConnectionIceErrorEvent.address` or "
            "`RTCPeerConnectionIceErrorEvent.port` instead.");
    case WebFeature::kIdentityInCanMakePaymentEvent:
        return DeprecationInfo::Create(feature, "IdentityInCanMakePaymentEvent",
            "The merchant origin and arbitrary data from the `canmakepayment` service worker event are deprecated and will be removed: `topOrigin`, "
            "`paymentRequestOrigin`, `methodData`, `modifiers`.");
    case WebFeature::kAddressSpacePrivateNonSecureContextEmbeddedLocal:
    case WebFeature::kAddressSpacePublicNonSecureContextEmbeddedLocal:
    case WebFeature::kAddressSpacePublicNonSecureContextEmbeddedPrivate:
        return DeprecationInfo::Create(feature, "InsecurePrivateNetworkSubresourceRequest",
            "The website requested a subresource from a network that it could only access because of its users' privileged network position. These requests "
            "expose non-public devices and servers to the internet, increasing the risk of a cross-site request forgery (CSRF) attack, and/or information "
            "leakage. To mitigate these risks, Chrome deprecates requests to non-public subresources when initiated from non-secure contexts, and will start "
            "blocking them.");
    case WebFeature::kDeprecatedInterestGroupDailyUpdateUrl:
        return DeprecationInfo::Create(feature, "InterestGroupDailyUpdateUrl",
            "The `dailyUpdateUrl` field of `InterestGroups` passed to `joinAdInterestGroup()` has been renamed to `updateUrl`, to more accurately reflect its "
            "behavior.");
    case WebFeature::kLocalCSSFileExtensionRejected:
        return DeprecationInfo::Create(
            feature, "LocalCSSFileExtensionRejected", "CSS cannot be loaded from `file:` URLs unless they end in a `.css` file extension.");
    case WebFeature::kMediaSourceAbortRemove:
        return DeprecationInfo::Create(feature, "MediaSourceAbortRemove",
            "Using `SourceBuffer.abort()` to abort `remove()`'s asynchronous range removal is deprecated due to specification change. Support will be removed "
            "in the future. You should listen to the `updateend` event instead. `abort()` is intended to only abort an asynchronous media append or reset "
            "parser state.");
    case WebFeature::kMediaSourceDurationTruncatingBuffered:
        return DeprecationInfo::Create(feature, "MediaSourceDurationTruncatingBuffered",
            "Setting `MediaSource.duration` below the highest presentation timestamp of any buffered coded frames is deprecated due to specification change. "
            "Support for implicit removal of truncated buffered media will be removed in the future. You should instead perform explicit `remove(newDuration, "
            "oldDuration)` on all `sourceBuffers`, where `newDuration < oldDuration`.");
    case WebFeature::kNoSysexWebMIDIWithoutPermission:
        return DeprecationInfo::Create(
            feature, "NoSysexWebMIDIWithoutPermission", "Web MIDI will ask a permission to use even if the sysex is not specified in the `MIDIOptions`.");
    case WebFeature::kNotificationAPIInsecureOriginIframe:
    case WebFeature::kNotificationInsecureOrigin:
    case WebFeature::kNotificationPermissionRequestedInsecureOrigin:
        return DeprecationInfo::Create(feature, "NotificationInsecureOrigin",
            "The Notification API may no longer be used from insecure origins. You should consider switching your application to a secure origin, such as "
            "HTTPS. See https://goo.gle/chrome-insecure-origins for more details.");
    case WebFeature::kNotificationPermissionRequestedIframe:
        return DeprecationInfo::Create(feature, "NotificationPermissionRequestedIframe",
            "Permission for the Notification API may no longer be requested from a cross-origin iframe. You should consider requesting permission from a "
            "top-level frame or opening a new window instead.");
    case WebFeature::kObsoleteCreateImageBitmapImageOrientationNone:
        return DeprecationInfo::Create(feature, "ObsoleteCreateImageBitmapImageOrientationNone",
            "Option `imageOrientation: 'none'` in createImageBitmap is deprecated. Please use createImageBitmap with option {imageOrientation: 'from-image'} "
            "instead.");
    case WebFeature::kObsoleteWebrtcTlsVersion:
        return DeprecationInfo::Create(
            feature, "ObsoleteWebRtcCipherSuite", "Your partner is negotiating an obsolete (D)TLS version. Please check with your partner to have this fixed.");
    case WebFeature::kExplicitOverflowVisibleOnReplacedElement:
        return DeprecationInfo::Create(feature, "OverflowVisibleOnReplacedElement",
            "Specifying `overflow: visible` on img, video and canvas tags may cause them to produce visual content outside of the element bounds. See "
            "https://github.com/WICG/shared-element-transitions/blob/main/debugging_overflow_on_images.md.");
    case WebFeature::kPaymentInstruments:
        return DeprecationInfo::Create(
            feature, "PaymentInstruments", "`paymentManager.instruments` is deprecated. Please use just-in-time install for payment handlers instead.");
    case WebFeature::kPaymentRequestCSPViolation:
        return DeprecationInfo::Create(feature, "PaymentRequestCSPViolation",
            "Your `PaymentRequest` call bypassed Content-Security-Policy (CSP) `connect-src` directive. This bypass is deprecated. Please add the payment "
            "method identifier from the `PaymentRequest` API (in `supportedMethods` field) to your CSP `connect-src` directive.");
    case WebFeature::kPersistentQuotaType:
        return DeprecationInfo::Create(
            feature, "PersistentQuotaType", "`StorageType.persistent` is deprecated. Please use standardized `navigator.storage` instead.");
    case WebFeature::kPictureSourceSrc:
        return DeprecationInfo::Create(
            feature, "PictureSourceSrc", "`<source src>` with a `<picture>` parent is invalid and therefore ignored. Please use `<source srcset>` instead.");
    case WebFeature::kPrefixedCancelAnimationFrame:
        return DeprecationInfo::Create(
            feature, "PrefixedCancelAnimationFrame", "webkitCancelAnimationFrame is vendor-specific. Please use the standard cancelAnimationFrame instead.");
    case WebFeature::kPrefixedRequestAnimationFrame:
        return DeprecationInfo::Create(
            feature, "PrefixedRequestAnimationFrame", "webkitRequestAnimationFrame is vendor-specific. Please use the standard requestAnimationFrame instead.");
    case WebFeature::kPrefixedVideoDisplayingFullscreen:
        return DeprecationInfo::Create(feature, "PrefixedVideoDisplayingFullscreen",
            "HTMLVideoElement.webkitDisplayingFullscreen is deprecated. Please use Document.fullscreenElement instead.");
    case WebFeature::kPrefixedVideoEnterFullScreen:
        return DeprecationInfo::Create(
            feature, "PrefixedVideoEnterFullScreen", "HTMLVideoElement.webkitEnterFullScreen() is deprecated. Please use Element.requestFullscreen() instead.");
    case WebFeature::kPrefixedVideoEnterFullscreen:
        return DeprecationInfo::Create(
            feature, "PrefixedVideoEnterFullscreen", "HTMLVideoElement.webkitEnterFullscreen() is deprecated. Please use Element.requestFullscreen() instead.");
    case WebFeature::kPrefixedVideoExitFullScreen:
        return DeprecationInfo::Create(
            feature, "PrefixedVideoExitFullScreen", "HTMLVideoElement.webkitExitFullScreen() is deprecated. Please use Document.exitFullscreen() instead.");
    case WebFeature::kPrefixedVideoExitFullscreen:
        return DeprecationInfo::Create(
            feature, "PrefixedVideoExitFullscreen", "HTMLVideoElement.webkitExitFullscreen() is deprecated. Please use Document.exitFullscreen() instead.");
    case WebFeature::kPrefixedVideoSupportsFullscreen:
        return DeprecationInfo::Create(feature, "PrefixedVideoSupportsFullscreen",
            "HTMLVideoElement.webkitSupportsFullscreen is deprecated. Please use Document.fullscreenEnabled instead.");
    case WebFeature::kRangeExpand:
        return DeprecationInfo::Create(feature, "RangeExpand", "Range.expand() is deprecated. Please use Selection.modify() instead.");
    case WebFeature::kRequestedSubresourceWithEmbeddedCredentials:
        return DeprecationInfo::Create(feature, "RequestedSubresourceWithEmbeddedCredentials",
            "Subresource requests whose URLs contain embedded credentials (e.g. `https://user:pass@host/`) are blocked.");
    case WebFeature::kRTCConstraintEnableDtlsSrtpFalse:
        return DeprecationInfo::Create(feature, "RTCConstraintEnableDtlsSrtpFalse",
            "The constraint `DtlsSrtpKeyAgreement` is removed. You have specified a `false` value for this constraint, which is interpreted as an attempt to "
            "use the removed `SDES key negotiation` method. This functionality is removed; use a service that supports `DTLS key negotiation` instead.");
    case WebFeature::kRTCConstraintEnableDtlsSrtpTrue:
        return DeprecationInfo::Create(feature, "RTCConstraintEnableDtlsSrtpTrue",
            "The constraint `DtlsSrtpKeyAgreement` is removed. You have specified a `true` value for this constraint, which had no effect, but you can remove "
            "this constraint for tidiness.");
    case WebFeature::kRTCPeerConnectionGetStatsLegacyNonCompliant:
        return DeprecationInfo::Create(feature, "RTCPeerConnectionGetStatsLegacyNonCompliant",
            "The callback-based getStats() is deprecated and will be removed. Use the spec-compliant getStats() instead.");
    case WebFeature::kRtcpMuxPolicyNegotiate:
        return DeprecationInfo::Create(feature, "RtcpMuxPolicyNegotiate", "The `rtcpMuxPolicy` option is deprecated and will be removed.");
    case WebFeature::kV8SharedArrayBufferConstructedWithoutIsolation:
        return DeprecationInfo::Create(feature, "SharedArrayBufferConstructedWithoutIsolation",
            "`SharedArrayBuffer` will require cross-origin isolation. See https://developer.chrome.com/blog/enabling-shared-array-buffer/ for more details.");
    case WebFeature::kTextToSpeech_SpeakDisallowedByAutoplay:
        return DeprecationInfo::Create(
            feature, "TextToSpeech_DisallowedByAutoplay", "`speechSynthesis.speak()` without user activation is deprecated and will be removed.");
    case WebFeature::kDocumentUnloadRegistered:
        return DeprecationInfo::Create(feature, "UnloadHandler", "Unload event listeners are deprecated and will be removed.");
    case WebFeature::kV8GPUAdapter_RequestAdapterInfo_Method:
        return DeprecationInfo::Create(feature, "V8GPUAdapter_RequestAdapterInfo_Method",
            "The GPUAdapter `requestAdapterInfo()` method is deprecated, instead use the GPUAdapter `info` attribute.");
    case WebFeature::kV8SharedArrayBufferConstructedInExtensionWithoutIsolation:
        return DeprecationInfo::Create(feature, "V8SharedArrayBufferConstructedInExtensionWithoutIsolation",
            "Extensions should opt into cross-origin isolation to continue using `SharedArrayBuffer`. See "
            "https://developer.chrome.com/docs/extensions/mv3/cross-origin-isolation/.");
    case WebFeature::kOpenWebDatabase:
        return DeprecationInfo::Create(feature, "WebSQL", "Web SQL is deprecated. Please use SQLite WebAssembly or Indexed Database");
    case WebFeature::kXHRJSONEncodingDetection:
        return DeprecationInfo::Create(feature, "XHRJSONEncodingDetection", "UTF-16 is not supported by response json in `XMLHttpRequest`");
    case WebFeature::kXMLHttpRequestSynchronousInNonWorkerOutsideBeforeUnload:
        return DeprecationInfo::Create(feature, "XMLHttpRequestSynchronousInNonWorkerOutsideBeforeUnload",
            "Synchronous `XMLHttpRequest` on the main thread is deprecated because of its detrimental effects to the end user's experience. For more help, "
            "check https://xhr.spec.whatwg.org/.");
    case WebFeature::kXRSupportsSession:
        return DeprecationInfo::Create(
            feature, "XRSupportsSession", "`supportsSession()` is deprecated. Please use `isSessionSupported()` and check the resolved boolean value instead.");
    default:
        return DeprecationInfo::Invalid(feature);
    }
}
} // namespace blink
