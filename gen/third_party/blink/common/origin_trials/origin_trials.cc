// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/common/origin_trials/origin_trials.h"

#include <array>
#include <iterator>
#include <string_view>

#include "base/containers/contains.h"
#include "base/ranges/algorithm.h"
#include "build/build_config.h"
#include "build/buildflag.h"
#include "build/chromeos_buildflags.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_feature.mojom-shared.h"

// For testing. See OriginTrialsSampleAPIInvalidOS.
#define BUILDFLAG_INTERNAL_IS_INVALID() (0)

namespace blink {

namespace {

static constexpr size_t kMaxFeaturesPerTrial = 2;
static constexpr struct TrialToFeature {
    const char* trial_name;
    unsigned feature_count;
    std::array<mojom::OriginTrialFeature, kMaxFeaturesPerTrial> features;
} kTrialToFeaturesMap[] = {
    { "AdInterestGroupAPI", 1,
        {
            mojom::OriginTrialFeature::kAdInterestGroupAPI,
        } },
    { "AIPromptAPIForExtension", 1,
        {
            mojom::OriginTrialFeature::kAIPromptAPIForExtension,
        } },
    { "AISummarizationAPI", 2,
        {
            mojom::OriginTrialFeature::kAISummarizationAPI,
            mojom::OriginTrialFeature::kBuiltInAIAPI,
        } },
    { "AppTitle", 1,
        {
            mojom::OriginTrialFeature::kAppTitle,
        } },
    { "AttributionReportingInterface", 1,
        {
            mojom::OriginTrialFeature::kAttributionReportingInterface,
        } },
    { "AudioContextPlayoutStats", 1,
        {
            mojom::OriginTrialFeature::kAudioContextPlayoutStats,
        } },
    { "AutoDarkMode", 1,
        {
            mojom::OriginTrialFeature::kAutoDarkMode,
        } },
    { "BackForwardCacheExperimentHTTPHeader", 1,
        {
            mojom::OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader,
        } },
    { "BackForwardCacheNotRestoredReasons", 1,
        {
            mojom::OriginTrialFeature::kBackForwardCacheNotRestoredReasons,
        } },
    { "CacheStorageCodeCacheHint", 1,
        {
            mojom::OriginTrialFeature::kCacheStorageCodeCacheHint,
        } },
    { "Canvas2dMesh", 1,
        {
            mojom::OriginTrialFeature::kCanvas2dMesh,
        } },
    { "CapturedSurfaceControl", 1,
        {
            mojom::OriginTrialFeature::kCapturedSurfaceControl,
        } },
    { "CoopRestrictProperties", 1,
        {
            mojom::OriginTrialFeature::kCoopRestrictProperties,
        } },
    { "WebSQL", 1,
        {
            mojom::OriginTrialFeature::kDatabase,
        } },
    { "DeprecateUnloadOptOut", 1,
        {
            mojom::OriginTrialFeature::kDeprecateUnloadOptOut,
        } },
    { "DigitalGoodsV2", 1,
        {
            mojom::OriginTrialFeature::kDigitalGoods,
        } },
    { "DisableDifferentOriginSubframeDialogSuppression", 1,
        {
            mojom::OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression,
        } },
    { "DisableHardwareNoiseSuppression", 1,
        {
            mojom::OriginTrialFeature::kDisableHardwareNoiseSuppression,
        } },
    { "DisableReduceAcceptLanguage", 1,
        {
            mojom::OriginTrialFeature::kDisableReduceAcceptLanguage,
        } },
    { "DisableThirdPartyStoragePartitioning2", 1,
        {
            mojom::OriginTrialFeature::kDisableThirdPartyStoragePartitioning2,
        } },
    { "DocumentIsolationPolicy", 1,
        {
            mojom::OriginTrialFeature::kDocumentIsolationPolicy,
        } },
    { "DocumentPolicyIncludeJSCallStacksInCrashReports", 1,
        {
            mojom::OriginTrialFeature::kDocumentPolicyIncludeJSCallStacksInCrashReports,
        } },
    { "DocumentPolicyNegotiation", 1,
        {
            mojom::OriginTrialFeature::kDocumentPolicyNegotiation,
        } },
    { "FedCmContinueOnBundle", 1,
        {
            mojom::OriginTrialFeature::kFedCmAuthz,
        } },
    { "FedCmButtonMode", 1,
        {
            mojom::OriginTrialFeature::kFedCmButtonMode,
        } },
    { "FedCmMultipleIdentityProviders", 1,
        {
            mojom::OriginTrialFeature::kFedCmMultipleIdentityProviders,
        } },
    { "FedCmWithStorageAccessAPI", 1,
        {
            mojom::OriginTrialFeature::kFedCmWithStorageAccessAPI,
        } },
    { "FetchLaterAPI", 1,
        {
            mojom::OriginTrialFeature::kFetchLaterAPI,
        } },
    { "FileSystemObserver", 1,
        {
            mojom::OriginTrialFeature::kFileSystemObserver,
        } },
    { "FledgeBiddingAndAuctionServer", 1,
        {
            mojom::OriginTrialFeature::kFledgeBiddingAndAuctionServerAPI,
        } },
    { "Focusgroup", 1,
        {
            mojom::OriginTrialFeature::kFocusgroup,
        } },
    { "GetAllScreensMedia", 1,
        {
            mojom::OriginTrialFeature::kGetAllScreensMedia,
        } },
    { "HrefTranslate", 1,
        {
            mojom::OriginTrialFeature::kHrefTranslate,
        } },
    { "JavaScriptCompileHintsMagicAlways", 1,
        {
            mojom::OriginTrialFeature::kJavaScriptCompileHintsMagicAlwaysRuntime,
        } },
    { "JavaScriptCompileHintsMagic", 1,
        {
            mojom::OriginTrialFeature::kJavaScriptCompileHintsMagicRuntime,
        } },
    { "KeyboardFocusableScrollersOptOut", 1,
        {
            mojom::OriginTrialFeature::kKeyboardFocusableScrollersOptOut,
        } },
    { "LanguageDetectionAPI", 1,
        {
            mojom::OriginTrialFeature::kLanguageDetectionAPI,
        } },
    { "LimitThirdPartyCookies", 1,
        {
            mojom::OriginTrialFeature::kLimitThirdPartyCookies,
        } },
    { "MediaCaptureBackgroundBlur", 2,
        {
            mojom::OriginTrialFeature::kMediaCaptureBackgroundBlur,
            mojom::OriginTrialFeature::kMediaCaptureConfigurationChange,
        } },
    { "MediaPreviewsOptOutPersistent", 1,
        {
            mojom::OriginTrialFeature::kMediaPreviewsOptOut,
        } },
    { "MediaSourceExtensionsForWebCodecs", 1,
        {
            mojom::OriginTrialFeature::kMediaSourceExtensionsForWebCodecs,
        } },
    { "MutationEvents", 1,
        {
            mojom::OriginTrialFeature::kMutationEvents,
        } },
    { "SoftNavigationHeuristics", 2,
        {
            mojom::OriginTrialFeature::kNavigationId,
            mojom::OriginTrialFeature::kSoftNavigationHeuristics,
        } },
    { "NotificationTriggers", 1,
        {
            mojom::OriginTrialFeature::kNotificationTriggers,
        } },
    { "Frobulate", 2,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPI,
            mojom::OriginTrialFeature::kProtectedOriginTrialsSampleAPI,
        } },
    { "FrobulateBrowserReadWrite", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIBrowserReadWrite,
        } },
    { "FrobulateDeprecation", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIDeprecation,
        } },
    { "FrobulateExpiryGracePeriod", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod,
        } },
    { "FrobulateExpiryGracePeriodThirdParty", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty,
        } },
    { "FrobulateImplied", 2,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIImplied,
            mojom::OriginTrialFeature::kProtectedOriginTrialsSampleAPIImplied,
        } },
    { "FrobulateInvalidOS", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS,
        } },
    { "FrobulateNavigation", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPINavigation,
        } },
    { "FrobulatePersistentExpiryGracePeriod", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod,
        } },
    { "FrobulatePersistent", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature,
        } },
    { "FrobulatePersistentInvalidOS", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentInvalidOS,
        } },
    { "FrobulatePersistentThirdPartyDeprecation", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature,
        } },
    { "FrobulateThirdParty", 1,
        {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIThirdParty,
        } },
    { "PageFreezeOptIn", 1,
        {
            mojom::OriginTrialFeature::kPageFreezeOptIn,
        } },
    { "PageFreezeOptOut", 1,
        {
            mojom::OriginTrialFeature::kPageFreezeOptOut,
        } },
    { "Parakeet", 1,
        {
            mojom::OriginTrialFeature::kParakeet,
        } },
    { "PerMethodCanMakePaymentQuota", 1,
        {
            mojom::OriginTrialFeature::kPerMethodCanMakePaymentQuota,
        } },
    { "PermissionElement", 1,
        {
            mojom::OriginTrialFeature::kPermissionElement,
        } },
    { "PNaCl", 1,
        {
            mojom::OriginTrialFeature::kPNaCl,
        } },
    { "DeprecatePrefixedVideoFullscreen", 1,
        {
            mojom::OriginTrialFeature::kPrefixedVideoFullscreen,
        } },
    { "PrivateNetworkAccessNonSecureContextsAllowed", 1,
        {
            mojom::OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed,
        } },
    { "PrivateNetworkAccessPermissionPrompt", 1,
        {
            mojom::OriginTrialFeature::kPrivateNetworkAccessPermissionPrompt,
        } },
    { "TrustTokens", 1,
        {
            mojom::OriginTrialFeature::kPrivateStateTokens,
        } },
    { "ReduceAcceptLanguage", 1,
        {
            mojom::OriginTrialFeature::kReduceAcceptLanguage,
        } },
    { "RtcAudioJitterBufferMaxPackets", 1,
        {
            mojom::OriginTrialFeature::kRtcAudioJitterBufferMaxPackets,
        } },
    { "RTCEncodedFrameSetMetadata", 1,
        {
            mojom::OriginTrialFeature::kRTCEncodedFrameSetMetadata,
        } },
    { "RTCLegacyCallbackBasedGetStats", 1,
        {
            mojom::OriginTrialFeature::kRTCLegacyCallbackBasedGetStats,
        } },
    { "RTCStatsRelativePacketArrivalDelay", 1,
        {
            mojom::OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay,
        } },
    { "SecurePaymentConfirmationOptOut", 1,
        {
            mojom::OriginTrialFeature::kSecurePaymentConfirmationOptOut,
        } },
    { "ServiceWorkerStaticRouter", 1,
        {
            mojom::OriginTrialFeature::kServiceWorkerStaticRouter,
        } },
    { "ServiceWorkerStaticRouterTimingInfo", 1,
        {
            mojom::OriginTrialFeature::kServiceWorkerStaticRouterTimingInfo,
        } },
    { "SignatureBasedIntegrity", 1,
        {
            mojom::OriginTrialFeature::kSignatureBasedIntegrity,
        } },
    { "SkipPreloadScanning", 1,
        {
            mojom::OriginTrialFeature::kSkipPreloadScanning,
        } },
    { "SpeculationRulesPrefetchFuture", 1,
        {
            mojom::OriginTrialFeature::kSpeculationRulesPrefetchFuture,
        } },
    { "DisableStandardizedBrowserZoom", 1,
        {
            mojom::OriginTrialFeature::kStandardizedBrowserZoomOptOut,
        } },
    { "StorageAccessHeader", 1,
        {
            mojom::OriginTrialFeature::kStorageAccessHeader,
        } },
    { "TextFragmentIdentifiers", 1,
        {
            mojom::OriginTrialFeature::kTextFragmentIdentifiers,
        } },
    { "TopLevelTpcd", 1,
        {
            mojom::OriginTrialFeature::kTopLevelTpcd,
        } },
    { "ForceTouchEventFeatureDetectionForInspector", 1,
        {
            mojom::OriginTrialFeature::kTouchEventFeatureDetection,
        } },
    { "Tpcd", 1,
        {
            mojom::OriginTrialFeature::kTpcd,
        } },
    { "TranslationAPI", 1,
        {
            mojom::OriginTrialFeature::kTranslationAPI,
        } },
    { "TranslationAPIEntryPoint", 1,
        {
            mojom::OriginTrialFeature::kTranslationAPIEntryPoint,
        } },
    { "UnrestrictedSharedArrayBuffer", 1,
        {
            mojom::OriginTrialFeature::kUnrestrictedSharedArrayBuffer,
        } },
    { "FoldableAPIs", 1,
        {
            mojom::OriginTrialFeature::kViewportSegments,
        } },
    { "WebAppLaunchQueue", 1,
        {
            mojom::OriginTrialFeature::kWebAppLaunchQueue,
        } },
    { "WebAppScopeExtensions", 1,
        {
            mojom::OriginTrialFeature::kWebAppScopeExtensions,
        } },
    { "WebAppUrlHandling", 1,
        {
            mojom::OriginTrialFeature::kWebAppUrlHandling,
        } },
    { "WebAssemblyJSPromiseIntegration", 1,
        {
            mojom::OriginTrialFeature::kWebAssemblyJSPromiseIntegration,
        } },
    { "WebAssemblyJSStringBuiltins", 1,
        {
            mojom::OriginTrialFeature::kWebAssemblyJSStringBuiltins,
        } },
    { "WebAuthnAttestationFormats", 1,
        {
            mojom::OriginTrialFeature::kWebAuthenticationAttestationFormats,
        } },
    { "WebGPUSubgroupsFeatures", 1,
        {
            mojom::OriginTrialFeature::kWebGPUSubgroupsFeatures,
        } },
    { "WebIdentityDigitalCredentials", 1,
        {
            mojom::OriginTrialFeature::kWebIdentityDigitalCredentials,
        } },
    { "WebTransportCustomCertificates", 1,
        {
            mojom::OriginTrialFeature::kWebTransportCustomCertificates,
        } },
    { "WebViewXRequestedWithDeprecation", 1,
        {
            mojom::OriginTrialFeature::kWebViewXRequestedWithDeprecation,
        } },
    { "WebXRImageTracking", 1,
        {
            mojom::OriginTrialFeature::kWebXRImageTracking,
        } },
    { "WebXRPlaneDetection", 1,
        {
            mojom::OriginTrialFeature::kWebXRPlaneDetection,
        } },
    // For testing
    { "This trial does not exist", 1, { mojom::OriginTrialFeature::kNonExisting } },
};

} // namespace

bool origin_trials::IsTrialValid(std::string_view trial_name)
{
    return base::Contains(kTrialToFeaturesMap, trial_name, &TrialToFeature::trial_name);
}

bool origin_trials::IsTrialEnabledForInsecureContext(std::string_view trial_name)
{
    static const char* const kEnabledForInsecureContext[] = {
        "DeprecateUnloadOptOut",
        "DisableDifferentOriginSubframeDialogSuppression",
        "DisableReduceAcceptLanguage",
        "DisableThirdPartyStoragePartitioning2",
        "KeyboardFocusableScrollersOptOut",
        "MutationEvents",
        "FrobulateDeprecation",
        "DeprecatePrefixedVideoFullscreen",
        "PrivateNetworkAccessNonSecureContextsAllowed",
        "DisableStandardizedBrowserZoom",
        "WebViewXRequestedWithDeprecation",
    };
    return base::Contains(kEnabledForInsecureContext, trial_name);
}

bool origin_trials::IsTrialEnabledForThirdPartyOrigins(std::string_view trial_name)
{
    static const char* const kEnabledForThirdPartyOrigins[] = {
        "AttributionReportingInterface",
        "Canvas2dMesh",
        "WebSQL",
        "DeprecateUnloadOptOut",
        "DisableReduceAcceptLanguage",
        "DisableThirdPartyStoragePartitioning2",
        "FedCmContinueOnBundle",
        "FedCmButtonMode",
        "FedCmMultipleIdentityProviders",
        "FetchLaterAPI",
        "FledgeBiddingAndAuctionServer",
        "KeyboardFocusableScrollersOptOut",
        "MediaPreviewsOptOutPersistent",
        "MutationEvents",
        "FrobulateExpiryGracePeriodThirdParty",
        "FrobulatePersistent",
        "FrobulatePersistentInvalidOS",
        "FrobulatePersistentThirdPartyDeprecation",
        "FrobulateThirdParty",
        "DeprecatePrefixedVideoFullscreen",
        "TrustTokens",
        "SecurePaymentConfirmationOptOut",
        "SoftNavigationHeuristics",
        "SpeculationRulesPrefetchFuture",
        "DisableStandardizedBrowserZoom",
        "Tpcd",
        "WebAuthnAttestationFormats",
        "WebIdentityDigitalCredentials",
        "WebViewXRequestedWithDeprecation",
    };
    return base::Contains(kEnabledForThirdPartyOrigins, trial_name);
}

bool origin_trials::IsTrialEnabledForBrowserProcessReadAccess(std::string_view trial_name)
{
    // Select all features that represent origin trials and have
    // browser_process_read_write_access enabled. Determine if that list of
    // features contains the  `trial_name` provided.
    static const char* const kEnabledForBrowserProcessReadWriteAccess[] = {
        "DisableThirdPartyStoragePartitioning2",
        "FedCmContinueOnBundle",
        "FedCmWithStorageAccessAPI",
        "FrobulateBrowserReadWrite",
    };
    return base::Contains(kEnabledForBrowserProcessReadWriteAccess, trial_name);
}

bool origin_trials::IsDeprecationTrial(std::string_view trial_name)
{
    for (auto feature : FeaturesForTrial(trial_name)) {
        if (GetTrialType(feature) == OriginTrialType::kDeprecation) {
            return true;
        }
    }
    return false;
}

OriginTrialType origin_trials::GetTrialType(mojom::OriginTrialFeature feature)
{
    switch (feature) {
    case mojom::OriginTrialFeature::kDatabase:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kDeprecateUnloadOptOut:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kDisableReduceAcceptLanguage:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kDisableThirdPartyStoragePartitioning2:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kKeyboardFocusableScrollersOptOut:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kMutationEvents:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kPrefixedVideoFullscreen:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kStandardizedBrowserZoomOptOut:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kTopLevelTpcd:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kTpcd:
        return OriginTrialType::kDeprecation;
    case mojom::OriginTrialFeature::kWebViewXRequestedWithDeprecation:
        return OriginTrialType::kDeprecation;
    default:
        return OriginTrialType::kDefault;
    }
}

base::span<const mojom::OriginTrialFeature> origin_trials::FeaturesForTrial(std::string_view trial_name)
{
    auto it = base::ranges::find(kTrialToFeaturesMap, trial_name, &TrialToFeature::trial_name);
    DCHECK(it != std::end(kTrialToFeaturesMap));
    return { it->features.begin(), it->feature_count };
}

base::span<const mojom::OriginTrialFeature> origin_trials::GetImpliedFeatures(mojom::OriginTrialFeature feature)
{
    if (feature == mojom::OriginTrialFeature::kParakeet) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kAdInterestGroupAPI,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kAISummarizationAPI) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kBuiltInAIAPI,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kLanguageDetectionAPI) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kBuiltInAIAPI,
            mojom::OriginTrialFeature::kTranslationAPIEntryPoint,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kTranslationAPIEntryPoint) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kBuiltInAIAPI,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kMediaCaptureBackgroundBlur) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kMediaCaptureConfigurationChange,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kOriginTrialsSampleAPI) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIImplied,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kOriginTrialsSampleAPIImplied,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kProtectedOriginTrialsSampleAPI) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kProtectedOriginTrialsSampleAPIImplied,
        };
        return implied_features;
    }
    if (feature == mojom::OriginTrialFeature::kTranslationAPI) {
        static constexpr mojom::OriginTrialFeature implied_features[] = {
            mojom::OriginTrialFeature::kTranslationAPIEntryPoint,
        };
        return implied_features;
    }
    return {};
}

bool origin_trials::FeatureEnabledForOS(mojom::OriginTrialFeature feature)
{
    switch (feature) {
    case mojom::OriginTrialFeature::kAdInterestGroupAPI:
        return true;
    case mojom::OriginTrialFeature::kAIPromptAPIForExtension:
        return true;
    case mojom::OriginTrialFeature::kAISummarizationAPI:
        return true;
    case mojom::OriginTrialFeature::kAppTitle:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kAttributionReportingInterface:
        return true;
    case mojom::OriginTrialFeature::kAudioContextPlayoutStats:
        return true;
    case mojom::OriginTrialFeature::kAutoDarkMode:
        return true;
    case mojom::OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader:
        return true;
    case mojom::OriginTrialFeature::kBackForwardCacheNotRestoredReasons:
        return true;
    case mojom::OriginTrialFeature::kBuiltInAIAPI:
        return true;
    case mojom::OriginTrialFeature::kCacheStorageCodeCacheHint:
        return true;
    case mojom::OriginTrialFeature::kCanvas2dMesh:
        return true;
    case mojom::OriginTrialFeature::kCapturedSurfaceControl:
        return true;
    case mojom::OriginTrialFeature::kCoopRestrictProperties:
        return true;
    case mojom::OriginTrialFeature::kDatabase:
        return true;
    case mojom::OriginTrialFeature::kDeprecateUnloadOptOut:
        return true;
    case mojom::OriginTrialFeature::kDigitalGoods:
#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression:
        return true;
    case mojom::OriginTrialFeature::kDisableHardwareNoiseSuppression:
        return true;
    case mojom::OriginTrialFeature::kDisableReduceAcceptLanguage:
        return true;
    case mojom::OriginTrialFeature::kDisableThirdPartyStoragePartitioning2:
        return true;
    case mojom::OriginTrialFeature::kDocumentIsolationPolicy:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kDocumentPolicyIncludeJSCallStacksInCrashReports:
        return true;
    case mojom::OriginTrialFeature::kDocumentPolicyNegotiation:
        return true;
    case mojom::OriginTrialFeature::kFedCmAuthz:
        return true;
    case mojom::OriginTrialFeature::kFedCmButtonMode:
        return true;
    case mojom::OriginTrialFeature::kFedCmMultipleIdentityProviders:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kFedCmWithStorageAccessAPI:
        return true;
    case mojom::OriginTrialFeature::kFetchLaterAPI:
        return true;
    case mojom::OriginTrialFeature::kFileSystemObserver:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kFledgeBiddingAndAuctionServerAPI:
        return true;
    case mojom::OriginTrialFeature::kFocusgroup:
        return true;
    case mojom::OriginTrialFeature::kGetAllScreensMedia:
#if BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kHrefTranslate:
        return true;
    case mojom::OriginTrialFeature::kJavaScriptCompileHintsMagicAlwaysRuntime:
        return true;
    case mojom::OriginTrialFeature::kJavaScriptCompileHintsMagicRuntime:
        return true;
    case mojom::OriginTrialFeature::kKeyboardFocusableScrollersOptOut:
        return true;
    case mojom::OriginTrialFeature::kLanguageDetectionAPI:
        return true;
    case mojom::OriginTrialFeature::kLimitThirdPartyCookies:
        return true;
    case mojom::OriginTrialFeature::kMediaCaptureBackgroundBlur:
        return true;
    case mojom::OriginTrialFeature::kMediaCaptureConfigurationChange:
        return true;
    case mojom::OriginTrialFeature::kMediaPreviewsOptOut:
        return true;
    case mojom::OriginTrialFeature::kMediaSourceExtensionsForWebCodecs:
        return true;
    case mojom::OriginTrialFeature::kMutationEvents:
        return true;
    case mojom::OriginTrialFeature::kNavigationId:
        return true;
    case mojom::OriginTrialFeature::kNotificationTriggers:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPI:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIBrowserReadWrite:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIImplied:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
#if BUILDFLAG(IS_INVALID)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPINavigation:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentInvalidOS:
#if BUILDFLAG(IS_INVALID)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature:
        return true;
    case mojom::OriginTrialFeature::kOriginTrialsSampleAPIThirdParty:
        return true;
    case mojom::OriginTrialFeature::kPageFreezeOptIn:
        return true;
    case mojom::OriginTrialFeature::kPageFreezeOptOut:
        return true;
    case mojom::OriginTrialFeature::kParakeet:
        return true;
    case mojom::OriginTrialFeature::kPerMethodCanMakePaymentQuota:
        return true;
    case mojom::OriginTrialFeature::kPermissionElement:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kPNaCl:
        return true;
    case mojom::OriginTrialFeature::kPrefixedVideoFullscreen:
        return true;
    case mojom::OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed:
        return true;
    case mojom::OriginTrialFeature::kPrivateNetworkAccessPermissionPrompt:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kPrivateStateTokens:
        return true;
    case mojom::OriginTrialFeature::kProtectedOriginTrialsSampleAPI:
        return true;
    case mojom::OriginTrialFeature::kProtectedOriginTrialsSampleAPIImplied:
        return true;
    case mojom::OriginTrialFeature::kReduceAcceptLanguage:
        return true;
    case mojom::OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
        return true;
    case mojom::OriginTrialFeature::kRTCEncodedFrameSetMetadata:
        return true;
    case mojom::OriginTrialFeature::kRTCLegacyCallbackBasedGetStats:
        return true;
    case mojom::OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
        return true;
    case mojom::OriginTrialFeature::kSecurePaymentConfirmationOptOut:
        return true;
    case mojom::OriginTrialFeature::kServiceWorkerStaticRouter:
        return true;
    case mojom::OriginTrialFeature::kServiceWorkerStaticRouterTimingInfo:
        return true;
    case mojom::OriginTrialFeature::kSignatureBasedIntegrity:
        return true;
    case mojom::OriginTrialFeature::kSkipPreloadScanning:
        return true;
    case mojom::OriginTrialFeature::kSoftNavigationHeuristics:
        return true;
    case mojom::OriginTrialFeature::kSpeculationRulesPrefetchFuture:
        return true;
    case mojom::OriginTrialFeature::kStandardizedBrowserZoomOptOut:
        return true;
    case mojom::OriginTrialFeature::kStorageAccessHeader:
        return true;
    case mojom::OriginTrialFeature::kTextFragmentIdentifiers:
        return true;
    case mojom::OriginTrialFeature::kTopLevelTpcd:
        return true;
    case mojom::OriginTrialFeature::kTouchEventFeatureDetection:
        return true;
    case mojom::OriginTrialFeature::kTpcd:
        return true;
    case mojom::OriginTrialFeature::kTranslationAPI:
        return true;
    case mojom::OriginTrialFeature::kTranslationAPIEntryPoint:
        return true;
    case mojom::OriginTrialFeature::kUnrestrictedSharedArrayBuffer:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kViewportSegments:
        return true;
    case mojom::OriginTrialFeature::kWebAppLaunchQueue:
        return true;
    case mojom::OriginTrialFeature::kWebAppScopeExtensions:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kWebAppUrlHandling:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kWebAssemblyJSPromiseIntegration:
        return true;
    case mojom::OriginTrialFeature::kWebAssemblyJSStringBuiltins:
        return true;
    case mojom::OriginTrialFeature::kWebAuthenticationAttestationFormats:
#if BUILDFLAG(IS_ANDROID)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kWebGPUSubgroupsFeatures:
        return true;
    case mojom::OriginTrialFeature::kWebIdentityDigitalCredentials:
#if BUILDFLAG(IS_ANDROID)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kWebTransportCustomCertificates:
        return true;
    case mojom::OriginTrialFeature::kWebViewXRequestedWithDeprecation:
#if BUILDFLAG(IS_ANDROID)
        return true;
#else
        return false;
#endif
    case mojom::OriginTrialFeature::kWebXRImageTracking:
        return true;
    case mojom::OriginTrialFeature::kWebXRPlaneDetection:
        return true;
    // For testing
    case mojom::OriginTrialFeature::kNonExisting:
        return true;
    }
}

} // namespace blink
