
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#ifndef SERVICES_METRICS_PUBLIC_CPP_UKM_BUILDERS_H
#define SERVICES_METRICS_PUBLIC_CPP_UKM_BUILDERS_H

#include <cstdint>

#include "services/metrics/public/cpp/ukm_entry_builder_base.h"

namespace ukm {
namespace builders {

class AbandonedSRPNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AbandonedSRPNavigation(ukm::SourceId source_id);
    explicit AbandonedSRPNavigation(ukm::SourceIdObj source_id);
    AbandonedSRPNavigation(AbandonedSRPNavigation&&);
    AbandonedSRPNavigation& operator=(AbandonedSRPNavigation&&);
    ~AbandonedSRPNavigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8701849857165570321);

    static const char kAbandonReasonName[];
    static constexpr uint64_t kAbandonReasonNameHash = UINT64_C(9220153800976320335);
    AbandonedSRPNavigation& SetAbandonReason(int64_t value);

    static const char kAbandonTimingFromLastMilestoneName[];
    static constexpr uint64_t kAbandonTimingFromLastMilestoneNameHash = UINT64_C(6375723186721527913);
    AbandonedSRPNavigation& SetAbandonTimingFromLastMilestone(int64_t value);

    static const char kAbandonTimingFromNavigationStartName[];
    static constexpr uint64_t kAbandonTimingFromNavigationStartNameHash = UINT64_C(3224877547677419773);
    AbandonedSRPNavigation& SetAbandonTimingFromNavigationStart(int64_t value);

    static const char kAFTEndTimeName[];
    static constexpr uint64_t kAFTEndTimeNameHash = UINT64_C(7398022789481527359);
    AbandonedSRPNavigation& SetAFTEndTime(int64_t value);

    static const char kAFTStartTimeName[];
    static constexpr uint64_t kAFTStartTimeNameHash = UINT64_C(4400427378727821028);
    AbandonedSRPNavigation& SetAFTStartTime(int64_t value);

    static const char kBodyChunkEndTimeName[];
    static constexpr uint64_t kBodyChunkEndTimeNameHash = UINT64_C(13850337811913152529);
    AbandonedSRPNavigation& SetBodyChunkEndTime(int64_t value);

    static const char kBodyChunkStartTimeName[];
    static constexpr uint64_t kBodyChunkStartTimeNameHash = UINT64_C(8284757693745651740);
    AbandonedSRPNavigation& SetBodyChunkStartTime(int64_t value);

    static const char kCommitReceivedTimeName[];
    static constexpr uint64_t kCommitReceivedTimeNameHash = UINT64_C(10091735938125740332);
    AbandonedSRPNavigation& SetCommitReceivedTime(int64_t value);

    static const char kCommitSentTimeName[];
    static constexpr uint64_t kCommitSentTimeNameHash = UINT64_C(11126417628787317284);
    AbandonedSRPNavigation& SetCommitSentTime(int64_t value);

    static const char kDidCommitTimeName[];
    static constexpr uint64_t kDidCommitTimeNameHash = UINT64_C(7446817284158648284);
    AbandonedSRPNavigation& SetDidCommitTime(int64_t value);

    static const char kDidRequestNonSRPName[];
    static constexpr uint64_t kDidRequestNonSRPNameHash = UINT64_C(7133003482382031552);
    AbandonedSRPNavigation& SetDidRequestNonSRP(int64_t value);

    static const char kDOMContentLoadedTimeName[];
    static constexpr uint64_t kDOMContentLoadedTimeNameHash = UINT64_C(8948119765481632524);
    AbandonedSRPNavigation& SetDOMContentLoadedTime(int64_t value);

    static const char kFirstContentfulPaintTimeName[];
    static constexpr uint64_t kFirstContentfulPaintTimeNameHash = UINT64_C(14468455761539569822);
    AbandonedSRPNavigation& SetFirstContentfulPaintTime(int64_t value);

    static const char kFirstRedirectedRequestStartTimeName[];
    static constexpr uint64_t kFirstRedirectedRequestStartTimeNameHash = UINT64_C(14120344171146723813);
    AbandonedSRPNavigation& SetFirstRedirectedRequestStartTime(int64_t value);

    static const char kFirstRedirectResponseReceivedName[];
    static constexpr uint64_t kFirstRedirectResponseReceivedNameHash = UINT64_C(10892104445278366937);
    AbandonedSRPNavigation& SetFirstRedirectResponseReceived(int64_t value);

    static const char kHeaderChunkEndTimeName[];
    static constexpr uint64_t kHeaderChunkEndTimeNameHash = UINT64_C(5335876774061609649);
    AbandonedSRPNavigation& SetHeaderChunkEndTime(int64_t value);

    static const char kHeaderChunkStartTimeName[];
    static constexpr uint64_t kHeaderChunkStartTimeNameHash = UINT64_C(8817035710336488678);
    AbandonedSRPNavigation& SetHeaderChunkStartTime(int64_t value);

    static const char kLargestContentfulPaintTimeName[];
    static constexpr uint64_t kLargestContentfulPaintTimeNameHash = UINT64_C(4234564031814655497);
    AbandonedSRPNavigation& SetLargestContentfulPaintTime(int64_t value);

    static const char kLastMilestoneBeforeAbandonName[];
    static constexpr uint64_t kLastMilestoneBeforeAbandonNameHash = UINT64_C(8446200822350403919);
    AbandonedSRPNavigation& SetLastMilestoneBeforeAbandon(int64_t value);

    static const char kLoaderStartTimeName[];
    static constexpr uint64_t kLoaderStartTimeNameHash = UINT64_C(16234182108747587459);
    AbandonedSRPNavigation& SetLoaderStartTime(int64_t value);

    static const char kLoadEventStartedTimeName[];
    static constexpr uint64_t kLoadEventStartedTimeNameHash = UINT64_C(12059652726595152637);
    AbandonedSRPNavigation& SetLoadEventStartedTime(int64_t value);

    static const char kNonRedirectedRequestStartTimeName[];
    static constexpr uint64_t kNonRedirectedRequestStartTimeNameHash = UINT64_C(17318652234451371373);
    AbandonedSRPNavigation& SetNonRedirectedRequestStartTime(int64_t value);

    static const char kNonRedirectResponseReceivedName[];
    static constexpr uint64_t kNonRedirectResponseReceivedNameHash = UINT64_C(6419751674832560689);
    AbandonedSRPNavigation& SetNonRedirectResponseReceived(int64_t value);

    static const char kParseStartTimeName[];
    static constexpr uint64_t kParseStartTimeNameHash = UINT64_C(10856944761640591267);
    AbandonedSRPNavigation& SetParseStartTime(int64_t value);

    static const char kPreviousBackgroundedTimeName[];
    static constexpr uint64_t kPreviousBackgroundedTimeNameHash = UINT64_C(17559234584987084816);
    AbandonedSRPNavigation& SetPreviousBackgroundedTime(int64_t value);

    static const char kPreviousHiddenTimeName[];
    static constexpr uint64_t kPreviousHiddenTimeNameHash = UINT64_C(12151804586931431244);
    AbandonedSRPNavigation& SetPreviousHiddenTime(int64_t value);

    static const char kRendererProcessInitTimeName[];
    static constexpr uint64_t kRendererProcessInitTimeNameHash = UINT64_C(5217106250572245309);
    AbandonedSRPNavigation& SetRendererProcessInitTime(int64_t value);

    static const char kRTTName[];
    static constexpr uint64_t kRTTNameHash = UINT64_C(17131669703269510613);
    AbandonedSRPNavigation& SetRTT(int64_t value);
};

class AboutThisSiteStatus final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AboutThisSiteStatus(ukm::SourceId source_id);
    explicit AboutThisSiteStatus(ukm::SourceIdObj source_id);
    AboutThisSiteStatus(AboutThisSiteStatus&&);
    AboutThisSiteStatus& operator=(AboutThisSiteStatus&&);
    ~AboutThisSiteStatus() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3328190265939661657);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    AboutThisSiteStatus& SetStatus(int64_t value);
};

class AbusiveExperienceHeuristic_JavaScriptDialog final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AbusiveExperienceHeuristic_JavaScriptDialog(ukm::SourceId source_id);
    explicit AbusiveExperienceHeuristic_JavaScriptDialog(ukm::SourceIdObj source_id);
    AbusiveExperienceHeuristic_JavaScriptDialog(AbusiveExperienceHeuristic_JavaScriptDialog&&);
    AbusiveExperienceHeuristic_JavaScriptDialog& operator=(AbusiveExperienceHeuristic_JavaScriptDialog&&);
    ~AbusiveExperienceHeuristic_JavaScriptDialog() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2140536877907621174);

    static const char kDismissalCauseName[];
    static constexpr uint64_t kDismissalCauseNameHash = UINT64_C(253402870863803684);
    AbusiveExperienceHeuristic_JavaScriptDialog& SetDismissalCause(int64_t value);
};

class AbusiveExperienceHeuristic_TabUnder final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AbusiveExperienceHeuristic_TabUnder(ukm::SourceId source_id);
    explicit AbusiveExperienceHeuristic_TabUnder(ukm::SourceIdObj source_id);
    AbusiveExperienceHeuristic_TabUnder(AbusiveExperienceHeuristic_TabUnder&&);
    AbusiveExperienceHeuristic_TabUnder& operator=(AbusiveExperienceHeuristic_TabUnder&&);
    ~AbusiveExperienceHeuristic_TabUnder() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14027824048938333848);

    static const char kDidTabUnderName[];
    static constexpr uint64_t kDidTabUnderNameHash = UINT64_C(1632877231929054164);
    AbusiveExperienceHeuristic_TabUnder& SetDidTabUnder(int64_t value);
};

class AbusiveExperienceHeuristic_WindowOpen final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AbusiveExperienceHeuristic_WindowOpen(ukm::SourceId source_id);
    explicit AbusiveExperienceHeuristic_WindowOpen(ukm::SourceIdObj source_id);
    AbusiveExperienceHeuristic_WindowOpen(AbusiveExperienceHeuristic_WindowOpen&&);
    AbusiveExperienceHeuristic_WindowOpen& operator=(AbusiveExperienceHeuristic_WindowOpen&&);
    ~AbusiveExperienceHeuristic_WindowOpen() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9914911288513336680);

    static const char kFromAdScriptName[];
    static constexpr uint64_t kFromAdScriptNameHash = UINT64_C(15256588101172132306);
    AbusiveExperienceHeuristic_WindowOpen& SetFromAdScript(int64_t value);

    static const char kFromAdSubframeName[];
    static constexpr uint64_t kFromAdSubframeNameHash = UINT64_C(11195998530139223421);
    AbusiveExperienceHeuristic_WindowOpen& SetFromAdSubframe(int64_t value);
};

class Accessibility_CanvasHasNonTrivialFallback final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_CanvasHasNonTrivialFallback(ukm::SourceId source_id);
    explicit Accessibility_CanvasHasNonTrivialFallback(ukm::SourceIdObj source_id);
    Accessibility_CanvasHasNonTrivialFallback(Accessibility_CanvasHasNonTrivialFallback&&);
    Accessibility_CanvasHasNonTrivialFallback& operator=(Accessibility_CanvasHasNonTrivialFallback&&);
    ~Accessibility_CanvasHasNonTrivialFallback() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14974513711212807879);

    static const char kSeenName[];
    static constexpr uint64_t kSeenNameHash = UINT64_C(13981160609965317407);
    Accessibility_CanvasHasNonTrivialFallback& SetSeen(int64_t value);
};

class Accessibility_ImageDescriptions final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_ImageDescriptions(ukm::SourceId source_id);
    explicit Accessibility_ImageDescriptions(ukm::SourceIdObj source_id);
    Accessibility_ImageDescriptions(Accessibility_ImageDescriptions&&);
    Accessibility_ImageDescriptions& operator=(Accessibility_ImageDescriptions&&);
    ~Accessibility_ImageDescriptions() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17643400000419784912);

    static const char kDescriptionName[];
    static constexpr uint64_t kDescriptionNameHash = UINT64_C(13089622011422296189);
    Accessibility_ImageDescriptions& SetDescription(int64_t value);

    static const char kImageAlreadyHasLabelName[];
    static constexpr uint64_t kImageAlreadyHasLabelNameHash = UINT64_C(17437196623992371779);
    Accessibility_ImageDescriptions& SetImageAlreadyHasLabel(int64_t value);

    static const char kOCRName[];
    static constexpr uint64_t kOCRNameHash = UINT64_C(17665867749841834535);
    Accessibility_ImageDescriptions& SetOCR(int64_t value);
};

class Accessibility_InaccessiblePDFs final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_InaccessiblePDFs(ukm::SourceId source_id);
    explicit Accessibility_InaccessiblePDFs(ukm::SourceIdObj source_id);
    Accessibility_InaccessiblePDFs(Accessibility_InaccessiblePDFs&&);
    Accessibility_InaccessiblePDFs& operator=(Accessibility_InaccessiblePDFs&&);
    ~Accessibility_InaccessiblePDFs() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3697069546265840852);

    static const char kSeenName[];
    static constexpr uint64_t kSeenNameHash = UINT64_C(13981160609965317407);
    Accessibility_InaccessiblePDFs& SetSeen(int64_t value);
};

class Accessibility_PageZoom final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_PageZoom(ukm::SourceId source_id);
    explicit Accessibility_PageZoom(ukm::SourceIdObj source_id);
    Accessibility_PageZoom(Accessibility_PageZoom&&);
    Accessibility_PageZoom& operator=(Accessibility_PageZoom&&);
    ~Accessibility_PageZoom() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7604161593172992016);

    static const char kSliderZoomValueName[];
    static constexpr uint64_t kSliderZoomValueNameHash = UINT64_C(10860240670662679606);
    Accessibility_PageZoom& SetSliderZoomValue(int64_t value);
};

class Accessibility_ReadAnything final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_ReadAnything(ukm::SourceId source_id);
    explicit Accessibility_ReadAnything(ukm::SourceIdObj source_id);
    Accessibility_ReadAnything(Accessibility_ReadAnything&&);
    Accessibility_ReadAnything& operator=(Accessibility_ReadAnything&&);
    ~Accessibility_ReadAnything() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1220117982628781122);

    static const char kMergedDistillationTime_FailureName[];
    static constexpr uint64_t kMergedDistillationTime_FailureNameHash = UINT64_C(2902107839752686337);
    Accessibility_ReadAnything& SetMergedDistillationTime_Failure(int64_t value);

    static const char kMergedDistillationTime_SuccessName[];
    static constexpr uint64_t kMergedDistillationTime_SuccessNameHash = UINT64_C(8935101722465252111);
    Accessibility_ReadAnything& SetMergedDistillationTime_Success(int64_t value);

    static const char kRulesDistillationTime_FailureName[];
    static constexpr uint64_t kRulesDistillationTime_FailureNameHash = UINT64_C(16801695228372896054);
    Accessibility_ReadAnything& SetRulesDistillationTime_Failure(int64_t value);

    static const char kRulesDistillationTime_SuccessName[];
    static constexpr uint64_t kRulesDistillationTime_SuccessNameHash = UINT64_C(14517845133733634886);
    Accessibility_ReadAnything& SetRulesDistillationTime_Success(int64_t value);
};

class Accessibility_ReadAnything_EmptyState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_ReadAnything_EmptyState(ukm::SourceId source_id);
    explicit Accessibility_ReadAnything_EmptyState(ukm::SourceIdObj source_id);
    Accessibility_ReadAnything_EmptyState(Accessibility_ReadAnything_EmptyState&&);
    Accessibility_ReadAnything_EmptyState& operator=(Accessibility_ReadAnything_EmptyState&&);
    ~Accessibility_ReadAnything_EmptyState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9340032261281702170);

    static const char kTotalNumSelectionsName[];
    static constexpr uint64_t kTotalNumSelectionsNameHash = UINT64_C(16951374961519602188);
    Accessibility_ReadAnything_EmptyState& SetTotalNumSelections(int64_t value);
};

class Accessibility_Renderer final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_Renderer(ukm::SourceId source_id);
    explicit Accessibility_Renderer(ukm::SourceIdObj source_id);
    Accessibility_Renderer(Accessibility_Renderer&&);
    Accessibility_Renderer& operator=(Accessibility_Renderer&&);
    ~Accessibility_Renderer() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11928696798041860883);

    static const char kCpuTime_SendPendingAccessibilityEventsName[];
    static constexpr uint64_t kCpuTime_SendPendingAccessibilityEventsNameHash = UINT64_C(10923305255192224661);
    Accessibility_Renderer& SetCpuTime_SendPendingAccessibilityEvents(int64_t value);
};

class Accessibility_ScreenAI final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Accessibility_ScreenAI(ukm::SourceId source_id);
    explicit Accessibility_ScreenAI(ukm::SourceIdObj source_id);
    Accessibility_ScreenAI(Accessibility_ScreenAI&&);
    Accessibility_ScreenAI& operator=(Accessibility_ScreenAI&&);
    ~Accessibility_ScreenAI() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17956348020429077585);

    static const char kScreen2xDistillationTime_FailureName[];
    static constexpr uint64_t kScreen2xDistillationTime_FailureNameHash = UINT64_C(9935941100412693500);
    Accessibility_ScreenAI& SetScreen2xDistillationTime_Failure(int64_t value);

    static const char kScreen2xDistillationTime_SuccessName[];
    static constexpr uint64_t kScreen2xDistillationTime_SuccessNameHash = UINT64_C(14180733479475049579);
    Accessibility_ScreenAI& SetScreen2xDistillationTime_Success(int64_t value);
};

class AdFrameLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AdFrameLoad(ukm::SourceId source_id);
    explicit AdFrameLoad(ukm::SourceIdObj source_id);
    AdFrameLoad(AdFrameLoad&&);
    AdFrameLoad& operator=(AdFrameLoad&&);
    ~AdFrameLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9171478480016060997);

    static const char kCpuTime_PeakWindowedPercentName[];
    static constexpr uint64_t kCpuTime_PeakWindowedPercentNameHash = UINT64_C(10694907416106821570);
    AdFrameLoad& SetCpuTime_PeakWindowedPercent(int64_t value);

    static const char kCpuTime_PreActivationName[];
    static constexpr uint64_t kCpuTime_PreActivationNameHash = UINT64_C(5794315328615334038);
    AdFrameLoad& SetCpuTime_PreActivation(int64_t value);

    static const char kCpuTime_TotalName[];
    static constexpr uint64_t kCpuTime_TotalNameHash = UINT64_C(15350101520340136860);
    AdFrameLoad& SetCpuTime_Total(int64_t value);

    static const char kFrameDepthName[];
    static constexpr uint64_t kFrameDepthNameHash = UINT64_C(5259598389912370111);
    AdFrameLoad& SetFrameDepth(int64_t value);

    static const char kLoading_CacheBytes2Name[];
    static constexpr uint64_t kLoading_CacheBytes2NameHash = UINT64_C(2812659824544278329);
    AdFrameLoad& SetLoading_CacheBytes2(int64_t value);

    static const char kLoading_ImageBytesName[];
    static constexpr uint64_t kLoading_ImageBytesNameHash = UINT64_C(4267019114733925172);
    AdFrameLoad& SetLoading_ImageBytes(int64_t value);

    static const char kLoading_JavascriptBytesName[];
    static constexpr uint64_t kLoading_JavascriptBytesNameHash = UINT64_C(9762950567105973962);
    AdFrameLoad& SetLoading_JavascriptBytes(int64_t value);

    static const char kLoading_NetworkBytesName[];
    static constexpr uint64_t kLoading_NetworkBytesNameHash = UINT64_C(2909577699402783051);
    AdFrameLoad& SetLoading_NetworkBytes(int64_t value);

    static const char kLoading_NumResourcesName[];
    static constexpr uint64_t kLoading_NumResourcesNameHash = UINT64_C(13450060208467074309);
    AdFrameLoad& SetLoading_NumResources(int64_t value);

    static const char kLoading_VideoBytesName[];
    static constexpr uint64_t kLoading_VideoBytesNameHash = UINT64_C(15011407665794377843);
    AdFrameLoad& SetLoading_VideoBytes(int64_t value);

    static const char kStatus_CrossOriginName[];
    static constexpr uint64_t kStatus_CrossOriginNameHash = UINT64_C(4568069380683941241);
    AdFrameLoad& SetStatus_CrossOrigin(int64_t value);

    static const char kStatus_MediaName[];
    static constexpr uint64_t kStatus_MediaNameHash = UINT64_C(4546060596826334451);
    AdFrameLoad& SetStatus_Media(int64_t value);

    static const char kStatus_UserActivationName[];
    static constexpr uint64_t kStatus_UserActivationNameHash = UINT64_C(5097180316580530092);
    AdFrameLoad& SetStatus_UserActivation(int64_t value);

    static const char kTiming_FirstContentfulPaintName[];
    static constexpr uint64_t kTiming_FirstContentfulPaintNameHash = UINT64_C(17943578481506543757);
    AdFrameLoad& SetTiming_FirstContentfulPaint(int64_t value);

    static const char kTiming_InteractiveName[];
    static constexpr uint64_t kTiming_InteractiveNameHash = UINT64_C(15125362531657075325);
    AdFrameLoad& SetTiming_Interactive(int64_t value);

    static const char kVisibility_FrameHeightName[];
    static constexpr uint64_t kVisibility_FrameHeightNameHash = UINT64_C(7279397677831738677);
    AdFrameLoad& SetVisibility_FrameHeight(int64_t value);

    static const char kVisibility_FrameWidthName[];
    static constexpr uint64_t kVisibility_FrameWidthNameHash = UINT64_C(3041121436852256629);
    AdFrameLoad& SetVisibility_FrameWidth(int64_t value);

    static const char kVisibility_HiddenName[];
    static constexpr uint64_t kVisibility_HiddenNameHash = UINT64_C(10742343504399641560);
    AdFrameLoad& SetVisibility_Hidden(int64_t value);
};

class AdPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AdPageLoad(ukm::SourceId source_id);
    explicit AdPageLoad(ukm::SourceIdObj source_id);
    AdPageLoad(AdPageLoad&&);
    AdPageLoad& operator=(AdPageLoad&&);
    ~AdPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(897698866892786861);

    static const char kAdBytesName[];
    static constexpr uint64_t kAdBytesNameHash = UINT64_C(6659033870686188869);
    AdPageLoad& SetAdBytes(int64_t value);

    static const char kAdCpuTimeName[];
    static constexpr uint64_t kAdCpuTimeNameHash = UINT64_C(4851683766975122096);
    AdPageLoad& SetAdCpuTime(int64_t value);

    static const char kAdJavascriptBytesName[];
    static constexpr uint64_t kAdJavascriptBytesNameHash = UINT64_C(13996584362851862436);
    AdPageLoad& SetAdJavascriptBytes(int64_t value);

    static const char kAdVideoBytesName[];
    static constexpr uint64_t kAdVideoBytesNameHash = UINT64_C(4207294672781050458);
    AdPageLoad& SetAdVideoBytes(int64_t value);

    static const char kMainframeAdBytesName[];
    static constexpr uint64_t kMainframeAdBytesNameHash = UINT64_C(10142968506033351129);
    AdPageLoad& SetMainframeAdBytes(int64_t value);

    static const char kMaxAdDensityByAreaName[];
    static constexpr uint64_t kMaxAdDensityByAreaNameHash = UINT64_C(7067391914447638302);
    AdPageLoad& SetMaxAdDensityByArea(int64_t value);

    static const char kMaxAdDensityByHeightName[];
    static constexpr uint64_t kMaxAdDensityByHeightNameHash = UINT64_C(11115055418774615844);
    AdPageLoad& SetMaxAdDensityByHeight(int64_t value);

    static const char kTotalBytesName[];
    static constexpr uint64_t kTotalBytesNameHash = UINT64_C(8087173487984213000);
    AdPageLoad& SetTotalBytes(int64_t value);
};

class AdPageLoadCustomSampling3 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AdPageLoadCustomSampling3(ukm::SourceId source_id);
    explicit AdPageLoadCustomSampling3(ukm::SourceIdObj source_id);
    AdPageLoadCustomSampling3(AdPageLoadCustomSampling3&&);
    AdPageLoadCustomSampling3& operator=(AdPageLoadCustomSampling3&&);
    ~AdPageLoadCustomSampling3() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8301571822483019451);

    static const char kAverageViewportAdDensityName[];
    static constexpr uint64_t kAverageViewportAdDensityNameHash = UINT64_C(101279546885733359);
    AdPageLoadCustomSampling3& SetAverageViewportAdDensity(int64_t value);

    static const char kKurtosisViewportAdDensityName[];
    static constexpr uint64_t kKurtosisViewportAdDensityNameHash = UINT64_C(5705913436163967023);
    AdPageLoadCustomSampling3& SetKurtosisViewportAdDensity(int64_t value);

    static const char kSkewnessViewportAdDensityName[];
    static constexpr uint64_t kSkewnessViewportAdDensityNameHash = UINT64_C(14047362495201803913);
    AdPageLoadCustomSampling3& SetSkewnessViewportAdDensity(int64_t value);

    static const char kVarianceViewportAdDensityName[];
    static constexpr uint64_t kVarianceViewportAdDensityNameHash = UINT64_C(8474488626695605641);
    AdPageLoadCustomSampling3& SetVarianceViewportAdDensity(int64_t value);
};

class AdsInterestGroup_AuctionLatency_V2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AdsInterestGroup_AuctionLatency_V2(ukm::SourceId source_id);
    explicit AdsInterestGroup_AuctionLatency_V2(ukm::SourceIdObj source_id);
    AdsInterestGroup_AuctionLatency_V2(AdsInterestGroup_AuctionLatency_V2&&);
    AdsInterestGroup_AuctionLatency_V2& operator=(AdsInterestGroup_AuctionLatency_V2&&);
    ~AdsInterestGroup_AuctionLatency_V2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4791458487205780047);

    static const char kBidGenerationPhaseEndTimeInMillisName[];
    static constexpr uint64_t kBidGenerationPhaseEndTimeInMillisNameHash = UINT64_C(6437462784594263570);
    AdsInterestGroup_AuctionLatency_V2& SetBidGenerationPhaseEndTimeInMillis(int64_t value);

    static const char kBidGenerationPhaseStartTimeInMillisName[];
    static constexpr uint64_t kBidGenerationPhaseStartTimeInMillisNameHash = UINT64_C(1118884574410262193);
    AdsInterestGroup_AuctionLatency_V2& SetBidGenerationPhaseStartTimeInMillis(int64_t value);

    static const char kBidSignalsFetchPhaseEndTimeInMillisName[];
    static constexpr uint64_t kBidSignalsFetchPhaseEndTimeInMillisNameHash = UINT64_C(16914559545477999076);
    AdsInterestGroup_AuctionLatency_V2& SetBidSignalsFetchPhaseEndTimeInMillis(int64_t value);

    static const char kBidSignalsFetchPhaseStartTimeInMillisName[];
    static constexpr uint64_t kBidSignalsFetchPhaseStartTimeInMillisNameHash = UINT64_C(10522786896799752754);
    AdsInterestGroup_AuctionLatency_V2& SetBidSignalsFetchPhaseStartTimeInMillis(int64_t value);

    static const char kEndToEndLatencyInMillisName[];
    static constexpr uint64_t kEndToEndLatencyInMillisNameHash = UINT64_C(6679428760865223099);
    AdsInterestGroup_AuctionLatency_V2& SetEndToEndLatencyInMillis(int64_t value);

    static const char kKAnonymityBidModeName[];
    static constexpr uint64_t kKAnonymityBidModeNameHash = UINT64_C(18357576992859719152);
    AdsInterestGroup_AuctionLatency_V2& SetKAnonymityBidMode(int64_t value);

    static const char kLoadInterestGroupPhaseEndTimeInMillisName[];
    static constexpr uint64_t kLoadInterestGroupPhaseEndTimeInMillisNameHash = UINT64_C(6519989537462309233);
    AdsInterestGroup_AuctionLatency_V2& SetLoadInterestGroupPhaseEndTimeInMillis(int64_t value);

    static const char kLoadInterestGroupPhaseLatencyInMillisName[];
    static constexpr uint64_t kLoadInterestGroupPhaseLatencyInMillisNameHash = UINT64_C(16310764380536414472);
    AdsInterestGroup_AuctionLatency_V2& SetLoadInterestGroupPhaseLatencyInMillis(int64_t value);

    static const char kMaxAdditionalBidDecodeLatencyInMillisName[];
    static constexpr uint64_t kMaxAdditionalBidDecodeLatencyInMillisNameHash = UINT64_C(7829694414471854301);
    AdsInterestGroup_AuctionLatency_V2& SetMaxAdditionalBidDecodeLatencyInMillis(int64_t value);

    static const char kMaxBidForOneInterestGroupLatencyInMillisName[];
    static constexpr uint64_t kMaxBidForOneInterestGroupLatencyInMillisNameHash = UINT64_C(18054414652807126083);
    AdsInterestGroup_AuctionLatency_V2& SetMaxBidForOneInterestGroupLatencyInMillis(int64_t value);

    static const char kMaxComponentAuctionLatencyInMillisName[];
    static constexpr uint64_t kMaxComponentAuctionLatencyInMillisNameHash = UINT64_C(4644322349357249496);
    AdsInterestGroup_AuctionLatency_V2& SetMaxComponentAuctionLatencyInMillis(int64_t value);

    static const char kMaxConfigPromisesResolvedCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMaxConfigPromisesResolvedCriticalPathLatencyInMillisNameHash = UINT64_C(13485229370252619718);
    AdsInterestGroup_AuctionLatency_V2& SetMaxConfigPromisesResolvedCriticalPathLatencyInMillis(int64_t value);

    static const char kMaxConfigPromisesResolvedLatencyInMillisName[];
    static constexpr uint64_t kMaxConfigPromisesResolvedLatencyInMillisNameHash = UINT64_C(16955422112063150391);
    AdsInterestGroup_AuctionLatency_V2& SetMaxConfigPromisesResolvedLatencyInMillis(int64_t value);

    static const char kMaxGenerateBidCodeReadyLatencyInMillisName[];
    static constexpr uint64_t kMaxGenerateBidCodeReadyLatencyInMillisNameHash = UINT64_C(14500581822229208940);
    AdsInterestGroup_AuctionLatency_V2& SetMaxGenerateBidCodeReadyLatencyInMillis(int64_t value);

    static const char kMaxGenerateBidConfigPromisesLatencyInMillisName[];
    static constexpr uint64_t kMaxGenerateBidConfigPromisesLatencyInMillisNameHash = UINT64_C(889063202136138528);
    AdsInterestGroup_AuctionLatency_V2& SetMaxGenerateBidConfigPromisesLatencyInMillis(int64_t value);

    static const char kMaxGenerateBidDirectFromSellerSignalsLatencyInMillisName[];
    static constexpr uint64_t kMaxGenerateBidDirectFromSellerSignalsLatencyInMillisNameHash = UINT64_C(7976569522581871188);
    AdsInterestGroup_AuctionLatency_V2& SetMaxGenerateBidDirectFromSellerSignalsLatencyInMillis(int64_t value);

    static const char kMaxGenerateBidTrustedBiddingSignalsLatencyInMillisName[];
    static constexpr uint64_t kMaxGenerateBidTrustedBiddingSignalsLatencyInMillisNameHash = UINT64_C(5693489122356762330);
    AdsInterestGroup_AuctionLatency_V2& SetMaxGenerateBidTrustedBiddingSignalsLatencyInMillis(int64_t value);

    static const char kMaxGenerateSingleBidLatencyInMillisName[];
    static constexpr uint64_t kMaxGenerateSingleBidLatencyInMillisNameHash = UINT64_C(355578983895344079);
    AdsInterestGroup_AuctionLatency_V2& SetMaxGenerateSingleBidLatencyInMillis(int64_t value);

    static const char kMaxScoreAdCodeReadyLatencyInMillisName[];
    static constexpr uint64_t kMaxScoreAdCodeReadyLatencyInMillisNameHash = UINT64_C(14613463483475783540);
    AdsInterestGroup_AuctionLatency_V2& SetMaxScoreAdCodeReadyLatencyInMillis(int64_t value);

    static const char kMaxScoreAdDirectFromSellerSignalsLatencyInMillisName[];
    static constexpr uint64_t kMaxScoreAdDirectFromSellerSignalsLatencyInMillisNameHash = UINT64_C(16159880886419366832);
    AdsInterestGroup_AuctionLatency_V2& SetMaxScoreAdDirectFromSellerSignalsLatencyInMillis(int64_t value);

    static const char kMaxScoreAdFlowLatencyInMillisName[];
    static constexpr uint64_t kMaxScoreAdFlowLatencyInMillisNameHash = UINT64_C(463506451696925211);
    AdsInterestGroup_AuctionLatency_V2& SetMaxScoreAdFlowLatencyInMillis(int64_t value);

    static const char kMaxScoreAdLatencyInMillisName[];
    static constexpr uint64_t kMaxScoreAdLatencyInMillisNameHash = UINT64_C(9026437348163894086);
    AdsInterestGroup_AuctionLatency_V2& SetMaxScoreAdLatencyInMillis(int64_t value);

    static const char kMaxScoreAdTrustedScoringSignalsLatencyInMillisName[];
    static constexpr uint64_t kMaxScoreAdTrustedScoringSignalsLatencyInMillisNameHash = UINT64_C(12946639724212918144);
    AdsInterestGroup_AuctionLatency_V2& SetMaxScoreAdTrustedScoringSignalsLatencyInMillis(int64_t value);

    static const char kMeanAdditionalBidDecodeLatencyInMillisName[];
    static constexpr uint64_t kMeanAdditionalBidDecodeLatencyInMillisNameHash = UINT64_C(4588215489204300532);
    AdsInterestGroup_AuctionLatency_V2& SetMeanAdditionalBidDecodeLatencyInMillis(int64_t value);

    static const char kMeanBidForOneInterestGroupLatencyInMillisName[];
    static constexpr uint64_t kMeanBidForOneInterestGroupLatencyInMillisNameHash = UINT64_C(17164734754323952352);
    AdsInterestGroup_AuctionLatency_V2& SetMeanBidForOneInterestGroupLatencyInMillis(int64_t value);

    static const char kMeanComponentAuctionLatencyInMillisName[];
    static constexpr uint64_t kMeanComponentAuctionLatencyInMillisNameHash = UINT64_C(1804242656888931003);
    AdsInterestGroup_AuctionLatency_V2& SetMeanComponentAuctionLatencyInMillis(int64_t value);

    static const char kMeanConfigPromisesResolvedCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanConfigPromisesResolvedCriticalPathLatencyInMillisNameHash = UINT64_C(4036660442576503708);
    AdsInterestGroup_AuctionLatency_V2& SetMeanConfigPromisesResolvedCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanConfigPromisesResolvedLatencyInMillisName[];
    static constexpr uint64_t kMeanConfigPromisesResolvedLatencyInMillisNameHash = UINT64_C(8345475484244353806);
    AdsInterestGroup_AuctionLatency_V2& SetMeanConfigPromisesResolvedLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidCodeReadyCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidCodeReadyCriticalPathLatencyInMillisNameHash = UINT64_C(12043165287237382169);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidCodeReadyCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidCodeReadyLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidCodeReadyLatencyInMillisNameHash = UINT64_C(15557004502068980114);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidCodeReadyLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidConfigPromisesCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidConfigPromisesCriticalPathLatencyInMillisNameHash = UINT64_C(244283023166785313);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidConfigPromisesCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidConfigPromisesLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidConfigPromisesLatencyInMillisNameHash = UINT64_C(202571096345075156);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidConfigPromisesLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidDirectFromSellerSignalsCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidDirectFromSellerSignalsCriticalPathLatencyInMillisNameHash = UINT64_C(18206182476096231881);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidDirectFromSellerSignalsCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidDirectFromSellerSignalsLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidDirectFromSellerSignalsLatencyInMillisNameHash = UINT64_C(9086221120492865667);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidDirectFromSellerSignalsLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidTrustedBiddingSignalsCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidTrustedBiddingSignalsCriticalPathLatencyInMillisNameHash = UINT64_C(18071695899529069470);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidTrustedBiddingSignalsCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanGenerateBidTrustedBiddingSignalsLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateBidTrustedBiddingSignalsLatencyInMillisNameHash = UINT64_C(1377890649618841482);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateBidTrustedBiddingSignalsLatencyInMillis(int64_t value);

    static const char kMeanGenerateSingleBidLatencyInMillisName[];
    static constexpr uint64_t kMeanGenerateSingleBidLatencyInMillisNameHash = UINT64_C(10499960894736474548);
    AdsInterestGroup_AuctionLatency_V2& SetMeanGenerateSingleBidLatencyInMillis(int64_t value);

    static const char kMeanScoreAdCodeReadyCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdCodeReadyCriticalPathLatencyInMillisNameHash = UINT64_C(16872227949451407538);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdCodeReadyCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanScoreAdCodeReadyLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdCodeReadyLatencyInMillisNameHash = UINT64_C(10652409612637499656);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdCodeReadyLatencyInMillis(int64_t value);

    static const char kMeanScoreAdDirectFromSellerSignalsCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdDirectFromSellerSignalsCriticalPathLatencyInMillisNameHash = UINT64_C(6069687727565581866);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdDirectFromSellerSignalsCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanScoreAdDirectFromSellerSignalsLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdDirectFromSellerSignalsLatencyInMillisNameHash = UINT64_C(14486153870081195336);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdDirectFromSellerSignalsLatencyInMillis(int64_t value);

    static const char kMeanScoreAdFlowLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdFlowLatencyInMillisNameHash = UINT64_C(9445510538977570759);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdFlowLatencyInMillis(int64_t value);

    static const char kMeanScoreAdLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdLatencyInMillisNameHash = UINT64_C(13100145823684254240);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdLatencyInMillis(int64_t value);

    static const char kMeanScoreAdTrustedScoringSignalsCriticalPathLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdTrustedScoringSignalsCriticalPathLatencyInMillisNameHash = UINT64_C(5700480063958078277);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdTrustedScoringSignalsCriticalPathLatencyInMillis(int64_t value);

    static const char kMeanScoreAdTrustedScoringSignalsLatencyInMillisName[];
    static constexpr uint64_t kMeanScoreAdTrustedScoringSignalsLatencyInMillisNameHash = UINT64_C(13640484841068951235);
    AdsInterestGroup_AuctionLatency_V2& SetMeanScoreAdTrustedScoringSignalsLatencyInMillis(int64_t value);

    static const char kMeanTimeBidsQueuedWaitingForConfigPromisesInMillisName[];
    static constexpr uint64_t kMeanTimeBidsQueuedWaitingForConfigPromisesInMillisNameHash = UINT64_C(13895847700498572669);
    AdsInterestGroup_AuctionLatency_V2& SetMeanTimeBidsQueuedWaitingForConfigPromisesInMillis(int64_t value);

    static const char kMeanTimeBidsQueuedWaitingForSellerWorkletInMillisName[];
    static constexpr uint64_t kMeanTimeBidsQueuedWaitingForSellerWorkletInMillisNameHash = UINT64_C(3797385740168909517);
    AdsInterestGroup_AuctionLatency_V2& SetMeanTimeBidsQueuedWaitingForSellerWorkletInMillis(int64_t value);

    static const char kMeanTimeTopLevelBidsQueuedWaitingForConfigPromisesInMillisName[];
    static constexpr uint64_t kMeanTimeTopLevelBidsQueuedWaitingForConfigPromisesInMillisNameHash = UINT64_C(15205183214709970707);
    AdsInterestGroup_AuctionLatency_V2& SetMeanTimeTopLevelBidsQueuedWaitingForConfigPromisesInMillis(int64_t value);

    static const char kMeanTimeTopLevelBidsQueuedWaitingForSellerWorkletInMillisName[];
    static constexpr uint64_t kMeanTimeTopLevelBidsQueuedWaitingForSellerWorkletInMillisNameHash = UINT64_C(1516506709992055162);
    AdsInterestGroup_AuctionLatency_V2& SetMeanTimeTopLevelBidsQueuedWaitingForSellerWorkletInMillis(int64_t value);

    static const char kNumAdditionalBidsNegativeTargetedName[];
    static constexpr uint64_t kNumAdditionalBidsNegativeTargetedNameHash = UINT64_C(9162155251528926063);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsNegativeTargeted(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToBuyerNotAllowedName[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToBuyerNotAllowedNameHash = UINT64_C(640757380820919053);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToBuyerNotAllowed(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToCurrencyMismatchName[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToCurrencyMismatchNameHash = UINT64_C(8661495814283069928);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToCurrencyMismatch(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToDecodeErrorName[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToDecodeErrorNameHash = UINT64_C(13718415836108177823);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToDecodeError(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToInvalidBase64Name[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToInvalidBase64NameHash = UINT64_C(4311479814850552036);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToInvalidBase64(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToJsonParseErrorName[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToJsonParseErrorNameHash = UINT64_C(15179798342096802676);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToJsonParseError(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToSignedBidDecodeErrorName[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToSignedBidDecodeErrorNameHash = UINT64_C(16465627994537635906);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToSignedBidDecodeError(int64_t value);

    static const char kNumAdditionalBidsRejectedDueToSignedBidJsonParseErrorName[];
    static constexpr uint64_t kNumAdditionalBidsRejectedDueToSignedBidJsonParseErrorNameHash = UINT64_C(6212091142362302211);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsRejectedDueToSignedBidJsonParseError(int64_t value);

    static const char kNumAdditionalBidsSentForScoringName[];
    static constexpr uint64_t kNumAdditionalBidsSentForScoringNameHash = UINT64_C(13543613007024271425);
    AdsInterestGroup_AuctionLatency_V2& SetNumAdditionalBidsSentForScoring(int64_t value);

    static const char kNumAuctionsWithConfigPromisesName[];
    static constexpr uint64_t kNumAuctionsWithConfigPromisesNameHash = UINT64_C(16147711769359182859);
    AdsInterestGroup_AuctionLatency_V2& SetNumAuctionsWithConfigPromises(int64_t value);

    static const char kNumBidderWorkletsName[];
    static constexpr uint64_t kNumBidderWorkletsNameHash = UINT64_C(17795063688260201748);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidderWorklets(int64_t value);

    static const char kNumBidsAbortedByBidderWorkletFatalErrorName[];
    static constexpr uint64_t kNumBidsAbortedByBidderWorkletFatalErrorNameHash = UINT64_C(7262166595989697129);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsAbortedByBidderWorkletFatalError(int64_t value);

    static const char kNumBidsAbortedByBuyerCumulativeTimeoutName[];
    static constexpr uint64_t kNumBidsAbortedByBuyerCumulativeTimeoutNameHash = UINT64_C(18108584456216928693);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsAbortedByBuyerCumulativeTimeout(int64_t value);

    static const char kNumBidsFilteredByPerBuyerLimitsName[];
    static constexpr uint64_t kNumBidsFilteredByPerBuyerLimitsNameHash = UINT64_C(1040760384080533635);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsFilteredByPerBuyerLimits(int64_t value);

    static const char kNumBidsFilteredDuringInterestGroupLoadName[];
    static constexpr uint64_t kNumBidsFilteredDuringInterestGroupLoadNameHash = UINT64_C(9991286530624350048);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsFilteredDuringInterestGroupLoad(int64_t value);

    static const char kNumBidsFilteredDuringReprioritizationName[];
    static constexpr uint64_t kNumBidsFilteredDuringReprioritizationNameHash = UINT64_C(4235295379639887651);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsFilteredDuringReprioritization(int64_t value);

    static const char kNumBidsQueuedWaitingForConfigPromisesName[];
    static constexpr uint64_t kNumBidsQueuedWaitingForConfigPromisesNameHash = UINT64_C(13796887774409065014);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsQueuedWaitingForConfigPromises(int64_t value);

    static const char kNumBidsQueuedWaitingForSellerWorkletName[];
    static constexpr uint64_t kNumBidsQueuedWaitingForSellerWorkletNameHash = UINT64_C(7815964478351652745);
    AdsInterestGroup_AuctionLatency_V2& SetNumBidsQueuedWaitingForSellerWorklet(int64_t value);

    static const char kNumConfigPromisesName[];
    static constexpr uint64_t kNumConfigPromisesNameHash = UINT64_C(6854364606563521685);
    AdsInterestGroup_AuctionLatency_V2& SetNumConfigPromises(int64_t value);

    static const char kNumDistinctOwnersWithInterestGroupsName[];
    static constexpr uint64_t kNumDistinctOwnersWithInterestGroupsNameHash = UINT64_C(13094502933264366447);
    AdsInterestGroup_AuctionLatency_V2& SetNumDistinctOwnersWithInterestGroups(int64_t value);

    static const char kNumGenerateBidCodeReadyOnCriticalPathName[];
    static constexpr uint64_t kNumGenerateBidCodeReadyOnCriticalPathNameHash = UINT64_C(3927625515721674397);
    AdsInterestGroup_AuctionLatency_V2& SetNumGenerateBidCodeReadyOnCriticalPath(int64_t value);

    static const char kNumGenerateBidConfigPromisesOnCriticalPathName[];
    static constexpr uint64_t kNumGenerateBidConfigPromisesOnCriticalPathNameHash = UINT64_C(13692171413445802233);
    AdsInterestGroup_AuctionLatency_V2& SetNumGenerateBidConfigPromisesOnCriticalPath(int64_t value);

    static const char kNumGenerateBidDirectFromSellerSignalsOnCriticalPathName[];
    static constexpr uint64_t kNumGenerateBidDirectFromSellerSignalsOnCriticalPathNameHash = UINT64_C(4876846632040656008);
    AdsInterestGroup_AuctionLatency_V2& SetNumGenerateBidDirectFromSellerSignalsOnCriticalPath(int64_t value);

    static const char kNumGenerateBidTrustedBiddingSignalsOnCriticalPathName[];
    static constexpr uint64_t kNumGenerateBidTrustedBiddingSignalsOnCriticalPathNameHash = UINT64_C(3166544493710110987);
    AdsInterestGroup_AuctionLatency_V2& SetNumGenerateBidTrustedBiddingSignalsOnCriticalPath(int64_t value);

    static const char kNumInterestGroupsName[];
    static constexpr uint64_t kNumInterestGroupsNameHash = UINT64_C(12771300644056798353);
    AdsInterestGroup_AuctionLatency_V2& SetNumInterestGroups(int64_t value);

    static const char kNumInterestGroupsWithNoBidsName[];
    static constexpr uint64_t kNumInterestGroupsWithNoBidsNameHash = UINT64_C(15708481179596224181);
    AdsInterestGroup_AuctionLatency_V2& SetNumInterestGroupsWithNoBids(int64_t value);

    static const char kNumInterestGroupsWithOnlyNonKAnonBidName[];
    static constexpr uint64_t kNumInterestGroupsWithOnlyNonKAnonBidNameHash = UINT64_C(17565464895667603039);
    AdsInterestGroup_AuctionLatency_V2& SetNumInterestGroupsWithOnlyNonKAnonBid(int64_t value);

    static const char kNumInterestGroupsWithOtherMultiBidName[];
    static constexpr uint64_t kNumInterestGroupsWithOtherMultiBidNameHash = UINT64_C(18316270741948443760);
    AdsInterestGroup_AuctionLatency_V2& SetNumInterestGroupsWithOtherMultiBid(int64_t value);

    static const char kNumInterestGroupsWithSameBidForKAnonAndNonKAnonName[];
    static constexpr uint64_t kNumInterestGroupsWithSameBidForKAnonAndNonKAnonNameHash = UINT64_C(7764242299071686810);
    AdsInterestGroup_AuctionLatency_V2& SetNumInterestGroupsWithSameBidForKAnonAndNonKAnon(int64_t value);

    static const char kNumInterestGroupsWithSeparateBidsForKAnonAndNonKAnonName[];
    static constexpr uint64_t kNumInterestGroupsWithSeparateBidsForKAnonAndNonKAnonNameHash = UINT64_C(9442320933407350648);
    AdsInterestGroup_AuctionLatency_V2& SetNumInterestGroupsWithSeparateBidsForKAnonAndNonKAnon(int64_t value);

    static const char kNumNegativeInterestGroupsName[];
    static constexpr uint64_t kNumNegativeInterestGroupsNameHash = UINT64_C(10297970658562756551);
    AdsInterestGroup_AuctionLatency_V2& SetNumNegativeInterestGroups(int64_t value);

    static const char kNumNegativeInterestGroupsIgnoredDueToInvalidSignatureName[];
    static constexpr uint64_t kNumNegativeInterestGroupsIgnoredDueToInvalidSignatureNameHash = UINT64_C(18296054258285221026);
    AdsInterestGroup_AuctionLatency_V2& SetNumNegativeInterestGroupsIgnoredDueToInvalidSignature(int64_t value);

    static const char kNumNegativeInterestGroupsIgnoredDueToJoiningOriginMismatchName[];
    static constexpr uint64_t kNumNegativeInterestGroupsIgnoredDueToJoiningOriginMismatchNameHash = UINT64_C(16440225141326239866);
    AdsInterestGroup_AuctionLatency_V2& SetNumNegativeInterestGroupsIgnoredDueToJoiningOriginMismatch(int64_t value);

    static const char kNumOwnersWithInterestGroupsName[];
    static constexpr uint64_t kNumOwnersWithInterestGroupsNameHash = UINT64_C(3499866861198089544);
    AdsInterestGroup_AuctionLatency_V2& SetNumOwnersWithInterestGroups(int64_t value);

    static const char kNumOwnersWithoutInterestGroupsName[];
    static constexpr uint64_t kNumOwnersWithoutInterestGroupsNameHash = UINT64_C(14381980322291953299);
    AdsInterestGroup_AuctionLatency_V2& SetNumOwnersWithoutInterestGroups(int64_t value);

    static const char kNumScoreAdCodeReadyOnCriticalPathName[];
    static constexpr uint64_t kNumScoreAdCodeReadyOnCriticalPathNameHash = UINT64_C(17290322157780053812);
    AdsInterestGroup_AuctionLatency_V2& SetNumScoreAdCodeReadyOnCriticalPath(int64_t value);

    static const char kNumScoreAdDirectFromSellerSignalsOnCriticalPathName[];
    static constexpr uint64_t kNumScoreAdDirectFromSellerSignalsOnCriticalPathNameHash = UINT64_C(12284997497481444612);
    AdsInterestGroup_AuctionLatency_V2& SetNumScoreAdDirectFromSellerSignalsOnCriticalPath(int64_t value);

    static const char kNumScoreAdTrustedScoringSignalsOnCriticalPathName[];
    static constexpr uint64_t kNumScoreAdTrustedScoringSignalsOnCriticalPathNameHash = UINT64_C(1309273105693338644);
    AdsInterestGroup_AuctionLatency_V2& SetNumScoreAdTrustedScoringSignalsOnCriticalPath(int64_t value);

    static const char kNumSellersWithBiddersName[];
    static constexpr uint64_t kNumSellersWithBiddersNameHash = UINT64_C(13414109950062296409);
    AdsInterestGroup_AuctionLatency_V2& SetNumSellersWithBidders(int64_t value);

    static const char kNumTopLevelBidsQueuedWaitingForConfigPromisesName[];
    static constexpr uint64_t kNumTopLevelBidsQueuedWaitingForConfigPromisesNameHash = UINT64_C(18174107111736375335);
    AdsInterestGroup_AuctionLatency_V2& SetNumTopLevelBidsQueuedWaitingForConfigPromises(int64_t value);

    static const char kNumTopLevelBidsQueuedWaitingForSellerWorkletName[];
    static constexpr uint64_t kNumTopLevelBidsQueuedWaitingForSellerWorkletNameHash = UINT64_C(18429587140188239580);
    AdsInterestGroup_AuctionLatency_V2& SetNumTopLevelBidsQueuedWaitingForSellerWorklet(int64_t value);

    static const char kResultName[];
    static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
    AdsInterestGroup_AuctionLatency_V2& SetResult(int64_t value);

    static const char kScoreSignalsFetchPhaseEndTimeInMillisName[];
    static constexpr uint64_t kScoreSignalsFetchPhaseEndTimeInMillisNameHash = UINT64_C(10003784614553670621);
    AdsInterestGroup_AuctionLatency_V2& SetScoreSignalsFetchPhaseEndTimeInMillis(int64_t value);

    static const char kScoreSignalsFetchPhaseStartTimeInMillisName[];
    static constexpr uint64_t kScoreSignalsFetchPhaseStartTimeInMillisNameHash = UINT64_C(9736818313221299464);
    AdsInterestGroup_AuctionLatency_V2& SetScoreSignalsFetchPhaseStartTimeInMillis(int64_t value);

    static const char kScoringPhaseEndTimeInMillisName[];
    static constexpr uint64_t kScoringPhaseEndTimeInMillisNameHash = UINT64_C(9083889969730447642);
    AdsInterestGroup_AuctionLatency_V2& SetScoringPhaseEndTimeInMillis(int64_t value);

    static const char kScoringPhaseStartTimeInMillisName[];
    static constexpr uint64_t kScoringPhaseStartTimeInMillisNameHash = UINT64_C(15028721279466311868);
    AdsInterestGroup_AuctionLatency_V2& SetScoringPhaseStartTimeInMillis(int64_t value);

    static const char kWorkletCreationPhaseEndTimeInMillisName[];
    static constexpr uint64_t kWorkletCreationPhaseEndTimeInMillisNameHash = UINT64_C(16431284590691901268);
    AdsInterestGroup_AuctionLatency_V2& SetWorkletCreationPhaseEndTimeInMillis(int64_t value);

    static const char kWorkletCreationPhaseStartTimeInMillisName[];
    static constexpr uint64_t kWorkletCreationPhaseStartTimeInMillisNameHash = UINT64_C(5970579697249646002);
    AdsInterestGroup_AuctionLatency_V2& SetWorkletCreationPhaseStartTimeInMillis(int64_t value);
};

class AdsIntervention_LastIntervention final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AdsIntervention_LastIntervention(ukm::SourceId source_id);
    explicit AdsIntervention_LastIntervention(ukm::SourceIdObj source_id);
    AdsIntervention_LastIntervention(AdsIntervention_LastIntervention&&);
    AdsIntervention_LastIntervention& operator=(AdsIntervention_LastIntervention&&);
    ~AdsIntervention_LastIntervention() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2556877997165288079);

    static const char kInterventionStatusName[];
    static constexpr uint64_t kInterventionStatusNameHash = UINT64_C(17407336889972122102);
    AdsIntervention_LastIntervention& SetInterventionStatus(int64_t value);

    static const char kInterventionTypeName[];
    static constexpr uint64_t kInterventionTypeNameHash = UINT64_C(10433808312201924328);
    AdsIntervention_LastIntervention& SetInterventionType(int64_t value);
};

class AmpPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AmpPageLoad(ukm::SourceId source_id);
    explicit AmpPageLoad(ukm::SourceIdObj source_id);
    AmpPageLoad(AmpPageLoad&&);
    AmpPageLoad& operator=(AmpPageLoad&&);
    ~AmpPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15288827799554694614);

    static const char kMainFrameAmpPageLoadName[];
    static constexpr uint64_t kMainFrameAmpPageLoadNameHash = UINT64_C(5461195790241701747);
    AmpPageLoad& SetMainFrameAmpPageLoad(int64_t value);

    static const char kSubFrame_InteractiveTiming_FirstInputDelay4Name[];
    static constexpr uint64_t kSubFrame_InteractiveTiming_FirstInputDelay4NameHash = UINT64_C(4724951111204316736);
    AmpPageLoad& SetSubFrame_InteractiveTiming_FirstInputDelay4(int64_t value);

    static const char kSubFrame_InteractiveTiming_NumInteractionsName[];
    static constexpr uint64_t kSubFrame_InteractiveTiming_NumInteractionsNameHash = UINT64_C(6405487252487015387);
    AmpPageLoad& SetSubFrame_InteractiveTiming_NumInteractions(int64_t value);

    static const char kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash = UINT64_C(14310210479358693733);
    AmpPageLoad& SetSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2Name[];
    static constexpr uint64_t kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2NameHash = UINT64_C(2587763567908773644);
    AmpPageLoad& SetSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2(int64_t value);

    static const char kSubFrame_LayoutInstability_CumulativeShiftScoreName[];
    static constexpr uint64_t kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash = UINT64_C(16418444555505335830);
    AmpPageLoad& SetSubFrame_LayoutInstability_CumulativeShiftScore(int64_t value);

    static const char kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName[];
    static constexpr uint64_t kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash = UINT64_C(14270238291922659727);
    AmpPageLoad& SetSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScroll(int64_t value);

    static const char kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash = UINT64_C(12481536835011236131);
    AmpPageLoad& SetSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kSubFrame_MainFrameToSubFrameNavigationDeltaName[];
    static constexpr uint64_t kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash = UINT64_C(8980472913360711190);
    AmpPageLoad& SetSubFrame_MainFrameToSubFrameNavigationDelta(int64_t value);

    static const char kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName[];
    static constexpr uint64_t kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash = UINT64_C(638842222187756601);
    AmpPageLoad& SetSubFrame_PaintTiming_NavigationToFirstContentfulPaint(int64_t value);

    static const char kSubFrame_PaintTiming_NavigationToFirstPaintName[];
    static constexpr uint64_t kSubFrame_PaintTiming_NavigationToFirstPaintNameHash = UINT64_C(248118270008625401);
    AmpPageLoad& SetSubFrame_PaintTiming_NavigationToFirstPaint(int64_t value);

    static const char kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2Name[];
    static constexpr uint64_t kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2NameHash = UINT64_C(2719061015675078879);
    AmpPageLoad& SetSubFrame_PaintTiming_NavigationToLargestContentfulPaint2(int64_t value);

    static const char kSubFrameAmpPageLoadName[];
    static constexpr uint64_t kSubFrameAmpPageLoadNameHash = UINT64_C(6483268505712723387);
    AmpPageLoad& SetSubFrameAmpPageLoad(int64_t value);
};

class Android_DarkTheme_AutoDarkMode final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Android_DarkTheme_AutoDarkMode(ukm::SourceId source_id);
    explicit Android_DarkTheme_AutoDarkMode(ukm::SourceIdObj source_id);
    Android_DarkTheme_AutoDarkMode(Android_DarkTheme_AutoDarkMode&&);
    Android_DarkTheme_AutoDarkMode& operator=(Android_DarkTheme_AutoDarkMode&&);
    ~Android_DarkTheme_AutoDarkMode() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16711907311792517361);

    static const char kDisabledByUserName[];
    static constexpr uint64_t kDisabledByUserNameHash = UINT64_C(988091392554320813);
    Android_DarkTheme_AutoDarkMode& SetDisabledByUser(int64_t value);
};

class Android_MultiWindowChangeActivity final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Android_MultiWindowChangeActivity(ukm::SourceId source_id);
    explicit Android_MultiWindowChangeActivity(ukm::SourceIdObj source_id);
    Android_MultiWindowChangeActivity(Android_MultiWindowChangeActivity&&);
    Android_MultiWindowChangeActivity& operator=(Android_MultiWindowChangeActivity&&);
    ~Android_MultiWindowChangeActivity() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4355485518635673093);

    static const char kActivityTypeName[];
    static constexpr uint64_t kActivityTypeNameHash = UINT64_C(3974259668746749924);
    Android_MultiWindowChangeActivity& SetActivityType(int64_t value);
};

class Android_MultiWindowState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Android_MultiWindowState(ukm::SourceId source_id);
    explicit Android_MultiWindowState(ukm::SourceIdObj source_id);
    Android_MultiWindowState(Android_MultiWindowState&&);
    Android_MultiWindowState& operator=(Android_MultiWindowState&&);
    ~Android_MultiWindowState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10096673379731574014);

    static const char kWindowStateName[];
    static constexpr uint64_t kWindowStateNameHash = UINT64_C(6916821418093523230);
    Android_MultiWindowState& SetWindowState(int64_t value);
};

class Android_NonDefaultRdsPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Android_NonDefaultRdsPageLoad(ukm::SourceId source_id);
    explicit Android_NonDefaultRdsPageLoad(ukm::SourceIdObj source_id);
    Android_NonDefaultRdsPageLoad(Android_NonDefaultRdsPageLoad&&);
    Android_NonDefaultRdsPageLoad& operator=(Android_NonDefaultRdsPageLoad&&);
    ~Android_NonDefaultRdsPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1673574238447854674);

    static const char kUserAgentTypeName[];
    static constexpr uint64_t kUserAgentTypeNameHash = UINT64_C(2318367853561664205);
    Android_NonDefaultRdsPageLoad& SetUserAgentType(int64_t value);
};

class Android_ScreenRotation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Android_ScreenRotation(ukm::SourceId source_id);
    explicit Android_ScreenRotation(ukm::SourceIdObj source_id);
    Android_ScreenRotation(Android_ScreenRotation&&);
    Android_ScreenRotation& operator=(Android_ScreenRotation&&);
    ~Android_ScreenRotation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8962487173277472783);

    static const char kTargetDeviceOrientationName[];
    static constexpr uint64_t kTargetDeviceOrientationNameHash = UINT64_C(15531336490743774368);
    Android_ScreenRotation& SetTargetDeviceOrientation(int64_t value);
};

class Android_UserRequestedUserAgentChange final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Android_UserRequestedUserAgentChange(ukm::SourceId source_id);
    explicit Android_UserRequestedUserAgentChange(ukm::SourceIdObj source_id);
    Android_UserRequestedUserAgentChange(Android_UserRequestedUserAgentChange&&);
    Android_UserRequestedUserAgentChange& operator=(Android_UserRequestedUserAgentChange&&);
    ~Android_UserRequestedUserAgentChange() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11570336803537235206);

    static const char kUserAgentTypeName[];
    static constexpr uint64_t kUserAgentTypeNameHash = UINT64_C(2318367853561664205);
    Android_UserRequestedUserAgentChange& SetUserAgentType(int64_t value);
};

class AppListAppClickData final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AppListAppClickData(ukm::SourceId source_id);
    explicit AppListAppClickData(ukm::SourceIdObj source_id);
    AppListAppClickData(AppListAppClickData&&);
    AppListAppClickData& operator=(AppListAppClickData&&);
    ~AppListAppClickData() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4589718692267131532);

    static const char kAppLaunchIdName[];
    static constexpr uint64_t kAppLaunchIdNameHash = UINT64_C(18141239051505688203);
    AppListAppClickData& SetAppLaunchId(int64_t value);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    AppListAppClickData& SetAppType(int64_t value);

    static const char kClickRankName[];
    static constexpr uint64_t kClickRankNameHash = UINT64_C(2055104011801596037);
    AppListAppClickData& SetClickRank(int64_t value);

    static const char kClicksEachHour00Name[];
    static constexpr uint64_t kClicksEachHour00NameHash = UINT64_C(9852218943589438537);
    AppListAppClickData& SetClicksEachHour00(int64_t value);

    static const char kClicksEachHour01Name[];
    static constexpr uint64_t kClicksEachHour01NameHash = UINT64_C(4594220155145935772);
    AppListAppClickData& SetClicksEachHour01(int64_t value);

    static const char kClicksEachHour02Name[];
    static constexpr uint64_t kClicksEachHour02NameHash = UINT64_C(2979946241209199190);
    AppListAppClickData& SetClicksEachHour02(int64_t value);

    static const char kClicksEachHour03Name[];
    static constexpr uint64_t kClicksEachHour03NameHash = UINT64_C(2807870101964151999);
    AppListAppClickData& SetClicksEachHour03(int64_t value);

    static const char kClicksEachHour04Name[];
    static constexpr uint64_t kClicksEachHour04NameHash = UINT64_C(714499009068860843);
    AppListAppClickData& SetClicksEachHour04(int64_t value);

    static const char kClicksEachHour05Name[];
    static constexpr uint64_t kClicksEachHour05NameHash = UINT64_C(17713188968632146147);
    AppListAppClickData& SetClicksEachHour05(int64_t value);

    static const char kClicksEachHour06Name[];
    static constexpr uint64_t kClicksEachHour06NameHash = UINT64_C(1175107707626973313);
    AppListAppClickData& SetClicksEachHour06(int64_t value);

    static const char kClicksEachHour07Name[];
    static constexpr uint64_t kClicksEachHour07NameHash = UINT64_C(2271012638508829384);
    AppListAppClickData& SetClicksEachHour07(int64_t value);

    static const char kClicksEachHour08Name[];
    static constexpr uint64_t kClicksEachHour08NameHash = UINT64_C(1772457901586832457);
    AppListAppClickData& SetClicksEachHour08(int64_t value);

    static const char kClicksEachHour09Name[];
    static constexpr uint64_t kClicksEachHour09NameHash = UINT64_C(2851247351851385842);
    AppListAppClickData& SetClicksEachHour09(int64_t value);

    static const char kClicksEachHour10Name[];
    static constexpr uint64_t kClicksEachHour10NameHash = UINT64_C(1806588398743155997);
    AppListAppClickData& SetClicksEachHour10(int64_t value);

    static const char kClicksEachHour11Name[];
    static constexpr uint64_t kClicksEachHour11NameHash = UINT64_C(3131444643108020140);
    AppListAppClickData& SetClicksEachHour11(int64_t value);

    static const char kClicksEachHour12Name[];
    static constexpr uint64_t kClicksEachHour12NameHash = UINT64_C(2448014348189133351);
    AppListAppClickData& SetClicksEachHour12(int64_t value);

    static const char kClicksEachHour13Name[];
    static constexpr uint64_t kClicksEachHour13NameHash = UINT64_C(18250438715855980346);
    AppListAppClickData& SetClicksEachHour13(int64_t value);

    static const char kClicksEachHour14Name[];
    static constexpr uint64_t kClicksEachHour14NameHash = UINT64_C(17694991336934069562);
    AppListAppClickData& SetClicksEachHour14(int64_t value);

    static const char kClicksEachHour15Name[];
    static constexpr uint64_t kClicksEachHour15NameHash = UINT64_C(841563503357754805);
    AppListAppClickData& SetClicksEachHour15(int64_t value);

    static const char kClicksEachHour16Name[];
    static constexpr uint64_t kClicksEachHour16NameHash = UINT64_C(2083341464824283347);
    AppListAppClickData& SetClicksEachHour16(int64_t value);

    static const char kClicksEachHour17Name[];
    static constexpr uint64_t kClicksEachHour17NameHash = UINT64_C(16117389064877716783);
    AppListAppClickData& SetClicksEachHour17(int64_t value);

    static const char kClicksEachHour18Name[];
    static constexpr uint64_t kClicksEachHour18NameHash = UINT64_C(8357842770757548892);
    AppListAppClickData& SetClicksEachHour18(int64_t value);

    static const char kClicksEachHour19Name[];
    static constexpr uint64_t kClicksEachHour19NameHash = UINT64_C(9017652834579276383);
    AppListAppClickData& SetClicksEachHour19(int64_t value);

    static const char kClicksEachHour20Name[];
    static constexpr uint64_t kClicksEachHour20NameHash = UINT64_C(16309270750830060266);
    AppListAppClickData& SetClicksEachHour20(int64_t value);

    static const char kClicksEachHour21Name[];
    static constexpr uint64_t kClicksEachHour21NameHash = UINT64_C(8993148668647496674);
    AppListAppClickData& SetClicksEachHour21(int64_t value);

    static const char kClicksEachHour22Name[];
    static constexpr uint64_t kClicksEachHour22NameHash = UINT64_C(6608700521453268064);
    AppListAppClickData& SetClicksEachHour22(int64_t value);

    static const char kClicksEachHour23Name[];
    static constexpr uint64_t kClicksEachHour23NameHash = UINT64_C(10184622070282293203);
    AppListAppClickData& SetClicksEachHour23(int64_t value);

    static const char kClicksLast24HoursName[];
    static constexpr uint64_t kClicksLast24HoursNameHash = UINT64_C(8208362521514978200);
    AppListAppClickData& SetClicksLast24Hours(int64_t value);

    static const char kClicksLastHourName[];
    static constexpr uint64_t kClicksLastHourNameHash = UINT64_C(11587637074403422994);
    AppListAppClickData& SetClicksLastHour(int64_t value);

    static const char kLastLaunchedFromName[];
    static constexpr uint64_t kLastLaunchedFromNameHash = UINT64_C(17950909090926741200);
    AppListAppClickData& SetLastLaunchedFrom(int64_t value);

    static const char kMostRecentlyUsedIndexName[];
    static constexpr uint64_t kMostRecentlyUsedIndexNameHash = UINT64_C(4904327804870856216);
    AppListAppClickData& SetMostRecentlyUsedIndex(int64_t value);

    static const char kSequenceNumberName[];
    static constexpr uint64_t kSequenceNumberNameHash = UINT64_C(3161886034278201905);
    AppListAppClickData& SetSequenceNumber(int64_t value);

    static const char kTimeSinceLastClickName[];
    static constexpr uint64_t kTimeSinceLastClickNameHash = UINT64_C(6482216598721160744);
    AppListAppClickData& SetTimeSinceLastClick(int64_t value);

    static const char kTotalClicksName[];
    static constexpr uint64_t kTotalClicksNameHash = UINT64_C(14899889891285787674);
    AppListAppClickData& SetTotalClicks(int64_t value);
};

class AppListAppLaunch final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit AppListAppLaunch(ukm::SourceId source_id);
    explicit AppListAppLaunch(ukm::SourceIdObj source_id);
    AppListAppLaunch(AppListAppLaunch&&);
    AppListAppLaunch& operator=(AppListAppLaunch&&);
    ~AppListAppLaunch() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16635456347627451827);

    static const char kAllClicksLast24HoursName[];
    static constexpr uint64_t kAllClicksLast24HoursNameHash = UINT64_C(4575029519393656215);
    AppListAppLaunch& SetAllClicksLast24Hours(int64_t value);

    static const char kAllClicksLastHourName[];
    static constexpr uint64_t kAllClicksLastHourNameHash = UINT64_C(14694624669615609981);
    AppListAppLaunch& SetAllClicksLastHour(int64_t value);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    AppListAppLaunch& SetAppType(int64_t value);

    static const char kClickMethodName[];
    static constexpr uint64_t kClickMethodNameHash = UINT64_C(6788393749258903020);
    AppListAppLaunch& SetClickMethod(int64_t value);

    static const char kDayOfWeekName[];
    static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
    AppListAppLaunch& SetDayOfWeek(int64_t value);

    static const char kDeviceModeName[];
    static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
    AppListAppLaunch& SetDeviceMode(int64_t value);

    static const char kDeviceTypeName[];
    static constexpr uint64_t kDeviceTypeNameHash = UINT64_C(7795620498098931292);
    AppListAppLaunch& SetDeviceType(int64_t value);

    static const char kHourOfDayName[];
    static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
    AppListAppLaunch& SetHourOfDay(int64_t value);

    static const char kLaunchedFromName[];
    static constexpr uint64_t kLaunchedFromNameHash = UINT64_C(6515313514467325646);
    AppListAppLaunch& SetLaunchedFrom(int64_t value);

    static const char kPositionIndexName[];
    static constexpr uint64_t kPositionIndexNameHash = UINT64_C(11513691020323067369);
    AppListAppLaunch& SetPositionIndex(int64_t value);

    static const char kTotalHoursName[];
    static constexpr uint64_t kTotalHoursNameHash = UINT64_C(14771740324071435168);
    AppListAppLaunch& SetTotalHours(int64_t value);
};

class Autofill_CardUploadDecision final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_CardUploadDecision(ukm::SourceId source_id);
    explicit Autofill_CardUploadDecision(ukm::SourceIdObj source_id);
    Autofill_CardUploadDecision(Autofill_CardUploadDecision&&);
    Autofill_CardUploadDecision& operator=(Autofill_CardUploadDecision&&);
    ~Autofill_CardUploadDecision() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3597047501124112026);

    static const char kUploadDecisionName[];
    static constexpr uint64_t kUploadDecisionNameHash = UINT64_C(1530202151366371243);
    Autofill_CardUploadDecision& SetUploadDecision(int64_t value);
};

class Autofill_CreditCardFill final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_CreditCardFill(ukm::SourceId source_id);
    explicit Autofill_CreditCardFill(ukm::SourceIdObj source_id);
    Autofill_CreditCardFill(Autofill_CreditCardFill&&);
    Autofill_CreditCardFill& operator=(Autofill_CreditCardFill&&);
    ~Autofill_CreditCardFill() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1996892304603525762);

    static const char kFillable_BeforeSecurity_BitmaskName[];
    static constexpr uint64_t kFillable_BeforeSecurity_BitmaskNameHash = UINT64_C(14401626179625678930);
    Autofill_CreditCardFill& SetFillable_BeforeSecurity_Bitmask(int64_t value);

    static const char kFillable_BeforeSecurity_QualitativeName[];
    static constexpr uint64_t kFillable_BeforeSecurity_QualitativeNameHash = UINT64_C(1463674364616392165);
    Autofill_CreditCardFill& SetFillable_BeforeSecurity_Qualitative(int64_t value);

    static const char kFillable_BeforeSecurity_Visible_BitmaskName[];
    static constexpr uint64_t kFillable_BeforeSecurity_Visible_BitmaskNameHash = UINT64_C(8220719584340325581);
    Autofill_CreditCardFill& SetFillable_BeforeSecurity_Visible_Bitmask(int64_t value);

    static const char kFillable_BeforeSecurity_Visible_QualitativeName[];
    static constexpr uint64_t kFillable_BeforeSecurity_Visible_QualitativeNameHash = UINT64_C(1070790715295398389);
    Autofill_CreditCardFill& SetFillable_BeforeSecurity_Visible_Qualitative(int64_t value);

    static const char kFilled_AfterSecurity_BitmaskName[];
    static constexpr uint64_t kFilled_AfterSecurity_BitmaskNameHash = UINT64_C(16407489604597583071);
    Autofill_CreditCardFill& SetFilled_AfterSecurity_Bitmask(int64_t value);

    static const char kFilled_AfterSecurity_QualitativeName[];
    static constexpr uint64_t kFilled_AfterSecurity_QualitativeNameHash = UINT64_C(1637507067647600871);
    Autofill_CreditCardFill& SetFilled_AfterSecurity_Qualitative(int64_t value);

    static const char kFilled_AfterSecurity_Visible_BitmaskName[];
    static constexpr uint64_t kFilled_AfterSecurity_Visible_BitmaskNameHash = UINT64_C(14189182261550739763);
    Autofill_CreditCardFill& SetFilled_AfterSecurity_Visible_Bitmask(int64_t value);

    static const char kFilled_AfterSecurity_Visible_QualitativeName[];
    static constexpr uint64_t kFilled_AfterSecurity_Visible_QualitativeNameHash = UINT64_C(242347718191828189);
    Autofill_CreditCardFill& SetFilled_AfterSecurity_Visible_Qualitative(int64_t value);

    static const char kFilled_BeforeSecurity_BitmaskName[];
    static constexpr uint64_t kFilled_BeforeSecurity_BitmaskNameHash = UINT64_C(10920561826798158638);
    Autofill_CreditCardFill& SetFilled_BeforeSecurity_Bitmask(int64_t value);

    static const char kFilled_BeforeSecurity_QualitativeName[];
    static constexpr uint64_t kFilled_BeforeSecurity_QualitativeNameHash = UINT64_C(10463945293182754195);
    Autofill_CreditCardFill& SetFilled_BeforeSecurity_Qualitative(int64_t value);

    static const char kFilled_BeforeSecurity_Visible_BitmaskName[];
    static constexpr uint64_t kFilled_BeforeSecurity_Visible_BitmaskNameHash = UINT64_C(5759464922790006912);
    Autofill_CreditCardFill& SetFilled_BeforeSecurity_Visible_Bitmask(int64_t value);

    static const char kFilled_BeforeSecurity_Visible_QualitativeName[];
    static constexpr uint64_t kFilled_BeforeSecurity_Visible_QualitativeNameHash = UINT64_C(14706365987156530447);
    Autofill_CreditCardFill& SetFilled_BeforeSecurity_Visible_Qualitative(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_CreditCardFill& SetFormSignature(int64_t value);

    static const char kSharedAutofillName[];
    static constexpr uint64_t kSharedAutofillNameHash = UINT64_C(2939421557428182983);
    Autofill_CreditCardFill& SetSharedAutofill(int64_t value);
};

class Autofill_DeveloperEngagement final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_DeveloperEngagement(ukm::SourceId source_id);
    explicit Autofill_DeveloperEngagement(ukm::SourceIdObj source_id);
    Autofill_DeveloperEngagement(Autofill_DeveloperEngagement&&);
    Autofill_DeveloperEngagement& operator=(Autofill_DeveloperEngagement&&);
    ~Autofill_DeveloperEngagement() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14550063303370974566);

    static const char kDeveloperEngagementName[];
    static constexpr uint64_t kDeveloperEngagementNameHash = UINT64_C(15538334115650657597);
    Autofill_DeveloperEngagement& SetDeveloperEngagement(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_DeveloperEngagement& SetFormSignature(int64_t value);

    static const char kFormTypesName[];
    static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
    Autofill_DeveloperEngagement& SetFormTypes(int64_t value);

    static const char kIsForCreditCardName[];
    static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
    Autofill_DeveloperEngagement& SetIsForCreditCard(int64_t value);
};

class Autofill_EditedAutofilledFieldAtSubmission final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_EditedAutofilledFieldAtSubmission(ukm::SourceId source_id);
    explicit Autofill_EditedAutofilledFieldAtSubmission(ukm::SourceIdObj source_id);
    Autofill_EditedAutofilledFieldAtSubmission(Autofill_EditedAutofilledFieldAtSubmission&&);
    Autofill_EditedAutofilledFieldAtSubmission& operator=(Autofill_EditedAutofilledFieldAtSubmission&&);
    ~Autofill_EditedAutofilledFieldAtSubmission() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15069365949047700716);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_EditedAutofilledFieldAtSubmission& SetFieldSignature(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_EditedAutofilledFieldAtSubmission& SetFormSignature(int64_t value);

    static const char kOverallTypeName[];
    static constexpr uint64_t kOverallTypeNameHash = UINT64_C(16896259778850698076);
    Autofill_EditedAutofilledFieldAtSubmission& SetOverallType(int64_t value);
};

class Autofill_FieldFillStatus final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_FieldFillStatus(ukm::SourceId source_id);
    explicit Autofill_FieldFillStatus(ukm::SourceIdObj source_id);
    Autofill_FieldFillStatus(Autofill_FieldFillStatus&&);
    Autofill_FieldFillStatus& operator=(Autofill_FieldFillStatus&&);
    ~Autofill_FieldFillStatus() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11456448948041474991);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_FieldFillStatus& SetFieldSignature(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_FieldFillStatus& SetFormSignature(int64_t value);

    static const char kIsAutofilledName[];
    static constexpr uint64_t kIsAutofilledNameHash = UINT64_C(17551275327964504767);
    Autofill_FieldFillStatus& SetIsAutofilled(int64_t value);

    static const char kMillisecondsSinceFormParsedName[];
    static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
    Autofill_FieldFillStatus& SetMillisecondsSinceFormParsed(int64_t value);

    static const char kPredictionSourceName[];
    static constexpr uint64_t kPredictionSourceNameHash = UINT64_C(5017294346205954242);
    Autofill_FieldFillStatus& SetPredictionSource(int64_t value);

    static const char kValidationEventName[];
    static constexpr uint64_t kValidationEventNameHash = UINT64_C(17361557898566789372);
    Autofill_FieldFillStatus& SetValidationEvent(int64_t value);

    static const char kWasPreviouslyAutofilledName[];
    static constexpr uint64_t kWasPreviouslyAutofilledNameHash = UINT64_C(1646712375187153208);
    Autofill_FieldFillStatus& SetWasPreviouslyAutofilled(int64_t value);
};

class Autofill_FieldTypeValidation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_FieldTypeValidation(ukm::SourceId source_id);
    explicit Autofill_FieldTypeValidation(ukm::SourceIdObj source_id);
    Autofill_FieldTypeValidation(Autofill_FieldTypeValidation&&);
    Autofill_FieldTypeValidation& operator=(Autofill_FieldTypeValidation&&);
    ~Autofill_FieldTypeValidation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1290380890049589579);

    static const char kActualTypeName[];
    static constexpr uint64_t kActualTypeNameHash = UINT64_C(4245305632546756744);
    Autofill_FieldTypeValidation& SetActualType(int64_t value);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_FieldTypeValidation& SetFieldSignature(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_FieldTypeValidation& SetFormSignature(int64_t value);

    static const char kMillisecondsSinceFormParsedName[];
    static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
    Autofill_FieldTypeValidation& SetMillisecondsSinceFormParsed(int64_t value);

    static const char kPredictedTypeName[];
    static constexpr uint64_t kPredictedTypeNameHash = UINT64_C(13118965333595910063);
    Autofill_FieldTypeValidation& SetPredictedType(int64_t value);

    static const char kPredictionSourceName[];
    static constexpr uint64_t kPredictionSourceNameHash = UINT64_C(5017294346205954242);
    Autofill_FieldTypeValidation& SetPredictionSource(int64_t value);

    static const char kValidationEventName[];
    static constexpr uint64_t kValidationEventNameHash = UINT64_C(17361557898566789372);
    Autofill_FieldTypeValidation& SetValidationEvent(int64_t value);
};

class Autofill_FormEvent final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_FormEvent(ukm::SourceId source_id);
    explicit Autofill_FormEvent(ukm::SourceIdObj source_id);
    Autofill_FormEvent(Autofill_FormEvent&&);
    Autofill_FormEvent& operator=(Autofill_FormEvent&&);
    ~Autofill_FormEvent() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16631655786524489525);

    static const char kAutofillFormEventName[];
    static constexpr uint64_t kAutofillFormEventNameHash = UINT64_C(101161368576121811);
    Autofill_FormEvent& SetAutofillFormEvent(int64_t value);

    static const char kFormTypesName[];
    static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
    Autofill_FormEvent& SetFormTypes(int64_t value);

    static const char kMillisecondsSinceFormParsedName[];
    static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
    Autofill_FormEvent& SetMillisecondsSinceFormParsed(int64_t value);
};

class Autofill_FormFillSuccessIOS final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_FormFillSuccessIOS(ukm::SourceId source_id);
    explicit Autofill_FormFillSuccessIOS(ukm::SourceIdObj source_id);
    Autofill_FormFillSuccessIOS(Autofill_FormFillSuccessIOS&&);
    Autofill_FormFillSuccessIOS& operator=(Autofill_FormFillSuccessIOS&&);
    ~Autofill_FormFillSuccessIOS() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(409508311075101037);

    static const char kFormFillSuccessName[];
    static constexpr uint64_t kFormFillSuccessNameHash = UINT64_C(4441642850899500057);
    Autofill_FormFillSuccessIOS& SetFormFillSuccess(int64_t value);
};

class Autofill_HiddenRepresentationalFieldSkipDecision final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_HiddenRepresentationalFieldSkipDecision(ukm::SourceId source_id);
    explicit Autofill_HiddenRepresentationalFieldSkipDecision(ukm::SourceIdObj source_id);
    Autofill_HiddenRepresentationalFieldSkipDecision(Autofill_HiddenRepresentationalFieldSkipDecision&&);
    Autofill_HiddenRepresentationalFieldSkipDecision& operator=(Autofill_HiddenRepresentationalFieldSkipDecision&&);
    ~Autofill_HiddenRepresentationalFieldSkipDecision() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14481214823422924028);

    static const char kFieldOverallTypeName[];
    static constexpr uint64_t kFieldOverallTypeNameHash = UINT64_C(5024560379185631865);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetFieldOverallType(int64_t value);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetFieldSignature(int64_t value);

    static const char kFieldTypeGroupName[];
    static constexpr uint64_t kFieldTypeGroupNameHash = UINT64_C(4771816394504495494);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetFieldTypeGroup(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetFormSignature(int64_t value);

    static const char kHeuristicTypeName[];
    static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetHeuristicType(int64_t value);

    static const char kHtmlFieldModeName[];
    static constexpr uint64_t kHtmlFieldModeNameHash = UINT64_C(15151906885863383301);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetHtmlFieldMode(int64_t value);

    static const char kHtmlFieldTypeName[];
    static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetHtmlFieldType(int64_t value);

    static const char kIsSkippedName[];
    static constexpr uint64_t kIsSkippedNameHash = UINT64_C(13869837774034534594);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetIsSkipped(int64_t value);

    static const char kServerTypeName[];
    static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
    Autofill_HiddenRepresentationalFieldSkipDecision& SetServerType(int64_t value);
};

class Autofill_InteractedWithForm final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_InteractedWithForm(ukm::SourceId source_id);
    explicit Autofill_InteractedWithForm(ukm::SourceIdObj source_id);
    Autofill_InteractedWithForm(Autofill_InteractedWithForm&&);
    Autofill_InteractedWithForm& operator=(Autofill_InteractedWithForm&&);
    ~Autofill_InteractedWithForm() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12943113565528625214);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_InteractedWithForm& SetFormSignature(int64_t value);

    static const char kFormTypesName[];
    static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
    Autofill_InteractedWithForm& SetFormTypes(int64_t value);

    static const char kIsForCreditCardName[];
    static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
    Autofill_InteractedWithForm& SetIsForCreditCard(int64_t value);

    static const char kLocalRecordTypeCountName[];
    static constexpr uint64_t kLocalRecordTypeCountNameHash = UINT64_C(4967504613046448052);
    Autofill_InteractedWithForm& SetLocalRecordTypeCount(int64_t value);

    static const char kServerRecordTypeCountName[];
    static constexpr uint64_t kServerRecordTypeCountNameHash = UINT64_C(7268279397149312763);
    Autofill_InteractedWithForm& SetServerRecordTypeCount(int64_t value);
};

class Autofill_KeyMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_KeyMetrics(ukm::SourceId source_id);
    explicit Autofill_KeyMetrics(ukm::SourceIdObj source_id);
    Autofill_KeyMetrics(Autofill_KeyMetrics&&);
    Autofill_KeyMetrics& operator=(Autofill_KeyMetrics&&);
    ~Autofill_KeyMetrics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4026604158724844667);

    static const char kAutofillFillsName[];
    static constexpr uint64_t kAutofillFillsNameHash = UINT64_C(7830837090299082022);
    Autofill_KeyMetrics& SetAutofillFills(int64_t value);

    static const char kFastCheckoutRunIdName[];
    static constexpr uint64_t kFastCheckoutRunIdNameHash = UINT64_C(8774362863465124629);
    Autofill_KeyMetrics& SetFastCheckoutRunId(int64_t value);

    static const char kFillingAcceptanceName[];
    static constexpr uint64_t kFillingAcceptanceNameHash = UINT64_C(16937874243866007579);
    Autofill_KeyMetrics& SetFillingAcceptance(int64_t value);

    static const char kFillingAssistanceName[];
    static constexpr uint64_t kFillingAssistanceNameHash = UINT64_C(4441810537939635736);
    Autofill_KeyMetrics& SetFillingAssistance(int64_t value);

    static const char kFillingCorrectnessName[];
    static constexpr uint64_t kFillingCorrectnessNameHash = UINT64_C(10147653658805856555);
    Autofill_KeyMetrics& SetFillingCorrectness(int64_t value);

    static const char kFillingReadinessName[];
    static constexpr uint64_t kFillingReadinessNameHash = UINT64_C(2113836689234660122);
    Autofill_KeyMetrics& SetFillingReadiness(int64_t value);

    static const char kFlowIdName[];
    static constexpr uint64_t kFlowIdNameHash = UINT64_C(11615983711679266461);
    Autofill_KeyMetrics& SetFlowId(int64_t value);

    static const char kFormElementUserModificationsName[];
    static constexpr uint64_t kFormElementUserModificationsNameHash = UINT64_C(9764065068563561078);
    Autofill_KeyMetrics& SetFormElementUserModifications(int64_t value);

    static const char kFormTypesName[];
    static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
    Autofill_KeyMetrics& SetFormTypes(int64_t value);
};

class Autofill_SuggestionFilled final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_SuggestionFilled(ukm::SourceId source_id);
    explicit Autofill_SuggestionFilled(ukm::SourceIdObj source_id);
    Autofill_SuggestionFilled(Autofill_SuggestionFilled&&);
    Autofill_SuggestionFilled& operator=(Autofill_SuggestionFilled&&);
    ~Autofill_SuggestionFilled() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17703268464688884622);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_SuggestionFilled& SetFieldSignature(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_SuggestionFilled& SetFormSignature(int64_t value);

    static const char kIsForCreditCardName[];
    static constexpr uint64_t kIsForCreditCardNameHash = UINT64_C(15493515522068288455);
    Autofill_SuggestionFilled& SetIsForCreditCard(int64_t value);

    static const char kMillisecondsSinceFormParsedName[];
    static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
    Autofill_SuggestionFilled& SetMillisecondsSinceFormParsed(int64_t value);

    static const char kRecordTypeName[];
    static constexpr uint64_t kRecordTypeNameHash = UINT64_C(2556852903161176255);
    Autofill_SuggestionFilled& SetRecordType(int64_t value);
};

class Autofill_SuggestionsShown final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_SuggestionsShown(ukm::SourceId source_id);
    explicit Autofill_SuggestionsShown(ukm::SourceIdObj source_id);
    Autofill_SuggestionsShown(Autofill_SuggestionsShown&&);
    Autofill_SuggestionsShown& operator=(Autofill_SuggestionsShown&&);
    ~Autofill_SuggestionsShown() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7579660929739851736);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_SuggestionsShown& SetFieldSignature(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_SuggestionsShown& SetFormSignature(int64_t value);

    static const char kHeuristicTypeName[];
    static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
    Autofill_SuggestionsShown& SetHeuristicType(int64_t value);

    static const char kHtmlFieldTypeName[];
    static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
    Autofill_SuggestionsShown& SetHtmlFieldType(int64_t value);

    static const char kMillisecondsSinceFormParsedName[];
    static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
    Autofill_SuggestionsShown& SetMillisecondsSinceFormParsed(int64_t value);

    static const char kServerTypeName[];
    static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
    Autofill_SuggestionsShown& SetServerType(int64_t value);
};

class Autofill_TextFieldDidChange final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill_TextFieldDidChange(ukm::SourceId source_id);
    explicit Autofill_TextFieldDidChange(ukm::SourceIdObj source_id);
    Autofill_TextFieldDidChange(Autofill_TextFieldDidChange&&);
    Autofill_TextFieldDidChange& operator=(Autofill_TextFieldDidChange&&);
    ~Autofill_TextFieldDidChange() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8376184896509210883);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill_TextFieldDidChange& SetFieldSignature(int64_t value);

    static const char kFieldTypeGroupName[];
    static constexpr uint64_t kFieldTypeGroupNameHash = UINT64_C(4771816394504495494);
    Autofill_TextFieldDidChange& SetFieldTypeGroup(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill_TextFieldDidChange& SetFormSignature(int64_t value);

    static const char kHeuristicTypeName[];
    static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
    Autofill_TextFieldDidChange& SetHeuristicType(int64_t value);

    static const char kHtmlFieldModeName[];
    static constexpr uint64_t kHtmlFieldModeNameHash = UINT64_C(15151906885863383301);
    Autofill_TextFieldDidChange& SetHtmlFieldMode(int64_t value);

    static const char kHtmlFieldTypeName[];
    static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
    Autofill_TextFieldDidChange& SetHtmlFieldType(int64_t value);

    static const char kIsAutofilledName[];
    static constexpr uint64_t kIsAutofilledNameHash = UINT64_C(17551275327964504767);
    Autofill_TextFieldDidChange& SetIsAutofilled(int64_t value);

    static const char kIsEmptyName[];
    static constexpr uint64_t kIsEmptyNameHash = UINT64_C(13334288173870607265);
    Autofill_TextFieldDidChange& SetIsEmpty(int64_t value);

    static const char kMillisecondsSinceFormParsedName[];
    static constexpr uint64_t kMillisecondsSinceFormParsedNameHash = UINT64_C(822617360850595330);
    Autofill_TextFieldDidChange& SetMillisecondsSinceFormParsed(int64_t value);

    static const char kServerTypeName[];
    static constexpr uint64_t kServerTypeNameHash = UINT64_C(3640361506783159573);
    Autofill_TextFieldDidChange& SetServerType(int64_t value);
};

class Autofill2_AddressProfileImport final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill2_AddressProfileImport(ukm::SourceId source_id);
    explicit Autofill2_AddressProfileImport(ukm::SourceIdObj source_id);
    Autofill2_AddressProfileImport(Autofill2_AddressProfileImport&&);
    Autofill2_AddressProfileImport& operator=(Autofill2_AddressProfileImport&&);
    ~Autofill2_AddressProfileImport() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4418205642899146911);

    static const char kAutocompleteUnrecognizedImportName[];
    static constexpr uint64_t kAutocompleteUnrecognizedImportNameHash = UINT64_C(7781521878207654023);
    Autofill2_AddressProfileImport& SetAutocompleteUnrecognizedImport(int64_t value);

    static const char kDuplicationRankName[];
    static constexpr uint64_t kDuplicationRankNameHash = UINT64_C(6310104327476160791);
    Autofill2_AddressProfileImport& SetDuplicationRank(int64_t value);

    static const char kImportTypeName[];
    static constexpr uint64_t kImportTypeNameHash = UINT64_C(9519193812938855147);
    Autofill2_AddressProfileImport& SetImportType(int64_t value);

    static const char kNumberOfEditedFieldsName[];
    static constexpr uint64_t kNumberOfEditedFieldsNameHash = UINT64_C(5450890206523572358);
    Autofill2_AddressProfileImport& SetNumberOfEditedFields(int64_t value);

    static const char kPhoneNumberStatusName[];
    static constexpr uint64_t kPhoneNumberStatusNameHash = UINT64_C(8983032179867015745);
    Autofill2_AddressProfileImport& SetPhoneNumberStatus(int64_t value);

    static const char kUserDecisionName[];
    static constexpr uint64_t kUserDecisionNameHash = UINT64_C(17869783508834948077);
    Autofill2_AddressProfileImport& SetUserDecision(int64_t value);

    static const char kUserHasExistingProfileName[];
    static constexpr uint64_t kUserHasExistingProfileNameHash = UINT64_C(4557882932054074061);
    Autofill2_AddressProfileImport& SetUserHasExistingProfile(int64_t value);
};

class Autofill2_FieldInfo final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill2_FieldInfo(ukm::SourceId source_id);
    explicit Autofill2_FieldInfo(ukm::SourceIdObj source_id);
    Autofill2_FieldInfo(Autofill2_FieldInfo&&);
    Autofill2_FieldInfo& operator=(Autofill2_FieldInfo&&);
    ~Autofill2_FieldInfo() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11766777789942094039);

    static const char kAutocompleteStateName[];
    static constexpr uint64_t kAutocompleteStateNameHash = UINT64_C(6432297826528058932);
    Autofill2_FieldInfo& SetAutocompleteState(int64_t value);

    static const char kAutofillSkippedStatusName[];
    static constexpr uint64_t kAutofillSkippedStatusNameHash = UINT64_C(14782038142865374992);
    Autofill2_FieldInfo& SetAutofillSkippedStatus(int64_t value);

    static const char kAutofillStatusVectorName[];
    static constexpr uint64_t kAutofillStatusVectorNameHash = UINT64_C(18187767980256995778);
    Autofill2_FieldInfo& SetAutofillStatusVector(int64_t value);

    static const char kFieldLogEventCountName[];
    static constexpr uint64_t kFieldLogEventCountNameHash = UINT64_C(9517498293485487802);
    Autofill2_FieldInfo& SetFieldLogEventCount(int64_t value);

    static const char kFieldSessionIdentifierName[];
    static constexpr uint64_t kFieldSessionIdentifierNameHash = UINT64_C(5116166075644172513);
    Autofill2_FieldInfo& SetFieldSessionIdentifier(int64_t value);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Autofill2_FieldInfo& SetFieldSignature(int64_t value);

    static const char kFormControlType2Name[];
    static constexpr uint64_t kFormControlType2NameHash = UINT64_C(7866066429830044389);
    Autofill2_FieldInfo& SetFormControlType2(int64_t value);

    static const char kFormSessionIdentifierName[];
    static constexpr uint64_t kFormSessionIdentifierNameHash = UINT64_C(15947627667954168598);
    Autofill2_FieldInfo& SetFormSessionIdentifier(int64_t value);

    static const char kHeuristicTypeName[];
    static constexpr uint64_t kHeuristicTypeNameHash = UINT64_C(17234680850427059129);
    Autofill2_FieldInfo& SetHeuristicType(int64_t value);

    static const char kHeuristicTypeDefaultName[];
    static constexpr uint64_t kHeuristicTypeDefaultNameHash = UINT64_C(13642892897949013046);
    Autofill2_FieldInfo& SetHeuristicTypeDefault(int64_t value);

    static const char kHeuristicTypeExperimentalName[];
    static constexpr uint64_t kHeuristicTypeExperimentalNameHash = UINT64_C(3157630532593044730);
    Autofill2_FieldInfo& SetHeuristicTypeExperimental(int64_t value);

    static const char kHeuristicTypeLegacyName[];
    static constexpr uint64_t kHeuristicTypeLegacyNameHash = UINT64_C(4154732131450263162);
    Autofill2_FieldInfo& SetHeuristicTypeLegacy(int64_t value);

    static const char kHtmlFieldModeName[];
    static constexpr uint64_t kHtmlFieldModeNameHash = UINT64_C(15151906885863383301);
    Autofill2_FieldInfo& SetHtmlFieldMode(int64_t value);

    static const char kHtmlFieldTypeName[];
    static constexpr uint64_t kHtmlFieldTypeNameHash = UINT64_C(13021611540219886097);
    Autofill2_FieldInfo& SetHtmlFieldType(int64_t value);

    static const char kOverallTypeName[];
    static constexpr uint64_t kOverallTypeNameHash = UINT64_C(16896259778850698076);
    Autofill2_FieldInfo& SetOverallType(int64_t value);

    static const char kRankInFieldSignatureGroupName[];
    static constexpr uint64_t kRankInFieldSignatureGroupNameHash = UINT64_C(7046669571938819124);
    Autofill2_FieldInfo& SetRankInFieldSignatureGroup(int64_t value);

    static const char kSectionIdName[];
    static constexpr uint64_t kSectionIdNameHash = UINT64_C(8131305116042545748);
    Autofill2_FieldInfo& SetSectionId(int64_t value);

    static const char kServerPredictionSource1Name[];
    static constexpr uint64_t kServerPredictionSource1NameHash = UINT64_C(17114353997717664197);
    Autofill2_FieldInfo& SetServerPredictionSource1(int64_t value);

    static const char kServerPredictionSource2Name[];
    static constexpr uint64_t kServerPredictionSource2NameHash = UINT64_C(15544786525374376045);
    Autofill2_FieldInfo& SetServerPredictionSource2(int64_t value);

    static const char kServerType1Name[];
    static constexpr uint64_t kServerType1NameHash = UINT64_C(17554894306353601590);
    Autofill2_FieldInfo& SetServerType1(int64_t value);

    static const char kServerType2Name[];
    static constexpr uint64_t kServerType2NameHash = UINT64_C(12121820838700529954);
    Autofill2_FieldInfo& SetServerType2(int64_t value);

    static const char kServerTypeIsOverrideName[];
    static constexpr uint64_t kServerTypeIsOverrideNameHash = UINT64_C(815444672996087578);
    Autofill2_FieldInfo& SetServerTypeIsOverride(int64_t value);

    static const char kTypeChangedByRationalizationName[];
    static constexpr uint64_t kTypeChangedByRationalizationNameHash = UINT64_C(14228417019572300322);
    Autofill2_FieldInfo& SetTypeChangedByRationalization(int64_t value);
};

class Autofill2_FieldInfoAfterSubmission final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill2_FieldInfoAfterSubmission(ukm::SourceId source_id);
    explicit Autofill2_FieldInfoAfterSubmission(ukm::SourceIdObj source_id);
    Autofill2_FieldInfoAfterSubmission(Autofill2_FieldInfoAfterSubmission&&);
    Autofill2_FieldInfoAfterSubmission& operator=(Autofill2_FieldInfoAfterSubmission&&);
    ~Autofill2_FieldInfoAfterSubmission() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12003710184381511525);

    static const char kFieldSessionIdentifierName[];
    static constexpr uint64_t kFieldSessionIdentifierNameHash = UINT64_C(5116166075644172513);
    Autofill2_FieldInfoAfterSubmission& SetFieldSessionIdentifier(int64_t value);

    static const char kFormSessionIdentifierName[];
    static constexpr uint64_t kFormSessionIdentifierNameHash = UINT64_C(15947627667954168598);
    Autofill2_FieldInfoAfterSubmission& SetFormSessionIdentifier(int64_t value);

    static const char kMillisecondsFromFormParsedUntilSubmissionName[];
    static constexpr uint64_t kMillisecondsFromFormParsedUntilSubmissionNameHash = UINT64_C(1977804889512907849);
    Autofill2_FieldInfoAfterSubmission& SetMillisecondsFromFormParsedUntilSubmission(int64_t value);

    static const char kSubmissionSourceName[];
    static constexpr uint64_t kSubmissionSourceNameHash = UINT64_C(2801602890901618022);
    Autofill2_FieldInfoAfterSubmission& SetSubmissionSource(int64_t value);

    static const char kSubmittedType1Name[];
    static constexpr uint64_t kSubmittedType1NameHash = UINT64_C(13159891703995784970);
    Autofill2_FieldInfoAfterSubmission& SetSubmittedType1(int64_t value);

    static const char kSubmittedType2Name[];
    static constexpr uint64_t kSubmittedType2NameHash = UINT64_C(930242577204265686);
    Autofill2_FieldInfoAfterSubmission& SetSubmittedType2(int64_t value);

    static const char kSubmittedType3Name[];
    static constexpr uint64_t kSubmittedType3NameHash = UINT64_C(17123877752771617738);
    Autofill2_FieldInfoAfterSubmission& SetSubmittedType3(int64_t value);
};

class Autofill2_FocusedComplexForm final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill2_FocusedComplexForm(ukm::SourceId source_id);
    explicit Autofill2_FocusedComplexForm(ukm::SourceIdObj source_id);
    Autofill2_FocusedComplexForm(Autofill2_FocusedComplexForm&&);
    Autofill2_FocusedComplexForm& operator=(Autofill2_FocusedComplexForm&&);
    ~Autofill2_FocusedComplexForm() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12057470962363748081);

    static const char kAutofillDataQueriedName[];
    static constexpr uint64_t kAutofillDataQueriedNameHash = UINT64_C(9295348965112185494);
    Autofill2_FocusedComplexForm& SetAutofillDataQueried(int64_t value);

    static const char kAutofilledName[];
    static constexpr uint64_t kAutofilledNameHash = UINT64_C(10418039777414012731);
    Autofill2_FocusedComplexForm& SetAutofilled(int64_t value);

    static const char kDayInAblationWindowName[];
    static constexpr uint64_t kDayInAblationWindowNameHash = UINT64_C(8039866577837580628);
    Autofill2_FocusedComplexForm& SetDayInAblationWindow(int64_t value);

    static const char kEditedAfterAutofillName[];
    static constexpr uint64_t kEditedAfterAutofillNameHash = UINT64_C(1822112092870689070);
    Autofill2_FocusedComplexForm& SetEditedAfterAutofill(int64_t value);

    static const char kFormSessionIdentifierName[];
    static constexpr uint64_t kFormSessionIdentifierNameHash = UINT64_C(15947627667954168598);
    Autofill2_FocusedComplexForm& SetFormSessionIdentifier(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill2_FocusedComplexForm& SetFormSignature(int64_t value);

    static const char kFormTypesName[];
    static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
    Autofill2_FocusedComplexForm& SetFormTypes(int64_t value);

    static const char kHadNonEmptyValueAtSubmissionName[];
    static constexpr uint64_t kHadNonEmptyValueAtSubmissionNameHash = UINT64_C(14690467002329902645);
    Autofill2_FocusedComplexForm& SetHadNonEmptyValueAtSubmission(int64_t value);

    static const char kIsAblationStudyInDryRunModeName[];
    static constexpr uint64_t kIsAblationStudyInDryRunModeNameHash = UINT64_C(4964187404226389898);
    Autofill2_FocusedComplexForm& SetIsAblationStudyInDryRunMode(int64_t value);

    static const char kIsInAblationGroupOfAblationName[];
    static constexpr uint64_t kIsInAblationGroupOfAblationNameHash = UINT64_C(16099349896011211113);
    Autofill2_FocusedComplexForm& SetIsInAblationGroupOfAblation(int64_t value);

    static const char kIsInAblationGroupOfConditionalAblationName[];
    static constexpr uint64_t kIsInAblationGroupOfConditionalAblationNameHash = UINT64_C(11016078837963025041);
    Autofill2_FocusedComplexForm& SetIsInAblationGroupOfConditionalAblation(int64_t value);

    static const char kIsInControlGroupOfAblationName[];
    static constexpr uint64_t kIsInControlGroupOfAblationNameHash = UINT64_C(3595561198432771041);
    Autofill2_FocusedComplexForm& SetIsInControlGroupOfAblation(int64_t value);

    static const char kIsInControlGroupOfConditionalAblationName[];
    static constexpr uint64_t kIsInControlGroupOfConditionalAblationNameHash = UINT64_C(6529480504436014266);
    Autofill2_FocusedComplexForm& SetIsInControlGroupOfConditionalAblation(int64_t value);

    static const char kMillisecondsFromFirstInteractionUntilSubmissionName[];
    static constexpr uint64_t kMillisecondsFromFirstInteractionUntilSubmissionNameHash = UINT64_C(2769756386259972465);
    Autofill2_FocusedComplexForm& SetMillisecondsFromFirstInteractionUntilSubmission(int64_t value);

    static const char kSuggestionsAvailableName[];
    static constexpr uint64_t kSuggestionsAvailableNameHash = UINT64_C(7875108368966614266);
    Autofill2_FocusedComplexForm& SetSuggestionsAvailable(int64_t value);

    static const char kUserModifiedName[];
    static constexpr uint64_t kUserModifiedNameHash = UINT64_C(13633085933441592014);
    Autofill2_FocusedComplexForm& SetUserModified(int64_t value);

    static const char kWasSubmittedName[];
    static constexpr uint64_t kWasSubmittedNameHash = UINT64_C(15177417090599472376);
    Autofill2_FocusedComplexForm& SetWasSubmitted(int64_t value);
};

class Autofill2_FormSummary final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill2_FormSummary(ukm::SourceId source_id);
    explicit Autofill2_FormSummary(ukm::SourceIdObj source_id);
    Autofill2_FormSummary(Autofill2_FormSummary&&);
    Autofill2_FormSummary& operator=(Autofill2_FormSummary&&);
    ~Autofill2_FormSummary() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8716111882571667287);

    static const char kAutofillFormEventsName[];
    static constexpr uint64_t kAutofillFormEventsNameHash = UINT64_C(12713966857930846209);
    Autofill2_FormSummary& SetAutofillFormEvents(int64_t value);

    static const char kAutofillFormEvents2Name[];
    static constexpr uint64_t kAutofillFormEvents2NameHash = UINT64_C(11123247277761517558);
    Autofill2_FormSummary& SetAutofillFormEvents2(int64_t value);

    static const char kFormSessionIdentifierName[];
    static constexpr uint64_t kFormSessionIdentifierNameHash = UINT64_C(15947627667954168598);
    Autofill2_FormSummary& SetFormSessionIdentifier(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill2_FormSummary& SetFormSignature(int64_t value);

    static const char kMillisecondsFromFirstInteratctionUntilSubmissionName[];
    static constexpr uint64_t kMillisecondsFromFirstInteratctionUntilSubmissionNameHash = UINT64_C(17775330976042215228);
    Autofill2_FormSummary& SetMillisecondsFromFirstInteratctionUntilSubmission(int64_t value);

    static const char kMillisecondsFromFormParsedUntilSubmissionName[];
    static constexpr uint64_t kMillisecondsFromFormParsedUntilSubmissionNameHash = UINT64_C(1977804889512907849);
    Autofill2_FormSummary& SetMillisecondsFromFormParsedUntilSubmission(int64_t value);

    static const char kSampleRateName[];
    static constexpr uint64_t kSampleRateNameHash = UINT64_C(13310874092316950528);
    Autofill2_FormSummary& SetSampleRate(int64_t value);

    static const char kWasSubmittedName[];
    static constexpr uint64_t kWasSubmittedNameHash = UINT64_C(15177417090599472376);
    Autofill2_FormSummary& SetWasSubmitted(int64_t value);
};

class Autofill2_SubmittedFormWithExperimentalFields final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Autofill2_SubmittedFormWithExperimentalFields(ukm::SourceId source_id);
    explicit Autofill2_SubmittedFormWithExperimentalFields(ukm::SourceIdObj source_id);
    Autofill2_SubmittedFormWithExperimentalFields(Autofill2_SubmittedFormWithExperimentalFields&&);
    Autofill2_SubmittedFormWithExperimentalFields& operator=(Autofill2_SubmittedFormWithExperimentalFields&&);
    ~Autofill2_SubmittedFormWithExperimentalFields() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(92926512322107493);

    static const char kFormSessionIdentifierName[];
    static constexpr uint64_t kFormSessionIdentifierNameHash = UINT64_C(15947627667954168598);
    Autofill2_SubmittedFormWithExperimentalFields& SetFormSessionIdentifier(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Autofill2_SubmittedFormWithExperimentalFields& SetFormSignature(int64_t value);

    static const char kNumberOfNonEmptyExperimentalFields0Name[];
    static constexpr uint64_t kNumberOfNonEmptyExperimentalFields0NameHash = UINT64_C(8036370710711206972);
    Autofill2_SubmittedFormWithExperimentalFields& SetNumberOfNonEmptyExperimentalFields0(int64_t value);

    static const char kNumberOfNonEmptyExperimentalFields1Name[];
    static constexpr uint64_t kNumberOfNonEmptyExperimentalFields1NameHash = UINT64_C(15429586979170962996);
    Autofill2_SubmittedFormWithExperimentalFields& SetNumberOfNonEmptyExperimentalFields1(int64_t value);

    static const char kNumberOfNonEmptyExperimentalFields2Name[];
    static constexpr uint64_t kNumberOfNonEmptyExperimentalFields2NameHash = UINT64_C(5173370459753379232);
    Autofill2_SubmittedFormWithExperimentalFields& SetNumberOfNonEmptyExperimentalFields2(int64_t value);

    static const char kNumberOfNonEmptyExperimentalFields3Name[];
    static constexpr uint64_t kNumberOfNonEmptyExperimentalFields3NameHash = UINT64_C(17769805557380694682);
    Autofill2_SubmittedFormWithExperimentalFields& SetNumberOfNonEmptyExperimentalFields3(int64_t value);

    static const char kNumberOfNonEmptyExperimentalFields4Name[];
    static constexpr uint64_t kNumberOfNonEmptyExperimentalFields4NameHash = UINT64_C(527416700270514121);
    Autofill2_SubmittedFormWithExperimentalFields& SetNumberOfNonEmptyExperimentalFields4(int64_t value);
};

class BackForwardCacheDisabledForRenderFrameHostReason final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BackForwardCacheDisabledForRenderFrameHostReason(ukm::SourceId source_id);
    explicit BackForwardCacheDisabledForRenderFrameHostReason(ukm::SourceIdObj source_id);
    BackForwardCacheDisabledForRenderFrameHostReason(BackForwardCacheDisabledForRenderFrameHostReason&&);
    BackForwardCacheDisabledForRenderFrameHostReason& operator=(BackForwardCacheDisabledForRenderFrameHostReason&&);
    ~BackForwardCacheDisabledForRenderFrameHostReason() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2667461721042691467);

    static const char kReason2Name[];
    static constexpr uint64_t kReason2NameHash = UINT64_C(13288760560789121403);
    BackForwardCacheDisabledForRenderFrameHostReason& SetReason2(int64_t value);
};

class BackForwardCacheDisallowActivationReason final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BackForwardCacheDisallowActivationReason(ukm::SourceId source_id);
    explicit BackForwardCacheDisallowActivationReason(ukm::SourceIdObj source_id);
    BackForwardCacheDisallowActivationReason(BackForwardCacheDisallowActivationReason&&);
    BackForwardCacheDisallowActivationReason& operator=(BackForwardCacheDisallowActivationReason&&);
    ~BackForwardCacheDisallowActivationReason() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17791611243479825042);

    static const char kReasonName[];
    static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
    BackForwardCacheDisallowActivationReason& SetReason(int64_t value);
};

class BackgroundFetch final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BackgroundFetch(ukm::SourceId source_id);
    explicit BackgroundFetch(ukm::SourceIdObj source_id);
    BackgroundFetch(BackgroundFetch&&);
    BackgroundFetch& operator=(BackgroundFetch&&);
    ~BackgroundFetch() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15260645490069405494);

    static const char kDeniedDueToPermissionsName[];
    static constexpr uint64_t kDeniedDueToPermissionsNameHash = UINT64_C(2758060228952433941);
    BackgroundFetch& SetDeniedDueToPermissions(int64_t value);

    static const char kDownloadTotalName[];
    static constexpr uint64_t kDownloadTotalNameHash = UINT64_C(8410270676684853040);
    BackgroundFetch& SetDownloadTotal(int64_t value);

    static const char kHasTitleName[];
    static constexpr uint64_t kHasTitleNameHash = UINT64_C(16464620929402588538);
    BackgroundFetch& SetHasTitle(int64_t value);

    static const char kNumIconsName[];
    static constexpr uint64_t kNumIconsNameHash = UINT64_C(12708022996225087379);
    BackgroundFetch& SetNumIcons(int64_t value);

    static const char kNumRequestsInFetchName[];
    static constexpr uint64_t kNumRequestsInFetchNameHash = UINT64_C(15496480607003620043);
    BackgroundFetch& SetNumRequestsInFetch(int64_t value);

    static const char kRatioOfIdealToChosenIconSizeName[];
    static constexpr uint64_t kRatioOfIdealToChosenIconSizeNameHash = UINT64_C(18158828977194098243);
    BackgroundFetch& SetRatioOfIdealToChosenIconSize(int64_t value);
};

class BackgroundFetchDeletingRegistration final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BackgroundFetchDeletingRegistration(ukm::SourceId source_id);
    explicit BackgroundFetchDeletingRegistration(ukm::SourceIdObj source_id);
    BackgroundFetchDeletingRegistration(BackgroundFetchDeletingRegistration&&);
    BackgroundFetchDeletingRegistration& operator=(BackgroundFetchDeletingRegistration&&);
    ~BackgroundFetchDeletingRegistration() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2765600174500981245);

    static const char kUserInitiatedAbortName[];
    static constexpr uint64_t kUserInitiatedAbortNameHash = UINT64_C(2365076081250918859);
    BackgroundFetchDeletingRegistration& SetUserInitiatedAbort(int64_t value);
};

class BackgroundSyncCompleted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BackgroundSyncCompleted(ukm::SourceId source_id);
    explicit BackgroundSyncCompleted(ukm::SourceIdObj source_id);
    BackgroundSyncCompleted(BackgroundSyncCompleted&&);
    BackgroundSyncCompleted& operator=(BackgroundSyncCompleted&&);
    ~BackgroundSyncCompleted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7109245137155486527);

    static const char kMaxAttemptsName[];
    static constexpr uint64_t kMaxAttemptsNameHash = UINT64_C(13811216186026220346);
    BackgroundSyncCompleted& SetMaxAttempts(int64_t value);

    static const char kNumAttemptsName[];
    static constexpr uint64_t kNumAttemptsNameHash = UINT64_C(537979731801272247);
    BackgroundSyncCompleted& SetNumAttempts(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    BackgroundSyncCompleted& SetStatus(int64_t value);
};

class BackgroundSyncRegistered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BackgroundSyncRegistered(ukm::SourceId source_id);
    explicit BackgroundSyncRegistered(ukm::SourceIdObj source_id);
    BackgroundSyncRegistered(BackgroundSyncRegistered&&);
    BackgroundSyncRegistered& operator=(BackgroundSyncRegistered&&);
    ~BackgroundSyncRegistered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3511425855963568724);

    static const char kCanFireName[];
    static constexpr uint64_t kCanFireNameHash = UINT64_C(14458670990807174531);
    BackgroundSyncRegistered& SetCanFire(int64_t value);

    static const char kIsReregisteredName[];
    static constexpr uint64_t kIsReregisteredNameHash = UINT64_C(10082741689941820461);
    BackgroundSyncRegistered& SetIsReregistered(int64_t value);
};

class Badging final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Badging(ukm::SourceId source_id);
    explicit Badging(ukm::SourceIdObj source_id);
    Badging(Badging&&);
    Badging& operator=(Badging&&);
    ~Badging() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12678664205992465342);

    static const char kUpdateAppBadgeName[];
    static constexpr uint64_t kUpdateAppBadgeNameHash = UINT64_C(5657178876164813495);
    Badging& SetUpdateAppBadge(int64_t value);
};

class Blink_ContentManagementSystem_Versions final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_ContentManagementSystem_Versions(ukm::SourceId source_id);
    explicit Blink_ContentManagementSystem_Versions(ukm::SourceIdObj source_id);
    Blink_ContentManagementSystem_Versions(Blink_ContentManagementSystem_Versions&&);
    Blink_ContentManagementSystem_Versions& operator=(Blink_ContentManagementSystem_Versions&&);
    ~Blink_ContentManagementSystem_Versions() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9941089978170015081);

    static const char kDrupalVersionName[];
    static constexpr uint64_t kDrupalVersionNameHash = UINT64_C(6771249113226323336);
    Blink_ContentManagementSystem_Versions& SetDrupalVersion(int64_t value);

    static const char kWordPressVersionName[];
    static constexpr uint64_t kWordPressVersionNameHash = UINT64_C(1738817915095640047);
    Blink_ContentManagementSystem_Versions& SetWordPressVersion(int64_t value);
};

class Blink_DeveloperMetricsRare final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_DeveloperMetricsRare(ukm::SourceId source_id);
    explicit Blink_DeveloperMetricsRare(ukm::SourceIdObj source_id);
    Blink_DeveloperMetricsRare(Blink_DeveloperMetricsRare&&);
    Blink_DeveloperMetricsRare& operator=(Blink_DeveloperMetricsRare&&);
    ~Blink_DeveloperMetricsRare() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17402744508281089121);

    static const char kFeatureName[];
    static constexpr uint64_t kFeatureNameHash = UINT64_C(2378497229593503977);
    Blink_DeveloperMetricsRare& SetFeature(int64_t value);

    static const char kIsMainFrameFeatureName[];
    static constexpr uint64_t kIsMainFrameFeatureNameHash = UINT64_C(8112503265735119902);
    Blink_DeveloperMetricsRare& SetIsMainFrameFeature(int64_t value);
};

class Blink_FedCm final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_FedCm(ukm::SourceId source_id);
    explicit Blink_FedCm(ukm::SourceIdObj source_id);
    Blink_FedCm(Blink_FedCm&&);
    Blink_FedCm& operator=(Blink_FedCm&&);
    ~Blink_FedCm() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6601472140741101491);

    static const char kAccountLabel_NumMatchingAccountsName[];
    static constexpr uint64_t kAccountLabel_NumMatchingAccountsNameHash = UINT64_C(14439608325916722985);
    Blink_FedCm& SetAccountLabel_NumMatchingAccounts(int64_t value);

    static const char kAccountsDialogShownName[];
    static constexpr uint64_t kAccountsDialogShownNameHash = UINT64_C(15948983178878538292);
    Blink_FedCm& SetAccountsDialogShown(int64_t value);

    static const char kAccountsRequestSentName[];
    static constexpr uint64_t kAccountsRequestSentNameHash = UINT64_C(2581000771776085137);
    Blink_FedCm& SetAccountsRequestSent(int64_t value);

    static const char kAutoReauthn_BlockedByContentSettingsName[];
    static constexpr uint64_t kAutoReauthn_BlockedByContentSettingsNameHash = UINT64_C(4802018292911474140);
    Blink_FedCm& SetAutoReauthn_BlockedByContentSettings(int64_t value);

    static const char kAutoReauthn_BlockedByEmbargoName[];
    static constexpr uint64_t kAutoReauthn_BlockedByEmbargoNameHash = UINT64_C(12833734315413668996);
    Blink_FedCm& SetAutoReauthn_BlockedByEmbargo(int64_t value);

    static const char kAutoReauthn_BlockedByPreventSilentAccessName[];
    static constexpr uint64_t kAutoReauthn_BlockedByPreventSilentAccessNameHash = UINT64_C(10517550635190593606);
    Blink_FedCm& SetAutoReauthn_BlockedByPreventSilentAccess(int64_t value);

    static const char kAutoReauthn_ReturningAccountsName[];
    static constexpr uint64_t kAutoReauthn_ReturningAccountsNameHash = UINT64_C(7238970971318975274);
    Blink_FedCm& SetAutoReauthn_ReturningAccounts(int64_t value);

    static const char kAutoReauthn_SucceededName[];
    static constexpr uint64_t kAutoReauthn_SucceededNameHash = UINT64_C(2092381572879261609);
    Blink_FedCm& SetAutoReauthn_Succeeded(int64_t value);

    static const char kAutoReauthn_TimeFromEmbargoWhenBlockedName[];
    static constexpr uint64_t kAutoReauthn_TimeFromEmbargoWhenBlockedNameHash = UINT64_C(15395647531418374864);
    Blink_FedCm& SetAutoReauthn_TimeFromEmbargoWhenBlocked(int64_t value);

    static const char kDisconnect_FrameTypeName[];
    static constexpr uint64_t kDisconnect_FrameTypeNameHash = UINT64_C(4726648256216116531);
    Blink_FedCm& SetDisconnect_FrameType(int64_t value);

    static const char kDomainHint_NumMatchingAccountsName[];
    static constexpr uint64_t kDomainHint_NumMatchingAccountsNameHash = UINT64_C(16710282080090409549);
    Blink_FedCm& SetDomainHint_NumMatchingAccounts(int64_t value);

    static const char kError_ErrorDialogResultName[];
    static constexpr uint64_t kError_ErrorDialogResultNameHash = UINT64_C(17866892561642102086);
    Blink_FedCm& SetError_ErrorDialogResult(int64_t value);

    static const char kError_ErrorDialogTypeName[];
    static constexpr uint64_t kError_ErrorDialogTypeNameHash = UINT64_C(13354982294660434187);
    Blink_FedCm& SetError_ErrorDialogType(int64_t value);

    static const char kError_TokenResponseTypeName[];
    static constexpr uint64_t kError_TokenResponseTypeNameHash = UINT64_C(14820302367530254781);
    Blink_FedCm& SetError_TokenResponseType(int64_t value);

    static const char kFedCmSessionIDName[];
    static constexpr uint64_t kFedCmSessionIDNameHash = UINT64_C(3354861899115709952);
    Blink_FedCm& SetFedCmSessionID(int64_t value);

    static const char kLoginHint_NumMatchingAccountsName[];
    static constexpr uint64_t kLoginHint_NumMatchingAccountsNameHash = UINT64_C(8824068587370372451);
    Blink_FedCm& SetLoginHint_NumMatchingAccounts(int64_t value);

    static const char kMismatchDialogShownName[];
    static constexpr uint64_t kMismatchDialogShownNameHash = UINT64_C(11485520766596316230);
    Blink_FedCm& SetMismatchDialogShown(int64_t value);

    static const char kMultipleRequestsRpModeName[];
    static constexpr uint64_t kMultipleRequestsRpModeNameHash = UINT64_C(12819267039583227210);
    Blink_FedCm& SetMultipleRequestsRpMode(int64_t value);

    static const char kNumIdpsMismatchName[];
    static constexpr uint64_t kNumIdpsMismatchNameHash = UINT64_C(15270635863189681416);
    Blink_FedCm& SetNumIdpsMismatch(int64_t value);

    static const char kNumIdpsRequestedName[];
    static constexpr uint64_t kNumIdpsRequestedNameHash = UINT64_C(9196491132780798395);
    Blink_FedCm& SetNumIdpsRequested(int64_t value);

    static const char kNumRequestsPerDocumentName[];
    static constexpr uint64_t kNumRequestsPerDocumentNameHash = UINT64_C(12728268635726573281);
    Blink_FedCm& SetNumRequestsPerDocument(int64_t value);

    static const char kPreventSilentAccessFrameTypeName[];
    static constexpr uint64_t kPreventSilentAccessFrameTypeNameHash = UINT64_C(12502871285731002683);
    Blink_FedCm& SetPreventSilentAccessFrameType(int64_t value);

    static const char kRpModeName[];
    static constexpr uint64_t kRpModeNameHash = UINT64_C(18215191285408856526);
    Blink_FedCm& SetRpMode(int64_t value);

    static const char kStatus_DisconnectName[];
    static constexpr uint64_t kStatus_DisconnectNameHash = UINT64_C(5102944309342693036);
    Blink_FedCm& SetStatus_Disconnect(int64_t value);

    static const char kStatus_MediationRequirementName[];
    static constexpr uint64_t kStatus_MediationRequirementNameHash = UINT64_C(7341985771654146448);
    Blink_FedCm& SetStatus_MediationRequirement(int64_t value);

    static const char kStatus_RequestIdTokenName[];
    static constexpr uint64_t kStatus_RequestIdTokenNameHash = UINT64_C(17280553313027361120);
    Blink_FedCm& SetStatus_RequestIdToken(int64_t value);

    static const char kStatus_SignInStateMatchName[];
    static constexpr uint64_t kStatus_SignInStateMatchNameHash = UINT64_C(15085451675015980083);
    Blink_FedCm& SetStatus_SignInStateMatch(int64_t value);

    static const char kTiming_AccountsDialogShownDurationName[];
    static constexpr uint64_t kTiming_AccountsDialogShownDurationNameHash = UINT64_C(11571078471586947859);
    Blink_FedCm& SetTiming_AccountsDialogShownDuration(int64_t value);

    static const char kTiming_CancelOnDialogName[];
    static constexpr uint64_t kTiming_CancelOnDialogNameHash = UINT64_C(3760049210363712305);
    Blink_FedCm& SetTiming_CancelOnDialog(int64_t value);

    static const char kTiming_ContinueOnDialogName[];
    static constexpr uint64_t kTiming_ContinueOnDialogNameHash = UINT64_C(5658920916221960950);
    Blink_FedCm& SetTiming_ContinueOnDialog(int64_t value);

    static const char kTiming_DisconnectName[];
    static constexpr uint64_t kTiming_DisconnectNameHash = UINT64_C(16164962436490374623);
    Blink_FedCm& SetTiming_Disconnect(int64_t value);

    static const char kTiming_GetUserInfoToButtonModeName[];
    static constexpr uint64_t kTiming_GetUserInfoToButtonModeNameHash = UINT64_C(12594881550517587662);
    Blink_FedCm& SetTiming_GetUserInfoToButtonMode(int64_t value);

    static const char kTiming_IdTokenResponseName[];
    static constexpr uint64_t kTiming_IdTokenResponseNameHash = UINT64_C(9815123395675115620);
    Blink_FedCm& SetTiming_IdTokenResponse(int64_t value);

    static const char kTiming_MismatchDialogShownDurationName[];
    static constexpr uint64_t kTiming_MismatchDialogShownDurationNameHash = UINT64_C(17261962705556864073);
    Blink_FedCm& SetTiming_MismatchDialogShownDuration(int64_t value);

    static const char kTiming_ShowAccountsDialogName[];
    static constexpr uint64_t kTiming_ShowAccountsDialogNameHash = UINT64_C(6586192106353245718);
    Blink_FedCm& SetTiming_ShowAccountsDialog(int64_t value);

    static const char kTiming_ShowAccountsDialogBreakdown_AccountsFetchName[];
    static constexpr uint64_t kTiming_ShowAccountsDialogBreakdown_AccountsFetchNameHash = UINT64_C(14538315915241873642);
    Blink_FedCm& SetTiming_ShowAccountsDialogBreakdown_AccountsFetch(int64_t value);

    static const char kTiming_ShowAccountsDialogBreakdown_ClientMetadataFetchName[];
    static constexpr uint64_t kTiming_ShowAccountsDialogBreakdown_ClientMetadataFetchNameHash = UINT64_C(8663363393863804298);
    Blink_FedCm& SetTiming_ShowAccountsDialogBreakdown_ClientMetadataFetch(int64_t value);

    static const char kTiming_ShowAccountsDialogBreakdown_WellKnownAndConfigFetchName[];
    static constexpr uint64_t kTiming_ShowAccountsDialogBreakdown_WellKnownAndConfigFetchNameHash = UINT64_C(509810056233166862);
    Blink_FedCm& SetTiming_ShowAccountsDialogBreakdown_WellKnownAndConfigFetch(int64_t value);

    static const char kTiming_TurnaroundTimeName[];
    static constexpr uint64_t kTiming_TurnaroundTimeNameHash = UINT64_C(964934984140136051);
    Blink_FedCm& SetTiming_TurnaroundTime(int64_t value);
};

class Blink_FedCmIdp final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_FedCmIdp(ukm::SourceId source_id);
    explicit Blink_FedCmIdp(ukm::SourceIdObj source_id);
    Blink_FedCmIdp(Blink_FedCmIdp&&);
    Blink_FedCmIdp& operator=(Blink_FedCmIdp&&);
    ~Blink_FedCmIdp() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14393930834880879921);

    static const char kAccountsDialogShownName[];
    static constexpr uint64_t kAccountsDialogShownNameHash = UINT64_C(15948983178878538292);
    Blink_FedCmIdp& SetAccountsDialogShown(int64_t value);

    static const char kAccountsRequestSentName[];
    static constexpr uint64_t kAccountsRequestSentNameHash = UINT64_C(2581000771776085137);
    Blink_FedCmIdp& SetAccountsRequestSent(int64_t value);

    static const char kDisconnect_FrameTypeName[];
    static constexpr uint64_t kDisconnect_FrameTypeNameHash = UINT64_C(4726648256216116531);
    Blink_FedCmIdp& SetDisconnect_FrameType(int64_t value);

    static const char kError_ErrorDialogResultName[];
    static constexpr uint64_t kError_ErrorDialogResultNameHash = UINT64_C(17866892561642102086);
    Blink_FedCmIdp& SetError_ErrorDialogResult(int64_t value);

    static const char kError_ErrorDialogTypeName[];
    static constexpr uint64_t kError_ErrorDialogTypeNameHash = UINT64_C(13354982294660434187);
    Blink_FedCmIdp& SetError_ErrorDialogType(int64_t value);

    static const char kError_ErrorUrlTypeName[];
    static constexpr uint64_t kError_ErrorUrlTypeNameHash = UINT64_C(5492577319982193117);
    Blink_FedCmIdp& SetError_ErrorUrlType(int64_t value);

    static const char kError_TokenResponseTypeName[];
    static constexpr uint64_t kError_TokenResponseTypeNameHash = UINT64_C(14820302367530254781);
    Blink_FedCmIdp& SetError_TokenResponseType(int64_t value);

    static const char kFedCmSessionIDName[];
    static constexpr uint64_t kFedCmSessionIDNameHash = UINT64_C(3354861899115709952);
    Blink_FedCmIdp& SetFedCmSessionID(int64_t value);

    static const char kMismatchDialogShownName[];
    static constexpr uint64_t kMismatchDialogShownNameHash = UINT64_C(11485520766596316230);
    Blink_FedCmIdp& SetMismatchDialogShown(int64_t value);

    static const char kMultipleRequestsRpModeName[];
    static constexpr uint64_t kMultipleRequestsRpModeNameHash = UINT64_C(12819267039583227210);
    Blink_FedCmIdp& SetMultipleRequestsRpMode(int64_t value);

    static const char kNumIdpsMismatchName[];
    static constexpr uint64_t kNumIdpsMismatchNameHash = UINT64_C(15270635863189681416);
    Blink_FedCmIdp& SetNumIdpsMismatch(int64_t value);

    static const char kNumIdpsRequestedName[];
    static constexpr uint64_t kNumIdpsRequestedNameHash = UINT64_C(9196491132780798395);
    Blink_FedCmIdp& SetNumIdpsRequested(int64_t value);

    static const char kRpModeName[];
    static constexpr uint64_t kRpModeNameHash = UINT64_C(18215191285408856526);
    Blink_FedCmIdp& SetRpMode(int64_t value);

    static const char kStatus_DisconnectName[];
    static constexpr uint64_t kStatus_DisconnectNameHash = UINT64_C(5102944309342693036);
    Blink_FedCmIdp& SetStatus_Disconnect(int64_t value);

    static const char kStatus_MediationRequirementName[];
    static constexpr uint64_t kStatus_MediationRequirementNameHash = UINT64_C(7341985771654146448);
    Blink_FedCmIdp& SetStatus_MediationRequirement(int64_t value);

    static const char kStatus_RequestIdTokenName[];
    static constexpr uint64_t kStatus_RequestIdTokenNameHash = UINT64_C(17280553313027361120);
    Blink_FedCmIdp& SetStatus_RequestIdToken(int64_t value);

    static const char kStatus_SignInStateMatchName[];
    static constexpr uint64_t kStatus_SignInStateMatchNameHash = UINT64_C(15085451675015980083);
    Blink_FedCmIdp& SetStatus_SignInStateMatch(int64_t value);

    static const char kTiming_AccountsDialogShownDurationName[];
    static constexpr uint64_t kTiming_AccountsDialogShownDurationNameHash = UINT64_C(11571078471586947859);
    Blink_FedCmIdp& SetTiming_AccountsDialogShownDuration(int64_t value);

    static const char kTiming_CancelOnDialogName[];
    static constexpr uint64_t kTiming_CancelOnDialogNameHash = UINT64_C(3760049210363712305);
    Blink_FedCmIdp& SetTiming_CancelOnDialog(int64_t value);

    static const char kTiming_ContinueOnDialogName[];
    static constexpr uint64_t kTiming_ContinueOnDialogNameHash = UINT64_C(5658920916221960950);
    Blink_FedCmIdp& SetTiming_ContinueOnDialog(int64_t value);

    static const char kTiming_DisconnectName[];
    static constexpr uint64_t kTiming_DisconnectNameHash = UINT64_C(16164962436490374623);
    Blink_FedCmIdp& SetTiming_Disconnect(int64_t value);

    static const char kTiming_IdTokenResponseName[];
    static constexpr uint64_t kTiming_IdTokenResponseNameHash = UINT64_C(9815123395675115620);
    Blink_FedCmIdp& SetTiming_IdTokenResponse(int64_t value);

    static const char kTiming_MismatchDialogShownDurationName[];
    static constexpr uint64_t kTiming_MismatchDialogShownDurationNameHash = UINT64_C(17261962705556864073);
    Blink_FedCmIdp& SetTiming_MismatchDialogShownDuration(int64_t value);

    static const char kTiming_ShowAccountsDialogName[];
    static constexpr uint64_t kTiming_ShowAccountsDialogNameHash = UINT64_C(6586192106353245718);
    Blink_FedCmIdp& SetTiming_ShowAccountsDialog(int64_t value);

    static const char kTiming_TurnaroundTimeName[];
    static constexpr uint64_t kTiming_TurnaroundTimeNameHash = UINT64_C(964934984140136051);
    Blink_FedCmIdp& SetTiming_TurnaroundTime(int64_t value);
};

class Blink_FindInPage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_FindInPage(ukm::SourceId source_id);
    explicit Blink_FindInPage(ukm::SourceIdObj source_id);
    Blink_FindInPage(Blink_FindInPage&&);
    Blink_FindInPage& operator=(Blink_FindInPage&&);
    ~Blink_FindInPage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14503116569381719800);

    static const char kBeforematchExpandedHiddenMatchableName[];
    static constexpr uint64_t kBeforematchExpandedHiddenMatchableNameHash = UINT64_C(1418541422054982411);
    Blink_FindInPage& SetBeforematchExpandedHiddenMatchable(int64_t value);

    static const char kDidHaveRenderSubtreeMatchName[];
    static constexpr uint64_t kDidHaveRenderSubtreeMatchNameHash = UINT64_C(10437331684651176215);
    Blink_FindInPage& SetDidHaveRenderSubtreeMatch(int64_t value);

    static const char kDidSearchName[];
    static constexpr uint64_t kDidSearchNameHash = UINT64_C(11237017958028068734);
    Blink_FindInPage& SetDidSearch(int64_t value);
};

class Blink_FrameLoader final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_FrameLoader(ukm::SourceId source_id);
    explicit Blink_FrameLoader(ukm::SourceIdObj source_id);
    Blink_FrameLoader(Blink_FrameLoader&&);
    Blink_FrameLoader& operator=(Blink_FrameLoader&&);
    ~Blink_FrameLoader() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16844813860515784834);

    static const char kCommitDocumentLoaderTimeName[];
    static constexpr uint64_t kCommitDocumentLoaderTimeNameHash = UINT64_C(9956533067091530475);
    Blink_FrameLoader& SetCommitDocumentLoaderTime(int64_t value);
};

class Blink_HTMLParsing final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_HTMLParsing(ukm::SourceId source_id);
    explicit Blink_HTMLParsing(ukm::SourceIdObj source_id);
    Blink_HTMLParsing(Blink_HTMLParsing&&);
    Blink_HTMLParsing& operator=(Blink_HTMLParsing&&);
    ~Blink_HTMLParsing() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11969773594143228030);

    static const char kChunkCountName[];
    static constexpr uint64_t kChunkCountNameHash = UINT64_C(12117884680134555924);
    Blink_HTMLParsing& SetChunkCount(int64_t value);

    static const char kFetchQueuedPreloadsTimeName[];
    static constexpr uint64_t kFetchQueuedPreloadsTimeNameHash = UINT64_C(11181566460668502457);
    Blink_HTMLParsing& SetFetchQueuedPreloadsTime(int64_t value);

    static const char kParsingTimeMaxName[];
    static constexpr uint64_t kParsingTimeMaxNameHash = UINT64_C(17100612038745900895);
    Blink_HTMLParsing& SetParsingTimeMax(int64_t value);

    static const char kParsingTimeMinName[];
    static constexpr uint64_t kParsingTimeMinNameHash = UINT64_C(1069166688745848743);
    Blink_HTMLParsing& SetParsingTimeMin(int64_t value);

    static const char kParsingTimeTotalName[];
    static constexpr uint64_t kParsingTimeTotalNameHash = UINT64_C(4428025718068016638);
    Blink_HTMLParsing& SetParsingTimeTotal(int64_t value);

    static const char kPreloadTimeName[];
    static constexpr uint64_t kPreloadTimeNameHash = UINT64_C(10231940208011006536);
    Blink_HTMLParsing& SetPreloadTime(int64_t value);

    static const char kPrepareToStopParsingTimeName[];
    static constexpr uint64_t kPrepareToStopParsingTimeNameHash = UINT64_C(2831826313858976977);
    Blink_HTMLParsing& SetPrepareToStopParsingTime(int64_t value);

    static const char kPumpTokenizerTimeName[];
    static constexpr uint64_t kPumpTokenizerTimeNameHash = UINT64_C(13454191439082080400);
    Blink_HTMLParsing& SetPumpTokenizerTime(int64_t value);

    static const char kScanAndPreloadTimeName[];
    static constexpr uint64_t kScanAndPreloadTimeNameHash = UINT64_C(6657456342375564209);
    Blink_HTMLParsing& SetScanAndPreloadTime(int64_t value);

    static const char kScanTimeName[];
    static constexpr uint64_t kScanTimeNameHash = UINT64_C(4279175345715057370);
    Blink_HTMLParsing& SetScanTime(int64_t value);

    static const char kTokensParsedAverageName[];
    static constexpr uint64_t kTokensParsedAverageNameHash = UINT64_C(9991938757455203086);
    Blink_HTMLParsing& SetTokensParsedAverage(int64_t value);

    static const char kTokensParsedMaxName[];
    static constexpr uint64_t kTokensParsedMaxNameHash = UINT64_C(5038652062281821354);
    Blink_HTMLParsing& SetTokensParsedMax(int64_t value);

    static const char kTokensParsedMinName[];
    static constexpr uint64_t kTokensParsedMinNameHash = UINT64_C(17792655194760260705);
    Blink_HTMLParsing& SetTokensParsedMin(int64_t value);

    static const char kTokensParsedTotalName[];
    static constexpr uint64_t kTokensParsedTotalNameHash = UINT64_C(15893456647292731302);
    Blink_HTMLParsing& SetTokensParsedTotal(int64_t value);

    static const char kYieldedTimeAverageName[];
    static constexpr uint64_t kYieldedTimeAverageNameHash = UINT64_C(13724762123779077336);
    Blink_HTMLParsing& SetYieldedTimeAverage(int64_t value);

    static const char kYieldedTimeMaxName[];
    static constexpr uint64_t kYieldedTimeMaxNameHash = UINT64_C(10007745934025216351);
    Blink_HTMLParsing& SetYieldedTimeMax(int64_t value);

    static const char kYieldedTimeMinName[];
    static constexpr uint64_t kYieldedTimeMinNameHash = UINT64_C(14554832440690350773);
    Blink_HTMLParsing& SetYieldedTimeMin(int64_t value);
};

class Blink_JavaScriptFramework_Versions final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_JavaScriptFramework_Versions(ukm::SourceId source_id);
    explicit Blink_JavaScriptFramework_Versions(ukm::SourceIdObj source_id);
    Blink_JavaScriptFramework_Versions(Blink_JavaScriptFramework_Versions&&);
    Blink_JavaScriptFramework_Versions& operator=(Blink_JavaScriptFramework_Versions&&);
    ~Blink_JavaScriptFramework_Versions() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14434501717955674760);

    static const char kAngularVersionName[];
    static constexpr uint64_t kAngularVersionNameHash = UINT64_C(11909034231716210465);
    Blink_JavaScriptFramework_Versions& SetAngularVersion(int64_t value);

    static const char kNextJSVersionName[];
    static constexpr uint64_t kNextJSVersionNameHash = UINT64_C(12860241096232567250);
    Blink_JavaScriptFramework_Versions& SetNextJSVersion(int64_t value);

    static const char kNuxtVersionName[];
    static constexpr uint64_t kNuxtVersionNameHash = UINT64_C(1729325144540856848);
    Blink_JavaScriptFramework_Versions& SetNuxtVersion(int64_t value);

    static const char kVueVersionName[];
    static constexpr uint64_t kVueVersionNameHash = UINT64_C(12723767202114968564);
    Blink_JavaScriptFramework_Versions& SetVueVersion(int64_t value);
};

class Blink_PageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_PageLoad(ukm::SourceId source_id);
    explicit Blink_PageLoad(ukm::SourceIdObj source_id);
    Blink_PageLoad(Blink_PageLoad&&);
    Blink_PageLoad& operator=(Blink_PageLoad&&);
    ~Blink_PageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11315426756825559974);

    static const char kAccessibilityName[];
    static constexpr uint64_t kAccessibilityNameHash = UINT64_C(16205354857356899161);
    Blink_PageLoad& SetAccessibility(int64_t value);

    static const char kAnchorElementMetricsIntersectionObserverName[];
    static constexpr uint64_t kAnchorElementMetricsIntersectionObserverNameHash = UINT64_C(14997201932118757899);
    Blink_PageLoad& SetAnchorElementMetricsIntersectionObserver(int64_t value);

    static const char kAnimateName[];
    static constexpr uint64_t kAnimateNameHash = UINT64_C(404752839576342973);
    Blink_PageLoad& SetAnimate(int64_t value);

    static const char kCompositingCommitName[];
    static constexpr uint64_t kCompositingCommitNameHash = UINT64_C(15809321536415505310);
    Blink_PageLoad& SetCompositingCommit(int64_t value);

    static const char kCompositingInputsName[];
    static constexpr uint64_t kCompositingInputsNameHash = UINT64_C(3671162331545334715);
    Blink_PageLoad& SetCompositingInputs(int64_t value);

    static const char kContentDocumentUpdateName[];
    static constexpr uint64_t kContentDocumentUpdateNameHash = UINT64_C(1358745339642406099);
    Blink_PageLoad& SetContentDocumentUpdate(int64_t value);

    static const char kDisplayLockIntersectionObserverName[];
    static constexpr uint64_t kDisplayLockIntersectionObserverNameHash = UINT64_C(7178067269321593883);
    Blink_PageLoad& SetDisplayLockIntersectionObserver(int64_t value);

    static const char kForcedStyleAndLayoutName[];
    static constexpr uint64_t kForcedStyleAndLayoutNameHash = UINT64_C(15609086396948909960);
    Blink_PageLoad& SetForcedStyleAndLayout(int64_t value);

    static const char kHandleInputEventsName[];
    static constexpr uint64_t kHandleInputEventsNameHash = UINT64_C(8113352720551083585);
    Blink_PageLoad& SetHandleInputEvents(int64_t value);

    static const char kHitTestDocumentUpdateName[];
    static constexpr uint64_t kHitTestDocumentUpdateNameHash = UINT64_C(11724920415365121476);
    Blink_PageLoad& SetHitTestDocumentUpdate(int64_t value);

    static const char kImplCompositorCommitName[];
    static constexpr uint64_t kImplCompositorCommitNameHash = UINT64_C(13634114799754628945);
    Blink_PageLoad& SetImplCompositorCommit(int64_t value);

    static const char kIntersectionObservationName[];
    static constexpr uint64_t kIntersectionObservationNameHash = UINT64_C(15458618821019023377);
    Blink_PageLoad& SetIntersectionObservation(int64_t value);

    static const char kIntersectionObservationInternalCountName[];
    static constexpr uint64_t kIntersectionObservationInternalCountNameHash = UINT64_C(6834253869799825667);
    Blink_PageLoad& SetIntersectionObservationInternalCount(int64_t value);

    static const char kIntersectionObservationJavascriptCountName[];
    static constexpr uint64_t kIntersectionObservationJavascriptCountNameHash = UINT64_C(1232440373849071112);
    Blink_PageLoad& SetIntersectionObservationJavascriptCount(int64_t value);

    static const char kJavascriptDocumentUpdateName[];
    static constexpr uint64_t kJavascriptDocumentUpdateNameHash = UINT64_C(838763158452309866);
    Blink_PageLoad& SetJavascriptDocumentUpdate(int64_t value);

    static const char kJavascriptIntersectionObserverName[];
    static constexpr uint64_t kJavascriptIntersectionObserverNameHash = UINT64_C(18042287564030592982);
    Blink_PageLoad& SetJavascriptIntersectionObserver(int64_t value);

    static const char kLayoutName[];
    static constexpr uint64_t kLayoutNameHash = UINT64_C(16994824421489949816);
    Blink_PageLoad& SetLayout(int64_t value);

    static const char kLazyLoadIntersectionObserverName[];
    static constexpr uint64_t kLazyLoadIntersectionObserverNameHash = UINT64_C(13104401194128021099);
    Blink_PageLoad& SetLazyLoadIntersectionObserver(int64_t value);

    static const char kMainFrameName[];
    static constexpr uint64_t kMainFrameNameHash = UINT64_C(4089985743552002450);
    Blink_PageLoad& SetMainFrame(int64_t value);

    static const char kMediaIntersectionObserverName[];
    static constexpr uint64_t kMediaIntersectionObserverNameHash = UINT64_C(7929379986308471900);
    Blink_PageLoad& SetMediaIntersectionObserver(int64_t value);

    static const char kPaintName[];
    static constexpr uint64_t kPaintNameHash = UINT64_C(5188891880448173739);
    Blink_PageLoad& SetPaint(int64_t value);

    static const char kParseStyleSheetName[];
    static constexpr uint64_t kParseStyleSheetNameHash = UINT64_C(894530995873833008);
    Blink_PageLoad& SetParseStyleSheet(int64_t value);

    static const char kPermissionElementIntersectionObserverName[];
    static constexpr uint64_t kPermissionElementIntersectionObserverNameHash = UINT64_C(1807616280577340055);
    Blink_PageLoad& SetPermissionElementIntersectionObserver(int64_t value);

    static const char kPossibleSynchronizedScrollCount2Name[];
    static constexpr uint64_t kPossibleSynchronizedScrollCount2NameHash = UINT64_C(14804210884018037500);
    Blink_PageLoad& SetPossibleSynchronizedScrollCount2(int64_t value);

    static const char kPrePaintName[];
    static constexpr uint64_t kPrePaintNameHash = UINT64_C(4880392982914161630);
    Blink_PageLoad& SetPrePaint(int64_t value);

    static const char kServiceDocumentUpdateName[];
    static constexpr uint64_t kServiceDocumentUpdateNameHash = UINT64_C(13428762956786215096);
    Blink_PageLoad& SetServiceDocumentUpdate(int64_t value);

    static const char kStyleName[];
    static constexpr uint64_t kStyleNameHash = UINT64_C(12549367841823747617);
    Blink_PageLoad& SetStyle(int64_t value);

    static const char kUpdateLayersName[];
    static constexpr uint64_t kUpdateLayersNameHash = UINT64_C(1916294310099025691);
    Blink_PageLoad& SetUpdateLayers(int64_t value);

    static const char kUpdateViewportIntersectionName[];
    static constexpr uint64_t kUpdateViewportIntersectionNameHash = UINT64_C(1757331034736396629);
    Blink_PageLoad& SetUpdateViewportIntersection(int64_t value);

    static const char kUserDrivenDocumentUpdateName[];
    static constexpr uint64_t kUserDrivenDocumentUpdateNameHash = UINT64_C(15346711473735247747);
    Blink_PageLoad& SetUserDrivenDocumentUpdate(int64_t value);

    static const char kVisualUpdateDelayName[];
    static constexpr uint64_t kVisualUpdateDelayNameHash = UINT64_C(8444490798196377656);
    Blink_PageLoad& SetVisualUpdateDelay(int64_t value);

    static const char kWaitForCommitName[];
    static constexpr uint64_t kWaitForCommitNameHash = UINT64_C(16193385044298516974);
    Blink_PageLoad& SetWaitForCommit(int64_t value);
};

class Blink_PaintTiming final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_PaintTiming(ukm::SourceId source_id);
    explicit Blink_PaintTiming(ukm::SourceIdObj source_id);
    Blink_PaintTiming(Blink_PaintTiming&&);
    Blink_PaintTiming& operator=(Blink_PaintTiming&&);
    ~Blink_PaintTiming() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14091970027896417477);

    static const char kLCPDebugging_HasViewportImageName[];
    static constexpr uint64_t kLCPDebugging_HasViewportImageNameHash = UINT64_C(16800939850569618070);
    Blink_PaintTiming& SetLCPDebugging_HasViewportImage(int64_t value);
};

class Blink_Script_AsyncScripts final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_Script_AsyncScripts(ukm::SourceId source_id);
    explicit Blink_Script_AsyncScripts(ukm::SourceIdObj source_id);
    Blink_Script_AsyncScripts(Blink_Script_AsyncScripts&&);
    Blink_Script_AsyncScripts& operator=(Blink_Script_AsyncScripts&&);
    ~Blink_Script_AsyncScripts() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16907734789798036504);
};

class Blink_ShapeText final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_ShapeText(ukm::SourceId source_id);
    explicit Blink_ShapeText(ukm::SourceIdObj source_id);
    Blink_ShapeText(Blink_ShapeText&&);
    Blink_ShapeText& operator=(Blink_ShapeText&&);
    ~Blink_ShapeText() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3664251173651435263);

    static const char kMaxTimeName[];
    static constexpr uint64_t kMaxTimeNameHash = UINT64_C(11424386854933328231);
    Blink_ShapeText& SetMaxTime(int64_t value);

    static const char kTotalTimeName[];
    static constexpr uint64_t kTotalTimeNameHash = UINT64_C(13668983701164557337);
    Blink_ShapeText& SetTotalTime(int64_t value);
};

class Blink_SVGImage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_SVGImage(ukm::SourceId source_id);
    explicit Blink_SVGImage(ukm::SourceIdObj source_id);
    Blink_SVGImage(Blink_SVGImage&&);
    Blink_SVGImage& operator=(Blink_SVGImage&&);
    ~Blink_SVGImage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16282696158499210158);

    static const char kCountName[];
    static constexpr uint64_t kCountNameHash = UINT64_C(16807320898981148612);
    Blink_SVGImage& SetCount(int64_t value);

    static const char kTotalTimeName[];
    static constexpr uint64_t kTotalTimeNameHash = UINT64_C(13668983701164557337);
    Blink_SVGImage& SetTotalTime(int64_t value);
};

class Blink_UpdateTime final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_UpdateTime(ukm::SourceId source_id);
    explicit Blink_UpdateTime(ukm::SourceIdObj source_id);
    Blink_UpdateTime(Blink_UpdateTime&&);
    Blink_UpdateTime& operator=(Blink_UpdateTime&&);
    ~Blink_UpdateTime() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(397568092790313676);

    static const char kAccessibilityName[];
    static constexpr uint64_t kAccessibilityNameHash = UINT64_C(16205354857356899161);
    Blink_UpdateTime& SetAccessibility(int64_t value);

    static const char kAccessibilityBeginMainFrameName[];
    static constexpr uint64_t kAccessibilityBeginMainFrameNameHash = UINT64_C(16370054653202805065);
    Blink_UpdateTime& SetAccessibilityBeginMainFrame(int64_t value);

    static const char kAnchorElementMetricsIntersectionObserverName[];
    static constexpr uint64_t kAnchorElementMetricsIntersectionObserverNameHash = UINT64_C(14997201932118757899);
    Blink_UpdateTime& SetAnchorElementMetricsIntersectionObserver(int64_t value);

    static const char kAnchorElementMetricsIntersectionObserverBeginMainFrameName[];
    static constexpr uint64_t kAnchorElementMetricsIntersectionObserverBeginMainFrameNameHash = UINT64_C(9195304428041768096);
    Blink_UpdateTime& SetAnchorElementMetricsIntersectionObserverBeginMainFrame(int64_t value);

    static const char kAnimateName[];
    static constexpr uint64_t kAnimateNameHash = UINT64_C(404752839576342973);
    Blink_UpdateTime& SetAnimate(int64_t value);

    static const char kAnimateBeginMainFrameName[];
    static constexpr uint64_t kAnimateBeginMainFrameNameHash = UINT64_C(9622018550701777011);
    Blink_UpdateTime& SetAnimateBeginMainFrame(int64_t value);

    static const char kCompositingCommitName[];
    static constexpr uint64_t kCompositingCommitNameHash = UINT64_C(15809321536415505310);
    Blink_UpdateTime& SetCompositingCommit(int64_t value);

    static const char kCompositingCommitBeginMainFrameName[];
    static constexpr uint64_t kCompositingCommitBeginMainFrameNameHash = UINT64_C(8598538897615787952);
    Blink_UpdateTime& SetCompositingCommitBeginMainFrame(int64_t value);

    static const char kCompositingInputsName[];
    static constexpr uint64_t kCompositingInputsNameHash = UINT64_C(3671162331545334715);
    Blink_UpdateTime& SetCompositingInputs(int64_t value);

    static const char kCompositingInputsBeginMainFrameName[];
    static constexpr uint64_t kCompositingInputsBeginMainFrameNameHash = UINT64_C(1004024316266743286);
    Blink_UpdateTime& SetCompositingInputsBeginMainFrame(int64_t value);

    static const char kContentDocumentUpdateName[];
    static constexpr uint64_t kContentDocumentUpdateNameHash = UINT64_C(1358745339642406099);
    Blink_UpdateTime& SetContentDocumentUpdate(int64_t value);

    static const char kContentDocumentUpdateBeginMainFrameName[];
    static constexpr uint64_t kContentDocumentUpdateBeginMainFrameNameHash = UINT64_C(7410495369725843276);
    Blink_UpdateTime& SetContentDocumentUpdateBeginMainFrame(int64_t value);

    static const char kDisplayLockIntersectionObserverName[];
    static constexpr uint64_t kDisplayLockIntersectionObserverNameHash = UINT64_C(7178067269321593883);
    Blink_UpdateTime& SetDisplayLockIntersectionObserver(int64_t value);

    static const char kDisplayLockIntersectionObserverBeginMainFrameName[];
    static constexpr uint64_t kDisplayLockIntersectionObserverBeginMainFrameNameHash = UINT64_C(15834384929724681025);
    Blink_UpdateTime& SetDisplayLockIntersectionObserverBeginMainFrame(int64_t value);

    static const char kForcedStyleAndLayoutName[];
    static constexpr uint64_t kForcedStyleAndLayoutNameHash = UINT64_C(15609086396948909960);
    Blink_UpdateTime& SetForcedStyleAndLayout(int64_t value);

    static const char kForcedStyleAndLayoutBeginMainFrameName[];
    static constexpr uint64_t kForcedStyleAndLayoutBeginMainFrameNameHash = UINT64_C(16327973277672989627);
    Blink_UpdateTime& SetForcedStyleAndLayoutBeginMainFrame(int64_t value);

    static const char kHandleInputEventsName[];
    static constexpr uint64_t kHandleInputEventsNameHash = UINT64_C(8113352720551083585);
    Blink_UpdateTime& SetHandleInputEvents(int64_t value);

    static const char kHandleInputEventsBeginMainFrameName[];
    static constexpr uint64_t kHandleInputEventsBeginMainFrameNameHash = UINT64_C(13294192933285545306);
    Blink_UpdateTime& SetHandleInputEventsBeginMainFrame(int64_t value);

    static const char kHitTestDocumentUpdateName[];
    static constexpr uint64_t kHitTestDocumentUpdateNameHash = UINT64_C(11724920415365121476);
    Blink_UpdateTime& SetHitTestDocumentUpdate(int64_t value);

    static const char kHitTestDocumentUpdateBeginMainFrameName[];
    static constexpr uint64_t kHitTestDocumentUpdateBeginMainFrameNameHash = UINT64_C(1812023415449158670);
    Blink_UpdateTime& SetHitTestDocumentUpdateBeginMainFrame(int64_t value);

    static const char kImplCompositorCommitName[];
    static constexpr uint64_t kImplCompositorCommitNameHash = UINT64_C(13634114799754628945);
    Blink_UpdateTime& SetImplCompositorCommit(int64_t value);

    static const char kImplCompositorCommitBeginMainFrameName[];
    static constexpr uint64_t kImplCompositorCommitBeginMainFrameNameHash = UINT64_C(4032810828473550911);
    Blink_UpdateTime& SetImplCompositorCommitBeginMainFrame(int64_t value);

    static const char kIntersectionObservationName[];
    static constexpr uint64_t kIntersectionObservationNameHash = UINT64_C(15458618821019023377);
    Blink_UpdateTime& SetIntersectionObservation(int64_t value);

    static const char kIntersectionObservationBeginMainFrameName[];
    static constexpr uint64_t kIntersectionObservationBeginMainFrameNameHash = UINT64_C(16834496994327973836);
    Blink_UpdateTime& SetIntersectionObservationBeginMainFrame(int64_t value);

    static const char kIntersectionObservationInternalCountName[];
    static constexpr uint64_t kIntersectionObservationInternalCountNameHash = UINT64_C(6834253869799825667);
    Blink_UpdateTime& SetIntersectionObservationInternalCount(int64_t value);

    static const char kIntersectionObservationInternalCountBeginMainFrameName[];
    static constexpr uint64_t kIntersectionObservationInternalCountBeginMainFrameNameHash = UINT64_C(17999515261369023863);
    Blink_UpdateTime& SetIntersectionObservationInternalCountBeginMainFrame(int64_t value);

    static const char kIntersectionObservationJavascriptCountName[];
    static constexpr uint64_t kIntersectionObservationJavascriptCountNameHash = UINT64_C(1232440373849071112);
    Blink_UpdateTime& SetIntersectionObservationJavascriptCount(int64_t value);

    static const char kIntersectionObservationJavascriptCountBeginMainFrameName[];
    static constexpr uint64_t kIntersectionObservationJavascriptCountBeginMainFrameNameHash = UINT64_C(12374448687972523560);
    Blink_UpdateTime& SetIntersectionObservationJavascriptCountBeginMainFrame(int64_t value);

    static const char kJavascriptDocumentUpdateName[];
    static constexpr uint64_t kJavascriptDocumentUpdateNameHash = UINT64_C(838763158452309866);
    Blink_UpdateTime& SetJavascriptDocumentUpdate(int64_t value);

    static const char kJavascriptDocumentUpdateBeginMainFrameName[];
    static constexpr uint64_t kJavascriptDocumentUpdateBeginMainFrameNameHash = UINT64_C(7022936487950091361);
    Blink_UpdateTime& SetJavascriptDocumentUpdateBeginMainFrame(int64_t value);

    static const char kJavascriptIntersectionObserverName[];
    static constexpr uint64_t kJavascriptIntersectionObserverNameHash = UINT64_C(18042287564030592982);
    Blink_UpdateTime& SetJavascriptIntersectionObserver(int64_t value);

    static const char kJavascriptIntersectionObserverBeginMainFrameName[];
    static constexpr uint64_t kJavascriptIntersectionObserverBeginMainFrameNameHash = UINT64_C(17663839954112465059);
    Blink_UpdateTime& SetJavascriptIntersectionObserverBeginMainFrame(int64_t value);

    static const char kLayoutName[];
    static constexpr uint64_t kLayoutNameHash = UINT64_C(16994824421489949816);
    Blink_UpdateTime& SetLayout(int64_t value);

    static const char kLayoutBeginMainFrameName[];
    static constexpr uint64_t kLayoutBeginMainFrameNameHash = UINT64_C(11452684584721882368);
    Blink_UpdateTime& SetLayoutBeginMainFrame(int64_t value);

    static const char kLazyLoadIntersectionObserverName[];
    static constexpr uint64_t kLazyLoadIntersectionObserverNameHash = UINT64_C(13104401194128021099);
    Blink_UpdateTime& SetLazyLoadIntersectionObserver(int64_t value);

    static const char kLazyLoadIntersectionObserverBeginMainFrameName[];
    static constexpr uint64_t kLazyLoadIntersectionObserverBeginMainFrameNameHash = UINT64_C(5364811165188730962);
    Blink_UpdateTime& SetLazyLoadIntersectionObserverBeginMainFrame(int64_t value);

    static const char kMainFrameName[];
    static constexpr uint64_t kMainFrameNameHash = UINT64_C(4089985743552002450);
    Blink_UpdateTime& SetMainFrame(int64_t value);

    static const char kMainFrameIsBeforeFCPName[];
    static constexpr uint64_t kMainFrameIsBeforeFCPNameHash = UINT64_C(9885769400282831772);
    Blink_UpdateTime& SetMainFrameIsBeforeFCP(int64_t value);

    static const char kMainFrameReasonsName[];
    static constexpr uint64_t kMainFrameReasonsNameHash = UINT64_C(8828908854731562228);
    Blink_UpdateTime& SetMainFrameReasons(int64_t value);

    static const char kMediaIntersectionObserverName[];
    static constexpr uint64_t kMediaIntersectionObserverNameHash = UINT64_C(7929379986308471900);
    Blink_UpdateTime& SetMediaIntersectionObserver(int64_t value);

    static const char kMediaIntersectionObserverBeginMainFrameName[];
    static constexpr uint64_t kMediaIntersectionObserverBeginMainFrameNameHash = UINT64_C(4033991528825288813);
    Blink_UpdateTime& SetMediaIntersectionObserverBeginMainFrame(int64_t value);

    static const char kPaintName[];
    static constexpr uint64_t kPaintNameHash = UINT64_C(5188891880448173739);
    Blink_UpdateTime& SetPaint(int64_t value);

    static const char kPaintBeginMainFrameName[];
    static constexpr uint64_t kPaintBeginMainFrameNameHash = UINT64_C(15248831105857504996);
    Blink_UpdateTime& SetPaintBeginMainFrame(int64_t value);

    static const char kParseStyleSheetName[];
    static constexpr uint64_t kParseStyleSheetNameHash = UINT64_C(894530995873833008);
    Blink_UpdateTime& SetParseStyleSheet(int64_t value);

    static const char kParseStyleSheetBeginMainFrameName[];
    static constexpr uint64_t kParseStyleSheetBeginMainFrameNameHash = UINT64_C(11811580094233179112);
    Blink_UpdateTime& SetParseStyleSheetBeginMainFrame(int64_t value);

    static const char kPermissionElementIntersectionObserverName[];
    static constexpr uint64_t kPermissionElementIntersectionObserverNameHash = UINT64_C(1807616280577340055);
    Blink_UpdateTime& SetPermissionElementIntersectionObserver(int64_t value);

    static const char kPermissionElementIntersectionObserverBeginMainFrameName[];
    static constexpr uint64_t kPermissionElementIntersectionObserverBeginMainFrameNameHash = UINT64_C(8495000340864575509);
    Blink_UpdateTime& SetPermissionElementIntersectionObserverBeginMainFrame(int64_t value);

    static const char kPossibleSynchronizedScrollCount2Name[];
    static constexpr uint64_t kPossibleSynchronizedScrollCount2NameHash = UINT64_C(14804210884018037500);
    Blink_UpdateTime& SetPossibleSynchronizedScrollCount2(int64_t value);

    static const char kPossibleSynchronizedScrollCount2BeginMainFrameName[];
    static constexpr uint64_t kPossibleSynchronizedScrollCount2BeginMainFrameNameHash = UINT64_C(78849555788140421);
    Blink_UpdateTime& SetPossibleSynchronizedScrollCount2BeginMainFrame(int64_t value);

    static const char kPrePaintName[];
    static constexpr uint64_t kPrePaintNameHash = UINT64_C(4880392982914161630);
    Blink_UpdateTime& SetPrePaint(int64_t value);

    static const char kPrePaintBeginMainFrameName[];
    static constexpr uint64_t kPrePaintBeginMainFrameNameHash = UINT64_C(16567526314361867217);
    Blink_UpdateTime& SetPrePaintBeginMainFrame(int64_t value);

    static const char kServiceDocumentUpdateName[];
    static constexpr uint64_t kServiceDocumentUpdateNameHash = UINT64_C(13428762956786215096);
    Blink_UpdateTime& SetServiceDocumentUpdate(int64_t value);

    static const char kServiceDocumentUpdateBeginMainFrameName[];
    static constexpr uint64_t kServiceDocumentUpdateBeginMainFrameNameHash = UINT64_C(9226397078952842727);
    Blink_UpdateTime& SetServiceDocumentUpdateBeginMainFrame(int64_t value);

    static const char kStyleName[];
    static constexpr uint64_t kStyleNameHash = UINT64_C(12549367841823747617);
    Blink_UpdateTime& SetStyle(int64_t value);

    static const char kStyleBeginMainFrameName[];
    static constexpr uint64_t kStyleBeginMainFrameNameHash = UINT64_C(10543819668997305570);
    Blink_UpdateTime& SetStyleBeginMainFrame(int64_t value);

    static const char kStylePercentageName[];
    static constexpr uint64_t kStylePercentageNameHash = UINT64_C(9410633853884879876);
    Blink_UpdateTime& SetStylePercentage(int64_t value);

    static const char kUpdateLayersName[];
    static constexpr uint64_t kUpdateLayersNameHash = UINT64_C(1916294310099025691);
    Blink_UpdateTime& SetUpdateLayers(int64_t value);

    static const char kUpdateLayersBeginMainFrameName[];
    static constexpr uint64_t kUpdateLayersBeginMainFrameNameHash = UINT64_C(9380996741760182459);
    Blink_UpdateTime& SetUpdateLayersBeginMainFrame(int64_t value);

    static const char kUpdateViewportIntersectionName[];
    static constexpr uint64_t kUpdateViewportIntersectionNameHash = UINT64_C(1757331034736396629);
    Blink_UpdateTime& SetUpdateViewportIntersection(int64_t value);

    static const char kUpdateViewportIntersectionBeginMainFrameName[];
    static constexpr uint64_t kUpdateViewportIntersectionBeginMainFrameNameHash = UINT64_C(11144009482153765904);
    Blink_UpdateTime& SetUpdateViewportIntersectionBeginMainFrame(int64_t value);

    static const char kUserDrivenDocumentUpdateName[];
    static constexpr uint64_t kUserDrivenDocumentUpdateNameHash = UINT64_C(15346711473735247747);
    Blink_UpdateTime& SetUserDrivenDocumentUpdate(int64_t value);

    static const char kUserDrivenDocumentUpdateBeginMainFrameName[];
    static constexpr uint64_t kUserDrivenDocumentUpdateBeginMainFrameNameHash = UINT64_C(9790701760139081748);
    Blink_UpdateTime& SetUserDrivenDocumentUpdateBeginMainFrame(int64_t value);

    static const char kVisualUpdateDelayName[];
    static constexpr uint64_t kVisualUpdateDelayNameHash = UINT64_C(8444490798196377656);
    Blink_UpdateTime& SetVisualUpdateDelay(int64_t value);

    static const char kVisualUpdateDelayBeginMainFrameName[];
    static constexpr uint64_t kVisualUpdateDelayBeginMainFrameNameHash = UINT64_C(137003963035025615);
    Blink_UpdateTime& SetVisualUpdateDelayBeginMainFrame(int64_t value);

    static const char kWaitForCommitName[];
    static constexpr uint64_t kWaitForCommitNameHash = UINT64_C(16193385044298516974);
    Blink_UpdateTime& SetWaitForCommit(int64_t value);

    static const char kWaitForCommitBeginMainFrameName[];
    static constexpr uint64_t kWaitForCommitBeginMainFrameNameHash = UINT64_C(2189166352894194716);
    Blink_UpdateTime& SetWaitForCommitBeginMainFrame(int64_t value);
};

class Blink_UseCounter final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Blink_UseCounter(ukm::SourceId source_id);
    explicit Blink_UseCounter(ukm::SourceIdObj source_id);
    Blink_UseCounter(Blink_UseCounter&&);
    Blink_UseCounter& operator=(Blink_UseCounter&&);
    ~Blink_UseCounter() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16486120572686381376);

    static const char kFeatureName[];
    static constexpr uint64_t kFeatureNameHash = UINT64_C(2378497229593503977);
    Blink_UseCounter& SetFeature(int64_t value);

    static const char kIsMainFrameFeatureName[];
    static constexpr uint64_t kIsMainFrameFeatureNameHash = UINT64_C(8112503265735119902);
    Blink_UseCounter& SetIsMainFrameFeature(int64_t value);
};

class BrowsingTopics_DocumentBrowsingTopicsApiResult2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BrowsingTopics_DocumentBrowsingTopicsApiResult2(ukm::SourceId source_id);
    explicit BrowsingTopics_DocumentBrowsingTopicsApiResult2(ukm::SourceIdObj source_id);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2(BrowsingTopics_DocumentBrowsingTopicsApiResult2&&);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& operator=(BrowsingTopics_DocumentBrowsingTopicsApiResult2&&);
    ~BrowsingTopics_DocumentBrowsingTopicsApiResult2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5152886962488555860);

    static const char kCandidateTopic0Name[];
    static constexpr uint64_t kCandidateTopic0NameHash = UINT64_C(9779967455276559717);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic0(int64_t value);

    static const char kCandidateTopic0IsTrueTopTopicName[];
    static constexpr uint64_t kCandidateTopic0IsTrueTopTopicNameHash = UINT64_C(1578593162974490059);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic0IsTrueTopTopic(int64_t value);

    static const char kCandidateTopic0ModelVersionName[];
    static constexpr uint64_t kCandidateTopic0ModelVersionNameHash = UINT64_C(9097187253179487414);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic0ModelVersion(int64_t value);

    static const char kCandidateTopic0ShouldBeFilteredName[];
    static constexpr uint64_t kCandidateTopic0ShouldBeFilteredNameHash = UINT64_C(14007932011223497651);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic0ShouldBeFiltered(int64_t value);

    static const char kCandidateTopic0TaxonomyVersionName[];
    static constexpr uint64_t kCandidateTopic0TaxonomyVersionNameHash = UINT64_C(7846803666213640328);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic0TaxonomyVersion(int64_t value);

    static const char kCandidateTopic1Name[];
    static constexpr uint64_t kCandidateTopic1NameHash = UINT64_C(4716647145539184457);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic1(int64_t value);

    static const char kCandidateTopic1IsTrueTopTopicName[];
    static constexpr uint64_t kCandidateTopic1IsTrueTopTopicNameHash = UINT64_C(10689948347449740134);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic1IsTrueTopTopic(int64_t value);

    static const char kCandidateTopic1ModelVersionName[];
    static constexpr uint64_t kCandidateTopic1ModelVersionNameHash = UINT64_C(16869336769338677652);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic1ModelVersion(int64_t value);

    static const char kCandidateTopic1ShouldBeFilteredName[];
    static constexpr uint64_t kCandidateTopic1ShouldBeFilteredNameHash = UINT64_C(2888877158651970197);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic1ShouldBeFiltered(int64_t value);

    static const char kCandidateTopic1TaxonomyVersionName[];
    static constexpr uint64_t kCandidateTopic1TaxonomyVersionNameHash = UINT64_C(6401608449666231639);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic1TaxonomyVersion(int64_t value);

    static const char kCandidateTopic2Name[];
    static constexpr uint64_t kCandidateTopic2NameHash = UINT64_C(14276467860023928408);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic2(int64_t value);

    static const char kCandidateTopic2IsTrueTopTopicName[];
    static constexpr uint64_t kCandidateTopic2IsTrueTopTopicNameHash = UINT64_C(6164705212347125651);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic2IsTrueTopTopic(int64_t value);

    static const char kCandidateTopic2ModelVersionName[];
    static constexpr uint64_t kCandidateTopic2ModelVersionNameHash = UINT64_C(13542832631646675538);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic2ModelVersion(int64_t value);

    static const char kCandidateTopic2ShouldBeFilteredName[];
    static constexpr uint64_t kCandidateTopic2ShouldBeFilteredNameHash = UINT64_C(14494530253087889005);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic2ShouldBeFiltered(int64_t value);

    static const char kCandidateTopic2TaxonomyVersionName[];
    static constexpr uint64_t kCandidateTopic2TaxonomyVersionNameHash = UINT64_C(15938433466537741546);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetCandidateTopic2TaxonomyVersion(int64_t value);

    static const char kFailureReasonName[];
    static constexpr uint64_t kFailureReasonNameHash = UINT64_C(14882323251151056958);
    BrowsingTopics_DocumentBrowsingTopicsApiResult2& SetFailureReason(int64_t value);
};

class BrowsingTopics_EpochTopicsCalculationResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BrowsingTopics_EpochTopicsCalculationResult(ukm::SourceId source_id);
    explicit BrowsingTopics_EpochTopicsCalculationResult(ukm::SourceIdObj source_id);
    BrowsingTopics_EpochTopicsCalculationResult(BrowsingTopics_EpochTopicsCalculationResult&&);
    BrowsingTopics_EpochTopicsCalculationResult& operator=(BrowsingTopics_EpochTopicsCalculationResult&&);
    ~BrowsingTopics_EpochTopicsCalculationResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3733375777248285534);

    static const char kModelVersionName[];
    static constexpr uint64_t kModelVersionNameHash = UINT64_C(11751551263536343651);
    BrowsingTopics_EpochTopicsCalculationResult& SetModelVersion(int64_t value);

    static const char kPaddedTopicsStartIndexName[];
    static constexpr uint64_t kPaddedTopicsStartIndexNameHash = UINT64_C(17165443436198363341);
    BrowsingTopics_EpochTopicsCalculationResult& SetPaddedTopicsStartIndex(int64_t value);

    static const char kTaxonomyVersionName[];
    static constexpr uint64_t kTaxonomyVersionNameHash = UINT64_C(5276091575720387166);
    BrowsingTopics_EpochTopicsCalculationResult& SetTaxonomyVersion(int64_t value);

    static const char kTopTopic0Name[];
    static constexpr uint64_t kTopTopic0NameHash = UINT64_C(15261850025188331200);
    BrowsingTopics_EpochTopicsCalculationResult& SetTopTopic0(int64_t value);

    static const char kTopTopic1Name[];
    static constexpr uint64_t kTopTopic1NameHash = UINT64_C(10957692344064497259);
    BrowsingTopics_EpochTopicsCalculationResult& SetTopTopic1(int64_t value);

    static const char kTopTopic2Name[];
    static constexpr uint64_t kTopTopic2NameHash = UINT64_C(16181688505325493092);
    BrowsingTopics_EpochTopicsCalculationResult& SetTopTopic2(int64_t value);

    static const char kTopTopic3Name[];
    static constexpr uint64_t kTopTopic3NameHash = UINT64_C(16634195735975385980);
    BrowsingTopics_EpochTopicsCalculationResult& SetTopTopic3(int64_t value);

    static const char kTopTopic4Name[];
    static constexpr uint64_t kTopTopic4NameHash = UINT64_C(5254361349741901366);
    BrowsingTopics_EpochTopicsCalculationResult& SetTopTopic4(int64_t value);
};

class BrowsingTopics_PageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BrowsingTopics_PageLoad(ukm::SourceId source_id);
    explicit BrowsingTopics_PageLoad(ukm::SourceIdObj source_id);
    BrowsingTopics_PageLoad(BrowsingTopics_PageLoad&&);
    BrowsingTopics_PageLoad& operator=(BrowsingTopics_PageLoad&&);
    ~BrowsingTopics_PageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(514082468828822420);

    static const char kTopicsRequestingContextDomainsCountName[];
    static constexpr uint64_t kTopicsRequestingContextDomainsCountNameHash = UINT64_C(12379540477272009700);
    BrowsingTopics_PageLoad& SetTopicsRequestingContextDomainsCount(int64_t value);
};

class BrowsingTopics_TopicsRedirectChainDetected final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit BrowsingTopics_TopicsRedirectChainDetected(ukm::SourceId source_id);
    explicit BrowsingTopics_TopicsRedirectChainDetected(ukm::SourceIdObj source_id);
    BrowsingTopics_TopicsRedirectChainDetected(BrowsingTopics_TopicsRedirectChainDetected&&);
    BrowsingTopics_TopicsRedirectChainDetected& operator=(BrowsingTopics_TopicsRedirectChainDetected&&);
    ~BrowsingTopics_TopicsRedirectChainDetected() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15467140159072428874);

    static const char kNumberOfPagesCallingTopicsName[];
    static constexpr uint64_t kNumberOfPagesCallingTopicsNameHash = UINT64_C(2189539803702625117);
    BrowsingTopics_TopicsRedirectChainDetected& SetNumberOfPagesCallingTopics(int64_t value);
};

class ChargeEventHistory final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChargeEventHistory(ukm::SourceId source_id);
    explicit ChargeEventHistory(ukm::SourceIdObj source_id);
    ChargeEventHistory(ChargeEventHistory&&);
    ChargeEventHistory& operator=(ChargeEventHistory&&);
    ~ChargeEventHistory() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17021732261447222699);

    static const char kChargeEventHistoryDurationName[];
    static constexpr uint64_t kChargeEventHistoryDurationNameHash = UINT64_C(1447103198500926653);
    ChargeEventHistory& SetChargeEventHistoryDuration(int64_t value);

    static const char kChargeEventHistoryIndexName[];
    static constexpr uint64_t kChargeEventHistoryIndexNameHash = UINT64_C(7240370364469268936);
    ChargeEventHistory& SetChargeEventHistoryIndex(int64_t value);

    static const char kChargeEventHistorySizeName[];
    static constexpr uint64_t kChargeEventHistorySizeNameHash = UINT64_C(18319669744445197381);
    ChargeEventHistory& SetChargeEventHistorySize(int64_t value);

    static const char kChargeEventHistoryStartTimeName[];
    static constexpr uint64_t kChargeEventHistoryStartTimeNameHash = UINT64_C(4994371636112116544);
    ChargeEventHistory& SetChargeEventHistoryStartTime(int64_t value);

    static const char kEventIdName[];
    static constexpr uint64_t kEventIdNameHash = UINT64_C(8388046208606800177);
    ChargeEventHistory& SetEventId(int64_t value);
};

class ChromeOS_DeviceManagement final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOS_DeviceManagement(ukm::SourceId source_id);
    explicit ChromeOS_DeviceManagement(ukm::SourceIdObj source_id);
    ChromeOS_DeviceManagement(ChromeOS_DeviceManagement&&);
    ChromeOS_DeviceManagement& operator=(ChromeOS_DeviceManagement&&);
    ~ChromeOS_DeviceManagement() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1896298827856298513);

    static const char kEnrollmentStatusName[];
    static constexpr uint64_t kEnrollmentStatusNameHash = UINT64_C(15149595284067252509);
    ChromeOS_DeviceManagement& SetEnrollmentStatus(int64_t value);
};

class ChromeOS_WebsiteUsageTime final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOS_WebsiteUsageTime(ukm::SourceId source_id);
    explicit ChromeOS_WebsiteUsageTime(ukm::SourceIdObj source_id);
    ChromeOS_WebsiteUsageTime(ChromeOS_WebsiteUsageTime&&);
    ChromeOS_WebsiteUsageTime& operator=(ChromeOS_WebsiteUsageTime&&);
    ~ChromeOS_WebsiteUsageTime() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4043047938625792161);

    static const char kDurationName[];
    static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
    ChromeOS_WebsiteUsageTime& SetDuration(int64_t value);

    static const char kIsFromLastLoginName[];
    static constexpr uint64_t kIsFromLastLoginNameHash = UINT64_C(4812910790621279734);
    ChromeOS_WebsiteUsageTime& SetIsFromLastLogin(int64_t value);

    static const char kPromotableName[];
    static constexpr uint64_t kPromotableNameHash = UINT64_C(16843428730026040799);
    ChromeOS_WebsiteUsageTime& SetPromotable(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOS_WebsiteUsageTime& SetUserDeviceMatrix(int64_t value);
};

class ChromeOSApp_InputEvent final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOSApp_InputEvent(ukm::SourceId source_id);
    explicit ChromeOSApp_InputEvent(ukm::SourceIdObj source_id);
    ChromeOSApp_InputEvent(ChromeOSApp_InputEvent&&);
    ChromeOSApp_InputEvent& operator=(ChromeOSApp_InputEvent&&);
    ~ChromeOSApp_InputEvent() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16604269996013569427);

    static const char kAppInputEventCountName[];
    static constexpr uint64_t kAppInputEventCountNameHash = UINT64_C(11827765306053959789);
    ChromeOSApp_InputEvent& SetAppInputEventCount(int64_t value);

    static const char kAppInputEventSourceName[];
    static constexpr uint64_t kAppInputEventSourceNameHash = UINT64_C(3067113818996271433);
    ChromeOSApp_InputEvent& SetAppInputEventSource(int64_t value);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    ChromeOSApp_InputEvent& SetAppType(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOSApp_InputEvent& SetUserDeviceMatrix(int64_t value);
};

class ChromeOSApp_InstalledApp final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOSApp_InstalledApp(ukm::SourceId source_id);
    explicit ChromeOSApp_InstalledApp(ukm::SourceIdObj source_id);
    ChromeOSApp_InstalledApp(ChromeOSApp_InstalledApp&&);
    ChromeOSApp_InstalledApp& operator=(ChromeOSApp_InstalledApp&&);
    ~ChromeOSApp_InstalledApp() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13143522973299484729);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    ChromeOSApp_InstalledApp& SetAppType(int64_t value);

    static const char kInstallReasonName[];
    static constexpr uint64_t kInstallReasonNameHash = UINT64_C(1281400133578045381);
    ChromeOSApp_InstalledApp& SetInstallReason(int64_t value);

    static const char kInstallSource2Name[];
    static constexpr uint64_t kInstallSource2NameHash = UINT64_C(4450116641290682837);
    ChromeOSApp_InstalledApp& SetInstallSource2(int64_t value);

    static const char kInstallTimeName[];
    static constexpr uint64_t kInstallTimeNameHash = UINT64_C(5107598874981245590);
    ChromeOSApp_InstalledApp& SetInstallTime(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOSApp_InstalledApp& SetUserDeviceMatrix(int64_t value);
};

class ChromeOSApp_Launch final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOSApp_Launch(ukm::SourceId source_id);
    explicit ChromeOSApp_Launch(ukm::SourceIdObj source_id);
    ChromeOSApp_Launch(ChromeOSApp_Launch&&);
    ChromeOSApp_Launch& operator=(ChromeOSApp_Launch&&);
    ~ChromeOSApp_Launch() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16690478234560038417);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    ChromeOSApp_Launch& SetAppType(int64_t value);

    static const char kLaunchSourceName[];
    static constexpr uint64_t kLaunchSourceNameHash = UINT64_C(5360095524695749322);
    ChromeOSApp_Launch& SetLaunchSource(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOSApp_Launch& SetUserDeviceMatrix(int64_t value);
};

class ChromeOSApp_UninstallApp final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOSApp_UninstallApp(ukm::SourceId source_id);
    explicit ChromeOSApp_UninstallApp(ukm::SourceIdObj source_id);
    ChromeOSApp_UninstallApp(ChromeOSApp_UninstallApp&&);
    ChromeOSApp_UninstallApp& operator=(ChromeOSApp_UninstallApp&&);
    ~ChromeOSApp_UninstallApp() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7097858366631929652);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    ChromeOSApp_UninstallApp& SetAppType(int64_t value);

    static const char kUninstallSourceName[];
    static constexpr uint64_t kUninstallSourceNameHash = UINT64_C(8215808397380782455);
    ChromeOSApp_UninstallApp& SetUninstallSource(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOSApp_UninstallApp& SetUserDeviceMatrix(int64_t value);
};

class ChromeOSApp_UsageTime final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOSApp_UsageTime(ukm::SourceId source_id);
    explicit ChromeOSApp_UsageTime(ukm::SourceIdObj source_id);
    ChromeOSApp_UsageTime(ChromeOSApp_UsageTime&&);
    ChromeOSApp_UsageTime& operator=(ChromeOSApp_UsageTime&&);
    ~ChromeOSApp_UsageTime() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2647010623881481336);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    ChromeOSApp_UsageTime& SetAppType(int64_t value);

    static const char kDurationName[];
    static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
    ChromeOSApp_UsageTime& SetDuration(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOSApp_UsageTime& SetUserDeviceMatrix(int64_t value);
};

class ChromeOSApp_UsageTimeReusedSourceId final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ChromeOSApp_UsageTimeReusedSourceId(ukm::SourceId source_id);
    explicit ChromeOSApp_UsageTimeReusedSourceId(ukm::SourceIdObj source_id);
    ChromeOSApp_UsageTimeReusedSourceId(ChromeOSApp_UsageTimeReusedSourceId&&);
    ChromeOSApp_UsageTimeReusedSourceId& operator=(ChromeOSApp_UsageTimeReusedSourceId&&);
    ~ChromeOSApp_UsageTimeReusedSourceId() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(72420250988622518);

    static const char kAppTypeName[];
    static constexpr uint64_t kAppTypeNameHash = UINT64_C(8663828604683851647);
    ChromeOSApp_UsageTimeReusedSourceId& SetAppType(int64_t value);

    static const char kDurationName[];
    static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
    ChromeOSApp_UsageTimeReusedSourceId& SetDuration(int64_t value);

    static const char kUserDeviceMatrixName[];
    static constexpr uint64_t kUserDeviceMatrixNameHash = UINT64_C(9998511329284805547);
    ChromeOSApp_UsageTimeReusedSourceId& SetUserDeviceMatrix(int64_t value);
};

class ClickInput final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClickInput(ukm::SourceId source_id);
    explicit ClickInput(ukm::SourceIdObj source_id);
    ClickInput(ClickInput&&);
    ClickInput& operator=(ClickInput&&);
    ~ClickInput() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(18270520290100355082);

    static const char kExperimental_ClickInputBurstName[];
    static constexpr uint64_t kExperimental_ClickInputBurstNameHash = UINT64_C(15140487667339141216);
    ClickInput& SetExperimental_ClickInputBurst(int64_t value);
};

class ClientHints_AcceptCHFrameUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClientHints_AcceptCHFrameUsage(ukm::SourceId source_id);
    explicit ClientHints_AcceptCHFrameUsage(ukm::SourceIdObj source_id);
    ClientHints_AcceptCHFrameUsage(ClientHints_AcceptCHFrameUsage&&);
    ClientHints_AcceptCHFrameUsage& operator=(ClientHints_AcceptCHFrameUsage&&);
    ~ClientHints_AcceptCHFrameUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1670115342895886069);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    ClientHints_AcceptCHFrameUsage& SetType(int64_t value);
};

class ClientHints_AcceptCHHeaderUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClientHints_AcceptCHHeaderUsage(ukm::SourceId source_id);
    explicit ClientHints_AcceptCHHeaderUsage(ukm::SourceIdObj source_id);
    ClientHints_AcceptCHHeaderUsage(ClientHints_AcceptCHHeaderUsage&&);
    ClientHints_AcceptCHHeaderUsage& operator=(ClientHints_AcceptCHHeaderUsage&&);
    ~ClientHints_AcceptCHHeaderUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6137790577840170170);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    ClientHints_AcceptCHHeaderUsage& SetType(int64_t value);
};

class ClientHints_AcceptCHMetaUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClientHints_AcceptCHMetaUsage(ukm::SourceId source_id);
    explicit ClientHints_AcceptCHMetaUsage(ukm::SourceIdObj source_id);
    ClientHints_AcceptCHMetaUsage(ClientHints_AcceptCHMetaUsage&&);
    ClientHints_AcceptCHMetaUsage& operator=(ClientHints_AcceptCHMetaUsage&&);
    ~ClientHints_AcceptCHMetaUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4925937897339251251);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    ClientHints_AcceptCHMetaUsage& SetType(int64_t value);
};

class ClientHints_CriticalCHHeaderUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClientHints_CriticalCHHeaderUsage(ukm::SourceId source_id);
    explicit ClientHints_CriticalCHHeaderUsage(ukm::SourceIdObj source_id);
    ClientHints_CriticalCHHeaderUsage(ClientHints_CriticalCHHeaderUsage&&);
    ClientHints_CriticalCHHeaderUsage& operator=(ClientHints_CriticalCHHeaderUsage&&);
    ~ClientHints_CriticalCHHeaderUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5294132008219398422);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    ClientHints_CriticalCHHeaderUsage& SetType(int64_t value);
};

class ClientHints_DelegateCHMetaUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClientHints_DelegateCHMetaUsage(ukm::SourceId source_id);
    explicit ClientHints_DelegateCHMetaUsage(ukm::SourceIdObj source_id);
    ClientHints_DelegateCHMetaUsage(ClientHints_DelegateCHMetaUsage&&);
    ClientHints_DelegateCHMetaUsage& operator=(ClientHints_DelegateCHMetaUsage&&);
    ~ClientHints_DelegateCHMetaUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11815588195090653537);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    ClientHints_DelegateCHMetaUsage& SetType(int64_t value);
};

class ClientRenderingAPI final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ClientRenderingAPI(ukm::SourceId source_id);
    explicit ClientRenderingAPI(ukm::SourceIdObj source_id);
    ClientRenderingAPI(ClientRenderingAPI&&);
    ClientRenderingAPI& operator=(ClientRenderingAPI&&);
    ~ClientRenderingAPI() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(528939567029470806);

    static const char kCanvas_RenderingContextName[];
    static constexpr uint64_t kCanvas_RenderingContextNameHash = UINT64_C(4637085183716198224);
    ClientRenderingAPI& SetCanvas_RenderingContext(int64_t value);

    static const char kCanvas_RenderingContextDrawnToName[];
    static constexpr uint64_t kCanvas_RenderingContextDrawnToNameHash = UINT64_C(18343045065676680559);
    ClientRenderingAPI& SetCanvas_RenderingContextDrawnTo(int64_t value);

    static const char kGPUDeviceName[];
    static constexpr uint64_t kGPUDeviceNameHash = UINT64_C(11346406363981858741);
    ClientRenderingAPI& SetGPUDevice(int64_t value);

    static const char kOffscreenCanvas_RenderingContextName[];
    static constexpr uint64_t kOffscreenCanvas_RenderingContextNameHash = UINT64_C(9150383311060652241);
    ClientRenderingAPI& SetOffscreenCanvas_RenderingContext(int64_t value);

    static const char kOffscreenCanvas_RenderingContextDrawnToName[];
    static constexpr uint64_t kOffscreenCanvas_RenderingContextDrawnToNameHash = UINT64_C(14178529242739198383);
    ClientRenderingAPI& SetOffscreenCanvas_RenderingContextDrawnTo(int64_t value);
};

class Companion_PageView final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Companion_PageView(ukm::SourceId source_id);
    explicit Companion_PageView(ukm::SourceIdObj source_id);
    Companion_PageView(Companion_PageView&&);
    Companion_PageView& operator=(Companion_PageView&&);
    ~Companion_PageView() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12263546160415692682);

    static const char kATX_ComponentPositionName[];
    static constexpr uint64_t kATX_ComponentPositionNameHash = UINT64_C(8026851268194452954);
    Companion_PageView& SetATX_ComponentPosition(int64_t value);

    static const char kATX_LastEventName[];
    static constexpr uint64_t kATX_LastEventNameHash = UINT64_C(14366067362915593881);
    Companion_PageView& SetATX_LastEvent(int64_t value);

    static const char kCQ_ClickPositionName[];
    static constexpr uint64_t kCQ_ClickPositionNameHash = UINT64_C(7104540026040963859);
    Companion_PageView& SetCQ_ClickPosition(int64_t value);

    static const char kCQ_ComponentPositionName[];
    static constexpr uint64_t kCQ_ComponentPositionNameHash = UINT64_C(14984889174207599474);
    Companion_PageView& SetCQ_ComponentPosition(int64_t value);

    static const char kCQ_LastEventName[];
    static constexpr uint64_t kCQ_LastEventNameHash = UINT64_C(11208466998787750890);
    Companion_PageView& SetCQ_LastEvent(int64_t value);

    static const char kCQ_NumEntriesAvailableName[];
    static constexpr uint64_t kCQ_NumEntriesAvailableNameHash = UINT64_C(11068753141556540684);
    Companion_PageView& SetCQ_NumEntriesAvailable(int64_t value);

    static const char kCQ_NumEntriesShownName[];
    static constexpr uint64_t kCQ_NumEntriesShownNameHash = UINT64_C(10234954390026280465);
    Companion_PageView& SetCQ_NumEntriesShown(int64_t value);

    static const char kOpenTriggerName[];
    static constexpr uint64_t kOpenTriggerNameHash = UINT64_C(4216281009882818848);
    Companion_PageView& SetOpenTrigger(int64_t value);

    static const char kPageEntities_ClickPositionName[];
    static constexpr uint64_t kPageEntities_ClickPositionNameHash = UINT64_C(4298043646499375886);
    Companion_PageView& SetPageEntities_ClickPosition(int64_t value);

    static const char kPageEntities_ComponentPositionName[];
    static constexpr uint64_t kPageEntities_ComponentPositionNameHash = UINT64_C(17497699017665466468);
    Companion_PageView& SetPageEntities_ComponentPosition(int64_t value);

    static const char kPageEntities_LastEventName[];
    static constexpr uint64_t kPageEntities_LastEventNameHash = UINT64_C(9105068204411189860);
    Companion_PageView& SetPageEntities_LastEvent(int64_t value);

    static const char kPageEntities_NumEntriesAvailableName[];
    static constexpr uint64_t kPageEntities_NumEntriesAvailableNameHash = UINT64_C(12845636651041862832);
    Companion_PageView& SetPageEntities_NumEntriesAvailable(int64_t value);

    static const char kPageEntities_NumEntriesShownName[];
    static constexpr uint64_t kPageEntities_NumEntriesShownNameHash = UINT64_C(10925544746474186815);
    Companion_PageView& SetPageEntities_NumEntriesShown(int64_t value);

    static const char kPH_ComponentPositionName[];
    static constexpr uint64_t kPH_ComponentPositionNameHash = UINT64_C(5149980882555086404);
    Companion_PageView& SetPH_ComponentPosition(int64_t value);

    static const char kPH_FeedbackName[];
    static constexpr uint64_t kPH_FeedbackNameHash = UINT64_C(7015463440781626339);
    Companion_PageView& SetPH_Feedback(int64_t value);

    static const char kPH_LastEventName[];
    static constexpr uint64_t kPH_LastEventNameHash = UINT64_C(3846349067990137622);
    Companion_PageView& SetPH_LastEvent(int64_t value);

    static const char kPHResult_ClickPositionName[];
    static constexpr uint64_t kPHResult_ClickPositionNameHash = UINT64_C(3771704585522332114);
    Companion_PageView& SetPHResult_ClickPosition(int64_t value);

    static const char kPHResult_ComponentPositionName[];
    static constexpr uint64_t kPHResult_ComponentPositionNameHash = UINT64_C(11641598518334225908);
    Companion_PageView& SetPHResult_ComponentPosition(int64_t value);

    static const char kPHResult_LastEventName[];
    static constexpr uint64_t kPHResult_LastEventNameHash = UINT64_C(5056628958551679431);
    Companion_PageView& SetPHResult_LastEvent(int64_t value);

    static const char kPHResult_NumEntriesAvailableName[];
    static constexpr uint64_t kPHResult_NumEntriesAvailableNameHash = UINT64_C(16639287815864981768);
    Companion_PageView& SetPHResult_NumEntriesAvailable(int64_t value);

    static const char kPHResult_NumEntriesShownName[];
    static constexpr uint64_t kPHResult_NumEntriesShownNameHash = UINT64_C(10964900772175662373);
    Companion_PageView& SetPHResult_NumEntriesShown(int64_t value);

    static const char kPromoEventName[];
    static constexpr uint64_t kPromoEventNameHash = UINT64_C(15015205867476896899);
    Companion_PageView& SetPromoEvent(int64_t value);

    static const char kRegionSearch_ClickCountName[];
    static constexpr uint64_t kRegionSearch_ClickCountNameHash = UINT64_C(7776423893624098810);
    Companion_PageView& SetRegionSearch_ClickCount(int64_t value);

    static const char kRelQr_ClickPositionName[];
    static constexpr uint64_t kRelQr_ClickPositionNameHash = UINT64_C(2047068065775692352);
    Companion_PageView& SetRelQr_ClickPosition(int64_t value);

    static const char kRelQr_ComponentPositionName[];
    static constexpr uint64_t kRelQr_ComponentPositionNameHash = UINT64_C(7386891832180779268);
    Companion_PageView& SetRelQr_ComponentPosition(int64_t value);

    static const char kRelQr_LastEventName[];
    static constexpr uint64_t kRelQr_LastEventNameHash = UINT64_C(11832871943397401478);
    Companion_PageView& SetRelQr_LastEvent(int64_t value);

    static const char kRelQr_NumEntriesAvailableName[];
    static constexpr uint64_t kRelQr_NumEntriesAvailableNameHash = UINT64_C(4365905159486022969);
    Companion_PageView& SetRelQr_NumEntriesAvailable(int64_t value);

    static const char kRelQr_NumEntriesShownName[];
    static constexpr uint64_t kRelQr_NumEntriesShownNameHash = UINT64_C(12153621185518643443);
    Companion_PageView& SetRelQr_NumEntriesShown(int64_t value);

    static const char kRelQs_ClickPositionName[];
    static constexpr uint64_t kRelQs_ClickPositionNameHash = UINT64_C(317425885387829215);
    Companion_PageView& SetRelQs_ClickPosition(int64_t value);

    static const char kRelQs_ComponentPositionName[];
    static constexpr uint64_t kRelQs_ComponentPositionNameHash = UINT64_C(15944827793802012106);
    Companion_PageView& SetRelQs_ComponentPosition(int64_t value);

    static const char kRelQs_LastEventName[];
    static constexpr uint64_t kRelQs_LastEventNameHash = UINT64_C(4219165126465896204);
    Companion_PageView& SetRelQs_LastEvent(int64_t value);

    static const char kRelQs_NumEntriesAvailableName[];
    static constexpr uint64_t kRelQs_NumEntriesAvailableNameHash = UINT64_C(3039948800523943296);
    Companion_PageView& SetRelQs_NumEntriesAvailable(int64_t value);

    static const char kRelQs_NumEntriesShownName[];
    static constexpr uint64_t kRelQs_NumEntriesShownNameHash = UINT64_C(10485906172394785772);
    Companion_PageView& SetRelQs_NumEntriesShown(int64_t value);

    static const char kTextSearchCountName[];
    static constexpr uint64_t kTextSearchCountNameHash = UINT64_C(10980706610597055127);
    Companion_PageView& SetTextSearchCount(int64_t value);

    static const char kVQ_ClickPositionName[];
    static constexpr uint64_t kVQ_ClickPositionNameHash = UINT64_C(7013970721202722954);
    Companion_PageView& SetVQ_ClickPosition(int64_t value);

    static const char kVQ_ComponentPositionName[];
    static constexpr uint64_t kVQ_ComponentPositionNameHash = UINT64_C(9837864047962483776);
    Companion_PageView& SetVQ_ComponentPosition(int64_t value);

    static const char kVQ_LastEventName[];
    static constexpr uint64_t kVQ_LastEventNameHash = UINT64_C(1517940785413811411);
    Companion_PageView& SetVQ_LastEvent(int64_t value);

    static const char kVQ_NumEntriesAvailableName[];
    static constexpr uint64_t kVQ_NumEntriesAvailableNameHash = UINT64_C(5519833055420872622);
    Companion_PageView& SetVQ_NumEntriesAvailable(int64_t value);

    static const char kVQ_NumEntriesShownName[];
    static constexpr uint64_t kVQ_NumEntriesShownNameHash = UINT64_C(17679889327123544415);
    Companion_PageView& SetVQ_NumEntriesShown(int64_t value);

    static const char kVQS_ImageSensitiveCountName[];
    static constexpr uint64_t kVQS_ImageSensitiveCountNameHash = UINT64_C(2421363452766336231);
    Companion_PageView& SetVQS_ImageSensitiveCount(int64_t value);

    static const char kVQS_ImageShoppyCountName[];
    static constexpr uint64_t kVQS_ImageShoppyCountNameHash = UINT64_C(15968558869421320656);
    Companion_PageView& SetVQS_ImageShoppyCount(int64_t value);

    static const char kVQS_ImageShoppyNotSensitiveCountName[];
    static constexpr uint64_t kVQS_ImageShoppyNotSensitiveCountNameHash = UINT64_C(15873197863861898616);
    Companion_PageView& SetVQS_ImageShoppyNotSensitiveCount(int64_t value);

    static const char kVQS_VisualEligibleImagesCountName[];
    static constexpr uint64_t kVQS_VisualEligibleImagesCountNameHash = UINT64_C(17771387450468210372);
    Companion_PageView& SetVQS_VisualEligibleImagesCount(int64_t value);

    static const char kVQS_VisualSearchTriggeredCountName[];
    static constexpr uint64_t kVQS_VisualSearchTriggeredCountNameHash = UINT64_C(3486283143025393680);
    Companion_PageView& SetVQS_VisualSearchTriggeredCount(int64_t value);
};

class Compose_PageEvents final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Compose_PageEvents(ukm::SourceId source_id);
    explicit Compose_PageEvents(ukm::SourceIdObj source_id);
    Compose_PageEvents(Compose_PageEvents&&);
    Compose_PageEvents& operator=(Compose_PageEvents&&);
    ~Compose_PageEvents() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3985288542356389988);

    static const char kComposeTextInsertedName[];
    static constexpr uint64_t kComposeTextInsertedNameHash = UINT64_C(1529883372102930552);
    Compose_PageEvents& SetComposeTextInserted(int64_t value);

    static const char kMenuItemClickedName[];
    static constexpr uint64_t kMenuItemClickedNameHash = UINT64_C(7152270533230000254);
    Compose_PageEvents& SetMenuItemClicked(int64_t value);

    static const char kMenuItemShownName[];
    static constexpr uint64_t kMenuItemShownNameHash = UINT64_C(1164620438642242488);
    Compose_PageEvents& SetMenuItemShown(int64_t value);

    static const char kMissingFormDataName[];
    static constexpr uint64_t kMissingFormDataNameHash = UINT64_C(9868356957895905469);
    Compose_PageEvents& SetMissingFormData(int64_t value);

    static const char kMissingFormFieldDataName[];
    static constexpr uint64_t kMissingFormFieldDataNameHash = UINT64_C(16672330768134080229);
    Compose_PageEvents& SetMissingFormFieldData(int64_t value);

    static const char kProactiveNudgeDisabledForSiteName[];
    static constexpr uint64_t kProactiveNudgeDisabledForSiteNameHash = UINT64_C(8761267236189481864);
    Compose_PageEvents& SetProactiveNudgeDisabledForSite(int64_t value);

    static const char kProactiveNudgeDisabledGloballyName[];
    static constexpr uint64_t kProactiveNudgeDisabledGloballyNameHash = UINT64_C(8462099075485472126);
    Compose_PageEvents& SetProactiveNudgeDisabledGlobally(int64_t value);

    static const char kProactiveNudgeOpenedName[];
    static constexpr uint64_t kProactiveNudgeOpenedNameHash = UINT64_C(1864878521589838907);
    Compose_PageEvents& SetProactiveNudgeOpened(int64_t value);

    static const char kProactiveNudgeShouldShowName[];
    static constexpr uint64_t kProactiveNudgeShouldShowNameHash = UINT64_C(10941975916766112718);
    Compose_PageEvents& SetProactiveNudgeShouldShow(int64_t value);

    static const char kProactiveNudgeShownName[];
    static constexpr uint64_t kProactiveNudgeShownNameHash = UINT64_C(375036935792169405);
    Compose_PageEvents& SetProactiveNudgeShown(int64_t value);
};

class Compose_SessionProgress final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Compose_SessionProgress(ukm::SourceId source_id);
    explicit Compose_SessionProgress(ukm::SourceIdObj source_id);
    Compose_SessionProgress(Compose_SessionProgress&&);
    Compose_SessionProgress& operator=(Compose_SessionProgress&&);
    ~Compose_SessionProgress() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17644213575895096611);

    static const char kCanceledName[];
    static constexpr uint64_t kCanceledNameHash = UINT64_C(1018656279737460067);
    Compose_SessionProgress& SetCanceled(int64_t value);

    static const char kCasualCountName[];
    static constexpr uint64_t kCasualCountNameHash = UINT64_C(7409548365602751944);
    Compose_SessionProgress& SetCasualCount(int64_t value);

    static const char kComposeCountName[];
    static constexpr uint64_t kComposeCountNameHash = UINT64_C(2221417367890112149);
    Compose_SessionProgress& SetComposeCount(int64_t value);

    static const char kDialogShownCountName[];
    static constexpr uint64_t kDialogShownCountNameHash = UINT64_C(12484289827565314066);
    Compose_SessionProgress& SetDialogShownCount(int64_t value);

    static const char kFormalCountName[];
    static constexpr uint64_t kFormalCountNameHash = UINT64_C(783152929378883966);
    Compose_SessionProgress& SetFormalCount(int64_t value);

    static const char kInsertedResultsName[];
    static constexpr uint64_t kInsertedResultsNameHash = UINT64_C(13028887832255837841);
    Compose_SessionProgress& SetInsertedResults(int64_t value);

    static const char kLengthenCountName[];
    static constexpr uint64_t kLengthenCountNameHash = UINT64_C(17478007101599605306);
    Compose_SessionProgress& SetLengthenCount(int64_t value);

    static const char kRegenerateCountName[];
    static constexpr uint64_t kRegenerateCountNameHash = UINT64_C(693581751111908086);
    Compose_SessionProgress& SetRegenerateCount(int64_t value);

    static const char kShortenCountName[];
    static constexpr uint64_t kShortenCountNameHash = UINT64_C(3786907751629834770);
    Compose_SessionProgress& SetShortenCount(int64_t value);

    static const char kStartedWithProactiveNudgeName[];
    static constexpr uint64_t kStartedWithProactiveNudgeNameHash = UINT64_C(17286217230020067961);
    Compose_SessionProgress& SetStartedWithProactiveNudge(int64_t value);

    static const char kUndoCountName[];
    static constexpr uint64_t kUndoCountNameHash = UINT64_C(11052334537289124941);
    Compose_SessionProgress& SetUndoCount(int64_t value);
};

class Compose_TextElementUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Compose_TextElementUsage(ukm::SourceId source_id);
    explicit Compose_TextElementUsage(ukm::SourceIdObj source_id);
    Compose_TextElementUsage(Compose_TextElementUsage&&);
    Compose_TextElementUsage& operator=(Compose_TextElementUsage&&);
    ~Compose_TextElementUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2872551356235666049);

    static const char kAutofillFormControlTypeName[];
    static constexpr uint64_t kAutofillFormControlTypeNameHash = UINT64_C(14754706597094045245);
    Compose_TextElementUsage& SetAutofillFormControlType(int64_t value);

    static const char kEditingTimeName[];
    static constexpr uint64_t kEditingTimeNameHash = UINT64_C(14875881222890763445);
    Compose_TextElementUsage& SetEditingTime(int64_t value);

    static const char kFieldSignatureName[];
    static constexpr uint64_t kFieldSignatureNameHash = UINT64_C(12548035803827306811);
    Compose_TextElementUsage& SetFieldSignature(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    Compose_TextElementUsage& SetFormSignature(int64_t value);

    static const char kIsAutofillFieldTypeName[];
    static constexpr uint64_t kIsAutofillFieldTypeNameHash = UINT64_C(10153299123261752463);
    Compose_TextElementUsage& SetIsAutofillFieldType(int64_t value);

    static const char kTypedCharacterCountName[];
    static constexpr uint64_t kTypedCharacterCountNameHash = UINT64_C(15472969950415499693);
    Compose_TextElementUsage& SetTypedCharacterCount(int64_t value);

    static const char kTypedWordCountName[];
    static constexpr uint64_t kTypedWordCountNameHash = UINT64_C(5655773007007417109);
    Compose_TextElementUsage& SetTypedWordCount(int64_t value);
};

class Compositor_Rendering final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Compositor_Rendering(ukm::SourceId source_id);
    explicit Compositor_Rendering(ukm::SourceIdObj source_id);
    Compositor_Rendering(Compositor_Rendering&&);
    Compositor_Rendering& operator=(Compositor_Rendering&&);
    ~Compositor_Rendering() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(18003859069234917647);

    static const char kCheckerboardedImagesCountName[];
    static constexpr uint64_t kCheckerboardedImagesCountNameHash = UINT64_C(1155611193130623091);
    Compositor_Rendering& SetCheckerboardedImagesCount(int64_t value);
};

class Compositor_UserInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Compositor_UserInteraction(ukm::SourceId source_id);
    explicit Compositor_UserInteraction(ukm::SourceIdObj source_id);
    Compositor_UserInteraction(Compositor_UserInteraction&&);
    Compositor_UserInteraction& operator=(Compositor_UserInteraction&&);
    ~Compositor_UserInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3378172330402895005);

    static const char kCheckerboardedContentAreaName[];
    static constexpr uint64_t kCheckerboardedContentAreaNameHash = UINT64_C(18364704041698110260);
    Compositor_UserInteraction& SetCheckerboardedContentArea(int64_t value);

    static const char kCheckerboardedContentAreaRatioName[];
    static constexpr uint64_t kCheckerboardedContentAreaRatioNameHash = UINT64_C(6812281970879011502);
    Compositor_UserInteraction& SetCheckerboardedContentAreaRatio(int64_t value);

    static const char kCheckerboardedImagesCountName[];
    static constexpr uint64_t kCheckerboardedImagesCountNameHash = UINT64_C(1155611193130623091);
    Compositor_UserInteraction& SetCheckerboardedImagesCount(int64_t value);

    static const char kNumMissingTilesName[];
    static constexpr uint64_t kNumMissingTilesNameHash = UINT64_C(14477360290938608899);
    Compositor_UserInteraction& SetNumMissingTiles(int64_t value);
};

class ContactsPicker_ShareStatistics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContactsPicker_ShareStatistics(ukm::SourceId source_id);
    explicit ContactsPicker_ShareStatistics(ukm::SourceIdObj source_id);
    ContactsPicker_ShareStatistics(ContactsPicker_ShareStatistics&&);
    ContactsPicker_ShareStatistics& operator=(ContactsPicker_ShareStatistics&&);
    ~ContactsPicker_ShareStatistics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11375675958515902207);

    static const char kPropertiesRequestedName[];
    static constexpr uint64_t kPropertiesRequestedNameHash = UINT64_C(18375281953152993238);
    ContactsPicker_ShareStatistics& SetPropertiesRequested(int64_t value);

    static const char kSelectCountName[];
    static constexpr uint64_t kSelectCountNameHash = UINT64_C(5527119260645369915);
    ContactsPicker_ShareStatistics& SetSelectCount(int64_t value);

    static const char kSelectPercentageName[];
    static constexpr uint64_t kSelectPercentageNameHash = UINT64_C(9795301071653640943);
    ContactsPicker_ShareStatistics& SetSelectPercentage(int64_t value);
};

class ContentIndex_Added final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContentIndex_Added(ukm::SourceId source_id);
    explicit ContentIndex_Added(ukm::SourceIdObj source_id);
    ContentIndex_Added(ContentIndex_Added&&);
    ContentIndex_Added& operator=(ContentIndex_Added&&);
    ~ContentIndex_Added() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7195670717417274603);

    static const char kCategoryName[];
    static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
    ContentIndex_Added& SetCategory(int64_t value);
};

class ContentIndex_DeletedByUser final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContentIndex_DeletedByUser(ukm::SourceId source_id);
    explicit ContentIndex_DeletedByUser(ukm::SourceIdObj source_id);
    ContentIndex_DeletedByUser(ContentIndex_DeletedByUser&&);
    ContentIndex_DeletedByUser& operator=(ContentIndex_DeletedByUser&&);
    ~ContentIndex_DeletedByUser() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8302809238691294596);

    static const char kDeletedName[];
    static constexpr uint64_t kDeletedNameHash = UINT64_C(6910211073230771657);
    ContentIndex_DeletedByUser& SetDeleted(int64_t value);
};

class ContentIndex_Opened final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContentIndex_Opened(ukm::SourceId source_id);
    explicit ContentIndex_Opened(ukm::SourceIdObj source_id);
    ContentIndex_Opened(ContentIndex_Opened&&);
    ContentIndex_Opened& operator=(ContentIndex_Opened&&);
    ~ContentIndex_Opened() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4039427715416584382);

    static const char kIsOfflineName[];
    static constexpr uint64_t kIsOfflineNameHash = UINT64_C(17298814962699281457);
    ContentIndex_Opened& SetIsOffline(int64_t value);
};

class ContentManagementSystemPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContentManagementSystemPageLoad(ukm::SourceId source_id);
    explicit ContentManagementSystemPageLoad(ukm::SourceIdObj source_id);
    ContentManagementSystemPageLoad(ContentManagementSystemPageLoad&&);
    ContentManagementSystemPageLoad& operator=(ContentManagementSystemPageLoad&&);
    ~ContentManagementSystemPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1004694677685087236);

    static const char kDrupalPageLoadName[];
    static constexpr uint64_t kDrupalPageLoadNameHash = UINT64_C(9983386745765459935);
    ContentManagementSystemPageLoad& SetDrupalPageLoad(int64_t value);

    static const char kJoomlaPageLoadName[];
    static constexpr uint64_t kJoomlaPageLoadNameHash = UINT64_C(5724997540514548764);
    ContentManagementSystemPageLoad& SetJoomlaPageLoad(int64_t value);

    static const char kShopifyPageLoadName[];
    static constexpr uint64_t kShopifyPageLoadNameHash = UINT64_C(7350853708099270688);
    ContentManagementSystemPageLoad& SetShopifyPageLoad(int64_t value);

    static const char kSquarespacePageLoadName[];
    static constexpr uint64_t kSquarespacePageLoadNameHash = UINT64_C(5369789598149388807);
    ContentManagementSystemPageLoad& SetSquarespacePageLoad(int64_t value);

    static const char kWixPageLoadName[];
    static constexpr uint64_t kWixPageLoadNameHash = UINT64_C(5085630226436734476);
    ContentManagementSystemPageLoad& SetWixPageLoad(int64_t value);

    static const char kWordPressPageLoadName[];
    static constexpr uint64_t kWordPressPageLoadNameHash = UINT64_C(8920973762019292497);
    ContentManagementSystemPageLoad& SetWordPressPageLoad(int64_t value);
};

class ContextMenuAndroid_Selected final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContextMenuAndroid_Selected(ukm::SourceId source_id);
    explicit ContextMenuAndroid_Selected(ukm::SourceIdObj source_id);
    ContextMenuAndroid_Selected(ContextMenuAndroid_Selected&&);
    ContextMenuAndroid_Selected& operator=(ContextMenuAndroid_Selected&&);
    ~ContextMenuAndroid_Selected() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1205887675013444985);

    static const char kActionName[];
    static constexpr uint64_t kActionNameHash = UINT64_C(21381969153622804);
    ContextMenuAndroid_Selected& SetAction(int64_t value);
};

class ContextMenuAndroid_Shown final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ContextMenuAndroid_Shown(ukm::SourceId source_id);
    explicit ContextMenuAndroid_Shown(ukm::SourceIdObj source_id);
    ContextMenuAndroid_Shown(ContextMenuAndroid_Shown&&);
    ContextMenuAndroid_Shown& operator=(ContextMenuAndroid_Shown&&);
    ~ContextMenuAndroid_Shown() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12646817710005836743);

    static const char kSearchByImageName[];
    static constexpr uint64_t kSearchByImageNameHash = UINT64_C(6108028259674083300);
    ContextMenuAndroid_Shown& SetSearchByImage(int64_t value);

    static const char kSearchWithGoogleLensName[];
    static constexpr uint64_t kSearchWithGoogleLensNameHash = UINT64_C(13660833589691996740);
    ContextMenuAndroid_Shown& SetSearchWithGoogleLens(int64_t value);

    static const char kShopWithGoogleLensName[];
    static constexpr uint64_t kShopWithGoogleLensNameHash = UINT64_C(8394054406851481398);
    ContextMenuAndroid_Shown& SetShopWithGoogleLens(int64_t value);

    static const char kShopWithGoogleLensChipName[];
    static constexpr uint64_t kShopWithGoogleLensChipNameHash = UINT64_C(307017728732963727);
    ContextMenuAndroid_Shown& SetShopWithGoogleLensChip(int64_t value);

    static const char kTranslateWithGoogleLensChipName[];
    static constexpr uint64_t kTranslateWithGoogleLensChipNameHash = UINT64_C(1156733219451370314);
    ContextMenuAndroid_Shown& SetTranslateWithGoogleLensChip(int64_t value);
};

class CookieHasNonAsciiCharacter final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit CookieHasNonAsciiCharacter(ukm::SourceId source_id);
    explicit CookieHasNonAsciiCharacter(ukm::SourceIdObj source_id);
    CookieHasNonAsciiCharacter(CookieHasNonAsciiCharacter&&);
    CookieHasNonAsciiCharacter& operator=(CookieHasNonAsciiCharacter&&);
    ~CookieHasNonAsciiCharacter() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17395284389490280523);

    static const char kNameName[];
    static constexpr uint64_t kNameNameHash = UINT64_C(5327248766486351172);
    CookieHasNonAsciiCharacter& SetName(int64_t value);

    static const char kValueName[];
    static constexpr uint64_t kValueNameHash = UINT64_C(7535087603100972091);
    CookieHasNonAsciiCharacter& SetValue(int64_t value);
};

class Cookies_Blocked_DueToOriginMismatch final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Cookies_Blocked_DueToOriginMismatch(ukm::SourceId source_id);
    explicit Cookies_Blocked_DueToOriginMismatch(ukm::SourceIdObj source_id);
    Cookies_Blocked_DueToOriginMismatch(Cookies_Blocked_DueToOriginMismatch&&);
    Cookies_Blocked_DueToOriginMismatch& operator=(Cookies_Blocked_DueToOriginMismatch&&);
    ~Cookies_Blocked_DueToOriginMismatch() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11473670249740636017);

    static const char kPortMismatchName[];
    static constexpr uint64_t kPortMismatchNameHash = UINT64_C(4331588188848799800);
    Cookies_Blocked_DueToOriginMismatch& SetPortMismatch(int64_t value);

    static const char kSchemeMismatchName[];
    static constexpr uint64_t kSchemeMismatchNameHash = UINT64_C(11529094954457655486);
    Cookies_Blocked_DueToOriginMismatch& SetSchemeMismatch(int64_t value);
};

class Cookies_FirstPartyPartitionedInCrossSiteContextV3 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Cookies_FirstPartyPartitionedInCrossSiteContextV3(ukm::SourceId source_id);
    explicit Cookies_FirstPartyPartitionedInCrossSiteContextV3(ukm::SourceIdObj source_id);
    Cookies_FirstPartyPartitionedInCrossSiteContextV3(Cookies_FirstPartyPartitionedInCrossSiteContextV3&&);
    Cookies_FirstPartyPartitionedInCrossSiteContextV3& operator=(Cookies_FirstPartyPartitionedInCrossSiteContextV3&&);
    ~Cookies_FirstPartyPartitionedInCrossSiteContextV3() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13189393161560362088);

    static const char kCookiePresentName[];
    static constexpr uint64_t kCookiePresentNameHash = UINT64_C(7098191299343393352);
    Cookies_FirstPartyPartitionedInCrossSiteContextV3& SetCookiePresent(int64_t value);
};

class CPUUsageMeasurement final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit CPUUsageMeasurement(ukm::SourceId source_id);
    explicit CPUUsageMeasurement(ukm::SourceIdObj source_id);
    CPUUsageMeasurement(CPUUsageMeasurement&&);
    CPUUsageMeasurement& operator=(CPUUsageMeasurement&&);
    ~CPUUsageMeasurement() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(988984496812825435);

    static const char kCPUUsageName[];
    static constexpr uint64_t kCPUUsageNameHash = UINT64_C(4766204289640456177);
    CPUUsageMeasurement& SetCPUUsage(int64_t value);

    static const char kEventTypeName[];
    static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
    CPUUsageMeasurement& SetEventType(int64_t value);

    static const char kIsVisibleName[];
    static constexpr uint64_t kIsVisibleNameHash = UINT64_C(1485165748725517792);
    CPUUsageMeasurement& SetIsVisible(int64_t value);

    static const char kNumberOfCoresidentTabsName[];
    static constexpr uint64_t kNumberOfCoresidentTabsNameHash = UINT64_C(9703380981804271394);
    CPUUsageMeasurement& SetNumberOfCoresidentTabs(int64_t value);

    static const char kObservationWindowSizeMsName[];
    static constexpr uint64_t kObservationWindowSizeMsNameHash = UINT64_C(73587915121421831);
    CPUUsageMeasurement& SetObservationWindowSizeMs(int64_t value);

    static const char kProcessUptimeMsName[];
    static constexpr uint64_t kProcessUptimeMsNameHash = UINT64_C(12996007208370462538);
    CPUUsageMeasurement& SetProcessUptimeMs(int64_t value);
};

class CrossOriginSubframeWithoutEmbeddingControl final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit CrossOriginSubframeWithoutEmbeddingControl(ukm::SourceId source_id);
    explicit CrossOriginSubframeWithoutEmbeddingControl(ukm::SourceIdObj source_id);
    CrossOriginSubframeWithoutEmbeddingControl(CrossOriginSubframeWithoutEmbeddingControl&&);
    CrossOriginSubframeWithoutEmbeddingControl& operator=(CrossOriginSubframeWithoutEmbeddingControl&&);
    ~CrossOriginSubframeWithoutEmbeddingControl() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15054308220608486353);

    static const char kSubframeEmbeddedName[];
    static constexpr uint64_t kSubframeEmbeddedNameHash = UINT64_C(5203601577682852063);
    CrossOriginSubframeWithoutEmbeddingControl& SetSubframeEmbedded(int64_t value);
};

class DailyChargeSummary final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DailyChargeSummary(ukm::SourceId source_id);
    explicit DailyChargeSummary(ukm::SourceIdObj source_id);
    DailyChargeSummary(DailyChargeSummary&&);
    DailyChargeSummary& operator=(DailyChargeSummary&&);
    ~DailyChargeSummary() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16118191348399710349);

    static const char kDailySummaryHoldTimeOnAcName[];
    static constexpr uint64_t kDailySummaryHoldTimeOnAcNameHash = UINT64_C(14199726382133622280);
    DailyChargeSummary& SetDailySummaryHoldTimeOnAc(int64_t value);

    static const char kDailySummaryIndexName[];
    static constexpr uint64_t kDailySummaryIndexNameHash = UINT64_C(2630954837482691208);
    DailyChargeSummary& SetDailySummaryIndex(int64_t value);

    static const char kDailySummaryNumDaysDistanceName[];
    static constexpr uint64_t kDailySummaryNumDaysDistanceNameHash = UINT64_C(17791925643640661812);
    DailyChargeSummary& SetDailySummaryNumDaysDistance(int64_t value);

    static const char kDailySummarySizeName[];
    static constexpr uint64_t kDailySummarySizeNameHash = UINT64_C(15823732571487929611);
    DailyChargeSummary& SetDailySummarySize(int64_t value);

    static const char kDailySummaryTimeFullOnAcName[];
    static constexpr uint64_t kDailySummaryTimeFullOnAcNameHash = UINT64_C(2139351908245000073);
    DailyChargeSummary& SetDailySummaryTimeFullOnAc(int64_t value);

    static const char kDailySummaryTimeOnAcName[];
    static constexpr uint64_t kDailySummaryTimeOnAcNameHash = UINT64_C(10161452711382136016);
    DailyChargeSummary& SetDailySummaryTimeOnAc(int64_t value);

    static const char kEventIdName[];
    static constexpr uint64_t kEventIdNameHash = UINT64_C(8388046208606800177);
    DailyChargeSummary& SetEventId(int64_t value);
};

class DataReductionProxy final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DataReductionProxy(ukm::SourceId source_id);
    explicit DataReductionProxy(ukm::SourceIdObj source_id);
    DataReductionProxy(DataReductionProxy&&);
    DataReductionProxy& operator=(DataReductionProxy&&);
    ~DataReductionProxy() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(26394013458683718);

    static const char kDataSaverPageUUIDName[];
    static constexpr uint64_t kDataSaverPageUUIDNameHash = UINT64_C(12817183208027107985);
    DataReductionProxy& SetDataSaverPageUUID(int64_t value);

    static const char kEstimatedOriginalNetworkBytesName[];
    static constexpr uint64_t kEstimatedOriginalNetworkBytesNameHash = UINT64_C(16999189648527820582);
    DataReductionProxy& SetEstimatedOriginalNetworkBytes(int64_t value);
};

class DevTools_Opened final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DevTools_Opened(ukm::SourceId source_id);
    explicit DevTools_Opened(ukm::SourceIdObj source_id);
    DevTools_Opened(DevTools_Opened&&);
    DevTools_Opened& operator=(DevTools_Opened&&);
    ~DevTools_Opened() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5460112050811125825);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    DevTools_Opened& SetHasOccurred(int64_t value);
};

class DIPS_ChainBegin final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_ChainBegin(ukm::SourceId source_id);
    explicit DIPS_ChainBegin(ukm::SourceIdObj source_id);
    DIPS_ChainBegin(DIPS_ChainBegin&&);
    DIPS_ChainBegin& operator=(DIPS_ChainBegin&&);
    ~DIPS_ChainBegin() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5320991773281187745);

    static const char kChainIdName[];
    static constexpr uint64_t kChainIdNameHash = UINT64_C(14235371006446327158);
    DIPS_ChainBegin& SetChainId(int64_t value);

    static const char kInitialAndFinalSitesSameName[];
    static constexpr uint64_t kInitialAndFinalSitesSameNameHash = UINT64_C(2870126779433127661);
    DIPS_ChainBegin& SetInitialAndFinalSitesSame(int64_t value);
};

class DIPS_ChainEnd final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_ChainEnd(ukm::SourceId source_id);
    explicit DIPS_ChainEnd(ukm::SourceIdObj source_id);
    DIPS_ChainEnd(DIPS_ChainEnd&&);
    DIPS_ChainEnd& operator=(DIPS_ChainEnd&&);
    ~DIPS_ChainEnd() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6946092153020974851);

    static const char kChainIdName[];
    static constexpr uint64_t kChainIdNameHash = UINT64_C(14235371006446327158);
    DIPS_ChainEnd& SetChainId(int64_t value);

    static const char kInitialAndFinalSitesSameName[];
    static constexpr uint64_t kInitialAndFinalSitesSameNameHash = UINT64_C(2870126779433127661);
    DIPS_ChainEnd& SetInitialAndFinalSitesSame(int64_t value);
};

class DIPS_Deletion final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_Deletion(ukm::SourceId source_id);
    explicit DIPS_Deletion(ukm::SourceIdObj source_id);
    DIPS_Deletion(DIPS_Deletion&&);
    DIPS_Deletion& operator=(DIPS_Deletion&&);
    ~DIPS_Deletion() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3655510906906408205);

    static const char kHasCookieExceptionName[];
    static constexpr uint64_t kHasCookieExceptionNameHash = UINT64_C(18014467115096973651);
    DIPS_Deletion& SetHasCookieException(int64_t value);

    static const char kIsDeletionEnabledName[];
    static constexpr uint64_t kIsDeletionEnabledNameHash = UINT64_C(4127216294855140550);
    DIPS_Deletion& SetIsDeletionEnabled(int64_t value);

    static const char kShouldBlockThirdPartyCookiesName[];
    static constexpr uint64_t kShouldBlockThirdPartyCookiesNameHash = UINT64_C(15429319331217236206);
    DIPS_Deletion& SetShouldBlockThirdPartyCookies(int64_t value);
};

class DIPS_NavigationFlowNode final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_NavigationFlowNode(ukm::SourceId source_id);
    explicit DIPS_NavigationFlowNode(ukm::SourceIdObj source_id);
    DIPS_NavigationFlowNode(DIPS_NavigationFlowNode&&);
    DIPS_NavigationFlowNode& operator=(DIPS_NavigationFlowNode&&);
    ~DIPS_NavigationFlowNode() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(481245041017727098);

    static const char kDidHaveSuccessfulWAAName[];
    static constexpr uint64_t kDidHaveSuccessfulWAANameHash = UINT64_C(7972495839579610809);
    DIPS_NavigationFlowNode& SetDidHaveSuccessfulWAA(int64_t value);

    static const char kDidHaveUserActivationName[];
    static constexpr uint64_t kDidHaveUserActivationNameHash = UINT64_C(17756820819260765374);
    DIPS_NavigationFlowNode& SetDidHaveUserActivation(int64_t value);

    static const char kVisitDurationMillisecondsName[];
    static constexpr uint64_t kVisitDurationMillisecondsNameHash = UINT64_C(15501375422769305931);
    DIPS_NavigationFlowNode& SetVisitDurationMilliseconds(int64_t value);

    static const char kWasEntryUserInitiatedName[];
    static constexpr uint64_t kWasEntryUserInitiatedNameHash = UINT64_C(12159983003748454612);
    DIPS_NavigationFlowNode& SetWasEntryUserInitiated(int64_t value);

    static const char kWasExitUserInitiatedName[];
    static constexpr uint64_t kWasExitUserInitiatedNameHash = UINT64_C(12670367287761885556);
    DIPS_NavigationFlowNode& SetWasExitUserInitiated(int64_t value);

    static const char kWereEntryAndExitRendererInitiatedName[];
    static constexpr uint64_t kWereEntryAndExitRendererInitiatedNameHash = UINT64_C(3819509353979374570);
    DIPS_NavigationFlowNode& SetWereEntryAndExitRendererInitiated(int64_t value);

    static const char kWerePreviousAndNextSiteSameName[];
    static constexpr uint64_t kWerePreviousAndNextSiteSameNameHash = UINT64_C(1527173308658455065);
    DIPS_NavigationFlowNode& SetWerePreviousAndNextSiteSame(int64_t value);
};

class DIPS_Redirect final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_Redirect(ukm::SourceId source_id);
    explicit DIPS_Redirect(ukm::SourceIdObj source_id);
    DIPS_Redirect(DIPS_Redirect&&);
    DIPS_Redirect& operator=(DIPS_Redirect&&);
    ~DIPS_Redirect() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15719730292389568123);

    static const char kChainIdName[];
    static constexpr uint64_t kChainIdNameHash = UINT64_C(14235371006446327158);
    DIPS_Redirect& SetChainId(int64_t value);

    static const char kClientBounceDelayName[];
    static constexpr uint64_t kClientBounceDelayNameHash = UINT64_C(12404651382509016907);
    DIPS_Redirect& SetClientBounceDelay(int64_t value);

    static const char kCookieAccessTypeName[];
    static constexpr uint64_t kCookieAccessTypeNameHash = UINT64_C(5955961854671352420);
    DIPS_Redirect& SetCookieAccessType(int64_t value);

    static const char kHasStickyActivationName[];
    static constexpr uint64_t kHasStickyActivationNameHash = UINT64_C(7189847282986580409);
    DIPS_Redirect& SetHasStickyActivation(int64_t value);

    static const char kInitialAndFinalSitesSameName[];
    static constexpr uint64_t kInitialAndFinalSitesSameNameHash = UINT64_C(2870126779433127661);
    DIPS_Redirect& SetInitialAndFinalSitesSame(int64_t value);

    static const char kIsPartialRedirectChainName[];
    static constexpr uint64_t kIsPartialRedirectChainNameHash = UINT64_C(15024867310570023965);
    DIPS_Redirect& SetIsPartialRedirectChain(int64_t value);

    static const char kRedirectAndFinalSiteSameName[];
    static constexpr uint64_t kRedirectAndFinalSiteSameNameHash = UINT64_C(16525948050615781443);
    DIPS_Redirect& SetRedirectAndFinalSiteSame(int64_t value);

    static const char kRedirectAndInitialSiteSameName[];
    static constexpr uint64_t kRedirectAndInitialSiteSameNameHash = UINT64_C(3292266005865575069);
    DIPS_Redirect& SetRedirectAndInitialSiteSame(int64_t value);

    static const char kRedirectChainIndexName[];
    static constexpr uint64_t kRedirectChainIndexNameHash = UINT64_C(14485461166890739371);
    DIPS_Redirect& SetRedirectChainIndex(int64_t value);

    static const char kRedirectChainLengthName[];
    static constexpr uint64_t kRedirectChainLengthNameHash = UINT64_C(15085417540273857827);
    DIPS_Redirect& SetRedirectChainLength(int64_t value);

    static const char kRedirectTypeName[];
    static constexpr uint64_t kRedirectTypeNameHash = UINT64_C(16169760589587797369);
    DIPS_Redirect& SetRedirectType(int64_t value);

    static const char kSiteEngagementLevelName[];
    static constexpr uint64_t kSiteEngagementLevelNameHash = UINT64_C(7434896235365170565);
    DIPS_Redirect& SetSiteEngagementLevel(int64_t value);

    static const char kWebAuthnAssertionRequestSucceededName[];
    static constexpr uint64_t kWebAuthnAssertionRequestSucceededNameHash = UINT64_C(15646288907003798494);
    DIPS_Redirect& SetWebAuthnAssertionRequestSucceeded(int64_t value);
};

class DIPS_SuspectedTrackerFlowEntrypoint final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_SuspectedTrackerFlowEntrypoint(ukm::SourceId source_id);
    explicit DIPS_SuspectedTrackerFlowEntrypoint(ukm::SourceIdObj source_id);
    DIPS_SuspectedTrackerFlowEntrypoint(DIPS_SuspectedTrackerFlowEntrypoint&&);
    DIPS_SuspectedTrackerFlowEntrypoint& operator=(DIPS_SuspectedTrackerFlowEntrypoint&&);
    ~DIPS_SuspectedTrackerFlowEntrypoint() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16212732140902898765);

    static const char kExitRedirectTypeName[];
    static constexpr uint64_t kExitRedirectTypeNameHash = UINT64_C(5685928804617422242);
    DIPS_SuspectedTrackerFlowEntrypoint& SetExitRedirectType(int64_t value);

    static const char kFlowIdName[];
    static constexpr uint64_t kFlowIdNameHash = UINT64_C(11615983711679266461);
    DIPS_SuspectedTrackerFlowEntrypoint& SetFlowId(int64_t value);
};

class DIPS_SuspectedTrackerFlowReferrer final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_SuspectedTrackerFlowReferrer(ukm::SourceId source_id);
    explicit DIPS_SuspectedTrackerFlowReferrer(ukm::SourceIdObj source_id);
    DIPS_SuspectedTrackerFlowReferrer(DIPS_SuspectedTrackerFlowReferrer&&);
    DIPS_SuspectedTrackerFlowReferrer& operator=(DIPS_SuspectedTrackerFlowReferrer&&);
    ~DIPS_SuspectedTrackerFlowReferrer() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6139758594329744253);

    static const char kFlowIdName[];
    static constexpr uint64_t kFlowIdNameHash = UINT64_C(11615983711679266461);
    DIPS_SuspectedTrackerFlowReferrer& SetFlowId(int64_t value);
};

class DIPS_TriggeringAction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_TriggeringAction(ukm::SourceId source_id);
    explicit DIPS_TriggeringAction(ukm::SourceIdObj source_id);
    DIPS_TriggeringAction(DIPS_TriggeringAction&&);
    DIPS_TriggeringAction& operator=(DIPS_TriggeringAction&&);
    ~DIPS_TriggeringAction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4781193942405335441);

    static const char kDidBounceName[];
    static constexpr uint64_t kDidBounceNameHash = UINT64_C(5334971918422712796);
    DIPS_TriggeringAction& SetDidBounce(int64_t value);

    static const char kDidStatefulBounceName[];
    static constexpr uint64_t kDidStatefulBounceNameHash = UINT64_C(11231371573011942798);
    DIPS_TriggeringAction& SetDidStatefulBounce(int64_t value);

    static const char kUsedStorageName[];
    static constexpr uint64_t kUsedStorageNameHash = UINT64_C(12144414623346730707);
    DIPS_TriggeringAction& SetUsedStorage(int64_t value);
};

class DIPS_TrustIndicator_InFlowInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DIPS_TrustIndicator_InFlowInteraction(ukm::SourceId source_id);
    explicit DIPS_TrustIndicator_InFlowInteraction(ukm::SourceIdObj source_id);
    DIPS_TrustIndicator_InFlowInteraction(DIPS_TrustIndicator_InFlowInteraction&&);
    DIPS_TrustIndicator_InFlowInteraction& operator=(DIPS_TrustIndicator_InFlowInteraction&&);
    ~DIPS_TrustIndicator_InFlowInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3444815615783303259);

    static const char kFlowIdName[];
    static constexpr uint64_t kFlowIdNameHash = UINT64_C(11615983711679266461);
    DIPS_TrustIndicator_InFlowInteraction& SetFlowId(int64_t value);
};

class DocumentCreated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit DocumentCreated(ukm::SourceId source_id);
    explicit DocumentCreated(ukm::SourceIdObj source_id);
    DocumentCreated(DocumentCreated&&);
    DocumentCreated& operator=(DocumentCreated&&);
    ~DocumentCreated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2704655726834470033);

    static const char kIsCrossOriginFrameName[];
    static constexpr uint64_t kIsCrossOriginFrameNameHash = UINT64_C(15054512686433939687);
    DocumentCreated& SetIsCrossOriginFrame(int64_t value);

    static const char kIsCrossSiteFrameName[];
    static constexpr uint64_t kIsCrossSiteFrameNameHash = UINT64_C(2664425578681353266);
    DocumentCreated& SetIsCrossSiteFrame(int64_t value);

    static const char kIsMainFrameName[];
    static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
    DocumentCreated& SetIsMainFrame(int64_t value);

    static const char kNavigationSourceIdName[];
    static constexpr uint64_t kNavigationSourceIdNameHash = UINT64_C(16809659592214455005);
    DocumentCreated& SetNavigationSourceId(int64_t value);
};

class Download_Completed final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Download_Completed(ukm::SourceId source_id);
    explicit Download_Completed(ukm::SourceIdObj source_id);
    Download_Completed(Download_Completed&&);
    Download_Completed& operator=(Download_Completed&&);
    ~Download_Completed() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9818692869640581957);

    static const char kBytesWastedName[];
    static constexpr uint64_t kBytesWastedNameHash = UINT64_C(13076198488342677109);
    Download_Completed& SetBytesWasted(int64_t value);

    static const char kDownloadIdName[];
    static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
    Download_Completed& SetDownloadId(int64_t value);

    static const char kResultingFileSizeName[];
    static constexpr uint64_t kResultingFileSizeNameHash = UINT64_C(9870186940406075265);
    Download_Completed& SetResultingFileSize(int64_t value);

    static const char kTimeSinceStartName[];
    static constexpr uint64_t kTimeSinceStartNameHash = UINT64_C(1379962242842370033);
    Download_Completed& SetTimeSinceStart(int64_t value);
};

class Download_Interrupted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Download_Interrupted(ukm::SourceId source_id);
    explicit Download_Interrupted(ukm::SourceIdObj source_id);
    Download_Interrupted(Download_Interrupted&&);
    Download_Interrupted& operator=(Download_Interrupted&&);
    ~Download_Interrupted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9706055097174303);

    static const char kBytesWastedName[];
    static constexpr uint64_t kBytesWastedNameHash = UINT64_C(13076198488342677109);
    Download_Interrupted& SetBytesWasted(int64_t value);

    static const char kChangeInFileSizeName[];
    static constexpr uint64_t kChangeInFileSizeNameHash = UINT64_C(16943406704139999114);
    Download_Interrupted& SetChangeInFileSize(int64_t value);

    static const char kDownloadIdName[];
    static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
    Download_Interrupted& SetDownloadId(int64_t value);

    static const char kReasonName[];
    static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
    Download_Interrupted& SetReason(int64_t value);

    static const char kResultingFileSizeName[];
    static constexpr uint64_t kResultingFileSizeNameHash = UINT64_C(9870186940406075265);
    Download_Interrupted& SetResultingFileSize(int64_t value);

    static const char kTimeSinceStartName[];
    static constexpr uint64_t kTimeSinceStartNameHash = UINT64_C(1379962242842370033);
    Download_Interrupted& SetTimeSinceStart(int64_t value);
};

class Download_Resumed final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Download_Resumed(ukm::SourceId source_id);
    explicit Download_Resumed(ukm::SourceIdObj source_id);
    Download_Resumed(Download_Resumed&&);
    Download_Resumed& operator=(Download_Resumed&&);
    ~Download_Resumed() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9188207819461355990);

    static const char kDownloadIdName[];
    static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
    Download_Resumed& SetDownloadId(int64_t value);

    static const char kModeName[];
    static constexpr uint64_t kModeNameHash = UINT64_C(7281166215790160128);
    Download_Resumed& SetMode(int64_t value);

    static const char kTimeSinceStartName[];
    static constexpr uint64_t kTimeSinceStartNameHash = UINT64_C(1379962242842370033);
    Download_Resumed& SetTimeSinceStart(int64_t value);
};

class Download_Started final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Download_Started(ukm::SourceId source_id);
    explicit Download_Started(ukm::SourceIdObj source_id);
    Download_Started(Download_Started&&);
    Download_Started& operator=(Download_Started&&);
    ~Download_Started() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2153997617158303225);

    static const char kDownloadConnectionSecurityName[];
    static constexpr uint64_t kDownloadConnectionSecurityNameHash = UINT64_C(1575516418771310819);
    Download_Started& SetDownloadConnectionSecurity(int64_t value);

    static const char kDownloadIdName[];
    static constexpr uint64_t kDownloadIdNameHash = UINT64_C(11576255866188961065);
    Download_Started& SetDownloadId(int64_t value);

    static const char kDownloadSourceName[];
    static constexpr uint64_t kDownloadSourceNameHash = UINT64_C(11957806128610167400);
    Download_Started& SetDownloadSource(int64_t value);

    static const char kFileTypeName[];
    static constexpr uint64_t kFileTypeNameHash = UINT64_C(1646892813222506878);
    Download_Started& SetFileType(int64_t value);

    static const char kIsSameHostDownloadName[];
    static constexpr uint64_t kIsSameHostDownloadNameHash = UINT64_C(11844668225816315716);
    Download_Started& SetIsSameHostDownload(int64_t value);
};

class Enterprise_Profile_Enrollment final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Enterprise_Profile_Enrollment(ukm::SourceId source_id);
    explicit Enterprise_Profile_Enrollment(ukm::SourceIdObj source_id);
    Enterprise_Profile_Enrollment(Enterprise_Profile_Enrollment&&);
    Enterprise_Profile_Enrollment& operator=(Enterprise_Profile_Enrollment&&);
    ~Enterprise_Profile_Enrollment() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15972247533344456664);

    static const char kIsUntrustedOidcRedirectName[];
    static constexpr uint64_t kIsUntrustedOidcRedirectNameHash = UINT64_C(6378769604951468609);
    Enterprise_Profile_Enrollment& SetIsUntrustedOidcRedirect(int64_t value);
};

class Event_Scroll final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Event_Scroll(ukm::SourceId source_id);
    explicit Event_Scroll(ukm::SourceIdObj source_id);
    Event_Scroll(Event_Scroll&&);
    Event_Scroll& operator=(Event_Scroll&&);
    ~Event_Scroll() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6161051744273924039);

    static const char kFrameCountName[];
    static constexpr uint64_t kFrameCountNameHash = UINT64_C(11025709895955198817);
    Event_Scroll& SetFrameCount(int64_t value);

    static const char kPredictorJankyFrameCountName[];
    static constexpr uint64_t kPredictorJankyFrameCountNameHash = UINT64_C(14344891341046870340);
    Event_Scroll& SetPredictorJankyFrameCount(int64_t value);

    static const char kScrollJank_DelayedFrameCountName[];
    static constexpr uint64_t kScrollJank_DelayedFrameCountNameHash = UINT64_C(14803884593954984455);
    Event_Scroll& SetScrollJank_DelayedFrameCount(int64_t value);

    static const char kScrollJank_MissedVsyncsMaxName[];
    static constexpr uint64_t kScrollJank_MissedVsyncsMaxNameHash = UINT64_C(15559361880138868442);
    Event_Scroll& SetScrollJank_MissedVsyncsMax(int64_t value);

    static const char kScrollJank_MissedVsyncsSumName[];
    static constexpr uint64_t kScrollJank_MissedVsyncsSumNameHash = UINT64_C(3253001738519110732);
    Event_Scroll& SetScrollJank_MissedVsyncsSum(int64_t value);

    static const char kVsyncCountName[];
    static constexpr uint64_t kVsyncCountNameHash = UINT64_C(10723582144283515744);
    Event_Scroll& SetVsyncCount(int64_t value);
};

class Event_ScrollJank_PredictorJank final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Event_ScrollJank_PredictorJank(ukm::SourceId source_id);
    explicit Event_ScrollJank_PredictorJank(ukm::SourceIdObj source_id);
    Event_ScrollJank_PredictorJank(Event_ScrollJank_PredictorJank&&);
    Event_ScrollJank_PredictorJank& operator=(Event_ScrollJank_PredictorJank&&);
    ~Event_ScrollJank_PredictorJank() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12205595443714861014);

    static const char kMaxDeltaName[];
    static constexpr uint64_t kMaxDeltaNameHash = UINT64_C(17545637207036206590);
    Event_ScrollJank_PredictorJank& SetMaxDelta(int64_t value);

    static const char kScrollUpdate_MissedVsync_FrameAboveJankyThreshold2Name[];
    static constexpr uint64_t kScrollUpdate_MissedVsync_FrameAboveJankyThreshold2NameHash = UINT64_C(14620028796937461493);
    Event_ScrollJank_PredictorJank& SetScrollUpdate_MissedVsync_FrameAboveJankyThreshold2(int64_t value);

    static const char kScrollUpdate_NoMissedVsync_FrameAboveJankyThreshold2Name[];
    static constexpr uint64_t kScrollUpdate_NoMissedVsync_FrameAboveJankyThreshold2NameHash = UINT64_C(15782093480730386868);
    Event_ScrollJank_PredictorJank& SetScrollUpdate_NoMissedVsync_FrameAboveJankyThreshold2(int64_t value);
};

class Extensions_BackgroundContentsCreated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Extensions_BackgroundContentsCreated(ukm::SourceId source_id);
    explicit Extensions_BackgroundContentsCreated(ukm::SourceIdObj source_id);
    Extensions_BackgroundContentsCreated(Extensions_BackgroundContentsCreated&&);
    Extensions_BackgroundContentsCreated& operator=(Extensions_BackgroundContentsCreated&&);
    ~Extensions_BackgroundContentsCreated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1380853390098998336);

    static const char kSeenName[];
    static constexpr uint64_t kSeenNameHash = UINT64_C(13981160609965317407);
    Extensions_BackgroundContentsCreated& SetSeen(int64_t value);
};

class Extensions_MV2ExtensionHandledInSoftDisable final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Extensions_MV2ExtensionHandledInSoftDisable(ukm::SourceId source_id);
    explicit Extensions_MV2ExtensionHandledInSoftDisable(ukm::SourceIdObj source_id);
    Extensions_MV2ExtensionHandledInSoftDisable(Extensions_MV2ExtensionHandledInSoftDisable&&);
    Extensions_MV2ExtensionHandledInSoftDisable& operator=(Extensions_MV2ExtensionHandledInSoftDisable&&);
    ~Extensions_MV2ExtensionHandledInSoftDisable() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6634692008901530734);

    static const char kActionName[];
    static constexpr uint64_t kActionNameHash = UINT64_C(21381969153622804);
    Extensions_MV2ExtensionHandledInSoftDisable& SetAction(int64_t value);
};

class Extensions_OnNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Extensions_OnNavigation(ukm::SourceId source_id);
    explicit Extensions_OnNavigation(ukm::SourceIdObj source_id);
    Extensions_OnNavigation(Extensions_OnNavigation&&);
    Extensions_OnNavigation& operator=(Extensions_OnNavigation&&);
    ~Extensions_OnNavigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12489573627374524023);

    static const char kDeclarativeNetRequestFeedbackPermissionCountName[];
    static constexpr uint64_t kDeclarativeNetRequestFeedbackPermissionCountNameHash = UINT64_C(15404373416506213664);
    Extensions_OnNavigation& SetDeclarativeNetRequestFeedbackPermissionCount(int64_t value);

    static const char kDeclarativeNetRequestPermissionCountName[];
    static constexpr uint64_t kDeclarativeNetRequestPermissionCountNameHash = UINT64_C(5890099923546806746);
    Extensions_OnNavigation& SetDeclarativeNetRequestPermissionCount(int64_t value);

    static const char kDeclarativeNetRequestWithHostAccessPermissionCountName[];
    static constexpr uint64_t kDeclarativeNetRequestWithHostAccessPermissionCountNameHash = UINT64_C(12260087892718786694);
    Extensions_OnNavigation& SetDeclarativeNetRequestWithHostAccessPermissionCount(int64_t value);

    static const char kDeclarativeWebRequestPermissionCountName[];
    static constexpr uint64_t kDeclarativeWebRequestPermissionCountNameHash = UINT64_C(18552730264776501);
    Extensions_OnNavigation& SetDeclarativeWebRequestPermissionCount(int64_t value);

    static const char kEnabledExtensionCountName[];
    static constexpr uint64_t kEnabledExtensionCountNameHash = UINT64_C(4875404951987157301);
    Extensions_OnNavigation& SetEnabledExtensionCount(int64_t value);

    static const char kEnabledExtensionCount_HaveHostPermissionsName[];
    static constexpr uint64_t kEnabledExtensionCount_HaveHostPermissionsNameHash = UINT64_C(14396594071145325284);
    Extensions_OnNavigation& SetEnabledExtensionCount_HaveHostPermissions(int64_t value);

    static const char kEnabledExtensionCount_InjectContentScriptName[];
    static constexpr uint64_t kEnabledExtensionCount_InjectContentScriptNameHash = UINT64_C(7144139813458476591);
    Extensions_OnNavigation& SetEnabledExtensionCount_InjectContentScript(int64_t value);

    static const char kWebRequestAuthProviderPermissionCountName[];
    static constexpr uint64_t kWebRequestAuthProviderPermissionCountNameHash = UINT64_C(14073357644843620505);
    Extensions_OnNavigation& SetWebRequestAuthProviderPermissionCount(int64_t value);

    static const char kWebRequestBlockingPermissionCountName[];
    static constexpr uint64_t kWebRequestBlockingPermissionCountNameHash = UINT64_C(1012633654825955958);
    Extensions_OnNavigation& SetWebRequestBlockingPermissionCount(int64_t value);

    static const char kWebRequestPermissionCountName[];
    static constexpr uint64_t kWebRequestPermissionCountNameHash = UINT64_C(4384118590633013797);
    Extensions_OnNavigation& SetWebRequestPermissionCount(int64_t value);
};

class Extensions_WebRequest_KeepaliveRequestFinished final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Extensions_WebRequest_KeepaliveRequestFinished(ukm::SourceId source_id);
    explicit Extensions_WebRequest_KeepaliveRequestFinished(ukm::SourceIdObj source_id);
    Extensions_WebRequest_KeepaliveRequestFinished(Extensions_WebRequest_KeepaliveRequestFinished&&);
    Extensions_WebRequest_KeepaliveRequestFinished& operator=(Extensions_WebRequest_KeepaliveRequestFinished&&);
    ~Extensions_WebRequest_KeepaliveRequestFinished() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12524558333720971544);

    static const char kNumRedirectsName[];
    static constexpr uint64_t kNumRedirectsNameHash = UINT64_C(8673123609428887707);
    Extensions_WebRequest_KeepaliveRequestFinished& SetNumRedirects(int64_t value);

    static const char kStateName[];
    static constexpr uint64_t kStateNameHash = UINT64_C(5089810972385038852);
    Extensions_WebRequest_KeepaliveRequestFinished& SetState(int64_t value);
};

class FacilitatedPayments_Pix_FopSelectorResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FacilitatedPayments_Pix_FopSelectorResult(ukm::SourceId source_id);
    explicit FacilitatedPayments_Pix_FopSelectorResult(ukm::SourceIdObj source_id);
    FacilitatedPayments_Pix_FopSelectorResult(FacilitatedPayments_Pix_FopSelectorResult&&);
    FacilitatedPayments_Pix_FopSelectorResult& operator=(FacilitatedPayments_Pix_FopSelectorResult&&);
    ~FacilitatedPayments_Pix_FopSelectorResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5216195086138498635);

    static const char kResultName[];
    static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
    FacilitatedPayments_Pix_FopSelectorResult& SetResult(int64_t value);
};

class FacilitatedPayments_Pix_FopSelectorShown final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FacilitatedPayments_Pix_FopSelectorShown(ukm::SourceId source_id);
    explicit FacilitatedPayments_Pix_FopSelectorShown(ukm::SourceIdObj source_id);
    FacilitatedPayments_Pix_FopSelectorShown(FacilitatedPayments_Pix_FopSelectorShown&&);
    FacilitatedPayments_Pix_FopSelectorShown& operator=(FacilitatedPayments_Pix_FopSelectorShown&&);
    ~FacilitatedPayments_Pix_FopSelectorShown() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3965223974824938409);

    static const char kShownName[];
    static constexpr uint64_t kShownNameHash = UINT64_C(11642401927465122037);
    FacilitatedPayments_Pix_FopSelectorShown& SetShown(int64_t value);
};

class FacilitatedPayments_Pix_InitiatePurchaseActionResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FacilitatedPayments_Pix_InitiatePurchaseActionResult(ukm::SourceId source_id);
    explicit FacilitatedPayments_Pix_InitiatePurchaseActionResult(ukm::SourceIdObj source_id);
    FacilitatedPayments_Pix_InitiatePurchaseActionResult(FacilitatedPayments_Pix_InitiatePurchaseActionResult&&);
    FacilitatedPayments_Pix_InitiatePurchaseActionResult& operator=(FacilitatedPayments_Pix_InitiatePurchaseActionResult&&);
    ~FacilitatedPayments_Pix_InitiatePurchaseActionResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9103820397241485062);

    static const char kResultName[];
    static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
    FacilitatedPayments_Pix_InitiatePurchaseActionResult& SetResult(int64_t value);
};

class FacilitatedPayments_Pix_Transaction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FacilitatedPayments_Pix_Transaction(ukm::SourceId source_id);
    explicit FacilitatedPayments_Pix_Transaction(ukm::SourceIdObj source_id);
    FacilitatedPayments_Pix_Transaction(FacilitatedPayments_Pix_Transaction&&);
    FacilitatedPayments_Pix_Transaction& operator=(FacilitatedPayments_Pix_Transaction&&);
    ~FacilitatedPayments_Pix_Transaction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14293647879030784692);

    static const char kResultName[];
    static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
    FacilitatedPayments_Pix_Transaction& SetResult(int64_t value);

    static const char kTriggerSourceName[];
    static constexpr uint64_t kTriggerSourceNameHash = UINT64_C(9327578615575406455);
    FacilitatedPayments_Pix_Transaction& SetTriggerSource(int64_t value);
};

class FacilitatedPayments_PixCodeCopied final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FacilitatedPayments_PixCodeCopied(ukm::SourceId source_id);
    explicit FacilitatedPayments_PixCodeCopied(ukm::SourceIdObj source_id);
    FacilitatedPayments_PixCodeCopied(FacilitatedPayments_PixCodeCopied&&);
    FacilitatedPayments_PixCodeCopied& operator=(FacilitatedPayments_PixCodeCopied&&);
    ~FacilitatedPayments_PixCodeCopied() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7998347817029737838);

    static const char kPixCodeCopiedName[];
    static constexpr uint64_t kPixCodeCopiedNameHash = UINT64_C(2530588208058251256);
    FacilitatedPayments_PixCodeCopied& SetPixCodeCopied(int64_t value);
};

class FacilitatedPayments_PixCodeDetectionResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FacilitatedPayments_PixCodeDetectionResult(ukm::SourceId source_id);
    explicit FacilitatedPayments_PixCodeDetectionResult(ukm::SourceIdObj source_id);
    FacilitatedPayments_PixCodeDetectionResult(FacilitatedPayments_PixCodeDetectionResult&&);
    FacilitatedPayments_PixCodeDetectionResult& operator=(FacilitatedPayments_PixCodeDetectionResult&&);
    ~FacilitatedPayments_PixCodeDetectionResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8091520906834343236);

    static const char kAttemptsName[];
    static constexpr uint64_t kAttemptsNameHash = UINT64_C(8909166950165828852);
    FacilitatedPayments_PixCodeDetectionResult& SetAttempts(int64_t value);

    static const char kDetectionTriggeredOnDomContentLoadedName[];
    static constexpr uint64_t kDetectionTriggeredOnDomContentLoadedNameHash = UINT64_C(16583686473427561569);
    FacilitatedPayments_PixCodeDetectionResult& SetDetectionTriggeredOnDomContentLoaded(int64_t value);

    static const char kLatencyInMillisName[];
    static constexpr uint64_t kLatencyInMillisNameHash = UINT64_C(9468930308877785989);
    FacilitatedPayments_PixCodeDetectionResult& SetLatencyInMillis(int64_t value);

    static const char kResultName[];
    static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
    FacilitatedPayments_PixCodeDetectionResult& SetResult(int64_t value);
};

class FamilyLinkUser_BlockedContent final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FamilyLinkUser_BlockedContent(ukm::SourceId source_id);
    explicit FamilyLinkUser_BlockedContent(ukm::SourceIdObj source_id);
    FamilyLinkUser_BlockedContent(FamilyLinkUser_BlockedContent&&);
    FamilyLinkUser_BlockedContent& operator=(FamilyLinkUser_BlockedContent&&);
    ~FamilyLinkUser_BlockedContent() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4648922300412212646);

    static const char kMainFrameBlockedName[];
    static constexpr uint64_t kMainFrameBlockedNameHash = UINT64_C(18128244960986027787);
    FamilyLinkUser_BlockedContent& SetMainFrameBlocked(int64_t value);

    static const char kNumBlockedIframesName[];
    static constexpr uint64_t kNumBlockedIframesNameHash = UINT64_C(6084184224638712807);
    FamilyLinkUser_BlockedContent& SetNumBlockedIframes(int64_t value);
};

class FamilyLinkUser_ReauthenticationInterstitial final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FamilyLinkUser_ReauthenticationInterstitial(ukm::SourceId source_id);
    explicit FamilyLinkUser_ReauthenticationInterstitial(ukm::SourceIdObj source_id);
    FamilyLinkUser_ReauthenticationInterstitial(FamilyLinkUser_ReauthenticationInterstitial&&);
    FamilyLinkUser_ReauthenticationInterstitial& operator=(FamilyLinkUser_ReauthenticationInterstitial&&);
    ~FamilyLinkUser_ReauthenticationInterstitial() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13643919678711340190);

    static const char kInterstitialShownName[];
    static constexpr uint64_t kInterstitialShownNameHash = UINT64_C(4406074973562429687);
    FamilyLinkUser_ReauthenticationInterstitial& SetInterstitialShown(int64_t value);

    static const char kReauthenticationCompletedName[];
    static constexpr uint64_t kReauthenticationCompletedNameHash = UINT64_C(18019467124304111621);
    FamilyLinkUser_ReauthenticationInterstitial& SetReauthenticationCompleted(int64_t value);

    static const char kReauthenticationStartedName[];
    static constexpr uint64_t kReauthenticationStartedNameHash = UINT64_C(13783518289529466956);
    FamilyLinkUser_ReauthenticationInterstitial& SetReauthenticationStarted(int64_t value);
};

class FastCheckout_FormStatus final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FastCheckout_FormStatus(ukm::SourceId source_id);
    explicit FastCheckout_FormStatus(ukm::SourceIdObj source_id);
    FastCheckout_FormStatus(FastCheckout_FormStatus&&);
    FastCheckout_FormStatus& operator=(FastCheckout_FormStatus&&);
    ~FastCheckout_FormStatus() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15212087424653185268);

    static const char kFilledName[];
    static constexpr uint64_t kFilledNameHash = UINT64_C(15696600479328041206);
    FastCheckout_FormStatus& SetFilled(int64_t value);

    static const char kFormSignatureName[];
    static constexpr uint64_t kFormSignatureNameHash = UINT64_C(4815584921581567107);
    FastCheckout_FormStatus& SetFormSignature(int64_t value);

    static const char kFormTypesName[];
    static constexpr uint64_t kFormTypesNameHash = UINT64_C(10767409811320878147);
    FastCheckout_FormStatus& SetFormTypes(int64_t value);

    static const char kRunIdName[];
    static constexpr uint64_t kRunIdNameHash = UINT64_C(11442258406165714974);
    FastCheckout_FormStatus& SetRunId(int64_t value);
};

class FastCheckout_RunOutcome final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FastCheckout_RunOutcome(ukm::SourceId source_id);
    explicit FastCheckout_RunOutcome(ukm::SourceIdObj source_id);
    FastCheckout_RunOutcome(FastCheckout_RunOutcome&&);
    FastCheckout_RunOutcome& operator=(FastCheckout_RunOutcome&&);
    ~FastCheckout_RunOutcome() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11852097459181603485);

    static const char kRunIdName[];
    static constexpr uint64_t kRunIdNameHash = UINT64_C(11442258406165714974);
    FastCheckout_RunOutcome& SetRunId(int64_t value);

    static const char kRunOutcomeName[];
    static constexpr uint64_t kRunOutcomeNameHash = UINT64_C(13225608597749331216);
    FastCheckout_RunOutcome& SetRunOutcome(int64_t value);
};

class Feedback_HappinessTrackingSurvey final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Feedback_HappinessTrackingSurvey(ukm::SourceId source_id);
    explicit Feedback_HappinessTrackingSurvey(ukm::SourceIdObj source_id);
    Feedback_HappinessTrackingSurvey(Feedback_HappinessTrackingSurvey&&);
    Feedback_HappinessTrackingSurvey& operator=(Feedback_HappinessTrackingSurvey&&);
    ~Feedback_HappinessTrackingSurvey() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14939729010542726247);

    static const char kSurveyAnswerToQuestion1Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion1NameHash = UINT64_C(6301467860240890767);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion1(int64_t value);

    static const char kSurveyAnswerToQuestion2Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion2NameHash = UINT64_C(17524990532057520074);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion2(int64_t value);

    static const char kSurveyAnswerToQuestion3Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion3NameHash = UINT64_C(11474291931344921924);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion3(int64_t value);

    static const char kSurveyAnswerToQuestion4Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion4NameHash = UINT64_C(6011194280185066074);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion4(int64_t value);

    static const char kSurveyAnswerToQuestion5Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion5NameHash = UINT64_C(7929244668320760635);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion5(int64_t value);

    static const char kSurveyAnswerToQuestion6Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion6NameHash = UINT64_C(13553888428304699771);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion6(int64_t value);

    static const char kSurveyAnswerToQuestion7Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion7NameHash = UINT64_C(16485206611783609878);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion7(int64_t value);

    static const char kSurveyAnswerToQuestion8Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion8NameHash = UINT64_C(17432801081074012632);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion8(int64_t value);

    static const char kSurveyAnswerToQuestion9Name[];
    static constexpr uint64_t kSurveyAnswerToQuestion9NameHash = UINT64_C(12073695291638843231);
    Feedback_HappinessTrackingSurvey& SetSurveyAnswerToQuestion9(int64_t value);

    static const char kSurveyCompletedName[];
    static constexpr uint64_t kSurveyCompletedNameHash = UINT64_C(12807764438230927171);
    Feedback_HappinessTrackingSurvey& SetSurveyCompleted(int64_t value);

    static const char kSurveyIdName[];
    static constexpr uint64_t kSurveyIdNameHash = UINT64_C(2724982962451610133);
    Feedback_HappinessTrackingSurvey& SetSurveyId(int64_t value);

    static const char kSurveyLoadedName[];
    static constexpr uint64_t kSurveyLoadedNameHash = UINT64_C(2848780276047583704);
    Feedback_HappinessTrackingSurvey& SetSurveyLoaded(int64_t value);
};

class FileSystemAPI_WebRequest final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FileSystemAPI_WebRequest(ukm::SourceId source_id);
    explicit FileSystemAPI_WebRequest(ukm::SourceIdObj source_id);
    FileSystemAPI_WebRequest(FileSystemAPI_WebRequest&&);
    FileSystemAPI_WebRequest& operator=(FileSystemAPI_WebRequest&&);
    ~FileSystemAPI_WebRequest() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15744625327213391071);

    static const char kPersistentName[];
    static constexpr uint64_t kPersistentNameHash = UINT64_C(6910695792866800057);
    FileSystemAPI_WebRequest& SetPersistent(int64_t value);

    static const char kTemporaryName[];
    static constexpr uint64_t kTemporaryNameHash = UINT64_C(1213822862652674492);
    FileSystemAPI_WebRequest& SetTemporary(int64_t value);
};

class FingerprintingProtection final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FingerprintingProtection(ukm::SourceId source_id);
    explicit FingerprintingProtection(ukm::SourceIdObj source_id);
    FingerprintingProtection(FingerprintingProtection&&);
    FingerprintingProtection& operator=(FingerprintingProtection&&);
    ~FingerprintingProtection() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17273599278651584311);

    static const char kActivationDecisionName[];
    static constexpr uint64_t kActivationDecisionNameHash = UINT64_C(8340568698825149996);
    FingerprintingProtection& SetActivationDecision(int64_t value);

    static const char kAllowlistSourceName[];
    static constexpr uint64_t kAllowlistSourceNameHash = UINT64_C(604863574602765854);
    FingerprintingProtection& SetAllowlistSource(int64_t value);

    static const char kDryRunName[];
    static constexpr uint64_t kDryRunNameHash = UINT64_C(15305931645510130195);
    FingerprintingProtection& SetDryRun(int64_t value);
};

class FingerprintingProtectionUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FingerprintingProtectionUsage(ukm::SourceId source_id);
    explicit FingerprintingProtectionUsage(ukm::SourceIdObj source_id);
    FingerprintingProtectionUsage(FingerprintingProtectionUsage&&);
    FingerprintingProtectionUsage& operator=(FingerprintingProtectionUsage&&);
    ~FingerprintingProtectionUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6486198570534837725);

    static const char kRefreshCountName[];
    static constexpr uint64_t kRefreshCountNameHash = UINT64_C(2886040824780537886);
    FingerprintingProtectionUsage& SetRefreshCount(int64_t value);

    static const char kSiteEngagementLevelName[];
    static constexpr uint64_t kSiteEngagementLevelNameHash = UINT64_C(7434896235365170565);
    FingerprintingProtectionUsage& SetSiteEngagementLevel(int64_t value);
};

class FlocPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit FlocPageLoad(ukm::SourceId source_id);
    explicit FlocPageLoad(ukm::SourceIdObj source_id);
    FlocPageLoad(FlocPageLoad&&);
    FlocPageLoad& operator=(FlocPageLoad&&);
    ~FlocPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6247082832829199138);

    static const char kFlocIdName[];
    static constexpr uint64_t kFlocIdNameHash = UINT64_C(12132897347379791215);
    FlocPageLoad& SetFlocId(int64_t value);
};

class Fullscreen_Enter final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Fullscreen_Enter(ukm::SourceId source_id);
    explicit Fullscreen_Enter(ukm::SourceIdObj source_id);
    Fullscreen_Enter(Fullscreen_Enter&&);
    Fullscreen_Enter& operator=(Fullscreen_Enter&&);
    ~Fullscreen_Enter() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17828670494812061854);

    static const char kLockStateName[];
    static constexpr uint64_t kLockStateNameHash = UINT64_C(1690349150269719208);
    Fullscreen_Enter& SetLockState(int64_t value);
};

class Fullscreen_Exit final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Fullscreen_Exit(ukm::SourceId source_id);
    explicit Fullscreen_Exit(ukm::SourceIdObj source_id);
    Fullscreen_Exit(Fullscreen_Exit&&);
    Fullscreen_Exit& operator=(Fullscreen_Exit&&);
    ~Fullscreen_Exit() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5280816973080484130);

    static const char kSessionDurationName[];
    static constexpr uint64_t kSessionDurationNameHash = UINT64_C(2701974374748336509);
    Fullscreen_Exit& SetSessionDuration(int64_t value);
};

class GameControls_ButtonOptionsMenuFunctionTriggered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameControls_ButtonOptionsMenuFunctionTriggered(ukm::SourceId source_id);
    explicit GameControls_ButtonOptionsMenuFunctionTriggered(ukm::SourceIdObj source_id);
    GameControls_ButtonOptionsMenuFunctionTriggered(GameControls_ButtonOptionsMenuFunctionTriggered&&);
    GameControls_ButtonOptionsMenuFunctionTriggered& operator=(GameControls_ButtonOptionsMenuFunctionTriggered&&);
    ~GameControls_ButtonOptionsMenuFunctionTriggered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14044001428377426573);

    static const char kFunctionName[];
    static constexpr uint64_t kFunctionNameHash = UINT64_C(9673878869274982271);
    GameControls_ButtonOptionsMenuFunctionTriggered& SetFunction(int64_t value);
};

class GameControls_EditDeleteMenuFuctionTriggered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameControls_EditDeleteMenuFuctionTriggered(ukm::SourceId source_id);
    explicit GameControls_EditDeleteMenuFuctionTriggered(ukm::SourceIdObj source_id);
    GameControls_EditDeleteMenuFuctionTriggered(GameControls_EditDeleteMenuFuctionTriggered&&);
    GameControls_EditDeleteMenuFuctionTriggered& operator=(GameControls_EditDeleteMenuFuctionTriggered&&);
    ~GameControls_EditDeleteMenuFuctionTriggered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10110804741753680625);

    static const char kFunctionName[];
    static constexpr uint64_t kFunctionNameHash = UINT64_C(9673878869274982271);
    GameControls_EditDeleteMenuFuctionTriggered& SetFunction(int64_t value);
};

class GameControls_EditingListFunctionTriggered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameControls_EditingListFunctionTriggered(ukm::SourceId source_id);
    explicit GameControls_EditingListFunctionTriggered(ukm::SourceIdObj source_id);
    GameControls_EditingListFunctionTriggered(GameControls_EditingListFunctionTriggered&&);
    GameControls_EditingListFunctionTriggered& operator=(GameControls_EditingListFunctionTriggered&&);
    ~GameControls_EditingListFunctionTriggered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6583827052843377008);

    static const char kFunctionName[];
    static constexpr uint64_t kFunctionNameHash = UINT64_C(9673878869274982271);
    GameControls_EditingListFunctionTriggered& SetFunction(int64_t value);
};

class GameControls_ToggleWithMappingSource final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameControls_ToggleWithMappingSource(ukm::SourceId source_id);
    explicit GameControls_ToggleWithMappingSource(ukm::SourceIdObj source_id);
    GameControls_ToggleWithMappingSource(GameControls_ToggleWithMappingSource&&);
    GameControls_ToggleWithMappingSource& operator=(GameControls_ToggleWithMappingSource&&);
    ~GameControls_ToggleWithMappingSource() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16087115784313917227);

    static const char kFunctionName[];
    static constexpr uint64_t kFunctionNameHash = UINT64_C(9673878869274982271);
    GameControls_ToggleWithMappingSource& SetFunction(int64_t value);

    static const char kMappingSourceName[];
    static constexpr uint64_t kMappingSourceNameHash = UINT64_C(9370335301330400847);
    GameControls_ToggleWithMappingSource& SetMappingSource(int64_t value);

    static const char kToggleOnName[];
    static constexpr uint64_t kToggleOnNameHash = UINT64_C(4337183602752804865);
    GameControls_ToggleWithMappingSource& SetToggleOn(int64_t value);
};

class GameDashboard_ControlsFeatureToggleState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ControlsFeatureToggleState(ukm::SourceId source_id);
    explicit GameDashboard_ControlsFeatureToggleState(ukm::SourceIdObj source_id);
    GameDashboard_ControlsFeatureToggleState(GameDashboard_ControlsFeatureToggleState&&);
    GameDashboard_ControlsFeatureToggleState& operator=(GameDashboard_ControlsFeatureToggleState&&);
    ~GameDashboard_ControlsFeatureToggleState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4583363670557255957);

    static const char kToggleOnName[];
    static constexpr uint64_t kToggleOnNameHash = UINT64_C(4337183602752804865);
    GameDashboard_ControlsFeatureToggleState& SetToggleOn(int64_t value);
};

class GameDashboard_ControlsHintToggleSource final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ControlsHintToggleSource(ukm::SourceId source_id);
    explicit GameDashboard_ControlsHintToggleSource(ukm::SourceIdObj source_id);
    GameDashboard_ControlsHintToggleSource(GameDashboard_ControlsHintToggleSource&&);
    GameDashboard_ControlsHintToggleSource& operator=(GameDashboard_ControlsHintToggleSource&&);
    ~GameDashboard_ControlsHintToggleSource() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17634705623839060115);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    GameDashboard_ControlsHintToggleSource& SetSource(int64_t value);

    static const char kToggleOnName[];
    static constexpr uint64_t kToggleOnNameHash = UINT64_C(4337183602752804865);
    GameDashboard_ControlsHintToggleSource& SetToggleOn(int64_t value);
};

class GameDashboard_EditControlsWithEmptyState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_EditControlsWithEmptyState(ukm::SourceId source_id);
    explicit GameDashboard_EditControlsWithEmptyState(ukm::SourceIdObj source_id);
    GameDashboard_EditControlsWithEmptyState(GameDashboard_EditControlsWithEmptyState&&);
    GameDashboard_EditControlsWithEmptyState& operator=(GameDashboard_EditControlsWithEmptyState&&);
    ~GameDashboard_EditControlsWithEmptyState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12749564289121122836);

    static const char kEmptyName[];
    static constexpr uint64_t kEmptyNameHash = UINT64_C(14856402023920672975);
    GameDashboard_EditControlsWithEmptyState& SetEmpty(int64_t value);
};

class GameDashboard_FunctionTriggered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_FunctionTriggered(ukm::SourceId source_id);
    explicit GameDashboard_FunctionTriggered(ukm::SourceIdObj source_id);
    GameDashboard_FunctionTriggered(GameDashboard_FunctionTriggered&&);
    GameDashboard_FunctionTriggered& operator=(GameDashboard_FunctionTriggered&&);
    ~GameDashboard_FunctionTriggered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11948877733512243447);

    static const char kFunctionName[];
    static constexpr uint64_t kFunctionNameHash = UINT64_C(9673878869274982271);
    GameDashboard_FunctionTriggered& SetFunction(int64_t value);
};

class GameDashboard_RecordingStartSource final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_RecordingStartSource(ukm::SourceId source_id);
    explicit GameDashboard_RecordingStartSource(ukm::SourceIdObj source_id);
    GameDashboard_RecordingStartSource(GameDashboard_RecordingStartSource&&);
    GameDashboard_RecordingStartSource& operator=(GameDashboard_RecordingStartSource&&);
    ~GameDashboard_RecordingStartSource() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17765246445126047128);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    GameDashboard_RecordingStartSource& SetSource(int64_t value);
};

class GameDashboard_ScreenshotTakeSource final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ScreenshotTakeSource(ukm::SourceId source_id);
    explicit GameDashboard_ScreenshotTakeSource(ukm::SourceIdObj source_id);
    GameDashboard_ScreenshotTakeSource(GameDashboard_ScreenshotTakeSource&&);
    GameDashboard_ScreenshotTakeSource& operator=(GameDashboard_ScreenshotTakeSource&&);
    ~GameDashboard_ScreenshotTakeSource() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15317274434861980345);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    GameDashboard_ScreenshotTakeSource& SetSource(int64_t value);
};

class GameDashboard_ToggleMainMenu final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ToggleMainMenu(ukm::SourceId source_id);
    explicit GameDashboard_ToggleMainMenu(ukm::SourceIdObj source_id);
    GameDashboard_ToggleMainMenu(GameDashboard_ToggleMainMenu&&);
    GameDashboard_ToggleMainMenu& operator=(GameDashboard_ToggleMainMenu&&);
    ~GameDashboard_ToggleMainMenu() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6124626189303220359);

    static const char kToggleMethodName[];
    static constexpr uint64_t kToggleMethodNameHash = UINT64_C(4215395916362638233);
    GameDashboard_ToggleMainMenu& SetToggleMethod(int64_t value);

    static const char kToggleOnName[];
    static constexpr uint64_t kToggleOnNameHash = UINT64_C(4337183602752804865);
    GameDashboard_ToggleMainMenu& SetToggleOn(int64_t value);
};

class GameDashboard_ToolbarClickToExpandState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ToolbarClickToExpandState(ukm::SourceId source_id);
    explicit GameDashboard_ToolbarClickToExpandState(ukm::SourceIdObj source_id);
    GameDashboard_ToolbarClickToExpandState(GameDashboard_ToolbarClickToExpandState&&);
    GameDashboard_ToolbarClickToExpandState& operator=(GameDashboard_ToolbarClickToExpandState&&);
    ~GameDashboard_ToolbarClickToExpandState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6793166926721319202);

    static const char kExpandedName[];
    static constexpr uint64_t kExpandedNameHash = UINT64_C(7203150201908454328);
    GameDashboard_ToolbarClickToExpandState& SetExpanded(int64_t value);
};

class GameDashboard_ToolbarNewLocation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ToolbarNewLocation(ukm::SourceId source_id);
    explicit GameDashboard_ToolbarNewLocation(ukm::SourceIdObj source_id);
    GameDashboard_ToolbarNewLocation(GameDashboard_ToolbarNewLocation&&);
    GameDashboard_ToolbarNewLocation& operator=(GameDashboard_ToolbarNewLocation&&);
    ~GameDashboard_ToolbarNewLocation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15379820645003093243);

    static const char kLocationName[];
    static constexpr uint64_t kLocationNameHash = UINT64_C(14869748323867449793);
    GameDashboard_ToolbarNewLocation& SetLocation(int64_t value);
};

class GameDashboard_ToolbarToggleState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_ToolbarToggleState(ukm::SourceId source_id);
    explicit GameDashboard_ToolbarToggleState(ukm::SourceIdObj source_id);
    GameDashboard_ToolbarToggleState(GameDashboard_ToolbarToggleState&&);
    GameDashboard_ToolbarToggleState& operator=(GameDashboard_ToolbarToggleState&&);
    ~GameDashboard_ToolbarToggleState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1179199656223978960);

    static const char kToggleOnName[];
    static constexpr uint64_t kToggleOnNameHash = UINT64_C(4337183602752804865);
    GameDashboard_ToolbarToggleState& SetToggleOn(int64_t value);
};

class GameDashboard_WelcomeDialogNotificationToggleState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GameDashboard_WelcomeDialogNotificationToggleState(ukm::SourceId source_id);
    explicit GameDashboard_WelcomeDialogNotificationToggleState(ukm::SourceIdObj source_id);
    GameDashboard_WelcomeDialogNotificationToggleState(GameDashboard_WelcomeDialogNotificationToggleState&&);
    GameDashboard_WelcomeDialogNotificationToggleState& operator=(GameDashboard_WelcomeDialogNotificationToggleState&&);
    ~GameDashboard_WelcomeDialogNotificationToggleState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1473466425166916734);

    static const char kToggleOnName[];
    static constexpr uint64_t kToggleOnNameHash = UINT64_C(4337183602752804865);
    GameDashboard_WelcomeDialogNotificationToggleState& SetToggleOn(int64_t value);
};

class GamingInputOverlay_ActionRepositionOperationType final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_ActionRepositionOperationType(ukm::SourceId source_id);
    explicit GamingInputOverlay_ActionRepositionOperationType(ukm::SourceIdObj source_id);
    GamingInputOverlay_ActionRepositionOperationType(GamingInputOverlay_ActionRepositionOperationType&&);
    GamingInputOverlay_ActionRepositionOperationType& operator=(GamingInputOverlay_ActionRepositionOperationType&&);
    ~GamingInputOverlay_ActionRepositionOperationType() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6114192382293476881);

    static const char kOperationTypeName[];
    static constexpr uint64_t kOperationTypeNameHash = UINT64_C(6503369524048419792);
    GamingInputOverlay_ActionRepositionOperationType& SetOperationType(int64_t value);
};

class GamingInputOverlay_ActionRepositionWindowStateType final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_ActionRepositionWindowStateType(ukm::SourceId source_id);
    explicit GamingInputOverlay_ActionRepositionWindowStateType(ukm::SourceIdObj source_id);
    GamingInputOverlay_ActionRepositionWindowStateType(GamingInputOverlay_ActionRepositionWindowStateType&&);
    GamingInputOverlay_ActionRepositionWindowStateType& operator=(GamingInputOverlay_ActionRepositionWindowStateType&&);
    ~GamingInputOverlay_ActionRepositionWindowStateType() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3845553971601578547);

    static const char kWindowStateTypeName[];
    static constexpr uint64_t kWindowStateTypeNameHash = UINT64_C(7835319652043001156);
    GamingInputOverlay_ActionRepositionWindowStateType& SetWindowStateType(int64_t value);
};

class GamingInputOverlay_ButtonGroupRepositionOperationType final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_ButtonGroupRepositionOperationType(ukm::SourceId source_id);
    explicit GamingInputOverlay_ButtonGroupRepositionOperationType(ukm::SourceIdObj source_id);
    GamingInputOverlay_ButtonGroupRepositionOperationType(GamingInputOverlay_ButtonGroupRepositionOperationType&&);
    GamingInputOverlay_ButtonGroupRepositionOperationType& operator=(GamingInputOverlay_ButtonGroupRepositionOperationType&&);
    ~GamingInputOverlay_ButtonGroupRepositionOperationType() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2989746233860473659);

    static const char kOperationTypeName[];
    static constexpr uint64_t kOperationTypeNameHash = UINT64_C(6503369524048419792);
    GamingInputOverlay_ButtonGroupRepositionOperationType& SetOperationType(int64_t value);
};

class GamingInputOverlay_ButtonGroupRepositionWindowStateType final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_ButtonGroupRepositionWindowStateType(ukm::SourceId source_id);
    explicit GamingInputOverlay_ButtonGroupRepositionWindowStateType(ukm::SourceIdObj source_id);
    GamingInputOverlay_ButtonGroupRepositionWindowStateType(GamingInputOverlay_ButtonGroupRepositionWindowStateType&&);
    GamingInputOverlay_ButtonGroupRepositionWindowStateType& operator=(GamingInputOverlay_ButtonGroupRepositionWindowStateType&&);
    ~GamingInputOverlay_ButtonGroupRepositionWindowStateType() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12219585854233442105);

    static const char kWindowStateTypeName[];
    static constexpr uint64_t kWindowStateTypeNameHash = UINT64_C(7835319652043001156);
    GamingInputOverlay_ButtonGroupRepositionWindowStateType& SetWindowStateType(int64_t value);
};

class GamingInputOverlay_Customization final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_Customization(ukm::SourceId source_id);
    explicit GamingInputOverlay_Customization(ukm::SourceIdObj source_id);
    GamingInputOverlay_Customization(GamingInputOverlay_Customization&&);
    GamingInputOverlay_Customization& operator=(GamingInputOverlay_Customization&&);
    ~GamingInputOverlay_Customization() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15868125188758034185);

    static const char kCustomizationUsedName[];
    static constexpr uint64_t kCustomizationUsedNameHash = UINT64_C(6807685685809889576);
    GamingInputOverlay_Customization& SetCustomizationUsed(int64_t value);
};

class GamingInputOverlay_Feature final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_Feature(ukm::SourceId source_id);
    explicit GamingInputOverlay_Feature(ukm::SourceIdObj source_id);
    GamingInputOverlay_Feature(GamingInputOverlay_Feature&&);
    GamingInputOverlay_Feature& operator=(GamingInputOverlay_Feature&&);
    ~GamingInputOverlay_Feature() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8325704071122675056);

    static const char kFeatureStateOnName[];
    static constexpr uint64_t kFeatureStateOnNameHash = UINT64_C(18127025031443190277);
    GamingInputOverlay_Feature& SetFeatureStateOn(int64_t value);
};

class GamingInputOverlay_MappingHint final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_MappingHint(ukm::SourceId source_id);
    explicit GamingInputOverlay_MappingHint(ukm::SourceIdObj source_id);
    GamingInputOverlay_MappingHint(GamingInputOverlay_MappingHint&&);
    GamingInputOverlay_MappingHint& operator=(GamingInputOverlay_MappingHint&&);
    ~GamingInputOverlay_MappingHint() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10738302011954418259);

    static const char kMappingHintStateOnName[];
    static constexpr uint64_t kMappingHintStateOnNameHash = UINT64_C(2109411855624377624);
    GamingInputOverlay_MappingHint& SetMappingHintStateOn(int64_t value);
};

class GamingInputOverlay_MenuEntryRepositionOperationType final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_MenuEntryRepositionOperationType(ukm::SourceId source_id);
    explicit GamingInputOverlay_MenuEntryRepositionOperationType(ukm::SourceIdObj source_id);
    GamingInputOverlay_MenuEntryRepositionOperationType(GamingInputOverlay_MenuEntryRepositionOperationType&&);
    GamingInputOverlay_MenuEntryRepositionOperationType& operator=(GamingInputOverlay_MenuEntryRepositionOperationType&&);
    ~GamingInputOverlay_MenuEntryRepositionOperationType() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3763584486430349859);

    static const char kOperationTypeName[];
    static constexpr uint64_t kOperationTypeNameHash = UINT64_C(6503369524048419792);
    GamingInputOverlay_MenuEntryRepositionOperationType& SetOperationType(int64_t value);
};

class GamingInputOverlay_MenuEntryRepositionWindowStateType final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GamingInputOverlay_MenuEntryRepositionWindowStateType(ukm::SourceId source_id);
    explicit GamingInputOverlay_MenuEntryRepositionWindowStateType(ukm::SourceIdObj source_id);
    GamingInputOverlay_MenuEntryRepositionWindowStateType(GamingInputOverlay_MenuEntryRepositionWindowStateType&&);
    GamingInputOverlay_MenuEntryRepositionWindowStateType& operator=(GamingInputOverlay_MenuEntryRepositionWindowStateType&&);
    ~GamingInputOverlay_MenuEntryRepositionWindowStateType() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5999613232746076014);

    static const char kWindowStateTypeName[];
    static constexpr uint64_t kWindowStateTypeNameHash = UINT64_C(7835319652043001156);
    GamingInputOverlay_MenuEntryRepositionWindowStateType& SetWindowStateType(int64_t value);
};

class GeneratedNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GeneratedNavigation(ukm::SourceId source_id);
    explicit GeneratedNavigation(ukm::SourceIdObj source_id);
    GeneratedNavigation(GeneratedNavigation&&);
    GeneratedNavigation& operator=(GeneratedNavigation&&);
    ~GeneratedNavigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17713702562453741093);

    static const char kFinalURLIsDefaultSearchEngineName[];
    static constexpr uint64_t kFinalURLIsDefaultSearchEngineNameHash = UINT64_C(1036686794479530753);
    GeneratedNavigation& SetFinalURLIsDefaultSearchEngine(int64_t value);

    static const char kFinalURLIsHomePageName[];
    static constexpr uint64_t kFinalURLIsHomePageNameHash = UINT64_C(1917448393817607381);
    GeneratedNavigation& SetFinalURLIsHomePage(int64_t value);

    static const char kFirstURLIsDefaultSearchEngineName[];
    static constexpr uint64_t kFirstURLIsDefaultSearchEngineNameHash = UINT64_C(16888879793066537203);
    GeneratedNavigation& SetFirstURLIsDefaultSearchEngine(int64_t value);

    static const char kFirstURLIsHomePageName[];
    static constexpr uint64_t kFirstURLIsHomePageNameHash = UINT64_C(7866972537372757464);
    GeneratedNavigation& SetFirstURLIsHomePage(int64_t value);
};

class GoogleDocsOfflineExtension final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit GoogleDocsOfflineExtension(ukm::SourceId source_id);
    explicit GoogleDocsOfflineExtension(ukm::SourceIdObj source_id);
    GoogleDocsOfflineExtension(GoogleDocsOfflineExtension&&);
    GoogleDocsOfflineExtension& operator=(GoogleDocsOfflineExtension&&);
    ~GoogleDocsOfflineExtension() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3420244295988015024);

    static const char kResourceRequestedName[];
    static constexpr uint64_t kResourceRequestedNameHash = UINT64_C(121230110045336584);
    GoogleDocsOfflineExtension& SetResourceRequested(int64_t value);
};

class Graphics_Smoothness_EventLatency final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Graphics_Smoothness_EventLatency(ukm::SourceId source_id);
    explicit Graphics_Smoothness_EventLatency(ukm::SourceIdObj source_id);
    Graphics_Smoothness_EventLatency(Graphics_Smoothness_EventLatency&&);
    Graphics_Smoothness_EventLatency& operator=(Graphics_Smoothness_EventLatency&&);
    ~Graphics_Smoothness_EventLatency() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11577416923418681607);

    static const char kActivationName[];
    static constexpr uint64_t kActivationNameHash = UINT64_C(12224509299331452166);
    Graphics_Smoothness_EventLatency& SetActivation(int64_t value);

    static const char kBeginImplFrameToSendBeginMainFrameName[];
    static constexpr uint64_t kBeginImplFrameToSendBeginMainFrameNameHash = UINT64_C(17008172611226938782);
    Graphics_Smoothness_EventLatency& SetBeginImplFrameToSendBeginMainFrame(int64_t value);

    static const char kCommitName[];
    static constexpr uint64_t kCommitNameHash = UINT64_C(6473274705490247427);
    Graphics_Smoothness_EventLatency& SetCommit(int64_t value);

    static const char kEndActivateToSubmitCompositorFrameName[];
    static constexpr uint64_t kEndActivateToSubmitCompositorFrameNameHash = UINT64_C(16428909035706792583);
    Graphics_Smoothness_EventLatency& SetEndActivateToSubmitCompositorFrame(int64_t value);

    static const char kEndCommitToActivationName[];
    static constexpr uint64_t kEndCommitToActivationNameHash = UINT64_C(3830696727341877188);
    Graphics_Smoothness_EventLatency& SetEndCommitToActivation(int64_t value);

    static const char kEventTypeName[];
    static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
    Graphics_Smoothness_EventLatency& SetEventType(int64_t value);

    static const char kGenerationToRendererCompositorName[];
    static constexpr uint64_t kGenerationToRendererCompositorNameHash = UINT64_C(969682407373868024);
    Graphics_Smoothness_EventLatency& SetGenerationToRendererCompositor(int64_t value);

    static const char kPinchInputTypeName[];
    static constexpr uint64_t kPinchInputTypeNameHash = UINT64_C(5518304116786289486);
    Graphics_Smoothness_EventLatency& SetPinchInputType(int64_t value);

    static const char kRendererCompositorFinishedToActivationName[];
    static constexpr uint64_t kRendererCompositorFinishedToActivationNameHash = UINT64_C(15927915954747123605);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToActivation(int64_t value);

    static const char kRendererCompositorFinishedToBeginImplFrameName[];
    static constexpr uint64_t kRendererCompositorFinishedToBeginImplFrameNameHash = UINT64_C(12032546549716609090);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToBeginImplFrame(int64_t value);

    static const char kRendererCompositorFinishedToCommitName[];
    static constexpr uint64_t kRendererCompositorFinishedToCommitNameHash = UINT64_C(9837145626601988004);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToCommit(int64_t value);

    static const char kRendererCompositorFinishedToEndActivateName[];
    static constexpr uint64_t kRendererCompositorFinishedToEndActivateNameHash = UINT64_C(9828986879827862650);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToEndActivate(int64_t value);

    static const char kRendererCompositorFinishedToEndCommitName[];
    static constexpr uint64_t kRendererCompositorFinishedToEndCommitNameHash = UINT64_C(4629632394901522803);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToEndCommit(int64_t value);

    static const char kRendererCompositorFinishedToSendBeginMainFrameName[];
    static constexpr uint64_t kRendererCompositorFinishedToSendBeginMainFrameNameHash = UINT64_C(17105239388500740890);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToSendBeginMainFrame(int64_t value);

    static const char kRendererCompositorFinishedToSubmitCompositorFrameName[];
    static constexpr uint64_t kRendererCompositorFinishedToSubmitCompositorFrameNameHash = UINT64_C(18271431260481951403);
    Graphics_Smoothness_EventLatency& SetRendererCompositorFinishedToSubmitCompositorFrame(int64_t value);

    static const char kRendererCompositorProcessingName[];
    static constexpr uint64_t kRendererCompositorProcessingNameHash = UINT64_C(5028192811609492297);
    Graphics_Smoothness_EventLatency& SetRendererCompositorProcessing(int64_t value);

    static const char kRendererCompositorQueueingDelayName[];
    static constexpr uint64_t kRendererCompositorQueueingDelayNameHash = UINT64_C(2468258078399488287);
    Graphics_Smoothness_EventLatency& SetRendererCompositorQueueingDelay(int64_t value);

    static const char kRendererCompositorToMainName[];
    static constexpr uint64_t kRendererCompositorToMainNameHash = UINT64_C(17276359931821242034);
    Graphics_Smoothness_EventLatency& SetRendererCompositorToMain(int64_t value);

    static const char kRendererMainFinishedToActivationName[];
    static constexpr uint64_t kRendererMainFinishedToActivationNameHash = UINT64_C(10018023188015662469);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToActivation(int64_t value);

    static const char kRendererMainFinishedToBeginImplFrameName[];
    static constexpr uint64_t kRendererMainFinishedToBeginImplFrameNameHash = UINT64_C(5159593079225697322);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToBeginImplFrame(int64_t value);

    static const char kRendererMainFinishedToCommitName[];
    static constexpr uint64_t kRendererMainFinishedToCommitNameHash = UINT64_C(10037858315111168217);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToCommit(int64_t value);

    static const char kRendererMainFinishedToEndActivateName[];
    static constexpr uint64_t kRendererMainFinishedToEndActivateNameHash = UINT64_C(2461849999618300610);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToEndActivate(int64_t value);

    static const char kRendererMainFinishedToEndCommitName[];
    static constexpr uint64_t kRendererMainFinishedToEndCommitNameHash = UINT64_C(10476577838406199835);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToEndCommit(int64_t value);

    static const char kRendererMainFinishedToSendBeginMainFrameName[];
    static constexpr uint64_t kRendererMainFinishedToSendBeginMainFrameNameHash = UINT64_C(6474019368894038500);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToSendBeginMainFrame(int64_t value);

    static const char kRendererMainFinishedToSubmitCompositorFrameName[];
    static constexpr uint64_t kRendererMainFinishedToSubmitCompositorFrameNameHash = UINT64_C(9123582581286357486);
    Graphics_Smoothness_EventLatency& SetRendererMainFinishedToSubmitCompositorFrame(int64_t value);

    static const char kRendererMainProcessingName[];
    static constexpr uint64_t kRendererMainProcessingNameHash = UINT64_C(10290253830413013004);
    Graphics_Smoothness_EventLatency& SetRendererMainProcessing(int64_t value);

    static const char kScrollBegin_TouchName[];
    static constexpr uint64_t kScrollBegin_TouchNameHash = UINT64_C(12651638458242760411);
    Graphics_Smoothness_EventLatency& SetScrollBegin_Touch(int64_t value);

    static const char kScrollBegin_WheelName[];
    static constexpr uint64_t kScrollBegin_WheelNameHash = UINT64_C(16753436230895006416);
    Graphics_Smoothness_EventLatency& SetScrollBegin_Wheel(int64_t value);

    static const char kScrollInputTypeName[];
    static constexpr uint64_t kScrollInputTypeNameHash = UINT64_C(17008543633647094581);
    Graphics_Smoothness_EventLatency& SetScrollInputType(int64_t value);

    static const char kScrollUpdate_TouchName[];
    static constexpr uint64_t kScrollUpdate_TouchNameHash = UINT64_C(7603444358775222954);
    Graphics_Smoothness_EventLatency& SetScrollUpdate_Touch(int64_t value);

    static const char kScrollUpdate_WheelName[];
    static constexpr uint64_t kScrollUpdate_WheelNameHash = UINT64_C(6226239432210241520);
    Graphics_Smoothness_EventLatency& SetScrollUpdate_Wheel(int64_t value);

    static const char kSendBeginMainFrameToCommitName[];
    static constexpr uint64_t kSendBeginMainFrameToCommitNameHash = UINT64_C(4533040338292079001);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit(int64_t value);

    static const char kSendBeginMainFrameToCommit_AccessibilityName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_AccessibilityNameHash = UINT64_C(4688218205422913270);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_Accessibility(int64_t value);

    static const char kSendBeginMainFrameToCommit_AnimateName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_AnimateNameHash = UINT64_C(8343767389934127044);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_Animate(int64_t value);

    static const char kSendBeginMainFrameToCommit_BeginMainSentToStartedName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash = UINT64_C(5384975942974359718);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_BeginMainSentToStarted(int64_t value);

    static const char kSendBeginMainFrameToCommit_CompositeCommitName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_CompositeCommitNameHash = UINT64_C(10575954611204518961);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_CompositeCommit(int64_t value);

    static const char kSendBeginMainFrameToCommit_CompositingInputsName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_CompositingInputsNameHash = UINT64_C(829465320820564719);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_CompositingInputs(int64_t value);

    static const char kSendBeginMainFrameToCommit_HandleInputEventsName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_HandleInputEventsNameHash = UINT64_C(1165118933490711579);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_HandleInputEvents(int64_t value);

    static const char kSendBeginMainFrameToCommit_LayoutUpdateName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_LayoutUpdateNameHash = UINT64_C(10225608126652137034);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_LayoutUpdate(int64_t value);

    static const char kSendBeginMainFrameToCommit_PaintName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_PaintNameHash = UINT64_C(232555831202593428);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_Paint(int64_t value);

    static const char kSendBeginMainFrameToCommit_PrepaintName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_PrepaintNameHash = UINT64_C(14043047910485169633);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_Prepaint(int64_t value);

    static const char kSendBeginMainFrameToCommit_StyleUpdateName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_StyleUpdateNameHash = UINT64_C(5007375205011789513);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_StyleUpdate(int64_t value);

    static const char kSendBeginMainFrameToCommit_UpdateLayersName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_UpdateLayersNameHash = UINT64_C(6804362734965297093);
    Graphics_Smoothness_EventLatency& SetSendBeginMainFrameToCommit_UpdateLayers(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrameName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrameNameHash = UINT64_C(6674140523643808969);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash = UINT64_C(607984992502472994);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReady(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash = UINT64_C(2975991725388751644);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatch(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash = UINT64_C(10347268106263508021);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEnd(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash = UINT64_C(11186016080733742173);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDraw(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash = UINT64_C(7210524409551472901);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStart(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash = UINT64_C(14306474530895290443);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrame(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash = UINT64_C(838162815137783913);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrame(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash = UINT64_C(6636157383910377693);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailable(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash = UINT64_C(6621395714715301150);
    Graphics_Smoothness_EventLatency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEnd(int64_t value);

    static const char kTotalLatencyName[];
    static constexpr uint64_t kTotalLatencyNameHash = UINT64_C(1484146670166706245);
    Graphics_Smoothness_EventLatency& SetTotalLatency(int64_t value);
};

class Graphics_Smoothness_Latency final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Graphics_Smoothness_Latency(ukm::SourceId source_id);
    explicit Graphics_Smoothness_Latency(ukm::SourceIdObj source_id);
    Graphics_Smoothness_Latency(Graphics_Smoothness_Latency&&);
    Graphics_Smoothness_Latency& operator=(Graphics_Smoothness_Latency&&);
    ~Graphics_Smoothness_Latency() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4259890394998283936);

    static const char kActivationName[];
    static constexpr uint64_t kActivationNameHash = UINT64_C(12224509299331452166);
    Graphics_Smoothness_Latency& SetActivation(int64_t value);

    static const char kBeginImplFrameToSendBeginMainFrameName[];
    static constexpr uint64_t kBeginImplFrameToSendBeginMainFrameNameHash = UINT64_C(17008172611226938782);
    Graphics_Smoothness_Latency& SetBeginImplFrameToSendBeginMainFrame(int64_t value);

    static const char kCanvasAnimationName[];
    static constexpr uint64_t kCanvasAnimationNameHash = UINT64_C(1503700410924474831);
    Graphics_Smoothness_Latency& SetCanvasAnimation(int64_t value);

    static const char kCommitName[];
    static constexpr uint64_t kCommitNameHash = UINT64_C(6473274705490247427);
    Graphics_Smoothness_Latency& SetCommit(int64_t value);

    static const char kCompositorAnimationName[];
    static constexpr uint64_t kCompositorAnimationNameHash = UINT64_C(11839765941398348215);
    Graphics_Smoothness_Latency& SetCompositorAnimation(int64_t value);

    static const char kEndActivateToSubmitCompositorFrameName[];
    static constexpr uint64_t kEndActivateToSubmitCompositorFrameNameHash = UINT64_C(16428909035706792583);
    Graphics_Smoothness_Latency& SetEndActivateToSubmitCompositorFrame(int64_t value);

    static const char kEndCommitToActivationName[];
    static constexpr uint64_t kEndCommitToActivationNameHash = UINT64_C(3830696727341877188);
    Graphics_Smoothness_Latency& SetEndCommitToActivation(int64_t value);

    static const char kJSAnimationName[];
    static constexpr uint64_t kJSAnimationNameHash = UINT64_C(1267442116416858132);
    Graphics_Smoothness_Latency& SetJSAnimation(int64_t value);

    static const char kMainThreadAnimationName[];
    static constexpr uint64_t kMainThreadAnimationNameHash = UINT64_C(17585341169403378470);
    Graphics_Smoothness_Latency& SetMainThreadAnimation(int64_t value);

    static const char kMissedFrameName[];
    static constexpr uint64_t kMissedFrameNameHash = UINT64_C(4476428804431606583);
    Graphics_Smoothness_Latency& SetMissedFrame(int64_t value);

    static const char kPinchZoomName[];
    static constexpr uint64_t kPinchZoomNameHash = UINT64_C(12064032880897582979);
    Graphics_Smoothness_Latency& SetPinchZoom(int64_t value);

    static const char kRAFName[];
    static constexpr uint64_t kRAFNameHash = UINT64_C(5697873212277685907);
    Graphics_Smoothness_Latency& SetRAF(int64_t value);

    static const char kScrollbarScrollName[];
    static constexpr uint64_t kScrollbarScrollNameHash = UINT64_C(9305810171768318292);
    Graphics_Smoothness_Latency& SetScrollbarScroll(int64_t value);

    static const char kSendBeginMainFrameToCommitName[];
    static constexpr uint64_t kSendBeginMainFrameToCommitNameHash = UINT64_C(4533040338292079001);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit(int64_t value);

    static const char kSendBeginMainFrameToCommit_AccessibilityName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_AccessibilityNameHash = UINT64_C(4688218205422913270);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_Accessibility(int64_t value);

    static const char kSendBeginMainFrameToCommit_AnimateName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_AnimateNameHash = UINT64_C(8343767389934127044);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_Animate(int64_t value);

    static const char kSendBeginMainFrameToCommit_BeginMainSentToStartedName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash = UINT64_C(5384975942974359718);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_BeginMainSentToStarted(int64_t value);

    static const char kSendBeginMainFrameToCommit_CompositeCommitName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_CompositeCommitNameHash = UINT64_C(10575954611204518961);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_CompositeCommit(int64_t value);

    static const char kSendBeginMainFrameToCommit_CompositingInputsName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_CompositingInputsNameHash = UINT64_C(829465320820564719);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_CompositingInputs(int64_t value);

    static const char kSendBeginMainFrameToCommit_HandleInputEventsName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_HandleInputEventsNameHash = UINT64_C(1165118933490711579);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_HandleInputEvents(int64_t value);

    static const char kSendBeginMainFrameToCommit_LayoutUpdateName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_LayoutUpdateNameHash = UINT64_C(10225608126652137034);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_LayoutUpdate(int64_t value);

    static const char kSendBeginMainFrameToCommit_PaintName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_PaintNameHash = UINT64_C(232555831202593428);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_Paint(int64_t value);

    static const char kSendBeginMainFrameToCommit_PrepaintName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_PrepaintNameHash = UINT64_C(14043047910485169633);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_Prepaint(int64_t value);

    static const char kSendBeginMainFrameToCommit_StyleUpdateName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_StyleUpdateNameHash = UINT64_C(5007375205011789513);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_StyleUpdate(int64_t value);

    static const char kSendBeginMainFrameToCommit_UpdateLayersName[];
    static constexpr uint64_t kSendBeginMainFrameToCommit_UpdateLayersNameHash = UINT64_C(6804362734965297093);
    Graphics_Smoothness_Latency& SetSendBeginMainFrameToCommit_UpdateLayers(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrameName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrameNameHash = UINT64_C(6674140523643808969);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash = UINT64_C(607984992502472994);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReady(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash = UINT64_C(2975991725388751644);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatch(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash = UINT64_C(10347268106263508021);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEnd(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash = UINT64_C(11186016080733742173);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDraw(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash = UINT64_C(7210524409551472901);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStart(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash = UINT64_C(14306474530895290443);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrame(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash = UINT64_C(838162815137783913);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrame(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash = UINT64_C(6636157383910377693);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailable(int64_t value);

    static const char kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName[];
    static constexpr uint64_t kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash = UINT64_C(6621395714715301150);
    Graphics_Smoothness_Latency& SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEnd(int64_t value);

    static const char kTotalLatencyName[];
    static constexpr uint64_t kTotalLatencyNameHash = UINT64_C(1484146670166706245);
    Graphics_Smoothness_Latency& SetTotalLatency(int64_t value);

    static const char kTouchScrollName[];
    static constexpr uint64_t kTouchScrollNameHash = UINT64_C(11899565240377852355);
    Graphics_Smoothness_Latency& SetTouchScroll(int64_t value);

    static const char kUnknownName[];
    static constexpr uint64_t kUnknownNameHash = UINT64_C(9806653697265365224);
    Graphics_Smoothness_Latency& SetUnknown(int64_t value);

    static const char kVideoName[];
    static constexpr uint64_t kVideoNameHash = UINT64_C(3810838688059735925);
    Graphics_Smoothness_Latency& SetVideo(int64_t value);

    static const char kWheelScrollName[];
    static constexpr uint64_t kWheelScrollNameHash = UINT64_C(82067021580369146);
    Graphics_Smoothness_Latency& SetWheelScroll(int64_t value);
};

class Graphics_Smoothness_NormalizedPercentDroppedFrames final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Graphics_Smoothness_NormalizedPercentDroppedFrames(ukm::SourceId source_id);
    explicit Graphics_Smoothness_NormalizedPercentDroppedFrames(ukm::SourceIdObj source_id);
    Graphics_Smoothness_NormalizedPercentDroppedFrames(Graphics_Smoothness_NormalizedPercentDroppedFrames&&);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& operator=(Graphics_Smoothness_NormalizedPercentDroppedFrames&&);
    ~Graphics_Smoothness_NormalizedPercentDroppedFrames() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5416874090953909475);

    static const char kAboveThresholdName[];
    static constexpr uint64_t kAboveThresholdNameHash = UINT64_C(3903388314598942607);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetAboveThreshold(int64_t value);

    static const char kAverageName[];
    static constexpr uint64_t kAverageNameHash = UINT64_C(12792884953155676512);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetAverage(int64_t value);

    static const char kCompositorFocusedMedianName[];
    static constexpr uint64_t kCompositorFocusedMedianNameHash = UINT64_C(2936504768399187226);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetCompositorFocusedMedian(int64_t value);

    static const char kCompositorFocusedPercentile95Name[];
    static constexpr uint64_t kCompositorFocusedPercentile95NameHash = UINT64_C(4480940570121275805);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetCompositorFocusedPercentile95(int64_t value);

    static const char kCompositorFocusedVarianceName[];
    static constexpr uint64_t kCompositorFocusedVarianceNameHash = UINT64_C(10328726722931190470);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetCompositorFocusedVariance(int64_t value);

    static const char kMainFocusedMedianName[];
    static constexpr uint64_t kMainFocusedMedianNameHash = UINT64_C(11909684403478958995);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetMainFocusedMedian(int64_t value);

    static const char kMainFocusedPercentile95Name[];
    static constexpr uint64_t kMainFocusedPercentile95NameHash = UINT64_C(12623533431636334946);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetMainFocusedPercentile95(int64_t value);

    static const char kMainFocusedVarianceName[];
    static constexpr uint64_t kMainFocusedVarianceNameHash = UINT64_C(15087842090678866286);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetMainFocusedVariance(int64_t value);

    static const char kMedianName[];
    static constexpr uint64_t kMedianNameHash = UINT64_C(7387339603919136090);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetMedian(int64_t value);

    static const char kPercentile95Name[];
    static constexpr uint64_t kPercentile95NameHash = UINT64_C(18351270367364284124);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetPercentile95(int64_t value);

    static const char kScrollFocusedMedianName[];
    static constexpr uint64_t kScrollFocusedMedianNameHash = UINT64_C(3260963509836071598);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetScrollFocusedMedian(int64_t value);

    static const char kScrollFocusedPercentile95Name[];
    static constexpr uint64_t kScrollFocusedPercentile95NameHash = UINT64_C(17595818103802445409);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetScrollFocusedPercentile95(int64_t value);

    static const char kScrollFocusedVarianceName[];
    static constexpr uint64_t kScrollFocusedVarianceNameHash = UINT64_C(10455972019816888927);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetScrollFocusedVariance(int64_t value);

    static const char kSmoothnessBadName[];
    static constexpr uint64_t kSmoothnessBadNameHash = UINT64_C(3383047832445944032);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessBad(int64_t value);

    static const char kSmoothnessGoodName[];
    static constexpr uint64_t kSmoothnessGoodNameHash = UINT64_C(6836816183999771224);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessGood(int64_t value);

    static const char kSmoothnessOkayName[];
    static constexpr uint64_t kSmoothnessOkayNameHash = UINT64_C(11999494808220352729);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessOkay(int64_t value);

    static const char kSmoothnessVeryBad25to50Name[];
    static constexpr uint64_t kSmoothnessVeryBad25to50NameHash = UINT64_C(10857937547338961432);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessVeryBad25to50(int64_t value);

    static const char kSmoothnessVeryBad50to75Name[];
    static constexpr uint64_t kSmoothnessVeryBad50to75NameHash = UINT64_C(12230252104172721554);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessVeryBad50to75(int64_t value);

    static const char kSmoothnessVeryBad75to100Name[];
    static constexpr uint64_t kSmoothnessVeryBad75to100NameHash = UINT64_C(17149138532113449568);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessVeryBad75to100(int64_t value);

    static const char kSmoothnessVeryGoodName[];
    static constexpr uint64_t kSmoothnessVeryGoodNameHash = UINT64_C(16960412765821659222);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetSmoothnessVeryGood(int64_t value);

    static const char kVarianceName[];
    static constexpr uint64_t kVarianceNameHash = UINT64_C(8073767802488514059);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetVariance(int64_t value);

    static const char kWorstCaseName[];
    static constexpr uint64_t kWorstCaseNameHash = UINT64_C(12634461731091244720);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetWorstCase(int64_t value);

    static const char kWorstCaseAfter1SecName[];
    static constexpr uint64_t kWorstCaseAfter1SecNameHash = UINT64_C(6530659958993034807);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetWorstCaseAfter1Sec(int64_t value);

    static const char kWorstCaseAfter2SecName[];
    static constexpr uint64_t kWorstCaseAfter2SecNameHash = UINT64_C(5627268941328769276);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetWorstCaseAfter2Sec(int64_t value);

    static const char kWorstCaseAfter5SecName[];
    static constexpr uint64_t kWorstCaseAfter5SecNameHash = UINT64_C(15590784865345700361);
    Graphics_Smoothness_NormalizedPercentDroppedFrames& SetWorstCaseAfter5Sec(int64_t value);
};

class HistoryClusters final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit HistoryClusters(ukm::SourceId source_id);
    explicit HistoryClusters(ukm::SourceIdObj source_id);
    HistoryClusters(HistoryClusters&&);
    HistoryClusters& operator=(HistoryClusters&&);
    ~HistoryClusters() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13892688012376547748);

    static const char kFinalStateName[];
    static constexpr uint64_t kFinalStateNameHash = UINT64_C(7135263041449206789);
    HistoryClusters& SetFinalState(int64_t value);

    static const char kInitialStateName[];
    static constexpr uint64_t kInitialStateNameHash = UINT64_C(5039075195775411013);
    HistoryClusters& SetInitialState(int64_t value);

    static const char kNumQueriesName[];
    static constexpr uint64_t kNumQueriesNameHash = UINT64_C(13072389686557582886);
    HistoryClusters& SetNumQueries(int64_t value);

    static const char kNumTogglesToBasicHistoryName[];
    static constexpr uint64_t kNumTogglesToBasicHistoryNameHash = UINT64_C(10473942860530549088);
    HistoryClusters& SetNumTogglesToBasicHistory(int64_t value);
};

class HistoryManipulationIntervention final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit HistoryManipulationIntervention(ukm::SourceId source_id);
    explicit HistoryManipulationIntervention(ukm::SourceIdObj source_id);
    HistoryManipulationIntervention(HistoryManipulationIntervention&&);
    HistoryManipulationIntervention& operator=(HistoryManipulationIntervention&&);
    ~HistoryManipulationIntervention() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17985071802125984440);
};

class HistoryNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit HistoryNavigation(ukm::SourceId source_id);
    explicit HistoryNavigation(ukm::SourceIdObj source_id);
    HistoryNavigation(HistoryNavigation&&);
    HistoryNavigation& operator=(HistoryNavigation&&);
    ~HistoryNavigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6390056345493314213);

    static const char kBackForwardCache_BlocklistedFeaturesName[];
    static constexpr uint64_t kBackForwardCache_BlocklistedFeaturesNameHash = UINT64_C(114784820077506701);
    HistoryNavigation& SetBackForwardCache_BlocklistedFeatures(int64_t value);

    static const char kBackForwardCache_BlocklistedFeatures2Name[];
    static constexpr uint64_t kBackForwardCache_BlocklistedFeatures2NameHash = UINT64_C(12490312374099468714);
    HistoryNavigation& SetBackForwardCache_BlocklistedFeatures2(int64_t value);

    static const char kBackForwardCache_BrowsingInstanceNotSwappedReasonName[];
    static constexpr uint64_t kBackForwardCache_BrowsingInstanceNotSwappedReasonNameHash = UINT64_C(15224206336538316);
    HistoryNavigation& SetBackForwardCache_BrowsingInstanceNotSwappedReason(int64_t value);

    static const char kBackForwardCache_DisabledForRenderFrameHostReasonCountName[];
    static constexpr uint64_t kBackForwardCache_DisabledForRenderFrameHostReasonCountNameHash = UINT64_C(15251262755855394501);
    HistoryNavigation& SetBackForwardCache_DisabledForRenderFrameHostReasonCount(int64_t value);

    static const char kBackForwardCache_IsAmpPageName[];
    static constexpr uint64_t kBackForwardCache_IsAmpPageNameHash = UINT64_C(4085141071540433903);
    HistoryNavigation& SetBackForwardCache_IsAmpPage(int64_t value);

    static const char kBackForwardCache_IsServedFromBackForwardCacheName[];
    static constexpr uint64_t kBackForwardCache_IsServedFromBackForwardCacheNameHash = UINT64_C(4696927693770382140);
    HistoryNavigation& SetBackForwardCache_IsServedFromBackForwardCache(int64_t value);

    static const char kBackForwardCache_NotRestoredReasonsName[];
    static constexpr uint64_t kBackForwardCache_NotRestoredReasonsNameHash = UINT64_C(1788460300115305264);
    HistoryNavigation& SetBackForwardCache_NotRestoredReasons(int64_t value);

    static const char kBackForwardCache_NotRestoredReasons2Name[];
    static constexpr uint64_t kBackForwardCache_NotRestoredReasons2NameHash = UINT64_C(4374969420623314852);
    HistoryNavigation& SetBackForwardCache_NotRestoredReasons2(int64_t value);

    static const char kCrossOriginSubframesFeaturesName[];
    static constexpr uint64_t kCrossOriginSubframesFeaturesNameHash = UINT64_C(15837216398858754148);
    HistoryNavigation& SetCrossOriginSubframesFeatures(int64_t value);

    static const char kCrossOriginSubframesFeatures2Name[];
    static constexpr uint64_t kCrossOriginSubframesFeatures2NameHash = UINT64_C(7787312135955237572);
    HistoryNavigation& SetCrossOriginSubframesFeatures2(int64_t value);

    static const char kCumulativeShiftScoreAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kCumulativeShiftScoreAfterBackForwardCacheRestoreNameHash = UINT64_C(4082107668430352853);
    HistoryNavigation& SetCumulativeShiftScoreAfterBackForwardCacheRestore(int64_t value);

    static const char kFirstInputDelayAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kFirstInputDelayAfterBackForwardCacheRestoreNameHash = UINT64_C(6232396995651525280);
    HistoryNavigation& SetFirstInputDelayAfterBackForwardCacheRestore(int64_t value);

    static const char kFirstRequestAnimationFrameAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kFirstRequestAnimationFrameAfterBackForwardCacheRestoreNameHash = UINT64_C(3321594754409068745);
    HistoryNavigation& SetFirstRequestAnimationFrameAfterBackForwardCacheRestore(int64_t value);

    static const char kForegroundDurationAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kForegroundDurationAfterBackForwardCacheRestoreNameHash = UINT64_C(13393782889429555662);
    HistoryNavigation& SetForegroundDurationAfterBackForwardCacheRestore(int64_t value);

    static const char kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName[];
    static constexpr uint64_t kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash = UINT64_C(10950301779928294410);
    HistoryNavigation& SetLastCommittedCrossDocumentNavigationSourceIdForTheSameDocument(int64_t value);

    static const char kMainFrameFeaturesName[];
    static constexpr uint64_t kMainFrameFeaturesNameHash = UINT64_C(277837253456542220);
    HistoryNavigation& SetMainFrameFeatures(int64_t value);

    static const char kMainFrameFeatures2Name[];
    static constexpr uint64_t kMainFrameFeatures2NameHash = UINT64_C(14711264664655245299);
    HistoryNavigation& SetMainFrameFeatures2(int64_t value);

    static const char kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msNameHash = UINT64_C(16084589991671433247);
    HistoryNavigation& SetMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kNavigatedToTheMostRecentEntryForDocumentName[];
    static constexpr uint64_t kNavigatedToTheMostRecentEntryForDocumentNameHash = UINT64_C(16985983351931289345);
    HistoryNavigation& SetNavigatedToTheMostRecentEntryForDocument(int64_t value);

    static const char kNavigationToFirstPaintAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kNavigationToFirstPaintAfterBackForwardCacheRestoreNameHash = UINT64_C(8986422447916353406);
    HistoryNavigation& SetNavigationToFirstPaintAfterBackForwardCacheRestore(int64_t value);

    static const char kNumInteractionsAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kNumInteractionsAfterBackForwardCacheRestoreNameHash = UINT64_C(3253999485075899832);
    HistoryNavigation& SetNumInteractionsAfterBackForwardCacheRestore(int64_t value);

    static const char kPageEndReasonAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kPageEndReasonAfterBackForwardCacheRestoreNameHash = UINT64_C(7249663761797243316);
    HistoryNavigation& SetPageEndReasonAfterBackForwardCacheRestore(int64_t value);

    static const char kSameOriginSubframesFeaturesName[];
    static constexpr uint64_t kSameOriginSubframesFeaturesNameHash = UINT64_C(3171771254759560933);
    HistoryNavigation& SetSameOriginSubframesFeatures(int64_t value);

    static const char kSameOriginSubframesFeatures2Name[];
    static constexpr uint64_t kSameOriginSubframesFeatures2NameHash = UINT64_C(12242339053610681573);
    HistoryNavigation& SetSameOriginSubframesFeatures2(int64_t value);

    static const char kSecondRequestAnimationFrameAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kSecondRequestAnimationFrameAfterBackForwardCacheRestoreNameHash = UINT64_C(78690090811193125);
    HistoryNavigation& SetSecondRequestAnimationFrameAfterBackForwardCacheRestore(int64_t value);

    static const char kThirdRequestAnimationFrameAfterBackForwardCacheRestoreName[];
    static constexpr uint64_t kThirdRequestAnimationFrameAfterBackForwardCacheRestoreNameHash = UINT64_C(2281099162348055178);
    HistoryNavigation& SetThirdRequestAnimationFrameAfterBackForwardCacheRestore(int64_t value);

    static const char kTimeSinceNavigatedAwayFromDocumentName[];
    static constexpr uint64_t kTimeSinceNavigatedAwayFromDocumentNameHash = UINT64_C(17394368525671091150);
    HistoryNavigation& SetTimeSinceNavigatedAwayFromDocument(int64_t value);

    static const char kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationNameHash = UINT64_C(7140223734474251815);
    HistoryNavigation& SetUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2Name[];
    static constexpr uint64_t kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2NameHash = UINT64_C(5982705054977473584);
    HistoryNavigation& SetWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2(int64_t value);
};

class Identifiability final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Identifiability(ukm::SourceId source_id);
    explicit Identifiability(ukm::SourceIdObj source_id);
    Identifiability(Identifiability&&);
    Identifiability& operator=(Identifiability&&);
    ~Identifiability() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(287024497009309687);

    static const char kGeneratorVersion_926Name[];
    static constexpr uint64_t kGeneratorVersion_926NameHash = UINT64_C(896956215682477568);
    Identifiability& SetGeneratorVersion_926(int64_t value);

    static const char kStudyGeneration_626Name[];
    static constexpr uint64_t kStudyGeneration_626NameHash = UINT64_C(11181185366848792576);
    Identifiability& SetStudyGeneration_626(int64_t value);
};

class InputMethod_Assistive_AutocorrectV2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit InputMethod_Assistive_AutocorrectV2(ukm::SourceId source_id);
    explicit InputMethod_Assistive_AutocorrectV2(ukm::SourceIdObj source_id);
    InputMethod_Assistive_AutocorrectV2(InputMethod_Assistive_AutocorrectV2&&);
    InputMethod_Assistive_AutocorrectV2& operator=(InputMethod_Assistive_AutocorrectV2&&);
    ~InputMethod_Assistive_AutocorrectV2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7967874514472474467);

    static const char kCompatibilitySummary_PKName[];
    static constexpr uint64_t kCompatibilitySummary_PKNameHash = UINT64_C(11910860897010613815);
    InputMethod_Assistive_AutocorrectV2& SetCompatibilitySummary_PK(int64_t value);

    static const char kCompatibilitySummary_VKName[];
    static constexpr uint64_t kCompatibilitySummary_VKNameHash = UINT64_C(6747491273244920612);
    InputMethod_Assistive_AutocorrectV2& SetCompatibilitySummary_VK(int64_t value);
};

class InputMethod_Assistive_Match final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit InputMethod_Assistive_Match(ukm::SourceId source_id);
    explicit InputMethod_Assistive_Match(ukm::SourceIdObj source_id);
    InputMethod_Assistive_Match(InputMethod_Assistive_Match&&);
    InputMethod_Assistive_Match& operator=(InputMethod_Assistive_Match&&);
    ~InputMethod_Assistive_Match() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16471533519799856378);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    InputMethod_Assistive_Match& SetType(int64_t value);
};

class InputMethod_LongpressDiacritics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit InputMethod_LongpressDiacritics(ukm::SourceId source_id);
    explicit InputMethod_LongpressDiacritics(ukm::SourceIdObj source_id);
    InputMethod_LongpressDiacritics(InputMethod_LongpressDiacritics&&);
    InputMethod_LongpressDiacritics& operator=(InputMethod_LongpressDiacritics&&);
    ~InputMethod_LongpressDiacritics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5032272348630134775);

    static const char kActionsName[];
    static constexpr uint64_t kActionsNameHash = UINT64_C(495170559598752135);
    InputMethod_LongpressDiacritics& SetActions(int64_t value);
};

class InputMethod_Manta_Orca final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit InputMethod_Manta_Orca(ukm::SourceId source_id);
    explicit InputMethod_Manta_Orca(ukm::SourceIdObj source_id);
    InputMethod_Manta_Orca(InputMethod_Manta_Orca&&);
    InputMethod_Manta_Orca& operator=(InputMethod_Manta_Orca&&);
    ~InputMethod_Manta_Orca() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17658006784147474164);

    static const char kEditorCriticalStatesName[];
    static constexpr uint64_t kEditorCriticalStatesNameHash = UINT64_C(10983627744125380786);
    InputMethod_Manta_Orca& SetEditorCriticalStates(int64_t value);
};

class InputMethod_NonCompliantApi final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit InputMethod_NonCompliantApi(ukm::SourceId source_id);
    explicit InputMethod_NonCompliantApi(ukm::SourceIdObj source_id);
    InputMethod_NonCompliantApi(InputMethod_NonCompliantApi&&);
    InputMethod_NonCompliantApi& operator=(InputMethod_NonCompliantApi&&);
    ~InputMethod_NonCompliantApi() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16790499697963531667);

    static const char kNonCompliantOperationName[];
    static constexpr uint64_t kNonCompliantOperationNameHash = UINT64_C(4174906312331753936);
    InputMethod_NonCompliantApi& SetNonCompliantOperation(int64_t value);
};

class InstalledRelatedApps final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit InstalledRelatedApps(ukm::SourceId source_id);
    explicit InstalledRelatedApps(ukm::SourceIdObj source_id);
    InstalledRelatedApps(InstalledRelatedApps&&);
    InstalledRelatedApps& operator=(InstalledRelatedApps&&);
    ~InstalledRelatedApps() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1640774753589741944);

    static const char kCalledName[];
    static constexpr uint64_t kCalledNameHash = UINT64_C(3312022293166359599);
    InstalledRelatedApps& SetCalled(int64_t value);
};

class IOS_FindInPageSearchMatches final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_FindInPageSearchMatches(ukm::SourceId source_id);
    explicit IOS_FindInPageSearchMatches(ukm::SourceIdObj source_id);
    IOS_FindInPageSearchMatches(IOS_FindInPageSearchMatches&&);
    IOS_FindInPageSearchMatches& operator=(IOS_FindInPageSearchMatches&&);
    ~IOS_FindInPageSearchMatches() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3999691266874322037);

    static const char kHasMatchesName[];
    static constexpr uint64_t kHasMatchesNameHash = UINT64_C(7077976188191291377);
    IOS_FindInPageSearchMatches& SetHasMatches(int64_t value);
};

class IOS_FullscreenActions final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_FullscreenActions(ukm::SourceId source_id);
    explicit IOS_FullscreenActions(ukm::SourceIdObj source_id);
    IOS_FullscreenActions(IOS_FullscreenActions&&);
    IOS_FullscreenActions& operator=(IOS_FullscreenActions&&);
    ~IOS_FullscreenActions() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8606631182486356401);

    static const char kHasExitedManuallyName[];
    static constexpr uint64_t kHasExitedManuallyNameHash = UINT64_C(4428608387087079722);
    IOS_FullscreenActions& SetHasExitedManually(int64_t value);
};

class IOS_IsDefaultBrowser final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_IsDefaultBrowser(ukm::SourceId source_id);
    explicit IOS_IsDefaultBrowser(ukm::SourceIdObj source_id);
    IOS_IsDefaultBrowser(IOS_IsDefaultBrowser&&);
    IOS_IsDefaultBrowser& operator=(IOS_IsDefaultBrowser&&);
    ~IOS_IsDefaultBrowser() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9401651119910784407);

    static const char kIsDefaultBrowserName[];
    static constexpr uint64_t kIsDefaultBrowserNameHash = UINT64_C(7467500293102567370);
    IOS_IsDefaultBrowser& SetIsDefaultBrowser(int64_t value);
};

class IOS_PageAddedToReadingList final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_PageAddedToReadingList(ukm::SourceId source_id);
    explicit IOS_PageAddedToReadingList(ukm::SourceIdObj source_id);
    IOS_PageAddedToReadingList(IOS_PageAddedToReadingList&&);
    IOS_PageAddedToReadingList& operator=(IOS_PageAddedToReadingList&&);
    ~IOS_PageAddedToReadingList() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11840518206463876002);

    static const char kAddedFromMessagesName[];
    static constexpr uint64_t kAddedFromMessagesNameHash = UINT64_C(1961682952303606781);
    IOS_PageAddedToReadingList& SetAddedFromMessages(int64_t value);
};

class IOS_PageReadability final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_PageReadability(ukm::SourceId source_id);
    explicit IOS_PageReadability(ukm::SourceIdObj source_id);
    IOS_PageReadability(IOS_PageReadability&&);
    IOS_PageReadability& operator=(IOS_PageReadability&&);
    ~IOS_PageReadability() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3910969266183986451);

    static const char kDidAcceptName[];
    static constexpr uint64_t kDidAcceptNameHash = UINT64_C(17852604745261628300);
    IOS_PageReadability& SetDidAccept(int64_t value);

    static const char kDistilibilityLongScoreName[];
    static constexpr uint64_t kDistilibilityLongScoreNameHash = UINT64_C(8675445402769829925);
    IOS_PageReadability& SetDistilibilityLongScore(int64_t value);

    static const char kDistilibilityScoreName[];
    static constexpr uint64_t kDistilibilityScoreNameHash = UINT64_C(7383956097092266897);
    IOS_PageReadability& SetDistilibilityScore(int64_t value);
};

class IOS_PageZoomChanged final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_PageZoomChanged(ukm::SourceId source_id);
    explicit IOS_PageZoomChanged(ukm::SourceIdObj source_id);
    IOS_PageZoomChanged(IOS_PageZoomChanged&&);
    IOS_PageZoomChanged& operator=(IOS_PageZoomChanged&&);
    ~IOS_PageZoomChanged() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4631281682778806273);

    static const char kContentSizeCategoryName[];
    static constexpr uint64_t kContentSizeCategoryNameHash = UINT64_C(17224924781030716348);
    IOS_PageZoomChanged& SetContentSizeCategory(int64_t value);

    static const char kOverallZoomLevelName[];
    static constexpr uint64_t kOverallZoomLevelNameHash = UINT64_C(2817337295596296593);
    IOS_PageZoomChanged& SetOverallZoomLevel(int64_t value);

    static const char kUserZoomLevelName[];
    static constexpr uint64_t kUserZoomLevelNameHash = UINT64_C(13800606689589064956);
    IOS_PageZoomChanged& SetUserZoomLevel(int64_t value);
};

class IOS_ParcelTrackingNumberDetected final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_ParcelTrackingNumberDetected(ukm::SourceId source_id);
    explicit IOS_ParcelTrackingNumberDetected(ukm::SourceIdObj source_id);
    IOS_ParcelTrackingNumberDetected(IOS_ParcelTrackingNumberDetected&&);
    IOS_ParcelTrackingNumberDetected& operator=(IOS_ParcelTrackingNumberDetected&&);
    ~IOS_ParcelTrackingNumberDetected() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1914766108595585505);

    static const char kParcelCarrierName[];
    static constexpr uint64_t kParcelCarrierNameHash = UINT64_C(14499665619527503005);
    IOS_ParcelTrackingNumberDetected& SetParcelCarrier(int64_t value);
};

class IOS_RendererGone final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit IOS_RendererGone(ukm::SourceId source_id);
    explicit IOS_RendererGone(ukm::SourceIdObj source_id);
    IOS_RendererGone(IOS_RendererGone&&);
    IOS_RendererGone& operator=(IOS_RendererGone&&);
    ~IOS_RendererGone() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10713578431670288986);

    static const char kAliveRecentlyRendererCountName[];
    static constexpr uint64_t kAliveRecentlyRendererCountNameHash = UINT64_C(14933446705995907612);
    IOS_RendererGone& SetAliveRecentlyRendererCount(int64_t value);

    static const char kAliveRendererCountName[];
    static constexpr uint64_t kAliveRendererCountNameHash = UINT64_C(4517554268483005232);
    IOS_RendererGone& SetAliveRendererCount(int64_t value);

    static const char kInForegroundName[];
    static constexpr uint64_t kInForegroundNameHash = UINT64_C(16087321402939566058);
    IOS_RendererGone& SetInForeground(int64_t value);

    static const char kSawMemoryWarningName[];
    static constexpr uint64_t kSawMemoryWarningNameHash = UINT64_C(449336318584050538);
    IOS_RendererGone& SetSawMemoryWarning(int64_t value);
};

class JavascriptFrameworkPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit JavascriptFrameworkPageLoad(ukm::SourceId source_id);
    explicit JavascriptFrameworkPageLoad(ukm::SourceIdObj source_id);
    JavascriptFrameworkPageLoad(JavascriptFrameworkPageLoad&&);
    JavascriptFrameworkPageLoad& operator=(JavascriptFrameworkPageLoad&&);
    ~JavascriptFrameworkPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7566859152267022983);

    static const char kAngularPageLoadName[];
    static constexpr uint64_t kAngularPageLoadNameHash = UINT64_C(13552620467552978003);
    JavascriptFrameworkPageLoad& SetAngularPageLoad(int64_t value);

    static const char kGatsbyPageLoadName[];
    static constexpr uint64_t kGatsbyPageLoadNameHash = UINT64_C(4108469667928385957);
    JavascriptFrameworkPageLoad& SetGatsbyPageLoad(int64_t value);

    static const char kNextJSPageLoadName[];
    static constexpr uint64_t kNextJSPageLoadNameHash = UINT64_C(5823716105324724425);
    JavascriptFrameworkPageLoad& SetNextJSPageLoad(int64_t value);

    static const char kNuxtJSPageLoadName[];
    static constexpr uint64_t kNuxtJSPageLoadNameHash = UINT64_C(150717109492864455);
    JavascriptFrameworkPageLoad& SetNuxtJSPageLoad(int64_t value);

    static const char kPreactPageLoadName[];
    static constexpr uint64_t kPreactPageLoadNameHash = UINT64_C(11528801525600169466);
    JavascriptFrameworkPageLoad& SetPreactPageLoad(int64_t value);

    static const char kReactPageLoadName[];
    static constexpr uint64_t kReactPageLoadNameHash = UINT64_C(823515382138530380);
    JavascriptFrameworkPageLoad& SetReactPageLoad(int64_t value);

    static const char kSapperPageLoadName[];
    static constexpr uint64_t kSapperPageLoadNameHash = UINT64_C(2407371090215998108);
    JavascriptFrameworkPageLoad& SetSapperPageLoad(int64_t value);

    static const char kSveltePageLoadName[];
    static constexpr uint64_t kSveltePageLoadNameHash = UINT64_C(12098081645028349776);
    JavascriptFrameworkPageLoad& SetSveltePageLoad(int64_t value);

    static const char kVuePageLoadName[];
    static constexpr uint64_t kVuePageLoadNameHash = UINT64_C(511177896623175404);
    JavascriptFrameworkPageLoad& SetVuePageLoad(int64_t value);

    static const char kVuePressPageLoadName[];
    static constexpr uint64_t kVuePressPageLoadNameHash = UINT64_C(10107093448791977777);
    JavascriptFrameworkPageLoad& SetVuePressPageLoad(int64_t value);
};

class Lens_Overlay_ContextualSearchbox_FocusedInSession final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_ContextualSearchbox_FocusedInSession(ukm::SourceId source_id);
    explicit Lens_Overlay_ContextualSearchbox_FocusedInSession(ukm::SourceIdObj source_id);
    Lens_Overlay_ContextualSearchbox_FocusedInSession(Lens_Overlay_ContextualSearchbox_FocusedInSession&&);
    Lens_Overlay_ContextualSearchbox_FocusedInSession& operator=(Lens_Overlay_ContextualSearchbox_FocusedInSession&&);
    ~Lens_Overlay_ContextualSearchbox_FocusedInSession() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14790400947302801717);

    static const char kFocusedInSessionName[];
    static constexpr uint64_t kFocusedInSessionNameHash = UINT64_C(9919582130806925857);
    Lens_Overlay_ContextualSearchbox_FocusedInSession& SetFocusedInSession(int64_t value);

    static const char kPageContentTypeName[];
    static constexpr uint64_t kPageContentTypeNameHash = UINT64_C(17397618346801192939);
    Lens_Overlay_ContextualSearchbox_FocusedInSession& SetPageContentType(int64_t value);
};

class Lens_Overlay_ContextualSearchBox_ShownInSession final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_ContextualSearchBox_ShownInSession(ukm::SourceId source_id);
    explicit Lens_Overlay_ContextualSearchBox_ShownInSession(ukm::SourceIdObj source_id);
    Lens_Overlay_ContextualSearchBox_ShownInSession(Lens_Overlay_ContextualSearchBox_ShownInSession&&);
    Lens_Overlay_ContextualSearchBox_ShownInSession& operator=(Lens_Overlay_ContextualSearchBox_ShownInSession&&);
    ~Lens_Overlay_ContextualSearchBox_ShownInSession() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11898097730227890116);

    static const char kPageContentTypeName[];
    static constexpr uint64_t kPageContentTypeNameHash = UINT64_C(17397618346801192939);
    Lens_Overlay_ContextualSearchBox_ShownInSession& SetPageContentType(int64_t value);

    static const char kWasShownName[];
    static constexpr uint64_t kWasShownNameHash = UINT64_C(1833388152196336106);
    Lens_Overlay_ContextualSearchBox_ShownInSession& SetWasShown(int64_t value);
};

class Lens_Overlay_ContextualSuggest_QueryIssuedInSession final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_ContextualSuggest_QueryIssuedInSession(ukm::SourceId source_id);
    explicit Lens_Overlay_ContextualSuggest_QueryIssuedInSession(ukm::SourceIdObj source_id);
    Lens_Overlay_ContextualSuggest_QueryIssuedInSession(Lens_Overlay_ContextualSuggest_QueryIssuedInSession&&);
    Lens_Overlay_ContextualSuggest_QueryIssuedInSession& operator=(Lens_Overlay_ContextualSuggest_QueryIssuedInSession&&);
    ~Lens_Overlay_ContextualSuggest_QueryIssuedInSession() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9359961652274800012);

    static const char kPageContentTypeName[];
    static constexpr uint64_t kPageContentTypeNameHash = UINT64_C(17397618346801192939);
    Lens_Overlay_ContextualSuggest_QueryIssuedInSession& SetPageContentType(int64_t value);

    static const char kQueryIssuedInSessionName[];
    static constexpr uint64_t kQueryIssuedInSessionNameHash = UINT64_C(3662967535407194652);
    Lens_Overlay_ContextualSuggest_QueryIssuedInSession& SetQueryIssuedInSession(int64_t value);
};

class Lens_Overlay_ContextualSuggest_ZPS_ShownInSession final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_ContextualSuggest_ZPS_ShownInSession(ukm::SourceId source_id);
    explicit Lens_Overlay_ContextualSuggest_ZPS_ShownInSession(ukm::SourceIdObj source_id);
    Lens_Overlay_ContextualSuggest_ZPS_ShownInSession(Lens_Overlay_ContextualSuggest_ZPS_ShownInSession&&);
    Lens_Overlay_ContextualSuggest_ZPS_ShownInSession& operator=(Lens_Overlay_ContextualSuggest_ZPS_ShownInSession&&);
    ~Lens_Overlay_ContextualSuggest_ZPS_ShownInSession() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5556638233503911795);

    static const char kPageContentTypeName[];
    static constexpr uint64_t kPageContentTypeNameHash = UINT64_C(17397618346801192939);
    Lens_Overlay_ContextualSuggest_ZPS_ShownInSession& SetPageContentType(int64_t value);

    static const char kShownInSessionName[];
    static constexpr uint64_t kShownInSessionNameHash = UINT64_C(12175188342780322484);
    Lens_Overlay_ContextualSuggest_ZPS_ShownInSession& SetShownInSession(int64_t value);
};

class Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession(ukm::SourceId source_id);
    explicit Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession(ukm::SourceIdObj source_id);
    Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession(Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession&&);
    Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession& operator=(Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession&&);
    ~Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16393195650402138039);

    static const char kPageContentTypeName[];
    static constexpr uint64_t kPageContentTypeNameHash = UINT64_C(17397618346801192939);
    Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession& SetPageContentType(int64_t value);

    static const char kSuggestionUsedInSessionName[];
    static constexpr uint64_t kSuggestionUsedInSessionNameHash = UINT64_C(12027047663256293755);
    Lens_Overlay_ContextualSuggest_ZPS_SuggestionUsedInSession& SetSuggestionUsedInSession(int64_t value);
};

class Lens_Overlay_Overlay_UserAction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_Overlay_UserAction(ukm::SourceId source_id);
    explicit Lens_Overlay_Overlay_UserAction(ukm::SourceIdObj source_id);
    Lens_Overlay_Overlay_UserAction(Lens_Overlay_Overlay_UserAction&&);
    Lens_Overlay_Overlay_UserAction& operator=(Lens_Overlay_Overlay_UserAction&&);
    ~Lens_Overlay_Overlay_UserAction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4208315803724186419);

    static const char kUserActionName[];
    static constexpr uint64_t kUserActionNameHash = UINT64_C(11431707273815549887);
    Lens_Overlay_Overlay_UserAction& SetUserAction(int64_t value);
};

class Lens_Overlay_SessionEnd final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_SessionEnd(ukm::SourceId source_id);
    explicit Lens_Overlay_SessionEnd(ukm::SourceIdObj source_id);
    Lens_Overlay_SessionEnd(Lens_Overlay_SessionEnd&&);
    Lens_Overlay_SessionEnd& operator=(Lens_Overlay_SessionEnd&&);
    ~Lens_Overlay_SessionEnd() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8217894806744583515);

    static const char kGeneratedTabCountName[];
    static constexpr uint64_t kGeneratedTabCountNameHash = UINT64_C(11138156723043859947);
    Lens_Overlay_SessionEnd& SetGeneratedTabCount(int64_t value);

    static const char kInvocationDocumentTypeName[];
    static constexpr uint64_t kInvocationDocumentTypeNameHash = UINT64_C(16415390191737992739);
    Lens_Overlay_SessionEnd& SetInvocationDocumentType(int64_t value);

    static const char kInvocationResultedInSearchName[];
    static constexpr uint64_t kInvocationResultedInSearchNameHash = UINT64_C(13225125722547883947);
    Lens_Overlay_SessionEnd& SetInvocationResultedInSearch(int64_t value);

    static const char kInvocationSourceName[];
    static constexpr uint64_t kInvocationSourceNameHash = UINT64_C(4280034365802741276);
    Lens_Overlay_SessionEnd& SetInvocationSource(int64_t value);

    static const char kSessionDurationName[];
    static constexpr uint64_t kSessionDurationNameHash = UINT64_C(2701974374748336509);
    Lens_Overlay_SessionEnd& SetSessionDuration(int64_t value);

    static const char kSessionForegroundDurationName[];
    static constexpr uint64_t kSessionForegroundDurationNameHash = UINT64_C(17470917332838606804);
    Lens_Overlay_SessionEnd& SetSessionForegroundDuration(int64_t value);
};

class Lens_Overlay_TimeToFirstInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Lens_Overlay_TimeToFirstInteraction(ukm::SourceId source_id);
    explicit Lens_Overlay_TimeToFirstInteraction(ukm::SourceIdObj source_id);
    Lens_Overlay_TimeToFirstInteraction(Lens_Overlay_TimeToFirstInteraction&&);
    Lens_Overlay_TimeToFirstInteraction& operator=(Lens_Overlay_TimeToFirstInteraction&&);
    ~Lens_Overlay_TimeToFirstInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6105502683077053997);

    static const char kAllEntryPointsName[];
    static constexpr uint64_t kAllEntryPointsNameHash = UINT64_C(2704925644952786737);
    Lens_Overlay_TimeToFirstInteraction& SetAllEntryPoints(int64_t value);

    static const char kAppMenuName[];
    static constexpr uint64_t kAppMenuNameHash = UINT64_C(17719311607275536276);
    Lens_Overlay_TimeToFirstInteraction& SetAppMenu(int64_t value);

    static const char kContentAreaContextMenuPageName[];
    static constexpr uint64_t kContentAreaContextMenuPageNameHash = UINT64_C(5485907601239034751);
    Lens_Overlay_TimeToFirstInteraction& SetContentAreaContextMenuPage(int64_t value);

    static const char kFindInPageName[];
    static constexpr uint64_t kFindInPageNameHash = UINT64_C(53139942253372262);
    Lens_Overlay_TimeToFirstInteraction& SetFindInPage(int64_t value);

    static const char kFirstInteractionTypeName[];
    static constexpr uint64_t kFirstInteractionTypeNameHash = UINT64_C(11791166981310733131);
    Lens_Overlay_TimeToFirstInteraction& SetFirstInteractionType(int64_t value);

    static const char kOmniboxName[];
    static constexpr uint64_t kOmniboxNameHash = UINT64_C(3147878021189006333);
    Lens_Overlay_TimeToFirstInteraction& SetOmnibox(int64_t value);

    static const char kToolbarName[];
    static constexpr uint64_t kToolbarNameHash = UINT64_C(17223392293291764532);
    Lens_Overlay_TimeToFirstInteraction& SetToolbar(int64_t value);
};

class LoadCountsPerTopLevelDocument final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit LoadCountsPerTopLevelDocument(ukm::SourceId source_id);
    explicit LoadCountsPerTopLevelDocument(ukm::SourceIdObj source_id);
    LoadCountsPerTopLevelDocument(LoadCountsPerTopLevelDocument&&);
    LoadCountsPerTopLevelDocument& operator=(LoadCountsPerTopLevelDocument&&);
    ~LoadCountsPerTopLevelDocument() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2459509573580782733);

    static const char kNumMainFrameSameDocumentLoads_HiddenName[];
    static constexpr uint64_t kNumMainFrameSameDocumentLoads_HiddenNameHash = UINT64_C(16308380425819769916);
    LoadCountsPerTopLevelDocument& SetNumMainFrameSameDocumentLoads_Hidden(int64_t value);

    static const char kNumMainFrameSameDocumentLoads_VisibleName[];
    static constexpr uint64_t kNumMainFrameSameDocumentLoads_VisibleNameHash = UINT64_C(18311735560954025968);
    LoadCountsPerTopLevelDocument& SetNumMainFrameSameDocumentLoads_Visible(int64_t value);

    static const char kNumSubFrameDifferentDocumentLoads_HiddenName[];
    static constexpr uint64_t kNumSubFrameDifferentDocumentLoads_HiddenNameHash = UINT64_C(14731836721542179442);
    LoadCountsPerTopLevelDocument& SetNumSubFrameDifferentDocumentLoads_Hidden(int64_t value);

    static const char kNumSubFrameDifferentDocumentLoads_VisibleName[];
    static constexpr uint64_t kNumSubFrameDifferentDocumentLoads_VisibleNameHash = UINT64_C(3665858183442379349);
    LoadCountsPerTopLevelDocument& SetNumSubFrameDifferentDocumentLoads_Visible(int64_t value);

    static const char kNumSubFrameSameDocumentLoads_HiddenName[];
    static constexpr uint64_t kNumSubFrameSameDocumentLoads_HiddenNameHash = UINT64_C(1725595575573050);
    LoadCountsPerTopLevelDocument& SetNumSubFrameSameDocumentLoads_Hidden(int64_t value);

    static const char kNumSubFrameSameDocumentLoads_VisibleName[];
    static constexpr uint64_t kNumSubFrameSameDocumentLoads_VisibleNameHash = UINT64_C(6499928911562111241);
    LoadCountsPerTopLevelDocument& SetNumSubFrameSameDocumentLoads_Visible(int64_t value);
};

class LoadingPredictor final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit LoadingPredictor(ukm::SourceId source_id);
    explicit LoadingPredictor(ukm::SourceIdObj source_id);
    LoadingPredictor(LoadingPredictor&&);
    LoadingPredictor& operator=(LoadingPredictor&&);
    ~LoadingPredictor() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17180165945688341623);

    static const char kCorrectSubresourceOriginPreconnectsInitiatedName[];
    static constexpr uint64_t kCorrectSubresourceOriginPreconnectsInitiatedNameHash = UINT64_C(11018846185563416109);
    LoadingPredictor& SetCorrectSubresourceOriginPreconnectsInitiated(int64_t value);

    static const char kCorrectSubresourcePrefetchesInitiatedName[];
    static constexpr uint64_t kCorrectSubresourcePrefetchesInitiatedNameHash = UINT64_C(7523816529585587032);
    LoadingPredictor& SetCorrectSubresourcePrefetchesInitiated(int64_t value);

    static const char kLocalPredictionCorrectlyPredictedOriginsName[];
    static constexpr uint64_t kLocalPredictionCorrectlyPredictedOriginsNameHash = UINT64_C(11890392650600702934);
    LoadingPredictor& SetLocalPredictionCorrectlyPredictedOrigins(int64_t value);

    static const char kLocalPredictionOriginsName[];
    static constexpr uint64_t kLocalPredictionOriginsNameHash = UINT64_C(4632708717020315528);
    LoadingPredictor& SetLocalPredictionOrigins(int64_t value);

    static const char kNavigationStartToFirstSubresourcePrefetchInitiatedName[];
    static constexpr uint64_t kNavigationStartToFirstSubresourcePrefetchInitiatedNameHash = UINT64_C(13900753661740299906);
    LoadingPredictor& SetNavigationStartToFirstSubresourcePrefetchInitiated(int64_t value);

    static const char kNavigationStartToNavigationCommitName[];
    static constexpr uint64_t kNavigationStartToNavigationCommitNameHash = UINT64_C(3398767228309508687);
    LoadingPredictor& SetNavigationStartToNavigationCommit(int64_t value);

    static const char kNavigationStartToOptimizationGuidePredictionArrivedName[];
    static constexpr uint64_t kNavigationStartToOptimizationGuidePredictionArrivedNameHash = UINT64_C(11075897637857966482);
    LoadingPredictor& SetNavigationStartToOptimizationGuidePredictionArrived(int64_t value);

    static const char kOptimizationGuidePredictionCorrectlyPredictedLowPriorityOriginsName[];
    static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedLowPriorityOriginsNameHash = UINT64_C(15586807953357884308);
    LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedLowPriorityOrigins(int64_t value);

    static const char kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresourcesName[];
    static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresourcesNameHash = UINT64_C(1515034998121495627);
    LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresources(int64_t value);

    static const char kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresources_CrossOriginName[];
    static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresources_CrossOriginNameHash = UINT64_C(10012148044212070283);
    LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedLowPrioritySubresources_CrossOrigin(int64_t value);

    static const char kOptimizationGuidePredictionCorrectlyPredictedOriginsName[];
    static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash = UINT64_C(13684299638232047171);
    LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedOrigins(int64_t value);

    static const char kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName[];
    static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash = UINT64_C(10378504874380127147);
    LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedSubresources(int64_t value);

    static const char kOptimizationGuidePredictionCorrectlyPredictedSubresources_CrossOriginName[];
    static constexpr uint64_t kOptimizationGuidePredictionCorrectlyPredictedSubresources_CrossOriginNameHash = UINT64_C(467879980375881047);
    LoadingPredictor& SetOptimizationGuidePredictionCorrectlyPredictedSubresources_CrossOrigin(int64_t value);

    static const char kOptimizationGuidePredictionDecisionName[];
    static constexpr uint64_t kOptimizationGuidePredictionDecisionNameHash = UINT64_C(15337213847512842846);
    LoadingPredictor& SetOptimizationGuidePredictionDecision(int64_t value);

    static const char kOptimizationGuidePredictionOriginsName[];
    static constexpr uint64_t kOptimizationGuidePredictionOriginsNameHash = UINT64_C(15824464772807852023);
    LoadingPredictor& SetOptimizationGuidePredictionOrigins(int64_t value);

    static const char kOptimizationGuidePredictionSubresourcesName[];
    static constexpr uint64_t kOptimizationGuidePredictionSubresourcesNameHash = UINT64_C(16369424947811357892);
    LoadingPredictor& SetOptimizationGuidePredictionSubresources(int64_t value);

    static const char kOptimizationGuidePredictionSubresources_CrossOriginName[];
    static constexpr uint64_t kOptimizationGuidePredictionSubresources_CrossOriginNameHash = UINT64_C(10293156159448518626);
    LoadingPredictor& SetOptimizationGuidePredictionSubresources_CrossOrigin(int64_t value);

    static const char kSubresourceOriginPreconnectsInitiatedName[];
    static constexpr uint64_t kSubresourceOriginPreconnectsInitiatedNameHash = UINT64_C(207068642963595880);
    LoadingPredictor& SetSubresourceOriginPreconnectsInitiated(int64_t value);

    static const char kSubresourcePrefetchesInitiatedName[];
    static constexpr uint64_t kSubresourcePrefetchesInitiatedNameHash = UINT64_C(9230070991632882019);
    LoadingPredictor& SetSubresourcePrefetchesInitiated(int64_t value);
};

class LocalNetworkRequests final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit LocalNetworkRequests(ukm::SourceId source_id);
    explicit LocalNetworkRequests(ukm::SourceIdObj source_id);
    LocalNetworkRequests(LocalNetworkRequests&&);
    LocalNetworkRequests& operator=(LocalNetworkRequests&&);
    ~LocalNetworkRequests() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5563841616204153427);

    static const char kCount_FailedName[];
    static constexpr uint64_t kCount_FailedNameHash = UINT64_C(4332170555344799116);
    LocalNetworkRequests& SetCount_Failed(int64_t value);

    static const char kCount_SuccessfulName[];
    static constexpr uint64_t kCount_SuccessfulNameHash = UINT64_C(7366317784072625071);
    LocalNetworkRequests& SetCount_Successful(int64_t value);

    static const char kPortTypeName[];
    static constexpr uint64_t kPortTypeNameHash = UINT64_C(8660532902729963646);
    LocalNetworkRequests& SetPortType(int64_t value);

    static const char kResourceTypeName[];
    static constexpr uint64_t kResourceTypeNameHash = UINT64_C(13449604986098457094);
    LocalNetworkRequests& SetResourceType(int64_t value);
};

class LookalikeUrl_NavigationSuggestion final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit LookalikeUrl_NavigationSuggestion(ukm::SourceId source_id);
    explicit LookalikeUrl_NavigationSuggestion(ukm::SourceIdObj source_id);
    LookalikeUrl_NavigationSuggestion(LookalikeUrl_NavigationSuggestion&&);
    LookalikeUrl_NavigationSuggestion& operator=(LookalikeUrl_NavigationSuggestion&&);
    ~LookalikeUrl_NavigationSuggestion() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6455694443766360259);

    static const char kMatchTypeName[];
    static constexpr uint64_t kMatchTypeNameHash = UINT64_C(11181695565646487911);
    LookalikeUrl_NavigationSuggestion& SetMatchType(int64_t value);

    static const char kTriggeredByInitialUrlName[];
    static constexpr uint64_t kTriggeredByInitialUrlNameHash = UINT64_C(11438973251354417638);
    LookalikeUrl_NavigationSuggestion& SetTriggeredByInitialUrl(int64_t value);

    static const char kUserActionName[];
    static constexpr uint64_t kUserActionNameHash = UINT64_C(11431707273815549887);
    LookalikeUrl_NavigationSuggestion& SetUserAction(int64_t value);
};

class MainFrameNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MainFrameNavigation(ukm::SourceId source_id);
    explicit MainFrameNavigation(ukm::SourceIdObj source_id);
    MainFrameNavigation(MainFrameNavigation&&);
    MainFrameNavigation& operator=(MainFrameNavigation&&);
    ~MainFrameNavigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17528121675680665933);

    static const char kDidCommitName[];
    static constexpr uint64_t kDidCommitNameHash = UINT64_C(15090303392628531230);
    MainFrameNavigation& SetDidCommit(int64_t value);
};

class MainFrameNavigation_ZstdContentEncoding final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MainFrameNavigation_ZstdContentEncoding(ukm::SourceId source_id);
    explicit MainFrameNavigation_ZstdContentEncoding(ukm::SourceIdObj source_id);
    MainFrameNavigation_ZstdContentEncoding(MainFrameNavigation_ZstdContentEncoding&&);
    MainFrameNavigation_ZstdContentEncoding& operator=(MainFrameNavigation_ZstdContentEncoding&&);
    ~MainFrameNavigation_ZstdContentEncoding() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12440808905277294625);

    static const char kUsedZstdName[];
    static constexpr uint64_t kUsedZstdNameHash = UINT64_C(2287008842715863406);
    MainFrameNavigation_ZstdContentEncoding& SetUsedZstd(int64_t value);
};

class Media_Autoplay_Attempt final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Autoplay_Attempt(ukm::SourceId source_id);
    explicit Media_Autoplay_Attempt(ukm::SourceIdObj source_id);
    Media_Autoplay_Attempt(Media_Autoplay_Attempt&&);
    Media_Autoplay_Attempt& operator=(Media_Autoplay_Attempt&&);
    ~Media_Autoplay_Attempt() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15357501003006382777);

    static const char kAudioTrackName[];
    static constexpr uint64_t kAudioTrackNameHash = UINT64_C(11741394230508611626);
    Media_Autoplay_Attempt& SetAudioTrack(int64_t value);

    static const char kHighMediaEngagementName[];
    static constexpr uint64_t kHighMediaEngagementNameHash = UINT64_C(7387526769811817505);
    Media_Autoplay_Attempt& SetHighMediaEngagement(int64_t value);

    static const char kMutedName[];
    static constexpr uint64_t kMutedNameHash = UINT64_C(8116925261070264013);
    Media_Autoplay_Attempt& SetMuted(int64_t value);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    Media_Autoplay_Attempt& SetSource(int64_t value);

    static const char kUserGestureRequiredName[];
    static constexpr uint64_t kUserGestureRequiredNameHash = UINT64_C(18423189923073954832);
    Media_Autoplay_Attempt& SetUserGestureRequired(int64_t value);

    static const char kUserGestureStatusName[];
    static constexpr uint64_t kUserGestureStatusNameHash = UINT64_C(17118719080195994394);
    Media_Autoplay_Attempt& SetUserGestureStatus(int64_t value);

    static const char kVideoTrackName[];
    static constexpr uint64_t kVideoTrackNameHash = UINT64_C(4366426770158320744);
    Media_Autoplay_Attempt& SetVideoTrack(int64_t value);
};

class Media_Autoplay_AudioContext final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Autoplay_AudioContext(ukm::SourceId source_id);
    explicit Media_Autoplay_AudioContext(ukm::SourceIdObj source_id);
    Media_Autoplay_AudioContext(Media_Autoplay_AudioContext&&);
    Media_Autoplay_AudioContext& operator=(Media_Autoplay_AudioContext&&);
    ~Media_Autoplay_AudioContext() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2039378813737092278);

    static const char kSourceNodeStartedName[];
    static constexpr uint64_t kSourceNodeStartedNameHash = UINT64_C(10503181443482708212);
    Media_Autoplay_AudioContext& SetSourceNodeStarted(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    Media_Autoplay_AudioContext& SetStatus(int64_t value);

    static const char kUnlockTypeName[];
    static constexpr uint64_t kUnlockTypeNameHash = UINT64_C(11517746341786708229);
    Media_Autoplay_AudioContext& SetUnlockType(int64_t value);
};

class Media_Autoplay_Muted_UnmuteAction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Autoplay_Muted_UnmuteAction(ukm::SourceId source_id);
    explicit Media_Autoplay_Muted_UnmuteAction(ukm::SourceIdObj source_id);
    Media_Autoplay_Muted_UnmuteAction(Media_Autoplay_Muted_UnmuteAction&&);
    Media_Autoplay_Muted_UnmuteAction& operator=(Media_Autoplay_Muted_UnmuteAction&&);
    ~Media_Autoplay_Muted_UnmuteAction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3015822386723746523);

    static const char kResultName[];
    static constexpr uint64_t kResultNameHash = UINT64_C(10298151285721392449);
    Media_Autoplay_Muted_UnmuteAction& SetResult(int64_t value);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    Media_Autoplay_Muted_UnmuteAction& SetSource(int64_t value);
};

class Media_BasicPlayback final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_BasicPlayback(ukm::SourceId source_id);
    explicit Media_BasicPlayback(ukm::SourceIdObj source_id);
    Media_BasicPlayback(Media_BasicPlayback&&);
    Media_BasicPlayback& operator=(Media_BasicPlayback&&);
    ~Media_BasicPlayback() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8416658001170131658);

    static const char kAudioCodecName[];
    static constexpr uint64_t kAudioCodecNameHash = UINT64_C(1465592132233517979);
    Media_BasicPlayback& SetAudioCodec(int64_t value);

    static const char kAudioCodecProfileName[];
    static constexpr uint64_t kAudioCodecProfileNameHash = UINT64_C(15517112798891852308);
    Media_BasicPlayback& SetAudioCodecProfile(int64_t value);

    static const char kAudioDecoderNameName[];
    static constexpr uint64_t kAudioDecoderNameNameHash = UINT64_C(7400968670179001125);
    Media_BasicPlayback& SetAudioDecoderName(int64_t value);

    static const char kAudioEncryptionSchemeName[];
    static constexpr uint64_t kAudioEncryptionSchemeNameHash = UINT64_C(9279392719755629215);
    Media_BasicPlayback& SetAudioEncryptionScheme(int64_t value);

    static const char kAutoplayInitiatedName[];
    static constexpr uint64_t kAutoplayInitiatedNameHash = UINT64_C(5475295434443958193);
    Media_BasicPlayback& SetAutoplayInitiated(int64_t value);

    static const char kCompletedRebuffersCountName[];
    static constexpr uint64_t kCompletedRebuffersCountNameHash = UINT64_C(11401868138030856851);
    Media_BasicPlayback& SetCompletedRebuffersCount(int64_t value);

    static const char kCompletedRebuffersDurationName[];
    static constexpr uint64_t kCompletedRebuffersDurationNameHash = UINT64_C(7260457768772866332);
    Media_BasicPlayback& SetCompletedRebuffersDuration(int64_t value);

    static const char kDurationName[];
    static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
    Media_BasicPlayback& SetDuration(int64_t value);

    static const char kHasAudioName[];
    static constexpr uint64_t kHasAudioNameHash = UINT64_C(11107996916041070680);
    Media_BasicPlayback& SetHasAudio(int64_t value);

    static const char kHasVideoName[];
    static constexpr uint64_t kHasVideoNameHash = UINT64_C(14168404852977906041);
    Media_BasicPlayback& SetHasVideo(int64_t value);

    static const char kIsBackgroundName[];
    static constexpr uint64_t kIsBackgroundNameHash = UINT64_C(5213574143647769765);
    Media_BasicPlayback& SetIsBackground(int64_t value);

    static const char kIsEMEName[];
    static constexpr uint64_t kIsEMENameHash = UINT64_C(9603548586615616861);
    Media_BasicPlayback& SetIsEME(int64_t value);

    static const char kIsMSEName[];
    static constexpr uint64_t kIsMSENameHash = UINT64_C(1649159027333078910);
    Media_BasicPlayback& SetIsMSE(int64_t value);

    static const char kIsMutedName[];
    static constexpr uint64_t kIsMutedNameHash = UINT64_C(16310095796065347619);
    Media_BasicPlayback& SetIsMuted(int64_t value);

    static const char kIsTopFrameName[];
    static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
    Media_BasicPlayback& SetIsTopFrame(int64_t value);

    static const char kLastPipelineStatusName[];
    static constexpr uint64_t kLastPipelineStatusNameHash = UINT64_C(7379597174511267180);
    Media_BasicPlayback& SetLastPipelineStatus(int64_t value);

    static const char kMeanTimeBetweenRebuffersName[];
    static constexpr uint64_t kMeanTimeBetweenRebuffersNameHash = UINT64_C(4184550771348788496);
    Media_BasicPlayback& SetMeanTimeBetweenRebuffers(int64_t value);

    static const char kMediaStreamTypeName[];
    static constexpr uint64_t kMediaStreamTypeNameHash = UINT64_C(15355014691788150092);
    Media_BasicPlayback& SetMediaStreamType(int64_t value);

    static const char kPlayerIDName[];
    static constexpr uint64_t kPlayerIDNameHash = UINT64_C(14726224399452516920);
    Media_BasicPlayback& SetPlayerID(int64_t value);

    static const char kRebuffersCountName[];
    static constexpr uint64_t kRebuffersCountNameHash = UINT64_C(13807071113907897713);
    Media_BasicPlayback& SetRebuffersCount(int64_t value);

    static const char kVideoCodecName[];
    static constexpr uint64_t kVideoCodecNameHash = UINT64_C(4277283989099800257);
    Media_BasicPlayback& SetVideoCodec(int64_t value);

    static const char kVideoCodecProfileName[];
    static constexpr uint64_t kVideoCodecProfileNameHash = UINT64_C(13549923910363567539);
    Media_BasicPlayback& SetVideoCodecProfile(int64_t value);

    static const char kVideoDecoderNameName[];
    static constexpr uint64_t kVideoDecoderNameNameHash = UINT64_C(2955371204855076682);
    Media_BasicPlayback& SetVideoDecoderName(int64_t value);

    static const char kVideoEncryptionSchemeName[];
    static constexpr uint64_t kVideoEncryptionSchemeNameHash = UINT64_C(8020364149971333246);
    Media_BasicPlayback& SetVideoEncryptionScheme(int64_t value);

    static const char kVideoFramesDecodedName[];
    static constexpr uint64_t kVideoFramesDecodedNameHash = UINT64_C(5249207403669740374);
    Media_BasicPlayback& SetVideoFramesDecoded(int64_t value);

    static const char kVideoFramesDroppedName[];
    static constexpr uint64_t kVideoFramesDroppedNameHash = UINT64_C(16832572534571948703);
    Media_BasicPlayback& SetVideoFramesDropped(int64_t value);

    static const char kVideoNaturalHeightName[];
    static constexpr uint64_t kVideoNaturalHeightNameHash = UINT64_C(1900038218584603521);
    Media_BasicPlayback& SetVideoNaturalHeight(int64_t value);

    static const char kVideoNaturalWidthName[];
    static constexpr uint64_t kVideoNaturalWidthNameHash = UINT64_C(7910695112651016017);
    Media_BasicPlayback& SetVideoNaturalWidth(int64_t value);

    static const char kWatchTimeName[];
    static constexpr uint64_t kWatchTimeNameHash = UINT64_C(4238353176698564424);
    Media_BasicPlayback& SetWatchTime(int64_t value);

    static const char kWatchTime_ACName[];
    static constexpr uint64_t kWatchTime_ACNameHash = UINT64_C(12245748949786056651);
    Media_BasicPlayback& SetWatchTime_AC(int64_t value);

    static const char kWatchTime_BatteryName[];
    static constexpr uint64_t kWatchTime_BatteryNameHash = UINT64_C(4816984999048658540);
    Media_BasicPlayback& SetWatchTime_Battery(int64_t value);

    static const char kWatchTime_DisplayFullscreenName[];
    static constexpr uint64_t kWatchTime_DisplayFullscreenNameHash = UINT64_C(17627238861389141605);
    Media_BasicPlayback& SetWatchTime_DisplayFullscreen(int64_t value);

    static const char kWatchTime_DisplayInlineName[];
    static constexpr uint64_t kWatchTime_DisplayInlineNameHash = UINT64_C(6904900890184958698);
    Media_BasicPlayback& SetWatchTime_DisplayInline(int64_t value);

    static const char kWatchTime_DisplayPictureInPictureName[];
    static constexpr uint64_t kWatchTime_DisplayPictureInPictureNameHash = UINT64_C(16046220114157168716);
    Media_BasicPlayback& SetWatchTime_DisplayPictureInPicture(int64_t value);

    static const char kWatchTime_NativeControlsOffName[];
    static constexpr uint64_t kWatchTime_NativeControlsOffNameHash = UINT64_C(10500999714956221012);
    Media_BasicPlayback& SetWatchTime_NativeControlsOff(int64_t value);

    static const char kWatchTime_NativeControlsOnName[];
    static constexpr uint64_t kWatchTime_NativeControlsOnNameHash = UINT64_C(7643229976440928650);
    Media_BasicPlayback& SetWatchTime_NativeControlsOn(int64_t value);
};

class Media_EME_ApiPromiseRejection final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_EME_ApiPromiseRejection(ukm::SourceId source_id);
    explicit Media_EME_ApiPromiseRejection(ukm::SourceIdObj source_id);
    Media_EME_ApiPromiseRejection(Media_EME_ApiPromiseRejection&&);
    Media_EME_ApiPromiseRejection& operator=(Media_EME_ApiPromiseRejection&&);
    ~Media_EME_ApiPromiseRejection() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7968428823878627316);

    static const char kApiName[];
    static constexpr uint64_t kApiNameHash = UINT64_C(8243361657487571724);
    Media_EME_ApiPromiseRejection& SetApi(int64_t value);

    static const char kKeySystemName[];
    static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
    Media_EME_ApiPromiseRejection& SetKeySystem(int64_t value);

    static const char kSystemCodeName[];
    static constexpr uint64_t kSystemCodeNameHash = UINT64_C(2228946995368470143);
    Media_EME_ApiPromiseRejection& SetSystemCode(int64_t value);

    static const char kUseHardwareSecureCodecsName[];
    static constexpr uint64_t kUseHardwareSecureCodecsNameHash = UINT64_C(10329498823065174552);
    Media_EME_ApiPromiseRejection& SetUseHardwareSecureCodecs(int64_t value);
};

class Media_EME_CdmSystemCode final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_EME_CdmSystemCode(ukm::SourceId source_id);
    explicit Media_EME_CdmSystemCode(ukm::SourceIdObj source_id);
    Media_EME_CdmSystemCode(Media_EME_CdmSystemCode&&);
    Media_EME_CdmSystemCode& operator=(Media_EME_CdmSystemCode&&);
    ~Media_EME_CdmSystemCode() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2589665349945066342);

    static const char kCdmSystemCodeName[];
    static constexpr uint64_t kCdmSystemCodeNameHash = UINT64_C(16995300388684951006);
    Media_EME_CdmSystemCode& SetCdmSystemCode(int64_t value);
};

class Media_EME_CreateMediaKeys final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_EME_CreateMediaKeys(ukm::SourceId source_id);
    explicit Media_EME_CreateMediaKeys(ukm::SourceIdObj source_id);
    Media_EME_CreateMediaKeys(Media_EME_CreateMediaKeys&&);
    Media_EME_CreateMediaKeys& operator=(Media_EME_CreateMediaKeys&&);
    ~Media_EME_CreateMediaKeys() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16664479587726188526);

    static const char kIsAdFrameName[];
    static constexpr uint64_t kIsAdFrameNameHash = UINT64_C(4919021348770235533);
    Media_EME_CreateMediaKeys& SetIsAdFrame(int64_t value);

    static const char kIsCrossOriginName[];
    static constexpr uint64_t kIsCrossOriginNameHash = UINT64_C(9876972617887417766);
    Media_EME_CreateMediaKeys& SetIsCrossOrigin(int64_t value);

    static const char kIsTopFrameName[];
    static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
    Media_EME_CreateMediaKeys& SetIsTopFrame(int64_t value);

    static const char kKeySystemName[];
    static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
    Media_EME_CreateMediaKeys& SetKeySystem(int64_t value);
};

class Media_EME_GetStatusForPolicy final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_EME_GetStatusForPolicy(ukm::SourceId source_id);
    explicit Media_EME_GetStatusForPolicy(ukm::SourceIdObj source_id);
    Media_EME_GetStatusForPolicy(Media_EME_GetStatusForPolicy&&);
    Media_EME_GetStatusForPolicy& operator=(Media_EME_GetStatusForPolicy&&);
    ~Media_EME_GetStatusForPolicy() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6913636598201291698);

    static const char kIsAdFrameName[];
    static constexpr uint64_t kIsAdFrameNameHash = UINT64_C(4919021348770235533);
    Media_EME_GetStatusForPolicy& SetIsAdFrame(int64_t value);

    static const char kKeySystemName[];
    static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
    Media_EME_GetStatusForPolicy& SetKeySystem(int64_t value);

    static const char kMinHdcpVersionName[];
    static constexpr uint64_t kMinHdcpVersionNameHash = UINT64_C(8902558389256612494);
    Media_EME_GetStatusForPolicy& SetMinHdcpVersion(int64_t value);

    static const char kUseHardwareSecureCodecsName[];
    static constexpr uint64_t kUseHardwareSecureCodecsNameHash = UINT64_C(10329498823065174552);
    Media_EME_GetStatusForPolicy& SetUseHardwareSecureCodecs(int64_t value);
};

class Media_EME_RequestMediaKeySystemAccess final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_EME_RequestMediaKeySystemAccess(ukm::SourceId source_id);
    explicit Media_EME_RequestMediaKeySystemAccess(ukm::SourceIdObj source_id);
    Media_EME_RequestMediaKeySystemAccess(Media_EME_RequestMediaKeySystemAccess&&);
    Media_EME_RequestMediaKeySystemAccess& operator=(Media_EME_RequestMediaKeySystemAccess&&);
    ~Media_EME_RequestMediaKeySystemAccess() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14018069268047764723);

    static const char kIsAdFrameName[];
    static constexpr uint64_t kIsAdFrameNameHash = UINT64_C(4919021348770235533);
    Media_EME_RequestMediaKeySystemAccess& SetIsAdFrame(int64_t value);

    static const char kIsCrossOriginName[];
    static constexpr uint64_t kIsCrossOriginNameHash = UINT64_C(9876972617887417766);
    Media_EME_RequestMediaKeySystemAccess& SetIsCrossOrigin(int64_t value);

    static const char kIsFromMediaCapabilitiesName[];
    static constexpr uint64_t kIsFromMediaCapabilitiesNameHash = UINT64_C(11197489030203151970);
    Media_EME_RequestMediaKeySystemAccess& SetIsFromMediaCapabilities(int64_t value);

    static const char kIsTopFrameName[];
    static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
    Media_EME_RequestMediaKeySystemAccess& SetIsTopFrame(int64_t value);

    static const char kKeySystemName[];
    static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
    Media_EME_RequestMediaKeySystemAccess& SetKeySystem(int64_t value);

    static const char kVideoCapabilitiesName[];
    static constexpr uint64_t kVideoCapabilitiesNameHash = UINT64_C(16227477551914694738);
    Media_EME_RequestMediaKeySystemAccess& SetVideoCapabilities(int64_t value);

    static const char kVideoCapabilities_HasEmptyRobustnessName[];
    static constexpr uint64_t kVideoCapabilities_HasEmptyRobustnessNameHash = UINT64_C(6254942854308824331);
    Media_EME_RequestMediaKeySystemAccess& SetVideoCapabilities_HasEmptyRobustness(int64_t value);

    static const char kVideoCapabilities_HasHwSecureAllRobustnessName[];
    static constexpr uint64_t kVideoCapabilities_HasHwSecureAllRobustnessNameHash = UINT64_C(10921133155864908334);
    Media_EME_RequestMediaKeySystemAccess& SetVideoCapabilities_HasHwSecureAllRobustness(int64_t value);
};

class Media_EME_Usage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_EME_Usage(ukm::SourceId source_id);
    explicit Media_EME_Usage(ukm::SourceIdObj source_id);
    Media_EME_Usage(Media_EME_Usage&&);
    Media_EME_Usage& operator=(Media_EME_Usage&&);
    ~Media_EME_Usage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1964837187481381741);

    static const char kApiName[];
    static constexpr uint64_t kApiNameHash = UINT64_C(8243361657487571724);
    Media_EME_Usage& SetApi(int64_t value);

    static const char kIsPersistentSessionName[];
    static constexpr uint64_t kIsPersistentSessionNameHash = UINT64_C(16642493047262097868);
    Media_EME_Usage& SetIsPersistentSession(int64_t value);

    static const char kKeySystemName[];
    static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
    Media_EME_Usage& SetKeySystem(int64_t value);

    static const char kUseHardwareSecureCodecsName[];
    static constexpr uint64_t kUseHardwareSecureCodecsNameHash = UINT64_C(10329498823065174552);
    Media_EME_Usage& SetUseHardwareSecureCodecs(int64_t value);
};

class Media_Engagement_SessionFinished final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Engagement_SessionFinished(ukm::SourceId source_id);
    explicit Media_Engagement_SessionFinished(ukm::SourceIdObj source_id);
    Media_Engagement_SessionFinished(Media_Engagement_SessionFinished&&);
    Media_Engagement_SessionFinished& operator=(Media_Engagement_SessionFinished&&);
    ~Media_Engagement_SessionFinished() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(886585293387977076);

    static const char kEngagement_IsHighName[];
    static constexpr uint64_t kEngagement_IsHighNameHash = UINT64_C(3559175725154865187);
    Media_Engagement_SessionFinished& SetEngagement_IsHigh(int64_t value);

    static const char kEngagement_ScoreName[];
    static constexpr uint64_t kEngagement_ScoreNameHash = UINT64_C(6115011579945185747);
    Media_Engagement_SessionFinished& SetEngagement_Score(int64_t value);

    static const char kPlaybacks_TotalName[];
    static constexpr uint64_t kPlaybacks_TotalNameHash = UINT64_C(17419025647826460429);
    Media_Engagement_SessionFinished& SetPlaybacks_Total(int64_t value);

    static const char kPlayer_Audible_DeltaName[];
    static constexpr uint64_t kPlayer_Audible_DeltaNameHash = UINT64_C(17580650989425633909);
    Media_Engagement_SessionFinished& SetPlayer_Audible_Delta(int64_t value);

    static const char kPlayer_Significant_DeltaName[];
    static constexpr uint64_t kPlayer_Significant_DeltaNameHash = UINT64_C(1233203601745147659);
    Media_Engagement_SessionFinished& SetPlayer_Significant_Delta(int64_t value);

    static const char kVisits_TotalName[];
    static constexpr uint64_t kVisits_TotalNameHash = UINT64_C(8621457172620586317);
    Media_Engagement_SessionFinished& SetVisits_Total(int64_t value);
};

class Media_Engagement_ShortPlaybackIgnored final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Engagement_ShortPlaybackIgnored(ukm::SourceId source_id);
    explicit Media_Engagement_ShortPlaybackIgnored(ukm::SourceIdObj source_id);
    Media_Engagement_ShortPlaybackIgnored(Media_Engagement_ShortPlaybackIgnored&&);
    Media_Engagement_ShortPlaybackIgnored& operator=(Media_Engagement_ShortPlaybackIgnored&&);
    ~Media_Engagement_ShortPlaybackIgnored() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13016590436839167921);

    static const char kLengthName[];
    static constexpr uint64_t kLengthNameHash = UINT64_C(13414706430103511103);
    Media_Engagement_ShortPlaybackIgnored& SetLength(int64_t value);
};

class Media_Feed_Discover final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Feed_Discover(ukm::SourceId source_id);
    explicit Media_Feed_Discover(ukm::SourceIdObj source_id);
    Media_Feed_Discover(Media_Feed_Discover&&);
    Media_Feed_Discover& operator=(Media_Feed_Discover&&);
    ~Media_Feed_Discover() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9905764244590677619);

    static const char kHasMediaFeedName[];
    static constexpr uint64_t kHasMediaFeedNameHash = UINT64_C(8108709776245181348);
    Media_Feed_Discover& SetHasMediaFeed(int64_t value);
};

class Media_GlobalMediaControls_ActionButtonPressed final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_GlobalMediaControls_ActionButtonPressed(ukm::SourceId source_id);
    explicit Media_GlobalMediaControls_ActionButtonPressed(ukm::SourceIdObj source_id);
    Media_GlobalMediaControls_ActionButtonPressed(Media_GlobalMediaControls_ActionButtonPressed&&);
    Media_GlobalMediaControls_ActionButtonPressed& operator=(Media_GlobalMediaControls_ActionButtonPressed&&);
    ~Media_GlobalMediaControls_ActionButtonPressed() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14701475071317937048);

    static const char kMediaSessionActionName[];
    static constexpr uint64_t kMediaSessionActionNameHash = UINT64_C(12367086545883832195);
    Media_GlobalMediaControls_ActionButtonPressed& SetMediaSessionAction(int64_t value);
};

class Media_Learning_PredictionRecord final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_Learning_PredictionRecord(ukm::SourceId source_id);
    explicit Media_Learning_PredictionRecord(ukm::SourceIdObj source_id);
    Media_Learning_PredictionRecord(Media_Learning_PredictionRecord&&);
    Media_Learning_PredictionRecord& operator=(Media_Learning_PredictionRecord&&);
    ~Media_Learning_PredictionRecord() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5140299263436558885);

    static const char kLearningTaskName[];
    static constexpr uint64_t kLearningTaskNameHash = UINT64_C(3255462620316368086);
    Media_Learning_PredictionRecord& SetLearningTask(int64_t value);

    static const char kObservedValueName[];
    static constexpr uint64_t kObservedValueNameHash = UINT64_C(9335108307962014649);
    Media_Learning_PredictionRecord& SetObservedValue(int64_t value);

    static const char kPredictedValueName[];
    static constexpr uint64_t kPredictedValueNameHash = UINT64_C(14522200333545318594);
    Media_Learning_PredictionRecord& SetPredictedValue(int64_t value);

    static const char kTrainingDataSizeName[];
    static constexpr uint64_t kTrainingDataSizeNameHash = UINT64_C(17064345110121741748);
    Media_Learning_PredictionRecord& SetTrainingDataSize(int64_t value);

    static const char kTrainingDataTotalWeightName[];
    static constexpr uint64_t kTrainingDataTotalWeightNameHash = UINT64_C(7855079783080918129);
    Media_Learning_PredictionRecord& SetTrainingDataTotalWeight(int64_t value);
};

class Media_SiteMuted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_SiteMuted(ukm::SourceId source_id);
    explicit Media_SiteMuted(ukm::SourceIdObj source_id);
    Media_SiteMuted(Media_SiteMuted&&);
    Media_SiteMuted& operator=(Media_SiteMuted&&);
    ~Media_SiteMuted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9485702385711484844);

    static const char kMuteReasonName[];
    static constexpr uint64_t kMuteReasonNameHash = UINT64_C(11711049693295628292);
    Media_SiteMuted& SetMuteReason(int64_t value);
};

class Media_VideoDecodePerfRecord final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_VideoDecodePerfRecord(ukm::SourceId source_id);
    explicit Media_VideoDecodePerfRecord(ukm::SourceIdObj source_id);
    Media_VideoDecodePerfRecord(Media_VideoDecodePerfRecord&&);
    Media_VideoDecodePerfRecord& operator=(Media_VideoDecodePerfRecord&&);
    ~Media_VideoDecodePerfRecord() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4207699002180294249);

    static const char kPerf_ApiWouldClaimIsPowerEfficientName[];
    static constexpr uint64_t kPerf_ApiWouldClaimIsPowerEfficientNameHash = UINT64_C(5735887776585123091);
    Media_VideoDecodePerfRecord& SetPerf_ApiWouldClaimIsPowerEfficient(int64_t value);

    static const char kPerf_ApiWouldClaimIsSmoothName[];
    static constexpr uint64_t kPerf_ApiWouldClaimIsSmoothNameHash = UINT64_C(12671368491971530709);
    Media_VideoDecodePerfRecord& SetPerf_ApiWouldClaimIsSmooth(int64_t value);

    static const char kPerf_PastVideoFramesDecodedName[];
    static constexpr uint64_t kPerf_PastVideoFramesDecodedNameHash = UINT64_C(8441960325832700449);
    Media_VideoDecodePerfRecord& SetPerf_PastVideoFramesDecoded(int64_t value);

    static const char kPerf_PastVideoFramesDroppedName[];
    static constexpr uint64_t kPerf_PastVideoFramesDroppedNameHash = UINT64_C(18418972936520347850);
    Media_VideoDecodePerfRecord& SetPerf_PastVideoFramesDropped(int64_t value);

    static const char kPerf_PastVideoFramesPowerEfficientName[];
    static constexpr uint64_t kPerf_PastVideoFramesPowerEfficientNameHash = UINT64_C(7446723482648341353);
    Media_VideoDecodePerfRecord& SetPerf_PastVideoFramesPowerEfficient(int64_t value);

    static const char kPerf_RecordIsPowerEfficientName[];
    static constexpr uint64_t kPerf_RecordIsPowerEfficientNameHash = UINT64_C(8067819045200543647);
    Media_VideoDecodePerfRecord& SetPerf_RecordIsPowerEfficient(int64_t value);

    static const char kPerf_RecordIsSmoothName[];
    static constexpr uint64_t kPerf_RecordIsSmoothNameHash = UINT64_C(12667944347029598270);
    Media_VideoDecodePerfRecord& SetPerf_RecordIsSmooth(int64_t value);

    static const char kPerf_VideoFramesDecodedName[];
    static constexpr uint64_t kPerf_VideoFramesDecodedNameHash = UINT64_C(13148455826076313336);
    Media_VideoDecodePerfRecord& SetPerf_VideoFramesDecoded(int64_t value);

    static const char kPerf_VideoFramesDroppedName[];
    static constexpr uint64_t kPerf_VideoFramesDroppedNameHash = UINT64_C(9694095505089398065);
    Media_VideoDecodePerfRecord& SetPerf_VideoFramesDropped(int64_t value);

    static const char kPerf_VideoFramesPowerEfficientName[];
    static constexpr uint64_t kPerf_VideoFramesPowerEfficientNameHash = UINT64_C(977668949207851975);
    Media_VideoDecodePerfRecord& SetPerf_VideoFramesPowerEfficient(int64_t value);

    static const char kVideo_CodecProfileName[];
    static constexpr uint64_t kVideo_CodecProfileNameHash = UINT64_C(12697741592931889256);
    Media_VideoDecodePerfRecord& SetVideo_CodecProfile(int64_t value);

    static const char kVideo_EME_KeySystemName[];
    static constexpr uint64_t kVideo_EME_KeySystemNameHash = UINT64_C(15796328125282619455);
    Media_VideoDecodePerfRecord& SetVideo_EME_KeySystem(int64_t value);

    static const char kVideo_EME_UseHwSecureCodecsName[];
    static constexpr uint64_t kVideo_EME_UseHwSecureCodecsNameHash = UINT64_C(6542307800731144643);
    Media_VideoDecodePerfRecord& SetVideo_EME_UseHwSecureCodecs(int64_t value);

    static const char kVideo_FramesPerSecondName[];
    static constexpr uint64_t kVideo_FramesPerSecondNameHash = UINT64_C(9284015185136411749);
    Media_VideoDecodePerfRecord& SetVideo_FramesPerSecond(int64_t value);

    static const char kVideo_InTopFrameName[];
    static constexpr uint64_t kVideo_InTopFrameNameHash = UINT64_C(2486969173492159481);
    Media_VideoDecodePerfRecord& SetVideo_InTopFrame(int64_t value);

    static const char kVideo_NaturalHeightName[];
    static constexpr uint64_t kVideo_NaturalHeightNameHash = UINT64_C(6424389758392557464);
    Media_VideoDecodePerfRecord& SetVideo_NaturalHeight(int64_t value);

    static const char kVideo_NaturalWidthName[];
    static constexpr uint64_t kVideo_NaturalWidthNameHash = UINT64_C(12684813081500050839);
    Media_VideoDecodePerfRecord& SetVideo_NaturalWidth(int64_t value);

    static const char kVideo_PlayerIDName[];
    static constexpr uint64_t kVideo_PlayerIDNameHash = UINT64_C(11303151379432599370);
    Media_VideoDecodePerfRecord& SetVideo_PlayerID(int64_t value);
};

class Media_VideoEncoderMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_VideoEncoderMetrics(ukm::SourceId source_id);
    explicit Media_VideoEncoderMetrics(ukm::SourceIdObj source_id);
    Media_VideoEncoderMetrics(Media_VideoEncoderMetrics&&);
    Media_VideoEncoderMetrics& operator=(Media_VideoEncoderMetrics&&);
    ~Media_VideoEncoderMetrics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10025438409800124399);

    static const char kHeightName[];
    static constexpr uint64_t kHeightNameHash = UINT64_C(17205655745617698527);
    Media_VideoEncoderMetrics& SetHeight(int64_t value);

    static const char kIsHardwareName[];
    static constexpr uint64_t kIsHardwareNameHash = UINT64_C(15730202734576384953);
    Media_VideoEncoderMetrics& SetIsHardware(int64_t value);

    static const char kNumEncodedFramesName[];
    static constexpr uint64_t kNumEncodedFramesNameHash = UINT64_C(9752648202670057952);
    Media_VideoEncoderMetrics& SetNumEncodedFrames(int64_t value);

    static const char kProfileName[];
    static constexpr uint64_t kProfileNameHash = UINT64_C(14765504761742342519);
    Media_VideoEncoderMetrics& SetProfile(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    Media_VideoEncoderMetrics& SetStatus(int64_t value);

    static const char kSVCModeName[];
    static constexpr uint64_t kSVCModeNameHash = UINT64_C(12887912560710683559);
    Media_VideoEncoderMetrics& SetSVCMode(int64_t value);

    static const char kUseCaseName[];
    static constexpr uint64_t kUseCaseNameHash = UINT64_C(10388051568539810908);
    Media_VideoEncoderMetrics& SetUseCase(int64_t value);

    static const char kWidthName[];
    static constexpr uint64_t kWidthNameHash = UINT64_C(3644896802912593514);
    Media_VideoEncoderMetrics& SetWidth(int64_t value);
};

class Media_WebAudio_AudioContext_AudibleTime final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_WebAudio_AudioContext_AudibleTime(ukm::SourceId source_id);
    explicit Media_WebAudio_AudioContext_AudibleTime(ukm::SourceIdObj source_id);
    Media_WebAudio_AudioContext_AudibleTime(Media_WebAudio_AudioContext_AudibleTime&&);
    Media_WebAudio_AudioContext_AudibleTime& operator=(Media_WebAudio_AudioContext_AudibleTime&&);
    ~Media_WebAudio_AudioContext_AudibleTime() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17314038096102597390);

    static const char kAudibleTimeName[];
    static constexpr uint64_t kAudibleTimeNameHash = UINT64_C(12873745361743450640);
    Media_WebAudio_AudioContext_AudibleTime& SetAudibleTime(int64_t value);

    static const char kIsMainFrameName[];
    static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
    Media_WebAudio_AudioContext_AudibleTime& SetIsMainFrame(int64_t value);
};

class Media_WebMediaPlayerState final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Media_WebMediaPlayerState(ukm::SourceId source_id);
    explicit Media_WebMediaPlayerState(ukm::SourceIdObj source_id);
    Media_WebMediaPlayerState(Media_WebMediaPlayerState&&);
    Media_WebMediaPlayerState& operator=(Media_WebMediaPlayerState&&);
    ~Media_WebMediaPlayerState() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14428460888229388079);

    static const char kAudioEncryptionTypeName[];
    static constexpr uint64_t kAudioEncryptionTypeNameHash = UINT64_C(11499229094358771644);
    Media_WebMediaPlayerState& SetAudioEncryptionType(int64_t value);

    static const char kContainerNameName[];
    static constexpr uint64_t kContainerNameNameHash = UINT64_C(4418601378549410313);
    Media_WebMediaPlayerState& SetContainerName(int64_t value);

    static const char kFinalPipelineStatusName[];
    static constexpr uint64_t kFinalPipelineStatusNameHash = UINT64_C(10539654806699313254);
    Media_WebMediaPlayerState& SetFinalPipelineStatus(int64_t value);

    static const char kHasWaitingForKeyName[];
    static constexpr uint64_t kHasWaitingForKeyNameHash = UINT64_C(9578599779584082916);
    Media_WebMediaPlayerState& SetHasWaitingForKey(int64_t value);

    static const char kIsEMEName[];
    static constexpr uint64_t kIsEMENameHash = UINT64_C(9603548586615616861);
    Media_WebMediaPlayerState& SetIsEME(int64_t value);

    static const char kIsHardwareSecureName[];
    static constexpr uint64_t kIsHardwareSecureNameHash = UINT64_C(10876322141119295554);
    Media_WebMediaPlayerState& SetIsHardwareSecure(int64_t value);

    static const char kIsMSEName[];
    static constexpr uint64_t kIsMSENameHash = UINT64_C(1649159027333078910);
    Media_WebMediaPlayerState& SetIsMSE(int64_t value);

    static const char kIsTopFrameName[];
    static constexpr uint64_t kIsTopFrameNameHash = UINT64_C(12076906272811428831);
    Media_WebMediaPlayerState& SetIsTopFrame(int64_t value);

    static const char kKeySystemName[];
    static constexpr uint64_t kKeySystemNameHash = UINT64_C(3295482835808862800);
    Media_WebMediaPlayerState& SetKeySystem(int64_t value);

    static const char kPlayerIDName[];
    static constexpr uint64_t kPlayerIDNameHash = UINT64_C(14726224399452516920);
    Media_WebMediaPlayerState& SetPlayerID(int64_t value);

    static const char kRendererTypeName[];
    static constexpr uint64_t kRendererTypeNameHash = UINT64_C(11413923700170638273);
    Media_WebMediaPlayerState& SetRendererType(int64_t value);

    static const char kTimeToFirstFrameName[];
    static constexpr uint64_t kTimeToFirstFrameNameHash = UINT64_C(4692112185366530109);
    Media_WebMediaPlayerState& SetTimeToFirstFrame(int64_t value);

    static const char kTimeToMetadataName[];
    static constexpr uint64_t kTimeToMetadataNameHash = UINT64_C(4362545705166911725);
    Media_WebMediaPlayerState& SetTimeToMetadata(int64_t value);

    static const char kTimeToPlayReadyName[];
    static constexpr uint64_t kTimeToPlayReadyNameHash = UINT64_C(3934160282665258072);
    Media_WebMediaPlayerState& SetTimeToPlayReady(int64_t value);

    static const char kURLSchemeName[];
    static constexpr uint64_t kURLSchemeNameHash = UINT64_C(2127881778750603395);
    Media_WebMediaPlayerState& SetURLScheme(int64_t value);

    static const char kVideoEncryptionTypeName[];
    static constexpr uint64_t kVideoEncryptionTypeNameHash = UINT64_C(437856474141909026);
    Media_WebMediaPlayerState& SetVideoEncryptionType(int64_t value);
};

class MediaRouter_CastWebSenderExtensionLoadUrl final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MediaRouter_CastWebSenderExtensionLoadUrl(ukm::SourceId source_id);
    explicit MediaRouter_CastWebSenderExtensionLoadUrl(ukm::SourceIdObj source_id);
    MediaRouter_CastWebSenderExtensionLoadUrl(MediaRouter_CastWebSenderExtensionLoadUrl&&);
    MediaRouter_CastWebSenderExtensionLoadUrl& operator=(MediaRouter_CastWebSenderExtensionLoadUrl&&);
    ~MediaRouter_CastWebSenderExtensionLoadUrl() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3512705025017023804);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    MediaRouter_CastWebSenderExtensionLoadUrl& SetHasOccurred(int64_t value);
};

class MediaRouter_SiteInitiatedMirroringStarted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MediaRouter_SiteInitiatedMirroringStarted(ukm::SourceId source_id);
    explicit MediaRouter_SiteInitiatedMirroringStarted(ukm::SourceIdObj source_id);
    MediaRouter_SiteInitiatedMirroringStarted(MediaRouter_SiteInitiatedMirroringStarted&&);
    MediaRouter_SiteInitiatedMirroringStarted& operator=(MediaRouter_SiteInitiatedMirroringStarted&&);
    ~MediaRouter_SiteInitiatedMirroringStarted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16497635965856919352);

    static const char kAllowAudioCaptureName[];
    static constexpr uint64_t kAllowAudioCaptureNameHash = UINT64_C(14362034231575525713);
    MediaRouter_SiteInitiatedMirroringStarted& SetAllowAudioCapture(int64_t value);
};

class MediaRouter_TabMirroringStarted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MediaRouter_TabMirroringStarted(ukm::SourceId source_id);
    explicit MediaRouter_TabMirroringStarted(ukm::SourceIdObj source_id);
    MediaRouter_TabMirroringStarted(MediaRouter_TabMirroringStarted&&);
    MediaRouter_TabMirroringStarted& operator=(MediaRouter_TabMirroringStarted&&);
    ~MediaRouter_TabMirroringStarted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2088599620296425553);

    static const char kAudioStateName[];
    static constexpr uint64_t kAudioStateNameHash = UINT64_C(17285533685146397729);
    MediaRouter_TabMirroringStarted& SetAudioState(int64_t value);
};

class MediaStream_Device final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MediaStream_Device(ukm::SourceId source_id);
    explicit MediaStream_Device(ukm::SourceIdObj source_id);
    MediaStream_Device(MediaStream_Device&&);
    MediaStream_Device& operator=(MediaStream_Device&&);
    ~MediaStream_Device() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10994491282953221287);

    static const char kVideoCaptureGenerateStreamResultName[];
    static constexpr uint64_t kVideoCaptureGenerateStreamResultNameHash = UINT64_C(17205699474216734964);
    MediaStream_Device& SetVideoCaptureGenerateStreamResult(int64_t value);
};

class Memory_Experimental final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Memory_Experimental(ukm::SourceId source_id);
    explicit Memory_Experimental(ukm::SourceIdObj source_id);
    Memory_Experimental(Memory_Experimental&&);
    Memory_Experimental& operator=(Memory_Experimental&&);
    ~Memory_Experimental() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2958711939369432145);

    static const char kArrayBufferName[];
    static constexpr uint64_t kArrayBufferNameHash = UINT64_C(11725738762011925469);
    Memory_Experimental& SetArrayBuffer(int64_t value);

    static const char kBlinkGCName[];
    static constexpr uint64_t kBlinkGCNameHash = UINT64_C(7968550169431094519);
    Memory_Experimental& SetBlinkGC(int64_t value);

    static const char kBlinkGC_AllocatedObjectsName[];
    static constexpr uint64_t kBlinkGC_AllocatedObjectsNameHash = UINT64_C(2308711769835636489);
    Memory_Experimental& SetBlinkGC_AllocatedObjects(int64_t value);

    static const char kCommandBufferName[];
    static constexpr uint64_t kCommandBufferNameHash = UINT64_C(11751001059183415549);
    Memory_Experimental& SetCommandBuffer(int64_t value);

    static const char kDiscardableName[];
    static constexpr uint64_t kDiscardableNameHash = UINT64_C(200561209145538443);
    Memory_Experimental& SetDiscardable(int64_t value);

    static const char kDownloadServiceName[];
    static constexpr uint64_t kDownloadServiceNameHash = UINT64_C(7359304541321789172);
    Memory_Experimental& SetDownloadService(int64_t value);

    static const char kExtensions_ValueStoreName[];
    static constexpr uint64_t kExtensions_ValueStoreNameHash = UINT64_C(29559029929544692);
    Memory_Experimental& SetExtensions_ValueStore(int64_t value);

    static const char kFontCachesName[];
    static constexpr uint64_t kFontCachesNameHash = UINT64_C(16529061004933942300);
    Memory_Experimental& SetFontCaches(int64_t value);

    static const char kGpuMemoryName[];
    static constexpr uint64_t kGpuMemoryNameHash = UINT64_C(490077485390910541);
    Memory_Experimental& SetGpuMemory(int64_t value);

    static const char kHistoryName[];
    static constexpr uint64_t kHistoryNameHash = UINT64_C(1644574205037202324);
    Memory_Experimental& SetHistory(int64_t value);

    static const char kIsVisibleName[];
    static constexpr uint64_t kIsVisibleNameHash = UINT64_C(1485165748725517792);
    Memory_Experimental& SetIsVisible(int64_t value);

    static const char kJavaHeapName[];
    static constexpr uint64_t kJavaHeapNameHash = UINT64_C(8862862044285854091);
    Memory_Experimental& SetJavaHeap(int64_t value);

    static const char kLevelDatabaseName[];
    static constexpr uint64_t kLevelDatabaseNameHash = UINT64_C(11348850218298612975);
    Memory_Experimental& SetLevelDatabase(int64_t value);

    static const char kMallocName[];
    static constexpr uint64_t kMallocNameHash = UINT64_C(1238957276816977011);
    Memory_Experimental& SetMalloc(int64_t value);

    static const char kMalloc_AllocatedObjectsName[];
    static constexpr uint64_t kMalloc_AllocatedObjectsNameHash = UINT64_C(1925721785185208243);
    Memory_Experimental& SetMalloc_AllocatedObjects(int64_t value);

    static const char kNumberOfAdSubframesName[];
    static constexpr uint64_t kNumberOfAdSubframesNameHash = UINT64_C(10743182343548519998);
    Memory_Experimental& SetNumberOfAdSubframes(int64_t value);

    static const char kNumberOfArrayBufferContentsName[];
    static constexpr uint64_t kNumberOfArrayBufferContentsNameHash = UINT64_C(13264497785936960149);
    Memory_Experimental& SetNumberOfArrayBufferContents(int64_t value);

    static const char kNumberOfDetachedScriptStatesName[];
    static constexpr uint64_t kNumberOfDetachedScriptStatesNameHash = UINT64_C(18265098399102889270);
    Memory_Experimental& SetNumberOfDetachedScriptStates(int64_t value);

    static const char kNumberOfDocumentsName[];
    static constexpr uint64_t kNumberOfDocumentsNameHash = UINT64_C(5733109213322944724);
    Memory_Experimental& SetNumberOfDocuments(int64_t value);

    static const char kNumberOfExtensionsName[];
    static constexpr uint64_t kNumberOfExtensionsNameHash = UINT64_C(3403202119543761618);
    Memory_Experimental& SetNumberOfExtensions(int64_t value);

    static const char kNumberOfFramesName[];
    static constexpr uint64_t kNumberOfFramesNameHash = UINT64_C(6940065104966512226);
    Memory_Experimental& SetNumberOfFrames(int64_t value);

    static const char kNumberOfLayoutObjectsName[];
    static constexpr uint64_t kNumberOfLayoutObjectsNameHash = UINT64_C(3649880882460262866);
    Memory_Experimental& SetNumberOfLayoutObjects(int64_t value);

    static const char kNumberOfMojoHandlesName[];
    static constexpr uint64_t kNumberOfMojoHandlesNameHash = UINT64_C(16814172961108727736);
    Memory_Experimental& SetNumberOfMojoHandles(int64_t value);

    static const char kNumberOfNodesName[];
    static constexpr uint64_t kNumberOfNodesNameHash = UINT64_C(15643987746411267564);
    Memory_Experimental& SetNumberOfNodes(int64_t value);

    static const char kNumberOfWebMediaPlayersName[];
    static constexpr uint64_t kNumberOfWebMediaPlayersNameHash = UINT64_C(12804910322462330532);
    Memory_Experimental& SetNumberOfWebMediaPlayers(int64_t value);

    static const char kOmniboxSuggestionsName[];
    static constexpr uint64_t kOmniboxSuggestionsNameHash = UINT64_C(17355891050851009725);
    Memory_Experimental& SetOmniboxSuggestions(int64_t value);

    static const char kPartitionAllocName[];
    static constexpr uint64_t kPartitionAllocNameHash = UINT64_C(9610482673592445024);
    Memory_Experimental& SetPartitionAlloc(int64_t value);

    static const char kPartitionAlloc_AllocatedObjectsName[];
    static constexpr uint64_t kPartitionAlloc_AllocatedObjectsNameHash = UINT64_C(15224183457205092815);
    Memory_Experimental& SetPartitionAlloc_AllocatedObjects(int64_t value);

    static const char kPartitionAlloc_Partitions_ArrayBufferName[];
    static constexpr uint64_t kPartitionAlloc_Partitions_ArrayBufferNameHash = UINT64_C(806433197023658949);
    Memory_Experimental& SetPartitionAlloc_Partitions_ArrayBuffer(int64_t value);

    static const char kPartitionAlloc_Partitions_BufferName[];
    static constexpr uint64_t kPartitionAlloc_Partitions_BufferNameHash = UINT64_C(12341882596033563250);
    Memory_Experimental& SetPartitionAlloc_Partitions_Buffer(int64_t value);

    static const char kPartitionAlloc_Partitions_FastMallocName[];
    static constexpr uint64_t kPartitionAlloc_Partitions_FastMallocNameHash = UINT64_C(13878052578744598290);
    Memory_Experimental& SetPartitionAlloc_Partitions_FastMalloc(int64_t value);

    static const char kPartitionAlloc_Partitions_LayoutName[];
    static constexpr uint64_t kPartitionAlloc_Partitions_LayoutNameHash = UINT64_C(6655809818244318026);
    Memory_Experimental& SetPartitionAlloc_Partitions_Layout(int64_t value);

    static const char kPrivateMemoryFootprintName[];
    static constexpr uint64_t kPrivateMemoryFootprintNameHash = UINT64_C(10052513537419821189);
    Memory_Experimental& SetPrivateMemoryFootprint(int64_t value);

    static const char kPrivateSwapFootprintName[];
    static constexpr uint64_t kPrivateSwapFootprintNameHash = UINT64_C(13571406198520885449);
    Memory_Experimental& SetPrivateSwapFootprint(int64_t value);

    static const char kProcessTypeName[];
    static constexpr uint64_t kProcessTypeNameHash = UINT64_C(7486237172651555104);
    Memory_Experimental& SetProcessType(int64_t value);

    static const char kResidentName[];
    static constexpr uint64_t kResidentNameHash = UINT64_C(13461411595380681438);
    Memory_Experimental& SetResident(int64_t value);

    static const char kSharedMemoryFootprintName[];
    static constexpr uint64_t kSharedMemoryFootprintNameHash = UINT64_C(17500641147677751075);
    Memory_Experimental& SetSharedMemoryFootprint(int64_t value);

    static const char kSiteStorageName[];
    static constexpr uint64_t kSiteStorageNameHash = UINT64_C(9072081726198684739);
    Memory_Experimental& SetSiteStorage(int64_t value);

    static const char kSiteStorage_BlobStorageName[];
    static constexpr uint64_t kSiteStorage_BlobStorageNameHash = UINT64_C(7198093127485286680);
    Memory_Experimental& SetSiteStorage_BlobStorage(int64_t value);

    static const char kSiteStorage_IndexDBName[];
    static constexpr uint64_t kSiteStorage_IndexDBNameHash = UINT64_C(6402762799502043507);
    Memory_Experimental& SetSiteStorage_IndexDB(int64_t value);

    static const char kSiteStorage_LocalStorageName[];
    static constexpr uint64_t kSiteStorage_LocalStorageNameHash = UINT64_C(14933128457130084075);
    Memory_Experimental& SetSiteStorage_LocalStorage(int64_t value);

    static const char kSiteStorage_SessionStorageName[];
    static constexpr uint64_t kSiteStorage_SessionStorageNameHash = UINT64_C(14209441575119482215);
    Memory_Experimental& SetSiteStorage_SessionStorage(int64_t value);

    static const char kSkiaName[];
    static constexpr uint64_t kSkiaNameHash = UINT64_C(9991921243016949116);
    Memory_Experimental& SetSkia(int64_t value);

    static const char kSkia_SkGlyphCacheName[];
    static constexpr uint64_t kSkia_SkGlyphCacheNameHash = UINT64_C(8035476658629055040);
    Memory_Experimental& SetSkia_SkGlyphCache(int64_t value);

    static const char kSkia_SkResourceCacheName[];
    static constexpr uint64_t kSkia_SkResourceCacheNameHash = UINT64_C(6214163245680517898);
    Memory_Experimental& SetSkia_SkResourceCache(int64_t value);

    static const char kSqliteName[];
    static constexpr uint64_t kSqliteNameHash = UINT64_C(2900118879024321274);
    Memory_Experimental& SetSqlite(int64_t value);

    static const char kSyncName[];
    static constexpr uint64_t kSyncNameHash = UINT64_C(15629878885545645682);
    Memory_Experimental& SetSync(int64_t value);

    static const char kTabRestoreName[];
    static constexpr uint64_t kTabRestoreNameHash = UINT64_C(4112632899105915167);
    Memory_Experimental& SetTabRestore(int64_t value);

    static const char kTimeSinceLastNavigationName[];
    static constexpr uint64_t kTimeSinceLastNavigationNameHash = UINT64_C(13938385952041404158);
    Memory_Experimental& SetTimeSinceLastNavigation(int64_t value);

    static const char kTimeSinceLastVisibilityChangeName[];
    static constexpr uint64_t kTimeSinceLastVisibilityChangeNameHash = UINT64_C(6720756525548063269);
    Memory_Experimental& SetTimeSinceLastVisibilityChange(int64_t value);

    static const char kTotal2_PrivateMemoryFootprintName[];
    static constexpr uint64_t kTotal2_PrivateMemoryFootprintNameHash = UINT64_C(3202306657284943476);
    Memory_Experimental& SetTotal2_PrivateMemoryFootprint(int64_t value);

    static const char kTotal2_SharedMemoryFootprintName[];
    static constexpr uint64_t kTotal2_SharedMemoryFootprintNameHash = UINT64_C(12351660231667012712);
    Memory_Experimental& SetTotal2_SharedMemoryFootprint(int64_t value);

    static const char kUIName[];
    static constexpr uint64_t kUINameHash = UINT64_C(8214408844178480006);
    Memory_Experimental& SetUI(int64_t value);

    static const char kUptimeName[];
    static constexpr uint64_t kUptimeNameHash = UINT64_C(15054621371739184368);
    Memory_Experimental& SetUptime(int64_t value);

    static const char kV8Name[];
    static constexpr uint64_t kV8NameHash = UINT64_C(16896410219304879775);
    Memory_Experimental& SetV8(int64_t value);

    static const char kV8_AllocatedObjectsName[];
    static constexpr uint64_t kV8_AllocatedObjectsNameHash = UINT64_C(12768063626211715955);
    Memory_Experimental& SetV8_AllocatedObjects(int64_t value);

    static const char kV8_MainName[];
    static constexpr uint64_t kV8_MainNameHash = UINT64_C(15822769446047631319);
    Memory_Experimental& SetV8_Main(int64_t value);

    static const char kV8_Main_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_AllocatedObjectsNameHash = UINT64_C(6415930962248516020);
    Memory_Experimental& SetV8_Main_AllocatedObjects(int64_t value);

    static const char kV8_Main_GlobalHandlesName[];
    static constexpr uint64_t kV8_Main_GlobalHandlesNameHash = UINT64_C(15581823109972252891);
    Memory_Experimental& SetV8_Main_GlobalHandles(int64_t value);

    static const char kV8_Main_GlobalHandles_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_GlobalHandles_AllocatedObjectsNameHash = UINT64_C(13390524526750856493);
    Memory_Experimental& SetV8_Main_GlobalHandles_AllocatedObjects(int64_t value);

    static const char kV8_Main_HeapName[];
    static constexpr uint64_t kV8_Main_HeapNameHash = UINT64_C(1921939464854386930);
    Memory_Experimental& SetV8_Main_Heap(int64_t value);

    static const char kV8_Main_Heap_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_AllocatedObjectsNameHash = UINT64_C(18399663685000936309);
    Memory_Experimental& SetV8_Main_Heap_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_CodeLargeObjectSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_CodeLargeObjectSpaceNameHash = UINT64_C(16494123902430388069);
    Memory_Experimental& SetV8_Main_Heap_CodeLargeObjectSpace(int64_t value);

    static const char kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(2364189807997549859);
    Memory_Experimental& SetV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_CodeSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_CodeSpaceNameHash = UINT64_C(17931395497534883149);
    Memory_Experimental& SetV8_Main_Heap_CodeSpace(int64_t value);

    static const char kV8_Main_Heap_CodeSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash = UINT64_C(8854776756506961912);
    Memory_Experimental& SetV8_Main_Heap_CodeSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_LargeObjectSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_LargeObjectSpaceNameHash = UINT64_C(11750966123435126059);
    Memory_Experimental& SetV8_Main_Heap_LargeObjectSpace(int64_t value);

    static const char kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(11564384343176289185);
    Memory_Experimental& SetV8_Main_Heap_LargeObjectSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_MapSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_MapSpaceNameHash = UINT64_C(11978611635426298319);
    Memory_Experimental& SetV8_Main_Heap_MapSpace(int64_t value);

    static const char kV8_Main_Heap_MapSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash = UINT64_C(16674407876969307804);
    Memory_Experimental& SetV8_Main_Heap_MapSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_NewLargeObjectSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_NewLargeObjectSpaceNameHash = UINT64_C(834392200182619412);
    Memory_Experimental& SetV8_Main_Heap_NewLargeObjectSpace(int64_t value);

    static const char kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(17778294341716883234);
    Memory_Experimental& SetV8_Main_Heap_NewLargeObjectSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_NewSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_NewSpaceNameHash = UINT64_C(10321246481429414455);
    Memory_Experimental& SetV8_Main_Heap_NewSpace(int64_t value);

    static const char kV8_Main_Heap_NewSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash = UINT64_C(14817743657656407284);
    Memory_Experimental& SetV8_Main_Heap_NewSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_OldSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_OldSpaceNameHash = UINT64_C(11173434268017894307);
    Memory_Experimental& SetV8_Main_Heap_OldSpace(int64_t value);

    static const char kV8_Main_Heap_OldSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash = UINT64_C(15835060948495197507);
    Memory_Experimental& SetV8_Main_Heap_OldSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_ReadOnlySpaceName[];
    static constexpr uint64_t kV8_Main_Heap_ReadOnlySpaceNameHash = UINT64_C(4433186457491512075);
    Memory_Experimental& SetV8_Main_Heap_ReadOnlySpace(int64_t value);

    static const char kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash = UINT64_C(9665716489791848232);
    Memory_Experimental& SetV8_Main_Heap_ReadOnlySpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_SharedLargeObjectSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_SharedLargeObjectSpaceNameHash = UINT64_C(1740930907259984756);
    Memory_Experimental& SetV8_Main_Heap_SharedLargeObjectSpace(int64_t value);

    static const char kV8_Main_Heap_SharedLargeObjectSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_SharedLargeObjectSpace_AllocatedObjectsNameHash = UINT64_C(13671294231352199987);
    Memory_Experimental& SetV8_Main_Heap_SharedLargeObjectSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_Heap_SharedSpaceName[];
    static constexpr uint64_t kV8_Main_Heap_SharedSpaceNameHash = UINT64_C(6885640070331998121);
    Memory_Experimental& SetV8_Main_Heap_SharedSpace(int64_t value);

    static const char kV8_Main_Heap_SharedSpace_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Main_Heap_SharedSpace_AllocatedObjectsNameHash = UINT64_C(3886354987391131732);
    Memory_Experimental& SetV8_Main_Heap_SharedSpace_AllocatedObjects(int64_t value);

    static const char kV8_Main_MallocName[];
    static constexpr uint64_t kV8_Main_MallocNameHash = UINT64_C(5158976984073464014);
    Memory_Experimental& SetV8_Main_Malloc(int64_t value);

    static const char kV8_WorkersName[];
    static constexpr uint64_t kV8_WorkersNameHash = UINT64_C(8553202260117802914);
    Memory_Experimental& SetV8_Workers(int64_t value);

    static const char kV8_Workers_AllocatedObjectsName[];
    static constexpr uint64_t kV8_Workers_AllocatedObjectsNameHash = UINT64_C(12177354597900444603);
    Memory_Experimental& SetV8_Workers_AllocatedObjects(int64_t value);

    static const char kWebCacheName[];
    static constexpr uint64_t kWebCacheNameHash = UINT64_C(13488018231190606421);
    Memory_Experimental& SetWebCache(int64_t value);

    static const char kWebCache_CSSStylesheetResourcesName[];
    static constexpr uint64_t kWebCache_CSSStylesheetResourcesNameHash = UINT64_C(9097814082721146272);
    Memory_Experimental& SetWebCache_CSSStylesheetResources(int64_t value);

    static const char kWebCache_EncodedSizeDuplicatedInDataUrlsName[];
    static constexpr uint64_t kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash = UINT64_C(14143651647860570899);
    Memory_Experimental& SetWebCache_EncodedSizeDuplicatedInDataUrls(int64_t value);

    static const char kWebCache_FontResourcesName[];
    static constexpr uint64_t kWebCache_FontResourcesNameHash = UINT64_C(9628146792345614317);
    Memory_Experimental& SetWebCache_FontResources(int64_t value);

    static const char kWebCache_ImageResourcesName[];
    static constexpr uint64_t kWebCache_ImageResourcesNameHash = UINT64_C(9515010466852810683);
    Memory_Experimental& SetWebCache_ImageResources(int64_t value);

    static const char kWebCache_OtherResourcesName[];
    static constexpr uint64_t kWebCache_OtherResourcesNameHash = UINT64_C(17732136591162526580);
    Memory_Experimental& SetWebCache_OtherResources(int64_t value);

    static const char kWebCache_ScriptResourcesName[];
    static constexpr uint64_t kWebCache_ScriptResourcesNameHash = UINT64_C(3925250771305782664);
    Memory_Experimental& SetWebCache_ScriptResources(int64_t value);

    static const char kWebCache_V8CodeCacheName[];
    static constexpr uint64_t kWebCache_V8CodeCacheNameHash = UINT64_C(12782736109709927035);
    Memory_Experimental& SetWebCache_V8CodeCache(int64_t value);

    static const char kWebCache_XSLStylesheetResourcesName[];
    static constexpr uint64_t kWebCache_XSLStylesheetResourcesNameHash = UINT64_C(12721691713197854566);
    Memory_Experimental& SetWebCache_XSLStylesheetResources(int64_t value);

    static const char kWebMediaPlayer_AudioName[];
    static constexpr uint64_t kWebMediaPlayer_AudioNameHash = UINT64_C(9811078190138863992);
    Memory_Experimental& SetWebMediaPlayer_Audio(int64_t value);

    static const char kWebMediaPlayer_DataSourceName[];
    static constexpr uint64_t kWebMediaPlayer_DataSourceNameHash = UINT64_C(7384723713952795180);
    Memory_Experimental& SetWebMediaPlayer_DataSource(int64_t value);

    static const char kWebMediaPlayer_DemuxerName[];
    static constexpr uint64_t kWebMediaPlayer_DemuxerNameHash = UINT64_C(15908638698549151493);
    Memory_Experimental& SetWebMediaPlayer_Demuxer(int64_t value);

    static const char kWebMediaPlayer_VideoName[];
    static constexpr uint64_t kWebMediaPlayer_VideoNameHash = UINT64_C(16129684864004564062);
    Memory_Experimental& SetWebMediaPlayer_Video(int64_t value);
};

class Memory_TabFootprint final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Memory_TabFootprint(ukm::SourceId source_id);
    explicit Memory_TabFootprint(ukm::SourceIdObj source_id);
    Memory_TabFootprint(Memory_TabFootprint&&);
    Memory_TabFootprint& operator=(Memory_TabFootprint&&);
    ~Memory_TabFootprint() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12430751894188593646);

    static const char kMainFrameProcessPMFName[];
    static constexpr uint64_t kMainFrameProcessPMFNameHash = UINT64_C(12781944348586693197);
    Memory_TabFootprint& SetMainFrameProcessPMF(int64_t value);

    static const char kSubFrameProcessPMF_ExcludedName[];
    static constexpr uint64_t kSubFrameProcessPMF_ExcludedNameHash = UINT64_C(4544803109589615267);
    Memory_TabFootprint& SetSubFrameProcessPMF_Excluded(int64_t value);

    static const char kSubFrameProcessPMF_IncludedName[];
    static constexpr uint64_t kSubFrameProcessPMF_IncludedNameHash = UINT64_C(10498004541020155793);
    Memory_TabFootprint& SetSubFrameProcessPMF_Included(int64_t value);

    static const char kSubFrameProcessPMF_TotalName[];
    static constexpr uint64_t kSubFrameProcessPMF_TotalNameHash = UINT64_C(11258618895083361601);
    Memory_TabFootprint& SetSubFrameProcessPMF_Total(int64_t value);

    static const char kTabPMFName[];
    static constexpr uint64_t kTabPMFNameHash = UINT64_C(5878461021664314052);
    Memory_TabFootprint& SetTabPMF(int64_t value);
};

class MixedContentAutoupgrade_ResourceRequest final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MixedContentAutoupgrade_ResourceRequest(ukm::SourceId source_id);
    explicit MixedContentAutoupgrade_ResourceRequest(ukm::SourceIdObj source_id);
    MixedContentAutoupgrade_ResourceRequest(MixedContentAutoupgrade_ResourceRequest&&);
    MixedContentAutoupgrade_ResourceRequest& operator=(MixedContentAutoupgrade_ResourceRequest&&);
    ~MixedContentAutoupgrade_ResourceRequest() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9946364510678884885);

    static const char kCodeName[];
    static constexpr uint64_t kCodeNameHash = UINT64_C(14559498612242860847);
    MixedContentAutoupgrade_ResourceRequest& SetCode(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    MixedContentAutoupgrade_ResourceRequest& SetStatus(int64_t value);
};

class MobileFriendliness final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MobileFriendliness(ukm::SourceId source_id);
    explicit MobileFriendliness(ukm::SourceIdObj source_id);
    MobileFriendliness(MobileFriendliness&&);
    MobileFriendliness& operator=(MobileFriendliness&&);
    ~MobileFriendliness() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2031262019788538998);

    static const char kAllowUserZoomName[];
    static constexpr uint64_t kAllowUserZoomNameHash = UINT64_C(14142747645707151019);
    MobileFriendliness& SetAllowUserZoom(int64_t value);

    static const char kSmallTextRatioName[];
    static constexpr uint64_t kSmallTextRatioNameHash = UINT64_C(5694740463845988499);
    MobileFriendliness& SetSmallTextRatio(int64_t value);

    static const char kTextContentOutsideViewportPercentageName[];
    static constexpr uint64_t kTextContentOutsideViewportPercentageNameHash = UINT64_C(13371890962709993581);
    MobileFriendliness& SetTextContentOutsideViewportPercentage(int64_t value);

    static const char kViewportDeviceWidthName[];
    static constexpr uint64_t kViewportDeviceWidthNameHash = UINT64_C(17436768906408925903);
    MobileFriendliness& SetViewportDeviceWidth(int64_t value);

    static const char kViewportHardcodedWidthName[];
    static constexpr uint64_t kViewportHardcodedWidthNameHash = UINT64_C(8491227714119818609);
    MobileFriendliness& SetViewportHardcodedWidth(int64_t value);

    static const char kViewportInitialScaleX10Name[];
    static constexpr uint64_t kViewportInitialScaleX10NameHash = UINT64_C(10344173199195698133);
    MobileFriendliness& SetViewportInitialScaleX10(int64_t value);
};

class MobileFriendliness_TappedBadTargets final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MobileFriendliness_TappedBadTargets(ukm::SourceId source_id);
    explicit MobileFriendliness_TappedBadTargets(ukm::SourceIdObj source_id);
    MobileFriendliness_TappedBadTargets(MobileFriendliness_TappedBadTargets&&);
    MobileFriendliness_TappedBadTargets& operator=(MobileFriendliness_TappedBadTargets&&);
    ~MobileFriendliness_TappedBadTargets() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4279746797929370611);

    static const char kCloseDisplayEdgeName[];
    static constexpr uint64_t kCloseDisplayEdgeNameHash = UINT64_C(17885044001109830637);
    MobileFriendliness_TappedBadTargets& SetCloseDisplayEdge(int64_t value);

    static const char kHighlyZoomedName[];
    static constexpr uint64_t kHighlyZoomedNameHash = UINT64_C(1833299880911875860);
    MobileFriendliness_TappedBadTargets& SetHighlyZoomed(int64_t value);

    static const char kTooCloseName[];
    static constexpr uint64_t kTooCloseNameHash = UINT64_C(17034511113963570176);
    MobileFriendliness_TappedBadTargets& SetTooClose(int64_t value);

    static const char kTooSmallName[];
    static constexpr uint64_t kTooSmallNameHash = UINT64_C(17602367443321653865);
    MobileFriendliness_TappedBadTargets& SetTooSmall(int64_t value);

    static const char kZoomedName[];
    static constexpr uint64_t kZoomedNameHash = UINT64_C(317755546890301875);
    MobileFriendliness_TappedBadTargets& SetZoomed(int64_t value);
};

class MobileMenu_DirectShare final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MobileMenu_DirectShare(ukm::SourceId source_id);
    explicit MobileMenu_DirectShare(ukm::SourceIdObj source_id);
    MobileMenu_DirectShare(MobileMenu_DirectShare&&);
    MobileMenu_DirectShare& operator=(MobileMenu_DirectShare&&);
    ~MobileMenu_DirectShare() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10323656781780570903);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    MobileMenu_DirectShare& SetHasOccurred(int64_t value);
};

class MobileMenu_FindInPage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MobileMenu_FindInPage(ukm::SourceId source_id);
    explicit MobileMenu_FindInPage(ukm::SourceIdObj source_id);
    MobileMenu_FindInPage(MobileMenu_FindInPage&&);
    MobileMenu_FindInPage& operator=(MobileMenu_FindInPage&&);
    ~MobileMenu_FindInPage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(317096594738729330);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    MobileMenu_FindInPage& SetHasOccurred(int64_t value);
};

class MobileMenu_Share final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit MobileMenu_Share(ukm::SourceId source_id);
    explicit MobileMenu_Share(ukm::SourceIdObj source_id);
    MobileMenu_Share(MobileMenu_Share&&);
    MobileMenu_Share& operator=(MobileMenu_Share&&);
    ~MobileMenu_Share() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16632756802456473210);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    MobileMenu_Share& SetHasOccurred(int64_t value);
};

class Navigation_IDNA2008Transition final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Navigation_IDNA2008Transition(ukm::SourceId source_id);
    explicit Navigation_IDNA2008Transition(ukm::SourceIdObj source_id);
    Navigation_IDNA2008Transition(Navigation_IDNA2008Transition&&);
    Navigation_IDNA2008Transition& operator=(Navigation_IDNA2008Transition&&);
    ~Navigation_IDNA2008Transition() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12118541746267936631);

    static const char kCharacterName[];
    static constexpr uint64_t kCharacterNameHash = UINT64_C(8548973727659841685);
    Navigation_IDNA2008Transition& SetCharacter(int64_t value);
};

class Navigation_ReceivedResponse final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Navigation_ReceivedResponse(ukm::SourceId source_id);
    explicit Navigation_ReceivedResponse(ukm::SourceIdObj source_id);
    Navigation_ReceivedResponse(Navigation_ReceivedResponse&&);
    Navigation_ReceivedResponse& operator=(Navigation_ReceivedResponse&&);
    ~Navigation_ReceivedResponse() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8202605063367714792);

    static const char kHasAcceptCHFrameName[];
    static constexpr uint64_t kHasAcceptCHFrameNameHash = UINT64_C(10031943393999527048);
    Navigation_ReceivedResponse& SetHasAcceptCHFrame(int64_t value);

    static const char kNavigationFirstResponseLatencyName[];
    static constexpr uint64_t kNavigationFirstResponseLatencyNameHash = UINT64_C(17054650368377244315);
    Navigation_ReceivedResponse& SetNavigationFirstResponseLatency(int64_t value);
};

class NavigationPredictorAnchorElementMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationPredictorAnchorElementMetrics(ukm::SourceId source_id);
    explicit NavigationPredictorAnchorElementMetrics(ukm::SourceIdObj source_id);
    NavigationPredictorAnchorElementMetrics(NavigationPredictorAnchorElementMetrics&&);
    NavigationPredictorAnchorElementMetrics& operator=(NavigationPredictorAnchorElementMetrics&&);
    ~NavigationPredictorAnchorElementMetrics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4064735116116070675);

    static const char kAnchorIndexName[];
    static constexpr uint64_t kAnchorIndexNameHash = UINT64_C(9397884037038305849);
    NavigationPredictorAnchorElementMetrics& SetAnchorIndex(int64_t value);

    static const char kBucketedPathHashName[];
    static constexpr uint64_t kBucketedPathHashNameHash = UINT64_C(8736781991002893450);
    NavigationPredictorAnchorElementMetrics& SetBucketedPathHash(int64_t value);

    static const char kContainsImageName[];
    static constexpr uint64_t kContainsImageNameHash = UINT64_C(16441638965853255360);
    NavigationPredictorAnchorElementMetrics& SetContainsImage(int64_t value);

    static const char kFontSizeName[];
    static constexpr uint64_t kFontSizeNameHash = UINT64_C(2643658496925572245);
    NavigationPredictorAnchorElementMetrics& SetFontSize(int64_t value);

    static const char kHasTextSiblingName[];
    static constexpr uint64_t kHasTextSiblingNameHash = UINT64_C(5766907595008553355);
    NavigationPredictorAnchorElementMetrics& SetHasTextSibling(int64_t value);

    static const char kIsBoldName[];
    static constexpr uint64_t kIsBoldNameHash = UINT64_C(4144648385448633082);
    NavigationPredictorAnchorElementMetrics& SetIsBold(int64_t value);

    static const char kIsInIframeName[];
    static constexpr uint64_t kIsInIframeNameHash = UINT64_C(2879927029285282397);
    NavigationPredictorAnchorElementMetrics& SetIsInIframe(int64_t value);

    static const char kIsURLIncrementedByOneName[];
    static constexpr uint64_t kIsURLIncrementedByOneNameHash = UINT64_C(3472078046519927012);
    NavigationPredictorAnchorElementMetrics& SetIsURLIncrementedByOne(int64_t value);

    static const char kNavigationStartToLinkLoggedMsName[];
    static constexpr uint64_t kNavigationStartToLinkLoggedMsNameHash = UINT64_C(2339728805912802951);
    NavigationPredictorAnchorElementMetrics& SetNavigationStartToLinkLoggedMs(int64_t value);

    static const char kPathDepthName[];
    static constexpr uint64_t kPathDepthNameHash = UINT64_C(5175545670794720336);
    NavigationPredictorAnchorElementMetrics& SetPathDepth(int64_t value);

    static const char kPathLengthName[];
    static constexpr uint64_t kPathLengthNameHash = UINT64_C(1889323937569217530);
    NavigationPredictorAnchorElementMetrics& SetPathLength(int64_t value);

    static const char kPercentClickableAreaName[];
    static constexpr uint64_t kPercentClickableAreaNameHash = UINT64_C(12162500925069527559);
    NavigationPredictorAnchorElementMetrics& SetPercentClickableArea(int64_t value);

    static const char kPercentVerticalDistanceName[];
    static constexpr uint64_t kPercentVerticalDistanceNameHash = UINT64_C(14979657413195163456);
    NavigationPredictorAnchorElementMetrics& SetPercentVerticalDistance(int64_t value);

    static const char kSameOriginName[];
    static constexpr uint64_t kSameOriginNameHash = UINT64_C(3198866256218607801);
    NavigationPredictorAnchorElementMetrics& SetSameOrigin(int64_t value);
};

class NavigationPredictorPageLinkClick final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationPredictorPageLinkClick(ukm::SourceId source_id);
    explicit NavigationPredictorPageLinkClick(ukm::SourceIdObj source_id);
    NavigationPredictorPageLinkClick(NavigationPredictorPageLinkClick&&);
    NavigationPredictorPageLinkClick& operator=(NavigationPredictorPageLinkClick&&);
    ~NavigationPredictorPageLinkClick() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10775915644707889889);

    static const char kAnchorElementIndexName[];
    static constexpr uint64_t kAnchorElementIndexNameHash = UINT64_C(10478607568863071276);
    NavigationPredictorPageLinkClick& SetAnchorElementIndex(int64_t value);

    static const char kHrefUnchangedName[];
    static constexpr uint64_t kHrefUnchangedNameHash = UINT64_C(3501437891647978003);
    NavigationPredictorPageLinkClick& SetHrefUnchanged(int64_t value);

    static const char kNavigationStartToLinkClickedMsName[];
    static constexpr uint64_t kNavigationStartToLinkClickedMsNameHash = UINT64_C(15205400953056588601);
    NavigationPredictorPageLinkClick& SetNavigationStartToLinkClickedMs(int64_t value);
};

class NavigationPredictorPageLinkMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationPredictorPageLinkMetrics(ukm::SourceId source_id);
    explicit NavigationPredictorPageLinkMetrics(ukm::SourceIdObj source_id);
    NavigationPredictorPageLinkMetrics(NavigationPredictorPageLinkMetrics&&);
    NavigationPredictorPageLinkMetrics& operator=(NavigationPredictorPageLinkMetrics&&);
    ~NavigationPredictorPageLinkMetrics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(367468233168747720);

    static const char kMedianLinkLocationName[];
    static constexpr uint64_t kMedianLinkLocationNameHash = UINT64_C(10492116656714417766);
    NavigationPredictorPageLinkMetrics& SetMedianLinkLocation(int64_t value);

    static const char kNumberOfAnchors_ContainsImageName[];
    static constexpr uint64_t kNumberOfAnchors_ContainsImageNameHash = UINT64_C(924687343626407188);
    NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_ContainsImage(int64_t value);

    static const char kNumberOfAnchors_InIframeName[];
    static constexpr uint64_t kNumberOfAnchors_InIframeNameHash = UINT64_C(6586263068289067744);
    NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_InIframe(int64_t value);

    static const char kNumberOfAnchors_SameHostName[];
    static constexpr uint64_t kNumberOfAnchors_SameHostNameHash = UINT64_C(6024206236807188452);
    NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_SameHost(int64_t value);

    static const char kNumberOfAnchors_TotalName[];
    static constexpr uint64_t kNumberOfAnchors_TotalNameHash = UINT64_C(2837656844888606476);
    NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_Total(int64_t value);

    static const char kNumberOfAnchors_URLIncrementedName[];
    static constexpr uint64_t kNumberOfAnchors_URLIncrementedNameHash = UINT64_C(4900312954566928460);
    NavigationPredictorPageLinkMetrics& SetNumberOfAnchors_URLIncremented(int64_t value);

    static const char kTotalClickableSpaceName[];
    static constexpr uint64_t kTotalClickableSpaceNameHash = UINT64_C(1923089912871098586);
    NavigationPredictorPageLinkMetrics& SetTotalClickableSpace(int64_t value);

    static const char kViewport_HeightName[];
    static constexpr uint64_t kViewport_HeightNameHash = UINT64_C(6402799756853104710);
    NavigationPredictorPageLinkMetrics& SetViewport_Height(int64_t value);

    static const char kViewport_WidthName[];
    static constexpr uint64_t kViewport_WidthNameHash = UINT64_C(2201646688798995121);
    NavigationPredictorPageLinkMetrics& SetViewport_Width(int64_t value);
};

class NavigationPredictorPreloadOnHover final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationPredictorPreloadOnHover(ukm::SourceId source_id);
    explicit NavigationPredictorPreloadOnHover(ukm::SourceIdObj source_id);
    NavigationPredictorPreloadOnHover(NavigationPredictorPreloadOnHover&&);
    NavigationPredictorPreloadOnHover& operator=(NavigationPredictorPreloadOnHover&&);
    ~NavigationPredictorPreloadOnHover() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4551066950181678222);

    static const char kHoverNotTakenMsName[];
    static constexpr uint64_t kHoverNotTakenMsNameHash = UINT64_C(4467330484610198575);
    NavigationPredictorPreloadOnHover& SetHoverNotTakenMs(int64_t value);

    static const char kHoverTakenMsName[];
    static constexpr uint64_t kHoverTakenMsNameHash = UINT64_C(16099467146121946442);
    NavigationPredictorPreloadOnHover& SetHoverTakenMs(int64_t value);

    static const char kMouseDownNotTakenMsName[];
    static constexpr uint64_t kMouseDownNotTakenMsNameHash = UINT64_C(6954320149648044415);
    NavigationPredictorPreloadOnHover& SetMouseDownNotTakenMs(int64_t value);

    static const char kMouseDownTakenMsName[];
    static constexpr uint64_t kMouseDownTakenMsNameHash = UINT64_C(51503021162748510);
    NavigationPredictorPreloadOnHover& SetMouseDownTakenMs(int64_t value);
};

class NavigationPredictorUserInteractions final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationPredictorUserInteractions(ukm::SourceId source_id);
    explicit NavigationPredictorUserInteractions(ukm::SourceIdObj source_id);
    NavigationPredictorUserInteractions(NavigationPredictorUserInteractions&&);
    NavigationPredictorUserInteractions& operator=(NavigationPredictorUserInteractions&&);
    ~NavigationPredictorUserInteractions() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5906381251666152842);

    static const char kAnchorIndexName[];
    static constexpr uint64_t kAnchorIndexNameHash = UINT64_C(9397884037038305849);
    NavigationPredictorUserInteractions& SetAnchorIndex(int64_t value);

    static const char kDistanceFromLastPointerDownName[];
    static constexpr uint64_t kDistanceFromLastPointerDownNameHash = UINT64_C(5015126581737728686);
    NavigationPredictorUserInteractions& SetDistanceFromLastPointerDown(int64_t value);

    static const char kEnteredViewportCountName[];
    static constexpr uint64_t kEnteredViewportCountNameHash = UINT64_C(18038712548234018622);
    NavigationPredictorUserInteractions& SetEnteredViewportCount(int64_t value);

    static const char kIsInViewportName[];
    static constexpr uint64_t kIsInViewportNameHash = UINT64_C(16594779979937947357);
    NavigationPredictorUserInteractions& SetIsInViewport(int64_t value);

    static const char kIsPointerHoveringOverName[];
    static constexpr uint64_t kIsPointerHoveringOverNameHash = UINT64_C(12774123402145154879);
    NavigationPredictorUserInteractions& SetIsPointerHoveringOver(int64_t value);

    static const char kMaxEnteredViewportToLeftViewportMsName[];
    static constexpr uint64_t kMaxEnteredViewportToLeftViewportMsNameHash = UINT64_C(8879544349101451530);
    NavigationPredictorUserInteractions& SetMaxEnteredViewportToLeftViewportMs(int64_t value);

    static const char kMaxHoverDwellTimeMsName[];
    static constexpr uint64_t kMaxHoverDwellTimeMsNameHash = UINT64_C(10686675378144372882);
    NavigationPredictorUserInteractions& SetMaxHoverDwellTimeMs(int64_t value);

    static const char kMouseAccelerationName[];
    static constexpr uint64_t kMouseAccelerationNameHash = UINT64_C(3923882579949594268);
    NavigationPredictorUserInteractions& SetMouseAcceleration(int64_t value);

    static const char kMouseVelocityName[];
    static constexpr uint64_t kMouseVelocityNameHash = UINT64_C(3433651536389463341);
    NavigationPredictorUserInteractions& SetMouseVelocity(int64_t value);

    static const char kPointerHoveringOverCountName[];
    static constexpr uint64_t kPointerHoveringOverCountNameHash = UINT64_C(5127996080152514538);
    NavigationPredictorUserInteractions& SetPointerHoveringOverCount(int64_t value);

    static const char kVerticalPositionInViewportName[];
    static constexpr uint64_t kVerticalPositionInViewportNameHash = UINT64_C(794264002235900738);
    NavigationPredictorUserInteractions& SetVerticalPositionInViewport(int64_t value);
};

class NavigationRequestBreakDown final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationRequestBreakDown(ukm::SourceId source_id);
    explicit NavigationRequestBreakDown(ukm::SourceIdObj source_id);
    NavigationRequestBreakDown(NavigationRequestBreakDown&&);
    NavigationRequestBreakDown& operator=(NavigationRequestBreakDown&&);
    ~NavigationRequestBreakDown() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6971828606222010244);

    static const char kBeginNavigationToLoaderStartName[];
    static constexpr uint64_t kBeginNavigationToLoaderStartNameHash = UINT64_C(1926723670368144695);
    NavigationRequestBreakDown& SetBeginNavigationToLoaderStart(int64_t value);

    static const char kLoaderStartToReceiveResponseName[];
    static constexpr uint64_t kLoaderStartToReceiveResponseNameHash = UINT64_C(5634293758211589185);
    NavigationRequestBreakDown& SetLoaderStartToReceiveResponse(int64_t value);

    static const char kNavigationStartToBeginNavigationName[];
    static constexpr uint64_t kNavigationStartToBeginNavigationNameHash = UINT64_C(5101769305723288617);
    NavigationRequestBreakDown& SetNavigationStartToBeginNavigation(int64_t value);

    static const char kReceiveResponseToCommitNavigationName[];
    static constexpr uint64_t kReceiveResponseToCommitNavigationNameHash = UINT64_C(12751734137397386089);
    NavigationRequestBreakDown& SetReceiveResponseToCommitNavigation(int64_t value);
};

class NavigationThrottleDeferredTime final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationThrottleDeferredTime(ukm::SourceId source_id);
    explicit NavigationThrottleDeferredTime(ukm::SourceIdObj source_id);
    NavigationThrottleDeferredTime(NavigationThrottleDeferredTime&&);
    NavigationThrottleDeferredTime& operator=(NavigationThrottleDeferredTime&&);
    ~NavigationThrottleDeferredTime() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11162965141345650317);

    static const char kDurationOfNavigationDeferralMsName[];
    static constexpr uint64_t kDurationOfNavigationDeferralMsNameHash = UINT64_C(8472542121801588163);
    NavigationThrottleDeferredTime& SetDurationOfNavigationDeferralMs(int64_t value);

    static const char kNavigationThrottleEventTypeName[];
    static constexpr uint64_t kNavigationThrottleEventTypeNameHash = UINT64_C(806649975832979388);
    NavigationThrottleDeferredTime& SetNavigationThrottleEventType(int64_t value);

    static const char kNavigationThrottleNameHashName[];
    static constexpr uint64_t kNavigationThrottleNameHashNameHash = UINT64_C(8729976295683680445);
    NavigationThrottleDeferredTime& SetNavigationThrottleNameHash(int64_t value);
};

class NavigationTiming final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NavigationTiming(ukm::SourceId source_id);
    explicit NavigationTiming(ukm::SourceIdObj source_id);
    NavigationTiming(NavigationTiming&&);
    NavigationTiming& operator=(NavigationTiming&&);
    ~NavigationTiming() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10253825785463205218);

    static const char kFinalLoaderCallbackName[];
    static constexpr uint64_t kFinalLoaderCallbackNameHash = UINT64_C(6374469588262495910);
    NavigationTiming& SetFinalLoaderCallback(int64_t value);

    static const char kFinalRequestStartName[];
    static constexpr uint64_t kFinalRequestStartNameHash = UINT64_C(11815399945354094146);
    NavigationTiming& SetFinalRequestStart(int64_t value);

    static const char kFinalResponseStartName[];
    static constexpr uint64_t kFinalResponseStartNameHash = UINT64_C(13915347411436087346);
    NavigationTiming& SetFinalResponseStart(int64_t value);

    static const char kFirstLoaderCallbackName[];
    static constexpr uint64_t kFirstLoaderCallbackNameHash = UINT64_C(15619811325143937572);
    NavigationTiming& SetFirstLoaderCallback(int64_t value);

    static const char kFirstRequestStartName[];
    static constexpr uint64_t kFirstRequestStartNameHash = UINT64_C(8607578836164150031);
    NavigationTiming& SetFirstRequestStart(int64_t value);

    static const char kFirstResponseStartName[];
    static constexpr uint64_t kFirstResponseStartNameHash = UINT64_C(12921608487894943184);
    NavigationTiming& SetFirstResponseStart(int64_t value);

    static const char kNavigationCommitSentName[];
    static constexpr uint64_t kNavigationCommitSentNameHash = UINT64_C(10755993212023138369);
    NavigationTiming& SetNavigationCommitSent(int64_t value);
};

class Network_DataUrls final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Network_DataUrls(ukm::SourceId source_id);
    explicit Network_DataUrls(ukm::SourceIdObj source_id);
    Network_DataUrls(Network_DataUrls&&);
    Network_DataUrls& operator=(Network_DataUrls&&);
    ~Network_DataUrls() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11843839735896046781);

    static const char kIsImageName[];
    static constexpr uint64_t kIsImageNameHash = UINT64_C(16164377299151918220);
    Network_DataUrls& SetIsImage(int64_t value);

    static const char kParseTimeName[];
    static constexpr uint64_t kParseTimeNameHash = UINT64_C(17015910212546350243);
    Network_DataUrls& SetParseTime(int64_t value);

    static const char kUrlLengthName[];
    static constexpr uint64_t kUrlLengthNameHash = UINT64_C(13802339684989893578);
    Network_DataUrls& SetUrlLength(int64_t value);
};

class NewTabPage_HistoryClusters final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NewTabPage_HistoryClusters(ukm::SourceId source_id);
    explicit NewTabPage_HistoryClusters(ukm::SourceIdObj source_id);
    NewTabPage_HistoryClusters(NewTabPage_HistoryClusters&&);
    NewTabPage_HistoryClusters& operator=(NewTabPage_HistoryClusters&&);
    ~NewTabPage_HistoryClusters() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(559094208615510931);

    static const char kBelongsToBoostedCategoryName[];
    static constexpr uint64_t kBelongsToBoostedCategoryNameHash = UINT64_C(6874253816197336447);
    NewTabPage_HistoryClusters& SetBelongsToBoostedCategory(int64_t value);

    static const char kBelongsToMostSeenCategoryName[];
    static constexpr uint64_t kBelongsToMostSeenCategoryNameHash = UINT64_C(15531857510265195394);
    NewTabPage_HistoryClusters& SetBelongsToMostSeenCategory(int64_t value);

    static const char kBelongsToMostUsedCategoryName[];
    static constexpr uint64_t kBelongsToMostUsedCategoryNameHash = UINT64_C(14714135004412625994);
    NewTabPage_HistoryClusters& SetBelongsToMostUsedCategory(int64_t value);

    static const char kDidDisableModuleName[];
    static constexpr uint64_t kDidDisableModuleNameHash = UINT64_C(15403329243198520632);
    NewTabPage_HistoryClusters& SetDidDisableModule(int64_t value);

    static const char kDidDismissModuleName[];
    static constexpr uint64_t kDidDismissModuleNameHash = UINT64_C(2595248557294338145);
    NewTabPage_HistoryClusters& SetDidDismissModule(int64_t value);

    static const char kDidEngageWithModuleName[];
    static constexpr uint64_t kDidEngageWithModuleNameHash = UINT64_C(706303784194036913);
    NewTabPage_HistoryClusters& SetDidEngageWithModule(int64_t value);

    static const char kDidMarkAsDoneName[];
    static constexpr uint64_t kDidMarkAsDoneNameHash = UINT64_C(6179140868304393454);
    NewTabPage_HistoryClusters& SetDidMarkAsDone(int64_t value);

    static const char kLayoutTypeShownName[];
    static constexpr uint64_t kLayoutTypeShownNameHash = UINT64_C(11086775481426639863);
    NewTabPage_HistoryClusters& SetLayoutTypeShown(int64_t value);

    static const char kMinutesSinceMostRecentVisitName[];
    static constexpr uint64_t kMinutesSinceMostRecentVisitNameHash = UINT64_C(5470557138815706688);
    NewTabPage_HistoryClusters& SetMinutesSinceMostRecentVisit(int64_t value);

    static const char kMostFrequentSeenCategoryCountName[];
    static constexpr uint64_t kMostFrequentSeenCategoryCountNameHash = UINT64_C(7074471831935571788);
    NewTabPage_HistoryClusters& SetMostFrequentSeenCategoryCount(int64_t value);

    static const char kMostFrequentUsedCategoryCountName[];
    static constexpr uint64_t kMostFrequentUsedCategoryCountNameHash = UINT64_C(394832121280293663);
    NewTabPage_HistoryClusters& SetMostFrequentUsedCategoryCount(int64_t value);

    static const char kNumAbandonedCartsName[];
    static constexpr uint64_t kNumAbandonedCartsNameHash = UINT64_C(9479945921710286606);
    NewTabPage_HistoryClusters& SetNumAbandonedCarts(int64_t value);

    static const char kNumAssociatedCategoriesName[];
    static constexpr uint64_t kNumAssociatedCategoriesNameHash = UINT64_C(11556687425927079138);
    NewTabPage_HistoryClusters& SetNumAssociatedCategories(int64_t value);

    static const char kNumTimesSeenLast24hName[];
    static constexpr uint64_t kNumTimesSeenLast24hNameHash = UINT64_C(8736705493520202236);
    NewTabPage_HistoryClusters& SetNumTimesSeenLast24h(int64_t value);

    static const char kNumTimesUsedLast24hName[];
    static constexpr uint64_t kNumTimesUsedLast24hNameHash = UINT64_C(3315522120224304794);
    NewTabPage_HistoryClusters& SetNumTimesUsedLast24h(int64_t value);

    static const char kNumTotalVisitsName[];
    static constexpr uint64_t kNumTotalVisitsNameHash = UINT64_C(14700845548935967128);
    NewTabPage_HistoryClusters& SetNumTotalVisits(int64_t value);

    static const char kNumUniqueHostsName[];
    static constexpr uint64_t kNumUniqueHostsNameHash = UINT64_C(5932491654448461837);
    NewTabPage_HistoryClusters& SetNumUniqueHosts(int64_t value);

    static const char kNumVisitsWithImageName[];
    static constexpr uint64_t kNumVisitsWithImageNameHash = UINT64_C(18222984287860040690);
    NewTabPage_HistoryClusters& SetNumVisitsWithImage(int64_t value);
};

class NoStatePrefetch final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit NoStatePrefetch(ukm::SourceId source_id);
    explicit NoStatePrefetch(ukm::SourceIdObj source_id);
    NoStatePrefetch(NoStatePrefetch&&);
    NoStatePrefetch& operator=(NoStatePrefetch&&);
    ~NoStatePrefetch() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5007192410804132260);

    static const char kPrefetchedRecently_FinalStatusName[];
    static constexpr uint64_t kPrefetchedRecently_FinalStatusNameHash = UINT64_C(9796471847649268750);
    NoStatePrefetch& SetPrefetchedRecently_FinalStatus(int64_t value);

    static const char kPrefetchedRecently_OriginName[];
    static constexpr uint64_t kPrefetchedRecently_OriginNameHash = UINT64_C(2530841639179133763);
    NoStatePrefetch& SetPrefetchedRecently_Origin(int64_t value);

    static const char kPrefetchedRecently_PrefetchAgeName[];
    static constexpr uint64_t kPrefetchedRecently_PrefetchAgeNameHash = UINT64_C(10422971425397899407);
    NoStatePrefetch& SetPrefetchedRecently_PrefetchAge(int64_t value);
};

class Notification final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Notification(ukm::SourceId source_id);
    explicit Notification(ukm::SourceIdObj source_id);
    Notification(Notification&&);
    Notification& operator=(Notification&&);
    ~Notification() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10867195639280438101);

    static const char kClosedReasonName[];
    static constexpr uint64_t kClosedReasonNameHash = UINT64_C(17020731291041401384);
    Notification& SetClosedReason(int64_t value);

    static const char kDidReplaceAnotherNotificationName[];
    static constexpr uint64_t kDidReplaceAnotherNotificationNameHash = UINT64_C(14697312060434823404);
    Notification& SetDidReplaceAnotherNotification(int64_t value);

    static const char kDidUserOpenSettingsName[];
    static constexpr uint64_t kDidUserOpenSettingsNameHash = UINT64_C(12457694958612229736);
    Notification& SetDidUserOpenSettings(int64_t value);

    static const char kHasBadgeName[];
    static constexpr uint64_t kHasBadgeNameHash = UINT64_C(1404314928722833713);
    Notification& SetHasBadge(int64_t value);

    static const char kHasIconName[];
    static constexpr uint64_t kHasIconNameHash = UINT64_C(4132654540182426756);
    Notification& SetHasIcon(int64_t value);

    static const char kHasImageName[];
    static constexpr uint64_t kHasImageNameHash = UINT64_C(15666573512201018736);
    Notification& SetHasImage(int64_t value);

    static const char kHasRenotifyName[];
    static constexpr uint64_t kHasRenotifyNameHash = UINT64_C(1255778828920234902);
    Notification& SetHasRenotify(int64_t value);

    static const char kHasTagName[];
    static constexpr uint64_t kHasTagNameHash = UINT64_C(10403421344797099586);
    Notification& SetHasTag(int64_t value);

    static const char kIsSilentName[];
    static constexpr uint64_t kIsSilentNameHash = UINT64_C(12611294049427120665);
    Notification& SetIsSilent(int64_t value);

    static const char kNumActionButtonClicksName[];
    static constexpr uint64_t kNumActionButtonClicksNameHash = UINT64_C(15400118752953521622);
    Notification& SetNumActionButtonClicks(int64_t value);

    static const char kNumActionsName[];
    static constexpr uint64_t kNumActionsNameHash = UINT64_C(1524089126526666739);
    Notification& SetNumActions(int64_t value);

    static const char kNumClicksName[];
    static constexpr uint64_t kNumClicksNameHash = UINT64_C(7685741146111146271);
    Notification& SetNumClicks(int64_t value);

    static const char kRequireInteractionName[];
    static constexpr uint64_t kRequireInteractionNameHash = UINT64_C(1417488390737291945);
    Notification& SetRequireInteraction(int64_t value);

    static const char kTimeUntilCloseName[];
    static constexpr uint64_t kTimeUntilCloseNameHash = UINT64_C(11999907426896258327);
    Notification& SetTimeUntilClose(int64_t value);

    static const char kTimeUntilFirstClickName[];
    static constexpr uint64_t kTimeUntilFirstClickNameHash = UINT64_C(5643047780569843127);
    Notification& SetTimeUntilFirstClick(int64_t value);

    static const char kTimeUntilLastClickName[];
    static constexpr uint64_t kTimeUntilLastClickNameHash = UINT64_C(11175801317414480864);
    Notification& SetTimeUntilLastClick(int64_t value);
};

class Omnibox_EditUrlSuggestion_Share final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Omnibox_EditUrlSuggestion_Share(ukm::SourceId source_id);
    explicit Omnibox_EditUrlSuggestion_Share(ukm::SourceIdObj source_id);
    Omnibox_EditUrlSuggestion_Share(Omnibox_EditUrlSuggestion_Share&&);
    Omnibox_EditUrlSuggestion_Share& operator=(Omnibox_EditUrlSuggestion_Share&&);
    ~Omnibox_EditUrlSuggestion_Share() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4133441977341793352);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    Omnibox_EditUrlSuggestion_Share& SetHasOccurred(int64_t value);
};

class Omnibox_SuggestionUsed final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Omnibox_SuggestionUsed(ukm::SourceId source_id);
    explicit Omnibox_SuggestionUsed(ukm::SourceIdObj source_id);
    Omnibox_SuggestionUsed(Omnibox_SuggestionUsed&&);
    Omnibox_SuggestionUsed& operator=(Omnibox_SuggestionUsed&&);
    ~Omnibox_SuggestionUsed() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(410068635758492342);

    static const char kResultTypeName[];
    static constexpr uint64_t kResultTypeNameHash = UINT64_C(8293845286137751377);
    Omnibox_SuggestionUsed& SetResultType(int64_t value);
};

class OmniboxSecurityIndicator_FormSubmission final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit OmniboxSecurityIndicator_FormSubmission(ukm::SourceId source_id);
    explicit OmniboxSecurityIndicator_FormSubmission(ukm::SourceIdObj source_id);
    OmniboxSecurityIndicator_FormSubmission(OmniboxSecurityIndicator_FormSubmission&&);
    OmniboxSecurityIndicator_FormSubmission& operator=(OmniboxSecurityIndicator_FormSubmission&&);
    ~OmniboxSecurityIndicator_FormSubmission() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2638435285752584045);

    static const char kSubmittedName[];
    static constexpr uint64_t kSubmittedNameHash = UINT64_C(6666273175654835609);
    OmniboxSecurityIndicator_FormSubmission& SetSubmitted(int64_t value);
};

class OpenerHeuristic_PopupInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit OpenerHeuristic_PopupInteraction(ukm::SourceId source_id);
    explicit OpenerHeuristic_PopupInteraction(ukm::SourceIdObj source_id);
    OpenerHeuristic_PopupInteraction(OpenerHeuristic_PopupInteraction&&);
    OpenerHeuristic_PopupInteraction& operator=(OpenerHeuristic_PopupInteraction&&);
    ~OpenerHeuristic_PopupInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9673748521109117539);

    static const char kOpenerHasSameSiteIframeName[];
    static constexpr uint64_t kOpenerHasSameSiteIframeNameHash = UINT64_C(15547075772128086806);
    OpenerHeuristic_PopupInteraction& SetOpenerHasSameSiteIframe(int64_t value);

    static const char kPopupIdName[];
    static constexpr uint64_t kPopupIdNameHash = UINT64_C(14441431756324727858);
    OpenerHeuristic_PopupInteraction& SetPopupId(int64_t value);

    static const char kSecondsSinceCommittedName[];
    static constexpr uint64_t kSecondsSinceCommittedNameHash = UINT64_C(7823593695701407031);
    OpenerHeuristic_PopupInteraction& SetSecondsSinceCommitted(int64_t value);

    static const char kUrlIndexName[];
    static constexpr uint64_t kUrlIndexNameHash = UINT64_C(11933910024925757754);
    OpenerHeuristic_PopupInteraction& SetUrlIndex(int64_t value);
};

class OpenerHeuristic_PopupPastInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit OpenerHeuristic_PopupPastInteraction(ukm::SourceId source_id);
    explicit OpenerHeuristic_PopupPastInteraction(ukm::SourceIdObj source_id);
    OpenerHeuristic_PopupPastInteraction(OpenerHeuristic_PopupPastInteraction&&);
    OpenerHeuristic_PopupPastInteraction& operator=(OpenerHeuristic_PopupPastInteraction&&);
    ~OpenerHeuristic_PopupPastInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(284944213972750594);

    static const char kHoursSinceLastInteractionName[];
    static constexpr uint64_t kHoursSinceLastInteractionNameHash = UINT64_C(4087224455125447084);
    OpenerHeuristic_PopupPastInteraction& SetHoursSinceLastInteraction(int64_t value);

    static const char kOpenerHasSameSiteIframeName[];
    static constexpr uint64_t kOpenerHasSameSiteIframeNameHash = UINT64_C(15547075772128086806);
    OpenerHeuristic_PopupPastInteraction& SetOpenerHasSameSiteIframe(int64_t value);

    static const char kPopupIdName[];
    static constexpr uint64_t kPopupIdNameHash = UINT64_C(14441431756324727858);
    OpenerHeuristic_PopupPastInteraction& SetPopupId(int64_t value);
};

class OpenerHeuristic_PostPopupCookieAccess final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit OpenerHeuristic_PostPopupCookieAccess(ukm::SourceId source_id);
    explicit OpenerHeuristic_PostPopupCookieAccess(ukm::SourceIdObj source_id);
    OpenerHeuristic_PostPopupCookieAccess(OpenerHeuristic_PostPopupCookieAccess&&);
    OpenerHeuristic_PostPopupCookieAccess& operator=(OpenerHeuristic_PostPopupCookieAccess&&);
    ~OpenerHeuristic_PostPopupCookieAccess() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3100647281250124680);

    static const char kAccessIdName[];
    static constexpr uint64_t kAccessIdNameHash = UINT64_C(11155306466381838703);
    OpenerHeuristic_PostPopupCookieAccess& SetAccessId(int64_t value);

    static const char kAccessSucceededName[];
    static constexpr uint64_t kAccessSucceededNameHash = UINT64_C(2230435749847591433);
    OpenerHeuristic_PostPopupCookieAccess& SetAccessSucceeded(int64_t value);

    static const char kHoursSincePopupOpenedName[];
    static constexpr uint64_t kHoursSincePopupOpenedNameHash = UINT64_C(1315229812705844087);
    OpenerHeuristic_PostPopupCookieAccess& SetHoursSincePopupOpened(int64_t value);

    static const char kIsAdTaggedName[];
    static constexpr uint64_t kIsAdTaggedNameHash = UINT64_C(17196529301178612283);
    OpenerHeuristic_PostPopupCookieAccess& SetIsAdTagged(int64_t value);
};

class OpenerHeuristic_TopLevel final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit OpenerHeuristic_TopLevel(ukm::SourceId source_id);
    explicit OpenerHeuristic_TopLevel(ukm::SourceIdObj source_id);
    OpenerHeuristic_TopLevel(OpenerHeuristic_TopLevel&&);
    OpenerHeuristic_TopLevel& operator=(OpenerHeuristic_TopLevel&&);
    ~OpenerHeuristic_TopLevel() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7387506176392750000);

    static const char kAccessIdName[];
    static constexpr uint64_t kAccessIdNameHash = UINT64_C(11155306466381838703);
    OpenerHeuristic_TopLevel& SetAccessId(int64_t value);

    static const char kHasSameSiteIframeName[];
    static constexpr uint64_t kHasSameSiteIframeNameHash = UINT64_C(12121249819210153261);
    OpenerHeuristic_TopLevel& SetHasSameSiteIframe(int64_t value);

    static const char kIsAdTaggedPopupClickName[];
    static constexpr uint64_t kIsAdTaggedPopupClickNameHash = UINT64_C(11587559602844211076);
    OpenerHeuristic_TopLevel& SetIsAdTaggedPopupClick(int64_t value);

    static const char kPopupIdName[];
    static constexpr uint64_t kPopupIdNameHash = UINT64_C(14441431756324727858);
    OpenerHeuristic_TopLevel& SetPopupId(int64_t value);

    static const char kPopupProviderName[];
    static constexpr uint64_t kPopupProviderNameHash = UINT64_C(4159300800153172830);
    OpenerHeuristic_TopLevel& SetPopupProvider(int64_t value);
};

class OptimizationGuide final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit OptimizationGuide(ukm::SourceId source_id);
    explicit OptimizationGuide(ukm::SourceIdObj source_id);
    OptimizationGuide(OptimizationGuide&&);
    OptimizationGuide& operator=(OptimizationGuide&&);
    ~OptimizationGuide() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2087579403365801585);

    static const char kNavigationHintsFetchAttemptStatusName[];
    static constexpr uint64_t kNavigationHintsFetchAttemptStatusNameHash = UINT64_C(1464000691203191735);
    OptimizationGuide& SetNavigationHintsFetchAttemptStatus(int64_t value);

    static const char kNavigationHintsFetchRequestLatencyName[];
    static constexpr uint64_t kNavigationHintsFetchRequestLatencyNameHash = UINT64_C(6533440160746002973);
    OptimizationGuide& SetNavigationHintsFetchRequestLatency(int64_t value);

    static const char kRegisteredOptimizationTargetsName[];
    static constexpr uint64_t kRegisteredOptimizationTargetsNameHash = UINT64_C(16583518481415531705);
    OptimizationGuide& SetRegisteredOptimizationTargets(int64_t value);

    static const char kRegisteredOptimizationTypesName[];
    static constexpr uint64_t kRegisteredOptimizationTypesNameHash = UINT64_C(16255593039456486105);
    OptimizationGuide& SetRegisteredOptimizationTypes(int64_t value);
};

class PageContentAnnotations2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageContentAnnotations2(ukm::SourceId source_id);
    explicit PageContentAnnotations2(ukm::SourceIdObj source_id);
    PageContentAnnotations2(PageContentAnnotations2&&);
    PageContentAnnotations2& operator=(PageContentAnnotations2&&);
    ~PageContentAnnotations2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3675683766249774286);

    static const char kVisibilityScoreName[];
    static constexpr uint64_t kVisibilityScoreNameHash = UINT64_C(16472091843743240030);
    PageContentAnnotations2& SetVisibilityScore(int64_t value);
};

class PageDomainInfo final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageDomainInfo(ukm::SourceId source_id);
    explicit PageDomainInfo(ukm::SourceIdObj source_id);
    PageDomainInfo(PageDomainInfo&&);
    PageDomainInfo& operator=(PageDomainInfo&&);
    ~PageDomainInfo() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12853622770478513093);

    static const char kDomainTypeName[];
    static constexpr uint64_t kDomainTypeNameHash = UINT64_C(7797620970950375408);
    PageDomainInfo& SetDomainType(int64_t value);
};

class PageForegroundSession final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageForegroundSession(ukm::SourceId source_id);
    explicit PageForegroundSession(ukm::SourceIdObj source_id);
    PageForegroundSession(PageForegroundSession&&);
    PageForegroundSession& operator=(PageForegroundSession&&);
    ~PageForegroundSession() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14423022965050986312);

    static const char kForegroundDurationName[];
    static constexpr uint64_t kForegroundDurationNameHash = UINT64_C(14040493619853098912);
    PageForegroundSession& SetForegroundDuration(int64_t value);

    static const char kForegroundTotalInputDelayName[];
    static constexpr uint64_t kForegroundTotalInputDelayNameHash = UINT64_C(8008711279838603073);
    PageForegroundSession& SetForegroundTotalInputDelay(int64_t value);
};

class PageInfoBubble final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageInfoBubble(ukm::SourceId source_id);
    explicit PageInfoBubble(ukm::SourceIdObj source_id);
    PageInfoBubble(PageInfoBubble&&);
    PageInfoBubble& operator=(PageInfoBubble&&);
    ~PageInfoBubble() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10171644723325805171);

    static const char kActionTakenName[];
    static constexpr uint64_t kActionTakenNameHash = UINT64_C(9500803244906435515);
    PageInfoBubble& SetActionTaken(int64_t value);
};

class PageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoad(ukm::SourceId source_id);
    explicit PageLoad(ukm::SourceIdObj source_id);
    PageLoad(PageLoad&&);
    PageLoad& operator=(PageLoad&&);
    ~PageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12426032810838168341);

    static const char kCpuTimeName[];
    static constexpr uint64_t kCpuTimeNameHash = UINT64_C(6353397511912813717);
    PageLoad& SetCpuTime(int64_t value);

    static const char kDayOfWeekName[];
    static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
    PageLoad& SetDayOfWeek(int64_t value);

    static const char kDocumentTiming_NavigationToDOMContentLoadedEventFiredName[];
    static constexpr uint64_t kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash = UINT64_C(6867802542830008226);
    PageLoad& SetDocumentTiming_NavigationToDOMContentLoadedEventFired(int64_t value);

    static const char kDocumentTiming_NavigationToLoadEventFiredName[];
    static constexpr uint64_t kDocumentTiming_NavigationToLoadEventFiredNameHash = UINT64_C(9492260367886123818);
    PageLoad& SetDocumentTiming_NavigationToLoadEventFired(int64_t value);

    static const char kDurationSinceLastVisitSecondsName[];
    static constexpr uint64_t kDurationSinceLastVisitSecondsNameHash = UINT64_C(14064867420815770005);
    PageLoad& SetDurationSinceLastVisitSeconds(int64_t value);

    static const char kExperimental_InputToNavigationStartName[];
    static constexpr uint64_t kExperimental_InputToNavigationStartNameHash = UINT64_C(16463295207942209746);
    PageLoad& SetExperimental_InputToNavigationStart(int64_t value);

    static const char kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenName[];
    static constexpr uint64_t kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenNameHash = UINT64_C(17227246285396615476);
    PageLoad& SetExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHidden(int64_t value);

    static const char kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msNameHash
        = UINT64_C(5677035669787318240);
    PageLoad& SetExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kExperimental_Navigation_UserInitiatedName[];
    static constexpr uint64_t kExperimental_Navigation_UserInitiatedNameHash = UINT64_C(16650208715214610274);
    PageLoad& SetExperimental_Navigation_UserInitiated(int64_t value);

    static const char kExperimental_TotalForegroundDurationName[];
    static constexpr uint64_t kExperimental_TotalForegroundDurationNameHash = UINT64_C(3470931647240642399);
    PageLoad& SetExperimental_TotalForegroundDuration(int64_t value);

    static const char kHourOfDayName[];
    static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
    PageLoad& SetHourOfDay(int64_t value);

    static const char kInteractiveTiming_FirstInputDelay4Name[];
    static constexpr uint64_t kInteractiveTiming_FirstInputDelay4NameHash = UINT64_C(6127468907094730300);
    PageLoad& SetInteractiveTiming_FirstInputDelay4(int64_t value);

    static const char kInteractiveTiming_FirstInputTimestamp4Name[];
    static constexpr uint64_t kInteractiveTiming_FirstInputTimestamp4NameHash = UINT64_C(16268762437310799839);
    PageLoad& SetInteractiveTiming_FirstInputTimestamp4(int64_t value);

    static const char kInteractiveTiming_FirstScrollDelayName[];
    static constexpr uint64_t kInteractiveTiming_FirstScrollDelayNameHash = UINT64_C(12767345461070005318);
    PageLoad& SetInteractiveTiming_FirstScrollDelay(int64_t value);

    static const char kInteractiveTiming_FirstScrollTimestampName[];
    static constexpr uint64_t kInteractiveTiming_FirstScrollTimestampNameHash = UINT64_C(9092590817606449334);
    PageLoad& SetInteractiveTiming_FirstScrollTimestamp(int64_t value);

    static const char kInteractiveTiming_INPOffsetName[];
    static constexpr uint64_t kInteractiveTiming_INPOffsetNameHash = UINT64_C(8979497468537936367);
    PageLoad& SetInteractiveTiming_INPOffset(int64_t value);

    static const char kInteractiveTiming_INPTimeName[];
    static constexpr uint64_t kInteractiveTiming_INPTimeNameHash = UINT64_C(7682789371897203313);
    PageLoad& SetInteractiveTiming_INPTime(int64_t value);

    static const char kInteractiveTiming_NumInteractionsName[];
    static constexpr uint64_t kInteractiveTiming_NumInteractionsNameHash = UINT64_C(11809849059952828483);
    PageLoad& SetInteractiveTiming_NumInteractions(int64_t value);

    static const char kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash = UINT64_C(10840313540306654437);
    PageLoad& SetInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationNameHash = UINT64_C(3129284972298807287);
    PageLoad& SetInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash = UINT64_C(3538217577346865260);
    PageLoad& SetInteractiveTiming_WorstUserInteractionLatency_MaxEventDuration(int64_t value);

    static const char kInteractiveTimingBeforeSoftNavigation_INPOffsetName[];
    static constexpr uint64_t kInteractiveTimingBeforeSoftNavigation_INPOffsetNameHash = UINT64_C(5149361121909269848);
    PageLoad& SetInteractiveTimingBeforeSoftNavigation_INPOffset(int64_t value);

    static const char kInteractiveTimingBeforeSoftNavigation_INPTimeName[];
    static constexpr uint64_t kInteractiveTimingBeforeSoftNavigation_INPTimeNameHash = UINT64_C(2553427409660474511);
    PageLoad& SetInteractiveTimingBeforeSoftNavigation_INPTime(int64_t value);

    static const char kInteractiveTimingBeforeSoftNavigation_NumInteractionsName[];
    static constexpr uint64_t kInteractiveTimingBeforeSoftNavigation_NumInteractionsNameHash = UINT64_C(5049829433862574480);
    PageLoad& SetInteractiveTimingBeforeSoftNavigation_NumInteractions(int64_t value);

    static const char kInteractiveTimingBeforeSoftNavigation_UserInteractionLatency_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTimingBeforeSoftNavigation_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash
        = UINT64_C(8043517162080863199);
    PageLoad& SetInteractiveTimingBeforeSoftNavigation_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kIsCrossProcessNavigationName[];
    static constexpr uint64_t kIsCrossProcessNavigationNameHash = UINT64_C(14766000458248570201);
    PageLoad& SetIsCrossProcessNavigation(int64_t value);

    static const char kIsExistingBookmarkName[];
    static constexpr uint64_t kIsExistingBookmarkNameHash = UINT64_C(3849262661369815215);
    PageLoad& SetIsExistingBookmark(int64_t value);

    static const char kIsExistingPartOfTabGroupName[];
    static constexpr uint64_t kIsExistingPartOfTabGroupNameHash = UINT64_C(6457812980021662913);
    PageLoad& SetIsExistingPartOfTabGroup(int64_t value);

    static const char kIsNewBookmarkName[];
    static constexpr uint64_t kIsNewBookmarkNameHash = UINT64_C(1135618230855533423);
    PageLoad& SetIsNewBookmark(int64_t value);

    static const char kIsNTPCustomLinkName[];
    static constexpr uint64_t kIsNTPCustomLinkNameHash = UINT64_C(8353494371537711160);
    PageLoad& SetIsNTPCustomLink(int64_t value);

    static const char kIsPlacedInTabGroupName[];
    static constexpr uint64_t kIsPlacedInTabGroupNameHash = UINT64_C(6426447933177595047);
    PageLoad& SetIsPlacedInTabGroup(int64_t value);

    static const char kIsScopedSearchLikeNavigationName[];
    static constexpr uint64_t kIsScopedSearchLikeNavigationNameHash = UINT64_C(17317631151278180503);
    PageLoad& SetIsScopedSearchLikeNavigation(int64_t value);

    static const char kLayoutInstability_CumulativeShiftScoreName[];
    static constexpr uint64_t kLayoutInstability_CumulativeShiftScoreNameHash = UINT64_C(6355895514150060407);
    PageLoad& SetLayoutInstability_CumulativeShiftScore(int64_t value);

    static const char kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName[];
    static constexpr uint64_t kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash = UINT64_C(4412907526533667174);
    PageLoad& SetLayoutInstability_CumulativeShiftScore_BeforeInputOrScroll(int64_t value);

    static const char kLayoutInstability_CumulativeShiftScore_MainFrameName[];
    static constexpr uint64_t kLayoutInstability_CumulativeShiftScore_MainFrameNameHash = UINT64_C(11706444123851508509);
    PageLoad& SetLayoutInstability_CumulativeShiftScore_MainFrame(int64_t value);

    static const char kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName[];
    static constexpr uint64_t kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash = UINT64_C(15733786266747591446);
    PageLoad& SetLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScroll(int64_t value);

    static const char kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash = UINT64_C(10830469890257014133);
    PageLoad& SetLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kLayoutInstabilityBeforeSoftNavigation_MaxCumulativeShiftScore_MainFrame_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kLayoutInstabilityBeforeSoftNavigation_MaxCumulativeShiftScore_MainFrame_SessionWindow_Gap1000ms_Max5000msNameHash
        = UINT64_C(3221216456221971879);
    PageLoad& SetLayoutInstabilityBeforeSoftNavigation_MaxCumulativeShiftScore_MainFrame_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kMainDocumentSequenceNumberName[];
    static constexpr uint64_t kMainDocumentSequenceNumberNameHash = UINT64_C(5968137368190340881);
    PageLoad& SetMainDocumentSequenceNumber(int64_t value);

    static const char kMainFrameResource_ConnectDelayName[];
    static constexpr uint64_t kMainFrameResource_ConnectDelayNameHash = UINT64_C(4568735770730238095);
    PageLoad& SetMainFrameResource_ConnectDelay(int64_t value);

    static const char kMainFrameResource_DNSDelayName[];
    static constexpr uint64_t kMainFrameResource_DNSDelayNameHash = UINT64_C(7307227729996236826);
    PageLoad& SetMainFrameResource_DNSDelay(int64_t value);

    static const char kMainFrameResource_HttpProtocolSchemeName[];
    static constexpr uint64_t kMainFrameResource_HttpProtocolSchemeNameHash = UINT64_C(3007836930622015766);
    PageLoad& SetMainFrameResource_HttpProtocolScheme(int64_t value);

    static const char kMainFrameResource_NavigationStartToConnectStartName[];
    static constexpr uint64_t kMainFrameResource_NavigationStartToConnectStartNameHash = UINT64_C(756382771665598106);
    PageLoad& SetMainFrameResource_NavigationStartToConnectStart(int64_t value);

    static const char kMainFrameResource_NavigationStartToReceiveHeadersStartName[];
    static constexpr uint64_t kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash = UINT64_C(1663480531586966499);
    PageLoad& SetMainFrameResource_NavigationStartToReceiveHeadersStart(int64_t value);

    static const char kMainFrameResource_NavigationStartToRequestStartName[];
    static constexpr uint64_t kMainFrameResource_NavigationStartToRequestStartNameHash = UINT64_C(2378326484600041608);
    PageLoad& SetMainFrameResource_NavigationStartToRequestStart(int64_t value);

    static const char kMainFrameResource_RedirectCountName[];
    static constexpr uint64_t kMainFrameResource_RedirectCountNameHash = UINT64_C(12945767909598519836);
    PageLoad& SetMainFrameResource_RedirectCount(int64_t value);

    static const char kMainFrameResource_RequestHadCookiesName[];
    static constexpr uint64_t kMainFrameResource_RequestHadCookiesNameHash = UINT64_C(8178313979867835427);
    PageLoad& SetMainFrameResource_RequestHadCookies(int64_t value);

    static const char kMainFrameResource_RequestHasNoStoreName[];
    static constexpr uint64_t kMainFrameResource_RequestHasNoStoreNameHash = UINT64_C(11828995768390638002);
    PageLoad& SetMainFrameResource_RequestHasNoStore(int64_t value);

    static const char kMainFrameResource_RequestStartToReceiveHeadersEndName[];
    static constexpr uint64_t kMainFrameResource_RequestStartToReceiveHeadersEndNameHash = UINT64_C(15735870039030289373);
    PageLoad& SetMainFrameResource_RequestStartToReceiveHeadersEnd(int64_t value);

    static const char kMainFrameResource_RequestStartToSendStartName[];
    static constexpr uint64_t kMainFrameResource_RequestStartToSendStartNameHash = UINT64_C(13976230857219088742);
    PageLoad& SetMainFrameResource_RequestStartToSendStart(int64_t value);

    static const char kMainFrameResource_SendStartToReceiveHeadersEndName[];
    static constexpr uint64_t kMainFrameResource_SendStartToReceiveHeadersEndNameHash = UINT64_C(14929342406575835437);
    PageLoad& SetMainFrameResource_SendStartToReceiveHeadersEnd(int64_t value);

    static const char kMainFrameResource_SocketReusedName[];
    static constexpr uint64_t kMainFrameResource_SocketReusedNameHash = UINT64_C(6515553691927856961);
    PageLoad& SetMainFrameResource_SocketReused(int64_t value);

    static const char kNavigation_InitiatorLocationName[];
    static constexpr uint64_t kNavigation_InitiatorLocationNameHash = UINT64_C(347990406346941426);
    PageLoad& SetNavigation_InitiatorLocation(int64_t value);

    static const char kNavigation_PageEndReason3Name[];
    static constexpr uint64_t kNavigation_PageEndReason3NameHash = UINT64_C(7884760301518296515);
    PageLoad& SetNavigation_PageEndReason3(int64_t value);

    static const char kNavigation_PageTransitionName[];
    static constexpr uint64_t kNavigation_PageTransitionNameHash = UINT64_C(6618380684727568744);
    PageLoad& SetNavigation_PageTransition(int64_t value);

    static const char kNavigationEntryOffsetName[];
    static constexpr uint64_t kNavigationEntryOffsetNameHash = UINT64_C(17340864924359066998);
    PageLoad& SetNavigationEntryOffset(int64_t value);

    static const char kNet_CacheBytes2Name[];
    static constexpr uint64_t kNet_CacheBytes2NameHash = UINT64_C(6646370524195624485);
    PageLoad& SetNet_CacheBytes2(int64_t value);

    static const char kNet_DownstreamKbpsEstimate_OnNavigationStartName[];
    static constexpr uint64_t kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash = UINT64_C(9428473883870683459);
    PageLoad& SetNet_DownstreamKbpsEstimate_OnNavigationStart(int64_t value);

    static const char kNet_EffectiveConnectionType2_OnNavigationStartName[];
    static constexpr uint64_t kNet_EffectiveConnectionType2_OnNavigationStartNameHash = UINT64_C(12505429480755299532);
    PageLoad& SetNet_EffectiveConnectionType2_OnNavigationStart(int64_t value);

    static const char kNet_ErrorCode_OnFailedProvisionalLoadName[];
    static constexpr uint64_t kNet_ErrorCode_OnFailedProvisionalLoadNameHash = UINT64_C(10394413376607560477);
    PageLoad& SetNet_ErrorCode_OnFailedProvisionalLoad(int64_t value);

    static const char kNet_HttpResponseCodeName[];
    static constexpr uint64_t kNet_HttpResponseCodeNameHash = UINT64_C(578349876587866241);
    PageLoad& SetNet_HttpResponseCode(int64_t value);

    static const char kNet_HttpRttEstimate_OnNavigationStartName[];
    static constexpr uint64_t kNet_HttpRttEstimate_OnNavigationStartNameHash = UINT64_C(5774646068519167414);
    PageLoad& SetNet_HttpRttEstimate_OnNavigationStart(int64_t value);

    static const char kNet_ImageBytes2Name[];
    static constexpr uint64_t kNet_ImageBytes2NameHash = UINT64_C(16036014599725664379);
    PageLoad& SetNet_ImageBytes2(int64_t value);

    static const char kNet_ImageSubframeBytes2Name[];
    static constexpr uint64_t kNet_ImageSubframeBytes2NameHash = UINT64_C(12597674206587437991);
    PageLoad& SetNet_ImageSubframeBytes2(int64_t value);

    static const char kNet_JavaScriptBytes2Name[];
    static constexpr uint64_t kNet_JavaScriptBytes2NameHash = UINT64_C(1286347957863757121);
    PageLoad& SetNet_JavaScriptBytes2(int64_t value);

    static const char kNet_JavaScriptMaxBytes2Name[];
    static constexpr uint64_t kNet_JavaScriptMaxBytes2NameHash = UINT64_C(7693330834615914887);
    PageLoad& SetNet_JavaScriptMaxBytes2(int64_t value);

    static const char kNet_MediaBytes2Name[];
    static constexpr uint64_t kNet_MediaBytes2NameHash = UINT64_C(1229295507334011582);
    PageLoad& SetNet_MediaBytes2(int64_t value);

    static const char kNet_NetworkBytes2Name[];
    static constexpr uint64_t kNet_NetworkBytes2NameHash = UINT64_C(17997790111755306706);
    PageLoad& SetNet_NetworkBytes2(int64_t value);

    static const char kNet_TransportRttEstimate_OnNavigationStartName[];
    static constexpr uint64_t kNet_TransportRttEstimate_OnNavigationStartNameHash = UINT64_C(1015883933811308473);
    PageLoad& SetNet_TransportRttEstimate_OnNavigationStart(int64_t value);

    static const char kOmniboxUrlCopiedName[];
    static constexpr uint64_t kOmniboxUrlCopiedNameHash = UINT64_C(10250056271381019089);
    PageLoad& SetOmniboxUrlCopied(int64_t value);

    static const char kPageTiming_ForegroundDurationName[];
    static constexpr uint64_t kPageTiming_ForegroundDurationNameHash = UINT64_C(2843257204381097865);
    PageLoad& SetPageTiming_ForegroundDuration(int64_t value);

    static const char kPageTiming_NavigationToFailedProvisionalLoadName[];
    static constexpr uint64_t kPageTiming_NavigationToFailedProvisionalLoadNameHash = UINT64_C(11986312636689853254);
    PageLoad& SetPageTiming_NavigationToFailedProvisionalLoad(int64_t value);

    static const char kPageTiming_TotalForegroundDurationName[];
    static constexpr uint64_t kPageTiming_TotalForegroundDurationNameHash = UINT64_C(15554098919276647786);
    PageLoad& SetPageTiming_TotalForegroundDuration(int64_t value);

    static const char kPageTiming_UserTimingMarkFullyLoadedName[];
    static constexpr uint64_t kPageTiming_UserTimingMarkFullyLoadedNameHash = UINT64_C(13826989195056411144);
    PageLoad& SetPageTiming_UserTimingMarkFullyLoaded(int64_t value);

    static const char kPageTiming_UserTimingMarkFullyVisibleName[];
    static constexpr uint64_t kPageTiming_UserTimingMarkFullyVisibleNameHash = UINT64_C(242363805495563163);
    PageLoad& SetPageTiming_UserTimingMarkFullyVisible(int64_t value);

    static const char kPageTiming_UserTimingMarkInteractiveName[];
    static constexpr uint64_t kPageTiming_UserTimingMarkInteractiveNameHash = UINT64_C(4567670599554371322);
    PageLoad& SetPageTiming_UserTimingMarkInteractive(int64_t value);

    static const char kPageVisitFinalStatusName[];
    static constexpr uint64_t kPageVisitFinalStatusNameHash = UINT64_C(15568769830052939365);
    PageLoad& SetPageVisitFinalStatus(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintBPPName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintBPPNameHash = UINT64_C(6973221327096189893);
    PageLoad& SetPaintTiming_LargestContentfulPaintBPP(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageDiscoveryTimeName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageDiscoveryTimeNameHash = UINT64_C(6951457103621142193);
    PageLoad& SetPaintTiming_LargestContentfulPaintImageDiscoveryTime(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageIsCrossOriginName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageIsCrossOriginNameHash = UINT64_C(14728818268751628005);
    PageLoad& SetPaintTiming_LargestContentfulPaintImageIsCrossOrigin(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageLoadEndName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageLoadEndNameHash = UINT64_C(12897333331469387965);
    PageLoad& SetPaintTiming_LargestContentfulPaintImageLoadEnd(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageLoadStartName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageLoadStartNameHash = UINT64_C(10768298899277068506);
    PageLoad& SetPaintTiming_LargestContentfulPaintImageLoadStart(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintRequestPriorityName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintRequestPriorityNameHash = UINT64_C(17986969397849841);
    PageLoad& SetPaintTiming_LargestContentfulPaintRequestPriority(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintTypeName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintTypeNameHash = UINT64_C(7824526725138222267);
    PageLoad& SetPaintTiming_LargestContentfulPaintType(int64_t value);

    static const char kPaintTiming_NavigationToFirstContentfulPaintName[];
    static constexpr uint64_t kPaintTiming_NavigationToFirstContentfulPaintNameHash = UINT64_C(8518716400092239089);
    PageLoad& SetPaintTiming_NavigationToFirstContentfulPaint(int64_t value);

    static const char kPaintTiming_NavigationToFirstPaintName[];
    static constexpr uint64_t kPaintTiming_NavigationToFirstPaintNameHash = UINT64_C(7259095400115977984);
    PageLoad& SetPaintTiming_NavigationToFirstPaint(int64_t value);

    static const char kPaintTiming_NavigationToLargestContentfulPaint2Name[];
    static constexpr uint64_t kPaintTiming_NavigationToLargestContentfulPaint2NameHash = UINT64_C(11508463360603863015);
    PageLoad& SetPaintTiming_NavigationToLargestContentfulPaint2(int64_t value);

    static const char kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameName[];
    static constexpr uint64_t kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameNameHash = UINT64_C(716874189796791255);
    PageLoad& SetPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrame(int64_t value);

    static const char kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameName[];
    static constexpr uint64_t kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameNameHash = UINT64_C(6221533677409529418);
    PageLoad& SetPaintTiming_NavigationToLargestContentfulPaint2_MainFrame(int64_t value);

    static const char kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenName[];
    static constexpr uint64_t kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenNameHash = UINT64_C(14112768646372960882);
    PageLoad& SetPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHidden(int64_t value);

    static const char kParseTiming_NavigationToParseStartName[];
    static constexpr uint64_t kParseTiming_NavigationToParseStartNameHash = UINT64_C(13847075934787644884);
    PageLoad& SetParseTiming_NavigationToParseStart(int64_t value);

    static const char kRefreshRateThrottledName[];
    static constexpr uint64_t kRefreshRateThrottledNameHash = UINT64_C(1325850711367642539);
    PageLoad& SetRefreshRateThrottled(int64_t value);

    static const char kSiteEngagementScoreName[];
    static constexpr uint64_t kSiteEngagementScoreNameHash = UINT64_C(325008584515519231);
    PageLoad& SetSiteEngagementScore(int64_t value);

    static const char kSiteInstanceRenderProcessAssignmentName[];
    static constexpr uint64_t kSiteInstanceRenderProcessAssignmentNameHash = UINT64_C(12998856227050414235);
    PageLoad& SetSiteInstanceRenderProcessAssignment(int64_t value);

    static const char kSoftNavigationCountName[];
    static constexpr uint64_t kSoftNavigationCountNameHash = UINT64_C(743863494159075225);
    PageLoad& SetSoftNavigationCount(int64_t value);

    static const char kThirdPartyCookieBlockingEnabledForSiteName[];
    static constexpr uint64_t kThirdPartyCookieBlockingEnabledForSiteNameHash = UINT64_C(440600315450942530);
    PageLoad& SetThirdPartyCookieBlockingEnabledForSite(int64_t value);

    static const char kWasCachedName[];
    static constexpr uint64_t kWasCachedNameHash = UINT64_C(8288453355921177151);
    PageLoad& SetWasCached(int64_t value);

    static const char kWasDiscardedName[];
    static constexpr uint64_t kWasDiscardedNameHash = UINT64_C(10626929371275140556);
    PageLoad& SetWasDiscarded(int64_t value);
};

class PageLoad_FromGoogleSearch final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoad_FromGoogleSearch(ukm::SourceId source_id);
    explicit PageLoad_FromGoogleSearch(ukm::SourceIdObj source_id);
    PageLoad_FromGoogleSearch(PageLoad_FromGoogleSearch&&);
    PageLoad_FromGoogleSearch& operator=(PageLoad_FromGoogleSearch&&);
    ~PageLoad_FromGoogleSearch() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8384138607730558665);

    static const char kGoogleSearchModeName[];
    static constexpr uint64_t kGoogleSearchModeNameHash = UINT64_C(5234403380533650229);
    PageLoad_FromGoogleSearch& SetGoogleSearchMode(int64_t value);
};

class PageLoad_Internal final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoad_Internal(ukm::SourceId source_id);
    explicit PageLoad_Internal(ukm::SourceIdObj source_id);
    PageLoad_Internal(PageLoad_Internal&&);
    PageLoad_Internal& operator=(PageLoad_Internal&&);
    ~PageLoad_Internal() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5441732143890651748);

    static const char kPaintTiming_LargestContentfulPaint_ContentTypeName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaint_ContentTypeNameHash = UINT64_C(16724376080307984909);
    PageLoad_Internal& SetPaintTiming_LargestContentfulPaint_ContentType(int64_t value);

    static const char kPaintTiming_LargestContentfulPaint_TerminationStateName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaint_TerminationStateNameHash = UINT64_C(5926365039165737690);
    PageLoad_Internal& SetPaintTiming_LargestContentfulPaint_TerminationState(int64_t value);
};

class PageLoad_PervasivePayloadsEnabled final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoad_PervasivePayloadsEnabled(ukm::SourceId source_id);
    explicit PageLoad_PervasivePayloadsEnabled(ukm::SourceIdObj source_id);
    PageLoad_PervasivePayloadsEnabled(PageLoad_PervasivePayloadsEnabled&&);
    PageLoad_PervasivePayloadsEnabled& operator=(PageLoad_PervasivePayloadsEnabled&&);
    ~PageLoad_PervasivePayloadsEnabled() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11995268860284106764);
};

class PageLoad_ServiceWorkerControlled final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoad_ServiceWorkerControlled(ukm::SourceId source_id);
    explicit PageLoad_ServiceWorkerControlled(ukm::SourceIdObj source_id);
    PageLoad_ServiceWorkerControlled(PageLoad_ServiceWorkerControlled&&);
    PageLoad_ServiceWorkerControlled& operator=(PageLoad_ServiceWorkerControlled&&);
    ~PageLoad_ServiceWorkerControlled() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(18067304287773255026);
};

class PageLoad_SignedExchange final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoad_SignedExchange(ukm::SourceId source_id);
    explicit PageLoad_SignedExchange(ukm::SourceIdObj source_id);
    PageLoad_SignedExchange(PageLoad_SignedExchange&&);
    PageLoad_SignedExchange& operator=(PageLoad_SignedExchange&&);
    ~PageLoad_SignedExchange() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14566014450078110818);

    static const char kServedFromGoogleCacheName[];
    static constexpr uint64_t kServedFromGoogleCacheNameHash = UINT64_C(17732685549292242683);
    PageLoad_SignedExchange& SetServedFromGoogleCache(int64_t value);
};

class PageLoadInitiatorForAdTagging final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageLoadInitiatorForAdTagging(ukm::SourceId source_id);
    explicit PageLoadInitiatorForAdTagging(ukm::SourceIdObj source_id);
    PageLoadInitiatorForAdTagging(PageLoadInitiatorForAdTagging&&);
    PageLoadInitiatorForAdTagging& operator=(PageLoadInitiatorForAdTagging&&);
    ~PageLoadInitiatorForAdTagging() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13210659676462006741);

    static const char kFromAdClickName[];
    static constexpr uint64_t kFromAdClickNameHash = UINT64_C(4382858238818830423);
    PageLoadInitiatorForAdTagging& SetFromAdClick(int64_t value);

    static const char kFromUserName[];
    static constexpr uint64_t kFromUserNameHash = UINT64_C(16441275034352248395);
    PageLoadInitiatorForAdTagging& SetFromUser(int64_t value);
};

class PageWithPassword final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PageWithPassword(ukm::SourceId source_id);
    explicit PageWithPassword(ukm::SourceIdObj source_id);
    PageWithPassword(PageWithPassword&&);
    PageWithPassword& operator=(PageWithPassword&&);
    ~PageWithPassword() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2493630448790526384);

    static const char kFormManagerAvailableName[];
    static constexpr uint64_t kFormManagerAvailableNameHash = UINT64_C(16068659807803166350);
    PageWithPassword& SetFormManagerAvailable(int64_t value);

    static const char kPageLevelUserActionName[];
    static constexpr uint64_t kPageLevelUserActionNameHash = UINT64_C(10977249896159391035);
    PageWithPassword& SetPageLevelUserAction(int64_t value);

    static const char kProvisionalSaveFailureName[];
    static constexpr uint64_t kProvisionalSaveFailureNameHash = UINT64_C(7470710753863609401);
    PageWithPassword& SetProvisionalSaveFailure(int64_t value);

    static const char kUserModifiedPasswordFieldName[];
    static constexpr uint64_t kUserModifiedPasswordFieldNameHash = UINT64_C(2714307025842210332);
    PageWithPassword& SetUserModifiedPasswordField(int64_t value);
};

class PaintPreviewCapture final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PaintPreviewCapture(ukm::SourceId source_id);
    explicit PaintPreviewCapture(ukm::SourceIdObj source_id);
    PaintPreviewCapture(PaintPreviewCapture&&);
    PaintPreviewCapture& operator=(PaintPreviewCapture&&);
    ~PaintPreviewCapture() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1595630084981618121);

    static const char kBlinkCaptureTimeName[];
    static constexpr uint64_t kBlinkCaptureTimeNameHash = UINT64_C(6510140679687069140);
    PaintPreviewCapture& SetBlinkCaptureTime(int64_t value);

    static const char kCompressedOnDiskSizeName[];
    static constexpr uint64_t kCompressedOnDiskSizeNameHash = UINT64_C(12971499806185141047);
    PaintPreviewCapture& SetCompressedOnDiskSize(int64_t value);
};

class PartitionedCookiePresentV2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PartitionedCookiePresentV2(ukm::SourceId source_id);
    explicit PartitionedCookiePresentV2(ukm::SourceIdObj source_id);
    PartitionedCookiePresentV2(PartitionedCookiePresentV2&&);
    PartitionedCookiePresentV2& operator=(PartitionedCookiePresentV2&&);
    ~PartitionedCookiePresentV2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9510248908405193837);

    static const char kPartitionedCookiePresentV2Name[];
    static constexpr uint64_t kPartitionedCookiePresentV2NameHash = UINT64_C(9510248908405193837);
    PartitionedCookiePresentV2& SetPartitionedCookiePresentV2(int64_t value);
};

class PasswordForm final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordForm(ukm::SourceId source_id);
    explicit PasswordForm(ukm::SourceIdObj source_id);
    PasswordForm(PasswordForm&&);
    PasswordForm& operator=(PasswordForm&&);
    ~PasswordForm() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8060270586115376858);

    static const char kClassificationCorrectness_ConfirmationPasswordName[];
    static constexpr uint64_t kClassificationCorrectness_ConfirmationPasswordNameHash = UINT64_C(12938234632031037187);
    PasswordForm& SetClassificationCorrectness_ConfirmationPassword(int64_t value);

    static const char kClassificationCorrectness_CurrentPasswordName[];
    static constexpr uint64_t kClassificationCorrectness_CurrentPasswordNameHash = UINT64_C(1547901570131468059);
    PasswordForm& SetClassificationCorrectness_CurrentPassword(int64_t value);

    static const char kClassificationCorrectness_NewPasswordName[];
    static constexpr uint64_t kClassificationCorrectness_NewPasswordNameHash = UINT64_C(16152937461631209867);
    PasswordForm& SetClassificationCorrectness_NewPassword(int64_t value);

    static const char kClassificationCorrectness_UsernameName[];
    static constexpr uint64_t kClassificationCorrectness_UsernameNameHash = UINT64_C(5908233573536947490);
    PasswordForm& SetClassificationCorrectness_Username(int64_t value);

    static const char kContext_FormSignatureName[];
    static constexpr uint64_t kContext_FormSignatureNameHash = UINT64_C(7963393494324030143);
    PasswordForm& SetContext_FormSignature(int64_t value);

    static const char kDynamicFormChangesName[];
    static constexpr uint64_t kDynamicFormChangesNameHash = UINT64_C(2597861915893901769);
    PasswordForm& SetDynamicFormChanges(int64_t value);

    static const char kFill_FirstFillingResultInRendererName[];
    static constexpr uint64_t kFill_FirstFillingResultInRendererNameHash = UINT64_C(2520810486634620725);
    PasswordForm& SetFill_FirstFillingResultInRenderer(int64_t value);

    static const char kFill_FirstWaitForUsernameReasonName[];
    static constexpr uint64_t kFill_FirstWaitForUsernameReasonNameHash = UINT64_C(7438807842425949182);
    PasswordForm& SetFill_FirstWaitForUsernameReason(int64_t value);

    static const char kGeneration_GeneratedPasswordName[];
    static constexpr uint64_t kGeneration_GeneratedPasswordNameHash = UINT64_C(63581670180275077);
    PasswordForm& SetGeneration_GeneratedPassword(int64_t value);

    static const char kGeneration_GeneratedPasswordModifiedName[];
    static constexpr uint64_t kGeneration_GeneratedPasswordModifiedNameHash = UINT64_C(2019134969922041879);
    PasswordForm& SetGeneration_GeneratedPasswordModified(int64_t value);

    static const char kGeneration_PopupShownName[];
    static constexpr uint64_t kGeneration_PopupShownNameHash = UINT64_C(3779268428021661864);
    PasswordForm& SetGeneration_PopupShown(int64_t value);

    static const char kManagerFill_ActionName[];
    static constexpr uint64_t kManagerFill_ActionNameHash = UINT64_C(10479452804440058134);
    PasswordForm& SetManagerFill_Action(int64_t value);

    static const char kManagerFill_AssistanceName[];
    static constexpr uint64_t kManagerFill_AssistanceNameHash = UINT64_C(8134193492903112186);
    PasswordForm& SetManagerFill_Assistance(int64_t value);

    static const char kManagerFill_AssistanceForSingleUsernameName[];
    static constexpr uint64_t kManagerFill_AssistanceForSingleUsernameNameHash = UINT64_C(9541708180713743295);
    PasswordForm& SetManagerFill_AssistanceForSingleUsername(int64_t value);

    static const char kParsingDiffFillingAndSavingName[];
    static constexpr uint64_t kParsingDiffFillingAndSavingNameHash = UINT64_C(13018243475274035602);
    PasswordForm& SetParsingDiffFillingAndSaving(int64_t value);

    static const char kReadonlyWhenFillingName[];
    static constexpr uint64_t kReadonlyWhenFillingNameHash = UINT64_C(4514761882709205318);
    PasswordForm& SetReadonlyWhenFilling(int64_t value);

    static const char kReadonlyWhenSavingName[];
    static constexpr uint64_t kReadonlyWhenSavingNameHash = UINT64_C(3695413570360800308);
    PasswordForm& SetReadonlyWhenSaving(int64_t value);

    static const char kSaving_Prompt_InteractionName[];
    static constexpr uint64_t kSaving_Prompt_InteractionNameHash = UINT64_C(11260027812017306962);
    PasswordForm& SetSaving_Prompt_Interaction(int64_t value);

    static const char kSaving_Prompt_ShownName[];
    static constexpr uint64_t kSaving_Prompt_ShownNameHash = UINT64_C(17150803645879521558);
    PasswordForm& SetSaving_Prompt_Shown(int64_t value);

    static const char kSaving_Prompt_TriggerName[];
    static constexpr uint64_t kSaving_Prompt_TriggerNameHash = UINT64_C(14370044635698072654);
    PasswordForm& SetSaving_Prompt_Trigger(int64_t value);

    static const char kSaving_ShowedManualFallbackForSavingName[];
    static constexpr uint64_t kSaving_ShowedManualFallbackForSavingNameHash = UINT64_C(1380853887219072743);
    PasswordForm& SetSaving_ShowedManualFallbackForSaving(int64_t value);

    static const char kSubmission_IndicatorName[];
    static constexpr uint64_t kSubmission_IndicatorNameHash = UINT64_C(2585760809099691441);
    PasswordForm& SetSubmission_Indicator(int64_t value);

    static const char kSubmission_ObservedName[];
    static constexpr uint64_t kSubmission_ObservedNameHash = UINT64_C(4515933539223991436);
    PasswordForm& SetSubmission_Observed(int64_t value);

    static const char kSubmission_SubmissionResultName[];
    static constexpr uint64_t kSubmission_SubmissionResultNameHash = UINT64_C(15247671546925217641);
    PasswordForm& SetSubmission_SubmissionResult(int64_t value);

    static const char kSubmission_SubmissionResult_GeneratedPasswordName[];
    static constexpr uint64_t kSubmission_SubmissionResult_GeneratedPasswordNameHash = UINT64_C(5733856544777984158);
    PasswordForm& SetSubmission_SubmissionResult_GeneratedPassword(int64_t value);

    static const char kSubmission_SubmittedFormType2Name[];
    static constexpr uint64_t kSubmission_SubmittedFormType2NameHash = UINT64_C(14130122935341980325);
    PasswordForm& SetSubmission_SubmittedFormType2(int64_t value);

    static const char kUpdating_Prompt_InteractionName[];
    static constexpr uint64_t kUpdating_Prompt_InteractionNameHash = UINT64_C(14320711380061622942);
    PasswordForm& SetUpdating_Prompt_Interaction(int64_t value);

    static const char kUpdating_Prompt_ShownName[];
    static constexpr uint64_t kUpdating_Prompt_ShownNameHash = UINT64_C(17781634715365209800);
    PasswordForm& SetUpdating_Prompt_Shown(int64_t value);

    static const char kUpdating_Prompt_TriggerName[];
    static constexpr uint64_t kUpdating_Prompt_TriggerNameHash = UINT64_C(15209183178715629827);
    PasswordForm& SetUpdating_Prompt_Trigger(int64_t value);

    static const char kUser_Action_CorrectedUsernameInFormName[];
    static constexpr uint64_t kUser_Action_CorrectedUsernameInFormNameHash = UINT64_C(7751416161539292552);
    PasswordForm& SetUser_Action_CorrectedUsernameInForm(int64_t value);

    static const char kUser_Action_EditedUsernameInBubbleName[];
    static constexpr uint64_t kUser_Action_EditedUsernameInBubbleNameHash = UINT64_C(10966659704643359477);
    PasswordForm& SetUser_Action_EditedUsernameInBubble(int64_t value);

    static const char kUser_Action_SelectedDifferentPasswordInBubbleName[];
    static constexpr uint64_t kUser_Action_SelectedDifferentPasswordInBubbleNameHash = UINT64_C(6311303221302518030);
    PasswordForm& SetUser_Action_SelectedDifferentPasswordInBubble(int64_t value);

    static const char kUser_Action_TriggeredManualFallbackForSavingName[];
    static constexpr uint64_t kUser_Action_TriggeredManualFallbackForSavingNameHash = UINT64_C(2587019996419876036);
    PasswordForm& SetUser_Action_TriggeredManualFallbackForSaving(int64_t value);
};

class PasswordManager_FirstCCTPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_FirstCCTPageLoad(ukm::SourceId source_id);
    explicit PasswordManager_FirstCCTPageLoad(ukm::SourceIdObj source_id);
    PasswordManager_FirstCCTPageLoad(PasswordManager_FirstCCTPageLoad&&);
    PasswordManager_FirstCCTPageLoad& operator=(PasswordManager_FirstCCTPageLoad&&);
    ~PasswordManager_FirstCCTPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1968976387895384760);

    static const char kHasPasswordFormName[];
    static constexpr uint64_t kHasPasswordFormNameHash = UINT64_C(11835236922656747505);
    PasswordManager_FirstCCTPageLoad& SetHasPasswordForm(int64_t value);
};

class PasswordManager_LeakWarningDialog final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_LeakWarningDialog(ukm::SourceId source_id);
    explicit PasswordManager_LeakWarningDialog(ukm::SourceIdObj source_id);
    PasswordManager_LeakWarningDialog(PasswordManager_LeakWarningDialog&&);
    PasswordManager_LeakWarningDialog& operator=(PasswordManager_LeakWarningDialog&&);
    ~PasswordManager_LeakWarningDialog() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12997918245497021702);

    static const char kPasswordLeakDetectionDialogDismissalReasonName[];
    static constexpr uint64_t kPasswordLeakDetectionDialogDismissalReasonNameHash = UINT64_C(14090109337501726672);
    PasswordManager_LeakWarningDialog& SetPasswordLeakDetectionDialogDismissalReason(int64_t value);

    static const char kPasswordLeakDetectionDialogTypeName[];
    static constexpr uint64_t kPasswordLeakDetectionDialogTypeNameHash = UINT64_C(10374809374421500686);
    PasswordManager_LeakWarningDialog& SetPasswordLeakDetectionDialogType(int64_t value);
};

class PasswordManager_NewlySavedPassword final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_NewlySavedPassword(ukm::SourceId source_id);
    explicit PasswordManager_NewlySavedPassword(ukm::SourceIdObj source_id);
    PasswordManager_NewlySavedPassword(PasswordManager_NewlySavedPassword&&);
    PasswordManager_NewlySavedPassword& operator=(PasswordManager_NewlySavedPassword&&);
    ~PasswordManager_NewlySavedPassword() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3312101392374499085);

    static const char kHasEmptyUsernameName[];
    static constexpr uint64_t kHasEmptyUsernameNameHash = UINT64_C(9648690868448947846);
    PasswordManager_NewlySavedPassword& SetHasEmptyUsername(int64_t value);

    static const char kIsPasswordGeneratedName[];
    static constexpr uint64_t kIsPasswordGeneratedNameHash = UINT64_C(14171687590247907180);
    PasswordManager_NewlySavedPassword& SetIsPasswordGenerated(int64_t value);
};

class PasswordManager_PasswordChangeTriggered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_PasswordChangeTriggered(ukm::SourceId source_id);
    explicit PasswordManager_PasswordChangeTriggered(ukm::SourceIdObj source_id);
    PasswordManager_PasswordChangeTriggered(PasswordManager_PasswordChangeTriggered&&);
    PasswordManager_PasswordChangeTriggered& operator=(PasswordManager_PasswordChangeTriggered&&);
    ~PasswordManager_PasswordChangeTriggered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16550471355748170236);

    static const char kPasswordChangeTypeName[];
    static constexpr uint64_t kPasswordChangeTypeNameHash = UINT64_C(18185276841847428236);
    PasswordManager_PasswordChangeTriggered& SetPasswordChangeType(int64_t value);
};

class PasswordManager_PasswordFillingIOS final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_PasswordFillingIOS(ukm::SourceId source_id);
    explicit PasswordManager_PasswordFillingIOS(ukm::SourceIdObj source_id);
    PasswordManager_PasswordFillingIOS(PasswordManager_PasswordFillingIOS&&);
    PasswordManager_PasswordFillingIOS& operator=(PasswordManager_PasswordFillingIOS&&);
    ~PasswordManager_PasswordFillingIOS() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5726428427092735799);

    static const char kFillingSuccessName[];
    static constexpr uint64_t kFillingSuccessNameHash = UINT64_C(8636960687931743345);
    PasswordManager_PasswordFillingIOS& SetFillingSuccess(int64_t value);
};

class PasswordManager_SavedPassword final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_SavedPassword(ukm::SourceId source_id);
    explicit PasswordManager_SavedPassword(ukm::SourceIdObj source_id);
    PasswordManager_SavedPassword(PasswordManager_SavedPassword&&);
    PasswordManager_SavedPassword& operator=(PasswordManager_SavedPassword&&);
    ~PasswordManager_SavedPassword() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2853752235848375735);

    static const char kIsPasswordGeneratedName[];
    static constexpr uint64_t kIsPasswordGeneratedNameHash = UINT64_C(14171687590247907180);
    PasswordManager_SavedPassword& SetIsPasswordGenerated(int64_t value);
};

class PasswordManager_WellKnownChangePasswordResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PasswordManager_WellKnownChangePasswordResult(ukm::SourceId source_id);
    explicit PasswordManager_WellKnownChangePasswordResult(ukm::SourceIdObj source_id);
    PasswordManager_WellKnownChangePasswordResult(PasswordManager_WellKnownChangePasswordResult&&);
    PasswordManager_WellKnownChangePasswordResult& operator=(PasswordManager_WellKnownChangePasswordResult&&);
    ~PasswordManager_WellKnownChangePasswordResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8595641688177899640);

    static const char kWellKnownChangePasswordResultName[];
    static constexpr uint64_t kWellKnownChangePasswordResultNameHash = UINT64_C(14178683783244667461);
    PasswordManager_WellKnownChangePasswordResult& SetWellKnownChangePasswordResult(int64_t value);
};

class PaymentApp_CheckoutEvents final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PaymentApp_CheckoutEvents(ukm::SourceId source_id);
    explicit PaymentApp_CheckoutEvents(ukm::SourceIdObj source_id);
    PaymentApp_CheckoutEvents(PaymentApp_CheckoutEvents&&);
    PaymentApp_CheckoutEvents& operator=(PaymentApp_CheckoutEvents&&);
    ~PaymentApp_CheckoutEvents() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(702207440764833882);

    static const char kCompletionStatusName[];
    static constexpr uint64_t kCompletionStatusNameHash = UINT64_C(5881049836470043232);
    PaymentApp_CheckoutEvents& SetCompletionStatus(int64_t value);

    static const char kEvents2Name[];
    static constexpr uint64_t kEvents2NameHash = UINT64_C(14505510451531155697);
    PaymentApp_CheckoutEvents& SetEvents2(int64_t value);
};

class PaymentRequest_CheckoutEvents final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PaymentRequest_CheckoutEvents(ukm::SourceId source_id);
    explicit PaymentRequest_CheckoutEvents(ukm::SourceIdObj source_id);
    PaymentRequest_CheckoutEvents(PaymentRequest_CheckoutEvents&&);
    PaymentRequest_CheckoutEvents& operator=(PaymentRequest_CheckoutEvents&&);
    ~PaymentRequest_CheckoutEvents() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9066413457122162526);

    static const char kCompletionStatusName[];
    static constexpr uint64_t kCompletionStatusNameHash = UINT64_C(5881049836470043232);
    PaymentRequest_CheckoutEvents& SetCompletionStatus(int64_t value);

    static const char kEvents2Name[];
    static constexpr uint64_t kEvents2NameHash = UINT64_C(14505510451531155697);
    PaymentRequest_CheckoutEvents& SetEvents2(int64_t value);
};

class PaymentRequest_TransactionAmount final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PaymentRequest_TransactionAmount(ukm::SourceId source_id);
    explicit PaymentRequest_TransactionAmount(ukm::SourceIdObj source_id);
    PaymentRequest_TransactionAmount(PaymentRequest_TransactionAmount&&);
    PaymentRequest_TransactionAmount& operator=(PaymentRequest_TransactionAmount&&);
    ~PaymentRequest_TransactionAmount() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4090736682116197688);

    static const char kCategoryName[];
    static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
    PaymentRequest_TransactionAmount& SetCategory(int64_t value);

    static const char kCompletionStatusName[];
    static constexpr uint64_t kCompletionStatusNameHash = UINT64_C(5881049836470043232);
    PaymentRequest_TransactionAmount& SetCompletionStatus(int64_t value);
};

class Pepper_Broker final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Pepper_Broker(ukm::SourceId source_id);
    explicit Pepper_Broker(ukm::SourceIdObj source_id);
    Pepper_Broker(Pepper_Broker&&);
    Pepper_Broker& operator=(Pepper_Broker&&);
    ~Pepper_Broker() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4863880088883807024);
};

class PerformanceAPI_LongAnimationFrame final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PerformanceAPI_LongAnimationFrame(ukm::SourceId source_id);
    explicit PerformanceAPI_LongAnimationFrame(ukm::SourceIdObj source_id);
    PerformanceAPI_LongAnimationFrame(PerformanceAPI_LongAnimationFrame&&);
    PerformanceAPI_LongAnimationFrame& operator=(PerformanceAPI_LongAnimationFrame&&);
    ~PerformanceAPI_LongAnimationFrame() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13281029919793825830);

    static const char kCategorized3PScriptLongAnimationFrameCallbackContributorsName[];
    static constexpr uint64_t kCategorized3PScriptLongAnimationFrameCallbackContributorsNameHash = UINT64_C(12022287678124773637);
    PerformanceAPI_LongAnimationFrame& SetCategorized3PScriptLongAnimationFrameCallbackContributors(int64_t value);

    static const char kCategorized3PScriptLongAnimationFrameScriptExecutionContributorsName[];
    static constexpr uint64_t kCategorized3PScriptLongAnimationFrameScriptExecutionContributorsNameHash = UINT64_C(4829151277415230072);
    PerformanceAPI_LongAnimationFrame& SetCategorized3PScriptLongAnimationFrameScriptExecutionContributors(int64_t value);

    static const char kDidPauseName[];
    static constexpr uint64_t kDidPauseNameHash = UINT64_C(10477248178901679230);
    PerformanceAPI_LongAnimationFrame& SetDidPause(int64_t value);

    static const char kDuration_DelayDeferName[];
    static constexpr uint64_t kDuration_DelayDeferNameHash = UINT64_C(7860748054848675842);
    PerformanceAPI_LongAnimationFrame& SetDuration_DelayDefer(int64_t value);

    static const char kDuration_EffectiveBlockingName[];
    static constexpr uint64_t kDuration_EffectiveBlockingNameHash = UINT64_C(13038771578899747948);
    PerformanceAPI_LongAnimationFrame& SetDuration_EffectiveBlocking(int64_t value);

    static const char kDuration_LongScript_JSCompilationName[];
    static constexpr uint64_t kDuration_LongScript_JSCompilationNameHash = UINT64_C(10883554306249058650);
    PerformanceAPI_LongAnimationFrame& SetDuration_LongScript_JSCompilation(int64_t value);

    static const char kDuration_LongScript_JSExecutionName[];
    static constexpr uint64_t kDuration_LongScript_JSExecutionNameHash = UINT64_C(18402005098376918543);
    PerformanceAPI_LongAnimationFrame& SetDuration_LongScript_JSExecution(int64_t value);

    static const char kDuration_LongScript_JSExecution_EventListenersName[];
    static constexpr uint64_t kDuration_LongScript_JSExecution_EventListenersNameHash = UINT64_C(12994815396606177711);
    PerformanceAPI_LongAnimationFrame& SetDuration_LongScript_JSExecution_EventListeners(int64_t value);

    static const char kDuration_LongScript_JSExecution_PromiseHandlersName[];
    static constexpr uint64_t kDuration_LongScript_JSExecution_PromiseHandlersNameHash = UINT64_C(8964170774657714896);
    PerformanceAPI_LongAnimationFrame& SetDuration_LongScript_JSExecution_PromiseHandlers(int64_t value);

    static const char kDuration_LongScript_JSExecution_ScriptBlocksName[];
    static constexpr uint64_t kDuration_LongScript_JSExecution_ScriptBlocksNameHash = UINT64_C(6995194644947410183);
    PerformanceAPI_LongAnimationFrame& SetDuration_LongScript_JSExecution_ScriptBlocks(int64_t value);

    static const char kDuration_LongScript_JSExecution_UserCallbacksName[];
    static constexpr uint64_t kDuration_LongScript_JSExecution_UserCallbacksNameHash = UINT64_C(11858193551669125580);
    PerformanceAPI_LongAnimationFrame& SetDuration_LongScript_JSExecution_UserCallbacks(int64_t value);

    static const char kDuration_StyleAndLayout_ForcedName[];
    static constexpr uint64_t kDuration_StyleAndLayout_ForcedNameHash = UINT64_C(5027273651206559127);
    PerformanceAPI_LongAnimationFrame& SetDuration_StyleAndLayout_Forced(int64_t value);

    static const char kDuration_StyleAndLayout_RenderPhaseName[];
    static constexpr uint64_t kDuration_StyleAndLayout_RenderPhaseNameHash = UINT64_C(9815790627351523584);
    PerformanceAPI_LongAnimationFrame& SetDuration_StyleAndLayout_RenderPhase(int64_t value);

    static const char kDuration_TotalName[];
    static constexpr uint64_t kDuration_TotalNameHash = UINT64_C(5658354959596154336);
    PerformanceAPI_LongAnimationFrame& SetDuration_Total(int64_t value);
};

class PerformanceAPI_LongTask final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PerformanceAPI_LongTask(ukm::SourceId source_id);
    explicit PerformanceAPI_LongTask(ukm::SourceIdObj source_id);
    PerformanceAPI_LongTask(PerformanceAPI_LongTask&&);
    PerformanceAPI_LongTask& operator=(PerformanceAPI_LongTask&&);
    ~PerformanceAPI_LongTask() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8942554384206766435);

    static const char kDurationName[];
    static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
    PerformanceAPI_LongTask& SetDuration(int64_t value);

    static const char kDuration_V8_ExecuteName[];
    static constexpr uint64_t kDuration_V8_ExecuteNameHash = UINT64_C(13534678444182987197);
    PerformanceAPI_LongTask& SetDuration_V8_Execute(int64_t value);

    static const char kDuration_V8_GCName[];
    static constexpr uint64_t kDuration_V8_GCNameHash = UINT64_C(11348730230744439520);
    PerformanceAPI_LongTask& SetDuration_V8_GC(int64_t value);

    static const char kDuration_V8_GC_Full_AtomicName[];
    static constexpr uint64_t kDuration_V8_GC_Full_AtomicNameHash = UINT64_C(10673238490554543557);
    PerformanceAPI_LongTask& SetDuration_V8_GC_Full_Atomic(int64_t value);

    static const char kDuration_V8_GC_Full_IncrementalName[];
    static constexpr uint64_t kDuration_V8_GC_Full_IncrementalNameHash = UINT64_C(17195329852058948643);
    PerformanceAPI_LongTask& SetDuration_V8_GC_Full_Incremental(int64_t value);

    static const char kDuration_V8_GC_YoungName[];
    static constexpr uint64_t kDuration_V8_GC_YoungNameHash = UINT64_C(6481026756167768720);
    PerformanceAPI_LongTask& SetDuration_V8_GC_Young(int64_t value);

    static const char kStartTimeName[];
    static constexpr uint64_t kStartTimeNameHash = UINT64_C(10676292628526786927);
    PerformanceAPI_LongTask& SetStartTime(int64_t value);
};

class PerformanceAPI_Memory final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PerformanceAPI_Memory(ukm::SourceId source_id);
    explicit PerformanceAPI_Memory(ukm::SourceIdObj source_id);
    PerformanceAPI_Memory(PerformanceAPI_Memory&&);
    PerformanceAPI_Memory& operator=(PerformanceAPI_Memory&&);
    ~PerformanceAPI_Memory() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11822404190090982098);

    static const char kDomName[];
    static constexpr uint64_t kDomNameHash = UINT64_C(9578980484144019624);
    PerformanceAPI_Memory& SetDom(int64_t value);

    static const char kJavaScriptName[];
    static constexpr uint64_t kJavaScriptNameHash = UINT64_C(7521387064766892559);
    PerformanceAPI_Memory& SetJavaScript(int64_t value);

    static const char kJavaScript_DedicatedWorkerName[];
    static constexpr uint64_t kJavaScript_DedicatedWorkerNameHash = UINT64_C(16530699357747008004);
    PerformanceAPI_Memory& SetJavaScript_DedicatedWorker(int64_t value);

    static const char kSharedName[];
    static constexpr uint64_t kSharedNameHash = UINT64_C(11967593260533149476);
    PerformanceAPI_Memory& SetShared(int64_t value);
};

class PerformanceAPI_Memory_Legacy final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PerformanceAPI_Memory_Legacy(ukm::SourceId source_id);
    explicit PerformanceAPI_Memory_Legacy(ukm::SourceIdObj source_id);
    PerformanceAPI_Memory_Legacy(PerformanceAPI_Memory_Legacy&&);
    PerformanceAPI_Memory_Legacy& operator=(PerformanceAPI_Memory_Legacy&&);
    ~PerformanceAPI_Memory_Legacy() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2959950180700461082);

    static const char kJavaScriptName[];
    static constexpr uint64_t kJavaScriptNameHash = UINT64_C(7521387064766892559);
    PerformanceAPI_Memory_Legacy& SetJavaScript(int64_t value);
};

class PerformanceManager_PageResourceUsage2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PerformanceManager_PageResourceUsage2(ukm::SourceId source_id);
    explicit PerformanceManager_PageResourceUsage2(ukm::SourceIdObj source_id);
    PerformanceManager_PageResourceUsage2(PerformanceManager_PageResourceUsage2&&);
    PerformanceManager_PageResourceUsage2& operator=(PerformanceManager_PageResourceUsage2&&);
    ~PerformanceManager_PageResourceUsage2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7310102334970989195);

    static const char kBackgroundStateName[];
    static constexpr uint64_t kBackgroundStateNameHash = UINT64_C(16811821127666008107);
    PerformanceManager_PageResourceUsage2& SetBackgroundState(int64_t value);

    static const char kMeasurementAlgorithmName[];
    static constexpr uint64_t kMeasurementAlgorithmNameHash = UINT64_C(7071568143101297096);
    PerformanceManager_PageResourceUsage2& SetMeasurementAlgorithm(int64_t value);

    static const char kPrivateFootprintEstimateName[];
    static constexpr uint64_t kPrivateFootprintEstimateNameHash = UINT64_C(2207187191511944491);
    PerformanceManager_PageResourceUsage2& SetPrivateFootprintEstimate(int64_t value);

    static const char kRecentCPUUsageName[];
    static constexpr uint64_t kRecentCPUUsageNameHash = UINT64_C(8604815657982414208);
    PerformanceManager_PageResourceUsage2& SetRecentCPUUsage(int64_t value);

    static const char kResidentSetSizeEstimateName[];
    static constexpr uint64_t kResidentSetSizeEstimateNameHash = UINT64_C(814404864056972047);
    PerformanceManager_PageResourceUsage2& SetResidentSetSizeEstimate(int64_t value);

    static const char kTotalRecentCPUUsageAllPagesName[];
    static constexpr uint64_t kTotalRecentCPUUsageAllPagesNameHash = UINT64_C(3522526693229877297);
    PerformanceManager_PageResourceUsage2& SetTotalRecentCPUUsageAllPages(int64_t value);
};

class PeriodicBackgroundSyncEventCompleted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PeriodicBackgroundSyncEventCompleted(ukm::SourceId source_id);
    explicit PeriodicBackgroundSyncEventCompleted(ukm::SourceIdObj source_id);
    PeriodicBackgroundSyncEventCompleted(PeriodicBackgroundSyncEventCompleted&&);
    PeriodicBackgroundSyncEventCompleted& operator=(PeriodicBackgroundSyncEventCompleted&&);
    ~PeriodicBackgroundSyncEventCompleted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10863131082725230381);

    static const char kMaxAttemptsName[];
    static constexpr uint64_t kMaxAttemptsNameHash = UINT64_C(13811216186026220346);
    PeriodicBackgroundSyncEventCompleted& SetMaxAttempts(int64_t value);

    static const char kNumAttemptsName[];
    static constexpr uint64_t kNumAttemptsNameHash = UINT64_C(537979731801272247);
    PeriodicBackgroundSyncEventCompleted& SetNumAttempts(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    PeriodicBackgroundSyncEventCompleted& SetStatus(int64_t value);
};

class PeriodicBackgroundSyncRegistered final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PeriodicBackgroundSyncRegistered(ukm::SourceId source_id);
    explicit PeriodicBackgroundSyncRegistered(ukm::SourceIdObj source_id);
    PeriodicBackgroundSyncRegistered(PeriodicBackgroundSyncRegistered&&);
    PeriodicBackgroundSyncRegistered& operator=(PeriodicBackgroundSyncRegistered&&);
    ~PeriodicBackgroundSyncRegistered() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8211654418406942912);

    static const char kIsReregisteredName[];
    static constexpr uint64_t kIsReregisteredNameHash = UINT64_C(10082741689941820461);
    PeriodicBackgroundSyncRegistered& SetIsReregistered(int64_t value);

    static const char kMinIntervalMsName[];
    static constexpr uint64_t kMinIntervalMsNameHash = UINT64_C(11330617392665034633);
    PeriodicBackgroundSyncRegistered& SetMinIntervalMs(int64_t value);
};

class Permission final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Permission(ukm::SourceId source_id);
    explicit Permission(ukm::SourceIdObj source_id);
    Permission(Permission&&);
    Permission& operator=(Permission&&);
    ~Permission() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17104084284355864347);

    static const char kActionName[];
    static constexpr uint64_t kActionNameHash = UINT64_C(21381969153622804);
    Permission& SetAction(int64_t value);

    static const char kGestureName[];
    static constexpr uint64_t kGestureNameHash = UINT64_C(1976985484619472355);
    Permission& SetGesture(int64_t value);

    static const char kOsPromptScreenName[];
    static constexpr uint64_t kOsPromptScreenNameHash = UINT64_C(9214598296304828588);
    Permission& SetOsPromptScreen(int64_t value);

    static const char kOsSystemSettingsScreenName[];
    static constexpr uint64_t kOsSystemSettingsScreenNameHash = UINT64_C(15057035871558248926);
    Permission& SetOsSystemSettingsScreen(int64_t value);

    static const char kPermissionAutoRevocationHistoryName[];
    static constexpr uint64_t kPermissionAutoRevocationHistoryNameHash = UINT64_C(4395845358858109531);
    Permission& SetPermissionAutoRevocationHistory(int64_t value);

    static const char kPermissionTypeName[];
    static constexpr uint64_t kPermissionTypeNameHash = UINT64_C(12838086084889581840);
    Permission& SetPermissionType(int64_t value);

    static const char kPredictionsApiResponse_GrantLikelihoodName[];
    static constexpr uint64_t kPredictionsApiResponse_GrantLikelihoodNameHash = UINT64_C(10440558144748451030);
    Permission& SetPredictionsApiResponse_GrantLikelihood(int64_t value);

    static const char kPredictionsApiResponse_HeldbackName[];
    static constexpr uint64_t kPredictionsApiResponse_HeldbackNameHash = UINT64_C(5074470472847521686);
    Permission& SetPredictionsApiResponse_Heldback(int64_t value);

    static const char kPriorDismissalsName[];
    static constexpr uint64_t kPriorDismissalsNameHash = UINT64_C(9632910442238752479);
    Permission& SetPriorDismissals(int64_t value);

    static const char kPriorIgnoresName[];
    static constexpr uint64_t kPriorIgnoresNameHash = UINT64_C(1762046784113667081);
    Permission& SetPriorIgnores(int64_t value);

    static const char kPromptDispositionName[];
    static constexpr uint64_t kPromptDispositionNameHash = UINT64_C(1320746900446203052);
    Permission& SetPromptDisposition(int64_t value);

    static const char kPromptDispositionReasonName[];
    static constexpr uint64_t kPromptDispositionReasonNameHash = UINT64_C(4135685975003167800);
    Permission& SetPromptDispositionReason(int64_t value);

    static const char kSatisfiedAdaptiveTriggersName[];
    static constexpr uint64_t kSatisfiedAdaptiveTriggersNameHash = UINT64_C(12099198537911135529);
    Permission& SetSatisfiedAdaptiveTriggers(int64_t value);

    static const char kSiteLevelScreenName[];
    static constexpr uint64_t kSiteLevelScreenNameHash = UINT64_C(16322576922840687148);
    Permission& SetSiteLevelScreen(int64_t value);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    Permission& SetSource(int64_t value);

    static const char kStats_AllPrompts_CountName[];
    static constexpr uint64_t kStats_AllPrompts_CountNameHash = UINT64_C(15206135699388839777);
    Permission& SetStats_AllPrompts_Count(int64_t value);

    static const char kStats_AllPrompts_DenyRateName[];
    static constexpr uint64_t kStats_AllPrompts_DenyRateNameHash = UINT64_C(4614926123709421369);
    Permission& SetStats_AllPrompts_DenyRate(int64_t value);

    static const char kStats_AllPrompts_DismissRateName[];
    static constexpr uint64_t kStats_AllPrompts_DismissRateNameHash = UINT64_C(6569639006048162080);
    Permission& SetStats_AllPrompts_DismissRate(int64_t value);

    static const char kStats_AllPrompts_GrantRateName[];
    static constexpr uint64_t kStats_AllPrompts_GrantRateNameHash = UINT64_C(16961482723309424386);
    Permission& SetStats_AllPrompts_GrantRate(int64_t value);

    static const char kStats_AllPrompts_IgnoreRateName[];
    static constexpr uint64_t kStats_AllPrompts_IgnoreRateNameHash = UINT64_C(15911128293907354588);
    Permission& SetStats_AllPrompts_IgnoreRate(int64_t value);

    static const char kStats_AllPromptsOfType_CountName[];
    static constexpr uint64_t kStats_AllPromptsOfType_CountNameHash = UINT64_C(2894571301281378860);
    Permission& SetStats_AllPromptsOfType_Count(int64_t value);

    static const char kStats_AllPromptsOfType_DenyRateName[];
    static constexpr uint64_t kStats_AllPromptsOfType_DenyRateNameHash = UINT64_C(9889400848536277793);
    Permission& SetStats_AllPromptsOfType_DenyRate(int64_t value);

    static const char kStats_AllPromptsOfType_DismissRateName[];
    static constexpr uint64_t kStats_AllPromptsOfType_DismissRateNameHash = UINT64_C(15001255705471340582);
    Permission& SetStats_AllPromptsOfType_DismissRate(int64_t value);

    static const char kStats_AllPromptsOfType_GrantRateName[];
    static constexpr uint64_t kStats_AllPromptsOfType_GrantRateNameHash = UINT64_C(13185700162536785576);
    Permission& SetStats_AllPromptsOfType_GrantRate(int64_t value);

    static const char kStats_AllPromptsOfType_IgnoreRateName[];
    static constexpr uint64_t kStats_AllPromptsOfType_IgnoreRateNameHash = UINT64_C(16808663110025527857);
    Permission& SetStats_AllPromptsOfType_IgnoreRate(int64_t value);

    static const char kStats_LoudPrompts_CountName[];
    static constexpr uint64_t kStats_LoudPrompts_CountNameHash = UINT64_C(9000538913142475069);
    Permission& SetStats_LoudPrompts_Count(int64_t value);

    static const char kStats_LoudPrompts_DenyRateName[];
    static constexpr uint64_t kStats_LoudPrompts_DenyRateNameHash = UINT64_C(6010234502411570844);
    Permission& SetStats_LoudPrompts_DenyRate(int64_t value);

    static const char kStats_LoudPrompts_DismissRateName[];
    static constexpr uint64_t kStats_LoudPrompts_DismissRateNameHash = UINT64_C(17731114805811696064);
    Permission& SetStats_LoudPrompts_DismissRate(int64_t value);

    static const char kStats_LoudPrompts_GrantRateName[];
    static constexpr uint64_t kStats_LoudPrompts_GrantRateNameHash = UINT64_C(18412528996966962990);
    Permission& SetStats_LoudPrompts_GrantRate(int64_t value);

    static const char kStats_LoudPrompts_IgnoreRateName[];
    static constexpr uint64_t kStats_LoudPrompts_IgnoreRateNameHash = UINT64_C(16365837423998619980);
    Permission& SetStats_LoudPrompts_IgnoreRate(int64_t value);

    static const char kStats_LoudPromptsOfType_CountName[];
    static constexpr uint64_t kStats_LoudPromptsOfType_CountNameHash = UINT64_C(17886527325867741808);
    Permission& SetStats_LoudPromptsOfType_Count(int64_t value);

    static const char kStats_LoudPromptsOfType_DenyRateName[];
    static constexpr uint64_t kStats_LoudPromptsOfType_DenyRateNameHash = UINT64_C(4682629720509934157);
    Permission& SetStats_LoudPromptsOfType_DenyRate(int64_t value);

    static const char kStats_LoudPromptsOfType_DismissRateName[];
    static constexpr uint64_t kStats_LoudPromptsOfType_DismissRateNameHash = UINT64_C(6009246587762481053);
    Permission& SetStats_LoudPromptsOfType_DismissRate(int64_t value);

    static const char kStats_LoudPromptsOfType_GrantRateName[];
    static constexpr uint64_t kStats_LoudPromptsOfType_GrantRateNameHash = UINT64_C(15857171918587165852);
    Permission& SetStats_LoudPromptsOfType_GrantRate(int64_t value);

    static const char kStats_LoudPromptsOfType_IgnoreRateName[];
    static constexpr uint64_t kStats_LoudPromptsOfType_IgnoreRateNameHash = UINT64_C(5099038401407550192);
    Permission& SetStats_LoudPromptsOfType_IgnoreRate(int64_t value);

    static const char kTimeToDecisionName[];
    static constexpr uint64_t kTimeToDecisionNameHash = UINT64_C(9106479769666366905);
    Permission& SetTimeToDecision(int64_t value);
};

class Permissions_EmbeddedPromptAction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Permissions_EmbeddedPromptAction(ukm::SourceId source_id);
    explicit Permissions_EmbeddedPromptAction(ukm::SourceIdObj source_id);
    Permissions_EmbeddedPromptAction(Permissions_EmbeddedPromptAction&&);
    Permissions_EmbeddedPromptAction& operator=(Permissions_EmbeddedPromptAction&&);
    ~Permissions_EmbeddedPromptAction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(623278836175790870);

    static const char kActionName[];
    static constexpr uint64_t kActionNameHash = UINT64_C(21381969153622804);
    Permissions_EmbeddedPromptAction& SetAction(int64_t value);

    static const char kPermissionTypeName[];
    static constexpr uint64_t kPermissionTypeNameHash = UINT64_C(12838086084889581840);
    Permissions_EmbeddedPromptAction& SetPermissionType(int64_t value);

    static const char kPreviousScreensName[];
    static constexpr uint64_t kPreviousScreensNameHash = UINT64_C(13528206729219176767);
    Permissions_EmbeddedPromptAction& SetPreviousScreens(int64_t value);

    static const char kScreenPermissionTypeName[];
    static constexpr uint64_t kScreenPermissionTypeNameHash = UINT64_C(7670698461569478849);
    Permissions_EmbeddedPromptAction& SetScreenPermissionType(int64_t value);

    static const char kVariantName[];
    static constexpr uint64_t kVariantNameHash = UINT64_C(5273460858772635525);
    Permissions_EmbeddedPromptAction& SetVariant(int64_t value);
};

class PermissionUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PermissionUsage(ukm::SourceId source_id);
    explicit PermissionUsage(ukm::SourceIdObj source_id);
    PermissionUsage(PermissionUsage&&);
    PermissionUsage& operator=(PermissionUsage&&);
    ~PermissionUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15070635187011991637);

    static const char kPermissionTypeName[];
    static constexpr uint64_t kPermissionTypeNameHash = UINT64_C(12838086084889581840);
    PermissionUsage& SetPermissionType(int64_t value);
};

class PermissionUsage_NotificationShown final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PermissionUsage_NotificationShown(ukm::SourceId source_id);
    explicit PermissionUsage_NotificationShown(ukm::SourceIdObj source_id);
    PermissionUsage_NotificationShown(PermissionUsage_NotificationShown&&);
    PermissionUsage_NotificationShown& operator=(PermissionUsage_NotificationShown&&);
    ~PermissionUsage_NotificationShown() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15267494322272545140);

    static const char kIsAllowlistedName[];
    static constexpr uint64_t kIsAllowlistedNameHash = UINT64_C(5190351420911942120);
    PermissionUsage_NotificationShown& SetIsAllowlisted(int64_t value);

    static const char kSuspiciousScoreName[];
    static constexpr uint64_t kSuspiciousScoreNameHash = UINT64_C(1884778691142411541);
    PermissionUsage_NotificationShown& SetSuspiciousScore(int64_t value);
};

class Plugins_FlashInstance final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Plugins_FlashInstance(ukm::SourceId source_id);
    explicit Plugins_FlashInstance(ukm::SourceIdObj source_id);
    Plugins_FlashInstance(Plugins_FlashInstance&&);
    Plugins_FlashInstance& operator=(Plugins_FlashInstance&&);
    ~Plugins_FlashInstance() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2851782918499658607);
};

class PlusAddresses_Submission final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PlusAddresses_Submission(ukm::SourceId source_id);
    explicit PlusAddresses_Submission(ukm::SourceIdObj source_id);
    PlusAddresses_Submission(PlusAddresses_Submission&&);
    PlusAddresses_Submission& operator=(PlusAddresses_Submission&&);
    ~PlusAddresses_Submission() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5655451705717763469);

    static const char kCheckoutOrCartPageName[];
    static constexpr uint64_t kCheckoutOrCartPageNameHash = UINT64_C(8533934222907466062);
    PlusAddresses_Submission& SetCheckoutOrCartPage(int64_t value);

    static const char kFieldCountBrowserFormName[];
    static constexpr uint64_t kFieldCountBrowserFormNameHash = UINT64_C(12108112839660673628);
    PlusAddresses_Submission& SetFieldCountBrowserForm(int64_t value);

    static const char kFieldCountRendererFormName[];
    static constexpr uint64_t kFieldCountRendererFormNameHash = UINT64_C(4366257803443961215);
    PlusAddresses_Submission& SetFieldCountRendererForm(int64_t value);

    static const char kManagedProfileName[];
    static constexpr uint64_t kManagedProfileNameHash = UINT64_C(340739973098159305);
    PlusAddresses_Submission& SetManagedProfile(int64_t value);

    static const char kNewlyCreatedPlusAddressName[];
    static constexpr uint64_t kNewlyCreatedPlusAddressNameHash = UINT64_C(12514410101414426586);
    PlusAddresses_Submission& SetNewlyCreatedPlusAddress(int64_t value);

    static const char kPasswordFormTypeName[];
    static constexpr uint64_t kPasswordFormTypeNameHash = UINT64_C(13822968525396020693);
    PlusAddresses_Submission& SetPasswordFormType(int64_t value);

    static const char kPlusAddressCountName[];
    static constexpr uint64_t kPlusAddressCountNameHash = UINT64_C(14840774790702528463);
    PlusAddresses_Submission& SetPlusAddressCount(int64_t value);

    static const char kSubmittedPlusAddressName[];
    static constexpr uint64_t kSubmittedPlusAddressNameHash = UINT64_C(16199847477669922376);
    PlusAddresses_Submission& SetSubmittedPlusAddress(int64_t value);

    static const char kSuggestionContextName[];
    static constexpr uint64_t kSuggestionContextNameHash = UINT64_C(17542675645890167825);
    PlusAddresses_Submission& SetSuggestionContext(int64_t value);

    static const char kWasShownCreateSuggestionName[];
    static constexpr uint64_t kWasShownCreateSuggestionNameHash = UINT64_C(17044885873250791936);
    PlusAddresses_Submission& SetWasShownCreateSuggestion(int64_t value);
};

class Popup_Closed final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Popup_Closed(ukm::SourceId source_id);
    explicit Popup_Closed(ukm::SourceIdObj source_id);
    Popup_Closed(Popup_Closed&&);
    Popup_Closed& operator=(Popup_Closed&&);
    ~Popup_Closed() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5373577291340314501);

    static const char kEngagementTimeName[];
    static constexpr uint64_t kEngagementTimeNameHash = UINT64_C(5757927903187539607);
    Popup_Closed& SetEngagementTime(int64_t value);

    static const char kNumActivationInteractionsName[];
    static constexpr uint64_t kNumActivationInteractionsNameHash = UINT64_C(1968290450355139412);
    Popup_Closed& SetNumActivationInteractions(int64_t value);

    static const char kNumGestureScrollBeginInteractionsName[];
    static constexpr uint64_t kNumGestureScrollBeginInteractionsNameHash = UINT64_C(16455411608912728271);
    Popup_Closed& SetNumGestureScrollBeginInteractions(int64_t value);

    static const char kNumInteractionsName[];
    static constexpr uint64_t kNumInteractionsNameHash = UINT64_C(5654420946245687695);
    Popup_Closed& SetNumInteractions(int64_t value);

    static const char kRedirectCountName[];
    static constexpr uint64_t kRedirectCountNameHash = UINT64_C(12071261283211509878);
    Popup_Closed& SetRedirectCount(int64_t value);

    static const char kSafeBrowsingStatusName[];
    static constexpr uint64_t kSafeBrowsingStatusNameHash = UINT64_C(9647052102537443981);
    Popup_Closed& SetSafeBrowsingStatus(int64_t value);

    static const char kTrustedName[];
    static constexpr uint64_t kTrustedNameHash = UINT64_C(13853175197766416028);
    Popup_Closed& SetTrusted(int64_t value);

    static const char kUserInitiatedCloseName[];
    static constexpr uint64_t kUserInitiatedCloseNameHash = UINT64_C(16452490512765540245);
    Popup_Closed& SetUserInitiatedClose(int64_t value);

    static const char kWindowOpenDispositionName[];
    static constexpr uint64_t kWindowOpenDispositionNameHash = UINT64_C(17804395139469765033);
    Popup_Closed& SetWindowOpenDisposition(int64_t value);
};

class Popup_Page final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Popup_Page(ukm::SourceId source_id);
    explicit Popup_Page(ukm::SourceIdObj source_id);
    Popup_Page(Popup_Page&&);
    Popup_Page& operator=(Popup_Page&&);
    ~Popup_Page() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9277003375443527515);

    static const char kAllowedName[];
    static constexpr uint64_t kAllowedNameHash = UINT64_C(13501762879137544078);
    Popup_Page& SetAllowed(int64_t value);
};

class Portal_Activate final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Portal_Activate(ukm::SourceId source_id);
    explicit Portal_Activate(ukm::SourceIdObj source_id);
    Portal_Activate(Portal_Activate&&);
    Portal_Activate& operator=(Portal_Activate&&);
    ~Portal_Activate() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(570650911258459707);

    static const char kPaintTiming_PortalActivationToFirstPaintName[];
    static constexpr uint64_t kPaintTiming_PortalActivationToFirstPaintNameHash = UINT64_C(10350998418336997145);
    Portal_Activate& SetPaintTiming_PortalActivationToFirstPaint(int64_t value);

    static const char kPortalActivationName[];
    static constexpr uint64_t kPortalActivationNameHash = UINT64_C(4430962806322008522);
    Portal_Activate& SetPortalActivation(int64_t value);

    static const char kPortalActivationBeforeLCPName[];
    static constexpr uint64_t kPortalActivationBeforeLCPNameHash = UINT64_C(16175379994101710778);
    Portal_Activate& SetPortalActivationBeforeLCP(int64_t value);
};

class PowerUsageScenariosIntervalData final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PowerUsageScenariosIntervalData(ukm::SourceId source_id);
    explicit PowerUsageScenariosIntervalData(ukm::SourceIdObj source_id);
    PowerUsageScenariosIntervalData(PowerUsageScenariosIntervalData&&);
    PowerUsageScenariosIntervalData& operator=(PowerUsageScenariosIntervalData&&);
    ~PowerUsageScenariosIntervalData() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1484103205961568756);

    static const char kBatteryDischargeModeName[];
    static constexpr uint64_t kBatteryDischargeModeNameHash = UINT64_C(8012802177325134825);
    PowerUsageScenariosIntervalData& SetBatteryDischargeMode(int64_t value);

    static const char kBatteryDischargeRateName[];
    static constexpr uint64_t kBatteryDischargeRateNameHash = UINT64_C(10740279131128052720);
    PowerUsageScenariosIntervalData& SetBatteryDischargeRate(int64_t value);

    static const char kBrowserShuttingDownName[];
    static constexpr uint64_t kBrowserShuttingDownNameHash = UINT64_C(4764183469636912406);
    PowerUsageScenariosIntervalData& SetBrowserShuttingDown(int64_t value);

    static const char kCPUTimeMsName[];
    static constexpr uint64_t kCPUTimeMsNameHash = UINT64_C(6926632203034980955);
    PowerUsageScenariosIntervalData& SetCPUTimeMs(int64_t value);

    static const char kDeviceSleptDuringIntervalName[];
    static constexpr uint64_t kDeviceSleptDuringIntervalNameHash = UINT64_C(1647534641725523716);
    PowerUsageScenariosIntervalData& SetDeviceSleptDuringInterval(int64_t value);

    static const char kFullscreenVideoSingleMonitorSecondsName[];
    static constexpr uint64_t kFullscreenVideoSingleMonitorSecondsNameHash = UINT64_C(5005689392526458623);
    PowerUsageScenariosIntervalData& SetFullscreenVideoSingleMonitorSeconds(int64_t value);

    static const char kIdleWakeUpsName[];
    static constexpr uint64_t kIdleWakeUpsNameHash = UINT64_C(13129480748900936528);
    PowerUsageScenariosIntervalData& SetIdleWakeUps(int64_t value);

    static const char kIntervalDurationSecondsName[];
    static constexpr uint64_t kIntervalDurationSecondsNameHash = UINT64_C(10060515322332976046);
    PowerUsageScenariosIntervalData& SetIntervalDurationSeconds(int64_t value);

    static const char kMaxTabCountName[];
    static constexpr uint64_t kMaxTabCountNameHash = UINT64_C(9962046382391466848);
    PowerUsageScenariosIntervalData& SetMaxTabCount(int64_t value);

    static const char kMaxVisibleWindowCountName[];
    static constexpr uint64_t kMaxVisibleWindowCountNameHash = UINT64_C(15536078874238250161);
    PowerUsageScenariosIntervalData& SetMaxVisibleWindowCount(int64_t value);

    static const char kOriginVisibilityTimeSecondsName[];
    static constexpr uint64_t kOriginVisibilityTimeSecondsNameHash = UINT64_C(4655053852122721981);
    PowerUsageScenariosIntervalData& SetOriginVisibilityTimeSeconds(int64_t value);

    static const char kPackageExitsName[];
    static constexpr uint64_t kPackageExitsNameHash = UINT64_C(14500460936964638692);
    PowerUsageScenariosIntervalData& SetPackageExits(int64_t value);

    static const char kPlayingAudioSecondsName[];
    static constexpr uint64_t kPlayingAudioSecondsNameHash = UINT64_C(3986924567980634530);
    PowerUsageScenariosIntervalData& SetPlayingAudioSeconds(int64_t value);

    static const char kTabClosedName[];
    static constexpr uint64_t kTabClosedNameHash = UINT64_C(17527225635667832158);
    PowerUsageScenariosIntervalData& SetTabClosed(int64_t value);

    static const char kTimePlayingVideoInVisibleTabName[];
    static constexpr uint64_t kTimePlayingVideoInVisibleTabNameHash = UINT64_C(15495195187441109248);
    PowerUsageScenariosIntervalData& SetTimePlayingVideoInVisibleTab(int64_t value);

    static const char kTimeSinceInteractionWithBrowserSecondsName[];
    static constexpr uint64_t kTimeSinceInteractionWithBrowserSecondsNameHash = UINT64_C(6261712889956192806);
    PowerUsageScenariosIntervalData& SetTimeSinceInteractionWithBrowserSeconds(int64_t value);

    static const char kTimeSinceInteractionWithSystemSecondsName[];
    static constexpr uint64_t kTimeSinceInteractionWithSystemSecondsNameHash = UINT64_C(16376385176122552687);
    PowerUsageScenariosIntervalData& SetTimeSinceInteractionWithSystemSeconds(int64_t value);

    static const char kTimeWithOpenWebRTCConnectionSecondsName[];
    static constexpr uint64_t kTimeWithOpenWebRTCConnectionSecondsNameHash = UINT64_C(2972750681128012711);
    PowerUsageScenariosIntervalData& SetTimeWithOpenWebRTCConnectionSeconds(int64_t value);

    static const char kTopLevelNavigationEventsName[];
    static constexpr uint64_t kTopLevelNavigationEventsNameHash = UINT64_C(9007247521834190514);
    PowerUsageScenariosIntervalData& SetTopLevelNavigationEvents(int64_t value);

    static const char kUptimeSecondsName[];
    static constexpr uint64_t kUptimeSecondsNameHash = UINT64_C(2001952298541068222);
    PowerUsageScenariosIntervalData& SetUptimeSeconds(int64_t value);

    static const char kURLVisibilityTimeSecondsName[];
    static constexpr uint64_t kURLVisibilityTimeSecondsNameHash = UINT64_C(18385055160424753010);
    PowerUsageScenariosIntervalData& SetURLVisibilityTimeSeconds(int64_t value);

    static const char kUserInteractionCountName[];
    static constexpr uint64_t kUserInteractionCountNameHash = UINT64_C(10973494702066475513);
    PowerUsageScenariosIntervalData& SetUserInteractionCount(int64_t value);

    static const char kVideoCaptureSecondsName[];
    static constexpr uint64_t kVideoCaptureSecondsNameHash = UINT64_C(5770286108963634075);
    PowerUsageScenariosIntervalData& SetVideoCaptureSeconds(int64_t value);
};

class PrefetchProxy final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PrefetchProxy(ukm::SourceId source_id);
    explicit PrefetchProxy(ukm::SourceIdObj source_id);
    PrefetchProxy(PrefetchProxy&&);
    PrefetchProxy& operator=(PrefetchProxy&&);
    ~PrefetchProxy() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11352241752715206016);

    static const char kdays_since_last_visit_to_originName[];
    static constexpr uint64_t kdays_since_last_visit_to_originNameHash = UINT64_C(210860424475155511);
    PrefetchProxy& Setdays_since_last_visit_to_origin(int64_t value);

    static const char kprefetch_attempted_countName[];
    static constexpr uint64_t kprefetch_attempted_countNameHash = UINT64_C(14009054735640351019);
    PrefetchProxy& Setprefetch_attempted_count(int64_t value);

    static const char kprefetch_eligible_countName[];
    static constexpr uint64_t kprefetch_eligible_countNameHash = UINT64_C(2248218164746653975);
    PrefetchProxy& Setprefetch_eligible_count(int64_t value);

    static const char kprefetch_successful_countName[];
    static constexpr uint64_t kprefetch_successful_countNameHash = UINT64_C(13378708688148375022);
    PrefetchProxy& Setprefetch_successful_count(int64_t value);
};

class PrefetchProxy_AfterSRPClick final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PrefetchProxy_AfterSRPClick(ukm::SourceId source_id);
    explicit PrefetchProxy_AfterSRPClick(ukm::SourceIdObj source_id);
    PrefetchProxy_AfterSRPClick(PrefetchProxy_AfterSRPClick&&);
    PrefetchProxy_AfterSRPClick& operator=(PrefetchProxy_AfterSRPClick&&);
    ~PrefetchProxy_AfterSRPClick() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6674705951757661648);

    static const char kClickedLinkSRPPositionName[];
    static constexpr uint64_t kClickedLinkSRPPositionNameHash = UINT64_C(6517804828846600668);
    PrefetchProxy_AfterSRPClick& SetClickedLinkSRPPosition(int64_t value);

    static const char kPrefetchHeaderLatencyMsName[];
    static constexpr uint64_t kPrefetchHeaderLatencyMsNameHash = UINT64_C(7529459795578638000);
    PrefetchProxy_AfterSRPClick& SetPrefetchHeaderLatencyMs(int64_t value);

    static const char kPrivatePrefetchName[];
    static constexpr uint64_t kPrivatePrefetchNameHash = UINT64_C(9145237687951559311);
    PrefetchProxy_AfterSRPClick& SetPrivatePrefetch(int64_t value);

    static const char kProbeLatencyMsName[];
    static constexpr uint64_t kProbeLatencyMsNameHash = UINT64_C(8004524944946139403);
    PrefetchProxy_AfterSRPClick& SetProbeLatencyMs(int64_t value);

    static const char kSameTabAsPrefetchingTabName[];
    static constexpr uint64_t kSameTabAsPrefetchingTabNameHash = UINT64_C(6352968288765198078);
    PrefetchProxy_AfterSRPClick& SetSameTabAsPrefetchingTab(int64_t value);

    static const char kSRPClickPrefetchStatusName[];
    static constexpr uint64_t kSRPClickPrefetchStatusNameHash = UINT64_C(7878335820719982043);
    PrefetchProxy_AfterSRPClick& SetSRPClickPrefetchStatus(int64_t value);

    static const char kSRPPrefetchEligibleCountName[];
    static constexpr uint64_t kSRPPrefetchEligibleCountNameHash = UINT64_C(12605281584920932061);
    PrefetchProxy_AfterSRPClick& SetSRPPrefetchEligibleCount(int64_t value);
};

class PrefetchProxy_PrefetchedResource final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PrefetchProxy_PrefetchedResource(ukm::SourceId source_id);
    explicit PrefetchProxy_PrefetchedResource(ukm::SourceIdObj source_id);
    PrefetchProxy_PrefetchedResource(PrefetchProxy_PrefetchedResource&&);
    PrefetchProxy_PrefetchedResource& operator=(PrefetchProxy_PrefetchedResource&&);
    ~PrefetchProxy_PrefetchedResource() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4145272093809115535);

    static const char kDataLengthName[];
    static constexpr uint64_t kDataLengthNameHash = UINT64_C(17089859510004165857);
    PrefetchProxy_PrefetchedResource& SetDataLength(int64_t value);

    static const char kFetchDurationMSName[];
    static constexpr uint64_t kFetchDurationMSNameHash = UINT64_C(4613084086861472268);
    PrefetchProxy_PrefetchedResource& SetFetchDurationMS(int64_t value);

    static const char kISPFilteringStatusName[];
    static constexpr uint64_t kISPFilteringStatusNameHash = UINT64_C(6757338012734431050);
    PrefetchProxy_PrefetchedResource& SetISPFilteringStatus(int64_t value);

    static const char kLinkClickedName[];
    static constexpr uint64_t kLinkClickedNameHash = UINT64_C(4362171511329748408);
    PrefetchProxy_PrefetchedResource& SetLinkClicked(int64_t value);

    static const char kLinkPositionName[];
    static constexpr uint64_t kLinkPositionNameHash = UINT64_C(3631041696461386974);
    PrefetchProxy_PrefetchedResource& SetLinkPosition(int64_t value);

    static const char kNavigationStartToFetchStartMSName[];
    static constexpr uint64_t kNavigationStartToFetchStartMSNameHash = UINT64_C(4817477453931099929);
    PrefetchProxy_PrefetchedResource& SetNavigationStartToFetchStartMS(int64_t value);

    static const char kResourceTypeName[];
    static constexpr uint64_t kResourceTypeNameHash = UINT64_C(13449604986098457094);
    PrefetchProxy_PrefetchedResource& SetResourceType(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    PrefetchProxy_PrefetchedResource& SetStatus(int64_t value);
};

class Preloading_Attempt final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Preloading_Attempt(ukm::SourceId source_id);
    explicit Preloading_Attempt(ukm::SourceIdObj source_id);
    Preloading_Attempt(Preloading_Attempt&&);
    Preloading_Attempt& operator=(Preloading_Attempt&&);
    ~Preloading_Attempt() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8746692042487350705);

    static const char kAccurateTriggeringName[];
    static constexpr uint64_t kAccurateTriggeringNameHash = UINT64_C(1619904085775979091);
    Preloading_Attempt& SetAccurateTriggering(int64_t value);

    static const char kEligibilityName[];
    static constexpr uint64_t kEligibilityNameHash = UINT64_C(12768698437797129924);
    Preloading_Attempt& SetEligibility(int64_t value);

    static const char kFailureReasonName[];
    static constexpr uint64_t kFailureReasonNameHash = UINT64_C(14882323251151056958);
    Preloading_Attempt& SetFailureReason(int64_t value);

    static const char kHoldbackStatusName[];
    static constexpr uint64_t kHoldbackStatusNameHash = UINT64_C(4412392211694608540);
    Preloading_Attempt& SetHoldbackStatus(int64_t value);

    static const char kPrefetchServiceWorkerRegisteredCheckName[];
    static constexpr uint64_t kPrefetchServiceWorkerRegisteredCheckNameHash = UINT64_C(228581178149260272);
    Preloading_Attempt& SetPrefetchServiceWorkerRegisteredCheck(int64_t value);

    static const char kPrefetchServiceWorkerRegisteredForURLCheckDurationName[];
    static constexpr uint64_t kPrefetchServiceWorkerRegisteredForURLCheckDurationNameHash = UINT64_C(11271871350121750196);
    Preloading_Attempt& SetPrefetchServiceWorkerRegisteredForURLCheckDuration(int64_t value);

    static const char kPreloadingPredictorName[];
    static constexpr uint64_t kPreloadingPredictorNameHash = UINT64_C(1456495145279962827);
    Preloading_Attempt& SetPreloadingPredictor(int64_t value);

    static const char kPreloadingTypeName[];
    static constexpr uint64_t kPreloadingTypeNameHash = UINT64_C(12008399334663561558);
    Preloading_Attempt& SetPreloadingType(int64_t value);

    static const char kReadyTimeName[];
    static constexpr uint64_t kReadyTimeNameHash = UINT64_C(8097704273938770758);
    Preloading_Attempt& SetReadyTime(int64_t value);

    static const char kSamplingLikelihoodName[];
    static constexpr uint64_t kSamplingLikelihoodNameHash = UINT64_C(1081593839225800700);
    Preloading_Attempt& SetSamplingLikelihood(int64_t value);

    static const char kSpeculationEagernessName[];
    static constexpr uint64_t kSpeculationEagernessNameHash = UINT64_C(13636186044555897900);
    Preloading_Attempt& SetSpeculationEagerness(int64_t value);

    static const char kTimeToNextNavigationName[];
    static constexpr uint64_t kTimeToNextNavigationNameHash = UINT64_C(10108968922612555273);
    Preloading_Attempt& SetTimeToNextNavigation(int64_t value);

    static const char kTriggeringOutcomeName[];
    static constexpr uint64_t kTriggeringOutcomeNameHash = UINT64_C(17699123771936181246);
    Preloading_Attempt& SetTriggeringOutcome(int64_t value);
};

class Preloading_Attempt_PreviousPrimaryPage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Preloading_Attempt_PreviousPrimaryPage(ukm::SourceId source_id);
    explicit Preloading_Attempt_PreviousPrimaryPage(ukm::SourceIdObj source_id);
    Preloading_Attempt_PreviousPrimaryPage(Preloading_Attempt_PreviousPrimaryPage&&);
    Preloading_Attempt_PreviousPrimaryPage& operator=(Preloading_Attempt_PreviousPrimaryPage&&);
    ~Preloading_Attempt_PreviousPrimaryPage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16426521927935131349);

    static const char kAccurateTriggeringName[];
    static constexpr uint64_t kAccurateTriggeringNameHash = UINT64_C(1619904085775979091);
    Preloading_Attempt_PreviousPrimaryPage& SetAccurateTriggering(int64_t value);

    static const char kEligibilityName[];
    static constexpr uint64_t kEligibilityNameHash = UINT64_C(12768698437797129924);
    Preloading_Attempt_PreviousPrimaryPage& SetEligibility(int64_t value);

    static const char kFailureReasonName[];
    static constexpr uint64_t kFailureReasonNameHash = UINT64_C(14882323251151056958);
    Preloading_Attempt_PreviousPrimaryPage& SetFailureReason(int64_t value);

    static const char kHoldbackStatusName[];
    static constexpr uint64_t kHoldbackStatusNameHash = UINT64_C(4412392211694608540);
    Preloading_Attempt_PreviousPrimaryPage& SetHoldbackStatus(int64_t value);

    static const char kPrefetchServiceWorkerRegisteredCheckName[];
    static constexpr uint64_t kPrefetchServiceWorkerRegisteredCheckNameHash = UINT64_C(228581178149260272);
    Preloading_Attempt_PreviousPrimaryPage& SetPrefetchServiceWorkerRegisteredCheck(int64_t value);

    static const char kPrefetchServiceWorkerRegisteredForURLCheckDurationName[];
    static constexpr uint64_t kPrefetchServiceWorkerRegisteredForURLCheckDurationNameHash = UINT64_C(11271871350121750196);
    Preloading_Attempt_PreviousPrimaryPage& SetPrefetchServiceWorkerRegisteredForURLCheckDuration(int64_t value);

    static const char kPreloadingPredictorName[];
    static constexpr uint64_t kPreloadingPredictorNameHash = UINT64_C(1456495145279962827);
    Preloading_Attempt_PreviousPrimaryPage& SetPreloadingPredictor(int64_t value);

    static const char kPreloadingTypeName[];
    static constexpr uint64_t kPreloadingTypeNameHash = UINT64_C(12008399334663561558);
    Preloading_Attempt_PreviousPrimaryPage& SetPreloadingType(int64_t value);

    static const char kReadyTimeName[];
    static constexpr uint64_t kReadyTimeNameHash = UINT64_C(8097704273938770758);
    Preloading_Attempt_PreviousPrimaryPage& SetReadyTime(int64_t value);

    static const char kSamplingLikelihoodName[];
    static constexpr uint64_t kSamplingLikelihoodNameHash = UINT64_C(1081593839225800700);
    Preloading_Attempt_PreviousPrimaryPage& SetSamplingLikelihood(int64_t value);

    static const char kSpeculationEagernessName[];
    static constexpr uint64_t kSpeculationEagernessNameHash = UINT64_C(13636186044555897900);
    Preloading_Attempt_PreviousPrimaryPage& SetSpeculationEagerness(int64_t value);

    static const char kTimeToNextNavigationName[];
    static constexpr uint64_t kTimeToNextNavigationNameHash = UINT64_C(10108968922612555273);
    Preloading_Attempt_PreviousPrimaryPage& SetTimeToNextNavigation(int64_t value);

    static const char kTriggeringOutcomeName[];
    static constexpr uint64_t kTriggeringOutcomeNameHash = UINT64_C(17699123771936181246);
    Preloading_Attempt_PreviousPrimaryPage& SetTriggeringOutcome(int64_t value);
};

class Preloading_NavigationPredictorModelTrainingData final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Preloading_NavigationPredictorModelTrainingData(ukm::SourceId source_id);
    explicit Preloading_NavigationPredictorModelTrainingData(ukm::SourceIdObj source_id);
    Preloading_NavigationPredictorModelTrainingData(Preloading_NavigationPredictorModelTrainingData&&);
    Preloading_NavigationPredictorModelTrainingData& operator=(Preloading_NavigationPredictorModelTrainingData&&);
    ~Preloading_NavigationPredictorModelTrainingData() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14634695338976802777);

    static const char kContainsImageName[];
    static constexpr uint64_t kContainsImageNameHash = UINT64_C(16441638965853255360);
    Preloading_NavigationPredictorModelTrainingData& SetContainsImage(int64_t value);

    static const char kFontSizeName[];
    static constexpr uint64_t kFontSizeNameHash = UINT64_C(2643658496925572245);
    Preloading_NavigationPredictorModelTrainingData& SetFontSize(int64_t value);

    static const char kHasTextSiblingName[];
    static constexpr uint64_t kHasTextSiblingNameHash = UINT64_C(5766907595008553355);
    Preloading_NavigationPredictorModelTrainingData& SetHasTextSibling(int64_t value);

    static const char kHoverDwellTimeMsName[];
    static constexpr uint64_t kHoverDwellTimeMsNameHash = UINT64_C(863795883123695262);
    Preloading_NavigationPredictorModelTrainingData& SetHoverDwellTimeMs(int64_t value);

    static const char kIsAccurateName[];
    static constexpr uint64_t kIsAccurateNameHash = UINT64_C(10891048041305501042);
    Preloading_NavigationPredictorModelTrainingData& SetIsAccurate(int64_t value);

    static const char kIsBoldName[];
    static constexpr uint64_t kIsBoldNameHash = UINT64_C(4144648385448633082);
    Preloading_NavigationPredictorModelTrainingData& SetIsBold(int64_t value);

    static const char kIsInIframeName[];
    static constexpr uint64_t kIsInIframeNameHash = UINT64_C(2879927029285282397);
    Preloading_NavigationPredictorModelTrainingData& SetIsInIframe(int64_t value);

    static const char kIsURLIncrementedByOneName[];
    static constexpr uint64_t kIsURLIncrementedByOneNameHash = UINT64_C(3472078046519927012);
    Preloading_NavigationPredictorModelTrainingData& SetIsURLIncrementedByOne(int64_t value);

    static const char kNavigationStartToLinkLoggedMsName[];
    static constexpr uint64_t kNavigationStartToLinkLoggedMsNameHash = UINT64_C(2339728805912802951);
    Preloading_NavigationPredictorModelTrainingData& SetNavigationStartToLinkLoggedMs(int64_t value);

    static const char kPathDepthName[];
    static constexpr uint64_t kPathDepthNameHash = UINT64_C(5175545670794720336);
    Preloading_NavigationPredictorModelTrainingData& SetPathDepth(int64_t value);

    static const char kPathLengthName[];
    static constexpr uint64_t kPathLengthNameHash = UINT64_C(1889323937569217530);
    Preloading_NavigationPredictorModelTrainingData& SetPathLength(int64_t value);

    static const char kPercentClickableAreaName[];
    static constexpr uint64_t kPercentClickableAreaNameHash = UINT64_C(12162500925069527559);
    Preloading_NavigationPredictorModelTrainingData& SetPercentClickableArea(int64_t value);

    static const char kPercentVerticalDistanceName[];
    static constexpr uint64_t kPercentVerticalDistanceNameHash = UINT64_C(14979657413195163456);
    Preloading_NavigationPredictorModelTrainingData& SetPercentVerticalDistance(int64_t value);

    static const char kPointerHoveringOverCountName[];
    static constexpr uint64_t kPointerHoveringOverCountNameHash = UINT64_C(5127996080152514538);
    Preloading_NavigationPredictorModelTrainingData& SetPointerHoveringOverCount(int64_t value);

    static const char kSameHostName[];
    static constexpr uint64_t kSameHostNameHash = UINT64_C(3683745955195564140);
    Preloading_NavigationPredictorModelTrainingData& SetSameHost(int64_t value);

    static const char kSamplingAmountName[];
    static constexpr uint64_t kSamplingAmountNameHash = UINT64_C(18238717572454932630);
    Preloading_NavigationPredictorModelTrainingData& SetSamplingAmount(int64_t value);
};

class Preloading_Prediction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Preloading_Prediction(ukm::SourceId source_id);
    explicit Preloading_Prediction(ukm::SourceIdObj source_id);
    Preloading_Prediction(Preloading_Prediction&&);
    Preloading_Prediction& operator=(Preloading_Prediction&&);
    ~Preloading_Prediction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7178389144071274549);

    static const char kAccuratePredictionName[];
    static constexpr uint64_t kAccuratePredictionNameHash = UINT64_C(9680925763323292340);
    Preloading_Prediction& SetAccuratePrediction(int64_t value);

    static const char kConfidenceName[];
    static constexpr uint64_t kConfidenceNameHash = UINT64_C(9803856876126306660);
    Preloading_Prediction& SetConfidence(int64_t value);

    static const char kPreloadingPredictorName[];
    static constexpr uint64_t kPreloadingPredictorNameHash = UINT64_C(1456495145279962827);
    Preloading_Prediction& SetPreloadingPredictor(int64_t value);

    static const char kSamplingAmountName[];
    static constexpr uint64_t kSamplingAmountNameHash = UINT64_C(18238717572454932630);
    Preloading_Prediction& SetSamplingAmount(int64_t value);

    static const char kTimeToNextNavigationName[];
    static constexpr uint64_t kTimeToNextNavigationNameHash = UINT64_C(10108968922612555273);
    Preloading_Prediction& SetTimeToNextNavigation(int64_t value);
};

class Preloading_Prediction_PreviousPrimaryPage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Preloading_Prediction_PreviousPrimaryPage(ukm::SourceId source_id);
    explicit Preloading_Prediction_PreviousPrimaryPage(ukm::SourceIdObj source_id);
    Preloading_Prediction_PreviousPrimaryPage(Preloading_Prediction_PreviousPrimaryPage&&);
    Preloading_Prediction_PreviousPrimaryPage& operator=(Preloading_Prediction_PreviousPrimaryPage&&);
    ~Preloading_Prediction_PreviousPrimaryPage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5667944672124880130);

    static const char kAccuratePredictionName[];
    static constexpr uint64_t kAccuratePredictionNameHash = UINT64_C(9680925763323292340);
    Preloading_Prediction_PreviousPrimaryPage& SetAccuratePrediction(int64_t value);

    static const char kConfidenceName[];
    static constexpr uint64_t kConfidenceNameHash = UINT64_C(9803856876126306660);
    Preloading_Prediction_PreviousPrimaryPage& SetConfidence(int64_t value);

    static const char kPreloadingPredictorName[];
    static constexpr uint64_t kPreloadingPredictorNameHash = UINT64_C(1456495145279962827);
    Preloading_Prediction_PreviousPrimaryPage& SetPreloadingPredictor(int64_t value);

    static const char kSamplingAmountName[];
    static constexpr uint64_t kSamplingAmountNameHash = UINT64_C(18238717572454932630);
    Preloading_Prediction_PreviousPrimaryPage& SetSamplingAmount(int64_t value);

    static const char kTimeToNextNavigationName[];
    static constexpr uint64_t kTimeToNextNavigationNameHash = UINT64_C(10108968922612555273);
    Preloading_Prediction_PreviousPrimaryPage& SetTimeToNextNavigation(int64_t value);
};

class PrerenderPageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PrerenderPageLoad(ukm::SourceId source_id);
    explicit PrerenderPageLoad(ukm::SourceIdObj source_id);
    PrerenderPageLoad(PrerenderPageLoad&&);
    PrerenderPageLoad& operator=(PrerenderPageLoad&&);
    ~PrerenderPageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14500319117729505239);

    static const char kFinalStatusName[];
    static constexpr uint64_t kFinalStatusNameHash = UINT64_C(8077396098933579486);
    PrerenderPageLoad& SetFinalStatus(int64_t value);

    static const char kInteractiveTiming_FirstInputDelay4Name[];
    static constexpr uint64_t kInteractiveTiming_FirstInputDelay4NameHash = UINT64_C(6127468907094730300);
    PrerenderPageLoad& SetInteractiveTiming_FirstInputDelay4(int64_t value);

    static const char kInteractiveTiming_NumInteractionsName[];
    static constexpr uint64_t kInteractiveTiming_NumInteractionsNameHash = UINT64_C(11809849059952828483);
    PrerenderPageLoad& SetInteractiveTiming_NumInteractions(int64_t value);

    static const char kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash = UINT64_C(10840313540306654437);
    PrerenderPageLoad& SetInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash = UINT64_C(3538217577346865260);
    PrerenderPageLoad& SetInteractiveTiming_WorstUserInteractionLatency_MaxEventDuration(int64_t value);

    static const char kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash = UINT64_C(10830469890257014133);
    PrerenderPageLoad& SetLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kMainFrameResource_RequestHasNoStoreName[];
    static constexpr uint64_t kMainFrameResource_RequestHasNoStoreNameHash = UINT64_C(11828995768390638002);
    PrerenderPageLoad& SetMainFrameResource_RequestHasNoStore(int64_t value);

    static const char kNavigation_InitiatorLocationName[];
    static constexpr uint64_t kNavigation_InitiatorLocationNameHash = UINT64_C(347990406346941426);
    PrerenderPageLoad& SetNavigation_InitiatorLocation(int64_t value);

    static const char kNavigation_PageTransitionName[];
    static constexpr uint64_t kNavigation_PageTransitionNameHash = UINT64_C(6618380684727568744);
    PrerenderPageLoad& SetNavigation_PageTransition(int64_t value);

    static const char kTiming_ActivationToFirstContentfulPaintName[];
    static constexpr uint64_t kTiming_ActivationToFirstContentfulPaintNameHash = UINT64_C(15539767333070983492);
    PrerenderPageLoad& SetTiming_ActivationToFirstContentfulPaint(int64_t value);

    static const char kTiming_ActivationToLargestContentfulPaintName[];
    static constexpr uint64_t kTiming_ActivationToLargestContentfulPaintNameHash = UINT64_C(14668565134136948861);
    PrerenderPageLoad& SetTiming_ActivationToLargestContentfulPaint(int64_t value);

    static const char kTiming_NavigationToActivationName[];
    static constexpr uint64_t kTiming_NavigationToActivationNameHash = UINT64_C(3846892965964002953);
    PrerenderPageLoad& SetTiming_NavigationToActivation(int64_t value);

    static const char kTriggeredPrerenderName[];
    static constexpr uint64_t kTriggeredPrerenderNameHash = UINT64_C(16004989971744195420);
    PrerenderPageLoad& SetTriggeredPrerender(int64_t value);

    static const char kWasPrerenderedName[];
    static constexpr uint64_t kWasPrerenderedNameHash = UINT64_C(11597662649033373562);
    PrerenderPageLoad& SetWasPrerendered(int64_t value);
};

class Presentation_StartResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Presentation_StartResult(ukm::SourceId source_id);
    explicit Presentation_StartResult(ukm::SourceIdObj source_id);
    Presentation_StartResult(Presentation_StartResult&&);
    Presentation_StartResult& operator=(Presentation_StartResult&&);
    ~Presentation_StartResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2441679537758985212);

    static const char kPresentationRequestName[];
    static constexpr uint64_t kPresentationRequestNameHash = UINT64_C(18430899178156992992);
    Presentation_StartResult& SetPresentationRequest(int64_t value);

    static const char kRemotePlaybackName[];
    static constexpr uint64_t kRemotePlaybackNameHash = UINT64_C(9916818522785584308);
    Presentation_StartResult& SetRemotePlayback(int64_t value);
};

class PWA_Visit final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit PWA_Visit(ukm::SourceId source_id);
    explicit PWA_Visit(ukm::SourceIdObj source_id);
    PWA_Visit(PWA_Visit&&);
    PWA_Visit& operator=(PWA_Visit&&);
    ~PWA_Visit() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4791378639615025150);

    static const char kLaunchSourceName[];
    static constexpr uint64_t kLaunchSourceNameHash = UINT64_C(5360095524695749322);
    PWA_Visit& SetLaunchSource(int64_t value);

    static const char kWebAPKableSiteVisitName[];
    static constexpr uint64_t kWebAPKableSiteVisitNameHash = UINT64_C(4362561697839438819);
    PWA_Visit& SetWebAPKableSiteVisit(int64_t value);
};

class RedirectHeuristic_CookieAccess2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit RedirectHeuristic_CookieAccess2(ukm::SourceId source_id);
    explicit RedirectHeuristic_CookieAccess2(ukm::SourceIdObj source_id);
    RedirectHeuristic_CookieAccess2(RedirectHeuristic_CookieAccess2&&);
    RedirectHeuristic_CookieAccess2& operator=(RedirectHeuristic_CookieAccess2&&);
    ~RedirectHeuristic_CookieAccess2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8023001203190348723);

    static const char kAccessAllowedName[];
    static constexpr uint64_t kAccessAllowedNameHash = UINT64_C(5230817163541053033);
    RedirectHeuristic_CookieAccess2& SetAccessAllowed(int64_t value);

    static const char kAccessIdName[];
    static constexpr uint64_t kAccessIdNameHash = UINT64_C(11155306466381838703);
    RedirectHeuristic_CookieAccess2& SetAccessId(int64_t value);

    static const char kDoesFirstPartyPrecedeThirdPartyName[];
    static constexpr uint64_t kDoesFirstPartyPrecedeThirdPartyNameHash = UINT64_C(17075433554235073639);
    RedirectHeuristic_CookieAccess2& SetDoesFirstPartyPrecedeThirdParty(int64_t value);

    static const char kHoursSinceLastInteractionName[];
    static constexpr uint64_t kHoursSinceLastInteractionNameHash = UINT64_C(4087224455125447084);
    RedirectHeuristic_CookieAccess2& SetHoursSinceLastInteraction(int64_t value);

    static const char kIsAdTaggedName[];
    static constexpr uint64_t kIsAdTaggedNameHash = UINT64_C(17196529301178612283);
    RedirectHeuristic_CookieAccess2& SetIsAdTagged(int64_t value);

    static const char kIsCurrentInteractionName[];
    static constexpr uint64_t kIsCurrentInteractionNameHash = UINT64_C(6246595677990719651);
    RedirectHeuristic_CookieAccess2& SetIsCurrentInteraction(int64_t value);

    static const char kMillisecondsSinceRedirectName[];
    static constexpr uint64_t kMillisecondsSinceRedirectNameHash = UINT64_C(14118449343310029104);
    RedirectHeuristic_CookieAccess2& SetMillisecondsSinceRedirect(int64_t value);

    static const char kOpenerHasSameSiteIframeName[];
    static constexpr uint64_t kOpenerHasSameSiteIframeNameHash = UINT64_C(15547075772128086806);
    RedirectHeuristic_CookieAccess2& SetOpenerHasSameSiteIframe(int64_t value);

    static const char kSitesPassedCountName[];
    static constexpr uint64_t kSitesPassedCountNameHash = UINT64_C(13099792485070626280);
    RedirectHeuristic_CookieAccess2& SetSitesPassedCount(int64_t value);
};

class RedirectHeuristic_CookieAccessThirdParty2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit RedirectHeuristic_CookieAccessThirdParty2(ukm::SourceId source_id);
    explicit RedirectHeuristic_CookieAccessThirdParty2(ukm::SourceIdObj source_id);
    RedirectHeuristic_CookieAccessThirdParty2(RedirectHeuristic_CookieAccessThirdParty2&&);
    RedirectHeuristic_CookieAccessThirdParty2& operator=(RedirectHeuristic_CookieAccessThirdParty2&&);
    ~RedirectHeuristic_CookieAccessThirdParty2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9485711265083453457);

    static const char kAccessIdName[];
    static constexpr uint64_t kAccessIdNameHash = UINT64_C(11155306466381838703);
    RedirectHeuristic_CookieAccessThirdParty2& SetAccessId(int64_t value);
};

class RendererSchedulerTask final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit RendererSchedulerTask(ukm::SourceId source_id);
    explicit RendererSchedulerTask(ukm::SourceIdObj source_id);
    RendererSchedulerTask(RendererSchedulerTask&&);
    RendererSchedulerTask& operator=(RendererSchedulerTask&&);
    ~RendererSchedulerTask() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(18249372845339521807);

    static const char kFrameStatusName[];
    static constexpr uint64_t kFrameStatusNameHash = UINT64_C(8127006928817986898);
    RendererSchedulerTask& SetFrameStatus(int64_t value);

    static const char kIsOOPIFName[];
    static constexpr uint64_t kIsOOPIFNameHash = UINT64_C(4026879053974581447);
    RendererSchedulerTask& SetIsOOPIF(int64_t value);

    static const char kPageSchedulersName[];
    static constexpr uint64_t kPageSchedulersNameHash = UINT64_C(11770126887694907943);
    RendererSchedulerTask& SetPageSchedulers(int64_t value);

    static const char kQueueTypeName[];
    static constexpr uint64_t kQueueTypeNameHash = UINT64_C(11208877159905152236);
    RendererSchedulerTask& SetQueueType(int64_t value);

    static const char kRendererAudibleName[];
    static constexpr uint64_t kRendererAudibleNameHash = UINT64_C(4748648681023634603);
    RendererSchedulerTask& SetRendererAudible(int64_t value);

    static const char kRendererBackgroundedName[];
    static constexpr uint64_t kRendererBackgroundedNameHash = UINT64_C(7540850391372337744);
    RendererSchedulerTask& SetRendererBackgrounded(int64_t value);

    static const char kRendererHiddenName[];
    static constexpr uint64_t kRendererHiddenNameHash = UINT64_C(4143722852895683235);
    RendererSchedulerTask& SetRendererHidden(int64_t value);

    static const char kSecondsSinceBackgroundedName[];
    static constexpr uint64_t kSecondsSinceBackgroundedNameHash = UINT64_C(11822329391758215615);
    RendererSchedulerTask& SetSecondsSinceBackgrounded(int64_t value);

    static const char kTaskCPUDurationName[];
    static constexpr uint64_t kTaskCPUDurationNameHash = UINT64_C(16455678090173301579);
    RendererSchedulerTask& SetTaskCPUDuration(int64_t value);

    static const char kTaskDurationName[];
    static constexpr uint64_t kTaskDurationNameHash = UINT64_C(3339793303415972546);
    RendererSchedulerTask& SetTaskDuration(int64_t value);

    static const char kTaskTypeName[];
    static constexpr uint64_t kTaskTypeNameHash = UINT64_C(12639142331433684509);
    RendererSchedulerTask& SetTaskType(int64_t value);

    static const char kThreadTypeName[];
    static constexpr uint64_t kThreadTypeNameHash = UINT64_C(16336169703352190142);
    RendererSchedulerTask& SetThreadType(int64_t value);

    static const char kUseCaseName[];
    static constexpr uint64_t kUseCaseNameHash = UINT64_C(10388051568539810908);
    RendererSchedulerTask& SetUseCase(int64_t value);

    static const char kVersionName[];
    static constexpr uint64_t kVersionNameHash = UINT64_C(3798449238516105146);
    RendererSchedulerTask& SetVersion(int64_t value);
};

class RenderViewContextMenu_Used final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit RenderViewContextMenu_Used(ukm::SourceId source_id);
    explicit RenderViewContextMenu_Used(ukm::SourceIdObj source_id);
    RenderViewContextMenu_Used(RenderViewContextMenu_Used&&);
    RenderViewContextMenu_Used& operator=(RenderViewContextMenu_Used&&);
    ~RenderViewContextMenu_Used() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14554281962363859401);

    static const char kSelectedMenuItemName[];
    static constexpr uint64_t kSelectedMenuItemNameHash = UINT64_C(17538581749235128283);
    RenderViewContextMenu_Used& SetSelectedMenuItem(int64_t value);
};

class RequestStorageAccessFor_RequestStorageResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit RequestStorageAccessFor_RequestStorageResult(ukm::SourceId source_id);
    explicit RequestStorageAccessFor_RequestStorageResult(ukm::SourceIdObj source_id);
    RequestStorageAccessFor_RequestStorageResult(RequestStorageAccessFor_RequestStorageResult&&);
    RequestStorageAccessFor_RequestStorageResult& operator=(RequestStorageAccessFor_RequestStorageResult&&);
    ~RequestStorageAccessFor_RequestStorageResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12682518437722483590);

    static const char kRequestStorageResultName[];
    static constexpr uint64_t kRequestStorageResultNameHash = UINT64_C(6085400302835551000);
    RequestStorageAccessFor_RequestStorageResult& SetRequestStorageResult(int64_t value);
};

class Responsiveness_UserInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Responsiveness_UserInteraction(ukm::SourceId source_id);
    explicit Responsiveness_UserInteraction(ukm::SourceIdObj source_id);
    Responsiveness_UserInteraction(Responsiveness_UserInteraction&&);
    Responsiveness_UserInteraction& operator=(Responsiveness_UserInteraction&&);
    ~Responsiveness_UserInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8390839146308016474);

    static const char kInteractionTypeName[];
    static constexpr uint64_t kInteractionTypeNameHash = UINT64_C(16697911661848345718);
    Responsiveness_UserInteraction& SetInteractionType(int64_t value);

    static const char kMaxEventDurationName[];
    static constexpr uint64_t kMaxEventDurationNameHash = UINT64_C(11189466165853570636);
    Responsiveness_UserInteraction& SetMaxEventDuration(int64_t value);

    static const char kTotalEventDurationName[];
    static constexpr uint64_t kTotalEventDurationNameHash = UINT64_C(9942285188121028777);
    Responsiveness_UserInteraction& SetTotalEventDuration(int64_t value);
};

class ResponsivenessMeasurement final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ResponsivenessMeasurement(ukm::SourceId source_id);
    explicit ResponsivenessMeasurement(ukm::SourceIdObj source_id);
    ResponsivenessMeasurement(ResponsivenessMeasurement&&);
    ResponsivenessMeasurement& operator=(ResponsivenessMeasurement&&);
    ~ResponsivenessMeasurement() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6628044799783508745);
};

class SafeBrowsingInterstitial final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SafeBrowsingInterstitial(ukm::SourceId source_id);
    explicit SafeBrowsingInterstitial(ukm::SourceIdObj source_id);
    SafeBrowsingInterstitial(SafeBrowsingInterstitial&&);
    SafeBrowsingInterstitial& operator=(SafeBrowsingInterstitial&&);
    ~SafeBrowsingInterstitial() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8193059715620786465);

    static const char kBypassedName[];
    static constexpr uint64_t kBypassedNameHash = UINT64_C(7467790098215268648);
    SafeBrowsingInterstitial& SetBypassed(int64_t value);

    static const char kShownName[];
    static constexpr uint64_t kShownNameHash = UINT64_C(11642401927465122037);
    SafeBrowsingInterstitial& SetShown(int64_t value);
};

class SalientImageAvailability final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SalientImageAvailability(ukm::SourceId source_id);
    explicit SalientImageAvailability(ukm::SourceIdObj source_id);
    SalientImageAvailability(SalientImageAvailability&&);
    SalientImageAvailability& operator=(SalientImageAvailability&&);
    ~SalientImageAvailability() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8255360323456312283);

    static const char kImageAvailabilityName[];
    static constexpr uint64_t kImageAvailabilityNameHash = UINT64_C(13066827509986025981);
    SalientImageAvailability& SetImageAvailability(int64_t value);
};

class SameSiteDifferentSchemeRequest final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SameSiteDifferentSchemeRequest(ukm::SourceId source_id);
    explicit SameSiteDifferentSchemeRequest(ukm::SourceIdObj source_id);
    SameSiteDifferentSchemeRequest(SameSiteDifferentSchemeRequest&&);
    SameSiteDifferentSchemeRequest& operator=(SameSiteDifferentSchemeRequest&&);
    ~SameSiteDifferentSchemeRequest() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14016795862258924641);
};

class SameSiteDifferentSchemeResponse final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SameSiteDifferentSchemeResponse(ukm::SourceId source_id);
    explicit SameSiteDifferentSchemeResponse(ukm::SourceIdObj source_id);
    SameSiteDifferentSchemeResponse(SameSiteDifferentSchemeResponse&&);
    SameSiteDifferentSchemeResponse& operator=(SameSiteDifferentSchemeResponse&&);
    ~SameSiteDifferentSchemeResponse() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6057282574508536454);
};

class SamesiteRedirectContextDowngrade final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SamesiteRedirectContextDowngrade(ukm::SourceId source_id);
    explicit SamesiteRedirectContextDowngrade(ukm::SourceIdObj source_id);
    SamesiteRedirectContextDowngrade(SamesiteRedirectContextDowngrade&&);
    SamesiteRedirectContextDowngrade& operator=(SamesiteRedirectContextDowngrade&&);
    ~SamesiteRedirectContextDowngrade() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3590891381445194196);

    static const char kAgePerCookieName[];
    static constexpr uint64_t kAgePerCookieNameHash = UINT64_C(5865493410444432378);
    SamesiteRedirectContextDowngrade& SetAgePerCookie(int64_t value);

    static const char kSamesiteValueReadPerCookieName[];
    static constexpr uint64_t kSamesiteValueReadPerCookieNameHash = UINT64_C(17680638188685646682);
    SamesiteRedirectContextDowngrade& SetSamesiteValueReadPerCookie(int64_t value);

    static const char kSamesiteValueWritePerCookieName[];
    static constexpr uint64_t kSamesiteValueWritePerCookieNameHash = UINT64_C(14837397327467396123);
    SamesiteRedirectContextDowngrade& SetSamesiteValueWritePerCookie(int64_t value);
};

class SavedTabGroup_Navigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SavedTabGroup_Navigation(ukm::SourceId source_id);
    explicit SavedTabGroup_Navigation(ukm::SourceIdObj source_id);
    SavedTabGroup_Navigation(SavedTabGroup_Navigation&&);
    SavedTabGroup_Navigation& operator=(SavedTabGroup_Navigation&&);
    ~SavedTabGroup_Navigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13143810872110815515);

    static const char kIsPostName[];
    static constexpr uint64_t kIsPostNameHash = UINT64_C(15067372049938987455);
    SavedTabGroup_Navigation& SetIsPost(int64_t value);

    static const char kNumSameUrlLoadName[];
    static constexpr uint64_t kNumSameUrlLoadNameHash = UINT64_C(11385907180792143591);
    SavedTabGroup_Navigation& SetNumSameUrlLoad(int64_t value);

    static const char kNumSameUrlWithoutRefAndQueryParamLoadName[];
    static constexpr uint64_t kNumSameUrlWithoutRefAndQueryParamLoadNameHash = UINT64_C(1763504226750254426);
    SavedTabGroup_Navigation& SetNumSameUrlWithoutRefAndQueryParamLoad(int64_t value);

    static const char kTabGroupTypeName[];
    static constexpr uint64_t kTabGroupTypeNameHash = UINT64_C(13751400130918985812);
    SavedTabGroup_Navigation& SetTabGroupType(int64_t value);

    static const char kWasRedirectedName[];
    static constexpr uint64_t kWasRedirectedNameHash = UINT64_C(11478487047991331859);
    SavedTabGroup_Navigation& SetWasRedirected(int64_t value);
};

class SchemefulSameSiteContextDowngrade final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SchemefulSameSiteContextDowngrade(ukm::SourceId source_id);
    explicit SchemefulSameSiteContextDowngrade(ukm::SourceIdObj source_id);
    SchemefulSameSiteContextDowngrade(SchemefulSameSiteContextDowngrade&&);
    SchemefulSameSiteContextDowngrade& operator=(SchemefulSameSiteContextDowngrade&&);
    ~SchemefulSameSiteContextDowngrade() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16392896102401488447);

    static const char kRequestPerCookieName[];
    static constexpr uint64_t kRequestPerCookieNameHash = UINT64_C(2434445133551336228);
    SchemefulSameSiteContextDowngrade& SetRequestPerCookie(int64_t value);

    static const char kResponsePerCookieName[];
    static constexpr uint64_t kResponsePerCookieNameHash = UINT64_C(5214101366751624340);
    SchemefulSameSiteContextDowngrade& SetResponsePerCookie(int64_t value);
};

class ScreenBrightness final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ScreenBrightness(ukm::SourceId source_id);
    explicit ScreenBrightness(ukm::SourceIdObj source_id);
    ScreenBrightness(ScreenBrightness&&);
    ScreenBrightness& operator=(ScreenBrightness&&);
    ~ScreenBrightness() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17111718181803892778);

    static const char kBatteryPercentName[];
    static constexpr uint64_t kBatteryPercentNameHash = UINT64_C(3434325767059222004);
    ScreenBrightness& SetBatteryPercent(int64_t value);

    static const char kBrightnessName[];
    static constexpr uint64_t kBrightnessNameHash = UINT64_C(12849653716714311268);
    ScreenBrightness& SetBrightness(int64_t value);

    static const char kDayOfWeekName[];
    static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
    ScreenBrightness& SetDayOfWeek(int64_t value);

    static const char kDeviceModeName[];
    static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
    ScreenBrightness& SetDeviceMode(int64_t value);

    static const char kHourOfDayName[];
    static constexpr uint64_t kHourOfDayNameHash = UINT64_C(7458652416968136217);
    ScreenBrightness& SetHourOfDay(int64_t value);

    static const char kIsAutoclickEnabledName[];
    static constexpr uint64_t kIsAutoclickEnabledNameHash = UINT64_C(12085477661763404958);
    ScreenBrightness& SetIsAutoclickEnabled(int64_t value);

    static const char kIsBrailleDisplayConnectedName[];
    static constexpr uint64_t kIsBrailleDisplayConnectedNameHash = UINT64_C(17405292260030448849);
    ScreenBrightness& SetIsBrailleDisplayConnected(int64_t value);

    static const char kIsCaretHighlightEnabledName[];
    static constexpr uint64_t kIsCaretHighlightEnabledNameHash = UINT64_C(10482296846968056654);
    ScreenBrightness& SetIsCaretHighlightEnabled(int64_t value);

    static const char kIsCursorHighlightEnabledName[];
    static constexpr uint64_t kIsCursorHighlightEnabledNameHash = UINT64_C(2111688606646287289);
    ScreenBrightness& SetIsCursorHighlightEnabled(int64_t value);

    static const char kIsFocusHighlightEnabledName[];
    static constexpr uint64_t kIsFocusHighlightEnabledNameHash = UINT64_C(4772586800047270064);
    ScreenBrightness& SetIsFocusHighlightEnabled(int64_t value);

    static const char kIsHighContrastEnabledName[];
    static constexpr uint64_t kIsHighContrastEnabledNameHash = UINT64_C(374822690988321958);
    ScreenBrightness& SetIsHighContrastEnabled(int64_t value);

    static const char kIsLargeCursorEnabledName[];
    static constexpr uint64_t kIsLargeCursorEnabledNameHash = UINT64_C(1440663063306295171);
    ScreenBrightness& SetIsLargeCursorEnabled(int64_t value);

    static const char kIsMagnifierEnabledName[];
    static constexpr uint64_t kIsMagnifierEnabledNameHash = UINT64_C(6711936056248658535);
    ScreenBrightness& SetIsMagnifierEnabled(int64_t value);

    static const char kIsMonoAudioEnabledName[];
    static constexpr uint64_t kIsMonoAudioEnabledNameHash = UINT64_C(11595411019290590600);
    ScreenBrightness& SetIsMonoAudioEnabled(int64_t value);

    static const char kIsSelectToSpeakEnabledName[];
    static constexpr uint64_t kIsSelectToSpeakEnabledNameHash = UINT64_C(4363348572679012907);
    ScreenBrightness& SetIsSelectToSpeakEnabled(int64_t value);

    static const char kIsSpokenFeedbackEnabledName[];
    static constexpr uint64_t kIsSpokenFeedbackEnabledNameHash = UINT64_C(6400938228896171943);
    ScreenBrightness& SetIsSpokenFeedbackEnabled(int64_t value);

    static const char kIsSwitchAccessEnabledName[];
    static constexpr uint64_t kIsSwitchAccessEnabledNameHash = UINT64_C(1769366891414824383);
    ScreenBrightness& SetIsSwitchAccessEnabled(int64_t value);

    static const char kIsVideoPlayingName[];
    static constexpr uint64_t kIsVideoPlayingNameHash = UINT64_C(1871421023467865761);
    ScreenBrightness& SetIsVideoPlaying(int64_t value);

    static const char kIsVirtualKeyboardEnabledName[];
    static constexpr uint64_t kIsVirtualKeyboardEnabledNameHash = UINT64_C(16129358140694558991);
    ScreenBrightness& SetIsVirtualKeyboardEnabled(int64_t value);

    static const char kLastActivityTimeSecName[];
    static constexpr uint64_t kLastActivityTimeSecNameHash = UINT64_C(2653130242002900914);
    ScreenBrightness& SetLastActivityTimeSec(int64_t value);

    static const char kNightLightTemperaturePercentName[];
    static constexpr uint64_t kNightLightTemperaturePercentNameHash = UINT64_C(10702391938559175141);
    ScreenBrightness& SetNightLightTemperaturePercent(int64_t value);

    static const char kNumRecentKeyEventsName[];
    static constexpr uint64_t kNumRecentKeyEventsNameHash = UINT64_C(17517294973322255376);
    ScreenBrightness& SetNumRecentKeyEvents(int64_t value);

    static const char kNumRecentMouseEventsName[];
    static constexpr uint64_t kNumRecentMouseEventsNameHash = UINT64_C(6164169136009494499);
    ScreenBrightness& SetNumRecentMouseEvents(int64_t value);

    static const char kNumRecentStylusEventsName[];
    static constexpr uint64_t kNumRecentStylusEventsNameHash = UINT64_C(13185006921548112034);
    ScreenBrightness& SetNumRecentStylusEvents(int64_t value);

    static const char kNumRecentTouchEventsName[];
    static constexpr uint64_t kNumRecentTouchEventsNameHash = UINT64_C(14067961327568630776);
    ScreenBrightness& SetNumRecentTouchEvents(int64_t value);

    static const char kOnBatteryName[];
    static constexpr uint64_t kOnBatteryNameHash = UINT64_C(9497943841916154435);
    ScreenBrightness& SetOnBattery(int64_t value);

    static const char kPreviousBrightnessName[];
    static constexpr uint64_t kPreviousBrightnessNameHash = UINT64_C(28161076988593854);
    ScreenBrightness& SetPreviousBrightness(int64_t value);

    static const char kReasonName[];
    static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
    ScreenBrightness& SetReason(int64_t value);

    static const char kRecentTimeActiveSecName[];
    static constexpr uint64_t kRecentTimeActiveSecNameHash = UINT64_C(8488182886786891867);
    ScreenBrightness& SetRecentTimeActiveSec(int64_t value);

    static const char kSequenceIdName[];
    static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
    ScreenBrightness& SetSequenceId(int64_t value);

    static const char kTimeSinceLastEventSecName[];
    static constexpr uint64_t kTimeSinceLastEventSecNameHash = UINT64_C(8786008257637497412);
    ScreenBrightness& SetTimeSinceLastEventSec(int64_t value);
};

class Security_SafetyTip final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Security_SafetyTip(ukm::SourceId source_id);
    explicit Security_SafetyTip(ukm::SourceIdObj source_id);
    Security_SafetyTip(Security_SafetyTip&&);
    Security_SafetyTip& operator=(Security_SafetyTip&&);
    ~Security_SafetyTip() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(345243929458665883);

    static const char kSafetyTipInteractionName[];
    static constexpr uint64_t kSafetyTipInteractionNameHash = UINT64_C(568933257952179197);
    Security_SafetyTip& SetSafetyTipInteraction(int64_t value);

    static const char kSafetyTipStatusName[];
    static constexpr uint64_t kSafetyTipStatusNameHash = UINT64_C(4178545148842217888);
    Security_SafetyTip& SetSafetyTipStatus(int64_t value);

    static const char kTriggeredKeywordsHeuristicsName[];
    static constexpr uint64_t kTriggeredKeywordsHeuristicsNameHash = UINT64_C(18218625137990774330);
    Security_SafetyTip& SetTriggeredKeywordsHeuristics(int64_t value);

    static const char kTriggeredLookalikeHeuristicsName[];
    static constexpr uint64_t kTriggeredLookalikeHeuristicsNameHash = UINT64_C(17597744927637524893);
    Security_SafetyTip& SetTriggeredLookalikeHeuristics(int64_t value);

    static const char kTriggeredServerSideBlocklistName[];
    static constexpr uint64_t kTriggeredServerSideBlocklistNameHash = UINT64_C(17953907279342391241);
    Security_SafetyTip& SetTriggeredServerSideBlocklist(int64_t value);

    static const char kUserPreviouslyIgnoredName[];
    static constexpr uint64_t kUserPreviouslyIgnoredNameHash = UINT64_C(7110437703924452447);
    Security_SafetyTip& SetUserPreviouslyIgnored(int64_t value);
};

class Security_SiteEngagement final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Security_SiteEngagement(ukm::SourceId source_id);
    explicit Security_SiteEngagement(ukm::SourceIdObj source_id);
    Security_SiteEngagement(Security_SiteEngagement&&);
    Security_SiteEngagement& operator=(Security_SiteEngagement&&);
    ~Security_SiteEngagement() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10614135803401894002);

    static const char kFinalSecurityLevelName[];
    static constexpr uint64_t kFinalSecurityLevelNameHash = UINT64_C(8095555624405238595);
    Security_SiteEngagement& SetFinalSecurityLevel(int64_t value);

    static const char kInitialSecurityLevelName[];
    static constexpr uint64_t kInitialSecurityLevelNameHash = UINT64_C(7293396472423676335);
    Security_SiteEngagement& SetInitialSecurityLevel(int64_t value);

    static const char kSafetyTipStatusName[];
    static constexpr uint64_t kSafetyTipStatusNameHash = UINT64_C(4178545148842217888);
    Security_SiteEngagement& SetSafetyTipStatus(int64_t value);

    static const char kScoreDeltaName[];
    static constexpr uint64_t kScoreDeltaNameHash = UINT64_C(9558031948839307480);
    Security_SiteEngagement& SetScoreDelta(int64_t value);

    static const char kScoreFinalName[];
    static constexpr uint64_t kScoreFinalNameHash = UINT64_C(16975692316282427253);
    Security_SiteEngagement& SetScoreFinal(int64_t value);
};

class Segmentation_ModelExecution final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Segmentation_ModelExecution(ukm::SourceId source_id);
    explicit Segmentation_ModelExecution(ukm::SourceIdObj source_id);
    Segmentation_ModelExecution(Segmentation_ModelExecution&&);
    Segmentation_ModelExecution& operator=(Segmentation_ModelExecution&&);
    ~Segmentation_ModelExecution() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9156952078430180947);

    static const char kActualResultName[];
    static constexpr uint64_t kActualResultNameHash = UINT64_C(75708979098091048);
    Segmentation_ModelExecution& SetActualResult(int64_t value);

    static const char kActualResult2Name[];
    static constexpr uint64_t kActualResult2NameHash = UINT64_C(3578418478613589147);
    Segmentation_ModelExecution& SetActualResult2(int64_t value);

    static const char kActualResult3Name[];
    static constexpr uint64_t kActualResult3NameHash = UINT64_C(1171146718822301515);
    Segmentation_ModelExecution& SetActualResult3(int64_t value);

    static const char kActualResult4Name[];
    static constexpr uint64_t kActualResult4NameHash = UINT64_C(13806890300399754902);
    Segmentation_ModelExecution& SetActualResult4(int64_t value);

    static const char kActualResult5Name[];
    static constexpr uint64_t kActualResult5NameHash = UINT64_C(9461921793353839380);
    Segmentation_ModelExecution& SetActualResult5(int64_t value);

    static const char kActualResult6Name[];
    static constexpr uint64_t kActualResult6NameHash = UINT64_C(3919209671038080897);
    Segmentation_ModelExecution& SetActualResult6(int64_t value);

    static const char kInput0Name[];
    static constexpr uint64_t kInput0NameHash = UINT64_C(5761360260065884163);
    Segmentation_ModelExecution& SetInput0(int64_t value);

    static const char kInput1Name[];
    static constexpr uint64_t kInput1NameHash = UINT64_C(150022148301328073);
    Segmentation_ModelExecution& SetInput1(int64_t value);

    static const char kInput10Name[];
    static constexpr uint64_t kInput10NameHash = UINT64_C(5382043254811018347);
    Segmentation_ModelExecution& SetInput10(int64_t value);

    static const char kInput11Name[];
    static constexpr uint64_t kInput11NameHash = UINT64_C(13710680849810929162);
    Segmentation_ModelExecution& SetInput11(int64_t value);

    static const char kInput12Name[];
    static constexpr uint64_t kInput12NameHash = UINT64_C(18255987674877980703);
    Segmentation_ModelExecution& SetInput12(int64_t value);

    static const char kInput13Name[];
    static constexpr uint64_t kInput13NameHash = UINT64_C(1395549324906585545);
    Segmentation_ModelExecution& SetInput13(int64_t value);

    static const char kInput14Name[];
    static constexpr uint64_t kInput14NameHash = UINT64_C(15544141401287184547);
    Segmentation_ModelExecution& SetInput14(int64_t value);

    static const char kInput15Name[];
    static constexpr uint64_t kInput15NameHash = UINT64_C(1297068923017748103);
    Segmentation_ModelExecution& SetInput15(int64_t value);

    static const char kInput16Name[];
    static constexpr uint64_t kInput16NameHash = UINT64_C(4447996251266984754);
    Segmentation_ModelExecution& SetInput16(int64_t value);

    static const char kInput17Name[];
    static constexpr uint64_t kInput17NameHash = UINT64_C(8625535355195750850);
    Segmentation_ModelExecution& SetInput17(int64_t value);

    static const char kInput18Name[];
    static constexpr uint64_t kInput18NameHash = UINT64_C(2186726270755637996);
    Segmentation_ModelExecution& SetInput18(int64_t value);

    static const char kInput19Name[];
    static constexpr uint64_t kInput19NameHash = UINT64_C(9342769490057487582);
    Segmentation_ModelExecution& SetInput19(int64_t value);

    static const char kInput2Name[];
    static constexpr uint64_t kInput2NameHash = UINT64_C(2739558361166217772);
    Segmentation_ModelExecution& SetInput2(int64_t value);

    static const char kInput20Name[];
    static constexpr uint64_t kInput20NameHash = UINT64_C(726277997289414545);
    Segmentation_ModelExecution& SetInput20(int64_t value);

    static const char kInput21Name[];
    static constexpr uint64_t kInput21NameHash = UINT64_C(17447515146284776261);
    Segmentation_ModelExecution& SetInput21(int64_t value);

    static const char kInput22Name[];
    static constexpr uint64_t kInput22NameHash = UINT64_C(15332112782858646956);
    Segmentation_ModelExecution& SetInput22(int64_t value);

    static const char kInput23Name[];
    static constexpr uint64_t kInput23NameHash = UINT64_C(1140705726355646911);
    Segmentation_ModelExecution& SetInput23(int64_t value);

    static const char kInput24Name[];
    static constexpr uint64_t kInput24NameHash = UINT64_C(4825979367930768680);
    Segmentation_ModelExecution& SetInput24(int64_t value);

    static const char kInput25Name[];
    static constexpr uint64_t kInput25NameHash = UINT64_C(6398414356518379639);
    Segmentation_ModelExecution& SetInput25(int64_t value);

    static const char kInput26Name[];
    static constexpr uint64_t kInput26NameHash = UINT64_C(14306964208473224736);
    Segmentation_ModelExecution& SetInput26(int64_t value);

    static const char kInput27Name[];
    static constexpr uint64_t kInput27NameHash = UINT64_C(13864621080592464415);
    Segmentation_ModelExecution& SetInput27(int64_t value);

    static const char kInput28Name[];
    static constexpr uint64_t kInput28NameHash = UINT64_C(4809921782683839417);
    Segmentation_ModelExecution& SetInput28(int64_t value);

    static const char kInput29Name[];
    static constexpr uint64_t kInput29NameHash = UINT64_C(753951162852883159);
    Segmentation_ModelExecution& SetInput29(int64_t value);

    static const char kInput3Name[];
    static constexpr uint64_t kInput3NameHash = UINT64_C(8907977139870642569);
    Segmentation_ModelExecution& SetInput3(int64_t value);

    static const char kInput30Name[];
    static constexpr uint64_t kInput30NameHash = UINT64_C(12643181180871220528);
    Segmentation_ModelExecution& SetInput30(int64_t value);

    static const char kInput31Name[];
    static constexpr uint64_t kInput31NameHash = UINT64_C(6896116607581579190);
    Segmentation_ModelExecution& SetInput31(int64_t value);

    static const char kInput32Name[];
    static constexpr uint64_t kInput32NameHash = UINT64_C(13439888074349446744);
    Segmentation_ModelExecution& SetInput32(int64_t value);

    static const char kInput33Name[];
    static constexpr uint64_t kInput33NameHash = UINT64_C(7978042717175942184);
    Segmentation_ModelExecution& SetInput33(int64_t value);

    static const char kInput34Name[];
    static constexpr uint64_t kInput34NameHash = UINT64_C(11750570938835763312);
    Segmentation_ModelExecution& SetInput34(int64_t value);

    static const char kInput35Name[];
    static constexpr uint64_t kInput35NameHash = UINT64_C(6750742350518178709);
    Segmentation_ModelExecution& SetInput35(int64_t value);

    static const char kInput36Name[];
    static constexpr uint64_t kInput36NameHash = UINT64_C(9915915152088269361);
    Segmentation_ModelExecution& SetInput36(int64_t value);

    static const char kInput37Name[];
    static constexpr uint64_t kInput37NameHash = UINT64_C(8863906702311787393);
    Segmentation_ModelExecution& SetInput37(int64_t value);

    static const char kInput38Name[];
    static constexpr uint64_t kInput38NameHash = UINT64_C(6320943313905037657);
    Segmentation_ModelExecution& SetInput38(int64_t value);

    static const char kInput39Name[];
    static constexpr uint64_t kInput39NameHash = UINT64_C(13394885344990785092);
    Segmentation_ModelExecution& SetInput39(int64_t value);

    static const char kInput4Name[];
    static constexpr uint64_t kInput4NameHash = UINT64_C(7177374837023795033);
    Segmentation_ModelExecution& SetInput4(int64_t value);

    static const char kInput40Name[];
    static constexpr uint64_t kInput40NameHash = UINT64_C(5503672546122166);
    Segmentation_ModelExecution& SetInput40(int64_t value);

    static const char kInput41Name[];
    static constexpr uint64_t kInput41NameHash = UINT64_C(10356239492805306646);
    Segmentation_ModelExecution& SetInput41(int64_t value);

    static const char kInput42Name[];
    static constexpr uint64_t kInput42NameHash = UINT64_C(18077445362027282197);
    Segmentation_ModelExecution& SetInput42(int64_t value);

    static const char kInput43Name[];
    static constexpr uint64_t kInput43NameHash = UINT64_C(8942270349166249919);
    Segmentation_ModelExecution& SetInput43(int64_t value);

    static const char kInput44Name[];
    static constexpr uint64_t kInput44NameHash = UINT64_C(151938723318050673);
    Segmentation_ModelExecution& SetInput44(int64_t value);

    static const char kInput45Name[];
    static constexpr uint64_t kInput45NameHash = UINT64_C(17764448836806480672);
    Segmentation_ModelExecution& SetInput45(int64_t value);

    static const char kInput46Name[];
    static constexpr uint64_t kInput46NameHash = UINT64_C(15145877572292381854);
    Segmentation_ModelExecution& SetInput46(int64_t value);

    static const char kInput47Name[];
    static constexpr uint64_t kInput47NameHash = UINT64_C(18207110842941359078);
    Segmentation_ModelExecution& SetInput47(int64_t value);

    static const char kInput48Name[];
    static constexpr uint64_t kInput48NameHash = UINT64_C(4873755339493510235);
    Segmentation_ModelExecution& SetInput48(int64_t value);

    static const char kInput49Name[];
    static constexpr uint64_t kInput49NameHash = UINT64_C(12829919773695102741);
    Segmentation_ModelExecution& SetInput49(int64_t value);

    static const char kInput5Name[];
    static constexpr uint64_t kInput5NameHash = UINT64_C(14790726670731605994);
    Segmentation_ModelExecution& SetInput5(int64_t value);

    static const char kInput6Name[];
    static constexpr uint64_t kInput6NameHash = UINT64_C(7684355987927865867);
    Segmentation_ModelExecution& SetInput6(int64_t value);

    static const char kInput7Name[];
    static constexpr uint64_t kInput7NameHash = UINT64_C(5720986814999778908);
    Segmentation_ModelExecution& SetInput7(int64_t value);

    static const char kInput8Name[];
    static constexpr uint64_t kInput8NameHash = UINT64_C(10504359519952526313);
    Segmentation_ModelExecution& SetInput8(int64_t value);

    static const char kInput9Name[];
    static constexpr uint64_t kInput9NameHash = UINT64_C(1392250864222612624);
    Segmentation_ModelExecution& SetInput9(int64_t value);

    static const char kModelVersionName[];
    static constexpr uint64_t kModelVersionNameHash = UINT64_C(11751551263536343651);
    Segmentation_ModelExecution& SetModelVersion(int64_t value);

    static const char kOptimizationTargetName[];
    static constexpr uint64_t kOptimizationTargetNameHash = UINT64_C(497024990162357142);
    Segmentation_ModelExecution& SetOptimizationTarget(int64_t value);

    static const char kOutputDelaySecName[];
    static constexpr uint64_t kOutputDelaySecNameHash = UINT64_C(7941748199480909392);
    Segmentation_ModelExecution& SetOutputDelaySec(int64_t value);

    static const char kPredictionResultName[];
    static constexpr uint64_t kPredictionResultNameHash = UINT64_C(8597389298677168176);
    Segmentation_ModelExecution& SetPredictionResult(int64_t value);

    static const char kPredictionResult1Name[];
    static constexpr uint64_t kPredictionResult1NameHash = UINT64_C(2622392971864017319);
    Segmentation_ModelExecution& SetPredictionResult1(int64_t value);

    static const char kPredictionResult10Name[];
    static constexpr uint64_t kPredictionResult10NameHash = UINT64_C(17237433293251626679);
    Segmentation_ModelExecution& SetPredictionResult10(int64_t value);

    static const char kPredictionResult2Name[];
    static constexpr uint64_t kPredictionResult2NameHash = UINT64_C(2412157983098988064);
    Segmentation_ModelExecution& SetPredictionResult2(int64_t value);

    static const char kPredictionResult3Name[];
    static constexpr uint64_t kPredictionResult3NameHash = UINT64_C(12837703656351307559);
    Segmentation_ModelExecution& SetPredictionResult3(int64_t value);

    static const char kPredictionResult4Name[];
    static constexpr uint64_t kPredictionResult4NameHash = UINT64_C(4495609423102035135);
    Segmentation_ModelExecution& SetPredictionResult4(int64_t value);

    static const char kPredictionResult5Name[];
    static constexpr uint64_t kPredictionResult5NameHash = UINT64_C(6205821896269319087);
    Segmentation_ModelExecution& SetPredictionResult5(int64_t value);

    static const char kPredictionResult6Name[];
    static constexpr uint64_t kPredictionResult6NameHash = UINT64_C(6507039871768532337);
    Segmentation_ModelExecution& SetPredictionResult6(int64_t value);

    static const char kPredictionResult7Name[];
    static constexpr uint64_t kPredictionResult7NameHash = UINT64_C(17089594956138813824);
    Segmentation_ModelExecution& SetPredictionResult7(int64_t value);

    static const char kPredictionResult8Name[];
    static constexpr uint64_t kPredictionResult8NameHash = UINT64_C(3934910392183033263);
    Segmentation_ModelExecution& SetPredictionResult8(int64_t value);

    static const char kPredictionResult9Name[];
    static constexpr uint64_t kPredictionResult9NameHash = UINT64_C(11165548966921076514);
    Segmentation_ModelExecution& SetPredictionResult9(int64_t value);

    static const char kSelectionResultName[];
    static constexpr uint64_t kSelectionResultNameHash = UINT64_C(15371238735853958028);
    Segmentation_ModelExecution& SetSelectionResult(int64_t value);
};

class ServiceWorker_MainResourceLoadCompleted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ServiceWorker_MainResourceLoadCompleted(ukm::SourceId source_id);
    explicit ServiceWorker_MainResourceLoadCompleted(ukm::SourceIdObj source_id);
    ServiceWorker_MainResourceLoadCompleted(ServiceWorker_MainResourceLoadCompleted&&);
    ServiceWorker_MainResourceLoadCompleted& operator=(ServiceWorker_MainResourceLoadCompleted&&);
    ~ServiceWorker_MainResourceLoadCompleted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3667446516803222545);

    static const char kActualRouterSourceTypeName[];
    static constexpr uint64_t kActualRouterSourceTypeNameHash = UINT64_C(12393482610045732963);
    ServiceWorker_MainResourceLoadCompleted& SetActualRouterSourceType(int64_t value);

    static const char kCacheLookupTimeName[];
    static constexpr uint64_t kCacheLookupTimeNameHash = UINT64_C(9689357548665155866);
    ServiceWorker_MainResourceLoadCompleted& SetCacheLookupTime(int64_t value);

    static const char kInitialWorkerStatusName[];
    static constexpr uint64_t kInitialWorkerStatusNameHash = UINT64_C(8726266245916839009);
    ServiceWorker_MainResourceLoadCompleted& SetInitialWorkerStatus(int64_t value);

    static const char kMatchedFirstRouterSourceTypeName[];
    static constexpr uint64_t kMatchedFirstRouterSourceTypeNameHash = UINT64_C(14378538428447312758);
    ServiceWorker_MainResourceLoadCompleted& SetMatchedFirstRouterSourceType(int64_t value);

    static const char kRouterEvaluationTimeName[];
    static constexpr uint64_t kRouterEvaluationTimeNameHash = UINT64_C(17815360484635108448);
    ServiceWorker_MainResourceLoadCompleted& SetRouterEvaluationTime(int64_t value);

    static const char kRouterRuleCountName[];
    static constexpr uint64_t kRouterRuleCountNameHash = UINT64_C(16475349113444097763);
    ServiceWorker_MainResourceLoadCompleted& SetRouterRuleCount(int64_t value);

    static const char kWorkerStatusOnEvaluationName[];
    static constexpr uint64_t kWorkerStatusOnEvaluationNameHash = UINT64_C(12577190485528634461);
    ServiceWorker_MainResourceLoadCompleted& SetWorkerStatusOnEvaluation(int64_t value);
};

class ServiceWorker_OnLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ServiceWorker_OnLoad(ukm::SourceId source_id);
    explicit ServiceWorker_OnLoad(ukm::SourceIdObj source_id);
    ServiceWorker_OnLoad(ServiceWorker_OnLoad&&);
    ServiceWorker_OnLoad& operator=(ServiceWorker_OnLoad&&);
    ~ServiceWorker_OnLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15102348699902695841);

    static const char kAudioFallbackName[];
    static constexpr uint64_t kAudioFallbackNameHash = UINT64_C(16138389636332845866);
    ServiceWorker_OnLoad& SetAudioFallback(int64_t value);

    static const char kAudioHandledName[];
    static constexpr uint64_t kAudioHandledNameHash = UINT64_C(17956730792959590511);
    ServiceWorker_OnLoad& SetAudioHandled(int64_t value);

    static const char kCSSStyleSheetFallbackName[];
    static constexpr uint64_t kCSSStyleSheetFallbackNameHash = UINT64_C(3593859089665897643);
    ServiceWorker_OnLoad& SetCSSStyleSheetFallback(int64_t value);

    static const char kCSSStyleSheetHandledName[];
    static constexpr uint64_t kCSSStyleSheetHandledNameHash = UINT64_C(10517965298735239032);
    ServiceWorker_OnLoad& SetCSSStyleSheetHandled(int64_t value);

    static const char kDictionaryFallbackName[];
    static constexpr uint64_t kDictionaryFallbackNameHash = UINT64_C(13445717714460720700);
    ServiceWorker_OnLoad& SetDictionaryFallback(int64_t value);

    static const char kDictionaryHandledName[];
    static constexpr uint64_t kDictionaryHandledNameHash = UINT64_C(13038010413131989653);
    ServiceWorker_OnLoad& SetDictionaryHandled(int64_t value);

    static const char kFontFallbackName[];
    static constexpr uint64_t kFontFallbackNameHash = UINT64_C(5243074012623308837);
    ServiceWorker_OnLoad& SetFontFallback(int64_t value);

    static const char kFontHandledName[];
    static constexpr uint64_t kFontHandledNameHash = UINT64_C(4539826137365260745);
    ServiceWorker_OnLoad& SetFontHandled(int64_t value);

    static const char kImageFallbackName[];
    static constexpr uint64_t kImageFallbackNameHash = UINT64_C(6841773001619742468);
    ServiceWorker_OnLoad& SetImageFallback(int64_t value);

    static const char kImageHandledName[];
    static constexpr uint64_t kImageHandledNameHash = UINT64_C(15285567803164275264);
    ServiceWorker_OnLoad& SetImageHandled(int64_t value);

    static const char kLinkPrefetchFallbackName[];
    static constexpr uint64_t kLinkPrefetchFallbackNameHash = UINT64_C(12598766854285236741);
    ServiceWorker_OnLoad& SetLinkPrefetchFallback(int64_t value);

    static const char kLinkPrefetchHandledName[];
    static constexpr uint64_t kLinkPrefetchHandledNameHash = UINT64_C(8113321388289206636);
    ServiceWorker_OnLoad& SetLinkPrefetchHandled(int64_t value);

    static const char kMainAndSubResourceLoadLocationName[];
    static constexpr uint64_t kMainAndSubResourceLoadLocationNameHash = UINT64_C(6147823118530426100);
    ServiceWorker_OnLoad& SetMainAndSubResourceLoadLocation(int64_t value);

    static const char kManifestFallbackName[];
    static constexpr uint64_t kManifestFallbackNameHash = UINT64_C(7831621679562355633);
    ServiceWorker_OnLoad& SetManifestFallback(int64_t value);

    static const char kManifestHandledName[];
    static constexpr uint64_t kManifestHandledNameHash = UINT64_C(14791047053451032046);
    ServiceWorker_OnLoad& SetManifestHandled(int64_t value);

    static const char kMatchedCacheRouterSourceCountName[];
    static constexpr uint64_t kMatchedCacheRouterSourceCountNameHash = UINT64_C(6331413656616969874);
    ServiceWorker_OnLoad& SetMatchedCacheRouterSourceCount(int64_t value);

    static const char kMatchedFetchEventRouterSourceCountName[];
    static constexpr uint64_t kMatchedFetchEventRouterSourceCountNameHash = UINT64_C(3216214254857135154);
    ServiceWorker_OnLoad& SetMatchedFetchEventRouterSourceCount(int64_t value);

    static const char kMatchedNetworkRouterSourceCountName[];
    static constexpr uint64_t kMatchedNetworkRouterSourceCountNameHash = UINT64_C(4019788518368790668);
    ServiceWorker_OnLoad& SetMatchedNetworkRouterSourceCount(int64_t value);

    static const char kMatchedRaceNetworkAndFetchRouterSourceCountName[];
    static constexpr uint64_t kMatchedRaceNetworkAndFetchRouterSourceCountNameHash = UINT64_C(12640843675497359737);
    ServiceWorker_OnLoad& SetMatchedRaceNetworkAndFetchRouterSourceCount(int64_t value);

    static const char kScriptFallbackName[];
    static constexpr uint64_t kScriptFallbackNameHash = UINT64_C(18275115230204467900);
    ServiceWorker_OnLoad& SetScriptFallback(int64_t value);

    static const char kScriptHandledName[];
    static constexpr uint64_t kScriptHandledNameHash = UINT64_C(7850316435748453081);
    ServiceWorker_OnLoad& SetScriptHandled(int64_t value);

    static const char kSpeculationRulesFallbackName[];
    static constexpr uint64_t kSpeculationRulesFallbackNameHash = UINT64_C(4427169709671966011);
    ServiceWorker_OnLoad& SetSpeculationRulesFallback(int64_t value);

    static const char kSpeculationRulesHandledName[];
    static constexpr uint64_t kSpeculationRulesHandledNameHash = UINT64_C(14885210901083100217);
    ServiceWorker_OnLoad& SetSpeculationRulesHandled(int64_t value);

    static const char kSubResourceFallbackRatioName[];
    static constexpr uint64_t kSubResourceFallbackRatioNameHash = UINT64_C(5010363185084736733);
    ServiceWorker_OnLoad& SetSubResourceFallbackRatio(int64_t value);

    static const char kSVGDocumentFallbackName[];
    static constexpr uint64_t kSVGDocumentFallbackNameHash = UINT64_C(17276522845747061498);
    ServiceWorker_OnLoad& SetSVGDocumentFallback(int64_t value);

    static const char kSVGDocumentHandledName[];
    static constexpr uint64_t kSVGDocumentHandledNameHash = UINT64_C(10039118041232603737);
    ServiceWorker_OnLoad& SetSVGDocumentHandled(int64_t value);

    static const char kTextTrackFallbackName[];
    static constexpr uint64_t kTextTrackFallbackNameHash = UINT64_C(9484704560561895521);
    ServiceWorker_OnLoad& SetTextTrackFallback(int64_t value);

    static const char kTextTrackHandledName[];
    static constexpr uint64_t kTextTrackHandledNameHash = UINT64_C(17623659889089244726);
    ServiceWorker_OnLoad& SetTextTrackHandled(int64_t value);

    static const char kTotalCacheLookupTimeName[];
    static constexpr uint64_t kTotalCacheLookupTimeNameHash = UINT64_C(1219021129624374946);
    ServiceWorker_OnLoad& SetTotalCacheLookupTime(int64_t value);

    static const char kTotalRouterEvaluationTimeName[];
    static constexpr uint64_t kTotalRouterEvaluationTimeNameHash = UINT64_C(18105115321767231798);
    ServiceWorker_OnLoad& SetTotalRouterEvaluationTime(int64_t value);

    static const char kTotalSubResourceFallbackName[];
    static constexpr uint64_t kTotalSubResourceFallbackNameHash = UINT64_C(16330162352104342410);
    ServiceWorker_OnLoad& SetTotalSubResourceFallback(int64_t value);

    static const char kTotalSubResourceLoadName[];
    static constexpr uint64_t kTotalSubResourceLoadNameHash = UINT64_C(2566575000254448588);
    ServiceWorker_OnLoad& SetTotalSubResourceLoad(int64_t value);

    static const char kVideoFallbackName[];
    static constexpr uint64_t kVideoFallbackNameHash = UINT64_C(13742581294918999857);
    ServiceWorker_OnLoad& SetVideoFallback(int64_t value);

    static const char kVideoHandledName[];
    static constexpr uint64_t kVideoHandledNameHash = UINT64_C(4642078925241326387);
    ServiceWorker_OnLoad& SetVideoHandled(int64_t value);

    static const char kXSLStyleSheetFallbackName[];
    static constexpr uint64_t kXSLStyleSheetFallbackNameHash = UINT64_C(7336812727313874349);
    ServiceWorker_OnLoad& SetXSLStyleSheetFallback(int64_t value);

    static const char kXSLStyleSheetHandledName[];
    static constexpr uint64_t kXSLStyleSheetHandledNameHash = UINT64_C(11859435171078605072);
    ServiceWorker_OnLoad& SetXSLStyleSheetHandled(int64_t value);
};

class SharedHighlights_LinkGenerated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SharedHighlights_LinkGenerated(ukm::SourceId source_id);
    explicit SharedHighlights_LinkGenerated(ukm::SourceIdObj source_id);
    SharedHighlights_LinkGenerated(SharedHighlights_LinkGenerated&&);
    SharedHighlights_LinkGenerated& operator=(SharedHighlights_LinkGenerated&&);
    ~SharedHighlights_LinkGenerated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9684160219705289407);

    static const char kErrorName[];
    static constexpr uint64_t kErrorNameHash = UINT64_C(10388411628442810104);
    SharedHighlights_LinkGenerated& SetError(int64_t value);

    static const char kSuccessName[];
    static constexpr uint64_t kSuccessNameHash = UINT64_C(5790085346892983794);
    SharedHighlights_LinkGenerated& SetSuccess(int64_t value);
};

class SharedHighlights_LinkGenerated_Requested final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SharedHighlights_LinkGenerated_Requested(ukm::SourceId source_id);
    explicit SharedHighlights_LinkGenerated_Requested(ukm::SourceIdObj source_id);
    SharedHighlights_LinkGenerated_Requested(SharedHighlights_LinkGenerated_Requested&&);
    SharedHighlights_LinkGenerated_Requested& operator=(SharedHighlights_LinkGenerated_Requested&&);
    ~SharedHighlights_LinkGenerated_Requested() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(386901924898439243);

    static const char kErrorName[];
    static constexpr uint64_t kErrorNameHash = UINT64_C(10388411628442810104);
    SharedHighlights_LinkGenerated_Requested& SetError(int64_t value);

    static const char kSuccessName[];
    static constexpr uint64_t kSuccessNameHash = UINT64_C(5790085346892983794);
    SharedHighlights_LinkGenerated_Requested& SetSuccess(int64_t value);
};

class SharedHighlights_LinkOpened final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SharedHighlights_LinkOpened(ukm::SourceId source_id);
    explicit SharedHighlights_LinkOpened(ukm::SourceIdObj source_id);
    SharedHighlights_LinkOpened(SharedHighlights_LinkOpened&&);
    SharedHighlights_LinkOpened& operator=(SharedHighlights_LinkOpened&&);
    ~SharedHighlights_LinkOpened() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11756915687522041272);

    static const char kSourceName[];
    static constexpr uint64_t kSourceNameHash = UINT64_C(17517803883951840204);
    SharedHighlights_LinkOpened& SetSource(int64_t value);

    static const char kSuccessName[];
    static constexpr uint64_t kSuccessNameHash = UINT64_C(5790085346892983794);
    SharedHighlights_LinkOpened& SetSuccess(int64_t value);
};

class Sharing_ClickToCall final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Sharing_ClickToCall(ukm::SourceId source_id);
    explicit Sharing_ClickToCall(ukm::SourceIdObj source_id);
    Sharing_ClickToCall(Sharing_ClickToCall&&);
    Sharing_ClickToCall& operator=(Sharing_ClickToCall&&);
    ~Sharing_ClickToCall() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13674128907128689363);

    static const char kEntryPointName[];
    static constexpr uint64_t kEntryPointNameHash = UINT64_C(14367068064969258826);
    Sharing_ClickToCall& SetEntryPoint(int64_t value);

    static const char kHasAppsName[];
    static constexpr uint64_t kHasAppsNameHash = UINT64_C(8572169351575878732);
    Sharing_ClickToCall& SetHasApps(int64_t value);

    static const char kHasDevicesName[];
    static constexpr uint64_t kHasDevicesNameHash = UINT64_C(2199982532385446345);
    Sharing_ClickToCall& SetHasDevices(int64_t value);

    static const char kSelectionName[];
    static constexpr uint64_t kSelectionNameHash = UINT64_C(8068723256203825537);
    Sharing_ClickToCall& SetSelection(int64_t value);
};

class Shopping_AddToCartDetection final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_AddToCartDetection(ukm::SourceId source_id);
    explicit Shopping_AddToCartDetection(ukm::SourceIdObj source_id);
    Shopping_AddToCartDetection(Shopping_AddToCartDetection&&);
    Shopping_AddToCartDetection& operator=(Shopping_AddToCartDetection&&);
    ~Shopping_AddToCartDetection() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13706312502393203858);

    static const char kHeuristicsExecutionTimeName[];
    static constexpr uint64_t kHeuristicsExecutionTimeNameHash = UINT64_C(5250854800023514488);
    Shopping_AddToCartDetection& SetHeuristicsExecutionTime(int64_t value);
};

class Shopping_CartExtraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_CartExtraction(ukm::SourceId source_id);
    explicit Shopping_CartExtraction(ukm::SourceIdObj source_id);
    Shopping_CartExtraction(Shopping_CartExtraction&&);
    Shopping_CartExtraction& operator=(Shopping_CartExtraction&&);
    ~Shopping_CartExtraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3949460549124608133);

    static const char kExtractionElapsedTimeName[];
    static constexpr uint64_t kExtractionElapsedTimeNameHash = UINT64_C(15571856795560467413);
    Shopping_CartExtraction& SetExtractionElapsedTime(int64_t value);

    static const char kExtractionExecutionTimeName[];
    static constexpr uint64_t kExtractionExecutionTimeNameHash = UINT64_C(11366090672896254376);
    Shopping_CartExtraction& SetExtractionExecutionTime(int64_t value);

    static const char kExtractionLongestTaskTimeName[];
    static constexpr uint64_t kExtractionLongestTaskTimeNameHash = UINT64_C(9626282323817938029);
    Shopping_CartExtraction& SetExtractionLongestTaskTime(int64_t value);

    static const char kExtractionTimedOutName[];
    static constexpr uint64_t kExtractionTimedOutNameHash = UINT64_C(3964136441095192791);
    Shopping_CartExtraction& SetExtractionTimedOut(int64_t value);

    static const char kExtractionTotalTasksTimeName[];
    static constexpr uint64_t kExtractionTotalTasksTimeNameHash = UINT64_C(7923924403217250445);
    Shopping_CartExtraction& SetExtractionTotalTasksTime(int64_t value);
};

class Shopping_ChromeCart final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_ChromeCart(ukm::SourceId source_id);
    explicit Shopping_ChromeCart(ukm::SourceIdObj source_id);
    Shopping_ChromeCart(Shopping_ChromeCart&&);
    Shopping_ChromeCart& operator=(Shopping_ChromeCart&&);
    ~Shopping_ChromeCart() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15978989974993672382);

    static const char kVisitCartName[];
    static constexpr uint64_t kVisitCartNameHash = UINT64_C(15744295698936290156);
    Shopping_ChromeCart& SetVisitCart(int64_t value);
};

class Shopping_Compare_ClusterIdenfitiedByClient final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_Compare_ClusterIdenfitiedByClient(ukm::SourceId source_id);
    explicit Shopping_Compare_ClusterIdenfitiedByClient(ukm::SourceIdObj source_id);
    Shopping_Compare_ClusterIdenfitiedByClient(Shopping_Compare_ClusterIdenfitiedByClient&&);
    Shopping_Compare_ClusterIdenfitiedByClient& operator=(Shopping_Compare_ClusterIdenfitiedByClient&&);
    ~Shopping_Compare_ClusterIdenfitiedByClient() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15728395807615377346);

    static const char kComparableByServerName[];
    static constexpr uint64_t kComparableByServerNameHash = UINT64_C(501341947665299387);
    Shopping_Compare_ClusterIdenfitiedByClient& SetComparableByServer(int64_t value);

    static const char kCompareEventIDName[];
    static constexpr uint64_t kCompareEventIDNameHash = UINT64_C(8488013041447752319);
    Shopping_Compare_ClusterIdenfitiedByClient& SetCompareEventID(int64_t value);
};

class Shopping_Discounts final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_Discounts(ukm::SourceId source_id);
    explicit Shopping_Discounts(ukm::SourceIdObj source_id);
    Shopping_Discounts(Shopping_Discounts&&);
    Shopping_Discounts& operator=(Shopping_Discounts&&);
    ~Shopping_Discounts() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15032836644362572537);

    static const char kAutoPopupEligibleButSuppressedName[];
    static constexpr uint64_t kAutoPopupEligibleButSuppressedNameHash = UINT64_C(15800185500856841800);
    Shopping_Discounts& SetAutoPopupEligibleButSuppressed(int64_t value);
};

class Shopping_FormSubmitted final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_FormSubmitted(ukm::SourceId source_id);
    explicit Shopping_FormSubmitted(ukm::SourceIdObj source_id);
    Shopping_FormSubmitted(Shopping_FormSubmitted&&);
    Shopping_FormSubmitted& operator=(Shopping_FormSubmitted&&);
    ~Shopping_FormSubmitted() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3010088505008297297);

    static const char kIsTransactionName[];
    static constexpr uint64_t kIsTransactionNameHash = UINT64_C(2385225591379210840);
    Shopping_FormSubmitted& SetIsTransaction(int64_t value);
};

class Shopping_MerchantTrust_DataAvailable final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_MerchantTrust_DataAvailable(ukm::SourceId source_id);
    explicit Shopping_MerchantTrust_DataAvailable(ukm::SourceIdObj source_id);
    Shopping_MerchantTrust_DataAvailable(Shopping_MerchantTrust_DataAvailable&&);
    Shopping_MerchantTrust_DataAvailable& operator=(Shopping_MerchantTrust_DataAvailable&&);
    ~Shopping_MerchantTrust_DataAvailable() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5357508630854566377);

    static const char kDataAvailableName[];
    static constexpr uint64_t kDataAvailableNameHash = UINT64_C(7172207529446801214);
    Shopping_MerchantTrust_DataAvailable& SetDataAvailable(int64_t value);
};

class Shopping_MerchantTrust_MessageClicked final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_MerchantTrust_MessageClicked(ukm::SourceId source_id);
    explicit Shopping_MerchantTrust_MessageClicked(ukm::SourceIdObj source_id);
    Shopping_MerchantTrust_MessageClicked(Shopping_MerchantTrust_MessageClicked&&);
    Shopping_MerchantTrust_MessageClicked& operator=(Shopping_MerchantTrust_MessageClicked&&);
    ~Shopping_MerchantTrust_MessageClicked() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14995105157617764468);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    Shopping_MerchantTrust_MessageClicked& SetHasOccurred(int64_t value);
};

class Shopping_MerchantTrust_MessageSeen final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_MerchantTrust_MessageSeen(ukm::SourceId source_id);
    explicit Shopping_MerchantTrust_MessageSeen(ukm::SourceIdObj source_id);
    Shopping_MerchantTrust_MessageSeen(Shopping_MerchantTrust_MessageSeen&&);
    Shopping_MerchantTrust_MessageSeen& operator=(Shopping_MerchantTrust_MessageSeen&&);
    ~Shopping_MerchantTrust_MessageSeen() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16840045675093743647);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    Shopping_MerchantTrust_MessageSeen& SetHasOccurred(int64_t value);
};

class Shopping_MerchantTrust_RowClicked final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_MerchantTrust_RowClicked(ukm::SourceId source_id);
    explicit Shopping_MerchantTrust_RowClicked(ukm::SourceIdObj source_id);
    Shopping_MerchantTrust_RowClicked(Shopping_MerchantTrust_RowClicked&&);
    Shopping_MerchantTrust_RowClicked& operator=(Shopping_MerchantTrust_RowClicked&&);
    ~Shopping_MerchantTrust_RowClicked() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10655844918945147363);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    Shopping_MerchantTrust_RowClicked& SetHasOccurred(int64_t value);
};

class Shopping_MerchantTrust_RowSeen final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_MerchantTrust_RowSeen(ukm::SourceId source_id);
    explicit Shopping_MerchantTrust_RowSeen(ukm::SourceIdObj source_id);
    Shopping_MerchantTrust_RowSeen(Shopping_MerchantTrust_RowSeen&&);
    Shopping_MerchantTrust_RowSeen& operator=(Shopping_MerchantTrust_RowSeen&&);
    ~Shopping_MerchantTrust_RowSeen() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4482961312405396574);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    Shopping_MerchantTrust_RowSeen& SetHasOccurred(int64_t value);
};

class Shopping_PDPStateWithLocalInfo final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_PDPStateWithLocalInfo(ukm::SourceId source_id);
    explicit Shopping_PDPStateWithLocalInfo(ukm::SourceIdObj source_id);
    Shopping_PDPStateWithLocalInfo(Shopping_PDPStateWithLocalInfo&&);
    Shopping_PDPStateWithLocalInfo& operator=(Shopping_PDPStateWithLocalInfo&&);
    ~Shopping_PDPStateWithLocalInfo() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9670390910407059784);

    static const char kPDPStateName[];
    static constexpr uint64_t kPDPStateNameHash = UINT64_C(11286918823362187842);
    Shopping_PDPStateWithLocalInfo& SetPDPState(int64_t value);
};

class Shopping_ShoppingAction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_ShoppingAction(ukm::SourceId source_id);
    explicit Shopping_ShoppingAction(ukm::SourceIdObj source_id);
    Shopping_ShoppingAction(Shopping_ShoppingAction&&);
    Shopping_ShoppingAction& operator=(Shopping_ShoppingAction&&);
    ~Shopping_ShoppingAction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(1072028031342147445);

    static const char kDiscountCopiedName[];
    static constexpr uint64_t kDiscountCopiedNameHash = UINT64_C(12198604073788116184);
    Shopping_ShoppingAction& SetDiscountCopied(int64_t value);

    static const char kDiscountOpenedName[];
    static constexpr uint64_t kDiscountOpenedNameHash = UINT64_C(14349091270510759248);
    Shopping_ShoppingAction& SetDiscountOpened(int64_t value);

    static const char kPriceInsightsOpenedName[];
    static constexpr uint64_t kPriceInsightsOpenedNameHash = UINT64_C(2111701015485587991);
    Shopping_ShoppingAction& SetPriceInsightsOpened(int64_t value);

    static const char kPriceTrackedName[];
    static constexpr uint64_t kPriceTrackedNameHash = UINT64_C(8895701467779509428);
    Shopping_ShoppingAction& SetPriceTracked(int64_t value);
};

class Shopping_ShoppingInformation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_ShoppingInformation(ukm::SourceId source_id);
    explicit Shopping_ShoppingInformation(ukm::SourceIdObj source_id);
    Shopping_ShoppingInformation(Shopping_ShoppingInformation&&);
    Shopping_ShoppingInformation& operator=(Shopping_ShoppingInformation&&);
    ~Shopping_ShoppingInformation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8745051225343642264);

    static const char kHasDiscountName[];
    static constexpr uint64_t kHasDiscountNameHash = UINT64_C(3383947808112417129);
    Shopping_ShoppingInformation& SetHasDiscount(int64_t value);

    static const char kHasPriceInsightsName[];
    static constexpr uint64_t kHasPriceInsightsNameHash = UINT64_C(7260225441174014206);
    Shopping_ShoppingInformation& SetHasPriceInsights(int64_t value);

    static const char kIsPriceTrackableName[];
    static constexpr uint64_t kIsPriceTrackableNameHash = UINT64_C(5791656589929102098);
    Shopping_ShoppingInformation& SetIsPriceTrackable(int64_t value);

    static const char kIsShoppingContentName[];
    static constexpr uint64_t kIsShoppingContentNameHash = UINT64_C(14966852632184817847);
    Shopping_ShoppingInformation& SetIsShoppingContent(int64_t value);

    static const char kPromotedFeatureName[];
    static constexpr uint64_t kPromotedFeatureNameHash = UINT64_C(6045203671866140067);
    Shopping_ShoppingInformation& SetPromotedFeature(int64_t value);
};

class Shopping_WillSendRequest final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Shopping_WillSendRequest(ukm::SourceId source_id);
    explicit Shopping_WillSendRequest(ukm::SourceIdObj source_id);
    Shopping_WillSendRequest(Shopping_WillSendRequest&&);
    Shopping_WillSendRequest& operator=(Shopping_WillSendRequest&&);
    ~Shopping_WillSendRequest() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16734271994830574968);

    static const char kIsAddToCartName[];
    static constexpr uint64_t kIsAddToCartNameHash = UINT64_C(11667601651520938807);
    Shopping_WillSendRequest& SetIsAddToCart(int64_t value);
};

class Site_Install final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Site_Install(ukm::SourceId source_id);
    explicit Site_Install(ukm::SourceIdObj source_id);
    Site_Install(Site_Install&&);
    Site_Install& operator=(Site_Install&&);
    ~Site_Install() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11664953658330515632);

    static const char kIsFullyInstalledName[];
    static constexpr uint64_t kIsFullyInstalledNameHash = UINT64_C(18181385909784257746);
    Site_Install& SetIsFullyInstalled(int64_t value);

    static const char kIsPartiallyInstalledName[];
    static constexpr uint64_t kIsPartiallyInstalledNameHash = UINT64_C(8644105914810579902);
    Site_Install& SetIsPartiallyInstalled(int64_t value);
};

class Site_Manifest final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Site_Manifest(ukm::SourceId source_id);
    explicit Site_Manifest(ukm::SourceIdObj source_id);
    Site_Manifest(Site_Manifest&&);
    Site_Manifest& operator=(Site_Manifest&&);
    ~Site_Manifest() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6971281771354023578);

    static const char kDisplayModeName[];
    static constexpr uint64_t kDisplayModeNameHash = UINT64_C(12581275766339648725);
    Site_Manifest& SetDisplayMode(int64_t value);

    static const char kHasBackgroundColorName[];
    static constexpr uint64_t kHasBackgroundColorNameHash = UINT64_C(16515787713929885496);
    Site_Manifest& SetHasBackgroundColor(int64_t value);

    static const char kHasIconsAnyName[];
    static constexpr uint64_t kHasIconsAnyNameHash = UINT64_C(4983617487970367888);
    Site_Manifest& SetHasIconsAny(int64_t value);

    static const char kHasIconsMaskableName[];
    static constexpr uint64_t kHasIconsMaskableNameHash = UINT64_C(2523521394906300467);
    Site_Manifest& SetHasIconsMaskable(int64_t value);

    static const char kHasNameName[];
    static constexpr uint64_t kHasNameNameHash = UINT64_C(16566688950993043228);
    Site_Manifest& SetHasName(int64_t value);

    static const char kHasScreenshotsName[];
    static constexpr uint64_t kHasScreenshotsNameHash = UINT64_C(6780481866526027462);
    Site_Manifest& SetHasScreenshots(int64_t value);

    static const char kHasStartUrlName[];
    static constexpr uint64_t kHasStartUrlNameHash = UINT64_C(11301080039298692860);
    Site_Manifest& SetHasStartUrl(int64_t value);

    static const char kHasThemeColorName[];
    static constexpr uint64_t kHasThemeColorNameHash = UINT64_C(6533850945655965012);
    Site_Manifest& SetHasThemeColor(int64_t value);
};

class Site_Quality final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Site_Quality(ukm::SourceId source_id);
    explicit Site_Quality(ukm::SourceIdObj source_id);
    Site_Quality(Site_Quality&&);
    Site_Quality& operator=(Site_Quality&&);
    ~Site_Quality() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16599718914662473687);

    static const char kCacheStorageSizeName[];
    static constexpr uint64_t kCacheStorageSizeNameHash = UINT64_C(17674093176108512819);
    Site_Quality& SetCacheStorageSize(int64_t value);

    static const char kHasFaviconsName[];
    static constexpr uint64_t kHasFaviconsNameHash = UINT64_C(12583545989314408493);
    Site_Quality& SetHasFavicons(int64_t value);

    static const char kHasFetchHandlerName[];
    static constexpr uint64_t kHasFetchHandlerNameHash = UINT64_C(13887875358231584306);
    Site_Quality& SetHasFetchHandler(int64_t value);

    static const char kServiceWorkerScriptSizeName[];
    static constexpr uint64_t kServiceWorkerScriptSizeNameHash = UINT64_C(14432014646625439595);
    Site_Quality& SetServiceWorkerScriptSize(int64_t value);
};

class SiteFamiliarityHeuristicResult final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SiteFamiliarityHeuristicResult(ukm::SourceId source_id);
    explicit SiteFamiliarityHeuristicResult(ukm::SourceIdObj source_id);
    SiteFamiliarityHeuristicResult(SiteFamiliarityHeuristicResult&&);
    SiteFamiliarityHeuristicResult& operator=(SiteFamiliarityHeuristicResult&&);
    ~SiteFamiliarityHeuristicResult() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(993750679081265304);

    static const char kAnyHeuristicsMatchName[];
    static constexpr uint64_t kAnyHeuristicsMatchNameHash = UINT64_C(4962542376021717220);
    SiteFamiliarityHeuristicResult& SetAnyHeuristicsMatch(int64_t value);

    static const char kOnHighConfidenceAllowlistName[];
    static constexpr uint64_t kOnHighConfidenceAllowlistNameHash = UINT64_C(7526410004744485263);
    SiteFamiliarityHeuristicResult& SetOnHighConfidenceAllowlist(int64_t value);

    static const char kSiteEngagementScoreName[];
    static constexpr uint64_t kSiteEngagementScoreNameHash = UINT64_C(325008584515519231);
    SiteFamiliarityHeuristicResult& SetSiteEngagementScore(int64_t value);

    static const char kSiteFamiliarityHistoryHeuristicName[];
    static constexpr uint64_t kSiteFamiliarityHistoryHeuristicNameHash = UINT64_C(15700057141415069925);
    SiteFamiliarityHeuristicResult& SetSiteFamiliarityHistoryHeuristic(int64_t value);
};

class SiteInstance final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SiteInstance(ukm::SourceId source_id);
    explicit SiteInstance(ukm::SourceIdObj source_id);
    SiteInstance(SiteInstance&&);
    SiteInstance& operator=(SiteInstance&&);
    ~SiteInstance() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6253142163073541541);

    static const char kNewProcessUsedForNavigationWhenSameSiteProcessExistsName[];
    static constexpr uint64_t kNewProcessUsedForNavigationWhenSameSiteProcessExistsNameHash = UINT64_C(944207937901224415);
    SiteInstance& SetNewProcessUsedForNavigationWhenSameSiteProcessExists(int64_t value);
};

class SmartCharging final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SmartCharging(ukm::SourceId source_id);
    explicit SmartCharging(ukm::SourceIdObj source_id);
    SmartCharging(SmartCharging&&);
    SmartCharging& operator=(SmartCharging&&);
    ~SmartCharging() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(18163040957371490481);

    static const char kBatteryPercentageName[];
    static constexpr uint64_t kBatteryPercentageNameHash = UINT64_C(14519123228304078098);
    SmartCharging& SetBatteryPercentage(int64_t value);

    static const char kBatteryPercentageBeforeLastChargeName[];
    static constexpr uint64_t kBatteryPercentageBeforeLastChargeNameHash = UINT64_C(18006859437126683457);
    SmartCharging& SetBatteryPercentageBeforeLastCharge(int64_t value);

    static const char kBatteryPercentageOfLastChargeName[];
    static constexpr uint64_t kBatteryPercentageOfLastChargeNameHash = UINT64_C(11152599426817198152);
    SmartCharging& SetBatteryPercentageOfLastCharge(int64_t value);

    static const char kDayOfMonthName[];
    static constexpr uint64_t kDayOfMonthNameHash = UINT64_C(6240377267495591558);
    SmartCharging& SetDayOfMonth(int64_t value);

    static const char kDayOfWeekName[];
    static constexpr uint64_t kDayOfWeekNameHash = UINT64_C(15612008539140949281);
    SmartCharging& SetDayOfWeek(int64_t value);

    static const char kDeviceModeName[];
    static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
    SmartCharging& SetDeviceMode(int64_t value);

    static const char kDeviceTypeName[];
    static constexpr uint64_t kDeviceTypeNameHash = UINT64_C(7795620498098931292);
    SmartCharging& SetDeviceType(int64_t value);

    static const char kDurationOfLastChargeName[];
    static constexpr uint64_t kDurationOfLastChargeNameHash = UINT64_C(2917539631700490805);
    SmartCharging& SetDurationOfLastCharge(int64_t value);

    static const char kDurationRecentAudioPlayingName[];
    static constexpr uint64_t kDurationRecentAudioPlayingNameHash = UINT64_C(13229015898265878531);
    SmartCharging& SetDurationRecentAudioPlaying(int64_t value);

    static const char kDurationRecentVideoPlayingName[];
    static constexpr uint64_t kDurationRecentVideoPlayingNameHash = UINT64_C(7949042912449780813);
    SmartCharging& SetDurationRecentVideoPlaying(int64_t value);

    static const char kEventIdName[];
    static constexpr uint64_t kEventIdNameHash = UINT64_C(8388046208606800177);
    SmartCharging& SetEventId(int64_t value);

    static const char kHaltFromLastChargeName[];
    static constexpr uint64_t kHaltFromLastChargeNameHash = UINT64_C(4462991214889947556);
    SmartCharging& SetHaltFromLastCharge(int64_t value);

    static const char kIsChargingName[];
    static constexpr uint64_t kIsChargingNameHash = UINT64_C(7785451285210820804);
    SmartCharging& SetIsCharging(int64_t value);

    static const char kMonthName[];
    static constexpr uint64_t kMonthNameHash = UINT64_C(8987927404178983737);
    SmartCharging& SetMonth(int64_t value);

    static const char kNumRecentKeyEventsName[];
    static constexpr uint64_t kNumRecentKeyEventsNameHash = UINT64_C(17517294973322255376);
    SmartCharging& SetNumRecentKeyEvents(int64_t value);

    static const char kNumRecentMouseEventsName[];
    static constexpr uint64_t kNumRecentMouseEventsNameHash = UINT64_C(6164169136009494499);
    SmartCharging& SetNumRecentMouseEvents(int64_t value);

    static const char kNumRecentStylusEventsName[];
    static constexpr uint64_t kNumRecentStylusEventsNameHash = UINT64_C(13185006921548112034);
    SmartCharging& SetNumRecentStylusEvents(int64_t value);

    static const char kNumRecentTouchEventsName[];
    static constexpr uint64_t kNumRecentTouchEventsNameHash = UINT64_C(14067961327568630776);
    SmartCharging& SetNumRecentTouchEvents(int64_t value);

    static const char kReasonName[];
    static constexpr uint64_t kReasonNameHash = UINT64_C(18445816987321669298);
    SmartCharging& SetReason(int64_t value);

    static const char kScreenBrightnessPercentName[];
    static constexpr uint64_t kScreenBrightnessPercentNameHash = UINT64_C(17633439285161136902);
    SmartCharging& SetScreenBrightnessPercent(int64_t value);

    static const char kTimeOfTheDayName[];
    static constexpr uint64_t kTimeOfTheDayNameHash = UINT64_C(12210633505613690203);
    SmartCharging& SetTimeOfTheDay(int64_t value);

    static const char kTimeSinceLastChargeName[];
    static constexpr uint64_t kTimeSinceLastChargeNameHash = UINT64_C(7810039360408170089);
    SmartCharging& SetTimeSinceLastCharge(int64_t value);

    static const char kTimezoneDifferenceFromLastChargeName[];
    static constexpr uint64_t kTimezoneDifferenceFromLastChargeNameHash = UINT64_C(9773033992964804237);
    SmartCharging& SetTimezoneDifferenceFromLastCharge(int64_t value);

    static const char kVoltageName[];
    static constexpr uint64_t kVoltageNameHash = UINT64_C(5373634262604211033);
    SmartCharging& SetVoltage(int64_t value);
};

class SMSReceiver final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SMSReceiver(ukm::SourceId source_id);
    explicit SMSReceiver(ukm::SourceIdObj source_id);
    SMSReceiver(SMSReceiver&&);
    SMSReceiver& operator=(SMSReceiver&&);
    ~SMSReceiver() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16019904587509461311);

    static const char kIsCrossOriginFrameName[];
    static constexpr uint64_t kIsCrossOriginFrameNameHash = UINT64_C(15054512686433939687);
    SMSReceiver& SetIsCrossOriginFrame(int64_t value);

    static const char kOutcomeName[];
    static constexpr uint64_t kOutcomeNameHash = UINT64_C(14948499774890759507);
    SMSReceiver& SetOutcome(int64_t value);

    static const char kSmsParsingStatusName[];
    static constexpr uint64_t kSmsParsingStatusNameHash = UINT64_C(4125092907764169982);
    SMSReceiver& SetSmsParsingStatus(int64_t value);

    static const char kTimeSmsReceiveMsName[];
    static constexpr uint64_t kTimeSmsReceiveMsNameHash = UINT64_C(16391606946531050381);
    SMSReceiver& SetTimeSmsReceiveMs(int64_t value);

    static const char kTimeSuccessMsName[];
    static constexpr uint64_t kTimeSuccessMsNameHash = UINT64_C(9257662670643133036);
    SMSReceiver& SetTimeSuccessMs(int64_t value);

    static const char kTimeUserCancelMsName[];
    static constexpr uint64_t kTimeUserCancelMsNameHash = UINT64_C(14753884043687476374);
    SMSReceiver& SetTimeUserCancelMs(int64_t value);
};

class SoftNavigation final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SoftNavigation(ukm::SourceId source_id);
    explicit SoftNavigation(ukm::SourceIdObj source_id);
    SoftNavigation(SoftNavigation&&);
    SoftNavigation& operator=(SoftNavigation&&);
    ~SoftNavigation() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15372023901254491137);

    static const char kInteractiveTiming_INPOffsetName[];
    static constexpr uint64_t kInteractiveTiming_INPOffsetNameHash = UINT64_C(8979497468537936367);
    SoftNavigation& SetInteractiveTiming_INPOffset(int64_t value);

    static const char kInteractiveTiming_INPTimeName[];
    static constexpr uint64_t kInteractiveTiming_INPTimeNameHash = UINT64_C(7682789371897203313);
    SoftNavigation& SetInteractiveTiming_INPTime(int64_t value);

    static const char kInteractiveTiming_NumInteractionsName[];
    static constexpr uint64_t kInteractiveTiming_NumInteractionsNameHash = UINT64_C(11809849059952828483);
    SoftNavigation& SetInteractiveTiming_NumInteractions(int64_t value);

    static const char kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[];
    static constexpr uint64_t kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash = UINT64_C(10840313540306654437);
    SoftNavigation& SetInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value);

    static const char kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[];
    static constexpr uint64_t kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash = UINT64_C(10830469890257014133);
    SoftNavigation& SetLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value);

    static const char kNavigationIdName[];
    static constexpr uint64_t kNavigationIdNameHash = UINT64_C(5550036704566686282);
    SoftNavigation& SetNavigationId(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintNameHash = UINT64_C(14563256248043352612);
    SoftNavigation& SetPaintTiming_LargestContentfulPaint(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintBPPName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintBPPNameHash = UINT64_C(6973221327096189893);
    SoftNavigation& SetPaintTiming_LargestContentfulPaintBPP(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageDiscoveryTimeName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageDiscoveryTimeNameHash = UINT64_C(6951457103621142193);
    SoftNavigation& SetPaintTiming_LargestContentfulPaintImageDiscoveryTime(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageLoadEndName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageLoadEndNameHash = UINT64_C(12897333331469387965);
    SoftNavigation& SetPaintTiming_LargestContentfulPaintImageLoadEnd(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintImageLoadStartName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintImageLoadStartNameHash = UINT64_C(10768298899277068506);
    SoftNavigation& SetPaintTiming_LargestContentfulPaintImageLoadStart(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintRequestPriorityName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintRequestPriorityNameHash = UINT64_C(17986969397849841);
    SoftNavigation& SetPaintTiming_LargestContentfulPaintRequestPriority(int64_t value);

    static const char kPaintTiming_LargestContentfulPaintTypeName[];
    static constexpr uint64_t kPaintTiming_LargestContentfulPaintTypeNameHash = UINT64_C(7824526725138222267);
    SoftNavigation& SetPaintTiming_LargestContentfulPaintType(int64_t value);

    static const char kStartTimeName[];
    static constexpr uint64_t kStartTimeNameHash = UINT64_C(10676292628526786927);
    SoftNavigation& SetStartTime(int64_t value);
};

class SubresourceFilter final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SubresourceFilter(ukm::SourceId source_id);
    explicit SubresourceFilter(ukm::SourceIdObj source_id);
    SubresourceFilter(SubresourceFilter&&);
    SubresourceFilter& operator=(SubresourceFilter&&);
    ~SubresourceFilter() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16234573202714536926);

    static const char kActivationDecisionName[];
    static constexpr uint64_t kActivationDecisionNameHash = UINT64_C(8340568698825149996);
    SubresourceFilter& SetActivationDecision(int64_t value);

    static const char kDryRunName[];
    static constexpr uint64_t kDryRunNameHash = UINT64_C(15305931645510130195);
    SubresourceFilter& SetDryRun(int64_t value);

    static const char kEnforcementRedirectPositionName[];
    static constexpr uint64_t kEnforcementRedirectPositionNameHash = UINT64_C(17469729262836585913);
    SubresourceFilter& SetEnforcementRedirectPosition(int64_t value);
};

class SubresourceLoad_ZstdContentEncoding final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SubresourceLoad_ZstdContentEncoding(ukm::SourceId source_id);
    explicit SubresourceLoad_ZstdContentEncoding(ukm::SourceIdObj source_id);
    SubresourceLoad_ZstdContentEncoding(SubresourceLoad_ZstdContentEncoding&&);
    SubresourceLoad_ZstdContentEncoding& operator=(SubresourceLoad_ZstdContentEncoding&&);
    ~SubresourceLoad_ZstdContentEncoding() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8817849481731339059);

    static const char kUsedZstdName[];
    static constexpr uint64_t kUsedZstdNameHash = UINT64_C(2287008842715863406);
    SubresourceLoad_ZstdContentEncoding& SetUsedZstd(int64_t value);
};

class SubresourceRedirect_PublicSrcVideoCompression final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit SubresourceRedirect_PublicSrcVideoCompression(ukm::SourceId source_id);
    explicit SubresourceRedirect_PublicSrcVideoCompression(ukm::SourceIdObj source_id);
    SubresourceRedirect_PublicSrcVideoCompression(SubresourceRedirect_PublicSrcVideoCompression&&);
    SubresourceRedirect_PublicSrcVideoCompression& operator=(SubresourceRedirect_PublicSrcVideoCompression&&);
    ~SubresourceRedirect_PublicSrcVideoCompression() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7915254855590561221);

    static const char kFullContentLengthName[];
    static constexpr uint64_t kFullContentLengthNameHash = UINT64_C(14828913975901463864);
    SubresourceRedirect_PublicSrcVideoCompression& SetFullContentLength(int64_t value);

    static const char kSubresourceRedirectResultName[];
    static constexpr uint64_t kSubresourceRedirectResultNameHash = UINT64_C(13633285177088868590);
    SubresourceRedirect_PublicSrcVideoCompression& SetSubresourceRedirectResult(int64_t value);
};

class Tab_Screenshot final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Tab_Screenshot(ukm::SourceId source_id);
    explicit Tab_Screenshot(ukm::SourceIdObj source_id);
    Tab_Screenshot(Tab_Screenshot&&);
    Tab_Screenshot& operator=(Tab_Screenshot&&);
    ~Tab_Screenshot() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4107587426159302168);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    Tab_Screenshot& SetHasOccurred(int64_t value);
};

class TabManager_Background_FirstAlertFired final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Background_FirstAlertFired(ukm::SourceId source_id);
    explicit TabManager_Background_FirstAlertFired(ukm::SourceIdObj source_id);
    TabManager_Background_FirstAlertFired(TabManager_Background_FirstAlertFired&&);
    TabManager_Background_FirstAlertFired& operator=(TabManager_Background_FirstAlertFired&&);
    ~TabManager_Background_FirstAlertFired() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6962158576008124011);

    static const char kIsMainFrameName[];
    static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
    TabManager_Background_FirstAlertFired& SetIsMainFrame(int64_t value);

    static const char kTimeFromBackgroundedName[];
    static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
    TabManager_Background_FirstAlertFired& SetTimeFromBackgrounded(int64_t value);
};

class TabManager_Background_FirstAudioStarts final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Background_FirstAudioStarts(ukm::SourceId source_id);
    explicit TabManager_Background_FirstAudioStarts(ukm::SourceIdObj source_id);
    TabManager_Background_FirstAudioStarts(TabManager_Background_FirstAudioStarts&&);
    TabManager_Background_FirstAudioStarts& operator=(TabManager_Background_FirstAudioStarts&&);
    ~TabManager_Background_FirstAudioStarts() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6253115585121265178);

    static const char kIsMainFrameName[];
    static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
    TabManager_Background_FirstAudioStarts& SetIsMainFrame(int64_t value);

    static const char kTimeFromBackgroundedName[];
    static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
    TabManager_Background_FirstAudioStarts& SetTimeFromBackgrounded(int64_t value);
};

class TabManager_Background_FirstFaviconUpdated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Background_FirstFaviconUpdated(ukm::SourceId source_id);
    explicit TabManager_Background_FirstFaviconUpdated(ukm::SourceIdObj source_id);
    TabManager_Background_FirstFaviconUpdated(TabManager_Background_FirstFaviconUpdated&&);
    TabManager_Background_FirstFaviconUpdated& operator=(TabManager_Background_FirstFaviconUpdated&&);
    ~TabManager_Background_FirstFaviconUpdated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7684352713481018374);

    static const char kTimeFromBackgroundedName[];
    static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
    TabManager_Background_FirstFaviconUpdated& SetTimeFromBackgrounded(int64_t value);
};

class TabManager_Background_FirstNonPersistentNotificationCreated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Background_FirstNonPersistentNotificationCreated(ukm::SourceId source_id);
    explicit TabManager_Background_FirstNonPersistentNotificationCreated(ukm::SourceIdObj source_id);
    TabManager_Background_FirstNonPersistentNotificationCreated(TabManager_Background_FirstNonPersistentNotificationCreated&&);
    TabManager_Background_FirstNonPersistentNotificationCreated& operator=(TabManager_Background_FirstNonPersistentNotificationCreated&&);
    ~TabManager_Background_FirstNonPersistentNotificationCreated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5800172692978642430);

    static const char kIsMainFrameName[];
    static constexpr uint64_t kIsMainFrameNameHash = UINT64_C(7266626398784684486);
    TabManager_Background_FirstNonPersistentNotificationCreated& SetIsMainFrame(int64_t value);

    static const char kTimeFromBackgroundedName[];
    static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
    TabManager_Background_FirstNonPersistentNotificationCreated& SetTimeFromBackgrounded(int64_t value);
};

class TabManager_Background_FirstTitleUpdated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Background_FirstTitleUpdated(ukm::SourceId source_id);
    explicit TabManager_Background_FirstTitleUpdated(ukm::SourceIdObj source_id);
    TabManager_Background_FirstTitleUpdated(TabManager_Background_FirstTitleUpdated&&);
    TabManager_Background_FirstTitleUpdated& operator=(TabManager_Background_FirstTitleUpdated&&);
    ~TabManager_Background_FirstTitleUpdated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13224923626166210718);

    static const char kTimeFromBackgroundedName[];
    static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
    TabManager_Background_FirstTitleUpdated& SetTimeFromBackgrounded(int64_t value);
};

class TabManager_Background_ForegroundedOrClosed final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Background_ForegroundedOrClosed(ukm::SourceId source_id);
    explicit TabManager_Background_ForegroundedOrClosed(ukm::SourceIdObj source_id);
    TabManager_Background_ForegroundedOrClosed(TabManager_Background_ForegroundedOrClosed&&);
    TabManager_Background_ForegroundedOrClosed& operator=(TabManager_Background_ForegroundedOrClosed&&);
    ~TabManager_Background_ForegroundedOrClosed() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11823633373787678555);

    static const char kIsDiscardedName[];
    static constexpr uint64_t kIsDiscardedNameHash = UINT64_C(4545578590056105756);
    TabManager_Background_ForegroundedOrClosed& SetIsDiscarded(int64_t value);

    static const char kIsForegroundedName[];
    static constexpr uint64_t kIsForegroundedNameHash = UINT64_C(18321524612313682043);
    TabManager_Background_ForegroundedOrClosed& SetIsForegrounded(int64_t value);

    static const char kLabelIdName[];
    static constexpr uint64_t kLabelIdNameHash = UINT64_C(14578023310397047120);
    TabManager_Background_ForegroundedOrClosed& SetLabelId(int64_t value);

    static const char kTimeFromBackgroundedName[];
    static constexpr uint64_t kTimeFromBackgroundedNameHash = UINT64_C(11659621178387050072);
    TabManager_Background_ForegroundedOrClosed& SetTimeFromBackgrounded(int64_t value);
};

class TabManager_Experimental_SessionRestore_TabSwitchLoadStopped final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(ukm::SourceId source_id);
    explicit TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(ukm::SourceIdObj source_id);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(TabManager_Experimental_SessionRestore_TabSwitchLoadStopped&&);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& operator=(TabManager_Experimental_SessionRestore_TabSwitchLoadStopped&&);
    ~TabManager_Experimental_SessionRestore_TabSwitchLoadStopped() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10989149245696867796);

    static const char kSequenceIdName[];
    static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSequenceId(int64_t value);

    static const char kSessionRestoreSessionIdName[];
    static constexpr uint64_t kSessionRestoreSessionIdNameHash = UINT64_C(15125204540231964086);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSessionRestoreSessionId(int64_t value);

    static const char kSessionRestoreTabCountName[];
    static constexpr uint64_t kSessionRestoreTabCountNameHash = UINT64_C(17950866683835588578);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSessionRestoreTabCount(int64_t value);

    static const char kSystemTabCountName[];
    static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetSystemTabCount(int64_t value);

    static const char kTabSwitchLoadTimeName[];
    static constexpr uint64_t kTabSwitchLoadTimeNameHash = UINT64_C(10500091388990852613);
    TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& SetTabSwitchLoadTime(int64_t value);
};

class TabManager_LifecycleStateChange final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_LifecycleStateChange(ukm::SourceId source_id);
    explicit TabManager_LifecycleStateChange(ukm::SourceIdObj source_id);
    TabManager_LifecycleStateChange(TabManager_LifecycleStateChange&&);
    TabManager_LifecycleStateChange& operator=(TabManager_LifecycleStateChange&&);
    ~TabManager_LifecycleStateChange() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15361214325300303131);

    static const char kFailureGlobalDisallowlistName[];
    static constexpr uint64_t kFailureGlobalDisallowlistNameHash = UINT64_C(5136762638734763087);
    TabManager_LifecycleStateChange& SetFailureGlobalDisallowlist(int64_t value);

    static const char kFailureHeuristicAudioName[];
    static constexpr uint64_t kFailureHeuristicAudioNameHash = UINT64_C(12990459205506514618);
    TabManager_LifecycleStateChange& SetFailureHeuristicAudio(int64_t value);

    static const char kFailureHeuristicFaviconName[];
    static constexpr uint64_t kFailureHeuristicFaviconNameHash = UINT64_C(6690922114157445648);
    TabManager_LifecycleStateChange& SetFailureHeuristicFavicon(int64_t value);

    static const char kFailureHeuristicInsufficientObservationName[];
    static constexpr uint64_t kFailureHeuristicInsufficientObservationNameHash = UINT64_C(9049974075249313421);
    TabManager_LifecycleStateChange& SetFailureHeuristicInsufficientObservation(int64_t value);

    static const char kFailureHeuristicNotificationsName[];
    static constexpr uint64_t kFailureHeuristicNotificationsNameHash = UINT64_C(17387734332470541652);
    TabManager_LifecycleStateChange& SetFailureHeuristicNotifications(int64_t value);

    static const char kFailureHeuristicTitleName[];
    static constexpr uint64_t kFailureHeuristicTitleNameHash = UINT64_C(233030549471232823);
    TabManager_LifecycleStateChange& SetFailureHeuristicTitle(int64_t value);

    static const char kFailureLifecyclesEnterprisePolicyOptOutName[];
    static constexpr uint64_t kFailureLifecyclesEnterprisePolicyOptOutNameHash = UINT64_C(1568209932272358843);
    TabManager_LifecycleStateChange& SetFailureLifecyclesEnterprisePolicyOptOut(int64_t value);

    static const char kFailureLivePictureInPictureName[];
    static constexpr uint64_t kFailureLivePictureInPictureNameHash = UINT64_C(3881288826038066381);
    TabManager_LifecycleStateChange& SetFailureLivePictureInPicture(int64_t value);

    static const char kFailureLiveStateCapturingName[];
    static constexpr uint64_t kFailureLiveStateCapturingNameHash = UINT64_C(1746761367355389825);
    TabManager_LifecycleStateChange& SetFailureLiveStateCapturing(int64_t value);

    static const char kFailureLiveStateDesktopCaptureName[];
    static constexpr uint64_t kFailureLiveStateDesktopCaptureNameHash = UINT64_C(11836939473639691991);
    TabManager_LifecycleStateChange& SetFailureLiveStateDesktopCapture(int64_t value);

    static const char kFailureLiveStateDevToolsOpenName[];
    static constexpr uint64_t kFailureLiveStateDevToolsOpenNameHash = UINT64_C(12821716976590806522);
    TabManager_LifecycleStateChange& SetFailureLiveStateDevToolsOpen(int64_t value);

    static const char kFailureLiveStateExtensionDisallowedName[];
    static constexpr uint64_t kFailureLiveStateExtensionDisallowedNameHash = UINT64_C(14913603322702848559);
    TabManager_LifecycleStateChange& SetFailureLiveStateExtensionDisallowed(int64_t value);

    static const char kFailureLiveStateFormEntryName[];
    static constexpr uint64_t kFailureLiveStateFormEntryNameHash = UINT64_C(2603883520869794602);
    TabManager_LifecycleStateChange& SetFailureLiveStateFormEntry(int64_t value);

    static const char kFailureLiveStateHasNotificationsPermissionName[];
    static constexpr uint64_t kFailureLiveStateHasNotificationsPermissionNameHash = UINT64_C(702525710594214990);
    TabManager_LifecycleStateChange& SetFailureLiveStateHasNotificationsPermission(int64_t value);

    static const char kFailureLiveStateIsPDFName[];
    static constexpr uint64_t kFailureLiveStateIsPDFNameHash = UINT64_C(13057031957762159216);
    TabManager_LifecycleStateChange& SetFailureLiveStateIsPDF(int64_t value);

    static const char kFailureLiveStateMirroringName[];
    static constexpr uint64_t kFailureLiveStateMirroringNameHash = UINT64_C(12092063214704219593);
    TabManager_LifecycleStateChange& SetFailureLiveStateMirroring(int64_t value);

    static const char kFailureLiveStatePlayingAudioName[];
    static constexpr uint64_t kFailureLiveStatePlayingAudioNameHash = UINT64_C(10433273516404381618);
    TabManager_LifecycleStateChange& SetFailureLiveStatePlayingAudio(int64_t value);

    static const char kFailureLiveStateSharingBrowsingInstanceName[];
    static constexpr uint64_t kFailureLiveStateSharingBrowsingInstanceNameHash = UINT64_C(13716775964206616000);
    TabManager_LifecycleStateChange& SetFailureLiveStateSharingBrowsingInstance(int64_t value);

    static const char kFailureLiveStateUsingBluetoothName[];
    static constexpr uint64_t kFailureLiveStateUsingBluetoothNameHash = UINT64_C(16735747532167439663);
    TabManager_LifecycleStateChange& SetFailureLiveStateUsingBluetooth(int64_t value);

    static const char kFailureLiveStateUsingIndexedDBLockName[];
    static constexpr uint64_t kFailureLiveStateUsingIndexedDBLockNameHash = UINT64_C(4740449931443625670);
    TabManager_LifecycleStateChange& SetFailureLiveStateUsingIndexedDBLock(int64_t value);

    static const char kFailureLiveStateUsingWebLockName[];
    static constexpr uint64_t kFailureLiveStateUsingWebLockNameHash = UINT64_C(11583253983001039995);
    TabManager_LifecycleStateChange& SetFailureLiveStateUsingWebLock(int64_t value);

    static const char kFailureLiveStateUsingWebSocketsName[];
    static constexpr uint64_t kFailureLiveStateUsingWebSocketsNameHash = UINT64_C(9779613440513908570);
    TabManager_LifecycleStateChange& SetFailureLiveStateUsingWebSockets(int64_t value);

    static const char kFailureLiveStateUsingWebUSBName[];
    static constexpr uint64_t kFailureLiveStateUsingWebUSBNameHash = UINT64_C(1264204074714928849);
    TabManager_LifecycleStateChange& SetFailureLiveStateUsingWebUSB(int64_t value);

    static const char kFailureLiveStateVisibleName[];
    static constexpr uint64_t kFailureLiveStateVisibleNameHash = UINT64_C(17796621035327630907);
    TabManager_LifecycleStateChange& SetFailureLiveStateVisible(int64_t value);

    static const char kFailureLiveWebAppName[];
    static constexpr uint64_t kFailureLiveWebAppNameHash = UINT64_C(17972142833607591150);
    TabManager_LifecycleStateChange& SetFailureLiveWebApp(int64_t value);

    static const char kFailureOriginTrialOptOutName[];
    static constexpr uint64_t kFailureOriginTrialOptOutNameHash = UINT64_C(3117221559354080435);
    TabManager_LifecycleStateChange& SetFailureOriginTrialOptOut(int64_t value);

    static const char kFailureOriginTrialUnknownName[];
    static constexpr uint64_t kFailureOriginTrialUnknownNameHash = UINT64_C(7785929326711993984);
    TabManager_LifecycleStateChange& SetFailureOriginTrialUnknown(int64_t value);

    static const char kLifecycleStateChangeReasonName[];
    static constexpr uint64_t kLifecycleStateChangeReasonNameHash = UINT64_C(6890089423438918274);
    TabManager_LifecycleStateChange& SetLifecycleStateChangeReason(int64_t value);

    static const char kNewLifecycleStateName[];
    static constexpr uint64_t kNewLifecycleStateNameHash = UINT64_C(12484427846537283830);
    TabManager_LifecycleStateChange& SetNewLifecycleState(int64_t value);

    static const char kOldLifecycleStateName[];
    static constexpr uint64_t kOldLifecycleStateNameHash = UINT64_C(981152026490365644);
    TabManager_LifecycleStateChange& SetOldLifecycleState(int64_t value);

    static const char kOutcomeName[];
    static constexpr uint64_t kOutcomeNameHash = UINT64_C(14948499774890759507);
    TabManager_LifecycleStateChange& SetOutcome(int64_t value);

    static const char kSuccessGlobalAllowlistName[];
    static constexpr uint64_t kSuccessGlobalAllowlistNameHash = UINT64_C(10481902485029877045);
    TabManager_LifecycleStateChange& SetSuccessGlobalAllowlist(int64_t value);

    static const char kSuccessHeuristicName[];
    static constexpr uint64_t kSuccessHeuristicNameHash = UINT64_C(7282383856026303779);
    TabManager_LifecycleStateChange& SetSuccessHeuristic(int64_t value);

    static const char kSuccessOriginTrialOptInName[];
    static constexpr uint64_t kSuccessOriginTrialOptInNameHash = UINT64_C(16495340119938645034);
    TabManager_LifecycleStateChange& SetSuccessOriginTrialOptIn(int64_t value);

    static const char kTimeSinceNavigationMsName[];
    static constexpr uint64_t kTimeSinceNavigationMsNameHash = UINT64_C(3766804751933420871);
    TabManager_LifecycleStateChange& SetTimeSinceNavigationMs(int64_t value);

    static const char kTimeSinceVisibilityStateChangeMsName[];
    static constexpr uint64_t kTimeSinceVisibilityStateChangeMsNameHash = UINT64_C(18111893678766007520);
    TabManager_LifecycleStateChange& SetTimeSinceVisibilityStateChangeMs(int64_t value);

    static const char kTransitionForcedName[];
    static constexpr uint64_t kTransitionForcedNameHash = UINT64_C(18125642282066928712);
    TabManager_LifecycleStateChange& SetTransitionForced(int64_t value);

    static const char kVisibilityStateName[];
    static constexpr uint64_t kVisibilityStateNameHash = UINT64_C(14490984458414165309);
    TabManager_LifecycleStateChange& SetVisibilityState(int64_t value);
};

class TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceId source_id);
    explicit TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceIdObj source_id);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo&&);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& operator=(
        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo&&);
    ~TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(8999972273877232390);

    static const char kExpectedTaskQueueingDurationName[];
    static constexpr uint64_t kExpectedTaskQueueingDurationNameHash = UINT64_C(17505273149654010352);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetExpectedTaskQueueingDuration(int64_t value);

    static const char kSequenceIdName[];
    static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSequenceId(int64_t value);

    static const char kSessionRestoreSessionIdName[];
    static constexpr uint64_t kSessionRestoreSessionIdNameHash = UINT64_C(15125204540231964086);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSessionRestoreSessionId(int64_t value);

    static const char kSessionRestoreTabCountName[];
    static constexpr uint64_t kSessionRestoreTabCountNameHash = UINT64_C(17950866683835588578);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSessionRestoreTabCount(int64_t value);

    static const char kSystemTabCountName[];
    static constexpr uint64_t kSystemTabCountNameHash = UINT64_C(14205160604226729773);
    TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& SetSystemTabCount(int64_t value);
};

class TabManager_TabLifetime final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_TabLifetime(ukm::SourceId source_id);
    explicit TabManager_TabLifetime(ukm::SourceIdObj source_id);
    TabManager_TabLifetime(TabManager_TabLifetime&&);
    TabManager_TabLifetime& operator=(TabManager_TabLifetime&&);
    ~TabManager_TabLifetime() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16307465990132225428);

    static const char kTimeSinceNavigationName[];
    static constexpr uint64_t kTimeSinceNavigationNameHash = UINT64_C(18199427499238622919);
    TabManager_TabLifetime& SetTimeSinceNavigation(int64_t value);
};

class TabManager_WindowMetrics final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabManager_WindowMetrics(ukm::SourceId source_id);
    explicit TabManager_WindowMetrics(ukm::SourceIdObj source_id);
    TabManager_WindowMetrics(TabManager_WindowMetrics&&);
    TabManager_WindowMetrics& operator=(TabManager_WindowMetrics&&);
    ~TabManager_WindowMetrics() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12562637272871338124);

    static const char kIsActiveName[];
    static constexpr uint64_t kIsActiveNameHash = UINT64_C(145730663672890399);
    TabManager_WindowMetrics& SetIsActive(int64_t value);

    static const char kShowStateName[];
    static constexpr uint64_t kShowStateNameHash = UINT64_C(6352664330247173052);
    TabManager_WindowMetrics& SetShowState(int64_t value);

    static const char kTabCountName[];
    static constexpr uint64_t kTabCountNameHash = UINT64_C(1513537862956601777);
    TabManager_WindowMetrics& SetTabCount(int64_t value);

    static const char kTypeName[];
    static constexpr uint64_t kTypeNameHash = UINT64_C(11671684778792498320);
    TabManager_WindowMetrics& SetType(int64_t value);

    static const char kWindowIdName[];
    static constexpr uint64_t kWindowIdNameHash = UINT64_C(2294382318193398891);
    TabManager_WindowMetrics& SetWindowId(int64_t value);
};

class TabRevisitTracker_TabStateChange final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabRevisitTracker_TabStateChange(ukm::SourceId source_id);
    explicit TabRevisitTracker_TabStateChange(ukm::SourceIdObj source_id);
    TabRevisitTracker_TabStateChange(TabRevisitTracker_TabStateChange&&);
    TabRevisitTracker_TabStateChange& operator=(TabRevisitTracker_TabStateChange&&);
    ~TabRevisitTracker_TabStateChange() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14351343629891097333);

    static const char kNewStateName[];
    static constexpr uint64_t kNewStateNameHash = UINT64_C(16927213407085882218);
    TabRevisitTracker_TabStateChange& SetNewState(int64_t value);

    static const char kNumTabsOnSameUrlName[];
    static constexpr uint64_t kNumTabsOnSameUrlNameHash = UINT64_C(16036984480190398342);
    TabRevisitTracker_TabStateChange& SetNumTabsOnSameUrl(int64_t value);

    static const char kNumTotalRevisitsName[];
    static constexpr uint64_t kNumTotalRevisitsNameHash = UINT64_C(10999342970937850703);
    TabRevisitTracker_TabStateChange& SetNumTotalRevisits(int64_t value);

    static const char kPreviousStateName[];
    static constexpr uint64_t kPreviousStateNameHash = UINT64_C(10053598155519825992);
    TabRevisitTracker_TabStateChange& SetPreviousState(int64_t value);

    static const char kSameTabGroupAsActiveTabName[];
    static constexpr uint64_t kSameTabGroupAsActiveTabNameHash = UINT64_C(10708747309792194783);
    TabRevisitTracker_TabStateChange& SetSameTabGroupAsActiveTab(int64_t value);

    static const char kSameWindowAsActiveTabName[];
    static constexpr uint64_t kSameWindowAsActiveTabNameHash = UINT64_C(336811542393626423);
    TabRevisitTracker_TabStateChange& SetSameWindowAsActiveTab(int64_t value);

    static const char kTimeInPreviousStateName[];
    static constexpr uint64_t kTimeInPreviousStateNameHash = UINT64_C(13334321562393514720);
    TabRevisitTracker_TabStateChange& SetTimeInPreviousState(int64_t value);

    static const char kTotalTimeActiveName[];
    static constexpr uint64_t kTotalTimeActiveNameHash = UINT64_C(12700501389012301578);
    TabRevisitTracker_TabStateChange& SetTotalTimeActive(int64_t value);
};

class TabStripOrganization final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TabStripOrganization(ukm::SourceId source_id);
    explicit TabStripOrganization(ukm::SourceIdObj source_id);
    TabStripOrganization(TabStripOrganization&&);
    TabStripOrganization& operator=(TabStripOrganization&&);
    ~TabStripOrganization() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10784052616835854511);

    static const char kIsActiveTabName[];
    static constexpr uint64_t kIsActiveTabNameHash = UINT64_C(8605931901711618551);
    TabStripOrganization& SetIsActiveTab(int64_t value);

    static const char kMinutesSinceLastActiveName[];
    static constexpr uint64_t kMinutesSinceLastActiveNameHash = UINT64_C(8744377624979526069);
    TabStripOrganization& SetMinutesSinceLastActive(int64_t value);

    static const char kSuggestedTabStripOrganizationReasonName[];
    static constexpr uint64_t kSuggestedTabStripOrganizationReasonNameHash = UINT64_C(5123517627706061170);
    TabStripOrganization& SetSuggestedTabStripOrganizationReason(int64_t value);

    static const char kTabGroupIDName[];
    static constexpr uint64_t kTabGroupIDNameHash = UINT64_C(16890484122427900635);
    TabStripOrganization& SetTabGroupID(int64_t value);

    static const char kTabStripEventIDName[];
    static constexpr uint64_t kTabStripEventIDNameHash = UINT64_C(4765518592756464902);
    TabStripOrganization& SetTabStripEventID(int64_t value);
};

class ThirdPartyCookies_BreakageIndicator_HTTPError final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ThirdPartyCookies_BreakageIndicator_HTTPError(ukm::SourceId source_id);
    explicit ThirdPartyCookies_BreakageIndicator_HTTPError(ukm::SourceIdObj source_id);
    ThirdPartyCookies_BreakageIndicator_HTTPError(ThirdPartyCookies_BreakageIndicator_HTTPError&&);
    ThirdPartyCookies_BreakageIndicator_HTTPError& operator=(ThirdPartyCookies_BreakageIndicator_HTTPError&&);
    ~ThirdPartyCookies_BreakageIndicator_HTTPError() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9088201269784118104);

    static const char kTPCBlockedName[];
    static constexpr uint64_t kTPCBlockedNameHash = UINT64_C(5869361073952519652);
    ThirdPartyCookies_BreakageIndicator_HTTPError& SetTPCBlocked(int64_t value);

    static const char kTPCBlockedInSettingsName[];
    static constexpr uint64_t kTPCBlockedInSettingsNameHash = UINT64_C(6655776299050811376);
    ThirdPartyCookies_BreakageIndicator_HTTPError& SetTPCBlockedInSettings(int64_t value);
};

class ThirdPartyCookies_BreakageIndicator_UncaughtJSError final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ThirdPartyCookies_BreakageIndicator_UncaughtJSError(ukm::SourceId source_id);
    explicit ThirdPartyCookies_BreakageIndicator_UncaughtJSError(ukm::SourceIdObj source_id);
    ThirdPartyCookies_BreakageIndicator_UncaughtJSError(ThirdPartyCookies_BreakageIndicator_UncaughtJSError&&);
    ThirdPartyCookies_BreakageIndicator_UncaughtJSError& operator=(ThirdPartyCookies_BreakageIndicator_UncaughtJSError&&);
    ~ThirdPartyCookies_BreakageIndicator_UncaughtJSError() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15404660138221362264);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    ThirdPartyCookies_BreakageIndicator_UncaughtJSError& SetHasOccurred(int64_t value);
};

class ThirdPartyCookies_BreakageIndicator_UserReload final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ThirdPartyCookies_BreakageIndicator_UserReload(ukm::SourceId source_id);
    explicit ThirdPartyCookies_BreakageIndicator_UserReload(ukm::SourceIdObj source_id);
    ThirdPartyCookies_BreakageIndicator_UserReload(ThirdPartyCookies_BreakageIndicator_UserReload&&);
    ThirdPartyCookies_BreakageIndicator_UserReload& operator=(ThirdPartyCookies_BreakageIndicator_UserReload&&);
    ~ThirdPartyCookies_BreakageIndicator_UserReload() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(18163975266525876574);

    static const char kTPCBlockedName[];
    static constexpr uint64_t kTPCBlockedNameHash = UINT64_C(5869361073952519652);
    ThirdPartyCookies_BreakageIndicator_UserReload& SetTPCBlocked(int64_t value);

    static const char kTPCBlockedInSettingsName[];
    static constexpr uint64_t kTPCBlockedInSettingsNameHash = UINT64_C(6655776299050811376);
    ThirdPartyCookies_BreakageIndicator_UserReload& SetTPCBlockedInSettings(int64_t value);
};

class ThirdPartyCookies_CookieControlsActivated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ThirdPartyCookies_CookieControlsActivated(ukm::SourceId source_id);
    explicit ThirdPartyCookies_CookieControlsActivated(ukm::SourceIdObj source_id);
    ThirdPartyCookies_CookieControlsActivated(ThirdPartyCookies_CookieControlsActivated&&);
    ThirdPartyCookies_CookieControlsActivated& operator=(ThirdPartyCookies_CookieControlsActivated&&);
    ~ThirdPartyCookies_CookieControlsActivated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(14349625384099335005);

    static const char kFedCmInitiatedName[];
    static constexpr uint64_t kFedCmInitiatedNameHash = UINT64_C(17678449151949810138);
    ThirdPartyCookies_CookieControlsActivated& SetFedCmInitiated(int64_t value);

    static const char kPageRefreshCountName[];
    static constexpr uint64_t kPageRefreshCountNameHash = UINT64_C(2163896647111621911);
    ThirdPartyCookies_CookieControlsActivated& SetPageRefreshCount(int64_t value);

    static const char kRepeatedActivationName[];
    static constexpr uint64_t kRepeatedActivationNameHash = UINT64_C(10403098248320793951);
    ThirdPartyCookies_CookieControlsActivated& SetRepeatedActivation(int64_t value);

    static const char kSiteEngagementLevelName[];
    static constexpr uint64_t kSiteEngagementLevelNameHash = UINT64_C(7434896235365170565);
    ThirdPartyCookies_CookieControlsActivated& SetSiteEngagementLevel(int64_t value);

    static const char kStorageAccessAPIRequestedName[];
    static constexpr uint64_t kStorageAccessAPIRequestedNameHash = UINT64_C(10397463518195761233);
    ThirdPartyCookies_CookieControlsActivated& SetStorageAccessAPIRequested(int64_t value);

    static const char kThirdPartySiteDataAccessTypeName[];
    static constexpr uint64_t kThirdPartySiteDataAccessTypeNameHash = UINT64_C(10611877135598967650);
    ThirdPartyCookies_CookieControlsActivated& SetThirdPartySiteDataAccessType(int64_t value);
};

class ThirdPartyCookies_TopLevelDeprecationTrial final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit ThirdPartyCookies_TopLevelDeprecationTrial(ukm::SourceId source_id);
    explicit ThirdPartyCookies_TopLevelDeprecationTrial(ukm::SourceIdObj source_id);
    ThirdPartyCookies_TopLevelDeprecationTrial(ThirdPartyCookies_TopLevelDeprecationTrial&&);
    ThirdPartyCookies_TopLevelDeprecationTrial& operator=(ThirdPartyCookies_TopLevelDeprecationTrial&&);
    ~ThirdPartyCookies_TopLevelDeprecationTrial() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(9317168121841018666);

    static const char kEnabledName[];
    static constexpr uint64_t kEnabledNameHash = UINT64_C(59174027418879706);
    ThirdPartyCookies_TopLevelDeprecationTrial& SetEnabled(int64_t value);

    static const char kMatchSubdomainsName[];
    static constexpr uint64_t kMatchSubdomainsNameHash = UINT64_C(3461548325568190315);
    ThirdPartyCookies_TopLevelDeprecationTrial& SetMatchSubdomains(int64_t value);
};

class TopToolbar_Share final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TopToolbar_Share(ukm::SourceId source_id);
    explicit TopToolbar_Share(ukm::SourceIdObj source_id);
    TopToolbar_Share(TopToolbar_Share&&);
    TopToolbar_Share& operator=(TopToolbar_Share&&);
    ~TopToolbar_Share() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4093974732248698099);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    TopToolbar_Share& SetHasOccurred(int64_t value);
};

class TouchToFill_Shown final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TouchToFill_Shown(ukm::SourceId source_id);
    explicit TouchToFill_Shown(ukm::SourceIdObj source_id);
    TouchToFill_Shown(TouchToFill_Shown&&);
    TouchToFill_Shown& operator=(TouchToFill_Shown&&);
    ~TouchToFill_Shown() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(833305494688204602);

    static const char kUserActionName[];
    static constexpr uint64_t kUserActionNameHash = UINT64_C(11431707273815549887);
    TouchToFill_Shown& SetUserAction(int64_t value);
};

class TouchToFill_SubmissionReadiness final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TouchToFill_SubmissionReadiness(ukm::SourceId source_id);
    explicit TouchToFill_SubmissionReadiness(ukm::SourceIdObj source_id);
    TouchToFill_SubmissionReadiness(TouchToFill_SubmissionReadiness&&);
    TouchToFill_SubmissionReadiness& operator=(TouchToFill_SubmissionReadiness&&);
    ~TouchToFill_SubmissionReadiness() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11228777951422985451);

    static const char kSubmissionReadinessName[];
    static constexpr uint64_t kSubmissionReadinessNameHash = UINT64_C(15534096632074932867);
    TouchToFill_SubmissionReadiness& SetSubmissionReadiness(int64_t value);
};

class TouchToFill_TimeToSuccessfulLogin final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TouchToFill_TimeToSuccessfulLogin(ukm::SourceId source_id);
    explicit TouchToFill_TimeToSuccessfulLogin(ukm::SourceIdObj source_id);
    TouchToFill_TimeToSuccessfulLogin(TouchToFill_TimeToSuccessfulLogin&&);
    TouchToFill_TimeToSuccessfulLogin& operator=(TouchToFill_TimeToSuccessfulLogin&&);
    ~TouchToFill_TimeToSuccessfulLogin() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5045482485607039969);

    static const char kTimeToSuccessfulLoginName[];
    static constexpr uint64_t kTimeToSuccessfulLoginNameHash = UINT64_C(17289330177927910299);
    TouchToFill_TimeToSuccessfulLogin& SetTimeToSuccessfulLogin(int64_t value);
};

class Tpcd_Mitigations_Dt_FirstParty_Deployment2 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Tpcd_Mitigations_Dt_FirstParty_Deployment2(ukm::SourceId source_id);
    explicit Tpcd_Mitigations_Dt_FirstParty_Deployment2(ukm::SourceIdObj source_id);
    Tpcd_Mitigations_Dt_FirstParty_Deployment2(Tpcd_Mitigations_Dt_FirstParty_Deployment2&&);
    Tpcd_Mitigations_Dt_FirstParty_Deployment2& operator=(Tpcd_Mitigations_Dt_FirstParty_Deployment2&&);
    ~Tpcd_Mitigations_Dt_FirstParty_Deployment2() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16389532164977706082);

    static const char kDeployedName[];
    static constexpr uint64_t kDeployedNameHash = UINT64_C(16904300166993283328);
    Tpcd_Mitigations_Dt_FirstParty_Deployment2& SetDeployed(int64_t value);
};

class Translate final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Translate(ukm::SourceId source_id);
    explicit Translate(ukm::SourceIdObj source_id);
    Translate(Translate&&);
    Translate& operator=(Translate&&);
    ~Translate() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16054416016310256565);

    static const char kAcceptCountName[];
    static constexpr uint64_t kAcceptCountNameHash = UINT64_C(8502235306677298033);
    Translate& SetAcceptCount(int64_t value);

    static const char kCountryName[];
    static constexpr uint64_t kCountryNameHash = UINT64_C(6445051938772793705);
    Translate& SetCountry(int64_t value);

    static const char kDeclineCountName[];
    static constexpr uint64_t kDeclineCountNameHash = UINT64_C(3180238090454488835);
    Translate& SetDeclineCount(int64_t value);

    static const char kEventTypeName[];
    static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
    Translate& SetEventType(int64_t value);

    static const char kIgnoreCountName[];
    static constexpr uint64_t kIgnoreCountNameHash = UINT64_C(14896378584437100759);
    Translate& SetIgnoreCount(int64_t value);

    static const char kRankerResponseName[];
    static constexpr uint64_t kRankerResponseNameHash = UINT64_C(6404631249487430957);
    Translate& SetRankerResponse(int64_t value);

    static const char kRankerVersionName[];
    static constexpr uint64_t kRankerVersionNameHash = UINT64_C(10214100949042673155);
    Translate& SetRankerVersion(int64_t value);

    static const char kSourceLanguageName[];
    static constexpr uint64_t kSourceLanguageNameHash = UINT64_C(15558163265405593795);
    Translate& SetSourceLanguage(int64_t value);

    static const char kTargetLanguageName[];
    static constexpr uint64_t kTargetLanguageNameHash = UINT64_C(8387451134401416124);
    Translate& SetTargetLanguage(int64_t value);
};

class TranslatePageLoad final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TranslatePageLoad(ukm::SourceId source_id);
    explicit TranslatePageLoad(ukm::SourceIdObj source_id);
    TranslatePageLoad(TranslatePageLoad&&);
    TranslatePageLoad& operator=(TranslatePageLoad&&);
    ~TranslatePageLoad() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5132773550783566872);

    static const char kFinalSourceLanguageName[];
    static constexpr uint64_t kFinalSourceLanguageNameHash = UINT64_C(4529763736522651943);
    TranslatePageLoad& SetFinalSourceLanguage(int64_t value);

    static const char kFinalStateName[];
    static constexpr uint64_t kFinalStateNameHash = UINT64_C(7135263041449206789);
    TranslatePageLoad& SetFinalState(int64_t value);

    static const char kFinalTargetLanguageName[];
    static constexpr uint64_t kFinalTargetLanguageNameHash = UINT64_C(11635918129757845831);
    TranslatePageLoad& SetFinalTargetLanguage(int64_t value);

    static const char kFirstTranslateErrorName[];
    static constexpr uint64_t kFirstTranslateErrorNameHash = UINT64_C(9217305282984928754);
    TranslatePageLoad& SetFirstTranslateError(int64_t value);

    static const char kFirstUIInteractionName[];
    static constexpr uint64_t kFirstUIInteractionNameHash = UINT64_C(5333453377518935190);
    TranslatePageLoad& SetFirstUIInteraction(int64_t value);

    static const char kHTMLContentLanguageName[];
    static constexpr uint64_t kHTMLContentLanguageNameHash = UINT64_C(8650073884862724155);
    TranslatePageLoad& SetHTMLContentLanguage(int64_t value);

    static const char kHTMLDocumentLanguageName[];
    static constexpr uint64_t kHTMLDocumentLanguageNameHash = UINT64_C(1123472852488583155);
    TranslatePageLoad& SetHTMLDocumentLanguage(int64_t value);

    static const char kInitialSourceLanguageName[];
    static constexpr uint64_t kInitialSourceLanguageNameHash = UINT64_C(1748637677338247218);
    TranslatePageLoad& SetInitialSourceLanguage(int64_t value);

    static const char kInitialSourceLanguageInContentLanguagesName[];
    static constexpr uint64_t kInitialSourceLanguageInContentLanguagesNameHash = UINT64_C(15478995535112255720);
    TranslatePageLoad& SetInitialSourceLanguageInContentLanguages(int64_t value);

    static const char kInitialStateName[];
    static constexpr uint64_t kInitialStateNameHash = UINT64_C(5039075195775411013);
    TranslatePageLoad& SetInitialState(int64_t value);

    static const char kInitialTargetLanguageName[];
    static constexpr uint64_t kInitialTargetLanguageNameHash = UINT64_C(9950279908379302836);
    TranslatePageLoad& SetInitialTargetLanguage(int64_t value);

    static const char kMaxTimeToTranslateName[];
    static constexpr uint64_t kMaxTimeToTranslateNameHash = UINT64_C(5466715943086141121);
    TranslatePageLoad& SetMaxTimeToTranslate(int64_t value);

    static const char kModelDetectedLanguageName[];
    static constexpr uint64_t kModelDetectedLanguageNameHash = UINT64_C(10873817195833485122);
    TranslatePageLoad& SetModelDetectedLanguage(int64_t value);

    static const char kModelDetectionReliabilityScoreName[];
    static constexpr uint64_t kModelDetectionReliabilityScoreNameHash = UINT64_C(3850870539894823708);
    TranslatePageLoad& SetModelDetectionReliabilityScore(int64_t value);

    static const char kNumReversionsName[];
    static constexpr uint64_t kNumReversionsNameHash = UINT64_C(8879971234798289294);
    TranslatePageLoad& SetNumReversions(int64_t value);

    static const char kNumTargetLanguageChangesName[];
    static constexpr uint64_t kNumTargetLanguageChangesNameHash = UINT64_C(101486262262552452);
    TranslatePageLoad& SetNumTargetLanguageChanges(int64_t value);

    static const char kNumTranslateErrorsName[];
    static constexpr uint64_t kNumTranslateErrorsNameHash = UINT64_C(14452703580979390282);
    TranslatePageLoad& SetNumTranslateErrors(int64_t value);

    static const char kNumTranslationsName[];
    static constexpr uint64_t kNumTranslationsNameHash = UINT64_C(4361453967272288793);
    TranslatePageLoad& SetNumTranslations(int64_t value);

    static const char kNumUIInteractionsName[];
    static constexpr uint64_t kNumUIInteractionsNameHash = UINT64_C(15600244326894550238);
    TranslatePageLoad& SetNumUIInteractions(int64_t value);

    static const char kRankerDecisionName[];
    static constexpr uint64_t kRankerDecisionNameHash = UINT64_C(1785216550039030435);
    TranslatePageLoad& SetRankerDecision(int64_t value);

    static const char kRankerVersionName[];
    static constexpr uint64_t kRankerVersionNameHash = UINT64_C(10214100949042673155);
    TranslatePageLoad& SetRankerVersion(int64_t value);

    static const char kSequenceNumberName[];
    static constexpr uint64_t kSequenceNumberNameHash = UINT64_C(3161886034278201905);
    TranslatePageLoad& SetSequenceNumber(int64_t value);

    static const char kTotalTimeNotTranslatedName[];
    static constexpr uint64_t kTotalTimeNotTranslatedNameHash = UINT64_C(12102707435315222782);
    TranslatePageLoad& SetTotalTimeNotTranslated(int64_t value);

    static const char kTotalTimeTranslatedName[];
    static constexpr uint64_t kTotalTimeTranslatedNameHash = UINT64_C(12691422260267431211);
    TranslatePageLoad& SetTotalTimeTranslated(int64_t value);

    static const char kTriggerDecisionName[];
    static constexpr uint64_t kTriggerDecisionNameHash = UINT64_C(16712599622372961266);
    TranslatePageLoad& SetTriggerDecision(int64_t value);

    static const char kWasContentEmptyName[];
    static constexpr uint64_t kWasContentEmptyNameHash = UINT64_C(9985474292476142427);
    TranslatePageLoad& SetWasContentEmpty(int64_t value);
};

class TrustedWebActivity_Open final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit TrustedWebActivity_Open(ukm::SourceId source_id);
    explicit TrustedWebActivity_Open(ukm::SourceIdObj source_id);
    TrustedWebActivity_Open(TrustedWebActivity_Open&&);
    TrustedWebActivity_Open& operator=(TrustedWebActivity_Open&&);
    ~TrustedWebActivity_Open() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15381255782093849665);

    static const char kHasOccurredName[];
    static constexpr uint64_t kHasOccurredNameHash = UINT64_C(1401967873843414280);
    TrustedWebActivity_Open& SetHasOccurred(int64_t value);
};

class Unload final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Unload(ukm::SourceId source_id);
    explicit Unload(ukm::SourceIdObj source_id);
    Unload(Unload&&);
    Unload& operator=(Unload&&);
    ~Unload() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12543039456478655125);

    static const char kBeforeUnloadDurationName[];
    static constexpr uint64_t kBeforeUnloadDurationNameHash = UINT64_C(17514078638441036700);
    Unload& SetBeforeUnloadDuration(int64_t value);

    static const char kBeforeUnloadQueueingDurationName[];
    static constexpr uint64_t kBeforeUnloadQueueingDurationNameHash = UINT64_C(190303907733053448);
    Unload& SetBeforeUnloadQueueingDuration(int64_t value);

    static const char kBeforeUnloadToCommit_CrossProcessName[];
    static constexpr uint64_t kBeforeUnloadToCommit_CrossProcessNameHash = UINT64_C(10234660141419785991);
    Unload& SetBeforeUnloadToCommit_CrossProcess(int64_t value);

    static const char kBeforeUnloadToCommit_SameProcessName[];
    static constexpr uint64_t kBeforeUnloadToCommit_SameProcessNameHash = UINT64_C(15691758345441892775);
    Unload& SetBeforeUnloadToCommit_SameProcess(int64_t value);

    static const char kUnloadDurationName[];
    static constexpr uint64_t kUnloadDurationNameHash = UINT64_C(18131939346052404675);
    Unload& SetUnloadDuration(int64_t value);

    static const char kUnloadQueueingDurationName[];
    static constexpr uint64_t kUnloadQueueingDurationNameHash = UINT64_C(11457635214080296079);
    Unload& SetUnloadQueueingDuration(int64_t value);
};

class UserActivity final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit UserActivity(ukm::SourceId source_id);
    explicit UserActivity(ukm::SourceIdObj source_id);
    UserActivity(UserActivity&&);
    UserActivity& operator=(UserActivity&&);
    ~UserActivity() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2395897864454822590);

    static const char kBatteryPercentName[];
    static constexpr uint64_t kBatteryPercentNameHash = UINT64_C(3434325767059222004);
    UserActivity& SetBatteryPercent(int64_t value);

    static const char kDeviceManagementName[];
    static constexpr uint64_t kDeviceManagementNameHash = UINT64_C(3879735998068387644);
    UserActivity& SetDeviceManagement(int64_t value);

    static const char kDeviceModeName[];
    static constexpr uint64_t kDeviceModeNameHash = UINT64_C(17552034499290033273);
    UserActivity& SetDeviceMode(int64_t value);

    static const char kDeviceTypeName[];
    static constexpr uint64_t kDeviceTypeNameHash = UINT64_C(7795620498098931292);
    UserActivity& SetDeviceType(int64_t value);

    static const char kEventLogDurationName[];
    static constexpr uint64_t kEventLogDurationNameHash = UINT64_C(9294112700816090959);
    UserActivity& SetEventLogDuration(int64_t value);

    static const char kEventReasonName[];
    static constexpr uint64_t kEventReasonNameHash = UINT64_C(16835794410928463032);
    UserActivity& SetEventReason(int64_t value);

    static const char kEventTypeName[];
    static constexpr uint64_t kEventTypeNameHash = UINT64_C(5446425777535537951);
    UserActivity& SetEventType(int64_t value);

    static const char kKeyEventsInLastHourName[];
    static constexpr uint64_t kKeyEventsInLastHourNameHash = UINT64_C(11299844146219290596);
    UserActivity& SetKeyEventsInLastHour(int64_t value);

    static const char kLastActivityDayName[];
    static constexpr uint64_t kLastActivityDayNameHash = UINT64_C(14339230944188901365);
    UserActivity& SetLastActivityDay(int64_t value);

    static const char kLastActivityTimeName[];
    static constexpr uint64_t kLastActivityTimeNameHash = UINT64_C(14831110523312780762);
    UserActivity& SetLastActivityTime(int64_t value);

    static const char kLastUserActivityTimeName[];
    static constexpr uint64_t kLastUserActivityTimeNameHash = UINT64_C(8788245832941149939);
    UserActivity& SetLastUserActivityTime(int64_t value);

    static const char kModelAppliedName[];
    static constexpr uint64_t kModelAppliedNameHash = UINT64_C(6801141381231795082);
    UserActivity& SetModelApplied(int64_t value);

    static const char kModelDecisionThresholdName[];
    static constexpr uint64_t kModelDecisionThresholdNameHash = UINT64_C(16615553209600420827);
    UserActivity& SetModelDecisionThreshold(int64_t value);

    static const char kModelInactivityScoreName[];
    static constexpr uint64_t kModelInactivityScoreNameHash = UINT64_C(1730033542070367675);
    UserActivity& SetModelInactivityScore(int64_t value);

    static const char kModelResponseName[];
    static constexpr uint64_t kModelResponseNameHash = UINT64_C(972970836639660541);
    UserActivity& SetModelResponse(int64_t value);

    static const char kMouseEventsInLastHourName[];
    static constexpr uint64_t kMouseEventsInLastHourNameHash = UINT64_C(11835042666579861839);
    UserActivity& SetMouseEventsInLastHour(int64_t value);

    static const char kOnBatteryName[];
    static constexpr uint64_t kOnBatteryNameHash = UINT64_C(9497943841916154435);
    UserActivity& SetOnBattery(int64_t value);

    static const char kPreviousNegativeActionsCountName[];
    static constexpr uint64_t kPreviousNegativeActionsCountNameHash = UINT64_C(17834864132047931181);
    UserActivity& SetPreviousNegativeActionsCount(int64_t value);

    static const char kPreviousPositiveActionsCountName[];
    static constexpr uint64_t kPreviousPositiveActionsCountNameHash = UINT64_C(6191193929978136769);
    UserActivity& SetPreviousPositiveActionsCount(int64_t value);

    static const char kRecentTimeActiveName[];
    static constexpr uint64_t kRecentTimeActiveNameHash = UINT64_C(14147624997432742521);
    UserActivity& SetRecentTimeActive(int64_t value);

    static const char kRecentVideoPlayingTimeName[];
    static constexpr uint64_t kRecentVideoPlayingTimeNameHash = UINT64_C(13380566763432764429);
    UserActivity& SetRecentVideoPlayingTime(int64_t value);

    static const char kScreenDimDelayName[];
    static constexpr uint64_t kScreenDimDelayNameHash = UINT64_C(16833327722358108459);
    UserActivity& SetScreenDimDelay(int64_t value);

    static const char kScreenDimmedInitiallyName[];
    static constexpr uint64_t kScreenDimmedInitiallyNameHash = UINT64_C(10179091906473872128);
    UserActivity& SetScreenDimmedInitially(int64_t value);

    static const char kScreenDimOccurredName[];
    static constexpr uint64_t kScreenDimOccurredNameHash = UINT64_C(9781953209119865440);
    UserActivity& SetScreenDimOccurred(int64_t value);

    static const char kScreenDimToOffDelayName[];
    static constexpr uint64_t kScreenDimToOffDelayNameHash = UINT64_C(6534684685018748413);
    UserActivity& SetScreenDimToOffDelay(int64_t value);

    static const char kScreenLockedInitiallyName[];
    static constexpr uint64_t kScreenLockedInitiallyNameHash = UINT64_C(17101958306385581732);
    UserActivity& SetScreenLockedInitially(int64_t value);

    static const char kScreenLockOccurredName[];
    static constexpr uint64_t kScreenLockOccurredNameHash = UINT64_C(15627670727691026054);
    UserActivity& SetScreenLockOccurred(int64_t value);

    static const char kScreenOffInitiallyName[];
    static constexpr uint64_t kScreenOffInitiallyNameHash = UINT64_C(7660996110440871532);
    UserActivity& SetScreenOffInitially(int64_t value);

    static const char kScreenOffOccurredName[];
    static constexpr uint64_t kScreenOffOccurredNameHash = UINT64_C(2742307602633466727);
    UserActivity& SetScreenOffOccurred(int64_t value);

    static const char kSequenceIdName[];
    static constexpr uint64_t kSequenceIdNameHash = UINT64_C(8860601784949375835);
    UserActivity& SetSequenceId(int64_t value);

    static const char kTimeSinceLastKeyName[];
    static constexpr uint64_t kTimeSinceLastKeyNameHash = UINT64_C(13324245886378099422);
    UserActivity& SetTimeSinceLastKey(int64_t value);

    static const char kTimeSinceLastMouseName[];
    static constexpr uint64_t kTimeSinceLastMouseNameHash = UINT64_C(17332744557102175004);
    UserActivity& SetTimeSinceLastMouse(int64_t value);

    static const char kTimeSinceLastTouchName[];
    static constexpr uint64_t kTimeSinceLastTouchNameHash = UINT64_C(14082842047789348566);
    UserActivity& SetTimeSinceLastTouch(int64_t value);

    static const char kTimeSinceLastVideoEndedName[];
    static constexpr uint64_t kTimeSinceLastVideoEndedNameHash = UINT64_C(10757682901092788351);
    UserActivity& SetTimeSinceLastVideoEnded(int64_t value);

    static const char kTouchEventsInLastHourName[];
    static constexpr uint64_t kTouchEventsInLastHourNameHash = UINT64_C(10049871984955982925);
    UserActivity& SetTouchEventsInLastHour(int64_t value);
};

class UserActivityId final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit UserActivityId(ukm::SourceId source_id);
    explicit UserActivityId(ukm::SourceIdObj source_id);
    UserActivityId(UserActivityId&&);
    UserActivityId& operator=(UserActivityId&&);
    ~UserActivityId() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13821826834442202003);

    static const char kActivityIdName[];
    static constexpr uint64_t kActivityIdNameHash = UINT64_C(11740600895634714945);
    UserActivityId& SetActivityId(int64_t value);

    static const char kContentTypeName[];
    static constexpr uint64_t kContentTypeNameHash = UINT64_C(13265227184175150385);
    UserActivityId& SetContentType(int64_t value);

    static const char kHasFormEntryName[];
    static constexpr uint64_t kHasFormEntryNameHash = UINT64_C(5531671421920391819);
    UserActivityId& SetHasFormEntry(int64_t value);

    static const char kIsActiveName[];
    static constexpr uint64_t kIsActiveNameHash = UINT64_C(145730663672890399);
    UserActivityId& SetIsActive(int64_t value);

    static const char kIsBrowserFocusedName[];
    static constexpr uint64_t kIsBrowserFocusedNameHash = UINT64_C(10440852628796553876);
    UserActivityId& SetIsBrowserFocused(int64_t value);

    static const char kIsBrowserVisibleName[];
    static constexpr uint64_t kIsBrowserVisibleNameHash = UINT64_C(3688875443071437947);
    UserActivityId& SetIsBrowserVisible(int64_t value);

    static const char kIsTopmostBrowserName[];
    static constexpr uint64_t kIsTopmostBrowserNameHash = UINT64_C(1520583382931955160);
    UserActivityId& SetIsTopmostBrowser(int64_t value);

    static const char kSiteEngagementScoreName[];
    static constexpr uint64_t kSiteEngagementScoreNameHash = UINT64_C(325008584515519231);
    UserActivityId& SetSiteEngagementScore(int64_t value);
};

class UserPerceivedPageVisit final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit UserPerceivedPageVisit(ukm::SourceId source_id);
    explicit UserPerceivedPageVisit(ukm::SourceIdObj source_id);
    UserPerceivedPageVisit(UserPerceivedPageVisit&&);
    UserPerceivedPageVisit& operator=(UserPerceivedPageVisit&&);
    ~UserPerceivedPageVisit() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4221731235635910179);

    static const char kNotCountedForCoreWebVitalsName[];
    static constexpr uint64_t kNotCountedForCoreWebVitalsNameHash = UINT64_C(15985276500203704359);
    UserPerceivedPageVisit& SetNotCountedForCoreWebVitals(int64_t value);

    static const char kPageVisitFinalStatusName[];
    static constexpr uint64_t kPageVisitFinalStatusNameHash = UINT64_C(15568769830052939365);
    UserPerceivedPageVisit& SetPageVisitFinalStatus(int64_t value);

    static const char kUserInitiatedName[];
    static constexpr uint64_t kUserInitiatedNameHash = UINT64_C(4906643665730180691);
    UserPerceivedPageVisit& SetUserInitiated(int64_t value);
};

class V8_Wasm_ModuleCompiled final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit V8_Wasm_ModuleCompiled(ukm::SourceId source_id);
    explicit V8_Wasm_ModuleCompiled(ukm::SourceIdObj source_id);
    V8_Wasm_ModuleCompiled(V8_Wasm_ModuleCompiled&&);
    V8_Wasm_ModuleCompiled& operator=(V8_Wasm_ModuleCompiled&&);
    ~V8_Wasm_ModuleCompiled() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12143286159580552989);

    static const char kAsyncName[];
    static constexpr uint64_t kAsyncNameHash = UINT64_C(2641995702112535574);
    V8_Wasm_ModuleCompiled& SetAsync(int64_t value);

    static const char kCachedName[];
    static constexpr uint64_t kCachedNameHash = UINT64_C(453717775238895883);
    V8_Wasm_ModuleCompiled& SetCached(int64_t value);

    static const char kCodeSizeName[];
    static constexpr uint64_t kCodeSizeNameHash = UINT64_C(4489507447692387463);
    V8_Wasm_ModuleCompiled& SetCodeSize(int64_t value);

    static const char kDeserializedName[];
    static constexpr uint64_t kDeserializedNameHash = UINT64_C(7672164651631470075);
    V8_Wasm_ModuleCompiled& SetDeserialized(int64_t value);

    static const char kLazyName[];
    static constexpr uint64_t kLazyNameHash = UINT64_C(5091860181698051066);
    V8_Wasm_ModuleCompiled& SetLazy(int64_t value);

    static const char kLiftoffBailoutCountName[];
    static constexpr uint64_t kLiftoffBailoutCountNameHash = UINT64_C(5722648529541372646);
    V8_Wasm_ModuleCompiled& SetLiftoffBailoutCount(int64_t value);

    static const char kStreamedName[];
    static constexpr uint64_t kStreamedNameHash = UINT64_C(13619919693661414920);
    V8_Wasm_ModuleCompiled& SetStreamed(int64_t value);

    static const char kSuccessName[];
    static constexpr uint64_t kSuccessNameHash = UINT64_C(5790085346892983794);
    V8_Wasm_ModuleCompiled& SetSuccess(int64_t value);

    static const char kWallClockDurationName[];
    static constexpr uint64_t kWallClockDurationNameHash = UINT64_C(5109936066037177312);
    V8_Wasm_ModuleCompiled& SetWallClockDuration(int64_t value);
};

class V8_Wasm_ModuleDecoded final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit V8_Wasm_ModuleDecoded(ukm::SourceId source_id);
    explicit V8_Wasm_ModuleDecoded(ukm::SourceIdObj source_id);
    V8_Wasm_ModuleDecoded(V8_Wasm_ModuleDecoded&&);
    V8_Wasm_ModuleDecoded& operator=(V8_Wasm_ModuleDecoded&&);
    ~V8_Wasm_ModuleDecoded() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(5663155407937554096);

    static const char kFunctionCountName[];
    static constexpr uint64_t kFunctionCountNameHash = UINT64_C(6741819159474344408);
    V8_Wasm_ModuleDecoded& SetFunctionCount(int64_t value);

    static const char kModuleSizeName[];
    static constexpr uint64_t kModuleSizeNameHash = UINT64_C(6750517084540206915);
    V8_Wasm_ModuleDecoded& SetModuleSize(int64_t value);

    static const char kStreamedName[];
    static constexpr uint64_t kStreamedNameHash = UINT64_C(13619919693661414920);
    V8_Wasm_ModuleDecoded& SetStreamed(int64_t value);

    static const char kSuccessName[];
    static constexpr uint64_t kSuccessNameHash = UINT64_C(5790085346892983794);
    V8_Wasm_ModuleDecoded& SetSuccess(int64_t value);

    static const char kWallClockDurationName[];
    static constexpr uint64_t kWallClockDurationNameHash = UINT64_C(5109936066037177312);
    V8_Wasm_ModuleDecoded& SetWallClockDuration(int64_t value);
};

class V8_Wasm_ModuleInstantiated final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit V8_Wasm_ModuleInstantiated(ukm::SourceId source_id);
    explicit V8_Wasm_ModuleInstantiated(ukm::SourceIdObj source_id);
    V8_Wasm_ModuleInstantiated(V8_Wasm_ModuleInstantiated&&);
    V8_Wasm_ModuleInstantiated& operator=(V8_Wasm_ModuleInstantiated&&);
    ~V8_Wasm_ModuleInstantiated() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15295210720868142566);

    static const char kImportedFunctionCountName[];
    static constexpr uint64_t kImportedFunctionCountNameHash = UINT64_C(5003274284110280271);
    V8_Wasm_ModuleInstantiated& SetImportedFunctionCount(int64_t value);

    static const char kSuccessName[];
    static constexpr uint64_t kSuccessNameHash = UINT64_C(5790085346892983794);
    V8_Wasm_ModuleInstantiated& SetSuccess(int64_t value);

    static const char kWallClockDurationName[];
    static constexpr uint64_t kWallClockDurationNameHash = UINT64_C(5109936066037177312);
    V8_Wasm_ModuleInstantiated& SetWallClockDuration(int64_t value);
};

class V8_Wasm_ModuleTieredUp final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit V8_Wasm_ModuleTieredUp(ukm::SourceId source_id);
    explicit V8_Wasm_ModuleTieredUp(ukm::SourceIdObj source_id);
    V8_Wasm_ModuleTieredUp(V8_Wasm_ModuleTieredUp&&);
    V8_Wasm_ModuleTieredUp& operator=(V8_Wasm_ModuleTieredUp&&);
    ~V8_Wasm_ModuleTieredUp() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2833187735774133395);

    static const char kCodeSizeName[];
    static constexpr uint64_t kCodeSizeNameHash = UINT64_C(4489507447692387463);
    V8_Wasm_ModuleTieredUp& SetCodeSize(int64_t value);

    static const char kLazyName[];
    static constexpr uint64_t kLazyNameHash = UINT64_C(5091860181698051066);
    V8_Wasm_ModuleTieredUp& SetLazy(int64_t value);

    static const char kWallClockDurationName[];
    static constexpr uint64_t kWallClockDurationNameHash = UINT64_C(5109936066037177312);
    V8_Wasm_ModuleTieredUp& SetWallClockDuration(int64_t value);
};

class V8CompileHints_Version5 final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit V8CompileHints_Version5(ukm::SourceId source_id);
    explicit V8CompileHints_Version5(ukm::SourceIdObj source_id);
    V8CompileHints_Version5(V8CompileHints_Version5&&);
    V8CompileHints_Version5& operator=(V8CompileHints_Version5&&);
    ~V8CompileHints_Version5() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12239806873861850751);

    static const char kData0Name[];
    static constexpr uint64_t kData0NameHash = UINT64_C(12561612964970349133);
    V8CompileHints_Version5& SetData0(int64_t value);

    static const char kData1Name[];
    static constexpr uint64_t kData1NameHash = UINT64_C(9465813868643304916);
    V8CompileHints_Version5& SetData1(int64_t value);

    static const char kData10Name[];
    static constexpr uint64_t kData10NameHash = UINT64_C(7392427434886672641);
    V8CompileHints_Version5& SetData10(int64_t value);

    static const char kData100Name[];
    static constexpr uint64_t kData100NameHash = UINT64_C(6811080155507941203);
    V8CompileHints_Version5& SetData100(int64_t value);

    static const char kData1000Name[];
    static constexpr uint64_t kData1000NameHash = UINT64_C(17350468615078943204);
    V8CompileHints_Version5& SetData1000(int64_t value);

    static const char kData1001Name[];
    static constexpr uint64_t kData1001NameHash = UINT64_C(498090858279743576);
    V8CompileHints_Version5& SetData1001(int64_t value);

    static const char kData1002Name[];
    static constexpr uint64_t kData1002NameHash = UINT64_C(818200639657720828);
    V8CompileHints_Version5& SetData1002(int64_t value);

    static const char kData1003Name[];
    static constexpr uint64_t kData1003NameHash = UINT64_C(6173461340994918976);
    V8CompileHints_Version5& SetData1003(int64_t value);

    static const char kData1004Name[];
    static constexpr uint64_t kData1004NameHash = UINT64_C(5253560705563411628);
    V8CompileHints_Version5& SetData1004(int64_t value);

    static const char kData1005Name[];
    static constexpr uint64_t kData1005NameHash = UINT64_C(9352147270834640734);
    V8CompileHints_Version5& SetData1005(int64_t value);

    static const char kData1006Name[];
    static constexpr uint64_t kData1006NameHash = UINT64_C(9666888035083157923);
    V8CompileHints_Version5& SetData1006(int64_t value);

    static const char kData1007Name[];
    static constexpr uint64_t kData1007NameHash = UINT64_C(4604786190813092749);
    V8CompileHints_Version5& SetData1007(int64_t value);

    static const char kData1008Name[];
    static constexpr uint64_t kData1008NameHash = UINT64_C(7094786861278685650);
    V8CompileHints_Version5& SetData1008(int64_t value);

    static const char kData1009Name[];
    static constexpr uint64_t kData1009NameHash = UINT64_C(14863274938474099272);
    V8CompileHints_Version5& SetData1009(int64_t value);

    static const char kData101Name[];
    static constexpr uint64_t kData101NameHash = UINT64_C(12390513483642551656);
    V8CompileHints_Version5& SetData101(int64_t value);

    static const char kData1010Name[];
    static constexpr uint64_t kData1010NameHash = UINT64_C(11986910281556359956);
    V8CompileHints_Version5& SetData1010(int64_t value);

    static const char kData1011Name[];
    static constexpr uint64_t kData1011NameHash = UINT64_C(13893181076012889528);
    V8CompileHints_Version5& SetData1011(int64_t value);

    static const char kData1012Name[];
    static constexpr uint64_t kData1012NameHash = UINT64_C(11583406193516971552);
    V8CompileHints_Version5& SetData1012(int64_t value);

    static const char kData1013Name[];
    static constexpr uint64_t kData1013NameHash = UINT64_C(3065758052332293987);
    V8CompileHints_Version5& SetData1013(int64_t value);

    static const char kData1014Name[];
    static constexpr uint64_t kData1014NameHash = UINT64_C(10440551878327364202);
    V8CompileHints_Version5& SetData1014(int64_t value);

    static const char kData1015Name[];
    static constexpr uint64_t kData1015NameHash = UINT64_C(418508182793751545);
    V8CompileHints_Version5& SetData1015(int64_t value);

    static const char kData1016Name[];
    static constexpr uint64_t kData1016NameHash = UINT64_C(8201240684271858472);
    V8CompileHints_Version5& SetData1016(int64_t value);

    static const char kData1017Name[];
    static constexpr uint64_t kData1017NameHash = UINT64_C(2507533166330708654);
    V8CompileHints_Version5& SetData1017(int64_t value);

    static const char kData1018Name[];
    static constexpr uint64_t kData1018NameHash = UINT64_C(6288965945587661714);
    V8CompileHints_Version5& SetData1018(int64_t value);

    static const char kData1019Name[];
    static constexpr uint64_t kData1019NameHash = UINT64_C(10400650419678036557);
    V8CompileHints_Version5& SetData1019(int64_t value);

    static const char kData102Name[];
    static constexpr uint64_t kData102NameHash = UINT64_C(5938738713597808420);
    V8CompileHints_Version5& SetData102(int64_t value);

    static const char kData1020Name[];
    static constexpr uint64_t kData1020NameHash = UINT64_C(9256220243795234369);
    V8CompileHints_Version5& SetData1020(int64_t value);

    static const char kData1021Name[];
    static constexpr uint64_t kData1021NameHash = UINT64_C(7611225498148478904);
    V8CompileHints_Version5& SetData1021(int64_t value);

    static const char kData1022Name[];
    static constexpr uint64_t kData1022NameHash = UINT64_C(16639955683517810420);
    V8CompileHints_Version5& SetData1022(int64_t value);

    static const char kData1023Name[];
    static constexpr uint64_t kData1023NameHash = UINT64_C(14005204756901987439);
    V8CompileHints_Version5& SetData1023(int64_t value);

    static const char kData103Name[];
    static constexpr uint64_t kData103NameHash = UINT64_C(1095599630814343377);
    V8CompileHints_Version5& SetData103(int64_t value);

    static const char kData104Name[];
    static constexpr uint64_t kData104NameHash = UINT64_C(3012589813806276636);
    V8CompileHints_Version5& SetData104(int64_t value);

    static const char kData105Name[];
    static constexpr uint64_t kData105NameHash = UINT64_C(5872561270942151298);
    V8CompileHints_Version5& SetData105(int64_t value);

    static const char kData106Name[];
    static constexpr uint64_t kData106NameHash = UINT64_C(14337398819636912071);
    V8CompileHints_Version5& SetData106(int64_t value);

    static const char kData107Name[];
    static constexpr uint64_t kData107NameHash = UINT64_C(8307139381419780182);
    V8CompileHints_Version5& SetData107(int64_t value);

    static const char kData108Name[];
    static constexpr uint64_t kData108NameHash = UINT64_C(6505042963744326376);
    V8CompileHints_Version5& SetData108(int64_t value);

    static const char kData109Name[];
    static constexpr uint64_t kData109NameHash = UINT64_C(10763483197662471853);
    V8CompileHints_Version5& SetData109(int64_t value);

    static const char kData11Name[];
    static constexpr uint64_t kData11NameHash = UINT64_C(7377469493895501137);
    V8CompileHints_Version5& SetData11(int64_t value);

    static const char kData110Name[];
    static constexpr uint64_t kData110NameHash = UINT64_C(2075862877251747869);
    V8CompileHints_Version5& SetData110(int64_t value);

    static const char kData111Name[];
    static constexpr uint64_t kData111NameHash = UINT64_C(13352174050434392920);
    V8CompileHints_Version5& SetData111(int64_t value);

    static const char kData112Name[];
    static constexpr uint64_t kData112NameHash = UINT64_C(3917181905747087624);
    V8CompileHints_Version5& SetData112(int64_t value);

    static const char kData113Name[];
    static constexpr uint64_t kData113NameHash = UINT64_C(4369848507813374387);
    V8CompileHints_Version5& SetData113(int64_t value);

    static const char kData114Name[];
    static constexpr uint64_t kData114NameHash = UINT64_C(6532572178338587583);
    V8CompileHints_Version5& SetData114(int64_t value);

    static const char kData115Name[];
    static constexpr uint64_t kData115NameHash = UINT64_C(10693975800672886918);
    V8CompileHints_Version5& SetData115(int64_t value);

    static const char kData116Name[];
    static constexpr uint64_t kData116NameHash = UINT64_C(13068027662242505795);
    V8CompileHints_Version5& SetData116(int64_t value);

    static const char kData117Name[];
    static constexpr uint64_t kData117NameHash = UINT64_C(13536935113402305141);
    V8CompileHints_Version5& SetData117(int64_t value);

    static const char kData118Name[];
    static constexpr uint64_t kData118NameHash = UINT64_C(11234507834495221477);
    V8CompileHints_Version5& SetData118(int64_t value);

    static const char kData119Name[];
    static constexpr uint64_t kData119NameHash = UINT64_C(528846320155282270);
    V8CompileHints_Version5& SetData119(int64_t value);

    static const char kData12Name[];
    static constexpr uint64_t kData12NameHash = UINT64_C(5765882350679471291);
    V8CompileHints_Version5& SetData12(int64_t value);

    static const char kData120Name[];
    static constexpr uint64_t kData120NameHash = UINT64_C(4354931742924148623);
    V8CompileHints_Version5& SetData120(int64_t value);

    static const char kData121Name[];
    static constexpr uint64_t kData121NameHash = UINT64_C(7089687209063136696);
    V8CompileHints_Version5& SetData121(int64_t value);

    static const char kData122Name[];
    static constexpr uint64_t kData122NameHash = UINT64_C(10937069230413390467);
    V8CompileHints_Version5& SetData122(int64_t value);

    static const char kData123Name[];
    static constexpr uint64_t kData123NameHash = UINT64_C(13875090911609417380);
    V8CompileHints_Version5& SetData123(int64_t value);

    static const char kData124Name[];
    static constexpr uint64_t kData124NameHash = UINT64_C(9362773160116404194);
    V8CompileHints_Version5& SetData124(int64_t value);

    static const char kData125Name[];
    static constexpr uint64_t kData125NameHash = UINT64_C(7124182579403508388);
    V8CompileHints_Version5& SetData125(int64_t value);

    static const char kData126Name[];
    static constexpr uint64_t kData126NameHash = UINT64_C(4565646605472407434);
    V8CompileHints_Version5& SetData126(int64_t value);

    static const char kData127Name[];
    static constexpr uint64_t kData127NameHash = UINT64_C(13168913507572667806);
    V8CompileHints_Version5& SetData127(int64_t value);

    static const char kData128Name[];
    static constexpr uint64_t kData128NameHash = UINT64_C(7615365949460307338);
    V8CompileHints_Version5& SetData128(int64_t value);

    static const char kData129Name[];
    static constexpr uint64_t kData129NameHash = UINT64_C(12893215093235285451);
    V8CompileHints_Version5& SetData129(int64_t value);

    static const char kData13Name[];
    static constexpr uint64_t kData13NameHash = UINT64_C(6454964254102430919);
    V8CompileHints_Version5& SetData13(int64_t value);

    static const char kData130Name[];
    static constexpr uint64_t kData130NameHash = UINT64_C(3965120257500349974);
    V8CompileHints_Version5& SetData130(int64_t value);

    static const char kData131Name[];
    static constexpr uint64_t kData131NameHash = UINT64_C(16003430247427986340);
    V8CompileHints_Version5& SetData131(int64_t value);

    static const char kData132Name[];
    static constexpr uint64_t kData132NameHash = UINT64_C(13260105057976956400);
    V8CompileHints_Version5& SetData132(int64_t value);

    static const char kData133Name[];
    static constexpr uint64_t kData133NameHash = UINT64_C(15208828244778272555);
    V8CompileHints_Version5& SetData133(int64_t value);

    static const char kData134Name[];
    static constexpr uint64_t kData134NameHash = UINT64_C(3777173257349006092);
    V8CompileHints_Version5& SetData134(int64_t value);

    static const char kData135Name[];
    static constexpr uint64_t kData135NameHash = UINT64_C(5662007774331437033);
    V8CompileHints_Version5& SetData135(int64_t value);

    static const char kData136Name[];
    static constexpr uint64_t kData136NameHash = UINT64_C(443343872050872861);
    V8CompileHints_Version5& SetData136(int64_t value);

    static const char kData137Name[];
    static constexpr uint64_t kData137NameHash = UINT64_C(16347645077252229186);
    V8CompileHints_Version5& SetData137(int64_t value);

    static const char kData138Name[];
    static constexpr uint64_t kData138NameHash = UINT64_C(7316460034331272471);
    V8CompileHints_Version5& SetData138(int64_t value);

    static const char kData139Name[];
    static constexpr uint64_t kData139NameHash = UINT64_C(12849373246023904757);
    V8CompileHints_Version5& SetData139(int64_t value);

    static const char kData14Name[];
    static constexpr uint64_t kData14NameHash = UINT64_C(6520556786952176609);
    V8CompileHints_Version5& SetData14(int64_t value);

    static const char kData140Name[];
    static constexpr uint64_t kData140NameHash = UINT64_C(13957429356229676152);
    V8CompileHints_Version5& SetData140(int64_t value);

    static const char kData141Name[];
    static constexpr uint64_t kData141NameHash = UINT64_C(7881959591121426942);
    V8CompileHints_Version5& SetData141(int64_t value);

    static const char kData142Name[];
    static constexpr uint64_t kData142NameHash = UINT64_C(8343419253880150549);
    V8CompileHints_Version5& SetData142(int64_t value);

    static const char kData143Name[];
    static constexpr uint64_t kData143NameHash = UINT64_C(11506729199650515560);
    V8CompileHints_Version5& SetData143(int64_t value);

    static const char kData144Name[];
    static constexpr uint64_t kData144NameHash = UINT64_C(15454431401061953449);
    V8CompileHints_Version5& SetData144(int64_t value);

    static const char kData145Name[];
    static constexpr uint64_t kData145NameHash = UINT64_C(13597583721349056801);
    V8CompileHints_Version5& SetData145(int64_t value);

    static const char kData146Name[];
    static constexpr uint64_t kData146NameHash = UINT64_C(16460397094544692848);
    V8CompileHints_Version5& SetData146(int64_t value);

    static const char kData147Name[];
    static constexpr uint64_t kData147NameHash = UINT64_C(16585572614854686921);
    V8CompileHints_Version5& SetData147(int64_t value);

    static const char kData148Name[];
    static constexpr uint64_t kData148NameHash = UINT64_C(7754500699790653466);
    V8CompileHints_Version5& SetData148(int64_t value);

    static const char kData149Name[];
    static constexpr uint64_t kData149NameHash = UINT64_C(12421821799008429148);
    V8CompileHints_Version5& SetData149(int64_t value);

    static const char kData15Name[];
    static constexpr uint64_t kData15NameHash = UINT64_C(8753224853828070162);
    V8CompileHints_Version5& SetData15(int64_t value);

    static const char kData150Name[];
    static constexpr uint64_t kData150NameHash = UINT64_C(17789572538986894207);
    V8CompileHints_Version5& SetData150(int64_t value);

    static const char kData151Name[];
    static constexpr uint64_t kData151NameHash = UINT64_C(4813470847667594866);
    V8CompileHints_Version5& SetData151(int64_t value);

    static const char kData152Name[];
    static constexpr uint64_t kData152NameHash = UINT64_C(16689952734781595318);
    V8CompileHints_Version5& SetData152(int64_t value);

    static const char kData153Name[];
    static constexpr uint64_t kData153NameHash = UINT64_C(6788767923068055559);
    V8CompileHints_Version5& SetData153(int64_t value);

    static const char kData154Name[];
    static constexpr uint64_t kData154NameHash = UINT64_C(15605096717701074299);
    V8CompileHints_Version5& SetData154(int64_t value);

    static const char kData155Name[];
    static constexpr uint64_t kData155NameHash = UINT64_C(5343525276420401864);
    V8CompileHints_Version5& SetData155(int64_t value);

    static const char kData156Name[];
    static constexpr uint64_t kData156NameHash = UINT64_C(11854110673081379971);
    V8CompileHints_Version5& SetData156(int64_t value);

    static const char kData157Name[];
    static constexpr uint64_t kData157NameHash = UINT64_C(11436818282479589727);
    V8CompileHints_Version5& SetData157(int64_t value);

    static const char kData158Name[];
    static constexpr uint64_t kData158NameHash = UINT64_C(3676741361516307967);
    V8CompileHints_Version5& SetData158(int64_t value);

    static const char kData159Name[];
    static constexpr uint64_t kData159NameHash = UINT64_C(14580427230936846038);
    V8CompileHints_Version5& SetData159(int64_t value);

    static const char kData16Name[];
    static constexpr uint64_t kData16NameHash = UINT64_C(15241971808454446648);
    V8CompileHints_Version5& SetData16(int64_t value);

    static const char kData160Name[];
    static constexpr uint64_t kData160NameHash = UINT64_C(4610566361486615841);
    V8CompileHints_Version5& SetData160(int64_t value);

    static const char kData161Name[];
    static constexpr uint64_t kData161NameHash = UINT64_C(528813923815131168);
    V8CompileHints_Version5& SetData161(int64_t value);

    static const char kData162Name[];
    static constexpr uint64_t kData162NameHash = UINT64_C(15940418687217556991);
    V8CompileHints_Version5& SetData162(int64_t value);

    static const char kData163Name[];
    static constexpr uint64_t kData163NameHash = UINT64_C(9635520372632886594);
    V8CompileHints_Version5& SetData163(int64_t value);

    static const char kData164Name[];
    static constexpr uint64_t kData164NameHash = UINT64_C(13244429826949674506);
    V8CompileHints_Version5& SetData164(int64_t value);

    static const char kData165Name[];
    static constexpr uint64_t kData165NameHash = UINT64_C(10933027219375428342);
    V8CompileHints_Version5& SetData165(int64_t value);

    static const char kData166Name[];
    static constexpr uint64_t kData166NameHash = UINT64_C(5293567286385098830);
    V8CompileHints_Version5& SetData166(int64_t value);

    static const char kData167Name[];
    static constexpr uint64_t kData167NameHash = UINT64_C(8458180886407977121);
    V8CompileHints_Version5& SetData167(int64_t value);

    static const char kData168Name[];
    static constexpr uint64_t kData168NameHash = UINT64_C(1394860289482698378);
    V8CompileHints_Version5& SetData168(int64_t value);

    static const char kData169Name[];
    static constexpr uint64_t kData169NameHash = UINT64_C(7413690541289660232);
    V8CompileHints_Version5& SetData169(int64_t value);

    static const char kData17Name[];
    static constexpr uint64_t kData17NameHash = UINT64_C(6133241947728174818);
    V8CompileHints_Version5& SetData17(int64_t value);

    static const char kData170Name[];
    static constexpr uint64_t kData170NameHash = UINT64_C(14449993336615870393);
    V8CompileHints_Version5& SetData170(int64_t value);

    static const char kData171Name[];
    static constexpr uint64_t kData171NameHash = UINT64_C(14605083620211732356);
    V8CompileHints_Version5& SetData171(int64_t value);

    static const char kData172Name[];
    static constexpr uint64_t kData172NameHash = UINT64_C(7057171344131932851);
    V8CompileHints_Version5& SetData172(int64_t value);

    static const char kData173Name[];
    static constexpr uint64_t kData173NameHash = UINT64_C(3607565247951318868);
    V8CompileHints_Version5& SetData173(int64_t value);

    static const char kData174Name[];
    static constexpr uint64_t kData174NameHash = UINT64_C(15938482796775372243);
    V8CompileHints_Version5& SetData174(int64_t value);

    static const char kData175Name[];
    static constexpr uint64_t kData175NameHash = UINT64_C(11327303997074138720);
    V8CompileHints_Version5& SetData175(int64_t value);

    static const char kData176Name[];
    static constexpr uint64_t kData176NameHash = UINT64_C(8485514010515654586);
    V8CompileHints_Version5& SetData176(int64_t value);

    static const char kData177Name[];
    static constexpr uint64_t kData177NameHash = UINT64_C(10045184437427921700);
    V8CompileHints_Version5& SetData177(int64_t value);

    static const char kData178Name[];
    static constexpr uint64_t kData178NameHash = UINT64_C(5161302555670257849);
    V8CompileHints_Version5& SetData178(int64_t value);

    static const char kData179Name[];
    static constexpr uint64_t kData179NameHash = UINT64_C(15428743865510607006);
    V8CompileHints_Version5& SetData179(int64_t value);

    static const char kData18Name[];
    static constexpr uint64_t kData18NameHash = UINT64_C(9626155382687506123);
    V8CompileHints_Version5& SetData18(int64_t value);

    static const char kData180Name[];
    static constexpr uint64_t kData180NameHash = UINT64_C(5889157332753788333);
    V8CompileHints_Version5& SetData180(int64_t value);

    static const char kData181Name[];
    static constexpr uint64_t kData181NameHash = UINT64_C(12357073326791723374);
    V8CompileHints_Version5& SetData181(int64_t value);

    static const char kData182Name[];
    static constexpr uint64_t kData182NameHash = UINT64_C(3089423456752294791);
    V8CompileHints_Version5& SetData182(int64_t value);

    static const char kData183Name[];
    static constexpr uint64_t kData183NameHash = UINT64_C(16344098664276722606);
    V8CompileHints_Version5& SetData183(int64_t value);

    static const char kData184Name[];
    static constexpr uint64_t kData184NameHash = UINT64_C(17407539368385889698);
    V8CompileHints_Version5& SetData184(int64_t value);

    static const char kData185Name[];
    static constexpr uint64_t kData185NameHash = UINT64_C(10212531236723491472);
    V8CompileHints_Version5& SetData185(int64_t value);

    static const char kData186Name[];
    static constexpr uint64_t kData186NameHash = UINT64_C(8096794467078709119);
    V8CompileHints_Version5& SetData186(int64_t value);

    static const char kData187Name[];
    static constexpr uint64_t kData187NameHash = UINT64_C(6768918549849025375);
    V8CompileHints_Version5& SetData187(int64_t value);

    static const char kData188Name[];
    static constexpr uint64_t kData188NameHash = UINT64_C(16207828548171009411);
    V8CompileHints_Version5& SetData188(int64_t value);

    static const char kData189Name[];
    static constexpr uint64_t kData189NameHash = UINT64_C(775056779468652859);
    V8CompileHints_Version5& SetData189(int64_t value);

    static const char kData19Name[];
    static constexpr uint64_t kData19NameHash = UINT64_C(8788248595525322130);
    V8CompileHints_Version5& SetData19(int64_t value);

    static const char kData190Name[];
    static constexpr uint64_t kData190NameHash = UINT64_C(9352213795760983141);
    V8CompileHints_Version5& SetData190(int64_t value);

    static const char kData191Name[];
    static constexpr uint64_t kData191NameHash = UINT64_C(4481551635432975160);
    V8CompileHints_Version5& SetData191(int64_t value);

    static const char kData192Name[];
    static constexpr uint64_t kData192NameHash = UINT64_C(2317414889949008490);
    V8CompileHints_Version5& SetData192(int64_t value);

    static const char kData193Name[];
    static constexpr uint64_t kData193NameHash = UINT64_C(8607416292390577587);
    V8CompileHints_Version5& SetData193(int64_t value);

    static const char kData194Name[];
    static constexpr uint64_t kData194NameHash = UINT64_C(2280432335157962707);
    V8CompileHints_Version5& SetData194(int64_t value);

    static const char kData195Name[];
    static constexpr uint64_t kData195NameHash = UINT64_C(14940670393347913124);
    V8CompileHints_Version5& SetData195(int64_t value);

    static const char kData196Name[];
    static constexpr uint64_t kData196NameHash = UINT64_C(6562675689923354159);
    V8CompileHints_Version5& SetData196(int64_t value);

    static const char kData197Name[];
    static constexpr uint64_t kData197NameHash = UINT64_C(7233608558437750800);
    V8CompileHints_Version5& SetData197(int64_t value);

    static const char kData198Name[];
    static constexpr uint64_t kData198NameHash = UINT64_C(5367510409071977827);
    V8CompileHints_Version5& SetData198(int64_t value);

    static const char kData199Name[];
    static constexpr uint64_t kData199NameHash = UINT64_C(12036254701907805166);
    V8CompileHints_Version5& SetData199(int64_t value);

    static const char kData2Name[];
    static constexpr uint64_t kData2NameHash = UINT64_C(16102376837876138764);
    V8CompileHints_Version5& SetData2(int64_t value);

    static const char kData20Name[];
    static constexpr uint64_t kData20NameHash = UINT64_C(6650719874390230141);
    V8CompileHints_Version5& SetData20(int64_t value);

    static const char kData200Name[];
    static constexpr uint64_t kData200NameHash = UINT64_C(2786527821249115485);
    V8CompileHints_Version5& SetData200(int64_t value);

    static const char kData201Name[];
    static constexpr uint64_t kData201NameHash = UINT64_C(6820727088671584951);
    V8CompileHints_Version5& SetData201(int64_t value);

    static const char kData202Name[];
    static constexpr uint64_t kData202NameHash = UINT64_C(14206364954734364894);
    V8CompileHints_Version5& SetData202(int64_t value);

    static const char kData203Name[];
    static constexpr uint64_t kData203NameHash = UINT64_C(17358897608945505546);
    V8CompileHints_Version5& SetData203(int64_t value);

    static const char kData204Name[];
    static constexpr uint64_t kData204NameHash = UINT64_C(9659433760007188655);
    V8CompileHints_Version5& SetData204(int64_t value);

    static const char kData205Name[];
    static constexpr uint64_t kData205NameHash = UINT64_C(6504360785418829997);
    V8CompileHints_Version5& SetData205(int64_t value);

    static const char kData206Name[];
    static constexpr uint64_t kData206NameHash = UINT64_C(17488697079836986421);
    V8CompileHints_Version5& SetData206(int64_t value);

    static const char kData207Name[];
    static constexpr uint64_t kData207NameHash = UINT64_C(13955914736717172238);
    V8CompileHints_Version5& SetData207(int64_t value);

    static const char kData208Name[];
    static constexpr uint64_t kData208NameHash = UINT64_C(17372841808141312831);
    V8CompileHints_Version5& SetData208(int64_t value);

    static const char kData209Name[];
    static constexpr uint64_t kData209NameHash = UINT64_C(12721912382794597205);
    V8CompileHints_Version5& SetData209(int64_t value);

    static const char kData21Name[];
    static constexpr uint64_t kData21NameHash = UINT64_C(16499541179208030269);
    V8CompileHints_Version5& SetData21(int64_t value);

    static const char kData210Name[];
    static constexpr uint64_t kData210NameHash = UINT64_C(10384511197831920602);
    V8CompileHints_Version5& SetData210(int64_t value);

    static const char kData211Name[];
    static constexpr uint64_t kData211NameHash = UINT64_C(14719541099492680541);
    V8CompileHints_Version5& SetData211(int64_t value);

    static const char kData212Name[];
    static constexpr uint64_t kData212NameHash = UINT64_C(16749307132718692776);
    V8CompileHints_Version5& SetData212(int64_t value);

    static const char kData213Name[];
    static constexpr uint64_t kData213NameHash = UINT64_C(1643926815123556723);
    V8CompileHints_Version5& SetData213(int64_t value);

    static const char kData214Name[];
    static constexpr uint64_t kData214NameHash = UINT64_C(6830544642677906244);
    V8CompileHints_Version5& SetData214(int64_t value);

    static const char kData215Name[];
    static constexpr uint64_t kData215NameHash = UINT64_C(4614506335047561394);
    V8CompileHints_Version5& SetData215(int64_t value);

    static const char kData216Name[];
    static constexpr uint64_t kData216NameHash = UINT64_C(17569831457353199197);
    V8CompileHints_Version5& SetData216(int64_t value);

    static const char kData217Name[];
    static constexpr uint64_t kData217NameHash = UINT64_C(16806912084272150726);
    V8CompileHints_Version5& SetData217(int64_t value);

    static const char kData218Name[];
    static constexpr uint64_t kData218NameHash = UINT64_C(13114340320482047340);
    V8CompileHints_Version5& SetData218(int64_t value);

    static const char kData219Name[];
    static constexpr uint64_t kData219NameHash = UINT64_C(8521609754800336333);
    V8CompileHints_Version5& SetData219(int64_t value);

    static const char kData22Name[];
    static constexpr uint64_t kData22NameHash = UINT64_C(8712684431303682705);
    V8CompileHints_Version5& SetData22(int64_t value);

    static const char kData220Name[];
    static constexpr uint64_t kData220NameHash = UINT64_C(14518016626367765776);
    V8CompileHints_Version5& SetData220(int64_t value);

    static const char kData221Name[];
    static constexpr uint64_t kData221NameHash = UINT64_C(16529949789851714302);
    V8CompileHints_Version5& SetData221(int64_t value);

    static const char kData222Name[];
    static constexpr uint64_t kData222NameHash = UINT64_C(4181137384170980531);
    V8CompileHints_Version5& SetData222(int64_t value);

    static const char kData223Name[];
    static constexpr uint64_t kData223NameHash = UINT64_C(12790882748376931112);
    V8CompileHints_Version5& SetData223(int64_t value);

    static const char kData224Name[];
    static constexpr uint64_t kData224NameHash = UINT64_C(10180479791488751717);
    V8CompileHints_Version5& SetData224(int64_t value);

    static const char kData225Name[];
    static constexpr uint64_t kData225NameHash = UINT64_C(12384702838772452435);
    V8CompileHints_Version5& SetData225(int64_t value);

    static const char kData226Name[];
    static constexpr uint64_t kData226NameHash = UINT64_C(5315536326699721833);
    V8CompileHints_Version5& SetData226(int64_t value);

    static const char kData227Name[];
    static constexpr uint64_t kData227NameHash = UINT64_C(9104014361548338741);
    V8CompileHints_Version5& SetData227(int64_t value);

    static const char kData228Name[];
    static constexpr uint64_t kData228NameHash = UINT64_C(13558621530225430121);
    V8CompileHints_Version5& SetData228(int64_t value);

    static const char kData229Name[];
    static constexpr uint64_t kData229NameHash = UINT64_C(2553266584989651178);
    V8CompileHints_Version5& SetData229(int64_t value);

    static const char kData23Name[];
    static constexpr uint64_t kData23NameHash = UINT64_C(10835550301709770036);
    V8CompileHints_Version5& SetData23(int64_t value);

    static const char kData230Name[];
    static constexpr uint64_t kData230NameHash = UINT64_C(13463307580360210208);
    V8CompileHints_Version5& SetData230(int64_t value);

    static const char kData231Name[];
    static constexpr uint64_t kData231NameHash = UINT64_C(3392701939522924253);
    V8CompileHints_Version5& SetData231(int64_t value);

    static const char kData232Name[];
    static constexpr uint64_t kData232NameHash = UINT64_C(4558741915038622390);
    V8CompileHints_Version5& SetData232(int64_t value);

    static const char kData233Name[];
    static constexpr uint64_t kData233NameHash = UINT64_C(4832052492817206971);
    V8CompileHints_Version5& SetData233(int64_t value);

    static const char kData234Name[];
    static constexpr uint64_t kData234NameHash = UINT64_C(14679397606932914597);
    V8CompileHints_Version5& SetData234(int64_t value);

    static const char kData235Name[];
    static constexpr uint64_t kData235NameHash = UINT64_C(151750431530965057);
    V8CompileHints_Version5& SetData235(int64_t value);

    static const char kData236Name[];
    static constexpr uint64_t kData236NameHash = UINT64_C(10087436960294761299);
    V8CompileHints_Version5& SetData236(int64_t value);

    static const char kData237Name[];
    static constexpr uint64_t kData237NameHash = UINT64_C(9349606533141524271);
    V8CompileHints_Version5& SetData237(int64_t value);

    static const char kData238Name[];
    static constexpr uint64_t kData238NameHash = UINT64_C(5695038217511129230);
    V8CompileHints_Version5& SetData238(int64_t value);

    static const char kData239Name[];
    static constexpr uint64_t kData239NameHash = UINT64_C(14708767812275942319);
    V8CompileHints_Version5& SetData239(int64_t value);

    static const char kData24Name[];
    static constexpr uint64_t kData24NameHash = UINT64_C(15419479420570424325);
    V8CompileHints_Version5& SetData24(int64_t value);

    static const char kData240Name[];
    static constexpr uint64_t kData240NameHash = UINT64_C(14685606162186811428);
    V8CompileHints_Version5& SetData240(int64_t value);

    static const char kData241Name[];
    static constexpr uint64_t kData241NameHash = UINT64_C(17069398735019700464);
    V8CompileHints_Version5& SetData241(int64_t value);

    static const char kData242Name[];
    static constexpr uint64_t kData242NameHash = UINT64_C(16634632897267880841);
    V8CompileHints_Version5& SetData242(int64_t value);

    static const char kData243Name[];
    static constexpr uint64_t kData243NameHash = UINT64_C(13557696409535414302);
    V8CompileHints_Version5& SetData243(int64_t value);

    static const char kData244Name[];
    static constexpr uint64_t kData244NameHash = UINT64_C(18443330975198375511);
    V8CompileHints_Version5& SetData244(int64_t value);

    static const char kData245Name[];
    static constexpr uint64_t kData245NameHash = UINT64_C(11284184722543826312);
    V8CompileHints_Version5& SetData245(int64_t value);

    static const char kData246Name[];
    static constexpr uint64_t kData246NameHash = UINT64_C(7629311601214993509);
    V8CompileHints_Version5& SetData246(int64_t value);

    static const char kData247Name[];
    static constexpr uint64_t kData247NameHash = UINT64_C(11399003791971107404);
    V8CompileHints_Version5& SetData247(int64_t value);

    static const char kData248Name[];
    static constexpr uint64_t kData248NameHash = UINT64_C(1126960966950985216);
    V8CompileHints_Version5& SetData248(int64_t value);

    static const char kData249Name[];
    static constexpr uint64_t kData249NameHash = UINT64_C(17705696748072828822);
    V8CompileHints_Version5& SetData249(int64_t value);

    static const char kData25Name[];
    static constexpr uint64_t kData25NameHash = UINT64_C(10155422527462965907);
    V8CompileHints_Version5& SetData25(int64_t value);

    static const char kData250Name[];
    static constexpr uint64_t kData250NameHash = UINT64_C(6407423849274558270);
    V8CompileHints_Version5& SetData250(int64_t value);

    static const char kData251Name[];
    static constexpr uint64_t kData251NameHash = UINT64_C(7078925196842430540);
    V8CompileHints_Version5& SetData251(int64_t value);

    static const char kData252Name[];
    static constexpr uint64_t kData252NameHash = UINT64_C(10135823058136085681);
    V8CompileHints_Version5& SetData252(int64_t value);

    static const char kData253Name[];
    static constexpr uint64_t kData253NameHash = UINT64_C(6124845921102628972);
    V8CompileHints_Version5& SetData253(int64_t value);

    static const char kData254Name[];
    static constexpr uint64_t kData254NameHash = UINT64_C(3186363289148214885);
    V8CompileHints_Version5& SetData254(int64_t value);

    static const char kData255Name[];
    static constexpr uint64_t kData255NameHash = UINT64_C(8906532664812757314);
    V8CompileHints_Version5& SetData255(int64_t value);

    static const char kData256Name[];
    static constexpr uint64_t kData256NameHash = UINT64_C(7571115307946644085);
    V8CompileHints_Version5& SetData256(int64_t value);

    static const char kData257Name[];
    static constexpr uint64_t kData257NameHash = UINT64_C(695631145268122975);
    V8CompileHints_Version5& SetData257(int64_t value);

    static const char kData258Name[];
    static constexpr uint64_t kData258NameHash = UINT64_C(11353237671788020664);
    V8CompileHints_Version5& SetData258(int64_t value);

    static const char kData259Name[];
    static constexpr uint64_t kData259NameHash = UINT64_C(7418645417768167717);
    V8CompileHints_Version5& SetData259(int64_t value);

    static const char kData26Name[];
    static constexpr uint64_t kData26NameHash = UINT64_C(4014927117942509652);
    V8CompileHints_Version5& SetData26(int64_t value);

    static const char kData260Name[];
    static constexpr uint64_t kData260NameHash = UINT64_C(1224826546477192955);
    V8CompileHints_Version5& SetData260(int64_t value);

    static const char kData261Name[];
    static constexpr uint64_t kData261NameHash = UINT64_C(6395959912377434974);
    V8CompileHints_Version5& SetData261(int64_t value);

    static const char kData262Name[];
    static constexpr uint64_t kData262NameHash = UINT64_C(11543976834544179269);
    V8CompileHints_Version5& SetData262(int64_t value);

    static const char kData263Name[];
    static constexpr uint64_t kData263NameHash = UINT64_C(11855657343302626613);
    V8CompileHints_Version5& SetData263(int64_t value);

    static const char kData264Name[];
    static constexpr uint64_t kData264NameHash = UINT64_C(6649341857977375644);
    V8CompileHints_Version5& SetData264(int64_t value);

    static const char kData265Name[];
    static constexpr uint64_t kData265NameHash = UINT64_C(5577688471476408851);
    V8CompileHints_Version5& SetData265(int64_t value);

    static const char kData266Name[];
    static constexpr uint64_t kData266NameHash = UINT64_C(8497050503068371294);
    V8CompileHints_Version5& SetData266(int64_t value);

    static const char kData267Name[];
    static constexpr uint64_t kData267NameHash = UINT64_C(8685622914866169243);
    V8CompileHints_Version5& SetData267(int64_t value);

    static const char kData268Name[];
    static constexpr uint64_t kData268NameHash = UINT64_C(9693390080928927220);
    V8CompileHints_Version5& SetData268(int64_t value);

    static const char kData269Name[];
    static constexpr uint64_t kData269NameHash = UINT64_C(9751143176458198242);
    V8CompileHints_Version5& SetData269(int64_t value);

    static const char kData27Name[];
    static constexpr uint64_t kData27NameHash = UINT64_C(3388789489935965951);
    V8CompileHints_Version5& SetData27(int64_t value);

    static const char kData270Name[];
    static constexpr uint64_t kData270NameHash = UINT64_C(4156113038515468368);
    V8CompileHints_Version5& SetData270(int64_t value);

    static const char kData271Name[];
    static constexpr uint64_t kData271NameHash = UINT64_C(4762569727561042218);
    V8CompileHints_Version5& SetData271(int64_t value);

    static const char kData272Name[];
    static constexpr uint64_t kData272NameHash = UINT64_C(8368953000806580535);
    V8CompileHints_Version5& SetData272(int64_t value);

    static const char kData273Name[];
    static constexpr uint64_t kData273NameHash = UINT64_C(14520867044067683570);
    V8CompileHints_Version5& SetData273(int64_t value);

    static const char kData274Name[];
    static constexpr uint64_t kData274NameHash = UINT64_C(16122005005134843282);
    V8CompileHints_Version5& SetData274(int64_t value);

    static const char kData275Name[];
    static constexpr uint64_t kData275NameHash = UINT64_C(7170607701193987754);
    V8CompileHints_Version5& SetData275(int64_t value);

    static const char kData276Name[];
    static constexpr uint64_t kData276NameHash = UINT64_C(9740576518544016365);
    V8CompileHints_Version5& SetData276(int64_t value);

    static const char kData277Name[];
    static constexpr uint64_t kData277NameHash = UINT64_C(13105609602689422714);
    V8CompileHints_Version5& SetData277(int64_t value);

    static const char kData278Name[];
    static constexpr uint64_t kData278NameHash = UINT64_C(15390216800758224196);
    V8CompileHints_Version5& SetData278(int64_t value);

    static const char kData279Name[];
    static constexpr uint64_t kData279NameHash = UINT64_C(2887878481545848876);
    V8CompileHints_Version5& SetData279(int64_t value);

    static const char kData28Name[];
    static constexpr uint64_t kData28NameHash = UINT64_C(8332075891544611016);
    V8CompileHints_Version5& SetData28(int64_t value);

    static const char kData280Name[];
    static constexpr uint64_t kData280NameHash = UINT64_C(10511538424038890199);
    V8CompileHints_Version5& SetData280(int64_t value);

    static const char kData281Name[];
    static constexpr uint64_t kData281NameHash = UINT64_C(6390266042627133974);
    V8CompileHints_Version5& SetData281(int64_t value);

    static const char kData282Name[];
    static constexpr uint64_t kData282NameHash = UINT64_C(11154569982320669357);
    V8CompileHints_Version5& SetData282(int64_t value);

    static const char kData283Name[];
    static constexpr uint64_t kData283NameHash = UINT64_C(14332457933192210477);
    V8CompileHints_Version5& SetData283(int64_t value);

    static const char kData284Name[];
    static constexpr uint64_t kData284NameHash = UINT64_C(4778071143009451973);
    V8CompileHints_Version5& SetData284(int64_t value);

    static const char kData285Name[];
    static constexpr uint64_t kData285NameHash = UINT64_C(6530891005182894951);
    V8CompileHints_Version5& SetData285(int64_t value);

    static const char kData286Name[];
    static constexpr uint64_t kData286NameHash = UINT64_C(5123091050181113519);
    V8CompileHints_Version5& SetData286(int64_t value);

    static const char kData287Name[];
    static constexpr uint64_t kData287NameHash = UINT64_C(1387976331519143582);
    V8CompileHints_Version5& SetData287(int64_t value);

    static const char kData288Name[];
    static constexpr uint64_t kData288NameHash = UINT64_C(5392179994781989490);
    V8CompileHints_Version5& SetData288(int64_t value);

    static const char kData289Name[];
    static constexpr uint64_t kData289NameHash = UINT64_C(11322406227484215991);
    V8CompileHints_Version5& SetData289(int64_t value);

    static const char kData29Name[];
    static constexpr uint64_t kData29NameHash = UINT64_C(13925560393561488127);
    V8CompileHints_Version5& SetData29(int64_t value);

    static const char kData290Name[];
    static constexpr uint64_t kData290NameHash = UINT64_C(11533927729250411559);
    V8CompileHints_Version5& SetData290(int64_t value);

    static const char kData291Name[];
    static constexpr uint64_t kData291NameHash = UINT64_C(17165078594103369088);
    V8CompileHints_Version5& SetData291(int64_t value);

    static const char kData292Name[];
    static constexpr uint64_t kData292NameHash = UINT64_C(11430741052299551204);
    V8CompileHints_Version5& SetData292(int64_t value);

    static const char kData293Name[];
    static constexpr uint64_t kData293NameHash = UINT64_C(4186704750403601180);
    V8CompileHints_Version5& SetData293(int64_t value);

    static const char kData294Name[];
    static constexpr uint64_t kData294NameHash = UINT64_C(11365194109542282743);
    V8CompileHints_Version5& SetData294(int64_t value);

    static const char kData295Name[];
    static constexpr uint64_t kData295NameHash = UINT64_C(9369647449090117573);
    V8CompileHints_Version5& SetData295(int64_t value);

    static const char kData296Name[];
    static constexpr uint64_t kData296NameHash = UINT64_C(17545002492804155062);
    V8CompileHints_Version5& SetData296(int64_t value);

    static const char kData297Name[];
    static constexpr uint64_t kData297NameHash = UINT64_C(1998559432020630808);
    V8CompileHints_Version5& SetData297(int64_t value);

    static const char kData298Name[];
    static constexpr uint64_t kData298NameHash = UINT64_C(14478524633707780135);
    V8CompileHints_Version5& SetData298(int64_t value);

    static const char kData299Name[];
    static constexpr uint64_t kData299NameHash = UINT64_C(9452320111310681695);
    V8CompileHints_Version5& SetData299(int64_t value);

    static const char kData3Name[];
    static constexpr uint64_t kData3NameHash = UINT64_C(444678221604420442);
    V8CompileHints_Version5& SetData3(int64_t value);

    static const char kData30Name[];
    static constexpr uint64_t kData30NameHash = UINT64_C(17483883809316097527);
    V8CompileHints_Version5& SetData30(int64_t value);

    static const char kData300Name[];
    static constexpr uint64_t kData300NameHash = UINT64_C(5722960191011013670);
    V8CompileHints_Version5& SetData300(int64_t value);

    static const char kData301Name[];
    static constexpr uint64_t kData301NameHash = UINT64_C(3993136402333535258);
    V8CompileHints_Version5& SetData301(int64_t value);

    static const char kData302Name[];
    static constexpr uint64_t kData302NameHash = UINT64_C(12099327402806872781);
    V8CompileHints_Version5& SetData302(int64_t value);

    static const char kData303Name[];
    static constexpr uint64_t kData303NameHash = UINT64_C(10608343048030585545);
    V8CompileHints_Version5& SetData303(int64_t value);

    static const char kData304Name[];
    static constexpr uint64_t kData304NameHash = UINT64_C(17666038496314190510);
    V8CompileHints_Version5& SetData304(int64_t value);

    static const char kData305Name[];
    static constexpr uint64_t kData305NameHash = UINT64_C(10404421441920358811);
    V8CompileHints_Version5& SetData305(int64_t value);

    static const char kData306Name[];
    static constexpr uint64_t kData306NameHash = UINT64_C(4151322539664841750);
    V8CompileHints_Version5& SetData306(int64_t value);

    static const char kData307Name[];
    static constexpr uint64_t kData307NameHash = UINT64_C(2493373487048796995);
    V8CompileHints_Version5& SetData307(int64_t value);

    static const char kData308Name[];
    static constexpr uint64_t kData308NameHash = UINT64_C(13794362511491721116);
    V8CompileHints_Version5& SetData308(int64_t value);

    static const char kData309Name[];
    static constexpr uint64_t kData309NameHash = UINT64_C(7840555996597333438);
    V8CompileHints_Version5& SetData309(int64_t value);

    static const char kData31Name[];
    static constexpr uint64_t kData31NameHash = UINT64_C(10024724794047249647);
    V8CompileHints_Version5& SetData31(int64_t value);

    static const char kData310Name[];
    static constexpr uint64_t kData310NameHash = UINT64_C(8253542419490297082);
    V8CompileHints_Version5& SetData310(int64_t value);

    static const char kData311Name[];
    static constexpr uint64_t kData311NameHash = UINT64_C(11897018013947336179);
    V8CompileHints_Version5& SetData311(int64_t value);

    static const char kData312Name[];
    static constexpr uint64_t kData312NameHash = UINT64_C(12388325496242761829);
    V8CompileHints_Version5& SetData312(int64_t value);

    static const char kData313Name[];
    static constexpr uint64_t kData313NameHash = UINT64_C(6597418393512037656);
    V8CompileHints_Version5& SetData313(int64_t value);

    static const char kData314Name[];
    static constexpr uint64_t kData314NameHash = UINT64_C(9666628887193297757);
    V8CompileHints_Version5& SetData314(int64_t value);

    static const char kData315Name[];
    static constexpr uint64_t kData315NameHash = UINT64_C(12372309501355909217);
    V8CompileHints_Version5& SetData315(int64_t value);

    static const char kData316Name[];
    static constexpr uint64_t kData316NameHash = UINT64_C(13383406787597307315);
    V8CompileHints_Version5& SetData316(int64_t value);

    static const char kData317Name[];
    static constexpr uint64_t kData317NameHash = UINT64_C(8718691672406460406);
    V8CompileHints_Version5& SetData317(int64_t value);

    static const char kData318Name[];
    static constexpr uint64_t kData318NameHash = UINT64_C(16220967350725822772);
    V8CompileHints_Version5& SetData318(int64_t value);

    static const char kData319Name[];
    static constexpr uint64_t kData319NameHash = UINT64_C(7590810880384186098);
    V8CompileHints_Version5& SetData319(int64_t value);

    static const char kData32Name[];
    static constexpr uint64_t kData32NameHash = UINT64_C(14976928871108155307);
    V8CompileHints_Version5& SetData32(int64_t value);

    static const char kData320Name[];
    static constexpr uint64_t kData320NameHash = UINT64_C(17108877837248679599);
    V8CompileHints_Version5& SetData320(int64_t value);

    static const char kData321Name[];
    static constexpr uint64_t kData321NameHash = UINT64_C(184279855096021621);
    V8CompileHints_Version5& SetData321(int64_t value);

    static const char kData322Name[];
    static constexpr uint64_t kData322NameHash = UINT64_C(18433343383901531734);
    V8CompileHints_Version5& SetData322(int64_t value);

    static const char kData323Name[];
    static constexpr uint64_t kData323NameHash = UINT64_C(6464022806174931423);
    V8CompileHints_Version5& SetData323(int64_t value);

    static const char kData324Name[];
    static constexpr uint64_t kData324NameHash = UINT64_C(17424236252385577471);
    V8CompileHints_Version5& SetData324(int64_t value);

    static const char kData325Name[];
    static constexpr uint64_t kData325NameHash = UINT64_C(4527274910225890998);
    V8CompileHints_Version5& SetData325(int64_t value);

    static const char kData326Name[];
    static constexpr uint64_t kData326NameHash = UINT64_C(2390445663228700757);
    V8CompileHints_Version5& SetData326(int64_t value);

    static const char kData327Name[];
    static constexpr uint64_t kData327NameHash = UINT64_C(17356894625842797092);
    V8CompileHints_Version5& SetData327(int64_t value);

    static const char kData328Name[];
    static constexpr uint64_t kData328NameHash = UINT64_C(10110123499879844424);
    V8CompileHints_Version5& SetData328(int64_t value);

    static const char kData329Name[];
    static constexpr uint64_t kData329NameHash = UINT64_C(17396556425074061616);
    V8CompileHints_Version5& SetData329(int64_t value);

    static const char kData33Name[];
    static constexpr uint64_t kData33NameHash = UINT64_C(16082521010452128649);
    V8CompileHints_Version5& SetData33(int64_t value);

    static const char kData330Name[];
    static constexpr uint64_t kData330NameHash = UINT64_C(12081175531324254161);
    V8CompileHints_Version5& SetData330(int64_t value);

    static const char kData331Name[];
    static constexpr uint64_t kData331NameHash = UINT64_C(9625950862773089450);
    V8CompileHints_Version5& SetData331(int64_t value);

    static const char kData332Name[];
    static constexpr uint64_t kData332NameHash = UINT64_C(1683628385363807713);
    V8CompileHints_Version5& SetData332(int64_t value);

    static const char kData333Name[];
    static constexpr uint64_t kData333NameHash = UINT64_C(14994943890697710131);
    V8CompileHints_Version5& SetData333(int64_t value);

    static const char kData334Name[];
    static constexpr uint64_t kData334NameHash = UINT64_C(9009125572259002762);
    V8CompileHints_Version5& SetData334(int64_t value);

    static const char kData335Name[];
    static constexpr uint64_t kData335NameHash = UINT64_C(12197956927972146028);
    V8CompileHints_Version5& SetData335(int64_t value);

    static const char kData336Name[];
    static constexpr uint64_t kData336NameHash = UINT64_C(1691704252245031340);
    V8CompileHints_Version5& SetData336(int64_t value);

    static const char kData337Name[];
    static constexpr uint64_t kData337NameHash = UINT64_C(7395878145509070556);
    V8CompileHints_Version5& SetData337(int64_t value);

    static const char kData338Name[];
    static constexpr uint64_t kData338NameHash = UINT64_C(7856528890880657928);
    V8CompileHints_Version5& SetData338(int64_t value);

    static const char kData339Name[];
    static constexpr uint64_t kData339NameHash = UINT64_C(17280631618741633313);
    V8CompileHints_Version5& SetData339(int64_t value);

    static const char kData34Name[];
    static constexpr uint64_t kData34NameHash = UINT64_C(14203340931012281405);
    V8CompileHints_Version5& SetData34(int64_t value);

    static const char kData340Name[];
    static constexpr uint64_t kData340NameHash = UINT64_C(16852824366345318245);
    V8CompileHints_Version5& SetData340(int64_t value);

    static const char kData341Name[];
    static constexpr uint64_t kData341NameHash = UINT64_C(9853134255279855852);
    V8CompileHints_Version5& SetData341(int64_t value);

    static const char kData342Name[];
    static constexpr uint64_t kData342NameHash = UINT64_C(8215198772426408971);
    V8CompileHints_Version5& SetData342(int64_t value);

    static const char kData343Name[];
    static constexpr uint64_t kData343NameHash = UINT64_C(8727002161985993376);
    V8CompileHints_Version5& SetData343(int64_t value);

    static const char kData344Name[];
    static constexpr uint64_t kData344NameHash = UINT64_C(5680962194636543936);
    V8CompileHints_Version5& SetData344(int64_t value);

    static const char kData345Name[];
    static constexpr uint64_t kData345NameHash = UINT64_C(647182642610903337);
    V8CompileHints_Version5& SetData345(int64_t value);

    static const char kData346Name[];
    static constexpr uint64_t kData346NameHash = UINT64_C(8403188176272137327);
    V8CompileHints_Version5& SetData346(int64_t value);

    static const char kData347Name[];
    static constexpr uint64_t kData347NameHash = UINT64_C(5266519773458465166);
    V8CompileHints_Version5& SetData347(int64_t value);

    static const char kData348Name[];
    static constexpr uint64_t kData348NameHash = UINT64_C(13973664606269602278);
    V8CompileHints_Version5& SetData348(int64_t value);

    static const char kData349Name[];
    static constexpr uint64_t kData349NameHash = UINT64_C(12079892950103873580);
    V8CompileHints_Version5& SetData349(int64_t value);

    static const char kData35Name[];
    static constexpr uint64_t kData35NameHash = UINT64_C(8805413516605564587);
    V8CompileHints_Version5& SetData35(int64_t value);

    static const char kData350Name[];
    static constexpr uint64_t kData350NameHash = UINT64_C(9308933863670400914);
    V8CompileHints_Version5& SetData350(int64_t value);

    static const char kData351Name[];
    static constexpr uint64_t kData351NameHash = UINT64_C(9651193635617051391);
    V8CompileHints_Version5& SetData351(int64_t value);

    static const char kData352Name[];
    static constexpr uint64_t kData352NameHash = UINT64_C(11443021957805223525);
    V8CompileHints_Version5& SetData352(int64_t value);

    static const char kData353Name[];
    static constexpr uint64_t kData353NameHash = UINT64_C(17435975260914904392);
    V8CompileHints_Version5& SetData353(int64_t value);

    static const char kData354Name[];
    static constexpr uint64_t kData354NameHash = UINT64_C(13093882943313014736);
    V8CompileHints_Version5& SetData354(int64_t value);

    static const char kData355Name[];
    static constexpr uint64_t kData355NameHash = UINT64_C(8962613318125983364);
    V8CompileHints_Version5& SetData355(int64_t value);

    static const char kData356Name[];
    static constexpr uint64_t kData356NameHash = UINT64_C(3207906788420668356);
    V8CompileHints_Version5& SetData356(int64_t value);

    static const char kData357Name[];
    static constexpr uint64_t kData357NameHash = UINT64_C(12107294428374116646);
    V8CompileHints_Version5& SetData357(int64_t value);

    static const char kData358Name[];
    static constexpr uint64_t kData358NameHash = UINT64_C(17876516535156519339);
    V8CompileHints_Version5& SetData358(int64_t value);

    static const char kData359Name[];
    static constexpr uint64_t kData359NameHash = UINT64_C(11929817007266630231);
    V8CompileHints_Version5& SetData359(int64_t value);

    static const char kData36Name[];
    static constexpr uint64_t kData36NameHash = UINT64_C(1287916636058720093);
    V8CompileHints_Version5& SetData36(int64_t value);

    static const char kData360Name[];
    static constexpr uint64_t kData360NameHash = UINT64_C(211284818194834683);
    V8CompileHints_Version5& SetData360(int64_t value);

    static const char kData361Name[];
    static constexpr uint64_t kData361NameHash = UINT64_C(10273495994037048162);
    V8CompileHints_Version5& SetData361(int64_t value);

    static const char kData362Name[];
    static constexpr uint64_t kData362NameHash = UINT64_C(11724818259481161725);
    V8CompileHints_Version5& SetData362(int64_t value);

    static const char kData363Name[];
    static constexpr uint64_t kData363NameHash = UINT64_C(18250055430295139125);
    V8CompileHints_Version5& SetData363(int64_t value);

    static const char kData364Name[];
    static constexpr uint64_t kData364NameHash = UINT64_C(15413684145045140689);
    V8CompileHints_Version5& SetData364(int64_t value);

    static const char kData365Name[];
    static constexpr uint64_t kData365NameHash = UINT64_C(124325850618600401);
    V8CompileHints_Version5& SetData365(int64_t value);

    static const char kData366Name[];
    static constexpr uint64_t kData366NameHash = UINT64_C(11121484729287493984);
    V8CompileHints_Version5& SetData366(int64_t value);

    static const char kData367Name[];
    static constexpr uint64_t kData367NameHash = UINT64_C(11665737989158661214);
    V8CompileHints_Version5& SetData367(int64_t value);

    static const char kData368Name[];
    static constexpr uint64_t kData368NameHash = UINT64_C(4026350969564354591);
    V8CompileHints_Version5& SetData368(int64_t value);

    static const char kData369Name[];
    static constexpr uint64_t kData369NameHash = UINT64_C(17955849657421733587);
    V8CompileHints_Version5& SetData369(int64_t value);

    static const char kData37Name[];
    static constexpr uint64_t kData37NameHash = UINT64_C(3637217025551653761);
    V8CompileHints_Version5& SetData37(int64_t value);

    static const char kData370Name[];
    static constexpr uint64_t kData370NameHash = UINT64_C(12530027683008751993);
    V8CompileHints_Version5& SetData370(int64_t value);

    static const char kData371Name[];
    static constexpr uint64_t kData371NameHash = UINT64_C(5988911359820198730);
    V8CompileHints_Version5& SetData371(int64_t value);

    static const char kData372Name[];
    static constexpr uint64_t kData372NameHash = UINT64_C(3238272753468757343);
    V8CompileHints_Version5& SetData372(int64_t value);

    static const char kData373Name[];
    static constexpr uint64_t kData373NameHash = UINT64_C(2182769691244048688);
    V8CompileHints_Version5& SetData373(int64_t value);

    static const char kData374Name[];
    static constexpr uint64_t kData374NameHash = UINT64_C(16881285653646067877);
    V8CompileHints_Version5& SetData374(int64_t value);

    static const char kData375Name[];
    static constexpr uint64_t kData375NameHash = UINT64_C(17039080029061044810);
    V8CompileHints_Version5& SetData375(int64_t value);

    static const char kData376Name[];
    static constexpr uint64_t kData376NameHash = UINT64_C(11534704667701244947);
    V8CompileHints_Version5& SetData376(int64_t value);

    static const char kData377Name[];
    static constexpr uint64_t kData377NameHash = UINT64_C(15639393481333634912);
    V8CompileHints_Version5& SetData377(int64_t value);

    static const char kData378Name[];
    static constexpr uint64_t kData378NameHash = UINT64_C(11090505965542874519);
    V8CompileHints_Version5& SetData378(int64_t value);

    static const char kData379Name[];
    static constexpr uint64_t kData379NameHash = UINT64_C(16356658372465742208);
    V8CompileHints_Version5& SetData379(int64_t value);

    static const char kData38Name[];
    static constexpr uint64_t kData38NameHash = UINT64_C(7755825412198693573);
    V8CompileHints_Version5& SetData38(int64_t value);

    static const char kData380Name[];
    static constexpr uint64_t kData380NameHash = UINT64_C(1881257067117533639);
    V8CompileHints_Version5& SetData380(int64_t value);

    static const char kData381Name[];
    static constexpr uint64_t kData381NameHash = UINT64_C(15970657321726375576);
    V8CompileHints_Version5& SetData381(int64_t value);

    static const char kData382Name[];
    static constexpr uint64_t kData382NameHash = UINT64_C(3164523453228197928);
    V8CompileHints_Version5& SetData382(int64_t value);

    static const char kData383Name[];
    static constexpr uint64_t kData383NameHash = UINT64_C(9413943384963355403);
    V8CompileHints_Version5& SetData383(int64_t value);

    static const char kData384Name[];
    static constexpr uint64_t kData384NameHash = UINT64_C(17192068592221963346);
    V8CompileHints_Version5& SetData384(int64_t value);

    static const char kData385Name[];
    static constexpr uint64_t kData385NameHash = UINT64_C(12064677818815033913);
    V8CompileHints_Version5& SetData385(int64_t value);

    static const char kData386Name[];
    static constexpr uint64_t kData386NameHash = UINT64_C(5124252099325939981);
    V8CompileHints_Version5& SetData386(int64_t value);

    static const char kData387Name[];
    static constexpr uint64_t kData387NameHash = UINT64_C(12932949484078477064);
    V8CompileHints_Version5& SetData387(int64_t value);

    static const char kData388Name[];
    static constexpr uint64_t kData388NameHash = UINT64_C(4694164985587279595);
    V8CompileHints_Version5& SetData388(int64_t value);

    static const char kData389Name[];
    static constexpr uint64_t kData389NameHash = UINT64_C(4959533837729430136);
    V8CompileHints_Version5& SetData389(int64_t value);

    static const char kData39Name[];
    static constexpr uint64_t kData39NameHash = UINT64_C(17283120578402989658);
    V8CompileHints_Version5& SetData39(int64_t value);

    static const char kData390Name[];
    static constexpr uint64_t kData390NameHash = UINT64_C(4815576251142366650);
    V8CompileHints_Version5& SetData390(int64_t value);

    static const char kData391Name[];
    static constexpr uint64_t kData391NameHash = UINT64_C(1433300221269327349);
    V8CompileHints_Version5& SetData391(int64_t value);

    static const char kData392Name[];
    static constexpr uint64_t kData392NameHash = UINT64_C(12060827212215046154);
    V8CompileHints_Version5& SetData392(int64_t value);

    static const char kData393Name[];
    static constexpr uint64_t kData393NameHash = UINT64_C(1303914462133799978);
    V8CompileHints_Version5& SetData393(int64_t value);

    static const char kData394Name[];
    static constexpr uint64_t kData394NameHash = UINT64_C(9424137785928377046);
    V8CompileHints_Version5& SetData394(int64_t value);

    static const char kData395Name[];
    static constexpr uint64_t kData395NameHash = UINT64_C(15977824617224179312);
    V8CompileHints_Version5& SetData395(int64_t value);

    static const char kData396Name[];
    static constexpr uint64_t kData396NameHash = UINT64_C(5723441948407189706);
    V8CompileHints_Version5& SetData396(int64_t value);

    static const char kData397Name[];
    static constexpr uint64_t kData397NameHash = UINT64_C(8303755474441124285);
    V8CompileHints_Version5& SetData397(int64_t value);

    static const char kData398Name[];
    static constexpr uint64_t kData398NameHash = UINT64_C(12311310450463640207);
    V8CompileHints_Version5& SetData398(int64_t value);

    static const char kData399Name[];
    static constexpr uint64_t kData399NameHash = UINT64_C(11223216956779303021);
    V8CompileHints_Version5& SetData399(int64_t value);

    static const char kData4Name[];
    static constexpr uint64_t kData4NameHash = UINT64_C(5121536211031008597);
    V8CompileHints_Version5& SetData4(int64_t value);

    static const char kData40Name[];
    static constexpr uint64_t kData40NameHash = UINT64_C(17612712274618515515);
    V8CompileHints_Version5& SetData40(int64_t value);

    static const char kData400Name[];
    static constexpr uint64_t kData400NameHash = UINT64_C(15846781466417017422);
    V8CompileHints_Version5& SetData400(int64_t value);

    static const char kData401Name[];
    static constexpr uint64_t kData401NameHash = UINT64_C(2416525619000198127);
    V8CompileHints_Version5& SetData401(int64_t value);

    static const char kData402Name[];
    static constexpr uint64_t kData402NameHash = UINT64_C(9219924446226185790);
    V8CompileHints_Version5& SetData402(int64_t value);

    static const char kData403Name[];
    static constexpr uint64_t kData403NameHash = UINT64_C(15401201703815113630);
    V8CompileHints_Version5& SetData403(int64_t value);

    static const char kData404Name[];
    static constexpr uint64_t kData404NameHash = UINT64_C(1602919477730311853);
    V8CompileHints_Version5& SetData404(int64_t value);

    static const char kData405Name[];
    static constexpr uint64_t kData405NameHash = UINT64_C(11086548478098567828);
    V8CompileHints_Version5& SetData405(int64_t value);

    static const char kData406Name[];
    static constexpr uint64_t kData406NameHash = UINT64_C(1022978859619871465);
    V8CompileHints_Version5& SetData406(int64_t value);

    static const char kData407Name[];
    static constexpr uint64_t kData407NameHash = UINT64_C(10012811101155186075);
    V8CompileHints_Version5& SetData407(int64_t value);

    static const char kData408Name[];
    static constexpr uint64_t kData408NameHash = UINT64_C(11619635802522139281);
    V8CompileHints_Version5& SetData408(int64_t value);

    static const char kData409Name[];
    static constexpr uint64_t kData409NameHash = UINT64_C(10549879184497044568);
    V8CompileHints_Version5& SetData409(int64_t value);

    static const char kData41Name[];
    static constexpr uint64_t kData41NameHash = UINT64_C(12343754781597810681);
    V8CompileHints_Version5& SetData41(int64_t value);

    static const char kData410Name[];
    static constexpr uint64_t kData410NameHash = UINT64_C(5309941270919449306);
    V8CompileHints_Version5& SetData410(int64_t value);

    static const char kData411Name[];
    static constexpr uint64_t kData411NameHash = UINT64_C(6139479356416962532);
    V8CompileHints_Version5& SetData411(int64_t value);

    static const char kData412Name[];
    static constexpr uint64_t kData412NameHash = UINT64_C(16457287346239739167);
    V8CompileHints_Version5& SetData412(int64_t value);

    static const char kData413Name[];
    static constexpr uint64_t kData413NameHash = UINT64_C(15086970914242376936);
    V8CompileHints_Version5& SetData413(int64_t value);

    static const char kData414Name[];
    static constexpr uint64_t kData414NameHash = UINT64_C(16945609717103947191);
    V8CompileHints_Version5& SetData414(int64_t value);

    static const char kData415Name[];
    static constexpr uint64_t kData415NameHash = UINT64_C(6669441264376482110);
    V8CompileHints_Version5& SetData415(int64_t value);

    static const char kData416Name[];
    static constexpr uint64_t kData416NameHash = UINT64_C(4916226517617912972);
    V8CompileHints_Version5& SetData416(int64_t value);

    static const char kData417Name[];
    static constexpr uint64_t kData417NameHash = UINT64_C(5962848547302174550);
    V8CompileHints_Version5& SetData417(int64_t value);

    static const char kData418Name[];
    static constexpr uint64_t kData418NameHash = UINT64_C(1566463000249559409);
    V8CompileHints_Version5& SetData418(int64_t value);

    static const char kData419Name[];
    static constexpr uint64_t kData419NameHash = UINT64_C(1762455291310281601);
    V8CompileHints_Version5& SetData419(int64_t value);

    static const char kData42Name[];
    static constexpr uint64_t kData42NameHash = UINT64_C(7554114004174771305);
    V8CompileHints_Version5& SetData42(int64_t value);

    static const char kData420Name[];
    static constexpr uint64_t kData420NameHash = UINT64_C(8472570313981106968);
    V8CompileHints_Version5& SetData420(int64_t value);

    static const char kData421Name[];
    static constexpr uint64_t kData421NameHash = UINT64_C(3660351666407455061);
    V8CompileHints_Version5& SetData421(int64_t value);

    static const char kData422Name[];
    static constexpr uint64_t kData422NameHash = UINT64_C(12968411017833085408);
    V8CompileHints_Version5& SetData422(int64_t value);

    static const char kData423Name[];
    static constexpr uint64_t kData423NameHash = UINT64_C(9468165745595752819);
    V8CompileHints_Version5& SetData423(int64_t value);

    static const char kData424Name[];
    static constexpr uint64_t kData424NameHash = UINT64_C(2650048521797129379);
    V8CompileHints_Version5& SetData424(int64_t value);

    static const char kData425Name[];
    static constexpr uint64_t kData425NameHash = UINT64_C(10563232705912704153);
    V8CompileHints_Version5& SetData425(int64_t value);

    static const char kData426Name[];
    static constexpr uint64_t kData426NameHash = UINT64_C(8080350389227266300);
    V8CompileHints_Version5& SetData426(int64_t value);

    static const char kData427Name[];
    static constexpr uint64_t kData427NameHash = UINT64_C(2210041513711049972);
    V8CompileHints_Version5& SetData427(int64_t value);

    static const char kData428Name[];
    static constexpr uint64_t kData428NameHash = UINT64_C(2599224489449296232);
    V8CompileHints_Version5& SetData428(int64_t value);

    static const char kData429Name[];
    static constexpr uint64_t kData429NameHash = UINT64_C(17682792226737502230);
    V8CompileHints_Version5& SetData429(int64_t value);

    static const char kData43Name[];
    static constexpr uint64_t kData43NameHash = UINT64_C(15275187757783261540);
    V8CompileHints_Version5& SetData43(int64_t value);

    static const char kData430Name[];
    static constexpr uint64_t kData430NameHash = UINT64_C(10469478688907246274);
    V8CompileHints_Version5& SetData430(int64_t value);

    static const char kData431Name[];
    static constexpr uint64_t kData431NameHash = UINT64_C(13657549759696647418);
    V8CompileHints_Version5& SetData431(int64_t value);

    static const char kData432Name[];
    static constexpr uint64_t kData432NameHash = UINT64_C(5900836531309412766);
    V8CompileHints_Version5& SetData432(int64_t value);

    static const char kData433Name[];
    static constexpr uint64_t kData433NameHash = UINT64_C(8686113038942925630);
    V8CompileHints_Version5& SetData433(int64_t value);

    static const char kData434Name[];
    static constexpr uint64_t kData434NameHash = UINT64_C(18140877088980544819);
    V8CompileHints_Version5& SetData434(int64_t value);

    static const char kData435Name[];
    static constexpr uint64_t kData435NameHash = UINT64_C(13242358502024270851);
    V8CompileHints_Version5& SetData435(int64_t value);

    static const char kData436Name[];
    static constexpr uint64_t kData436NameHash = UINT64_C(15491948783227293294);
    V8CompileHints_Version5& SetData436(int64_t value);

    static const char kData437Name[];
    static constexpr uint64_t kData437NameHash = UINT64_C(8649578028965237680);
    V8CompileHints_Version5& SetData437(int64_t value);

    static const char kData438Name[];
    static constexpr uint64_t kData438NameHash = UINT64_C(1758624248089467232);
    V8CompileHints_Version5& SetData438(int64_t value);

    static const char kData439Name[];
    static constexpr uint64_t kData439NameHash = UINT64_C(14557751330911516584);
    V8CompileHints_Version5& SetData439(int64_t value);

    static const char kData44Name[];
    static constexpr uint64_t kData44NameHash = UINT64_C(14867636809799553113);
    V8CompileHints_Version5& SetData44(int64_t value);

    static const char kData440Name[];
    static constexpr uint64_t kData440NameHash = UINT64_C(15245165810381828642);
    V8CompileHints_Version5& SetData440(int64_t value);

    static const char kData441Name[];
    static constexpr uint64_t kData441NameHash = UINT64_C(16574719304672950208);
    V8CompileHints_Version5& SetData441(int64_t value);

    static const char kData442Name[];
    static constexpr uint64_t kData442NameHash = UINT64_C(7305282687203185225);
    V8CompileHints_Version5& SetData442(int64_t value);

    static const char kData443Name[];
    static constexpr uint64_t kData443NameHash = UINT64_C(9945702161559330276);
    V8CompileHints_Version5& SetData443(int64_t value);

    static const char kData444Name[];
    static constexpr uint64_t kData444NameHash = UINT64_C(2469134271821932770);
    V8CompileHints_Version5& SetData444(int64_t value);

    static const char kData445Name[];
    static constexpr uint64_t kData445NameHash = UINT64_C(13606396818542708600);
    V8CompileHints_Version5& SetData445(int64_t value);

    static const char kData446Name[];
    static constexpr uint64_t kData446NameHash = UINT64_C(16313175200671571482);
    V8CompileHints_Version5& SetData446(int64_t value);

    static const char kData447Name[];
    static constexpr uint64_t kData447NameHash = UINT64_C(17316080065310111231);
    V8CompileHints_Version5& SetData447(int64_t value);

    static const char kData448Name[];
    static constexpr uint64_t kData448NameHash = UINT64_C(13715837545612389982);
    V8CompileHints_Version5& SetData448(int64_t value);

    static const char kData449Name[];
    static constexpr uint64_t kData449NameHash = UINT64_C(1663575619417489837);
    V8CompileHints_Version5& SetData449(int64_t value);

    static const char kData45Name[];
    static constexpr uint64_t kData45NameHash = UINT64_C(16709858073427580769);
    V8CompileHints_Version5& SetData45(int64_t value);

    static const char kData450Name[];
    static constexpr uint64_t kData450NameHash = UINT64_C(9335637106325738516);
    V8CompileHints_Version5& SetData450(int64_t value);

    static const char kData451Name[];
    static constexpr uint64_t kData451NameHash = UINT64_C(3825450484817535399);
    V8CompileHints_Version5& SetData451(int64_t value);

    static const char kData452Name[];
    static constexpr uint64_t kData452NameHash = UINT64_C(16335036588773565119);
    V8CompileHints_Version5& SetData452(int64_t value);

    static const char kData453Name[];
    static constexpr uint64_t kData453NameHash = UINT64_C(10123203310520056797);
    V8CompileHints_Version5& SetData453(int64_t value);

    static const char kData454Name[];
    static constexpr uint64_t kData454NameHash = UINT64_C(4315387607287646199);
    V8CompileHints_Version5& SetData454(int64_t value);

    static const char kData455Name[];
    static constexpr uint64_t kData455NameHash = UINT64_C(10365548361052818108);
    V8CompileHints_Version5& SetData455(int64_t value);

    static const char kData456Name[];
    static constexpr uint64_t kData456NameHash = UINT64_C(16129038535689276863);
    V8CompileHints_Version5& SetData456(int64_t value);

    static const char kData457Name[];
    static constexpr uint64_t kData457NameHash = UINT64_C(1836119490677208972);
    V8CompileHints_Version5& SetData457(int64_t value);

    static const char kData458Name[];
    static constexpr uint64_t kData458NameHash = UINT64_C(2537917177002540229);
    V8CompileHints_Version5& SetData458(int64_t value);

    static const char kData459Name[];
    static constexpr uint64_t kData459NameHash = UINT64_C(14148679650986644376);
    V8CompileHints_Version5& SetData459(int64_t value);

    static const char kData46Name[];
    static constexpr uint64_t kData46NameHash = UINT64_C(12928845788577376791);
    V8CompileHints_Version5& SetData46(int64_t value);

    static const char kData460Name[];
    static constexpr uint64_t kData460NameHash = UINT64_C(6224546628230857956);
    V8CompileHints_Version5& SetData460(int64_t value);

    static const char kData461Name[];
    static constexpr uint64_t kData461NameHash = UINT64_C(12881883324079212095);
    V8CompileHints_Version5& SetData461(int64_t value);

    static const char kData462Name[];
    static constexpr uint64_t kData462NameHash = UINT64_C(10865817198813744896);
    V8CompileHints_Version5& SetData462(int64_t value);

    static const char kData463Name[];
    static constexpr uint64_t kData463NameHash = UINT64_C(4305576838062673021);
    V8CompileHints_Version5& SetData463(int64_t value);

    static const char kData464Name[];
    static constexpr uint64_t kData464NameHash = UINT64_C(16347131318282937898);
    V8CompileHints_Version5& SetData464(int64_t value);

    static const char kData465Name[];
    static constexpr uint64_t kData465NameHash = UINT64_C(2115078151215858453);
    V8CompileHints_Version5& SetData465(int64_t value);

    static const char kData466Name[];
    static constexpr uint64_t kData466NameHash = UINT64_C(15241803392304781928);
    V8CompileHints_Version5& SetData466(int64_t value);

    static const char kData467Name[];
    static constexpr uint64_t kData467NameHash = UINT64_C(4452349871335694632);
    V8CompileHints_Version5& SetData467(int64_t value);

    static const char kData468Name[];
    static constexpr uint64_t kData468NameHash = UINT64_C(10345676135133630469);
    V8CompileHints_Version5& SetData468(int64_t value);

    static const char kData469Name[];
    static constexpr uint64_t kData469NameHash = UINT64_C(8040468133102344303);
    V8CompileHints_Version5& SetData469(int64_t value);

    static const char kData47Name[];
    static constexpr uint64_t kData47NameHash = UINT64_C(1521728193343948796);
    V8CompileHints_Version5& SetData47(int64_t value);

    static const char kData470Name[];
    static constexpr uint64_t kData470NameHash = UINT64_C(520283479406498740);
    V8CompileHints_Version5& SetData470(int64_t value);

    static const char kData471Name[];
    static constexpr uint64_t kData471NameHash = UINT64_C(14924456945747836923);
    V8CompileHints_Version5& SetData471(int64_t value);

    static const char kData472Name[];
    static constexpr uint64_t kData472NameHash = UINT64_C(124482056009378082);
    V8CompileHints_Version5& SetData472(int64_t value);

    static const char kData473Name[];
    static constexpr uint64_t kData473NameHash = UINT64_C(2874708752725473064);
    V8CompileHints_Version5& SetData473(int64_t value);

    static const char kData474Name[];
    static constexpr uint64_t kData474NameHash = UINT64_C(6563721490372900910);
    V8CompileHints_Version5& SetData474(int64_t value);

    static const char kData475Name[];
    static constexpr uint64_t kData475NameHash = UINT64_C(6975856157888864397);
    V8CompileHints_Version5& SetData475(int64_t value);

    static const char kData476Name[];
    static constexpr uint64_t kData476NameHash = UINT64_C(16546780737826286528);
    V8CompileHints_Version5& SetData476(int64_t value);

    static const char kData477Name[];
    static constexpr uint64_t kData477NameHash = UINT64_C(17747364127942433415);
    V8CompileHints_Version5& SetData477(int64_t value);

    static const char kData478Name[];
    static constexpr uint64_t kData478NameHash = UINT64_C(10490522578012055474);
    V8CompileHints_Version5& SetData478(int64_t value);

    static const char kData479Name[];
    static constexpr uint64_t kData479NameHash = UINT64_C(11124815860832412575);
    V8CompileHints_Version5& SetData479(int64_t value);

    static const char kData48Name[];
    static constexpr uint64_t kData48NameHash = UINT64_C(14433608669577029217);
    V8CompileHints_Version5& SetData48(int64_t value);

    static const char kData480Name[];
    static constexpr uint64_t kData480NameHash = UINT64_C(2043003048497449197);
    V8CompileHints_Version5& SetData480(int64_t value);

    static const char kData481Name[];
    static constexpr uint64_t kData481NameHash = UINT64_C(11730646217064154536);
    V8CompileHints_Version5& SetData481(int64_t value);

    static const char kData482Name[];
    static constexpr uint64_t kData482NameHash = UINT64_C(296337787191675977);
    V8CompileHints_Version5& SetData482(int64_t value);

    static const char kData483Name[];
    static constexpr uint64_t kData483NameHash = UINT64_C(7925263183206032116);
    V8CompileHints_Version5& SetData483(int64_t value);

    static const char kData484Name[];
    static constexpr uint64_t kData484NameHash = UINT64_C(15838380360801679842);
    V8CompileHints_Version5& SetData484(int64_t value);

    static const char kData485Name[];
    static constexpr uint64_t kData485NameHash = UINT64_C(2883985185231029192);
    V8CompileHints_Version5& SetData485(int64_t value);

    static const char kData486Name[];
    static constexpr uint64_t kData486NameHash = UINT64_C(2030437441840980536);
    V8CompileHints_Version5& SetData486(int64_t value);

    static const char kData487Name[];
    static constexpr uint64_t kData487NameHash = UINT64_C(2084238983378122642);
    V8CompileHints_Version5& SetData487(int64_t value);

    static const char kData488Name[];
    static constexpr uint64_t kData488NameHash = UINT64_C(7392912283936986484);
    V8CompileHints_Version5& SetData488(int64_t value);

    static const char kData489Name[];
    static constexpr uint64_t kData489NameHash = UINT64_C(5584818787566887251);
    V8CompileHints_Version5& SetData489(int64_t value);

    static const char kData49Name[];
    static constexpr uint64_t kData49NameHash = UINT64_C(6687756573152018069);
    V8CompileHints_Version5& SetData49(int64_t value);

    static const char kData490Name[];
    static constexpr uint64_t kData490NameHash = UINT64_C(5740462767260669117);
    V8CompileHints_Version5& SetData490(int64_t value);

    static const char kData491Name[];
    static constexpr uint64_t kData491NameHash = UINT64_C(12864438047010883341);
    V8CompileHints_Version5& SetData491(int64_t value);

    static const char kData492Name[];
    static constexpr uint64_t kData492NameHash = UINT64_C(3419633394174232376);
    V8CompileHints_Version5& SetData492(int64_t value);

    static const char kData493Name[];
    static constexpr uint64_t kData493NameHash = UINT64_C(10935142695387804651);
    V8CompileHints_Version5& SetData493(int64_t value);

    static const char kData494Name[];
    static constexpr uint64_t kData494NameHash = UINT64_C(2720047216721621289);
    V8CompileHints_Version5& SetData494(int64_t value);

    static const char kData495Name[];
    static constexpr uint64_t kData495NameHash = UINT64_C(16123388258850382808);
    V8CompileHints_Version5& SetData495(int64_t value);

    static const char kData496Name[];
    static constexpr uint64_t kData496NameHash = UINT64_C(14911013983937665766);
    V8CompileHints_Version5& SetData496(int64_t value);

    static const char kData497Name[];
    static constexpr uint64_t kData497NameHash = UINT64_C(11302707047600162641);
    V8CompileHints_Version5& SetData497(int64_t value);

    static const char kData498Name[];
    static constexpr uint64_t kData498NameHash = UINT64_C(6318536367173820626);
    V8CompileHints_Version5& SetData498(int64_t value);

    static const char kData499Name[];
    static constexpr uint64_t kData499NameHash = UINT64_C(9019591785047065998);
    V8CompileHints_Version5& SetData499(int64_t value);

    static const char kData5Name[];
    static constexpr uint64_t kData5NameHash = UINT64_C(3904131108901794296);
    V8CompileHints_Version5& SetData5(int64_t value);

    static const char kData50Name[];
    static constexpr uint64_t kData50NameHash = UINT64_C(8046915854566340567);
    V8CompileHints_Version5& SetData50(int64_t value);

    static const char kData500Name[];
    static constexpr uint64_t kData500NameHash = UINT64_C(3024242955634052360);
    V8CompileHints_Version5& SetData500(int64_t value);

    static const char kData501Name[];
    static constexpr uint64_t kData501NameHash = UINT64_C(17948272062852859244);
    V8CompileHints_Version5& SetData501(int64_t value);

    static const char kData502Name[];
    static constexpr uint64_t kData502NameHash = UINT64_C(6944951203326024100);
    V8CompileHints_Version5& SetData502(int64_t value);

    static const char kData503Name[];
    static constexpr uint64_t kData503NameHash = UINT64_C(16657098633618035682);
    V8CompileHints_Version5& SetData503(int64_t value);

    static const char kData504Name[];
    static constexpr uint64_t kData504NameHash = UINT64_C(4111329454191834965);
    V8CompileHints_Version5& SetData504(int64_t value);

    static const char kData505Name[];
    static constexpr uint64_t kData505NameHash = UINT64_C(6196399878400839981);
    V8CompileHints_Version5& SetData505(int64_t value);

    static const char kData506Name[];
    static constexpr uint64_t kData506NameHash = UINT64_C(191619443509846184);
    V8CompileHints_Version5& SetData506(int64_t value);

    static const char kData507Name[];
    static constexpr uint64_t kData507NameHash = UINT64_C(16426199488973188799);
    V8CompileHints_Version5& SetData507(int64_t value);

    static const char kData508Name[];
    static constexpr uint64_t kData508NameHash = UINT64_C(17831649016592861737);
    V8CompileHints_Version5& SetData508(int64_t value);

    static const char kData509Name[];
    static constexpr uint64_t kData509NameHash = UINT64_C(431252387522751997);
    V8CompileHints_Version5& SetData509(int64_t value);

    static const char kData51Name[];
    static constexpr uint64_t kData51NameHash = UINT64_C(4096172863595276888);
    V8CompileHints_Version5& SetData51(int64_t value);

    static const char kData510Name[];
    static constexpr uint64_t kData510NameHash = UINT64_C(9633198563007956500);
    V8CompileHints_Version5& SetData510(int64_t value);

    static const char kData511Name[];
    static constexpr uint64_t kData511NameHash = UINT64_C(17125303123318763980);
    V8CompileHints_Version5& SetData511(int64_t value);

    static const char kData512Name[];
    static constexpr uint64_t kData512NameHash = UINT64_C(16905071317317905184);
    V8CompileHints_Version5& SetData512(int64_t value);

    static const char kData513Name[];
    static constexpr uint64_t kData513NameHash = UINT64_C(9308125723317171248);
    V8CompileHints_Version5& SetData513(int64_t value);

    static const char kData514Name[];
    static constexpr uint64_t kData514NameHash = UINT64_C(2095341659412259354);
    V8CompileHints_Version5& SetData514(int64_t value);

    static const char kData515Name[];
    static constexpr uint64_t kData515NameHash = UINT64_C(15810151180156331736);
    V8CompileHints_Version5& SetData515(int64_t value);

    static const char kData516Name[];
    static constexpr uint64_t kData516NameHash = UINT64_C(4308284572069558434);
    V8CompileHints_Version5& SetData516(int64_t value);

    static const char kData517Name[];
    static constexpr uint64_t kData517NameHash = UINT64_C(14998236147124908067);
    V8CompileHints_Version5& SetData517(int64_t value);

    static const char kData518Name[];
    static constexpr uint64_t kData518NameHash = UINT64_C(2768450694985663948);
    V8CompileHints_Version5& SetData518(int64_t value);

    static const char kData519Name[];
    static constexpr uint64_t kData519NameHash = UINT64_C(17705842627842625522);
    V8CompileHints_Version5& SetData519(int64_t value);

    static const char kData52Name[];
    static constexpr uint64_t kData52NameHash = UINT64_C(7861171575728784594);
    V8CompileHints_Version5& SetData52(int64_t value);

    static const char kData520Name[];
    static constexpr uint64_t kData520NameHash = UINT64_C(17487513855649430333);
    V8CompileHints_Version5& SetData520(int64_t value);

    static const char kData521Name[];
    static constexpr uint64_t kData521NameHash = UINT64_C(52129130212126029);
    V8CompileHints_Version5& SetData521(int64_t value);

    static const char kData522Name[];
    static constexpr uint64_t kData522NameHash = UINT64_C(16019873693324191998);
    V8CompileHints_Version5& SetData522(int64_t value);

    static const char kData523Name[];
    static constexpr uint64_t kData523NameHash = UINT64_C(13179204069922952032);
    V8CompileHints_Version5& SetData523(int64_t value);

    static const char kData524Name[];
    static constexpr uint64_t kData524NameHash = UINT64_C(11103976811339389802);
    V8CompileHints_Version5& SetData524(int64_t value);

    static const char kData525Name[];
    static constexpr uint64_t kData525NameHash = UINT64_C(2365382950459834297);
    V8CompileHints_Version5& SetData525(int64_t value);

    static const char kData526Name[];
    static constexpr uint64_t kData526NameHash = UINT64_C(7214814188171142636);
    V8CompileHints_Version5& SetData526(int64_t value);

    static const char kData527Name[];
    static constexpr uint64_t kData527NameHash = UINT64_C(9780785849053358743);
    V8CompileHints_Version5& SetData527(int64_t value);

    static const char kData528Name[];
    static constexpr uint64_t kData528NameHash = UINT64_C(102536404725393394);
    V8CompileHints_Version5& SetData528(int64_t value);

    static const char kData529Name[];
    static constexpr uint64_t kData529NameHash = UINT64_C(3028255020803398221);
    V8CompileHints_Version5& SetData529(int64_t value);

    static const char kData53Name[];
    static constexpr uint64_t kData53NameHash = UINT64_C(2955850373312353463);
    V8CompileHints_Version5& SetData53(int64_t value);

    static const char kData530Name[];
    static constexpr uint64_t kData530NameHash = UINT64_C(14745541573256951363);
    V8CompileHints_Version5& SetData530(int64_t value);

    static const char kData531Name[];
    static constexpr uint64_t kData531NameHash = UINT64_C(16694843912870863855);
    V8CompileHints_Version5& SetData531(int64_t value);

    static const char kData532Name[];
    static constexpr uint64_t kData532NameHash = UINT64_C(15086678406600809896);
    V8CompileHints_Version5& SetData532(int64_t value);

    static const char kData533Name[];
    static constexpr uint64_t kData533NameHash = UINT64_C(7028892866869526724);
    V8CompileHints_Version5& SetData533(int64_t value);

    static const char kData534Name[];
    static constexpr uint64_t kData534NameHash = UINT64_C(12082960632348593450);
    V8CompileHints_Version5& SetData534(int64_t value);

    static const char kData535Name[];
    static constexpr uint64_t kData535NameHash = UINT64_C(995007525127748028);
    V8CompileHints_Version5& SetData535(int64_t value);

    static const char kData536Name[];
    static constexpr uint64_t kData536NameHash = UINT64_C(5080218887373453043);
    V8CompileHints_Version5& SetData536(int64_t value);

    static const char kData537Name[];
    static constexpr uint64_t kData537NameHash = UINT64_C(1351702452342596248);
    V8CompileHints_Version5& SetData537(int64_t value);

    static const char kData538Name[];
    static constexpr uint64_t kData538NameHash = UINT64_C(6007231319670147310);
    V8CompileHints_Version5& SetData538(int64_t value);

    static const char kData539Name[];
    static constexpr uint64_t kData539NameHash = UINT64_C(13888732012454756609);
    V8CompileHints_Version5& SetData539(int64_t value);

    static const char kData54Name[];
    static constexpr uint64_t kData54NameHash = UINT64_C(9280856132839544462);
    V8CompileHints_Version5& SetData54(int64_t value);

    static const char kData540Name[];
    static constexpr uint64_t kData540NameHash = UINT64_C(16902326903682156060);
    V8CompileHints_Version5& SetData540(int64_t value);

    static const char kData541Name[];
    static constexpr uint64_t kData541NameHash = UINT64_C(12403863551456419510);
    V8CompileHints_Version5& SetData541(int64_t value);

    static const char kData542Name[];
    static constexpr uint64_t kData542NameHash = UINT64_C(15937757748287477739);
    V8CompileHints_Version5& SetData542(int64_t value);

    static const char kData543Name[];
    static constexpr uint64_t kData543NameHash = UINT64_C(2643509502530526957);
    V8CompileHints_Version5& SetData543(int64_t value);

    static const char kData544Name[];
    static constexpr uint64_t kData544NameHash = UINT64_C(17123164135116492553);
    V8CompileHints_Version5& SetData544(int64_t value);

    static const char kData545Name[];
    static constexpr uint64_t kData545NameHash = UINT64_C(16779378763146803776);
    V8CompileHints_Version5& SetData545(int64_t value);

    static const char kData546Name[];
    static constexpr uint64_t kData546NameHash = UINT64_C(13244468485418912441);
    V8CompileHints_Version5& SetData546(int64_t value);

    static const char kData547Name[];
    static constexpr uint64_t kData547NameHash = UINT64_C(16498229562427212712);
    V8CompileHints_Version5& SetData547(int64_t value);

    static const char kData548Name[];
    static constexpr uint64_t kData548NameHash = UINT64_C(4500705059979154656);
    V8CompileHints_Version5& SetData548(int64_t value);

    static const char kData549Name[];
    static constexpr uint64_t kData549NameHash = UINT64_C(10229463697756082632);
    V8CompileHints_Version5& SetData549(int64_t value);

    static const char kData55Name[];
    static constexpr uint64_t kData55NameHash = UINT64_C(241116441780511494);
    V8CompileHints_Version5& SetData55(int64_t value);

    static const char kData550Name[];
    static constexpr uint64_t kData550NameHash = UINT64_C(2953224357337491605);
    V8CompileHints_Version5& SetData550(int64_t value);

    static const char kData551Name[];
    static constexpr uint64_t kData551NameHash = UINT64_C(217897228752649234);
    V8CompileHints_Version5& SetData551(int64_t value);

    static const char kData552Name[];
    static constexpr uint64_t kData552NameHash = UINT64_C(15311534705690395265);
    V8CompileHints_Version5& SetData552(int64_t value);

    static const char kData553Name[];
    static constexpr uint64_t kData553NameHash = UINT64_C(2151584061196308505);
    V8CompileHints_Version5& SetData553(int64_t value);

    static const char kData554Name[];
    static constexpr uint64_t kData554NameHash = UINT64_C(3744478521613341814);
    V8CompileHints_Version5& SetData554(int64_t value);

    static const char kData555Name[];
    static constexpr uint64_t kData555NameHash = UINT64_C(13006395441012314705);
    V8CompileHints_Version5& SetData555(int64_t value);

    static const char kData556Name[];
    static constexpr uint64_t kData556NameHash = UINT64_C(14371794309547023498);
    V8CompileHints_Version5& SetData556(int64_t value);

    static const char kData557Name[];
    static constexpr uint64_t kData557NameHash = UINT64_C(126148109592302551);
    V8CompileHints_Version5& SetData557(int64_t value);

    static const char kData558Name[];
    static constexpr uint64_t kData558NameHash = UINT64_C(16232437387667922445);
    V8CompileHints_Version5& SetData558(int64_t value);

    static const char kData559Name[];
    static constexpr uint64_t kData559NameHash = UINT64_C(15398788569711406427);
    V8CompileHints_Version5& SetData559(int64_t value);

    static const char kData56Name[];
    static constexpr uint64_t kData56NameHash = UINT64_C(8631920093463433633);
    V8CompileHints_Version5& SetData56(int64_t value);

    static const char kData560Name[];
    static constexpr uint64_t kData560NameHash = UINT64_C(17088765068546789130);
    V8CompileHints_Version5& SetData560(int64_t value);

    static const char kData561Name[];
    static constexpr uint64_t kData561NameHash = UINT64_C(15638850326126178360);
    V8CompileHints_Version5& SetData561(int64_t value);

    static const char kData562Name[];
    static constexpr uint64_t kData562NameHash = UINT64_C(12615510506643203242);
    V8CompileHints_Version5& SetData562(int64_t value);

    static const char kData563Name[];
    static constexpr uint64_t kData563NameHash = UINT64_C(14940984066075251341);
    V8CompileHints_Version5& SetData563(int64_t value);

    static const char kData564Name[];
    static constexpr uint64_t kData564NameHash = UINT64_C(11969315091256712448);
    V8CompileHints_Version5& SetData564(int64_t value);

    static const char kData565Name[];
    static constexpr uint64_t kData565NameHash = UINT64_C(2171733652471987205);
    V8CompileHints_Version5& SetData565(int64_t value);

    static const char kData566Name[];
    static constexpr uint64_t kData566NameHash = UINT64_C(5345103255438514537);
    V8CompileHints_Version5& SetData566(int64_t value);

    static const char kData567Name[];
    static constexpr uint64_t kData567NameHash = UINT64_C(1141406151232163999);
    V8CompileHints_Version5& SetData567(int64_t value);

    static const char kData568Name[];
    static constexpr uint64_t kData568NameHash = UINT64_C(16105590715880831311);
    V8CompileHints_Version5& SetData568(int64_t value);

    static const char kData569Name[];
    static constexpr uint64_t kData569NameHash = UINT64_C(2042390900696586073);
    V8CompileHints_Version5& SetData569(int64_t value);

    static const char kData57Name[];
    static constexpr uint64_t kData57NameHash = UINT64_C(3526596200196000792);
    V8CompileHints_Version5& SetData57(int64_t value);

    static const char kData570Name[];
    static constexpr uint64_t kData570NameHash = UINT64_C(530586178753175874);
    V8CompileHints_Version5& SetData570(int64_t value);

    static const char kData571Name[];
    static constexpr uint64_t kData571NameHash = UINT64_C(16263366242482971316);
    V8CompileHints_Version5& SetData571(int64_t value);

    static const char kData572Name[];
    static constexpr uint64_t kData572NameHash = UINT64_C(15500110511718517292);
    V8CompileHints_Version5& SetData572(int64_t value);

    static const char kData573Name[];
    static constexpr uint64_t kData573NameHash = UINT64_C(16621130581765585433);
    V8CompileHints_Version5& SetData573(int64_t value);

    static const char kData574Name[];
    static constexpr uint64_t kData574NameHash = UINT64_C(772619896833340331);
    V8CompileHints_Version5& SetData574(int64_t value);

    static const char kData575Name[];
    static constexpr uint64_t kData575NameHash = UINT64_C(11816236955985161666);
    V8CompileHints_Version5& SetData575(int64_t value);

    static const char kData576Name[];
    static constexpr uint64_t kData576NameHash = UINT64_C(5836550756560405662);
    V8CompileHints_Version5& SetData576(int64_t value);

    static const char kData577Name[];
    static constexpr uint64_t kData577NameHash = UINT64_C(3989716399799941113);
    V8CompileHints_Version5& SetData577(int64_t value);

    static const char kData578Name[];
    static constexpr uint64_t kData578NameHash = UINT64_C(14492372830099908787);
    V8CompileHints_Version5& SetData578(int64_t value);

    static const char kData579Name[];
    static constexpr uint64_t kData579NameHash = UINT64_C(2074441401356594541);
    V8CompileHints_Version5& SetData579(int64_t value);

    static const char kData58Name[];
    static constexpr uint64_t kData58NameHash = UINT64_C(2616084140512492772);
    V8CompileHints_Version5& SetData58(int64_t value);

    static const char kData580Name[];
    static constexpr uint64_t kData580NameHash = UINT64_C(6586927491899717996);
    V8CompileHints_Version5& SetData580(int64_t value);

    static const char kData581Name[];
    static constexpr uint64_t kData581NameHash = UINT64_C(9991815783079138067);
    V8CompileHints_Version5& SetData581(int64_t value);

    static const char kData582Name[];
    static constexpr uint64_t kData582NameHash = UINT64_C(4626295052803883880);
    V8CompileHints_Version5& SetData582(int64_t value);

    static const char kData583Name[];
    static constexpr uint64_t kData583NameHash = UINT64_C(8485791786857285128);
    V8CompileHints_Version5& SetData583(int64_t value);

    static const char kData584Name[];
    static constexpr uint64_t kData584NameHash = UINT64_C(17446867727812886110);
    V8CompileHints_Version5& SetData584(int64_t value);

    static const char kData585Name[];
    static constexpr uint64_t kData585NameHash = UINT64_C(3190441966606043388);
    V8CompileHints_Version5& SetData585(int64_t value);

    static const char kData586Name[];
    static constexpr uint64_t kData586NameHash = UINT64_C(4953531143486768097);
    V8CompileHints_Version5& SetData586(int64_t value);

    static const char kData587Name[];
    static constexpr uint64_t kData587NameHash = UINT64_C(13294108501093001352);
    V8CompileHints_Version5& SetData587(int64_t value);

    static const char kData588Name[];
    static constexpr uint64_t kData588NameHash = UINT64_C(16487630285633909286);
    V8CompileHints_Version5& SetData588(int64_t value);

    static const char kData589Name[];
    static constexpr uint64_t kData589NameHash = UINT64_C(6632046016944891643);
    V8CompileHints_Version5& SetData589(int64_t value);

    static const char kData59Name[];
    static constexpr uint64_t kData59NameHash = UINT64_C(6958794827678743856);
    V8CompileHints_Version5& SetData59(int64_t value);

    static const char kData590Name[];
    static constexpr uint64_t kData590NameHash = UINT64_C(1894796232124933524);
    V8CompileHints_Version5& SetData590(int64_t value);

    static const char kData591Name[];
    static constexpr uint64_t kData591NameHash = UINT64_C(9022437352350976134);
    V8CompileHints_Version5& SetData591(int64_t value);

    static const char kData592Name[];
    static constexpr uint64_t kData592NameHash = UINT64_C(7224139974393079254);
    V8CompileHints_Version5& SetData592(int64_t value);

    static const char kData593Name[];
    static constexpr uint64_t kData593NameHash = UINT64_C(13158996048823956368);
    V8CompileHints_Version5& SetData593(int64_t value);

    static const char kData594Name[];
    static constexpr uint64_t kData594NameHash = UINT64_C(9001555277739068107);
    V8CompileHints_Version5& SetData594(int64_t value);

    static const char kData595Name[];
    static constexpr uint64_t kData595NameHash = UINT64_C(1758486276041881857);
    V8CompileHints_Version5& SetData595(int64_t value);

    static const char kData596Name[];
    static constexpr uint64_t kData596NameHash = UINT64_C(11844524136919260953);
    V8CompileHints_Version5& SetData596(int64_t value);

    static const char kData597Name[];
    static constexpr uint64_t kData597NameHash = UINT64_C(9189132849762474799);
    V8CompileHints_Version5& SetData597(int64_t value);

    static const char kData598Name[];
    static constexpr uint64_t kData598NameHash = UINT64_C(1228222664064113424);
    V8CompileHints_Version5& SetData598(int64_t value);

    static const char kData599Name[];
    static constexpr uint64_t kData599NameHash = UINT64_C(15499561298801853804);
    V8CompileHints_Version5& SetData599(int64_t value);

    static const char kData6Name[];
    static constexpr uint64_t kData6NameHash = UINT64_C(18310534281519966375);
    V8CompileHints_Version5& SetData6(int64_t value);

    static const char kData60Name[];
    static constexpr uint64_t kData60NameHash = UINT64_C(14455433327486103018);
    V8CompileHints_Version5& SetData60(int64_t value);

    static const char kData600Name[];
    static constexpr uint64_t kData600NameHash = UINT64_C(838264077050697650);
    V8CompileHints_Version5& SetData600(int64_t value);

    static const char kData601Name[];
    static constexpr uint64_t kData601NameHash = UINT64_C(8529476500596724295);
    V8CompileHints_Version5& SetData601(int64_t value);

    static const char kData602Name[];
    static constexpr uint64_t kData602NameHash = UINT64_C(16651954985769387941);
    V8CompileHints_Version5& SetData602(int64_t value);

    static const char kData603Name[];
    static constexpr uint64_t kData603NameHash = UINT64_C(18163690635593529553);
    V8CompileHints_Version5& SetData603(int64_t value);

    static const char kData604Name[];
    static constexpr uint64_t kData604NameHash = UINT64_C(13675788362486712902);
    V8CompileHints_Version5& SetData604(int64_t value);

    static const char kData605Name[];
    static constexpr uint64_t kData605NameHash = UINT64_C(9909577091951177125);
    V8CompileHints_Version5& SetData605(int64_t value);

    static const char kData606Name[];
    static constexpr uint64_t kData606NameHash = UINT64_C(13237506966014781653);
    V8CompileHints_Version5& SetData606(int64_t value);

    static const char kData607Name[];
    static constexpr uint64_t kData607NameHash = UINT64_C(16032929676147208879);
    V8CompileHints_Version5& SetData607(int64_t value);

    static const char kData608Name[];
    static constexpr uint64_t kData608NameHash = UINT64_C(11565239894408807086);
    V8CompileHints_Version5& SetData608(int64_t value);

    static const char kData609Name[];
    static constexpr uint64_t kData609NameHash = UINT64_C(15553736758308337711);
    V8CompileHints_Version5& SetData609(int64_t value);

    static const char kData61Name[];
    static constexpr uint64_t kData61NameHash = UINT64_C(7106383177261244199);
    V8CompileHints_Version5& SetData61(int64_t value);

    static const char kData610Name[];
    static constexpr uint64_t kData610NameHash = UINT64_C(707456302232360294);
    V8CompileHints_Version5& SetData610(int64_t value);

    static const char kData611Name[];
    static constexpr uint64_t kData611NameHash = UINT64_C(9515940940970311385);
    V8CompileHints_Version5& SetData611(int64_t value);

    static const char kData612Name[];
    static constexpr uint64_t kData612NameHash = UINT64_C(4766045084465429847);
    V8CompileHints_Version5& SetData612(int64_t value);

    static const char kData613Name[];
    static constexpr uint64_t kData613NameHash = UINT64_C(6976999743415559475);
    V8CompileHints_Version5& SetData613(int64_t value);

    static const char kData614Name[];
    static constexpr uint64_t kData614NameHash = UINT64_C(12910252666274690093);
    V8CompileHints_Version5& SetData614(int64_t value);

    static const char kData615Name[];
    static constexpr uint64_t kData615NameHash = UINT64_C(511728398898809996);
    V8CompileHints_Version5& SetData615(int64_t value);

    static const char kData616Name[];
    static constexpr uint64_t kData616NameHash = UINT64_C(11066137741568296116);
    V8CompileHints_Version5& SetData616(int64_t value);

    static const char kData617Name[];
    static constexpr uint64_t kData617NameHash = UINT64_C(686122873700237751);
    V8CompileHints_Version5& SetData617(int64_t value);

    static const char kData618Name[];
    static constexpr uint64_t kData618NameHash = UINT64_C(18230567797532853335);
    V8CompileHints_Version5& SetData618(int64_t value);

    static const char kData619Name[];
    static constexpr uint64_t kData619NameHash = UINT64_C(265732391543446720);
    V8CompileHints_Version5& SetData619(int64_t value);

    static const char kData62Name[];
    static constexpr uint64_t kData62NameHash = UINT64_C(9063998842432351148);
    V8CompileHints_Version5& SetData62(int64_t value);

    static const char kData620Name[];
    static constexpr uint64_t kData620NameHash = UINT64_C(421301918878094674);
    V8CompileHints_Version5& SetData620(int64_t value);

    static const char kData621Name[];
    static constexpr uint64_t kData621NameHash = UINT64_C(15155700875965093289);
    V8CompileHints_Version5& SetData621(int64_t value);

    static const char kData622Name[];
    static constexpr uint64_t kData622NameHash = UINT64_C(5374768048164973501);
    V8CompileHints_Version5& SetData622(int64_t value);

    static const char kData623Name[];
    static constexpr uint64_t kData623NameHash = UINT64_C(4439096264648234696);
    V8CompileHints_Version5& SetData623(int64_t value);

    static const char kData624Name[];
    static constexpr uint64_t kData624NameHash = UINT64_C(6420616712794660154);
    V8CompileHints_Version5& SetData624(int64_t value);

    static const char kData625Name[];
    static constexpr uint64_t kData625NameHash = UINT64_C(13551022464017608048);
    V8CompileHints_Version5& SetData625(int64_t value);

    static const char kData626Name[];
    static constexpr uint64_t kData626NameHash = UINT64_C(2535841146403997680);
    V8CompileHints_Version5& SetData626(int64_t value);

    static const char kData627Name[];
    static constexpr uint64_t kData627NameHash = UINT64_C(13184317559858840936);
    V8CompileHints_Version5& SetData627(int64_t value);

    static const char kData628Name[];
    static constexpr uint64_t kData628NameHash = UINT64_C(6827564692257293399);
    V8CompileHints_Version5& SetData628(int64_t value);

    static const char kData629Name[];
    static constexpr uint64_t kData629NameHash = UINT64_C(9720588487083343904);
    V8CompileHints_Version5& SetData629(int64_t value);

    static const char kData63Name[];
    static constexpr uint64_t kData63NameHash = UINT64_C(858042078118426480);
    V8CompileHints_Version5& SetData63(int64_t value);

    static const char kData630Name[];
    static constexpr uint64_t kData630NameHash = UINT64_C(5563500137610887704);
    V8CompileHints_Version5& SetData630(int64_t value);

    static const char kData631Name[];
    static constexpr uint64_t kData631NameHash = UINT64_C(13722591130872772800);
    V8CompileHints_Version5& SetData631(int64_t value);

    static const char kData632Name[];
    static constexpr uint64_t kData632NameHash = UINT64_C(1762365058839384015);
    V8CompileHints_Version5& SetData632(int64_t value);

    static const char kData633Name[];
    static constexpr uint64_t kData633NameHash = UINT64_C(10160784845941703248);
    V8CompileHints_Version5& SetData633(int64_t value);

    static const char kData634Name[];
    static constexpr uint64_t kData634NameHash = UINT64_C(6230037009314609882);
    V8CompileHints_Version5& SetData634(int64_t value);

    static const char kData635Name[];
    static constexpr uint64_t kData635NameHash = UINT64_C(7451254195107370917);
    V8CompileHints_Version5& SetData635(int64_t value);

    static const char kData636Name[];
    static constexpr uint64_t kData636NameHash = UINT64_C(11639200091424379257);
    V8CompileHints_Version5& SetData636(int64_t value);

    static const char kData637Name[];
    static constexpr uint64_t kData637NameHash = UINT64_C(15094158572805121333);
    V8CompileHints_Version5& SetData637(int64_t value);

    static const char kData638Name[];
    static constexpr uint64_t kData638NameHash = UINT64_C(5455399318545316289);
    V8CompileHints_Version5& SetData638(int64_t value);

    static const char kData639Name[];
    static constexpr uint64_t kData639NameHash = UINT64_C(12338821000842972738);
    V8CompileHints_Version5& SetData639(int64_t value);

    static const char kData64Name[];
    static constexpr uint64_t kData64NameHash = UINT64_C(12445089611357272324);
    V8CompileHints_Version5& SetData64(int64_t value);

    static const char kData640Name[];
    static constexpr uint64_t kData640NameHash = UINT64_C(5248056898514980027);
    V8CompileHints_Version5& SetData640(int64_t value);

    static const char kData641Name[];
    static constexpr uint64_t kData641NameHash = UINT64_C(12070796997003194166);
    V8CompileHints_Version5& SetData641(int64_t value);

    static const char kData642Name[];
    static constexpr uint64_t kData642NameHash = UINT64_C(8973139057964836177);
    V8CompileHints_Version5& SetData642(int64_t value);

    static const char kData643Name[];
    static constexpr uint64_t kData643NameHash = UINT64_C(2979598714439654799);
    V8CompileHints_Version5& SetData643(int64_t value);

    static const char kData644Name[];
    static constexpr uint64_t kData644NameHash = UINT64_C(10772020803794718706);
    V8CompileHints_Version5& SetData644(int64_t value);

    static const char kData645Name[];
    static constexpr uint64_t kData645NameHash = UINT64_C(7147797197440713075);
    V8CompileHints_Version5& SetData645(int64_t value);

    static const char kData646Name[];
    static constexpr uint64_t kData646NameHash = UINT64_C(15460631129117876474);
    V8CompileHints_Version5& SetData646(int64_t value);

    static const char kData647Name[];
    static constexpr uint64_t kData647NameHash = UINT64_C(94207690947813124);
    V8CompileHints_Version5& SetData647(int64_t value);

    static const char kData648Name[];
    static constexpr uint64_t kData648NameHash = UINT64_C(12215490169761916642);
    V8CompileHints_Version5& SetData648(int64_t value);

    static const char kData649Name[];
    static constexpr uint64_t kData649NameHash = UINT64_C(3148668703599013032);
    V8CompileHints_Version5& SetData649(int64_t value);

    static const char kData65Name[];
    static constexpr uint64_t kData65NameHash = UINT64_C(16727026613326416696);
    V8CompileHints_Version5& SetData65(int64_t value);

    static const char kData650Name[];
    static constexpr uint64_t kData650NameHash = UINT64_C(10797698572413476463);
    V8CompileHints_Version5& SetData650(int64_t value);

    static const char kData651Name[];
    static constexpr uint64_t kData651NameHash = UINT64_C(14002754301680503690);
    V8CompileHints_Version5& SetData651(int64_t value);

    static const char kData652Name[];
    static constexpr uint64_t kData652NameHash = UINT64_C(13572563867475733682);
    V8CompileHints_Version5& SetData652(int64_t value);

    static const char kData653Name[];
    static constexpr uint64_t kData653NameHash = UINT64_C(8648761971559389930);
    V8CompileHints_Version5& SetData653(int64_t value);

    static const char kData654Name[];
    static constexpr uint64_t kData654NameHash = UINT64_C(18105415539714255340);
    V8CompileHints_Version5& SetData654(int64_t value);

    static const char kData655Name[];
    static constexpr uint64_t kData655NameHash = UINT64_C(4115941268275735437);
    V8CompileHints_Version5& SetData655(int64_t value);

    static const char kData656Name[];
    static constexpr uint64_t kData656NameHash = UINT64_C(17225314765465720856);
    V8CompileHints_Version5& SetData656(int64_t value);

    static const char kData657Name[];
    static constexpr uint64_t kData657NameHash = UINT64_C(13842358848566186514);
    V8CompileHints_Version5& SetData657(int64_t value);

    static const char kData658Name[];
    static constexpr uint64_t kData658NameHash = UINT64_C(1277159895321073206);
    V8CompileHints_Version5& SetData658(int64_t value);

    static const char kData659Name[];
    static constexpr uint64_t kData659NameHash = UINT64_C(13465873707249130266);
    V8CompileHints_Version5& SetData659(int64_t value);

    static const char kData66Name[];
    static constexpr uint64_t kData66NameHash = UINT64_C(8847405704828866248);
    V8CompileHints_Version5& SetData66(int64_t value);

    static const char kData660Name[];
    static constexpr uint64_t kData660NameHash = UINT64_C(5229279157945141244);
    V8CompileHints_Version5& SetData660(int64_t value);

    static const char kData661Name[];
    static constexpr uint64_t kData661NameHash = UINT64_C(15759405823859646084);
    V8CompileHints_Version5& SetData661(int64_t value);

    static const char kData662Name[];
    static constexpr uint64_t kData662NameHash = UINT64_C(2339455194281171843);
    V8CompileHints_Version5& SetData662(int64_t value);

    static const char kData663Name[];
    static constexpr uint64_t kData663NameHash = UINT64_C(12190205077752025420);
    V8CompileHints_Version5& SetData663(int64_t value);

    static const char kData664Name[];
    static constexpr uint64_t kData664NameHash = UINT64_C(8332664692700107820);
    V8CompileHints_Version5& SetData664(int64_t value);

    static const char kData665Name[];
    static constexpr uint64_t kData665NameHash = UINT64_C(10495952153675228567);
    V8CompileHints_Version5& SetData665(int64_t value);

    static const char kData666Name[];
    static constexpr uint64_t kData666NameHash = UINT64_C(12822154294830295311);
    V8CompileHints_Version5& SetData666(int64_t value);

    static const char kData667Name[];
    static constexpr uint64_t kData667NameHash = UINT64_C(15112072202930612222);
    V8CompileHints_Version5& SetData667(int64_t value);

    static const char kData668Name[];
    static constexpr uint64_t kData668NameHash = UINT64_C(8525708570954772945);
    V8CompileHints_Version5& SetData668(int64_t value);

    static const char kData669Name[];
    static constexpr uint64_t kData669NameHash = UINT64_C(9468311611343936501);
    V8CompileHints_Version5& SetData669(int64_t value);

    static const char kData67Name[];
    static constexpr uint64_t kData67NameHash = UINT64_C(9627954239867249267);
    V8CompileHints_Version5& SetData67(int64_t value);

    static const char kData670Name[];
    static constexpr uint64_t kData670NameHash = UINT64_C(16502185846796707792);
    V8CompileHints_Version5& SetData670(int64_t value);

    static const char kData671Name[];
    static constexpr uint64_t kData671NameHash = UINT64_C(14670454748547653104);
    V8CompileHints_Version5& SetData671(int64_t value);

    static const char kData672Name[];
    static constexpr uint64_t kData672NameHash = UINT64_C(9668131402624032275);
    V8CompileHints_Version5& SetData672(int64_t value);

    static const char kData673Name[];
    static constexpr uint64_t kData673NameHash = UINT64_C(9475186053873753736);
    V8CompileHints_Version5& SetData673(int64_t value);

    static const char kData674Name[];
    static constexpr uint64_t kData674NameHash = UINT64_C(2607784368753737143);
    V8CompileHints_Version5& SetData674(int64_t value);

    static const char kData675Name[];
    static constexpr uint64_t kData675NameHash = UINT64_C(13005262438453508018);
    V8CompileHints_Version5& SetData675(int64_t value);

    static const char kData676Name[];
    static constexpr uint64_t kData676NameHash = UINT64_C(16576563847577870475);
    V8CompileHints_Version5& SetData676(int64_t value);

    static const char kData677Name[];
    static constexpr uint64_t kData677NameHash = UINT64_C(11479948899700724580);
    V8CompileHints_Version5& SetData677(int64_t value);

    static const char kData678Name[];
    static constexpr uint64_t kData678NameHash = UINT64_C(5745732576055965286);
    V8CompileHints_Version5& SetData678(int64_t value);

    static const char kData679Name[];
    static constexpr uint64_t kData679NameHash = UINT64_C(7883416625760658519);
    V8CompileHints_Version5& SetData679(int64_t value);

    static const char kData68Name[];
    static constexpr uint64_t kData68NameHash = UINT64_C(4757832309358033722);
    V8CompileHints_Version5& SetData68(int64_t value);

    static const char kData680Name[];
    static constexpr uint64_t kData680NameHash = UINT64_C(5562480808695015110);
    V8CompileHints_Version5& SetData680(int64_t value);

    static const char kData681Name[];
    static constexpr uint64_t kData681NameHash = UINT64_C(14921060310394501457);
    V8CompileHints_Version5& SetData681(int64_t value);

    static const char kData682Name[];
    static constexpr uint64_t kData682NameHash = UINT64_C(10743365415557295359);
    V8CompileHints_Version5& SetData682(int64_t value);

    static const char kData683Name[];
    static constexpr uint64_t kData683NameHash = UINT64_C(15960828544743657668);
    V8CompileHints_Version5& SetData683(int64_t value);

    static const char kData684Name[];
    static constexpr uint64_t kData684NameHash = UINT64_C(8001164525901300745);
    V8CompileHints_Version5& SetData684(int64_t value);

    static const char kData685Name[];
    static constexpr uint64_t kData685NameHash = UINT64_C(1196001699614121532);
    V8CompileHints_Version5& SetData685(int64_t value);

    static const char kData686Name[];
    static constexpr uint64_t kData686NameHash = UINT64_C(177674711808273492);
    V8CompileHints_Version5& SetData686(int64_t value);

    static const char kData687Name[];
    static constexpr uint64_t kData687NameHash = UINT64_C(18205252450354528645);
    V8CompileHints_Version5& SetData687(int64_t value);

    static const char kData688Name[];
    static constexpr uint64_t kData688NameHash = UINT64_C(6155020406688101632);
    V8CompileHints_Version5& SetData688(int64_t value);

    static const char kData689Name[];
    static constexpr uint64_t kData689NameHash = UINT64_C(5480942448716927750);
    V8CompileHints_Version5& SetData689(int64_t value);

    static const char kData69Name[];
    static constexpr uint64_t kData69NameHash = UINT64_C(9288829528565862264);
    V8CompileHints_Version5& SetData69(int64_t value);

    static const char kData690Name[];
    static constexpr uint64_t kData690NameHash = UINT64_C(18362219884373553920);
    V8CompileHints_Version5& SetData690(int64_t value);

    static const char kData691Name[];
    static constexpr uint64_t kData691NameHash = UINT64_C(4880047146810292539);
    V8CompileHints_Version5& SetData691(int64_t value);

    static const char kData692Name[];
    static constexpr uint64_t kData692NameHash = UINT64_C(1613508855089996938);
    V8CompileHints_Version5& SetData692(int64_t value);

    static const char kData693Name[];
    static constexpr uint64_t kData693NameHash = UINT64_C(1112416952445668953);
    V8CompileHints_Version5& SetData693(int64_t value);

    static const char kData694Name[];
    static constexpr uint64_t kData694NameHash = UINT64_C(2062358582857150548);
    V8CompileHints_Version5& SetData694(int64_t value);

    static const char kData695Name[];
    static constexpr uint64_t kData695NameHash = UINT64_C(14347545165232226842);
    V8CompileHints_Version5& SetData695(int64_t value);

    static const char kData696Name[];
    static constexpr uint64_t kData696NameHash = UINT64_C(8238984728380569774);
    V8CompileHints_Version5& SetData696(int64_t value);

    static const char kData697Name[];
    static constexpr uint64_t kData697NameHash = UINT64_C(4361864836692722254);
    V8CompileHints_Version5& SetData697(int64_t value);

    static const char kData698Name[];
    static constexpr uint64_t kData698NameHash = UINT64_C(12601799744572683847);
    V8CompileHints_Version5& SetData698(int64_t value);

    static const char kData699Name[];
    static constexpr uint64_t kData699NameHash = UINT64_C(13508445351002682629);
    V8CompileHints_Version5& SetData699(int64_t value);

    static const char kData7Name[];
    static constexpr uint64_t kData7NameHash = UINT64_C(12517001999066685635);
    V8CompileHints_Version5& SetData7(int64_t value);

    static const char kData70Name[];
    static constexpr uint64_t kData70NameHash = UINT64_C(16214996601398629989);
    V8CompileHints_Version5& SetData70(int64_t value);

    static const char kData700Name[];
    static constexpr uint64_t kData700NameHash = UINT64_C(6022071177095597588);
    V8CompileHints_Version5& SetData700(int64_t value);

    static const char kData701Name[];
    static constexpr uint64_t kData701NameHash = UINT64_C(7182039051011218605);
    V8CompileHints_Version5& SetData701(int64_t value);

    static const char kData702Name[];
    static constexpr uint64_t kData702NameHash = UINT64_C(2312843996119782830);
    V8CompileHints_Version5& SetData702(int64_t value);

    static const char kData703Name[];
    static constexpr uint64_t kData703NameHash = UINT64_C(4262683858879474847);
    V8CompileHints_Version5& SetData703(int64_t value);

    static const char kData704Name[];
    static constexpr uint64_t kData704NameHash = UINT64_C(7049715082831228946);
    V8CompileHints_Version5& SetData704(int64_t value);

    static const char kData705Name[];
    static constexpr uint64_t kData705NameHash = UINT64_C(8080903989144720974);
    V8CompileHints_Version5& SetData705(int64_t value);

    static const char kData706Name[];
    static constexpr uint64_t kData706NameHash = UINT64_C(16581916644371942238);
    V8CompileHints_Version5& SetData706(int64_t value);

    static const char kData707Name[];
    static constexpr uint64_t kData707NameHash = UINT64_C(10703219780578238638);
    V8CompileHints_Version5& SetData707(int64_t value);

    static const char kData708Name[];
    static constexpr uint64_t kData708NameHash = UINT64_C(15203460127998342104);
    V8CompileHints_Version5& SetData708(int64_t value);

    static const char kData709Name[];
    static constexpr uint64_t kData709NameHash = UINT64_C(5829691626267986703);
    V8CompileHints_Version5& SetData709(int64_t value);

    static const char kData71Name[];
    static constexpr uint64_t kData71NameHash = UINT64_C(3976644302335562924);
    V8CompileHints_Version5& SetData71(int64_t value);

    static const char kData710Name[];
    static constexpr uint64_t kData710NameHash = UINT64_C(9799893095406600798);
    V8CompileHints_Version5& SetData710(int64_t value);

    static const char kData711Name[];
    static constexpr uint64_t kData711NameHash = UINT64_C(18349772890705349533);
    V8CompileHints_Version5& SetData711(int64_t value);

    static const char kData712Name[];
    static constexpr uint64_t kData712NameHash = UINT64_C(1433220721049144609);
    V8CompileHints_Version5& SetData712(int64_t value);

    static const char kData713Name[];
    static constexpr uint64_t kData713NameHash = UINT64_C(16615327520430191844);
    V8CompileHints_Version5& SetData713(int64_t value);

    static const char kData714Name[];
    static constexpr uint64_t kData714NameHash = UINT64_C(13241700206026482138);
    V8CompileHints_Version5& SetData714(int64_t value);

    static const char kData715Name[];
    static constexpr uint64_t kData715NameHash = UINT64_C(4885886129547327229);
    V8CompileHints_Version5& SetData715(int64_t value);

    static const char kData716Name[];
    static constexpr uint64_t kData716NameHash = UINT64_C(12865784717441049140);
    V8CompileHints_Version5& SetData716(int64_t value);

    static const char kData717Name[];
    static constexpr uint64_t kData717NameHash = UINT64_C(1353626946162342698);
    V8CompileHints_Version5& SetData717(int64_t value);

    static const char kData718Name[];
    static constexpr uint64_t kData718NameHash = UINT64_C(9610709739420903562);
    V8CompileHints_Version5& SetData718(int64_t value);

    static const char kData719Name[];
    static constexpr uint64_t kData719NameHash = UINT64_C(6072890316222042323);
    V8CompileHints_Version5& SetData719(int64_t value);

    static const char kData72Name[];
    static constexpr uint64_t kData72NameHash = UINT64_C(667072553346907381);
    V8CompileHints_Version5& SetData72(int64_t value);

    static const char kData720Name[];
    static constexpr uint64_t kData720NameHash = UINT64_C(13510153893746762203);
    V8CompileHints_Version5& SetData720(int64_t value);

    static const char kData721Name[];
    static constexpr uint64_t kData721NameHash = UINT64_C(13745080433482074198);
    V8CompileHints_Version5& SetData721(int64_t value);

    static const char kData722Name[];
    static constexpr uint64_t kData722NameHash = UINT64_C(7003303600572222128);
    V8CompileHints_Version5& SetData722(int64_t value);

    static const char kData723Name[];
    static constexpr uint64_t kData723NameHash = UINT64_C(16691144087173241840);
    V8CompileHints_Version5& SetData723(int64_t value);

    static const char kData724Name[];
    static constexpr uint64_t kData724NameHash = UINT64_C(2393729884969163862);
    V8CompileHints_Version5& SetData724(int64_t value);

    static const char kData725Name[];
    static constexpr uint64_t kData725NameHash = UINT64_C(7065658752403301291);
    V8CompileHints_Version5& SetData725(int64_t value);

    static const char kData726Name[];
    static constexpr uint64_t kData726NameHash = UINT64_C(124065899520140683);
    V8CompileHints_Version5& SetData726(int64_t value);

    static const char kData727Name[];
    static constexpr uint64_t kData727NameHash = UINT64_C(8569700029861988681);
    V8CompileHints_Version5& SetData727(int64_t value);

    static const char kData728Name[];
    static constexpr uint64_t kData728NameHash = UINT64_C(18420428160357481345);
    V8CompileHints_Version5& SetData728(int64_t value);

    static const char kData729Name[];
    static constexpr uint64_t kData729NameHash = UINT64_C(6950531994873006304);
    V8CompileHints_Version5& SetData729(int64_t value);

    static const char kData73Name[];
    static constexpr uint64_t kData73NameHash = UINT64_C(16824501108650334249);
    V8CompileHints_Version5& SetData73(int64_t value);

    static const char kData730Name[];
    static constexpr uint64_t kData730NameHash = UINT64_C(5861744340898107647);
    V8CompileHints_Version5& SetData730(int64_t value);

    static const char kData731Name[];
    static constexpr uint64_t kData731NameHash = UINT64_C(13420443548579643053);
    V8CompileHints_Version5& SetData731(int64_t value);

    static const char kData732Name[];
    static constexpr uint64_t kData732NameHash = UINT64_C(4436414908866885710);
    V8CompileHints_Version5& SetData732(int64_t value);

    static const char kData733Name[];
    static constexpr uint64_t kData733NameHash = UINT64_C(12191780877756264108);
    V8CompileHints_Version5& SetData733(int64_t value);

    static const char kData734Name[];
    static constexpr uint64_t kData734NameHash = UINT64_C(3525731137068493330);
    V8CompileHints_Version5& SetData734(int64_t value);

    static const char kData735Name[];
    static constexpr uint64_t kData735NameHash = UINT64_C(13276214384388845858);
    V8CompileHints_Version5& SetData735(int64_t value);

    static const char kData736Name[];
    static constexpr uint64_t kData736NameHash = UINT64_C(1037547461078131950);
    V8CompileHints_Version5& SetData736(int64_t value);

    static const char kData737Name[];
    static constexpr uint64_t kData737NameHash = UINT64_C(16153818584973730024);
    V8CompileHints_Version5& SetData737(int64_t value);

    static const char kData738Name[];
    static constexpr uint64_t kData738NameHash = UINT64_C(2194598884867437533);
    V8CompileHints_Version5& SetData738(int64_t value);

    static const char kData739Name[];
    static constexpr uint64_t kData739NameHash = UINT64_C(14073619118304045769);
    V8CompileHints_Version5& SetData739(int64_t value);

    static const char kData74Name[];
    static constexpr uint64_t kData74NameHash = UINT64_C(9214105424437505953);
    V8CompileHints_Version5& SetData74(int64_t value);

    static const char kData740Name[];
    static constexpr uint64_t kData740NameHash = UINT64_C(14311379017720947615);
    V8CompileHints_Version5& SetData740(int64_t value);

    static const char kData741Name[];
    static constexpr uint64_t kData741NameHash = UINT64_C(17122623078107295483);
    V8CompileHints_Version5& SetData741(int64_t value);

    static const char kData742Name[];
    static constexpr uint64_t kData742NameHash = UINT64_C(17716358859040998836);
    V8CompileHints_Version5& SetData742(int64_t value);

    static const char kData743Name[];
    static constexpr uint64_t kData743NameHash = UINT64_C(5129879855754944806);
    V8CompileHints_Version5& SetData743(int64_t value);

    static const char kData744Name[];
    static constexpr uint64_t kData744NameHash = UINT64_C(41304382752073581);
    V8CompileHints_Version5& SetData744(int64_t value);

    static const char kData745Name[];
    static constexpr uint64_t kData745NameHash = UINT64_C(18107486052534221245);
    V8CompileHints_Version5& SetData745(int64_t value);

    static const char kData746Name[];
    static constexpr uint64_t kData746NameHash = UINT64_C(5102618081846501176);
    V8CompileHints_Version5& SetData746(int64_t value);

    static const char kData747Name[];
    static constexpr uint64_t kData747NameHash = UINT64_C(8729112764366125608);
    V8CompileHints_Version5& SetData747(int64_t value);

    static const char kData748Name[];
    static constexpr uint64_t kData748NameHash = UINT64_C(5843216550655295928);
    V8CompileHints_Version5& SetData748(int64_t value);

    static const char kData749Name[];
    static constexpr uint64_t kData749NameHash = UINT64_C(18129908718636931120);
    V8CompileHints_Version5& SetData749(int64_t value);

    static const char kData75Name[];
    static constexpr uint64_t kData75NameHash = UINT64_C(3633833304294248487);
    V8CompileHints_Version5& SetData75(int64_t value);

    static const char kData750Name[];
    static constexpr uint64_t kData750NameHash = UINT64_C(12494025866219997460);
    V8CompileHints_Version5& SetData750(int64_t value);

    static const char kData751Name[];
    static constexpr uint64_t kData751NameHash = UINT64_C(17897528194438305135);
    V8CompileHints_Version5& SetData751(int64_t value);

    static const char kData752Name[];
    static constexpr uint64_t kData752NameHash = UINT64_C(15257478260708281278);
    V8CompileHints_Version5& SetData752(int64_t value);

    static const char kData753Name[];
    static constexpr uint64_t kData753NameHash = UINT64_C(4158460463660322809);
    V8CompileHints_Version5& SetData753(int64_t value);

    static const char kData754Name[];
    static constexpr uint64_t kData754NameHash = UINT64_C(1358090048121162305);
    V8CompileHints_Version5& SetData754(int64_t value);

    static const char kData755Name[];
    static constexpr uint64_t kData755NameHash = UINT64_C(9403930459734858736);
    V8CompileHints_Version5& SetData755(int64_t value);

    static const char kData756Name[];
    static constexpr uint64_t kData756NameHash = UINT64_C(7339085426046004991);
    V8CompileHints_Version5& SetData756(int64_t value);

    static const char kData757Name[];
    static constexpr uint64_t kData757NameHash = UINT64_C(9884211844314273268);
    V8CompileHints_Version5& SetData757(int64_t value);

    static const char kData758Name[];
    static constexpr uint64_t kData758NameHash = UINT64_C(221413412620181940);
    V8CompileHints_Version5& SetData758(int64_t value);

    static const char kData759Name[];
    static constexpr uint64_t kData759NameHash = UINT64_C(4993494874889610914);
    V8CompileHints_Version5& SetData759(int64_t value);

    static const char kData76Name[];
    static constexpr uint64_t kData76NameHash = UINT64_C(9217722372704811221);
    V8CompileHints_Version5& SetData76(int64_t value);

    static const char kData760Name[];
    static constexpr uint64_t kData760NameHash = UINT64_C(8335911749144452810);
    V8CompileHints_Version5& SetData760(int64_t value);

    static const char kData761Name[];
    static constexpr uint64_t kData761NameHash = UINT64_C(206049307760741081);
    V8CompileHints_Version5& SetData761(int64_t value);

    static const char kData762Name[];
    static constexpr uint64_t kData762NameHash = UINT64_C(107087179333648107);
    V8CompileHints_Version5& SetData762(int64_t value);

    static const char kData763Name[];
    static constexpr uint64_t kData763NameHash = UINT64_C(12540689771944853817);
    V8CompileHints_Version5& SetData763(int64_t value);

    static const char kData764Name[];
    static constexpr uint64_t kData764NameHash = UINT64_C(11355678602705506396);
    V8CompileHints_Version5& SetData764(int64_t value);

    static const char kData765Name[];
    static constexpr uint64_t kData765NameHash = UINT64_C(13218683677197919851);
    V8CompileHints_Version5& SetData765(int64_t value);

    static const char kData766Name[];
    static constexpr uint64_t kData766NameHash = UINT64_C(9834408143451951712);
    V8CompileHints_Version5& SetData766(int64_t value);

    static const char kData767Name[];
    static constexpr uint64_t kData767NameHash = UINT64_C(15407106215782096149);
    V8CompileHints_Version5& SetData767(int64_t value);

    static const char kData768Name[];
    static constexpr uint64_t kData768NameHash = UINT64_C(9380338473288208655);
    V8CompileHints_Version5& SetData768(int64_t value);

    static const char kData769Name[];
    static constexpr uint64_t kData769NameHash = UINT64_C(6688570710721091971);
    V8CompileHints_Version5& SetData769(int64_t value);

    static const char kData77Name[];
    static constexpr uint64_t kData77NameHash = UINT64_C(7678980835984368970);
    V8CompileHints_Version5& SetData77(int64_t value);

    static const char kData770Name[];
    static constexpr uint64_t kData770NameHash = UINT64_C(11420243346981444423);
    V8CompileHints_Version5& SetData770(int64_t value);

    static const char kData771Name[];
    static constexpr uint64_t kData771NameHash = UINT64_C(1038806276238895482);
    V8CompileHints_Version5& SetData771(int64_t value);

    static const char kData772Name[];
    static constexpr uint64_t kData772NameHash = UINT64_C(13319492837665809823);
    V8CompileHints_Version5& SetData772(int64_t value);

    static const char kData773Name[];
    static constexpr uint64_t kData773NameHash = UINT64_C(12833846300695399180);
    V8CompileHints_Version5& SetData773(int64_t value);

    static const char kData774Name[];
    static constexpr uint64_t kData774NameHash = UINT64_C(7380954210365226543);
    V8CompileHints_Version5& SetData774(int64_t value);

    static const char kData775Name[];
    static constexpr uint64_t kData775NameHash = UINT64_C(8061391394658932623);
    V8CompileHints_Version5& SetData775(int64_t value);

    static const char kData776Name[];
    static constexpr uint64_t kData776NameHash = UINT64_C(10000218011567048325);
    V8CompileHints_Version5& SetData776(int64_t value);

    static const char kData777Name[];
    static constexpr uint64_t kData777NameHash = UINT64_C(7153740581491094933);
    V8CompileHints_Version5& SetData777(int64_t value);

    static const char kData778Name[];
    static constexpr uint64_t kData778NameHash = UINT64_C(14948194715267556863);
    V8CompileHints_Version5& SetData778(int64_t value);

    static const char kData779Name[];
    static constexpr uint64_t kData779NameHash = UINT64_C(9589999304162224569);
    V8CompileHints_Version5& SetData779(int64_t value);

    static const char kData78Name[];
    static constexpr uint64_t kData78NameHash = UINT64_C(8742453184626406260);
    V8CompileHints_Version5& SetData78(int64_t value);

    static const char kData780Name[];
    static constexpr uint64_t kData780NameHash = UINT64_C(16181040700245797287);
    V8CompileHints_Version5& SetData780(int64_t value);

    static const char kData781Name[];
    static constexpr uint64_t kData781NameHash = UINT64_C(569927214415502567);
    V8CompileHints_Version5& SetData781(int64_t value);

    static const char kData782Name[];
    static constexpr uint64_t kData782NameHash = UINT64_C(9096927806119658544);
    V8CompileHints_Version5& SetData782(int64_t value);

    static const char kData783Name[];
    static constexpr uint64_t kData783NameHash = UINT64_C(18310370368121526707);
    V8CompileHints_Version5& SetData783(int64_t value);

    static const char kData784Name[];
    static constexpr uint64_t kData784NameHash = UINT64_C(5079228851283469950);
    V8CompileHints_Version5& SetData784(int64_t value);

    static const char kData785Name[];
    static constexpr uint64_t kData785NameHash = UINT64_C(13792559662542810841);
    V8CompileHints_Version5& SetData785(int64_t value);

    static const char kData786Name[];
    static constexpr uint64_t kData786NameHash = UINT64_C(11313078565787403809);
    V8CompileHints_Version5& SetData786(int64_t value);

    static const char kData787Name[];
    static constexpr uint64_t kData787NameHash = UINT64_C(15279590556423439321);
    V8CompileHints_Version5& SetData787(int64_t value);

    static const char kData788Name[];
    static constexpr uint64_t kData788NameHash = UINT64_C(11791855452845463898);
    V8CompileHints_Version5& SetData788(int64_t value);

    static const char kData789Name[];
    static constexpr uint64_t kData789NameHash = UINT64_C(15906811480782530448);
    V8CompileHints_Version5& SetData789(int64_t value);

    static const char kData79Name[];
    static constexpr uint64_t kData79NameHash = UINT64_C(16414418257034622362);
    V8CompileHints_Version5& SetData79(int64_t value);

    static const char kData790Name[];
    static constexpr uint64_t kData790NameHash = UINT64_C(16203552377787878553);
    V8CompileHints_Version5& SetData790(int64_t value);

    static const char kData791Name[];
    static constexpr uint64_t kData791NameHash = UINT64_C(17356629371518917004);
    V8CompileHints_Version5& SetData791(int64_t value);

    static const char kData792Name[];
    static constexpr uint64_t kData792NameHash = UINT64_C(7484410406252583940);
    V8CompileHints_Version5& SetData792(int64_t value);

    static const char kData793Name[];
    static constexpr uint64_t kData793NameHash = UINT64_C(3197957949443256085);
    V8CompileHints_Version5& SetData793(int64_t value);

    static const char kData794Name[];
    static constexpr uint64_t kData794NameHash = UINT64_C(14519219073349750297);
    V8CompileHints_Version5& SetData794(int64_t value);

    static const char kData795Name[];
    static constexpr uint64_t kData795NameHash = UINT64_C(11835390347255775491);
    V8CompileHints_Version5& SetData795(int64_t value);

    static const char kData796Name[];
    static constexpr uint64_t kData796NameHash = UINT64_C(11511159127059695985);
    V8CompileHints_Version5& SetData796(int64_t value);

    static const char kData797Name[];
    static constexpr uint64_t kData797NameHash = UINT64_C(7106220137772585408);
    V8CompileHints_Version5& SetData797(int64_t value);

    static const char kData798Name[];
    static constexpr uint64_t kData798NameHash = UINT64_C(6151091818970384252);
    V8CompileHints_Version5& SetData798(int64_t value);

    static const char kData799Name[];
    static constexpr uint64_t kData799NameHash = UINT64_C(9699929142811102985);
    V8CompileHints_Version5& SetData799(int64_t value);

    static const char kData8Name[];
    static constexpr uint64_t kData8NameHash = UINT64_C(17369359774291489419);
    V8CompileHints_Version5& SetData8(int64_t value);

    static const char kData80Name[];
    static constexpr uint64_t kData80NameHash = UINT64_C(14517412534543068194);
    V8CompileHints_Version5& SetData80(int64_t value);

    static const char kData800Name[];
    static constexpr uint64_t kData800NameHash = UINT64_C(8179302210991331112);
    V8CompileHints_Version5& SetData800(int64_t value);

    static const char kData801Name[];
    static constexpr uint64_t kData801NameHash = UINT64_C(18302107034175204064);
    V8CompileHints_Version5& SetData801(int64_t value);

    static const char kData802Name[];
    static constexpr uint64_t kData802NameHash = UINT64_C(16286131808593544514);
    V8CompileHints_Version5& SetData802(int64_t value);

    static const char kData803Name[];
    static constexpr uint64_t kData803NameHash = UINT64_C(14504542783892271685);
    V8CompileHints_Version5& SetData803(int64_t value);

    static const char kData804Name[];
    static constexpr uint64_t kData804NameHash = UINT64_C(7740233491074058716);
    V8CompileHints_Version5& SetData804(int64_t value);

    static const char kData805Name[];
    static constexpr uint64_t kData805NameHash = UINT64_C(3520899653590476710);
    V8CompileHints_Version5& SetData805(int64_t value);

    static const char kData806Name[];
    static constexpr uint64_t kData806NameHash = UINT64_C(10958108307372425481);
    V8CompileHints_Version5& SetData806(int64_t value);

    static const char kData807Name[];
    static constexpr uint64_t kData807NameHash = UINT64_C(15418159627982662392);
    V8CompileHints_Version5& SetData807(int64_t value);

    static const char kData808Name[];
    static constexpr uint64_t kData808NameHash = UINT64_C(7612638421100159208);
    V8CompileHints_Version5& SetData808(int64_t value);

    static const char kData809Name[];
    static constexpr uint64_t kData809NameHash = UINT64_C(10249398421692458208);
    V8CompileHints_Version5& SetData809(int64_t value);

    static const char kData81Name[];
    static constexpr uint64_t kData81NameHash = UINT64_C(5855145616294642456);
    V8CompileHints_Version5& SetData81(int64_t value);

    static const char kData810Name[];
    static constexpr uint64_t kData810NameHash = UINT64_C(6224411067966028973);
    V8CompileHints_Version5& SetData810(int64_t value);

    static const char kData811Name[];
    static constexpr uint64_t kData811NameHash = UINT64_C(11679341803898088052);
    V8CompileHints_Version5& SetData811(int64_t value);

    static const char kData812Name[];
    static constexpr uint64_t kData812NameHash = UINT64_C(8284953792988685411);
    V8CompileHints_Version5& SetData812(int64_t value);

    static const char kData813Name[];
    static constexpr uint64_t kData813NameHash = UINT64_C(14541548709978903445);
    V8CompileHints_Version5& SetData813(int64_t value);

    static const char kData814Name[];
    static constexpr uint64_t kData814NameHash = UINT64_C(17100449189844525928);
    V8CompileHints_Version5& SetData814(int64_t value);

    static const char kData815Name[];
    static constexpr uint64_t kData815NameHash = UINT64_C(2559833625212937868);
    V8CompileHints_Version5& SetData815(int64_t value);

    static const char kData816Name[];
    static constexpr uint64_t kData816NameHash = UINT64_C(12173681226722671039);
    V8CompileHints_Version5& SetData816(int64_t value);

    static const char kData817Name[];
    static constexpr uint64_t kData817NameHash = UINT64_C(7082233246015449521);
    V8CompileHints_Version5& SetData817(int64_t value);

    static const char kData818Name[];
    static constexpr uint64_t kData818NameHash = UINT64_C(14676595369341572863);
    V8CompileHints_Version5& SetData818(int64_t value);

    static const char kData819Name[];
    static constexpr uint64_t kData819NameHash = UINT64_C(17666334562675611013);
    V8CompileHints_Version5& SetData819(int64_t value);

    static const char kData82Name[];
    static constexpr uint64_t kData82NameHash = UINT64_C(6683856238529524020);
    V8CompileHints_Version5& SetData82(int64_t value);

    static const char kData820Name[];
    static constexpr uint64_t kData820NameHash = UINT64_C(10096177712458667678);
    V8CompileHints_Version5& SetData820(int64_t value);

    static const char kData821Name[];
    static constexpr uint64_t kData821NameHash = UINT64_C(2365129186038643444);
    V8CompileHints_Version5& SetData821(int64_t value);

    static const char kData822Name[];
    static constexpr uint64_t kData822NameHash = UINT64_C(12389949272362919472);
    V8CompileHints_Version5& SetData822(int64_t value);

    static const char kData823Name[];
    static constexpr uint64_t kData823NameHash = UINT64_C(13980874385406250968);
    V8CompileHints_Version5& SetData823(int64_t value);

    static const char kData824Name[];
    static constexpr uint64_t kData824NameHash = UINT64_C(656947440986700780);
    V8CompileHints_Version5& SetData824(int64_t value);

    static const char kData825Name[];
    static constexpr uint64_t kData825NameHash = UINT64_C(17934260740823908904);
    V8CompileHints_Version5& SetData825(int64_t value);

    static const char kData826Name[];
    static constexpr uint64_t kData826NameHash = UINT64_C(6132555043898511538);
    V8CompileHints_Version5& SetData826(int64_t value);

    static const char kData827Name[];
    static constexpr uint64_t kData827NameHash = UINT64_C(219899745600278902);
    V8CompileHints_Version5& SetData827(int64_t value);

    static const char kData828Name[];
    static constexpr uint64_t kData828NameHash = UINT64_C(1210001898626981112);
    V8CompileHints_Version5& SetData828(int64_t value);

    static const char kData829Name[];
    static constexpr uint64_t kData829NameHash = UINT64_C(6760754350464429575);
    V8CompileHints_Version5& SetData829(int64_t value);

    static const char kData83Name[];
    static constexpr uint64_t kData83NameHash = UINT64_C(17205042470074059127);
    V8CompileHints_Version5& SetData83(int64_t value);

    static const char kData830Name[];
    static constexpr uint64_t kData830NameHash = UINT64_C(18259204988767196591);
    V8CompileHints_Version5& SetData830(int64_t value);

    static const char kData831Name[];
    static constexpr uint64_t kData831NameHash = UINT64_C(556994040647302433);
    V8CompileHints_Version5& SetData831(int64_t value);

    static const char kData832Name[];
    static constexpr uint64_t kData832NameHash = UINT64_C(13803464176067941196);
    V8CompileHints_Version5& SetData832(int64_t value);

    static const char kData833Name[];
    static constexpr uint64_t kData833NameHash = UINT64_C(3374903019180429272);
    V8CompileHints_Version5& SetData833(int64_t value);

    static const char kData834Name[];
    static constexpr uint64_t kData834NameHash = UINT64_C(11919767369280717514);
    V8CompileHints_Version5& SetData834(int64_t value);

    static const char kData835Name[];
    static constexpr uint64_t kData835NameHash = UINT64_C(1149915672105409371);
    V8CompileHints_Version5& SetData835(int64_t value);

    static const char kData836Name[];
    static constexpr uint64_t kData836NameHash = UINT64_C(16152550652570785084);
    V8CompileHints_Version5& SetData836(int64_t value);

    static const char kData837Name[];
    static constexpr uint64_t kData837NameHash = UINT64_C(1296276013700165786);
    V8CompileHints_Version5& SetData837(int64_t value);

    static const char kData838Name[];
    static constexpr uint64_t kData838NameHash = UINT64_C(2596000783555655929);
    V8CompileHints_Version5& SetData838(int64_t value);

    static const char kData839Name[];
    static constexpr uint64_t kData839NameHash = UINT64_C(7889475994187794311);
    V8CompileHints_Version5& SetData839(int64_t value);

    static const char kData84Name[];
    static constexpr uint64_t kData84NameHash = UINT64_C(7341361354510934017);
    V8CompileHints_Version5& SetData84(int64_t value);

    static const char kData840Name[];
    static constexpr uint64_t kData840NameHash = UINT64_C(3130458672219717418);
    V8CompileHints_Version5& SetData840(int64_t value);

    static const char kData841Name[];
    static constexpr uint64_t kData841NameHash = UINT64_C(6250844533397803149);
    V8CompileHints_Version5& SetData841(int64_t value);

    static const char kData842Name[];
    static constexpr uint64_t kData842NameHash = UINT64_C(11758615821160664);
    V8CompileHints_Version5& SetData842(int64_t value);

    static const char kData843Name[];
    static constexpr uint64_t kData843NameHash = UINT64_C(15709173546946007760);
    V8CompileHints_Version5& SetData843(int64_t value);

    static const char kData844Name[];
    static constexpr uint64_t kData844NameHash = UINT64_C(6975688804613721256);
    V8CompileHints_Version5& SetData844(int64_t value);

    static const char kData845Name[];
    static constexpr uint64_t kData845NameHash = UINT64_C(18282711533186921310);
    V8CompileHints_Version5& SetData845(int64_t value);

    static const char kData846Name[];
    static constexpr uint64_t kData846NameHash = UINT64_C(11120795879986991255);
    V8CompileHints_Version5& SetData846(int64_t value);

    static const char kData847Name[];
    static constexpr uint64_t kData847NameHash = UINT64_C(15740151075337350128);
    V8CompileHints_Version5& SetData847(int64_t value);

    static const char kData848Name[];
    static constexpr uint64_t kData848NameHash = UINT64_C(15776487367634844453);
    V8CompileHints_Version5& SetData848(int64_t value);

    static const char kData849Name[];
    static constexpr uint64_t kData849NameHash = UINT64_C(4370771286103827428);
    V8CompileHints_Version5& SetData849(int64_t value);

    static const char kData85Name[];
    static constexpr uint64_t kData85NameHash = UINT64_C(11809204502063710045);
    V8CompileHints_Version5& SetData85(int64_t value);

    static const char kData850Name[];
    static constexpr uint64_t kData850NameHash = UINT64_C(12345027693833814405);
    V8CompileHints_Version5& SetData850(int64_t value);

    static const char kData851Name[];
    static constexpr uint64_t kData851NameHash = UINT64_C(9372406653099413533);
    V8CompileHints_Version5& SetData851(int64_t value);

    static const char kData852Name[];
    static constexpr uint64_t kData852NameHash = UINT64_C(8344506543852281498);
    V8CompileHints_Version5& SetData852(int64_t value);

    static const char kData853Name[];
    static constexpr uint64_t kData853NameHash = UINT64_C(17932727180887786603);
    V8CompileHints_Version5& SetData853(int64_t value);

    static const char kData854Name[];
    static constexpr uint64_t kData854NameHash = UINT64_C(3618693875889397745);
    V8CompileHints_Version5& SetData854(int64_t value);

    static const char kData855Name[];
    static constexpr uint64_t kData855NameHash = UINT64_C(14964200568396639451);
    V8CompileHints_Version5& SetData855(int64_t value);

    static const char kData856Name[];
    static constexpr uint64_t kData856NameHash = UINT64_C(10158293130744018131);
    V8CompileHints_Version5& SetData856(int64_t value);

    static const char kData857Name[];
    static constexpr uint64_t kData857NameHash = UINT64_C(7870096787107892046);
    V8CompileHints_Version5& SetData857(int64_t value);

    static const char kData858Name[];
    static constexpr uint64_t kData858NameHash = UINT64_C(1110674850849117940);
    V8CompileHints_Version5& SetData858(int64_t value);

    static const char kData859Name[];
    static constexpr uint64_t kData859NameHash = UINT64_C(7939343378268707576);
    V8CompileHints_Version5& SetData859(int64_t value);

    static const char kData86Name[];
    static constexpr uint64_t kData86NameHash = UINT64_C(1147770807375488600);
    V8CompileHints_Version5& SetData86(int64_t value);

    static const char kData860Name[];
    static constexpr uint64_t kData860NameHash = UINT64_C(7188537084912364440);
    V8CompileHints_Version5& SetData860(int64_t value);

    static const char kData861Name[];
    static constexpr uint64_t kData861NameHash = UINT64_C(14975929474730960961);
    V8CompileHints_Version5& SetData861(int64_t value);

    static const char kData862Name[];
    static constexpr uint64_t kData862NameHash = UINT64_C(60385425229606179);
    V8CompileHints_Version5& SetData862(int64_t value);

    static const char kData863Name[];
    static constexpr uint64_t kData863NameHash = UINT64_C(13664426340839844303);
    V8CompileHints_Version5& SetData863(int64_t value);

    static const char kData864Name[];
    static constexpr uint64_t kData864NameHash = UINT64_C(6354406048401211256);
    V8CompileHints_Version5& SetData864(int64_t value);

    static const char kData865Name[];
    static constexpr uint64_t kData865NameHash = UINT64_C(306667783846758940);
    V8CompileHints_Version5& SetData865(int64_t value);

    static const char kData866Name[];
    static constexpr uint64_t kData866NameHash = UINT64_C(16617592989991046051);
    V8CompileHints_Version5& SetData866(int64_t value);

    static const char kData867Name[];
    static constexpr uint64_t kData867NameHash = UINT64_C(13377105132672391325);
    V8CompileHints_Version5& SetData867(int64_t value);

    static const char kData868Name[];
    static constexpr uint64_t kData868NameHash = UINT64_C(2604893092809299576);
    V8CompileHints_Version5& SetData868(int64_t value);

    static const char kData869Name[];
    static constexpr uint64_t kData869NameHash = UINT64_C(11631119409794679555);
    V8CompileHints_Version5& SetData869(int64_t value);

    static const char kData87Name[];
    static constexpr uint64_t kData87NameHash = UINT64_C(6679073693922105218);
    V8CompileHints_Version5& SetData87(int64_t value);

    static const char kData870Name[];
    static constexpr uint64_t kData870NameHash = UINT64_C(7391081369348588574);
    V8CompileHints_Version5& SetData870(int64_t value);

    static const char kData871Name[];
    static constexpr uint64_t kData871NameHash = UINT64_C(6779916168646814909);
    V8CompileHints_Version5& SetData871(int64_t value);

    static const char kData872Name[];
    static constexpr uint64_t kData872NameHash = UINT64_C(727444922804102631);
    V8CompileHints_Version5& SetData872(int64_t value);

    static const char kData873Name[];
    static constexpr uint64_t kData873NameHash = UINT64_C(16133506600128291699);
    V8CompileHints_Version5& SetData873(int64_t value);

    static const char kData874Name[];
    static constexpr uint64_t kData874NameHash = UINT64_C(1496098981691818841);
    V8CompileHints_Version5& SetData874(int64_t value);

    static const char kData875Name[];
    static constexpr uint64_t kData875NameHash = UINT64_C(15931014062213642483);
    V8CompileHints_Version5& SetData875(int64_t value);

    static const char kData876Name[];
    static constexpr uint64_t kData876NameHash = UINT64_C(4229153911415755052);
    V8CompileHints_Version5& SetData876(int64_t value);

    static const char kData877Name[];
    static constexpr uint64_t kData877NameHash = UINT64_C(2602489601437935234);
    V8CompileHints_Version5& SetData877(int64_t value);

    static const char kData878Name[];
    static constexpr uint64_t kData878NameHash = UINT64_C(4060905076318257955);
    V8CompileHints_Version5& SetData878(int64_t value);

    static const char kData879Name[];
    static constexpr uint64_t kData879NameHash = UINT64_C(18415048014229659244);
    V8CompileHints_Version5& SetData879(int64_t value);

    static const char kData88Name[];
    static constexpr uint64_t kData88NameHash = UINT64_C(4546096970374784779);
    V8CompileHints_Version5& SetData88(int64_t value);

    static const char kData880Name[];
    static constexpr uint64_t kData880NameHash = UINT64_C(13388972696679453722);
    V8CompileHints_Version5& SetData880(int64_t value);

    static const char kData881Name[];
    static constexpr uint64_t kData881NameHash = UINT64_C(877910216193871567);
    V8CompileHints_Version5& SetData881(int64_t value);

    static const char kData882Name[];
    static constexpr uint64_t kData882NameHash = UINT64_C(2002744780499501847);
    V8CompileHints_Version5& SetData882(int64_t value);

    static const char kData883Name[];
    static constexpr uint64_t kData883NameHash = UINT64_C(9702066100414955596);
    V8CompileHints_Version5& SetData883(int64_t value);

    static const char kData884Name[];
    static constexpr uint64_t kData884NameHash = UINT64_C(47576987671695754);
    V8CompileHints_Version5& SetData884(int64_t value);

    static const char kData885Name[];
    static constexpr uint64_t kData885NameHash = UINT64_C(9700935060570012958);
    V8CompileHints_Version5& SetData885(int64_t value);

    static const char kData886Name[];
    static constexpr uint64_t kData886NameHash = UINT64_C(5816779603891984542);
    V8CompileHints_Version5& SetData886(int64_t value);

    static const char kData887Name[];
    static constexpr uint64_t kData887NameHash = UINT64_C(14337106079712407587);
    V8CompileHints_Version5& SetData887(int64_t value);

    static const char kData888Name[];
    static constexpr uint64_t kData888NameHash = UINT64_C(12862170505984043693);
    V8CompileHints_Version5& SetData888(int64_t value);

    static const char kData889Name[];
    static constexpr uint64_t kData889NameHash = UINT64_C(485937724283397434);
    V8CompileHints_Version5& SetData889(int64_t value);

    static const char kData89Name[];
    static constexpr uint64_t kData89NameHash = UINT64_C(10428695585430592617);
    V8CompileHints_Version5& SetData89(int64_t value);

    static const char kData890Name[];
    static constexpr uint64_t kData890NameHash = UINT64_C(4125011042679673571);
    V8CompileHints_Version5& SetData890(int64_t value);

    static const char kData891Name[];
    static constexpr uint64_t kData891NameHash = UINT64_C(703022499272637450);
    V8CompileHints_Version5& SetData891(int64_t value);

    static const char kData892Name[];
    static constexpr uint64_t kData892NameHash = UINT64_C(2964627646471573769);
    V8CompileHints_Version5& SetData892(int64_t value);

    static const char kData893Name[];
    static constexpr uint64_t kData893NameHash = UINT64_C(16949515347989362800);
    V8CompileHints_Version5& SetData893(int64_t value);

    static const char kData894Name[];
    static constexpr uint64_t kData894NameHash = UINT64_C(10640100898977510401);
    V8CompileHints_Version5& SetData894(int64_t value);

    static const char kData895Name[];
    static constexpr uint64_t kData895NameHash = UINT64_C(8246103000354080841);
    V8CompileHints_Version5& SetData895(int64_t value);

    static const char kData896Name[];
    static constexpr uint64_t kData896NameHash = UINT64_C(14833791193561856126);
    V8CompileHints_Version5& SetData896(int64_t value);

    static const char kData897Name[];
    static constexpr uint64_t kData897NameHash = UINT64_C(4452504274855836379);
    V8CompileHints_Version5& SetData897(int64_t value);

    static const char kData898Name[];
    static constexpr uint64_t kData898NameHash = UINT64_C(8987988278134840833);
    V8CompileHints_Version5& SetData898(int64_t value);

    static const char kData899Name[];
    static constexpr uint64_t kData899NameHash = UINT64_C(16425851202456432632);
    V8CompileHints_Version5& SetData899(int64_t value);

    static const char kData9Name[];
    static constexpr uint64_t kData9NameHash = UINT64_C(183507090610026713);
    V8CompileHints_Version5& SetData9(int64_t value);

    static const char kData90Name[];
    static constexpr uint64_t kData90NameHash = UINT64_C(2299728526729800954);
    V8CompileHints_Version5& SetData90(int64_t value);

    static const char kData900Name[];
    static constexpr uint64_t kData900NameHash = UINT64_C(907637463836767634);
    V8CompileHints_Version5& SetData900(int64_t value);

    static const char kData901Name[];
    static constexpr uint64_t kData901NameHash = UINT64_C(1986744576567992126);
    V8CompileHints_Version5& SetData901(int64_t value);

    static const char kData902Name[];
    static constexpr uint64_t kData902NameHash = UINT64_C(2548856709577987415);
    V8CompileHints_Version5& SetData902(int64_t value);

    static const char kData903Name[];
    static constexpr uint64_t kData903NameHash = UINT64_C(11199188427358616436);
    V8CompileHints_Version5& SetData903(int64_t value);

    static const char kData904Name[];
    static constexpr uint64_t kData904NameHash = UINT64_C(2635149374856495761);
    V8CompileHints_Version5& SetData904(int64_t value);

    static const char kData905Name[];
    static constexpr uint64_t kData905NameHash = UINT64_C(17201211990056790084);
    V8CompileHints_Version5& SetData905(int64_t value);

    static const char kData906Name[];
    static constexpr uint64_t kData906NameHash = UINT64_C(11479717283097964602);
    V8CompileHints_Version5& SetData906(int64_t value);

    static const char kData907Name[];
    static constexpr uint64_t kData907NameHash = UINT64_C(16713396614129074094);
    V8CompileHints_Version5& SetData907(int64_t value);

    static const char kData908Name[];
    static constexpr uint64_t kData908NameHash = UINT64_C(1457163900820535861);
    V8CompileHints_Version5& SetData908(int64_t value);

    static const char kData909Name[];
    static constexpr uint64_t kData909NameHash = UINT64_C(15504611538348220849);
    V8CompileHints_Version5& SetData909(int64_t value);

    static const char kData91Name[];
    static constexpr uint64_t kData91NameHash = UINT64_C(4480826422484456147);
    V8CompileHints_Version5& SetData91(int64_t value);

    static const char kData910Name[];
    static constexpr uint64_t kData910NameHash = UINT64_C(11509676109433012406);
    V8CompileHints_Version5& SetData910(int64_t value);

    static const char kData911Name[];
    static constexpr uint64_t kData911NameHash = UINT64_C(16243212833039833432);
    V8CompileHints_Version5& SetData911(int64_t value);

    static const char kData912Name[];
    static constexpr uint64_t kData912NameHash = UINT64_C(13829368754300501186);
    V8CompileHints_Version5& SetData912(int64_t value);

    static const char kData913Name[];
    static constexpr uint64_t kData913NameHash = UINT64_C(8120275408181519471);
    V8CompileHints_Version5& SetData913(int64_t value);

    static const char kData914Name[];
    static constexpr uint64_t kData914NameHash = UINT64_C(8718327826118516401);
    V8CompileHints_Version5& SetData914(int64_t value);

    static const char kData915Name[];
    static constexpr uint64_t kData915NameHash = UINT64_C(9355027886519574336);
    V8CompileHints_Version5& SetData915(int64_t value);

    static const char kData916Name[];
    static constexpr uint64_t kData916NameHash = UINT64_C(18234703497453798642);
    V8CompileHints_Version5& SetData916(int64_t value);

    static const char kData917Name[];
    static constexpr uint64_t kData917NameHash = UINT64_C(5162947177854483119);
    V8CompileHints_Version5& SetData917(int64_t value);

    static const char kData918Name[];
    static constexpr uint64_t kData918NameHash = UINT64_C(1172564379841732903);
    V8CompileHints_Version5& SetData918(int64_t value);

    static const char kData919Name[];
    static constexpr uint64_t kData919NameHash = UINT64_C(11602072159495153488);
    V8CompileHints_Version5& SetData919(int64_t value);

    static const char kData92Name[];
    static constexpr uint64_t kData92NameHash = UINT64_C(8955840266503098958);
    V8CompileHints_Version5& SetData92(int64_t value);

    static const char kData920Name[];
    static constexpr uint64_t kData920NameHash = UINT64_C(8850138638239684390);
    V8CompileHints_Version5& SetData920(int64_t value);

    static const char kData921Name[];
    static constexpr uint64_t kData921NameHash = UINT64_C(15537092771059543752);
    V8CompileHints_Version5& SetData921(int64_t value);

    static const char kData922Name[];
    static constexpr uint64_t kData922NameHash = UINT64_C(2529351577040586919);
    V8CompileHints_Version5& SetData922(int64_t value);

    static const char kData923Name[];
    static constexpr uint64_t kData923NameHash = UINT64_C(14284680462235043982);
    V8CompileHints_Version5& SetData923(int64_t value);

    static const char kData924Name[];
    static constexpr uint64_t kData924NameHash = UINT64_C(12568517770889301434);
    V8CompileHints_Version5& SetData924(int64_t value);

    static const char kData925Name[];
    static constexpr uint64_t kData925NameHash = UINT64_C(14741895765449129574);
    V8CompileHints_Version5& SetData925(int64_t value);

    static const char kData926Name[];
    static constexpr uint64_t kData926NameHash = UINT64_C(7821414770904118302);
    V8CompileHints_Version5& SetData926(int64_t value);

    static const char kData927Name[];
    static constexpr uint64_t kData927NameHash = UINT64_C(7077636855039895266);
    V8CompileHints_Version5& SetData927(int64_t value);

    static const char kData928Name[];
    static constexpr uint64_t kData928NameHash = UINT64_C(13896187717450525689);
    V8CompileHints_Version5& SetData928(int64_t value);

    static const char kData929Name[];
    static constexpr uint64_t kData929NameHash = UINT64_C(4501074903564994645);
    V8CompileHints_Version5& SetData929(int64_t value);

    static const char kData93Name[];
    static constexpr uint64_t kData93NameHash = UINT64_C(8882365360005987332);
    V8CompileHints_Version5& SetData93(int64_t value);

    static const char kData930Name[];
    static constexpr uint64_t kData930NameHash = UINT64_C(5810664190215367656);
    V8CompileHints_Version5& SetData930(int64_t value);

    static const char kData931Name[];
    static constexpr uint64_t kData931NameHash = UINT64_C(14455710822855834099);
    V8CompileHints_Version5& SetData931(int64_t value);

    static const char kData932Name[];
    static constexpr uint64_t kData932NameHash = UINT64_C(3675619105217945929);
    V8CompileHints_Version5& SetData932(int64_t value);

    static const char kData933Name[];
    static constexpr uint64_t kData933NameHash = UINT64_C(10081120491544391457);
    V8CompileHints_Version5& SetData933(int64_t value);

    static const char kData934Name[];
    static constexpr uint64_t kData934NameHash = UINT64_C(6686118570017962099);
    V8CompileHints_Version5& SetData934(int64_t value);

    static const char kData935Name[];
    static constexpr uint64_t kData935NameHash = UINT64_C(9527420807261913226);
    V8CompileHints_Version5& SetData935(int64_t value);

    static const char kData936Name[];
    static constexpr uint64_t kData936NameHash = UINT64_C(6371654736518762482);
    V8CompileHints_Version5& SetData936(int64_t value);

    static const char kData937Name[];
    static constexpr uint64_t kData937NameHash = UINT64_C(13528467116264540983);
    V8CompileHints_Version5& SetData937(int64_t value);

    static const char kData938Name[];
    static constexpr uint64_t kData938NameHash = UINT64_C(6519618752768805941);
    V8CompileHints_Version5& SetData938(int64_t value);

    static const char kData939Name[];
    static constexpr uint64_t kData939NameHash = UINT64_C(10383091396014101115);
    V8CompileHints_Version5& SetData939(int64_t value);

    static const char kData94Name[];
    static constexpr uint64_t kData94NameHash = UINT64_C(14131839284803569069);
    V8CompileHints_Version5& SetData94(int64_t value);

    static const char kData940Name[];
    static constexpr uint64_t kData940NameHash = UINT64_C(6578710524826946158);
    V8CompileHints_Version5& SetData940(int64_t value);

    static const char kData941Name[];
    static constexpr uint64_t kData941NameHash = UINT64_C(13009550101891185904);
    V8CompileHints_Version5& SetData941(int64_t value);

    static const char kData942Name[];
    static constexpr uint64_t kData942NameHash = UINT64_C(11808826704237386686);
    V8CompileHints_Version5& SetData942(int64_t value);

    static const char kData943Name[];
    static constexpr uint64_t kData943NameHash = UINT64_C(11818359147557089310);
    V8CompileHints_Version5& SetData943(int64_t value);

    static const char kData944Name[];
    static constexpr uint64_t kData944NameHash = UINT64_C(6666304908395824758);
    V8CompileHints_Version5& SetData944(int64_t value);

    static const char kData945Name[];
    static constexpr uint64_t kData945NameHash = UINT64_C(15249917751331382396);
    V8CompileHints_Version5& SetData945(int64_t value);

    static const char kData946Name[];
    static constexpr uint64_t kData946NameHash = UINT64_C(7317347311901213872);
    V8CompileHints_Version5& SetData946(int64_t value);

    static const char kData947Name[];
    static constexpr uint64_t kData947NameHash = UINT64_C(8110670464016332332);
    V8CompileHints_Version5& SetData947(int64_t value);

    static const char kData948Name[];
    static constexpr uint64_t kData948NameHash = UINT64_C(929476770630338558);
    V8CompileHints_Version5& SetData948(int64_t value);

    static const char kData949Name[];
    static constexpr uint64_t kData949NameHash = UINT64_C(9853701649876668280);
    V8CompileHints_Version5& SetData949(int64_t value);

    static const char kData95Name[];
    static constexpr uint64_t kData95NameHash = UINT64_C(7721487877952830216);
    V8CompileHints_Version5& SetData95(int64_t value);

    static const char kData950Name[];
    static constexpr uint64_t kData950NameHash = UINT64_C(16569482879115976664);
    V8CompileHints_Version5& SetData950(int64_t value);

    static const char kData951Name[];
    static constexpr uint64_t kData951NameHash = UINT64_C(10660487966439673391);
    V8CompileHints_Version5& SetData951(int64_t value);

    static const char kData952Name[];
    static constexpr uint64_t kData952NameHash = UINT64_C(1581614350102829561);
    V8CompileHints_Version5& SetData952(int64_t value);

    static const char kData953Name[];
    static constexpr uint64_t kData953NameHash = UINT64_C(12749971616187501519);
    V8CompileHints_Version5& SetData953(int64_t value);

    static const char kData954Name[];
    static constexpr uint64_t kData954NameHash = UINT64_C(108962185569588409);
    V8CompileHints_Version5& SetData954(int64_t value);

    static const char kData955Name[];
    static constexpr uint64_t kData955NameHash = UINT64_C(2532046117828797662);
    V8CompileHints_Version5& SetData955(int64_t value);

    static const char kData956Name[];
    static constexpr uint64_t kData956NameHash = UINT64_C(489356586843000581);
    V8CompileHints_Version5& SetData956(int64_t value);

    static const char kData957Name[];
    static constexpr uint64_t kData957NameHash = UINT64_C(14978015010071696228);
    V8CompileHints_Version5& SetData957(int64_t value);

    static const char kData958Name[];
    static constexpr uint64_t kData958NameHash = UINT64_C(10452142416361656435);
    V8CompileHints_Version5& SetData958(int64_t value);

    static const char kData959Name[];
    static constexpr uint64_t kData959NameHash = UINT64_C(11011354825429091909);
    V8CompileHints_Version5& SetData959(int64_t value);

    static const char kData96Name[];
    static constexpr uint64_t kData96NameHash = UINT64_C(12197577101260520910);
    V8CompileHints_Version5& SetData96(int64_t value);

    static const char kData960Name[];
    static constexpr uint64_t kData960NameHash = UINT64_C(7541714172191976940);
    V8CompileHints_Version5& SetData960(int64_t value);

    static const char kData961Name[];
    static constexpr uint64_t kData961NameHash = UINT64_C(1920999729270936020);
    V8CompileHints_Version5& SetData961(int64_t value);

    static const char kData962Name[];
    static constexpr uint64_t kData962NameHash = UINT64_C(11428538851712684166);
    V8CompileHints_Version5& SetData962(int64_t value);

    static const char kData963Name[];
    static constexpr uint64_t kData963NameHash = UINT64_C(5270537433578059973);
    V8CompileHints_Version5& SetData963(int64_t value);

    static const char kData964Name[];
    static constexpr uint64_t kData964NameHash = UINT64_C(14444965904127258054);
    V8CompileHints_Version5& SetData964(int64_t value);

    static const char kData965Name[];
    static constexpr uint64_t kData965NameHash = UINT64_C(16842780604389044922);
    V8CompileHints_Version5& SetData965(int64_t value);

    static const char kData966Name[];
    static constexpr uint64_t kData966NameHash = UINT64_C(15772343591472794606);
    V8CompileHints_Version5& SetData966(int64_t value);

    static const char kData967Name[];
    static constexpr uint64_t kData967NameHash = UINT64_C(11483540003991778299);
    V8CompileHints_Version5& SetData967(int64_t value);

    static const char kData968Name[];
    static constexpr uint64_t kData968NameHash = UINT64_C(13080156465323949633);
    V8CompileHints_Version5& SetData968(int64_t value);

    static const char kData969Name[];
    static constexpr uint64_t kData969NameHash = UINT64_C(17421491270378935982);
    V8CompileHints_Version5& SetData969(int64_t value);

    static const char kData97Name[];
    static constexpr uint64_t kData97NameHash = UINT64_C(10487995622792157880);
    V8CompileHints_Version5& SetData97(int64_t value);

    static const char kData970Name[];
    static constexpr uint64_t kData970NameHash = UINT64_C(4317753346335638370);
    V8CompileHints_Version5& SetData970(int64_t value);

    static const char kData971Name[];
    static constexpr uint64_t kData971NameHash = UINT64_C(2293708348183663150);
    V8CompileHints_Version5& SetData971(int64_t value);

    static const char kData972Name[];
    static constexpr uint64_t kData972NameHash = UINT64_C(8218160764406186610);
    V8CompileHints_Version5& SetData972(int64_t value);

    static const char kData973Name[];
    static constexpr uint64_t kData973NameHash = UINT64_C(7115254073253000163);
    V8CompileHints_Version5& SetData973(int64_t value);

    static const char kData974Name[];
    static constexpr uint64_t kData974NameHash = UINT64_C(11550692223249631030);
    V8CompileHints_Version5& SetData974(int64_t value);

    static const char kData975Name[];
    static constexpr uint64_t kData975NameHash = UINT64_C(11659046452629546647);
    V8CompileHints_Version5& SetData975(int64_t value);

    static const char kData976Name[];
    static constexpr uint64_t kData976NameHash = UINT64_C(11590679596716223121);
    V8CompileHints_Version5& SetData976(int64_t value);

    static const char kData977Name[];
    static constexpr uint64_t kData977NameHash = UINT64_C(18427874241029382222);
    V8CompileHints_Version5& SetData977(int64_t value);

    static const char kData978Name[];
    static constexpr uint64_t kData978NameHash = UINT64_C(6605774147849690395);
    V8CompileHints_Version5& SetData978(int64_t value);

    static const char kData979Name[];
    static constexpr uint64_t kData979NameHash = UINT64_C(15102543613087726361);
    V8CompileHints_Version5& SetData979(int64_t value);

    static const char kData98Name[];
    static constexpr uint64_t kData98NameHash = UINT64_C(3513171694677301201);
    V8CompileHints_Version5& SetData98(int64_t value);

    static const char kData980Name[];
    static constexpr uint64_t kData980NameHash = UINT64_C(5432118877664213952);
    V8CompileHints_Version5& SetData980(int64_t value);

    static const char kData981Name[];
    static constexpr uint64_t kData981NameHash = UINT64_C(6213527670525023812);
    V8CompileHints_Version5& SetData981(int64_t value);

    static const char kData982Name[];
    static constexpr uint64_t kData982NameHash = UINT64_C(16513194443479813384);
    V8CompileHints_Version5& SetData982(int64_t value);

    static const char kData983Name[];
    static constexpr uint64_t kData983NameHash = UINT64_C(16717369042755634207);
    V8CompileHints_Version5& SetData983(int64_t value);

    static const char kData984Name[];
    static constexpr uint64_t kData984NameHash = UINT64_C(11994727926775303032);
    V8CompileHints_Version5& SetData984(int64_t value);

    static const char kData985Name[];
    static constexpr uint64_t kData985NameHash = UINT64_C(6604806700206906491);
    V8CompileHints_Version5& SetData985(int64_t value);

    static const char kData986Name[];
    static constexpr uint64_t kData986NameHash = UINT64_C(13702524095711887009);
    V8CompileHints_Version5& SetData986(int64_t value);

    static const char kData987Name[];
    static constexpr uint64_t kData987NameHash = UINT64_C(15678990507932788859);
    V8CompileHints_Version5& SetData987(int64_t value);

    static const char kData988Name[];
    static constexpr uint64_t kData988NameHash = UINT64_C(36163242262006015);
    V8CompileHints_Version5& SetData988(int64_t value);

    static const char kData989Name[];
    static constexpr uint64_t kData989NameHash = UINT64_C(8969438891708993434);
    V8CompileHints_Version5& SetData989(int64_t value);

    static const char kData99Name[];
    static constexpr uint64_t kData99NameHash = UINT64_C(625319131471587651);
    V8CompileHints_Version5& SetData99(int64_t value);

    static const char kData990Name[];
    static constexpr uint64_t kData990NameHash = UINT64_C(2997395300945129370);
    V8CompileHints_Version5& SetData990(int64_t value);

    static const char kData991Name[];
    static constexpr uint64_t kData991NameHash = UINT64_C(3846866476681798990);
    V8CompileHints_Version5& SetData991(int64_t value);

    static const char kData992Name[];
    static constexpr uint64_t kData992NameHash = UINT64_C(6241433172993672915);
    V8CompileHints_Version5& SetData992(int64_t value);

    static const char kData993Name[];
    static constexpr uint64_t kData993NameHash = UINT64_C(6400994771608445499);
    V8CompileHints_Version5& SetData993(int64_t value);

    static const char kData994Name[];
    static constexpr uint64_t kData994NameHash = UINT64_C(1103582108674405260);
    V8CompileHints_Version5& SetData994(int64_t value);

    static const char kData995Name[];
    static constexpr uint64_t kData995NameHash = UINT64_C(4751152376241900678);
    V8CompileHints_Version5& SetData995(int64_t value);

    static const char kData996Name[];
    static constexpr uint64_t kData996NameHash = UINT64_C(14765148725870957432);
    V8CompileHints_Version5& SetData996(int64_t value);

    static const char kData997Name[];
    static constexpr uint64_t kData997NameHash = UINT64_C(12850455910748467880);
    V8CompileHints_Version5& SetData997(int64_t value);

    static const char kData998Name[];
    static constexpr uint64_t kData998NameHash = UINT64_C(17046055395851303893);
    V8CompileHints_Version5& SetData998(int64_t value);

    static const char kData999Name[];
    static constexpr uint64_t kData999NameHash = UINT64_C(3067078823605397950);
    V8CompileHints_Version5& SetData999(int64_t value);
};

class VideoConferencingEvent final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit VideoConferencingEvent(ukm::SourceId source_id);
    explicit VideoConferencingEvent(ukm::SourceIdObj source_id);
    VideoConferencingEvent(VideoConferencingEvent&&);
    VideoConferencingEvent& operator=(VideoConferencingEvent&&);
    ~VideoConferencingEvent() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13751685094429308900);

    static const char kCameraCaptureDurationName[];
    static constexpr uint64_t kCameraCaptureDurationNameHash = UINT64_C(6678031813125258299);
    VideoConferencingEvent& SetCameraCaptureDuration(int64_t value);

    static const char kDidCaptureCameraName[];
    static constexpr uint64_t kDidCaptureCameraNameHash = UINT64_C(4807300001380451453);
    VideoConferencingEvent& SetDidCaptureCamera(int64_t value);

    static const char kDidCaptureMicrophoneName[];
    static constexpr uint64_t kDidCaptureMicrophoneNameHash = UINT64_C(5899099474296701207);
    VideoConferencingEvent& SetDidCaptureMicrophone(int64_t value);

    static const char kDidCaptureScreenName[];
    static constexpr uint64_t kDidCaptureScreenNameHash = UINT64_C(6190107993427348284);
    VideoConferencingEvent& SetDidCaptureScreen(int64_t value);

    static const char kMicrophoneCaptureDurationName[];
    static constexpr uint64_t kMicrophoneCaptureDurationNameHash = UINT64_C(17129386129143241962);
    VideoConferencingEvent& SetMicrophoneCaptureDuration(int64_t value);

    static const char kScreenCaptureDurationName[];
    static constexpr uint64_t kScreenCaptureDurationNameHash = UINT64_C(15573229505023547614);
    VideoConferencingEvent& SetScreenCaptureDuration(int64_t value);

    static const char kTotalDurationName[];
    static constexpr uint64_t kTotalDurationNameHash = UINT64_C(491625579949459591);
    VideoConferencingEvent& SetTotalDuration(int64_t value);
};

class VirtualKeyboard_Open final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit VirtualKeyboard_Open(ukm::SourceId source_id);
    explicit VirtualKeyboard_Open(ukm::SourceIdObj source_id);
    VirtualKeyboard_Open(VirtualKeyboard_Open&&);
    VirtualKeyboard_Open& operator=(VirtualKeyboard_Open&&);
    ~VirtualKeyboard_Open() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(3904325154478962694);

    static const char kTextInputTypeName[];
    static constexpr uint64_t kTextInputTypeNameHash = UINT64_C(6049523454185107552);
    VirtualKeyboard_Open& SetTextInputType(int64_t value);
};

class Wallet_BoardingPassDetect final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Wallet_BoardingPassDetect(ukm::SourceId source_id);
    explicit Wallet_BoardingPassDetect(ukm::SourceIdObj source_id);
    Wallet_BoardingPassDetect(Wallet_BoardingPassDetect&&);
    Wallet_BoardingPassDetect& operator=(Wallet_BoardingPassDetect&&);
    ~Wallet_BoardingPassDetect() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(16867238133244431157);

    static const char kDetectedName[];
    static constexpr uint64_t kDetectedNameHash = UINT64_C(5286907366254680517);
    Wallet_BoardingPassDetect& SetDetected(int64_t value);
};

class WebAPK_Install final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAPK_Install(ukm::SourceId source_id);
    explicit WebAPK_Install(ukm::SourceIdObj source_id);
    WebAPK_Install(WebAPK_Install&&);
    WebAPK_Install& operator=(WebAPK_Install&&);
    ~WebAPK_Install() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(12193435703081602033);

    static const char kDisplayModeName[];
    static constexpr uint64_t kDisplayModeNameHash = UINT64_C(12581275766339648725);
    WebAPK_Install& SetDisplayMode(int64_t value);

    static const char kDistributorName[];
    static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
    WebAPK_Install& SetDistributor(int64_t value);

    static const char kInstallName[];
    static constexpr uint64_t kInstallNameHash = UINT64_C(3789841737615482174);
    WebAPK_Install& SetInstall(int64_t value);

    static const char kInstallSourceName[];
    static constexpr uint64_t kInstallSourceNameHash = UINT64_C(7897354207534621578);
    WebAPK_Install& SetInstallSource(int64_t value);
};

class WebAPK_SessionEnd final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAPK_SessionEnd(ukm::SourceId source_id);
    explicit WebAPK_SessionEnd(ukm::SourceIdObj source_id);
    WebAPK_SessionEnd(WebAPK_SessionEnd&&);
    WebAPK_SessionEnd& operator=(WebAPK_SessionEnd&&);
    ~WebAPK_SessionEnd() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(304278077624055651);

    static const char kAppVersionName[];
    static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
    WebAPK_SessionEnd& SetAppVersion(int64_t value);

    static const char kDistributorName[];
    static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
    WebAPK_SessionEnd& SetDistributor(int64_t value);

    static const char kSessionDurationName[];
    static constexpr uint64_t kSessionDurationNameHash = UINT64_C(2701974374748336509);
    WebAPK_SessionEnd& SetSessionDuration(int64_t value);
};

class WebAPK_Uninstall final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAPK_Uninstall(ukm::SourceId source_id);
    explicit WebAPK_Uninstall(ukm::SourceIdObj source_id);
    WebAPK_Uninstall(WebAPK_Uninstall&&);
    WebAPK_Uninstall& operator=(WebAPK_Uninstall&&);
    ~WebAPK_Uninstall() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15147671640732652143);

    static const char kAppVersionName[];
    static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
    WebAPK_Uninstall& SetAppVersion(int64_t value);

    static const char kDistributorName[];
    static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
    WebAPK_Uninstall& SetDistributor(int64_t value);

    static const char kInstalledDurationName[];
    static constexpr uint64_t kInstalledDurationNameHash = UINT64_C(8139225208300052851);
    WebAPK_Uninstall& SetInstalledDuration(int64_t value);

    static const char kLifetimeLaunchesName[];
    static constexpr uint64_t kLifetimeLaunchesNameHash = UINT64_C(14300233011189208559);
    WebAPK_Uninstall& SetLifetimeLaunches(int64_t value);

    static const char kUninstallName[];
    static constexpr uint64_t kUninstallNameHash = UINT64_C(11708794393683665055);
    WebAPK_Uninstall& SetUninstall(int64_t value);
};

class WebAPK_Visit final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAPK_Visit(ukm::SourceId source_id);
    explicit WebAPK_Visit(ukm::SourceIdObj source_id);
    WebAPK_Visit(WebAPK_Visit&&);
    WebAPK_Visit& operator=(WebAPK_Visit&&);
    ~WebAPK_Visit() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7419239618516179300);

    static const char kAppVersionName[];
    static constexpr uint64_t kAppVersionNameHash = UINT64_C(333571752519763750);
    WebAPK_Visit& SetAppVersion(int64_t value);

    static const char kDistributorName[];
    static constexpr uint64_t kDistributorNameHash = UINT64_C(8247396947590737646);
    WebAPK_Visit& SetDistributor(int64_t value);

    static const char kLaunchName[];
    static constexpr uint64_t kLaunchNameHash = UINT64_C(10738535331188906759);
    WebAPK_Visit& SetLaunch(int64_t value);

    static const char kLaunchSourceName[];
    static constexpr uint64_t kLaunchSourceNameHash = UINT64_C(5360095524695749322);
    WebAPK_Visit& SetLaunchSource(int64_t value);
};

class Webapp_AddToHomeScreen final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Webapp_AddToHomeScreen(ukm::SourceId source_id);
    explicit Webapp_AddToHomeScreen(ukm::SourceIdObj source_id);
    Webapp_AddToHomeScreen(Webapp_AddToHomeScreen&&);
    Webapp_AddToHomeScreen& operator=(Webapp_AddToHomeScreen&&);
    ~Webapp_AddToHomeScreen() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17489292060937518703);

    static const char kDisplayModeName[];
    static constexpr uint64_t kDisplayModeNameHash = UINT64_C(12581275766339648725);
    Webapp_AddToHomeScreen& SetDisplayMode(int64_t value);

    static const char kSameAsManifestStartUrlName[];
    static constexpr uint64_t kSameAsManifestStartUrlNameHash = UINT64_C(2343270875302892503);
    Webapp_AddToHomeScreen& SetSameAsManifestStartUrl(int64_t value);

    static const char kShortcutReasonName[];
    static constexpr uint64_t kShortcutReasonNameHash = UINT64_C(18163638025754419753);
    Webapp_AddToHomeScreen& SetShortcutReason(int64_t value);
};

class WebApp_DailyInteraction final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebApp_DailyInteraction(ukm::SourceId source_id);
    explicit WebApp_DailyInteraction(ukm::SourceIdObj source_id);
    WebApp_DailyInteraction(WebApp_DailyInteraction&&);
    WebApp_DailyInteraction& operator=(WebApp_DailyInteraction&&);
    ~WebApp_DailyInteraction() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10823086981545979708);

    static const char kBackgroundDurationName[];
    static constexpr uint64_t kBackgroundDurationNameHash = UINT64_C(11993638961121254288);
    WebApp_DailyInteraction& SetBackgroundDuration(int64_t value);

    static const char kCapturesLinksName[];
    static constexpr uint64_t kCapturesLinksNameHash = UINT64_C(2540755936465675141);
    WebApp_DailyInteraction& SetCapturesLinks(int64_t value);

    static const char kDisplayModeName[];
    static constexpr uint64_t kDisplayModeNameHash = UINT64_C(12581275766339648725);
    WebApp_DailyInteraction& SetDisplayMode(int64_t value);

    static const char kForegroundDurationName[];
    static constexpr uint64_t kForegroundDurationNameHash = UINT64_C(14040493619853098912);
    WebApp_DailyInteraction& SetForegroundDuration(int64_t value);

    static const char kInstalledName[];
    static constexpr uint64_t kInstalledNameHash = UINT64_C(11015034891594477851);
    WebApp_DailyInteraction& SetInstalled(int64_t value);

    static const char kInstallSourceName[];
    static constexpr uint64_t kInstallSourceNameHash = UINT64_C(7897354207534621578);
    WebApp_DailyInteraction& SetInstallSource(int64_t value);

    static const char kNumSessionsName[];
    static constexpr uint64_t kNumSessionsNameHash = UINT64_C(6349061493514857092);
    WebApp_DailyInteraction& SetNumSessions(int64_t value);

    static const char kPromotableName[];
    static constexpr uint64_t kPromotableNameHash = UINT64_C(16843428730026040799);
    WebApp_DailyInteraction& SetPromotable(int64_t value);

    static const char kUsedName[];
    static constexpr uint64_t kUsedNameHash = UINT64_C(116280672541001035);
    WebApp_DailyInteraction& SetUsed(int64_t value);
};

class WebAuthn_ConditionalUiGetCall final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAuthn_ConditionalUiGetCall(ukm::SourceId source_id);
    explicit WebAuthn_ConditionalUiGetCall(ukm::SourceIdObj source_id);
    WebAuthn_ConditionalUiGetCall(WebAuthn_ConditionalUiGetCall&&);
    WebAuthn_ConditionalUiGetCall& operator=(WebAuthn_ConditionalUiGetCall&&);
    ~WebAuthn_ConditionalUiGetCall() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(10568617214355697205);

    static const char kTimeSinceDomContentLoadedName[];
    static constexpr uint64_t kTimeSinceDomContentLoadedNameHash = UINT64_C(10417823736900703018);
    WebAuthn_ConditionalUiGetCall& SetTimeSinceDomContentLoaded(int64_t value);
};

class WebAuthn_RegisterCompletion final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAuthn_RegisterCompletion(ukm::SourceId source_id);
    explicit WebAuthn_RegisterCompletion(ukm::SourceIdObj source_id);
    WebAuthn_RegisterCompletion(WebAuthn_RegisterCompletion&&);
    WebAuthn_RegisterCompletion& operator=(WebAuthn_RegisterCompletion&&);
    ~WebAuthn_RegisterCompletion() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(13818196675028885634);

    static const char kRegisterCompletionResultName[];
    static constexpr uint64_t kRegisterCompletionResultNameHash = UINT64_C(4429686185327565675);
    WebAuthn_RegisterCompletion& SetRegisterCompletionResult(int64_t value);

    static const char kRequestModeName[];
    static constexpr uint64_t kRequestModeNameHash = UINT64_C(8559224737499631640);
    WebAuthn_RegisterCompletion& SetRequestMode(int64_t value);
};

class WebAuthn_SignCompletion final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebAuthn_SignCompletion(ukm::SourceId source_id);
    explicit WebAuthn_SignCompletion(ukm::SourceIdObj source_id);
    WebAuthn_SignCompletion(WebAuthn_SignCompletion&&);
    WebAuthn_SignCompletion& operator=(WebAuthn_SignCompletion&&);
    ~WebAuthn_SignCompletion() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15241522087642277816);

    static const char kRequestModeName[];
    static constexpr uint64_t kRequestModeNameHash = UINT64_C(8559224737499631640);
    WebAuthn_SignCompletion& SetRequestMode(int64_t value);

    static const char kSignCompletionResultName[];
    static constexpr uint64_t kSignCompletionResultNameHash = UINT64_C(2394106997026630596);
    WebAuthn_SignCompletion& SetSignCompletionResult(int64_t value);
};

class WebOTPImpact final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebOTPImpact(ukm::SourceId source_id);
    explicit WebOTPImpact(ukm::SourceIdObj source_id);
    WebOTPImpact(WebOTPImpact&&);
    WebOTPImpact& operator=(WebOTPImpact&&);
    ~WebOTPImpact() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(17612510707700865831);

    static const char kPhoneCollectionName[];
    static constexpr uint64_t kPhoneCollectionNameHash = UINT64_C(11935312185914297479);
    WebOTPImpact& SetPhoneCollection(int64_t value);
};

class WebRTC_AddressHarvesting final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebRTC_AddressHarvesting(ukm::SourceId source_id);
    explicit WebRTC_AddressHarvesting(ukm::SourceIdObj source_id);
    WebRTC_AddressHarvesting(WebRTC_AddressHarvesting&&);
    WebRTC_AddressHarvesting& operator=(WebRTC_AddressHarvesting&&);
    ~WebRTC_AddressHarvesting() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(6759459948386423184);

    static const char kUsagePatternName[];
    static constexpr uint64_t kUsagePatternNameHash = UINT64_C(2048621503660355193);
    WebRTC_AddressHarvesting& SetUsagePattern(int64_t value);
};

class WebRTC_ComplexSdp final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WebRTC_ComplexSdp(ukm::SourceId source_id);
    explicit WebRTC_ComplexSdp(ukm::SourceIdObj source_id);
    WebRTC_ComplexSdp(WebRTC_ComplexSdp&&);
    WebRTC_ComplexSdp& operator=(WebRTC_ComplexSdp&&);
    ~WebRTC_ComplexSdp() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7456919696038345904);

    static const char kCategoryName[];
    static constexpr uint64_t kCategoryNameHash = UINT64_C(4241224519481557898);
    WebRTC_ComplexSdp& SetCategory(int64_t value);
};

class WindowProxyUsage final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit WindowProxyUsage(ukm::SourceId source_id);
    explicit WindowProxyUsage(ukm::SourceIdObj source_id);
    WindowProxyUsage(WindowProxyUsage&&);
    WindowProxyUsage& operator=(WindowProxyUsage&&);
    ~WindowProxyUsage() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(7117761419315601762);

    static const char kAccessTypeName[];
    static constexpr uint64_t kAccessTypeNameHash = UINT64_C(14082856430404456345);
    WindowProxyUsage& SetAccessType(int64_t value);

    static const char kIsSamePageName[];
    static constexpr uint64_t kIsSamePageNameHash = UINT64_C(16069397676861864018);
    WindowProxyUsage& SetIsSamePage(int64_t value);

    static const char kLocalFrameContextName[];
    static constexpr uint64_t kLocalFrameContextNameHash = UINT64_C(8500408449673532128);
    WindowProxyUsage& SetLocalFrameContext(int64_t value);

    static const char kLocalPageContextName[];
    static constexpr uint64_t kLocalPageContextNameHash = UINT64_C(11224877600886433659);
    WindowProxyUsage& SetLocalPageContext(int64_t value);

    static const char kLocalUserActivationStateName[];
    static constexpr uint64_t kLocalUserActivationStateNameHash = UINT64_C(4665337674344662690);
    WindowProxyUsage& SetLocalUserActivationState(int64_t value);

    static const char kRemoteFrameContextName[];
    static constexpr uint64_t kRemoteFrameContextNameHash = UINT64_C(8382190263217194383);
    WindowProxyUsage& SetRemoteFrameContext(int64_t value);

    static const char kRemotePageContextName[];
    static constexpr uint64_t kRemotePageContextNameHash = UINT64_C(17585414079876608573);
    WindowProxyUsage& SetRemotePageContext(int64_t value);

    static const char kRemoteUserActivationStateName[];
    static constexpr uint64_t kRemoteUserActivationStateNameHash = UINT64_C(14174062418359721783);
    WindowProxyUsage& SetRemoteUserActivationState(int64_t value);

    static const char kStorageKeyComparisonName[];
    static constexpr uint64_t kStorageKeyComparisonNameHash = UINT64_C(5247437214358308486);
    WindowProxyUsage& SetStorageKeyComparison(int64_t value);
};

class Worker_ClientAdded final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit Worker_ClientAdded(ukm::SourceId source_id);
    explicit Worker_ClientAdded(ukm::SourceIdObj source_id);
    Worker_ClientAdded(Worker_ClientAdded&&);
    Worker_ClientAdded& operator=(Worker_ClientAdded&&);
    ~Worker_ClientAdded() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(11030368718596656137);

    static const char kClientSourceIdName[];
    static constexpr uint64_t kClientSourceIdNameHash = UINT64_C(9413451302033519885);
    Worker_ClientAdded& SetClientSourceId(int64_t value);

    static const char kWorkerTypeName[];
    static constexpr uint64_t kWorkerTypeNameHash = UINT64_C(7679145406125110851);
    Worker_ClientAdded& SetWorkerType(int64_t value);
};

class XR_WebXR final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit XR_WebXR(ukm::SourceId source_id);
    explicit XR_WebXR(ukm::SourceIdObj source_id);
    XR_WebXR(XR_WebXR&&);
    XR_WebXR& operator=(XR_WebXR&&);
    ~XR_WebXR() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(2966287978545946180);

    static const char kDidGetXRInputSourcesName[];
    static constexpr uint64_t kDidGetXRInputSourcesNameHash = UINT64_C(14351844110769922173);
    XR_WebXR& SetDidGetXRInputSources(int64_t value);

    static const char kDidRequestAvailableDevicesName[];
    static constexpr uint64_t kDidRequestAvailableDevicesNameHash = UINT64_C(5107681164098988581);
    XR_WebXR& SetDidRequestAvailableDevices(int64_t value);

    static const char kDidRequestPoseName[];
    static constexpr uint64_t kDidRequestPoseNameHash = UINT64_C(1918328077075117272);
    XR_WebXR& SetDidRequestPose(int64_t value);

    static const char kDidRequestPresentationName[];
    static constexpr uint64_t kDidRequestPresentationNameHash = UINT64_C(15657914383994855428);
    XR_WebXR& SetDidRequestPresentation(int64_t value);

    static const char kDidUseNavigatorXRName[];
    static constexpr uint64_t kDidUseNavigatorXRNameHash = UINT64_C(10361228866366512051);
    XR_WebXR& SetDidUseNavigatorXR(int64_t value);

    static const char kReturnedDeviceName[];
    static constexpr uint64_t kReturnedDeviceNameHash = UINT64_C(1409100318625382915);
    XR_WebXR& SetReturnedDevice(int64_t value);

    static const char kReturnedPresentationCapableDeviceName[];
    static constexpr uint64_t kReturnedPresentationCapableDeviceNameHash = UINT64_C(6868640628705115096);
    XR_WebXR& SetReturnedPresentationCapableDevice(int64_t value);
};

class XR_WebXR_Session final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit XR_WebXR_Session(ukm::SourceId source_id);
    explicit XR_WebXR_Session(ukm::SourceIdObj source_id);
    XR_WebXR_Session(XR_WebXR_Session&&);
    XR_WebXR_Session& operator=(XR_WebXR_Session&&);
    ~XR_WebXR_Session() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(4113953897099533496);

    static const char kDurationName[];
    static constexpr uint64_t kDurationNameHash = UINT64_C(16153614581047612563);
    XR_WebXR_Session& SetDuration(int64_t value);

    static const char kFeatureRequest_BoundedFloorName[];
    static constexpr uint64_t kFeatureRequest_BoundedFloorNameHash = UINT64_C(16901359366456654591);
    XR_WebXR_Session& SetFeatureRequest_BoundedFloor(int64_t value);

    static const char kFeatureRequest_LocalName[];
    static constexpr uint64_t kFeatureRequest_LocalNameHash = UINT64_C(13815453126277382446);
    XR_WebXR_Session& SetFeatureRequest_Local(int64_t value);

    static const char kFeatureRequest_LocalFloorName[];
    static constexpr uint64_t kFeatureRequest_LocalFloorNameHash = UINT64_C(10252183817747774542);
    XR_WebXR_Session& SetFeatureRequest_LocalFloor(int64_t value);

    static const char kFeatureRequest_UnboundedName[];
    static constexpr uint64_t kFeatureRequest_UnboundedNameHash = UINT64_C(136983454872075535);
    XR_WebXR_Session& SetFeatureRequest_Unbounded(int64_t value);

    static const char kFeatureRequest_ViewerName[];
    static constexpr uint64_t kFeatureRequest_ViewerNameHash = UINT64_C(15521080164987816802);
    XR_WebXR_Session& SetFeatureRequest_Viewer(int64_t value);

    static const char kFeatureUse_BoundedFloorName[];
    static constexpr uint64_t kFeatureUse_BoundedFloorNameHash = UINT64_C(17918695119767135356);
    XR_WebXR_Session& SetFeatureUse_BoundedFloor(int64_t value);

    static const char kFeatureUse_LocalName[];
    static constexpr uint64_t kFeatureUse_LocalNameHash = UINT64_C(863830676396637536);
    XR_WebXR_Session& SetFeatureUse_Local(int64_t value);

    static const char kFeatureUse_LocalFloorName[];
    static constexpr uint64_t kFeatureUse_LocalFloorNameHash = UINT64_C(1848942618885117456);
    XR_WebXR_Session& SetFeatureUse_LocalFloor(int64_t value);

    static const char kFeatureUse_UnboundedName[];
    static constexpr uint64_t kFeatureUse_UnboundedNameHash = UINT64_C(892938442719335112);
    XR_WebXR_Session& SetFeatureUse_Unbounded(int64_t value);

    static const char kFeatureUse_ViewerName[];
    static constexpr uint64_t kFeatureUse_ViewerNameHash = UINT64_C(10409675248815280630);
    XR_WebXR_Session& SetFeatureUse_Viewer(int64_t value);

    static const char kModeName[];
    static constexpr uint64_t kModeNameHash = UINT64_C(7281166215790160128);
    XR_WebXR_Session& SetMode(int64_t value);
};

class XR_WebXR_SessionRequest final : public ::ukm::internal::UkmEntryBuilderBase {
public:
    explicit XR_WebXR_SessionRequest(ukm::SourceId source_id);
    explicit XR_WebXR_SessionRequest(ukm::SourceIdObj source_id);
    XR_WebXR_SessionRequest(XR_WebXR_SessionRequest&&);
    XR_WebXR_SessionRequest& operator=(XR_WebXR_SessionRequest&&);
    ~XR_WebXR_SessionRequest() override;

    static const char kEntryName[];
    static constexpr uint64_t kEntryNameHash = UINT64_C(15349576264204541813);

    static const char kFeature_BoundedFloorName[];
    static constexpr uint64_t kFeature_BoundedFloorNameHash = UINT64_C(9616676461285313482);
    XR_WebXR_SessionRequest& SetFeature_BoundedFloor(int64_t value);

    static const char kFeature_LocalName[];
    static constexpr uint64_t kFeature_LocalNameHash = UINT64_C(6494346351619867017);
    XR_WebXR_SessionRequest& SetFeature_Local(int64_t value);

    static const char kFeature_LocalFloorName[];
    static constexpr uint64_t kFeature_LocalFloorNameHash = UINT64_C(1462584064413291363);
    XR_WebXR_SessionRequest& SetFeature_LocalFloor(int64_t value);

    static const char kFeature_UnboundedName[];
    static constexpr uint64_t kFeature_UnboundedNameHash = UINT64_C(6682040134498450962);
    XR_WebXR_SessionRequest& SetFeature_Unbounded(int64_t value);

    static const char kFeature_ViewerName[];
    static constexpr uint64_t kFeature_ViewerNameHash = UINT64_C(6038436711203453177);
    XR_WebXR_SessionRequest& SetFeature_Viewer(int64_t value);

    static const char kModeName[];
    static constexpr uint64_t kModeNameHash = UINT64_C(7281166215790160128);
    XR_WebXR_SessionRequest& SetMode(int64_t value);

    static const char kStatusName[];
    static constexpr uint64_t kStatusNameHash = UINT64_C(17029140179819671253);
    XR_WebXR_SessionRequest& SetStatus(int64_t value);
};

} // namespace builders
} // namespace ukm

#endif // SERVICES_METRICS_PUBLIC_CPP_UKM_BUILDERS_H
