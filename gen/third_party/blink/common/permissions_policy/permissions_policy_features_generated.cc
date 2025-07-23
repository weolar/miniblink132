// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/common/permissions_policy/permissions_policy_features_generated.h"

#include "base/no_destructor.h"
#include "base/feature_list.h"
#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/mojom/permissions_policy/permissions_policy_feature.mojom.h"

namespace blink {

// Applies new defaults based on flags.
void UpdatePermissionsPolicyFeatureListFlagDefaults(PermissionsPolicyFeatureList& mutable_feature_list)
{
    if (base::FeatureList::IsEnabled(features::kAdInterestGroupAPIRestrictedPolicyByDefault)) {
        mutable_feature_list.find(mojom::PermissionsPolicyFeature::kJoinAdInterestGroup)->second = PermissionsPolicyFeatureDefault::EnableForSelf;
    } else {
        mutable_feature_list.find(mojom::PermissionsPolicyFeature::kJoinAdInterestGroup)->second = PermissionsPolicyFeatureDefault::EnableForAll;
    }

    if (base::FeatureList::IsEnabled(features::kAdInterestGroupAPIRestrictedPolicyByDefault)) {
        mutable_feature_list.find(mojom::PermissionsPolicyFeature::kRunAdAuction)->second = PermissionsPolicyFeatureDefault::EnableForSelf;
    } else {
        mutable_feature_list.find(mojom::PermissionsPolicyFeature::kRunAdAuction)->second = PermissionsPolicyFeatureDefault::EnableForAll;
    }
}

// The base list with no flags or special cases.
PermissionsPolicyFeatureList GetBasePermissionsPolicyFeatureList()
{
    static const base::NoDestructor<PermissionsPolicyFeatureList> feature_list({
        { mojom::PermissionsPolicyFeature::kAccelerometer, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kAllScreensCapture, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kAmbientLightSensor, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kAttributionReporting, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kAutoplay, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kBluetooth, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kBrowsingTopics, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kBrowsingTopicsBackwardCompatible, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kCamera, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kCapturedSurfaceControl, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintDPR, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintDeviceMemory, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintDownlink, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintECT, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintPrefersColorScheme, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintPrefersReducedMotion, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintPrefersReducedTransparency, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintRTT, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintSaveData, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kClientHintUA, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kClientHintUAArch, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUABitness, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUAFormFactors, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUAPlatform, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kClientHintUAModel, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUAMobile, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kClientHintUAFullVersion, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUAFullVersionList, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUAPlatformVersion, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintUAWoW64, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintViewportHeight, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintViewportWidth, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClientHintWidth, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClipboardRead, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kClipboardWrite, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kComputePressure, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kControlledFrame, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kCrossOriginIsolated, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kDeferredFetch, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kDigitalCredentialsGet, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kDirectSockets, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kDirectSocketsPrivate, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kDisplayCapture, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kEncryptedMedia, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kExecutionWhileOutOfViewport, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kExecutionWhileNotRendered, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kFencedUnpartitionedStorageRead, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kFocusWithoutUserActivation, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kFullscreen, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kFrobulate, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kGamepad, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kGeolocation, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kGyroscope, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kHid, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kIdentityCredentialsGet, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kIdleDetection, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kJoinAdInterestGroup, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kKeyboardMap, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kLocalFonts, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kMagnetometer, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kMediaPlaybackWhileNotVisible, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kMicrophone, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kMidiFeature, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kOTPCredentials, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kPartitionedPopins, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kPayment, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kPictureInPicture, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kPrivateAggregation, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kPrivateStateTokenIssuance, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kPublicKeyCredentialsCreate, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kPublicKeyCredentialsGet, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kRunAdAuction, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kScreenWakeLock, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kSerial, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kSharedAutofill, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kSharedStorage, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kSharedStorageSelectUrl, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kSmartCard, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kSpeakerSelection, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kStorageAccessAPI, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kSubApps, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kSyncXHR, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kTrustTokenRedemption, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kUsb, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kUsbUnrestricted, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kUnload, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kVerticalScroll, PermissionsPolicyFeatureDefault::EnableForAll },
        { mojom::PermissionsPolicyFeature::kWebAppInstallation, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kWebPrinting, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kWebShare, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kWebXr, PermissionsPolicyFeatureDefault::EnableForSelf },
        { mojom::PermissionsPolicyFeature::kWindowManagement, PermissionsPolicyFeatureDefault::EnableForSelf },
    });
    return *feature_list;
}

// Defaults with "unload" using EnabledForNone.
PermissionsPolicyFeatureList& GetPermissionsPolicyFeatureListUnloadNone()
{
    static base::NoDestructor<PermissionsPolicyFeatureList> feature_list([] {
        PermissionsPolicyFeatureList map = GetBasePermissionsPolicyFeatureList();
        UpdatePermissionsPolicyFeatureListFlagDefaults(map);

        map.find(mojom::PermissionsPolicyFeature::kUnload)->second = PermissionsPolicyFeatureDefault::EnableForNone;

        return map;
    }());
    return *feature_list;
}

// Defaults with "unload" using EnabledForAll.
PermissionsPolicyFeatureList& GetPermissionsPolicyFeatureListUnloadAll()
{
    static base::NoDestructor<PermissionsPolicyFeatureList> feature_list([] {
        PermissionsPolicyFeatureList map = GetBasePermissionsPolicyFeatureList();
        UpdatePermissionsPolicyFeatureListFlagDefaults(map);

        map.find(mojom::PermissionsPolicyFeature::kUnload)->second = PermissionsPolicyFeatureDefault::EnableForAll;

        return map;
    }());
    return *feature_list;
}

} // namespace blink
