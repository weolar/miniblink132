// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/policy_helper.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/permissions_policy/document_policy_features.json5
//   ../../third_party/blink/renderer/core/permissions_policy/permissions_policy_features.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/permissions_policy/policy_helper.h"

#include "third_party/blink/public/mojom/permissions_policy/document_policy_feature.mojom-blink.h"
#include "third_party/blink/public/mojom/permissions_policy/permissions_policy_feature.mojom-blink.h"
#include "third_party/blink/public/mojom/permissions_policy/permissions_policy.mojom-blink.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/inspector/protocol/page.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {
namespace {

const char kAccelerometerPolicyName[] = "accelerometer";
const char kAllScreensCapturePolicyName[] = "all-screens-capture";
const char kAmbientLightSensorPolicyName[] = "ambient-light-sensor";
const char kAttributionReportingPolicyName[] = "attribution-reporting";
const char kAutoplayPolicyName[] = "autoplay";
const char kBluetoothPolicyName[] = "bluetooth";
const char kBrowsingTopicsPolicyName[] = "browsing-topics";
const char kBrowsingTopicsBackwardCompatiblePolicyName[] = "interest-cohort";
const char kCameraPolicyName[] = "camera";
const char kCapturedSurfaceControlPolicyName[] = "captured-surface-control";
const char kClientHintDPRPolicyName[] = "ch-dpr";
const char kClientHintDeviceMemoryPolicyName[] = "ch-device-memory";
const char kClientHintDownlinkPolicyName[] = "ch-downlink";
const char kClientHintECTPolicyName[] = "ch-ect";
const char kClientHintPrefersColorSchemePolicyName[] = "ch-prefers-color-scheme";
const char kClientHintPrefersReducedMotionPolicyName[] = "ch-prefers-reduced-motion";
const char kClientHintPrefersReducedTransparencyPolicyName[] = "ch-prefers-reduced-transparency";
const char kClientHintRTTPolicyName[] = "ch-rtt";
const char kClientHintSaveDataPolicyName[] = "ch-save-data";
const char kClientHintUAPolicyName[] = "ch-ua";
const char kClientHintUAArchPolicyName[] = "ch-ua-arch";
const char kClientHintUABitnessPolicyName[] = "ch-ua-bitness";
const char kClientHintUAFormFactorsPolicyName[] = "ch-ua-form-factors";
const char kClientHintUAPlatformPolicyName[] = "ch-ua-platform";
const char kClientHintUAModelPolicyName[] = "ch-ua-model";
const char kClientHintUAMobilePolicyName[] = "ch-ua-mobile";
const char kClientHintUAFullVersionPolicyName[] = "ch-ua-full-version";
const char kClientHintUAFullVersionListPolicyName[] = "ch-ua-full-version-list";
const char kClientHintUAPlatformVersionPolicyName[] = "ch-ua-platform-version";
const char kClientHintUAWoW64PolicyName[] = "ch-ua-wow64";
const char kClientHintViewportHeightPolicyName[] = "ch-viewport-height";
const char kClientHintViewportWidthPolicyName[] = "ch-viewport-width";
const char kClientHintWidthPolicyName[] = "ch-width";
const char kClipboardReadPolicyName[] = "clipboard-read";
const char kClipboardWritePolicyName[] = "clipboard-write";
const char kComputePressurePolicyName[] = "compute-pressure";
const char kControlledFramePolicyName[] = "controlled-frame";
const char kCrossOriginIsolatedPolicyName[] = "cross-origin-isolated";
const char kDeferredFetchPolicyName[] = "deferred-fetch";
const char kDigitalCredentialsGetPolicyName[] = "digital-credentials-get";
const char kDirectSocketsPolicyName[] = "direct-sockets";
const char kDirectSocketsPrivatePolicyName[] = "direct-sockets-private";
const char kDisplayCapturePolicyName[] = "display-capture";
const char kEncryptedMediaPolicyName[] = "encrypted-media";
const char kExecutionWhileOutOfViewportPolicyName[] = "execution-while-out-of-viewport";
const char kExecutionWhileNotRenderedPolicyName[] = "execution-while-not-rendered";
const char kFencedUnpartitionedStorageReadPolicyName[] = "fenced-unpartitioned-storage-read";
const char kFocusWithoutUserActivationPolicyName[] = "focus-without-user-activation";
const char kFullscreenPolicyName[] = "fullscreen";
const char kFrobulatePolicyName[] = "frobulate";
const char kGamepadPolicyName[] = "gamepad";
const char kGeolocationPolicyName[] = "geolocation";
const char kGyroscopePolicyName[] = "gyroscope";
const char kHidPolicyName[] = "hid";
const char kIdentityCredentialsGetPolicyName[] = "identity-credentials-get";
const char kIdleDetectionPolicyName[] = "idle-detection";
const char kJoinAdInterestGroupPolicyName[] = "join-ad-interest-group";
const char kKeyboardMapPolicyName[] = "keyboard-map";
const char kLocalFontsPolicyName[] = "local-fonts";
const char kMagnetometerPolicyName[] = "magnetometer";
const char kMediaPlaybackWhileNotVisiblePolicyName[] = "media-playback-while-not-visible";
const char kMicrophonePolicyName[] = "microphone";
const char kMidiFeaturePolicyName[] = "midi";
const char kOTPCredentialsPolicyName[] = "otp-credentials";
const char kPartitionedPopinsPolicyName[] = "popins";
const char kPaymentPolicyName[] = "payment";
const char kPictureInPicturePolicyName[] = "picture-in-picture";
const char kPrivateAggregationPolicyName[] = "private-aggregation";
const char kPrivateStateTokenIssuancePolicyName[] = "private-state-token-issuance";
const char kPublicKeyCredentialsCreatePolicyName[] = "publickey-credentials-create";
const char kPublicKeyCredentialsGetPolicyName[] = "publickey-credentials-get";
const char kRunAdAuctionPolicyName[] = "run-ad-auction";
const char kScreenWakeLockPolicyName[] = "screen-wake-lock";
const char kSerialPolicyName[] = "serial";
const char kSharedAutofillPolicyName[] = "shared-autofill";
const char kSharedStoragePolicyName[] = "shared-storage";
const char kSharedStorageSelectUrlPolicyName[] = "shared-storage-select-url";
const char kSmartCardPolicyName[] = "smart-card";
const char kSpeakerSelectionPolicyName[] = "speaker-selection";
const char kStorageAccessAPIPolicyName[] = "storage-access";
const char kSubAppsPolicyName[] = "sub-apps";
const char kSyncXHRPolicyName[] = "sync-xhr";
const char kTrustTokenRedemptionPolicyName[] = "private-state-token-redemption";
const char kUsbPolicyName[] = "usb";
const char kUsbUnrestrictedPolicyName[] = "usb-unrestricted";
const char kUnloadPolicyName[] = "unload";
const char kVerticalScrollPolicyName[] = "vertical-scroll";
const char kWebAppInstallationPolicyName[] = "web-app-installation";
const char kWebPrintingPolicyName[] = "web-printing";
const char kWebSharePolicyName[] = "web-share";
const char kWebXrPolicyName[] = "xr-spatial-tracking";
const char kWindowManagementPolicyName[] = "window-management";

} // namespace

// Features which depend on a flag also have the same flag controlling whether
// they are in this map. Features which are shipping as part of an origin trial
// add their feature names to this map unconditionally, as the trial token could
// be added after the HTTP header needs to be parsed. This also means that
// top-level documents which simply want to embed another page which uses an
// origin trial feature, without using the feature themselves, can use
// permissions policy to allow use of the feature in subframes (The framed
// document will still require a valid origin trial token to use the feature in
// this scenario).
const FeatureNameMap GetDefaultFeatureNameMap(bool is_isolated_context)
{
    DEFINE_STATIC_LOCAL(FeatureNameMapCache, default_feature_name_map_cache, ());
    FeatureNameMapCacheKey key(is_isolated_context);
    if (default_feature_name_map_cache.Contains(key) && !default_feature_name_map_cache.at(key).empty()) {
        return default_feature_name_map_cache.at(key);
    }

    FeatureNameMap default_feature_name_map;
    default_feature_name_map.Set(kAccelerometerPolicyName, mojom::PermissionsPolicyFeature::kAccelerometer);
    if (is_isolated_context) {
        default_feature_name_map.Set(kAllScreensCapturePolicyName, mojom::PermissionsPolicyFeature::kAllScreensCapture);
    }
    default_feature_name_map.Set(kAutoplayPolicyName, mojom::PermissionsPolicyFeature::kAutoplay);
    default_feature_name_map.Set(kCameraPolicyName, mojom::PermissionsPolicyFeature::kCamera);
    default_feature_name_map.Set(kCapturedSurfaceControlPolicyName, mojom::PermissionsPolicyFeature::kCapturedSurfaceControl);
    default_feature_name_map.Set(kClientHintDPRPolicyName, mojom::PermissionsPolicyFeature::kClientHintDPR);
    default_feature_name_map.Set(kClientHintDeviceMemoryPolicyName, mojom::PermissionsPolicyFeature::kClientHintDeviceMemory);
    default_feature_name_map.Set(kClientHintDownlinkPolicyName, mojom::PermissionsPolicyFeature::kClientHintDownlink);
    default_feature_name_map.Set(kClientHintECTPolicyName, mojom::PermissionsPolicyFeature::kClientHintECT);
    default_feature_name_map.Set(kClientHintPrefersColorSchemePolicyName, mojom::PermissionsPolicyFeature::kClientHintPrefersColorScheme);
    default_feature_name_map.Set(kClientHintPrefersReducedMotionPolicyName, mojom::PermissionsPolicyFeature::kClientHintPrefersReducedMotion);
    default_feature_name_map.Set(kClientHintPrefersReducedTransparencyPolicyName, mojom::PermissionsPolicyFeature::kClientHintPrefersReducedTransparency);
    default_feature_name_map.Set(kClientHintRTTPolicyName, mojom::PermissionsPolicyFeature::kClientHintRTT);
    default_feature_name_map.Set(kClientHintSaveDataPolicyName, mojom::PermissionsPolicyFeature::kClientHintSaveData);
    default_feature_name_map.Set(kClientHintUAPolicyName, mojom::PermissionsPolicyFeature::kClientHintUA);
    default_feature_name_map.Set(kClientHintUAArchPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAArch);
    default_feature_name_map.Set(kClientHintUABitnessPolicyName, mojom::PermissionsPolicyFeature::kClientHintUABitness);
    default_feature_name_map.Set(kClientHintUAFormFactorsPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAFormFactors);
    default_feature_name_map.Set(kClientHintUAPlatformPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAPlatform);
    default_feature_name_map.Set(kClientHintUAModelPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAModel);
    default_feature_name_map.Set(kClientHintUAMobilePolicyName, mojom::PermissionsPolicyFeature::kClientHintUAMobile);
    default_feature_name_map.Set(kClientHintUAFullVersionPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAFullVersion);
    default_feature_name_map.Set(kClientHintUAFullVersionListPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAFullVersionList);
    default_feature_name_map.Set(kClientHintUAPlatformVersionPolicyName, mojom::PermissionsPolicyFeature::kClientHintUAPlatformVersion);
    default_feature_name_map.Set(kClientHintUAWoW64PolicyName, mojom::PermissionsPolicyFeature::kClientHintUAWoW64);
    default_feature_name_map.Set(kClientHintViewportWidthPolicyName, mojom::PermissionsPolicyFeature::kClientHintViewportWidth);
    default_feature_name_map.Set(kClientHintWidthPolicyName, mojom::PermissionsPolicyFeature::kClientHintWidth);
    default_feature_name_map.Set(kClipboardReadPolicyName, mojom::PermissionsPolicyFeature::kClipboardRead);
    default_feature_name_map.Set(kClipboardWritePolicyName, mojom::PermissionsPolicyFeature::kClipboardWrite);
    default_feature_name_map.Set(kCrossOriginIsolatedPolicyName, mojom::PermissionsPolicyFeature::kCrossOriginIsolated);
    default_feature_name_map.Set(kDeferredFetchPolicyName, mojom::PermissionsPolicyFeature::kDeferredFetch);
    default_feature_name_map.Set(kDigitalCredentialsGetPolicyName, mojom::PermissionsPolicyFeature::kDigitalCredentialsGet);
    default_feature_name_map.Set(kDisplayCapturePolicyName, mojom::PermissionsPolicyFeature::kDisplayCapture);
    default_feature_name_map.Set(kEncryptedMediaPolicyName, mojom::PermissionsPolicyFeature::kEncryptedMedia);
    default_feature_name_map.Set(kFullscreenPolicyName, mojom::PermissionsPolicyFeature::kFullscreen);
    default_feature_name_map.Set(kFrobulatePolicyName, mojom::PermissionsPolicyFeature::kFrobulate);
    default_feature_name_map.Set(kGamepadPolicyName, mojom::PermissionsPolicyFeature::kGamepad);
    default_feature_name_map.Set(kGeolocationPolicyName, mojom::PermissionsPolicyFeature::kGeolocation);
    default_feature_name_map.Set(kGyroscopePolicyName, mojom::PermissionsPolicyFeature::kGyroscope);
    default_feature_name_map.Set(kIdentityCredentialsGetPolicyName, mojom::PermissionsPolicyFeature::kIdentityCredentialsGet);
    default_feature_name_map.Set(kIdleDetectionPolicyName, mojom::PermissionsPolicyFeature::kIdleDetection);
    default_feature_name_map.Set(kJoinAdInterestGroupPolicyName, mojom::PermissionsPolicyFeature::kJoinAdInterestGroup);
    default_feature_name_map.Set(kKeyboardMapPolicyName, mojom::PermissionsPolicyFeature::kKeyboardMap);
    default_feature_name_map.Set(kMagnetometerPolicyName, mojom::PermissionsPolicyFeature::kMagnetometer);
    default_feature_name_map.Set(kMicrophonePolicyName, mojom::PermissionsPolicyFeature::kMicrophone);
    default_feature_name_map.Set(kMidiFeaturePolicyName, mojom::PermissionsPolicyFeature::kMidiFeature);
    default_feature_name_map.Set(kPictureInPicturePolicyName, mojom::PermissionsPolicyFeature::kPictureInPicture);
    default_feature_name_map.Set(kPrivateStateTokenIssuancePolicyName, mojom::PermissionsPolicyFeature::kPrivateStateTokenIssuance);
    default_feature_name_map.Set(kPublicKeyCredentialsCreatePolicyName, mojom::PermissionsPolicyFeature::kPublicKeyCredentialsCreate);
    default_feature_name_map.Set(kPublicKeyCredentialsGetPolicyName, mojom::PermissionsPolicyFeature::kPublicKeyCredentialsGet);
    default_feature_name_map.Set(kStorageAccessAPIPolicyName, mojom::PermissionsPolicyFeature::kStorageAccessAPI);
    default_feature_name_map.Set(kSyncXHRPolicyName, mojom::PermissionsPolicyFeature::kSyncXHR);
    default_feature_name_map.Set(kTrustTokenRedemptionPolicyName, mojom::PermissionsPolicyFeature::kTrustTokenRedemption);
    default_feature_name_map.Set(kUnloadPolicyName, mojom::PermissionsPolicyFeature::kUnload);
    default_feature_name_map.Set(kWindowManagementPolicyName, mojom::PermissionsPolicyFeature::kWindowManagement);
    if (RuntimeEnabledFeatures::AttributionReportingEnabled()) {
        default_feature_name_map.Set(kAttributionReportingPolicyName, mojom::PermissionsPolicyFeature::kAttributionReporting);
    }
    if (RuntimeEnabledFeatures::AttributionReportingCrossAppWebEnabled()) {
        default_feature_name_map.Set(kAttributionReportingPolicyName, mojom::PermissionsPolicyFeature::kAttributionReporting);
    }
    if (RuntimeEnabledFeatures::BlockingFocusWithoutUserActivationEnabled()) {
        default_feature_name_map.Set(kFocusWithoutUserActivationPolicyName, mojom::PermissionsPolicyFeature::kFocusWithoutUserActivation);
    }
    if (RuntimeEnabledFeatures::ComputePressureEnabled()) {
        default_feature_name_map.Set(kComputePressurePolicyName, mojom::PermissionsPolicyFeature::kComputePressure);
    }
    if (RuntimeEnabledFeatures::ControlledFrameEnabled()) {
        if (is_isolated_context) {
            default_feature_name_map.Set(kControlledFramePolicyName, mojom::PermissionsPolicyFeature::kControlledFrame);
        }
    }
    if (RuntimeEnabledFeatures::DesktopPWAsSubAppsEnabled()) {
        if (is_isolated_context) {
            default_feature_name_map.Set(kSubAppsPolicyName, mojom::PermissionsPolicyFeature::kSubApps);
        }
    }
    if (RuntimeEnabledFeatures::DirectSocketsEnabled()) {
        if (is_isolated_context) {
            default_feature_name_map.Set(kDirectSocketsPolicyName, mojom::PermissionsPolicyFeature::kDirectSockets);
        }
        if (is_isolated_context) {
            default_feature_name_map.Set(kDirectSocketsPrivatePolicyName, mojom::PermissionsPolicyFeature::kDirectSocketsPrivate);
        }
    }
    if (RuntimeEnabledFeatures::ExperimentalPoliciesEnabled()) {
        default_feature_name_map.Set(kVerticalScrollPolicyName, mojom::PermissionsPolicyFeature::kVerticalScroll);
    }
    if (RuntimeEnabledFeatures::FencedFramesLocalUnpartitionedDataAccessEnabled()) {
        default_feature_name_map.Set(kFencedUnpartitionedStorageReadPolicyName, mojom::PermissionsPolicyFeature::kFencedUnpartitionedStorageRead);
    }
    if (RuntimeEnabledFeatures::FledgeEnabled()) {
        default_feature_name_map.Set(kPrivateAggregationPolicyName, mojom::PermissionsPolicyFeature::kPrivateAggregation);
        default_feature_name_map.Set(kRunAdAuctionPolicyName, mojom::PermissionsPolicyFeature::kRunAdAuction);
    }
    if (RuntimeEnabledFeatures::FontAccessEnabled()) {
        default_feature_name_map.Set(kLocalFontsPolicyName, mojom::PermissionsPolicyFeature::kLocalFonts);
    }
    if (RuntimeEnabledFeatures::FreezeFramesOnVisibilityEnabled()) {
        default_feature_name_map.Set(kExecutionWhileOutOfViewportPolicyName, mojom::PermissionsPolicyFeature::kExecutionWhileOutOfViewport);
        default_feature_name_map.Set(kExecutionWhileNotRenderedPolicyName, mojom::PermissionsPolicyFeature::kExecutionWhileNotRendered);
    }
    if (RuntimeEnabledFeatures::MediaPlaybackWhileNotVisiblePermissionPolicyEnabled()) {
        default_feature_name_map.Set(kMediaPlaybackWhileNotVisiblePolicyName, mojom::PermissionsPolicyFeature::kMediaPlaybackWhileNotVisible);
    }
    if (RuntimeEnabledFeatures::PartitionedPopinsEnabled()) {
        default_feature_name_map.Set(kPartitionedPopinsPolicyName, mojom::PermissionsPolicyFeature::kPartitionedPopins);
    }
    if (RuntimeEnabledFeatures::PaymentRequestEnabled()) {
        default_feature_name_map.Set(kPaymentPolicyName, mojom::PermissionsPolicyFeature::kPayment);
    }
    if (RuntimeEnabledFeatures::SensorExtraClassesEnabled()) {
        default_feature_name_map.Set(kAmbientLightSensorPolicyName, mojom::PermissionsPolicyFeature::kAmbientLightSensor);
    }
    if (RuntimeEnabledFeatures::SerialEnabled()) {
        default_feature_name_map.Set(kSerialPolicyName, mojom::PermissionsPolicyFeature::kSerial);
    }
    if (RuntimeEnabledFeatures::SharedAutofillEnabled()) {
        default_feature_name_map.Set(kSharedAutofillPolicyName, mojom::PermissionsPolicyFeature::kSharedAutofill);
    }
    if (RuntimeEnabledFeatures::SharedStorageAPIEnabled()) {
        default_feature_name_map.Set(kPrivateAggregationPolicyName, mojom::PermissionsPolicyFeature::kPrivateAggregation);
        default_feature_name_map.Set(kSharedStoragePolicyName, mojom::PermissionsPolicyFeature::kSharedStorage);
        default_feature_name_map.Set(kSharedStorageSelectUrlPolicyName, mojom::PermissionsPolicyFeature::kSharedStorageSelectUrl);
    }
    if (RuntimeEnabledFeatures::SmartCardEnabled()) {
        if (is_isolated_context) {
            default_feature_name_map.Set(kSmartCardPolicyName, mojom::PermissionsPolicyFeature::kSmartCard);
        }
    }
    if (RuntimeEnabledFeatures::SpeakerSelectionEnabled()) {
        default_feature_name_map.Set(kSpeakerSelectionPolicyName, mojom::PermissionsPolicyFeature::kSpeakerSelection);
    }
    if (RuntimeEnabledFeatures::TopicsAPIEnabled()) {
        default_feature_name_map.Set(kBrowsingTopicsPolicyName, mojom::PermissionsPolicyFeature::kBrowsingTopics);
        default_feature_name_map.Set(kBrowsingTopicsBackwardCompatiblePolicyName, mojom::PermissionsPolicyFeature::kBrowsingTopicsBackwardCompatible);
    }
    if (RuntimeEnabledFeatures::UnrestrictedUsbEnabled()) {
        if (is_isolated_context) {
            default_feature_name_map.Set(kUsbUnrestrictedPolicyName, mojom::PermissionsPolicyFeature::kUsbUnrestricted);
        }
    }
    if (RuntimeEnabledFeatures::ViewportHeightClientHintHeaderEnabled()) {
        default_feature_name_map.Set(kClientHintViewportHeightPolicyName, mojom::PermissionsPolicyFeature::kClientHintViewportHeight);
    }
    if (RuntimeEnabledFeatures::WakeLockEnabled()) {
        default_feature_name_map.Set(kScreenWakeLockPolicyName, mojom::PermissionsPolicyFeature::kScreenWakeLock);
    }
    if (RuntimeEnabledFeatures::WebAppInstallationEnabled()) {
        default_feature_name_map.Set(kWebAppInstallationPolicyName, mojom::PermissionsPolicyFeature::kWebAppInstallation);
    }
    if (RuntimeEnabledFeatures::WebBluetoothEnabled()) {
        default_feature_name_map.Set(kBluetoothPolicyName, mojom::PermissionsPolicyFeature::kBluetooth);
    }
    if (RuntimeEnabledFeatures::WebHIDEnabled()) {
        default_feature_name_map.Set(kHidPolicyName, mojom::PermissionsPolicyFeature::kHid);
    }
    if (RuntimeEnabledFeatures::WebOTPAssertionFeaturePolicyEnabled()) {
        default_feature_name_map.Set(kOTPCredentialsPolicyName, mojom::PermissionsPolicyFeature::kOTPCredentials);
    }
    if (RuntimeEnabledFeatures::WebPrintingEnabled()) {
        if (is_isolated_context) {
            default_feature_name_map.Set(kWebPrintingPolicyName, mojom::PermissionsPolicyFeature::kWebPrinting);
        }
    }
    if (RuntimeEnabledFeatures::WebShareEnabled()) {
        default_feature_name_map.Set(kWebSharePolicyName, mojom::PermissionsPolicyFeature::kWebShare);
    }
    if (RuntimeEnabledFeatures::WebUSBEnabled()) {
        default_feature_name_map.Set(kUsbPolicyName, mojom::PermissionsPolicyFeature::kUsb);
    }
    if (RuntimeEnabledFeatures::WebXREnabled()) {
        default_feature_name_map.Set(kWebXrPolicyName, mojom::PermissionsPolicyFeature::kWebXr);
    }

    // Before we set |key| in the hash to be the map, check that it's empty.
    if (default_feature_name_map_cache.Contains(key)) {
        CHECK(default_feature_name_map_cache.at(key).empty());
    }

    // The contents of |default_feature_name_map| are copied into
    // |default_feature_name_map_cache| here, which is declared static
    // local above.
    default_feature_name_map_cache.Set(key, default_feature_name_map);

    return default_feature_name_map;
}

DocumentPolicyFeatureSet& GetAvailableDocumentPolicyFeaturesInternal()
{
    DEFINE_STATIC_LOCAL(DocumentPolicyFeatureSet, features, ());
    return features;
}

void ResetAvailableDocumentPolicyFeaturesForTest()
{
    GetAvailableDocumentPolicyFeaturesInternal().clear();
}

const DocumentPolicyFeatureSet& GetAvailableDocumentPolicyFeatures()
{
    DocumentPolicyFeatureSet& features = GetAvailableDocumentPolicyFeaturesInternal();
    if (features.empty()) {
        features.insert(mojom::DocumentPolicyFeature::kDefault);
        features.insert(mojom::DocumentPolicyFeature::kForceLoadAtTop);
        features.insert(mojom::DocumentPolicyFeature::kJSProfiling);
        features.insert(mojom::DocumentPolicyFeature::kIncludeJSCallStacksInCrashReports);
        if (RuntimeEnabledFeatures::DocumentPolicyExpectNoLinkedResourcesEnabled()) {
            features.insert(mojom::DocumentPolicyFeature::kExpectNoLinkedResources);
        }
        if (RuntimeEnabledFeatures::DocumentPolicySyncXHREnabled()) {
            features.insert(mojom::DocumentPolicyFeature::kSyncXHR);
        }
    }
    return features;
}

// If any of the origin trial runtime feature is enabled, returns false,
// i.e. the feature is considered enabled by origin trial.
bool DisabledByOriginTrial(const String& feature_name, FeatureContext* feature_context)
{
    if (feature_name == kAllScreensCapturePolicyName) {
        return !RuntimeEnabledFeatures::GetAllScreensMediaEnabled(feature_context);
    }
    if (feature_name == kCapturedSurfaceControlPolicyName) {
        return !RuntimeEnabledFeatures::CapturedSurfaceControlEnabled(feature_context);
    }
    if (feature_name == kDeferredFetchPolicyName) {
        return !RuntimeEnabledFeatures::FetchLaterAPIEnabled(feature_context);
    }
    if (feature_name == kDigitalCredentialsGetPolicyName) {
        return !RuntimeEnabledFeatures::WebIdentityDigitalCredentialsEnabled(feature_context);
    }
    if (feature_name == kFrobulatePolicyName) {
        return !RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(feature_context);
    }
    if (feature_name == kJoinAdInterestGroupPolicyName) {
        return !RuntimeEnabledFeatures::AdInterestGroupAPIEnabled(feature_context);
    }
    if (feature_name == kPrivateStateTokenIssuancePolicyName) {
        return !RuntimeEnabledFeatures::PrivateStateTokensEnabled(feature_context);
    }
    if (feature_name == kTrustTokenRedemptionPolicyName) {
        return !RuntimeEnabledFeatures::PrivateStateTokensEnabled(feature_context);
    }
    return false;
}

bool DisabledByOriginTrial(mojom::blink::DocumentPolicyFeature feature, FeatureContext* feature_context)
{
    return false;
}

String PermissionsPolicyFeatureToProtocol(mojom::blink::PermissionsPolicyFeature feature, ExecutionContext* execution_context)
{
    if (execution_context && execution_context->IsIsolatedContext()) {
        switch (feature) {
        case mojom::blink::PermissionsPolicyFeature::kAllScreensCapture:
            return protocol::Page::PermissionsPolicyFeatureEnum::AllScreensCapture;
        case mojom::blink::PermissionsPolicyFeature::kControlledFrame:
            return protocol::Page::PermissionsPolicyFeatureEnum::ControlledFrame;
        case mojom::blink::PermissionsPolicyFeature::kDirectSockets:
            return protocol::Page::PermissionsPolicyFeatureEnum::DirectSockets;
        case mojom::blink::PermissionsPolicyFeature::kDirectSocketsPrivate:
            return protocol::Page::PermissionsPolicyFeatureEnum::DirectSocketsPrivate;
        case mojom::blink::PermissionsPolicyFeature::kSmartCard:
            return protocol::Page::PermissionsPolicyFeatureEnum::SmartCard;
        case mojom::blink::PermissionsPolicyFeature::kSubApps:
            return protocol::Page::PermissionsPolicyFeatureEnum::SubApps;
        case mojom::blink::PermissionsPolicyFeature::kUsbUnrestricted:
            return protocol::Page::PermissionsPolicyFeatureEnum::UsbUnrestricted;
        case mojom::blink::PermissionsPolicyFeature::kWebPrinting:
            return protocol::Page::PermissionsPolicyFeatureEnum::WebPrinting;
        default:
            break;
        }
    }
    switch (feature) {
    case mojom::blink::PermissionsPolicyFeature::kAccelerometer:
        return protocol::Page::PermissionsPolicyFeatureEnum::Accelerometer;
    case mojom::blink::PermissionsPolicyFeature::kAmbientLightSensor:
        return protocol::Page::PermissionsPolicyFeatureEnum::AmbientLightSensor;
    case mojom::blink::PermissionsPolicyFeature::kAttributionReporting:
        return protocol::Page::PermissionsPolicyFeatureEnum::AttributionReporting;
    case mojom::blink::PermissionsPolicyFeature::kAutoplay:
        return protocol::Page::PermissionsPolicyFeatureEnum::Autoplay;
    case mojom::blink::PermissionsPolicyFeature::kBluetooth:
        return protocol::Page::PermissionsPolicyFeatureEnum::Bluetooth;
    case mojom::blink::PermissionsPolicyFeature::kBrowsingTopics:
        return protocol::Page::PermissionsPolicyFeatureEnum::BrowsingTopics;
    case mojom::blink::PermissionsPolicyFeature::kBrowsingTopicsBackwardCompatible:
        return protocol::Page::PermissionsPolicyFeatureEnum::InterestCohort;
    case mojom::blink::PermissionsPolicyFeature::kCamera:
        return protocol::Page::PermissionsPolicyFeatureEnum::Camera;
    case mojom::blink::PermissionsPolicyFeature::kCapturedSurfaceControl:
        return protocol::Page::PermissionsPolicyFeatureEnum::CapturedSurfaceControl;
    case mojom::blink::PermissionsPolicyFeature::kClientHintDPR:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChDpr;
    case mojom::blink::PermissionsPolicyFeature::kClientHintDeviceMemory:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChDeviceMemory;
    case mojom::blink::PermissionsPolicyFeature::kClientHintDownlink:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChDownlink;
    case mojom::blink::PermissionsPolicyFeature::kClientHintECT:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChEct;
    case mojom::blink::PermissionsPolicyFeature::kClientHintPrefersColorScheme:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChPrefersColorScheme;
    case mojom::blink::PermissionsPolicyFeature::kClientHintPrefersReducedMotion:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChPrefersReducedMotion;
    case mojom::blink::PermissionsPolicyFeature::kClientHintPrefersReducedTransparency:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChPrefersReducedTransparency;
    case mojom::blink::PermissionsPolicyFeature::kClientHintRTT:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChRtt;
    case mojom::blink::PermissionsPolicyFeature::kClientHintSaveData:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChSaveData;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUA:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUa;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAArch:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaArch;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUABitness:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaBitness;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAFormFactors:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaFormFactors;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAPlatform:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaPlatform;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAModel:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaModel;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAMobile:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaMobile;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAFullVersion:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaFullVersion;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAFullVersionList:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaFullVersionList;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAPlatformVersion:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaPlatformVersion;
    case mojom::blink::PermissionsPolicyFeature::kClientHintUAWoW64:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChUaWow64;
    case mojom::blink::PermissionsPolicyFeature::kClientHintViewportHeight:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChViewportHeight;
    case mojom::blink::PermissionsPolicyFeature::kClientHintViewportWidth:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChViewportWidth;
    case mojom::blink::PermissionsPolicyFeature::kClientHintWidth:
        return protocol::Page::PermissionsPolicyFeatureEnum::ChWidth;
    case mojom::blink::PermissionsPolicyFeature::kClipboardRead:
        return protocol::Page::PermissionsPolicyFeatureEnum::ClipboardRead;
    case mojom::blink::PermissionsPolicyFeature::kClipboardWrite:
        return protocol::Page::PermissionsPolicyFeatureEnum::ClipboardWrite;
    case mojom::blink::PermissionsPolicyFeature::kComputePressure:
        return protocol::Page::PermissionsPolicyFeatureEnum::ComputePressure;
    case mojom::blink::PermissionsPolicyFeature::kCrossOriginIsolated:
        return protocol::Page::PermissionsPolicyFeatureEnum::CrossOriginIsolated;
    case mojom::blink::PermissionsPolicyFeature::kDeferredFetch:
        return protocol::Page::PermissionsPolicyFeatureEnum::DeferredFetch;
    case mojom::blink::PermissionsPolicyFeature::kDigitalCredentialsGet:
        return protocol::Page::PermissionsPolicyFeatureEnum::DigitalCredentialsGet;
    case mojom::blink::PermissionsPolicyFeature::kDisplayCapture:
        return protocol::Page::PermissionsPolicyFeatureEnum::DisplayCapture;
    case mojom::blink::PermissionsPolicyFeature::kEncryptedMedia:
        return protocol::Page::PermissionsPolicyFeatureEnum::EncryptedMedia;
    case mojom::blink::PermissionsPolicyFeature::kExecutionWhileOutOfViewport:
        return protocol::Page::PermissionsPolicyFeatureEnum::ExecutionWhileOutOfViewport;
    case mojom::blink::PermissionsPolicyFeature::kExecutionWhileNotRendered:
        return protocol::Page::PermissionsPolicyFeatureEnum::ExecutionWhileNotRendered;
    case mojom::blink::PermissionsPolicyFeature::kFencedUnpartitionedStorageRead:
        return protocol::Page::PermissionsPolicyFeatureEnum::FencedUnpartitionedStorageRead;
    case mojom::blink::PermissionsPolicyFeature::kFocusWithoutUserActivation:
        return protocol::Page::PermissionsPolicyFeatureEnum::FocusWithoutUserActivation;
    case mojom::blink::PermissionsPolicyFeature::kFullscreen:
        return protocol::Page::PermissionsPolicyFeatureEnum::Fullscreen;
    case mojom::blink::PermissionsPolicyFeature::kFrobulate:
        return protocol::Page::PermissionsPolicyFeatureEnum::Frobulate;
    case mojom::blink::PermissionsPolicyFeature::kGamepad:
        return protocol::Page::PermissionsPolicyFeatureEnum::Gamepad;
    case mojom::blink::PermissionsPolicyFeature::kGeolocation:
        return protocol::Page::PermissionsPolicyFeatureEnum::Geolocation;
    case mojom::blink::PermissionsPolicyFeature::kGyroscope:
        return protocol::Page::PermissionsPolicyFeatureEnum::Gyroscope;
    case mojom::blink::PermissionsPolicyFeature::kHid:
        return protocol::Page::PermissionsPolicyFeatureEnum::Hid;
    case mojom::blink::PermissionsPolicyFeature::kIdentityCredentialsGet:
        return protocol::Page::PermissionsPolicyFeatureEnum::IdentityCredentialsGet;
    case mojom::blink::PermissionsPolicyFeature::kIdleDetection:
        return protocol::Page::PermissionsPolicyFeatureEnum::IdleDetection;
    case mojom::blink::PermissionsPolicyFeature::kJoinAdInterestGroup:
        return protocol::Page::PermissionsPolicyFeatureEnum::JoinAdInterestGroup;
    case mojom::blink::PermissionsPolicyFeature::kKeyboardMap:
        return protocol::Page::PermissionsPolicyFeatureEnum::KeyboardMap;
    case mojom::blink::PermissionsPolicyFeature::kLocalFonts:
        return protocol::Page::PermissionsPolicyFeatureEnum::LocalFonts;
    case mojom::blink::PermissionsPolicyFeature::kMagnetometer:
        return protocol::Page::PermissionsPolicyFeatureEnum::Magnetometer;
    case mojom::blink::PermissionsPolicyFeature::kMediaPlaybackWhileNotVisible:
        return protocol::Page::PermissionsPolicyFeatureEnum::MediaPlaybackWhileNotVisible;
    case mojom::blink::PermissionsPolicyFeature::kMicrophone:
        return protocol::Page::PermissionsPolicyFeatureEnum::Microphone;
    case mojom::blink::PermissionsPolicyFeature::kMidiFeature:
        return protocol::Page::PermissionsPolicyFeatureEnum::Midi;
    case mojom::blink::PermissionsPolicyFeature::kOTPCredentials:
        return protocol::Page::PermissionsPolicyFeatureEnum::OtpCredentials;
    case mojom::blink::PermissionsPolicyFeature::kPartitionedPopins:
        return protocol::Page::PermissionsPolicyFeatureEnum::Popins;
    case mojom::blink::PermissionsPolicyFeature::kPayment:
        return protocol::Page::PermissionsPolicyFeatureEnum::Payment;
    case mojom::blink::PermissionsPolicyFeature::kPictureInPicture:
        return protocol::Page::PermissionsPolicyFeatureEnum::PictureInPicture;
    case mojom::blink::PermissionsPolicyFeature::kPrivateAggregation:
        return protocol::Page::PermissionsPolicyFeatureEnum::PrivateAggregation;
    case mojom::blink::PermissionsPolicyFeature::kPrivateStateTokenIssuance:
        return protocol::Page::PermissionsPolicyFeatureEnum::PrivateStateTokenIssuance;
    case mojom::blink::PermissionsPolicyFeature::kPublicKeyCredentialsCreate:
        return protocol::Page::PermissionsPolicyFeatureEnum::PublickeyCredentialsCreate;
    case mojom::blink::PermissionsPolicyFeature::kPublicKeyCredentialsGet:
        return protocol::Page::PermissionsPolicyFeatureEnum::PublickeyCredentialsGet;
    case mojom::blink::PermissionsPolicyFeature::kRunAdAuction:
        return protocol::Page::PermissionsPolicyFeatureEnum::RunAdAuction;
    case mojom::blink::PermissionsPolicyFeature::kScreenWakeLock:
        return protocol::Page::PermissionsPolicyFeatureEnum::ScreenWakeLock;
    case mojom::blink::PermissionsPolicyFeature::kSerial:
        return protocol::Page::PermissionsPolicyFeatureEnum::Serial;
    case mojom::blink::PermissionsPolicyFeature::kSharedAutofill:
        return protocol::Page::PermissionsPolicyFeatureEnum::SharedAutofill;
    case mojom::blink::PermissionsPolicyFeature::kSharedStorage:
        return protocol::Page::PermissionsPolicyFeatureEnum::SharedStorage;
    case mojom::blink::PermissionsPolicyFeature::kSharedStorageSelectUrl:
        return protocol::Page::PermissionsPolicyFeatureEnum::SharedStorageSelectUrl;
    case mojom::blink::PermissionsPolicyFeature::kSpeakerSelection:
        return protocol::Page::PermissionsPolicyFeatureEnum::SpeakerSelection;
    case mojom::blink::PermissionsPolicyFeature::kStorageAccessAPI:
        return protocol::Page::PermissionsPolicyFeatureEnum::StorageAccess;
    case mojom::blink::PermissionsPolicyFeature::kSyncXHR:
        return protocol::Page::PermissionsPolicyFeatureEnum::SyncXhr;
    case mojom::blink::PermissionsPolicyFeature::kTrustTokenRedemption:
        return protocol::Page::PermissionsPolicyFeatureEnum::PrivateStateTokenRedemption;
    case mojom::blink::PermissionsPolicyFeature::kUsb:
        return protocol::Page::PermissionsPolicyFeatureEnum::Usb;
    case mojom::blink::PermissionsPolicyFeature::kUnload:
        return protocol::Page::PermissionsPolicyFeatureEnum::Unload;
    case mojom::blink::PermissionsPolicyFeature::kVerticalScroll:
        return protocol::Page::PermissionsPolicyFeatureEnum::VerticalScroll;
    case mojom::blink::PermissionsPolicyFeature::kWebAppInstallation:
        return protocol::Page::PermissionsPolicyFeatureEnum::WebAppInstallation;
    case mojom::blink::PermissionsPolicyFeature::kWebShare:
        return protocol::Page::PermissionsPolicyFeatureEnum::WebShare;
    case mojom::blink::PermissionsPolicyFeature::kWebXr:
        return protocol::Page::PermissionsPolicyFeatureEnum::XrSpatialTracking;
    case mojom::blink::PermissionsPolicyFeature::kWindowManagement:
        return protocol::Page::PermissionsPolicyFeatureEnum::WindowManagement;
    default:
        // This default case also handles the mojom entry for
        // mojom::blink::PermissionsPolicyFeature::kNotFound.
        NOTREACHED();
    }
}

} // namespace blink
