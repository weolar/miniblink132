// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/settings_base.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/frame/settings.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SETTINGS_BASE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SETTINGS_BASE_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/frame/settings_delegate.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/public/common/css/navigation_controls.h"
#include "third_party/blink/public/mojom/css/preferred_color_scheme.mojom-shared.h"
#include "third_party/blink/public/mojom/manifest/display_mode.mojom-shared.h"
#include "third_party/blink/public/mojom/v8_cache_options.mojom-blink.h"
#include "third_party/blink/public/mojom/webpreferences/web_preferences.mojom-blink.h"
#include "third_party/blink/public/platform/web_effective_connection_type.h"
#include "third_party/blink/renderer/core/editing/selection_strategy.h"
#include "third_party/blink/renderer/core/html/media/autoplay_policy.h"
#include "third_party/blink/renderer/core/html/parser/parser_scripting_flag_policy.h"
#include "third_party/blink/renderer/core/html/track/text_track_kind_user_preference.h"
#include "third_party/blink/renderer/platform/graphics/lcd_text_preference.h"
#include "ui/base/mojom/window_show_state.mojom-blink.h"
#include "ui/base/pointer/pointer_device.h"
#include "ui/gfx/geometry/size.h"

namespace blink {

class CORE_EXPORT SettingsBase {
    DISALLOW_NEW();

public:
    bool GetDOMPasteAllowed() const
    {
        return dom_paste_allowed_;
    }
    bool GetDontSendKeyEventsToJavascript() const
    {
        return dont_send_key_events_to_javascript_;
    }
    bool GetHighlightAds() const
    {
        return highlight_ads_;
    }
    LCDTextPreference GetLCDTextPreference() const
    {
        return lcd_text_preference_;
    }
    double GetNetworkQuietTimeout() const
    {
        return network_quiet_timeout_;
    }
    bool GetWebXRImmersiveArAllowed() const
    {
        return web_xr_immersive_ar_allowed_;
    }
    int GetAccelerated2dCanvasMSAASampleCount() const
    {
        return accelerated_2d_canvas_msaa_sample_count_;
    }
    bool GetAcceleratedCompositingEnabled() const
    {
        return accelerated_compositing_enabled_;
    }
    bool GetAccessibilityAlwaysShowFocus() const
    {
        return accessibility_always_show_focus_;
    }
    double GetAccessibilityFontScaleFactor() const
    {
        return accessibility_font_scale_factor_;
    }
    int GetAccessibilityFontWeightAdjustment() const
    {
        return accessibility_font_weight_adjustment_;
    }
    bool GetAccessibilityIncludeSvgGElement() const
    {
        return accessibility_include_svg_g_element_;
    }
    bool GetAccessibilityPasswordValuesEnabled() const
    {
        return accessibility_password_values_enabled_;
    }
    int GetAccessibilityTextSizeContrastFactor() const
    {
        return accessibility_text_size_contrast_factor_;
    }
    bool GetAllowCustomScrollbarInMainFrame() const
    {
        return allow_custom_scrollbar_in_main_frame_;
    }
    bool GetAllowFileAccessFromFileURLs() const
    {
        return allow_file_access_from_file_urls_;
    }
    bool GetAllowGeolocationOnInsecureOrigins() const
    {
        return allow_geolocation_on_insecure_origins_;
    }
    bool GetAllowNonEmptyNavigatorPlugins() const
    {
        return allow_non_empty_navigator_plugins_;
    }
    bool GetAllowRunningOfInsecureContent() const
    {
        return allow_running_of_insecure_content_;
    }
    bool GetAllowScriptsToCloseWindows() const
    {
        return allow_scripts_to_close_windows_;
    }
    bool GetAllowUniversalAccessFromFileURLs() const
    {
        return allow_universal_access_from_file_urls_;
    }
    bool GetAlwaysShowContextMenuOnTouch() const
    {
        return always_show_context_menu_on_touch_;
    }
    bool GetAntialiased2dCanvasEnabled() const
    {
        return antialiased_2d_canvas_enabled_;
    }
    bool GetAntialiasedClips2dCanvasEnabled() const
    {
        return antialiased_clips_2d_canvas_enabled_;
    }
    bool GetAriaModalPrunesAXTree() const
    {
        return aria_modal_prunes_ax_tree_;
    }
    AutoplayPolicy::Type GetAutoplayPolicy() const
    {
        return autoplay_policy_;
    }
    int GetAvailableHoverTypes() const
    {
        return available_hover_types_;
    }
    int GetAvailablePointerTypes() const
    {
        return available_pointer_types_;
    }
    bool GetBarrelButtonForDragEnabled() const
    {
        return barrel_button_for_drag_enabled_;
    }
    bool GetBypassCSP() const
    {
        return bypass_csp_;
    }
    bool GetCaretBrowsingEnabled() const
    {
        return caret_browsing_enabled_;
    }
    bool GetCookieEnabled() const
    {
        return cookie_enabled_;
    }
    int GetDefaultFixedFontSize() const
    {
        return default_fixed_font_size_;
    }
    int GetDefaultFontSize() const
    {
        return default_font_size_;
    }
    const String& GetDefaultTextEncodingName() const
    {
        return default_text_encoding_name_;
    }
    const String& GetDefaultVideoPosterURL() const
    {
        return default_video_poster_url_;
    }
    double GetDeviceScaleAdjustment() const
    {
        return device_scale_adjustment_;
    }
    bool GetDisableReadingFromCanvas() const
    {
        return disable_reading_from_canvas_;
    }
    bool GetDisallowFetchForDocWrittenScriptsInMainFrame() const
    {
        return disallow_fetch_for_doc_written_scripts_in_main_frame_;
    }
    bool GetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G() const
    {
        return disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g_;
    }
    bool GetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections() const
    {
        return disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections_;
    }
    blink::mojom::DisplayMode GetDisplayModeOverride() const
    {
        return display_mode_override_;
    }
    bool GetDNSPrefetchingEnabled() const
    {
        return dns_prefetching_enabled_;
    }
    bool GetDoHtmlPreloadScanning() const
    {
        return do_html_preload_scanning_;
    }
    bool GetDoNotUpdateSelectionOnMutatingSelectionRange() const
    {
        return do_not_update_selection_on_mutating_selection_range_;
    }
    bool GetDownloadableBinaryFontsEnabled() const
    {
        return downloadable_binary_fonts_enabled_;
    }
    bool GetDynamicSafeAreaInsetsEnabled() const
    {
        return dynamic_safe_area_insets_enabled_;
    }
    mojom::EditingBehavior GetEditingBehaviorType() const
    {
        return editing_behavior_type_;
    }
    bool GetEmbeddedMediaExperienceEnabled() const
    {
        return embedded_media_experience_enabled_;
    }
    bool GetForceAndroidOverlayScrollbar() const
    {
        return force_android_overlay_scrollbar_;
    }
    bool GetForceDarkModeEnabled() const
    {
        return force_dark_mode_enabled_;
    }
    bool GetForceMainWorldInitialization() const
    {
        return force_main_world_initialization_;
    }
    bool GetForceTouchEventFeatureDetectionForInspector() const
    {
        return force_touch_event_feature_detection_for_inspector_;
    }
    bool GetForceZeroLayoutHeight() const
    {
        return force_zero_layout_height_;
    }
    bool GetFullscreenSupported() const
    {
        return fullscreen_supported_;
    }
    bool GetHideDownloadUI() const
    {
        return hide_download_ui_;
    }
    bool GetHideScrollbars() const
    {
        return hide_scrollbars_;
    }
    bool GetHyperlinkAuditingEnabled() const
    {
        return hyperlink_auditing_enabled_;
    }
    bool GetIgnoreMainFrameOverflowHiddenQuirk() const
    {
        return ignore_main_frame_overflow_hidden_quirk_;
    }
    mojom::blink::ImageAnimationPolicy GetImageAnimationPolicy() const
    {
        return image_animation_policy_;
    }
    bool GetImagesEnabled() const
    {
        return images_enabled_;
    }
    bool GetImmersiveModeEnabled() const
    {
        return immersive_mode_enabled_;
    }
    bool GetInForcedColors() const
    {
        return in_forced_colors_;
    }
    bool GetInvertedColors() const
    {
        return inverted_colors_;
    }
    bool GetIsForcedColorsDisabled() const
    {
        return is_forced_colors_disabled_;
    }
    bool GetJavaScriptCanAccessClipboard() const
    {
        return java_script_can_access_clipboard_;
    }
    bool GetLazyLoadEnabled() const
    {
        return lazy_load_enabled_;
    }
    int GetLazyLoadingFrameMarginPx2G() const
    {
        return lazy_loading_frame_margin_px_2_g_;
    }
    int GetLazyLoadingFrameMarginPx3G() const
    {
        return lazy_loading_frame_margin_px_3_g_;
    }
    int GetLazyLoadingFrameMarginPx4G() const
    {
        return lazy_loading_frame_margin_px_4_g_;
    }
    int GetLazyLoadingFrameMarginPxOffline() const
    {
        return lazy_loading_frame_margin_px_offline_;
    }
    int GetLazyLoadingFrameMarginPxSlow2G() const
    {
        return lazy_loading_frame_margin_px_slow_2_g_;
    }
    int GetLazyLoadingFrameMarginPxUnknown() const
    {
        return lazy_loading_frame_margin_px_unknown_;
    }
    int GetLazyLoadingImageMarginPx2G() const
    {
        return lazy_loading_image_margin_px_2_g_;
    }
    int GetLazyLoadingImageMarginPx3G() const
    {
        return lazy_loading_image_margin_px_3_g_;
    }
    int GetLazyLoadingImageMarginPx4G() const
    {
        return lazy_loading_image_margin_px_4_g_;
    }
    int GetLazyLoadingImageMarginPxOffline() const
    {
        return lazy_loading_image_margin_px_offline_;
    }
    int GetLazyLoadingImageMarginPxSlow2G() const
    {
        return lazy_loading_image_margin_px_slow_2_g_;
    }
    int GetLazyLoadingImageMarginPxUnknown() const
    {
        return lazy_loading_image_margin_px_unknown_;
    }
    bool GetLoadWithOverviewMode() const
    {
        return load_with_overview_mode_;
    }
    bool GetLoadsImagesAutomatically() const
    {
        return loads_images_automatically_;
    }
    bool GetLocalStorageEnabled() const
    {
        return local_storage_enabled_;
    }
    bool GetLogDnsPrefetchAndPreconnect() const
    {
        return log_dns_prefetch_and_preconnect_;
    }
    bool GetLogPreload() const
    {
        return log_preload_;
    }
    WebEffectiveConnectionType GetLowPriorityIframesThreshold() const
    {
        return low_priority_iframes_threshold_;
    }
    bool GetMainFrameClipsContent() const
    {
        return main_frame_clips_content_;
    }
    bool GetMainFrameResizesAreOrientationChanges() const
    {
        return main_frame_resizes_are_orientation_changes_;
    }
    int GetMaxTouchPoints() const
    {
        return max_touch_points_;
    }
    bool GetMediaControlsEnabled() const
    {
        return media_controls_enabled_;
    }
    const String& GetMediaTypeOverride() const
    {
        return media_type_override_;
    }
    int GetMinimumFontSize() const
    {
        return minimum_font_size_;
    }
    int GetMinimumLogicalFontSize() const
    {
        return minimum_logical_font_size_;
    }
    bool GetMockGestureTapHighlightsEnabled() const
    {
        return mock_gesture_tap_highlights_enabled_;
    }
    bool GetModalContextMenu() const
    {
        return modal_context_menu_;
    }
    bool GetMultiTargetTapNotificationEnabled() const
    {
        return multi_target_tap_notification_enabled_;
    }
    bool GetNavigateOnDragDrop() const
    {
        return navigate_on_drag_drop_;
    }
    NavigationControls GetNavigationControls() const
    {
        return navigation_controls_;
    }
    const String& GetNavigatorPlatformOverride() const
    {
        return navigator_platform_override_;
    }
    mojom::blink::OutputDeviceUpdateAbilityType GetOutputDeviceUpdateAbilityType() const
    {
        return output_device_update_ability_type_;
    }
    ParserScriptingFlagPolicy GetParserScriptingFlagPolicy() const
    {
        return parser_scripting_flag_policy_;
    }
    double GetPasswordEchoDurationInSeconds() const
    {
        return password_echo_duration_in_seconds_;
    }
    bool GetPasswordEchoEnabled() const
    {
        return password_echo_enabled_;
    }
    bool GetPictureInPictureEnabled() const
    {
        return picture_in_picture_enabled_;
    }
    bool GetPlaceRTLScrollbarsOnLeftSideInMainFrame() const
    {
        return place_rtl_scrollbars_on_left_side_in_main_frame_;
    }
    bool GetPluginsEnabled() const
    {
        return plugins_enabled_;
    }
    bool GetPreferHiddenVolumeControls() const
    {
        return prefer_hidden_volume_controls_;
    }
    mojom::blink::PreferredColorScheme GetPreferredColorScheme() const
    {
        return preferred_color_scheme_;
    }
    mojom::blink::PreferredContrast GetPreferredContrast() const
    {
        return preferred_contrast_;
    }
    mojom::blink::PreferredColorScheme GetPreferredRootScrollbarColorScheme() const
    {
        return preferred_root_scrollbar_color_scheme_;
    }
    bool GetPrefersDefaultScrollbarStyles() const
    {
        return prefers_default_scrollbar_styles_;
    }
    bool GetPrefersReducedMotion() const
    {
        return prefers_reduced_motion_;
    }
    bool GetPrefersReducedTransparency() const
    {
        return prefers_reduced_transparency_;
    }
    bool GetPresentationReceiver() const
    {
        return presentation_receiver_;
    }
    bool GetPresentationRequiresUserGesture() const
    {
        return presentation_requires_user_gesture_;
    }
    mojom::blink::HoverType GetPrimaryHoverType() const
    {
        return primary_hover_type_;
    }
    blink::mojom::PointerType GetPrimaryPointerType() const
    {
        return primary_pointer_type_;
    }
    float GetPrintingMaximumShrinkFactor() const
    {
        return printing_maximum_shrink_factor_;
    }
    bool GetReportScreenSizeInPhysicalPixelsQuirk() const
    {
        return report_screen_size_in_physical_pixels_quirk_;
    }
    bool GetRequireTransientActivationAndAuthorizationForSubAppsAPI() const
    {
        return require_transient_activation_and_authorization_for_sub_apps_api_;
    }
    bool GetRequireTransientActivationForGetDisplayMedia() const
    {
        return require_transient_activation_for_get_display_media_;
    }
    bool GetRequireTransientActivationForShowFileOrDirectoryPicker() const
    {
        return require_transient_activation_for_show_file_or_directory_picker_;
    }
    bool GetResizable() const
    {
        return resizable_;
    }
    bool GetRubberBandingOnCompositorThread() const
    {
        return rubber_banding_on_compositor_thread_;
    }
    bool GetScriptEnabled() const
    {
        return script_enabled_;
    }
    bool GetScrollAnimatorEnabled() const
    {
        return scroll_animator_enabled_;
    }
    bool GetSelectTrailingWhitespaceEnabled() const
    {
        return select_trailing_whitespace_enabled_;
    }
    bool GetSelectionClipboardBufferAvailable() const
    {
        return selection_clipboard_buffer_available_;
    }
    bool GetSelectionIncludesAltImageText() const
    {
        return selection_includes_alt_image_text_;
    }
    SelectionStrategy GetSelectionStrategy() const
    {
        return selection_strategy_;
    }
    bool GetShouldClearDocumentBackground() const
    {
        return should_clear_document_background_;
    }
    bool GetShouldPrintBackgrounds() const
    {
        return should_print_backgrounds_;
    }
    bool GetShouldProtectAgainstIpcFlooding() const
    {
        return should_protect_against_ipc_flooding_;
    }
    bool GetShouldReuseGlobalForUnownedMainFrame() const
    {
        return should_reuse_global_for_unowned_main_frame_;
    }
    bool GetShowContextMenuOnMouseUp() const
    {
        return show_context_menu_on_mouse_up_;
    }
    bool GetShrinksViewportContentToFit() const
    {
        return shrinks_viewport_content_to_fit_;
    }
    bool GetSmartInsertDeleteEnabled() const
    {
        return smart_insert_delete_enabled_;
    }
    bool GetSmoothScrollForFindEnabled() const
    {
        return smooth_scroll_for_find_enabled_;
    }
    bool GetSpatialNavigationEnabled() const
    {
        return spatial_navigation_enabled_;
    }
    bool GetSpellCheckEnabledByDefault() const
    {
        return spell_check_enabled_by_default_;
    }
    bool GetStrictMixedContentChecking() const
    {
        return strict_mixed_content_checking_;
    }
    bool GetStrictMixedContentCheckingForPlugin() const
    {
        return strict_mixed_content_checking_for_plugin_;
    }
    bool GetStrictPowerfulFeatureRestrictions() const
    {
        return strict_powerful_feature_restrictions_;
    }
    bool GetStrictlyBlockBlockableMixedContent() const
    {
        return strictly_block_blockable_mixed_content_;
    }
    bool GetSupportsMultipleWindows() const
    {
        return supports_multiple_windows_;
    }
    bool GetSyncXHRInDocumentsEnabled() const
    {
        return sync_xhr_in_documents_enabled_;
    }
    bool GetTargetBlankImpliesNoOpenerEnabledWillBeRemoved() const
    {
        return target_blank_implies_no_opener_enabled_will_be_removed_;
    }
    bool GetTextAreasAreResizable() const
    {
        return text_areas_are_resizable_;
    }
    bool GetTextAutosizingEnabled() const
    {
        return text_autosizing_enabled_;
    }
    gfx::Size GetTextAutosizingWindowSizeOverride() const
    {
        return text_autosizing_window_size_override_;
    }
    const String& GetTextTrackBackgroundColor() const
    {
        return text_track_background_color_;
    }
    const String& GetTextTrackFontFamily() const
    {
        return text_track_font_family_;
    }
    const String& GetTextTrackFontStyle() const
    {
        return text_track_font_style_;
    }
    const String& GetTextTrackFontVariant() const
    {
        return text_track_font_variant_;
    }
    TextTrackKindUserPreference GetTextTrackKindUserPreference() const
    {
        return text_track_kind_user_preference_;
    }
    double GetTextTrackMarginPercentage() const
    {
        return text_track_margin_percentage_;
    }
    const String& GetTextTrackTextColor() const
    {
        return text_track_text_color_;
    }
    const String& GetTextTrackTextShadow() const
    {
        return text_track_text_shadow_;
    }
    const String& GetTextTrackTextSize() const
    {
        return text_track_text_size_;
    }
    const String& GetTextTrackWindowColor() const
    {
        return text_track_window_color_;
    }
    const String& GetTextTrackWindowRadius() const
    {
        return text_track_window_radius_;
    }
    bool GetTouchDragDropEnabled() const
    {
        return touch_drag_drop_enabled_;
    }
    bool GetTouchDragEndContextMenu() const
    {
        return touch_drag_end_context_menu_;
    }
    bool GetTouchEditingEnabled() const
    {
        return touch_editing_enabled_;
    }
    bool GetUseAXMenuList() const
    {
        return use_ax_menu_list_;
    }
    bool GetUseWideViewport() const
    {
        return use_wide_viewport_;
    }
    mojom::blink::V8CacheOptions GetV8CacheOptions() const
    {
        return v8_cache_options_;
    }
    int GetValidationMessageTimerMagnification() const
    {
        return validation_message_timer_magnification_;
    }
    bool GetViewportEnabled() const
    {
        return viewport_enabled_;
    }
    bool GetViewportMetaEnabled() const
    {
        return viewport_meta_enabled_;
    }
    bool GetViewportMetaMergeContentQuirk() const
    {
        return viewport_meta_merge_content_quirk_;
    }
    bool GetViewportMetaZeroValuesQuirk() const
    {
        return viewport_meta_zero_values_quirk_;
    }
    mojom::blink::ViewportStyle GetViewportStyle() const
    {
        return viewport_style_;
    }
    const String& GetWebAppScope() const
    {
        return web_app_scope_;
    }
    bool GetWebGL1Enabled() const
    {
        return web_gl_1_enabled_;
    }
    bool GetWebGL2Enabled() const
    {
        return webgl2_enabled_;
    }
    bool GetWebGLErrorsToConsoleEnabled() const
    {
        return web_gl_errors_to_console_enabled_;
    }
    bool GetWebSecurityEnabled() const
    {
        return web_security_enabled_;
    }
    bool GetWideViewportQuirkEnabled() const
    {
        return wide_viewport_quirk_enabled_;
    }
    ui::mojom::blink::WindowShowState GetWindowShowState() const
    {
        return window_show_state_;
    }

    void SetDOMPasteAllowed(bool dom_paste_allowed);
    void SetDontSendKeyEventsToJavascript(bool dont_send_key_events_to_javascript);
    void SetHighlightAds(bool highlight_ads);
    void SetLCDTextPreference(LCDTextPreference lcd_text_preference);
    void SetNetworkQuietTimeout(double network_quiet_timeout);
    void SetWebXRImmersiveArAllowed(bool web_xr_immersive_ar_allowed);
    void SetAccelerated2dCanvasMSAASampleCount(int accelerated_2d_canvas_msaa_sample_count);
    void SetAcceleratedCompositingEnabled(bool accelerated_compositing_enabled);
    void SetAccessibilityAlwaysShowFocus(bool accessibility_always_show_focus);
    void SetAccessibilityFontScaleFactor(double accessibility_font_scale_factor);
    void SetAccessibilityFontWeightAdjustment(int accessibility_font_weight_adjustment);
    void SetAccessibilityIncludeSvgGElement(bool accessibility_include_svg_g_element);
    void SetAccessibilityPasswordValuesEnabled(bool accessibility_password_values_enabled);
    void SetAccessibilityTextSizeContrastFactor(int accessibility_text_size_contrast_factor);
    void SetAllowCustomScrollbarInMainFrame(bool allow_custom_scrollbar_in_main_frame);
    void SetAllowFileAccessFromFileURLs(bool allow_file_access_from_file_urls);
    void SetAllowGeolocationOnInsecureOrigins(bool allow_geolocation_on_insecure_origins);
    void SetAllowNonEmptyNavigatorPlugins(bool allow_non_empty_navigator_plugins);
    void SetAllowRunningOfInsecureContent(bool allow_running_of_insecure_content);
    void SetAllowScriptsToCloseWindows(bool allow_scripts_to_close_windows);
    void SetAllowUniversalAccessFromFileURLs(bool allow_universal_access_from_file_urls);
    void SetAlwaysShowContextMenuOnTouch(bool always_show_context_menu_on_touch);
    void SetAntialiased2dCanvasEnabled(bool antialiased_2d_canvas_enabled);
    void SetAntialiasedClips2dCanvasEnabled(bool antialiased_clips_2d_canvas_enabled);
    void SetAriaModalPrunesAXTree(bool aria_modal_prunes_ax_tree);
    void SetAutoplayPolicy(AutoplayPolicy::Type autoplay_policy);
    void SetAvailableHoverTypes(int available_hover_types);
    void SetAvailablePointerTypes(int available_pointer_types);
    void SetBarrelButtonForDragEnabled(bool barrel_button_for_drag_enabled);
    void SetBypassCSP(bool bypass_csp);
    void SetCaretBrowsingEnabled(bool caret_browsing_enabled);
    void SetCookieEnabled(bool cookie_enabled);
    void SetDefaultFixedFontSize(int default_fixed_font_size);
    void SetDefaultFontSize(int default_font_size);
    void SetDefaultTextEncodingName(const String& default_text_encoding_name);
    void SetDefaultVideoPosterURL(const String& default_video_poster_url);
    void SetDeviceScaleAdjustment(double device_scale_adjustment);
    void SetDisableReadingFromCanvas(bool disable_reading_from_canvas);
    void SetDisallowFetchForDocWrittenScriptsInMainFrame(bool disallow_fetch_for_doc_written_scripts_in_main_frame);
    void SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g);
    void SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(bool disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections);
    void SetDisplayModeOverride(blink::mojom::DisplayMode display_mode_override);
    void SetDNSPrefetchingEnabled(bool dns_prefetching_enabled);
    void SetDoHtmlPreloadScanning(bool do_html_preload_scanning);
    void SetDoNotUpdateSelectionOnMutatingSelectionRange(bool do_not_update_selection_on_mutating_selection_range);
    void SetDownloadableBinaryFontsEnabled(bool downloadable_binary_fonts_enabled);
    void SetDynamicSafeAreaInsetsEnabled(bool dynamic_safe_area_insets_enabled);
    void SetEditingBehaviorType(mojom::EditingBehavior editing_behavior_type);
    void SetEmbeddedMediaExperienceEnabled(bool embedded_media_experience_enabled);
    void SetForceAndroidOverlayScrollbar(bool force_android_overlay_scrollbar);
    void SetForceDarkModeEnabled(bool force_dark_mode_enabled);
    void SetForceMainWorldInitialization(bool force_main_world_initialization);
    void SetForceTouchEventFeatureDetectionForInspector(bool force_touch_event_feature_detection_for_inspector);
    void SetForceZeroLayoutHeight(bool force_zero_layout_height);
    void SetFullscreenSupported(bool fullscreen_supported);
    void SetHideDownloadUI(bool hide_download_ui);
    void SetHideScrollbars(bool hide_scrollbars);
    void SetHyperlinkAuditingEnabled(bool hyperlink_auditing_enabled);
    void SetIgnoreMainFrameOverflowHiddenQuirk(bool ignore_main_frame_overflow_hidden_quirk);
    void SetImageAnimationPolicy(mojom::blink::ImageAnimationPolicy image_animation_policy);
    void SetImagesEnabled(bool images_enabled);
    void SetImmersiveModeEnabled(bool immersive_mode_enabled);
    void SetInForcedColors(bool in_forced_colors);
    void SetInvertedColors(bool inverted_colors);
    void SetIsForcedColorsDisabled(bool is_forced_colors_disabled);
    void SetJavaScriptCanAccessClipboard(bool java_script_can_access_clipboard);
    void SetLazyLoadEnabled(bool lazy_load_enabled);
    void SetLazyLoadingFrameMarginPx2G(int lazy_loading_frame_margin_px_2_g);
    void SetLazyLoadingFrameMarginPx3G(int lazy_loading_frame_margin_px_3_g);
    void SetLazyLoadingFrameMarginPx4G(int lazy_loading_frame_margin_px_4_g);
    void SetLazyLoadingFrameMarginPxOffline(int lazy_loading_frame_margin_px_offline);
    void SetLazyLoadingFrameMarginPxSlow2G(int lazy_loading_frame_margin_px_slow_2_g);
    void SetLazyLoadingFrameMarginPxUnknown(int lazy_loading_frame_margin_px_unknown);
    void SetLazyLoadingImageMarginPx2G(int lazy_loading_image_margin_px_2_g);
    void SetLazyLoadingImageMarginPx3G(int lazy_loading_image_margin_px_3_g);
    void SetLazyLoadingImageMarginPx4G(int lazy_loading_image_margin_px_4_g);
    void SetLazyLoadingImageMarginPxOffline(int lazy_loading_image_margin_px_offline);
    void SetLazyLoadingImageMarginPxSlow2G(int lazy_loading_image_margin_px_slow_2_g);
    void SetLazyLoadingImageMarginPxUnknown(int lazy_loading_image_margin_px_unknown);
    void SetLoadWithOverviewMode(bool load_with_overview_mode);
    void SetLoadsImagesAutomatically(bool loads_images_automatically);
    void SetLocalStorageEnabled(bool local_storage_enabled);
    void SetLogDnsPrefetchAndPreconnect(bool log_dns_prefetch_and_preconnect);
    void SetLogPreload(bool log_preload);
    void SetLowPriorityIframesThreshold(WebEffectiveConnectionType low_priority_iframes_threshold);
    void SetMainFrameClipsContent(bool main_frame_clips_content);
    void SetMainFrameResizesAreOrientationChanges(bool main_frame_resizes_are_orientation_changes);
    void SetMaxTouchPoints(int max_touch_points);
    void SetMediaControlsEnabled(bool media_controls_enabled);
    void SetMediaTypeOverride(const String& media_type_override);
    void SetMinimumFontSize(int minimum_font_size);
    void SetMinimumLogicalFontSize(int minimum_logical_font_size);
    void SetMockGestureTapHighlightsEnabled(bool mock_gesture_tap_highlights_enabled);
    void SetModalContextMenu(bool modal_context_menu);
    void SetMultiTargetTapNotificationEnabled(bool multi_target_tap_notification_enabled);
    void SetNavigateOnDragDrop(bool navigate_on_drag_drop);
    void SetNavigationControls(NavigationControls navigation_controls);
    void SetNavigatorPlatformOverride(const String& navigator_platform_override);
    void SetOutputDeviceUpdateAbilityType(mojom::blink::OutputDeviceUpdateAbilityType output_device_update_ability_type);
    void SetParserScriptingFlagPolicy(ParserScriptingFlagPolicy parser_scripting_flag_policy);
    void SetPasswordEchoDurationInSeconds(double password_echo_duration_in_seconds);
    void SetPasswordEchoEnabled(bool password_echo_enabled);
    void SetPictureInPictureEnabled(bool picture_in_picture_enabled);
    void SetPlaceRTLScrollbarsOnLeftSideInMainFrame(bool place_rtl_scrollbars_on_left_side_in_main_frame);
    void SetPluginsEnabled(bool plugins_enabled);
    void SetPreferHiddenVolumeControls(bool prefer_hidden_volume_controls);
    void SetPreferredColorScheme(mojom::blink::PreferredColorScheme preferred_color_scheme);
    void SetPreferredContrast(mojom::blink::PreferredContrast preferred_contrast);
    void SetPreferredRootScrollbarColorScheme(mojom::blink::PreferredColorScheme preferred_root_scrollbar_color_scheme);
    void SetPrefersDefaultScrollbarStyles(bool prefers_default_scrollbar_styles);
    void SetPrefersReducedMotion(bool prefers_reduced_motion);
    void SetPrefersReducedTransparency(bool prefers_reduced_transparency);
    void SetPresentationReceiver(bool presentation_receiver);
    void SetPresentationRequiresUserGesture(bool presentation_requires_user_gesture);
    void SetPrimaryHoverType(mojom::blink::HoverType primary_hover_type);
    void SetPrimaryPointerType(blink::mojom::PointerType primary_pointer_type);
    void SetPrintingMaximumShrinkFactor(float printing_maximum_shrink_factor);
    void SetReportScreenSizeInPhysicalPixelsQuirk(bool report_screen_size_in_physical_pixels_quirk);
    void SetRequireTransientActivationAndAuthorizationForSubAppsAPI(bool require_transient_activation_and_authorization_for_sub_apps_api);
    void SetRequireTransientActivationForGetDisplayMedia(bool require_transient_activation_for_get_display_media);
    void SetRequireTransientActivationForShowFileOrDirectoryPicker(bool require_transient_activation_for_show_file_or_directory_picker);
    void SetResizable(bool resizable);
    void SetRubberBandingOnCompositorThread(bool rubber_banding_on_compositor_thread);
    void SetScriptEnabled(bool script_enabled);
    void SetScrollAnimatorEnabled(bool scroll_animator_enabled);
    void SetSelectTrailingWhitespaceEnabled(bool select_trailing_whitespace_enabled);
    void SetSelectionClipboardBufferAvailable(bool selection_clipboard_buffer_available);
    void SetSelectionIncludesAltImageText(bool selection_includes_alt_image_text);
    void SetSelectionStrategy(SelectionStrategy selection_strategy);
    void SetShouldClearDocumentBackground(bool should_clear_document_background);
    void SetShouldPrintBackgrounds(bool should_print_backgrounds);
    void SetShouldProtectAgainstIpcFlooding(bool should_protect_against_ipc_flooding);
    void SetShouldReuseGlobalForUnownedMainFrame(bool should_reuse_global_for_unowned_main_frame);
    void SetShowContextMenuOnMouseUp(bool show_context_menu_on_mouse_up);
    void SetShrinksViewportContentToFit(bool shrinks_viewport_content_to_fit);
    void SetSmartInsertDeleteEnabled(bool smart_insert_delete_enabled);
    void SetSmoothScrollForFindEnabled(bool smooth_scroll_for_find_enabled);
    void SetSpatialNavigationEnabled(bool spatial_navigation_enabled);
    void SetSpellCheckEnabledByDefault(bool spell_check_enabled_by_default);
    void SetStrictMixedContentChecking(bool strict_mixed_content_checking);
    void SetStrictMixedContentCheckingForPlugin(bool strict_mixed_content_checking_for_plugin);
    void SetStrictPowerfulFeatureRestrictions(bool strict_powerful_feature_restrictions);
    void SetStrictlyBlockBlockableMixedContent(bool strictly_block_blockable_mixed_content);
    void SetSupportsMultipleWindows(bool supports_multiple_windows);
    void SetSyncXHRInDocumentsEnabled(bool sync_xhr_in_documents_enabled);
    void SetTargetBlankImpliesNoOpenerEnabledWillBeRemoved(bool target_blank_implies_no_opener_enabled_will_be_removed);
    void SetTextAreasAreResizable(bool text_areas_are_resizable);
    void SetTextAutosizingEnabled(bool text_autosizing_enabled);
    void SetTextAutosizingWindowSizeOverride(gfx::Size text_autosizing_window_size_override);
    void SetTextTrackBackgroundColor(const String& text_track_background_color);
    void SetTextTrackFontFamily(const String& text_track_font_family);
    void SetTextTrackFontStyle(const String& text_track_font_style);
    void SetTextTrackFontVariant(const String& text_track_font_variant);
    void SetTextTrackKindUserPreference(TextTrackKindUserPreference text_track_kind_user_preference);
    void SetTextTrackMarginPercentage(double text_track_margin_percentage);
    void SetTextTrackTextColor(const String& text_track_text_color);
    void SetTextTrackTextShadow(const String& text_track_text_shadow);
    void SetTextTrackTextSize(const String& text_track_text_size);
    void SetTextTrackWindowColor(const String& text_track_window_color);
    void SetTextTrackWindowRadius(const String& text_track_window_radius);
    void SetTouchDragDropEnabled(bool touch_drag_drop_enabled);
    void SetTouchDragEndContextMenu(bool touch_drag_end_context_menu);
    void SetTouchEditingEnabled(bool touch_editing_enabled);
    void SetUseAXMenuList(bool use_ax_menu_list);
    void SetUseWideViewport(bool use_wide_viewport);
    void SetV8CacheOptions(mojom::blink::V8CacheOptions v8_cache_options);
    void SetValidationMessageTimerMagnification(int validation_message_timer_magnification);
    void SetViewportEnabled(bool viewport_enabled);
    void SetViewportMetaEnabled(bool viewport_meta_enabled);
    void SetViewportMetaMergeContentQuirk(bool viewport_meta_merge_content_quirk);
    void SetViewportMetaZeroValuesQuirk(bool viewport_meta_zero_values_quirk);
    void SetViewportStyle(mojom::blink::ViewportStyle viewport_style);
    void SetWebAppScope(const String& web_app_scope);
    void SetWebGL1Enabled(bool web_gl_1_enabled);
    void SetWebGL2Enabled(bool webgl2_enabled);
    void SetWebGLErrorsToConsoleEnabled(bool web_gl_errors_to_console_enabled);
    void SetWebSecurityEnabled(bool web_security_enabled);
    void SetWideViewportQuirkEnabled(bool wide_viewport_quirk_enabled);
    void SetWindowShowState(ui::mojom::blink::WindowShowState window_show_state);

    void SetFromStrings(const String& name, const String& value);
    void SetDelegate(SettingsDelegate* delegate);

protected:
    SettingsBase();

    void Invalidate(SettingsDelegate::ChangeType);

private:
    SettingsDelegate* delegate_;

    LCDTextPreference lcd_text_preference_;
    double network_quiet_timeout_;
    int accelerated_2d_canvas_msaa_sample_count_;
    double accessibility_font_scale_factor_;
    int accessibility_font_weight_adjustment_;
    int accessibility_text_size_contrast_factor_;
    AutoplayPolicy::Type autoplay_policy_;
    int available_hover_types_;
    int available_pointer_types_;
    int default_fixed_font_size_;
    int default_font_size_;
    String default_text_encoding_name_;
    String default_video_poster_url_;
    double device_scale_adjustment_;
    blink::mojom::DisplayMode display_mode_override_;
    mojom::EditingBehavior editing_behavior_type_;
    mojom::blink::ImageAnimationPolicy image_animation_policy_;
    int lazy_loading_frame_margin_px_2_g_;
    int lazy_loading_frame_margin_px_3_g_;
    int lazy_loading_frame_margin_px_4_g_;
    int lazy_loading_frame_margin_px_offline_;
    int lazy_loading_frame_margin_px_slow_2_g_;
    int lazy_loading_frame_margin_px_unknown_;
    int lazy_loading_image_margin_px_2_g_;
    int lazy_loading_image_margin_px_3_g_;
    int lazy_loading_image_margin_px_4_g_;
    int lazy_loading_image_margin_px_offline_;
    int lazy_loading_image_margin_px_slow_2_g_;
    int lazy_loading_image_margin_px_unknown_;
    WebEffectiveConnectionType low_priority_iframes_threshold_;
    int max_touch_points_;
    String media_type_override_;
    int minimum_font_size_;
    int minimum_logical_font_size_;
    NavigationControls navigation_controls_;
    String navigator_platform_override_;
    mojom::blink::OutputDeviceUpdateAbilityType output_device_update_ability_type_;
    ParserScriptingFlagPolicy parser_scripting_flag_policy_;
    double password_echo_duration_in_seconds_;
    mojom::blink::PreferredColorScheme preferred_color_scheme_;
    mojom::blink::PreferredContrast preferred_contrast_;
    mojom::blink::PreferredColorScheme preferred_root_scrollbar_color_scheme_;
    mojom::blink::HoverType primary_hover_type_;
    blink::mojom::PointerType primary_pointer_type_;
    float printing_maximum_shrink_factor_;
    SelectionStrategy selection_strategy_;
    gfx::Size text_autosizing_window_size_override_;
    String text_track_background_color_;
    String text_track_font_family_;
    String text_track_font_style_;
    String text_track_font_variant_;
    TextTrackKindUserPreference text_track_kind_user_preference_;
    double text_track_margin_percentage_;
    String text_track_text_color_;
    String text_track_text_shadow_;
    String text_track_text_size_;
    String text_track_window_color_;
    String text_track_window_radius_;
    mojom::blink::V8CacheOptions v8_cache_options_;
    int validation_message_timer_magnification_;
    mojom::blink::ViewportStyle viewport_style_;
    String web_app_scope_;
    ui::mojom::blink::WindowShowState window_show_state_;
    bool dom_paste_allowed_ : 1;
    bool dont_send_key_events_to_javascript_ : 1;
    bool highlight_ads_ : 1;
    bool web_xr_immersive_ar_allowed_ : 1;
    bool accelerated_compositing_enabled_ : 1;
    bool accessibility_always_show_focus_ : 1;
    bool accessibility_include_svg_g_element_ : 1;
    bool accessibility_password_values_enabled_ : 1;
    bool allow_custom_scrollbar_in_main_frame_ : 1;
    bool allow_file_access_from_file_urls_ : 1;
    bool allow_geolocation_on_insecure_origins_ : 1;
    bool allow_non_empty_navigator_plugins_ : 1;
    bool allow_running_of_insecure_content_ : 1;
    bool allow_scripts_to_close_windows_ : 1;
    bool allow_universal_access_from_file_urls_ : 1;
    bool always_show_context_menu_on_touch_ : 1;
    bool antialiased_2d_canvas_enabled_ : 1;
    bool antialiased_clips_2d_canvas_enabled_ : 1;
    bool aria_modal_prunes_ax_tree_ : 1;
    bool barrel_button_for_drag_enabled_ : 1;
    bool bypass_csp_ : 1;
    bool caret_browsing_enabled_ : 1;
    bool cookie_enabled_ : 1;
    bool disable_reading_from_canvas_ : 1;
    bool disallow_fetch_for_doc_written_scripts_in_main_frame_ : 1;
    bool disallow_fetch_for_doc_written_scripts_in_main_frame_if_effectively_2_g_ : 1;
    bool disallow_fetch_for_doc_written_scripts_in_main_frame_on_slow_connections_ : 1;
    bool dns_prefetching_enabled_ : 1;
    bool do_html_preload_scanning_ : 1;
    bool do_not_update_selection_on_mutating_selection_range_ : 1;
    bool downloadable_binary_fonts_enabled_ : 1;
    bool dynamic_safe_area_insets_enabled_ : 1;
    bool embedded_media_experience_enabled_ : 1;
    bool force_android_overlay_scrollbar_ : 1;
    bool force_dark_mode_enabled_ : 1;
    bool force_main_world_initialization_ : 1;
    bool force_touch_event_feature_detection_for_inspector_ : 1;
    bool force_zero_layout_height_ : 1;
    bool fullscreen_supported_ : 1;
    bool hide_download_ui_ : 1;
    bool hide_scrollbars_ : 1;
    bool hyperlink_auditing_enabled_ : 1;
    bool ignore_main_frame_overflow_hidden_quirk_ : 1;
    bool images_enabled_ : 1;
    bool immersive_mode_enabled_ : 1;
    bool in_forced_colors_ : 1;
    bool inverted_colors_ : 1;
    bool is_forced_colors_disabled_ : 1;
    bool java_script_can_access_clipboard_ : 1;
    bool lazy_load_enabled_ : 1;
    bool load_with_overview_mode_ : 1;
    bool loads_images_automatically_ : 1;
    bool local_storage_enabled_ : 1;
    bool log_dns_prefetch_and_preconnect_ : 1;
    bool log_preload_ : 1;
    bool main_frame_clips_content_ : 1;
    bool main_frame_resizes_are_orientation_changes_ : 1;
    bool media_controls_enabled_ : 1;
    bool mock_gesture_tap_highlights_enabled_ : 1;
    bool modal_context_menu_ : 1;
    bool multi_target_tap_notification_enabled_ : 1;
    bool navigate_on_drag_drop_ : 1;
    bool password_echo_enabled_ : 1;
    bool picture_in_picture_enabled_ : 1;
    bool place_rtl_scrollbars_on_left_side_in_main_frame_ : 1;
    bool plugins_enabled_ : 1;
    bool prefer_hidden_volume_controls_ : 1;
    bool prefers_default_scrollbar_styles_ : 1;
    bool prefers_reduced_motion_ : 1;
    bool prefers_reduced_transparency_ : 1;
    bool presentation_receiver_ : 1;
    bool presentation_requires_user_gesture_ : 1;
    bool report_screen_size_in_physical_pixels_quirk_ : 1;
    bool require_transient_activation_and_authorization_for_sub_apps_api_ : 1;
    bool require_transient_activation_for_get_display_media_ : 1;
    bool require_transient_activation_for_show_file_or_directory_picker_ : 1;
    bool resizable_ : 1;
    bool rubber_banding_on_compositor_thread_ : 1;
    bool script_enabled_ : 1;
    bool scroll_animator_enabled_ : 1;
    bool select_trailing_whitespace_enabled_ : 1;
    bool selection_clipboard_buffer_available_ : 1;
    bool selection_includes_alt_image_text_ : 1;
    bool should_clear_document_background_ : 1;
    bool should_print_backgrounds_ : 1;
    bool should_protect_against_ipc_flooding_ : 1;
    bool should_reuse_global_for_unowned_main_frame_ : 1;
    bool show_context_menu_on_mouse_up_ : 1;
    bool shrinks_viewport_content_to_fit_ : 1;
    bool smart_insert_delete_enabled_ : 1;
    bool smooth_scroll_for_find_enabled_ : 1;
    bool spatial_navigation_enabled_ : 1;
    bool spell_check_enabled_by_default_ : 1;
    bool strict_mixed_content_checking_ : 1;
    bool strict_mixed_content_checking_for_plugin_ : 1;
    bool strict_powerful_feature_restrictions_ : 1;
    bool strictly_block_blockable_mixed_content_ : 1;
    bool supports_multiple_windows_ : 1;
    bool sync_xhr_in_documents_enabled_ : 1;
    bool target_blank_implies_no_opener_enabled_will_be_removed_ : 1;
    bool text_areas_are_resizable_ : 1;
    bool text_autosizing_enabled_ : 1;
    bool touch_drag_drop_enabled_ : 1;
    bool touch_drag_end_context_menu_ : 1;
    bool touch_editing_enabled_ : 1;
    bool use_ax_menu_list_ : 1;
    bool use_wide_viewport_ : 1;
    bool viewport_enabled_ : 1;
    bool viewport_meta_enabled_ : 1;
    bool viewport_meta_merge_content_quirk_ : 1;
    bool viewport_meta_zero_values_quirk_ : 1;
    bool web_gl_1_enabled_ : 1;
    bool webgl2_enabled_ : 1;
    bool web_gl_errors_to_console_enabled_ : 1;
    bool web_security_enabled_ : 1;
    bool wide_viewport_quirk_enabled_ : 1;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_SETTINGS_BASE_H_
