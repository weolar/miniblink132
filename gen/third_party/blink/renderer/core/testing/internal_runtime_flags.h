// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/internal_runtime_flags.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_RUNTIME_FLAGS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_RUNTIME_FLAGS_H_

#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/platform/wtf/ref_counted.h"

namespace blink {

class InternalRuntimeFlags : public ScriptWrappable {
    DEFINE_WRAPPERTYPEINFO();

public:
    static InternalRuntimeFlags* create()
    {
        return MakeGarbageCollected<InternalRuntimeFlags>();
    }

    InternalRuntimeFlags()
    {
    }

    // These are reset between web tests from Internals::resetToConsistentState
    // using RuntimeEnabledFeatures::Backup.
    void setAccelerated2dCanvasEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetAccelerated2dCanvasEnabled(isEnabled);
    }
    void setAutomationControlledEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetAutomationControlledEnabled(isEnabled);
    }
    void setImplicitRootScrollerEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetImplicitRootScrollerEnabled(isEnabled);
    }
    void setLangAttributeAwareFormControlUIEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetLangAttributeAwareFormControlUIEnabled(isEnabled);
    }
    void setMediaControlsOverlayPlayButtonEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetMediaControlsOverlayPlayButtonEnabled(isEnabled);
    }
    void setPaintUnderInvalidationCheckingEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetPaintUnderInvalidationCheckingEnabled(isEnabled);
    }
    void setPercentBasedScrollingEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetPercentBasedScrollingEnabled(isEnabled);
    }
    void setPreferNonCompositedScrollingEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetPreferNonCompositedScrollingEnabled(isEnabled);
    }
    void setRemotePlaybackBackendEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetRemotePlaybackBackendEnabled(isEnabled);
    }
    void setVideoAutoFullscreenEnabled(bool isEnabled)
    {
        RuntimeEnabledFeatures::SetVideoAutoFullscreenEnabled(isEnabled);
    }

    bool accelerated2dCanvasEnabled()
    {
        return RuntimeEnabledFeatures::Accelerated2dCanvasEnabled();
    }
    bool acceleratedSmallCanvasesEnabled()
    {
        return RuntimeEnabledFeatures::AcceleratedSmallCanvasesEnabled();
    }
    bool accessibilityAriaVirtualContentEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilityAriaVirtualContentEnabled();
    }
    bool accessibilityExposeDisplayNoneEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilityExposeDisplayNoneEnabled();
    }
    bool accessibilityMinRoleTabbableEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilityMinRoleTabbableEnabled();
    }
    bool accessibilityOSLevelBoldTextEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilityOSLevelBoldTextEnabled();
    }
    bool accessibilityProhibitedNamesEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilityProhibitedNamesEnabled();
    }
    bool accessibilitySerializationSizeMetricsEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilitySerializationSizeMetricsEnabled();
    }
    bool accessibilityUseAXPositionForDocumentMarkersEnabled()
    {
        return RuntimeEnabledFeatures::AccessibilityUseAXPositionForDocumentMarkersEnabled();
    }
    bool addressSpaceEnabled()
    {
        return RuntimeEnabledFeatures::AddressSpaceEnabled();
    }
    bool adInterestGroupAPIEnabled()
    {
        return RuntimeEnabledFeatures::AdInterestGroupAPIEnabledByRuntimeFlag();
    }
    bool adjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled()
    {
        return RuntimeEnabledFeatures::AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled();
    }
    bool adTaggingEnabled()
    {
        return RuntimeEnabledFeatures::AdTaggingEnabled();
    }
    bool aiPromptAPIEnabled()
    {
        return RuntimeEnabledFeatures::AIPromptAPIEnabled();
    }
    bool aiPromptAPIForExtensionEnabled()
    {
        return RuntimeEnabledFeatures::AIPromptAPIForExtensionEnabledByRuntimeFlag();
    }
    bool aiPromptAPIForWebPlatformEnabled()
    {
        return RuntimeEnabledFeatures::AIPromptAPIForWebPlatformEnabled();
    }
    bool aiRewriterAPIEnabled()
    {
        return RuntimeEnabledFeatures::AIRewriterAPIEnabled();
    }
    bool aiSummarizationAPIEnabled()
    {
        return RuntimeEnabledFeatures::AISummarizationAPIEnabledByRuntimeFlag();
    }
    bool aiWriterAPIEnabled()
    {
        return RuntimeEnabledFeatures::AIWriterAPIEnabled();
    }
    bool allowContentInitiatedDataUrlNavigationsEnabled()
    {
        return RuntimeEnabledFeatures::AllowContentInitiatedDataUrlNavigationsEnabled();
    }
    bool allowJavaScriptToResetAutofillStateEnabled()
    {
        return RuntimeEnabledFeatures::AllowJavaScriptToResetAutofillStateEnabled();
    }
    bool allowPreloadingWithCSPMetaTagEnabled()
    {
        return RuntimeEnabledFeatures::AllowPreloadingWithCSPMetaTagEnabled();
    }
    bool allowURNsInIframesEnabled()
    {
        return RuntimeEnabledFeatures::AllowURNsInIframesEnabled();
    }
    bool androidDownloadableFontsMatchingEnabled()
    {
        return RuntimeEnabledFeatures::AndroidDownloadableFontsMatchingEnabled();
    }
    bool animationProgressAPIEnabled()
    {
        return RuntimeEnabledFeatures::AnimationProgressAPIEnabled();
    }
    bool animationWorkletEnabled()
    {
        return RuntimeEnabledFeatures::AnimationWorkletEnabled();
    }
    bool anonymousIframeEnabled()
    {
        return RuntimeEnabledFeatures::AnonymousIframeEnabled();
    }
    bool aomAriaRelationshipPropertiesEnabled()
    {
        return RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesEnabled();
    }
    bool aomAriaRelationshipPropertiesAriaOwnsEnabled()
    {
        return RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesAriaOwnsEnabled();
    }
    bool appTitleEnabled()
    {
        return RuntimeEnabledFeatures::AppTitleEnabledByRuntimeFlag();
    }
    bool ariaActionsEnabled()
    {
        return RuntimeEnabledFeatures::AriaActionsEnabled();
    }
    bool ariaNotifyEnabled()
    {
        return RuntimeEnabledFeatures::AriaNotifyEnabled();
    }
    bool ariaRowColIndexTextEnabled()
    {
        return RuntimeEnabledFeatures::AriaRowColIndexTextEnabled();
    }
    bool atomicMoveAPIEnabled()
    {
        return RuntimeEnabledFeatures::AtomicMoveAPIEnabled();
    }
    bool attributionReportingEnabled()
    {
        return RuntimeEnabledFeatures::AttributionReportingEnabled();
    }
    bool attributionReportingCrossAppWebEnabled()
    {
        return RuntimeEnabledFeatures::AttributionReportingCrossAppWebEnabled();
    }
    bool attributionReportingInterfaceEnabled()
    {
        return RuntimeEnabledFeatures::AttributionReportingInterfaceEnabledByRuntimeFlag();
    }
    bool audioContextInterruptedStateEnabled()
    {
        return RuntimeEnabledFeatures::AudioContextInterruptedStateEnabled();
    }
    bool audioContextOnErrorEnabled()
    {
        return RuntimeEnabledFeatures::AudioContextOnErrorEnabled();
    }
    bool audioContextPlayoutStatsEnabled()
    {
        return RuntimeEnabledFeatures::AudioContextPlayoutStatsEnabledByRuntimeFlag();
    }
    bool audioContextSetSinkIdEnabled()
    {
        return RuntimeEnabledFeatures::AudioContextSetSinkIdEnabled();
    }
    bool audioOutputDevicesEnabled()
    {
        return RuntimeEnabledFeatures::AudioOutputDevicesEnabled();
    }
    bool audioVideoTracksEnabled()
    {
        return RuntimeEnabledFeatures::AudioVideoTracksEnabled();
    }
    bool auraScrollbarUsesNinePatchTrackEnabled()
    {
        return RuntimeEnabledFeatures::AuraScrollbarUsesNinePatchTrackEnabled();
    }
    bool auraScrollbarUsesSolidColorThumbEnabled()
    {
        return RuntimeEnabledFeatures::AuraScrollbarUsesSolidColorThumbEnabled();
    }
    bool autoDarkModeEnabled()
    {
        return RuntimeEnabledFeatures::AutoDarkModeEnabledByRuntimeFlag();
    }
    bool automationControlledEnabled()
    {
        return RuntimeEnabledFeatures::AutomationControlledEnabled();
    }
    bool autoPictureInPictureVideoHeuristicsEnabled()
    {
        return RuntimeEnabledFeatures::AutoPictureInPictureVideoHeuristicsEnabled();
    }
    bool backfaceVisibilityInteropEnabled()
    {
        return RuntimeEnabledFeatures::BackfaceVisibilityInteropEnabled();
    }
    bool backForwardCacheEnabled()
    {
        return RuntimeEnabledFeatures::BackForwardCacheEnabled();
    }
    bool backForwardCacheExperimentHTTPHeaderEnabled()
    {
        return RuntimeEnabledFeatures::BackForwardCacheExperimentHTTPHeaderEnabledByRuntimeFlag();
    }
    bool backForwardCacheNotRestoredReasonsEnabled()
    {
        return RuntimeEnabledFeatures::BackForwardCacheNotRestoredReasonsEnabledByRuntimeFlag();
    }
    bool backForwardTransitionsEnabled()
    {
        return RuntimeEnabledFeatures::BackForwardTransitionsEnabled();
    }
    bool backgroundFetchEnabled()
    {
        return RuntimeEnabledFeatures::BackgroundFetchEnabled();
    }
    bool barcodeDetectorEnabled()
    {
        return RuntimeEnabledFeatures::BarcodeDetectorEnabled();
    }
    bool bidiCaretAffinityEnabled()
    {
        return RuntimeEnabledFeatures::BidiCaretAffinityEnabled();
    }
    bool blinkExtensionChromeOSEnabled()
    {
        return RuntimeEnabledFeatures::BlinkExtensionChromeOSEnabled();
    }
    bool blinkExtensionChromeOSKioskEnabled()
    {
        return RuntimeEnabledFeatures::BlinkExtensionChromeOSKioskEnabled();
    }
    bool blinkExtensionDiagnosticsEnabled()
    {
        return RuntimeEnabledFeatures::BlinkExtensionDiagnosticsEnabled();
    }
    bool blinkExtensionWebViewEnabled()
    {
        return RuntimeEnabledFeatures::BlinkExtensionWebViewEnabled();
    }
    bool blinkExtensionWebViewMediaIntegrityEnabled()
    {
        return RuntimeEnabledFeatures::BlinkExtensionWebViewMediaIntegrityEnabled();
    }
    bool blinkLifecycleScriptForbiddenEnabled()
    {
        return RuntimeEnabledFeatures::BlinkLifecycleScriptForbiddenEnabled();
    }
    bool blinkRuntimeCallStatsEnabled()
    {
        return RuntimeEnabledFeatures::BlinkRuntimeCallStatsEnabled();
    }
    bool blockingFocusWithoutUserActivationEnabled()
    {
        return RuntimeEnabledFeatures::BlockingFocusWithoutUserActivationEnabled();
    }
    bool boundaryEventDispatchTracksNodeRemovalEnabled()
    {
        return RuntimeEnabledFeatures::BoundaryEventDispatchTracksNodeRemovalEnabled();
    }
    bool boxDecorationBreakEnabled()
    {
        return RuntimeEnabledFeatures::BoxDecorationBreakEnabled();
    }
    bool breakIteratorHyphenMinusEnabled()
    {
        return RuntimeEnabledFeatures::BreakIteratorHyphenMinusEnabled();
    }
    bool browserVerifiedUserActivationKeyboardEnabled()
    {
        return RuntimeEnabledFeatures::BrowserVerifiedUserActivationKeyboardEnabled();
    }
    bool browserVerifiedUserActivationMouseEnabled()
    {
        return RuntimeEnabledFeatures::BrowserVerifiedUserActivationMouseEnabled();
    }
    bool bufferedBytesConsumerLimitSizeEnabled()
    {
        return RuntimeEnabledFeatures::BufferedBytesConsumerLimitSizeEnabled();
    }
    bool builtInAIAPIEnabled()
    {
        return RuntimeEnabledFeatures::BuiltInAIAPIEnabledByRuntimeFlag();
    }
    bool bypassPepcSecurityForTestingEnabled()
    {
        return RuntimeEnabledFeatures::BypassPepcSecurityForTestingEnabled();
    }
    bool cacheStorageCodeCacheHintEnabled()
    {
        return RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabledByRuntimeFlag();
    }
    bool calendarPickerMonthPopupButtonDisabledColorEnabled()
    {
        return RuntimeEnabledFeatures::CalendarPickerMonthPopupButtonDisabledColorEnabled();
    }
    bool callExitNodeWithoutLayoutObjectEnabled()
    {
        return RuntimeEnabledFeatures::CallExitNodeWithoutLayoutObjectEnabled();
    }
    bool canvas2dCanvasFilterEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dCanvasFilterEnabled();
    }
    bool canvas2dGPUTransferEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dGPUTransferEnabled();
    }
    bool canvas2dImageChromiumEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dImageChromiumEnabled();
    }
    bool canvas2dLayersEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dLayersEnabled();
    }
    bool canvas2dLayersWithOptionsEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dLayersWithOptionsEnabled();
    }
    bool canvas2dMeshEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dMeshEnabledByRuntimeFlag();
    }
    bool canvas2dTextMetricsShapingEnabled()
    {
        return RuntimeEnabledFeatures::Canvas2dTextMetricsShapingEnabled();
    }
    bool canvasFloatingPointEnabled()
    {
        return RuntimeEnabledFeatures::CanvasFloatingPointEnabled();
    }
    bool canvasHDREnabled()
    {
        return RuntimeEnabledFeatures::CanvasHDREnabled();
    }
    bool canvasImageSmoothingEnabled()
    {
        return RuntimeEnabledFeatures::CanvasImageSmoothingEnabled();
    }
    bool canvasPlaceElementEnabled()
    {
        return RuntimeEnabledFeatures::CanvasPlaceElementEnabled();
    }
    bool canvasUsesArcPaintOpEnabled()
    {
        return RuntimeEnabledFeatures::CanvasUsesArcPaintOpEnabled();
    }
    bool capabilityDelegationDisplayCaptureRequestEnabled()
    {
        return RuntimeEnabledFeatures::CapabilityDelegationDisplayCaptureRequestEnabled();
    }
    bool captureControllerEnabled()
    {
        return RuntimeEnabledFeatures::CaptureControllerEnabled();
    }
    bool capturedMouseEventsEnabled()
    {
        return RuntimeEnabledFeatures::CapturedMouseEventsEnabled();
    }
    bool capturedSurfaceControlEnabled()
    {
        return RuntimeEnabledFeatures::CapturedSurfaceControlEnabledByRuntimeFlag();
    }
    bool captureHandleEnabled()
    {
        return RuntimeEnabledFeatures::CaptureHandleEnabled();
    }
    bool caretPositionFromPointEnabled()
    {
        return RuntimeEnabledFeatures::CaretPositionFromPointEnabled();
    }
    bool cctNewRFMPushBehaviorEnabled()
    {
        return RuntimeEnabledFeatures::CCTNewRFMPushBehaviorEnabled();
    }
    bool checkIfHighestRootContainsPositionAnchorNodeEnabled()
    {
        return RuntimeEnabledFeatures::CheckIfHighestRootContainsPositionAnchorNodeEnabled();
    }
    bool checkVisibilityExtraPropertiesEnabled()
    {
        return RuntimeEnabledFeatures::CheckVisibilityExtraPropertiesEnabled();
    }
    bool clickToCapturedPointerEnabled()
    {
        return RuntimeEnabledFeatures::ClickToCapturedPointerEnabled();
    }
    bool clipboardItemWithDOMStringSupportEnabled()
    {
        return RuntimeEnabledFeatures::ClipboardItemWithDOMStringSupportEnabled();
    }
    bool clipPathRejectEmptyPathsEnabled()
    {
        return RuntimeEnabledFeatures::ClipPathRejectEmptyPathsEnabled();
    }
    bool coalesceSelectionchangeEventEnabled()
    {
        return RuntimeEnabledFeatures::CoalesceSelectionchangeEventEnabled();
    }
    bool coepReflectionEnabled()
    {
        return RuntimeEnabledFeatures::CoepReflectionEnabled();
    }
    bool compositeBGColorAnimationEnabled()
    {
        return RuntimeEnabledFeatures::CompositeBGColorAnimationEnabled();
    }
    bool compositeBoxShadowAnimationEnabled()
    {
        return RuntimeEnabledFeatures::CompositeBoxShadowAnimationEnabled();
    }
    bool compositeClipPathAnimationEnabled()
    {
        return RuntimeEnabledFeatures::CompositeClipPathAnimationEnabled();
    }
    bool compositedAnimationsCancelledAsynchronouslyEnabled()
    {
        return RuntimeEnabledFeatures::CompositedAnimationsCancelledAsynchronouslyEnabled();
    }
    bool compositedSelectionUpdateEnabled()
    {
        return RuntimeEnabledFeatures::CompositedSelectionUpdateEnabled();
    }
    bool compositionForegroundMarkersEnabled()
    {
        return RuntimeEnabledFeatures::CompositionForegroundMarkersEnabled();
    }
    bool compressionDictionaryTransportEnabled()
    {
        return RuntimeEnabledFeatures::CompressionDictionaryTransportEnabled();
    }
    bool compressionDictionaryTransportBackendEnabled()
    {
        return RuntimeEnabledFeatures::CompressionDictionaryTransportBackendEnabled();
    }
    bool computedAccessibilityInfoEnabled()
    {
        return RuntimeEnabledFeatures::ComputedAccessibilityInfoEnabled();
    }
    bool computePressureEnabled()
    {
        return RuntimeEnabledFeatures::ComputePressureEnabled();
    }
    bool concurrentViewTransitionsSPAEnabled()
    {
        return RuntimeEnabledFeatures::ConcurrentViewTransitionsSPAEnabled();
    }
    bool contactsManagerEnabled()
    {
        return RuntimeEnabledFeatures::ContactsManagerEnabled();
    }
    bool contactsManagerExtraPropertiesEnabled()
    {
        return RuntimeEnabledFeatures::ContactsManagerExtraPropertiesEnabled();
    }
    bool containerTypeNoLayoutContainmentEnabled()
    {
        return RuntimeEnabledFeatures::ContainerTypeNoLayoutContainmentEnabled();
    }
    bool contentIndexEnabled()
    {
        return RuntimeEnabledFeatures::ContentIndexEnabled();
    }
    bool contextMenuEnabled()
    {
        return RuntimeEnabledFeatures::ContextMenuEnabled();
    }
    bool continueEventTimingRecordingWhenBufferIsFullEnabled()
    {
        return RuntimeEnabledFeatures::ContinueEventTimingRecordingWhenBufferIsFullEnabled();
    }
    bool controlledFrameEnabled()
    {
        return RuntimeEnabledFeatures::ControlledFrameEnabled();
    }
    bool cookieDeprecationFacilitatedTestingEnabled()
    {
        return RuntimeEnabledFeatures::CookieDeprecationFacilitatedTestingEnabled();
    }
    bool cooperativeSchedulingEnabled()
    {
        return RuntimeEnabledFeatures::CooperativeSchedulingEnabled();
    }
    bool coopRestrictPropertiesEnabled()
    {
        return RuntimeEnabledFeatures::CoopRestrictPropertiesEnabledByRuntimeFlag();
    }
    bool corsRFC1918Enabled()
    {
        return RuntimeEnabledFeatures::CorsRFC1918Enabled();
    }
    bool createInputShadowTreeDuringLayoutEnabled()
    {
        return RuntimeEnabledFeatures::CreateInputShadowTreeDuringLayoutEnabled();
    }
    bool credentialManagerReportEnabled()
    {
        return RuntimeEnabledFeatures::CredentialManagerReportEnabled();
    }
    bool crossFramePerformanceTimelineEnabled()
    {
        return RuntimeEnabledFeatures::CrossFramePerformanceTimelineEnabled();
    }
    bool cssAccentColorKeywordEnabled()
    {
        return RuntimeEnabledFeatures::CSSAccentColorKeywordEnabled();
    }
    bool cssAdvancedAttrFunctionEnabled()
    {
        return RuntimeEnabledFeatures::CSSAdvancedAttrFunctionEnabled();
    }
    bool cssAnchorScopeEnabled()
    {
        return RuntimeEnabledFeatures::CSSAnchorScopeEnabled();
    }
    bool cssAnchorSizeInsetsMarginsEnabled()
    {
        return RuntimeEnabledFeatures::CSSAnchorSizeInsetsMarginsEnabled();
    }
    bool cssAtPropertyStringSyntaxEnabled()
    {
        return RuntimeEnabledFeatures::CSSAtPropertyStringSyntaxEnabled();
    }
    bool cssAtRuleCounterStyleImageSymbolsEnabled()
    {
        return RuntimeEnabledFeatures::CSSAtRuleCounterStyleImageSymbolsEnabled();
    }
    bool cssAtRuleCounterStyleSpeakAsDescriptorEnabled()
    {
        return RuntimeEnabledFeatures::CSSAtRuleCounterStyleSpeakAsDescriptorEnabled();
    }
    bool cssBackgroundClipUnprefixEnabled()
    {
        return RuntimeEnabledFeatures::CSSBackgroundClipUnprefixEnabled();
    }
    bool cssCalcSimplificationAndSerializationEnabled()
    {
        return RuntimeEnabledFeatures::CSSCalcSimplificationAndSerializationEnabled();
    }
    bool cssCalcSizeFunctionEnabled()
    {
        return RuntimeEnabledFeatures::CSSCalcSizeFunctionEnabled();
    }
    bool cssCaretAnimationEnabled()
    {
        return RuntimeEnabledFeatures::CSSCaretAnimationEnabled();
    }
    bool cssCascadeCorrectScopeEnabled()
    {
        return RuntimeEnabledFeatures::CSSCascadeCorrectScopeEnabled();
    }
    bool cssCaseSensitiveSelectorEnabled()
    {
        return RuntimeEnabledFeatures::CSSCaseSensitiveSelectorEnabled();
    }
    bool cssColorContrastEnabled()
    {
        return RuntimeEnabledFeatures::CSSColorContrastEnabled();
    }
    bool cssColorTypedOMEnabled()
    {
        return RuntimeEnabledFeatures::CSSColorTypedOMEnabled();
    }
    bool cssComputedStyleFullPseudoElementParserEnabled()
    {
        return RuntimeEnabledFeatures::CSSComputedStyleFullPseudoElementParserEnabled();
    }
    bool cssContentVisibilityImpliesContainIntrinsicSizeAutoEnabled()
    {
        return RuntimeEnabledFeatures::CSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled();
    }
    bool cssCrossFadeEnabled()
    {
        return RuntimeEnabledFeatures::CSSCrossFadeEnabled();
    }
    bool cssCustomStateDeprecatedSyntaxEnabled()
    {
        return RuntimeEnabledFeatures::CSSCustomStateDeprecatedSyntaxEnabled();
    }
    bool cssCustomStateNewSyntaxEnabled()
    {
        return RuntimeEnabledFeatures::CSSCustomStateNewSyntaxEnabled();
    }
    bool cssDynamicRangeLimitEnabled()
    {
        return RuntimeEnabledFeatures::CSSDynamicRangeLimitEnabled();
    }
    bool cssEnumeratedCustomPropertiesEnabled()
    {
        return RuntimeEnabledFeatures::CSSEnumeratedCustomPropertiesEnabled();
    }
    bool cssExponentialFunctionsEnabled()
    {
        return RuntimeEnabledFeatures::CSSExponentialFunctionsEnabled();
    }
    bool cssFlatTreeContainerEnabled()
    {
        return RuntimeEnabledFeatures::CSSFlatTreeContainerEnabled();
    }
    bool cssFontSizeAdjustEnabled()
    {
        return RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled();
    }
    bool cssFunctionsEnabled()
    {
        return RuntimeEnabledFeatures::CSSFunctionsEnabled();
    }
    bool cssGapDecorationEnabled()
    {
        return RuntimeEnabledFeatures::CSSGapDecorationEnabled();
    }
    bool cssHexAlphaColorEnabled()
    {
        return RuntimeEnabledFeatures::CSSHexAlphaColorEnabled();
    }
    bool cssInertEnabled()
    {
        return RuntimeEnabledFeatures::CSSInertEnabled();
    }
    bool cssInsetAreaPropertyEnabled()
    {
        return RuntimeEnabledFeatures::CSSInsetAreaPropertyEnabled();
    }
    bool cssKeyframesRuleLengthEnabled()
    {
        return RuntimeEnabledFeatures::CSSKeyframesRuleLengthEnabled();
    }
    bool cssLayoutAPIEnabled()
    {
        return RuntimeEnabledFeatures::CSSLayoutAPIEnabled();
    }
    bool cssLazyParsingFastPathEnabled()
    {
        return RuntimeEnabledFeatures::CSSLazyParsingFastPathEnabled();
    }
    bool cssLineClampEnabled()
    {
        return RuntimeEnabledFeatures::CSSLineClampEnabled();
    }
    bool cssLineClampWebkitBoxBlockificationEnabled()
    {
        return RuntimeEnabledFeatures::CSSLineClampWebkitBoxBlockificationEnabled();
    }
    bool cssLogicalOverflowEnabled()
    {
        return RuntimeEnabledFeatures::CSSLogicalOverflowEnabled();
    }
    bool cssMarkerNestedPseudoElementEnabled()
    {
        return RuntimeEnabledFeatures::CSSMarkerNestedPseudoElementEnabled();
    }
    bool cssMasonryLayoutEnabled()
    {
        return RuntimeEnabledFeatures::CSSMasonryLayoutEnabled();
    }
    bool cssMixinsEnabled()
    {
        return RuntimeEnabledFeatures::CSSMixinsEnabled();
    }
    bool cssNestedDeclarationsEnabled()
    {
        return RuntimeEnabledFeatures::CSSNestedDeclarationsEnabled();
    }
    bool cssNestedPseudoElementsEnabled()
    {
        return RuntimeEnabledFeatures::CSSNestedPseudoElementsEnabled();
    }
    bool cssOverflowContainerQueriesEnabled()
    {
        return RuntimeEnabledFeatures::CSSOverflowContainerQueriesEnabled();
    }
    bool cssPaintAPIArgumentsEnabled()
    {
        return RuntimeEnabledFeatures::CSSPaintAPIArgumentsEnabled();
    }
    bool cssParserIgnoreCharsetForURLsEnabled()
    {
        return RuntimeEnabledFeatures::CSSParserIgnoreCharsetForURLsEnabled();
    }
    bool cssPartAllowsMoreSelectorsAfterEnabled()
    {
        return RuntimeEnabledFeatures::CSSPartAllowsMoreSelectorsAfterEnabled();
    }
    bool cssPositionAreaValueEnabled()
    {
        return RuntimeEnabledFeatures::CSSPositionAreaValueEnabled();
    }
    bool cssPositionStickyStaticScrollPositionEnabled()
    {
        return RuntimeEnabledFeatures::CSSPositionStickyStaticScrollPositionEnabled();
    }
    bool cssProgressNotationEnabled()
    {
        return RuntimeEnabledFeatures::CSSProgressNotationEnabled();
    }
    bool cssPseudoColumnEnabled()
    {
        return RuntimeEnabledFeatures::CSSPseudoColumnEnabled();
    }
    bool cssPseudoHasSlottedEnabled()
    {
        return RuntimeEnabledFeatures::CSSPseudoHasSlottedEnabled();
    }
    bool cssPseudoOpenClosedEnabled()
    {
        return RuntimeEnabledFeatures::CSSPseudoOpenClosedEnabled();
    }
    bool cssPseudoPlayingPausedEnabled()
    {
        return RuntimeEnabledFeatures::CSSPseudoPlayingPausedEnabled();
    }
    bool cssPseudoScrollButtonsEnabled()
    {
        return RuntimeEnabledFeatures::CSSPseudoScrollButtonsEnabled();
    }
    bool cssPseudoScrollMarkersEnabled()
    {
        return RuntimeEnabledFeatures::CSSPseudoScrollMarkersEnabled();
    }
    bool cssReadingFlowEnabled()
    {
        return RuntimeEnabledFeatures::CSSReadingFlowEnabled();
    }
    bool cssRelativeColorEnabled()
    {
        return RuntimeEnabledFeatures::CSSRelativeColorEnabled();
    }
    bool cssRelativeColorLateResolveAlwaysEnabled()
    {
        return RuntimeEnabledFeatures::CSSRelativeColorLateResolveAlwaysEnabled();
    }
    bool cssRelativeColorPreserveNoneEnabled()
    {
        return RuntimeEnabledFeatures::CSSRelativeColorPreserveNoneEnabled();
    }
    bool cssRelativeColorSupportsCurrentcolorEnabled()
    {
        return RuntimeEnabledFeatures::CSSRelativeColorSupportsCurrentcolorEnabled();
    }
    bool cssResizeAutoEnabled()
    {
        return RuntimeEnabledFeatures::CSSResizeAutoEnabled();
    }
    bool cssScrollSnapChangeEventEnabled()
    {
        return RuntimeEnabledFeatures::CSSScrollSnapChangeEventEnabled();
    }
    bool cssScrollSnapChangingEventEnabled()
    {
        return RuntimeEnabledFeatures::CSSScrollSnapChangingEventEnabled();
    }
    bool cssScrollSnapEventsEnabled()
    {
        return RuntimeEnabledFeatures::CSSScrollSnapEventsEnabled();
    }
    bool cssScrollStartEnabled()
    {
        return RuntimeEnabledFeatures::CSSScrollStartEnabled();
    }
    bool cssScrollStartTargetEnabled()
    {
        return RuntimeEnabledFeatures::CSSScrollStartTargetEnabled();
    }
    bool cssScrollStateContainerQueriesEnabled()
    {
        return RuntimeEnabledFeatures::CSSScrollStateContainerQueriesEnabled();
    }
    bool cssSelectorFragmentAnchorEnabled()
    {
        return RuntimeEnabledFeatures::CSSSelectorFragmentAnchorEnabled();
    }
    bool cssSignRelatedFunctionsEnabled()
    {
        return RuntimeEnabledFeatures::CSSSignRelatedFunctionsEnabled();
    }
    bool cssSnapContainerQueriesEnabled()
    {
        return RuntimeEnabledFeatures::CSSSnapContainerQueriesEnabled();
    }
    bool cssSteppedValueFunctionsEnabled()
    {
        return RuntimeEnabledFeatures::CSSSteppedValueFunctionsEnabled();
    }
    bool cssStickyContainerQueriesEnabled()
    {
        return RuntimeEnabledFeatures::CSSStickyContainerQueriesEnabled();
    }
    bool cssSupportsAtRuleFunctionEnabled()
    {
        return RuntimeEnabledFeatures::CSSSupportsAtRuleFunctionEnabled();
    }
    bool cssSupportsForImportRulesEnabled()
    {
        return RuntimeEnabledFeatures::CSSSupportsForImportRulesEnabled();
    }
    bool cssSystemAccentColorEnabled()
    {
        return RuntimeEnabledFeatures::CSSSystemAccentColorEnabled();
    }
    bool cssTextAutoSpaceEnabled()
    {
        return RuntimeEnabledFeatures::CSSTextAutoSpaceEnabled();
    }
    bool cssTextBoxTrimEnabled()
    {
        return RuntimeEnabledFeatures::CSSTextBoxTrimEnabled();
    }
    bool cssTextSpacingEnabled()
    {
        return RuntimeEnabledFeatures::CSSTextSpacingEnabled();
    }
    bool cssTreeScopedTimelinesEnabled()
    {
        return RuntimeEnabledFeatures::CSSTreeScopedTimelinesEnabled();
    }
    bool cssUserSelectContainEnabled()
    {
        return RuntimeEnabledFeatures::CSSUserSelectContainEnabled();
    }
    bool cssVideoDynamicRangeMediaQueriesEnabled()
    {
        return RuntimeEnabledFeatures::CSSVideoDynamicRangeMediaQueriesEnabled();
    }
    bool cssViewTransitionAutoNameEnabled()
    {
        return RuntimeEnabledFeatures::CSSViewTransitionAutoNameEnabled();
    }
    bool cssViewTransitionClassEnabled()
    {
        return RuntimeEnabledFeatures::CSSViewTransitionClassEnabled();
    }
    bool cursorAnchorInfoMojoPipeEnabled()
    {
        return RuntimeEnabledFeatures::CursorAnchorInfoMojoPipeEnabled();
    }
    bool customizableSelectEnabled()
    {
        return RuntimeEnabledFeatures::CustomizableSelectEnabled();
    }
    bool databaseEnabled()
    {
        return RuntimeEnabledFeatures::DatabaseEnabledByRuntimeFlag();
    }
    bool deprecatedRequestAdapterInfoEnabled()
    {
        return RuntimeEnabledFeatures::DeprecatedRequestAdapterInfoEnabled();
    }
    bool deprecateUnloadOptOutEnabled()
    {
        return RuntimeEnabledFeatures::DeprecateUnloadOptOutEnabledByRuntimeFlag();
    }
    bool desktopCaptureDisableLocalEchoControlEnabled()
    {
        return RuntimeEnabledFeatures::DesktopCaptureDisableLocalEchoControlEnabled();
    }
    bool desktopPWAsAdditionalWindowingControlsEnabled()
    {
        return RuntimeEnabledFeatures::DesktopPWAsAdditionalWindowingControlsEnabled();
    }
    bool desktopPWAsSubAppsEnabled()
    {
        return RuntimeEnabledFeatures::DesktopPWAsSubAppsEnabled();
    }
    bool detailsStylingEnabled()
    {
        return RuntimeEnabledFeatures::DetailsStylingEnabled();
    }
    bool deviceAttributesEnabled()
    {
        return RuntimeEnabledFeatures::DeviceAttributesEnabled();
    }
    bool deviceOrientationRequestPermissionEnabled()
    {
        return RuntimeEnabledFeatures::DeviceOrientationRequestPermissionEnabled();
    }
    bool devicePostureEnabled()
    {
        return RuntimeEnabledFeatures::DevicePostureEnabled();
    }
    bool dialogCloseWhenOpenRemovedEnabled()
    {
        return RuntimeEnabledFeatures::DialogCloseWhenOpenRemovedEnabled();
    }
    bool dialogElementToggleEventsEnabled()
    {
        return RuntimeEnabledFeatures::DialogElementToggleEventsEnabled();
    }
    bool dialogNewFocusBehaviorEnabled()
    {
        return RuntimeEnabledFeatures::DialogNewFocusBehaviorEnabled();
    }
    bool digitalGoodsEnabled()
    {
        return RuntimeEnabledFeatures::DigitalGoodsEnabledByRuntimeFlag();
    }
    bool digitalGoodsV21Enabled()
    {
        return RuntimeEnabledFeatures::DigitalGoodsV2_1Enabled();
    }
    bool dirAutoFixSlotExclusionsEnabled()
    {
        return RuntimeEnabledFeatures::DirAutoFixSlotExclusionsEnabled();
    }
    bool directSocketsEnabled()
    {
        return RuntimeEnabledFeatures::DirectSocketsEnabled();
    }
    bool disableAhemAntialiasEnabled()
    {
        return RuntimeEnabledFeatures::DisableAhemAntialiasEnabled();
    }
    bool disableDifferentOriginSubframeDialogSuppressionEnabled()
    {
        return RuntimeEnabledFeatures::DisableDifferentOriginSubframeDialogSuppressionEnabledByRuntimeFlag();
    }
    bool disableHardwareNoiseSuppressionEnabled()
    {
        return RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabledByRuntimeFlag();
    }
    bool disableReduceAcceptLanguageEnabled()
    {
        return RuntimeEnabledFeatures::DisableReduceAcceptLanguageEnabledByRuntimeFlag();
    }
    bool disableSelectAllForEmptyTextEnabled()
    {
        return RuntimeEnabledFeatures::DisableSelectAllForEmptyTextEnabled();
    }
    bool disableThirdPartyStoragePartitioning2Enabled()
    {
        return RuntimeEnabledFeatures::DisableThirdPartyStoragePartitioning2EnabledByRuntimeFlag();
    }
    bool dispatchBeforeInputForSpinButtonInteractionsEnabled()
    {
        return RuntimeEnabledFeatures::DispatchBeforeInputForSpinButtonInteractionsEnabled();
    }
    bool dispatchHiddenVisibilityTransitionsEnabled()
    {
        return RuntimeEnabledFeatures::DispatchHiddenVisibilityTransitionsEnabled();
    }
    bool dispatchSelectionchangeEventPerElementEnabled()
    {
        return RuntimeEnabledFeatures::DispatchSelectionchangeEventPerElementEnabled();
    }
    bool displayContentsFocusableEnabled()
    {
        return RuntimeEnabledFeatures::DisplayContentsFocusableEnabled();
    }
    bool displayCutoutAPIEnabled()
    {
        return RuntimeEnabledFeatures::DisplayCutoutAPIEnabled();
    }
    bool documentCookieEnabled()
    {
        return RuntimeEnabledFeatures::DocumentCookieEnabled();
    }
    bool documentDomainEnabled()
    {
        return RuntimeEnabledFeatures::DocumentDomainEnabled();
    }
    bool documentInstallChunkingEnabled()
    {
        return RuntimeEnabledFeatures::DocumentInstallChunkingEnabled();
    }
    bool documentIsolationPolicyEnabled()
    {
        return RuntimeEnabledFeatures::DocumentIsolationPolicyEnabledByRuntimeFlag();
    }
    bool documentOpenOriginAliasRemovalEnabled()
    {
        return RuntimeEnabledFeatures::DocumentOpenOriginAliasRemovalEnabled();
    }
    bool documentOpenSandboxInheritanceRemovalEnabled()
    {
        return RuntimeEnabledFeatures::DocumentOpenSandboxInheritanceRemovalEnabled();
    }
    bool documentPictureInPictureAPIEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPictureInPictureAPIEnabled();
    }
    bool documentPictureInPicturePreferInitialPlacementEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPictureInPicturePreferInitialPlacementEnabled();
    }
    bool documentPictureInPictureUserActivationEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPictureInPictureUserActivationEnabled();
    }
    bool documentPolicyDocumentDomainEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPolicyDocumentDomainEnabled();
    }
    bool documentPolicyExpectNoLinkedResourcesEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPolicyExpectNoLinkedResourcesEnabled();
    }
    bool documentPolicyIncludeJSCallStacksInCrashReportsEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPolicyIncludeJSCallStacksInCrashReportsEnabledByRuntimeFlag();
    }
    bool documentPolicyNegotiationEnabled()
    {
        return RuntimeEnabledFeatures::DocumentPolicyNegotiationEnabledByRuntimeFlag();
    }
    bool documentPolicySyncXHREnabled()
    {
        return RuntimeEnabledFeatures::DocumentPolicySyncXHREnabled();
    }
    bool documentRenderBlockingEnabled()
    {
        return RuntimeEnabledFeatures::DocumentRenderBlockingEnabled();
    }
    bool documentWriteEnabled()
    {
        return RuntimeEnabledFeatures::DocumentWriteEnabled();
    }
    bool domPartsAPIEnabled()
    {
        return RuntimeEnabledFeatures::DOMPartsAPIEnabled();
    }
    bool domPartsAPIMinimalEnabled()
    {
        return RuntimeEnabledFeatures::DOMPartsAPIMinimalEnabled();
    }
    bool dropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled()
    {
        return RuntimeEnabledFeatures::DropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled();
    }
    bool dynamicSafeAreaInsetsEnabled()
    {
        return RuntimeEnabledFeatures::DynamicSafeAreaInsetsEnabled();
    }
    bool dynamicSafeAreaInsetsOnScrollEnabled()
    {
        return RuntimeEnabledFeatures::DynamicSafeAreaInsetsOnScrollEnabled();
    }
    bool elementCaptureEnabled()
    {
        return RuntimeEnabledFeatures::ElementCaptureEnabled();
    }
    bool elementGetInnerHTMLEnabled()
    {
        return RuntimeEnabledFeatures::ElementGetInnerHTMLEnabled();
    }
    bool enforceAnonymityExposureEnabled()
    {
        return RuntimeEnabledFeatures::EnforceAnonymityExposureEnabled();
    }
    bool escapeLtGtInAttributesEnabled()
    {
        return RuntimeEnabledFeatures::EscapeLtGtInAttributesEnabled();
    }
    bool eventTimingHandleKeyboardEventSimulatedClickEnabled()
    {
        return RuntimeEnabledFeatures::EventTimingHandleKeyboardEventSimulatedClickEnabled();
    }
    bool eventTimingInteractionCountEnabled()
    {
        return RuntimeEnabledFeatures::EventTimingInteractionCountEnabled();
    }
    bool eventTimingSelectionAutoScrollNoInteractionIdEnabled()
    {
        return RuntimeEnabledFeatures::EventTimingSelectionAutoScrollNoInteractionIdEnabled();
    }
    bool eventTimingTapStopScrollNoInteractionIdEnabled()
    {
        return RuntimeEnabledFeatures::EventTimingTapStopScrollNoInteractionIdEnabled();
    }
    bool excludeTransparentTextsFromBeingLcpEligibleEnabled()
    {
        return RuntimeEnabledFeatures::ExcludeTransparentTextsFromBeingLcpEligibleEnabled();
    }
    bool experimentalContentSecurityPolicyFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::ExperimentalContentSecurityPolicyFeaturesEnabled();
    }
    bool experimentalJSProfilerMarkersEnabled()
    {
        return RuntimeEnabledFeatures::ExperimentalJSProfilerMarkersEnabled();
    }
    bool experimentalMachineLearningNeuralNetworkEnabled()
    {
        return RuntimeEnabledFeatures::ExperimentalMachineLearningNeuralNetworkEnabled();
    }
    bool experimentalPoliciesEnabled()
    {
        return RuntimeEnabledFeatures::ExperimentalPoliciesEnabled();
    }
    bool exposeCoarsenedRenderTimeEnabled()
    {
        return RuntimeEnabledFeatures::ExposeCoarsenedRenderTimeEnabled();
    }
    bool exposeRenderTimeNonTaoDelayedImageEnabled()
    {
        return RuntimeEnabledFeatures::ExposeRenderTimeNonTaoDelayedImageEnabled();
    }
    bool extendedTextMetricsEnabled()
    {
        return RuntimeEnabledFeatures::ExtendedTextMetricsEnabled();
    }
    bool eyeDropperAPIEnabled()
    {
        return RuntimeEnabledFeatures::EyeDropperAPIEnabled();
    }
    bool faceDetectorEnabled()
    {
        return RuntimeEnabledFeatures::FaceDetectorEnabled();
    }
    bool fastNonCompositedScrollHitTestEnabled()
    {
        return RuntimeEnabledFeatures::FastNonCompositedScrollHitTestEnabled();
    }
    bool fastPathSingleSelectorExactMatchEnabled()
    {
        return RuntimeEnabledFeatures::FastPathSingleSelectorExactMatchEnabled();
    }
    bool fastPositionIteratorEnabled()
    {
        return RuntimeEnabledFeatures::FastPositionIteratorEnabled();
    }
    bool fedCmEnabled()
    {
        return RuntimeEnabledFeatures::FedCmEnabled();
    }
    bool fedCmAuthzEnabled()
    {
        return RuntimeEnabledFeatures::FedCmAuthzEnabledByRuntimeFlag();
    }
    bool fedCmAutoSelectedFlagEnabled()
    {
        return RuntimeEnabledFeatures::FedCmAutoSelectedFlagEnabled();
    }
    bool fedCmButtonModeEnabled()
    {
        return RuntimeEnabledFeatures::FedCmButtonModeEnabledByRuntimeFlag();
    }
    bool fedCmDisconnectEnabled()
    {
        return RuntimeEnabledFeatures::FedCmDisconnectEnabled();
    }
    bool fedCmDomainHintEnabled()
    {
        return RuntimeEnabledFeatures::FedCmDomainHintEnabled();
    }
    bool fedCmErrorEnabled()
    {
        return RuntimeEnabledFeatures::FedCmErrorEnabled();
    }
    bool fedCmIdPRegistrationEnabled()
    {
        return RuntimeEnabledFeatures::FedCmIdPRegistrationEnabled();
    }
    bool fedCmIdpSigninStatusEnabled()
    {
        return RuntimeEnabledFeatures::FedCmIdpSigninStatusEnabled();
    }
    bool fedCmMultipleIdentityProvidersEnabled()
    {
        return RuntimeEnabledFeatures::FedCmMultipleIdentityProvidersEnabledByRuntimeFlag();
    }
    bool fedCmSelectiveDisclosureEnabled()
    {
        return RuntimeEnabledFeatures::FedCmSelectiveDisclosureEnabled();
    }
    bool fedCmWithStorageAccessAPIEnabled()
    {
        return RuntimeEnabledFeatures::FedCmWithStorageAccessAPIEnabledByRuntimeFlag();
    }
    bool fencedFramesEnabled()
    {
        return RuntimeEnabledFeatures::FencedFramesEnabled();
    }
    bool fencedFramesAPIChangesEnabled()
    {
        return RuntimeEnabledFeatures::FencedFramesAPIChangesEnabled();
    }
    bool fencedFramesDefaultModeEnabled()
    {
        return RuntimeEnabledFeatures::FencedFramesDefaultModeEnabled();
    }
    bool fencedFramesLocalUnpartitionedDataAccessEnabled()
    {
        return RuntimeEnabledFeatures::FencedFramesLocalUnpartitionedDataAccessEnabled();
    }
    bool fetchBodyBytesEnabled()
    {
        return RuntimeEnabledFeatures::FetchBodyBytesEnabled();
    }
    bool fetchLaterAPIEnabled()
    {
        return RuntimeEnabledFeatures::FetchLaterAPIEnabledByRuntimeFlag();
    }
    bool fetchUploadStreamingEnabled()
    {
        return RuntimeEnabledFeatures::FetchUploadStreamingEnabled();
    }
    bool fileHandlingEnabled()
    {
        return RuntimeEnabledFeatures::FileHandlingEnabled();
    }
    bool fileHandlingIconsEnabled()
    {
        return RuntimeEnabledFeatures::FileHandlingIconsEnabled();
    }
    bool fileSystemEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemEnabled();
    }
    bool fileSystemAccessEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemAccessEnabled();
    }
    bool fileSystemAccessAPIExperimentalEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemAccessAPIExperimentalEnabled();
    }
    bool fileSystemAccessGetCloudIdentifiersEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemAccessGetCloudIdentifiersEnabled();
    }
    bool fileSystemAccessLocalEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemAccessLocalEnabled();
    }
    bool fileSystemAccessLockingSchemeEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemAccessLockingSchemeEnabled();
    }
    bool fileSystemAccessOriginPrivateEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemAccessOriginPrivateEnabled();
    }
    bool fileSystemObserverEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemObserverEnabledByRuntimeFlag();
    }
    bool fileSystemObserverUnobserveEnabled()
    {
        return RuntimeEnabledFeatures::FileSystemObserverUnobserveEnabled();
    }
    bool findDecomposedInShortTextEnabled()
    {
        return RuntimeEnabledFeatures::FindDecomposedInShortTextEnabled();
    }
    bool findRubyInPageEnabled()
    {
        return RuntimeEnabledFeatures::FindRubyInPageEnabled();
    }
    bool findTextInReadonlyTextInputEnabled()
    {
        return RuntimeEnabledFeatures::FindTextInReadonlyTextInputEnabled();
    }
    bool findTextSkipCollapsedTextEnabled()
    {
        return RuntimeEnabledFeatures::FindTextSkipCollapsedTextEnabled();
    }
    bool fledgeEnabled()
    {
        return RuntimeEnabledFeatures::FledgeEnabled();
    }
    bool fledgeAuctionDealSupportEnabled()
    {
        return RuntimeEnabledFeatures::FledgeAuctionDealSupportEnabled();
    }
    bool fledgeBiddingAndAuctionServerAPIEnabled()
    {
        return RuntimeEnabledFeatures::FledgeBiddingAndAuctionServerAPIEnabledByRuntimeFlag();
    }
    bool fledgeCustomMaxAuctionAdComponentsEnabled()
    {
        return RuntimeEnabledFeatures::FledgeCustomMaxAuctionAdComponentsEnabled();
    }
    bool fledgeDeprecatedRenderURLReplacementsEnabled()
    {
        return RuntimeEnabledFeatures::FledgeDeprecatedRenderURLReplacementsEnabled();
    }
    bool fledgeDirectFromSellerSignalsHeaderAdSlotEnabled()
    {
        return RuntimeEnabledFeatures::FledgeDirectFromSellerSignalsHeaderAdSlotEnabled();
    }
    bool fledgeMultiBidEnabled()
    {
        return RuntimeEnabledFeatures::FledgeMultiBidEnabled();
    }
    bool fledgeRealTimeReportingEnabled()
    {
        return RuntimeEnabledFeatures::FledgeRealTimeReportingEnabled();
    }
    bool fledgeReportingTimeoutEnabled()
    {
        return RuntimeEnabledFeatures::FledgeReportingTimeoutEnabled();
    }
    bool fledgeSellerNonceEnabled()
    {
        return RuntimeEnabledFeatures::FledgeSellerNonceEnabled();
    }
    bool fledgeTrustedSignalsKVv2SupportEnabled()
    {
        return RuntimeEnabledFeatures::FledgeTrustedSignalsKVv2SupportEnabled();
    }
    bool fluentOverlayScrollbarsEnabled()
    {
        return RuntimeEnabledFeatures::FluentOverlayScrollbarsEnabled();
    }
    bool fluentScrollbarsEnabled()
    {
        return RuntimeEnabledFeatures::FluentScrollbarsEnabled();
    }
    bool fluentScrollbarUsesNinePatchTrackEnabled()
    {
        return RuntimeEnabledFeatures::FluentScrollbarUsesNinePatchTrackEnabled();
    }
    bool focusgroupEnabled()
    {
        return RuntimeEnabledFeatures::FocusgroupEnabledByRuntimeFlag();
    }
    bool fontAccessEnabled()
    {
        return RuntimeEnabledFeatures::FontAccessEnabled();
    }
    bool fontationsFontBackendEnabled()
    {
        return RuntimeEnabledFeatures::FontationsFontBackendEnabled();
    }
    bool fontationsForSelectedFormatsEnabled()
    {
        return RuntimeEnabledFeatures::FontationsForSelectedFormatsEnabled();
    }
    bool fontFamilyPostscriptMatchingCTMigrationEnabled()
    {
        return RuntimeEnabledFeatures::FontFamilyPostscriptMatchingCTMigrationEnabled();
    }
    bool fontFamilyStyleMatchingCTMigrationEnabled()
    {
        return RuntimeEnabledFeatures::FontFamilyStyleMatchingCTMigrationEnabled();
    }
    bool fontPresentWinEnabled()
    {
        return RuntimeEnabledFeatures::FontPresentWinEnabled();
    }
    bool fontSrcLocalMatchingEnabled()
    {
        return RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled();
    }
    bool fontSystemFallbackNotoCjkEnabled()
    {
        return RuntimeEnabledFeatures::FontSystemFallbackNotoCjkEnabled();
    }
    bool fontVariantEmojiEnabled()
    {
        return RuntimeEnabledFeatures::FontVariantEmojiEnabled();
    }
    bool fontVariationSequencesEnabled()
    {
        return RuntimeEnabledFeatures::FontVariationSequencesEnabled();
    }
    bool forcedColorsEnabled()
    {
        return RuntimeEnabledFeatures::ForcedColorsEnabled();
    }
    bool forcedColorsPreserveParentColorEnabled()
    {
        return RuntimeEnabledFeatures::ForcedColorsPreserveParentColorEnabled();
    }
    bool forceEagerMeasureMemoryEnabled()
    {
        return RuntimeEnabledFeatures::ForceEagerMeasureMemoryEnabled();
    }
    bool forceReduceMotionEnabled()
    {
        return RuntimeEnabledFeatures::ForceReduceMotionEnabled();
    }
    bool forceTallerSelectPopupEnabled()
    {
        return RuntimeEnabledFeatures::ForceTallerSelectPopupEnabled();
    }
    bool formControlRestoreStateIfAutocompleteOffEnabled()
    {
        return RuntimeEnabledFeatures::FormControlRestoreStateIfAutocompleteOffEnabled();
    }
    bool formControlsVerticalWritingModeDirectionSupportEnabled()
    {
        return RuntimeEnabledFeatures::FormControlsVerticalWritingModeDirectionSupportEnabled();
    }
    bool fractionalScrollOffsetsEnabled()
    {
        return RuntimeEnabledFeatures::FractionalScrollOffsetsEnabled();
    }
    bool freezeFramesOnVisibilityEnabled()
    {
        return RuntimeEnabledFeatures::FreezeFramesOnVisibilityEnabled();
    }
    bool gamepadMultitouchEnabled()
    {
        return RuntimeEnabledFeatures::GamepadMultitouchEnabled();
    }
    bool getAllScreensMediaEnabled()
    {
        return RuntimeEnabledFeatures::GetAllScreensMediaEnabledByRuntimeFlag();
    }
    bool getDisplayMediaEnabled()
    {
        return RuntimeEnabledFeatures::GetDisplayMediaEnabled();
    }
    bool getDisplayMediaRequiresUserActivationEnabled()
    {
        return RuntimeEnabledFeatures::GetDisplayMediaRequiresUserActivationEnabled();
    }
    bool groupEffectEnabled()
    {
        return RuntimeEnabledFeatures::GroupEffectEnabled();
    }
    bool handleSelectionChangeOnDeletingEmptyElementEnabled()
    {
        return RuntimeEnabledFeatures::HandleSelectionChangeOnDeletingEmptyElementEnabled();
    }
    bool handwritingRecognitionEnabled()
    {
        return RuntimeEnabledFeatures::HandwritingRecognitionEnabled();
    }
    bool hangingWhitespaceDoesNotDependOnAlignmentEnabled()
    {
        return RuntimeEnabledFeatures::HangingWhitespaceDoesNotDependOnAlignmentEnabled();
    }
    bool hasUAVisualTransitionEnabled()
    {
        return RuntimeEnabledFeatures::HasUAVisualTransitionEnabled();
    }
    bool highlightInheritanceEnabled()
    {
        return RuntimeEnabledFeatures::HighlightInheritanceEnabled();
    }
    bool highlightPointerEventsEnabled()
    {
        return RuntimeEnabledFeatures::HighlightPointerEventsEnabled();
    }
    bool highlightsFromPointEnabled()
    {
        return RuntimeEnabledFeatures::HighlightsFromPointEnabled();
    }
    bool hitTestOpaquenessEnabled()
    {
        return RuntimeEnabledFeatures::HitTestOpaquenessEnabled();
    }
    bool hitTestOpaquenessOmitLineBoxEnabled()
    {
        return RuntimeEnabledFeatures::HitTestOpaquenessOmitLineBoxEnabled();
    }
    bool hrefTranslateEnabled()
    {
        return RuntimeEnabledFeatures::HrefTranslateEnabledByRuntimeFlag();
    }
    bool htmlAnchorAttributeEnabled()
    {
        return RuntimeEnabledFeatures::HTMLAnchorAttributeEnabled();
    }
    bool htmlDialogLightDismissEnabled()
    {
        return RuntimeEnabledFeatures::HTMLDialogLightDismissEnabled();
    }
    bool htmlEmbedElementNotForceLayoutEnabled()
    {
        return RuntimeEnabledFeatures::HTMLEmbedElementNotForceLayoutEnabled();
    }
    bool htmlInterestTargetAttributeEnabled()
    {
        return RuntimeEnabledFeatures::HTMLInterestTargetAttributeEnabled();
    }
    bool htmlInvokeActionsV2Enabled()
    {
        return RuntimeEnabledFeatures::HTMLInvokeActionsV2Enabled();
    }
    bool htmlInvokeTargetAttributeEnabled()
    {
        return RuntimeEnabledFeatures::HTMLInvokeTargetAttributeEnabled();
    }
    bool htmlObjectElementFallbackDetachContentFrameEnabled()
    {
        return RuntimeEnabledFeatures::HTMLObjectElementFallbackDetachContentFrameEnabled();
    }
    bool htmlParserYieldAndDelayOftenForTestingEnabled()
    {
        return RuntimeEnabledFeatures::HTMLParserYieldAndDelayOftenForTestingEnabled();
    }
    bool htmlPopoverActionHoverEnabled()
    {
        return RuntimeEnabledFeatures::HTMLPopoverActionHoverEnabled();
    }
    bool htmlPopoverHintEnabled()
    {
        return RuntimeEnabledFeatures::HTMLPopoverHintEnabled();
    }
    bool htmlSelectElementShowPickerEnabled()
    {
        return RuntimeEnabledFeatures::HTMLSelectElementShowPickerEnabled();
    }
    bool implicitRootScrollerEnabled()
    {
        return RuntimeEnabledFeatures::ImplicitRootScrollerEnabled();
    }
    bool importAttributesDisallowUnknownKeysEnabled()
    {
        return RuntimeEnabledFeatures::ImportAttributesDisallowUnknownKeysEnabled();
    }
    bool importMapIntegrityEnabled()
    {
        return RuntimeEnabledFeatures::ImportMapIntegrityEnabled();
    }
    bool incomingCallNotificationsEnabled()
    {
        return RuntimeEnabledFeatures::IncomingCallNotificationsEnabled();
    }
    bool incrementLocalSurfaceIdForMainframeSameDocNavigationEnabled()
    {
        return RuntimeEnabledFeatures::IncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled();
    }
    bool indexedDbGetAllRecordsEnabled()
    {
        return RuntimeEnabledFeatures::IndexedDbGetAllRecordsEnabled();
    }
    bool inertElementNonEditableEnabled()
    {
        return RuntimeEnabledFeatures::InertElementNonEditableEnabled();
    }
    bool inertElementNonSearchableEnabled()
    {
        return RuntimeEnabledFeatures::InertElementNonSearchableEnabled();
    }
    bool infiniteCullRectEnabled()
    {
        return RuntimeEnabledFeatures::InfiniteCullRectEnabled();
    }
    bool inheritUserModifyWithoutContenteditableEnabled()
    {
        return RuntimeEnabledFeatures::InheritUserModifyWithoutContenteditableEnabled();
    }
    bool initialLetterRaiseBySpecifiedEnabled()
    {
        return RuntimeEnabledFeatures::InitialLetterRaiseBySpecifiedEnabled();
    }
    bool inlineBlockInSameLineEnabled()
    {
        return RuntimeEnabledFeatures::InlineBlockInSameLineEnabled();
    }
    bool innerHTMLParserFastpathLogFailureEnabled()
    {
        return RuntimeEnabledFeatures::InnerHTMLParserFastpathLogFailureEnabled();
    }
    bool inputClosesSelectEnabled()
    {
        return RuntimeEnabledFeatures::InputClosesSelectEnabled();
    }
    bool inputMultipleFieldsUIEnabled()
    {
        return RuntimeEnabledFeatures::InputMultipleFieldsUIEnabled();
    }
    bool insertBlockquoteBeforeOuterBlockEnabled()
    {
        return RuntimeEnabledFeatures::InsertBlockquoteBeforeOuterBlockEnabled();
    }
    bool insertLineBreakIfPhrasingContentEnabled()
    {
        return RuntimeEnabledFeatures::InsertLineBreakIfPhrasingContentEnabled();
    }
    bool inspectorGhostRulesEnabled()
    {
        return RuntimeEnabledFeatures::InspectorGhostRulesEnabled();
    }
    bool installedAppEnabled()
    {
        return RuntimeEnabledFeatures::InstalledAppEnabled();
    }
    bool installOnDeviceSpeechRecognitionEnabled()
    {
        return RuntimeEnabledFeatures::InstallOnDeviceSpeechRecognitionEnabled();
    }
    bool interestGroupsInSharedStorageWorkletEnabled()
    {
        return RuntimeEnabledFeatures::InterestGroupsInSharedStorageWorkletEnabled();
    }
    bool interoperablePrivateAttributionEnabled()
    {
        return RuntimeEnabledFeatures::InteroperablePrivateAttributionEnabled();
    }
    bool intersectionObserverScrollMarginEnabled()
    {
        return RuntimeEnabledFeatures::IntersectionObserverScrollMarginEnabled();
    }
    bool invertedColorsEnabled()
    {
        return RuntimeEnabledFeatures::InvertedColorsEnabled();
    }
    bool invisibleSVGAnimationThrottlingEnabled()
    {
        return RuntimeEnabledFeatures::InvisibleSVGAnimationThrottlingEnabled();
    }
    bool javaScriptCompileHintsMagicAlwaysRuntimeEnabled()
    {
        return RuntimeEnabledFeatures::JavaScriptCompileHintsMagicAlwaysRuntimeEnabledByRuntimeFlag();
    }
    bool javaScriptCompileHintsMagicRuntimeEnabled()
    {
        return RuntimeEnabledFeatures::JavaScriptCompileHintsMagicRuntimeEnabledByRuntimeFlag();
    }
    bool keepCSSTargetAfterReattachEnabled()
    {
        return RuntimeEnabledFeatures::KeepCSSTargetAfterReattachEnabled();
    }
    bool keyboardAccessibleTooltipEnabled()
    {
        return RuntimeEnabledFeatures::KeyboardAccessibleTooltipEnabled();
    }
    bool keyboardFocusableScrollersEnabled()
    {
        return RuntimeEnabledFeatures::KeyboardFocusableScrollersEnabled();
    }
    bool keyboardFocusableScrollersOptOutEnabled()
    {
        return RuntimeEnabledFeatures::KeyboardFocusableScrollersOptOutEnabledByRuntimeFlag();
    }
    bool labelAndDelegatesFocusNewHandlingEnabled()
    {
        return RuntimeEnabledFeatures::LabelAndDelegatesFocusNewHandlingEnabled();
    }
    bool langAttributeAwareFormControlUIEnabled()
    {
        return RuntimeEnabledFeatures::LangAttributeAwareFormControlUIEnabled();
    }
    bool languageDetectionAPIEnabled()
    {
        return RuntimeEnabledFeatures::LanguageDetectionAPIEnabledByRuntimeFlag();
    }
    bool layoutFlexNewRowAlgorithmV3Enabled()
    {
        return RuntimeEnabledFeatures::LayoutFlexNewRowAlgorithmV3Enabled();
    }
    bool layoutIgnoreMarginsForStickyEnabled()
    {
        return RuntimeEnabledFeatures::LayoutIgnoreMarginsForStickyEnabled();
    }
    bool layoutJustifySelfForBlocksEnabled()
    {
        return RuntimeEnabledFeatures::LayoutJustifySelfForBlocksEnabled();
    }
    bool layoutNGShapeCacheEnabled()
    {
        return RuntimeEnabledFeatures::LayoutNGShapeCacheEnabled();
    }
    bool layoutStretchEnabled()
    {
        return RuntimeEnabledFeatures::LayoutStretchEnabled();
    }
    bool lazyInitializeMediaControlsEnabled()
    {
        return RuntimeEnabledFeatures::LazyInitializeMediaControlsEnabled();
    }
    bool lazyLoadScrollMarginEnabled()
    {
        return RuntimeEnabledFeatures::LazyLoadScrollMarginEnabled();
    }
    bool lazyLoadScrollMarginIframeEnabled()
    {
        return RuntimeEnabledFeatures::LazyLoadScrollMarginIframeEnabled();
    }
    bool lcpAnimatedImagesWebExposedEnabled()
    {
        return RuntimeEnabledFeatures::LCPAnimatedImagesWebExposedEnabled();
    }
    bool legacyWindowsDWriteFontFallbackEnabled()
    {
        return RuntimeEnabledFeatures::LegacyWindowsDWriteFontFallbackEnabled();
    }
    bool limitThirdPartyCookiesEnabled()
    {
        return RuntimeEnabledFeatures::LimitThirdPartyCookiesEnabledByRuntimeFlag();
    }
    bool lineBoxBelowLeadingFloatsEnabled()
    {
        return RuntimeEnabledFeatures::LineBoxBelowLeadingFloatsEnabled();
    }
    bool listItemWithCounterSetNotSetExplicitValueEnabled()
    {
        return RuntimeEnabledFeatures::ListItemWithCounterSetNotSetExplicitValueEnabled();
    }
    bool lockedModeEnabled()
    {
        return RuntimeEnabledFeatures::LockedModeEnabled();
    }
    bool longAnimationFrameTimingEnabled()
    {
        return RuntimeEnabledFeatures::LongAnimationFrameTimingEnabled();
    }
    bool longPressLinkSelectTextEnabled()
    {
        return RuntimeEnabledFeatures::LongPressLinkSelectTextEnabled();
    }
    bool longTaskFromLongAnimationFrameEnabled()
    {
        return RuntimeEnabledFeatures::LongTaskFromLongAnimationFrameEnabled();
    }
    bool machineLearningNeuralNetworkEnabled()
    {
        return RuntimeEnabledFeatures::MachineLearningNeuralNetworkEnabled();
    }
    bool managedConfigurationEnabled()
    {
        return RuntimeEnabledFeatures::ManagedConfigurationEnabled();
    }
    bool measureMemoryEnabled()
    {
        return RuntimeEnabledFeatures::MeasureMemoryEnabled();
    }
    bool mediaCapabilitiesDynamicRangeEnabled()
    {
        return RuntimeEnabledFeatures::MediaCapabilitiesDynamicRangeEnabled();
    }
    bool mediaCapabilitiesEncodingInfoEnabled()
    {
        return RuntimeEnabledFeatures::MediaCapabilitiesEncodingInfoEnabled();
    }
    bool mediaCapabilitiesSpatialAudioEnabled()
    {
        return RuntimeEnabledFeatures::MediaCapabilitiesSpatialAudioEnabled();
    }
    bool mediaCaptureEnabled()
    {
        return RuntimeEnabledFeatures::MediaCaptureEnabled();
    }
    bool mediaCaptureBackgroundBlurEnabled()
    {
        return RuntimeEnabledFeatures::MediaCaptureBackgroundBlurEnabledByRuntimeFlag();
    }
    bool mediaCaptureCameraControlsEnabled()
    {
        return RuntimeEnabledFeatures::MediaCaptureCameraControlsEnabled();
    }
    bool mediaCaptureConfigurationChangeEnabled()
    {
        return RuntimeEnabledFeatures::MediaCaptureConfigurationChangeEnabledByRuntimeFlag();
    }
    bool mediaCaptureVoiceIsolationEnabled()
    {
        return RuntimeEnabledFeatures::MediaCaptureVoiceIsolationEnabled();
    }
    bool mediaCastOverlayButtonEnabled()
    {
        return RuntimeEnabledFeatures::MediaCastOverlayButtonEnabled();
    }
    bool mediaControlsExpandGestureEnabled()
    {
        return RuntimeEnabledFeatures::MediaControlsExpandGestureEnabled();
    }
    bool mediaControlsOverlayPlayButtonEnabled()
    {
        return RuntimeEnabledFeatures::MediaControlsOverlayPlayButtonEnabled();
    }
    bool mediaElementVolumeGreaterThanOneEnabled()
    {
        return RuntimeEnabledFeatures::MediaElementVolumeGreaterThanOneEnabled();
    }
    bool mediaEngagementBypassAutoplayPoliciesEnabled()
    {
        return RuntimeEnabledFeatures::MediaEngagementBypassAutoplayPoliciesEnabled();
    }
    bool mediaLatencyHintEnabled()
    {
        return RuntimeEnabledFeatures::MediaLatencyHintEnabled();
    }
    bool mediaPlaybackWhileNotVisiblePermissionPolicyEnabled()
    {
        return RuntimeEnabledFeatures::MediaPlaybackWhileNotVisiblePermissionPolicyEnabled();
    }
    bool mediaPreviewsOptOutEnabled()
    {
        return RuntimeEnabledFeatures::MediaPreviewsOptOutEnabledByRuntimeFlag();
    }
    bool mediaQueryNavigationControlsEnabled()
    {
        return RuntimeEnabledFeatures::MediaQueryNavigationControlsEnabled();
    }
    bool mediaRecorderUseMediaVideoEncoderEnabled()
    {
        return RuntimeEnabledFeatures::MediaRecorderUseMediaVideoEncoderEnabled();
    }
    bool mediaSessionEnabled()
    {
        return RuntimeEnabledFeatures::MediaSessionEnabled();
    }
    bool mediaSessionChapterInformationEnabled()
    {
        return RuntimeEnabledFeatures::MediaSessionChapterInformationEnabled();
    }
    bool mediaSessionEnterPictureInPictureEnabled()
    {
        return RuntimeEnabledFeatures::MediaSessionEnterPictureInPictureEnabled();
    }
    bool mediaSourceExperimentalEnabled()
    {
        return RuntimeEnabledFeatures::MediaSourceExperimentalEnabled();
    }
    bool mediaSourceExtensionsForWebCodecsEnabled()
    {
        return RuntimeEnabledFeatures::MediaSourceExtensionsForWebCodecsEnabledByRuntimeFlag();
    }
    bool mediaSourceNewAbortAndDurationEnabled()
    {
        return RuntimeEnabledFeatures::MediaSourceNewAbortAndDurationEnabled();
    }
    bool mediaStreamTrackTransferEnabled()
    {
        return RuntimeEnabledFeatures::MediaStreamTrackTransferEnabled();
    }
    bool mediaStreamTrackWebSpeechEnabled()
    {
        return RuntimeEnabledFeatures::MediaStreamTrackWebSpeechEnabled();
    }
    bool messagePortCloseEventEnabled()
    {
        return RuntimeEnabledFeatures::MessagePortCloseEventEnabled();
    }
    bool metaRefreshNoFractionalEnabled()
    {
        return RuntimeEnabledFeatures::MetaRefreshNoFractionalEnabled();
    }
    bool meterAppearanceNoneFallbackStyleEnabled()
    {
        return RuntimeEnabledFeatures::MeterAppearanceNoneFallbackStyleEnabled();
    }
    bool meterDevolveAppearanceEnabled()
    {
        return RuntimeEnabledFeatures::MeterDevolveAppearanceEnabled();
    }
    bool middleClickAutoscrollEnabled()
    {
        return RuntimeEnabledFeatures::MiddleClickAutoscrollEnabled();
    }
    bool minimimalResourceRequestPrepBeforeCacheLookupEnabled()
    {
        return RuntimeEnabledFeatures::MinimimalResourceRequestPrepBeforeCacheLookupEnabled();
    }
    bool mobileLayoutThemeEnabled()
    {
        return RuntimeEnabledFeatures::MobileLayoutThemeEnabled();
    }
    bool modifyParagraphCrossEditingoundaryEnabled()
    {
        return RuntimeEnabledFeatures::ModifyParagraphCrossEditingoundaryEnabled();
    }
    bool mojoJSEnabled()
    {
        return RuntimeEnabledFeatures::MojoJSEnabled();
    }
    bool mojoJSTestEnabled()
    {
        return RuntimeEnabledFeatures::MojoJSTestEnabled();
    }
    bool moveEndingSelectionToListChildEnabled()
    {
        return RuntimeEnabledFeatures::MoveEndingSelectionToListChildEnabled();
    }
    bool moveToParagraphStartOrEndSkipsNonEditableEnabled()
    {
        return RuntimeEnabledFeatures::MoveToParagraphStartOrEndSkipsNonEditableEnabled();
    }
    bool multipleImportMapsEnabled()
    {
        return RuntimeEnabledFeatures::MultipleImportMapsEnabled();
    }
    bool multiSelectDeselectWhenOnlyOptionEnabled()
    {
        return RuntimeEnabledFeatures::MultiSelectDeselectWhenOnlyOptionEnabled();
    }
    bool multiSmoothScrollIntoViewEnabled()
    {
        return RuntimeEnabledFeatures::MultiSmoothScrollIntoViewEnabled();
    }
    bool mutationEventsEnabled()
    {
        return RuntimeEnabledFeatures::MutationEventsEnabledByRuntimeFlag();
    }
    bool mutationEventsSpecialTrialMessageEnabled()
    {
        return RuntimeEnabledFeatures::MutationEventsSpecialTrialMessageEnabled();
    }
    bool navigateEventCommitBehaviorEnabled()
    {
        return RuntimeEnabledFeatures::NavigateEventCommitBehaviorEnabled();
    }
    bool navigateEventSourceElementEnabled()
    {
        return RuntimeEnabledFeatures::NavigateEventSourceElementEnabled();
    }
    bool navigationActivationEnabled()
    {
        return RuntimeEnabledFeatures::NavigationActivationEnabled();
    }
    bool navigationIdEnabled()
    {
        return RuntimeEnabledFeatures::NavigationIdEnabledByRuntimeFlag();
    }
    bool navigatorContentUtilsEnabled()
    {
        return RuntimeEnabledFeatures::NavigatorContentUtilsEnabled();
    }
    bool nestedViewTransitionEnabled()
    {
        return RuntimeEnabledFeatures::NestedViewTransitionEnabled();
    }
    bool netInfoConstantTypeEnabled()
    {
        return RuntimeEnabledFeatures::NetInfoConstantTypeEnabled();
    }
    bool netInfoDownlinkMaxEnabled()
    {
        return RuntimeEnabledFeatures::NetInfoDownlinkMaxEnabled();
    }
    bool newGetFocusableAreaBehaviorEnabled()
    {
        return RuntimeEnabledFeatures::NewGetFocusableAreaBehaviorEnabled();
    }
    bool noIdleEncodingForWebTestsEnabled()
    {
        return RuntimeEnabledFeatures::NoIdleEncodingForWebTestsEnabled();
    }
    bool noIncreasingEndOffsetOnSplittingTextNodesEnabled()
    {
        return RuntimeEnabledFeatures::NoIncreasingEndOffsetOnSplittingTextNodesEnabled();
    }
    bool nonEmptyBlockquotesOnOutdentingEnabled()
    {
        return RuntimeEnabledFeatures::NonEmptyBlockquotesOnOutdentingEnabled();
    }
    bool nonNullInputEventDataForTextAreaEnabled()
    {
        return RuntimeEnabledFeatures::NonNullInputEventDataForTextAreaEnabled();
    }
    bool nonStandardAppearanceValueSliderVerticalEnabled()
    {
        return RuntimeEnabledFeatures::NonStandardAppearanceValueSliderVerticalEnabled();
    }
    bool notificationConstructorEnabled()
    {
        return RuntimeEnabledFeatures::NotificationConstructorEnabled();
    }
    bool notificationContentImageEnabled()
    {
        return RuntimeEnabledFeatures::NotificationContentImageEnabled();
    }
    bool notificationsEnabled()
    {
        return RuntimeEnabledFeatures::NotificationsEnabled();
    }
    bool notificationTriggersEnabled()
    {
        return RuntimeEnabledFeatures::NotificationTriggersEnabledByRuntimeFlag();
    }
    bool observableAPIEnabled()
    {
        return RuntimeEnabledFeatures::ObservableAPIEnabled();
    }
    bool offMainThreadCSSPaintEnabled()
    {
        return RuntimeEnabledFeatures::OffMainThreadCSSPaintEnabled();
    }
    bool offscreenCanvasCommitEnabled()
    {
        return RuntimeEnabledFeatures::OffscreenCanvasCommitEnabled();
    }
    bool omitBlurEventOnElementRemovalEnabled()
    {
        return RuntimeEnabledFeatures::OmitBlurEventOnElementRemovalEnabled();
    }
    bool onDeviceChangeEnabled()
    {
        return RuntimeEnabledFeatures::OnDeviceChangeEnabled();
    }
    bool onDeviceWebSpeechAvailableEnabled()
    {
        return RuntimeEnabledFeatures::OnDeviceWebSpeechAvailableEnabled();
    }
    bool orientationEventEnabled()
    {
        return RuntimeEnabledFeatures::OrientationEventEnabled();
    }
    bool originIsolationHeaderEnabled()
    {
        return RuntimeEnabledFeatures::OriginIsolationHeaderEnabled();
    }
    bool originPolicyEnabled()
    {
        return RuntimeEnabledFeatures::OriginPolicyEnabled();
    }
    bool originTrialsSampleAPIEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIBrowserReadWriteEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIBrowserReadWriteEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIDependentEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIDependentEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIDeprecationEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIExpiryGracePeriodEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIExpiryGracePeriodEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIImpliedEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIInvalidOSEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPINavigationEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIPersistentExpiryGracePeriodEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIPersistentFeatureEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIPersistentFeatureEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIPersistentInvalidOSEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIPersistentInvalidOSEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabledByRuntimeFlag();
    }
    bool originTrialsSampleAPIThirdPartyEnabled()
    {
        return RuntimeEnabledFeatures::OriginTrialsSampleAPIThirdPartyEnabledByRuntimeFlag();
    }
    bool overscrollCustomizationEnabled()
    {
        return RuntimeEnabledFeatures::OverscrollCustomizationEnabled();
    }
    bool pageFreezeOptInEnabled()
    {
        return RuntimeEnabledFeatures::PageFreezeOptInEnabledByRuntimeFlag();
    }
    bool pageFreezeOptOutEnabled()
    {
        return RuntimeEnabledFeatures::PageFreezeOptOutEnabledByRuntimeFlag();
    }
    bool pageMarginBoxesEnabled()
    {
        return RuntimeEnabledFeatures::PageMarginBoxesEnabled();
    }
    bool pagePopupEnabled()
    {
        return RuntimeEnabledFeatures::PagePopupEnabled();
    }
    bool pageRevealEventEnabled()
    {
        return RuntimeEnabledFeatures::PageRevealEventEnabled();
    }
    bool pageSwapEventEnabled()
    {
        return RuntimeEnabledFeatures::PageSwapEventEnabled();
    }
    bool paintHighlightsForFirstLetterEnabled()
    {
        return RuntimeEnabledFeatures::PaintHighlightsForFirstLetterEnabled();
    }
    bool paintHoldingForIframesEnabled()
    {
        return RuntimeEnabledFeatures::PaintHoldingForIframesEnabled();
    }
    bool paintHoldingForLocalIframesEnabled()
    {
        return RuntimeEnabledFeatures::PaintHoldingForLocalIframesEnabled();
    }
    bool paintUnderInvalidationCheckingEnabled()
    {
        return RuntimeEnabledFeatures::PaintUnderInvalidationCheckingEnabled();
    }
    bool parakeetEnabled()
    {
        return RuntimeEnabledFeatures::ParakeetEnabledByRuntimeFlag();
    }
    bool partitionedPopinsEnabled()
    {
        return RuntimeEnabledFeatures::PartitionedPopinsEnabled();
    }
    bool partitionVisitedLinkDatabaseWithSelfLinksEnabled()
    {
        return RuntimeEnabledFeatures::PartitionVisitedLinkDatabaseWithSelfLinksEnabled();
    }
    bool passwordRevealEnabled()
    {
        return RuntimeEnabledFeatures::PasswordRevealEnabled();
    }
    bool paymentAppEnabled()
    {
        return RuntimeEnabledFeatures::PaymentAppEnabled();
    }
    bool paymentInstrumentsEnabled()
    {
        return RuntimeEnabledFeatures::PaymentInstrumentsEnabled();
    }
    bool paymentLinkDetectionEnabled()
    {
        return RuntimeEnabledFeatures::PaymentLinkDetectionEnabled();
    }
    bool paymentMethodChangeEventEnabled()
    {
        return RuntimeEnabledFeatures::PaymentMethodChangeEventEnabled();
    }
    bool paymentRequestEnabled()
    {
        return RuntimeEnabledFeatures::PaymentRequestEnabled();
    }
    bool percentBasedScrollingEnabled()
    {
        return RuntimeEnabledFeatures::PercentBasedScrollingEnabled();
    }
    bool performanceManagerInstrumentationEnabled()
    {
        return RuntimeEnabledFeatures::PerformanceManagerInstrumentationEnabled();
    }
    bool performanceMarkFeatureUsageEnabled()
    {
        return RuntimeEnabledFeatures::PerformanceMarkFeatureUsageEnabled();
    }
    bool performanceNavigateSystemEntropyEnabled()
    {
        return RuntimeEnabledFeatures::PerformanceNavigateSystemEntropyEnabled();
    }
    bool performanceNavigationTimingConfidenceEnabled()
    {
        return RuntimeEnabledFeatures::PerformanceNavigationTimingConfidenceEnabled();
    }
    bool periodicBackgroundSyncEnabled()
    {
        return RuntimeEnabledFeatures::PeriodicBackgroundSyncEnabled();
    }
    bool perMethodCanMakePaymentQuotaEnabled()
    {
        return RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag();
    }
    bool permissionElementEnabled()
    {
        return RuntimeEnabledFeatures::PermissionElementEnabledByRuntimeFlag();
    }
    bool permissionsEnabled()
    {
        return RuntimeEnabledFeatures::PermissionsEnabled();
    }
    bool permissionsRequestRevokeEnabled()
    {
        return RuntimeEnabledFeatures::PermissionsRequestRevokeEnabled();
    }
    bool pNaClEnabled()
    {
        return RuntimeEnabledFeatures::PNaClEnabledByRuntimeFlag();
    }
    bool pointerEventDeviceIdEnabled()
    {
        return RuntimeEnabledFeatures::PointerEventDeviceIdEnabled();
    }
    bool pointerEventTargetsInEventListsEnabled()
    {
        return RuntimeEnabledFeatures::PointerEventTargetsInEventListsEnabled();
    }
    bool popoverAnchorRelationshipsEnabled()
    {
        return RuntimeEnabledFeatures::PopoverAnchorRelationshipsEnabled();
    }
    bool popoverDialogNewFocusBehaviorEnabled()
    {
        return RuntimeEnabledFeatures::PopoverDialogNewFocusBehaviorEnabled();
    }
    bool positionOutsideTabSpanCheckSiblingNodeEnabled()
    {
        return RuntimeEnabledFeatures::PositionOutsideTabSpanCheckSiblingNodeEnabled();
    }
    bool preciseMemoryInfoEnabled()
    {
        return RuntimeEnabledFeatures::PreciseMemoryInfoEnabled();
    }
    bool preferDefaultScrollbarStylesEnabled()
    {
        return RuntimeEnabledFeatures::PreferDefaultScrollbarStylesEnabled();
    }
    bool preferNonCompositedScrollingEnabled()
    {
        return RuntimeEnabledFeatures::PreferNonCompositedScrollingEnabled();
    }
    bool prefersReducedDataEnabled()
    {
        return RuntimeEnabledFeatures::PrefersReducedDataEnabled();
    }
    bool prefixedVideoFullscreenEnabled()
    {
        return RuntimeEnabledFeatures::PrefixedVideoFullscreenEnabledByRuntimeFlag();
    }
    bool prerender2Enabled()
    {
        return RuntimeEnabledFeatures::Prerender2Enabled();
    }
    bool presentationEnabled()
    {
        return RuntimeEnabledFeatures::PresentationEnabled();
    }
    bool preserveFollowingBlockStylesDuringBlockMergeEnabled()
    {
        return RuntimeEnabledFeatures::PreserveFollowingBlockStylesDuringBlockMergeEnabled();
    }
    bool preventUndoIfNotEditableEnabled()
    {
        return RuntimeEnabledFeatures::PreventUndoIfNotEditableEnabled();
    }
    bool privateAggregationApiFilteringIdsEnabled()
    {
        return RuntimeEnabledFeatures::PrivateAggregationApiFilteringIdsEnabled();
    }
    bool privateAggregationAuctionReportBuyerDebugModeConfigEnabled()
    {
        return RuntimeEnabledFeatures::PrivateAggregationAuctionReportBuyerDebugModeConfigEnabled();
    }
    bool privateNetworkAccessNonSecureContextsAllowedEnabled()
    {
        return RuntimeEnabledFeatures::PrivateNetworkAccessNonSecureContextsAllowedEnabledByRuntimeFlag();
    }
    bool privateNetworkAccessNullIpAddressEnabled()
    {
        return RuntimeEnabledFeatures::PrivateNetworkAccessNullIpAddressEnabled();
    }
    bool privateNetworkAccessPermissionPromptEnabled()
    {
        return RuntimeEnabledFeatures::PrivateNetworkAccessPermissionPromptEnabledByRuntimeFlag();
    }
    bool privateStateTokensEnabled()
    {
        return RuntimeEnabledFeatures::PrivateStateTokensEnabledByRuntimeFlag();
    }
    bool privateStateTokensAlwaysAllowIssuanceEnabled()
    {
        return RuntimeEnabledFeatures::PrivateStateTokensAlwaysAllowIssuanceEnabled();
    }
    bool protectedOriginTrialsSampleAPIEnabled()
    {
        return RuntimeEnabledFeatures::ProtectedOriginTrialsSampleAPIEnabledByRuntimeFlag();
    }
    bool protectedOriginTrialsSampleAPIDependentEnabled()
    {
        return RuntimeEnabledFeatures::ProtectedOriginTrialsSampleAPIDependentEnabledByRuntimeFlag();
    }
    bool protectedOriginTrialsSampleAPIImpliedEnabled()
    {
        return RuntimeEnabledFeatures::ProtectedOriginTrialsSampleAPIImpliedEnabledByRuntimeFlag();
    }
    bool pseudoElementsCorrectInGetComputedStyleEnabled()
    {
        return RuntimeEnabledFeatures::PseudoElementsCorrectInGetComputedStyleEnabled();
    }
    bool pseudoElementsFocusableEnabled()
    {
        return RuntimeEnabledFeatures::PseudoElementsFocusableEnabled();
    }
    bool pushMessageDataBytesEnabled()
    {
        return RuntimeEnabledFeatures::PushMessageDataBytesEnabled();
    }
    bool pushMessagingEnabled()
    {
        return RuntimeEnabledFeatures::PushMessagingEnabled();
    }
    bool pushMessagingSubscriptionChangeEnabled()
    {
        return RuntimeEnabledFeatures::PushMessagingSubscriptionChangeEnabled();
    }
    bool quickIntensiveWakeUpThrottlingAfterLoadingEnabled()
    {
        return RuntimeEnabledFeatures::QuickIntensiveWakeUpThrottlingAfterLoadingEnabled();
    }
    bool rasterInducingScrollEnabled()
    {
        return RuntimeEnabledFeatures::RasterInducingScrollEnabled();
    }
    bool readableStreamAsyncIterableEnabled()
    {
        return RuntimeEnabledFeatures::ReadableStreamAsyncIterableEnabled();
    }
    bool reduceAcceptLanguageEnabled()
    {
        return RuntimeEnabledFeatures::ReduceAcceptLanguageEnabledByRuntimeFlag();
    }
    bool reduceCookieIPCsEnabled()
    {
        return RuntimeEnabledFeatures::ReduceCookieIPCsEnabled();
    }
    bool reduceUserAgentAndroidVersionDeviceModelEnabled()
    {
        return RuntimeEnabledFeatures::ReduceUserAgentAndroidVersionDeviceModelEnabled();
    }
    bool reduceUserAgentMinorVersionEnabled()
    {
        return RuntimeEnabledFeatures::ReduceUserAgentMinorVersionEnabled();
    }
    bool reduceUserAgentPlatformOsCpuEnabled()
    {
        return RuntimeEnabledFeatures::ReduceUserAgentPlatformOsCpuEnabled();
    }
    bool regionCaptureEnabled()
    {
        return RuntimeEnabledFeatures::RegionCaptureEnabled();
    }
    bool relOpenerBcgDependencyHintEnabled()
    {
        return RuntimeEnabledFeatures::RelOpenerBcgDependencyHintEnabled();
    }
    bool remotePlaybackEnabled()
    {
        return RuntimeEnabledFeatures::RemotePlaybackEnabled();
    }
    bool remotePlaybackBackendEnabled()
    {
        return RuntimeEnabledFeatures::RemotePlaybackBackendEnabled();
    }
    bool removeCollapsedPlaceholderEnabled()
    {
        return RuntimeEnabledFeatures::RemoveCollapsedPlaceholderEnabled();
    }
    bool removeDanglingMarkupInTargetEnabled()
    {
        return RuntimeEnabledFeatures::RemoveDanglingMarkupInTargetEnabled();
    }
    bool removeDataUrlInSvgUseEnabled()
    {
        return RuntimeEnabledFeatures::RemoveDataUrlInSvgUseEnabled();
    }
    bool removeNodeHavingChildrenIfFullySelectedEnabled()
    {
        return RuntimeEnabledFeatures::RemoveNodeHavingChildrenIfFullySelectedEnabled();
    }
    bool removeVisibleSelectionInDOMSelectionEnabled()
    {
        return RuntimeEnabledFeatures::RemoveVisibleSelectionInDOMSelectionEnabled();
    }
    bool renderBlockingInlineModuleScriptEnabled()
    {
        return RuntimeEnabledFeatures::RenderBlockingInlineModuleScriptEnabled();
    }
    bool renderBlockingStatusEnabled()
    {
        return RuntimeEnabledFeatures::RenderBlockingStatusEnabled();
    }
    bool renderPriorityAttributeEnabled()
    {
        return RuntimeEnabledFeatures::RenderPriorityAttributeEnabled();
    }
    bool reportEventTimingAtVisibilityChangeEnabled()
    {
        return RuntimeEnabledFeatures::ReportEventTimingAtVisibilityChangeEnabled();
    }
    bool reportVisibleLineBoundsEnabled()
    {
        return RuntimeEnabledFeatures::ReportVisibleLineBoundsEnabled();
    }
    bool resetInputTypeToNoneBeforeCharacterInputEnabled()
    {
        return RuntimeEnabledFeatures::ResetInputTypeToNoneBeforeCharacterInputEnabled();
    }
    bool resourceTimingContentTypeEnabled()
    {
        return RuntimeEnabledFeatures::ResourceTimingContentTypeEnabled();
    }
    bool resourceTimingFinalResponseHeadersStartEnabled()
    {
        return RuntimeEnabledFeatures::ResourceTimingFinalResponseHeadersStartEnabled();
    }
    bool resourceTimingUseCORSForBodySizesEnabled()
    {
        return RuntimeEnabledFeatures::ResourceTimingUseCORSForBodySizesEnabled();
    }
    bool restrictGamepadAccessEnabled()
    {
        return RuntimeEnabledFeatures::RestrictGamepadAccessEnabled();
    }
    bool reuseShapeResultsByFontsEnabled()
    {
        return RuntimeEnabledFeatures::ReuseShapeResultsByFontsEnabled();
    }
    bool rewindFloatsEnabled()
    {
        return RuntimeEnabledFeatures::RewindFloatsEnabled();
    }
    bool rootElementWithPlaceHolderAfterDeletingSelectionEnabled()
    {
        return RuntimeEnabledFeatures::RootElementWithPlaceHolderAfterDeletingSelectionEnabled();
    }
    bool rtcAudioJitterBufferMaxPacketsEnabled()
    {
        return RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag();
    }
    bool rtcDataChannelPriorityEnabled()
    {
        return RuntimeEnabledFeatures::RTCDataChannelPriorityEnabled();
    }
    bool rtcEncodedAudioFrameAbsCaptureTimeEnabled()
    {
        return RuntimeEnabledFeatures::RTCEncodedAudioFrameAbsCaptureTimeEnabled();
    }
    bool rtcEncodedFrameSetMetadataEnabled()
    {
        return RuntimeEnabledFeatures::RTCEncodedFrameSetMetadataEnabledByRuntimeFlag();
    }
    bool rtcEncodedVideoFrameAdditionalMetadataEnabled()
    {
        return RuntimeEnabledFeatures::RTCEncodedVideoFrameAdditionalMetadataEnabled();
    }
    bool rtcJitterBufferTargetEnabled()
    {
        return RuntimeEnabledFeatures::RTCJitterBufferTargetEnabled();
    }
    bool rtcLegacyCallbackBasedGetStatsEnabled()
    {
        return RuntimeEnabledFeatures::RTCLegacyCallbackBasedGetStatsEnabledByRuntimeFlag();
    }
    bool rtcRtpEncodingParametersCodecEnabled()
    {
        return RuntimeEnabledFeatures::RTCRtpEncodingParametersCodecEnabled();
    }
    bool rtcRtpScaleResolutionDownToEnabled()
    {
        return RuntimeEnabledFeatures::RTCRtpScaleResolutionDownToEnabled();
    }
    bool rtcRtpScriptTransformEnabled()
    {
        return RuntimeEnabledFeatures::RTCRtpScriptTransformEnabled();
    }
    bool rtcRtpTransportEnabled()
    {
        return RuntimeEnabledFeatures::RTCRtpTransportEnabled();
    }
    bool rtcStatsRelativePacketArrivalDelayEnabled()
    {
        return RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag();
    }
    bool rtcSvcScalabilityModeEnabled()
    {
        return RuntimeEnabledFeatures::RTCSvcScalabilityModeEnabled();
    }
    bool rubyShortHeuristicsEnabled()
    {
        return RuntimeEnabledFeatures::RubyShortHeuristicsEnabled();
    }
    bool sanitizerAPIEnabled()
    {
        return RuntimeEnabledFeatures::SanitizerAPIEnabled();
    }
    bool schedulerYieldEnabled()
    {
        return RuntimeEnabledFeatures::SchedulerYieldEnabled();
    }
    bool scheduleSelectionChangeOnBackspaceEnabled()
    {
        return RuntimeEnabledFeatures::ScheduleSelectionChangeOnBackspaceEnabled();
    }
    bool scopedCustomElementRegistryEnabled()
    {
        return RuntimeEnabledFeatures::ScopedCustomElementRegistryEnabled();
    }
    bool scriptedSpeechRecognitionEnabled()
    {
        return RuntimeEnabledFeatures::ScriptedSpeechRecognitionEnabled();
    }
    bool scriptedSpeechSynthesisEnabled()
    {
        return RuntimeEnabledFeatures::ScriptedSpeechSynthesisEnabled();
    }
    bool scrollbarColorEnabled()
    {
        return RuntimeEnabledFeatures::ScrollbarColorEnabled();
    }
    bool scrollbarWidthEnabled()
    {
        return RuntimeEnabledFeatures::ScrollbarWidthEnabled();
    }
    bool scrollEndEventsEnabled()
    {
        return RuntimeEnabledFeatures::ScrollEndEventsEnabled();
    }
    bool scrollIntoViewRootFrameViewportBugFixEnabled()
    {
        return RuntimeEnabledFeatures::ScrollIntoViewRootFrameViewportBugFixEnabled();
    }
    bool scrollTimelineEnabled()
    {
        return RuntimeEnabledFeatures::ScrollTimelineEnabled();
    }
    bool scrollTimelineCurrentTimeEnabled()
    {
        return RuntimeEnabledFeatures::ScrollTimelineCurrentTimeEnabled();
    }
    bool scrollTopLeftInteropEnabled()
    {
        return RuntimeEnabledFeatures::ScrollTopLeftInteropEnabled();
    }
    bool searchTextHighlightPseudoEnabled()
    {
        return RuntimeEnabledFeatures::SearchTextHighlightPseudoEnabled();
    }
    bool securePaymentConfirmationEnabled()
    {
        return RuntimeEnabledFeatures::SecurePaymentConfirmationEnabled();
    }
    bool securePaymentConfirmationDebugEnabled()
    {
        return RuntimeEnabledFeatures::SecurePaymentConfirmationDebugEnabled();
    }
    bool securePaymentConfirmationNetworkAndIssuerIconsEnabled()
    {
        return RuntimeEnabledFeatures::SecurePaymentConfirmationNetworkAndIssuerIconsEnabled();
    }
    bool securePaymentConfirmationOptOutEnabled()
    {
        return RuntimeEnabledFeatures::SecurePaymentConfirmationOptOutEnabledByRuntimeFlag();
    }
    bool selectAudioOutputEnabled()
    {
        return RuntimeEnabledFeatures::SelectAudioOutputEnabled();
    }
    bool selectedcontentelementAttributeEnabled()
    {
        return RuntimeEnabledFeatures::SelectedcontentelementAttributeEnabled();
    }
    bool selectionAcrossShadowDOMEnabled()
    {
        return RuntimeEnabledFeatures::SelectionAcrossShadowDOMEnabled();
    }
    bool selectionIsCollapsedShadowDOMSupportEnabled()
    {
        return RuntimeEnabledFeatures::SelectionIsCollapsedShadowDOMSupportEnabled();
    }
    bool selectionOnShadowDOMWithDelegatesFocusEnabled()
    {
        return RuntimeEnabledFeatures::SelectionOnShadowDOMWithDelegatesFocusEnabled();
    }
    bool selectOptionAccessibilityTargetSizeEnabled()
    {
        return RuntimeEnabledFeatures::SelectOptionAccessibilityTargetSizeEnabled();
    }
    bool selectParserRelaxationEnabled()
    {
        return RuntimeEnabledFeatures::SelectParserRelaxationEnabled();
    }
    bool selectPopupLessUpdatesEnabled()
    {
        return RuntimeEnabledFeatures::SelectPopupLessUpdatesEnabled();
    }
    bool sendBeaconThrowForBlobWithNonSimpleTypeEnabled()
    {
        return RuntimeEnabledFeatures::SendBeaconThrowForBlobWithNonSimpleTypeEnabled();
    }
    bool sensorExtraClassesEnabled()
    {
        return RuntimeEnabledFeatures::SensorExtraClassesEnabled();
    }
    bool serialEnabled()
    {
        return RuntimeEnabledFeatures::SerialEnabled();
    }
    bool serializeViewTransitionStateInSPAEnabled()
    {
        return RuntimeEnabledFeatures::SerializeViewTransitionStateInSPAEnabled();
    }
    bool serialPortConnectedEnabled()
    {
        return RuntimeEnabledFeatures::SerialPortConnectedEnabled();
    }
    bool serviceWorkerClientLifecycleStateEnabled()
    {
        return RuntimeEnabledFeatures::ServiceWorkerClientLifecycleStateEnabled();
    }
    bool serviceWorkerStaticRouterEnabled()
    {
        return RuntimeEnabledFeatures::ServiceWorkerStaticRouterEnabledByRuntimeFlag();
    }
    bool serviceWorkerStaticRouterTimingInfoEnabled()
    {
        return RuntimeEnabledFeatures::ServiceWorkerStaticRouterTimingInfoEnabledByRuntimeFlag();
    }
    bool setSequentialFocusStartingPointEnabled()
    {
        return RuntimeEnabledFeatures::SetSequentialFocusStartingPointEnabled();
    }
    bool shadowRootReferenceTargetEnabled()
    {
        return RuntimeEnabledFeatures::ShadowRootReferenceTargetEnabled();
    }
    bool shapeOutsideWritingModeFixEnabled()
    {
        return RuntimeEnabledFeatures::ShapeOutsideWritingModeFixEnabled();
    }
    bool shapeResultCachedPreviousSafeToBreakOffsetEnabled()
    {
        return RuntimeEnabledFeatures::ShapeResultCachedPreviousSafeToBreakOffsetEnabled();
    }
    bool sharedArrayBufferEnabled()
    {
        return RuntimeEnabledFeatures::SharedArrayBufferEnabled();
    }
    bool sharedArrayBufferOnDesktopEnabled()
    {
        return RuntimeEnabledFeatures::SharedArrayBufferOnDesktopEnabled();
    }
    bool sharedArrayBufferUnrestrictedAccessAllowedEnabled()
    {
        return RuntimeEnabledFeatures::SharedArrayBufferUnrestrictedAccessAllowedEnabled();
    }
    bool sharedAutofillEnabled()
    {
        return RuntimeEnabledFeatures::SharedAutofillEnabled();
    }
    bool sharedStorageAPIEnabled()
    {
        return RuntimeEnabledFeatures::SharedStorageAPIEnabled();
    }
    bool sharedStorageAPIM118Enabled()
    {
        return RuntimeEnabledFeatures::SharedStorageAPIM118Enabled();
    }
    bool sharedStorageAPIM125Enabled()
    {
        return RuntimeEnabledFeatures::SharedStorageAPIM125Enabled();
    }
    bool sharedStorageWebLocksEnabled()
    {
        return RuntimeEnabledFeatures::SharedStorageWebLocksEnabled();
    }
    bool sharedWorkerEnabled()
    {
        return RuntimeEnabledFeatures::SharedWorkerEnabled();
    }
    bool sidewaysWritingModesEnabled()
    {
        return RuntimeEnabledFeatures::SidewaysWritingModesEnabled();
    }
    bool signatureBasedIntegrityEnabled()
    {
        return RuntimeEnabledFeatures::SignatureBasedIntegrityEnabledByRuntimeFlag();
    }
    bool siteInitiatedMirroringEnabled()
    {
        return RuntimeEnabledFeatures::SiteInitiatedMirroringEnabled();
    }
    bool skipAdEnabled()
    {
        return RuntimeEnabledFeatures::SkipAdEnabled();
    }
    bool skipPreloadScanningEnabled()
    {
        return RuntimeEnabledFeatures::SkipPreloadScanningEnabledByRuntimeFlag();
    }
    bool skipTemporaryDocumentFragmentEnabled()
    {
        return RuntimeEnabledFeatures::SkipTemporaryDocumentFragmentEnabled();
    }
    bool skipTouchEventFilterEnabled()
    {
        return RuntimeEnabledFeatures::SkipTouchEventFilterEnabled();
    }
    bool smartCardEnabled()
    {
        return RuntimeEnabledFeatures::SmartCardEnabled();
    }
    bool smartZoomEnabled()
    {
        return RuntimeEnabledFeatures::SmartZoomEnabled();
    }
    bool smilAutoSuspendOnLagEnabled()
    {
        return RuntimeEnabledFeatures::SmilAutoSuspendOnLagEnabled();
    }
    bool softNavigationDetectionEnabled()
    {
        return RuntimeEnabledFeatures::SoftNavigationDetectionEnabled();
    }
    bool softNavigationHeuristicsEnabled()
    {
        return RuntimeEnabledFeatures::SoftNavigationHeuristicsEnabledByRuntimeFlag();
    }
    bool softNavigationHeuristicsExposeFPAndFCPEnabled()
    {
        return RuntimeEnabledFeatures::SoftNavigationHeuristicsExposeFPAndFCPEnabled();
    }
    bool speakerSelectionEnabled()
    {
        return RuntimeEnabledFeatures::SpeakerSelectionEnabled();
    }
    bool speculationRulesPointerDownHeuristicsEnabled()
    {
        return RuntimeEnabledFeatures::SpeculationRulesPointerDownHeuristicsEnabled();
    }
    bool speculationRulesPointerHoverHeuristicsEnabled()
    {
        return RuntimeEnabledFeatures::SpeculationRulesPointerHoverHeuristicsEnabled();
    }
    bool speculationRulesPrefetchFutureEnabled()
    {
        return RuntimeEnabledFeatures::SpeculationRulesPrefetchFutureEnabledByRuntimeFlag();
    }
    bool speculationRulesPrefetchWithSubresourcesEnabled()
    {
        return RuntimeEnabledFeatures::SpeculationRulesPrefetchWithSubresourcesEnabled();
    }
    bool srcsetMaxDensityEnabled()
    {
        return RuntimeEnabledFeatures::SrcsetMaxDensityEnabled();
    }
    bool stableBlinkFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::StableBlinkFeaturesEnabled();
    }
    bool standardizedBrowserZoomEnabled()
    {
        return RuntimeEnabledFeatures::StandardizedBrowserZoomEnabled();
    }
    bool standardizedBrowserZoomOptOutEnabled()
    {
        return RuntimeEnabledFeatures::StandardizedBrowserZoomOptOutEnabledByRuntimeFlag();
    }
    bool staticAnimationOptimizationEnabled()
    {
        return RuntimeEnabledFeatures::StaticAnimationOptimizationEnabled();
    }
    bool storageAccessHeaderEnabled()
    {
        return RuntimeEnabledFeatures::StorageAccessHeaderEnabledByRuntimeFlag();
    }
    bool storageBucketsEnabled()
    {
        return RuntimeEnabledFeatures::StorageBucketsEnabled();
    }
    bool storageBucketsDurabilityEnabled()
    {
        return RuntimeEnabledFeatures::StorageBucketsDurabilityEnabled();
    }
    bool storageBucketsLocksEnabled()
    {
        return RuntimeEnabledFeatures::StorageBucketsLocksEnabled();
    }
    bool stricterCellWidthContentSizeQuirkEnabled()
    {
        return RuntimeEnabledFeatures::StricterCellWidthContentSizeQuirkEnabled();
    }
    bool strictMimeTypesForWorkersEnabled()
    {
        return RuntimeEnabledFeatures::StrictMimeTypesForWorkersEnabled();
    }
    bool stylusHandwritingEnabled()
    {
        return RuntimeEnabledFeatures::StylusHandwritingEnabled();
    }
    bool svgContextPaintEnabled()
    {
        return RuntimeEnabledFeatures::SvgContextPaintEnabled();
    }
    bool svgCrossOriginAttributeEnabled()
    {
        return RuntimeEnabledFeatures::SvgCrossOriginAttributeEnabled();
    }
    bool svgEagerPresAttrStyleUpdateEnabled()
    {
        return RuntimeEnabledFeatures::SvgEagerPresAttrStyleUpdateEnabled();
    }
    bool svgExternalResourcesEnabled()
    {
        return RuntimeEnabledFeatures::SvgExternalResourcesEnabled();
    }
    bool svgFilterUserSpaceViewportForNonSvgEnabled()
    {
        return RuntimeEnabledFeatures::SvgFilterUserSpaceViewportForNonSvgEnabled();
    }
    bool svgGradientColorInterpolationLinearRgbSupportEnabled()
    {
        return RuntimeEnabledFeatures::SvgGradientColorInterpolationLinearRgbSupportEnabled();
    }
    bool svgInlineRootPixelSnappingScaleAdjustmentEnabled()
    {
        return RuntimeEnabledFeatures::SvgInlineRootPixelSnappingScaleAdjustmentEnabled();
    }
    bool svgNoPixelSnappingScaleAdjustmentEnabled()
    {
        return RuntimeEnabledFeatures::SvgNoPixelSnappingScaleAdjustmentEnabled();
    }
    bool svgTransformOptimizationEnabled()
    {
        return RuntimeEnabledFeatures::SvgTransformOptimizationEnabled();
    }
    bool synthesizedKeyboardEventsForAccessibilityActionsEnabled()
    {
        return RuntimeEnabledFeatures::SynthesizedKeyboardEventsForAccessibilityActionsEnabled();
    }
    bool systemFallbackEmojiVSSupportEnabled()
    {
        return RuntimeEnabledFeatures::SystemFallbackEmojiVSSupportEnabled();
    }
    bool systemWakeLockEnabled()
    {
        return RuntimeEnabledFeatures::SystemWakeLockEnabled();
    }
    bool testBlinkFeatureDefaultEnabled()
    {
        return RuntimeEnabledFeatures::TestBlinkFeatureDefaultEnabled();
    }
    bool testFeatureEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureEnabled();
    }
    bool testFeatureDependentEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureDependentEnabled();
    }
    bool testFeatureImpliedEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureImpliedEnabled();
    }
    bool testFeatureProtectedEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureProtectedEnabled();
    }
    bool testFeatureProtectedDependentEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureProtectedDependentEnabled();
    }
    bool testFeatureProtectedImpliedEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureProtectedImpliedEnabled();
    }
    bool testFeatureStableEnabled()
    {
        return RuntimeEnabledFeatures::TestFeatureStableEnabled();
    }
    bool textDetectorEnabled()
    {
        return RuntimeEnabledFeatures::TextDetectorEnabled();
    }
    bool textDiffSplitFixEnabled()
    {
        return RuntimeEnabledFeatures::TextDiffSplitFixEnabled();
    }
    bool textFragmentAPIEnabled()
    {
        return RuntimeEnabledFeatures::TextFragmentAPIEnabled();
    }
    bool textFragmentIdentifiersEnabled()
    {
        return RuntimeEnabledFeatures::TextFragmentIdentifiersEnabledByRuntimeFlag();
    }
    bool textFragmentTapOpensContextMenuEnabled()
    {
        return RuntimeEnabledFeatures::TextFragmentTapOpensContextMenuEnabled();
    }
    bool textInputNotAlwaysDirAutoEnabled()
    {
        return RuntimeEnabledFeatures::TextInputNotAlwaysDirAutoEnabled();
    }
    bool textMetricsBaselinesEnabled()
    {
        return RuntimeEnabledFeatures::TextMetricsBaselinesEnabled();
    }
    bool textSegmentBoundaryForElementWithFloatStyleEnabled()
    {
        return RuntimeEnabledFeatures::TextSegmentBoundaryForElementWithFloatStyleEnabled();
    }
    bool textSizeAdjustImprovementsEnabled()
    {
        return RuntimeEnabledFeatures::TextSizeAdjustImprovementsEnabled();
    }
    bool textTransformAndSecurityFixEnabled()
    {
        return RuntimeEnabledFeatures::TextTransformAndSecurityFixEnabled();
    }
    bool timelineScopeEnabled()
    {
        return RuntimeEnabledFeatures::TimelineScopeEnabled();
    }
    bool timerThrottlingForBackgroundTabsEnabled()
    {
        return RuntimeEnabledFeatures::TimerThrottlingForBackgroundTabsEnabled();
    }
    bool timestampBasedCLSTrackingEnabled()
    {
        return RuntimeEnabledFeatures::TimestampBasedCLSTrackingEnabled();
    }
    bool timeZoneChangeEventEnabled()
    {
        return RuntimeEnabledFeatures::TimeZoneChangeEventEnabled();
    }
    bool topicsAPIEnabled()
    {
        return RuntimeEnabledFeatures::TopicsAPIEnabled();
    }
    bool topicsDocumentAPIEnabled()
    {
        return RuntimeEnabledFeatures::TopicsDocumentAPIEnabled();
    }
    bool topLayerInactiveDocumentExceptionsEnabled()
    {
        return RuntimeEnabledFeatures::TopLayerInactiveDocumentExceptionsEnabled();
    }
    bool topLevelTpcdEnabled()
    {
        return RuntimeEnabledFeatures::TopLevelTpcdEnabledByRuntimeFlag();
    }
    bool touchDragAndContextMenuEnabled()
    {
        return RuntimeEnabledFeatures::TouchDragAndContextMenuEnabled();
    }
    bool touchDragOnShortPressEnabled()
    {
        return RuntimeEnabledFeatures::TouchDragOnShortPressEnabled();
    }
    bool touchEventFeatureDetectionEnabled()
    {
        return RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabledByRuntimeFlag();
    }
    bool touchTextEditingRedesignEnabled()
    {
        return RuntimeEnabledFeatures::TouchTextEditingRedesignEnabled();
    }
    bool tpcdEnabled()
    {
        return RuntimeEnabledFeatures::TpcdEnabledByRuntimeFlag();
    }
    bool transferableRTCDataChannelEnabled()
    {
        return RuntimeEnabledFeatures::TransferableRTCDataChannelEnabled();
    }
    bool translateServiceEnabled()
    {
        return RuntimeEnabledFeatures::TranslateServiceEnabled();
    }
    bool translationAPIEnabled()
    {
        return RuntimeEnabledFeatures::TranslationAPIEnabledByRuntimeFlag();
    }
    bool translationAPIEntryPointEnabled()
    {
        return RuntimeEnabledFeatures::TranslationAPIEntryPointEnabledByRuntimeFlag();
    }
    bool trustedTypeBeforePolicyCreationEventEnabled()
    {
        return RuntimeEnabledFeatures::TrustedTypeBeforePolicyCreationEventEnabled();
    }
    bool trustedTypesFromLiteralEnabled()
    {
        return RuntimeEnabledFeatures::TrustedTypesFromLiteralEnabled();
    }
    bool trustedTypesUseCodeLikeEnabled()
    {
        return RuntimeEnabledFeatures::TrustedTypesUseCodeLikeEnabled();
    }
    bool unclosedFormControlIsInvalidEnabled()
    {
        return RuntimeEnabledFeatures::UnclosedFormControlIsInvalidEnabled();
    }
    bool unexposedTaskIdsEnabled()
    {
        return RuntimeEnabledFeatures::UnexposedTaskIdsEnabled();
    }
    bool unownedAnimationsSkipCSSEventsEnabled()
    {
        return RuntimeEnabledFeatures::UnownedAnimationsSkipCSSEventsEnabled();
    }
    bool unrestrictedMeasureUserAgentSpecificMemoryEnabled()
    {
        return RuntimeEnabledFeatures::UnrestrictedMeasureUserAgentSpecificMemoryEnabled();
    }
    bool unrestrictedSharedArrayBufferEnabled()
    {
        return RuntimeEnabledFeatures::UnrestrictedSharedArrayBufferEnabledByRuntimeFlag();
    }
    bool unrestrictedUsbEnabled()
    {
        return RuntimeEnabledFeatures::UnrestrictedUsbEnabled();
    }
    bool urlPatternCompareComponentEnabled()
    {
        return RuntimeEnabledFeatures::URLPatternCompareComponentEnabled();
    }
    bool urlSearchParamsHasAndDeleteMultipleArgsEnabled()
    {
        return RuntimeEnabledFeatures::URLSearchParamsHasAndDeleteMultipleArgsEnabled();
    }
    bool useBeginFramePresentationFeedbackEnabled()
    {
        return RuntimeEnabledFeatures::UseBeginFramePresentationFeedbackEnabled();
    }
    bool useLowQualityInterpolationEnabled()
    {
        return RuntimeEnabledFeatures::UseLowQualityInterpolationEnabled();
    }
    bool userActivationSameOriginVisibilityEnabled()
    {
        return RuntimeEnabledFeatures::UserActivationSameOriginVisibilityEnabled();
    }
    bool useSelectionFocusNodeForCaretNavigationEnabled()
    {
        return RuntimeEnabledFeatures::UseSelectionFocusNodeForCaretNavigationEnabled();
    }
    bool useUndoStepElementDispatchBeforeInputEnabled()
    {
        return RuntimeEnabledFeatures::UseUndoStepElementDispatchBeforeInputEnabled();
    }
    bool v8IdleTasksEnabled()
    {
        return RuntimeEnabledFeatures::V8IdleTasksEnabled();
    }
    bool videoAutoFullscreenEnabled()
    {
        return RuntimeEnabledFeatures::VideoAutoFullscreenEnabled();
    }
    bool videoFrameMetadataBackgroundBlurEnabled()
    {
        return RuntimeEnabledFeatures::VideoFrameMetadataBackgroundBlurEnabled();
    }
    bool videoFullscreenOrientationLockEnabled()
    {
        return RuntimeEnabledFeatures::VideoFullscreenOrientationLockEnabled();
    }
    bool videoRotateToFullscreenEnabled()
    {
        return RuntimeEnabledFeatures::VideoRotateToFullscreenEnabled();
    }
    bool videoTrackGeneratorEnabled()
    {
        return RuntimeEnabledFeatures::VideoTrackGeneratorEnabled();
    }
    bool videoTrackGeneratorInWindowEnabled()
    {
        return RuntimeEnabledFeatures::VideoTrackGeneratorInWindowEnabled();
    }
    bool videoTrackGeneratorInWorkerEnabled()
    {
        return RuntimeEnabledFeatures::VideoTrackGeneratorInWorkerEnabled();
    }
    bool viewportChangesUpdateTextAutosizingEnabled()
    {
        return RuntimeEnabledFeatures::ViewportChangesUpdateTextAutosizingEnabled();
    }
    bool viewportHeightClientHintHeaderEnabled()
    {
        return RuntimeEnabledFeatures::ViewportHeightClientHintHeaderEnabled();
    }
    bool viewportSegmentsEnabled()
    {
        return RuntimeEnabledFeatures::ViewportSegmentsEnabledByRuntimeFlag();
    }
    bool viewTransitionDisableSnapBrowserControlsOnHiddenEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionDisableSnapBrowserControlsOnHiddenEnabled();
    }
    bool viewTransitionLayeredCaptureEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionLayeredCaptureEnabled();
    }
    bool viewTransitionLongCallbackTimeoutForTestingEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionLongCallbackTimeoutForTestingEnabled();
    }
    bool viewTransitionOnNavigationEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionOnNavigationEnabled();
    }
    bool viewTransitionOnNavigationForIframesEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionOnNavigationForIframesEnabled();
    }
    bool viewTransitionOverflowRectFromSurfaceEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionOverflowRectFromSurfaceEnabled();
    }
    bool viewTransitionTreeScopedNamesEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionTreeScopedNamesEnabled();
    }
    bool viewTransitionTypesEnabled()
    {
        return RuntimeEnabledFeatures::ViewTransitionTypesEnabled();
    }
    bool visibilityCollapseColumnEnabled()
    {
        return RuntimeEnabledFeatures::VisibilityCollapseColumnEnabled();
    }
    bool visualViewportOnScrollEndEnabled()
    {
        return RuntimeEnabledFeatures::VisualViewportOnScrollEndEnabled();
    }
    bool wakeLockEnabled()
    {
        return RuntimeEnabledFeatures::WakeLockEnabled();
    }
    bool warnOnContentVisibilityRenderAccessEnabled()
    {
        return RuntimeEnabledFeatures::WarnOnContentVisibilityRenderAccessEnabled();
    }
    bool webAnimationsSVGEnabled()
    {
        return RuntimeEnabledFeatures::WebAnimationsSVGEnabled();
    }
    bool webAppInstallationEnabled()
    {
        return RuntimeEnabledFeatures::WebAppInstallationEnabled();
    }
    bool webAppLaunchQueueEnabled()
    {
        return RuntimeEnabledFeatures::WebAppLaunchQueueEnabledByRuntimeFlag();
    }
    bool webAppScopeExtensionsEnabled()
    {
        return RuntimeEnabledFeatures::WebAppScopeExtensionsEnabledByRuntimeFlag();
    }
    bool webAppTabStripEnabled()
    {
        return RuntimeEnabledFeatures::WebAppTabStripEnabled();
    }
    bool webAppTabStripCustomizationsEnabled()
    {
        return RuntimeEnabledFeatures::WebAppTabStripCustomizationsEnabled();
    }
    bool webAppTranslationsEnabled()
    {
        return RuntimeEnabledFeatures::WebAppTranslationsEnabled();
    }
    bool webAppUrlHandlingEnabled()
    {
        return RuntimeEnabledFeatures::WebAppUrlHandlingEnabledByRuntimeFlag();
    }
    bool webAssemblyJSPromiseIntegrationEnabled()
    {
        return RuntimeEnabledFeatures::WebAssemblyJSPromiseIntegrationEnabledByRuntimeFlag();
    }
    bool webAssemblyJSStringBuiltinsEnabled()
    {
        return RuntimeEnabledFeatures::WebAssemblyJSStringBuiltinsEnabledByRuntimeFlag();
    }
    bool webAudioBypassOutputBufferingEnabled()
    {
        return RuntimeEnabledFeatures::WebAudioBypassOutputBufferingEnabled();
    }
    bool webAudioBypassOutputBufferingOptOutEnabled()
    {
        return RuntimeEnabledFeatures::WebAudioBypassOutputBufferingOptOutEnabled();
    }
    bool webAuthEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthEnabled();
    }
    bool webAuthAuthenticatorAttachmentEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthAuthenticatorAttachmentEnabled();
    }
    bool webAuthenticationAmbientEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationAmbientEnabled();
    }
    bool webAuthenticationAttestationFormatsEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationAttestationFormatsEnabledByRuntimeFlag();
    }
    bool webAuthenticationClientCapabilitiesEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationClientCapabilitiesEnabled();
    }
    bool webAuthenticationJSONSerializationEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationJSONSerializationEnabled();
    }
    bool webAuthenticationLargeBlobExtensionEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationLargeBlobExtensionEnabled();
    }
    bool webAuthenticationPRFEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationPRFEnabled();
    }
    bool webAuthenticationRemoteDesktopSupportEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationRemoteDesktopSupportEnabled();
    }
    bool webAuthenticationSupplementalPubKeysEnabled()
    {
        return RuntimeEnabledFeatures::WebAuthenticationSupplementalPubKeysEnabled();
    }
    bool webBluetoothEnabled()
    {
        return RuntimeEnabledFeatures::WebBluetoothEnabled();
    }
    bool webBluetoothGetDevicesEnabled()
    {
        return RuntimeEnabledFeatures::WebBluetoothGetDevicesEnabled();
    }
    bool webBluetoothScanningEnabled()
    {
        return RuntimeEnabledFeatures::WebBluetoothScanningEnabled();
    }
    bool webBluetoothWatchAdvertisementsEnabled()
    {
        return RuntimeEnabledFeatures::WebBluetoothWatchAdvertisementsEnabled();
    }
    bool webcodecsCopyToRGBEnabled()
    {
        return RuntimeEnabledFeatures::WebCodecsCopyToRGBEnabled();
    }
    bool webcodecsHBDFormatsEnabled()
    {
        return RuntimeEnabledFeatures::WebCodecsHBDFormatsEnabled();
    }
    bool webcodecsOrientationEnabled()
    {
        return RuntimeEnabledFeatures::WebCodecsOrientationEnabled();
    }
    bool webcodecsVideoEncoderBuffersEnabled()
    {
        return RuntimeEnabledFeatures::WebCodecsVideoEncoderBuffersEnabled();
    }
    bool webCryptoCurve25519Enabled()
    {
        return RuntimeEnabledFeatures::WebCryptoCurve25519Enabled();
    }
    bool webFontResizeLCPEnabled()
    {
        return RuntimeEnabledFeatures::WebFontResizeLCPEnabled();
    }
    bool webglDeveloperExtensionsEnabled()
    {
        return RuntimeEnabledFeatures::WebGLDeveloperExtensionsEnabled();
    }
    bool webglDraftExtensionsEnabled()
    {
        return RuntimeEnabledFeatures::WebGLDraftExtensionsEnabled();
    }
    bool webglDrawingBufferStorageEnabled()
    {
        return RuntimeEnabledFeatures::WebGLDrawingBufferStorageEnabled();
    }
    bool webglImageChromiumEnabled()
    {
        return RuntimeEnabledFeatures::WebGLImageChromiumEnabled();
    }
    bool webgpuCanvasContextGetConfigurationEnabled()
    {
        return RuntimeEnabledFeatures::WebGPUCanvasContextGetConfigurationEnabled();
    }
    bool webgpuDeveloperFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::WebGPUDeveloperFeaturesEnabled();
    }
    bool webgpuDeviceAdapterInfoEnabled()
    {
        return RuntimeEnabledFeatures::WebGPUDeviceAdapterInfoEnabled();
    }
    bool webgpuExperimentalFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::WebGPUExperimentalFeaturesEnabled();
    }
    bool webgpuHDREnabled()
    {
        return RuntimeEnabledFeatures::WebGPUHDREnabled();
    }
    bool webgpuSubgroupsFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::WebGPUSubgroupsFeaturesEnabledByRuntimeFlag();
    }
    bool webgpuTextureViewUsageEnabled()
    {
        return RuntimeEnabledFeatures::WebGPUTextureViewUsageEnabled();
    }
    bool webHIDEnabled()
    {
        return RuntimeEnabledFeatures::WebHIDEnabled();
    }
    bool webHIDOnDedicatedWorkersEnabled()
    {
        return RuntimeEnabledFeatures::WebHIDOnDedicatedWorkersEnabled();
    }
    bool webHIDOnServiceWorkersEnabled()
    {
        return RuntimeEnabledFeatures::WebHIDOnServiceWorkersEnabled();
    }
    bool webIdentityDigitalCredentialsEnabled()
    {
        return RuntimeEnabledFeatures::WebIdentityDigitalCredentialsEnabledByRuntimeFlag();
    }
    bool webIDLBigIntUsesToBigIntEnabled()
    {
        return RuntimeEnabledFeatures::WebIDLBigIntUsesToBigIntEnabled();
    }
    bool webNFCEnabled()
    {
        return RuntimeEnabledFeatures::WebNFCEnabled();
    }
    bool webOTPEnabled()
    {
        return RuntimeEnabledFeatures::WebOTPEnabled();
    }
    bool webOTPAssertionFeaturePolicyEnabled()
    {
        return RuntimeEnabledFeatures::WebOTPAssertionFeaturePolicyEnabled();
    }
    bool webPreferencesEnabled()
    {
        return RuntimeEnabledFeatures::WebPreferencesEnabled();
    }
    bool webPrintingEnabled()
    {
        return RuntimeEnabledFeatures::WebPrintingEnabled();
    }
    bool webShareEnabled()
    {
        return RuntimeEnabledFeatures::WebShareEnabled();
    }
    bool websocketStreamEnabled()
    {
        return RuntimeEnabledFeatures::WebSocketStreamEnabled();
    }
    bool webTransportCustomCertificatesEnabled()
    {
        return RuntimeEnabledFeatures::WebTransportCustomCertificatesEnabledByRuntimeFlag();
    }
    bool webTransportStatsEnabled()
    {
        return RuntimeEnabledFeatures::WebTransportStatsEnabled();
    }
    bool webUSBEnabled()
    {
        return RuntimeEnabledFeatures::WebUSBEnabled();
    }
    bool webUSBOnDedicatedWorkersEnabled()
    {
        return RuntimeEnabledFeatures::WebUSBOnDedicatedWorkersEnabled();
    }
    bool webUSBOnServiceWorkersEnabled()
    {
        return RuntimeEnabledFeatures::WebUSBOnServiceWorkersEnabled();
    }
    bool webViewXREquestedWithDeprecationEnabled()
    {
        return RuntimeEnabledFeatures::WebViewXRequestedWithDeprecationEnabledByRuntimeFlag();
    }
    bool webVTTRegionsEnabled()
    {
        return RuntimeEnabledFeatures::WebVTTRegionsEnabled();
    }
    bool webXREnabled()
    {
        return RuntimeEnabledFeatures::WebXREnabled();
    }
    bool webXREnabledFeaturesEnabled()
    {
        return RuntimeEnabledFeatures::WebXREnabledFeaturesEnabled();
    }
    bool webXRFrameRateEnabled()
    {
        return RuntimeEnabledFeatures::WebXRFrameRateEnabled();
    }
    bool webXRFrontFacingEnabled()
    {
        return RuntimeEnabledFeatures::WebXRFrontFacingEnabled();
    }
    bool webXRGPUBindingEnabled()
    {
        return RuntimeEnabledFeatures::WebXRGPUBindingEnabled();
    }
    bool webXRHandInputEnabled()
    {
        return RuntimeEnabledFeatures::WebXRHandInputEnabled();
    }
    bool webXRHitTestEntityTypesEnabled()
    {
        return RuntimeEnabledFeatures::WebXRHitTestEntityTypesEnabled();
    }
    bool webXRImageTrackingEnabled()
    {
        return RuntimeEnabledFeatures::WebXRImageTrackingEnabledByRuntimeFlag();
    }
    bool webXRLayersEnabled()
    {
        return RuntimeEnabledFeatures::WebXRLayersEnabled();
    }
    bool webXRLayersCommonEnabled()
    {
        return RuntimeEnabledFeatures::WebXRLayersCommonEnabled();
    }
    bool webXRPlaneDetectionEnabled()
    {
        return RuntimeEnabledFeatures::WebXRPlaneDetectionEnabledByRuntimeFlag();
    }
    bool webXRPoseMotionDataEnabled()
    {
        return RuntimeEnabledFeatures::WebXRPoseMotionDataEnabled();
    }
    bool webXRSpecParityEnabled()
    {
        return RuntimeEnabledFeatures::WebXRSpecParityEnabled();
    }
    bool windowDefaultStatusEnabled()
    {
        return RuntimeEnabledFeatures::WindowDefaultStatusEnabled();
    }
    bool xmlParserMergeAdjacentCDataSectionsEnabled()
    {
        return RuntimeEnabledFeatures::XMLParserMergeAdjacentCDataSectionsEnabled();
    }
    bool zeroCopyTabCaptureEnabled()
    {
        return RuntimeEnabledFeatures::ZeroCopyTabCaptureEnabled();
    }
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_RUNTIME_FLAGS_H_
