
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#include "services/metrics/public/cpp//ukm_decode.h"
#include "services/metrics/public/cpp//ukm_builders.h"

namespace ukm {
namespace builders {

std::map<uint64_t, EntryDecoder> CreateDecodeMap()
{
    return {

        { UINT64_C(8701849857165570321),
            { AbandonedSRPNavigation::kEntryName,
                {

                    { AbandonedSRPNavigation::kAbandonReasonNameHash, AbandonedSRPNavigation::kAbandonReasonName },

                    { AbandonedSRPNavigation::kAbandonTimingFromLastMilestoneNameHash, AbandonedSRPNavigation::kAbandonTimingFromLastMilestoneName },

                    { AbandonedSRPNavigation::kAbandonTimingFromNavigationStartNameHash, AbandonedSRPNavigation::kAbandonTimingFromNavigationStartName },

                    { AbandonedSRPNavigation::kAFTEndTimeNameHash, AbandonedSRPNavigation::kAFTEndTimeName },

                    { AbandonedSRPNavigation::kAFTStartTimeNameHash, AbandonedSRPNavigation::kAFTStartTimeName },

                    { AbandonedSRPNavigation::kBodyChunkEndTimeNameHash, AbandonedSRPNavigation::kBodyChunkEndTimeName },

                    { AbandonedSRPNavigation::kBodyChunkStartTimeNameHash, AbandonedSRPNavigation::kBodyChunkStartTimeName },

                    { AbandonedSRPNavigation::kCommitReceivedTimeNameHash, AbandonedSRPNavigation::kCommitReceivedTimeName },

                    { AbandonedSRPNavigation::kCommitSentTimeNameHash, AbandonedSRPNavigation::kCommitSentTimeName },

                    { AbandonedSRPNavigation::kDidCommitTimeNameHash, AbandonedSRPNavigation::kDidCommitTimeName },

                    { AbandonedSRPNavigation::kDidRequestNonSRPNameHash, AbandonedSRPNavigation::kDidRequestNonSRPName },

                    { AbandonedSRPNavigation::kDOMContentLoadedTimeNameHash, AbandonedSRPNavigation::kDOMContentLoadedTimeName },

                    { AbandonedSRPNavigation::kFirstContentfulPaintTimeNameHash, AbandonedSRPNavigation::kFirstContentfulPaintTimeName },

                    { AbandonedSRPNavigation::kFirstRedirectedRequestStartTimeNameHash, AbandonedSRPNavigation::kFirstRedirectedRequestStartTimeName },

                    { AbandonedSRPNavigation::kFirstRedirectResponseReceivedNameHash, AbandonedSRPNavigation::kFirstRedirectResponseReceivedName },

                    { AbandonedSRPNavigation::kHeaderChunkEndTimeNameHash, AbandonedSRPNavigation::kHeaderChunkEndTimeName },

                    { AbandonedSRPNavigation::kHeaderChunkStartTimeNameHash, AbandonedSRPNavigation::kHeaderChunkStartTimeName },

                    { AbandonedSRPNavigation::kLargestContentfulPaintTimeNameHash, AbandonedSRPNavigation::kLargestContentfulPaintTimeName },

                    { AbandonedSRPNavigation::kLastMilestoneBeforeAbandonNameHash, AbandonedSRPNavigation::kLastMilestoneBeforeAbandonName },

                    { AbandonedSRPNavigation::kLoaderStartTimeNameHash, AbandonedSRPNavigation::kLoaderStartTimeName },

                    { AbandonedSRPNavigation::kLoadEventStartedTimeNameHash, AbandonedSRPNavigation::kLoadEventStartedTimeName },

                    { AbandonedSRPNavigation::kNonRedirectedRequestStartTimeNameHash, AbandonedSRPNavigation::kNonRedirectedRequestStartTimeName },

                    { AbandonedSRPNavigation::kNonRedirectResponseReceivedNameHash, AbandonedSRPNavigation::kNonRedirectResponseReceivedName },

                    { AbandonedSRPNavigation::kParseStartTimeNameHash, AbandonedSRPNavigation::kParseStartTimeName },

                    { AbandonedSRPNavigation::kPreviousBackgroundedTimeNameHash, AbandonedSRPNavigation::kPreviousBackgroundedTimeName },

                    { AbandonedSRPNavigation::kPreviousHiddenTimeNameHash, AbandonedSRPNavigation::kPreviousHiddenTimeName },

                    { AbandonedSRPNavigation::kRendererProcessInitTimeNameHash, AbandonedSRPNavigation::kRendererProcessInitTimeName },

                    { AbandonedSRPNavigation::kRTTNameHash, AbandonedSRPNavigation::kRTTName },

                } } },

        { UINT64_C(3328190265939661657),
            { AboutThisSiteStatus::kEntryName,
                {

                    { AboutThisSiteStatus::kStatusNameHash, AboutThisSiteStatus::kStatusName },

                } } },

        { UINT64_C(2140536877907621174),
            { AbusiveExperienceHeuristic_JavaScriptDialog::kEntryName,
                {

                    { AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseNameHash, AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseName },

                } } },

        { UINT64_C(14027824048938333848),
            { AbusiveExperienceHeuristic_TabUnder::kEntryName,
                {

                    { AbusiveExperienceHeuristic_TabUnder::kDidTabUnderNameHash, AbusiveExperienceHeuristic_TabUnder::kDidTabUnderName },

                } } },

        { UINT64_C(9914911288513336680),
            { AbusiveExperienceHeuristic_WindowOpen::kEntryName,
                {

                    { AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptNameHash, AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptName },

                    { AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeNameHash, AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeName },

                } } },

        { UINT64_C(14974513711212807879),
            { Accessibility_CanvasHasNonTrivialFallback::kEntryName,
                {

                    { Accessibility_CanvasHasNonTrivialFallback::kSeenNameHash, Accessibility_CanvasHasNonTrivialFallback::kSeenName },

                } } },

        { UINT64_C(17643400000419784912),
            { Accessibility_ImageDescriptions::kEntryName,
                {

                    { Accessibility_ImageDescriptions::kDescriptionNameHash, Accessibility_ImageDescriptions::kDescriptionName },

                    { Accessibility_ImageDescriptions::kImageAlreadyHasLabelNameHash, Accessibility_ImageDescriptions::kImageAlreadyHasLabelName },

                    { Accessibility_ImageDescriptions::kOCRNameHash, Accessibility_ImageDescriptions::kOCRName },

                } } },

        { UINT64_C(3697069546265840852),
            { Accessibility_InaccessiblePDFs::kEntryName,
                {

                    { Accessibility_InaccessiblePDFs::kSeenNameHash, Accessibility_InaccessiblePDFs::kSeenName },

                } } },

        { UINT64_C(7604161593172992016),
            { Accessibility_PageZoom::kEntryName,
                {

                    { Accessibility_PageZoom::kSliderZoomValueNameHash, Accessibility_PageZoom::kSliderZoomValueName },

                } } },

        { UINT64_C(1220117982628781122),
            { Accessibility_ReadAnything::kEntryName,
                {

                    { Accessibility_ReadAnything::kMergedDistillationTime_FailureNameHash, Accessibility_ReadAnything::kMergedDistillationTime_FailureName },

                    { Accessibility_ReadAnything::kMergedDistillationTime_SuccessNameHash, Accessibility_ReadAnything::kMergedDistillationTime_SuccessName },

                    { Accessibility_ReadAnything::kRulesDistillationTime_FailureNameHash, Accessibility_ReadAnything::kRulesDistillationTime_FailureName },

                    { Accessibility_ReadAnything::kRulesDistillationTime_SuccessNameHash, Accessibility_ReadAnything::kRulesDistillationTime_SuccessName },

                } } },

        { UINT64_C(9340032261281702170),
            { Accessibility_ReadAnything_EmptyState::kEntryName,
                {

                    { Accessibility_ReadAnything_EmptyState::kTotalNumSelectionsNameHash, Accessibility_ReadAnything_EmptyState::kTotalNumSelectionsName },

                } } },

        { UINT64_C(11928696798041860883),
            { Accessibility_Renderer::kEntryName,
                {

                    { Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsNameHash,
                        Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsName },

                } } },

        { UINT64_C(17956348020429077585),
            { Accessibility_ScreenAI::kEntryName,
                {

                    { Accessibility_ScreenAI::kScreen2xDistillationTime_FailureNameHash, Accessibility_ScreenAI::kScreen2xDistillationTime_FailureName },

                    { Accessibility_ScreenAI::kScreen2xDistillationTime_SuccessNameHash, Accessibility_ScreenAI::kScreen2xDistillationTime_SuccessName },

                } } },

        { UINT64_C(9171478480016060997),
            { AdFrameLoad::kEntryName,
                {

                    { AdFrameLoad::kCpuTime_PeakWindowedPercentNameHash, AdFrameLoad::kCpuTime_PeakWindowedPercentName },

                    { AdFrameLoad::kCpuTime_PreActivationNameHash, AdFrameLoad::kCpuTime_PreActivationName },

                    { AdFrameLoad::kCpuTime_TotalNameHash, AdFrameLoad::kCpuTime_TotalName },

                    { AdFrameLoad::kFrameDepthNameHash, AdFrameLoad::kFrameDepthName },

                    { AdFrameLoad::kLoading_CacheBytes2NameHash, AdFrameLoad::kLoading_CacheBytes2Name },

                    { AdFrameLoad::kLoading_ImageBytesNameHash, AdFrameLoad::kLoading_ImageBytesName },

                    { AdFrameLoad::kLoading_JavascriptBytesNameHash, AdFrameLoad::kLoading_JavascriptBytesName },

                    { AdFrameLoad::kLoading_NetworkBytesNameHash, AdFrameLoad::kLoading_NetworkBytesName },

                    { AdFrameLoad::kLoading_NumResourcesNameHash, AdFrameLoad::kLoading_NumResourcesName },

                    { AdFrameLoad::kLoading_VideoBytesNameHash, AdFrameLoad::kLoading_VideoBytesName },

                    { AdFrameLoad::kStatus_CrossOriginNameHash, AdFrameLoad::kStatus_CrossOriginName },

                    { AdFrameLoad::kStatus_MediaNameHash, AdFrameLoad::kStatus_MediaName },

                    { AdFrameLoad::kStatus_UserActivationNameHash, AdFrameLoad::kStatus_UserActivationName },

                    { AdFrameLoad::kTiming_FirstContentfulPaintNameHash, AdFrameLoad::kTiming_FirstContentfulPaintName },

                    { AdFrameLoad::kTiming_InteractiveNameHash, AdFrameLoad::kTiming_InteractiveName },

                    { AdFrameLoad::kVisibility_FrameHeightNameHash, AdFrameLoad::kVisibility_FrameHeightName },

                    { AdFrameLoad::kVisibility_FrameWidthNameHash, AdFrameLoad::kVisibility_FrameWidthName },

                    { AdFrameLoad::kVisibility_HiddenNameHash, AdFrameLoad::kVisibility_HiddenName },

                } } },

        { UINT64_C(897698866892786861),
            { AdPageLoad::kEntryName,
                {

                    { AdPageLoad::kAdBytesNameHash, AdPageLoad::kAdBytesName },

                    { AdPageLoad::kAdCpuTimeNameHash, AdPageLoad::kAdCpuTimeName },

                    { AdPageLoad::kAdJavascriptBytesNameHash, AdPageLoad::kAdJavascriptBytesName },

                    { AdPageLoad::kAdVideoBytesNameHash, AdPageLoad::kAdVideoBytesName },

                    { AdPageLoad::kMainframeAdBytesNameHash, AdPageLoad::kMainframeAdBytesName },

                    { AdPageLoad::kMaxAdDensityByAreaNameHash, AdPageLoad::kMaxAdDensityByAreaName },

                    { AdPageLoad::kMaxAdDensityByHeightNameHash, AdPageLoad::kMaxAdDensityByHeightName },

                    { AdPageLoad::kTotalBytesNameHash, AdPageLoad::kTotalBytesName },

                } } },

        { UINT64_C(8301571822483019451),
            { AdPageLoadCustomSampling3::kEntryName,
                {

                    { AdPageLoadCustomSampling3::kAverageViewportAdDensityNameHash, AdPageLoadCustomSampling3::kAverageViewportAdDensityName },

                    { AdPageLoadCustomSampling3::kKurtosisViewportAdDensityNameHash, AdPageLoadCustomSampling3::kKurtosisViewportAdDensityName },

                    { AdPageLoadCustomSampling3::kSkewnessViewportAdDensityNameHash, AdPageLoadCustomSampling3::kSkewnessViewportAdDensityName },

                    { AdPageLoadCustomSampling3::kVarianceViewportAdDensityNameHash, AdPageLoadCustomSampling3::kVarianceViewportAdDensityName },

                } } },

        { UINT64_C(4791458487205780047),
            { AdsInterestGroup_AuctionLatency_V2::kEntryName,
                {

                    { AdsInterestGroup_AuctionLatency_V2::kBidGenerationPhaseEndTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kBidGenerationPhaseEndTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kBidGenerationPhaseStartTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kBidGenerationPhaseStartTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kBidSignalsFetchPhaseEndTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kBidSignalsFetchPhaseEndTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kBidSignalsFetchPhaseStartTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kBidSignalsFetchPhaseStartTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kEndToEndLatencyInMillisNameHash, AdsInterestGroup_AuctionLatency_V2::kEndToEndLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kKAnonymityBidModeNameHash, AdsInterestGroup_AuctionLatency_V2::kKAnonymityBidModeName },

                    { AdsInterestGroup_AuctionLatency_V2::kLoadInterestGroupPhaseEndTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kLoadInterestGroupPhaseEndTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kLoadInterestGroupPhaseLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kLoadInterestGroupPhaseLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxAdditionalBidDecodeLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxAdditionalBidDecodeLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxBidForOneInterestGroupLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxBidForOneInterestGroupLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxComponentAuctionLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxComponentAuctionLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxConfigPromisesResolvedCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxConfigPromisesResolvedCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxConfigPromisesResolvedLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxConfigPromisesResolvedLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidCodeReadyLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidCodeReadyLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidConfigPromisesLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidConfigPromisesLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidDirectFromSellerSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidDirectFromSellerSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidTrustedBiddingSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxGenerateBidTrustedBiddingSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxGenerateSingleBidLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxGenerateSingleBidLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdCodeReadyLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdCodeReadyLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdDirectFromSellerSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdDirectFromSellerSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdFlowLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdFlowLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdTrustedScoringSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMaxScoreAdTrustedScoringSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanAdditionalBidDecodeLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanAdditionalBidDecodeLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanBidForOneInterestGroupLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanBidForOneInterestGroupLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanComponentAuctionLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanComponentAuctionLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanConfigPromisesResolvedCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanConfigPromisesResolvedCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanConfigPromisesResolvedLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanConfigPromisesResolvedLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidCodeReadyCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidCodeReadyCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidCodeReadyLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidCodeReadyLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidConfigPromisesCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidConfigPromisesCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidConfigPromisesLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidConfigPromisesLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidDirectFromSellerSignalsCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidDirectFromSellerSignalsCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidDirectFromSellerSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidDirectFromSellerSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidTrustedBiddingSignalsCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidTrustedBiddingSignalsCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidTrustedBiddingSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateBidTrustedBiddingSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanGenerateSingleBidLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanGenerateSingleBidLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdCodeReadyCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdCodeReadyCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdCodeReadyLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdCodeReadyLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdDirectFromSellerSignalsCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdDirectFromSellerSignalsCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdDirectFromSellerSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdDirectFromSellerSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdFlowLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdFlowLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdTrustedScoringSignalsCriticalPathLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdTrustedScoringSignalsCriticalPathLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdTrustedScoringSignalsLatencyInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanScoreAdTrustedScoringSignalsLatencyInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanTimeBidsQueuedWaitingForConfigPromisesInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanTimeBidsQueuedWaitingForConfigPromisesInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanTimeBidsQueuedWaitingForSellerWorkletInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanTimeBidsQueuedWaitingForSellerWorkletInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanTimeTopLevelBidsQueuedWaitingForConfigPromisesInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanTimeTopLevelBidsQueuedWaitingForConfigPromisesInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kMeanTimeTopLevelBidsQueuedWaitingForSellerWorkletInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kMeanTimeTopLevelBidsQueuedWaitingForSellerWorkletInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsNegativeTargetedNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsNegativeTargetedName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToBuyerNotAllowedNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToBuyerNotAllowedName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToCurrencyMismatchNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToCurrencyMismatchName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToDecodeErrorNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToDecodeErrorName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToInvalidBase64NameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToInvalidBase64Name },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToJsonParseErrorNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToJsonParseErrorName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToSignedBidDecodeErrorNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToSignedBidDecodeErrorName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToSignedBidJsonParseErrorNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsRejectedDueToSignedBidJsonParseErrorName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsSentForScoringNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAdditionalBidsSentForScoringName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumAuctionsWithConfigPromisesNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumAuctionsWithConfigPromisesName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidderWorkletsNameHash, AdsInterestGroup_AuctionLatency_V2::kNumBidderWorkletsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsAbortedByBidderWorkletFatalErrorNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsAbortedByBidderWorkletFatalErrorName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsAbortedByBuyerCumulativeTimeoutNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsAbortedByBuyerCumulativeTimeoutName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsFilteredByPerBuyerLimitsNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsFilteredByPerBuyerLimitsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsFilteredDuringInterestGroupLoadNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsFilteredDuringInterestGroupLoadName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsFilteredDuringReprioritizationNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsFilteredDuringReprioritizationName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsQueuedWaitingForConfigPromisesNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsQueuedWaitingForConfigPromisesName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumBidsQueuedWaitingForSellerWorkletNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumBidsQueuedWaitingForSellerWorkletName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumConfigPromisesNameHash, AdsInterestGroup_AuctionLatency_V2::kNumConfigPromisesName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumDistinctOwnersWithInterestGroupsNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumDistinctOwnersWithInterestGroupsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidCodeReadyOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidCodeReadyOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidConfigPromisesOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidConfigPromisesOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidDirectFromSellerSignalsOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidDirectFromSellerSignalsOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidTrustedBiddingSignalsOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumGenerateBidTrustedBiddingSignalsOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsNameHash, AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithNoBidsNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithNoBidsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithOnlyNonKAnonBidNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithOnlyNonKAnonBidName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithOtherMultiBidNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithOtherMultiBidName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithSameBidForKAnonAndNonKAnonNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithSameBidForKAnonAndNonKAnonName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithSeparateBidsForKAnonAndNonKAnonNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumInterestGroupsWithSeparateBidsForKAnonAndNonKAnonName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumNegativeInterestGroupsNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumNegativeInterestGroupsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumNegativeInterestGroupsIgnoredDueToInvalidSignatureNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumNegativeInterestGroupsIgnoredDueToInvalidSignatureName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumNegativeInterestGroupsIgnoredDueToJoiningOriginMismatchNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumNegativeInterestGroupsIgnoredDueToJoiningOriginMismatchName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumOwnersWithInterestGroupsNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumOwnersWithInterestGroupsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumOwnersWithoutInterestGroupsNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumOwnersWithoutInterestGroupsName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumScoreAdCodeReadyOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumScoreAdCodeReadyOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumScoreAdDirectFromSellerSignalsOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumScoreAdDirectFromSellerSignalsOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumScoreAdTrustedScoringSignalsOnCriticalPathNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumScoreAdTrustedScoringSignalsOnCriticalPathName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumSellersWithBiddersNameHash, AdsInterestGroup_AuctionLatency_V2::kNumSellersWithBiddersName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumTopLevelBidsQueuedWaitingForConfigPromisesNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumTopLevelBidsQueuedWaitingForConfigPromisesName },

                    { AdsInterestGroup_AuctionLatency_V2::kNumTopLevelBidsQueuedWaitingForSellerWorkletNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kNumTopLevelBidsQueuedWaitingForSellerWorkletName },

                    { AdsInterestGroup_AuctionLatency_V2::kResultNameHash, AdsInterestGroup_AuctionLatency_V2::kResultName },

                    { AdsInterestGroup_AuctionLatency_V2::kScoreSignalsFetchPhaseEndTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kScoreSignalsFetchPhaseEndTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kScoreSignalsFetchPhaseStartTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kScoreSignalsFetchPhaseStartTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kScoringPhaseEndTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kScoringPhaseEndTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kScoringPhaseStartTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kScoringPhaseStartTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kWorkletCreationPhaseEndTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kWorkletCreationPhaseEndTimeInMillisName },

                    { AdsInterestGroup_AuctionLatency_V2::kWorkletCreationPhaseStartTimeInMillisNameHash,
                        AdsInterestGroup_AuctionLatency_V2::kWorkletCreationPhaseStartTimeInMillisName },

                } } },

        { UINT64_C(2556877997165288079),
            { AdsIntervention_LastIntervention::kEntryName,
                {

                    { AdsIntervention_LastIntervention::kInterventionStatusNameHash, AdsIntervention_LastIntervention::kInterventionStatusName },

                    { AdsIntervention_LastIntervention::kInterventionTypeNameHash, AdsIntervention_LastIntervention::kInterventionTypeName },

                } } },

        { UINT64_C(15288827799554694614),
            { AmpPageLoad::kEntryName,
                {

                    { AmpPageLoad::kMainFrameAmpPageLoadNameHash, AmpPageLoad::kMainFrameAmpPageLoadName },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4NameHash, AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4Name },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_NumInteractionsNameHash, AmpPageLoad::kSubFrame_InteractiveTiming_NumInteractionsName },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2NameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2Name },

                    { AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash,
                        AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreName },

                    { AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash,
                        AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName },

                    { AmpPageLoad::kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        AmpPageLoad::kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash, AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaName },

                    { AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash,
                        AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName },

                    { AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstPaintNameHash, AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstPaintName },

                    { AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2NameHash,
                        AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2Name },

                    { AmpPageLoad::kSubFrameAmpPageLoadNameHash, AmpPageLoad::kSubFrameAmpPageLoadName },

                } } },

        { UINT64_C(16711907311792517361),
            { Android_DarkTheme_AutoDarkMode::kEntryName,
                {

                    { Android_DarkTheme_AutoDarkMode::kDisabledByUserNameHash, Android_DarkTheme_AutoDarkMode::kDisabledByUserName },

                } } },

        { UINT64_C(4355485518635673093),
            { Android_MultiWindowChangeActivity::kEntryName,
                {

                    { Android_MultiWindowChangeActivity::kActivityTypeNameHash, Android_MultiWindowChangeActivity::kActivityTypeName },

                } } },

        { UINT64_C(10096673379731574014),
            { Android_MultiWindowState::kEntryName,
                {

                    { Android_MultiWindowState::kWindowStateNameHash, Android_MultiWindowState::kWindowStateName },

                } } },

        { UINT64_C(1673574238447854674),
            { Android_NonDefaultRdsPageLoad::kEntryName,
                {

                    { Android_NonDefaultRdsPageLoad::kUserAgentTypeNameHash, Android_NonDefaultRdsPageLoad::kUserAgentTypeName },

                } } },

        { UINT64_C(8962487173277472783),
            { Android_ScreenRotation::kEntryName,
                {

                    { Android_ScreenRotation::kTargetDeviceOrientationNameHash, Android_ScreenRotation::kTargetDeviceOrientationName },

                } } },

        { UINT64_C(11570336803537235206),
            { Android_UserRequestedUserAgentChange::kEntryName,
                {

                    { Android_UserRequestedUserAgentChange::kUserAgentTypeNameHash, Android_UserRequestedUserAgentChange::kUserAgentTypeName },

                } } },

        { UINT64_C(4589718692267131532),
            { AppListAppClickData::kEntryName,
                {

                    { AppListAppClickData::kAppLaunchIdNameHash, AppListAppClickData::kAppLaunchIdName },

                    { AppListAppClickData::kAppTypeNameHash, AppListAppClickData::kAppTypeName },

                    { AppListAppClickData::kClickRankNameHash, AppListAppClickData::kClickRankName },

                    { AppListAppClickData::kClicksEachHour00NameHash, AppListAppClickData::kClicksEachHour00Name },

                    { AppListAppClickData::kClicksEachHour01NameHash, AppListAppClickData::kClicksEachHour01Name },

                    { AppListAppClickData::kClicksEachHour02NameHash, AppListAppClickData::kClicksEachHour02Name },

                    { AppListAppClickData::kClicksEachHour03NameHash, AppListAppClickData::kClicksEachHour03Name },

                    { AppListAppClickData::kClicksEachHour04NameHash, AppListAppClickData::kClicksEachHour04Name },

                    { AppListAppClickData::kClicksEachHour05NameHash, AppListAppClickData::kClicksEachHour05Name },

                    { AppListAppClickData::kClicksEachHour06NameHash, AppListAppClickData::kClicksEachHour06Name },

                    { AppListAppClickData::kClicksEachHour07NameHash, AppListAppClickData::kClicksEachHour07Name },

                    { AppListAppClickData::kClicksEachHour08NameHash, AppListAppClickData::kClicksEachHour08Name },

                    { AppListAppClickData::kClicksEachHour09NameHash, AppListAppClickData::kClicksEachHour09Name },

                    { AppListAppClickData::kClicksEachHour10NameHash, AppListAppClickData::kClicksEachHour10Name },

                    { AppListAppClickData::kClicksEachHour11NameHash, AppListAppClickData::kClicksEachHour11Name },

                    { AppListAppClickData::kClicksEachHour12NameHash, AppListAppClickData::kClicksEachHour12Name },

                    { AppListAppClickData::kClicksEachHour13NameHash, AppListAppClickData::kClicksEachHour13Name },

                    { AppListAppClickData::kClicksEachHour14NameHash, AppListAppClickData::kClicksEachHour14Name },

                    { AppListAppClickData::kClicksEachHour15NameHash, AppListAppClickData::kClicksEachHour15Name },

                    { AppListAppClickData::kClicksEachHour16NameHash, AppListAppClickData::kClicksEachHour16Name },

                    { AppListAppClickData::kClicksEachHour17NameHash, AppListAppClickData::kClicksEachHour17Name },

                    { AppListAppClickData::kClicksEachHour18NameHash, AppListAppClickData::kClicksEachHour18Name },

                    { AppListAppClickData::kClicksEachHour19NameHash, AppListAppClickData::kClicksEachHour19Name },

                    { AppListAppClickData::kClicksEachHour20NameHash, AppListAppClickData::kClicksEachHour20Name },

                    { AppListAppClickData::kClicksEachHour21NameHash, AppListAppClickData::kClicksEachHour21Name },

                    { AppListAppClickData::kClicksEachHour22NameHash, AppListAppClickData::kClicksEachHour22Name },

                    { AppListAppClickData::kClicksEachHour23NameHash, AppListAppClickData::kClicksEachHour23Name },

                    { AppListAppClickData::kClicksLast24HoursNameHash, AppListAppClickData::kClicksLast24HoursName },

                    { AppListAppClickData::kClicksLastHourNameHash, AppListAppClickData::kClicksLastHourName },

                    { AppListAppClickData::kLastLaunchedFromNameHash, AppListAppClickData::kLastLaunchedFromName },

                    { AppListAppClickData::kMostRecentlyUsedIndexNameHash, AppListAppClickData::kMostRecentlyUsedIndexName },

                    { AppListAppClickData::kSequenceNumberNameHash, AppListAppClickData::kSequenceNumberName },

                    { AppListAppClickData::kTimeSinceLastClickNameHash, AppListAppClickData::kTimeSinceLastClickName },

                    { AppListAppClickData::kTotalClicksNameHash, AppListAppClickData::kTotalClicksName },

                } } },

        { UINT64_C(16635456347627451827),
            { AppListAppLaunch::kEntryName,
                {

                    { AppListAppLaunch::kAllClicksLast24HoursNameHash, AppListAppLaunch::kAllClicksLast24HoursName },

                    { AppListAppLaunch::kAllClicksLastHourNameHash, AppListAppLaunch::kAllClicksLastHourName },

                    { AppListAppLaunch::kAppTypeNameHash, AppListAppLaunch::kAppTypeName },

                    { AppListAppLaunch::kClickMethodNameHash, AppListAppLaunch::kClickMethodName },

                    { AppListAppLaunch::kDayOfWeekNameHash, AppListAppLaunch::kDayOfWeekName },

                    { AppListAppLaunch::kDeviceModeNameHash, AppListAppLaunch::kDeviceModeName },

                    { AppListAppLaunch::kDeviceTypeNameHash, AppListAppLaunch::kDeviceTypeName },

                    { AppListAppLaunch::kHourOfDayNameHash, AppListAppLaunch::kHourOfDayName },

                    { AppListAppLaunch::kLaunchedFromNameHash, AppListAppLaunch::kLaunchedFromName },

                    { AppListAppLaunch::kPositionIndexNameHash, AppListAppLaunch::kPositionIndexName },

                    { AppListAppLaunch::kTotalHoursNameHash, AppListAppLaunch::kTotalHoursName },

                } } },

        { UINT64_C(3597047501124112026),
            { Autofill_CardUploadDecision::kEntryName,
                {

                    { Autofill_CardUploadDecision::kUploadDecisionNameHash, Autofill_CardUploadDecision::kUploadDecisionName },

                } } },

        { UINT64_C(1996892304603525762),
            { Autofill_CreditCardFill::kEntryName,
                {

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFillable_BeforeSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_QualitativeNameHash,
                        Autofill_CreditCardFill::kFillable_BeforeSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_BitmaskNameHash,
                        Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_QualitativeNameHash,
                        Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFilled_AfterSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_QualitativeNameHash, Autofill_CreditCardFill::kFilled_AfterSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_BitmaskNameHash,
                        Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_QualitativeNameHash,
                        Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFilled_BeforeSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_QualitativeNameHash, Autofill_CreditCardFill::kFilled_BeforeSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_BitmaskNameHash,
                        Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_QualitativeNameHash,
                        Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFormSignatureNameHash, Autofill_CreditCardFill::kFormSignatureName },

                    { Autofill_CreditCardFill::kSharedAutofillNameHash, Autofill_CreditCardFill::kSharedAutofillName },

                } } },

        { UINT64_C(14550063303370974566),
            { Autofill_DeveloperEngagement::kEntryName,
                {

                    { Autofill_DeveloperEngagement::kDeveloperEngagementNameHash, Autofill_DeveloperEngagement::kDeveloperEngagementName },

                    { Autofill_DeveloperEngagement::kFormSignatureNameHash, Autofill_DeveloperEngagement::kFormSignatureName },

                    { Autofill_DeveloperEngagement::kFormTypesNameHash, Autofill_DeveloperEngagement::kFormTypesName },

                    { Autofill_DeveloperEngagement::kIsForCreditCardNameHash, Autofill_DeveloperEngagement::kIsForCreditCardName },

                } } },

        { UINT64_C(15069365949047700716),
            { Autofill_EditedAutofilledFieldAtSubmission::kEntryName,
                {

                    { Autofill_EditedAutofilledFieldAtSubmission::kFieldSignatureNameHash, Autofill_EditedAutofilledFieldAtSubmission::kFieldSignatureName },

                    { Autofill_EditedAutofilledFieldAtSubmission::kFormSignatureNameHash, Autofill_EditedAutofilledFieldAtSubmission::kFormSignatureName },

                    { Autofill_EditedAutofilledFieldAtSubmission::kOverallTypeNameHash, Autofill_EditedAutofilledFieldAtSubmission::kOverallTypeName },

                } } },

        { UINT64_C(11456448948041474991),
            { Autofill_FieldFillStatus::kEntryName,
                {

                    { Autofill_FieldFillStatus::kFieldSignatureNameHash, Autofill_FieldFillStatus::kFieldSignatureName },

                    { Autofill_FieldFillStatus::kFormSignatureNameHash, Autofill_FieldFillStatus::kFormSignatureName },

                    { Autofill_FieldFillStatus::kIsAutofilledNameHash, Autofill_FieldFillStatus::kIsAutofilledName },

                    { Autofill_FieldFillStatus::kMillisecondsSinceFormParsedNameHash, Autofill_FieldFillStatus::kMillisecondsSinceFormParsedName },

                    { Autofill_FieldFillStatus::kPredictionSourceNameHash, Autofill_FieldFillStatus::kPredictionSourceName },

                    { Autofill_FieldFillStatus::kValidationEventNameHash, Autofill_FieldFillStatus::kValidationEventName },

                    { Autofill_FieldFillStatus::kWasPreviouslyAutofilledNameHash, Autofill_FieldFillStatus::kWasPreviouslyAutofilledName },

                } } },

        { UINT64_C(1290380890049589579),
            { Autofill_FieldTypeValidation::kEntryName,
                {

                    { Autofill_FieldTypeValidation::kActualTypeNameHash, Autofill_FieldTypeValidation::kActualTypeName },

                    { Autofill_FieldTypeValidation::kFieldSignatureNameHash, Autofill_FieldTypeValidation::kFieldSignatureName },

                    { Autofill_FieldTypeValidation::kFormSignatureNameHash, Autofill_FieldTypeValidation::kFormSignatureName },

                    { Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedNameHash, Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedName },

                    { Autofill_FieldTypeValidation::kPredictedTypeNameHash, Autofill_FieldTypeValidation::kPredictedTypeName },

                    { Autofill_FieldTypeValidation::kPredictionSourceNameHash, Autofill_FieldTypeValidation::kPredictionSourceName },

                    { Autofill_FieldTypeValidation::kValidationEventNameHash, Autofill_FieldTypeValidation::kValidationEventName },

                } } },

        { UINT64_C(16631655786524489525),
            { Autofill_FormEvent::kEntryName,
                {

                    { Autofill_FormEvent::kAutofillFormEventNameHash, Autofill_FormEvent::kAutofillFormEventName },

                    { Autofill_FormEvent::kFormTypesNameHash, Autofill_FormEvent::kFormTypesName },

                    { Autofill_FormEvent::kMillisecondsSinceFormParsedNameHash, Autofill_FormEvent::kMillisecondsSinceFormParsedName },

                } } },

        { UINT64_C(409508311075101037),
            { Autofill_FormFillSuccessIOS::kEntryName,
                {

                    { Autofill_FormFillSuccessIOS::kFormFillSuccessNameHash, Autofill_FormFillSuccessIOS::kFormFillSuccessName },

                } } },

        { UINT64_C(14481214823422924028),
            { Autofill_HiddenRepresentationalFieldSkipDecision::kEntryName,
                {

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeNameHash,
                        Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeName },

                } } },

        { UINT64_C(12943113565528625214),
            { Autofill_InteractedWithForm::kEntryName,
                {

                    { Autofill_InteractedWithForm::kFormSignatureNameHash, Autofill_InteractedWithForm::kFormSignatureName },

                    { Autofill_InteractedWithForm::kFormTypesNameHash, Autofill_InteractedWithForm::kFormTypesName },

                    { Autofill_InteractedWithForm::kIsForCreditCardNameHash, Autofill_InteractedWithForm::kIsForCreditCardName },

                    { Autofill_InteractedWithForm::kLocalRecordTypeCountNameHash, Autofill_InteractedWithForm::kLocalRecordTypeCountName },

                    { Autofill_InteractedWithForm::kServerRecordTypeCountNameHash, Autofill_InteractedWithForm::kServerRecordTypeCountName },

                } } },

        { UINT64_C(4026604158724844667),
            { Autofill_KeyMetrics::kEntryName,
                {

                    { Autofill_KeyMetrics::kAutofillFillsNameHash, Autofill_KeyMetrics::kAutofillFillsName },

                    { Autofill_KeyMetrics::kFastCheckoutRunIdNameHash, Autofill_KeyMetrics::kFastCheckoutRunIdName },

                    { Autofill_KeyMetrics::kFillingAcceptanceNameHash, Autofill_KeyMetrics::kFillingAcceptanceName },

                    { Autofill_KeyMetrics::kFillingAssistanceNameHash, Autofill_KeyMetrics::kFillingAssistanceName },

                    { Autofill_KeyMetrics::kFillingCorrectnessNameHash, Autofill_KeyMetrics::kFillingCorrectnessName },

                    { Autofill_KeyMetrics::kFillingReadinessNameHash, Autofill_KeyMetrics::kFillingReadinessName },

                    { Autofill_KeyMetrics::kFlowIdNameHash, Autofill_KeyMetrics::kFlowIdName },

                    { Autofill_KeyMetrics::kFormElementUserModificationsNameHash, Autofill_KeyMetrics::kFormElementUserModificationsName },

                    { Autofill_KeyMetrics::kFormTypesNameHash, Autofill_KeyMetrics::kFormTypesName },

                } } },

        { UINT64_C(17703268464688884622),
            { Autofill_SuggestionFilled::kEntryName,
                {

                    { Autofill_SuggestionFilled::kFieldSignatureNameHash, Autofill_SuggestionFilled::kFieldSignatureName },

                    { Autofill_SuggestionFilled::kFormSignatureNameHash, Autofill_SuggestionFilled::kFormSignatureName },

                    { Autofill_SuggestionFilled::kIsForCreditCardNameHash, Autofill_SuggestionFilled::kIsForCreditCardName },

                    { Autofill_SuggestionFilled::kMillisecondsSinceFormParsedNameHash, Autofill_SuggestionFilled::kMillisecondsSinceFormParsedName },

                    { Autofill_SuggestionFilled::kRecordTypeNameHash, Autofill_SuggestionFilled::kRecordTypeName },

                } } },

        { UINT64_C(7579660929739851736),
            { Autofill_SuggestionsShown::kEntryName,
                {

                    { Autofill_SuggestionsShown::kFieldSignatureNameHash, Autofill_SuggestionsShown::kFieldSignatureName },

                    { Autofill_SuggestionsShown::kFormSignatureNameHash, Autofill_SuggestionsShown::kFormSignatureName },

                    { Autofill_SuggestionsShown::kHeuristicTypeNameHash, Autofill_SuggestionsShown::kHeuristicTypeName },

                    { Autofill_SuggestionsShown::kHtmlFieldTypeNameHash, Autofill_SuggestionsShown::kHtmlFieldTypeName },

                    { Autofill_SuggestionsShown::kMillisecondsSinceFormParsedNameHash, Autofill_SuggestionsShown::kMillisecondsSinceFormParsedName },

                    { Autofill_SuggestionsShown::kServerTypeNameHash, Autofill_SuggestionsShown::kServerTypeName },

                } } },

        { UINT64_C(8376184896509210883),
            { Autofill_TextFieldDidChange::kEntryName,
                {

                    { Autofill_TextFieldDidChange::kFieldSignatureNameHash, Autofill_TextFieldDidChange::kFieldSignatureName },

                    { Autofill_TextFieldDidChange::kFieldTypeGroupNameHash, Autofill_TextFieldDidChange::kFieldTypeGroupName },

                    { Autofill_TextFieldDidChange::kFormSignatureNameHash, Autofill_TextFieldDidChange::kFormSignatureName },

                    { Autofill_TextFieldDidChange::kHeuristicTypeNameHash, Autofill_TextFieldDidChange::kHeuristicTypeName },

                    { Autofill_TextFieldDidChange::kHtmlFieldModeNameHash, Autofill_TextFieldDidChange::kHtmlFieldModeName },

                    { Autofill_TextFieldDidChange::kHtmlFieldTypeNameHash, Autofill_TextFieldDidChange::kHtmlFieldTypeName },

                    { Autofill_TextFieldDidChange::kIsAutofilledNameHash, Autofill_TextFieldDidChange::kIsAutofilledName },

                    { Autofill_TextFieldDidChange::kIsEmptyNameHash, Autofill_TextFieldDidChange::kIsEmptyName },

                    { Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedNameHash, Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedName },

                    { Autofill_TextFieldDidChange::kServerTypeNameHash, Autofill_TextFieldDidChange::kServerTypeName },

                } } },

        { UINT64_C(4418205642899146911),
            { Autofill2_AddressProfileImport::kEntryName,
                {

                    { Autofill2_AddressProfileImport::kAutocompleteUnrecognizedImportNameHash,
                        Autofill2_AddressProfileImport::kAutocompleteUnrecognizedImportName },

                    { Autofill2_AddressProfileImport::kDuplicationRankNameHash, Autofill2_AddressProfileImport::kDuplicationRankName },

                    { Autofill2_AddressProfileImport::kImportTypeNameHash, Autofill2_AddressProfileImport::kImportTypeName },

                    { Autofill2_AddressProfileImport::kNumberOfEditedFieldsNameHash, Autofill2_AddressProfileImport::kNumberOfEditedFieldsName },

                    { Autofill2_AddressProfileImport::kPhoneNumberStatusNameHash, Autofill2_AddressProfileImport::kPhoneNumberStatusName },

                    { Autofill2_AddressProfileImport::kUserDecisionNameHash, Autofill2_AddressProfileImport::kUserDecisionName },

                    { Autofill2_AddressProfileImport::kUserHasExistingProfileNameHash, Autofill2_AddressProfileImport::kUserHasExistingProfileName },

                } } },

        { UINT64_C(11766777789942094039),
            { Autofill2_FieldInfo::kEntryName,
                {

                    { Autofill2_FieldInfo::kAutocompleteStateNameHash, Autofill2_FieldInfo::kAutocompleteStateName },

                    { Autofill2_FieldInfo::kAutofillSkippedStatusNameHash, Autofill2_FieldInfo::kAutofillSkippedStatusName },

                    { Autofill2_FieldInfo::kAutofillStatusVectorNameHash, Autofill2_FieldInfo::kAutofillStatusVectorName },

                    { Autofill2_FieldInfo::kFieldLogEventCountNameHash, Autofill2_FieldInfo::kFieldLogEventCountName },

                    { Autofill2_FieldInfo::kFieldSessionIdentifierNameHash, Autofill2_FieldInfo::kFieldSessionIdentifierName },

                    { Autofill2_FieldInfo::kFieldSignatureNameHash, Autofill2_FieldInfo::kFieldSignatureName },

                    { Autofill2_FieldInfo::kFormControlType2NameHash, Autofill2_FieldInfo::kFormControlType2Name },

                    { Autofill2_FieldInfo::kFormSessionIdentifierNameHash, Autofill2_FieldInfo::kFormSessionIdentifierName },

                    { Autofill2_FieldInfo::kHeuristicTypeNameHash, Autofill2_FieldInfo::kHeuristicTypeName },

                    { Autofill2_FieldInfo::kHeuristicTypeDefaultNameHash, Autofill2_FieldInfo::kHeuristicTypeDefaultName },

                    { Autofill2_FieldInfo::kHeuristicTypeExperimentalNameHash, Autofill2_FieldInfo::kHeuristicTypeExperimentalName },

                    { Autofill2_FieldInfo::kHeuristicTypeLegacyNameHash, Autofill2_FieldInfo::kHeuristicTypeLegacyName },

                    { Autofill2_FieldInfo::kHtmlFieldModeNameHash, Autofill2_FieldInfo::kHtmlFieldModeName },

                    { Autofill2_FieldInfo::kHtmlFieldTypeNameHash, Autofill2_FieldInfo::kHtmlFieldTypeName },

                    { Autofill2_FieldInfo::kOverallTypeNameHash, Autofill2_FieldInfo::kOverallTypeName },

                    { Autofill2_FieldInfo::kRankInFieldSignatureGroupNameHash, Autofill2_FieldInfo::kRankInFieldSignatureGroupName },

                    { Autofill2_FieldInfo::kSectionIdNameHash, Autofill2_FieldInfo::kSectionIdName },

                    { Autofill2_FieldInfo::kServerPredictionSource1NameHash, Autofill2_FieldInfo::kServerPredictionSource1Name },

                    { Autofill2_FieldInfo::kServerPredictionSource2NameHash, Autofill2_FieldInfo::kServerPredictionSource2Name },

                    { Autofill2_FieldInfo::kServerType1NameHash, Autofill2_FieldInfo::kServerType1Name },

                    { Autofill2_FieldInfo::kServerType2NameHash, Autofill2_FieldInfo::kServerType2Name },

                    { Autofill2_FieldInfo::kServerTypeIsOverrideNameHash, Autofill2_FieldInfo::kServerTypeIsOverrideName },

                    { Autofill2_FieldInfo::kTypeChangedByRationalizationNameHash, Autofill2_FieldInfo::kTypeChangedByRationalizationName },

                } } },

        { UINT64_C(12003710184381511525),
            { Autofill2_FieldInfoAfterSubmission::kEntryName,
                {

                    { Autofill2_FieldInfoAfterSubmission::kFieldSessionIdentifierNameHash, Autofill2_FieldInfoAfterSubmission::kFieldSessionIdentifierName },

                    { Autofill2_FieldInfoAfterSubmission::kFormSessionIdentifierNameHash, Autofill2_FieldInfoAfterSubmission::kFormSessionIdentifierName },

                    { Autofill2_FieldInfoAfterSubmission::kMillisecondsFromFormParsedUntilSubmissionNameHash,
                        Autofill2_FieldInfoAfterSubmission::kMillisecondsFromFormParsedUntilSubmissionName },

                    { Autofill2_FieldInfoAfterSubmission::kSubmissionSourceNameHash, Autofill2_FieldInfoAfterSubmission::kSubmissionSourceName },

                    { Autofill2_FieldInfoAfterSubmission::kSubmittedType1NameHash, Autofill2_FieldInfoAfterSubmission::kSubmittedType1Name },

                    { Autofill2_FieldInfoAfterSubmission::kSubmittedType2NameHash, Autofill2_FieldInfoAfterSubmission::kSubmittedType2Name },

                    { Autofill2_FieldInfoAfterSubmission::kSubmittedType3NameHash, Autofill2_FieldInfoAfterSubmission::kSubmittedType3Name },

                } } },

        { UINT64_C(12057470962363748081),
            { Autofill2_FocusedComplexForm::kEntryName,
                {

                    { Autofill2_FocusedComplexForm::kAutofillDataQueriedNameHash, Autofill2_FocusedComplexForm::kAutofillDataQueriedName },

                    { Autofill2_FocusedComplexForm::kAutofilledNameHash, Autofill2_FocusedComplexForm::kAutofilledName },

                    { Autofill2_FocusedComplexForm::kDayInAblationWindowNameHash, Autofill2_FocusedComplexForm::kDayInAblationWindowName },

                    { Autofill2_FocusedComplexForm::kEditedAfterAutofillNameHash, Autofill2_FocusedComplexForm::kEditedAfterAutofillName },

                    { Autofill2_FocusedComplexForm::kFormSessionIdentifierNameHash, Autofill2_FocusedComplexForm::kFormSessionIdentifierName },

                    { Autofill2_FocusedComplexForm::kFormSignatureNameHash, Autofill2_FocusedComplexForm::kFormSignatureName },

                    { Autofill2_FocusedComplexForm::kFormTypesNameHash, Autofill2_FocusedComplexForm::kFormTypesName },

                    { Autofill2_FocusedComplexForm::kHadNonEmptyValueAtSubmissionNameHash, Autofill2_FocusedComplexForm::kHadNonEmptyValueAtSubmissionName },

                    { Autofill2_FocusedComplexForm::kIsAblationStudyInDryRunModeNameHash, Autofill2_FocusedComplexForm::kIsAblationStudyInDryRunModeName },

                    { Autofill2_FocusedComplexForm::kIsInAblationGroupOfAblationNameHash, Autofill2_FocusedComplexForm::kIsInAblationGroupOfAblationName },

                    { Autofill2_FocusedComplexForm::kIsInAblationGroupOfConditionalAblationNameHash,
                        Autofill2_FocusedComplexForm::kIsInAblationGroupOfConditionalAblationName },

                    { Autofill2_FocusedComplexForm::kIsInControlGroupOfAblationNameHash, Autofill2_FocusedComplexForm::kIsInControlGroupOfAblationName },

                    { Autofill2_FocusedComplexForm::kIsInControlGroupOfConditionalAblationNameHash,
                        Autofill2_FocusedComplexForm::kIsInControlGroupOfConditionalAblationName },

                    { Autofill2_FocusedComplexForm::kMillisecondsFromFirstInteractionUntilSubmissionNameHash,
                        Autofill2_FocusedComplexForm::kMillisecondsFromFirstInteractionUntilSubmissionName },

                    { Autofill2_FocusedComplexForm::kSuggestionsAvailableNameHash, Autofill2_FocusedComplexForm::kSuggestionsAvailableName },

                    { Autofill2_FocusedComplexForm::kUserModifiedNameHash, Autofill2_FocusedComplexForm::kUserModifiedName },

                    { Autofill2_FocusedComplexForm::kWasSubmittedNameHash, Autofill2_FocusedComplexForm::kWasSubmittedName },

                } } },

        { UINT64_C(8716111882571667287),
            { Autofill2_FormSummary::kEntryName,
                {

                    { Autofill2_FormSummary::kAutofillFormEventsNameHash, Autofill2_FormSummary::kAutofillFormEventsName },

                    { Autofill2_FormSummary::kAutofillFormEvents2NameHash, Autofill2_FormSummary::kAutofillFormEvents2Name },

                    { Autofill2_FormSummary::kFormSessionIdentifierNameHash, Autofill2_FormSummary::kFormSessionIdentifierName },

                    { Autofill2_FormSummary::kFormSignatureNameHash, Autofill2_FormSummary::kFormSignatureName },

                    { Autofill2_FormSummary::kMillisecondsFromFirstInteratctionUntilSubmissionNameHash,
                        Autofill2_FormSummary::kMillisecondsFromFirstInteratctionUntilSubmissionName },

                    { Autofill2_FormSummary::kMillisecondsFromFormParsedUntilSubmissionNameHash,
                        Autofill2_FormSummary::kMillisecondsFromFormParsedUntilSubmissionName },

                    { Autofill2_FormSummary::kSampleRateNameHash, Autofill2_FormSummary::kSampleRateName },

                    { Autofill2_FormSummary::kWasSubmittedNameHash, Autofill2_FormSummary::kWasSubmittedName },

                } } },

        { UINT64_C(92926512322107493),
            { Autofill2_SubmittedFormWithExperimentalFields::kEntryName,
                {

                    { Autofill2_SubmittedFormWithExperimentalFields::kFormSessionIdentifierNameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kFormSessionIdentifierName },

                    { Autofill2_SubmittedFormWithExperimentalFields::kFormSignatureNameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kFormSignatureName },

                    { Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields0NameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields0Name },

                    { Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields1NameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields1Name },

                    { Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields2NameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields2Name },

                    { Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields3NameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields3Name },

                    { Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields4NameHash,
                        Autofill2_SubmittedFormWithExperimentalFields::kNumberOfNonEmptyExperimentalFields4Name },

                } } },

        { UINT64_C(2667461721042691467),
            { BackForwardCacheDisabledForRenderFrameHostReason::kEntryName,
                {

                    { BackForwardCacheDisabledForRenderFrameHostReason::kReason2NameHash, BackForwardCacheDisabledForRenderFrameHostReason::kReason2Name },

                } } },

        { UINT64_C(17791611243479825042),
            { BackForwardCacheDisallowActivationReason::kEntryName,
                {

                    { BackForwardCacheDisallowActivationReason::kReasonNameHash, BackForwardCacheDisallowActivationReason::kReasonName },

                } } },

        { UINT64_C(15260645490069405494),
            { BackgroundFetch::kEntryName,
                {

                    { BackgroundFetch::kDeniedDueToPermissionsNameHash, BackgroundFetch::kDeniedDueToPermissionsName },

                    { BackgroundFetch::kDownloadTotalNameHash, BackgroundFetch::kDownloadTotalName },

                    { BackgroundFetch::kHasTitleNameHash, BackgroundFetch::kHasTitleName },

                    { BackgroundFetch::kNumIconsNameHash, BackgroundFetch::kNumIconsName },

                    { BackgroundFetch::kNumRequestsInFetchNameHash, BackgroundFetch::kNumRequestsInFetchName },

                    { BackgroundFetch::kRatioOfIdealToChosenIconSizeNameHash, BackgroundFetch::kRatioOfIdealToChosenIconSizeName },

                } } },

        { UINT64_C(2765600174500981245),
            { BackgroundFetchDeletingRegistration::kEntryName,
                {

                    { BackgroundFetchDeletingRegistration::kUserInitiatedAbortNameHash, BackgroundFetchDeletingRegistration::kUserInitiatedAbortName },

                } } },

        { UINT64_C(7109245137155486527),
            { BackgroundSyncCompleted::kEntryName,
                {

                    { BackgroundSyncCompleted::kMaxAttemptsNameHash, BackgroundSyncCompleted::kMaxAttemptsName },

                    { BackgroundSyncCompleted::kNumAttemptsNameHash, BackgroundSyncCompleted::kNumAttemptsName },

                    { BackgroundSyncCompleted::kStatusNameHash, BackgroundSyncCompleted::kStatusName },

                } } },

        { UINT64_C(3511425855963568724),
            { BackgroundSyncRegistered::kEntryName,
                {

                    { BackgroundSyncRegistered::kCanFireNameHash, BackgroundSyncRegistered::kCanFireName },

                    { BackgroundSyncRegistered::kIsReregisteredNameHash, BackgroundSyncRegistered::kIsReregisteredName },

                } } },

        { UINT64_C(12678664205992465342),
            { Badging::kEntryName,
                {

                    { Badging::kUpdateAppBadgeNameHash, Badging::kUpdateAppBadgeName },

                } } },

        { UINT64_C(9941089978170015081),
            { Blink_ContentManagementSystem_Versions::kEntryName,
                {

                    { Blink_ContentManagementSystem_Versions::kDrupalVersionNameHash, Blink_ContentManagementSystem_Versions::kDrupalVersionName },

                    { Blink_ContentManagementSystem_Versions::kWordPressVersionNameHash, Blink_ContentManagementSystem_Versions::kWordPressVersionName },

                } } },

        { UINT64_C(17402744508281089121),
            { Blink_DeveloperMetricsRare::kEntryName,
                {

                    { Blink_DeveloperMetricsRare::kFeatureNameHash, Blink_DeveloperMetricsRare::kFeatureName },

                    { Blink_DeveloperMetricsRare::kIsMainFrameFeatureNameHash, Blink_DeveloperMetricsRare::kIsMainFrameFeatureName },

                } } },

        { UINT64_C(6601472140741101491),
            { Blink_FedCm::kEntryName,
                {

                    { Blink_FedCm::kAccountLabel_NumMatchingAccountsNameHash, Blink_FedCm::kAccountLabel_NumMatchingAccountsName },

                    { Blink_FedCm::kAccountsDialogShownNameHash, Blink_FedCm::kAccountsDialogShownName },

                    { Blink_FedCm::kAccountsRequestSentNameHash, Blink_FedCm::kAccountsRequestSentName },

                    { Blink_FedCm::kAutoReauthn_BlockedByContentSettingsNameHash, Blink_FedCm::kAutoReauthn_BlockedByContentSettingsName },

                    { Blink_FedCm::kAutoReauthn_BlockedByEmbargoNameHash, Blink_FedCm::kAutoReauthn_BlockedByEmbargoName },

                    { Blink_FedCm::kAutoReauthn_BlockedByPreventSilentAccessNameHash, Blink_FedCm::kAutoReauthn_BlockedByPreventSilentAccessName },

                    { Blink_FedCm::kAutoReauthn_ReturningAccountsNameHash, Blink_FedCm::kAutoReauthn_ReturningAccountsName },

                    { Blink_FedCm::kAutoReauthn_SucceededNameHash, Blink_FedCm::kAutoReauthn_SucceededName },

                    { Blink_FedCm::kAutoReauthn_TimeFromEmbargoWhenBlockedNameHash, Blink_FedCm::kAutoReauthn_TimeFromEmbargoWhenBlockedName },

                    { Blink_FedCm::kDisconnect_FrameTypeNameHash, Blink_FedCm::kDisconnect_FrameTypeName },

                    { Blink_FedCm::kDomainHint_NumMatchingAccountsNameHash, Blink_FedCm::kDomainHint_NumMatchingAccountsName },

                    { Blink_FedCm::kError_ErrorDialogResultNameHash, Blink_FedCm::kError_ErrorDialogResultName },

                    { Blink_FedCm::kError_ErrorDialogTypeNameHash, Blink_FedCm::kError_ErrorDialogTypeName },

                    { Blink_FedCm::kError_TokenResponseTypeNameHash, Blink_FedCm::kError_TokenResponseTypeName },

                    { Blink_FedCm::kFedCmSessionIDNameHash, Blink_FedCm::kFedCmSessionIDName },

                    { Blink_FedCm::kLoginHint_NumMatchingAccountsNameHash, Blink_FedCm::kLoginHint_NumMatchingAccountsName },

                    { Blink_FedCm::kMismatchDialogShownNameHash, Blink_FedCm::kMismatchDialogShownName },

                    { Blink_FedCm::kMultipleRequestsRpModeNameHash, Blink_FedCm::kMultipleRequestsRpModeName },

                    { Blink_FedCm::kNumIdpsMismatchNameHash, Blink_FedCm::kNumIdpsMismatchName },

                    { Blink_FedCm::kNumIdpsRequestedNameHash, Blink_FedCm::kNumIdpsRequestedName },

                    { Blink_FedCm::kNumRequestsPerDocumentNameHash, Blink_FedCm::kNumRequestsPerDocumentName },

                    { Blink_FedCm::kPreventSilentAccessFrameTypeNameHash, Blink_FedCm::kPreventSilentAccessFrameTypeName },

                    { Blink_FedCm::kRpModeNameHash, Blink_FedCm::kRpModeName },

                    { Blink_FedCm::kStatus_DisconnectNameHash, Blink_FedCm::kStatus_DisconnectName },

                    { Blink_FedCm::kStatus_MediationRequirementNameHash, Blink_FedCm::kStatus_MediationRequirementName },

                    { Blink_FedCm::kStatus_RequestIdTokenNameHash, Blink_FedCm::kStatus_RequestIdTokenName },

                    { Blink_FedCm::kStatus_SignInStateMatchNameHash, Blink_FedCm::kStatus_SignInStateMatchName },

                    { Blink_FedCm::kTiming_AccountsDialogShownDurationNameHash, Blink_FedCm::kTiming_AccountsDialogShownDurationName },

                    { Blink_FedCm::kTiming_CancelOnDialogNameHash, Blink_FedCm::kTiming_CancelOnDialogName },

                    { Blink_FedCm::kTiming_ContinueOnDialogNameHash, Blink_FedCm::kTiming_ContinueOnDialogName },

                    { Blink_FedCm::kTiming_DisconnectNameHash, Blink_FedCm::kTiming_DisconnectName },

                    { Blink_FedCm::kTiming_GetUserInfoToButtonModeNameHash, Blink_FedCm::kTiming_GetUserInfoToButtonModeName },

                    { Blink_FedCm::kTiming_IdTokenResponseNameHash, Blink_FedCm::kTiming_IdTokenResponseName },

                    { Blink_FedCm::kTiming_MismatchDialogShownDurationNameHash, Blink_FedCm::kTiming_MismatchDialogShownDurationName },

                    { Blink_FedCm::kTiming_ShowAccountsDialogNameHash, Blink_FedCm::kTiming_ShowAccountsDialogName },

                    { Blink_FedCm::kTiming_ShowAccountsDialogBreakdown_AccountsFetchNameHash,
                        Blink_FedCm::kTiming_ShowAccountsDialogBreakdown_AccountsFetchName },

                    { Blink_FedCm::kTiming_ShowAccountsDialogBreakdown_ClientMetadataFetchNameHash,
                        Blink_FedCm::kTiming_ShowAccountsDialogBreakdown_ClientMetadataFetchName },

                    { Blink_FedCm::kTiming_ShowAccountsDialogBreakdown_WellKnownAndConfigFetchNameHash,
                        Blink_FedCm::kTiming_ShowAccountsDialogBreakdown_WellKnownAndConfigFetchName },

                    { Blink_FedCm::kTiming_TurnaroundTimeNameHash, Blink_FedCm::kTiming_TurnaroundTimeName },

                } } },

        { UINT64_C(14393930834880879921),
            { Blink_FedCmIdp::kEntryName,
                {

                    { Blink_FedCmIdp::kAccountsDialogShownNameHash, Blink_FedCmIdp::kAccountsDialogShownName },

                    { Blink_FedCmIdp::kAccountsRequestSentNameHash, Blink_FedCmIdp::kAccountsRequestSentName },

                    { Blink_FedCmIdp::kDisconnect_FrameTypeNameHash, Blink_FedCmIdp::kDisconnect_FrameTypeName },

                    { Blink_FedCmIdp::kError_ErrorDialogResultNameHash, Blink_FedCmIdp::kError_ErrorDialogResultName },

                    { Blink_FedCmIdp::kError_ErrorDialogTypeNameHash, Blink_FedCmIdp::kError_ErrorDialogTypeName },

                    { Blink_FedCmIdp::kError_ErrorUrlTypeNameHash, Blink_FedCmIdp::kError_ErrorUrlTypeName },

                    { Blink_FedCmIdp::kError_TokenResponseTypeNameHash, Blink_FedCmIdp::kError_TokenResponseTypeName },

                    { Blink_FedCmIdp::kFedCmSessionIDNameHash, Blink_FedCmIdp::kFedCmSessionIDName },

                    { Blink_FedCmIdp::kMismatchDialogShownNameHash, Blink_FedCmIdp::kMismatchDialogShownName },

                    { Blink_FedCmIdp::kMultipleRequestsRpModeNameHash, Blink_FedCmIdp::kMultipleRequestsRpModeName },

                    { Blink_FedCmIdp::kNumIdpsMismatchNameHash, Blink_FedCmIdp::kNumIdpsMismatchName },

                    { Blink_FedCmIdp::kNumIdpsRequestedNameHash, Blink_FedCmIdp::kNumIdpsRequestedName },

                    { Blink_FedCmIdp::kRpModeNameHash, Blink_FedCmIdp::kRpModeName },

                    { Blink_FedCmIdp::kStatus_DisconnectNameHash, Blink_FedCmIdp::kStatus_DisconnectName },

                    { Blink_FedCmIdp::kStatus_MediationRequirementNameHash, Blink_FedCmIdp::kStatus_MediationRequirementName },

                    { Blink_FedCmIdp::kStatus_RequestIdTokenNameHash, Blink_FedCmIdp::kStatus_RequestIdTokenName },

                    { Blink_FedCmIdp::kStatus_SignInStateMatchNameHash, Blink_FedCmIdp::kStatus_SignInStateMatchName },

                    { Blink_FedCmIdp::kTiming_AccountsDialogShownDurationNameHash, Blink_FedCmIdp::kTiming_AccountsDialogShownDurationName },

                    { Blink_FedCmIdp::kTiming_CancelOnDialogNameHash, Blink_FedCmIdp::kTiming_CancelOnDialogName },

                    { Blink_FedCmIdp::kTiming_ContinueOnDialogNameHash, Blink_FedCmIdp::kTiming_ContinueOnDialogName },

                    { Blink_FedCmIdp::kTiming_DisconnectNameHash, Blink_FedCmIdp::kTiming_DisconnectName },

                    { Blink_FedCmIdp::kTiming_IdTokenResponseNameHash, Blink_FedCmIdp::kTiming_IdTokenResponseName },

                    { Blink_FedCmIdp::kTiming_MismatchDialogShownDurationNameHash, Blink_FedCmIdp::kTiming_MismatchDialogShownDurationName },

                    { Blink_FedCmIdp::kTiming_ShowAccountsDialogNameHash, Blink_FedCmIdp::kTiming_ShowAccountsDialogName },

                    { Blink_FedCmIdp::kTiming_TurnaroundTimeNameHash, Blink_FedCmIdp::kTiming_TurnaroundTimeName },

                } } },

        { UINT64_C(14503116569381719800),
            { Blink_FindInPage::kEntryName,
                {

                    { Blink_FindInPage::kBeforematchExpandedHiddenMatchableNameHash, Blink_FindInPage::kBeforematchExpandedHiddenMatchableName },

                    { Blink_FindInPage::kDidHaveRenderSubtreeMatchNameHash, Blink_FindInPage::kDidHaveRenderSubtreeMatchName },

                    { Blink_FindInPage::kDidSearchNameHash, Blink_FindInPage::kDidSearchName },

                } } },

        { UINT64_C(16844813860515784834),
            { Blink_FrameLoader::kEntryName,
                {

                    { Blink_FrameLoader::kCommitDocumentLoaderTimeNameHash, Blink_FrameLoader::kCommitDocumentLoaderTimeName },

                } } },

        { UINT64_C(11969773594143228030),
            { Blink_HTMLParsing::kEntryName,
                {

                    { Blink_HTMLParsing::kChunkCountNameHash, Blink_HTMLParsing::kChunkCountName },

                    { Blink_HTMLParsing::kFetchQueuedPreloadsTimeNameHash, Blink_HTMLParsing::kFetchQueuedPreloadsTimeName },

                    { Blink_HTMLParsing::kParsingTimeMaxNameHash, Blink_HTMLParsing::kParsingTimeMaxName },

                    { Blink_HTMLParsing::kParsingTimeMinNameHash, Blink_HTMLParsing::kParsingTimeMinName },

                    { Blink_HTMLParsing::kParsingTimeTotalNameHash, Blink_HTMLParsing::kParsingTimeTotalName },

                    { Blink_HTMLParsing::kPreloadTimeNameHash, Blink_HTMLParsing::kPreloadTimeName },

                    { Blink_HTMLParsing::kPrepareToStopParsingTimeNameHash, Blink_HTMLParsing::kPrepareToStopParsingTimeName },

                    { Blink_HTMLParsing::kPumpTokenizerTimeNameHash, Blink_HTMLParsing::kPumpTokenizerTimeName },

                    { Blink_HTMLParsing::kScanAndPreloadTimeNameHash, Blink_HTMLParsing::kScanAndPreloadTimeName },

                    { Blink_HTMLParsing::kScanTimeNameHash, Blink_HTMLParsing::kScanTimeName },

                    { Blink_HTMLParsing::kTokensParsedAverageNameHash, Blink_HTMLParsing::kTokensParsedAverageName },

                    { Blink_HTMLParsing::kTokensParsedMaxNameHash, Blink_HTMLParsing::kTokensParsedMaxName },

                    { Blink_HTMLParsing::kTokensParsedMinNameHash, Blink_HTMLParsing::kTokensParsedMinName },

                    { Blink_HTMLParsing::kTokensParsedTotalNameHash, Blink_HTMLParsing::kTokensParsedTotalName },

                    { Blink_HTMLParsing::kYieldedTimeAverageNameHash, Blink_HTMLParsing::kYieldedTimeAverageName },

                    { Blink_HTMLParsing::kYieldedTimeMaxNameHash, Blink_HTMLParsing::kYieldedTimeMaxName },

                    { Blink_HTMLParsing::kYieldedTimeMinNameHash, Blink_HTMLParsing::kYieldedTimeMinName },

                } } },

        { UINT64_C(14434501717955674760),
            { Blink_JavaScriptFramework_Versions::kEntryName,
                {

                    { Blink_JavaScriptFramework_Versions::kAngularVersionNameHash, Blink_JavaScriptFramework_Versions::kAngularVersionName },

                    { Blink_JavaScriptFramework_Versions::kNextJSVersionNameHash, Blink_JavaScriptFramework_Versions::kNextJSVersionName },

                    { Blink_JavaScriptFramework_Versions::kNuxtVersionNameHash, Blink_JavaScriptFramework_Versions::kNuxtVersionName },

                    { Blink_JavaScriptFramework_Versions::kVueVersionNameHash, Blink_JavaScriptFramework_Versions::kVueVersionName },

                } } },

        { UINT64_C(11315426756825559974),
            { Blink_PageLoad::kEntryName,
                {

                    { Blink_PageLoad::kAccessibilityNameHash, Blink_PageLoad::kAccessibilityName },

                    { Blink_PageLoad::kAnchorElementMetricsIntersectionObserverNameHash, Blink_PageLoad::kAnchorElementMetricsIntersectionObserverName },

                    { Blink_PageLoad::kAnimateNameHash, Blink_PageLoad::kAnimateName },

                    { Blink_PageLoad::kCompositingCommitNameHash, Blink_PageLoad::kCompositingCommitName },

                    { Blink_PageLoad::kCompositingInputsNameHash, Blink_PageLoad::kCompositingInputsName },

                    { Blink_PageLoad::kContentDocumentUpdateNameHash, Blink_PageLoad::kContentDocumentUpdateName },

                    { Blink_PageLoad::kDisplayLockIntersectionObserverNameHash, Blink_PageLoad::kDisplayLockIntersectionObserverName },

                    { Blink_PageLoad::kForcedStyleAndLayoutNameHash, Blink_PageLoad::kForcedStyleAndLayoutName },

                    { Blink_PageLoad::kHandleInputEventsNameHash, Blink_PageLoad::kHandleInputEventsName },

                    { Blink_PageLoad::kHitTestDocumentUpdateNameHash, Blink_PageLoad::kHitTestDocumentUpdateName },

                    { Blink_PageLoad::kImplCompositorCommitNameHash, Blink_PageLoad::kImplCompositorCommitName },

                    { Blink_PageLoad::kIntersectionObservationNameHash, Blink_PageLoad::kIntersectionObservationName },

                    { Blink_PageLoad::kIntersectionObservationInternalCountNameHash, Blink_PageLoad::kIntersectionObservationInternalCountName },

                    { Blink_PageLoad::kIntersectionObservationJavascriptCountNameHash, Blink_PageLoad::kIntersectionObservationJavascriptCountName },

                    { Blink_PageLoad::kJavascriptDocumentUpdateNameHash, Blink_PageLoad::kJavascriptDocumentUpdateName },

                    { Blink_PageLoad::kJavascriptIntersectionObserverNameHash, Blink_PageLoad::kJavascriptIntersectionObserverName },

                    { Blink_PageLoad::kLayoutNameHash, Blink_PageLoad::kLayoutName },

                    { Blink_PageLoad::kLazyLoadIntersectionObserverNameHash, Blink_PageLoad::kLazyLoadIntersectionObserverName },

                    { Blink_PageLoad::kMainFrameNameHash, Blink_PageLoad::kMainFrameName },

                    { Blink_PageLoad::kMediaIntersectionObserverNameHash, Blink_PageLoad::kMediaIntersectionObserverName },

                    { Blink_PageLoad::kPaintNameHash, Blink_PageLoad::kPaintName },

                    { Blink_PageLoad::kParseStyleSheetNameHash, Blink_PageLoad::kParseStyleSheetName },

                    { Blink_PageLoad::kPermissionElementIntersectionObserverNameHash, Blink_PageLoad::kPermissionElementIntersectionObserverName },

                    { Blink_PageLoad::kPossibleSynchronizedScrollCount2NameHash, Blink_PageLoad::kPossibleSynchronizedScrollCount2Name },

                    { Blink_PageLoad::kPrePaintNameHash, Blink_PageLoad::kPrePaintName },

                    { Blink_PageLoad::kServiceDocumentUpdateNameHash, Blink_PageLoad::kServiceDocumentUpdateName },

                    { Blink_PageLoad::kStyleNameHash, Blink_PageLoad::kStyleName },

                    { Blink_PageLoad::kUpdateLayersNameHash, Blink_PageLoad::kUpdateLayersName },

                    { Blink_PageLoad::kUpdateViewportIntersectionNameHash, Blink_PageLoad::kUpdateViewportIntersectionName },

                    { Blink_PageLoad::kUserDrivenDocumentUpdateNameHash, Blink_PageLoad::kUserDrivenDocumentUpdateName },

                    { Blink_PageLoad::kVisualUpdateDelayNameHash, Blink_PageLoad::kVisualUpdateDelayName },

                    { Blink_PageLoad::kWaitForCommitNameHash, Blink_PageLoad::kWaitForCommitName },

                } } },

        { UINT64_C(14091970027896417477),
            { Blink_PaintTiming::kEntryName,
                {

                    { Blink_PaintTiming::kLCPDebugging_HasViewportImageNameHash, Blink_PaintTiming::kLCPDebugging_HasViewportImageName },

                } } },

        { UINT64_C(16907734789798036504),
            { Blink_Script_AsyncScripts::kEntryName,
                {

                } } },

        { UINT64_C(3664251173651435263),
            { Blink_ShapeText::kEntryName,
                {

                    { Blink_ShapeText::kMaxTimeNameHash, Blink_ShapeText::kMaxTimeName },

                    { Blink_ShapeText::kTotalTimeNameHash, Blink_ShapeText::kTotalTimeName },

                } } },

        { UINT64_C(16282696158499210158),
            { Blink_SVGImage::kEntryName,
                {

                    { Blink_SVGImage::kCountNameHash, Blink_SVGImage::kCountName },

                    { Blink_SVGImage::kTotalTimeNameHash, Blink_SVGImage::kTotalTimeName },

                } } },

        { UINT64_C(397568092790313676),
            { Blink_UpdateTime::kEntryName,
                {

                    { Blink_UpdateTime::kAccessibilityNameHash, Blink_UpdateTime::kAccessibilityName },

                    { Blink_UpdateTime::kAccessibilityBeginMainFrameNameHash, Blink_UpdateTime::kAccessibilityBeginMainFrameName },

                    { Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverNameHash, Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverName },

                    { Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverBeginMainFrameNameHash,
                        Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kAnimateNameHash, Blink_UpdateTime::kAnimateName },

                    { Blink_UpdateTime::kAnimateBeginMainFrameNameHash, Blink_UpdateTime::kAnimateBeginMainFrameName },

                    { Blink_UpdateTime::kCompositingCommitNameHash, Blink_UpdateTime::kCompositingCommitName },

                    { Blink_UpdateTime::kCompositingCommitBeginMainFrameNameHash, Blink_UpdateTime::kCompositingCommitBeginMainFrameName },

                    { Blink_UpdateTime::kCompositingInputsNameHash, Blink_UpdateTime::kCompositingInputsName },

                    { Blink_UpdateTime::kCompositingInputsBeginMainFrameNameHash, Blink_UpdateTime::kCompositingInputsBeginMainFrameName },

                    { Blink_UpdateTime::kContentDocumentUpdateNameHash, Blink_UpdateTime::kContentDocumentUpdateName },

                    { Blink_UpdateTime::kContentDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kContentDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kDisplayLockIntersectionObserverNameHash, Blink_UpdateTime::kDisplayLockIntersectionObserverName },

                    { Blink_UpdateTime::kDisplayLockIntersectionObserverBeginMainFrameNameHash,
                        Blink_UpdateTime::kDisplayLockIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kForcedStyleAndLayoutNameHash, Blink_UpdateTime::kForcedStyleAndLayoutName },

                    { Blink_UpdateTime::kForcedStyleAndLayoutBeginMainFrameNameHash, Blink_UpdateTime::kForcedStyleAndLayoutBeginMainFrameName },

                    { Blink_UpdateTime::kHandleInputEventsNameHash, Blink_UpdateTime::kHandleInputEventsName },

                    { Blink_UpdateTime::kHandleInputEventsBeginMainFrameNameHash, Blink_UpdateTime::kHandleInputEventsBeginMainFrameName },

                    { Blink_UpdateTime::kHitTestDocumentUpdateNameHash, Blink_UpdateTime::kHitTestDocumentUpdateName },

                    { Blink_UpdateTime::kHitTestDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kHitTestDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kImplCompositorCommitNameHash, Blink_UpdateTime::kImplCompositorCommitName },

                    { Blink_UpdateTime::kImplCompositorCommitBeginMainFrameNameHash, Blink_UpdateTime::kImplCompositorCommitBeginMainFrameName },

                    { Blink_UpdateTime::kIntersectionObservationNameHash, Blink_UpdateTime::kIntersectionObservationName },

                    { Blink_UpdateTime::kIntersectionObservationBeginMainFrameNameHash, Blink_UpdateTime::kIntersectionObservationBeginMainFrameName },

                    { Blink_UpdateTime::kIntersectionObservationInternalCountNameHash, Blink_UpdateTime::kIntersectionObservationInternalCountName },

                    { Blink_UpdateTime::kIntersectionObservationInternalCountBeginMainFrameNameHash,
                        Blink_UpdateTime::kIntersectionObservationInternalCountBeginMainFrameName },

                    { Blink_UpdateTime::kIntersectionObservationJavascriptCountNameHash, Blink_UpdateTime::kIntersectionObservationJavascriptCountName },

                    { Blink_UpdateTime::kIntersectionObservationJavascriptCountBeginMainFrameNameHash,
                        Blink_UpdateTime::kIntersectionObservationJavascriptCountBeginMainFrameName },

                    { Blink_UpdateTime::kJavascriptDocumentUpdateNameHash, Blink_UpdateTime::kJavascriptDocumentUpdateName },

                    { Blink_UpdateTime::kJavascriptDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kJavascriptDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kJavascriptIntersectionObserverNameHash, Blink_UpdateTime::kJavascriptIntersectionObserverName },

                    { Blink_UpdateTime::kJavascriptIntersectionObserverBeginMainFrameNameHash,
                        Blink_UpdateTime::kJavascriptIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kLayoutNameHash, Blink_UpdateTime::kLayoutName },

                    { Blink_UpdateTime::kLayoutBeginMainFrameNameHash, Blink_UpdateTime::kLayoutBeginMainFrameName },

                    { Blink_UpdateTime::kLazyLoadIntersectionObserverNameHash, Blink_UpdateTime::kLazyLoadIntersectionObserverName },

                    { Blink_UpdateTime::kLazyLoadIntersectionObserverBeginMainFrameNameHash,
                        Blink_UpdateTime::kLazyLoadIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kMainFrameNameHash, Blink_UpdateTime::kMainFrameName },

                    { Blink_UpdateTime::kMainFrameIsBeforeFCPNameHash, Blink_UpdateTime::kMainFrameIsBeforeFCPName },

                    { Blink_UpdateTime::kMainFrameReasonsNameHash, Blink_UpdateTime::kMainFrameReasonsName },

                    { Blink_UpdateTime::kMediaIntersectionObserverNameHash, Blink_UpdateTime::kMediaIntersectionObserverName },

                    { Blink_UpdateTime::kMediaIntersectionObserverBeginMainFrameNameHash, Blink_UpdateTime::kMediaIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kPaintNameHash, Blink_UpdateTime::kPaintName },

                    { Blink_UpdateTime::kPaintBeginMainFrameNameHash, Blink_UpdateTime::kPaintBeginMainFrameName },

                    { Blink_UpdateTime::kParseStyleSheetNameHash, Blink_UpdateTime::kParseStyleSheetName },

                    { Blink_UpdateTime::kParseStyleSheetBeginMainFrameNameHash, Blink_UpdateTime::kParseStyleSheetBeginMainFrameName },

                    { Blink_UpdateTime::kPermissionElementIntersectionObserverNameHash, Blink_UpdateTime::kPermissionElementIntersectionObserverName },

                    { Blink_UpdateTime::kPermissionElementIntersectionObserverBeginMainFrameNameHash,
                        Blink_UpdateTime::kPermissionElementIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kPossibleSynchronizedScrollCount2NameHash, Blink_UpdateTime::kPossibleSynchronizedScrollCount2Name },

                    { Blink_UpdateTime::kPossibleSynchronizedScrollCount2BeginMainFrameNameHash,
                        Blink_UpdateTime::kPossibleSynchronizedScrollCount2BeginMainFrameName },

                    { Blink_UpdateTime::kPrePaintNameHash, Blink_UpdateTime::kPrePaintName },

                    { Blink_UpdateTime::kPrePaintBeginMainFrameNameHash, Blink_UpdateTime::kPrePaintBeginMainFrameName },

                    { Blink_UpdateTime::kServiceDocumentUpdateNameHash, Blink_UpdateTime::kServiceDocumentUpdateName },

                    { Blink_UpdateTime::kServiceDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kServiceDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kStyleNameHash, Blink_UpdateTime::kStyleName },

                    { Blink_UpdateTime::kStyleBeginMainFrameNameHash, Blink_UpdateTime::kStyleBeginMainFrameName },

                    { Blink_UpdateTime::kStylePercentageNameHash, Blink_UpdateTime::kStylePercentageName },

                    { Blink_UpdateTime::kUpdateLayersNameHash, Blink_UpdateTime::kUpdateLayersName },

                    { Blink_UpdateTime::kUpdateLayersBeginMainFrameNameHash, Blink_UpdateTime::kUpdateLayersBeginMainFrameName },

                    { Blink_UpdateTime::kUpdateViewportIntersectionNameHash, Blink_UpdateTime::kUpdateViewportIntersectionName },

                    { Blink_UpdateTime::kUpdateViewportIntersectionBeginMainFrameNameHash, Blink_UpdateTime::kUpdateViewportIntersectionBeginMainFrameName },

                    { Blink_UpdateTime::kUserDrivenDocumentUpdateNameHash, Blink_UpdateTime::kUserDrivenDocumentUpdateName },

                    { Blink_UpdateTime::kUserDrivenDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kUserDrivenDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kVisualUpdateDelayNameHash, Blink_UpdateTime::kVisualUpdateDelayName },

                    { Blink_UpdateTime::kVisualUpdateDelayBeginMainFrameNameHash, Blink_UpdateTime::kVisualUpdateDelayBeginMainFrameName },

                    { Blink_UpdateTime::kWaitForCommitNameHash, Blink_UpdateTime::kWaitForCommitName },

                    { Blink_UpdateTime::kWaitForCommitBeginMainFrameNameHash, Blink_UpdateTime::kWaitForCommitBeginMainFrameName },

                } } },

        { UINT64_C(16486120572686381376),
            { Blink_UseCounter::kEntryName,
                {

                    { Blink_UseCounter::kFeatureNameHash, Blink_UseCounter::kFeatureName },

                    { Blink_UseCounter::kIsMainFrameFeatureNameHash, Blink_UseCounter::kIsMainFrameFeatureName },

                } } },

        { UINT64_C(5152886962488555860),
            { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kEntryName,
                {

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0NameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0Name },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0IsTrueTopTopicNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0IsTrueTopTopicName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0ModelVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0ModelVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0ShouldBeFilteredNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0ShouldBeFilteredName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0TaxonomyVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic0TaxonomyVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1NameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1Name },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1IsTrueTopTopicNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1IsTrueTopTopicName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1ModelVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1ModelVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1ShouldBeFilteredNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1ShouldBeFilteredName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1TaxonomyVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic1TaxonomyVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2NameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2Name },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2IsTrueTopTopicNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2IsTrueTopTopicName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2ModelVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2ModelVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2ShouldBeFilteredNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2ShouldBeFilteredName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2TaxonomyVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kCandidateTopic2TaxonomyVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult2::kFailureReasonNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult2::kFailureReasonName },

                } } },

        { UINT64_C(3733375777248285534),
            { BrowsingTopics_EpochTopicsCalculationResult::kEntryName,
                {

                    { BrowsingTopics_EpochTopicsCalculationResult::kModelVersionNameHash, BrowsingTopics_EpochTopicsCalculationResult::kModelVersionName },

                    { BrowsingTopics_EpochTopicsCalculationResult::kPaddedTopicsStartIndexNameHash,
                        BrowsingTopics_EpochTopicsCalculationResult::kPaddedTopicsStartIndexName },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTaxonomyVersionNameHash,
                        BrowsingTopics_EpochTopicsCalculationResult::kTaxonomyVersionName },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic0NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic0Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic1NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic1Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic2NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic2Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic3NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic3Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic4NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic4Name },

                } } },

        { UINT64_C(514082468828822420),
            { BrowsingTopics_PageLoad::kEntryName,
                {

                    { BrowsingTopics_PageLoad::kTopicsRequestingContextDomainsCountNameHash,
                        BrowsingTopics_PageLoad::kTopicsRequestingContextDomainsCountName },

                } } },

        { UINT64_C(15467140159072428874),
            { BrowsingTopics_TopicsRedirectChainDetected::kEntryName,
                {

                    { BrowsingTopics_TopicsRedirectChainDetected::kNumberOfPagesCallingTopicsNameHash,
                        BrowsingTopics_TopicsRedirectChainDetected::kNumberOfPagesCallingTopicsName },

                } } },

        { UINT64_C(17021732261447222699),
            { ChargeEventHistory::kEntryName,
                {

                    { ChargeEventHistory::kChargeEventHistoryDurationNameHash, ChargeEventHistory::kChargeEventHistoryDurationName },

                    { ChargeEventHistory::kChargeEventHistoryIndexNameHash, ChargeEventHistory::kChargeEventHistoryIndexName },

                    { ChargeEventHistory::kChargeEventHistorySizeNameHash, ChargeEventHistory::kChargeEventHistorySizeName },

                    { ChargeEventHistory::kChargeEventHistoryStartTimeNameHash, ChargeEventHistory::kChargeEventHistoryStartTimeName },

                    { ChargeEventHistory::kEventIdNameHash, ChargeEventHistory::kEventIdName },

                } } },

        { UINT64_C(1896298827856298513),
            { ChromeOS_DeviceManagement::kEntryName,
                {

                    { ChromeOS_DeviceManagement::kEnrollmentStatusNameHash, ChromeOS_DeviceManagement::kEnrollmentStatusName },

                } } },

        { UINT64_C(4043047938625792161),
            { ChromeOS_WebsiteUsageTime::kEntryName,
                {

                    { ChromeOS_WebsiteUsageTime::kDurationNameHash, ChromeOS_WebsiteUsageTime::kDurationName },

                    { ChromeOS_WebsiteUsageTime::kIsFromLastLoginNameHash, ChromeOS_WebsiteUsageTime::kIsFromLastLoginName },

                    { ChromeOS_WebsiteUsageTime::kPromotableNameHash, ChromeOS_WebsiteUsageTime::kPromotableName },

                    { ChromeOS_WebsiteUsageTime::kUserDeviceMatrixNameHash, ChromeOS_WebsiteUsageTime::kUserDeviceMatrixName },

                } } },

        { UINT64_C(16604269996013569427),
            { ChromeOSApp_InputEvent::kEntryName,
                {

                    { ChromeOSApp_InputEvent::kAppInputEventCountNameHash, ChromeOSApp_InputEvent::kAppInputEventCountName },

                    { ChromeOSApp_InputEvent::kAppInputEventSourceNameHash, ChromeOSApp_InputEvent::kAppInputEventSourceName },

                    { ChromeOSApp_InputEvent::kAppTypeNameHash, ChromeOSApp_InputEvent::kAppTypeName },

                    { ChromeOSApp_InputEvent::kUserDeviceMatrixNameHash, ChromeOSApp_InputEvent::kUserDeviceMatrixName },

                } } },

        { UINT64_C(13143522973299484729),
            { ChromeOSApp_InstalledApp::kEntryName,
                {

                    { ChromeOSApp_InstalledApp::kAppTypeNameHash, ChromeOSApp_InstalledApp::kAppTypeName },

                    { ChromeOSApp_InstalledApp::kInstallReasonNameHash, ChromeOSApp_InstalledApp::kInstallReasonName },

                    { ChromeOSApp_InstalledApp::kInstallSource2NameHash, ChromeOSApp_InstalledApp::kInstallSource2Name },

                    { ChromeOSApp_InstalledApp::kInstallTimeNameHash, ChromeOSApp_InstalledApp::kInstallTimeName },

                    { ChromeOSApp_InstalledApp::kUserDeviceMatrixNameHash, ChromeOSApp_InstalledApp::kUserDeviceMatrixName },

                } } },

        { UINT64_C(16690478234560038417),
            { ChromeOSApp_Launch::kEntryName,
                {

                    { ChromeOSApp_Launch::kAppTypeNameHash, ChromeOSApp_Launch::kAppTypeName },

                    { ChromeOSApp_Launch::kLaunchSourceNameHash, ChromeOSApp_Launch::kLaunchSourceName },

                    { ChromeOSApp_Launch::kUserDeviceMatrixNameHash, ChromeOSApp_Launch::kUserDeviceMatrixName },

                } } },

        { UINT64_C(7097858366631929652),
            { ChromeOSApp_UninstallApp::kEntryName,
                {

                    { ChromeOSApp_UninstallApp::kAppTypeNameHash, ChromeOSApp_UninstallApp::kAppTypeName },

                    { ChromeOSApp_UninstallApp::kUninstallSourceNameHash, ChromeOSApp_UninstallApp::kUninstallSourceName },

                    { ChromeOSApp_UninstallApp::kUserDeviceMatrixNameHash, ChromeOSApp_UninstallApp::kUserDeviceMatrixName },

                } } },

        { UINT64_C(2647010623881481336),
            { ChromeOSApp_UsageTime::kEntryName,
                {

                    { ChromeOSApp_UsageTime::kAppTypeNameHash, ChromeOSApp_UsageTime::kAppTypeName },

                    { ChromeOSApp_UsageTime::kDurationNameHash, ChromeOSApp_UsageTime::kDurationName },

                    { ChromeOSApp_UsageTime::kUserDeviceMatrixNameHash, ChromeOSApp_UsageTime::kUserDeviceMatrixName },

                } } },

        { UINT64_C(72420250988622518),
            { ChromeOSApp_UsageTimeReusedSourceId::kEntryName,
                {

                    { ChromeOSApp_UsageTimeReusedSourceId::kAppTypeNameHash, ChromeOSApp_UsageTimeReusedSourceId::kAppTypeName },

                    { ChromeOSApp_UsageTimeReusedSourceId::kDurationNameHash, ChromeOSApp_UsageTimeReusedSourceId::kDurationName },

                    { ChromeOSApp_UsageTimeReusedSourceId::kUserDeviceMatrixNameHash, ChromeOSApp_UsageTimeReusedSourceId::kUserDeviceMatrixName },

                } } },

        { UINT64_C(18270520290100355082),
            { ClickInput::kEntryName,
                {

                    { ClickInput::kExperimental_ClickInputBurstNameHash, ClickInput::kExperimental_ClickInputBurstName },

                } } },

        { UINT64_C(1670115342895886069),
            { ClientHints_AcceptCHFrameUsage::kEntryName,
                {

                    { ClientHints_AcceptCHFrameUsage::kTypeNameHash, ClientHints_AcceptCHFrameUsage::kTypeName },

                } } },

        { UINT64_C(6137790577840170170),
            { ClientHints_AcceptCHHeaderUsage::kEntryName,
                {

                    { ClientHints_AcceptCHHeaderUsage::kTypeNameHash, ClientHints_AcceptCHHeaderUsage::kTypeName },

                } } },

        { UINT64_C(4925937897339251251),
            { ClientHints_AcceptCHMetaUsage::kEntryName,
                {

                    { ClientHints_AcceptCHMetaUsage::kTypeNameHash, ClientHints_AcceptCHMetaUsage::kTypeName },

                } } },

        { UINT64_C(5294132008219398422),
            { ClientHints_CriticalCHHeaderUsage::kEntryName,
                {

                    { ClientHints_CriticalCHHeaderUsage::kTypeNameHash, ClientHints_CriticalCHHeaderUsage::kTypeName },

                } } },

        { UINT64_C(11815588195090653537),
            { ClientHints_DelegateCHMetaUsage::kEntryName,
                {

                    { ClientHints_DelegateCHMetaUsage::kTypeNameHash, ClientHints_DelegateCHMetaUsage::kTypeName },

                } } },

        { UINT64_C(528939567029470806),
            { ClientRenderingAPI::kEntryName,
                {

                    { ClientRenderingAPI::kCanvas_RenderingContextNameHash, ClientRenderingAPI::kCanvas_RenderingContextName },

                    { ClientRenderingAPI::kCanvas_RenderingContextDrawnToNameHash, ClientRenderingAPI::kCanvas_RenderingContextDrawnToName },

                    { ClientRenderingAPI::kGPUDeviceNameHash, ClientRenderingAPI::kGPUDeviceName },

                    { ClientRenderingAPI::kOffscreenCanvas_RenderingContextNameHash, ClientRenderingAPI::kOffscreenCanvas_RenderingContextName },

                    { ClientRenderingAPI::kOffscreenCanvas_RenderingContextDrawnToNameHash, ClientRenderingAPI::kOffscreenCanvas_RenderingContextDrawnToName },

                } } },

        { UINT64_C(12263546160415692682),
            { Companion_PageView::kEntryName,
                {

                    { Companion_PageView::kATX_ComponentPositionNameHash, Companion_PageView::kATX_ComponentPositionName },

                    { Companion_PageView::kATX_LastEventNameHash, Companion_PageView::kATX_LastEventName },

                    { Companion_PageView::kCQ_ClickPositionNameHash, Companion_PageView::kCQ_ClickPositionName },

                    { Companion_PageView::kCQ_ComponentPositionNameHash, Companion_PageView::kCQ_ComponentPositionName },

                    { Companion_PageView::kCQ_LastEventNameHash, Companion_PageView::kCQ_LastEventName },

                    { Companion_PageView::kCQ_NumEntriesAvailableNameHash, Companion_PageView::kCQ_NumEntriesAvailableName },

                    { Companion_PageView::kCQ_NumEntriesShownNameHash, Companion_PageView::kCQ_NumEntriesShownName },

                    { Companion_PageView::kOpenTriggerNameHash, Companion_PageView::kOpenTriggerName },

                    { Companion_PageView::kPageEntities_ClickPositionNameHash, Companion_PageView::kPageEntities_ClickPositionName },

                    { Companion_PageView::kPageEntities_ComponentPositionNameHash, Companion_PageView::kPageEntities_ComponentPositionName },

                    { Companion_PageView::kPageEntities_LastEventNameHash, Companion_PageView::kPageEntities_LastEventName },

                    { Companion_PageView::kPageEntities_NumEntriesAvailableNameHash, Companion_PageView::kPageEntities_NumEntriesAvailableName },

                    { Companion_PageView::kPageEntities_NumEntriesShownNameHash, Companion_PageView::kPageEntities_NumEntriesShownName },

                    { Companion_PageView::kPH_ComponentPositionNameHash, Companion_PageView::kPH_ComponentPositionName },

                    { Companion_PageView::kPH_FeedbackNameHash, Companion_PageView::kPH_FeedbackName },

                    { Companion_PageView::kPH_LastEventNameHash, Companion_PageView::kPH_LastEventName },

                    { Companion_PageView::kPHResult_ClickPositionNameHash, Companion_PageView::kPHResult_ClickPositionName },

                    { Companion_PageView::kPHResult_ComponentPositionNameHash, Companion_PageView::kPHResult_ComponentPositionName },

                    { Companion_PageView::kPHResult_LastEventNameHash, Companion_PageView::kPHResult_LastEventName },

                    { Companion_PageView::kPHResult_NumEntriesAvailableNameHash, Companion_PageView::kPHResult_NumEntriesAvailableName },

                    { Companion_PageView::kPHResult_NumEntriesShownNameHash, Companion_PageView::kPHResult_NumEntriesShownName },

                    { Companion_PageView::kPromoEventNameHash, Companion_PageView::kPromoEventName },

                    { Companion_PageView::kRegionSearch_ClickCountNameHash, Companion_PageView::kRegionSearch_ClickCountName },

                    { Companion_PageView::kRelQr_ClickPositionNameHash, Companion_PageView::kRelQr_ClickPositionName },

                    { Companion_PageView::kRelQr_ComponentPositionNameHash, Companion_PageView::kRelQr_ComponentPositionName },

                    { Companion_PageView::kRelQr_LastEventNameHash, Companion_PageView::kRelQr_LastEventName },

                    { Companion_PageView::kRelQr_NumEntriesAvailableNameHash, Companion_PageView::kRelQr_NumEntriesAvailableName },

                    { Companion_PageView::kRelQr_NumEntriesShownNameHash, Companion_PageView::kRelQr_NumEntriesShownName },

                    { Companion_PageView::kRelQs_ClickPositionNameHash, Companion_PageView::kRelQs_ClickPositionName },

                    { Companion_PageView::kRelQs_ComponentPositionNameHash, Companion_PageView::kRelQs_ComponentPositionName },

                    { Companion_PageView::kRelQs_LastEventNameHash, Companion_PageView::kRelQs_LastEventName },

                    { Companion_PageView::kRelQs_NumEntriesAvailableNameHash, Companion_PageView::kRelQs_NumEntriesAvailableName },

                    { Companion_PageView::kRelQs_NumEntriesShownNameHash, Companion_PageView::kRelQs_NumEntriesShownName },

                    { Companion_PageView::kTextSearchCountNameHash, Companion_PageView::kTextSearchCountName },

                    { Companion_PageView::kVQ_ClickPositionNameHash, Companion_PageView::kVQ_ClickPositionName },

                    { Companion_PageView::kVQ_ComponentPositionNameHash, Companion_PageView::kVQ_ComponentPositionName },

                    { Companion_PageView::kVQ_LastEventNameHash, Companion_PageView::kVQ_LastEventName },

                    { Companion_PageView::kVQ_NumEntriesAvailableNameHash, Companion_PageView::kVQ_NumEntriesAvailableName },

                    { Companion_PageView::kVQ_NumEntriesShownNameHash, Companion_PageView::kVQ_NumEntriesShownName },

                    { Companion_PageView::kVQS_ImageSensitiveCountNameHash, Companion_PageView::kVQS_ImageSensitiveCountName },

                    { Companion_PageView::kVQS_ImageShoppyCountNameHash, Companion_PageView::kVQS_ImageShoppyCountName },

                    { Companion_PageView::kVQS_ImageShoppyNotSensitiveCountNameHash, Companion_PageView::kVQS_ImageShoppyNotSensitiveCountName },

                    { Companion_PageView::kVQS_VisualEligibleImagesCountNameHash, Companion_PageView::kVQS_VisualEligibleImagesCountName },

                    { Companion_PageView::kVQS_VisualSearchTriggeredCountNameHash, Companion_PageView::kVQS_VisualSearchTriggeredCountName },

                } } },

        { UINT64_C(3985288542356389988),
            { Compose_PageEvents::kEntryName,
                {

                    { Compose_PageEvents::kComposeTextInsertedNameHash, Compose_PageEvents::kComposeTextInsertedName },

                    { Compose_PageEvents::kMenuItemClickedNameHash, Compose_PageEvents::kMenuItemClickedName },

                    { Compose_PageEvents::kMenuItemShownNameHash, Compose_PageEvents::kMenuItemShownName },

                    { Compose_PageEvents::kMissingFormDataNameHash, Compose_PageEvents::kMissingFormDataName },

                    { Compose_PageEvents::kMissingFormFieldDataNameHash, Compose_PageEvents::kMissingFormFieldDataName },

                    { Compose_PageEvents::kProactiveNudgeDisabledForSiteNameHash, Compose_PageEvents::kProactiveNudgeDisabledForSiteName },

                    { Compose_PageEvents::kProactiveNudgeDisabledGloballyNameHash, Compose_PageEvents::kProactiveNudgeDisabledGloballyName },

                    { Compose_PageEvents::kProactiveNudgeOpenedNameHash, Compose_PageEvents::kProactiveNudgeOpenedName },

                    { Compose_PageEvents::kProactiveNudgeShouldShowNameHash, Compose_PageEvents::kProactiveNudgeShouldShowName },

                    { Compose_PageEvents::kProactiveNudgeShownNameHash, Compose_PageEvents::kProactiveNudgeShownName },

                } } },

        { UINT64_C(17644213575895096611),
            { Compose_SessionProgress::kEntryName,
                {

                    { Compose_SessionProgress::kCanceledNameHash, Compose_SessionProgress::kCanceledName },

                    { Compose_SessionProgress::kCasualCountNameHash, Compose_SessionProgress::kCasualCountName },

                    { Compose_SessionProgress::kComposeCountNameHash, Compose_SessionProgress::kComposeCountName },

                    { Compose_SessionProgress::kDialogShownCountNameHash, Compose_SessionProgress::kDialogShownCountName },

                    { Compose_SessionProgress::kFormalCountNameHash, Compose_SessionProgress::kFormalCountName },

                    { Compose_SessionProgress::kInsertedResultsNameHash, Compose_SessionProgress::kInsertedResultsName },

                    { Compose_SessionProgress::kLengthenCountNameHash, Compose_SessionProgress::kLengthenCountName },

                    { Compose_SessionProgress::kRegenerateCountNameHash, Compose_SessionProgress::kRegenerateCountName },

                    { Compose_SessionProgress::kShortenCountNameHash, Compose_SessionProgress::kShortenCountName },

                    { Compose_SessionProgress::kStartedWithProactiveNudgeNameHash, Compose_SessionProgress::kStartedWithProactiveNudgeName },

                    { Compose_SessionProgress::kUndoCountNameHash, Compose_SessionProgress::kUndoCountName },

                } } },

        { UINT64_C(2872551356235666049),
            { Compose_TextElementUsage::kEntryName,
                {

                    { Compose_TextElementUsage::kAutofillFormControlTypeNameHash, Compose_TextElementUsage::kAutofillFormControlTypeName },

                    { Compose_TextElementUsage::kEditingTimeNameHash, Compose_TextElementUsage::kEditingTimeName },

                    { Compose_TextElementUsage::kFieldSignatureNameHash, Compose_TextElementUsage::kFieldSignatureName },

                    { Compose_TextElementUsage::kFormSignatureNameHash, Compose_TextElementUsage::kFormSignatureName },

                    { Compose_TextElementUsage::kIsAutofillFieldTypeNameHash, Compose_TextElementUsage::kIsAutofillFieldTypeName },

                    { Compose_TextElementUsage::kTypedCharacterCountNameHash, Compose_TextElementUsage::kTypedCharacterCountName },

                    { Compose_TextElementUsage::kTypedWordCountNameHash, Compose_TextElementUsage::kTypedWordCountName },

                } } },

        { UINT64_C(18003859069234917647),
            { Compositor_Rendering::kEntryName,
                {

                    { Compositor_Rendering::kCheckerboardedImagesCountNameHash, Compositor_Rendering::kCheckerboardedImagesCountName },

                } } },

        { UINT64_C(3378172330402895005),
            { Compositor_UserInteraction::kEntryName,
                {

                    { Compositor_UserInteraction::kCheckerboardedContentAreaNameHash, Compositor_UserInteraction::kCheckerboardedContentAreaName },

                    { Compositor_UserInteraction::kCheckerboardedContentAreaRatioNameHash, Compositor_UserInteraction::kCheckerboardedContentAreaRatioName },

                    { Compositor_UserInteraction::kCheckerboardedImagesCountNameHash, Compositor_UserInteraction::kCheckerboardedImagesCountName },

                    { Compositor_UserInteraction::kNumMissingTilesNameHash, Compositor_UserInteraction::kNumMissingTilesName },

                } } },

        { UINT64_C(11375675958515902207),
            { ContactsPicker_ShareStatistics::kEntryName,
                {

                    { ContactsPicker_ShareStatistics::kPropertiesRequestedNameHash, ContactsPicker_ShareStatistics::kPropertiesRequestedName },

                    { ContactsPicker_ShareStatistics::kSelectCountNameHash, ContactsPicker_ShareStatistics::kSelectCountName },

                    { ContactsPicker_ShareStatistics::kSelectPercentageNameHash, ContactsPicker_ShareStatistics::kSelectPercentageName },

                } } },

        { UINT64_C(7195670717417274603),
            { ContentIndex_Added::kEntryName,
                {

                    { ContentIndex_Added::kCategoryNameHash, ContentIndex_Added::kCategoryName },

                } } },

        { UINT64_C(8302809238691294596),
            { ContentIndex_DeletedByUser::kEntryName,
                {

                    { ContentIndex_DeletedByUser::kDeletedNameHash, ContentIndex_DeletedByUser::kDeletedName },

                } } },

        { UINT64_C(4039427715416584382),
            { ContentIndex_Opened::kEntryName,
                {

                    { ContentIndex_Opened::kIsOfflineNameHash, ContentIndex_Opened::kIsOfflineName },

                } } },

        { UINT64_C(1004694677685087236),
            { ContentManagementSystemPageLoad::kEntryName,
                {

                    { ContentManagementSystemPageLoad::kDrupalPageLoadNameHash, ContentManagementSystemPageLoad::kDrupalPageLoadName },

                    { ContentManagementSystemPageLoad::kJoomlaPageLoadNameHash, ContentManagementSystemPageLoad::kJoomlaPageLoadName },

                    { ContentManagementSystemPageLoad::kShopifyPageLoadNameHash, ContentManagementSystemPageLoad::kShopifyPageLoadName },

                    { ContentManagementSystemPageLoad::kSquarespacePageLoadNameHash, ContentManagementSystemPageLoad::kSquarespacePageLoadName },

                    { ContentManagementSystemPageLoad::kWixPageLoadNameHash, ContentManagementSystemPageLoad::kWixPageLoadName },

                    { ContentManagementSystemPageLoad::kWordPressPageLoadNameHash, ContentManagementSystemPageLoad::kWordPressPageLoadName },

                } } },

        { UINT64_C(1205887675013444985),
            { ContextMenuAndroid_Selected::kEntryName,
                {

                    { ContextMenuAndroid_Selected::kActionNameHash, ContextMenuAndroid_Selected::kActionName },

                } } },

        { UINT64_C(12646817710005836743),
            { ContextMenuAndroid_Shown::kEntryName,
                {

                    { ContextMenuAndroid_Shown::kSearchByImageNameHash, ContextMenuAndroid_Shown::kSearchByImageName },

                    { ContextMenuAndroid_Shown::kSearchWithGoogleLensNameHash, ContextMenuAndroid_Shown::kSearchWithGoogleLensName },

                    { ContextMenuAndroid_Shown::kShopWithGoogleLensNameHash, ContextMenuAndroid_Shown::kShopWithGoogleLensName },

                    { ContextMenuAndroid_Shown::kShopWithGoogleLensChipNameHash, ContextMenuAndroid_Shown::kShopWithGoogleLensChipName },

                    { ContextMenuAndroid_Shown::kTranslateWithGoogleLensChipNameHash, ContextMenuAndroid_Shown::kTranslateWithGoogleLensChipName },

                } } },

        { UINT64_C(17395284389490280523),
            { CookieHasNonAsciiCharacter::kEntryName,
                {

                    { CookieHasNonAsciiCharacter::kNameNameHash, CookieHasNonAsciiCharacter::kNameName },

                    { CookieHasNonAsciiCharacter::kValueNameHash, CookieHasNonAsciiCharacter::kValueName },

                } } },

        { UINT64_C(11473670249740636017),
            { Cookies_Blocked_DueToOriginMismatch::kEntryName,
                {

                    { Cookies_Blocked_DueToOriginMismatch::kPortMismatchNameHash, Cookies_Blocked_DueToOriginMismatch::kPortMismatchName },

                    { Cookies_Blocked_DueToOriginMismatch::kSchemeMismatchNameHash, Cookies_Blocked_DueToOriginMismatch::kSchemeMismatchName },

                } } },

        { UINT64_C(13189393161560362088),
            { Cookies_FirstPartyPartitionedInCrossSiteContextV3::kEntryName,
                {

                    { Cookies_FirstPartyPartitionedInCrossSiteContextV3::kCookiePresentNameHash,
                        Cookies_FirstPartyPartitionedInCrossSiteContextV3::kCookiePresentName },

                } } },

        { UINT64_C(988984496812825435),
            { CPUUsageMeasurement::kEntryName,
                {

                    { CPUUsageMeasurement::kCPUUsageNameHash, CPUUsageMeasurement::kCPUUsageName },

                    { CPUUsageMeasurement::kEventTypeNameHash, CPUUsageMeasurement::kEventTypeName },

                    { CPUUsageMeasurement::kIsVisibleNameHash, CPUUsageMeasurement::kIsVisibleName },

                    { CPUUsageMeasurement::kNumberOfCoresidentTabsNameHash, CPUUsageMeasurement::kNumberOfCoresidentTabsName },

                    { CPUUsageMeasurement::kObservationWindowSizeMsNameHash, CPUUsageMeasurement::kObservationWindowSizeMsName },

                    { CPUUsageMeasurement::kProcessUptimeMsNameHash, CPUUsageMeasurement::kProcessUptimeMsName },

                } } },

        { UINT64_C(15054308220608486353),
            { CrossOriginSubframeWithoutEmbeddingControl::kEntryName,
                {

                    { CrossOriginSubframeWithoutEmbeddingControl::kSubframeEmbeddedNameHash,
                        CrossOriginSubframeWithoutEmbeddingControl::kSubframeEmbeddedName },

                } } },

        { UINT64_C(16118191348399710349),
            { DailyChargeSummary::kEntryName,
                {

                    { DailyChargeSummary::kDailySummaryHoldTimeOnAcNameHash, DailyChargeSummary::kDailySummaryHoldTimeOnAcName },

                    { DailyChargeSummary::kDailySummaryIndexNameHash, DailyChargeSummary::kDailySummaryIndexName },

                    { DailyChargeSummary::kDailySummaryNumDaysDistanceNameHash, DailyChargeSummary::kDailySummaryNumDaysDistanceName },

                    { DailyChargeSummary::kDailySummarySizeNameHash, DailyChargeSummary::kDailySummarySizeName },

                    { DailyChargeSummary::kDailySummaryTimeFullOnAcNameHash, DailyChargeSummary::kDailySummaryTimeFullOnAcName },

                    { DailyChargeSummary::kDailySummaryTimeOnAcNameHash, DailyChargeSummary::kDailySummaryTimeOnAcName },

                    { DailyChargeSummary::kEventIdNameHash, DailyChargeSummary::kEventIdName },

                } } },

        { UINT64_C(26394013458683718),
            { DataReductionProxy::kEntryName,
                {

                    { DataReductionProxy::kDataSaverPageUUIDNameHash, DataReductionProxy::kDataSaverPageUUIDName },

                    { DataReductionProxy::kEstimatedOriginalNetworkBytesNameHash, DataReductionProxy::kEstimatedOriginalNetworkBytesName },

                } } },

        { UINT64_C(5460112050811125825),
            { DevTools_Opened::kEntryName,
                {

                    { DevTools_Opened::kHasOccurredNameHash, DevTools_Opened::kHasOccurredName },

                } } },

        { UINT64_C(5320991773281187745),
            { DIPS_ChainBegin::kEntryName,
                {

                    { DIPS_ChainBegin::kChainIdNameHash, DIPS_ChainBegin::kChainIdName },

                    { DIPS_ChainBegin::kInitialAndFinalSitesSameNameHash, DIPS_ChainBegin::kInitialAndFinalSitesSameName },

                } } },

        { UINT64_C(6946092153020974851),
            { DIPS_ChainEnd::kEntryName,
                {

                    { DIPS_ChainEnd::kChainIdNameHash, DIPS_ChainEnd::kChainIdName },

                    { DIPS_ChainEnd::kInitialAndFinalSitesSameNameHash, DIPS_ChainEnd::kInitialAndFinalSitesSameName },

                } } },

        { UINT64_C(3655510906906408205),
            { DIPS_Deletion::kEntryName,
                {

                    { DIPS_Deletion::kHasCookieExceptionNameHash, DIPS_Deletion::kHasCookieExceptionName },

                    { DIPS_Deletion::kIsDeletionEnabledNameHash, DIPS_Deletion::kIsDeletionEnabledName },

                    { DIPS_Deletion::kShouldBlockThirdPartyCookiesNameHash, DIPS_Deletion::kShouldBlockThirdPartyCookiesName },

                } } },

        { UINT64_C(481245041017727098),
            { DIPS_NavigationFlowNode::kEntryName,
                {

                    { DIPS_NavigationFlowNode::kDidHaveSuccessfulWAANameHash, DIPS_NavigationFlowNode::kDidHaveSuccessfulWAAName },

                    { DIPS_NavigationFlowNode::kDidHaveUserActivationNameHash, DIPS_NavigationFlowNode::kDidHaveUserActivationName },

                    { DIPS_NavigationFlowNode::kVisitDurationMillisecondsNameHash, DIPS_NavigationFlowNode::kVisitDurationMillisecondsName },

                    { DIPS_NavigationFlowNode::kWasEntryUserInitiatedNameHash, DIPS_NavigationFlowNode::kWasEntryUserInitiatedName },

                    { DIPS_NavigationFlowNode::kWasExitUserInitiatedNameHash, DIPS_NavigationFlowNode::kWasExitUserInitiatedName },

                    { DIPS_NavigationFlowNode::kWereEntryAndExitRendererInitiatedNameHash, DIPS_NavigationFlowNode::kWereEntryAndExitRendererInitiatedName },

                    { DIPS_NavigationFlowNode::kWerePreviousAndNextSiteSameNameHash, DIPS_NavigationFlowNode::kWerePreviousAndNextSiteSameName },

                } } },

        { UINT64_C(15719730292389568123),
            { DIPS_Redirect::kEntryName,
                {

                    { DIPS_Redirect::kChainIdNameHash, DIPS_Redirect::kChainIdName },

                    { DIPS_Redirect::kClientBounceDelayNameHash, DIPS_Redirect::kClientBounceDelayName },

                    { DIPS_Redirect::kCookieAccessTypeNameHash, DIPS_Redirect::kCookieAccessTypeName },

                    { DIPS_Redirect::kHasStickyActivationNameHash, DIPS_Redirect::kHasStickyActivationName },

                    { DIPS_Redirect::kInitialAndFinalSitesSameNameHash, DIPS_Redirect::kInitialAndFinalSitesSameName },

                    { DIPS_Redirect::kIsPartialRedirectChainNameHash, DIPS_Redirect::kIsPartialRedirectChainName },

                    { DIPS_Redirect::kRedirectAndFinalSiteSameNameHash, DIPS_Redirect::kRedirectAndFinalSiteSameName },

                    { DIPS_Redirect::kRedirectAndInitialSiteSameNameHash, DIPS_Redirect::kRedirectAndInitialSiteSameName },

                    { DIPS_Redirect::kRedirectChainIndexNameHash, DIPS_Redirect::kRedirectChainIndexName },

                    { DIPS_Redirect::kRedirectChainLengthNameHash, DIPS_Redirect::kRedirectChainLengthName },

                    { DIPS_Redirect::kRedirectTypeNameHash, DIPS_Redirect::kRedirectTypeName },

                    { DIPS_Redirect::kSiteEngagementLevelNameHash, DIPS_Redirect::kSiteEngagementLevelName },

                    { DIPS_Redirect::kWebAuthnAssertionRequestSucceededNameHash, DIPS_Redirect::kWebAuthnAssertionRequestSucceededName },

                } } },

        { UINT64_C(16212732140902898765),
            { DIPS_SuspectedTrackerFlowEntrypoint::kEntryName,
                {

                    { DIPS_SuspectedTrackerFlowEntrypoint::kExitRedirectTypeNameHash, DIPS_SuspectedTrackerFlowEntrypoint::kExitRedirectTypeName },

                    { DIPS_SuspectedTrackerFlowEntrypoint::kFlowIdNameHash, DIPS_SuspectedTrackerFlowEntrypoint::kFlowIdName },

                } } },

        { UINT64_C(6139758594329744253),
            { DIPS_SuspectedTrackerFlowReferrer::kEntryName,
                {

                    { DIPS_SuspectedTrackerFlowReferrer::kFlowIdNameHash, DIPS_SuspectedTrackerFlowReferrer::kFlowIdName },

                } } },

        { UINT64_C(4781193942405335441),
            { DIPS_TriggeringAction::kEntryName,
                {

                    { DIPS_TriggeringAction::kDidBounceNameHash, DIPS_TriggeringAction::kDidBounceName },

                    { DIPS_TriggeringAction::kDidStatefulBounceNameHash, DIPS_TriggeringAction::kDidStatefulBounceName },

                    { DIPS_TriggeringAction::kUsedStorageNameHash, DIPS_TriggeringAction::kUsedStorageName },

                } } },

        { UINT64_C(3444815615783303259),
            { DIPS_TrustIndicator_InFlowInteraction::kEntryName,
                {

                    { DIPS_TrustIndicator_InFlowInteraction::kFlowIdNameHash, DIPS_TrustIndicator_InFlowInteraction::kFlowIdName },

                } } },

        { UINT64_C(2704655726834470033),
            { DocumentCreated::kEntryName,
                {

                    { DocumentCreated::kIsCrossOriginFrameNameHash, DocumentCreated::kIsCrossOriginFrameName },

                    { DocumentCreated::kIsCrossSiteFrameNameHash, DocumentCreated::kIsCrossSiteFrameName },

                    { DocumentCreated::kIsMainFrameNameHash, DocumentCreated::kIsMainFrameName },

                    { DocumentCreated::kNavigationSourceIdNameHash, DocumentCreated::kNavigationSourceIdName },

                } } },

        { UINT64_C(9818692869640581957),
            { Download_Completed::kEntryName,
                {

                    { Download_Completed::kBytesWastedNameHash, Download_Completed::kBytesWastedName },

                    { Download_Completed::kDownloadIdNameHash, Download_Completed::kDownloadIdName },

                    { Download_Completed::kResultingFileSizeNameHash, Download_Completed::kResultingFileSizeName },

                    { Download_Completed::kTimeSinceStartNameHash, Download_Completed::kTimeSinceStartName },

                } } },

        { UINT64_C(9706055097174303),
            { Download_Interrupted::kEntryName,
                {

                    { Download_Interrupted::kBytesWastedNameHash, Download_Interrupted::kBytesWastedName },

                    { Download_Interrupted::kChangeInFileSizeNameHash, Download_Interrupted::kChangeInFileSizeName },

                    { Download_Interrupted::kDownloadIdNameHash, Download_Interrupted::kDownloadIdName },

                    { Download_Interrupted::kReasonNameHash, Download_Interrupted::kReasonName },

                    { Download_Interrupted::kResultingFileSizeNameHash, Download_Interrupted::kResultingFileSizeName },

                    { Download_Interrupted::kTimeSinceStartNameHash, Download_Interrupted::kTimeSinceStartName },

                } } },

        { UINT64_C(9188207819461355990),
            { Download_Resumed::kEntryName,
                {

                    { Download_Resumed::kDownloadIdNameHash, Download_Resumed::kDownloadIdName },

                    { Download_Resumed::kModeNameHash, Download_Resumed::kModeName },

                    { Download_Resumed::kTimeSinceStartNameHash, Download_Resumed::kTimeSinceStartName },

                } } },

        { UINT64_C(2153997617158303225),
            { Download_Started::kEntryName,
                {

                    { Download_Started::kDownloadConnectionSecurityNameHash, Download_Started::kDownloadConnectionSecurityName },

                    { Download_Started::kDownloadIdNameHash, Download_Started::kDownloadIdName },

                    { Download_Started::kDownloadSourceNameHash, Download_Started::kDownloadSourceName },

                    { Download_Started::kFileTypeNameHash, Download_Started::kFileTypeName },

                    { Download_Started::kIsSameHostDownloadNameHash, Download_Started::kIsSameHostDownloadName },

                } } },

        { UINT64_C(15972247533344456664),
            { Enterprise_Profile_Enrollment::kEntryName,
                {

                    { Enterprise_Profile_Enrollment::kIsUntrustedOidcRedirectNameHash, Enterprise_Profile_Enrollment::kIsUntrustedOidcRedirectName },

                } } },

        { UINT64_C(6161051744273924039),
            { Event_Scroll::kEntryName,
                {

                    { Event_Scroll::kFrameCountNameHash, Event_Scroll::kFrameCountName },

                    { Event_Scroll::kPredictorJankyFrameCountNameHash, Event_Scroll::kPredictorJankyFrameCountName },

                    { Event_Scroll::kScrollJank_DelayedFrameCountNameHash, Event_Scroll::kScrollJank_DelayedFrameCountName },

                    { Event_Scroll::kScrollJank_MissedVsyncsMaxNameHash, Event_Scroll::kScrollJank_MissedVsyncsMaxName },

                    { Event_Scroll::kScrollJank_MissedVsyncsSumNameHash, Event_Scroll::kScrollJank_MissedVsyncsSumName },

                    { Event_Scroll::kVsyncCountNameHash, Event_Scroll::kVsyncCountName },

                } } },

        { UINT64_C(12205595443714861014),
            { Event_ScrollJank_PredictorJank::kEntryName,
                {

                    { Event_ScrollJank_PredictorJank::kMaxDeltaNameHash, Event_ScrollJank_PredictorJank::kMaxDeltaName },

                    { Event_ScrollJank_PredictorJank::kScrollUpdate_MissedVsync_FrameAboveJankyThreshold2NameHash,
                        Event_ScrollJank_PredictorJank::kScrollUpdate_MissedVsync_FrameAboveJankyThreshold2Name },

                    { Event_ScrollJank_PredictorJank::kScrollUpdate_NoMissedVsync_FrameAboveJankyThreshold2NameHash,
                        Event_ScrollJank_PredictorJank::kScrollUpdate_NoMissedVsync_FrameAboveJankyThreshold2Name },

                } } },

        { UINT64_C(1380853390098998336),
            { Extensions_BackgroundContentsCreated::kEntryName,
                {

                    { Extensions_BackgroundContentsCreated::kSeenNameHash, Extensions_BackgroundContentsCreated::kSeenName },

                } } },

        { UINT64_C(6634692008901530734),
            { Extensions_MV2ExtensionHandledInSoftDisable::kEntryName,
                {

                    { Extensions_MV2ExtensionHandledInSoftDisable::kActionNameHash, Extensions_MV2ExtensionHandledInSoftDisable::kActionName },

                } } },

        { UINT64_C(12489573627374524023),
            { Extensions_OnNavigation::kEntryName,
                {

                    { Extensions_OnNavigation::kDeclarativeNetRequestFeedbackPermissionCountNameHash,
                        Extensions_OnNavigation::kDeclarativeNetRequestFeedbackPermissionCountName },

                    { Extensions_OnNavigation::kDeclarativeNetRequestPermissionCountNameHash,
                        Extensions_OnNavigation::kDeclarativeNetRequestPermissionCountName },

                    { Extensions_OnNavigation::kDeclarativeNetRequestWithHostAccessPermissionCountNameHash,
                        Extensions_OnNavigation::kDeclarativeNetRequestWithHostAccessPermissionCountName },

                    { Extensions_OnNavigation::kDeclarativeWebRequestPermissionCountNameHash,
                        Extensions_OnNavigation::kDeclarativeWebRequestPermissionCountName },

                    { Extensions_OnNavigation::kEnabledExtensionCountNameHash, Extensions_OnNavigation::kEnabledExtensionCountName },

                    { Extensions_OnNavigation::kEnabledExtensionCount_HaveHostPermissionsNameHash,
                        Extensions_OnNavigation::kEnabledExtensionCount_HaveHostPermissionsName },

                    { Extensions_OnNavigation::kEnabledExtensionCount_InjectContentScriptNameHash,
                        Extensions_OnNavigation::kEnabledExtensionCount_InjectContentScriptName },

                    { Extensions_OnNavigation::kWebRequestAuthProviderPermissionCountNameHash,
                        Extensions_OnNavigation::kWebRequestAuthProviderPermissionCountName },

                    { Extensions_OnNavigation::kWebRequestBlockingPermissionCountNameHash, Extensions_OnNavigation::kWebRequestBlockingPermissionCountName },

                    { Extensions_OnNavigation::kWebRequestPermissionCountNameHash, Extensions_OnNavigation::kWebRequestPermissionCountName },

                } } },

        { UINT64_C(12524558333720971544),
            { Extensions_WebRequest_KeepaliveRequestFinished::kEntryName,
                {

                    { Extensions_WebRequest_KeepaliveRequestFinished::kNumRedirectsNameHash,
                        Extensions_WebRequest_KeepaliveRequestFinished::kNumRedirectsName },

                    { Extensions_WebRequest_KeepaliveRequestFinished::kStateNameHash, Extensions_WebRequest_KeepaliveRequestFinished::kStateName },

                } } },

        { UINT64_C(5216195086138498635),
            { FacilitatedPayments_Pix_FopSelectorResult::kEntryName,
                {

                    { FacilitatedPayments_Pix_FopSelectorResult::kResultNameHash, FacilitatedPayments_Pix_FopSelectorResult::kResultName },

                } } },

        { UINT64_C(3965223974824938409),
            { FacilitatedPayments_Pix_FopSelectorShown::kEntryName,
                {

                    { FacilitatedPayments_Pix_FopSelectorShown::kShownNameHash, FacilitatedPayments_Pix_FopSelectorShown::kShownName },

                } } },

        { UINT64_C(9103820397241485062),
            { FacilitatedPayments_Pix_InitiatePurchaseActionResult::kEntryName,
                {

                    { FacilitatedPayments_Pix_InitiatePurchaseActionResult::kResultNameHash,
                        FacilitatedPayments_Pix_InitiatePurchaseActionResult::kResultName },

                } } },

        { UINT64_C(14293647879030784692),
            { FacilitatedPayments_Pix_Transaction::kEntryName,
                {

                    { FacilitatedPayments_Pix_Transaction::kResultNameHash, FacilitatedPayments_Pix_Transaction::kResultName },

                    { FacilitatedPayments_Pix_Transaction::kTriggerSourceNameHash, FacilitatedPayments_Pix_Transaction::kTriggerSourceName },

                } } },

        { UINT64_C(7998347817029737838),
            { FacilitatedPayments_PixCodeCopied::kEntryName,
                {

                    { FacilitatedPayments_PixCodeCopied::kPixCodeCopiedNameHash, FacilitatedPayments_PixCodeCopied::kPixCodeCopiedName },

                } } },

        { UINT64_C(8091520906834343236),
            { FacilitatedPayments_PixCodeDetectionResult::kEntryName,
                {

                    { FacilitatedPayments_PixCodeDetectionResult::kAttemptsNameHash, FacilitatedPayments_PixCodeDetectionResult::kAttemptsName },

                    { FacilitatedPayments_PixCodeDetectionResult::kDetectionTriggeredOnDomContentLoadedNameHash,
                        FacilitatedPayments_PixCodeDetectionResult::kDetectionTriggeredOnDomContentLoadedName },

                    { FacilitatedPayments_PixCodeDetectionResult::kLatencyInMillisNameHash, FacilitatedPayments_PixCodeDetectionResult::kLatencyInMillisName },

                    { FacilitatedPayments_PixCodeDetectionResult::kResultNameHash, FacilitatedPayments_PixCodeDetectionResult::kResultName },

                } } },

        { UINT64_C(4648922300412212646),
            { FamilyLinkUser_BlockedContent::kEntryName,
                {

                    { FamilyLinkUser_BlockedContent::kMainFrameBlockedNameHash, FamilyLinkUser_BlockedContent::kMainFrameBlockedName },

                    { FamilyLinkUser_BlockedContent::kNumBlockedIframesNameHash, FamilyLinkUser_BlockedContent::kNumBlockedIframesName },

                } } },

        { UINT64_C(13643919678711340190),
            { FamilyLinkUser_ReauthenticationInterstitial::kEntryName,
                {

                    { FamilyLinkUser_ReauthenticationInterstitial::kInterstitialShownNameHash,
                        FamilyLinkUser_ReauthenticationInterstitial::kInterstitialShownName },

                    { FamilyLinkUser_ReauthenticationInterstitial::kReauthenticationCompletedNameHash,
                        FamilyLinkUser_ReauthenticationInterstitial::kReauthenticationCompletedName },

                    { FamilyLinkUser_ReauthenticationInterstitial::kReauthenticationStartedNameHash,
                        FamilyLinkUser_ReauthenticationInterstitial::kReauthenticationStartedName },

                } } },

        { UINT64_C(15212087424653185268),
            { FastCheckout_FormStatus::kEntryName,
                {

                    { FastCheckout_FormStatus::kFilledNameHash, FastCheckout_FormStatus::kFilledName },

                    { FastCheckout_FormStatus::kFormSignatureNameHash, FastCheckout_FormStatus::kFormSignatureName },

                    { FastCheckout_FormStatus::kFormTypesNameHash, FastCheckout_FormStatus::kFormTypesName },

                    { FastCheckout_FormStatus::kRunIdNameHash, FastCheckout_FormStatus::kRunIdName },

                } } },

        { UINT64_C(11852097459181603485),
            { FastCheckout_RunOutcome::kEntryName,
                {

                    { FastCheckout_RunOutcome::kRunIdNameHash, FastCheckout_RunOutcome::kRunIdName },

                    { FastCheckout_RunOutcome::kRunOutcomeNameHash, FastCheckout_RunOutcome::kRunOutcomeName },

                } } },

        { UINT64_C(14939729010542726247),
            { Feedback_HappinessTrackingSurvey::kEntryName,
                {

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion1NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion1Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion2NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion2Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion3NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion3Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion4NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion4Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion5NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion5Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion6NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion6Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion7NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion7Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion8NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion8Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion9NameHash, Feedback_HappinessTrackingSurvey::kSurveyAnswerToQuestion9Name },

                    { Feedback_HappinessTrackingSurvey::kSurveyCompletedNameHash, Feedback_HappinessTrackingSurvey::kSurveyCompletedName },

                    { Feedback_HappinessTrackingSurvey::kSurveyIdNameHash, Feedback_HappinessTrackingSurvey::kSurveyIdName },

                    { Feedback_HappinessTrackingSurvey::kSurveyLoadedNameHash, Feedback_HappinessTrackingSurvey::kSurveyLoadedName },

                } } },

        { UINT64_C(15744625327213391071),
            { FileSystemAPI_WebRequest::kEntryName,
                {

                    { FileSystemAPI_WebRequest::kPersistentNameHash, FileSystemAPI_WebRequest::kPersistentName },

                    { FileSystemAPI_WebRequest::kTemporaryNameHash, FileSystemAPI_WebRequest::kTemporaryName },

                } } },

        { UINT64_C(17273599278651584311),
            { FingerprintingProtection::kEntryName,
                {

                    { FingerprintingProtection::kActivationDecisionNameHash, FingerprintingProtection::kActivationDecisionName },

                    { FingerprintingProtection::kAllowlistSourceNameHash, FingerprintingProtection::kAllowlistSourceName },

                    { FingerprintingProtection::kDryRunNameHash, FingerprintingProtection::kDryRunName },

                } } },

        { UINT64_C(6486198570534837725),
            { FingerprintingProtectionUsage::kEntryName,
                {

                    { FingerprintingProtectionUsage::kRefreshCountNameHash, FingerprintingProtectionUsage::kRefreshCountName },

                    { FingerprintingProtectionUsage::kSiteEngagementLevelNameHash, FingerprintingProtectionUsage::kSiteEngagementLevelName },

                } } },

        { UINT64_C(6247082832829199138),
            { FlocPageLoad::kEntryName,
                {

                    { FlocPageLoad::kFlocIdNameHash, FlocPageLoad::kFlocIdName },

                } } },

        { UINT64_C(17828670494812061854),
            { Fullscreen_Enter::kEntryName,
                {

                    { Fullscreen_Enter::kLockStateNameHash, Fullscreen_Enter::kLockStateName },

                } } },

        { UINT64_C(5280816973080484130),
            { Fullscreen_Exit::kEntryName,
                {

                    { Fullscreen_Exit::kSessionDurationNameHash, Fullscreen_Exit::kSessionDurationName },

                } } },

        { UINT64_C(14044001428377426573),
            { GameControls_ButtonOptionsMenuFunctionTriggered::kEntryName,
                {

                    { GameControls_ButtonOptionsMenuFunctionTriggered::kFunctionNameHash, GameControls_ButtonOptionsMenuFunctionTriggered::kFunctionName },

                } } },

        { UINT64_C(10110804741753680625),
            { GameControls_EditDeleteMenuFuctionTriggered::kEntryName,
                {

                    { GameControls_EditDeleteMenuFuctionTriggered::kFunctionNameHash, GameControls_EditDeleteMenuFuctionTriggered::kFunctionName },

                } } },

        { UINT64_C(6583827052843377008),
            { GameControls_EditingListFunctionTriggered::kEntryName,
                {

                    { GameControls_EditingListFunctionTriggered::kFunctionNameHash, GameControls_EditingListFunctionTriggered::kFunctionName },

                } } },

        { UINT64_C(16087115784313917227),
            { GameControls_ToggleWithMappingSource::kEntryName,
                {

                    { GameControls_ToggleWithMappingSource::kFunctionNameHash, GameControls_ToggleWithMappingSource::kFunctionName },

                    { GameControls_ToggleWithMappingSource::kMappingSourceNameHash, GameControls_ToggleWithMappingSource::kMappingSourceName },

                    { GameControls_ToggleWithMappingSource::kToggleOnNameHash, GameControls_ToggleWithMappingSource::kToggleOnName },

                } } },

        { UINT64_C(4583363670557255957),
            { GameDashboard_ControlsFeatureToggleState::kEntryName,
                {

                    { GameDashboard_ControlsFeatureToggleState::kToggleOnNameHash, GameDashboard_ControlsFeatureToggleState::kToggleOnName },

                } } },

        { UINT64_C(17634705623839060115),
            { GameDashboard_ControlsHintToggleSource::kEntryName,
                {

                    { GameDashboard_ControlsHintToggleSource::kSourceNameHash, GameDashboard_ControlsHintToggleSource::kSourceName },

                    { GameDashboard_ControlsHintToggleSource::kToggleOnNameHash, GameDashboard_ControlsHintToggleSource::kToggleOnName },

                } } },

        { UINT64_C(12749564289121122836),
            { GameDashboard_EditControlsWithEmptyState::kEntryName,
                {

                    { GameDashboard_EditControlsWithEmptyState::kEmptyNameHash, GameDashboard_EditControlsWithEmptyState::kEmptyName },

                } } },

        { UINT64_C(11948877733512243447),
            { GameDashboard_FunctionTriggered::kEntryName,
                {

                    { GameDashboard_FunctionTriggered::kFunctionNameHash, GameDashboard_FunctionTriggered::kFunctionName },

                } } },

        { UINT64_C(17765246445126047128),
            { GameDashboard_RecordingStartSource::kEntryName,
                {

                    { GameDashboard_RecordingStartSource::kSourceNameHash, GameDashboard_RecordingStartSource::kSourceName },

                } } },

        { UINT64_C(15317274434861980345),
            { GameDashboard_ScreenshotTakeSource::kEntryName,
                {

                    { GameDashboard_ScreenshotTakeSource::kSourceNameHash, GameDashboard_ScreenshotTakeSource::kSourceName },

                } } },

        { UINT64_C(6124626189303220359),
            { GameDashboard_ToggleMainMenu::kEntryName,
                {

                    { GameDashboard_ToggleMainMenu::kToggleMethodNameHash, GameDashboard_ToggleMainMenu::kToggleMethodName },

                    { GameDashboard_ToggleMainMenu::kToggleOnNameHash, GameDashboard_ToggleMainMenu::kToggleOnName },

                } } },

        { UINT64_C(6793166926721319202),
            { GameDashboard_ToolbarClickToExpandState::kEntryName,
                {

                    { GameDashboard_ToolbarClickToExpandState::kExpandedNameHash, GameDashboard_ToolbarClickToExpandState::kExpandedName },

                } } },

        { UINT64_C(15379820645003093243),
            { GameDashboard_ToolbarNewLocation::kEntryName,
                {

                    { GameDashboard_ToolbarNewLocation::kLocationNameHash, GameDashboard_ToolbarNewLocation::kLocationName },

                } } },

        { UINT64_C(1179199656223978960),
            { GameDashboard_ToolbarToggleState::kEntryName,
                {

                    { GameDashboard_ToolbarToggleState::kToggleOnNameHash, GameDashboard_ToolbarToggleState::kToggleOnName },

                } } },

        { UINT64_C(1473466425166916734),
            { GameDashboard_WelcomeDialogNotificationToggleState::kEntryName,
                {

                    { GameDashboard_WelcomeDialogNotificationToggleState::kToggleOnNameHash,
                        GameDashboard_WelcomeDialogNotificationToggleState::kToggleOnName },

                } } },

        { UINT64_C(6114192382293476881),
            { GamingInputOverlay_ActionRepositionOperationType::kEntryName,
                {

                    { GamingInputOverlay_ActionRepositionOperationType::kOperationTypeNameHash,
                        GamingInputOverlay_ActionRepositionOperationType::kOperationTypeName },

                } } },

        { UINT64_C(3845553971601578547),
            { GamingInputOverlay_ActionRepositionWindowStateType::kEntryName,
                {

                    { GamingInputOverlay_ActionRepositionWindowStateType::kWindowStateTypeNameHash,
                        GamingInputOverlay_ActionRepositionWindowStateType::kWindowStateTypeName },

                } } },

        { UINT64_C(2989746233860473659),
            { GamingInputOverlay_ButtonGroupRepositionOperationType::kEntryName,
                {

                    { GamingInputOverlay_ButtonGroupRepositionOperationType::kOperationTypeNameHash,
                        GamingInputOverlay_ButtonGroupRepositionOperationType::kOperationTypeName },

                } } },

        { UINT64_C(12219585854233442105),
            { GamingInputOverlay_ButtonGroupRepositionWindowStateType::kEntryName,
                {

                    { GamingInputOverlay_ButtonGroupRepositionWindowStateType::kWindowStateTypeNameHash,
                        GamingInputOverlay_ButtonGroupRepositionWindowStateType::kWindowStateTypeName },

                } } },

        { UINT64_C(15868125188758034185),
            { GamingInputOverlay_Customization::kEntryName,
                {

                    { GamingInputOverlay_Customization::kCustomizationUsedNameHash, GamingInputOverlay_Customization::kCustomizationUsedName },

                } } },

        { UINT64_C(8325704071122675056),
            { GamingInputOverlay_Feature::kEntryName,
                {

                    { GamingInputOverlay_Feature::kFeatureStateOnNameHash, GamingInputOverlay_Feature::kFeatureStateOnName },

                } } },

        { UINT64_C(10738302011954418259),
            { GamingInputOverlay_MappingHint::kEntryName,
                {

                    { GamingInputOverlay_MappingHint::kMappingHintStateOnNameHash, GamingInputOverlay_MappingHint::kMappingHintStateOnName },

                } } },

        { UINT64_C(3763584486430349859),
            { GamingInputOverlay_MenuEntryRepositionOperationType::kEntryName,
                {

                    { GamingInputOverlay_MenuEntryRepositionOperationType::kOperationTypeNameHash,
                        GamingInputOverlay_MenuEntryRepositionOperationType::kOperationTypeName },

                } } },

        { UINT64_C(5999613232746076014),
            { GamingInputOverlay_MenuEntryRepositionWindowStateType::kEntryName,
                {

                    { GamingInputOverlay_MenuEntryRepositionWindowStateType::kWindowStateTypeNameHash,
                        GamingInputOverlay_MenuEntryRepositionWindowStateType::kWindowStateTypeName },

                } } },

        { UINT64_C(17713702562453741093),
            { GeneratedNavigation::kEntryName,
                {

                    { GeneratedNavigation::kFinalURLIsDefaultSearchEngineNameHash, GeneratedNavigation::kFinalURLIsDefaultSearchEngineName },

                    { GeneratedNavigation::kFinalURLIsHomePageNameHash, GeneratedNavigation::kFinalURLIsHomePageName },

                    { GeneratedNavigation::kFirstURLIsDefaultSearchEngineNameHash, GeneratedNavigation::kFirstURLIsDefaultSearchEngineName },

                    { GeneratedNavigation::kFirstURLIsHomePageNameHash, GeneratedNavigation::kFirstURLIsHomePageName },

                } } },

        { UINT64_C(3420244295988015024),
            { GoogleDocsOfflineExtension::kEntryName,
                {

                    { GoogleDocsOfflineExtension::kResourceRequestedNameHash, GoogleDocsOfflineExtension::kResourceRequestedName },

                } } },

        { UINT64_C(11577416923418681607),
            { Graphics_Smoothness_EventLatency::kEntryName,
                {

                    { Graphics_Smoothness_EventLatency::kActivationNameHash, Graphics_Smoothness_EventLatency::kActivationName },

                    { Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameNameHash,
                        Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameName },

                    { Graphics_Smoothness_EventLatency::kCommitNameHash, Graphics_Smoothness_EventLatency::kCommitName },

                    { Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kEndCommitToActivationNameHash, Graphics_Smoothness_EventLatency::kEndCommitToActivationName },

                    { Graphics_Smoothness_EventLatency::kEventTypeNameHash, Graphics_Smoothness_EventLatency::kEventTypeName },

                    { Graphics_Smoothness_EventLatency::kGenerationToRendererCompositorNameHash,
                        Graphics_Smoothness_EventLatency::kGenerationToRendererCompositorName },

                    { Graphics_Smoothness_EventLatency::kPinchInputTypeNameHash, Graphics_Smoothness_EventLatency::kPinchInputTypeName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToActivationNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToActivationName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToBeginImplFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToBeginImplFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToCommitNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndActivateNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndActivateName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndCommitNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSendBeginMainFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSendBeginMainFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSubmitCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSubmitCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorProcessingNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorProcessingName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorQueueingDelayNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorQueueingDelayName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorToMainNameHash, Graphics_Smoothness_EventLatency::kRendererCompositorToMainName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToActivationNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToActivationName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToBeginImplFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToBeginImplFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToCommitNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndActivateNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndActivateName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndCommitNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToSendBeginMainFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToSendBeginMainFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToSubmitCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToSubmitCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererMainProcessingNameHash, Graphics_Smoothness_EventLatency::kRendererMainProcessingName },

                    { Graphics_Smoothness_EventLatency::kScrollBegin_TouchNameHash, Graphics_Smoothness_EventLatency::kScrollBegin_TouchName },

                    { Graphics_Smoothness_EventLatency::kScrollBegin_WheelNameHash, Graphics_Smoothness_EventLatency::kScrollBegin_WheelName },

                    { Graphics_Smoothness_EventLatency::kScrollInputTypeNameHash, Graphics_Smoothness_EventLatency::kScrollInputTypeName },

                    { Graphics_Smoothness_EventLatency::kScrollUpdate_TouchNameHash, Graphics_Smoothness_EventLatency::kScrollUpdate_TouchName },

                    { Graphics_Smoothness_EventLatency::kScrollUpdate_WheelNameHash, Graphics_Smoothness_EventLatency::kScrollUpdate_WheelName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AccessibilityNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AccessibilityName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AnimateNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AnimateName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_BeginMainSentToStartedName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositeCommitNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositeCommitName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositingInputsNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositingInputsName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_HandleInputEventsNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_HandleInputEventsName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_LayoutUpdateNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_LayoutUpdateName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PaintNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PaintName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PrepaintNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PrepaintName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_StyleUpdateNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_StyleUpdateName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_UpdateLayersNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_UpdateLayersName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName },

                    { Graphics_Smoothness_EventLatency::kTotalLatencyNameHash, Graphics_Smoothness_EventLatency::kTotalLatencyName },

                } } },

        { UINT64_C(4259890394998283936),
            { Graphics_Smoothness_Latency::kEntryName,
                {

                    { Graphics_Smoothness_Latency::kActivationNameHash, Graphics_Smoothness_Latency::kActivationName },

                    { Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameNameHash,
                        Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameName },

                    { Graphics_Smoothness_Latency::kCanvasAnimationNameHash, Graphics_Smoothness_Latency::kCanvasAnimationName },

                    { Graphics_Smoothness_Latency::kCommitNameHash, Graphics_Smoothness_Latency::kCommitName },

                    { Graphics_Smoothness_Latency::kCompositorAnimationNameHash, Graphics_Smoothness_Latency::kCompositorAnimationName },

                    { Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameName },

                    { Graphics_Smoothness_Latency::kEndCommitToActivationNameHash, Graphics_Smoothness_Latency::kEndCommitToActivationName },

                    { Graphics_Smoothness_Latency::kJSAnimationNameHash, Graphics_Smoothness_Latency::kJSAnimationName },

                    { Graphics_Smoothness_Latency::kMainThreadAnimationNameHash, Graphics_Smoothness_Latency::kMainThreadAnimationName },

                    { Graphics_Smoothness_Latency::kMissedFrameNameHash, Graphics_Smoothness_Latency::kMissedFrameName },

                    { Graphics_Smoothness_Latency::kPinchZoomNameHash, Graphics_Smoothness_Latency::kPinchZoomName },

                    { Graphics_Smoothness_Latency::kRAFNameHash, Graphics_Smoothness_Latency::kRAFName },

                    { Graphics_Smoothness_Latency::kScrollbarScrollNameHash, Graphics_Smoothness_Latency::kScrollbarScrollName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AccessibilityNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AccessibilityName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AnimateNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AnimateName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_BeginMainSentToStartedName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositeCommitNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositeCommitName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositingInputsNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositingInputsName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_HandleInputEventsNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_HandleInputEventsName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_LayoutUpdateNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_LayoutUpdateName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PaintNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PaintName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PrepaintNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PrepaintName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_StyleUpdateNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_StyleUpdateName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_UpdateLayersNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_UpdateLayersName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName },

                    { Graphics_Smoothness_Latency::kTotalLatencyNameHash, Graphics_Smoothness_Latency::kTotalLatencyName },

                    { Graphics_Smoothness_Latency::kTouchScrollNameHash, Graphics_Smoothness_Latency::kTouchScrollName },

                    { Graphics_Smoothness_Latency::kUnknownNameHash, Graphics_Smoothness_Latency::kUnknownName },

                    { Graphics_Smoothness_Latency::kVideoNameHash, Graphics_Smoothness_Latency::kVideoName },

                    { Graphics_Smoothness_Latency::kWheelScrollNameHash, Graphics_Smoothness_Latency::kWheelScrollName },

                } } },

        { UINT64_C(5416874090953909475),
            { Graphics_Smoothness_NormalizedPercentDroppedFrames::kEntryName,
                {

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kAboveThresholdNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kAboveThresholdName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kAverageNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kAverageName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedMedianNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedMedianNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMedianNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedMedianNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessBadNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessBadName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessGoodNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessGoodName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessOkayNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessOkayName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad25to50NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad25to50Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad50to75NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad50to75Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad75to100NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad75to100Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryGoodNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryGoodName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter1SecNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter1SecName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter2SecNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter2SecName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter5SecNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter5SecName },

                } } },

        { UINT64_C(13892688012376547748),
            { HistoryClusters::kEntryName,
                {

                    { HistoryClusters::kFinalStateNameHash, HistoryClusters::kFinalStateName },

                    { HistoryClusters::kInitialStateNameHash, HistoryClusters::kInitialStateName },

                    { HistoryClusters::kNumQueriesNameHash, HistoryClusters::kNumQueriesName },

                    { HistoryClusters::kNumTogglesToBasicHistoryNameHash, HistoryClusters::kNumTogglesToBasicHistoryName },

                } } },

        { UINT64_C(17985071802125984440),
            { HistoryManipulationIntervention::kEntryName,
                {

                } } },

        { UINT64_C(6390056345493314213),
            { HistoryNavigation::kEntryName,
                {

                    { HistoryNavigation::kBackForwardCache_BlocklistedFeaturesNameHash, HistoryNavigation::kBackForwardCache_BlocklistedFeaturesName },

                    { HistoryNavigation::kBackForwardCache_BlocklistedFeatures2NameHash, HistoryNavigation::kBackForwardCache_BlocklistedFeatures2Name },

                    { HistoryNavigation::kBackForwardCache_BrowsingInstanceNotSwappedReasonNameHash,
                        HistoryNavigation::kBackForwardCache_BrowsingInstanceNotSwappedReasonName },

                    { HistoryNavigation::kBackForwardCache_DisabledForRenderFrameHostReasonCountNameHash,
                        HistoryNavigation::kBackForwardCache_DisabledForRenderFrameHostReasonCountName },

                    { HistoryNavigation::kBackForwardCache_IsAmpPageNameHash, HistoryNavigation::kBackForwardCache_IsAmpPageName },

                    { HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheNameHash,
                        HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheName },

                    { HistoryNavigation::kBackForwardCache_NotRestoredReasonsNameHash, HistoryNavigation::kBackForwardCache_NotRestoredReasonsName },

                    { HistoryNavigation::kBackForwardCache_NotRestoredReasons2NameHash, HistoryNavigation::kBackForwardCache_NotRestoredReasons2Name },

                    { HistoryNavigation::kCrossOriginSubframesFeaturesNameHash, HistoryNavigation::kCrossOriginSubframesFeaturesName },

                    { HistoryNavigation::kCrossOriginSubframesFeatures2NameHash, HistoryNavigation::kCrossOriginSubframesFeatures2Name },

                    { HistoryNavigation::kCumulativeShiftScoreAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kCumulativeShiftScoreAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kFirstInputDelayAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kFirstInputDelayAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kFirstRequestAnimationFrameAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kFirstRequestAnimationFrameAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kForegroundDurationAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kForegroundDurationAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash,
                        HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName },

                    { HistoryNavigation::kMainFrameFeaturesNameHash, HistoryNavigation::kMainFrameFeaturesName },

                    { HistoryNavigation::kMainFrameFeatures2NameHash, HistoryNavigation::kMainFrameFeatures2Name },

                    { HistoryNavigation::kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        HistoryNavigation::kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msName },

                    { HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentNameHash, HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentName },

                    { HistoryNavigation::kNavigationToFirstPaintAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kNavigationToFirstPaintAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kNumInteractionsAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kNumInteractionsAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kPageEndReasonAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kPageEndReasonAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kSameOriginSubframesFeaturesNameHash, HistoryNavigation::kSameOriginSubframesFeaturesName },

                    { HistoryNavigation::kSameOriginSubframesFeatures2NameHash, HistoryNavigation::kSameOriginSubframesFeatures2Name },

                    { HistoryNavigation::kSecondRequestAnimationFrameAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kSecondRequestAnimationFrameAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kThirdRequestAnimationFrameAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kThirdRequestAnimationFrameAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentNameHash, HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentName },

                    { HistoryNavigation::kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationNameHash,
                        HistoryNavigation::kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationName },

                    { HistoryNavigation::kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2NameHash,
                        HistoryNavigation::kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2Name },

                } } },

        { UINT64_C(287024497009309687),
            { Identifiability::kEntryName,
                {

                    { Identifiability::kGeneratorVersion_926NameHash, Identifiability::kGeneratorVersion_926Name },

                    { Identifiability::kStudyGeneration_626NameHash, Identifiability::kStudyGeneration_626Name },

                } } },

        { UINT64_C(7967874514472474467),
            { InputMethod_Assistive_AutocorrectV2::kEntryName,
                {

                    { InputMethod_Assistive_AutocorrectV2::kCompatibilitySummary_PKNameHash,
                        InputMethod_Assistive_AutocorrectV2::kCompatibilitySummary_PKName },

                    { InputMethod_Assistive_AutocorrectV2::kCompatibilitySummary_VKNameHash,
                        InputMethod_Assistive_AutocorrectV2::kCompatibilitySummary_VKName },

                } } },

        { UINT64_C(16471533519799856378),
            { InputMethod_Assistive_Match::kEntryName,
                {

                    { InputMethod_Assistive_Match::kTypeNameHash, InputMethod_Assistive_Match::kTypeName },

                } } },

        { UINT64_C(5032272348630134775),
            { InputMethod_LongpressDiacritics::kEntryName,
                {

                    { InputMethod_LongpressDiacritics::kActionsNameHash, InputMethod_LongpressDiacritics::kActionsName },

                } } },

        { UINT64_C(17658006784147474164),
            { InputMethod_Manta_Orca::kEntryName,
                {

                    { InputMethod_Manta_Orca::kEditorCriticalStatesNameHash, InputMethod_Manta_Orca::kEditorCriticalStatesName },

                } } },

        { UINT64_C(16790499697963531667),
            { InputMethod_NonCompliantApi::kEntryName,
                {

                    { InputMethod_NonCompliantApi::kNonCompliantOperationNameHash, InputMethod_NonCompliantApi::kNonCompliantOperationName },

                } } },

        { UINT64_C(1640774753589741944),
            { InstalledRelatedApps::kEntryName,
                {

                    { InstalledRelatedApps::kCalledNameHash, InstalledRelatedApps::kCalledName },

                } } },

        { UINT64_C(3999691266874322037),
            { IOS_FindInPageSearchMatches::kEntryName,
                {

                    { IOS_FindInPageSearchMatches::kHasMatchesNameHash, IOS_FindInPageSearchMatches::kHasMatchesName },

                } } },

        { UINT64_C(8606631182486356401),
            { IOS_FullscreenActions::kEntryName,
                {

                    { IOS_FullscreenActions::kHasExitedManuallyNameHash, IOS_FullscreenActions::kHasExitedManuallyName },

                } } },

        { UINT64_C(9401651119910784407),
            { IOS_IsDefaultBrowser::kEntryName,
                {

                    { IOS_IsDefaultBrowser::kIsDefaultBrowserNameHash, IOS_IsDefaultBrowser::kIsDefaultBrowserName },

                } } },

        { UINT64_C(11840518206463876002),
            { IOS_PageAddedToReadingList::kEntryName,
                {

                    { IOS_PageAddedToReadingList::kAddedFromMessagesNameHash, IOS_PageAddedToReadingList::kAddedFromMessagesName },

                } } },

        { UINT64_C(3910969266183986451),
            { IOS_PageReadability::kEntryName,
                {

                    { IOS_PageReadability::kDidAcceptNameHash, IOS_PageReadability::kDidAcceptName },

                    { IOS_PageReadability::kDistilibilityLongScoreNameHash, IOS_PageReadability::kDistilibilityLongScoreName },

                    { IOS_PageReadability::kDistilibilityScoreNameHash, IOS_PageReadability::kDistilibilityScoreName },

                } } },

        { UINT64_C(4631281682778806273),
            { IOS_PageZoomChanged::kEntryName,
                {

                    { IOS_PageZoomChanged::kContentSizeCategoryNameHash, IOS_PageZoomChanged::kContentSizeCategoryName },

                    { IOS_PageZoomChanged::kOverallZoomLevelNameHash, IOS_PageZoomChanged::kOverallZoomLevelName },

                    { IOS_PageZoomChanged::kUserZoomLevelNameHash, IOS_PageZoomChanged::kUserZoomLevelName },

                } } },

        { UINT64_C(1914766108595585505),
            { IOS_ParcelTrackingNumberDetected::kEntryName,
                {

                    { IOS_ParcelTrackingNumberDetected::kParcelCarrierNameHash, IOS_ParcelTrackingNumberDetected::kParcelCarrierName },

                } } },

        { UINT64_C(10713578431670288986),
            { IOS_RendererGone::kEntryName,
                {

                    { IOS_RendererGone::kAliveRecentlyRendererCountNameHash, IOS_RendererGone::kAliveRecentlyRendererCountName },

                    { IOS_RendererGone::kAliveRendererCountNameHash, IOS_RendererGone::kAliveRendererCountName },

                    { IOS_RendererGone::kInForegroundNameHash, IOS_RendererGone::kInForegroundName },

                    { IOS_RendererGone::kSawMemoryWarningNameHash, IOS_RendererGone::kSawMemoryWarningName },

                } } },

        { UINT64_C(7566859152267022983),
            { JavascriptFrameworkPageLoad::kEntryName,
                {

                    { JavascriptFrameworkPageLoad::kAngularPageLoadNameHash, JavascriptFrameworkPageLoad::kAngularPageLoadName },

                    { JavascriptFrameworkPageLoad::kGatsbyPageLoadNameHash, JavascriptFrameworkPageLoad::kGatsbyPageLoadName },

                    { JavascriptFrameworkPageLoad::kNextJSPageLoadNameHash, JavascriptFrameworkPageLoad::kNextJSPageLoadName },

                    { JavascriptFrameworkPageLoad::kNuxtJSPageLoadNameHash, JavascriptFrameworkPageLoad::kNuxtJSPageLoadName },

                    { JavascriptFrameworkPageLoad::kPreactPageLoadNameHash, JavascriptFrameworkPageLoad::kPreactPageLoadName },

                    { JavascriptFrameworkPageLoad::kReactPageLoadNameHash, JavascriptFrameworkPageLoad::kReactPageLoadName },

                    { JavascriptFrameworkPageLoad::kSapperPageLoadNameHash, JavascriptFrameworkPageLoad::kSapperPageLoadName },

                    { JavascriptFrameworkPageLoad::kSveltePageLoadNameHash, JavascriptFrameworkPageLoad::kSveltePageLoadName },

                    { JavascriptFrameworkPageLoad::kVuePageLoadNameHash, JavascriptFrameworkPageLoad::kVuePageLoadName },

                    { JavascriptFrameworkPageLoad::kVuePressPageLoadNameHash, JavascriptFrameworkPageLoad::kVuePressPageLoadName },

                } } },

        { UINT64_C(14790400947302801717),
            { Lens_Overlay_ContextualSearchbox_FocusedInSession::kEntryName,
                {

                    { Lens_Overlay_ContextualSearchbox_FocusedInSession::kFocusedInSessionNameHash,
                        Lens_Overlay_ContextualSearchbox_FocusedInSession::kFocusedInSessionName },

                    { Lens_Overlay_ContextualSearchbox_FocusedInSession::kPageContentTypeNameHash,
                        Lens_Overlay_ContextualSearchbox_FocusedInSession::kPageContentTypeName },

                } } },

        { UINT64_C(11898097730227890116),
            { Lens_Overlay_ContextualSearchBox_ShownInSession::kEntryName,
                {

                    { Lens_Overlay_ContextualSearchBox_ShownInSession::kPageContentTypeNameHash,
                        Lens_Overlay_ContextualSearchBox_ShownInSession::kPageContentTypeName },

                    { Lens_Overlay_ContextualSearchBox_ShownInSession::kWasShownNameHash, Lens_Overlay_ContextualSearchBox_ShownInSession::kWasShownName },

                } } },

        { UINT64_C(9359961652274800012),
            { Lens_Overlay_ContextualSuggest_QueryIssuedInSession::kEntryName,
                {

                    { Lens_Overlay_ContextualSuggest_QueryIssuedInSession::kPageContentTypeNameHash,
                        Lens_Overlay_ContextualSuggest_QueryIssuedInSession::kPageContentTypeName },

                    { Lens_Overlay_ContextualSuggest_QueryIssuedInSession::kQueryIssuedInSessionNameHash,
                        Lens_Overlay_ContextualSuggest_QueryIssuedInSession::kQueryIssuedInSessionName },

                } } },

        { UINT64_C(5556638233503911795),
            { Lens_Overlay_ContextualSuggest_ZPS_ShownInSession::kEntryName,
                {

                    { Lens_Overlay_ContextualSuggest_ZPS_ShownInSession::kPageContentTypeNameHash,
                        Lens_Overlay_ContextualSuggest_ZPS_ShownInSession::kPageContentTypeName },

                    { Lens_Overlay_ContextualSuggest_ZPS_ShownInSession::kShownInSessionNameHash,
                        Lens_Overlay_ContextualSuggest_ZPS_ShownInSession::kShownInSessionName },

                } } },

        { UINT64_C(16393195650402138039),
            { Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession::kEntryName,
                {

                    { Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession::kPageContentTypeNameHash,
                        Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession::kPageContentTypeName },

                    { Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession::kSuggestionUsedInSessionNameHash,
                        Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession::kSuggestionUsedInSessionName },

                } } },

        { UINT64_C(4208315803724186419),
            { Lens_Overlay_Overlay_UserAction::kEntryName,
                {

                    { Lens_Overlay_Overlay_UserAction::kUserActionNameHash, Lens_Overlay_Overlay_UserAction::kUserActionName },

                } } },

        { UINT64_C(8217894806744583515),
            { Lens_Overlay_SessionEnd::kEntryName,
                {

                    { Lens_Overlay_SessionEnd::kGeneratedTabCountNameHash, Lens_Overlay_SessionEnd::kGeneratedTabCountName },

                    { Lens_Overlay_SessionEnd::kInvocationDocumentTypeNameHash, Lens_Overlay_SessionEnd::kInvocationDocumentTypeName },

                    { Lens_Overlay_SessionEnd::kInvocationResultedInSearchNameHash, Lens_Overlay_SessionEnd::kInvocationResultedInSearchName },

                    { Lens_Overlay_SessionEnd::kInvocationSourceNameHash, Lens_Overlay_SessionEnd::kInvocationSourceName },

                    { Lens_Overlay_SessionEnd::kSessionDurationNameHash, Lens_Overlay_SessionEnd::kSessionDurationName },

                    { Lens_Overlay_SessionEnd::kSessionForegroundDurationNameHash, Lens_Overlay_SessionEnd::kSessionForegroundDurationName },

                } } },

        { UINT64_C(6105502683077053997),
            { Lens_Overlay_TimeToFirstInteraction::kEntryName,
                {

                    { Lens_Overlay_TimeToFirstInteraction::kAllEntryPointsNameHash, Lens_Overlay_TimeToFirstInteraction::kAllEntryPointsName },

                    { Lens_Overlay_TimeToFirstInteraction::kAppMenuNameHash, Lens_Overlay_TimeToFirstInteraction::kAppMenuName },

                    { Lens_Overlay_TimeToFirstInteraction::kContentAreaContextMenuPageNameHash,
                        Lens_Overlay_TimeToFirstInteraction::kContentAreaContextMenuPageName },

                    { Lens_Overlay_TimeToFirstInteraction::kFindInPageNameHash, Lens_Overlay_TimeToFirstInteraction::kFindInPageName },

                    { Lens_Overlay_TimeToFirstInteraction::kFirstInteractionTypeNameHash, Lens_Overlay_TimeToFirstInteraction::kFirstInteractionTypeName },

                    { Lens_Overlay_TimeToFirstInteraction::kOmniboxNameHash, Lens_Overlay_TimeToFirstInteraction::kOmniboxName },

                    { Lens_Overlay_TimeToFirstInteraction::kToolbarNameHash, Lens_Overlay_TimeToFirstInteraction::kToolbarName },

                } } },

        { UINT64_C(2459509573580782733),
            { LoadCountsPerTopLevelDocument::kEntryName,
                {

                    { LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_HiddenNameHash,
                        LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_HiddenName },

                    { LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_VisibleNameHash,
                        LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_VisibleName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_HiddenNameHash,
                        LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_HiddenName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_VisibleNameHash,
                        LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_VisibleName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_HiddenNameHash,
                        LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_HiddenName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_VisibleNameHash,
                        LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_VisibleName },

                } } },

        { UINT64_C(17180165945688341623),
            { LoadingPredictor::kEntryName,
                {

                    { LoadingPredictor::kCorrectSubresourceOriginPreconnectsInitiatedNameHash,
                        LoadingPredictor::kCorrectSubresourceOriginPreconnectsInitiatedName },

                    { LoadingPredictor::kCorrectSubresourcePrefetchesInitiatedNameHash, LoadingPredictor::kCorrectSubresourcePrefetchesInitiatedName },

                    { LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsNameHash, LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsName },

                    { LoadingPredictor::kLocalPredictionOriginsNameHash, LoadingPredictor::kLocalPredictionOriginsName },

                    { LoadingPredictor::kNavigationStartToFirstSubresourcePrefetchInitiatedNameHash,
                        LoadingPredictor::kNavigationStartToFirstSubresourcePrefetchInitiatedName },

                    { LoadingPredictor::kNavigationStartToNavigationCommitNameHash, LoadingPredictor::kNavigationStartToNavigationCommitName },

                    { LoadingPredictor::kNavigationStartToOptimizationGuidePredictionArrivedNameHash,
                        LoadingPredictor::kNavigationStartToOptimizationGuidePredictionArrivedName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedLowPriorityOriginsNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedLowPriorityOriginsName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresourcesNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresourcesName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresources_CrossOriginNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresources_CrossOriginName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresources_CrossOriginNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresources_CrossOriginName },

                    { LoadingPredictor::kOptimizationGuidePredictionDecisionNameHash, LoadingPredictor::kOptimizationGuidePredictionDecisionName },

                    { LoadingPredictor::kOptimizationGuidePredictionOriginsNameHash, LoadingPredictor::kOptimizationGuidePredictionOriginsName },

                    { LoadingPredictor::kOptimizationGuidePredictionSubresourcesNameHash, LoadingPredictor::kOptimizationGuidePredictionSubresourcesName },

                    { LoadingPredictor::kOptimizationGuidePredictionSubresources_CrossOriginNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionSubresources_CrossOriginName },

                    { LoadingPredictor::kSubresourceOriginPreconnectsInitiatedNameHash, LoadingPredictor::kSubresourceOriginPreconnectsInitiatedName },

                    { LoadingPredictor::kSubresourcePrefetchesInitiatedNameHash, LoadingPredictor::kSubresourcePrefetchesInitiatedName },

                } } },

        { UINT64_C(5563841616204153427),
            { LocalNetworkRequests::kEntryName,
                {

                    { LocalNetworkRequests::kCount_FailedNameHash, LocalNetworkRequests::kCount_FailedName },

                    { LocalNetworkRequests::kCount_SuccessfulNameHash, LocalNetworkRequests::kCount_SuccessfulName },

                    { LocalNetworkRequests::kPortTypeNameHash, LocalNetworkRequests::kPortTypeName },

                    { LocalNetworkRequests::kResourceTypeNameHash, LocalNetworkRequests::kResourceTypeName },

                } } },

        { UINT64_C(6455694443766360259),
            { LookalikeUrl_NavigationSuggestion::kEntryName,
                {

                    { LookalikeUrl_NavigationSuggestion::kMatchTypeNameHash, LookalikeUrl_NavigationSuggestion::kMatchTypeName },

                    { LookalikeUrl_NavigationSuggestion::kTriggeredByInitialUrlNameHash, LookalikeUrl_NavigationSuggestion::kTriggeredByInitialUrlName },

                    { LookalikeUrl_NavigationSuggestion::kUserActionNameHash, LookalikeUrl_NavigationSuggestion::kUserActionName },

                } } },

        { UINT64_C(17528121675680665933),
            { MainFrameNavigation::kEntryName,
                {

                    { MainFrameNavigation::kDidCommitNameHash, MainFrameNavigation::kDidCommitName },

                } } },

        { UINT64_C(12440808905277294625),
            { MainFrameNavigation_ZstdContentEncoding::kEntryName,
                {

                    { MainFrameNavigation_ZstdContentEncoding::kUsedZstdNameHash, MainFrameNavigation_ZstdContentEncoding::kUsedZstdName },

                } } },

        { UINT64_C(15357501003006382777),
            { Media_Autoplay_Attempt::kEntryName,
                {

                    { Media_Autoplay_Attempt::kAudioTrackNameHash, Media_Autoplay_Attempt::kAudioTrackName },

                    { Media_Autoplay_Attempt::kHighMediaEngagementNameHash, Media_Autoplay_Attempt::kHighMediaEngagementName },

                    { Media_Autoplay_Attempt::kMutedNameHash, Media_Autoplay_Attempt::kMutedName },

                    { Media_Autoplay_Attempt::kSourceNameHash, Media_Autoplay_Attempt::kSourceName },

                    { Media_Autoplay_Attempt::kUserGestureRequiredNameHash, Media_Autoplay_Attempt::kUserGestureRequiredName },

                    { Media_Autoplay_Attempt::kUserGestureStatusNameHash, Media_Autoplay_Attempt::kUserGestureStatusName },

                    { Media_Autoplay_Attempt::kVideoTrackNameHash, Media_Autoplay_Attempt::kVideoTrackName },

                } } },

        { UINT64_C(2039378813737092278),
            { Media_Autoplay_AudioContext::kEntryName,
                {

                    { Media_Autoplay_AudioContext::kSourceNodeStartedNameHash, Media_Autoplay_AudioContext::kSourceNodeStartedName },

                    { Media_Autoplay_AudioContext::kStatusNameHash, Media_Autoplay_AudioContext::kStatusName },

                    { Media_Autoplay_AudioContext::kUnlockTypeNameHash, Media_Autoplay_AudioContext::kUnlockTypeName },

                } } },

        { UINT64_C(3015822386723746523),
            { Media_Autoplay_Muted_UnmuteAction::kEntryName,
                {

                    { Media_Autoplay_Muted_UnmuteAction::kResultNameHash, Media_Autoplay_Muted_UnmuteAction::kResultName },

                    { Media_Autoplay_Muted_UnmuteAction::kSourceNameHash, Media_Autoplay_Muted_UnmuteAction::kSourceName },

                } } },

        { UINT64_C(8416658001170131658),
            { Media_BasicPlayback::kEntryName,
                {

                    { Media_BasicPlayback::kAudioCodecNameHash, Media_BasicPlayback::kAudioCodecName },

                    { Media_BasicPlayback::kAudioCodecProfileNameHash, Media_BasicPlayback::kAudioCodecProfileName },

                    { Media_BasicPlayback::kAudioDecoderNameNameHash, Media_BasicPlayback::kAudioDecoderNameName },

                    { Media_BasicPlayback::kAudioEncryptionSchemeNameHash, Media_BasicPlayback::kAudioEncryptionSchemeName },

                    { Media_BasicPlayback::kAutoplayInitiatedNameHash, Media_BasicPlayback::kAutoplayInitiatedName },

                    { Media_BasicPlayback::kCompletedRebuffersCountNameHash, Media_BasicPlayback::kCompletedRebuffersCountName },

                    { Media_BasicPlayback::kCompletedRebuffersDurationNameHash, Media_BasicPlayback::kCompletedRebuffersDurationName },

                    { Media_BasicPlayback::kDurationNameHash, Media_BasicPlayback::kDurationName },

                    { Media_BasicPlayback::kHasAudioNameHash, Media_BasicPlayback::kHasAudioName },

                    { Media_BasicPlayback::kHasVideoNameHash, Media_BasicPlayback::kHasVideoName },

                    { Media_BasicPlayback::kIsBackgroundNameHash, Media_BasicPlayback::kIsBackgroundName },

                    { Media_BasicPlayback::kIsEMENameHash, Media_BasicPlayback::kIsEMEName },

                    { Media_BasicPlayback::kIsMSENameHash, Media_BasicPlayback::kIsMSEName },

                    { Media_BasicPlayback::kIsMutedNameHash, Media_BasicPlayback::kIsMutedName },

                    { Media_BasicPlayback::kIsTopFrameNameHash, Media_BasicPlayback::kIsTopFrameName },

                    { Media_BasicPlayback::kLastPipelineStatusNameHash, Media_BasicPlayback::kLastPipelineStatusName },

                    { Media_BasicPlayback::kMeanTimeBetweenRebuffersNameHash, Media_BasicPlayback::kMeanTimeBetweenRebuffersName },

                    { Media_BasicPlayback::kMediaStreamTypeNameHash, Media_BasicPlayback::kMediaStreamTypeName },

                    { Media_BasicPlayback::kPlayerIDNameHash, Media_BasicPlayback::kPlayerIDName },

                    { Media_BasicPlayback::kRebuffersCountNameHash, Media_BasicPlayback::kRebuffersCountName },

                    { Media_BasicPlayback::kVideoCodecNameHash, Media_BasicPlayback::kVideoCodecName },

                    { Media_BasicPlayback::kVideoCodecProfileNameHash, Media_BasicPlayback::kVideoCodecProfileName },

                    { Media_BasicPlayback::kVideoDecoderNameNameHash, Media_BasicPlayback::kVideoDecoderNameName },

                    { Media_BasicPlayback::kVideoEncryptionSchemeNameHash, Media_BasicPlayback::kVideoEncryptionSchemeName },

                    { Media_BasicPlayback::kVideoFramesDecodedNameHash, Media_BasicPlayback::kVideoFramesDecodedName },

                    { Media_BasicPlayback::kVideoFramesDroppedNameHash, Media_BasicPlayback::kVideoFramesDroppedName },

                    { Media_BasicPlayback::kVideoNaturalHeightNameHash, Media_BasicPlayback::kVideoNaturalHeightName },

                    { Media_BasicPlayback::kVideoNaturalWidthNameHash, Media_BasicPlayback::kVideoNaturalWidthName },

                    { Media_BasicPlayback::kWatchTimeNameHash, Media_BasicPlayback::kWatchTimeName },

                    { Media_BasicPlayback::kWatchTime_ACNameHash, Media_BasicPlayback::kWatchTime_ACName },

                    { Media_BasicPlayback::kWatchTime_BatteryNameHash, Media_BasicPlayback::kWatchTime_BatteryName },

                    { Media_BasicPlayback::kWatchTime_DisplayFullscreenNameHash, Media_BasicPlayback::kWatchTime_DisplayFullscreenName },

                    { Media_BasicPlayback::kWatchTime_DisplayInlineNameHash, Media_BasicPlayback::kWatchTime_DisplayInlineName },

                    { Media_BasicPlayback::kWatchTime_DisplayPictureInPictureNameHash, Media_BasicPlayback::kWatchTime_DisplayPictureInPictureName },

                    { Media_BasicPlayback::kWatchTime_NativeControlsOffNameHash, Media_BasicPlayback::kWatchTime_NativeControlsOffName },

                    { Media_BasicPlayback::kWatchTime_NativeControlsOnNameHash, Media_BasicPlayback::kWatchTime_NativeControlsOnName },

                } } },

        { UINT64_C(7968428823878627316),
            { Media_EME_ApiPromiseRejection::kEntryName,
                {

                    { Media_EME_ApiPromiseRejection::kApiNameHash, Media_EME_ApiPromiseRejection::kApiName },

                    { Media_EME_ApiPromiseRejection::kKeySystemNameHash, Media_EME_ApiPromiseRejection::kKeySystemName },

                    { Media_EME_ApiPromiseRejection::kSystemCodeNameHash, Media_EME_ApiPromiseRejection::kSystemCodeName },

                    { Media_EME_ApiPromiseRejection::kUseHardwareSecureCodecsNameHash, Media_EME_ApiPromiseRejection::kUseHardwareSecureCodecsName },

                } } },

        { UINT64_C(2589665349945066342),
            { Media_EME_CdmSystemCode::kEntryName,
                {

                    { Media_EME_CdmSystemCode::kCdmSystemCodeNameHash, Media_EME_CdmSystemCode::kCdmSystemCodeName },

                } } },

        { UINT64_C(16664479587726188526),
            { Media_EME_CreateMediaKeys::kEntryName,
                {

                    { Media_EME_CreateMediaKeys::kIsAdFrameNameHash, Media_EME_CreateMediaKeys::kIsAdFrameName },

                    { Media_EME_CreateMediaKeys::kIsCrossOriginNameHash, Media_EME_CreateMediaKeys::kIsCrossOriginName },

                    { Media_EME_CreateMediaKeys::kIsTopFrameNameHash, Media_EME_CreateMediaKeys::kIsTopFrameName },

                    { Media_EME_CreateMediaKeys::kKeySystemNameHash, Media_EME_CreateMediaKeys::kKeySystemName },

                } } },

        { UINT64_C(6913636598201291698),
            { Media_EME_GetStatusForPolicy::kEntryName,
                {

                    { Media_EME_GetStatusForPolicy::kIsAdFrameNameHash, Media_EME_GetStatusForPolicy::kIsAdFrameName },

                    { Media_EME_GetStatusForPolicy::kKeySystemNameHash, Media_EME_GetStatusForPolicy::kKeySystemName },

                    { Media_EME_GetStatusForPolicy::kMinHdcpVersionNameHash, Media_EME_GetStatusForPolicy::kMinHdcpVersionName },

                    { Media_EME_GetStatusForPolicy::kUseHardwareSecureCodecsNameHash, Media_EME_GetStatusForPolicy::kUseHardwareSecureCodecsName },

                } } },

        { UINT64_C(14018069268047764723),
            { Media_EME_RequestMediaKeySystemAccess::kEntryName,
                {

                    { Media_EME_RequestMediaKeySystemAccess::kIsAdFrameNameHash, Media_EME_RequestMediaKeySystemAccess::kIsAdFrameName },

                    { Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginNameHash, Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginName },

                    { Media_EME_RequestMediaKeySystemAccess::kIsFromMediaCapabilitiesNameHash,
                        Media_EME_RequestMediaKeySystemAccess::kIsFromMediaCapabilitiesName },

                    { Media_EME_RequestMediaKeySystemAccess::kIsTopFrameNameHash, Media_EME_RequestMediaKeySystemAccess::kIsTopFrameName },

                    { Media_EME_RequestMediaKeySystemAccess::kKeySystemNameHash, Media_EME_RequestMediaKeySystemAccess::kKeySystemName },

                    { Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesNameHash, Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesName },

                    { Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessNameHash,
                        Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessName },

                    { Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessNameHash,
                        Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessName },

                } } },

        { UINT64_C(1964837187481381741),
            { Media_EME_Usage::kEntryName,
                {

                    { Media_EME_Usage::kApiNameHash, Media_EME_Usage::kApiName },

                    { Media_EME_Usage::kIsPersistentSessionNameHash, Media_EME_Usage::kIsPersistentSessionName },

                    { Media_EME_Usage::kKeySystemNameHash, Media_EME_Usage::kKeySystemName },

                    { Media_EME_Usage::kUseHardwareSecureCodecsNameHash, Media_EME_Usage::kUseHardwareSecureCodecsName },

                } } },

        { UINT64_C(886585293387977076),
            { Media_Engagement_SessionFinished::kEntryName,
                {

                    { Media_Engagement_SessionFinished::kEngagement_IsHighNameHash, Media_Engagement_SessionFinished::kEngagement_IsHighName },

                    { Media_Engagement_SessionFinished::kEngagement_ScoreNameHash, Media_Engagement_SessionFinished::kEngagement_ScoreName },

                    { Media_Engagement_SessionFinished::kPlaybacks_TotalNameHash, Media_Engagement_SessionFinished::kPlaybacks_TotalName },

                    { Media_Engagement_SessionFinished::kPlayer_Audible_DeltaNameHash, Media_Engagement_SessionFinished::kPlayer_Audible_DeltaName },

                    { Media_Engagement_SessionFinished::kPlayer_Significant_DeltaNameHash, Media_Engagement_SessionFinished::kPlayer_Significant_DeltaName },

                    { Media_Engagement_SessionFinished::kVisits_TotalNameHash, Media_Engagement_SessionFinished::kVisits_TotalName },

                } } },

        { UINT64_C(13016590436839167921),
            { Media_Engagement_ShortPlaybackIgnored::kEntryName,
                {

                    { Media_Engagement_ShortPlaybackIgnored::kLengthNameHash, Media_Engagement_ShortPlaybackIgnored::kLengthName },

                } } },

        { UINT64_C(9905764244590677619),
            { Media_Feed_Discover::kEntryName,
                {

                    { Media_Feed_Discover::kHasMediaFeedNameHash, Media_Feed_Discover::kHasMediaFeedName },

                } } },

        { UINT64_C(14701475071317937048),
            { Media_GlobalMediaControls_ActionButtonPressed::kEntryName,
                {

                    { Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionNameHash,
                        Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionName },

                } } },

        { UINT64_C(5140299263436558885),
            { Media_Learning_PredictionRecord::kEntryName,
                {

                    { Media_Learning_PredictionRecord::kLearningTaskNameHash, Media_Learning_PredictionRecord::kLearningTaskName },

                    { Media_Learning_PredictionRecord::kObservedValueNameHash, Media_Learning_PredictionRecord::kObservedValueName },

                    { Media_Learning_PredictionRecord::kPredictedValueNameHash, Media_Learning_PredictionRecord::kPredictedValueName },

                    { Media_Learning_PredictionRecord::kTrainingDataSizeNameHash, Media_Learning_PredictionRecord::kTrainingDataSizeName },

                    { Media_Learning_PredictionRecord::kTrainingDataTotalWeightNameHash, Media_Learning_PredictionRecord::kTrainingDataTotalWeightName },

                } } },

        { UINT64_C(9485702385711484844),
            { Media_SiteMuted::kEntryName,
                {

                    { Media_SiteMuted::kMuteReasonNameHash, Media_SiteMuted::kMuteReasonName },

                } } },

        { UINT64_C(4207699002180294249),
            { Media_VideoDecodePerfRecord::kEntryName,
                {

                    { Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientNameHash,
                        Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothNameHash, Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothName },

                    { Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedName },

                    { Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedName },

                    { Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientNameHash,
                        Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothNameHash, Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothName },

                    { Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedName },

                    { Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedName },

                    { Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kVideo_CodecProfileNameHash, Media_VideoDecodePerfRecord::kVideo_CodecProfileName },

                    { Media_VideoDecodePerfRecord::kVideo_EME_KeySystemNameHash, Media_VideoDecodePerfRecord::kVideo_EME_KeySystemName },

                    { Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsNameHash, Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsName },

                    { Media_VideoDecodePerfRecord::kVideo_FramesPerSecondNameHash, Media_VideoDecodePerfRecord::kVideo_FramesPerSecondName },

                    { Media_VideoDecodePerfRecord::kVideo_InTopFrameNameHash, Media_VideoDecodePerfRecord::kVideo_InTopFrameName },

                    { Media_VideoDecodePerfRecord::kVideo_NaturalHeightNameHash, Media_VideoDecodePerfRecord::kVideo_NaturalHeightName },

                    { Media_VideoDecodePerfRecord::kVideo_NaturalWidthNameHash, Media_VideoDecodePerfRecord::kVideo_NaturalWidthName },

                    { Media_VideoDecodePerfRecord::kVideo_PlayerIDNameHash, Media_VideoDecodePerfRecord::kVideo_PlayerIDName },

                } } },

        { UINT64_C(10025438409800124399),
            { Media_VideoEncoderMetrics::kEntryName,
                {

                    { Media_VideoEncoderMetrics::kHeightNameHash, Media_VideoEncoderMetrics::kHeightName },

                    { Media_VideoEncoderMetrics::kIsHardwareNameHash, Media_VideoEncoderMetrics::kIsHardwareName },

                    { Media_VideoEncoderMetrics::kNumEncodedFramesNameHash, Media_VideoEncoderMetrics::kNumEncodedFramesName },

                    { Media_VideoEncoderMetrics::kProfileNameHash, Media_VideoEncoderMetrics::kProfileName },

                    { Media_VideoEncoderMetrics::kStatusNameHash, Media_VideoEncoderMetrics::kStatusName },

                    { Media_VideoEncoderMetrics::kSVCModeNameHash, Media_VideoEncoderMetrics::kSVCModeName },

                    { Media_VideoEncoderMetrics::kUseCaseNameHash, Media_VideoEncoderMetrics::kUseCaseName },

                    { Media_VideoEncoderMetrics::kWidthNameHash, Media_VideoEncoderMetrics::kWidthName },

                } } },

        { UINT64_C(17314038096102597390),
            { Media_WebAudio_AudioContext_AudibleTime::kEntryName,
                {

                    { Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeNameHash, Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeName },

                    { Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameNameHash, Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameName },

                } } },

        { UINT64_C(14428460888229388079),
            { Media_WebMediaPlayerState::kEntryName,
                {

                    { Media_WebMediaPlayerState::kAudioEncryptionTypeNameHash, Media_WebMediaPlayerState::kAudioEncryptionTypeName },

                    { Media_WebMediaPlayerState::kContainerNameNameHash, Media_WebMediaPlayerState::kContainerNameName },

                    { Media_WebMediaPlayerState::kFinalPipelineStatusNameHash, Media_WebMediaPlayerState::kFinalPipelineStatusName },

                    { Media_WebMediaPlayerState::kHasWaitingForKeyNameHash, Media_WebMediaPlayerState::kHasWaitingForKeyName },

                    { Media_WebMediaPlayerState::kIsEMENameHash, Media_WebMediaPlayerState::kIsEMEName },

                    { Media_WebMediaPlayerState::kIsHardwareSecureNameHash, Media_WebMediaPlayerState::kIsHardwareSecureName },

                    { Media_WebMediaPlayerState::kIsMSENameHash, Media_WebMediaPlayerState::kIsMSEName },

                    { Media_WebMediaPlayerState::kIsTopFrameNameHash, Media_WebMediaPlayerState::kIsTopFrameName },

                    { Media_WebMediaPlayerState::kKeySystemNameHash, Media_WebMediaPlayerState::kKeySystemName },

                    { Media_WebMediaPlayerState::kPlayerIDNameHash, Media_WebMediaPlayerState::kPlayerIDName },

                    { Media_WebMediaPlayerState::kRendererTypeNameHash, Media_WebMediaPlayerState::kRendererTypeName },

                    { Media_WebMediaPlayerState::kTimeToFirstFrameNameHash, Media_WebMediaPlayerState::kTimeToFirstFrameName },

                    { Media_WebMediaPlayerState::kTimeToMetadataNameHash, Media_WebMediaPlayerState::kTimeToMetadataName },

                    { Media_WebMediaPlayerState::kTimeToPlayReadyNameHash, Media_WebMediaPlayerState::kTimeToPlayReadyName },

                    { Media_WebMediaPlayerState::kURLSchemeNameHash, Media_WebMediaPlayerState::kURLSchemeName },

                    { Media_WebMediaPlayerState::kVideoEncryptionTypeNameHash, Media_WebMediaPlayerState::kVideoEncryptionTypeName },

                } } },

        { UINT64_C(3512705025017023804),
            { MediaRouter_CastWebSenderExtensionLoadUrl::kEntryName,
                {

                    { MediaRouter_CastWebSenderExtensionLoadUrl::kHasOccurredNameHash, MediaRouter_CastWebSenderExtensionLoadUrl::kHasOccurredName },

                } } },

        { UINT64_C(16497635965856919352),
            { MediaRouter_SiteInitiatedMirroringStarted::kEntryName,
                {

                    { MediaRouter_SiteInitiatedMirroringStarted::kAllowAudioCaptureNameHash,
                        MediaRouter_SiteInitiatedMirroringStarted::kAllowAudioCaptureName },

                } } },

        { UINT64_C(2088599620296425553),
            { MediaRouter_TabMirroringStarted::kEntryName,
                {

                    { MediaRouter_TabMirroringStarted::kAudioStateNameHash, MediaRouter_TabMirroringStarted::kAudioStateName },

                } } },

        { UINT64_C(10994491282953221287),
            { MediaStream_Device::kEntryName,
                {

                    { MediaStream_Device::kVideoCaptureGenerateStreamResultNameHash, MediaStream_Device::kVideoCaptureGenerateStreamResultName },

                } } },

        { UINT64_C(2958711939369432145),
            { Memory_Experimental::kEntryName,
                {

                    { Memory_Experimental::kArrayBufferNameHash, Memory_Experimental::kArrayBufferName },

                    { Memory_Experimental::kBlinkGCNameHash, Memory_Experimental::kBlinkGCName },

                    { Memory_Experimental::kBlinkGC_AllocatedObjectsNameHash, Memory_Experimental::kBlinkGC_AllocatedObjectsName },

                    { Memory_Experimental::kCommandBufferNameHash, Memory_Experimental::kCommandBufferName },

                    { Memory_Experimental::kDiscardableNameHash, Memory_Experimental::kDiscardableName },

                    { Memory_Experimental::kDownloadServiceNameHash, Memory_Experimental::kDownloadServiceName },

                    { Memory_Experimental::kExtensions_ValueStoreNameHash, Memory_Experimental::kExtensions_ValueStoreName },

                    { Memory_Experimental::kFontCachesNameHash, Memory_Experimental::kFontCachesName },

                    { Memory_Experimental::kGpuMemoryNameHash, Memory_Experimental::kGpuMemoryName },

                    { Memory_Experimental::kHistoryNameHash, Memory_Experimental::kHistoryName },

                    { Memory_Experimental::kIsVisibleNameHash, Memory_Experimental::kIsVisibleName },

                    { Memory_Experimental::kJavaHeapNameHash, Memory_Experimental::kJavaHeapName },

                    { Memory_Experimental::kLevelDatabaseNameHash, Memory_Experimental::kLevelDatabaseName },

                    { Memory_Experimental::kMallocNameHash, Memory_Experimental::kMallocName },

                    { Memory_Experimental::kMalloc_AllocatedObjectsNameHash, Memory_Experimental::kMalloc_AllocatedObjectsName },

                    { Memory_Experimental::kNumberOfAdSubframesNameHash, Memory_Experimental::kNumberOfAdSubframesName },

                    { Memory_Experimental::kNumberOfArrayBufferContentsNameHash, Memory_Experimental::kNumberOfArrayBufferContentsName },

                    { Memory_Experimental::kNumberOfDetachedScriptStatesNameHash, Memory_Experimental::kNumberOfDetachedScriptStatesName },

                    { Memory_Experimental::kNumberOfDocumentsNameHash, Memory_Experimental::kNumberOfDocumentsName },

                    { Memory_Experimental::kNumberOfExtensionsNameHash, Memory_Experimental::kNumberOfExtensionsName },

                    { Memory_Experimental::kNumberOfFramesNameHash, Memory_Experimental::kNumberOfFramesName },

                    { Memory_Experimental::kNumberOfLayoutObjectsNameHash, Memory_Experimental::kNumberOfLayoutObjectsName },

                    { Memory_Experimental::kNumberOfMojoHandlesNameHash, Memory_Experimental::kNumberOfMojoHandlesName },

                    { Memory_Experimental::kNumberOfNodesNameHash, Memory_Experimental::kNumberOfNodesName },

                    { Memory_Experimental::kNumberOfWebMediaPlayersNameHash, Memory_Experimental::kNumberOfWebMediaPlayersName },

                    { Memory_Experimental::kOmniboxSuggestionsNameHash, Memory_Experimental::kOmniboxSuggestionsName },

                    { Memory_Experimental::kPartitionAllocNameHash, Memory_Experimental::kPartitionAllocName },

                    { Memory_Experimental::kPartitionAlloc_AllocatedObjectsNameHash, Memory_Experimental::kPartitionAlloc_AllocatedObjectsName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferNameHash, Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_BufferNameHash, Memory_Experimental::kPartitionAlloc_Partitions_BufferName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_FastMallocNameHash, Memory_Experimental::kPartitionAlloc_Partitions_FastMallocName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_LayoutNameHash, Memory_Experimental::kPartitionAlloc_Partitions_LayoutName },

                    { Memory_Experimental::kPrivateMemoryFootprintNameHash, Memory_Experimental::kPrivateMemoryFootprintName },

                    { Memory_Experimental::kPrivateSwapFootprintNameHash, Memory_Experimental::kPrivateSwapFootprintName },

                    { Memory_Experimental::kProcessTypeNameHash, Memory_Experimental::kProcessTypeName },

                    { Memory_Experimental::kResidentNameHash, Memory_Experimental::kResidentName },

                    { Memory_Experimental::kSharedMemoryFootprintNameHash, Memory_Experimental::kSharedMemoryFootprintName },

                    { Memory_Experimental::kSiteStorageNameHash, Memory_Experimental::kSiteStorageName },

                    { Memory_Experimental::kSiteStorage_BlobStorageNameHash, Memory_Experimental::kSiteStorage_BlobStorageName },

                    { Memory_Experimental::kSiteStorage_IndexDBNameHash, Memory_Experimental::kSiteStorage_IndexDBName },

                    { Memory_Experimental::kSiteStorage_LocalStorageNameHash, Memory_Experimental::kSiteStorage_LocalStorageName },

                    { Memory_Experimental::kSiteStorage_SessionStorageNameHash, Memory_Experimental::kSiteStorage_SessionStorageName },

                    { Memory_Experimental::kSkiaNameHash, Memory_Experimental::kSkiaName },

                    { Memory_Experimental::kSkia_SkGlyphCacheNameHash, Memory_Experimental::kSkia_SkGlyphCacheName },

                    { Memory_Experimental::kSkia_SkResourceCacheNameHash, Memory_Experimental::kSkia_SkResourceCacheName },

                    { Memory_Experimental::kSqliteNameHash, Memory_Experimental::kSqliteName },

                    { Memory_Experimental::kSyncNameHash, Memory_Experimental::kSyncName },

                    { Memory_Experimental::kTabRestoreNameHash, Memory_Experimental::kTabRestoreName },

                    { Memory_Experimental::kTimeSinceLastNavigationNameHash, Memory_Experimental::kTimeSinceLastNavigationName },

                    { Memory_Experimental::kTimeSinceLastVisibilityChangeNameHash, Memory_Experimental::kTimeSinceLastVisibilityChangeName },

                    { Memory_Experimental::kTotal2_PrivateMemoryFootprintNameHash, Memory_Experimental::kTotal2_PrivateMemoryFootprintName },

                    { Memory_Experimental::kTotal2_SharedMemoryFootprintNameHash, Memory_Experimental::kTotal2_SharedMemoryFootprintName },

                    { Memory_Experimental::kUINameHash, Memory_Experimental::kUIName },

                    { Memory_Experimental::kUptimeNameHash, Memory_Experimental::kUptimeName },

                    { Memory_Experimental::kV8NameHash, Memory_Experimental::kV8Name },

                    { Memory_Experimental::kV8_AllocatedObjectsNameHash, Memory_Experimental::kV8_AllocatedObjectsName },

                    { Memory_Experimental::kV8_MainNameHash, Memory_Experimental::kV8_MainName },

                    { Memory_Experimental::kV8_Main_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_GlobalHandlesNameHash, Memory_Experimental::kV8_Main_GlobalHandlesName },

                    { Memory_Experimental::kV8_Main_GlobalHandles_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_GlobalHandles_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_HeapNameHash, Memory_Experimental::kV8_Main_HeapName },

                    { Memory_Experimental::kV8_Main_Heap_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_CodeSpaceNameHash, Memory_Experimental::kV8_Main_Heap_CodeSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_MapSpaceNameHash, Memory_Experimental::kV8_Main_Heap_MapSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_NewSpaceNameHash, Memory_Experimental::kV8_Main_Heap_NewSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_OldSpaceNameHash, Memory_Experimental::kV8_Main_Heap_OldSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceNameHash, Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceName },

                    { Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_SharedLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_SharedLargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_SharedLargeObjectSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_SharedLargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_SharedSpaceNameHash, Memory_Experimental::kV8_Main_Heap_SharedSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_SharedSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_SharedSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_MallocNameHash, Memory_Experimental::kV8_Main_MallocName },

                    { Memory_Experimental::kV8_WorkersNameHash, Memory_Experimental::kV8_WorkersName },

                    { Memory_Experimental::kV8_Workers_AllocatedObjectsNameHash, Memory_Experimental::kV8_Workers_AllocatedObjectsName },

                    { Memory_Experimental::kWebCacheNameHash, Memory_Experimental::kWebCacheName },

                    { Memory_Experimental::kWebCache_CSSStylesheetResourcesNameHash, Memory_Experimental::kWebCache_CSSStylesheetResourcesName },

                    { Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash,
                        Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsName },

                    { Memory_Experimental::kWebCache_FontResourcesNameHash, Memory_Experimental::kWebCache_FontResourcesName },

                    { Memory_Experimental::kWebCache_ImageResourcesNameHash, Memory_Experimental::kWebCache_ImageResourcesName },

                    { Memory_Experimental::kWebCache_OtherResourcesNameHash, Memory_Experimental::kWebCache_OtherResourcesName },

                    { Memory_Experimental::kWebCache_ScriptResourcesNameHash, Memory_Experimental::kWebCache_ScriptResourcesName },

                    { Memory_Experimental::kWebCache_V8CodeCacheNameHash, Memory_Experimental::kWebCache_V8CodeCacheName },

                    { Memory_Experimental::kWebCache_XSLStylesheetResourcesNameHash, Memory_Experimental::kWebCache_XSLStylesheetResourcesName },

                    { Memory_Experimental::kWebMediaPlayer_AudioNameHash, Memory_Experimental::kWebMediaPlayer_AudioName },

                    { Memory_Experimental::kWebMediaPlayer_DataSourceNameHash, Memory_Experimental::kWebMediaPlayer_DataSourceName },

                    { Memory_Experimental::kWebMediaPlayer_DemuxerNameHash, Memory_Experimental::kWebMediaPlayer_DemuxerName },

                    { Memory_Experimental::kWebMediaPlayer_VideoNameHash, Memory_Experimental::kWebMediaPlayer_VideoName },

                } } },

        { UINT64_C(12430751894188593646),
            { Memory_TabFootprint::kEntryName,
                {

                    { Memory_TabFootprint::kMainFrameProcessPMFNameHash, Memory_TabFootprint::kMainFrameProcessPMFName },

                    { Memory_TabFootprint::kSubFrameProcessPMF_ExcludedNameHash, Memory_TabFootprint::kSubFrameProcessPMF_ExcludedName },

                    { Memory_TabFootprint::kSubFrameProcessPMF_IncludedNameHash, Memory_TabFootprint::kSubFrameProcessPMF_IncludedName },

                    { Memory_TabFootprint::kSubFrameProcessPMF_TotalNameHash, Memory_TabFootprint::kSubFrameProcessPMF_TotalName },

                    { Memory_TabFootprint::kTabPMFNameHash, Memory_TabFootprint::kTabPMFName },

                } } },

        { UINT64_C(9946364510678884885),
            { MixedContentAutoupgrade_ResourceRequest::kEntryName,
                {

                    { MixedContentAutoupgrade_ResourceRequest::kCodeNameHash, MixedContentAutoupgrade_ResourceRequest::kCodeName },

                    { MixedContentAutoupgrade_ResourceRequest::kStatusNameHash, MixedContentAutoupgrade_ResourceRequest::kStatusName },

                } } },

        { UINT64_C(2031262019788538998),
            { MobileFriendliness::kEntryName,
                {

                    { MobileFriendliness::kAllowUserZoomNameHash, MobileFriendliness::kAllowUserZoomName },

                    { MobileFriendliness::kSmallTextRatioNameHash, MobileFriendliness::kSmallTextRatioName },

                    { MobileFriendliness::kTextContentOutsideViewportPercentageNameHash, MobileFriendliness::kTextContentOutsideViewportPercentageName },

                    { MobileFriendliness::kViewportDeviceWidthNameHash, MobileFriendliness::kViewportDeviceWidthName },

                    { MobileFriendliness::kViewportHardcodedWidthNameHash, MobileFriendliness::kViewportHardcodedWidthName },

                    { MobileFriendliness::kViewportInitialScaleX10NameHash, MobileFriendliness::kViewportInitialScaleX10Name },

                } } },

        { UINT64_C(4279746797929370611),
            { MobileFriendliness_TappedBadTargets::kEntryName,
                {

                    { MobileFriendliness_TappedBadTargets::kCloseDisplayEdgeNameHash, MobileFriendliness_TappedBadTargets::kCloseDisplayEdgeName },

                    { MobileFriendliness_TappedBadTargets::kHighlyZoomedNameHash, MobileFriendliness_TappedBadTargets::kHighlyZoomedName },

                    { MobileFriendliness_TappedBadTargets::kTooCloseNameHash, MobileFriendliness_TappedBadTargets::kTooCloseName },

                    { MobileFriendliness_TappedBadTargets::kTooSmallNameHash, MobileFriendliness_TappedBadTargets::kTooSmallName },

                    { MobileFriendliness_TappedBadTargets::kZoomedNameHash, MobileFriendliness_TappedBadTargets::kZoomedName },

                } } },

        { UINT64_C(10323656781780570903),
            { MobileMenu_DirectShare::kEntryName,
                {

                    { MobileMenu_DirectShare::kHasOccurredNameHash, MobileMenu_DirectShare::kHasOccurredName },

                } } },

        { UINT64_C(317096594738729330),
            { MobileMenu_FindInPage::kEntryName,
                {

                    { MobileMenu_FindInPage::kHasOccurredNameHash, MobileMenu_FindInPage::kHasOccurredName },

                } } },

        { UINT64_C(16632756802456473210),
            { MobileMenu_Share::kEntryName,
                {

                    { MobileMenu_Share::kHasOccurredNameHash, MobileMenu_Share::kHasOccurredName },

                } } },

        { UINT64_C(12118541746267936631),
            { Navigation_IDNA2008Transition::kEntryName,
                {

                    { Navigation_IDNA2008Transition::kCharacterNameHash, Navigation_IDNA2008Transition::kCharacterName },

                } } },

        { UINT64_C(8202605063367714792),
            { Navigation_ReceivedResponse::kEntryName,
                {

                    { Navigation_ReceivedResponse::kHasAcceptCHFrameNameHash, Navigation_ReceivedResponse::kHasAcceptCHFrameName },

                    { Navigation_ReceivedResponse::kNavigationFirstResponseLatencyNameHash, Navigation_ReceivedResponse::kNavigationFirstResponseLatencyName },

                } } },

        { UINT64_C(4064735116116070675),
            { NavigationPredictorAnchorElementMetrics::kEntryName,
                {

                    { NavigationPredictorAnchorElementMetrics::kAnchorIndexNameHash, NavigationPredictorAnchorElementMetrics::kAnchorIndexName },

                    { NavigationPredictorAnchorElementMetrics::kBucketedPathHashNameHash, NavigationPredictorAnchorElementMetrics::kBucketedPathHashName },

                    { NavigationPredictorAnchorElementMetrics::kContainsImageNameHash, NavigationPredictorAnchorElementMetrics::kContainsImageName },

                    { NavigationPredictorAnchorElementMetrics::kFontSizeNameHash, NavigationPredictorAnchorElementMetrics::kFontSizeName },

                    { NavigationPredictorAnchorElementMetrics::kHasTextSiblingNameHash, NavigationPredictorAnchorElementMetrics::kHasTextSiblingName },

                    { NavigationPredictorAnchorElementMetrics::kIsBoldNameHash, NavigationPredictorAnchorElementMetrics::kIsBoldName },

                    { NavigationPredictorAnchorElementMetrics::kIsInIframeNameHash, NavigationPredictorAnchorElementMetrics::kIsInIframeName },

                    { NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneNameHash,
                        NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneName },

                    { NavigationPredictorAnchorElementMetrics::kNavigationStartToLinkLoggedMsNameHash,
                        NavigationPredictorAnchorElementMetrics::kNavigationStartToLinkLoggedMsName },

                    { NavigationPredictorAnchorElementMetrics::kPathDepthNameHash, NavigationPredictorAnchorElementMetrics::kPathDepthName },

                    { NavigationPredictorAnchorElementMetrics::kPathLengthNameHash, NavigationPredictorAnchorElementMetrics::kPathLengthName },

                    { NavigationPredictorAnchorElementMetrics::kPercentClickableAreaNameHash,
                        NavigationPredictorAnchorElementMetrics::kPercentClickableAreaName },

                    { NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceNameHash,
                        NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceName },

                    { NavigationPredictorAnchorElementMetrics::kSameOriginNameHash, NavigationPredictorAnchorElementMetrics::kSameOriginName },

                } } },

        { UINT64_C(10775915644707889889),
            { NavigationPredictorPageLinkClick::kEntryName,
                {

                    { NavigationPredictorPageLinkClick::kAnchorElementIndexNameHash, NavigationPredictorPageLinkClick::kAnchorElementIndexName },

                    { NavigationPredictorPageLinkClick::kHrefUnchangedNameHash, NavigationPredictorPageLinkClick::kHrefUnchangedName },

                    { NavigationPredictorPageLinkClick::kNavigationStartToLinkClickedMsNameHash,
                        NavigationPredictorPageLinkClick::kNavigationStartToLinkClickedMsName },

                } } },

        { UINT64_C(367468233168747720),
            { NavigationPredictorPageLinkMetrics::kEntryName,
                {

                    { NavigationPredictorPageLinkMetrics::kMedianLinkLocationNameHash, NavigationPredictorPageLinkMetrics::kMedianLinkLocationName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageNameHash,
                        NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeNameHash,
                        NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostNameHash,
                        NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedNameHash,
                        NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedName },

                    { NavigationPredictorPageLinkMetrics::kTotalClickableSpaceNameHash, NavigationPredictorPageLinkMetrics::kTotalClickableSpaceName },

                    { NavigationPredictorPageLinkMetrics::kViewport_HeightNameHash, NavigationPredictorPageLinkMetrics::kViewport_HeightName },

                    { NavigationPredictorPageLinkMetrics::kViewport_WidthNameHash, NavigationPredictorPageLinkMetrics::kViewport_WidthName },

                } } },

        { UINT64_C(4551066950181678222),
            { NavigationPredictorPreloadOnHover::kEntryName,
                {

                    { NavigationPredictorPreloadOnHover::kHoverNotTakenMsNameHash, NavigationPredictorPreloadOnHover::kHoverNotTakenMsName },

                    { NavigationPredictorPreloadOnHover::kHoverTakenMsNameHash, NavigationPredictorPreloadOnHover::kHoverTakenMsName },

                    { NavigationPredictorPreloadOnHover::kMouseDownNotTakenMsNameHash, NavigationPredictorPreloadOnHover::kMouseDownNotTakenMsName },

                    { NavigationPredictorPreloadOnHover::kMouseDownTakenMsNameHash, NavigationPredictorPreloadOnHover::kMouseDownTakenMsName },

                } } },

        { UINT64_C(5906381251666152842),
            { NavigationPredictorUserInteractions::kEntryName,
                {

                    { NavigationPredictorUserInteractions::kAnchorIndexNameHash, NavigationPredictorUserInteractions::kAnchorIndexName },

                    { NavigationPredictorUserInteractions::kDistanceFromLastPointerDownNameHash,
                        NavigationPredictorUserInteractions::kDistanceFromLastPointerDownName },

                    { NavigationPredictorUserInteractions::kEnteredViewportCountNameHash, NavigationPredictorUserInteractions::kEnteredViewportCountName },

                    { NavigationPredictorUserInteractions::kIsInViewportNameHash, NavigationPredictorUserInteractions::kIsInViewportName },

                    { NavigationPredictorUserInteractions::kIsPointerHoveringOverNameHash, NavigationPredictorUserInteractions::kIsPointerHoveringOverName },

                    { NavigationPredictorUserInteractions::kMaxEnteredViewportToLeftViewportMsNameHash,
                        NavigationPredictorUserInteractions::kMaxEnteredViewportToLeftViewportMsName },

                    { NavigationPredictorUserInteractions::kMaxHoverDwellTimeMsNameHash, NavigationPredictorUserInteractions::kMaxHoverDwellTimeMsName },

                    { NavigationPredictorUserInteractions::kMouseAccelerationNameHash, NavigationPredictorUserInteractions::kMouseAccelerationName },

                    { NavigationPredictorUserInteractions::kMouseVelocityNameHash, NavigationPredictorUserInteractions::kMouseVelocityName },

                    { NavigationPredictorUserInteractions::kPointerHoveringOverCountNameHash,
                        NavigationPredictorUserInteractions::kPointerHoveringOverCountName },

                    { NavigationPredictorUserInteractions::kVerticalPositionInViewportNameHash,
                        NavigationPredictorUserInteractions::kVerticalPositionInViewportName },

                } } },

        { UINT64_C(6971828606222010244),
            { NavigationRequestBreakDown::kEntryName,
                {

                    { NavigationRequestBreakDown::kBeginNavigationToLoaderStartNameHash, NavigationRequestBreakDown::kBeginNavigationToLoaderStartName },

                    { NavigationRequestBreakDown::kLoaderStartToReceiveResponseNameHash, NavigationRequestBreakDown::kLoaderStartToReceiveResponseName },

                    { NavigationRequestBreakDown::kNavigationStartToBeginNavigationNameHash,
                        NavigationRequestBreakDown::kNavigationStartToBeginNavigationName },

                    { NavigationRequestBreakDown::kReceiveResponseToCommitNavigationNameHash,
                        NavigationRequestBreakDown::kReceiveResponseToCommitNavigationName },

                } } },

        { UINT64_C(11162965141345650317),
            { NavigationThrottleDeferredTime::kEntryName,
                {

                    { NavigationThrottleDeferredTime::kDurationOfNavigationDeferralMsNameHash,
                        NavigationThrottleDeferredTime::kDurationOfNavigationDeferralMsName },

                    { NavigationThrottleDeferredTime::kNavigationThrottleEventTypeNameHash, NavigationThrottleDeferredTime::kNavigationThrottleEventTypeName },

                    { NavigationThrottleDeferredTime::kNavigationThrottleNameHashNameHash, NavigationThrottleDeferredTime::kNavigationThrottleNameHashName },

                } } },

        { UINT64_C(10253825785463205218),
            { NavigationTiming::kEntryName,
                {

                    { NavigationTiming::kFinalLoaderCallbackNameHash, NavigationTiming::kFinalLoaderCallbackName },

                    { NavigationTiming::kFinalRequestStartNameHash, NavigationTiming::kFinalRequestStartName },

                    { NavigationTiming::kFinalResponseStartNameHash, NavigationTiming::kFinalResponseStartName },

                    { NavigationTiming::kFirstLoaderCallbackNameHash, NavigationTiming::kFirstLoaderCallbackName },

                    { NavigationTiming::kFirstRequestStartNameHash, NavigationTiming::kFirstRequestStartName },

                    { NavigationTiming::kFirstResponseStartNameHash, NavigationTiming::kFirstResponseStartName },

                    { NavigationTiming::kNavigationCommitSentNameHash, NavigationTiming::kNavigationCommitSentName },

                } } },

        { UINT64_C(11843839735896046781),
            { Network_DataUrls::kEntryName,
                {

                    { Network_DataUrls::kIsImageNameHash, Network_DataUrls::kIsImageName },

                    { Network_DataUrls::kParseTimeNameHash, Network_DataUrls::kParseTimeName },

                    { Network_DataUrls::kUrlLengthNameHash, Network_DataUrls::kUrlLengthName },

                } } },

        { UINT64_C(559094208615510931),
            { NewTabPage_HistoryClusters::kEntryName,
                {

                    { NewTabPage_HistoryClusters::kBelongsToBoostedCategoryNameHash, NewTabPage_HistoryClusters::kBelongsToBoostedCategoryName },

                    { NewTabPage_HistoryClusters::kBelongsToMostSeenCategoryNameHash, NewTabPage_HistoryClusters::kBelongsToMostSeenCategoryName },

                    { NewTabPage_HistoryClusters::kBelongsToMostUsedCategoryNameHash, NewTabPage_HistoryClusters::kBelongsToMostUsedCategoryName },

                    { NewTabPage_HistoryClusters::kDidDisableModuleNameHash, NewTabPage_HistoryClusters::kDidDisableModuleName },

                    { NewTabPage_HistoryClusters::kDidDismissModuleNameHash, NewTabPage_HistoryClusters::kDidDismissModuleName },

                    { NewTabPage_HistoryClusters::kDidEngageWithModuleNameHash, NewTabPage_HistoryClusters::kDidEngageWithModuleName },

                    { NewTabPage_HistoryClusters::kDidMarkAsDoneNameHash, NewTabPage_HistoryClusters::kDidMarkAsDoneName },

                    { NewTabPage_HistoryClusters::kLayoutTypeShownNameHash, NewTabPage_HistoryClusters::kLayoutTypeShownName },

                    { NewTabPage_HistoryClusters::kMinutesSinceMostRecentVisitNameHash, NewTabPage_HistoryClusters::kMinutesSinceMostRecentVisitName },

                    { NewTabPage_HistoryClusters::kMostFrequentSeenCategoryCountNameHash, NewTabPage_HistoryClusters::kMostFrequentSeenCategoryCountName },

                    { NewTabPage_HistoryClusters::kMostFrequentUsedCategoryCountNameHash, NewTabPage_HistoryClusters::kMostFrequentUsedCategoryCountName },

                    { NewTabPage_HistoryClusters::kNumAbandonedCartsNameHash, NewTabPage_HistoryClusters::kNumAbandonedCartsName },

                    { NewTabPage_HistoryClusters::kNumAssociatedCategoriesNameHash, NewTabPage_HistoryClusters::kNumAssociatedCategoriesName },

                    { NewTabPage_HistoryClusters::kNumTimesSeenLast24hNameHash, NewTabPage_HistoryClusters::kNumTimesSeenLast24hName },

                    { NewTabPage_HistoryClusters::kNumTimesUsedLast24hNameHash, NewTabPage_HistoryClusters::kNumTimesUsedLast24hName },

                    { NewTabPage_HistoryClusters::kNumTotalVisitsNameHash, NewTabPage_HistoryClusters::kNumTotalVisitsName },

                    { NewTabPage_HistoryClusters::kNumUniqueHostsNameHash, NewTabPage_HistoryClusters::kNumUniqueHostsName },

                    { NewTabPage_HistoryClusters::kNumVisitsWithImageNameHash, NewTabPage_HistoryClusters::kNumVisitsWithImageName },

                } } },

        { UINT64_C(5007192410804132260),
            { NoStatePrefetch::kEntryName,
                {

                    { NoStatePrefetch::kPrefetchedRecently_FinalStatusNameHash, NoStatePrefetch::kPrefetchedRecently_FinalStatusName },

                    { NoStatePrefetch::kPrefetchedRecently_OriginNameHash, NoStatePrefetch::kPrefetchedRecently_OriginName },

                    { NoStatePrefetch::kPrefetchedRecently_PrefetchAgeNameHash, NoStatePrefetch::kPrefetchedRecently_PrefetchAgeName },

                } } },

        { UINT64_C(10867195639280438101),
            { Notification::kEntryName,
                {

                    { Notification::kClosedReasonNameHash, Notification::kClosedReasonName },

                    { Notification::kDidReplaceAnotherNotificationNameHash, Notification::kDidReplaceAnotherNotificationName },

                    { Notification::kDidUserOpenSettingsNameHash, Notification::kDidUserOpenSettingsName },

                    { Notification::kHasBadgeNameHash, Notification::kHasBadgeName },

                    { Notification::kHasIconNameHash, Notification::kHasIconName },

                    { Notification::kHasImageNameHash, Notification::kHasImageName },

                    { Notification::kHasRenotifyNameHash, Notification::kHasRenotifyName },

                    { Notification::kHasTagNameHash, Notification::kHasTagName },

                    { Notification::kIsSilentNameHash, Notification::kIsSilentName },

                    { Notification::kNumActionButtonClicksNameHash, Notification::kNumActionButtonClicksName },

                    { Notification::kNumActionsNameHash, Notification::kNumActionsName },

                    { Notification::kNumClicksNameHash, Notification::kNumClicksName },

                    { Notification::kRequireInteractionNameHash, Notification::kRequireInteractionName },

                    { Notification::kTimeUntilCloseNameHash, Notification::kTimeUntilCloseName },

                    { Notification::kTimeUntilFirstClickNameHash, Notification::kTimeUntilFirstClickName },

                    { Notification::kTimeUntilLastClickNameHash, Notification::kTimeUntilLastClickName },

                } } },

        { UINT64_C(4133441977341793352),
            { Omnibox_EditUrlSuggestion_Share::kEntryName,
                {

                    { Omnibox_EditUrlSuggestion_Share::kHasOccurredNameHash, Omnibox_EditUrlSuggestion_Share::kHasOccurredName },

                } } },

        { UINT64_C(410068635758492342),
            { Omnibox_SuggestionUsed::kEntryName,
                {

                    { Omnibox_SuggestionUsed::kResultTypeNameHash, Omnibox_SuggestionUsed::kResultTypeName },

                } } },

        { UINT64_C(2638435285752584045),
            { OmniboxSecurityIndicator_FormSubmission::kEntryName,
                {

                    { OmniboxSecurityIndicator_FormSubmission::kSubmittedNameHash, OmniboxSecurityIndicator_FormSubmission::kSubmittedName },

                } } },

        { UINT64_C(9673748521109117539),
            { OpenerHeuristic_PopupInteraction::kEntryName,
                {

                    { OpenerHeuristic_PopupInteraction::kOpenerHasSameSiteIframeNameHash, OpenerHeuristic_PopupInteraction::kOpenerHasSameSiteIframeName },

                    { OpenerHeuristic_PopupInteraction::kPopupIdNameHash, OpenerHeuristic_PopupInteraction::kPopupIdName },

                    { OpenerHeuristic_PopupInteraction::kSecondsSinceCommittedNameHash, OpenerHeuristic_PopupInteraction::kSecondsSinceCommittedName },

                    { OpenerHeuristic_PopupInteraction::kUrlIndexNameHash, OpenerHeuristic_PopupInteraction::kUrlIndexName },

                } } },

        { UINT64_C(284944213972750594),
            { OpenerHeuristic_PopupPastInteraction::kEntryName,
                {

                    { OpenerHeuristic_PopupPastInteraction::kHoursSinceLastInteractionNameHash,
                        OpenerHeuristic_PopupPastInteraction::kHoursSinceLastInteractionName },

                    { OpenerHeuristic_PopupPastInteraction::kOpenerHasSameSiteIframeNameHash,
                        OpenerHeuristic_PopupPastInteraction::kOpenerHasSameSiteIframeName },

                    { OpenerHeuristic_PopupPastInteraction::kPopupIdNameHash, OpenerHeuristic_PopupPastInteraction::kPopupIdName },

                } } },

        { UINT64_C(3100647281250124680),
            { OpenerHeuristic_PostPopupCookieAccess::kEntryName,
                {

                    { OpenerHeuristic_PostPopupCookieAccess::kAccessIdNameHash, OpenerHeuristic_PostPopupCookieAccess::kAccessIdName },

                    { OpenerHeuristic_PostPopupCookieAccess::kAccessSucceededNameHash, OpenerHeuristic_PostPopupCookieAccess::kAccessSucceededName },

                    { OpenerHeuristic_PostPopupCookieAccess::kHoursSincePopupOpenedNameHash,
                        OpenerHeuristic_PostPopupCookieAccess::kHoursSincePopupOpenedName },

                    { OpenerHeuristic_PostPopupCookieAccess::kIsAdTaggedNameHash, OpenerHeuristic_PostPopupCookieAccess::kIsAdTaggedName },

                } } },

        { UINT64_C(7387506176392750000),
            { OpenerHeuristic_TopLevel::kEntryName,
                {

                    { OpenerHeuristic_TopLevel::kAccessIdNameHash, OpenerHeuristic_TopLevel::kAccessIdName },

                    { OpenerHeuristic_TopLevel::kHasSameSiteIframeNameHash, OpenerHeuristic_TopLevel::kHasSameSiteIframeName },

                    { OpenerHeuristic_TopLevel::kIsAdTaggedPopupClickNameHash, OpenerHeuristic_TopLevel::kIsAdTaggedPopupClickName },

                    { OpenerHeuristic_TopLevel::kPopupIdNameHash, OpenerHeuristic_TopLevel::kPopupIdName },

                    { OpenerHeuristic_TopLevel::kPopupProviderNameHash, OpenerHeuristic_TopLevel::kPopupProviderName },

                } } },

        { UINT64_C(2087579403365801585),
            { OptimizationGuide::kEntryName,
                {

                    { OptimizationGuide::kNavigationHintsFetchAttemptStatusNameHash, OptimizationGuide::kNavigationHintsFetchAttemptStatusName },

                    { OptimizationGuide::kNavigationHintsFetchRequestLatencyNameHash, OptimizationGuide::kNavigationHintsFetchRequestLatencyName },

                    { OptimizationGuide::kRegisteredOptimizationTargetsNameHash, OptimizationGuide::kRegisteredOptimizationTargetsName },

                    { OptimizationGuide::kRegisteredOptimizationTypesNameHash, OptimizationGuide::kRegisteredOptimizationTypesName },

                } } },

        { UINT64_C(3675683766249774286),
            { PageContentAnnotations2::kEntryName,
                {

                    { PageContentAnnotations2::kVisibilityScoreNameHash, PageContentAnnotations2::kVisibilityScoreName },

                } } },

        { UINT64_C(12853622770478513093),
            { PageDomainInfo::kEntryName,
                {

                    { PageDomainInfo::kDomainTypeNameHash, PageDomainInfo::kDomainTypeName },

                } } },

        { UINT64_C(14423022965050986312),
            { PageForegroundSession::kEntryName,
                {

                    { PageForegroundSession::kForegroundDurationNameHash, PageForegroundSession::kForegroundDurationName },

                    { PageForegroundSession::kForegroundTotalInputDelayNameHash, PageForegroundSession::kForegroundTotalInputDelayName },

                } } },

        { UINT64_C(10171644723325805171),
            { PageInfoBubble::kEntryName,
                {

                    { PageInfoBubble::kActionTakenNameHash, PageInfoBubble::kActionTakenName },

                } } },

        { UINT64_C(12426032810838168341),
            { PageLoad::kEntryName,
                {

                    { PageLoad::kCpuTimeNameHash, PageLoad::kCpuTimeName },

                    { PageLoad::kDayOfWeekNameHash, PageLoad::kDayOfWeekName },

                    { PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash,
                        PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredName },

                    { PageLoad::kDocumentTiming_NavigationToLoadEventFiredNameHash, PageLoad::kDocumentTiming_NavigationToLoadEventFiredName },

                    { PageLoad::kDurationSinceLastVisitSecondsNameHash, PageLoad::kDurationSinceLastVisitSecondsName },

                    { PageLoad::kExperimental_InputToNavigationStartNameHash, PageLoad::kExperimental_InputToNavigationStartName },

                    { PageLoad::kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenNameHash,
                        PageLoad::kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenName },

                    { PageLoad::kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PageLoad::kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msName },

                    { PageLoad::kExperimental_Navigation_UserInitiatedNameHash, PageLoad::kExperimental_Navigation_UserInitiatedName },

                    { PageLoad::kExperimental_TotalForegroundDurationNameHash, PageLoad::kExperimental_TotalForegroundDurationName },

                    { PageLoad::kHourOfDayNameHash, PageLoad::kHourOfDayName },

                    { PageLoad::kInteractiveTiming_FirstInputDelay4NameHash, PageLoad::kInteractiveTiming_FirstInputDelay4Name },

                    { PageLoad::kInteractiveTiming_FirstInputTimestamp4NameHash, PageLoad::kInteractiveTiming_FirstInputTimestamp4Name },

                    { PageLoad::kInteractiveTiming_FirstScrollDelayNameHash, PageLoad::kInteractiveTiming_FirstScrollDelayName },

                    { PageLoad::kInteractiveTiming_FirstScrollTimestampNameHash, PageLoad::kInteractiveTiming_FirstScrollTimestampName },

                    { PageLoad::kInteractiveTiming_INPOffsetNameHash, PageLoad::kInteractiveTiming_INPOffsetName },

                    { PageLoad::kInteractiveTiming_INPTimeNameHash, PageLoad::kInteractiveTiming_INPTimeName },

                    { PageLoad::kInteractiveTiming_NumInteractionsNameHash, PageLoad::kInteractiveTiming_NumInteractionsName },

                    { PageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName },

                    { PageLoad::kInteractiveTimingBeforeSoftNavigation_INPOffsetNameHash, PageLoad::kInteractiveTimingBeforeSoftNavigation_INPOffsetName },

                    { PageLoad::kInteractiveTimingBeforeSoftNavigation_INPTimeNameHash, PageLoad::kInteractiveTimingBeforeSoftNavigation_INPTimeName },

                    { PageLoad::kInteractiveTimingBeforeSoftNavigation_NumInteractionsNameHash,
                        PageLoad::kInteractiveTimingBeforeSoftNavigation_NumInteractionsName },

                    { PageLoad::kInteractiveTimingBeforeSoftNavigation_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTimingBeforeSoftNavigation_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { PageLoad::kIsCrossProcessNavigationNameHash, PageLoad::kIsCrossProcessNavigationName },

                    { PageLoad::kIsExistingBookmarkNameHash, PageLoad::kIsExistingBookmarkName },

                    { PageLoad::kIsExistingPartOfTabGroupNameHash, PageLoad::kIsExistingPartOfTabGroupName },

                    { PageLoad::kIsNewBookmarkNameHash, PageLoad::kIsNewBookmarkName },

                    { PageLoad::kIsNTPCustomLinkNameHash, PageLoad::kIsNTPCustomLinkName },

                    { PageLoad::kIsPlacedInTabGroupNameHash, PageLoad::kIsPlacedInTabGroupName },

                    { PageLoad::kIsScopedSearchLikeNavigationNameHash, PageLoad::kIsScopedSearchLikeNavigationName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScoreNameHash, PageLoad::kLayoutInstability_CumulativeShiftScoreName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash,
                        PageLoad::kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameNameHash, PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash,
                        PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName },

                    { PageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { PageLoad::kLayoutInstabilityBeforeSoftNavigation_MaxCumulativeShiftScore_MainFrame_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PageLoad::kLayoutInstabilityBeforeSoftNavigation_MaxCumulativeShiftScore_MainFrame_SessionWindow_Gap1000ms_Max5000msName },

                    { PageLoad::kMainDocumentSequenceNumberNameHash, PageLoad::kMainDocumentSequenceNumberName },

                    { PageLoad::kMainFrameResource_ConnectDelayNameHash, PageLoad::kMainFrameResource_ConnectDelayName },

                    { PageLoad::kMainFrameResource_DNSDelayNameHash, PageLoad::kMainFrameResource_DNSDelayName },

                    { PageLoad::kMainFrameResource_HttpProtocolSchemeNameHash, PageLoad::kMainFrameResource_HttpProtocolSchemeName },

                    { PageLoad::kMainFrameResource_NavigationStartToConnectStartNameHash, PageLoad::kMainFrameResource_NavigationStartToConnectStartName },

                    { PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash,
                        PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartName },

                    { PageLoad::kMainFrameResource_NavigationStartToRequestStartNameHash, PageLoad::kMainFrameResource_NavigationStartToRequestStartName },

                    { PageLoad::kMainFrameResource_RedirectCountNameHash, PageLoad::kMainFrameResource_RedirectCountName },

                    { PageLoad::kMainFrameResource_RequestHadCookiesNameHash, PageLoad::kMainFrameResource_RequestHadCookiesName },

                    { PageLoad::kMainFrameResource_RequestHasNoStoreNameHash, PageLoad::kMainFrameResource_RequestHasNoStoreName },

                    { PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndNameHash, PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndName },

                    { PageLoad::kMainFrameResource_RequestStartToSendStartNameHash, PageLoad::kMainFrameResource_RequestStartToSendStartName },

                    { PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndNameHash, PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndName },

                    { PageLoad::kMainFrameResource_SocketReusedNameHash, PageLoad::kMainFrameResource_SocketReusedName },

                    { PageLoad::kNavigation_InitiatorLocationNameHash, PageLoad::kNavigation_InitiatorLocationName },

                    { PageLoad::kNavigation_PageEndReason3NameHash, PageLoad::kNavigation_PageEndReason3Name },

                    { PageLoad::kNavigation_PageTransitionNameHash, PageLoad::kNavigation_PageTransitionName },

                    { PageLoad::kNavigationEntryOffsetNameHash, PageLoad::kNavigationEntryOffsetName },

                    { PageLoad::kNet_CacheBytes2NameHash, PageLoad::kNet_CacheBytes2Name },

                    { PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash, PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartName },

                    { PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartNameHash, PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartName },

                    { PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadNameHash, PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadName },

                    { PageLoad::kNet_HttpResponseCodeNameHash, PageLoad::kNet_HttpResponseCodeName },

                    { PageLoad::kNet_HttpRttEstimate_OnNavigationStartNameHash, PageLoad::kNet_HttpRttEstimate_OnNavigationStartName },

                    { PageLoad::kNet_ImageBytes2NameHash, PageLoad::kNet_ImageBytes2Name },

                    { PageLoad::kNet_ImageSubframeBytes2NameHash, PageLoad::kNet_ImageSubframeBytes2Name },

                    { PageLoad::kNet_JavaScriptBytes2NameHash, PageLoad::kNet_JavaScriptBytes2Name },

                    { PageLoad::kNet_JavaScriptMaxBytes2NameHash, PageLoad::kNet_JavaScriptMaxBytes2Name },

                    { PageLoad::kNet_MediaBytes2NameHash, PageLoad::kNet_MediaBytes2Name },

                    { PageLoad::kNet_NetworkBytes2NameHash, PageLoad::kNet_NetworkBytes2Name },

                    { PageLoad::kNet_TransportRttEstimate_OnNavigationStartNameHash, PageLoad::kNet_TransportRttEstimate_OnNavigationStartName },

                    { PageLoad::kOmniboxUrlCopiedNameHash, PageLoad::kOmniboxUrlCopiedName },

                    { PageLoad::kPageTiming_ForegroundDurationNameHash, PageLoad::kPageTiming_ForegroundDurationName },

                    { PageLoad::kPageTiming_NavigationToFailedProvisionalLoadNameHash, PageLoad::kPageTiming_NavigationToFailedProvisionalLoadName },

                    { PageLoad::kPageTiming_TotalForegroundDurationNameHash, PageLoad::kPageTiming_TotalForegroundDurationName },

                    { PageLoad::kPageTiming_UserTimingMarkFullyLoadedNameHash, PageLoad::kPageTiming_UserTimingMarkFullyLoadedName },

                    { PageLoad::kPageTiming_UserTimingMarkFullyVisibleNameHash, PageLoad::kPageTiming_UserTimingMarkFullyVisibleName },

                    { PageLoad::kPageTiming_UserTimingMarkInteractiveNameHash, PageLoad::kPageTiming_UserTimingMarkInteractiveName },

                    { PageLoad::kPageVisitFinalStatusNameHash, PageLoad::kPageVisitFinalStatusName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintBPPNameHash, PageLoad::kPaintTiming_LargestContentfulPaintBPPName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintImageDiscoveryTimeNameHash,
                        PageLoad::kPaintTiming_LargestContentfulPaintImageDiscoveryTimeName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintImageIsCrossOriginNameHash,
                        PageLoad::kPaintTiming_LargestContentfulPaintImageIsCrossOriginName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintImageLoadEndNameHash, PageLoad::kPaintTiming_LargestContentfulPaintImageLoadEndName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintImageLoadStartNameHash, PageLoad::kPaintTiming_LargestContentfulPaintImageLoadStartName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintRequestPriorityNameHash, PageLoad::kPaintTiming_LargestContentfulPaintRequestPriorityName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintTypeNameHash, PageLoad::kPaintTiming_LargestContentfulPaintTypeName },

                    { PageLoad::kPaintTiming_NavigationToFirstContentfulPaintNameHash, PageLoad::kPaintTiming_NavigationToFirstContentfulPaintName },

                    { PageLoad::kPaintTiming_NavigationToFirstPaintNameHash, PageLoad::kPaintTiming_NavigationToFirstPaintName },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2NameHash, PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2Name },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameNameHash,
                        PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameName },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameNameHash,
                        PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameName },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenNameHash,
                        PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenName },

                    { PageLoad::kParseTiming_NavigationToParseStartNameHash, PageLoad::kParseTiming_NavigationToParseStartName },

                    { PageLoad::kRefreshRateThrottledNameHash, PageLoad::kRefreshRateThrottledName },

                    { PageLoad::kSiteEngagementScoreNameHash, PageLoad::kSiteEngagementScoreName },

                    { PageLoad::kSiteInstanceRenderProcessAssignmentNameHash, PageLoad::kSiteInstanceRenderProcessAssignmentName },

                    { PageLoad::kSoftNavigationCountNameHash, PageLoad::kSoftNavigationCountName },

                    { PageLoad::kThirdPartyCookieBlockingEnabledForSiteNameHash, PageLoad::kThirdPartyCookieBlockingEnabledForSiteName },

                    { PageLoad::kWasCachedNameHash, PageLoad::kWasCachedName },

                    { PageLoad::kWasDiscardedNameHash, PageLoad::kWasDiscardedName },

                } } },

        { UINT64_C(8384138607730558665),
            { PageLoad_FromGoogleSearch::kEntryName,
                {

                    { PageLoad_FromGoogleSearch::kGoogleSearchModeNameHash, PageLoad_FromGoogleSearch::kGoogleSearchModeName },

                } } },

        { UINT64_C(5441732143890651748),
            { PageLoad_Internal::kEntryName,
                {

                    { PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeNameHash,
                        PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeName },

                    { PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateNameHash,
                        PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateName },

                } } },

        { UINT64_C(11995268860284106764),
            { PageLoad_PervasivePayloadsEnabled::kEntryName,
                {

                } } },

        { UINT64_C(18067304287773255026),
            { PageLoad_ServiceWorkerControlled::kEntryName,
                {

                } } },

        { UINT64_C(14566014450078110818),
            { PageLoad_SignedExchange::kEntryName,
                {

                    { PageLoad_SignedExchange::kServedFromGoogleCacheNameHash, PageLoad_SignedExchange::kServedFromGoogleCacheName },

                } } },

        { UINT64_C(13210659676462006741),
            { PageLoadInitiatorForAdTagging::kEntryName,
                {

                    { PageLoadInitiatorForAdTagging::kFromAdClickNameHash, PageLoadInitiatorForAdTagging::kFromAdClickName },

                    { PageLoadInitiatorForAdTagging::kFromUserNameHash, PageLoadInitiatorForAdTagging::kFromUserName },

                } } },

        { UINT64_C(2493630448790526384),
            { PageWithPassword::kEntryName,
                {

                    { PageWithPassword::kFormManagerAvailableNameHash, PageWithPassword::kFormManagerAvailableName },

                    { PageWithPassword::kPageLevelUserActionNameHash, PageWithPassword::kPageLevelUserActionName },

                    { PageWithPassword::kProvisionalSaveFailureNameHash, PageWithPassword::kProvisionalSaveFailureName },

                    { PageWithPassword::kUserModifiedPasswordFieldNameHash, PageWithPassword::kUserModifiedPasswordFieldName },

                } } },

        { UINT64_C(1595630084981618121),
            { PaintPreviewCapture::kEntryName,
                {

                    { PaintPreviewCapture::kBlinkCaptureTimeNameHash, PaintPreviewCapture::kBlinkCaptureTimeName },

                    { PaintPreviewCapture::kCompressedOnDiskSizeNameHash, PaintPreviewCapture::kCompressedOnDiskSizeName },

                } } },

        { UINT64_C(9510248908405193837),
            { PartitionedCookiePresentV2::kEntryName,
                {

                    { PartitionedCookiePresentV2::kPartitionedCookiePresentV2NameHash, PartitionedCookiePresentV2::kPartitionedCookiePresentV2Name },

                } } },

        { UINT64_C(8060270586115376858),
            { PasswordForm::kEntryName,
                {

                    { PasswordForm::kClassificationCorrectness_ConfirmationPasswordNameHash,
                        PasswordForm::kClassificationCorrectness_ConfirmationPasswordName },

                    { PasswordForm::kClassificationCorrectness_CurrentPasswordNameHash, PasswordForm::kClassificationCorrectness_CurrentPasswordName },

                    { PasswordForm::kClassificationCorrectness_NewPasswordNameHash, PasswordForm::kClassificationCorrectness_NewPasswordName },

                    { PasswordForm::kClassificationCorrectness_UsernameNameHash, PasswordForm::kClassificationCorrectness_UsernameName },

                    { PasswordForm::kContext_FormSignatureNameHash, PasswordForm::kContext_FormSignatureName },

                    { PasswordForm::kDynamicFormChangesNameHash, PasswordForm::kDynamicFormChangesName },

                    { PasswordForm::kFill_FirstFillingResultInRendererNameHash, PasswordForm::kFill_FirstFillingResultInRendererName },

                    { PasswordForm::kFill_FirstWaitForUsernameReasonNameHash, PasswordForm::kFill_FirstWaitForUsernameReasonName },

                    { PasswordForm::kGeneration_GeneratedPasswordNameHash, PasswordForm::kGeneration_GeneratedPasswordName },

                    { PasswordForm::kGeneration_GeneratedPasswordModifiedNameHash, PasswordForm::kGeneration_GeneratedPasswordModifiedName },

                    { PasswordForm::kGeneration_PopupShownNameHash, PasswordForm::kGeneration_PopupShownName },

                    { PasswordForm::kManagerFill_ActionNameHash, PasswordForm::kManagerFill_ActionName },

                    { PasswordForm::kManagerFill_AssistanceNameHash, PasswordForm::kManagerFill_AssistanceName },

                    { PasswordForm::kManagerFill_AssistanceForSingleUsernameNameHash, PasswordForm::kManagerFill_AssistanceForSingleUsernameName },

                    { PasswordForm::kParsingDiffFillingAndSavingNameHash, PasswordForm::kParsingDiffFillingAndSavingName },

                    { PasswordForm::kReadonlyWhenFillingNameHash, PasswordForm::kReadonlyWhenFillingName },

                    { PasswordForm::kReadonlyWhenSavingNameHash, PasswordForm::kReadonlyWhenSavingName },

                    { PasswordForm::kSaving_Prompt_InteractionNameHash, PasswordForm::kSaving_Prompt_InteractionName },

                    { PasswordForm::kSaving_Prompt_ShownNameHash, PasswordForm::kSaving_Prompt_ShownName },

                    { PasswordForm::kSaving_Prompt_TriggerNameHash, PasswordForm::kSaving_Prompt_TriggerName },

                    { PasswordForm::kSaving_ShowedManualFallbackForSavingNameHash, PasswordForm::kSaving_ShowedManualFallbackForSavingName },

                    { PasswordForm::kSubmission_IndicatorNameHash, PasswordForm::kSubmission_IndicatorName },

                    { PasswordForm::kSubmission_ObservedNameHash, PasswordForm::kSubmission_ObservedName },

                    { PasswordForm::kSubmission_SubmissionResultNameHash, PasswordForm::kSubmission_SubmissionResultName },

                    { PasswordForm::kSubmission_SubmissionResult_GeneratedPasswordNameHash, PasswordForm::kSubmission_SubmissionResult_GeneratedPasswordName },

                    { PasswordForm::kSubmission_SubmittedFormType2NameHash, PasswordForm::kSubmission_SubmittedFormType2Name },

                    { PasswordForm::kUpdating_Prompt_InteractionNameHash, PasswordForm::kUpdating_Prompt_InteractionName },

                    { PasswordForm::kUpdating_Prompt_ShownNameHash, PasswordForm::kUpdating_Prompt_ShownName },

                    { PasswordForm::kUpdating_Prompt_TriggerNameHash, PasswordForm::kUpdating_Prompt_TriggerName },

                    { PasswordForm::kUser_Action_CorrectedUsernameInFormNameHash, PasswordForm::kUser_Action_CorrectedUsernameInFormName },

                    { PasswordForm::kUser_Action_EditedUsernameInBubbleNameHash, PasswordForm::kUser_Action_EditedUsernameInBubbleName },

                    { PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleNameHash, PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleName },

                    { PasswordForm::kUser_Action_TriggeredManualFallbackForSavingNameHash, PasswordForm::kUser_Action_TriggeredManualFallbackForSavingName },

                } } },

        { UINT64_C(1968976387895384760),
            { PasswordManager_FirstCCTPageLoad::kEntryName,
                {

                    { PasswordManager_FirstCCTPageLoad::kHasPasswordFormNameHash, PasswordManager_FirstCCTPageLoad::kHasPasswordFormName },

                } } },

        { UINT64_C(12997918245497021702),
            { PasswordManager_LeakWarningDialog::kEntryName,
                {

                    { PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogDismissalReasonNameHash,
                        PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogDismissalReasonName },

                    { PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogTypeNameHash,
                        PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogTypeName },

                } } },

        { UINT64_C(3312101392374499085),
            { PasswordManager_NewlySavedPassword::kEntryName,
                {

                    { PasswordManager_NewlySavedPassword::kHasEmptyUsernameNameHash, PasswordManager_NewlySavedPassword::kHasEmptyUsernameName },

                    { PasswordManager_NewlySavedPassword::kIsPasswordGeneratedNameHash, PasswordManager_NewlySavedPassword::kIsPasswordGeneratedName },

                } } },

        { UINT64_C(16550471355748170236),
            { PasswordManager_PasswordChangeTriggered::kEntryName,
                {

                    { PasswordManager_PasswordChangeTriggered::kPasswordChangeTypeNameHash, PasswordManager_PasswordChangeTriggered::kPasswordChangeTypeName },

                } } },

        { UINT64_C(5726428427092735799),
            { PasswordManager_PasswordFillingIOS::kEntryName,
                {

                    { PasswordManager_PasswordFillingIOS::kFillingSuccessNameHash, PasswordManager_PasswordFillingIOS::kFillingSuccessName },

                } } },

        { UINT64_C(2853752235848375735),
            { PasswordManager_SavedPassword::kEntryName,
                {

                    { PasswordManager_SavedPassword::kIsPasswordGeneratedNameHash, PasswordManager_SavedPassword::kIsPasswordGeneratedName },

                } } },

        { UINT64_C(8595641688177899640),
            { PasswordManager_WellKnownChangePasswordResult::kEntryName,
                {

                    { PasswordManager_WellKnownChangePasswordResult::kWellKnownChangePasswordResultNameHash,
                        PasswordManager_WellKnownChangePasswordResult::kWellKnownChangePasswordResultName },

                } } },

        { UINT64_C(702207440764833882),
            { PaymentApp_CheckoutEvents::kEntryName,
                {

                    { PaymentApp_CheckoutEvents::kCompletionStatusNameHash, PaymentApp_CheckoutEvents::kCompletionStatusName },

                    { PaymentApp_CheckoutEvents::kEvents2NameHash, PaymentApp_CheckoutEvents::kEvents2Name },

                } } },

        { UINT64_C(9066413457122162526),
            { PaymentRequest_CheckoutEvents::kEntryName,
                {

                    { PaymentRequest_CheckoutEvents::kCompletionStatusNameHash, PaymentRequest_CheckoutEvents::kCompletionStatusName },

                    { PaymentRequest_CheckoutEvents::kEvents2NameHash, PaymentRequest_CheckoutEvents::kEvents2Name },

                } } },

        { UINT64_C(4090736682116197688),
            { PaymentRequest_TransactionAmount::kEntryName,
                {

                    { PaymentRequest_TransactionAmount::kCategoryNameHash, PaymentRequest_TransactionAmount::kCategoryName },

                    { PaymentRequest_TransactionAmount::kCompletionStatusNameHash, PaymentRequest_TransactionAmount::kCompletionStatusName },

                } } },

        { UINT64_C(4863880088883807024),
            { Pepper_Broker::kEntryName,
                {

                } } },

        { UINT64_C(13281029919793825830),
            { PerformanceAPI_LongAnimationFrame::kEntryName,
                {

                    { PerformanceAPI_LongAnimationFrame::kCategorized3PScriptLongAnimationFrameCallbackContributorsNameHash,
                        PerformanceAPI_LongAnimationFrame::kCategorized3PScriptLongAnimationFrameCallbackContributorsName },

                    { PerformanceAPI_LongAnimationFrame::kCategorized3PScriptLongAnimationFrameScriptExecutionContributorsNameHash,
                        PerformanceAPI_LongAnimationFrame::kCategorized3PScriptLongAnimationFrameScriptExecutionContributorsName },

                    { PerformanceAPI_LongAnimationFrame::kDidPauseNameHash, PerformanceAPI_LongAnimationFrame::kDidPauseName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_DelayDeferNameHash, PerformanceAPI_LongAnimationFrame::kDuration_DelayDeferName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_EffectiveBlockingNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_EffectiveBlockingName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSCompilationNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSCompilationName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecutionNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecutionName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_EventListenersNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_EventListenersName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_PromiseHandlersNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_PromiseHandlersName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_ScriptBlocksNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_ScriptBlocksName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_UserCallbacksNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_LongScript_JSExecution_UserCallbacksName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_StyleAndLayout_ForcedNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_StyleAndLayout_ForcedName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_StyleAndLayout_RenderPhaseNameHash,
                        PerformanceAPI_LongAnimationFrame::kDuration_StyleAndLayout_RenderPhaseName },

                    { PerformanceAPI_LongAnimationFrame::kDuration_TotalNameHash, PerformanceAPI_LongAnimationFrame::kDuration_TotalName },

                } } },

        { UINT64_C(8942554384206766435),
            { PerformanceAPI_LongTask::kEntryName,
                {

                    { PerformanceAPI_LongTask::kDurationNameHash, PerformanceAPI_LongTask::kDurationName },

                    { PerformanceAPI_LongTask::kDuration_V8_ExecuteNameHash, PerformanceAPI_LongTask::kDuration_V8_ExecuteName },

                    { PerformanceAPI_LongTask::kDuration_V8_GCNameHash, PerformanceAPI_LongTask::kDuration_V8_GCName },

                    { PerformanceAPI_LongTask::kDuration_V8_GC_Full_AtomicNameHash, PerformanceAPI_LongTask::kDuration_V8_GC_Full_AtomicName },

                    { PerformanceAPI_LongTask::kDuration_V8_GC_Full_IncrementalNameHash, PerformanceAPI_LongTask::kDuration_V8_GC_Full_IncrementalName },

                    { PerformanceAPI_LongTask::kDuration_V8_GC_YoungNameHash, PerformanceAPI_LongTask::kDuration_V8_GC_YoungName },

                    { PerformanceAPI_LongTask::kStartTimeNameHash, PerformanceAPI_LongTask::kStartTimeName },

                } } },

        { UINT64_C(11822404190090982098),
            { PerformanceAPI_Memory::kEntryName,
                {

                    { PerformanceAPI_Memory::kDomNameHash, PerformanceAPI_Memory::kDomName },

                    { PerformanceAPI_Memory::kJavaScriptNameHash, PerformanceAPI_Memory::kJavaScriptName },

                    { PerformanceAPI_Memory::kJavaScript_DedicatedWorkerNameHash, PerformanceAPI_Memory::kJavaScript_DedicatedWorkerName },

                    { PerformanceAPI_Memory::kSharedNameHash, PerformanceAPI_Memory::kSharedName },

                } } },

        { UINT64_C(2959950180700461082),
            { PerformanceAPI_Memory_Legacy::kEntryName,
                {

                    { PerformanceAPI_Memory_Legacy::kJavaScriptNameHash, PerformanceAPI_Memory_Legacy::kJavaScriptName },

                } } },

        { UINT64_C(7310102334970989195),
            { PerformanceManager_PageResourceUsage2::kEntryName,
                {

                    { PerformanceManager_PageResourceUsage2::kBackgroundStateNameHash, PerformanceManager_PageResourceUsage2::kBackgroundStateName },

                    { PerformanceManager_PageResourceUsage2::kMeasurementAlgorithmNameHash, PerformanceManager_PageResourceUsage2::kMeasurementAlgorithmName },

                    { PerformanceManager_PageResourceUsage2::kPrivateFootprintEstimateNameHash,
                        PerformanceManager_PageResourceUsage2::kPrivateFootprintEstimateName },

                    { PerformanceManager_PageResourceUsage2::kRecentCPUUsageNameHash, PerformanceManager_PageResourceUsage2::kRecentCPUUsageName },

                    { PerformanceManager_PageResourceUsage2::kResidentSetSizeEstimateNameHash,
                        PerformanceManager_PageResourceUsage2::kResidentSetSizeEstimateName },

                    { PerformanceManager_PageResourceUsage2::kTotalRecentCPUUsageAllPagesNameHash,
                        PerformanceManager_PageResourceUsage2::kTotalRecentCPUUsageAllPagesName },

                } } },

        { UINT64_C(10863131082725230381),
            { PeriodicBackgroundSyncEventCompleted::kEntryName,
                {

                    { PeriodicBackgroundSyncEventCompleted::kMaxAttemptsNameHash, PeriodicBackgroundSyncEventCompleted::kMaxAttemptsName },

                    { PeriodicBackgroundSyncEventCompleted::kNumAttemptsNameHash, PeriodicBackgroundSyncEventCompleted::kNumAttemptsName },

                    { PeriodicBackgroundSyncEventCompleted::kStatusNameHash, PeriodicBackgroundSyncEventCompleted::kStatusName },

                } } },

        { UINT64_C(8211654418406942912),
            { PeriodicBackgroundSyncRegistered::kEntryName,
                {

                    { PeriodicBackgroundSyncRegistered::kIsReregisteredNameHash, PeriodicBackgroundSyncRegistered::kIsReregisteredName },

                    { PeriodicBackgroundSyncRegistered::kMinIntervalMsNameHash, PeriodicBackgroundSyncRegistered::kMinIntervalMsName },

                } } },

        { UINT64_C(17104084284355864347),
            { Permission::kEntryName,
                {

                    { Permission::kActionNameHash, Permission::kActionName },

                    { Permission::kGestureNameHash, Permission::kGestureName },

                    { Permission::kOsPromptScreenNameHash, Permission::kOsPromptScreenName },

                    { Permission::kOsSystemSettingsScreenNameHash, Permission::kOsSystemSettingsScreenName },

                    { Permission::kPermissionAutoRevocationHistoryNameHash, Permission::kPermissionAutoRevocationHistoryName },

                    { Permission::kPermissionTypeNameHash, Permission::kPermissionTypeName },

                    { Permission::kPredictionsApiResponse_GrantLikelihoodNameHash, Permission::kPredictionsApiResponse_GrantLikelihoodName },

                    { Permission::kPredictionsApiResponse_HeldbackNameHash, Permission::kPredictionsApiResponse_HeldbackName },

                    { Permission::kPriorDismissalsNameHash, Permission::kPriorDismissalsName },

                    { Permission::kPriorIgnoresNameHash, Permission::kPriorIgnoresName },

                    { Permission::kPromptDispositionNameHash, Permission::kPromptDispositionName },

                    { Permission::kPromptDispositionReasonNameHash, Permission::kPromptDispositionReasonName },

                    { Permission::kSatisfiedAdaptiveTriggersNameHash, Permission::kSatisfiedAdaptiveTriggersName },

                    { Permission::kSiteLevelScreenNameHash, Permission::kSiteLevelScreenName },

                    { Permission::kSourceNameHash, Permission::kSourceName },

                    { Permission::kStats_AllPrompts_CountNameHash, Permission::kStats_AllPrompts_CountName },

                    { Permission::kStats_AllPrompts_DenyRateNameHash, Permission::kStats_AllPrompts_DenyRateName },

                    { Permission::kStats_AllPrompts_DismissRateNameHash, Permission::kStats_AllPrompts_DismissRateName },

                    { Permission::kStats_AllPrompts_GrantRateNameHash, Permission::kStats_AllPrompts_GrantRateName },

                    { Permission::kStats_AllPrompts_IgnoreRateNameHash, Permission::kStats_AllPrompts_IgnoreRateName },

                    { Permission::kStats_AllPromptsOfType_CountNameHash, Permission::kStats_AllPromptsOfType_CountName },

                    { Permission::kStats_AllPromptsOfType_DenyRateNameHash, Permission::kStats_AllPromptsOfType_DenyRateName },

                    { Permission::kStats_AllPromptsOfType_DismissRateNameHash, Permission::kStats_AllPromptsOfType_DismissRateName },

                    { Permission::kStats_AllPromptsOfType_GrantRateNameHash, Permission::kStats_AllPromptsOfType_GrantRateName },

                    { Permission::kStats_AllPromptsOfType_IgnoreRateNameHash, Permission::kStats_AllPromptsOfType_IgnoreRateName },

                    { Permission::kStats_LoudPrompts_CountNameHash, Permission::kStats_LoudPrompts_CountName },

                    { Permission::kStats_LoudPrompts_DenyRateNameHash, Permission::kStats_LoudPrompts_DenyRateName },

                    { Permission::kStats_LoudPrompts_DismissRateNameHash, Permission::kStats_LoudPrompts_DismissRateName },

                    { Permission::kStats_LoudPrompts_GrantRateNameHash, Permission::kStats_LoudPrompts_GrantRateName },

                    { Permission::kStats_LoudPrompts_IgnoreRateNameHash, Permission::kStats_LoudPrompts_IgnoreRateName },

                    { Permission::kStats_LoudPromptsOfType_CountNameHash, Permission::kStats_LoudPromptsOfType_CountName },

                    { Permission::kStats_LoudPromptsOfType_DenyRateNameHash, Permission::kStats_LoudPromptsOfType_DenyRateName },

                    { Permission::kStats_LoudPromptsOfType_DismissRateNameHash, Permission::kStats_LoudPromptsOfType_DismissRateName },

                    { Permission::kStats_LoudPromptsOfType_GrantRateNameHash, Permission::kStats_LoudPromptsOfType_GrantRateName },

                    { Permission::kStats_LoudPromptsOfType_IgnoreRateNameHash, Permission::kStats_LoudPromptsOfType_IgnoreRateName },

                    { Permission::kTimeToDecisionNameHash, Permission::kTimeToDecisionName },

                } } },

        { UINT64_C(623278836175790870),
            { Permissions_EmbeddedPromptAction::kEntryName,
                {

                    { Permissions_EmbeddedPromptAction::kActionNameHash, Permissions_EmbeddedPromptAction::kActionName },

                    { Permissions_EmbeddedPromptAction::kPermissionTypeNameHash, Permissions_EmbeddedPromptAction::kPermissionTypeName },

                    { Permissions_EmbeddedPromptAction::kPreviousScreensNameHash, Permissions_EmbeddedPromptAction::kPreviousScreensName },

                    { Permissions_EmbeddedPromptAction::kScreenPermissionTypeNameHash, Permissions_EmbeddedPromptAction::kScreenPermissionTypeName },

                    { Permissions_EmbeddedPromptAction::kVariantNameHash, Permissions_EmbeddedPromptAction::kVariantName },

                } } },

        { UINT64_C(15070635187011991637),
            { PermissionUsage::kEntryName,
                {

                    { PermissionUsage::kPermissionTypeNameHash, PermissionUsage::kPermissionTypeName },

                } } },

        { UINT64_C(15267494322272545140),
            { PermissionUsage_NotificationShown::kEntryName,
                {

                    { PermissionUsage_NotificationShown::kIsAllowlistedNameHash, PermissionUsage_NotificationShown::kIsAllowlistedName },

                    { PermissionUsage_NotificationShown::kSuspiciousScoreNameHash, PermissionUsage_NotificationShown::kSuspiciousScoreName },

                } } },

        { UINT64_C(2851782918499658607),
            { Plugins_FlashInstance::kEntryName,
                {

                } } },

        { UINT64_C(5655451705717763469),
            { PlusAddresses_Submission::kEntryName,
                {

                    { PlusAddresses_Submission::kCheckoutOrCartPageNameHash, PlusAddresses_Submission::kCheckoutOrCartPageName },

                    { PlusAddresses_Submission::kFieldCountBrowserFormNameHash, PlusAddresses_Submission::kFieldCountBrowserFormName },

                    { PlusAddresses_Submission::kFieldCountRendererFormNameHash, PlusAddresses_Submission::kFieldCountRendererFormName },

                    { PlusAddresses_Submission::kManagedProfileNameHash, PlusAddresses_Submission::kManagedProfileName },

                    { PlusAddresses_Submission::kNewlyCreatedPlusAddressNameHash, PlusAddresses_Submission::kNewlyCreatedPlusAddressName },

                    { PlusAddresses_Submission::kPasswordFormTypeNameHash, PlusAddresses_Submission::kPasswordFormTypeName },

                    { PlusAddresses_Submission::kPlusAddressCountNameHash, PlusAddresses_Submission::kPlusAddressCountName },

                    { PlusAddresses_Submission::kSubmittedPlusAddressNameHash, PlusAddresses_Submission::kSubmittedPlusAddressName },

                    { PlusAddresses_Submission::kSuggestionContextNameHash, PlusAddresses_Submission::kSuggestionContextName },

                    { PlusAddresses_Submission::kWasShownCreateSuggestionNameHash, PlusAddresses_Submission::kWasShownCreateSuggestionName },

                } } },

        { UINT64_C(5373577291340314501),
            { Popup_Closed::kEntryName,
                {

                    { Popup_Closed::kEngagementTimeNameHash, Popup_Closed::kEngagementTimeName },

                    { Popup_Closed::kNumActivationInteractionsNameHash, Popup_Closed::kNumActivationInteractionsName },

                    { Popup_Closed::kNumGestureScrollBeginInteractionsNameHash, Popup_Closed::kNumGestureScrollBeginInteractionsName },

                    { Popup_Closed::kNumInteractionsNameHash, Popup_Closed::kNumInteractionsName },

                    { Popup_Closed::kRedirectCountNameHash, Popup_Closed::kRedirectCountName },

                    { Popup_Closed::kSafeBrowsingStatusNameHash, Popup_Closed::kSafeBrowsingStatusName },

                    { Popup_Closed::kTrustedNameHash, Popup_Closed::kTrustedName },

                    { Popup_Closed::kUserInitiatedCloseNameHash, Popup_Closed::kUserInitiatedCloseName },

                    { Popup_Closed::kWindowOpenDispositionNameHash, Popup_Closed::kWindowOpenDispositionName },

                } } },

        { UINT64_C(9277003375443527515),
            { Popup_Page::kEntryName,
                {

                    { Popup_Page::kAllowedNameHash, Popup_Page::kAllowedName },

                } } },

        { UINT64_C(570650911258459707),
            { Portal_Activate::kEntryName,
                {

                    { Portal_Activate::kPaintTiming_PortalActivationToFirstPaintNameHash, Portal_Activate::kPaintTiming_PortalActivationToFirstPaintName },

                    { Portal_Activate::kPortalActivationNameHash, Portal_Activate::kPortalActivationName },

                    { Portal_Activate::kPortalActivationBeforeLCPNameHash, Portal_Activate::kPortalActivationBeforeLCPName },

                } } },

        { UINT64_C(1484103205961568756),
            { PowerUsageScenariosIntervalData::kEntryName,
                {

                    { PowerUsageScenariosIntervalData::kBatteryDischargeModeNameHash, PowerUsageScenariosIntervalData::kBatteryDischargeModeName },

                    { PowerUsageScenariosIntervalData::kBatteryDischargeRateNameHash, PowerUsageScenariosIntervalData::kBatteryDischargeRateName },

                    { PowerUsageScenariosIntervalData::kBrowserShuttingDownNameHash, PowerUsageScenariosIntervalData::kBrowserShuttingDownName },

                    { PowerUsageScenariosIntervalData::kCPUTimeMsNameHash, PowerUsageScenariosIntervalData::kCPUTimeMsName },

                    { PowerUsageScenariosIntervalData::kDeviceSleptDuringIntervalNameHash, PowerUsageScenariosIntervalData::kDeviceSleptDuringIntervalName },

                    { PowerUsageScenariosIntervalData::kFullscreenVideoSingleMonitorSecondsNameHash,
                        PowerUsageScenariosIntervalData::kFullscreenVideoSingleMonitorSecondsName },

                    { PowerUsageScenariosIntervalData::kIdleWakeUpsNameHash, PowerUsageScenariosIntervalData::kIdleWakeUpsName },

                    { PowerUsageScenariosIntervalData::kIntervalDurationSecondsNameHash, PowerUsageScenariosIntervalData::kIntervalDurationSecondsName },

                    { PowerUsageScenariosIntervalData::kMaxTabCountNameHash, PowerUsageScenariosIntervalData::kMaxTabCountName },

                    { PowerUsageScenariosIntervalData::kMaxVisibleWindowCountNameHash, PowerUsageScenariosIntervalData::kMaxVisibleWindowCountName },

                    { PowerUsageScenariosIntervalData::kOriginVisibilityTimeSecondsNameHash,
                        PowerUsageScenariosIntervalData::kOriginVisibilityTimeSecondsName },

                    { PowerUsageScenariosIntervalData::kPackageExitsNameHash, PowerUsageScenariosIntervalData::kPackageExitsName },

                    { PowerUsageScenariosIntervalData::kPlayingAudioSecondsNameHash, PowerUsageScenariosIntervalData::kPlayingAudioSecondsName },

                    { PowerUsageScenariosIntervalData::kTabClosedNameHash, PowerUsageScenariosIntervalData::kTabClosedName },

                    { PowerUsageScenariosIntervalData::kTimePlayingVideoInVisibleTabNameHash,
                        PowerUsageScenariosIntervalData::kTimePlayingVideoInVisibleTabName },

                    { PowerUsageScenariosIntervalData::kTimeSinceInteractionWithBrowserSecondsNameHash,
                        PowerUsageScenariosIntervalData::kTimeSinceInteractionWithBrowserSecondsName },

                    { PowerUsageScenariosIntervalData::kTimeSinceInteractionWithSystemSecondsNameHash,
                        PowerUsageScenariosIntervalData::kTimeSinceInteractionWithSystemSecondsName },

                    { PowerUsageScenariosIntervalData::kTimeWithOpenWebRTCConnectionSecondsNameHash,
                        PowerUsageScenariosIntervalData::kTimeWithOpenWebRTCConnectionSecondsName },

                    { PowerUsageScenariosIntervalData::kTopLevelNavigationEventsNameHash, PowerUsageScenariosIntervalData::kTopLevelNavigationEventsName },

                    { PowerUsageScenariosIntervalData::kUptimeSecondsNameHash, PowerUsageScenariosIntervalData::kUptimeSecondsName },

                    { PowerUsageScenariosIntervalData::kURLVisibilityTimeSecondsNameHash, PowerUsageScenariosIntervalData::kURLVisibilityTimeSecondsName },

                    { PowerUsageScenariosIntervalData::kUserInteractionCountNameHash, PowerUsageScenariosIntervalData::kUserInteractionCountName },

                    { PowerUsageScenariosIntervalData::kVideoCaptureSecondsNameHash, PowerUsageScenariosIntervalData::kVideoCaptureSecondsName },

                } } },

        { UINT64_C(11352241752715206016),
            { PrefetchProxy::kEntryName,
                {

                    { PrefetchProxy::kdays_since_last_visit_to_originNameHash, PrefetchProxy::kdays_since_last_visit_to_originName },

                    { PrefetchProxy::kprefetch_attempted_countNameHash, PrefetchProxy::kprefetch_attempted_countName },

                    { PrefetchProxy::kprefetch_eligible_countNameHash, PrefetchProxy::kprefetch_eligible_countName },

                    { PrefetchProxy::kprefetch_successful_countNameHash, PrefetchProxy::kprefetch_successful_countName },

                } } },

        { UINT64_C(6674705951757661648),
            { PrefetchProxy_AfterSRPClick::kEntryName,
                {

                    { PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionNameHash, PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionName },

                    { PrefetchProxy_AfterSRPClick::kPrefetchHeaderLatencyMsNameHash, PrefetchProxy_AfterSRPClick::kPrefetchHeaderLatencyMsName },

                    { PrefetchProxy_AfterSRPClick::kPrivatePrefetchNameHash, PrefetchProxy_AfterSRPClick::kPrivatePrefetchName },

                    { PrefetchProxy_AfterSRPClick::kProbeLatencyMsNameHash, PrefetchProxy_AfterSRPClick::kProbeLatencyMsName },

                    { PrefetchProxy_AfterSRPClick::kSameTabAsPrefetchingTabNameHash, PrefetchProxy_AfterSRPClick::kSameTabAsPrefetchingTabName },

                    { PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusNameHash, PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusName },

                    { PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountNameHash, PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountName },

                } } },

        { UINT64_C(4145272093809115535),
            { PrefetchProxy_PrefetchedResource::kEntryName,
                {

                    { PrefetchProxy_PrefetchedResource::kDataLengthNameHash, PrefetchProxy_PrefetchedResource::kDataLengthName },

                    { PrefetchProxy_PrefetchedResource::kFetchDurationMSNameHash, PrefetchProxy_PrefetchedResource::kFetchDurationMSName },

                    { PrefetchProxy_PrefetchedResource::kISPFilteringStatusNameHash, PrefetchProxy_PrefetchedResource::kISPFilteringStatusName },

                    { PrefetchProxy_PrefetchedResource::kLinkClickedNameHash, PrefetchProxy_PrefetchedResource::kLinkClickedName },

                    { PrefetchProxy_PrefetchedResource::kLinkPositionNameHash, PrefetchProxy_PrefetchedResource::kLinkPositionName },

                    { PrefetchProxy_PrefetchedResource::kNavigationStartToFetchStartMSNameHash,
                        PrefetchProxy_PrefetchedResource::kNavigationStartToFetchStartMSName },

                    { PrefetchProxy_PrefetchedResource::kResourceTypeNameHash, PrefetchProxy_PrefetchedResource::kResourceTypeName },

                    { PrefetchProxy_PrefetchedResource::kStatusNameHash, PrefetchProxy_PrefetchedResource::kStatusName },

                } } },

        { UINT64_C(8746692042487350705),
            { Preloading_Attempt::kEntryName,
                {

                    { Preloading_Attempt::kAccurateTriggeringNameHash, Preloading_Attempt::kAccurateTriggeringName },

                    { Preloading_Attempt::kEligibilityNameHash, Preloading_Attempt::kEligibilityName },

                    { Preloading_Attempt::kFailureReasonNameHash, Preloading_Attempt::kFailureReasonName },

                    { Preloading_Attempt::kHoldbackStatusNameHash, Preloading_Attempt::kHoldbackStatusName },

                    { Preloading_Attempt::kPrefetchServiceWorkerRegisteredCheckNameHash, Preloading_Attempt::kPrefetchServiceWorkerRegisteredCheckName },

                    { Preloading_Attempt::kPrefetchServiceWorkerRegisteredForURLCheckDurationNameHash,
                        Preloading_Attempt::kPrefetchServiceWorkerRegisteredForURLCheckDurationName },

                    { Preloading_Attempt::kPreloadingPredictorNameHash, Preloading_Attempt::kPreloadingPredictorName },

                    { Preloading_Attempt::kPreloadingTypeNameHash, Preloading_Attempt::kPreloadingTypeName },

                    { Preloading_Attempt::kReadyTimeNameHash, Preloading_Attempt::kReadyTimeName },

                    { Preloading_Attempt::kSamplingLikelihoodNameHash, Preloading_Attempt::kSamplingLikelihoodName },

                    { Preloading_Attempt::kSpeculationEagernessNameHash, Preloading_Attempt::kSpeculationEagernessName },

                    { Preloading_Attempt::kTimeToNextNavigationNameHash, Preloading_Attempt::kTimeToNextNavigationName },

                    { Preloading_Attempt::kTriggeringOutcomeNameHash, Preloading_Attempt::kTriggeringOutcomeName },

                } } },

        { UINT64_C(16426521927935131349),
            { Preloading_Attempt_PreviousPrimaryPage::kEntryName,
                {

                    { Preloading_Attempt_PreviousPrimaryPage::kAccurateTriggeringNameHash, Preloading_Attempt_PreviousPrimaryPage::kAccurateTriggeringName },

                    { Preloading_Attempt_PreviousPrimaryPage::kEligibilityNameHash, Preloading_Attempt_PreviousPrimaryPage::kEligibilityName },

                    { Preloading_Attempt_PreviousPrimaryPage::kFailureReasonNameHash, Preloading_Attempt_PreviousPrimaryPage::kFailureReasonName },

                    { Preloading_Attempt_PreviousPrimaryPage::kHoldbackStatusNameHash, Preloading_Attempt_PreviousPrimaryPage::kHoldbackStatusName },

                    { Preloading_Attempt_PreviousPrimaryPage::kPrefetchServiceWorkerRegisteredCheckNameHash,
                        Preloading_Attempt_PreviousPrimaryPage::kPrefetchServiceWorkerRegisteredCheckName },

                    { Preloading_Attempt_PreviousPrimaryPage::kPrefetchServiceWorkerRegisteredForURLCheckDurationNameHash,
                        Preloading_Attempt_PreviousPrimaryPage::kPrefetchServiceWorkerRegisteredForURLCheckDurationName },

                    { Preloading_Attempt_PreviousPrimaryPage::kPreloadingPredictorNameHash, Preloading_Attempt_PreviousPrimaryPage::kPreloadingPredictorName },

                    { Preloading_Attempt_PreviousPrimaryPage::kPreloadingTypeNameHash, Preloading_Attempt_PreviousPrimaryPage::kPreloadingTypeName },

                    { Preloading_Attempt_PreviousPrimaryPage::kReadyTimeNameHash, Preloading_Attempt_PreviousPrimaryPage::kReadyTimeName },

                    { Preloading_Attempt_PreviousPrimaryPage::kSamplingLikelihoodNameHash, Preloading_Attempt_PreviousPrimaryPage::kSamplingLikelihoodName },

                    { Preloading_Attempt_PreviousPrimaryPage::kSpeculationEagernessNameHash,
                        Preloading_Attempt_PreviousPrimaryPage::kSpeculationEagernessName },

                    { Preloading_Attempt_PreviousPrimaryPage::kTimeToNextNavigationNameHash,
                        Preloading_Attempt_PreviousPrimaryPage::kTimeToNextNavigationName },

                    { Preloading_Attempt_PreviousPrimaryPage::kTriggeringOutcomeNameHash, Preloading_Attempt_PreviousPrimaryPage::kTriggeringOutcomeName },

                } } },

        { UINT64_C(14634695338976802777),
            { Preloading_NavigationPredictorModelTrainingData::kEntryName,
                {

                    { Preloading_NavigationPredictorModelTrainingData::kContainsImageNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kContainsImageName },

                    { Preloading_NavigationPredictorModelTrainingData::kFontSizeNameHash, Preloading_NavigationPredictorModelTrainingData::kFontSizeName },

                    { Preloading_NavigationPredictorModelTrainingData::kHasTextSiblingNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kHasTextSiblingName },

                    { Preloading_NavigationPredictorModelTrainingData::kHoverDwellTimeMsNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kHoverDwellTimeMsName },

                    { Preloading_NavigationPredictorModelTrainingData::kIsAccurateNameHash, Preloading_NavigationPredictorModelTrainingData::kIsAccurateName },

                    { Preloading_NavigationPredictorModelTrainingData::kIsBoldNameHash, Preloading_NavigationPredictorModelTrainingData::kIsBoldName },

                    { Preloading_NavigationPredictorModelTrainingData::kIsInIframeNameHash, Preloading_NavigationPredictorModelTrainingData::kIsInIframeName },

                    { Preloading_NavigationPredictorModelTrainingData::kIsURLIncrementedByOneNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kIsURLIncrementedByOneName },

                    { Preloading_NavigationPredictorModelTrainingData::kNavigationStartToLinkLoggedMsNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kNavigationStartToLinkLoggedMsName },

                    { Preloading_NavigationPredictorModelTrainingData::kPathDepthNameHash, Preloading_NavigationPredictorModelTrainingData::kPathDepthName },

                    { Preloading_NavigationPredictorModelTrainingData::kPathLengthNameHash, Preloading_NavigationPredictorModelTrainingData::kPathLengthName },

                    { Preloading_NavigationPredictorModelTrainingData::kPercentClickableAreaNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kPercentClickableAreaName },

                    { Preloading_NavigationPredictorModelTrainingData::kPercentVerticalDistanceNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kPercentVerticalDistanceName },

                    { Preloading_NavigationPredictorModelTrainingData::kPointerHoveringOverCountNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kPointerHoveringOverCountName },

                    { Preloading_NavigationPredictorModelTrainingData::kSameHostNameHash, Preloading_NavigationPredictorModelTrainingData::kSameHostName },

                    { Preloading_NavigationPredictorModelTrainingData::kSamplingAmountNameHash,
                        Preloading_NavigationPredictorModelTrainingData::kSamplingAmountName },

                } } },

        { UINT64_C(7178389144071274549),
            { Preloading_Prediction::kEntryName,
                {

                    { Preloading_Prediction::kAccuratePredictionNameHash, Preloading_Prediction::kAccuratePredictionName },

                    { Preloading_Prediction::kConfidenceNameHash, Preloading_Prediction::kConfidenceName },

                    { Preloading_Prediction::kPreloadingPredictorNameHash, Preloading_Prediction::kPreloadingPredictorName },

                    { Preloading_Prediction::kSamplingAmountNameHash, Preloading_Prediction::kSamplingAmountName },

                    { Preloading_Prediction::kTimeToNextNavigationNameHash, Preloading_Prediction::kTimeToNextNavigationName },

                } } },

        { UINT64_C(5667944672124880130),
            { Preloading_Prediction_PreviousPrimaryPage::kEntryName,
                {

                    { Preloading_Prediction_PreviousPrimaryPage::kAccuratePredictionNameHash,
                        Preloading_Prediction_PreviousPrimaryPage::kAccuratePredictionName },

                    { Preloading_Prediction_PreviousPrimaryPage::kConfidenceNameHash, Preloading_Prediction_PreviousPrimaryPage::kConfidenceName },

                    { Preloading_Prediction_PreviousPrimaryPage::kPreloadingPredictorNameHash,
                        Preloading_Prediction_PreviousPrimaryPage::kPreloadingPredictorName },

                    { Preloading_Prediction_PreviousPrimaryPage::kSamplingAmountNameHash, Preloading_Prediction_PreviousPrimaryPage::kSamplingAmountName },

                    { Preloading_Prediction_PreviousPrimaryPage::kTimeToNextNavigationNameHash,
                        Preloading_Prediction_PreviousPrimaryPage::kTimeToNextNavigationName },

                } } },

        { UINT64_C(14500319117729505239),
            { PrerenderPageLoad::kEntryName,
                {

                    { PrerenderPageLoad::kFinalStatusNameHash, PrerenderPageLoad::kFinalStatusName },

                    { PrerenderPageLoad::kInteractiveTiming_FirstInputDelay4NameHash, PrerenderPageLoad::kInteractiveTiming_FirstInputDelay4Name },

                    { PrerenderPageLoad::kInteractiveTiming_NumInteractionsNameHash, PrerenderPageLoad::kInteractiveTiming_NumInteractionsName },

                    { PrerenderPageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        PrerenderPageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { PrerenderPageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash,
                        PrerenderPageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName },

                    { PrerenderPageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PrerenderPageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { PrerenderPageLoad::kMainFrameResource_RequestHasNoStoreNameHash, PrerenderPageLoad::kMainFrameResource_RequestHasNoStoreName },

                    { PrerenderPageLoad::kNavigation_InitiatorLocationNameHash, PrerenderPageLoad::kNavigation_InitiatorLocationName },

                    { PrerenderPageLoad::kNavigation_PageTransitionNameHash, PrerenderPageLoad::kNavigation_PageTransitionName },

                    { PrerenderPageLoad::kTiming_ActivationToFirstContentfulPaintNameHash, PrerenderPageLoad::kTiming_ActivationToFirstContentfulPaintName },

                    { PrerenderPageLoad::kTiming_ActivationToLargestContentfulPaintNameHash,
                        PrerenderPageLoad::kTiming_ActivationToLargestContentfulPaintName },

                    { PrerenderPageLoad::kTiming_NavigationToActivationNameHash, PrerenderPageLoad::kTiming_NavigationToActivationName },

                    { PrerenderPageLoad::kTriggeredPrerenderNameHash, PrerenderPageLoad::kTriggeredPrerenderName },

                    { PrerenderPageLoad::kWasPrerenderedNameHash, PrerenderPageLoad::kWasPrerenderedName },

                } } },

        { UINT64_C(2441679537758985212),
            { Presentation_StartResult::kEntryName,
                {

                    { Presentation_StartResult::kPresentationRequestNameHash, Presentation_StartResult::kPresentationRequestName },

                    { Presentation_StartResult::kRemotePlaybackNameHash, Presentation_StartResult::kRemotePlaybackName },

                } } },

        { UINT64_C(4791378639615025150),
            { PWA_Visit::kEntryName,
                {

                    { PWA_Visit::kLaunchSourceNameHash, PWA_Visit::kLaunchSourceName },

                    { PWA_Visit::kWebAPKableSiteVisitNameHash, PWA_Visit::kWebAPKableSiteVisitName },

                } } },

        { UINT64_C(8023001203190348723),
            { RedirectHeuristic_CookieAccess2::kEntryName,
                {

                    { RedirectHeuristic_CookieAccess2::kAccessAllowedNameHash, RedirectHeuristic_CookieAccess2::kAccessAllowedName },

                    { RedirectHeuristic_CookieAccess2::kAccessIdNameHash, RedirectHeuristic_CookieAccess2::kAccessIdName },

                    { RedirectHeuristic_CookieAccess2::kDoesFirstPartyPrecedeThirdPartyNameHash,
                        RedirectHeuristic_CookieAccess2::kDoesFirstPartyPrecedeThirdPartyName },

                    { RedirectHeuristic_CookieAccess2::kHoursSinceLastInteractionNameHash, RedirectHeuristic_CookieAccess2::kHoursSinceLastInteractionName },

                    { RedirectHeuristic_CookieAccess2::kIsAdTaggedNameHash, RedirectHeuristic_CookieAccess2::kIsAdTaggedName },

                    { RedirectHeuristic_CookieAccess2::kIsCurrentInteractionNameHash, RedirectHeuristic_CookieAccess2::kIsCurrentInteractionName },

                    { RedirectHeuristic_CookieAccess2::kMillisecondsSinceRedirectNameHash, RedirectHeuristic_CookieAccess2::kMillisecondsSinceRedirectName },

                    { RedirectHeuristic_CookieAccess2::kOpenerHasSameSiteIframeNameHash, RedirectHeuristic_CookieAccess2::kOpenerHasSameSiteIframeName },

                    { RedirectHeuristic_CookieAccess2::kSitesPassedCountNameHash, RedirectHeuristic_CookieAccess2::kSitesPassedCountName },

                } } },

        { UINT64_C(9485711265083453457),
            { RedirectHeuristic_CookieAccessThirdParty2::kEntryName,
                {

                    { RedirectHeuristic_CookieAccessThirdParty2::kAccessIdNameHash, RedirectHeuristic_CookieAccessThirdParty2::kAccessIdName },

                } } },

        { UINT64_C(18249372845339521807),
            { RendererSchedulerTask::kEntryName,
                {

                    { RendererSchedulerTask::kFrameStatusNameHash, RendererSchedulerTask::kFrameStatusName },

                    { RendererSchedulerTask::kIsOOPIFNameHash, RendererSchedulerTask::kIsOOPIFName },

                    { RendererSchedulerTask::kPageSchedulersNameHash, RendererSchedulerTask::kPageSchedulersName },

                    { RendererSchedulerTask::kQueueTypeNameHash, RendererSchedulerTask::kQueueTypeName },

                    { RendererSchedulerTask::kRendererAudibleNameHash, RendererSchedulerTask::kRendererAudibleName },

                    { RendererSchedulerTask::kRendererBackgroundedNameHash, RendererSchedulerTask::kRendererBackgroundedName },

                    { RendererSchedulerTask::kRendererHiddenNameHash, RendererSchedulerTask::kRendererHiddenName },

                    { RendererSchedulerTask::kSecondsSinceBackgroundedNameHash, RendererSchedulerTask::kSecondsSinceBackgroundedName },

                    { RendererSchedulerTask::kTaskCPUDurationNameHash, RendererSchedulerTask::kTaskCPUDurationName },

                    { RendererSchedulerTask::kTaskDurationNameHash, RendererSchedulerTask::kTaskDurationName },

                    { RendererSchedulerTask::kTaskTypeNameHash, RendererSchedulerTask::kTaskTypeName },

                    { RendererSchedulerTask::kThreadTypeNameHash, RendererSchedulerTask::kThreadTypeName },

                    { RendererSchedulerTask::kUseCaseNameHash, RendererSchedulerTask::kUseCaseName },

                    { RendererSchedulerTask::kVersionNameHash, RendererSchedulerTask::kVersionName },

                } } },

        { UINT64_C(14554281962363859401),
            { RenderViewContextMenu_Used::kEntryName,
                {

                    { RenderViewContextMenu_Used::kSelectedMenuItemNameHash, RenderViewContextMenu_Used::kSelectedMenuItemName },

                } } },

        { UINT64_C(12682518437722483590),
            { RequestStorageAccessFor_RequestStorageResult::kEntryName,
                {

                    { RequestStorageAccessFor_RequestStorageResult::kRequestStorageResultNameHash,
                        RequestStorageAccessFor_RequestStorageResult::kRequestStorageResultName },

                } } },

        { UINT64_C(8390839146308016474),
            { Responsiveness_UserInteraction::kEntryName,
                {

                    { Responsiveness_UserInteraction::kInteractionTypeNameHash, Responsiveness_UserInteraction::kInteractionTypeName },

                    { Responsiveness_UserInteraction::kMaxEventDurationNameHash, Responsiveness_UserInteraction::kMaxEventDurationName },

                    { Responsiveness_UserInteraction::kTotalEventDurationNameHash, Responsiveness_UserInteraction::kTotalEventDurationName },

                } } },

        { UINT64_C(6628044799783508745),
            { ResponsivenessMeasurement::kEntryName,
                {

                } } },

        { UINT64_C(8193059715620786465),
            { SafeBrowsingInterstitial::kEntryName,
                {

                    { SafeBrowsingInterstitial::kBypassedNameHash, SafeBrowsingInterstitial::kBypassedName },

                    { SafeBrowsingInterstitial::kShownNameHash, SafeBrowsingInterstitial::kShownName },

                } } },

        { UINT64_C(8255360323456312283),
            { SalientImageAvailability::kEntryName,
                {

                    { SalientImageAvailability::kImageAvailabilityNameHash, SalientImageAvailability::kImageAvailabilityName },

                } } },

        { UINT64_C(14016795862258924641),
            { SameSiteDifferentSchemeRequest::kEntryName,
                {

                } } },

        { UINT64_C(6057282574508536454),
            { SameSiteDifferentSchemeResponse::kEntryName,
                {

                } } },

        { UINT64_C(3590891381445194196),
            { SamesiteRedirectContextDowngrade::kEntryName,
                {

                    { SamesiteRedirectContextDowngrade::kAgePerCookieNameHash, SamesiteRedirectContextDowngrade::kAgePerCookieName },

                    { SamesiteRedirectContextDowngrade::kSamesiteValueReadPerCookieNameHash,
                        SamesiteRedirectContextDowngrade::kSamesiteValueReadPerCookieName },

                    { SamesiteRedirectContextDowngrade::kSamesiteValueWritePerCookieNameHash,
                        SamesiteRedirectContextDowngrade::kSamesiteValueWritePerCookieName },

                } } },

        { UINT64_C(13143810872110815515),
            { SavedTabGroup_Navigation::kEntryName,
                {

                    { SavedTabGroup_Navigation::kIsPostNameHash, SavedTabGroup_Navigation::kIsPostName },

                    { SavedTabGroup_Navigation::kNumSameUrlLoadNameHash, SavedTabGroup_Navigation::kNumSameUrlLoadName },

                    { SavedTabGroup_Navigation::kNumSameUrlWithoutRefAndQueryParamLoadNameHash,
                        SavedTabGroup_Navigation::kNumSameUrlWithoutRefAndQueryParamLoadName },

                    { SavedTabGroup_Navigation::kTabGroupTypeNameHash, SavedTabGroup_Navigation::kTabGroupTypeName },

                    { SavedTabGroup_Navigation::kWasRedirectedNameHash, SavedTabGroup_Navigation::kWasRedirectedName },

                } } },

        { UINT64_C(16392896102401488447),
            { SchemefulSameSiteContextDowngrade::kEntryName,
                {

                    { SchemefulSameSiteContextDowngrade::kRequestPerCookieNameHash, SchemefulSameSiteContextDowngrade::kRequestPerCookieName },

                    { SchemefulSameSiteContextDowngrade::kResponsePerCookieNameHash, SchemefulSameSiteContextDowngrade::kResponsePerCookieName },

                } } },

        { UINT64_C(17111718181803892778),
            { ScreenBrightness::kEntryName,
                {

                    { ScreenBrightness::kBatteryPercentNameHash, ScreenBrightness::kBatteryPercentName },

                    { ScreenBrightness::kBrightnessNameHash, ScreenBrightness::kBrightnessName },

                    { ScreenBrightness::kDayOfWeekNameHash, ScreenBrightness::kDayOfWeekName },

                    { ScreenBrightness::kDeviceModeNameHash, ScreenBrightness::kDeviceModeName },

                    { ScreenBrightness::kHourOfDayNameHash, ScreenBrightness::kHourOfDayName },

                    { ScreenBrightness::kIsAutoclickEnabledNameHash, ScreenBrightness::kIsAutoclickEnabledName },

                    { ScreenBrightness::kIsBrailleDisplayConnectedNameHash, ScreenBrightness::kIsBrailleDisplayConnectedName },

                    { ScreenBrightness::kIsCaretHighlightEnabledNameHash, ScreenBrightness::kIsCaretHighlightEnabledName },

                    { ScreenBrightness::kIsCursorHighlightEnabledNameHash, ScreenBrightness::kIsCursorHighlightEnabledName },

                    { ScreenBrightness::kIsFocusHighlightEnabledNameHash, ScreenBrightness::kIsFocusHighlightEnabledName },

                    { ScreenBrightness::kIsHighContrastEnabledNameHash, ScreenBrightness::kIsHighContrastEnabledName },

                    { ScreenBrightness::kIsLargeCursorEnabledNameHash, ScreenBrightness::kIsLargeCursorEnabledName },

                    { ScreenBrightness::kIsMagnifierEnabledNameHash, ScreenBrightness::kIsMagnifierEnabledName },

                    { ScreenBrightness::kIsMonoAudioEnabledNameHash, ScreenBrightness::kIsMonoAudioEnabledName },

                    { ScreenBrightness::kIsSelectToSpeakEnabledNameHash, ScreenBrightness::kIsSelectToSpeakEnabledName },

                    { ScreenBrightness::kIsSpokenFeedbackEnabledNameHash, ScreenBrightness::kIsSpokenFeedbackEnabledName },

                    { ScreenBrightness::kIsSwitchAccessEnabledNameHash, ScreenBrightness::kIsSwitchAccessEnabledName },

                    { ScreenBrightness::kIsVideoPlayingNameHash, ScreenBrightness::kIsVideoPlayingName },

                    { ScreenBrightness::kIsVirtualKeyboardEnabledNameHash, ScreenBrightness::kIsVirtualKeyboardEnabledName },

                    { ScreenBrightness::kLastActivityTimeSecNameHash, ScreenBrightness::kLastActivityTimeSecName },

                    { ScreenBrightness::kNightLightTemperaturePercentNameHash, ScreenBrightness::kNightLightTemperaturePercentName },

                    { ScreenBrightness::kNumRecentKeyEventsNameHash, ScreenBrightness::kNumRecentKeyEventsName },

                    { ScreenBrightness::kNumRecentMouseEventsNameHash, ScreenBrightness::kNumRecentMouseEventsName },

                    { ScreenBrightness::kNumRecentStylusEventsNameHash, ScreenBrightness::kNumRecentStylusEventsName },

                    { ScreenBrightness::kNumRecentTouchEventsNameHash, ScreenBrightness::kNumRecentTouchEventsName },

                    { ScreenBrightness::kOnBatteryNameHash, ScreenBrightness::kOnBatteryName },

                    { ScreenBrightness::kPreviousBrightnessNameHash, ScreenBrightness::kPreviousBrightnessName },

                    { ScreenBrightness::kReasonNameHash, ScreenBrightness::kReasonName },

                    { ScreenBrightness::kRecentTimeActiveSecNameHash, ScreenBrightness::kRecentTimeActiveSecName },

                    { ScreenBrightness::kSequenceIdNameHash, ScreenBrightness::kSequenceIdName },

                    { ScreenBrightness::kTimeSinceLastEventSecNameHash, ScreenBrightness::kTimeSinceLastEventSecName },

                } } },

        { UINT64_C(345243929458665883),
            { Security_SafetyTip::kEntryName,
                {

                    { Security_SafetyTip::kSafetyTipInteractionNameHash, Security_SafetyTip::kSafetyTipInteractionName },

                    { Security_SafetyTip::kSafetyTipStatusNameHash, Security_SafetyTip::kSafetyTipStatusName },

                    { Security_SafetyTip::kTriggeredKeywordsHeuristicsNameHash, Security_SafetyTip::kTriggeredKeywordsHeuristicsName },

                    { Security_SafetyTip::kTriggeredLookalikeHeuristicsNameHash, Security_SafetyTip::kTriggeredLookalikeHeuristicsName },

                    { Security_SafetyTip::kTriggeredServerSideBlocklistNameHash, Security_SafetyTip::kTriggeredServerSideBlocklistName },

                    { Security_SafetyTip::kUserPreviouslyIgnoredNameHash, Security_SafetyTip::kUserPreviouslyIgnoredName },

                } } },

        { UINT64_C(10614135803401894002),
            { Security_SiteEngagement::kEntryName,
                {

                    { Security_SiteEngagement::kFinalSecurityLevelNameHash, Security_SiteEngagement::kFinalSecurityLevelName },

                    { Security_SiteEngagement::kInitialSecurityLevelNameHash, Security_SiteEngagement::kInitialSecurityLevelName },

                    { Security_SiteEngagement::kSafetyTipStatusNameHash, Security_SiteEngagement::kSafetyTipStatusName },

                    { Security_SiteEngagement::kScoreDeltaNameHash, Security_SiteEngagement::kScoreDeltaName },

                    { Security_SiteEngagement::kScoreFinalNameHash, Security_SiteEngagement::kScoreFinalName },

                } } },

        { UINT64_C(9156952078430180947),
            { Segmentation_ModelExecution::kEntryName,
                {

                    { Segmentation_ModelExecution::kActualResultNameHash, Segmentation_ModelExecution::kActualResultName },

                    { Segmentation_ModelExecution::kActualResult2NameHash, Segmentation_ModelExecution::kActualResult2Name },

                    { Segmentation_ModelExecution::kActualResult3NameHash, Segmentation_ModelExecution::kActualResult3Name },

                    { Segmentation_ModelExecution::kActualResult4NameHash, Segmentation_ModelExecution::kActualResult4Name },

                    { Segmentation_ModelExecution::kActualResult5NameHash, Segmentation_ModelExecution::kActualResult5Name },

                    { Segmentation_ModelExecution::kActualResult6NameHash, Segmentation_ModelExecution::kActualResult6Name },

                    { Segmentation_ModelExecution::kInput0NameHash, Segmentation_ModelExecution::kInput0Name },

                    { Segmentation_ModelExecution::kInput1NameHash, Segmentation_ModelExecution::kInput1Name },

                    { Segmentation_ModelExecution::kInput10NameHash, Segmentation_ModelExecution::kInput10Name },

                    { Segmentation_ModelExecution::kInput11NameHash, Segmentation_ModelExecution::kInput11Name },

                    { Segmentation_ModelExecution::kInput12NameHash, Segmentation_ModelExecution::kInput12Name },

                    { Segmentation_ModelExecution::kInput13NameHash, Segmentation_ModelExecution::kInput13Name },

                    { Segmentation_ModelExecution::kInput14NameHash, Segmentation_ModelExecution::kInput14Name },

                    { Segmentation_ModelExecution::kInput15NameHash, Segmentation_ModelExecution::kInput15Name },

                    { Segmentation_ModelExecution::kInput16NameHash, Segmentation_ModelExecution::kInput16Name },

                    { Segmentation_ModelExecution::kInput17NameHash, Segmentation_ModelExecution::kInput17Name },

                    { Segmentation_ModelExecution::kInput18NameHash, Segmentation_ModelExecution::kInput18Name },

                    { Segmentation_ModelExecution::kInput19NameHash, Segmentation_ModelExecution::kInput19Name },

                    { Segmentation_ModelExecution::kInput2NameHash, Segmentation_ModelExecution::kInput2Name },

                    { Segmentation_ModelExecution::kInput20NameHash, Segmentation_ModelExecution::kInput20Name },

                    { Segmentation_ModelExecution::kInput21NameHash, Segmentation_ModelExecution::kInput21Name },

                    { Segmentation_ModelExecution::kInput22NameHash, Segmentation_ModelExecution::kInput22Name },

                    { Segmentation_ModelExecution::kInput23NameHash, Segmentation_ModelExecution::kInput23Name },

                    { Segmentation_ModelExecution::kInput24NameHash, Segmentation_ModelExecution::kInput24Name },

                    { Segmentation_ModelExecution::kInput25NameHash, Segmentation_ModelExecution::kInput25Name },

                    { Segmentation_ModelExecution::kInput26NameHash, Segmentation_ModelExecution::kInput26Name },

                    { Segmentation_ModelExecution::kInput27NameHash, Segmentation_ModelExecution::kInput27Name },

                    { Segmentation_ModelExecution::kInput28NameHash, Segmentation_ModelExecution::kInput28Name },

                    { Segmentation_ModelExecution::kInput29NameHash, Segmentation_ModelExecution::kInput29Name },

                    { Segmentation_ModelExecution::kInput3NameHash, Segmentation_ModelExecution::kInput3Name },

                    { Segmentation_ModelExecution::kInput30NameHash, Segmentation_ModelExecution::kInput30Name },

                    { Segmentation_ModelExecution::kInput31NameHash, Segmentation_ModelExecution::kInput31Name },

                    { Segmentation_ModelExecution::kInput32NameHash, Segmentation_ModelExecution::kInput32Name },

                    { Segmentation_ModelExecution::kInput33NameHash, Segmentation_ModelExecution::kInput33Name },

                    { Segmentation_ModelExecution::kInput34NameHash, Segmentation_ModelExecution::kInput34Name },

                    { Segmentation_ModelExecution::kInput35NameHash, Segmentation_ModelExecution::kInput35Name },

                    { Segmentation_ModelExecution::kInput36NameHash, Segmentation_ModelExecution::kInput36Name },

                    { Segmentation_ModelExecution::kInput37NameHash, Segmentation_ModelExecution::kInput37Name },

                    { Segmentation_ModelExecution::kInput38NameHash, Segmentation_ModelExecution::kInput38Name },

                    { Segmentation_ModelExecution::kInput39NameHash, Segmentation_ModelExecution::kInput39Name },

                    { Segmentation_ModelExecution::kInput4NameHash, Segmentation_ModelExecution::kInput4Name },

                    { Segmentation_ModelExecution::kInput40NameHash, Segmentation_ModelExecution::kInput40Name },

                    { Segmentation_ModelExecution::kInput41NameHash, Segmentation_ModelExecution::kInput41Name },

                    { Segmentation_ModelExecution::kInput42NameHash, Segmentation_ModelExecution::kInput42Name },

                    { Segmentation_ModelExecution::kInput43NameHash, Segmentation_ModelExecution::kInput43Name },

                    { Segmentation_ModelExecution::kInput44NameHash, Segmentation_ModelExecution::kInput44Name },

                    { Segmentation_ModelExecution::kInput45NameHash, Segmentation_ModelExecution::kInput45Name },

                    { Segmentation_ModelExecution::kInput46NameHash, Segmentation_ModelExecution::kInput46Name },

                    { Segmentation_ModelExecution::kInput47NameHash, Segmentation_ModelExecution::kInput47Name },

                    { Segmentation_ModelExecution::kInput48NameHash, Segmentation_ModelExecution::kInput48Name },

                    { Segmentation_ModelExecution::kInput49NameHash, Segmentation_ModelExecution::kInput49Name },

                    { Segmentation_ModelExecution::kInput5NameHash, Segmentation_ModelExecution::kInput5Name },

                    { Segmentation_ModelExecution::kInput6NameHash, Segmentation_ModelExecution::kInput6Name },

                    { Segmentation_ModelExecution::kInput7NameHash, Segmentation_ModelExecution::kInput7Name },

                    { Segmentation_ModelExecution::kInput8NameHash, Segmentation_ModelExecution::kInput8Name },

                    { Segmentation_ModelExecution::kInput9NameHash, Segmentation_ModelExecution::kInput9Name },

                    { Segmentation_ModelExecution::kModelVersionNameHash, Segmentation_ModelExecution::kModelVersionName },

                    { Segmentation_ModelExecution::kOptimizationTargetNameHash, Segmentation_ModelExecution::kOptimizationTargetName },

                    { Segmentation_ModelExecution::kOutputDelaySecNameHash, Segmentation_ModelExecution::kOutputDelaySecName },

                    { Segmentation_ModelExecution::kPredictionResultNameHash, Segmentation_ModelExecution::kPredictionResultName },

                    { Segmentation_ModelExecution::kPredictionResult1NameHash, Segmentation_ModelExecution::kPredictionResult1Name },

                    { Segmentation_ModelExecution::kPredictionResult10NameHash, Segmentation_ModelExecution::kPredictionResult10Name },

                    { Segmentation_ModelExecution::kPredictionResult2NameHash, Segmentation_ModelExecution::kPredictionResult2Name },

                    { Segmentation_ModelExecution::kPredictionResult3NameHash, Segmentation_ModelExecution::kPredictionResult3Name },

                    { Segmentation_ModelExecution::kPredictionResult4NameHash, Segmentation_ModelExecution::kPredictionResult4Name },

                    { Segmentation_ModelExecution::kPredictionResult5NameHash, Segmentation_ModelExecution::kPredictionResult5Name },

                    { Segmentation_ModelExecution::kPredictionResult6NameHash, Segmentation_ModelExecution::kPredictionResult6Name },

                    { Segmentation_ModelExecution::kPredictionResult7NameHash, Segmentation_ModelExecution::kPredictionResult7Name },

                    { Segmentation_ModelExecution::kPredictionResult8NameHash, Segmentation_ModelExecution::kPredictionResult8Name },

                    { Segmentation_ModelExecution::kPredictionResult9NameHash, Segmentation_ModelExecution::kPredictionResult9Name },

                    { Segmentation_ModelExecution::kSelectionResultNameHash, Segmentation_ModelExecution::kSelectionResultName },

                } } },

        { UINT64_C(3667446516803222545),
            { ServiceWorker_MainResourceLoadCompleted::kEntryName,
                {

                    { ServiceWorker_MainResourceLoadCompleted::kActualRouterSourceTypeNameHash,
                        ServiceWorker_MainResourceLoadCompleted::kActualRouterSourceTypeName },

                    { ServiceWorker_MainResourceLoadCompleted::kCacheLookupTimeNameHash, ServiceWorker_MainResourceLoadCompleted::kCacheLookupTimeName },

                    { ServiceWorker_MainResourceLoadCompleted::kInitialWorkerStatusNameHash,
                        ServiceWorker_MainResourceLoadCompleted::kInitialWorkerStatusName },

                    { ServiceWorker_MainResourceLoadCompleted::kMatchedFirstRouterSourceTypeNameHash,
                        ServiceWorker_MainResourceLoadCompleted::kMatchedFirstRouterSourceTypeName },

                    { ServiceWorker_MainResourceLoadCompleted::kRouterEvaluationTimeNameHash,
                        ServiceWorker_MainResourceLoadCompleted::kRouterEvaluationTimeName },

                    { ServiceWorker_MainResourceLoadCompleted::kRouterRuleCountNameHash, ServiceWorker_MainResourceLoadCompleted::kRouterRuleCountName },

                    { ServiceWorker_MainResourceLoadCompleted::kWorkerStatusOnEvaluationNameHash,
                        ServiceWorker_MainResourceLoadCompleted::kWorkerStatusOnEvaluationName },

                } } },

        { UINT64_C(15102348699902695841),
            { ServiceWorker_OnLoad::kEntryName,
                {

                    { ServiceWorker_OnLoad::kAudioFallbackNameHash, ServiceWorker_OnLoad::kAudioFallbackName },

                    { ServiceWorker_OnLoad::kAudioHandledNameHash, ServiceWorker_OnLoad::kAudioHandledName },

                    { ServiceWorker_OnLoad::kCSSStyleSheetFallbackNameHash, ServiceWorker_OnLoad::kCSSStyleSheetFallbackName },

                    { ServiceWorker_OnLoad::kCSSStyleSheetHandledNameHash, ServiceWorker_OnLoad::kCSSStyleSheetHandledName },

                    { ServiceWorker_OnLoad::kDictionaryFallbackNameHash, ServiceWorker_OnLoad::kDictionaryFallbackName },

                    { ServiceWorker_OnLoad::kDictionaryHandledNameHash, ServiceWorker_OnLoad::kDictionaryHandledName },

                    { ServiceWorker_OnLoad::kFontFallbackNameHash, ServiceWorker_OnLoad::kFontFallbackName },

                    { ServiceWorker_OnLoad::kFontHandledNameHash, ServiceWorker_OnLoad::kFontHandledName },

                    { ServiceWorker_OnLoad::kImageFallbackNameHash, ServiceWorker_OnLoad::kImageFallbackName },

                    { ServiceWorker_OnLoad::kImageHandledNameHash, ServiceWorker_OnLoad::kImageHandledName },

                    { ServiceWorker_OnLoad::kLinkPrefetchFallbackNameHash, ServiceWorker_OnLoad::kLinkPrefetchFallbackName },

                    { ServiceWorker_OnLoad::kLinkPrefetchHandledNameHash, ServiceWorker_OnLoad::kLinkPrefetchHandledName },

                    { ServiceWorker_OnLoad::kMainAndSubResourceLoadLocationNameHash, ServiceWorker_OnLoad::kMainAndSubResourceLoadLocationName },

                    { ServiceWorker_OnLoad::kManifestFallbackNameHash, ServiceWorker_OnLoad::kManifestFallbackName },

                    { ServiceWorker_OnLoad::kManifestHandledNameHash, ServiceWorker_OnLoad::kManifestHandledName },

                    { ServiceWorker_OnLoad::kMatchedCacheRouterSourceCountNameHash, ServiceWorker_OnLoad::kMatchedCacheRouterSourceCountName },

                    { ServiceWorker_OnLoad::kMatchedFetchEventRouterSourceCountNameHash, ServiceWorker_OnLoad::kMatchedFetchEventRouterSourceCountName },

                    { ServiceWorker_OnLoad::kMatchedNetworkRouterSourceCountNameHash, ServiceWorker_OnLoad::kMatchedNetworkRouterSourceCountName },

                    { ServiceWorker_OnLoad::kMatchedRaceNetworkAndFetchRouterSourceCountNameHash,
                        ServiceWorker_OnLoad::kMatchedRaceNetworkAndFetchRouterSourceCountName },

                    { ServiceWorker_OnLoad::kScriptFallbackNameHash, ServiceWorker_OnLoad::kScriptFallbackName },

                    { ServiceWorker_OnLoad::kScriptHandledNameHash, ServiceWorker_OnLoad::kScriptHandledName },

                    { ServiceWorker_OnLoad::kSpeculationRulesFallbackNameHash, ServiceWorker_OnLoad::kSpeculationRulesFallbackName },

                    { ServiceWorker_OnLoad::kSpeculationRulesHandledNameHash, ServiceWorker_OnLoad::kSpeculationRulesHandledName },

                    { ServiceWorker_OnLoad::kSubResourceFallbackRatioNameHash, ServiceWorker_OnLoad::kSubResourceFallbackRatioName },

                    { ServiceWorker_OnLoad::kSVGDocumentFallbackNameHash, ServiceWorker_OnLoad::kSVGDocumentFallbackName },

                    { ServiceWorker_OnLoad::kSVGDocumentHandledNameHash, ServiceWorker_OnLoad::kSVGDocumentHandledName },

                    { ServiceWorker_OnLoad::kTextTrackFallbackNameHash, ServiceWorker_OnLoad::kTextTrackFallbackName },

                    { ServiceWorker_OnLoad::kTextTrackHandledNameHash, ServiceWorker_OnLoad::kTextTrackHandledName },

                    { ServiceWorker_OnLoad::kTotalCacheLookupTimeNameHash, ServiceWorker_OnLoad::kTotalCacheLookupTimeName },

                    { ServiceWorker_OnLoad::kTotalRouterEvaluationTimeNameHash, ServiceWorker_OnLoad::kTotalRouterEvaluationTimeName },

                    { ServiceWorker_OnLoad::kTotalSubResourceFallbackNameHash, ServiceWorker_OnLoad::kTotalSubResourceFallbackName },

                    { ServiceWorker_OnLoad::kTotalSubResourceLoadNameHash, ServiceWorker_OnLoad::kTotalSubResourceLoadName },

                    { ServiceWorker_OnLoad::kVideoFallbackNameHash, ServiceWorker_OnLoad::kVideoFallbackName },

                    { ServiceWorker_OnLoad::kVideoHandledNameHash, ServiceWorker_OnLoad::kVideoHandledName },

                    { ServiceWorker_OnLoad::kXSLStyleSheetFallbackNameHash, ServiceWorker_OnLoad::kXSLStyleSheetFallbackName },

                    { ServiceWorker_OnLoad::kXSLStyleSheetHandledNameHash, ServiceWorker_OnLoad::kXSLStyleSheetHandledName },

                } } },

        { UINT64_C(9684160219705289407),
            { SharedHighlights_LinkGenerated::kEntryName,
                {

                    { SharedHighlights_LinkGenerated::kErrorNameHash, SharedHighlights_LinkGenerated::kErrorName },

                    { SharedHighlights_LinkGenerated::kSuccessNameHash, SharedHighlights_LinkGenerated::kSuccessName },

                } } },

        { UINT64_C(386901924898439243),
            { SharedHighlights_LinkGenerated_Requested::kEntryName,
                {

                    { SharedHighlights_LinkGenerated_Requested::kErrorNameHash, SharedHighlights_LinkGenerated_Requested::kErrorName },

                    { SharedHighlights_LinkGenerated_Requested::kSuccessNameHash, SharedHighlights_LinkGenerated_Requested::kSuccessName },

                } } },

        { UINT64_C(11756915687522041272),
            { SharedHighlights_LinkOpened::kEntryName,
                {

                    { SharedHighlights_LinkOpened::kSourceNameHash, SharedHighlights_LinkOpened::kSourceName },

                    { SharedHighlights_LinkOpened::kSuccessNameHash, SharedHighlights_LinkOpened::kSuccessName },

                } } },

        { UINT64_C(13674128907128689363),
            { Sharing_ClickToCall::kEntryName,
                {

                    { Sharing_ClickToCall::kEntryPointNameHash, Sharing_ClickToCall::kEntryPointName },

                    { Sharing_ClickToCall::kHasAppsNameHash, Sharing_ClickToCall::kHasAppsName },

                    { Sharing_ClickToCall::kHasDevicesNameHash, Sharing_ClickToCall::kHasDevicesName },

                    { Sharing_ClickToCall::kSelectionNameHash, Sharing_ClickToCall::kSelectionName },

                } } },

        { UINT64_C(13706312502393203858),
            { Shopping_AddToCartDetection::kEntryName,
                {

                    { Shopping_AddToCartDetection::kHeuristicsExecutionTimeNameHash, Shopping_AddToCartDetection::kHeuristicsExecutionTimeName },

                } } },

        { UINT64_C(3949460549124608133),
            { Shopping_CartExtraction::kEntryName,
                {

                    { Shopping_CartExtraction::kExtractionElapsedTimeNameHash, Shopping_CartExtraction::kExtractionElapsedTimeName },

                    { Shopping_CartExtraction::kExtractionExecutionTimeNameHash, Shopping_CartExtraction::kExtractionExecutionTimeName },

                    { Shopping_CartExtraction::kExtractionLongestTaskTimeNameHash, Shopping_CartExtraction::kExtractionLongestTaskTimeName },

                    { Shopping_CartExtraction::kExtractionTimedOutNameHash, Shopping_CartExtraction::kExtractionTimedOutName },

                    { Shopping_CartExtraction::kExtractionTotalTasksTimeNameHash, Shopping_CartExtraction::kExtractionTotalTasksTimeName },

                } } },

        { UINT64_C(15978989974993672382),
            { Shopping_ChromeCart::kEntryName,
                {

                    { Shopping_ChromeCart::kVisitCartNameHash, Shopping_ChromeCart::kVisitCartName },

                } } },

        { UINT64_C(15728395807615377346),
            { Shopping_Compare_ClusterIdenfitiedByClient::kEntryName,
                {

                    { Shopping_Compare_ClusterIdenfitiedByClient::kComparableByServerNameHash,
                        Shopping_Compare_ClusterIdenfitiedByClient::kComparableByServerName },

                    { Shopping_Compare_ClusterIdenfitiedByClient::kCompareEventIDNameHash, Shopping_Compare_ClusterIdenfitiedByClient::kCompareEventIDName },

                } } },

        { UINT64_C(15032836644362572537),
            { Shopping_Discounts::kEntryName,
                {

                    { Shopping_Discounts::kAutoPopupEligibleButSuppressedNameHash, Shopping_Discounts::kAutoPopupEligibleButSuppressedName },

                } } },

        { UINT64_C(3010088505008297297),
            { Shopping_FormSubmitted::kEntryName,
                {

                    { Shopping_FormSubmitted::kIsTransactionNameHash, Shopping_FormSubmitted::kIsTransactionName },

                } } },

        { UINT64_C(5357508630854566377),
            { Shopping_MerchantTrust_DataAvailable::kEntryName,
                {

                    { Shopping_MerchantTrust_DataAvailable::kDataAvailableNameHash, Shopping_MerchantTrust_DataAvailable::kDataAvailableName },

                } } },

        { UINT64_C(14995105157617764468),
            { Shopping_MerchantTrust_MessageClicked::kEntryName,
                {

                    { Shopping_MerchantTrust_MessageClicked::kHasOccurredNameHash, Shopping_MerchantTrust_MessageClicked::kHasOccurredName },

                } } },

        { UINT64_C(16840045675093743647),
            { Shopping_MerchantTrust_MessageSeen::kEntryName,
                {

                    { Shopping_MerchantTrust_MessageSeen::kHasOccurredNameHash, Shopping_MerchantTrust_MessageSeen::kHasOccurredName },

                } } },

        { UINT64_C(10655844918945147363),
            { Shopping_MerchantTrust_RowClicked::kEntryName,
                {

                    { Shopping_MerchantTrust_RowClicked::kHasOccurredNameHash, Shopping_MerchantTrust_RowClicked::kHasOccurredName },

                } } },

        { UINT64_C(4482961312405396574),
            { Shopping_MerchantTrust_RowSeen::kEntryName,
                {

                    { Shopping_MerchantTrust_RowSeen::kHasOccurredNameHash, Shopping_MerchantTrust_RowSeen::kHasOccurredName },

                } } },

        { UINT64_C(9670390910407059784),
            { Shopping_PDPStateWithLocalInfo::kEntryName,
                {

                    { Shopping_PDPStateWithLocalInfo::kPDPStateNameHash, Shopping_PDPStateWithLocalInfo::kPDPStateName },

                } } },

        { UINT64_C(1072028031342147445),
            { Shopping_ShoppingAction::kEntryName,
                {

                    { Shopping_ShoppingAction::kDiscountCopiedNameHash, Shopping_ShoppingAction::kDiscountCopiedName },

                    { Shopping_ShoppingAction::kDiscountOpenedNameHash, Shopping_ShoppingAction::kDiscountOpenedName },

                    { Shopping_ShoppingAction::kPriceInsightsOpenedNameHash, Shopping_ShoppingAction::kPriceInsightsOpenedName },

                    { Shopping_ShoppingAction::kPriceTrackedNameHash, Shopping_ShoppingAction::kPriceTrackedName },

                } } },

        { UINT64_C(8745051225343642264),
            { Shopping_ShoppingInformation::kEntryName,
                {

                    { Shopping_ShoppingInformation::kHasDiscountNameHash, Shopping_ShoppingInformation::kHasDiscountName },

                    { Shopping_ShoppingInformation::kHasPriceInsightsNameHash, Shopping_ShoppingInformation::kHasPriceInsightsName },

                    { Shopping_ShoppingInformation::kIsPriceTrackableNameHash, Shopping_ShoppingInformation::kIsPriceTrackableName },

                    { Shopping_ShoppingInformation::kIsShoppingContentNameHash, Shopping_ShoppingInformation::kIsShoppingContentName },

                    { Shopping_ShoppingInformation::kPromotedFeatureNameHash, Shopping_ShoppingInformation::kPromotedFeatureName },

                } } },

        { UINT64_C(16734271994830574968),
            { Shopping_WillSendRequest::kEntryName,
                {

                    { Shopping_WillSendRequest::kIsAddToCartNameHash, Shopping_WillSendRequest::kIsAddToCartName },

                } } },

        { UINT64_C(11664953658330515632),
            { Site_Install::kEntryName,
                {

                    { Site_Install::kIsFullyInstalledNameHash, Site_Install::kIsFullyInstalledName },

                    { Site_Install::kIsPartiallyInstalledNameHash, Site_Install::kIsPartiallyInstalledName },

                } } },

        { UINT64_C(6971281771354023578),
            { Site_Manifest::kEntryName,
                {

                    { Site_Manifest::kDisplayModeNameHash, Site_Manifest::kDisplayModeName },

                    { Site_Manifest::kHasBackgroundColorNameHash, Site_Manifest::kHasBackgroundColorName },

                    { Site_Manifest::kHasIconsAnyNameHash, Site_Manifest::kHasIconsAnyName },

                    { Site_Manifest::kHasIconsMaskableNameHash, Site_Manifest::kHasIconsMaskableName },

                    { Site_Manifest::kHasNameNameHash, Site_Manifest::kHasNameName },

                    { Site_Manifest::kHasScreenshotsNameHash, Site_Manifest::kHasScreenshotsName },

                    { Site_Manifest::kHasStartUrlNameHash, Site_Manifest::kHasStartUrlName },

                    { Site_Manifest::kHasThemeColorNameHash, Site_Manifest::kHasThemeColorName },

                } } },

        { UINT64_C(16599718914662473687),
            { Site_Quality::kEntryName,
                {

                    { Site_Quality::kCacheStorageSizeNameHash, Site_Quality::kCacheStorageSizeName },

                    { Site_Quality::kHasFaviconsNameHash, Site_Quality::kHasFaviconsName },

                    { Site_Quality::kHasFetchHandlerNameHash, Site_Quality::kHasFetchHandlerName },

                    { Site_Quality::kServiceWorkerScriptSizeNameHash, Site_Quality::kServiceWorkerScriptSizeName },

                } } },

        { UINT64_C(993750679081265304),
            { SiteFamiliarityHeuristicResult::kEntryName,
                {

                    { SiteFamiliarityHeuristicResult::kAnyHeuristicsMatchNameHash, SiteFamiliarityHeuristicResult::kAnyHeuristicsMatchName },

                    { SiteFamiliarityHeuristicResult::kOnHighConfidenceAllowlistNameHash, SiteFamiliarityHeuristicResult::kOnHighConfidenceAllowlistName },

                    { SiteFamiliarityHeuristicResult::kSiteEngagementScoreNameHash, SiteFamiliarityHeuristicResult::kSiteEngagementScoreName },

                    { SiteFamiliarityHeuristicResult::kSiteFamiliarityHistoryHeuristicNameHash,
                        SiteFamiliarityHeuristicResult::kSiteFamiliarityHistoryHeuristicName },

                } } },

        { UINT64_C(6253142163073541541),
            { SiteInstance::kEntryName,
                {

                    { SiteInstance::kNewProcessUsedForNavigationWhenSameSiteProcessExistsNameHash,
                        SiteInstance::kNewProcessUsedForNavigationWhenSameSiteProcessExistsName },

                } } },

        { UINT64_C(18163040957371490481),
            { SmartCharging::kEntryName,
                {

                    { SmartCharging::kBatteryPercentageNameHash, SmartCharging::kBatteryPercentageName },

                    { SmartCharging::kBatteryPercentageBeforeLastChargeNameHash, SmartCharging::kBatteryPercentageBeforeLastChargeName },

                    { SmartCharging::kBatteryPercentageOfLastChargeNameHash, SmartCharging::kBatteryPercentageOfLastChargeName },

                    { SmartCharging::kDayOfMonthNameHash, SmartCharging::kDayOfMonthName },

                    { SmartCharging::kDayOfWeekNameHash, SmartCharging::kDayOfWeekName },

                    { SmartCharging::kDeviceModeNameHash, SmartCharging::kDeviceModeName },

                    { SmartCharging::kDeviceTypeNameHash, SmartCharging::kDeviceTypeName },

                    { SmartCharging::kDurationOfLastChargeNameHash, SmartCharging::kDurationOfLastChargeName },

                    { SmartCharging::kDurationRecentAudioPlayingNameHash, SmartCharging::kDurationRecentAudioPlayingName },

                    { SmartCharging::kDurationRecentVideoPlayingNameHash, SmartCharging::kDurationRecentVideoPlayingName },

                    { SmartCharging::kEventIdNameHash, SmartCharging::kEventIdName },

                    { SmartCharging::kHaltFromLastChargeNameHash, SmartCharging::kHaltFromLastChargeName },

                    { SmartCharging::kIsChargingNameHash, SmartCharging::kIsChargingName },

                    { SmartCharging::kMonthNameHash, SmartCharging::kMonthName },

                    { SmartCharging::kNumRecentKeyEventsNameHash, SmartCharging::kNumRecentKeyEventsName },

                    { SmartCharging::kNumRecentMouseEventsNameHash, SmartCharging::kNumRecentMouseEventsName },

                    { SmartCharging::kNumRecentStylusEventsNameHash, SmartCharging::kNumRecentStylusEventsName },

                    { SmartCharging::kNumRecentTouchEventsNameHash, SmartCharging::kNumRecentTouchEventsName },

                    { SmartCharging::kReasonNameHash, SmartCharging::kReasonName },

                    { SmartCharging::kScreenBrightnessPercentNameHash, SmartCharging::kScreenBrightnessPercentName },

                    { SmartCharging::kTimeOfTheDayNameHash, SmartCharging::kTimeOfTheDayName },

                    { SmartCharging::kTimeSinceLastChargeNameHash, SmartCharging::kTimeSinceLastChargeName },

                    { SmartCharging::kTimezoneDifferenceFromLastChargeNameHash, SmartCharging::kTimezoneDifferenceFromLastChargeName },

                    { SmartCharging::kVoltageNameHash, SmartCharging::kVoltageName },

                } } },

        { UINT64_C(16019904587509461311),
            { SMSReceiver::kEntryName,
                {

                    { SMSReceiver::kIsCrossOriginFrameNameHash, SMSReceiver::kIsCrossOriginFrameName },

                    { SMSReceiver::kOutcomeNameHash, SMSReceiver::kOutcomeName },

                    { SMSReceiver::kSmsParsingStatusNameHash, SMSReceiver::kSmsParsingStatusName },

                    { SMSReceiver::kTimeSmsReceiveMsNameHash, SMSReceiver::kTimeSmsReceiveMsName },

                    { SMSReceiver::kTimeSuccessMsNameHash, SMSReceiver::kTimeSuccessMsName },

                    { SMSReceiver::kTimeUserCancelMsNameHash, SMSReceiver::kTimeUserCancelMsName },

                } } },

        { UINT64_C(15372023901254491137),
            { SoftNavigation::kEntryName,
                {

                    { SoftNavigation::kInteractiveTiming_INPOffsetNameHash, SoftNavigation::kInteractiveTiming_INPOffsetName },

                    { SoftNavigation::kInteractiveTiming_INPTimeNameHash, SoftNavigation::kInteractiveTiming_INPTimeName },

                    { SoftNavigation::kInteractiveTiming_NumInteractionsNameHash, SoftNavigation::kInteractiveTiming_NumInteractionsName },

                    { SoftNavigation::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        SoftNavigation::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { SoftNavigation::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        SoftNavigation::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { SoftNavigation::kNavigationIdNameHash, SoftNavigation::kNavigationIdName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintNameHash, SoftNavigation::kPaintTiming_LargestContentfulPaintName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintBPPNameHash, SoftNavigation::kPaintTiming_LargestContentfulPaintBPPName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintImageDiscoveryTimeNameHash,
                        SoftNavigation::kPaintTiming_LargestContentfulPaintImageDiscoveryTimeName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintImageLoadEndNameHash,
                        SoftNavigation::kPaintTiming_LargestContentfulPaintImageLoadEndName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintImageLoadStartNameHash,
                        SoftNavigation::kPaintTiming_LargestContentfulPaintImageLoadStartName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintRequestPriorityNameHash,
                        SoftNavigation::kPaintTiming_LargestContentfulPaintRequestPriorityName },

                    { SoftNavigation::kPaintTiming_LargestContentfulPaintTypeNameHash, SoftNavigation::kPaintTiming_LargestContentfulPaintTypeName },

                    { SoftNavigation::kStartTimeNameHash, SoftNavigation::kStartTimeName },

                } } },

        { UINT64_C(16234573202714536926),
            { SubresourceFilter::kEntryName,
                {

                    { SubresourceFilter::kActivationDecisionNameHash, SubresourceFilter::kActivationDecisionName },

                    { SubresourceFilter::kDryRunNameHash, SubresourceFilter::kDryRunName },

                    { SubresourceFilter::kEnforcementRedirectPositionNameHash, SubresourceFilter::kEnforcementRedirectPositionName },

                } } },

        { UINT64_C(8817849481731339059),
            { SubresourceLoad_ZstdContentEncoding::kEntryName,
                {

                    { SubresourceLoad_ZstdContentEncoding::kUsedZstdNameHash, SubresourceLoad_ZstdContentEncoding::kUsedZstdName },

                } } },

        { UINT64_C(7915254855590561221),
            { SubresourceRedirect_PublicSrcVideoCompression::kEntryName,
                {

                    { SubresourceRedirect_PublicSrcVideoCompression::kFullContentLengthNameHash,
                        SubresourceRedirect_PublicSrcVideoCompression::kFullContentLengthName },

                    { SubresourceRedirect_PublicSrcVideoCompression::kSubresourceRedirectResultNameHash,
                        SubresourceRedirect_PublicSrcVideoCompression::kSubresourceRedirectResultName },

                } } },

        { UINT64_C(4107587426159302168),
            { Tab_Screenshot::kEntryName,
                {

                    { Tab_Screenshot::kHasOccurredNameHash, Tab_Screenshot::kHasOccurredName },

                } } },

        { UINT64_C(6962158576008124011),
            { TabManager_Background_FirstAlertFired::kEntryName,
                {

                    { TabManager_Background_FirstAlertFired::kIsMainFrameNameHash, TabManager_Background_FirstAlertFired::kIsMainFrameName },

                    { TabManager_Background_FirstAlertFired::kTimeFromBackgroundedNameHash, TabManager_Background_FirstAlertFired::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(6253115585121265178),
            { TabManager_Background_FirstAudioStarts::kEntryName,
                {

                    { TabManager_Background_FirstAudioStarts::kIsMainFrameNameHash, TabManager_Background_FirstAudioStarts::kIsMainFrameName },

                    { TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedNameHash,
                        TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(7684352713481018374),
            { TabManager_Background_FirstFaviconUpdated::kEntryName,
                {

                    { TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedNameHash,
                        TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(5800172692978642430),
            { TabManager_Background_FirstNonPersistentNotificationCreated::kEntryName,
                {

                    { TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameNameHash,
                        TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameName },

                    { TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedNameHash,
                        TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(13224923626166210718),
            { TabManager_Background_FirstTitleUpdated::kEntryName,
                {

                    { TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedNameHash,
                        TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(11823633373787678555),
            { TabManager_Background_ForegroundedOrClosed::kEntryName,
                {

                    { TabManager_Background_ForegroundedOrClosed::kIsDiscardedNameHash, TabManager_Background_ForegroundedOrClosed::kIsDiscardedName },

                    { TabManager_Background_ForegroundedOrClosed::kIsForegroundedNameHash, TabManager_Background_ForegroundedOrClosed::kIsForegroundedName },

                    { TabManager_Background_ForegroundedOrClosed::kLabelIdNameHash, TabManager_Background_ForegroundedOrClosed::kLabelIdName },

                    { TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedNameHash,
                        TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(10989149245696867796),
            { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryName,
                {

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeName },

                } } },

        { UINT64_C(15361214325300303131),
            { TabManager_LifecycleStateChange::kEntryName,
                {

                    { TabManager_LifecycleStateChange::kFailureGlobalDisallowlistNameHash, TabManager_LifecycleStateChange::kFailureGlobalDisallowlistName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicAudioNameHash, TabManager_LifecycleStateChange::kFailureHeuristicAudioName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicFaviconNameHash, TabManager_LifecycleStateChange::kFailureHeuristicFaviconName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationNameHash,
                        TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicNotificationsNameHash,
                        TabManager_LifecycleStateChange::kFailureHeuristicNotificationsName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicTitleNameHash, TabManager_LifecycleStateChange::kFailureHeuristicTitleName },

                    { TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutNameHash,
                        TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutName },

                    { TabManager_LifecycleStateChange::kFailureLivePictureInPictureNameHash,
                        TabManager_LifecycleStateChange::kFailureLivePictureInPictureName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateCapturingNameHash, TabManager_LifecycleStateChange::kFailureLiveStateCapturingName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateFormEntryNameHash, TabManager_LifecycleStateChange::kFailureLiveStateFormEntryName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateIsPDFNameHash, TabManager_LifecycleStateChange::kFailureLiveStateIsPDFName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateMirroringNameHash, TabManager_LifecycleStateChange::kFailureLiveStateMirroringName },

                    { TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateVisibleNameHash, TabManager_LifecycleStateChange::kFailureLiveStateVisibleName },

                    { TabManager_LifecycleStateChange::kFailureLiveWebAppNameHash, TabManager_LifecycleStateChange::kFailureLiveWebAppName },

                    { TabManager_LifecycleStateChange::kFailureOriginTrialOptOutNameHash, TabManager_LifecycleStateChange::kFailureOriginTrialOptOutName },

                    { TabManager_LifecycleStateChange::kFailureOriginTrialUnknownNameHash, TabManager_LifecycleStateChange::kFailureOriginTrialUnknownName },

                    { TabManager_LifecycleStateChange::kLifecycleStateChangeReasonNameHash, TabManager_LifecycleStateChange::kLifecycleStateChangeReasonName },

                    { TabManager_LifecycleStateChange::kNewLifecycleStateNameHash, TabManager_LifecycleStateChange::kNewLifecycleStateName },

                    { TabManager_LifecycleStateChange::kOldLifecycleStateNameHash, TabManager_LifecycleStateChange::kOldLifecycleStateName },

                    { TabManager_LifecycleStateChange::kOutcomeNameHash, TabManager_LifecycleStateChange::kOutcomeName },

                    { TabManager_LifecycleStateChange::kSuccessGlobalAllowlistNameHash, TabManager_LifecycleStateChange::kSuccessGlobalAllowlistName },

                    { TabManager_LifecycleStateChange::kSuccessHeuristicNameHash, TabManager_LifecycleStateChange::kSuccessHeuristicName },

                    { TabManager_LifecycleStateChange::kSuccessOriginTrialOptInNameHash, TabManager_LifecycleStateChange::kSuccessOriginTrialOptInName },

                    { TabManager_LifecycleStateChange::kTimeSinceNavigationMsNameHash, TabManager_LifecycleStateChange::kTimeSinceNavigationMsName },

                    { TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsNameHash,
                        TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsName },

                    { TabManager_LifecycleStateChange::kTransitionForcedNameHash, TabManager_LifecycleStateChange::kTransitionForcedName },

                    { TabManager_LifecycleStateChange::kVisibilityStateNameHash, TabManager_LifecycleStateChange::kVisibilityStateName },

                } } },

        { UINT64_C(8999972273877232390),
            { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName,
                {

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName },

                } } },

        { UINT64_C(16307465990132225428),
            { TabManager_TabLifetime::kEntryName,
                {

                    { TabManager_TabLifetime::kTimeSinceNavigationNameHash, TabManager_TabLifetime::kTimeSinceNavigationName },

                } } },

        { UINT64_C(12562637272871338124),
            { TabManager_WindowMetrics::kEntryName,
                {

                    { TabManager_WindowMetrics::kIsActiveNameHash, TabManager_WindowMetrics::kIsActiveName },

                    { TabManager_WindowMetrics::kShowStateNameHash, TabManager_WindowMetrics::kShowStateName },

                    { TabManager_WindowMetrics::kTabCountNameHash, TabManager_WindowMetrics::kTabCountName },

                    { TabManager_WindowMetrics::kTypeNameHash, TabManager_WindowMetrics::kTypeName },

                    { TabManager_WindowMetrics::kWindowIdNameHash, TabManager_WindowMetrics::kWindowIdName },

                } } },

        { UINT64_C(14351343629891097333),
            { TabRevisitTracker_TabStateChange::kEntryName,
                {

                    { TabRevisitTracker_TabStateChange::kNewStateNameHash, TabRevisitTracker_TabStateChange::kNewStateName },

                    { TabRevisitTracker_TabStateChange::kNumTabsOnSameUrlNameHash, TabRevisitTracker_TabStateChange::kNumTabsOnSameUrlName },

                    { TabRevisitTracker_TabStateChange::kNumTotalRevisitsNameHash, TabRevisitTracker_TabStateChange::kNumTotalRevisitsName },

                    { TabRevisitTracker_TabStateChange::kPreviousStateNameHash, TabRevisitTracker_TabStateChange::kPreviousStateName },

                    { TabRevisitTracker_TabStateChange::kSameTabGroupAsActiveTabNameHash, TabRevisitTracker_TabStateChange::kSameTabGroupAsActiveTabName },

                    { TabRevisitTracker_TabStateChange::kSameWindowAsActiveTabNameHash, TabRevisitTracker_TabStateChange::kSameWindowAsActiveTabName },

                    { TabRevisitTracker_TabStateChange::kTimeInPreviousStateNameHash, TabRevisitTracker_TabStateChange::kTimeInPreviousStateName },

                    { TabRevisitTracker_TabStateChange::kTotalTimeActiveNameHash, TabRevisitTracker_TabStateChange::kTotalTimeActiveName },

                } } },

        { UINT64_C(10784052616835854511),
            { TabStripOrganization::kEntryName,
                {

                    { TabStripOrganization::kIsActiveTabNameHash, TabStripOrganization::kIsActiveTabName },

                    { TabStripOrganization::kMinutesSinceLastActiveNameHash, TabStripOrganization::kMinutesSinceLastActiveName },

                    { TabStripOrganization::kSuggestedTabStripOrganizationReasonNameHash, TabStripOrganization::kSuggestedTabStripOrganizationReasonName },

                    { TabStripOrganization::kTabGroupIDNameHash, TabStripOrganization::kTabGroupIDName },

                    { TabStripOrganization::kTabStripEventIDNameHash, TabStripOrganization::kTabStripEventIDName },

                } } },

        { UINT64_C(9088201269784118104),
            { ThirdPartyCookies_BreakageIndicator_HTTPError::kEntryName,
                {

                    { ThirdPartyCookies_BreakageIndicator_HTTPError::kTPCBlockedNameHash, ThirdPartyCookies_BreakageIndicator_HTTPError::kTPCBlockedName },

                    { ThirdPartyCookies_BreakageIndicator_HTTPError::kTPCBlockedInSettingsNameHash,
                        ThirdPartyCookies_BreakageIndicator_HTTPError::kTPCBlockedInSettingsName },

                } } },

        { UINT64_C(15404660138221362264),
            { ThirdPartyCookies_BreakageIndicator_UncaughtJSError::kEntryName,
                {

                    { ThirdPartyCookies_BreakageIndicator_UncaughtJSError::kHasOccurredNameHash,
                        ThirdPartyCookies_BreakageIndicator_UncaughtJSError::kHasOccurredName },

                } } },

        { UINT64_C(18163975266525876574),
            { ThirdPartyCookies_BreakageIndicator_UserReload::kEntryName,
                {

                    { ThirdPartyCookies_BreakageIndicator_UserReload::kTPCBlockedNameHash, ThirdPartyCookies_BreakageIndicator_UserReload::kTPCBlockedName },

                    { ThirdPartyCookies_BreakageIndicator_UserReload::kTPCBlockedInSettingsNameHash,
                        ThirdPartyCookies_BreakageIndicator_UserReload::kTPCBlockedInSettingsName },

                } } },

        { UINT64_C(14349625384099335005),
            { ThirdPartyCookies_CookieControlsActivated::kEntryName,
                {

                    { ThirdPartyCookies_CookieControlsActivated::kFedCmInitiatedNameHash, ThirdPartyCookies_CookieControlsActivated::kFedCmInitiatedName },

                    { ThirdPartyCookies_CookieControlsActivated::kPageRefreshCountNameHash, ThirdPartyCookies_CookieControlsActivated::kPageRefreshCountName },

                    { ThirdPartyCookies_CookieControlsActivated::kRepeatedActivationNameHash,
                        ThirdPartyCookies_CookieControlsActivated::kRepeatedActivationName },

                    { ThirdPartyCookies_CookieControlsActivated::kSiteEngagementLevelNameHash,
                        ThirdPartyCookies_CookieControlsActivated::kSiteEngagementLevelName },

                    { ThirdPartyCookies_CookieControlsActivated::kStorageAccessAPIRequestedNameHash,
                        ThirdPartyCookies_CookieControlsActivated::kStorageAccessAPIRequestedName },

                    { ThirdPartyCookies_CookieControlsActivated::kThirdPartySiteDataAccessTypeNameHash,
                        ThirdPartyCookies_CookieControlsActivated::kThirdPartySiteDataAccessTypeName },

                } } },

        { UINT64_C(9317168121841018666),
            { ThirdPartyCookies_TopLevelDeprecationTrial::kEntryName,
                {

                    { ThirdPartyCookies_TopLevelDeprecationTrial::kEnabledNameHash, ThirdPartyCookies_TopLevelDeprecationTrial::kEnabledName },

                    { ThirdPartyCookies_TopLevelDeprecationTrial::kMatchSubdomainsNameHash, ThirdPartyCookies_TopLevelDeprecationTrial::kMatchSubdomainsName },

                } } },

        { UINT64_C(4093974732248698099),
            { TopToolbar_Share::kEntryName,
                {

                    { TopToolbar_Share::kHasOccurredNameHash, TopToolbar_Share::kHasOccurredName },

                } } },

        { UINT64_C(833305494688204602),
            { TouchToFill_Shown::kEntryName,
                {

                    { TouchToFill_Shown::kUserActionNameHash, TouchToFill_Shown::kUserActionName },

                } } },

        { UINT64_C(11228777951422985451),
            { TouchToFill_SubmissionReadiness::kEntryName,
                {

                    { TouchToFill_SubmissionReadiness::kSubmissionReadinessNameHash, TouchToFill_SubmissionReadiness::kSubmissionReadinessName },

                } } },

        { UINT64_C(5045482485607039969),
            { TouchToFill_TimeToSuccessfulLogin::kEntryName,
                {

                    { TouchToFill_TimeToSuccessfulLogin::kTimeToSuccessfulLoginNameHash, TouchToFill_TimeToSuccessfulLogin::kTimeToSuccessfulLoginName },

                } } },

        { UINT64_C(16389532164977706082),
            { Tpcd_Mitigations_Dt_FirstParty_Deployment2::kEntryName,
                {

                    { Tpcd_Mitigations_Dt_FirstParty_Deployment2::kDeployedNameHash, Tpcd_Mitigations_Dt_FirstParty_Deployment2::kDeployedName },

                } } },

        { UINT64_C(16054416016310256565),
            { Translate::kEntryName,
                {

                    { Translate::kAcceptCountNameHash, Translate::kAcceptCountName },

                    { Translate::kCountryNameHash, Translate::kCountryName },

                    { Translate::kDeclineCountNameHash, Translate::kDeclineCountName },

                    { Translate::kEventTypeNameHash, Translate::kEventTypeName },

                    { Translate::kIgnoreCountNameHash, Translate::kIgnoreCountName },

                    { Translate::kRankerResponseNameHash, Translate::kRankerResponseName },

                    { Translate::kRankerVersionNameHash, Translate::kRankerVersionName },

                    { Translate::kSourceLanguageNameHash, Translate::kSourceLanguageName },

                    { Translate::kTargetLanguageNameHash, Translate::kTargetLanguageName },

                } } },

        { UINT64_C(5132773550783566872),
            { TranslatePageLoad::kEntryName,
                {

                    { TranslatePageLoad::kFinalSourceLanguageNameHash, TranslatePageLoad::kFinalSourceLanguageName },

                    { TranslatePageLoad::kFinalStateNameHash, TranslatePageLoad::kFinalStateName },

                    { TranslatePageLoad::kFinalTargetLanguageNameHash, TranslatePageLoad::kFinalTargetLanguageName },

                    { TranslatePageLoad::kFirstTranslateErrorNameHash, TranslatePageLoad::kFirstTranslateErrorName },

                    { TranslatePageLoad::kFirstUIInteractionNameHash, TranslatePageLoad::kFirstUIInteractionName },

                    { TranslatePageLoad::kHTMLContentLanguageNameHash, TranslatePageLoad::kHTMLContentLanguageName },

                    { TranslatePageLoad::kHTMLDocumentLanguageNameHash, TranslatePageLoad::kHTMLDocumentLanguageName },

                    { TranslatePageLoad::kInitialSourceLanguageNameHash, TranslatePageLoad::kInitialSourceLanguageName },

                    { TranslatePageLoad::kInitialSourceLanguageInContentLanguagesNameHash, TranslatePageLoad::kInitialSourceLanguageInContentLanguagesName },

                    { TranslatePageLoad::kInitialStateNameHash, TranslatePageLoad::kInitialStateName },

                    { TranslatePageLoad::kInitialTargetLanguageNameHash, TranslatePageLoad::kInitialTargetLanguageName },

                    { TranslatePageLoad::kMaxTimeToTranslateNameHash, TranslatePageLoad::kMaxTimeToTranslateName },

                    { TranslatePageLoad::kModelDetectedLanguageNameHash, TranslatePageLoad::kModelDetectedLanguageName },

                    { TranslatePageLoad::kModelDetectionReliabilityScoreNameHash, TranslatePageLoad::kModelDetectionReliabilityScoreName },

                    { TranslatePageLoad::kNumReversionsNameHash, TranslatePageLoad::kNumReversionsName },

                    { TranslatePageLoad::kNumTargetLanguageChangesNameHash, TranslatePageLoad::kNumTargetLanguageChangesName },

                    { TranslatePageLoad::kNumTranslateErrorsNameHash, TranslatePageLoad::kNumTranslateErrorsName },

                    { TranslatePageLoad::kNumTranslationsNameHash, TranslatePageLoad::kNumTranslationsName },

                    { TranslatePageLoad::kNumUIInteractionsNameHash, TranslatePageLoad::kNumUIInteractionsName },

                    { TranslatePageLoad::kRankerDecisionNameHash, TranslatePageLoad::kRankerDecisionName },

                    { TranslatePageLoad::kRankerVersionNameHash, TranslatePageLoad::kRankerVersionName },

                    { TranslatePageLoad::kSequenceNumberNameHash, TranslatePageLoad::kSequenceNumberName },

                    { TranslatePageLoad::kTotalTimeNotTranslatedNameHash, TranslatePageLoad::kTotalTimeNotTranslatedName },

                    { TranslatePageLoad::kTotalTimeTranslatedNameHash, TranslatePageLoad::kTotalTimeTranslatedName },

                    { TranslatePageLoad::kTriggerDecisionNameHash, TranslatePageLoad::kTriggerDecisionName },

                    { TranslatePageLoad::kWasContentEmptyNameHash, TranslatePageLoad::kWasContentEmptyName },

                } } },

        { UINT64_C(15381255782093849665),
            { TrustedWebActivity_Open::kEntryName,
                {

                    { TrustedWebActivity_Open::kHasOccurredNameHash, TrustedWebActivity_Open::kHasOccurredName },

                } } },

        { UINT64_C(12543039456478655125),
            { Unload::kEntryName,
                {

                    { Unload::kBeforeUnloadDurationNameHash, Unload::kBeforeUnloadDurationName },

                    { Unload::kBeforeUnloadQueueingDurationNameHash, Unload::kBeforeUnloadQueueingDurationName },

                    { Unload::kBeforeUnloadToCommit_CrossProcessNameHash, Unload::kBeforeUnloadToCommit_CrossProcessName },

                    { Unload::kBeforeUnloadToCommit_SameProcessNameHash, Unload::kBeforeUnloadToCommit_SameProcessName },

                    { Unload::kUnloadDurationNameHash, Unload::kUnloadDurationName },

                    { Unload::kUnloadQueueingDurationNameHash, Unload::kUnloadQueueingDurationName },

                } } },

        { UINT64_C(2395897864454822590),
            { UserActivity::kEntryName,
                {

                    { UserActivity::kBatteryPercentNameHash, UserActivity::kBatteryPercentName },

                    { UserActivity::kDeviceManagementNameHash, UserActivity::kDeviceManagementName },

                    { UserActivity::kDeviceModeNameHash, UserActivity::kDeviceModeName },

                    { UserActivity::kDeviceTypeNameHash, UserActivity::kDeviceTypeName },

                    { UserActivity::kEventLogDurationNameHash, UserActivity::kEventLogDurationName },

                    { UserActivity::kEventReasonNameHash, UserActivity::kEventReasonName },

                    { UserActivity::kEventTypeNameHash, UserActivity::kEventTypeName },

                    { UserActivity::kKeyEventsInLastHourNameHash, UserActivity::kKeyEventsInLastHourName },

                    { UserActivity::kLastActivityDayNameHash, UserActivity::kLastActivityDayName },

                    { UserActivity::kLastActivityTimeNameHash, UserActivity::kLastActivityTimeName },

                    { UserActivity::kLastUserActivityTimeNameHash, UserActivity::kLastUserActivityTimeName },

                    { UserActivity::kModelAppliedNameHash, UserActivity::kModelAppliedName },

                    { UserActivity::kModelDecisionThresholdNameHash, UserActivity::kModelDecisionThresholdName },

                    { UserActivity::kModelInactivityScoreNameHash, UserActivity::kModelInactivityScoreName },

                    { UserActivity::kModelResponseNameHash, UserActivity::kModelResponseName },

                    { UserActivity::kMouseEventsInLastHourNameHash, UserActivity::kMouseEventsInLastHourName },

                    { UserActivity::kOnBatteryNameHash, UserActivity::kOnBatteryName },

                    { UserActivity::kPreviousNegativeActionsCountNameHash, UserActivity::kPreviousNegativeActionsCountName },

                    { UserActivity::kPreviousPositiveActionsCountNameHash, UserActivity::kPreviousPositiveActionsCountName },

                    { UserActivity::kRecentTimeActiveNameHash, UserActivity::kRecentTimeActiveName },

                    { UserActivity::kRecentVideoPlayingTimeNameHash, UserActivity::kRecentVideoPlayingTimeName },

                    { UserActivity::kScreenDimDelayNameHash, UserActivity::kScreenDimDelayName },

                    { UserActivity::kScreenDimmedInitiallyNameHash, UserActivity::kScreenDimmedInitiallyName },

                    { UserActivity::kScreenDimOccurredNameHash, UserActivity::kScreenDimOccurredName },

                    { UserActivity::kScreenDimToOffDelayNameHash, UserActivity::kScreenDimToOffDelayName },

                    { UserActivity::kScreenLockedInitiallyNameHash, UserActivity::kScreenLockedInitiallyName },

                    { UserActivity::kScreenLockOccurredNameHash, UserActivity::kScreenLockOccurredName },

                    { UserActivity::kScreenOffInitiallyNameHash, UserActivity::kScreenOffInitiallyName },

                    { UserActivity::kScreenOffOccurredNameHash, UserActivity::kScreenOffOccurredName },

                    { UserActivity::kSequenceIdNameHash, UserActivity::kSequenceIdName },

                    { UserActivity::kTimeSinceLastKeyNameHash, UserActivity::kTimeSinceLastKeyName },

                    { UserActivity::kTimeSinceLastMouseNameHash, UserActivity::kTimeSinceLastMouseName },

                    { UserActivity::kTimeSinceLastTouchNameHash, UserActivity::kTimeSinceLastTouchName },

                    { UserActivity::kTimeSinceLastVideoEndedNameHash, UserActivity::kTimeSinceLastVideoEndedName },

                    { UserActivity::kTouchEventsInLastHourNameHash, UserActivity::kTouchEventsInLastHourName },

                } } },

        { UINT64_C(13821826834442202003),
            { UserActivityId::kEntryName,
                {

                    { UserActivityId::kActivityIdNameHash, UserActivityId::kActivityIdName },

                    { UserActivityId::kContentTypeNameHash, UserActivityId::kContentTypeName },

                    { UserActivityId::kHasFormEntryNameHash, UserActivityId::kHasFormEntryName },

                    { UserActivityId::kIsActiveNameHash, UserActivityId::kIsActiveName },

                    { UserActivityId::kIsBrowserFocusedNameHash, UserActivityId::kIsBrowserFocusedName },

                    { UserActivityId::kIsBrowserVisibleNameHash, UserActivityId::kIsBrowserVisibleName },

                    { UserActivityId::kIsTopmostBrowserNameHash, UserActivityId::kIsTopmostBrowserName },

                    { UserActivityId::kSiteEngagementScoreNameHash, UserActivityId::kSiteEngagementScoreName },

                } } },

        { UINT64_C(4221731235635910179),
            { UserPerceivedPageVisit::kEntryName,
                {

                    { UserPerceivedPageVisit::kNotCountedForCoreWebVitalsNameHash, UserPerceivedPageVisit::kNotCountedForCoreWebVitalsName },

                    { UserPerceivedPageVisit::kPageVisitFinalStatusNameHash, UserPerceivedPageVisit::kPageVisitFinalStatusName },

                    { UserPerceivedPageVisit::kUserInitiatedNameHash, UserPerceivedPageVisit::kUserInitiatedName },

                } } },

        { UINT64_C(12143286159580552989),
            { V8_Wasm_ModuleCompiled::kEntryName,
                {

                    { V8_Wasm_ModuleCompiled::kAsyncNameHash, V8_Wasm_ModuleCompiled::kAsyncName },

                    { V8_Wasm_ModuleCompiled::kCachedNameHash, V8_Wasm_ModuleCompiled::kCachedName },

                    { V8_Wasm_ModuleCompiled::kCodeSizeNameHash, V8_Wasm_ModuleCompiled::kCodeSizeName },

                    { V8_Wasm_ModuleCompiled::kDeserializedNameHash, V8_Wasm_ModuleCompiled::kDeserializedName },

                    { V8_Wasm_ModuleCompiled::kLazyNameHash, V8_Wasm_ModuleCompiled::kLazyName },

                    { V8_Wasm_ModuleCompiled::kLiftoffBailoutCountNameHash, V8_Wasm_ModuleCompiled::kLiftoffBailoutCountName },

                    { V8_Wasm_ModuleCompiled::kStreamedNameHash, V8_Wasm_ModuleCompiled::kStreamedName },

                    { V8_Wasm_ModuleCompiled::kSuccessNameHash, V8_Wasm_ModuleCompiled::kSuccessName },

                    { V8_Wasm_ModuleCompiled::kWallClockDurationNameHash, V8_Wasm_ModuleCompiled::kWallClockDurationName },

                } } },

        { UINT64_C(5663155407937554096),
            { V8_Wasm_ModuleDecoded::kEntryName,
                {

                    { V8_Wasm_ModuleDecoded::kFunctionCountNameHash, V8_Wasm_ModuleDecoded::kFunctionCountName },

                    { V8_Wasm_ModuleDecoded::kModuleSizeNameHash, V8_Wasm_ModuleDecoded::kModuleSizeName },

                    { V8_Wasm_ModuleDecoded::kStreamedNameHash, V8_Wasm_ModuleDecoded::kStreamedName },

                    { V8_Wasm_ModuleDecoded::kSuccessNameHash, V8_Wasm_ModuleDecoded::kSuccessName },

                    { V8_Wasm_ModuleDecoded::kWallClockDurationNameHash, V8_Wasm_ModuleDecoded::kWallClockDurationName },

                } } },

        { UINT64_C(15295210720868142566),
            { V8_Wasm_ModuleInstantiated::kEntryName,
                {

                    { V8_Wasm_ModuleInstantiated::kImportedFunctionCountNameHash, V8_Wasm_ModuleInstantiated::kImportedFunctionCountName },

                    { V8_Wasm_ModuleInstantiated::kSuccessNameHash, V8_Wasm_ModuleInstantiated::kSuccessName },

                    { V8_Wasm_ModuleInstantiated::kWallClockDurationNameHash, V8_Wasm_ModuleInstantiated::kWallClockDurationName },

                } } },

        { UINT64_C(2833187735774133395),
            { V8_Wasm_ModuleTieredUp::kEntryName,
                {

                    { V8_Wasm_ModuleTieredUp::kCodeSizeNameHash, V8_Wasm_ModuleTieredUp::kCodeSizeName },

                    { V8_Wasm_ModuleTieredUp::kLazyNameHash, V8_Wasm_ModuleTieredUp::kLazyName },

                    { V8_Wasm_ModuleTieredUp::kWallClockDurationNameHash, V8_Wasm_ModuleTieredUp::kWallClockDurationName },

                } } },

        { UINT64_C(12239806873861850751),
            { V8CompileHints_Version5::kEntryName,
                {

                    { V8CompileHints_Version5::kData0NameHash, V8CompileHints_Version5::kData0Name },

                    { V8CompileHints_Version5::kData1NameHash, V8CompileHints_Version5::kData1Name },

                    { V8CompileHints_Version5::kData10NameHash, V8CompileHints_Version5::kData10Name },

                    { V8CompileHints_Version5::kData100NameHash, V8CompileHints_Version5::kData100Name },

                    { V8CompileHints_Version5::kData1000NameHash, V8CompileHints_Version5::kData1000Name },

                    { V8CompileHints_Version5::kData1001NameHash, V8CompileHints_Version5::kData1001Name },

                    { V8CompileHints_Version5::kData1002NameHash, V8CompileHints_Version5::kData1002Name },

                    { V8CompileHints_Version5::kData1003NameHash, V8CompileHints_Version5::kData1003Name },

                    { V8CompileHints_Version5::kData1004NameHash, V8CompileHints_Version5::kData1004Name },

                    { V8CompileHints_Version5::kData1005NameHash, V8CompileHints_Version5::kData1005Name },

                    { V8CompileHints_Version5::kData1006NameHash, V8CompileHints_Version5::kData1006Name },

                    { V8CompileHints_Version5::kData1007NameHash, V8CompileHints_Version5::kData1007Name },

                    { V8CompileHints_Version5::kData1008NameHash, V8CompileHints_Version5::kData1008Name },

                    { V8CompileHints_Version5::kData1009NameHash, V8CompileHints_Version5::kData1009Name },

                    { V8CompileHints_Version5::kData101NameHash, V8CompileHints_Version5::kData101Name },

                    { V8CompileHints_Version5::kData1010NameHash, V8CompileHints_Version5::kData1010Name },

                    { V8CompileHints_Version5::kData1011NameHash, V8CompileHints_Version5::kData1011Name },

                    { V8CompileHints_Version5::kData1012NameHash, V8CompileHints_Version5::kData1012Name },

                    { V8CompileHints_Version5::kData1013NameHash, V8CompileHints_Version5::kData1013Name },

                    { V8CompileHints_Version5::kData1014NameHash, V8CompileHints_Version5::kData1014Name },

                    { V8CompileHints_Version5::kData1015NameHash, V8CompileHints_Version5::kData1015Name },

                    { V8CompileHints_Version5::kData1016NameHash, V8CompileHints_Version5::kData1016Name },

                    { V8CompileHints_Version5::kData1017NameHash, V8CompileHints_Version5::kData1017Name },

                    { V8CompileHints_Version5::kData1018NameHash, V8CompileHints_Version5::kData1018Name },

                    { V8CompileHints_Version5::kData1019NameHash, V8CompileHints_Version5::kData1019Name },

                    { V8CompileHints_Version5::kData102NameHash, V8CompileHints_Version5::kData102Name },

                    { V8CompileHints_Version5::kData1020NameHash, V8CompileHints_Version5::kData1020Name },

                    { V8CompileHints_Version5::kData1021NameHash, V8CompileHints_Version5::kData1021Name },

                    { V8CompileHints_Version5::kData1022NameHash, V8CompileHints_Version5::kData1022Name },

                    { V8CompileHints_Version5::kData1023NameHash, V8CompileHints_Version5::kData1023Name },

                    { V8CompileHints_Version5::kData103NameHash, V8CompileHints_Version5::kData103Name },

                    { V8CompileHints_Version5::kData104NameHash, V8CompileHints_Version5::kData104Name },

                    { V8CompileHints_Version5::kData105NameHash, V8CompileHints_Version5::kData105Name },

                    { V8CompileHints_Version5::kData106NameHash, V8CompileHints_Version5::kData106Name },

                    { V8CompileHints_Version5::kData107NameHash, V8CompileHints_Version5::kData107Name },

                    { V8CompileHints_Version5::kData108NameHash, V8CompileHints_Version5::kData108Name },

                    { V8CompileHints_Version5::kData109NameHash, V8CompileHints_Version5::kData109Name },

                    { V8CompileHints_Version5::kData11NameHash, V8CompileHints_Version5::kData11Name },

                    { V8CompileHints_Version5::kData110NameHash, V8CompileHints_Version5::kData110Name },

                    { V8CompileHints_Version5::kData111NameHash, V8CompileHints_Version5::kData111Name },

                    { V8CompileHints_Version5::kData112NameHash, V8CompileHints_Version5::kData112Name },

                    { V8CompileHints_Version5::kData113NameHash, V8CompileHints_Version5::kData113Name },

                    { V8CompileHints_Version5::kData114NameHash, V8CompileHints_Version5::kData114Name },

                    { V8CompileHints_Version5::kData115NameHash, V8CompileHints_Version5::kData115Name },

                    { V8CompileHints_Version5::kData116NameHash, V8CompileHints_Version5::kData116Name },

                    { V8CompileHints_Version5::kData117NameHash, V8CompileHints_Version5::kData117Name },

                    { V8CompileHints_Version5::kData118NameHash, V8CompileHints_Version5::kData118Name },

                    { V8CompileHints_Version5::kData119NameHash, V8CompileHints_Version5::kData119Name },

                    { V8CompileHints_Version5::kData12NameHash, V8CompileHints_Version5::kData12Name },

                    { V8CompileHints_Version5::kData120NameHash, V8CompileHints_Version5::kData120Name },

                    { V8CompileHints_Version5::kData121NameHash, V8CompileHints_Version5::kData121Name },

                    { V8CompileHints_Version5::kData122NameHash, V8CompileHints_Version5::kData122Name },

                    { V8CompileHints_Version5::kData123NameHash, V8CompileHints_Version5::kData123Name },

                    { V8CompileHints_Version5::kData124NameHash, V8CompileHints_Version5::kData124Name },

                    { V8CompileHints_Version5::kData125NameHash, V8CompileHints_Version5::kData125Name },

                    { V8CompileHints_Version5::kData126NameHash, V8CompileHints_Version5::kData126Name },

                    { V8CompileHints_Version5::kData127NameHash, V8CompileHints_Version5::kData127Name },

                    { V8CompileHints_Version5::kData128NameHash, V8CompileHints_Version5::kData128Name },

                    { V8CompileHints_Version5::kData129NameHash, V8CompileHints_Version5::kData129Name },

                    { V8CompileHints_Version5::kData13NameHash, V8CompileHints_Version5::kData13Name },

                    { V8CompileHints_Version5::kData130NameHash, V8CompileHints_Version5::kData130Name },

                    { V8CompileHints_Version5::kData131NameHash, V8CompileHints_Version5::kData131Name },

                    { V8CompileHints_Version5::kData132NameHash, V8CompileHints_Version5::kData132Name },

                    { V8CompileHints_Version5::kData133NameHash, V8CompileHints_Version5::kData133Name },

                    { V8CompileHints_Version5::kData134NameHash, V8CompileHints_Version5::kData134Name },

                    { V8CompileHints_Version5::kData135NameHash, V8CompileHints_Version5::kData135Name },

                    { V8CompileHints_Version5::kData136NameHash, V8CompileHints_Version5::kData136Name },

                    { V8CompileHints_Version5::kData137NameHash, V8CompileHints_Version5::kData137Name },

                    { V8CompileHints_Version5::kData138NameHash, V8CompileHints_Version5::kData138Name },

                    { V8CompileHints_Version5::kData139NameHash, V8CompileHints_Version5::kData139Name },

                    { V8CompileHints_Version5::kData14NameHash, V8CompileHints_Version5::kData14Name },

                    { V8CompileHints_Version5::kData140NameHash, V8CompileHints_Version5::kData140Name },

                    { V8CompileHints_Version5::kData141NameHash, V8CompileHints_Version5::kData141Name },

                    { V8CompileHints_Version5::kData142NameHash, V8CompileHints_Version5::kData142Name },

                    { V8CompileHints_Version5::kData143NameHash, V8CompileHints_Version5::kData143Name },

                    { V8CompileHints_Version5::kData144NameHash, V8CompileHints_Version5::kData144Name },

                    { V8CompileHints_Version5::kData145NameHash, V8CompileHints_Version5::kData145Name },

                    { V8CompileHints_Version5::kData146NameHash, V8CompileHints_Version5::kData146Name },

                    { V8CompileHints_Version5::kData147NameHash, V8CompileHints_Version5::kData147Name },

                    { V8CompileHints_Version5::kData148NameHash, V8CompileHints_Version5::kData148Name },

                    { V8CompileHints_Version5::kData149NameHash, V8CompileHints_Version5::kData149Name },

                    { V8CompileHints_Version5::kData15NameHash, V8CompileHints_Version5::kData15Name },

                    { V8CompileHints_Version5::kData150NameHash, V8CompileHints_Version5::kData150Name },

                    { V8CompileHints_Version5::kData151NameHash, V8CompileHints_Version5::kData151Name },

                    { V8CompileHints_Version5::kData152NameHash, V8CompileHints_Version5::kData152Name },

                    { V8CompileHints_Version5::kData153NameHash, V8CompileHints_Version5::kData153Name },

                    { V8CompileHints_Version5::kData154NameHash, V8CompileHints_Version5::kData154Name },

                    { V8CompileHints_Version5::kData155NameHash, V8CompileHints_Version5::kData155Name },

                    { V8CompileHints_Version5::kData156NameHash, V8CompileHints_Version5::kData156Name },

                    { V8CompileHints_Version5::kData157NameHash, V8CompileHints_Version5::kData157Name },

                    { V8CompileHints_Version5::kData158NameHash, V8CompileHints_Version5::kData158Name },

                    { V8CompileHints_Version5::kData159NameHash, V8CompileHints_Version5::kData159Name },

                    { V8CompileHints_Version5::kData16NameHash, V8CompileHints_Version5::kData16Name },

                    { V8CompileHints_Version5::kData160NameHash, V8CompileHints_Version5::kData160Name },

                    { V8CompileHints_Version5::kData161NameHash, V8CompileHints_Version5::kData161Name },

                    { V8CompileHints_Version5::kData162NameHash, V8CompileHints_Version5::kData162Name },

                    { V8CompileHints_Version5::kData163NameHash, V8CompileHints_Version5::kData163Name },

                    { V8CompileHints_Version5::kData164NameHash, V8CompileHints_Version5::kData164Name },

                    { V8CompileHints_Version5::kData165NameHash, V8CompileHints_Version5::kData165Name },

                    { V8CompileHints_Version5::kData166NameHash, V8CompileHints_Version5::kData166Name },

                    { V8CompileHints_Version5::kData167NameHash, V8CompileHints_Version5::kData167Name },

                    { V8CompileHints_Version5::kData168NameHash, V8CompileHints_Version5::kData168Name },

                    { V8CompileHints_Version5::kData169NameHash, V8CompileHints_Version5::kData169Name },

                    { V8CompileHints_Version5::kData17NameHash, V8CompileHints_Version5::kData17Name },

                    { V8CompileHints_Version5::kData170NameHash, V8CompileHints_Version5::kData170Name },

                    { V8CompileHints_Version5::kData171NameHash, V8CompileHints_Version5::kData171Name },

                    { V8CompileHints_Version5::kData172NameHash, V8CompileHints_Version5::kData172Name },

                    { V8CompileHints_Version5::kData173NameHash, V8CompileHints_Version5::kData173Name },

                    { V8CompileHints_Version5::kData174NameHash, V8CompileHints_Version5::kData174Name },

                    { V8CompileHints_Version5::kData175NameHash, V8CompileHints_Version5::kData175Name },

                    { V8CompileHints_Version5::kData176NameHash, V8CompileHints_Version5::kData176Name },

                    { V8CompileHints_Version5::kData177NameHash, V8CompileHints_Version5::kData177Name },

                    { V8CompileHints_Version5::kData178NameHash, V8CompileHints_Version5::kData178Name },

                    { V8CompileHints_Version5::kData179NameHash, V8CompileHints_Version5::kData179Name },

                    { V8CompileHints_Version5::kData18NameHash, V8CompileHints_Version5::kData18Name },

                    { V8CompileHints_Version5::kData180NameHash, V8CompileHints_Version5::kData180Name },

                    { V8CompileHints_Version5::kData181NameHash, V8CompileHints_Version5::kData181Name },

                    { V8CompileHints_Version5::kData182NameHash, V8CompileHints_Version5::kData182Name },

                    { V8CompileHints_Version5::kData183NameHash, V8CompileHints_Version5::kData183Name },

                    { V8CompileHints_Version5::kData184NameHash, V8CompileHints_Version5::kData184Name },

                    { V8CompileHints_Version5::kData185NameHash, V8CompileHints_Version5::kData185Name },

                    { V8CompileHints_Version5::kData186NameHash, V8CompileHints_Version5::kData186Name },

                    { V8CompileHints_Version5::kData187NameHash, V8CompileHints_Version5::kData187Name },

                    { V8CompileHints_Version5::kData188NameHash, V8CompileHints_Version5::kData188Name },

                    { V8CompileHints_Version5::kData189NameHash, V8CompileHints_Version5::kData189Name },

                    { V8CompileHints_Version5::kData19NameHash, V8CompileHints_Version5::kData19Name },

                    { V8CompileHints_Version5::kData190NameHash, V8CompileHints_Version5::kData190Name },

                    { V8CompileHints_Version5::kData191NameHash, V8CompileHints_Version5::kData191Name },

                    { V8CompileHints_Version5::kData192NameHash, V8CompileHints_Version5::kData192Name },

                    { V8CompileHints_Version5::kData193NameHash, V8CompileHints_Version5::kData193Name },

                    { V8CompileHints_Version5::kData194NameHash, V8CompileHints_Version5::kData194Name },

                    { V8CompileHints_Version5::kData195NameHash, V8CompileHints_Version5::kData195Name },

                    { V8CompileHints_Version5::kData196NameHash, V8CompileHints_Version5::kData196Name },

                    { V8CompileHints_Version5::kData197NameHash, V8CompileHints_Version5::kData197Name },

                    { V8CompileHints_Version5::kData198NameHash, V8CompileHints_Version5::kData198Name },

                    { V8CompileHints_Version5::kData199NameHash, V8CompileHints_Version5::kData199Name },

                    { V8CompileHints_Version5::kData2NameHash, V8CompileHints_Version5::kData2Name },

                    { V8CompileHints_Version5::kData20NameHash, V8CompileHints_Version5::kData20Name },

                    { V8CompileHints_Version5::kData200NameHash, V8CompileHints_Version5::kData200Name },

                    { V8CompileHints_Version5::kData201NameHash, V8CompileHints_Version5::kData201Name },

                    { V8CompileHints_Version5::kData202NameHash, V8CompileHints_Version5::kData202Name },

                    { V8CompileHints_Version5::kData203NameHash, V8CompileHints_Version5::kData203Name },

                    { V8CompileHints_Version5::kData204NameHash, V8CompileHints_Version5::kData204Name },

                    { V8CompileHints_Version5::kData205NameHash, V8CompileHints_Version5::kData205Name },

                    { V8CompileHints_Version5::kData206NameHash, V8CompileHints_Version5::kData206Name },

                    { V8CompileHints_Version5::kData207NameHash, V8CompileHints_Version5::kData207Name },

                    { V8CompileHints_Version5::kData208NameHash, V8CompileHints_Version5::kData208Name },

                    { V8CompileHints_Version5::kData209NameHash, V8CompileHints_Version5::kData209Name },

                    { V8CompileHints_Version5::kData21NameHash, V8CompileHints_Version5::kData21Name },

                    { V8CompileHints_Version5::kData210NameHash, V8CompileHints_Version5::kData210Name },

                    { V8CompileHints_Version5::kData211NameHash, V8CompileHints_Version5::kData211Name },

                    { V8CompileHints_Version5::kData212NameHash, V8CompileHints_Version5::kData212Name },

                    { V8CompileHints_Version5::kData213NameHash, V8CompileHints_Version5::kData213Name },

                    { V8CompileHints_Version5::kData214NameHash, V8CompileHints_Version5::kData214Name },

                    { V8CompileHints_Version5::kData215NameHash, V8CompileHints_Version5::kData215Name },

                    { V8CompileHints_Version5::kData216NameHash, V8CompileHints_Version5::kData216Name },

                    { V8CompileHints_Version5::kData217NameHash, V8CompileHints_Version5::kData217Name },

                    { V8CompileHints_Version5::kData218NameHash, V8CompileHints_Version5::kData218Name },

                    { V8CompileHints_Version5::kData219NameHash, V8CompileHints_Version5::kData219Name },

                    { V8CompileHints_Version5::kData22NameHash, V8CompileHints_Version5::kData22Name },

                    { V8CompileHints_Version5::kData220NameHash, V8CompileHints_Version5::kData220Name },

                    { V8CompileHints_Version5::kData221NameHash, V8CompileHints_Version5::kData221Name },

                    { V8CompileHints_Version5::kData222NameHash, V8CompileHints_Version5::kData222Name },

                    { V8CompileHints_Version5::kData223NameHash, V8CompileHints_Version5::kData223Name },

                    { V8CompileHints_Version5::kData224NameHash, V8CompileHints_Version5::kData224Name },

                    { V8CompileHints_Version5::kData225NameHash, V8CompileHints_Version5::kData225Name },

                    { V8CompileHints_Version5::kData226NameHash, V8CompileHints_Version5::kData226Name },

                    { V8CompileHints_Version5::kData227NameHash, V8CompileHints_Version5::kData227Name },

                    { V8CompileHints_Version5::kData228NameHash, V8CompileHints_Version5::kData228Name },

                    { V8CompileHints_Version5::kData229NameHash, V8CompileHints_Version5::kData229Name },

                    { V8CompileHints_Version5::kData23NameHash, V8CompileHints_Version5::kData23Name },

                    { V8CompileHints_Version5::kData230NameHash, V8CompileHints_Version5::kData230Name },

                    { V8CompileHints_Version5::kData231NameHash, V8CompileHints_Version5::kData231Name },

                    { V8CompileHints_Version5::kData232NameHash, V8CompileHints_Version5::kData232Name },

                    { V8CompileHints_Version5::kData233NameHash, V8CompileHints_Version5::kData233Name },

                    { V8CompileHints_Version5::kData234NameHash, V8CompileHints_Version5::kData234Name },

                    { V8CompileHints_Version5::kData235NameHash, V8CompileHints_Version5::kData235Name },

                    { V8CompileHints_Version5::kData236NameHash, V8CompileHints_Version5::kData236Name },

                    { V8CompileHints_Version5::kData237NameHash, V8CompileHints_Version5::kData237Name },

                    { V8CompileHints_Version5::kData238NameHash, V8CompileHints_Version5::kData238Name },

                    { V8CompileHints_Version5::kData239NameHash, V8CompileHints_Version5::kData239Name },

                    { V8CompileHints_Version5::kData24NameHash, V8CompileHints_Version5::kData24Name },

                    { V8CompileHints_Version5::kData240NameHash, V8CompileHints_Version5::kData240Name },

                    { V8CompileHints_Version5::kData241NameHash, V8CompileHints_Version5::kData241Name },

                    { V8CompileHints_Version5::kData242NameHash, V8CompileHints_Version5::kData242Name },

                    { V8CompileHints_Version5::kData243NameHash, V8CompileHints_Version5::kData243Name },

                    { V8CompileHints_Version5::kData244NameHash, V8CompileHints_Version5::kData244Name },

                    { V8CompileHints_Version5::kData245NameHash, V8CompileHints_Version5::kData245Name },

                    { V8CompileHints_Version5::kData246NameHash, V8CompileHints_Version5::kData246Name },

                    { V8CompileHints_Version5::kData247NameHash, V8CompileHints_Version5::kData247Name },

                    { V8CompileHints_Version5::kData248NameHash, V8CompileHints_Version5::kData248Name },

                    { V8CompileHints_Version5::kData249NameHash, V8CompileHints_Version5::kData249Name },

                    { V8CompileHints_Version5::kData25NameHash, V8CompileHints_Version5::kData25Name },

                    { V8CompileHints_Version5::kData250NameHash, V8CompileHints_Version5::kData250Name },

                    { V8CompileHints_Version5::kData251NameHash, V8CompileHints_Version5::kData251Name },

                    { V8CompileHints_Version5::kData252NameHash, V8CompileHints_Version5::kData252Name },

                    { V8CompileHints_Version5::kData253NameHash, V8CompileHints_Version5::kData253Name },

                    { V8CompileHints_Version5::kData254NameHash, V8CompileHints_Version5::kData254Name },

                    { V8CompileHints_Version5::kData255NameHash, V8CompileHints_Version5::kData255Name },

                    { V8CompileHints_Version5::kData256NameHash, V8CompileHints_Version5::kData256Name },

                    { V8CompileHints_Version5::kData257NameHash, V8CompileHints_Version5::kData257Name },

                    { V8CompileHints_Version5::kData258NameHash, V8CompileHints_Version5::kData258Name },

                    { V8CompileHints_Version5::kData259NameHash, V8CompileHints_Version5::kData259Name },

                    { V8CompileHints_Version5::kData26NameHash, V8CompileHints_Version5::kData26Name },

                    { V8CompileHints_Version5::kData260NameHash, V8CompileHints_Version5::kData260Name },

                    { V8CompileHints_Version5::kData261NameHash, V8CompileHints_Version5::kData261Name },

                    { V8CompileHints_Version5::kData262NameHash, V8CompileHints_Version5::kData262Name },

                    { V8CompileHints_Version5::kData263NameHash, V8CompileHints_Version5::kData263Name },

                    { V8CompileHints_Version5::kData264NameHash, V8CompileHints_Version5::kData264Name },

                    { V8CompileHints_Version5::kData265NameHash, V8CompileHints_Version5::kData265Name },

                    { V8CompileHints_Version5::kData266NameHash, V8CompileHints_Version5::kData266Name },

                    { V8CompileHints_Version5::kData267NameHash, V8CompileHints_Version5::kData267Name },

                    { V8CompileHints_Version5::kData268NameHash, V8CompileHints_Version5::kData268Name },

                    { V8CompileHints_Version5::kData269NameHash, V8CompileHints_Version5::kData269Name },

                    { V8CompileHints_Version5::kData27NameHash, V8CompileHints_Version5::kData27Name },

                    { V8CompileHints_Version5::kData270NameHash, V8CompileHints_Version5::kData270Name },

                    { V8CompileHints_Version5::kData271NameHash, V8CompileHints_Version5::kData271Name },

                    { V8CompileHints_Version5::kData272NameHash, V8CompileHints_Version5::kData272Name },

                    { V8CompileHints_Version5::kData273NameHash, V8CompileHints_Version5::kData273Name },

                    { V8CompileHints_Version5::kData274NameHash, V8CompileHints_Version5::kData274Name },

                    { V8CompileHints_Version5::kData275NameHash, V8CompileHints_Version5::kData275Name },

                    { V8CompileHints_Version5::kData276NameHash, V8CompileHints_Version5::kData276Name },

                    { V8CompileHints_Version5::kData277NameHash, V8CompileHints_Version5::kData277Name },

                    { V8CompileHints_Version5::kData278NameHash, V8CompileHints_Version5::kData278Name },

                    { V8CompileHints_Version5::kData279NameHash, V8CompileHints_Version5::kData279Name },

                    { V8CompileHints_Version5::kData28NameHash, V8CompileHints_Version5::kData28Name },

                    { V8CompileHints_Version5::kData280NameHash, V8CompileHints_Version5::kData280Name },

                    { V8CompileHints_Version5::kData281NameHash, V8CompileHints_Version5::kData281Name },

                    { V8CompileHints_Version5::kData282NameHash, V8CompileHints_Version5::kData282Name },

                    { V8CompileHints_Version5::kData283NameHash, V8CompileHints_Version5::kData283Name },

                    { V8CompileHints_Version5::kData284NameHash, V8CompileHints_Version5::kData284Name },

                    { V8CompileHints_Version5::kData285NameHash, V8CompileHints_Version5::kData285Name },

                    { V8CompileHints_Version5::kData286NameHash, V8CompileHints_Version5::kData286Name },

                    { V8CompileHints_Version5::kData287NameHash, V8CompileHints_Version5::kData287Name },

                    { V8CompileHints_Version5::kData288NameHash, V8CompileHints_Version5::kData288Name },

                    { V8CompileHints_Version5::kData289NameHash, V8CompileHints_Version5::kData289Name },

                    { V8CompileHints_Version5::kData29NameHash, V8CompileHints_Version5::kData29Name },

                    { V8CompileHints_Version5::kData290NameHash, V8CompileHints_Version5::kData290Name },

                    { V8CompileHints_Version5::kData291NameHash, V8CompileHints_Version5::kData291Name },

                    { V8CompileHints_Version5::kData292NameHash, V8CompileHints_Version5::kData292Name },

                    { V8CompileHints_Version5::kData293NameHash, V8CompileHints_Version5::kData293Name },

                    { V8CompileHints_Version5::kData294NameHash, V8CompileHints_Version5::kData294Name },

                    { V8CompileHints_Version5::kData295NameHash, V8CompileHints_Version5::kData295Name },

                    { V8CompileHints_Version5::kData296NameHash, V8CompileHints_Version5::kData296Name },

                    { V8CompileHints_Version5::kData297NameHash, V8CompileHints_Version5::kData297Name },

                    { V8CompileHints_Version5::kData298NameHash, V8CompileHints_Version5::kData298Name },

                    { V8CompileHints_Version5::kData299NameHash, V8CompileHints_Version5::kData299Name },

                    { V8CompileHints_Version5::kData3NameHash, V8CompileHints_Version5::kData3Name },

                    { V8CompileHints_Version5::kData30NameHash, V8CompileHints_Version5::kData30Name },

                    { V8CompileHints_Version5::kData300NameHash, V8CompileHints_Version5::kData300Name },

                    { V8CompileHints_Version5::kData301NameHash, V8CompileHints_Version5::kData301Name },

                    { V8CompileHints_Version5::kData302NameHash, V8CompileHints_Version5::kData302Name },

                    { V8CompileHints_Version5::kData303NameHash, V8CompileHints_Version5::kData303Name },

                    { V8CompileHints_Version5::kData304NameHash, V8CompileHints_Version5::kData304Name },

                    { V8CompileHints_Version5::kData305NameHash, V8CompileHints_Version5::kData305Name },

                    { V8CompileHints_Version5::kData306NameHash, V8CompileHints_Version5::kData306Name },

                    { V8CompileHints_Version5::kData307NameHash, V8CompileHints_Version5::kData307Name },

                    { V8CompileHints_Version5::kData308NameHash, V8CompileHints_Version5::kData308Name },

                    { V8CompileHints_Version5::kData309NameHash, V8CompileHints_Version5::kData309Name },

                    { V8CompileHints_Version5::kData31NameHash, V8CompileHints_Version5::kData31Name },

                    { V8CompileHints_Version5::kData310NameHash, V8CompileHints_Version5::kData310Name },

                    { V8CompileHints_Version5::kData311NameHash, V8CompileHints_Version5::kData311Name },

                    { V8CompileHints_Version5::kData312NameHash, V8CompileHints_Version5::kData312Name },

                    { V8CompileHints_Version5::kData313NameHash, V8CompileHints_Version5::kData313Name },

                    { V8CompileHints_Version5::kData314NameHash, V8CompileHints_Version5::kData314Name },

                    { V8CompileHints_Version5::kData315NameHash, V8CompileHints_Version5::kData315Name },

                    { V8CompileHints_Version5::kData316NameHash, V8CompileHints_Version5::kData316Name },

                    { V8CompileHints_Version5::kData317NameHash, V8CompileHints_Version5::kData317Name },

                    { V8CompileHints_Version5::kData318NameHash, V8CompileHints_Version5::kData318Name },

                    { V8CompileHints_Version5::kData319NameHash, V8CompileHints_Version5::kData319Name },

                    { V8CompileHints_Version5::kData32NameHash, V8CompileHints_Version5::kData32Name },

                    { V8CompileHints_Version5::kData320NameHash, V8CompileHints_Version5::kData320Name },

                    { V8CompileHints_Version5::kData321NameHash, V8CompileHints_Version5::kData321Name },

                    { V8CompileHints_Version5::kData322NameHash, V8CompileHints_Version5::kData322Name },

                    { V8CompileHints_Version5::kData323NameHash, V8CompileHints_Version5::kData323Name },

                    { V8CompileHints_Version5::kData324NameHash, V8CompileHints_Version5::kData324Name },

                    { V8CompileHints_Version5::kData325NameHash, V8CompileHints_Version5::kData325Name },

                    { V8CompileHints_Version5::kData326NameHash, V8CompileHints_Version5::kData326Name },

                    { V8CompileHints_Version5::kData327NameHash, V8CompileHints_Version5::kData327Name },

                    { V8CompileHints_Version5::kData328NameHash, V8CompileHints_Version5::kData328Name },

                    { V8CompileHints_Version5::kData329NameHash, V8CompileHints_Version5::kData329Name },

                    { V8CompileHints_Version5::kData33NameHash, V8CompileHints_Version5::kData33Name },

                    { V8CompileHints_Version5::kData330NameHash, V8CompileHints_Version5::kData330Name },

                    { V8CompileHints_Version5::kData331NameHash, V8CompileHints_Version5::kData331Name },

                    { V8CompileHints_Version5::kData332NameHash, V8CompileHints_Version5::kData332Name },

                    { V8CompileHints_Version5::kData333NameHash, V8CompileHints_Version5::kData333Name },

                    { V8CompileHints_Version5::kData334NameHash, V8CompileHints_Version5::kData334Name },

                    { V8CompileHints_Version5::kData335NameHash, V8CompileHints_Version5::kData335Name },

                    { V8CompileHints_Version5::kData336NameHash, V8CompileHints_Version5::kData336Name },

                    { V8CompileHints_Version5::kData337NameHash, V8CompileHints_Version5::kData337Name },

                    { V8CompileHints_Version5::kData338NameHash, V8CompileHints_Version5::kData338Name },

                    { V8CompileHints_Version5::kData339NameHash, V8CompileHints_Version5::kData339Name },

                    { V8CompileHints_Version5::kData34NameHash, V8CompileHints_Version5::kData34Name },

                    { V8CompileHints_Version5::kData340NameHash, V8CompileHints_Version5::kData340Name },

                    { V8CompileHints_Version5::kData341NameHash, V8CompileHints_Version5::kData341Name },

                    { V8CompileHints_Version5::kData342NameHash, V8CompileHints_Version5::kData342Name },

                    { V8CompileHints_Version5::kData343NameHash, V8CompileHints_Version5::kData343Name },

                    { V8CompileHints_Version5::kData344NameHash, V8CompileHints_Version5::kData344Name },

                    { V8CompileHints_Version5::kData345NameHash, V8CompileHints_Version5::kData345Name },

                    { V8CompileHints_Version5::kData346NameHash, V8CompileHints_Version5::kData346Name },

                    { V8CompileHints_Version5::kData347NameHash, V8CompileHints_Version5::kData347Name },

                    { V8CompileHints_Version5::kData348NameHash, V8CompileHints_Version5::kData348Name },

                    { V8CompileHints_Version5::kData349NameHash, V8CompileHints_Version5::kData349Name },

                    { V8CompileHints_Version5::kData35NameHash, V8CompileHints_Version5::kData35Name },

                    { V8CompileHints_Version5::kData350NameHash, V8CompileHints_Version5::kData350Name },

                    { V8CompileHints_Version5::kData351NameHash, V8CompileHints_Version5::kData351Name },

                    { V8CompileHints_Version5::kData352NameHash, V8CompileHints_Version5::kData352Name },

                    { V8CompileHints_Version5::kData353NameHash, V8CompileHints_Version5::kData353Name },

                    { V8CompileHints_Version5::kData354NameHash, V8CompileHints_Version5::kData354Name },

                    { V8CompileHints_Version5::kData355NameHash, V8CompileHints_Version5::kData355Name },

                    { V8CompileHints_Version5::kData356NameHash, V8CompileHints_Version5::kData356Name },

                    { V8CompileHints_Version5::kData357NameHash, V8CompileHints_Version5::kData357Name },

                    { V8CompileHints_Version5::kData358NameHash, V8CompileHints_Version5::kData358Name },

                    { V8CompileHints_Version5::kData359NameHash, V8CompileHints_Version5::kData359Name },

                    { V8CompileHints_Version5::kData36NameHash, V8CompileHints_Version5::kData36Name },

                    { V8CompileHints_Version5::kData360NameHash, V8CompileHints_Version5::kData360Name },

                    { V8CompileHints_Version5::kData361NameHash, V8CompileHints_Version5::kData361Name },

                    { V8CompileHints_Version5::kData362NameHash, V8CompileHints_Version5::kData362Name },

                    { V8CompileHints_Version5::kData363NameHash, V8CompileHints_Version5::kData363Name },

                    { V8CompileHints_Version5::kData364NameHash, V8CompileHints_Version5::kData364Name },

                    { V8CompileHints_Version5::kData365NameHash, V8CompileHints_Version5::kData365Name },

                    { V8CompileHints_Version5::kData366NameHash, V8CompileHints_Version5::kData366Name },

                    { V8CompileHints_Version5::kData367NameHash, V8CompileHints_Version5::kData367Name },

                    { V8CompileHints_Version5::kData368NameHash, V8CompileHints_Version5::kData368Name },

                    { V8CompileHints_Version5::kData369NameHash, V8CompileHints_Version5::kData369Name },

                    { V8CompileHints_Version5::kData37NameHash, V8CompileHints_Version5::kData37Name },

                    { V8CompileHints_Version5::kData370NameHash, V8CompileHints_Version5::kData370Name },

                    { V8CompileHints_Version5::kData371NameHash, V8CompileHints_Version5::kData371Name },

                    { V8CompileHints_Version5::kData372NameHash, V8CompileHints_Version5::kData372Name },

                    { V8CompileHints_Version5::kData373NameHash, V8CompileHints_Version5::kData373Name },

                    { V8CompileHints_Version5::kData374NameHash, V8CompileHints_Version5::kData374Name },

                    { V8CompileHints_Version5::kData375NameHash, V8CompileHints_Version5::kData375Name },

                    { V8CompileHints_Version5::kData376NameHash, V8CompileHints_Version5::kData376Name },

                    { V8CompileHints_Version5::kData377NameHash, V8CompileHints_Version5::kData377Name },

                    { V8CompileHints_Version5::kData378NameHash, V8CompileHints_Version5::kData378Name },

                    { V8CompileHints_Version5::kData379NameHash, V8CompileHints_Version5::kData379Name },

                    { V8CompileHints_Version5::kData38NameHash, V8CompileHints_Version5::kData38Name },

                    { V8CompileHints_Version5::kData380NameHash, V8CompileHints_Version5::kData380Name },

                    { V8CompileHints_Version5::kData381NameHash, V8CompileHints_Version5::kData381Name },

                    { V8CompileHints_Version5::kData382NameHash, V8CompileHints_Version5::kData382Name },

                    { V8CompileHints_Version5::kData383NameHash, V8CompileHints_Version5::kData383Name },

                    { V8CompileHints_Version5::kData384NameHash, V8CompileHints_Version5::kData384Name },

                    { V8CompileHints_Version5::kData385NameHash, V8CompileHints_Version5::kData385Name },

                    { V8CompileHints_Version5::kData386NameHash, V8CompileHints_Version5::kData386Name },

                    { V8CompileHints_Version5::kData387NameHash, V8CompileHints_Version5::kData387Name },

                    { V8CompileHints_Version5::kData388NameHash, V8CompileHints_Version5::kData388Name },

                    { V8CompileHints_Version5::kData389NameHash, V8CompileHints_Version5::kData389Name },

                    { V8CompileHints_Version5::kData39NameHash, V8CompileHints_Version5::kData39Name },

                    { V8CompileHints_Version5::kData390NameHash, V8CompileHints_Version5::kData390Name },

                    { V8CompileHints_Version5::kData391NameHash, V8CompileHints_Version5::kData391Name },

                    { V8CompileHints_Version5::kData392NameHash, V8CompileHints_Version5::kData392Name },

                    { V8CompileHints_Version5::kData393NameHash, V8CompileHints_Version5::kData393Name },

                    { V8CompileHints_Version5::kData394NameHash, V8CompileHints_Version5::kData394Name },

                    { V8CompileHints_Version5::kData395NameHash, V8CompileHints_Version5::kData395Name },

                    { V8CompileHints_Version5::kData396NameHash, V8CompileHints_Version5::kData396Name },

                    { V8CompileHints_Version5::kData397NameHash, V8CompileHints_Version5::kData397Name },

                    { V8CompileHints_Version5::kData398NameHash, V8CompileHints_Version5::kData398Name },

                    { V8CompileHints_Version5::kData399NameHash, V8CompileHints_Version5::kData399Name },

                    { V8CompileHints_Version5::kData4NameHash, V8CompileHints_Version5::kData4Name },

                    { V8CompileHints_Version5::kData40NameHash, V8CompileHints_Version5::kData40Name },

                    { V8CompileHints_Version5::kData400NameHash, V8CompileHints_Version5::kData400Name },

                    { V8CompileHints_Version5::kData401NameHash, V8CompileHints_Version5::kData401Name },

                    { V8CompileHints_Version5::kData402NameHash, V8CompileHints_Version5::kData402Name },

                    { V8CompileHints_Version5::kData403NameHash, V8CompileHints_Version5::kData403Name },

                    { V8CompileHints_Version5::kData404NameHash, V8CompileHints_Version5::kData404Name },

                    { V8CompileHints_Version5::kData405NameHash, V8CompileHints_Version5::kData405Name },

                    { V8CompileHints_Version5::kData406NameHash, V8CompileHints_Version5::kData406Name },

                    { V8CompileHints_Version5::kData407NameHash, V8CompileHints_Version5::kData407Name },

                    { V8CompileHints_Version5::kData408NameHash, V8CompileHints_Version5::kData408Name },

                    { V8CompileHints_Version5::kData409NameHash, V8CompileHints_Version5::kData409Name },

                    { V8CompileHints_Version5::kData41NameHash, V8CompileHints_Version5::kData41Name },

                    { V8CompileHints_Version5::kData410NameHash, V8CompileHints_Version5::kData410Name },

                    { V8CompileHints_Version5::kData411NameHash, V8CompileHints_Version5::kData411Name },

                    { V8CompileHints_Version5::kData412NameHash, V8CompileHints_Version5::kData412Name },

                    { V8CompileHints_Version5::kData413NameHash, V8CompileHints_Version5::kData413Name },

                    { V8CompileHints_Version5::kData414NameHash, V8CompileHints_Version5::kData414Name },

                    { V8CompileHints_Version5::kData415NameHash, V8CompileHints_Version5::kData415Name },

                    { V8CompileHints_Version5::kData416NameHash, V8CompileHints_Version5::kData416Name },

                    { V8CompileHints_Version5::kData417NameHash, V8CompileHints_Version5::kData417Name },

                    { V8CompileHints_Version5::kData418NameHash, V8CompileHints_Version5::kData418Name },

                    { V8CompileHints_Version5::kData419NameHash, V8CompileHints_Version5::kData419Name },

                    { V8CompileHints_Version5::kData42NameHash, V8CompileHints_Version5::kData42Name },

                    { V8CompileHints_Version5::kData420NameHash, V8CompileHints_Version5::kData420Name },

                    { V8CompileHints_Version5::kData421NameHash, V8CompileHints_Version5::kData421Name },

                    { V8CompileHints_Version5::kData422NameHash, V8CompileHints_Version5::kData422Name },

                    { V8CompileHints_Version5::kData423NameHash, V8CompileHints_Version5::kData423Name },

                    { V8CompileHints_Version5::kData424NameHash, V8CompileHints_Version5::kData424Name },

                    { V8CompileHints_Version5::kData425NameHash, V8CompileHints_Version5::kData425Name },

                    { V8CompileHints_Version5::kData426NameHash, V8CompileHints_Version5::kData426Name },

                    { V8CompileHints_Version5::kData427NameHash, V8CompileHints_Version5::kData427Name },

                    { V8CompileHints_Version5::kData428NameHash, V8CompileHints_Version5::kData428Name },

                    { V8CompileHints_Version5::kData429NameHash, V8CompileHints_Version5::kData429Name },

                    { V8CompileHints_Version5::kData43NameHash, V8CompileHints_Version5::kData43Name },

                    { V8CompileHints_Version5::kData430NameHash, V8CompileHints_Version5::kData430Name },

                    { V8CompileHints_Version5::kData431NameHash, V8CompileHints_Version5::kData431Name },

                    { V8CompileHints_Version5::kData432NameHash, V8CompileHints_Version5::kData432Name },

                    { V8CompileHints_Version5::kData433NameHash, V8CompileHints_Version5::kData433Name },

                    { V8CompileHints_Version5::kData434NameHash, V8CompileHints_Version5::kData434Name },

                    { V8CompileHints_Version5::kData435NameHash, V8CompileHints_Version5::kData435Name },

                    { V8CompileHints_Version5::kData436NameHash, V8CompileHints_Version5::kData436Name },

                    { V8CompileHints_Version5::kData437NameHash, V8CompileHints_Version5::kData437Name },

                    { V8CompileHints_Version5::kData438NameHash, V8CompileHints_Version5::kData438Name },

                    { V8CompileHints_Version5::kData439NameHash, V8CompileHints_Version5::kData439Name },

                    { V8CompileHints_Version5::kData44NameHash, V8CompileHints_Version5::kData44Name },

                    { V8CompileHints_Version5::kData440NameHash, V8CompileHints_Version5::kData440Name },

                    { V8CompileHints_Version5::kData441NameHash, V8CompileHints_Version5::kData441Name },

                    { V8CompileHints_Version5::kData442NameHash, V8CompileHints_Version5::kData442Name },

                    { V8CompileHints_Version5::kData443NameHash, V8CompileHints_Version5::kData443Name },

                    { V8CompileHints_Version5::kData444NameHash, V8CompileHints_Version5::kData444Name },

                    { V8CompileHints_Version5::kData445NameHash, V8CompileHints_Version5::kData445Name },

                    { V8CompileHints_Version5::kData446NameHash, V8CompileHints_Version5::kData446Name },

                    { V8CompileHints_Version5::kData447NameHash, V8CompileHints_Version5::kData447Name },

                    { V8CompileHints_Version5::kData448NameHash, V8CompileHints_Version5::kData448Name },

                    { V8CompileHints_Version5::kData449NameHash, V8CompileHints_Version5::kData449Name },

                    { V8CompileHints_Version5::kData45NameHash, V8CompileHints_Version5::kData45Name },

                    { V8CompileHints_Version5::kData450NameHash, V8CompileHints_Version5::kData450Name },

                    { V8CompileHints_Version5::kData451NameHash, V8CompileHints_Version5::kData451Name },

                    { V8CompileHints_Version5::kData452NameHash, V8CompileHints_Version5::kData452Name },

                    { V8CompileHints_Version5::kData453NameHash, V8CompileHints_Version5::kData453Name },

                    { V8CompileHints_Version5::kData454NameHash, V8CompileHints_Version5::kData454Name },

                    { V8CompileHints_Version5::kData455NameHash, V8CompileHints_Version5::kData455Name },

                    { V8CompileHints_Version5::kData456NameHash, V8CompileHints_Version5::kData456Name },

                    { V8CompileHints_Version5::kData457NameHash, V8CompileHints_Version5::kData457Name },

                    { V8CompileHints_Version5::kData458NameHash, V8CompileHints_Version5::kData458Name },

                    { V8CompileHints_Version5::kData459NameHash, V8CompileHints_Version5::kData459Name },

                    { V8CompileHints_Version5::kData46NameHash, V8CompileHints_Version5::kData46Name },

                    { V8CompileHints_Version5::kData460NameHash, V8CompileHints_Version5::kData460Name },

                    { V8CompileHints_Version5::kData461NameHash, V8CompileHints_Version5::kData461Name },

                    { V8CompileHints_Version5::kData462NameHash, V8CompileHints_Version5::kData462Name },

                    { V8CompileHints_Version5::kData463NameHash, V8CompileHints_Version5::kData463Name },

                    { V8CompileHints_Version5::kData464NameHash, V8CompileHints_Version5::kData464Name },

                    { V8CompileHints_Version5::kData465NameHash, V8CompileHints_Version5::kData465Name },

                    { V8CompileHints_Version5::kData466NameHash, V8CompileHints_Version5::kData466Name },

                    { V8CompileHints_Version5::kData467NameHash, V8CompileHints_Version5::kData467Name },

                    { V8CompileHints_Version5::kData468NameHash, V8CompileHints_Version5::kData468Name },

                    { V8CompileHints_Version5::kData469NameHash, V8CompileHints_Version5::kData469Name },

                    { V8CompileHints_Version5::kData47NameHash, V8CompileHints_Version5::kData47Name },

                    { V8CompileHints_Version5::kData470NameHash, V8CompileHints_Version5::kData470Name },

                    { V8CompileHints_Version5::kData471NameHash, V8CompileHints_Version5::kData471Name },

                    { V8CompileHints_Version5::kData472NameHash, V8CompileHints_Version5::kData472Name },

                    { V8CompileHints_Version5::kData473NameHash, V8CompileHints_Version5::kData473Name },

                    { V8CompileHints_Version5::kData474NameHash, V8CompileHints_Version5::kData474Name },

                    { V8CompileHints_Version5::kData475NameHash, V8CompileHints_Version5::kData475Name },

                    { V8CompileHints_Version5::kData476NameHash, V8CompileHints_Version5::kData476Name },

                    { V8CompileHints_Version5::kData477NameHash, V8CompileHints_Version5::kData477Name },

                    { V8CompileHints_Version5::kData478NameHash, V8CompileHints_Version5::kData478Name },

                    { V8CompileHints_Version5::kData479NameHash, V8CompileHints_Version5::kData479Name },

                    { V8CompileHints_Version5::kData48NameHash, V8CompileHints_Version5::kData48Name },

                    { V8CompileHints_Version5::kData480NameHash, V8CompileHints_Version5::kData480Name },

                    { V8CompileHints_Version5::kData481NameHash, V8CompileHints_Version5::kData481Name },

                    { V8CompileHints_Version5::kData482NameHash, V8CompileHints_Version5::kData482Name },

                    { V8CompileHints_Version5::kData483NameHash, V8CompileHints_Version5::kData483Name },

                    { V8CompileHints_Version5::kData484NameHash, V8CompileHints_Version5::kData484Name },

                    { V8CompileHints_Version5::kData485NameHash, V8CompileHints_Version5::kData485Name },

                    { V8CompileHints_Version5::kData486NameHash, V8CompileHints_Version5::kData486Name },

                    { V8CompileHints_Version5::kData487NameHash, V8CompileHints_Version5::kData487Name },

                    { V8CompileHints_Version5::kData488NameHash, V8CompileHints_Version5::kData488Name },

                    { V8CompileHints_Version5::kData489NameHash, V8CompileHints_Version5::kData489Name },

                    { V8CompileHints_Version5::kData49NameHash, V8CompileHints_Version5::kData49Name },

                    { V8CompileHints_Version5::kData490NameHash, V8CompileHints_Version5::kData490Name },

                    { V8CompileHints_Version5::kData491NameHash, V8CompileHints_Version5::kData491Name },

                    { V8CompileHints_Version5::kData492NameHash, V8CompileHints_Version5::kData492Name },

                    { V8CompileHints_Version5::kData493NameHash, V8CompileHints_Version5::kData493Name },

                    { V8CompileHints_Version5::kData494NameHash, V8CompileHints_Version5::kData494Name },

                    { V8CompileHints_Version5::kData495NameHash, V8CompileHints_Version5::kData495Name },

                    { V8CompileHints_Version5::kData496NameHash, V8CompileHints_Version5::kData496Name },

                    { V8CompileHints_Version5::kData497NameHash, V8CompileHints_Version5::kData497Name },

                    { V8CompileHints_Version5::kData498NameHash, V8CompileHints_Version5::kData498Name },

                    { V8CompileHints_Version5::kData499NameHash, V8CompileHints_Version5::kData499Name },

                    { V8CompileHints_Version5::kData5NameHash, V8CompileHints_Version5::kData5Name },

                    { V8CompileHints_Version5::kData50NameHash, V8CompileHints_Version5::kData50Name },

                    { V8CompileHints_Version5::kData500NameHash, V8CompileHints_Version5::kData500Name },

                    { V8CompileHints_Version5::kData501NameHash, V8CompileHints_Version5::kData501Name },

                    { V8CompileHints_Version5::kData502NameHash, V8CompileHints_Version5::kData502Name },

                    { V8CompileHints_Version5::kData503NameHash, V8CompileHints_Version5::kData503Name },

                    { V8CompileHints_Version5::kData504NameHash, V8CompileHints_Version5::kData504Name },

                    { V8CompileHints_Version5::kData505NameHash, V8CompileHints_Version5::kData505Name },

                    { V8CompileHints_Version5::kData506NameHash, V8CompileHints_Version5::kData506Name },

                    { V8CompileHints_Version5::kData507NameHash, V8CompileHints_Version5::kData507Name },

                    { V8CompileHints_Version5::kData508NameHash, V8CompileHints_Version5::kData508Name },

                    { V8CompileHints_Version5::kData509NameHash, V8CompileHints_Version5::kData509Name },

                    { V8CompileHints_Version5::kData51NameHash, V8CompileHints_Version5::kData51Name },

                    { V8CompileHints_Version5::kData510NameHash, V8CompileHints_Version5::kData510Name },

                    { V8CompileHints_Version5::kData511NameHash, V8CompileHints_Version5::kData511Name },

                    { V8CompileHints_Version5::kData512NameHash, V8CompileHints_Version5::kData512Name },

                    { V8CompileHints_Version5::kData513NameHash, V8CompileHints_Version5::kData513Name },

                    { V8CompileHints_Version5::kData514NameHash, V8CompileHints_Version5::kData514Name },

                    { V8CompileHints_Version5::kData515NameHash, V8CompileHints_Version5::kData515Name },

                    { V8CompileHints_Version5::kData516NameHash, V8CompileHints_Version5::kData516Name },

                    { V8CompileHints_Version5::kData517NameHash, V8CompileHints_Version5::kData517Name },

                    { V8CompileHints_Version5::kData518NameHash, V8CompileHints_Version5::kData518Name },

                    { V8CompileHints_Version5::kData519NameHash, V8CompileHints_Version5::kData519Name },

                    { V8CompileHints_Version5::kData52NameHash, V8CompileHints_Version5::kData52Name },

                    { V8CompileHints_Version5::kData520NameHash, V8CompileHints_Version5::kData520Name },

                    { V8CompileHints_Version5::kData521NameHash, V8CompileHints_Version5::kData521Name },

                    { V8CompileHints_Version5::kData522NameHash, V8CompileHints_Version5::kData522Name },

                    { V8CompileHints_Version5::kData523NameHash, V8CompileHints_Version5::kData523Name },

                    { V8CompileHints_Version5::kData524NameHash, V8CompileHints_Version5::kData524Name },

                    { V8CompileHints_Version5::kData525NameHash, V8CompileHints_Version5::kData525Name },

                    { V8CompileHints_Version5::kData526NameHash, V8CompileHints_Version5::kData526Name },

                    { V8CompileHints_Version5::kData527NameHash, V8CompileHints_Version5::kData527Name },

                    { V8CompileHints_Version5::kData528NameHash, V8CompileHints_Version5::kData528Name },

                    { V8CompileHints_Version5::kData529NameHash, V8CompileHints_Version5::kData529Name },

                    { V8CompileHints_Version5::kData53NameHash, V8CompileHints_Version5::kData53Name },

                    { V8CompileHints_Version5::kData530NameHash, V8CompileHints_Version5::kData530Name },

                    { V8CompileHints_Version5::kData531NameHash, V8CompileHints_Version5::kData531Name },

                    { V8CompileHints_Version5::kData532NameHash, V8CompileHints_Version5::kData532Name },

                    { V8CompileHints_Version5::kData533NameHash, V8CompileHints_Version5::kData533Name },

                    { V8CompileHints_Version5::kData534NameHash, V8CompileHints_Version5::kData534Name },

                    { V8CompileHints_Version5::kData535NameHash, V8CompileHints_Version5::kData535Name },

                    { V8CompileHints_Version5::kData536NameHash, V8CompileHints_Version5::kData536Name },

                    { V8CompileHints_Version5::kData537NameHash, V8CompileHints_Version5::kData537Name },

                    { V8CompileHints_Version5::kData538NameHash, V8CompileHints_Version5::kData538Name },

                    { V8CompileHints_Version5::kData539NameHash, V8CompileHints_Version5::kData539Name },

                    { V8CompileHints_Version5::kData54NameHash, V8CompileHints_Version5::kData54Name },

                    { V8CompileHints_Version5::kData540NameHash, V8CompileHints_Version5::kData540Name },

                    { V8CompileHints_Version5::kData541NameHash, V8CompileHints_Version5::kData541Name },

                    { V8CompileHints_Version5::kData542NameHash, V8CompileHints_Version5::kData542Name },

                    { V8CompileHints_Version5::kData543NameHash, V8CompileHints_Version5::kData543Name },

                    { V8CompileHints_Version5::kData544NameHash, V8CompileHints_Version5::kData544Name },

                    { V8CompileHints_Version5::kData545NameHash, V8CompileHints_Version5::kData545Name },

                    { V8CompileHints_Version5::kData546NameHash, V8CompileHints_Version5::kData546Name },

                    { V8CompileHints_Version5::kData547NameHash, V8CompileHints_Version5::kData547Name },

                    { V8CompileHints_Version5::kData548NameHash, V8CompileHints_Version5::kData548Name },

                    { V8CompileHints_Version5::kData549NameHash, V8CompileHints_Version5::kData549Name },

                    { V8CompileHints_Version5::kData55NameHash, V8CompileHints_Version5::kData55Name },

                    { V8CompileHints_Version5::kData550NameHash, V8CompileHints_Version5::kData550Name },

                    { V8CompileHints_Version5::kData551NameHash, V8CompileHints_Version5::kData551Name },

                    { V8CompileHints_Version5::kData552NameHash, V8CompileHints_Version5::kData552Name },

                    { V8CompileHints_Version5::kData553NameHash, V8CompileHints_Version5::kData553Name },

                    { V8CompileHints_Version5::kData554NameHash, V8CompileHints_Version5::kData554Name },

                    { V8CompileHints_Version5::kData555NameHash, V8CompileHints_Version5::kData555Name },

                    { V8CompileHints_Version5::kData556NameHash, V8CompileHints_Version5::kData556Name },

                    { V8CompileHints_Version5::kData557NameHash, V8CompileHints_Version5::kData557Name },

                    { V8CompileHints_Version5::kData558NameHash, V8CompileHints_Version5::kData558Name },

                    { V8CompileHints_Version5::kData559NameHash, V8CompileHints_Version5::kData559Name },

                    { V8CompileHints_Version5::kData56NameHash, V8CompileHints_Version5::kData56Name },

                    { V8CompileHints_Version5::kData560NameHash, V8CompileHints_Version5::kData560Name },

                    { V8CompileHints_Version5::kData561NameHash, V8CompileHints_Version5::kData561Name },

                    { V8CompileHints_Version5::kData562NameHash, V8CompileHints_Version5::kData562Name },

                    { V8CompileHints_Version5::kData563NameHash, V8CompileHints_Version5::kData563Name },

                    { V8CompileHints_Version5::kData564NameHash, V8CompileHints_Version5::kData564Name },

                    { V8CompileHints_Version5::kData565NameHash, V8CompileHints_Version5::kData565Name },

                    { V8CompileHints_Version5::kData566NameHash, V8CompileHints_Version5::kData566Name },

                    { V8CompileHints_Version5::kData567NameHash, V8CompileHints_Version5::kData567Name },

                    { V8CompileHints_Version5::kData568NameHash, V8CompileHints_Version5::kData568Name },

                    { V8CompileHints_Version5::kData569NameHash, V8CompileHints_Version5::kData569Name },

                    { V8CompileHints_Version5::kData57NameHash, V8CompileHints_Version5::kData57Name },

                    { V8CompileHints_Version5::kData570NameHash, V8CompileHints_Version5::kData570Name },

                    { V8CompileHints_Version5::kData571NameHash, V8CompileHints_Version5::kData571Name },

                    { V8CompileHints_Version5::kData572NameHash, V8CompileHints_Version5::kData572Name },

                    { V8CompileHints_Version5::kData573NameHash, V8CompileHints_Version5::kData573Name },

                    { V8CompileHints_Version5::kData574NameHash, V8CompileHints_Version5::kData574Name },

                    { V8CompileHints_Version5::kData575NameHash, V8CompileHints_Version5::kData575Name },

                    { V8CompileHints_Version5::kData576NameHash, V8CompileHints_Version5::kData576Name },

                    { V8CompileHints_Version5::kData577NameHash, V8CompileHints_Version5::kData577Name },

                    { V8CompileHints_Version5::kData578NameHash, V8CompileHints_Version5::kData578Name },

                    { V8CompileHints_Version5::kData579NameHash, V8CompileHints_Version5::kData579Name },

                    { V8CompileHints_Version5::kData58NameHash, V8CompileHints_Version5::kData58Name },

                    { V8CompileHints_Version5::kData580NameHash, V8CompileHints_Version5::kData580Name },

                    { V8CompileHints_Version5::kData581NameHash, V8CompileHints_Version5::kData581Name },

                    { V8CompileHints_Version5::kData582NameHash, V8CompileHints_Version5::kData582Name },

                    { V8CompileHints_Version5::kData583NameHash, V8CompileHints_Version5::kData583Name },

                    { V8CompileHints_Version5::kData584NameHash, V8CompileHints_Version5::kData584Name },

                    { V8CompileHints_Version5::kData585NameHash, V8CompileHints_Version5::kData585Name },

                    { V8CompileHints_Version5::kData586NameHash, V8CompileHints_Version5::kData586Name },

                    { V8CompileHints_Version5::kData587NameHash, V8CompileHints_Version5::kData587Name },

                    { V8CompileHints_Version5::kData588NameHash, V8CompileHints_Version5::kData588Name },

                    { V8CompileHints_Version5::kData589NameHash, V8CompileHints_Version5::kData589Name },

                    { V8CompileHints_Version5::kData59NameHash, V8CompileHints_Version5::kData59Name },

                    { V8CompileHints_Version5::kData590NameHash, V8CompileHints_Version5::kData590Name },

                    { V8CompileHints_Version5::kData591NameHash, V8CompileHints_Version5::kData591Name },

                    { V8CompileHints_Version5::kData592NameHash, V8CompileHints_Version5::kData592Name },

                    { V8CompileHints_Version5::kData593NameHash, V8CompileHints_Version5::kData593Name },

                    { V8CompileHints_Version5::kData594NameHash, V8CompileHints_Version5::kData594Name },

                    { V8CompileHints_Version5::kData595NameHash, V8CompileHints_Version5::kData595Name },

                    { V8CompileHints_Version5::kData596NameHash, V8CompileHints_Version5::kData596Name },

                    { V8CompileHints_Version5::kData597NameHash, V8CompileHints_Version5::kData597Name },

                    { V8CompileHints_Version5::kData598NameHash, V8CompileHints_Version5::kData598Name },

                    { V8CompileHints_Version5::kData599NameHash, V8CompileHints_Version5::kData599Name },

                    { V8CompileHints_Version5::kData6NameHash, V8CompileHints_Version5::kData6Name },

                    { V8CompileHints_Version5::kData60NameHash, V8CompileHints_Version5::kData60Name },

                    { V8CompileHints_Version5::kData600NameHash, V8CompileHints_Version5::kData600Name },

                    { V8CompileHints_Version5::kData601NameHash, V8CompileHints_Version5::kData601Name },

                    { V8CompileHints_Version5::kData602NameHash, V8CompileHints_Version5::kData602Name },

                    { V8CompileHints_Version5::kData603NameHash, V8CompileHints_Version5::kData603Name },

                    { V8CompileHints_Version5::kData604NameHash, V8CompileHints_Version5::kData604Name },

                    { V8CompileHints_Version5::kData605NameHash, V8CompileHints_Version5::kData605Name },

                    { V8CompileHints_Version5::kData606NameHash, V8CompileHints_Version5::kData606Name },

                    { V8CompileHints_Version5::kData607NameHash, V8CompileHints_Version5::kData607Name },

                    { V8CompileHints_Version5::kData608NameHash, V8CompileHints_Version5::kData608Name },

                    { V8CompileHints_Version5::kData609NameHash, V8CompileHints_Version5::kData609Name },

                    { V8CompileHints_Version5::kData61NameHash, V8CompileHints_Version5::kData61Name },

                    { V8CompileHints_Version5::kData610NameHash, V8CompileHints_Version5::kData610Name },

                    { V8CompileHints_Version5::kData611NameHash, V8CompileHints_Version5::kData611Name },

                    { V8CompileHints_Version5::kData612NameHash, V8CompileHints_Version5::kData612Name },

                    { V8CompileHints_Version5::kData613NameHash, V8CompileHints_Version5::kData613Name },

                    { V8CompileHints_Version5::kData614NameHash, V8CompileHints_Version5::kData614Name },

                    { V8CompileHints_Version5::kData615NameHash, V8CompileHints_Version5::kData615Name },

                    { V8CompileHints_Version5::kData616NameHash, V8CompileHints_Version5::kData616Name },

                    { V8CompileHints_Version5::kData617NameHash, V8CompileHints_Version5::kData617Name },

                    { V8CompileHints_Version5::kData618NameHash, V8CompileHints_Version5::kData618Name },

                    { V8CompileHints_Version5::kData619NameHash, V8CompileHints_Version5::kData619Name },

                    { V8CompileHints_Version5::kData62NameHash, V8CompileHints_Version5::kData62Name },

                    { V8CompileHints_Version5::kData620NameHash, V8CompileHints_Version5::kData620Name },

                    { V8CompileHints_Version5::kData621NameHash, V8CompileHints_Version5::kData621Name },

                    { V8CompileHints_Version5::kData622NameHash, V8CompileHints_Version5::kData622Name },

                    { V8CompileHints_Version5::kData623NameHash, V8CompileHints_Version5::kData623Name },

                    { V8CompileHints_Version5::kData624NameHash, V8CompileHints_Version5::kData624Name },

                    { V8CompileHints_Version5::kData625NameHash, V8CompileHints_Version5::kData625Name },

                    { V8CompileHints_Version5::kData626NameHash, V8CompileHints_Version5::kData626Name },

                    { V8CompileHints_Version5::kData627NameHash, V8CompileHints_Version5::kData627Name },

                    { V8CompileHints_Version5::kData628NameHash, V8CompileHints_Version5::kData628Name },

                    { V8CompileHints_Version5::kData629NameHash, V8CompileHints_Version5::kData629Name },

                    { V8CompileHints_Version5::kData63NameHash, V8CompileHints_Version5::kData63Name },

                    { V8CompileHints_Version5::kData630NameHash, V8CompileHints_Version5::kData630Name },

                    { V8CompileHints_Version5::kData631NameHash, V8CompileHints_Version5::kData631Name },

                    { V8CompileHints_Version5::kData632NameHash, V8CompileHints_Version5::kData632Name },

                    { V8CompileHints_Version5::kData633NameHash, V8CompileHints_Version5::kData633Name },

                    { V8CompileHints_Version5::kData634NameHash, V8CompileHints_Version5::kData634Name },

                    { V8CompileHints_Version5::kData635NameHash, V8CompileHints_Version5::kData635Name },

                    { V8CompileHints_Version5::kData636NameHash, V8CompileHints_Version5::kData636Name },

                    { V8CompileHints_Version5::kData637NameHash, V8CompileHints_Version5::kData637Name },

                    { V8CompileHints_Version5::kData638NameHash, V8CompileHints_Version5::kData638Name },

                    { V8CompileHints_Version5::kData639NameHash, V8CompileHints_Version5::kData639Name },

                    { V8CompileHints_Version5::kData64NameHash, V8CompileHints_Version5::kData64Name },

                    { V8CompileHints_Version5::kData640NameHash, V8CompileHints_Version5::kData640Name },

                    { V8CompileHints_Version5::kData641NameHash, V8CompileHints_Version5::kData641Name },

                    { V8CompileHints_Version5::kData642NameHash, V8CompileHints_Version5::kData642Name },

                    { V8CompileHints_Version5::kData643NameHash, V8CompileHints_Version5::kData643Name },

                    { V8CompileHints_Version5::kData644NameHash, V8CompileHints_Version5::kData644Name },

                    { V8CompileHints_Version5::kData645NameHash, V8CompileHints_Version5::kData645Name },

                    { V8CompileHints_Version5::kData646NameHash, V8CompileHints_Version5::kData646Name },

                    { V8CompileHints_Version5::kData647NameHash, V8CompileHints_Version5::kData647Name },

                    { V8CompileHints_Version5::kData648NameHash, V8CompileHints_Version5::kData648Name },

                    { V8CompileHints_Version5::kData649NameHash, V8CompileHints_Version5::kData649Name },

                    { V8CompileHints_Version5::kData65NameHash, V8CompileHints_Version5::kData65Name },

                    { V8CompileHints_Version5::kData650NameHash, V8CompileHints_Version5::kData650Name },

                    { V8CompileHints_Version5::kData651NameHash, V8CompileHints_Version5::kData651Name },

                    { V8CompileHints_Version5::kData652NameHash, V8CompileHints_Version5::kData652Name },

                    { V8CompileHints_Version5::kData653NameHash, V8CompileHints_Version5::kData653Name },

                    { V8CompileHints_Version5::kData654NameHash, V8CompileHints_Version5::kData654Name },

                    { V8CompileHints_Version5::kData655NameHash, V8CompileHints_Version5::kData655Name },

                    { V8CompileHints_Version5::kData656NameHash, V8CompileHints_Version5::kData656Name },

                    { V8CompileHints_Version5::kData657NameHash, V8CompileHints_Version5::kData657Name },

                    { V8CompileHints_Version5::kData658NameHash, V8CompileHints_Version5::kData658Name },

                    { V8CompileHints_Version5::kData659NameHash, V8CompileHints_Version5::kData659Name },

                    { V8CompileHints_Version5::kData66NameHash, V8CompileHints_Version5::kData66Name },

                    { V8CompileHints_Version5::kData660NameHash, V8CompileHints_Version5::kData660Name },

                    { V8CompileHints_Version5::kData661NameHash, V8CompileHints_Version5::kData661Name },

                    { V8CompileHints_Version5::kData662NameHash, V8CompileHints_Version5::kData662Name },

                    { V8CompileHints_Version5::kData663NameHash, V8CompileHints_Version5::kData663Name },

                    { V8CompileHints_Version5::kData664NameHash, V8CompileHints_Version5::kData664Name },

                    { V8CompileHints_Version5::kData665NameHash, V8CompileHints_Version5::kData665Name },

                    { V8CompileHints_Version5::kData666NameHash, V8CompileHints_Version5::kData666Name },

                    { V8CompileHints_Version5::kData667NameHash, V8CompileHints_Version5::kData667Name },

                    { V8CompileHints_Version5::kData668NameHash, V8CompileHints_Version5::kData668Name },

                    { V8CompileHints_Version5::kData669NameHash, V8CompileHints_Version5::kData669Name },

                    { V8CompileHints_Version5::kData67NameHash, V8CompileHints_Version5::kData67Name },

                    { V8CompileHints_Version5::kData670NameHash, V8CompileHints_Version5::kData670Name },

                    { V8CompileHints_Version5::kData671NameHash, V8CompileHints_Version5::kData671Name },

                    { V8CompileHints_Version5::kData672NameHash, V8CompileHints_Version5::kData672Name },

                    { V8CompileHints_Version5::kData673NameHash, V8CompileHints_Version5::kData673Name },

                    { V8CompileHints_Version5::kData674NameHash, V8CompileHints_Version5::kData674Name },

                    { V8CompileHints_Version5::kData675NameHash, V8CompileHints_Version5::kData675Name },

                    { V8CompileHints_Version5::kData676NameHash, V8CompileHints_Version5::kData676Name },

                    { V8CompileHints_Version5::kData677NameHash, V8CompileHints_Version5::kData677Name },

                    { V8CompileHints_Version5::kData678NameHash, V8CompileHints_Version5::kData678Name },

                    { V8CompileHints_Version5::kData679NameHash, V8CompileHints_Version5::kData679Name },

                    { V8CompileHints_Version5::kData68NameHash, V8CompileHints_Version5::kData68Name },

                    { V8CompileHints_Version5::kData680NameHash, V8CompileHints_Version5::kData680Name },

                    { V8CompileHints_Version5::kData681NameHash, V8CompileHints_Version5::kData681Name },

                    { V8CompileHints_Version5::kData682NameHash, V8CompileHints_Version5::kData682Name },

                    { V8CompileHints_Version5::kData683NameHash, V8CompileHints_Version5::kData683Name },

                    { V8CompileHints_Version5::kData684NameHash, V8CompileHints_Version5::kData684Name },

                    { V8CompileHints_Version5::kData685NameHash, V8CompileHints_Version5::kData685Name },

                    { V8CompileHints_Version5::kData686NameHash, V8CompileHints_Version5::kData686Name },

                    { V8CompileHints_Version5::kData687NameHash, V8CompileHints_Version5::kData687Name },

                    { V8CompileHints_Version5::kData688NameHash, V8CompileHints_Version5::kData688Name },

                    { V8CompileHints_Version5::kData689NameHash, V8CompileHints_Version5::kData689Name },

                    { V8CompileHints_Version5::kData69NameHash, V8CompileHints_Version5::kData69Name },

                    { V8CompileHints_Version5::kData690NameHash, V8CompileHints_Version5::kData690Name },

                    { V8CompileHints_Version5::kData691NameHash, V8CompileHints_Version5::kData691Name },

                    { V8CompileHints_Version5::kData692NameHash, V8CompileHints_Version5::kData692Name },

                    { V8CompileHints_Version5::kData693NameHash, V8CompileHints_Version5::kData693Name },

                    { V8CompileHints_Version5::kData694NameHash, V8CompileHints_Version5::kData694Name },

                    { V8CompileHints_Version5::kData695NameHash, V8CompileHints_Version5::kData695Name },

                    { V8CompileHints_Version5::kData696NameHash, V8CompileHints_Version5::kData696Name },

                    { V8CompileHints_Version5::kData697NameHash, V8CompileHints_Version5::kData697Name },

                    { V8CompileHints_Version5::kData698NameHash, V8CompileHints_Version5::kData698Name },

                    { V8CompileHints_Version5::kData699NameHash, V8CompileHints_Version5::kData699Name },

                    { V8CompileHints_Version5::kData7NameHash, V8CompileHints_Version5::kData7Name },

                    { V8CompileHints_Version5::kData70NameHash, V8CompileHints_Version5::kData70Name },

                    { V8CompileHints_Version5::kData700NameHash, V8CompileHints_Version5::kData700Name },

                    { V8CompileHints_Version5::kData701NameHash, V8CompileHints_Version5::kData701Name },

                    { V8CompileHints_Version5::kData702NameHash, V8CompileHints_Version5::kData702Name },

                    { V8CompileHints_Version5::kData703NameHash, V8CompileHints_Version5::kData703Name },

                    { V8CompileHints_Version5::kData704NameHash, V8CompileHints_Version5::kData704Name },

                    { V8CompileHints_Version5::kData705NameHash, V8CompileHints_Version5::kData705Name },

                    { V8CompileHints_Version5::kData706NameHash, V8CompileHints_Version5::kData706Name },

                    { V8CompileHints_Version5::kData707NameHash, V8CompileHints_Version5::kData707Name },

                    { V8CompileHints_Version5::kData708NameHash, V8CompileHints_Version5::kData708Name },

                    { V8CompileHints_Version5::kData709NameHash, V8CompileHints_Version5::kData709Name },

                    { V8CompileHints_Version5::kData71NameHash, V8CompileHints_Version5::kData71Name },

                    { V8CompileHints_Version5::kData710NameHash, V8CompileHints_Version5::kData710Name },

                    { V8CompileHints_Version5::kData711NameHash, V8CompileHints_Version5::kData711Name },

                    { V8CompileHints_Version5::kData712NameHash, V8CompileHints_Version5::kData712Name },

                    { V8CompileHints_Version5::kData713NameHash, V8CompileHints_Version5::kData713Name },

                    { V8CompileHints_Version5::kData714NameHash, V8CompileHints_Version5::kData714Name },

                    { V8CompileHints_Version5::kData715NameHash, V8CompileHints_Version5::kData715Name },

                    { V8CompileHints_Version5::kData716NameHash, V8CompileHints_Version5::kData716Name },

                    { V8CompileHints_Version5::kData717NameHash, V8CompileHints_Version5::kData717Name },

                    { V8CompileHints_Version5::kData718NameHash, V8CompileHints_Version5::kData718Name },

                    { V8CompileHints_Version5::kData719NameHash, V8CompileHints_Version5::kData719Name },

                    { V8CompileHints_Version5::kData72NameHash, V8CompileHints_Version5::kData72Name },

                    { V8CompileHints_Version5::kData720NameHash, V8CompileHints_Version5::kData720Name },

                    { V8CompileHints_Version5::kData721NameHash, V8CompileHints_Version5::kData721Name },

                    { V8CompileHints_Version5::kData722NameHash, V8CompileHints_Version5::kData722Name },

                    { V8CompileHints_Version5::kData723NameHash, V8CompileHints_Version5::kData723Name },

                    { V8CompileHints_Version5::kData724NameHash, V8CompileHints_Version5::kData724Name },

                    { V8CompileHints_Version5::kData725NameHash, V8CompileHints_Version5::kData725Name },

                    { V8CompileHints_Version5::kData726NameHash, V8CompileHints_Version5::kData726Name },

                    { V8CompileHints_Version5::kData727NameHash, V8CompileHints_Version5::kData727Name },

                    { V8CompileHints_Version5::kData728NameHash, V8CompileHints_Version5::kData728Name },

                    { V8CompileHints_Version5::kData729NameHash, V8CompileHints_Version5::kData729Name },

                    { V8CompileHints_Version5::kData73NameHash, V8CompileHints_Version5::kData73Name },

                    { V8CompileHints_Version5::kData730NameHash, V8CompileHints_Version5::kData730Name },

                    { V8CompileHints_Version5::kData731NameHash, V8CompileHints_Version5::kData731Name },

                    { V8CompileHints_Version5::kData732NameHash, V8CompileHints_Version5::kData732Name },

                    { V8CompileHints_Version5::kData733NameHash, V8CompileHints_Version5::kData733Name },

                    { V8CompileHints_Version5::kData734NameHash, V8CompileHints_Version5::kData734Name },

                    { V8CompileHints_Version5::kData735NameHash, V8CompileHints_Version5::kData735Name },

                    { V8CompileHints_Version5::kData736NameHash, V8CompileHints_Version5::kData736Name },

                    { V8CompileHints_Version5::kData737NameHash, V8CompileHints_Version5::kData737Name },

                    { V8CompileHints_Version5::kData738NameHash, V8CompileHints_Version5::kData738Name },

                    { V8CompileHints_Version5::kData739NameHash, V8CompileHints_Version5::kData739Name },

                    { V8CompileHints_Version5::kData74NameHash, V8CompileHints_Version5::kData74Name },

                    { V8CompileHints_Version5::kData740NameHash, V8CompileHints_Version5::kData740Name },

                    { V8CompileHints_Version5::kData741NameHash, V8CompileHints_Version5::kData741Name },

                    { V8CompileHints_Version5::kData742NameHash, V8CompileHints_Version5::kData742Name },

                    { V8CompileHints_Version5::kData743NameHash, V8CompileHints_Version5::kData743Name },

                    { V8CompileHints_Version5::kData744NameHash, V8CompileHints_Version5::kData744Name },

                    { V8CompileHints_Version5::kData745NameHash, V8CompileHints_Version5::kData745Name },

                    { V8CompileHints_Version5::kData746NameHash, V8CompileHints_Version5::kData746Name },

                    { V8CompileHints_Version5::kData747NameHash, V8CompileHints_Version5::kData747Name },

                    { V8CompileHints_Version5::kData748NameHash, V8CompileHints_Version5::kData748Name },

                    { V8CompileHints_Version5::kData749NameHash, V8CompileHints_Version5::kData749Name },

                    { V8CompileHints_Version5::kData75NameHash, V8CompileHints_Version5::kData75Name },

                    { V8CompileHints_Version5::kData750NameHash, V8CompileHints_Version5::kData750Name },

                    { V8CompileHints_Version5::kData751NameHash, V8CompileHints_Version5::kData751Name },

                    { V8CompileHints_Version5::kData752NameHash, V8CompileHints_Version5::kData752Name },

                    { V8CompileHints_Version5::kData753NameHash, V8CompileHints_Version5::kData753Name },

                    { V8CompileHints_Version5::kData754NameHash, V8CompileHints_Version5::kData754Name },

                    { V8CompileHints_Version5::kData755NameHash, V8CompileHints_Version5::kData755Name },

                    { V8CompileHints_Version5::kData756NameHash, V8CompileHints_Version5::kData756Name },

                    { V8CompileHints_Version5::kData757NameHash, V8CompileHints_Version5::kData757Name },

                    { V8CompileHints_Version5::kData758NameHash, V8CompileHints_Version5::kData758Name },

                    { V8CompileHints_Version5::kData759NameHash, V8CompileHints_Version5::kData759Name },

                    { V8CompileHints_Version5::kData76NameHash, V8CompileHints_Version5::kData76Name },

                    { V8CompileHints_Version5::kData760NameHash, V8CompileHints_Version5::kData760Name },

                    { V8CompileHints_Version5::kData761NameHash, V8CompileHints_Version5::kData761Name },

                    { V8CompileHints_Version5::kData762NameHash, V8CompileHints_Version5::kData762Name },

                    { V8CompileHints_Version5::kData763NameHash, V8CompileHints_Version5::kData763Name },

                    { V8CompileHints_Version5::kData764NameHash, V8CompileHints_Version5::kData764Name },

                    { V8CompileHints_Version5::kData765NameHash, V8CompileHints_Version5::kData765Name },

                    { V8CompileHints_Version5::kData766NameHash, V8CompileHints_Version5::kData766Name },

                    { V8CompileHints_Version5::kData767NameHash, V8CompileHints_Version5::kData767Name },

                    { V8CompileHints_Version5::kData768NameHash, V8CompileHints_Version5::kData768Name },

                    { V8CompileHints_Version5::kData769NameHash, V8CompileHints_Version5::kData769Name },

                    { V8CompileHints_Version5::kData77NameHash, V8CompileHints_Version5::kData77Name },

                    { V8CompileHints_Version5::kData770NameHash, V8CompileHints_Version5::kData770Name },

                    { V8CompileHints_Version5::kData771NameHash, V8CompileHints_Version5::kData771Name },

                    { V8CompileHints_Version5::kData772NameHash, V8CompileHints_Version5::kData772Name },

                    { V8CompileHints_Version5::kData773NameHash, V8CompileHints_Version5::kData773Name },

                    { V8CompileHints_Version5::kData774NameHash, V8CompileHints_Version5::kData774Name },

                    { V8CompileHints_Version5::kData775NameHash, V8CompileHints_Version5::kData775Name },

                    { V8CompileHints_Version5::kData776NameHash, V8CompileHints_Version5::kData776Name },

                    { V8CompileHints_Version5::kData777NameHash, V8CompileHints_Version5::kData777Name },

                    { V8CompileHints_Version5::kData778NameHash, V8CompileHints_Version5::kData778Name },

                    { V8CompileHints_Version5::kData779NameHash, V8CompileHints_Version5::kData779Name },

                    { V8CompileHints_Version5::kData78NameHash, V8CompileHints_Version5::kData78Name },

                    { V8CompileHints_Version5::kData780NameHash, V8CompileHints_Version5::kData780Name },

                    { V8CompileHints_Version5::kData781NameHash, V8CompileHints_Version5::kData781Name },

                    { V8CompileHints_Version5::kData782NameHash, V8CompileHints_Version5::kData782Name },

                    { V8CompileHints_Version5::kData783NameHash, V8CompileHints_Version5::kData783Name },

                    { V8CompileHints_Version5::kData784NameHash, V8CompileHints_Version5::kData784Name },

                    { V8CompileHints_Version5::kData785NameHash, V8CompileHints_Version5::kData785Name },

                    { V8CompileHints_Version5::kData786NameHash, V8CompileHints_Version5::kData786Name },

                    { V8CompileHints_Version5::kData787NameHash, V8CompileHints_Version5::kData787Name },

                    { V8CompileHints_Version5::kData788NameHash, V8CompileHints_Version5::kData788Name },

                    { V8CompileHints_Version5::kData789NameHash, V8CompileHints_Version5::kData789Name },

                    { V8CompileHints_Version5::kData79NameHash, V8CompileHints_Version5::kData79Name },

                    { V8CompileHints_Version5::kData790NameHash, V8CompileHints_Version5::kData790Name },

                    { V8CompileHints_Version5::kData791NameHash, V8CompileHints_Version5::kData791Name },

                    { V8CompileHints_Version5::kData792NameHash, V8CompileHints_Version5::kData792Name },

                    { V8CompileHints_Version5::kData793NameHash, V8CompileHints_Version5::kData793Name },

                    { V8CompileHints_Version5::kData794NameHash, V8CompileHints_Version5::kData794Name },

                    { V8CompileHints_Version5::kData795NameHash, V8CompileHints_Version5::kData795Name },

                    { V8CompileHints_Version5::kData796NameHash, V8CompileHints_Version5::kData796Name },

                    { V8CompileHints_Version5::kData797NameHash, V8CompileHints_Version5::kData797Name },

                    { V8CompileHints_Version5::kData798NameHash, V8CompileHints_Version5::kData798Name },

                    { V8CompileHints_Version5::kData799NameHash, V8CompileHints_Version5::kData799Name },

                    { V8CompileHints_Version5::kData8NameHash, V8CompileHints_Version5::kData8Name },

                    { V8CompileHints_Version5::kData80NameHash, V8CompileHints_Version5::kData80Name },

                    { V8CompileHints_Version5::kData800NameHash, V8CompileHints_Version5::kData800Name },

                    { V8CompileHints_Version5::kData801NameHash, V8CompileHints_Version5::kData801Name },

                    { V8CompileHints_Version5::kData802NameHash, V8CompileHints_Version5::kData802Name },

                    { V8CompileHints_Version5::kData803NameHash, V8CompileHints_Version5::kData803Name },

                    { V8CompileHints_Version5::kData804NameHash, V8CompileHints_Version5::kData804Name },

                    { V8CompileHints_Version5::kData805NameHash, V8CompileHints_Version5::kData805Name },

                    { V8CompileHints_Version5::kData806NameHash, V8CompileHints_Version5::kData806Name },

                    { V8CompileHints_Version5::kData807NameHash, V8CompileHints_Version5::kData807Name },

                    { V8CompileHints_Version5::kData808NameHash, V8CompileHints_Version5::kData808Name },

                    { V8CompileHints_Version5::kData809NameHash, V8CompileHints_Version5::kData809Name },

                    { V8CompileHints_Version5::kData81NameHash, V8CompileHints_Version5::kData81Name },

                    { V8CompileHints_Version5::kData810NameHash, V8CompileHints_Version5::kData810Name },

                    { V8CompileHints_Version5::kData811NameHash, V8CompileHints_Version5::kData811Name },

                    { V8CompileHints_Version5::kData812NameHash, V8CompileHints_Version5::kData812Name },

                    { V8CompileHints_Version5::kData813NameHash, V8CompileHints_Version5::kData813Name },

                    { V8CompileHints_Version5::kData814NameHash, V8CompileHints_Version5::kData814Name },

                    { V8CompileHints_Version5::kData815NameHash, V8CompileHints_Version5::kData815Name },

                    { V8CompileHints_Version5::kData816NameHash, V8CompileHints_Version5::kData816Name },

                    { V8CompileHints_Version5::kData817NameHash, V8CompileHints_Version5::kData817Name },

                    { V8CompileHints_Version5::kData818NameHash, V8CompileHints_Version5::kData818Name },

                    { V8CompileHints_Version5::kData819NameHash, V8CompileHints_Version5::kData819Name },

                    { V8CompileHints_Version5::kData82NameHash, V8CompileHints_Version5::kData82Name },

                    { V8CompileHints_Version5::kData820NameHash, V8CompileHints_Version5::kData820Name },

                    { V8CompileHints_Version5::kData821NameHash, V8CompileHints_Version5::kData821Name },

                    { V8CompileHints_Version5::kData822NameHash, V8CompileHints_Version5::kData822Name },

                    { V8CompileHints_Version5::kData823NameHash, V8CompileHints_Version5::kData823Name },

                    { V8CompileHints_Version5::kData824NameHash, V8CompileHints_Version5::kData824Name },

                    { V8CompileHints_Version5::kData825NameHash, V8CompileHints_Version5::kData825Name },

                    { V8CompileHints_Version5::kData826NameHash, V8CompileHints_Version5::kData826Name },

                    { V8CompileHints_Version5::kData827NameHash, V8CompileHints_Version5::kData827Name },

                    { V8CompileHints_Version5::kData828NameHash, V8CompileHints_Version5::kData828Name },

                    { V8CompileHints_Version5::kData829NameHash, V8CompileHints_Version5::kData829Name },

                    { V8CompileHints_Version5::kData83NameHash, V8CompileHints_Version5::kData83Name },

                    { V8CompileHints_Version5::kData830NameHash, V8CompileHints_Version5::kData830Name },

                    { V8CompileHints_Version5::kData831NameHash, V8CompileHints_Version5::kData831Name },

                    { V8CompileHints_Version5::kData832NameHash, V8CompileHints_Version5::kData832Name },

                    { V8CompileHints_Version5::kData833NameHash, V8CompileHints_Version5::kData833Name },

                    { V8CompileHints_Version5::kData834NameHash, V8CompileHints_Version5::kData834Name },

                    { V8CompileHints_Version5::kData835NameHash, V8CompileHints_Version5::kData835Name },

                    { V8CompileHints_Version5::kData836NameHash, V8CompileHints_Version5::kData836Name },

                    { V8CompileHints_Version5::kData837NameHash, V8CompileHints_Version5::kData837Name },

                    { V8CompileHints_Version5::kData838NameHash, V8CompileHints_Version5::kData838Name },

                    { V8CompileHints_Version5::kData839NameHash, V8CompileHints_Version5::kData839Name },

                    { V8CompileHints_Version5::kData84NameHash, V8CompileHints_Version5::kData84Name },

                    { V8CompileHints_Version5::kData840NameHash, V8CompileHints_Version5::kData840Name },

                    { V8CompileHints_Version5::kData841NameHash, V8CompileHints_Version5::kData841Name },

                    { V8CompileHints_Version5::kData842NameHash, V8CompileHints_Version5::kData842Name },

                    { V8CompileHints_Version5::kData843NameHash, V8CompileHints_Version5::kData843Name },

                    { V8CompileHints_Version5::kData844NameHash, V8CompileHints_Version5::kData844Name },

                    { V8CompileHints_Version5::kData845NameHash, V8CompileHints_Version5::kData845Name },

                    { V8CompileHints_Version5::kData846NameHash, V8CompileHints_Version5::kData846Name },

                    { V8CompileHints_Version5::kData847NameHash, V8CompileHints_Version5::kData847Name },

                    { V8CompileHints_Version5::kData848NameHash, V8CompileHints_Version5::kData848Name },

                    { V8CompileHints_Version5::kData849NameHash, V8CompileHints_Version5::kData849Name },

                    { V8CompileHints_Version5::kData85NameHash, V8CompileHints_Version5::kData85Name },

                    { V8CompileHints_Version5::kData850NameHash, V8CompileHints_Version5::kData850Name },

                    { V8CompileHints_Version5::kData851NameHash, V8CompileHints_Version5::kData851Name },

                    { V8CompileHints_Version5::kData852NameHash, V8CompileHints_Version5::kData852Name },

                    { V8CompileHints_Version5::kData853NameHash, V8CompileHints_Version5::kData853Name },

                    { V8CompileHints_Version5::kData854NameHash, V8CompileHints_Version5::kData854Name },

                    { V8CompileHints_Version5::kData855NameHash, V8CompileHints_Version5::kData855Name },

                    { V8CompileHints_Version5::kData856NameHash, V8CompileHints_Version5::kData856Name },

                    { V8CompileHints_Version5::kData857NameHash, V8CompileHints_Version5::kData857Name },

                    { V8CompileHints_Version5::kData858NameHash, V8CompileHints_Version5::kData858Name },

                    { V8CompileHints_Version5::kData859NameHash, V8CompileHints_Version5::kData859Name },

                    { V8CompileHints_Version5::kData86NameHash, V8CompileHints_Version5::kData86Name },

                    { V8CompileHints_Version5::kData860NameHash, V8CompileHints_Version5::kData860Name },

                    { V8CompileHints_Version5::kData861NameHash, V8CompileHints_Version5::kData861Name },

                    { V8CompileHints_Version5::kData862NameHash, V8CompileHints_Version5::kData862Name },

                    { V8CompileHints_Version5::kData863NameHash, V8CompileHints_Version5::kData863Name },

                    { V8CompileHints_Version5::kData864NameHash, V8CompileHints_Version5::kData864Name },

                    { V8CompileHints_Version5::kData865NameHash, V8CompileHints_Version5::kData865Name },

                    { V8CompileHints_Version5::kData866NameHash, V8CompileHints_Version5::kData866Name },

                    { V8CompileHints_Version5::kData867NameHash, V8CompileHints_Version5::kData867Name },

                    { V8CompileHints_Version5::kData868NameHash, V8CompileHints_Version5::kData868Name },

                    { V8CompileHints_Version5::kData869NameHash, V8CompileHints_Version5::kData869Name },

                    { V8CompileHints_Version5::kData87NameHash, V8CompileHints_Version5::kData87Name },

                    { V8CompileHints_Version5::kData870NameHash, V8CompileHints_Version5::kData870Name },

                    { V8CompileHints_Version5::kData871NameHash, V8CompileHints_Version5::kData871Name },

                    { V8CompileHints_Version5::kData872NameHash, V8CompileHints_Version5::kData872Name },

                    { V8CompileHints_Version5::kData873NameHash, V8CompileHints_Version5::kData873Name },

                    { V8CompileHints_Version5::kData874NameHash, V8CompileHints_Version5::kData874Name },

                    { V8CompileHints_Version5::kData875NameHash, V8CompileHints_Version5::kData875Name },

                    { V8CompileHints_Version5::kData876NameHash, V8CompileHints_Version5::kData876Name },

                    { V8CompileHints_Version5::kData877NameHash, V8CompileHints_Version5::kData877Name },

                    { V8CompileHints_Version5::kData878NameHash, V8CompileHints_Version5::kData878Name },

                    { V8CompileHints_Version5::kData879NameHash, V8CompileHints_Version5::kData879Name },

                    { V8CompileHints_Version5::kData88NameHash, V8CompileHints_Version5::kData88Name },

                    { V8CompileHints_Version5::kData880NameHash, V8CompileHints_Version5::kData880Name },

                    { V8CompileHints_Version5::kData881NameHash, V8CompileHints_Version5::kData881Name },

                    { V8CompileHints_Version5::kData882NameHash, V8CompileHints_Version5::kData882Name },

                    { V8CompileHints_Version5::kData883NameHash, V8CompileHints_Version5::kData883Name },

                    { V8CompileHints_Version5::kData884NameHash, V8CompileHints_Version5::kData884Name },

                    { V8CompileHints_Version5::kData885NameHash, V8CompileHints_Version5::kData885Name },

                    { V8CompileHints_Version5::kData886NameHash, V8CompileHints_Version5::kData886Name },

                    { V8CompileHints_Version5::kData887NameHash, V8CompileHints_Version5::kData887Name },

                    { V8CompileHints_Version5::kData888NameHash, V8CompileHints_Version5::kData888Name },

                    { V8CompileHints_Version5::kData889NameHash, V8CompileHints_Version5::kData889Name },

                    { V8CompileHints_Version5::kData89NameHash, V8CompileHints_Version5::kData89Name },

                    { V8CompileHints_Version5::kData890NameHash, V8CompileHints_Version5::kData890Name },

                    { V8CompileHints_Version5::kData891NameHash, V8CompileHints_Version5::kData891Name },

                    { V8CompileHints_Version5::kData892NameHash, V8CompileHints_Version5::kData892Name },

                    { V8CompileHints_Version5::kData893NameHash, V8CompileHints_Version5::kData893Name },

                    { V8CompileHints_Version5::kData894NameHash, V8CompileHints_Version5::kData894Name },

                    { V8CompileHints_Version5::kData895NameHash, V8CompileHints_Version5::kData895Name },

                    { V8CompileHints_Version5::kData896NameHash, V8CompileHints_Version5::kData896Name },

                    { V8CompileHints_Version5::kData897NameHash, V8CompileHints_Version5::kData897Name },

                    { V8CompileHints_Version5::kData898NameHash, V8CompileHints_Version5::kData898Name },

                    { V8CompileHints_Version5::kData899NameHash, V8CompileHints_Version5::kData899Name },

                    { V8CompileHints_Version5::kData9NameHash, V8CompileHints_Version5::kData9Name },

                    { V8CompileHints_Version5::kData90NameHash, V8CompileHints_Version5::kData90Name },

                    { V8CompileHints_Version5::kData900NameHash, V8CompileHints_Version5::kData900Name },

                    { V8CompileHints_Version5::kData901NameHash, V8CompileHints_Version5::kData901Name },

                    { V8CompileHints_Version5::kData902NameHash, V8CompileHints_Version5::kData902Name },

                    { V8CompileHints_Version5::kData903NameHash, V8CompileHints_Version5::kData903Name },

                    { V8CompileHints_Version5::kData904NameHash, V8CompileHints_Version5::kData904Name },

                    { V8CompileHints_Version5::kData905NameHash, V8CompileHints_Version5::kData905Name },

                    { V8CompileHints_Version5::kData906NameHash, V8CompileHints_Version5::kData906Name },

                    { V8CompileHints_Version5::kData907NameHash, V8CompileHints_Version5::kData907Name },

                    { V8CompileHints_Version5::kData908NameHash, V8CompileHints_Version5::kData908Name },

                    { V8CompileHints_Version5::kData909NameHash, V8CompileHints_Version5::kData909Name },

                    { V8CompileHints_Version5::kData91NameHash, V8CompileHints_Version5::kData91Name },

                    { V8CompileHints_Version5::kData910NameHash, V8CompileHints_Version5::kData910Name },

                    { V8CompileHints_Version5::kData911NameHash, V8CompileHints_Version5::kData911Name },

                    { V8CompileHints_Version5::kData912NameHash, V8CompileHints_Version5::kData912Name },

                    { V8CompileHints_Version5::kData913NameHash, V8CompileHints_Version5::kData913Name },

                    { V8CompileHints_Version5::kData914NameHash, V8CompileHints_Version5::kData914Name },

                    { V8CompileHints_Version5::kData915NameHash, V8CompileHints_Version5::kData915Name },

                    { V8CompileHints_Version5::kData916NameHash, V8CompileHints_Version5::kData916Name },

                    { V8CompileHints_Version5::kData917NameHash, V8CompileHints_Version5::kData917Name },

                    { V8CompileHints_Version5::kData918NameHash, V8CompileHints_Version5::kData918Name },

                    { V8CompileHints_Version5::kData919NameHash, V8CompileHints_Version5::kData919Name },

                    { V8CompileHints_Version5::kData92NameHash, V8CompileHints_Version5::kData92Name },

                    { V8CompileHints_Version5::kData920NameHash, V8CompileHints_Version5::kData920Name },

                    { V8CompileHints_Version5::kData921NameHash, V8CompileHints_Version5::kData921Name },

                    { V8CompileHints_Version5::kData922NameHash, V8CompileHints_Version5::kData922Name },

                    { V8CompileHints_Version5::kData923NameHash, V8CompileHints_Version5::kData923Name },

                    { V8CompileHints_Version5::kData924NameHash, V8CompileHints_Version5::kData924Name },

                    { V8CompileHints_Version5::kData925NameHash, V8CompileHints_Version5::kData925Name },

                    { V8CompileHints_Version5::kData926NameHash, V8CompileHints_Version5::kData926Name },

                    { V8CompileHints_Version5::kData927NameHash, V8CompileHints_Version5::kData927Name },

                    { V8CompileHints_Version5::kData928NameHash, V8CompileHints_Version5::kData928Name },

                    { V8CompileHints_Version5::kData929NameHash, V8CompileHints_Version5::kData929Name },

                    { V8CompileHints_Version5::kData93NameHash, V8CompileHints_Version5::kData93Name },

                    { V8CompileHints_Version5::kData930NameHash, V8CompileHints_Version5::kData930Name },

                    { V8CompileHints_Version5::kData931NameHash, V8CompileHints_Version5::kData931Name },

                    { V8CompileHints_Version5::kData932NameHash, V8CompileHints_Version5::kData932Name },

                    { V8CompileHints_Version5::kData933NameHash, V8CompileHints_Version5::kData933Name },

                    { V8CompileHints_Version5::kData934NameHash, V8CompileHints_Version5::kData934Name },

                    { V8CompileHints_Version5::kData935NameHash, V8CompileHints_Version5::kData935Name },

                    { V8CompileHints_Version5::kData936NameHash, V8CompileHints_Version5::kData936Name },

                    { V8CompileHints_Version5::kData937NameHash, V8CompileHints_Version5::kData937Name },

                    { V8CompileHints_Version5::kData938NameHash, V8CompileHints_Version5::kData938Name },

                    { V8CompileHints_Version5::kData939NameHash, V8CompileHints_Version5::kData939Name },

                    { V8CompileHints_Version5::kData94NameHash, V8CompileHints_Version5::kData94Name },

                    { V8CompileHints_Version5::kData940NameHash, V8CompileHints_Version5::kData940Name },

                    { V8CompileHints_Version5::kData941NameHash, V8CompileHints_Version5::kData941Name },

                    { V8CompileHints_Version5::kData942NameHash, V8CompileHints_Version5::kData942Name },

                    { V8CompileHints_Version5::kData943NameHash, V8CompileHints_Version5::kData943Name },

                    { V8CompileHints_Version5::kData944NameHash, V8CompileHints_Version5::kData944Name },

                    { V8CompileHints_Version5::kData945NameHash, V8CompileHints_Version5::kData945Name },

                    { V8CompileHints_Version5::kData946NameHash, V8CompileHints_Version5::kData946Name },

                    { V8CompileHints_Version5::kData947NameHash, V8CompileHints_Version5::kData947Name },

                    { V8CompileHints_Version5::kData948NameHash, V8CompileHints_Version5::kData948Name },

                    { V8CompileHints_Version5::kData949NameHash, V8CompileHints_Version5::kData949Name },

                    { V8CompileHints_Version5::kData95NameHash, V8CompileHints_Version5::kData95Name },

                    { V8CompileHints_Version5::kData950NameHash, V8CompileHints_Version5::kData950Name },

                    { V8CompileHints_Version5::kData951NameHash, V8CompileHints_Version5::kData951Name },

                    { V8CompileHints_Version5::kData952NameHash, V8CompileHints_Version5::kData952Name },

                    { V8CompileHints_Version5::kData953NameHash, V8CompileHints_Version5::kData953Name },

                    { V8CompileHints_Version5::kData954NameHash, V8CompileHints_Version5::kData954Name },

                    { V8CompileHints_Version5::kData955NameHash, V8CompileHints_Version5::kData955Name },

                    { V8CompileHints_Version5::kData956NameHash, V8CompileHints_Version5::kData956Name },

                    { V8CompileHints_Version5::kData957NameHash, V8CompileHints_Version5::kData957Name },

                    { V8CompileHints_Version5::kData958NameHash, V8CompileHints_Version5::kData958Name },

                    { V8CompileHints_Version5::kData959NameHash, V8CompileHints_Version5::kData959Name },

                    { V8CompileHints_Version5::kData96NameHash, V8CompileHints_Version5::kData96Name },

                    { V8CompileHints_Version5::kData960NameHash, V8CompileHints_Version5::kData960Name },

                    { V8CompileHints_Version5::kData961NameHash, V8CompileHints_Version5::kData961Name },

                    { V8CompileHints_Version5::kData962NameHash, V8CompileHints_Version5::kData962Name },

                    { V8CompileHints_Version5::kData963NameHash, V8CompileHints_Version5::kData963Name },

                    { V8CompileHints_Version5::kData964NameHash, V8CompileHints_Version5::kData964Name },

                    { V8CompileHints_Version5::kData965NameHash, V8CompileHints_Version5::kData965Name },

                    { V8CompileHints_Version5::kData966NameHash, V8CompileHints_Version5::kData966Name },

                    { V8CompileHints_Version5::kData967NameHash, V8CompileHints_Version5::kData967Name },

                    { V8CompileHints_Version5::kData968NameHash, V8CompileHints_Version5::kData968Name },

                    { V8CompileHints_Version5::kData969NameHash, V8CompileHints_Version5::kData969Name },

                    { V8CompileHints_Version5::kData97NameHash, V8CompileHints_Version5::kData97Name },

                    { V8CompileHints_Version5::kData970NameHash, V8CompileHints_Version5::kData970Name },

                    { V8CompileHints_Version5::kData971NameHash, V8CompileHints_Version5::kData971Name },

                    { V8CompileHints_Version5::kData972NameHash, V8CompileHints_Version5::kData972Name },

                    { V8CompileHints_Version5::kData973NameHash, V8CompileHints_Version5::kData973Name },

                    { V8CompileHints_Version5::kData974NameHash, V8CompileHints_Version5::kData974Name },

                    { V8CompileHints_Version5::kData975NameHash, V8CompileHints_Version5::kData975Name },

                    { V8CompileHints_Version5::kData976NameHash, V8CompileHints_Version5::kData976Name },

                    { V8CompileHints_Version5::kData977NameHash, V8CompileHints_Version5::kData977Name },

                    { V8CompileHints_Version5::kData978NameHash, V8CompileHints_Version5::kData978Name },

                    { V8CompileHints_Version5::kData979NameHash, V8CompileHints_Version5::kData979Name },

                    { V8CompileHints_Version5::kData98NameHash, V8CompileHints_Version5::kData98Name },

                    { V8CompileHints_Version5::kData980NameHash, V8CompileHints_Version5::kData980Name },

                    { V8CompileHints_Version5::kData981NameHash, V8CompileHints_Version5::kData981Name },

                    { V8CompileHints_Version5::kData982NameHash, V8CompileHints_Version5::kData982Name },

                    { V8CompileHints_Version5::kData983NameHash, V8CompileHints_Version5::kData983Name },

                    { V8CompileHints_Version5::kData984NameHash, V8CompileHints_Version5::kData984Name },

                    { V8CompileHints_Version5::kData985NameHash, V8CompileHints_Version5::kData985Name },

                    { V8CompileHints_Version5::kData986NameHash, V8CompileHints_Version5::kData986Name },

                    { V8CompileHints_Version5::kData987NameHash, V8CompileHints_Version5::kData987Name },

                    { V8CompileHints_Version5::kData988NameHash, V8CompileHints_Version5::kData988Name },

                    { V8CompileHints_Version5::kData989NameHash, V8CompileHints_Version5::kData989Name },

                    { V8CompileHints_Version5::kData99NameHash, V8CompileHints_Version5::kData99Name },

                    { V8CompileHints_Version5::kData990NameHash, V8CompileHints_Version5::kData990Name },

                    { V8CompileHints_Version5::kData991NameHash, V8CompileHints_Version5::kData991Name },

                    { V8CompileHints_Version5::kData992NameHash, V8CompileHints_Version5::kData992Name },

                    { V8CompileHints_Version5::kData993NameHash, V8CompileHints_Version5::kData993Name },

                    { V8CompileHints_Version5::kData994NameHash, V8CompileHints_Version5::kData994Name },

                    { V8CompileHints_Version5::kData995NameHash, V8CompileHints_Version5::kData995Name },

                    { V8CompileHints_Version5::kData996NameHash, V8CompileHints_Version5::kData996Name },

                    { V8CompileHints_Version5::kData997NameHash, V8CompileHints_Version5::kData997Name },

                    { V8CompileHints_Version5::kData998NameHash, V8CompileHints_Version5::kData998Name },

                    { V8CompileHints_Version5::kData999NameHash, V8CompileHints_Version5::kData999Name },

                } } },

        { UINT64_C(13751685094429308900),
            { VideoConferencingEvent::kEntryName,
                {

                    { VideoConferencingEvent::kCameraCaptureDurationNameHash, VideoConferencingEvent::kCameraCaptureDurationName },

                    { VideoConferencingEvent::kDidCaptureCameraNameHash, VideoConferencingEvent::kDidCaptureCameraName },

                    { VideoConferencingEvent::kDidCaptureMicrophoneNameHash, VideoConferencingEvent::kDidCaptureMicrophoneName },

                    { VideoConferencingEvent::kDidCaptureScreenNameHash, VideoConferencingEvent::kDidCaptureScreenName },

                    { VideoConferencingEvent::kMicrophoneCaptureDurationNameHash, VideoConferencingEvent::kMicrophoneCaptureDurationName },

                    { VideoConferencingEvent::kScreenCaptureDurationNameHash, VideoConferencingEvent::kScreenCaptureDurationName },

                    { VideoConferencingEvent::kTotalDurationNameHash, VideoConferencingEvent::kTotalDurationName },

                } } },

        { UINT64_C(3904325154478962694),
            { VirtualKeyboard_Open::kEntryName,
                {

                    { VirtualKeyboard_Open::kTextInputTypeNameHash, VirtualKeyboard_Open::kTextInputTypeName },

                } } },

        { UINT64_C(16867238133244431157),
            { Wallet_BoardingPassDetect::kEntryName,
                {

                    { Wallet_BoardingPassDetect::kDetectedNameHash, Wallet_BoardingPassDetect::kDetectedName },

                } } },

        { UINT64_C(12193435703081602033),
            { WebAPK_Install::kEntryName,
                {

                    { WebAPK_Install::kDisplayModeNameHash, WebAPK_Install::kDisplayModeName },

                    { WebAPK_Install::kDistributorNameHash, WebAPK_Install::kDistributorName },

                    { WebAPK_Install::kInstallNameHash, WebAPK_Install::kInstallName },

                    { WebAPK_Install::kInstallSourceNameHash, WebAPK_Install::kInstallSourceName },

                } } },

        { UINT64_C(304278077624055651),
            { WebAPK_SessionEnd::kEntryName,
                {

                    { WebAPK_SessionEnd::kAppVersionNameHash, WebAPK_SessionEnd::kAppVersionName },

                    { WebAPK_SessionEnd::kDistributorNameHash, WebAPK_SessionEnd::kDistributorName },

                    { WebAPK_SessionEnd::kSessionDurationNameHash, WebAPK_SessionEnd::kSessionDurationName },

                } } },

        { UINT64_C(15147671640732652143),
            { WebAPK_Uninstall::kEntryName,
                {

                    { WebAPK_Uninstall::kAppVersionNameHash, WebAPK_Uninstall::kAppVersionName },

                    { WebAPK_Uninstall::kDistributorNameHash, WebAPK_Uninstall::kDistributorName },

                    { WebAPK_Uninstall::kInstalledDurationNameHash, WebAPK_Uninstall::kInstalledDurationName },

                    { WebAPK_Uninstall::kLifetimeLaunchesNameHash, WebAPK_Uninstall::kLifetimeLaunchesName },

                    { WebAPK_Uninstall::kUninstallNameHash, WebAPK_Uninstall::kUninstallName },

                } } },

        { UINT64_C(7419239618516179300),
            { WebAPK_Visit::kEntryName,
                {

                    { WebAPK_Visit::kAppVersionNameHash, WebAPK_Visit::kAppVersionName },

                    { WebAPK_Visit::kDistributorNameHash, WebAPK_Visit::kDistributorName },

                    { WebAPK_Visit::kLaunchNameHash, WebAPK_Visit::kLaunchName },

                    { WebAPK_Visit::kLaunchSourceNameHash, WebAPK_Visit::kLaunchSourceName },

                } } },

        { UINT64_C(17489292060937518703),
            { Webapp_AddToHomeScreen::kEntryName,
                {

                    { Webapp_AddToHomeScreen::kDisplayModeNameHash, Webapp_AddToHomeScreen::kDisplayModeName },

                    { Webapp_AddToHomeScreen::kSameAsManifestStartUrlNameHash, Webapp_AddToHomeScreen::kSameAsManifestStartUrlName },

                    { Webapp_AddToHomeScreen::kShortcutReasonNameHash, Webapp_AddToHomeScreen::kShortcutReasonName },

                } } },

        { UINT64_C(10823086981545979708),
            { WebApp_DailyInteraction::kEntryName,
                {

                    { WebApp_DailyInteraction::kBackgroundDurationNameHash, WebApp_DailyInteraction::kBackgroundDurationName },

                    { WebApp_DailyInteraction::kCapturesLinksNameHash, WebApp_DailyInteraction::kCapturesLinksName },

                    { WebApp_DailyInteraction::kDisplayModeNameHash, WebApp_DailyInteraction::kDisplayModeName },

                    { WebApp_DailyInteraction::kForegroundDurationNameHash, WebApp_DailyInteraction::kForegroundDurationName },

                    { WebApp_DailyInteraction::kInstalledNameHash, WebApp_DailyInteraction::kInstalledName },

                    { WebApp_DailyInteraction::kInstallSourceNameHash, WebApp_DailyInteraction::kInstallSourceName },

                    { WebApp_DailyInteraction::kNumSessionsNameHash, WebApp_DailyInteraction::kNumSessionsName },

                    { WebApp_DailyInteraction::kPromotableNameHash, WebApp_DailyInteraction::kPromotableName },

                    { WebApp_DailyInteraction::kUsedNameHash, WebApp_DailyInteraction::kUsedName },

                } } },

        { UINT64_C(10568617214355697205),
            { WebAuthn_ConditionalUiGetCall::kEntryName,
                {

                    { WebAuthn_ConditionalUiGetCall::kTimeSinceDomContentLoadedNameHash, WebAuthn_ConditionalUiGetCall::kTimeSinceDomContentLoadedName },

                } } },

        { UINT64_C(13818196675028885634),
            { WebAuthn_RegisterCompletion::kEntryName,
                {

                    { WebAuthn_RegisterCompletion::kRegisterCompletionResultNameHash, WebAuthn_RegisterCompletion::kRegisterCompletionResultName },

                    { WebAuthn_RegisterCompletion::kRequestModeNameHash, WebAuthn_RegisterCompletion::kRequestModeName },

                } } },

        { UINT64_C(15241522087642277816),
            { WebAuthn_SignCompletion::kEntryName,
                {

                    { WebAuthn_SignCompletion::kRequestModeNameHash, WebAuthn_SignCompletion::kRequestModeName },

                    { WebAuthn_SignCompletion::kSignCompletionResultNameHash, WebAuthn_SignCompletion::kSignCompletionResultName },

                } } },

        { UINT64_C(17612510707700865831),
            { WebOTPImpact::kEntryName,
                {

                    { WebOTPImpact::kPhoneCollectionNameHash, WebOTPImpact::kPhoneCollectionName },

                } } },

        { UINT64_C(6759459948386423184),
            { WebRTC_AddressHarvesting::kEntryName,
                {

                    { WebRTC_AddressHarvesting::kUsagePatternNameHash, WebRTC_AddressHarvesting::kUsagePatternName },

                } } },

        { UINT64_C(7456919696038345904),
            { WebRTC_ComplexSdp::kEntryName,
                {

                    { WebRTC_ComplexSdp::kCategoryNameHash, WebRTC_ComplexSdp::kCategoryName },

                } } },

        { UINT64_C(7117761419315601762),
            { WindowProxyUsage::kEntryName,
                {

                    { WindowProxyUsage::kAccessTypeNameHash, WindowProxyUsage::kAccessTypeName },

                    { WindowProxyUsage::kIsSamePageNameHash, WindowProxyUsage::kIsSamePageName },

                    { WindowProxyUsage::kLocalFrameContextNameHash, WindowProxyUsage::kLocalFrameContextName },

                    { WindowProxyUsage::kLocalPageContextNameHash, WindowProxyUsage::kLocalPageContextName },

                    { WindowProxyUsage::kLocalUserActivationStateNameHash, WindowProxyUsage::kLocalUserActivationStateName },

                    { WindowProxyUsage::kRemoteFrameContextNameHash, WindowProxyUsage::kRemoteFrameContextName },

                    { WindowProxyUsage::kRemotePageContextNameHash, WindowProxyUsage::kRemotePageContextName },

                    { WindowProxyUsage::kRemoteUserActivationStateNameHash, WindowProxyUsage::kRemoteUserActivationStateName },

                    { WindowProxyUsage::kStorageKeyComparisonNameHash, WindowProxyUsage::kStorageKeyComparisonName },

                } } },

        { UINT64_C(11030368718596656137),
            { Worker_ClientAdded::kEntryName,
                {

                    { Worker_ClientAdded::kClientSourceIdNameHash, Worker_ClientAdded::kClientSourceIdName },

                    { Worker_ClientAdded::kWorkerTypeNameHash, Worker_ClientAdded::kWorkerTypeName },

                } } },

        { UINT64_C(2966287978545946180),
            { XR_WebXR::kEntryName,
                {

                    { XR_WebXR::kDidGetXRInputSourcesNameHash, XR_WebXR::kDidGetXRInputSourcesName },

                    { XR_WebXR::kDidRequestAvailableDevicesNameHash, XR_WebXR::kDidRequestAvailableDevicesName },

                    { XR_WebXR::kDidRequestPoseNameHash, XR_WebXR::kDidRequestPoseName },

                    { XR_WebXR::kDidRequestPresentationNameHash, XR_WebXR::kDidRequestPresentationName },

                    { XR_WebXR::kDidUseNavigatorXRNameHash, XR_WebXR::kDidUseNavigatorXRName },

                    { XR_WebXR::kReturnedDeviceNameHash, XR_WebXR::kReturnedDeviceName },

                    { XR_WebXR::kReturnedPresentationCapableDeviceNameHash, XR_WebXR::kReturnedPresentationCapableDeviceName },

                } } },

        { UINT64_C(4113953897099533496),
            { XR_WebXR_Session::kEntryName,
                {

                    { XR_WebXR_Session::kDurationNameHash, XR_WebXR_Session::kDurationName },

                    { XR_WebXR_Session::kFeatureRequest_BoundedFloorNameHash, XR_WebXR_Session::kFeatureRequest_BoundedFloorName },

                    { XR_WebXR_Session::kFeatureRequest_LocalNameHash, XR_WebXR_Session::kFeatureRequest_LocalName },

                    { XR_WebXR_Session::kFeatureRequest_LocalFloorNameHash, XR_WebXR_Session::kFeatureRequest_LocalFloorName },

                    { XR_WebXR_Session::kFeatureRequest_UnboundedNameHash, XR_WebXR_Session::kFeatureRequest_UnboundedName },

                    { XR_WebXR_Session::kFeatureRequest_ViewerNameHash, XR_WebXR_Session::kFeatureRequest_ViewerName },

                    { XR_WebXR_Session::kFeatureUse_BoundedFloorNameHash, XR_WebXR_Session::kFeatureUse_BoundedFloorName },

                    { XR_WebXR_Session::kFeatureUse_LocalNameHash, XR_WebXR_Session::kFeatureUse_LocalName },

                    { XR_WebXR_Session::kFeatureUse_LocalFloorNameHash, XR_WebXR_Session::kFeatureUse_LocalFloorName },

                    { XR_WebXR_Session::kFeatureUse_UnboundedNameHash, XR_WebXR_Session::kFeatureUse_UnboundedName },

                    { XR_WebXR_Session::kFeatureUse_ViewerNameHash, XR_WebXR_Session::kFeatureUse_ViewerName },

                    { XR_WebXR_Session::kModeNameHash, XR_WebXR_Session::kModeName },

                } } },

        { UINT64_C(15349576264204541813),
            { XR_WebXR_SessionRequest::kEntryName,
                {

                    { XR_WebXR_SessionRequest::kFeature_BoundedFloorNameHash, XR_WebXR_SessionRequest::kFeature_BoundedFloorName },

                    { XR_WebXR_SessionRequest::kFeature_LocalNameHash, XR_WebXR_SessionRequest::kFeature_LocalName },

                    { XR_WebXR_SessionRequest::kFeature_LocalFloorNameHash, XR_WebXR_SessionRequest::kFeature_LocalFloorName },

                    { XR_WebXR_SessionRequest::kFeature_UnboundedNameHash, XR_WebXR_SessionRequest::kFeature_UnboundedName },

                    { XR_WebXR_SessionRequest::kFeature_ViewerNameHash, XR_WebXR_SessionRequest::kFeature_ViewerName },

                    { XR_WebXR_SessionRequest::kModeNameHash, XR_WebXR_SessionRequest::kModeName },

                    { XR_WebXR_SessionRequest::kStatusNameHash, XR_WebXR_SessionRequest::kStatusName },

                } } },

    };
}

} // namespace builders
} // namespace ukm
