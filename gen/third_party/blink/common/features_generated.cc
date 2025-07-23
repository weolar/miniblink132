// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/features_generated.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/common/features_generated.h"

namespace blink {
namespace features {

BASE_FEATURE(kAccelerated2dCanvas, "Accelerated2dCanvas", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAcceleratedSmallCanvases, "AcceleratedSmallCanvases", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAccessibilityExposeDisplayNone, "AccessibilityExposeDisplayNone", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAccessibilityMinRoleTabbable, "AccessibilityMinRoleTabbable", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAccessibilityOSLevelBoldText, "AccessibilityOSLevelBoldText", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAccessibilityProhibitedNames, "AccessibilityProhibitedNames", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAccessibilitySerializationSizeMetrics, "AccessibilitySerializationSizeMetrics", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAddressSpace, "AddressSpace", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAdInterestGroupAPI, "AdInterestGroupAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAdjustEndOfNextParagraphIfMovedParagraphIsUpdated, "AdjustEndOfNextParagraphIfMovedParagraphIsUpdated", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kEnableAIPromptAPI, "EnableAIPromptAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEnableAIPromptAPIForExtension, "EnableAIPromptAPIForExtension", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kEnableAIPromptAPIForWebPlatform, "EnableAIPromptAPIForWebPlatform", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEnableAIRewriterAPI, "EnableAIRewriterAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEnableAISummarizationAPI, "EnableAISummarizationAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kEnableAIWriterAPI, "EnableAIWriterAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAllowJavaScriptToResetAutofillState, "AllowJavaScriptToResetAutofillState", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAllowPreloadingWithCSPMetaTag, "AllowPreloadingWithCSPMetaTag", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAnimationProgressAPI, "AnimationProgressAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAnimationWorklet, "AnimationWorklet", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAnonymousIframe, "AnonymousIframe", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAOMAriaRelationshipProperties, "AOMAriaRelationshipProperties", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAOMAriaRelationshipPropertiesAriaOwns, "AOMAriaRelationshipPropertiesAriaOwns", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAppEnableAppTitle, "WebAppEnableAppTitle", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAriaActions, "AriaActions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAriaNotify, "AriaNotify", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAriaRowColIndexText, "AriaRowColIndexText", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAtomicMoveAPI, "AtomicMoveAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAudioContextInterruptedState, "AudioContextInterruptedState", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAudioContextOnError, "AudioContextOnError", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAudioContextPlayoutStats, "AudioContextPlayoutStats", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAudioContextSetSinkId, "AudioContextSetSinkId", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAudioOutputDevices, "AudioOutputDevices",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kAudioVideoTracks, "AudioVideoTracks", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAuraScrollbarUsesNinePatchTrack, "AuraScrollbarUsesNinePatchTrack", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAuraScrollbarUsesSolidColorThumb, "AuraScrollbarUsesSolidColorThumb", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kAutoPictureInPictureVideoHeuristics, "AutoPictureInPictureVideoHeuristics", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBackfaceVisibilityInterop, "BackfaceVisibilityInterop", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBackForwardCacheSendNotRestoredReasons, "BackForwardCacheSendNotRestoredReasons", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kBackForwardTransitions, "BackForwardTransitions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBarcodeDetector, "BarcodeDetector",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kBidiCaretAffinity, "BidiCaretAffinity", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlinkExtensionChromeOS, "BlinkExtensionChromeOS", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlinkExtensionChromeOSKiosk, "BlinkExtensionChromeOSKiosk", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlinkExtensionWebView, "BlinkExtensionWebView", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlinkExtensionWebViewMediaIntegrity, "BlinkExtensionWebViewMediaIntegrity", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlinkLifecycleScriptForbidden, "BlinkLifecycleScriptForbidden", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlinkRuntimeCallStats, "BlinkRuntimeCallStats", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlockingFocusWithoutUserActivation, "BlockingFocusWithoutUserActivation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBoundaryEventDispatchTracksNodeRemoval, "BoundaryEventDispatchTracksNodeRemoval", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBoxDecorationBreak, "BoxDecorationBreak", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kBreakIteratorHyphenMinus, "BreakIteratorHyphenMinus", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kBufferedBytesConsumerLimitSize, "BufferedBytesConsumerLimitSize", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kEnableBuiltInAIAPI, "EnableBuiltInAIAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kBypassPepcSecurityForTesting, "BypassPepcSecurityForTesting", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCalendarPickerMonthPopupButtonDisabledColor, "CalendarPickerMonthPopupButtonDisabledColor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCallExitNodeWithoutLayoutObject, "CallExitNodeWithoutLayoutObject", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCanvas2dCanvasFilter, "Canvas2dCanvasFilter", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvas2dGPUTransfer, "Canvas2dGPUTransfer", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvas2dLayers, "Canvas2dLayers", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvas2dLayersWithOptions, "Canvas2dLayersWithOptions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvas2dMesh, "Canvas2dMesh", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvas2dTextMetricsShaping, "Canvas2dTextMetricsShaping", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvasFloatingPoint, "CanvasFloatingPoint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvasHDR, "CanvasHDR", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvasImageSmoothing, "CanvasImageSmoothing", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvasPlaceElement, "CanvasPlaceElement", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCanvasUsesArcPaintOp, "CanvasUsesArcPaintOp", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCapabilityDelegationDisplayCaptureRequest, "CapabilityDelegationDisplayCaptureRequest", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCaptureController, "CaptureController",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kCapturedMouseEvents, "CapturedMouseEvents",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kCapturedSurfaceControl, "CapturedSurfaceControl",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kCaptureHandle, "CaptureHandle",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kCaretPositionFromPoint, "CaretPositionFromPoint", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCCTNewRFMPushBehavior, "CCTNewRFMPushBehavior", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCheckIfHighestRootContainsPositionAnchorNode, "CheckIfHighestRootContainsPositionAnchorNode", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCheckVisibilityExtraProperties, "CheckVisibilityExtraProperties", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kClickToCapturedPointer, "ClickToCapturedPointer", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kClipboardItemWithDOMStringSupport, "ClipboardItemWithDOMStringSupport", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kClipPathRejectEmptyPaths, "ClipPathRejectEmptyPaths", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCoalesceSelectionchangeEvent, "CoalesceSelectionchangeEvent", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCoepReflection, "CoepReflection", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCompositeBoxShadowAnimation, "CompositeBoxShadowAnimation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCompositeClipPathAnimation, "CompositeClipPathAnimation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCompositedAnimationsCancelledAsynchronously, "CompositedAnimationsCancelledAsynchronously", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCompositionForegroundMarkers, "CompositionForegroundMarkers",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kComputedAccessibilityInfo, "ComputedAccessibilityInfo", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kComputePressure, "ComputePressure",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kConcurrentViewTransitionsSPA, "ConcurrentViewTransitionsSPA", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kContactsManager, "ContactsManager",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kContactsManagerExtraProperties, "ContactsManagerExtraProperties",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kContainerTypeNoLayoutContainment, "ContainerTypeNoLayoutContainment", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kContentIndex, "ContentIndex",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kContextMenu, "ContextMenu", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kContinueEventTimingRecordingWhenBufferIsFull, "ContinueEventTimingRecordingWhenBufferIsFull", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kControlledFrame, "ControlledFrame", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCorsRFC1918, "CorsRFC1918", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCreateInputShadowTreeDuringLayout, "CreateInputShadowTreeDuringLayout", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCredentialManagerReport, "CredentialManagerReport", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCrossFramePerformanceTimeline, "CrossFramePerformanceTimeline", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAccentColorKeyword, "CSSAccentColorKeyword", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAdvancedAttrFunction, "CSSAdvancedAttrFunction", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAnchorScope, "CSSAnchorScope", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAnchorSizeInsetsMargins, "CSSAnchorSizeInsetsMargins", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAtPropertyStringSyntax, "CSSAtPropertyStringSyntax", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAtRuleCounterStyleImageSymbols, "CSSAtRuleCounterStyleImageSymbols", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSAtRuleCounterStyleSpeakAsDescriptor, "CSSAtRuleCounterStyleSpeakAsDescriptor", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSBackgroundClipUnprefix, "CSSBackgroundClipUnprefix", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCalcSimplificationAndSerialization, "CSSCalcSimplificationAndSerialization", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCalcSizeFunction, "CSSCalcSizeFunction", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCaretAnimation, "CSSCaretAnimation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCascadeCorrectScope, "CSSCascadeCorrectScope", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCaseSensitiveSelector, "CSSCaseSensitiveSelector", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSColorContrast, "CSSColorContrast", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSColorTypedOM, "CSSColorTypedOM", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSComputedStyleFullPseudoElementParser, "CSSComputedStyleFullPseudoElementParser", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSContentVisibilityImpliesContainIntrinsicSizeAuto, "CSSContentVisibilityImpliesContainIntrinsicSizeAuto", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCrossFade, "CSSCrossFade", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCustomStateDeprecatedSyntax, "CSSCustomStateDeprecatedSyntax", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSCustomStateNewSyntax, "CSSCustomStateNewSyntax", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSDynamicRangeLimit, "CSSDynamicRangeLimit", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSEnumeratedCustomProperties, "CSSEnumeratedCustomProperties", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSExponentialFunctions, "CSSExponentialFunctions", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSFlatTreeContainer, "CSSFlatTreeContainer", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSFontSizeAdjust, "CSSFontSizeAdjust", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSFunctions, "CSSFunctions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSGapDecoration, "CSSGapDecoration", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSHexAlphaColor, "CSSHexAlphaColor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSInert, "CSSInert", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSInsetAreaProperty, "CSSInsetAreaProperty", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSKeyframesRuleLength, "CSSKeyframesRuleLength", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSLayoutAPI, "CSSLayoutAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSLazyParsingFastPath, "CSSLazyParsingFastPath", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSLineClamp, "CSSLineClamp", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSLineClampWebkitBoxBlockification, "CSSLineClampWebkitBoxBlockification", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSLogicalOverflow, "CSSLogicalOverflow", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSMarkerNestedPseudoElement, "CSSMarkerNestedPseudoElement", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSMasonryLayout, "CSSMasonryLayout", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSMixins, "CSSMixins", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSNestedDeclarations, "CSSNestedDeclarations", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSNestedPseudoElements, "CSSNestedPseudoElements", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSOverflowContainerQueries, "CSSOverflowContainerQueries", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPaintAPIArguments, "CSSPaintAPIArguments", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSParserIgnoreCharsetForURLs, "CSSParserIgnoreCharsetForURLs", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPartAllowsMoreSelectorsAfter, "CSSPartAllowsMoreSelectorsAfter", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPositionAreaValue, "CSSPositionAreaValue", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPositionStickyStaticScrollPosition, "CSSPositionStickyStaticScrollPosition", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSProgressNotation, "CSSProgressNotation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPseudoColumn, "CSSPseudoColumn", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPseudoHasSlotted, "CSSPseudoHasSlotted", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPseudoOpenClosed, "CSSPseudoOpenClosed", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPseudoPlayingPaused, "CSSPseudoPlayingPaused", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPseudoScrollButtons, "CSSPseudoScrollButtons", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSPseudoScrollMarkers, "CSSPseudoScrollMarkers", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSReadingFlow, "CSSReadingFlow", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSRelativeColor, "CSSRelativeColor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSRelativeColorLateResolveAlways, "CSSRelativeColorLateResolveAlways", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSRelativeColorPreserveNone, "CSSRelativeColorPreserveNone", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSRelativeColorSupportsCurrentcolor, "CSSRelativeColorSupportsCurrentcolor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSResizeAuto, "CSSResizeAuto", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSScrollSnapChangeEvent, "CSSScrollSnapChangeEvent", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSScrollSnapChangingEvent, "CSSScrollSnapChangingEvent", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSScrollSnapEvents, "CSSScrollSnapEvents", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSScrollStart, "CSSScrollStart", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSScrollStartTarget, "CSSScrollStartTarget", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSScrollStateContainerQueries, "CSSScrollStateContainerQueries", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCssSelectorFragmentAnchor, "CssSelectorFragmentAnchor", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSSignRelatedFunctions, "CSSSignRelatedFunctions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSSnapContainerQueries, "CSSSnapContainerQueries", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSSteppedValueFunctions, "CSSSteppedValueFunctions", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSStickyContainerQueries, "CSSStickyContainerQueries", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSSupportsAtRuleFunction, "CSSSupportsAtRuleFunction", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSSupportsForImportRules, "CSSSupportsForImportRules", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSSystemAccentColor, "CSSSystemAccentColor", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSTextAutoSpace, "CSSTextAutoSpace", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSTextBoxTrim, "CSSTextBoxTrim", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSTextSpacing, "CSSTextSpacing", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSTreeScopedTimelines, "CSSTreeScopedTimelines", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSUserSelectContain, "CSSUserSelectContain", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSVideoDynamicRangeMediaQueries, "CSSVideoDynamicRangeMediaQueries", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSViewTransitionAutoName, "CSSViewTransitionAutoName", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCSSViewTransitionClass, "CSSViewTransitionClass", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCursorAnchorInfoMojoPipe, "CursorAnchorInfoMojoPipe", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCustomizableSelect, "CustomizableSelect", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDeprecatedRequestAdapterInfo, "DeprecatedRequestAdapterInfo", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDeprecateUnloadOptOut, "DeprecateUnloadOptOut", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDesktopCaptureDisableLocalEchoControl, "DesktopCaptureDisableLocalEchoControl", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDesktopPWAsAdditionalWindowingControls, "DesktopPWAsAdditionalWindowingControls", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDesktopPWAsSubApps, "DesktopPWAsSubApps", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDetailsStyling, "DetailsStyling", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDeviceAttributes, "DeviceAttributes",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kDeviceOrientationRequestPermission, "DeviceOrientationRequestPermission", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDevicePosture, "DevicePosture", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDialogCloseWhenOpenRemoved, "DialogCloseWhenOpenRemoved", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDialogElementToggleEvents, "DialogElementToggleEvents", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDialogNewFocusBehavior, "DialogNewFocusBehavior", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDigitalGoodsV2_1, "DigitalGoodsV2_1",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kDirAutoFixSlotExclusions, "DirAutoFixSlotExclusions", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDirectSockets, "DirectSockets", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDisableAhemAntialias, "DisableAhemAntialias", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDisableSelectAllForEmptyText, "DisableSelectAllForEmptyText", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDispatchBeforeInputForSpinButtonInteractions, "DispatchBeforeInputForSpinButtonInteractions", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDispatchHiddenVisibilityTransitions, "DispatchHiddenVisibilityTransitions", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDispatchSelectionchangeEventPerElement, "DispatchSelectionchangeEventPerElement", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDisplayContentsFocusable, "DisplayContentsFocusable", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentCookie, "DocumentCookie", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentDomain, "DocumentDomain", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentInstallChunking, "DocumentInstallChunking", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentOpenOriginAliasRemoval, "DocumentOpenOriginAliasRemoval", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentOpenSandboxInheritanceRemoval, "DocumentOpenSandboxInheritanceRemoval", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentPictureInPictureAPI, "DocumentPictureInPictureAPI",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kDocumentPictureInPicturePreferInitialPlacement, "DocumentPictureInPicturePreferInitialPlacement",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kDocumentPictureInPictureUserActivation, "DocumentPictureInPictureUserActivation",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kDocumentPolicyDocumentDomain, "DocumentPolicyDocumentDomain", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentPolicyExpectNoLinkedResources, "DocumentPolicyExpectNoLinkedResources", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentPolicyIncludeJSCallStacksInCrashReports, "DocumentPolicyIncludeJSCallStacksInCrashReports", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentPolicySyncXHR, "DocumentPolicySyncXHR", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentRenderBlocking, "DocumentRenderBlocking", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentWrite, "DocumentWrite", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDOMPartsAPI, "DOMPartsAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDOMPartsAPIMinimal, "DOMPartsAPIMinimal", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDropUrlAsPlainTextInPlainTextOnlyEditablePosition, "DropUrlAsPlainTextInPlainTextOnlyEditablePosition", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDynamicSafeAreaInsets, "DynamicSafeAreaInsets", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDynamicSafeAreaInsetsOnScroll, "DynamicSafeAreaInsetsOnScroll", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kElementCapture, "ElementCapture",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kElementGetInnerHTML, "ElementGetInnerHTML", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEnforceAnonymityExposure, "EnforceAnonymityExposure", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kEscapeLtGtInAttributes, "EscapeLtGtInAttributes", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEventTimingHandleKeyboardEventSimulatedClick, "EventTimingHandleKeyboardEventSimulatedClick", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kEventTimingInteractionCount, "EventTimingInteractionCount", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEventTimingSelectionAutoScrollNoInteractionId, "EventTimingSelectionAutoScrollNoInteractionId", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEventTimingTapStopScrollNoInteractionId, "EventTimingTapStopScrollNoInteractionId", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kExcludeTransparentTextsFromBeingLcpEligible, "ExcludeTransparentTextsFromBeingLcpEligible", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kExperimentalJSProfilerMarkers, "ExperimentalJSProfilerMarkers", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kExperimentalPolicies, "ExperimentalPolicies", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kExposeCoarsenedRenderTime, "ExposeCoarsenedRenderTime", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kExposeRenderTimeNonTaoDelayedImage, "ExposeRenderTimeNonTaoDelayedImage", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kExtendedTextMetrics, "ExtendedTextMetrics", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFaceDetector, "FaceDetector", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFastNonCompositedScrollHitTest, "FastNonCompositedScrollHitTest", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFastPathSingleSelectorExactMatch, "FastPathSingleSelectorExactMatch", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFastPositionIterator, "FastPositionIterator", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFedCmWithStorageAccessAPI, "FedCmWithStorageAccessAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFencedFramesAPIChanges, "FencedFramesAPIChanges", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFencedFramesDefaultMode, "FencedFramesDefaultMode", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFetchBodyBytes, "FetchBodyBytes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFetchLaterAPI, "FetchLaterAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFetchUploadStreaming, "FetchUploadStreaming", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFileHandlingAPI, "FileHandlingAPI",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kFileSystemAccess, "FileSystemAccess", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFileSystemAccessAPIExperimental, "FileSystemAccessAPIExperimental", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFileSystemAccessGetCloudIdentifiers, "FileSystemAccessGetCloudIdentifiers",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kFileSystemAccessLocal, "FileSystemAccessLocal",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kFileSystemAccessLockingScheme, "FileSystemAccessLockingScheme", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFileSystemAccessOriginPrivate, "FileSystemAccessOriginPrivate", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFileSystemObserver, "FileSystemObserver", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFileSystemObserverUnobserve, "FileSystemObserverUnobserve", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFindDecomposedInShortText, "FindDecomposedInShortText", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFindRubyInPage, "FindRubyInPage", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFindTextInReadonlyTextInput, "FindTextInReadonlyTextInput", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFindTextSkipCollapsedText, "FindTextSkipCollapsedText", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeAuctionDealSupport, "FledgeAuctionDealSupport", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeCustomMaxAuctionAdComponents, "FledgeCustomMaxAuctionAdComponents", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeDeprecatedRenderURLReplacements, "FledgeDeprecatedRenderURLReplacements", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeDirectFromSellerSignalsHeaderAdSlot, "FledgeDirectFromSellerSignalsHeaderAdSlot", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeMultiBid, "FledgeMultiBid", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeRealTimeReporting, "FledgeRealTimeReporting", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeReportingTimeout, "FledgeReportingTimeout", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeSellerNonce, "FledgeSellerNonce", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFledgeTrustedSignalsKVv2Support, "FledgeTrustedSignalsKVv2Support", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFluentScrollbarUsesNinePatchTrack, "FluentScrollbarUsesNinePatchTrack", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFontAccess, "FontAccess",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kFontationsFontBackend, "FontationsFontBackend", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFontationsForSelectedFormats, "FontationsForSelectedFormats", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFontFamilyPostscriptMatchingCTMigration, "FontFamilyPostscriptMatchingCTMigration", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFontFamilyStyleMatchingCTMigration, "FontFamilyStyleMatchingCTMigration", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFontPresentWin, "FontPresentWin", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFontSystemFallbackNotoCjk, "FontSystemFallbackNotoCjk", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFontVariantEmoji, "FontVariantEmoji", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFontVariationSequences, "FontVariationSequences", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kForcedColorsPreserveParentColor, "ForcedColorsPreserveParentColor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kForceEagerMeasureMemory, "ForceEagerMeasureMemory", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kForceReduceMotion, "ForceReduceMotion", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kForceTallerSelectPopup, "ForceTallerSelectPopup",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kFormControlRestoreStateIfAutocompleteOff, "FormControlRestoreStateIfAutocompleteOff", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kFormControlsVerticalWritingModeDirectionSupport, "FormControlsVerticalWritingModeDirectionSupport", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kFreezeFramesOnVisibility, "FreezeFramesOnVisibility", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kGamepadMultitouch, "GamepadMultitouch", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kGetAllScreensMedia, "GetAllScreensMedia", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kGetDisplayMediaRequiresUserActivation, "GetDisplayMediaRequiresUserActivation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kGroupEffect, "GroupEffect", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHandleSelectionChangeOnDeletingEmptyElement, "HandleSelectionChangeOnDeletingEmptyElement", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHandwritingRecognition, "HandwritingRecognition",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kHangingWhitespaceDoesNotDependOnAlignment, "HangingWhitespaceDoesNotDependOnAlignment", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHasUAVisualTransition, "HasUAVisualTransition", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHighlightInheritance, "HighlightInheritance", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHighlightPointerEvents, "HighlightPointerEvents", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHighlightsFromPoint, "HighlightsFromPoint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHitTestOpaqueness, "HitTestOpaqueness", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHitTestOpaquenessOmitLineBox, "HitTestOpaquenessOmitLineBox", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLAnchorAttribute, "HTMLAnchorAttribute", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLDialogLightDismiss, "HTMLDialogLightDismiss", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLEmbedElementNotForceLayout, "HTMLEmbedElementNotForceLayout", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLInterestTargetAttribute, "HTMLInterestTargetAttribute", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLInvokeActionsV2, "HTMLInvokeActionsV2", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLInvokeTargetAttribute, "HTMLInvokeTargetAttribute", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLObjectElementFallbackDetachContentFrame, "HTMLObjectElementFallbackDetachContentFrame", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLParserYieldAndDelayOftenForTesting, "HTMLParserYieldAndDelayOftenForTesting", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLPopoverActionHover, "HTMLPopoverActionHover", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLPopoverHint, "HTMLPopoverHint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLSelectElementShowPicker, "HTMLSelectElementShowPicker", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kImportAttributesDisallowUnknownKeys, "ImportAttributesDisallowUnknownKeys", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kImportMapIntegrity, "ImportMapIntegrity", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kIncomingCallNotifications, "IncomingCallNotifications", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kIncrementLocalSurfaceIdForMainframeSameDocNavigation, "IncrementLocalSurfaceIdForMainframeSameDocNavigation",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kIndexedDbGetAllRecords, "IndexedDbGetAllRecords", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInertElementNonEditable, "InertElementNonEditable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInertElementNonSearchable, "InertElementNonSearchable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInfiniteCullRect, "InfiniteCullRect", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInheritUserModifyWithoutContenteditable, "InheritUserModifyWithoutContenteditable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInitialLetterRaiseBySpecified, "InitialLetterRaiseBySpecified", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInlineBlockInSameLine, "InlineBlockInSameLine", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInnerHTMLParserFastpathLogFailure, "InnerHTMLParserFastpathLogFailure", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInputClosesSelect, "InputClosesSelect", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInputMultipleFieldsUI, "InputMultipleFieldsUI",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kInsertBlockquoteBeforeOuterBlock, "InsertBlockquoteBeforeOuterBlock", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInsertLineBreakIfPhrasingContent, "InsertLineBreakIfPhrasingContent",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kInspectorGhostRules, "InspectorGhostRules", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInstallOnDeviceSpeechRecognition, "InstallOnDeviceSpeechRecognition", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInterestGroupsInSharedStorageWorklet, "InterestGroupsInSharedStorageWorklet", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInteroperablePrivateAttribution, "InteroperablePrivateAttribution", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kIntersectionObserverScrollMargin, "IntersectionObserverScrollMargin", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kInvertedColors, "InvertedColors", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kInvisibleSVGAnimationThrottling, "InvisibleSVGAnimationThrottling", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kJavaScriptCompileHintsMagicAlwaysRuntime, "JavaScriptCompileHintsMagicAlwaysRuntime", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kJavaScriptCompileHintsMagicRuntime, "JavaScriptCompileHintsMagicRuntime", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kKeepCSSTargetAfterReattach, "KeepCSSTargetAfterReattach", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kKeyboardFocusableScrollers, "KeyboardFocusableScrollers", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kKeyboardFocusableScrollersOptOut, "KeyboardFocusableScrollersOptOut", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLabelAndDelegatesFocusNewHandling, "LabelAndDelegatesFocusNewHandling", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLangAttributeAwareFormControlUI, "LangAttributeAwareFormControlUI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLanguageDetectionAPI, "LanguageDetectionAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutFlexNewRowAlgorithmV3, "LayoutFlexNewRowAlgorithmV3", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutIgnoreMarginsForSticky, "LayoutIgnoreMarginsForSticky", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutJustifySelfForBlocks, "LayoutJustifySelfForBlocks", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutNGShapeCache, "LayoutNGShapeCache", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutStretch, "LayoutStretch", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLazyLoadScrollMargin, "LazyLoadScrollMargin", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLazyLoadScrollMarginIframe, "LazyLoadScrollMarginIframe", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLCPAnimatedImagesWebExposed, "LCPAnimatedImagesWebExposed", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLineBoxBelowLeadingFloats, "LineBoxBelowLeadingFloats", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kListItemWithCounterSetNotSetExplicitValue, "ListItemWithCounterSetNotSetExplicitValue", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLockedMode, "LockedMode", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLongAnimationFrameTiming, "LongAnimationFrameTiming", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLongPressLinkSelectText, "LongPressLinkSelectText", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLongTaskFromLongAnimationFrame, "LongTaskFromLongAnimationFrame", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kManagedConfiguration, "ManagedConfiguration", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMeasureMemory, "MeasureMemory", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMediaCapabilitiesDynamicRange, "MediaCapabilitiesDynamicRange", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMediaCapabilitiesEncodingInfo, "MediaCapabilitiesEncodingInfo", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaCapabilitiesSpatialAudio, "MediaCapabilitiesSpatialAudio", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaCapture, "MediaCapture",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kMediaCaptureCameraControls, "MediaCaptureCameraControls", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaCaptureVoiceIsolation, "MediaCaptureVoiceIsolation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaElementVolumeGreaterThanOne, "MediaElementVolumeGreaterThanOne", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaLatencyHint, "MediaLatencyHint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaPlaybackWhileNotVisiblePermissionPolicy, "MediaPlaybackWhileNotVisiblePermissionPolicy", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaQueryNavigationControls, "MediaQueryNavigationControls", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaRecorderUseMediaVideoEncoder, "MediaRecorderUseMediaVideoEncoder", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaSessionChapterInformation, "MediaSessionChapterInformation", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMediaSessionEnterPictureInPicture, "MediaSessionEnterPictureInPicture", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMediaSourceExperimental, "MediaSourceExperimental", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaSourceNewAbortAndDuration, "MediaSourceNewAbortAndDuration", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMediaStreamTrackWebSpeech, "MediaStreamTrackWebSpeech", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMessagePortCloseEvent, "MessagePortCloseEvent", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMetaRefreshNoFractional, "MetaRefreshNoFractional", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMeterAppearanceNoneFallbackStyle, "MeterAppearanceNoneFallbackStyle", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMeterDevolveAppearance, "MeterDevolveAppearance", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMiddleClickAutoscroll, "MiddleClickAutoscroll", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMinimimalResourceRequestPrepBeforeCacheLookup, "MinimimalResourceRequestPrepBeforeCacheLookup", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMobileLayoutTheme, "MobileLayoutTheme", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kModifyParagraphCrossEditingoundary, "ModifyParagraphCrossEditingoundary", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMojoJS, "MojoJS", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMoveEndingSelectionToListChild, "MoveEndingSelectionToListChild", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMoveToParagraphStartOrEndSkipsNonEditable, "MoveToParagraphStartOrEndSkipsNonEditable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMultipleImportMaps, "MultipleImportMaps", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMultiSelectDeselectWhenOnlyOption, "MultiSelectDeselectWhenOnlyOption", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMultiSmoothScrollIntoView, "MultiSmoothScrollIntoView", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMutationEvents, "MutationEvents", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kMutationEventsSpecialTrialMessage, "MutationEventsSpecialTrialMessage", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNavigateEventCommitBehavior, "NavigateEventCommitBehavior", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNavigateEventSourceElement, "NavigateEventSourceElement", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNavigationActivation, "NavigationActivation", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNavigationId, "NavigationId", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNavigatorContentUtils, "NavigatorContentUtils",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kNestedViewTransition, "NestedViewTransition", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNetInfoConstantType, "NetInfoConstantType", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNewGetFocusableAreaBehavior, "NewGetFocusableAreaBehavior", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNoIdleEncodingForWebTests, "NoIdleEncodingForWebTests", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kNoIncreasingEndOffsetOnSplittingTextNodes, "NoIncreasingEndOffsetOnSplittingTextNodes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNonEmptyBlockquotesOnOutdenting, "NonEmptyBlockquotesOnOutdenting", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNonNullInputEventDataForTextArea, "NonNullInputEventDataForTextArea", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNonStandardAppearanceValueSliderVertical, "NonStandardAppearanceValueSliderVertical", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNotificationConstructor, "NotificationConstructor",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kObservableAPI, "ObservableAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kOffMainThreadCSSPaint, "OffMainThreadCSSPaint", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kOffscreenCanvasCommit, "OffscreenCanvasCommit", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kOmitBlurEventOnElementRemoval, "OmitBlurEventOnElementRemoval", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kOnDeviceChange, "OnDeviceChange", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kOnDeviceWebSpeechAvailable, "OnDeviceWebSpeechAvailable", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kOrientationEvent, "OrientationEvent",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kOriginPolicy, "OriginPolicy", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kOverscrollCustomization, "OverscrollCustomization", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPageMarginBoxes, "PageMarginBoxes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPagePopup, "PagePopup",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kPageRevealEvent, "PageRevealEvent", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPageSwapEvent, "PageSwapEvent", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPaintHighlightsForFirstLetter, "PaintHighlightsForFirstLetter", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPaintHoldingForIframes, "PaintHoldingForIframes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPaintHoldingForLocalIframes, "PaintHoldingForLocalIframes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPaintUnderInvalidationChecking, "PaintUnderInvalidationChecking", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kParakeet, "Parakeet", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPartitionedPopins, "PartitionedPopins", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPartitionVisitedLinkDatabaseWithSelfLinks, "PartitionVisitedLinkDatabaseWithSelfLinks",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kPasswordReveal, "PasswordReveal", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPaymentInstruments, "PaymentInstruments", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPaymentLinkDetection, "PaymentLinkDetection", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPaymentMethodChangeEvent, "PaymentMethodChangeEvent", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPerformanceMarkFeatureUsage, "PerformanceMarkFeatureUsage", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPerformanceNavigateSystemEntropy, "PerformanceNavigateSystemEntropy", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPerformanceNavigationTimingConfidence, "PerformanceNavigationTimingConfidence", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPermissionElement, "PermissionElement", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPermissionsRequestRevoke, "PermissionsRequestRevoke", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPointerEventDeviceId, "PointerEventDeviceId", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPointerEventTargetsInEventLists, "PointerEventTargetsInEventLists", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPopoverAnchorRelationships, "PopoverAnchorRelationships", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPopoverDialogNewFocusBehavior, "PopoverDialogNewFocusBehavior", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPositionOutsideTabSpanCheckSiblingNode, "PositionOutsideTabSpanCheckSiblingNode", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPreferDefaultScrollbarStyles, "PreferDefaultScrollbarStyles", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPreferNonCompositedScrolling, "PreferNonCompositedScrolling", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPrefersReducedData, "PrefersReducedData", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPrefixedVideoFullscreen, "PrefixedVideoFullscreen", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPrerender2, "Prerender2", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPreserveFollowingBlockStylesDuringBlockMerge, "PreserveFollowingBlockStylesDuringBlockMerge", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPreventUndoIfNotEditable, "PreventUndoIfNotEditable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPrivateAggregationApiFilteringIds, "PrivateAggregationApiFilteringIds", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPrivateAggregationAuctionReportBuyerDebugModeConfig, "PrivateAggregationAuctionReportBuyerDebugModeConfig", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPseudoElementsCorrectInGetComputedStyle, "PseudoElementsCorrectInGetComputedStyle", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPseudoElementsFocusable, "PseudoElementsFocusable", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kQuickIntensiveWakeUpThrottlingAfterLoading, "QuickIntensiveWakeUpThrottlingAfterLoading", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRasterInducingScroll, "RasterInducingScroll", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kReadableStreamAsyncIterable, "ReadableStreamAsyncIterable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kReduceCookieIPCs, "ReduceCookieIPCs", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kReduceUserAgentAndroidVersionDeviceModel, "ReduceUserAgentAndroidVersionDeviceModel",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kReduceUserAgentMinorVersion, "ReduceUserAgentMinorVersion", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kReduceUserAgentPlatformOsCpu, "ReduceUserAgentPlatformOsCpu",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kRegionCapture, "RegionCapture",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kRelOpenerBcgDependencyHint, "RelOpenerBcgDependencyHint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRemotePlaybackBackend, "RemotePlaybackBackend",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kRemoveCollapsedPlaceholder, "RemoveCollapsedPlaceholder", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRemoveDanglingMarkupInTarget, "RemoveDanglingMarkupInTarget", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRemoveDataUrlInSvgUse, "RemoveDataUrlInSvgUse", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRemoveNodeHavingChildrenIfFullySelected, "RemoveNodeHavingChildrenIfFullySelected", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRemoveVisibleSelectionInDOMSelection, "RemoveVisibleSelectionInDOMSelection", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRenderBlockingInlineModuleScript, "RenderBlockingInlineModuleScript", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRenderBlockingStatus, "RenderBlockingStatus", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRenderPriorityAttribute, "RenderPriorityAttribute", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kReportEventTimingAtVisibilityChange, "ReportEventTimingAtVisibilityChange", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kReportVisibleLineBounds, "ReportVisibleLineBounds",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kResetInputTypeToNoneBeforeCharacterInput, "ResetInputTypeToNoneBeforeCharacterInput", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kResourceTimingContentType, "ResourceTimingContentType", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kResourceTimingFinalResponseHeadersStart, "ResourceTimingFinalResponseHeadersStart", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kResourceTimingUseCORSForBodySizes, "ResourceTimingUseCORSForBodySizes", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kReuseShapeResultsByFonts, "ReuseShapeResultsByFonts", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRewindFloats, "RewindFloats", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRootElementWithPlaceHolderAfterDeletingSelection, "RootElementWithPlaceHolderAfterDeletingSelection", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRTCDataChannelPriority, "RTCDataChannelPriority", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRTCEncodedAudioFrameAbsCaptureTime, "RTCEncodedAudioFrameAbsCaptureTime", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRTCEncodedFrameSetMetadata, "RTCEncodedFrameSetMetadata", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRTCEncodedVideoFrameAdditionalMetadata, "RTCEncodedVideoFrameAdditionalMetadata", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRTCJitterBufferTarget, "RTCJitterBufferTarget", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRTCRtpEncodingParametersCodec, "RTCRtpEncodingParametersCodec", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRTCRtpScaleResolutionDownTo, "RTCRtpScaleResolutionDownTo", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRTCRtpScriptTransform, "RTCRtpScriptTransform", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRTCRtpTransport, "RTCRtpTransport", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kRTCSvcScalabilityMode, "RTCSvcScalabilityMode", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kRubyShortHeuristics, "RubyShortHeuristics", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSanitizerAPI, "SanitizerAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSchedulerYield, "SchedulerYield", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScheduleSelectionChangeOnBackspace, "ScheduleSelectionChangeOnBackspace",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kScopedCustomElementRegistry, "ScopedCustomElementRegistry", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kScrollbarColor, "ScrollbarColor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScrollbarWidth, "ScrollbarWidth", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScrollEndEvents, "ScrollEndEvents", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScrollIntoViewRootFrameViewportBugFix, "ScrollIntoViewRootFrameViewportBugFix", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScrollTimeline, "ScrollTimeline", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScrollTimelineCurrentTime, "ScrollTimelineCurrentTime", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kScrollTopLeftInterop, "ScrollTopLeftInterop", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSearchTextHighlightPseudo, "SearchTextHighlightPseudo", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSecurePaymentConfirmationNetworkAndIssuerIcons, "SecurePaymentConfirmationNetworkAndIssuerIcons", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSelectAudioOutput, "SelectAudioOutput",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kSelectedcontentelementAttribute, "SelectedcontentelementAttribute", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSelectionAcrossShadowDOM, "SelectionAcrossShadowDOM", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSelectionIsCollapsedShadowDOMSupport, "SelectionIsCollapsedShadowDOMSupport", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSelectionOnShadowDOMWithDelegatesFocus, "SelectionOnShadowDOMWithDelegatesFocus", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSelectOptionAccessibilityTargetSize, "SelectOptionAccessibilityTargetSize", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSelectParserRelaxation, "SelectParserRelaxation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSelectPopupLessUpdates, "SelectPopupLessUpdates", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSerial, "Serial",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kSerializeViewTransitionStateInSPA, "SerializeViewTransitionStateInSPA", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kServiceWorkerClientLifecycleState, "ServiceWorkerClientLifecycleState", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kServiceWorkerStaticRouterTimingInfo, "ServiceWorkerStaticRouterTimingInfo", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSetSequentialFocusStartingPoint, "SetSequentialFocusStartingPoint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kShadowRootReferenceTarget, "ShadowRootReferenceTarget", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kShapeOutsideWritingModeFix, "ShapeOutsideWritingModeFix", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kShapeResultCachedPreviousSafeToBreakOffset, "ShapeResultCachedPreviousSafeToBreakOffset", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSharedStorageWebLocks, "SharedStorageWebLocks", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSidewaysWritingModes, "SidewaysWritingModes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSiteInitiatedMirroring, "SiteInitiatedMirroring", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSkipAd, "SkipAd", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSkipPreloadScanning, "SkipPreloadScanning", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSkipTemporaryDocumentFragment, "SkipTemporaryDocumentFragment", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSkipTouchEventFilter, "SkipTouchEventFilter", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSmartCard, "SmartCard",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kSmilAutoSuspendOnLag, "SmilAutoSuspendOnLag", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSoftNavigationDetection, "SoftNavigationDetection", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSoftNavigationHeuristics, "SoftNavigationHeuristics", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSoftNavigationHeuristicsExposeFPAndFCP, "SoftNavigationHeuristicsExposeFPAndFCP", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSpeakerSelection, "SpeakerSelection", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSpeculationRulesPointerDownHeuristics, "SpeculationRulesPointerDownHeuristics", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSpeculationRulesPointerHoverHeuristics, "SpeculationRulesPointerHoverHeuristics", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSpeculationRulesPrefetchWithSubresources, "SpeculationRulesPrefetchWithSubresources", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSrcsetMaxDensity, "SrcsetMaxDensity", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kStandardizedBrowserZoom, "StandardizedBrowserZoom", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kStandardizedBrowserZoomOptOut, "StandardizedBrowserZoomOptOut", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kStaticAnimationOptimization, "StaticAnimationOptimization", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kStorageAccessHeader, "StorageAccessHeader", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kStorageBuckets, "StorageBuckets", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kStorageBucketsDurability, "StorageBucketsDurability", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kStorageBucketsLocks, "StorageBucketsLocks", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kStricterCellWidthContentSizeQuirk, "StricterCellWidthContentSizeQuirk", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kStrictMimeTypesForWorkers, "StrictMimeTypesForWorkers", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSvgContextPaint, "SvgContextPaint", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgCrossOriginAttribute, "SvgCrossOriginAttribute", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgEagerPresAttrStyleUpdate, "SvgEagerPresAttrStyleUpdate", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgExternalResources, "SvgExternalResources", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgFilterUserSpaceViewportForNonSvg, "SvgFilterUserSpaceViewportForNonSvg", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgGradientColorInterpolationLinearRgbSupport, "SvgGradientColorInterpolationLinearRgbSupport", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgInlineRootPixelSnappingScaleAdjustment, "SvgInlineRootPixelSnappingScaleAdjustment", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgNoPixelSnappingScaleAdjustment, "SvgNoPixelSnappingScaleAdjustment", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSvgTransformOptimization, "SvgTransformOptimization", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSynthesizedKeyboardEventsForAccessibilityActions, "SynthesizedKeyboardEventsForAccessibilityActions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSystemFallbackEmojiVSSupport, "SystemFallbackEmojiVSSupport", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSystemWakeLock, "SystemWakeLock", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTestBlinkFeatureDefault, "TestBlinkFeatureDefault", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTestFeatureStable, "TestFeatureStable", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTextDetector, "TextDetector", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTextDiffSplitFix, "TextDiffSplitFix", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTextFragmentAPI, "TextFragmentAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTextFragmentAnchor, "TextFragmentAnchor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTextFragmentTapOpensContextMenu, "TextFragmentTapOpensContextMenu",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kTextInputNotAlwaysDirAuto, "TextInputNotAlwaysDirAuto", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTextMetricsBaselines, "TextMetricsBaselines", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTextSegmentBoundaryForElementWithFloatStyle, "TextSegmentBoundaryForElementWithFloatStyle", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTextSizeAdjustImprovements, "TextSizeAdjustImprovements", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTextTransformAndSecurityFix, "TextTransformAndSecurityFix", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTimelineScope, "TimelineScope", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTimestampBasedCLSTracking, "TimestampBasedCLSTracking", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTimeZoneChangeEvent, "TimeZoneChangeEvent", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTopLayerInactiveDocumentExceptions, "TopLayerInactiveDocumentExceptions", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTouchDragOnShortPress, "TouchDragOnShortPress", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTransferableRTCDataChannel, "TransferableRTCDataChannel", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTranslateService, "TranslateService", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEnableTranslationAPI, "EnableTranslationAPI", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kTranslationAPIEntryPoint, "TranslationAPIEntryPoint", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTrustedTypeBeforePolicyCreationEvent, "TrustedTypeBeforePolicyCreationEvent", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTrustedTypesUseCodeLike, "TrustedTypesUseCodeLike", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kUnclosedFormControlIsInvalid, "UnclosedFormControlIsInvalid", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kUnexposedTaskIds, "UnexposedTaskIds", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kUnownedAnimationsSkipCSSEvents, "UnownedAnimationsSkipCSSEvents", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kUnrestrictedMeasureUserAgentSpecificMemory, "UnrestrictedMeasureUserAgentSpecificMemory", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kUnrestrictedUsb, "UnrestrictedUsb", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kURLPatternCompareComponent, "URLPatternCompareComponent", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kURLSearchParamsHasAndDeleteMultipleArgs, "URLSearchParamsHasAndDeleteMultipleArgs", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kUseBeginFramePresentationFeedback, "UseBeginFramePresentationFeedback",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kUseLowQualityInterpolation, "UseLowQualityInterpolation",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kUseSelectionFocusNodeForCaretNavigation, "UseSelectionFocusNodeForCaretNavigation", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kUseUndoStepElementDispatchBeforeInput, "UseUndoStepElementDispatchBeforeInput", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kVideoAutoFullscreen, "VideoAutoFullscreen", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVideoFrameMetadataBackgroundBlur, "VideoFrameMetadataBackgroundBlur", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVideoFullscreenOrientationLock, "VideoFullscreenOrientationLock", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVideoRotateToFullscreen, "VideoRotateToFullscreen", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVideoTrackGenerator, "VideoTrackGenerator", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVideoTrackGeneratorInWindow, "VideoTrackGeneratorInWindow", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVideoTrackGeneratorInWorker, "VideoTrackGeneratorInWorker", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kViewportChangesUpdateTextAutosizing, "ViewportChangesUpdateTextAutosizing", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewportHeightClientHintHeader, "ViewportHeightClientHintHeader", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewportSegments, "ViewportSegments", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionDisableSnapBrowserControlsOnHidden, "ViewTransitionDisableSnapBrowserControlsOnHidden", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionLayeredCapture, "ViewTransitionLayeredCapture", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionLongCallbackTimeoutForTesting, "ViewTransitionLongCallbackTimeoutForTesting", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionOnNavigation, "ViewTransitionOnNavigation", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionOnNavigationForIframes, "ViewTransitionOnNavigationForIframes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionOverflowRectFromSurface, "ViewTransitionOverflowRectFromSurface", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionTreeScopedNames, "ViewTransitionTreeScopedNames", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewTransitionTypes, "ViewTransitionTypes", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kVisibilityCollapseColumn, "VisibilityCollapseColumn", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVisualViewportOnScrollEnd, "VisualViewportOnScrollEnd", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWakeLock, "WakeLock", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWarnOnContentVisibilityRenderAccess, "WarnOnContentVisibilityRenderAccess", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAnimationsSVG, "WebAnimationsSVG", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAppInstallation, "WebAppInstallation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDesktopPWAsTabStrip, "DesktopPWAsTabStrip", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kDesktopPWAsTabStripCustomizations, "DesktopPWAsTabStripCustomizations", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAppEnableTranslations, "WebAppEnableTranslations", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAssemblyJSStringBuiltins, "WebAssemblyJSStringBuiltins", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAudioBypassOutputBuffering, "WebAudioBypassOutputBuffering", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAudioBypassOutputBufferingOptOut, "WebAudioBypassOutputBufferingOptOut", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuth, "WebAuth", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthAuthenticatorAttachment, "WebAuthAuthenticatorAttachment", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthenticationAttestationFormats, "WebAuthenticationAttestationFormats", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthenticationClientCapabilities, "WebAuthenticationClientCapabilities", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthenticationJSONSerialization, "WebAuthenticationJSONSerialization", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthenticationLargeBlobExtension, "WebAuthenticationLargeBlobExtension", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthenticationPRFExtension, "WebAuthenticationPRFExtension", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAuthenticationSupplementalPubKeys, "WebAuthenticationSupplementalPubKeys", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebBluetoothScanning, "WebBluetoothScanning", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebCodecsCopyToRGB, "WebCodecsCopyToRGB", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebCodecsHBDFormats, "WebCodecsHBDFormats", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebCodecsOrientation, "WebCodecsOrientation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebCodecsVideoEncoderBuffers, "WebCodecsVideoEncoderBuffers", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebCryptoCurve25519, "WebCryptoCurve25519", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebFontResizeLCP, "WebFontResizeLCP", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebGLDrawingBufferStorage, "WebGLDrawingBufferStorage", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebGPUCanvasContextGetConfiguration, "WebGPUCanvasContextGetConfiguration", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebGPUDeviceAdapterInfo, "WebGPUDeviceAdapterInfo", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebGPUExperimentalFeatures, "WebGPUExperimentalFeatures", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebGPUHDR, "WebGPUHDR", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebGPUTextureViewUsage, "WebGPUTextureViewUsage", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebHID, "WebHID",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_ENABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_ENABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kWebHIDOnDedicatedWorkers, "WebHIDOnDedicatedWorkers", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebIDLBigIntUsesToBigInt, "WebIDLBigIntUsesToBigInt", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebPreferences, "WebPreferences", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebPrinting, "WebPrinting",
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_WIN)
        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
                base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_MAC)
                    base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_LINUX)
                        base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if BUILDFLAG(IS_IOS)
                            base::FEATURE_DISABLED_BY_DEFAULT
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
                                base::FEATURE_DISABLED_BY_DEFAULT
#endif
);

BASE_FEATURE(kWebSocketStream, "WebSocketStream", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebUSBOnDedicatedWorkers, "WebUSBOnDedicatedWorkers", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebVTTRegions, "WebVTTRegions", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebXREnabledFeatures, "WebXREnabledFeatures", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebXRHitTestEntityTypes, "WebXRHitTestEntityTypes", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebXRSpecParity, "WebXRSpecParity", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWindowDefaultStatus, "WindowDefaultStatus", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kXMLParserMergeAdjacentCDataSections, "XMLParserMergeAdjacentCDataSections", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kZeroCopyTabCapture, "ZeroCopyTabCapture", base::FEATURE_DISABLED_BY_DEFAULT);

} // namespace features
} // namespace blink
