// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/policy_helper_public.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5

#include "third_party/blink/public/common/permissions_policy/policy_helper_public.h"

#include "base/no_destructor.h"
#include "third_party/blink/public/mojom/permissions_policy/permissions_policy_feature.mojom.h"
#include "third_party/blink/public/mojom/permissions_policy/permissions_policy.mojom.h"

namespace blink {

// Unlike the private version (which lives in
// blink/renderer/core/permissions_policy/), these maps will include all
// features, regardless of whether or not they depend on a blink runtime enabled
// feature that is enabled/disabled. Features which are shipping as part of an
// origin trial add their feature names to this map unconditionally, as the
// trial token could be added after the HTTP header needs to be parsed. This
// also means that top-level documents which simply want to embed another page
// which uses an origin trial feature, without using the feature themselves, can
// use permissions policy to allow use of the feature in subframes (The framed
// document will still require a valid origin trial token to use the feature in
// this scenario).

const PermissionsPolicyNameToFeatureMap& GetPermissionsPolicyNameToFeatureMap()
{
    static const PermissionsPolicyNameToFeatureMap default_feature_name_map = {
        { "accelerometer", mojom::PermissionsPolicyFeature::kAccelerometer },
        { "all-screens-capture", mojom::PermissionsPolicyFeature::kAllScreensCapture },
        { "ambient-light-sensor", mojom::PermissionsPolicyFeature::kAmbientLightSensor },
        { "attribution-reporting", mojom::PermissionsPolicyFeature::kAttributionReporting },
        { "autoplay", mojom::PermissionsPolicyFeature::kAutoplay },
        { "bluetooth", mojom::PermissionsPolicyFeature::kBluetooth },
        { "browsing-topics", mojom::PermissionsPolicyFeature::kBrowsingTopics },
        { "interest-cohort", mojom::PermissionsPolicyFeature::kBrowsingTopicsBackwardCompatible },
        { "camera", mojom::PermissionsPolicyFeature::kCamera },
        { "captured-surface-control", mojom::PermissionsPolicyFeature::kCapturedSurfaceControl },
        { "ch-dpr", mojom::PermissionsPolicyFeature::kClientHintDPR },
        { "ch-device-memory", mojom::PermissionsPolicyFeature::kClientHintDeviceMemory },
        { "ch-downlink", mojom::PermissionsPolicyFeature::kClientHintDownlink },
        { "ch-ect", mojom::PermissionsPolicyFeature::kClientHintECT },
        { "ch-prefers-color-scheme", mojom::PermissionsPolicyFeature::kClientHintPrefersColorScheme },
        { "ch-prefers-reduced-motion", mojom::PermissionsPolicyFeature::kClientHintPrefersReducedMotion },
        { "ch-prefers-reduced-transparency", mojom::PermissionsPolicyFeature::kClientHintPrefersReducedTransparency },
        { "ch-rtt", mojom::PermissionsPolicyFeature::kClientHintRTT },
        { "ch-save-data", mojom::PermissionsPolicyFeature::kClientHintSaveData },
        { "ch-ua", mojom::PermissionsPolicyFeature::kClientHintUA },
        { "ch-ua-arch", mojom::PermissionsPolicyFeature::kClientHintUAArch },
        { "ch-ua-bitness", mojom::PermissionsPolicyFeature::kClientHintUABitness },
        { "ch-ua-form-factors", mojom::PermissionsPolicyFeature::kClientHintUAFormFactors },
        { "ch-ua-platform", mojom::PermissionsPolicyFeature::kClientHintUAPlatform },
        { "ch-ua-model", mojom::PermissionsPolicyFeature::kClientHintUAModel },
        { "ch-ua-mobile", mojom::PermissionsPolicyFeature::kClientHintUAMobile },
        { "ch-ua-full-version", mojom::PermissionsPolicyFeature::kClientHintUAFullVersion },
        { "ch-ua-full-version-list", mojom::PermissionsPolicyFeature::kClientHintUAFullVersionList },
        { "ch-ua-platform-version", mojom::PermissionsPolicyFeature::kClientHintUAPlatformVersion },
        { "ch-ua-wow64", mojom::PermissionsPolicyFeature::kClientHintUAWoW64 },
        { "ch-viewport-height", mojom::PermissionsPolicyFeature::kClientHintViewportHeight },
        { "ch-viewport-width", mojom::PermissionsPolicyFeature::kClientHintViewportWidth },
        { "ch-width", mojom::PermissionsPolicyFeature::kClientHintWidth },
        { "clipboard-read", mojom::PermissionsPolicyFeature::kClipboardRead },
        { "clipboard-write", mojom::PermissionsPolicyFeature::kClipboardWrite },
        { "compute-pressure", mojom::PermissionsPolicyFeature::kComputePressure },
        { "controlled-frame", mojom::PermissionsPolicyFeature::kControlledFrame },
        { "cross-origin-isolated", mojom::PermissionsPolicyFeature::kCrossOriginIsolated },
        { "deferred-fetch", mojom::PermissionsPolicyFeature::kDeferredFetch },
        { "digital-credentials-get", mojom::PermissionsPolicyFeature::kDigitalCredentialsGet },
        { "direct-sockets", mojom::PermissionsPolicyFeature::kDirectSockets },
        { "direct-sockets-private", mojom::PermissionsPolicyFeature::kDirectSocketsPrivate },
        { "display-capture", mojom::PermissionsPolicyFeature::kDisplayCapture },
        { "encrypted-media", mojom::PermissionsPolicyFeature::kEncryptedMedia },
        { "execution-while-out-of-viewport", mojom::PermissionsPolicyFeature::kExecutionWhileOutOfViewport },
        { "execution-while-not-rendered", mojom::PermissionsPolicyFeature::kExecutionWhileNotRendered },
        { "fenced-unpartitioned-storage-read", mojom::PermissionsPolicyFeature::kFencedUnpartitionedStorageRead },
        { "focus-without-user-activation", mojom::PermissionsPolicyFeature::kFocusWithoutUserActivation },
        { "fullscreen", mojom::PermissionsPolicyFeature::kFullscreen },
        { "frobulate", mojom::PermissionsPolicyFeature::kFrobulate },
        { "gamepad", mojom::PermissionsPolicyFeature::kGamepad },
        { "geolocation", mojom::PermissionsPolicyFeature::kGeolocation },
        { "gyroscope", mojom::PermissionsPolicyFeature::kGyroscope },
        { "hid", mojom::PermissionsPolicyFeature::kHid },
        { "identity-credentials-get", mojom::PermissionsPolicyFeature::kIdentityCredentialsGet },
        { "idle-detection", mojom::PermissionsPolicyFeature::kIdleDetection },
        { "join-ad-interest-group", mojom::PermissionsPolicyFeature::kJoinAdInterestGroup },
        { "keyboard-map", mojom::PermissionsPolicyFeature::kKeyboardMap },
        { "local-fonts", mojom::PermissionsPolicyFeature::kLocalFonts },
        { "magnetometer", mojom::PermissionsPolicyFeature::kMagnetometer },
        { "media-playback-while-not-visible", mojom::PermissionsPolicyFeature::kMediaPlaybackWhileNotVisible },
        { "microphone", mojom::PermissionsPolicyFeature::kMicrophone },
        { "midi", mojom::PermissionsPolicyFeature::kMidiFeature },
        { "otp-credentials", mojom::PermissionsPolicyFeature::kOTPCredentials },
        { "popins", mojom::PermissionsPolicyFeature::kPartitionedPopins },
        { "payment", mojom::PermissionsPolicyFeature::kPayment },
        { "picture-in-picture", mojom::PermissionsPolicyFeature::kPictureInPicture },
        { "private-aggregation", mojom::PermissionsPolicyFeature::kPrivateAggregation },
        { "private-state-token-issuance", mojom::PermissionsPolicyFeature::kPrivateStateTokenIssuance },
        { "publickey-credentials-create", mojom::PermissionsPolicyFeature::kPublicKeyCredentialsCreate },
        { "publickey-credentials-get", mojom::PermissionsPolicyFeature::kPublicKeyCredentialsGet },
        { "run-ad-auction", mojom::PermissionsPolicyFeature::kRunAdAuction },
        { "screen-wake-lock", mojom::PermissionsPolicyFeature::kScreenWakeLock },
        { "serial", mojom::PermissionsPolicyFeature::kSerial },
        { "shared-autofill", mojom::PermissionsPolicyFeature::kSharedAutofill },
        { "shared-storage", mojom::PermissionsPolicyFeature::kSharedStorage },
        { "shared-storage-select-url", mojom::PermissionsPolicyFeature::kSharedStorageSelectUrl },
        { "smart-card", mojom::PermissionsPolicyFeature::kSmartCard },
        { "speaker-selection", mojom::PermissionsPolicyFeature::kSpeakerSelection },
        { "storage-access", mojom::PermissionsPolicyFeature::kStorageAccessAPI },
        { "sub-apps", mojom::PermissionsPolicyFeature::kSubApps },
        { "sync-xhr", mojom::PermissionsPolicyFeature::kSyncXHR },
        { "private-state-token-redemption", mojom::PermissionsPolicyFeature::kTrustTokenRedemption },
        { "usb", mojom::PermissionsPolicyFeature::kUsb },
        { "usb-unrestricted", mojom::PermissionsPolicyFeature::kUsbUnrestricted },
        { "unload", mojom::PermissionsPolicyFeature::kUnload },
        { "vertical-scroll", mojom::PermissionsPolicyFeature::kVerticalScroll },
        { "web-app-installation", mojom::PermissionsPolicyFeature::kWebAppInstallation },
        { "web-printing", mojom::PermissionsPolicyFeature::kWebPrinting },
        { "web-share", mojom::PermissionsPolicyFeature::kWebShare },
        { "xr-spatial-tracking", mojom::PermissionsPolicyFeature::kWebXr },
        { "window-management", mojom::PermissionsPolicyFeature::kWindowManagement },
    };

    return default_feature_name_map;
}

const PermissionsPolicyFeatureToNameMap& GetPermissionsPolicyFeatureToNameMap()
{
    static const PermissionsPolicyFeatureToNameMap default_feature_to_name_map = {
        { mojom::PermissionsPolicyFeature::kAccelerometer, "accelerometer" },
        { mojom::PermissionsPolicyFeature::kAllScreensCapture, "all-screens-capture" },
        { mojom::PermissionsPolicyFeature::kAmbientLightSensor, "ambient-light-sensor" },
        { mojom::PermissionsPolicyFeature::kAttributionReporting, "attribution-reporting" },
        { mojom::PermissionsPolicyFeature::kAutoplay, "autoplay" },
        { mojom::PermissionsPolicyFeature::kBluetooth, "bluetooth" },
        { mojom::PermissionsPolicyFeature::kBrowsingTopics, "browsing-topics" },
        { mojom::PermissionsPolicyFeature::kBrowsingTopicsBackwardCompatible, "interest-cohort" },
        { mojom::PermissionsPolicyFeature::kCamera, "camera" },
        { mojom::PermissionsPolicyFeature::kCapturedSurfaceControl, "captured-surface-control" },
        { mojom::PermissionsPolicyFeature::kClientHintDPR, "ch-dpr" },
        { mojom::PermissionsPolicyFeature::kClientHintDeviceMemory, "ch-device-memory" },
        { mojom::PermissionsPolicyFeature::kClientHintDownlink, "ch-downlink" },
        { mojom::PermissionsPolicyFeature::kClientHintECT, "ch-ect" },
        { mojom::PermissionsPolicyFeature::kClientHintPrefersColorScheme, "ch-prefers-color-scheme" },
        { mojom::PermissionsPolicyFeature::kClientHintPrefersReducedMotion, "ch-prefers-reduced-motion" },
        { mojom::PermissionsPolicyFeature::kClientHintPrefersReducedTransparency, "ch-prefers-reduced-transparency" },
        { mojom::PermissionsPolicyFeature::kClientHintRTT, "ch-rtt" },
        { mojom::PermissionsPolicyFeature::kClientHintSaveData, "ch-save-data" },
        { mojom::PermissionsPolicyFeature::kClientHintUA, "ch-ua" },
        { mojom::PermissionsPolicyFeature::kClientHintUAArch, "ch-ua-arch" },
        { mojom::PermissionsPolicyFeature::kClientHintUABitness, "ch-ua-bitness" },
        { mojom::PermissionsPolicyFeature::kClientHintUAFormFactors, "ch-ua-form-factors" },
        { mojom::PermissionsPolicyFeature::kClientHintUAPlatform, "ch-ua-platform" },
        { mojom::PermissionsPolicyFeature::kClientHintUAModel, "ch-ua-model" },
        { mojom::PermissionsPolicyFeature::kClientHintUAMobile, "ch-ua-mobile" },
        { mojom::PermissionsPolicyFeature::kClientHintUAFullVersion, "ch-ua-full-version" },
        { mojom::PermissionsPolicyFeature::kClientHintUAFullVersionList, "ch-ua-full-version-list" },
        { mojom::PermissionsPolicyFeature::kClientHintUAPlatformVersion, "ch-ua-platform-version" },
        { mojom::PermissionsPolicyFeature::kClientHintUAWoW64, "ch-ua-wow64" },
        { mojom::PermissionsPolicyFeature::kClientHintViewportHeight, "ch-viewport-height" },
        { mojom::PermissionsPolicyFeature::kClientHintViewportWidth, "ch-viewport-width" },
        { mojom::PermissionsPolicyFeature::kClientHintWidth, "ch-width" },
        { mojom::PermissionsPolicyFeature::kClipboardRead, "clipboard-read" },
        { mojom::PermissionsPolicyFeature::kClipboardWrite, "clipboard-write" },
        { mojom::PermissionsPolicyFeature::kComputePressure, "compute-pressure" },
        { mojom::PermissionsPolicyFeature::kControlledFrame, "controlled-frame" },
        { mojom::PermissionsPolicyFeature::kCrossOriginIsolated, "cross-origin-isolated" },
        { mojom::PermissionsPolicyFeature::kDeferredFetch, "deferred-fetch" },
        { mojom::PermissionsPolicyFeature::kDigitalCredentialsGet, "digital-credentials-get" },
        { mojom::PermissionsPolicyFeature::kDirectSockets, "direct-sockets" },
        { mojom::PermissionsPolicyFeature::kDirectSocketsPrivate, "direct-sockets-private" },
        { mojom::PermissionsPolicyFeature::kDisplayCapture, "display-capture" },
        { mojom::PermissionsPolicyFeature::kEncryptedMedia, "encrypted-media" },
        { mojom::PermissionsPolicyFeature::kExecutionWhileOutOfViewport, "execution-while-out-of-viewport" },
        { mojom::PermissionsPolicyFeature::kExecutionWhileNotRendered, "execution-while-not-rendered" },
        { mojom::PermissionsPolicyFeature::kFencedUnpartitionedStorageRead, "fenced-unpartitioned-storage-read" },
        { mojom::PermissionsPolicyFeature::kFocusWithoutUserActivation, "focus-without-user-activation" },
        { mojom::PermissionsPolicyFeature::kFullscreen, "fullscreen" },
        { mojom::PermissionsPolicyFeature::kFrobulate, "frobulate" },
        { mojom::PermissionsPolicyFeature::kGamepad, "gamepad" },
        { mojom::PermissionsPolicyFeature::kGeolocation, "geolocation" },
        { mojom::PermissionsPolicyFeature::kGyroscope, "gyroscope" },
        { mojom::PermissionsPolicyFeature::kHid, "hid" },
        { mojom::PermissionsPolicyFeature::kIdentityCredentialsGet, "identity-credentials-get" },
        { mojom::PermissionsPolicyFeature::kIdleDetection, "idle-detection" },
        { mojom::PermissionsPolicyFeature::kJoinAdInterestGroup, "join-ad-interest-group" },
        { mojom::PermissionsPolicyFeature::kKeyboardMap, "keyboard-map" },
        { mojom::PermissionsPolicyFeature::kLocalFonts, "local-fonts" },
        { mojom::PermissionsPolicyFeature::kMagnetometer, "magnetometer" },
        { mojom::PermissionsPolicyFeature::kMediaPlaybackWhileNotVisible, "media-playback-while-not-visible" },
        { mojom::PermissionsPolicyFeature::kMicrophone, "microphone" },
        { mojom::PermissionsPolicyFeature::kMidiFeature, "midi" },
        { mojom::PermissionsPolicyFeature::kOTPCredentials, "otp-credentials" },
        { mojom::PermissionsPolicyFeature::kPartitionedPopins, "popins" },
        { mojom::PermissionsPolicyFeature::kPayment, "payment" },
        { mojom::PermissionsPolicyFeature::kPictureInPicture, "picture-in-picture" },
        { mojom::PermissionsPolicyFeature::kPrivateAggregation, "private-aggregation" },
        { mojom::PermissionsPolicyFeature::kPrivateStateTokenIssuance, "private-state-token-issuance" },
        { mojom::PermissionsPolicyFeature::kPublicKeyCredentialsCreate, "publickey-credentials-create" },
        { mojom::PermissionsPolicyFeature::kPublicKeyCredentialsGet, "publickey-credentials-get" },
        { mojom::PermissionsPolicyFeature::kRunAdAuction, "run-ad-auction" },
        { mojom::PermissionsPolicyFeature::kScreenWakeLock, "screen-wake-lock" },
        { mojom::PermissionsPolicyFeature::kSerial, "serial" },
        { mojom::PermissionsPolicyFeature::kSharedAutofill, "shared-autofill" },
        { mojom::PermissionsPolicyFeature::kSharedStorage, "shared-storage" },
        { mojom::PermissionsPolicyFeature::kSharedStorageSelectUrl, "shared-storage-select-url" },
        { mojom::PermissionsPolicyFeature::kSmartCard, "smart-card" },
        { mojom::PermissionsPolicyFeature::kSpeakerSelection, "speaker-selection" },
        { mojom::PermissionsPolicyFeature::kStorageAccessAPI, "storage-access" },
        { mojom::PermissionsPolicyFeature::kSubApps, "sub-apps" },
        { mojom::PermissionsPolicyFeature::kSyncXHR, "sync-xhr" },
        { mojom::PermissionsPolicyFeature::kTrustTokenRedemption, "private-state-token-redemption" },
        { mojom::PermissionsPolicyFeature::kUsb, "usb" },
        { mojom::PermissionsPolicyFeature::kUsbUnrestricted, "usb-unrestricted" },
        { mojom::PermissionsPolicyFeature::kUnload, "unload" },
        { mojom::PermissionsPolicyFeature::kVerticalScroll, "vertical-scroll" },
        { mojom::PermissionsPolicyFeature::kWebAppInstallation, "web-app-installation" },
        { mojom::PermissionsPolicyFeature::kWebPrinting, "web-printing" },
        { mojom::PermissionsPolicyFeature::kWebShare, "web-share" },
        { mojom::PermissionsPolicyFeature::kWebXr, "xr-spatial-tracking" },
        { mojom::PermissionsPolicyFeature::kWindowManagement, "window-management" },
    };
    return default_feature_to_name_map;
}

} // namespace blink
