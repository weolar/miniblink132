// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features_test_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_

#include "base/check_op.h"
#include "base/memory/protected_memory.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

// Don't use this class directly. Use Scoped*ForTest instead.
class RuntimeEnabledFeaturesTestHelpers {
public:
    template <bool& data_member> class ScopedRuntimeEnabledFeature {
    public:
        ScopedRuntimeEnabledFeature(bool enabled)
            : enabled_(enabled)
            , original_(data_member)
        {
            data_member = enabled;
        }
        ~ScopedRuntimeEnabledFeature()
        {
            CHECK_EQ(enabled_, data_member);
            data_member = original_;
        }

    private:
        bool enabled_;
        bool original_;
    };

    template <base::ProtectedMemory<bool>& data_member> class ScopedRuntimeEnabledProtectedFeature {
    public:
        ScopedRuntimeEnabledProtectedFeature(bool enabled)
            : enabled_(enabled)
            , original_(*data_member)
        {
            base::AutoWritableMemory data_member_writer(data_member);
            data_member_writer.GetProtectedData() = enabled;
        }
        ~ScopedRuntimeEnabledProtectedFeature()
        {
            CHECK_EQ(enabled_, *data_member);
            base::AutoWritableMemory data_member_writer(data_member);
            data_member_writer.GetProtectedData() = original_;
        }

    private:
        bool enabled_;
        bool original_;
    };

    using ScopedAccelerated2dCanvas = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_>;
    using ScopedAcceleratedSmallCanvases = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_>;
    using ScopedAccessibilityAriaVirtualContent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_>;
    using ScopedAccessibilityExposeDisplayNone = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_>;
    using ScopedAccessibilityMinRoleTabbable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_min_role_tabbable_enabled_>;
    using ScopedAccessibilityOSLevelBoldText = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_os_level_bold_text_enabled_>;
    using ScopedAccessibilityProhibitedNames = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_prohibited_names_enabled_>;
    using ScopedAccessibilitySerializationSizeMetrics
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_serialization_size_metrics_enabled_>;
    using ScopedAccessibilityUseAXPositionForDocumentMarkers
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_>;
    using ScopedAddressSpace = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_address_space_enabled_>;
    using ScopedAdInterestGroupAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_>;
    using ScopedAdjustEndOfNextParagraphIfMovedParagraphIsUpdated
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_>;
    using ScopedAdTagging = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_>;
    using ScopedAIPromptAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ai_prompt_api_enabled_>;
    using ScopedAIPromptAPIForExtension = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_extension_enabled_>;
    using ScopedAIPromptAPIForWebPlatform = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_web_platform_enabled_>;
    using ScopedAIRewriterAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ai_rewriter_api_enabled_>;
    using ScopedAISummarizationAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ai_summarization_api_enabled_>;
    using ScopedAIWriterAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ai_writer_api_enabled_>;
    using ScopedAllowContentInitiatedDataUrlNavigations
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_>;
    using ScopedAllowJavaScriptToResetAutofillState
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_allow_java_script_to_reset_autofill_state_enabled_>;
    using ScopedAllowPreloadingWithCSPMetaTag = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_allow_preloading_with_csp_meta_tag_enabled_>;
    using ScopedAllowURNsInIframes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_allow_ur_ns_in_iframes_enabled_>;
    using ScopedAndroidDownloadableFontsMatching = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_>;
    using ScopedAnimationProgressAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_animation_progress_api_enabled_>;
    using ScopedAnimationWorklet = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_>;
    using ScopedAnonymousIframe = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_>;
    using ScopedAOMAriaRelationshipProperties = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_>;
    using ScopedAOMAriaRelationshipPropertiesAriaOwns
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_aria_owns_enabled_>;
    using ScopedAppTitle = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_app_title_enabled_>;
    using ScopedAriaActions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aria_actions_enabled_>;
    using ScopedAriaNotify = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aria_notify_enabled_>;
    using ScopedAriaRowColIndexText = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aria_row_col_index_text_enabled_>;
    using ScopedAtomicMoveAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_atomic_move_api_enabled_>;
    using ScopedAttributionReporting = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_>;
    using ScopedAttributionReportingCrossAppWeb = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_attribution_reporting_cross_app_web_enabled_>;
    using ScopedAttributionReportingInterface = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_attribution_reporting_interface_enabled_>;
    using ScopedAudioContextInterruptedState = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_audio_context_interrupted_state_enabled_>;
    using ScopedAudioContextOnError = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_audio_context_on_error_enabled_>;
    using ScopedAudioContextPlayoutStats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_audio_context_playout_stats_enabled_>;
    using ScopedAudioContextSetSinkId = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_>;
    using ScopedAudioOutputDevices = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_>;
    using ScopedAudioVideoTracks = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_>;
    using ScopedAuraScrollbarUsesNinePatchTrack = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_nine_patch_track_enabled_>;
    using ScopedAuraScrollbarUsesSolidColorThumb = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_solid_color_thumb_enabled_>;
    using ScopedAutoDarkMode = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_>;
    using ScopedAutomationControlled = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_>;
    using ScopedAutoPictureInPictureVideoHeuristics
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_video_heuristics_enabled_>;
    using ScopedBackfaceVisibilityInterop = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_>;
    using ScopedBackForwardCache = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_>;
    using ScopedBackForwardCacheExperimentHTTPHeader
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_>;
    using ScopedBackForwardCacheNotRestoredReasons
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_>;
    using ScopedBackForwardTransitions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_back_forward_transitions_enabled_>;
    using ScopedBackgroundFetch = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_background_fetch_enabled_>;
    using ScopedBarcodeDetector = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_>;
    using ScopedBidiCaretAffinity = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_>;
    using ScopedBlinkExtensionChromeOS = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_>;
    using ScopedBlinkExtensionChromeOSKiosk = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_kiosk_enabled_>;
    using ScopedBlinkExtensionDiagnostics = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_extension_diagnostics_enabled_>;
    using ScopedBlinkExtensionWebView = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_extension_web_view_enabled_>;
    using ScopedBlinkExtensionWebViewMediaIntegrity
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_extension_web_view_media_integrity_enabled_>;
    using ScopedBlinkLifecycleScriptForbidden = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_lifecycle_script_forbidden_enabled_>;
    using ScopedBlinkRuntimeCallStats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_>;
    using ScopedBlockingFocusWithoutUserActivation
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_>;
    using ScopedBoundaryEventDispatchTracksNodeRemoval
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_boundary_event_dispatch_tracks_node_removal_enabled_>;
    using ScopedBoxDecorationBreak = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_box_decoration_break_enabled_>;
    using ScopedBreakIteratorHyphenMinus = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_break_iterator_hyphen_minus_enabled_>;
    using ScopedBrowserVerifiedUserActivationKeyboard
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_>;
    using ScopedBrowserVerifiedUserActivationMouse
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_>;
    using ScopedBufferedBytesConsumerLimitSize = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_buffered_bytes_consumer_limit_size_enabled_>;
    using ScopedBuiltInAIAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_built_in_aiapi_enabled_>;
    using ScopedBypassPepcSecurityForTesting = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_bypass_pepc_security_for_testing_enabled_>;
    using ScopedCacheStorageCodeCacheHint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_>;
    using ScopedCalendarPickerMonthPopupButtonDisabledColor
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_calendar_picker_month_popup_button_disabled_color_enabled_>;
    using ScopedCallExitNodeWithoutLayoutObject = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_call_exit_node_without_layout_object_enabled_>;
    using ScopedCanvas2dCanvasFilter = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_canvas_filter_enabled_>;
    using ScopedCanvas2dGPUTransfer = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_gpu_transfer_enabled_>;
    using ScopedCanvas2dImageChromium = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_>;
    using ScopedCanvas2dLayers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_>;
    using ScopedCanvas2dLayersWithOptions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_layers_with_options_enabled_>;
    using ScopedCanvas2dMesh = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_mesh_enabled_>;
    using ScopedCanvas2dTextMetricsShaping = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_2d_text_metrics_shaping_enabled_>;
    using ScopedCanvasFloatingPoint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_floating_point_enabled_>;
    using ScopedCanvasHDR = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_>;
    using ScopedCanvasImageSmoothing = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_>;
    using ScopedCanvasPlaceElement = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_place_element_enabled_>;
    using ScopedCanvasUsesArcPaintOp = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_canvas_uses_arc_paint_op_enabled_>;
    using ScopedCapabilityDelegationDisplayCaptureRequest
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_capability_delegation_display_capture_request_enabled_>;
    using ScopedCaptureController = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_capture_controller_enabled_>;
    using ScopedCapturedMouseEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_>;
    using ScopedCapturedSurfaceControl = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_>;
    using ScopedCaptureHandle = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_capture_handle_enabled_>;
    using ScopedCaretPositionFromPoint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_caret_position_from_point_enabled_>;
    using ScopedCCTNewRFMPushBehavior = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cct_new_rfm_push_behavior_enabled_>;
    using ScopedCheckIfHighestRootContainsPositionAnchorNode
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_check_if_highest_root_contains_position_anchor_node_enabled_>;
    using ScopedCheckVisibilityExtraProperties = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_check_visibility_extra_properties_enabled_>;
    using ScopedClickToCapturedPointer = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_>;
    using ScopedClipboardItemWithDOMStringSupport = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_clipboard_item_with_dom_string_support_enabled_>;
    using ScopedClipPathRejectEmptyPaths = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_clip_path_reject_empty_paths_enabled_>;
    using ScopedCoalesceSelectionchangeEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_coalesce_selectionchange_event_enabled_>;
    using ScopedCoepReflection = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_>;
    using ScopedCompositeBGColorAnimation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_>;
    using ScopedCompositeBoxShadowAnimation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_>;
    using ScopedCompositeClipPathAnimation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_>;
    using ScopedCompositedAnimationsCancelledAsynchronously
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_composited_animations_cancelled_asynchronously_enabled_>;
    using ScopedCompositedSelectionUpdate = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_>;
    using ScopedCompositionForegroundMarkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_>;
    using ScopedCompressionDictionaryTransport = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_enabled_>;
    using ScopedCompressionDictionaryTransportBackend
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_backend_enabled_>;
    using ScopedComputedAccessibilityInfo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_>;
    using ScopedComputePressure = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_>;
    using ScopedConcurrentViewTransitionsSPA = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_concurrent_view_transitions_spa_enabled_>;
    using ScopedContactsManager = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_>;
    using ScopedContactsManagerExtraProperties = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_>;
    using ScopedContainerTypeNoLayoutContainment = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_container_type_no_layout_containment_enabled_>;
    using ScopedContentIndex = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_content_index_enabled_>;
    using ScopedContextMenu = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_context_menu_enabled_>;
    using ScopedContinueEventTimingRecordingWhenBufferIsFull
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_continue_event_timing_recording_when_buffer_is_full_enabled_>;
    using ScopedControlledFrame = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_controlled_frame_enabled_>;
    using ScopedCookieDeprecationFacilitatedTesting
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cookie_deprecation_facilitated_testing_enabled_>;
    using ScopedCooperativeScheduling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_>;
    using ScopedCoopRestrictProperties = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_coop_restrict_properties_enabled_>;
    using ScopedCorsRFC1918 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_>;
    using ScopedCreateInputShadowTreeDuringLayout = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_create_input_shadow_tree_during_layout_enabled_>;
    using ScopedCredentialManagerReport = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_credential_manager_report_enabled_>;
    using ScopedCrossFramePerformanceTimeline = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cross_frame_performance_timeline_enabled_>;
    using ScopedCSSAccentColorKeyword = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_accent_color_keyword_enabled_>;
    using ScopedCSSAdvancedAttrFunction = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_advanced_attr_function_enabled_>;
    using ScopedCSSAnchorScope = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_anchor_scope_enabled_>;
    using ScopedCSSAnchorSizeInsetsMargins = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_anchor_size_insets_margins_enabled_>;
    using ScopedCSSAtPropertyStringSyntax = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_at_property_string_syntax_enabled_>;
    using ScopedCSSAtRuleCounterStyleImageSymbols
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_>;
    using ScopedCSSAtRuleCounterStyleSpeakAsDescriptor
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_>;
    using ScopedCSSBackgroundClipUnprefix = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_background_clip_unprefix_enabled_>;
    using ScopedCSSCalcSimplificationAndSerialization
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_>;
    using ScopedCSSCalcSizeFunction = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_calc_size_function_enabled_>;
    using ScopedCSSCaretAnimation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_caret_animation_enabled_>;
    using ScopedCSSCascadeCorrectScope = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_cascade_correct_scope_enabled_>;
    using ScopedCSSCaseSensitiveSelector = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_>;
    using ScopedCSSColorContrast = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_>;
    using ScopedCSSColorTypedOM = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_>;
    using ScopedCSSComputedStyleFullPseudoElementParser
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_computed_style_full_pseudo_element_parser_enabled_>;
    using ScopedCSSContentVisibilityImpliesContainIntrinsicSizeAuto
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_>;
    using ScopedCSSCrossFade = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_cross_fade_enabled_>;
    using ScopedCSSCustomStateDeprecatedSyntax = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_custom_state_deprecated_syntax_enabled_>;
    using ScopedCSSCustomStateNewSyntax = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_custom_state_new_syntax_enabled_>;
    using ScopedCSSDynamicRangeLimit = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_dynamic_range_limit_enabled_>;
    using ScopedCSSEnumeratedCustomProperties = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_>;
    using ScopedCSSExponentialFunctions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_exponential_functions_enabled_>;
    using ScopedCSSFlatTreeContainer = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_flat_tree_container_enabled_>;
    using ScopedCSSFontSizeAdjust = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_>;
    using ScopedCSSFunctions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_functions_enabled_>;
    using ScopedCSSGapDecoration = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_gap_decoration_enabled_>;
    using ScopedCSSHexAlphaColor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_>;
    using ScopedCSSInert = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_inert_enabled_>;
    using ScopedCSSInsetAreaProperty = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_inset_area_property_enabled_>;
    using ScopedCSSKeyframesRuleLength = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_keyframes_rule_length_enabled_>;
    using ScopedCSSLayoutAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_>;
    using ScopedCSSLazyParsingFastPath = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_lazy_parsing_fast_path_enabled_>;
    using ScopedCSSLineClamp = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_line_clamp_enabled_>;
    using ScopedCSSLineClampWebkitBoxBlockification
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_line_clamp_webkit_box_blockification_enabled_>;
    using ScopedCSSLogicalOverflow = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_>;
    using ScopedCSSMarkerNestedPseudoElement = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_>;
    using ScopedCSSMasonryLayout = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_masonry_layout_enabled_>;
    using ScopedCSSMixins = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_mixins_enabled_>;
    using ScopedCSSNestedDeclarations = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_nested_declarations_enabled_>;
    using ScopedCSSNestedPseudoElements = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_nested_pseudo_elements_enabled_>;
    using ScopedCSSOverflowContainerQueries = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_overflow_container_queries_enabled_>;
    using ScopedCSSPaintAPIArguments = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_>;
    using ScopedCSSParserIgnoreCharsetForURLs = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_parser_ignore_charset_for_urls_enabled_>;
    using ScopedCSSPartAllowsMoreSelectorsAfter = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_part_allows_more_selectors_after_enabled_>;
    using ScopedCSSPositionAreaValue = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_position_area_value_enabled_>;
    using ScopedCSSPositionStickyStaticScrollPosition
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_>;
    using ScopedCSSProgressNotation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_progress_notation_enabled_>;
    using ScopedCSSPseudoColumn = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_pseudo_column_enabled_>;
    using ScopedCSSPseudoHasSlotted = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_pseudo_has_slotted_enabled_>;
    using ScopedCSSPseudoOpenClosed = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_pseudo_open_closed_enabled_>;
    using ScopedCSSPseudoPlayingPaused = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_>;
    using ScopedCSSPseudoScrollButtons = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_buttons_enabled_>;
    using ScopedCSSPseudoScrollMarkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_markers_enabled_>;
    using ScopedCSSReadingFlow = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_reading_flow_enabled_>;
    using ScopedCSSRelativeColor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_relative_color_enabled_>;
    using ScopedCSSRelativeColorLateResolveAlways = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_relative_color_late_resolve_always_enabled_>;
    using ScopedCSSRelativeColorPreserveNone = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_relative_color_preserve_none_enabled_>;
    using ScopedCSSRelativeColorSupportsCurrentcolor
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_relative_color_supports_currentcolor_enabled_>;
    using ScopedCSSResizeAuto = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_resize_auto_enabled_>;
    using ScopedCSSScrollSnapChangeEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_scroll_snap_change_event_enabled_>;
    using ScopedCSSScrollSnapChangingEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_scroll_snap_changing_event_enabled_>;
    using ScopedCSSScrollSnapEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_scroll_snap_events_enabled_>;
    using ScopedCSSScrollStart = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_scroll_start_enabled_>;
    using ScopedCSSScrollStartTarget = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_scroll_start_target_enabled_>;
    using ScopedCSSScrollStateContainerQueries = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_scroll_state_container_queries_enabled_>;
    using ScopedCSSSelectorFragmentAnchor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_>;
    using ScopedCSSSignRelatedFunctions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_sign_related_functions_enabled_>;
    using ScopedCSSSnapContainerQueries = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_snap_container_queries_enabled_>;
    using ScopedCSSSteppedValueFunctions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_stepped_value_functions_enabled_>;
    using ScopedCSSStickyContainerQueries = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_sticky_container_queries_enabled_>;
    using ScopedCSSSupportsAtRuleFunction = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_supports_at_rule_function_enabled_>;
    using ScopedCSSSupportsForImportRules = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_supports_for_import_rules_enabled_>;
    using ScopedCSSSystemAccentColor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_system_accent_color_enabled_>;
    using ScopedCSSTextAutoSpace = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_text_auto_space_enabled_>;
    using ScopedCSSTextBoxTrim = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_text_box_trim_enabled_>;
    using ScopedCSSTextSpacing = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_text_spacing_enabled_>;
    using ScopedCSSTreeScopedTimelines = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_tree_scoped_timelines_enabled_>;
    using ScopedCSSUserSelectContain = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_user_select_contain_enabled_>;
    using ScopedCSSVideoDynamicRangeMediaQueries = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_>;
    using ScopedCSSViewTransitionAutoName = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_view_transition_auto_name_enabled_>;
    using ScopedCSSViewTransitionClass = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_css_view_transition_class_enabled_>;
    using ScopedCursorAnchorInfoMojoPipe = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_cursor_anchor_info_mojo_pipe_enabled_>;
    using ScopedCustomizableSelect = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_customizable_select_enabled_>;
    using ScopedDatabase = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_database_enabled_>;
    using ScopedDeprecatedRequestAdapterInfo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_deprecated_request_adapter_info_enabled_>;
    using ScopedDeprecateUnloadOptOut = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_deprecate_unload_opt_out_enabled_>;
    using ScopedDesktopCaptureDisableLocalEchoControl
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_>;
    using ScopedDesktopPWAsAdditionalWindowingControls
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_desktop_pw_as_additional_windowing_controls_enabled_>;
    using ScopedDesktopPWAsSubApps = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_>;
    using ScopedDetailsStyling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_details_styling_enabled_>;
    using ScopedDeviceAttributes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_device_attributes_enabled_>;
    using ScopedDeviceOrientationRequestPermission = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_>;
    using ScopedDevicePosture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_device_posture_enabled_>;
    using ScopedDialogCloseWhenOpenRemoved = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dialog_close_when_open_removed_enabled_>;
    using ScopedDialogElementToggleEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dialog_element_toggle_events_enabled_>;
    using ScopedDialogNewFocusBehavior = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dialog_new_focus_behavior_enabled_>;
    using ScopedDigitalGoods = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_digital_goods_enabled_>;
    using ScopedDigitalGoodsV2_1 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_>;
    using ScopedDirAutoFixSlotExclusions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dir_auto_fix_slot_exclusions_enabled_>;
    using ScopedDirectSockets = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_>;
    using ScopedDisableAhemAntialias = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_disable_ahem_antialias_enabled_>;
    using ScopedDisableDifferentOriginSubframeDialogSuppression
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_>;
    using ScopedDisableHardwareNoiseSuppression = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_>;
    using ScopedDisableReduceAcceptLanguage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_disable_reduce_accept_language_enabled_>;
    using ScopedDisableSelectAllForEmptyText = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_disable_select_all_for_empty_text_enabled_>;
    using ScopedDisableThirdPartyStoragePartitioning2
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_disable_third_party_storage_partitioning_2_enabled_>;
    using ScopedDispatchBeforeInputForSpinButtonInteractions
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dispatch_before_input_for_spin_button_interactions_enabled_>;
    using ScopedDispatchHiddenVisibilityTransitions
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dispatch_hidden_visibility_transitions_enabled_>;
    using ScopedDispatchSelectionchangeEventPerElement
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dispatch_selectionchange_event_per_element_enabled_>;
    using ScopedDisplayContentsFocusable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_display_contents_focusable_enabled_>;
    using ScopedDisplayCutoutAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_>;
    using ScopedDocumentCookie = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_cookie_enabled_>;
    using ScopedDocumentDomain = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_domain_enabled_>;
    using ScopedDocumentInstallChunking = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_install_chunking_enabled_>;
    using ScopedDocumentIsolationPolicy = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_isolation_policy_enabled_>;
    using ScopedDocumentOpenOriginAliasRemoval = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_open_origin_alias_removal_enabled_>;
    using ScopedDocumentOpenSandboxInheritanceRemoval
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_open_sandbox_inheritance_removal_enabled_>;
    using ScopedDocumentPictureInPictureAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_>;
    using ScopedDocumentPictureInPicturePreferInitialPlacement
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_>;
    using ScopedDocumentPictureInPictureUserActivation
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_>;
    using ScopedDocumentPolicyDocumentDomain = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_>;
    using ScopedDocumentPolicyExpectNoLinkedResources
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_policy_expect_no_linked_resources_enabled_>;
    using ScopedDocumentPolicyIncludeJSCallStacksInCrashReports
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_policy_include_js_call_stacks_in_crash_reports_enabled_>;
    using ScopedDocumentPolicyNegotiation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_>;
    using ScopedDocumentPolicySyncXHR = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_>;
    using ScopedDocumentRenderBlocking = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_render_blocking_enabled_>;
    using ScopedDocumentWrite = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_document_write_enabled_>;
    using ScopedDOMPartsAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dom_parts_api_enabled_>;
    using ScopedDOMPartsAPIMinimal = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dom_parts_api_minimal_enabled_>;
    using ScopedDropUrlAsPlainTextInPlainTextOnlyEditablePosition
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_>;
    using ScopedDynamicSafeAreaInsets = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_enabled_>;
    using ScopedDynamicSafeAreaInsetsOnScroll = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_on_scroll_enabled_>;
    using ScopedElementCapture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_element_capture_enabled_>;
    using ScopedElementGetInnerHTML = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_element_get_inner_html_enabled_>;
    using ScopedEnforceAnonymityExposure = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_enforce_anonymity_exposure_enabled_>;
    using ScopedEscapeLtGtInAttributes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_escape_lt_gt_in_attributes_enabled_>;
    using ScopedEventTimingHandleKeyboardEventSimulatedClick
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_event_timing_handle_keyboard_event_simulated_click_enabled_>;
    using ScopedEventTimingInteractionCount = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_event_timing_interaction_count_enabled_>;
    using ScopedEventTimingSelectionAutoScrollNoInteractionId
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_event_timing_selection_auto_scroll_no_interaction_id_enabled_>;
    using ScopedEventTimingTapStopScrollNoInteractionId
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_event_timing_tap_stop_scroll_no_interaction_id_enabled_>;
    using ScopedExcludeTransparentTextsFromBeingLcpEligible
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_exclude_transparent_texts_from_being_lcp_eligible_enabled_>;
    using ScopedExperimentalContentSecurityPolicyFeatures
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_>;
    using ScopedExperimentalJSProfilerMarkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_>;
    using ScopedExperimentalMachineLearningNeuralNetwork
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_experimental_machine_learning_neural_network_enabled_>;
    using ScopedExperimentalPolicies = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_>;
    using ScopedExposeCoarsenedRenderTime = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_expose_coarsened_render_time_enabled_>;
    using ScopedExposeRenderTimeNonTaoDelayedImage
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_expose_render_time_non_tao_delayed_image_enabled_>;
    using ScopedExtendedTextMetrics = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_>;
    using ScopedEyeDropperAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_>;
    using ScopedFaceDetector = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_face_detector_enabled_>;
    using ScopedFastNonCompositedScrollHitTest = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fast_non_composited_scroll_hit_test_enabled_>;
    using ScopedFastPathSingleSelectorExactMatch = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fast_path_single_selector_exact_match_enabled_>;
    using ScopedFastPositionIterator = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fast_position_iterator_enabled_>;
    using ScopedFedCm = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_enabled_>;
    using ScopedFedCmAuthz = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_authz_enabled_>;
    using ScopedFedCmAutoSelectedFlag = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_auto_selected_flag_enabled_>;
    using ScopedFedCmButtonMode = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_button_mode_enabled_>;
    using ScopedFedCmDisconnect = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_disconnect_enabled_>;
    using ScopedFedCmDomainHint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_domain_hint_enabled_>;
    using ScopedFedCmError = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_error_enabled_>;
    using ScopedFedCmIdPRegistration = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_id_p_registration_enabled_>;
    using ScopedFedCmIdpSigninStatus = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_>;
    using ScopedFedCmMultipleIdentityProviders = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_>;
    using ScopedFedCmSelectiveDisclosure = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_selective_disclosure_enabled_>;
    using ScopedFedCmWithStorageAccessAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fed_cm_with_storage_access_api_enabled_>;
    using ScopedFencedFrames = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_>;
    using ScopedFencedFramesAPIChanges = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fenced_frames_api_changes_enabled_>;
    using ScopedFencedFramesDefaultMode = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fenced_frames_default_mode_enabled_>;
    using ScopedFencedFramesLocalUnpartitionedDataAccess
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fenced_frames_local_unpartitioned_data_access_enabled_>;
    using ScopedFetchBodyBytes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fetch_body_bytes_enabled_>;
    using ScopedFetchLaterAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fetch_later_api_enabled_>;
    using ScopedFetchUploadStreaming = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_>;
    using ScopedFileHandling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_handling_enabled_>;
    using ScopedFileHandlingIcons = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_>;
    using ScopedFileSystem = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_enabled_>;
    using ScopedFileSystemAccess = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_access_enabled_>;
    using ScopedFileSystemAccessAPIExperimental = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_>;
    using ScopedFileSystemAccessGetCloudIdentifiers
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_>;
    using ScopedFileSystemAccessLocal = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_>;
    using ScopedFileSystemAccessLockingScheme = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_access_locking_scheme_enabled_>;
    using ScopedFileSystemAccessOriginPrivate = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_>;
    using ScopedFileSystemObserver = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_observer_enabled_>;
    using ScopedFileSystemObserverUnobserve = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_file_system_observer_unobserve_enabled_>;
    using ScopedFindDecomposedInShortText = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_find_decomposed_in_short_text_enabled_>;
    using ScopedFindRubyInPage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_find_ruby_in_page_enabled_>;
    using ScopedFindTextInReadonlyTextInput = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_find_text_in_readonly_text_input_enabled_>;
    using ScopedFindTextSkipCollapsedText = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_find_text_skip_collapsed_text_enabled_>;
    using ScopedFledge = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_enabled_>;
    using ScopedFledgeAuctionDealSupport = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_auction_deal_support_enabled_>;
    using ScopedFledgeBiddingAndAuctionServerAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_bidding_and_auction_server_api_enabled_>;
    using ScopedFledgeCustomMaxAuctionAdComponents
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_custom_max_auction_ad_components_enabled_>;
    using ScopedFledgeDeprecatedRenderURLReplacements
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_deprecated_render_url_replacements_enabled_>;
    using ScopedFledgeDirectFromSellerSignalsHeaderAdSlot
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_direct_from_seller_signals_header_ad_slot_enabled_>;
    using ScopedFledgeMultiBid = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_multi_bid_enabled_>;
    using ScopedFledgeRealTimeReporting = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_real_time_reporting_enabled_>;
    using ScopedFledgeReportingTimeout = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_reporting_timeout_enabled_>;
    using ScopedFledgeSellerNonce = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_seller_nonce_enabled_>;
    using ScopedFledgeTrustedSignalsKVv2Support = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fledge_trusted_signals_k_vv_2_support_enabled_>;
    using ScopedFluentOverlayScrollbars = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fluent_overlay_scrollbars_enabled_>;
    using ScopedFluentScrollbars = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_>;
    using ScopedFluentScrollbarUsesNinePatchTrack = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fluent_scrollbar_uses_nine_patch_track_enabled_>;
    using ScopedFocusgroup = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_focusgroup_enabled_>;
    using ScopedFontAccess = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_access_enabled_>;
    using ScopedFontationsFontBackend = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fontations_font_backend_enabled_>;
    using ScopedFontationsForSelectedFormats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fontations_for_selected_formats_enabled_>;
    using ScopedFontFamilyPostscriptMatchingCTMigration
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_family_postscript_matching_ct_migration_enabled_>;
    using ScopedFontFamilyStyleMatchingCTMigration
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_family_style_matching_ct_migration_enabled_>;
    using ScopedFontPresentWin = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_present_win_enabled_>;
    using ScopedFontSrcLocalMatching = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_>;
    using ScopedFontSystemFallbackNotoCjk = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_system_fallback_noto_cjk_enabled_>;
    using ScopedFontVariantEmoji = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_variant_emoji_enabled_>;
    using ScopedFontVariationSequences = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_font_variation_sequences_enabled_>;
    using ScopedForcedColors = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_forced_colors_enabled_>;
    using ScopedForcedColorsPreserveParentColor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_>;
    using ScopedForceEagerMeasureMemory = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_>;
    using ScopedForceReduceMotion = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_>;
    using ScopedForceTallerSelectPopup = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_>;
    using ScopedFormControlRestoreStateIfAutocompleteOff
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_form_control_restore_state_if_autocomplete_off_enabled_>;
    using ScopedFormControlsVerticalWritingModeDirectionSupport
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_form_controls_vertical_writing_mode_direction_support_enabled_>;
    using ScopedFractionalScrollOffsets = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_>;
    using ScopedFreezeFramesOnVisibility = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_>;
    using ScopedGamepadMultitouch = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_gamepad_multitouch_enabled_>;
    using ScopedGetAllScreensMedia = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_get_all_screens_media_enabled_>;
    using ScopedGetDisplayMedia = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_get_display_media_enabled_>;
    using ScopedGetDisplayMediaRequiresUserActivation
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_get_display_media_requires_user_activation_enabled_>;
    using ScopedGroupEffect = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_group_effect_enabled_>;
    using ScopedHandleSelectionChangeOnDeletingEmptyElement
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_handle_selection_change_on_deleting_empty_element_enabled_>;
    using ScopedHandwritingRecognition = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_>;
    using ScopedHangingWhitespaceDoesNotDependOnAlignment
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_hanging_whitespace_does_not_depend_on_alignment_enabled_>;
    using ScopedHasUAVisualTransition = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_has_ua_visual_transition_enabled_>;
    using ScopedHighlightInheritance = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_>;
    using ScopedHighlightPointerEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_>;
    using ScopedHighlightsFromPoint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_highlights_from_point_enabled_>;
    using ScopedHitTestOpaqueness = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_enabled_>;
    using ScopedHitTestOpaquenessOmitLineBox = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_omit_line_box_enabled_>;
    using ScopedHrefTranslate = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_href_translate_enabled_>;
    using ScopedHTMLAnchorAttribute = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_anchor_attribute_enabled_>;
    using ScopedHTMLDialogLightDismiss = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_dialog_light_dismiss_enabled_>;
    using ScopedHTMLEmbedElementNotForceLayout = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_embed_element_not_force_layout_enabled_>;
    using ScopedHTMLInterestTargetAttribute = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_interest_target_attribute_enabled_>;
    using ScopedHTMLInvokeActionsV2 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_invoke_actions_v_2_enabled_>;
    using ScopedHTMLInvokeTargetAttribute = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_invoke_target_attribute_enabled_>;
    using ScopedHTMLObjectElementFallbackDetachContentFrame
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_object_element_fallback_detach_content_frame_enabled_>;
    using ScopedHTMLParserYieldAndDelayOftenForTesting
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_parser_yield_and_delay_often_for_testing_enabled_>;
    using ScopedHTMLPopoverActionHover = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_popover_action_hover_enabled_>;
    using ScopedHTMLPopoverHint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_popover_hint_enabled_>;
    using ScopedHTMLSelectElementShowPicker = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_html_select_element_show_picker_enabled_>;
    using ScopedImplicitRootScroller = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_>;
    using ScopedImportAttributesDisallowUnknownKeys
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_import_attributes_disallow_unknown_keys_enabled_>;
    using ScopedImportMapIntegrity = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_import_map_integrity_enabled_>;
    using ScopedIncomingCallNotifications = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_incoming_call_notifications_enabled_>;
    using ScopedIncrementLocalSurfaceIdForMainframeSameDocNavigation
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_>;
    using ScopedIndexedDbGetAllRecords = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_indexed_db_get_all_records_enabled_>;
    using ScopedInertElementNonEditable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inert_element_non_editable_enabled_>;
    using ScopedInertElementNonSearchable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inert_element_non_searchable_enabled_>;
    using ScopedInfiniteCullRect = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_>;
    using ScopedInheritUserModifyWithoutContenteditable
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inherit_user_modify_without_contenteditable_enabled_>;
    using ScopedInitialLetterRaiseBySpecified = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_initial_letter_raise_by_specified_enabled_>;
    using ScopedInlineBlockInSameLine = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inline_block_in_same_line_enabled_>;
    using ScopedInnerHTMLParserFastpathLogFailure = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inner_html_parser_fastpath_log_failure_enabled_>;
    using ScopedInputClosesSelect = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_input_closes_select_enabled_>;
    using ScopedInputMultipleFieldsUI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_>;
    using ScopedInsertBlockquoteBeforeOuterBlock = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_insert_blockquote_before_outer_block_enabled_>;
    using ScopedInsertLineBreakIfPhrasingContent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_>;
    using ScopedInspectorGhostRules = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inspector_ghost_rules_enabled_>;
    using ScopedInstalledApp = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_installed_app_enabled_>;
    using ScopedInstallOnDeviceSpeechRecognition = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_install_on_device_speech_recognition_enabled_>;
    using ScopedInterestGroupsInSharedStorageWorklet
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_interest_groups_in_shared_storage_worklet_enabled_>;
    using ScopedInteroperablePrivateAttribution = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_interoperable_private_attribution_enabled_>;
    using ScopedIntersectionObserverScrollMargin = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_intersection_observer_scroll_margin_enabled_>;
    using ScopedInvertedColors = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_inverted_colors_enabled_>;
    using ScopedInvisibleSVGAnimationThrottling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_invisible_svg_animation_throttling_enabled_>;
    using ScopedJavaScriptCompileHintsMagicAlwaysRuntime
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_always_runtime_enabled_>;
    using ScopedJavaScriptCompileHintsMagicRuntime
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_runtime_enabled_>;
    using ScopedKeepCSSTargetAfterReattach = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_keep_css_target_after_reattach_enabled_>;
    using ScopedKeyboardAccessibleTooltip = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_>;
    using ScopedKeyboardFocusableScrollers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_>;
    using ScopedKeyboardFocusableScrollersOptOut = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_opt_out_enabled_>;
    using ScopedLabelAndDelegatesFocusNewHandling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_label_and_delegates_focus_new_handling_enabled_>;
    using ScopedLangAttributeAwareFormControlUI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_>;
    using ScopedLanguageDetectionAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_language_detection_api_enabled_>;
    using ScopedLayoutFlexNewRowAlgorithmV3 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_layout_flex_new_row_algorithm_v_3_enabled_>;
    using ScopedLayoutIgnoreMarginsForSticky = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_layout_ignore_margins_for_sticky_enabled_>;
    using ScopedLayoutJustifySelfForBlocks = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_layout_justify_self_for_blocks_enabled_>;
    using ScopedLayoutNGShapeCache = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_layout_ng_shape_cache_enabled_>;
    using ScopedLayoutStretch = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_layout_stretch_enabled_>;
    using ScopedLazyInitializeMediaControls = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_>;
    using ScopedLazyLoadScrollMargin = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_enabled_>;
    using ScopedLazyLoadScrollMarginIframe = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_iframe_enabled_>;
    using ScopedLCPAnimatedImagesWebExposed = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_>;
    using ScopedLegacyWindowsDWriteFontFallback = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_>;
    using ScopedLimitThirdPartyCookies = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_limit_third_party_cookies_enabled_>;
    using ScopedLineBoxBelowLeadingFloats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_line_box_below_leading_floats_enabled_>;
    using ScopedListItemWithCounterSetNotSetExplicitValue
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_list_item_with_counter_set_not_set_explicit_value_enabled_>;
    using ScopedLockedMode = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_locked_mode_enabled_>;
    using ScopedLongAnimationFrameTiming = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_long_animation_frame_timing_enabled_>;
    using ScopedLongPressLinkSelectText = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_long_press_link_select_text_enabled_>;
    using ScopedLongTaskFromLongAnimationFrame = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_long_task_from_long_animation_frame_enabled_>;
    using ScopedMachineLearningNeuralNetwork = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_>;
    using ScopedManagedConfiguration = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_>;
    using ScopedMeasureMemory = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_measure_memory_enabled_>;
    using ScopedMediaCapabilitiesDynamicRange = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_>;
    using ScopedMediaCapabilitiesEncodingInfo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_>;
    using ScopedMediaCapabilitiesSpatialAudio = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_>;
    using ScopedMediaCapture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capture_enabled_>;
    using ScopedMediaCaptureBackgroundBlur = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_>;
    using ScopedMediaCaptureCameraControls = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capture_camera_controls_enabled_>;
    using ScopedMediaCaptureConfigurationChange = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capture_configuration_change_enabled_>;
    using ScopedMediaCaptureVoiceIsolation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_capture_voice_isolation_enabled_>;
    using ScopedMediaCastOverlayButton = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_>;
    using ScopedMediaControlsExpandGesture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_>;
    using ScopedMediaControlsOverlayPlayButton = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_>;
    using ScopedMediaElementVolumeGreaterThanOne = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_>;
    using ScopedMediaEngagementBypassAutoplayPolicies
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_>;
    using ScopedMediaLatencyHint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_>;
    using ScopedMediaPlaybackWhileNotVisiblePermissionPolicy
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_playback_while_not_visible_permission_policy_enabled_>;
    using ScopedMediaPreviewsOptOut = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_previews_opt_out_enabled_>;
    using ScopedMediaQueryNavigationControls = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_>;
    using ScopedMediaRecorderUseMediaVideoEncoder = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_recorder_use_media_video_encoder_enabled_>;
    using ScopedMediaSession = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_session_enabled_>;
    using ScopedMediaSessionChapterInformation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_session_chapter_information_enabled_>;
    using ScopedMediaSessionEnterPictureInPicture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_session_enter_picture_in_picture_enabled_>;
    using ScopedMediaSourceExperimental = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_>;
    using ScopedMediaSourceExtensionsForWebCodecs = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_>;
    using ScopedMediaSourceNewAbortAndDuration = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_>;
    using ScopedMediaStreamTrackTransfer = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_>;
    using ScopedMediaStreamTrackWebSpeech = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_media_stream_track_web_speech_enabled_>;
    using ScopedMessagePortCloseEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_message_port_close_event_enabled_>;
    using ScopedMetaRefreshNoFractional = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_meta_refresh_no_fractional_enabled_>;
    using ScopedMeterAppearanceNoneFallbackStyle = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_meter_appearance_none_fallback_style_enabled_>;
    using ScopedMeterDevolveAppearance = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_meter_devolve_appearance_enabled_>;
    using ScopedMiddleClickAutoscroll = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_>;
    using ScopedMinimimalResourceRequestPrepBeforeCacheLookup
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_minimimal_resource_request_prep_before_cache_lookup_enabled_>;
    using ScopedMobileLayoutTheme = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_>;
    using ScopedModifyParagraphCrossEditingoundary = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_modify_paragraph_cross_editingoundary_enabled_>;
    using ScopedMojoJS = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_mojo_js_enabled_>;
    using ScopedMojoJSTest = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_mojo_js_test_enabled_>;
    using ScopedMoveEndingSelectionToListChild = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_move_ending_selection_to_list_child_enabled_>;
    using ScopedMoveToParagraphStartOrEndSkipsNonEditable
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_move_to_paragraph_start_or_end_skips_non_editable_enabled_>;
    using ScopedMultipleImportMaps = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_multiple_import_maps_enabled_>;
    using ScopedMultiSelectDeselectWhenOnlyOption = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_multi_select_deselect_when_only_option_enabled_>;
    using ScopedMultiSmoothScrollIntoView = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_multi_smooth_scroll_into_view_enabled_>;
    using ScopedMutationEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_mutation_events_enabled_>;
    using ScopedMutationEventsSpecialTrialMessage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_mutation_events_special_trial_message_enabled_>;
    using ScopedNavigateEventCommitBehavior = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_navigate_event_commit_behavior_enabled_>;
    using ScopedNavigateEventSourceElement = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_navigate_event_source_element_enabled_>;
    using ScopedNavigationActivation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_navigation_activation_enabled_>;
    using ScopedNavigationId = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_navigation_id_enabled_>;
    using ScopedNavigatorContentUtils = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_>;
    using ScopedNestedViewTransition = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_nested_view_transition_enabled_>;
    using ScopedNetInfoConstantType = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_net_info_constant_type_enabled_>;
    using ScopedNetInfoDownlinkMax = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_>;
    using ScopedNewGetFocusableAreaBehavior = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_new_get_focusable_area_behavior_enabled_>;
    using ScopedNoIdleEncodingForWebTests = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_>;
    using ScopedNoIncreasingEndOffsetOnSplittingTextNodes
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_no_increasing_end_offset_on_splitting_text_nodes_enabled_>;
    using ScopedNonEmptyBlockquotesOnOutdenting = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_non_empty_blockquotes_on_outdenting_enabled_>;
    using ScopedNonNullInputEventDataForTextArea = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_non_null_input_event_data_for_text_area_enabled_>;
    using ScopedNonStandardAppearanceValueSliderVertical
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_non_standard_appearance_value_slider_vertical_enabled_>;
    using ScopedNotificationConstructor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_>;
    using ScopedNotificationContentImage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_>;
    using ScopedNotifications = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_notifications_enabled_>;
    using ScopedNotificationTriggers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_>;
    using ScopedObservableAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_observable_api_enabled_>;
    using ScopedOffMainThreadCSSPaint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_>;
    using ScopedOffscreenCanvasCommit = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_>;
    using ScopedOmitBlurEventOnElementRemoval = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_omit_blur_event_on_element_removal_enabled_>;
    using ScopedOnDeviceChange = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_on_device_change_enabled_>;
    using ScopedOnDeviceWebSpeechAvailable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_on_device_web_speech_available_enabled_>;
    using ScopedOrientationEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_orientation_event_enabled_>;
    using ScopedOriginIsolationHeader = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_>;
    using ScopedOriginPolicy = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_policy_enabled_>;
    using ScopedOriginTrialsSampleAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_>;
    using ScopedOriginTrialsSampleAPIBrowserReadWrite
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_browser_read_write_enabled_>;
    using ScopedOriginTrialsSampleAPIDependent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_>;
    using ScopedOriginTrialsSampleAPIDeprecation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_>;
    using ScopedOriginTrialsSampleAPIExpiryGracePeriod
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_>;
    using ScopedOriginTrialsSampleAPIExpiryGracePeriodThirdParty
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_>;
    using ScopedOriginTrialsSampleAPIImplied = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_>;
    using ScopedOriginTrialsSampleAPIInvalidOS = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_>;
    using ScopedOriginTrialsSampleAPINavigation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_>;
    using ScopedOriginTrialsSampleAPIPersistentExpiryGracePeriod
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_>;
    using ScopedOriginTrialsSampleAPIPersistentFeature
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_>;
    using ScopedOriginTrialsSampleAPIPersistentInvalidOS
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_invalid_os_enabled_>;
    using ScopedOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_>;
    using ScopedOriginTrialsSampleAPIThirdParty = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_>;
    using ScopedOverscrollCustomization = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_>;
    using ScopedPageFreezeOptIn = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_>;
    using ScopedPageFreezeOptOut = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_>;
    using ScopedPageMarginBoxes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_page_margin_boxes_enabled_>;
    using ScopedPagePopup = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_page_popup_enabled_>;
    using ScopedPageRevealEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_page_reveal_event_enabled_>;
    using ScopedPageSwapEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_page_swap_event_enabled_>;
    using ScopedPaintHighlightsForFirstLetter = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_paint_highlights_for_first_letter_enabled_>;
    using ScopedPaintHoldingForIframes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_paint_holding_for_iframes_enabled_>;
    using ScopedPaintHoldingForLocalIframes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_paint_holding_for_local_iframes_enabled_>;
    using ScopedPaintUnderInvalidationChecking = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_>;
    using ScopedParakeet = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_parakeet_enabled_>;
    using ScopedPartitionedPopins = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_partitioned_popins_enabled_>;
    using ScopedPartitionVisitedLinkDatabaseWithSelfLinks
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_>;
    using ScopedPasswordReveal = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_password_reveal_enabled_>;
    using ScopedPaymentApp = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_payment_app_enabled_>;
    using ScopedPaymentInstruments = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_payment_instruments_enabled_>;
    using ScopedPaymentLinkDetection = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_payment_link_detection_enabled_>;
    using ScopedPaymentMethodChangeEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_>;
    using ScopedPaymentRequest = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_payment_request_enabled_>;
    using ScopedPercentBasedScrolling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_>;
    using ScopedPerformanceManagerInstrumentation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_>;
    using ScopedPerformanceMarkFeatureUsage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_performance_mark_feature_usage_enabled_>;
    using ScopedPerformanceNavigateSystemEntropy = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_performance_navigate_system_entropy_enabled_>;
    using ScopedPerformanceNavigationTimingConfidence
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_performance_navigation_timing_confidence_enabled_>;
    using ScopedPeriodicBackgroundSync = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_>;
    using ScopedPerMethodCanMakePaymentQuota = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_>;
    using ScopedPermissionElement = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_permission_element_enabled_>;
    using ScopedPermissions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_permissions_enabled_>;
    using ScopedPermissionsRequestRevoke = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_>;
    using ScopedPNaCl = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_>;
    using ScopedPointerEventDeviceId = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_pointer_event_device_id_enabled_>;
    using ScopedPointerEventTargetsInEventLists = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_pointer_event_targets_in_event_lists_enabled_>;
    using ScopedPopoverAnchorRelationships = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_popover_anchor_relationships_enabled_>;
    using ScopedPopoverDialogNewFocusBehavior = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_popover_dialog_new_focus_behavior_enabled_>;
    using ScopedPositionOutsideTabSpanCheckSiblingNode
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_position_outside_tab_span_check_sibling_node_enabled_>;
    using ScopedPreciseMemoryInfo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_>;
    using ScopedPreferDefaultScrollbarStyles = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_prefer_default_scrollbar_styles_enabled_>;
    using ScopedPreferNonCompositedScrolling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_>;
    using ScopedPrefersReducedData = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_>;
    using ScopedPrefixedVideoFullscreen = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_>;
    using ScopedPrerender2 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_prerender_2_enabled_>;
    using ScopedPresentation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_presentation_enabled_>;
    using ScopedPreserveFollowingBlockStylesDuringBlockMerge
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_preserve_following_block_styles_during_block_merge_enabled_>;
    using ScopedPreventUndoIfNotEditable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_prevent_undo_if_not_editable_enabled_>;
    using ScopedPrivateAggregationApiFilteringIds = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_aggregation_api_filtering_ids_enabled_>;
    using ScopedPrivateAggregationAuctionReportBuyerDebugModeConfig
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_>;
    using ScopedPrivateNetworkAccessNonSecureContextsAllowed
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_>;
    using ScopedPrivateNetworkAccessNullIpAddress = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_network_access_null_ip_address_enabled_>;
    using ScopedPrivateNetworkAccessPermissionPrompt
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_>;
    using ScopedPrivateStateTokens = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_state_tokens_enabled_>;
    using ScopedPrivateStateTokensAlwaysAllowIssuance
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_private_state_tokens_always_allow_issuance_enabled_>;
    using ScopedProtectedOriginTrialsSampleAPI
        = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_protected_origin_trials_sample_api_enabled_>;
    using ScopedProtectedOriginTrialsSampleAPIDependent
        = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_protected_origin_trials_sample_api_dependent_enabled_>;
    using ScopedProtectedOriginTrialsSampleAPIImplied
        = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_protected_origin_trials_sample_api_implied_enabled_>;
    using ScopedPseudoElementsCorrectInGetComputedStyle
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_pseudo_elements_correct_in_get_computed_style_enabled_>;
    using ScopedPseudoElementsFocusable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_pseudo_elements_focusable_enabled_>;
    using ScopedPushMessageDataBytes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_push_message_data_bytes_enabled_>;
    using ScopedPushMessaging = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_push_messaging_enabled_>;
    using ScopedPushMessagingSubscriptionChange = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_>;
    using ScopedQuickIntensiveWakeUpThrottlingAfterLoading
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_>;
    using ScopedRasterInducingScroll = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_raster_inducing_scroll_enabled_>;
    using ScopedReadableStreamAsyncIterable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_readable_stream_async_iterable_enabled_>;
    using ScopedReduceAcceptLanguage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reduce_accept_language_enabled_>;
    using ScopedReduceCookieIPCs = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reduce_cookie_ip_cs_enabled_>;
    using ScopedReduceUserAgentAndroidVersionDeviceModel
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_>;
    using ScopedReduceUserAgentMinorVersion = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_>;
    using ScopedReduceUserAgentPlatformOsCpu = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_>;
    using ScopedRegionCapture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_region_capture_enabled_>;
    using ScopedRelOpenerBcgDependencyHint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rel_opener_bcg_dependency_hint_enabled_>;
    using ScopedRemotePlayback = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remote_playback_enabled_>;
    using ScopedRemotePlaybackBackend = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_>;
    using ScopedRemoveCollapsedPlaceholder = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remove_collapsed_placeholder_enabled_>;
    using ScopedRemoveDanglingMarkupInTarget = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remove_dangling_markup_in_target_enabled_>;
    using ScopedRemoveDataUrlInSvgUse = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remove_data_url_in_svg_use_enabled_>;
    using ScopedRemoveNodeHavingChildrenIfFullySelected
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remove_node_having_children_if_fully_selected_enabled_>;
    using ScopedRemoveVisibleSelectionInDOMSelection
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_remove_visible_selection_in_dom_selection_enabled_>;
    using ScopedRenderBlockingInlineModuleScript = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_render_blocking_inline_module_script_enabled_>;
    using ScopedRenderBlockingStatus = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_>;
    using ScopedRenderPriorityAttribute = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_>;
    using ScopedReportEventTimingAtVisibilityChange
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_report_event_timing_at_visibility_change_enabled_>;
    using ScopedReportVisibleLineBounds = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_>;
    using ScopedResetInputTypeToNoneBeforeCharacterInput
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reset_input_type_to_none_before_character_input_enabled_>;
    using ScopedResourceTimingContentType = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_resource_timing_content_type_enabled_>;
    using ScopedResourceTimingFinalResponseHeadersStart
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_resource_timing_final_response_headers_start_enabled_>;
    using ScopedResourceTimingUseCORSForBodySizes
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_resource_timing_use_cors_for_body_sizes_enabled_>;
    using ScopedRestrictGamepadAccess = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_>;
    using ScopedReuseShapeResultsByFonts = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_reuse_shape_results_by_fonts_enabled_>;
    using ScopedRewindFloats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rewind_floats_enabled_>;
    using ScopedRootElementWithPlaceHolderAfterDeletingSelection
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_root_element_with_place_holder_after_deleting_selection_enabled_>;
    using ScopedRtcAudioJitterBufferMaxPackets = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_>;
    using ScopedRTCDataChannelPriority = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_data_channel_priority_enabled_>;
    using ScopedRTCEncodedAudioFrameAbsCaptureTime
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_encoded_audio_frame_abs_capture_time_enabled_>;
    using ScopedRTCEncodedFrameSetMetadata = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_encoded_frame_set_metadata_enabled_>;
    using ScopedRTCEncodedVideoFrameAdditionalMetadata
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_encoded_video_frame_additional_metadata_enabled_>;
    using ScopedRTCJitterBufferTarget = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_jitter_buffer_target_enabled_>;
    using ScopedRTCLegacyCallbackBasedGetStats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_legacy_callback_based_get_stats_enabled_>;
    using ScopedRTCRtpEncodingParametersCodec = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_rtp_encoding_parameters_codec_enabled_>;
    using ScopedRTCRtpScaleResolutionDownTo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_rtp_scale_resolution_down_to_enabled_>;
    using ScopedRTCRtpScriptTransform = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_rtp_script_transform_enabled_>;
    using ScopedRTCRtpTransport = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_rtp_transport_enabled_>;
    using ScopedRTCStatsRelativePacketArrivalDelay
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_>;
    using ScopedRTCSvcScalabilityMode = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_>;
    using ScopedRubyShortHeuristics = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_ruby_short_heuristics_enabled_>;
    using ScopedSanitizerAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_>;
    using ScopedSchedulerYield = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scheduler_yield_enabled_>;
    using ScopedScheduleSelectionChangeOnBackspace
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_>;
    using ScopedScopedCustomElementRegistry = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_>;
    using ScopedScriptedSpeechRecognition = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_>;
    using ScopedScriptedSpeechSynthesis = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_>;
    using ScopedScrollbarColor = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scrollbar_color_enabled_>;
    using ScopedScrollbarWidth = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_>;
    using ScopedScrollEndEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_>;
    using ScopedScrollIntoViewRootFrameViewportBugFix
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scroll_into_view_root_frame_viewport_bug_fix_enabled_>;
    using ScopedScrollTimeline = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_>;
    using ScopedScrollTimelineCurrentTime = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scroll_timeline_current_time_enabled_>;
    using ScopedScrollTopLeftInterop = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_>;
    using ScopedSearchTextHighlightPseudo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_search_text_highlight_pseudo_enabled_>;
    using ScopedSecurePaymentConfirmation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_>;
    using ScopedSecurePaymentConfirmationDebug = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_>;
    using ScopedSecurePaymentConfirmationNetworkAndIssuerIcons
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_network_and_issuer_icons_enabled_>;
    using ScopedSecurePaymentConfirmationOptOut = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_>;
    using ScopedSelectAudioOutput = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_>;
    using ScopedSelectedcontentelementAttribute = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_selectedcontentelement_attribute_enabled_>;
    using ScopedSelectionAcrossShadowDOM = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_selection_across_shadow_dom_enabled_>;
    using ScopedSelectionIsCollapsedShadowDOMSupport
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_selection_is_collapsed_shadow_dom_support_enabled_>;
    using ScopedSelectionOnShadowDOMWithDelegatesFocus
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_selection_on_shadow_dom_with_delegates_focus_enabled_>;
    using ScopedSelectOptionAccessibilityTargetSize
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_select_option_accessibility_target_size_enabled_>;
    using ScopedSelectParserRelaxation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_select_parser_relaxation_enabled_>;
    using ScopedSelectPopupLessUpdates = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_select_popup_less_updates_enabled_>;
    using ScopedSendBeaconThrowForBlobWithNonSimpleType
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_>;
    using ScopedSensorExtraClasses = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_>;
    using ScopedSerial = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_serial_enabled_>;
    using ScopedSerializeViewTransitionStateInSPA = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_serialize_view_transition_state_in_spa_enabled_>;
    using ScopedSerialPortConnected = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_>;
    using ScopedServiceWorkerClientLifecycleState = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_>;
    using ScopedServiceWorkerStaticRouter = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_service_worker_static_router_enabled_>;
    using ScopedServiceWorkerStaticRouterTimingInfo
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_service_worker_static_router_timing_info_enabled_>;
    using ScopedSetSequentialFocusStartingPoint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_set_sequential_focus_starting_point_enabled_>;
    using ScopedShadowRootReferenceTarget = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shadow_root_reference_target_enabled_>;
    using ScopedShapeOutsideWritingModeFix = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shape_outside_writing_mode_fix_enabled_>;
    using ScopedShapeResultCachedPreviousSafeToBreakOffset
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shape_result_cached_previous_safe_to_break_offset_enabled_>;
    using ScopedSharedArrayBuffer = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_>;
    using ScopedSharedArrayBufferOnDesktop = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_>;
    using ScopedSharedArrayBufferUnrestrictedAccessAllowed
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_>;
    using ScopedSharedAutofill = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_>;
    using ScopedSharedStorageAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_>;
    using ScopedSharedStorageAPIM118 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_storage_api_m_118_enabled_>;
    using ScopedSharedStorageAPIM125 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_storage_api_m_125_enabled_>;
    using ScopedSharedStorageWebLocks = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_storage_web_locks_enabled_>;
    using ScopedSharedWorker = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_shared_worker_enabled_>;
    using ScopedSidewaysWritingModes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_sideways_writing_modes_enabled_>;
    using ScopedSignatureBasedIntegrity = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_>;
    using ScopedSiteInitiatedMirroring = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_>;
    using ScopedSkipAd = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_skip_ad_enabled_>;
    using ScopedSkipPreloadScanning = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_skip_preload_scanning_enabled_>;
    using ScopedSkipTemporaryDocumentFragment = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_skip_temporary_document_fragment_enabled_>;
    using ScopedSkipTouchEventFilter = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_>;
    using ScopedSmartCard = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_smart_card_enabled_>;
    using ScopedSmartZoom = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_>;
    using ScopedSmilAutoSuspendOnLag = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_smil_auto_suspend_on_lag_enabled_>;
    using ScopedSoftNavigationDetection = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_soft_navigation_detection_enabled_>;
    using ScopedSoftNavigationHeuristics = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_>;
    using ScopedSoftNavigationHeuristicsExposeFPAndFCP
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_>;
    using ScopedSpeakerSelection = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_speaker_selection_enabled_>;
    using ScopedSpeculationRulesPointerDownHeuristics
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_down_heuristics_enabled_>;
    using ScopedSpeculationRulesPointerHoverHeuristics
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_hover_heuristics_enabled_>;
    using ScopedSpeculationRulesPrefetchFuture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_future_enabled_>;
    using ScopedSpeculationRulesPrefetchWithSubresources
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_>;
    using ScopedSrcsetMaxDensity = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_>;
    using ScopedStableBlinkFeatures = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_>;
    using ScopedStandardizedBrowserZoom = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_enabled_>;
    using ScopedStandardizedBrowserZoomOptOut = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_opt_out_enabled_>;
    using ScopedStaticAnimationOptimization = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_static_animation_optimization_enabled_>;
    using ScopedStorageAccessHeader = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_storage_access_header_enabled_>;
    using ScopedStorageBuckets = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_>;
    using ScopedStorageBucketsDurability = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_storage_buckets_durability_enabled_>;
    using ScopedStorageBucketsLocks = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_storage_buckets_locks_enabled_>;
    using ScopedStricterCellWidthContentSizeQuirk = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_stricter_cell_width_content_size_quirk_enabled_>;
    using ScopedStrictMimeTypesForWorkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_>;
    using ScopedStylusHandwriting = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_>;
    using ScopedSvgContextPaint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_context_paint_enabled_>;
    using ScopedSvgCrossOriginAttribute = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_cross_origin_attribute_enabled_>;
    using ScopedSvgEagerPresAttrStyleUpdate = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_eager_pres_attr_style_update_enabled_>;
    using ScopedSvgExternalResources = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_external_resources_enabled_>;
    using ScopedSvgFilterUserSpaceViewportForNonSvg
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_filter_user_space_viewport_for_non_svg_enabled_>;
    using ScopedSvgGradientColorInterpolationLinearRgbSupport
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_gradient_color_interpolation_linear_rgb_support_enabled_>;
    using ScopedSvgInlineRootPixelSnappingScaleAdjustment
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_>;
    using ScopedSvgNoPixelSnappingScaleAdjustment = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_no_pixel_snapping_scale_adjustment_enabled_>;
    using ScopedSvgTransformOptimization = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_svg_transform_optimization_enabled_>;
    using ScopedSynthesizedKeyboardEventsForAccessibilityActions
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_>;
    using ScopedSystemFallbackEmojiVSSupport = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_system_fallback_emoji_vs_support_enabled_>;
    using ScopedSystemWakeLock = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_>;
    using ScopedTestBlinkFeatureDefault = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_test_blink_feature_default_enabled_>;
    using ScopedTestFeature = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_test_feature_enabled_>;
    using ScopedTestFeatureDependent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_>;
    using ScopedTestFeatureImplied = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_>;
    using ScopedTestFeatureProtected = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_test_feature_protected_enabled_>;
    using ScopedTestFeatureProtectedDependent = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_test_feature_protected_dependent_enabled_>;
    using ScopedTestFeatureProtectedImplied = ScopedRuntimeEnabledProtectedFeature<RuntimeEnabledFeaturesBase::is_test_feature_protected_implied_enabled_>;
    using ScopedTestFeatureStable = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_test_feature_stable_enabled_>;
    using ScopedTextDetector = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_detector_enabled_>;
    using ScopedTextDiffSplitFix = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_diff_split_fix_enabled_>;
    using ScopedTextFragmentAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_>;
    using ScopedTextFragmentIdentifiers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_>;
    using ScopedTextFragmentTapOpensContextMenu = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_>;
    using ScopedTextInputNotAlwaysDirAuto = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_input_not_always_dir_auto_enabled_>;
    using ScopedTextMetricsBaselines = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_metrics_baselines_enabled_>;
    using ScopedTextSegmentBoundaryForElementWithFloatStyle
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_segment_boundary_for_element_with_float_style_enabled_>;
    using ScopedTextSizeAdjustImprovements = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_size_adjust_improvements_enabled_>;
    using ScopedTextTransformAndSecurityFix = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_text_transform_and_security_fix_enabled_>;
    using ScopedTimelineScope = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_timeline_scope_enabled_>;
    using ScopedTimerThrottlingForBackgroundTabs = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_>;
    using ScopedTimestampBasedCLSTracking = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_timestamp_based_cls_tracking_enabled_>;
    using ScopedTimeZoneChangeEvent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_>;
    using ScopedTopicsAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_topics_api_enabled_>;
    using ScopedTopicsDocumentAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_topics_document_api_enabled_>;
    using ScopedTopLayerInactiveDocumentExceptions
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_top_layer_inactive_document_exceptions_enabled_>;
    using ScopedTopLevelTpcd = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_top_level_tpcd_enabled_>;
    using ScopedTouchDragAndContextMenu = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_>;
    using ScopedTouchDragOnShortPress = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_>;
    using ScopedTouchEventFeatureDetection = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_>;
    using ScopedTouchTextEditingRedesign = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_touch_text_editing_redesign_enabled_>;
    using ScopedTpcd = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_tpcd_enabled_>;
    using ScopedTransferableRTCDataChannel = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_transferable_rtc_data_channel_enabled_>;
    using ScopedTranslateService = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_translate_service_enabled_>;
    using ScopedTranslationAPI = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_translation_api_enabled_>;
    using ScopedTranslationAPIEntryPoint = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_translation_api_entry_point_enabled_>;
    using ScopedTrustedTypeBeforePolicyCreationEvent
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_>;
    using ScopedTrustedTypesFromLiteral = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_trusted_types_from_literal_enabled_>;
    using ScopedTrustedTypesUseCodeLike = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_>;
    using ScopedUnclosedFormControlIsInvalid = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_>;
    using ScopedUnexposedTaskIds = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_>;
    using ScopedUnownedAnimationsSkipCSSEvents = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_unowned_animations_skip_css_events_enabled_>;
    using ScopedUnrestrictedMeasureUserAgentSpecificMemory
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_unrestricted_measure_user_agent_specific_memory_enabled_>;
    using ScopedUnrestrictedSharedArrayBuffer = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_>;
    using ScopedUnrestrictedUsb = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_unrestricted_usb_enabled_>;
    using ScopedURLPatternCompareComponent = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_>;
    using ScopedURLSearchParamsHasAndDeleteMultipleArgs
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_url_search_params_has_and_delete_multiple_args_enabled_>;
    using ScopedUseBeginFramePresentationFeedback = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_>;
    using ScopedUseLowQualityInterpolation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_>;
    using ScopedUserActivationSameOriginVisibility
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_>;
    using ScopedUseSelectionFocusNodeForCaretNavigation
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_use_selection_focus_node_for_caret_navigation_enabled_>;
    using ScopedUseUndoStepElementDispatchBeforeInput
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_use_undo_step_element_dispatch_before_input_enabled_>;
    using ScopedV8IdleTasks = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_>;
    using ScopedVideoAutoFullscreen = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_>;
    using ScopedVideoFrameMetadataBackgroundBlur = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_frame_metadata_background_blur_enabled_>;
    using ScopedVideoFullscreenOrientationLock = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_>;
    using ScopedVideoRotateToFullscreen = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_>;
    using ScopedVideoTrackGenerator = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_>;
    using ScopedVideoTrackGeneratorInWindow = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_>;
    using ScopedVideoTrackGeneratorInWorker = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_>;
    using ScopedViewportChangesUpdateTextAutosizing
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_viewport_changes_update_text_autosizing_enabled_>;
    using ScopedViewportHeightClientHintHeader = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_>;
    using ScopedViewportSegments = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_>;
    using ScopedViewTransitionDisableSnapBrowserControlsOnHidden
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_disable_snap_browser_controls_on_hidden_enabled_>;
    using ScopedViewTransitionLayeredCapture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_layered_capture_enabled_>;
    using ScopedViewTransitionLongCallbackTimeoutForTesting
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_long_callback_timeout_for_testing_enabled_>;
    using ScopedViewTransitionOnNavigation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_enabled_>;
    using ScopedViewTransitionOnNavigationForIframes
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_for_iframes_enabled_>;
    using ScopedViewTransitionOverflowRectFromSurface
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_overflow_rect_from_surface_enabled_>;
    using ScopedViewTransitionTreeScopedNames = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_tree_scoped_names_enabled_>;
    using ScopedViewTransitionTypes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_view_transition_types_enabled_>;
    using ScopedVisibilityCollapseColumn = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_>;
    using ScopedVisualViewportOnScrollEnd = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_visual_viewport_on_scroll_end_enabled_>;
    using ScopedWakeLock = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_wake_lock_enabled_>;
    using ScopedWarnOnContentVisibilityRenderAccess
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_>;
    using ScopedWebAnimationsSVG = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_>;
    using ScopedWebAppInstallation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_installation_enabled_>;
    using ScopedWebAppLaunchQueue = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_>;
    using ScopedWebAppScopeExtensions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_scope_extensions_enabled_>;
    using ScopedWebAppTabStrip = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_>;
    using ScopedWebAppTabStripCustomizations = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_>;
    using ScopedWebAppTranslations = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_>;
    using ScopedWebAppUrlHandling = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_>;
    using ScopedWebAssemblyJSPromiseIntegration = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_assembly_js_promise_integration_enabled_>;
    using ScopedWebAssemblyJSStringBuiltins = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_assembly_js_string_builtins_enabled_>;
    using ScopedWebAudioBypassOutputBuffering = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_enabled_>;
    using ScopedWebAudioBypassOutputBufferingOptOut
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_opt_out_enabled_>;
    using ScopedWebAuth = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_auth_enabled_>;
    using ScopedWebAuthAuthenticatorAttachment = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_>;
    using ScopedWebAuthenticationAmbient = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_ambient_enabled_>;
    using ScopedWebAuthenticationAttestationFormats
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_attestation_formats_enabled_>;
    using ScopedWebAuthenticationClientCapabilities
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_client_capabilities_enabled_>;
    using ScopedWebAuthenticationJSONSerialization
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_js_on_serialization_enabled_>;
    using ScopedWebAuthenticationLargeBlobExtension
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_>;
    using ScopedWebAuthenticationPRF = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_prf_enabled_>;
    using ScopedWebAuthenticationRemoteDesktopSupport
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_>;
    using ScopedWebAuthenticationSupplementalPubKeys
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_authentication_supplemental_pub_keys_enabled_>;
    using ScopedWebBluetooth = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_>;
    using ScopedWebBluetoothGetDevices = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_>;
    using ScopedWebBluetoothScanning = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_>;
    using ScopedWebBluetoothWatchAdvertisements = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_>;
    using ScopedWebCodecsCopyToRGB = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webcodecs_copy_to_rgb_enabled_>;
    using ScopedWebCodecsHBDFormats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webcodecs_hbd_formats_enabled_>;
    using ScopedWebCodecsOrientation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webcodecs_orientation_enabled_>;
    using ScopedWebCodecsVideoEncoderBuffers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webcodecs_video_encoder_buffers_enabled_>;
    using ScopedWebCryptoCurve25519 = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_crypto_curve_25519_enabled_>;
    using ScopedWebFontResizeLCP = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_font_resize_lcp_enabled_>;
    using ScopedWebGLDeveloperExtensions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_>;
    using ScopedWebGLDraftExtensions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_>;
    using ScopedWebGLDrawingBufferStorage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgl_drawing_buffer_storage_enabled_>;
    using ScopedWebGLImageChromium = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_>;
    using ScopedWebGPUCanvasContextGetConfiguration
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_canvas_context_get_configuration_enabled_>;
    using ScopedWebGPUDeveloperFeatures = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_>;
    using ScopedWebGPUDeviceAdapterInfo = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_device_adapter_info_enabled_>;
    using ScopedWebGPUExperimentalFeatures = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_experimental_features_enabled_>;
    using ScopedWebGPUHDR = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_hdr_enabled_>;
    using ScopedWebGPUSubgroupsFeatures = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_subgroups_features_enabled_>;
    using ScopedWebGPUTextureViewUsage = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_webgpu_texture_view_usage_enabled_>;
    using ScopedWebHID = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_hid_enabled_>;
    using ScopedWebHIDOnDedicatedWorkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_hid_on_dedicated_workers_enabled_>;
    using ScopedWebHIDOnServiceWorkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_>;
    using ScopedWebIdentityDigitalCredentials = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_identity_digital_credentials_enabled_>;
    using ScopedWebIDLBigIntUsesToBigInt = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_idl_big_int_uses_to_big_int_enabled_>;
    using ScopedWebNFC = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_nfc_enabled_>;
    using ScopedWebOTP = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_otp_enabled_>;
    using ScopedWebOTPAssertionFeaturePolicy = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_>;
    using ScopedWebPreferences = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_preferences_enabled_>;
    using ScopedWebPrinting = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_printing_enabled_>;
    using ScopedWebShare = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_share_enabled_>;
    using ScopedWebSocketStream = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_>;
    using ScopedWebTransportCustomCertificates = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_>;
    using ScopedWebTransportStats = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_transport_stats_enabled_>;
    using ScopedWebUSB = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_usb_enabled_>;
    using ScopedWebUSBOnDedicatedWorkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_>;
    using ScopedWebUSBOnServiceWorkers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_>;
    using ScopedWebViewXRequestedWithDeprecation = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_view_xr_equested_with_deprecation_enabled_>;
    using ScopedWebVTTRegions = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_>;
    using ScopedWebXR = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_enabled_>;
    using ScopedWebXREnabledFeatures = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_enabled_features_enabled_>;
    using ScopedWebXRFrameRate = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_frame_rate_enabled_>;
    using ScopedWebXRFrontFacing = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_front_facing_enabled_>;
    using ScopedWebXRGPUBinding = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_gpu_binding_enabled_>;
    using ScopedWebXRHandInput = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_>;
    using ScopedWebXRHitTestEntityTypes = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_>;
    using ScopedWebXRImageTracking = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_>;
    using ScopedWebXRLayers = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_layers_enabled_>;
    using ScopedWebXRLayersCommon = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_layers_common_enabled_>;
    using ScopedWebXRPlaneDetection = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_>;
    using ScopedWebXRPoseMotionData = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_pose_motion_data_enabled_>;
    using ScopedWebXRSpecParity = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_web_xr_spec_parity_enabled_>;
    using ScopedWindowDefaultStatus = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_window_default_status_enabled_>;
    using ScopedXMLParserMergeAdjacentCDataSections
        = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_xml_parser_merge_adjacent_c_data_sections_enabled_>;
    using ScopedZeroCopyTabCapture = ScopedRuntimeEnabledFeature<RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_>;
};

using ScopedAccelerated2dCanvasForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccelerated2dCanvas;
using ScopedAcceleratedSmallCanvasesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAcceleratedSmallCanvases;
using ScopedAccessibilityAriaVirtualContentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityAriaVirtualContent;
using ScopedAccessibilityExposeDisplayNoneForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityExposeDisplayNone;
using ScopedAccessibilityMinRoleTabbableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityMinRoleTabbable;
using ScopedAccessibilityOSLevelBoldTextForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityOSLevelBoldText;
using ScopedAccessibilityProhibitedNamesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityProhibitedNames;
using ScopedAccessibilitySerializationSizeMetricsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilitySerializationSizeMetrics;
using ScopedAccessibilityUseAXPositionForDocumentMarkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAccessibilityUseAXPositionForDocumentMarkers;
using ScopedAddressSpaceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAddressSpace;
using ScopedAdInterestGroupAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAdInterestGroupAPI;
using ScopedAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedForTest
    = RuntimeEnabledFeaturesTestHelpers::ScopedAdjustEndOfNextParagraphIfMovedParagraphIsUpdated;
using ScopedAdTaggingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAdTagging;
using ScopedAIPromptAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAIPromptAPI;
using ScopedAIPromptAPIForExtensionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAIPromptAPIForExtension;
using ScopedAIPromptAPIForWebPlatformForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAIPromptAPIForWebPlatform;
using ScopedAIRewriterAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAIRewriterAPI;
using ScopedAISummarizationAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAISummarizationAPI;
using ScopedAIWriterAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAIWriterAPI;
using ScopedAllowContentInitiatedDataUrlNavigationsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAllowContentInitiatedDataUrlNavigations;
using ScopedAllowJavaScriptToResetAutofillStateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAllowJavaScriptToResetAutofillState;
using ScopedAllowPreloadingWithCSPMetaTagForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAllowPreloadingWithCSPMetaTag;
using ScopedAllowURNsInIframesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAllowURNsInIframes;
using ScopedAndroidDownloadableFontsMatchingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAndroidDownloadableFontsMatching;
using ScopedAnimationProgressAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAnimationProgressAPI;
using ScopedAnimationWorkletForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAnimationWorklet;
using ScopedAnonymousIframeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAnonymousIframe;
using ScopedAOMAriaRelationshipPropertiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAOMAriaRelationshipProperties;
using ScopedAOMAriaRelationshipPropertiesAriaOwnsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAOMAriaRelationshipPropertiesAriaOwns;
using ScopedAppTitleForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAppTitle;
using ScopedAriaActionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAriaActions;
using ScopedAriaNotifyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAriaNotify;
using ScopedAriaRowColIndexTextForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAriaRowColIndexText;
using ScopedAtomicMoveAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAtomicMoveAPI;
using ScopedAttributionReportingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAttributionReporting;
using ScopedAttributionReportingCrossAppWebForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAttributionReportingCrossAppWeb;
using ScopedAttributionReportingInterfaceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAttributionReportingInterface;
using ScopedAudioContextInterruptedStateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAudioContextInterruptedState;
using ScopedAudioContextOnErrorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAudioContextOnError;
using ScopedAudioContextPlayoutStatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAudioContextPlayoutStats;
using ScopedAudioContextSetSinkIdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAudioContextSetSinkId;
using ScopedAudioOutputDevicesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAudioOutputDevices;
using ScopedAudioVideoTracksForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAudioVideoTracks;
using ScopedAuraScrollbarUsesNinePatchTrackForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAuraScrollbarUsesNinePatchTrack;
using ScopedAuraScrollbarUsesSolidColorThumbForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAuraScrollbarUsesSolidColorThumb;
using ScopedAutoDarkModeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAutoDarkMode;
using ScopedAutomationControlledForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAutomationControlled;
using ScopedAutoPictureInPictureVideoHeuristicsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedAutoPictureInPictureVideoHeuristics;
using ScopedBackfaceVisibilityInteropForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBackfaceVisibilityInterop;
using ScopedBackForwardCacheForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBackForwardCache;
using ScopedBackForwardCacheExperimentHTTPHeaderForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBackForwardCacheExperimentHTTPHeader;
using ScopedBackForwardCacheNotRestoredReasonsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBackForwardCacheNotRestoredReasons;
using ScopedBackForwardTransitionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBackForwardTransitions;
using ScopedBackgroundFetchForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBackgroundFetch;
using ScopedBarcodeDetectorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBarcodeDetector;
using ScopedBidiCaretAffinityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBidiCaretAffinity;
using ScopedBlinkExtensionChromeOSForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkExtensionChromeOS;
using ScopedBlinkExtensionChromeOSKioskForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkExtensionChromeOSKiosk;
using ScopedBlinkExtensionDiagnosticsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkExtensionDiagnostics;
using ScopedBlinkExtensionWebViewForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkExtensionWebView;
using ScopedBlinkExtensionWebViewMediaIntegrityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkExtensionWebViewMediaIntegrity;
using ScopedBlinkLifecycleScriptForbiddenForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkLifecycleScriptForbidden;
using ScopedBlinkRuntimeCallStatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlinkRuntimeCallStats;
using ScopedBlockingFocusWithoutUserActivationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBlockingFocusWithoutUserActivation;
using ScopedBoundaryEventDispatchTracksNodeRemovalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBoundaryEventDispatchTracksNodeRemoval;
using ScopedBoxDecorationBreakForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBoxDecorationBreak;
using ScopedBreakIteratorHyphenMinusForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBreakIteratorHyphenMinus;
using ScopedBrowserVerifiedUserActivationKeyboardForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBrowserVerifiedUserActivationKeyboard;
using ScopedBrowserVerifiedUserActivationMouseForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBrowserVerifiedUserActivationMouse;
using ScopedBufferedBytesConsumerLimitSizeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBufferedBytesConsumerLimitSize;
using ScopedBuiltInAIAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBuiltInAIAPI;
using ScopedBypassPepcSecurityForTestingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedBypassPepcSecurityForTesting;
using ScopedCacheStorageCodeCacheHintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCacheStorageCodeCacheHint;
using ScopedCalendarPickerMonthPopupButtonDisabledColorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCalendarPickerMonthPopupButtonDisabledColor;
using ScopedCallExitNodeWithoutLayoutObjectForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCallExitNodeWithoutLayoutObject;
using ScopedCanvas2dCanvasFilterForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dCanvasFilter;
using ScopedCanvas2dGPUTransferForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dGPUTransfer;
using ScopedCanvas2dImageChromiumForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dImageChromium;
using ScopedCanvas2dLayersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dLayers;
using ScopedCanvas2dLayersWithOptionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dLayersWithOptions;
using ScopedCanvas2dMeshForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dMesh;
using ScopedCanvas2dTextMetricsShapingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvas2dTextMetricsShaping;
using ScopedCanvasFloatingPointForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvasFloatingPoint;
using ScopedCanvasHDRForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvasHDR;
using ScopedCanvasImageSmoothingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvasImageSmoothing;
using ScopedCanvasPlaceElementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvasPlaceElement;
using ScopedCanvasUsesArcPaintOpForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCanvasUsesArcPaintOp;
using ScopedCapabilityDelegationDisplayCaptureRequestForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCapabilityDelegationDisplayCaptureRequest;
using ScopedCaptureControllerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCaptureController;
using ScopedCapturedMouseEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCapturedMouseEvents;
using ScopedCapturedSurfaceControlForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCapturedSurfaceControl;
using ScopedCaptureHandleForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCaptureHandle;
using ScopedCaretPositionFromPointForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCaretPositionFromPoint;
using ScopedCCTNewRFMPushBehaviorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCCTNewRFMPushBehavior;
using ScopedCheckIfHighestRootContainsPositionAnchorNodeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCheckIfHighestRootContainsPositionAnchorNode;
using ScopedCheckVisibilityExtraPropertiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCheckVisibilityExtraProperties;
using ScopedClickToCapturedPointerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedClickToCapturedPointer;
using ScopedClipboardItemWithDOMStringSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedClipboardItemWithDOMStringSupport;
using ScopedClipPathRejectEmptyPathsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedClipPathRejectEmptyPaths;
using ScopedCoalesceSelectionchangeEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCoalesceSelectionchangeEvent;
using ScopedCoepReflectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCoepReflection;
using ScopedCompositeBGColorAnimationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompositeBGColorAnimation;
using ScopedCompositeBoxShadowAnimationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompositeBoxShadowAnimation;
using ScopedCompositeClipPathAnimationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompositeClipPathAnimation;
using ScopedCompositedAnimationsCancelledAsynchronouslyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompositedAnimationsCancelledAsynchronously;
using ScopedCompositedSelectionUpdateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompositedSelectionUpdate;
using ScopedCompositionForegroundMarkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompositionForegroundMarkers;
using ScopedCompressionDictionaryTransportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompressionDictionaryTransport;
using ScopedCompressionDictionaryTransportBackendForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCompressionDictionaryTransportBackend;
using ScopedComputedAccessibilityInfoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedComputedAccessibilityInfo;
using ScopedComputePressureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedComputePressure;
using ScopedConcurrentViewTransitionsSPAForTest = RuntimeEnabledFeaturesTestHelpers::ScopedConcurrentViewTransitionsSPA;
using ScopedContactsManagerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedContactsManager;
using ScopedContactsManagerExtraPropertiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedContactsManagerExtraProperties;
using ScopedContainerTypeNoLayoutContainmentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedContainerTypeNoLayoutContainment;
using ScopedContentIndexForTest = RuntimeEnabledFeaturesTestHelpers::ScopedContentIndex;
using ScopedContextMenuForTest = RuntimeEnabledFeaturesTestHelpers::ScopedContextMenu;
using ScopedContinueEventTimingRecordingWhenBufferIsFullForTest = RuntimeEnabledFeaturesTestHelpers::ScopedContinueEventTimingRecordingWhenBufferIsFull;
using ScopedControlledFrameForTest = RuntimeEnabledFeaturesTestHelpers::ScopedControlledFrame;
using ScopedCookieDeprecationFacilitatedTestingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCookieDeprecationFacilitatedTesting;
using ScopedCooperativeSchedulingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCooperativeScheduling;
using ScopedCoopRestrictPropertiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCoopRestrictProperties;
using ScopedCorsRFC1918ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCorsRFC1918;
using ScopedCreateInputShadowTreeDuringLayoutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCreateInputShadowTreeDuringLayout;
using ScopedCredentialManagerReportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCredentialManagerReport;
using ScopedCrossFramePerformanceTimelineForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCrossFramePerformanceTimeline;
using ScopedCSSAccentColorKeywordForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAccentColorKeyword;
using ScopedCSSAdvancedAttrFunctionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAdvancedAttrFunction;
using ScopedCSSAnchorScopeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAnchorScope;
using ScopedCSSAnchorSizeInsetsMarginsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAnchorSizeInsetsMargins;
using ScopedCSSAtPropertyStringSyntaxForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAtPropertyStringSyntax;
using ScopedCSSAtRuleCounterStyleImageSymbolsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAtRuleCounterStyleImageSymbols;
using ScopedCSSAtRuleCounterStyleSpeakAsDescriptorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSAtRuleCounterStyleSpeakAsDescriptor;
using ScopedCSSBackgroundClipUnprefixForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSBackgroundClipUnprefix;
using ScopedCSSCalcSimplificationAndSerializationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCalcSimplificationAndSerialization;
using ScopedCSSCalcSizeFunctionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCalcSizeFunction;
using ScopedCSSCaretAnimationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCaretAnimation;
using ScopedCSSCascadeCorrectScopeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCascadeCorrectScope;
using ScopedCSSCaseSensitiveSelectorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCaseSensitiveSelector;
using ScopedCSSColorContrastForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSColorContrast;
using ScopedCSSColorTypedOMForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSColorTypedOM;
using ScopedCSSComputedStyleFullPseudoElementParserForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSComputedStyleFullPseudoElementParser;
using ScopedCSSContentVisibilityImpliesContainIntrinsicSizeAutoForTest
    = RuntimeEnabledFeaturesTestHelpers::ScopedCSSContentVisibilityImpliesContainIntrinsicSizeAuto;
using ScopedCSSCrossFadeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCrossFade;
using ScopedCSSCustomStateDeprecatedSyntaxForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCustomStateDeprecatedSyntax;
using ScopedCSSCustomStateNewSyntaxForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSCustomStateNewSyntax;
using ScopedCSSDynamicRangeLimitForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSDynamicRangeLimit;
using ScopedCSSEnumeratedCustomPropertiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSEnumeratedCustomProperties;
using ScopedCSSExponentialFunctionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSExponentialFunctions;
using ScopedCSSFlatTreeContainerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSFlatTreeContainer;
using ScopedCSSFontSizeAdjustForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSFontSizeAdjust;
using ScopedCSSFunctionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSFunctions;
using ScopedCSSGapDecorationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSGapDecoration;
using ScopedCSSHexAlphaColorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSHexAlphaColor;
using ScopedCSSInertForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSInert;
using ScopedCSSInsetAreaPropertyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSInsetAreaProperty;
using ScopedCSSKeyframesRuleLengthForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSKeyframesRuleLength;
using ScopedCSSLayoutAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSLayoutAPI;
using ScopedCSSLazyParsingFastPathForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSLazyParsingFastPath;
using ScopedCSSLineClampForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSLineClamp;
using ScopedCSSLineClampWebkitBoxBlockificationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSLineClampWebkitBoxBlockification;
using ScopedCSSLogicalOverflowForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSLogicalOverflow;
using ScopedCSSMarkerNestedPseudoElementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSMarkerNestedPseudoElement;
using ScopedCSSMasonryLayoutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSMasonryLayout;
using ScopedCSSMixinsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSMixins;
using ScopedCSSNestedDeclarationsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSNestedDeclarations;
using ScopedCSSNestedPseudoElementsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSNestedPseudoElements;
using ScopedCSSOverflowContainerQueriesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSOverflowContainerQueries;
using ScopedCSSPaintAPIArgumentsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPaintAPIArguments;
using ScopedCSSParserIgnoreCharsetForURLsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSParserIgnoreCharsetForURLs;
using ScopedCSSPartAllowsMoreSelectorsAfterForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPartAllowsMoreSelectorsAfter;
using ScopedCSSPositionAreaValueForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPositionAreaValue;
using ScopedCSSPositionStickyStaticScrollPositionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPositionStickyStaticScrollPosition;
using ScopedCSSProgressNotationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSProgressNotation;
using ScopedCSSPseudoColumnForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoColumn;
using ScopedCSSPseudoHasSlottedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoHasSlotted;
using ScopedCSSPseudoOpenClosedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoOpenClosed;
using ScopedCSSPseudoPlayingPausedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoPlayingPaused;
using ScopedCSSPseudoScrollButtonsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoScrollButtons;
using ScopedCSSPseudoScrollMarkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSPseudoScrollMarkers;
using ScopedCSSReadingFlowForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSReadingFlow;
using ScopedCSSRelativeColorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSRelativeColor;
using ScopedCSSRelativeColorLateResolveAlwaysForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSRelativeColorLateResolveAlways;
using ScopedCSSRelativeColorPreserveNoneForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSRelativeColorPreserveNone;
using ScopedCSSRelativeColorSupportsCurrentcolorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSRelativeColorSupportsCurrentcolor;
using ScopedCSSResizeAutoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSResizeAuto;
using ScopedCSSScrollSnapChangeEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollSnapChangeEvent;
using ScopedCSSScrollSnapChangingEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollSnapChangingEvent;
using ScopedCSSScrollSnapEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollSnapEvents;
using ScopedCSSScrollStartForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollStart;
using ScopedCSSScrollStartTargetForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollStartTarget;
using ScopedCSSScrollStateContainerQueriesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSScrollStateContainerQueries;
using ScopedCSSSelectorFragmentAnchorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSelectorFragmentAnchor;
using ScopedCSSSignRelatedFunctionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSignRelatedFunctions;
using ScopedCSSSnapContainerQueriesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSnapContainerQueries;
using ScopedCSSSteppedValueFunctionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSteppedValueFunctions;
using ScopedCSSStickyContainerQueriesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSStickyContainerQueries;
using ScopedCSSSupportsAtRuleFunctionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSupportsAtRuleFunction;
using ScopedCSSSupportsForImportRulesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSupportsForImportRules;
using ScopedCSSSystemAccentColorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSSystemAccentColor;
using ScopedCSSTextAutoSpaceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSTextAutoSpace;
using ScopedCSSTextBoxTrimForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSTextBoxTrim;
using ScopedCSSTextSpacingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSTextSpacing;
using ScopedCSSTreeScopedTimelinesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSTreeScopedTimelines;
using ScopedCSSUserSelectContainForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSUserSelectContain;
using ScopedCSSVideoDynamicRangeMediaQueriesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSVideoDynamicRangeMediaQueries;
using ScopedCSSViewTransitionAutoNameForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSViewTransitionAutoName;
using ScopedCSSViewTransitionClassForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCSSViewTransitionClass;
using ScopedCursorAnchorInfoMojoPipeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCursorAnchorInfoMojoPipe;
using ScopedCustomizableSelectForTest = RuntimeEnabledFeaturesTestHelpers::ScopedCustomizableSelect;
using ScopedDatabaseForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDatabase;
using ScopedDeprecatedRequestAdapterInfoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDeprecatedRequestAdapterInfo;
using ScopedDeprecateUnloadOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDeprecateUnloadOptOut;
using ScopedDesktopCaptureDisableLocalEchoControlForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDesktopCaptureDisableLocalEchoControl;
using ScopedDesktopPWAsAdditionalWindowingControlsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDesktopPWAsAdditionalWindowingControls;
using ScopedDesktopPWAsSubAppsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDesktopPWAsSubApps;
using ScopedDetailsStylingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDetailsStyling;
using ScopedDeviceAttributesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDeviceAttributes;
using ScopedDeviceOrientationRequestPermissionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDeviceOrientationRequestPermission;
using ScopedDevicePostureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDevicePosture;
using ScopedDialogCloseWhenOpenRemovedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDialogCloseWhenOpenRemoved;
using ScopedDialogElementToggleEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDialogElementToggleEvents;
using ScopedDialogNewFocusBehaviorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDialogNewFocusBehavior;
using ScopedDigitalGoodsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDigitalGoods;
using ScopedDigitalGoodsV2_1ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDigitalGoodsV2_1;
using ScopedDirAutoFixSlotExclusionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDirAutoFixSlotExclusions;
using ScopedDirectSocketsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDirectSockets;
using ScopedDisableAhemAntialiasForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisableAhemAntialias;
using ScopedDisableDifferentOriginSubframeDialogSuppressionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisableDifferentOriginSubframeDialogSuppression;
using ScopedDisableHardwareNoiseSuppressionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisableHardwareNoiseSuppression;
using ScopedDisableReduceAcceptLanguageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisableReduceAcceptLanguage;
using ScopedDisableSelectAllForEmptyTextForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisableSelectAllForEmptyText;
using ScopedDisableThirdPartyStoragePartitioning2ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisableThirdPartyStoragePartitioning2;
using ScopedDispatchBeforeInputForSpinButtonInteractionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDispatchBeforeInputForSpinButtonInteractions;
using ScopedDispatchHiddenVisibilityTransitionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDispatchHiddenVisibilityTransitions;
using ScopedDispatchSelectionchangeEventPerElementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDispatchSelectionchangeEventPerElement;
using ScopedDisplayContentsFocusableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisplayContentsFocusable;
using ScopedDisplayCutoutAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDisplayCutoutAPI;
using ScopedDocumentCookieForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentCookie;
using ScopedDocumentDomainForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentDomain;
using ScopedDocumentInstallChunkingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentInstallChunking;
using ScopedDocumentIsolationPolicyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentIsolationPolicy;
using ScopedDocumentOpenOriginAliasRemovalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentOpenOriginAliasRemoval;
using ScopedDocumentOpenSandboxInheritanceRemovalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentOpenSandboxInheritanceRemoval;
using ScopedDocumentPictureInPictureAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPictureInPictureAPI;
using ScopedDocumentPictureInPicturePreferInitialPlacementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPictureInPicturePreferInitialPlacement;
using ScopedDocumentPictureInPictureUserActivationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPictureInPictureUserActivation;
using ScopedDocumentPolicyDocumentDomainForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPolicyDocumentDomain;
using ScopedDocumentPolicyExpectNoLinkedResourcesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPolicyExpectNoLinkedResources;
using ScopedDocumentPolicyIncludeJSCallStacksInCrashReportsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPolicyIncludeJSCallStacksInCrashReports;
using ScopedDocumentPolicyNegotiationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPolicyNegotiation;
using ScopedDocumentPolicySyncXHRForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentPolicySyncXHR;
using ScopedDocumentRenderBlockingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentRenderBlocking;
using ScopedDocumentWriteForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDocumentWrite;
using ScopedDOMPartsAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDOMPartsAPI;
using ScopedDOMPartsAPIMinimalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDOMPartsAPIMinimal;
using ScopedDropUrlAsPlainTextInPlainTextOnlyEditablePositionForTest
    = RuntimeEnabledFeaturesTestHelpers::ScopedDropUrlAsPlainTextInPlainTextOnlyEditablePosition;
using ScopedDynamicSafeAreaInsetsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDynamicSafeAreaInsets;
using ScopedDynamicSafeAreaInsetsOnScrollForTest = RuntimeEnabledFeaturesTestHelpers::ScopedDynamicSafeAreaInsetsOnScroll;
using ScopedElementCaptureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedElementCapture;
using ScopedElementGetInnerHTMLForTest = RuntimeEnabledFeaturesTestHelpers::ScopedElementGetInnerHTML;
using ScopedEnforceAnonymityExposureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEnforceAnonymityExposure;
using ScopedEscapeLtGtInAttributesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEscapeLtGtInAttributes;
using ScopedEventTimingHandleKeyboardEventSimulatedClickForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEventTimingHandleKeyboardEventSimulatedClick;
using ScopedEventTimingInteractionCountForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEventTimingInteractionCount;
using ScopedEventTimingSelectionAutoScrollNoInteractionIdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEventTimingSelectionAutoScrollNoInteractionId;
using ScopedEventTimingTapStopScrollNoInteractionIdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEventTimingTapStopScrollNoInteractionId;
using ScopedExcludeTransparentTextsFromBeingLcpEligibleForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExcludeTransparentTextsFromBeingLcpEligible;
using ScopedExperimentalContentSecurityPolicyFeaturesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalContentSecurityPolicyFeatures;
using ScopedExperimentalJSProfilerMarkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalJSProfilerMarkers;
using ScopedExperimentalMachineLearningNeuralNetworkForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalMachineLearningNeuralNetwork;
using ScopedExperimentalPoliciesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExperimentalPolicies;
using ScopedExposeCoarsenedRenderTimeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExposeCoarsenedRenderTime;
using ScopedExposeRenderTimeNonTaoDelayedImageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExposeRenderTimeNonTaoDelayedImage;
using ScopedExtendedTextMetricsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedExtendedTextMetrics;
using ScopedEyeDropperAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedEyeDropperAPI;
using ScopedFaceDetectorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFaceDetector;
using ScopedFastNonCompositedScrollHitTestForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFastNonCompositedScrollHitTest;
using ScopedFastPathSingleSelectorExactMatchForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFastPathSingleSelectorExactMatch;
using ScopedFastPositionIteratorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFastPositionIterator;
using ScopedFedCmForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCm;
using ScopedFedCmAuthzForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmAuthz;
using ScopedFedCmAutoSelectedFlagForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmAutoSelectedFlag;
using ScopedFedCmButtonModeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmButtonMode;
using ScopedFedCmDisconnectForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmDisconnect;
using ScopedFedCmDomainHintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmDomainHint;
using ScopedFedCmErrorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmError;
using ScopedFedCmIdPRegistrationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmIdPRegistration;
using ScopedFedCmIdpSigninStatusForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmIdpSigninStatus;
using ScopedFedCmMultipleIdentityProvidersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmMultipleIdentityProviders;
using ScopedFedCmSelectiveDisclosureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmSelectiveDisclosure;
using ScopedFedCmWithStorageAccessAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFedCmWithStorageAccessAPI;
using ScopedFencedFramesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFencedFrames;
using ScopedFencedFramesAPIChangesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFencedFramesAPIChanges;
using ScopedFencedFramesDefaultModeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFencedFramesDefaultMode;
using ScopedFencedFramesLocalUnpartitionedDataAccessForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFencedFramesLocalUnpartitionedDataAccess;
using ScopedFetchBodyBytesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFetchBodyBytes;
using ScopedFetchLaterAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFetchLaterAPI;
using ScopedFetchUploadStreamingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFetchUploadStreaming;
using ScopedFileHandlingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileHandling;
using ScopedFileHandlingIconsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileHandlingIcons;
using ScopedFileSystemForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystem;
using ScopedFileSystemAccessForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemAccess;
using ScopedFileSystemAccessAPIExperimentalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemAccessAPIExperimental;
using ScopedFileSystemAccessGetCloudIdentifiersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemAccessGetCloudIdentifiers;
using ScopedFileSystemAccessLocalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemAccessLocal;
using ScopedFileSystemAccessLockingSchemeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemAccessLockingScheme;
using ScopedFileSystemAccessOriginPrivateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemAccessOriginPrivate;
using ScopedFileSystemObserverForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemObserver;
using ScopedFileSystemObserverUnobserveForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFileSystemObserverUnobserve;
using ScopedFindDecomposedInShortTextForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFindDecomposedInShortText;
using ScopedFindRubyInPageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFindRubyInPage;
using ScopedFindTextInReadonlyTextInputForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFindTextInReadonlyTextInput;
using ScopedFindTextSkipCollapsedTextForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFindTextSkipCollapsedText;
using ScopedFledgeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledge;
using ScopedFledgeAuctionDealSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeAuctionDealSupport;
using ScopedFledgeBiddingAndAuctionServerAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeBiddingAndAuctionServerAPI;
using ScopedFledgeCustomMaxAuctionAdComponentsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeCustomMaxAuctionAdComponents;
using ScopedFledgeDeprecatedRenderURLReplacementsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeDeprecatedRenderURLReplacements;
using ScopedFledgeDirectFromSellerSignalsHeaderAdSlotForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeDirectFromSellerSignalsHeaderAdSlot;
using ScopedFledgeMultiBidForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeMultiBid;
using ScopedFledgeRealTimeReportingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeRealTimeReporting;
using ScopedFledgeReportingTimeoutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeReportingTimeout;
using ScopedFledgeSellerNonceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeSellerNonce;
using ScopedFledgeTrustedSignalsKVv2SupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFledgeTrustedSignalsKVv2Support;
using ScopedFluentOverlayScrollbarsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFluentOverlayScrollbars;
using ScopedFluentScrollbarsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFluentScrollbars;
using ScopedFluentScrollbarUsesNinePatchTrackForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFluentScrollbarUsesNinePatchTrack;
using ScopedFocusgroupForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFocusgroup;
using ScopedFontAccessForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontAccess;
using ScopedFontationsFontBackendForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontationsFontBackend;
using ScopedFontationsForSelectedFormatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontationsForSelectedFormats;
using ScopedFontFamilyPostscriptMatchingCTMigrationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontFamilyPostscriptMatchingCTMigration;
using ScopedFontFamilyStyleMatchingCTMigrationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontFamilyStyleMatchingCTMigration;
using ScopedFontPresentWinForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontPresentWin;
using ScopedFontSrcLocalMatchingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontSrcLocalMatching;
using ScopedFontSystemFallbackNotoCjkForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontSystemFallbackNotoCjk;
using ScopedFontVariantEmojiForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontVariantEmoji;
using ScopedFontVariationSequencesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFontVariationSequences;
using ScopedForcedColorsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedForcedColors;
using ScopedForcedColorsPreserveParentColorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedForcedColorsPreserveParentColor;
using ScopedForceEagerMeasureMemoryForTest = RuntimeEnabledFeaturesTestHelpers::ScopedForceEagerMeasureMemory;
using ScopedForceReduceMotionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedForceReduceMotion;
using ScopedForceTallerSelectPopupForTest = RuntimeEnabledFeaturesTestHelpers::ScopedForceTallerSelectPopup;
using ScopedFormControlRestoreStateIfAutocompleteOffForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFormControlRestoreStateIfAutocompleteOff;
using ScopedFormControlsVerticalWritingModeDirectionSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFormControlsVerticalWritingModeDirectionSupport;
using ScopedFractionalScrollOffsetsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFractionalScrollOffsets;
using ScopedFreezeFramesOnVisibilityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedFreezeFramesOnVisibility;
using ScopedGamepadMultitouchForTest = RuntimeEnabledFeaturesTestHelpers::ScopedGamepadMultitouch;
using ScopedGetAllScreensMediaForTest = RuntimeEnabledFeaturesTestHelpers::ScopedGetAllScreensMedia;
using ScopedGetDisplayMediaForTest = RuntimeEnabledFeaturesTestHelpers::ScopedGetDisplayMedia;
using ScopedGetDisplayMediaRequiresUserActivationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedGetDisplayMediaRequiresUserActivation;
using ScopedGroupEffectForTest = RuntimeEnabledFeaturesTestHelpers::ScopedGroupEffect;
using ScopedHandleSelectionChangeOnDeletingEmptyElementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHandleSelectionChangeOnDeletingEmptyElement;
using ScopedHandwritingRecognitionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHandwritingRecognition;
using ScopedHangingWhitespaceDoesNotDependOnAlignmentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHangingWhitespaceDoesNotDependOnAlignment;
using ScopedHasUAVisualTransitionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHasUAVisualTransition;
using ScopedHighlightInheritanceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHighlightInheritance;
using ScopedHighlightPointerEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHighlightPointerEvents;
using ScopedHighlightsFromPointForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHighlightsFromPoint;
using ScopedHitTestOpaquenessForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHitTestOpaqueness;
using ScopedHitTestOpaquenessOmitLineBoxForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHitTestOpaquenessOmitLineBox;
using ScopedHrefTranslateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHrefTranslate;
using ScopedHTMLAnchorAttributeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLAnchorAttribute;
using ScopedHTMLDialogLightDismissForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLDialogLightDismiss;
using ScopedHTMLEmbedElementNotForceLayoutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLEmbedElementNotForceLayout;
using ScopedHTMLInterestTargetAttributeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLInterestTargetAttribute;
using ScopedHTMLInvokeActionsV2ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLInvokeActionsV2;
using ScopedHTMLInvokeTargetAttributeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLInvokeTargetAttribute;
using ScopedHTMLObjectElementFallbackDetachContentFrameForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLObjectElementFallbackDetachContentFrame;
using ScopedHTMLParserYieldAndDelayOftenForTestingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLParserYieldAndDelayOftenForTesting;
using ScopedHTMLPopoverActionHoverForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLPopoverActionHover;
using ScopedHTMLPopoverHintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLPopoverHint;
using ScopedHTMLSelectElementShowPickerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedHTMLSelectElementShowPicker;
using ScopedImplicitRootScrollerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedImplicitRootScroller;
using ScopedImportAttributesDisallowUnknownKeysForTest = RuntimeEnabledFeaturesTestHelpers::ScopedImportAttributesDisallowUnknownKeys;
using ScopedImportMapIntegrityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedImportMapIntegrity;
using ScopedIncomingCallNotificationsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedIncomingCallNotifications;
using ScopedIncrementLocalSurfaceIdForMainframeSameDocNavigationForTest
    = RuntimeEnabledFeaturesTestHelpers::ScopedIncrementLocalSurfaceIdForMainframeSameDocNavigation;
using ScopedIndexedDbGetAllRecordsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedIndexedDbGetAllRecords;
using ScopedInertElementNonEditableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInertElementNonEditable;
using ScopedInertElementNonSearchableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInertElementNonSearchable;
using ScopedInfiniteCullRectForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInfiniteCullRect;
using ScopedInheritUserModifyWithoutContenteditableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInheritUserModifyWithoutContenteditable;
using ScopedInitialLetterRaiseBySpecifiedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInitialLetterRaiseBySpecified;
using ScopedInlineBlockInSameLineForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInlineBlockInSameLine;
using ScopedInnerHTMLParserFastpathLogFailureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInnerHTMLParserFastpathLogFailure;
using ScopedInputClosesSelectForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInputClosesSelect;
using ScopedInputMultipleFieldsUIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInputMultipleFieldsUI;
using ScopedInsertBlockquoteBeforeOuterBlockForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInsertBlockquoteBeforeOuterBlock;
using ScopedInsertLineBreakIfPhrasingContentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInsertLineBreakIfPhrasingContent;
using ScopedInspectorGhostRulesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInspectorGhostRules;
using ScopedInstalledAppForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInstalledApp;
using ScopedInstallOnDeviceSpeechRecognitionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInstallOnDeviceSpeechRecognition;
using ScopedInterestGroupsInSharedStorageWorkletForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInterestGroupsInSharedStorageWorklet;
using ScopedInteroperablePrivateAttributionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInteroperablePrivateAttribution;
using ScopedIntersectionObserverScrollMarginForTest = RuntimeEnabledFeaturesTestHelpers::ScopedIntersectionObserverScrollMargin;
using ScopedInvertedColorsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInvertedColors;
using ScopedInvisibleSVGAnimationThrottlingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedInvisibleSVGAnimationThrottling;
using ScopedJavaScriptCompileHintsMagicAlwaysRuntimeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedJavaScriptCompileHintsMagicAlwaysRuntime;
using ScopedJavaScriptCompileHintsMagicRuntimeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedJavaScriptCompileHintsMagicRuntime;
using ScopedKeepCSSTargetAfterReattachForTest = RuntimeEnabledFeaturesTestHelpers::ScopedKeepCSSTargetAfterReattach;
using ScopedKeyboardAccessibleTooltipForTest = RuntimeEnabledFeaturesTestHelpers::ScopedKeyboardAccessibleTooltip;
using ScopedKeyboardFocusableScrollersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedKeyboardFocusableScrollers;
using ScopedKeyboardFocusableScrollersOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedKeyboardFocusableScrollersOptOut;
using ScopedLabelAndDelegatesFocusNewHandlingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLabelAndDelegatesFocusNewHandling;
using ScopedLangAttributeAwareFormControlUIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLangAttributeAwareFormControlUI;
using ScopedLanguageDetectionAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLanguageDetectionAPI;
using ScopedLayoutFlexNewRowAlgorithmV3ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLayoutFlexNewRowAlgorithmV3;
using ScopedLayoutIgnoreMarginsForStickyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLayoutIgnoreMarginsForSticky;
using ScopedLayoutJustifySelfForBlocksForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLayoutJustifySelfForBlocks;
using ScopedLayoutNGShapeCacheForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLayoutNGShapeCache;
using ScopedLayoutStretchForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLayoutStretch;
using ScopedLazyInitializeMediaControlsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLazyInitializeMediaControls;
using ScopedLazyLoadScrollMarginForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLazyLoadScrollMargin;
using ScopedLazyLoadScrollMarginIframeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLazyLoadScrollMarginIframe;
using ScopedLCPAnimatedImagesWebExposedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLCPAnimatedImagesWebExposed;
using ScopedLegacyWindowsDWriteFontFallbackForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLegacyWindowsDWriteFontFallback;
using ScopedLimitThirdPartyCookiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLimitThirdPartyCookies;
using ScopedLineBoxBelowLeadingFloatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLineBoxBelowLeadingFloats;
using ScopedListItemWithCounterSetNotSetExplicitValueForTest = RuntimeEnabledFeaturesTestHelpers::ScopedListItemWithCounterSetNotSetExplicitValue;
using ScopedLockedModeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLockedMode;
using ScopedLongAnimationFrameTimingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLongAnimationFrameTiming;
using ScopedLongPressLinkSelectTextForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLongPressLinkSelectText;
using ScopedLongTaskFromLongAnimationFrameForTest = RuntimeEnabledFeaturesTestHelpers::ScopedLongTaskFromLongAnimationFrame;
using ScopedMachineLearningNeuralNetworkForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMachineLearningNeuralNetwork;
using ScopedManagedConfigurationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedManagedConfiguration;
using ScopedMeasureMemoryForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMeasureMemory;
using ScopedMediaCapabilitiesDynamicRangeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesDynamicRange;
using ScopedMediaCapabilitiesEncodingInfoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesEncodingInfo;
using ScopedMediaCapabilitiesSpatialAudioForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapabilitiesSpatialAudio;
using ScopedMediaCaptureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCapture;
using ScopedMediaCaptureBackgroundBlurForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCaptureBackgroundBlur;
using ScopedMediaCaptureCameraControlsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCaptureCameraControls;
using ScopedMediaCaptureConfigurationChangeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCaptureConfigurationChange;
using ScopedMediaCaptureVoiceIsolationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCaptureVoiceIsolation;
using ScopedMediaCastOverlayButtonForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaCastOverlayButton;
using ScopedMediaControlsExpandGestureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaControlsExpandGesture;
using ScopedMediaControlsOverlayPlayButtonForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaControlsOverlayPlayButton;
using ScopedMediaElementVolumeGreaterThanOneForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaElementVolumeGreaterThanOne;
using ScopedMediaEngagementBypassAutoplayPoliciesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaEngagementBypassAutoplayPolicies;
using ScopedMediaLatencyHintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaLatencyHint;
using ScopedMediaPlaybackWhileNotVisiblePermissionPolicyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaPlaybackWhileNotVisiblePermissionPolicy;
using ScopedMediaPreviewsOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaPreviewsOptOut;
using ScopedMediaQueryNavigationControlsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaQueryNavigationControls;
using ScopedMediaRecorderUseMediaVideoEncoderForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaRecorderUseMediaVideoEncoder;
using ScopedMediaSessionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaSession;
using ScopedMediaSessionChapterInformationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaSessionChapterInformation;
using ScopedMediaSessionEnterPictureInPictureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaSessionEnterPictureInPicture;
using ScopedMediaSourceExperimentalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceExperimental;
using ScopedMediaSourceExtensionsForWebCodecsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceExtensionsForWebCodecs;
using ScopedMediaSourceNewAbortAndDurationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaSourceNewAbortAndDuration;
using ScopedMediaStreamTrackTransferForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaStreamTrackTransfer;
using ScopedMediaStreamTrackWebSpeechForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMediaStreamTrackWebSpeech;
using ScopedMessagePortCloseEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMessagePortCloseEvent;
using ScopedMetaRefreshNoFractionalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMetaRefreshNoFractional;
using ScopedMeterAppearanceNoneFallbackStyleForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMeterAppearanceNoneFallbackStyle;
using ScopedMeterDevolveAppearanceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMeterDevolveAppearance;
using ScopedMiddleClickAutoscrollForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMiddleClickAutoscroll;
using ScopedMinimimalResourceRequestPrepBeforeCacheLookupForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMinimimalResourceRequestPrepBeforeCacheLookup;
using ScopedMobileLayoutThemeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMobileLayoutTheme;
using ScopedModifyParagraphCrossEditingoundaryForTest = RuntimeEnabledFeaturesTestHelpers::ScopedModifyParagraphCrossEditingoundary;
using ScopedMojoJSForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMojoJS;
using ScopedMojoJSTestForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMojoJSTest;
using ScopedMoveEndingSelectionToListChildForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMoveEndingSelectionToListChild;
using ScopedMoveToParagraphStartOrEndSkipsNonEditableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMoveToParagraphStartOrEndSkipsNonEditable;
using ScopedMultipleImportMapsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMultipleImportMaps;
using ScopedMultiSelectDeselectWhenOnlyOptionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMultiSelectDeselectWhenOnlyOption;
using ScopedMultiSmoothScrollIntoViewForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMultiSmoothScrollIntoView;
using ScopedMutationEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMutationEvents;
using ScopedMutationEventsSpecialTrialMessageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedMutationEventsSpecialTrialMessage;
using ScopedNavigateEventCommitBehaviorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNavigateEventCommitBehavior;
using ScopedNavigateEventSourceElementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNavigateEventSourceElement;
using ScopedNavigationActivationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNavigationActivation;
using ScopedNavigationIdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNavigationId;
using ScopedNavigatorContentUtilsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNavigatorContentUtils;
using ScopedNestedViewTransitionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNestedViewTransition;
using ScopedNetInfoConstantTypeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNetInfoConstantType;
using ScopedNetInfoDownlinkMaxForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNetInfoDownlinkMax;
using ScopedNewGetFocusableAreaBehaviorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNewGetFocusableAreaBehavior;
using ScopedNoIdleEncodingForWebTestsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNoIdleEncodingForWebTests;
using ScopedNoIncreasingEndOffsetOnSplittingTextNodesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNoIncreasingEndOffsetOnSplittingTextNodes;
using ScopedNonEmptyBlockquotesOnOutdentingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNonEmptyBlockquotesOnOutdenting;
using ScopedNonNullInputEventDataForTextAreaForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNonNullInputEventDataForTextArea;
using ScopedNonStandardAppearanceValueSliderVerticalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNonStandardAppearanceValueSliderVertical;
using ScopedNotificationConstructorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNotificationConstructor;
using ScopedNotificationContentImageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNotificationContentImage;
using ScopedNotificationsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNotifications;
using ScopedNotificationTriggersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedNotificationTriggers;
using ScopedObservableAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedObservableAPI;
using ScopedOffMainThreadCSSPaintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOffMainThreadCSSPaint;
using ScopedOffscreenCanvasCommitForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOffscreenCanvasCommit;
using ScopedOmitBlurEventOnElementRemovalForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOmitBlurEventOnElementRemoval;
using ScopedOnDeviceChangeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOnDeviceChange;
using ScopedOnDeviceWebSpeechAvailableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOnDeviceWebSpeechAvailable;
using ScopedOrientationEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOrientationEvent;
using ScopedOriginIsolationHeaderForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginIsolationHeader;
using ScopedOriginPolicyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginPolicy;
using ScopedOriginTrialsSampleAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPI;
using ScopedOriginTrialsSampleAPIBrowserReadWriteForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIBrowserReadWrite;
using ScopedOriginTrialsSampleAPIDependentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIDependent;
using ScopedOriginTrialsSampleAPIDeprecationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIDeprecation;
using ScopedOriginTrialsSampleAPIExpiryGracePeriodForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIExpiryGracePeriod;
using ScopedOriginTrialsSampleAPIExpiryGracePeriodThirdPartyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIExpiryGracePeriodThirdParty;
using ScopedOriginTrialsSampleAPIImpliedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIImplied;
using ScopedOriginTrialsSampleAPIInvalidOSForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIInvalidOS;
using ScopedOriginTrialsSampleAPINavigationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPINavigation;
using ScopedOriginTrialsSampleAPIPersistentExpiryGracePeriodForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIPersistentExpiryGracePeriod;
using ScopedOriginTrialsSampleAPIPersistentFeatureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIPersistentFeature;
using ScopedOriginTrialsSampleAPIPersistentInvalidOSForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIPersistentInvalidOS;
using ScopedOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureForTest
    = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature;
using ScopedOriginTrialsSampleAPIThirdPartyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOriginTrialsSampleAPIThirdParty;
using ScopedOverscrollCustomizationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedOverscrollCustomization;
using ScopedPageFreezeOptInForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPageFreezeOptIn;
using ScopedPageFreezeOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPageFreezeOptOut;
using ScopedPageMarginBoxesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPageMarginBoxes;
using ScopedPagePopupForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPagePopup;
using ScopedPageRevealEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPageRevealEvent;
using ScopedPageSwapEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPageSwapEvent;
using ScopedPaintHighlightsForFirstLetterForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaintHighlightsForFirstLetter;
using ScopedPaintHoldingForIframesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaintHoldingForIframes;
using ScopedPaintHoldingForLocalIframesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaintHoldingForLocalIframes;
using ScopedPaintUnderInvalidationCheckingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaintUnderInvalidationChecking;
using ScopedParakeetForTest = RuntimeEnabledFeaturesTestHelpers::ScopedParakeet;
using ScopedPartitionedPopinsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPartitionedPopins;
using ScopedPartitionVisitedLinkDatabaseWithSelfLinksForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPartitionVisitedLinkDatabaseWithSelfLinks;
using ScopedPasswordRevealForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPasswordReveal;
using ScopedPaymentAppForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaymentApp;
using ScopedPaymentInstrumentsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaymentInstruments;
using ScopedPaymentLinkDetectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaymentLinkDetection;
using ScopedPaymentMethodChangeEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaymentMethodChangeEvent;
using ScopedPaymentRequestForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPaymentRequest;
using ScopedPercentBasedScrollingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPercentBasedScrolling;
using ScopedPerformanceManagerInstrumentationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPerformanceManagerInstrumentation;
using ScopedPerformanceMarkFeatureUsageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPerformanceMarkFeatureUsage;
using ScopedPerformanceNavigateSystemEntropyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPerformanceNavigateSystemEntropy;
using ScopedPerformanceNavigationTimingConfidenceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPerformanceNavigationTimingConfidence;
using ScopedPeriodicBackgroundSyncForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPeriodicBackgroundSync;
using ScopedPerMethodCanMakePaymentQuotaForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPerMethodCanMakePaymentQuota;
using ScopedPermissionElementForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPermissionElement;
using ScopedPermissionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPermissions;
using ScopedPermissionsRequestRevokeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPermissionsRequestRevoke;
using ScopedPNaClForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPNaCl;
using ScopedPointerEventDeviceIdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPointerEventDeviceId;
using ScopedPointerEventTargetsInEventListsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPointerEventTargetsInEventLists;
using ScopedPopoverAnchorRelationshipsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPopoverAnchorRelationships;
using ScopedPopoverDialogNewFocusBehaviorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPopoverDialogNewFocusBehavior;
using ScopedPositionOutsideTabSpanCheckSiblingNodeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPositionOutsideTabSpanCheckSiblingNode;
using ScopedPreciseMemoryInfoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPreciseMemoryInfo;
using ScopedPreferDefaultScrollbarStylesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPreferDefaultScrollbarStyles;
using ScopedPreferNonCompositedScrollingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPreferNonCompositedScrolling;
using ScopedPrefersReducedDataForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrefersReducedData;
using ScopedPrefixedVideoFullscreenForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrefixedVideoFullscreen;
using ScopedPrerender2ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrerender2;
using ScopedPresentationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPresentation;
using ScopedPreserveFollowingBlockStylesDuringBlockMergeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPreserveFollowingBlockStylesDuringBlockMerge;
using ScopedPreventUndoIfNotEditableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPreventUndoIfNotEditable;
using ScopedPrivateAggregationApiFilteringIdsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateAggregationApiFilteringIds;
using ScopedPrivateAggregationAuctionReportBuyerDebugModeConfigForTest
    = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateAggregationAuctionReportBuyerDebugModeConfig;
using ScopedPrivateNetworkAccessNonSecureContextsAllowedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateNetworkAccessNonSecureContextsAllowed;
using ScopedPrivateNetworkAccessNullIpAddressForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateNetworkAccessNullIpAddress;
using ScopedPrivateNetworkAccessPermissionPromptForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateNetworkAccessPermissionPrompt;
using ScopedPrivateStateTokensForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateStateTokens;
using ScopedPrivateStateTokensAlwaysAllowIssuanceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPrivateStateTokensAlwaysAllowIssuance;
using ScopedProtectedOriginTrialsSampleAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedProtectedOriginTrialsSampleAPI;
using ScopedProtectedOriginTrialsSampleAPIDependentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedProtectedOriginTrialsSampleAPIDependent;
using ScopedProtectedOriginTrialsSampleAPIImpliedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedProtectedOriginTrialsSampleAPIImplied;
using ScopedPseudoElementsCorrectInGetComputedStyleForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPseudoElementsCorrectInGetComputedStyle;
using ScopedPseudoElementsFocusableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPseudoElementsFocusable;
using ScopedPushMessageDataBytesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPushMessageDataBytes;
using ScopedPushMessagingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPushMessaging;
using ScopedPushMessagingSubscriptionChangeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedPushMessagingSubscriptionChange;
using ScopedQuickIntensiveWakeUpThrottlingAfterLoadingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedQuickIntensiveWakeUpThrottlingAfterLoading;
using ScopedRasterInducingScrollForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRasterInducingScroll;
using ScopedReadableStreamAsyncIterableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReadableStreamAsyncIterable;
using ScopedReduceAcceptLanguageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReduceAcceptLanguage;
using ScopedReduceCookieIPCsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReduceCookieIPCs;
using ScopedReduceUserAgentAndroidVersionDeviceModelForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReduceUserAgentAndroidVersionDeviceModel;
using ScopedReduceUserAgentMinorVersionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReduceUserAgentMinorVersion;
using ScopedReduceUserAgentPlatformOsCpuForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReduceUserAgentPlatformOsCpu;
using ScopedRegionCaptureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRegionCapture;
using ScopedRelOpenerBcgDependencyHintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRelOpenerBcgDependencyHint;
using ScopedRemotePlaybackForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemotePlayback;
using ScopedRemotePlaybackBackendForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemotePlaybackBackend;
using ScopedRemoveCollapsedPlaceholderForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemoveCollapsedPlaceholder;
using ScopedRemoveDanglingMarkupInTargetForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemoveDanglingMarkupInTarget;
using ScopedRemoveDataUrlInSvgUseForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemoveDataUrlInSvgUse;
using ScopedRemoveNodeHavingChildrenIfFullySelectedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemoveNodeHavingChildrenIfFullySelected;
using ScopedRemoveVisibleSelectionInDOMSelectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRemoveVisibleSelectionInDOMSelection;
using ScopedRenderBlockingInlineModuleScriptForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRenderBlockingInlineModuleScript;
using ScopedRenderBlockingStatusForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRenderBlockingStatus;
using ScopedRenderPriorityAttributeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRenderPriorityAttribute;
using ScopedReportEventTimingAtVisibilityChangeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReportEventTimingAtVisibilityChange;
using ScopedReportVisibleLineBoundsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReportVisibleLineBounds;
using ScopedResetInputTypeToNoneBeforeCharacterInputForTest = RuntimeEnabledFeaturesTestHelpers::ScopedResetInputTypeToNoneBeforeCharacterInput;
using ScopedResourceTimingContentTypeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedResourceTimingContentType;
using ScopedResourceTimingFinalResponseHeadersStartForTest = RuntimeEnabledFeaturesTestHelpers::ScopedResourceTimingFinalResponseHeadersStart;
using ScopedResourceTimingUseCORSForBodySizesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedResourceTimingUseCORSForBodySizes;
using ScopedRestrictGamepadAccessForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRestrictGamepadAccess;
using ScopedReuseShapeResultsByFontsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedReuseShapeResultsByFonts;
using ScopedRewindFloatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRewindFloats;
using ScopedRootElementWithPlaceHolderAfterDeletingSelectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRootElementWithPlaceHolderAfterDeletingSelection;
using ScopedRtcAudioJitterBufferMaxPacketsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRtcAudioJitterBufferMaxPackets;
using ScopedRTCDataChannelPriorityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCDataChannelPriority;
using ScopedRTCEncodedAudioFrameAbsCaptureTimeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCEncodedAudioFrameAbsCaptureTime;
using ScopedRTCEncodedFrameSetMetadataForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCEncodedFrameSetMetadata;
using ScopedRTCEncodedVideoFrameAdditionalMetadataForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCEncodedVideoFrameAdditionalMetadata;
using ScopedRTCJitterBufferTargetForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCJitterBufferTarget;
using ScopedRTCLegacyCallbackBasedGetStatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCLegacyCallbackBasedGetStats;
using ScopedRTCRtpEncodingParametersCodecForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCRtpEncodingParametersCodec;
using ScopedRTCRtpScaleResolutionDownToForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCRtpScaleResolutionDownTo;
using ScopedRTCRtpScriptTransformForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCRtpScriptTransform;
using ScopedRTCRtpTransportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCRtpTransport;
using ScopedRTCStatsRelativePacketArrivalDelayForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCStatsRelativePacketArrivalDelay;
using ScopedRTCSvcScalabilityModeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRTCSvcScalabilityMode;
using ScopedRubyShortHeuristicsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedRubyShortHeuristics;
using ScopedSanitizerAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSanitizerAPI;
using ScopedSchedulerYieldForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSchedulerYield;
using ScopedScheduleSelectionChangeOnBackspaceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScheduleSelectionChangeOnBackspace;
using ScopedScopedCustomElementRegistryForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScopedCustomElementRegistry;
using ScopedScriptedSpeechRecognitionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScriptedSpeechRecognition;
using ScopedScriptedSpeechSynthesisForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScriptedSpeechSynthesis;
using ScopedScrollbarColorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollbarColor;
using ScopedScrollbarWidthForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollbarWidth;
using ScopedScrollEndEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollEndEvents;
using ScopedScrollIntoViewRootFrameViewportBugFixForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollIntoViewRootFrameViewportBugFix;
using ScopedScrollTimelineForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollTimeline;
using ScopedScrollTimelineCurrentTimeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollTimelineCurrentTime;
using ScopedScrollTopLeftInteropForTest = RuntimeEnabledFeaturesTestHelpers::ScopedScrollTopLeftInterop;
using ScopedSearchTextHighlightPseudoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSearchTextHighlightPseudo;
using ScopedSecurePaymentConfirmationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSecurePaymentConfirmation;
using ScopedSecurePaymentConfirmationDebugForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSecurePaymentConfirmationDebug;
using ScopedSecurePaymentConfirmationNetworkAndIssuerIconsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSecurePaymentConfirmationNetworkAndIssuerIcons;
using ScopedSecurePaymentConfirmationOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSecurePaymentConfirmationOptOut;
using ScopedSelectAudioOutputForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectAudioOutput;
using ScopedSelectedcontentelementAttributeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectedcontentelementAttribute;
using ScopedSelectionAcrossShadowDOMForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectionAcrossShadowDOM;
using ScopedSelectionIsCollapsedShadowDOMSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectionIsCollapsedShadowDOMSupport;
using ScopedSelectionOnShadowDOMWithDelegatesFocusForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectionOnShadowDOMWithDelegatesFocus;
using ScopedSelectOptionAccessibilityTargetSizeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectOptionAccessibilityTargetSize;
using ScopedSelectParserRelaxationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectParserRelaxation;
using ScopedSelectPopupLessUpdatesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSelectPopupLessUpdates;
using ScopedSendBeaconThrowForBlobWithNonSimpleTypeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSendBeaconThrowForBlobWithNonSimpleType;
using ScopedSensorExtraClassesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSensorExtraClasses;
using ScopedSerialForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSerial;
using ScopedSerializeViewTransitionStateInSPAForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSerializeViewTransitionStateInSPA;
using ScopedSerialPortConnectedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSerialPortConnected;
using ScopedServiceWorkerClientLifecycleStateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedServiceWorkerClientLifecycleState;
using ScopedServiceWorkerStaticRouterForTest = RuntimeEnabledFeaturesTestHelpers::ScopedServiceWorkerStaticRouter;
using ScopedServiceWorkerStaticRouterTimingInfoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedServiceWorkerStaticRouterTimingInfo;
using ScopedSetSequentialFocusStartingPointForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSetSequentialFocusStartingPoint;
using ScopedShadowRootReferenceTargetForTest = RuntimeEnabledFeaturesTestHelpers::ScopedShadowRootReferenceTarget;
using ScopedShapeOutsideWritingModeFixForTest = RuntimeEnabledFeaturesTestHelpers::ScopedShapeOutsideWritingModeFix;
using ScopedShapeResultCachedPreviousSafeToBreakOffsetForTest = RuntimeEnabledFeaturesTestHelpers::ScopedShapeResultCachedPreviousSafeToBreakOffset;
using ScopedSharedArrayBufferForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedArrayBuffer;
using ScopedSharedArrayBufferOnDesktopForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedArrayBufferOnDesktop;
using ScopedSharedArrayBufferUnrestrictedAccessAllowedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedArrayBufferUnrestrictedAccessAllowed;
using ScopedSharedAutofillForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedAutofill;
using ScopedSharedStorageAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedStorageAPI;
using ScopedSharedStorageAPIM118ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedStorageAPIM118;
using ScopedSharedStorageAPIM125ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedStorageAPIM125;
using ScopedSharedStorageWebLocksForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedStorageWebLocks;
using ScopedSharedWorkerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSharedWorker;
using ScopedSidewaysWritingModesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSidewaysWritingModes;
using ScopedSignatureBasedIntegrityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSignatureBasedIntegrity;
using ScopedSiteInitiatedMirroringForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSiteInitiatedMirroring;
using ScopedSkipAdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSkipAd;
using ScopedSkipPreloadScanningForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSkipPreloadScanning;
using ScopedSkipTemporaryDocumentFragmentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSkipTemporaryDocumentFragment;
using ScopedSkipTouchEventFilterForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSkipTouchEventFilter;
using ScopedSmartCardForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSmartCard;
using ScopedSmartZoomForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSmartZoom;
using ScopedSmilAutoSuspendOnLagForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSmilAutoSuspendOnLag;
using ScopedSoftNavigationDetectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSoftNavigationDetection;
using ScopedSoftNavigationHeuristicsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSoftNavigationHeuristics;
using ScopedSoftNavigationHeuristicsExposeFPAndFCPForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSoftNavigationHeuristicsExposeFPAndFCP;
using ScopedSpeakerSelectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSpeakerSelection;
using ScopedSpeculationRulesPointerDownHeuristicsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSpeculationRulesPointerDownHeuristics;
using ScopedSpeculationRulesPointerHoverHeuristicsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSpeculationRulesPointerHoverHeuristics;
using ScopedSpeculationRulesPrefetchFutureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSpeculationRulesPrefetchFuture;
using ScopedSpeculationRulesPrefetchWithSubresourcesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSpeculationRulesPrefetchWithSubresources;
using ScopedSrcsetMaxDensityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSrcsetMaxDensity;
using ScopedStableBlinkFeaturesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStableBlinkFeatures;
using ScopedStandardizedBrowserZoomForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStandardizedBrowserZoom;
using ScopedStandardizedBrowserZoomOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStandardizedBrowserZoomOptOut;
using ScopedStaticAnimationOptimizationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStaticAnimationOptimization;
using ScopedStorageAccessHeaderForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStorageAccessHeader;
using ScopedStorageBucketsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStorageBuckets;
using ScopedStorageBucketsDurabilityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStorageBucketsDurability;
using ScopedStorageBucketsLocksForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStorageBucketsLocks;
using ScopedStricterCellWidthContentSizeQuirkForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStricterCellWidthContentSizeQuirk;
using ScopedStrictMimeTypesForWorkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStrictMimeTypesForWorkers;
using ScopedStylusHandwritingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedStylusHandwriting;
using ScopedSvgContextPaintForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgContextPaint;
using ScopedSvgCrossOriginAttributeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgCrossOriginAttribute;
using ScopedSvgEagerPresAttrStyleUpdateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgEagerPresAttrStyleUpdate;
using ScopedSvgExternalResourcesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgExternalResources;
using ScopedSvgFilterUserSpaceViewportForNonSvgForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgFilterUserSpaceViewportForNonSvg;
using ScopedSvgGradientColorInterpolationLinearRgbSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgGradientColorInterpolationLinearRgbSupport;
using ScopedSvgInlineRootPixelSnappingScaleAdjustmentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgInlineRootPixelSnappingScaleAdjustment;
using ScopedSvgNoPixelSnappingScaleAdjustmentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgNoPixelSnappingScaleAdjustment;
using ScopedSvgTransformOptimizationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSvgTransformOptimization;
using ScopedSynthesizedKeyboardEventsForAccessibilityActionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSynthesizedKeyboardEventsForAccessibilityActions;
using ScopedSystemFallbackEmojiVSSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSystemFallbackEmojiVSSupport;
using ScopedSystemWakeLockForTest = RuntimeEnabledFeaturesTestHelpers::ScopedSystemWakeLock;
using ScopedTestBlinkFeatureDefaultForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestBlinkFeatureDefault;
using ScopedTestFeatureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeature;
using ScopedTestFeatureDependentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureDependent;
using ScopedTestFeatureImpliedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureImplied;
using ScopedTestFeatureProtectedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureProtected;
using ScopedTestFeatureProtectedDependentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureProtectedDependent;
using ScopedTestFeatureProtectedImpliedForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureProtectedImplied;
using ScopedTestFeatureStableForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTestFeatureStable;
using ScopedTextDetectorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextDetector;
using ScopedTextDiffSplitFixForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextDiffSplitFix;
using ScopedTextFragmentAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextFragmentAPI;
using ScopedTextFragmentIdentifiersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextFragmentIdentifiers;
using ScopedTextFragmentTapOpensContextMenuForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextFragmentTapOpensContextMenu;
using ScopedTextInputNotAlwaysDirAutoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextInputNotAlwaysDirAuto;
using ScopedTextMetricsBaselinesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextMetricsBaselines;
using ScopedTextSegmentBoundaryForElementWithFloatStyleForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextSegmentBoundaryForElementWithFloatStyle;
using ScopedTextSizeAdjustImprovementsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextSizeAdjustImprovements;
using ScopedTextTransformAndSecurityFixForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTextTransformAndSecurityFix;
using ScopedTimelineScopeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTimelineScope;
using ScopedTimerThrottlingForBackgroundTabsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTimerThrottlingForBackgroundTabs;
using ScopedTimestampBasedCLSTrackingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTimestampBasedCLSTracking;
using ScopedTimeZoneChangeEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTimeZoneChangeEvent;
using ScopedTopicsAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTopicsAPI;
using ScopedTopicsDocumentAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTopicsDocumentAPI;
using ScopedTopLayerInactiveDocumentExceptionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTopLayerInactiveDocumentExceptions;
using ScopedTopLevelTpcdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTopLevelTpcd;
using ScopedTouchDragAndContextMenuForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTouchDragAndContextMenu;
using ScopedTouchDragOnShortPressForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTouchDragOnShortPress;
using ScopedTouchEventFeatureDetectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTouchEventFeatureDetection;
using ScopedTouchTextEditingRedesignForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTouchTextEditingRedesign;
using ScopedTpcdForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTpcd;
using ScopedTransferableRTCDataChannelForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTransferableRTCDataChannel;
using ScopedTranslateServiceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTranslateService;
using ScopedTranslationAPIForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTranslationAPI;
using ScopedTranslationAPIEntryPointForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTranslationAPIEntryPoint;
using ScopedTrustedTypeBeforePolicyCreationEventForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTrustedTypeBeforePolicyCreationEvent;
using ScopedTrustedTypesFromLiteralForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTrustedTypesFromLiteral;
using ScopedTrustedTypesUseCodeLikeForTest = RuntimeEnabledFeaturesTestHelpers::ScopedTrustedTypesUseCodeLike;
using ScopedUnclosedFormControlIsInvalidForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUnclosedFormControlIsInvalid;
using ScopedUnexposedTaskIdsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUnexposedTaskIds;
using ScopedUnownedAnimationsSkipCSSEventsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUnownedAnimationsSkipCSSEvents;
using ScopedUnrestrictedMeasureUserAgentSpecificMemoryForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUnrestrictedMeasureUserAgentSpecificMemory;
using ScopedUnrestrictedSharedArrayBufferForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUnrestrictedSharedArrayBuffer;
using ScopedUnrestrictedUsbForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUnrestrictedUsb;
using ScopedURLPatternCompareComponentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedURLPatternCompareComponent;
using ScopedURLSearchParamsHasAndDeleteMultipleArgsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedURLSearchParamsHasAndDeleteMultipleArgs;
using ScopedUseBeginFramePresentationFeedbackForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUseBeginFramePresentationFeedback;
using ScopedUseLowQualityInterpolationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUseLowQualityInterpolation;
using ScopedUserActivationSameOriginVisibilityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUserActivationSameOriginVisibility;
using ScopedUseSelectionFocusNodeForCaretNavigationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUseSelectionFocusNodeForCaretNavigation;
using ScopedUseUndoStepElementDispatchBeforeInputForTest = RuntimeEnabledFeaturesTestHelpers::ScopedUseUndoStepElementDispatchBeforeInput;
using ScopedV8IdleTasksForTest = RuntimeEnabledFeaturesTestHelpers::ScopedV8IdleTasks;
using ScopedVideoAutoFullscreenForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoAutoFullscreen;
using ScopedVideoFrameMetadataBackgroundBlurForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoFrameMetadataBackgroundBlur;
using ScopedVideoFullscreenOrientationLockForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoFullscreenOrientationLock;
using ScopedVideoRotateToFullscreenForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoRotateToFullscreen;
using ScopedVideoTrackGeneratorForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoTrackGenerator;
using ScopedVideoTrackGeneratorInWindowForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoTrackGeneratorInWindow;
using ScopedVideoTrackGeneratorInWorkerForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVideoTrackGeneratorInWorker;
using ScopedViewportChangesUpdateTextAutosizingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewportChangesUpdateTextAutosizing;
using ScopedViewportHeightClientHintHeaderForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewportHeightClientHintHeader;
using ScopedViewportSegmentsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewportSegments;
using ScopedViewTransitionDisableSnapBrowserControlsOnHiddenForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionDisableSnapBrowserControlsOnHidden;
using ScopedViewTransitionLayeredCaptureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionLayeredCapture;
using ScopedViewTransitionLongCallbackTimeoutForTestingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionLongCallbackTimeoutForTesting;
using ScopedViewTransitionOnNavigationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionOnNavigation;
using ScopedViewTransitionOnNavigationForIframesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionOnNavigationForIframes;
using ScopedViewTransitionOverflowRectFromSurfaceForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionOverflowRectFromSurface;
using ScopedViewTransitionTreeScopedNamesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionTreeScopedNames;
using ScopedViewTransitionTypesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedViewTransitionTypes;
using ScopedVisibilityCollapseColumnForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVisibilityCollapseColumn;
using ScopedVisualViewportOnScrollEndForTest = RuntimeEnabledFeaturesTestHelpers::ScopedVisualViewportOnScrollEnd;
using ScopedWakeLockForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWakeLock;
using ScopedWarnOnContentVisibilityRenderAccessForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWarnOnContentVisibilityRenderAccess;
using ScopedWebAnimationsSVGForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAnimationsSVG;
using ScopedWebAppInstallationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppInstallation;
using ScopedWebAppLaunchQueueForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppLaunchQueue;
using ScopedWebAppScopeExtensionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppScopeExtensions;
using ScopedWebAppTabStripForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppTabStrip;
using ScopedWebAppTabStripCustomizationsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppTabStripCustomizations;
using ScopedWebAppTranslationsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppTranslations;
using ScopedWebAppUrlHandlingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAppUrlHandling;
using ScopedWebAssemblyJSPromiseIntegrationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAssemblyJSPromiseIntegration;
using ScopedWebAssemblyJSStringBuiltinsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAssemblyJSStringBuiltins;
using ScopedWebAudioBypassOutputBufferingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAudioBypassOutputBuffering;
using ScopedWebAudioBypassOutputBufferingOptOutForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAudioBypassOutputBufferingOptOut;
using ScopedWebAuthForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuth;
using ScopedWebAuthAuthenticatorAttachmentForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthAuthenticatorAttachment;
using ScopedWebAuthenticationAmbientForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationAmbient;
using ScopedWebAuthenticationAttestationFormatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationAttestationFormats;
using ScopedWebAuthenticationClientCapabilitiesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationClientCapabilities;
using ScopedWebAuthenticationJSONSerializationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationJSONSerialization;
using ScopedWebAuthenticationLargeBlobExtensionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationLargeBlobExtension;
using ScopedWebAuthenticationPRFForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationPRF;
using ScopedWebAuthenticationRemoteDesktopSupportForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationRemoteDesktopSupport;
using ScopedWebAuthenticationSupplementalPubKeysForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebAuthenticationSupplementalPubKeys;
using ScopedWebBluetoothForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetooth;
using ScopedWebBluetoothGetDevicesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothGetDevices;
using ScopedWebBluetoothScanningForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothScanning;
using ScopedWebBluetoothWatchAdvertisementsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebBluetoothWatchAdvertisements;
using ScopedWebCodecsCopyToRGBForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebCodecsCopyToRGB;
using ScopedWebCodecsHBDFormatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebCodecsHBDFormats;
using ScopedWebCodecsOrientationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebCodecsOrientation;
using ScopedWebCodecsVideoEncoderBuffersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebCodecsVideoEncoderBuffers;
using ScopedWebCryptoCurve25519ForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebCryptoCurve25519;
using ScopedWebFontResizeLCPForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebFontResizeLCP;
using ScopedWebGLDeveloperExtensionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGLDeveloperExtensions;
using ScopedWebGLDraftExtensionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGLDraftExtensions;
using ScopedWebGLDrawingBufferStorageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGLDrawingBufferStorage;
using ScopedWebGLImageChromiumForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGLImageChromium;
using ScopedWebGPUCanvasContextGetConfigurationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUCanvasContextGetConfiguration;
using ScopedWebGPUDeveloperFeaturesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUDeveloperFeatures;
using ScopedWebGPUDeviceAdapterInfoForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUDeviceAdapterInfo;
using ScopedWebGPUExperimentalFeaturesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUExperimentalFeatures;
using ScopedWebGPUHDRForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUHDR;
using ScopedWebGPUSubgroupsFeaturesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUSubgroupsFeatures;
using ScopedWebGPUTextureViewUsageForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebGPUTextureViewUsage;
using ScopedWebHIDForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebHID;
using ScopedWebHIDOnDedicatedWorkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebHIDOnDedicatedWorkers;
using ScopedWebHIDOnServiceWorkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebHIDOnServiceWorkers;
using ScopedWebIdentityDigitalCredentialsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebIdentityDigitalCredentials;
using ScopedWebIDLBigIntUsesToBigIntForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebIDLBigIntUsesToBigInt;
using ScopedWebNFCForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebNFC;
using ScopedWebOTPForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebOTP;
using ScopedWebOTPAssertionFeaturePolicyForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebOTPAssertionFeaturePolicy;
using ScopedWebPreferencesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebPreferences;
using ScopedWebPrintingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebPrinting;
using ScopedWebShareForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebShare;
using ScopedWebSocketStreamForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebSocketStream;
using ScopedWebTransportCustomCertificatesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebTransportCustomCertificates;
using ScopedWebTransportStatsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebTransportStats;
using ScopedWebUSBForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebUSB;
using ScopedWebUSBOnDedicatedWorkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebUSBOnDedicatedWorkers;
using ScopedWebUSBOnServiceWorkersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebUSBOnServiceWorkers;
using ScopedWebViewXRequestedWithDeprecationForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebViewXRequestedWithDeprecation;
using ScopedWebVTTRegionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebVTTRegions;
using ScopedWebXRForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXR;
using ScopedWebXREnabledFeaturesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXREnabledFeatures;
using ScopedWebXRFrameRateForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRFrameRate;
using ScopedWebXRFrontFacingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRFrontFacing;
using ScopedWebXRGPUBindingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRGPUBinding;
using ScopedWebXRHandInputForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRHandInput;
using ScopedWebXRHitTestEntityTypesForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRHitTestEntityTypes;
using ScopedWebXRImageTrackingForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRImageTracking;
using ScopedWebXRLayersForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRLayers;
using ScopedWebXRLayersCommonForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRLayersCommon;
using ScopedWebXRPlaneDetectionForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRPlaneDetection;
using ScopedWebXRPoseMotionDataForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRPoseMotionData;
using ScopedWebXRSpecParityForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWebXRSpecParity;
using ScopedWindowDefaultStatusForTest = RuntimeEnabledFeaturesTestHelpers::ScopedWindowDefaultStatus;
using ScopedXMLParserMergeAdjacentCDataSectionsForTest = RuntimeEnabledFeaturesTestHelpers::ScopedXMLParserMergeAdjacentCDataSections;
using ScopedZeroCopyTabCaptureForTest = RuntimeEnabledFeaturesTestHelpers::ScopedZeroCopyTabCapture;
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_TEST_HELPERS_H_
