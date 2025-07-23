// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/viz/common/features.h"

#include <string>

#include "base/command_line.h"
#include "base/feature_list.h"
#include "base/metrics/field_trial_params.h"
#include "base/system/sys_info.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
#include "components/viz/common/delegated_ink_prediction_configuration.h"
#include "components/viz/common/switches.h"
#include "components/viz/common/viz_utils.h"
#include "gpu/config/gpu_finch_features.h"
#include "gpu/config/gpu_switches.h"
#include "media/media_buildflags.h"

#if BUILDFLAG(IS_ANDROID)
#include "base/android/build_info.h"
#endif

namespace {

// FieldTrialParams for `DynamicSchedulerForDraw` and
// `kDynamicSchedulerForClients`.
const char kDynamicSchedulerPercentile[] = "percentile";

} // namespace

namespace features {

std::optional<uint64_t> NumCooldownFramesForAckOnSurfaceActivationDuringInteraction()
{
    return 3;
//     if (!ShouldAckOnSurfaceActivationWhenInteractive()) {
//         return std::nullopt;
//     }
//     CHECK_GE(kNumCooldownFramesForAckOnSurfaceActivationDuringInteraction.Get(), 0) << "The number of cooldown frames must be non-negative";
//     return static_cast<uint64_t>(kNumCooldownFramesForAckOnSurfaceActivationDuringInteraction.Get());
}


// If enabled, CompositorFrameSinkClient::OnBeginFrame is also treated as the
// DidReceiveCompositorFrameAck. Both in providing the Ack for the previous
// frame, and in returning resources. While enabled we attempt to not send
// separate Ack and ReclaimResources signals. However if while sending an
// OnBeginFrame there is a pending Ack, then if the Ack arrives before the next
// OnBeginFrame we will send the Ack immediately, rather than batching it.
BASE_FEATURE(kOnBeginFrameAcks, "OnBeginFrameAcks", base::FEATURE_DISABLED_BY_DEFAULT);

bool IsOnBeginFrameAcksEnabled()
{
    return base::FeatureList::IsEnabled(features::kOnBeginFrameAcks);
}

BASE_FEATURE(kUseFrameIntervalDecider, "UseFrameIntervalDecider", base::FEATURE_DISABLED_BY_DEFAULT);

bool IsUsingFrameIntervalDecider()
{
#if BUILDFLAG(IS_ANDROID)
    if (base::FeatureList::IsEnabled(kWebViewFrameRateHints)) {
        return true;
    }
#endif
    return base::FeatureList::IsEnabled(kUseFrameIntervalDecider);
}

BASE_FEATURE(kEnableVariableRefreshRateAlwaysOn, "EnableVariableRefreshRateAlwaysOn", base::FEATURE_DISABLED_BY_DEFAULT);
bool IsVariableRefreshRateAlwaysOn()
{
    return base::FeatureList::IsEnabled(kEnableVariableRefreshRateAlwaysOn);
}

// If enabled, surface activation and draw do not block on dependencies.
BASE_FEATURE(kDrawImmediatelyWhenInteractive, "DrawImmediatelyWhenInteractive",
#if BUILDFLAG(IS_IOS)
    base::FEATURE_ENABLED_BY_DEFAULT
#else
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

bool ShouldDrawImmediatelyWhenInteractive()
{
    return base::FeatureList::IsEnabled(features::kDrawImmediatelyWhenInteractive);
}

// If enabled, info for quads from the last render pass will be reported as
// UMAs.
BASE_FEATURE(kShouldLogFrameQuadInfo, "ShouldLogFrameQuadInfo", base::FEATURE_ENABLED_BY_DEFAULT);

bool ShouldLogFrameQuadInfo()
{
    return base::FeatureList::IsEnabled(features::kShouldLogFrameQuadInfo);
}

// if enabled, Any CompositorFrameSink of type video that defines a preferred
// framerate that is below the display framerate will throttle OnBeginFrame
// callbacks to match the preferred framerate.
BASE_FEATURE(kOnBeginFrameThrottleVideo, "OnBeginFrameThrottleVideo",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#else
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

bool ShouldOnBeginFrameThrottleVideo()
{
    return base::FeatureList::IsEnabled(features::kOnBeginFrameThrottleVideo);
}

// Enables the use of power hint APIs on Android.
BASE_FEATURE(kAdpf, "Adpf", base::FEATURE_DISABLED_BY_DEFAULT);

// Target duration used for power hint on Android.
// `0` indicates use hard coded default.
const base::FeatureParam<int> kAdpfTargetDurationMs { &kAdpf, "AdpfTargetDurationMs", 0 };

#if BUILDFLAG(IS_CHROMEOS_ASH)
#define kEnableOverlayPrioritizationValue base::FEATURE_ENABLED_BY_DEFAULT
#else
#define kEnableOverlayPrioritizationValue base::FEATURE_DISABLED_BY_DEFAULT
#endif
BASE_FEATURE(kEnableOverlayPrioritization, "EnableOverlayPrioritization", kEnableOverlayPrioritizationValue);

#if BUILDFLAG(IS_CHROMEOS_ASH)
#define kUseMultipleOverlaysValue base::FEATURE_ENABLED_BY_DEFAULT
#else
#define kUseMultipleOverlaysValue base::FEATURE_DISABLED_BY_DEFAULT
#endif
BASE_FEATURE(kUseMultipleOverlays, "UseMultipleOverlays", kUseMultipleOverlaysValue);

const char kMaxOverlaysParam[] = "max_overlays";

#if BUILDFLAG(IS_CHROMEOS_LACROS)
#define kDelegatedCompositingValue base::FEATURE_ENABLED_BY_DEFAULT
#else
#define kDelegatedCompositingValue base::FEATURE_DISABLED_BY_DEFAULT
#endif
BASE_FEATURE(kDelegatedCompositing, "DelegatedCompositing", kDelegatedCompositingValue);

BASE_FEATURE(kVideoDetectorIgnoreNonVideos, "VideoDetectorIgnoreNonVideos", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSimpleFrameRateThrottling, "SimpleFrameRateThrottling", base::FEATURE_DISABLED_BY_DEFAULT);

// Kill-switch to disable de-jelly, even if flags/properties indicate it should
// be enabled.
BASE_FEATURE(kDisableDeJelly, "DisableDeJelly", base::FEATURE_DISABLED_BY_DEFAULT);

#if BUILDFLAG(IS_ANDROID)
// When wide color gamut content from the web is encountered, promote our
// display to wide color gamut if supported.
BASE_FEATURE(kDynamicColorGamut, "DynamicColorGamut", base::FEATURE_DISABLED_BY_DEFAULT);
#endif

// Submit CompositorFrame from SynchronousLayerTreeFrameSink directly to viz in
// WebView.
BASE_FEATURE(kVizFrameSubmissionForWebView, "VizFrameSubmissionForWebView", base::FEATURE_DISABLED_BY_DEFAULT);

// Whether we should use the real buffers corresponding to overlay candidates in
// order to do a pageflip test rather than allocating test buffers.
BASE_FEATURE(kUseRealBuffersForPageFlipTest, "UseRealBuffersForPageFlipTest", base::FEATURE_ENABLED_BY_DEFAULT);

#if BUILDFLAG(IS_FUCHSIA)
// Enables SkiaOutputDeviceBufferQueue instead of Vulkan swapchain on Fuchsia.
BASE_FEATURE(kUseSkiaOutputDeviceBufferQueue, "UseSkiaOutputDeviceBufferQueue", base::FEATURE_ENABLED_BY_DEFAULT);
#endif

// Whether we should log extra debug information to webrtc native log.
BASE_FEATURE(kWebRtcLogCapturePipeline, "WebRtcLogCapturePipeline", base::FEATURE_DISABLED_BY_DEFAULT);

#if BUILDFLAG(IS_WIN)
// Enables swap chains to call SetPresentDuration to request DWM/OS to reduce
// vsync.
BASE_FEATURE(kUseSetPresentDuration, "UseSetPresentDuration", base::FEATURE_DISABLED_BY_DEFAULT);
#endif // BUILDFLAG(IS_WIN)

// Enables platform supported delegated ink trails instead of Skia backed
// delegated ink trails.
BASE_FEATURE(kUsePlatformDelegatedInk, "UsePlatformDelegatedInk", base::FEATURE_ENABLED_BY_DEFAULT);

// Used to debug Android WebView Vulkan composite. Composite to an intermediate
// buffer and draw the intermediate buffer to the secondary command buffer.
BASE_FEATURE(kWebViewVulkanIntermediateBuffer, "WebViewVulkanIntermediateBuffer", base::FEATURE_DISABLED_BY_DEFAULT);

#if BUILDFLAG(IS_ANDROID)
// Hardcoded as disabled for WebView to have a different default for
// UseSurfaceLayerForVideo from chrome.
BASE_FEATURE(kUseSurfaceLayerForVideoDefault, "UseSurfaceLayerForVideoDefault", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebViewNewInvalidateHeuristic, "WebViewNewInvalidateHeuristic", base::FEATURE_DISABLED_BY_DEFAULT);

// Historically media on android hardcoded SRGB color space because of lack of
// color space support in surface control. This controls if we want to use real
// color space in DisplayCompositor.
BASE_FEATURE(kUseRealVideoColorSpaceForDisplay, "UseRealVideoColorSpaceForDisplay", base::FEATURE_ENABLED_BY_DEFAULT);
#endif

// Used by CC to throttle frame production of older surfaces. Used by the
// Browser to batch SurfaceSync calls sent to the Renderer for properties can
// change in close proximity to each other.
BASE_FEATURE(kSurfaceSyncThrottling, "SurfaceSyncThrottling", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDrawPredictedInkPoint, "DrawPredictedInkPoint", base::FEATURE_DISABLED_BY_DEFAULT);
const char kDraw1Point12Ms[] = "1-pt-12ms";
const char kDraw2Points6Ms[] = "2-pt-6ms";
const char kDraw1Point6Ms[] = "1-pt-6ms";
const char kDraw2Points3Ms[] = "2-pt-3ms";
const char kPredictorKalman[] = "kalman";
const char kPredictorLinearResampling[] = "linear-resampling";
const char kPredictorLinear1[] = "linear-1";
const char kPredictorLinear2[] = "linear-2";
const char kPredictorLsq[] = "lsq";

// Used by Viz to parameterize adjustments to scheduler deadlines.
BASE_FEATURE(kDynamicSchedulerForDraw, "DynamicSchedulerForDraw", base::FEATURE_DISABLED_BY_DEFAULT);
// User to parameterize adjustments to clients' deadlines.
BASE_FEATURE(kDynamicSchedulerForClients, "DynamicSchedulerForClients", base::FEATURE_DISABLED_BY_DEFAULT);

#if BUILDFLAG(IS_MAC)
BASE_FEATURE(kMacCAOverlayQuad, "MacCAOverlayQuads", base::FEATURE_ENABLED_BY_DEFAULT);
// The maximum supported overlay quad number on Mac CALayerOverlay.
// The default is set to -1. When MaxNum is < 0, the default in CALayerOverlay
// will be used instead.
const base::FeatureParam<int> kMacCAOverlayQuadMaxNum { &kMacCAOverlayQuad, "MacCAOverlayQuadMaxNum", -1 };
#endif

#if BUILDFLAG(IS_APPLE) || defined(USE_OZONE)
BASE_FEATURE(kCanSkipRenderPassOverlay, "CanSkipRenderPassOverlay", base::FEATURE_ENABLED_BY_DEFAULT);
#endif

// TODO(crbug.com/1357744): Solve the vulkan flakiness issue before enabling
// this on Linux.
BASE_FEATURE(kAllowUndamagedNonrootRenderPassToSkip, "AllowUndamagedNonrootRenderPassToSkip", base::FEATURE_DISABLED_BY_DEFAULT);

// Whether to:
// - Perform periodic inactive frame culling.
// - Cull *all* frames in case of critical memory pressure, rather than keeping
//   one.
BASE_FEATURE(kAggressiveFrameCulling, "AggressiveFrameCulling", base::FEATURE_DISABLED_BY_DEFAULT);

// If enabled, do not rely on surface garbage collection to happen
// periodically, but trigger it eagerly, to avoid missing calls.
BASE_FEATURE(kEagerSurfaceGarbageCollection, "EagerSurfaceGarbageCollection", base::FEATURE_DISABLED_BY_DEFAULT);

// Only applies when a caller has requested a custom BeginFrame rate via the
// Throttle() API in frame_sink_manager.mojom. If enabled, parameters related
// to the BeginFrame rate are overridden in viz to reflect the throttled rate
// before being circulated in the system. The most notable are the interval and
// deadline in BeginFrameArgs. If disabled, these parameters reflect the default
// vsync rate (the behavior at the time this feature was created.)
BASE_FEATURE(kOverrideThrottledFrameRateParams, "OverrideThrottledFrameRateParams", base::FEATURE_DISABLED_BY_DEFAULT);

// Allow SurfaceAggregator to merge render passes when they contain quads that
// require overlay (e.g. protected video). See usage in |EmitSurfaceContent|.
BASE_FEATURE(kAllowForceMergeRenderPassWithRequireOverlayQuads, "AllowForceMergeRenderPassWithRequireOverlayQuads", base::FEATURE_ENABLED_BY_DEFAULT);

// When enabled, ClientResourceProvider will take callbacks intended to be ran
// on the Main-thread, and will batch them into a single jump to that thread.
// Rather than each performing its own separate post task.
//
// Enabled 03/2024, kept to run a holdback experiment.
BASE_FEATURE(kBatchMainThreadReleaseCallbacks, "BatchMainThreadReleaseCallbacks", base::FEATURE_ENABLED_BY_DEFAULT);

// When enabled, ClientResourceProvider will allow for the batching of
// callbacks. So that the client can perform a series of individual releases,
// but have ClientResourceProvider coordinate the callbacks. This allows all of
// the Main-thread callbacks to be batched into a single jump to that thread.
//
// When disabled each callback will perform its own separate post task.
BASE_FEATURE(kBatchResourceRelease, "BatchResourceRelease", base::FEATURE_DISABLED_BY_DEFAULT);

// Use BlitRequests for copy requests made by ViewTransition.
BASE_FEATURE(kBlitRequestsForViewTransition, "BlitRequestsForViewTransition", base::FEATURE_DISABLED_BY_DEFAULT);

// Do HDR color conversion per render pass update rect in renderer instead of
// inserting a separate color conversion pass during surface aggregation.
BASE_FEATURE(kColorConversionInRenderer, "ColorConversionInRenderer", base::FEATURE_ENABLED_BY_DEFAULT);

#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_WIN)
// Cached in Java as well, make sure defaults are updated together.
BASE_FEATURE(kElasticOverscroll, "ElasticOverscroll",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#else // BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
);
#endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID)

// If enabled, Chrome includes the Renderer Main thread(s) into the
// ADPF(Android Dynamic Performance Framework) hint session.
BASE_FEATURE(kEnableADPFRendererMain, "EnableADPFRendererMain", base::FEATURE_ENABLED_BY_DEFAULT);

// If enabled, Chrome puts Renderer Main threads into a separate
// ADPF(Android Dynamic Performance Framework) hint session, and does not
// report any timing hints from this session.
BASE_FEATURE(kEnableADPFSeparateRendererMainSession, "EnableADPFSeparateRendererMainSession", base::FEATURE_DISABLED_BY_DEFAULT);

// If enabled, Chrome's ADPF(Android Dynamic Performance Framework) hint
// session includes Renderer threads only if:
// - The Renderer is handling an interacton
// - The Renderer is the main frame's Renderer, and there no Renderers handling
//   an interaction.
BASE_FEATURE(kEnableInteractiveOnlyADPFRenderer, "EnableInteractiveOnlyADPFRenderer", base::FEATURE_DISABLED_BY_DEFAULT);

// If enabled, Chrome includes only main frame's Renderer Main thread(s) into
// the ADPF(Android Dynamic Performance Framework) hint session.
BASE_FEATURE(kEnableMainFrameOnlyADPFRendererMain, "EnableMainFrameOnlyADPFRendererMain", base::FEATURE_DISABLED_BY_DEFAULT);

// When enabled, ClientResourceProvider will attempt to unlock and delete
// TransferableResources that have been returned as a part of eviction.
//
// Enabled by default 03/2014, kept to run a holdback experiment.
BASE_FEATURE(kEvictionUnlocksResources, "EvictionUnlocksResources", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEyeDropper, "EyeDropper", base::FEATURE_DISABLED_BY_DEFAULT);

// Stops BeginFrame issue to use |last_vsync_interval_| instead of the current
// set of BeginFrameArgs.
// TODO(b/333940735): Should be removed if the issue isn't fixed.
BASE_FEATURE(kLastVSyncArgsKillswitch, "LastVSyncArgsKillswitch", base::FEATURE_DISABLED_BY_DEFAULT);

// Note: This feature is actively being finched (Oct, 2024).
BASE_FEATURE(kRenderPassDrawnRect, "RenderPassDrawnRect", base::FEATURE_DISABLED_BY_DEFAULT);

// If enabled, FrameRateDecider will toggle to half framerate if there's only
// one video on screen whose framerate is lower than the display vsync and in
// perfect cadence.
BASE_FEATURE(kSingleVideoFrameRateThrottling, "SingleVideoFrameRateThrottling", base::FEATURE_DISABLED_BY_DEFAULT);

#if BUILDFLAG(IS_WIN)
BASE_FEATURE(kUseGammaContrastRegistrySettings, "UseGammaContrastRegistrySettings", base::FEATURE_ENABLED_BY_DEFAULT);
#endif  // BUILDFLAG(IS_WIN)

bool IsAdpfEnabled()
{
    // TODO(crbug.com/1157620): Limit this to correct android version.
    return base::FeatureList::IsEnabled(kAdpf);
}

bool IsOverlayPrioritizationEnabled()
{
#if BUILDFLAG(IS_CHROMEOS_LACROS)
    // DelegatedCompositing in Lacros makes this feature a no-op.
    return false;
#else
    return base::FeatureList::IsEnabled(kEnableOverlayPrioritization);
#endif
}

bool IsDelegatedCompositingEnabled()
{
    return base::FeatureList::IsEnabled(kDelegatedCompositing);
}

// If a synchronous IPC should used when destroying windows. This exists to test
// the impact of removing the sync IPC.
bool IsSyncWindowDestructionEnabled()
{
    static BASE_FEATURE(kSyncWindowDestruction, "SyncWindowDestruction", base::FEATURE_ENABLED_BY_DEFAULT);

    return base::FeatureList::IsEnabled(kSyncWindowDestruction);
}

bool IsSimpleFrameRateThrottlingEnabled()
{
    return base::FeatureList::IsEnabled(kSimpleFrameRateThrottling);
}

#if BUILDFLAG(IS_ANDROID)
bool IsDynamicColorGamutEnabled()
{
    if (viz::AlwaysUseWideColorGamut())
        return false;
    auto* build_info = base::android::BuildInfo::GetInstance();
    if (build_info->sdk_int() < base::android::SDK_VERSION_Q)
        return false;
    return base::FeatureList::IsEnabled(kDynamicColorGamut);
}
#endif

bool IsUsingVizFrameSubmissionForWebView()
{
    return base::FeatureList::IsEnabled(kVizFrameSubmissionForWebView);
}

bool ShouldUseRealBuffersForPageFlipTest()
{
    return base::FeatureList::IsEnabled(kUseRealBuffersForPageFlipTest);
}

bool ShouldWebRtcLogCapturePipeline()
{
    return base::FeatureList::IsEnabled(kWebRtcLogCapturePipeline);
}

#if BUILDFLAG(IS_WIN)
bool ShouldUseSetPresentDuration()
{
    return base::FeatureList::IsEnabled(kUseSetPresentDuration);
}
#endif // BUILDFLAG(IS_WIN)

// bool ShouldDrawPredictedInkPoints()
// {
//     if (!base::FeatureList::IsEnabled(kDrawPredictedInkPoint))
//         return std::nullopt;
// 
//     std::string predicted_points = GetFieldTrialParamValueByFeature(kDrawPredictedInkPoint, "predicted_points");
//     if (predicted_points == kDraw1Point12Ms)
//         return viz::PredictionConfig::k1Point12Ms;
//     else if (predicted_points == kDraw2Points6Ms)
//         return viz::PredictionConfig::k2Points6Ms;
//     else if (predicted_points == kDraw1Point6Ms)
//         return viz::PredictionConfig::k1Point6Ms;
//     else if (predicted_points == kDraw2Points3Ms)
//         return viz::PredictionConfig::k2Points3Ms;
// 
//     NOTREACHED();
//     return std::nullopt;
// }

std::string InkPredictor()
{
    if (!base::FeatureList::IsEnabled(kDrawPredictedInkPoint))
        return "";

    return GetFieldTrialParamValueByFeature(kDrawPredictedInkPoint, "predictor");
}

bool ShouldUsePlatformDelegatedInk()
{
    return base::FeatureList::IsEnabled(kUsePlatformDelegatedInk);
}

bool UseSurfaceLayerForVideo()
{
#if BUILDFLAG(IS_ANDROID)
    // SurfaceLayer video should work fine with new heuristic.
    if (base::FeatureList::IsEnabled(kWebViewNewInvalidateHeuristic))
        return true;

    // Allow enabling UseSurfaceLayerForVideo if webview is using surface control.
    if (::features::IsAndroidSurfaceControlEnabled()) {
        return true;
    }
    return base::FeatureList::IsEnabled(kUseSurfaceLayerForVideoDefault);
#else
    return true;
#endif
}

#if BUILDFLAG(IS_ANDROID)
bool UseRealVideoColorSpaceForDisplay()
{
    // We need Android S for proper color space support in SurfaceControl.
    if (base::android::BuildInfo::GetInstance()->sdk_int() < base::android::SdkVersion::SDK_VERSION_S)
        return false;

    return base::FeatureList::IsEnabled(features::kUseRealVideoColorSpaceForDisplay);
}
#endif

bool IsSurfaceSyncThrottling()
{
    return base::FeatureList::IsEnabled(kSurfaceSyncThrottling);
}

// Used by Viz to determine if viz::DisplayScheduler should dynamically adjust
// its frame deadline. Returns the percentile of historic draw times to base the
// deadline on. Or std::nullopt if the feature is disabled.
std::optional<double> IsDynamicSchedulerEnabledForDraw()
{
    if (!base::FeatureList::IsEnabled(kDynamicSchedulerForDraw))
        return std::nullopt;
    double result = base::GetFieldTrialParamByFeatureAsDouble(kDynamicSchedulerForDraw, kDynamicSchedulerPercentile, -1.0);
    if (result < 0.0)
        return std::nullopt;
    return result;
}

// Used by Viz to determine if the frame deadlines provided to CC should be
// dynamically adjusted. Returns the percentile of historic draw times to base
// the deadline on. Or std::nullopt if the feature is disabled.
std::optional<double> IsDynamicSchedulerEnabledForClients()
{
    if (!base::FeatureList::IsEnabled(kDynamicSchedulerForClients))
        return std::nullopt;
    double result = base::GetFieldTrialParamByFeatureAsDouble(kDynamicSchedulerForClients, kDynamicSchedulerPercentile, -1.0);
    if (result < 0.0)
        return std::nullopt;
    return result;
}

int MaxOverlaysConsidered()
{
    if (!IsOverlayPrioritizationEnabled()) {
        return 1;
    }

    if (!base::FeatureList::IsEnabled(kUseMultipleOverlays)) {
        return 1;
    }

    return base::GetFieldTrialParamByFeatureAsInt(kUseMultipleOverlays, kMaxOverlaysParam, 8);
}

bool ShouldVideoDetectorIgnoreNonVideoFrames()
{
    return base::FeatureList::IsEnabled(kVideoDetectorIgnoreNonVideos);
}

bool ShouldOverrideThrottledFrameRateParams()
{
    return base::FeatureList::IsEnabled(kOverrideThrottledFrameRateParams);
}

} // namespace features
