// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_

#include <string>

#include "base/gtest_prod_util.h"
#include "base/memory/protected_memory.h"
#include "third_party/blink/renderer/platform/platform_export.h"
#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"

#define ASSERT_ORIGIN_TRIAL(feature)                                                                                                                           \
    static_assert(                                                                                                                                             \
        std::is_same<decltype(::blink::RuntimeEnabledFeatures::feature##EnabledByRuntimeFlag()), bool>(), #feature " must be part of an origin trial");

namespace blink {

class FeatureContext;

// A class that stores static enablers for all experimental features.

class PLATFORM_EXPORT RuntimeEnabledFeaturesBase {
    STATIC_ONLY(RuntimeEnabledFeaturesBase);

public:
    class PLATFORM_EXPORT Backup {
    public:
        explicit Backup();
        void Restore();

    private:
        bool is_accelerated_2d_canvas_enabled_;
        bool is_accelerated_small_canvases_enabled_;
        bool is_accessibility_aria_virtual_content_enabled_;
        bool is_accessibility_expose_display_none_enabled_;
        bool is_accessibility_min_role_tabbable_enabled_;
        bool is_accessibility_os_level_bold_text_enabled_;
        bool is_accessibility_prohibited_names_enabled_;
        bool is_accessibility_serialization_size_metrics_enabled_;
        bool is_accessibility_use_ax_position_for_document_markers_enabled_;
        bool is_address_space_enabled_;
        bool is_ad_interest_group_api_enabled_;
        bool is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_;
        bool is_ad_tagging_enabled_;
        bool is_ai_prompt_api_enabled_;
        bool is_ai_prompt_api_for_extension_enabled_;
        bool is_ai_prompt_api_for_web_platform_enabled_;
        bool is_ai_rewriter_api_enabled_;
        bool is_ai_summarization_api_enabled_;
        bool is_ai_writer_api_enabled_;
        bool is_allow_content_initiated_data_url_navigations_enabled_;
        bool is_allow_java_script_to_reset_autofill_state_enabled_;
        bool is_allow_preloading_with_csp_meta_tag_enabled_;
        bool is_allow_ur_ns_in_iframes_enabled_;
        bool is_android_downloadable_fonts_matching_enabled_;
        bool is_animation_progress_api_enabled_;
        bool is_animation_worklet_enabled_;
        bool is_anonymous_iframe_enabled_;
        bool is_aom_aria_relationship_properties_enabled_;
        bool is_aom_aria_relationship_properties_aria_owns_enabled_;
        bool is_app_title_enabled_;
        bool is_aria_actions_enabled_;
        bool is_aria_notify_enabled_;
        bool is_aria_row_col_index_text_enabled_;
        bool is_atomic_move_api_enabled_;
        bool is_attribution_reporting_enabled_;
        bool is_attribution_reporting_cross_app_web_enabled_;
        bool is_attribution_reporting_interface_enabled_;
        bool is_audio_context_interrupted_state_enabled_;
        bool is_audio_context_on_error_enabled_;
        bool is_audio_context_playout_stats_enabled_;
        bool is_audio_context_set_sink_id_enabled_;
        bool is_audio_output_devices_enabled_;
        bool is_audio_video_tracks_enabled_;
        bool is_aura_scrollbar_uses_nine_patch_track_enabled_;
        bool is_aura_scrollbar_uses_solid_color_thumb_enabled_;
        bool is_auto_dark_mode_enabled_;
        bool is_automation_controlled_enabled_;
        bool is_auto_picture_in_picture_video_heuristics_enabled_;
        bool is_backface_visibility_interop_enabled_;
        bool is_back_forward_cache_enabled_;
        bool is_back_forward_cache_experiment_http_header_enabled_;
        bool is_back_forward_cache_not_restored_reasons_enabled_;
        bool is_back_forward_transitions_enabled_;
        bool is_background_fetch_enabled_;
        bool is_barcode_detector_enabled_;
        bool is_bidi_caret_affinity_enabled_;
        bool is_blink_extension_chrome_os_enabled_;
        bool is_blink_extension_chrome_os_kiosk_enabled_;
        bool is_blink_extension_diagnostics_enabled_;
        bool is_blink_extension_web_view_enabled_;
        bool is_blink_extension_web_view_media_integrity_enabled_;
        bool is_blink_lifecycle_script_forbidden_enabled_;
        bool is_blink_runtime_call_stats_enabled_;
        bool is_blocking_focus_without_user_activation_enabled_;
        bool is_boundary_event_dispatch_tracks_node_removal_enabled_;
        bool is_box_decoration_break_enabled_;
        bool is_break_iterator_hyphen_minus_enabled_;
        bool is_browser_verified_user_activation_keyboard_enabled_;
        bool is_browser_verified_user_activation_mouse_enabled_;
        bool is_buffered_bytes_consumer_limit_size_enabled_;
        bool is_built_in_aiapi_enabled_;
        bool is_bypass_pepc_security_for_testing_enabled_;
        bool is_cache_storage_code_cache_hint_enabled_;
        bool is_calendar_picker_month_popup_button_disabled_color_enabled_;
        bool is_call_exit_node_without_layout_object_enabled_;
        bool is_canvas_2d_canvas_filter_enabled_;
        bool is_canvas_2d_gpu_transfer_enabled_;
        bool is_canvas_2d_image_chromium_enabled_;
        bool is_canvas_2d_layers_enabled_;
        bool is_canvas_2d_layers_with_options_enabled_;
        bool is_canvas_2d_mesh_enabled_;
        bool is_canvas_2d_text_metrics_shaping_enabled_;
        bool is_canvas_floating_point_enabled_;
        bool is_canvas_hdr_enabled_;
        bool is_canvas_image_smoothing_enabled_;
        bool is_canvas_place_element_enabled_;
        bool is_canvas_uses_arc_paint_op_enabled_;
        bool is_capability_delegation_display_capture_request_enabled_;
        bool is_capture_controller_enabled_;
        bool is_captured_mouse_events_enabled_;
        bool is_captured_surface_control_enabled_;
        bool is_capture_handle_enabled_;
        bool is_caret_position_from_point_enabled_;
        bool is_cct_new_rfm_push_behavior_enabled_;
        bool is_check_if_highest_root_contains_position_anchor_node_enabled_;
        bool is_check_visibility_extra_properties_enabled_;
        bool is_click_to_captured_pointer_enabled_;
        bool is_clipboard_item_with_dom_string_support_enabled_;
        bool is_clip_path_reject_empty_paths_enabled_;
        bool is_coalesce_selectionchange_event_enabled_;
        bool is_coep_reflection_enabled_;
        bool is_composite_bg_color_animation_enabled_;
        bool is_composite_box_shadow_animation_enabled_;
        bool is_composite_clip_path_animation_enabled_;
        bool is_composited_animations_cancelled_asynchronously_enabled_;
        bool is_composited_selection_update_enabled_;
        bool is_composition_foreground_markers_enabled_;
        bool is_compression_dictionary_transport_enabled_;
        bool is_compression_dictionary_transport_backend_enabled_;
        bool is_computed_accessibility_info_enabled_;
        bool is_compute_pressure_enabled_;
        bool is_concurrent_view_transitions_spa_enabled_;
        bool is_contacts_manager_enabled_;
        bool is_contacts_manager_extra_properties_enabled_;
        bool is_container_type_no_layout_containment_enabled_;
        bool is_content_index_enabled_;
        bool is_context_menu_enabled_;
        bool is_continue_event_timing_recording_when_buffer_is_full_enabled_;
        bool is_controlled_frame_enabled_;
        bool is_cookie_deprecation_facilitated_testing_enabled_;
        bool is_cooperative_scheduling_enabled_;
        bool is_coop_restrict_properties_enabled_;
        bool is_cors_rfc_1918_enabled_;
        bool is_create_input_shadow_tree_during_layout_enabled_;
        bool is_credential_manager_report_enabled_;
        bool is_cross_frame_performance_timeline_enabled_;
        bool is_css_accent_color_keyword_enabled_;
        bool is_css_advanced_attr_function_enabled_;
        bool is_css_anchor_scope_enabled_;
        bool is_css_anchor_size_insets_margins_enabled_;
        bool is_css_at_property_string_syntax_enabled_;
        bool is_css_at_rule_counter_style_image_symbols_enabled_;
        bool is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
        bool is_css_background_clip_unprefix_enabled_;
        bool is_css_calc_simplification_and_serialization_enabled_;
        bool is_css_calc_size_function_enabled_;
        bool is_css_caret_animation_enabled_;
        bool is_css_cascade_correct_scope_enabled_;
        bool is_css_case_sensitive_selector_enabled_;
        bool is_css_color_contrast_enabled_;
        bool is_css_color_typed_om_enabled_;
        bool is_css_computed_style_full_pseudo_element_parser_enabled_;
        bool is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_;
        bool is_css_cross_fade_enabled_;
        bool is_css_custom_state_deprecated_syntax_enabled_;
        bool is_css_custom_state_new_syntax_enabled_;
        bool is_css_dynamic_range_limit_enabled_;
        bool is_css_enumerated_custom_properties_enabled_;
        bool is_css_exponential_functions_enabled_;
        bool is_css_flat_tree_container_enabled_;
        bool is_css_font_size_adjust_enabled_;
        bool is_css_functions_enabled_;
        bool is_css_gap_decoration_enabled_;
        bool is_css_hex_alpha_color_enabled_;
        bool is_css_inert_enabled_;
        bool is_css_inset_area_property_enabled_;
        bool is_css_keyframes_rule_length_enabled_;
        bool is_css_layout_api_enabled_;
        bool is_css_lazy_parsing_fast_path_enabled_;
        bool is_css_line_clamp_enabled_;
        bool is_css_line_clamp_webkit_box_blockification_enabled_;
        bool is_css_logical_overflow_enabled_;
        bool is_css_marker_nested_pseudo_element_enabled_;
        bool is_css_masonry_layout_enabled_;
        bool is_css_mixins_enabled_;
        bool is_css_nested_declarations_enabled_;
        bool is_css_nested_pseudo_elements_enabled_;
        bool is_css_overflow_container_queries_enabled_;
        bool is_css_paint_api_arguments_enabled_;
        bool is_css_parser_ignore_charset_for_urls_enabled_;
        bool is_css_part_allows_more_selectors_after_enabled_;
        bool is_css_position_area_value_enabled_;
        bool is_css_position_sticky_static_scroll_position_enabled_;
        bool is_css_progress_notation_enabled_;
        bool is_css_pseudo_column_enabled_;
        bool is_css_pseudo_has_slotted_enabled_;
        bool is_css_pseudo_open_closed_enabled_;
        bool is_css_pseudo_playing_paused_enabled_;
        bool is_css_pseudo_scroll_buttons_enabled_;
        bool is_css_pseudo_scroll_markers_enabled_;
        bool is_css_reading_flow_enabled_;
        bool is_css_relative_color_enabled_;
        bool is_css_relative_color_late_resolve_always_enabled_;
        bool is_css_relative_color_preserve_none_enabled_;
        bool is_css_relative_color_supports_currentcolor_enabled_;
        bool is_css_resize_auto_enabled_;
        bool is_css_scroll_snap_change_event_enabled_;
        bool is_css_scroll_snap_changing_event_enabled_;
        bool is_css_scroll_snap_events_enabled_;
        bool is_css_scroll_start_enabled_;
        bool is_css_scroll_start_target_enabled_;
        bool is_css_scroll_state_container_queries_enabled_;
        bool is_css_selector_fragment_anchor_enabled_;
        bool is_css_sign_related_functions_enabled_;
        bool is_css_snap_container_queries_enabled_;
        bool is_css_stepped_value_functions_enabled_;
        bool is_css_sticky_container_queries_enabled_;
        bool is_css_supports_at_rule_function_enabled_;
        bool is_css_supports_for_import_rules_enabled_;
        bool is_css_system_accent_color_enabled_;
        bool is_css_text_auto_space_enabled_;
        bool is_css_text_box_trim_enabled_;
        bool is_css_text_spacing_enabled_;
        bool is_css_tree_scoped_timelines_enabled_;
        bool is_css_user_select_contain_enabled_;
        bool is_css_video_dynamic_range_media_queries_enabled_;
        bool is_css_view_transition_auto_name_enabled_;
        bool is_css_view_transition_class_enabled_;
        bool is_cursor_anchor_info_mojo_pipe_enabled_;
        bool is_customizable_select_enabled_;
        bool is_database_enabled_;
        bool is_deprecated_request_adapter_info_enabled_;
        bool is_deprecate_unload_opt_out_enabled_;
        bool is_desktop_capture_disable_local_echo_control_enabled_;
        bool is_desktop_pw_as_additional_windowing_controls_enabled_;
        bool is_desktop_pw_as_sub_apps_enabled_;
        bool is_details_styling_enabled_;
        bool is_device_attributes_enabled_;
        bool is_device_orientation_request_permission_enabled_;
        bool is_device_posture_enabled_;
        bool is_dialog_close_when_open_removed_enabled_;
        bool is_dialog_element_toggle_events_enabled_;
        bool is_dialog_new_focus_behavior_enabled_;
        bool is_digital_goods_enabled_;
        bool is_digital_goods_v_2_1_enabled_;
        bool is_dir_auto_fix_slot_exclusions_enabled_;
        bool is_direct_sockets_enabled_;
        bool is_disable_ahem_antialias_enabled_;
        bool is_disable_different_origin_subframe_dialog_suppression_enabled_;
        bool is_disable_hardware_noise_suppression_enabled_;
        bool is_disable_reduce_accept_language_enabled_;
        bool is_disable_select_all_for_empty_text_enabled_;
        bool is_disable_third_party_storage_partitioning_2_enabled_;
        bool is_dispatch_before_input_for_spin_button_interactions_enabled_;
        bool is_dispatch_hidden_visibility_transitions_enabled_;
        bool is_dispatch_selectionchange_event_per_element_enabled_;
        bool is_display_contents_focusable_enabled_;
        bool is_display_cutout_api_enabled_;
        bool is_document_cookie_enabled_;
        bool is_document_domain_enabled_;
        bool is_document_install_chunking_enabled_;
        bool is_document_isolation_policy_enabled_;
        bool is_document_open_origin_alias_removal_enabled_;
        bool is_document_open_sandbox_inheritance_removal_enabled_;
        bool is_document_picture_in_picture_api_enabled_;
        bool is_document_picture_in_picture_prefer_initial_placement_enabled_;
        bool is_document_picture_in_picture_user_activation_enabled_;
        bool is_document_policy_document_domain_enabled_;
        bool is_document_policy_expect_no_linked_resources_enabled_;
        bool is_document_policy_include_js_call_stacks_in_crash_reports_enabled_;
        bool is_document_policy_negotiation_enabled_;
        bool is_document_policy_sync_xhr_enabled_;
        bool is_document_render_blocking_enabled_;
        bool is_document_write_enabled_;
        bool is_dom_parts_api_enabled_;
        bool is_dom_parts_api_minimal_enabled_;
        bool is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_;
        bool is_dynamic_safe_area_insets_enabled_;
        bool is_dynamic_safe_area_insets_on_scroll_enabled_;
        bool is_element_capture_enabled_;
        bool is_element_get_inner_html_enabled_;
        bool is_enforce_anonymity_exposure_enabled_;
        bool is_escape_lt_gt_in_attributes_enabled_;
        bool is_event_timing_handle_keyboard_event_simulated_click_enabled_;
        bool is_event_timing_interaction_count_enabled_;
        bool is_event_timing_selection_auto_scroll_no_interaction_id_enabled_;
        bool is_event_timing_tap_stop_scroll_no_interaction_id_enabled_;
        bool is_exclude_transparent_texts_from_being_lcp_eligible_enabled_;
        bool is_experimental_content_security_policy_features_enabled_;
        bool is_experimental_js_profiler_markers_enabled_;
        bool is_experimental_machine_learning_neural_network_enabled_;
        bool is_experimental_policies_enabled_;
        bool is_expose_coarsened_render_time_enabled_;
        bool is_expose_render_time_non_tao_delayed_image_enabled_;
        bool is_extended_text_metrics_enabled_;
        bool is_eye_dropper_api_enabled_;
        bool is_face_detector_enabled_;
        bool is_fast_non_composited_scroll_hit_test_enabled_;
        bool is_fast_path_single_selector_exact_match_enabled_;
        bool is_fast_position_iterator_enabled_;
        bool is_fed_cm_enabled_;
        bool is_fed_cm_authz_enabled_;
        bool is_fed_cm_auto_selected_flag_enabled_;
        bool is_fed_cm_button_mode_enabled_;
        bool is_fed_cm_disconnect_enabled_;
        bool is_fed_cm_domain_hint_enabled_;
        bool is_fed_cm_error_enabled_;
        bool is_fed_cm_id_p_registration_enabled_;
        bool is_fed_cm_idp_signin_status_enabled_;
        bool is_fed_cm_multiple_identity_providers_enabled_;
        bool is_fed_cm_selective_disclosure_enabled_;
        bool is_fed_cm_with_storage_access_api_enabled_;
        bool is_fenced_frames_enabled_;
        bool is_fenced_frames_api_changes_enabled_;
        bool is_fenced_frames_default_mode_enabled_;
        bool is_fenced_frames_local_unpartitioned_data_access_enabled_;
        bool is_fetch_body_bytes_enabled_;
        bool is_fetch_later_api_enabled_;
        bool is_fetch_upload_streaming_enabled_;
        bool is_file_handling_enabled_;
        bool is_file_handling_icons_enabled_;
        bool is_file_system_enabled_;
        bool is_file_system_access_enabled_;
        bool is_file_system_access_api_experimental_enabled_;
        bool is_file_system_access_get_cloud_identifiers_enabled_;
        bool is_file_system_access_local_enabled_;
        bool is_file_system_access_locking_scheme_enabled_;
        bool is_file_system_access_origin_private_enabled_;
        bool is_file_system_observer_enabled_;
        bool is_file_system_observer_unobserve_enabled_;
        bool is_find_decomposed_in_short_text_enabled_;
        bool is_find_ruby_in_page_enabled_;
        bool is_find_text_in_readonly_text_input_enabled_;
        bool is_find_text_skip_collapsed_text_enabled_;
        bool is_fledge_enabled_;
        bool is_fledge_auction_deal_support_enabled_;
        bool is_fledge_bidding_and_auction_server_api_enabled_;
        bool is_fledge_custom_max_auction_ad_components_enabled_;
        bool is_fledge_deprecated_render_url_replacements_enabled_;
        bool is_fledge_direct_from_seller_signals_header_ad_slot_enabled_;
        bool is_fledge_multi_bid_enabled_;
        bool is_fledge_real_time_reporting_enabled_;
        bool is_fledge_reporting_timeout_enabled_;
        bool is_fledge_seller_nonce_enabled_;
        bool is_fledge_trusted_signals_k_vv_2_support_enabled_;
        bool is_fluent_overlay_scrollbars_enabled_;
        bool is_fluent_scrollbars_enabled_;
        bool is_fluent_scrollbar_uses_nine_patch_track_enabled_;
        bool is_focusgroup_enabled_;
        bool is_font_access_enabled_;
        bool is_fontations_font_backend_enabled_;
        bool is_fontations_for_selected_formats_enabled_;
        bool is_font_family_postscript_matching_ct_migration_enabled_;
        bool is_font_family_style_matching_ct_migration_enabled_;
        bool is_font_present_win_enabled_;
        bool is_font_src_local_matching_enabled_;
        bool is_font_system_fallback_noto_cjk_enabled_;
        bool is_font_variant_emoji_enabled_;
        bool is_font_variation_sequences_enabled_;
        bool is_forced_colors_enabled_;
        bool is_forced_colors_preserve_parent_color_enabled_;
        bool is_force_eager_measure_memory_enabled_;
        bool is_force_reduce_motion_enabled_;
        bool is_force_taller_select_popup_enabled_;
        bool is_form_control_restore_state_if_autocomplete_off_enabled_;
        bool is_form_controls_vertical_writing_mode_direction_support_enabled_;
        bool is_fractional_scroll_offsets_enabled_;
        bool is_freeze_frames_on_visibility_enabled_;
        bool is_gamepad_multitouch_enabled_;
        bool is_get_all_screens_media_enabled_;
        bool is_get_display_media_enabled_;
        bool is_get_display_media_requires_user_activation_enabled_;
        bool is_group_effect_enabled_;
        bool is_handle_selection_change_on_deleting_empty_element_enabled_;
        bool is_handwriting_recognition_enabled_;
        bool is_hanging_whitespace_does_not_depend_on_alignment_enabled_;
        bool is_has_ua_visual_transition_enabled_;
        bool is_highlight_inheritance_enabled_;
        bool is_highlight_pointer_events_enabled_;
        bool is_highlights_from_point_enabled_;
        bool is_hit_test_opaqueness_enabled_;
        bool is_hit_test_opaqueness_omit_line_box_enabled_;
        bool is_href_translate_enabled_;
        bool is_html_anchor_attribute_enabled_;
        bool is_html_dialog_light_dismiss_enabled_;
        bool is_html_embed_element_not_force_layout_enabled_;
        bool is_html_interest_target_attribute_enabled_;
        bool is_html_invoke_actions_v_2_enabled_;
        bool is_html_invoke_target_attribute_enabled_;
        bool is_html_object_element_fallback_detach_content_frame_enabled_;
        bool is_html_parser_yield_and_delay_often_for_testing_enabled_;
        bool is_html_popover_action_hover_enabled_;
        bool is_html_popover_hint_enabled_;
        bool is_html_select_element_show_picker_enabled_;
        bool is_implicit_root_scroller_enabled_;
        bool is_import_attributes_disallow_unknown_keys_enabled_;
        bool is_import_map_integrity_enabled_;
        bool is_incoming_call_notifications_enabled_;
        bool is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_;
        bool is_indexed_db_get_all_records_enabled_;
        bool is_inert_element_non_editable_enabled_;
        bool is_inert_element_non_searchable_enabled_;
        bool is_infinite_cull_rect_enabled_;
        bool is_inherit_user_modify_without_contenteditable_enabled_;
        bool is_initial_letter_raise_by_specified_enabled_;
        bool is_inline_block_in_same_line_enabled_;
        bool is_inner_html_parser_fastpath_log_failure_enabled_;
        bool is_input_closes_select_enabled_;
        bool is_input_multiple_fields_ui_enabled_;
        bool is_insert_blockquote_before_outer_block_enabled_;
        bool is_insert_line_break_if_phrasing_content_enabled_;
        bool is_inspector_ghost_rules_enabled_;
        bool is_installed_app_enabled_;
        bool is_install_on_device_speech_recognition_enabled_;
        bool is_interest_groups_in_shared_storage_worklet_enabled_;
        bool is_interoperable_private_attribution_enabled_;
        bool is_intersection_observer_scroll_margin_enabled_;
        bool is_inverted_colors_enabled_;
        bool is_invisible_svg_animation_throttling_enabled_;
        bool is_java_script_compile_hints_magic_always_runtime_enabled_;
        bool is_java_script_compile_hints_magic_runtime_enabled_;
        bool is_keep_css_target_after_reattach_enabled_;
        bool is_keyboard_accessible_tooltip_enabled_;
        bool is_keyboard_focusable_scrollers_enabled_;
        bool is_keyboard_focusable_scrollers_opt_out_enabled_;
        bool is_label_and_delegates_focus_new_handling_enabled_;
        bool is_lang_attribute_aware_form_control_ui_enabled_;
        bool is_language_detection_api_enabled_;
        bool is_layout_flex_new_row_algorithm_v_3_enabled_;
        bool is_layout_ignore_margins_for_sticky_enabled_;
        bool is_layout_justify_self_for_blocks_enabled_;
        bool is_layout_ng_shape_cache_enabled_;
        bool is_layout_stretch_enabled_;
        bool is_lazy_initialize_media_controls_enabled_;
        bool is_lazy_load_scroll_margin_enabled_;
        bool is_lazy_load_scroll_margin_iframe_enabled_;
        bool is_lcp_animated_images_web_exposed_enabled_;
        bool is_legacy_windows_d_write_font_fallback_enabled_;
        bool is_limit_third_party_cookies_enabled_;
        bool is_line_box_below_leading_floats_enabled_;
        bool is_list_item_with_counter_set_not_set_explicit_value_enabled_;
        bool is_locked_mode_enabled_;
        bool is_long_animation_frame_timing_enabled_;
        bool is_long_press_link_select_text_enabled_;
        bool is_long_task_from_long_animation_frame_enabled_;
        bool is_machine_learning_neural_network_enabled_;
        bool is_managed_configuration_enabled_;
        bool is_measure_memory_enabled_;
        bool is_media_capabilities_dynamic_range_enabled_;
        bool is_media_capabilities_encoding_info_enabled_;
        bool is_media_capabilities_spatial_audio_enabled_;
        bool is_media_capture_enabled_;
        bool is_media_capture_background_blur_enabled_;
        bool is_media_capture_camera_controls_enabled_;
        bool is_media_capture_configuration_change_enabled_;
        bool is_media_capture_voice_isolation_enabled_;
        bool is_media_cast_overlay_button_enabled_;
        bool is_media_controls_expand_gesture_enabled_;
        bool is_media_controls_overlay_play_button_enabled_;
        bool is_media_element_volume_greater_than_one_enabled_;
        bool is_media_engagement_bypass_autoplay_policies_enabled_;
        bool is_media_latency_hint_enabled_;
        bool is_media_playback_while_not_visible_permission_policy_enabled_;
        bool is_media_previews_opt_out_enabled_;
        bool is_media_query_navigation_controls_enabled_;
        bool is_media_recorder_use_media_video_encoder_enabled_;
        bool is_media_session_enabled_;
        bool is_media_session_chapter_information_enabled_;
        bool is_media_session_enter_picture_in_picture_enabled_;
        bool is_media_source_experimental_enabled_;
        bool is_media_source_extensions_for_webcodecs_enabled_;
        bool is_media_source_new_abort_and_duration_enabled_;
        bool is_media_stream_track_transfer_enabled_;
        bool is_media_stream_track_web_speech_enabled_;
        bool is_message_port_close_event_enabled_;
        bool is_meta_refresh_no_fractional_enabled_;
        bool is_meter_appearance_none_fallback_style_enabled_;
        bool is_meter_devolve_appearance_enabled_;
        bool is_middle_click_autoscroll_enabled_;
        bool is_minimimal_resource_request_prep_before_cache_lookup_enabled_;
        bool is_mobile_layout_theme_enabled_;
        bool is_modify_paragraph_cross_editingoundary_enabled_;
        bool is_mojo_js_enabled_;
        bool is_mojo_js_test_enabled_;
        bool is_move_ending_selection_to_list_child_enabled_;
        bool is_move_to_paragraph_start_or_end_skips_non_editable_enabled_;
        bool is_multiple_import_maps_enabled_;
        bool is_multi_select_deselect_when_only_option_enabled_;
        bool is_multi_smooth_scroll_into_view_enabled_;
        bool is_mutation_events_enabled_;
        bool is_mutation_events_special_trial_message_enabled_;
        bool is_navigate_event_commit_behavior_enabled_;
        bool is_navigate_event_source_element_enabled_;
        bool is_navigation_activation_enabled_;
        bool is_navigation_id_enabled_;
        bool is_navigator_content_utils_enabled_;
        bool is_nested_view_transition_enabled_;
        bool is_net_info_constant_type_enabled_;
        bool is_net_info_downlink_max_enabled_;
        bool is_new_get_focusable_area_behavior_enabled_;
        bool is_no_idle_encoding_for_web_tests_enabled_;
        bool is_no_increasing_end_offset_on_splitting_text_nodes_enabled_;
        bool is_non_empty_blockquotes_on_outdenting_enabled_;
        bool is_non_null_input_event_data_for_text_area_enabled_;
        bool is_non_standard_appearance_value_slider_vertical_enabled_;
        bool is_notification_constructor_enabled_;
        bool is_notification_content_image_enabled_;
        bool is_notifications_enabled_;
        bool is_notification_triggers_enabled_;
        bool is_observable_api_enabled_;
        bool is_off_main_thread_css_paint_enabled_;
        bool is_offscreen_canvas_commit_enabled_;
        bool is_omit_blur_event_on_element_removal_enabled_;
        bool is_on_device_change_enabled_;
        bool is_on_device_web_speech_available_enabled_;
        bool is_orientation_event_enabled_;
        bool is_origin_isolation_header_enabled_;
        bool is_origin_policy_enabled_;
        bool is_origin_trials_sample_api_enabled_;
        bool is_origin_trials_sample_api_browser_read_write_enabled_;
        bool is_origin_trials_sample_api_dependent_enabled_;
        bool is_origin_trials_sample_api_deprecation_enabled_;
        bool is_origin_trials_sample_api_expiry_grace_period_enabled_;
        bool is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_;
        bool is_origin_trials_sample_api_implied_enabled_;
        bool is_origin_trials_sample_api_invalid_os_enabled_;
        bool is_origin_trials_sample_api_navigation_enabled_;
        bool is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_;
        bool is_origin_trials_sample_api_persistent_feature_enabled_;
        bool is_origin_trials_sample_api_persistent_invalid_os_enabled_;
        bool is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_;
        bool is_origin_trials_sample_api_third_party_enabled_;
        bool is_overscroll_customization_enabled_;
        bool is_page_freeze_opt_in_enabled_;
        bool is_page_freeze_opt_out_enabled_;
        bool is_page_margin_boxes_enabled_;
        bool is_page_popup_enabled_;
        bool is_page_reveal_event_enabled_;
        bool is_page_swap_event_enabled_;
        bool is_paint_highlights_for_first_letter_enabled_;
        bool is_paint_holding_for_iframes_enabled_;
        bool is_paint_holding_for_local_iframes_enabled_;
        bool is_paint_under_invalidation_checking_enabled_;
        bool is_parakeet_enabled_;
        bool is_partitioned_popins_enabled_;
        bool is_partition_visited_link_database_with_self_links_enabled_;
        bool is_password_reveal_enabled_;
        bool is_payment_app_enabled_;
        bool is_payment_instruments_enabled_;
        bool is_payment_link_detection_enabled_;
        bool is_payment_method_change_event_enabled_;
        bool is_payment_request_enabled_;
        bool is_percent_based_scrolling_enabled_;
        bool is_performance_manager_instrumentation_enabled_;
        bool is_performance_mark_feature_usage_enabled_;
        bool is_performance_navigate_system_entropy_enabled_;
        bool is_performance_navigation_timing_confidence_enabled_;
        bool is_periodic_background_sync_enabled_;
        bool is_per_method_can_make_payment_quota_enabled_;
        bool is_permission_element_enabled_;
        bool is_permissions_enabled_;
        bool is_permissions_request_revoke_enabled_;
        bool is_p_na_cl_enabled_;
        bool is_pointer_event_device_id_enabled_;
        bool is_pointer_event_targets_in_event_lists_enabled_;
        bool is_popover_anchor_relationships_enabled_;
        bool is_popover_dialog_new_focus_behavior_enabled_;
        bool is_position_outside_tab_span_check_sibling_node_enabled_;
        bool is_precise_memory_info_enabled_;
        bool is_prefer_default_scrollbar_styles_enabled_;
        bool is_prefer_non_composited_scrolling_enabled_;
        bool is_prefers_reduced_data_enabled_;
        bool is_prefixed_video_fullscreen_enabled_;
        bool is_prerender_2_enabled_;
        bool is_presentation_enabled_;
        bool is_preserve_following_block_styles_during_block_merge_enabled_;
        bool is_prevent_undo_if_not_editable_enabled_;
        bool is_private_aggregation_api_filtering_ids_enabled_;
        bool is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_;
        bool is_private_network_access_non_secure_contexts_allowed_enabled_;
        bool is_private_network_access_null_ip_address_enabled_;
        bool is_private_network_access_permission_prompt_enabled_;
        bool is_private_state_tokens_enabled_;
        bool is_private_state_tokens_always_allow_issuance_enabled_;
        bool is_protected_origin_trials_sample_api_enabled_;
        bool is_protected_origin_trials_sample_api_dependent_enabled_;
        bool is_protected_origin_trials_sample_api_implied_enabled_;
        bool is_pseudo_elements_correct_in_get_computed_style_enabled_;
        bool is_pseudo_elements_focusable_enabled_;
        bool is_push_message_data_bytes_enabled_;
        bool is_push_messaging_enabled_;
        bool is_push_messaging_subscription_change_enabled_;
        bool is_quick_intensive_wake_up_throttling_after_loading_enabled_;
        bool is_raster_inducing_scroll_enabled_;
        bool is_readable_stream_async_iterable_enabled_;
        bool is_reduce_accept_language_enabled_;
        bool is_reduce_cookie_ip_cs_enabled_;
        bool is_reduce_user_agent_android_version_device_model_enabled_;
        bool is_reduce_user_agent_minor_version_enabled_;
        bool is_reduce_user_agent_platform_os_cpu_enabled_;
        bool is_region_capture_enabled_;
        bool is_rel_opener_bcg_dependency_hint_enabled_;
        bool is_remote_playback_enabled_;
        bool is_remote_playback_backend_enabled_;
        bool is_remove_collapsed_placeholder_enabled_;
        bool is_remove_dangling_markup_in_target_enabled_;
        bool is_remove_data_url_in_svg_use_enabled_;
        bool is_remove_node_having_children_if_fully_selected_enabled_;
        bool is_remove_visible_selection_in_dom_selection_enabled_;
        bool is_render_blocking_inline_module_script_enabled_;
        bool is_render_blocking_status_enabled_;
        bool is_render_priority_attribute_enabled_;
        bool is_report_event_timing_at_visibility_change_enabled_;
        bool is_report_visible_line_bounds_enabled_;
        bool is_reset_input_type_to_none_before_character_input_enabled_;
        bool is_resource_timing_content_type_enabled_;
        bool is_resource_timing_final_response_headers_start_enabled_;
        bool is_resource_timing_use_cors_for_body_sizes_enabled_;
        bool is_restrict_gamepad_access_enabled_;
        bool is_reuse_shape_results_by_fonts_enabled_;
        bool is_rewind_floats_enabled_;
        bool is_root_element_with_place_holder_after_deleting_selection_enabled_;
        bool is_rtc_audio_jitter_buffer_max_packets_enabled_;
        bool is_rtc_data_channel_priority_enabled_;
        bool is_rtc_encoded_audio_frame_abs_capture_time_enabled_;
        bool is_rtc_encoded_frame_set_metadata_enabled_;
        bool is_rtc_encoded_video_frame_additional_metadata_enabled_;
        bool is_rtc_jitter_buffer_target_enabled_;
        bool is_rtc_legacy_callback_based_get_stats_enabled_;
        bool is_rtc_rtp_encoding_parameters_codec_enabled_;
        bool is_rtc_rtp_scale_resolution_down_to_enabled_;
        bool is_rtc_rtp_script_transform_enabled_;
        bool is_rtc_rtp_transport_enabled_;
        bool is_rtc_stats_relative_packet_arrival_delay_enabled_;
        bool is_rtc_svc_scalability_mode_enabled_;
        bool is_ruby_short_heuristics_enabled_;
        bool is_sanitizer_api_enabled_;
        bool is_scheduler_yield_enabled_;
        bool is_schedule_selection_change_on_backspace_enabled_;
        bool is_scoped_custom_element_registry_enabled_;
        bool is_scripted_speech_recognition_enabled_;
        bool is_scripted_speech_synthesis_enabled_;
        bool is_scrollbar_color_enabled_;
        bool is_scrollbar_width_enabled_;
        bool is_scroll_end_events_enabled_;
        bool is_scroll_into_view_root_frame_viewport_bug_fix_enabled_;
        bool is_scroll_timeline_enabled_;
        bool is_scroll_timeline_current_time_enabled_;
        bool is_scroll_top_left_interop_enabled_;
        bool is_search_text_highlight_pseudo_enabled_;
        bool is_secure_payment_confirmation_enabled_;
        bool is_secure_payment_confirmation_debug_enabled_;
        bool is_secure_payment_confirmation_network_and_issuer_icons_enabled_;
        bool is_secure_payment_confirmation_opt_out_enabled_;
        bool is_select_audio_output_enabled_;
        bool is_selectedcontentelement_attribute_enabled_;
        bool is_selection_across_shadow_dom_enabled_;
        bool is_selection_is_collapsed_shadow_dom_support_enabled_;
        bool is_selection_on_shadow_dom_with_delegates_focus_enabled_;
        bool is_select_option_accessibility_target_size_enabled_;
        bool is_select_parser_relaxation_enabled_;
        bool is_select_popup_less_updates_enabled_;
        bool is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
        bool is_sensor_extra_classes_enabled_;
        bool is_serial_enabled_;
        bool is_serialize_view_transition_state_in_spa_enabled_;
        bool is_serial_port_connected_enabled_;
        bool is_service_worker_client_lifecycle_state_enabled_;
        bool is_service_worker_static_router_enabled_;
        bool is_service_worker_static_router_timing_info_enabled_;
        bool is_set_sequential_focus_starting_point_enabled_;
        bool is_shadow_root_reference_target_enabled_;
        bool is_shape_outside_writing_mode_fix_enabled_;
        bool is_shape_result_cached_previous_safe_to_break_offset_enabled_;
        bool is_shared_array_buffer_enabled_;
        bool is_shared_array_buffer_on_desktop_enabled_;
        bool is_shared_array_buffer_unrestricted_access_allowed_enabled_;
        bool is_shared_autofill_enabled_;
        bool is_shared_storage_api_enabled_;
        bool is_shared_storage_api_m_118_enabled_;
        bool is_shared_storage_api_m_125_enabled_;
        bool is_shared_storage_web_locks_enabled_;
        bool is_shared_worker_enabled_;
        bool is_sideways_writing_modes_enabled_;
        bool is_signature_based_integrity_enabled_;
        bool is_site_initiated_mirroring_enabled_;
        bool is_skip_ad_enabled_;
        bool is_skip_preload_scanning_enabled_;
        bool is_skip_temporary_document_fragment_enabled_;
        bool is_skip_touch_event_filter_enabled_;
        bool is_smart_card_enabled_;
        bool is_smart_zoom_enabled_;
        bool is_smil_auto_suspend_on_lag_enabled_;
        bool is_soft_navigation_detection_enabled_;
        bool is_soft_navigation_heuristics_enabled_;
        bool is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_;
        bool is_speaker_selection_enabled_;
        bool is_speculation_rules_pointer_down_heuristics_enabled_;
        bool is_speculation_rules_pointer_hover_heuristics_enabled_;
        bool is_speculation_rules_prefetch_future_enabled_;
        bool is_speculation_rules_prefetch_with_subresources_enabled_;
        bool is_srcset_max_density_enabled_;
        bool is_stable_blink_features_enabled_;
        bool is_standardized_browser_zoom_enabled_;
        bool is_standardized_browser_zoom_opt_out_enabled_;
        bool is_static_animation_optimization_enabled_;
        bool is_storage_access_header_enabled_;
        bool is_storage_buckets_enabled_;
        bool is_storage_buckets_durability_enabled_;
        bool is_storage_buckets_locks_enabled_;
        bool is_stricter_cell_width_content_size_quirk_enabled_;
        bool is_strict_mime_types_for_workers_enabled_;
        bool is_stylus_handwriting_enabled_;
        bool is_svg_context_paint_enabled_;
        bool is_svg_cross_origin_attribute_enabled_;
        bool is_svg_eager_pres_attr_style_update_enabled_;
        bool is_svg_external_resources_enabled_;
        bool is_svg_filter_user_space_viewport_for_non_svg_enabled_;
        bool is_svg_gradient_color_interpolation_linear_rgb_support_enabled_;
        bool is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_;
        bool is_svg_no_pixel_snapping_scale_adjustment_enabled_;
        bool is_svg_transform_optimization_enabled_;
        bool is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
        bool is_system_fallback_emoji_vs_support_enabled_;
        bool is_system_wake_lock_enabled_;
        bool is_test_blink_feature_default_enabled_;
        bool is_test_feature_enabled_;
        bool is_test_feature_dependent_enabled_;
        bool is_test_feature_implied_enabled_;
        bool is_test_feature_protected_enabled_;
        bool is_test_feature_protected_dependent_enabled_;
        bool is_test_feature_protected_implied_enabled_;
        bool is_test_feature_stable_enabled_;
        bool is_text_detector_enabled_;
        bool is_text_diff_split_fix_enabled_;
        bool is_text_fragment_api_enabled_;
        bool is_text_fragment_identifiers_enabled_;
        bool is_text_fragment_tap_opens_context_menu_enabled_;
        bool is_text_input_not_always_dir_auto_enabled_;
        bool is_text_metrics_baselines_enabled_;
        bool is_text_segment_boundary_for_element_with_float_style_enabled_;
        bool is_text_size_adjust_improvements_enabled_;
        bool is_text_transform_and_security_fix_enabled_;
        bool is_timeline_scope_enabled_;
        bool is_timer_throttling_for_background_tabs_enabled_;
        bool is_timestamp_based_cls_tracking_enabled_;
        bool is_time_zone_change_event_enabled_;
        bool is_topics_api_enabled_;
        bool is_topics_document_api_enabled_;
        bool is_top_layer_inactive_document_exceptions_enabled_;
        bool is_top_level_tpcd_enabled_;
        bool is_touch_drag_and_context_menu_enabled_;
        bool is_touch_drag_on_short_press_enabled_;
        bool is_touch_event_feature_detection_enabled_;
        bool is_touch_text_editing_redesign_enabled_;
        bool is_tpcd_enabled_;
        bool is_transferable_rtc_data_channel_enabled_;
        bool is_translate_service_enabled_;
        bool is_translation_api_enabled_;
        bool is_translation_api_entry_point_enabled_;
        bool is_trusted_type_before_policy_creation_event_enabled_;
        bool is_trusted_types_from_literal_enabled_;
        bool is_trusted_types_use_code_like_enabled_;
        bool is_unclosed_form_control_is_invalid_enabled_;
        bool is_unexposed_task_ids_enabled_;
        bool is_unowned_animations_skip_css_events_enabled_;
        bool is_unrestricted_measure_user_agent_specific_memory_enabled_;
        bool is_unrestricted_shared_array_buffer_enabled_;
        bool is_unrestricted_usb_enabled_;
        bool is_url_pattern_compare_component_enabled_;
        bool is_url_search_params_has_and_delete_multiple_args_enabled_;
        bool is_use_begin_frame_presentation_feedback_enabled_;
        bool is_use_low_quality_interpolation_enabled_;
        bool is_user_activation_same_origin_visibility_enabled_;
        bool is_use_selection_focus_node_for_caret_navigation_enabled_;
        bool is_use_undo_step_element_dispatch_before_input_enabled_;
        bool is_v8_idle_tasks_enabled_;
        bool is_video_auto_fullscreen_enabled_;
        bool is_video_frame_metadata_background_blur_enabled_;
        bool is_video_fullscreen_orientation_lock_enabled_;
        bool is_video_rotate_to_fullscreen_enabled_;
        bool is_video_track_generator_enabled_;
        bool is_video_track_generator_in_window_enabled_;
        bool is_video_track_generator_in_worker_enabled_;
        bool is_viewport_changes_update_text_autosizing_enabled_;
        bool is_viewport_height_client_hint_header_enabled_;
        bool is_viewport_segments_enabled_;
        bool is_view_transition_disable_snap_browser_controls_on_hidden_enabled_;
        bool is_view_transition_layered_capture_enabled_;
        bool is_view_transition_long_callback_timeout_for_testing_enabled_;
        bool is_view_transition_on_navigation_enabled_;
        bool is_view_transition_on_navigation_for_iframes_enabled_;
        bool is_view_transition_overflow_rect_from_surface_enabled_;
        bool is_view_transition_tree_scoped_names_enabled_;
        bool is_view_transition_types_enabled_;
        bool is_visibility_collapse_column_enabled_;
        bool is_visual_viewport_on_scroll_end_enabled_;
        bool is_wake_lock_enabled_;
        bool is_warn_on_content_visibility_render_access_enabled_;
        bool is_web_animations_svg_enabled_;
        bool is_web_app_installation_enabled_;
        bool is_web_app_launch_queue_enabled_;
        bool is_web_app_scope_extensions_enabled_;
        bool is_web_app_tab_strip_enabled_;
        bool is_web_app_tab_strip_customizations_enabled_;
        bool is_web_app_translations_enabled_;
        bool is_web_app_url_handling_enabled_;
        bool is_web_assembly_js_promise_integration_enabled_;
        bool is_web_assembly_js_string_builtins_enabled_;
        bool is_web_audio_bypass_output_buffering_enabled_;
        bool is_web_audio_bypass_output_buffering_opt_out_enabled_;
        bool is_web_auth_enabled_;
        bool is_web_auth_authenticator_attachment_enabled_;
        bool is_web_authentication_ambient_enabled_;
        bool is_web_authentication_attestation_formats_enabled_;
        bool is_web_authentication_client_capabilities_enabled_;
        bool is_web_authentication_js_on_serialization_enabled_;
        bool is_web_authentication_large_blob_extension_enabled_;
        bool is_web_authentication_prf_enabled_;
        bool is_web_authentication_remote_desktop_support_enabled_;
        bool is_web_authentication_supplemental_pub_keys_enabled_;
        bool is_web_bluetooth_enabled_;
        bool is_web_bluetooth_get_devices_enabled_;
        bool is_web_bluetooth_scanning_enabled_;
        bool is_web_bluetooth_watch_advertisements_enabled_;
        bool is_webcodecs_copy_to_rgb_enabled_;
        bool is_webcodecs_hbd_formats_enabled_;
        bool is_webcodecs_orientation_enabled_;
        bool is_webcodecs_video_encoder_buffers_enabled_;
        bool is_web_crypto_curve_25519_enabled_;
        bool is_web_font_resize_lcp_enabled_;
        bool is_webgl_developer_extensions_enabled_;
        bool is_webgl_draft_extensions_enabled_;
        bool is_webgl_drawing_buffer_storage_enabled_;
        bool is_webgl_image_chromium_enabled_;
        bool is_webgpu_canvas_context_get_configuration_enabled_;
        bool is_webgpu_developer_features_enabled_;
        bool is_webgpu_device_adapter_info_enabled_;
        bool is_webgpu_experimental_features_enabled_;
        bool is_webgpu_hdr_enabled_;
        bool is_webgpu_subgroups_features_enabled_;
        bool is_webgpu_texture_view_usage_enabled_;
        bool is_web_hid_enabled_;
        bool is_web_hid_on_dedicated_workers_enabled_;
        bool is_web_hid_on_service_workers_enabled_;
        bool is_web_identity_digital_credentials_enabled_;
        bool is_web_idl_big_int_uses_to_big_int_enabled_;
        bool is_web_nfc_enabled_;
        bool is_web_otp_enabled_;
        bool is_web_otp_assertion_feature_policy_enabled_;
        bool is_web_preferences_enabled_;
        bool is_web_printing_enabled_;
        bool is_web_share_enabled_;
        bool is_websocket_stream_enabled_;
        bool is_web_transport_custom_certificates_enabled_;
        bool is_web_transport_stats_enabled_;
        bool is_web_usb_enabled_;
        bool is_web_usb_on_dedicated_workers_enabled_;
        bool is_web_usb_on_service_workers_enabled_;
        bool is_web_view_xr_equested_with_deprecation_enabled_;
        bool is_web_vtt_regions_enabled_;
        bool is_web_xr_enabled_;
        bool is_web_xr_enabled_features_enabled_;
        bool is_web_xr_frame_rate_enabled_;
        bool is_web_xr_front_facing_enabled_;
        bool is_web_xr_gpu_binding_enabled_;
        bool is_web_xr_hand_input_enabled_;
        bool is_web_xr_hit_test_entity_types_enabled_;
        bool is_web_xr_image_tracking_enabled_;
        bool is_web_xr_layers_enabled_;
        bool is_web_xr_layers_common_enabled_;
        bool is_web_xr_plane_detection_enabled_;
        bool is_web_xr_pose_motion_data_enabled_;
        bool is_web_xr_spec_parity_enabled_;
        bool is_window_default_status_enabled_;
        bool is_xml_parser_merge_adjacent_c_data_sections_enabled_;
        bool is_zero_copy_tab_capture_enabled_;
    };

    // Simple getter methods for protected memory values that ensure they are
    // properly initialized before first access.
    static bool get_is_mojo_js_enabled_();
    static bool get_is_mojo_js_test_enabled_();
    static bool get_is_protected_origin_trials_sample_api_enabled_();
    static bool get_is_protected_origin_trials_sample_api_dependent_enabled_();
    static bool get_is_protected_origin_trials_sample_api_implied_enabled_();
    static bool get_is_test_feature_protected_enabled_();
    static bool get_is_test_feature_protected_dependent_enabled_();
    static bool get_is_test_feature_protected_implied_enabled_();

    static bool Accelerated2dCanvasEnabled()
    {
        return is_accelerated_2d_canvas_enabled_;
    }

    static bool Accelerated2dCanvasEnabled(const FeatureContext*)
    {
        return Accelerated2dCanvasEnabled();
    }

    static bool AcceleratedSmallCanvasesEnabled()
    {
        return is_accelerated_small_canvases_enabled_;
    }

    static bool AcceleratedSmallCanvasesEnabled(const FeatureContext*)
    {
        return AcceleratedSmallCanvasesEnabled();
    }

    static bool AccessibilityAriaVirtualContentEnabled()
    {
        return is_accessibility_aria_virtual_content_enabled_;
    }

    static bool AccessibilityAriaVirtualContentEnabled(const FeatureContext*)
    {
        return AccessibilityAriaVirtualContentEnabled();
    }

    static bool AccessibilityExposeDisplayNoneEnabled()
    {
        return is_accessibility_expose_display_none_enabled_;
    }

    static bool AccessibilityExposeDisplayNoneEnabled(const FeatureContext*)
    {
        return AccessibilityExposeDisplayNoneEnabled();
    }

    static bool AccessibilityMinRoleTabbableEnabled()
    {
        return is_accessibility_min_role_tabbable_enabled_;
    }

    static bool AccessibilityMinRoleTabbableEnabled(const FeatureContext*)
    {
        return AccessibilityMinRoleTabbableEnabled();
    }

    static bool AccessibilityOSLevelBoldTextEnabled()
    {
        return is_accessibility_os_level_bold_text_enabled_;
    }

    static bool AccessibilityOSLevelBoldTextEnabled(const FeatureContext*)
    {
        return AccessibilityOSLevelBoldTextEnabled();
    }

    static bool AccessibilityProhibitedNamesEnabled()
    {
        return is_accessibility_prohibited_names_enabled_;
    }

    static bool AccessibilityProhibitedNamesEnabled(const FeatureContext*)
    {
        return AccessibilityProhibitedNamesEnabled();
    }

    static bool AccessibilitySerializationSizeMetricsEnabled()
    {
        return is_accessibility_serialization_size_metrics_enabled_;
    }

    static bool AccessibilitySerializationSizeMetricsEnabled(const FeatureContext*)
    {
        return AccessibilitySerializationSizeMetricsEnabled();
    }

    static bool AccessibilityUseAXPositionForDocumentMarkersEnabled()
    {
        return is_accessibility_use_ax_position_for_document_markers_enabled_;
    }

    static bool AccessibilityUseAXPositionForDocumentMarkersEnabled(const FeatureContext*)
    {
        return AccessibilityUseAXPositionForDocumentMarkersEnabled();
    }

    static bool AddressSpaceEnabled()
    {
        if (CorsRFC1918Enabled())
            return true;
        return is_address_space_enabled_;
    }

    static bool AddressSpaceEnabled(const FeatureContext*)
    {
        return AddressSpaceEnabled();
    }

    static bool AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled()
    {
        return is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_;
    }

    static bool AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled(const FeatureContext*)
    {
        return AdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled();
    }

    static bool AdTaggingEnabled()
    {
        return is_ad_tagging_enabled_;
    }

    static bool AdTaggingEnabled(const FeatureContext*)
    {
        return AdTaggingEnabled();
    }

    static bool AIPromptAPIEnabled()
    {
        if (AIPromptAPIForWebPlatformEnabled())
            return true;
        return is_ai_prompt_api_enabled_;
    }

    static bool AIPromptAPIEnabled(const FeatureContext*)
    {
        return AIPromptAPIEnabled();
    }

    static bool AIPromptAPIForWebPlatformEnabled()
    {
        return is_ai_prompt_api_for_web_platform_enabled_;
    }

    static bool AIPromptAPIForWebPlatformEnabled(const FeatureContext*)
    {
        return AIPromptAPIForWebPlatformEnabled();
    }

    static bool AIRewriterAPIEnabled()
    {
        return is_ai_rewriter_api_enabled_;
    }

    static bool AIRewriterAPIEnabled(const FeatureContext*)
    {
        return AIRewriterAPIEnabled();
    }

    static bool AIWriterAPIEnabled()
    {
        return is_ai_writer_api_enabled_;
    }

    static bool AIWriterAPIEnabled(const FeatureContext*)
    {
        return AIWriterAPIEnabled();
    }

    static bool AllowContentInitiatedDataUrlNavigationsEnabled()
    {
        return is_allow_content_initiated_data_url_navigations_enabled_;
    }

    static bool AllowContentInitiatedDataUrlNavigationsEnabled(const FeatureContext*)
    {
        return AllowContentInitiatedDataUrlNavigationsEnabled();
    }

    static bool AllowJavaScriptToResetAutofillStateEnabled()
    {
        return is_allow_java_script_to_reset_autofill_state_enabled_;
    }

    static bool AllowJavaScriptToResetAutofillStateEnabled(const FeatureContext*)
    {
        return AllowJavaScriptToResetAutofillStateEnabled();
    }

    static bool AllowPreloadingWithCSPMetaTagEnabled()
    {
        return is_allow_preloading_with_csp_meta_tag_enabled_;
    }

    static bool AllowPreloadingWithCSPMetaTagEnabled(const FeatureContext*)
    {
        return AllowPreloadingWithCSPMetaTagEnabled();
    }

    static bool AllowURNsInIframesEnabled()
    {
        return is_allow_ur_ns_in_iframes_enabled_;
    }

    static bool AllowURNsInIframesEnabled(const FeatureContext*)
    {
        return AllowURNsInIframesEnabled();
    }

    static bool AndroidDownloadableFontsMatchingEnabled()
    {
        return is_android_downloadable_fonts_matching_enabled_;
    }

    static bool AndroidDownloadableFontsMatchingEnabled(const FeatureContext*)
    {
        return AndroidDownloadableFontsMatchingEnabled();
    }

    static bool AnimationProgressAPIEnabled()
    {
        return is_animation_progress_api_enabled_;
    }

    static bool AnimationProgressAPIEnabled(const FeatureContext*)
    {
        return AnimationProgressAPIEnabled();
    }

    static bool AnimationWorkletEnabled()
    {
        return is_animation_worklet_enabled_;
    }

    static bool AnimationWorkletEnabled(const FeatureContext*)
    {
        return AnimationWorkletEnabled();
    }

    static bool AnonymousIframeEnabled()
    {
        return is_anonymous_iframe_enabled_;
    }

    static bool AnonymousIframeEnabled(const FeatureContext*)
    {
        return AnonymousIframeEnabled();
    }

    static bool AOMAriaRelationshipPropertiesEnabled()
    {
        return is_aom_aria_relationship_properties_enabled_;
    }

    static bool AOMAriaRelationshipPropertiesEnabled(const FeatureContext*)
    {
        return AOMAriaRelationshipPropertiesEnabled();
    }

    static bool AOMAriaRelationshipPropertiesAriaOwnsEnabled()
    {
        if (!AOMAriaRelationshipPropertiesEnabled())
            return false;
        return is_aom_aria_relationship_properties_aria_owns_enabled_;
    }

    static bool AOMAriaRelationshipPropertiesAriaOwnsEnabled(const FeatureContext*)
    {
        return AOMAriaRelationshipPropertiesAriaOwnsEnabled();
    }

    static bool AriaActionsEnabled()
    {
        return is_aria_actions_enabled_;
    }

    static bool AriaActionsEnabled(const FeatureContext*)
    {
        return AriaActionsEnabled();
    }

    static bool AriaNotifyEnabled()
    {
        return is_aria_notify_enabled_;
    }

    static bool AriaNotifyEnabled(const FeatureContext*)
    {
        return AriaNotifyEnabled();
    }

    static bool AriaRowColIndexTextEnabled()
    {
        return is_aria_row_col_index_text_enabled_;
    }

    static bool AriaRowColIndexTextEnabled(const FeatureContext*)
    {
        return AriaRowColIndexTextEnabled();
    }

    static bool AtomicMoveAPIEnabled()
    {
        return is_atomic_move_api_enabled_;
    }

    static bool AtomicMoveAPIEnabled(const FeatureContext*)
    {
        return AtomicMoveAPIEnabled();
    }

    static bool AttributionReportingEnabled()
    {
        return is_attribution_reporting_enabled_;
    }

    static bool AttributionReportingEnabled(const FeatureContext*)
    {
        return AttributionReportingEnabled();
    }

    static bool AttributionReportingCrossAppWebEnabled()
    {
        return is_attribution_reporting_cross_app_web_enabled_;
    }

    static bool AttributionReportingCrossAppWebEnabled(const FeatureContext*)
    {
        return AttributionReportingCrossAppWebEnabled();
    }

    static bool AudioContextInterruptedStateEnabled()
    {
        return is_audio_context_interrupted_state_enabled_;
    }

    static bool AudioContextInterruptedStateEnabled(const FeatureContext*)
    {
        return AudioContextInterruptedStateEnabled();
    }

    static bool AudioContextOnErrorEnabled()
    {
        return is_audio_context_on_error_enabled_;
    }

    static bool AudioContextOnErrorEnabled(const FeatureContext*)
    {
        return AudioContextOnErrorEnabled();
    }

    static bool AudioContextSetSinkIdEnabled()
    {
        return is_audio_context_set_sink_id_enabled_;
    }

    static bool AudioContextSetSinkIdEnabled(const FeatureContext*)
    {
        return AudioContextSetSinkIdEnabled();
    }

    static bool AudioOutputDevicesEnabled()
    {
        return is_audio_output_devices_enabled_;
    }

    static bool AudioOutputDevicesEnabled(const FeatureContext*)
    {
        return AudioOutputDevicesEnabled();
    }

    static bool AudioVideoTracksEnabled()
    {
        return is_audio_video_tracks_enabled_;
    }

    static bool AudioVideoTracksEnabled(const FeatureContext*)
    {
        return AudioVideoTracksEnabled();
    }

    static bool AuraScrollbarUsesNinePatchTrackEnabled()
    {
        return is_aura_scrollbar_uses_nine_patch_track_enabled_;
    }

    static bool AuraScrollbarUsesNinePatchTrackEnabled(const FeatureContext*)
    {
        return AuraScrollbarUsesNinePatchTrackEnabled();
    }

    static bool AuraScrollbarUsesSolidColorThumbEnabled()
    {
        return is_aura_scrollbar_uses_solid_color_thumb_enabled_;
    }

    static bool AuraScrollbarUsesSolidColorThumbEnabled(const FeatureContext*)
    {
        return AuraScrollbarUsesSolidColorThumbEnabled();
    }

    static bool AutomationControlledEnabled()
    {
        return is_automation_controlled_enabled_;
    }

    static bool AutomationControlledEnabled(const FeatureContext*)
    {
        return AutomationControlledEnabled();
    }

    static bool AutoPictureInPictureVideoHeuristicsEnabled()
    {
        return is_auto_picture_in_picture_video_heuristics_enabled_;
    }

    static bool AutoPictureInPictureVideoHeuristicsEnabled(const FeatureContext*)
    {
        return AutoPictureInPictureVideoHeuristicsEnabled();
    }

    static bool BackfaceVisibilityInteropEnabled()
    {
        return is_backface_visibility_interop_enabled_;
    }

    static bool BackfaceVisibilityInteropEnabled(const FeatureContext*)
    {
        return BackfaceVisibilityInteropEnabled();
    }

    static bool BackForwardCacheEnabled()
    {
        return is_back_forward_cache_enabled_;
    }

    static bool BackForwardCacheEnabled(const FeatureContext*)
    {
        return BackForwardCacheEnabled();
    }

    static bool BackForwardTransitionsEnabled()
    {
        return is_back_forward_transitions_enabled_;
    }

    static bool BackForwardTransitionsEnabled(const FeatureContext*)
    {
        return BackForwardTransitionsEnabled();
    }

    static bool BackgroundFetchEnabled()
    {
        return is_background_fetch_enabled_;
    }

    static bool BackgroundFetchEnabled(const FeatureContext*)
    {
        return BackgroundFetchEnabled();
    }

    static bool BarcodeDetectorEnabled()
    {
        return is_barcode_detector_enabled_;
    }

    static bool BarcodeDetectorEnabled(const FeatureContext*)
    {
        return BarcodeDetectorEnabled();
    }

    static bool BidiCaretAffinityEnabled()
    {
        return is_bidi_caret_affinity_enabled_;
    }

    static bool BidiCaretAffinityEnabled(const FeatureContext*)
    {
        return BidiCaretAffinityEnabled();
    }

    static bool BlinkExtensionChromeOSEnabled()
    {
        return is_blink_extension_chrome_os_enabled_;
    }

    static bool BlinkExtensionChromeOSEnabled(const FeatureContext*);

    static bool BlinkExtensionChromeOSKioskEnabled()
    {
        if (!BlinkExtensionChromeOSEnabled())
            return false;
        return is_blink_extension_chrome_os_kiosk_enabled_;
    }

    static bool BlinkExtensionChromeOSKioskEnabled(const FeatureContext*);

    static bool BlinkExtensionDiagnosticsEnabled()
    {
        if (!BlinkExtensionChromeOSEnabled())
            return false;
        return is_blink_extension_diagnostics_enabled_;
    }

    static bool BlinkExtensionDiagnosticsEnabled(const FeatureContext*);

    static bool BlinkExtensionWebViewEnabled()
    {
        return is_blink_extension_web_view_enabled_;
    }

    static bool BlinkExtensionWebViewEnabled(const FeatureContext*)
    {
        return BlinkExtensionWebViewEnabled();
    }

    static bool BlinkExtensionWebViewMediaIntegrityEnabled()
    {
        return is_blink_extension_web_view_media_integrity_enabled_;
    }

    static bool BlinkExtensionWebViewMediaIntegrityEnabled(const FeatureContext*)
    {
        return BlinkExtensionWebViewMediaIntegrityEnabled();
    }

    static bool BlinkLifecycleScriptForbiddenEnabled()
    {
        return is_blink_lifecycle_script_forbidden_enabled_;
    }

    static bool BlinkLifecycleScriptForbiddenEnabled(const FeatureContext*)
    {
        return BlinkLifecycleScriptForbiddenEnabled();
    }

    static bool BlinkRuntimeCallStatsEnabled()
    {
        return is_blink_runtime_call_stats_enabled_;
    }

    static bool BlinkRuntimeCallStatsEnabled(const FeatureContext*)
    {
        return BlinkRuntimeCallStatsEnabled();
    }

    static bool BlockingFocusWithoutUserActivationEnabled()
    {
        return is_blocking_focus_without_user_activation_enabled_;
    }

    static bool BlockingFocusWithoutUserActivationEnabled(const FeatureContext*)
    {
        return BlockingFocusWithoutUserActivationEnabled();
    }

    static bool BoundaryEventDispatchTracksNodeRemovalEnabled()
    {
        return is_boundary_event_dispatch_tracks_node_removal_enabled_;
    }

    static bool BoundaryEventDispatchTracksNodeRemovalEnabled(const FeatureContext*)
    {
        return BoundaryEventDispatchTracksNodeRemovalEnabled();
    }

    static bool BoxDecorationBreakEnabled()
    {
        return is_box_decoration_break_enabled_;
    }

    static bool BoxDecorationBreakEnabled(const FeatureContext*)
    {
        return BoxDecorationBreakEnabled();
    }

    static bool BreakIteratorHyphenMinusEnabled()
    {
        return is_break_iterator_hyphen_minus_enabled_;
    }

    static bool BreakIteratorHyphenMinusEnabled(const FeatureContext*)
    {
        return BreakIteratorHyphenMinusEnabled();
    }

    static bool BrowserVerifiedUserActivationKeyboardEnabled()
    {
        return is_browser_verified_user_activation_keyboard_enabled_;
    }

    static bool BrowserVerifiedUserActivationKeyboardEnabled(const FeatureContext*)
    {
        return BrowserVerifiedUserActivationKeyboardEnabled();
    }

    static bool BrowserVerifiedUserActivationMouseEnabled()
    {
        return is_browser_verified_user_activation_mouse_enabled_;
    }

    static bool BrowserVerifiedUserActivationMouseEnabled(const FeatureContext*)
    {
        return BrowserVerifiedUserActivationMouseEnabled();
    }

    static bool BufferedBytesConsumerLimitSizeEnabled()
    {
        return is_buffered_bytes_consumer_limit_size_enabled_;
    }

    static bool BufferedBytesConsumerLimitSizeEnabled(const FeatureContext*)
    {
        return BufferedBytesConsumerLimitSizeEnabled();
    }

    static bool BypassPepcSecurityForTestingEnabled()
    {
        return is_bypass_pepc_security_for_testing_enabled_;
    }

    static bool BypassPepcSecurityForTestingEnabled(const FeatureContext*)
    {
        return BypassPepcSecurityForTestingEnabled();
    }

    static bool CalendarPickerMonthPopupButtonDisabledColorEnabled()
    {
        return is_calendar_picker_month_popup_button_disabled_color_enabled_;
    }

    static bool CalendarPickerMonthPopupButtonDisabledColorEnabled(const FeatureContext*)
    {
        return CalendarPickerMonthPopupButtonDisabledColorEnabled();
    }

    static bool CallExitNodeWithoutLayoutObjectEnabled()
    {
        return is_call_exit_node_without_layout_object_enabled_;
    }

    static bool CallExitNodeWithoutLayoutObjectEnabled(const FeatureContext*)
    {
        return CallExitNodeWithoutLayoutObjectEnabled();
    }

    static bool Canvas2dCanvasFilterEnabled()
    {
        return is_canvas_2d_canvas_filter_enabled_;
    }

    static bool Canvas2dCanvasFilterEnabled(const FeatureContext*)
    {
        return Canvas2dCanvasFilterEnabled();
    }

    static bool Canvas2dGPUTransferEnabled()
    {
        return is_canvas_2d_gpu_transfer_enabled_;
    }

    static bool Canvas2dGPUTransferEnabled(const FeatureContext*)
    {
        return Canvas2dGPUTransferEnabled();
    }

    static bool Canvas2dImageChromiumEnabled()
    {
        return is_canvas_2d_image_chromium_enabled_;
    }

    static bool Canvas2dImageChromiumEnabled(const FeatureContext*)
    {
        return Canvas2dImageChromiumEnabled();
    }

    static bool Canvas2dLayersEnabled()
    {
        return is_canvas_2d_layers_enabled_;
    }

    static bool Canvas2dLayersEnabled(const FeatureContext*)
    {
        return Canvas2dLayersEnabled();
    }

    static bool Canvas2dLayersWithOptionsEnabled()
    {
        if (!Canvas2dLayersEnabled())
            return false;
        return is_canvas_2d_layers_with_options_enabled_;
    }

    static bool Canvas2dLayersWithOptionsEnabled(const FeatureContext*)
    {
        return Canvas2dLayersWithOptionsEnabled();
    }

    static bool Canvas2dTextMetricsShapingEnabled()
    {
        return is_canvas_2d_text_metrics_shaping_enabled_;
    }

    static bool Canvas2dTextMetricsShapingEnabled(const FeatureContext*)
    {
        return Canvas2dTextMetricsShapingEnabled();
    }

    static bool CanvasFloatingPointEnabled()
    {
        return is_canvas_floating_point_enabled_;
    }

    static bool CanvasFloatingPointEnabled(const FeatureContext*)
    {
        return CanvasFloatingPointEnabled();
    }

    static bool CanvasHDREnabled()
    {
        return is_canvas_hdr_enabled_;
    }

    static bool CanvasHDREnabled(const FeatureContext*)
    {
        return CanvasHDREnabled();
    }

    static bool CanvasImageSmoothingEnabled()
    {
        return is_canvas_image_smoothing_enabled_;
    }

    static bool CanvasImageSmoothingEnabled(const FeatureContext*)
    {
        return CanvasImageSmoothingEnabled();
    }

    static bool CanvasPlaceElementEnabled()
    {
        return is_canvas_place_element_enabled_;
    }

    static bool CanvasPlaceElementEnabled(const FeatureContext*)
    {
        return CanvasPlaceElementEnabled();
    }

    static bool CanvasUsesArcPaintOpEnabled()
    {
        return is_canvas_uses_arc_paint_op_enabled_;
    }

    static bool CanvasUsesArcPaintOpEnabled(const FeatureContext*)
    {
        return CanvasUsesArcPaintOpEnabled();
    }

    static bool CapabilityDelegationDisplayCaptureRequestEnabled()
    {
        return is_capability_delegation_display_capture_request_enabled_;
    }

    static bool CapabilityDelegationDisplayCaptureRequestEnabled(const FeatureContext*)
    {
        return CapabilityDelegationDisplayCaptureRequestEnabled();
    }

    static bool CaptureControllerEnabled()
    {
        return is_capture_controller_enabled_;
    }

    static bool CaptureControllerEnabled(const FeatureContext*)
    {
        return CaptureControllerEnabled();
    }

    static bool CapturedMouseEventsEnabled()
    {
        if (!CaptureControllerEnabled())
            return false;
        return is_captured_mouse_events_enabled_;
    }

    static bool CapturedMouseEventsEnabled(const FeatureContext*)
    {
        return CapturedMouseEventsEnabled();
    }

    static bool CaptureHandleEnabled()
    {
        if (!GetDisplayMediaEnabled())
            return false;
        return is_capture_handle_enabled_;
    }

    static bool CaptureHandleEnabled(const FeatureContext*)
    {
        return CaptureHandleEnabled();
    }

    static bool CaretPositionFromPointEnabled()
    {
        return is_caret_position_from_point_enabled_;
    }

    static bool CaretPositionFromPointEnabled(const FeatureContext*)
    {
        return CaretPositionFromPointEnabled();
    }

    static bool CCTNewRFMPushBehaviorEnabled()
    {
        return is_cct_new_rfm_push_behavior_enabled_;
    }

    static bool CCTNewRFMPushBehaviorEnabled(const FeatureContext*)
    {
        return CCTNewRFMPushBehaviorEnabled();
    }

    static bool CheckIfHighestRootContainsPositionAnchorNodeEnabled()
    {
        return is_check_if_highest_root_contains_position_anchor_node_enabled_;
    }

    static bool CheckIfHighestRootContainsPositionAnchorNodeEnabled(const FeatureContext*)
    {
        return CheckIfHighestRootContainsPositionAnchorNodeEnabled();
    }

    static bool CheckVisibilityExtraPropertiesEnabled()
    {
        return is_check_visibility_extra_properties_enabled_;
    }

    static bool CheckVisibilityExtraPropertiesEnabled(const FeatureContext*)
    {
        return CheckVisibilityExtraPropertiesEnabled();
    }

    static bool ClickToCapturedPointerEnabled()
    {
        return is_click_to_captured_pointer_enabled_;
    }

    static bool ClickToCapturedPointerEnabled(const FeatureContext*)
    {
        return ClickToCapturedPointerEnabled();
    }

    static bool ClipboardItemWithDOMStringSupportEnabled()
    {
        return is_clipboard_item_with_dom_string_support_enabled_;
    }

    static bool ClipboardItemWithDOMStringSupportEnabled(const FeatureContext*)
    {
        return ClipboardItemWithDOMStringSupportEnabled();
    }

    static bool ClipPathRejectEmptyPathsEnabled()
    {
        return is_clip_path_reject_empty_paths_enabled_;
    }

    static bool ClipPathRejectEmptyPathsEnabled(const FeatureContext*)
    {
        return ClipPathRejectEmptyPathsEnabled();
    }

    static bool CoalesceSelectionchangeEventEnabled()
    {
        return is_coalesce_selectionchange_event_enabled_;
    }

    static bool CoalesceSelectionchangeEventEnabled(const FeatureContext*)
    {
        return CoalesceSelectionchangeEventEnabled();
    }

    static bool CoepReflectionEnabled()
    {
        return is_coep_reflection_enabled_;
    }

    static bool CoepReflectionEnabled(const FeatureContext*)
    {
        return CoepReflectionEnabled();
    }

    static bool CompositeBGColorAnimationEnabled()
    {
        return is_composite_bg_color_animation_enabled_;
    }

    static bool CompositeBGColorAnimationEnabled(const FeatureContext*)
    {
        return CompositeBGColorAnimationEnabled();
    }

    static bool CompositeBoxShadowAnimationEnabled()
    {
        return is_composite_box_shadow_animation_enabled_;
    }

    static bool CompositeBoxShadowAnimationEnabled(const FeatureContext*)
    {
        return CompositeBoxShadowAnimationEnabled();
    }

    static bool CompositeClipPathAnimationEnabled()
    {
        return is_composite_clip_path_animation_enabled_;
    }

    static bool CompositeClipPathAnimationEnabled(const FeatureContext*)
    {
        return CompositeClipPathAnimationEnabled();
    }

    static bool CompositedAnimationsCancelledAsynchronouslyEnabled()
    {
        return is_composited_animations_cancelled_asynchronously_enabled_;
    }

    static bool CompositedAnimationsCancelledAsynchronouslyEnabled(const FeatureContext*)
    {
        return CompositedAnimationsCancelledAsynchronouslyEnabled();
    }

    static bool CompositedSelectionUpdateEnabled()
    {
        return is_composited_selection_update_enabled_;
    }

    static bool CompositedSelectionUpdateEnabled(const FeatureContext*)
    {
        return CompositedSelectionUpdateEnabled();
    }

    static bool CompositionForegroundMarkersEnabled()
    {
        return is_composition_foreground_markers_enabled_;
    }

    static bool CompositionForegroundMarkersEnabled(const FeatureContext*)
    {
        return CompositionForegroundMarkersEnabled();
    }

    static bool CompressionDictionaryTransportEnabled()
    {
        return is_compression_dictionary_transport_enabled_;
    }

    static bool CompressionDictionaryTransportEnabled(const FeatureContext*)
    {
        return CompressionDictionaryTransportEnabled();
    }

    static bool CompressionDictionaryTransportBackendEnabled()
    {
        return is_compression_dictionary_transport_backend_enabled_;
    }

    static bool CompressionDictionaryTransportBackendEnabled(const FeatureContext*)
    {
        return CompressionDictionaryTransportBackendEnabled();
    }

    static bool ComputedAccessibilityInfoEnabled()
    {
        return is_computed_accessibility_info_enabled_;
    }

    static bool ComputedAccessibilityInfoEnabled(const FeatureContext*)
    {
        return ComputedAccessibilityInfoEnabled();
    }

    static bool ComputePressureEnabled()
    {
        return is_compute_pressure_enabled_;
    }

    static bool ComputePressureEnabled(const FeatureContext*)
    {
        return ComputePressureEnabled();
    }

    static bool ConcurrentViewTransitionsSPAEnabled()
    {
        return is_concurrent_view_transitions_spa_enabled_;
    }

    static bool ConcurrentViewTransitionsSPAEnabled(const FeatureContext*)
    {
        return ConcurrentViewTransitionsSPAEnabled();
    }

    static bool ContactsManagerEnabled()
    {
        return is_contacts_manager_enabled_;
    }

    static bool ContactsManagerEnabled(const FeatureContext*)
    {
        return ContactsManagerEnabled();
    }

    static bool ContactsManagerExtraPropertiesEnabled()
    {
        return is_contacts_manager_extra_properties_enabled_;
    }

    static bool ContactsManagerExtraPropertiesEnabled(const FeatureContext*)
    {
        return ContactsManagerExtraPropertiesEnabled();
    }

    static bool ContainerTypeNoLayoutContainmentEnabled()
    {
        return is_container_type_no_layout_containment_enabled_;
    }

    static bool ContainerTypeNoLayoutContainmentEnabled(const FeatureContext*)
    {
        return ContainerTypeNoLayoutContainmentEnabled();
    }

    static bool ContentIndexEnabled()
    {
        return is_content_index_enabled_;
    }

    static bool ContentIndexEnabled(const FeatureContext*)
    {
        return ContentIndexEnabled();
    }

    static bool ContextMenuEnabled()
    {
        return is_context_menu_enabled_;
    }

    static bool ContextMenuEnabled(const FeatureContext*)
    {
        return ContextMenuEnabled();
    }

    static bool ContinueEventTimingRecordingWhenBufferIsFullEnabled()
    {
        return is_continue_event_timing_recording_when_buffer_is_full_enabled_;
    }

    static bool ContinueEventTimingRecordingWhenBufferIsFullEnabled(const FeatureContext*)
    {
        return ContinueEventTimingRecordingWhenBufferIsFullEnabled();
    }

    static bool ControlledFrameEnabled()
    {
        return is_controlled_frame_enabled_;
    }

    static bool ControlledFrameEnabled(const FeatureContext*)
    {
        return ControlledFrameEnabled();
    }

    static bool CookieDeprecationFacilitatedTestingEnabled()
    {
        return is_cookie_deprecation_facilitated_testing_enabled_;
    }

    static bool CookieDeprecationFacilitatedTestingEnabled(const FeatureContext*)
    {
        return CookieDeprecationFacilitatedTestingEnabled();
    }

    static bool CooperativeSchedulingEnabled()
    {
        return is_cooperative_scheduling_enabled_;
    }

    static bool CooperativeSchedulingEnabled(const FeatureContext*)
    {
        return CooperativeSchedulingEnabled();
    }

    static bool CorsRFC1918Enabled()
    {
        return is_cors_rfc_1918_enabled_;
    }

    static bool CorsRFC1918Enabled(const FeatureContext*)
    {
        return CorsRFC1918Enabled();
    }

    static bool CreateInputShadowTreeDuringLayoutEnabled()
    {
        return is_create_input_shadow_tree_during_layout_enabled_;
    }

    static bool CreateInputShadowTreeDuringLayoutEnabled(const FeatureContext*)
    {
        return CreateInputShadowTreeDuringLayoutEnabled();
    }

    static bool CredentialManagerReportEnabled()
    {
        return is_credential_manager_report_enabled_;
    }

    static bool CredentialManagerReportEnabled(const FeatureContext*)
    {
        return CredentialManagerReportEnabled();
    }

    static bool CrossFramePerformanceTimelineEnabled()
    {
        return is_cross_frame_performance_timeline_enabled_;
    }

    static bool CrossFramePerformanceTimelineEnabled(const FeatureContext*)
    {
        return CrossFramePerformanceTimelineEnabled();
    }

    static bool CSSAccentColorKeywordEnabled()
    {
        return is_css_accent_color_keyword_enabled_;
    }

    static bool CSSAccentColorKeywordEnabled(const FeatureContext*)
    {
        return CSSAccentColorKeywordEnabled();
    }

    static bool CSSAdvancedAttrFunctionEnabled()
    {
        return is_css_advanced_attr_function_enabled_;
    }

    static bool CSSAdvancedAttrFunctionEnabled(const FeatureContext*)
    {
        return CSSAdvancedAttrFunctionEnabled();
    }

    static bool CSSAnchorScopeEnabled()
    {
        return is_css_anchor_scope_enabled_;
    }

    static bool CSSAnchorScopeEnabled(const FeatureContext*)
    {
        return CSSAnchorScopeEnabled();
    }

    static bool CSSAnchorSizeInsetsMarginsEnabled()
    {
        return is_css_anchor_size_insets_margins_enabled_;
    }

    static bool CSSAnchorSizeInsetsMarginsEnabled(const FeatureContext*)
    {
        return CSSAnchorSizeInsetsMarginsEnabled();
    }

    static bool CSSAtPropertyStringSyntaxEnabled()
    {
        return is_css_at_property_string_syntax_enabled_;
    }

    static bool CSSAtPropertyStringSyntaxEnabled(const FeatureContext*)
    {
        return CSSAtPropertyStringSyntaxEnabled();
    }

    static bool CSSAtRuleCounterStyleImageSymbolsEnabled()
    {
        return is_css_at_rule_counter_style_image_symbols_enabled_;
    }

    static bool CSSAtRuleCounterStyleImageSymbolsEnabled(const FeatureContext*)
    {
        return CSSAtRuleCounterStyleImageSymbolsEnabled();
    }

    static bool CSSAtRuleCounterStyleSpeakAsDescriptorEnabled()
    {
        return is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
    }

    static bool CSSAtRuleCounterStyleSpeakAsDescriptorEnabled(const FeatureContext*)
    {
        return CSSAtRuleCounterStyleSpeakAsDescriptorEnabled();
    }

    static bool CSSBackgroundClipUnprefixEnabled()
    {
        return is_css_background_clip_unprefix_enabled_;
    }

    static bool CSSBackgroundClipUnprefixEnabled(const FeatureContext*)
    {
        return CSSBackgroundClipUnprefixEnabled();
    }

    static bool CSSCalcSimplificationAndSerializationEnabled()
    {
        return is_css_calc_simplification_and_serialization_enabled_;
    }

    static bool CSSCalcSimplificationAndSerializationEnabled(const FeatureContext*)
    {
        return CSSCalcSimplificationAndSerializationEnabled();
    }

    static bool CSSCalcSizeFunctionEnabled()
    {
        return is_css_calc_size_function_enabled_;
    }

    static bool CSSCalcSizeFunctionEnabled(const FeatureContext*)
    {
        return CSSCalcSizeFunctionEnabled();
    }

    static bool CSSCaretAnimationEnabled()
    {
        return is_css_caret_animation_enabled_;
    }

    static bool CSSCaretAnimationEnabled(const FeatureContext*)
    {
        return CSSCaretAnimationEnabled();
    }

    static bool CSSCascadeCorrectScopeEnabled()
    {
        return is_css_cascade_correct_scope_enabled_;
    }

    static bool CSSCascadeCorrectScopeEnabled(const FeatureContext*)
    {
        return CSSCascadeCorrectScopeEnabled();
    }

    static bool CSSCaseSensitiveSelectorEnabled()
    {
        return is_css_case_sensitive_selector_enabled_;
    }

    static bool CSSCaseSensitiveSelectorEnabled(const FeatureContext*)
    {
        return CSSCaseSensitiveSelectorEnabled();
    }

    static bool CSSColorContrastEnabled()
    {
        return is_css_color_contrast_enabled_;
    }

    static bool CSSColorContrastEnabled(const FeatureContext*)
    {
        return CSSColorContrastEnabled();
    }

    static bool CSSColorTypedOMEnabled()
    {
        return is_css_color_typed_om_enabled_;
    }

    static bool CSSColorTypedOMEnabled(const FeatureContext*)
    {
        return CSSColorTypedOMEnabled();
    }

    static bool CSSComputedStyleFullPseudoElementParserEnabled()
    {
        return is_css_computed_style_full_pseudo_element_parser_enabled_;
    }

    static bool CSSComputedStyleFullPseudoElementParserEnabled(const FeatureContext*)
    {
        return CSSComputedStyleFullPseudoElementParserEnabled();
    }

    static bool CSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled()
    {
        return is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_;
    }

    static bool CSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled(const FeatureContext*)
    {
        return CSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled();
    }

    static bool CSSCrossFadeEnabled()
    {
        return is_css_cross_fade_enabled_;
    }

    static bool CSSCrossFadeEnabled(const FeatureContext*)
    {
        return CSSCrossFadeEnabled();
    }

    static bool CSSCustomStateDeprecatedSyntaxEnabled()
    {
        return is_css_custom_state_deprecated_syntax_enabled_;
    }

    static bool CSSCustomStateDeprecatedSyntaxEnabled(const FeatureContext*)
    {
        return CSSCustomStateDeprecatedSyntaxEnabled();
    }

    static bool CSSCustomStateNewSyntaxEnabled()
    {
        return is_css_custom_state_new_syntax_enabled_;
    }

    static bool CSSCustomStateNewSyntaxEnabled(const FeatureContext*)
    {
        return CSSCustomStateNewSyntaxEnabled();
    }

    static bool CSSDynamicRangeLimitEnabled()
    {
        return is_css_dynamic_range_limit_enabled_;
    }

    static bool CSSDynamicRangeLimitEnabled(const FeatureContext*)
    {
        return CSSDynamicRangeLimitEnabled();
    }

    static bool CSSEnumeratedCustomPropertiesEnabled()
    {
        return is_css_enumerated_custom_properties_enabled_;
    }

    static bool CSSEnumeratedCustomPropertiesEnabled(const FeatureContext*)
    {
        return CSSEnumeratedCustomPropertiesEnabled();
    }

    static bool CSSExponentialFunctionsEnabled()
    {
        return is_css_exponential_functions_enabled_;
    }

    static bool CSSExponentialFunctionsEnabled(const FeatureContext*)
    {
        return CSSExponentialFunctionsEnabled();
    }

    static bool CSSFlatTreeContainerEnabled()
    {
        return is_css_flat_tree_container_enabled_;
    }

    static bool CSSFlatTreeContainerEnabled(const FeatureContext*)
    {
        return CSSFlatTreeContainerEnabled();
    }

    static bool CSSFontSizeAdjustEnabled()
    {
        return is_css_font_size_adjust_enabled_;
    }

    static bool CSSFontSizeAdjustEnabled(const FeatureContext*)
    {
        return CSSFontSizeAdjustEnabled();
    }

    static bool CSSFunctionsEnabled()
    {
        return is_css_functions_enabled_;
    }

    static bool CSSFunctionsEnabled(const FeatureContext*)
    {
        return CSSFunctionsEnabled();
    }

    static bool CSSGapDecorationEnabled()
    {
        return is_css_gap_decoration_enabled_;
    }

    static bool CSSGapDecorationEnabled(const FeatureContext*)
    {
        return CSSGapDecorationEnabled();
    }

    static bool CSSHexAlphaColorEnabled()
    {
        return is_css_hex_alpha_color_enabled_;
    }

    static bool CSSHexAlphaColorEnabled(const FeatureContext*)
    {
        return CSSHexAlphaColorEnabled();
    }

    static bool CSSInertEnabled()
    {
        return is_css_inert_enabled_;
    }

    static bool CSSInertEnabled(const FeatureContext*)
    {
        return CSSInertEnabled();
    }

    static bool CSSInsetAreaPropertyEnabled()
    {
        return is_css_inset_area_property_enabled_;
    }

    static bool CSSInsetAreaPropertyEnabled(const FeatureContext*)
    {
        return CSSInsetAreaPropertyEnabled();
    }

    static bool CSSKeyframesRuleLengthEnabled()
    {
        return is_css_keyframes_rule_length_enabled_;
    }

    static bool CSSKeyframesRuleLengthEnabled(const FeatureContext*)
    {
        return CSSKeyframesRuleLengthEnabled();
    }

    static bool CSSLayoutAPIEnabled()
    {
        return is_css_layout_api_enabled_;
    }

    static bool CSSLayoutAPIEnabled(const FeatureContext*)
    {
        return CSSLayoutAPIEnabled();
    }

    static bool CSSLazyParsingFastPathEnabled()
    {
        return is_css_lazy_parsing_fast_path_enabled_;
    }

    static bool CSSLazyParsingFastPathEnabled(const FeatureContext*)
    {
        return CSSLazyParsingFastPathEnabled();
    }

    static bool CSSLineClampEnabled()
    {
        return is_css_line_clamp_enabled_;
    }

    static bool CSSLineClampEnabled(const FeatureContext*)
    {
        return CSSLineClampEnabled();
    }

    static bool CSSLineClampWebkitBoxBlockificationEnabled()
    {
        return is_css_line_clamp_webkit_box_blockification_enabled_;
    }

    static bool CSSLineClampWebkitBoxBlockificationEnabled(const FeatureContext*)
    {
        return CSSLineClampWebkitBoxBlockificationEnabled();
    }

    static bool CSSLogicalOverflowEnabled()
    {
        return is_css_logical_overflow_enabled_;
    }

    static bool CSSLogicalOverflowEnabled(const FeatureContext*)
    {
        return CSSLogicalOverflowEnabled();
    }

    static bool CSSMarkerNestedPseudoElementEnabled()
    {
        return is_css_marker_nested_pseudo_element_enabled_;
    }

    static bool CSSMarkerNestedPseudoElementEnabled(const FeatureContext*)
    {
        return CSSMarkerNestedPseudoElementEnabled();
    }

    static bool CSSMasonryLayoutEnabled()
    {
        return is_css_masonry_layout_enabled_;
    }

    static bool CSSMasonryLayoutEnabled(const FeatureContext*)
    {
        return CSSMasonryLayoutEnabled();
    }

    static bool CSSMixinsEnabled()
    {
        return is_css_mixins_enabled_;
    }

    static bool CSSMixinsEnabled(const FeatureContext*)
    {
        return CSSMixinsEnabled();
    }

    static bool CSSNestedDeclarationsEnabled()
    {
        return is_css_nested_declarations_enabled_;
    }

    static bool CSSNestedDeclarationsEnabled(const FeatureContext*)
    {
        return CSSNestedDeclarationsEnabled();
    }

    static bool CSSNestedPseudoElementsEnabled()
    {
        return is_css_nested_pseudo_elements_enabled_;
    }

    static bool CSSNestedPseudoElementsEnabled(const FeatureContext*)
    {
        return CSSNestedPseudoElementsEnabled();
    }

    static bool CSSOverflowContainerQueriesEnabled()
    {
        return is_css_overflow_container_queries_enabled_;
    }

    static bool CSSOverflowContainerQueriesEnabled(const FeatureContext*)
    {
        return CSSOverflowContainerQueriesEnabled();
    }

    static bool CSSPaintAPIArgumentsEnabled()
    {
        return is_css_paint_api_arguments_enabled_;
    }

    static bool CSSPaintAPIArgumentsEnabled(const FeatureContext*)
    {
        return CSSPaintAPIArgumentsEnabled();
    }

    static bool CSSParserIgnoreCharsetForURLsEnabled()
    {
        return is_css_parser_ignore_charset_for_urls_enabled_;
    }

    static bool CSSParserIgnoreCharsetForURLsEnabled(const FeatureContext*)
    {
        return CSSParserIgnoreCharsetForURLsEnabled();
    }

    static bool CSSPartAllowsMoreSelectorsAfterEnabled()
    {
        return is_css_part_allows_more_selectors_after_enabled_;
    }

    static bool CSSPartAllowsMoreSelectorsAfterEnabled(const FeatureContext*)
    {
        return CSSPartAllowsMoreSelectorsAfterEnabled();
    }

    static bool CSSPositionAreaValueEnabled()
    {
        return is_css_position_area_value_enabled_;
    }

    static bool CSSPositionAreaValueEnabled(const FeatureContext*)
    {
        return CSSPositionAreaValueEnabled();
    }

    static bool CSSPositionStickyStaticScrollPositionEnabled()
    {
        return is_css_position_sticky_static_scroll_position_enabled_;
    }

    static bool CSSPositionStickyStaticScrollPositionEnabled(const FeatureContext*)
    {
        return CSSPositionStickyStaticScrollPositionEnabled();
    }

    static bool CSSProgressNotationEnabled()
    {
        return is_css_progress_notation_enabled_;
    }

    static bool CSSProgressNotationEnabled(const FeatureContext*)
    {
        return CSSProgressNotationEnabled();
    }

    static bool CSSPseudoColumnEnabled()
    {
        return is_css_pseudo_column_enabled_;
    }

    static bool CSSPseudoColumnEnabled(const FeatureContext*)
    {
        return CSSPseudoColumnEnabled();
    }

    static bool CSSPseudoHasSlottedEnabled()
    {
        return is_css_pseudo_has_slotted_enabled_;
    }

    static bool CSSPseudoHasSlottedEnabled(const FeatureContext*)
    {
        return CSSPseudoHasSlottedEnabled();
    }

    static bool CSSPseudoOpenClosedEnabled()
    {
        return is_css_pseudo_open_closed_enabled_;
    }

    static bool CSSPseudoOpenClosedEnabled(const FeatureContext*)
    {
        return CSSPseudoOpenClosedEnabled();
    }

    static bool CSSPseudoPlayingPausedEnabled()
    {
        return is_css_pseudo_playing_paused_enabled_;
    }

    static bool CSSPseudoPlayingPausedEnabled(const FeatureContext*)
    {
        return CSSPseudoPlayingPausedEnabled();
    }

    static bool CSSPseudoScrollButtonsEnabled()
    {
        if (!PseudoElementsFocusableEnabled())
            return false;
        return is_css_pseudo_scroll_buttons_enabled_;
    }

    static bool CSSPseudoScrollButtonsEnabled(const FeatureContext*)
    {
        return CSSPseudoScrollButtonsEnabled();
    }

    static bool CSSPseudoScrollMarkersEnabled()
    {
        if (!PseudoElementsFocusableEnabled())
            return false;
        return is_css_pseudo_scroll_markers_enabled_;
    }

    static bool CSSPseudoScrollMarkersEnabled(const FeatureContext*)
    {
        return CSSPseudoScrollMarkersEnabled();
    }

    static bool CSSReadingFlowEnabled()
    {
        return is_css_reading_flow_enabled_;
    }

    static bool CSSReadingFlowEnabled(const FeatureContext*)
    {
        return CSSReadingFlowEnabled();
    }

    static bool CSSRelativeColorEnabled()
    {
        return is_css_relative_color_enabled_;
    }

    static bool CSSRelativeColorEnabled(const FeatureContext*)
    {
        return CSSRelativeColorEnabled();
    }

    static bool CSSRelativeColorLateResolveAlwaysEnabled()
    {
        return is_css_relative_color_late_resolve_always_enabled_;
    }

    static bool CSSRelativeColorLateResolveAlwaysEnabled(const FeatureContext*)
    {
        return CSSRelativeColorLateResolveAlwaysEnabled();
    }

    static bool CSSRelativeColorPreserveNoneEnabled()
    {
        return is_css_relative_color_preserve_none_enabled_;
    }

    static bool CSSRelativeColorPreserveNoneEnabled(const FeatureContext*)
    {
        return CSSRelativeColorPreserveNoneEnabled();
    }

    static bool CSSRelativeColorSupportsCurrentcolorEnabled()
    {
        return is_css_relative_color_supports_currentcolor_enabled_;
    }

    static bool CSSRelativeColorSupportsCurrentcolorEnabled(const FeatureContext*)
    {
        return CSSRelativeColorSupportsCurrentcolorEnabled();
    }

    static bool CSSResizeAutoEnabled()
    {
        return is_css_resize_auto_enabled_;
    }

    static bool CSSResizeAutoEnabled(const FeatureContext*)
    {
        return CSSResizeAutoEnabled();
    }

    static bool CSSScrollSnapChangeEventEnabled()
    {
        return is_css_scroll_snap_change_event_enabled_;
    }

    static bool CSSScrollSnapChangeEventEnabled(const FeatureContext*)
    {
        return CSSScrollSnapChangeEventEnabled();
    }

    static bool CSSScrollSnapChangingEventEnabled()
    {
        return is_css_scroll_snap_changing_event_enabled_;
    }

    static bool CSSScrollSnapChangingEventEnabled(const FeatureContext*)
    {
        return CSSScrollSnapChangingEventEnabled();
    }

    static bool CSSScrollSnapEventsEnabled()
    {
        if (CSSScrollSnapChangeEventEnabled())
            return true;
        if (CSSScrollSnapChangingEventEnabled())
            return true;
        return is_css_scroll_snap_events_enabled_;
    }

    static bool CSSScrollSnapEventsEnabled(const FeatureContext*)
    {
        return CSSScrollSnapEventsEnabled();
    }

    static bool CSSScrollStartEnabled()
    {
        return is_css_scroll_start_enabled_;
    }

    static bool CSSScrollStartEnabled(const FeatureContext*)
    {
        return CSSScrollStartEnabled();
    }

    static bool CSSScrollStartTargetEnabled()
    {
        return is_css_scroll_start_target_enabled_;
    }

    static bool CSSScrollStartTargetEnabled(const FeatureContext*)
    {
        return CSSScrollStartTargetEnabled();
    }

    static bool CSSScrollStateContainerQueriesEnabled()
    {
        if (CSSStickyContainerQueriesEnabled())
            return true;
        if (CSSSnapContainerQueriesEnabled())
            return true;
        if (CSSOverflowContainerQueriesEnabled())
            return true;
        return is_css_scroll_state_container_queries_enabled_;
    }

    static bool CSSScrollStateContainerQueriesEnabled(const FeatureContext*)
    {
        return CSSScrollStateContainerQueriesEnabled();
    }

    static bool CSSSelectorFragmentAnchorEnabled()
    {
        return is_css_selector_fragment_anchor_enabled_;
    }

    static bool CSSSelectorFragmentAnchorEnabled(const FeatureContext*)
    {
        return CSSSelectorFragmentAnchorEnabled();
    }

    static bool CSSSignRelatedFunctionsEnabled()
    {
        return is_css_sign_related_functions_enabled_;
    }

    static bool CSSSignRelatedFunctionsEnabled(const FeatureContext*)
    {
        return CSSSignRelatedFunctionsEnabled();
    }

    static bool CSSSnapContainerQueriesEnabled()
    {
        return is_css_snap_container_queries_enabled_;
    }

    static bool CSSSnapContainerQueriesEnabled(const FeatureContext*)
    {
        return CSSSnapContainerQueriesEnabled();
    }

    static bool CSSSteppedValueFunctionsEnabled()
    {
        return is_css_stepped_value_functions_enabled_;
    }

    static bool CSSSteppedValueFunctionsEnabled(const FeatureContext*)
    {
        return CSSSteppedValueFunctionsEnabled();
    }

    static bool CSSStickyContainerQueriesEnabled()
    {
        return is_css_sticky_container_queries_enabled_;
    }

    static bool CSSStickyContainerQueriesEnabled(const FeatureContext*)
    {
        return CSSStickyContainerQueriesEnabled();
    }

    static bool CSSSupportsAtRuleFunctionEnabled()
    {
        return is_css_supports_at_rule_function_enabled_;
    }

    static bool CSSSupportsAtRuleFunctionEnabled(const FeatureContext*)
    {
        return CSSSupportsAtRuleFunctionEnabled();
    }

    static bool CSSSupportsForImportRulesEnabled()
    {
        return is_css_supports_for_import_rules_enabled_;
    }

    static bool CSSSupportsForImportRulesEnabled(const FeatureContext*)
    {
        return CSSSupportsForImportRulesEnabled();
    }

    static bool CSSSystemAccentColorEnabled()
    {
        return is_css_system_accent_color_enabled_;
    }

    static bool CSSSystemAccentColorEnabled(const FeatureContext*)
    {
        return CSSSystemAccentColorEnabled();
    }

    static bool CSSTextAutoSpaceEnabled()
    {
        return is_css_text_auto_space_enabled_;
    }

    static bool CSSTextAutoSpaceEnabled(const FeatureContext*)
    {
        return CSSTextAutoSpaceEnabled();
    }

    static bool CSSTextBoxTrimEnabled()
    {
        return is_css_text_box_trim_enabled_;
    }

    static bool CSSTextBoxTrimEnabled(const FeatureContext*)
    {
        return CSSTextBoxTrimEnabled();
    }

    static bool CSSTextSpacingEnabled()
    {
        if (!CSSTextAutoSpaceEnabled())
            return false;
        return is_css_text_spacing_enabled_;
    }

    static bool CSSTextSpacingEnabled(const FeatureContext*)
    {
        return CSSTextSpacingEnabled();
    }

    static bool CSSTreeScopedTimelinesEnabled()
    {
        return is_css_tree_scoped_timelines_enabled_;
    }

    static bool CSSTreeScopedTimelinesEnabled(const FeatureContext*)
    {
        return CSSTreeScopedTimelinesEnabled();
    }

    static bool CSSUserSelectContainEnabled()
    {
        return is_css_user_select_contain_enabled_;
    }

    static bool CSSUserSelectContainEnabled(const FeatureContext*)
    {
        return CSSUserSelectContainEnabled();
    }

    static bool CSSVideoDynamicRangeMediaQueriesEnabled()
    {
        return is_css_video_dynamic_range_media_queries_enabled_;
    }

    static bool CSSVideoDynamicRangeMediaQueriesEnabled(const FeatureContext*)
    {
        return CSSVideoDynamicRangeMediaQueriesEnabled();
    }

    static bool CSSViewTransitionAutoNameEnabled()
    {
        return is_css_view_transition_auto_name_enabled_;
    }

    static bool CSSViewTransitionAutoNameEnabled(const FeatureContext*)
    {
        return CSSViewTransitionAutoNameEnabled();
    }

    static bool CSSViewTransitionClassEnabled()
    {
        return is_css_view_transition_class_enabled_;
    }

    static bool CSSViewTransitionClassEnabled(const FeatureContext*)
    {
        return CSSViewTransitionClassEnabled();
    }

    static bool CursorAnchorInfoMojoPipeEnabled()
    {
        return is_cursor_anchor_info_mojo_pipe_enabled_;
    }

    static bool CursorAnchorInfoMojoPipeEnabled(const FeatureContext*)
    {
        return CursorAnchorInfoMojoPipeEnabled();
    }

    static bool CustomizableSelectEnabled()
    {
        if (!CSSPseudoOpenClosedEnabled())
            return false;
        if (!SelectParserRelaxationEnabled())
            return false;
        return is_customizable_select_enabled_;
    }

    static bool CustomizableSelectEnabled(const FeatureContext*)
    {
        return CustomizableSelectEnabled();
    }

    static bool DeprecatedRequestAdapterInfoEnabled()
    {
        return is_deprecated_request_adapter_info_enabled_;
    }

    static bool DeprecatedRequestAdapterInfoEnabled(const FeatureContext*)
    {
        return DeprecatedRequestAdapterInfoEnabled();
    }

    static bool DesktopCaptureDisableLocalEchoControlEnabled()
    {
        return is_desktop_capture_disable_local_echo_control_enabled_;
    }

    static bool DesktopCaptureDisableLocalEchoControlEnabled(const FeatureContext*)
    {
        return DesktopCaptureDisableLocalEchoControlEnabled();
    }

    static bool DesktopPWAsAdditionalWindowingControlsEnabled()
    {
        return is_desktop_pw_as_additional_windowing_controls_enabled_;
    }

    static bool DesktopPWAsAdditionalWindowingControlsEnabled(const FeatureContext*)
    {
        return DesktopPWAsAdditionalWindowingControlsEnabled();
    }

    static bool DesktopPWAsSubAppsEnabled()
    {
        return is_desktop_pw_as_sub_apps_enabled_;
    }

    static bool DesktopPWAsSubAppsEnabled(const FeatureContext*)
    {
        return DesktopPWAsSubAppsEnabled();
    }

    static bool DetailsStylingEnabled()
    {
        return is_details_styling_enabled_;
    }

    static bool DetailsStylingEnabled(const FeatureContext*)
    {
        return DetailsStylingEnabled();
    }

    static bool DeviceAttributesEnabled()
    {
        return is_device_attributes_enabled_;
    }

    static bool DeviceAttributesEnabled(const FeatureContext*)
    {
        return DeviceAttributesEnabled();
    }

    static bool DeviceOrientationRequestPermissionEnabled()
    {
        return is_device_orientation_request_permission_enabled_;
    }

    static bool DeviceOrientationRequestPermissionEnabled(const FeatureContext*)
    {
        return DeviceOrientationRequestPermissionEnabled();
    }

    static bool DevicePostureEnabled()
    {
        return is_device_posture_enabled_;
    }

    static bool DevicePostureEnabled(const FeatureContext*)
    {
        return DevicePostureEnabled();
    }

    static bool DialogCloseWhenOpenRemovedEnabled()
    {
        return is_dialog_close_when_open_removed_enabled_;
    }

    static bool DialogCloseWhenOpenRemovedEnabled(const FeatureContext*)
    {
        return DialogCloseWhenOpenRemovedEnabled();
    }

    static bool DialogElementToggleEventsEnabled()
    {
        return is_dialog_element_toggle_events_enabled_;
    }

    static bool DialogElementToggleEventsEnabled(const FeatureContext*)
    {
        return DialogElementToggleEventsEnabled();
    }

    static bool DialogNewFocusBehaviorEnabled()
    {
        if (!NewGetFocusableAreaBehaviorEnabled())
            return false;
        return is_dialog_new_focus_behavior_enabled_;
    }

    static bool DialogNewFocusBehaviorEnabled(const FeatureContext*)
    {
        return DialogNewFocusBehaviorEnabled();
    }

    static bool DigitalGoodsV2_1Enabled()
    {
        return is_digital_goods_v_2_1_enabled_;
    }

    static bool DigitalGoodsV2_1Enabled(const FeatureContext*)
    {
        return DigitalGoodsV2_1Enabled();
    }

    static bool DirAutoFixSlotExclusionsEnabled()
    {
        return is_dir_auto_fix_slot_exclusions_enabled_;
    }

    static bool DirAutoFixSlotExclusionsEnabled(const FeatureContext*)
    {
        return DirAutoFixSlotExclusionsEnabled();
    }

    static bool DirectSocketsEnabled()
    {
        return is_direct_sockets_enabled_;
    }

    static bool DirectSocketsEnabled(const FeatureContext*)
    {
        return DirectSocketsEnabled();
    }

    static bool DisableAhemAntialiasEnabled()
    {
        return is_disable_ahem_antialias_enabled_;
    }

    static bool DisableAhemAntialiasEnabled(const FeatureContext*)
    {
        return DisableAhemAntialiasEnabled();
    }

    static bool DisableSelectAllForEmptyTextEnabled()
    {
        return is_disable_select_all_for_empty_text_enabled_;
    }

    static bool DisableSelectAllForEmptyTextEnabled(const FeatureContext*)
    {
        return DisableSelectAllForEmptyTextEnabled();
    }

    static bool DispatchBeforeInputForSpinButtonInteractionsEnabled()
    {
        return is_dispatch_before_input_for_spin_button_interactions_enabled_;
    }

    static bool DispatchBeforeInputForSpinButtonInteractionsEnabled(const FeatureContext*)
    {
        return DispatchBeforeInputForSpinButtonInteractionsEnabled();
    }

    static bool DispatchHiddenVisibilityTransitionsEnabled()
    {
        return is_dispatch_hidden_visibility_transitions_enabled_;
    }

    static bool DispatchHiddenVisibilityTransitionsEnabled(const FeatureContext*)
    {
        return DispatchHiddenVisibilityTransitionsEnabled();
    }

    static bool DispatchSelectionchangeEventPerElementEnabled()
    {
        return is_dispatch_selectionchange_event_per_element_enabled_;
    }

    static bool DispatchSelectionchangeEventPerElementEnabled(const FeatureContext*)
    {
        return DispatchSelectionchangeEventPerElementEnabled();
    }

    static bool DisplayContentsFocusableEnabled()
    {
        return is_display_contents_focusable_enabled_;
    }

    static bool DisplayContentsFocusableEnabled(const FeatureContext*)
    {
        return DisplayContentsFocusableEnabled();
    }

    static bool DisplayCutoutAPIEnabled()
    {
        return is_display_cutout_api_enabled_;
    }

    static bool DisplayCutoutAPIEnabled(const FeatureContext*)
    {
        return DisplayCutoutAPIEnabled();
    }

    static bool DocumentCookieEnabled()
    {
        return is_document_cookie_enabled_;
    }

    static bool DocumentCookieEnabled(const FeatureContext*)
    {
        return DocumentCookieEnabled();
    }

    static bool DocumentDomainEnabled()
    {
        return is_document_domain_enabled_;
    }

    static bool DocumentDomainEnabled(const FeatureContext*)
    {
        return DocumentDomainEnabled();
    }

    static bool DocumentInstallChunkingEnabled()
    {
        return is_document_install_chunking_enabled_;
    }

    static bool DocumentInstallChunkingEnabled(const FeatureContext*)
    {
        return DocumentInstallChunkingEnabled();
    }

    static bool DocumentOpenOriginAliasRemovalEnabled()
    {
        return is_document_open_origin_alias_removal_enabled_;
    }

    static bool DocumentOpenOriginAliasRemovalEnabled(const FeatureContext*)
    {
        return DocumentOpenOriginAliasRemovalEnabled();
    }

    static bool DocumentOpenSandboxInheritanceRemovalEnabled()
    {
        return is_document_open_sandbox_inheritance_removal_enabled_;
    }

    static bool DocumentOpenSandboxInheritanceRemovalEnabled(const FeatureContext*)
    {
        return DocumentOpenSandboxInheritanceRemovalEnabled();
    }

    static bool DocumentPictureInPictureAPIEnabled()
    {
        return is_document_picture_in_picture_api_enabled_;
    }

    static bool DocumentPictureInPictureAPIEnabled(const FeatureContext*)
    {
        return DocumentPictureInPictureAPIEnabled();
    }

    static bool DocumentPictureInPicturePreferInitialPlacementEnabled()
    {
        return is_document_picture_in_picture_prefer_initial_placement_enabled_;
    }

    static bool DocumentPictureInPicturePreferInitialPlacementEnabled(const FeatureContext*)
    {
        return DocumentPictureInPicturePreferInitialPlacementEnabled();
    }

    static bool DocumentPictureInPictureUserActivationEnabled()
    {
        return is_document_picture_in_picture_user_activation_enabled_;
    }

    static bool DocumentPictureInPictureUserActivationEnabled(const FeatureContext*)
    {
        return DocumentPictureInPictureUserActivationEnabled();
    }

    static bool DocumentPolicyDocumentDomainEnabled()
    {
        return is_document_policy_document_domain_enabled_;
    }

    static bool DocumentPolicyDocumentDomainEnabled(const FeatureContext*)
    {
        return DocumentPolicyDocumentDomainEnabled();
    }

    static bool DocumentPolicyExpectNoLinkedResourcesEnabled()
    {
        return is_document_policy_expect_no_linked_resources_enabled_;
    }

    static bool DocumentPolicyExpectNoLinkedResourcesEnabled(const FeatureContext*)
    {
        return DocumentPolicyExpectNoLinkedResourcesEnabled();
    }

    static bool DocumentPolicySyncXHREnabled()
    {
        return is_document_policy_sync_xhr_enabled_;
    }

    static bool DocumentPolicySyncXHREnabled(const FeatureContext*)
    {
        return DocumentPolicySyncXHREnabled();
    }

    static bool DocumentRenderBlockingEnabled()
    {
        return is_document_render_blocking_enabled_;
    }

    static bool DocumentRenderBlockingEnabled(const FeatureContext*)
    {
        return DocumentRenderBlockingEnabled();
    }

    static bool DocumentWriteEnabled()
    {
        return is_document_write_enabled_;
    }

    static bool DocumentWriteEnabled(const FeatureContext*)
    {
        return DocumentWriteEnabled();
    }

    static bool DOMPartsAPIEnabled()
    {
        if (DOMPartsAPIMinimalEnabled())
            return true;
        return is_dom_parts_api_enabled_;
    }

    static bool DOMPartsAPIEnabled(const FeatureContext*)
    {
        return DOMPartsAPIEnabled();
    }

    static bool DOMPartsAPIMinimalEnabled()
    {
        return is_dom_parts_api_minimal_enabled_;
    }

    static bool DOMPartsAPIMinimalEnabled(const FeatureContext*)
    {
        return DOMPartsAPIMinimalEnabled();
    }

    static bool DropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled()
    {
        return is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_;
    }

    static bool DropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled(const FeatureContext*)
    {
        return DropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled();
    }

    static bool DynamicSafeAreaInsetsEnabled()
    {
        return is_dynamic_safe_area_insets_enabled_;
    }

    static bool DynamicSafeAreaInsetsEnabled(const FeatureContext*)
    {
        return DynamicSafeAreaInsetsEnabled();
    }

    static bool DynamicSafeAreaInsetsOnScrollEnabled()
    {
        if (!DynamicSafeAreaInsetsEnabled())
            return false;
        return is_dynamic_safe_area_insets_on_scroll_enabled_;
    }

    static bool DynamicSafeAreaInsetsOnScrollEnabled(const FeatureContext*)
    {
        return DynamicSafeAreaInsetsOnScrollEnabled();
    }

    static bool ElementCaptureEnabled()
    {
        return is_element_capture_enabled_;
    }

    static bool ElementCaptureEnabled(const FeatureContext*)
    {
        return ElementCaptureEnabled();
    }

    static bool ElementGetInnerHTMLEnabled()
    {
        return is_element_get_inner_html_enabled_;
    }

    static bool ElementGetInnerHTMLEnabled(const FeatureContext*)
    {
        return ElementGetInnerHTMLEnabled();
    }

    static bool EnforceAnonymityExposureEnabled()
    {
        return is_enforce_anonymity_exposure_enabled_;
    }

    static bool EnforceAnonymityExposureEnabled(const FeatureContext*)
    {
        return EnforceAnonymityExposureEnabled();
    }

    static bool EscapeLtGtInAttributesEnabled()
    {
        return is_escape_lt_gt_in_attributes_enabled_;
    }

    static bool EscapeLtGtInAttributesEnabled(const FeatureContext*)
    {
        return EscapeLtGtInAttributesEnabled();
    }

    static bool EventTimingHandleKeyboardEventSimulatedClickEnabled()
    {
        return is_event_timing_handle_keyboard_event_simulated_click_enabled_;
    }

    static bool EventTimingHandleKeyboardEventSimulatedClickEnabled(const FeatureContext*)
    {
        return EventTimingHandleKeyboardEventSimulatedClickEnabled();
    }

    static bool EventTimingInteractionCountEnabled()
    {
        return is_event_timing_interaction_count_enabled_;
    }

    static bool EventTimingInteractionCountEnabled(const FeatureContext*)
    {
        return EventTimingInteractionCountEnabled();
    }

    static bool EventTimingSelectionAutoScrollNoInteractionIdEnabled()
    {
        return is_event_timing_selection_auto_scroll_no_interaction_id_enabled_;
    }

    static bool EventTimingSelectionAutoScrollNoInteractionIdEnabled(const FeatureContext*)
    {
        return EventTimingSelectionAutoScrollNoInteractionIdEnabled();
    }

    static bool EventTimingTapStopScrollNoInteractionIdEnabled()
    {
        return is_event_timing_tap_stop_scroll_no_interaction_id_enabled_;
    }

    static bool EventTimingTapStopScrollNoInteractionIdEnabled(const FeatureContext*)
    {
        return EventTimingTapStopScrollNoInteractionIdEnabled();
    }

    static bool ExcludeTransparentTextsFromBeingLcpEligibleEnabled()
    {
        return is_exclude_transparent_texts_from_being_lcp_eligible_enabled_;
    }

    static bool ExcludeTransparentTextsFromBeingLcpEligibleEnabled(const FeatureContext*)
    {
        return ExcludeTransparentTextsFromBeingLcpEligibleEnabled();
    }

    static bool ExperimentalContentSecurityPolicyFeaturesEnabled()
    {
        return is_experimental_content_security_policy_features_enabled_;
    }

    static bool ExperimentalContentSecurityPolicyFeaturesEnabled(const FeatureContext*)
    {
        return ExperimentalContentSecurityPolicyFeaturesEnabled();
    }

    static bool ExperimentalJSProfilerMarkersEnabled()
    {
        return is_experimental_js_profiler_markers_enabled_;
    }

    static bool ExperimentalJSProfilerMarkersEnabled(const FeatureContext*)
    {
        return ExperimentalJSProfilerMarkersEnabled();
    }

    static bool ExperimentalMachineLearningNeuralNetworkEnabled()
    {
        return is_experimental_machine_learning_neural_network_enabled_;
    }

    static bool ExperimentalMachineLearningNeuralNetworkEnabled(const FeatureContext*)
    {
        return ExperimentalMachineLearningNeuralNetworkEnabled();
    }

    static bool ExperimentalPoliciesEnabled()
    {
        return is_experimental_policies_enabled_;
    }

    static bool ExperimentalPoliciesEnabled(const FeatureContext*)
    {
        return ExperimentalPoliciesEnabled();
    }

    static bool ExposeCoarsenedRenderTimeEnabled()
    {
        return is_expose_coarsened_render_time_enabled_;
    }

    static bool ExposeCoarsenedRenderTimeEnabled(const FeatureContext*)
    {
        return ExposeCoarsenedRenderTimeEnabled();
    }

    static bool ExposeRenderTimeNonTaoDelayedImageEnabled()
    {
        return is_expose_render_time_non_tao_delayed_image_enabled_;
    }

    static bool ExposeRenderTimeNonTaoDelayedImageEnabled(const FeatureContext*)
    {
        return ExposeRenderTimeNonTaoDelayedImageEnabled();
    }

    static bool ExtendedTextMetricsEnabled()
    {
        return is_extended_text_metrics_enabled_;
    }

    static bool ExtendedTextMetricsEnabled(const FeatureContext*)
    {
        return ExtendedTextMetricsEnabled();
    }

    static bool EyeDropperAPIEnabled()
    {
        return is_eye_dropper_api_enabled_;
    }

    static bool EyeDropperAPIEnabled(const FeatureContext*)
    {
        return EyeDropperAPIEnabled();
    }

    static bool FaceDetectorEnabled()
    {
        return is_face_detector_enabled_;
    }

    static bool FaceDetectorEnabled(const FeatureContext*)
    {
        return FaceDetectorEnabled();
    }

    static bool FastNonCompositedScrollHitTestEnabled()
    {
        if (!HitTestOpaquenessEnabled())
            return false;
        if (!RasterInducingScrollEnabled())
            return false;
        return is_fast_non_composited_scroll_hit_test_enabled_;
    }

    static bool FastNonCompositedScrollHitTestEnabled(const FeatureContext*)
    {
        return FastNonCompositedScrollHitTestEnabled();
    }

    static bool FastPathSingleSelectorExactMatchEnabled()
    {
        return is_fast_path_single_selector_exact_match_enabled_;
    }

    static bool FastPathSingleSelectorExactMatchEnabled(const FeatureContext*)
    {
        return FastPathSingleSelectorExactMatchEnabled();
    }

    static bool FastPositionIteratorEnabled()
    {
        return is_fast_position_iterator_enabled_;
    }

    static bool FastPositionIteratorEnabled(const FeatureContext*)
    {
        return FastPositionIteratorEnabled();
    }

    static bool FedCmEnabled()
    {
        return is_fed_cm_enabled_;
    }

    static bool FedCmEnabled(const FeatureContext*)
    {
        return FedCmEnabled();
    }

    static bool FedCmAutoSelectedFlagEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_auto_selected_flag_enabled_;
    }

    static bool FedCmAutoSelectedFlagEnabled(const FeatureContext*)
    {
        return FedCmAutoSelectedFlagEnabled();
    }

    static bool FedCmDisconnectEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_disconnect_enabled_;
    }

    static bool FedCmDisconnectEnabled(const FeatureContext*)
    {
        return FedCmDisconnectEnabled();
    }

    static bool FedCmDomainHintEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_domain_hint_enabled_;
    }

    static bool FedCmDomainHintEnabled(const FeatureContext*)
    {
        return FedCmDomainHintEnabled();
    }

    static bool FedCmErrorEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_error_enabled_;
    }

    static bool FedCmErrorEnabled(const FeatureContext*)
    {
        return FedCmErrorEnabled();
    }

    static bool FedCmIdPRegistrationEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_id_p_registration_enabled_;
    }

    static bool FedCmIdPRegistrationEnabled(const FeatureContext*)
    {
        return FedCmIdPRegistrationEnabled();
    }

    static bool FedCmIdpSigninStatusEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_idp_signin_status_enabled_;
    }

    static bool FedCmIdpSigninStatusEnabled(const FeatureContext*);

    static bool FedCmSelectiveDisclosureEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_selective_disclosure_enabled_;
    }

    static bool FedCmSelectiveDisclosureEnabled(const FeatureContext*)
    {
        return FedCmSelectiveDisclosureEnabled();
    }

    static bool FencedFramesEnabled()
    {
        return is_fenced_frames_enabled_;
    }

    static bool FencedFramesEnabled(const FeatureContext*)
    {
        return FencedFramesEnabled();
    }

    static bool FencedFramesAPIChangesEnabled()
    {
        return is_fenced_frames_api_changes_enabled_;
    }

    static bool FencedFramesAPIChangesEnabled(const FeatureContext*)
    {
        return FencedFramesAPIChangesEnabled();
    }

    static bool FencedFramesDefaultModeEnabled()
    {
        return is_fenced_frames_default_mode_enabled_;
    }

    static bool FencedFramesDefaultModeEnabled(const FeatureContext*)
    {
        return FencedFramesDefaultModeEnabled();
    }

    static bool FencedFramesLocalUnpartitionedDataAccessEnabled()
    {
        return is_fenced_frames_local_unpartitioned_data_access_enabled_;
    }

    static bool FencedFramesLocalUnpartitionedDataAccessEnabled(const FeatureContext*)
    {
        return FencedFramesLocalUnpartitionedDataAccessEnabled();
    }

    static bool FetchBodyBytesEnabled()
    {
        return is_fetch_body_bytes_enabled_;
    }

    static bool FetchBodyBytesEnabled(const FeatureContext*)
    {
        return FetchBodyBytesEnabled();
    }

    static bool FetchUploadStreamingEnabled()
    {
        return is_fetch_upload_streaming_enabled_;
    }

    static bool FetchUploadStreamingEnabled(const FeatureContext*)
    {
        return FetchUploadStreamingEnabled();
    }

    static bool FileHandlingEnabled()
    {
        if (!FileSystemAccessLocalEnabled())
            return false;
        return is_file_handling_enabled_;
    }

    static bool FileHandlingEnabled(const FeatureContext*)
    {
        return FileHandlingEnabled();
    }

    static bool FileHandlingIconsEnabled()
    {
        if (!FileHandlingEnabled())
            return false;
        return is_file_handling_icons_enabled_;
    }

    static bool FileHandlingIconsEnabled(const FeatureContext*)
    {
        return FileHandlingIconsEnabled();
    }

    static bool FileSystemEnabled()
    {
        return is_file_system_enabled_;
    }

    static bool FileSystemEnabled(const FeatureContext*)
    {
        return FileSystemEnabled();
    }

    static bool FileSystemAccessEnabled()
    {
        if (FileSystemAccessLocalEnabled())
            return true;
        if (FileSystemAccessOriginPrivateEnabled())
            return true;
        return is_file_system_access_enabled_;
    }

    static bool FileSystemAccessEnabled(const FeatureContext*)
    {
        return FileSystemAccessEnabled();
    }

    static bool FileSystemAccessAPIExperimentalEnabled()
    {
        return is_file_system_access_api_experimental_enabled_;
    }

    static bool FileSystemAccessAPIExperimentalEnabled(const FeatureContext*)
    {
        return FileSystemAccessAPIExperimentalEnabled();
    }

    static bool FileSystemAccessGetCloudIdentifiersEnabled()
    {
        return is_file_system_access_get_cloud_identifiers_enabled_;
    }

    static bool FileSystemAccessGetCloudIdentifiersEnabled(const FeatureContext*)
    {
        return FileSystemAccessGetCloudIdentifiersEnabled();
    }

    static bool FileSystemAccessLocalEnabled()
    {
        return is_file_system_access_local_enabled_;
    }

    static bool FileSystemAccessLocalEnabled(const FeatureContext*)
    {
        return FileSystemAccessLocalEnabled();
    }

    static bool FileSystemAccessLockingSchemeEnabled()
    {
        return is_file_system_access_locking_scheme_enabled_;
    }

    static bool FileSystemAccessLockingSchemeEnabled(const FeatureContext*)
    {
        return FileSystemAccessLockingSchemeEnabled();
    }

    static bool FileSystemAccessOriginPrivateEnabled()
    {
        return is_file_system_access_origin_private_enabled_;
    }

    static bool FileSystemAccessOriginPrivateEnabled(const FeatureContext*)
    {
        return FileSystemAccessOriginPrivateEnabled();
    }

    static bool FileSystemObserverUnobserveEnabled()
    {
        return is_file_system_observer_unobserve_enabled_;
    }

    static bool FileSystemObserverUnobserveEnabled(const FeatureContext*)
    {
        return FileSystemObserverUnobserveEnabled();
    }

    static bool FindDecomposedInShortTextEnabled()
    {
        return is_find_decomposed_in_short_text_enabled_;
    }

    static bool FindDecomposedInShortTextEnabled(const FeatureContext*)
    {
        return FindDecomposedInShortTextEnabled();
    }

    static bool FindRubyInPageEnabled()
    {
        return is_find_ruby_in_page_enabled_;
    }

    static bool FindRubyInPageEnabled(const FeatureContext*)
    {
        return FindRubyInPageEnabled();
    }

    static bool FindTextInReadonlyTextInputEnabled()
    {
        return is_find_text_in_readonly_text_input_enabled_;
    }

    static bool FindTextInReadonlyTextInputEnabled(const FeatureContext*)
    {
        return FindTextInReadonlyTextInputEnabled();
    }

    static bool FindTextSkipCollapsedTextEnabled()
    {
        if (!FindDecomposedInShortTextEnabled())
            return false;
        return is_find_text_skip_collapsed_text_enabled_;
    }

    static bool FindTextSkipCollapsedTextEnabled(const FeatureContext*)
    {
        return FindTextSkipCollapsedTextEnabled();
    }

    static bool FledgeEnabled()
    {
        return is_fledge_enabled_;
    }

    static bool FledgeEnabled(const FeatureContext*)
    {
        return FledgeEnabled();
    }

    static bool FledgeAuctionDealSupportEnabled()
    {
        return is_fledge_auction_deal_support_enabled_;
    }

    static bool FledgeAuctionDealSupportEnabled(const FeatureContext*)
    {
        return FledgeAuctionDealSupportEnabled();
    }

    static bool FledgeCustomMaxAuctionAdComponentsEnabled()
    {
        return is_fledge_custom_max_auction_ad_components_enabled_;
    }

    static bool FledgeCustomMaxAuctionAdComponentsEnabled(const FeatureContext*)
    {
        return FledgeCustomMaxAuctionAdComponentsEnabled();
    }

    static bool FledgeDeprecatedRenderURLReplacementsEnabled()
    {
        return is_fledge_deprecated_render_url_replacements_enabled_;
    }

    static bool FledgeDeprecatedRenderURLReplacementsEnabled(const FeatureContext*)
    {
        return FledgeDeprecatedRenderURLReplacementsEnabled();
    }

    static bool FledgeDirectFromSellerSignalsHeaderAdSlotEnabled()
    {
        return is_fledge_direct_from_seller_signals_header_ad_slot_enabled_;
    }

    static bool FledgeDirectFromSellerSignalsHeaderAdSlotEnabled(const FeatureContext*)
    {
        return FledgeDirectFromSellerSignalsHeaderAdSlotEnabled();
    }

    static bool FledgeMultiBidEnabled()
    {
        return is_fledge_multi_bid_enabled_;
    }

    static bool FledgeMultiBidEnabled(const FeatureContext*)
    {
        return FledgeMultiBidEnabled();
    }

    static bool FledgeRealTimeReportingEnabled()
    {
        return is_fledge_real_time_reporting_enabled_;
    }

    static bool FledgeRealTimeReportingEnabled(const FeatureContext*)
    {
        return FledgeRealTimeReportingEnabled();
    }

    static bool FledgeReportingTimeoutEnabled()
    {
        return is_fledge_reporting_timeout_enabled_;
    }

    static bool FledgeReportingTimeoutEnabled(const FeatureContext*)
    {
        return FledgeReportingTimeoutEnabled();
    }

    static bool FledgeSellerNonceEnabled()
    {
        return is_fledge_seller_nonce_enabled_;
    }

    static bool FledgeSellerNonceEnabled(const FeatureContext*)
    {
        return FledgeSellerNonceEnabled();
    }

    static bool FledgeTrustedSignalsKVv2SupportEnabled()
    {
        return is_fledge_trusted_signals_k_vv_2_support_enabled_;
    }

    static bool FledgeTrustedSignalsKVv2SupportEnabled(const FeatureContext*)
    {
        return FledgeTrustedSignalsKVv2SupportEnabled();
    }

    static bool FluentOverlayScrollbarsEnabled()
    {
        return is_fluent_overlay_scrollbars_enabled_;
    }

    static bool FluentOverlayScrollbarsEnabled(const FeatureContext*)
    {
        return FluentOverlayScrollbarsEnabled();
    }

    static bool FluentScrollbarsEnabled()
    {
        return is_fluent_scrollbars_enabled_;
    }

    static bool FluentScrollbarsEnabled(const FeatureContext*)
    {
        return FluentScrollbarsEnabled();
    }

    static bool FluentScrollbarUsesNinePatchTrackEnabled()
    {
        return is_fluent_scrollbar_uses_nine_patch_track_enabled_;
    }

    static bool FluentScrollbarUsesNinePatchTrackEnabled(const FeatureContext*)
    {
        return FluentScrollbarUsesNinePatchTrackEnabled();
    }

    static bool FontAccessEnabled()
    {
        return is_font_access_enabled_;
    }

    static bool FontAccessEnabled(const FeatureContext*)
    {
        return FontAccessEnabled();
    }

    static bool FontationsFontBackendEnabled()
    {
        return is_fontations_font_backend_enabled_;
    }

    static bool FontationsFontBackendEnabled(const FeatureContext*)
    {
        return FontationsFontBackendEnabled();
    }

    static bool FontationsForSelectedFormatsEnabled()
    {
        return is_fontations_for_selected_formats_enabled_;
    }

    static bool FontationsForSelectedFormatsEnabled(const FeatureContext*)
    {
        return FontationsForSelectedFormatsEnabled();
    }

    static bool FontFamilyPostscriptMatchingCTMigrationEnabled()
    {
        return is_font_family_postscript_matching_ct_migration_enabled_;
    }

    static bool FontFamilyPostscriptMatchingCTMigrationEnabled(const FeatureContext*)
    {
        return FontFamilyPostscriptMatchingCTMigrationEnabled();
    }

    static bool FontFamilyStyleMatchingCTMigrationEnabled()
    {
        return is_font_family_style_matching_ct_migration_enabled_;
    }

    static bool FontFamilyStyleMatchingCTMigrationEnabled(const FeatureContext*)
    {
        return FontFamilyStyleMatchingCTMigrationEnabled();
    }

    static bool FontPresentWinEnabled()
    {
        return is_font_present_win_enabled_;
    }

    static bool FontPresentWinEnabled(const FeatureContext*)
    {
        return FontPresentWinEnabled();
    }

    static bool FontSrcLocalMatchingEnabled()
    {
        return is_font_src_local_matching_enabled_;
    }

    static bool FontSrcLocalMatchingEnabled(const FeatureContext*)
    {
        return FontSrcLocalMatchingEnabled();
    }

    static bool FontSystemFallbackNotoCjkEnabled()
    {
        return is_font_system_fallback_noto_cjk_enabled_;
    }

    static bool FontSystemFallbackNotoCjkEnabled(const FeatureContext*)
    {
        return FontSystemFallbackNotoCjkEnabled();
    }

    static bool FontVariantEmojiEnabled()
    {
        return is_font_variant_emoji_enabled_;
    }

    static bool FontVariantEmojiEnabled(const FeatureContext*)
    {
        return FontVariantEmojiEnabled();
    }

    static bool FontVariationSequencesEnabled()
    {
        return is_font_variation_sequences_enabled_;
    }

    static bool FontVariationSequencesEnabled(const FeatureContext*)
    {
        return FontVariationSequencesEnabled();
    }

    static bool ForcedColorsEnabled()
    {
        return is_forced_colors_enabled_;
    }

    static bool ForcedColorsEnabled(const FeatureContext*)
    {
        return ForcedColorsEnabled();
    }

    static bool ForcedColorsPreserveParentColorEnabled()
    {
        return is_forced_colors_preserve_parent_color_enabled_;
    }

    static bool ForcedColorsPreserveParentColorEnabled(const FeatureContext*)
    {
        return ForcedColorsPreserveParentColorEnabled();
    }

    static bool ForceEagerMeasureMemoryEnabled()
    {
        return is_force_eager_measure_memory_enabled_;
    }

    static bool ForceEagerMeasureMemoryEnabled(const FeatureContext*)
    {
        return ForceEagerMeasureMemoryEnabled();
    }

    static bool ForceReduceMotionEnabled()
    {
        return is_force_reduce_motion_enabled_;
    }

    static bool ForceReduceMotionEnabled(const FeatureContext*)
    {
        return ForceReduceMotionEnabled();
    }

    static bool ForceTallerSelectPopupEnabled()
    {
        return is_force_taller_select_popup_enabled_;
    }

    static bool ForceTallerSelectPopupEnabled(const FeatureContext*)
    {
        return ForceTallerSelectPopupEnabled();
    }

    static bool FormControlRestoreStateIfAutocompleteOffEnabled()
    {
        return is_form_control_restore_state_if_autocomplete_off_enabled_;
    }

    static bool FormControlRestoreStateIfAutocompleteOffEnabled(const FeatureContext*)
    {
        return FormControlRestoreStateIfAutocompleteOffEnabled();
    }

    static bool FormControlsVerticalWritingModeDirectionSupportEnabled()
    {
        return is_form_controls_vertical_writing_mode_direction_support_enabled_;
    }

    static bool FormControlsVerticalWritingModeDirectionSupportEnabled(const FeatureContext*)
    {
        return FormControlsVerticalWritingModeDirectionSupportEnabled();
    }

    static bool FractionalScrollOffsetsEnabled()
    {
        return is_fractional_scroll_offsets_enabled_;
    }

    static bool FractionalScrollOffsetsEnabled(const FeatureContext*)
    {
        return FractionalScrollOffsetsEnabled();
    }

    static bool FreezeFramesOnVisibilityEnabled()
    {
        return is_freeze_frames_on_visibility_enabled_;
    }

    static bool FreezeFramesOnVisibilityEnabled(const FeatureContext*)
    {
        return FreezeFramesOnVisibilityEnabled();
    }

    static bool GamepadMultitouchEnabled()
    {
        return is_gamepad_multitouch_enabled_;
    }

    static bool GamepadMultitouchEnabled(const FeatureContext*)
    {
        return GamepadMultitouchEnabled();
    }

    static bool GetDisplayMediaEnabled()
    {
        return is_get_display_media_enabled_;
    }

    static bool GetDisplayMediaEnabled(const FeatureContext*)
    {
        return GetDisplayMediaEnabled();
    }

    static bool GetDisplayMediaRequiresUserActivationEnabled()
    {
        if (!GetDisplayMediaEnabled())
            return false;
        return is_get_display_media_requires_user_activation_enabled_;
    }

    static bool GetDisplayMediaRequiresUserActivationEnabled(const FeatureContext*)
    {
        return GetDisplayMediaRequiresUserActivationEnabled();
    }

    static bool GroupEffectEnabled()
    {
        return is_group_effect_enabled_;
    }

    static bool GroupEffectEnabled(const FeatureContext*)
    {
        return GroupEffectEnabled();
    }

    static bool HandleSelectionChangeOnDeletingEmptyElementEnabled()
    {
        return is_handle_selection_change_on_deleting_empty_element_enabled_;
    }

    static bool HandleSelectionChangeOnDeletingEmptyElementEnabled(const FeatureContext*)
    {
        return HandleSelectionChangeOnDeletingEmptyElementEnabled();
    }

    static bool HandwritingRecognitionEnabled()
    {
        return is_handwriting_recognition_enabled_;
    }

    static bool HandwritingRecognitionEnabled(const FeatureContext*)
    {
        return HandwritingRecognitionEnabled();
    }

    static bool HangingWhitespaceDoesNotDependOnAlignmentEnabled()
    {
        return is_hanging_whitespace_does_not_depend_on_alignment_enabled_;
    }

    static bool HangingWhitespaceDoesNotDependOnAlignmentEnabled(const FeatureContext*)
    {
        return HangingWhitespaceDoesNotDependOnAlignmentEnabled();
    }

    static bool HasUAVisualTransitionEnabled()
    {
        return is_has_ua_visual_transition_enabled_;
    }

    static bool HasUAVisualTransitionEnabled(const FeatureContext*)
    {
        return HasUAVisualTransitionEnabled();
    }

    static bool HighlightInheritanceEnabled()
    {
        return is_highlight_inheritance_enabled_;
    }

    static bool HighlightInheritanceEnabled(const FeatureContext*)
    {
        return HighlightInheritanceEnabled();
    }

    static bool HighlightPointerEventsEnabled()
    {
        return is_highlight_pointer_events_enabled_;
    }

    static bool HighlightPointerEventsEnabled(const FeatureContext*)
    {
        return HighlightPointerEventsEnabled();
    }

    static bool HighlightsFromPointEnabled()
    {
        return is_highlights_from_point_enabled_;
    }

    static bool HighlightsFromPointEnabled(const FeatureContext*)
    {
        return HighlightsFromPointEnabled();
    }

    static bool HitTestOpaquenessEnabled()
    {
        return is_hit_test_opaqueness_enabled_;
    }

    static bool HitTestOpaquenessEnabled(const FeatureContext*)
    {
        return HitTestOpaquenessEnabled();
    }

    static bool HitTestOpaquenessOmitLineBoxEnabled()
    {
        if (!HitTestOpaquenessEnabled())
            return false;
        return is_hit_test_opaqueness_omit_line_box_enabled_;
    }

    static bool HitTestOpaquenessOmitLineBoxEnabled(const FeatureContext*)
    {
        return HitTestOpaquenessOmitLineBoxEnabled();
    }

    static bool HTMLAnchorAttributeEnabled()
    {
        return is_html_anchor_attribute_enabled_;
    }

    static bool HTMLAnchorAttributeEnabled(const FeatureContext*)
    {
        return HTMLAnchorAttributeEnabled();
    }

    static bool HTMLDialogLightDismissEnabled()
    {
        return is_html_dialog_light_dismiss_enabled_;
    }

    static bool HTMLDialogLightDismissEnabled(const FeatureContext*)
    {
        return HTMLDialogLightDismissEnabled();
    }

    static bool HTMLEmbedElementNotForceLayoutEnabled()
    {
        return is_html_embed_element_not_force_layout_enabled_;
    }

    static bool HTMLEmbedElementNotForceLayoutEnabled(const FeatureContext*)
    {
        return HTMLEmbedElementNotForceLayoutEnabled();
    }

    static bool HTMLInterestTargetAttributeEnabled()
    {
        return is_html_interest_target_attribute_enabled_;
    }

    static bool HTMLInterestTargetAttributeEnabled(const FeatureContext*)
    {
        return HTMLInterestTargetAttributeEnabled();
    }

    static bool HTMLInvokeActionsV2Enabled()
    {
        return is_html_invoke_actions_v_2_enabled_;
    }

    static bool HTMLInvokeActionsV2Enabled(const FeatureContext*)
    {
        return HTMLInvokeActionsV2Enabled();
    }

    static bool HTMLInvokeTargetAttributeEnabled()
    {
        return is_html_invoke_target_attribute_enabled_;
    }

    static bool HTMLInvokeTargetAttributeEnabled(const FeatureContext*)
    {
        return HTMLInvokeTargetAttributeEnabled();
    }

    static bool HTMLObjectElementFallbackDetachContentFrameEnabled()
    {
        return is_html_object_element_fallback_detach_content_frame_enabled_;
    }

    static bool HTMLObjectElementFallbackDetachContentFrameEnabled(const FeatureContext*)
    {
        return HTMLObjectElementFallbackDetachContentFrameEnabled();
    }

    static bool HTMLParserYieldAndDelayOftenForTestingEnabled()
    {
        return is_html_parser_yield_and_delay_often_for_testing_enabled_;
    }

    static bool HTMLParserYieldAndDelayOftenForTestingEnabled(const FeatureContext*)
    {
        return HTMLParserYieldAndDelayOftenForTestingEnabled();
    }

    static bool HTMLPopoverActionHoverEnabled()
    {
        return is_html_popover_action_hover_enabled_;
    }

    static bool HTMLPopoverActionHoverEnabled(const FeatureContext*)
    {
        return HTMLPopoverActionHoverEnabled();
    }

    static bool HTMLPopoverHintEnabled()
    {
        return is_html_popover_hint_enabled_;
    }

    static bool HTMLPopoverHintEnabled(const FeatureContext*)
    {
        return HTMLPopoverHintEnabled();
    }

    static bool HTMLSelectElementShowPickerEnabled()
    {
        return is_html_select_element_show_picker_enabled_;
    }

    static bool HTMLSelectElementShowPickerEnabled(const FeatureContext*)
    {
        return HTMLSelectElementShowPickerEnabled();
    }

    static bool ImplicitRootScrollerEnabled()
    {
        return is_implicit_root_scroller_enabled_;
    }

    static bool ImplicitRootScrollerEnabled(const FeatureContext*)
    {
        return ImplicitRootScrollerEnabled();
    }

    static bool ImportAttributesDisallowUnknownKeysEnabled()
    {
        return is_import_attributes_disallow_unknown_keys_enabled_;
    }

    static bool ImportAttributesDisallowUnknownKeysEnabled(const FeatureContext*)
    {
        return ImportAttributesDisallowUnknownKeysEnabled();
    }

    static bool ImportMapIntegrityEnabled()
    {
        return is_import_map_integrity_enabled_;
    }

    static bool ImportMapIntegrityEnabled(const FeatureContext*)
    {
        return ImportMapIntegrityEnabled();
    }

    static bool IncomingCallNotificationsEnabled()
    {
        return is_incoming_call_notifications_enabled_;
    }

    static bool IncomingCallNotificationsEnabled(const FeatureContext*)
    {
        return IncomingCallNotificationsEnabled();
    }

    static bool IncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled()
    {
        return is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_;
    }

    static bool IncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled(const FeatureContext*)
    {
        return IncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled();
    }

    static bool IndexedDbGetAllRecordsEnabled()
    {
        return is_indexed_db_get_all_records_enabled_;
    }

    static bool IndexedDbGetAllRecordsEnabled(const FeatureContext*)
    {
        return IndexedDbGetAllRecordsEnabled();
    }

    static bool InertElementNonEditableEnabled()
    {
        return is_inert_element_non_editable_enabled_;
    }

    static bool InertElementNonEditableEnabled(const FeatureContext*)
    {
        return InertElementNonEditableEnabled();
    }

    static bool InertElementNonSearchableEnabled()
    {
        return is_inert_element_non_searchable_enabled_;
    }

    static bool InertElementNonSearchableEnabled(const FeatureContext*)
    {
        return InertElementNonSearchableEnabled();
    }

    static bool InfiniteCullRectEnabled()
    {
        return is_infinite_cull_rect_enabled_;
    }

    static bool InfiniteCullRectEnabled(const FeatureContext*)
    {
        return InfiniteCullRectEnabled();
    }

    static bool InheritUserModifyWithoutContenteditableEnabled()
    {
        return is_inherit_user_modify_without_contenteditable_enabled_;
    }

    static bool InheritUserModifyWithoutContenteditableEnabled(const FeatureContext*)
    {
        return InheritUserModifyWithoutContenteditableEnabled();
    }

    static bool InitialLetterRaiseBySpecifiedEnabled()
    {
        return is_initial_letter_raise_by_specified_enabled_;
    }

    static bool InitialLetterRaiseBySpecifiedEnabled(const FeatureContext*)
    {
        return InitialLetterRaiseBySpecifiedEnabled();
    }

    static bool InlineBlockInSameLineEnabled()
    {
        return is_inline_block_in_same_line_enabled_;
    }

    static bool InlineBlockInSameLineEnabled(const FeatureContext*)
    {
        return InlineBlockInSameLineEnabled();
    }

    static bool InnerHTMLParserFastpathLogFailureEnabled()
    {
        return is_inner_html_parser_fastpath_log_failure_enabled_;
    }

    static bool InnerHTMLParserFastpathLogFailureEnabled(const FeatureContext*)
    {
        return InnerHTMLParserFastpathLogFailureEnabled();
    }

    static bool InputClosesSelectEnabled()
    {
        if (!SelectParserRelaxationEnabled())
            return false;
        return is_input_closes_select_enabled_;
    }

    static bool InputClosesSelectEnabled(const FeatureContext*)
    {
        return InputClosesSelectEnabled();
    }

    static bool InputMultipleFieldsUIEnabled()
    {
        return is_input_multiple_fields_ui_enabled_;
    }

    static bool InputMultipleFieldsUIEnabled(const FeatureContext*)
    {
        return InputMultipleFieldsUIEnabled();
    }

    static bool InsertBlockquoteBeforeOuterBlockEnabled()
    {
        return is_insert_blockquote_before_outer_block_enabled_;
    }

    static bool InsertBlockquoteBeforeOuterBlockEnabled(const FeatureContext*)
    {
        return InsertBlockquoteBeforeOuterBlockEnabled();
    }

    static bool InsertLineBreakIfPhrasingContentEnabled()
    {
        return is_insert_line_break_if_phrasing_content_enabled_;
    }

    static bool InsertLineBreakIfPhrasingContentEnabled(const FeatureContext*)
    {
        return InsertLineBreakIfPhrasingContentEnabled();
    }

    static bool InspectorGhostRulesEnabled()
    {
        return is_inspector_ghost_rules_enabled_;
    }

    static bool InspectorGhostRulesEnabled(const FeatureContext*)
    {
        return InspectorGhostRulesEnabled();
    }

    static bool InstalledAppEnabled()
    {
        return is_installed_app_enabled_;
    }

    static bool InstalledAppEnabled(const FeatureContext*)
    {
        return InstalledAppEnabled();
    }

    static bool InstallOnDeviceSpeechRecognitionEnabled()
    {
        return is_install_on_device_speech_recognition_enabled_;
    }

    static bool InstallOnDeviceSpeechRecognitionEnabled(const FeatureContext*)
    {
        return InstallOnDeviceSpeechRecognitionEnabled();
    }

    static bool InterestGroupsInSharedStorageWorkletEnabled()
    {
        return is_interest_groups_in_shared_storage_worklet_enabled_;
    }

    static bool InterestGroupsInSharedStorageWorkletEnabled(const FeatureContext*)
    {
        return InterestGroupsInSharedStorageWorkletEnabled();
    }

    static bool InteroperablePrivateAttributionEnabled()
    {
        return is_interoperable_private_attribution_enabled_;
    }

    static bool InteroperablePrivateAttributionEnabled(const FeatureContext*)
    {
        return InteroperablePrivateAttributionEnabled();
    }

    static bool IntersectionObserverScrollMarginEnabled()
    {
        return is_intersection_observer_scroll_margin_enabled_;
    }

    static bool IntersectionObserverScrollMarginEnabled(const FeatureContext*)
    {
        return IntersectionObserverScrollMarginEnabled();
    }

    static bool InvertedColorsEnabled()
    {
        return is_inverted_colors_enabled_;
    }

    static bool InvertedColorsEnabled(const FeatureContext*)
    {
        return InvertedColorsEnabled();
    }

    static bool InvisibleSVGAnimationThrottlingEnabled()
    {
        return is_invisible_svg_animation_throttling_enabled_;
    }

    static bool InvisibleSVGAnimationThrottlingEnabled(const FeatureContext*)
    {
        return InvisibleSVGAnimationThrottlingEnabled();
    }

    static bool KeepCSSTargetAfterReattachEnabled()
    {
        return is_keep_css_target_after_reattach_enabled_;
    }

    static bool KeepCSSTargetAfterReattachEnabled(const FeatureContext*)
    {
        return KeepCSSTargetAfterReattachEnabled();
    }

    static bool KeyboardAccessibleTooltipEnabled()
    {
        return is_keyboard_accessible_tooltip_enabled_;
    }

    static bool KeyboardAccessibleTooltipEnabled(const FeatureContext*)
    {
        return KeyboardAccessibleTooltipEnabled();
    }

    static bool KeyboardFocusableScrollersEnabled()
    {
        return is_keyboard_focusable_scrollers_enabled_;
    }

    static bool KeyboardFocusableScrollersEnabled(const FeatureContext*)
    {
        return KeyboardFocusableScrollersEnabled();
    }

    static bool LabelAndDelegatesFocusNewHandlingEnabled()
    {
        return is_label_and_delegates_focus_new_handling_enabled_;
    }

    static bool LabelAndDelegatesFocusNewHandlingEnabled(const FeatureContext*)
    {
        return LabelAndDelegatesFocusNewHandlingEnabled();
    }

    static bool LangAttributeAwareFormControlUIEnabled()
    {
        return is_lang_attribute_aware_form_control_ui_enabled_;
    }

    static bool LangAttributeAwareFormControlUIEnabled(const FeatureContext*)
    {
        return LangAttributeAwareFormControlUIEnabled();
    }

    static bool LayoutFlexNewRowAlgorithmV3Enabled()
    {
        return is_layout_flex_new_row_algorithm_v_3_enabled_;
    }

    static bool LayoutFlexNewRowAlgorithmV3Enabled(const FeatureContext*)
    {
        return LayoutFlexNewRowAlgorithmV3Enabled();
    }

    static bool LayoutIgnoreMarginsForStickyEnabled()
    {
        return is_layout_ignore_margins_for_sticky_enabled_;
    }

    static bool LayoutIgnoreMarginsForStickyEnabled(const FeatureContext*)
    {
        return LayoutIgnoreMarginsForStickyEnabled();
    }

    static bool LayoutJustifySelfForBlocksEnabled()
    {
        return is_layout_justify_self_for_blocks_enabled_;
    }

    static bool LayoutJustifySelfForBlocksEnabled(const FeatureContext*)
    {
        return LayoutJustifySelfForBlocksEnabled();
    }

    static bool LayoutNGShapeCacheEnabled()
    {
        return is_layout_ng_shape_cache_enabled_;
    }

    static bool LayoutNGShapeCacheEnabled(const FeatureContext*)
    {
        return LayoutNGShapeCacheEnabled();
    }

    static bool LayoutStretchEnabled()
    {
        return is_layout_stretch_enabled_;
    }

    static bool LayoutStretchEnabled(const FeatureContext*)
    {
        return LayoutStretchEnabled();
    }

    static bool LazyInitializeMediaControlsEnabled()
    {
        return is_lazy_initialize_media_controls_enabled_;
    }

    static bool LazyInitializeMediaControlsEnabled(const FeatureContext*)
    {
        return LazyInitializeMediaControlsEnabled();
    }

    static bool LazyLoadScrollMarginEnabled()
    {
        return is_lazy_load_scroll_margin_enabled_;
    }

    static bool LazyLoadScrollMarginEnabled(const FeatureContext*)
    {
        return LazyLoadScrollMarginEnabled();
    }

    static bool LazyLoadScrollMarginIframeEnabled()
    {
        return is_lazy_load_scroll_margin_iframe_enabled_;
    }

    static bool LazyLoadScrollMarginIframeEnabled(const FeatureContext*)
    {
        return LazyLoadScrollMarginIframeEnabled();
    }

    static bool LCPAnimatedImagesWebExposedEnabled()
    {
        return is_lcp_animated_images_web_exposed_enabled_;
    }

    static bool LCPAnimatedImagesWebExposedEnabled(const FeatureContext*)
    {
        return LCPAnimatedImagesWebExposedEnabled();
    }

    static bool LegacyWindowsDWriteFontFallbackEnabled()
    {
        return is_legacy_windows_d_write_font_fallback_enabled_;
    }

    static bool LegacyWindowsDWriteFontFallbackEnabled(const FeatureContext*)
    {
        return LegacyWindowsDWriteFontFallbackEnabled();
    }

    static bool LineBoxBelowLeadingFloatsEnabled()
    {
        return is_line_box_below_leading_floats_enabled_;
    }

    static bool LineBoxBelowLeadingFloatsEnabled(const FeatureContext*)
    {
        return LineBoxBelowLeadingFloatsEnabled();
    }

    static bool ListItemWithCounterSetNotSetExplicitValueEnabled()
    {
        return is_list_item_with_counter_set_not_set_explicit_value_enabled_;
    }

    static bool ListItemWithCounterSetNotSetExplicitValueEnabled(const FeatureContext*)
    {
        return ListItemWithCounterSetNotSetExplicitValueEnabled();
    }

    static bool LockedModeEnabled()
    {
        return is_locked_mode_enabled_;
    }

    static bool LockedModeEnabled(const FeatureContext*)
    {
        return LockedModeEnabled();
    }

    static bool LongAnimationFrameTimingEnabled()
    {
        return is_long_animation_frame_timing_enabled_;
    }

    static bool LongAnimationFrameTimingEnabled(const FeatureContext*)
    {
        return LongAnimationFrameTimingEnabled();
    }

    static bool LongPressLinkSelectTextEnabled()
    {
        return is_long_press_link_select_text_enabled_;
    }

    static bool LongPressLinkSelectTextEnabled(const FeatureContext*)
    {
        return LongPressLinkSelectTextEnabled();
    }

    static bool LongTaskFromLongAnimationFrameEnabled()
    {
        return is_long_task_from_long_animation_frame_enabled_;
    }

    static bool LongTaskFromLongAnimationFrameEnabled(const FeatureContext*)
    {
        return LongTaskFromLongAnimationFrameEnabled();
    }

    static bool MachineLearningNeuralNetworkEnabled()
    {
        return is_machine_learning_neural_network_enabled_;
    }

    static bool MachineLearningNeuralNetworkEnabled(const FeatureContext*)
    {
        return MachineLearningNeuralNetworkEnabled();
    }

    static bool ManagedConfigurationEnabled()
    {
        return is_managed_configuration_enabled_;
    }

    static bool ManagedConfigurationEnabled(const FeatureContext*)
    {
        return ManagedConfigurationEnabled();
    }

    static bool MeasureMemoryEnabled()
    {
        return is_measure_memory_enabled_;
    }

    static bool MeasureMemoryEnabled(const FeatureContext*)
    {
        return MeasureMemoryEnabled();
    }

    static bool MediaCapabilitiesDynamicRangeEnabled()
    {
        return is_media_capabilities_dynamic_range_enabled_;
    }

    static bool MediaCapabilitiesDynamicRangeEnabled(const FeatureContext*)
    {
        return MediaCapabilitiesDynamicRangeEnabled();
    }

    static bool MediaCapabilitiesEncodingInfoEnabled()
    {
        return is_media_capabilities_encoding_info_enabled_;
    }

    static bool MediaCapabilitiesEncodingInfoEnabled(const FeatureContext*)
    {
        return MediaCapabilitiesEncodingInfoEnabled();
    }

    static bool MediaCapabilitiesSpatialAudioEnabled()
    {
        return is_media_capabilities_spatial_audio_enabled_;
    }

    static bool MediaCapabilitiesSpatialAudioEnabled(const FeatureContext*)
    {
        return MediaCapabilitiesSpatialAudioEnabled();
    }

    static bool MediaCaptureEnabled()
    {
        return is_media_capture_enabled_;
    }

    static bool MediaCaptureEnabled(const FeatureContext*)
    {
        return MediaCaptureEnabled();
    }

    static bool MediaCaptureCameraControlsEnabled()
    {
        return is_media_capture_camera_controls_enabled_;
    }

    static bool MediaCaptureCameraControlsEnabled(const FeatureContext*)
    {
        return MediaCaptureCameraControlsEnabled();
    }

    static bool MediaCaptureVoiceIsolationEnabled()
    {
        return is_media_capture_voice_isolation_enabled_;
    }

    static bool MediaCaptureVoiceIsolationEnabled(const FeatureContext*)
    {
        return MediaCaptureVoiceIsolationEnabled();
    }

    static bool MediaCastOverlayButtonEnabled()
    {
        return is_media_cast_overlay_button_enabled_;
    }

    static bool MediaCastOverlayButtonEnabled(const FeatureContext*)
    {
        return MediaCastOverlayButtonEnabled();
    }

    static bool MediaControlsExpandGestureEnabled()
    {
        return is_media_controls_expand_gesture_enabled_;
    }

    static bool MediaControlsExpandGestureEnabled(const FeatureContext*)
    {
        return MediaControlsExpandGestureEnabled();
    }

    static bool MediaControlsOverlayPlayButtonEnabled()
    {
        return is_media_controls_overlay_play_button_enabled_;
    }

    static bool MediaControlsOverlayPlayButtonEnabled(const FeatureContext*)
    {
        return MediaControlsOverlayPlayButtonEnabled();
    }

    static bool MediaElementVolumeGreaterThanOneEnabled()
    {
        return is_media_element_volume_greater_than_one_enabled_;
    }

    static bool MediaElementVolumeGreaterThanOneEnabled(const FeatureContext*)
    {
        return MediaElementVolumeGreaterThanOneEnabled();
    }

    static bool MediaEngagementBypassAutoplayPoliciesEnabled()
    {
        return is_media_engagement_bypass_autoplay_policies_enabled_;
    }

    static bool MediaEngagementBypassAutoplayPoliciesEnabled(const FeatureContext*)
    {
        return MediaEngagementBypassAutoplayPoliciesEnabled();
    }

    static bool MediaLatencyHintEnabled()
    {
        return is_media_latency_hint_enabled_;
    }

    static bool MediaLatencyHintEnabled(const FeatureContext*)
    {
        return MediaLatencyHintEnabled();
    }

    static bool MediaPlaybackWhileNotVisiblePermissionPolicyEnabled()
    {
        return is_media_playback_while_not_visible_permission_policy_enabled_;
    }

    static bool MediaPlaybackWhileNotVisiblePermissionPolicyEnabled(const FeatureContext*)
    {
        return MediaPlaybackWhileNotVisiblePermissionPolicyEnabled();
    }

    static bool MediaQueryNavigationControlsEnabled()
    {
        return is_media_query_navigation_controls_enabled_;
    }

    static bool MediaQueryNavigationControlsEnabled(const FeatureContext*)
    {
        return MediaQueryNavigationControlsEnabled();
    }

    static bool MediaRecorderUseMediaVideoEncoderEnabled()
    {
        return is_media_recorder_use_media_video_encoder_enabled_;
    }

    static bool MediaRecorderUseMediaVideoEncoderEnabled(const FeatureContext*)
    {
        return MediaRecorderUseMediaVideoEncoderEnabled();
    }

    static bool MediaSessionEnabled()
    {
        return is_media_session_enabled_;
    }

    static bool MediaSessionEnabled(const FeatureContext*)
    {
        return MediaSessionEnabled();
    }

    static bool MediaSessionChapterInformationEnabled()
    {
        return is_media_session_chapter_information_enabled_;
    }

    static bool MediaSessionChapterInformationEnabled(const FeatureContext*)
    {
        return MediaSessionChapterInformationEnabled();
    }

    static bool MediaSessionEnterPictureInPictureEnabled()
    {
        return is_media_session_enter_picture_in_picture_enabled_;
    }

    static bool MediaSessionEnterPictureInPictureEnabled(const FeatureContext*)
    {
        return MediaSessionEnterPictureInPictureEnabled();
    }

    static bool MediaSourceExperimentalEnabled()
    {
        return is_media_source_experimental_enabled_;
    }

    static bool MediaSourceExperimentalEnabled(const FeatureContext*)
    {
        return MediaSourceExperimentalEnabled();
    }

    static bool MediaSourceNewAbortAndDurationEnabled()
    {
        return is_media_source_new_abort_and_duration_enabled_;
    }

    static bool MediaSourceNewAbortAndDurationEnabled(const FeatureContext*)
    {
        return MediaSourceNewAbortAndDurationEnabled();
    }

    static bool MediaStreamTrackTransferEnabled()
    {
        return is_media_stream_track_transfer_enabled_;
    }

    static bool MediaStreamTrackTransferEnabled(const FeatureContext*)
    {
        return MediaStreamTrackTransferEnabled();
    }

    static bool MediaStreamTrackWebSpeechEnabled()
    {
        return is_media_stream_track_web_speech_enabled_;
    }

    static bool MediaStreamTrackWebSpeechEnabled(const FeatureContext*)
    {
        return MediaStreamTrackWebSpeechEnabled();
    }

    static bool MessagePortCloseEventEnabled()
    {
        return is_message_port_close_event_enabled_;
    }

    static bool MessagePortCloseEventEnabled(const FeatureContext*)
    {
        return MessagePortCloseEventEnabled();
    }

    static bool MetaRefreshNoFractionalEnabled()
    {
        return is_meta_refresh_no_fractional_enabled_;
    }

    static bool MetaRefreshNoFractionalEnabled(const FeatureContext*)
    {
        return MetaRefreshNoFractionalEnabled();
    }

    static bool MeterAppearanceNoneFallbackStyleEnabled()
    {
        return is_meter_appearance_none_fallback_style_enabled_;
    }

    static bool MeterAppearanceNoneFallbackStyleEnabled(const FeatureContext*)
    {
        return MeterAppearanceNoneFallbackStyleEnabled();
    }

    static bool MeterDevolveAppearanceEnabled()
    {
        return is_meter_devolve_appearance_enabled_;
    }

    static bool MeterDevolveAppearanceEnabled(const FeatureContext*)
    {
        return MeterDevolveAppearanceEnabled();
    }

    static bool MiddleClickAutoscrollEnabled()
    {
        return is_middle_click_autoscroll_enabled_;
    }

    static bool MiddleClickAutoscrollEnabled(const FeatureContext*)
    {
        return MiddleClickAutoscrollEnabled();
    }

    static bool MinimimalResourceRequestPrepBeforeCacheLookupEnabled()
    {
        return is_minimimal_resource_request_prep_before_cache_lookup_enabled_;
    }

    static bool MinimimalResourceRequestPrepBeforeCacheLookupEnabled(const FeatureContext*)
    {
        return MinimimalResourceRequestPrepBeforeCacheLookupEnabled();
    }

    static bool MobileLayoutThemeEnabled()
    {
        return is_mobile_layout_theme_enabled_;
    }

    static bool MobileLayoutThemeEnabled(const FeatureContext*)
    {
        return MobileLayoutThemeEnabled();
    }

    static bool ModifyParagraphCrossEditingoundaryEnabled()
    {
        return is_modify_paragraph_cross_editingoundary_enabled_;
    }

    static bool ModifyParagraphCrossEditingoundaryEnabled(const FeatureContext*)
    {
        return ModifyParagraphCrossEditingoundaryEnabled();
    }

    static bool MojoJSEnabled()
    {
        return get_is_mojo_js_enabled_();
    }

    static bool MojoJSEnabled(const FeatureContext*)
    {
        return MojoJSEnabled();
    }

    static bool MojoJSTestEnabled()
    {
        return get_is_mojo_js_test_enabled_();
    }

    static bool MojoJSTestEnabled(const FeatureContext*)
    {
        return MojoJSTestEnabled();
    }

    static bool MoveEndingSelectionToListChildEnabled()
    {
        return is_move_ending_selection_to_list_child_enabled_;
    }

    static bool MoveEndingSelectionToListChildEnabled(const FeatureContext*)
    {
        return MoveEndingSelectionToListChildEnabled();
    }

    static bool MoveToParagraphStartOrEndSkipsNonEditableEnabled()
    {
        return is_move_to_paragraph_start_or_end_skips_non_editable_enabled_;
    }

    static bool MoveToParagraphStartOrEndSkipsNonEditableEnabled(const FeatureContext*)
    {
        return MoveToParagraphStartOrEndSkipsNonEditableEnabled();
    }

    static bool MultipleImportMapsEnabled()
    {
        return is_multiple_import_maps_enabled_;
    }

    static bool MultipleImportMapsEnabled(const FeatureContext*)
    {
        return MultipleImportMapsEnabled();
    }

    static bool MultiSelectDeselectWhenOnlyOptionEnabled()
    {
        return is_multi_select_deselect_when_only_option_enabled_;
    }

    static bool MultiSelectDeselectWhenOnlyOptionEnabled(const FeatureContext*)
    {
        return MultiSelectDeselectWhenOnlyOptionEnabled();
    }

    static bool MultiSmoothScrollIntoViewEnabled()
    {
        return is_multi_smooth_scroll_into_view_enabled_;
    }

    static bool MultiSmoothScrollIntoViewEnabled(const FeatureContext*)
    {
        return MultiSmoothScrollIntoViewEnabled();
    }

    static bool MutationEventsSpecialTrialMessageEnabled()
    {
        return is_mutation_events_special_trial_message_enabled_;
    }

    static bool MutationEventsSpecialTrialMessageEnabled(const FeatureContext*)
    {
        return MutationEventsSpecialTrialMessageEnabled();
    }

    static bool NavigateEventCommitBehaviorEnabled()
    {
        return is_navigate_event_commit_behavior_enabled_;
    }

    static bool NavigateEventCommitBehaviorEnabled(const FeatureContext*)
    {
        return NavigateEventCommitBehaviorEnabled();
    }

    static bool NavigateEventSourceElementEnabled()
    {
        return is_navigate_event_source_element_enabled_;
    }

    static bool NavigateEventSourceElementEnabled(const FeatureContext*)
    {
        return NavigateEventSourceElementEnabled();
    }

    static bool NavigationActivationEnabled()
    {
        return is_navigation_activation_enabled_;
    }

    static bool NavigationActivationEnabled(const FeatureContext*)
    {
        return NavigationActivationEnabled();
    }

    static bool NavigatorContentUtilsEnabled()
    {
        return is_navigator_content_utils_enabled_;
    }

    static bool NavigatorContentUtilsEnabled(const FeatureContext*)
    {
        return NavigatorContentUtilsEnabled();
    }

    static bool NestedViewTransitionEnabled()
    {
        return is_nested_view_transition_enabled_;
    }

    static bool NestedViewTransitionEnabled(const FeatureContext*)
    {
        return NestedViewTransitionEnabled();
    }

    static bool NetInfoConstantTypeEnabled()
    {
        return is_net_info_constant_type_enabled_;
    }

    static bool NetInfoConstantTypeEnabled(const FeatureContext*)
    {
        return NetInfoConstantTypeEnabled();
    }

    static bool NetInfoDownlinkMaxEnabled()
    {
        return is_net_info_downlink_max_enabled_;
    }

    static bool NetInfoDownlinkMaxEnabled(const FeatureContext*)
    {
        return NetInfoDownlinkMaxEnabled();
    }

    static bool NewGetFocusableAreaBehaviorEnabled()
    {
        return is_new_get_focusable_area_behavior_enabled_;
    }

    static bool NewGetFocusableAreaBehaviorEnabled(const FeatureContext*)
    {
        return NewGetFocusableAreaBehaviorEnabled();
    }

    static bool NoIdleEncodingForWebTestsEnabled()
    {
        return is_no_idle_encoding_for_web_tests_enabled_;
    }

    static bool NoIdleEncodingForWebTestsEnabled(const FeatureContext*)
    {
        return NoIdleEncodingForWebTestsEnabled();
    }

    static bool NoIncreasingEndOffsetOnSplittingTextNodesEnabled()
    {
        return is_no_increasing_end_offset_on_splitting_text_nodes_enabled_;
    }

    static bool NoIncreasingEndOffsetOnSplittingTextNodesEnabled(const FeatureContext*)
    {
        return NoIncreasingEndOffsetOnSplittingTextNodesEnabled();
    }

    static bool NonEmptyBlockquotesOnOutdentingEnabled()
    {
        return is_non_empty_blockquotes_on_outdenting_enabled_;
    }

    static bool NonEmptyBlockquotesOnOutdentingEnabled(const FeatureContext*)
    {
        return NonEmptyBlockquotesOnOutdentingEnabled();
    }

    static bool NonNullInputEventDataForTextAreaEnabled()
    {
        return is_non_null_input_event_data_for_text_area_enabled_;
    }

    static bool NonNullInputEventDataForTextAreaEnabled(const FeatureContext*)
    {
        return NonNullInputEventDataForTextAreaEnabled();
    }

    static bool NonStandardAppearanceValueSliderVerticalEnabled()
    {
        return is_non_standard_appearance_value_slider_vertical_enabled_;
    }

    static bool NonStandardAppearanceValueSliderVerticalEnabled(const FeatureContext*)
    {
        return NonStandardAppearanceValueSliderVerticalEnabled();
    }

    static bool NotificationConstructorEnabled()
    {
        return is_notification_constructor_enabled_;
    }

    static bool NotificationConstructorEnabled(const FeatureContext*)
    {
        return NotificationConstructorEnabled();
    }

    static bool NotificationContentImageEnabled()
    {
        return is_notification_content_image_enabled_;
    }

    static bool NotificationContentImageEnabled(const FeatureContext*)
    {
        return NotificationContentImageEnabled();
    }

    static bool NotificationsEnabled()
    {
        return is_notifications_enabled_;
    }

    static bool NotificationsEnabled(const FeatureContext*)
    {
        return NotificationsEnabled();
    }

    static bool ObservableAPIEnabled()
    {
        return is_observable_api_enabled_;
    }

    static bool ObservableAPIEnabled(const FeatureContext*)
    {
        return ObservableAPIEnabled();
    }

    static bool OffMainThreadCSSPaintEnabled()
    {
        return is_off_main_thread_css_paint_enabled_;
    }

    static bool OffMainThreadCSSPaintEnabled(const FeatureContext*)
    {
        return OffMainThreadCSSPaintEnabled();
    }

    static bool OffscreenCanvasCommitEnabled()
    {
        return is_offscreen_canvas_commit_enabled_;
    }

    static bool OffscreenCanvasCommitEnabled(const FeatureContext*)
    {
        return OffscreenCanvasCommitEnabled();
    }

    static bool OmitBlurEventOnElementRemovalEnabled()
    {
        return is_omit_blur_event_on_element_removal_enabled_;
    }

    static bool OmitBlurEventOnElementRemovalEnabled(const FeatureContext*)
    {
        return OmitBlurEventOnElementRemovalEnabled();
    }

    static bool OnDeviceChangeEnabled()
    {
        return is_on_device_change_enabled_;
    }

    static bool OnDeviceChangeEnabled(const FeatureContext*)
    {
        return OnDeviceChangeEnabled();
    }

    static bool OnDeviceWebSpeechAvailableEnabled()
    {
        return is_on_device_web_speech_available_enabled_;
    }

    static bool OnDeviceWebSpeechAvailableEnabled(const FeatureContext*)
    {
        return OnDeviceWebSpeechAvailableEnabled();
    }

    static bool OrientationEventEnabled()
    {
        return is_orientation_event_enabled_;
    }

    static bool OrientationEventEnabled(const FeatureContext*)
    {
        return OrientationEventEnabled();
    }

    static bool OriginIsolationHeaderEnabled()
    {
        return is_origin_isolation_header_enabled_;
    }

    static bool OriginIsolationHeaderEnabled(const FeatureContext*)
    {
        return OriginIsolationHeaderEnabled();
    }

    static bool OriginPolicyEnabled()
    {
        return is_origin_policy_enabled_;
    }

    static bool OriginPolicyEnabled(const FeatureContext*)
    {
        return OriginPolicyEnabled();
    }

    static bool OverscrollCustomizationEnabled()
    {
        return is_overscroll_customization_enabled_;
    }

    static bool OverscrollCustomizationEnabled(const FeatureContext*)
    {
        return OverscrollCustomizationEnabled();
    }

    static bool PageMarginBoxesEnabled()
    {
        return is_page_margin_boxes_enabled_;
    }

    static bool PageMarginBoxesEnabled(const FeatureContext*)
    {
        return PageMarginBoxesEnabled();
    }

    static bool PagePopupEnabled()
    {
        return is_page_popup_enabled_;
    }

    static bool PagePopupEnabled(const FeatureContext*)
    {
        return PagePopupEnabled();
    }

    static bool PageRevealEventEnabled()
    {
        return is_page_reveal_event_enabled_;
    }

    static bool PageRevealEventEnabled(const FeatureContext*)
    {
        return PageRevealEventEnabled();
    }

    static bool PageSwapEventEnabled()
    {
        return is_page_swap_event_enabled_;
    }

    static bool PageSwapEventEnabled(const FeatureContext*)
    {
        return PageSwapEventEnabled();
    }

    static bool PaintHighlightsForFirstLetterEnabled()
    {
        return is_paint_highlights_for_first_letter_enabled_;
    }

    static bool PaintHighlightsForFirstLetterEnabled(const FeatureContext*)
    {
        return PaintHighlightsForFirstLetterEnabled();
    }

    static bool PaintHoldingForIframesEnabled()
    {
        return is_paint_holding_for_iframes_enabled_;
    }

    static bool PaintHoldingForIframesEnabled(const FeatureContext*)
    {
        return PaintHoldingForIframesEnabled();
    }

    static bool PaintHoldingForLocalIframesEnabled()
    {
        return is_paint_holding_for_local_iframes_enabled_;
    }

    static bool PaintHoldingForLocalIframesEnabled(const FeatureContext*)
    {
        return PaintHoldingForLocalIframesEnabled();
    }

    static bool PaintUnderInvalidationCheckingEnabled()
    {
        return is_paint_under_invalidation_checking_enabled_;
    }

    static bool PaintUnderInvalidationCheckingEnabled(const FeatureContext*)
    {
        return PaintUnderInvalidationCheckingEnabled();
    }

    static bool PartitionedPopinsEnabled()
    {
        return is_partitioned_popins_enabled_;
    }

    static bool PartitionedPopinsEnabled(const FeatureContext*)
    {
        return PartitionedPopinsEnabled();
    }

    static bool PartitionVisitedLinkDatabaseWithSelfLinksEnabled()
    {
        return is_partition_visited_link_database_with_self_links_enabled_;
    }

    static bool PartitionVisitedLinkDatabaseWithSelfLinksEnabled(const FeatureContext*)
    {
        return PartitionVisitedLinkDatabaseWithSelfLinksEnabled();
    }

    static bool PasswordRevealEnabled()
    {
        return is_password_reveal_enabled_;
    }

    static bool PasswordRevealEnabled(const FeatureContext*)
    {
        return PasswordRevealEnabled();
    }

    static bool PaymentAppEnabled()
    {
        if (!PaymentRequestEnabled())
            return false;
        return is_payment_app_enabled_;
    }

    static bool PaymentAppEnabled(const FeatureContext*)
    {
        return PaymentAppEnabled();
    }

    static bool PaymentInstrumentsEnabled()
    {
        if (!PaymentAppEnabled())
            return false;
        return is_payment_instruments_enabled_;
    }

    static bool PaymentInstrumentsEnabled(const FeatureContext*)
    {
        return PaymentInstrumentsEnabled();
    }

    static bool PaymentLinkDetectionEnabled()
    {
        return is_payment_link_detection_enabled_;
    }

    static bool PaymentLinkDetectionEnabled(const FeatureContext*)
    {
        return PaymentLinkDetectionEnabled();
    }

    static bool PaymentMethodChangeEventEnabled()
    {
        if (!PaymentRequestEnabled())
            return false;
        return is_payment_method_change_event_enabled_;
    }

    static bool PaymentMethodChangeEventEnabled(const FeatureContext*)
    {
        return PaymentMethodChangeEventEnabled();
    }

    static bool PaymentRequestEnabled()
    {
        return is_payment_request_enabled_;
    }

    static bool PaymentRequestEnabled(const FeatureContext*)
    {
        return PaymentRequestEnabled();
    }

    static bool PercentBasedScrollingEnabled()
    {
        return is_percent_based_scrolling_enabled_;
    }

    static bool PercentBasedScrollingEnabled(const FeatureContext*)
    {
        return PercentBasedScrollingEnabled();
    }

    static bool PerformanceManagerInstrumentationEnabled()
    {
        return is_performance_manager_instrumentation_enabled_;
    }

    static bool PerformanceManagerInstrumentationEnabled(const FeatureContext*)
    {
        return PerformanceManagerInstrumentationEnabled();
    }

    static bool PerformanceMarkFeatureUsageEnabled()
    {
        return is_performance_mark_feature_usage_enabled_;
    }

    static bool PerformanceMarkFeatureUsageEnabled(const FeatureContext*)
    {
        return PerformanceMarkFeatureUsageEnabled();
    }

    static bool PerformanceNavigateSystemEntropyEnabled()
    {
        return is_performance_navigate_system_entropy_enabled_;
    }

    static bool PerformanceNavigateSystemEntropyEnabled(const FeatureContext*)
    {
        return PerformanceNavigateSystemEntropyEnabled();
    }

    static bool PerformanceNavigationTimingConfidenceEnabled()
    {
        return is_performance_navigation_timing_confidence_enabled_;
    }

    static bool PerformanceNavigationTimingConfidenceEnabled(const FeatureContext*)
    {
        return PerformanceNavigationTimingConfidenceEnabled();
    }

    static bool PeriodicBackgroundSyncEnabled()
    {
        return is_periodic_background_sync_enabled_;
    }

    static bool PeriodicBackgroundSyncEnabled(const FeatureContext*)
    {
        return PeriodicBackgroundSyncEnabled();
    }

    static bool PermissionsEnabled()
    {
        return is_permissions_enabled_;
    }

    static bool PermissionsEnabled(const FeatureContext*)
    {
        return PermissionsEnabled();
    }

    static bool PermissionsRequestRevokeEnabled()
    {
        return is_permissions_request_revoke_enabled_;
    }

    static bool PermissionsRequestRevokeEnabled(const FeatureContext*)
    {
        return PermissionsRequestRevokeEnabled();
    }

    static bool PointerEventDeviceIdEnabled()
    {
        return is_pointer_event_device_id_enabled_;
    }

    static bool PointerEventDeviceIdEnabled(const FeatureContext*)
    {
        return PointerEventDeviceIdEnabled();
    }

    static bool PointerEventTargetsInEventListsEnabled()
    {
        return is_pointer_event_targets_in_event_lists_enabled_;
    }

    static bool PointerEventTargetsInEventListsEnabled(const FeatureContext*)
    {
        return PointerEventTargetsInEventListsEnabled();
    }

    static bool PopoverAnchorRelationshipsEnabled()
    {
        return is_popover_anchor_relationships_enabled_;
    }

    static bool PopoverAnchorRelationshipsEnabled(const FeatureContext*)
    {
        return PopoverAnchorRelationshipsEnabled();
    }

    static bool PopoverDialogNewFocusBehaviorEnabled()
    {
        return is_popover_dialog_new_focus_behavior_enabled_;
    }

    static bool PopoverDialogNewFocusBehaviorEnabled(const FeatureContext*)
    {
        return PopoverDialogNewFocusBehaviorEnabled();
    }

    static bool PositionOutsideTabSpanCheckSiblingNodeEnabled()
    {
        return is_position_outside_tab_span_check_sibling_node_enabled_;
    }

    static bool PositionOutsideTabSpanCheckSiblingNodeEnabled(const FeatureContext*)
    {
        return PositionOutsideTabSpanCheckSiblingNodeEnabled();
    }

    static bool PreciseMemoryInfoEnabled()
    {
        return is_precise_memory_info_enabled_;
    }

    static bool PreciseMemoryInfoEnabled(const FeatureContext*)
    {
        return PreciseMemoryInfoEnabled();
    }

    static bool PreferDefaultScrollbarStylesEnabled()
    {
        return is_prefer_default_scrollbar_styles_enabled_;
    }

    static bool PreferDefaultScrollbarStylesEnabled(const FeatureContext*)
    {
        return PreferDefaultScrollbarStylesEnabled();
    }

    static bool PreferNonCompositedScrollingEnabled()
    {
        return is_prefer_non_composited_scrolling_enabled_;
    }

    static bool PreferNonCompositedScrollingEnabled(const FeatureContext*)
    {
        return PreferNonCompositedScrollingEnabled();
    }

    static bool PrefersReducedDataEnabled()
    {
        return is_prefers_reduced_data_enabled_;
    }

    static bool PrefersReducedDataEnabled(const FeatureContext*)
    {
        return PrefersReducedDataEnabled();
    }

    static bool Prerender2Enabled()
    {
        return is_prerender_2_enabled_;
    }

    static bool Prerender2Enabled(const FeatureContext*)
    {
        return Prerender2Enabled();
    }

    static bool PresentationEnabled()
    {
        return is_presentation_enabled_;
    }

    static bool PresentationEnabled(const FeatureContext*)
    {
        return PresentationEnabled();
    }

    static bool PreserveFollowingBlockStylesDuringBlockMergeEnabled()
    {
        return is_preserve_following_block_styles_during_block_merge_enabled_;
    }

    static bool PreserveFollowingBlockStylesDuringBlockMergeEnabled(const FeatureContext*)
    {
        return PreserveFollowingBlockStylesDuringBlockMergeEnabled();
    }

    static bool PreventUndoIfNotEditableEnabled()
    {
        return is_prevent_undo_if_not_editable_enabled_;
    }

    static bool PreventUndoIfNotEditableEnabled(const FeatureContext*)
    {
        return PreventUndoIfNotEditableEnabled();
    }

    static bool PrivateAggregationApiFilteringIdsEnabled()
    {
        return is_private_aggregation_api_filtering_ids_enabled_;
    }

    static bool PrivateAggregationApiFilteringIdsEnabled(const FeatureContext*)
    {
        return PrivateAggregationApiFilteringIdsEnabled();
    }

    static bool PrivateAggregationAuctionReportBuyerDebugModeConfigEnabled()
    {
        return is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_;
    }

    static bool PrivateAggregationAuctionReportBuyerDebugModeConfigEnabled(const FeatureContext*)
    {
        return PrivateAggregationAuctionReportBuyerDebugModeConfigEnabled();
    }

    static bool PrivateNetworkAccessNullIpAddressEnabled()
    {
        return is_private_network_access_null_ip_address_enabled_;
    }

    static bool PrivateNetworkAccessNullIpAddressEnabled(const FeatureContext*)
    {
        return PrivateNetworkAccessNullIpAddressEnabled();
    }

    static bool PrivateStateTokensAlwaysAllowIssuanceEnabled()
    {
        return is_private_state_tokens_always_allow_issuance_enabled_;
    }

    static bool PrivateStateTokensAlwaysAllowIssuanceEnabled(const FeatureContext*)
    {
        return PrivateStateTokensAlwaysAllowIssuanceEnabled();
    }

    static bool PseudoElementsCorrectInGetComputedStyleEnabled()
    {
        return is_pseudo_elements_correct_in_get_computed_style_enabled_;
    }

    static bool PseudoElementsCorrectInGetComputedStyleEnabled(const FeatureContext*)
    {
        return PseudoElementsCorrectInGetComputedStyleEnabled();
    }

    static bool PseudoElementsFocusableEnabled()
    {
        return is_pseudo_elements_focusable_enabled_;
    }

    static bool PseudoElementsFocusableEnabled(const FeatureContext*)
    {
        return PseudoElementsFocusableEnabled();
    }

    static bool PushMessageDataBytesEnabled()
    {
        if (!PushMessagingEnabled())
            return false;
        return is_push_message_data_bytes_enabled_;
    }

    static bool PushMessageDataBytesEnabled(const FeatureContext*)
    {
        return PushMessageDataBytesEnabled();
    }

    static bool PushMessagingEnabled()
    {
        return is_push_messaging_enabled_;
    }

    static bool PushMessagingEnabled(const FeatureContext*)
    {
        return PushMessagingEnabled();
    }

    static bool PushMessagingSubscriptionChangeEnabled()
    {
        return is_push_messaging_subscription_change_enabled_;
    }

    static bool PushMessagingSubscriptionChangeEnabled(const FeatureContext*)
    {
        return PushMessagingSubscriptionChangeEnabled();
    }

    static bool QuickIntensiveWakeUpThrottlingAfterLoadingEnabled()
    {
        return is_quick_intensive_wake_up_throttling_after_loading_enabled_;
    }

    static bool QuickIntensiveWakeUpThrottlingAfterLoadingEnabled(const FeatureContext*)
    {
        return QuickIntensiveWakeUpThrottlingAfterLoadingEnabled();
    }

    static bool RasterInducingScrollEnabled()
    {
        return is_raster_inducing_scroll_enabled_;
    }

    static bool RasterInducingScrollEnabled(const FeatureContext*)
    {
        return RasterInducingScrollEnabled();
    }

    static bool ReadableStreamAsyncIterableEnabled()
    {
        return is_readable_stream_async_iterable_enabled_;
    }

    static bool ReadableStreamAsyncIterableEnabled(const FeatureContext*)
    {
        return ReadableStreamAsyncIterableEnabled();
    }

    static bool ReduceCookieIPCsEnabled()
    {
        return is_reduce_cookie_ip_cs_enabled_;
    }

    static bool ReduceCookieIPCsEnabled(const FeatureContext*)
    {
        return ReduceCookieIPCsEnabled();
    }

    static bool ReduceUserAgentAndroidVersionDeviceModelEnabled()
    {
        if (!ReduceUserAgentMinorVersionEnabled())
            return false;
        return is_reduce_user_agent_android_version_device_model_enabled_;
    }

    static bool ReduceUserAgentAndroidVersionDeviceModelEnabled(const FeatureContext*)
    {
        return ReduceUserAgentAndroidVersionDeviceModelEnabled();
    }

    static bool ReduceUserAgentMinorVersionEnabled()
    {
        return is_reduce_user_agent_minor_version_enabled_;
    }

    static bool ReduceUserAgentMinorVersionEnabled(const FeatureContext*)
    {
        return ReduceUserAgentMinorVersionEnabled();
    }

    static bool ReduceUserAgentPlatformOsCpuEnabled()
    {
        if (!ReduceUserAgentMinorVersionEnabled())
            return false;
        return is_reduce_user_agent_platform_os_cpu_enabled_;
    }

    static bool ReduceUserAgentPlatformOsCpuEnabled(const FeatureContext*)
    {
        return ReduceUserAgentPlatformOsCpuEnabled();
    }

    static bool RegionCaptureEnabled()
    {
        return is_region_capture_enabled_;
    }

    static bool RegionCaptureEnabled(const FeatureContext*)
    {
        return RegionCaptureEnabled();
    }

    static bool RelOpenerBcgDependencyHintEnabled()
    {
        return is_rel_opener_bcg_dependency_hint_enabled_;
    }

    static bool RelOpenerBcgDependencyHintEnabled(const FeatureContext*)
    {
        return RelOpenerBcgDependencyHintEnabled();
    }

    static bool RemotePlaybackEnabled()
    {
        return is_remote_playback_enabled_;
    }

    static bool RemotePlaybackEnabled(const FeatureContext*)
    {
        return RemotePlaybackEnabled();
    }

    static bool RemotePlaybackBackendEnabled()
    {
        return is_remote_playback_backend_enabled_;
    }

    static bool RemotePlaybackBackendEnabled(const FeatureContext*)
    {
        return RemotePlaybackBackendEnabled();
    }

    static bool RemoveCollapsedPlaceholderEnabled()
    {
        return is_remove_collapsed_placeholder_enabled_;
    }

    static bool RemoveCollapsedPlaceholderEnabled(const FeatureContext*)
    {
        return RemoveCollapsedPlaceholderEnabled();
    }

    static bool RemoveDanglingMarkupInTargetEnabled()
    {
        return is_remove_dangling_markup_in_target_enabled_;
    }

    static bool RemoveDanglingMarkupInTargetEnabled(const FeatureContext*)
    {
        return RemoveDanglingMarkupInTargetEnabled();
    }

    static bool RemoveDataUrlInSvgUseEnabled()
    {
        return is_remove_data_url_in_svg_use_enabled_;
    }

    static bool RemoveDataUrlInSvgUseEnabled(const FeatureContext*)
    {
        return RemoveDataUrlInSvgUseEnabled();
    }

    static bool RemoveNodeHavingChildrenIfFullySelectedEnabled()
    {
        return is_remove_node_having_children_if_fully_selected_enabled_;
    }

    static bool RemoveNodeHavingChildrenIfFullySelectedEnabled(const FeatureContext*)
    {
        return RemoveNodeHavingChildrenIfFullySelectedEnabled();
    }

    static bool RemoveVisibleSelectionInDOMSelectionEnabled()
    {
        return is_remove_visible_selection_in_dom_selection_enabled_;
    }

    static bool RemoveVisibleSelectionInDOMSelectionEnabled(const FeatureContext*)
    {
        return RemoveVisibleSelectionInDOMSelectionEnabled();
    }

    static bool RenderBlockingInlineModuleScriptEnabled()
    {
        return is_render_blocking_inline_module_script_enabled_;
    }

    static bool RenderBlockingInlineModuleScriptEnabled(const FeatureContext*)
    {
        return RenderBlockingInlineModuleScriptEnabled();
    }

    static bool RenderBlockingStatusEnabled()
    {
        return is_render_blocking_status_enabled_;
    }

    static bool RenderBlockingStatusEnabled(const FeatureContext*)
    {
        return RenderBlockingStatusEnabled();
    }

    static bool RenderPriorityAttributeEnabled()
    {
        return is_render_priority_attribute_enabled_;
    }

    static bool RenderPriorityAttributeEnabled(const FeatureContext*)
    {
        return RenderPriorityAttributeEnabled();
    }

    static bool ReportEventTimingAtVisibilityChangeEnabled()
    {
        return is_report_event_timing_at_visibility_change_enabled_;
    }

    static bool ReportEventTimingAtVisibilityChangeEnabled(const FeatureContext*)
    {
        return ReportEventTimingAtVisibilityChangeEnabled();
    }

    static bool ReportVisibleLineBoundsEnabled()
    {
        return is_report_visible_line_bounds_enabled_;
    }

    static bool ReportVisibleLineBoundsEnabled(const FeatureContext*)
    {
        return ReportVisibleLineBoundsEnabled();
    }

    static bool ResetInputTypeToNoneBeforeCharacterInputEnabled()
    {
        return is_reset_input_type_to_none_before_character_input_enabled_;
    }

    static bool ResetInputTypeToNoneBeforeCharacterInputEnabled(const FeatureContext*)
    {
        return ResetInputTypeToNoneBeforeCharacterInputEnabled();
    }

    static bool ResourceTimingContentTypeEnabled()
    {
        return is_resource_timing_content_type_enabled_;
    }

    static bool ResourceTimingContentTypeEnabled(const FeatureContext*)
    {
        return ResourceTimingContentTypeEnabled();
    }

    static bool ResourceTimingFinalResponseHeadersStartEnabled()
    {
        return is_resource_timing_final_response_headers_start_enabled_;
    }

    static bool ResourceTimingFinalResponseHeadersStartEnabled(const FeatureContext*)
    {
        return ResourceTimingFinalResponseHeadersStartEnabled();
    }

    static bool ResourceTimingUseCORSForBodySizesEnabled()
    {
        return is_resource_timing_use_cors_for_body_sizes_enabled_;
    }

    static bool ResourceTimingUseCORSForBodySizesEnabled(const FeatureContext*)
    {
        return ResourceTimingUseCORSForBodySizesEnabled();
    }

    static bool RestrictGamepadAccessEnabled()
    {
        return is_restrict_gamepad_access_enabled_;
    }

    static bool RestrictGamepadAccessEnabled(const FeatureContext*)
    {
        return RestrictGamepadAccessEnabled();
    }

    static bool ReuseShapeResultsByFontsEnabled()
    {
        return is_reuse_shape_results_by_fonts_enabled_;
    }

    static bool ReuseShapeResultsByFontsEnabled(const FeatureContext*)
    {
        return ReuseShapeResultsByFontsEnabled();
    }

    static bool RewindFloatsEnabled()
    {
        return is_rewind_floats_enabled_;
    }

    static bool RewindFloatsEnabled(const FeatureContext*)
    {
        return RewindFloatsEnabled();
    }

    static bool RootElementWithPlaceHolderAfterDeletingSelectionEnabled()
    {
        return is_root_element_with_place_holder_after_deleting_selection_enabled_;
    }

    static bool RootElementWithPlaceHolderAfterDeletingSelectionEnabled(const FeatureContext*)
    {
        return RootElementWithPlaceHolderAfterDeletingSelectionEnabled();
    }

    static bool RTCDataChannelPriorityEnabled()
    {
        return is_rtc_data_channel_priority_enabled_;
    }

    static bool RTCDataChannelPriorityEnabled(const FeatureContext*)
    {
        return RTCDataChannelPriorityEnabled();
    }

    static bool RTCEncodedAudioFrameAbsCaptureTimeEnabled()
    {
        return is_rtc_encoded_audio_frame_abs_capture_time_enabled_;
    }

    static bool RTCEncodedAudioFrameAbsCaptureTimeEnabled(const FeatureContext*)
    {
        return RTCEncodedAudioFrameAbsCaptureTimeEnabled();
    }

    static bool RTCEncodedVideoFrameAdditionalMetadataEnabled()
    {
        return is_rtc_encoded_video_frame_additional_metadata_enabled_;
    }

    static bool RTCEncodedVideoFrameAdditionalMetadataEnabled(const FeatureContext*)
    {
        return RTCEncodedVideoFrameAdditionalMetadataEnabled();
    }

    static bool RTCJitterBufferTargetEnabled()
    {
        return is_rtc_jitter_buffer_target_enabled_;
    }

    static bool RTCJitterBufferTargetEnabled(const FeatureContext*)
    {
        return RTCJitterBufferTargetEnabled();
    }

    static bool RTCRtpEncodingParametersCodecEnabled()
    {
        return is_rtc_rtp_encoding_parameters_codec_enabled_;
    }

    static bool RTCRtpEncodingParametersCodecEnabled(const FeatureContext*)
    {
        return RTCRtpEncodingParametersCodecEnabled();
    }

    static bool RTCRtpScaleResolutionDownToEnabled()
    {
        return is_rtc_rtp_scale_resolution_down_to_enabled_;
    }

    static bool RTCRtpScaleResolutionDownToEnabled(const FeatureContext*)
    {
        return RTCRtpScaleResolutionDownToEnabled();
    }

    static bool RTCRtpScriptTransformEnabled()
    {
        return is_rtc_rtp_script_transform_enabled_;
    }

    static bool RTCRtpScriptTransformEnabled(const FeatureContext*)
    {
        return RTCRtpScriptTransformEnabled();
    }

    static bool RTCRtpTransportEnabled()
    {
        return is_rtc_rtp_transport_enabled_;
    }

    static bool RTCRtpTransportEnabled(const FeatureContext*)
    {
        return RTCRtpTransportEnabled();
    }

    static bool RTCSvcScalabilityModeEnabled()
    {
        return is_rtc_svc_scalability_mode_enabled_;
    }

    static bool RTCSvcScalabilityModeEnabled(const FeatureContext*)
    {
        return RTCSvcScalabilityModeEnabled();
    }

    static bool RubyShortHeuristicsEnabled()
    {
        return is_ruby_short_heuristics_enabled_;
    }

    static bool RubyShortHeuristicsEnabled(const FeatureContext*)
    {
        return RubyShortHeuristicsEnabled();
    }

    static bool SanitizerAPIEnabled()
    {
        return is_sanitizer_api_enabled_;
    }

    static bool SanitizerAPIEnabled(const FeatureContext*)
    {
        return SanitizerAPIEnabled();
    }

    static bool SchedulerYieldEnabled()
    {
        return is_scheduler_yield_enabled_;
    }

    static bool SchedulerYieldEnabled(const FeatureContext*)
    {
        return SchedulerYieldEnabled();
    }

    static bool ScheduleSelectionChangeOnBackspaceEnabled()
    {
        return is_schedule_selection_change_on_backspace_enabled_;
    }

    static bool ScheduleSelectionChangeOnBackspaceEnabled(const FeatureContext*)
    {
        return ScheduleSelectionChangeOnBackspaceEnabled();
    }

    static bool ScopedCustomElementRegistryEnabled()
    {
        return is_scoped_custom_element_registry_enabled_;
    }

    static bool ScopedCustomElementRegistryEnabled(const FeatureContext*)
    {
        return ScopedCustomElementRegistryEnabled();
    }

    static bool ScriptedSpeechRecognitionEnabled()
    {
        return is_scripted_speech_recognition_enabled_;
    }

    static bool ScriptedSpeechRecognitionEnabled(const FeatureContext*)
    {
        return ScriptedSpeechRecognitionEnabled();
    }

    static bool ScriptedSpeechSynthesisEnabled()
    {
        return is_scripted_speech_synthesis_enabled_;
    }

    static bool ScriptedSpeechSynthesisEnabled(const FeatureContext*)
    {
        return ScriptedSpeechSynthesisEnabled();
    }

    static bool ScrollbarColorEnabled()
    {
        return is_scrollbar_color_enabled_;
    }

    static bool ScrollbarColorEnabled(const FeatureContext*)
    {
        return ScrollbarColorEnabled();
    }

    static bool ScrollbarWidthEnabled()
    {
        return is_scrollbar_width_enabled_;
    }

    static bool ScrollbarWidthEnabled(const FeatureContext*)
    {
        return ScrollbarWidthEnabled();
    }

    static bool ScrollEndEventsEnabled()
    {
        return is_scroll_end_events_enabled_;
    }

    static bool ScrollEndEventsEnabled(const FeatureContext*)
    {
        return ScrollEndEventsEnabled();
    }

    static bool ScrollIntoViewRootFrameViewportBugFixEnabled()
    {
        return is_scroll_into_view_root_frame_viewport_bug_fix_enabled_;
    }

    static bool ScrollIntoViewRootFrameViewportBugFixEnabled(const FeatureContext*)
    {
        return ScrollIntoViewRootFrameViewportBugFixEnabled();
    }

    static bool ScrollTimelineEnabled()
    {
        if (AnimationWorkletEnabled())
            return true;
        if (ScrollTimelineCurrentTimeEnabled())
            return true;
        return is_scroll_timeline_enabled_;
    }

    static bool ScrollTimelineEnabled(const FeatureContext*)
    {
        return ScrollTimelineEnabled();
    }

    static bool ScrollTimelineCurrentTimeEnabled()
    {
        return is_scroll_timeline_current_time_enabled_;
    }

    static bool ScrollTimelineCurrentTimeEnabled(const FeatureContext*)
    {
        return ScrollTimelineCurrentTimeEnabled();
    }

    static bool ScrollTopLeftInteropEnabled()
    {
        return is_scroll_top_left_interop_enabled_;
    }

    static bool ScrollTopLeftInteropEnabled(const FeatureContext*)
    {
        return ScrollTopLeftInteropEnabled();
    }

    static bool SearchTextHighlightPseudoEnabled()
    {
        return is_search_text_highlight_pseudo_enabled_;
    }

    static bool SearchTextHighlightPseudoEnabled(const FeatureContext*)
    {
        return SearchTextHighlightPseudoEnabled();
    }

    static bool SecurePaymentConfirmationEnabled()
    {
        return is_secure_payment_confirmation_enabled_;
    }

    static bool SecurePaymentConfirmationEnabled(const FeatureContext*)
    {
        return SecurePaymentConfirmationEnabled();
    }

    static bool SecurePaymentConfirmationDebugEnabled()
    {
        return is_secure_payment_confirmation_debug_enabled_;
    }

    static bool SecurePaymentConfirmationDebugEnabled(const FeatureContext*)
    {
        return SecurePaymentConfirmationDebugEnabled();
    }

    static bool SecurePaymentConfirmationNetworkAndIssuerIconsEnabled()
    {
        return is_secure_payment_confirmation_network_and_issuer_icons_enabled_;
    }

    static bool SecurePaymentConfirmationNetworkAndIssuerIconsEnabled(const FeatureContext*)
    {
        return SecurePaymentConfirmationNetworkAndIssuerIconsEnabled();
    }

    static bool SelectAudioOutputEnabled()
    {
        return is_select_audio_output_enabled_;
    }

    static bool SelectAudioOutputEnabled(const FeatureContext*)
    {
        return SelectAudioOutputEnabled();
    }

    static bool SelectedcontentelementAttributeEnabled()
    {
        if (!CustomizableSelectEnabled())
            return false;
        return is_selectedcontentelement_attribute_enabled_;
    }

    static bool SelectedcontentelementAttributeEnabled(const FeatureContext*)
    {
        return SelectedcontentelementAttributeEnabled();
    }

    static bool SelectionAcrossShadowDOMEnabled()
    {
        return is_selection_across_shadow_dom_enabled_;
    }

    static bool SelectionAcrossShadowDOMEnabled(const FeatureContext*)
    {
        return SelectionAcrossShadowDOMEnabled();
    }

    static bool SelectionIsCollapsedShadowDOMSupportEnabled()
    {
        return is_selection_is_collapsed_shadow_dom_support_enabled_;
    }

    static bool SelectionIsCollapsedShadowDOMSupportEnabled(const FeatureContext*)
    {
        return SelectionIsCollapsedShadowDOMSupportEnabled();
    }

    static bool SelectionOnShadowDOMWithDelegatesFocusEnabled()
    {
        return is_selection_on_shadow_dom_with_delegates_focus_enabled_;
    }

    static bool SelectionOnShadowDOMWithDelegatesFocusEnabled(const FeatureContext*)
    {
        return SelectionOnShadowDOMWithDelegatesFocusEnabled();
    }

    static bool SelectOptionAccessibilityTargetSizeEnabled()
    {
        return is_select_option_accessibility_target_size_enabled_;
    }

    static bool SelectOptionAccessibilityTargetSizeEnabled(const FeatureContext*)
    {
        return SelectOptionAccessibilityTargetSizeEnabled();
    }

    static bool SelectParserRelaxationEnabled()
    {
        return is_select_parser_relaxation_enabled_;
    }

    static bool SelectParserRelaxationEnabled(const FeatureContext*)
    {
        return SelectParserRelaxationEnabled();
    }

    static bool SelectPopupLessUpdatesEnabled()
    {
        return is_select_popup_less_updates_enabled_;
    }

    static bool SelectPopupLessUpdatesEnabled(const FeatureContext*)
    {
        return SelectPopupLessUpdatesEnabled();
    }

    static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled()
    {
        return is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
    }

    static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled(const FeatureContext*)
    {
        return SendBeaconThrowForBlobWithNonSimpleTypeEnabled();
    }

    static bool SensorExtraClassesEnabled()
    {
        return is_sensor_extra_classes_enabled_;
    }

    static bool SensorExtraClassesEnabled(const FeatureContext*)
    {
        return SensorExtraClassesEnabled();
    }

    static bool SerialEnabled()
    {
        return is_serial_enabled_;
    }

    static bool SerialEnabled(const FeatureContext*)
    {
        return SerialEnabled();
    }

    static bool SerializeViewTransitionStateInSPAEnabled()
    {
        return is_serialize_view_transition_state_in_spa_enabled_;
    }

    static bool SerializeViewTransitionStateInSPAEnabled(const FeatureContext*)
    {
        return SerializeViewTransitionStateInSPAEnabled();
    }

    static bool SerialPortConnectedEnabled()
    {
        return is_serial_port_connected_enabled_;
    }

    static bool SerialPortConnectedEnabled(const FeatureContext*)
    {
        return SerialPortConnectedEnabled();
    }

    static bool ServiceWorkerClientLifecycleStateEnabled()
    {
        return is_service_worker_client_lifecycle_state_enabled_;
    }

    static bool ServiceWorkerClientLifecycleStateEnabled(const FeatureContext*)
    {
        return ServiceWorkerClientLifecycleStateEnabled();
    }

    static bool SetSequentialFocusStartingPointEnabled()
    {
        return is_set_sequential_focus_starting_point_enabled_;
    }

    static bool SetSequentialFocusStartingPointEnabled(const FeatureContext*)
    {
        return SetSequentialFocusStartingPointEnabled();
    }

    static bool ShadowRootReferenceTargetEnabled()
    {
        return is_shadow_root_reference_target_enabled_;
    }

    static bool ShadowRootReferenceTargetEnabled(const FeatureContext*)
    {
        return ShadowRootReferenceTargetEnabled();
    }

    static bool ShapeOutsideWritingModeFixEnabled()
    {
        return is_shape_outside_writing_mode_fix_enabled_;
    }

    static bool ShapeOutsideWritingModeFixEnabled(const FeatureContext*)
    {
        return ShapeOutsideWritingModeFixEnabled();
    }

    static bool ShapeResultCachedPreviousSafeToBreakOffsetEnabled()
    {
        return is_shape_result_cached_previous_safe_to_break_offset_enabled_;
    }

    static bool ShapeResultCachedPreviousSafeToBreakOffsetEnabled(const FeatureContext*)
    {
        return ShapeResultCachedPreviousSafeToBreakOffsetEnabled();
    }

    static bool SharedArrayBufferEnabled()
    {
        return is_shared_array_buffer_enabled_;
    }

    static bool SharedArrayBufferEnabled(const FeatureContext*)
    {
        return SharedArrayBufferEnabled();
    }

    static bool SharedArrayBufferOnDesktopEnabled()
    {
        return is_shared_array_buffer_on_desktop_enabled_;
    }

    static bool SharedArrayBufferOnDesktopEnabled(const FeatureContext*)
    {
        return SharedArrayBufferOnDesktopEnabled();
    }

    static bool SharedArrayBufferUnrestrictedAccessAllowedEnabled()
    {
        return is_shared_array_buffer_unrestricted_access_allowed_enabled_;
    }

    static bool SharedArrayBufferUnrestrictedAccessAllowedEnabled(const FeatureContext*)
    {
        return SharedArrayBufferUnrestrictedAccessAllowedEnabled();
    }

    static bool SharedAutofillEnabled()
    {
        return is_shared_autofill_enabled_;
    }

    static bool SharedAutofillEnabled(const FeatureContext*)
    {
        return SharedAutofillEnabled();
    }

    static bool SharedStorageAPIEnabled()
    {
        return is_shared_storage_api_enabled_;
    }

    static bool SharedStorageAPIEnabled(const FeatureContext*)
    {
        return SharedStorageAPIEnabled();
    }

    static bool SharedStorageAPIM118Enabled()
    {
        return is_shared_storage_api_m_118_enabled_;
    }

    static bool SharedStorageAPIM118Enabled(const FeatureContext*)
    {
        return SharedStorageAPIM118Enabled();
    }

    static bool SharedStorageAPIM125Enabled()
    {
        return is_shared_storage_api_m_125_enabled_;
    }

    static bool SharedStorageAPIM125Enabled(const FeatureContext*)
    {
        return SharedStorageAPIM125Enabled();
    }

    static bool SharedStorageWebLocksEnabled()
    {
        return is_shared_storage_web_locks_enabled_;
    }

    static bool SharedStorageWebLocksEnabled(const FeatureContext*)
    {
        return SharedStorageWebLocksEnabled();
    }

    static bool SharedWorkerEnabled()
    {
        return is_shared_worker_enabled_;
    }

    static bool SharedWorkerEnabled(const FeatureContext*)
    {
        return SharedWorkerEnabled();
    }

    static bool SidewaysWritingModesEnabled()
    {
        return is_sideways_writing_modes_enabled_;
    }

    static bool SidewaysWritingModesEnabled(const FeatureContext*)
    {
        return SidewaysWritingModesEnabled();
    }

    static bool SiteInitiatedMirroringEnabled()
    {
        return is_site_initiated_mirroring_enabled_;
    }

    static bool SiteInitiatedMirroringEnabled(const FeatureContext*)
    {
        return SiteInitiatedMirroringEnabled();
    }

    static bool SkipAdEnabled()
    {
        if (!MediaSessionEnabled())
            return false;
        return is_skip_ad_enabled_;
    }

    static bool SkipAdEnabled(const FeatureContext*)
    {
        return SkipAdEnabled();
    }

    static bool SkipTemporaryDocumentFragmentEnabled()
    {
        return is_skip_temporary_document_fragment_enabled_;
    }

    static bool SkipTemporaryDocumentFragmentEnabled(const FeatureContext*)
    {
        return SkipTemporaryDocumentFragmentEnabled();
    }

    static bool SkipTouchEventFilterEnabled()
    {
        return is_skip_touch_event_filter_enabled_;
    }

    static bool SkipTouchEventFilterEnabled(const FeatureContext*)
    {
        return SkipTouchEventFilterEnabled();
    }

    static bool SmartCardEnabled()
    {
        return is_smart_card_enabled_;
    }

    static bool SmartCardEnabled(const FeatureContext*)
    {
        return SmartCardEnabled();
    }

    static bool SmartZoomEnabled()
    {
        return is_smart_zoom_enabled_;
    }

    static bool SmartZoomEnabled(const FeatureContext*)
    {
        return SmartZoomEnabled();
    }

    static bool SmilAutoSuspendOnLagEnabled()
    {
        return is_smil_auto_suspend_on_lag_enabled_;
    }

    static bool SmilAutoSuspendOnLagEnabled(const FeatureContext*)
    {
        return SmilAutoSuspendOnLagEnabled();
    }

    static bool SoftNavigationDetectionEnabled()
    {
        return is_soft_navigation_detection_enabled_;
    }

    static bool SoftNavigationDetectionEnabled(const FeatureContext*)
    {
        return SoftNavigationDetectionEnabled();
    }

    static bool SoftNavigationHeuristicsExposeFPAndFCPEnabled()
    {
        return is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_;
    }

    static bool SoftNavigationHeuristicsExposeFPAndFCPEnabled(const FeatureContext*)
    {
        return SoftNavigationHeuristicsExposeFPAndFCPEnabled();
    }

    static bool SpeakerSelectionEnabled()
    {
        return is_speaker_selection_enabled_;
    }

    static bool SpeakerSelectionEnabled(const FeatureContext*)
    {
        return SpeakerSelectionEnabled();
    }

    static bool SpeculationRulesPointerDownHeuristicsEnabled()
    {
        return is_speculation_rules_pointer_down_heuristics_enabled_;
    }

    static bool SpeculationRulesPointerDownHeuristicsEnabled(const FeatureContext*)
    {
        return SpeculationRulesPointerDownHeuristicsEnabled();
    }

    static bool SpeculationRulesPointerHoverHeuristicsEnabled()
    {
        return is_speculation_rules_pointer_hover_heuristics_enabled_;
    }

    static bool SpeculationRulesPointerHoverHeuristicsEnabled(const FeatureContext*)
    {
        return SpeculationRulesPointerHoverHeuristicsEnabled();
    }

    static bool SpeculationRulesPrefetchWithSubresourcesEnabled()
    {
        return is_speculation_rules_prefetch_with_subresources_enabled_;
    }

    static bool SpeculationRulesPrefetchWithSubresourcesEnabled(const FeatureContext*)
    {
        return SpeculationRulesPrefetchWithSubresourcesEnabled();
    }

    static bool SrcsetMaxDensityEnabled()
    {
        return is_srcset_max_density_enabled_;
    }

    static bool SrcsetMaxDensityEnabled(const FeatureContext*)
    {
        return SrcsetMaxDensityEnabled();
    }

    static bool StableBlinkFeaturesEnabled()
    {
        return is_stable_blink_features_enabled_;
    }

    static bool StableBlinkFeaturesEnabled(const FeatureContext*)
    {
        return StableBlinkFeaturesEnabled();
    }

    static bool StandardizedBrowserZoomEnabled()
    {
        return is_standardized_browser_zoom_enabled_;
    }

    static bool StandardizedBrowserZoomEnabled(const FeatureContext*)
    {
        return StandardizedBrowserZoomEnabled();
    }

    static bool StaticAnimationOptimizationEnabled()
    {
        return is_static_animation_optimization_enabled_;
    }

    static bool StaticAnimationOptimizationEnabled(const FeatureContext*)
    {
        return StaticAnimationOptimizationEnabled();
    }

    static bool StorageBucketsEnabled()
    {
        return is_storage_buckets_enabled_;
    }

    static bool StorageBucketsEnabled(const FeatureContext*)
    {
        return StorageBucketsEnabled();
    }

    static bool StorageBucketsDurabilityEnabled()
    {
        return is_storage_buckets_durability_enabled_;
    }

    static bool StorageBucketsDurabilityEnabled(const FeatureContext*)
    {
        return StorageBucketsDurabilityEnabled();
    }

    static bool StorageBucketsLocksEnabled()
    {
        return is_storage_buckets_locks_enabled_;
    }

    static bool StorageBucketsLocksEnabled(const FeatureContext*)
    {
        return StorageBucketsLocksEnabled();
    }

    static bool StricterCellWidthContentSizeQuirkEnabled()
    {
        return is_stricter_cell_width_content_size_quirk_enabled_;
    }

    static bool StricterCellWidthContentSizeQuirkEnabled(const FeatureContext*)
    {
        return StricterCellWidthContentSizeQuirkEnabled();
    }

    static bool StrictMimeTypesForWorkersEnabled()
    {
        return is_strict_mime_types_for_workers_enabled_;
    }

    static bool StrictMimeTypesForWorkersEnabled(const FeatureContext*)
    {
        return StrictMimeTypesForWorkersEnabled();
    }

    static bool StylusHandwritingEnabled()
    {
        return is_stylus_handwriting_enabled_;
    }

    static bool StylusHandwritingEnabled(const FeatureContext*)
    {
        return StylusHandwritingEnabled();
    }

    static bool SvgContextPaintEnabled()
    {
        return is_svg_context_paint_enabled_;
    }

    static bool SvgContextPaintEnabled(const FeatureContext*)
    {
        return SvgContextPaintEnabled();
    }

    static bool SvgCrossOriginAttributeEnabled()
    {
        return is_svg_cross_origin_attribute_enabled_;
    }

    static bool SvgCrossOriginAttributeEnabled(const FeatureContext*)
    {
        return SvgCrossOriginAttributeEnabled();
    }

    static bool SvgEagerPresAttrStyleUpdateEnabled()
    {
        return is_svg_eager_pres_attr_style_update_enabled_;
    }

    static bool SvgEagerPresAttrStyleUpdateEnabled(const FeatureContext*)
    {
        return SvgEagerPresAttrStyleUpdateEnabled();
    }

    static bool SvgExternalResourcesEnabled()
    {
        return is_svg_external_resources_enabled_;
    }

    static bool SvgExternalResourcesEnabled(const FeatureContext*)
    {
        return SvgExternalResourcesEnabled();
    }

    static bool SvgFilterUserSpaceViewportForNonSvgEnabled()
    {
        return is_svg_filter_user_space_viewport_for_non_svg_enabled_;
    }

    static bool SvgFilterUserSpaceViewportForNonSvgEnabled(const FeatureContext*)
    {
        return SvgFilterUserSpaceViewportForNonSvgEnabled();
    }

    static bool SvgGradientColorInterpolationLinearRgbSupportEnabled()
    {
        return is_svg_gradient_color_interpolation_linear_rgb_support_enabled_;
    }

    static bool SvgGradientColorInterpolationLinearRgbSupportEnabled(const FeatureContext*)
    {
        return SvgGradientColorInterpolationLinearRgbSupportEnabled();
    }

    static bool SvgInlineRootPixelSnappingScaleAdjustmentEnabled()
    {
        return is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_;
    }

    static bool SvgInlineRootPixelSnappingScaleAdjustmentEnabled(const FeatureContext*)
    {
        return SvgInlineRootPixelSnappingScaleAdjustmentEnabled();
    }

    static bool SvgNoPixelSnappingScaleAdjustmentEnabled()
    {
        return is_svg_no_pixel_snapping_scale_adjustment_enabled_;
    }

    static bool SvgNoPixelSnappingScaleAdjustmentEnabled(const FeatureContext*)
    {
        return SvgNoPixelSnappingScaleAdjustmentEnabled();
    }

    static bool SvgTransformOptimizationEnabled()
    {
        return is_svg_transform_optimization_enabled_;
    }

    static bool SvgTransformOptimizationEnabled(const FeatureContext*)
    {
        return SvgTransformOptimizationEnabled();
    }

    static bool SynthesizedKeyboardEventsForAccessibilityActionsEnabled()
    {
        return is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
    }

    static bool SynthesizedKeyboardEventsForAccessibilityActionsEnabled(const FeatureContext*)
    {
        return SynthesizedKeyboardEventsForAccessibilityActionsEnabled();
    }

    static bool SystemFallbackEmojiVSSupportEnabled()
    {
        return is_system_fallback_emoji_vs_support_enabled_;
    }

    static bool SystemFallbackEmojiVSSupportEnabled(const FeatureContext*)
    {
        return SystemFallbackEmojiVSSupportEnabled();
    }

    static bool SystemWakeLockEnabled()
    {
        return is_system_wake_lock_enabled_;
    }

    static bool SystemWakeLockEnabled(const FeatureContext*)
    {
        return SystemWakeLockEnabled();
    }

    static bool TestBlinkFeatureDefaultEnabled()
    {
        return is_test_blink_feature_default_enabled_;
    }

    static bool TestBlinkFeatureDefaultEnabled(const FeatureContext*)
    {
        return TestBlinkFeatureDefaultEnabled();
    }

    static bool TestFeatureEnabled()
    {
        return is_test_feature_enabled_;
    }

    static bool TestFeatureEnabled(const FeatureContext*);

    static bool TestFeatureDependentEnabled()
    {
        if (!TestFeatureImpliedEnabled())
            return false;
        return is_test_feature_dependent_enabled_;
    }

    static bool TestFeatureDependentEnabled(const FeatureContext*)
    {
        return TestFeatureDependentEnabled();
    }

    static bool TestFeatureImpliedEnabled()
    {
        if (TestFeatureEnabled())
            return true;
        return is_test_feature_implied_enabled_;
    }

    static bool TestFeatureImpliedEnabled(const FeatureContext*)
    {
        return TestFeatureImpliedEnabled();
    }

    static bool TestFeatureProtectedEnabled()
    {
        return get_is_test_feature_protected_enabled_();
    }

    static bool TestFeatureProtectedEnabled(const FeatureContext*)
    {
        return TestFeatureProtectedEnabled();
    }

    static bool TestFeatureProtectedDependentEnabled()
    {
        if (!TestFeatureProtectedImpliedEnabled())
            return false;
        return get_is_test_feature_protected_dependent_enabled_();
    }

    static bool TestFeatureProtectedDependentEnabled(const FeatureContext*)
    {
        return TestFeatureProtectedDependentEnabled();
    }

    static bool TestFeatureProtectedImpliedEnabled()
    {
        if (TestFeatureProtectedEnabled())
            return true;
        return get_is_test_feature_protected_implied_enabled_();
    }

    static bool TestFeatureProtectedImpliedEnabled(const FeatureContext*)
    {
        return TestFeatureProtectedImpliedEnabled();
    }

    static bool TestFeatureStableEnabled()
    {
        return is_test_feature_stable_enabled_;
    }

    static bool TestFeatureStableEnabled(const FeatureContext*)
    {
        return TestFeatureStableEnabled();
    }

    static bool TextDetectorEnabled()
    {
        return is_text_detector_enabled_;
    }

    static bool TextDetectorEnabled(const FeatureContext*)
    {
        return TextDetectorEnabled();
    }

    static bool TextDiffSplitFixEnabled()
    {
        return is_text_diff_split_fix_enabled_;
    }

    static bool TextDiffSplitFixEnabled(const FeatureContext*)
    {
        return TextDiffSplitFixEnabled();
    }

    static bool TextFragmentAPIEnabled()
    {
        return is_text_fragment_api_enabled_;
    }

    static bool TextFragmentAPIEnabled(const FeatureContext*)
    {
        return TextFragmentAPIEnabled();
    }

    static bool TextFragmentTapOpensContextMenuEnabled()
    {
        return is_text_fragment_tap_opens_context_menu_enabled_;
    }

    static bool TextFragmentTapOpensContextMenuEnabled(const FeatureContext*)
    {
        return TextFragmentTapOpensContextMenuEnabled();
    }

    static bool TextInputNotAlwaysDirAutoEnabled()
    {
        return is_text_input_not_always_dir_auto_enabled_;
    }

    static bool TextInputNotAlwaysDirAutoEnabled(const FeatureContext*)
    {
        return TextInputNotAlwaysDirAutoEnabled();
    }

    static bool TextMetricsBaselinesEnabled()
    {
        return is_text_metrics_baselines_enabled_;
    }

    static bool TextMetricsBaselinesEnabled(const FeatureContext*)
    {
        return TextMetricsBaselinesEnabled();
    }

    static bool TextSegmentBoundaryForElementWithFloatStyleEnabled()
    {
        return is_text_segment_boundary_for_element_with_float_style_enabled_;
    }

    static bool TextSegmentBoundaryForElementWithFloatStyleEnabled(const FeatureContext*)
    {
        return TextSegmentBoundaryForElementWithFloatStyleEnabled();
    }

    static bool TextSizeAdjustImprovementsEnabled()
    {
        return is_text_size_adjust_improvements_enabled_;
    }

    static bool TextSizeAdjustImprovementsEnabled(const FeatureContext*)
    {
        return TextSizeAdjustImprovementsEnabled();
    }

    static bool TextTransformAndSecurityFixEnabled()
    {
        return is_text_transform_and_security_fix_enabled_;
    }

    static bool TextTransformAndSecurityFixEnabled(const FeatureContext*)
    {
        return TextTransformAndSecurityFixEnabled();
    }

    static bool TimelineScopeEnabled()
    {
        if (!ScrollTimelineEnabled())
            return false;
        return is_timeline_scope_enabled_;
    }

    static bool TimelineScopeEnabled(const FeatureContext*)
    {
        return TimelineScopeEnabled();
    }

    static bool TimerThrottlingForBackgroundTabsEnabled()
    {
        return is_timer_throttling_for_background_tabs_enabled_;
    }

    static bool TimerThrottlingForBackgroundTabsEnabled(const FeatureContext*)
    {
        return TimerThrottlingForBackgroundTabsEnabled();
    }

    static bool TimestampBasedCLSTrackingEnabled()
    {
        return is_timestamp_based_cls_tracking_enabled_;
    }

    static bool TimestampBasedCLSTrackingEnabled(const FeatureContext*)
    {
        return TimestampBasedCLSTrackingEnabled();
    }

    static bool TimeZoneChangeEventEnabled()
    {
        return is_time_zone_change_event_enabled_;
    }

    static bool TimeZoneChangeEventEnabled(const FeatureContext*)
    {
        return TimeZoneChangeEventEnabled();
    }

    static bool TopicsAPIEnabled()
    {
        return is_topics_api_enabled_;
    }

    static bool TopicsAPIEnabled(const FeatureContext*)
    {
        return TopicsAPIEnabled();
    }

    static bool TopicsDocumentAPIEnabled()
    {
        return is_topics_document_api_enabled_;
    }

    static bool TopicsDocumentAPIEnabled(const FeatureContext*)
    {
        return TopicsDocumentAPIEnabled();
    }

    static bool TopLayerInactiveDocumentExceptionsEnabled()
    {
        return is_top_layer_inactive_document_exceptions_enabled_;
    }

    static bool TopLayerInactiveDocumentExceptionsEnabled(const FeatureContext*)
    {
        return TopLayerInactiveDocumentExceptionsEnabled();
    }

    static bool TouchDragAndContextMenuEnabled()
    {
        if (TouchDragOnShortPressEnabled())
            return true;
        return is_touch_drag_and_context_menu_enabled_;
    }

    static bool TouchDragAndContextMenuEnabled(const FeatureContext*)
    {
        return TouchDragAndContextMenuEnabled();
    }

    static bool TouchDragOnShortPressEnabled()
    {
        return is_touch_drag_on_short_press_enabled_;
    }

    static bool TouchDragOnShortPressEnabled(const FeatureContext*)
    {
        return TouchDragOnShortPressEnabled();
    }

    static bool TouchTextEditingRedesignEnabled()
    {
        return is_touch_text_editing_redesign_enabled_;
    }

    static bool TouchTextEditingRedesignEnabled(const FeatureContext*)
    {
        return TouchTextEditingRedesignEnabled();
    }

    static bool TransferableRTCDataChannelEnabled()
    {
        return is_transferable_rtc_data_channel_enabled_;
    }

    static bool TransferableRTCDataChannelEnabled(const FeatureContext*)
    {
        return TransferableRTCDataChannelEnabled();
    }

    static bool TranslateServiceEnabled()
    {
        return is_translate_service_enabled_;
    }

    static bool TranslateServiceEnabled(const FeatureContext*)
    {
        return TranslateServiceEnabled();
    }

    static bool TrustedTypeBeforePolicyCreationEventEnabled()
    {
        return is_trusted_type_before_policy_creation_event_enabled_;
    }

    static bool TrustedTypeBeforePolicyCreationEventEnabled(const FeatureContext*)
    {
        return TrustedTypeBeforePolicyCreationEventEnabled();
    }

    static bool TrustedTypesFromLiteralEnabled()
    {
        return is_trusted_types_from_literal_enabled_;
    }

    static bool TrustedTypesFromLiteralEnabled(const FeatureContext*)
    {
        return TrustedTypesFromLiteralEnabled();
    }

    static bool TrustedTypesUseCodeLikeEnabled()
    {
        return is_trusted_types_use_code_like_enabled_;
    }

    static bool TrustedTypesUseCodeLikeEnabled(const FeatureContext*)
    {
        return TrustedTypesUseCodeLikeEnabled();
    }

    static bool UnclosedFormControlIsInvalidEnabled()
    {
        return is_unclosed_form_control_is_invalid_enabled_;
    }

    static bool UnclosedFormControlIsInvalidEnabled(const FeatureContext*)
    {
        return UnclosedFormControlIsInvalidEnabled();
    }

    static bool UnexposedTaskIdsEnabled()
    {
        return is_unexposed_task_ids_enabled_;
    }

    static bool UnexposedTaskIdsEnabled(const FeatureContext*)
    {
        return UnexposedTaskIdsEnabled();
    }

    static bool UnownedAnimationsSkipCSSEventsEnabled()
    {
        return is_unowned_animations_skip_css_events_enabled_;
    }

    static bool UnownedAnimationsSkipCSSEventsEnabled(const FeatureContext*)
    {
        return UnownedAnimationsSkipCSSEventsEnabled();
    }

    static bool UnrestrictedMeasureUserAgentSpecificMemoryEnabled()
    {
        return is_unrestricted_measure_user_agent_specific_memory_enabled_;
    }

    static bool UnrestrictedMeasureUserAgentSpecificMemoryEnabled(const FeatureContext*)
    {
        return UnrestrictedMeasureUserAgentSpecificMemoryEnabled();
    }

    static bool UnrestrictedUsbEnabled()
    {
        if (!WebUSBEnabled())
            return false;
        return is_unrestricted_usb_enabled_;
    }

    static bool UnrestrictedUsbEnabled(const FeatureContext*)
    {
        return UnrestrictedUsbEnabled();
    }

    static bool URLPatternCompareComponentEnabled()
    {
        return is_url_pattern_compare_component_enabled_;
    }

    static bool URLPatternCompareComponentEnabled(const FeatureContext*)
    {
        return URLPatternCompareComponentEnabled();
    }

    static bool URLSearchParamsHasAndDeleteMultipleArgsEnabled()
    {
        return is_url_search_params_has_and_delete_multiple_args_enabled_;
    }

    static bool URLSearchParamsHasAndDeleteMultipleArgsEnabled(const FeatureContext*)
    {
        return URLSearchParamsHasAndDeleteMultipleArgsEnabled();
    }

    static bool UseBeginFramePresentationFeedbackEnabled()
    {
        return is_use_begin_frame_presentation_feedback_enabled_;
    }

    static bool UseBeginFramePresentationFeedbackEnabled(const FeatureContext*)
    {
        return UseBeginFramePresentationFeedbackEnabled();
    }

    static bool UseLowQualityInterpolationEnabled()
    {
        return is_use_low_quality_interpolation_enabled_;
    }

    static bool UseLowQualityInterpolationEnabled(const FeatureContext*)
    {
        return UseLowQualityInterpolationEnabled();
    }

    static bool UserActivationSameOriginVisibilityEnabled()
    {
        return is_user_activation_same_origin_visibility_enabled_;
    }

    static bool UserActivationSameOriginVisibilityEnabled(const FeatureContext*)
    {
        return UserActivationSameOriginVisibilityEnabled();
    }

    static bool UseSelectionFocusNodeForCaretNavigationEnabled()
    {
        return is_use_selection_focus_node_for_caret_navigation_enabled_;
    }

    static bool UseSelectionFocusNodeForCaretNavigationEnabled(const FeatureContext*)
    {
        return UseSelectionFocusNodeForCaretNavigationEnabled();
    }

    static bool UseUndoStepElementDispatchBeforeInputEnabled()
    {
        return is_use_undo_step_element_dispatch_before_input_enabled_;
    }

    static bool UseUndoStepElementDispatchBeforeInputEnabled(const FeatureContext*)
    {
        return UseUndoStepElementDispatchBeforeInputEnabled();
    }

    static bool V8IdleTasksEnabled()
    {
        return is_v8_idle_tasks_enabled_;
    }

    static bool V8IdleTasksEnabled(const FeatureContext*)
    {
        return V8IdleTasksEnabled();
    }

    static bool VideoAutoFullscreenEnabled()
    {
        return is_video_auto_fullscreen_enabled_;
    }

    static bool VideoAutoFullscreenEnabled(const FeatureContext*)
    {
        return VideoAutoFullscreenEnabled();
    }

    static bool VideoFrameMetadataBackgroundBlurEnabled()
    {
        return is_video_frame_metadata_background_blur_enabled_;
    }

    static bool VideoFrameMetadataBackgroundBlurEnabled(const FeatureContext*)
    {
        return VideoFrameMetadataBackgroundBlurEnabled();
    }

    static bool VideoFullscreenOrientationLockEnabled()
    {
        return is_video_fullscreen_orientation_lock_enabled_;
    }

    static bool VideoFullscreenOrientationLockEnabled(const FeatureContext*)
    {
        return VideoFullscreenOrientationLockEnabled();
    }

    static bool VideoRotateToFullscreenEnabled()
    {
        return is_video_rotate_to_fullscreen_enabled_;
    }

    static bool VideoRotateToFullscreenEnabled(const FeatureContext*)
    {
        return VideoRotateToFullscreenEnabled();
    }

    static bool VideoTrackGeneratorEnabled()
    {
        return is_video_track_generator_enabled_;
    }

    static bool VideoTrackGeneratorEnabled(const FeatureContext*)
    {
        return VideoTrackGeneratorEnabled();
    }

    static bool VideoTrackGeneratorInWindowEnabled()
    {
        return is_video_track_generator_in_window_enabled_;
    }

    static bool VideoTrackGeneratorInWindowEnabled(const FeatureContext*)
    {
        return VideoTrackGeneratorInWindowEnabled();
    }

    static bool VideoTrackGeneratorInWorkerEnabled()
    {
        return is_video_track_generator_in_worker_enabled_;
    }

    static bool VideoTrackGeneratorInWorkerEnabled(const FeatureContext*)
    {
        return VideoTrackGeneratorInWorkerEnabled();
    }

    static bool ViewportChangesUpdateTextAutosizingEnabled()
    {
        return is_viewport_changes_update_text_autosizing_enabled_;
    }

    static bool ViewportChangesUpdateTextAutosizingEnabled(const FeatureContext*)
    {
        return ViewportChangesUpdateTextAutosizingEnabled();
    }

    static bool ViewportHeightClientHintHeaderEnabled()
    {
        return is_viewport_height_client_hint_header_enabled_;
    }

    static bool ViewportHeightClientHintHeaderEnabled(const FeatureContext*)
    {
        return ViewportHeightClientHintHeaderEnabled();
    }

    static bool ViewTransitionDisableSnapBrowserControlsOnHiddenEnabled()
    {
        return is_view_transition_disable_snap_browser_controls_on_hidden_enabled_;
    }

    static bool ViewTransitionDisableSnapBrowserControlsOnHiddenEnabled(const FeatureContext*)
    {
        return ViewTransitionDisableSnapBrowserControlsOnHiddenEnabled();
    }

    static bool ViewTransitionLayeredCaptureEnabled()
    {
        return is_view_transition_layered_capture_enabled_;
    }

    static bool ViewTransitionLayeredCaptureEnabled(const FeatureContext*)
    {
        return ViewTransitionLayeredCaptureEnabled();
    }

    static bool ViewTransitionLongCallbackTimeoutForTestingEnabled()
    {
        return is_view_transition_long_callback_timeout_for_testing_enabled_;
    }

    static bool ViewTransitionLongCallbackTimeoutForTestingEnabled(const FeatureContext*)
    {
        return ViewTransitionLongCallbackTimeoutForTestingEnabled();
    }

    static bool ViewTransitionOnNavigationEnabled()
    {
        return is_view_transition_on_navigation_enabled_;
    }

    static bool ViewTransitionOnNavigationEnabled(const FeatureContext*)
    {
        return ViewTransitionOnNavigationEnabled();
    }

    static bool ViewTransitionOnNavigationForIframesEnabled()
    {
        return is_view_transition_on_navigation_for_iframes_enabled_;
    }

    static bool ViewTransitionOnNavigationForIframesEnabled(const FeatureContext*)
    {
        return ViewTransitionOnNavigationForIframesEnabled();
    }

    static bool ViewTransitionOverflowRectFromSurfaceEnabled()
    {
        if (ViewTransitionLayeredCaptureEnabled())
            return true;
        return is_view_transition_overflow_rect_from_surface_enabled_;
    }

    static bool ViewTransitionOverflowRectFromSurfaceEnabled(const FeatureContext*)
    {
        return ViewTransitionOverflowRectFromSurfaceEnabled();
    }

    static bool ViewTransitionTreeScopedNamesEnabled()
    {
        return is_view_transition_tree_scoped_names_enabled_;
    }

    static bool ViewTransitionTreeScopedNamesEnabled(const FeatureContext*)
    {
        return ViewTransitionTreeScopedNamesEnabled();
    }

    static bool ViewTransitionTypesEnabled()
    {
        return is_view_transition_types_enabled_;
    }

    static bool ViewTransitionTypesEnabled(const FeatureContext*)
    {
        return ViewTransitionTypesEnabled();
    }

    static bool VisibilityCollapseColumnEnabled()
    {
        return is_visibility_collapse_column_enabled_;
    }

    static bool VisibilityCollapseColumnEnabled(const FeatureContext*)
    {
        return VisibilityCollapseColumnEnabled();
    }

    static bool VisualViewportOnScrollEndEnabled()
    {
        return is_visual_viewport_on_scroll_end_enabled_;
    }

    static bool VisualViewportOnScrollEndEnabled(const FeatureContext*)
    {
        return VisualViewportOnScrollEndEnabled();
    }

    static bool WakeLockEnabled()
    {
        if (SystemWakeLockEnabled())
            return true;
        return is_wake_lock_enabled_;
    }

    static bool WakeLockEnabled(const FeatureContext*)
    {
        return WakeLockEnabled();
    }

    static bool WarnOnContentVisibilityRenderAccessEnabled()
    {
        return is_warn_on_content_visibility_render_access_enabled_;
    }

    static bool WarnOnContentVisibilityRenderAccessEnabled(const FeatureContext*)
    {
        return WarnOnContentVisibilityRenderAccessEnabled();
    }

    static bool WebAnimationsSVGEnabled()
    {
        return is_web_animations_svg_enabled_;
    }

    static bool WebAnimationsSVGEnabled(const FeatureContext*)
    {
        return WebAnimationsSVGEnabled();
    }

    static bool WebAppInstallationEnabled()
    {
        return is_web_app_installation_enabled_;
    }

    static bool WebAppInstallationEnabled(const FeatureContext*)
    {
        return WebAppInstallationEnabled();
    }

    static bool WebAppTabStripEnabled()
    {
        return is_web_app_tab_strip_enabled_;
    }

    static bool WebAppTabStripEnabled(const FeatureContext*)
    {
        return WebAppTabStripEnabled();
    }

    static bool WebAppTabStripCustomizationsEnabled()
    {
        return is_web_app_tab_strip_customizations_enabled_;
    }

    static bool WebAppTabStripCustomizationsEnabled(const FeatureContext*)
    {
        return WebAppTabStripCustomizationsEnabled();
    }

    static bool WebAppTranslationsEnabled()
    {
        return is_web_app_translations_enabled_;
    }

    static bool WebAppTranslationsEnabled(const FeatureContext*)
    {
        return WebAppTranslationsEnabled();
    }

    static bool WebAudioBypassOutputBufferingEnabled()
    {
        return is_web_audio_bypass_output_buffering_enabled_;
    }

    static bool WebAudioBypassOutputBufferingEnabled(const FeatureContext*)
    {
        return WebAudioBypassOutputBufferingEnabled();
    }

    static bool WebAudioBypassOutputBufferingOptOutEnabled()
    {
        return is_web_audio_bypass_output_buffering_opt_out_enabled_;
    }

    static bool WebAudioBypassOutputBufferingOptOutEnabled(const FeatureContext*)
    {
        return WebAudioBypassOutputBufferingOptOutEnabled();
    }

    static bool WebAuthEnabled()
    {
        return is_web_auth_enabled_;
    }

    static bool WebAuthEnabled(const FeatureContext*)
    {
        return WebAuthEnabled();
    }

    static bool WebAuthAuthenticatorAttachmentEnabled()
    {
        return is_web_auth_authenticator_attachment_enabled_;
    }

    static bool WebAuthAuthenticatorAttachmentEnabled(const FeatureContext*)
    {
        return WebAuthAuthenticatorAttachmentEnabled();
    }

    static bool WebAuthenticationAmbientEnabled()
    {
        return is_web_authentication_ambient_enabled_;
    }

    static bool WebAuthenticationAmbientEnabled(const FeatureContext*)
    {
        return WebAuthenticationAmbientEnabled();
    }

    static bool WebAuthenticationClientCapabilitiesEnabled()
    {
        return is_web_authentication_client_capabilities_enabled_;
    }

    static bool WebAuthenticationClientCapabilitiesEnabled(const FeatureContext*)
    {
        return WebAuthenticationClientCapabilitiesEnabled();
    }

    static bool WebAuthenticationJSONSerializationEnabled()
    {
        return is_web_authentication_js_on_serialization_enabled_;
    }

    static bool WebAuthenticationJSONSerializationEnabled(const FeatureContext*)
    {
        return WebAuthenticationJSONSerializationEnabled();
    }

    static bool WebAuthenticationLargeBlobExtensionEnabled()
    {
        return is_web_authentication_large_blob_extension_enabled_;
    }

    static bool WebAuthenticationLargeBlobExtensionEnabled(const FeatureContext*)
    {
        return WebAuthenticationLargeBlobExtensionEnabled();
    }

    static bool WebAuthenticationPRFEnabled()
    {
        return is_web_authentication_prf_enabled_;
    }

    static bool WebAuthenticationPRFEnabled(const FeatureContext*)
    {
        return WebAuthenticationPRFEnabled();
    }

    static bool WebAuthenticationRemoteDesktopSupportEnabled()
    {
        return is_web_authentication_remote_desktop_support_enabled_;
    }

    static bool WebAuthenticationRemoteDesktopSupportEnabled(const FeatureContext*)
    {
        return WebAuthenticationRemoteDesktopSupportEnabled();
    }

    static bool WebAuthenticationSupplementalPubKeysEnabled()
    {
        return is_web_authentication_supplemental_pub_keys_enabled_;
    }

    static bool WebAuthenticationSupplementalPubKeysEnabled(const FeatureContext*)
    {
        return WebAuthenticationSupplementalPubKeysEnabled();
    }

    static bool WebBluetoothEnabled()
    {
        return is_web_bluetooth_enabled_;
    }

    static bool WebBluetoothEnabled(const FeatureContext*)
    {
        return WebBluetoothEnabled();
    }

    static bool WebBluetoothGetDevicesEnabled()
    {
        return is_web_bluetooth_get_devices_enabled_;
    }

    static bool WebBluetoothGetDevicesEnabled(const FeatureContext*)
    {
        return WebBluetoothGetDevicesEnabled();
    }

    static bool WebBluetoothScanningEnabled()
    {
        return is_web_bluetooth_scanning_enabled_;
    }

    static bool WebBluetoothScanningEnabled(const FeatureContext*)
    {
        return WebBluetoothScanningEnabled();
    }

    static bool WebBluetoothWatchAdvertisementsEnabled()
    {
        return is_web_bluetooth_watch_advertisements_enabled_;
    }

    static bool WebBluetoothWatchAdvertisementsEnabled(const FeatureContext*)
    {
        return WebBluetoothWatchAdvertisementsEnabled();
    }

    static bool WebCodecsCopyToRGBEnabled()
    {
        return is_webcodecs_copy_to_rgb_enabled_;
    }

    static bool WebCodecsCopyToRGBEnabled(const FeatureContext*)
    {
        return WebCodecsCopyToRGBEnabled();
    }

    static bool WebCodecsHBDFormatsEnabled()
    {
        return is_webcodecs_hbd_formats_enabled_;
    }

    static bool WebCodecsHBDFormatsEnabled(const FeatureContext*)
    {
        return WebCodecsHBDFormatsEnabled();
    }

    static bool WebCodecsOrientationEnabled()
    {
        return is_webcodecs_orientation_enabled_;
    }

    static bool WebCodecsOrientationEnabled(const FeatureContext*)
    {
        return WebCodecsOrientationEnabled();
    }

    static bool WebCodecsVideoEncoderBuffersEnabled()
    {
        return is_webcodecs_video_encoder_buffers_enabled_;
    }

    static bool WebCodecsVideoEncoderBuffersEnabled(const FeatureContext*)
    {
        return WebCodecsVideoEncoderBuffersEnabled();
    }

    static bool WebCryptoCurve25519Enabled()
    {
        return is_web_crypto_curve_25519_enabled_;
    }

    static bool WebCryptoCurve25519Enabled(const FeatureContext*)
    {
        return WebCryptoCurve25519Enabled();
    }

    static bool WebFontResizeLCPEnabled()
    {
        return is_web_font_resize_lcp_enabled_;
    }

    static bool WebFontResizeLCPEnabled(const FeatureContext*)
    {
        return WebFontResizeLCPEnabled();
    }

    static bool WebGLDeveloperExtensionsEnabled()
    {
        return is_webgl_developer_extensions_enabled_;
    }

    static bool WebGLDeveloperExtensionsEnabled(const FeatureContext*)
    {
        return WebGLDeveloperExtensionsEnabled();
    }

    static bool WebGLDraftExtensionsEnabled()
    {
        return is_webgl_draft_extensions_enabled_;
    }

    static bool WebGLDraftExtensionsEnabled(const FeatureContext*)
    {
        return WebGLDraftExtensionsEnabled();
    }

    static bool WebGLDrawingBufferStorageEnabled()
    {
        return is_webgl_drawing_buffer_storage_enabled_;
    }

    static bool WebGLDrawingBufferStorageEnabled(const FeatureContext*)
    {
        return WebGLDrawingBufferStorageEnabled();
    }

    static bool WebGLImageChromiumEnabled()
    {
        return is_webgl_image_chromium_enabled_;
    }

    static bool WebGLImageChromiumEnabled(const FeatureContext*)
    {
        return WebGLImageChromiumEnabled();
    }

    static bool WebGPUCanvasContextGetConfigurationEnabled()
    {
        return is_webgpu_canvas_context_get_configuration_enabled_;
    }

    static bool WebGPUCanvasContextGetConfigurationEnabled(const FeatureContext*)
    {
        return WebGPUCanvasContextGetConfigurationEnabled();
    }

    static bool WebGPUDeveloperFeaturesEnabled()
    {
        return is_webgpu_developer_features_enabled_;
    }

    static bool WebGPUDeveloperFeaturesEnabled(const FeatureContext*)
    {
        return WebGPUDeveloperFeaturesEnabled();
    }

    static bool WebGPUDeviceAdapterInfoEnabled()
    {
        return is_webgpu_device_adapter_info_enabled_;
    }

    static bool WebGPUDeviceAdapterInfoEnabled(const FeatureContext*)
    {
        return WebGPUDeviceAdapterInfoEnabled();
    }

    static bool WebGPUExperimentalFeaturesEnabled()
    {
        return is_webgpu_experimental_features_enabled_;
    }

    static bool WebGPUExperimentalFeaturesEnabled(const FeatureContext*)
    {
        return WebGPUExperimentalFeaturesEnabled();
    }

    static bool WebGPUHDREnabled()
    {
        return is_webgpu_hdr_enabled_;
    }

    static bool WebGPUHDREnabled(const FeatureContext*)
    {
        return WebGPUHDREnabled();
    }

    static bool WebGPUTextureViewUsageEnabled()
    {
        return is_webgpu_texture_view_usage_enabled_;
    }

    static bool WebGPUTextureViewUsageEnabled(const FeatureContext*)
    {
        return WebGPUTextureViewUsageEnabled();
    }

    static bool WebHIDEnabled()
    {
        return is_web_hid_enabled_;
    }

    static bool WebHIDEnabled(const FeatureContext*)
    {
        return WebHIDEnabled();
    }

    static bool WebHIDOnDedicatedWorkersEnabled()
    {
        if (!WebHIDEnabled())
            return false;
        return is_web_hid_on_dedicated_workers_enabled_;
    }

    static bool WebHIDOnDedicatedWorkersEnabled(const FeatureContext*)
    {
        return WebHIDOnDedicatedWorkersEnabled();
    }

    static bool WebHIDOnServiceWorkersEnabled()
    {
        if (!WebHIDEnabled())
            return false;
        return is_web_hid_on_service_workers_enabled_;
    }

    static bool WebHIDOnServiceWorkersEnabled(const FeatureContext*)
    {
        return WebHIDOnServiceWorkersEnabled();
    }

    static bool WebIDLBigIntUsesToBigIntEnabled()
    {
        return is_web_idl_big_int_uses_to_big_int_enabled_;
    }

    static bool WebIDLBigIntUsesToBigIntEnabled(const FeatureContext*)
    {
        return WebIDLBigIntUsesToBigIntEnabled();
    }

    static bool WebNFCEnabled()
    {
        return is_web_nfc_enabled_;
    }

    static bool WebNFCEnabled(const FeatureContext*)
    {
        return WebNFCEnabled();
    }

    static bool WebOTPEnabled()
    {
        return is_web_otp_enabled_;
    }

    static bool WebOTPEnabled(const FeatureContext*)
    {
        return WebOTPEnabled();
    }

    static bool WebOTPAssertionFeaturePolicyEnabled()
    {
        if (!WebOTPEnabled())
            return false;
        return is_web_otp_assertion_feature_policy_enabled_;
    }

    static bool WebOTPAssertionFeaturePolicyEnabled(const FeatureContext*)
    {
        return WebOTPAssertionFeaturePolicyEnabled();
    }

    static bool WebPreferencesEnabled()
    {
        return is_web_preferences_enabled_;
    }

    static bool WebPreferencesEnabled(const FeatureContext*)
    {
        return WebPreferencesEnabled();
    }

    static bool WebPrintingEnabled()
    {
        return is_web_printing_enabled_;
    }

    static bool WebPrintingEnabled(const FeatureContext*)
    {
        return WebPrintingEnabled();
    }

    static bool WebShareEnabled()
    {
        return is_web_share_enabled_;
    }

    static bool WebShareEnabled(const FeatureContext*)
    {
        return WebShareEnabled();
    }

    static bool WebSocketStreamEnabled()
    {
        return is_websocket_stream_enabled_;
    }

    static bool WebSocketStreamEnabled(const FeatureContext*)
    {
        return WebSocketStreamEnabled();
    }

    static bool WebTransportStatsEnabled()
    {
        return is_web_transport_stats_enabled_;
    }

    static bool WebTransportStatsEnabled(const FeatureContext*)
    {
        return WebTransportStatsEnabled();
    }

    static bool WebUSBEnabled()
    {
        return is_web_usb_enabled_;
    }

    static bool WebUSBEnabled(const FeatureContext*)
    {
        return WebUSBEnabled();
    }

    static bool WebUSBOnDedicatedWorkersEnabled()
    {
        if (!WebUSBEnabled())
            return false;
        return is_web_usb_on_dedicated_workers_enabled_;
    }

    static bool WebUSBOnDedicatedWorkersEnabled(const FeatureContext*)
    {
        return WebUSBOnDedicatedWorkersEnabled();
    }

    static bool WebUSBOnServiceWorkersEnabled()
    {
        if (!WebUSBEnabled())
            return false;
        return is_web_usb_on_service_workers_enabled_;
    }

    static bool WebUSBOnServiceWorkersEnabled(const FeatureContext*)
    {
        return WebUSBOnServiceWorkersEnabled();
    }

    static bool WebVTTRegionsEnabled()
    {
        return is_web_vtt_regions_enabled_;
    }

    static bool WebVTTRegionsEnabled(const FeatureContext*)
    {
        return WebVTTRegionsEnabled();
    }

    static bool WebXREnabled()
    {
        return is_web_xr_enabled_;
    }

    static bool WebXREnabled(const FeatureContext*)
    {
        return WebXREnabled();
    }

    static bool WebXREnabledFeaturesEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_enabled_features_enabled_;
    }

    static bool WebXREnabledFeaturesEnabled(const FeatureContext*)
    {
        return WebXREnabledFeaturesEnabled();
    }

    static bool WebXRFrameRateEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_frame_rate_enabled_;
    }

    static bool WebXRFrameRateEnabled(const FeatureContext*)
    {
        return WebXRFrameRateEnabled();
    }

    static bool WebXRFrontFacingEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_front_facing_enabled_;
    }

    static bool WebXRFrontFacingEnabled(const FeatureContext*)
    {
        return WebXRFrontFacingEnabled();
    }

    static bool WebXRGPUBindingEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_gpu_binding_enabled_;
    }

    static bool WebXRGPUBindingEnabled(const FeatureContext*)
    {
        return WebXRGPUBindingEnabled();
    }

    static bool WebXRHandInputEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_hand_input_enabled_;
    }

    static bool WebXRHandInputEnabled(const FeatureContext*)
    {
        return WebXRHandInputEnabled();
    }

    static bool WebXRHitTestEntityTypesEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_hit_test_entity_types_enabled_;
    }

    static bool WebXRHitTestEntityTypesEnabled(const FeatureContext*)
    {
        return WebXRHitTestEntityTypesEnabled();
    }

    static bool WebXRLayersEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_layers_enabled_;
    }

    static bool WebXRLayersEnabled(const FeatureContext*)
    {
        return WebXRLayersEnabled();
    }

    static bool WebXRLayersCommonEnabled()
    {
        if (WebXRLayersEnabled())
            return true;
        if (WebXRGPUBindingEnabled())
            return true;
        return is_web_xr_layers_common_enabled_;
    }

    static bool WebXRLayersCommonEnabled(const FeatureContext*)
    {
        return WebXRLayersCommonEnabled();
    }

    static bool WebXRPoseMotionDataEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_pose_motion_data_enabled_;
    }

    static bool WebXRPoseMotionDataEnabled(const FeatureContext*)
    {
        return WebXRPoseMotionDataEnabled();
    }

    static bool WebXRSpecParityEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_spec_parity_enabled_;
    }

    static bool WebXRSpecParityEnabled(const FeatureContext*)
    {
        return WebXRSpecParityEnabled();
    }

    static bool WindowDefaultStatusEnabled()
    {
        return is_window_default_status_enabled_;
    }

    static bool WindowDefaultStatusEnabled(const FeatureContext*)
    {
        return WindowDefaultStatusEnabled();
    }

    static bool XMLParserMergeAdjacentCDataSectionsEnabled()
    {
        return is_xml_parser_merge_adjacent_c_data_sections_enabled_;
    }

    static bool XMLParserMergeAdjacentCDataSectionsEnabled(const FeatureContext*)
    {
        return XMLParserMergeAdjacentCDataSectionsEnabled();
    }

    static bool ZeroCopyTabCaptureEnabled()
    {
        return is_zero_copy_tab_capture_enabled_;
    }

    static bool ZeroCopyTabCaptureEnabled(const FeatureContext*)
    {
        return ZeroCopyTabCaptureEnabled();
    }

    // Origin-trial-enabled features:
    //
    // These features are currently part of an origin trial (see
    // https://www.chromium.org/blink/origin-trials). <feature>EnabledByRuntimeFlag()
    // can be used to test whether the feature is unconditionally enabled
    // (for example, by starting the browser with the appropriate command-line flag).
    // However, that is almost always the incorrect check. Most renderer code should
    // be calling <feature>Enabled(const FeatureContext*) instead, to test if the
    // feature is enabled in a given context.

    static bool AdInterestGroupAPIEnabledByRuntimeFlag()
    {
        return AdInterestGroupAPIEnabled(nullptr);
    }
    static bool AdInterestGroupAPIEnabled(const FeatureContext*);

    static bool AIPromptAPIForExtensionEnabledByRuntimeFlag()
    {
        return AIPromptAPIForExtensionEnabled(nullptr);
    }
    static bool AIPromptAPIForExtensionEnabled(const FeatureContext*);

    static bool AISummarizationAPIEnabledByRuntimeFlag()
    {
        return AISummarizationAPIEnabled(nullptr);
    }
    static bool AISummarizationAPIEnabled(const FeatureContext*);

    static bool AppTitleEnabledByRuntimeFlag()
    {
        return AppTitleEnabled(nullptr);
    }
    static bool AppTitleEnabled(const FeatureContext*);

    static bool AttributionReportingInterfaceEnabledByRuntimeFlag()
    {
        return AttributionReportingInterfaceEnabled(nullptr);
    }
    static bool AttributionReportingInterfaceEnabled(const FeatureContext*);

    static bool AudioContextPlayoutStatsEnabledByRuntimeFlag()
    {
        return AudioContextPlayoutStatsEnabled(nullptr);
    }
    static bool AudioContextPlayoutStatsEnabled(const FeatureContext*);

    static bool AutoDarkModeEnabledByRuntimeFlag()
    {
        return AutoDarkModeEnabled(nullptr);
    }
    static bool AutoDarkModeEnabled(const FeatureContext*);

    static bool BackForwardCacheExperimentHTTPHeaderEnabledByRuntimeFlag()
    {
        return BackForwardCacheExperimentHTTPHeaderEnabled(nullptr);
    }
    static bool BackForwardCacheExperimentHTTPHeaderEnabled(const FeatureContext*);

    static bool BackForwardCacheNotRestoredReasonsEnabledByRuntimeFlag()
    {
        return BackForwardCacheNotRestoredReasonsEnabled(nullptr);
    }
    static bool BackForwardCacheNotRestoredReasonsEnabled(const FeatureContext*);

    static bool BuiltInAIAPIEnabledByRuntimeFlag()
    {
        return BuiltInAIAPIEnabled(nullptr);
    }
    static bool BuiltInAIAPIEnabled(const FeatureContext*);

    static bool CacheStorageCodeCacheHintEnabledByRuntimeFlag()
    {
        return CacheStorageCodeCacheHintEnabled(nullptr);
    }
    static bool CacheStorageCodeCacheHintEnabled(const FeatureContext*);

    static bool Canvas2dMeshEnabledByRuntimeFlag()
    {
        return Canvas2dMeshEnabled(nullptr);
    }
    static bool Canvas2dMeshEnabled(const FeatureContext*);

    static bool CapturedSurfaceControlEnabledByRuntimeFlag()
    {
        return CapturedSurfaceControlEnabled(nullptr);
    }
    static bool CapturedSurfaceControlEnabled(const FeatureContext*);

    static bool CoopRestrictPropertiesEnabledByRuntimeFlag()
    {
        return CoopRestrictPropertiesEnabled(nullptr);
    }
    static bool CoopRestrictPropertiesEnabled(const FeatureContext*);

    static bool DatabaseEnabledByRuntimeFlag()
    {
        return DatabaseEnabled(nullptr);
    }
    static bool DatabaseEnabled(const FeatureContext*);

    static bool DeprecateUnloadOptOutEnabledByRuntimeFlag()
    {
        return DeprecateUnloadOptOutEnabled(nullptr);
    }
    static bool DeprecateUnloadOptOutEnabled(const FeatureContext*);

    static bool DigitalGoodsEnabledByRuntimeFlag()
    {
        return DigitalGoodsEnabled(nullptr);
    }
    static bool DigitalGoodsEnabled(const FeatureContext*);

    static bool DisableDifferentOriginSubframeDialogSuppressionEnabledByRuntimeFlag()
    {
        return DisableDifferentOriginSubframeDialogSuppressionEnabled(nullptr);
    }
    static bool DisableDifferentOriginSubframeDialogSuppressionEnabled(const FeatureContext*);

    static bool DisableHardwareNoiseSuppressionEnabledByRuntimeFlag()
    {
        return DisableHardwareNoiseSuppressionEnabled(nullptr);
    }
    static bool DisableHardwareNoiseSuppressionEnabled(const FeatureContext*);

    static bool DisableReduceAcceptLanguageEnabledByRuntimeFlag()
    {
        return DisableReduceAcceptLanguageEnabled(nullptr);
    }
    static bool DisableReduceAcceptLanguageEnabled(const FeatureContext*);

    static bool DisableThirdPartyStoragePartitioning2EnabledByRuntimeFlag()
    {
        return DisableThirdPartyStoragePartitioning2Enabled(nullptr);
    }
    static bool DisableThirdPartyStoragePartitioning2Enabled(const FeatureContext*);

    static bool DocumentIsolationPolicyEnabledByRuntimeFlag()
    {
        return DocumentIsolationPolicyEnabled(nullptr);
    }
    static bool DocumentIsolationPolicyEnabled(const FeatureContext*);

    static bool DocumentPolicyIncludeJSCallStacksInCrashReportsEnabledByRuntimeFlag()
    {
        return DocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(nullptr);
    }
    static bool DocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(const FeatureContext*);

    static bool DocumentPolicyNegotiationEnabledByRuntimeFlag()
    {
        return DocumentPolicyNegotiationEnabled(nullptr);
    }
    static bool DocumentPolicyNegotiationEnabled(const FeatureContext*);

    static bool FedCmAuthzEnabledByRuntimeFlag()
    {
        return FedCmAuthzEnabled(nullptr);
    }
    static bool FedCmAuthzEnabled(const FeatureContext*);

    static bool FedCmButtonModeEnabledByRuntimeFlag()
    {
        return FedCmButtonModeEnabled(nullptr);
    }
    static bool FedCmButtonModeEnabled(const FeatureContext*);

    static bool FedCmMultipleIdentityProvidersEnabledByRuntimeFlag()
    {
        return FedCmMultipleIdentityProvidersEnabled(nullptr);
    }
    static bool FedCmMultipleIdentityProvidersEnabled(const FeatureContext*);

    static bool FedCmWithStorageAccessAPIEnabledByRuntimeFlag()
    {
        return FedCmWithStorageAccessAPIEnabled(nullptr);
    }
    static bool FedCmWithStorageAccessAPIEnabled(const FeatureContext*);

    static bool FetchLaterAPIEnabledByRuntimeFlag()
    {
        return FetchLaterAPIEnabled(nullptr);
    }
    static bool FetchLaterAPIEnabled(const FeatureContext*);

    static bool FileSystemObserverEnabledByRuntimeFlag()
    {
        return FileSystemObserverEnabled(nullptr);
    }
    static bool FileSystemObserverEnabled(const FeatureContext*);

    static bool FledgeBiddingAndAuctionServerAPIEnabledByRuntimeFlag()
    {
        return FledgeBiddingAndAuctionServerAPIEnabled(nullptr);
    }
    static bool FledgeBiddingAndAuctionServerAPIEnabled(const FeatureContext*);

    static bool FocusgroupEnabledByRuntimeFlag()
    {
        return FocusgroupEnabled(nullptr);
    }
    static bool FocusgroupEnabled(const FeatureContext*);

    static bool GetAllScreensMediaEnabledByRuntimeFlag()
    {
        return GetAllScreensMediaEnabled(nullptr);
    }
    static bool GetAllScreensMediaEnabled(const FeatureContext*);

    static bool HrefTranslateEnabledByRuntimeFlag()
    {
        return HrefTranslateEnabled(nullptr);
    }
    static bool HrefTranslateEnabled(const FeatureContext*);

    static bool JavaScriptCompileHintsMagicAlwaysRuntimeEnabledByRuntimeFlag()
    {
        return JavaScriptCompileHintsMagicAlwaysRuntimeEnabled(nullptr);
    }
    static bool JavaScriptCompileHintsMagicAlwaysRuntimeEnabled(const FeatureContext*);

    static bool JavaScriptCompileHintsMagicRuntimeEnabledByRuntimeFlag()
    {
        return JavaScriptCompileHintsMagicRuntimeEnabled(nullptr);
    }
    static bool JavaScriptCompileHintsMagicRuntimeEnabled(const FeatureContext*);

    static bool KeyboardFocusableScrollersOptOutEnabledByRuntimeFlag()
    {
        return KeyboardFocusableScrollersOptOutEnabled(nullptr);
    }
    static bool KeyboardFocusableScrollersOptOutEnabled(const FeatureContext*);

    static bool LanguageDetectionAPIEnabledByRuntimeFlag()
    {
        return LanguageDetectionAPIEnabled(nullptr);
    }
    static bool LanguageDetectionAPIEnabled(const FeatureContext*);

    static bool LimitThirdPartyCookiesEnabledByRuntimeFlag()
    {
        return LimitThirdPartyCookiesEnabled(nullptr);
    }
    static bool LimitThirdPartyCookiesEnabled(const FeatureContext*);

    static bool MediaCaptureBackgroundBlurEnabledByRuntimeFlag()
    {
        return MediaCaptureBackgroundBlurEnabled(nullptr);
    }
    static bool MediaCaptureBackgroundBlurEnabled(const FeatureContext*);

    static bool MediaCaptureConfigurationChangeEnabledByRuntimeFlag()
    {
        return MediaCaptureConfigurationChangeEnabled(nullptr);
    }
    static bool MediaCaptureConfigurationChangeEnabled(const FeatureContext*);

    static bool MediaPreviewsOptOutEnabledByRuntimeFlag()
    {
        return MediaPreviewsOptOutEnabled(nullptr);
    }
    static bool MediaPreviewsOptOutEnabled(const FeatureContext*);

    static bool MediaSourceExtensionsForWebCodecsEnabledByRuntimeFlag()
    {
        return MediaSourceExtensionsForWebCodecsEnabled(nullptr);
    }
    static bool MediaSourceExtensionsForWebCodecsEnabled(const FeatureContext*);

    static bool MutationEventsEnabledByRuntimeFlag()
    {
        return MutationEventsEnabled(nullptr);
    }
    static bool MutationEventsEnabled(const FeatureContext*);

    static bool NavigationIdEnabledByRuntimeFlag()
    {
        return NavigationIdEnabled(nullptr);
    }
    static bool NavigationIdEnabled(const FeatureContext*);

    static bool NotificationTriggersEnabledByRuntimeFlag()
    {
        return NotificationTriggersEnabled(nullptr);
    }
    static bool NotificationTriggersEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIBrowserReadWriteEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIBrowserReadWriteEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIBrowserReadWriteEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIDependentEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIDependentEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIDependentEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIDeprecationEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIExpiryGracePeriodEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIExpiryGracePeriodEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIExpiryGracePeriodEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIImpliedEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIImpliedEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIInvalidOSEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPINavigationEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPINavigationEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPINavigationEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIPersistentFeatureEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIPersistentFeatureEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIPersistentFeatureEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIPersistentInvalidOSEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIPersistentInvalidOSEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIPersistentInvalidOSEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIThirdPartyEnabledByRuntimeFlag()
    {
        return OriginTrialsSampleAPIThirdPartyEnabled(nullptr);
    }
    static bool OriginTrialsSampleAPIThirdPartyEnabled(const FeatureContext*);

    static bool PageFreezeOptInEnabledByRuntimeFlag()
    {
        return PageFreezeOptInEnabled(nullptr);
    }
    static bool PageFreezeOptInEnabled(const FeatureContext*);

    static bool PageFreezeOptOutEnabledByRuntimeFlag()
    {
        return PageFreezeOptOutEnabled(nullptr);
    }
    static bool PageFreezeOptOutEnabled(const FeatureContext*);

    static bool ParakeetEnabledByRuntimeFlag()
    {
        return ParakeetEnabled(nullptr);
    }
    static bool ParakeetEnabled(const FeatureContext*);

    static bool PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag()
    {
        return PerMethodCanMakePaymentQuotaEnabled(nullptr);
    }
    static bool PerMethodCanMakePaymentQuotaEnabled(const FeatureContext*);

    static bool PermissionElementEnabledByRuntimeFlag()
    {
        return PermissionElementEnabled(nullptr);
    }
    static bool PermissionElementEnabled(const FeatureContext*);

    static bool PNaClEnabledByRuntimeFlag()
    {
        return PNaClEnabled(nullptr);
    }
    static bool PNaClEnabled(const FeatureContext*);

    static bool PrefixedVideoFullscreenEnabledByRuntimeFlag()
    {
        return PrefixedVideoFullscreenEnabled(nullptr);
    }
    static bool PrefixedVideoFullscreenEnabled(const FeatureContext*);

    static bool PrivateNetworkAccessNonSecureContextsAllowedEnabledByRuntimeFlag()
    {
        return PrivateNetworkAccessNonSecureContextsAllowedEnabled(nullptr);
    }
    static bool PrivateNetworkAccessNonSecureContextsAllowedEnabled(const FeatureContext*);

    static bool PrivateNetworkAccessPermissionPromptEnabledByRuntimeFlag()
    {
        return PrivateNetworkAccessPermissionPromptEnabled(nullptr);
    }
    static bool PrivateNetworkAccessPermissionPromptEnabled(const FeatureContext*);

    static bool PrivateStateTokensEnabledByRuntimeFlag()
    {
        return PrivateStateTokensEnabled(nullptr);
    }
    static bool PrivateStateTokensEnabled(const FeatureContext*);

    static bool ProtectedOriginTrialsSampleAPIEnabledByRuntimeFlag()
    {
        return ProtectedOriginTrialsSampleAPIEnabled(nullptr);
    }
    static bool ProtectedOriginTrialsSampleAPIEnabled(const FeatureContext*);

    static bool ProtectedOriginTrialsSampleAPIDependentEnabledByRuntimeFlag()
    {
        return ProtectedOriginTrialsSampleAPIDependentEnabled(nullptr);
    }
    static bool ProtectedOriginTrialsSampleAPIDependentEnabled(const FeatureContext*);

    static bool ProtectedOriginTrialsSampleAPIImpliedEnabledByRuntimeFlag()
    {
        return ProtectedOriginTrialsSampleAPIImpliedEnabled(nullptr);
    }
    static bool ProtectedOriginTrialsSampleAPIImpliedEnabled(const FeatureContext*);

    static bool ReduceAcceptLanguageEnabledByRuntimeFlag()
    {
        return ReduceAcceptLanguageEnabled(nullptr);
    }
    static bool ReduceAcceptLanguageEnabled(const FeatureContext*);

    static bool RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag()
    {
        return RtcAudioJitterBufferMaxPacketsEnabled(nullptr);
    }
    static bool RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext*);

    static bool RTCEncodedFrameSetMetadataEnabledByRuntimeFlag()
    {
        return RTCEncodedFrameSetMetadataEnabled(nullptr);
    }
    static bool RTCEncodedFrameSetMetadataEnabled(const FeatureContext*);

    static bool RTCLegacyCallbackBasedGetStatsEnabledByRuntimeFlag()
    {
        return RTCLegacyCallbackBasedGetStatsEnabled(nullptr);
    }
    static bool RTCLegacyCallbackBasedGetStatsEnabled(const FeatureContext*);

    static bool RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag()
    {
        return RTCStatsRelativePacketArrivalDelayEnabled(nullptr);
    }
    static bool RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext*);

    static bool SecurePaymentConfirmationOptOutEnabledByRuntimeFlag()
    {
        return SecurePaymentConfirmationOptOutEnabled(nullptr);
    }
    static bool SecurePaymentConfirmationOptOutEnabled(const FeatureContext*);

    static bool ServiceWorkerStaticRouterEnabledByRuntimeFlag()
    {
        return ServiceWorkerStaticRouterEnabled(nullptr);
    }
    static bool ServiceWorkerStaticRouterEnabled(const FeatureContext*);

    static bool ServiceWorkerStaticRouterTimingInfoEnabledByRuntimeFlag()
    {
        return ServiceWorkerStaticRouterTimingInfoEnabled(nullptr);
    }
    static bool ServiceWorkerStaticRouterTimingInfoEnabled(const FeatureContext*);

    static bool SignatureBasedIntegrityEnabledByRuntimeFlag()
    {
        return SignatureBasedIntegrityEnabled(nullptr);
    }
    static bool SignatureBasedIntegrityEnabled(const FeatureContext*);

    static bool SkipPreloadScanningEnabledByRuntimeFlag()
    {
        return SkipPreloadScanningEnabled(nullptr);
    }
    static bool SkipPreloadScanningEnabled(const FeatureContext*);

    static bool SoftNavigationHeuristicsEnabledByRuntimeFlag()
    {
        return SoftNavigationHeuristicsEnabled(nullptr);
    }
    static bool SoftNavigationHeuristicsEnabled(const FeatureContext*);

    static bool SpeculationRulesPrefetchFutureEnabledByRuntimeFlag()
    {
        return SpeculationRulesPrefetchFutureEnabled(nullptr);
    }
    static bool SpeculationRulesPrefetchFutureEnabled(const FeatureContext*);

    static bool StandardizedBrowserZoomOptOutEnabledByRuntimeFlag()
    {
        return StandardizedBrowserZoomOptOutEnabled(nullptr);
    }
    static bool StandardizedBrowserZoomOptOutEnabled(const FeatureContext*);

    static bool StorageAccessHeaderEnabledByRuntimeFlag()
    {
        return StorageAccessHeaderEnabled(nullptr);
    }
    static bool StorageAccessHeaderEnabled(const FeatureContext*);

    static bool TextFragmentIdentifiersEnabledByRuntimeFlag()
    {
        return TextFragmentIdentifiersEnabled(nullptr);
    }
    static bool TextFragmentIdentifiersEnabled(const FeatureContext*);

    static bool TopLevelTpcdEnabledByRuntimeFlag()
    {
        return TopLevelTpcdEnabled(nullptr);
    }
    static bool TopLevelTpcdEnabled(const FeatureContext*);

    static bool TouchEventFeatureDetectionEnabledByRuntimeFlag()
    {
        return TouchEventFeatureDetectionEnabled(nullptr);
    }
    static bool TouchEventFeatureDetectionEnabled(const FeatureContext*);

    static bool TpcdEnabledByRuntimeFlag()
    {
        return TpcdEnabled(nullptr);
    }
    static bool TpcdEnabled(const FeatureContext*);

    static bool TranslationAPIEnabledByRuntimeFlag()
    {
        return TranslationAPIEnabled(nullptr);
    }
    static bool TranslationAPIEnabled(const FeatureContext*);

    static bool TranslationAPIEntryPointEnabledByRuntimeFlag()
    {
        return TranslationAPIEntryPointEnabled(nullptr);
    }
    static bool TranslationAPIEntryPointEnabled(const FeatureContext*);

    static bool UnrestrictedSharedArrayBufferEnabledByRuntimeFlag()
    {
        return UnrestrictedSharedArrayBufferEnabled(nullptr);
    }
    static bool UnrestrictedSharedArrayBufferEnabled(const FeatureContext*);

    static bool ViewportSegmentsEnabledByRuntimeFlag()
    {
        return ViewportSegmentsEnabled(nullptr);
    }
    static bool ViewportSegmentsEnabled(const FeatureContext*);

    static bool WebAppLaunchQueueEnabledByRuntimeFlag()
    {
        return WebAppLaunchQueueEnabled(nullptr);
    }
    static bool WebAppLaunchQueueEnabled(const FeatureContext*);

    static bool WebAppScopeExtensionsEnabledByRuntimeFlag()
    {
        return WebAppScopeExtensionsEnabled(nullptr);
    }
    static bool WebAppScopeExtensionsEnabled(const FeatureContext*);

    static bool WebAppUrlHandlingEnabledByRuntimeFlag()
    {
        return WebAppUrlHandlingEnabled(nullptr);
    }
    static bool WebAppUrlHandlingEnabled(const FeatureContext*);

    static bool WebAssemblyJSPromiseIntegrationEnabledByRuntimeFlag()
    {
        return WebAssemblyJSPromiseIntegrationEnabled(nullptr);
    }
    static bool WebAssemblyJSPromiseIntegrationEnabled(const FeatureContext*);

    static bool WebAssemblyJSStringBuiltinsEnabledByRuntimeFlag()
    {
        return WebAssemblyJSStringBuiltinsEnabled(nullptr);
    }
    static bool WebAssemblyJSStringBuiltinsEnabled(const FeatureContext*);

    static bool WebAuthenticationAttestationFormatsEnabledByRuntimeFlag()
    {
        return WebAuthenticationAttestationFormatsEnabled(nullptr);
    }
    static bool WebAuthenticationAttestationFormatsEnabled(const FeatureContext*);

    static bool WebGPUSubgroupsFeaturesEnabledByRuntimeFlag()
    {
        return WebGPUSubgroupsFeaturesEnabled(nullptr);
    }
    static bool WebGPUSubgroupsFeaturesEnabled(const FeatureContext*);

    static bool WebIdentityDigitalCredentialsEnabledByRuntimeFlag()
    {
        return WebIdentityDigitalCredentialsEnabled(nullptr);
    }
    static bool WebIdentityDigitalCredentialsEnabled(const FeatureContext*);

    static bool WebTransportCustomCertificatesEnabledByRuntimeFlag()
    {
        return WebTransportCustomCertificatesEnabled(nullptr);
    }
    static bool WebTransportCustomCertificatesEnabled(const FeatureContext*);

    static bool WebViewXRequestedWithDeprecationEnabledByRuntimeFlag()
    {
        return WebViewXRequestedWithDeprecationEnabled(nullptr);
    }
    static bool WebViewXRequestedWithDeprecationEnabled(const FeatureContext*);

    static bool WebXRImageTrackingEnabledByRuntimeFlag()
    {
        return WebXRImageTrackingEnabled(nullptr);
    }
    static bool WebXRImageTrackingEnabled(const FeatureContext*);

    static bool WebXRPlaneDetectionEnabledByRuntimeFlag()
    {
        return WebXRPlaneDetectionEnabled(nullptr);
    }
    static bool WebXRPlaneDetectionEnabled(const FeatureContext*);

    static bool IsFeatureEnabledFromString(const std::string& name);

protected:
    // See the comment in RuntimeEnabledFeatures for why these are protected.
    static void SetStableFeaturesEnabled(bool);
    static void SetExperimentalFeaturesEnabled(bool);
    static void SetTestFeaturesEnabled(bool);
    static void SetOriginTrialControlledFeaturesEnabled(bool);

    static void SetFeatureEnabledFromString(const std::string& name, bool enabled);
    static void UpdateStatusFromBaseFeatures();

    static void SetAccelerated2dCanvasEnabled(bool enabled)
    {
        is_accelerated_2d_canvas_enabled_ = enabled;
    }
    static void SetAcceleratedSmallCanvasesEnabled(bool enabled)
    {
        is_accelerated_small_canvases_enabled_ = enabled;
    }
    static void SetAccessibilityAriaVirtualContentEnabled(bool enabled)
    {
        is_accessibility_aria_virtual_content_enabled_ = enabled;
    }
    static void SetAccessibilityExposeDisplayNoneEnabled(bool enabled)
    {
        is_accessibility_expose_display_none_enabled_ = enabled;
    }
    static void SetAccessibilityMinRoleTabbableEnabled(bool enabled)
    {
        is_accessibility_min_role_tabbable_enabled_ = enabled;
    }
    static void SetAccessibilityOSLevelBoldTextEnabled(bool enabled)
    {
        is_accessibility_os_level_bold_text_enabled_ = enabled;
    }
    static void SetAccessibilityProhibitedNamesEnabled(bool enabled)
    {
        is_accessibility_prohibited_names_enabled_ = enabled;
    }
    static void SetAccessibilitySerializationSizeMetricsEnabled(bool enabled)
    {
        is_accessibility_serialization_size_metrics_enabled_ = enabled;
    }
    static void SetAccessibilityUseAXPositionForDocumentMarkersEnabled(bool enabled)
    {
        is_accessibility_use_ax_position_for_document_markers_enabled_ = enabled;
    }
    static void SetAddressSpaceEnabled(bool enabled)
    {
        is_address_space_enabled_ = enabled;
    }
    static void SetAdInterestGroupAPIEnabled(bool enabled)
    {
        is_ad_interest_group_api_enabled_ = enabled;
    }
    static void SetAdjustEndOfNextParagraphIfMovedParagraphIsUpdatedEnabled(bool enabled)
    {
        is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_ = enabled;
    }
    static void SetAdTaggingEnabled(bool enabled)
    {
        is_ad_tagging_enabled_ = enabled;
    }
    static void SetAIPromptAPIEnabled(bool enabled)
    {
        is_ai_prompt_api_enabled_ = enabled;
    }
    static void SetAIPromptAPIForExtensionEnabled(bool enabled)
    {
        is_ai_prompt_api_for_extension_enabled_ = enabled;
    }
    static void SetAIPromptAPIForWebPlatformEnabled(bool enabled)
    {
        is_ai_prompt_api_for_web_platform_enabled_ = enabled;
    }
    static void SetAIRewriterAPIEnabled(bool enabled)
    {
        is_ai_rewriter_api_enabled_ = enabled;
    }
    static void SetAISummarizationAPIEnabled(bool enabled)
    {
        is_ai_summarization_api_enabled_ = enabled;
    }
    static void SetAIWriterAPIEnabled(bool enabled)
    {
        is_ai_writer_api_enabled_ = enabled;
    }
    static void SetAllowContentInitiatedDataUrlNavigationsEnabled(bool enabled)
    {
        is_allow_content_initiated_data_url_navigations_enabled_ = enabled;
    }
    static void SetAllowJavaScriptToResetAutofillStateEnabled(bool enabled)
    {
        is_allow_java_script_to_reset_autofill_state_enabled_ = enabled;
    }
    static void SetAllowPreloadingWithCSPMetaTagEnabled(bool enabled)
    {
        is_allow_preloading_with_csp_meta_tag_enabled_ = enabled;
    }
    static void SetAllowURNsInIframesEnabled(bool enabled)
    {
        is_allow_ur_ns_in_iframes_enabled_ = enabled;
    }
    static void SetAndroidDownloadableFontsMatchingEnabled(bool enabled)
    {
        is_android_downloadable_fonts_matching_enabled_ = enabled;
    }
    static void SetAnimationProgressAPIEnabled(bool enabled)
    {
        is_animation_progress_api_enabled_ = enabled;
    }
    static void SetAnimationWorkletEnabled(bool enabled)
    {
        is_animation_worklet_enabled_ = enabled;
    }
    static void SetAnonymousIframeEnabled(bool enabled)
    {
        is_anonymous_iframe_enabled_ = enabled;
    }
    static void SetAOMAriaRelationshipPropertiesEnabled(bool enabled)
    {
        is_aom_aria_relationship_properties_enabled_ = enabled;
    }
    static void SetAOMAriaRelationshipPropertiesAriaOwnsEnabled(bool enabled)
    {
        is_aom_aria_relationship_properties_aria_owns_enabled_ = enabled;
    }
    static void SetAppTitleEnabled(bool enabled)
    {
        is_app_title_enabled_ = enabled;
    }
    static void SetAriaActionsEnabled(bool enabled)
    {
        is_aria_actions_enabled_ = enabled;
    }
    static void SetAriaNotifyEnabled(bool enabled)
    {
        is_aria_notify_enabled_ = enabled;
    }
    static void SetAriaRowColIndexTextEnabled(bool enabled)
    {
        is_aria_row_col_index_text_enabled_ = enabled;
    }
    static void SetAtomicMoveAPIEnabled(bool enabled)
    {
        is_atomic_move_api_enabled_ = enabled;
    }
    static void SetAttributionReportingEnabled(bool enabled)
    {
        is_attribution_reporting_enabled_ = enabled;
    }
    static void SetAttributionReportingCrossAppWebEnabled(bool enabled)
    {
        is_attribution_reporting_cross_app_web_enabled_ = enabled;
    }
    static void SetAttributionReportingInterfaceEnabled(bool enabled)
    {
        is_attribution_reporting_interface_enabled_ = enabled;
    }
    static void SetAudioContextInterruptedStateEnabled(bool enabled)
    {
        is_audio_context_interrupted_state_enabled_ = enabled;
    }
    static void SetAudioContextOnErrorEnabled(bool enabled)
    {
        is_audio_context_on_error_enabled_ = enabled;
    }
    static void SetAudioContextPlayoutStatsEnabled(bool enabled)
    {
        is_audio_context_playout_stats_enabled_ = enabled;
    }
    static void SetAudioContextSetSinkIdEnabled(bool enabled)
    {
        is_audio_context_set_sink_id_enabled_ = enabled;
    }
    static void SetAudioOutputDevicesEnabled(bool enabled)
    {
        is_audio_output_devices_enabled_ = enabled;
    }
    static void SetAudioVideoTracksEnabled(bool enabled)
    {
        is_audio_video_tracks_enabled_ = enabled;
    }
    static void SetAuraScrollbarUsesNinePatchTrackEnabled(bool enabled)
    {
        is_aura_scrollbar_uses_nine_patch_track_enabled_ = enabled;
    }
    static void SetAuraScrollbarUsesSolidColorThumbEnabled(bool enabled)
    {
        is_aura_scrollbar_uses_solid_color_thumb_enabled_ = enabled;
    }
    static void SetAutoDarkModeEnabled(bool enabled)
    {
        is_auto_dark_mode_enabled_ = enabled;
    }
    static void SetAutomationControlledEnabled(bool enabled)
    {
        is_automation_controlled_enabled_ = enabled;
    }
    static void SetAutoPictureInPictureVideoHeuristicsEnabled(bool enabled)
    {
        is_auto_picture_in_picture_video_heuristics_enabled_ = enabled;
    }
    static void SetBackfaceVisibilityInteropEnabled(bool enabled)
    {
        is_backface_visibility_interop_enabled_ = enabled;
    }
    static void SetBackForwardCacheEnabled(bool enabled)
    {
        is_back_forward_cache_enabled_ = enabled;
    }
    static void SetBackForwardCacheExperimentHTTPHeaderEnabled(bool enabled)
    {
        is_back_forward_cache_experiment_http_header_enabled_ = enabled;
    }
    static void SetBackForwardCacheNotRestoredReasonsEnabled(bool enabled)
    {
        is_back_forward_cache_not_restored_reasons_enabled_ = enabled;
    }
    static void SetBackForwardTransitionsEnabled(bool enabled)
    {
        is_back_forward_transitions_enabled_ = enabled;
    }
    static void SetBackgroundFetchEnabled(bool enabled)
    {
        is_background_fetch_enabled_ = enabled;
    }
    static void SetBarcodeDetectorEnabled(bool enabled)
    {
        is_barcode_detector_enabled_ = enabled;
    }
    static void SetBidiCaretAffinityEnabled(bool enabled)
    {
        is_bidi_caret_affinity_enabled_ = enabled;
    }
    static void SetBlinkExtensionChromeOSEnabled(bool enabled)
    {
        is_blink_extension_chrome_os_enabled_ = enabled;
    }
    static void SetBlinkExtensionChromeOSKioskEnabled(bool enabled)
    {
        is_blink_extension_chrome_os_kiosk_enabled_ = enabled;
    }
    static void SetBlinkExtensionDiagnosticsEnabled(bool enabled)
    {
        is_blink_extension_diagnostics_enabled_ = enabled;
    }
    static void SetBlinkExtensionWebViewEnabled(bool enabled)
    {
        is_blink_extension_web_view_enabled_ = enabled;
    }
    static void SetBlinkExtensionWebViewMediaIntegrityEnabled(bool enabled)
    {
        is_blink_extension_web_view_media_integrity_enabled_ = enabled;
    }
    static void SetBlinkLifecycleScriptForbiddenEnabled(bool enabled)
    {
        is_blink_lifecycle_script_forbidden_enabled_ = enabled;
    }
    static void SetBlinkRuntimeCallStatsEnabled(bool enabled)
    {
        is_blink_runtime_call_stats_enabled_ = enabled;
    }
    static void SetBlockingFocusWithoutUserActivationEnabled(bool enabled)
    {
        is_blocking_focus_without_user_activation_enabled_ = enabled;
    }
    static void SetBoundaryEventDispatchTracksNodeRemovalEnabled(bool enabled)
    {
        is_boundary_event_dispatch_tracks_node_removal_enabled_ = enabled;
    }
    static void SetBoxDecorationBreakEnabled(bool enabled)
    {
        is_box_decoration_break_enabled_ = enabled;
    }
    static void SetBreakIteratorHyphenMinusEnabled(bool enabled)
    {
        is_break_iterator_hyphen_minus_enabled_ = enabled;
    }
    static void SetBrowserVerifiedUserActivationKeyboardEnabled(bool enabled)
    {
        is_browser_verified_user_activation_keyboard_enabled_ = enabled;
    }
    static void SetBrowserVerifiedUserActivationMouseEnabled(bool enabled)
    {
        is_browser_verified_user_activation_mouse_enabled_ = enabled;
    }
    static void SetBufferedBytesConsumerLimitSizeEnabled(bool enabled)
    {
        is_buffered_bytes_consumer_limit_size_enabled_ = enabled;
    }
    static void SetBuiltInAIAPIEnabled(bool enabled)
    {
        is_built_in_aiapi_enabled_ = enabled;
    }
    static void SetBypassPepcSecurityForTestingEnabled(bool enabled)
    {
        is_bypass_pepc_security_for_testing_enabled_ = enabled;
    }
    static void SetCacheStorageCodeCacheHintEnabled(bool enabled)
    {
        is_cache_storage_code_cache_hint_enabled_ = enabled;
    }
    static void SetCalendarPickerMonthPopupButtonDisabledColorEnabled(bool enabled)
    {
        is_calendar_picker_month_popup_button_disabled_color_enabled_ = enabled;
    }
    static void SetCallExitNodeWithoutLayoutObjectEnabled(bool enabled)
    {
        is_call_exit_node_without_layout_object_enabled_ = enabled;
    }
    static void SetCanvas2dCanvasFilterEnabled(bool enabled)
    {
        is_canvas_2d_canvas_filter_enabled_ = enabled;
    }
    static void SetCanvas2dGPUTransferEnabled(bool enabled)
    {
        is_canvas_2d_gpu_transfer_enabled_ = enabled;
    }
    static void SetCanvas2dImageChromiumEnabled(bool enabled)
    {
        is_canvas_2d_image_chromium_enabled_ = enabled;
    }
    static void SetCanvas2dLayersEnabled(bool enabled)
    {
        is_canvas_2d_layers_enabled_ = enabled;
    }
    static void SetCanvas2dLayersWithOptionsEnabled(bool enabled)
    {
        is_canvas_2d_layers_with_options_enabled_ = enabled;
    }
    static void SetCanvas2dMeshEnabled(bool enabled)
    {
        is_canvas_2d_mesh_enabled_ = enabled;
    }
    static void SetCanvas2dTextMetricsShapingEnabled(bool enabled)
    {
        is_canvas_2d_text_metrics_shaping_enabled_ = enabled;
    }
    static void SetCanvasFloatingPointEnabled(bool enabled)
    {
        is_canvas_floating_point_enabled_ = enabled;
    }
    static void SetCanvasHDREnabled(bool enabled)
    {
        is_canvas_hdr_enabled_ = enabled;
    }
    static void SetCanvasImageSmoothingEnabled(bool enabled)
    {
        is_canvas_image_smoothing_enabled_ = enabled;
    }
    static void SetCanvasPlaceElementEnabled(bool enabled)
    {
        is_canvas_place_element_enabled_ = enabled;
    }
    static void SetCanvasUsesArcPaintOpEnabled(bool enabled)
    {
        is_canvas_uses_arc_paint_op_enabled_ = enabled;
    }
    static void SetCapabilityDelegationDisplayCaptureRequestEnabled(bool enabled)
    {
        is_capability_delegation_display_capture_request_enabled_ = enabled;
    }
    static void SetCaptureControllerEnabled(bool enabled)
    {
        is_capture_controller_enabled_ = enabled;
    }
    static void SetCapturedMouseEventsEnabled(bool enabled)
    {
        is_captured_mouse_events_enabled_ = enabled;
    }
    static void SetCapturedSurfaceControlEnabled(bool enabled)
    {
        is_captured_surface_control_enabled_ = enabled;
    }
    static void SetCaptureHandleEnabled(bool enabled)
    {
        is_capture_handle_enabled_ = enabled;
    }
    static void SetCaretPositionFromPointEnabled(bool enabled)
    {
        is_caret_position_from_point_enabled_ = enabled;
    }
    static void SetCCTNewRFMPushBehaviorEnabled(bool enabled)
    {
        is_cct_new_rfm_push_behavior_enabled_ = enabled;
    }
    static void SetCheckIfHighestRootContainsPositionAnchorNodeEnabled(bool enabled)
    {
        is_check_if_highest_root_contains_position_anchor_node_enabled_ = enabled;
    }
    static void SetCheckVisibilityExtraPropertiesEnabled(bool enabled)
    {
        is_check_visibility_extra_properties_enabled_ = enabled;
    }
    static void SetClickToCapturedPointerEnabled(bool enabled)
    {
        is_click_to_captured_pointer_enabled_ = enabled;
    }
    static void SetClipboardItemWithDOMStringSupportEnabled(bool enabled)
    {
        is_clipboard_item_with_dom_string_support_enabled_ = enabled;
    }
    static void SetClipPathRejectEmptyPathsEnabled(bool enabled)
    {
        is_clip_path_reject_empty_paths_enabled_ = enabled;
    }
    static void SetCoalesceSelectionchangeEventEnabled(bool enabled)
    {
        is_coalesce_selectionchange_event_enabled_ = enabled;
    }
    static void SetCoepReflectionEnabled(bool enabled)
    {
        is_coep_reflection_enabled_ = enabled;
    }
    static void SetCompositeBGColorAnimationEnabled(bool enabled)
    {
        is_composite_bg_color_animation_enabled_ = enabled;
    }
    static void SetCompositeBoxShadowAnimationEnabled(bool enabled)
    {
        is_composite_box_shadow_animation_enabled_ = enabled;
    }
    static void SetCompositeClipPathAnimationEnabled(bool enabled)
    {
        is_composite_clip_path_animation_enabled_ = enabled;
    }
    static void SetCompositedAnimationsCancelledAsynchronouslyEnabled(bool enabled)
    {
        is_composited_animations_cancelled_asynchronously_enabled_ = enabled;
    }
    static void SetCompositedSelectionUpdateEnabled(bool enabled)
    {
        is_composited_selection_update_enabled_ = enabled;
    }
    static void SetCompositionForegroundMarkersEnabled(bool enabled)
    {
        is_composition_foreground_markers_enabled_ = enabled;
    }
    static void SetCompressionDictionaryTransportEnabled(bool enabled)
    {
        is_compression_dictionary_transport_enabled_ = enabled;
    }
    static void SetCompressionDictionaryTransportBackendEnabled(bool enabled)
    {
        is_compression_dictionary_transport_backend_enabled_ = enabled;
    }
    static void SetComputedAccessibilityInfoEnabled(bool enabled)
    {
        is_computed_accessibility_info_enabled_ = enabled;
    }
    static void SetComputePressureEnabled(bool enabled)
    {
        is_compute_pressure_enabled_ = enabled;
    }
    static void SetConcurrentViewTransitionsSPAEnabled(bool enabled)
    {
        is_concurrent_view_transitions_spa_enabled_ = enabled;
    }
    static void SetContactsManagerEnabled(bool enabled)
    {
        is_contacts_manager_enabled_ = enabled;
    }
    static void SetContactsManagerExtraPropertiesEnabled(bool enabled)
    {
        is_contacts_manager_extra_properties_enabled_ = enabled;
    }
    static void SetContainerTypeNoLayoutContainmentEnabled(bool enabled)
    {
        is_container_type_no_layout_containment_enabled_ = enabled;
    }
    static void SetContentIndexEnabled(bool enabled)
    {
        is_content_index_enabled_ = enabled;
    }
    static void SetContextMenuEnabled(bool enabled)
    {
        is_context_menu_enabled_ = enabled;
    }
    static void SetContinueEventTimingRecordingWhenBufferIsFullEnabled(bool enabled)
    {
        is_continue_event_timing_recording_when_buffer_is_full_enabled_ = enabled;
    }
    static void SetControlledFrameEnabled(bool enabled)
    {
        is_controlled_frame_enabled_ = enabled;
    }
    static void SetCookieDeprecationFacilitatedTestingEnabled(bool enabled)
    {
        is_cookie_deprecation_facilitated_testing_enabled_ = enabled;
    }
    static void SetCooperativeSchedulingEnabled(bool enabled)
    {
        is_cooperative_scheduling_enabled_ = enabled;
    }
    static void SetCoopRestrictPropertiesEnabled(bool enabled)
    {
        is_coop_restrict_properties_enabled_ = enabled;
    }
    static void SetCorsRFC1918Enabled(bool enabled)
    {
        is_cors_rfc_1918_enabled_ = enabled;
    }
    static void SetCreateInputShadowTreeDuringLayoutEnabled(bool enabled)
    {
        is_create_input_shadow_tree_during_layout_enabled_ = enabled;
    }
    static void SetCredentialManagerReportEnabled(bool enabled)
    {
        is_credential_manager_report_enabled_ = enabled;
    }
    static void SetCrossFramePerformanceTimelineEnabled(bool enabled)
    {
        is_cross_frame_performance_timeline_enabled_ = enabled;
    }
    static void SetCSSAccentColorKeywordEnabled(bool enabled)
    {
        is_css_accent_color_keyword_enabled_ = enabled;
    }
    static void SetCSSAdvancedAttrFunctionEnabled(bool enabled)
    {
        is_css_advanced_attr_function_enabled_ = enabled;
    }
    static void SetCSSAnchorScopeEnabled(bool enabled)
    {
        is_css_anchor_scope_enabled_ = enabled;
    }
    static void SetCSSAnchorSizeInsetsMarginsEnabled(bool enabled)
    {
        is_css_anchor_size_insets_margins_enabled_ = enabled;
    }
    static void SetCSSAtPropertyStringSyntaxEnabled(bool enabled)
    {
        is_css_at_property_string_syntax_enabled_ = enabled;
    }
    static void SetCSSAtRuleCounterStyleImageSymbolsEnabled(bool enabled)
    {
        is_css_at_rule_counter_style_image_symbols_enabled_ = enabled;
    }
    static void SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled(bool enabled)
    {
        is_css_at_rule_counter_style_speak_as_descriptor_enabled_ = enabled;
    }
    static void SetCSSBackgroundClipUnprefixEnabled(bool enabled)
    {
        is_css_background_clip_unprefix_enabled_ = enabled;
    }
    static void SetCSSCalcSimplificationAndSerializationEnabled(bool enabled)
    {
        is_css_calc_simplification_and_serialization_enabled_ = enabled;
    }
    static void SetCSSCalcSizeFunctionEnabled(bool enabled)
    {
        is_css_calc_size_function_enabled_ = enabled;
    }
    static void SetCSSCaretAnimationEnabled(bool enabled)
    {
        is_css_caret_animation_enabled_ = enabled;
    }
    static void SetCSSCascadeCorrectScopeEnabled(bool enabled)
    {
        is_css_cascade_correct_scope_enabled_ = enabled;
    }
    static void SetCSSCaseSensitiveSelectorEnabled(bool enabled)
    {
        is_css_case_sensitive_selector_enabled_ = enabled;
    }
    static void SetCSSColorContrastEnabled(bool enabled)
    {
        is_css_color_contrast_enabled_ = enabled;
    }
    static void SetCSSColorTypedOMEnabled(bool enabled)
    {
        is_css_color_typed_om_enabled_ = enabled;
    }
    static void SetCSSComputedStyleFullPseudoElementParserEnabled(bool enabled)
    {
        is_css_computed_style_full_pseudo_element_parser_enabled_ = enabled;
    }
    static void SetCSSContentVisibilityImpliesContainIntrinsicSizeAutoEnabled(bool enabled)
    {
        is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_ = enabled;
    }
    static void SetCSSCrossFadeEnabled(bool enabled)
    {
        is_css_cross_fade_enabled_ = enabled;
    }
    static void SetCSSCustomStateDeprecatedSyntaxEnabled(bool enabled)
    {
        is_css_custom_state_deprecated_syntax_enabled_ = enabled;
    }
    static void SetCSSCustomStateNewSyntaxEnabled(bool enabled)
    {
        is_css_custom_state_new_syntax_enabled_ = enabled;
    }
    static void SetCSSDynamicRangeLimitEnabled(bool enabled)
    {
        is_css_dynamic_range_limit_enabled_ = enabled;
    }
    static void SetCSSEnumeratedCustomPropertiesEnabled(bool enabled)
    {
        is_css_enumerated_custom_properties_enabled_ = enabled;
    }
    static void SetCSSExponentialFunctionsEnabled(bool enabled)
    {
        is_css_exponential_functions_enabled_ = enabled;
    }
    static void SetCSSFlatTreeContainerEnabled(bool enabled)
    {
        is_css_flat_tree_container_enabled_ = enabled;
    }
    static void SetCSSFontSizeAdjustEnabled(bool enabled)
    {
        is_css_font_size_adjust_enabled_ = enabled;
    }
    static void SetCSSFunctionsEnabled(bool enabled)
    {
        is_css_functions_enabled_ = enabled;
    }
    static void SetCSSGapDecorationEnabled(bool enabled)
    {
        is_css_gap_decoration_enabled_ = enabled;
    }
    static void SetCSSHexAlphaColorEnabled(bool enabled)
    {
        is_css_hex_alpha_color_enabled_ = enabled;
    }
    static void SetCSSInertEnabled(bool enabled)
    {
        is_css_inert_enabled_ = enabled;
    }
    static void SetCSSInsetAreaPropertyEnabled(bool enabled)
    {
        is_css_inset_area_property_enabled_ = enabled;
    }
    static void SetCSSKeyframesRuleLengthEnabled(bool enabled)
    {
        is_css_keyframes_rule_length_enabled_ = enabled;
    }
    static void SetCSSLayoutAPIEnabled(bool enabled)
    {
        is_css_layout_api_enabled_ = enabled;
    }
    static void SetCSSLazyParsingFastPathEnabled(bool enabled)
    {
        is_css_lazy_parsing_fast_path_enabled_ = enabled;
    }
    static void SetCSSLineClampEnabled(bool enabled)
    {
        is_css_line_clamp_enabled_ = enabled;
    }
    static void SetCSSLineClampWebkitBoxBlockificationEnabled(bool enabled)
    {
        is_css_line_clamp_webkit_box_blockification_enabled_ = enabled;
    }
    static void SetCSSLogicalOverflowEnabled(bool enabled)
    {
        is_css_logical_overflow_enabled_ = enabled;
    }
    static void SetCSSMarkerNestedPseudoElementEnabled(bool enabled)
    {
        is_css_marker_nested_pseudo_element_enabled_ = enabled;
    }
    static void SetCSSMasonryLayoutEnabled(bool enabled)
    {
        is_css_masonry_layout_enabled_ = enabled;
    }
    static void SetCSSMixinsEnabled(bool enabled)
    {
        is_css_mixins_enabled_ = enabled;
    }
    static void SetCSSNestedDeclarationsEnabled(bool enabled)
    {
        is_css_nested_declarations_enabled_ = enabled;
    }
    static void SetCSSNestedPseudoElementsEnabled(bool enabled)
    {
        is_css_nested_pseudo_elements_enabled_ = enabled;
    }
    static void SetCSSOverflowContainerQueriesEnabled(bool enabled)
    {
        is_css_overflow_container_queries_enabled_ = enabled;
    }
    static void SetCSSPaintAPIArgumentsEnabled(bool enabled)
    {
        is_css_paint_api_arguments_enabled_ = enabled;
    }
    static void SetCSSParserIgnoreCharsetForURLsEnabled(bool enabled)
    {
        is_css_parser_ignore_charset_for_urls_enabled_ = enabled;
    }
    static void SetCSSPartAllowsMoreSelectorsAfterEnabled(bool enabled)
    {
        is_css_part_allows_more_selectors_after_enabled_ = enabled;
    }
    static void SetCSSPositionAreaValueEnabled(bool enabled)
    {
        is_css_position_area_value_enabled_ = enabled;
    }
    static void SetCSSPositionStickyStaticScrollPositionEnabled(bool enabled)
    {
        is_css_position_sticky_static_scroll_position_enabled_ = enabled;
    }
    static void SetCSSProgressNotationEnabled(bool enabled)
    {
        is_css_progress_notation_enabled_ = enabled;
    }
    static void SetCSSPseudoColumnEnabled(bool enabled)
    {
        is_css_pseudo_column_enabled_ = enabled;
    }
    static void SetCSSPseudoHasSlottedEnabled(bool enabled)
    {
        is_css_pseudo_has_slotted_enabled_ = enabled;
    }
    static void SetCSSPseudoOpenClosedEnabled(bool enabled)
    {
        is_css_pseudo_open_closed_enabled_ = enabled;
    }
    static void SetCSSPseudoPlayingPausedEnabled(bool enabled)
    {
        is_css_pseudo_playing_paused_enabled_ = enabled;
    }
    static void SetCSSPseudoScrollButtonsEnabled(bool enabled)
    {
        is_css_pseudo_scroll_buttons_enabled_ = enabled;
    }
    static void SetCSSPseudoScrollMarkersEnabled(bool enabled)
    {
        is_css_pseudo_scroll_markers_enabled_ = enabled;
    }
    static void SetCSSReadingFlowEnabled(bool enabled)
    {
        is_css_reading_flow_enabled_ = enabled;
    }
    static void SetCSSRelativeColorEnabled(bool enabled)
    {
        is_css_relative_color_enabled_ = enabled;
    }
    static void SetCSSRelativeColorLateResolveAlwaysEnabled(bool enabled)
    {
        is_css_relative_color_late_resolve_always_enabled_ = enabled;
    }
    static void SetCSSRelativeColorPreserveNoneEnabled(bool enabled)
    {
        is_css_relative_color_preserve_none_enabled_ = enabled;
    }
    static void SetCSSRelativeColorSupportsCurrentcolorEnabled(bool enabled)
    {
        is_css_relative_color_supports_currentcolor_enabled_ = enabled;
    }
    static void SetCSSResizeAutoEnabled(bool enabled)
    {
        is_css_resize_auto_enabled_ = enabled;
    }
    static void SetCSSScrollSnapChangeEventEnabled(bool enabled)
    {
        is_css_scroll_snap_change_event_enabled_ = enabled;
    }
    static void SetCSSScrollSnapChangingEventEnabled(bool enabled)
    {
        is_css_scroll_snap_changing_event_enabled_ = enabled;
    }
    static void SetCSSScrollSnapEventsEnabled(bool enabled)
    {
        is_css_scroll_snap_events_enabled_ = enabled;
    }
    static void SetCSSScrollStartEnabled(bool enabled)
    {
        is_css_scroll_start_enabled_ = enabled;
    }
    static void SetCSSScrollStartTargetEnabled(bool enabled)
    {
        is_css_scroll_start_target_enabled_ = enabled;
    }
    static void SetCSSScrollStateContainerQueriesEnabled(bool enabled)
    {
        is_css_scroll_state_container_queries_enabled_ = enabled;
    }
    static void SetCSSSelectorFragmentAnchorEnabled(bool enabled)
    {
        is_css_selector_fragment_anchor_enabled_ = enabled;
    }
    static void SetCSSSignRelatedFunctionsEnabled(bool enabled)
    {
        is_css_sign_related_functions_enabled_ = enabled;
    }
    static void SetCSSSnapContainerQueriesEnabled(bool enabled)
    {
        is_css_snap_container_queries_enabled_ = enabled;
    }
    static void SetCSSSteppedValueFunctionsEnabled(bool enabled)
    {
        is_css_stepped_value_functions_enabled_ = enabled;
    }
    static void SetCSSStickyContainerQueriesEnabled(bool enabled)
    {
        is_css_sticky_container_queries_enabled_ = enabled;
    }
    static void SetCSSSupportsAtRuleFunctionEnabled(bool enabled)
    {
        is_css_supports_at_rule_function_enabled_ = enabled;
    }
    static void SetCSSSupportsForImportRulesEnabled(bool enabled)
    {
        is_css_supports_for_import_rules_enabled_ = enabled;
    }
    static void SetCSSSystemAccentColorEnabled(bool enabled)
    {
        is_css_system_accent_color_enabled_ = enabled;
    }
    static void SetCSSTextAutoSpaceEnabled(bool enabled)
    {
        is_css_text_auto_space_enabled_ = enabled;
    }
    static void SetCSSTextBoxTrimEnabled(bool enabled)
    {
        is_css_text_box_trim_enabled_ = enabled;
    }
    static void SetCSSTextSpacingEnabled(bool enabled)
    {
        is_css_text_spacing_enabled_ = enabled;
    }
    static void SetCSSTreeScopedTimelinesEnabled(bool enabled)
    {
        is_css_tree_scoped_timelines_enabled_ = enabled;
    }
    static void SetCSSUserSelectContainEnabled(bool enabled)
    {
        is_css_user_select_contain_enabled_ = enabled;
    }
    static void SetCSSVideoDynamicRangeMediaQueriesEnabled(bool enabled)
    {
        is_css_video_dynamic_range_media_queries_enabled_ = enabled;
    }
    static void SetCSSViewTransitionAutoNameEnabled(bool enabled)
    {
        is_css_view_transition_auto_name_enabled_ = enabled;
    }
    static void SetCSSViewTransitionClassEnabled(bool enabled)
    {
        is_css_view_transition_class_enabled_ = enabled;
    }
    static void SetCursorAnchorInfoMojoPipeEnabled(bool enabled)
    {
        is_cursor_anchor_info_mojo_pipe_enabled_ = enabled;
    }
    static void SetCustomizableSelectEnabled(bool enabled)
    {
        is_customizable_select_enabled_ = enabled;
    }
    static void SetDatabaseEnabled(bool enabled)
    {
        is_database_enabled_ = enabled;
    }
    static void SetDeprecatedRequestAdapterInfoEnabled(bool enabled)
    {
        is_deprecated_request_adapter_info_enabled_ = enabled;
    }
    static void SetDeprecateUnloadOptOutEnabled(bool enabled)
    {
        is_deprecate_unload_opt_out_enabled_ = enabled;
    }
    static void SetDesktopCaptureDisableLocalEchoControlEnabled(bool enabled)
    {
        is_desktop_capture_disable_local_echo_control_enabled_ = enabled;
    }
    static void SetDesktopPWAsAdditionalWindowingControlsEnabled(bool enabled)
    {
        is_desktop_pw_as_additional_windowing_controls_enabled_ = enabled;
    }
    static void SetDesktopPWAsSubAppsEnabled(bool enabled)
    {
        is_desktop_pw_as_sub_apps_enabled_ = enabled;
    }
    static void SetDetailsStylingEnabled(bool enabled)
    {
        is_details_styling_enabled_ = enabled;
    }
    static void SetDeviceAttributesEnabled(bool enabled)
    {
        is_device_attributes_enabled_ = enabled;
    }
    static void SetDeviceOrientationRequestPermissionEnabled(bool enabled)
    {
        is_device_orientation_request_permission_enabled_ = enabled;
    }
    static void SetDevicePostureEnabled(bool enabled)
    {
        is_device_posture_enabled_ = enabled;
    }
    static void SetDialogCloseWhenOpenRemovedEnabled(bool enabled)
    {
        is_dialog_close_when_open_removed_enabled_ = enabled;
    }
    static void SetDialogElementToggleEventsEnabled(bool enabled)
    {
        is_dialog_element_toggle_events_enabled_ = enabled;
    }
    static void SetDialogNewFocusBehaviorEnabled(bool enabled)
    {
        is_dialog_new_focus_behavior_enabled_ = enabled;
    }
    static void SetDigitalGoodsEnabled(bool enabled)
    {
        is_digital_goods_enabled_ = enabled;
    }
    static void SetDigitalGoodsV2_1Enabled(bool enabled)
    {
        is_digital_goods_v_2_1_enabled_ = enabled;
    }
    static void SetDirAutoFixSlotExclusionsEnabled(bool enabled)
    {
        is_dir_auto_fix_slot_exclusions_enabled_ = enabled;
    }
    static void SetDirectSocketsEnabled(bool enabled)
    {
        is_direct_sockets_enabled_ = enabled;
    }
    static void SetDisableAhemAntialiasEnabled(bool enabled)
    {
        is_disable_ahem_antialias_enabled_ = enabled;
    }
    static void SetDisableDifferentOriginSubframeDialogSuppressionEnabled(bool enabled)
    {
        is_disable_different_origin_subframe_dialog_suppression_enabled_ = enabled;
    }
    static void SetDisableHardwareNoiseSuppressionEnabled(bool enabled)
    {
        is_disable_hardware_noise_suppression_enabled_ = enabled;
    }
    static void SetDisableReduceAcceptLanguageEnabled(bool enabled)
    {
        is_disable_reduce_accept_language_enabled_ = enabled;
    }
    static void SetDisableSelectAllForEmptyTextEnabled(bool enabled)
    {
        is_disable_select_all_for_empty_text_enabled_ = enabled;
    }
    static void SetDisableThirdPartyStoragePartitioning2Enabled(bool enabled)
    {
        is_disable_third_party_storage_partitioning_2_enabled_ = enabled;
    }
    static void SetDispatchBeforeInputForSpinButtonInteractionsEnabled(bool enabled)
    {
        is_dispatch_before_input_for_spin_button_interactions_enabled_ = enabled;
    }
    static void SetDispatchHiddenVisibilityTransitionsEnabled(bool enabled)
    {
        is_dispatch_hidden_visibility_transitions_enabled_ = enabled;
    }
    static void SetDispatchSelectionchangeEventPerElementEnabled(bool enabled)
    {
        is_dispatch_selectionchange_event_per_element_enabled_ = enabled;
    }
    static void SetDisplayContentsFocusableEnabled(bool enabled)
    {
        is_display_contents_focusable_enabled_ = enabled;
    }
    static void SetDisplayCutoutAPIEnabled(bool enabled)
    {
        is_display_cutout_api_enabled_ = enabled;
    }
    static void SetDocumentCookieEnabled(bool enabled)
    {
        is_document_cookie_enabled_ = enabled;
    }
    static void SetDocumentDomainEnabled(bool enabled)
    {
        is_document_domain_enabled_ = enabled;
    }
    static void SetDocumentInstallChunkingEnabled(bool enabled)
    {
        is_document_install_chunking_enabled_ = enabled;
    }
    static void SetDocumentIsolationPolicyEnabled(bool enabled)
    {
        is_document_isolation_policy_enabled_ = enabled;
    }
    static void SetDocumentOpenOriginAliasRemovalEnabled(bool enabled)
    {
        is_document_open_origin_alias_removal_enabled_ = enabled;
    }
    static void SetDocumentOpenSandboxInheritanceRemovalEnabled(bool enabled)
    {
        is_document_open_sandbox_inheritance_removal_enabled_ = enabled;
    }
    static void SetDocumentPictureInPictureAPIEnabled(bool enabled)
    {
        is_document_picture_in_picture_api_enabled_ = enabled;
    }
    static void SetDocumentPictureInPicturePreferInitialPlacementEnabled(bool enabled)
    {
        is_document_picture_in_picture_prefer_initial_placement_enabled_ = enabled;
    }
    static void SetDocumentPictureInPictureUserActivationEnabled(bool enabled)
    {
        is_document_picture_in_picture_user_activation_enabled_ = enabled;
    }
    static void SetDocumentPolicyDocumentDomainEnabled(bool enabled)
    {
        is_document_policy_document_domain_enabled_ = enabled;
    }
    static void SetDocumentPolicyExpectNoLinkedResourcesEnabled(bool enabled)
    {
        is_document_policy_expect_no_linked_resources_enabled_ = enabled;
    }
    static void SetDocumentPolicyIncludeJSCallStacksInCrashReportsEnabled(bool enabled)
    {
        is_document_policy_include_js_call_stacks_in_crash_reports_enabled_ = enabled;
    }
    static void SetDocumentPolicyNegotiationEnabled(bool enabled)
    {
        is_document_policy_negotiation_enabled_ = enabled;
    }
    static void SetDocumentPolicySyncXHREnabled(bool enabled)
    {
        is_document_policy_sync_xhr_enabled_ = enabled;
    }
    static void SetDocumentRenderBlockingEnabled(bool enabled)
    {
        is_document_render_blocking_enabled_ = enabled;
    }
    static void SetDocumentWriteEnabled(bool enabled)
    {
        is_document_write_enabled_ = enabled;
    }
    static void SetDOMPartsAPIEnabled(bool enabled)
    {
        is_dom_parts_api_enabled_ = enabled;
    }
    static void SetDOMPartsAPIMinimalEnabled(bool enabled)
    {
        is_dom_parts_api_minimal_enabled_ = enabled;
    }
    static void SetDropUrlAsPlainTextInPlainTextOnlyEditablePositionEnabled(bool enabled)
    {
        is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_ = enabled;
    }
    static void SetDynamicSafeAreaInsetsEnabled(bool enabled)
    {
        is_dynamic_safe_area_insets_enabled_ = enabled;
    }
    static void SetDynamicSafeAreaInsetsOnScrollEnabled(bool enabled)
    {
        is_dynamic_safe_area_insets_on_scroll_enabled_ = enabled;
    }
    static void SetElementCaptureEnabled(bool enabled)
    {
        is_element_capture_enabled_ = enabled;
    }
    static void SetElementGetInnerHTMLEnabled(bool enabled)
    {
        is_element_get_inner_html_enabled_ = enabled;
    }
    static void SetEnforceAnonymityExposureEnabled(bool enabled)
    {
        is_enforce_anonymity_exposure_enabled_ = enabled;
    }
    static void SetEscapeLtGtInAttributesEnabled(bool enabled)
    {
        is_escape_lt_gt_in_attributes_enabled_ = enabled;
    }
    static void SetEventTimingHandleKeyboardEventSimulatedClickEnabled(bool enabled)
    {
        is_event_timing_handle_keyboard_event_simulated_click_enabled_ = enabled;
    }
    static void SetEventTimingInteractionCountEnabled(bool enabled)
    {
        is_event_timing_interaction_count_enabled_ = enabled;
    }
    static void SetEventTimingSelectionAutoScrollNoInteractionIdEnabled(bool enabled)
    {
        is_event_timing_selection_auto_scroll_no_interaction_id_enabled_ = enabled;
    }
    static void SetEventTimingTapStopScrollNoInteractionIdEnabled(bool enabled)
    {
        is_event_timing_tap_stop_scroll_no_interaction_id_enabled_ = enabled;
    }
    static void SetExcludeTransparentTextsFromBeingLcpEligibleEnabled(bool enabled)
    {
        is_exclude_transparent_texts_from_being_lcp_eligible_enabled_ = enabled;
    }
    static void SetExperimentalContentSecurityPolicyFeaturesEnabled(bool enabled)
    {
        is_experimental_content_security_policy_features_enabled_ = enabled;
    }
    static void SetExperimentalJSProfilerMarkersEnabled(bool enabled)
    {
        is_experimental_js_profiler_markers_enabled_ = enabled;
    }
    static void SetExperimentalMachineLearningNeuralNetworkEnabled(bool enabled)
    {
        is_experimental_machine_learning_neural_network_enabled_ = enabled;
    }
    static void SetExperimentalPoliciesEnabled(bool enabled)
    {
        is_experimental_policies_enabled_ = enabled;
    }
    static void SetExposeCoarsenedRenderTimeEnabled(bool enabled)
    {
        is_expose_coarsened_render_time_enabled_ = enabled;
    }
    static void SetExposeRenderTimeNonTaoDelayedImageEnabled(bool enabled)
    {
        is_expose_render_time_non_tao_delayed_image_enabled_ = enabled;
    }
    static void SetExtendedTextMetricsEnabled(bool enabled)
    {
        is_extended_text_metrics_enabled_ = enabled;
    }
    static void SetEyeDropperAPIEnabled(bool enabled)
    {
        is_eye_dropper_api_enabled_ = enabled;
    }
    static void SetFaceDetectorEnabled(bool enabled)
    {
        is_face_detector_enabled_ = enabled;
    }
    static void SetFastNonCompositedScrollHitTestEnabled(bool enabled)
    {
        is_fast_non_composited_scroll_hit_test_enabled_ = enabled;
    }
    static void SetFastPathSingleSelectorExactMatchEnabled(bool enabled)
    {
        is_fast_path_single_selector_exact_match_enabled_ = enabled;
    }
    static void SetFastPositionIteratorEnabled(bool enabled)
    {
        is_fast_position_iterator_enabled_ = enabled;
    }
    static void SetFedCmEnabled(bool enabled)
    {
        is_fed_cm_enabled_ = enabled;
    }
    static void SetFedCmAuthzEnabled(bool enabled)
    {
        is_fed_cm_authz_enabled_ = enabled;
    }
    static void SetFedCmAutoSelectedFlagEnabled(bool enabled)
    {
        is_fed_cm_auto_selected_flag_enabled_ = enabled;
    }
    static void SetFedCmButtonModeEnabled(bool enabled)
    {
        is_fed_cm_button_mode_enabled_ = enabled;
    }
    static void SetFedCmDisconnectEnabled(bool enabled)
    {
        is_fed_cm_disconnect_enabled_ = enabled;
    }
    static void SetFedCmDomainHintEnabled(bool enabled)
    {
        is_fed_cm_domain_hint_enabled_ = enabled;
    }
    static void SetFedCmErrorEnabled(bool enabled)
    {
        is_fed_cm_error_enabled_ = enabled;
    }
    static void SetFedCmIdPRegistrationEnabled(bool enabled)
    {
        is_fed_cm_id_p_registration_enabled_ = enabled;
    }
    static void SetFedCmIdpSigninStatusEnabled(bool enabled)
    {
        is_fed_cm_idp_signin_status_enabled_ = enabled;
    }
    static void SetFedCmMultipleIdentityProvidersEnabled(bool enabled)
    {
        is_fed_cm_multiple_identity_providers_enabled_ = enabled;
    }
    static void SetFedCmSelectiveDisclosureEnabled(bool enabled)
    {
        is_fed_cm_selective_disclosure_enabled_ = enabled;
    }
    static void SetFedCmWithStorageAccessAPIEnabled(bool enabled)
    {
        is_fed_cm_with_storage_access_api_enabled_ = enabled;
    }
    static void SetFencedFramesEnabled(bool enabled)
    {
        is_fenced_frames_enabled_ = enabled;
    }
    static void SetFencedFramesAPIChangesEnabled(bool enabled)
    {
        is_fenced_frames_api_changes_enabled_ = enabled;
    }
    static void SetFencedFramesDefaultModeEnabled(bool enabled)
    {
        is_fenced_frames_default_mode_enabled_ = enabled;
    }
    static void SetFencedFramesLocalUnpartitionedDataAccessEnabled(bool enabled)
    {
        is_fenced_frames_local_unpartitioned_data_access_enabled_ = enabled;
    }
    static void SetFetchBodyBytesEnabled(bool enabled)
    {
        is_fetch_body_bytes_enabled_ = enabled;
    }
    static void SetFetchLaterAPIEnabled(bool enabled)
    {
        is_fetch_later_api_enabled_ = enabled;
    }
    static void SetFetchUploadStreamingEnabled(bool enabled)
    {
        is_fetch_upload_streaming_enabled_ = enabled;
    }
    static void SetFileHandlingEnabled(bool enabled)
    {
        is_file_handling_enabled_ = enabled;
    }
    static void SetFileHandlingIconsEnabled(bool enabled)
    {
        is_file_handling_icons_enabled_ = enabled;
    }
    static void SetFileSystemEnabled(bool enabled)
    {
        is_file_system_enabled_ = enabled;
    }
    static void SetFileSystemAccessEnabled(bool enabled)
    {
        is_file_system_access_enabled_ = enabled;
    }
    static void SetFileSystemAccessAPIExperimentalEnabled(bool enabled)
    {
        is_file_system_access_api_experimental_enabled_ = enabled;
    }
    static void SetFileSystemAccessGetCloudIdentifiersEnabled(bool enabled)
    {
        is_file_system_access_get_cloud_identifiers_enabled_ = enabled;
    }
    static void SetFileSystemAccessLocalEnabled(bool enabled)
    {
        is_file_system_access_local_enabled_ = enabled;
    }
    static void SetFileSystemAccessLockingSchemeEnabled(bool enabled)
    {
        is_file_system_access_locking_scheme_enabled_ = enabled;
    }
    static void SetFileSystemAccessOriginPrivateEnabled(bool enabled)
    {
        is_file_system_access_origin_private_enabled_ = enabled;
    }
    static void SetFileSystemObserverEnabled(bool enabled)
    {
        is_file_system_observer_enabled_ = enabled;
    }
    static void SetFileSystemObserverUnobserveEnabled(bool enabled)
    {
        is_file_system_observer_unobserve_enabled_ = enabled;
    }
    static void SetFindDecomposedInShortTextEnabled(bool enabled)
    {
        is_find_decomposed_in_short_text_enabled_ = enabled;
    }
    static void SetFindRubyInPageEnabled(bool enabled)
    {
        is_find_ruby_in_page_enabled_ = enabled;
    }
    static void SetFindTextInReadonlyTextInputEnabled(bool enabled)
    {
        is_find_text_in_readonly_text_input_enabled_ = enabled;
    }
    static void SetFindTextSkipCollapsedTextEnabled(bool enabled)
    {
        is_find_text_skip_collapsed_text_enabled_ = enabled;
    }
    static void SetFledgeEnabled(bool enabled)
    {
        is_fledge_enabled_ = enabled;
    }
    static void SetFledgeAuctionDealSupportEnabled(bool enabled)
    {
        is_fledge_auction_deal_support_enabled_ = enabled;
    }
    static void SetFledgeBiddingAndAuctionServerAPIEnabled(bool enabled)
    {
        is_fledge_bidding_and_auction_server_api_enabled_ = enabled;
    }
    static void SetFledgeCustomMaxAuctionAdComponentsEnabled(bool enabled)
    {
        is_fledge_custom_max_auction_ad_components_enabled_ = enabled;
    }
    static void SetFledgeDeprecatedRenderURLReplacementsEnabled(bool enabled)
    {
        is_fledge_deprecated_render_url_replacements_enabled_ = enabled;
    }
    static void SetFledgeDirectFromSellerSignalsHeaderAdSlotEnabled(bool enabled)
    {
        is_fledge_direct_from_seller_signals_header_ad_slot_enabled_ = enabled;
    }
    static void SetFledgeMultiBidEnabled(bool enabled)
    {
        is_fledge_multi_bid_enabled_ = enabled;
    }
    static void SetFledgeRealTimeReportingEnabled(bool enabled)
    {
        is_fledge_real_time_reporting_enabled_ = enabled;
    }
    static void SetFledgeReportingTimeoutEnabled(bool enabled)
    {
        is_fledge_reporting_timeout_enabled_ = enabled;
    }
    static void SetFledgeSellerNonceEnabled(bool enabled)
    {
        is_fledge_seller_nonce_enabled_ = enabled;
    }
    static void SetFledgeTrustedSignalsKVv2SupportEnabled(bool enabled)
    {
        is_fledge_trusted_signals_k_vv_2_support_enabled_ = enabled;
    }
    static void SetFluentOverlayScrollbarsEnabled(bool enabled)
    {
        is_fluent_overlay_scrollbars_enabled_ = enabled;
    }
    static void SetFluentScrollbarsEnabled(bool enabled)
    {
        is_fluent_scrollbars_enabled_ = enabled;
    }
    static void SetFluentScrollbarUsesNinePatchTrackEnabled(bool enabled)
    {
        is_fluent_scrollbar_uses_nine_patch_track_enabled_ = enabled;
    }
    static void SetFocusgroupEnabled(bool enabled)
    {
        is_focusgroup_enabled_ = enabled;
    }
    static void SetFontAccessEnabled(bool enabled)
    {
        is_font_access_enabled_ = enabled;
    }
    static void SetFontationsFontBackendEnabled(bool enabled)
    {
        is_fontations_font_backend_enabled_ = enabled;
    }
    static void SetFontationsForSelectedFormatsEnabled(bool enabled)
    {
        is_fontations_for_selected_formats_enabled_ = enabled;
    }
    static void SetFontFamilyPostscriptMatchingCTMigrationEnabled(bool enabled)
    {
        is_font_family_postscript_matching_ct_migration_enabled_ = enabled;
    }
    static void SetFontFamilyStyleMatchingCTMigrationEnabled(bool enabled)
    {
        is_font_family_style_matching_ct_migration_enabled_ = enabled;
    }
    static void SetFontPresentWinEnabled(bool enabled)
    {
        is_font_present_win_enabled_ = enabled;
    }
    static void SetFontSrcLocalMatchingEnabled(bool enabled)
    {
        is_font_src_local_matching_enabled_ = enabled;
    }
    static void SetFontSystemFallbackNotoCjkEnabled(bool enabled)
    {
        is_font_system_fallback_noto_cjk_enabled_ = enabled;
    }
    static void SetFontVariantEmojiEnabled(bool enabled)
    {
        is_font_variant_emoji_enabled_ = enabled;
    }
    static void SetFontVariationSequencesEnabled(bool enabled)
    {
        is_font_variation_sequences_enabled_ = enabled;
    }
    static void SetForcedColorsEnabled(bool enabled)
    {
        is_forced_colors_enabled_ = enabled;
    }
    static void SetForcedColorsPreserveParentColorEnabled(bool enabled)
    {
        is_forced_colors_preserve_parent_color_enabled_ = enabled;
    }
    static void SetForceEagerMeasureMemoryEnabled(bool enabled)
    {
        is_force_eager_measure_memory_enabled_ = enabled;
    }
    static void SetForceReduceMotionEnabled(bool enabled)
    {
        is_force_reduce_motion_enabled_ = enabled;
    }
    static void SetForceTallerSelectPopupEnabled(bool enabled)
    {
        is_force_taller_select_popup_enabled_ = enabled;
    }
    static void SetFormControlRestoreStateIfAutocompleteOffEnabled(bool enabled)
    {
        is_form_control_restore_state_if_autocomplete_off_enabled_ = enabled;
    }
    static void SetFormControlsVerticalWritingModeDirectionSupportEnabled(bool enabled)
    {
        is_form_controls_vertical_writing_mode_direction_support_enabled_ = enabled;
    }
    static void SetFractionalScrollOffsetsEnabled(bool enabled)
    {
        is_fractional_scroll_offsets_enabled_ = enabled;
    }
    static void SetFreezeFramesOnVisibilityEnabled(bool enabled)
    {
        is_freeze_frames_on_visibility_enabled_ = enabled;
    }
    static void SetGamepadMultitouchEnabled(bool enabled)
    {
        is_gamepad_multitouch_enabled_ = enabled;
    }
    static void SetGetAllScreensMediaEnabled(bool enabled)
    {
        is_get_all_screens_media_enabled_ = enabled;
    }
    static void SetGetDisplayMediaEnabled(bool enabled)
    {
        is_get_display_media_enabled_ = enabled;
    }
    static void SetGetDisplayMediaRequiresUserActivationEnabled(bool enabled)
    {
        is_get_display_media_requires_user_activation_enabled_ = enabled;
    }
    static void SetGroupEffectEnabled(bool enabled)
    {
        is_group_effect_enabled_ = enabled;
    }
    static void SetHandleSelectionChangeOnDeletingEmptyElementEnabled(bool enabled)
    {
        is_handle_selection_change_on_deleting_empty_element_enabled_ = enabled;
    }
    static void SetHandwritingRecognitionEnabled(bool enabled)
    {
        is_handwriting_recognition_enabled_ = enabled;
    }
    static void SetHangingWhitespaceDoesNotDependOnAlignmentEnabled(bool enabled)
    {
        is_hanging_whitespace_does_not_depend_on_alignment_enabled_ = enabled;
    }
    static void SetHasUAVisualTransitionEnabled(bool enabled)
    {
        is_has_ua_visual_transition_enabled_ = enabled;
    }
    static void SetHighlightInheritanceEnabled(bool enabled)
    {
        is_highlight_inheritance_enabled_ = enabled;
    }
    static void SetHighlightPointerEventsEnabled(bool enabled)
    {
        is_highlight_pointer_events_enabled_ = enabled;
    }
    static void SetHighlightsFromPointEnabled(bool enabled)
    {
        is_highlights_from_point_enabled_ = enabled;
    }
    static void SetHitTestOpaquenessEnabled(bool enabled)
    {
        is_hit_test_opaqueness_enabled_ = enabled;
    }
    static void SetHitTestOpaquenessOmitLineBoxEnabled(bool enabled)
    {
        is_hit_test_opaqueness_omit_line_box_enabled_ = enabled;
    }
    static void SetHrefTranslateEnabled(bool enabled)
    {
        is_href_translate_enabled_ = enabled;
    }
    static void SetHTMLAnchorAttributeEnabled(bool enabled)
    {
        is_html_anchor_attribute_enabled_ = enabled;
    }
    static void SetHTMLDialogLightDismissEnabled(bool enabled)
    {
        is_html_dialog_light_dismiss_enabled_ = enabled;
    }
    static void SetHTMLEmbedElementNotForceLayoutEnabled(bool enabled)
    {
        is_html_embed_element_not_force_layout_enabled_ = enabled;
    }
    static void SetHTMLInterestTargetAttributeEnabled(bool enabled)
    {
        is_html_interest_target_attribute_enabled_ = enabled;
    }
    static void SetHTMLInvokeActionsV2Enabled(bool enabled)
    {
        is_html_invoke_actions_v_2_enabled_ = enabled;
    }
    static void SetHTMLInvokeTargetAttributeEnabled(bool enabled)
    {
        is_html_invoke_target_attribute_enabled_ = enabled;
    }
    static void SetHTMLObjectElementFallbackDetachContentFrameEnabled(bool enabled)
    {
        is_html_object_element_fallback_detach_content_frame_enabled_ = enabled;
    }
    static void SetHTMLParserYieldAndDelayOftenForTestingEnabled(bool enabled)
    {
        is_html_parser_yield_and_delay_often_for_testing_enabled_ = enabled;
    }
    static void SetHTMLPopoverActionHoverEnabled(bool enabled)
    {
        is_html_popover_action_hover_enabled_ = enabled;
    }
    static void SetHTMLPopoverHintEnabled(bool enabled)
    {
        is_html_popover_hint_enabled_ = enabled;
    }
    static void SetHTMLSelectElementShowPickerEnabled(bool enabled)
    {
        is_html_select_element_show_picker_enabled_ = enabled;
    }
    static void SetImplicitRootScrollerEnabled(bool enabled)
    {
        is_implicit_root_scroller_enabled_ = enabled;
    }
    static void SetImportAttributesDisallowUnknownKeysEnabled(bool enabled)
    {
        is_import_attributes_disallow_unknown_keys_enabled_ = enabled;
    }
    static void SetImportMapIntegrityEnabled(bool enabled)
    {
        is_import_map_integrity_enabled_ = enabled;
    }
    static void SetIncomingCallNotificationsEnabled(bool enabled)
    {
        is_incoming_call_notifications_enabled_ = enabled;
    }
    static void SetIncrementLocalSurfaceIdForMainframeSameDocNavigationEnabled(bool enabled)
    {
        is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_ = enabled;
    }
    static void SetIndexedDbGetAllRecordsEnabled(bool enabled)
    {
        is_indexed_db_get_all_records_enabled_ = enabled;
    }
    static void SetInertElementNonEditableEnabled(bool enabled)
    {
        is_inert_element_non_editable_enabled_ = enabled;
    }
    static void SetInertElementNonSearchableEnabled(bool enabled)
    {
        is_inert_element_non_searchable_enabled_ = enabled;
    }
    static void SetInfiniteCullRectEnabled(bool enabled)
    {
        is_infinite_cull_rect_enabled_ = enabled;
    }
    static void SetInheritUserModifyWithoutContenteditableEnabled(bool enabled)
    {
        is_inherit_user_modify_without_contenteditable_enabled_ = enabled;
    }
    static void SetInitialLetterRaiseBySpecifiedEnabled(bool enabled)
    {
        is_initial_letter_raise_by_specified_enabled_ = enabled;
    }
    static void SetInlineBlockInSameLineEnabled(bool enabled)
    {
        is_inline_block_in_same_line_enabled_ = enabled;
    }
    static void SetInnerHTMLParserFastpathLogFailureEnabled(bool enabled)
    {
        is_inner_html_parser_fastpath_log_failure_enabled_ = enabled;
    }
    static void SetInputClosesSelectEnabled(bool enabled)
    {
        is_input_closes_select_enabled_ = enabled;
    }
    static void SetInputMultipleFieldsUIEnabled(bool enabled)
    {
        is_input_multiple_fields_ui_enabled_ = enabled;
    }
    static void SetInsertBlockquoteBeforeOuterBlockEnabled(bool enabled)
    {
        is_insert_blockquote_before_outer_block_enabled_ = enabled;
    }
    static void SetInsertLineBreakIfPhrasingContentEnabled(bool enabled)
    {
        is_insert_line_break_if_phrasing_content_enabled_ = enabled;
    }
    static void SetInspectorGhostRulesEnabled(bool enabled)
    {
        is_inspector_ghost_rules_enabled_ = enabled;
    }
    static void SetInstalledAppEnabled(bool enabled)
    {
        is_installed_app_enabled_ = enabled;
    }
    static void SetInstallOnDeviceSpeechRecognitionEnabled(bool enabled)
    {
        is_install_on_device_speech_recognition_enabled_ = enabled;
    }
    static void SetInterestGroupsInSharedStorageWorkletEnabled(bool enabled)
    {
        is_interest_groups_in_shared_storage_worklet_enabled_ = enabled;
    }
    static void SetInteroperablePrivateAttributionEnabled(bool enabled)
    {
        is_interoperable_private_attribution_enabled_ = enabled;
    }
    static void SetIntersectionObserverScrollMarginEnabled(bool enabled)
    {
        is_intersection_observer_scroll_margin_enabled_ = enabled;
    }
    static void SetInvertedColorsEnabled(bool enabled)
    {
        is_inverted_colors_enabled_ = enabled;
    }
    static void SetInvisibleSVGAnimationThrottlingEnabled(bool enabled)
    {
        is_invisible_svg_animation_throttling_enabled_ = enabled;
    }
    static void SetJavaScriptCompileHintsMagicAlwaysRuntimeEnabled(bool enabled)
    {
        is_java_script_compile_hints_magic_always_runtime_enabled_ = enabled;
    }
    static void SetJavaScriptCompileHintsMagicRuntimeEnabled(bool enabled)
    {
        is_java_script_compile_hints_magic_runtime_enabled_ = enabled;
    }
    static void SetKeepCSSTargetAfterReattachEnabled(bool enabled)
    {
        is_keep_css_target_after_reattach_enabled_ = enabled;
    }
    static void SetKeyboardAccessibleTooltipEnabled(bool enabled)
    {
        is_keyboard_accessible_tooltip_enabled_ = enabled;
    }
    static void SetKeyboardFocusableScrollersEnabled(bool enabled)
    {
        is_keyboard_focusable_scrollers_enabled_ = enabled;
    }
    static void SetKeyboardFocusableScrollersOptOutEnabled(bool enabled)
    {
        is_keyboard_focusable_scrollers_opt_out_enabled_ = enabled;
    }
    static void SetLabelAndDelegatesFocusNewHandlingEnabled(bool enabled)
    {
        is_label_and_delegates_focus_new_handling_enabled_ = enabled;
    }
    static void SetLangAttributeAwareFormControlUIEnabled(bool enabled)
    {
        is_lang_attribute_aware_form_control_ui_enabled_ = enabled;
    }
    static void SetLanguageDetectionAPIEnabled(bool enabled)
    {
        is_language_detection_api_enabled_ = enabled;
    }
    static void SetLayoutFlexNewRowAlgorithmV3Enabled(bool enabled)
    {
        is_layout_flex_new_row_algorithm_v_3_enabled_ = enabled;
    }
    static void SetLayoutIgnoreMarginsForStickyEnabled(bool enabled)
    {
        is_layout_ignore_margins_for_sticky_enabled_ = enabled;
    }
    static void SetLayoutJustifySelfForBlocksEnabled(bool enabled)
    {
        is_layout_justify_self_for_blocks_enabled_ = enabled;
    }
    static void SetLayoutNGShapeCacheEnabled(bool enabled)
    {
        is_layout_ng_shape_cache_enabled_ = enabled;
    }
    static void SetLayoutStretchEnabled(bool enabled)
    {
        is_layout_stretch_enabled_ = enabled;
    }
    static void SetLazyInitializeMediaControlsEnabled(bool enabled)
    {
        is_lazy_initialize_media_controls_enabled_ = enabled;
    }
    static void SetLazyLoadScrollMarginEnabled(bool enabled)
    {
        is_lazy_load_scroll_margin_enabled_ = enabled;
    }
    static void SetLazyLoadScrollMarginIframeEnabled(bool enabled)
    {
        is_lazy_load_scroll_margin_iframe_enabled_ = enabled;
    }
    static void SetLCPAnimatedImagesWebExposedEnabled(bool enabled)
    {
        is_lcp_animated_images_web_exposed_enabled_ = enabled;
    }
    static void SetLegacyWindowsDWriteFontFallbackEnabled(bool enabled)
    {
        is_legacy_windows_d_write_font_fallback_enabled_ = enabled;
    }
    static void SetLimitThirdPartyCookiesEnabled(bool enabled)
    {
        is_limit_third_party_cookies_enabled_ = enabled;
    }
    static void SetLineBoxBelowLeadingFloatsEnabled(bool enabled)
    {
        is_line_box_below_leading_floats_enabled_ = enabled;
    }
    static void SetListItemWithCounterSetNotSetExplicitValueEnabled(bool enabled)
    {
        is_list_item_with_counter_set_not_set_explicit_value_enabled_ = enabled;
    }
    static void SetLockedModeEnabled(bool enabled)
    {
        is_locked_mode_enabled_ = enabled;
    }
    static void SetLongAnimationFrameTimingEnabled(bool enabled)
    {
        is_long_animation_frame_timing_enabled_ = enabled;
    }
    static void SetLongPressLinkSelectTextEnabled(bool enabled)
    {
        is_long_press_link_select_text_enabled_ = enabled;
    }
    static void SetLongTaskFromLongAnimationFrameEnabled(bool enabled)
    {
        is_long_task_from_long_animation_frame_enabled_ = enabled;
    }
    static void SetMachineLearningNeuralNetworkEnabled(bool enabled)
    {
        is_machine_learning_neural_network_enabled_ = enabled;
    }
    static void SetManagedConfigurationEnabled(bool enabled)
    {
        is_managed_configuration_enabled_ = enabled;
    }
    static void SetMeasureMemoryEnabled(bool enabled)
    {
        is_measure_memory_enabled_ = enabled;
    }
    static void SetMediaCapabilitiesDynamicRangeEnabled(bool enabled)
    {
        is_media_capabilities_dynamic_range_enabled_ = enabled;
    }
    static void SetMediaCapabilitiesEncodingInfoEnabled(bool enabled)
    {
        is_media_capabilities_encoding_info_enabled_ = enabled;
    }
    static void SetMediaCapabilitiesSpatialAudioEnabled(bool enabled)
    {
        is_media_capabilities_spatial_audio_enabled_ = enabled;
    }
    static void SetMediaCaptureEnabled(bool enabled)
    {
        is_media_capture_enabled_ = enabled;
    }
    static void SetMediaCaptureBackgroundBlurEnabled(bool enabled)
    {
        is_media_capture_background_blur_enabled_ = enabled;
    }
    static void SetMediaCaptureCameraControlsEnabled(bool enabled)
    {
        is_media_capture_camera_controls_enabled_ = enabled;
    }
    static void SetMediaCaptureConfigurationChangeEnabled(bool enabled)
    {
        is_media_capture_configuration_change_enabled_ = enabled;
    }
    static void SetMediaCaptureVoiceIsolationEnabled(bool enabled)
    {
        is_media_capture_voice_isolation_enabled_ = enabled;
    }
    static void SetMediaCastOverlayButtonEnabled(bool enabled)
    {
        is_media_cast_overlay_button_enabled_ = enabled;
    }
    static void SetMediaControlsExpandGestureEnabled(bool enabled)
    {
        is_media_controls_expand_gesture_enabled_ = enabled;
    }
    static void SetMediaControlsOverlayPlayButtonEnabled(bool enabled)
    {
        is_media_controls_overlay_play_button_enabled_ = enabled;
    }
    static void SetMediaElementVolumeGreaterThanOneEnabled(bool enabled)
    {
        is_media_element_volume_greater_than_one_enabled_ = enabled;
    }
    static void SetMediaEngagementBypassAutoplayPoliciesEnabled(bool enabled)
    {
        is_media_engagement_bypass_autoplay_policies_enabled_ = enabled;
    }
    static void SetMediaLatencyHintEnabled(bool enabled)
    {
        is_media_latency_hint_enabled_ = enabled;
    }
    static void SetMediaPlaybackWhileNotVisiblePermissionPolicyEnabled(bool enabled)
    {
        is_media_playback_while_not_visible_permission_policy_enabled_ = enabled;
    }
    static void SetMediaPreviewsOptOutEnabled(bool enabled)
    {
        is_media_previews_opt_out_enabled_ = enabled;
    }
    static void SetMediaQueryNavigationControlsEnabled(bool enabled)
    {
        is_media_query_navigation_controls_enabled_ = enabled;
    }
    static void SetMediaRecorderUseMediaVideoEncoderEnabled(bool enabled)
    {
        is_media_recorder_use_media_video_encoder_enabled_ = enabled;
    }
    static void SetMediaSessionEnabled(bool enabled)
    {
        is_media_session_enabled_ = enabled;
    }
    static void SetMediaSessionChapterInformationEnabled(bool enabled)
    {
        is_media_session_chapter_information_enabled_ = enabled;
    }
    static void SetMediaSessionEnterPictureInPictureEnabled(bool enabled)
    {
        is_media_session_enter_picture_in_picture_enabled_ = enabled;
    }
    static void SetMediaSourceExperimentalEnabled(bool enabled)
    {
        is_media_source_experimental_enabled_ = enabled;
    }
    static void SetMediaSourceExtensionsForWebCodecsEnabled(bool enabled)
    {
        is_media_source_extensions_for_webcodecs_enabled_ = enabled;
    }
    static void SetMediaSourceNewAbortAndDurationEnabled(bool enabled)
    {
        is_media_source_new_abort_and_duration_enabled_ = enabled;
    }
    static void SetMediaStreamTrackTransferEnabled(bool enabled)
    {
        is_media_stream_track_transfer_enabled_ = enabled;
    }
    static void SetMediaStreamTrackWebSpeechEnabled(bool enabled)
    {
        is_media_stream_track_web_speech_enabled_ = enabled;
    }
    static void SetMessagePortCloseEventEnabled(bool enabled)
    {
        is_message_port_close_event_enabled_ = enabled;
    }
    static void SetMetaRefreshNoFractionalEnabled(bool enabled)
    {
        is_meta_refresh_no_fractional_enabled_ = enabled;
    }
    static void SetMeterAppearanceNoneFallbackStyleEnabled(bool enabled)
    {
        is_meter_appearance_none_fallback_style_enabled_ = enabled;
    }
    static void SetMeterDevolveAppearanceEnabled(bool enabled)
    {
        is_meter_devolve_appearance_enabled_ = enabled;
    }
    static void SetMiddleClickAutoscrollEnabled(bool enabled)
    {
        is_middle_click_autoscroll_enabled_ = enabled;
    }
    static void SetMinimimalResourceRequestPrepBeforeCacheLookupEnabled(bool enabled)
    {
        is_minimimal_resource_request_prep_before_cache_lookup_enabled_ = enabled;
    }
    static void SetMobileLayoutThemeEnabled(bool enabled)
    {
        is_mobile_layout_theme_enabled_ = enabled;
    }
    static void SetModifyParagraphCrossEditingoundaryEnabled(bool enabled)
    {
        is_modify_paragraph_cross_editingoundary_enabled_ = enabled;
    }
    static void SetMojoJSEnabled(bool enabled);
    static void SetMojoJSTestEnabled(bool enabled);
    static void SetMoveEndingSelectionToListChildEnabled(bool enabled)
    {
        is_move_ending_selection_to_list_child_enabled_ = enabled;
    }
    static void SetMoveToParagraphStartOrEndSkipsNonEditableEnabled(bool enabled)
    {
        is_move_to_paragraph_start_or_end_skips_non_editable_enabled_ = enabled;
    }
    static void SetMultipleImportMapsEnabled(bool enabled)
    {
        is_multiple_import_maps_enabled_ = enabled;
    }
    static void SetMultiSelectDeselectWhenOnlyOptionEnabled(bool enabled)
    {
        is_multi_select_deselect_when_only_option_enabled_ = enabled;
    }
    static void SetMultiSmoothScrollIntoViewEnabled(bool enabled)
    {
        is_multi_smooth_scroll_into_view_enabled_ = enabled;
    }
    static void SetMutationEventsEnabled(bool enabled)
    {
        is_mutation_events_enabled_ = enabled;
    }
    static void SetMutationEventsSpecialTrialMessageEnabled(bool enabled)
    {
        is_mutation_events_special_trial_message_enabled_ = enabled;
    }
    static void SetNavigateEventCommitBehaviorEnabled(bool enabled)
    {
        is_navigate_event_commit_behavior_enabled_ = enabled;
    }
    static void SetNavigateEventSourceElementEnabled(bool enabled)
    {
        is_navigate_event_source_element_enabled_ = enabled;
    }
    static void SetNavigationActivationEnabled(bool enabled)
    {
        is_navigation_activation_enabled_ = enabled;
    }
    static void SetNavigationIdEnabled(bool enabled)
    {
        is_navigation_id_enabled_ = enabled;
    }
    static void SetNavigatorContentUtilsEnabled(bool enabled)
    {
        is_navigator_content_utils_enabled_ = enabled;
    }
    static void SetNestedViewTransitionEnabled(bool enabled)
    {
        is_nested_view_transition_enabled_ = enabled;
    }
    static void SetNetInfoConstantTypeEnabled(bool enabled)
    {
        is_net_info_constant_type_enabled_ = enabled;
    }
    static void SetNetInfoDownlinkMaxEnabled(bool enabled)
    {
        is_net_info_downlink_max_enabled_ = enabled;
    }
    static void SetNewGetFocusableAreaBehaviorEnabled(bool enabled)
    {
        is_new_get_focusable_area_behavior_enabled_ = enabled;
    }
    static void SetNoIdleEncodingForWebTestsEnabled(bool enabled)
    {
        is_no_idle_encoding_for_web_tests_enabled_ = enabled;
    }
    static void SetNoIncreasingEndOffsetOnSplittingTextNodesEnabled(bool enabled)
    {
        is_no_increasing_end_offset_on_splitting_text_nodes_enabled_ = enabled;
    }
    static void SetNonEmptyBlockquotesOnOutdentingEnabled(bool enabled)
    {
        is_non_empty_blockquotes_on_outdenting_enabled_ = enabled;
    }
    static void SetNonNullInputEventDataForTextAreaEnabled(bool enabled)
    {
        is_non_null_input_event_data_for_text_area_enabled_ = enabled;
    }
    static void SetNonStandardAppearanceValueSliderVerticalEnabled(bool enabled)
    {
        is_non_standard_appearance_value_slider_vertical_enabled_ = enabled;
    }
    static void SetNotificationConstructorEnabled(bool enabled)
    {
        is_notification_constructor_enabled_ = enabled;
    }
    static void SetNotificationContentImageEnabled(bool enabled)
    {
        is_notification_content_image_enabled_ = enabled;
    }
    static void SetNotificationsEnabled(bool enabled)
    {
        is_notifications_enabled_ = enabled;
    }
    static void SetNotificationTriggersEnabled(bool enabled)
    {
        is_notification_triggers_enabled_ = enabled;
    }
    static void SetObservableAPIEnabled(bool enabled)
    {
        is_observable_api_enabled_ = enabled;
    }
    static void SetOffMainThreadCSSPaintEnabled(bool enabled)
    {
        is_off_main_thread_css_paint_enabled_ = enabled;
    }
    static void SetOffscreenCanvasCommitEnabled(bool enabled)
    {
        is_offscreen_canvas_commit_enabled_ = enabled;
    }
    static void SetOmitBlurEventOnElementRemovalEnabled(bool enabled)
    {
        is_omit_blur_event_on_element_removal_enabled_ = enabled;
    }
    static void SetOnDeviceChangeEnabled(bool enabled)
    {
        is_on_device_change_enabled_ = enabled;
    }
    static void SetOnDeviceWebSpeechAvailableEnabled(bool enabled)
    {
        is_on_device_web_speech_available_enabled_ = enabled;
    }
    static void SetOrientationEventEnabled(bool enabled)
    {
        is_orientation_event_enabled_ = enabled;
    }
    static void SetOriginIsolationHeaderEnabled(bool enabled)
    {
        is_origin_isolation_header_enabled_ = enabled;
    }
    static void SetOriginPolicyEnabled(bool enabled)
    {
        is_origin_policy_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIEnabled(bool enabled)
    {
        is_origin_trials_sample_api_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIBrowserReadWriteEnabled(bool enabled)
    {
        is_origin_trials_sample_api_browser_read_write_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIDependentEnabled(bool enabled)
    {
        is_origin_trials_sample_api_dependent_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIDeprecationEnabled(bool enabled)
    {
        is_origin_trials_sample_api_deprecation_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIExpiryGracePeriodEnabled(bool enabled)
    {
        is_origin_trials_sample_api_expiry_grace_period_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(bool enabled)
    {
        is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIImpliedEnabled(bool enabled)
    {
        is_origin_trials_sample_api_implied_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIInvalidOSEnabled(bool enabled)
    {
        is_origin_trials_sample_api_invalid_os_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPINavigationEnabled(bool enabled)
    {
        is_origin_trials_sample_api_navigation_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(bool enabled)
    {
        is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIPersistentFeatureEnabled(bool enabled)
    {
        is_origin_trials_sample_api_persistent_feature_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIPersistentInvalidOSEnabled(bool enabled)
    {
        is_origin_trials_sample_api_persistent_invalid_os_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIPersistentThirdPartyDeprecationFeatureEnabled(bool enabled)
    {
        is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_ = enabled;
    }
    static void SetOriginTrialsSampleAPIThirdPartyEnabled(bool enabled)
    {
        is_origin_trials_sample_api_third_party_enabled_ = enabled;
    }
    static void SetOverscrollCustomizationEnabled(bool enabled)
    {
        is_overscroll_customization_enabled_ = enabled;
    }
    static void SetPageFreezeOptInEnabled(bool enabled)
    {
        is_page_freeze_opt_in_enabled_ = enabled;
    }
    static void SetPageFreezeOptOutEnabled(bool enabled)
    {
        is_page_freeze_opt_out_enabled_ = enabled;
    }
    static void SetPageMarginBoxesEnabled(bool enabled)
    {
        is_page_margin_boxes_enabled_ = enabled;
    }
    static void SetPagePopupEnabled(bool enabled)
    {
        is_page_popup_enabled_ = enabled;
    }
    static void SetPageRevealEventEnabled(bool enabled)
    {
        is_page_reveal_event_enabled_ = enabled;
    }
    static void SetPageSwapEventEnabled(bool enabled)
    {
        is_page_swap_event_enabled_ = enabled;
    }
    static void SetPaintHighlightsForFirstLetterEnabled(bool enabled)
    {
        is_paint_highlights_for_first_letter_enabled_ = enabled;
    }
    static void SetPaintHoldingForIframesEnabled(bool enabled)
    {
        is_paint_holding_for_iframes_enabled_ = enabled;
    }
    static void SetPaintHoldingForLocalIframesEnabled(bool enabled)
    {
        is_paint_holding_for_local_iframes_enabled_ = enabled;
    }
    static void SetPaintUnderInvalidationCheckingEnabled(bool enabled)
    {
        is_paint_under_invalidation_checking_enabled_ = enabled;
    }
    static void SetParakeetEnabled(bool enabled)
    {
        is_parakeet_enabled_ = enabled;
    }
    static void SetPartitionedPopinsEnabled(bool enabled)
    {
        is_partitioned_popins_enabled_ = enabled;
    }
    static void SetPartitionVisitedLinkDatabaseWithSelfLinksEnabled(bool enabled)
    {
        is_partition_visited_link_database_with_self_links_enabled_ = enabled;
    }
    static void SetPasswordRevealEnabled(bool enabled)
    {
        is_password_reveal_enabled_ = enabled;
    }
    static void SetPaymentAppEnabled(bool enabled)
    {
        is_payment_app_enabled_ = enabled;
    }
    static void SetPaymentInstrumentsEnabled(bool enabled)
    {
        is_payment_instruments_enabled_ = enabled;
    }
    static void SetPaymentLinkDetectionEnabled(bool enabled)
    {
        is_payment_link_detection_enabled_ = enabled;
    }
    static void SetPaymentMethodChangeEventEnabled(bool enabled)
    {
        is_payment_method_change_event_enabled_ = enabled;
    }
    static void SetPaymentRequestEnabled(bool enabled)
    {
        is_payment_request_enabled_ = enabled;
    }
    static void SetPercentBasedScrollingEnabled(bool enabled)
    {
        is_percent_based_scrolling_enabled_ = enabled;
    }
    static void SetPerformanceManagerInstrumentationEnabled(bool enabled)
    {
        is_performance_manager_instrumentation_enabled_ = enabled;
    }
    static void SetPerformanceMarkFeatureUsageEnabled(bool enabled)
    {
        is_performance_mark_feature_usage_enabled_ = enabled;
    }
    static void SetPerformanceNavigateSystemEntropyEnabled(bool enabled)
    {
        is_performance_navigate_system_entropy_enabled_ = enabled;
    }
    static void SetPerformanceNavigationTimingConfidenceEnabled(bool enabled)
    {
        is_performance_navigation_timing_confidence_enabled_ = enabled;
    }
    static void SetPeriodicBackgroundSyncEnabled(bool enabled)
    {
        is_periodic_background_sync_enabled_ = enabled;
    }
    static void SetPerMethodCanMakePaymentQuotaEnabled(bool enabled)
    {
        is_per_method_can_make_payment_quota_enabled_ = enabled;
    }
    static void SetPermissionElementEnabled(bool enabled)
    {
        is_permission_element_enabled_ = enabled;
    }
    static void SetPermissionsEnabled(bool enabled)
    {
        is_permissions_enabled_ = enabled;
    }
    static void SetPermissionsRequestRevokeEnabled(bool enabled)
    {
        is_permissions_request_revoke_enabled_ = enabled;
    }
    static void SetPNaClEnabled(bool enabled)
    {
        is_p_na_cl_enabled_ = enabled;
    }
    static void SetPointerEventDeviceIdEnabled(bool enabled)
    {
        is_pointer_event_device_id_enabled_ = enabled;
    }
    static void SetPointerEventTargetsInEventListsEnabled(bool enabled)
    {
        is_pointer_event_targets_in_event_lists_enabled_ = enabled;
    }
    static void SetPopoverAnchorRelationshipsEnabled(bool enabled)
    {
        is_popover_anchor_relationships_enabled_ = enabled;
    }
    static void SetPopoverDialogNewFocusBehaviorEnabled(bool enabled)
    {
        is_popover_dialog_new_focus_behavior_enabled_ = enabled;
    }
    static void SetPositionOutsideTabSpanCheckSiblingNodeEnabled(bool enabled)
    {
        is_position_outside_tab_span_check_sibling_node_enabled_ = enabled;
    }
    static void SetPreciseMemoryInfoEnabled(bool enabled)
    {
        is_precise_memory_info_enabled_ = enabled;
    }
    static void SetPreferDefaultScrollbarStylesEnabled(bool enabled)
    {
        is_prefer_default_scrollbar_styles_enabled_ = enabled;
    }
    static void SetPreferNonCompositedScrollingEnabled(bool enabled)
    {
        is_prefer_non_composited_scrolling_enabled_ = enabled;
    }
    static void SetPrefersReducedDataEnabled(bool enabled)
    {
        is_prefers_reduced_data_enabled_ = enabled;
    }
    static void SetPrefixedVideoFullscreenEnabled(bool enabled)
    {
        is_prefixed_video_fullscreen_enabled_ = enabled;
    }
    static void SetPrerender2Enabled(bool enabled)
    {
        is_prerender_2_enabled_ = enabled;
    }
    static void SetPresentationEnabled(bool enabled)
    {
        is_presentation_enabled_ = enabled;
    }
    static void SetPreserveFollowingBlockStylesDuringBlockMergeEnabled(bool enabled)
    {
        is_preserve_following_block_styles_during_block_merge_enabled_ = enabled;
    }
    static void SetPreventUndoIfNotEditableEnabled(bool enabled)
    {
        is_prevent_undo_if_not_editable_enabled_ = enabled;
    }
    static void SetPrivateAggregationApiFilteringIdsEnabled(bool enabled)
    {
        is_private_aggregation_api_filtering_ids_enabled_ = enabled;
    }
    static void SetPrivateAggregationAuctionReportBuyerDebugModeConfigEnabled(bool enabled)
    {
        is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_ = enabled;
    }
    static void SetPrivateNetworkAccessNonSecureContextsAllowedEnabled(bool enabled)
    {
        is_private_network_access_non_secure_contexts_allowed_enabled_ = enabled;
    }
    static void SetPrivateNetworkAccessNullIpAddressEnabled(bool enabled)
    {
        is_private_network_access_null_ip_address_enabled_ = enabled;
    }
    static void SetPrivateNetworkAccessPermissionPromptEnabled(bool enabled)
    {
        is_private_network_access_permission_prompt_enabled_ = enabled;
    }
    static void SetPrivateStateTokensEnabled(bool enabled)
    {
        is_private_state_tokens_enabled_ = enabled;
    }
    static void SetPrivateStateTokensAlwaysAllowIssuanceEnabled(bool enabled)
    {
        is_private_state_tokens_always_allow_issuance_enabled_ = enabled;
    }
    static void SetProtectedOriginTrialsSampleAPIEnabled(bool enabled);
    static void SetProtectedOriginTrialsSampleAPIDependentEnabled(bool enabled);
    static void SetProtectedOriginTrialsSampleAPIImpliedEnabled(bool enabled);
    static void SetPseudoElementsCorrectInGetComputedStyleEnabled(bool enabled)
    {
        is_pseudo_elements_correct_in_get_computed_style_enabled_ = enabled;
    }
    static void SetPseudoElementsFocusableEnabled(bool enabled)
    {
        is_pseudo_elements_focusable_enabled_ = enabled;
    }
    static void SetPushMessageDataBytesEnabled(bool enabled)
    {
        is_push_message_data_bytes_enabled_ = enabled;
    }
    static void SetPushMessagingEnabled(bool enabled)
    {
        is_push_messaging_enabled_ = enabled;
    }
    static void SetPushMessagingSubscriptionChangeEnabled(bool enabled)
    {
        is_push_messaging_subscription_change_enabled_ = enabled;
    }
    static void SetQuickIntensiveWakeUpThrottlingAfterLoadingEnabled(bool enabled)
    {
        is_quick_intensive_wake_up_throttling_after_loading_enabled_ = enabled;
    }
    static void SetRasterInducingScrollEnabled(bool enabled)
    {
        is_raster_inducing_scroll_enabled_ = enabled;
    }
    static void SetReadableStreamAsyncIterableEnabled(bool enabled)
    {
        is_readable_stream_async_iterable_enabled_ = enabled;
    }
    static void SetReduceAcceptLanguageEnabled(bool enabled)
    {
        is_reduce_accept_language_enabled_ = enabled;
    }
    static void SetReduceCookieIPCsEnabled(bool enabled)
    {
        is_reduce_cookie_ip_cs_enabled_ = enabled;
    }
    static void SetReduceUserAgentAndroidVersionDeviceModelEnabled(bool enabled)
    {
        is_reduce_user_agent_android_version_device_model_enabled_ = enabled;
    }
    static void SetReduceUserAgentMinorVersionEnabled(bool enabled)
    {
        is_reduce_user_agent_minor_version_enabled_ = enabled;
    }
    static void SetReduceUserAgentPlatformOsCpuEnabled(bool enabled)
    {
        is_reduce_user_agent_platform_os_cpu_enabled_ = enabled;
    }
    static void SetRegionCaptureEnabled(bool enabled)
    {
        is_region_capture_enabled_ = enabled;
    }
    static void SetRelOpenerBcgDependencyHintEnabled(bool enabled)
    {
        is_rel_opener_bcg_dependency_hint_enabled_ = enabled;
    }
    static void SetRemotePlaybackEnabled(bool enabled)
    {
        is_remote_playback_enabled_ = enabled;
    }
    static void SetRemotePlaybackBackendEnabled(bool enabled)
    {
        is_remote_playback_backend_enabled_ = enabled;
    }
    static void SetRemoveCollapsedPlaceholderEnabled(bool enabled)
    {
        is_remove_collapsed_placeholder_enabled_ = enabled;
    }
    static void SetRemoveDanglingMarkupInTargetEnabled(bool enabled)
    {
        is_remove_dangling_markup_in_target_enabled_ = enabled;
    }
    static void SetRemoveDataUrlInSvgUseEnabled(bool enabled)
    {
        is_remove_data_url_in_svg_use_enabled_ = enabled;
    }
    static void SetRemoveNodeHavingChildrenIfFullySelectedEnabled(bool enabled)
    {
        is_remove_node_having_children_if_fully_selected_enabled_ = enabled;
    }
    static void SetRemoveVisibleSelectionInDOMSelectionEnabled(bool enabled)
    {
        is_remove_visible_selection_in_dom_selection_enabled_ = enabled;
    }
    static void SetRenderBlockingInlineModuleScriptEnabled(bool enabled)
    {
        is_render_blocking_inline_module_script_enabled_ = enabled;
    }
    static void SetRenderBlockingStatusEnabled(bool enabled)
    {
        is_render_blocking_status_enabled_ = enabled;
    }
    static void SetRenderPriorityAttributeEnabled(bool enabled)
    {
        is_render_priority_attribute_enabled_ = enabled;
    }
    static void SetReportEventTimingAtVisibilityChangeEnabled(bool enabled)
    {
        is_report_event_timing_at_visibility_change_enabled_ = enabled;
    }
    static void SetReportVisibleLineBoundsEnabled(bool enabled)
    {
        is_report_visible_line_bounds_enabled_ = enabled;
    }
    static void SetResetInputTypeToNoneBeforeCharacterInputEnabled(bool enabled)
    {
        is_reset_input_type_to_none_before_character_input_enabled_ = enabled;
    }
    static void SetResourceTimingContentTypeEnabled(bool enabled)
    {
        is_resource_timing_content_type_enabled_ = enabled;
    }
    static void SetResourceTimingFinalResponseHeadersStartEnabled(bool enabled)
    {
        is_resource_timing_final_response_headers_start_enabled_ = enabled;
    }
    static void SetResourceTimingUseCORSForBodySizesEnabled(bool enabled)
    {
        is_resource_timing_use_cors_for_body_sizes_enabled_ = enabled;
    }
    static void SetRestrictGamepadAccessEnabled(bool enabled)
    {
        is_restrict_gamepad_access_enabled_ = enabled;
    }
    static void SetReuseShapeResultsByFontsEnabled(bool enabled)
    {
        is_reuse_shape_results_by_fonts_enabled_ = enabled;
    }
    static void SetRewindFloatsEnabled(bool enabled)
    {
        is_rewind_floats_enabled_ = enabled;
    }
    static void SetRootElementWithPlaceHolderAfterDeletingSelectionEnabled(bool enabled)
    {
        is_root_element_with_place_holder_after_deleting_selection_enabled_ = enabled;
    }
    static void SetRtcAudioJitterBufferMaxPacketsEnabled(bool enabled)
    {
        is_rtc_audio_jitter_buffer_max_packets_enabled_ = enabled;
    }
    static void SetRTCDataChannelPriorityEnabled(bool enabled)
    {
        is_rtc_data_channel_priority_enabled_ = enabled;
    }
    static void SetRTCEncodedAudioFrameAbsCaptureTimeEnabled(bool enabled)
    {
        is_rtc_encoded_audio_frame_abs_capture_time_enabled_ = enabled;
    }
    static void SetRTCEncodedFrameSetMetadataEnabled(bool enabled)
    {
        is_rtc_encoded_frame_set_metadata_enabled_ = enabled;
    }
    static void SetRTCEncodedVideoFrameAdditionalMetadataEnabled(bool enabled)
    {
        is_rtc_encoded_video_frame_additional_metadata_enabled_ = enabled;
    }
    static void SetRTCJitterBufferTargetEnabled(bool enabled)
    {
        is_rtc_jitter_buffer_target_enabled_ = enabled;
    }
    static void SetRTCLegacyCallbackBasedGetStatsEnabled(bool enabled)
    {
        is_rtc_legacy_callback_based_get_stats_enabled_ = enabled;
    }
    static void SetRTCRtpEncodingParametersCodecEnabled(bool enabled)
    {
        is_rtc_rtp_encoding_parameters_codec_enabled_ = enabled;
    }
    static void SetRTCRtpScaleResolutionDownToEnabled(bool enabled)
    {
        is_rtc_rtp_scale_resolution_down_to_enabled_ = enabled;
    }
    static void SetRTCRtpScriptTransformEnabled(bool enabled)
    {
        is_rtc_rtp_script_transform_enabled_ = enabled;
    }
    static void SetRTCRtpTransportEnabled(bool enabled)
    {
        is_rtc_rtp_transport_enabled_ = enabled;
    }
    static void SetRTCStatsRelativePacketArrivalDelayEnabled(bool enabled)
    {
        is_rtc_stats_relative_packet_arrival_delay_enabled_ = enabled;
    }
    static void SetRTCSvcScalabilityModeEnabled(bool enabled)
    {
        is_rtc_svc_scalability_mode_enabled_ = enabled;
    }
    static void SetRubyShortHeuristicsEnabled(bool enabled)
    {
        is_ruby_short_heuristics_enabled_ = enabled;
    }
    static void SetSanitizerAPIEnabled(bool enabled)
    {
        is_sanitizer_api_enabled_ = enabled;
    }
    static void SetSchedulerYieldEnabled(bool enabled)
    {
        is_scheduler_yield_enabled_ = enabled;
    }
    static void SetScheduleSelectionChangeOnBackspaceEnabled(bool enabled)
    {
        is_schedule_selection_change_on_backspace_enabled_ = enabled;
    }
    static void SetScopedCustomElementRegistryEnabled(bool enabled)
    {
        is_scoped_custom_element_registry_enabled_ = enabled;
    }
    static void SetScriptedSpeechRecognitionEnabled(bool enabled)
    {
        is_scripted_speech_recognition_enabled_ = enabled;
    }
    static void SetScriptedSpeechSynthesisEnabled(bool enabled)
    {
        is_scripted_speech_synthesis_enabled_ = enabled;
    }
    static void SetScrollbarColorEnabled(bool enabled)
    {
        is_scrollbar_color_enabled_ = enabled;
    }
    static void SetScrollbarWidthEnabled(bool enabled)
    {
        is_scrollbar_width_enabled_ = enabled;
    }
    static void SetScrollEndEventsEnabled(bool enabled)
    {
        is_scroll_end_events_enabled_ = enabled;
    }
    static void SetScrollIntoViewRootFrameViewportBugFixEnabled(bool enabled)
    {
        is_scroll_into_view_root_frame_viewport_bug_fix_enabled_ = enabled;
    }
    static void SetScrollTimelineEnabled(bool enabled)
    {
        is_scroll_timeline_enabled_ = enabled;
    }
    static void SetScrollTimelineCurrentTimeEnabled(bool enabled)
    {
        is_scroll_timeline_current_time_enabled_ = enabled;
    }
    static void SetScrollTopLeftInteropEnabled(bool enabled)
    {
        is_scroll_top_left_interop_enabled_ = enabled;
    }
    static void SetSearchTextHighlightPseudoEnabled(bool enabled)
    {
        is_search_text_highlight_pseudo_enabled_ = enabled;
    }
    static void SetSecurePaymentConfirmationEnabled(bool enabled)
    {
        is_secure_payment_confirmation_enabled_ = enabled;
    }
    static void SetSecurePaymentConfirmationDebugEnabled(bool enabled)
    {
        is_secure_payment_confirmation_debug_enabled_ = enabled;
    }
    static void SetSecurePaymentConfirmationNetworkAndIssuerIconsEnabled(bool enabled)
    {
        is_secure_payment_confirmation_network_and_issuer_icons_enabled_ = enabled;
    }
    static void SetSecurePaymentConfirmationOptOutEnabled(bool enabled)
    {
        is_secure_payment_confirmation_opt_out_enabled_ = enabled;
    }
    static void SetSelectAudioOutputEnabled(bool enabled)
    {
        is_select_audio_output_enabled_ = enabled;
    }
    static void SetSelectedcontentelementAttributeEnabled(bool enabled)
    {
        is_selectedcontentelement_attribute_enabled_ = enabled;
    }
    static void SetSelectionAcrossShadowDOMEnabled(bool enabled)
    {
        is_selection_across_shadow_dom_enabled_ = enabled;
    }
    static void SetSelectionIsCollapsedShadowDOMSupportEnabled(bool enabled)
    {
        is_selection_is_collapsed_shadow_dom_support_enabled_ = enabled;
    }
    static void SetSelectionOnShadowDOMWithDelegatesFocusEnabled(bool enabled)
    {
        is_selection_on_shadow_dom_with_delegates_focus_enabled_ = enabled;
    }
    static void SetSelectOptionAccessibilityTargetSizeEnabled(bool enabled)
    {
        is_select_option_accessibility_target_size_enabled_ = enabled;
    }
    static void SetSelectParserRelaxationEnabled(bool enabled)
    {
        is_select_parser_relaxation_enabled_ = enabled;
    }
    static void SetSelectPopupLessUpdatesEnabled(bool enabled)
    {
        is_select_popup_less_updates_enabled_ = enabled;
    }
    static void SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(bool enabled)
    {
        is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = enabled;
    }
    static void SetSensorExtraClassesEnabled(bool enabled)
    {
        is_sensor_extra_classes_enabled_ = enabled;
    }
    static void SetSerialEnabled(bool enabled)
    {
        is_serial_enabled_ = enabled;
    }
    static void SetSerializeViewTransitionStateInSPAEnabled(bool enabled)
    {
        is_serialize_view_transition_state_in_spa_enabled_ = enabled;
    }
    static void SetSerialPortConnectedEnabled(bool enabled)
    {
        is_serial_port_connected_enabled_ = enabled;
    }
    static void SetServiceWorkerClientLifecycleStateEnabled(bool enabled)
    {
        is_service_worker_client_lifecycle_state_enabled_ = enabled;
    }
    static void SetServiceWorkerStaticRouterEnabled(bool enabled)
    {
        is_service_worker_static_router_enabled_ = enabled;
    }
    static void SetServiceWorkerStaticRouterTimingInfoEnabled(bool enabled)
    {
        is_service_worker_static_router_timing_info_enabled_ = enabled;
    }
    static void SetSetSequentialFocusStartingPointEnabled(bool enabled)
    {
        is_set_sequential_focus_starting_point_enabled_ = enabled;
    }
    static void SetShadowRootReferenceTargetEnabled(bool enabled)
    {
        is_shadow_root_reference_target_enabled_ = enabled;
    }
    static void SetShapeOutsideWritingModeFixEnabled(bool enabled)
    {
        is_shape_outside_writing_mode_fix_enabled_ = enabled;
    }
    static void SetShapeResultCachedPreviousSafeToBreakOffsetEnabled(bool enabled)
    {
        is_shape_result_cached_previous_safe_to_break_offset_enabled_ = enabled;
    }
    static void SetSharedArrayBufferEnabled(bool enabled)
    {
        is_shared_array_buffer_enabled_ = enabled;
    }
    static void SetSharedArrayBufferOnDesktopEnabled(bool enabled)
    {
        is_shared_array_buffer_on_desktop_enabled_ = enabled;
    }
    static void SetSharedArrayBufferUnrestrictedAccessAllowedEnabled(bool enabled)
    {
        is_shared_array_buffer_unrestricted_access_allowed_enabled_ = enabled;
    }
    static void SetSharedAutofillEnabled(bool enabled)
    {
        is_shared_autofill_enabled_ = enabled;
    }
    static void SetSharedStorageAPIEnabled(bool enabled)
    {
        is_shared_storage_api_enabled_ = enabled;
    }
    static void SetSharedStorageAPIM118Enabled(bool enabled)
    {
        is_shared_storage_api_m_118_enabled_ = enabled;
    }
    static void SetSharedStorageAPIM125Enabled(bool enabled)
    {
        is_shared_storage_api_m_125_enabled_ = enabled;
    }
    static void SetSharedStorageWebLocksEnabled(bool enabled)
    {
        is_shared_storage_web_locks_enabled_ = enabled;
    }
    static void SetSharedWorkerEnabled(bool enabled)
    {
        is_shared_worker_enabled_ = enabled;
    }
    static void SetSidewaysWritingModesEnabled(bool enabled)
    {
        is_sideways_writing_modes_enabled_ = enabled;
    }
    static void SetSignatureBasedIntegrityEnabled(bool enabled)
    {
        is_signature_based_integrity_enabled_ = enabled;
    }
    static void SetSiteInitiatedMirroringEnabled(bool enabled)
    {
        is_site_initiated_mirroring_enabled_ = enabled;
    }
    static void SetSkipAdEnabled(bool enabled)
    {
        is_skip_ad_enabled_ = enabled;
    }
    static void SetSkipPreloadScanningEnabled(bool enabled)
    {
        is_skip_preload_scanning_enabled_ = enabled;
    }
    static void SetSkipTemporaryDocumentFragmentEnabled(bool enabled)
    {
        is_skip_temporary_document_fragment_enabled_ = enabled;
    }
    static void SetSkipTouchEventFilterEnabled(bool enabled)
    {
        is_skip_touch_event_filter_enabled_ = enabled;
    }
    static void SetSmartCardEnabled(bool enabled)
    {
        is_smart_card_enabled_ = enabled;
    }
    static void SetSmartZoomEnabled(bool enabled)
    {
        is_smart_zoom_enabled_ = enabled;
    }
    static void SetSmilAutoSuspendOnLagEnabled(bool enabled)
    {
        is_smil_auto_suspend_on_lag_enabled_ = enabled;
    }
    static void SetSoftNavigationDetectionEnabled(bool enabled)
    {
        is_soft_navigation_detection_enabled_ = enabled;
    }
    static void SetSoftNavigationHeuristicsEnabled(bool enabled)
    {
        is_soft_navigation_heuristics_enabled_ = enabled;
    }
    static void SetSoftNavigationHeuristicsExposeFPAndFCPEnabled(bool enabled)
    {
        is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_ = enabled;
    }
    static void SetSpeakerSelectionEnabled(bool enabled)
    {
        is_speaker_selection_enabled_ = enabled;
    }
    static void SetSpeculationRulesPointerDownHeuristicsEnabled(bool enabled)
    {
        is_speculation_rules_pointer_down_heuristics_enabled_ = enabled;
    }
    static void SetSpeculationRulesPointerHoverHeuristicsEnabled(bool enabled)
    {
        is_speculation_rules_pointer_hover_heuristics_enabled_ = enabled;
    }
    static void SetSpeculationRulesPrefetchFutureEnabled(bool enabled)
    {
        is_speculation_rules_prefetch_future_enabled_ = enabled;
    }
    static void SetSpeculationRulesPrefetchWithSubresourcesEnabled(bool enabled)
    {
        is_speculation_rules_prefetch_with_subresources_enabled_ = enabled;
    }
    static void SetSrcsetMaxDensityEnabled(bool enabled)
    {
        is_srcset_max_density_enabled_ = enabled;
    }
    static void SetStableBlinkFeaturesEnabled(bool enabled)
    {
        is_stable_blink_features_enabled_ = enabled;
    }
    static void SetStandardizedBrowserZoomEnabled(bool enabled)
    {
        is_standardized_browser_zoom_enabled_ = enabled;
    }
    static void SetStandardizedBrowserZoomOptOutEnabled(bool enabled)
    {
        is_standardized_browser_zoom_opt_out_enabled_ = enabled;
    }
    static void SetStaticAnimationOptimizationEnabled(bool enabled)
    {
        is_static_animation_optimization_enabled_ = enabled;
    }
    static void SetStorageAccessHeaderEnabled(bool enabled)
    {
        is_storage_access_header_enabled_ = enabled;
    }
    static void SetStorageBucketsEnabled(bool enabled)
    {
        is_storage_buckets_enabled_ = enabled;
    }
    static void SetStorageBucketsDurabilityEnabled(bool enabled)
    {
        is_storage_buckets_durability_enabled_ = enabled;
    }
    static void SetStorageBucketsLocksEnabled(bool enabled)
    {
        is_storage_buckets_locks_enabled_ = enabled;
    }
    static void SetStricterCellWidthContentSizeQuirkEnabled(bool enabled)
    {
        is_stricter_cell_width_content_size_quirk_enabled_ = enabled;
    }
    static void SetStrictMimeTypesForWorkersEnabled(bool enabled)
    {
        is_strict_mime_types_for_workers_enabled_ = enabled;
    }
    static void SetStylusHandwritingEnabled(bool enabled)
    {
        is_stylus_handwriting_enabled_ = enabled;
    }
    static void SetSvgContextPaintEnabled(bool enabled)
    {
        is_svg_context_paint_enabled_ = enabled;
    }
    static void SetSvgCrossOriginAttributeEnabled(bool enabled)
    {
        is_svg_cross_origin_attribute_enabled_ = enabled;
    }
    static void SetSvgEagerPresAttrStyleUpdateEnabled(bool enabled)
    {
        is_svg_eager_pres_attr_style_update_enabled_ = enabled;
    }
    static void SetSvgExternalResourcesEnabled(bool enabled)
    {
        is_svg_external_resources_enabled_ = enabled;
    }
    static void SetSvgFilterUserSpaceViewportForNonSvgEnabled(bool enabled)
    {
        is_svg_filter_user_space_viewport_for_non_svg_enabled_ = enabled;
    }
    static void SetSvgGradientColorInterpolationLinearRgbSupportEnabled(bool enabled)
    {
        is_svg_gradient_color_interpolation_linear_rgb_support_enabled_ = enabled;
    }
    static void SetSvgInlineRootPixelSnappingScaleAdjustmentEnabled(bool enabled)
    {
        is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_ = enabled;
    }
    static void SetSvgNoPixelSnappingScaleAdjustmentEnabled(bool enabled)
    {
        is_svg_no_pixel_snapping_scale_adjustment_enabled_ = enabled;
    }
    static void SetSvgTransformOptimizationEnabled(bool enabled)
    {
        is_svg_transform_optimization_enabled_ = enabled;
    }
    static void SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled(bool enabled)
    {
        is_synthesized_keyboard_events_for_accessibility_actions_enabled_ = enabled;
    }
    static void SetSystemFallbackEmojiVSSupportEnabled(bool enabled)
    {
        is_system_fallback_emoji_vs_support_enabled_ = enabled;
    }
    static void SetSystemWakeLockEnabled(bool enabled)
    {
        is_system_wake_lock_enabled_ = enabled;
    }
    static void SetTestBlinkFeatureDefaultEnabled(bool enabled)
    {
        is_test_blink_feature_default_enabled_ = enabled;
    }
    static void SetTestFeatureEnabled(bool enabled)
    {
        is_test_feature_enabled_ = enabled;
    }
    static void SetTestFeatureDependentEnabled(bool enabled)
    {
        is_test_feature_dependent_enabled_ = enabled;
    }
    static void SetTestFeatureImpliedEnabled(bool enabled)
    {
        is_test_feature_implied_enabled_ = enabled;
    }
    static void SetTestFeatureProtectedEnabled(bool enabled);
    static void SetTestFeatureProtectedDependentEnabled(bool enabled);
    static void SetTestFeatureProtectedImpliedEnabled(bool enabled);
    static void SetTestFeatureStableEnabled(bool enabled)
    {
        is_test_feature_stable_enabled_ = enabled;
    }
    static void SetTextDetectorEnabled(bool enabled)
    {
        is_text_detector_enabled_ = enabled;
    }
    static void SetTextDiffSplitFixEnabled(bool enabled)
    {
        is_text_diff_split_fix_enabled_ = enabled;
    }
    static void SetTextFragmentAPIEnabled(bool enabled)
    {
        is_text_fragment_api_enabled_ = enabled;
    }
    static void SetTextFragmentIdentifiersEnabled(bool enabled)
    {
        is_text_fragment_identifiers_enabled_ = enabled;
    }
    static void SetTextFragmentTapOpensContextMenuEnabled(bool enabled)
    {
        is_text_fragment_tap_opens_context_menu_enabled_ = enabled;
    }
    static void SetTextInputNotAlwaysDirAutoEnabled(bool enabled)
    {
        is_text_input_not_always_dir_auto_enabled_ = enabled;
    }
    static void SetTextMetricsBaselinesEnabled(bool enabled)
    {
        is_text_metrics_baselines_enabled_ = enabled;
    }
    static void SetTextSegmentBoundaryForElementWithFloatStyleEnabled(bool enabled)
    {
        is_text_segment_boundary_for_element_with_float_style_enabled_ = enabled;
    }
    static void SetTextSizeAdjustImprovementsEnabled(bool enabled)
    {
        is_text_size_adjust_improvements_enabled_ = enabled;
    }
    static void SetTextTransformAndSecurityFixEnabled(bool enabled)
    {
        is_text_transform_and_security_fix_enabled_ = enabled;
    }
    static void SetTimelineScopeEnabled(bool enabled)
    {
        is_timeline_scope_enabled_ = enabled;
    }
    static void SetTimerThrottlingForBackgroundTabsEnabled(bool enabled)
    {
        is_timer_throttling_for_background_tabs_enabled_ = enabled;
    }
    static void SetTimestampBasedCLSTrackingEnabled(bool enabled)
    {
        is_timestamp_based_cls_tracking_enabled_ = enabled;
    }
    static void SetTimeZoneChangeEventEnabled(bool enabled)
    {
        is_time_zone_change_event_enabled_ = enabled;
    }
    static void SetTopicsAPIEnabled(bool enabled)
    {
        is_topics_api_enabled_ = enabled;
    }
    static void SetTopicsDocumentAPIEnabled(bool enabled)
    {
        is_topics_document_api_enabled_ = enabled;
    }
    static void SetTopLayerInactiveDocumentExceptionsEnabled(bool enabled)
    {
        is_top_layer_inactive_document_exceptions_enabled_ = enabled;
    }
    static void SetTopLevelTpcdEnabled(bool enabled)
    {
        is_top_level_tpcd_enabled_ = enabled;
    }
    static void SetTouchDragAndContextMenuEnabled(bool enabled)
    {
        is_touch_drag_and_context_menu_enabled_ = enabled;
    }
    static void SetTouchDragOnShortPressEnabled(bool enabled)
    {
        is_touch_drag_on_short_press_enabled_ = enabled;
    }
    static void SetTouchEventFeatureDetectionEnabled(bool enabled)
    {
        is_touch_event_feature_detection_enabled_ = enabled;
    }
    static void SetTouchTextEditingRedesignEnabled(bool enabled)
    {
        is_touch_text_editing_redesign_enabled_ = enabled;
    }
    static void SetTpcdEnabled(bool enabled)
    {
        is_tpcd_enabled_ = enabled;
    }
    static void SetTransferableRTCDataChannelEnabled(bool enabled)
    {
        is_transferable_rtc_data_channel_enabled_ = enabled;
    }
    static void SetTranslateServiceEnabled(bool enabled)
    {
        is_translate_service_enabled_ = enabled;
    }
    static void SetTranslationAPIEnabled(bool enabled)
    {
        is_translation_api_enabled_ = enabled;
    }
    static void SetTranslationAPIEntryPointEnabled(bool enabled)
    {
        is_translation_api_entry_point_enabled_ = enabled;
    }
    static void SetTrustedTypeBeforePolicyCreationEventEnabled(bool enabled)
    {
        is_trusted_type_before_policy_creation_event_enabled_ = enabled;
    }
    static void SetTrustedTypesFromLiteralEnabled(bool enabled)
    {
        is_trusted_types_from_literal_enabled_ = enabled;
    }
    static void SetTrustedTypesUseCodeLikeEnabled(bool enabled)
    {
        is_trusted_types_use_code_like_enabled_ = enabled;
    }
    static void SetUnclosedFormControlIsInvalidEnabled(bool enabled)
    {
        is_unclosed_form_control_is_invalid_enabled_ = enabled;
    }
    static void SetUnexposedTaskIdsEnabled(bool enabled)
    {
        is_unexposed_task_ids_enabled_ = enabled;
    }
    static void SetUnownedAnimationsSkipCSSEventsEnabled(bool enabled)
    {
        is_unowned_animations_skip_css_events_enabled_ = enabled;
    }
    static void SetUnrestrictedMeasureUserAgentSpecificMemoryEnabled(bool enabled)
    {
        is_unrestricted_measure_user_agent_specific_memory_enabled_ = enabled;
    }
    static void SetUnrestrictedSharedArrayBufferEnabled(bool enabled)
    {
        is_unrestricted_shared_array_buffer_enabled_ = enabled;
    }
    static void SetUnrestrictedUsbEnabled(bool enabled)
    {
        is_unrestricted_usb_enabled_ = enabled;
    }
    static void SetURLPatternCompareComponentEnabled(bool enabled)
    {
        is_url_pattern_compare_component_enabled_ = enabled;
    }
    static void SetURLSearchParamsHasAndDeleteMultipleArgsEnabled(bool enabled)
    {
        is_url_search_params_has_and_delete_multiple_args_enabled_ = enabled;
    }
    static void SetUseBeginFramePresentationFeedbackEnabled(bool enabled)
    {
        is_use_begin_frame_presentation_feedback_enabled_ = enabled;
    }
    static void SetUseLowQualityInterpolationEnabled(bool enabled)
    {
        is_use_low_quality_interpolation_enabled_ = enabled;
    }
    static void SetUserActivationSameOriginVisibilityEnabled(bool enabled)
    {
        is_user_activation_same_origin_visibility_enabled_ = enabled;
    }
    static void SetUseSelectionFocusNodeForCaretNavigationEnabled(bool enabled)
    {
        is_use_selection_focus_node_for_caret_navigation_enabled_ = enabled;
    }
    static void SetUseUndoStepElementDispatchBeforeInputEnabled(bool enabled)
    {
        is_use_undo_step_element_dispatch_before_input_enabled_ = enabled;
    }
    static void SetV8IdleTasksEnabled(bool enabled)
    {
        is_v8_idle_tasks_enabled_ = enabled;
    }
    static void SetVideoAutoFullscreenEnabled(bool enabled)
    {
        is_video_auto_fullscreen_enabled_ = enabled;
    }
    static void SetVideoFrameMetadataBackgroundBlurEnabled(bool enabled)
    {
        is_video_frame_metadata_background_blur_enabled_ = enabled;
    }
    static void SetVideoFullscreenOrientationLockEnabled(bool enabled)
    {
        is_video_fullscreen_orientation_lock_enabled_ = enabled;
    }
    static void SetVideoRotateToFullscreenEnabled(bool enabled)
    {
        is_video_rotate_to_fullscreen_enabled_ = enabled;
    }
    static void SetVideoTrackGeneratorEnabled(bool enabled)
    {
        is_video_track_generator_enabled_ = enabled;
    }
    static void SetVideoTrackGeneratorInWindowEnabled(bool enabled)
    {
        is_video_track_generator_in_window_enabled_ = enabled;
    }
    static void SetVideoTrackGeneratorInWorkerEnabled(bool enabled)
    {
        is_video_track_generator_in_worker_enabled_ = enabled;
    }
    static void SetViewportChangesUpdateTextAutosizingEnabled(bool enabled)
    {
        is_viewport_changes_update_text_autosizing_enabled_ = enabled;
    }
    static void SetViewportHeightClientHintHeaderEnabled(bool enabled)
    {
        is_viewport_height_client_hint_header_enabled_ = enabled;
    }
    static void SetViewportSegmentsEnabled(bool enabled)
    {
        is_viewport_segments_enabled_ = enabled;
    }
    static void SetViewTransitionDisableSnapBrowserControlsOnHiddenEnabled(bool enabled)
    {
        is_view_transition_disable_snap_browser_controls_on_hidden_enabled_ = enabled;
    }
    static void SetViewTransitionLayeredCaptureEnabled(bool enabled)
    {
        is_view_transition_layered_capture_enabled_ = enabled;
    }
    static void SetViewTransitionLongCallbackTimeoutForTestingEnabled(bool enabled)
    {
        is_view_transition_long_callback_timeout_for_testing_enabled_ = enabled;
    }
    static void SetViewTransitionOnNavigationEnabled(bool enabled)
    {
        is_view_transition_on_navigation_enabled_ = enabled;
    }
    static void SetViewTransitionOnNavigationForIframesEnabled(bool enabled)
    {
        is_view_transition_on_navigation_for_iframes_enabled_ = enabled;
    }
    static void SetViewTransitionOverflowRectFromSurfaceEnabled(bool enabled)
    {
        is_view_transition_overflow_rect_from_surface_enabled_ = enabled;
    }
    static void SetViewTransitionTreeScopedNamesEnabled(bool enabled)
    {
        is_view_transition_tree_scoped_names_enabled_ = enabled;
    }
    static void SetViewTransitionTypesEnabled(bool enabled)
    {
        is_view_transition_types_enabled_ = enabled;
    }
    static void SetVisibilityCollapseColumnEnabled(bool enabled)
    {
        is_visibility_collapse_column_enabled_ = enabled;
    }
    static void SetVisualViewportOnScrollEndEnabled(bool enabled)
    {
        is_visual_viewport_on_scroll_end_enabled_ = enabled;
    }
    static void SetWakeLockEnabled(bool enabled)
    {
        is_wake_lock_enabled_ = enabled;
    }
    static void SetWarnOnContentVisibilityRenderAccessEnabled(bool enabled)
    {
        is_warn_on_content_visibility_render_access_enabled_ = enabled;
    }
    static void SetWebAnimationsSVGEnabled(bool enabled)
    {
        is_web_animations_svg_enabled_ = enabled;
    }
    static void SetWebAppInstallationEnabled(bool enabled)
    {
        is_web_app_installation_enabled_ = enabled;
    }
    static void SetWebAppLaunchQueueEnabled(bool enabled)
    {
        is_web_app_launch_queue_enabled_ = enabled;
    }
    static void SetWebAppScopeExtensionsEnabled(bool enabled)
    {
        is_web_app_scope_extensions_enabled_ = enabled;
    }
    static void SetWebAppTabStripEnabled(bool enabled)
    {
        is_web_app_tab_strip_enabled_ = enabled;
    }
    static void SetWebAppTabStripCustomizationsEnabled(bool enabled)
    {
        is_web_app_tab_strip_customizations_enabled_ = enabled;
    }
    static void SetWebAppTranslationsEnabled(bool enabled)
    {
        is_web_app_translations_enabled_ = enabled;
    }
    static void SetWebAppUrlHandlingEnabled(bool enabled)
    {
        is_web_app_url_handling_enabled_ = enabled;
    }
    static void SetWebAssemblyJSPromiseIntegrationEnabled(bool enabled)
    {
        is_web_assembly_js_promise_integration_enabled_ = enabled;
    }
    static void SetWebAssemblyJSStringBuiltinsEnabled(bool enabled)
    {
        is_web_assembly_js_string_builtins_enabled_ = enabled;
    }
    static void SetWebAudioBypassOutputBufferingEnabled(bool enabled)
    {
        is_web_audio_bypass_output_buffering_enabled_ = enabled;
    }
    static void SetWebAudioBypassOutputBufferingOptOutEnabled(bool enabled)
    {
        is_web_audio_bypass_output_buffering_opt_out_enabled_ = enabled;
    }
    static void SetWebAuthEnabled(bool enabled)
    {
        is_web_auth_enabled_ = enabled;
    }
    static void SetWebAuthAuthenticatorAttachmentEnabled(bool enabled)
    {
        is_web_auth_authenticator_attachment_enabled_ = enabled;
    }
    static void SetWebAuthenticationAmbientEnabled(bool enabled)
    {
        is_web_authentication_ambient_enabled_ = enabled;
    }
    static void SetWebAuthenticationAttestationFormatsEnabled(bool enabled)
    {
        is_web_authentication_attestation_formats_enabled_ = enabled;
    }
    static void SetWebAuthenticationClientCapabilitiesEnabled(bool enabled)
    {
        is_web_authentication_client_capabilities_enabled_ = enabled;
    }
    static void SetWebAuthenticationJSONSerializationEnabled(bool enabled)
    {
        is_web_authentication_js_on_serialization_enabled_ = enabled;
    }
    static void SetWebAuthenticationLargeBlobExtensionEnabled(bool enabled)
    {
        is_web_authentication_large_blob_extension_enabled_ = enabled;
    }
    static void SetWebAuthenticationPRFEnabled(bool enabled)
    {
        is_web_authentication_prf_enabled_ = enabled;
    }
    static void SetWebAuthenticationRemoteDesktopSupportEnabled(bool enabled)
    {
        is_web_authentication_remote_desktop_support_enabled_ = enabled;
    }
    static void SetWebAuthenticationSupplementalPubKeysEnabled(bool enabled)
    {
        is_web_authentication_supplemental_pub_keys_enabled_ = enabled;
    }
    static void SetWebBluetoothEnabled(bool enabled)
    {
        is_web_bluetooth_enabled_ = enabled;
    }
    static void SetWebBluetoothGetDevicesEnabled(bool enabled)
    {
        is_web_bluetooth_get_devices_enabled_ = enabled;
    }
    static void SetWebBluetoothScanningEnabled(bool enabled)
    {
        is_web_bluetooth_scanning_enabled_ = enabled;
    }
    static void SetWebBluetoothWatchAdvertisementsEnabled(bool enabled)
    {
        is_web_bluetooth_watch_advertisements_enabled_ = enabled;
    }
    static void SetWebCodecsCopyToRGBEnabled(bool enabled)
    {
        is_webcodecs_copy_to_rgb_enabled_ = enabled;
    }
    static void SetWebCodecsHBDFormatsEnabled(bool enabled)
    {
        is_webcodecs_hbd_formats_enabled_ = enabled;
    }
    static void SetWebCodecsOrientationEnabled(bool enabled)
    {
        is_webcodecs_orientation_enabled_ = enabled;
    }
    static void SetWebCodecsVideoEncoderBuffersEnabled(bool enabled)
    {
        is_webcodecs_video_encoder_buffers_enabled_ = enabled;
    }
    static void SetWebCryptoCurve25519Enabled(bool enabled)
    {
        is_web_crypto_curve_25519_enabled_ = enabled;
    }
    static void SetWebFontResizeLCPEnabled(bool enabled)
    {
        is_web_font_resize_lcp_enabled_ = enabled;
    }
    static void SetWebGLDeveloperExtensionsEnabled(bool enabled)
    {
        is_webgl_developer_extensions_enabled_ = enabled;
    }
    static void SetWebGLDraftExtensionsEnabled(bool enabled)
    {
        is_webgl_draft_extensions_enabled_ = enabled;
    }
    static void SetWebGLDrawingBufferStorageEnabled(bool enabled)
    {
        is_webgl_drawing_buffer_storage_enabled_ = enabled;
    }
    static void SetWebGLImageChromiumEnabled(bool enabled)
    {
        is_webgl_image_chromium_enabled_ = enabled;
    }
    static void SetWebGPUCanvasContextGetConfigurationEnabled(bool enabled)
    {
        is_webgpu_canvas_context_get_configuration_enabled_ = enabled;
    }
    static void SetWebGPUDeveloperFeaturesEnabled(bool enabled)
    {
        is_webgpu_developer_features_enabled_ = enabled;
    }
    static void SetWebGPUDeviceAdapterInfoEnabled(bool enabled)
    {
        is_webgpu_device_adapter_info_enabled_ = enabled;
    }
    static void SetWebGPUExperimentalFeaturesEnabled(bool enabled)
    {
        is_webgpu_experimental_features_enabled_ = enabled;
    }
    static void SetWebGPUHDREnabled(bool enabled)
    {
        is_webgpu_hdr_enabled_ = enabled;
    }
    static void SetWebGPUSubgroupsFeaturesEnabled(bool enabled)
    {
        is_webgpu_subgroups_features_enabled_ = enabled;
    }
    static void SetWebGPUTextureViewUsageEnabled(bool enabled)
    {
        is_webgpu_texture_view_usage_enabled_ = enabled;
    }
    static void SetWebHIDEnabled(bool enabled)
    {
        is_web_hid_enabled_ = enabled;
    }
    static void SetWebHIDOnDedicatedWorkersEnabled(bool enabled)
    {
        is_web_hid_on_dedicated_workers_enabled_ = enabled;
    }
    static void SetWebHIDOnServiceWorkersEnabled(bool enabled)
    {
        is_web_hid_on_service_workers_enabled_ = enabled;
    }
    static void SetWebIdentityDigitalCredentialsEnabled(bool enabled)
    {
        is_web_identity_digital_credentials_enabled_ = enabled;
    }
    static void SetWebIDLBigIntUsesToBigIntEnabled(bool enabled)
    {
        is_web_idl_big_int_uses_to_big_int_enabled_ = enabled;
    }
    static void SetWebNFCEnabled(bool enabled)
    {
        is_web_nfc_enabled_ = enabled;
    }
    static void SetWebOTPEnabled(bool enabled)
    {
        is_web_otp_enabled_ = enabled;
    }
    static void SetWebOTPAssertionFeaturePolicyEnabled(bool enabled)
    {
        is_web_otp_assertion_feature_policy_enabled_ = enabled;
    }
    static void SetWebPreferencesEnabled(bool enabled)
    {
        is_web_preferences_enabled_ = enabled;
    }
    static void SetWebPrintingEnabled(bool enabled)
    {
        is_web_printing_enabled_ = enabled;
    }
    static void SetWebShareEnabled(bool enabled)
    {
        is_web_share_enabled_ = enabled;
    }
    static void SetWebSocketStreamEnabled(bool enabled)
    {
        is_websocket_stream_enabled_ = enabled;
    }
    static void SetWebTransportCustomCertificatesEnabled(bool enabled)
    {
        is_web_transport_custom_certificates_enabled_ = enabled;
    }
    static void SetWebTransportStatsEnabled(bool enabled)
    {
        is_web_transport_stats_enabled_ = enabled;
    }
    static void SetWebUSBEnabled(bool enabled)
    {
        is_web_usb_enabled_ = enabled;
    }
    static void SetWebUSBOnDedicatedWorkersEnabled(bool enabled)
    {
        is_web_usb_on_dedicated_workers_enabled_ = enabled;
    }
    static void SetWebUSBOnServiceWorkersEnabled(bool enabled)
    {
        is_web_usb_on_service_workers_enabled_ = enabled;
    }
    static void SetWebViewXRequestedWithDeprecationEnabled(bool enabled)
    {
        is_web_view_xr_equested_with_deprecation_enabled_ = enabled;
    }
    static void SetWebVTTRegionsEnabled(bool enabled)
    {
        is_web_vtt_regions_enabled_ = enabled;
    }
    static void SetWebXREnabled(bool enabled)
    {
        is_web_xr_enabled_ = enabled;
    }
    static void SetWebXREnabledFeaturesEnabled(bool enabled)
    {
        is_web_xr_enabled_features_enabled_ = enabled;
    }
    static void SetWebXRFrameRateEnabled(bool enabled)
    {
        is_web_xr_frame_rate_enabled_ = enabled;
    }
    static void SetWebXRFrontFacingEnabled(bool enabled)
    {
        is_web_xr_front_facing_enabled_ = enabled;
    }
    static void SetWebXRGPUBindingEnabled(bool enabled)
    {
        is_web_xr_gpu_binding_enabled_ = enabled;
    }
    static void SetWebXRHandInputEnabled(bool enabled)
    {
        is_web_xr_hand_input_enabled_ = enabled;
    }
    static void SetWebXRHitTestEntityTypesEnabled(bool enabled)
    {
        is_web_xr_hit_test_entity_types_enabled_ = enabled;
    }
    static void SetWebXRImageTrackingEnabled(bool enabled)
    {
        is_web_xr_image_tracking_enabled_ = enabled;
    }
    static void SetWebXRLayersEnabled(bool enabled)
    {
        is_web_xr_layers_enabled_ = enabled;
    }
    static void SetWebXRLayersCommonEnabled(bool enabled)
    {
        is_web_xr_layers_common_enabled_ = enabled;
    }
    static void SetWebXRPlaneDetectionEnabled(bool enabled)
    {
        is_web_xr_plane_detection_enabled_ = enabled;
    }
    static void SetWebXRPoseMotionDataEnabled(bool enabled)
    {
        is_web_xr_pose_motion_data_enabled_ = enabled;
    }
    static void SetWebXRSpecParityEnabled(bool enabled)
    {
        is_web_xr_spec_parity_enabled_ = enabled;
    }
    static void SetWindowDefaultStatusEnabled(bool enabled)
    {
        is_window_default_status_enabled_ = enabled;
    }
    static void SetXMLParserMergeAdjacentCDataSectionsEnabled(bool enabled)
    {
        is_xml_parser_merge_adjacent_c_data_sections_enabled_ = enabled;
    }
    static void SetZeroCopyTabCaptureEnabled(bool enabled)
    {
        is_zero_copy_tab_capture_enabled_ = enabled;
    }

private:
    friend class RuntimeEnabledFeaturesTestHelpers;

    static bool is_accelerated_2d_canvas_enabled_;
    static bool is_accelerated_small_canvases_enabled_;
    static bool is_accessibility_aria_virtual_content_enabled_;
    static bool is_accessibility_expose_display_none_enabled_;
    static bool is_accessibility_min_role_tabbable_enabled_;
    static bool is_accessibility_os_level_bold_text_enabled_;
    static bool is_accessibility_prohibited_names_enabled_;
    static bool is_accessibility_serialization_size_metrics_enabled_;
    static bool is_accessibility_use_ax_position_for_document_markers_enabled_;
    static bool is_address_space_enabled_;
    static bool is_ad_interest_group_api_enabled_;
    static bool is_adjust_end_of_next_paragraph_if_moved_paragraph_is_updated_enabled_;
    static bool is_ad_tagging_enabled_;
    static bool is_ai_prompt_api_enabled_;
    static bool is_ai_prompt_api_for_extension_enabled_;
    static bool is_ai_prompt_api_for_web_platform_enabled_;
    static bool is_ai_rewriter_api_enabled_;
    static bool is_ai_summarization_api_enabled_;
    static bool is_ai_writer_api_enabled_;
    static bool is_allow_content_initiated_data_url_navigations_enabled_;
    static bool is_allow_java_script_to_reset_autofill_state_enabled_;
    static bool is_allow_preloading_with_csp_meta_tag_enabled_;
    static bool is_allow_ur_ns_in_iframes_enabled_;
    static bool is_android_downloadable_fonts_matching_enabled_;
    static bool is_animation_progress_api_enabled_;
    static bool is_animation_worklet_enabled_;
    static bool is_anonymous_iframe_enabled_;
    static bool is_aom_aria_relationship_properties_enabled_;
    static bool is_aom_aria_relationship_properties_aria_owns_enabled_;
    static bool is_app_title_enabled_;
    static bool is_aria_actions_enabled_;
    static bool is_aria_notify_enabled_;
    static bool is_aria_row_col_index_text_enabled_;
    static bool is_atomic_move_api_enabled_;
    static bool is_attribution_reporting_enabled_;
    static bool is_attribution_reporting_cross_app_web_enabled_;
    static bool is_attribution_reporting_interface_enabled_;
    static bool is_audio_context_interrupted_state_enabled_;
    static bool is_audio_context_on_error_enabled_;
    static bool is_audio_context_playout_stats_enabled_;
    static bool is_audio_context_set_sink_id_enabled_;
    static bool is_audio_output_devices_enabled_;
    static bool is_audio_video_tracks_enabled_;
    static bool is_aura_scrollbar_uses_nine_patch_track_enabled_;
    static bool is_aura_scrollbar_uses_solid_color_thumb_enabled_;
    static bool is_auto_dark_mode_enabled_;
    static bool is_automation_controlled_enabled_;
    static bool is_auto_picture_in_picture_video_heuristics_enabled_;
    static bool is_backface_visibility_interop_enabled_;
    static bool is_back_forward_cache_enabled_;
    static bool is_back_forward_cache_experiment_http_header_enabled_;
    static bool is_back_forward_cache_not_restored_reasons_enabled_;
    static bool is_back_forward_transitions_enabled_;
    static bool is_background_fetch_enabled_;
    static bool is_barcode_detector_enabled_;
    static bool is_bidi_caret_affinity_enabled_;
    static bool is_blink_extension_chrome_os_enabled_;
    static bool is_blink_extension_chrome_os_kiosk_enabled_;
    static bool is_blink_extension_diagnostics_enabled_;
    static bool is_blink_extension_web_view_enabled_;
    static bool is_blink_extension_web_view_media_integrity_enabled_;
    static bool is_blink_lifecycle_script_forbidden_enabled_;
    static bool is_blink_runtime_call_stats_enabled_;
    static bool is_blocking_focus_without_user_activation_enabled_;
    static bool is_boundary_event_dispatch_tracks_node_removal_enabled_;
    static bool is_box_decoration_break_enabled_;
    static bool is_break_iterator_hyphen_minus_enabled_;
    static bool is_browser_verified_user_activation_keyboard_enabled_;
    static bool is_browser_verified_user_activation_mouse_enabled_;
    static bool is_buffered_bytes_consumer_limit_size_enabled_;
    static bool is_built_in_aiapi_enabled_;
    static bool is_bypass_pepc_security_for_testing_enabled_;
    static bool is_cache_storage_code_cache_hint_enabled_;
    static bool is_calendar_picker_month_popup_button_disabled_color_enabled_;
    static bool is_call_exit_node_without_layout_object_enabled_;
    static bool is_canvas_2d_canvas_filter_enabled_;
    static bool is_canvas_2d_gpu_transfer_enabled_;
    static bool is_canvas_2d_image_chromium_enabled_;
    static bool is_canvas_2d_layers_enabled_;
    static bool is_canvas_2d_layers_with_options_enabled_;
    static bool is_canvas_2d_mesh_enabled_;
    static bool is_canvas_2d_text_metrics_shaping_enabled_;
    static bool is_canvas_floating_point_enabled_;
    static bool is_canvas_hdr_enabled_;
    static bool is_canvas_image_smoothing_enabled_;
    static bool is_canvas_place_element_enabled_;
    static bool is_canvas_uses_arc_paint_op_enabled_;
    static bool is_capability_delegation_display_capture_request_enabled_;
    static bool is_capture_controller_enabled_;
    static bool is_captured_mouse_events_enabled_;
    static bool is_captured_surface_control_enabled_;
    static bool is_capture_handle_enabled_;
    static bool is_caret_position_from_point_enabled_;
    static bool is_cct_new_rfm_push_behavior_enabled_;
    static bool is_check_if_highest_root_contains_position_anchor_node_enabled_;
    static bool is_check_visibility_extra_properties_enabled_;
    static bool is_click_to_captured_pointer_enabled_;
    static bool is_clipboard_item_with_dom_string_support_enabled_;
    static bool is_clip_path_reject_empty_paths_enabled_;
    static bool is_coalesce_selectionchange_event_enabled_;
    static bool is_coep_reflection_enabled_;
    static bool is_composite_bg_color_animation_enabled_;
    static bool is_composite_box_shadow_animation_enabled_;
    static bool is_composite_clip_path_animation_enabled_;
    static bool is_composited_animations_cancelled_asynchronously_enabled_;
    static bool is_composited_selection_update_enabled_;
    static bool is_composition_foreground_markers_enabled_;
    static bool is_compression_dictionary_transport_enabled_;
    static bool is_compression_dictionary_transport_backend_enabled_;
    static bool is_computed_accessibility_info_enabled_;
    static bool is_compute_pressure_enabled_;
    static bool is_concurrent_view_transitions_spa_enabled_;
    static bool is_contacts_manager_enabled_;
    static bool is_contacts_manager_extra_properties_enabled_;
    static bool is_container_type_no_layout_containment_enabled_;
    static bool is_content_index_enabled_;
    static bool is_context_menu_enabled_;
    static bool is_continue_event_timing_recording_when_buffer_is_full_enabled_;
    static bool is_controlled_frame_enabled_;
    static bool is_cookie_deprecation_facilitated_testing_enabled_;
    static bool is_cooperative_scheduling_enabled_;
    static bool is_coop_restrict_properties_enabled_;
    static bool is_cors_rfc_1918_enabled_;
    static bool is_create_input_shadow_tree_during_layout_enabled_;
    static bool is_credential_manager_report_enabled_;
    static bool is_cross_frame_performance_timeline_enabled_;
    static bool is_css_accent_color_keyword_enabled_;
    static bool is_css_advanced_attr_function_enabled_;
    static bool is_css_anchor_scope_enabled_;
    static bool is_css_anchor_size_insets_margins_enabled_;
    static bool is_css_at_property_string_syntax_enabled_;
    static bool is_css_at_rule_counter_style_image_symbols_enabled_;
    static bool is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
    static bool is_css_background_clip_unprefix_enabled_;
    static bool is_css_calc_simplification_and_serialization_enabled_;
    static bool is_css_calc_size_function_enabled_;
    static bool is_css_caret_animation_enabled_;
    static bool is_css_cascade_correct_scope_enabled_;
    static bool is_css_case_sensitive_selector_enabled_;
    static bool is_css_color_contrast_enabled_;
    static bool is_css_color_typed_om_enabled_;
    static bool is_css_computed_style_full_pseudo_element_parser_enabled_;
    static bool is_css_content_visibility_implies_contain_intrinsic_size_auto_enabled_;
    static bool is_css_cross_fade_enabled_;
    static bool is_css_custom_state_deprecated_syntax_enabled_;
    static bool is_css_custom_state_new_syntax_enabled_;
    static bool is_css_dynamic_range_limit_enabled_;
    static bool is_css_enumerated_custom_properties_enabled_;
    static bool is_css_exponential_functions_enabled_;
    static bool is_css_flat_tree_container_enabled_;
    static bool is_css_font_size_adjust_enabled_;
    static bool is_css_functions_enabled_;
    static bool is_css_gap_decoration_enabled_;
    static bool is_css_hex_alpha_color_enabled_;
    static bool is_css_inert_enabled_;
    static bool is_css_inset_area_property_enabled_;
    static bool is_css_keyframes_rule_length_enabled_;
    static bool is_css_layout_api_enabled_;
    static bool is_css_lazy_parsing_fast_path_enabled_;
    static bool is_css_line_clamp_enabled_;
    static bool is_css_line_clamp_webkit_box_blockification_enabled_;
    static bool is_css_logical_overflow_enabled_;
    static bool is_css_marker_nested_pseudo_element_enabled_;
    static bool is_css_masonry_layout_enabled_;
    static bool is_css_mixins_enabled_;
    static bool is_css_nested_declarations_enabled_;
    static bool is_css_nested_pseudo_elements_enabled_;
    static bool is_css_overflow_container_queries_enabled_;
    static bool is_css_paint_api_arguments_enabled_;
    static bool is_css_parser_ignore_charset_for_urls_enabled_;
    static bool is_css_part_allows_more_selectors_after_enabled_;
    static bool is_css_position_area_value_enabled_;
    static bool is_css_position_sticky_static_scroll_position_enabled_;
    static bool is_css_progress_notation_enabled_;
    static bool is_css_pseudo_column_enabled_;
    static bool is_css_pseudo_has_slotted_enabled_;
    static bool is_css_pseudo_open_closed_enabled_;
    static bool is_css_pseudo_playing_paused_enabled_;
    static bool is_css_pseudo_scroll_buttons_enabled_;
    static bool is_css_pseudo_scroll_markers_enabled_;
    static bool is_css_reading_flow_enabled_;
    static bool is_css_relative_color_enabled_;
    static bool is_css_relative_color_late_resolve_always_enabled_;
    static bool is_css_relative_color_preserve_none_enabled_;
    static bool is_css_relative_color_supports_currentcolor_enabled_;
    static bool is_css_resize_auto_enabled_;
    static bool is_css_scroll_snap_change_event_enabled_;
    static bool is_css_scroll_snap_changing_event_enabled_;
    static bool is_css_scroll_snap_events_enabled_;
    static bool is_css_scroll_start_enabled_;
    static bool is_css_scroll_start_target_enabled_;
    static bool is_css_scroll_state_container_queries_enabled_;
    static bool is_css_selector_fragment_anchor_enabled_;
    static bool is_css_sign_related_functions_enabled_;
    static bool is_css_snap_container_queries_enabled_;
    static bool is_css_stepped_value_functions_enabled_;
    static bool is_css_sticky_container_queries_enabled_;
    static bool is_css_supports_at_rule_function_enabled_;
    static bool is_css_supports_for_import_rules_enabled_;
    static bool is_css_system_accent_color_enabled_;
    static bool is_css_text_auto_space_enabled_;
    static bool is_css_text_box_trim_enabled_;
    static bool is_css_text_spacing_enabled_;
    static bool is_css_tree_scoped_timelines_enabled_;
    static bool is_css_user_select_contain_enabled_;
    static bool is_css_video_dynamic_range_media_queries_enabled_;
    static bool is_css_view_transition_auto_name_enabled_;
    static bool is_css_view_transition_class_enabled_;
    static bool is_cursor_anchor_info_mojo_pipe_enabled_;
    static bool is_customizable_select_enabled_;
    static bool is_database_enabled_;
    static bool is_deprecated_request_adapter_info_enabled_;
    static bool is_deprecate_unload_opt_out_enabled_;
    static bool is_desktop_capture_disable_local_echo_control_enabled_;
    static bool is_desktop_pw_as_additional_windowing_controls_enabled_;
    static bool is_desktop_pw_as_sub_apps_enabled_;
    static bool is_details_styling_enabled_;
    static bool is_device_attributes_enabled_;
    static bool is_device_orientation_request_permission_enabled_;
    static bool is_device_posture_enabled_;
    static bool is_dialog_close_when_open_removed_enabled_;
    static bool is_dialog_element_toggle_events_enabled_;
    static bool is_dialog_new_focus_behavior_enabled_;
    static bool is_digital_goods_enabled_;
    static bool is_digital_goods_v_2_1_enabled_;
    static bool is_dir_auto_fix_slot_exclusions_enabled_;
    static bool is_direct_sockets_enabled_;
    static bool is_disable_ahem_antialias_enabled_;
    static bool is_disable_different_origin_subframe_dialog_suppression_enabled_;
    static bool is_disable_hardware_noise_suppression_enabled_;
    static bool is_disable_reduce_accept_language_enabled_;
    static bool is_disable_select_all_for_empty_text_enabled_;
    static bool is_disable_third_party_storage_partitioning_2_enabled_;
    static bool is_dispatch_before_input_for_spin_button_interactions_enabled_;
    static bool is_dispatch_hidden_visibility_transitions_enabled_;
    static bool is_dispatch_selectionchange_event_per_element_enabled_;
    static bool is_display_contents_focusable_enabled_;
    static bool is_display_cutout_api_enabled_;
    static bool is_document_cookie_enabled_;
    static bool is_document_domain_enabled_;
    static bool is_document_install_chunking_enabled_;
    static bool is_document_isolation_policy_enabled_;
    static bool is_document_open_origin_alias_removal_enabled_;
    static bool is_document_open_sandbox_inheritance_removal_enabled_;
    static bool is_document_picture_in_picture_api_enabled_;
    static bool is_document_picture_in_picture_prefer_initial_placement_enabled_;
    static bool is_document_picture_in_picture_user_activation_enabled_;
    static bool is_document_policy_document_domain_enabled_;
    static bool is_document_policy_expect_no_linked_resources_enabled_;
    static bool is_document_policy_include_js_call_stacks_in_crash_reports_enabled_;
    static bool is_document_policy_negotiation_enabled_;
    static bool is_document_policy_sync_xhr_enabled_;
    static bool is_document_render_blocking_enabled_;
    static bool is_document_write_enabled_;
    static bool is_dom_parts_api_enabled_;
    static bool is_dom_parts_api_minimal_enabled_;
    static bool is_drop_url_as_plain_text_in_plain_text_only_editable_position_enabled_;
    static bool is_dynamic_safe_area_insets_enabled_;
    static bool is_dynamic_safe_area_insets_on_scroll_enabled_;
    static bool is_element_capture_enabled_;
    static bool is_element_get_inner_html_enabled_;
    static bool is_enforce_anonymity_exposure_enabled_;
    static bool is_escape_lt_gt_in_attributes_enabled_;
    static bool is_event_timing_handle_keyboard_event_simulated_click_enabled_;
    static bool is_event_timing_interaction_count_enabled_;
    static bool is_event_timing_selection_auto_scroll_no_interaction_id_enabled_;
    static bool is_event_timing_tap_stop_scroll_no_interaction_id_enabled_;
    static bool is_exclude_transparent_texts_from_being_lcp_eligible_enabled_;
    static bool is_experimental_content_security_policy_features_enabled_;
    static bool is_experimental_js_profiler_markers_enabled_;
    static bool is_experimental_machine_learning_neural_network_enabled_;
    static bool is_experimental_policies_enabled_;
    static bool is_expose_coarsened_render_time_enabled_;
    static bool is_expose_render_time_non_tao_delayed_image_enabled_;
    static bool is_extended_text_metrics_enabled_;
    static bool is_eye_dropper_api_enabled_;
    static bool is_face_detector_enabled_;
    static bool is_fast_non_composited_scroll_hit_test_enabled_;
    static bool is_fast_path_single_selector_exact_match_enabled_;
    static bool is_fast_position_iterator_enabled_;
    static bool is_fed_cm_enabled_;
    static bool is_fed_cm_authz_enabled_;
    static bool is_fed_cm_auto_selected_flag_enabled_;
    static bool is_fed_cm_button_mode_enabled_;
    static bool is_fed_cm_disconnect_enabled_;
    static bool is_fed_cm_domain_hint_enabled_;
    static bool is_fed_cm_error_enabled_;
    static bool is_fed_cm_id_p_registration_enabled_;
    static bool is_fed_cm_idp_signin_status_enabled_;
    static bool is_fed_cm_multiple_identity_providers_enabled_;
    static bool is_fed_cm_selective_disclosure_enabled_;
    static bool is_fed_cm_with_storage_access_api_enabled_;
    static bool is_fenced_frames_enabled_;
    static bool is_fenced_frames_api_changes_enabled_;
    static bool is_fenced_frames_default_mode_enabled_;
    static bool is_fenced_frames_local_unpartitioned_data_access_enabled_;
    static bool is_fetch_body_bytes_enabled_;
    static bool is_fetch_later_api_enabled_;
    static bool is_fetch_upload_streaming_enabled_;
    static bool is_file_handling_enabled_;
    static bool is_file_handling_icons_enabled_;
    static bool is_file_system_enabled_;
    static bool is_file_system_access_enabled_;
    static bool is_file_system_access_api_experimental_enabled_;
    static bool is_file_system_access_get_cloud_identifiers_enabled_;
    static bool is_file_system_access_local_enabled_;
    static bool is_file_system_access_locking_scheme_enabled_;
    static bool is_file_system_access_origin_private_enabled_;
    static bool is_file_system_observer_enabled_;
    static bool is_file_system_observer_unobserve_enabled_;
    static bool is_find_decomposed_in_short_text_enabled_;
    static bool is_find_ruby_in_page_enabled_;
    static bool is_find_text_in_readonly_text_input_enabled_;
    static bool is_find_text_skip_collapsed_text_enabled_;
    static bool is_fledge_enabled_;
    static bool is_fledge_auction_deal_support_enabled_;
    static bool is_fledge_bidding_and_auction_server_api_enabled_;
    static bool is_fledge_custom_max_auction_ad_components_enabled_;
    static bool is_fledge_deprecated_render_url_replacements_enabled_;
    static bool is_fledge_direct_from_seller_signals_header_ad_slot_enabled_;
    static bool is_fledge_multi_bid_enabled_;
    static bool is_fledge_real_time_reporting_enabled_;
    static bool is_fledge_reporting_timeout_enabled_;
    static bool is_fledge_seller_nonce_enabled_;
    static bool is_fledge_trusted_signals_k_vv_2_support_enabled_;
    static bool is_fluent_overlay_scrollbars_enabled_;
    static bool is_fluent_scrollbars_enabled_;
    static bool is_fluent_scrollbar_uses_nine_patch_track_enabled_;
    static bool is_focusgroup_enabled_;
    static bool is_font_access_enabled_;
    static bool is_fontations_font_backend_enabled_;
    static bool is_fontations_for_selected_formats_enabled_;
    static bool is_font_family_postscript_matching_ct_migration_enabled_;
    static bool is_font_family_style_matching_ct_migration_enabled_;
    static bool is_font_present_win_enabled_;
    static bool is_font_src_local_matching_enabled_;
    static bool is_font_system_fallback_noto_cjk_enabled_;
    static bool is_font_variant_emoji_enabled_;
    static bool is_font_variation_sequences_enabled_;
    static bool is_forced_colors_enabled_;
    static bool is_forced_colors_preserve_parent_color_enabled_;
    static bool is_force_eager_measure_memory_enabled_;
    static bool is_force_reduce_motion_enabled_;
    static bool is_force_taller_select_popup_enabled_;
    static bool is_form_control_restore_state_if_autocomplete_off_enabled_;
    static bool is_form_controls_vertical_writing_mode_direction_support_enabled_;
    static bool is_fractional_scroll_offsets_enabled_;
    static bool is_freeze_frames_on_visibility_enabled_;
    static bool is_gamepad_multitouch_enabled_;
    static bool is_get_all_screens_media_enabled_;
    static bool is_get_display_media_enabled_;
    static bool is_get_display_media_requires_user_activation_enabled_;
    static bool is_group_effect_enabled_;
    static bool is_handle_selection_change_on_deleting_empty_element_enabled_;
    static bool is_handwriting_recognition_enabled_;
    static bool is_hanging_whitespace_does_not_depend_on_alignment_enabled_;
    static bool is_has_ua_visual_transition_enabled_;
    static bool is_highlight_inheritance_enabled_;
    static bool is_highlight_pointer_events_enabled_;
    static bool is_highlights_from_point_enabled_;
    static bool is_hit_test_opaqueness_enabled_;
    static bool is_hit_test_opaqueness_omit_line_box_enabled_;
    static bool is_href_translate_enabled_;
    static bool is_html_anchor_attribute_enabled_;
    static bool is_html_dialog_light_dismiss_enabled_;
    static bool is_html_embed_element_not_force_layout_enabled_;
    static bool is_html_interest_target_attribute_enabled_;
    static bool is_html_invoke_actions_v_2_enabled_;
    static bool is_html_invoke_target_attribute_enabled_;
    static bool is_html_object_element_fallback_detach_content_frame_enabled_;
    static bool is_html_parser_yield_and_delay_often_for_testing_enabled_;
    static bool is_html_popover_action_hover_enabled_;
    static bool is_html_popover_hint_enabled_;
    static bool is_html_select_element_show_picker_enabled_;
    static bool is_implicit_root_scroller_enabled_;
    static bool is_import_attributes_disallow_unknown_keys_enabled_;
    static bool is_import_map_integrity_enabled_;
    static bool is_incoming_call_notifications_enabled_;
    static bool is_increment_local_surface_id_for_mainframe_same_doc_navigation_enabled_;
    static bool is_indexed_db_get_all_records_enabled_;
    static bool is_inert_element_non_editable_enabled_;
    static bool is_inert_element_non_searchable_enabled_;
    static bool is_infinite_cull_rect_enabled_;
    static bool is_inherit_user_modify_without_contenteditable_enabled_;
    static bool is_initial_letter_raise_by_specified_enabled_;
    static bool is_inline_block_in_same_line_enabled_;
    static bool is_inner_html_parser_fastpath_log_failure_enabled_;
    static bool is_input_closes_select_enabled_;
    static bool is_input_multiple_fields_ui_enabled_;
    static bool is_insert_blockquote_before_outer_block_enabled_;
    static bool is_insert_line_break_if_phrasing_content_enabled_;
    static bool is_inspector_ghost_rules_enabled_;
    static bool is_installed_app_enabled_;
    static bool is_install_on_device_speech_recognition_enabled_;
    static bool is_interest_groups_in_shared_storage_worklet_enabled_;
    static bool is_interoperable_private_attribution_enabled_;
    static bool is_intersection_observer_scroll_margin_enabled_;
    static bool is_inverted_colors_enabled_;
    static bool is_invisible_svg_animation_throttling_enabled_;
    static bool is_java_script_compile_hints_magic_always_runtime_enabled_;
    static bool is_java_script_compile_hints_magic_runtime_enabled_;
    static bool is_keep_css_target_after_reattach_enabled_;
    static bool is_keyboard_accessible_tooltip_enabled_;
    static bool is_keyboard_focusable_scrollers_enabled_;
    static bool is_keyboard_focusable_scrollers_opt_out_enabled_;
    static bool is_label_and_delegates_focus_new_handling_enabled_;
    static bool is_lang_attribute_aware_form_control_ui_enabled_;
    static bool is_language_detection_api_enabled_;
    static bool is_layout_flex_new_row_algorithm_v_3_enabled_;
    static bool is_layout_ignore_margins_for_sticky_enabled_;
    static bool is_layout_justify_self_for_blocks_enabled_;
    static bool is_layout_ng_shape_cache_enabled_;
    static bool is_layout_stretch_enabled_;
    static bool is_lazy_initialize_media_controls_enabled_;
    static bool is_lazy_load_scroll_margin_enabled_;
    static bool is_lazy_load_scroll_margin_iframe_enabled_;
    static bool is_lcp_animated_images_web_exposed_enabled_;
    static bool is_legacy_windows_d_write_font_fallback_enabled_;
    static bool is_limit_third_party_cookies_enabled_;
    static bool is_line_box_below_leading_floats_enabled_;
    static bool is_list_item_with_counter_set_not_set_explicit_value_enabled_;
    static bool is_locked_mode_enabled_;
    static bool is_long_animation_frame_timing_enabled_;
    static bool is_long_press_link_select_text_enabled_;
    static bool is_long_task_from_long_animation_frame_enabled_;
    static bool is_machine_learning_neural_network_enabled_;
    static bool is_managed_configuration_enabled_;
    static bool is_measure_memory_enabled_;
    static bool is_media_capabilities_dynamic_range_enabled_;
    static bool is_media_capabilities_encoding_info_enabled_;
    static bool is_media_capabilities_spatial_audio_enabled_;
    static bool is_media_capture_enabled_;
    static bool is_media_capture_background_blur_enabled_;
    static bool is_media_capture_camera_controls_enabled_;
    static bool is_media_capture_configuration_change_enabled_;
    static bool is_media_capture_voice_isolation_enabled_;
    static bool is_media_cast_overlay_button_enabled_;
    static bool is_media_controls_expand_gesture_enabled_;
    static bool is_media_controls_overlay_play_button_enabled_;
    static bool is_media_element_volume_greater_than_one_enabled_;
    static bool is_media_engagement_bypass_autoplay_policies_enabled_;
    static bool is_media_latency_hint_enabled_;
    static bool is_media_playback_while_not_visible_permission_policy_enabled_;
    static bool is_media_previews_opt_out_enabled_;
    static bool is_media_query_navigation_controls_enabled_;
    static bool is_media_recorder_use_media_video_encoder_enabled_;
    static bool is_media_session_enabled_;
    static bool is_media_session_chapter_information_enabled_;
    static bool is_media_session_enter_picture_in_picture_enabled_;
    static bool is_media_source_experimental_enabled_;
    static bool is_media_source_extensions_for_webcodecs_enabled_;
    static bool is_media_source_new_abort_and_duration_enabled_;
    static bool is_media_stream_track_transfer_enabled_;
    static bool is_media_stream_track_web_speech_enabled_;
    static bool is_message_port_close_event_enabled_;
    static bool is_meta_refresh_no_fractional_enabled_;
    static bool is_meter_appearance_none_fallback_style_enabled_;
    static bool is_meter_devolve_appearance_enabled_;
    static bool is_middle_click_autoscroll_enabled_;
    static bool is_minimimal_resource_request_prep_before_cache_lookup_enabled_;
    static bool is_mobile_layout_theme_enabled_;
    static bool is_modify_paragraph_cross_editingoundary_enabled_;
    static bool is_move_ending_selection_to_list_child_enabled_;
    static bool is_move_to_paragraph_start_or_end_skips_non_editable_enabled_;
    static bool is_multiple_import_maps_enabled_;
    static bool is_multi_select_deselect_when_only_option_enabled_;
    static bool is_multi_smooth_scroll_into_view_enabled_;
    static bool is_mutation_events_enabled_;
    static bool is_mutation_events_special_trial_message_enabled_;
    static bool is_navigate_event_commit_behavior_enabled_;
    static bool is_navigate_event_source_element_enabled_;
    static bool is_navigation_activation_enabled_;
    static bool is_navigation_id_enabled_;
    static bool is_navigator_content_utils_enabled_;
    static bool is_nested_view_transition_enabled_;
    static bool is_net_info_constant_type_enabled_;
    static bool is_net_info_downlink_max_enabled_;
    static bool is_new_get_focusable_area_behavior_enabled_;
    static bool is_no_idle_encoding_for_web_tests_enabled_;
    static bool is_no_increasing_end_offset_on_splitting_text_nodes_enabled_;
    static bool is_non_empty_blockquotes_on_outdenting_enabled_;
    static bool is_non_null_input_event_data_for_text_area_enabled_;
    static bool is_non_standard_appearance_value_slider_vertical_enabled_;
    static bool is_notification_constructor_enabled_;
    static bool is_notification_content_image_enabled_;
    static bool is_notifications_enabled_;
    static bool is_notification_triggers_enabled_;
    static bool is_observable_api_enabled_;
    static bool is_off_main_thread_css_paint_enabled_;
    static bool is_offscreen_canvas_commit_enabled_;
    static bool is_omit_blur_event_on_element_removal_enabled_;
    static bool is_on_device_change_enabled_;
    static bool is_on_device_web_speech_available_enabled_;
    static bool is_orientation_event_enabled_;
    static bool is_origin_isolation_header_enabled_;
    static bool is_origin_policy_enabled_;
    static bool is_origin_trials_sample_api_enabled_;
    static bool is_origin_trials_sample_api_browser_read_write_enabled_;
    static bool is_origin_trials_sample_api_dependent_enabled_;
    static bool is_origin_trials_sample_api_deprecation_enabled_;
    static bool is_origin_trials_sample_api_expiry_grace_period_enabled_;
    static bool is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_;
    static bool is_origin_trials_sample_api_implied_enabled_;
    static bool is_origin_trials_sample_api_invalid_os_enabled_;
    static bool is_origin_trials_sample_api_navigation_enabled_;
    static bool is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_;
    static bool is_origin_trials_sample_api_persistent_feature_enabled_;
    static bool is_origin_trials_sample_api_persistent_invalid_os_enabled_;
    static bool is_origin_trials_sample_api_persistent_third_party_deprecation_feature_enabled_;
    static bool is_origin_trials_sample_api_third_party_enabled_;
    static bool is_overscroll_customization_enabled_;
    static bool is_page_freeze_opt_in_enabled_;
    static bool is_page_freeze_opt_out_enabled_;
    static bool is_page_margin_boxes_enabled_;
    static bool is_page_popup_enabled_;
    static bool is_page_reveal_event_enabled_;
    static bool is_page_swap_event_enabled_;
    static bool is_paint_highlights_for_first_letter_enabled_;
    static bool is_paint_holding_for_iframes_enabled_;
    static bool is_paint_holding_for_local_iframes_enabled_;
    static bool is_paint_under_invalidation_checking_enabled_;
    static bool is_parakeet_enabled_;
    static bool is_partitioned_popins_enabled_;
    static bool is_partition_visited_link_database_with_self_links_enabled_;
    static bool is_password_reveal_enabled_;
    static bool is_payment_app_enabled_;
    static bool is_payment_instruments_enabled_;
    static bool is_payment_link_detection_enabled_;
    static bool is_payment_method_change_event_enabled_;
    static bool is_payment_request_enabled_;
    static bool is_percent_based_scrolling_enabled_;
    static bool is_performance_manager_instrumentation_enabled_;
    static bool is_performance_mark_feature_usage_enabled_;
    static bool is_performance_navigate_system_entropy_enabled_;
    static bool is_performance_navigation_timing_confidence_enabled_;
    static bool is_periodic_background_sync_enabled_;
    static bool is_per_method_can_make_payment_quota_enabled_;
    static bool is_permission_element_enabled_;
    static bool is_permissions_enabled_;
    static bool is_permissions_request_revoke_enabled_;
    static bool is_p_na_cl_enabled_;
    static bool is_pointer_event_device_id_enabled_;
    static bool is_pointer_event_targets_in_event_lists_enabled_;
    static bool is_popover_anchor_relationships_enabled_;
    static bool is_popover_dialog_new_focus_behavior_enabled_;
    static bool is_position_outside_tab_span_check_sibling_node_enabled_;
    static bool is_precise_memory_info_enabled_;
    static bool is_prefer_default_scrollbar_styles_enabled_;
    static bool is_prefer_non_composited_scrolling_enabled_;
    static bool is_prefers_reduced_data_enabled_;
    static bool is_prefixed_video_fullscreen_enabled_;
    static bool is_prerender_2_enabled_;
    static bool is_presentation_enabled_;
    static bool is_preserve_following_block_styles_during_block_merge_enabled_;
    static bool is_prevent_undo_if_not_editable_enabled_;
    static bool is_private_aggregation_api_filtering_ids_enabled_;
    static bool is_private_aggregation_auction_report_buyer_debug_mode_config_enabled_;
    static bool is_private_network_access_non_secure_contexts_allowed_enabled_;
    static bool is_private_network_access_null_ip_address_enabled_;
    static bool is_private_network_access_permission_prompt_enabled_;
    static bool is_private_state_tokens_enabled_;
    static bool is_private_state_tokens_always_allow_issuance_enabled_;
    static bool is_pseudo_elements_correct_in_get_computed_style_enabled_;
    static bool is_pseudo_elements_focusable_enabled_;
    static bool is_push_message_data_bytes_enabled_;
    static bool is_push_messaging_enabled_;
    static bool is_push_messaging_subscription_change_enabled_;
    static bool is_quick_intensive_wake_up_throttling_after_loading_enabled_;
    static bool is_raster_inducing_scroll_enabled_;
    static bool is_readable_stream_async_iterable_enabled_;
    static bool is_reduce_accept_language_enabled_;
    static bool is_reduce_cookie_ip_cs_enabled_;
    static bool is_reduce_user_agent_android_version_device_model_enabled_;
    static bool is_reduce_user_agent_minor_version_enabled_;
    static bool is_reduce_user_agent_platform_os_cpu_enabled_;
    static bool is_region_capture_enabled_;
    static bool is_rel_opener_bcg_dependency_hint_enabled_;
    static bool is_remote_playback_enabled_;
    static bool is_remote_playback_backend_enabled_;
    static bool is_remove_collapsed_placeholder_enabled_;
    static bool is_remove_dangling_markup_in_target_enabled_;
    static bool is_remove_data_url_in_svg_use_enabled_;
    static bool is_remove_node_having_children_if_fully_selected_enabled_;
    static bool is_remove_visible_selection_in_dom_selection_enabled_;
    static bool is_render_blocking_inline_module_script_enabled_;
    static bool is_render_blocking_status_enabled_;
    static bool is_render_priority_attribute_enabled_;
    static bool is_report_event_timing_at_visibility_change_enabled_;
    static bool is_report_visible_line_bounds_enabled_;
    static bool is_reset_input_type_to_none_before_character_input_enabled_;
    static bool is_resource_timing_content_type_enabled_;
    static bool is_resource_timing_final_response_headers_start_enabled_;
    static bool is_resource_timing_use_cors_for_body_sizes_enabled_;
    static bool is_restrict_gamepad_access_enabled_;
    static bool is_reuse_shape_results_by_fonts_enabled_;
    static bool is_rewind_floats_enabled_;
    static bool is_root_element_with_place_holder_after_deleting_selection_enabled_;
    static bool is_rtc_audio_jitter_buffer_max_packets_enabled_;
    static bool is_rtc_data_channel_priority_enabled_;
    static bool is_rtc_encoded_audio_frame_abs_capture_time_enabled_;
    static bool is_rtc_encoded_frame_set_metadata_enabled_;
    static bool is_rtc_encoded_video_frame_additional_metadata_enabled_;
    static bool is_rtc_jitter_buffer_target_enabled_;
    static bool is_rtc_legacy_callback_based_get_stats_enabled_;
    static bool is_rtc_rtp_encoding_parameters_codec_enabled_;
    static bool is_rtc_rtp_scale_resolution_down_to_enabled_;
    static bool is_rtc_rtp_script_transform_enabled_;
    static bool is_rtc_rtp_transport_enabled_;
    static bool is_rtc_stats_relative_packet_arrival_delay_enabled_;
    static bool is_rtc_svc_scalability_mode_enabled_;
    static bool is_ruby_short_heuristics_enabled_;
    static bool is_sanitizer_api_enabled_;
    static bool is_scheduler_yield_enabled_;
    static bool is_schedule_selection_change_on_backspace_enabled_;
    static bool is_scoped_custom_element_registry_enabled_;
    static bool is_scripted_speech_recognition_enabled_;
    static bool is_scripted_speech_synthesis_enabled_;
    static bool is_scrollbar_color_enabled_;
    static bool is_scrollbar_width_enabled_;
    static bool is_scroll_end_events_enabled_;
    static bool is_scroll_into_view_root_frame_viewport_bug_fix_enabled_;
    static bool is_scroll_timeline_enabled_;
    static bool is_scroll_timeline_current_time_enabled_;
    static bool is_scroll_top_left_interop_enabled_;
    static bool is_search_text_highlight_pseudo_enabled_;
    static bool is_secure_payment_confirmation_enabled_;
    static bool is_secure_payment_confirmation_debug_enabled_;
    static bool is_secure_payment_confirmation_network_and_issuer_icons_enabled_;
    static bool is_secure_payment_confirmation_opt_out_enabled_;
    static bool is_select_audio_output_enabled_;
    static bool is_selectedcontentelement_attribute_enabled_;
    static bool is_selection_across_shadow_dom_enabled_;
    static bool is_selection_is_collapsed_shadow_dom_support_enabled_;
    static bool is_selection_on_shadow_dom_with_delegates_focus_enabled_;
    static bool is_select_option_accessibility_target_size_enabled_;
    static bool is_select_parser_relaxation_enabled_;
    static bool is_select_popup_less_updates_enabled_;
    static bool is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
    static bool is_sensor_extra_classes_enabled_;
    static bool is_serial_enabled_;
    static bool is_serialize_view_transition_state_in_spa_enabled_;
    static bool is_serial_port_connected_enabled_;
    static bool is_service_worker_client_lifecycle_state_enabled_;
    static bool is_service_worker_static_router_enabled_;
    static bool is_service_worker_static_router_timing_info_enabled_;
    static bool is_set_sequential_focus_starting_point_enabled_;
    static bool is_shadow_root_reference_target_enabled_;
    static bool is_shape_outside_writing_mode_fix_enabled_;
    static bool is_shape_result_cached_previous_safe_to_break_offset_enabled_;
    static bool is_shared_array_buffer_enabled_;
    static bool is_shared_array_buffer_on_desktop_enabled_;
    static bool is_shared_array_buffer_unrestricted_access_allowed_enabled_;
    static bool is_shared_autofill_enabled_;
    static bool is_shared_storage_api_enabled_;
    static bool is_shared_storage_api_m_118_enabled_;
    static bool is_shared_storage_api_m_125_enabled_;
    static bool is_shared_storage_web_locks_enabled_;
    static bool is_shared_worker_enabled_;
    static bool is_sideways_writing_modes_enabled_;
    static bool is_signature_based_integrity_enabled_;
    static bool is_site_initiated_mirroring_enabled_;
    static bool is_skip_ad_enabled_;
    static bool is_skip_preload_scanning_enabled_;
    static bool is_skip_temporary_document_fragment_enabled_;
    static bool is_skip_touch_event_filter_enabled_;
    static bool is_smart_card_enabled_;
    static bool is_smart_zoom_enabled_;
    static bool is_smil_auto_suspend_on_lag_enabled_;
    static bool is_soft_navigation_detection_enabled_;
    static bool is_soft_navigation_heuristics_enabled_;
    static bool is_soft_navigation_heuristics_expose_fp_and_fcp_enabled_;
    static bool is_speaker_selection_enabled_;
    static bool is_speculation_rules_pointer_down_heuristics_enabled_;
    static bool is_speculation_rules_pointer_hover_heuristics_enabled_;
    static bool is_speculation_rules_prefetch_future_enabled_;
    static bool is_speculation_rules_prefetch_with_subresources_enabled_;
    static bool is_srcset_max_density_enabled_;
    static bool is_stable_blink_features_enabled_;
    static bool is_standardized_browser_zoom_enabled_;
    static bool is_standardized_browser_zoom_opt_out_enabled_;
    static bool is_static_animation_optimization_enabled_;
    static bool is_storage_access_header_enabled_;
    static bool is_storage_buckets_enabled_;
    static bool is_storage_buckets_durability_enabled_;
    static bool is_storage_buckets_locks_enabled_;
    static bool is_stricter_cell_width_content_size_quirk_enabled_;
    static bool is_strict_mime_types_for_workers_enabled_;
    static bool is_stylus_handwriting_enabled_;
    static bool is_svg_context_paint_enabled_;
    static bool is_svg_cross_origin_attribute_enabled_;
    static bool is_svg_eager_pres_attr_style_update_enabled_;
    static bool is_svg_external_resources_enabled_;
    static bool is_svg_filter_user_space_viewport_for_non_svg_enabled_;
    static bool is_svg_gradient_color_interpolation_linear_rgb_support_enabled_;
    static bool is_svg_inline_root_pixel_snapping_scale_adjustment_enabled_;
    static bool is_svg_no_pixel_snapping_scale_adjustment_enabled_;
    static bool is_svg_transform_optimization_enabled_;
    static bool is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
    static bool is_system_fallback_emoji_vs_support_enabled_;
    static bool is_system_wake_lock_enabled_;
    static bool is_test_blink_feature_default_enabled_;
    static bool is_test_feature_enabled_;
    static bool is_test_feature_dependent_enabled_;
    static bool is_test_feature_implied_enabled_;
    static bool is_test_feature_stable_enabled_;
    static bool is_text_detector_enabled_;
    static bool is_text_diff_split_fix_enabled_;
    static bool is_text_fragment_api_enabled_;
    static bool is_text_fragment_identifiers_enabled_;
    static bool is_text_fragment_tap_opens_context_menu_enabled_;
    static bool is_text_input_not_always_dir_auto_enabled_;
    static bool is_text_metrics_baselines_enabled_;
    static bool is_text_segment_boundary_for_element_with_float_style_enabled_;
    static bool is_text_size_adjust_improvements_enabled_;
    static bool is_text_transform_and_security_fix_enabled_;
    static bool is_timeline_scope_enabled_;
    static bool is_timer_throttling_for_background_tabs_enabled_;
    static bool is_timestamp_based_cls_tracking_enabled_;
    static bool is_time_zone_change_event_enabled_;
    static bool is_topics_api_enabled_;
    static bool is_topics_document_api_enabled_;
    static bool is_top_layer_inactive_document_exceptions_enabled_;
    static bool is_top_level_tpcd_enabled_;
    static bool is_touch_drag_and_context_menu_enabled_;
    static bool is_touch_drag_on_short_press_enabled_;
    static bool is_touch_event_feature_detection_enabled_;
    static bool is_touch_text_editing_redesign_enabled_;
    static bool is_tpcd_enabled_;
    static bool is_transferable_rtc_data_channel_enabled_;
    static bool is_translate_service_enabled_;
    static bool is_translation_api_enabled_;
    static bool is_translation_api_entry_point_enabled_;
    static bool is_trusted_type_before_policy_creation_event_enabled_;
    static bool is_trusted_types_from_literal_enabled_;
    static bool is_trusted_types_use_code_like_enabled_;
    static bool is_unclosed_form_control_is_invalid_enabled_;
    static bool is_unexposed_task_ids_enabled_;
    static bool is_unowned_animations_skip_css_events_enabled_;
    static bool is_unrestricted_measure_user_agent_specific_memory_enabled_;
    static bool is_unrestricted_shared_array_buffer_enabled_;
    static bool is_unrestricted_usb_enabled_;
    static bool is_url_pattern_compare_component_enabled_;
    static bool is_url_search_params_has_and_delete_multiple_args_enabled_;
    static bool is_use_begin_frame_presentation_feedback_enabled_;
    static bool is_use_low_quality_interpolation_enabled_;
    static bool is_user_activation_same_origin_visibility_enabled_;
    static bool is_use_selection_focus_node_for_caret_navigation_enabled_;
    static bool is_use_undo_step_element_dispatch_before_input_enabled_;
    static bool is_v8_idle_tasks_enabled_;
    static bool is_video_auto_fullscreen_enabled_;
    static bool is_video_frame_metadata_background_blur_enabled_;
    static bool is_video_fullscreen_orientation_lock_enabled_;
    static bool is_video_rotate_to_fullscreen_enabled_;
    static bool is_video_track_generator_enabled_;
    static bool is_video_track_generator_in_window_enabled_;
    static bool is_video_track_generator_in_worker_enabled_;
    static bool is_viewport_changes_update_text_autosizing_enabled_;
    static bool is_viewport_height_client_hint_header_enabled_;
    static bool is_viewport_segments_enabled_;
    static bool is_view_transition_disable_snap_browser_controls_on_hidden_enabled_;
    static bool is_view_transition_layered_capture_enabled_;
    static bool is_view_transition_long_callback_timeout_for_testing_enabled_;
    static bool is_view_transition_on_navigation_enabled_;
    static bool is_view_transition_on_navigation_for_iframes_enabled_;
    static bool is_view_transition_overflow_rect_from_surface_enabled_;
    static bool is_view_transition_tree_scoped_names_enabled_;
    static bool is_view_transition_types_enabled_;
    static bool is_visibility_collapse_column_enabled_;
    static bool is_visual_viewport_on_scroll_end_enabled_;
    static bool is_wake_lock_enabled_;
    static bool is_warn_on_content_visibility_render_access_enabled_;
    static bool is_web_animations_svg_enabled_;
    static bool is_web_app_installation_enabled_;
    static bool is_web_app_launch_queue_enabled_;
    static bool is_web_app_scope_extensions_enabled_;
    static bool is_web_app_tab_strip_enabled_;
    static bool is_web_app_tab_strip_customizations_enabled_;
    static bool is_web_app_translations_enabled_;
    static bool is_web_app_url_handling_enabled_;
    static bool is_web_assembly_js_promise_integration_enabled_;
    static bool is_web_assembly_js_string_builtins_enabled_;
    static bool is_web_audio_bypass_output_buffering_enabled_;
    static bool is_web_audio_bypass_output_buffering_opt_out_enabled_;
    static bool is_web_auth_enabled_;
    static bool is_web_auth_authenticator_attachment_enabled_;
    static bool is_web_authentication_ambient_enabled_;
    static bool is_web_authentication_attestation_formats_enabled_;
    static bool is_web_authentication_client_capabilities_enabled_;
    static bool is_web_authentication_js_on_serialization_enabled_;
    static bool is_web_authentication_large_blob_extension_enabled_;
    static bool is_web_authentication_prf_enabled_;
    static bool is_web_authentication_remote_desktop_support_enabled_;
    static bool is_web_authentication_supplemental_pub_keys_enabled_;
    static bool is_web_bluetooth_enabled_;
    static bool is_web_bluetooth_get_devices_enabled_;
    static bool is_web_bluetooth_scanning_enabled_;
    static bool is_web_bluetooth_watch_advertisements_enabled_;
    static bool is_webcodecs_copy_to_rgb_enabled_;
    static bool is_webcodecs_hbd_formats_enabled_;
    static bool is_webcodecs_orientation_enabled_;
    static bool is_webcodecs_video_encoder_buffers_enabled_;
    static bool is_web_crypto_curve_25519_enabled_;
    static bool is_web_font_resize_lcp_enabled_;
    static bool is_webgl_developer_extensions_enabled_;
    static bool is_webgl_draft_extensions_enabled_;
    static bool is_webgl_drawing_buffer_storage_enabled_;
    static bool is_webgl_image_chromium_enabled_;
    static bool is_webgpu_canvas_context_get_configuration_enabled_;
    static bool is_webgpu_developer_features_enabled_;
    static bool is_webgpu_device_adapter_info_enabled_;
    static bool is_webgpu_experimental_features_enabled_;
    static bool is_webgpu_hdr_enabled_;
    static bool is_webgpu_subgroups_features_enabled_;
    static bool is_webgpu_texture_view_usage_enabled_;
    static bool is_web_hid_enabled_;
    static bool is_web_hid_on_dedicated_workers_enabled_;
    static bool is_web_hid_on_service_workers_enabled_;
    static bool is_web_identity_digital_credentials_enabled_;
    static bool is_web_idl_big_int_uses_to_big_int_enabled_;
    static bool is_web_nfc_enabled_;
    static bool is_web_otp_enabled_;
    static bool is_web_otp_assertion_feature_policy_enabled_;
    static bool is_web_preferences_enabled_;
    static bool is_web_printing_enabled_;
    static bool is_web_share_enabled_;
    static bool is_websocket_stream_enabled_;
    static bool is_web_transport_custom_certificates_enabled_;
    static bool is_web_transport_stats_enabled_;
    static bool is_web_usb_enabled_;
    static bool is_web_usb_on_dedicated_workers_enabled_;
    static bool is_web_usb_on_service_workers_enabled_;
    static bool is_web_view_xr_equested_with_deprecation_enabled_;
    static bool is_web_vtt_regions_enabled_;
    static bool is_web_xr_enabled_;
    static bool is_web_xr_enabled_features_enabled_;
    static bool is_web_xr_frame_rate_enabled_;
    static bool is_web_xr_front_facing_enabled_;
    static bool is_web_xr_gpu_binding_enabled_;
    static bool is_web_xr_hand_input_enabled_;
    static bool is_web_xr_hit_test_entity_types_enabled_;
    static bool is_web_xr_image_tracking_enabled_;
    static bool is_web_xr_layers_enabled_;
    static bool is_web_xr_layers_common_enabled_;
    static bool is_web_xr_plane_detection_enabled_;
    static bool is_web_xr_pose_motion_data_enabled_;
    static bool is_web_xr_spec_parity_enabled_;
    static bool is_window_default_status_enabled_;
    static bool is_xml_parser_merge_adjacent_c_data_sections_enabled_;
    static bool is_zero_copy_tab_capture_enabled_;

    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_mojo_js_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_mojo_js_test_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_protected_origin_trials_sample_api_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_protected_origin_trials_sample_api_dependent_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_protected_origin_trials_sample_api_implied_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_test_feature_protected_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_test_feature_protected_dependent_enabled_;
    static DECLARE_PROTECTED_DATA base::ProtectedMemory<bool> is_test_feature_protected_implied_enabled_;
};

class PLATFORM_EXPORT RuntimeEnabledFeatures : public RuntimeEnabledFeaturesBase {
    STATIC_ONLY(RuntimeEnabledFeatures);

    // Only the following friends are allowed to use the setters defined in the
    // protected section of RuntimeEnabledFeaturesBase. Normally, unit tests
    // should use the ScopedFeatureNameForTest classes defined in
    // platform/testing/runtime_enabled_features_test_helpers.h.
    friend class DevToolsEmulator;
    friend class InternalRuntimeFlags;
    friend class V8ContextSnapshotImpl;
    friend class WebRuntimeFeaturesBase;
    friend class WebRuntimeFeatures;
    friend class WebView;
    friend class RuntimeEnabledFeaturesTestTraits;
    friend class RuntimeProtectedEnabledFeaturesTestTraits;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
