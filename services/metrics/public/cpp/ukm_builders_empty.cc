
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#include "services/metrics/public/cpp/ukm_builders.h"
#include "services/metrics/public/cpp/ukm_entry_builder.h"

namespace ukm {
namespace builders {

PerformanceAPI_Memory_Legacy::~PerformanceAPI_Memory_Legacy(void) = default;

PerformanceAPI_Memory_Legacy::PerformanceAPI_Memory_Legacy(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory_Legacy::PerformanceAPI_Memory_Legacy(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ukm::builders::PerformanceAPI_Memory_Legacy& ukm::builders::PerformanceAPI_Memory_Legacy::SetJavaScript(int64_t) { return *this; }

Responsiveness_UserInteraction::Responsiveness_UserInteraction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Responsiveness_UserInteraction::Responsiveness_UserInteraction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}
Responsiveness_UserInteraction::~Responsiveness_UserInteraction(void) = default;
Responsiveness_UserInteraction& Responsiveness_UserInteraction::SetInteractionType(int64_t) { return *this; }
Responsiveness_UserInteraction& Responsiveness_UserInteraction::SetMaxEventDuration(int64_t) { return *this; }
Responsiveness_UserInteraction& Responsiveness_UserInteraction::SetTotalEventDuration(int64_t) { return *this; }

Blink_AutomaticLazyLoadFrame::Blink_AutomaticLazyLoadFrame(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_AutomaticLazyLoadFrame::Blink_AutomaticLazyLoadFrame(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_AutomaticLazyLoadFrame::~Blink_AutomaticLazyLoadFrame() = default;

AbusiveExperienceHeuristic_WindowOpen::AbusiveExperienceHeuristic_WindowOpen(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_WindowOpen::AbusiveExperienceHeuristic_WindowOpen(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_WindowOpen::~AbusiveExperienceHeuristic_WindowOpen() = default;

Blink_FindInPage::Blink_FindInPage(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}
Blink_FindInPage::Blink_FindInPage(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}
Blink_FindInPage::~Blink_FindInPage() = default;

Blink_HTMLParsing::Blink_HTMLParsing(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_HTMLParsing::Blink_HTMLParsing(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_HTMLParsing::~Blink_HTMLParsing() = default;

Blink_PageLoad::Blink_PageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PageLoad::Blink_PageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PageLoad::~Blink_PageLoad() = default;

Blink_PaintTiming::Blink_PaintTiming(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PaintTiming::Blink_PaintTiming(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PaintTiming::~Blink_PaintTiming() = default;
Blink_UpdateTime::Blink_UpdateTime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_UpdateTime::Blink_UpdateTime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_UpdateTime::~Blink_UpdateTime() = default;
ClientRenderingAPI::ClientRenderingAPI(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ClientRenderingAPI::ClientRenderingAPI(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ClientRenderingAPI::~ClientRenderingAPI() = default;

FontMatchAttempts::FontMatchAttempts(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FontMatchAttempts::FontMatchAttempts(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FontMatchAttempts::~FontMatchAttempts() = default;

InputEvent::InputEvent(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputEvent::InputEvent(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputEvent::~InputEvent() = default;
Media_Autoplay_Attempt::Media_Autoplay_Attempt(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Attempt::Media_Autoplay_Attempt(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Attempt::~Media_Autoplay_Attempt() = default;
Media_Autoplay_Muted_UnmuteAction::Media_Autoplay_Muted_UnmuteAction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Muted_UnmuteAction::Media_Autoplay_Muted_UnmuteAction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Muted_UnmuteAction::~Media_Autoplay_Muted_UnmuteAction() = default;
Net_LegacyTLSVersion::Net_LegacyTLSVersion(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Net_LegacyTLSVersion::Net_LegacyTLSVersion(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Net_LegacyTLSVersion::~Net_LegacyTLSVersion() = default;
Network_CacheTransparency::Network_CacheTransparency(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Network_CacheTransparency::Network_CacheTransparency(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Network_CacheTransparency::~Network_CacheTransparency() = default;
PerformanceAPI_LongTask::PerformanceAPI_LongTask(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_LongTask::PerformanceAPI_LongTask(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_LongTask::~PerformanceAPI_LongTask() = default;
PerformanceAPI_Memory::PerformanceAPI_Memory(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory::PerformanceAPI_Memory(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory::~PerformanceAPI_Memory() = default;

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::~PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket() = default;

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::PostMessage_Incoming_FirstPartyToFirstParty_SameBucket(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::PostMessage_Incoming_FirstPartyToFirstParty_SameBucket(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::~PostMessage_Incoming_FirstPartyToFirstParty_SameBucket() = default;
PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::~PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin() = default;

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::~PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin() = default;

PostMessage_Incoming_Frame::PostMessage_Incoming_Frame(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Frame::PostMessage_Incoming_Frame(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Frame::~PostMessage_Incoming_Frame() = default;
PostMessage_Incoming_Opaque::PostMessage_Incoming_Opaque(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Opaque::PostMessage_Incoming_Opaque(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Opaque::~PostMessage_Incoming_Opaque() = default;
PostMessage_Incoming_Page::PostMessage_Incoming_Page(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Page::PostMessage_Incoming_Page(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Page::~PostMessage_Incoming_Page() = default;

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::~PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin() = default;

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::~PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin() = default;

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::~PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin() = default;

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::~PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin() = default;
PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::~PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket() = default;
RendererSchedulerTask::RendererSchedulerTask(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

RendererSchedulerTask::RendererSchedulerTask(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

RendererSchedulerTask::~RendererSchedulerTask() = default;
V8_Wasm_ModuleCompiled::V8_Wasm_ModuleCompiled(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleCompiled::V8_Wasm_ModuleCompiled(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleCompiled::~V8_Wasm_ModuleCompiled() = default;
V8_Wasm_ModuleDecoded::V8_Wasm_ModuleDecoded(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleDecoded::V8_Wasm_ModuleDecoded(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleDecoded::~V8_Wasm_ModuleDecoded() = default;
V8_Wasm_ModuleInstantiated::V8_Wasm_ModuleInstantiated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleInstantiated::V8_Wasm_ModuleInstantiated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleInstantiated::~V8_Wasm_ModuleInstantiated() = default;

AbusiveExperienceHeuristic_WindowOpen& AbusiveExperienceHeuristic_WindowOpen::SetFromAdScript(int64_t) { return *this; }
AbusiveExperienceHeuristic_WindowOpen& AbusiveExperienceHeuristic_WindowOpen::SetFromAdSubframe(int64_t) { return *this; }
Blink_AutomaticLazyLoadFrame& Blink_AutomaticLazyLoadFrame::SetLazyAdsFrameCount(int64_t) { return *this; }
Blink_AutomaticLazyLoadFrame& Blink_AutomaticLazyLoadFrame::SetLazyEmbedsFrameCount(int64_t) { return *this; }
Blink_FindInPage& Blink_FindInPage::SetBeforematchExpandedHiddenMatchable(int64_t) { return *this; }
Blink_FindInPage& Blink_FindInPage::SetDidHaveRenderSubtreeMatch(int64_t) { return *this; }
Blink_FindInPage& Blink_FindInPage::SetDidSearch(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetChunkCount(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeMax(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeMin(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeTotal(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedAverage(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedMax(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedMin(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedTotal(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeAverage(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeMax(int64_t) { return *this; }
Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeMin(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetAccessibility(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetAnchorElementMetricsIntersectionObserver(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetAnimate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetCompositingCommit(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetCompositingInputs(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetContentDocumentUpdate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetDisplayLockIntersectionObserver(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetForcedStyleAndLayout(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetHandleInputEvents(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetHitTestDocumentUpdate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetImplCompositorCommit(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetIntersectionObservation(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetIntersectionObservationInternalCount(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetIntersectionObservationJavascriptCount(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetJavascriptDocumentUpdate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetJavascriptIntersectionObserver(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetLayout(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetLazyLoadIntersectionObserver(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetMainFrame(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetMediaIntersectionObserver(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetPaint(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetParseStyleSheet(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetPrePaint(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetScrollDocumentUpdate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetServiceDocumentUpdate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetStyle(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetUpdateLayers(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetUpdateViewportIntersection(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetUserDrivenDocumentUpdate(int64_t) { return *this; }
Blink_PageLoad& Blink_PageLoad::SetWaitForCommit(int64_t) { return *this; }
Blink_PaintTiming& Blink_PaintTiming::SetLCPDebugging_HasViewportImage(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetAccessibility(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetAccessibilityBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetAnchorElementMetricsIntersectionObserver(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetAnchorElementMetricsIntersectionObserverBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetAnimate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetAnimateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetCompositingCommit(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetCompositingCommitBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetCompositingInputs(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetCompositingInputsBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetContentDocumentUpdate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetContentDocumentUpdateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetDisplayLockIntersectionObserver(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetDisplayLockIntersectionObserverBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetForcedStyleAndLayout(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetForcedStyleAndLayoutBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetHandleInputEvents(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetHandleInputEventsBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetHitTestDocumentUpdate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetHitTestDocumentUpdateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetImplCompositorCommit(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetImplCompositorCommitBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservation(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationInternalCount(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationInternalCountBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationJavascriptCount(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationJavascriptCountBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetJavascriptDocumentUpdate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetJavascriptDocumentUpdateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetJavascriptIntersectionObserver(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetJavascriptIntersectionObserverBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetLayout(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetLayoutBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetLazyLoadIntersectionObserver(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetLazyLoadIntersectionObserverBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetMainFrameIsBeforeFCP(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetMainFrameReasons(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetMediaIntersectionObserver(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetMediaIntersectionObserverBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetPaint(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetPaintBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetParseStyleSheet(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetParseStyleSheetBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetPrePaint(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetPrePaintBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetScrollDocumentUpdate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetScrollDocumentUpdateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetServiceDocumentUpdate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetServiceDocumentUpdateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetStyle(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetStyleBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetUpdateLayers(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetUpdateLayersBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetUpdateViewportIntersection(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetUpdateViewportIntersectionBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetUserDrivenDocumentUpdate(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetUserDrivenDocumentUpdateBeginMainFrame(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetWaitForCommit(int64_t) { return *this; }
Blink_UpdateTime& Blink_UpdateTime::SetWaitForCommitBeginMainFrame(int64_t) { return *this; }
ClientRenderingAPI& ClientRenderingAPI::SetCanvas_RenderingContext(int64_t) { return *this; }
ClientRenderingAPI& ClientRenderingAPI::SetCanvas_RenderingContextDrawnTo(int64_t) { return *this; }
ClientRenderingAPI& ClientRenderingAPI::SetOffscreenCanvas_RenderingContext(int64_t) { return *this; }
ClientRenderingAPI& ClientRenderingAPI::SetOffscreenCanvas_RenderingContextDrawnTo(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetLoadContext(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetLocalFontFailures(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetLocalFontSuccesses(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetLocalFontTotal(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilyFailures(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilySuccesses(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilyTotal(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetWebFontFamilyFailures(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetWebFontFamilySuccesses(int64_t) { return *this; }
FontMatchAttempts& FontMatchAttempts::SetWebFontFamilyTotal(int64_t) { return *this; }
InputEvent& InputEvent::SetEventType(int64_t) { return *this; }
InputEvent& InputEvent::SetInteractiveTiming_InputDelay(int64_t) { return *this; }
InputEvent& InputEvent::SetInteractiveTiming_ProcessingFinishedToNextPaint(int64_t) { return *this; }
InputEvent& InputEvent::SetInteractiveTiming_ProcessingTime(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetAudioTrack(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetHighMediaEngagement(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetMuted(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetSource(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetUserGestureRequired(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetUserGestureStatus(int64_t) { return *this; }
Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetVideoTrack(int64_t) { return *this; }
Media_Autoplay_Muted_UnmuteAction& Media_Autoplay_Muted_UnmuteAction::SetResult(int64_t) { return *this; }
Media_Autoplay_Muted_UnmuteAction& Media_Autoplay_Muted_UnmuteAction::SetSource(int64_t) { return *this; }
Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsAdResource(int64_t) { return *this; }
Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsMainFrame(int64_t) { return *this; }
Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsSubresource(int64_t) { return *this; }
Network_CacheTransparency& Network_CacheTransparency::SetFoundPervasivePayload(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_Execute(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC_Full_Atomic(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC_Full_Incremental(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC_Young(int64_t) { return *this; }
PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetStartTime(int64_t) { return *this; }
PerformanceAPI_Memory& PerformanceAPI_Memory::SetDom(int64_t) { return *this; }
PerformanceAPI_Memory& PerformanceAPI_Memory::SetJavaScript(int64_t) { return *this; }
PerformanceAPI_Memory& PerformanceAPI_Memory::SetJavaScript_DedicatedWorker(int64_t) { return *this; }
PerformanceAPI_Memory& PerformanceAPI_Memory::SetShared(int64_t) { return *this; }
PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket& PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::SetSourceFrameSourceId(int64_t) { return *this; }
PostMessage_Incoming_FirstPartyToFirstParty_SameBucket& PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::SetSourceFrameSourceId(int64_t) { return *this; }
PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin& PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::SetSourceFrameSourceId(
    int64_t)
{
    return *this;
}
PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin& PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::SetSourceFrameSourceId(int64_t)
{
    return *this;
}
PostMessage_Incoming_Frame& PostMessage_Incoming_Frame::SetSourceFrameSourceId(int64_t) { return *this; }
PostMessage_Incoming_Opaque& PostMessage_Incoming_Opaque::SetSourceFrameSourceId(int64_t) { return *this; }
PostMessage_Incoming_Page& PostMessage_Incoming_Page::SetSourcePageSourceId(int64_t) { return *this; }
PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin& PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::SetSourceFrameSourceId(
    int64_t)
{
    return *this;
}
PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin& PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::SetSourceFrameSourceId(int64_t)
{
    return *this;
}
PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin& PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::SetSourceFrameSourceId(
    int64_t)
{
    return *this;
}
PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin& PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::SetSourceFrameSourceId(int64_t)
{
    return *this;
}
PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket& PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::SetSourceFrameSourceId(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetFrameStatus(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetIsOOPIF(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetPageSchedulers(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetQueueType(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetRendererAudible(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetRendererBackgrounded(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetRendererHidden(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetSecondsSinceBackgrounded(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetTaskCPUDuration(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetTaskDuration(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetTaskType(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetThreadType(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetUseCase(int64_t) { return *this; }
RendererSchedulerTask& RendererSchedulerTask::SetVersion(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetAsync(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetCached(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetCodeSize(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetDeserialized(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetLazy(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetLiftoffBailoutCount(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetStreamed(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetSuccess(int64_t) { return *this; }
V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetWallClockDuration(int64_t) { return *this; }
V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetFunctionCount(int64_t) { return *this; }
V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetModuleSize(int64_t) { return *this; }
V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetStreamed(int64_t) { return *this; }
V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetSuccess(int64_t) { return *this; }
V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetWallClockDuration(int64_t) { return *this; }
V8_Wasm_ModuleInstantiated& V8_Wasm_ModuleInstantiated::SetImportedFunctionCount(int64_t) { return *this; }
V8_Wasm_ModuleInstantiated& V8_Wasm_ModuleInstantiated::SetSuccess(int64_t) { return *this; }
V8_Wasm_ModuleInstantiated& V8_Wasm_ModuleInstantiated::SetWallClockDuration(int64_t) { return *this; }

}

UkmRecorder* UkmRecorder::Get(void)
{
    //*(int*)1 = 1;
    return nullptr;
}

int64_t UkmRecorder::GetNewSourceID(void)
{
    static int64_t s_count = 1;
    return s_count++;
}

}