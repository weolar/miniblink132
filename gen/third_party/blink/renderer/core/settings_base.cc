// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/settings_base.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/frame/settings.json5

#include "third_party/blink/renderer/core/settings_base.h"

#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
#include "third_party/blink/renderer/core/frame/settings_string_converter.h"

namespace blink {

SettingsBase::SettingsBase()
    : delegate_(nullptr)
    , lcd_text_preference_(LCDTextPreference::kStronglyPreferred)
    , network_quiet_timeout_(0.5)
    , accelerated_2d_canvas_msaa_sample_count_(0)
    , accessibility_font_scale_factor_(1.0)
    , accessibility_font_weight_adjustment_(0)
    , accessibility_text_size_contrast_factor_(0)
    , autoplay_policy_(AutoplayPolicy::Type::kNoUserGestureRequired)
    , available_hover_types_(ui::HOVER_TYPE_NONE)
    , available_pointer_types_(ui::POINTER_TYPE_NONE)
    , default_fixed_font_size_(0)
    , default_font_size_(0)
    , device_scale_adjustment_(1.0)
    , display_mode_override_(blink::mojom::DisplayMode::kUndefined)
#if BUILDFLAG(IS_ANDROID)
    , editing_behavior_type_(mojom::blink::EditingBehavior::kEditingAndroidBehavior)
#elif BUILDFLAG(IS_CHROMEOS_ASH)
    , editing_behavior_type_(mojom::blink::EditingBehavior::kEditingChromeOSBehavior)
#elif BUILDFLAG(IS_CHROMEOS_LACROS)
    , editing_behavior_type_(mojom::blink::EditingBehavior::kEditingChromeOSBehavior)
#elif BUILDFLAG(IS_MAC)
    , editing_behavior_type_(mojom::blink::EditingBehavior::kEditingMacBehavior)
#elif BUILDFLAG(IS_WIN)
    , editing_behavior_type_(mojom::blink::EditingBehavior::kEditingWindowsBehavior)
#else
    , editing_behavior_type_(mojom::blink::EditingBehavior::kEditingUnixBehavior)
#endif
    , image_animation_policy_(mojom::blink::ImageAnimationPolicy::kImageAnimationPolicyAllowed)
    , lazy_loading_frame_margin_px_2_g_(6000)
    , lazy_loading_frame_margin_px_3_g_(3500)
    , lazy_loading_frame_margin_px_4_g_(2500)
    , lazy_loading_frame_margin_px_offline_(8000)
    , lazy_loading_frame_margin_px_slow_2_g_(8000)
    , lazy_loading_frame_margin_px_unknown_(4000)
    , lazy_loading_image_margin_px_2_g_(6000)
    , lazy_loading_image_margin_px_3_g_(2500)
    , lazy_loading_image_margin_px_4_g_(1250)
    , lazy_loading_image_margin_px_offline_(8000)
    , lazy_loading_image_margin_px_slow_2_g_(8000)
    , lazy_loading_image_margin_px_unknown_(3000)
    , low_priority_iframes_threshold_(WebEffectiveConnectionType::kTypeUnknown)
    , max_touch_points_(0)
    , media_type_override_("")
    , minimum_font_size_(0)
    , minimum_logical_font_size_(0)
    , navigation_controls_(NavigationControls::kNone)
    , output_device_update_ability_type_(mojom::blink::OutputDeviceUpdateAbilityType::kFastType)
    , parser_scripting_flag_policy_(ParserScriptingFlagPolicy::kOnlyIfScriptIsEnabled)
    , password_echo_duration_in_seconds_(1)
    , preferred_color_scheme_(mojom::blink::PreferredColorScheme::kLight)
    , preferred_contrast_(mojom::blink::PreferredContrast::kNoPreference)
    , preferred_root_scrollbar_color_scheme_(mojom::blink::PreferredColorScheme::kLight)
    , primary_hover_type_(mojom::blink::HoverType::kHoverNone)
    , primary_pointer_type_(mojom::blink::PointerType::kPointerNone)
    , printing_maximum_shrink_factor_(1.5)
    , selection_strategy_(SelectionStrategy::kCharacter)
    , text_track_kind_user_preference_(TextTrackKindUserPreference::kDefault)
    , text_track_margin_percentage_(0)
    , v8_cache_options_(mojom::blink::V8CacheOptions::kDefault)
    , validation_message_timer_magnification_(50)
    , viewport_style_(mojom::blink::ViewportStyle::kDefault)
    , window_show_state_(ui::mojom::blink::WindowShowState::kDefault)
    , dom_paste_allowed_(false)
    , dont_send_key_events_to_javascript_(false)
    , highlight_ads_(false)
    , web_xr_immersive_ar_allowed_(true)
    , accelerated_compositing_enabled_(false)
    , accessibility_always_show_focus_(false)
    , accessibility_include_svg_g_element_(false)
    , accessibility_password_values_enabled_(false)
    , allow_custom_scrollbar_in_main_frame_(true)
    , allow_file_access_from_file_urls_(true)
    , allow_geolocation_on_insecure_origins_(false)
    , allow_non_empty_navigator_plugins_(false)
    , allow_running_of_insecure_content_(true)
    , allow_scripts_to_close_windows_(false)
    , allow_universal_access_from_file_urls_(true)
    , always_show_context_menu_on_touch_(true)
    , antialiased_2d_canvas_enabled_(true)
    , antialiased_clips_2d_canvas_enabled_(true)
    , aria_modal_prunes_ax_tree_(false)
    , barrel_button_for_drag_enabled_(false)
    , bypass_csp_(false)
    , caret_browsing_enabled_(false)
    , cookie_enabled_(true)
    , disable_reading_from_canvas_(false)
    , disallow_fetch_for_doc_written_scripts_in_main_frame_(false)
    , disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g_(false)
    , disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections_(true)
    , dns_prefetching_enabled_(false)
    , do_html_preload_scanning_(true)
    , do_not_update_selection_on_mutating_selection_range_(false)
    , downloadable_binary_fonts_enabled_(true)
    , dynamic_safe_area_insets_enabled_(false)
    , embedded_media_experience_enabled_(false)
    , force_android_overlay_scrollbar_(false)
    , force_dark_mode_enabled_(false)
    , force_main_world_initialization_(false)
    , force_touch_event_feature_detection_for_inspector_(false)
    , force_zero_layout_height_(false)
    , fullscreen_supported_(true)
    , hide_download_ui_(false)
    , hide_scrollbars_(false)
    , hyperlink_auditing_enabled_(false)
    , ignore_main_frame_overflow_hidden_quirk_(false)
    , images_enabled_(true)
    , immersive_mode_enabled_(false)
    , in_forced_colors_(false)
    , inverted_colors_(false)
    , is_forced_colors_disabled_(false)
    , java_script_can_access_clipboard_(false)
    , lazy_load_enabled_(true)
    , load_with_overview_mode_(true)
    , loads_images_automatically_(false)
    , local_storage_enabled_(false)
    , log_dns_prefetch_and_preconnect_(false)
    , log_preload_(false)
    , main_frame_clips_content_(true)
    , main_frame_resizes_are_orientation_changes_(false)
    , media_controls_enabled_(true)
    , mock_gesture_tap_highlights_enabled_(false)
    , modal_context_menu_(true)
    , multi_target_tap_notification_enabled_(true)
    , navigate_on_drag_drop_(true)
    , password_echo_enabled_(false)
    , picture_in_picture_enabled_(true)
    , place_rtl_scrollbars_on_left_side_in_main_frame_(false)
    , plugins_enabled_(false)
    , prefer_hidden_volume_controls_(false)
    , prefers_default_scrollbar_styles_(false)
    , prefers_reduced_motion_(false)
    , prefers_reduced_transparency_(false)
    , presentation_receiver_(false)
    , presentation_requires_user_gesture_(true)
    , report_screen_size_in_physical_pixels_quirk_(false)
    , require_transient_activation_and_authorization_for_sub_apps_api_(true)
    , require_transient_activation_for_get_display_media_(true)
    , require_transient_activation_for_show_file_or_directory_picker_(true)
    , resizable_(true)
    , rubber_banding_on_compositor_thread_(false)
    , script_enabled_(false)
    , scroll_animator_enabled_(true)
#if BUILDFLAG(IS_WIN)
    , select_trailing_whitespace_enabled_(true)
#else
    , select_trailing_whitespace_enabled_(false)
#endif
    , selection_clipboard_buffer_available_(false)
    , selection_includes_alt_image_text_(false)
    , should_clear_document_background_(true)
    , should_print_backgrounds_(false)
    , should_protect_against_ipc_flooding_(true)
    , should_reuse_global_for_unowned_main_frame_(false)
    , show_context_menu_on_mouse_up_(false)
    , shrinks_viewport_content_to_fit_(false)
    , smart_insert_delete_enabled_(false)
    , smooth_scroll_for_find_enabled_(false)
    , spatial_navigation_enabled_(false)
    , spell_check_enabled_by_default_(true)
    , strict_mixed_content_checking_(false)
    , strict_mixed_content_checking_for_plugin_(false)
    , strict_powerful_feature_restrictions_(false)
    , strictly_block_blockable_mixed_content_(false)
    , supports_multiple_windows_(true)
    , sync_xhr_in_documents_enabled_(true)
    , target_blank_implies_no_opener_enabled_will_be_removed_(true)
    , text_areas_are_resizable_(false)
    , text_autosizing_enabled_(false)
    , touch_drag_drop_enabled_(false)
    , touch_drag_end_context_menu_(false)
    , touch_editing_enabled_(false)
    , use_ax_menu_list_(true)
    , use_wide_viewport_(true)
    , viewport_enabled_(false)
    , viewport_meta_enabled_(false)
    , viewport_meta_merge_content_quirk_(false)
    , viewport_meta_zero_values_quirk_(false)
    , web_gl_1_enabled_(true)
    , webgl2_enabled_(true)
    , web_gl_errors_to_console_enabled_(true)
    , web_security_enabled_(true)
    , wide_viewport_quirk_enabled_(false)
{
}

void SettingsBase::SetDOMPasteAllowed(bool dom_paste_allowed)
{
    if (dom_paste_allowed_ == dom_paste_allowed)
        return;
    dom_paste_allowed_ = dom_paste_allowed;
}

void SettingsBase::SetDontSendKeyEventsToJavascript(bool dont_send_key_events_to_javascript)
{
    if (dont_send_key_events_to_javascript_ == dont_send_key_events_to_javascript)
        return;
    dont_send_key_events_to_javascript_ = dont_send_key_events_to_javascript;
}

void SettingsBase::SetHighlightAds(bool highlight_ads)
{
    if (highlight_ads_ == highlight_ads)
        return;
    highlight_ads_ = highlight_ads;
    Invalidate(SettingsDelegate::ChangeType::kHighlightAds);
}

void SettingsBase::SetLCDTextPreference(LCDTextPreference lcd_text_preference)
{
    if (lcd_text_preference_ == lcd_text_preference)
        return;
    lcd_text_preference_ = lcd_text_preference;
    Invalidate(SettingsDelegate::ChangeType::kAcceleratedCompositing);
}

void SettingsBase::SetNetworkQuietTimeout(double network_quiet_timeout)
{
    if (network_quiet_timeout_ == network_quiet_timeout)
        return;
    network_quiet_timeout_ = network_quiet_timeout;
}

void SettingsBase::SetWebXRImmersiveArAllowed(bool web_xr_immersive_ar_allowed)
{
    if (web_xr_immersive_ar_allowed_ == web_xr_immersive_ar_allowed)
        return;
    web_xr_immersive_ar_allowed_ = web_xr_immersive_ar_allowed;
}

void SettingsBase::SetAccelerated2dCanvasMSAASampleCount(int accelerated_2d_canvas_msaa_sample_count)
{
    if (accelerated_2d_canvas_msaa_sample_count_ == accelerated_2d_canvas_msaa_sample_count)
        return;
    accelerated_2d_canvas_msaa_sample_count_ = accelerated_2d_canvas_msaa_sample_count;
}

void SettingsBase::SetAcceleratedCompositingEnabled(bool accelerated_compositing_enabled)
{
    if (accelerated_compositing_enabled_ == accelerated_compositing_enabled)
        return;
    accelerated_compositing_enabled_ = accelerated_compositing_enabled;
    Invalidate(SettingsDelegate::ChangeType::kAcceleratedCompositing);
}

void SettingsBase::SetAccessibilityAlwaysShowFocus(bool accessibility_always_show_focus)
{
    if (accessibility_always_show_focus_ == accessibility_always_show_focus)
        return;
    accessibility_always_show_focus_ = accessibility_always_show_focus;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetAccessibilityFontScaleFactor(double accessibility_font_scale_factor)
{
    if (accessibility_font_scale_factor_ == accessibility_font_scale_factor)
        return;
    accessibility_font_scale_factor_ = accessibility_font_scale_factor;
    Invalidate(SettingsDelegate::ChangeType::kTextAutosizing);
}

void SettingsBase::SetAccessibilityFontWeightAdjustment(int accessibility_font_weight_adjustment)
{
    if (accessibility_font_weight_adjustment_ == accessibility_font_weight_adjustment)
        return;
    accessibility_font_weight_adjustment_ = accessibility_font_weight_adjustment;
}

void SettingsBase::SetAccessibilityIncludeSvgGElement(bool accessibility_include_svg_g_element)
{
    if (accessibility_include_svg_g_element_ == accessibility_include_svg_g_element)
        return;
    accessibility_include_svg_g_element_ = accessibility_include_svg_g_element;
}

void SettingsBase::SetAccessibilityPasswordValuesEnabled(bool accessibility_password_values_enabled)
{
    if (accessibility_password_values_enabled_ == accessibility_password_values_enabled)
        return;
    accessibility_password_values_enabled_ = accessibility_password_values_enabled;
}

void SettingsBase::SetAccessibilityTextSizeContrastFactor(int accessibility_text_size_contrast_factor)
{
    if (accessibility_text_size_contrast_factor_ == accessibility_text_size_contrast_factor)
        return;
    accessibility_text_size_contrast_factor_ = accessibility_text_size_contrast_factor;
}

void SettingsBase::SetAllowCustomScrollbarInMainFrame(bool allow_custom_scrollbar_in_main_frame)
{
    if (allow_custom_scrollbar_in_main_frame_ == allow_custom_scrollbar_in_main_frame)
        return;
    allow_custom_scrollbar_in_main_frame_ = allow_custom_scrollbar_in_main_frame;
}

void SettingsBase::SetAllowFileAccessFromFileURLs(bool allow_file_access_from_file_urls)
{
    if (allow_file_access_from_file_urls_ == allow_file_access_from_file_urls)
        return;
    allow_file_access_from_file_urls_ = allow_file_access_from_file_urls;
}

void SettingsBase::SetAllowGeolocationOnInsecureOrigins(bool allow_geolocation_on_insecure_origins)
{
    if (allow_geolocation_on_insecure_origins_ == allow_geolocation_on_insecure_origins)
        return;
    allow_geolocation_on_insecure_origins_ = allow_geolocation_on_insecure_origins;
}

void SettingsBase::SetAllowNonEmptyNavigatorPlugins(bool allow_non_empty_navigator_plugins)
{
    if (allow_non_empty_navigator_plugins_ == allow_non_empty_navigator_plugins)
        return;
    allow_non_empty_navigator_plugins_ = allow_non_empty_navigator_plugins;
}

void SettingsBase::SetAllowRunningOfInsecureContent(bool allow_running_of_insecure_content)
{
    if (allow_running_of_insecure_content_ == allow_running_of_insecure_content)
        return;
    allow_running_of_insecure_content_ = allow_running_of_insecure_content;
}

void SettingsBase::SetAllowScriptsToCloseWindows(bool allow_scripts_to_close_windows)
{
    if (allow_scripts_to_close_windows_ == allow_scripts_to_close_windows)
        return;
    allow_scripts_to_close_windows_ = allow_scripts_to_close_windows;
}

void SettingsBase::SetAllowUniversalAccessFromFileURLs(bool allow_universal_access_from_file_urls)
{
    if (allow_universal_access_from_file_urls_ == allow_universal_access_from_file_urls)
        return;
    allow_universal_access_from_file_urls_ = allow_universal_access_from_file_urls;
    Invalidate(SettingsDelegate::ChangeType::kUniversalAccess);
}

void SettingsBase::SetAlwaysShowContextMenuOnTouch(bool always_show_context_menu_on_touch)
{
    if (always_show_context_menu_on_touch_ == always_show_context_menu_on_touch)
        return;
    always_show_context_menu_on_touch_ = always_show_context_menu_on_touch;
}

void SettingsBase::SetAntialiased2dCanvasEnabled(bool antialiased_2d_canvas_enabled)
{
    if (antialiased_2d_canvas_enabled_ == antialiased_2d_canvas_enabled)
        return;
    antialiased_2d_canvas_enabled_ = antialiased_2d_canvas_enabled;
}

void SettingsBase::SetAntialiasedClips2dCanvasEnabled(bool antialiased_clips_2d_canvas_enabled)
{
    if (antialiased_clips_2d_canvas_enabled_ == antialiased_clips_2d_canvas_enabled)
        return;
    antialiased_clips_2d_canvas_enabled_ = antialiased_clips_2d_canvas_enabled;
}

void SettingsBase::SetAriaModalPrunesAXTree(bool aria_modal_prunes_ax_tree)
{
    if (aria_modal_prunes_ax_tree_ == aria_modal_prunes_ax_tree)
        return;
    aria_modal_prunes_ax_tree_ = aria_modal_prunes_ax_tree;
}

void SettingsBase::SetAutoplayPolicy(AutoplayPolicy::Type autoplay_policy)
{
    if (autoplay_policy_ == autoplay_policy)
        return;
    autoplay_policy_ = autoplay_policy;
}

void SettingsBase::SetAvailableHoverTypes(int available_hover_types)
{
    if (available_hover_types_ == available_hover_types)
        return;
    available_hover_types_ = available_hover_types;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetAvailablePointerTypes(int available_pointer_types)
{
    if (available_pointer_types_ == available_pointer_types)
        return;
    available_pointer_types_ = available_pointer_types;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetBarrelButtonForDragEnabled(bool barrel_button_for_drag_enabled)
{
    if (barrel_button_for_drag_enabled_ == barrel_button_for_drag_enabled)
        return;
    barrel_button_for_drag_enabled_ = barrel_button_for_drag_enabled;
}

void SettingsBase::SetBypassCSP(bool bypass_csp)
{
    if (bypass_csp_ == bypass_csp)
        return;
    bypass_csp_ = bypass_csp;
}

void SettingsBase::SetCaretBrowsingEnabled(bool caret_browsing_enabled)
{
    if (caret_browsing_enabled_ == caret_browsing_enabled)
        return;
    caret_browsing_enabled_ = caret_browsing_enabled;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetCookieEnabled(bool cookie_enabled)
{
    if (cookie_enabled_ == cookie_enabled)
        return;
    cookie_enabled_ = cookie_enabled;
}

void SettingsBase::SetDefaultFixedFontSize(int default_fixed_font_size)
{
    if (default_fixed_font_size_ == default_fixed_font_size)
        return;
    default_fixed_font_size_ = default_fixed_font_size;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetDefaultFontSize(int default_font_size)
{
    if (default_font_size_ == default_font_size)
        return;
    default_font_size_ = default_font_size;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetDefaultTextEncodingName(const String& default_text_encoding_name)
{
    if (default_text_encoding_name_ == default_text_encoding_name)
        return;
    default_text_encoding_name_ = default_text_encoding_name;
}

void SettingsBase::SetDefaultVideoPosterURL(const String& default_video_poster_url)
{
    if (default_video_poster_url_ == default_video_poster_url)
        return;
    default_video_poster_url_ = default_video_poster_url;
}

void SettingsBase::SetDeviceScaleAdjustment(double device_scale_adjustment)
{
    if (device_scale_adjustment_ == device_scale_adjustment)
        return;
    device_scale_adjustment_ = device_scale_adjustment;
    Invalidate(SettingsDelegate::ChangeType::kTextAutosizing);
}

void SettingsBase::SetDisableReadingFromCanvas(bool disable_reading_from_canvas)
{
    if (disable_reading_from_canvas_ == disable_reading_from_canvas)
        return;
    disable_reading_from_canvas_ = disable_reading_from_canvas;
}

void SettingsBase::SetDisallowFetchForDocWrittenScriptsInMainFrame(bool disallow_fetch_for_doc_written_scripts_in_main_frame)
{
    if (disallow_fetch_for_doc_written_scripts_in_main_frame_ == disallow_fetch_for_doc_written_scripts_in_main_frame)
        return;
    disallow_fetch_for_doc_written_scripts_in_main_frame_ = disallow_fetch_for_doc_written_scripts_in_main_frame;
}

void SettingsBase::SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g)
{
    if (disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g_ == disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g)
        return;
    disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g_ = disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g;
}

void SettingsBase::SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(
    bool disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections)
{
    if (disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections_ == disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections)
        return;
    disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections_ = disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections;
}

void SettingsBase::SetDisplayModeOverride(blink::mojom::DisplayMode display_mode_override)
{
    if (display_mode_override_ == display_mode_override)
        return;
    display_mode_override_ = display_mode_override;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetDNSPrefetchingEnabled(bool dns_prefetching_enabled)
{
    if (dns_prefetching_enabled_ == dns_prefetching_enabled)
        return;
    dns_prefetching_enabled_ = dns_prefetching_enabled;
    Invalidate(SettingsDelegate::ChangeType::kDNSPrefetching);
}

void SettingsBase::SetDoHtmlPreloadScanning(bool do_html_preload_scanning)
{
    if (do_html_preload_scanning_ == do_html_preload_scanning)
        return;
    do_html_preload_scanning_ = do_html_preload_scanning;
}

void SettingsBase::SetDoNotUpdateSelectionOnMutatingSelectionRange(bool do_not_update_selection_on_mutating_selection_range)
{
    if (do_not_update_selection_on_mutating_selection_range_ == do_not_update_selection_on_mutating_selection_range)
        return;
    do_not_update_selection_on_mutating_selection_range_ = do_not_update_selection_on_mutating_selection_range;
}

void SettingsBase::SetDownloadableBinaryFontsEnabled(bool downloadable_binary_fonts_enabled)
{
    if (downloadable_binary_fonts_enabled_ == downloadable_binary_fonts_enabled)
        return;
    downloadable_binary_fonts_enabled_ = downloadable_binary_fonts_enabled;
}

void SettingsBase::SetDynamicSafeAreaInsetsEnabled(bool dynamic_safe_area_insets_enabled)
{
    if (dynamic_safe_area_insets_enabled_ == dynamic_safe_area_insets_enabled)
        return;
    dynamic_safe_area_insets_enabled_ = dynamic_safe_area_insets_enabled;
}

void SettingsBase::SetEditingBehaviorType(mojom::EditingBehavior editing_behavior_type)
{
    if (editing_behavior_type_ == editing_behavior_type)
        return;
    editing_behavior_type_ = editing_behavior_type;
}

void SettingsBase::SetEmbeddedMediaExperienceEnabled(bool embedded_media_experience_enabled)
{
    if (embedded_media_experience_enabled_ == embedded_media_experience_enabled)
        return;
    embedded_media_experience_enabled_ = embedded_media_experience_enabled;
}

void SettingsBase::SetForceAndroidOverlayScrollbar(bool force_android_overlay_scrollbar)
{
    if (force_android_overlay_scrollbar_ == force_android_overlay_scrollbar)
        return;
    force_android_overlay_scrollbar_ = force_android_overlay_scrollbar;
    Invalidate(SettingsDelegate::ChangeType::kScrollbarLayout);
}

void SettingsBase::SetForceDarkModeEnabled(bool force_dark_mode_enabled)
{
    if (force_dark_mode_enabled_ == force_dark_mode_enabled)
        return;
    force_dark_mode_enabled_ = force_dark_mode_enabled;
    Invalidate(SettingsDelegate::ChangeType::kColorScheme);
    Invalidate(SettingsDelegate::ChangeType::kStyle);
    Invalidate(SettingsDelegate::ChangeType::kPaint);
}

void SettingsBase::SetForceMainWorldInitialization(bool force_main_world_initialization)
{
    if (force_main_world_initialization_ == force_main_world_initialization)
        return;
    force_main_world_initialization_ = force_main_world_initialization;
    Invalidate(SettingsDelegate::ChangeType::kDOMWorlds);
}

void SettingsBase::SetForceTouchEventFeatureDetectionForInspector(bool force_touch_event_feature_detection_for_inspector)
{
    if (force_touch_event_feature_detection_for_inspector_ == force_touch_event_feature_detection_for_inspector)
        return;
    force_touch_event_feature_detection_for_inspector_ = force_touch_event_feature_detection_for_inspector;
}

void SettingsBase::SetForceZeroLayoutHeight(bool force_zero_layout_height)
{
    if (force_zero_layout_height_ == force_zero_layout_height)
        return;
    force_zero_layout_height_ = force_zero_layout_height;
    Invalidate(SettingsDelegate::ChangeType::kViewportDescription);
}

void SettingsBase::SetFullscreenSupported(bool fullscreen_supported)
{
    if (fullscreen_supported_ == fullscreen_supported)
        return;
    fullscreen_supported_ = fullscreen_supported;
}

void SettingsBase::SetHideDownloadUI(bool hide_download_ui)
{
    if (hide_download_ui_ == hide_download_ui)
        return;
    hide_download_ui_ = hide_download_ui;
}

void SettingsBase::SetHideScrollbars(bool hide_scrollbars)
{
    if (hide_scrollbars_ == hide_scrollbars)
        return;
    hide_scrollbars_ = hide_scrollbars;
    Invalidate(SettingsDelegate::ChangeType::kViewportPaintProperties);
}

void SettingsBase::SetHyperlinkAuditingEnabled(bool hyperlink_auditing_enabled)
{
    if (hyperlink_auditing_enabled_ == hyperlink_auditing_enabled)
        return;
    hyperlink_auditing_enabled_ = hyperlink_auditing_enabled;
}

void SettingsBase::SetIgnoreMainFrameOverflowHiddenQuirk(bool ignore_main_frame_overflow_hidden_quirk)
{
    if (ignore_main_frame_overflow_hidden_quirk_ == ignore_main_frame_overflow_hidden_quirk)
        return;
    ignore_main_frame_overflow_hidden_quirk_ = ignore_main_frame_overflow_hidden_quirk;
}

void SettingsBase::SetImageAnimationPolicy(mojom::blink::ImageAnimationPolicy image_animation_policy)
{
    if (image_animation_policy_ == image_animation_policy)
        return;
    image_animation_policy_ = image_animation_policy;
}

void SettingsBase::SetImagesEnabled(bool images_enabled)
{
    if (images_enabled_ == images_enabled)
        return;
    images_enabled_ = images_enabled;
    Invalidate(SettingsDelegate::ChangeType::kImageLoading);
}

void SettingsBase::SetImmersiveModeEnabled(bool immersive_mode_enabled)
{
    if (immersive_mode_enabled_ == immersive_mode_enabled)
        return;
    immersive_mode_enabled_ = immersive_mode_enabled;
}

void SettingsBase::SetInForcedColors(bool in_forced_colors)
{
    if (in_forced_colors_ == in_forced_colors)
        return;
    in_forced_colors_ = in_forced_colors;
}

void SettingsBase::SetInvertedColors(bool inverted_colors)
{
    if (inverted_colors_ == inverted_colors)
        return;
    inverted_colors_ = inverted_colors;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetIsForcedColorsDisabled(bool is_forced_colors_disabled)
{
    if (is_forced_colors_disabled_ == is_forced_colors_disabled)
        return;
    is_forced_colors_disabled_ = is_forced_colors_disabled;
    Invalidate(SettingsDelegate::ChangeType::kForcedColors);
}

void SettingsBase::SetJavaScriptCanAccessClipboard(bool java_script_can_access_clipboard)
{
    if (java_script_can_access_clipboard_ == java_script_can_access_clipboard)
        return;
    java_script_can_access_clipboard_ = java_script_can_access_clipboard;
}

void SettingsBase::SetLazyLoadEnabled(bool lazy_load_enabled)
{
    if (lazy_load_enabled_ == lazy_load_enabled)
        return;
    lazy_load_enabled_ = lazy_load_enabled;
}

void SettingsBase::SetLazyLoadingFrameMarginPx2G(int lazy_loading_frame_margin_px_2_g)
{
    if (lazy_loading_frame_margin_px_2_g_ == lazy_loading_frame_margin_px_2_g)
        return;
    lazy_loading_frame_margin_px_2_g_ = lazy_loading_frame_margin_px_2_g;
}

void SettingsBase::SetLazyLoadingFrameMarginPx3G(int lazy_loading_frame_margin_px_3_g)
{
    if (lazy_loading_frame_margin_px_3_g_ == lazy_loading_frame_margin_px_3_g)
        return;
    lazy_loading_frame_margin_px_3_g_ = lazy_loading_frame_margin_px_3_g;
}

void SettingsBase::SetLazyLoadingFrameMarginPx4G(int lazy_loading_frame_margin_px_4_g)
{
    if (lazy_loading_frame_margin_px_4_g_ == lazy_loading_frame_margin_px_4_g)
        return;
    lazy_loading_frame_margin_px_4_g_ = lazy_loading_frame_margin_px_4_g;
}

void SettingsBase::SetLazyLoadingFrameMarginPxOffline(int lazy_loading_frame_margin_px_offline)
{
    if (lazy_loading_frame_margin_px_offline_ == lazy_loading_frame_margin_px_offline)
        return;
    lazy_loading_frame_margin_px_offline_ = lazy_loading_frame_margin_px_offline;
}

void SettingsBase::SetLazyLoadingFrameMarginPxSlow2G(int lazy_loading_frame_margin_px_slow_2_g)
{
    if (lazy_loading_frame_margin_px_slow_2_g_ == lazy_loading_frame_margin_px_slow_2_g)
        return;
    lazy_loading_frame_margin_px_slow_2_g_ = lazy_loading_frame_margin_px_slow_2_g;
}

void SettingsBase::SetLazyLoadingFrameMarginPxUnknown(int lazy_loading_frame_margin_px_unknown)
{
    if (lazy_loading_frame_margin_px_unknown_ == lazy_loading_frame_margin_px_unknown)
        return;
    lazy_loading_frame_margin_px_unknown_ = lazy_loading_frame_margin_px_unknown;
}

void SettingsBase::SetLazyLoadingImageMarginPx2G(int lazy_loading_image_margin_px_2_g)
{
    if (lazy_loading_image_margin_px_2_g_ == lazy_loading_image_margin_px_2_g)
        return;
    lazy_loading_image_margin_px_2_g_ = lazy_loading_image_margin_px_2_g;
}

void SettingsBase::SetLazyLoadingImageMarginPx3G(int lazy_loading_image_margin_px_3_g)
{
    if (lazy_loading_image_margin_px_3_g_ == lazy_loading_image_margin_px_3_g)
        return;
    lazy_loading_image_margin_px_3_g_ = lazy_loading_image_margin_px_3_g;
}

void SettingsBase::SetLazyLoadingImageMarginPx4G(int lazy_loading_image_margin_px_4_g)
{
    if (lazy_loading_image_margin_px_4_g_ == lazy_loading_image_margin_px_4_g)
        return;
    lazy_loading_image_margin_px_4_g_ = lazy_loading_image_margin_px_4_g;
}

void SettingsBase::SetLazyLoadingImageMarginPxOffline(int lazy_loading_image_margin_px_offline)
{
    if (lazy_loading_image_margin_px_offline_ == lazy_loading_image_margin_px_offline)
        return;
    lazy_loading_image_margin_px_offline_ = lazy_loading_image_margin_px_offline;
}

void SettingsBase::SetLazyLoadingImageMarginPxSlow2G(int lazy_loading_image_margin_px_slow_2_g)
{
    if (lazy_loading_image_margin_px_slow_2_g_ == lazy_loading_image_margin_px_slow_2_g)
        return;
    lazy_loading_image_margin_px_slow_2_g_ = lazy_loading_image_margin_px_slow_2_g;
}

void SettingsBase::SetLazyLoadingImageMarginPxUnknown(int lazy_loading_image_margin_px_unknown)
{
    if (lazy_loading_image_margin_px_unknown_ == lazy_loading_image_margin_px_unknown)
        return;
    lazy_loading_image_margin_px_unknown_ = lazy_loading_image_margin_px_unknown;
}

void SettingsBase::SetLoadWithOverviewMode(bool load_with_overview_mode)
{
    if (load_with_overview_mode_ == load_with_overview_mode)
        return;
    load_with_overview_mode_ = load_with_overview_mode;
    Invalidate(SettingsDelegate::ChangeType::kViewportDescription);
}

void SettingsBase::SetLoadsImagesAutomatically(bool loads_images_automatically)
{
    if (loads_images_automatically_ == loads_images_automatically)
        return;
    loads_images_automatically_ = loads_images_automatically;
    Invalidate(SettingsDelegate::ChangeType::kImageLoading);
}

void SettingsBase::SetLocalStorageEnabled(bool local_storage_enabled)
{
    if (local_storage_enabled_ == local_storage_enabled)
        return;
    local_storage_enabled_ = local_storage_enabled;
}

void SettingsBase::SetLogDnsPrefetchAndPreconnect(bool log_dns_prefetch_and_preconnect)
{
    if (log_dns_prefetch_and_preconnect_ == log_dns_prefetch_and_preconnect)
        return;
    log_dns_prefetch_and_preconnect_ = log_dns_prefetch_and_preconnect;
}

void SettingsBase::SetLogPreload(bool log_preload)
{
    if (log_preload_ == log_preload)
        return;
    log_preload_ = log_preload;
}

void SettingsBase::SetLowPriorityIframesThreshold(WebEffectiveConnectionType low_priority_iframes_threshold)
{
    if (low_priority_iframes_threshold_ == low_priority_iframes_threshold)
        return;
    low_priority_iframes_threshold_ = low_priority_iframes_threshold;
}

void SettingsBase::SetMainFrameClipsContent(bool main_frame_clips_content)
{
    if (main_frame_clips_content_ == main_frame_clips_content)
        return;
    main_frame_clips_content_ = main_frame_clips_content;
    Invalidate(SettingsDelegate::ChangeType::kViewportPaintProperties);
}

void SettingsBase::SetMainFrameResizesAreOrientationChanges(bool main_frame_resizes_are_orientation_changes)
{
    if (main_frame_resizes_are_orientation_changes_ == main_frame_resizes_are_orientation_changes)
        return;
    main_frame_resizes_are_orientation_changes_ = main_frame_resizes_are_orientation_changes;
}

void SettingsBase::SetMaxTouchPoints(int max_touch_points)
{
    if (max_touch_points_ == max_touch_points)
        return;
    max_touch_points_ = max_touch_points;
}

void SettingsBase::SetMediaControlsEnabled(bool media_controls_enabled)
{
    if (media_controls_enabled_ == media_controls_enabled)
        return;
    media_controls_enabled_ = media_controls_enabled;
    Invalidate(SettingsDelegate::ChangeType::kMediaControls);
}

void SettingsBase::SetMediaTypeOverride(const String& media_type_override)
{
    if (media_type_override_ == media_type_override)
        return;
    media_type_override_ = media_type_override;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetMinimumFontSize(int minimum_font_size)
{
    if (minimum_font_size_ == minimum_font_size)
        return;
    minimum_font_size_ = minimum_font_size;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetMinimumLogicalFontSize(int minimum_logical_font_size)
{
    if (minimum_logical_font_size_ == minimum_logical_font_size)
        return;
    minimum_logical_font_size_ = minimum_logical_font_size;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetMockGestureTapHighlightsEnabled(bool mock_gesture_tap_highlights_enabled)
{
    if (mock_gesture_tap_highlights_enabled_ == mock_gesture_tap_highlights_enabled)
        return;
    mock_gesture_tap_highlights_enabled_ = mock_gesture_tap_highlights_enabled;
}

void SettingsBase::SetModalContextMenu(bool modal_context_menu)
{
    if (modal_context_menu_ == modal_context_menu)
        return;
    modal_context_menu_ = modal_context_menu;
}

void SettingsBase::SetMultiTargetTapNotificationEnabled(bool multi_target_tap_notification_enabled)
{
    if (multi_target_tap_notification_enabled_ == multi_target_tap_notification_enabled)
        return;
    multi_target_tap_notification_enabled_ = multi_target_tap_notification_enabled;
}

void SettingsBase::SetNavigateOnDragDrop(bool navigate_on_drag_drop)
{
    if (navigate_on_drag_drop_ == navigate_on_drag_drop)
        return;
    navigate_on_drag_drop_ = navigate_on_drag_drop;
}

void SettingsBase::SetNavigationControls(NavigationControls navigation_controls)
{
    if (navigation_controls_ == navigation_controls)
        return;
    navigation_controls_ = navigation_controls;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetNavigatorPlatformOverride(const String& navigator_platform_override)
{
    if (navigator_platform_override_ == navigator_platform_override)
        return;
    navigator_platform_override_ = navigator_platform_override;
}

void SettingsBase::SetOutputDeviceUpdateAbilityType(mojom::blink::OutputDeviceUpdateAbilityType output_device_update_ability_type)
{
    if (output_device_update_ability_type_ == output_device_update_ability_type)
        return;
    output_device_update_ability_type_ = output_device_update_ability_type;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetParserScriptingFlagPolicy(ParserScriptingFlagPolicy parser_scripting_flag_policy)
{
    if (parser_scripting_flag_policy_ == parser_scripting_flag_policy)
        return;
    parser_scripting_flag_policy_ = parser_scripting_flag_policy;
}

void SettingsBase::SetPasswordEchoDurationInSeconds(double password_echo_duration_in_seconds)
{
    if (password_echo_duration_in_seconds_ == password_echo_duration_in_seconds)
        return;
    password_echo_duration_in_seconds_ = password_echo_duration_in_seconds;
}

void SettingsBase::SetPasswordEchoEnabled(bool password_echo_enabled)
{
    if (password_echo_enabled_ == password_echo_enabled)
        return;
    password_echo_enabled_ = password_echo_enabled;
}

void SettingsBase::SetPictureInPictureEnabled(bool picture_in_picture_enabled)
{
    if (picture_in_picture_enabled_ == picture_in_picture_enabled)
        return;
    picture_in_picture_enabled_ = picture_in_picture_enabled;
}

void SettingsBase::SetPlaceRTLScrollbarsOnLeftSideInMainFrame(bool place_rtl_scrollbars_on_left_side_in_main_frame)
{
    if (place_rtl_scrollbars_on_left_side_in_main_frame_ == place_rtl_scrollbars_on_left_side_in_main_frame)
        return;
    place_rtl_scrollbars_on_left_side_in_main_frame_ = place_rtl_scrollbars_on_left_side_in_main_frame;
    Invalidate(SettingsDelegate::ChangeType::kScrollbarLayout);
}

void SettingsBase::SetPluginsEnabled(bool plugins_enabled)
{
    if (plugins_enabled_ == plugins_enabled)
        return;
    plugins_enabled_ = plugins_enabled;
    Invalidate(SettingsDelegate::ChangeType::kPlugins);
}

void SettingsBase::SetPreferHiddenVolumeControls(bool prefer_hidden_volume_controls)
{
    if (prefer_hidden_volume_controls_ == prefer_hidden_volume_controls)
        return;
    prefer_hidden_volume_controls_ = prefer_hidden_volume_controls;
}

void SettingsBase::SetPreferredColorScheme(mojom::blink::PreferredColorScheme preferred_color_scheme)
{
    if (preferred_color_scheme_ == preferred_color_scheme)
        return;
    preferred_color_scheme_ = preferred_color_scheme;
    Invalidate(SettingsDelegate::ChangeType::kColorScheme);
}

void SettingsBase::SetPreferredContrast(mojom::blink::PreferredContrast preferred_contrast)
{
    if (preferred_contrast_ == preferred_contrast)
        return;
    preferred_contrast_ = preferred_contrast;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetPreferredRootScrollbarColorScheme(mojom::blink::PreferredColorScheme preferred_root_scrollbar_color_scheme)
{
    if (preferred_root_scrollbar_color_scheme_ == preferred_root_scrollbar_color_scheme)
        return;
    preferred_root_scrollbar_color_scheme_ = preferred_root_scrollbar_color_scheme;
    Invalidate(SettingsDelegate::ChangeType::kPaint);
}

void SettingsBase::SetPrefersDefaultScrollbarStyles(bool prefers_default_scrollbar_styles)
{
    if (prefers_default_scrollbar_styles_ == prefers_default_scrollbar_styles)
        return;
    prefers_default_scrollbar_styles_ = prefers_default_scrollbar_styles;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetPrefersReducedMotion(bool prefers_reduced_motion)
{
    if (prefers_reduced_motion_ == prefers_reduced_motion)
        return;
    prefers_reduced_motion_ = prefers_reduced_motion;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetPrefersReducedTransparency(bool prefers_reduced_transparency)
{
    if (prefers_reduced_transparency_ == prefers_reduced_transparency)
        return;
    prefers_reduced_transparency_ = prefers_reduced_transparency;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetPresentationReceiver(bool presentation_receiver)
{
    if (presentation_receiver_ == presentation_receiver)
        return;
    presentation_receiver_ = presentation_receiver;
}

void SettingsBase::SetPresentationRequiresUserGesture(bool presentation_requires_user_gesture)
{
    if (presentation_requires_user_gesture_ == presentation_requires_user_gesture)
        return;
    presentation_requires_user_gesture_ = presentation_requires_user_gesture;
}

void SettingsBase::SetPrimaryHoverType(mojom::blink::HoverType primary_hover_type)
{
    if (primary_hover_type_ == primary_hover_type)
        return;
    primary_hover_type_ = primary_hover_type;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetPrimaryPointerType(blink::mojom::PointerType primary_pointer_type)
{
    if (primary_pointer_type_ == primary_pointer_type)
        return;
    primary_pointer_type_ = primary_pointer_type;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetPrintingMaximumShrinkFactor(float printing_maximum_shrink_factor)
{
    if (printing_maximum_shrink_factor_ == printing_maximum_shrink_factor)
        return;
    printing_maximum_shrink_factor_ = printing_maximum_shrink_factor;
}

void SettingsBase::SetReportScreenSizeInPhysicalPixelsQuirk(bool report_screen_size_in_physical_pixels_quirk)
{
    if (report_screen_size_in_physical_pixels_quirk_ == report_screen_size_in_physical_pixels_quirk)
        return;
    report_screen_size_in_physical_pixels_quirk_ = report_screen_size_in_physical_pixels_quirk;
}

void SettingsBase::SetRequireTransientActivationAndAuthorizationForSubAppsAPI(bool require_transient_activation_and_authorization_for_sub_apps_api)
{
    if (require_transient_activation_and_authorization_for_sub_apps_api_ == require_transient_activation_and_authorization_for_sub_apps_api)
        return;
    require_transient_activation_and_authorization_for_sub_apps_api_ = require_transient_activation_and_authorization_for_sub_apps_api;
}

void SettingsBase::SetRequireTransientActivationForGetDisplayMedia(bool require_transient_activation_for_get_display_media)
{
    if (require_transient_activation_for_get_display_media_ == require_transient_activation_for_get_display_media)
        return;
    require_transient_activation_for_get_display_media_ = require_transient_activation_for_get_display_media;
}

void SettingsBase::SetRequireTransientActivationForShowFileOrDirectoryPicker(bool require_transient_activation_for_show_file_or_directory_picker)
{
    if (require_transient_activation_for_show_file_or_directory_picker_ == require_transient_activation_for_show_file_or_directory_picker)
        return;
    require_transient_activation_for_show_file_or_directory_picker_ = require_transient_activation_for_show_file_or_directory_picker;
}

void SettingsBase::SetResizable(bool resizable)
{
    if (resizable_ == resizable)
        return;
    resizable_ = resizable;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetRubberBandingOnCompositorThread(bool rubber_banding_on_compositor_thread)
{
    if (rubber_banding_on_compositor_thread_ == rubber_banding_on_compositor_thread)
        return;
    rubber_banding_on_compositor_thread_ = rubber_banding_on_compositor_thread;
}

void SettingsBase::SetScriptEnabled(bool script_enabled)
{
    if (script_enabled_ == script_enabled)
        return;
    script_enabled_ = script_enabled;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetScrollAnimatorEnabled(bool scroll_animator_enabled)
{
    if (scroll_animator_enabled_ == scroll_animator_enabled)
        return;
    scroll_animator_enabled_ = scroll_animator_enabled;
}

void SettingsBase::SetSelectTrailingWhitespaceEnabled(bool select_trailing_whitespace_enabled)
{
    if (select_trailing_whitespace_enabled_ == select_trailing_whitespace_enabled)
        return;
    select_trailing_whitespace_enabled_ = select_trailing_whitespace_enabled;
}

void SettingsBase::SetSelectionClipboardBufferAvailable(bool selection_clipboard_buffer_available)
{
    if (selection_clipboard_buffer_available_ == selection_clipboard_buffer_available)
        return;
    selection_clipboard_buffer_available_ = selection_clipboard_buffer_available;
}

void SettingsBase::SetSelectionIncludesAltImageText(bool selection_includes_alt_image_text)
{
    if (selection_includes_alt_image_text_ == selection_includes_alt_image_text)
        return;
    selection_includes_alt_image_text_ = selection_includes_alt_image_text;
}

void SettingsBase::SetSelectionStrategy(SelectionStrategy selection_strategy)
{
    if (selection_strategy_ == selection_strategy)
        return;
    selection_strategy_ = selection_strategy;
}

void SettingsBase::SetShouldClearDocumentBackground(bool should_clear_document_background)
{
    if (should_clear_document_background_ == should_clear_document_background)
        return;
    should_clear_document_background_ = should_clear_document_background;
}

void SettingsBase::SetShouldPrintBackgrounds(bool should_print_backgrounds)
{
    if (should_print_backgrounds_ == should_print_backgrounds)
        return;
    should_print_backgrounds_ = should_print_backgrounds;
}

void SettingsBase::SetShouldProtectAgainstIpcFlooding(bool should_protect_against_ipc_flooding)
{
    if (should_protect_against_ipc_flooding_ == should_protect_against_ipc_flooding)
        return;
    should_protect_against_ipc_flooding_ = should_protect_against_ipc_flooding;
}

void SettingsBase::SetShouldReuseGlobalForUnownedMainFrame(bool should_reuse_global_for_unowned_main_frame)
{
    if (should_reuse_global_for_unowned_main_frame_ == should_reuse_global_for_unowned_main_frame)
        return;
    should_reuse_global_for_unowned_main_frame_ = should_reuse_global_for_unowned_main_frame;
}

void SettingsBase::SetShowContextMenuOnMouseUp(bool show_context_menu_on_mouse_up)
{
    if (show_context_menu_on_mouse_up_ == show_context_menu_on_mouse_up)
        return;
    show_context_menu_on_mouse_up_ = show_context_menu_on_mouse_up;
}

void SettingsBase::SetShrinksViewportContentToFit(bool shrinks_viewport_content_to_fit)
{
    if (shrinks_viewport_content_to_fit_ == shrinks_viewport_content_to_fit)
        return;
    shrinks_viewport_content_to_fit_ = shrinks_viewport_content_to_fit;
}

void SettingsBase::SetSmartInsertDeleteEnabled(bool smart_insert_delete_enabled)
{
    if (smart_insert_delete_enabled_ == smart_insert_delete_enabled)
        return;
    smart_insert_delete_enabled_ = smart_insert_delete_enabled;
}

void SettingsBase::SetSmoothScrollForFindEnabled(bool smooth_scroll_for_find_enabled)
{
    if (smooth_scroll_for_find_enabled_ == smooth_scroll_for_find_enabled)
        return;
    smooth_scroll_for_find_enabled_ = smooth_scroll_for_find_enabled;
}

void SettingsBase::SetSpatialNavigationEnabled(bool spatial_navigation_enabled)
{
    if (spatial_navigation_enabled_ == spatial_navigation_enabled)
        return;
    spatial_navigation_enabled_ = spatial_navigation_enabled;
}

void SettingsBase::SetSpellCheckEnabledByDefault(bool spell_check_enabled_by_default)
{
    if (spell_check_enabled_by_default_ == spell_check_enabled_by_default)
        return;
    spell_check_enabled_by_default_ = spell_check_enabled_by_default;
}

void SettingsBase::SetStrictMixedContentChecking(bool strict_mixed_content_checking)
{
    if (strict_mixed_content_checking_ == strict_mixed_content_checking)
        return;
    strict_mixed_content_checking_ = strict_mixed_content_checking;
}

void SettingsBase::SetStrictMixedContentCheckingForPlugin(bool strict_mixed_content_checking_for_plugin)
{
    if (strict_mixed_content_checking_for_plugin_ == strict_mixed_content_checking_for_plugin)
        return;
    strict_mixed_content_checking_for_plugin_ = strict_mixed_content_checking_for_plugin;
}

void SettingsBase::SetStrictPowerfulFeatureRestrictions(bool strict_powerful_feature_restrictions)
{
    if (strict_powerful_feature_restrictions_ == strict_powerful_feature_restrictions)
        return;
    strict_powerful_feature_restrictions_ = strict_powerful_feature_restrictions;
}

void SettingsBase::SetStrictlyBlockBlockableMixedContent(bool strictly_block_blockable_mixed_content)
{
    if (strictly_block_blockable_mixed_content_ == strictly_block_blockable_mixed_content)
        return;
    strictly_block_blockable_mixed_content_ = strictly_block_blockable_mixed_content;
}

void SettingsBase::SetSupportsMultipleWindows(bool supports_multiple_windows)
{
    if (supports_multiple_windows_ == supports_multiple_windows)
        return;
    supports_multiple_windows_ = supports_multiple_windows;
}

void SettingsBase::SetSyncXHRInDocumentsEnabled(bool sync_xhr_in_documents_enabled)
{
    if (sync_xhr_in_documents_enabled_ == sync_xhr_in_documents_enabled)
        return;
    sync_xhr_in_documents_enabled_ = sync_xhr_in_documents_enabled;
}

void SettingsBase::SetTargetBlankImpliesNoOpenerEnabledWillBeRemoved(bool target_blank_implies_no_opener_enabled_will_be_removed)
{
    if (target_blank_implies_no_opener_enabled_will_be_removed_ == target_blank_implies_no_opener_enabled_will_be_removed)
        return;
    target_blank_implies_no_opener_enabled_will_be_removed_ = target_blank_implies_no_opener_enabled_will_be_removed;
}

void SettingsBase::SetTextAreasAreResizable(bool text_areas_are_resizable)
{
    if (text_areas_are_resizable_ == text_areas_are_resizable)
        return;
    text_areas_are_resizable_ = text_areas_are_resizable;
    Invalidate(SettingsDelegate::ChangeType::kStyle);
}

void SettingsBase::SetTextAutosizingEnabled(bool text_autosizing_enabled)
{
    if (text_autosizing_enabled_ == text_autosizing_enabled)
        return;
    text_autosizing_enabled_ = text_autosizing_enabled;
    Invalidate(SettingsDelegate::ChangeType::kTextAutosizing);
}

void SettingsBase::SetTextAutosizingWindowSizeOverride(gfx::Size text_autosizing_window_size_override)
{
    if (text_autosizing_window_size_override_ == text_autosizing_window_size_override)
        return;
    text_autosizing_window_size_override_ = text_autosizing_window_size_override;
    Invalidate(SettingsDelegate::ChangeType::kTextAutosizing);
}

void SettingsBase::SetTextTrackBackgroundColor(const String& text_track_background_color)
{
    if (text_track_background_color_ == text_track_background_color)
        return;
    text_track_background_color_ = text_track_background_color;
}

void SettingsBase::SetTextTrackFontFamily(const String& text_track_font_family)
{
    if (text_track_font_family_ == text_track_font_family)
        return;
    text_track_font_family_ = text_track_font_family;
}

void SettingsBase::SetTextTrackFontStyle(const String& text_track_font_style)
{
    if (text_track_font_style_ == text_track_font_style)
        return;
    text_track_font_style_ = text_track_font_style;
}

void SettingsBase::SetTextTrackFontVariant(const String& text_track_font_variant)
{
    if (text_track_font_variant_ == text_track_font_variant)
        return;
    text_track_font_variant_ = text_track_font_variant;
}

void SettingsBase::SetTextTrackKindUserPreference(TextTrackKindUserPreference text_track_kind_user_preference)
{
    if (text_track_kind_user_preference_ == text_track_kind_user_preference)
        return;
    text_track_kind_user_preference_ = text_track_kind_user_preference;
    Invalidate(SettingsDelegate::ChangeType::kTextTrackKindUserPreference);
}

void SettingsBase::SetTextTrackMarginPercentage(double text_track_margin_percentage)
{
    if (text_track_margin_percentage_ == text_track_margin_percentage)
        return;
    text_track_margin_percentage_ = text_track_margin_percentage;
}

void SettingsBase::SetTextTrackTextColor(const String& text_track_text_color)
{
    if (text_track_text_color_ == text_track_text_color)
        return;
    text_track_text_color_ = text_track_text_color;
}

void SettingsBase::SetTextTrackTextShadow(const String& text_track_text_shadow)
{
    if (text_track_text_shadow_ == text_track_text_shadow)
        return;
    text_track_text_shadow_ = text_track_text_shadow;
}

void SettingsBase::SetTextTrackTextSize(const String& text_track_text_size)
{
    if (text_track_text_size_ == text_track_text_size)
        return;
    text_track_text_size_ = text_track_text_size;
}

void SettingsBase::SetTextTrackWindowColor(const String& text_track_window_color)
{
    if (text_track_window_color_ == text_track_window_color)
        return;
    text_track_window_color_ = text_track_window_color;
}

void SettingsBase::SetTextTrackWindowRadius(const String& text_track_window_radius)
{
    if (text_track_window_radius_ == text_track_window_radius)
        return;
    text_track_window_radius_ = text_track_window_radius;
}

void SettingsBase::SetTouchDragDropEnabled(bool touch_drag_drop_enabled)
{
    if (touch_drag_drop_enabled_ == touch_drag_drop_enabled)
        return;
    touch_drag_drop_enabled_ = touch_drag_drop_enabled;
}

void SettingsBase::SetTouchDragEndContextMenu(bool touch_drag_end_context_menu)
{
    if (touch_drag_end_context_menu_ == touch_drag_end_context_menu)
        return;
    touch_drag_end_context_menu_ = touch_drag_end_context_menu;
}

void SettingsBase::SetTouchEditingEnabled(bool touch_editing_enabled)
{
    if (touch_editing_enabled_ == touch_editing_enabled)
        return;
    touch_editing_enabled_ = touch_editing_enabled;
}

void SettingsBase::SetUseAXMenuList(bool use_ax_menu_list)
{
    if (use_ax_menu_list_ == use_ax_menu_list)
        return;
    use_ax_menu_list_ = use_ax_menu_list;
}

void SettingsBase::SetUseWideViewport(bool use_wide_viewport)
{
    if (use_wide_viewport_ == use_wide_viewport)
        return;
    use_wide_viewport_ = use_wide_viewport;
    Invalidate(SettingsDelegate::ChangeType::kViewportDescription);
}

void SettingsBase::SetV8CacheOptions(mojom::blink::V8CacheOptions v8_cache_options)
{
    if (v8_cache_options_ == v8_cache_options)
        return;
    v8_cache_options_ = v8_cache_options;
}

void SettingsBase::SetValidationMessageTimerMagnification(int validation_message_timer_magnification)
{
    if (validation_message_timer_magnification_ == validation_message_timer_magnification)
        return;
    validation_message_timer_magnification_ = validation_message_timer_magnification;
}

void SettingsBase::SetViewportEnabled(bool viewport_enabled)
{
    if (viewport_enabled_ == viewport_enabled)
        return;
    viewport_enabled_ = viewport_enabled;
    Invalidate(SettingsDelegate::ChangeType::kViewportDescription);
}

void SettingsBase::SetViewportMetaEnabled(bool viewport_meta_enabled)
{
    if (viewport_meta_enabled_ == viewport_meta_enabled)
        return;
    viewport_meta_enabled_ = viewport_meta_enabled;
    Invalidate(SettingsDelegate::ChangeType::kViewportDescription);
}

void SettingsBase::SetViewportMetaMergeContentQuirk(bool viewport_meta_merge_content_quirk)
{
    if (viewport_meta_merge_content_quirk_ == viewport_meta_merge_content_quirk)
        return;
    viewport_meta_merge_content_quirk_ = viewport_meta_merge_content_quirk;
}

void SettingsBase::SetViewportMetaZeroValuesQuirk(bool viewport_meta_zero_values_quirk)
{
    if (viewport_meta_zero_values_quirk_ == viewport_meta_zero_values_quirk)
        return;
    viewport_meta_zero_values_quirk_ = viewport_meta_zero_values_quirk;
}

void SettingsBase::SetViewportStyle(mojom::blink::ViewportStyle viewport_style)
{
    if (viewport_style_ == viewport_style)
        return;
    viewport_style_ = viewport_style;
    Invalidate(SettingsDelegate::ChangeType::kViewportStyle);
}

void SettingsBase::SetWebAppScope(const String& web_app_scope)
{
    if (web_app_scope_ == web_app_scope)
        return;
    web_app_scope_ = web_app_scope;
}

void SettingsBase::SetWebGL1Enabled(bool web_gl_1_enabled)
{
    if (web_gl_1_enabled_ == web_gl_1_enabled)
        return;
    web_gl_1_enabled_ = web_gl_1_enabled;
}

void SettingsBase::SetWebGL2Enabled(bool webgl2_enabled)
{
    if (webgl2_enabled_ == webgl2_enabled)
        return;
    webgl2_enabled_ = webgl2_enabled;
}

void SettingsBase::SetWebGLErrorsToConsoleEnabled(bool web_gl_errors_to_console_enabled)
{
    if (web_gl_errors_to_console_enabled_ == web_gl_errors_to_console_enabled)
        return;
    web_gl_errors_to_console_enabled_ = web_gl_errors_to_console_enabled;
}

void SettingsBase::SetWebSecurityEnabled(bool web_security_enabled)
{
    if (web_security_enabled_ == web_security_enabled)
        return;
    web_security_enabled_ = web_security_enabled;
}

void SettingsBase::SetWideViewportQuirkEnabled(bool wide_viewport_quirk_enabled)
{
    if (wide_viewport_quirk_enabled_ == wide_viewport_quirk_enabled)
        return;
    wide_viewport_quirk_enabled_ = wide_viewport_quirk_enabled;
}

void SettingsBase::SetWindowShowState(ui::mojom::blink::WindowShowState window_show_state)
{
    if (window_show_state_ == window_show_state)
        return;
    window_show_state_ = window_show_state;
    Invalidate(SettingsDelegate::ChangeType::kMediaQuery);
}

void SettingsBase::SetFromStrings(const String& name, const String& value)
{
    if (name == "DOMPasteAllowed") {
        SetDOMPasteAllowed(FromString<bool>()(value));
        return;
    }
    if (name == "DontSendKeyEventsToJavascript") {
        SetDontSendKeyEventsToJavascript(FromString<bool>()(value));
        return;
    }
    if (name == "HighlightAds") {
        SetHighlightAds(FromString<bool>()(value));
        return;
    }
    if (name == "LCDTextPreference") {
        SetLCDTextPreference(FromString<LCDTextPreference>()(value));
        return;
    }
    if (name == "NetworkQuietTimeout") {
        SetNetworkQuietTimeout(FromString<double>()(value));
        return;
    }
    if (name == "WebXRImmersiveArAllowed") {
        SetWebXRImmersiveArAllowed(FromString<bool>()(value));
        return;
    }
    if (name == "accelerated2dCanvasMSAASampleCount") {
        SetAccelerated2dCanvasMSAASampleCount(FromString<int>()(value));
        return;
    }
    if (name == "acceleratedCompositingEnabled") {
        SetAcceleratedCompositingEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "accessibilityAlwaysShowFocus") {
        SetAccessibilityAlwaysShowFocus(FromString<bool>()(value));
        return;
    }
    if (name == "accessibilityFontScaleFactor") {
        SetAccessibilityFontScaleFactor(FromString<double>()(value));
        return;
    }
    if (name == "accessibilityFontWeightAdjustment") {
        SetAccessibilityFontWeightAdjustment(FromString<int>()(value));
        return;
    }
    if (name == "accessibilityIncludeSvgGElement") {
        SetAccessibilityIncludeSvgGElement(FromString<bool>()(value));
        return;
    }
    if (name == "accessibilityPasswordValuesEnabled") {
        SetAccessibilityPasswordValuesEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "accessibilityTextSizeContrastFactor") {
        SetAccessibilityTextSizeContrastFactor(FromString<int>()(value));
        return;
    }
    if (name == "allowCustomScrollbarInMainFrame") {
        SetAllowCustomScrollbarInMainFrame(FromString<bool>()(value));
        return;
    }
    if (name == "allowFileAccessFromFileURLs") {
        SetAllowFileAccessFromFileURLs(FromString<bool>()(value));
        return;
    }
    if (name == "allowGeolocationOnInsecureOrigins") {
        SetAllowGeolocationOnInsecureOrigins(FromString<bool>()(value));
        return;
    }
    if (name == "allowNonEmptyNavigatorPlugins") {
        SetAllowNonEmptyNavigatorPlugins(FromString<bool>()(value));
        return;
    }
    if (name == "allowRunningOfInsecureContent") {
        SetAllowRunningOfInsecureContent(FromString<bool>()(value));
        return;
    }
    if (name == "allowScriptsToCloseWindows") {
        SetAllowScriptsToCloseWindows(FromString<bool>()(value));
        return;
    }
    if (name == "allowUniversalAccessFromFileURLs") {
        SetAllowUniversalAccessFromFileURLs(FromString<bool>()(value));
        return;
    }
    if (name == "alwaysShowContextMenuOnTouch") {
        SetAlwaysShowContextMenuOnTouch(FromString<bool>()(value));
        return;
    }
    if (name == "antialiased2dCanvasEnabled") {
        SetAntialiased2dCanvasEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "antialiasedClips2dCanvasEnabled") {
        SetAntialiasedClips2dCanvasEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "ariaModalPrunesAXTree") {
        SetAriaModalPrunesAXTree(FromString<bool>()(value));
        return;
    }
    if (name == "autoplayPolicy") {
        SetAutoplayPolicy(FromString<AutoplayPolicy::Type>()(value));
        return;
    }
    if (name == "availableHoverTypes") {
        SetAvailableHoverTypes(FromString<int>()(value));
        return;
    }
    if (name == "availablePointerTypes") {
        SetAvailablePointerTypes(FromString<int>()(value));
        return;
    }
    if (name == "barrelButtonForDragEnabled") {
        SetBarrelButtonForDragEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "bypassCSP") {
        SetBypassCSP(FromString<bool>()(value));
        return;
    }
    if (name == "caretBrowsingEnabled") {
        SetCaretBrowsingEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "cookieEnabled") {
        SetCookieEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "defaultFixedFontSize") {
        SetDefaultFixedFontSize(FromString<int>()(value));
        return;
    }
    if (name == "defaultFontSize") {
        SetDefaultFontSize(FromString<int>()(value));
        return;
    }
    if (name == "defaultTextEncodingName") {
        SetDefaultTextEncodingName(FromString<String>()(value));
        return;
    }
    if (name == "defaultVideoPosterURL") {
        SetDefaultVideoPosterURL(FromString<String>()(value));
        return;
    }
    if (name == "deviceScaleAdjustment") {
        SetDeviceScaleAdjustment(FromString<double>()(value));
        return;
    }
    if (name == "disableReadingFromCanvas") {
        SetDisableReadingFromCanvas(FromString<bool>()(value));
        return;
    }
    if (name == "disallowFetchForDocWrittenScriptsInMainFrame") {
        SetDisallowFetchForDocWrittenScriptsInMainFrame(FromString<bool>()(value));
        return;
    }
    if (name == "disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G") {
        SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(FromString<bool>()(value));
        return;
    }
    if (name == "disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections") {
        SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(FromString<bool>()(value));
        return;
    }
    if (name == "displayModeOverride") {
        SetDisplayModeOverride(FromString<blink::mojom::DisplayMode>()(value));
        return;
    }
    if (name == "dnsPrefetchingEnabled") {
        SetDNSPrefetchingEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "doHtmlPreloadScanning") {
        SetDoHtmlPreloadScanning(FromString<bool>()(value));
        return;
    }
    if (name == "doNotUpdateSelectionOnMutatingSelectionRange") {
        SetDoNotUpdateSelectionOnMutatingSelectionRange(FromString<bool>()(value));
        return;
    }
    if (name == "downloadableBinaryFontsEnabled") {
        SetDownloadableBinaryFontsEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "dynamicSafeAreaInsetsEnabled") {
        SetDynamicSafeAreaInsetsEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "editingBehaviorType") {
        SetEditingBehaviorType(FromString<mojom::EditingBehavior>()(value));
        return;
    }
    if (name == "embeddedMediaExperienceEnabled") {
        SetEmbeddedMediaExperienceEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "forceAndroidOverlayScrollbar") {
        SetForceAndroidOverlayScrollbar(FromString<bool>()(value));
        return;
    }
    if (name == "forceDarkModeEnabled") {
        SetForceDarkModeEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "forceMainWorldInitialization") {
        SetForceMainWorldInitialization(FromString<bool>()(value));
        return;
    }
    if (name == "forceTouchEventFeatureDetectionForInspector") {
        SetForceTouchEventFeatureDetectionForInspector(FromString<bool>()(value));
        return;
    }
    if (name == "forceZeroLayoutHeight") {
        SetForceZeroLayoutHeight(FromString<bool>()(value));
        return;
    }
    if (name == "fullscreenSupported") {
        SetFullscreenSupported(FromString<bool>()(value));
        return;
    }
    if (name == "hideDownloadUI") {
        SetHideDownloadUI(FromString<bool>()(value));
        return;
    }
    if (name == "hideScrollbars") {
        SetHideScrollbars(FromString<bool>()(value));
        return;
    }
    if (name == "hyperlinkAuditingEnabled") {
        SetHyperlinkAuditingEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "ignoreMainFrameOverflowHiddenQuirk") {
        SetIgnoreMainFrameOverflowHiddenQuirk(FromString<bool>()(value));
        return;
    }
    if (name == "imageAnimationPolicy") {
        SetImageAnimationPolicy(FromString<mojom::blink::ImageAnimationPolicy>()(value));
        return;
    }
    if (name == "imagesEnabled") {
        SetImagesEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "immersiveModeEnabled") {
        SetImmersiveModeEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "inForcedColors") {
        SetInForcedColors(FromString<bool>()(value));
        return;
    }
    if (name == "invertedColors") {
        SetInvertedColors(FromString<bool>()(value));
        return;
    }
    if (name == "isForcedColorsDisabled") {
        SetIsForcedColorsDisabled(FromString<bool>()(value));
        return;
    }
    if (name == "javaScriptCanAccessClipboard") {
        SetJavaScriptCanAccessClipboard(FromString<bool>()(value));
        return;
    }
    if (name == "lazyLoadEnabled") {
        SetLazyLoadEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "lazyLoadingFrameMarginPx2G") {
        SetLazyLoadingFrameMarginPx2G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingFrameMarginPx3G") {
        SetLazyLoadingFrameMarginPx3G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingFrameMarginPx4G") {
        SetLazyLoadingFrameMarginPx4G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingFrameMarginPxOffline") {
        SetLazyLoadingFrameMarginPxOffline(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingFrameMarginPxSlow2G") {
        SetLazyLoadingFrameMarginPxSlow2G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingFrameMarginPxUnknown") {
        SetLazyLoadingFrameMarginPxUnknown(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingImageMarginPx2G") {
        SetLazyLoadingImageMarginPx2G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingImageMarginPx3G") {
        SetLazyLoadingImageMarginPx3G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingImageMarginPx4G") {
        SetLazyLoadingImageMarginPx4G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingImageMarginPxOffline") {
        SetLazyLoadingImageMarginPxOffline(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingImageMarginPxSlow2G") {
        SetLazyLoadingImageMarginPxSlow2G(FromString<int>()(value));
        return;
    }
    if (name == "lazyLoadingImageMarginPxUnknown") {
        SetLazyLoadingImageMarginPxUnknown(FromString<int>()(value));
        return;
    }
    if (name == "loadWithOverviewMode") {
        SetLoadWithOverviewMode(FromString<bool>()(value));
        return;
    }
    if (name == "loadsImagesAutomatically") {
        SetLoadsImagesAutomatically(FromString<bool>()(value));
        return;
    }
    if (name == "localStorageEnabled") {
        SetLocalStorageEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "logDnsPrefetchAndPreconnect") {
        SetLogDnsPrefetchAndPreconnect(FromString<bool>()(value));
        return;
    }
    if (name == "logPreload") {
        SetLogPreload(FromString<bool>()(value));
        return;
    }
    if (name == "lowPriorityIframesThreshold") {
        SetLowPriorityIframesThreshold(FromString<WebEffectiveConnectionType>()(value));
        return;
    }
    if (name == "mainFrameClipsContent") {
        SetMainFrameClipsContent(FromString<bool>()(value));
        return;
    }
    if (name == "mainFrameResizesAreOrientationChanges") {
        SetMainFrameResizesAreOrientationChanges(FromString<bool>()(value));
        return;
    }
    if (name == "maxTouchPoints") {
        SetMaxTouchPoints(FromString<int>()(value));
        return;
    }
    if (name == "mediaControlsEnabled") {
        SetMediaControlsEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "mediaTypeOverride") {
        SetMediaTypeOverride(FromString<String>()(value));
        return;
    }
    if (name == "minimumFontSize") {
        SetMinimumFontSize(FromString<int>()(value));
        return;
    }
    if (name == "minimumLogicalFontSize") {
        SetMinimumLogicalFontSize(FromString<int>()(value));
        return;
    }
    if (name == "mockGestureTapHighlightsEnabled") {
        SetMockGestureTapHighlightsEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "modalContextMenu") {
        SetModalContextMenu(FromString<bool>()(value));
        return;
    }
    if (name == "multiTargetTapNotificationEnabled") {
        SetMultiTargetTapNotificationEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "navigateOnDragDrop") {
        SetNavigateOnDragDrop(FromString<bool>()(value));
        return;
    }
    if (name == "navigationControls") {
        SetNavigationControls(FromString<NavigationControls>()(value));
        return;
    }
    if (name == "navigatorPlatformOverride") {
        SetNavigatorPlatformOverride(FromString<String>()(value));
        return;
    }
    if (name == "outputDeviceUpdateAbilityType") {
        SetOutputDeviceUpdateAbilityType(FromString<mojom::blink::OutputDeviceUpdateAbilityType>()(value));
        return;
    }
    if (name == "parserScriptingFlagPolicy") {
        SetParserScriptingFlagPolicy(FromString<ParserScriptingFlagPolicy>()(value));
        return;
    }
    if (name == "passwordEchoDurationInSeconds") {
        SetPasswordEchoDurationInSeconds(FromString<double>()(value));
        return;
    }
    if (name == "passwordEchoEnabled") {
        SetPasswordEchoEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "pictureInPictureEnabled") {
        SetPictureInPictureEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "placeRTLScrollbarsOnLeftSideInMainFrame") {
        SetPlaceRTLScrollbarsOnLeftSideInMainFrame(FromString<bool>()(value));
        return;
    }
    if (name == "pluginsEnabled") {
        SetPluginsEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "preferHiddenVolumeControls") {
        SetPreferHiddenVolumeControls(FromString<bool>()(value));
        return;
    }
    if (name == "preferredColorScheme") {
        SetPreferredColorScheme(FromString<mojom::blink::PreferredColorScheme>()(value));
        return;
    }
    if (name == "preferredContrast") {
        SetPreferredContrast(FromString<mojom::blink::PreferredContrast>()(value));
        return;
    }
    if (name == "preferredRootScrollbarColorScheme") {
        SetPreferredRootScrollbarColorScheme(FromString<mojom::blink::PreferredColorScheme>()(value));
        return;
    }
    if (name == "prefersDefaultScrollbarStyles") {
        SetPrefersDefaultScrollbarStyles(FromString<bool>()(value));
        return;
    }
    if (name == "prefersReducedMotion") {
        SetPrefersReducedMotion(FromString<bool>()(value));
        return;
    }
    if (name == "prefersReducedTransparency") {
        SetPrefersReducedTransparency(FromString<bool>()(value));
        return;
    }
    if (name == "presentationReceiver") {
        SetPresentationReceiver(FromString<bool>()(value));
        return;
    }
    if (name == "presentationRequiresUserGesture") {
        SetPresentationRequiresUserGesture(FromString<bool>()(value));
        return;
    }
    if (name == "primaryHoverType") {
        SetPrimaryHoverType(FromString<mojom::blink::HoverType>()(value));
        return;
    }
    if (name == "primaryPointerType") {
        SetPrimaryPointerType(FromString<blink::mojom::PointerType>()(value));
        return;
    }
    if (name == "printingMaximumShrinkFactor") {
        SetPrintingMaximumShrinkFactor(FromString<float>()(value));
        return;
    }
    if (name == "reportScreenSizeInPhysicalPixelsQuirk") {
        SetReportScreenSizeInPhysicalPixelsQuirk(FromString<bool>()(value));
        return;
    }
    if (name == "requireTransientActivationAndAuthorizationForSubAppsAPI") {
        SetRequireTransientActivationAndAuthorizationForSubAppsAPI(FromString<bool>()(value));
        return;
    }
    if (name == "requireTransientActivationForGetDisplayMedia") {
        SetRequireTransientActivationForGetDisplayMedia(FromString<bool>()(value));
        return;
    }
    if (name == "requireTransientActivationForShowFileOrDirectoryPicker") {
        SetRequireTransientActivationForShowFileOrDirectoryPicker(FromString<bool>()(value));
        return;
    }
    if (name == "resizable") {
        SetResizable(FromString<bool>()(value));
        return;
    }
    if (name == "rubberBandingOnCompositorThread") {
        SetRubberBandingOnCompositorThread(FromString<bool>()(value));
        return;
    }
    if (name == "scriptEnabled") {
        SetScriptEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "scrollAnimatorEnabled") {
        SetScrollAnimatorEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "selectTrailingWhitespaceEnabled") {
        SetSelectTrailingWhitespaceEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "selectionClipboardBufferAvailable") {
        SetSelectionClipboardBufferAvailable(FromString<bool>()(value));
        return;
    }
    if (name == "selectionIncludesAltImageText") {
        SetSelectionIncludesAltImageText(FromString<bool>()(value));
        return;
    }
    if (name == "selectionStrategy") {
        SetSelectionStrategy(FromString<SelectionStrategy>()(value));
        return;
    }
    if (name == "shouldClearDocumentBackground") {
        SetShouldClearDocumentBackground(FromString<bool>()(value));
        return;
    }
    if (name == "shouldPrintBackgrounds") {
        SetShouldPrintBackgrounds(FromString<bool>()(value));
        return;
    }
    if (name == "shouldProtectAgainstIpcFlooding") {
        SetShouldProtectAgainstIpcFlooding(FromString<bool>()(value));
        return;
    }
    if (name == "shouldReuseGlobalForUnownedMainFrame") {
        SetShouldReuseGlobalForUnownedMainFrame(FromString<bool>()(value));
        return;
    }
    if (name == "showContextMenuOnMouseUp") {
        SetShowContextMenuOnMouseUp(FromString<bool>()(value));
        return;
    }
    if (name == "shrinksViewportContentToFit") {
        SetShrinksViewportContentToFit(FromString<bool>()(value));
        return;
    }
    if (name == "smartInsertDeleteEnabled") {
        SetSmartInsertDeleteEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "smoothScrollForFindEnabled") {
        SetSmoothScrollForFindEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "spatialNavigationEnabled") {
        SetSpatialNavigationEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "spellCheckEnabledByDefault") {
        SetSpellCheckEnabledByDefault(FromString<bool>()(value));
        return;
    }
    if (name == "strictMixedContentChecking") {
        SetStrictMixedContentChecking(FromString<bool>()(value));
        return;
    }
    if (name == "strictMixedContentCheckingForPlugin") {
        SetStrictMixedContentCheckingForPlugin(FromString<bool>()(value));
        return;
    }
    if (name == "strictPowerfulFeatureRestrictions") {
        SetStrictPowerfulFeatureRestrictions(FromString<bool>()(value));
        return;
    }
    if (name == "strictlyBlockBlockableMixedContent") {
        SetStrictlyBlockBlockableMixedContent(FromString<bool>()(value));
        return;
    }
    if (name == "supportsMultipleWindows") {
        SetSupportsMultipleWindows(FromString<bool>()(value));
        return;
    }
    if (name == "syncXHRInDocumentsEnabled") {
        SetSyncXHRInDocumentsEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "targetBlankImpliesNoOpenerEnabledWillBeRemoved") {
        SetTargetBlankImpliesNoOpenerEnabledWillBeRemoved(FromString<bool>()(value));
        return;
    }
    if (name == "textAreasAreResizable") {
        SetTextAreasAreResizable(FromString<bool>()(value));
        return;
    }
    if (name == "textAutosizingEnabled") {
        SetTextAutosizingEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "textAutosizingWindowSizeOverride") {
        SetTextAutosizingWindowSizeOverride(FromString<gfx::Size>()(value));
        return;
    }
    if (name == "textTrackBackgroundColor") {
        SetTextTrackBackgroundColor(FromString<String>()(value));
        return;
    }
    if (name == "textTrackFontFamily") {
        SetTextTrackFontFamily(FromString<String>()(value));
        return;
    }
    if (name == "textTrackFontStyle") {
        SetTextTrackFontStyle(FromString<String>()(value));
        return;
    }
    if (name == "textTrackFontVariant") {
        SetTextTrackFontVariant(FromString<String>()(value));
        return;
    }
    if (name == "textTrackKindUserPreference") {
        SetTextTrackKindUserPreference(FromString<TextTrackKindUserPreference>()(value));
        return;
    }
    if (name == "textTrackMarginPercentage") {
        SetTextTrackMarginPercentage(FromString<double>()(value));
        return;
    }
    if (name == "textTrackTextColor") {
        SetTextTrackTextColor(FromString<String>()(value));
        return;
    }
    if (name == "textTrackTextShadow") {
        SetTextTrackTextShadow(FromString<String>()(value));
        return;
    }
    if (name == "textTrackTextSize") {
        SetTextTrackTextSize(FromString<String>()(value));
        return;
    }
    if (name == "textTrackWindowColor") {
        SetTextTrackWindowColor(FromString<String>()(value));
        return;
    }
    if (name == "textTrackWindowRadius") {
        SetTextTrackWindowRadius(FromString<String>()(value));
        return;
    }
    if (name == "touchDragDropEnabled") {
        SetTouchDragDropEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "touchDragEndContextMenu") {
        SetTouchDragEndContextMenu(FromString<bool>()(value));
        return;
    }
    if (name == "touchEditingEnabled") {
        SetTouchEditingEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "useAXMenuList") {
        SetUseAXMenuList(FromString<bool>()(value));
        return;
    }
    if (name == "useWideViewport") {
        SetUseWideViewport(FromString<bool>()(value));
        return;
    }
    if (name == "v8CacheOptions") {
        SetV8CacheOptions(FromString<mojom::blink::V8CacheOptions>()(value));
        return;
    }
    if (name == "validationMessageTimerMagnification") {
        SetValidationMessageTimerMagnification(FromString<int>()(value));
        return;
    }
    if (name == "viewportEnabled") {
        SetViewportEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "viewportMetaEnabled") {
        SetViewportMetaEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "viewportMetaMergeContentQuirk") {
        SetViewportMetaMergeContentQuirk(FromString<bool>()(value));
        return;
    }
    if (name == "viewportMetaZeroValuesQuirk") {
        SetViewportMetaZeroValuesQuirk(FromString<bool>()(value));
        return;
    }
    if (name == "viewportStyle") {
        SetViewportStyle(FromString<mojom::blink::ViewportStyle>()(value));
        return;
    }
    if (name == "webAppScope") {
        SetWebAppScope(FromString<String>()(value));
        return;
    }
    if (name == "webGL1Enabled") {
        SetWebGL1Enabled(FromString<bool>()(value));
        return;
    }
    if (name == "webGL2Enabled") {
        SetWebGL2Enabled(FromString<bool>()(value));
        return;
    }
    if (name == "webGLErrorsToConsoleEnabled") {
        SetWebGLErrorsToConsoleEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "webSecurityEnabled") {
        SetWebSecurityEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "wideViewportQuirkEnabled") {
        SetWideViewportQuirkEnabled(FromString<bool>()(value));
        return;
    }
    if (name == "windowShowState") {
        SetWindowShowState(FromString<ui::mojom::blink::WindowShowState>()(value));
        return;
    }
}

void SettingsBase::SetDelegate(SettingsDelegate* delegate)
{
    delegate_ = delegate;
}

void SettingsBase::Invalidate(SettingsDelegate::ChangeType change_type)
{
    if (delegate_) {
        delegate_->SettingsChanged(change_type);
    }
}

} // namespace blink
