// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "build/build_config.h"
#include "build/chromeos_buildflags.h"

#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_feature.mojom-shared.h"
#include "third_party/blink/renderer/platform/feature_context.h"
#include "third_party/blink/renderer/platform/runtime_feature_state/runtime_feature_state_override_context.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

RuntimeEnabledFeaturesBase::Backup::Backup()
    : is_accelerated_2d_canvas_enabled_(RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_)
    , is_accelerated_small_canvases_enabled_(RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_)
    , is_accessibility_aria_virtual_content_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_)
    , is_accessibility_expose_display_none_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_)
    , is_accessibility_min_role_tabbable_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_min_role_tabbable_enabled_)
    , is_accessibility_os_level_bold_text_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_os_level_bold_text_enabled_)
    , is_accessibility_prohibited_names_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_prohibited_names_enabled_)
    , is_accessibility_serialization_size_metrics_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_serialization_size_metrics_enabled_)
    , is_accessibility_use_ax_position_for_document_markers_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_)
    , is_address_space_enabled_(RuntimeEnabledFeaturesBase::is_address_space_enabled_)
    , is_ad_interest_group_api_enabled_(RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_)
    , is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_(
          RuntimeEnabledFeaturesBase::is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_)
    , is_ad_tagging_enabled_(RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_)
    , is_ai_prompt_api_enabled_(RuntimeEnabledFeaturesBase::is_ai_prompt_api_enabled_)
    , is_ai_prompt_api_for_extension_enabled_(RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_extension_enabled_)
    , is_ai_prompt_api_for_web_platform_enabled_(RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_web_platform_enabled_)
    , is_ai_rewriter_api_enabled_(RuntimeEnabledFeaturesBase::is_ai_rewriter_api_enabled_)
    , is_ai_summarization_api_enabled_(RuntimeEnabledFeaturesBase::is_ai_summarization_api_enabled_)
    , is_ai_writer_api_enabled_(RuntimeEnabledFeaturesBase::is_ai_writer_api_enabled_)
    , is_allow_content_initiated_data_url_navigations_enabled_(RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_)
    , is_allow_java_script_to_reset_autofill_state_enabled_(RuntimeEnabledFeaturesBase::is_allow_java_script_to_reset_autofill_state_enabled_)
    , is_allow_preloading_with_csp_meta_tag_enabled_(RuntimeEnabledFeaturesBase::is_allow_preloading_with_csp_meta_tag_enabled_)
    , is_allow_ur_ns_in_iframes_enabled_(RuntimeEnabledFeaturesBase::is_allow_ur_ns_in_iframes_enabled_)
    , is_android_downloadable_fonts_matching_enabled_(RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_)
    , is_animation_progress_api_enabled_(RuntimeEnabledFeaturesBase::is_animation_progress_api_enabled_)
    , is_animation_worklet_enabled_(RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_)
    , is_anonymous_iframe_enabled_(RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_)
    , is_aom_aria_relationship_properties_enabled_(RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_)
    , is_aom_aria_relationship_properties_aria_owns_enabled_(RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_aria_owns_enabled_)
    , is_app_title_enabled_(RuntimeEnabledFeaturesBase::is_app_title_enabled_)
    , is_aria_actions_enabled_(RuntimeEnabledFeaturesBase::is_aria_actions_enabled_)
    , is_aria_notify_enabled_(RuntimeEnabledFeaturesBase::is_aria_notify_enabled_)
    , is_aria_row_col_index_text_enabled_(RuntimeEnabledFeaturesBase::is_aria_row_col_index_text_enabled_)
    , is_atomic_move_api_enabled_(RuntimeEnabledFeaturesBase::is_atomic_move_api_enabled_)
    , is_attribution_reporting_enabled_(RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_)
    , is_attribution_reporting_cross_app_web_enabled_(RuntimeEnabledFeaturesBase::is_attribution_reporting_cross_app_web_enabled_)
    , is_attribution_reporting_interface_enabled_(RuntimeEnabledFeaturesBase::is_attribution_reporting_interface_enabled_)
    , is_audio_context_interrupted_state_enabled_(RuntimeEnabledFeaturesBase::is_audio_context_interrupted_state_enabled_)
    , is_audio_context_on_error_enabled_(RuntimeEnabledFeaturesBase::is_audio_context_on_error_enabled_)
    , is_audio_context_playout_stats_enabled_(RuntimeEnabledFeaturesBase::is_audio_context_playout_stats_enabled_)
    , is_audio_context_set_sink_id_enabled_(RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_)
    , is_audio_output_devices_enabled_(RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_)
    , is_audio_video_tracks_enabled_(RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_)
    , is_aura_scrollbar_uses_nine_patch_track_enabled_(RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_nine_patch_track_enabled_)
    , is_aura_scrollbar_uses_solid_color_thumb_enabled_(RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_solid_color_thumb_enabled_)
    , is_auto_dark_mode_enabled_(RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_)
    , is_automation_controlled_enabled_(RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_)
    , is_auto_picture_in_picture_video_heuristics_enabled_(RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_video_heuristics_enabled_)
    , is_backface_visibility_interop_enabled_(RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_)
    , is_back_forward_cache_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_)
    , is_back_forward_cache_experiment_http_header_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_)
    , is_back_forward_cache_not_restored_reasons_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_)
    , is_back_forward_transitions_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_transitions_enabled_)
    , is_background_fetch_enabled_(RuntimeEnabledFeaturesBase::is_background_fetch_enabled_)
    , is_barcode_detector_enabled_(RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_)
    , is_bidi_caret_affinity_enabled_(RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_)
    , is_blink_extension_chrome_os_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_)
    , is_blink_extension_chrome_os_kiosk_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_kiosk_enabled_)
    , is_blink_extension_diagnostics_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_diagnostics_enabled_)
    , is_blink_extension_web_view_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_web_view_enabled_)
    , is_blink_extension_web_view_media_integrity_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_web_view_media_integrity_enabled_)
    , is_blink_lifecycle_script_forbidden_enabled_(RuntimeEnabledFeaturesBase::is_blink_lifecycle_script_forbidden_enabled_)
    , is_blink_runtime_call_stats_enabled_(RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_)
    , is_blocking_focus_without_user_activation_enabled_(RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_)
    , is_boundary_event_dispatch_tracks_node_removal_enabled_(RuntimeEnabledFeaturesBase::is_boundary_event_dispatch_tracks_node_removal_enabled_)
    , is_box_decoration_break_enabled_(RuntimeEnabledFeaturesBase::is_box_decoration_break_enabled_)
    , is_break_iterator_hyphen_minus_enabled_(RuntimeEnabledFeaturesBase::is_break_iterator_hyphen_minus_enabled_)
    , is_browser_verified_user_activation_keyboard_enabled_(RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_)
    , is_browser_verified_user_activation_mouse_enabled_(RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_)
    , is_buffered_bytes_consumer_limit_size_enabled_(RuntimeEnabledFeaturesBase::is_buffered_bytes_consumer_limit_size_enabled_)
    , is_built_in_aiapi_enabled_(RuntimeEnabledFeaturesBase::is_built_in_aiapi_enabled_)
    , is_bypass_pepc_security_for_testing_enabled_(RuntimeEnabledFeaturesBase::is_bypass_pepc_security_for_testing_enabled_)
    , is_cache_storage_code_cache_hint_enabled_(RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_)
    , is_calendar_picker_month_popup_button_disabled_color_enabled_(RuntimeEnabledFeaturesBase::is_calendar_picker_month_popup_button_disabled_color_enabled_)
    , is_call_exit_node_without_layout_object_enabled_(RuntimeEnabledFeaturesBase::is_call_exit_node_without_layout_object_enabled_)
    , is_canvas_2d_canvas_filter_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_canvas_filter_enabled_)
    , is_canvas_2d_gpu_transfer_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_gpu_transfer_enabled_)
    , is_canvas_2d_image_chromium_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_)
    , is_canvas_2d_layers_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_)
    , is_canvas_2d_layers_with_options_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_layers_with_options_enabled_)
    , is_canvas_2d_mesh_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_mesh_enabled_)
    , is_canvas_2d_text_metrics_shaping_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_text_metrics_shaping_enabled_)
    , is_canvas_floating_point_enabled_(RuntimeEnabledFeaturesBase::is_canvas_floating_point_enabled_)
    , is_canvas_hdr_enabled_(RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_)
    , is_canvas_image_smoothing_enabled_(RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_)
    , is_canvas_place_element_enabled_(RuntimeEnabledFeaturesBase::is_canvas_place_element_enabled_)
    , is_canvas_uses_arc_paint_op_enabled_(RuntimeEnabledFeaturesBase::is_canvas_uses_arc_paint_op_enabled_)
    , is_capability_delegation_display_capture_request_enabled_(RuntimeEnabledFeaturesBase::is_capability_delegation_display_capture_request_enabled_)
    , is_capture_controller_enabled_(RuntimeEnabledFeaturesBase::is_capture_controller_enabled_)
    , is_captured_mouse_events_enabled_(RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_)
    , is_captured_surface_control_enabled_(RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_)
    , is_capture_handle_enabled_(RuntimeEnabledFeaturesBase::is_capture_handle_enabled_)
    , is_caret_position_from_point_enabled_(RuntimeEnabledFeaturesBase::is_caret_position_from_point_enabled_)
    , is_cct_new_rfm_push_behavior_enabled_(RuntimeEnabledFeaturesBase::is_cct_new_rfm_push_behavior_enabled_)
    , is_check_if_highest_root_contains_position_anchor_node_enabled_(
          RuntimeEnabledFeaturesBase::is_check_if_highest_root_contains_position_anchor_node_enabled_)
    , is_check_visibility_extra_properties_enabled_(RuntimeEnabledFeaturesBase::is_check_visibility_extra_properties_enabled_)
    , is_click_to_captured_pointer_enabled_(RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_)
    , is_clipboard_item_with_dom_string_support_enabled_(RuntimeEnabledFeaturesBase::is_clipboard_item_with_dom_string_support_enabled_)
    , is_clip_path_reject_empty_paths_enabled_(RuntimeEnabledFeaturesBase::is_clip_path_reject_empty_paths_enabled_)
    , is_coalesce_selectionchange_event_enabled_(RuntimeEnabledFeaturesBase::is_coalesce_selectionchange_event_enabled_)
    , is_coep_reflection_enabled_(RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_)
    , is_composite_bg_color_animation_enabled_(RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_)
    , is_composite_box_shadow_animation_enabled_(RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_)
    , is_composite_clip_path_animation_enabled_(RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_)
    , is_composited_animations_cancelled_asynchronously_enabled_(RuntimeEnabledFeaturesBase::is_composited_animations_cancelled_asynchronously_enabled_)
    , is_composited_selection_update_enabled_(RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_)
    , is_composition_foreground_markers_enabled_(RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_)
    , is_compression_dictionary_transport_enabled_(RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_enabled_)
    , is_compression_dictionary_transport_backend_enabled_(RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_backend_enabled_)
    , is_computed_accessibility_info_enabled_(RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_)
    , is_compute_pressure_enabled_(RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_)
    , is_concurrent_view_transitions_spa_enabled_(RuntimeEnabledFeaturesBase::is_concurrent_view_transitions_spa_enabled_)
    , is_contacts_manager_enabled_(RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_)
    , is_contacts_manager_extra_properties_enabled_(RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_)
    , is_container_type_no_layout_containment_enabled_(RuntimeEnabledFeaturesBase::is_container_type_no_layout_containment_enabled_)
    , is_content_index_enabled_(RuntimeEnabledFeaturesBase::is_content_index_enabled_)
    , is_context_menu_enabled_(RuntimeEnabledFeaturesBase::is_context_menu_enabled_)
    , is_continue_event_timing_recording_when_buffer_is_full_enabled_(
          RuntimeEnabledFeaturesBase::is_continue_event_timing_recording_when_buffer_is_full_enabled_)
    , is_controlled_frame_enabled_(RuntimeEnabledFeaturesBase::is_controlled_frame_enabled_)
    , is_cookie_deprecation_facilitated_testing_enabled_(RuntimeEnabledFeaturesBase::is_cookie_deprecation_facilitated_testing_enabled_)
    , is_cooperative_scheduling_enabled_(RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_)
    , is_coop_restrict_properties_enabled_(RuntimeEnabledFeaturesBase::is_coop_restrict_properties_enabled_)
    , is_cors_rfc_1918_enabled_(RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_)
    , is_create_input_shadow_tree_during_layout_enabled_(RuntimeEnabledFeaturesBase::is_create_input_shadow_tree_during_layout_enabled_)
    , is_credential_manager_report_enabled_(RuntimeEnabledFeaturesBase::is_credential_manager_report_enabled_)
    , is_cross_frame_performance_timeline_enabled_(RuntimeEnabledFeaturesBase::is_cross_frame_performance_timeline_enabled_)
    , is_css_accent_color_keyword_enabled_(RuntimeEnabledFeaturesBase::is_css_accent_color_keyword_enabled_)
    , is_css_advanced_attr_function_enabled_(RuntimeEnabledFeaturesBase::is_css_advanced_attr_function_enabled_)
    , is_css_anchor_scope_enabled_(RuntimeEnabledFeaturesBase::is_css_anchor_scope_enabled_)
    , is_css_anchor_size_insets_margins_enabled_(RuntimeEnabledFeaturesBase::is_css_anchor_size_insets_margins_enabled_)
    , is_css_at_property_string_syntax_enabled_(RuntimeEnabledFeaturesBase::is_css_at_property_string_syntax_enabled_)
    , is_css_at_rule_counter_style_image_symbols_enabled_(RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_)
    , is_css_at_rule_counter_style_speak_as_descriptor_enabled_(RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_)
    , is_css_background_clip_unprefix_enabled_(RuntimeEnabledFeaturesBase::is_css_background_clip_unprefix_enabled_)
    , is_css_calc_simplification_and_serialization_enabled_(RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_)
    , is_css_calc_size_function_enabled_(RuntimeEnabledFeaturesBase::is_css_calc_size_function_enabled_)
    , is_css_caret_animation_enabled_(RuntimeEnabledFeaturesBase::is_css_caret_animation_enabled_)
    , is_css_cascade_correct_scope_enabled_(RuntimeEnabledFeaturesBase::is_css_cascade_correct_scope_enabled_)
    , is_css_case_sensitive_selector_enabled_(RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_)
    , is_css_color_contrast_enabled_(RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_)
    , is_css_color_typed_om_enabled_(RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_)
    , is_css_computed_style_full_pseudo_element_parser_enabled_(RuntimeEnabledFeaturesBase::is_css_computed_style_full_pseudo_element_parser_enabled_)
    , is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_(
          RuntimeEnabledFeaturesBase::is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_)
    , is_css_cross_fade_enabled_(RuntimeEnabledFeaturesBase::is_css_cross_fade_enabled_)
    , is_css_custom_state_deprecated_syntax_enabled_(RuntimeEnabledFeaturesBase::is_css_custom_state_deprecated_syntax_enabled_)
    , is_css_custom_state_new_syntax_enabled_(RuntimeEnabledFeaturesBase::is_css_custom_state_new_syntax_enabled_)
    , is_css_dynamic_range_limit_enabled_(RuntimeEnabledFeaturesBase::is_css_dynamic_range_limit_enabled_)
    , is_css_enumerated_custom_properties_enabled_(RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_)
    , is_css_exponential_functions_enabled_(RuntimeEnabledFeaturesBase::is_css_exponential_functions_enabled_)
    , is_css_flat_tree_container_enabled_(RuntimeEnabledFeaturesBase::is_css_flat_tree_container_enabled_)
    , is_css_font_size_adjust_enabled_(RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_)
    , is_css_functions_enabled_(RuntimeEnabledFeaturesBase::is_css_functions_enabled_)
    , is_css_gap_decoration_enabled_(RuntimeEnabledFeaturesBase::is_css_gap_decoration_enabled_)
    , is_css_hex_alpha_color_enabled_(RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_)
    , is_css_inert_enabled_(RuntimeEnabledFeaturesBase::is_css_inert_enabled_)
    , is_css_inset_area_property_enabled_(RuntimeEnabledFeaturesBase::is_css_inset_area_property_enabled_)
    , is_css_keyframes_rule_length_enabled_(RuntimeEnabledFeaturesBase::is_css_keyframes_rule_length_enabled_)
    , is_css_layout_api_enabled_(RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_)
    , is_css_lazy_parsing_fast_path_enabled_(RuntimeEnabledFeaturesBase::is_css_lazy_parsing_fast_path_enabled_)
    , is_css_line_clamp_enabled_(RuntimeEnabledFeaturesBase::is_css_line_clamp_enabled_)
    , is_css_line_clamp_webkit_box_blockification_enabled_(RuntimeEnabledFeaturesBase::is_css_line_clamp_webkit_box_blockification_enabled_)
    , is_css_logical_overflow_enabled_(RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_)
    , is_css_marker_nested_pseudo_element_enabled_(RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_)
    , is_css_masonry_layout_enabled_(RuntimeEnabledFeaturesBase::is_css_masonry_layout_enabled_)
    , is_css_mixins_enabled_(RuntimeEnabledFeaturesBase::is_css_mixins_enabled_)
    , is_css_nested_declarations_enabled_(RuntimeEnabledFeaturesBase::is_css_nested_declarations_enabled_)
    , is_css_nested_pseudo_elements_enabled_(RuntimeEnabledFeaturesBase::is_css_nested_pseudo_elements_enabled_)
    , is_css_overflow_container_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_overflow_container_queries_enabled_)
    , is_css_paint_api_arguments_enabled_(RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_)
    , is_css_parser_ignore_charset_for_urls_enabled_(RuntimeEnabledFeaturesBase::is_css_parser_ignore_charset_for_urls_enabled_)
    , is_css_part_allows_more_selectors_after_enabled_(RuntimeEnabledFeaturesBase::is_css_part_allows_more_selectors_after_enabled_)
    , is_css_position_area_value_enabled_(RuntimeEnabledFeaturesBase::is_css_position_area_value_enabled_)
    , is_css_position_sticky_static_scroll_position_enabled_(RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_)
    , is_css_progress_notation_enabled_(RuntimeEnabledFeaturesBase::is_css_progress_notation_enabled_)
    , is_css_pseudo_column_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_column_enabled_)
    , is_css_pseudo_has_slotted_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_has_slotted_enabled_)
    , is_css_pseudo_open_closed_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_open_closed_enabled_)
    , is_css_pseudo_playing_paused_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_)
    , is_css_pseudo_scroll_buttons_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_buttons_enabled_)
    , is_css_pseudo_scroll_markers_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_markers_enabled_)
    , is_css_reading_flow_enabled_(RuntimeEnabledFeaturesBase::is_css_reading_flow_enabled_)
    , is_css_relative_color_enabled_(RuntimeEnabledFeaturesBase::is_css_relative_color_enabled_)
    , is_css_relative_color_late_resolve_always_enabled_(RuntimeEnabledFeaturesBase::is_css_relative_color_late_resolve_always_enabled_)
    , is_css_relative_color_preserve_none_enabled_(RuntimeEnabledFeaturesBase::is_css_relative_color_preserve_none_enabled_)
    , is_css_relative_color_supports_currentcolor_enabled_(RuntimeEnabledFeaturesBase::is_css_relative_color_supports_currentcolor_enabled_)
    , is_css_resize_auto_enabled_(RuntimeEnabledFeaturesBase::is_css_resize_auto_enabled_)
    , is_css_scroll_snap_change_event_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_snap_change_event_enabled_)
    , is_css_scroll_snap_changing_event_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_snap_changing_event_enabled_)
    , is_css_scroll_snap_events_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_snap_events_enabled_)
    , is_css_scroll_start_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_start_enabled_)
    , is_css_scroll_start_target_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_start_target_enabled_)
    , is_css_scroll_state_container_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_state_container_queries_enabled_)
    , is_css_selector_fragment_anchor_enabled_(RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_)
    , is_css_sign_related_functions_enabled_(RuntimeEnabledFeaturesBase::is_css_sign_related_functions_enabled_)
    , is_css_snap_container_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_snap_container_queries_enabled_)
    , is_css_stepped_value_functions_enabled_(RuntimeEnabledFeaturesBase::is_css_stepped_value_functions_enabled_)
    , is_css_sticky_container_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_sticky_container_queries_enabled_)
    , is_css_supports_at_rule_function_enabled_(RuntimeEnabledFeaturesBase::is_css_supports_at_rule_function_enabled_)
    , is_css_supports_for_import_rules_enabled_(RuntimeEnabledFeaturesBase::is_css_supports_for_import_rules_enabled_)
    , is_css_system_accent_color_enabled_(RuntimeEnabledFeaturesBase::is_css_system_accent_color_enabled_)
    , is_css_text_auto_space_enabled_(RuntimeEnabledFeaturesBase::is_css_text_auto_space_enabled_)
    , is_css_text_box_trim_enabled_(RuntimeEnabledFeaturesBase::is_css_text_box_trim_enabled_)
    , is_css_text_spacing_enabled_(RuntimeEnabledFeaturesBase::is_css_text_spacing_enabled_)
    , is_css_tree_scoped_timelines_enabled_(RuntimeEnabledFeaturesBase::is_css_tree_scoped_timelines_enabled_)
    , is_css_user_select_contain_enabled_(RuntimeEnabledFeaturesBase::is_css_user_select_contain_enabled_)
    , is_css_video_dynamic_range_media_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_)
    , is_css_view_transition_auto_name_enabled_(RuntimeEnabledFeaturesBase::is_css_view_transition_auto_name_enabled_)
    , is_css_view_transition_class_enabled_(RuntimeEnabledFeaturesBase::is_css_view_transition_class_enabled_)
    , is_cursor_anchor_info_mojo_pipe_enabled_(RuntimeEnabledFeaturesBase::is_cursor_anchor_info_mojo_pipe_enabled_)
    , is_customizable_select_enabled_(RuntimeEnabledFeaturesBase::is_customizable_select_enabled_)
    , is_database_enabled_(RuntimeEnabledFeaturesBase::is_database_enabled_)
    , is_deprecated_request_adapter_info_enabled_(RuntimeEnabledFeaturesBase::is_deprecated_request_adapter_info_enabled_)
    , is_deprecate_unload_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_deprecate_unload_opt_out_enabled_)
    , is_desktop_capture_disable_local_echo_control_enabled_(RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_)
    , is_desktop_pw_as_additional_windowing_controls_enabled_(RuntimeEnabledFeaturesBase::is_desktop_pw_as_additional_windowing_controls_enabled_)
    , is_desktop_pw_as_sub_apps_enabled_(RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_)
    , is_details_styling_enabled_(RuntimeEnabledFeaturesBase::is_details_styling_enabled_)
    , is_device_attributes_enabled_(RuntimeEnabledFeaturesBase::is_device_attributes_enabled_)
    , is_device_orientation_request_permission_enabled_(RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_)
    , is_device_posture_enabled_(RuntimeEnabledFeaturesBase::is_device_posture_enabled_)
    , is_dialog_close_when_open_removed_enabled_(RuntimeEnabledFeaturesBase::is_dialog_close_when_open_removed_enabled_)
    , is_dialog_element_toggle_events_enabled_(RuntimeEnabledFeaturesBase::is_dialog_element_toggle_events_enabled_)
    , is_dialog_new_focus_behavior_enabled_(RuntimeEnabledFeaturesBase::is_dialog_new_focus_behavior_enabled_)
    , is_digital_goods_enabled_(RuntimeEnabledFeaturesBase::is_digital_goods_enabled_)
    , is_digital_goods_v_2_1_enabled_(RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_)
    , is_dir_auto_fix_slot_exclusions_enabled_(RuntimeEnabledFeaturesBase::is_dir_auto_fix_slot_exclusions_enabled_)
    , is_direct_sockets_enabled_(RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_)
    , is_disable_ahem_antialias_enabled_(RuntimeEnabledFeaturesBase::is_disable_ahem_antialias_enabled_)
    , is_disable_different_origin_subframe_dialog_suppression_enabled_(
          RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_)
    , is_disable_hardware_noise_suppression_enabled_(RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_)
    , is_disable_reduce_accept_language_enabled_(RuntimeEnabledFeaturesBase::is_disable_reduce_accept_language_enabled_)
    , is_disable_select_all_for_empty_text_enabled_(RuntimeEnabledFeaturesBase::is_disable_select_all_for_empty_text_enabled_)
    , is_disable_third_party_storage_partitioning_2_enabled_(RuntimeEnabledFeaturesBase::is_disable_third_party_storage_partitioning_2_enabled_)
    , is_dispatch_before_input_for_spin_button_interactions_enabled_(RuntimeEnabledFeaturesBase::is_dispatch_before_input_for_spin_button_interactions_enabled_)
    , is_dispatch_hidden_visibility_transitions_enabled_(RuntimeEnabledFeaturesBase::is_dispatch_hidden_visibility_transitions_enabled_)
    , is_dispatch_selectionchange_event_per_element_enabled_(RuntimeEnabledFeaturesBase::is_dispatch_selectionchange_event_per_element_enabled_)
    , is_display_contents_focusable_enabled_(RuntimeEnabledFeaturesBase::is_display_contents_focusable_enabled_)
    , is_display_cutout_api_enabled_(RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_)
    , is_document_cookie_enabled_(RuntimeEnabledFeaturesBase::is_document_cookie_enabled_)
    , is_document_domain_enabled_(RuntimeEnabledFeaturesBase::is_document_domain_enabled_)
    , is_document_install_chunking_enabled_(RuntimeEnabledFeaturesBase::is_document_install_chunking_enabled_)
    , is_document_isolation_policy_enabled_(RuntimeEnabledFeaturesBase::is_document_isolation_policy_enabled_)
    , is_document_open_origin_alias_removal_enabled_(RuntimeEnabledFeaturesBase::is_document_open_origin_alias_removal_enabled_)
    , is_document_open_sandbox_inheritance_removal_enabled_(RuntimeEnabledFeaturesBase::is_document_open_sandbox_inheritance_removal_enabled_)
    , is_document_picture_in_picture_api_enabled_(RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_)
    , is_document_picture_in_picture_prefer_initial_placement_enabled_(
          RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_)
    , is_document_picture_in_picture_user_activation_enabled_(RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_)
    , is_document_policy_document_domain_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_)
    , is_document_policy_expect_no_linked_resources_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_expect_no_linked_resources_enabled_)
    , is_document_policy_include_js_call_stacks_in_crash_reports_enabled_(
          RuntimeEnabledFeaturesBase::is_document_policy_include_js_call_stacks_in_crash_reports_enabled_)
    , is_document_policy_negotiation_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_)
    , is_document_policy_sync_xhr_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_)
    , is_document_render_blocking_enabled_(RuntimeEnabledFeaturesBase::is_document_render_blocking_enabled_)
    , is_document_write_enabled_(RuntimeEnabledFeaturesBase::is_document_write_enabled_)
    , is_dom_parts_api_enabled_(RuntimeEnabledFeaturesBase::is_dom_parts_api_enabled_)
    , is_dom_parts_api_minimal_enabled_(RuntimeEnabledFeaturesBase::is_dom_parts_api_minimal_enabled_)
    , is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_(
          RuntimeEnabledFeaturesBase::is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_)
    , is_dynamic_safe_area_insets_enabled_(RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_enabled_)
    , is_dynamic_safe_area_insets_on_scroll_enabled_(RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_on_scroll_enabled_)
    , is_element_capture_enabled_(RuntimeEnabledFeaturesBase::is_element_capture_enabled_)
    , is_element_get_inner_html_enabled_(RuntimeEnabledFeaturesBase::is_element_get_inner_html_enabled_)
    , is_enforce_anonymity_exposure_enabled_(RuntimeEnabledFeaturesBase::is_enforce_anonymity_exposure_enabled_)
    , is_escape_lt_gt_in_attributes_enabled_(RuntimeEnabledFeaturesBase::is_escape_lt_gt_in_attributes_enabled_)
    , is_event_timing_handle_keyboard_event_simulated_click_enabled_(RuntimeEnabledFeaturesBase::is_event_timing_handle_keyboard_event_simulated_click_enabled_)
    , is_event_timing_interaction_count_enabled_(RuntimeEnabledFeaturesBase::is_event_timing_interaction_count_enabled_)
    , is_event_timing_selection_auto_scroll_no_interaction_id_enabled_(
          RuntimeEnabledFeaturesBase::is_event_timing_selection_auto_scroll_no_interaction_id_enabled_)
    , is_event_timing_tap_stop_scroll_no_interaction_id_enabled_(RuntimeEnabledFeaturesBase::is_event_timing_tap_stop_scroll_no_interaction_id_enabled_)
    , is_exclude_transparent_texts_from_being_lcp_eligible_enabled_(RuntimeEnabledFeaturesBase::is_exclude_transparent_texts_from_being_lcp_eligible_enabled_)
    , is_experimental_content_security_policy_features_enabled_(RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_)
    , is_experimental_js_profiler_markers_enabled_(RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_)
    , is_experimental_machine_learning_neural_network_enabled_(RuntimeEnabledFeaturesBase::is_experimental_machine_learning_neural_network_enabled_)
    , is_experimental_policies_enabled_(RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_)
    , is_expose_coarsened_render_time_enabled_(RuntimeEnabledFeaturesBase::is_expose_coarsened_render_time_enabled_)
    , is_expose_render_time_non_tao_delayed_image_enabled_(RuntimeEnabledFeaturesBase::is_expose_render_time_non_tao_delayed_image_enabled_)
    , is_extended_text_metrics_enabled_(RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_)
    , is_eye_dropper_api_enabled_(RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_)
    , is_face_detector_enabled_(RuntimeEnabledFeaturesBase::is_face_detector_enabled_)
    , is_fast_non_composited_scroll_hit_test_enabled_(RuntimeEnabledFeaturesBase::is_fast_non_composited_scroll_hit_test_enabled_)
    , is_fast_path_single_selector_exact_match_enabled_(RuntimeEnabledFeaturesBase::is_fast_path_single_selector_exact_match_enabled_)
    , is_fast_position_iterator_enabled_(RuntimeEnabledFeaturesBase::is_fast_position_iterator_enabled_)
    , is_fed_cm_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_enabled_)
    , is_fed_cm_authz_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_authz_enabled_)
    , is_fed_cm_auto_selected_flag_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_auto_selected_flag_enabled_)
    , is_fed_cm_button_mode_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_button_mode_enabled_)
    , is_fed_cm_disconnect_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_disconnect_enabled_)
    , is_fed_cm_domain_hint_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_domain_hint_enabled_)
    , is_fed_cm_error_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_error_enabled_)
    , is_fed_cm_id_p_registration_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_id_p_registration_enabled_)
    , is_fed_cm_idp_signin_status_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_)
    , is_fed_cm_multiple_identity_providers_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_)
    , is_fed_cm_selective_disclosure_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_selective_disclosure_enabled_)
    , is_fed_cm_with_storage_access_api_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_with_storage_access_api_enabled_)
    , is_fenced_frames_enabled_(RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_)
    , is_fenced_frames_api_changes_enabled_(RuntimeEnabledFeaturesBase::is_fenced_frames_api_changes_enabled_)
    , is_fenced_frames_default_mode_enabled_(RuntimeEnabledFeaturesBase::is_fenced_frames_default_mode_enabled_)
    , is_fenced_frames_local_unpartitioned_data_access_enabled_(RuntimeEnabledFeaturesBase::is_fenced_frames_local_unpartitioned_data_access_enabled_)
    , is_fetch_body_bytes_enabled_(RuntimeEnabledFeaturesBase::is_fetch_body_bytes_enabled_)
    , is_fetch_later_api_enabled_(RuntimeEnabledFeaturesBase::is_fetch_later_api_enabled_)
    , is_fetch_upload_streaming_enabled_(RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_)
    , is_file_handling_enabled_(RuntimeEnabledFeaturesBase::is_file_handling_enabled_)
    , is_file_handling_icons_enabled_(RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_)
    , is_file_system_enabled_(RuntimeEnabledFeaturesBase::is_file_system_enabled_)
    , is_file_system_access_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_enabled_)
    , is_file_system_access_api_experimental_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_)
    , is_file_system_access_get_cloud_identifiers_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_)
    , is_file_system_access_local_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_)
    , is_file_system_access_locking_scheme_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_locking_scheme_enabled_)
    , is_file_system_access_origin_private_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_)
    , is_file_system_observer_enabled_(RuntimeEnabledFeaturesBase::is_file_system_observer_enabled_)
    , is_file_system_observer_unobserve_enabled_(RuntimeEnabledFeaturesBase::is_file_system_observer_unobserve_enabled_)
    , is_find_decomposed_in_short_text_enabled_(RuntimeEnabledFeaturesBase::is_find_decomposed_in_short_text_enabled_)
    , is_find_ruby_in_page_enabled_(RuntimeEnabledFeaturesBase::is_find_ruby_in_page_enabled_)
    , is_find_text_in_readonly_text_input_enabled_(RuntimeEnabledFeaturesBase::is_find_text_in_readonly_text_input_enabled_)
    , is_find_text_skip_collapsed_text_enabled_(RuntimeEnabledFeaturesBase::is_find_text_skip_collapsed_text_enabled_)
    , is_fledge_enabled_(RuntimeEnabledFeaturesBase::is_fledge_enabled_)
    , is_fledge_auction_deal_support_enabled_(RuntimeEnabledFeaturesBase::is_fledge_auction_deal_support_enabled_)
    , is_fledge_bidding_and_auction_server_api_enabled_(RuntimeEnabledFeaturesBase::is_fledge_bidding_and_auction_server_api_enabled_)
    , is_fledge_custom_max_auction_ad_components_enabled_(RuntimeEnabledFeaturesBase::is_fledge_custom_max_auction_ad_components_enabled_)
    , is_fledge_deprecated_render_url_replacements_enabled_(RuntimeEnabledFeaturesBase::is_fledge_deprecated_render_url_replacements_enabled_)
    , is_fledge_direct_from_seller_signals_header_ad_slot_enabled_(RuntimeEnabledFeaturesBase::is_fledge_direct_from_seller_signals_header_ad_slot_enabled_)
    , is_fledge_multi_bid_enabled_(RuntimeEnabledFeaturesBase::is_fledge_multi_bid_enabled_)
    , is_fledge_real_time_reporting_enabled_(RuntimeEnabledFeaturesBase::is_fledge_real_time_reporting_enabled_)
    , is_fledge_reporting_timeout_enabled_(RuntimeEnabledFeaturesBase::is_fledge_reporting_timeout_enabled_)
    , is_fledge_seller_nonce_enabled_(RuntimeEnabledFeaturesBase::is_fledge_seller_nonce_enabled_)
    , is_fledge_trusted_signals_k_vv_2_support_enabled_(RuntimeEnabledFeaturesBase::is_fledge_trusted_signals_k_vv_2_support_enabled_)
    , is_fluent_overlay_scrollbars_enabled_(RuntimeEnabledFeaturesBase::is_fluent_overlay_scrollbars_enabled_)
    , is_fluent_scrollbars_enabled_(RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_)
    , is_fluent_scrollbar_uses_nine_patch_track_enabled_(RuntimeEnabledFeaturesBase::is_fluent_scrollbar_uses_nine_patch_track_enabled_)
    , is_focusgroup_enabled_(RuntimeEnabledFeaturesBase::is_focusgroup_enabled_)
    , is_font_access_enabled_(RuntimeEnabledFeaturesBase::is_font_access_enabled_)
    , is_fontations_font_backend_enabled_(RuntimeEnabledFeaturesBase::is_fontations_font_backend_enabled_)
    , is_fontations_for_selected_formats_enabled_(RuntimeEnabledFeaturesBase::is_fontations_for_selected_formats_enabled_)
    , is_font_family_postscript_matching_ct_migration_enabled_(RuntimeEnabledFeaturesBase::is_font_family_postscript_matching_ct_migration_enabled_)
    , is_font_family_style_matching_ct_migration_enabled_(RuntimeEnabledFeaturesBase::is_font_family_style_matching_ct_migration_enabled_)
    , is_font_present_win_enabled_(RuntimeEnabledFeaturesBase::is_font_present_win_enabled_)
    , is_font_src_local_matching_enabled_(RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_)
    , is_font_system_fallback_noto_cjk_enabled_(RuntimeEnabledFeaturesBase::is_font_system_fallback_noto_cjk_enabled_)
    , is_font_variant_emoji_enabled_(RuntimeEnabledFeaturesBase::is_font_variant_emoji_enabled_)
    , is_font_variation_sequences_enabled_(RuntimeEnabledFeaturesBase::is_font_variation_sequences_enabled_)
    , is_forced_colors_enabled_(RuntimeEnabledFeaturesBase::is_forced_colors_enabled_)
    , is_forced_colors_preserve_parent_color_enabled_(RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_)
    , is_force_eager_measure_memory_enabled_(RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_)
    , is_force_reduce_motion_enabled_(RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_)
    , is_force_taller_select_popup_enabled_(RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_)
    , is_form_control_restore_state_if_autocomplete_off_enabled_(RuntimeEnabledFeaturesBase::is_form_control_restore_state_if_autocomplete_off_enabled_)
    , is_form_controls_vertical_writing_mode_direction_support_enabled_(
          RuntimeEnabledFeaturesBase::is_form_controls_vertical_writing_mode_direction_support_enabled_)
    , is_fractional_scroll_offsets_enabled_(RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_)
    , is_freeze_frames_on_visibility_enabled_(RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_)
    , is_gamepad_multitouch_enabled_(RuntimeEnabledFeaturesBase::is_gamepad_multitouch_enabled_)
    , is_get_all_screens_media_enabled_(RuntimeEnabledFeaturesBase::is_get_all_screens_media_enabled_)
    , is_get_display_media_enabled_(RuntimeEnabledFeaturesBase::is_get_display_media_enabled_)
    , is_get_display_media_requires_user_activation_enabled_(RuntimeEnabledFeaturesBase::is_get_display_media_requires_user_activation_enabled_)
    , is_group_effect_enabled_(RuntimeEnabledFeaturesBase::is_group_effect_enabled_)
    , is_handle_selection_change_on_deleting_empty_element_enabled_(RuntimeEnabledFeaturesBase::is_handle_selection_change_on_deleting_empty_element_enabled_)
    , is_handwriting_recognition_enabled_(RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_)
    , is_hanging_whitespace_does_not_depend_on_alignment_enabled_(RuntimeEnabledFeaturesBase::is_hanging_whitespace_does_not_depend_on_alignment_enabled_)
    , is_has_ua_visual_transition_enabled_(RuntimeEnabledFeaturesBase::is_has_ua_visual_transition_enabled_)
    , is_highlight_inheritance_enabled_(RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_)
    , is_highlight_pointer_events_enabled_(RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_)
    , is_highlights_from_point_enabled_(RuntimeEnabledFeaturesBase::is_highlights_from_point_enabled_)
    , is_hit_test_opaqueness_enabled_(RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_enabled_)
    , is_hit_test_opaqueness_omit_line_box_enabled_(RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_omit_line_box_enabled_)
    , is_href_translate_enabled_(RuntimeEnabledFeaturesBase::is_href_translate_enabled_)
    , is_html_anchor_attribute_enabled_(RuntimeEnabledFeaturesBase::is_html_anchor_attribute_enabled_)
    , is_html_dialog_light_dismiss_enabled_(RuntimeEnabledFeaturesBase::is_html_dialog_light_dismiss_enabled_)
    , is_html_embed_element_not_force_layout_enabled_(RuntimeEnabledFeaturesBase::is_html_embed_element_not_force_layout_enabled_)
    , is_html_interest_target_attribute_enabled_(RuntimeEnabledFeaturesBase::is_html_interest_target_attribute_enabled_)
    , is_html_invoke_actions_v_2_enabled_(RuntimeEnabledFeaturesBase::is_html_invoke_actions_v_2_enabled_)
    , is_html_invoke_target_attribute_enabled_(RuntimeEnabledFeaturesBase::is_html_invoke_target_attribute_enabled_)
    , is_html_object_element_fallback_detach_content_frame_enabled_(RuntimeEnabledFeaturesBase::is_html_object_element_fallback_detach_content_frame_enabled_)
    , is_html_parser_yield_and_delay_often_for_testing_enabled_(RuntimeEnabledFeaturesBase::is_html_parser_yield_and_delay_often_for_testing_enabled_)
    , is_html_popover_action_hover_enabled_(RuntimeEnabledFeaturesBase::is_html_popover_action_hover_enabled_)
    , is_html_popover_hint_enabled_(RuntimeEnabledFeaturesBase::is_html_popover_hint_enabled_)
    , is_html_select_element_show_picker_enabled_(RuntimeEnabledFeaturesBase::is_html_select_element_show_picker_enabled_)
    , is_implicit_root_scroller_enabled_(RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_)
    , is_import_attributes_disallow_unknown_keys_enabled_(RuntimeEnabledFeaturesBase::is_import_attributes_disallow_unknown_keys_enabled_)
    , is_import_map_integrity_enabled_(RuntimeEnabledFeaturesBase::is_import_map_integrity_enabled_)
    , is_incoming_call_notifications_enabled_(RuntimeEnabledFeaturesBase::is_incoming_call_notifications_enabled_)
    , is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_(
          RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_)
    , is_indexed_db_get_all_records_enabled_(RuntimeEnabledFeaturesBase::is_indexed_db_get_all_records_enabled_)
    , is_inert_element_non_editable_enabled_(RuntimeEnabledFeaturesBase::is_inert_element_non_editable_enabled_)
    , is_inert_element_non_searchable_enabled_(RuntimeEnabledFeaturesBase::is_inert_element_non_searchable_enabled_)
    , is_infinite_cull_rect_enabled_(RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_)
    , is_inherit_user_modify_without_contenteditable_enabled_(RuntimeEnabledFeaturesBase::is_inherit_user_modify_without_contenteditable_enabled_)
    , is_initial_letter_raise_by_specified_enabled_(RuntimeEnabledFeaturesBase::is_initial_letter_raise_by_specified_enabled_)
    , is_inline_block_in_same_line_enabled_(RuntimeEnabledFeaturesBase::is_inline_block_in_same_line_enabled_)
    , is_inner_html_parser_fastpath_log_failure_enabled_(RuntimeEnabledFeaturesBase::is_inner_html_parser_fastpath_log_failure_enabled_)
    , is_input_closes_select_enabled_(RuntimeEnabledFeaturesBase::is_input_closes_select_enabled_)
    , is_input_multiple_fields_ui_enabled_(RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_)
    , is_insert_blockquote_before_outer_block_enabled_(RuntimeEnabledFeaturesBase::is_insert_blockquote_before_outer_block_enabled_)
    , is_insert_line_break_if_phrasing_content_enabled_(RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_)
    , is_inspector_ghost_rules_enabled_(RuntimeEnabledFeaturesBase::is_inspector_ghost_rules_enabled_)
    , is_installed_app_enabled_(RuntimeEnabledFeaturesBase::is_installed_app_enabled_)
    , is_install_on_device_speech_recognition_enabled_(RuntimeEnabledFeaturesBase::is_install_on_device_speech_recognition_enabled_)
    , is_interest_groups_in_shared_storage_worklet_enabled_(RuntimeEnabledFeaturesBase::is_interest_groups_in_shared_storage_worklet_enabled_)
    , is_interoperable_private_attribution_enabled_(RuntimeEnabledFeaturesBase::is_interoperable_private_attribution_enabled_)
    , is_intersection_observer_scroll_margin_enabled_(RuntimeEnabledFeaturesBase::is_intersection_observer_scroll_margin_enabled_)
    , is_inverted_colors_enabled_(RuntimeEnabledFeaturesBase::is_inverted_colors_enabled_)
    , is_invisible_svg_animation_throttling_enabled_(RuntimeEnabledFeaturesBase::is_invisible_svg_animation_throttling_enabled_)
    , is_java_script_compile_hints_magic_always_runtime_enabled_(RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_always_runtime_enabled_)
    , is_java_script_compile_hints_magic_runtime_enabled_(RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_runtime_enabled_)
    , is_keep_css_target_after_reattach_enabled_(RuntimeEnabledFeaturesBase::is_keep_css_target_after_reattach_enabled_)
    , is_keyboard_accessible_tooltip_enabled_(RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_)
    , is_keyboard_focusable_scrollers_enabled_(RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_)
    , is_keyboard_focusable_scrollers_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_opt_out_enabled_)
    , is_label_and_delegates_focus_new_handling_enabled_(RuntimeEnabledFeaturesBase::is_label_and_delegates_focus_new_handling_enabled_)
    , is_lang_attribute_aware_form_control_ui_enabled_(RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_)
    , is_language_detection_api_enabled_(RuntimeEnabledFeaturesBase::is_language_detection_api_enabled_)
    , is_layout_flex_new_row_algorithm_v_3_enabled_(RuntimeEnabledFeaturesBase::is_layout_flex_new_row_algorithm_v_3_enabled_)
    , is_layout_ignore_margins_for_sticky_enabled_(RuntimeEnabledFeaturesBase::is_layout_ignore_margins_for_sticky_enabled_)
    , is_layout_justify_self_for_blocks_enabled_(RuntimeEnabledFeaturesBase::is_layout_justify_self_for_blocks_enabled_)
    , is_layout_ng_shape_cache_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_shape_cache_enabled_)
    , is_layout_stretch_enabled_(RuntimeEnabledFeaturesBase::is_layout_stretch_enabled_)
    , is_lazy_initialize_media_controls_enabled_(RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_)
    , is_lazy_load_scroll_margin_enabled_(RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_enabled_)
    , is_lazy_load_scroll_margin_iframe_enabled_(RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_iframe_enabled_)
    , is_lcp_animated_images_web_exposed_enabled_(RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_)
    , is_legacy_windows_d_write_font_fallback_enabled_(RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_)
    , is_limit_third_party_cookies_enabled_(RuntimeEnabledFeaturesBase::is_limit_third_party_cookies_enabled_)
    , is_line_box_below_leading_floats_enabled_(RuntimeEnabledFeaturesBase::is_line_box_below_leading_floats_enabled_)
    , is_list_item_with_counter_set_not_set_explicit_value_enabled_(RuntimeEnabledFeaturesBase::is_list_item_with_counter_set_not_set_explicit_value_enabled_)
    , is_locked_mode_enabled_(RuntimeEnabledFeaturesBase::is_locked_mode_enabled_)
    , is_long_animation_frame_timing_enabled_(RuntimeEnabledFeaturesBase::is_long_animation_frame_timing_enabled_)
    , is_long_press_link_select_text_enabled_(RuntimeEnabledFeaturesBase::is_long_press_link_select_text_enabled_)
    , is_long_task_from_long_animation_frame_enabled_(RuntimeEnabledFeaturesBase::is_long_task_from_long_animation_frame_enabled_)
    , is_machine_learning_neural_network_enabled_(RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_)
    , is_managed_configuration_enabled_(RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_)
    , is_measure_memory_enabled_(RuntimeEnabledFeaturesBase::is_measure_memory_enabled_)
    , is_media_capabilities_dynamic_range_enabled_(RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_)
    , is_media_capabilities_encoding_info_enabled_(RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_)
    , is_media_capabilities_spatial_audio_enabled_(RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_)
    , is_media_capture_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_enabled_)
    , is_media_capture_background_blur_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_)
    , is_media_capture_camera_controls_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_camera_controls_enabled_)
    , is_media_capture_configuration_change_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_configuration_change_enabled_)
    , is_media_capture_voice_isolation_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_voice_isolation_enabled_)
    , is_media_cast_overlay_button_enabled_(RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_)
    , is_media_controls_expand_gesture_enabled_(RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_)
    , is_media_controls_overlay_play_button_enabled_(RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_)
    , is_media_element_volume_greater_than_one_enabled_(RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_)
    , is_media_engagement_bypass_autoplay_policies_enabled_(RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_)
    , is_media_latency_hint_enabled_(RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_)
    , is_media_playback_while_not_visible_permission_policy_enabled_(RuntimeEnabledFeaturesBase::is_media_playback_while_not_visible_permission_policy_enabled_)
    , is_media_previews_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_media_previews_opt_out_enabled_)
    , is_media_query_navigation_controls_enabled_(RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_)
    , is_media_recorder_use_media_video_encoder_enabled_(RuntimeEnabledFeaturesBase::is_media_recorder_use_media_video_encoder_enabled_)
    , is_media_session_enabled_(RuntimeEnabledFeaturesBase::is_media_session_enabled_)
    , is_media_session_chapter_information_enabled_(RuntimeEnabledFeaturesBase::is_media_session_chapter_information_enabled_)
    , is_media_session_enter_picture_in_picture_enabled_(RuntimeEnabledFeaturesBase::is_media_session_enter_picture_in_picture_enabled_)
    , is_media_source_experimental_enabled_(RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_)
    , is_media_source_extensions_for_webcodecs_enabled_(RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_)
    , is_media_source_new_abort_and_duration_enabled_(RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_)
    , is_media_stream_track_transfer_enabled_(RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_)
    , is_media_stream_track_web_speech_enabled_(RuntimeEnabledFeaturesBase::is_media_stream_track_web_speech_enabled_)
    , is_message_port_close_event_enabled_(RuntimeEnabledFeaturesBase::is_message_port_close_event_enabled_)
    , is_meta_refresh_no_fractional_enabled_(RuntimeEnabledFeaturesBase::is_meta_refresh_no_fractional_enabled_)
    , is_meter_appearance_none_fallback_style_enabled_(RuntimeEnabledFeaturesBase::is_meter_appearance_none_fallback_style_enabled_)
    , is_meter_devolve_appearance_enabled_(RuntimeEnabledFeaturesBase::is_meter_devolve_appearance_enabled_)
    , is_middle_click_autoscroll_enabled_(RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_)
    , is_minimimal_resource_request_prep_before_cache_lookup_enabled_(
          RuntimeEnabledFeaturesBase::is_minimimal_resource_request_prep_before_cache_lookup_enabled_)
    , is_mobile_layout_theme_enabled_(RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_)
    , is_modify_paragraph_cross_editingoundary_enabled_(RuntimeEnabledFeaturesBase::is_modify_paragraph_cross_editingoundary_enabled_)
    , is_mojo_js_enabled_(RuntimeEnabledFeaturesBase::get_is_mojo_js_enabled_())
    , is_mojo_js_test_enabled_(RuntimeEnabledFeaturesBase::get_is_mojo_js_test_enabled_())
    , is_move_ending_selection_to_list_child_enabled_(RuntimeEnabledFeaturesBase::is_move_ending_selection_to_list_child_enabled_)
    , is_move_to_paragraph_start_or_end_skips_non_editable_enabled_(RuntimeEnabledFeaturesBase::is_move_to_paragraph_start_or_end_skips_non_editable_enabled_)
    , is_multiple_import_maps_enabled_(RuntimeEnabledFeaturesBase::is_multiple_import_maps_enabled_)
    , is_multi_select_deselect_when_only_option_enabled_(RuntimeEnabledFeaturesBase::is_multi_select_deselect_when_only_option_enabled_)
    , is_multi_smooth_scroll_into_view_enabled_(RuntimeEnabledFeaturesBase::is_multi_smooth_scroll_into_view_enabled_)
    , is_mutation_events_enabled_(RuntimeEnabledFeaturesBase::is_mutation_events_enabled_)
    , is_mutation_events_special_trial_message_enabled_(RuntimeEnabledFeaturesBase::is_mutation_events_special_trial_message_enabled_)
    , is_navigate_event_commit_behavior_enabled_(RuntimeEnabledFeaturesBase::is_navigate_event_commit_behavior_enabled_)
    , is_navigate_event_source_element_enabled_(RuntimeEnabledFeaturesBase::is_navigate_event_source_element_enabled_)
    , is_navigation_activation_enabled_(RuntimeEnabledFeaturesBase::is_navigation_activation_enabled_)
    , is_navigation_id_enabled_(RuntimeEnabledFeaturesBase::is_navigation_id_enabled_)
    , is_navigator_content_utils_enabled_(RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_)
    , is_nested_view_transition_enabled_(RuntimeEnabledFeaturesBase::is_nested_view_transition_enabled_)
    , is_net_info_constant_type_enabled_(RuntimeEnabledFeaturesBase::is_net_info_constant_type_enabled_)
    , is_net_info_downlink_max_enabled_(RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_)
    , is_new_get_focusable_area_behavior_enabled_(RuntimeEnabledFeaturesBase::is_new_get_focusable_area_behavior_enabled_)
    , is_no_idle_encoding_for_web_tests_enabled_(RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_)
    , is_no_increasing_end_offset_on_splitting_text_nodes_enabled_(RuntimeEnabledFeaturesBase::is_no_increasing_end_offset_on_splitting_text_nodes_enabled_)
    , is_non_empty_blockquotes_on_outdenting_enabled_(RuntimeEnabledFeaturesBase::is_non_empty_blockquotes_on_outdenting_enabled_)
    , is_non_null_input_event_data_for_text_area_enabled_(RuntimeEnabledFeaturesBase::is_non_null_input_event_data_for_text_area_enabled_)
    , is_non_standard_appearance_value_slider_vertical_enabled_(RuntimeEnabledFeaturesBase::is_non_standard_appearance_value_slider_vertical_enabled_)
    , is_notification_constructor_enabled_(RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_)
    , is_notification_content_image_enabled_(RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_)
    , is_notifications_enabled_(RuntimeEnabledFeaturesBase::is_notifications_enabled_)
    , is_notification_triggers_enabled_(RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_)
    , is_observable_api_enabled_(RuntimeEnabledFeaturesBase::is_observable_api_enabled_)
    , is_off_main_thread_css_paint_enabled_(RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_)
    , is_offscreen_canvas_commit_enabled_(RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_)
    , is_omit_blur_event_on_element_removal_enabled_(RuntimeEnabledFeaturesBase::is_omit_blur_event_on_element_removal_enabled_)
    , is_on_device_change_enabled_(RuntimeEnabledFeaturesBase::is_on_device_change_enabled_)
    , is_on_device_web_speech_available_enabled_(RuntimeEnabledFeaturesBase::is_on_device_web_speech_available_enabled_)
    , is_orientation_event_enabled_(RuntimeEnabledFeaturesBase::is_orientation_event_enabled_)
    , is_origin_isolation_header_enabled_(RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_)
    , is_origin_policy_enabled_(RuntimeEnabledFeaturesBase::is_origin_policy_enabled_)
    , is_origin_trials_sample_api_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_)
    , is_origin_trials_sample_api_browser_read_write_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_browser_read_write_enabled_)
    , is_origin_trials_sample_api_dependent_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_)
    , is_origin_trials_sample_api_deprecation_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_)
    , is_origin_trials_sample_api_expiry_grace_period_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_)
    , is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_(
          RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_)
    , is_origin_trials_sample_api_implied_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_)
    , is_origin_trials_sample_api_invalid_os_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_)
    , is_origin_trials_sample_api_navigation_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_)
    , is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_(
          RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_)
    , is_origin_trials_sample_api_persistent_feature_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_)
    , is_origin_trials_sample_api_persistent_invalid_os_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_invalid_os_enabled_)
    , is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_(
          RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_)
    , is_origin_trials_sample_api_third_party_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_)
    , is_overscroll_customization_enabled_(RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_)
    , is_page_freeze_opt_in_enabled_(RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_)
    , is_page_freeze_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_)
    , is_page_margin_boxes_enabled_(RuntimeEnabledFeaturesBase::is_page_margin_boxes_enabled_)
    , is_page_popup_enabled_(RuntimeEnabledFeaturesBase::is_page_popup_enabled_)
    , is_page_reveal_event_enabled_(RuntimeEnabledFeaturesBase::is_page_reveal_event_enabled_)
    , is_page_swap_event_enabled_(RuntimeEnabledFeaturesBase::is_page_swap_event_enabled_)
    , is_paint_highlights_for_first_letter_enabled_(RuntimeEnabledFeaturesBase::is_paint_highlights_for_first_letter_enabled_)
    , is_paint_holding_for_iframes_enabled_(RuntimeEnabledFeaturesBase::is_paint_holding_for_iframes_enabled_)
    , is_paint_holding_for_local_iframes_enabled_(RuntimeEnabledFeaturesBase::is_paint_holding_for_local_iframes_enabled_)
    , is_paint_under_invalidation_checking_enabled_(RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_)
    , is_parakeet_enabled_(RuntimeEnabledFeaturesBase::is_parakeet_enabled_)
    , is_partitioned_popins_enabled_(RuntimeEnabledFeaturesBase::is_partitioned_popins_enabled_)
    , is_partition_visited_link_database_with_self_links_enabled_(RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_)
    , is_password_reveal_enabled_(RuntimeEnabledFeaturesBase::is_password_reveal_enabled_)
    , is_payment_app_enabled_(RuntimeEnabledFeaturesBase::is_payment_app_enabled_)
    , is_payment_instruments_enabled_(RuntimeEnabledFeaturesBase::is_payment_instruments_enabled_)
    , is_payment_link_detection_enabled_(RuntimeEnabledFeaturesBase::is_payment_link_detection_enabled_)
    , is_payment_method_change_event_enabled_(RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_)
    , is_payment_request_enabled_(RuntimeEnabledFeaturesBase::is_payment_request_enabled_)
    , is_percent_based_scrolling_enabled_(RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_)
    , is_performance_manager_instrumentation_enabled_(RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_)
    , is_performance_mark_feature_usage_enabled_(RuntimeEnabledFeaturesBase::is_performance_mark_feature_usage_enabled_)
    , is_performance_navigate_system_entropy_enabled_(RuntimeEnabledFeaturesBase::is_performance_navigate_system_entropy_enabled_)
    , is_performance_navigation_timing_confidence_enabled_(RuntimeEnabledFeaturesBase::is_performance_navigation_timing_confidence_enabled_)
    , is_periodic_background_sync_enabled_(RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_)
    , is_per_method_can_make_payment_quota_enabled_(RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_)
    , is_permission_element_enabled_(RuntimeEnabledFeaturesBase::is_permission_element_enabled_)
    , is_permissions_enabled_(RuntimeEnabledFeaturesBase::is_permissions_enabled_)
    , is_permissions_request_revoke_enabled_(RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_)
    , is_p_na_cl_enabled_(RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_)
    , is_pointer_event_device_id_enabled_(RuntimeEnabledFeaturesBase::is_pointer_event_device_id_enabled_)
    , is_pointer_event_targets_in_event_lists_enabled_(RuntimeEnabledFeaturesBase::is_pointer_event_targets_in_event_lists_enabled_)
    , is_popover_anchor_relationships_enabled_(RuntimeEnabledFeaturesBase::is_popover_anchor_relationships_enabled_)
    , is_popover_dialog_new_focus_behavior_enabled_(RuntimeEnabledFeaturesBase::is_popover_dialog_new_focus_behavior_enabled_)
    , is_position_outside_tab_span_check_sibling_node_enabled_(RuntimeEnabledFeaturesBase::is_position_outside_tab_span_check_sibling_node_enabled_)
    , is_precise_memory_info_enabled_(RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_)
    , is_prefer_default_scrollbar_styles_enabled_(RuntimeEnabledFeaturesBase::is_prefer_default_scrollbar_styles_enabled_)
    , is_prefer_non_composited_scrolling_enabled_(RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_)
    , is_prefers_reduced_data_enabled_(RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_)
    , is_prefixed_video_fullscreen_enabled_(RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_)
    , is_prerender_2_enabled_(RuntimeEnabledFeaturesBase::is_prerender_2_enabled_)
    , is_presentation_enabled_(RuntimeEnabledFeaturesBase::is_presentation_enabled_)
    , is_preserve_following_block_styles_during_block_merge_enabled_(RuntimeEnabledFeaturesBase::is_preserve_following_block_styles_during_block_merge_enabled_)
    , is_prevent_undo_if_not_editable_enabled_(RuntimeEnabledFeaturesBase::is_prevent_undo_if_not_editable_enabled_)
    , is_private_aggregation_api_filtering_ids_enabled_(RuntimeEnabledFeaturesBase::is_private_aggregation_api_filtering_ids_enabled_)
    , is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_(
          RuntimeEnabledFeaturesBase::is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_)
    , is_private_network_access_non_secure_contexts_allowed_enabled_(RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_)
    , is_private_network_access_null_ip_address_enabled_(RuntimeEnabledFeaturesBase::is_private_network_access_null_ip_address_enabled_)
    , is_private_network_access_permission_prompt_enabled_(RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_)
    , is_private_state_tokens_enabled_(RuntimeEnabledFeaturesBase::is_private_state_tokens_enabled_)
    , is_private_state_tokens_always_allow_issuance_enabled_(RuntimeEnabledFeaturesBase::is_private_state_tokens_always_allow_issuance_enabled_)
    , is_protected_origin_trials_sample_api_enabled_(RuntimeEnabledFeaturesBase::get_is_protected_origin_trials_sample_api_enabled_())
    , is_protected_origin_trials_sample_api_dependent_enabled_(RuntimeEnabledFeaturesBase::get_is_protected_origin_trials_sample_api_dependent_enabled_())
    , is_protected_origin_trials_sample_api_implied_enabled_(RuntimeEnabledFeaturesBase::get_is_protected_origin_trials_sample_api_implied_enabled_())
    , is_pseudo_elements_correct_in_get_computed_style_enabled_(RuntimeEnabledFeaturesBase::is_pseudo_elements_correct_in_get_computed_style_enabled_)
    , is_pseudo_elements_focusable_enabled_(RuntimeEnabledFeaturesBase::is_pseudo_elements_focusable_enabled_)
    , is_push_message_data_bytes_enabled_(RuntimeEnabledFeaturesBase::is_push_message_data_bytes_enabled_)
    , is_push_messaging_enabled_(RuntimeEnabledFeaturesBase::is_push_messaging_enabled_)
    , is_push_messaging_subscription_change_enabled_(RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_)
    , is_quick_intensive_wake_up_throttling_after_loading_enabled_(RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_)
    , is_raster_inducing_scroll_enabled_(RuntimeEnabledFeaturesBase::is_raster_inducing_scroll_enabled_)
    , is_readable_stream_async_iterable_enabled_(RuntimeEnabledFeaturesBase::is_readable_stream_async_iterable_enabled_)
    , is_reduce_accept_language_enabled_(RuntimeEnabledFeaturesBase::is_reduce_accept_language_enabled_)
    , is_reduce_cookie_ip_cs_enabled_(RuntimeEnabledFeaturesBase::is_reduce_cookie_ip_cs_enabled_)
    , is_reduce_user_agent_android_version_device_model_enabled_(RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_)
    , is_reduce_user_agent_minor_version_enabled_(RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_)
    , is_reduce_user_agent_platform_os_cpu_enabled_(RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_)
    , is_region_capture_enabled_(RuntimeEnabledFeaturesBase::is_region_capture_enabled_)
    , is_rel_opener_bcg_dependency_hint_enabled_(RuntimeEnabledFeaturesBase::is_rel_opener_bcg_dependency_hint_enabled_)
    , is_remote_playback_enabled_(RuntimeEnabledFeaturesBase::is_remote_playback_enabled_)
    , is_remote_playback_backend_enabled_(RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_)
    , is_remove_collapsed_placeholder_enabled_(RuntimeEnabledFeaturesBase::is_remove_collapsed_placeholder_enabled_)
    , is_remove_dangling_markup_in_target_enabled_(RuntimeEnabledFeaturesBase::is_remove_dangling_markup_in_target_enabled_)
    , is_remove_data_url_in_svg_use_enabled_(RuntimeEnabledFeaturesBase::is_remove_data_url_in_svg_use_enabled_)
    , is_remove_node_having_children_if_fully_selected_enabled_(RuntimeEnabledFeaturesBase::is_remove_node_having_children_if_fully_selected_enabled_)
    , is_remove_visible_selection_in_dom_selection_enabled_(RuntimeEnabledFeaturesBase::is_remove_visible_selection_in_dom_selection_enabled_)
    , is_render_blocking_inline_module_script_enabled_(RuntimeEnabledFeaturesBase::is_render_blocking_inline_module_script_enabled_)
    , is_render_blocking_status_enabled_(RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_)
    , is_render_priority_attribute_enabled_(RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_)
    , is_report_event_timing_at_visibility_change_enabled_(RuntimeEnabledFeaturesBase::is_report_event_timing_at_visibility_change_enabled_)
    , is_report_visible_line_bounds_enabled_(RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_)
    , is_reset_input_type_to_none_before_character_input_enabled_(RuntimeEnabledFeaturesBase::is_reset_input_type_to_none_before_character_input_enabled_)
    , is_resource_timing_content_type_enabled_(RuntimeEnabledFeaturesBase::is_resource_timing_content_type_enabled_)
    , is_resource_timing_final_response_headers_start_enabled_(RuntimeEnabledFeaturesBase::is_resource_timing_final_response_headers_start_enabled_)
    , is_resource_timing_use_cors_for_body_sizes_enabled_(RuntimeEnabledFeaturesBase::is_resource_timing_use_cors_for_body_sizes_enabled_)
    , is_restrict_gamepad_access_enabled_(RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_)
    , is_reuse_shape_results_by_fonts_enabled_(RuntimeEnabledFeaturesBase::is_reuse_shape_results_by_fonts_enabled_)
    , is_rewind_floats_enabled_(RuntimeEnabledFeaturesBase::is_rewind_floats_enabled_)
    , is_root_element_with_place_holder_after_deleting_selection_enabled_(
          RuntimeEnabledFeaturesBase::is_root_element_with_place_holder_after_deleting_selection_enabled_)
    , is_rtc_audio_jitter_buffer_max_packets_enabled_(RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_)
    , is_rtc_data_channel_priority_enabled_(RuntimeEnabledFeaturesBase::is_rtc_data_channel_priority_enabled_)
    , is_rtc_encoded_audio_frame_abs_capture_time_enabled_(RuntimeEnabledFeaturesBase::is_rtc_encoded_audio_frame_abs_capture_time_enabled_)
    , is_rtc_encoded_frame_set_metadata_enabled_(RuntimeEnabledFeaturesBase::is_rtc_encoded_frame_set_metadata_enabled_)
    , is_rtc_encoded_video_frame_additional_metadata_enabled_(RuntimeEnabledFeaturesBase::is_rtc_encoded_video_frame_additional_metadata_enabled_)
    , is_rtc_jitter_buffer_target_enabled_(RuntimeEnabledFeaturesBase::is_rtc_jitter_buffer_target_enabled_)
    , is_rtc_legacy_callback_based_get_stats_enabled_(RuntimeEnabledFeaturesBase::is_rtc_legacy_callback_based_get_stats_enabled_)
    , is_rtc_rtp_encoding_parameters_codec_enabled_(RuntimeEnabledFeaturesBase::is_rtc_rtp_encoding_parameters_codec_enabled_)
    , is_rtc_rtp_scale_resolution_down_to_enabled_(RuntimeEnabledFeaturesBase::is_rtc_rtp_scale_resolution_down_to_enabled_)
    , is_rtc_rtp_script_transform_enabled_(RuntimeEnabledFeaturesBase::is_rtc_rtp_script_transform_enabled_)
    , is_rtc_rtp_transport_enabled_(RuntimeEnabledFeaturesBase::is_rtc_rtp_transport_enabled_)
    , is_rtc_stats_relative_packet_arrival_delay_enabled_(RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_)
    , is_rtc_svc_scalability_mode_enabled_(RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_)
    , is_ruby_short_heuristics_enabled_(RuntimeEnabledFeaturesBase::is_ruby_short_heuristics_enabled_)
    , is_sanitizer_api_enabled_(RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_)
    , is_scheduler_yield_enabled_(RuntimeEnabledFeaturesBase::is_scheduler_yield_enabled_)
    , is_schedule_selection_change_on_backspace_enabled_(RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_)
    , is_scoped_custom_element_registry_enabled_(RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_)
    , is_scripted_speech_recognition_enabled_(RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_)
    , is_scripted_speech_synthesis_enabled_(RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_)
    , is_scrollbar_color_enabled_(RuntimeEnabledFeaturesBase::is_scrollbar_color_enabled_)
    , is_scrollbar_width_enabled_(RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_)
    , is_scroll_end_events_enabled_(RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_)
    , is_scroll_into_view_root_frame_viewport_bug_fix_enabled_(RuntimeEnabledFeaturesBase::is_scroll_into_view_root_frame_viewport_bug_fix_enabled_)
    , is_scroll_timeline_enabled_(RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_)
    , is_scroll_timeline_current_time_enabled_(RuntimeEnabledFeaturesBase::is_scroll_timeline_current_time_enabled_)
    , is_scroll_top_left_interop_enabled_(RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_)
    , is_search_text_highlight_pseudo_enabled_(RuntimeEnabledFeaturesBase::is_search_text_highlight_pseudo_enabled_)
    , is_secure_payment_confirmation_enabled_(RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_)
    , is_secure_payment_confirmation_debug_enabled_(RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_)
    , is_secure_payment_confirmation_network_and_issuer_icons_enabled_(
          RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_network_and_issuer_icons_enabled_)
    , is_secure_payment_confirmation_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_)
    , is_select_audio_output_enabled_(RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_)
    , is_selectedcontentelement_attribute_enabled_(RuntimeEnabledFeaturesBase::is_selectedcontentelement_attribute_enabled_)
    , is_selection_across_shadow_dom_enabled_(RuntimeEnabledFeaturesBase::is_selection_across_shadow_dom_enabled_)
    , is_selection_is_collapsed_shadow_dom_support_enabled_(RuntimeEnabledFeaturesBase::is_selection_is_collapsed_shadow_dom_support_enabled_)
    , is_selection_on_shadow_dom_with_delegates_focus_enabled_(RuntimeEnabledFeaturesBase::is_selection_on_shadow_dom_with_delegates_focus_enabled_)
    , is_select_option_accessibility_target_size_enabled_(RuntimeEnabledFeaturesBase::is_select_option_accessibility_target_size_enabled_)
    , is_select_parser_relaxation_enabled_(RuntimeEnabledFeaturesBase::is_select_parser_relaxation_enabled_)
    , is_select_popup_less_updates_enabled_(RuntimeEnabledFeaturesBase::is_select_popup_less_updates_enabled_)
    , is_send_beacon_throw_for_blob_with_non_simple_type_enabled_(RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_)
    , is_sensor_extra_classes_enabled_(RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_)
    , is_serial_enabled_(RuntimeEnabledFeaturesBase::is_serial_enabled_)
    , is_serialize_view_transition_state_in_spa_enabled_(RuntimeEnabledFeaturesBase::is_serialize_view_transition_state_in_spa_enabled_)
    , is_serial_port_connected_enabled_(RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_)
    , is_service_worker_client_lifecycle_state_enabled_(RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_)
    , is_service_worker_static_router_enabled_(RuntimeEnabledFeaturesBase::is_service_worker_static_router_enabled_)
    , is_service_worker_static_router_timing_info_enabled_(RuntimeEnabledFeaturesBase::is_service_worker_static_router_timing_info_enabled_)
    , is_set_sequential_focus_starting_point_enabled_(RuntimeEnabledFeaturesBase::is_set_sequential_focus_starting_point_enabled_)
    , is_shadow_root_reference_target_enabled_(RuntimeEnabledFeaturesBase::is_shadow_root_reference_target_enabled_)
    , is_shape_outside_writing_mode_fix_enabled_(RuntimeEnabledFeaturesBase::is_shape_outside_writing_mode_fix_enabled_)
    , is_shape_result_cached_previous_safe_to_break_offset_enabled_(RuntimeEnabledFeaturesBase::is_shape_result_cached_previous_safe_to_break_offset_enabled_)
    , is_shared_array_buffer_enabled_(RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_)
    , is_shared_array_buffer_on_desktop_enabled_(RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_)
    , is_shared_array_buffer_unrestricted_access_allowed_enabled_(RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_)
    , is_shared_autofill_enabled_(RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_)
    , is_shared_storage_api_enabled_(RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_)
    , is_shared_storage_api_m_118_enabled_(RuntimeEnabledFeaturesBase::is_shared_storage_api_m_118_enabled_)
    , is_shared_storage_api_m_125_enabled_(RuntimeEnabledFeaturesBase::is_shared_storage_api_m_125_enabled_)
    , is_shared_storage_web_locks_enabled_(RuntimeEnabledFeaturesBase::is_shared_storage_web_locks_enabled_)
    , is_shared_worker_enabled_(RuntimeEnabledFeaturesBase::is_shared_worker_enabled_)
    , is_sideways_writing_modes_enabled_(RuntimeEnabledFeaturesBase::is_sideways_writing_modes_enabled_)
    , is_signature_based_integrity_enabled_(RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_)
    , is_site_initiated_mirroring_enabled_(RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_)
    , is_skip_ad_enabled_(RuntimeEnabledFeaturesBase::is_skip_ad_enabled_)
    , is_skip_preload_scanning_enabled_(RuntimeEnabledFeaturesBase::is_skip_preload_scanning_enabled_)
    , is_skip_temporary_document_fragment_enabled_(RuntimeEnabledFeaturesBase::is_skip_temporary_document_fragment_enabled_)
    , is_skip_touch_event_filter_enabled_(RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_)
    , is_smart_card_enabled_(RuntimeEnabledFeaturesBase::is_smart_card_enabled_)
    , is_smart_zoom_enabled_(RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_)
    , is_smil_auto_suspend_on_lag_enabled_(RuntimeEnabledFeaturesBase::is_smil_auto_suspend_on_lag_enabled_)
    , is_soft_navigation_detection_enabled_(RuntimeEnabledFeaturesBase::is_soft_navigation_detection_enabled_)
    , is_soft_navigation_heuristics_enabled_(RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_)
    , is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_(RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_)
    , is_speaker_selection_enabled_(RuntimeEnabledFeaturesBase::is_speaker_selection_enabled_)
    , is_speculation_rules_pointer_down_heuristics_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_down_heuristics_enabled_)
    , is_speculation_rules_pointer_hover_heuristics_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_hover_heuristics_enabled_)
    , is_speculation_rules_prefetch_future_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_future_enabled_)
    , is_speculation_rules_prefetch_with_subresources_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_)
    , is_srcset_max_density_enabled_(RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_)
    , is_stable_blink_features_enabled_(RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_)
    , is_standardized_browser_zoom_enabled_(RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_enabled_)
    , is_standardized_browser_zoom_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_opt_out_enabled_)
    , is_static_animation_optimization_enabled_(RuntimeEnabledFeaturesBase::is_static_animation_optimization_enabled_)
    , is_storage_access_header_enabled_(RuntimeEnabledFeaturesBase::is_storage_access_header_enabled_)
    , is_storage_buckets_enabled_(RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_)
    , is_storage_buckets_durability_enabled_(RuntimeEnabledFeaturesBase::is_storage_buckets_durability_enabled_)
    , is_storage_buckets_locks_enabled_(RuntimeEnabledFeaturesBase::is_storage_buckets_locks_enabled_)
    , is_stricter_cell_width_content_size_quirk_enabled_(RuntimeEnabledFeaturesBase::is_stricter_cell_width_content_size_quirk_enabled_)
    , is_strict_mime_types_for_workers_enabled_(RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_)
    , is_stylus_handwriting_enabled_(RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_)
    , is_svg_context_paint_enabled_(RuntimeEnabledFeaturesBase::is_svg_context_paint_enabled_)
    , is_svg_cross_origin_attribute_enabled_(RuntimeEnabledFeaturesBase::is_svg_cross_origin_attribute_enabled_)
    , is_svg_eager_pres_attr_style_update_enabled_(RuntimeEnabledFeaturesBase::is_svg_eager_pres_attr_style_update_enabled_)
    , is_svg_external_resources_enabled_(RuntimeEnabledFeaturesBase::is_svg_external_resources_enabled_)
    , is_svg_filter_user_space_viewport_for_non_svg_enabled_(RuntimeEnabledFeaturesBase::is_svg_filter_user_space_viewport_for_non_svg_enabled_)
    , is_svg_gradient_color_interpolation_linear_rgb_support_enabled_(
          RuntimeEnabledFeaturesBase::is_svg_gradient_color_interpolation_linear_rgb_support_enabled_)
    , is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_(RuntimeEnabledFeaturesBase::is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_)
    , is_svg_no_pixel_snapping_scale_adjustment_enabled_(RuntimeEnabledFeaturesBase::is_svg_no_pixel_snapping_scale_adjustment_enabled_)
    , is_svg_transform_optimization_enabled_(RuntimeEnabledFeaturesBase::is_svg_transform_optimization_enabled_)
    , is_synthesized_keyboard_events_for_accessibility_actions_enabled_(
          RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_)
    , is_system_fallback_emoji_vs_support_enabled_(RuntimeEnabledFeaturesBase::is_system_fallback_emoji_vs_support_enabled_)
    , is_system_wake_lock_enabled_(RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_)
    , is_test_blink_feature_default_enabled_(RuntimeEnabledFeaturesBase::is_test_blink_feature_default_enabled_)
    , is_test_feature_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_enabled_)
    , is_test_feature_dependent_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_)
    , is_test_feature_implied_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_)
    , is_test_feature_protected_enabled_(RuntimeEnabledFeaturesBase::get_is_test_feature_protected_enabled_())
    , is_test_feature_protected_dependent_enabled_(RuntimeEnabledFeaturesBase::get_is_test_feature_protected_dependent_enabled_())
    , is_test_feature_protected_implied_enabled_(RuntimeEnabledFeaturesBase::get_is_test_feature_protected_implied_enabled_())
    , is_test_feature_stable_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_stable_enabled_)
    , is_text_detector_enabled_(RuntimeEnabledFeaturesBase::is_text_detector_enabled_)
    , is_text_diff_split_fix_enabled_(RuntimeEnabledFeaturesBase::is_text_diff_split_fix_enabled_)
    , is_text_fragment_api_enabled_(RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_)
    , is_text_fragment_identifiers_enabled_(RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_)
    , is_text_fragment_tap_opens_context_menu_enabled_(RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_)
    , is_text_input_not_always_dir_auto_enabled_(RuntimeEnabledFeaturesBase::is_text_input_not_always_dir_auto_enabled_)
    , is_text_metrics_baselines_enabled_(RuntimeEnabledFeaturesBase::is_text_metrics_baselines_enabled_)
    , is_text_segment_boundary_for_element_with_float_style_enabled_(RuntimeEnabledFeaturesBase::is_text_segment_boundary_for_element_with_float_style_enabled_)
    , is_text_size_adjust_improvements_enabled_(RuntimeEnabledFeaturesBase::is_text_size_adjust_improvements_enabled_)
    , is_text_transform_and_security_fix_enabled_(RuntimeEnabledFeaturesBase::is_text_transform_and_security_fix_enabled_)
    , is_timeline_scope_enabled_(RuntimeEnabledFeaturesBase::is_timeline_scope_enabled_)
    , is_timer_throttling_for_background_tabs_enabled_(RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_)
    , is_timestamp_based_cls_tracking_enabled_(RuntimeEnabledFeaturesBase::is_timestamp_based_cls_tracking_enabled_)
    , is_time_zone_change_event_enabled_(RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_)
    , is_topics_api_enabled_(RuntimeEnabledFeaturesBase::is_topics_api_enabled_)
    , is_topics_document_api_enabled_(RuntimeEnabledFeaturesBase::is_topics_document_api_enabled_)
    , is_top_layer_inactive_document_exceptions_enabled_(RuntimeEnabledFeaturesBase::is_top_layer_inactive_document_exceptions_enabled_)
    , is_top_level_tpcd_enabled_(RuntimeEnabledFeaturesBase::is_top_level_tpcd_enabled_)
    , is_touch_drag_and_context_menu_enabled_(RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_)
    , is_touch_drag_on_short_press_enabled_(RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_)
    , is_touch_event_feature_detection_enabled_(RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_)
    , is_touch_text_editing_redesign_enabled_(RuntimeEnabledFeaturesBase::is_touch_text_editing_redesign_enabled_)
    , is_tpcd_enabled_(RuntimeEnabledFeaturesBase::is_tpcd_enabled_)
    , is_transferable_rtc_data_channel_enabled_(RuntimeEnabledFeaturesBase::is_transferable_rtc_data_channel_enabled_)
    , is_translate_service_enabled_(RuntimeEnabledFeaturesBase::is_translate_service_enabled_)
    , is_translation_api_enabled_(RuntimeEnabledFeaturesBase::is_translation_api_enabled_)
    , is_translation_api_entry_point_enabled_(RuntimeEnabledFeaturesBase::is_translation_api_entry_point_enabled_)
    , is_trusted_type_before_policy_creation_event_enabled_(RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_)
    , is_trusted_types_from_literal_enabled_(RuntimeEnabledFeaturesBase::is_trusted_types_from_literal_enabled_)
    , is_trusted_types_use_code_like_enabled_(RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_)
    , is_unclosed_form_control_is_invalid_enabled_(RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_)
    , is_unexposed_task_ids_enabled_(RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_)
    , is_unowned_animations_skip_css_events_enabled_(RuntimeEnabledFeaturesBase::is_unowned_animations_skip_css_events_enabled_)
    , is_unrestricted_measure_user_agent_specific_memory_enabled_(RuntimeEnabledFeaturesBase::is_unrestricted_measure_user_agent_specific_memory_enabled_)
    , is_unrestricted_shared_array_buffer_enabled_(RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_)
    , is_unrestricted_usb_enabled_(RuntimeEnabledFeaturesBase::is_unrestricted_usb_enabled_)
    , is_url_pattern_compare_component_enabled_(RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_)
    , is_url_search_params_has_and_delete_multiple_args_enabled_(RuntimeEnabledFeaturesBase::is_url_search_params_has_and_delete_multiple_args_enabled_)
    , is_use_begin_frame_presentation_feedback_enabled_(RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_)
    , is_use_low_quality_interpolation_enabled_(RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_)
    , is_user_activation_same_origin_visibility_enabled_(RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_)
    , is_use_selection_focus_node_for_caret_navigation_enabled_(RuntimeEnabledFeaturesBase::is_use_selection_focus_node_for_caret_navigation_enabled_)
    , is_use_undo_step_element_dispatch_before_input_enabled_(RuntimeEnabledFeaturesBase::is_use_undo_step_element_dispatch_before_input_enabled_)
    , is_v8_idle_tasks_enabled_(RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_)
    , is_video_auto_fullscreen_enabled_(RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_)
    , is_video_frame_metadata_background_blur_enabled_(RuntimeEnabledFeaturesBase::is_video_frame_metadata_background_blur_enabled_)
    , is_video_fullscreen_orientation_lock_enabled_(RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_)
    , is_video_rotate_to_fullscreen_enabled_(RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_)
    , is_video_track_generator_enabled_(RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_)
    , is_video_track_generator_in_window_enabled_(RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_)
    , is_video_track_generator_in_worker_enabled_(RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_)
    , is_viewport_changes_update_text_autosizing_enabled_(RuntimeEnabledFeaturesBase::is_viewport_changes_update_text_autosizing_enabled_)
    , is_viewport_height_client_hint_header_enabled_(RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_)
    , is_viewport_segments_enabled_(RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_)
    , is_view_transition_disable_snap_browser_controls_on_hidden_enabled_(
          RuntimeEnabledFeaturesBase::is_view_transition_disable_snap_browser_controls_on_hidden_enabled_)
    , is_view_transition_layered_capture_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_layered_capture_enabled_)
    , is_view_transition_long_callback_timeout_for_testing_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_long_callback_timeout_for_testing_enabled_)
    , is_view_transition_on_navigation_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_enabled_)
    , is_view_transition_on_navigation_for_iframes_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_for_iframes_enabled_)
    , is_view_transition_overflow_rect_from_surface_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_overflow_rect_from_surface_enabled_)
    , is_view_transition_tree_scoped_names_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_tree_scoped_names_enabled_)
    , is_view_transition_types_enabled_(RuntimeEnabledFeaturesBase::is_view_transition_types_enabled_)
    , is_visibility_collapse_column_enabled_(RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_)
    , is_visual_viewport_on_scroll_end_enabled_(RuntimeEnabledFeaturesBase::is_visual_viewport_on_scroll_end_enabled_)
    , is_wake_lock_enabled_(RuntimeEnabledFeaturesBase::is_wake_lock_enabled_)
    , is_warn_on_content_visibility_render_access_enabled_(RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_)
    , is_web_animations_svg_enabled_(RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_)
    , is_web_app_installation_enabled_(RuntimeEnabledFeaturesBase::is_web_app_installation_enabled_)
    , is_web_app_launch_queue_enabled_(RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_)
    , is_web_app_scope_extensions_enabled_(RuntimeEnabledFeaturesBase::is_web_app_scope_extensions_enabled_)
    , is_web_app_tab_strip_enabled_(RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_)
    , is_web_app_tab_strip_customizations_enabled_(RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_)
    , is_web_app_translations_enabled_(RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_)
    , is_web_app_url_handling_enabled_(RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_)
    , is_web_assembly_js_promise_integration_enabled_(RuntimeEnabledFeaturesBase::is_web_assembly_js_promise_integration_enabled_)
    , is_web_assembly_js_string_builtins_enabled_(RuntimeEnabledFeaturesBase::is_web_assembly_js_string_builtins_enabled_)
    , is_web_audio_bypass_output_buffering_enabled_(RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_enabled_)
    , is_web_audio_bypass_output_buffering_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_opt_out_enabled_)
    , is_web_auth_enabled_(RuntimeEnabledFeaturesBase::is_web_auth_enabled_)
    , is_web_auth_authenticator_attachment_enabled_(RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_)
    , is_web_authentication_ambient_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_ambient_enabled_)
    , is_web_authentication_attestation_formats_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_attestation_formats_enabled_)
    , is_web_authentication_client_capabilities_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_client_capabilities_enabled_)
    , is_web_authentication_js_on_serialization_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_js_on_serialization_enabled_)
    , is_web_authentication_large_blob_extension_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_)
    , is_web_authentication_prf_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_prf_enabled_)
    , is_web_authentication_remote_desktop_support_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_)
    , is_web_authentication_supplemental_pub_keys_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_supplemental_pub_keys_enabled_)
    , is_web_bluetooth_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_)
    , is_web_bluetooth_get_devices_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_)
    , is_web_bluetooth_scanning_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_)
    , is_web_bluetooth_watch_advertisements_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_)
    , is_webcodecs_copy_to_rgb_enabled_(RuntimeEnabledFeaturesBase::is_webcodecs_copy_to_rgb_enabled_)
    , is_webcodecs_hbd_formats_enabled_(RuntimeEnabledFeaturesBase::is_webcodecs_hbd_formats_enabled_)
    , is_webcodecs_orientation_enabled_(RuntimeEnabledFeaturesBase::is_webcodecs_orientation_enabled_)
    , is_webcodecs_video_encoder_buffers_enabled_(RuntimeEnabledFeaturesBase::is_webcodecs_video_encoder_buffers_enabled_)
    , is_web_crypto_curve_25519_enabled_(RuntimeEnabledFeaturesBase::is_web_crypto_curve_25519_enabled_)
    , is_web_font_resize_lcp_enabled_(RuntimeEnabledFeaturesBase::is_web_font_resize_lcp_enabled_)
    , is_webgl_developer_extensions_enabled_(RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_)
    , is_webgl_draft_extensions_enabled_(RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_)
    , is_webgl_drawing_buffer_storage_enabled_(RuntimeEnabledFeaturesBase::is_webgl_drawing_buffer_storage_enabled_)
    , is_webgl_image_chromium_enabled_(RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_)
    , is_webgpu_canvas_context_get_configuration_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_canvas_context_get_configuration_enabled_)
    , is_webgpu_developer_features_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_)
    , is_webgpu_device_adapter_info_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_device_adapter_info_enabled_)
    , is_webgpu_experimental_features_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_experimental_features_enabled_)
    , is_webgpu_hdr_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_hdr_enabled_)
    , is_webgpu_subgroups_features_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_subgroups_features_enabled_)
    , is_webgpu_texture_view_usage_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_texture_view_usage_enabled_)
    , is_web_hid_enabled_(RuntimeEnabledFeaturesBase::is_web_hid_enabled_)
    , is_web_hid_on_dedicated_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_hid_on_dedicated_workers_enabled_)
    , is_web_hid_on_service_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_)
    , is_web_identity_digital_credentials_enabled_(RuntimeEnabledFeaturesBase::is_web_identity_digital_credentials_enabled_)
    , is_web_idl_big_int_uses_to_big_int_enabled_(RuntimeEnabledFeaturesBase::is_web_idl_big_int_uses_to_big_int_enabled_)
    , is_web_nfc_enabled_(RuntimeEnabledFeaturesBase::is_web_nfc_enabled_)
    , is_web_otp_enabled_(RuntimeEnabledFeaturesBase::is_web_otp_enabled_)
    , is_web_otp_assertion_feature_policy_enabled_(RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_)
    , is_web_preferences_enabled_(RuntimeEnabledFeaturesBase::is_web_preferences_enabled_)
    , is_web_printing_enabled_(RuntimeEnabledFeaturesBase::is_web_printing_enabled_)
    , is_web_share_enabled_(RuntimeEnabledFeaturesBase::is_web_share_enabled_)
    , is_websocket_stream_enabled_(RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_)
    , is_web_transport_custom_certificates_enabled_(RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_)
    , is_web_transport_stats_enabled_(RuntimeEnabledFeaturesBase::is_web_transport_stats_enabled_)
    , is_web_usb_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_enabled_)
    , is_web_usb_on_dedicated_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_)
    , is_web_usb_on_service_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_)
    , is_web_view_xr_equested_with_deprecation_enabled_(RuntimeEnabledFeaturesBase::is_web_view_xr_equested_with_deprecation_enabled_)
    , is_web_vtt_regions_enabled_(RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_)
    , is_web_xr_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_enabled_)
    , is_web_xr_enabled_features_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_enabled_features_enabled_)
    , is_web_xr_frame_rate_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_frame_rate_enabled_)
    , is_web_xr_front_facing_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_front_facing_enabled_)
    , is_web_xr_gpu_binding_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_gpu_binding_enabled_)
    , is_web_xr_hand_input_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_)
    , is_web_xr_hit_test_entity_types_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_)
    , is_web_xr_image_tracking_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_)
    , is_web_xr_layers_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_layers_enabled_)
    , is_web_xr_layers_common_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_layers_common_enabled_)
    , is_web_xr_plane_detection_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_)
    , is_web_xr_pose_motion_data_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_pose_motion_data_enabled_)
    , is_web_xr_spec_parity_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_spec_parity_enabled_)
    , is_window_default_status_enabled_(RuntimeEnabledFeaturesBase::is_window_default_status_enabled_)
    , is_xml_parser_merge_adjacent_c_data_sections_enabled_(RuntimeEnabledFeaturesBase::is_xml_parser_merge_adjacent_c_data_sections_enabled_)
    , is_zero_copy_tab_capture_enabled_(RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_)
{
}

void RuntimeEnabledFeaturesBase::Backup::Restore()
{
    RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_ = is_accelerated_2d_canvas_enabled_;
    RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_ = is_accelerated_small_canvases_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_ = is_accessibility_aria_virtual_content_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_ = is_accessibility_expose_display_none_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_min_role_tabbable_enabled_ = is_accessibility_min_role_tabbable_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_os_level_bold_text_enabled_ = is_accessibility_os_level_bold_text_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_prohibited_names_enabled_ = is_accessibility_prohibited_names_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_serialization_size_metrics_enabled_ = is_accessibility_serialization_size_metrics_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_ = is_accessibility_use_ax_position_for_document_markers_enabled_;
    RuntimeEnabledFeaturesBase::is_address_space_enabled_ = is_address_space_enabled_;
    RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_ = is_ad_interest_group_api_enabled_;
    RuntimeEnabledFeaturesBase::is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_
        = is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_;
    RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_ = is_ad_tagging_enabled_;
    RuntimeEnabledFeaturesBase::is_ai_prompt_api_enabled_ = is_ai_prompt_api_enabled_;
    RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_extension_enabled_ = is_ai_prompt_api_for_extension_enabled_;
    RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_web_platform_enabled_ = is_ai_prompt_api_for_web_platform_enabled_;
    RuntimeEnabledFeaturesBase::is_ai_rewriter_api_enabled_ = is_ai_rewriter_api_enabled_;
    RuntimeEnabledFeaturesBase::is_ai_summarization_api_enabled_ = is_ai_summarization_api_enabled_;
    RuntimeEnabledFeaturesBase::is_ai_writer_api_enabled_ = is_ai_writer_api_enabled_;
    RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_ = is_allow_content_initiated_data_url_navigations_enabled_;
    RuntimeEnabledFeaturesBase::is_allow_java_script_to_reset_autofill_state_enabled_ = is_allow_java_script_to_reset_autofill_state_enabled_;
    RuntimeEnabledFeaturesBase::is_allow_preloading_with_csp_meta_tag_enabled_ = is_allow_preloading_with_csp_meta_tag_enabled_;
    RuntimeEnabledFeaturesBase::is_allow_ur_ns_in_iframes_enabled_ = is_allow_ur_ns_in_iframes_enabled_;
    RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_ = is_android_downloadable_fonts_matching_enabled_;
    RuntimeEnabledFeaturesBase::is_animation_progress_api_enabled_ = is_animation_progress_api_enabled_;
    RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_ = is_animation_worklet_enabled_;
    RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_ = is_anonymous_iframe_enabled_;
    RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_ = is_aom_aria_relationship_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_aria_owns_enabled_ = is_aom_aria_relationship_properties_aria_owns_enabled_;
    RuntimeEnabledFeaturesBase::is_app_title_enabled_ = is_app_title_enabled_;
    RuntimeEnabledFeaturesBase::is_aria_actions_enabled_ = is_aria_actions_enabled_;
    RuntimeEnabledFeaturesBase::is_aria_notify_enabled_ = is_aria_notify_enabled_;
    RuntimeEnabledFeaturesBase::is_aria_row_col_index_text_enabled_ = is_aria_row_col_index_text_enabled_;
    RuntimeEnabledFeaturesBase::is_atomic_move_api_enabled_ = is_atomic_move_api_enabled_;
    RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_ = is_attribution_reporting_enabled_;
    RuntimeEnabledFeaturesBase::is_attribution_reporting_cross_app_web_enabled_ = is_attribution_reporting_cross_app_web_enabled_;
    RuntimeEnabledFeaturesBase::is_attribution_reporting_interface_enabled_ = is_attribution_reporting_interface_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_context_interrupted_state_enabled_ = is_audio_context_interrupted_state_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_context_on_error_enabled_ = is_audio_context_on_error_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_context_playout_stats_enabled_ = is_audio_context_playout_stats_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_ = is_audio_context_set_sink_id_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = is_audio_output_devices_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_ = is_audio_video_tracks_enabled_;
    RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_nine_patch_track_enabled_ = is_aura_scrollbar_uses_nine_patch_track_enabled_;
    RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_solid_color_thumb_enabled_ = is_aura_scrollbar_uses_solid_color_thumb_enabled_;
    RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_ = is_auto_dark_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_ = is_automation_controlled_enabled_;
    RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_video_heuristics_enabled_ = is_auto_picture_in_picture_video_heuristics_enabled_;
    RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_ = is_backface_visibility_interop_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_ = is_back_forward_cache_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_ = is_back_forward_cache_experiment_http_header_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_ = is_back_forward_cache_not_restored_reasons_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_transitions_enabled_ = is_back_forward_transitions_enabled_;
    RuntimeEnabledFeaturesBase::is_background_fetch_enabled_ = is_background_fetch_enabled_;
    RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = is_barcode_detector_enabled_;
    RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_ = is_bidi_caret_affinity_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_ = is_blink_extension_chrome_os_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_kiosk_enabled_ = is_blink_extension_chrome_os_kiosk_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_diagnostics_enabled_ = is_blink_extension_diagnostics_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_web_view_enabled_ = is_blink_extension_web_view_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_web_view_media_integrity_enabled_ = is_blink_extension_web_view_media_integrity_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_lifecycle_script_forbidden_enabled_ = is_blink_lifecycle_script_forbidden_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_ = is_blink_runtime_call_stats_enabled_;
    RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_ = is_blocking_focus_without_user_activation_enabled_;
    RuntimeEnabledFeaturesBase::is_boundary_event_dispatch_tracks_node_removal_enabled_ = is_boundary_event_dispatch_tracks_node_removal_enabled_;
    RuntimeEnabledFeaturesBase::is_box_decoration_break_enabled_ = is_box_decoration_break_enabled_;
    RuntimeEnabledFeaturesBase::is_break_iterator_hyphen_minus_enabled_ = is_break_iterator_hyphen_minus_enabled_;
    RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_ = is_browser_verified_user_activation_keyboard_enabled_;
    RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_ = is_browser_verified_user_activation_mouse_enabled_;
    RuntimeEnabledFeaturesBase::is_buffered_bytes_consumer_limit_size_enabled_ = is_buffered_bytes_consumer_limit_size_enabled_;
    RuntimeEnabledFeaturesBase::is_built_in_aiapi_enabled_ = is_built_in_aiapi_enabled_;
    RuntimeEnabledFeaturesBase::is_bypass_pepc_security_for_testing_enabled_ = is_bypass_pepc_security_for_testing_enabled_;
    RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_ = is_cache_storage_code_cache_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_calendar_picker_month_popup_button_disabled_color_enabled_ = is_calendar_picker_month_popup_button_disabled_color_enabled_;
    RuntimeEnabledFeaturesBase::is_call_exit_node_without_layout_object_enabled_ = is_call_exit_node_without_layout_object_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_canvas_filter_enabled_ = is_canvas_2d_canvas_filter_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_gpu_transfer_enabled_ = is_canvas_2d_gpu_transfer_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_ = is_canvas_2d_image_chromium_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_ = is_canvas_2d_layers_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_layers_with_options_enabled_ = is_canvas_2d_layers_with_options_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_mesh_enabled_ = is_canvas_2d_mesh_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_text_metrics_shaping_enabled_ = is_canvas_2d_text_metrics_shaping_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_floating_point_enabled_ = is_canvas_floating_point_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_ = is_canvas_hdr_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_ = is_canvas_image_smoothing_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_place_element_enabled_ = is_canvas_place_element_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_uses_arc_paint_op_enabled_ = is_canvas_uses_arc_paint_op_enabled_;
    RuntimeEnabledFeaturesBase::is_capability_delegation_display_capture_request_enabled_ = is_capability_delegation_display_capture_request_enabled_;
    RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = is_capture_controller_enabled_;
    RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = is_captured_mouse_events_enabled_;
    RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = is_captured_surface_control_enabled_;
    RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = is_capture_handle_enabled_;
    RuntimeEnabledFeaturesBase::is_caret_position_from_point_enabled_ = is_caret_position_from_point_enabled_;
    RuntimeEnabledFeaturesBase::is_cct_new_rfm_push_behavior_enabled_ = is_cct_new_rfm_push_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_check_if_highest_root_contains_position_anchor_node_enabled_
        = is_check_if_highest_root_contains_position_anchor_node_enabled_;
    RuntimeEnabledFeaturesBase::is_check_visibility_extra_properties_enabled_ = is_check_visibility_extra_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_ = is_click_to_captured_pointer_enabled_;
    RuntimeEnabledFeaturesBase::is_clipboard_item_with_dom_string_support_enabled_ = is_clipboard_item_with_dom_string_support_enabled_;
    RuntimeEnabledFeaturesBase::is_clip_path_reject_empty_paths_enabled_ = is_clip_path_reject_empty_paths_enabled_;
    RuntimeEnabledFeaturesBase::is_coalesce_selectionchange_event_enabled_ = is_coalesce_selectionchange_event_enabled_;
    RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_ = is_coep_reflection_enabled_;
    RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_ = is_composite_bg_color_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_ = is_composite_box_shadow_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_ = is_composite_clip_path_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_composited_animations_cancelled_asynchronously_enabled_ = is_composited_animations_cancelled_asynchronously_enabled_;
    RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = is_composited_selection_update_enabled_;
    RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = is_composition_foreground_markers_enabled_;
    RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_enabled_ = is_compression_dictionary_transport_enabled_;
    RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_backend_enabled_ = is_compression_dictionary_transport_backend_enabled_;
    RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_ = is_computed_accessibility_info_enabled_;
    RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = is_compute_pressure_enabled_;
    RuntimeEnabledFeaturesBase::is_concurrent_view_transitions_spa_enabled_ = is_concurrent_view_transitions_spa_enabled_;
    RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = is_contacts_manager_enabled_;
    RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = is_contacts_manager_extra_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_container_type_no_layout_containment_enabled_ = is_container_type_no_layout_containment_enabled_;
    RuntimeEnabledFeaturesBase::is_content_index_enabled_ = is_content_index_enabled_;
    RuntimeEnabledFeaturesBase::is_context_menu_enabled_ = is_context_menu_enabled_;
    RuntimeEnabledFeaturesBase::is_continue_event_timing_recording_when_buffer_is_full_enabled_
        = is_continue_event_timing_recording_when_buffer_is_full_enabled_;
    RuntimeEnabledFeaturesBase::is_controlled_frame_enabled_ = is_controlled_frame_enabled_;
    RuntimeEnabledFeaturesBase::is_cookie_deprecation_facilitated_testing_enabled_ = is_cookie_deprecation_facilitated_testing_enabled_;
    RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_ = is_cooperative_scheduling_enabled_;
    RuntimeEnabledFeaturesBase::is_coop_restrict_properties_enabled_ = is_coop_restrict_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_ = is_cors_rfc_1918_enabled_;
    RuntimeEnabledFeaturesBase::is_create_input_shadow_tree_during_layout_enabled_ = is_create_input_shadow_tree_during_layout_enabled_;
    RuntimeEnabledFeaturesBase::is_credential_manager_report_enabled_ = is_credential_manager_report_enabled_;
    RuntimeEnabledFeaturesBase::is_cross_frame_performance_timeline_enabled_ = is_cross_frame_performance_timeline_enabled_;
    RuntimeEnabledFeaturesBase::is_css_accent_color_keyword_enabled_ = is_css_accent_color_keyword_enabled_;
    RuntimeEnabledFeaturesBase::is_css_advanced_attr_function_enabled_ = is_css_advanced_attr_function_enabled_;
    RuntimeEnabledFeaturesBase::is_css_anchor_scope_enabled_ = is_css_anchor_scope_enabled_;
    RuntimeEnabledFeaturesBase::is_css_anchor_size_insets_margins_enabled_ = is_css_anchor_size_insets_margins_enabled_;
    RuntimeEnabledFeaturesBase::is_css_at_property_string_syntax_enabled_ = is_css_at_property_string_syntax_enabled_;
    RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_ = is_css_at_rule_counter_style_image_symbols_enabled_;
    RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_ = is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
    RuntimeEnabledFeaturesBase::is_css_background_clip_unprefix_enabled_ = is_css_background_clip_unprefix_enabled_;
    RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_ = is_css_calc_simplification_and_serialization_enabled_;
    RuntimeEnabledFeaturesBase::is_css_calc_size_function_enabled_ = is_css_calc_size_function_enabled_;
    RuntimeEnabledFeaturesBase::is_css_caret_animation_enabled_ = is_css_caret_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_css_cascade_correct_scope_enabled_ = is_css_cascade_correct_scope_enabled_;
    RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_ = is_css_case_sensitive_selector_enabled_;
    RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_ = is_css_color_contrast_enabled_;
    RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_ = is_css_color_typed_om_enabled_;
    RuntimeEnabledFeaturesBase::is_css_computed_style_full_pseudo_element_parser_enabled_ = is_css_computed_style_full_pseudo_element_parser_enabled_;
    RuntimeEnabledFeaturesBase::is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_
        = is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_;
    RuntimeEnabledFeaturesBase::is_css_cross_fade_enabled_ = is_css_cross_fade_enabled_;
    RuntimeEnabledFeaturesBase::is_css_custom_state_deprecated_syntax_enabled_ = is_css_custom_state_deprecated_syntax_enabled_;
    RuntimeEnabledFeaturesBase::is_css_custom_state_new_syntax_enabled_ = is_css_custom_state_new_syntax_enabled_;
    RuntimeEnabledFeaturesBase::is_css_dynamic_range_limit_enabled_ = is_css_dynamic_range_limit_enabled_;
    RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_ = is_css_enumerated_custom_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_css_exponential_functions_enabled_ = is_css_exponential_functions_enabled_;
    RuntimeEnabledFeaturesBase::is_css_flat_tree_container_enabled_ = is_css_flat_tree_container_enabled_;
    RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_ = is_css_font_size_adjust_enabled_;
    RuntimeEnabledFeaturesBase::is_css_functions_enabled_ = is_css_functions_enabled_;
    RuntimeEnabledFeaturesBase::is_css_gap_decoration_enabled_ = is_css_gap_decoration_enabled_;
    RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_ = is_css_hex_alpha_color_enabled_;
    RuntimeEnabledFeaturesBase::is_css_inert_enabled_ = is_css_inert_enabled_;
    RuntimeEnabledFeaturesBase::is_css_inset_area_property_enabled_ = is_css_inset_area_property_enabled_;
    RuntimeEnabledFeaturesBase::is_css_keyframes_rule_length_enabled_ = is_css_keyframes_rule_length_enabled_;
    RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_ = is_css_layout_api_enabled_;
    RuntimeEnabledFeaturesBase::is_css_lazy_parsing_fast_path_enabled_ = is_css_lazy_parsing_fast_path_enabled_;
    RuntimeEnabledFeaturesBase::is_css_line_clamp_enabled_ = is_css_line_clamp_enabled_;
    RuntimeEnabledFeaturesBase::is_css_line_clamp_webkit_box_blockification_enabled_ = is_css_line_clamp_webkit_box_blockification_enabled_;
    RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_ = is_css_logical_overflow_enabled_;
    RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_ = is_css_marker_nested_pseudo_element_enabled_;
    RuntimeEnabledFeaturesBase::is_css_masonry_layout_enabled_ = is_css_masonry_layout_enabled_;
    RuntimeEnabledFeaturesBase::is_css_mixins_enabled_ = is_css_mixins_enabled_;
    RuntimeEnabledFeaturesBase::is_css_nested_declarations_enabled_ = is_css_nested_declarations_enabled_;
    RuntimeEnabledFeaturesBase::is_css_nested_pseudo_elements_enabled_ = is_css_nested_pseudo_elements_enabled_;
    RuntimeEnabledFeaturesBase::is_css_overflow_container_queries_enabled_ = is_css_overflow_container_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_ = is_css_paint_api_arguments_enabled_;
    RuntimeEnabledFeaturesBase::is_css_parser_ignore_charset_for_urls_enabled_ = is_css_parser_ignore_charset_for_urls_enabled_;
    RuntimeEnabledFeaturesBase::is_css_part_allows_more_selectors_after_enabled_ = is_css_part_allows_more_selectors_after_enabled_;
    RuntimeEnabledFeaturesBase::is_css_position_area_value_enabled_ = is_css_position_area_value_enabled_;
    RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_ = is_css_position_sticky_static_scroll_position_enabled_;
    RuntimeEnabledFeaturesBase::is_css_progress_notation_enabled_ = is_css_progress_notation_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_column_enabled_ = is_css_pseudo_column_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_has_slotted_enabled_ = is_css_pseudo_has_slotted_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_open_closed_enabled_ = is_css_pseudo_open_closed_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_ = is_css_pseudo_playing_paused_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_buttons_enabled_ = is_css_pseudo_scroll_buttons_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_markers_enabled_ = is_css_pseudo_scroll_markers_enabled_;
    RuntimeEnabledFeaturesBase::is_css_reading_flow_enabled_ = is_css_reading_flow_enabled_;
    RuntimeEnabledFeaturesBase::is_css_relative_color_enabled_ = is_css_relative_color_enabled_;
    RuntimeEnabledFeaturesBase::is_css_relative_color_late_resolve_always_enabled_ = is_css_relative_color_late_resolve_always_enabled_;
    RuntimeEnabledFeaturesBase::is_css_relative_color_preserve_none_enabled_ = is_css_relative_color_preserve_none_enabled_;
    RuntimeEnabledFeaturesBase::is_css_relative_color_supports_currentcolor_enabled_ = is_css_relative_color_supports_currentcolor_enabled_;
    RuntimeEnabledFeaturesBase::is_css_resize_auto_enabled_ = is_css_resize_auto_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_snap_change_event_enabled_ = is_css_scroll_snap_change_event_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_snap_changing_event_enabled_ = is_css_scroll_snap_changing_event_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_snap_events_enabled_ = is_css_scroll_snap_events_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_start_enabled_ = is_css_scroll_start_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_start_target_enabled_ = is_css_scroll_start_target_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_state_container_queries_enabled_ = is_css_scroll_state_container_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_ = is_css_selector_fragment_anchor_enabled_;
    RuntimeEnabledFeaturesBase::is_css_sign_related_functions_enabled_ = is_css_sign_related_functions_enabled_;
    RuntimeEnabledFeaturesBase::is_css_snap_container_queries_enabled_ = is_css_snap_container_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_stepped_value_functions_enabled_ = is_css_stepped_value_functions_enabled_;
    RuntimeEnabledFeaturesBase::is_css_sticky_container_queries_enabled_ = is_css_sticky_container_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_supports_at_rule_function_enabled_ = is_css_supports_at_rule_function_enabled_;
    RuntimeEnabledFeaturesBase::is_css_supports_for_import_rules_enabled_ = is_css_supports_for_import_rules_enabled_;
    RuntimeEnabledFeaturesBase::is_css_system_accent_color_enabled_ = is_css_system_accent_color_enabled_;
    RuntimeEnabledFeaturesBase::is_css_text_auto_space_enabled_ = is_css_text_auto_space_enabled_;
    RuntimeEnabledFeaturesBase::is_css_text_box_trim_enabled_ = is_css_text_box_trim_enabled_;
    RuntimeEnabledFeaturesBase::is_css_text_spacing_enabled_ = is_css_text_spacing_enabled_;
    RuntimeEnabledFeaturesBase::is_css_tree_scoped_timelines_enabled_ = is_css_tree_scoped_timelines_enabled_;
    RuntimeEnabledFeaturesBase::is_css_user_select_contain_enabled_ = is_css_user_select_contain_enabled_;
    RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_ = is_css_video_dynamic_range_media_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_view_transition_auto_name_enabled_ = is_css_view_transition_auto_name_enabled_;
    RuntimeEnabledFeaturesBase::is_css_view_transition_class_enabled_ = is_css_view_transition_class_enabled_;
    RuntimeEnabledFeaturesBase::is_cursor_anchor_info_mojo_pipe_enabled_ = is_cursor_anchor_info_mojo_pipe_enabled_;
    RuntimeEnabledFeaturesBase::is_customizable_select_enabled_ = is_customizable_select_enabled_;
    RuntimeEnabledFeaturesBase::is_database_enabled_ = is_database_enabled_;
    RuntimeEnabledFeaturesBase::is_deprecated_request_adapter_info_enabled_ = is_deprecated_request_adapter_info_enabled_;
    RuntimeEnabledFeaturesBase::is_deprecate_unload_opt_out_enabled_ = is_deprecate_unload_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_ = is_desktop_capture_disable_local_echo_control_enabled_;
    RuntimeEnabledFeaturesBase::is_desktop_pw_as_additional_windowing_controls_enabled_ = is_desktop_pw_as_additional_windowing_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_ = is_desktop_pw_as_sub_apps_enabled_;
    RuntimeEnabledFeaturesBase::is_details_styling_enabled_ = is_details_styling_enabled_;
    RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = is_device_attributes_enabled_;
    RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_ = is_device_orientation_request_permission_enabled_;
    RuntimeEnabledFeaturesBase::is_device_posture_enabled_ = is_device_posture_enabled_;
    RuntimeEnabledFeaturesBase::is_dialog_close_when_open_removed_enabled_ = is_dialog_close_when_open_removed_enabled_;
    RuntimeEnabledFeaturesBase::is_dialog_element_toggle_events_enabled_ = is_dialog_element_toggle_events_enabled_;
    RuntimeEnabledFeaturesBase::is_dialog_new_focus_behavior_enabled_ = is_dialog_new_focus_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = is_digital_goods_enabled_;
    RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = is_digital_goods_v_2_1_enabled_;
    RuntimeEnabledFeaturesBase::is_dir_auto_fix_slot_exclusions_enabled_ = is_dir_auto_fix_slot_exclusions_enabled_;
    RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_ = is_direct_sockets_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_ahem_antialias_enabled_ = is_disable_ahem_antialias_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_
        = is_disable_different_origin_subframe_dialog_suppression_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_ = is_disable_hardware_noise_suppression_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_reduce_accept_language_enabled_ = is_disable_reduce_accept_language_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_select_all_for_empty_text_enabled_ = is_disable_select_all_for_empty_text_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_third_party_storage_partitioning_2_enabled_ = is_disable_third_party_storage_partitioning_2_enabled_;
    RuntimeEnabledFeaturesBase::is_dispatch_before_input_for_spin_button_interactions_enabled_ = is_dispatch_before_input_for_spin_button_interactions_enabled_;
    RuntimeEnabledFeaturesBase::is_dispatch_hidden_visibility_transitions_enabled_ = is_dispatch_hidden_visibility_transitions_enabled_;
    RuntimeEnabledFeaturesBase::is_dispatch_selectionchange_event_per_element_enabled_ = is_dispatch_selectionchange_event_per_element_enabled_;
    RuntimeEnabledFeaturesBase::is_display_contents_focusable_enabled_ = is_display_contents_focusable_enabled_;
    RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_ = is_display_cutout_api_enabled_;
    RuntimeEnabledFeaturesBase::is_document_cookie_enabled_ = is_document_cookie_enabled_;
    RuntimeEnabledFeaturesBase::is_document_domain_enabled_ = is_document_domain_enabled_;
    RuntimeEnabledFeaturesBase::is_document_install_chunking_enabled_ = is_document_install_chunking_enabled_;
    RuntimeEnabledFeaturesBase::is_document_isolation_policy_enabled_ = is_document_isolation_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_document_open_origin_alias_removal_enabled_ = is_document_open_origin_alias_removal_enabled_;
    RuntimeEnabledFeaturesBase::is_document_open_sandbox_inheritance_removal_enabled_ = is_document_open_sandbox_inheritance_removal_enabled_;
    RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = is_document_picture_in_picture_api_enabled_;
    RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_
        = is_document_picture_in_picture_prefer_initial_placement_enabled_;
    RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = is_document_picture_in_picture_user_activation_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_ = is_document_policy_document_domain_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_expect_no_linked_resources_enabled_ = is_document_policy_expect_no_linked_resources_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_include_js_call_stacks_in_crash_reports_enabled_
        = is_document_policy_include_js_call_stacks_in_crash_reports_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_ = is_document_policy_negotiation_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_ = is_document_policy_sync_xhr_enabled_;
    RuntimeEnabledFeaturesBase::is_document_render_blocking_enabled_ = is_document_render_blocking_enabled_;
    RuntimeEnabledFeaturesBase::is_document_write_enabled_ = is_document_write_enabled_;
    RuntimeEnabledFeaturesBase::is_dom_parts_api_enabled_ = is_dom_parts_api_enabled_;
    RuntimeEnabledFeaturesBase::is_dom_parts_api_minimal_enabled_ = is_dom_parts_api_minimal_enabled_;
    RuntimeEnabledFeaturesBase::is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_
        = is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_;
    RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_enabled_ = is_dynamic_safe_area_insets_enabled_;
    RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_on_scroll_enabled_ = is_dynamic_safe_area_insets_on_scroll_enabled_;
    RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = is_element_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_element_get_inner_html_enabled_ = is_element_get_inner_html_enabled_;
    RuntimeEnabledFeaturesBase::is_enforce_anonymity_exposure_enabled_ = is_enforce_anonymity_exposure_enabled_;
    RuntimeEnabledFeaturesBase::is_escape_lt_gt_in_attributes_enabled_ = is_escape_lt_gt_in_attributes_enabled_;
    RuntimeEnabledFeaturesBase::is_event_timing_handle_keyboard_event_simulated_click_enabled_ = is_event_timing_handle_keyboard_event_simulated_click_enabled_;
    RuntimeEnabledFeaturesBase::is_event_timing_interaction_count_enabled_ = is_event_timing_interaction_count_enabled_;
    RuntimeEnabledFeaturesBase::is_event_timing_selection_auto_scroll_no_interaction_id_enabled_
        = is_event_timing_selection_auto_scroll_no_interaction_id_enabled_;
    RuntimeEnabledFeaturesBase::is_event_timing_tap_stop_scroll_no_interaction_id_enabled_ = is_event_timing_tap_stop_scroll_no_interaction_id_enabled_;
    RuntimeEnabledFeaturesBase::is_exclude_transparent_texts_from_being_lcp_eligible_enabled_ = is_exclude_transparent_texts_from_being_lcp_eligible_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_ = is_experimental_content_security_policy_features_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_ = is_experimental_js_profiler_markers_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_machine_learning_neural_network_enabled_ = is_experimental_machine_learning_neural_network_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_ = is_experimental_policies_enabled_;
    RuntimeEnabledFeaturesBase::is_expose_coarsened_render_time_enabled_ = is_expose_coarsened_render_time_enabled_;
    RuntimeEnabledFeaturesBase::is_expose_render_time_non_tao_delayed_image_enabled_ = is_expose_render_time_non_tao_delayed_image_enabled_;
    RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_ = is_extended_text_metrics_enabled_;
    RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = is_eye_dropper_api_enabled_;
    RuntimeEnabledFeaturesBase::is_face_detector_enabled_ = is_face_detector_enabled_;
    RuntimeEnabledFeaturesBase::is_fast_non_composited_scroll_hit_test_enabled_ = is_fast_non_composited_scroll_hit_test_enabled_;
    RuntimeEnabledFeaturesBase::is_fast_path_single_selector_exact_match_enabled_ = is_fast_path_single_selector_exact_match_enabled_;
    RuntimeEnabledFeaturesBase::is_fast_position_iterator_enabled_ = is_fast_position_iterator_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_enabled_ = is_fed_cm_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_authz_enabled_ = is_fed_cm_authz_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_auto_selected_flag_enabled_ = is_fed_cm_auto_selected_flag_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_button_mode_enabled_ = is_fed_cm_button_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_disconnect_enabled_ = is_fed_cm_disconnect_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_domain_hint_enabled_ = is_fed_cm_domain_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_error_enabled_ = is_fed_cm_error_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_id_p_registration_enabled_ = is_fed_cm_id_p_registration_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_ = is_fed_cm_idp_signin_status_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_ = is_fed_cm_multiple_identity_providers_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_selective_disclosure_enabled_ = is_fed_cm_selective_disclosure_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_with_storage_access_api_enabled_ = is_fed_cm_with_storage_access_api_enabled_;
    RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_ = is_fenced_frames_enabled_;
    RuntimeEnabledFeaturesBase::is_fenced_frames_api_changes_enabled_ = is_fenced_frames_api_changes_enabled_;
    RuntimeEnabledFeaturesBase::is_fenced_frames_default_mode_enabled_ = is_fenced_frames_default_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_fenced_frames_local_unpartitioned_data_access_enabled_ = is_fenced_frames_local_unpartitioned_data_access_enabled_;
    RuntimeEnabledFeaturesBase::is_fetch_body_bytes_enabled_ = is_fetch_body_bytes_enabled_;
    RuntimeEnabledFeaturesBase::is_fetch_later_api_enabled_ = is_fetch_later_api_enabled_;
    RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_ = is_fetch_upload_streaming_enabled_;
    RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = is_file_handling_enabled_;
    RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = is_file_handling_icons_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_enabled_ = is_file_system_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_enabled_ = is_file_system_access_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_ = is_file_system_access_api_experimental_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = is_file_system_access_get_cloud_identifiers_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = is_file_system_access_local_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_locking_scheme_enabled_ = is_file_system_access_locking_scheme_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = is_file_system_access_origin_private_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_observer_enabled_ = is_file_system_observer_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_observer_unobserve_enabled_ = is_file_system_observer_unobserve_enabled_;
    RuntimeEnabledFeaturesBase::is_find_decomposed_in_short_text_enabled_ = is_find_decomposed_in_short_text_enabled_;
    RuntimeEnabledFeaturesBase::is_find_ruby_in_page_enabled_ = is_find_ruby_in_page_enabled_;
    RuntimeEnabledFeaturesBase::is_find_text_in_readonly_text_input_enabled_ = is_find_text_in_readonly_text_input_enabled_;
    RuntimeEnabledFeaturesBase::is_find_text_skip_collapsed_text_enabled_ = is_find_text_skip_collapsed_text_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_enabled_ = is_fledge_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_auction_deal_support_enabled_ = is_fledge_auction_deal_support_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_bidding_and_auction_server_api_enabled_ = is_fledge_bidding_and_auction_server_api_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_custom_max_auction_ad_components_enabled_ = is_fledge_custom_max_auction_ad_components_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_deprecated_render_url_replacements_enabled_ = is_fledge_deprecated_render_url_replacements_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_direct_from_seller_signals_header_ad_slot_enabled_ = is_fledge_direct_from_seller_signals_header_ad_slot_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_multi_bid_enabled_ = is_fledge_multi_bid_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_real_time_reporting_enabled_ = is_fledge_real_time_reporting_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_reporting_timeout_enabled_ = is_fledge_reporting_timeout_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_seller_nonce_enabled_ = is_fledge_seller_nonce_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_trusted_signals_k_vv_2_support_enabled_ = is_fledge_trusted_signals_k_vv_2_support_enabled_;
    RuntimeEnabledFeaturesBase::is_fluent_overlay_scrollbars_enabled_ = is_fluent_overlay_scrollbars_enabled_;
    RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_ = is_fluent_scrollbars_enabled_;
    RuntimeEnabledFeaturesBase::is_fluent_scrollbar_uses_nine_patch_track_enabled_ = is_fluent_scrollbar_uses_nine_patch_track_enabled_;
    RuntimeEnabledFeaturesBase::is_focusgroup_enabled_ = is_focusgroup_enabled_;
    RuntimeEnabledFeaturesBase::is_font_access_enabled_ = is_font_access_enabled_;
    RuntimeEnabledFeaturesBase::is_fontations_font_backend_enabled_ = is_fontations_font_backend_enabled_;
    RuntimeEnabledFeaturesBase::is_fontations_for_selected_formats_enabled_ = is_fontations_for_selected_formats_enabled_;
    RuntimeEnabledFeaturesBase::is_font_family_postscript_matching_ct_migration_enabled_ = is_font_family_postscript_matching_ct_migration_enabled_;
    RuntimeEnabledFeaturesBase::is_font_family_style_matching_ct_migration_enabled_ = is_font_family_style_matching_ct_migration_enabled_;
    RuntimeEnabledFeaturesBase::is_font_present_win_enabled_ = is_font_present_win_enabled_;
    RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_ = is_font_src_local_matching_enabled_;
    RuntimeEnabledFeaturesBase::is_font_system_fallback_noto_cjk_enabled_ = is_font_system_fallback_noto_cjk_enabled_;
    RuntimeEnabledFeaturesBase::is_font_variant_emoji_enabled_ = is_font_variant_emoji_enabled_;
    RuntimeEnabledFeaturesBase::is_font_variation_sequences_enabled_ = is_font_variation_sequences_enabled_;
    RuntimeEnabledFeaturesBase::is_forced_colors_enabled_ = is_forced_colors_enabled_;
    RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_ = is_forced_colors_preserve_parent_color_enabled_;
    RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_ = is_force_eager_measure_memory_enabled_;
    RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_ = is_force_reduce_motion_enabled_;
    RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = is_force_taller_select_popup_enabled_;
    RuntimeEnabledFeaturesBase::is_form_control_restore_state_if_autocomplete_off_enabled_ = is_form_control_restore_state_if_autocomplete_off_enabled_;
    RuntimeEnabledFeaturesBase::is_form_controls_vertical_writing_mode_direction_support_enabled_
        = is_form_controls_vertical_writing_mode_direction_support_enabled_;
    RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_ = is_fractional_scroll_offsets_enabled_;
    RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_ = is_freeze_frames_on_visibility_enabled_;
    RuntimeEnabledFeaturesBase::is_gamepad_multitouch_enabled_ = is_gamepad_multitouch_enabled_;
    RuntimeEnabledFeaturesBase::is_get_all_screens_media_enabled_ = is_get_all_screens_media_enabled_;
    RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = is_get_display_media_enabled_;
    RuntimeEnabledFeaturesBase::is_get_display_media_requires_user_activation_enabled_ = is_get_display_media_requires_user_activation_enabled_;
    RuntimeEnabledFeaturesBase::is_group_effect_enabled_ = is_group_effect_enabled_;
    RuntimeEnabledFeaturesBase::is_handle_selection_change_on_deleting_empty_element_enabled_ = is_handle_selection_change_on_deleting_empty_element_enabled_;
    RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = is_handwriting_recognition_enabled_;
    RuntimeEnabledFeaturesBase::is_hanging_whitespace_does_not_depend_on_alignment_enabled_ = is_hanging_whitespace_does_not_depend_on_alignment_enabled_;
    RuntimeEnabledFeaturesBase::is_has_ua_visual_transition_enabled_ = is_has_ua_visual_transition_enabled_;
    RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_ = is_highlight_inheritance_enabled_;
    RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_ = is_highlight_pointer_events_enabled_;
    RuntimeEnabledFeaturesBase::is_highlights_from_point_enabled_ = is_highlights_from_point_enabled_;
    RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_enabled_ = is_hit_test_opaqueness_enabled_;
    RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_omit_line_box_enabled_ = is_hit_test_opaqueness_omit_line_box_enabled_;
    RuntimeEnabledFeaturesBase::is_href_translate_enabled_ = is_href_translate_enabled_;
    RuntimeEnabledFeaturesBase::is_html_anchor_attribute_enabled_ = is_html_anchor_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_html_dialog_light_dismiss_enabled_ = is_html_dialog_light_dismiss_enabled_;
    RuntimeEnabledFeaturesBase::is_html_embed_element_not_force_layout_enabled_ = is_html_embed_element_not_force_layout_enabled_;
    RuntimeEnabledFeaturesBase::is_html_interest_target_attribute_enabled_ = is_html_interest_target_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_html_invoke_actions_v_2_enabled_ = is_html_invoke_actions_v_2_enabled_;
    RuntimeEnabledFeaturesBase::is_html_invoke_target_attribute_enabled_ = is_html_invoke_target_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_html_object_element_fallback_detach_content_frame_enabled_ = is_html_object_element_fallback_detach_content_frame_enabled_;
    RuntimeEnabledFeaturesBase::is_html_parser_yield_and_delay_often_for_testing_enabled_ = is_html_parser_yield_and_delay_often_for_testing_enabled_;
    RuntimeEnabledFeaturesBase::is_html_popover_action_hover_enabled_ = is_html_popover_action_hover_enabled_;
    RuntimeEnabledFeaturesBase::is_html_popover_hint_enabled_ = is_html_popover_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_html_select_element_show_picker_enabled_ = is_html_select_element_show_picker_enabled_;
    RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = is_implicit_root_scroller_enabled_;
    RuntimeEnabledFeaturesBase::is_import_attributes_disallow_unknown_keys_enabled_ = is_import_attributes_disallow_unknown_keys_enabled_;
    RuntimeEnabledFeaturesBase::is_import_map_integrity_enabled_ = is_import_map_integrity_enabled_;
    RuntimeEnabledFeaturesBase::is_incoming_call_notifications_enabled_ = is_incoming_call_notifications_enabled_;
    RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_
        = is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_;
    RuntimeEnabledFeaturesBase::is_indexed_db_get_all_records_enabled_ = is_indexed_db_get_all_records_enabled_;
    RuntimeEnabledFeaturesBase::is_inert_element_non_editable_enabled_ = is_inert_element_non_editable_enabled_;
    RuntimeEnabledFeaturesBase::is_inert_element_non_searchable_enabled_ = is_inert_element_non_searchable_enabled_;
    RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_ = is_infinite_cull_rect_enabled_;
    RuntimeEnabledFeaturesBase::is_inherit_user_modify_without_contenteditable_enabled_ = is_inherit_user_modify_without_contenteditable_enabled_;
    RuntimeEnabledFeaturesBase::is_initial_letter_raise_by_specified_enabled_ = is_initial_letter_raise_by_specified_enabled_;
    RuntimeEnabledFeaturesBase::is_inline_block_in_same_line_enabled_ = is_inline_block_in_same_line_enabled_;
    RuntimeEnabledFeaturesBase::is_inner_html_parser_fastpath_log_failure_enabled_ = is_inner_html_parser_fastpath_log_failure_enabled_;
    RuntimeEnabledFeaturesBase::is_input_closes_select_enabled_ = is_input_closes_select_enabled_;
    RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = is_input_multiple_fields_ui_enabled_;
    RuntimeEnabledFeaturesBase::is_insert_blockquote_before_outer_block_enabled_ = is_insert_blockquote_before_outer_block_enabled_;
    RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = is_insert_line_break_if_phrasing_content_enabled_;
    RuntimeEnabledFeaturesBase::is_inspector_ghost_rules_enabled_ = is_inspector_ghost_rules_enabled_;
    RuntimeEnabledFeaturesBase::is_installed_app_enabled_ = is_installed_app_enabled_;
    RuntimeEnabledFeaturesBase::is_install_on_device_speech_recognition_enabled_ = is_install_on_device_speech_recognition_enabled_;
    RuntimeEnabledFeaturesBase::is_interest_groups_in_shared_storage_worklet_enabled_ = is_interest_groups_in_shared_storage_worklet_enabled_;
    RuntimeEnabledFeaturesBase::is_interoperable_private_attribution_enabled_ = is_interoperable_private_attribution_enabled_;
    RuntimeEnabledFeaturesBase::is_intersection_observer_scroll_margin_enabled_ = is_intersection_observer_scroll_margin_enabled_;
    RuntimeEnabledFeaturesBase::is_inverted_colors_enabled_ = is_inverted_colors_enabled_;
    RuntimeEnabledFeaturesBase::is_invisible_svg_animation_throttling_enabled_ = is_invisible_svg_animation_throttling_enabled_;
    RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_always_runtime_enabled_ = is_java_script_compile_hints_magic_always_runtime_enabled_;
    RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_runtime_enabled_ = is_java_script_compile_hints_magic_runtime_enabled_;
    RuntimeEnabledFeaturesBase::is_keep_css_target_after_reattach_enabled_ = is_keep_css_target_after_reattach_enabled_;
    RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_ = is_keyboard_accessible_tooltip_enabled_;
    RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_ = is_keyboard_focusable_scrollers_enabled_;
    RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_opt_out_enabled_ = is_keyboard_focusable_scrollers_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_label_and_delegates_focus_new_handling_enabled_ = is_label_and_delegates_focus_new_handling_enabled_;
    RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_ = is_lang_attribute_aware_form_control_ui_enabled_;
    RuntimeEnabledFeaturesBase::is_language_detection_api_enabled_ = is_language_detection_api_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_flex_new_row_algorithm_v_3_enabled_ = is_layout_flex_new_row_algorithm_v_3_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ignore_margins_for_sticky_enabled_ = is_layout_ignore_margins_for_sticky_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_justify_self_for_blocks_enabled_ = is_layout_justify_self_for_blocks_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_shape_cache_enabled_ = is_layout_ng_shape_cache_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_stretch_enabled_ = is_layout_stretch_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_ = is_lazy_initialize_media_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_enabled_ = is_lazy_load_scroll_margin_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_iframe_enabled_ = is_lazy_load_scroll_margin_iframe_enabled_;
    RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_ = is_lcp_animated_images_web_exposed_enabled_;
    RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_ = is_legacy_windows_d_write_font_fallback_enabled_;
    RuntimeEnabledFeaturesBase::is_limit_third_party_cookies_enabled_ = is_limit_third_party_cookies_enabled_;
    RuntimeEnabledFeaturesBase::is_line_box_below_leading_floats_enabled_ = is_line_box_below_leading_floats_enabled_;
    RuntimeEnabledFeaturesBase::is_list_item_with_counter_set_not_set_explicit_value_enabled_ = is_list_item_with_counter_set_not_set_explicit_value_enabled_;
    RuntimeEnabledFeaturesBase::is_locked_mode_enabled_ = is_locked_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_long_animation_frame_timing_enabled_ = is_long_animation_frame_timing_enabled_;
    RuntimeEnabledFeaturesBase::is_long_press_link_select_text_enabled_ = is_long_press_link_select_text_enabled_;
    RuntimeEnabledFeaturesBase::is_long_task_from_long_animation_frame_enabled_ = is_long_task_from_long_animation_frame_enabled_;
    RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_ = is_machine_learning_neural_network_enabled_;
    RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_ = is_managed_configuration_enabled_;
    RuntimeEnabledFeaturesBase::is_measure_memory_enabled_ = is_measure_memory_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_ = is_media_capabilities_dynamic_range_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_ = is_media_capabilities_encoding_info_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_ = is_media_capabilities_spatial_audio_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = is_media_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_ = is_media_capture_background_blur_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_camera_controls_enabled_ = is_media_capture_camera_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_configuration_change_enabled_ = is_media_capture_configuration_change_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_voice_isolation_enabled_ = is_media_capture_voice_isolation_enabled_;
    RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_ = is_media_cast_overlay_button_enabled_;
    RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_ = is_media_controls_expand_gesture_enabled_;
    RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = is_media_controls_overlay_play_button_enabled_;
    RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_ = is_media_element_volume_greater_than_one_enabled_;
    RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_ = is_media_engagement_bypass_autoplay_policies_enabled_;
    RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_ = is_media_latency_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_media_playback_while_not_visible_permission_policy_enabled_ = is_media_playback_while_not_visible_permission_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_media_previews_opt_out_enabled_ = is_media_previews_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_ = is_media_query_navigation_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_media_recorder_use_media_video_encoder_enabled_ = is_media_recorder_use_media_video_encoder_enabled_;
    RuntimeEnabledFeaturesBase::is_media_session_enabled_ = is_media_session_enabled_;
    RuntimeEnabledFeaturesBase::is_media_session_chapter_information_enabled_ = is_media_session_chapter_information_enabled_;
    RuntimeEnabledFeaturesBase::is_media_session_enter_picture_in_picture_enabled_ = is_media_session_enter_picture_in_picture_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_ = is_media_source_experimental_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_ = is_media_source_extensions_for_webcodecs_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_ = is_media_source_new_abort_and_duration_enabled_;
    RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_ = is_media_stream_track_transfer_enabled_;
    RuntimeEnabledFeaturesBase::is_media_stream_track_web_speech_enabled_ = is_media_stream_track_web_speech_enabled_;
    RuntimeEnabledFeaturesBase::is_message_port_close_event_enabled_ = is_message_port_close_event_enabled_;
    RuntimeEnabledFeaturesBase::is_meta_refresh_no_fractional_enabled_ = is_meta_refresh_no_fractional_enabled_;
    RuntimeEnabledFeaturesBase::is_meter_appearance_none_fallback_style_enabled_ = is_meter_appearance_none_fallback_style_enabled_;
    RuntimeEnabledFeaturesBase::is_meter_devolve_appearance_enabled_ = is_meter_devolve_appearance_enabled_;
    RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_ = is_middle_click_autoscroll_enabled_;
    RuntimeEnabledFeaturesBase::is_minimimal_resource_request_prep_before_cache_lookup_enabled_
        = is_minimimal_resource_request_prep_before_cache_lookup_enabled_;
    RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_ = is_mobile_layout_theme_enabled_;
    RuntimeEnabledFeaturesBase::is_modify_paragraph_cross_editingoundary_enabled_ = is_modify_paragraph_cross_editingoundary_enabled_;
    RuntimeEnabledFeaturesBase::SetMojoJSEnabled(is_mojo_js_enabled_);
    RuntimeEnabledFeaturesBase::SetMojoJSTestEnabled(is_mojo_js_test_enabled_);
    RuntimeEnabledFeaturesBase::is_move_ending_selection_to_list_child_enabled_ = is_move_ending_selection_to_list_child_enabled_;
    RuntimeEnabledFeaturesBase::is_move_to_paragraph_start_or_end_skips_non_editable_enabled_ = is_move_to_paragraph_start_or_end_skips_non_editable_enabled_;
    RuntimeEnabledFeaturesBase::is_multiple_import_maps_enabled_ = is_multiple_import_maps_enabled_;
    RuntimeEnabledFeaturesBase::is_multi_select_deselect_when_only_option_enabled_ = is_multi_select_deselect_when_only_option_enabled_;
    RuntimeEnabledFeaturesBase::is_multi_smooth_scroll_into_view_enabled_ = is_multi_smooth_scroll_into_view_enabled_;
    RuntimeEnabledFeaturesBase::is_mutation_events_enabled_ = is_mutation_events_enabled_;
    RuntimeEnabledFeaturesBase::is_mutation_events_special_trial_message_enabled_ = is_mutation_events_special_trial_message_enabled_;
    RuntimeEnabledFeaturesBase::is_navigate_event_commit_behavior_enabled_ = is_navigate_event_commit_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_navigate_event_source_element_enabled_ = is_navigate_event_source_element_enabled_;
    RuntimeEnabledFeaturesBase::is_navigation_activation_enabled_ = is_navigation_activation_enabled_;
    RuntimeEnabledFeaturesBase::is_navigation_id_enabled_ = is_navigation_id_enabled_;
    RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = is_navigator_content_utils_enabled_;
    RuntimeEnabledFeaturesBase::is_nested_view_transition_enabled_ = is_nested_view_transition_enabled_;
    RuntimeEnabledFeaturesBase::is_net_info_constant_type_enabled_ = is_net_info_constant_type_enabled_;
    RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = is_net_info_downlink_max_enabled_;
    RuntimeEnabledFeaturesBase::is_new_get_focusable_area_behavior_enabled_ = is_new_get_focusable_area_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_ = is_no_idle_encoding_for_web_tests_enabled_;
    RuntimeEnabledFeaturesBase::is_no_increasing_end_offset_on_splitting_text_nodes_enabled_ = is_no_increasing_end_offset_on_splitting_text_nodes_enabled_;
    RuntimeEnabledFeaturesBase::is_non_empty_blockquotes_on_outdenting_enabled_ = is_non_empty_blockquotes_on_outdenting_enabled_;
    RuntimeEnabledFeaturesBase::is_non_null_input_event_data_for_text_area_enabled_ = is_non_null_input_event_data_for_text_area_enabled_;
    RuntimeEnabledFeaturesBase::is_non_standard_appearance_value_slider_vertical_enabled_ = is_non_standard_appearance_value_slider_vertical_enabled_;
    RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = is_notification_constructor_enabled_;
    RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = is_notification_content_image_enabled_;
    RuntimeEnabledFeaturesBase::is_notifications_enabled_ = is_notifications_enabled_;
    RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_ = is_notification_triggers_enabled_;
    RuntimeEnabledFeaturesBase::is_observable_api_enabled_ = is_observable_api_enabled_;
    RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_ = is_off_main_thread_css_paint_enabled_;
    RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_ = is_offscreen_canvas_commit_enabled_;
    RuntimeEnabledFeaturesBase::is_omit_blur_event_on_element_removal_enabled_ = is_omit_blur_event_on_element_removal_enabled_;
    RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = is_on_device_change_enabled_;
    RuntimeEnabledFeaturesBase::is_on_device_web_speech_available_enabled_ = is_on_device_web_speech_available_enabled_;
    RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = is_orientation_event_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_ = is_origin_isolation_header_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_policy_enabled_ = is_origin_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_ = is_origin_trials_sample_api_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_browser_read_write_enabled_ = is_origin_trials_sample_api_browser_read_write_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_ = is_origin_trials_sample_api_dependent_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_ = is_origin_trials_sample_api_deprecation_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_ = is_origin_trials_sample_api_expiry_grace_period_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_
        = is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_ = is_origin_trials_sample_api_implied_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_ = is_origin_trials_sample_api_invalid_os_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_ = is_origin_trials_sample_api_navigation_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_
        = is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_ = is_origin_trials_sample_api_persistent_feature_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_invalid_os_enabled_ = is_origin_trials_sample_api_persistent_invalid_os_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_
        = is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_ = is_origin_trials_sample_api_third_party_enabled_;
    RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_ = is_overscroll_customization_enabled_;
    RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_ = is_page_freeze_opt_in_enabled_;
    RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_ = is_page_freeze_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_page_margin_boxes_enabled_ = is_page_margin_boxes_enabled_;
    RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = is_page_popup_enabled_;
    RuntimeEnabledFeaturesBase::is_page_reveal_event_enabled_ = is_page_reveal_event_enabled_;
    RuntimeEnabledFeaturesBase::is_page_swap_event_enabled_ = is_page_swap_event_enabled_;
    RuntimeEnabledFeaturesBase::is_paint_highlights_for_first_letter_enabled_ = is_paint_highlights_for_first_letter_enabled_;
    RuntimeEnabledFeaturesBase::is_paint_holding_for_iframes_enabled_ = is_paint_holding_for_iframes_enabled_;
    RuntimeEnabledFeaturesBase::is_paint_holding_for_local_iframes_enabled_ = is_paint_holding_for_local_iframes_enabled_;
    RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_ = is_paint_under_invalidation_checking_enabled_;
    RuntimeEnabledFeaturesBase::is_parakeet_enabled_ = is_parakeet_enabled_;
    RuntimeEnabledFeaturesBase::is_partitioned_popins_enabled_ = is_partitioned_popins_enabled_;
    RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = is_partition_visited_link_database_with_self_links_enabled_;
    RuntimeEnabledFeaturesBase::is_password_reveal_enabled_ = is_password_reveal_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_app_enabled_ = is_payment_app_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_instruments_enabled_ = is_payment_instruments_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_link_detection_enabled_ = is_payment_link_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_ = is_payment_method_change_event_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_request_enabled_ = is_payment_request_enabled_;
    RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_ = is_percent_based_scrolling_enabled_;
    RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_ = is_performance_manager_instrumentation_enabled_;
    RuntimeEnabledFeaturesBase::is_performance_mark_feature_usage_enabled_ = is_performance_mark_feature_usage_enabled_;
    RuntimeEnabledFeaturesBase::is_performance_navigate_system_entropy_enabled_ = is_performance_navigate_system_entropy_enabled_;
    RuntimeEnabledFeaturesBase::is_performance_navigation_timing_confidence_enabled_ = is_performance_navigation_timing_confidence_enabled_;
    RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_ = is_periodic_background_sync_enabled_;
    RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_ = is_per_method_can_make_payment_quota_enabled_;
    RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = is_permission_element_enabled_;
    RuntimeEnabledFeaturesBase::is_permissions_enabled_ = is_permissions_enabled_;
    RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_ = is_permissions_request_revoke_enabled_;
    RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_ = is_p_na_cl_enabled_;
    RuntimeEnabledFeaturesBase::is_pointer_event_device_id_enabled_ = is_pointer_event_device_id_enabled_;
    RuntimeEnabledFeaturesBase::is_pointer_event_targets_in_event_lists_enabled_ = is_pointer_event_targets_in_event_lists_enabled_;
    RuntimeEnabledFeaturesBase::is_popover_anchor_relationships_enabled_ = is_popover_anchor_relationships_enabled_;
    RuntimeEnabledFeaturesBase::is_popover_dialog_new_focus_behavior_enabled_ = is_popover_dialog_new_focus_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_position_outside_tab_span_check_sibling_node_enabled_ = is_position_outside_tab_span_check_sibling_node_enabled_;
    RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_ = is_precise_memory_info_enabled_;
    RuntimeEnabledFeaturesBase::is_prefer_default_scrollbar_styles_enabled_ = is_prefer_default_scrollbar_styles_enabled_;
    RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_ = is_prefer_non_composited_scrolling_enabled_;
    RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_ = is_prefers_reduced_data_enabled_;
    RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_ = is_prefixed_video_fullscreen_enabled_;
    RuntimeEnabledFeaturesBase::is_prerender_2_enabled_ = is_prerender_2_enabled_;
    RuntimeEnabledFeaturesBase::is_presentation_enabled_ = is_presentation_enabled_;
    RuntimeEnabledFeaturesBase::is_preserve_following_block_styles_during_block_merge_enabled_ = is_preserve_following_block_styles_during_block_merge_enabled_;
    RuntimeEnabledFeaturesBase::is_prevent_undo_if_not_editable_enabled_ = is_prevent_undo_if_not_editable_enabled_;
    RuntimeEnabledFeaturesBase::is_private_aggregation_api_filtering_ids_enabled_ = is_private_aggregation_api_filtering_ids_enabled_;
    RuntimeEnabledFeaturesBase::is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_
        = is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_;
    RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_ = is_private_network_access_non_secure_contexts_allowed_enabled_;
    RuntimeEnabledFeaturesBase::is_private_network_access_null_ip_address_enabled_ = is_private_network_access_null_ip_address_enabled_;
    RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_ = is_private_network_access_permission_prompt_enabled_;
    RuntimeEnabledFeaturesBase::is_private_state_tokens_enabled_ = is_private_state_tokens_enabled_;
    RuntimeEnabledFeaturesBase::is_private_state_tokens_always_allow_issuance_enabled_ = is_private_state_tokens_always_allow_issuance_enabled_;
    RuntimeEnabledFeaturesBase::SetProtectedOriginTrialsSampleAPIEnabled(is_protected_origin_trials_sample_api_enabled_);
    RuntimeEnabledFeaturesBase::SetProtectedOriginTrialsSampleAPIDependentEnabled(is_protected_origin_trials_sample_api_dependent_enabled_);
    RuntimeEnabledFeaturesBase::SetProtectedOriginTrialsSampleAPIImpliedEnabled(is_protected_origin_trials_sample_api_implied_enabled_);
    RuntimeEnabledFeaturesBase::is_pseudo_elements_correct_in_get_computed_style_enabled_ = is_pseudo_elements_correct_in_get_computed_style_enabled_;
    RuntimeEnabledFeaturesBase::is_pseudo_elements_focusable_enabled_ = is_pseudo_elements_focusable_enabled_;
    RuntimeEnabledFeaturesBase::is_push_message_data_bytes_enabled_ = is_push_message_data_bytes_enabled_;
    RuntimeEnabledFeaturesBase::is_push_messaging_enabled_ = is_push_messaging_enabled_;
    RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_ = is_push_messaging_subscription_change_enabled_;
    RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_ = is_quick_intensive_wake_up_throttling_after_loading_enabled_;
    RuntimeEnabledFeaturesBase::is_raster_inducing_scroll_enabled_ = is_raster_inducing_scroll_enabled_;
    RuntimeEnabledFeaturesBase::is_readable_stream_async_iterable_enabled_ = is_readable_stream_async_iterable_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_accept_language_enabled_ = is_reduce_accept_language_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_cookie_ip_cs_enabled_ = is_reduce_cookie_ip_cs_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = is_reduce_user_agent_android_version_device_model_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_ = is_reduce_user_agent_minor_version_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = is_reduce_user_agent_platform_os_cpu_enabled_;
    RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = is_region_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_rel_opener_bcg_dependency_hint_enabled_ = is_rel_opener_bcg_dependency_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_remote_playback_enabled_ = is_remote_playback_enabled_;
    RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = is_remote_playback_backend_enabled_;
    RuntimeEnabledFeaturesBase::is_remove_collapsed_placeholder_enabled_ = is_remove_collapsed_placeholder_enabled_;
    RuntimeEnabledFeaturesBase::is_remove_dangling_markup_in_target_enabled_ = is_remove_dangling_markup_in_target_enabled_;
    RuntimeEnabledFeaturesBase::is_remove_data_url_in_svg_use_enabled_ = is_remove_data_url_in_svg_use_enabled_;
    RuntimeEnabledFeaturesBase::is_remove_node_having_children_if_fully_selected_enabled_ = is_remove_node_having_children_if_fully_selected_enabled_;
    RuntimeEnabledFeaturesBase::is_remove_visible_selection_in_dom_selection_enabled_ = is_remove_visible_selection_in_dom_selection_enabled_;
    RuntimeEnabledFeaturesBase::is_render_blocking_inline_module_script_enabled_ = is_render_blocking_inline_module_script_enabled_;
    RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_ = is_render_blocking_status_enabled_;
    RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_ = is_render_priority_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_report_event_timing_at_visibility_change_enabled_ = is_report_event_timing_at_visibility_change_enabled_;
    RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = is_report_visible_line_bounds_enabled_;
    RuntimeEnabledFeaturesBase::is_reset_input_type_to_none_before_character_input_enabled_ = is_reset_input_type_to_none_before_character_input_enabled_;
    RuntimeEnabledFeaturesBase::is_resource_timing_content_type_enabled_ = is_resource_timing_content_type_enabled_;
    RuntimeEnabledFeaturesBase::is_resource_timing_final_response_headers_start_enabled_ = is_resource_timing_final_response_headers_start_enabled_;
    RuntimeEnabledFeaturesBase::is_resource_timing_use_cors_for_body_sizes_enabled_ = is_resource_timing_use_cors_for_body_sizes_enabled_;
    RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_ = is_restrict_gamepad_access_enabled_;
    RuntimeEnabledFeaturesBase::is_reuse_shape_results_by_fonts_enabled_ = is_reuse_shape_results_by_fonts_enabled_;
    RuntimeEnabledFeaturesBase::is_rewind_floats_enabled_ = is_rewind_floats_enabled_;
    RuntimeEnabledFeaturesBase::is_root_element_with_place_holder_after_deleting_selection_enabled_
        = is_root_element_with_place_holder_after_deleting_selection_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_ = is_rtc_audio_jitter_buffer_max_packets_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_data_channel_priority_enabled_ = is_rtc_data_channel_priority_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_encoded_audio_frame_abs_capture_time_enabled_ = is_rtc_encoded_audio_frame_abs_capture_time_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_encoded_frame_set_metadata_enabled_ = is_rtc_encoded_frame_set_metadata_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_encoded_video_frame_additional_metadata_enabled_ = is_rtc_encoded_video_frame_additional_metadata_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_jitter_buffer_target_enabled_ = is_rtc_jitter_buffer_target_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_legacy_callback_based_get_stats_enabled_ = is_rtc_legacy_callback_based_get_stats_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_rtp_encoding_parameters_codec_enabled_ = is_rtc_rtp_encoding_parameters_codec_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_rtp_scale_resolution_down_to_enabled_ = is_rtc_rtp_scale_resolution_down_to_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_rtp_script_transform_enabled_ = is_rtc_rtp_script_transform_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_rtp_transport_enabled_ = is_rtc_rtp_transport_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_ = is_rtc_stats_relative_packet_arrival_delay_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_ = is_rtc_svc_scalability_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_ruby_short_heuristics_enabled_ = is_ruby_short_heuristics_enabled_;
    RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_ = is_sanitizer_api_enabled_;
    RuntimeEnabledFeaturesBase::is_scheduler_yield_enabled_ = is_scheduler_yield_enabled_;
    RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = is_schedule_selection_change_on_backspace_enabled_;
    RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_ = is_scoped_custom_element_registry_enabled_;
    RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_ = is_scripted_speech_recognition_enabled_;
    RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_ = is_scripted_speech_synthesis_enabled_;
    RuntimeEnabledFeaturesBase::is_scrollbar_color_enabled_ = is_scrollbar_color_enabled_;
    RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_ = is_scrollbar_width_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_ = is_scroll_end_events_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_into_view_root_frame_viewport_bug_fix_enabled_ = is_scroll_into_view_root_frame_viewport_bug_fix_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_ = is_scroll_timeline_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_timeline_current_time_enabled_ = is_scroll_timeline_current_time_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_ = is_scroll_top_left_interop_enabled_;
    RuntimeEnabledFeaturesBase::is_search_text_highlight_pseudo_enabled_ = is_search_text_highlight_pseudo_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_ = is_secure_payment_confirmation_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_ = is_secure_payment_confirmation_debug_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_network_and_issuer_icons_enabled_
        = is_secure_payment_confirmation_network_and_issuer_icons_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_ = is_secure_payment_confirmation_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = is_select_audio_output_enabled_;
    RuntimeEnabledFeaturesBase::is_selectedcontentelement_attribute_enabled_ = is_selectedcontentelement_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_selection_across_shadow_dom_enabled_ = is_selection_across_shadow_dom_enabled_;
    RuntimeEnabledFeaturesBase::is_selection_is_collapsed_shadow_dom_support_enabled_ = is_selection_is_collapsed_shadow_dom_support_enabled_;
    RuntimeEnabledFeaturesBase::is_selection_on_shadow_dom_with_delegates_focus_enabled_ = is_selection_on_shadow_dom_with_delegates_focus_enabled_;
    RuntimeEnabledFeaturesBase::is_select_option_accessibility_target_size_enabled_ = is_select_option_accessibility_target_size_enabled_;
    RuntimeEnabledFeaturesBase::is_select_parser_relaxation_enabled_ = is_select_parser_relaxation_enabled_;
    RuntimeEnabledFeaturesBase::is_select_popup_less_updates_enabled_ = is_select_popup_less_updates_enabled_;
    RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
    RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_ = is_sensor_extra_classes_enabled_;
    RuntimeEnabledFeaturesBase::is_serial_enabled_ = is_serial_enabled_;
    RuntimeEnabledFeaturesBase::is_serialize_view_transition_state_in_spa_enabled_ = is_serialize_view_transition_state_in_spa_enabled_;
    RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = is_serial_port_connected_enabled_;
    RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_ = is_service_worker_client_lifecycle_state_enabled_;
    RuntimeEnabledFeaturesBase::is_service_worker_static_router_enabled_ = is_service_worker_static_router_enabled_;
    RuntimeEnabledFeaturesBase::is_service_worker_static_router_timing_info_enabled_ = is_service_worker_static_router_timing_info_enabled_;
    RuntimeEnabledFeaturesBase::is_set_sequential_focus_starting_point_enabled_ = is_set_sequential_focus_starting_point_enabled_;
    RuntimeEnabledFeaturesBase::is_shadow_root_reference_target_enabled_ = is_shadow_root_reference_target_enabled_;
    RuntimeEnabledFeaturesBase::is_shape_outside_writing_mode_fix_enabled_ = is_shape_outside_writing_mode_fix_enabled_;
    RuntimeEnabledFeaturesBase::is_shape_result_cached_previous_safe_to_break_offset_enabled_ = is_shape_result_cached_previous_safe_to_break_offset_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_ = is_shared_array_buffer_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_ = is_shared_array_buffer_on_desktop_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_ = is_shared_array_buffer_unrestricted_access_allowed_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_ = is_shared_autofill_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_ = is_shared_storage_api_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_storage_api_m_118_enabled_ = is_shared_storage_api_m_118_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_storage_api_m_125_enabled_ = is_shared_storage_api_m_125_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_storage_web_locks_enabled_ = is_shared_storage_web_locks_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = is_shared_worker_enabled_;
    RuntimeEnabledFeaturesBase::is_sideways_writing_modes_enabled_ = is_sideways_writing_modes_enabled_;
    RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_ = is_signature_based_integrity_enabled_;
    RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_ = is_site_initiated_mirroring_enabled_;
    RuntimeEnabledFeaturesBase::is_skip_ad_enabled_ = is_skip_ad_enabled_;
    RuntimeEnabledFeaturesBase::is_skip_preload_scanning_enabled_ = is_skip_preload_scanning_enabled_;
    RuntimeEnabledFeaturesBase::is_skip_temporary_document_fragment_enabled_ = is_skip_temporary_document_fragment_enabled_;
    RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_ = is_skip_touch_event_filter_enabled_;
    RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = is_smart_card_enabled_;
    RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = is_smart_zoom_enabled_;
    RuntimeEnabledFeaturesBase::is_smil_auto_suspend_on_lag_enabled_ = is_smil_auto_suspend_on_lag_enabled_;
    RuntimeEnabledFeaturesBase::is_soft_navigation_detection_enabled_ = is_soft_navigation_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_ = is_soft_navigation_heuristics_enabled_;
    RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_ = is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_;
    RuntimeEnabledFeaturesBase::is_speaker_selection_enabled_ = is_speaker_selection_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_down_heuristics_enabled_ = is_speculation_rules_pointer_down_heuristics_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_hover_heuristics_enabled_ = is_speculation_rules_pointer_hover_heuristics_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_future_enabled_ = is_speculation_rules_prefetch_future_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_ = is_speculation_rules_prefetch_with_subresources_enabled_;
    RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_ = is_srcset_max_density_enabled_;
    RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_ = is_stable_blink_features_enabled_;
    RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_enabled_ = is_standardized_browser_zoom_enabled_;
    RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_opt_out_enabled_ = is_standardized_browser_zoom_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_static_animation_optimization_enabled_ = is_static_animation_optimization_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_access_header_enabled_ = is_storage_access_header_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_ = is_storage_buckets_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_buckets_durability_enabled_ = is_storage_buckets_durability_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_buckets_locks_enabled_ = is_storage_buckets_locks_enabled_;
    RuntimeEnabledFeaturesBase::is_stricter_cell_width_content_size_quirk_enabled_ = is_stricter_cell_width_content_size_quirk_enabled_;
    RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_ = is_strict_mime_types_for_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_ = is_stylus_handwriting_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_context_paint_enabled_ = is_svg_context_paint_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_cross_origin_attribute_enabled_ = is_svg_cross_origin_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_eager_pres_attr_style_update_enabled_ = is_svg_eager_pres_attr_style_update_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_external_resources_enabled_ = is_svg_external_resources_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_filter_user_space_viewport_for_non_svg_enabled_ = is_svg_filter_user_space_viewport_for_non_svg_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_gradient_color_interpolation_linear_rgb_support_enabled_
        = is_svg_gradient_color_interpolation_linear_rgb_support_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_ = is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_no_pixel_snapping_scale_adjustment_enabled_ = is_svg_no_pixel_snapping_scale_adjustment_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_transform_optimization_enabled_ = is_svg_transform_optimization_enabled_;
    RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_
        = is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
    RuntimeEnabledFeaturesBase::is_system_fallback_emoji_vs_support_enabled_ = is_system_fallback_emoji_vs_support_enabled_;
    RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_ = is_system_wake_lock_enabled_;
    RuntimeEnabledFeaturesBase::is_test_blink_feature_default_enabled_ = is_test_blink_feature_default_enabled_;
    RuntimeEnabledFeaturesBase::is_test_feature_enabled_ = is_test_feature_enabled_;
    RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_ = is_test_feature_dependent_enabled_;
    RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_ = is_test_feature_implied_enabled_;
    RuntimeEnabledFeaturesBase::SetTestFeatureProtectedEnabled(is_test_feature_protected_enabled_);
    RuntimeEnabledFeaturesBase::SetTestFeatureProtectedDependentEnabled(is_test_feature_protected_dependent_enabled_);
    RuntimeEnabledFeaturesBase::SetTestFeatureProtectedImpliedEnabled(is_test_feature_protected_implied_enabled_);
    RuntimeEnabledFeaturesBase::is_test_feature_stable_enabled_ = is_test_feature_stable_enabled_;
    RuntimeEnabledFeaturesBase::is_text_detector_enabled_ = is_text_detector_enabled_;
    RuntimeEnabledFeaturesBase::is_text_diff_split_fix_enabled_ = is_text_diff_split_fix_enabled_;
    RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_ = is_text_fragment_api_enabled_;
    RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_ = is_text_fragment_identifiers_enabled_;
    RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = is_text_fragment_tap_opens_context_menu_enabled_;
    RuntimeEnabledFeaturesBase::is_text_input_not_always_dir_auto_enabled_ = is_text_input_not_always_dir_auto_enabled_;
    RuntimeEnabledFeaturesBase::is_text_metrics_baselines_enabled_ = is_text_metrics_baselines_enabled_;
    RuntimeEnabledFeaturesBase::is_text_segment_boundary_for_element_with_float_style_enabled_ = is_text_segment_boundary_for_element_with_float_style_enabled_;
    RuntimeEnabledFeaturesBase::is_text_size_adjust_improvements_enabled_ = is_text_size_adjust_improvements_enabled_;
    RuntimeEnabledFeaturesBase::is_text_transform_and_security_fix_enabled_ = is_text_transform_and_security_fix_enabled_;
    RuntimeEnabledFeaturesBase::is_timeline_scope_enabled_ = is_timeline_scope_enabled_;
    RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_ = is_timer_throttling_for_background_tabs_enabled_;
    RuntimeEnabledFeaturesBase::is_timestamp_based_cls_tracking_enabled_ = is_timestamp_based_cls_tracking_enabled_;
    RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_ = is_time_zone_change_event_enabled_;
    RuntimeEnabledFeaturesBase::is_topics_api_enabled_ = is_topics_api_enabled_;
    RuntimeEnabledFeaturesBase::is_topics_document_api_enabled_ = is_topics_document_api_enabled_;
    RuntimeEnabledFeaturesBase::is_top_layer_inactive_document_exceptions_enabled_ = is_top_layer_inactive_document_exceptions_enabled_;
    RuntimeEnabledFeaturesBase::is_top_level_tpcd_enabled_ = is_top_level_tpcd_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_ = is_touch_drag_and_context_menu_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_ = is_touch_drag_on_short_press_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_ = is_touch_event_feature_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_text_editing_redesign_enabled_ = is_touch_text_editing_redesign_enabled_;
    RuntimeEnabledFeaturesBase::is_tpcd_enabled_ = is_tpcd_enabled_;
    RuntimeEnabledFeaturesBase::is_transferable_rtc_data_channel_enabled_ = is_transferable_rtc_data_channel_enabled_;
    RuntimeEnabledFeaturesBase::is_translate_service_enabled_ = is_translate_service_enabled_;
    RuntimeEnabledFeaturesBase::is_translation_api_enabled_ = is_translation_api_enabled_;
    RuntimeEnabledFeaturesBase::is_translation_api_entry_point_enabled_ = is_translation_api_entry_point_enabled_;
    RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_ = is_trusted_type_before_policy_creation_event_enabled_;
    RuntimeEnabledFeaturesBase::is_trusted_types_from_literal_enabled_ = is_trusted_types_from_literal_enabled_;
    RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_ = is_trusted_types_use_code_like_enabled_;
    RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_ = is_unclosed_form_control_is_invalid_enabled_;
    RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_ = is_unexposed_task_ids_enabled_;
    RuntimeEnabledFeaturesBase::is_unowned_animations_skip_css_events_enabled_ = is_unowned_animations_skip_css_events_enabled_;
    RuntimeEnabledFeaturesBase::is_unrestricted_measure_user_agent_specific_memory_enabled_ = is_unrestricted_measure_user_agent_specific_memory_enabled_;
    RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_ = is_unrestricted_shared_array_buffer_enabled_;
    RuntimeEnabledFeaturesBase::is_unrestricted_usb_enabled_ = is_unrestricted_usb_enabled_;
    RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_ = is_url_pattern_compare_component_enabled_;
    RuntimeEnabledFeaturesBase::is_url_search_params_has_and_delete_multiple_args_enabled_ = is_url_search_params_has_and_delete_multiple_args_enabled_;
    RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = is_use_begin_frame_presentation_feedback_enabled_;
    RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = is_use_low_quality_interpolation_enabled_;
    RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_ = is_user_activation_same_origin_visibility_enabled_;
    RuntimeEnabledFeaturesBase::is_use_selection_focus_node_for_caret_navigation_enabled_ = is_use_selection_focus_node_for_caret_navigation_enabled_;
    RuntimeEnabledFeaturesBase::is_use_undo_step_element_dispatch_before_input_enabled_ = is_use_undo_step_element_dispatch_before_input_enabled_;
    RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_ = is_v8_idle_tasks_enabled_;
    RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_ = is_video_auto_fullscreen_enabled_;
    RuntimeEnabledFeaturesBase::is_video_frame_metadata_background_blur_enabled_ = is_video_frame_metadata_background_blur_enabled_;
    RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_ = is_video_fullscreen_orientation_lock_enabled_;
    RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_ = is_video_rotate_to_fullscreen_enabled_;
    RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_ = is_video_track_generator_enabled_;
    RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_ = is_video_track_generator_in_window_enabled_;
    RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_ = is_video_track_generator_in_worker_enabled_;
    RuntimeEnabledFeaturesBase::is_viewport_changes_update_text_autosizing_enabled_ = is_viewport_changes_update_text_autosizing_enabled_;
    RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_ = is_viewport_height_client_hint_header_enabled_;
    RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_ = is_viewport_segments_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_disable_snap_browser_controls_on_hidden_enabled_
        = is_view_transition_disable_snap_browser_controls_on_hidden_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_layered_capture_enabled_ = is_view_transition_layered_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_long_callback_timeout_for_testing_enabled_ = is_view_transition_long_callback_timeout_for_testing_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_enabled_ = is_view_transition_on_navigation_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_for_iframes_enabled_ = is_view_transition_on_navigation_for_iframes_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_overflow_rect_from_surface_enabled_ = is_view_transition_overflow_rect_from_surface_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_tree_scoped_names_enabled_ = is_view_transition_tree_scoped_names_enabled_;
    RuntimeEnabledFeaturesBase::is_view_transition_types_enabled_ = is_view_transition_types_enabled_;
    RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_ = is_visibility_collapse_column_enabled_;
    RuntimeEnabledFeaturesBase::is_visual_viewport_on_scroll_end_enabled_ = is_visual_viewport_on_scroll_end_enabled_;
    RuntimeEnabledFeaturesBase::is_wake_lock_enabled_ = is_wake_lock_enabled_;
    RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_ = is_warn_on_content_visibility_render_access_enabled_;
    RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_ = is_web_animations_svg_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_installation_enabled_ = is_web_app_installation_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_ = is_web_app_launch_queue_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_scope_extensions_enabled_ = is_web_app_scope_extensions_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = is_web_app_tab_strip_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = is_web_app_tab_strip_customizations_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_ = is_web_app_translations_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_ = is_web_app_url_handling_enabled_;
    RuntimeEnabledFeaturesBase::is_web_assembly_js_promise_integration_enabled_ = is_web_assembly_js_promise_integration_enabled_;
    RuntimeEnabledFeaturesBase::is_web_assembly_js_string_builtins_enabled_ = is_web_assembly_js_string_builtins_enabled_;
    RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_enabled_ = is_web_audio_bypass_output_buffering_enabled_;
    RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_opt_out_enabled_ = is_web_audio_bypass_output_buffering_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_web_auth_enabled_ = is_web_auth_enabled_;
    RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_ = is_web_auth_authenticator_attachment_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_ambient_enabled_ = is_web_authentication_ambient_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_attestation_formats_enabled_ = is_web_authentication_attestation_formats_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_client_capabilities_enabled_ = is_web_authentication_client_capabilities_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_js_on_serialization_enabled_ = is_web_authentication_js_on_serialization_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_ = is_web_authentication_large_blob_extension_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_prf_enabled_ = is_web_authentication_prf_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_ = is_web_authentication_remote_desktop_support_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_supplemental_pub_keys_enabled_ = is_web_authentication_supplemental_pub_keys_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = is_web_bluetooth_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_ = is_web_bluetooth_get_devices_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_ = is_web_bluetooth_scanning_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_ = is_web_bluetooth_watch_advertisements_enabled_;
    RuntimeEnabledFeaturesBase::is_webcodecs_copy_to_rgb_enabled_ = is_webcodecs_copy_to_rgb_enabled_;
    RuntimeEnabledFeaturesBase::is_webcodecs_hbd_formats_enabled_ = is_webcodecs_hbd_formats_enabled_;
    RuntimeEnabledFeaturesBase::is_webcodecs_orientation_enabled_ = is_webcodecs_orientation_enabled_;
    RuntimeEnabledFeaturesBase::is_webcodecs_video_encoder_buffers_enabled_ = is_webcodecs_video_encoder_buffers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_crypto_curve_25519_enabled_ = is_web_crypto_curve_25519_enabled_;
    RuntimeEnabledFeaturesBase::is_web_font_resize_lcp_enabled_ = is_web_font_resize_lcp_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_ = is_webgl_developer_extensions_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_ = is_webgl_draft_extensions_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_drawing_buffer_storage_enabled_ = is_webgl_drawing_buffer_storage_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_ = is_webgl_image_chromium_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_canvas_context_get_configuration_enabled_ = is_webgpu_canvas_context_get_configuration_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_ = is_webgpu_developer_features_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_device_adapter_info_enabled_ = is_webgpu_device_adapter_info_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_experimental_features_enabled_ = is_webgpu_experimental_features_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_hdr_enabled_ = is_webgpu_hdr_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_subgroups_features_enabled_ = is_webgpu_subgroups_features_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_texture_view_usage_enabled_ = is_webgpu_texture_view_usage_enabled_;
    RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = is_web_hid_enabled_;
    RuntimeEnabledFeaturesBase::is_web_hid_on_dedicated_workers_enabled_ = is_web_hid_on_dedicated_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_ = is_web_hid_on_service_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_identity_digital_credentials_enabled_ = is_web_identity_digital_credentials_enabled_;
    RuntimeEnabledFeaturesBase::is_web_idl_big_int_uses_to_big_int_enabled_ = is_web_idl_big_int_uses_to_big_int_enabled_;
    RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = is_web_nfc_enabled_;
    RuntimeEnabledFeaturesBase::is_web_otp_enabled_ = is_web_otp_enabled_;
    RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_ = is_web_otp_assertion_feature_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_web_preferences_enabled_ = is_web_preferences_enabled_;
    RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = is_web_printing_enabled_;
    RuntimeEnabledFeaturesBase::is_web_share_enabled_ = is_web_share_enabled_;
    RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_ = is_websocket_stream_enabled_;
    RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_ = is_web_transport_custom_certificates_enabled_;
    RuntimeEnabledFeaturesBase::is_web_transport_stats_enabled_ = is_web_transport_stats_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_enabled_ = is_web_usb_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_ = is_web_usb_on_dedicated_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_ = is_web_usb_on_service_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_view_xr_equested_with_deprecation_enabled_ = is_web_view_xr_equested_with_deprecation_enabled_;
    RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_ = is_web_vtt_regions_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_enabled_ = is_web_xr_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_enabled_features_enabled_ = is_web_xr_enabled_features_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_frame_rate_enabled_ = is_web_xr_frame_rate_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_front_facing_enabled_ = is_web_xr_front_facing_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_gpu_binding_enabled_ = is_web_xr_gpu_binding_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_ = is_web_xr_hand_input_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_ = is_web_xr_hit_test_entity_types_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_ = is_web_xr_image_tracking_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_layers_enabled_ = is_web_xr_layers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_layers_common_enabled_ = is_web_xr_layers_common_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_ = is_web_xr_plane_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_pose_motion_data_enabled_ = is_web_xr_pose_motion_data_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_spec_parity_enabled_ = is_web_xr_spec_parity_enabled_;
    RuntimeEnabledFeaturesBase::is_window_default_status_enabled_ = is_window_default_status_enabled_;
    RuntimeEnabledFeaturesBase::is_xml_parser_merge_adjacent_c_data_sections_enabled_ = is_xml_parser_merge_adjacent_c_data_sections_enabled_;
    RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_ = is_zero_copy_tab_capture_enabled_;
}

void RuntimeEnabledFeaturesBase::SetStableFeaturesEnabled(bool enable)
{
    SetAccelerated2dCanvasEnabled(enable);
    SetAcceleratedSmallCanvasesEnabled(enable);
    SetAdInterestGroupAPIEnabled(enable);
    SetAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled(enable);
    SetAnonymousIframeEnabled(enable);
    SetAriaRowColIndexTextEnabled(enable);
    SetAttributionReportingEnabled(enable);
    SetAttributionReportingCrossAppWebEnabled(enable);
    SetAudioContextOnErrorEnabled(enable);
    SetAudioContextSetSinkIdEnabled(enable);
    SetAuraScrollbarUsesSolidColorThumbEnabled(enable);
    SetBackForwardCacheNotRestoredReasonsEnabled(enable);
    SetBackgroundFetchEnabled(enable);
    SetBoxDecorationBreakEnabled(enable);
    SetBreakIteratorHyphenMinusEnabled(enable);
    SetBufferedBytesConsumerLimitSizeEnabled(enable);
    SetCalendarPickerMonthPopupButtonDisabledColorEnabled(enable);
    SetCallExitNodeWithoutLayoutObjectEnabled(enable);
    SetCanvasUsesArcPaintOpEnabled(enable);
    SetCaretPositionFromPointEnabled(enable);
    SetCheckIfHighestRootContainsPositionAnchorNodeEnabled(enable);
    SetCheckVisibilityExtraPropertiesEnabled(enable);
    SetClipPathRejectEmptyPathsEnabled(enable);
    SetCoalesceSelectionchangeEventEnabled(enable);
    SetCompositedAnimationsCancelledAsynchronouslyEnabled(enable);
    SetConcurrentViewTransitionsSPAEnabled(enable);
    SetContainerTypeNoLayoutContainmentEnabled(enable);
    SetContinueEventTimingRecordingWhenBufferIsFullEnabled(enable);
    SetCreateInputShadowTreeDuringLayoutEnabled(enable);
    SetCredentialManagerReportEnabled(enable);
    SetCSSAnchorScopeEnabled(enable);
    SetCSSAnchorSizeInsetsMarginsEnabled(enable);
    SetCSSAtPropertyStringSyntaxEnabled(enable);
    SetCSSBackgroundClipUnprefixEnabled(enable);
    SetCSSCalcSizeFunctionEnabled(enable);
    SetCSSCascadeCorrectScopeEnabled(enable);
    SetCSSComputedStyleFullPseudoElementParserEnabled(enable);
    SetCSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled(enable);
    SetCSSCustomStateNewSyntaxEnabled(enable);
    SetCSSExponentialFunctionsEnabled(enable);
    SetCSSFlatTreeContainerEnabled(enable);
    SetCSSFontSizeAdjustEnabled(enable);
    SetCSSHexAlphaColorEnabled(enable);
    SetCSSKeyframesRuleLengthEnabled(enable);
    SetCSSLineClampWebkitBoxBlockificationEnabled(enable);
    SetCSSNestedDeclarationsEnabled(enable);
    SetCSSPartAllowsMoreSelectorsAfterEnabled(enable);
    SetCSSPositionAreaValueEnabled(enable);
    SetCSSRelativeColorEnabled(enable);
    SetCSSRelativeColorLateResolveAlwaysEnabled(enable);
    SetCSSRelativeColorPreserveNoneEnabled(enable);
    SetCSSRelativeColorSupportsCurrentcolorEnabled(enable);
    SetCSSResizeAutoEnabled(enable);
    SetCSSScrollSnapChangeEventEnabled(enable);
    SetCSSScrollSnapChangingEventEnabled(enable);
    SetCSSScrollSnapEventsEnabled(enable);
    SetCSSSteppedValueFunctionsEnabled(enable);
    SetCSSSupportsForImportRulesEnabled(enable);
    SetCSSViewTransitionClassEnabled(enable);
    SetDetailsStylingEnabled(enable);
    SetDevicePostureEnabled(enable);
    SetDialogElementToggleEventsEnabled(enable);
    SetDirAutoFixSlotExclusionsEnabled(enable);
    SetDirectSocketsEnabled(enable);
    SetDisableSelectAllForEmptyTextEnabled(enable);
    SetDispatchBeforeInputForSpinButtonInteractionsEnabled(enable);
    SetDispatchHiddenVisibilityTransitionsEnabled(enable);
    SetDispatchSelectionchangeEventPerElementEnabled(enable);
    SetDocumentInstallChunkingEnabled(enable);
    SetDocumentOpenSandboxInheritanceRemovalEnabled(enable);
    SetDocumentRenderBlockingEnabled(enable);
    SetDropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled(enable);
    SetEnforceAnonymityExposureEnabled(enable);
    SetEventTimingHandleKeyboardEventSimulatedClickEnabled(enable);
    SetEventTimingTapStopScrollNoInteractionIdEnabled(enable);
    SetExcludeTransparentTextsFromBeingLcpEligibleEnabled(enable);
    SetFastNonCompositedScrollHitTestEnabled(enable);
    SetFastPathSingleSelectorExactMatchEnabled(enable);
    SetFedCmEnabled(enable);
    SetFedCmAuthzEnabled(enable);
    SetFedCmAutoSelectedFlagEnabled(enable);
    SetFedCmButtonModeEnabled(enable);
    SetFedCmDisconnectEnabled(enable);
    SetFedCmDomainHintEnabled(enable);
    SetFedCmErrorEnabled(enable);
    SetFedCmIdpSigninStatusEnabled(enable);
    SetFedCmWithStorageAccessAPIEnabled(enable);
    SetFencedFramesEnabled(enable);
    SetFencedFramesAPIChangesEnabled(enable);
    SetFetchBodyBytesEnabled(enable);
    SetFetchUploadStreamingEnabled(enable);
    SetFileSystemEnabled(enable);
    SetFileSystemAccessLockingSchemeEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFindDecomposedInShortTextEnabled(enable);
    SetFindRubyInPageEnabled(enable);
    SetFindTextSkipCollapsedTextEnabled(enable);
    SetFledgeEnabled(enable);
    SetFledgeBiddingAndAuctionServerAPIEnabled(enable);
    SetFledgeCustomMaxAuctionAdComponentsEnabled(enable);
    SetFledgeDeprecatedRenderURLReplacementsEnabled(enable);
    SetFledgeDirectFromSellerSignalsHeaderAdSlotEnabled(enable);
    SetFledgeMultiBidEnabled(enable);
    SetFledgeRealTimeReportingEnabled(enable);
    SetFledgeReportingTimeoutEnabled(enable);
    SetFluentScrollbarUsesNinePatchTrackEnabled(enable);
    SetFontationsForSelectedFormatsEnabled(enable);
    SetFontPresentWinEnabled(enable);
    SetFontSystemFallbackNotoCjkEnabled(enable);
    SetFontVariantEmojiEnabled(enable);
    SetFontVariationSequencesEnabled(enable);
    SetForcedColorsEnabled(enable);
    SetForcedColorsPreserveParentColorEnabled(enable);
    SetFormControlsVerticalWritingModeDirectionSupportEnabled(enable);
    SetHandleSelectionChangeOnDeletingEmptyElementEnabled(enable);
    SetHangingWhitespaceDoesNotDependOnAlignmentEnabled(enable);
    SetHasUAVisualTransitionEnabled(enable);
    SetHitTestOpaquenessEnabled(enable);
    SetHitTestOpaquenessOmitLineBoxEnabled(enable);
    SetHrefTranslateEnabled(enable);
    SetHTMLEmbedElementNotForceLayoutEnabled(enable);
    SetHTMLObjectElementFallbackDetachContentFrameEnabled(enable);
    SetHTMLSelectElementShowPickerEnabled(enable);
    SetImportAttributesDisallowUnknownKeysEnabled(enable);
    SetImportMapIntegrityEnabled(enable);
    SetInertElementNonEditableEnabled(enable);
    SetInertElementNonSearchableEnabled(enable);
    SetInheritUserModifyWithoutContenteditableEnabled(enable);
    SetInitialLetterRaiseBySpecifiedEnabled(enable);
    SetInlineBlockInSameLineEnabled(enable);
    SetInsertBlockquoteBeforeOuterBlockEnabled(enable);
    SetInstalledAppEnabled(enable);
    SetIntersectionObserverScrollMarginEnabled(enable);
    SetInvisibleSVGAnimationThrottlingEnabled(enable);
    SetKeepCSSTargetAfterReattachEnabled(enable);
    SetKeyboardFocusableScrollersEnabled(enable);
    SetLabelAndDelegatesFocusNewHandlingEnabled(enable);
    SetLayoutJustifySelfForBlocksEnabled(enable);
    SetLazyLoadScrollMarginEnabled(enable);
    SetLazyLoadScrollMarginIframeEnabled(enable);
    SetLineBoxBelowLeadingFloatsEnabled(enable);
    SetListItemWithCounterSetNotSetExplicitValueEnabled(enable);
    SetLongAnimationFrameTimingEnabled(enable);
    SetManagedConfigurationEnabled(enable);
    SetMeasureMemoryEnabled(enable);
    SetMediaCapabilitiesDynamicRangeEnabled(enable);
    SetMediaSessionEnabled(enable);
    SetMediaSessionChapterInformationEnabled(enable);
    SetMediaSessionEnterPictureInPictureEnabled(enable);
    SetMetaRefreshNoFractionalEnabled(enable);
    SetMeterAppearanceNoneFallbackStyleEnabled(enable);
    SetMeterDevolveAppearanceEnabled(enable);
    SetMinimimalResourceRequestPrepBeforeCacheLookupEnabled(enable);
    SetModifyParagraphCrossEditingoundaryEnabled(enable);
    SetMoveEndingSelectionToListChildEnabled(enable);
    SetMoveToParagraphStartOrEndSkipsNonEditableEnabled(enable);
    SetMultiSmoothScrollIntoViewEnabled(enable);
    SetNavigationActivationEnabled(enable);
    SetNewGetFocusableAreaBehaviorEnabled(enable);
    SetNoIncreasingEndOffsetOnSplittingTextNodesEnabled(enable);
    SetNonEmptyBlockquotesOnOutdentingEnabled(enable);
    SetNonNullInputEventDataForTextAreaEnabled(enable);
    SetNonStandardAppearanceValueSliderVerticalEnabled(enable);
    SetNotificationsEnabled(enable);
    SetOffMainThreadCSSPaintEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetOriginIsolationHeaderEnabled(enable);
    SetPageMarginBoxesEnabled(enable);
    SetPageRevealEventEnabled(enable);
    SetPageSwapEventEnabled(enable);
    SetPaintHighlightsForFirstLetterEnabled(enable);
    SetPaintHoldingForIframesEnabled(enable);
    SetPaintHoldingForLocalIframesEnabled(enable);
    SetPaymentMethodChangeEventEnabled(enable);
    SetPeriodicBackgroundSyncEnabled(enable);
    SetPermissionsEnabled(enable);
    SetPointerEventDeviceIdEnabled(enable);
    SetPointerEventTargetsInEventListsEnabled(enable);
    SetPopoverDialogNewFocusBehaviorEnabled(enable);
    SetPositionOutsideTabSpanCheckSiblingNodeEnabled(enable);
    SetPrerender2Enabled(enable);
    SetPresentationEnabled(enable);
    SetPreserveFollowingBlockStylesDuringBlockMergeEnabled(enable);
    SetPreventUndoIfNotEditableEnabled(enable);
    SetPrivateAggregationApiFilteringIdsEnabled(enable);
    SetPrivateAggregationAuctionReportBuyerDebugModeConfigEnabled(enable);
    SetPrivateNetworkAccessPermissionPromptEnabled(enable);
    SetPseudoElementsCorrectInGetComputedStyleEnabled(enable);
    SetPushMessageDataBytesEnabled(enable);
    SetPushMessagingEnabled(enable);
    SetQuickIntensiveWakeUpThrottlingAfterLoadingEnabled(enable);
    SetReadableStreamAsyncIterableEnabled(enable);
    SetReduceCookieIPCsEnabled(enable);
    SetReduceUserAgentMinorVersionEnabled(enable);
    SetRemotePlaybackEnabled(enable);
    SetRemoveCollapsedPlaceholderEnabled(enable);
    SetRemoveDanglingMarkupInTargetEnabled(enable);
    SetRemoveDataUrlInSvgUseEnabled(enable);
    SetRemoveNodeHavingChildrenIfFullySelectedEnabled(enable);
    SetRenderBlockingInlineModuleScriptEnabled(enable);
    SetRenderBlockingStatusEnabled(enable);
    SetReportEventTimingAtVisibilityChangeEnabled(enable);
    SetResetInputTypeToNoneBeforeCharacterInputEnabled(enable);
    SetReuseShapeResultsByFontsEnabled(enable);
    SetRewindFloatsEnabled(enable);
    SetRootElementWithPlaceHolderAfterDeletingSelectionEnabled(enable);
    SetRTCJitterBufferTargetEnabled(enable);
    SetRTCRtpEncodingParametersCodecEnabled(enable);
    SetRTCRtpScaleResolutionDownToEnabled(enable);
    SetRTCSvcScalabilityModeEnabled(enable);
    SetRubyShortHeuristicsEnabled(enable);
    SetSchedulerYieldEnabled(enable);
    SetScriptedSpeechRecognitionEnabled(enable);
    SetScriptedSpeechSynthesisEnabled(enable);
    SetScrollbarColorEnabled(enable);
    SetScrollbarWidthEnabled(enable);
    SetScrollEndEventsEnabled(enable);
    SetScrollIntoViewRootFrameViewportBugFixEnabled(enable);
    SetScrollTimelineEnabled(enable);
    SetScrollTopLeftInteropEnabled(enable);
    SetSecurePaymentConfirmationOptOutEnabled(enable);
    SetSelectionIsCollapsedShadowDOMSupportEnabled(enable);
    SetSelectOptionAccessibilityTargetSizeEnabled(enable);
    SetSelectPopupLessUpdatesEnabled(enable);
    SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(enable);
    SetShapeOutsideWritingModeFixEnabled(enable);
    SetShapeResultCachedPreviousSafeToBreakOffsetEnabled(enable);
    SetSharedStorageAPIEnabled(enable);
    SetSidewaysWritingModesEnabled(enable);
    SetSkipAdEnabled(enable);
    SetSkipTemporaryDocumentFragmentEnabled(enable);
    SetSkipTouchEventFilterEnabled(enable);
    SetSmilAutoSuspendOnLagEnabled(enable);
    SetSoftNavigationDetectionEnabled(enable);
    SetStableBlinkFeaturesEnabled(enable);
    SetStandardizedBrowserZoomEnabled(enable);
    SetStaticAnimationOptimizationEnabled(enable);
    SetStorageBucketsEnabled(enable);
    SetStricterCellWidthContentSizeQuirkEnabled(enable);
    SetSvgContextPaintEnabled(enable);
    SetSvgCrossOriginAttributeEnabled(enable);
    SetSvgEagerPresAttrStyleUpdateEnabled(enable);
    SetSvgExternalResourcesEnabled(enable);
    SetSvgFilterUserSpaceViewportForNonSvgEnabled(enable);
    SetSvgGradientColorInterpolationLinearRgbSupportEnabled(enable);
    SetSvgInlineRootPixelSnappingScaleAdjustmentEnabled(enable);
    SetSvgNoPixelSnappingScaleAdjustmentEnabled(enable);
    SetSvgTransformOptimizationEnabled(enable);
    SetSystemFallbackEmojiVSSupportEnabled(enable);
    SetTestFeatureStableEnabled(enable);
    SetTextDiffSplitFixEnabled(enable);
    SetTextFragmentIdentifiersEnabled(enable);
    SetTextInputNotAlwaysDirAutoEnabled(enable);
    SetTextMetricsBaselinesEnabled(enable);
    SetTextSegmentBoundaryForElementWithFloatStyleEnabled(enable);
    SetTextTransformAndSecurityFixEnabled(enable);
    SetTimelineScopeEnabled(enable);
    SetTimerThrottlingForBackgroundTabsEnabled(enable);
    SetTopicsAPIEnabled(enable);
    SetTopicsDocumentAPIEnabled(enable);
    SetTopLayerInactiveDocumentExceptionsEnabled(enable);
    SetTouchEventFeatureDetectionEnabled(enable);
    SetTransferableRTCDataChannelEnabled(enable);
    SetUnownedAnimationsSkipCSSEventsEnabled(enable);
    SetUnrestrictedUsbEnabled(enable);
    SetURLSearchParamsHasAndDeleteMultipleArgsEnabled(enable);
    SetUseSelectionFocusNodeForCaretNavigationEnabled(enable);
    SetUseUndoStepElementDispatchBeforeInputEnabled(enable);
    SetViewportChangesUpdateTextAutosizingEnabled(enable);
    SetViewportHeightClientHintHeaderEnabled(enable);
    SetViewTransitionDisableSnapBrowserControlsOnHiddenEnabled(enable);
    SetViewTransitionOnNavigationEnabled(enable);
    SetViewTransitionOnNavigationForIframesEnabled(enable);
    SetViewTransitionOverflowRectFromSurfaceEnabled(enable);
    SetViewTransitionTreeScopedNamesEnabled(enable);
    SetViewTransitionTypesEnabled(enable);
    SetVisualViewportOnScrollEndEnabled(enable);
    SetWakeLockEnabled(enable);
    SetWebAssemblyJSStringBuiltinsEnabled(enable);
    SetWebAuthEnabled(enable);
    SetWebAuthenticationJSONSerializationEnabled(enable);
    SetWebAuthenticationLargeBlobExtensionEnabled(enable);
    SetWebAuthenticationPRFEnabled(enable);
    SetWebCodecsCopyToRGBEnabled(enable);
    SetWebCodecsHBDFormatsEnabled(enable);
    SetWebGLDrawingBufferStorageEnabled(enable);
    SetWebGPUCanvasContextGetConfigurationEnabled(enable);
    SetWebGPUDeviceAdapterInfoEnabled(enable);
    SetWebGPUHDREnabled(enable);
    SetWebGPUTextureViewUsageEnabled(enable);
    SetWebHIDOnDedicatedWorkersEnabled(enable);
    SetWebIDLBigIntUsesToBigIntEnabled(enable);
    SetWebOTPEnabled(enable);
    SetWebOTPAssertionFeaturePolicyEnabled(enable);
    SetWebSocketStreamEnabled(enable);
    SetWebTransportCustomCertificatesEnabled(enable);
    SetWebUSBEnabled(enable);
    SetWebUSBOnDedicatedWorkersEnabled(enable);
    SetWebXREnabled(enable);
    SetWebXREnabledFeaturesEnabled(enable);
    SetWebXRHandInputEnabled(enable);
    SetXMLParserMergeAdjacentCDataSectionsEnabled(enable);

    // Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
    SetBarcodeDetectorEnabled(enable);
    SetCompositedSelectionUpdateEnabled(enable);
    SetCompositionForegroundMarkersEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetImplicitRootScrollerEnabled(enable);
    SetIncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled(enable);
    SetMediaCaptureEnabled(enable);
    SetMediaControlsOverlayPlayButtonEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOrientationEventEnabled(enable);
    SetReduceUserAgentAndroidVersionDeviceModelEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetReportVisibleLineBoundsEnabled(enable);
    SetTextFragmentTapOpensContextMenuEnabled(enable);
    SetUseLowQualityInterpolationEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebNFCEnabled(enable);
#endif

#if BUILDFLAG(IS_WIN)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetPagePopupEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    SetAudioOutputDevicesEnabled(enable);
    SetBarcodeDetectorEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetForceTallerSelectPopupEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetPagePopupEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetUseBeginFramePresentationFeedbackEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
    SetAudioOutputDevicesEnabled(enable);
    SetBarcodeDetectorEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetForceTallerSelectPopupEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetPagePopupEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetUseBeginFramePresentationFeedbackEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_MAC)
    SetAudioOutputDevicesEnabled(enable);
    SetBarcodeDetectorEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetPagePopupEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_LINUX)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetPagePopupEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_IOS)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

    // Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureControllerEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetComputePressureEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetDocumentPictureInPicturePreferInitialPlacementEnabled(enable);
    SetDocumentPictureInPictureUserActivationEnabled(enable);
    SetElementCaptureEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetPagePopupEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetScheduleSelectionChangeOnBackspaceEnabled(enable);
    SetSerialEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebHIDEnabled(enable);
#endif
}

void RuntimeEnabledFeaturesBase::SetExperimentalFeaturesEnabled(bool enable)
{
    SetAccessibilityAriaVirtualContentEnabled(enable);
    SetAccessibilityOSLevelBoldTextEnabled(enable);
    SetAccessibilitySerializationSizeMetricsEnabled(enable);
    SetAddressSpaceEnabled(enable);
    SetAllowJavaScriptToResetAutofillStateEnabled(enable);
    SetAllowPreloadingWithCSPMetaTagEnabled(enable);
    SetAnimationProgressAPIEnabled(enable);
    SetAOMAriaRelationshipPropertiesEnabled(enable);
    SetAOMAriaRelationshipPropertiesAriaOwnsEnabled(enable);
    SetAppTitleEnabled(enable);
    SetAriaActionsEnabled(enable);
    SetAudioContextPlayoutStatsEnabled(enable);
    SetAudioVideoTracksEnabled(enable);
    SetAutoPictureInPictureVideoHeuristicsEnabled(enable);
    SetBackForwardCacheExperimentHTTPHeaderEnabled(enable);
    SetBlockingFocusWithoutUserActivationEnabled(enable);
    SetBoundaryEventDispatchTracksNodeRemovalEnabled(enable);
    SetCacheStorageCodeCacheHintEnabled(enable);
    SetCanvas2dCanvasFilterEnabled(enable);
    SetCanvas2dGPUTransferEnabled(enable);
    SetCanvas2dLayersWithOptionsEnabled(enable);
    SetCanvas2dTextMetricsShapingEnabled(enable);
    SetCanvasFloatingPointEnabled(enable);
    SetCanvasHDREnabled(enable);
    SetCanvasImageSmoothingEnabled(enable);
    SetCanvasPlaceElementEnabled(enable);
    SetCapabilityDelegationDisplayCaptureRequestEnabled(enable);
    SetClickToCapturedPointerEnabled(enable);
    SetClipboardItemWithDOMStringSupportEnabled(enable);
    SetCompositeBGColorAnimationEnabled(enable);
    SetComputedAccessibilityInfoEnabled(enable);
    SetContextMenuEnabled(enable);
    SetControlledFrameEnabled(enable);
    SetCrossFramePerformanceTimelineEnabled(enable);
    SetCSSAccentColorKeywordEnabled(enable);
    SetCSSColorContrastEnabled(enable);
    SetCSSColorTypedOMEnabled(enable);
    SetCSSCrossFadeEnabled(enable);
    SetCSSDynamicRangeLimitEnabled(enable);
    SetCSSInertEnabled(enable);
    SetCSSLayoutAPIEnabled(enable);
    SetCSSLazyParsingFastPathEnabled(enable);
    SetCSSLineClampEnabled(enable);
    SetCSSMarkerNestedPseudoElementEnabled(enable);
    SetCSSNestedPseudoElementsEnabled(enable);
    SetCSSOverflowContainerQueriesEnabled(enable);
    SetCSSPaintAPIArgumentsEnabled(enable);
    SetCSSProgressNotationEnabled(enable);
    SetCSSPseudoColumnEnabled(enable);
    SetCSSPseudoHasSlottedEnabled(enable);
    SetCSSPseudoOpenClosedEnabled(enable);
    SetCSSPseudoScrollButtonsEnabled(enable);
    SetCSSPseudoScrollMarkersEnabled(enable);
    SetCSSReadingFlowEnabled(enable);
    SetCSSScrollStartTargetEnabled(enable);
    SetCSSSelectorFragmentAnchorEnabled(enable);
    SetCSSSignRelatedFunctionsEnabled(enable);
    SetCSSSnapContainerQueriesEnabled(enable);
    SetCSSStickyContainerQueriesEnabled(enable);
    SetCSSSupportsAtRuleFunctionEnabled(enable);
    SetCSSSystemAccentColorEnabled(enable);
    SetCSSTextAutoSpaceEnabled(enable);
    SetCSSTextBoxTrimEnabled(enable);
    SetCSSVideoDynamicRangeMediaQueriesEnabled(enable);
    SetCSSViewTransitionAutoNameEnabled(enable);
    SetCustomizableSelectEnabled(enable);
    SetDatabaseEnabled(enable);
    SetDesktopCaptureDisableLocalEchoControlEnabled(enable);
    SetDeviceOrientationRequestPermissionEnabled(enable);
    SetDialogCloseWhenOpenRemovedEnabled(enable);
    SetDialogNewFocusBehaviorEnabled(enable);
    SetDisableHardwareNoiseSuppressionEnabled(enable);
    SetDisableThirdPartyStoragePartitioning2Enabled(enable);
    SetDisplayContentsFocusableEnabled(enable);
    SetDocumentIsolationPolicyEnabled(enable);
    SetDocumentOpenOriginAliasRemovalEnabled(enable);
    SetDocumentPolicyDocumentDomainEnabled(enable);
    SetDocumentPolicyExpectNoLinkedResourcesEnabled(enable);
    SetDocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(enable);
    SetDocumentPolicyNegotiationEnabled(enable);
    SetDocumentPolicySyncXHREnabled(enable);
    SetDOMPartsAPIEnabled(enable);
    SetEscapeLtGtInAttributesEnabled(enable);
    SetEventTimingInteractionCountEnabled(enable);
    SetEventTimingSelectionAutoScrollNoInteractionIdEnabled(enable);
    SetExperimentalContentSecurityPolicyFeaturesEnabled(enable);
    SetExperimentalJSProfilerMarkersEnabled(enable);
    SetExperimentalPoliciesEnabled(enable);
    SetExtendedTextMetricsEnabled(enable);
    SetFaceDetectorEnabled(enable);
    SetFetchLaterAPIEnabled(enable);
    SetFileSystemAccessAPIExperimentalEnabled(enable);
    SetFileSystemObserverEnabled(enable);
    SetFileSystemObserverUnobserveEnabled(enable);
    SetFindTextInReadonlyTextInputEnabled(enable);
    SetFocusgroupEnabled(enable);
    SetFontationsFontBackendEnabled(enable);
    SetFreezeFramesOnVisibilityEnabled(enable);
    SetGamepadMultitouchEnabled(enable);
    SetGetDisplayMediaRequiresUserActivationEnabled(enable);
    SetHighlightInheritanceEnabled(enable);
    SetHTMLAnchorAttributeEnabled(enable);
    SetHTMLDialogLightDismissEnabled(enable);
    SetHTMLInterestTargetAttributeEnabled(enable);
    SetHTMLInvokeActionsV2Enabled(enable);
    SetHTMLInvokeTargetAttributeEnabled(enable);
    SetHTMLPopoverHintEnabled(enable);
    SetIndexedDbGetAllRecordsEnabled(enable);
    SetInnerHTMLParserFastpathLogFailureEnabled(enable);
    SetInteroperablePrivateAttributionEnabled(enable);
    SetInvertedColorsEnabled(enable);
    SetJavaScriptCompileHintsMagicAlwaysRuntimeEnabled(enable);
    SetJavaScriptCompileHintsMagicRuntimeEnabled(enable);
    SetKeyboardAccessibleTooltipEnabled(enable);
    SetLanguageDetectionAPIEnabled(enable);
    SetLayoutStretchEnabled(enable);
    SetLimitThirdPartyCookiesEnabled(enable);
    SetMediaCapabilitiesEncodingInfoEnabled(enable);
    SetMediaCaptureBackgroundBlurEnabled(enable);
    SetMediaCaptureCameraControlsEnabled(enable);
    SetMediaCaptureConfigurationChangeEnabled(enable);
    SetMediaCaptureVoiceIsolationEnabled(enable);
    SetMediaSourceExperimentalEnabled(enable);
    SetMediaSourceExtensionsForWebCodecsEnabled(enable);
    SetMediaSourceNewAbortAndDurationEnabled(enable);
    SetMultipleImportMapsEnabled(enable);
    SetNavigateEventCommitBehaviorEnabled(enable);
    SetNavigateEventSourceElementEnabled(enable);
    SetNavigationIdEnabled(enable);
    SetNestedViewTransitionEnabled(enable);
    SetNotificationTriggersEnabled(enable);
    SetObservableAPIEnabled(enable);
    SetOffscreenCanvasCommitEnabled(enable);
    SetOriginPolicyEnabled(enable);
    SetOverscrollCustomizationEnabled(enable);
    SetPartitionedPopinsEnabled(enable);
    SetPaymentAppEnabled(enable);
    SetPaymentLinkDetectionEnabled(enable);
    SetPaymentRequestEnabled(enable);
    SetPerformanceMarkFeatureUsageEnabled(enable);
    SetPerformanceNavigateSystemEntropyEnabled(enable);
    SetPerformanceNavigationTimingConfidenceEnabled(enable);
    SetPerMethodCanMakePaymentQuotaEnabled(enable);
    SetPermissionsRequestRevokeEnabled(enable);
    SetPopoverAnchorRelationshipsEnabled(enable);
    SetPrefersReducedDataEnabled(enable);
    SetPrivateNetworkAccessNonSecureContextsAllowedEnabled(enable);
    SetPrivateNetworkAccessNullIpAddressEnabled(enable);
    SetPseudoElementsFocusableEnabled(enable);
    SetPushMessagingSubscriptionChangeEnabled(enable);
    SetResourceTimingContentTypeEnabled(enable);
    SetResourceTimingFinalResponseHeadersStartEnabled(enable);
    SetRestrictGamepadAccessEnabled(enable);
    SetRtcAudioJitterBufferMaxPacketsEnabled(enable);
    SetRTCDataChannelPriorityEnabled(enable);
    SetRTCEncodedAudioFrameAbsCaptureTimeEnabled(enable);
    SetRTCEncodedFrameSetMetadataEnabled(enable);
    SetRTCEncodedVideoFrameAdditionalMetadataEnabled(enable);
    SetRTCLegacyCallbackBasedGetStatsEnabled(enable);
    SetRTCRtpScriptTransformEnabled(enable);
    SetRTCStatsRelativePacketArrivalDelayEnabled(enable);
    SetScopedCustomElementRegistryEnabled(enable);
    SetScrollTimelineCurrentTimeEnabled(enable);
    SetSecurePaymentConfirmationNetworkAndIssuerIconsEnabled(enable);
    SetSelectedcontentelementAttributeEnabled(enable);
    SetSelectionAcrossShadowDOMEnabled(enable);
    SetSelectionOnShadowDOMWithDelegatesFocusEnabled(enable);
    SetSelectParserRelaxationEnabled(enable);
    SetSensorExtraClassesEnabled(enable);
    SetServiceWorkerClientLifecycleStateEnabled(enable);
    SetSetSequentialFocusStartingPointEnabled(enable);
    SetShadowRootReferenceTargetEnabled(enable);
    SetSignatureBasedIntegrityEnabled(enable);
    SetSiteInitiatedMirroringEnabled(enable);
    SetSoftNavigationHeuristicsEnabled(enable);
    SetSpeakerSelectionEnabled(enable);
    SetStorageAccessHeaderEnabled(enable);
    SetStorageBucketsDurabilityEnabled(enable);
    SetStorageBucketsLocksEnabled(enable);
    SetStrictMimeTypesForWorkersEnabled(enable);
    SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled(enable);
    SetSystemWakeLockEnabled(enable);
    SetTextDetectorEnabled(enable);
    SetTextFragmentAPIEnabled(enable);
    SetTextSizeAdjustImprovementsEnabled(enable);
    SetTimestampBasedCLSTrackingEnabled(enable);
    SetTimeZoneChangeEventEnabled(enable);
    SetTopLevelTpcdEnabled(enable);
    SetTpcdEnabled(enable);
    SetTrustedTypeBeforePolicyCreationEventEnabled(enable);
    SetTrustedTypesFromLiteralEnabled(enable);
    SetTrustedTypesUseCodeLikeEnabled(enable);
    SetUnclosedFormControlIsInvalidEnabled(enable);
    SetURLPatternCompareComponentEnabled(enable);
    SetVideoFrameMetadataBackgroundBlurEnabled(enable);
    SetViewportSegmentsEnabled(enable);
    SetWebAnimationsSVGEnabled(enable);
    SetWebAppInstallationEnabled(enable);
    SetWebAppScopeExtensionsEnabled(enable);
    SetWebAppTranslationsEnabled(enable);
    SetWebAppUrlHandlingEnabled(enable);
    SetWebAssemblyJSPromiseIntegrationEnabled(enable);
    SetWebAuthenticationAmbientEnabled(enable);
    SetWebAuthenticationAttestationFormatsEnabled(enable);
    SetWebAuthenticationClientCapabilitiesEnabled(enable);
    SetWebAuthenticationSupplementalPubKeysEnabled(enable);
    SetWebBluetoothGetDevicesEnabled(enable);
    SetWebBluetoothScanningEnabled(enable);
    SetWebBluetoothWatchAdvertisementsEnabled(enable);
    SetWebCodecsOrientationEnabled(enable);
    SetWebCodecsVideoEncoderBuffersEnabled(enable);
    SetWebCryptoCurve25519Enabled(enable);
    SetWebFontResizeLCPEnabled(enable);
    SetWebGLDeveloperExtensionsEnabled(enable);
    SetWebGPUExperimentalFeaturesEnabled(enable);
    SetWebGPUSubgroupsFeaturesEnabled(enable);
    SetWebIdentityDigitalCredentialsEnabled(enable);
    SetWebPreferencesEnabled(enable);
    SetWebTransportStatsEnabled(enable);
    SetWebViewXRequestedWithDeprecationEnabled(enable);
    SetWebVTTRegionsEnabled(enable);
    SetWebXRFrameRateEnabled(enable);
    SetWebXRFrontFacingEnabled(enable);
    SetWebXRGPUBindingEnabled(enable);
    SetWebXRHitTestEntityTypesEnabled(enable);
    SetWebXRImageTrackingEnabled(enable);
    SetWebXRLayersEnabled(enable);
    SetWebXRLayersCommonEnabled(enable);
    SetWebXRPlaneDetectionEnabled(enable);
    SetWebXRPoseMotionDataEnabled(enable);
    SetWebXRSpecParityEnabled(enable);

    // Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
    SetDeviceAttributesEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
#endif

#if BUILDFLAG(IS_WIN)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetFileSystemAccessGetCloudIdentifiersEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetFileSystemAccessGetCloudIdentifiersEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
#endif

#if BUILDFLAG(IS_MAC)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
#endif

#if BUILDFLAG(IS_LINUX)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
    SetWebBluetoothEnabled(enable);
#endif

#if BUILDFLAG(IS_IOS)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
    SetWebBluetoothEnabled(enable);
#endif

    // Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
    SetCapturedSurfaceControlEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetSerialPortConnectedEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTabStripCustomizationsEnabled(enable);
    SetWebBluetoothEnabled(enable);
#endif
}

void RuntimeEnabledFeaturesBase::SetTestFeaturesEnabled(bool enable)
{
    SetAccessibilityExposeDisplayNoneEnabled(enable);
    SetAdTaggingEnabled(enable);
    SetAIPromptAPIEnabled(enable);
    SetAIPromptAPIForExtensionEnabled(enable);
    SetAIPromptAPIForWebPlatformEnabled(enable);
    SetAIRewriterAPIEnabled(enable);
    SetAISummarizationAPIEnabled(enable);
    SetAIWriterAPIEnabled(enable);
    SetAriaNotifyEnabled(enable);
    SetAtomicMoveAPIEnabled(enable);
    SetAudioContextInterruptedStateEnabled(enable);
    SetAuraScrollbarUsesNinePatchTrackEnabled(enable);
    SetBuiltInAIAPIEnabled(enable);
    SetCanvas2dMeshEnabled(enable);
    SetCoepReflectionEnabled(enable);
    SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled(enable);
    SetCSSCaretAnimationEnabled(enable);
    SetCSSCaseSensitiveSelectorEnabled(enable);
    SetCSSEnumeratedCustomPropertiesEnabled(enable);
    SetCSSFunctionsEnabled(enable);
    SetCSSLogicalOverflowEnabled(enable);
    SetCSSMasonryLayoutEnabled(enable);
    SetCSSPositionStickyStaticScrollPositionEnabled(enable);
    SetCSSPseudoPlayingPausedEnabled(enable);
    SetCSSScrollStartEnabled(enable);
    SetCSSUserSelectContainEnabled(enable);
    SetDesktopPWAsAdditionalWindowingControlsEnabled(enable);
    SetDesktopPWAsSubAppsEnabled(enable);
    SetExposeCoarsenedRenderTimeEnabled(enable);
    SetFedCmIdPRegistrationEnabled(enable);
    SetFledgeAuctionDealSupportEnabled(enable);
    SetFledgeSellerNonceEnabled(enable);
    SetFledgeTrustedSignalsKVv2SupportEnabled(enable);
    SetGetAllScreensMediaEnabled(enable);
    SetGroupEffectEnabled(enable);
    SetHTMLPopoverActionHoverEnabled(enable);
    SetLayoutFlexNewRowAlgorithmV3Enabled(enable);
    SetLayoutNGShapeCacheEnabled(enable);
    SetLCPAnimatedImagesWebExposedEnabled(enable);
    SetLockedModeEnabled(enable);
    SetLongTaskFromLongAnimationFrameEnabled(enable);
    SetMediaCapabilitiesSpatialAudioEnabled(enable);
    SetMediaLatencyHintEnabled(enable);
    SetMediaPlaybackWhileNotVisiblePermissionPolicyEnabled(enable);
    SetMediaStreamTrackTransferEnabled(enable);
    SetMessagePortCloseEventEnabled(enable);
    SetMiddleClickAutoscrollEnabled(enable);
    SetMojoJSEnabled(enable);
    SetMojoJSTestEnabled(enable);
    SetMultiSelectDeselectWhenOnlyOptionEnabled(enable);
    SetNoIdleEncodingForWebTestsEnabled(enable);
    SetOmitBlurEventOnElementRemovalEnabled(enable);
    SetPrefixedVideoFullscreenEnabled(enable);
    SetPrivateStateTokensAlwaysAllowIssuanceEnabled(enable);
    SetRasterInducingScrollEnabled(enable);
    SetRemoveVisibleSelectionInDOMSelectionEnabled(enable);
    SetResourceTimingUseCORSForBodySizesEnabled(enable);
    SetRTCRtpTransportEnabled(enable);
    SetSanitizerAPIEnabled(enable);
    SetSearchTextHighlightPseudoEnabled(enable);
    SetSecurePaymentConfirmationEnabled(enable);
    SetSharedAutofillEnabled(enable);
    SetTranslationAPIEnabled(enable);
    SetTranslationAPIEntryPointEnabled(enable);
    SetVideoTrackGeneratorEnabled(enable);
    SetVideoTrackGeneratorInWindowEnabled(enable);
    SetViewTransitionLongCallbackTimeoutForTestingEnabled(enable);
    SetWebAuthAuthenticatorAttachmentEnabled(enable);
    SetWebShareEnabled(enable);

    // Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
    SetFileHandlingEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetInsertLineBreakIfPhrasingContentEnabled(enable);
    SetSmartZoomEnabled(enable);
#endif

#if BUILDFLAG(IS_WIN)
    SetBarcodeDetectorEnabled(enable);
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif

#if BUILDFLAG(IS_MAC)
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif

#if BUILDFLAG(IS_LINUX)
    SetBarcodeDetectorEnabled(enable);
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif

#if BUILDFLAG(IS_IOS)
    SetBarcodeDetectorEnabled(enable);
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif

    // Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
    SetBarcodeDetectorEnabled(enable);
    SetCapturedMouseEventsEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetSelectAudioOutputEnabled(enable);
    SetSmartCardEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebPrintingEnabled(enable);
#endif
}

void RuntimeEnabledFeaturesBase::SetOriginTrialControlledFeaturesEnabled(bool enable)
{
    SetAdInterestGroupAPIEnabled(enable);
    SetAIPromptAPIForExtensionEnabled(enable);
    SetAISummarizationAPIEnabled(enable);
    SetAppTitleEnabled(enable);
    SetAttributionReportingInterfaceEnabled(enable);
    SetAudioContextPlayoutStatsEnabled(enable);
    SetAutoDarkModeEnabled(enable);
    SetBackForwardCacheExperimentHTTPHeaderEnabled(enable);
    SetBackForwardCacheNotRestoredReasonsEnabled(enable);
    SetBuiltInAIAPIEnabled(enable);
    SetCacheStorageCodeCacheHintEnabled(enable);
    SetCanvas2dMeshEnabled(enable);
    SetCapturedSurfaceControlEnabled(enable);
    SetCoopRestrictPropertiesEnabled(enable);
    SetDatabaseEnabled(enable);
    SetDeprecateUnloadOptOutEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDisableDifferentOriginSubframeDialogSuppressionEnabled(enable);
    SetDisableHardwareNoiseSuppressionEnabled(enable);
    SetDisableReduceAcceptLanguageEnabled(enable);
    SetDisableThirdPartyStoragePartitioning2Enabled(enable);
    SetDocumentIsolationPolicyEnabled(enable);
    SetDocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(enable);
    SetDocumentPolicyNegotiationEnabled(enable);
    SetFedCmAuthzEnabled(enable);
    SetFedCmButtonModeEnabled(enable);
    SetFedCmMultipleIdentityProvidersEnabled(enable);
    SetFedCmWithStorageAccessAPIEnabled(enable);
    SetFetchLaterAPIEnabled(enable);
    SetFileSystemObserverEnabled(enable);
    SetFledgeBiddingAndAuctionServerAPIEnabled(enable);
    SetFocusgroupEnabled(enable);
    SetGetAllScreensMediaEnabled(enable);
    SetHrefTranslateEnabled(enable);
    SetJavaScriptCompileHintsMagicAlwaysRuntimeEnabled(enable);
    SetJavaScriptCompileHintsMagicRuntimeEnabled(enable);
    SetKeyboardFocusableScrollersOptOutEnabled(enable);
    SetLanguageDetectionAPIEnabled(enable);
    SetLimitThirdPartyCookiesEnabled(enable);
    SetMediaCaptureBackgroundBlurEnabled(enable);
    SetMediaCaptureConfigurationChangeEnabled(enable);
    SetMediaPreviewsOptOutEnabled(enable);
    SetMediaSourceExtensionsForWebCodecsEnabled(enable);
    SetMutationEventsEnabled(enable);
    SetNavigationIdEnabled(enable);
    SetNotificationTriggersEnabled(enable);
    SetOriginTrialsSampleAPIEnabled(enable);
    SetOriginTrialsSampleAPIBrowserReadWriteEnabled(enable);
    SetOriginTrialsSampleAPIDependentEnabled(enable);
    SetOriginTrialsSampleAPIDeprecationEnabled(enable);
    SetOriginTrialsSampleAPIExpiryGracePeriodEnabled(enable);
    SetOriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(enable);
    SetOriginTrialsSampleAPIImpliedEnabled(enable);
    SetOriginTrialsSampleAPIInvalidOSEnabled(enable);
    SetOriginTrialsSampleAPINavigationEnabled(enable);
    SetOriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(enable);
    SetOriginTrialsSampleAPIPersistentFeatureEnabled(enable);
    SetOriginTrialsSampleAPIPersistentInvalidOSEnabled(enable);
    SetOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(enable);
    SetOriginTrialsSampleAPIThirdPartyEnabled(enable);
    SetPageFreezeOptInEnabled(enable);
    SetPageFreezeOptOutEnabled(enable);
    SetParakeetEnabled(enable);
    SetPerMethodCanMakePaymentQuotaEnabled(enable);
    SetPermissionElementEnabled(enable);
    SetPNaClEnabled(enable);
    SetPrefixedVideoFullscreenEnabled(enable);
    SetPrivateNetworkAccessNonSecureContextsAllowedEnabled(enable);
    SetPrivateNetworkAccessPermissionPromptEnabled(enable);
    SetPrivateStateTokensEnabled(enable);
    SetProtectedOriginTrialsSampleAPIEnabled(enable);
    SetProtectedOriginTrialsSampleAPIDependentEnabled(enable);
    SetProtectedOriginTrialsSampleAPIImpliedEnabled(enable);
    SetReduceAcceptLanguageEnabled(enable);
    SetRtcAudioJitterBufferMaxPacketsEnabled(enable);
    SetRTCEncodedFrameSetMetadataEnabled(enable);
    SetRTCLegacyCallbackBasedGetStatsEnabled(enable);
    SetRTCStatsRelativePacketArrivalDelayEnabled(enable);
    SetSecurePaymentConfirmationOptOutEnabled(enable);
    SetServiceWorkerStaticRouterEnabled(enable);
    SetServiceWorkerStaticRouterTimingInfoEnabled(enable);
    SetSignatureBasedIntegrityEnabled(enable);
    SetSkipPreloadScanningEnabled(enable);
    SetSoftNavigationHeuristicsEnabled(enable);
    SetSpeculationRulesPrefetchFutureEnabled(enable);
    SetStandardizedBrowserZoomOptOutEnabled(enable);
    SetStorageAccessHeaderEnabled(enable);
    SetTextFragmentIdentifiersEnabled(enable);
    SetTopLevelTpcdEnabled(enable);
    SetTouchEventFeatureDetectionEnabled(enable);
    SetTpcdEnabled(enable);
    SetTranslationAPIEnabled(enable);
    SetTranslationAPIEntryPointEnabled(enable);
    SetUnrestrictedSharedArrayBufferEnabled(enable);
    SetViewportSegmentsEnabled(enable);
    SetWebAppLaunchQueueEnabled(enable);
    SetWebAppScopeExtensionsEnabled(enable);
    SetWebAppUrlHandlingEnabled(enable);
    SetWebAssemblyJSPromiseIntegrationEnabled(enable);
    SetWebAssemblyJSStringBuiltinsEnabled(enable);
    SetWebAuthenticationAttestationFormatsEnabled(enable);
    SetWebGPUSubgroupsFeaturesEnabled(enable);
    SetWebIdentityDigitalCredentialsEnabled(enable);
    SetWebTransportCustomCertificatesEnabled(enable);
    SetWebViewXRequestedWithDeprecationEnabled(enable);
    SetWebXRImageTrackingEnabled(enable);
    SetWebXRPlaneDetectionEnabled(enable);
}

void RuntimeEnabledFeaturesBase::SetFeatureEnabledFromString(const std::string& name, bool enable)
{
    static const struct {
        const char* name;
        void (*SetFunction)(bool);
    } kFeatures[] = {
        { "AIPromptAPI", SetAIPromptAPIEnabled },
        { "AIPromptAPIForExtension", SetAIPromptAPIForExtensionEnabled },
        { "AIPromptAPIForWebPlatform", SetAIPromptAPIForWebPlatformEnabled },
        { "AIRewriterAPI", SetAIRewriterAPIEnabled },
        { "AISummarizationAPI", SetAISummarizationAPIEnabled },
        { "AIWriterAPI", SetAIWriterAPIEnabled },
        { "AOMAriaRelationshipProperties", SetAOMAriaRelationshipPropertiesEnabled },
        { "AOMAriaRelationshipPropertiesAriaOwns", SetAOMAriaRelationshipPropertiesAriaOwnsEnabled },
        { "Accelerated2dCanvas", SetAccelerated2dCanvasEnabled },
        { "AcceleratedSmallCanvases", SetAcceleratedSmallCanvasesEnabled },
        { "AccessibilityAriaVirtualContent", SetAccessibilityAriaVirtualContentEnabled },
        { "AccessibilityExposeDisplayNone", SetAccessibilityExposeDisplayNoneEnabled },
        { "AccessibilityMinRoleTabbable", SetAccessibilityMinRoleTabbableEnabled },
        { "AccessibilityOSLevelBoldText", SetAccessibilityOSLevelBoldTextEnabled },
        { "AccessibilityProhibitedNames", SetAccessibilityProhibitedNamesEnabled },
        { "AccessibilitySerializationSizeMetrics", SetAccessibilitySerializationSizeMetricsEnabled },
        { "AccessibilityUseAXPositionForDocumentMarkers", SetAccessibilityUseAXPositionForDocumentMarkersEnabled },
        { "AdInterestGroupAPI", SetAdInterestGroupAPIEnabled },
        { "AdTagging", SetAdTaggingEnabled },
        { "AddressSpace", SetAddressSpaceEnabled },
        { "AdjustEndOfNextParagraphIfMovedParagraphIsUpdated", SetAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled },
        { "AllowContentInitiatedDataUrlNavigations", SetAllowContentInitiatedDataUrlNavigationsEnabled },
        { "AllowJavaScriptToResetAutofillState", SetAllowJavaScriptToResetAutofillStateEnabled },
        { "AllowPreloadingWithCSPMetaTag", SetAllowPreloadingWithCSPMetaTagEnabled },
        { "AllowURNsInIframes", SetAllowURNsInIframesEnabled },
        { "AndroidDownloadableFontsMatching", SetAndroidDownloadableFontsMatchingEnabled },
        { "AnimationProgressAPI", SetAnimationProgressAPIEnabled },
        { "AnimationWorklet", SetAnimationWorkletEnabled },
        { "AnonymousIframe", SetAnonymousIframeEnabled },
        { "AppTitle", SetAppTitleEnabled },
        { "AriaActions", SetAriaActionsEnabled },
        { "AriaNotify", SetAriaNotifyEnabled },
        { "AriaRowColIndexText", SetAriaRowColIndexTextEnabled },
        { "AtomicMoveAPI", SetAtomicMoveAPIEnabled },
        { "AttributionReporting", SetAttributionReportingEnabled },
        { "AttributionReportingCrossAppWeb", SetAttributionReportingCrossAppWebEnabled },
        { "AttributionReportingInterface", SetAttributionReportingInterfaceEnabled },
        { "AudioContextInterruptedState", SetAudioContextInterruptedStateEnabled },
        { "AudioContextOnError", SetAudioContextOnErrorEnabled },
        { "AudioContextPlayoutStats", SetAudioContextPlayoutStatsEnabled },
        { "AudioContextSetSinkId", SetAudioContextSetSinkIdEnabled },
        { "AudioOutputDevices", SetAudioOutputDevicesEnabled },
        { "AudioVideoTracks", SetAudioVideoTracksEnabled },
        { "AuraScrollbarUsesNinePatchTrack", SetAuraScrollbarUsesNinePatchTrackEnabled },
        { "AuraScrollbarUsesSolidColorThumb", SetAuraScrollbarUsesSolidColorThumbEnabled },
        { "AutoDarkMode", SetAutoDarkModeEnabled },
        { "AutoPictureInPictureVideoHeuristics", SetAutoPictureInPictureVideoHeuristicsEnabled },
        { "AutomationControlled", SetAutomationControlledEnabled },
        { "BackForwardCache", SetBackForwardCacheEnabled },
        { "BackForwardCacheExperimentHTTPHeader", SetBackForwardCacheExperimentHTTPHeaderEnabled },
        { "BackForwardCacheNotRestoredReasons", SetBackForwardCacheNotRestoredReasonsEnabled },
        { "BackForwardTransitions", SetBackForwardTransitionsEnabled },
        { "BackfaceVisibilityInterop", SetBackfaceVisibilityInteropEnabled },
        { "BackgroundFetch", SetBackgroundFetchEnabled },
        { "BarcodeDetector", SetBarcodeDetectorEnabled },
        { "BidiCaretAffinity", SetBidiCaretAffinityEnabled },
        { "BlinkExtensionChromeOS", SetBlinkExtensionChromeOSEnabled },
        { "BlinkExtensionChromeOSKiosk", SetBlinkExtensionChromeOSKioskEnabled },
        { "BlinkExtensionDiagnostics", SetBlinkExtensionDiagnosticsEnabled },
        { "BlinkExtensionWebView", SetBlinkExtensionWebViewEnabled },
        { "BlinkExtensionWebViewMediaIntegrity", SetBlinkExtensionWebViewMediaIntegrityEnabled },
        { "BlinkLifecycleScriptForbidden", SetBlinkLifecycleScriptForbiddenEnabled },
        { "BlinkRuntimeCallStats", SetBlinkRuntimeCallStatsEnabled },
        { "BlockingFocusWithoutUserActivation", SetBlockingFocusWithoutUserActivationEnabled },
        { "BoundaryEventDispatchTracksNodeRemoval", SetBoundaryEventDispatchTracksNodeRemovalEnabled },
        { "BoxDecorationBreak", SetBoxDecorationBreakEnabled },
        { "BreakIteratorHyphenMinus", SetBreakIteratorHyphenMinusEnabled },
        { "BrowserVerifiedUserActivationKeyboard", SetBrowserVerifiedUserActivationKeyboardEnabled },
        { "BrowserVerifiedUserActivationMouse", SetBrowserVerifiedUserActivationMouseEnabled },
        { "BufferedBytesConsumerLimitSize", SetBufferedBytesConsumerLimitSizeEnabled },
        { "BuiltInAIAPI", SetBuiltInAIAPIEnabled },
        { "BypassPepcSecurityForTesting", SetBypassPepcSecurityForTestingEnabled },
        { "CCTNewRFMPushBehavior", SetCCTNewRFMPushBehaviorEnabled },
        { "CSSAccentColorKeyword", SetCSSAccentColorKeywordEnabled },
        { "CSSAdvancedAttrFunction", SetCSSAdvancedAttrFunctionEnabled },
        { "CSSAnchorScope", SetCSSAnchorScopeEnabled },
        { "CSSAnchorSizeInsetsMargins", SetCSSAnchorSizeInsetsMarginsEnabled },
        { "CSSAtPropertyStringSyntax", SetCSSAtPropertyStringSyntaxEnabled },
        { "CSSAtRuleCounterStyleImageSymbols", SetCSSAtRuleCounterStyleImageSymbolsEnabled },
        { "CSSAtRuleCounterStyleSpeakAsDescriptor", SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled },
        { "CSSBackgroundClipUnprefix", SetCSSBackgroundClipUnprefixEnabled },
        { "CSSCalcSimplificationAndSerialization", SetCSSCalcSimplificationAndSerializationEnabled },
        { "CSSCalcSizeFunction", SetCSSCalcSizeFunctionEnabled },
        { "CSSCaretAnimation", SetCSSCaretAnimationEnabled },
        { "CSSCascadeCorrectScope", SetCSSCascadeCorrectScopeEnabled },
        { "CSSCaseSensitiveSelector", SetCSSCaseSensitiveSelectorEnabled },
        { "CSSColorContrast", SetCSSColorContrastEnabled },
        { "CSSColorTypedOM", SetCSSColorTypedOMEnabled },
        { "CSSComputedStyleFullPseudoElementParser", SetCSSComputedStyleFullPseudoElementParserEnabled },
        { "CSSContentVisibilityImpliesContainIntrinsicSizeAuto", SetCSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled },
        { "CSSCrossFade", SetCSSCrossFadeEnabled },
        { "CSSCustomStateDeprecatedSyntax", SetCSSCustomStateDeprecatedSyntaxEnabled },
        { "CSSCustomStateNewSyntax", SetCSSCustomStateNewSyntaxEnabled },
        { "CSSDynamicRangeLimit", SetCSSDynamicRangeLimitEnabled },
        { "CSSEnumeratedCustomProperties", SetCSSEnumeratedCustomPropertiesEnabled },
        { "CSSExponentialFunctions", SetCSSExponentialFunctionsEnabled },
        { "CSSFlatTreeContainer", SetCSSFlatTreeContainerEnabled },
        { "CSSFontSizeAdjust", SetCSSFontSizeAdjustEnabled },
        { "CSSFunctions", SetCSSFunctionsEnabled },
        { "CSSGapDecoration", SetCSSGapDecorationEnabled },
        { "CSSHexAlphaColor", SetCSSHexAlphaColorEnabled },
        { "CSSInert", SetCSSInertEnabled },
        { "CSSInsetAreaProperty", SetCSSInsetAreaPropertyEnabled },
        { "CSSKeyframesRuleLength", SetCSSKeyframesRuleLengthEnabled },
        { "CSSLayoutAPI", SetCSSLayoutAPIEnabled },
        { "CSSLazyParsingFastPath", SetCSSLazyParsingFastPathEnabled },
        { "CSSLineClamp", SetCSSLineClampEnabled },
        { "CSSLineClampWebkitBoxBlockification", SetCSSLineClampWebkitBoxBlockificationEnabled },
        { "CSSLogicalOverflow", SetCSSLogicalOverflowEnabled },
        { "CSSMarkerNestedPseudoElement", SetCSSMarkerNestedPseudoElementEnabled },
        { "CSSMasonryLayout", SetCSSMasonryLayoutEnabled },
        { "CSSMixins", SetCSSMixinsEnabled },
        { "CSSNestedDeclarations", SetCSSNestedDeclarationsEnabled },
        { "CSSNestedPseudoElements", SetCSSNestedPseudoElementsEnabled },
        { "CSSOverflowContainerQueries", SetCSSOverflowContainerQueriesEnabled },
        { "CSSPaintAPIArguments", SetCSSPaintAPIArgumentsEnabled },
        { "CSSParserIgnoreCharsetForURLs", SetCSSParserIgnoreCharsetForURLsEnabled },
        { "CSSPartAllowsMoreSelectorsAfter", SetCSSPartAllowsMoreSelectorsAfterEnabled },
        { "CSSPositionAreaValue", SetCSSPositionAreaValueEnabled },
        { "CSSPositionStickyStaticScrollPosition", SetCSSPositionStickyStaticScrollPositionEnabled },
        { "CSSProgressNotation", SetCSSProgressNotationEnabled },
        { "CSSPseudoColumn", SetCSSPseudoColumnEnabled },
        { "CSSPseudoHasSlotted", SetCSSPseudoHasSlottedEnabled },
        { "CSSPseudoOpenClosed", SetCSSPseudoOpenClosedEnabled },
        { "CSSPseudoPlayingPaused", SetCSSPseudoPlayingPausedEnabled },
        { "CSSPseudoScrollButtons", SetCSSPseudoScrollButtonsEnabled },
        { "CSSPseudoScrollMarkers", SetCSSPseudoScrollMarkersEnabled },
        { "CSSReadingFlow", SetCSSReadingFlowEnabled },
        { "CSSRelativeColor", SetCSSRelativeColorEnabled },
        { "CSSRelativeColorLateResolveAlways", SetCSSRelativeColorLateResolveAlwaysEnabled },
        { "CSSRelativeColorPreserveNone", SetCSSRelativeColorPreserveNoneEnabled },
        { "CSSRelativeColorSupportsCurrentcolor", SetCSSRelativeColorSupportsCurrentcolorEnabled },
        { "CSSResizeAuto", SetCSSResizeAutoEnabled },
        { "CSSScrollSnapChangeEvent", SetCSSScrollSnapChangeEventEnabled },
        { "CSSScrollSnapChangingEvent", SetCSSScrollSnapChangingEventEnabled },
        { "CSSScrollSnapEvents", SetCSSScrollSnapEventsEnabled },
        { "CSSScrollStart", SetCSSScrollStartEnabled },
        { "CSSScrollStartTarget", SetCSSScrollStartTargetEnabled },
        { "CSSScrollStateContainerQueries", SetCSSScrollStateContainerQueriesEnabled },
        { "CSSSelectorFragmentAnchor", SetCSSSelectorFragmentAnchorEnabled },
        { "CSSSignRelatedFunctions", SetCSSSignRelatedFunctionsEnabled },
        { "CSSSnapContainerQueries", SetCSSSnapContainerQueriesEnabled },
        { "CSSSteppedValueFunctions", SetCSSSteppedValueFunctionsEnabled },
        { "CSSStickyContainerQueries", SetCSSStickyContainerQueriesEnabled },
        { "CSSSupportsAtRuleFunction", SetCSSSupportsAtRuleFunctionEnabled },
        { "CSSSupportsForImportRules", SetCSSSupportsForImportRulesEnabled },
        { "CSSSystemAccentColor", SetCSSSystemAccentColorEnabled },
        { "CSSTextAutoSpace", SetCSSTextAutoSpaceEnabled },
        { "CSSTextBoxTrim", SetCSSTextBoxTrimEnabled },
        { "CSSTextSpacing", SetCSSTextSpacingEnabled },
        { "CSSTreeScopedTimelines", SetCSSTreeScopedTimelinesEnabled },
        { "CSSUserSelectContain", SetCSSUserSelectContainEnabled },
        { "CSSVideoDynamicRangeMediaQueries", SetCSSVideoDynamicRangeMediaQueriesEnabled },
        { "CSSViewTransitionAutoName", SetCSSViewTransitionAutoNameEnabled },
        { "CSSViewTransitionClass", SetCSSViewTransitionClassEnabled },
        { "CacheStorageCodeCacheHint", SetCacheStorageCodeCacheHintEnabled },
        { "CalendarPickerMonthPopupButtonDisabledColor", SetCalendarPickerMonthPopupButtonDisabledColorEnabled },
        { "CallExitNodeWithoutLayoutObject", SetCallExitNodeWithoutLayoutObjectEnabled },
        { "Canvas2dCanvasFilter", SetCanvas2dCanvasFilterEnabled },
        { "Canvas2dGPUTransfer", SetCanvas2dGPUTransferEnabled },
        { "Canvas2dImageChromium", SetCanvas2dImageChromiumEnabled },
        { "Canvas2dLayers", SetCanvas2dLayersEnabled },
        { "Canvas2dLayersWithOptions", SetCanvas2dLayersWithOptionsEnabled },
        { "Canvas2dMesh", SetCanvas2dMeshEnabled },
        { "Canvas2dTextMetricsShaping", SetCanvas2dTextMetricsShapingEnabled },
        { "CanvasFloatingPoint", SetCanvasFloatingPointEnabled },
        { "CanvasHDR", SetCanvasHDREnabled },
        { "CanvasImageSmoothing", SetCanvasImageSmoothingEnabled },
        { "CanvasPlaceElement", SetCanvasPlaceElementEnabled },
        { "CanvasUsesArcPaintOp", SetCanvasUsesArcPaintOpEnabled },
        { "CapabilityDelegationDisplayCaptureRequest", SetCapabilityDelegationDisplayCaptureRequestEnabled },
        { "CaptureController", SetCaptureControllerEnabled },
        { "CaptureHandle", SetCaptureHandleEnabled },
        { "CapturedMouseEvents", SetCapturedMouseEventsEnabled },
        { "CapturedSurfaceControl", SetCapturedSurfaceControlEnabled },
        { "CaretPositionFromPoint", SetCaretPositionFromPointEnabled },
        { "CheckIfHighestRootContainsPositionAnchorNode", SetCheckIfHighestRootContainsPositionAnchorNodeEnabled },
        { "CheckVisibilityExtraProperties", SetCheckVisibilityExtraPropertiesEnabled },
        { "ClickToCapturedPointer", SetClickToCapturedPointerEnabled },
        { "ClipPathRejectEmptyPaths", SetClipPathRejectEmptyPathsEnabled },
        { "ClipboardItemWithDOMStringSupport", SetClipboardItemWithDOMStringSupportEnabled },
        { "CoalesceSelectionchangeEvent", SetCoalesceSelectionchangeEventEnabled },
        { "CoepReflection", SetCoepReflectionEnabled },
        { "CompositeBGColorAnimation", SetCompositeBGColorAnimationEnabled },
        { "CompositeBoxShadowAnimation", SetCompositeBoxShadowAnimationEnabled },
        { "CompositeClipPathAnimation", SetCompositeClipPathAnimationEnabled },
        { "CompositedAnimationsCancelledAsynchronously", SetCompositedAnimationsCancelledAsynchronouslyEnabled },
        { "CompositedSelectionUpdate", SetCompositedSelectionUpdateEnabled },
        { "CompositionForegroundMarkers", SetCompositionForegroundMarkersEnabled },
        { "CompressionDictionaryTransport", SetCompressionDictionaryTransportEnabled },
        { "CompressionDictionaryTransportBackend", SetCompressionDictionaryTransportBackendEnabled },
        { "ComputePressure", SetComputePressureEnabled },
        { "ComputedAccessibilityInfo", SetComputedAccessibilityInfoEnabled },
        { "ConcurrentViewTransitionsSPA", SetConcurrentViewTransitionsSPAEnabled },
        { "ContactsManager", SetContactsManagerEnabled },
        { "ContactsManagerExtraProperties", SetContactsManagerExtraPropertiesEnabled },
        { "ContainerTypeNoLayoutContainment", SetContainerTypeNoLayoutContainmentEnabled },
        { "ContentIndex", SetContentIndexEnabled },
        { "ContextMenu", SetContextMenuEnabled },
        { "ContinueEventTimingRecordingWhenBufferIsFull", SetContinueEventTimingRecordingWhenBufferIsFullEnabled },
        { "ControlledFrame", SetControlledFrameEnabled },
        { "CookieDeprecationFacilitatedTesting", SetCookieDeprecationFacilitatedTestingEnabled },
        { "CoopRestrictProperties", SetCoopRestrictPropertiesEnabled },
        { "CooperativeScheduling", SetCooperativeSchedulingEnabled },
        { "CorsRFC1918", SetCorsRFC1918Enabled },
        { "CreateInputShadowTreeDuringLayout", SetCreateInputShadowTreeDuringLayoutEnabled },
        { "CredentialManagerReport", SetCredentialManagerReportEnabled },
        { "CrossFramePerformanceTimeline", SetCrossFramePerformanceTimelineEnabled },
        { "CursorAnchorInfoMojoPipe", SetCursorAnchorInfoMojoPipeEnabled },
        { "CustomizableSelect", SetCustomizableSelectEnabled },
        { "DOMPartsAPI", SetDOMPartsAPIEnabled },
        { "DOMPartsAPIMinimal", SetDOMPartsAPIMinimalEnabled },
        { "Database", SetDatabaseEnabled },
        { "DeprecateUnloadOptOut", SetDeprecateUnloadOptOutEnabled },
        { "DeprecatedRequestAdapterInfo", SetDeprecatedRequestAdapterInfoEnabled },
        { "DesktopCaptureDisableLocalEchoControl", SetDesktopCaptureDisableLocalEchoControlEnabled },
        { "DesktopPWAsAdditionalWindowingControls", SetDesktopPWAsAdditionalWindowingControlsEnabled },
        { "DesktopPWAsSubApps", SetDesktopPWAsSubAppsEnabled },
        { "DetailsStyling", SetDetailsStylingEnabled },
        { "DeviceAttributes", SetDeviceAttributesEnabled },
        { "DeviceOrientationRequestPermission", SetDeviceOrientationRequestPermissionEnabled },
        { "DevicePosture", SetDevicePostureEnabled },
        { "DialogCloseWhenOpenRemoved", SetDialogCloseWhenOpenRemovedEnabled },
        { "DialogElementToggleEvents", SetDialogElementToggleEventsEnabled },
        { "DialogNewFocusBehavior", SetDialogNewFocusBehaviorEnabled },
        { "DigitalGoods", SetDigitalGoodsEnabled },
        { "DigitalGoodsV2_1", SetDigitalGoodsV2_1Enabled },
        { "DirAutoFixSlotExclusions", SetDirAutoFixSlotExclusionsEnabled },
        { "DirectSockets", SetDirectSocketsEnabled },
        { "DisableAhemAntialias", SetDisableAhemAntialiasEnabled },
        { "DisableDifferentOriginSubframeDialogSuppression", SetDisableDifferentOriginSubframeDialogSuppressionEnabled },
        { "DisableHardwareNoiseSuppression", SetDisableHardwareNoiseSuppressionEnabled },
        { "DisableReduceAcceptLanguage", SetDisableReduceAcceptLanguageEnabled },
        { "DisableSelectAllForEmptyText", SetDisableSelectAllForEmptyTextEnabled },
        { "DisableThirdPartyStoragePartitioning2", SetDisableThirdPartyStoragePartitioning2Enabled },
        { "DispatchBeforeInputForSpinButtonInteractions", SetDispatchBeforeInputForSpinButtonInteractionsEnabled },
        { "DispatchHiddenVisibilityTransitions", SetDispatchHiddenVisibilityTransitionsEnabled },
        { "DispatchSelectionchangeEventPerElement", SetDispatchSelectionchangeEventPerElementEnabled },
        { "DisplayContentsFocusable", SetDisplayContentsFocusableEnabled },
        { "DisplayCutoutAPI", SetDisplayCutoutAPIEnabled },
        { "DocumentCookie", SetDocumentCookieEnabled },
        { "DocumentDomain", SetDocumentDomainEnabled },
        { "DocumentInstallChunking", SetDocumentInstallChunkingEnabled },
        { "DocumentIsolationPolicy", SetDocumentIsolationPolicyEnabled },
        { "DocumentOpenOriginAliasRemoval", SetDocumentOpenOriginAliasRemovalEnabled },
        { "DocumentOpenSandboxInheritanceRemoval", SetDocumentOpenSandboxInheritanceRemovalEnabled },
        { "DocumentPictureInPictureAPI", SetDocumentPictureInPictureAPIEnabled },
        { "DocumentPictureInPicturePreferInitialPlacement", SetDocumentPictureInPicturePreferInitialPlacementEnabled },
        { "DocumentPictureInPictureUserActivation", SetDocumentPictureInPictureUserActivationEnabled },
        { "DocumentPolicyDocumentDomain", SetDocumentPolicyDocumentDomainEnabled },
        { "DocumentPolicyExpectNoLinkedResources", SetDocumentPolicyExpectNoLinkedResourcesEnabled },
        { "DocumentPolicyIncludeJSCallStacksInCrashReports", SetDocumentPolicyIncludeJSCallStacksInCrashReportsEnabled },
        { "DocumentPolicyNegotiation", SetDocumentPolicyNegotiationEnabled },
        { "DocumentPolicySyncXHR", SetDocumentPolicySyncXHREnabled },
        { "DocumentRenderBlocking", SetDocumentRenderBlockingEnabled },
        { "DocumentWrite", SetDocumentWriteEnabled },
        { "DropUrlAsPlainTextInPlainTextOnlyEditablePosition", SetDropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled },
        { "DynamicSafeAreaInsets", SetDynamicSafeAreaInsetsEnabled },
        { "DynamicSafeAreaInsetsOnScroll", SetDynamicSafeAreaInsetsOnScrollEnabled },
        { "ElementCapture", SetElementCaptureEnabled },
        { "ElementGetInnerHTML", SetElementGetInnerHTMLEnabled },
        { "EnforceAnonymityExposure", SetEnforceAnonymityExposureEnabled },
        { "EscapeLtGtInAttributes", SetEscapeLtGtInAttributesEnabled },
        { "EventTimingHandleKeyboardEventSimulatedClick", SetEventTimingHandleKeyboardEventSimulatedClickEnabled },
        { "EventTimingInteractionCount", SetEventTimingInteractionCountEnabled },
        { "EventTimingSelectionAutoScrollNoInteractionId", SetEventTimingSelectionAutoScrollNoInteractionIdEnabled },
        { "EventTimingTapStopScrollNoInteractionId", SetEventTimingTapStopScrollNoInteractionIdEnabled },
        { "ExcludeTransparentTextsFromBeingLcpEligible", SetExcludeTransparentTextsFromBeingLcpEligibleEnabled },
        { "ExperimentalContentSecurityPolicyFeatures", SetExperimentalContentSecurityPolicyFeaturesEnabled },
        { "ExperimentalJSProfilerMarkers", SetExperimentalJSProfilerMarkersEnabled },
        { "ExperimentalMachineLearningNeuralNetwork", SetExperimentalMachineLearningNeuralNetworkEnabled },
        { "ExperimentalPolicies", SetExperimentalPoliciesEnabled },
        { "ExposeCoarsenedRenderTime", SetExposeCoarsenedRenderTimeEnabled },
        { "ExposeRenderTimeNonTaoDelayedImage", SetExposeRenderTimeNonTaoDelayedImageEnabled },
        { "ExtendedTextMetrics", SetExtendedTextMetricsEnabled },
        { "EyeDropperAPI", SetEyeDropperAPIEnabled },
        { "FaceDetector", SetFaceDetectorEnabled },
        { "FastNonCompositedScrollHitTest", SetFastNonCompositedScrollHitTestEnabled },
        { "FastPathSingleSelectorExactMatch", SetFastPathSingleSelectorExactMatchEnabled },
        { "FastPositionIterator", SetFastPositionIteratorEnabled },
        { "FedCm", SetFedCmEnabled },
        { "FedCmAuthz", SetFedCmAuthzEnabled },
        { "FedCmAutoSelectedFlag", SetFedCmAutoSelectedFlagEnabled },
        { "FedCmButtonMode", SetFedCmButtonModeEnabled },
        { "FedCmDisconnect", SetFedCmDisconnectEnabled },
        { "FedCmDomainHint", SetFedCmDomainHintEnabled },
        { "FedCmError", SetFedCmErrorEnabled },
        { "FedCmIdPRegistration", SetFedCmIdPRegistrationEnabled },
        { "FedCmIdpSigninStatus", SetFedCmIdpSigninStatusEnabled },
        { "FedCmMultipleIdentityProviders", SetFedCmMultipleIdentityProvidersEnabled },
        { "FedCmSelectiveDisclosure", SetFedCmSelectiveDisclosureEnabled },
        { "FedCmWithStorageAccessAPI", SetFedCmWithStorageAccessAPIEnabled },
        { "FencedFrames", SetFencedFramesEnabled },
        { "FencedFramesAPIChanges", SetFencedFramesAPIChangesEnabled },
        { "FencedFramesDefaultMode", SetFencedFramesDefaultModeEnabled },
        { "FencedFramesLocalUnpartitionedDataAccess", SetFencedFramesLocalUnpartitionedDataAccessEnabled },
        { "FetchBodyBytes", SetFetchBodyBytesEnabled },
        { "FetchLaterAPI", SetFetchLaterAPIEnabled },
        { "FetchUploadStreaming", SetFetchUploadStreamingEnabled },
        { "FileHandling", SetFileHandlingEnabled },
        { "FileHandlingIcons", SetFileHandlingIconsEnabled },
        { "FileSystem", SetFileSystemEnabled },
        { "FileSystemAccess", SetFileSystemAccessEnabled },
        { "FileSystemAccessAPIExperimental", SetFileSystemAccessAPIExperimentalEnabled },
        { "FileSystemAccessGetCloudIdentifiers", SetFileSystemAccessGetCloudIdentifiersEnabled },
        { "FileSystemAccessLocal", SetFileSystemAccessLocalEnabled },
        { "FileSystemAccessLockingScheme", SetFileSystemAccessLockingSchemeEnabled },
        { "FileSystemAccessOriginPrivate", SetFileSystemAccessOriginPrivateEnabled },
        { "FileSystemObserver", SetFileSystemObserverEnabled },
        { "FileSystemObserverUnobserve", SetFileSystemObserverUnobserveEnabled },
        { "FindDecomposedInShortText", SetFindDecomposedInShortTextEnabled },
        { "FindRubyInPage", SetFindRubyInPageEnabled },
        { "FindTextInReadonlyTextInput", SetFindTextInReadonlyTextInputEnabled },
        { "FindTextSkipCollapsedText", SetFindTextSkipCollapsedTextEnabled },
        { "Fledge", SetFledgeEnabled },
        { "FledgeAuctionDealSupport", SetFledgeAuctionDealSupportEnabled },
        { "FledgeBiddingAndAuctionServerAPI", SetFledgeBiddingAndAuctionServerAPIEnabled },
        { "FledgeCustomMaxAuctionAdComponents", SetFledgeCustomMaxAuctionAdComponentsEnabled },
        { "FledgeDeprecatedRenderURLReplacements", SetFledgeDeprecatedRenderURLReplacementsEnabled },
        { "FledgeDirectFromSellerSignalsHeaderAdSlot", SetFledgeDirectFromSellerSignalsHeaderAdSlotEnabled },
        { "FledgeMultiBid", SetFledgeMultiBidEnabled },
        { "FledgeRealTimeReporting", SetFledgeRealTimeReportingEnabled },
        { "FledgeReportingTimeout", SetFledgeReportingTimeoutEnabled },
        { "FledgeSellerNonce", SetFledgeSellerNonceEnabled },
        { "FledgeTrustedSignalsKVv2Support", SetFledgeTrustedSignalsKVv2SupportEnabled },
        { "FluentOverlayScrollbars", SetFluentOverlayScrollbarsEnabled },
        { "FluentScrollbarUsesNinePatchTrack", SetFluentScrollbarUsesNinePatchTrackEnabled },
        { "FluentScrollbars", SetFluentScrollbarsEnabled },
        { "Focusgroup", SetFocusgroupEnabled },
        { "FontAccess", SetFontAccessEnabled },
        { "FontFamilyPostscriptMatchingCTMigration", SetFontFamilyPostscriptMatchingCTMigrationEnabled },
        { "FontFamilyStyleMatchingCTMigration", SetFontFamilyStyleMatchingCTMigrationEnabled },
        { "FontPresentWin", SetFontPresentWinEnabled },
        { "FontSrcLocalMatching", SetFontSrcLocalMatchingEnabled },
        { "FontSystemFallbackNotoCjk", SetFontSystemFallbackNotoCjkEnabled },
        { "FontVariantEmoji", SetFontVariantEmojiEnabled },
        { "FontVariationSequences", SetFontVariationSequencesEnabled },
        { "FontationsFontBackend", SetFontationsFontBackendEnabled },
        { "FontationsForSelectedFormats", SetFontationsForSelectedFormatsEnabled },
        { "ForceEagerMeasureMemory", SetForceEagerMeasureMemoryEnabled },
        { "ForceReduceMotion", SetForceReduceMotionEnabled },
        { "ForceTallerSelectPopup", SetForceTallerSelectPopupEnabled },
        { "ForcedColors", SetForcedColorsEnabled },
        { "ForcedColorsPreserveParentColor", SetForcedColorsPreserveParentColorEnabled },
        { "FormControlRestoreStateIfAutocompleteOff", SetFormControlRestoreStateIfAutocompleteOffEnabled },
        { "FormControlsVerticalWritingModeDirectionSupport", SetFormControlsVerticalWritingModeDirectionSupportEnabled },
        { "FractionalScrollOffsets", SetFractionalScrollOffsetsEnabled },
        { "FreezeFramesOnVisibility", SetFreezeFramesOnVisibilityEnabled },
        { "GamepadMultitouch", SetGamepadMultitouchEnabled },
        { "GetAllScreensMedia", SetGetAllScreensMediaEnabled },
        { "GetDisplayMedia", SetGetDisplayMediaEnabled },
        { "GetDisplayMediaRequiresUserActivation", SetGetDisplayMediaRequiresUserActivationEnabled },
        { "GroupEffect", SetGroupEffectEnabled },
        { "HTMLAnchorAttribute", SetHTMLAnchorAttributeEnabled },
        { "HTMLDialogLightDismiss", SetHTMLDialogLightDismissEnabled },
        { "HTMLEmbedElementNotForceLayout", SetHTMLEmbedElementNotForceLayoutEnabled },
        { "HTMLInterestTargetAttribute", SetHTMLInterestTargetAttributeEnabled },
        { "HTMLInvokeActionsV2", SetHTMLInvokeActionsV2Enabled },
        { "HTMLInvokeTargetAttribute", SetHTMLInvokeTargetAttributeEnabled },
        { "HTMLObjectElementFallbackDetachContentFrame", SetHTMLObjectElementFallbackDetachContentFrameEnabled },
        { "HTMLParserYieldAndDelayOftenForTesting", SetHTMLParserYieldAndDelayOftenForTestingEnabled },
        { "HTMLPopoverActionHover", SetHTMLPopoverActionHoverEnabled },
        { "HTMLPopoverHint", SetHTMLPopoverHintEnabled },
        { "HTMLSelectElementShowPicker", SetHTMLSelectElementShowPickerEnabled },
        { "HandleSelectionChangeOnDeletingEmptyElement", SetHandleSelectionChangeOnDeletingEmptyElementEnabled },
        { "HandwritingRecognition", SetHandwritingRecognitionEnabled },
        { "HangingWhitespaceDoesNotDependOnAlignment", SetHangingWhitespaceDoesNotDependOnAlignmentEnabled },
        { "HasUAVisualTransition", SetHasUAVisualTransitionEnabled },
        { "HighlightInheritance", SetHighlightInheritanceEnabled },
        { "HighlightPointerEvents", SetHighlightPointerEventsEnabled },
        { "HighlightsFromPoint", SetHighlightsFromPointEnabled },
        { "HitTestOpaqueness", SetHitTestOpaquenessEnabled },
        { "HitTestOpaquenessOmitLineBox", SetHitTestOpaquenessOmitLineBoxEnabled },
        { "HrefTranslate", SetHrefTranslateEnabled },
        { "ImplicitRootScroller", SetImplicitRootScrollerEnabled },
        { "ImportAttributesDisallowUnknownKeys", SetImportAttributesDisallowUnknownKeysEnabled },
        { "ImportMapIntegrity", SetImportMapIntegrityEnabled },
        { "IncomingCallNotifications", SetIncomingCallNotificationsEnabled },
        { "IncrementLocalSurfaceIdForMainframeSameDocNavigation", SetIncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled },
        { "IndexedDbGetAllRecords", SetIndexedDbGetAllRecordsEnabled },
        { "InertElementNonEditable", SetInertElementNonEditableEnabled },
        { "InertElementNonSearchable", SetInertElementNonSearchableEnabled },
        { "InfiniteCullRect", SetInfiniteCullRectEnabled },
        { "InheritUserModifyWithoutContenteditable", SetInheritUserModifyWithoutContenteditableEnabled },
        { "InitialLetterRaiseBySpecified", SetInitialLetterRaiseBySpecifiedEnabled },
        { "InlineBlockInSameLine", SetInlineBlockInSameLineEnabled },
        { "InnerHTMLParserFastpathLogFailure", SetInnerHTMLParserFastpathLogFailureEnabled },
        { "InputClosesSelect", SetInputClosesSelectEnabled },
        { "InputMultipleFieldsUI", SetInputMultipleFieldsUIEnabled },
        { "InsertBlockquoteBeforeOuterBlock", SetInsertBlockquoteBeforeOuterBlockEnabled },
        { "InsertLineBreakIfPhrasingContent", SetInsertLineBreakIfPhrasingContentEnabled },
        { "InspectorGhostRules", SetInspectorGhostRulesEnabled },
        { "InstallOnDeviceSpeechRecognition", SetInstallOnDeviceSpeechRecognitionEnabled },
        { "InstalledApp", SetInstalledAppEnabled },
        { "InterestGroupsInSharedStorageWorklet", SetInterestGroupsInSharedStorageWorkletEnabled },
        { "InteroperablePrivateAttribution", SetInteroperablePrivateAttributionEnabled },
        { "IntersectionObserverScrollMargin", SetIntersectionObserverScrollMarginEnabled },
        { "InvertedColors", SetInvertedColorsEnabled },
        { "InvisibleSVGAnimationThrottling", SetInvisibleSVGAnimationThrottlingEnabled },
        { "JavaScriptCompileHintsMagicAlwaysRuntime", SetJavaScriptCompileHintsMagicAlwaysRuntimeEnabled },
        { "JavaScriptCompileHintsMagicRuntime", SetJavaScriptCompileHintsMagicRuntimeEnabled },
        { "KeepCSSTargetAfterReattach", SetKeepCSSTargetAfterReattachEnabled },
        { "KeyboardAccessibleTooltip", SetKeyboardAccessibleTooltipEnabled },
        { "KeyboardFocusableScrollers", SetKeyboardFocusableScrollersEnabled },
        { "KeyboardFocusableScrollersOptOut", SetKeyboardFocusableScrollersOptOutEnabled },
        { "LCPAnimatedImagesWebExposed", SetLCPAnimatedImagesWebExposedEnabled },
        { "LabelAndDelegatesFocusNewHandling", SetLabelAndDelegatesFocusNewHandlingEnabled },
        { "LangAttributeAwareFormControlUI", SetLangAttributeAwareFormControlUIEnabled },
        { "LanguageDetectionAPI", SetLanguageDetectionAPIEnabled },
        { "LayoutFlexNewRowAlgorithmV3", SetLayoutFlexNewRowAlgorithmV3Enabled },
        { "LayoutIgnoreMarginsForSticky", SetLayoutIgnoreMarginsForStickyEnabled },
        { "LayoutJustifySelfForBlocks", SetLayoutJustifySelfForBlocksEnabled },
        { "LayoutNGShapeCache", SetLayoutNGShapeCacheEnabled },
        { "LayoutStretch", SetLayoutStretchEnabled },
        { "LazyInitializeMediaControls", SetLazyInitializeMediaControlsEnabled },
        { "LazyLoadScrollMargin", SetLazyLoadScrollMarginEnabled },
        { "LazyLoadScrollMarginIframe", SetLazyLoadScrollMarginIframeEnabled },
        { "LegacyWindowsDWriteFontFallback", SetLegacyWindowsDWriteFontFallbackEnabled },
        { "LimitThirdPartyCookies", SetLimitThirdPartyCookiesEnabled },
        { "LineBoxBelowLeadingFloats", SetLineBoxBelowLeadingFloatsEnabled },
        { "ListItemWithCounterSetNotSetExplicitValue", SetListItemWithCounterSetNotSetExplicitValueEnabled },
        { "LockedMode", SetLockedModeEnabled },
        { "LongAnimationFrameTiming", SetLongAnimationFrameTimingEnabled },
        { "LongPressLinkSelectText", SetLongPressLinkSelectTextEnabled },
        { "LongTaskFromLongAnimationFrame", SetLongTaskFromLongAnimationFrameEnabled },
        { "MachineLearningNeuralNetwork", SetMachineLearningNeuralNetworkEnabled },
        { "ManagedConfiguration", SetManagedConfigurationEnabled },
        { "MeasureMemory", SetMeasureMemoryEnabled },
        { "MediaCapabilitiesDynamicRange", SetMediaCapabilitiesDynamicRangeEnabled },
        { "MediaCapabilitiesEncodingInfo", SetMediaCapabilitiesEncodingInfoEnabled },
        { "MediaCapabilitiesSpatialAudio", SetMediaCapabilitiesSpatialAudioEnabled },
        { "MediaCapture", SetMediaCaptureEnabled },
        { "MediaCaptureBackgroundBlur", SetMediaCaptureBackgroundBlurEnabled },
        { "MediaCaptureCameraControls", SetMediaCaptureCameraControlsEnabled },
        { "MediaCaptureConfigurationChange", SetMediaCaptureConfigurationChangeEnabled },
        { "MediaCaptureVoiceIsolation", SetMediaCaptureVoiceIsolationEnabled },
        { "MediaCastOverlayButton", SetMediaCastOverlayButtonEnabled },
        { "MediaControlsExpandGesture", SetMediaControlsExpandGestureEnabled },
        { "MediaControlsOverlayPlayButton", SetMediaControlsOverlayPlayButtonEnabled },
        { "MediaElementVolumeGreaterThanOne", SetMediaElementVolumeGreaterThanOneEnabled },
        { "MediaEngagementBypassAutoplayPolicies", SetMediaEngagementBypassAutoplayPoliciesEnabled },
        { "MediaLatencyHint", SetMediaLatencyHintEnabled },
        { "MediaPlaybackWhileNotVisiblePermissionPolicy", SetMediaPlaybackWhileNotVisiblePermissionPolicyEnabled },
        { "MediaPreviewsOptOut", SetMediaPreviewsOptOutEnabled },
        { "MediaQueryNavigationControls", SetMediaQueryNavigationControlsEnabled },
        { "MediaRecorderUseMediaVideoEncoder", SetMediaRecorderUseMediaVideoEncoderEnabled },
        { "MediaSession", SetMediaSessionEnabled },
        { "MediaSessionChapterInformation", SetMediaSessionChapterInformationEnabled },
        { "MediaSessionEnterPictureInPicture", SetMediaSessionEnterPictureInPictureEnabled },
        { "MediaSourceExperimental", SetMediaSourceExperimentalEnabled },
        { "MediaSourceExtensionsForWebCodecs", SetMediaSourceExtensionsForWebCodecsEnabled },
        { "MediaSourceNewAbortAndDuration", SetMediaSourceNewAbortAndDurationEnabled },
        { "MediaStreamTrackTransfer", SetMediaStreamTrackTransferEnabled },
        { "MediaStreamTrackWebSpeech", SetMediaStreamTrackWebSpeechEnabled },
        { "MessagePortCloseEvent", SetMessagePortCloseEventEnabled },
        { "MetaRefreshNoFractional", SetMetaRefreshNoFractionalEnabled },
        { "MeterAppearanceNoneFallbackStyle", SetMeterAppearanceNoneFallbackStyleEnabled },
        { "MeterDevolveAppearance", SetMeterDevolveAppearanceEnabled },
        { "MiddleClickAutoscroll", SetMiddleClickAutoscrollEnabled },
        { "MinimimalResourceRequestPrepBeforeCacheLookup", SetMinimimalResourceRequestPrepBeforeCacheLookupEnabled },
        { "MobileLayoutTheme", SetMobileLayoutThemeEnabled },
        { "ModifyParagraphCrossEditingoundary", SetModifyParagraphCrossEditingoundaryEnabled },
        { "MojoJS", SetMojoJSEnabled },
        { "MojoJSTest", SetMojoJSTestEnabled },
        { "MoveEndingSelectionToListChild", SetMoveEndingSelectionToListChildEnabled },
        { "MoveToParagraphStartOrEndSkipsNonEditable", SetMoveToParagraphStartOrEndSkipsNonEditableEnabled },
        { "MultiSelectDeselectWhenOnlyOption", SetMultiSelectDeselectWhenOnlyOptionEnabled },
        { "MultiSmoothScrollIntoView", SetMultiSmoothScrollIntoViewEnabled },
        { "MultipleImportMaps", SetMultipleImportMapsEnabled },
        { "MutationEvents", SetMutationEventsEnabled },
        { "MutationEventsSpecialTrialMessage", SetMutationEventsSpecialTrialMessageEnabled },
        { "NavigateEventCommitBehavior", SetNavigateEventCommitBehaviorEnabled },
        { "NavigateEventSourceElement", SetNavigateEventSourceElementEnabled },
        { "NavigationActivation", SetNavigationActivationEnabled },
        { "NavigationId", SetNavigationIdEnabled },
        { "NavigatorContentUtils", SetNavigatorContentUtilsEnabled },
        { "NestedViewTransition", SetNestedViewTransitionEnabled },
        { "NetInfoConstantType", SetNetInfoConstantTypeEnabled },
        { "NetInfoDownlinkMax", SetNetInfoDownlinkMaxEnabled },
        { "NewGetFocusableAreaBehavior", SetNewGetFocusableAreaBehaviorEnabled },
        { "NoIdleEncodingForWebTests", SetNoIdleEncodingForWebTestsEnabled },
        { "NoIncreasingEndOffsetOnSplittingTextNodes", SetNoIncreasingEndOffsetOnSplittingTextNodesEnabled },
        { "NonEmptyBlockquotesOnOutdenting", SetNonEmptyBlockquotesOnOutdentingEnabled },
        { "NonNullInputEventDataForTextArea", SetNonNullInputEventDataForTextAreaEnabled },
        { "NonStandardAppearanceValueSliderVertical", SetNonStandardAppearanceValueSliderVerticalEnabled },
        { "NotificationConstructor", SetNotificationConstructorEnabled },
        { "NotificationContentImage", SetNotificationContentImageEnabled },
        { "NotificationTriggers", SetNotificationTriggersEnabled },
        { "Notifications", SetNotificationsEnabled },
        { "ObservableAPI", SetObservableAPIEnabled },
        { "OffMainThreadCSSPaint", SetOffMainThreadCSSPaintEnabled },
        { "OffscreenCanvasCommit", SetOffscreenCanvasCommitEnabled },
        { "OmitBlurEventOnElementRemoval", SetOmitBlurEventOnElementRemovalEnabled },
        { "OnDeviceChange", SetOnDeviceChangeEnabled },
        { "OnDeviceWebSpeechAvailable", SetOnDeviceWebSpeechAvailableEnabled },
        { "OrientationEvent", SetOrientationEventEnabled },
        { "OriginIsolationHeader", SetOriginIsolationHeaderEnabled },
        { "OriginPolicy", SetOriginPolicyEnabled },
        { "OriginTrialsSampleAPI", SetOriginTrialsSampleAPIEnabled },
        { "OriginTrialsSampleAPIBrowserReadWrite", SetOriginTrialsSampleAPIBrowserReadWriteEnabled },
        { "OriginTrialsSampleAPIDependent", SetOriginTrialsSampleAPIDependentEnabled },
        { "OriginTrialsSampleAPIDeprecation", SetOriginTrialsSampleAPIDeprecationEnabled },
        { "OriginTrialsSampleAPIExpiryGracePeriod", SetOriginTrialsSampleAPIExpiryGracePeriodEnabled },
        { "OriginTrialsSampleAPIExpiryGracePeriodThirdParty", SetOriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled },
        { "OriginTrialsSampleAPIImplied", SetOriginTrialsSampleAPIImpliedEnabled },
        { "OriginTrialsSampleAPIInvalidOS", SetOriginTrialsSampleAPIInvalidOSEnabled },
        { "OriginTrialsSampleAPINavigation", SetOriginTrialsSampleAPINavigationEnabled },
        { "OriginTrialsSampleAPIPersistentExpiryGracePeriod", SetOriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled },
        { "OriginTrialsSampleAPIPersistentFeature", SetOriginTrialsSampleAPIPersistentFeatureEnabled },
        { "OriginTrialsSampleAPIPersistentInvalidOS", SetOriginTrialsSampleAPIPersistentInvalidOSEnabled },
        { "OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature", SetOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled },
        { "OriginTrialsSampleAPIThirdParty", SetOriginTrialsSampleAPIThirdPartyEnabled },
        { "OverscrollCustomization", SetOverscrollCustomizationEnabled },
        { "PNaCl", SetPNaClEnabled },
        { "PageFreezeOptIn", SetPageFreezeOptInEnabled },
        { "PageFreezeOptOut", SetPageFreezeOptOutEnabled },
        { "PageMarginBoxes", SetPageMarginBoxesEnabled },
        { "PagePopup", SetPagePopupEnabled },
        { "PageRevealEvent", SetPageRevealEventEnabled },
        { "PageSwapEvent", SetPageSwapEventEnabled },
        { "PaintHighlightsForFirstLetter", SetPaintHighlightsForFirstLetterEnabled },
        { "PaintHoldingForIframes", SetPaintHoldingForIframesEnabled },
        { "PaintHoldingForLocalIframes", SetPaintHoldingForLocalIframesEnabled },
        { "PaintUnderInvalidationChecking", SetPaintUnderInvalidationCheckingEnabled },
        { "Parakeet", SetParakeetEnabled },
        { "PartitionVisitedLinkDatabaseWithSelfLinks", SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled },
        { "PartitionedPopins", SetPartitionedPopinsEnabled },
        { "PasswordReveal", SetPasswordRevealEnabled },
        { "PaymentApp", SetPaymentAppEnabled },
        { "PaymentInstruments", SetPaymentInstrumentsEnabled },
        { "PaymentLinkDetection", SetPaymentLinkDetectionEnabled },
        { "PaymentMethodChangeEvent", SetPaymentMethodChangeEventEnabled },
        { "PaymentRequest", SetPaymentRequestEnabled },
        { "PerMethodCanMakePaymentQuota", SetPerMethodCanMakePaymentQuotaEnabled },
        { "PercentBasedScrolling", SetPercentBasedScrollingEnabled },
        { "PerformanceManagerInstrumentation", SetPerformanceManagerInstrumentationEnabled },
        { "PerformanceMarkFeatureUsage", SetPerformanceMarkFeatureUsageEnabled },
        { "PerformanceNavigateSystemEntropy", SetPerformanceNavigateSystemEntropyEnabled },
        { "PerformanceNavigationTimingConfidence", SetPerformanceNavigationTimingConfidenceEnabled },
        { "PeriodicBackgroundSync", SetPeriodicBackgroundSyncEnabled },
        { "PermissionElement", SetPermissionElementEnabled },
        { "Permissions", SetPermissionsEnabled },
        { "PermissionsRequestRevoke", SetPermissionsRequestRevokeEnabled },
        { "PointerEventDeviceId", SetPointerEventDeviceIdEnabled },
        { "PointerEventTargetsInEventLists", SetPointerEventTargetsInEventListsEnabled },
        { "PopoverAnchorRelationships", SetPopoverAnchorRelationshipsEnabled },
        { "PopoverDialogNewFocusBehavior", SetPopoverDialogNewFocusBehaviorEnabled },
        { "PositionOutsideTabSpanCheckSiblingNode", SetPositionOutsideTabSpanCheckSiblingNodeEnabled },
        { "PreciseMemoryInfo", SetPreciseMemoryInfoEnabled },
        { "PreferDefaultScrollbarStyles", SetPreferDefaultScrollbarStylesEnabled },
        { "PreferNonCompositedScrolling", SetPreferNonCompositedScrollingEnabled },
        { "PrefersReducedData", SetPrefersReducedDataEnabled },
        { "PrefixedVideoFullscreen", SetPrefixedVideoFullscreenEnabled },
        { "Prerender2", SetPrerender2Enabled },
        { "Presentation", SetPresentationEnabled },
        { "PreserveFollowingBlockStylesDuringBlockMerge", SetPreserveFollowingBlockStylesDuringBlockMergeEnabled },
        { "PreventUndoIfNotEditable", SetPreventUndoIfNotEditableEnabled },
        { "PrivateAggregationApiFilteringIds", SetPrivateAggregationApiFilteringIdsEnabled },
        { "PrivateAggregationAuctionReportBuyerDebugModeConfig", SetPrivateAggregationAuctionReportBuyerDebugModeConfigEnabled },
        { "PrivateNetworkAccessNonSecureContextsAllowed", SetPrivateNetworkAccessNonSecureContextsAllowedEnabled },
        { "PrivateNetworkAccessNullIpAddress", SetPrivateNetworkAccessNullIpAddressEnabled },
        { "PrivateNetworkAccessPermissionPrompt", SetPrivateNetworkAccessPermissionPromptEnabled },
        { "PrivateStateTokens", SetPrivateStateTokensEnabled },
        { "PrivateStateTokensAlwaysAllowIssuance", SetPrivateStateTokensAlwaysAllowIssuanceEnabled },
        { "ProtectedOriginTrialsSampleAPI", SetProtectedOriginTrialsSampleAPIEnabled },
        { "ProtectedOriginTrialsSampleAPIDependent", SetProtectedOriginTrialsSampleAPIDependentEnabled },
        { "ProtectedOriginTrialsSampleAPIImplied", SetProtectedOriginTrialsSampleAPIImpliedEnabled },
        { "PseudoElementsCorrectInGetComputedStyle", SetPseudoElementsCorrectInGetComputedStyleEnabled },
        { "PseudoElementsFocusable", SetPseudoElementsFocusableEnabled },
        { "PushMessageDataBytes", SetPushMessageDataBytesEnabled },
        { "PushMessaging", SetPushMessagingEnabled },
        { "PushMessagingSubscriptionChange", SetPushMessagingSubscriptionChangeEnabled },
        { "QuickIntensiveWakeUpThrottlingAfterLoading", SetQuickIntensiveWakeUpThrottlingAfterLoadingEnabled },
        { "RTCDataChannelPriority", SetRTCDataChannelPriorityEnabled },
        { "RTCEncodedAudioFrameAbsCaptureTime", SetRTCEncodedAudioFrameAbsCaptureTimeEnabled },
        { "RTCEncodedFrameSetMetadata", SetRTCEncodedFrameSetMetadataEnabled },
        { "RTCEncodedVideoFrameAdditionalMetadata", SetRTCEncodedVideoFrameAdditionalMetadataEnabled },
        { "RTCJitterBufferTarget", SetRTCJitterBufferTargetEnabled },
        { "RTCLegacyCallbackBasedGetStats", SetRTCLegacyCallbackBasedGetStatsEnabled },
        { "RTCRtpEncodingParametersCodec", SetRTCRtpEncodingParametersCodecEnabled },
        { "RTCRtpScaleResolutionDownTo", SetRTCRtpScaleResolutionDownToEnabled },
        { "RTCRtpScriptTransform", SetRTCRtpScriptTransformEnabled },
        { "RTCRtpTransport", SetRTCRtpTransportEnabled },
        { "RTCStatsRelativePacketArrivalDelay", SetRTCStatsRelativePacketArrivalDelayEnabled },
        { "RTCSvcScalabilityMode", SetRTCSvcScalabilityModeEnabled },
        { "RasterInducingScroll", SetRasterInducingScrollEnabled },
        { "ReadableStreamAsyncIterable", SetReadableStreamAsyncIterableEnabled },
        { "ReduceAcceptLanguage", SetReduceAcceptLanguageEnabled },
        { "ReduceCookieIPCs", SetReduceCookieIPCsEnabled },
        { "ReduceUserAgentAndroidVersionDeviceModel", SetReduceUserAgentAndroidVersionDeviceModelEnabled },
        { "ReduceUserAgentMinorVersion", SetReduceUserAgentMinorVersionEnabled },
        { "ReduceUserAgentPlatformOsCpu", SetReduceUserAgentPlatformOsCpuEnabled },
        { "RegionCapture", SetRegionCaptureEnabled },
        { "RelOpenerBcgDependencyHint", SetRelOpenerBcgDependencyHintEnabled },
        { "RemotePlayback", SetRemotePlaybackEnabled },
        { "RemotePlaybackBackend", SetRemotePlaybackBackendEnabled },
        { "RemoveCollapsedPlaceholder", SetRemoveCollapsedPlaceholderEnabled },
        { "RemoveDanglingMarkupInTarget", SetRemoveDanglingMarkupInTargetEnabled },
        { "RemoveDataUrlInSvgUse", SetRemoveDataUrlInSvgUseEnabled },
        { "RemoveNodeHavingChildrenIfFullySelected", SetRemoveNodeHavingChildrenIfFullySelectedEnabled },
        { "RemoveVisibleSelectionInDOMSelection", SetRemoveVisibleSelectionInDOMSelectionEnabled },
        { "RenderBlockingInlineModuleScript", SetRenderBlockingInlineModuleScriptEnabled },
        { "RenderBlockingStatus", SetRenderBlockingStatusEnabled },
        { "RenderPriorityAttribute", SetRenderPriorityAttributeEnabled },
        { "ReportEventTimingAtVisibilityChange", SetReportEventTimingAtVisibilityChangeEnabled },
        { "ReportVisibleLineBounds", SetReportVisibleLineBoundsEnabled },
        { "ResetInputTypeToNoneBeforeCharacterInput", SetResetInputTypeToNoneBeforeCharacterInputEnabled },
        { "ResourceTimingContentType", SetResourceTimingContentTypeEnabled },
        { "ResourceTimingFinalResponseHeadersStart", SetResourceTimingFinalResponseHeadersStartEnabled },
        { "ResourceTimingUseCORSForBodySizes", SetResourceTimingUseCORSForBodySizesEnabled },
        { "RestrictGamepadAccess", SetRestrictGamepadAccessEnabled },
        { "ReuseShapeResultsByFonts", SetReuseShapeResultsByFontsEnabled },
        { "RewindFloats", SetRewindFloatsEnabled },
        { "RootElementWithPlaceHolderAfterDeletingSelection", SetRootElementWithPlaceHolderAfterDeletingSelectionEnabled },
        { "RtcAudioJitterBufferMaxPackets", SetRtcAudioJitterBufferMaxPacketsEnabled },
        { "RubyShortHeuristics", SetRubyShortHeuristicsEnabled },
        { "SanitizerAPI", SetSanitizerAPIEnabled },
        { "ScheduleSelectionChangeOnBackspace", SetScheduleSelectionChangeOnBackspaceEnabled },
        { "SchedulerYield", SetSchedulerYieldEnabled },
        { "ScopedCustomElementRegistry", SetScopedCustomElementRegistryEnabled },
        { "ScriptedSpeechRecognition", SetScriptedSpeechRecognitionEnabled },
        { "ScriptedSpeechSynthesis", SetScriptedSpeechSynthesisEnabled },
        { "ScrollEndEvents", SetScrollEndEventsEnabled },
        { "ScrollIntoViewRootFrameViewportBugFix", SetScrollIntoViewRootFrameViewportBugFixEnabled },
        { "ScrollTimeline", SetScrollTimelineEnabled },
        { "ScrollTimelineCurrentTime", SetScrollTimelineCurrentTimeEnabled },
        { "ScrollTopLeftInterop", SetScrollTopLeftInteropEnabled },
        { "ScrollbarColor", SetScrollbarColorEnabled },
        { "ScrollbarWidth", SetScrollbarWidthEnabled },
        { "SearchTextHighlightPseudo", SetSearchTextHighlightPseudoEnabled },
        { "SecurePaymentConfirmation", SetSecurePaymentConfirmationEnabled },
        { "SecurePaymentConfirmationDebug", SetSecurePaymentConfirmationDebugEnabled },
        { "SecurePaymentConfirmationNetworkAndIssuerIcons", SetSecurePaymentConfirmationNetworkAndIssuerIconsEnabled },
        { "SecurePaymentConfirmationOptOut", SetSecurePaymentConfirmationOptOutEnabled },
        { "SelectAudioOutput", SetSelectAudioOutputEnabled },
        { "SelectOptionAccessibilityTargetSize", SetSelectOptionAccessibilityTargetSizeEnabled },
        { "SelectParserRelaxation", SetSelectParserRelaxationEnabled },
        { "SelectPopupLessUpdates", SetSelectPopupLessUpdatesEnabled },
        { "SelectedcontentelementAttribute", SetSelectedcontentelementAttributeEnabled },
        { "SelectionAcrossShadowDOM", SetSelectionAcrossShadowDOMEnabled },
        { "SelectionIsCollapsedShadowDOMSupport", SetSelectionIsCollapsedShadowDOMSupportEnabled },
        { "SelectionOnShadowDOMWithDelegatesFocus", SetSelectionOnShadowDOMWithDelegatesFocusEnabled },
        { "SendBeaconThrowForBlobWithNonSimpleType", SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled },
        { "SensorExtraClasses", SetSensorExtraClassesEnabled },
        { "Serial", SetSerialEnabled },
        { "SerialPortConnected", SetSerialPortConnectedEnabled },
        { "SerializeViewTransitionStateInSPA", SetSerializeViewTransitionStateInSPAEnabled },
        { "ServiceWorkerClientLifecycleState", SetServiceWorkerClientLifecycleStateEnabled },
        { "ServiceWorkerStaticRouter", SetServiceWorkerStaticRouterEnabled },
        { "ServiceWorkerStaticRouterTimingInfo", SetServiceWorkerStaticRouterTimingInfoEnabled },
        { "SetSequentialFocusStartingPoint", SetSetSequentialFocusStartingPointEnabled },
        { "ShadowRootReferenceTarget", SetShadowRootReferenceTargetEnabled },
        { "ShapeOutsideWritingModeFix", SetShapeOutsideWritingModeFixEnabled },
        { "ShapeResultCachedPreviousSafeToBreakOffset", SetShapeResultCachedPreviousSafeToBreakOffsetEnabled },
        { "SharedArrayBuffer", SetSharedArrayBufferEnabled },
        { "SharedArrayBufferOnDesktop", SetSharedArrayBufferOnDesktopEnabled },
        { "SharedArrayBufferUnrestrictedAccessAllowed", SetSharedArrayBufferUnrestrictedAccessAllowedEnabled },
        { "SharedAutofill", SetSharedAutofillEnabled },
        { "SharedStorageAPI", SetSharedStorageAPIEnabled },
        { "SharedStorageAPIM118", SetSharedStorageAPIM118Enabled },
        { "SharedStorageAPIM125", SetSharedStorageAPIM125Enabled },
        { "SharedStorageWebLocks", SetSharedStorageWebLocksEnabled },
        { "SharedWorker", SetSharedWorkerEnabled },
        { "SidewaysWritingModes", SetSidewaysWritingModesEnabled },
        { "SignatureBasedIntegrity", SetSignatureBasedIntegrityEnabled },
        { "SiteInitiatedMirroring", SetSiteInitiatedMirroringEnabled },
        { "SkipAd", SetSkipAdEnabled },
        { "SkipPreloadScanning", SetSkipPreloadScanningEnabled },
        { "SkipTemporaryDocumentFragment", SetSkipTemporaryDocumentFragmentEnabled },
        { "SkipTouchEventFilter", SetSkipTouchEventFilterEnabled },
        { "SmartCard", SetSmartCardEnabled },
        { "SmartZoom", SetSmartZoomEnabled },
        { "SmilAutoSuspendOnLag", SetSmilAutoSuspendOnLagEnabled },
        { "SoftNavigationDetection", SetSoftNavigationDetectionEnabled },
        { "SoftNavigationHeuristics", SetSoftNavigationHeuristicsEnabled },
        { "SoftNavigationHeuristicsExposeFPAndFCP", SetSoftNavigationHeuristicsExposeFPAndFCPEnabled },
        { "SpeakerSelection", SetSpeakerSelectionEnabled },
        { "SpeculationRulesPointerDownHeuristics", SetSpeculationRulesPointerDownHeuristicsEnabled },
        { "SpeculationRulesPointerHoverHeuristics", SetSpeculationRulesPointerHoverHeuristicsEnabled },
        { "SpeculationRulesPrefetchFuture", SetSpeculationRulesPrefetchFutureEnabled },
        { "SpeculationRulesPrefetchWithSubresources", SetSpeculationRulesPrefetchWithSubresourcesEnabled },
        { "SrcsetMaxDensity", SetSrcsetMaxDensityEnabled },
        { "StableBlinkFeatures", SetStableBlinkFeaturesEnabled },
        { "StandardizedBrowserZoom", SetStandardizedBrowserZoomEnabled },
        { "StandardizedBrowserZoomOptOut", SetStandardizedBrowserZoomOptOutEnabled },
        { "StaticAnimationOptimization", SetStaticAnimationOptimizationEnabled },
        { "StorageAccessHeader", SetStorageAccessHeaderEnabled },
        { "StorageBuckets", SetStorageBucketsEnabled },
        { "StorageBucketsDurability", SetStorageBucketsDurabilityEnabled },
        { "StorageBucketsLocks", SetStorageBucketsLocksEnabled },
        { "StrictMimeTypesForWorkers", SetStrictMimeTypesForWorkersEnabled },
        { "StricterCellWidthContentSizeQuirk", SetStricterCellWidthContentSizeQuirkEnabled },
        { "StylusHandwriting", SetStylusHandwritingEnabled },
        { "SvgContextPaint", SetSvgContextPaintEnabled },
        { "SvgCrossOriginAttribute", SetSvgCrossOriginAttributeEnabled },
        { "SvgEagerPresAttrStyleUpdate", SetSvgEagerPresAttrStyleUpdateEnabled },
        { "SvgExternalResources", SetSvgExternalResourcesEnabled },
        { "SvgFilterUserSpaceViewportForNonSvg", SetSvgFilterUserSpaceViewportForNonSvgEnabled },
        { "SvgGradientColorInterpolationLinearRgbSupport", SetSvgGradientColorInterpolationLinearRgbSupportEnabled },
        { "SvgInlineRootPixelSnappingScaleAdjustment", SetSvgInlineRootPixelSnappingScaleAdjustmentEnabled },
        { "SvgNoPixelSnappingScaleAdjustment", SetSvgNoPixelSnappingScaleAdjustmentEnabled },
        { "SvgTransformOptimization", SetSvgTransformOptimizationEnabled },
        { "SynthesizedKeyboardEventsForAccessibilityActions", SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled },
        { "SystemFallbackEmojiVSSupport", SetSystemFallbackEmojiVSSupportEnabled },
        { "SystemWakeLock", SetSystemWakeLockEnabled },
        { "TestBlinkFeatureDefault", SetTestBlinkFeatureDefaultEnabled },
        { "TestFeature", SetTestFeatureEnabled },
        { "TestFeatureDependent", SetTestFeatureDependentEnabled },
        { "TestFeatureImplied", SetTestFeatureImpliedEnabled },
        { "TestFeatureProtected", SetTestFeatureProtectedEnabled },
        { "TestFeatureProtectedDependent", SetTestFeatureProtectedDependentEnabled },
        { "TestFeatureProtectedImplied", SetTestFeatureProtectedImpliedEnabled },
        { "TestFeatureStable", SetTestFeatureStableEnabled },
        { "TextDetector", SetTextDetectorEnabled },
        { "TextDiffSplitFix", SetTextDiffSplitFixEnabled },
        { "TextFragmentAPI", SetTextFragmentAPIEnabled },
        { "TextFragmentIdentifiers", SetTextFragmentIdentifiersEnabled },
        { "TextFragmentTapOpensContextMenu", SetTextFragmentTapOpensContextMenuEnabled },
        { "TextInputNotAlwaysDirAuto", SetTextInputNotAlwaysDirAutoEnabled },
        { "TextMetricsBaselines", SetTextMetricsBaselinesEnabled },
        { "TextSegmentBoundaryForElementWithFloatStyle", SetTextSegmentBoundaryForElementWithFloatStyleEnabled },
        { "TextSizeAdjustImprovements", SetTextSizeAdjustImprovementsEnabled },
        { "TextTransformAndSecurityFix", SetTextTransformAndSecurityFixEnabled },
        { "TimeZoneChangeEvent", SetTimeZoneChangeEventEnabled },
        { "TimelineScope", SetTimelineScopeEnabled },
        { "TimerThrottlingForBackgroundTabs", SetTimerThrottlingForBackgroundTabsEnabled },
        { "TimestampBasedCLSTracking", SetTimestampBasedCLSTrackingEnabled },
        { "TopLayerInactiveDocumentExceptions", SetTopLayerInactiveDocumentExceptionsEnabled },
        { "TopLevelTpcd", SetTopLevelTpcdEnabled },
        { "TopicsAPI", SetTopicsAPIEnabled },
        { "TopicsDocumentAPI", SetTopicsDocumentAPIEnabled },
        { "TouchDragAndContextMenu", SetTouchDragAndContextMenuEnabled },
        { "TouchDragOnShortPress", SetTouchDragOnShortPressEnabled },
        { "TouchEventFeatureDetection", SetTouchEventFeatureDetectionEnabled },
        { "TouchTextEditingRedesign", SetTouchTextEditingRedesignEnabled },
        { "Tpcd", SetTpcdEnabled },
        { "TransferableRTCDataChannel", SetTransferableRTCDataChannelEnabled },
        { "TranslateService", SetTranslateServiceEnabled },
        { "TranslationAPI", SetTranslationAPIEnabled },
        { "TranslationAPIEntryPoint", SetTranslationAPIEntryPointEnabled },
        { "TrustedTypeBeforePolicyCreationEvent", SetTrustedTypeBeforePolicyCreationEventEnabled },
        { "TrustedTypesFromLiteral", SetTrustedTypesFromLiteralEnabled },
        { "TrustedTypesUseCodeLike", SetTrustedTypesUseCodeLikeEnabled },
        { "URLPatternCompareComponent", SetURLPatternCompareComponentEnabled },
        { "URLSearchParamsHasAndDeleteMultipleArgs", SetURLSearchParamsHasAndDeleteMultipleArgsEnabled },
        { "UnclosedFormControlIsInvalid", SetUnclosedFormControlIsInvalidEnabled },
        { "UnexposedTaskIds", SetUnexposedTaskIdsEnabled },
        { "UnownedAnimationsSkipCSSEvents", SetUnownedAnimationsSkipCSSEventsEnabled },
        { "UnrestrictedMeasureUserAgentSpecificMemory", SetUnrestrictedMeasureUserAgentSpecificMemoryEnabled },
        { "UnrestrictedSharedArrayBuffer", SetUnrestrictedSharedArrayBufferEnabled },
        { "UnrestrictedUsb", SetUnrestrictedUsbEnabled },
        { "UseBeginFramePresentationFeedback", SetUseBeginFramePresentationFeedbackEnabled },
        { "UseLowQualityInterpolation", SetUseLowQualityInterpolationEnabled },
        { "UseSelectionFocusNodeForCaretNavigation", SetUseSelectionFocusNodeForCaretNavigationEnabled },
        { "UseUndoStepElementDispatchBeforeInput", SetUseUndoStepElementDispatchBeforeInputEnabled },
        { "UserActivationSameOriginVisibility", SetUserActivationSameOriginVisibilityEnabled },
        { "V8IdleTasks", SetV8IdleTasksEnabled },
        { "VideoAutoFullscreen", SetVideoAutoFullscreenEnabled },
        { "VideoFrameMetadataBackgroundBlur", SetVideoFrameMetadataBackgroundBlurEnabled },
        { "VideoFullscreenOrientationLock", SetVideoFullscreenOrientationLockEnabled },
        { "VideoRotateToFullscreen", SetVideoRotateToFullscreenEnabled },
        { "VideoTrackGenerator", SetVideoTrackGeneratorEnabled },
        { "VideoTrackGeneratorInWindow", SetVideoTrackGeneratorInWindowEnabled },
        { "VideoTrackGeneratorInWorker", SetVideoTrackGeneratorInWorkerEnabled },
        { "ViewTransitionDisableSnapBrowserControlsOnHidden", SetViewTransitionDisableSnapBrowserControlsOnHiddenEnabled },
        { "ViewTransitionLayeredCapture", SetViewTransitionLayeredCaptureEnabled },
        { "ViewTransitionLongCallbackTimeoutForTesting", SetViewTransitionLongCallbackTimeoutForTestingEnabled },
        { "ViewTransitionOnNavigation", SetViewTransitionOnNavigationEnabled },
        { "ViewTransitionOnNavigationForIframes", SetViewTransitionOnNavigationForIframesEnabled },
        { "ViewTransitionOverflowRectFromSurface", SetViewTransitionOverflowRectFromSurfaceEnabled },
        { "ViewTransitionTreeScopedNames", SetViewTransitionTreeScopedNamesEnabled },
        { "ViewTransitionTypes", SetViewTransitionTypesEnabled },
        { "ViewportChangesUpdateTextAutosizing", SetViewportChangesUpdateTextAutosizingEnabled },
        { "ViewportHeightClientHintHeader", SetViewportHeightClientHintHeaderEnabled },
        { "ViewportSegments", SetViewportSegmentsEnabled },
        { "VisibilityCollapseColumn", SetVisibilityCollapseColumnEnabled },
        { "VisualViewportOnScrollEnd", SetVisualViewportOnScrollEndEnabled },
        { "WakeLock", SetWakeLockEnabled },
        { "WarnOnContentVisibilityRenderAccess", SetWarnOnContentVisibilityRenderAccessEnabled },
        { "WebAnimationsSVG", SetWebAnimationsSVGEnabled },
        { "WebAppInstallation", SetWebAppInstallationEnabled },
        { "WebAppLaunchQueue", SetWebAppLaunchQueueEnabled },
        { "WebAppScopeExtensions", SetWebAppScopeExtensionsEnabled },
        { "WebAppTabStrip", SetWebAppTabStripEnabled },
        { "WebAppTabStripCustomizations", SetWebAppTabStripCustomizationsEnabled },
        { "WebAppTranslations", SetWebAppTranslationsEnabled },
        { "WebAppUrlHandling", SetWebAppUrlHandlingEnabled },
        { "WebAssemblyJSPromiseIntegration", SetWebAssemblyJSPromiseIntegrationEnabled },
        { "WebAssemblyJSStringBuiltins", SetWebAssemblyJSStringBuiltinsEnabled },
        { "WebAudioBypassOutputBuffering", SetWebAudioBypassOutputBufferingEnabled },
        { "WebAudioBypassOutputBufferingOptOut", SetWebAudioBypassOutputBufferingOptOutEnabled },
        { "WebAuth", SetWebAuthEnabled },
        { "WebAuthAuthenticatorAttachment", SetWebAuthAuthenticatorAttachmentEnabled },
        { "WebAuthenticationAmbient", SetWebAuthenticationAmbientEnabled },
        { "WebAuthenticationAttestationFormats", SetWebAuthenticationAttestationFormatsEnabled },
        { "WebAuthenticationClientCapabilities", SetWebAuthenticationClientCapabilitiesEnabled },
        { "WebAuthenticationJSONSerialization", SetWebAuthenticationJSONSerializationEnabled },
        { "WebAuthenticationLargeBlobExtension", SetWebAuthenticationLargeBlobExtensionEnabled },
        { "WebAuthenticationPRF", SetWebAuthenticationPRFEnabled },
        { "WebAuthenticationRemoteDesktopSupport", SetWebAuthenticationRemoteDesktopSupportEnabled },
        { "WebAuthenticationSupplementalPubKeys", SetWebAuthenticationSupplementalPubKeysEnabled },
        { "WebBluetooth", SetWebBluetoothEnabled },
        { "WebBluetoothGetDevices", SetWebBluetoothGetDevicesEnabled },
        { "WebBluetoothScanning", SetWebBluetoothScanningEnabled },
        { "WebBluetoothWatchAdvertisements", SetWebBluetoothWatchAdvertisementsEnabled },
        { "WebCodecsCopyToRGB", SetWebCodecsCopyToRGBEnabled },
        { "WebCodecsHBDFormats", SetWebCodecsHBDFormatsEnabled },
        { "WebCodecsOrientation", SetWebCodecsOrientationEnabled },
        { "WebCodecsVideoEncoderBuffers", SetWebCodecsVideoEncoderBuffersEnabled },
        { "WebCryptoCurve25519", SetWebCryptoCurve25519Enabled },
        { "WebFontResizeLCP", SetWebFontResizeLCPEnabled },
        { "WebGLDeveloperExtensions", SetWebGLDeveloperExtensionsEnabled },
        { "WebGLDraftExtensions", SetWebGLDraftExtensionsEnabled },
        { "WebGLDrawingBufferStorage", SetWebGLDrawingBufferStorageEnabled },
        { "WebGLImageChromium", SetWebGLImageChromiumEnabled },
        { "WebGPUCanvasContextGetConfiguration", SetWebGPUCanvasContextGetConfigurationEnabled },
        { "WebGPUDeveloperFeatures", SetWebGPUDeveloperFeaturesEnabled },
        { "WebGPUDeviceAdapterInfo", SetWebGPUDeviceAdapterInfoEnabled },
        { "WebGPUExperimentalFeatures", SetWebGPUExperimentalFeaturesEnabled },
        { "WebGPUHDR", SetWebGPUHDREnabled },
        { "WebGPUSubgroupsFeatures", SetWebGPUSubgroupsFeaturesEnabled },
        { "WebGPUTextureViewUsage", SetWebGPUTextureViewUsageEnabled },
        { "WebHID", SetWebHIDEnabled },
        { "WebHIDOnDedicatedWorkers", SetWebHIDOnDedicatedWorkersEnabled },
        { "WebHIDOnServiceWorkers", SetWebHIDOnServiceWorkersEnabled },
        { "WebIDLBigIntUsesToBigInt", SetWebIDLBigIntUsesToBigIntEnabled },
        { "WebIdentityDigitalCredentials", SetWebIdentityDigitalCredentialsEnabled },
        { "WebNFC", SetWebNFCEnabled },
        { "WebOTP", SetWebOTPEnabled },
        { "WebOTPAssertionFeaturePolicy", SetWebOTPAssertionFeaturePolicyEnabled },
        { "WebPreferences", SetWebPreferencesEnabled },
        { "WebPrinting", SetWebPrintingEnabled },
        { "WebShare", SetWebShareEnabled },
        { "WebSocketStream", SetWebSocketStreamEnabled },
        { "WebTransportCustomCertificates", SetWebTransportCustomCertificatesEnabled },
        { "WebTransportStats", SetWebTransportStatsEnabled },
        { "WebUSB", SetWebUSBEnabled },
        { "WebUSBOnDedicatedWorkers", SetWebUSBOnDedicatedWorkersEnabled },
        { "WebUSBOnServiceWorkers", SetWebUSBOnServiceWorkersEnabled },
        { "WebVTTRegions", SetWebVTTRegionsEnabled },
        { "WebViewXRequestedWithDeprecation", SetWebViewXRequestedWithDeprecationEnabled },
        { "WebXR", SetWebXREnabled },
        { "WebXREnabledFeatures", SetWebXREnabledFeaturesEnabled },
        { "WebXRFrameRate", SetWebXRFrameRateEnabled },
        { "WebXRFrontFacing", SetWebXRFrontFacingEnabled },
        { "WebXRGPUBinding", SetWebXRGPUBindingEnabled },
        { "WebXRHandInput", SetWebXRHandInputEnabled },
        { "WebXRHitTestEntityTypes", SetWebXRHitTestEntityTypesEnabled },
        { "WebXRImageTracking", SetWebXRImageTrackingEnabled },
        { "WebXRLayers", SetWebXRLayersEnabled },
        { "WebXRLayersCommon", SetWebXRLayersCommonEnabled },
        { "WebXRPlaneDetection", SetWebXRPlaneDetectionEnabled },
        { "WebXRPoseMotionData", SetWebXRPoseMotionDataEnabled },
        { "WebXRSpecParity", SetWebXRSpecParityEnabled },
        { "WindowDefaultStatus", SetWindowDefaultStatusEnabled },
        { "XMLParserMergeAdjacentCDataSections", SetXMLParserMergeAdjacentCDataSectionsEnabled },
        { "ZeroCopyTabCapture", SetZeroCopyTabCaptureEnabled },
    };

    auto feature
        = std::lower_bound(std::begin(kFeatures), std::end(kFeatures), name, [](const auto& feature, const std::string& name) { return feature.name < name; });

    if (feature != std::end(kFeatures) && feature->name == name)
        feature->SetFunction(enable);
    else
        DLOG(ERROR) << "RuntimeEnabledFeature not recognized: " << name;
}

bool RuntimeEnabledFeaturesBase::IsFeatureEnabledFromString(const std::string& name)
{
    static const struct {
        const char* name;
        bool (*GetFunction)();
    } kFeatures[] = {
        { "AIPromptAPI", AIPromptAPIEnabled },
        { "AIPromptAPIForWebPlatform", AIPromptAPIForWebPlatformEnabled },
        { "AIRewriterAPI", AIRewriterAPIEnabled },
        { "AIWriterAPI", AIWriterAPIEnabled },
        { "AOMAriaRelationshipProperties", AOMAriaRelationshipPropertiesEnabled },
        { "AOMAriaRelationshipPropertiesAriaOwns", AOMAriaRelationshipPropertiesAriaOwnsEnabled },
        { "Accelerated2dCanvas", Accelerated2dCanvasEnabled },
        { "AcceleratedSmallCanvases", AcceleratedSmallCanvasesEnabled },
        { "AccessibilityAriaVirtualContent", AccessibilityAriaVirtualContentEnabled },
        { "AccessibilityExposeDisplayNone", AccessibilityExposeDisplayNoneEnabled },
        { "AccessibilityMinRoleTabbable", AccessibilityMinRoleTabbableEnabled },
        { "AccessibilityOSLevelBoldText", AccessibilityOSLevelBoldTextEnabled },
        { "AccessibilityProhibitedNames", AccessibilityProhibitedNamesEnabled },
        { "AccessibilitySerializationSizeMetrics", AccessibilitySerializationSizeMetricsEnabled },
        { "AccessibilityUseAXPositionForDocumentMarkers", AccessibilityUseAXPositionForDocumentMarkersEnabled },
        { "AdTagging", AdTaggingEnabled },
        { "AddressSpace", AddressSpaceEnabled },
        { "AdjustEndOfNextParagraphIfMovedParagraphIsUpdated", AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled },
        { "AllowContentInitiatedDataUrlNavigations", AllowContentInitiatedDataUrlNavigationsEnabled },
        { "AllowJavaScriptToResetAutofillState", AllowJavaScriptToResetAutofillStateEnabled },
        { "AllowPreloadingWithCSPMetaTag", AllowPreloadingWithCSPMetaTagEnabled },
        { "AllowURNsInIframes", AllowURNsInIframesEnabled },
        { "AndroidDownloadableFontsMatching", AndroidDownloadableFontsMatchingEnabled },
        { "AnimationProgressAPI", AnimationProgressAPIEnabled },
        { "AnimationWorklet", AnimationWorkletEnabled },
        { "AnonymousIframe", AnonymousIframeEnabled },
        { "AriaActions", AriaActionsEnabled },
        { "AriaNotify", AriaNotifyEnabled },
        { "AriaRowColIndexText", AriaRowColIndexTextEnabled },
        { "AtomicMoveAPI", AtomicMoveAPIEnabled },
        { "AttributionReporting", AttributionReportingEnabled },
        { "AttributionReportingCrossAppWeb", AttributionReportingCrossAppWebEnabled },
        { "AudioContextInterruptedState", AudioContextInterruptedStateEnabled },
        { "AudioContextOnError", AudioContextOnErrorEnabled },
        { "AudioContextSetSinkId", AudioContextSetSinkIdEnabled },
        { "AudioOutputDevices", AudioOutputDevicesEnabled },
        { "AudioVideoTracks", AudioVideoTracksEnabled },
        { "AuraScrollbarUsesNinePatchTrack", AuraScrollbarUsesNinePatchTrackEnabled },
        { "AuraScrollbarUsesSolidColorThumb", AuraScrollbarUsesSolidColorThumbEnabled },
        { "AutoPictureInPictureVideoHeuristics", AutoPictureInPictureVideoHeuristicsEnabled },
        { "AutomationControlled", AutomationControlledEnabled },
        { "BackForwardCache", BackForwardCacheEnabled },
        { "BackForwardTransitions", BackForwardTransitionsEnabled },
        { "BackfaceVisibilityInterop", BackfaceVisibilityInteropEnabled },
        { "BackgroundFetch", BackgroundFetchEnabled },
        { "BarcodeDetector", BarcodeDetectorEnabled },
        { "BidiCaretAffinity", BidiCaretAffinityEnabled },
        { "BlinkExtensionChromeOS", BlinkExtensionChromeOSEnabled },
        { "BlinkExtensionChromeOSKiosk", BlinkExtensionChromeOSKioskEnabled },
        { "BlinkExtensionDiagnostics", BlinkExtensionDiagnosticsEnabled },
        { "BlinkExtensionWebView", BlinkExtensionWebViewEnabled },
        { "BlinkExtensionWebViewMediaIntegrity", BlinkExtensionWebViewMediaIntegrityEnabled },
        { "BlinkLifecycleScriptForbidden", BlinkLifecycleScriptForbiddenEnabled },
        { "BlinkRuntimeCallStats", BlinkRuntimeCallStatsEnabled },
        { "BlockingFocusWithoutUserActivation", BlockingFocusWithoutUserActivationEnabled },
        { "BoundaryEventDispatchTracksNodeRemoval", BoundaryEventDispatchTracksNodeRemovalEnabled },
        { "BoxDecorationBreak", BoxDecorationBreakEnabled },
        { "BreakIteratorHyphenMinus", BreakIteratorHyphenMinusEnabled },
        { "BrowserVerifiedUserActivationKeyboard", BrowserVerifiedUserActivationKeyboardEnabled },
        { "BrowserVerifiedUserActivationMouse", BrowserVerifiedUserActivationMouseEnabled },
        { "BufferedBytesConsumerLimitSize", BufferedBytesConsumerLimitSizeEnabled },
        { "BypassPepcSecurityForTesting", BypassPepcSecurityForTestingEnabled },
        { "CCTNewRFMPushBehavior", CCTNewRFMPushBehaviorEnabled },
        { "CSSAccentColorKeyword", CSSAccentColorKeywordEnabled },
        { "CSSAdvancedAttrFunction", CSSAdvancedAttrFunctionEnabled },
        { "CSSAnchorScope", CSSAnchorScopeEnabled },
        { "CSSAnchorSizeInsetsMargins", CSSAnchorSizeInsetsMarginsEnabled },
        { "CSSAtPropertyStringSyntax", CSSAtPropertyStringSyntaxEnabled },
        { "CSSAtRuleCounterStyleImageSymbols", CSSAtRuleCounterStyleImageSymbolsEnabled },
        { "CSSAtRuleCounterStyleSpeakAsDescriptor", CSSAtRuleCounterStyleSpeakAsDescriptorEnabled },
        { "CSSBackgroundClipUnprefix", CSSBackgroundClipUnprefixEnabled },
        { "CSSCalcSimplificationAndSerialization", CSSCalcSimplificationAndSerializationEnabled },
        { "CSSCalcSizeFunction", CSSCalcSizeFunctionEnabled },
        { "CSSCaretAnimation", CSSCaretAnimationEnabled },
        { "CSSCascadeCorrectScope", CSSCascadeCorrectScopeEnabled },
        { "CSSCaseSensitiveSelector", CSSCaseSensitiveSelectorEnabled },
        { "CSSColorContrast", CSSColorContrastEnabled },
        { "CSSColorTypedOM", CSSColorTypedOMEnabled },
        { "CSSComputedStyleFullPseudoElementParser", CSSComputedStyleFullPseudoElementParserEnabled },
        { "CSSContentVisibilityImpliesContainIntrinsicSizeAuto", CSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled },
        { "CSSCrossFade", CSSCrossFadeEnabled },
        { "CSSCustomStateDeprecatedSyntax", CSSCustomStateDeprecatedSyntaxEnabled },
        { "CSSCustomStateNewSyntax", CSSCustomStateNewSyntaxEnabled },
        { "CSSDynamicRangeLimit", CSSDynamicRangeLimitEnabled },
        { "CSSEnumeratedCustomProperties", CSSEnumeratedCustomPropertiesEnabled },
        { "CSSExponentialFunctions", CSSExponentialFunctionsEnabled },
        { "CSSFlatTreeContainer", CSSFlatTreeContainerEnabled },
        { "CSSFontSizeAdjust", CSSFontSizeAdjustEnabled },
        { "CSSFunctions", CSSFunctionsEnabled },
        { "CSSGapDecoration", CSSGapDecorationEnabled },
        { "CSSHexAlphaColor", CSSHexAlphaColorEnabled },
        { "CSSInert", CSSInertEnabled },
        { "CSSInsetAreaProperty", CSSInsetAreaPropertyEnabled },
        { "CSSKeyframesRuleLength", CSSKeyframesRuleLengthEnabled },
        { "CSSLayoutAPI", CSSLayoutAPIEnabled },
        { "CSSLazyParsingFastPath", CSSLazyParsingFastPathEnabled },
        { "CSSLineClamp", CSSLineClampEnabled },
        { "CSSLineClampWebkitBoxBlockification", CSSLineClampWebkitBoxBlockificationEnabled },
        { "CSSLogicalOverflow", CSSLogicalOverflowEnabled },
        { "CSSMarkerNestedPseudoElement", CSSMarkerNestedPseudoElementEnabled },
        { "CSSMasonryLayout", CSSMasonryLayoutEnabled },
        { "CSSMixins", CSSMixinsEnabled },
        { "CSSNestedDeclarations", CSSNestedDeclarationsEnabled },
        { "CSSNestedPseudoElements", CSSNestedPseudoElementsEnabled },
        { "CSSOverflowContainerQueries", CSSOverflowContainerQueriesEnabled },
        { "CSSPaintAPIArguments", CSSPaintAPIArgumentsEnabled },
        { "CSSParserIgnoreCharsetForURLs", CSSParserIgnoreCharsetForURLsEnabled },
        { "CSSPartAllowsMoreSelectorsAfter", CSSPartAllowsMoreSelectorsAfterEnabled },
        { "CSSPositionAreaValue", CSSPositionAreaValueEnabled },
        { "CSSPositionStickyStaticScrollPosition", CSSPositionStickyStaticScrollPositionEnabled },
        { "CSSProgressNotation", CSSProgressNotationEnabled },
        { "CSSPseudoColumn", CSSPseudoColumnEnabled },
        { "CSSPseudoHasSlotted", CSSPseudoHasSlottedEnabled },
        { "CSSPseudoOpenClosed", CSSPseudoOpenClosedEnabled },
        { "CSSPseudoPlayingPaused", CSSPseudoPlayingPausedEnabled },
        { "CSSPseudoScrollButtons", CSSPseudoScrollButtonsEnabled },
        { "CSSPseudoScrollMarkers", CSSPseudoScrollMarkersEnabled },
        { "CSSReadingFlow", CSSReadingFlowEnabled },
        { "CSSRelativeColor", CSSRelativeColorEnabled },
        { "CSSRelativeColorLateResolveAlways", CSSRelativeColorLateResolveAlwaysEnabled },
        { "CSSRelativeColorPreserveNone", CSSRelativeColorPreserveNoneEnabled },
        { "CSSRelativeColorSupportsCurrentcolor", CSSRelativeColorSupportsCurrentcolorEnabled },
        { "CSSResizeAuto", CSSResizeAutoEnabled },
        { "CSSScrollSnapChangeEvent", CSSScrollSnapChangeEventEnabled },
        { "CSSScrollSnapChangingEvent", CSSScrollSnapChangingEventEnabled },
        { "CSSScrollSnapEvents", CSSScrollSnapEventsEnabled },
        { "CSSScrollStart", CSSScrollStartEnabled },
        { "CSSScrollStartTarget", CSSScrollStartTargetEnabled },
        { "CSSScrollStateContainerQueries", CSSScrollStateContainerQueriesEnabled },
        { "CSSSelectorFragmentAnchor", CSSSelectorFragmentAnchorEnabled },
        { "CSSSignRelatedFunctions", CSSSignRelatedFunctionsEnabled },
        { "CSSSnapContainerQueries", CSSSnapContainerQueriesEnabled },
        { "CSSSteppedValueFunctions", CSSSteppedValueFunctionsEnabled },
        { "CSSStickyContainerQueries", CSSStickyContainerQueriesEnabled },
        { "CSSSupportsAtRuleFunction", CSSSupportsAtRuleFunctionEnabled },
        { "CSSSupportsForImportRules", CSSSupportsForImportRulesEnabled },
        { "CSSSystemAccentColor", CSSSystemAccentColorEnabled },
        { "CSSTextAutoSpace", CSSTextAutoSpaceEnabled },
        { "CSSTextBoxTrim", CSSTextBoxTrimEnabled },
        { "CSSTextSpacing", CSSTextSpacingEnabled },
        { "CSSTreeScopedTimelines", CSSTreeScopedTimelinesEnabled },
        { "CSSUserSelectContain", CSSUserSelectContainEnabled },
        { "CSSVideoDynamicRangeMediaQueries", CSSVideoDynamicRangeMediaQueriesEnabled },
        { "CSSViewTransitionAutoName", CSSViewTransitionAutoNameEnabled },
        { "CSSViewTransitionClass", CSSViewTransitionClassEnabled },
        { "CalendarPickerMonthPopupButtonDisabledColor", CalendarPickerMonthPopupButtonDisabledColorEnabled },
        { "CallExitNodeWithoutLayoutObject", CallExitNodeWithoutLayoutObjectEnabled },
        { "Canvas2dCanvasFilter", Canvas2dCanvasFilterEnabled },
        { "Canvas2dGPUTransfer", Canvas2dGPUTransferEnabled },
        { "Canvas2dImageChromium", Canvas2dImageChromiumEnabled },
        { "Canvas2dLayers", Canvas2dLayersEnabled },
        { "Canvas2dLayersWithOptions", Canvas2dLayersWithOptionsEnabled },
        { "Canvas2dTextMetricsShaping", Canvas2dTextMetricsShapingEnabled },
        { "CanvasFloatingPoint", CanvasFloatingPointEnabled },
        { "CanvasHDR", CanvasHDREnabled },
        { "CanvasImageSmoothing", CanvasImageSmoothingEnabled },
        { "CanvasPlaceElement", CanvasPlaceElementEnabled },
        { "CanvasUsesArcPaintOp", CanvasUsesArcPaintOpEnabled },
        { "CapabilityDelegationDisplayCaptureRequest", CapabilityDelegationDisplayCaptureRequestEnabled },
        { "CaptureController", CaptureControllerEnabled },
        { "CaptureHandle", CaptureHandleEnabled },
        { "CapturedMouseEvents", CapturedMouseEventsEnabled },
        { "CaretPositionFromPoint", CaretPositionFromPointEnabled },
        { "CheckIfHighestRootContainsPositionAnchorNode", CheckIfHighestRootContainsPositionAnchorNodeEnabled },
        { "CheckVisibilityExtraProperties", CheckVisibilityExtraPropertiesEnabled },
        { "ClickToCapturedPointer", ClickToCapturedPointerEnabled },
        { "ClipPathRejectEmptyPaths", ClipPathRejectEmptyPathsEnabled },
        { "ClipboardItemWithDOMStringSupport", ClipboardItemWithDOMStringSupportEnabled },
        { "CoalesceSelectionchangeEvent", CoalesceSelectionchangeEventEnabled },
        { "CoepReflection", CoepReflectionEnabled },
        { "CompositeBGColorAnimation", CompositeBGColorAnimationEnabled },
        { "CompositeBoxShadowAnimation", CompositeBoxShadowAnimationEnabled },
        { "CompositeClipPathAnimation", CompositeClipPathAnimationEnabled },
        { "CompositedAnimationsCancelledAsynchronously", CompositedAnimationsCancelledAsynchronouslyEnabled },
        { "CompositedSelectionUpdate", CompositedSelectionUpdateEnabled },
        { "CompositionForegroundMarkers", CompositionForegroundMarkersEnabled },
        { "CompressionDictionaryTransport", CompressionDictionaryTransportEnabled },
        { "CompressionDictionaryTransportBackend", CompressionDictionaryTransportBackendEnabled },
        { "ComputePressure", ComputePressureEnabled },
        { "ComputedAccessibilityInfo", ComputedAccessibilityInfoEnabled },
        { "ConcurrentViewTransitionsSPA", ConcurrentViewTransitionsSPAEnabled },
        { "ContactsManager", ContactsManagerEnabled },
        { "ContactsManagerExtraProperties", ContactsManagerExtraPropertiesEnabled },
        { "ContainerTypeNoLayoutContainment", ContainerTypeNoLayoutContainmentEnabled },
        { "ContentIndex", ContentIndexEnabled },
        { "ContextMenu", ContextMenuEnabled },
        { "ContinueEventTimingRecordingWhenBufferIsFull", ContinueEventTimingRecordingWhenBufferIsFullEnabled },
        { "ControlledFrame", ControlledFrameEnabled },
        { "CookieDeprecationFacilitatedTesting", CookieDeprecationFacilitatedTestingEnabled },
        { "CooperativeScheduling", CooperativeSchedulingEnabled },
        { "CorsRFC1918", CorsRFC1918Enabled },
        { "CreateInputShadowTreeDuringLayout", CreateInputShadowTreeDuringLayoutEnabled },
        { "CredentialManagerReport", CredentialManagerReportEnabled },
        { "CrossFramePerformanceTimeline", CrossFramePerformanceTimelineEnabled },
        { "CursorAnchorInfoMojoPipe", CursorAnchorInfoMojoPipeEnabled },
        { "CustomizableSelect", CustomizableSelectEnabled },
        { "DOMPartsAPI", DOMPartsAPIEnabled },
        { "DOMPartsAPIMinimal", DOMPartsAPIMinimalEnabled },
        { "DeprecatedRequestAdapterInfo", DeprecatedRequestAdapterInfoEnabled },
        { "DesktopCaptureDisableLocalEchoControl", DesktopCaptureDisableLocalEchoControlEnabled },
        { "DesktopPWAsAdditionalWindowingControls", DesktopPWAsAdditionalWindowingControlsEnabled },
        { "DesktopPWAsSubApps", DesktopPWAsSubAppsEnabled },
        { "DetailsStyling", DetailsStylingEnabled },
        { "DeviceAttributes", DeviceAttributesEnabled },
        { "DeviceOrientationRequestPermission", DeviceOrientationRequestPermissionEnabled },
        { "DevicePosture", DevicePostureEnabled },
        { "DialogCloseWhenOpenRemoved", DialogCloseWhenOpenRemovedEnabled },
        { "DialogElementToggleEvents", DialogElementToggleEventsEnabled },
        { "DialogNewFocusBehavior", DialogNewFocusBehaviorEnabled },
        { "DigitalGoodsV2_1", DigitalGoodsV2_1Enabled },
        { "DirAutoFixSlotExclusions", DirAutoFixSlotExclusionsEnabled },
        { "DirectSockets", DirectSocketsEnabled },
        { "DisableAhemAntialias", DisableAhemAntialiasEnabled },
        { "DisableSelectAllForEmptyText", DisableSelectAllForEmptyTextEnabled },
        { "DispatchBeforeInputForSpinButtonInteractions", DispatchBeforeInputForSpinButtonInteractionsEnabled },
        { "DispatchHiddenVisibilityTransitions", DispatchHiddenVisibilityTransitionsEnabled },
        { "DispatchSelectionchangeEventPerElement", DispatchSelectionchangeEventPerElementEnabled },
        { "DisplayContentsFocusable", DisplayContentsFocusableEnabled },
        { "DisplayCutoutAPI", DisplayCutoutAPIEnabled },
        { "DocumentCookie", DocumentCookieEnabled },
        { "DocumentDomain", DocumentDomainEnabled },
        { "DocumentInstallChunking", DocumentInstallChunkingEnabled },
        { "DocumentOpenOriginAliasRemoval", DocumentOpenOriginAliasRemovalEnabled },
        { "DocumentOpenSandboxInheritanceRemoval", DocumentOpenSandboxInheritanceRemovalEnabled },
        { "DocumentPictureInPictureAPI", DocumentPictureInPictureAPIEnabled },
        { "DocumentPictureInPicturePreferInitialPlacement", DocumentPictureInPicturePreferInitialPlacementEnabled },
        { "DocumentPictureInPictureUserActivation", DocumentPictureInPictureUserActivationEnabled },
        { "DocumentPolicyDocumentDomain", DocumentPolicyDocumentDomainEnabled },
        { "DocumentPolicyExpectNoLinkedResources", DocumentPolicyExpectNoLinkedResourcesEnabled },
        { "DocumentPolicySyncXHR", DocumentPolicySyncXHREnabled },
        { "DocumentRenderBlocking", DocumentRenderBlockingEnabled },
        { "DocumentWrite", DocumentWriteEnabled },
        { "DropUrlAsPlainTextInPlainTextOnlyEditablePosition", DropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled },
        { "DynamicSafeAreaInsets", DynamicSafeAreaInsetsEnabled },
        { "DynamicSafeAreaInsetsOnScroll", DynamicSafeAreaInsetsOnScrollEnabled },
        { "ElementCapture", ElementCaptureEnabled },
        { "ElementGetInnerHTML", ElementGetInnerHTMLEnabled },
        { "EnforceAnonymityExposure", EnforceAnonymityExposureEnabled },
        { "EscapeLtGtInAttributes", EscapeLtGtInAttributesEnabled },
        { "EventTimingHandleKeyboardEventSimulatedClick", EventTimingHandleKeyboardEventSimulatedClickEnabled },
        { "EventTimingInteractionCount", EventTimingInteractionCountEnabled },
        { "EventTimingSelectionAutoScrollNoInteractionId", EventTimingSelectionAutoScrollNoInteractionIdEnabled },
        { "EventTimingTapStopScrollNoInteractionId", EventTimingTapStopScrollNoInteractionIdEnabled },
        { "ExcludeTransparentTextsFromBeingLcpEligible", ExcludeTransparentTextsFromBeingLcpEligibleEnabled },
        { "ExperimentalContentSecurityPolicyFeatures", ExperimentalContentSecurityPolicyFeaturesEnabled },
        { "ExperimentalJSProfilerMarkers", ExperimentalJSProfilerMarkersEnabled },
        { "ExperimentalMachineLearningNeuralNetwork", ExperimentalMachineLearningNeuralNetworkEnabled },
        { "ExperimentalPolicies", ExperimentalPoliciesEnabled },
        { "ExposeCoarsenedRenderTime", ExposeCoarsenedRenderTimeEnabled },
        { "ExposeRenderTimeNonTaoDelayedImage", ExposeRenderTimeNonTaoDelayedImageEnabled },
        { "ExtendedTextMetrics", ExtendedTextMetricsEnabled },
        { "EyeDropperAPI", EyeDropperAPIEnabled },
        { "FaceDetector", FaceDetectorEnabled },
        { "FastNonCompositedScrollHitTest", FastNonCompositedScrollHitTestEnabled },
        { "FastPathSingleSelectorExactMatch", FastPathSingleSelectorExactMatchEnabled },
        { "FastPositionIterator", FastPositionIteratorEnabled },
        { "FedCm", FedCmEnabled },
        { "FedCmAutoSelectedFlag", FedCmAutoSelectedFlagEnabled },
        { "FedCmDisconnect", FedCmDisconnectEnabled },
        { "FedCmDomainHint", FedCmDomainHintEnabled },
        { "FedCmError", FedCmErrorEnabled },
        { "FedCmIdPRegistration", FedCmIdPRegistrationEnabled },
        { "FedCmIdpSigninStatus", FedCmIdpSigninStatusEnabled },
        { "FedCmSelectiveDisclosure", FedCmSelectiveDisclosureEnabled },
        { "FencedFrames", FencedFramesEnabled },
        { "FencedFramesAPIChanges", FencedFramesAPIChangesEnabled },
        { "FencedFramesDefaultMode", FencedFramesDefaultModeEnabled },
        { "FencedFramesLocalUnpartitionedDataAccess", FencedFramesLocalUnpartitionedDataAccessEnabled },
        { "FetchBodyBytes", FetchBodyBytesEnabled },
        { "FetchUploadStreaming", FetchUploadStreamingEnabled },
        { "FileHandling", FileHandlingEnabled },
        { "FileHandlingIcons", FileHandlingIconsEnabled },
        { "FileSystem", FileSystemEnabled },
        { "FileSystemAccess", FileSystemAccessEnabled },
        { "FileSystemAccessAPIExperimental", FileSystemAccessAPIExperimentalEnabled },
        { "FileSystemAccessGetCloudIdentifiers", FileSystemAccessGetCloudIdentifiersEnabled },
        { "FileSystemAccessLocal", FileSystemAccessLocalEnabled },
        { "FileSystemAccessLockingScheme", FileSystemAccessLockingSchemeEnabled },
        { "FileSystemAccessOriginPrivate", FileSystemAccessOriginPrivateEnabled },
        { "FileSystemObserverUnobserve", FileSystemObserverUnobserveEnabled },
        { "FindDecomposedInShortText", FindDecomposedInShortTextEnabled },
        { "FindRubyInPage", FindRubyInPageEnabled },
        { "FindTextInReadonlyTextInput", FindTextInReadonlyTextInputEnabled },
        { "FindTextSkipCollapsedText", FindTextSkipCollapsedTextEnabled },
        { "Fledge", FledgeEnabled },
        { "FledgeAuctionDealSupport", FledgeAuctionDealSupportEnabled },
        { "FledgeCustomMaxAuctionAdComponents", FledgeCustomMaxAuctionAdComponentsEnabled },
        { "FledgeDeprecatedRenderURLReplacements", FledgeDeprecatedRenderURLReplacementsEnabled },
        { "FledgeDirectFromSellerSignalsHeaderAdSlot", FledgeDirectFromSellerSignalsHeaderAdSlotEnabled },
        { "FledgeMultiBid", FledgeMultiBidEnabled },
        { "FledgeRealTimeReporting", FledgeRealTimeReportingEnabled },
        { "FledgeReportingTimeout", FledgeReportingTimeoutEnabled },
        { "FledgeSellerNonce", FledgeSellerNonceEnabled },
        { "FledgeTrustedSignalsKVv2Support", FledgeTrustedSignalsKVv2SupportEnabled },
        { "FluentOverlayScrollbars", FluentOverlayScrollbarsEnabled },
        { "FluentScrollbarUsesNinePatchTrack", FluentScrollbarUsesNinePatchTrackEnabled },
        { "FluentScrollbars", FluentScrollbarsEnabled },
        { "FontAccess", FontAccessEnabled },
        { "FontFamilyPostscriptMatchingCTMigration", FontFamilyPostscriptMatchingCTMigrationEnabled },
        { "FontFamilyStyleMatchingCTMigration", FontFamilyStyleMatchingCTMigrationEnabled },
        { "FontPresentWin", FontPresentWinEnabled },
        { "FontSrcLocalMatching", FontSrcLocalMatchingEnabled },
        { "FontSystemFallbackNotoCjk", FontSystemFallbackNotoCjkEnabled },
        { "FontVariantEmoji", FontVariantEmojiEnabled },
        { "FontVariationSequences", FontVariationSequencesEnabled },
        { "FontationsFontBackend", FontationsFontBackendEnabled },
        { "FontationsForSelectedFormats", FontationsForSelectedFormatsEnabled },
        { "ForceEagerMeasureMemory", ForceEagerMeasureMemoryEnabled },
        { "ForceReduceMotion", ForceReduceMotionEnabled },
        { "ForceTallerSelectPopup", ForceTallerSelectPopupEnabled },
        { "ForcedColors", ForcedColorsEnabled },
        { "ForcedColorsPreserveParentColor", ForcedColorsPreserveParentColorEnabled },
        { "FormControlRestoreStateIfAutocompleteOff", FormControlRestoreStateIfAutocompleteOffEnabled },
        { "FormControlsVerticalWritingModeDirectionSupport", FormControlsVerticalWritingModeDirectionSupportEnabled },
        { "FractionalScrollOffsets", FractionalScrollOffsetsEnabled },
        { "FreezeFramesOnVisibility", FreezeFramesOnVisibilityEnabled },
        { "GamepadMultitouch", GamepadMultitouchEnabled },
        { "GetDisplayMedia", GetDisplayMediaEnabled },
        { "GetDisplayMediaRequiresUserActivation", GetDisplayMediaRequiresUserActivationEnabled },
        { "GroupEffect", GroupEffectEnabled },
        { "HTMLAnchorAttribute", HTMLAnchorAttributeEnabled },
        { "HTMLDialogLightDismiss", HTMLDialogLightDismissEnabled },
        { "HTMLEmbedElementNotForceLayout", HTMLEmbedElementNotForceLayoutEnabled },
        { "HTMLInterestTargetAttribute", HTMLInterestTargetAttributeEnabled },
        { "HTMLInvokeActionsV2", HTMLInvokeActionsV2Enabled },
        { "HTMLInvokeTargetAttribute", HTMLInvokeTargetAttributeEnabled },
        { "HTMLObjectElementFallbackDetachContentFrame", HTMLObjectElementFallbackDetachContentFrameEnabled },
        { "HTMLParserYieldAndDelayOftenForTesting", HTMLParserYieldAndDelayOftenForTestingEnabled },
        { "HTMLPopoverActionHover", HTMLPopoverActionHoverEnabled },
        { "HTMLPopoverHint", HTMLPopoverHintEnabled },
        { "HTMLSelectElementShowPicker", HTMLSelectElementShowPickerEnabled },
        { "HandleSelectionChangeOnDeletingEmptyElement", HandleSelectionChangeOnDeletingEmptyElementEnabled },
        { "HandwritingRecognition", HandwritingRecognitionEnabled },
        { "HangingWhitespaceDoesNotDependOnAlignment", HangingWhitespaceDoesNotDependOnAlignmentEnabled },
        { "HasUAVisualTransition", HasUAVisualTransitionEnabled },
        { "HighlightInheritance", HighlightInheritanceEnabled },
        { "HighlightPointerEvents", HighlightPointerEventsEnabled },
        { "HighlightsFromPoint", HighlightsFromPointEnabled },
        { "HitTestOpaqueness", HitTestOpaquenessEnabled },
        { "HitTestOpaquenessOmitLineBox", HitTestOpaquenessOmitLineBoxEnabled },
        { "ImplicitRootScroller", ImplicitRootScrollerEnabled },
        { "ImportAttributesDisallowUnknownKeys", ImportAttributesDisallowUnknownKeysEnabled },
        { "ImportMapIntegrity", ImportMapIntegrityEnabled },
        { "IncomingCallNotifications", IncomingCallNotificationsEnabled },
        { "IncrementLocalSurfaceIdForMainframeSameDocNavigation", IncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled },
        { "IndexedDbGetAllRecords", IndexedDbGetAllRecordsEnabled },
        { "InertElementNonEditable", InertElementNonEditableEnabled },
        { "InertElementNonSearchable", InertElementNonSearchableEnabled },
        { "InfiniteCullRect", InfiniteCullRectEnabled },
        { "InheritUserModifyWithoutContenteditable", InheritUserModifyWithoutContenteditableEnabled },
        { "InitialLetterRaiseBySpecified", InitialLetterRaiseBySpecifiedEnabled },
        { "InlineBlockInSameLine", InlineBlockInSameLineEnabled },
        { "InnerHTMLParserFastpathLogFailure", InnerHTMLParserFastpathLogFailureEnabled },
        { "InputClosesSelect", InputClosesSelectEnabled },
        { "InputMultipleFieldsUI", InputMultipleFieldsUIEnabled },
        { "InsertBlockquoteBeforeOuterBlock", InsertBlockquoteBeforeOuterBlockEnabled },
        { "InsertLineBreakIfPhrasingContent", InsertLineBreakIfPhrasingContentEnabled },
        { "InspectorGhostRules", InspectorGhostRulesEnabled },
        { "InstallOnDeviceSpeechRecognition", InstallOnDeviceSpeechRecognitionEnabled },
        { "InstalledApp", InstalledAppEnabled },
        { "InterestGroupsInSharedStorageWorklet", InterestGroupsInSharedStorageWorkletEnabled },
        { "InteroperablePrivateAttribution", InteroperablePrivateAttributionEnabled },
        { "IntersectionObserverScrollMargin", IntersectionObserverScrollMarginEnabled },
        { "InvertedColors", InvertedColorsEnabled },
        { "InvisibleSVGAnimationThrottling", InvisibleSVGAnimationThrottlingEnabled },
        { "KeepCSSTargetAfterReattach", KeepCSSTargetAfterReattachEnabled },
        { "KeyboardAccessibleTooltip", KeyboardAccessibleTooltipEnabled },
        { "KeyboardFocusableScrollers", KeyboardFocusableScrollersEnabled },
        { "LCPAnimatedImagesWebExposed", LCPAnimatedImagesWebExposedEnabled },
        { "LabelAndDelegatesFocusNewHandling", LabelAndDelegatesFocusNewHandlingEnabled },
        { "LangAttributeAwareFormControlUI", LangAttributeAwareFormControlUIEnabled },
        { "LayoutFlexNewRowAlgorithmV3", LayoutFlexNewRowAlgorithmV3Enabled },
        { "LayoutIgnoreMarginsForSticky", LayoutIgnoreMarginsForStickyEnabled },
        { "LayoutJustifySelfForBlocks", LayoutJustifySelfForBlocksEnabled },
        { "LayoutNGShapeCache", LayoutNGShapeCacheEnabled },
        { "LayoutStretch", LayoutStretchEnabled },
        { "LazyInitializeMediaControls", LazyInitializeMediaControlsEnabled },
        { "LazyLoadScrollMargin", LazyLoadScrollMarginEnabled },
        { "LazyLoadScrollMarginIframe", LazyLoadScrollMarginIframeEnabled },
        { "LegacyWindowsDWriteFontFallback", LegacyWindowsDWriteFontFallbackEnabled },
        { "LineBoxBelowLeadingFloats", LineBoxBelowLeadingFloatsEnabled },
        { "ListItemWithCounterSetNotSetExplicitValue", ListItemWithCounterSetNotSetExplicitValueEnabled },
        { "LockedMode", LockedModeEnabled },
        { "LongAnimationFrameTiming", LongAnimationFrameTimingEnabled },
        { "LongPressLinkSelectText", LongPressLinkSelectTextEnabled },
        { "LongTaskFromLongAnimationFrame", LongTaskFromLongAnimationFrameEnabled },
        { "MachineLearningNeuralNetwork", MachineLearningNeuralNetworkEnabled },
        { "ManagedConfiguration", ManagedConfigurationEnabled },
        { "MeasureMemory", MeasureMemoryEnabled },
        { "MediaCapabilitiesDynamicRange", MediaCapabilitiesDynamicRangeEnabled },
        { "MediaCapabilitiesEncodingInfo", MediaCapabilitiesEncodingInfoEnabled },
        { "MediaCapabilitiesSpatialAudio", MediaCapabilitiesSpatialAudioEnabled },
        { "MediaCapture", MediaCaptureEnabled },
        { "MediaCaptureCameraControls", MediaCaptureCameraControlsEnabled },
        { "MediaCaptureVoiceIsolation", MediaCaptureVoiceIsolationEnabled },
        { "MediaCastOverlayButton", MediaCastOverlayButtonEnabled },
        { "MediaControlsExpandGesture", MediaControlsExpandGestureEnabled },
        { "MediaControlsOverlayPlayButton", MediaControlsOverlayPlayButtonEnabled },
        { "MediaElementVolumeGreaterThanOne", MediaElementVolumeGreaterThanOneEnabled },
        { "MediaEngagementBypassAutoplayPolicies", MediaEngagementBypassAutoplayPoliciesEnabled },
        { "MediaLatencyHint", MediaLatencyHintEnabled },
        { "MediaPlaybackWhileNotVisiblePermissionPolicy", MediaPlaybackWhileNotVisiblePermissionPolicyEnabled },
        { "MediaQueryNavigationControls", MediaQueryNavigationControlsEnabled },
        { "MediaRecorderUseMediaVideoEncoder", MediaRecorderUseMediaVideoEncoderEnabled },
        { "MediaSession", MediaSessionEnabled },
        { "MediaSessionChapterInformation", MediaSessionChapterInformationEnabled },
        { "MediaSessionEnterPictureInPicture", MediaSessionEnterPictureInPictureEnabled },
        { "MediaSourceExperimental", MediaSourceExperimentalEnabled },
        { "MediaSourceNewAbortAndDuration", MediaSourceNewAbortAndDurationEnabled },
        { "MediaStreamTrackTransfer", MediaStreamTrackTransferEnabled },
        { "MediaStreamTrackWebSpeech", MediaStreamTrackWebSpeechEnabled },
        { "MessagePortCloseEvent", MessagePortCloseEventEnabled },
        { "MetaRefreshNoFractional", MetaRefreshNoFractionalEnabled },
        { "MeterAppearanceNoneFallbackStyle", MeterAppearanceNoneFallbackStyleEnabled },
        { "MeterDevolveAppearance", MeterDevolveAppearanceEnabled },
        { "MiddleClickAutoscroll", MiddleClickAutoscrollEnabled },
        { "MinimimalResourceRequestPrepBeforeCacheLookup", MinimimalResourceRequestPrepBeforeCacheLookupEnabled },
        { "MobileLayoutTheme", MobileLayoutThemeEnabled },
        { "ModifyParagraphCrossEditingoundary", ModifyParagraphCrossEditingoundaryEnabled },
        { "MojoJS", MojoJSEnabled },
        { "MojoJSTest", MojoJSTestEnabled },
        { "MoveEndingSelectionToListChild", MoveEndingSelectionToListChildEnabled },
        { "MoveToParagraphStartOrEndSkipsNonEditable", MoveToParagraphStartOrEndSkipsNonEditableEnabled },
        { "MultiSelectDeselectWhenOnlyOption", MultiSelectDeselectWhenOnlyOptionEnabled },
        { "MultiSmoothScrollIntoView", MultiSmoothScrollIntoViewEnabled },
        { "MultipleImportMaps", MultipleImportMapsEnabled },
        { "MutationEventsSpecialTrialMessage", MutationEventsSpecialTrialMessageEnabled },
        { "NavigateEventCommitBehavior", NavigateEventCommitBehaviorEnabled },
        { "NavigateEventSourceElement", NavigateEventSourceElementEnabled },
        { "NavigationActivation", NavigationActivationEnabled },
        { "NavigatorContentUtils", NavigatorContentUtilsEnabled },
        { "NestedViewTransition", NestedViewTransitionEnabled },
        { "NetInfoConstantType", NetInfoConstantTypeEnabled },
        { "NetInfoDownlinkMax", NetInfoDownlinkMaxEnabled },
        { "NewGetFocusableAreaBehavior", NewGetFocusableAreaBehaviorEnabled },
        { "NoIdleEncodingForWebTests", NoIdleEncodingForWebTestsEnabled },
        { "NoIncreasingEndOffsetOnSplittingTextNodes", NoIncreasingEndOffsetOnSplittingTextNodesEnabled },
        { "NonEmptyBlockquotesOnOutdenting", NonEmptyBlockquotesOnOutdentingEnabled },
        { "NonNullInputEventDataForTextArea", NonNullInputEventDataForTextAreaEnabled },
        { "NonStandardAppearanceValueSliderVertical", NonStandardAppearanceValueSliderVerticalEnabled },
        { "NotificationConstructor", NotificationConstructorEnabled },
        { "NotificationContentImage", NotificationContentImageEnabled },
        { "Notifications", NotificationsEnabled },
        { "ObservableAPI", ObservableAPIEnabled },
        { "OffMainThreadCSSPaint", OffMainThreadCSSPaintEnabled },
        { "OffscreenCanvasCommit", OffscreenCanvasCommitEnabled },
        { "OmitBlurEventOnElementRemoval", OmitBlurEventOnElementRemovalEnabled },
        { "OnDeviceChange", OnDeviceChangeEnabled },
        { "OnDeviceWebSpeechAvailable", OnDeviceWebSpeechAvailableEnabled },
        { "OrientationEvent", OrientationEventEnabled },
        { "OriginIsolationHeader", OriginIsolationHeaderEnabled },
        { "OriginPolicy", OriginPolicyEnabled },
        { "OverscrollCustomization", OverscrollCustomizationEnabled },
        { "PageMarginBoxes", PageMarginBoxesEnabled },
        { "PagePopup", PagePopupEnabled },
        { "PageRevealEvent", PageRevealEventEnabled },
        { "PageSwapEvent", PageSwapEventEnabled },
        { "PaintHighlightsForFirstLetter", PaintHighlightsForFirstLetterEnabled },
        { "PaintHoldingForIframes", PaintHoldingForIframesEnabled },
        { "PaintHoldingForLocalIframes", PaintHoldingForLocalIframesEnabled },
        { "PaintUnderInvalidationChecking", PaintUnderInvalidationCheckingEnabled },
        { "PartitionVisitedLinkDatabaseWithSelfLinks", PartitionVisitedLinkDatabaseWithSelfLinksEnabled },
        { "PartitionedPopins", PartitionedPopinsEnabled },
        { "PasswordReveal", PasswordRevealEnabled },
        { "PaymentApp", PaymentAppEnabled },
        { "PaymentInstruments", PaymentInstrumentsEnabled },
        { "PaymentLinkDetection", PaymentLinkDetectionEnabled },
        { "PaymentMethodChangeEvent", PaymentMethodChangeEventEnabled },
        { "PaymentRequest", PaymentRequestEnabled },
        { "PercentBasedScrolling", PercentBasedScrollingEnabled },
        { "PerformanceManagerInstrumentation", PerformanceManagerInstrumentationEnabled },
        { "PerformanceMarkFeatureUsage", PerformanceMarkFeatureUsageEnabled },
        { "PerformanceNavigateSystemEntropy", PerformanceNavigateSystemEntropyEnabled },
        { "PerformanceNavigationTimingConfidence", PerformanceNavigationTimingConfidenceEnabled },
        { "PeriodicBackgroundSync", PeriodicBackgroundSyncEnabled },
        { "Permissions", PermissionsEnabled },
        { "PermissionsRequestRevoke", PermissionsRequestRevokeEnabled },
        { "PointerEventDeviceId", PointerEventDeviceIdEnabled },
        { "PointerEventTargetsInEventLists", PointerEventTargetsInEventListsEnabled },
        { "PopoverAnchorRelationships", PopoverAnchorRelationshipsEnabled },
        { "PopoverDialogNewFocusBehavior", PopoverDialogNewFocusBehaviorEnabled },
        { "PositionOutsideTabSpanCheckSiblingNode", PositionOutsideTabSpanCheckSiblingNodeEnabled },
        { "PreciseMemoryInfo", PreciseMemoryInfoEnabled },
        { "PreferDefaultScrollbarStyles", PreferDefaultScrollbarStylesEnabled },
        { "PreferNonCompositedScrolling", PreferNonCompositedScrollingEnabled },
        { "PrefersReducedData", PrefersReducedDataEnabled },
        { "Prerender2", Prerender2Enabled },
        { "Presentation", PresentationEnabled },
        { "PreserveFollowingBlockStylesDuringBlockMerge", PreserveFollowingBlockStylesDuringBlockMergeEnabled },
        { "PreventUndoIfNotEditable", PreventUndoIfNotEditableEnabled },
        { "PrivateAggregationApiFilteringIds", PrivateAggregationApiFilteringIdsEnabled },
        { "PrivateAggregationAuctionReportBuyerDebugModeConfig", PrivateAggregationAuctionReportBuyerDebugModeConfigEnabled },
        { "PrivateNetworkAccessNullIpAddress", PrivateNetworkAccessNullIpAddressEnabled },
        { "PrivateStateTokensAlwaysAllowIssuance", PrivateStateTokensAlwaysAllowIssuanceEnabled },
        { "PseudoElementsCorrectInGetComputedStyle", PseudoElementsCorrectInGetComputedStyleEnabled },
        { "PseudoElementsFocusable", PseudoElementsFocusableEnabled },
        { "PushMessageDataBytes", PushMessageDataBytesEnabled },
        { "PushMessaging", PushMessagingEnabled },
        { "PushMessagingSubscriptionChange", PushMessagingSubscriptionChangeEnabled },
        { "QuickIntensiveWakeUpThrottlingAfterLoading", QuickIntensiveWakeUpThrottlingAfterLoadingEnabled },
        { "RTCDataChannelPriority", RTCDataChannelPriorityEnabled },
        { "RTCEncodedAudioFrameAbsCaptureTime", RTCEncodedAudioFrameAbsCaptureTimeEnabled },
        { "RTCEncodedVideoFrameAdditionalMetadata", RTCEncodedVideoFrameAdditionalMetadataEnabled },
        { "RTCJitterBufferTarget", RTCJitterBufferTargetEnabled },
        { "RTCRtpEncodingParametersCodec", RTCRtpEncodingParametersCodecEnabled },
        { "RTCRtpScaleResolutionDownTo", RTCRtpScaleResolutionDownToEnabled },
        { "RTCRtpScriptTransform", RTCRtpScriptTransformEnabled },
        { "RTCRtpTransport", RTCRtpTransportEnabled },
        { "RTCSvcScalabilityMode", RTCSvcScalabilityModeEnabled },
        { "RasterInducingScroll", RasterInducingScrollEnabled },
        { "ReadableStreamAsyncIterable", ReadableStreamAsyncIterableEnabled },
        { "ReduceCookieIPCs", ReduceCookieIPCsEnabled },
        { "ReduceUserAgentAndroidVersionDeviceModel", ReduceUserAgentAndroidVersionDeviceModelEnabled },
        { "ReduceUserAgentMinorVersion", ReduceUserAgentMinorVersionEnabled },
        { "ReduceUserAgentPlatformOsCpu", ReduceUserAgentPlatformOsCpuEnabled },
        { "RegionCapture", RegionCaptureEnabled },
        { "RelOpenerBcgDependencyHint", RelOpenerBcgDependencyHintEnabled },
        { "RemotePlayback", RemotePlaybackEnabled },
        { "RemotePlaybackBackend", RemotePlaybackBackendEnabled },
        { "RemoveCollapsedPlaceholder", RemoveCollapsedPlaceholderEnabled },
        { "RemoveDanglingMarkupInTarget", RemoveDanglingMarkupInTargetEnabled },
        { "RemoveDataUrlInSvgUse", RemoveDataUrlInSvgUseEnabled },
        { "RemoveNodeHavingChildrenIfFullySelected", RemoveNodeHavingChildrenIfFullySelectedEnabled },
        { "RemoveVisibleSelectionInDOMSelection", RemoveVisibleSelectionInDOMSelectionEnabled },
        { "RenderBlockingInlineModuleScript", RenderBlockingInlineModuleScriptEnabled },
        { "RenderBlockingStatus", RenderBlockingStatusEnabled },
        { "RenderPriorityAttribute", RenderPriorityAttributeEnabled },
        { "ReportEventTimingAtVisibilityChange", ReportEventTimingAtVisibilityChangeEnabled },
        { "ReportVisibleLineBounds", ReportVisibleLineBoundsEnabled },
        { "ResetInputTypeToNoneBeforeCharacterInput", ResetInputTypeToNoneBeforeCharacterInputEnabled },
        { "ResourceTimingContentType", ResourceTimingContentTypeEnabled },
        { "ResourceTimingFinalResponseHeadersStart", ResourceTimingFinalResponseHeadersStartEnabled },
        { "ResourceTimingUseCORSForBodySizes", ResourceTimingUseCORSForBodySizesEnabled },
        { "RestrictGamepadAccess", RestrictGamepadAccessEnabled },
        { "ReuseShapeResultsByFonts", ReuseShapeResultsByFontsEnabled },
        { "RewindFloats", RewindFloatsEnabled },
        { "RootElementWithPlaceHolderAfterDeletingSelection", RootElementWithPlaceHolderAfterDeletingSelectionEnabled },
        { "RubyShortHeuristics", RubyShortHeuristicsEnabled },
        { "SanitizerAPI", SanitizerAPIEnabled },
        { "ScheduleSelectionChangeOnBackspace", ScheduleSelectionChangeOnBackspaceEnabled },
        { "SchedulerYield", SchedulerYieldEnabled },
        { "ScopedCustomElementRegistry", ScopedCustomElementRegistryEnabled },
        { "ScriptedSpeechRecognition", ScriptedSpeechRecognitionEnabled },
        { "ScriptedSpeechSynthesis", ScriptedSpeechSynthesisEnabled },
        { "ScrollEndEvents", ScrollEndEventsEnabled },
        { "ScrollIntoViewRootFrameViewportBugFix", ScrollIntoViewRootFrameViewportBugFixEnabled },
        { "ScrollTimeline", ScrollTimelineEnabled },
        { "ScrollTimelineCurrentTime", ScrollTimelineCurrentTimeEnabled },
        { "ScrollTopLeftInterop", ScrollTopLeftInteropEnabled },
        { "ScrollbarColor", ScrollbarColorEnabled },
        { "ScrollbarWidth", ScrollbarWidthEnabled },
        { "SearchTextHighlightPseudo", SearchTextHighlightPseudoEnabled },
        { "SecurePaymentConfirmation", SecurePaymentConfirmationEnabled },
        { "SecurePaymentConfirmationDebug", SecurePaymentConfirmationDebugEnabled },
        { "SecurePaymentConfirmationNetworkAndIssuerIcons", SecurePaymentConfirmationNetworkAndIssuerIconsEnabled },
        { "SelectAudioOutput", SelectAudioOutputEnabled },
        { "SelectOptionAccessibilityTargetSize", SelectOptionAccessibilityTargetSizeEnabled },
        { "SelectParserRelaxation", SelectParserRelaxationEnabled },
        { "SelectPopupLessUpdates", SelectPopupLessUpdatesEnabled },
        { "SelectedcontentelementAttribute", SelectedcontentelementAttributeEnabled },
        { "SelectionAcrossShadowDOM", SelectionAcrossShadowDOMEnabled },
        { "SelectionIsCollapsedShadowDOMSupport", SelectionIsCollapsedShadowDOMSupportEnabled },
        { "SelectionOnShadowDOMWithDelegatesFocus", SelectionOnShadowDOMWithDelegatesFocusEnabled },
        { "SendBeaconThrowForBlobWithNonSimpleType", SendBeaconThrowForBlobWithNonSimpleTypeEnabled },
        { "SensorExtraClasses", SensorExtraClassesEnabled },
        { "Serial", SerialEnabled },
        { "SerialPortConnected", SerialPortConnectedEnabled },
        { "SerializeViewTransitionStateInSPA", SerializeViewTransitionStateInSPAEnabled },
        { "ServiceWorkerClientLifecycleState", ServiceWorkerClientLifecycleStateEnabled },
        { "SetSequentialFocusStartingPoint", SetSequentialFocusStartingPointEnabled },
        { "ShadowRootReferenceTarget", ShadowRootReferenceTargetEnabled },
        { "ShapeOutsideWritingModeFix", ShapeOutsideWritingModeFixEnabled },
        { "ShapeResultCachedPreviousSafeToBreakOffset", ShapeResultCachedPreviousSafeToBreakOffsetEnabled },
        { "SharedArrayBuffer", SharedArrayBufferEnabled },
        { "SharedArrayBufferOnDesktop", SharedArrayBufferOnDesktopEnabled },
        { "SharedArrayBufferUnrestrictedAccessAllowed", SharedArrayBufferUnrestrictedAccessAllowedEnabled },
        { "SharedAutofill", SharedAutofillEnabled },
        { "SharedStorageAPI", SharedStorageAPIEnabled },
        { "SharedStorageAPIM118", SharedStorageAPIM118Enabled },
        { "SharedStorageAPIM125", SharedStorageAPIM125Enabled },
        { "SharedStorageWebLocks", SharedStorageWebLocksEnabled },
        { "SharedWorker", SharedWorkerEnabled },
        { "SidewaysWritingModes", SidewaysWritingModesEnabled },
        { "SiteInitiatedMirroring", SiteInitiatedMirroringEnabled },
        { "SkipAd", SkipAdEnabled },
        { "SkipTemporaryDocumentFragment", SkipTemporaryDocumentFragmentEnabled },
        { "SkipTouchEventFilter", SkipTouchEventFilterEnabled },
        { "SmartCard", SmartCardEnabled },
        { "SmartZoom", SmartZoomEnabled },
        { "SmilAutoSuspendOnLag", SmilAutoSuspendOnLagEnabled },
        { "SoftNavigationDetection", SoftNavigationDetectionEnabled },
        { "SoftNavigationHeuristicsExposeFPAndFCP", SoftNavigationHeuristicsExposeFPAndFCPEnabled },
        { "SpeakerSelection", SpeakerSelectionEnabled },
        { "SpeculationRulesPointerDownHeuristics", SpeculationRulesPointerDownHeuristicsEnabled },
        { "SpeculationRulesPointerHoverHeuristics", SpeculationRulesPointerHoverHeuristicsEnabled },
        { "SpeculationRulesPrefetchWithSubresources", SpeculationRulesPrefetchWithSubresourcesEnabled },
        { "SrcsetMaxDensity", SrcsetMaxDensityEnabled },
        { "StableBlinkFeatures", StableBlinkFeaturesEnabled },
        { "StandardizedBrowserZoom", StandardizedBrowserZoomEnabled },
        { "StaticAnimationOptimization", StaticAnimationOptimizationEnabled },
        { "StorageBuckets", StorageBucketsEnabled },
        { "StorageBucketsDurability", StorageBucketsDurabilityEnabled },
        { "StorageBucketsLocks", StorageBucketsLocksEnabled },
        { "StrictMimeTypesForWorkers", StrictMimeTypesForWorkersEnabled },
        { "StricterCellWidthContentSizeQuirk", StricterCellWidthContentSizeQuirkEnabled },
        { "StylusHandwriting", StylusHandwritingEnabled },
        { "SvgContextPaint", SvgContextPaintEnabled },
        { "SvgCrossOriginAttribute", SvgCrossOriginAttributeEnabled },
        { "SvgEagerPresAttrStyleUpdate", SvgEagerPresAttrStyleUpdateEnabled },
        { "SvgExternalResources", SvgExternalResourcesEnabled },
        { "SvgFilterUserSpaceViewportForNonSvg", SvgFilterUserSpaceViewportForNonSvgEnabled },
        { "SvgGradientColorInterpolationLinearRgbSupport", SvgGradientColorInterpolationLinearRgbSupportEnabled },
        { "SvgInlineRootPixelSnappingScaleAdjustment", SvgInlineRootPixelSnappingScaleAdjustmentEnabled },
        { "SvgNoPixelSnappingScaleAdjustment", SvgNoPixelSnappingScaleAdjustmentEnabled },
        { "SvgTransformOptimization", SvgTransformOptimizationEnabled },
        { "SynthesizedKeyboardEventsForAccessibilityActions", SynthesizedKeyboardEventsForAccessibilityActionsEnabled },
        { "SystemFallbackEmojiVSSupport", SystemFallbackEmojiVSSupportEnabled },
        { "SystemWakeLock", SystemWakeLockEnabled },
        { "TestBlinkFeatureDefault", TestBlinkFeatureDefaultEnabled },
        { "TestFeature", TestFeatureEnabled },
        { "TestFeatureDependent", TestFeatureDependentEnabled },
        { "TestFeatureImplied", TestFeatureImpliedEnabled },
        { "TestFeatureProtected", TestFeatureProtectedEnabled },
        { "TestFeatureProtectedDependent", TestFeatureProtectedDependentEnabled },
        { "TestFeatureProtectedImplied", TestFeatureProtectedImpliedEnabled },
        { "TestFeatureStable", TestFeatureStableEnabled },
        { "TextDetector", TextDetectorEnabled },
        { "TextDiffSplitFix", TextDiffSplitFixEnabled },
        { "TextFragmentAPI", TextFragmentAPIEnabled },
        { "TextFragmentTapOpensContextMenu", TextFragmentTapOpensContextMenuEnabled },
        { "TextInputNotAlwaysDirAuto", TextInputNotAlwaysDirAutoEnabled },
        { "TextMetricsBaselines", TextMetricsBaselinesEnabled },
        { "TextSegmentBoundaryForElementWithFloatStyle", TextSegmentBoundaryForElementWithFloatStyleEnabled },
        { "TextSizeAdjustImprovements", TextSizeAdjustImprovementsEnabled },
        { "TextTransformAndSecurityFix", TextTransformAndSecurityFixEnabled },
        { "TimeZoneChangeEvent", TimeZoneChangeEventEnabled },
        { "TimelineScope", TimelineScopeEnabled },
        { "TimerThrottlingForBackgroundTabs", TimerThrottlingForBackgroundTabsEnabled },
        { "TimestampBasedCLSTracking", TimestampBasedCLSTrackingEnabled },
        { "TopLayerInactiveDocumentExceptions", TopLayerInactiveDocumentExceptionsEnabled },
        { "TopicsAPI", TopicsAPIEnabled },
        { "TopicsDocumentAPI", TopicsDocumentAPIEnabled },
        { "TouchDragAndContextMenu", TouchDragAndContextMenuEnabled },
        { "TouchDragOnShortPress", TouchDragOnShortPressEnabled },
        { "TouchTextEditingRedesign", TouchTextEditingRedesignEnabled },
        { "TransferableRTCDataChannel", TransferableRTCDataChannelEnabled },
        { "TranslateService", TranslateServiceEnabled },
        { "TrustedTypeBeforePolicyCreationEvent", TrustedTypeBeforePolicyCreationEventEnabled },
        { "TrustedTypesFromLiteral", TrustedTypesFromLiteralEnabled },
        { "TrustedTypesUseCodeLike", TrustedTypesUseCodeLikeEnabled },
        { "URLPatternCompareComponent", URLPatternCompareComponentEnabled },
        { "URLSearchParamsHasAndDeleteMultipleArgs", URLSearchParamsHasAndDeleteMultipleArgsEnabled },
        { "UnclosedFormControlIsInvalid", UnclosedFormControlIsInvalidEnabled },
        { "UnexposedTaskIds", UnexposedTaskIdsEnabled },
        { "UnownedAnimationsSkipCSSEvents", UnownedAnimationsSkipCSSEventsEnabled },
        { "UnrestrictedMeasureUserAgentSpecificMemory", UnrestrictedMeasureUserAgentSpecificMemoryEnabled },
        { "UnrestrictedUsb", UnrestrictedUsbEnabled },
        { "UseBeginFramePresentationFeedback", UseBeginFramePresentationFeedbackEnabled },
        { "UseLowQualityInterpolation", UseLowQualityInterpolationEnabled },
        { "UseSelectionFocusNodeForCaretNavigation", UseSelectionFocusNodeForCaretNavigationEnabled },
        { "UseUndoStepElementDispatchBeforeInput", UseUndoStepElementDispatchBeforeInputEnabled },
        { "UserActivationSameOriginVisibility", UserActivationSameOriginVisibilityEnabled },
        { "V8IdleTasks", V8IdleTasksEnabled },
        { "VideoAutoFullscreen", VideoAutoFullscreenEnabled },
        { "VideoFrameMetadataBackgroundBlur", VideoFrameMetadataBackgroundBlurEnabled },
        { "VideoFullscreenOrientationLock", VideoFullscreenOrientationLockEnabled },
        { "VideoRotateToFullscreen", VideoRotateToFullscreenEnabled },
        { "VideoTrackGenerator", VideoTrackGeneratorEnabled },
        { "VideoTrackGeneratorInWindow", VideoTrackGeneratorInWindowEnabled },
        { "VideoTrackGeneratorInWorker", VideoTrackGeneratorInWorkerEnabled },
        { "ViewTransitionDisableSnapBrowserControlsOnHidden", ViewTransitionDisableSnapBrowserControlsOnHiddenEnabled },
        { "ViewTransitionLayeredCapture", ViewTransitionLayeredCaptureEnabled },
        { "ViewTransitionLongCallbackTimeoutForTesting", ViewTransitionLongCallbackTimeoutForTestingEnabled },
        { "ViewTransitionOnNavigation", ViewTransitionOnNavigationEnabled },
        { "ViewTransitionOnNavigationForIframes", ViewTransitionOnNavigationForIframesEnabled },
        { "ViewTransitionOverflowRectFromSurface", ViewTransitionOverflowRectFromSurfaceEnabled },
        { "ViewTransitionTreeScopedNames", ViewTransitionTreeScopedNamesEnabled },
        { "ViewTransitionTypes", ViewTransitionTypesEnabled },
        { "ViewportChangesUpdateTextAutosizing", ViewportChangesUpdateTextAutosizingEnabled },
        { "ViewportHeightClientHintHeader", ViewportHeightClientHintHeaderEnabled },
        { "VisibilityCollapseColumn", VisibilityCollapseColumnEnabled },
        { "VisualViewportOnScrollEnd", VisualViewportOnScrollEndEnabled },
        { "WakeLock", WakeLockEnabled },
        { "WarnOnContentVisibilityRenderAccess", WarnOnContentVisibilityRenderAccessEnabled },
        { "WebAnimationsSVG", WebAnimationsSVGEnabled },
        { "WebAppInstallation", WebAppInstallationEnabled },
        { "WebAppTabStrip", WebAppTabStripEnabled },
        { "WebAppTabStripCustomizations", WebAppTabStripCustomizationsEnabled },
        { "WebAppTranslations", WebAppTranslationsEnabled },
        { "WebAudioBypassOutputBuffering", WebAudioBypassOutputBufferingEnabled },
        { "WebAudioBypassOutputBufferingOptOut", WebAudioBypassOutputBufferingOptOutEnabled },
        { "WebAuth", WebAuthEnabled },
        { "WebAuthAuthenticatorAttachment", WebAuthAuthenticatorAttachmentEnabled },
        { "WebAuthenticationAmbient", WebAuthenticationAmbientEnabled },
        { "WebAuthenticationClientCapabilities", WebAuthenticationClientCapabilitiesEnabled },
        { "WebAuthenticationJSONSerialization", WebAuthenticationJSONSerializationEnabled },
        { "WebAuthenticationLargeBlobExtension", WebAuthenticationLargeBlobExtensionEnabled },
        { "WebAuthenticationPRF", WebAuthenticationPRFEnabled },
        { "WebAuthenticationRemoteDesktopSupport", WebAuthenticationRemoteDesktopSupportEnabled },
        { "WebAuthenticationSupplementalPubKeys", WebAuthenticationSupplementalPubKeysEnabled },
        { "WebBluetooth", WebBluetoothEnabled },
        { "WebBluetoothGetDevices", WebBluetoothGetDevicesEnabled },
        { "WebBluetoothScanning", WebBluetoothScanningEnabled },
        { "WebBluetoothWatchAdvertisements", WebBluetoothWatchAdvertisementsEnabled },
        { "WebCodecsCopyToRGB", WebCodecsCopyToRGBEnabled },
        { "WebCodecsHBDFormats", WebCodecsHBDFormatsEnabled },
        { "WebCodecsOrientation", WebCodecsOrientationEnabled },
        { "WebCodecsVideoEncoderBuffers", WebCodecsVideoEncoderBuffersEnabled },
        { "WebCryptoCurve25519", WebCryptoCurve25519Enabled },
        { "WebFontResizeLCP", WebFontResizeLCPEnabled },
        { "WebGLDeveloperExtensions", WebGLDeveloperExtensionsEnabled },
        { "WebGLDraftExtensions", WebGLDraftExtensionsEnabled },
        { "WebGLDrawingBufferStorage", WebGLDrawingBufferStorageEnabled },
        { "WebGLImageChromium", WebGLImageChromiumEnabled },
        { "WebGPUCanvasContextGetConfiguration", WebGPUCanvasContextGetConfigurationEnabled },
        { "WebGPUDeveloperFeatures", WebGPUDeveloperFeaturesEnabled },
        { "WebGPUDeviceAdapterInfo", WebGPUDeviceAdapterInfoEnabled },
        { "WebGPUExperimentalFeatures", WebGPUExperimentalFeaturesEnabled },
        { "WebGPUHDR", WebGPUHDREnabled },
        { "WebGPUTextureViewUsage", WebGPUTextureViewUsageEnabled },
        { "WebHID", WebHIDEnabled },
        { "WebHIDOnDedicatedWorkers", WebHIDOnDedicatedWorkersEnabled },
        { "WebHIDOnServiceWorkers", WebHIDOnServiceWorkersEnabled },
        { "WebIDLBigIntUsesToBigInt", WebIDLBigIntUsesToBigIntEnabled },
        { "WebNFC", WebNFCEnabled },
        { "WebOTP", WebOTPEnabled },
        { "WebOTPAssertionFeaturePolicy", WebOTPAssertionFeaturePolicyEnabled },
        { "WebPreferences", WebPreferencesEnabled },
        { "WebPrinting", WebPrintingEnabled },
        { "WebShare", WebShareEnabled },
        { "WebSocketStream", WebSocketStreamEnabled },
        { "WebTransportStats", WebTransportStatsEnabled },
        { "WebUSB", WebUSBEnabled },
        { "WebUSBOnDedicatedWorkers", WebUSBOnDedicatedWorkersEnabled },
        { "WebUSBOnServiceWorkers", WebUSBOnServiceWorkersEnabled },
        { "WebVTTRegions", WebVTTRegionsEnabled },
        { "WebXR", WebXREnabled },
        { "WebXREnabledFeatures", WebXREnabledFeaturesEnabled },
        { "WebXRFrameRate", WebXRFrameRateEnabled },
        { "WebXRFrontFacing", WebXRFrontFacingEnabled },
        { "WebXRGPUBinding", WebXRGPUBindingEnabled },
        { "WebXRHandInput", WebXRHandInputEnabled },
        { "WebXRHitTestEntityTypes", WebXRHitTestEntityTypesEnabled },
        { "WebXRLayers", WebXRLayersEnabled },
        { "WebXRLayersCommon", WebXRLayersCommonEnabled },
        { "WebXRPoseMotionData", WebXRPoseMotionDataEnabled },
        { "WebXRSpecParity", WebXRSpecParityEnabled },
        { "WindowDefaultStatus", WindowDefaultStatusEnabled },
        { "XMLParserMergeAdjacentCDataSections", XMLParserMergeAdjacentCDataSectionsEnabled },
        { "ZeroCopyTabCapture", ZeroCopyTabCaptureEnabled },
    };

    auto feature
        = std::lower_bound(std::begin(kFeatures), std::end(kFeatures), name, [](const auto& feature, const std::string& name) { return feature.name < name; });

    if (feature != std::end(kFeatures) && feature->name == name) {
        return feature->GetFunction();
    } else {
        CHECK(false) << " RuntimeEnabledFeature not recognized: " << name;
        return false;
    }
}

// static
void RuntimeEnabledFeaturesBase::UpdateStatusFromBaseFeatures()
{
    struct BaseFeatureToRuntimeFeatureMap {
        const base::Feature& feature;
        void (*enabler)(bool enable);
        bool if_overridden;
    };
    const BaseFeatureToRuntimeFeatureMap mappings[] = {
        { blink::features::kEnableAIPromptAPI, SetAIPromptAPIEnabled, false },
        { blink::features::kEnableAIPromptAPIForExtension, SetAIPromptAPIForExtensionEnabled, true },
        { blink::features::kEnableAIPromptAPIForWebPlatform, SetAIPromptAPIForWebPlatformEnabled, false },
        { blink::features::kEnableAIRewriterAPI, SetAIRewriterAPIEnabled, false },
        { blink::features::kEnableAISummarizationAPI, SetAISummarizationAPIEnabled, true },
        { blink::features::kEnableAIWriterAPI, SetAIWriterAPIEnabled, false },
        { blink::features::kAOMAriaRelationshipProperties, SetAOMAriaRelationshipPropertiesEnabled, false },
        { blink::features::kAOMAriaRelationshipPropertiesAriaOwns, SetAOMAriaRelationshipPropertiesAriaOwnsEnabled, false },
        { blink::features::kAccelerated2dCanvas, SetAccelerated2dCanvasEnabled, false },
        { blink::features::kAcceleratedSmallCanvases, SetAcceleratedSmallCanvasesEnabled, false },
        { blink::features::kAccessibilityExposeDisplayNone, SetAccessibilityExposeDisplayNoneEnabled, false },
        { blink::features::kAccessibilityMinRoleTabbable, SetAccessibilityMinRoleTabbableEnabled, false },
        { blink::features::kAccessibilityOSLevelBoldText, SetAccessibilityOSLevelBoldTextEnabled, false },
        { blink::features::kAccessibilityProhibitedNames, SetAccessibilityProhibitedNamesEnabled, false },
        { blink::features::kAccessibilitySerializationSizeMetrics, SetAccessibilitySerializationSizeMetricsEnabled, false },
        { blink::features::kAdInterestGroupAPI, SetAdInterestGroupAPIEnabled, false },
        { blink::features::kAddressSpace, SetAddressSpaceEnabled, false },
        { blink::features::kAdjustEndOfNextParagraphIfMovedParagraphIsUpdated, SetAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled, false },
        { blink::features::kAllowJavaScriptToResetAutofillState, SetAllowJavaScriptToResetAutofillStateEnabled, false },
        { blink::features::kAllowPreloadingWithCSPMetaTag, SetAllowPreloadingWithCSPMetaTagEnabled, false },
        { blink::features::kAnimationProgressAPI, SetAnimationProgressAPIEnabled, false },
        { blink::features::kAnimationWorklet, SetAnimationWorkletEnabled, false },
        { blink::features::kAnonymousIframe, SetAnonymousIframeEnabled, false },
        { blink::features::kWebAppEnableAppTitle, SetAppTitleEnabled, false },
        { blink::features::kAriaActions, SetAriaActionsEnabled, false },
        { blink::features::kAriaNotify, SetAriaNotifyEnabled, false },
        { blink::features::kAriaRowColIndexText, SetAriaRowColIndexTextEnabled, false },
        { blink::features::kAtomicMoveAPI, SetAtomicMoveAPIEnabled, false },
        { blink::features::kAudioContextInterruptedState, SetAudioContextInterruptedStateEnabled, false },
        { blink::features::kAudioContextOnError, SetAudioContextOnErrorEnabled, false },
        { blink::features::kAudioContextPlayoutStats, SetAudioContextPlayoutStatsEnabled, false },
        { blink::features::kAudioContextSetSinkId, SetAudioContextSetSinkIdEnabled, false },
        { blink::features::kAudioOutputDevices, SetAudioOutputDevicesEnabled, false },
        { blink::features::kAudioVideoTracks, SetAudioVideoTracksEnabled, false },
        { blink::features::kAuraScrollbarUsesNinePatchTrack, SetAuraScrollbarUsesNinePatchTrackEnabled, false },
        { blink::features::kAuraScrollbarUsesSolidColorThumb, SetAuraScrollbarUsesSolidColorThumbEnabled, false },
        { blink::features::kAutoPictureInPictureVideoHeuristics, SetAutoPictureInPictureVideoHeuristicsEnabled, false },
        { blink::features::kBackForwardCacheSendNotRestoredReasons, SetBackForwardCacheNotRestoredReasonsEnabled, true },
        { blink::features::kBackForwardTransitions, SetBackForwardTransitionsEnabled, false },
        { blink::features::kBackfaceVisibilityInterop, SetBackfaceVisibilityInteropEnabled, false },
        { blink::features::kBarcodeDetector, SetBarcodeDetectorEnabled, false },
        { blink::features::kBidiCaretAffinity, SetBidiCaretAffinityEnabled, false },
        { blink::features::kBlinkExtensionChromeOS, SetBlinkExtensionChromeOSEnabled, false },
        { blink::features::kBlinkExtensionChromeOSKiosk, SetBlinkExtensionChromeOSKioskEnabled, false },
        { blink::features::kBlinkExtensionWebView, SetBlinkExtensionWebViewEnabled, false },
        { blink::features::kBlinkExtensionWebViewMediaIntegrity, SetBlinkExtensionWebViewMediaIntegrityEnabled, false },
        { blink::features::kBlinkLifecycleScriptForbidden, SetBlinkLifecycleScriptForbiddenEnabled, false },
        { blink::features::kBlinkRuntimeCallStats, SetBlinkRuntimeCallStatsEnabled, false },
        { blink::features::kBlockingFocusWithoutUserActivation, SetBlockingFocusWithoutUserActivationEnabled, false },
        { blink::features::kBoundaryEventDispatchTracksNodeRemoval, SetBoundaryEventDispatchTracksNodeRemovalEnabled, false },
        { blink::features::kBoxDecorationBreak, SetBoxDecorationBreakEnabled, false },
        { blink::features::kBreakIteratorHyphenMinus, SetBreakIteratorHyphenMinusEnabled, false },
        { blink::features::kBufferedBytesConsumerLimitSize, SetBufferedBytesConsumerLimitSizeEnabled, false },
        { blink::features::kEnableBuiltInAIAPI, SetBuiltInAIAPIEnabled, true },
        { blink::features::kBypassPepcSecurityForTesting, SetBypassPepcSecurityForTestingEnabled, false },
        { blink::features::kCCTNewRFMPushBehavior, SetCCTNewRFMPushBehaviorEnabled, false },
        { blink::features::kCSSAccentColorKeyword, SetCSSAccentColorKeywordEnabled, false },
        { blink::features::kCSSAdvancedAttrFunction, SetCSSAdvancedAttrFunctionEnabled, false },
        { blink::features::kCSSAnchorScope, SetCSSAnchorScopeEnabled, false },
        { blink::features::kCSSAnchorSizeInsetsMargins, SetCSSAnchorSizeInsetsMarginsEnabled, false },
        { blink::features::kCSSAtPropertyStringSyntax, SetCSSAtPropertyStringSyntaxEnabled, false },
        { blink::features::kCSSAtRuleCounterStyleImageSymbols, SetCSSAtRuleCounterStyleImageSymbolsEnabled, false },
        { blink::features::kCSSAtRuleCounterStyleSpeakAsDescriptor, SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled, false },
        { blink::features::kCSSBackgroundClipUnprefix, SetCSSBackgroundClipUnprefixEnabled, false },
        { blink::features::kCSSCalcSimplificationAndSerialization, SetCSSCalcSimplificationAndSerializationEnabled, false },
        { blink::features::kCSSCalcSizeFunction, SetCSSCalcSizeFunctionEnabled, false },
        { blink::features::kCSSCaretAnimation, SetCSSCaretAnimationEnabled, false },
        { blink::features::kCSSCascadeCorrectScope, SetCSSCascadeCorrectScopeEnabled, false },
        { blink::features::kCSSCaseSensitiveSelector, SetCSSCaseSensitiveSelectorEnabled, false },
        { blink::features::kCSSColorContrast, SetCSSColorContrastEnabled, false },
        { blink::features::kCSSColorTypedOM, SetCSSColorTypedOMEnabled, false },
        { blink::features::kCSSComputedStyleFullPseudoElementParser, SetCSSComputedStyleFullPseudoElementParserEnabled, false },
        { blink::features::kCSSContentVisibilityImpliesContainIntrinsicSizeAuto, SetCSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled, false },
        { blink::features::kCSSCrossFade, SetCSSCrossFadeEnabled, false },
        { blink::features::kCSSCustomStateDeprecatedSyntax, SetCSSCustomStateDeprecatedSyntaxEnabled, false },
        { blink::features::kCSSCustomStateNewSyntax, SetCSSCustomStateNewSyntaxEnabled, false },
        { blink::features::kCSSDynamicRangeLimit, SetCSSDynamicRangeLimitEnabled, false },
        { blink::features::kCSSEnumeratedCustomProperties, SetCSSEnumeratedCustomPropertiesEnabled, false },
        { blink::features::kCSSExponentialFunctions, SetCSSExponentialFunctionsEnabled, false },
        { blink::features::kCSSFlatTreeContainer, SetCSSFlatTreeContainerEnabled, false },
        { blink::features::kCSSFontSizeAdjust, SetCSSFontSizeAdjustEnabled, false },
        { blink::features::kCSSFunctions, SetCSSFunctionsEnabled, false },
        { blink::features::kCSSGapDecoration, SetCSSGapDecorationEnabled, false },
        { blink::features::kCSSHexAlphaColor, SetCSSHexAlphaColorEnabled, false },
        { blink::features::kCSSInert, SetCSSInertEnabled, false },
        { blink::features::kCSSInsetAreaProperty, SetCSSInsetAreaPropertyEnabled, false },
        { blink::features::kCSSKeyframesRuleLength, SetCSSKeyframesRuleLengthEnabled, false },
        { blink::features::kCSSLayoutAPI, SetCSSLayoutAPIEnabled, false },
        { blink::features::kCSSLazyParsingFastPath, SetCSSLazyParsingFastPathEnabled, false },
        { blink::features::kCSSLineClamp, SetCSSLineClampEnabled, false },
        { blink::features::kCSSLineClampWebkitBoxBlockification, SetCSSLineClampWebkitBoxBlockificationEnabled, false },
        { blink::features::kCSSLogicalOverflow, SetCSSLogicalOverflowEnabled, false },
        { blink::features::kCSSMarkerNestedPseudoElement, SetCSSMarkerNestedPseudoElementEnabled, false },
        { blink::features::kCSSMasonryLayout, SetCSSMasonryLayoutEnabled, false },
        { blink::features::kCSSMixins, SetCSSMixinsEnabled, false },
        { blink::features::kCSSNestedDeclarations, SetCSSNestedDeclarationsEnabled, false },
        { blink::features::kCSSNestedPseudoElements, SetCSSNestedPseudoElementsEnabled, false },
        { blink::features::kCSSOverflowContainerQueries, SetCSSOverflowContainerQueriesEnabled, false },
        { blink::features::kCSSPaintAPIArguments, SetCSSPaintAPIArgumentsEnabled, false },
        { blink::features::kCSSParserIgnoreCharsetForURLs, SetCSSParserIgnoreCharsetForURLsEnabled, false },
        { blink::features::kCSSPartAllowsMoreSelectorsAfter, SetCSSPartAllowsMoreSelectorsAfterEnabled, false },
        { blink::features::kCSSPositionAreaValue, SetCSSPositionAreaValueEnabled, false },
        { blink::features::kCSSPositionStickyStaticScrollPosition, SetCSSPositionStickyStaticScrollPositionEnabled, false },
        { blink::features::kCSSProgressNotation, SetCSSProgressNotationEnabled, false },
        { blink::features::kCSSPseudoColumn, SetCSSPseudoColumnEnabled, false },
        { blink::features::kCSSPseudoHasSlotted, SetCSSPseudoHasSlottedEnabled, false },
        { blink::features::kCSSPseudoOpenClosed, SetCSSPseudoOpenClosedEnabled, false },
        { blink::features::kCSSPseudoPlayingPaused, SetCSSPseudoPlayingPausedEnabled, false },
        { blink::features::kCSSPseudoScrollButtons, SetCSSPseudoScrollButtonsEnabled, false },
        { blink::features::kCSSPseudoScrollMarkers, SetCSSPseudoScrollMarkersEnabled, false },
        { blink::features::kCSSReadingFlow, SetCSSReadingFlowEnabled, false },
        { blink::features::kCSSRelativeColor, SetCSSRelativeColorEnabled, false },
        { blink::features::kCSSRelativeColorLateResolveAlways, SetCSSRelativeColorLateResolveAlwaysEnabled, false },
        { blink::features::kCSSRelativeColorPreserveNone, SetCSSRelativeColorPreserveNoneEnabled, false },
        { blink::features::kCSSRelativeColorSupportsCurrentcolor, SetCSSRelativeColorSupportsCurrentcolorEnabled, false },
        { blink::features::kCSSResizeAuto, SetCSSResizeAutoEnabled, false },
        { blink::features::kCSSScrollSnapChangeEvent, SetCSSScrollSnapChangeEventEnabled, false },
        { blink::features::kCSSScrollSnapChangingEvent, SetCSSScrollSnapChangingEventEnabled, false },
        { blink::features::kCSSScrollSnapEvents, SetCSSScrollSnapEventsEnabled, false },
        { blink::features::kCSSScrollStart, SetCSSScrollStartEnabled, false },
        { blink::features::kCSSScrollStartTarget, SetCSSScrollStartTargetEnabled, false },
        { blink::features::kCSSScrollStateContainerQueries, SetCSSScrollStateContainerQueriesEnabled, false },
        { blink::features::kCssSelectorFragmentAnchor, SetCSSSelectorFragmentAnchorEnabled, false },
        { blink::features::kCSSSignRelatedFunctions, SetCSSSignRelatedFunctionsEnabled, false },
        { blink::features::kCSSSnapContainerQueries, SetCSSSnapContainerQueriesEnabled, false },
        { blink::features::kCSSSteppedValueFunctions, SetCSSSteppedValueFunctionsEnabled, false },
        { blink::features::kCSSStickyContainerQueries, SetCSSStickyContainerQueriesEnabled, false },
        { blink::features::kCSSSupportsAtRuleFunction, SetCSSSupportsAtRuleFunctionEnabled, false },
        { blink::features::kCSSSupportsForImportRules, SetCSSSupportsForImportRulesEnabled, false },
        { blink::features::kCSSSystemAccentColor, SetCSSSystemAccentColorEnabled, false },
        { blink::features::kCSSTextAutoSpace, SetCSSTextAutoSpaceEnabled, false },
        { blink::features::kCSSTextBoxTrim, SetCSSTextBoxTrimEnabled, false },
        { blink::features::kCSSTextSpacing, SetCSSTextSpacingEnabled, false },
        { blink::features::kCSSTreeScopedTimelines, SetCSSTreeScopedTimelinesEnabled, false },
        { blink::features::kCSSUserSelectContain, SetCSSUserSelectContainEnabled, false },
        { blink::features::kCSSVideoDynamicRangeMediaQueries, SetCSSVideoDynamicRangeMediaQueriesEnabled, false },
        { blink::features::kCSSViewTransitionAutoName, SetCSSViewTransitionAutoNameEnabled, false },
        { blink::features::kCSSViewTransitionClass, SetCSSViewTransitionClassEnabled, false },
        { blink::features::kCalendarPickerMonthPopupButtonDisabledColor, SetCalendarPickerMonthPopupButtonDisabledColorEnabled, false },
        { blink::features::kCallExitNodeWithoutLayoutObject, SetCallExitNodeWithoutLayoutObjectEnabled, false },
        { blink::features::kCanvas2dCanvasFilter, SetCanvas2dCanvasFilterEnabled, false },
        { blink::features::kCanvas2dGPUTransfer, SetCanvas2dGPUTransferEnabled, false },
        { blink::features::kCanvas2dLayers, SetCanvas2dLayersEnabled, false },
        { blink::features::kCanvas2dLayersWithOptions, SetCanvas2dLayersWithOptionsEnabled, false },
        { blink::features::kCanvas2dMesh, SetCanvas2dMeshEnabled, false },
        { blink::features::kCanvas2dTextMetricsShaping, SetCanvas2dTextMetricsShapingEnabled, false },
        { blink::features::kCanvasFloatingPoint, SetCanvasFloatingPointEnabled, false },
        { blink::features::kCanvasHDR, SetCanvasHDREnabled, false },
        { blink::features::kCanvasImageSmoothing, SetCanvasImageSmoothingEnabled, false },
        { blink::features::kCanvasPlaceElement, SetCanvasPlaceElementEnabled, false },
        { blink::features::kCanvasUsesArcPaintOp, SetCanvasUsesArcPaintOpEnabled, false },
        { blink::features::kCapabilityDelegationDisplayCaptureRequest, SetCapabilityDelegationDisplayCaptureRequestEnabled, false },
        { blink::features::kCaptureController, SetCaptureControllerEnabled, false },
        { blink::features::kCaptureHandle, SetCaptureHandleEnabled, false },
        { blink::features::kCapturedMouseEvents, SetCapturedMouseEventsEnabled, false },
        { blink::features::kCapturedSurfaceControl, SetCapturedSurfaceControlEnabled, false },
        { blink::features::kCaretPositionFromPoint, SetCaretPositionFromPointEnabled, false },
        { blink::features::kCheckIfHighestRootContainsPositionAnchorNode, SetCheckIfHighestRootContainsPositionAnchorNodeEnabled, false },
        { blink::features::kCheckVisibilityExtraProperties, SetCheckVisibilityExtraPropertiesEnabled, false },
        { blink::features::kClickToCapturedPointer, SetClickToCapturedPointerEnabled, false },
        { blink::features::kClipPathRejectEmptyPaths, SetClipPathRejectEmptyPathsEnabled, false },
        { blink::features::kClipboardItemWithDOMStringSupport, SetClipboardItemWithDOMStringSupportEnabled, false },
        { blink::features::kCoalesceSelectionchangeEvent, SetCoalesceSelectionchangeEventEnabled, false },
        { blink::features::kCoepReflection, SetCoepReflectionEnabled, false },
        { blink::features::kCompositeBoxShadowAnimation, SetCompositeBoxShadowAnimationEnabled, false },
        { blink::features::kCompositeClipPathAnimation, SetCompositeClipPathAnimationEnabled, false },
        { blink::features::kCompositedAnimationsCancelledAsynchronously, SetCompositedAnimationsCancelledAsynchronouslyEnabled, false },
        { blink::features::kCompositionForegroundMarkers, SetCompositionForegroundMarkersEnabled, false },
        { blink::features::kComputePressure, SetComputePressureEnabled, false },
        { blink::features::kComputedAccessibilityInfo, SetComputedAccessibilityInfoEnabled, false },
        { blink::features::kConcurrentViewTransitionsSPA, SetConcurrentViewTransitionsSPAEnabled, false },
        { blink::features::kContactsManager, SetContactsManagerEnabled, false },
        { blink::features::kContactsManagerExtraProperties, SetContactsManagerExtraPropertiesEnabled, false },
        { blink::features::kContainerTypeNoLayoutContainment, SetContainerTypeNoLayoutContainmentEnabled, false },
        { blink::features::kContentIndex, SetContentIndexEnabled, false },
        { blink::features::kContextMenu, SetContextMenuEnabled, false },
        { blink::features::kContinueEventTimingRecordingWhenBufferIsFull, SetContinueEventTimingRecordingWhenBufferIsFullEnabled, false },
        { blink::features::kControlledFrame, SetControlledFrameEnabled, false },
        { blink::features::kCorsRFC1918, SetCorsRFC1918Enabled, false },
        { blink::features::kCreateInputShadowTreeDuringLayout, SetCreateInputShadowTreeDuringLayoutEnabled, false },
        { blink::features::kCredentialManagerReport, SetCredentialManagerReportEnabled, false },
        { blink::features::kCrossFramePerformanceTimeline, SetCrossFramePerformanceTimelineEnabled, false },
        { blink::features::kCursorAnchorInfoMojoPipe, SetCursorAnchorInfoMojoPipeEnabled, false },
        { blink::features::kCustomizableSelect, SetCustomizableSelectEnabled, false },
        { blink::features::kDOMPartsAPI, SetDOMPartsAPIEnabled, false },
        { blink::features::kDOMPartsAPIMinimal, SetDOMPartsAPIMinimalEnabled, false },
        { blink::features::kDeprecateUnloadOptOut, SetDeprecateUnloadOptOutEnabled, false },
        { blink::features::kDeprecatedRequestAdapterInfo, SetDeprecatedRequestAdapterInfoEnabled, false },
        { blink::features::kDesktopCaptureDisableLocalEchoControl, SetDesktopCaptureDisableLocalEchoControlEnabled, false },
        { blink::features::kDesktopPWAsAdditionalWindowingControls, SetDesktopPWAsAdditionalWindowingControlsEnabled, false },
        { blink::features::kDesktopPWAsSubApps, SetDesktopPWAsSubAppsEnabled, false },
        { blink::features::kDetailsStyling, SetDetailsStylingEnabled, false },
        { blink::features::kDeviceAttributes, SetDeviceAttributesEnabled, false },
        { blink::features::kDeviceOrientationRequestPermission, SetDeviceOrientationRequestPermissionEnabled, false },
        { blink::features::kDevicePosture, SetDevicePostureEnabled, false },
        { blink::features::kDialogCloseWhenOpenRemoved, SetDialogCloseWhenOpenRemovedEnabled, false },
        { blink::features::kDialogElementToggleEvents, SetDialogElementToggleEventsEnabled, false },
        { blink::features::kDialogNewFocusBehavior, SetDialogNewFocusBehaviorEnabled, false },
        { blink::features::kDigitalGoodsV2_1, SetDigitalGoodsV2_1Enabled, false },
        { blink::features::kDirAutoFixSlotExclusions, SetDirAutoFixSlotExclusionsEnabled, false },
        { blink::features::kDirectSockets, SetDirectSocketsEnabled, false },
        { blink::features::kDisableAhemAntialias, SetDisableAhemAntialiasEnabled, false },
        { blink::features::kDisableSelectAllForEmptyText, SetDisableSelectAllForEmptyTextEnabled, false },
        { blink::features::kDispatchBeforeInputForSpinButtonInteractions, SetDispatchBeforeInputForSpinButtonInteractionsEnabled, false },
        { blink::features::kDispatchHiddenVisibilityTransitions, SetDispatchHiddenVisibilityTransitionsEnabled, false },
        { blink::features::kDispatchSelectionchangeEventPerElement, SetDispatchSelectionchangeEventPerElementEnabled, false },
        { blink::features::kDisplayContentsFocusable, SetDisplayContentsFocusableEnabled, false },
        { blink::features::kDocumentCookie, SetDocumentCookieEnabled, false },
        { blink::features::kDocumentDomain, SetDocumentDomainEnabled, false },
        { blink::features::kDocumentInstallChunking, SetDocumentInstallChunkingEnabled, false },
        { blink::features::kDocumentOpenOriginAliasRemoval, SetDocumentOpenOriginAliasRemovalEnabled, true },
        { blink::features::kDocumentOpenSandboxInheritanceRemoval, SetDocumentOpenSandboxInheritanceRemovalEnabled, true },
        { blink::features::kDocumentPictureInPictureAPI, SetDocumentPictureInPictureAPIEnabled, false },
        { blink::features::kDocumentPictureInPicturePreferInitialPlacement, SetDocumentPictureInPicturePreferInitialPlacementEnabled, false },
        { blink::features::kDocumentPictureInPictureUserActivation, SetDocumentPictureInPictureUserActivationEnabled, false },
        { blink::features::kDocumentPolicyDocumentDomain, SetDocumentPolicyDocumentDomainEnabled, false },
        { blink::features::kDocumentPolicyExpectNoLinkedResources, SetDocumentPolicyExpectNoLinkedResourcesEnabled, false },
        { blink::features::kDocumentPolicyIncludeJSCallStacksInCrashReports, SetDocumentPolicyIncludeJSCallStacksInCrashReportsEnabled, true },
        { blink::features::kDocumentPolicySyncXHR, SetDocumentPolicySyncXHREnabled, false },
        { blink::features::kDocumentRenderBlocking, SetDocumentRenderBlockingEnabled, false },
        { blink::features::kDocumentWrite, SetDocumentWriteEnabled, false },
        { blink::features::kDropUrlAsPlainTextInPlainTextOnlyEditablePosition, SetDropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled, false },
        { blink::features::kDynamicSafeAreaInsets, SetDynamicSafeAreaInsetsEnabled, false },
        { blink::features::kDynamicSafeAreaInsetsOnScroll, SetDynamicSafeAreaInsetsOnScrollEnabled, false },
        { blink::features::kElementCapture, SetElementCaptureEnabled, false },
        { blink::features::kElementGetInnerHTML, SetElementGetInnerHTMLEnabled, false },
        { blink::features::kEnforceAnonymityExposure, SetEnforceAnonymityExposureEnabled, false },
        { blink::features::kEscapeLtGtInAttributes, SetEscapeLtGtInAttributesEnabled, false },
        { blink::features::kEventTimingHandleKeyboardEventSimulatedClick, SetEventTimingHandleKeyboardEventSimulatedClickEnabled, false },
        { blink::features::kEventTimingInteractionCount, SetEventTimingInteractionCountEnabled, false },
        { blink::features::kEventTimingSelectionAutoScrollNoInteractionId, SetEventTimingSelectionAutoScrollNoInteractionIdEnabled, false },
        { blink::features::kEventTimingTapStopScrollNoInteractionId, SetEventTimingTapStopScrollNoInteractionIdEnabled, false },
        { blink::features::kExcludeTransparentTextsFromBeingLcpEligible, SetExcludeTransparentTextsFromBeingLcpEligibleEnabled, false },
        { blink::features::kExperimentalJSProfilerMarkers, SetExperimentalJSProfilerMarkersEnabled, false },
        { blink::features::kExperimentalPolicies, SetExperimentalPoliciesEnabled, false },
        { blink::features::kExposeCoarsenedRenderTime, SetExposeCoarsenedRenderTimeEnabled, false },
        { blink::features::kExposeRenderTimeNonTaoDelayedImage, SetExposeRenderTimeNonTaoDelayedImageEnabled, false },
        { blink::features::kExtendedTextMetrics, SetExtendedTextMetricsEnabled, false },
        { blink::features::kFaceDetector, SetFaceDetectorEnabled, false },
        { blink::features::kFastNonCompositedScrollHitTest, SetFastNonCompositedScrollHitTestEnabled, false },
        { blink::features::kFastPathSingleSelectorExactMatch, SetFastPathSingleSelectorExactMatchEnabled, false },
        { blink::features::kFastPositionIterator, SetFastPositionIteratorEnabled, false },
        { blink::features::kFedCmWithStorageAccessAPI, SetFedCmWithStorageAccessAPIEnabled, true },
        { blink::features::kFencedFramesAPIChanges, SetFencedFramesAPIChangesEnabled, false },
        { blink::features::kFencedFramesDefaultMode, SetFencedFramesDefaultModeEnabled, false },
        { blink::features::kFetchBodyBytes, SetFetchBodyBytesEnabled, false },
        { blink::features::kFetchLaterAPI, SetFetchLaterAPIEnabled, true },
        { blink::features::kFetchUploadStreaming, SetFetchUploadStreamingEnabled, false },
        { blink::features::kFileHandlingAPI, SetFileHandlingEnabled, false },
        { blink::features::kFileSystemAccess, SetFileSystemAccessEnabled, false },
        { blink::features::kFileSystemAccessAPIExperimental, SetFileSystemAccessAPIExperimentalEnabled, false },
        { blink::features::kFileSystemAccessGetCloudIdentifiers, SetFileSystemAccessGetCloudIdentifiersEnabled, false },
        { blink::features::kFileSystemAccessLocal, SetFileSystemAccessLocalEnabled, false },
        { blink::features::kFileSystemAccessLockingScheme, SetFileSystemAccessLockingSchemeEnabled, false },
        { blink::features::kFileSystemAccessOriginPrivate, SetFileSystemAccessOriginPrivateEnabled, false },
        { blink::features::kFileSystemObserver, SetFileSystemObserverEnabled, false },
        { blink::features::kFileSystemObserverUnobserve, SetFileSystemObserverUnobserveEnabled, false },
        { blink::features::kFindDecomposedInShortText, SetFindDecomposedInShortTextEnabled, false },
        { blink::features::kFindRubyInPage, SetFindRubyInPageEnabled, false },
        { blink::features::kFindTextInReadonlyTextInput, SetFindTextInReadonlyTextInputEnabled, false },
        { blink::features::kFindTextSkipCollapsedText, SetFindTextSkipCollapsedTextEnabled, false },
        { blink::features::kFledgeAuctionDealSupport, SetFledgeAuctionDealSupportEnabled, false },
        { blink::features::kFledgeCustomMaxAuctionAdComponents, SetFledgeCustomMaxAuctionAdComponentsEnabled, false },
        { blink::features::kFledgeDeprecatedRenderURLReplacements, SetFledgeDeprecatedRenderURLReplacementsEnabled, false },
        { blink::features::kFledgeDirectFromSellerSignalsHeaderAdSlot, SetFledgeDirectFromSellerSignalsHeaderAdSlotEnabled, false },
        { blink::features::kFledgeMultiBid, SetFledgeMultiBidEnabled, false },
        { blink::features::kFledgeRealTimeReporting, SetFledgeRealTimeReportingEnabled, false },
        { blink::features::kFledgeReportingTimeout, SetFledgeReportingTimeoutEnabled, false },
        { blink::features::kFledgeSellerNonce, SetFledgeSellerNonceEnabled, false },
        { blink::features::kFledgeTrustedSignalsKVv2Support, SetFledgeTrustedSignalsKVv2SupportEnabled, false },
        { blink::features::kFluentScrollbarUsesNinePatchTrack, SetFluentScrollbarUsesNinePatchTrackEnabled, false },
        { blink::features::kFontAccess, SetFontAccessEnabled, false },
        { blink::features::kFontFamilyPostscriptMatchingCTMigration, SetFontFamilyPostscriptMatchingCTMigrationEnabled, false },
        { blink::features::kFontFamilyStyleMatchingCTMigration, SetFontFamilyStyleMatchingCTMigrationEnabled, false },
        { blink::features::kFontPresentWin, SetFontPresentWinEnabled, false },
        { blink::features::kFontSystemFallbackNotoCjk, SetFontSystemFallbackNotoCjkEnabled, false },
        { blink::features::kFontVariantEmoji, SetFontVariantEmojiEnabled, false },
        { blink::features::kFontVariationSequences, SetFontVariationSequencesEnabled, false },
        { blink::features::kFontationsFontBackend, SetFontationsFontBackendEnabled, false },
        { blink::features::kFontationsForSelectedFormats, SetFontationsForSelectedFormatsEnabled, false },
        { blink::features::kForceEagerMeasureMemory, SetForceEagerMeasureMemoryEnabled, false },
        { blink::features::kForceReduceMotion, SetForceReduceMotionEnabled, false },
        { blink::features::kForceTallerSelectPopup, SetForceTallerSelectPopupEnabled, false },
        { blink::features::kForcedColorsPreserveParentColor, SetForcedColorsPreserveParentColorEnabled, false },
        { blink::features::kFormControlRestoreStateIfAutocompleteOff, SetFormControlRestoreStateIfAutocompleteOffEnabled, false },
        { blink::features::kFormControlsVerticalWritingModeDirectionSupport, SetFormControlsVerticalWritingModeDirectionSupportEnabled, false },
        { blink::features::kFreezeFramesOnVisibility, SetFreezeFramesOnVisibilityEnabled, false },
        { blink::features::kGamepadMultitouch, SetGamepadMultitouchEnabled, false },
        { blink::features::kGetAllScreensMedia, SetGetAllScreensMediaEnabled, false },
        { blink::features::kGetDisplayMediaRequiresUserActivation, SetGetDisplayMediaRequiresUserActivationEnabled, false },
        { blink::features::kGroupEffect, SetGroupEffectEnabled, false },
        { blink::features::kHTMLAnchorAttribute, SetHTMLAnchorAttributeEnabled, false },
        { blink::features::kHTMLDialogLightDismiss, SetHTMLDialogLightDismissEnabled, false },
        { blink::features::kHTMLEmbedElementNotForceLayout, SetHTMLEmbedElementNotForceLayoutEnabled, false },
        { blink::features::kHTMLInterestTargetAttribute, SetHTMLInterestTargetAttributeEnabled, false },
        { blink::features::kHTMLInvokeActionsV2, SetHTMLInvokeActionsV2Enabled, false },
        { blink::features::kHTMLInvokeTargetAttribute, SetHTMLInvokeTargetAttributeEnabled, false },
        { blink::features::kHTMLObjectElementFallbackDetachContentFrame, SetHTMLObjectElementFallbackDetachContentFrameEnabled, false },
        { blink::features::kHTMLParserYieldAndDelayOftenForTesting, SetHTMLParserYieldAndDelayOftenForTestingEnabled, false },
        { blink::features::kHTMLPopoverActionHover, SetHTMLPopoverActionHoverEnabled, false },
        { blink::features::kHTMLPopoverHint, SetHTMLPopoverHintEnabled, false },
        { blink::features::kHTMLSelectElementShowPicker, SetHTMLSelectElementShowPickerEnabled, false },
        { blink::features::kHandleSelectionChangeOnDeletingEmptyElement, SetHandleSelectionChangeOnDeletingEmptyElementEnabled, false },
        { blink::features::kHandwritingRecognition, SetHandwritingRecognitionEnabled, false },
        { blink::features::kHangingWhitespaceDoesNotDependOnAlignment, SetHangingWhitespaceDoesNotDependOnAlignmentEnabled, false },
        { blink::features::kHasUAVisualTransition, SetHasUAVisualTransitionEnabled, false },
        { blink::features::kHighlightInheritance, SetHighlightInheritanceEnabled, false },
        { blink::features::kHighlightPointerEvents, SetHighlightPointerEventsEnabled, false },
        { blink::features::kHighlightsFromPoint, SetHighlightsFromPointEnabled, false },
        { blink::features::kHitTestOpaqueness, SetHitTestOpaquenessEnabled, false },
        { blink::features::kHitTestOpaquenessOmitLineBox, SetHitTestOpaquenessOmitLineBoxEnabled, false },
        { blink::features::kImportAttributesDisallowUnknownKeys, SetImportAttributesDisallowUnknownKeysEnabled, false },
        { blink::features::kImportMapIntegrity, SetImportMapIntegrityEnabled, false },
        { blink::features::kIncomingCallNotifications, SetIncomingCallNotificationsEnabled, false },
        { blink::features::kIncrementLocalSurfaceIdForMainframeSameDocNavigation, SetIncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled, false },
        { blink::features::kIndexedDbGetAllRecords, SetIndexedDbGetAllRecordsEnabled, false },
        { blink::features::kInertElementNonEditable, SetInertElementNonEditableEnabled, false },
        { blink::features::kInertElementNonSearchable, SetInertElementNonSearchableEnabled, false },
        { blink::features::kInfiniteCullRect, SetInfiniteCullRectEnabled, false },
        { blink::features::kInheritUserModifyWithoutContenteditable, SetInheritUserModifyWithoutContenteditableEnabled, false },
        { blink::features::kInitialLetterRaiseBySpecified, SetInitialLetterRaiseBySpecifiedEnabled, false },
        { blink::features::kInlineBlockInSameLine, SetInlineBlockInSameLineEnabled, false },
        { blink::features::kInnerHTMLParserFastpathLogFailure, SetInnerHTMLParserFastpathLogFailureEnabled, false },
        { blink::features::kInputClosesSelect, SetInputClosesSelectEnabled, false },
        { blink::features::kInputMultipleFieldsUI, SetInputMultipleFieldsUIEnabled, false },
        { blink::features::kInsertBlockquoteBeforeOuterBlock, SetInsertBlockquoteBeforeOuterBlockEnabled, false },
        { blink::features::kInsertLineBreakIfPhrasingContent, SetInsertLineBreakIfPhrasingContentEnabled, false },
        { blink::features::kInspectorGhostRules, SetInspectorGhostRulesEnabled, false },
        { blink::features::kInstallOnDeviceSpeechRecognition, SetInstallOnDeviceSpeechRecognitionEnabled, false },
        { blink::features::kInterestGroupsInSharedStorageWorklet, SetInterestGroupsInSharedStorageWorkletEnabled, false },
        { blink::features::kInteroperablePrivateAttribution, SetInteroperablePrivateAttributionEnabled, false },
        { blink::features::kIntersectionObserverScrollMargin, SetIntersectionObserverScrollMarginEnabled, false },
        { blink::features::kInvertedColors, SetInvertedColorsEnabled, false },
        { blink::features::kInvisibleSVGAnimationThrottling, SetInvisibleSVGAnimationThrottlingEnabled, false },
        { blink::features::kJavaScriptCompileHintsMagicAlwaysRuntime, SetJavaScriptCompileHintsMagicAlwaysRuntimeEnabled, false },
        { blink::features::kJavaScriptCompileHintsMagicRuntime, SetJavaScriptCompileHintsMagicRuntimeEnabled, false },
        { blink::features::kKeepCSSTargetAfterReattach, SetKeepCSSTargetAfterReattachEnabled, false },
        { blink::features::kKeyboardFocusableScrollers, SetKeyboardFocusableScrollersEnabled, false },
        { blink::features::kKeyboardFocusableScrollersOptOut, SetKeyboardFocusableScrollersOptOutEnabled, false },
        { blink::features::kLCPAnimatedImagesWebExposed, SetLCPAnimatedImagesWebExposedEnabled, false },
        { blink::features::kLabelAndDelegatesFocusNewHandling, SetLabelAndDelegatesFocusNewHandlingEnabled, false },
        { blink::features::kLangAttributeAwareFormControlUI, SetLangAttributeAwareFormControlUIEnabled, false },
        { blink::features::kLanguageDetectionAPI, SetLanguageDetectionAPIEnabled, true },
        { blink::features::kLayoutFlexNewRowAlgorithmV3, SetLayoutFlexNewRowAlgorithmV3Enabled, false },
        { blink::features::kLayoutIgnoreMarginsForSticky, SetLayoutIgnoreMarginsForStickyEnabled, false },
        { blink::features::kLayoutJustifySelfForBlocks, SetLayoutJustifySelfForBlocksEnabled, false },
        { blink::features::kLayoutNGShapeCache, SetLayoutNGShapeCacheEnabled, false },
        { blink::features::kLayoutStretch, SetLayoutStretchEnabled, false },
        { blink::features::kLazyLoadScrollMargin, SetLazyLoadScrollMarginEnabled, false },
        { blink::features::kLazyLoadScrollMarginIframe, SetLazyLoadScrollMarginIframeEnabled, false },
        { blink::features::kLineBoxBelowLeadingFloats, SetLineBoxBelowLeadingFloatsEnabled, false },
        { blink::features::kListItemWithCounterSetNotSetExplicitValue, SetListItemWithCounterSetNotSetExplicitValueEnabled, false },
        { blink::features::kLockedMode, SetLockedModeEnabled, false },
        { blink::features::kLongAnimationFrameTiming, SetLongAnimationFrameTimingEnabled, false },
        { blink::features::kLongPressLinkSelectText, SetLongPressLinkSelectTextEnabled, false },
        { blink::features::kLongTaskFromLongAnimationFrame, SetLongTaskFromLongAnimationFrameEnabled, false },
        { blink::features::kManagedConfiguration, SetManagedConfigurationEnabled, false },
        { blink::features::kMeasureMemory, SetMeasureMemoryEnabled, false },
        { blink::features::kMediaCapabilitiesDynamicRange, SetMediaCapabilitiesDynamicRangeEnabled, false },
        { blink::features::kMediaCapabilitiesEncodingInfo, SetMediaCapabilitiesEncodingInfoEnabled, false },
        { blink::features::kMediaCapabilitiesSpatialAudio, SetMediaCapabilitiesSpatialAudioEnabled, false },
        { blink::features::kMediaCapture, SetMediaCaptureEnabled, false },
        { blink::features::kMediaCaptureCameraControls, SetMediaCaptureCameraControlsEnabled, false },
        { blink::features::kMediaCaptureVoiceIsolation, SetMediaCaptureVoiceIsolationEnabled, false },
        { blink::features::kMediaElementVolumeGreaterThanOne, SetMediaElementVolumeGreaterThanOneEnabled, false },
        { blink::features::kMediaLatencyHint, SetMediaLatencyHintEnabled, false },
        { blink::features::kMediaPlaybackWhileNotVisiblePermissionPolicy, SetMediaPlaybackWhileNotVisiblePermissionPolicyEnabled, false },
        { blink::features::kMediaQueryNavigationControls, SetMediaQueryNavigationControlsEnabled, false },
        { blink::features::kMediaRecorderUseMediaVideoEncoder, SetMediaRecorderUseMediaVideoEncoderEnabled, false },
        { blink::features::kMediaSessionChapterInformation, SetMediaSessionChapterInformationEnabled, false },
        { blink::features::kMediaSessionEnterPictureInPicture, SetMediaSessionEnterPictureInPictureEnabled, false },
        { blink::features::kMediaSourceExperimental, SetMediaSourceExperimentalEnabled, false },
        { blink::features::kMediaSourceNewAbortAndDuration, SetMediaSourceNewAbortAndDurationEnabled, false },
        { blink::features::kMediaStreamTrackWebSpeech, SetMediaStreamTrackWebSpeechEnabled, false },
        { blink::features::kMessagePortCloseEvent, SetMessagePortCloseEventEnabled, false },
        { blink::features::kMetaRefreshNoFractional, SetMetaRefreshNoFractionalEnabled, false },
        { blink::features::kMeterAppearanceNoneFallbackStyle, SetMeterAppearanceNoneFallbackStyleEnabled, false },
        { blink::features::kMeterDevolveAppearance, SetMeterDevolveAppearanceEnabled, false },
        { blink::features::kMiddleClickAutoscroll, SetMiddleClickAutoscrollEnabled, false },
        { blink::features::kMinimimalResourceRequestPrepBeforeCacheLookup, SetMinimimalResourceRequestPrepBeforeCacheLookupEnabled, false },
        { blink::features::kMobileLayoutTheme, SetMobileLayoutThemeEnabled, false },
        { blink::features::kModifyParagraphCrossEditingoundary, SetModifyParagraphCrossEditingoundaryEnabled, false },
        { blink::features::kMojoJS, SetMojoJSEnabled, false },
        { blink::features::kMoveEndingSelectionToListChild, SetMoveEndingSelectionToListChildEnabled, false },
        { blink::features::kMoveToParagraphStartOrEndSkipsNonEditable, SetMoveToParagraphStartOrEndSkipsNonEditableEnabled, false },
        { blink::features::kMultiSelectDeselectWhenOnlyOption, SetMultiSelectDeselectWhenOnlyOptionEnabled, false },
        { blink::features::kMultiSmoothScrollIntoView, SetMultiSmoothScrollIntoViewEnabled, false },
        { blink::features::kMultipleImportMaps, SetMultipleImportMapsEnabled, false },
        { blink::features::kMutationEvents, SetMutationEventsEnabled, false },
        { blink::features::kMutationEventsSpecialTrialMessage, SetMutationEventsSpecialTrialMessageEnabled, false },
        { blink::features::kNavigateEventCommitBehavior, SetNavigateEventCommitBehaviorEnabled, false },
        { blink::features::kNavigateEventSourceElement, SetNavigateEventSourceElementEnabled, false },
        { blink::features::kNavigationActivation, SetNavigationActivationEnabled, false },
        { blink::features::kNavigationId, SetNavigationIdEnabled, false },
        { blink::features::kNavigatorContentUtils, SetNavigatorContentUtilsEnabled, false },
        { blink::features::kNestedViewTransition, SetNestedViewTransitionEnabled, false },
        { blink::features::kNetInfoConstantType, SetNetInfoConstantTypeEnabled, false },
        { blink::features::kNewGetFocusableAreaBehavior, SetNewGetFocusableAreaBehaviorEnabled, false },
        { blink::features::kNoIdleEncodingForWebTests, SetNoIdleEncodingForWebTestsEnabled, false },
        { blink::features::kNoIncreasingEndOffsetOnSplittingTextNodes, SetNoIncreasingEndOffsetOnSplittingTextNodesEnabled, false },
        { blink::features::kNonEmptyBlockquotesOnOutdenting, SetNonEmptyBlockquotesOnOutdentingEnabled, false },
        { blink::features::kNonNullInputEventDataForTextArea, SetNonNullInputEventDataForTextAreaEnabled, false },
        { blink::features::kNonStandardAppearanceValueSliderVertical, SetNonStandardAppearanceValueSliderVerticalEnabled, false },
        { blink::features::kNotificationConstructor, SetNotificationConstructorEnabled, false },
        { blink::features::kObservableAPI, SetObservableAPIEnabled, false },
        { blink::features::kOffMainThreadCSSPaint, SetOffMainThreadCSSPaintEnabled, false },
        { blink::features::kOffscreenCanvasCommit, SetOffscreenCanvasCommitEnabled, false },
        { blink::features::kOmitBlurEventOnElementRemoval, SetOmitBlurEventOnElementRemovalEnabled, false },
        { blink::features::kOnDeviceChange, SetOnDeviceChangeEnabled, false },
        { blink::features::kOnDeviceWebSpeechAvailable, SetOnDeviceWebSpeechAvailableEnabled, false },
        { blink::features::kOrientationEvent, SetOrientationEventEnabled, false },
        { blink::features::kOriginPolicy, SetOriginPolicyEnabled, false },
        { blink::features::kOverscrollCustomization, SetOverscrollCustomizationEnabled, false },
        { blink::features::kPageMarginBoxes, SetPageMarginBoxesEnabled, false },
        { blink::features::kPagePopup, SetPagePopupEnabled, false },
        { blink::features::kPageRevealEvent, SetPageRevealEventEnabled, false },
        { blink::features::kPageSwapEvent, SetPageSwapEventEnabled, false },
        { blink::features::kPaintHighlightsForFirstLetter, SetPaintHighlightsForFirstLetterEnabled, false },
        { blink::features::kPaintHoldingForIframes, SetPaintHoldingForIframesEnabled, false },
        { blink::features::kPaintHoldingForLocalIframes, SetPaintHoldingForLocalIframesEnabled, false },
        { blink::features::kPaintUnderInvalidationChecking, SetPaintUnderInvalidationCheckingEnabled, false },
        { blink::features::kParakeet, SetParakeetEnabled, false },
        { blink::features::kPartitionVisitedLinkDatabaseWithSelfLinks, SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled, false },
        { blink::features::kPartitionedPopins, SetPartitionedPopinsEnabled, false },
        { blink::features::kPasswordReveal, SetPasswordRevealEnabled, false },
        { blink::features::kPaymentInstruments, SetPaymentInstrumentsEnabled, false },
        { blink::features::kPaymentLinkDetection, SetPaymentLinkDetectionEnabled, false },
        { blink::features::kPaymentMethodChangeEvent, SetPaymentMethodChangeEventEnabled, false },
        { blink::features::kPerformanceMarkFeatureUsage, SetPerformanceMarkFeatureUsageEnabled, false },
        { blink::features::kPerformanceNavigateSystemEntropy, SetPerformanceNavigateSystemEntropyEnabled, false },
        { blink::features::kPerformanceNavigationTimingConfidence, SetPerformanceNavigationTimingConfidenceEnabled, false },
        { blink::features::kPermissionElement, SetPermissionElementEnabled, true },
        { blink::features::kPermissionsRequestRevoke, SetPermissionsRequestRevokeEnabled, false },
        { blink::features::kPointerEventDeviceId, SetPointerEventDeviceIdEnabled, false },
        { blink::features::kPointerEventTargetsInEventLists, SetPointerEventTargetsInEventListsEnabled, false },
        { blink::features::kPopoverAnchorRelationships, SetPopoverAnchorRelationshipsEnabled, false },
        { blink::features::kPopoverDialogNewFocusBehavior, SetPopoverDialogNewFocusBehaviorEnabled, false },
        { blink::features::kPositionOutsideTabSpanCheckSiblingNode, SetPositionOutsideTabSpanCheckSiblingNodeEnabled, false },
        { blink::features::kPreferDefaultScrollbarStyles, SetPreferDefaultScrollbarStylesEnabled, false },
        { blink::features::kPreferNonCompositedScrolling, SetPreferNonCompositedScrollingEnabled, false },
        { blink::features::kPrefersReducedData, SetPrefersReducedDataEnabled, false },
        { blink::features::kPrefixedVideoFullscreen, SetPrefixedVideoFullscreenEnabled, false },
        { blink::features::kPrerender2, SetPrerender2Enabled, false },
        { blink::features::kPreserveFollowingBlockStylesDuringBlockMerge, SetPreserveFollowingBlockStylesDuringBlockMergeEnabled, false },
        { blink::features::kPreventUndoIfNotEditable, SetPreventUndoIfNotEditableEnabled, false },
        { blink::features::kPrivateAggregationApiFilteringIds, SetPrivateAggregationApiFilteringIdsEnabled, false },
        { blink::features::kPrivateAggregationAuctionReportBuyerDebugModeConfig, SetPrivateAggregationAuctionReportBuyerDebugModeConfigEnabled, false },
        { blink::features::kPseudoElementsCorrectInGetComputedStyle, SetPseudoElementsCorrectInGetComputedStyleEnabled, false },
        { blink::features::kPseudoElementsFocusable, SetPseudoElementsFocusableEnabled, false },
        { blink::features::kQuickIntensiveWakeUpThrottlingAfterLoading, SetQuickIntensiveWakeUpThrottlingAfterLoadingEnabled, false },
        { blink::features::kRTCDataChannelPriority, SetRTCDataChannelPriorityEnabled, false },
        { blink::features::kRTCEncodedAudioFrameAbsCaptureTime, SetRTCEncodedAudioFrameAbsCaptureTimeEnabled, false },
        { blink::features::kRTCEncodedFrameSetMetadata, SetRTCEncodedFrameSetMetadataEnabled, false },
        { blink::features::kRTCEncodedVideoFrameAdditionalMetadata, SetRTCEncodedVideoFrameAdditionalMetadataEnabled, false },
        { blink::features::kRTCJitterBufferTarget, SetRTCJitterBufferTargetEnabled, false },
        { blink::features::kRTCRtpEncodingParametersCodec, SetRTCRtpEncodingParametersCodecEnabled, false },
        { blink::features::kRTCRtpScaleResolutionDownTo, SetRTCRtpScaleResolutionDownToEnabled, false },
        { blink::features::kRTCRtpScriptTransform, SetRTCRtpScriptTransformEnabled, false },
        { blink::features::kRTCRtpTransport, SetRTCRtpTransportEnabled, false },
        { blink::features::kRTCSvcScalabilityMode, SetRTCSvcScalabilityModeEnabled, false },
        { blink::features::kRasterInducingScroll, SetRasterInducingScrollEnabled, false },
        { blink::features::kReadableStreamAsyncIterable, SetReadableStreamAsyncIterableEnabled, false },
        { blink::features::kReduceCookieIPCs, SetReduceCookieIPCsEnabled, false },
        { blink::features::kReduceUserAgentAndroidVersionDeviceModel, SetReduceUserAgentAndroidVersionDeviceModelEnabled, false },
        { blink::features::kReduceUserAgentMinorVersion, SetReduceUserAgentMinorVersionEnabled, false },
        { blink::features::kReduceUserAgentPlatformOsCpu, SetReduceUserAgentPlatformOsCpuEnabled, false },
        { blink::features::kRegionCapture, SetRegionCaptureEnabled, false },
        { blink::features::kRelOpenerBcgDependencyHint, SetRelOpenerBcgDependencyHintEnabled, false },
        { blink::features::kRemotePlaybackBackend, SetRemotePlaybackBackendEnabled, false },
        { blink::features::kRemoveCollapsedPlaceholder, SetRemoveCollapsedPlaceholderEnabled, false },
        { blink::features::kRemoveDanglingMarkupInTarget, SetRemoveDanglingMarkupInTargetEnabled, false },
        { blink::features::kRemoveDataUrlInSvgUse, SetRemoveDataUrlInSvgUseEnabled, false },
        { blink::features::kRemoveNodeHavingChildrenIfFullySelected, SetRemoveNodeHavingChildrenIfFullySelectedEnabled, false },
        { blink::features::kRemoveVisibleSelectionInDOMSelection, SetRemoveVisibleSelectionInDOMSelectionEnabled, false },
        { blink::features::kRenderBlockingInlineModuleScript, SetRenderBlockingInlineModuleScriptEnabled, false },
        { blink::features::kRenderBlockingStatus, SetRenderBlockingStatusEnabled, false },
        { blink::features::kRenderPriorityAttribute, SetRenderPriorityAttributeEnabled, false },
        { blink::features::kReportEventTimingAtVisibilityChange, SetReportEventTimingAtVisibilityChangeEnabled, false },
        { blink::features::kReportVisibleLineBounds, SetReportVisibleLineBoundsEnabled, false },
        { blink::features::kResetInputTypeToNoneBeforeCharacterInput, SetResetInputTypeToNoneBeforeCharacterInputEnabled, false },
        { blink::features::kResourceTimingContentType, SetResourceTimingContentTypeEnabled, false },
        { blink::features::kResourceTimingFinalResponseHeadersStart, SetResourceTimingFinalResponseHeadersStartEnabled, false },
        { blink::features::kResourceTimingUseCORSForBodySizes, SetResourceTimingUseCORSForBodySizesEnabled, false },
        { blink::features::kReuseShapeResultsByFonts, SetReuseShapeResultsByFontsEnabled, false },
        { blink::features::kRewindFloats, SetRewindFloatsEnabled, false },
        { blink::features::kRootElementWithPlaceHolderAfterDeletingSelection, SetRootElementWithPlaceHolderAfterDeletingSelectionEnabled, false },
        { blink::features::kRubyShortHeuristics, SetRubyShortHeuristicsEnabled, false },
        { blink::features::kSanitizerAPI, SetSanitizerAPIEnabled, false },
        { blink::features::kScheduleSelectionChangeOnBackspace, SetScheduleSelectionChangeOnBackspaceEnabled, false },
        { blink::features::kSchedulerYield, SetSchedulerYieldEnabled, false },
        { blink::features::kScopedCustomElementRegistry, SetScopedCustomElementRegistryEnabled, false },
        { blink::features::kScrollEndEvents, SetScrollEndEventsEnabled, false },
        { blink::features::kScrollIntoViewRootFrameViewportBugFix, SetScrollIntoViewRootFrameViewportBugFixEnabled, false },
        { blink::features::kScrollTimeline, SetScrollTimelineEnabled, false },
        { blink::features::kScrollTimelineCurrentTime, SetScrollTimelineCurrentTimeEnabled, false },
        { blink::features::kScrollTopLeftInterop, SetScrollTopLeftInteropEnabled, false },
        { blink::features::kScrollbarColor, SetScrollbarColorEnabled, false },
        { blink::features::kScrollbarWidth, SetScrollbarWidthEnabled, false },
        { blink::features::kSearchTextHighlightPseudo, SetSearchTextHighlightPseudoEnabled, false },
        { blink::features::kSecurePaymentConfirmationNetworkAndIssuerIcons, SetSecurePaymentConfirmationNetworkAndIssuerIconsEnabled, false },
        { blink::features::kSelectAudioOutput, SetSelectAudioOutputEnabled, false },
        { blink::features::kSelectOptionAccessibilityTargetSize, SetSelectOptionAccessibilityTargetSizeEnabled, false },
        { blink::features::kSelectParserRelaxation, SetSelectParserRelaxationEnabled, false },
        { blink::features::kSelectPopupLessUpdates, SetSelectPopupLessUpdatesEnabled, false },
        { blink::features::kSelectedcontentelementAttribute, SetSelectedcontentelementAttributeEnabled, false },
        { blink::features::kSelectionAcrossShadowDOM, SetSelectionAcrossShadowDOMEnabled, false },
        { blink::features::kSelectionIsCollapsedShadowDOMSupport, SetSelectionIsCollapsedShadowDOMSupportEnabled, false },
        { blink::features::kSelectionOnShadowDOMWithDelegatesFocus, SetSelectionOnShadowDOMWithDelegatesFocusEnabled, false },
        { blink::features::kSerial, SetSerialEnabled, false },
        { blink::features::kSerializeViewTransitionStateInSPA, SetSerializeViewTransitionStateInSPAEnabled, false },
        { blink::features::kServiceWorkerClientLifecycleState, SetServiceWorkerClientLifecycleStateEnabled, false },
        { blink::features::kServiceWorkerStaticRouterTimingInfo, SetServiceWorkerStaticRouterTimingInfoEnabled, false },
        { blink::features::kSetSequentialFocusStartingPoint, SetSetSequentialFocusStartingPointEnabled, false },
        { blink::features::kShadowRootReferenceTarget, SetShadowRootReferenceTargetEnabled, false },
        { blink::features::kShapeOutsideWritingModeFix, SetShapeOutsideWritingModeFixEnabled, false },
        { blink::features::kShapeResultCachedPreviousSafeToBreakOffset, SetShapeResultCachedPreviousSafeToBreakOffsetEnabled, false },
        { blink::features::kSharedStorageWebLocks, SetSharedStorageWebLocksEnabled, false },
        { blink::features::kSidewaysWritingModes, SetSidewaysWritingModesEnabled, false },
        { blink::features::kSiteInitiatedMirroring, SetSiteInitiatedMirroringEnabled, false },
        { blink::features::kSkipAd, SetSkipAdEnabled, false },
        { blink::features::kSkipPreloadScanning, SetSkipPreloadScanningEnabled, false },
        { blink::features::kSkipTemporaryDocumentFragment, SetSkipTemporaryDocumentFragmentEnabled, false },
        { blink::features::kSkipTouchEventFilter, SetSkipTouchEventFilterEnabled, false },
        { blink::features::kSmartCard, SetSmartCardEnabled, false },
        { blink::features::kSmilAutoSuspendOnLag, SetSmilAutoSuspendOnLagEnabled, false },
        { blink::features::kSoftNavigationDetection, SetSoftNavigationDetectionEnabled, false },
        { blink::features::kSoftNavigationHeuristics, SetSoftNavigationHeuristicsEnabled, false },
        { blink::features::kSoftNavigationHeuristicsExposeFPAndFCP, SetSoftNavigationHeuristicsExposeFPAndFCPEnabled, false },
        { blink::features::kSpeakerSelection, SetSpeakerSelectionEnabled, false },
        { blink::features::kSpeculationRulesPointerDownHeuristics, SetSpeculationRulesPointerDownHeuristicsEnabled, false },
        { blink::features::kSpeculationRulesPointerHoverHeuristics, SetSpeculationRulesPointerHoverHeuristicsEnabled, false },
        { blink::features::kSpeculationRulesPrefetchWithSubresources, SetSpeculationRulesPrefetchWithSubresourcesEnabled, false },
        { blink::features::kSrcsetMaxDensity, SetSrcsetMaxDensityEnabled, false },
        { blink::features::kStandardizedBrowserZoom, SetStandardizedBrowserZoomEnabled, false },
        { blink::features::kStandardizedBrowserZoomOptOut, SetStandardizedBrowserZoomOptOutEnabled, false },
        { blink::features::kStaticAnimationOptimization, SetStaticAnimationOptimizationEnabled, false },
        { blink::features::kStorageAccessHeader, SetStorageAccessHeaderEnabled, false },
        { blink::features::kStorageBuckets, SetStorageBucketsEnabled, false },
        { blink::features::kStorageBucketsDurability, SetStorageBucketsDurabilityEnabled, false },
        { blink::features::kStorageBucketsLocks, SetStorageBucketsLocksEnabled, false },
        { blink::features::kStrictMimeTypesForWorkers, SetStrictMimeTypesForWorkersEnabled, false },
        { blink::features::kStricterCellWidthContentSizeQuirk, SetStricterCellWidthContentSizeQuirkEnabled, false },
        { blink::features::kSvgContextPaint, SetSvgContextPaintEnabled, false },
        { blink::features::kSvgCrossOriginAttribute, SetSvgCrossOriginAttributeEnabled, false },
        { blink::features::kSvgEagerPresAttrStyleUpdate, SetSvgEagerPresAttrStyleUpdateEnabled, false },
        { blink::features::kSvgExternalResources, SetSvgExternalResourcesEnabled, false },
        { blink::features::kSvgFilterUserSpaceViewportForNonSvg, SetSvgFilterUserSpaceViewportForNonSvgEnabled, false },
        { blink::features::kSvgGradientColorInterpolationLinearRgbSupport, SetSvgGradientColorInterpolationLinearRgbSupportEnabled, false },
        { blink::features::kSvgInlineRootPixelSnappingScaleAdjustment, SetSvgInlineRootPixelSnappingScaleAdjustmentEnabled, false },
        { blink::features::kSvgNoPixelSnappingScaleAdjustment, SetSvgNoPixelSnappingScaleAdjustmentEnabled, false },
        { blink::features::kSvgTransformOptimization, SetSvgTransformOptimizationEnabled, false },
        { blink::features::kSynthesizedKeyboardEventsForAccessibilityActions, SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled, false },
        { blink::features::kSystemFallbackEmojiVSSupport, SetSystemFallbackEmojiVSSupportEnabled, false },
        { blink::features::kSystemWakeLock, SetSystemWakeLockEnabled, false },
        { blink::features::kTestBlinkFeatureDefault, SetTestBlinkFeatureDefaultEnabled, true },
        { blink::features::kTestFeatureStable, SetTestFeatureStableEnabled, false },
        { blink::features::kTextDetector, SetTextDetectorEnabled, false },
        { blink::features::kTextDiffSplitFix, SetTextDiffSplitFixEnabled, false },
        { blink::features::kTextFragmentAPI, SetTextFragmentAPIEnabled, false },
        { blink::features::kTextFragmentAnchor, SetTextFragmentIdentifiersEnabled, false },
        { blink::features::kTextFragmentTapOpensContextMenu, SetTextFragmentTapOpensContextMenuEnabled, false },
        { blink::features::kTextInputNotAlwaysDirAuto, SetTextInputNotAlwaysDirAutoEnabled, false },
        { blink::features::kTextMetricsBaselines, SetTextMetricsBaselinesEnabled, false },
        { blink::features::kTextSegmentBoundaryForElementWithFloatStyle, SetTextSegmentBoundaryForElementWithFloatStyleEnabled, false },
        { blink::features::kTextSizeAdjustImprovements, SetTextSizeAdjustImprovementsEnabled, false },
        { blink::features::kTextTransformAndSecurityFix, SetTextTransformAndSecurityFixEnabled, false },
        { blink::features::kTimeZoneChangeEvent, SetTimeZoneChangeEventEnabled, false },
        { blink::features::kTimelineScope, SetTimelineScopeEnabled, false },
        { blink::features::kTimestampBasedCLSTracking, SetTimestampBasedCLSTrackingEnabled, false },
        { blink::features::kTopLayerInactiveDocumentExceptions, SetTopLayerInactiveDocumentExceptionsEnabled, false },
        { blink::features::kTouchDragOnShortPress, SetTouchDragOnShortPressEnabled, false },
        { blink::features::kTransferableRTCDataChannel, SetTransferableRTCDataChannelEnabled, false },
        { blink::features::kTranslateService, SetTranslateServiceEnabled, false },
        { blink::features::kEnableTranslationAPI, SetTranslationAPIEnabled, true },
        { blink::features::kTranslationAPIEntryPoint, SetTranslationAPIEntryPointEnabled, false },
        { blink::features::kTrustedTypeBeforePolicyCreationEvent, SetTrustedTypeBeforePolicyCreationEventEnabled, false },
        { blink::features::kTrustedTypesUseCodeLike, SetTrustedTypesUseCodeLikeEnabled, false },
        { blink::features::kURLPatternCompareComponent, SetURLPatternCompareComponentEnabled, false },
        { blink::features::kURLSearchParamsHasAndDeleteMultipleArgs, SetURLSearchParamsHasAndDeleteMultipleArgsEnabled, false },
        { blink::features::kUnclosedFormControlIsInvalid, SetUnclosedFormControlIsInvalidEnabled, false },
        { blink::features::kUnexposedTaskIds, SetUnexposedTaskIdsEnabled, false },
        { blink::features::kUnownedAnimationsSkipCSSEvents, SetUnownedAnimationsSkipCSSEventsEnabled, false },
        { blink::features::kUnrestrictedMeasureUserAgentSpecificMemory, SetUnrestrictedMeasureUserAgentSpecificMemoryEnabled, false },
        { blink::features::kUnrestrictedUsb, SetUnrestrictedUsbEnabled, false },
        { blink::features::kUseBeginFramePresentationFeedback, SetUseBeginFramePresentationFeedbackEnabled, false },
        { blink::features::kUseLowQualityInterpolation, SetUseLowQualityInterpolationEnabled, false },
        { blink::features::kUseSelectionFocusNodeForCaretNavigation, SetUseSelectionFocusNodeForCaretNavigationEnabled, false },
        { blink::features::kUseUndoStepElementDispatchBeforeInput, SetUseUndoStepElementDispatchBeforeInputEnabled, false },
        { blink::features::kVideoAutoFullscreen, SetVideoAutoFullscreenEnabled, false },
        { blink::features::kVideoFrameMetadataBackgroundBlur, SetVideoFrameMetadataBackgroundBlurEnabled, false },
        { blink::features::kVideoFullscreenOrientationLock, SetVideoFullscreenOrientationLockEnabled, false },
        { blink::features::kVideoRotateToFullscreen, SetVideoRotateToFullscreenEnabled, false },
        { blink::features::kVideoTrackGenerator, SetVideoTrackGeneratorEnabled, false },
        { blink::features::kVideoTrackGeneratorInWindow, SetVideoTrackGeneratorInWindowEnabled, false },
        { blink::features::kVideoTrackGeneratorInWorker, SetVideoTrackGeneratorInWorkerEnabled, false },
        { blink::features::kViewTransitionDisableSnapBrowserControlsOnHidden, SetViewTransitionDisableSnapBrowserControlsOnHiddenEnabled, false },
        { blink::features::kViewTransitionLayeredCapture, SetViewTransitionLayeredCaptureEnabled, false },
        { blink::features::kViewTransitionLongCallbackTimeoutForTesting, SetViewTransitionLongCallbackTimeoutForTestingEnabled, false },
        { blink::features::kViewTransitionOnNavigation, SetViewTransitionOnNavigationEnabled, false },
        { blink::features::kViewTransitionOnNavigationForIframes, SetViewTransitionOnNavigationForIframesEnabled, false },
        { blink::features::kViewTransitionOverflowRectFromSurface, SetViewTransitionOverflowRectFromSurfaceEnabled, false },
        { blink::features::kViewTransitionTreeScopedNames, SetViewTransitionTreeScopedNamesEnabled, false },
        { blink::features::kViewTransitionTypes, SetViewTransitionTypesEnabled, false },
        { blink::features::kViewportChangesUpdateTextAutosizing, SetViewportChangesUpdateTextAutosizingEnabled, false },
        { blink::features::kViewportHeightClientHintHeader, SetViewportHeightClientHintHeaderEnabled, false },
        { blink::features::kViewportSegments, SetViewportSegmentsEnabled, true },
        { blink::features::kVisibilityCollapseColumn, SetVisibilityCollapseColumnEnabled, false },
        { blink::features::kVisualViewportOnScrollEnd, SetVisualViewportOnScrollEndEnabled, false },
        { blink::features::kWakeLock, SetWakeLockEnabled, false },
        { blink::features::kWarnOnContentVisibilityRenderAccess, SetWarnOnContentVisibilityRenderAccessEnabled, false },
        { blink::features::kWebAnimationsSVG, SetWebAnimationsSVGEnabled, false },
        { blink::features::kWebAppInstallation, SetWebAppInstallationEnabled, false },
        { blink::features::kDesktopPWAsTabStrip, SetWebAppTabStripEnabled, true },
        { blink::features::kDesktopPWAsTabStripCustomizations, SetWebAppTabStripCustomizationsEnabled, true },
        { blink::features::kWebAppEnableTranslations, SetWebAppTranslationsEnabled, false },
        { blink::features::kWebAssemblyJSStringBuiltins, SetWebAssemblyJSStringBuiltinsEnabled, false },
        { blink::features::kWebAudioBypassOutputBuffering, SetWebAudioBypassOutputBufferingEnabled, false },
        { blink::features::kWebAudioBypassOutputBufferingOptOut, SetWebAudioBypassOutputBufferingOptOutEnabled, false },
        { blink::features::kWebAuth, SetWebAuthEnabled, false },
        { blink::features::kWebAuthAuthenticatorAttachment, SetWebAuthAuthenticatorAttachmentEnabled, false },
        { blink::features::kWebAuthenticationAttestationFormats, SetWebAuthenticationAttestationFormatsEnabled, false },
        { blink::features::kWebAuthenticationClientCapabilities, SetWebAuthenticationClientCapabilitiesEnabled, false },
        { blink::features::kWebAuthenticationJSONSerialization, SetWebAuthenticationJSONSerializationEnabled, false },
        { blink::features::kWebAuthenticationLargeBlobExtension, SetWebAuthenticationLargeBlobExtensionEnabled, false },
        { blink::features::kWebAuthenticationPRFExtension, SetWebAuthenticationPRFEnabled, false },
        { blink::features::kWebAuthenticationSupplementalPubKeys, SetWebAuthenticationSupplementalPubKeysEnabled, false },
        { blink::features::kWebBluetoothScanning, SetWebBluetoothScanningEnabled, false },
        { blink::features::kWebCodecsCopyToRGB, SetWebCodecsCopyToRGBEnabled, false },
        { blink::features::kWebCodecsHBDFormats, SetWebCodecsHBDFormatsEnabled, false },
        { blink::features::kWebCodecsOrientation, SetWebCodecsOrientationEnabled, false },
        { blink::features::kWebCodecsVideoEncoderBuffers, SetWebCodecsVideoEncoderBuffersEnabled, false },
        { blink::features::kWebCryptoCurve25519, SetWebCryptoCurve25519Enabled, false },
        { blink::features::kWebFontResizeLCP, SetWebFontResizeLCPEnabled, false },
        { blink::features::kWebGLDrawingBufferStorage, SetWebGLDrawingBufferStorageEnabled, false },
        { blink::features::kWebGPUCanvasContextGetConfiguration, SetWebGPUCanvasContextGetConfigurationEnabled, false },
        { blink::features::kWebGPUDeviceAdapterInfo, SetWebGPUDeviceAdapterInfoEnabled, false },
        { blink::features::kWebGPUExperimentalFeatures, SetWebGPUExperimentalFeaturesEnabled, false },
        { blink::features::kWebGPUHDR, SetWebGPUHDREnabled, false },
        { blink::features::kWebGPUTextureViewUsage, SetWebGPUTextureViewUsageEnabled, false },
        { blink::features::kWebHID, SetWebHIDEnabled, false },
        { blink::features::kWebHIDOnDedicatedWorkers, SetWebHIDOnDedicatedWorkersEnabled, false },
        { blink::features::kWebIDLBigIntUsesToBigInt, SetWebIDLBigIntUsesToBigIntEnabled, false },
        { blink::features::kWebPreferences, SetWebPreferencesEnabled, false },
        { blink::features::kWebPrinting, SetWebPrintingEnabled, false },
        { blink::features::kWebSocketStream, SetWebSocketStreamEnabled, false },
        { blink::features::kWebUSBOnDedicatedWorkers, SetWebUSBOnDedicatedWorkersEnabled, false },
        { blink::features::kWebVTTRegions, SetWebVTTRegionsEnabled, false },
        { blink::features::kWebXREnabledFeatures, SetWebXREnabledFeaturesEnabled, false },
        { blink::features::kWebXRHitTestEntityTypes, SetWebXRHitTestEntityTypesEnabled, false },
        { blink::features::kWebXRSpecParity, SetWebXRSpecParityEnabled, false },
        { blink::features::kWindowDefaultStatus, SetWindowDefaultStatusEnabled, false },
        { blink::features::kXMLParserMergeAdjacentCDataSections, SetXMLParserMergeAdjacentCDataSectionsEnabled, false },
        { blink::features::kZeroCopyTabCapture, SetZeroCopyTabCaptureEnabled, false },
    };
    for (const auto& map : mappings) {
        const bool feature_enabled = base::FeatureList::IsEnabled(map.feature);
        const bool is_overridden = base::FeatureList::GetStateIfOverridden(map.feature).has_value();
        if (map.if_overridden) {
            if (is_overridden)
                map.enabler(feature_enabled);
        } else {
            if (feature_enabled || is_overridden)
                map.enabler(feature_enabled);
        }
    }
}

void RuntimeEnabledFeaturesBase::SetMojoJSEnabled(bool enabled)
{
    if (get_is_mojo_js_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_mojo_js_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetMojoJSTestEnabled(bool enabled)
{
    if (get_is_mojo_js_test_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_mojo_js_test_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetProtectedOriginTrialsSampleAPIEnabled(bool enabled)
{
    if (get_is_protected_origin_trials_sample_api_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_protected_origin_trials_sample_api_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetProtectedOriginTrialsSampleAPIDependentEnabled(bool enabled)
{
    if (get_is_protected_origin_trials_sample_api_dependent_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_protected_origin_trials_sample_api_dependent_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetProtectedOriginTrialsSampleAPIImpliedEnabled(bool enabled)
{
    if (get_is_protected_origin_trials_sample_api_implied_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_protected_origin_trials_sample_api_implied_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetTestFeatureProtectedEnabled(bool enabled)
{
    if (get_is_test_feature_protected_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_test_feature_protected_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetTestFeatureProtectedDependentEnabled(bool enabled)
{
    if (get_is_test_feature_protected_dependent_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_test_feature_protected_dependent_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}
void RuntimeEnabledFeaturesBase::SetTestFeatureProtectedImpliedEnabled(bool enabled)
{
    if (get_is_test_feature_protected_implied_enabled_() == enabled) {
        return;
    }
    base::AutoWritableMemory protected_memory_writer(is_test_feature_protected_implied_enabled_);
    protected_memory_writer.GetProtectedData() = enabled;
}

bool RuntimeEnabledFeaturesBase::BlinkExtensionChromeOSEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsBlinkExtensionChromeOSForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsBlinkExtensionChromeOSForceDisabled()) {
        return false;
    }

    return BlinkExtensionChromeOSEnabled();
}

bool RuntimeEnabledFeaturesBase::BlinkExtensionChromeOSKioskEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsBlinkExtensionChromeOSKioskForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsBlinkExtensionChromeOSKioskForceDisabled()) {
        return false;
    }

    return BlinkExtensionChromeOSKioskEnabled();
}

bool RuntimeEnabledFeaturesBase::BlinkExtensionDiagnosticsEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsBlinkExtensionDiagnosticsForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsBlinkExtensionDiagnosticsForceDisabled()) {
        return false;
    }

    return BlinkExtensionDiagnosticsEnabled();
}

bool RuntimeEnabledFeaturesBase::FedCmIdpSigninStatusEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsFedCmIdpSigninStatusForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsFedCmIdpSigninStatusForceDisabled()) {
        return false;
    }

    return FedCmIdpSigninStatusEnabled();
}

bool RuntimeEnabledFeaturesBase::TestFeatureEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsTestFeatureForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsTestFeatureForceDisabled()) {
        return false;
    }

    return TestFeatureEnabled();
}

bool RuntimeEnabledFeaturesBase::AdInterestGroupAPIEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::FledgeEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::ParakeetEnabled(context))
        return true;
    if (is_ad_interest_group_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAdInterestGroupAPI);
}

bool RuntimeEnabledFeaturesBase::AIPromptAPIForExtensionEnabled(const FeatureContext* context)
{
    if (is_ai_prompt_api_for_extension_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAIPromptAPIForExtension);
}

bool RuntimeEnabledFeaturesBase::AISummarizationAPIEnabled(const FeatureContext* context)
{
    if (is_ai_summarization_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAISummarizationAPI);
}

bool RuntimeEnabledFeaturesBase::AppTitleEnabled(const FeatureContext* context)
{
    if (is_app_title_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAppTitle);
}

bool RuntimeEnabledFeaturesBase::AttributionReportingInterfaceEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::AttributionReportingEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::AttributionReportingCrossAppWebEnabled(context))
        return true;
    if (is_attribution_reporting_interface_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAttributionReportingInterface);
}

bool RuntimeEnabledFeaturesBase::AudioContextPlayoutStatsEnabled(const FeatureContext* context)
{
    if (is_audio_context_playout_stats_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAudioContextPlayoutStats);
}

bool RuntimeEnabledFeaturesBase::AutoDarkModeEnabled(const FeatureContext* context)
{
    if (is_auto_dark_mode_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kAutoDarkMode);
}

bool RuntimeEnabledFeaturesBase::BackForwardCacheExperimentHTTPHeaderEnabled(const FeatureContext* context)
{
    if (is_back_forward_cache_experiment_http_header_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader);
}

bool RuntimeEnabledFeaturesBase::BackForwardCacheNotRestoredReasonsEnabled(const FeatureContext* context)
{
    if (is_back_forward_cache_not_restored_reasons_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kBackForwardCacheNotRestoredReasons);
}

bool RuntimeEnabledFeaturesBase::BuiltInAIAPIEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::AIPromptAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::AIRewriterAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::AISummarizationAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::AIWriterAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::LanguageDetectionAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::TranslationAPIEntryPointEnabled(context))
        return true;
    if (is_built_in_aiapi_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kBuiltInAIAPI);
}

bool RuntimeEnabledFeaturesBase::CacheStorageCodeCacheHintEnabled(const FeatureContext* context)
{
    if (is_cache_storage_code_cache_hint_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kCacheStorageCodeCacheHint);
}

bool RuntimeEnabledFeaturesBase::Canvas2dMeshEnabled(const FeatureContext* context)
{
    if (is_canvas_2d_mesh_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kCanvas2dMesh);
}

bool RuntimeEnabledFeaturesBase::CapturedSurfaceControlEnabled(const FeatureContext* context)
{
    if (is_captured_surface_control_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kCapturedSurfaceControl);
}

bool RuntimeEnabledFeaturesBase::CoopRestrictPropertiesEnabled(const FeatureContext* context)
{
    if (is_coop_restrict_properties_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kCoopRestrictProperties);
}

bool RuntimeEnabledFeaturesBase::DatabaseEnabled(const FeatureContext* context)
{
    if (is_database_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDatabase);
}

bool RuntimeEnabledFeaturesBase::DeprecateUnloadOptOutEnabled(const FeatureContext* context)
{
    if (is_deprecate_unload_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDeprecateUnloadOptOut);
}

bool RuntimeEnabledFeaturesBase::DigitalGoodsEnabled(const FeatureContext* context)
{
    if (is_digital_goods_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDigitalGoods);
}

bool RuntimeEnabledFeaturesBase::DisableDifferentOriginSubframeDialogSuppressionEnabled(const FeatureContext* context)
{
    if (is_disable_different_origin_subframe_dialog_suppression_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression);
}

bool RuntimeEnabledFeaturesBase::DisableHardwareNoiseSuppressionEnabled(const FeatureContext* context)
{
    if (is_disable_hardware_noise_suppression_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDisableHardwareNoiseSuppression);
}

bool RuntimeEnabledFeaturesBase::DisableReduceAcceptLanguageEnabled(const FeatureContext* context)
{
    if (is_disable_reduce_accept_language_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDisableReduceAcceptLanguage);
}

bool RuntimeEnabledFeaturesBase::DisableThirdPartyStoragePartitioning2Enabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsDisableThirdPartyStoragePartitioning2ForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsDisableThirdPartyStoragePartitioning2ForceDisabled()) {
        return false;
    }

    if (is_disable_third_party_storage_partitioning_2_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDisableThirdPartyStoragePartitioning2);
}

bool RuntimeEnabledFeaturesBase::DocumentIsolationPolicyEnabled(const FeatureContext* context)
{
    if (is_document_isolation_policy_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDocumentIsolationPolicy);
}

bool RuntimeEnabledFeaturesBase::DocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(const FeatureContext* context)
{
    if (is_document_policy_include_js_call_stacks_in_crash_reports_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDocumentPolicyIncludeJSCallStacksInCrashReports);
}

bool RuntimeEnabledFeaturesBase::DocumentPolicyNegotiationEnabled(const FeatureContext* context)
{
    if (is_document_policy_negotiation_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kDocumentPolicyNegotiation);
}

bool RuntimeEnabledFeaturesBase::FedCmAuthzEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsFedCmAuthzForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsFedCmAuthzForceDisabled()) {
        return false;
    }

    if (!RuntimeEnabledFeaturesBase::FedCmEnabled(context))
        return false;
    if (is_fed_cm_authz_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFedCmAuthz);
}

bool RuntimeEnabledFeaturesBase::FedCmButtonModeEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::FedCmEnabled(context))
        return false;
    if (is_fed_cm_button_mode_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFedCmButtonMode);
}

bool RuntimeEnabledFeaturesBase::FedCmMultipleIdentityProvidersEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::FedCmEnabled(context))
        return false;
    if (is_fed_cm_multiple_identity_providers_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFedCmMultipleIdentityProviders);
}

bool RuntimeEnabledFeaturesBase::FedCmWithStorageAccessAPIEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsFedCmWithStorageAccessAPIForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsFedCmWithStorageAccessAPIForceDisabled()) {
        return false;
    }

    if (!RuntimeEnabledFeaturesBase::FedCmEnabled(context))
        return false;
    if (is_fed_cm_with_storage_access_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFedCmWithStorageAccessAPI);
}

bool RuntimeEnabledFeaturesBase::FetchLaterAPIEnabled(const FeatureContext* context)
{
    if (is_fetch_later_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFetchLaterAPI);
}

bool RuntimeEnabledFeaturesBase::FileSystemObserverEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::FileSystemAccessEnabled(context))
        return false;
    if (is_file_system_observer_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFileSystemObserver);
}

bool RuntimeEnabledFeaturesBase::FledgeBiddingAndAuctionServerAPIEnabled(const FeatureContext* context)
{
    if (is_fledge_bidding_and_auction_server_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFledgeBiddingAndAuctionServerAPI);
}

bool RuntimeEnabledFeaturesBase::FocusgroupEnabled(const FeatureContext* context)
{
    if (is_focusgroup_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kFocusgroup);
}

bool RuntimeEnabledFeaturesBase::GetAllScreensMediaEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::GetDisplayMediaEnabled(context))
        return false;
    if (is_get_all_screens_media_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kGetAllScreensMedia);
}

bool RuntimeEnabledFeaturesBase::HrefTranslateEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::TranslateServiceEnabled(context))
        return false;
    if (is_href_translate_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kHrefTranslate);
}

bool RuntimeEnabledFeaturesBase::JavaScriptCompileHintsMagicAlwaysRuntimeEnabled(const FeatureContext* context)
{
    if (is_java_script_compile_hints_magic_always_runtime_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kJavaScriptCompileHintsMagicAlwaysRuntime);
}

bool RuntimeEnabledFeaturesBase::JavaScriptCompileHintsMagicRuntimeEnabled(const FeatureContext* context)
{
    if (is_java_script_compile_hints_magic_runtime_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kJavaScriptCompileHintsMagicRuntime);
}

bool RuntimeEnabledFeaturesBase::KeyboardFocusableScrollersOptOutEnabled(const FeatureContext* context)
{
    if (is_keyboard_focusable_scrollers_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kKeyboardFocusableScrollersOptOut);
}

bool RuntimeEnabledFeaturesBase::LanguageDetectionAPIEnabled(const FeatureContext* context)
{
    if (is_language_detection_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kLanguageDetectionAPI);
}

bool RuntimeEnabledFeaturesBase::LimitThirdPartyCookiesEnabled(const FeatureContext* context)
{
    if (is_limit_third_party_cookies_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kLimitThirdPartyCookies);
}

bool RuntimeEnabledFeaturesBase::MediaCaptureBackgroundBlurEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::MediaCaptureCameraControlsEnabled(context))
        return true;
    if (is_media_capture_background_blur_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kMediaCaptureBackgroundBlur);
}

bool RuntimeEnabledFeaturesBase::MediaCaptureConfigurationChangeEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::MediaCaptureBackgroundBlurEnabled(context))
        return true;
    if (is_media_capture_configuration_change_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kMediaCaptureConfigurationChange);
}

bool RuntimeEnabledFeaturesBase::MediaPreviewsOptOutEnabled(const FeatureContext* context)
{
    if (is_media_previews_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kMediaPreviewsOptOut);
}

bool RuntimeEnabledFeaturesBase::MediaSourceExtensionsForWebCodecsEnabled(const FeatureContext* context)
{
    if (is_media_source_extensions_for_webcodecs_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kMediaSourceExtensionsForWebCodecs);
}

bool RuntimeEnabledFeaturesBase::MutationEventsEnabled(const FeatureContext* context)
{
    if (is_mutation_events_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kMutationEvents);
}

bool RuntimeEnabledFeaturesBase::NavigationIdEnabled(const FeatureContext* context)
{
    if (is_navigation_id_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kNavigationId);
}

bool RuntimeEnabledFeaturesBase::NotificationTriggersEnabled(const FeatureContext* context)
{
    if (is_notification_triggers_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kNotificationTriggers);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPI);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIBrowserReadWriteEnabled(const FeatureContext* context)
{
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsOriginTrialsSampleAPIBrowserReadWriteForceEnabled()) {
        return true;
    }
    if (context && context->GetRuntimeFeatureStateOverrideContext()->IsOriginTrialsSampleAPIBrowserReadWriteForceDisabled()) {
        return false;
    }

    if (is_origin_trials_sample_api_browser_read_write_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIBrowserReadWrite);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIDependentEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIEnabled(context))
        return false;
    if (is_origin_trials_sample_api_dependent_enabled_)
        return true;
    // The feature does not have an origin trial name and its runtime flag
    // is not enabled.
    return false;
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_deprecation_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIDeprecation);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIExpiryGracePeriodEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_expiry_grace_period_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIImpliedEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIInvalidOSEnabled(context))
        return true;
    if (is_origin_trials_sample_api_implied_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIImplied);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_invalid_os_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPINavigationEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_navigation_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPINavigation);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIPersistentFeatureEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_persistent_feature_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIPersistentInvalidOSEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_persistent_invalid_os_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIPersistentInvalidOS);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeature);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIThirdPartyEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_third_party_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIThirdParty);
}

bool RuntimeEnabledFeaturesBase::PageFreezeOptInEnabled(const FeatureContext* context)
{
    if (is_page_freeze_opt_in_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPageFreezeOptIn);
}

bool RuntimeEnabledFeaturesBase::PageFreezeOptOutEnabled(const FeatureContext* context)
{
    if (is_page_freeze_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPageFreezeOptOut);
}

bool RuntimeEnabledFeaturesBase::ParakeetEnabled(const FeatureContext* context)
{
    if (is_parakeet_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kParakeet);
}

bool RuntimeEnabledFeaturesBase::PerMethodCanMakePaymentQuotaEnabled(const FeatureContext* context)
{
    if (is_per_method_can_make_payment_quota_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPerMethodCanMakePaymentQuota);
}

bool RuntimeEnabledFeaturesBase::PermissionElementEnabled(const FeatureContext* context)
{
    if (is_permission_element_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPermissionElement);
}

bool RuntimeEnabledFeaturesBase::PNaClEnabled(const FeatureContext* context)
{
    if (is_p_na_cl_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPNaCl);
}

bool RuntimeEnabledFeaturesBase::PrefixedVideoFullscreenEnabled(const FeatureContext* context)
{
    if (is_prefixed_video_fullscreen_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPrefixedVideoFullscreen);
}

bool RuntimeEnabledFeaturesBase::PrivateNetworkAccessNonSecureContextsAllowedEnabled(const FeatureContext* context)
{
    if (is_private_network_access_non_secure_contexts_allowed_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed);
}

bool RuntimeEnabledFeaturesBase::PrivateNetworkAccessPermissionPromptEnabled(const FeatureContext* context)
{
    if (is_private_network_access_permission_prompt_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPrivateNetworkAccessPermissionPrompt);
}

bool RuntimeEnabledFeaturesBase::PrivateStateTokensEnabled(const FeatureContext* context)
{
    if (is_private_state_tokens_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kPrivateStateTokens);
}

bool RuntimeEnabledFeaturesBase::ProtectedOriginTrialsSampleAPIEnabled(const FeatureContext* context)
{
    if (get_is_protected_origin_trials_sample_api_enabled_())
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kProtectedOriginTrialsSampleAPI);
}

bool RuntimeEnabledFeaturesBase::ProtectedOriginTrialsSampleAPIDependentEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::ProtectedOriginTrialsSampleAPIEnabled(context))
        return false;
    if (get_is_protected_origin_trials_sample_api_dependent_enabled_())
        return true;
    // The feature does not have an origin trial name and its runtime flag
    // is not enabled.
    return false;
}

bool RuntimeEnabledFeaturesBase::ProtectedOriginTrialsSampleAPIImpliedEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::ProtectedOriginTrialsSampleAPIEnabled(context))
        return true;
    if (get_is_protected_origin_trials_sample_api_implied_enabled_())
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kProtectedOriginTrialsSampleAPIImplied);
}

bool RuntimeEnabledFeaturesBase::ReduceAcceptLanguageEnabled(const FeatureContext* context)
{
    if (is_reduce_accept_language_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kReduceAcceptLanguage);
}

bool RuntimeEnabledFeaturesBase::RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext* context)
{
    if (is_rtc_audio_jitter_buffer_max_packets_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kRtcAudioJitterBufferMaxPackets);
}

bool RuntimeEnabledFeaturesBase::RTCEncodedFrameSetMetadataEnabled(const FeatureContext* context)
{
    if (is_rtc_encoded_frame_set_metadata_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kRTCEncodedFrameSetMetadata);
}

bool RuntimeEnabledFeaturesBase::RTCLegacyCallbackBasedGetStatsEnabled(const FeatureContext* context)
{
    if (is_rtc_legacy_callback_based_get_stats_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kRTCLegacyCallbackBasedGetStats);
}

bool RuntimeEnabledFeaturesBase::RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext* context)
{
    if (is_rtc_stats_relative_packet_arrival_delay_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay);
}

bool RuntimeEnabledFeaturesBase::SecurePaymentConfirmationOptOutEnabled(const FeatureContext* context)
{
    if (is_secure_payment_confirmation_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kSecurePaymentConfirmationOptOut);
}

bool RuntimeEnabledFeaturesBase::ServiceWorkerStaticRouterEnabled(const FeatureContext* context)
{
    if (is_service_worker_static_router_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kServiceWorkerStaticRouter);
}

bool RuntimeEnabledFeaturesBase::ServiceWorkerStaticRouterTimingInfoEnabled(const FeatureContext* context)
{
    if (is_service_worker_static_router_timing_info_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kServiceWorkerStaticRouterTimingInfo);
}

bool RuntimeEnabledFeaturesBase::SignatureBasedIntegrityEnabled(const FeatureContext* context)
{
    if (is_signature_based_integrity_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kSignatureBasedIntegrity);
}

bool RuntimeEnabledFeaturesBase::SkipPreloadScanningEnabled(const FeatureContext* context)
{
    if (is_skip_preload_scanning_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kSkipPreloadScanning);
}

bool RuntimeEnabledFeaturesBase::SoftNavigationHeuristicsEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::NavigationIdEnabled(context))
        return false;
    if (!RuntimeEnabledFeaturesBase::SoftNavigationDetectionEnabled(context))
        return false;
    if (is_soft_navigation_heuristics_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kSoftNavigationHeuristics);
}

bool RuntimeEnabledFeaturesBase::SpeculationRulesPrefetchFutureEnabled(const FeatureContext* context)
{
    if (is_speculation_rules_prefetch_future_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kSpeculationRulesPrefetchFuture);
}

bool RuntimeEnabledFeaturesBase::StandardizedBrowserZoomOptOutEnabled(const FeatureContext* context)
{
    if (is_standardized_browser_zoom_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kStandardizedBrowserZoomOptOut);
}

bool RuntimeEnabledFeaturesBase::StorageAccessHeaderEnabled(const FeatureContext* context)
{
    if (is_storage_access_header_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kStorageAccessHeader);
}

bool RuntimeEnabledFeaturesBase::TextFragmentIdentifiersEnabled(const FeatureContext* context)
{
    if (is_text_fragment_identifiers_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kTextFragmentIdentifiers);
}

bool RuntimeEnabledFeaturesBase::TopLevelTpcdEnabled(const FeatureContext* context)
{
    if (is_top_level_tpcd_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kTopLevelTpcd);
}

bool RuntimeEnabledFeaturesBase::TouchEventFeatureDetectionEnabled(const FeatureContext* context)
{
    if (is_touch_event_feature_detection_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kTouchEventFeatureDetection);
}

bool RuntimeEnabledFeaturesBase::TpcdEnabled(const FeatureContext* context)
{
    if (is_tpcd_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kTpcd);
}

bool RuntimeEnabledFeaturesBase::TranslationAPIEnabled(const FeatureContext* context)
{
    if (is_translation_api_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kTranslationAPI);
}

bool RuntimeEnabledFeaturesBase::TranslationAPIEntryPointEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::TranslationAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::LanguageDetectionAPIEnabled(context))
        return true;
    if (is_translation_api_entry_point_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kTranslationAPIEntryPoint);
}

bool RuntimeEnabledFeaturesBase::UnrestrictedSharedArrayBufferEnabled(const FeatureContext* context)
{
    if (is_unrestricted_shared_array_buffer_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kUnrestrictedSharedArrayBuffer);
}

bool RuntimeEnabledFeaturesBase::ViewportSegmentsEnabled(const FeatureContext* context)
{
    if (is_viewport_segments_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kViewportSegments);
}

bool RuntimeEnabledFeaturesBase::WebAppLaunchQueueEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::FileHandlingEnabled(context))
        return true;
    if (is_web_app_launch_queue_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebAppLaunchQueue);
}

bool RuntimeEnabledFeaturesBase::WebAppScopeExtensionsEnabled(const FeatureContext* context)
{
    if (is_web_app_scope_extensions_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebAppScopeExtensions);
}

bool RuntimeEnabledFeaturesBase::WebAppUrlHandlingEnabled(const FeatureContext* context)
{
    if (is_web_app_url_handling_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebAppUrlHandling);
}

bool RuntimeEnabledFeaturesBase::WebAssemblyJSPromiseIntegrationEnabled(const FeatureContext* context)
{
    if (is_web_assembly_js_promise_integration_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebAssemblyJSPromiseIntegration);
}

bool RuntimeEnabledFeaturesBase::WebAssemblyJSStringBuiltinsEnabled(const FeatureContext* context)
{
    if (is_web_assembly_js_string_builtins_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebAssemblyJSStringBuiltins);
}

bool RuntimeEnabledFeaturesBase::WebAuthenticationAttestationFormatsEnabled(const FeatureContext* context)
{
    if (is_web_authentication_attestation_formats_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebAuthenticationAttestationFormats);
}

bool RuntimeEnabledFeaturesBase::WebGPUSubgroupsFeaturesEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::WebGPUExperimentalFeaturesEnabled(context))
        return true;
    if (is_webgpu_subgroups_features_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebGPUSubgroupsFeatures);
}

bool RuntimeEnabledFeaturesBase::WebIdentityDigitalCredentialsEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::FedCmEnabled(context))
        return false;
    if (is_web_identity_digital_credentials_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebIdentityDigitalCredentials);
}

bool RuntimeEnabledFeaturesBase::WebTransportCustomCertificatesEnabled(const FeatureContext* context)
{
    if (is_web_transport_custom_certificates_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebTransportCustomCertificates);
}

bool RuntimeEnabledFeaturesBase::WebViewXRequestedWithDeprecationEnabled(const FeatureContext* context)
{
    if (is_web_view_xr_equested_with_deprecation_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebViewXRequestedWithDeprecation);
}

bool RuntimeEnabledFeaturesBase::WebXRImageTrackingEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::WebXREnabled(context))
        return false;
    if (is_web_xr_image_tracking_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebXRImageTracking);
}

bool RuntimeEnabledFeaturesBase::WebXRPlaneDetectionEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::WebXREnabled(context))
        return false;
    if (is_web_xr_plane_detection_enabled_)
        return true;
    return context && context->FeatureEnabled(mojom::blink::OriginTrialFeature::kWebXRPlaneDetection);
}

bool RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_min_role_tabbable_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_os_level_bold_text_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_prohibited_names_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_serialization_size_metrics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_address_space_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ai_prompt_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_extension_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ai_prompt_api_for_web_platform_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ai_rewriter_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ai_summarization_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ai_writer_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_allow_java_script_to_reset_autofill_state_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_allow_preloading_with_csp_meta_tag_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_allow_ur_ns_in_iframes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_animation_progress_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_aria_owns_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_app_title_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aria_actions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aria_notify_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aria_row_col_index_text_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_atomic_move_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_attribution_reporting_cross_app_web_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_attribution_reporting_interface_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_audio_context_interrupted_state_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_audio_context_on_error_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_audio_context_playout_stats_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_nine_patch_track_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aura_scrollbar_uses_solid_color_thumb_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_video_heuristics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_back_forward_transitions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_background_fetch_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_kiosk_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_diagnostics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_web_view_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_web_view_media_integrity_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_lifecycle_script_forbidden_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_boundary_event_dispatch_tracks_node_removal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_box_decoration_break_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_break_iterator_hyphen_minus_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_buffered_bytes_consumer_limit_size_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_built_in_aiapi_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_bypass_pepc_security_for_testing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_calendar_picker_month_popup_button_disabled_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_call_exit_node_without_layout_object_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_canvas_filter_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_gpu_transfer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_layers_with_options_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_mesh_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_text_metrics_shaping_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_floating_point_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_place_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_uses_arc_paint_op_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capability_delegation_display_capture_request_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_caret_position_from_point_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_cct_new_rfm_push_behavior_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_check_if_highest_root_contains_position_anchor_node_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_check_visibility_extra_properties_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_clipboard_item_with_dom_string_support_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_clip_path_reject_empty_paths_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_coalesce_selectionchange_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composited_animations_cancelled_asynchronously_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compression_dictionary_transport_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_concurrent_view_transitions_spa_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_container_type_no_layout_containment_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_continue_event_timing_recording_when_buffer_is_full_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_controlled_frame_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cookie_deprecation_facilitated_testing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_coop_restrict_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_create_input_shadow_tree_during_layout_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_credential_manager_report_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_cross_frame_performance_timeline_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_accent_color_keyword_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_advanced_attr_function_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_anchor_scope_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_anchor_size_insets_margins_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_at_property_string_syntax_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_background_clip_unprefix_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_calc_size_function_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_caret_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_cascade_correct_scope_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_computed_style_full_pseudo_element_parser_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_cross_fade_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_custom_state_deprecated_syntax_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_custom_state_new_syntax_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_dynamic_range_limit_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_exponential_functions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_flat_tree_container_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_functions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_gap_decoration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_inert_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_inset_area_property_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_keyframes_rule_length_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_lazy_parsing_fast_path_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_line_clamp_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_line_clamp_webkit_box_blockification_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_masonry_layout_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_mixins_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_nested_declarations_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_nested_pseudo_elements_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_overflow_container_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_parser_ignore_charset_for_urls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_part_allows_more_selectors_after_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_position_area_value_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_progress_notation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_column_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_has_slotted_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_open_closed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_buttons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_scroll_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_reading_flow_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_relative_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_relative_color_late_resolve_always_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_relative_color_preserve_none_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_relative_color_supports_currentcolor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_resize_auto_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_scroll_snap_change_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_scroll_snap_changing_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_scroll_snap_events_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_scroll_start_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_scroll_start_target_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_scroll_state_container_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_sign_related_functions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_snap_container_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_stepped_value_functions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_sticky_container_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_supports_at_rule_function_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_supports_for_import_rules_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_system_accent_color_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_text_auto_space_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_text_box_trim_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_text_spacing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_tree_scoped_timelines_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_user_select_contain_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_view_transition_auto_name_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_view_transition_class_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_cursor_anchor_info_mojo_pipe_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_customizable_select_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_database_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_deprecated_request_adapter_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_deprecate_unload_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_desktop_pw_as_additional_windowing_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_details_styling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_posture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_dialog_close_when_open_removed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_dialog_element_toggle_events_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_dialog_new_focus_behavior_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_dir_auto_fix_slot_exclusions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_disable_ahem_antialias_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_disable_reduce_accept_language_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_disable_select_all_for_empty_text_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_disable_third_party_storage_partitioning_2_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_dispatch_before_input_for_spin_button_interactions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_dispatch_hidden_visibility_transitions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_dispatch_selectionchange_event_per_element_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_display_contents_focusable_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_cookie_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_domain_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_install_chunking_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_isolation_policy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_open_origin_alias_removal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_open_sandbox_inheritance_removal_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_expect_no_linked_resources_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_include_js_call_stacks_in_crash_reports_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_render_blocking_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_write_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_dom_parts_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_dom_parts_api_minimal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_dynamic_safe_area_insets_on_scroll_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_element_get_inner_html_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_enforce_anonymity_exposure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_escape_lt_gt_in_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_event_timing_handle_keyboard_event_simulated_click_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_event_timing_interaction_count_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_event_timing_selection_auto_scroll_no_interaction_id_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_event_timing_tap_stop_scroll_no_interaction_id_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_exclude_transparent_texts_from_being_lcp_eligible_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_experimental_machine_learning_neural_network_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_expose_coarsened_render_time_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_expose_render_time_non_tao_delayed_image_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_face_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fast_non_composited_scroll_hit_test_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fast_path_single_selector_exact_match_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fast_position_iterator_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_authz_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_auto_selected_flag_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_button_mode_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_disconnect_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_domain_hint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_error_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_id_p_registration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_selective_disclosure_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_with_storage_access_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fenced_frames_api_changes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fenced_frames_default_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fenced_frames_local_unpartitioned_data_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fetch_body_bytes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fetch_later_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_locking_scheme_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_observer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_observer_unobserve_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_find_decomposed_in_short_text_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_find_ruby_in_page_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_find_text_in_readonly_text_input_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_find_text_skip_collapsed_text_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_auction_deal_support_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fledge_bidding_and_auction_server_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_custom_max_auction_ad_components_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_deprecated_render_url_replacements_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_direct_from_seller_signals_header_ad_slot_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_multi_bid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_real_time_reporting_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_reporting_timeout_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_seller_nonce_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fledge_trusted_signals_k_vv_2_support_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fluent_overlay_scrollbars_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fluent_scrollbar_uses_nine_patch_track_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_focusgroup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fontations_font_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fontations_for_selected_formats_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_family_postscript_matching_ct_migration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_font_family_style_matching_ct_migration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_font_present_win_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_font_system_fallback_noto_cjk_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_variant_emoji_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_variation_sequences_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_forced_colors_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_form_control_restore_state_if_autocomplete_off_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_form_controls_vertical_writing_mode_direction_support_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_gamepad_multitouch_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_all_screens_media_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_requires_user_activation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_group_effect_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handle_selection_change_on_deleting_empty_element_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_hanging_whitespace_does_not_depend_on_alignment_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_has_ua_visual_transition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_highlights_from_point_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_hit_test_opaqueness_omit_line_box_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_href_translate_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_html_anchor_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_dialog_light_dismiss_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_embed_element_not_force_layout_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_html_interest_target_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_invoke_actions_v_2_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_invoke_target_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_object_element_fallback_detach_content_frame_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_html_parser_yield_and_delay_often_for_testing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_popover_action_hover_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_popover_hint_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_select_element_show_picker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_import_attributes_disallow_unknown_keys_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_import_map_integrity_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_incoming_call_notifications_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_indexed_db_get_all_records_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_inert_element_non_editable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_inert_element_non_searchable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_inherit_user_modify_without_contenteditable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_initial_letter_raise_by_specified_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_inline_block_in_same_line_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_inner_html_parser_fastpath_log_failure_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_closes_select_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_insert_blockquote_before_outer_block_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_inspector_ghost_rules_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_installed_app_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_install_on_device_speech_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_interest_groups_in_shared_storage_worklet_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_interoperable_private_attribution_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_intersection_observer_scroll_margin_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_inverted_colors_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_invisible_svg_animation_throttling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_always_runtime_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_java_script_compile_hints_magic_runtime_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_keep_css_target_after_reattach_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_label_and_delegates_focus_new_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_language_detection_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_layout_flex_new_row_algorithm_v_3_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_layout_ignore_margins_for_sticky_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_layout_justify_self_for_blocks_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_shape_cache_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_layout_stretch_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_lazy_load_scroll_margin_iframe_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_limit_third_party_cookies_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_line_box_below_leading_floats_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_list_item_with_counter_set_not_set_explicit_value_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_locked_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_long_animation_frame_timing_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_long_press_link_select_text_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_long_task_from_long_animation_frame_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_measure_memory_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_camera_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_configuration_change_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_voice_isolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_playback_while_not_visible_permission_policy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_previews_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_recorder_use_media_video_encoder_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_session_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_session_chapter_information_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_session_enter_picture_in_picture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_stream_track_web_speech_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_message_port_close_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_meta_refresh_no_fractional_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_meter_appearance_none_fallback_style_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_meter_devolve_appearance_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_minimimal_resource_request_prep_before_cache_lookup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_modify_paragraph_cross_editingoundary_enabled_ = true;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_mojo_js_enabled_;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_mojo_js_test_enabled_;
bool RuntimeEnabledFeaturesBase::is_move_ending_selection_to_list_child_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_move_to_paragraph_start_or_end_skips_non_editable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_multiple_import_maps_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_multi_select_deselect_when_only_option_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_multi_smooth_scroll_into_view_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_mutation_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_mutation_events_special_trial_message_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigate_event_commit_behavior_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigate_event_source_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigation_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_navigation_id_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_nested_view_transition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_net_info_constant_type_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_new_get_focusable_area_behavior_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_no_increasing_end_offset_on_splitting_text_nodes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_non_empty_blockquotes_on_outdenting_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_non_null_input_event_data_for_text_area_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_non_standard_appearance_value_slider_vertical_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notifications_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_observable_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_omit_blur_event_on_element_removal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_web_speech_available_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_origin_policy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_browser_read_write_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_invalid_os_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_margin_boxes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_page_reveal_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_page_swap_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_paint_highlights_for_first_letter_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_paint_holding_for_iframes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_paint_holding_for_local_iframes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_parakeet_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_partitioned_popins_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_password_reveal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_app_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_instruments_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_link_detection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_payment_request_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_performance_mark_feature_usage_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_performance_navigate_system_entropy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_performance_navigation_timing_confidence_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permissions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_pointer_event_device_id_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_pointer_event_targets_in_event_lists_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_popover_anchor_relationships_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_popover_dialog_new_focus_behavior_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_position_outside_tab_span_check_sibling_node_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefer_default_scrollbar_styles_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prerender_2_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_presentation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_preserve_following_block_styles_during_block_merge_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_prevent_undo_if_not_editable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_private_aggregation_api_filtering_ids_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_private_network_access_null_ip_address_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_private_state_tokens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_private_state_tokens_always_allow_issuance_enabled_ = false;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_protected_origin_trials_sample_api_enabled_;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_protected_origin_trials_sample_api_dependent_enabled_;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_protected_origin_trials_sample_api_implied_enabled_;
bool RuntimeEnabledFeaturesBase::is_pseudo_elements_correct_in_get_computed_style_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_pseudo_elements_focusable_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_push_message_data_bytes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_push_messaging_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_raster_inducing_scroll_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_readable_stream_async_iterable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_reduce_accept_language_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_cookie_ip_cs_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_rel_opener_bcg_dependency_hint_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_remote_playback_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remove_collapsed_placeholder_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remove_dangling_markup_in_target_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remove_data_url_in_svg_use_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remove_node_having_children_if_fully_selected_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remove_visible_selection_in_dom_selection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_render_blocking_inline_module_script_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_report_event_timing_at_visibility_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_reset_input_type_to_none_before_character_input_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_resource_timing_content_type_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_resource_timing_final_response_headers_start_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_resource_timing_use_cors_for_body_sizes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reuse_shape_results_by_fonts_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_rewind_floats_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_root_element_with_place_holder_after_deleting_selection_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_data_channel_priority_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_encoded_audio_frame_abs_capture_time_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_encoded_frame_set_metadata_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_encoded_video_frame_additional_metadata_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_jitter_buffer_target_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_rtc_legacy_callback_based_get_stats_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_rtp_encoding_parameters_codec_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_rtc_rtp_scale_resolution_down_to_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_rtc_rtp_script_transform_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_rtp_transport_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_ruby_short_heuristics_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scheduler_yield_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scrollbar_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scroll_into_view_root_frame_viewport_bug_fix_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scroll_timeline_current_time_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_search_text_highlight_pseudo_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_network_and_issuer_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_selectedcontentelement_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_selection_across_shadow_dom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_selection_is_collapsed_shadow_dom_support_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_selection_on_shadow_dom_with_delegates_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_select_option_accessibility_target_size_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_parser_relaxation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_select_popup_less_updates_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serialize_view_transition_state_in_spa_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_service_worker_static_router_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_service_worker_static_router_timing_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_set_sequential_focus_starting_point_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shadow_root_reference_target_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shape_outside_writing_mode_fix_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shape_result_cached_previous_safe_to_break_offset_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_storage_api_m_118_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_storage_api_m_125_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_storage_web_locks_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_sideways_writing_modes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_skip_ad_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_skip_preload_scanning_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_skip_temporary_document_fragment_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smil_auto_suspend_on_lag_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_soft_navigation_detection_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speaker_selection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_down_heuristics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_pointer_hover_heuristics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_future_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_standardized_browser_zoom_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_static_animation_optimization_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_storage_access_header_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_storage_buckets_durability_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_storage_buckets_locks_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_stricter_cell_width_content_size_quirk_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_svg_context_paint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_cross_origin_attribute_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_eager_pres_attr_style_update_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_external_resources_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_filter_user_space_viewport_for_non_svg_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_gradient_color_interpolation_linear_rgb_support_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_no_pixel_snapping_scale_adjustment_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_transform_optimization_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_system_fallback_emoji_vs_support_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_blink_feature_default_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_feature_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_ = false;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_test_feature_protected_enabled_;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_test_feature_protected_dependent_enabled_;
DEFINE_PROTECTED_DATA base::ProtectedMemory<bool> RuntimeEnabledFeaturesBase::is_test_feature_protected_implied_enabled_;
bool RuntimeEnabledFeaturesBase::is_test_feature_stable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_diff_split_fix_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_input_not_always_dir_auto_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_metrics_baselines_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_segment_boundary_for_element_with_float_style_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_size_adjust_improvements_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_transform_and_security_fix_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_timeline_scope_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_timestamp_based_cls_tracking_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_topics_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_topics_document_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_top_layer_inactive_document_exceptions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_top_level_tpcd_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_touch_text_editing_redesign_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_tpcd_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_transferable_rtc_data_channel_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_translate_service_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_translation_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_translation_api_entry_point_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trusted_types_from_literal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unowned_animations_skip_css_events_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_unrestricted_measure_user_agent_specific_memory_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unrestricted_usb_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_url_search_params_has_and_delete_multiple_args_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_selection_focus_node_for_caret_navigation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_use_undo_step_element_dispatch_before_input_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_frame_metadata_background_blur_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_viewport_changes_update_text_autosizing_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_view_transition_disable_snap_browser_controls_on_hidden_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_view_transition_layered_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_view_transition_long_callback_timeout_for_testing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_view_transition_on_navigation_for_iframes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_view_transition_overflow_rect_from_surface_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_view_transition_tree_scoped_names_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_view_transition_types_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_visual_viewport_on_scroll_end_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_wake_lock_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_installation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_scope_extensions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_assembly_js_promise_integration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_assembly_js_string_builtins_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_audio_bypass_output_buffering_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_auth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_ambient_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_attestation_formats_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_client_capabilities_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_js_on_serialization_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_authentication_prf_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_supplemental_pub_keys_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webcodecs_copy_to_rgb_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webcodecs_hbd_formats_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webcodecs_orientation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webcodecs_video_encoder_buffers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_crypto_curve_25519_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_font_resize_lcp_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgl_drawing_buffer_storage_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_canvas_context_get_configuration_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_device_adapter_info_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webgpu_experimental_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_hdr_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webgpu_subgroups_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_texture_view_usage_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_on_dedicated_workers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_identity_digital_credentials_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_idl_big_int_uses_to_big_int_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_otp_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_preferences_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_share_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_transport_stats_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_usb_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_view_xr_equested_with_deprecation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_enabled_features_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_frame_rate_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_front_facing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_gpu_binding_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_layers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_layers_common_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_pose_motion_data_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_spec_parity_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_window_default_status_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_xml_parser_merge_adjacent_c_data_sections_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_ = false;

// Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

#if BUILDFLAG(IS_WIN)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

#if BUILDFLAG(IS_MAC)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

#if BUILDFLAG(IS_LINUX)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

#if BUILDFLAG(IS_IOS)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

// Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC)                        \
    && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_IOS)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_controller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_captured_mouse_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_captured_surface_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composition_foreground_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_prefer_initial_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_user_activation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_element_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_get_cloud_identifiers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_insert_line_break_if_phrasing_content_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_partition_visited_link_database_with_self_links_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permission_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_android_version_device_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_report_visible_line_bounds_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_schedule_selection_change_on_backspace_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_select_audio_output_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_connected_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_smart_card_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_smart_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_begin_frame_presentation_feedback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_use_low_quality_interpolation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_customizations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_printing_enabled_ = false;
#endif

// Simple getter methods for protected memory values that ensure they are
// properly initialized before first access.
bool RuntimeEnabledFeaturesBase::get_is_mojo_js_enabled_()
{
    static base::ProtectedMemoryInitializer is_mojo_js_enabled_initializer(is_mojo_js_enabled_, false);
    return *is_mojo_js_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_mojo_js_test_enabled_()
{
    static base::ProtectedMemoryInitializer is_mojo_js_test_enabled_initializer(is_mojo_js_test_enabled_, false);
    return *is_mojo_js_test_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_protected_origin_trials_sample_api_enabled_()
{
    static base::ProtectedMemoryInitializer is_protected_origin_trials_sample_api_enabled_initializer(is_protected_origin_trials_sample_api_enabled_, false);
    return *is_protected_origin_trials_sample_api_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_protected_origin_trials_sample_api_dependent_enabled_()
{
    static base::ProtectedMemoryInitializer is_protected_origin_trials_sample_api_dependent_enabled_initializer(
        is_protected_origin_trials_sample_api_dependent_enabled_, false);
    return *is_protected_origin_trials_sample_api_dependent_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_protected_origin_trials_sample_api_implied_enabled_()
{
    static base::ProtectedMemoryInitializer is_protected_origin_trials_sample_api_implied_enabled_initializer(
        is_protected_origin_trials_sample_api_implied_enabled_, false);
    return *is_protected_origin_trials_sample_api_implied_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_test_feature_protected_enabled_()
{
    static base::ProtectedMemoryInitializer is_test_feature_protected_enabled_initializer(is_test_feature_protected_enabled_, false);
    return *is_test_feature_protected_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_test_feature_protected_dependent_enabled_()
{
    static base::ProtectedMemoryInitializer is_test_feature_protected_dependent_enabled_initializer(is_test_feature_protected_dependent_enabled_, false);
    return *is_test_feature_protected_dependent_enabled_;
}
bool RuntimeEnabledFeaturesBase::get_is_test_feature_protected_implied_enabled_()
{
    static base::ProtectedMemoryInitializer is_test_feature_protected_implied_enabled_initializer(is_test_feature_protected_implied_enabled_, false);
    return *is_test_feature_protected_implied_enabled_;
}

} // namespace blink
