// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/internal_settings_generated.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/frame/settings.json5

#include "internal_settings_generated.h"

#include "third_party/blink/renderer/core/page/page.h"
#include "third_party/blink/renderer/core/frame/settings.h"

namespace blink {

InternalSettingsGenerated::InternalSettingsGenerated(Page& page)
    : InternalSettingsPageSupplementBase(page)
{
    backup_.SetDOMPasteAllowed(GetSettings().GetDOMPasteAllowed());
    backup_.SetDontSendKeyEventsToJavascript(GetSettings().GetDontSendKeyEventsToJavascript());
    backup_.SetHighlightAds(GetSettings().GetHighlightAds());
    backup_.SetLCDTextPreference(GetSettings().GetLCDTextPreference());
    backup_.SetNetworkQuietTimeout(GetSettings().GetNetworkQuietTimeout());
    backup_.SetWebXRImmersiveArAllowed(GetSettings().GetWebXRImmersiveArAllowed());
    backup_.SetAccelerated2dCanvasMSAASampleCount(GetSettings().GetAccelerated2dCanvasMSAASampleCount());
    backup_.SetAcceleratedCompositingEnabled(GetSettings().GetAcceleratedCompositingEnabled());
    backup_.SetAccessibilityAlwaysShowFocus(GetSettings().GetAccessibilityAlwaysShowFocus());
    backup_.SetAccessibilityFontScaleFactor(GetSettings().GetAccessibilityFontScaleFactor());
    backup_.SetAccessibilityFontWeightAdjustment(GetSettings().GetAccessibilityFontWeightAdjustment());
    backup_.SetAccessibilityIncludeSvgGElement(GetSettings().GetAccessibilityIncludeSvgGElement());
    backup_.SetAccessibilityPasswordValuesEnabled(GetSettings().GetAccessibilityPasswordValuesEnabled());
    backup_.SetAccessibilityTextSizeContrastFactor(GetSettings().GetAccessibilityTextSizeContrastFactor());
    backup_.SetAllowCustomScrollbarInMainFrame(GetSettings().GetAllowCustomScrollbarInMainFrame());
    backup_.SetAllowFileAccessFromFileURLs(GetSettings().GetAllowFileAccessFromFileURLs());
    backup_.SetAllowGeolocationOnInsecureOrigins(GetSettings().GetAllowGeolocationOnInsecureOrigins());
    backup_.SetAllowNonEmptyNavigatorPlugins(GetSettings().GetAllowNonEmptyNavigatorPlugins());
    backup_.SetAllowRunningOfInsecureContent(GetSettings().GetAllowRunningOfInsecureContent());
    backup_.SetAllowScriptsToCloseWindows(GetSettings().GetAllowScriptsToCloseWindows());
    backup_.SetAllowUniversalAccessFromFileURLs(GetSettings().GetAllowUniversalAccessFromFileURLs());
    backup_.SetAlwaysShowContextMenuOnTouch(GetSettings().GetAlwaysShowContextMenuOnTouch());
    backup_.SetAntialiased2dCanvasEnabled(GetSettings().GetAntialiased2dCanvasEnabled());
    backup_.SetAntialiasedClips2dCanvasEnabled(GetSettings().GetAntialiasedClips2dCanvasEnabled());
    backup_.SetAriaModalPrunesAXTree(GetSettings().GetAriaModalPrunesAXTree());
    backup_.SetAutoplayPolicy(GetSettings().GetAutoplayPolicy());
    backup_.SetAvailableHoverTypes(GetSettings().GetAvailableHoverTypes());
    backup_.SetAvailablePointerTypes(GetSettings().GetAvailablePointerTypes());
    backup_.SetBarrelButtonForDragEnabled(GetSettings().GetBarrelButtonForDragEnabled());
    backup_.SetBypassCSP(GetSettings().GetBypassCSP());
    backup_.SetCaretBrowsingEnabled(GetSettings().GetCaretBrowsingEnabled());
    backup_.SetCookieEnabled(GetSettings().GetCookieEnabled());
    backup_.SetDefaultFixedFontSize(GetSettings().GetDefaultFixedFontSize());
    backup_.SetDefaultFontSize(GetSettings().GetDefaultFontSize());
    backup_.SetDefaultTextEncodingName(GetSettings().GetDefaultTextEncodingName());
    backup_.SetDefaultVideoPosterURL(GetSettings().GetDefaultVideoPosterURL());
    backup_.SetDeviceScaleAdjustment(GetSettings().GetDeviceScaleAdjustment());
    backup_.SetDisableReadingFromCanvas(GetSettings().GetDisableReadingFromCanvas());
    backup_.SetDisallowFetchForDocWrittenScriptsInMainFrame(GetSettings().GetDisallowFetchForDocWrittenScriptsInMainFrame());
    backup_.SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(GetSettings().GetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G());
    backup_.SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(GetSettings().GetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections());
    backup_.SetDisplayModeOverride(GetSettings().GetDisplayModeOverride());
    backup_.SetDNSPrefetchingEnabled(GetSettings().GetDNSPrefetchingEnabled());
    backup_.SetDoHtmlPreloadScanning(GetSettings().GetDoHtmlPreloadScanning());
    backup_.SetDoNotUpdateSelectionOnMutatingSelectionRange(GetSettings().GetDoNotUpdateSelectionOnMutatingSelectionRange());
    backup_.SetDownloadableBinaryFontsEnabled(GetSettings().GetDownloadableBinaryFontsEnabled());
    backup_.SetDynamicSafeAreaInsetsEnabled(GetSettings().GetDynamicSafeAreaInsetsEnabled());
    backup_.SetEditingBehaviorType(GetSettings().GetEditingBehaviorType());
    backup_.SetEmbeddedMediaExperienceEnabled(GetSettings().GetEmbeddedMediaExperienceEnabled());
    backup_.SetForceAndroidOverlayScrollbar(GetSettings().GetForceAndroidOverlayScrollbar());
    backup_.SetForceDarkModeEnabled(GetSettings().GetForceDarkModeEnabled());
    backup_.SetForceMainWorldInitialization(GetSettings().GetForceMainWorldInitialization());
    backup_.SetForceTouchEventFeatureDetectionForInspector(GetSettings().GetForceTouchEventFeatureDetectionForInspector());
    backup_.SetForceZeroLayoutHeight(GetSettings().GetForceZeroLayoutHeight());
    backup_.SetFullscreenSupported(GetSettings().GetFullscreenSupported());
    backup_.SetHideDownloadUI(GetSettings().GetHideDownloadUI());
    backup_.SetHideScrollbars(GetSettings().GetHideScrollbars());
    backup_.SetHyperlinkAuditingEnabled(GetSettings().GetHyperlinkAuditingEnabled());
    backup_.SetIgnoreMainFrameOverflowHiddenQuirk(GetSettings().GetIgnoreMainFrameOverflowHiddenQuirk());
    backup_.SetImageAnimationPolicy(GetSettings().GetImageAnimationPolicy());
    backup_.SetImagesEnabled(GetSettings().GetImagesEnabled());
    backup_.SetImmersiveModeEnabled(GetSettings().GetImmersiveModeEnabled());
    backup_.SetInForcedColors(GetSettings().GetInForcedColors());
    backup_.SetInvertedColors(GetSettings().GetInvertedColors());
    backup_.SetIsForcedColorsDisabled(GetSettings().GetIsForcedColorsDisabled());
    backup_.SetJavaScriptCanAccessClipboard(GetSettings().GetJavaScriptCanAccessClipboard());
    backup_.SetLazyLoadEnabled(GetSettings().GetLazyLoadEnabled());
    backup_.SetLazyLoadingFrameMarginPx2G(GetSettings().GetLazyLoadingFrameMarginPx2G());
    backup_.SetLazyLoadingFrameMarginPx3G(GetSettings().GetLazyLoadingFrameMarginPx3G());
    backup_.SetLazyLoadingFrameMarginPx4G(GetSettings().GetLazyLoadingFrameMarginPx4G());
    backup_.SetLazyLoadingFrameMarginPxOffline(GetSettings().GetLazyLoadingFrameMarginPxOffline());
    backup_.SetLazyLoadingFrameMarginPxSlow2G(GetSettings().GetLazyLoadingFrameMarginPxSlow2G());
    backup_.SetLazyLoadingFrameMarginPxUnknown(GetSettings().GetLazyLoadingFrameMarginPxUnknown());
    backup_.SetLazyLoadingImageMarginPx2G(GetSettings().GetLazyLoadingImageMarginPx2G());
    backup_.SetLazyLoadingImageMarginPx3G(GetSettings().GetLazyLoadingImageMarginPx3G());
    backup_.SetLazyLoadingImageMarginPx4G(GetSettings().GetLazyLoadingImageMarginPx4G());
    backup_.SetLazyLoadingImageMarginPxOffline(GetSettings().GetLazyLoadingImageMarginPxOffline());
    backup_.SetLazyLoadingImageMarginPxSlow2G(GetSettings().GetLazyLoadingImageMarginPxSlow2G());
    backup_.SetLazyLoadingImageMarginPxUnknown(GetSettings().GetLazyLoadingImageMarginPxUnknown());
    backup_.SetLoadWithOverviewMode(GetSettings().GetLoadWithOverviewMode());
    backup_.SetLoadsImagesAutomatically(GetSettings().GetLoadsImagesAutomatically());
    backup_.SetLocalStorageEnabled(GetSettings().GetLocalStorageEnabled());
    backup_.SetLogDnsPrefetchAndPreconnect(GetSettings().GetLogDnsPrefetchAndPreconnect());
    backup_.SetLogPreload(GetSettings().GetLogPreload());
    backup_.SetLowPriorityIframesThreshold(GetSettings().GetLowPriorityIframesThreshold());
    backup_.SetMainFrameClipsContent(GetSettings().GetMainFrameClipsContent());
    backup_.SetMainFrameResizesAreOrientationChanges(GetSettings().GetMainFrameResizesAreOrientationChanges());
    backup_.SetMaxTouchPoints(GetSettings().GetMaxTouchPoints());
    backup_.SetMediaControlsEnabled(GetSettings().GetMediaControlsEnabled());
    backup_.SetMediaTypeOverride(GetSettings().GetMediaTypeOverride());
    backup_.SetMinimumFontSize(GetSettings().GetMinimumFontSize());
    backup_.SetMinimumLogicalFontSize(GetSettings().GetMinimumLogicalFontSize());
    backup_.SetMockGestureTapHighlightsEnabled(GetSettings().GetMockGestureTapHighlightsEnabled());
    backup_.SetModalContextMenu(GetSettings().GetModalContextMenu());
    backup_.SetMultiTargetTapNotificationEnabled(GetSettings().GetMultiTargetTapNotificationEnabled());
    backup_.SetNavigateOnDragDrop(GetSettings().GetNavigateOnDragDrop());
    backup_.SetNavigationControls(GetSettings().GetNavigationControls());
    backup_.SetNavigatorPlatformOverride(GetSettings().GetNavigatorPlatformOverride());
    backup_.SetOutputDeviceUpdateAbilityType(GetSettings().GetOutputDeviceUpdateAbilityType());
    backup_.SetParserScriptingFlagPolicy(GetSettings().GetParserScriptingFlagPolicy());
    backup_.SetPasswordEchoDurationInSeconds(GetSettings().GetPasswordEchoDurationInSeconds());
    backup_.SetPasswordEchoEnabled(GetSettings().GetPasswordEchoEnabled());
    backup_.SetPictureInPictureEnabled(GetSettings().GetPictureInPictureEnabled());
    backup_.SetPlaceRTLScrollbarsOnLeftSideInMainFrame(GetSettings().GetPlaceRTLScrollbarsOnLeftSideInMainFrame());
    backup_.SetPluginsEnabled(GetSettings().GetPluginsEnabled());
    backup_.SetPreferHiddenVolumeControls(GetSettings().GetPreferHiddenVolumeControls());
    backup_.SetPreferredColorScheme(GetSettings().GetPreferredColorScheme());
    backup_.SetPreferredContrast(GetSettings().GetPreferredContrast());
    backup_.SetPreferredRootScrollbarColorScheme(GetSettings().GetPreferredRootScrollbarColorScheme());
    backup_.SetPrefersDefaultScrollbarStyles(GetSettings().GetPrefersDefaultScrollbarStyles());
    backup_.SetPrefersReducedMotion(GetSettings().GetPrefersReducedMotion());
    backup_.SetPrefersReducedTransparency(GetSettings().GetPrefersReducedTransparency());
    backup_.SetPresentationReceiver(GetSettings().GetPresentationReceiver());
    backup_.SetPresentationRequiresUserGesture(GetSettings().GetPresentationRequiresUserGesture());
    backup_.SetPrimaryHoverType(GetSettings().GetPrimaryHoverType());
    backup_.SetPrimaryPointerType(GetSettings().GetPrimaryPointerType());
    backup_.SetPrintingMaximumShrinkFactor(GetSettings().GetPrintingMaximumShrinkFactor());
    backup_.SetReportScreenSizeInPhysicalPixelsQuirk(GetSettings().GetReportScreenSizeInPhysicalPixelsQuirk());
    backup_.SetRequireTransientActivationAndAuthorizationForSubAppsAPI(GetSettings().GetRequireTransientActivationAndAuthorizationForSubAppsAPI());
    backup_.SetRequireTransientActivationForGetDisplayMedia(GetSettings().GetRequireTransientActivationForGetDisplayMedia());
    backup_.SetRequireTransientActivationForShowFileOrDirectoryPicker(GetSettings().GetRequireTransientActivationForShowFileOrDirectoryPicker());
    backup_.SetResizable(GetSettings().GetResizable());
    backup_.SetRubberBandingOnCompositorThread(GetSettings().GetRubberBandingOnCompositorThread());
    backup_.SetScriptEnabled(GetSettings().GetScriptEnabled());
    backup_.SetScrollAnimatorEnabled(GetSettings().GetScrollAnimatorEnabled());
    backup_.SetSelectTrailingWhitespaceEnabled(GetSettings().GetSelectTrailingWhitespaceEnabled());
    backup_.SetSelectionClipboardBufferAvailable(GetSettings().GetSelectionClipboardBufferAvailable());
    backup_.SetSelectionIncludesAltImageText(GetSettings().GetSelectionIncludesAltImageText());
    backup_.SetSelectionStrategy(GetSettings().GetSelectionStrategy());
    backup_.SetShouldClearDocumentBackground(GetSettings().GetShouldClearDocumentBackground());
    backup_.SetShouldPrintBackgrounds(GetSettings().GetShouldPrintBackgrounds());
    backup_.SetShouldProtectAgainstIpcFlooding(GetSettings().GetShouldProtectAgainstIpcFlooding());
    backup_.SetShouldReuseGlobalForUnownedMainFrame(GetSettings().GetShouldReuseGlobalForUnownedMainFrame());
    backup_.SetShowContextMenuOnMouseUp(GetSettings().GetShowContextMenuOnMouseUp());
    backup_.SetShrinksViewportContentToFit(GetSettings().GetShrinksViewportContentToFit());
    backup_.SetSmartInsertDeleteEnabled(GetSettings().GetSmartInsertDeleteEnabled());
    backup_.SetSmoothScrollForFindEnabled(GetSettings().GetSmoothScrollForFindEnabled());
    backup_.SetSpatialNavigationEnabled(GetSettings().GetSpatialNavigationEnabled());
    backup_.SetSpellCheckEnabledByDefault(GetSettings().GetSpellCheckEnabledByDefault());
    backup_.SetStrictMixedContentChecking(GetSettings().GetStrictMixedContentChecking());
    backup_.SetStrictMixedContentCheckingForPlugin(GetSettings().GetStrictMixedContentCheckingForPlugin());
    backup_.SetStrictPowerfulFeatureRestrictions(GetSettings().GetStrictPowerfulFeatureRestrictions());
    backup_.SetStrictlyBlockBlockableMixedContent(GetSettings().GetStrictlyBlockBlockableMixedContent());
    backup_.SetSupportsMultipleWindows(GetSettings().GetSupportsMultipleWindows());
    backup_.SetSyncXHRInDocumentsEnabled(GetSettings().GetSyncXHRInDocumentsEnabled());
    backup_.SetTargetBlankImpliesNoOpenerEnabledWillBeRemoved(GetSettings().GetTargetBlankImpliesNoOpenerEnabledWillBeRemoved());
    backup_.SetTextAreasAreResizable(GetSettings().GetTextAreasAreResizable());
    backup_.SetTextAutosizingEnabled(GetSettings().GetTextAutosizingEnabled());
    backup_.SetTextAutosizingWindowSizeOverride(GetSettings().GetTextAutosizingWindowSizeOverride());
    backup_.SetTextTrackBackgroundColor(GetSettings().GetTextTrackBackgroundColor());
    backup_.SetTextTrackFontFamily(GetSettings().GetTextTrackFontFamily());
    backup_.SetTextTrackFontStyle(GetSettings().GetTextTrackFontStyle());
    backup_.SetTextTrackFontVariant(GetSettings().GetTextTrackFontVariant());
    backup_.SetTextTrackKindUserPreference(GetSettings().GetTextTrackKindUserPreference());
    backup_.SetTextTrackMarginPercentage(GetSettings().GetTextTrackMarginPercentage());
    backup_.SetTextTrackTextColor(GetSettings().GetTextTrackTextColor());
    backup_.SetTextTrackTextShadow(GetSettings().GetTextTrackTextShadow());
    backup_.SetTextTrackTextSize(GetSettings().GetTextTrackTextSize());
    backup_.SetTextTrackWindowColor(GetSettings().GetTextTrackWindowColor());
    backup_.SetTextTrackWindowRadius(GetSettings().GetTextTrackWindowRadius());
    backup_.SetTouchDragDropEnabled(GetSettings().GetTouchDragDropEnabled());
    backup_.SetTouchDragEndContextMenu(GetSettings().GetTouchDragEndContextMenu());
    backup_.SetTouchEditingEnabled(GetSettings().GetTouchEditingEnabled());
    backup_.SetUseAXMenuList(GetSettings().GetUseAXMenuList());
    backup_.SetUseWideViewport(GetSettings().GetUseWideViewport());
    backup_.SetV8CacheOptions(GetSettings().GetV8CacheOptions());
    backup_.SetValidationMessageTimerMagnification(GetSettings().GetValidationMessageTimerMagnification());
    backup_.SetViewportEnabled(GetSettings().GetViewportEnabled());
    backup_.SetViewportMetaEnabled(GetSettings().GetViewportMetaEnabled());
    backup_.SetViewportMetaMergeContentQuirk(GetSettings().GetViewportMetaMergeContentQuirk());
    backup_.SetViewportMetaZeroValuesQuirk(GetSettings().GetViewportMetaZeroValuesQuirk());
    backup_.SetViewportStyle(GetSettings().GetViewportStyle());
    backup_.SetWebAppScope(GetSettings().GetWebAppScope());
    backup_.SetWebGL1Enabled(GetSettings().GetWebGL1Enabled());
    backup_.SetWebGL2Enabled(GetSettings().GetWebGL2Enabled());
    backup_.SetWebGLErrorsToConsoleEnabled(GetSettings().GetWebGLErrorsToConsoleEnabled());
    backup_.SetWebSecurityEnabled(GetSettings().GetWebSecurityEnabled());
    backup_.SetWideViewportQuirkEnabled(GetSettings().GetWideViewportQuirkEnabled());
    backup_.SetWindowShowState(GetSettings().GetWindowShowState());
}

InternalSettingsGenerated::~InternalSettingsGenerated()
{
}

void InternalSettingsGenerated::ResetToConsistentState()
{
    GetSettings().SetDOMPasteAllowed(backup_.GetDOMPasteAllowed());
    GetSettings().SetDontSendKeyEventsToJavascript(backup_.GetDontSendKeyEventsToJavascript());
    GetSettings().SetHighlightAds(backup_.GetHighlightAds());
    GetSettings().SetLCDTextPreference(backup_.GetLCDTextPreference());
    GetSettings().SetNetworkQuietTimeout(backup_.GetNetworkQuietTimeout());
    GetSettings().SetWebXRImmersiveArAllowed(backup_.GetWebXRImmersiveArAllowed());
    GetSettings().SetAccelerated2dCanvasMSAASampleCount(backup_.GetAccelerated2dCanvasMSAASampleCount());
    GetSettings().SetAcceleratedCompositingEnabled(backup_.GetAcceleratedCompositingEnabled());
    GetSettings().SetAccessibilityAlwaysShowFocus(backup_.GetAccessibilityAlwaysShowFocus());
    GetSettings().SetAccessibilityFontScaleFactor(backup_.GetAccessibilityFontScaleFactor());
    GetSettings().SetAccessibilityFontWeightAdjustment(backup_.GetAccessibilityFontWeightAdjustment());
    GetSettings().SetAccessibilityIncludeSvgGElement(backup_.GetAccessibilityIncludeSvgGElement());
    GetSettings().SetAccessibilityPasswordValuesEnabled(backup_.GetAccessibilityPasswordValuesEnabled());
    GetSettings().SetAccessibilityTextSizeContrastFactor(backup_.GetAccessibilityTextSizeContrastFactor());
    GetSettings().SetAllowCustomScrollbarInMainFrame(backup_.GetAllowCustomScrollbarInMainFrame());
    GetSettings().SetAllowFileAccessFromFileURLs(backup_.GetAllowFileAccessFromFileURLs());
    GetSettings().SetAllowGeolocationOnInsecureOrigins(backup_.GetAllowGeolocationOnInsecureOrigins());
    GetSettings().SetAllowNonEmptyNavigatorPlugins(backup_.GetAllowNonEmptyNavigatorPlugins());
    GetSettings().SetAllowRunningOfInsecureContent(backup_.GetAllowRunningOfInsecureContent());
    GetSettings().SetAllowScriptsToCloseWindows(backup_.GetAllowScriptsToCloseWindows());
    GetSettings().SetAllowUniversalAccessFromFileURLs(backup_.GetAllowUniversalAccessFromFileURLs());
    GetSettings().SetAlwaysShowContextMenuOnTouch(backup_.GetAlwaysShowContextMenuOnTouch());
    GetSettings().SetAntialiased2dCanvasEnabled(backup_.GetAntialiased2dCanvasEnabled());
    GetSettings().SetAntialiasedClips2dCanvasEnabled(backup_.GetAntialiasedClips2dCanvasEnabled());
    GetSettings().SetAriaModalPrunesAXTree(backup_.GetAriaModalPrunesAXTree());
    GetSettings().SetAutoplayPolicy(backup_.GetAutoplayPolicy());
    GetSettings().SetAvailableHoverTypes(backup_.GetAvailableHoverTypes());
    GetSettings().SetAvailablePointerTypes(backup_.GetAvailablePointerTypes());
    GetSettings().SetBarrelButtonForDragEnabled(backup_.GetBarrelButtonForDragEnabled());
    GetSettings().SetBypassCSP(backup_.GetBypassCSP());
    GetSettings().SetCaretBrowsingEnabled(backup_.GetCaretBrowsingEnabled());
    GetSettings().SetCookieEnabled(backup_.GetCookieEnabled());
    GetSettings().SetDefaultFixedFontSize(backup_.GetDefaultFixedFontSize());
    GetSettings().SetDefaultFontSize(backup_.GetDefaultFontSize());
    GetSettings().SetDefaultTextEncodingName(backup_.GetDefaultTextEncodingName());
    GetSettings().SetDefaultVideoPosterURL(backup_.GetDefaultVideoPosterURL());
    GetSettings().SetDeviceScaleAdjustment(backup_.GetDeviceScaleAdjustment());
    GetSettings().SetDisableReadingFromCanvas(backup_.GetDisableReadingFromCanvas());
    GetSettings().SetDisallowFetchForDocWrittenScriptsInMainFrame(backup_.GetDisallowFetchForDocWrittenScriptsInMainFrame());
    GetSettings().SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(backup_.GetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G());
    GetSettings().SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(backup_.GetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections());
    GetSettings().SetDisplayModeOverride(backup_.GetDisplayModeOverride());
    GetSettings().SetDNSPrefetchingEnabled(backup_.GetDNSPrefetchingEnabled());
    GetSettings().SetDoHtmlPreloadScanning(backup_.GetDoHtmlPreloadScanning());
    GetSettings().SetDoNotUpdateSelectionOnMutatingSelectionRange(backup_.GetDoNotUpdateSelectionOnMutatingSelectionRange());
    GetSettings().SetDownloadableBinaryFontsEnabled(backup_.GetDownloadableBinaryFontsEnabled());
    GetSettings().SetDynamicSafeAreaInsetsEnabled(backup_.GetDynamicSafeAreaInsetsEnabled());
    GetSettings().SetEditingBehaviorType(backup_.GetEditingBehaviorType());
    GetSettings().SetEmbeddedMediaExperienceEnabled(backup_.GetEmbeddedMediaExperienceEnabled());
    GetSettings().SetForceAndroidOverlayScrollbar(backup_.GetForceAndroidOverlayScrollbar());
    GetSettings().SetForceDarkModeEnabled(backup_.GetForceDarkModeEnabled());
    GetSettings().SetForceMainWorldInitialization(backup_.GetForceMainWorldInitialization());
    GetSettings().SetForceTouchEventFeatureDetectionForInspector(backup_.GetForceTouchEventFeatureDetectionForInspector());
    GetSettings().SetForceZeroLayoutHeight(backup_.GetForceZeroLayoutHeight());
    GetSettings().SetFullscreenSupported(backup_.GetFullscreenSupported());
    GetSettings().SetHideDownloadUI(backup_.GetHideDownloadUI());
    GetSettings().SetHideScrollbars(backup_.GetHideScrollbars());
    GetSettings().SetHyperlinkAuditingEnabled(backup_.GetHyperlinkAuditingEnabled());
    GetSettings().SetIgnoreMainFrameOverflowHiddenQuirk(backup_.GetIgnoreMainFrameOverflowHiddenQuirk());
    GetSettings().SetImageAnimationPolicy(backup_.GetImageAnimationPolicy());
    GetSettings().SetImagesEnabled(backup_.GetImagesEnabled());
    GetSettings().SetImmersiveModeEnabled(backup_.GetImmersiveModeEnabled());
    GetSettings().SetInForcedColors(backup_.GetInForcedColors());
    GetSettings().SetInvertedColors(backup_.GetInvertedColors());
    GetSettings().SetIsForcedColorsDisabled(backup_.GetIsForcedColorsDisabled());
    GetSettings().SetJavaScriptCanAccessClipboard(backup_.GetJavaScriptCanAccessClipboard());
    GetSettings().SetLazyLoadEnabled(backup_.GetLazyLoadEnabled());
    GetSettings().SetLazyLoadingFrameMarginPx2G(backup_.GetLazyLoadingFrameMarginPx2G());
    GetSettings().SetLazyLoadingFrameMarginPx3G(backup_.GetLazyLoadingFrameMarginPx3G());
    GetSettings().SetLazyLoadingFrameMarginPx4G(backup_.GetLazyLoadingFrameMarginPx4G());
    GetSettings().SetLazyLoadingFrameMarginPxOffline(backup_.GetLazyLoadingFrameMarginPxOffline());
    GetSettings().SetLazyLoadingFrameMarginPxSlow2G(backup_.GetLazyLoadingFrameMarginPxSlow2G());
    GetSettings().SetLazyLoadingFrameMarginPxUnknown(backup_.GetLazyLoadingFrameMarginPxUnknown());
    GetSettings().SetLazyLoadingImageMarginPx2G(backup_.GetLazyLoadingImageMarginPx2G());
    GetSettings().SetLazyLoadingImageMarginPx3G(backup_.GetLazyLoadingImageMarginPx3G());
    GetSettings().SetLazyLoadingImageMarginPx4G(backup_.GetLazyLoadingImageMarginPx4G());
    GetSettings().SetLazyLoadingImageMarginPxOffline(backup_.GetLazyLoadingImageMarginPxOffline());
    GetSettings().SetLazyLoadingImageMarginPxSlow2G(backup_.GetLazyLoadingImageMarginPxSlow2G());
    GetSettings().SetLazyLoadingImageMarginPxUnknown(backup_.GetLazyLoadingImageMarginPxUnknown());
    GetSettings().SetLoadWithOverviewMode(backup_.GetLoadWithOverviewMode());
    GetSettings().SetLoadsImagesAutomatically(backup_.GetLoadsImagesAutomatically());
    GetSettings().SetLocalStorageEnabled(backup_.GetLocalStorageEnabled());
    GetSettings().SetLogDnsPrefetchAndPreconnect(backup_.GetLogDnsPrefetchAndPreconnect());
    GetSettings().SetLogPreload(backup_.GetLogPreload());
    GetSettings().SetLowPriorityIframesThreshold(backup_.GetLowPriorityIframesThreshold());
    GetSettings().SetMainFrameClipsContent(backup_.GetMainFrameClipsContent());
    GetSettings().SetMainFrameResizesAreOrientationChanges(backup_.GetMainFrameResizesAreOrientationChanges());
    GetSettings().SetMaxTouchPoints(backup_.GetMaxTouchPoints());
    GetSettings().SetMediaControlsEnabled(backup_.GetMediaControlsEnabled());
    GetSettings().SetMediaTypeOverride(backup_.GetMediaTypeOverride());
    GetSettings().SetMinimumFontSize(backup_.GetMinimumFontSize());
    GetSettings().SetMinimumLogicalFontSize(backup_.GetMinimumLogicalFontSize());
    GetSettings().SetMockGestureTapHighlightsEnabled(backup_.GetMockGestureTapHighlightsEnabled());
    GetSettings().SetModalContextMenu(backup_.GetModalContextMenu());
    GetSettings().SetMultiTargetTapNotificationEnabled(backup_.GetMultiTargetTapNotificationEnabled());
    GetSettings().SetNavigateOnDragDrop(backup_.GetNavigateOnDragDrop());
    GetSettings().SetNavigationControls(backup_.GetNavigationControls());
    GetSettings().SetNavigatorPlatformOverride(backup_.GetNavigatorPlatformOverride());
    GetSettings().SetOutputDeviceUpdateAbilityType(backup_.GetOutputDeviceUpdateAbilityType());
    GetSettings().SetParserScriptingFlagPolicy(backup_.GetParserScriptingFlagPolicy());
    GetSettings().SetPasswordEchoDurationInSeconds(backup_.GetPasswordEchoDurationInSeconds());
    GetSettings().SetPasswordEchoEnabled(backup_.GetPasswordEchoEnabled());
    GetSettings().SetPictureInPictureEnabled(backup_.GetPictureInPictureEnabled());
    GetSettings().SetPlaceRTLScrollbarsOnLeftSideInMainFrame(backup_.GetPlaceRTLScrollbarsOnLeftSideInMainFrame());
    GetSettings().SetPluginsEnabled(backup_.GetPluginsEnabled());
    GetSettings().SetPreferHiddenVolumeControls(backup_.GetPreferHiddenVolumeControls());
    GetSettings().SetPreferredColorScheme(backup_.GetPreferredColorScheme());
    GetSettings().SetPreferredContrast(backup_.GetPreferredContrast());
    GetSettings().SetPreferredRootScrollbarColorScheme(backup_.GetPreferredRootScrollbarColorScheme());
    GetSettings().SetPrefersDefaultScrollbarStyles(backup_.GetPrefersDefaultScrollbarStyles());
    GetSettings().SetPrefersReducedMotion(backup_.GetPrefersReducedMotion());
    GetSettings().SetPrefersReducedTransparency(backup_.GetPrefersReducedTransparency());
    GetSettings().SetPresentationReceiver(backup_.GetPresentationReceiver());
    GetSettings().SetPresentationRequiresUserGesture(backup_.GetPresentationRequiresUserGesture());
    GetSettings().SetPrimaryHoverType(backup_.GetPrimaryHoverType());
    GetSettings().SetPrimaryPointerType(backup_.GetPrimaryPointerType());
    GetSettings().SetPrintingMaximumShrinkFactor(backup_.GetPrintingMaximumShrinkFactor());
    GetSettings().SetReportScreenSizeInPhysicalPixelsQuirk(backup_.GetReportScreenSizeInPhysicalPixelsQuirk());
    GetSettings().SetRequireTransientActivationAndAuthorizationForSubAppsAPI(backup_.GetRequireTransientActivationAndAuthorizationForSubAppsAPI());
    GetSettings().SetRequireTransientActivationForGetDisplayMedia(backup_.GetRequireTransientActivationForGetDisplayMedia());
    GetSettings().SetRequireTransientActivationForShowFileOrDirectoryPicker(backup_.GetRequireTransientActivationForShowFileOrDirectoryPicker());
    GetSettings().SetResizable(backup_.GetResizable());
    GetSettings().SetRubberBandingOnCompositorThread(backup_.GetRubberBandingOnCompositorThread());
    GetSettings().SetScriptEnabled(backup_.GetScriptEnabled());
    GetSettings().SetScrollAnimatorEnabled(backup_.GetScrollAnimatorEnabled());
    GetSettings().SetSelectTrailingWhitespaceEnabled(backup_.GetSelectTrailingWhitespaceEnabled());
    GetSettings().SetSelectionClipboardBufferAvailable(backup_.GetSelectionClipboardBufferAvailable());
    GetSettings().SetSelectionIncludesAltImageText(backup_.GetSelectionIncludesAltImageText());
    GetSettings().SetSelectionStrategy(backup_.GetSelectionStrategy());
    GetSettings().SetShouldClearDocumentBackground(backup_.GetShouldClearDocumentBackground());
    GetSettings().SetShouldPrintBackgrounds(backup_.GetShouldPrintBackgrounds());
    GetSettings().SetShouldProtectAgainstIpcFlooding(backup_.GetShouldProtectAgainstIpcFlooding());
    GetSettings().SetShouldReuseGlobalForUnownedMainFrame(backup_.GetShouldReuseGlobalForUnownedMainFrame());
    GetSettings().SetShowContextMenuOnMouseUp(backup_.GetShowContextMenuOnMouseUp());
    GetSettings().SetShrinksViewportContentToFit(backup_.GetShrinksViewportContentToFit());
    GetSettings().SetSmartInsertDeleteEnabled(backup_.GetSmartInsertDeleteEnabled());
    GetSettings().SetSmoothScrollForFindEnabled(backup_.GetSmoothScrollForFindEnabled());
    GetSettings().SetSpatialNavigationEnabled(backup_.GetSpatialNavigationEnabled());
    GetSettings().SetSpellCheckEnabledByDefault(backup_.GetSpellCheckEnabledByDefault());
    GetSettings().SetStrictMixedContentChecking(backup_.GetStrictMixedContentChecking());
    GetSettings().SetStrictMixedContentCheckingForPlugin(backup_.GetStrictMixedContentCheckingForPlugin());
    GetSettings().SetStrictPowerfulFeatureRestrictions(backup_.GetStrictPowerfulFeatureRestrictions());
    GetSettings().SetStrictlyBlockBlockableMixedContent(backup_.GetStrictlyBlockBlockableMixedContent());
    GetSettings().SetSupportsMultipleWindows(backup_.GetSupportsMultipleWindows());
    GetSettings().SetSyncXHRInDocumentsEnabled(backup_.GetSyncXHRInDocumentsEnabled());
    GetSettings().SetTargetBlankImpliesNoOpenerEnabledWillBeRemoved(backup_.GetTargetBlankImpliesNoOpenerEnabledWillBeRemoved());
    GetSettings().SetTextAreasAreResizable(backup_.GetTextAreasAreResizable());
    GetSettings().SetTextAutosizingEnabled(backup_.GetTextAutosizingEnabled());
    GetSettings().SetTextAutosizingWindowSizeOverride(backup_.GetTextAutosizingWindowSizeOverride());
    GetSettings().SetTextTrackBackgroundColor(backup_.GetTextTrackBackgroundColor());
    GetSettings().SetTextTrackFontFamily(backup_.GetTextTrackFontFamily());
    GetSettings().SetTextTrackFontStyle(backup_.GetTextTrackFontStyle());
    GetSettings().SetTextTrackFontVariant(backup_.GetTextTrackFontVariant());
    GetSettings().SetTextTrackKindUserPreference(backup_.GetTextTrackKindUserPreference());
    GetSettings().SetTextTrackMarginPercentage(backup_.GetTextTrackMarginPercentage());
    GetSettings().SetTextTrackTextColor(backup_.GetTextTrackTextColor());
    GetSettings().SetTextTrackTextShadow(backup_.GetTextTrackTextShadow());
    GetSettings().SetTextTrackTextSize(backup_.GetTextTrackTextSize());
    GetSettings().SetTextTrackWindowColor(backup_.GetTextTrackWindowColor());
    GetSettings().SetTextTrackWindowRadius(backup_.GetTextTrackWindowRadius());
    GetSettings().SetTouchDragDropEnabled(backup_.GetTouchDragDropEnabled());
    GetSettings().SetTouchDragEndContextMenu(backup_.GetTouchDragEndContextMenu());
    GetSettings().SetTouchEditingEnabled(backup_.GetTouchEditingEnabled());
    GetSettings().SetUseAXMenuList(backup_.GetUseAXMenuList());
    GetSettings().SetUseWideViewport(backup_.GetUseWideViewport());
    GetSettings().SetV8CacheOptions(backup_.GetV8CacheOptions());
    GetSettings().SetValidationMessageTimerMagnification(backup_.GetValidationMessageTimerMagnification());
    GetSettings().SetViewportEnabled(backup_.GetViewportEnabled());
    GetSettings().SetViewportMetaEnabled(backup_.GetViewportMetaEnabled());
    GetSettings().SetViewportMetaMergeContentQuirk(backup_.GetViewportMetaMergeContentQuirk());
    GetSettings().SetViewportMetaZeroValuesQuirk(backup_.GetViewportMetaZeroValuesQuirk());
    GetSettings().SetViewportStyle(backup_.GetViewportStyle());
    GetSettings().SetWebAppScope(backup_.GetWebAppScope());
    GetSettings().SetWebGL1Enabled(backup_.GetWebGL1Enabled());
    GetSettings().SetWebGL2Enabled(backup_.GetWebGL2Enabled());
    GetSettings().SetWebGLErrorsToConsoleEnabled(backup_.GetWebGLErrorsToConsoleEnabled());
    GetSettings().SetWebSecurityEnabled(backup_.GetWebSecurityEnabled());
    GetSettings().SetWideViewportQuirkEnabled(backup_.GetWideViewportQuirkEnabled());
    GetSettings().SetWindowShowState(backup_.GetWindowShowState());
}

void InternalSettingsGenerated::setDOMPasteAllowed(bool DOMPasteAllowed)
{
    GetSettings().SetDOMPasteAllowed(DOMPasteAllowed);
}

void InternalSettingsGenerated::setDontSendKeyEventsToJavascript(bool DontSendKeyEventsToJavascript)
{
    GetSettings().SetDontSendKeyEventsToJavascript(DontSendKeyEventsToJavascript);
}

void InternalSettingsGenerated::setHighlightAds(bool HighlightAds)
{
    GetSettings().SetHighlightAds(HighlightAds);
}

void InternalSettingsGenerated::setNetworkQuietTimeout(double NetworkQuietTimeout)
{
    GetSettings().SetNetworkQuietTimeout(NetworkQuietTimeout);
}

void InternalSettingsGenerated::setWebXRImmersiveArAllowed(bool WebXRImmersiveArAllowed)
{
    GetSettings().SetWebXRImmersiveArAllowed(WebXRImmersiveArAllowed);
}

void InternalSettingsGenerated::setAccelerated2dCanvasMSAASampleCount(int accelerated2dCanvasMSAASampleCount)
{
    GetSettings().SetAccelerated2dCanvasMSAASampleCount(accelerated2dCanvasMSAASampleCount);
}

void InternalSettingsGenerated::setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled)
{
    GetSettings().SetAcceleratedCompositingEnabled(acceleratedCompositingEnabled);
}

void InternalSettingsGenerated::setAccessibilityAlwaysShowFocus(bool accessibilityAlwaysShowFocus)
{
    GetSettings().SetAccessibilityAlwaysShowFocus(accessibilityAlwaysShowFocus);
}

void InternalSettingsGenerated::setAccessibilityFontScaleFactor(double accessibilityFontScaleFactor)
{
    GetSettings().SetAccessibilityFontScaleFactor(accessibilityFontScaleFactor);
}

void InternalSettingsGenerated::setAccessibilityFontWeightAdjustment(int accessibilityFontWeightAdjustment)
{
    GetSettings().SetAccessibilityFontWeightAdjustment(accessibilityFontWeightAdjustment);
}

void InternalSettingsGenerated::setAccessibilityIncludeSvgGElement(bool accessibilityIncludeSvgGElement)
{
    GetSettings().SetAccessibilityIncludeSvgGElement(accessibilityIncludeSvgGElement);
}

void InternalSettingsGenerated::setAccessibilityPasswordValuesEnabled(bool accessibilityPasswordValuesEnabled)
{
    GetSettings().SetAccessibilityPasswordValuesEnabled(accessibilityPasswordValuesEnabled);
}

void InternalSettingsGenerated::setAccessibilityTextSizeContrastFactor(int accessibilityTextSizeContrastFactor)
{
    GetSettings().SetAccessibilityTextSizeContrastFactor(accessibilityTextSizeContrastFactor);
}

void InternalSettingsGenerated::setAllowCustomScrollbarInMainFrame(bool allowCustomScrollbarInMainFrame)
{
    GetSettings().SetAllowCustomScrollbarInMainFrame(allowCustomScrollbarInMainFrame);
}

void InternalSettingsGenerated::setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs)
{
    GetSettings().SetAllowFileAccessFromFileURLs(allowFileAccessFromFileURLs);
}

void InternalSettingsGenerated::setAllowGeolocationOnInsecureOrigins(bool allowGeolocationOnInsecureOrigins)
{
    GetSettings().SetAllowGeolocationOnInsecureOrigins(allowGeolocationOnInsecureOrigins);
}

void InternalSettingsGenerated::setAllowNonEmptyNavigatorPlugins(bool allowNonEmptyNavigatorPlugins)
{
    GetSettings().SetAllowNonEmptyNavigatorPlugins(allowNonEmptyNavigatorPlugins);
}

void InternalSettingsGenerated::setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent)
{
    GetSettings().SetAllowRunningOfInsecureContent(allowRunningOfInsecureContent);
}

void InternalSettingsGenerated::setAllowScriptsToCloseWindows(bool allowScriptsToCloseWindows)
{
    GetSettings().SetAllowScriptsToCloseWindows(allowScriptsToCloseWindows);
}

void InternalSettingsGenerated::setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs)
{
    GetSettings().SetAllowUniversalAccessFromFileURLs(allowUniversalAccessFromFileURLs);
}

void InternalSettingsGenerated::setAlwaysShowContextMenuOnTouch(bool alwaysShowContextMenuOnTouch)
{
    GetSettings().SetAlwaysShowContextMenuOnTouch(alwaysShowContextMenuOnTouch);
}

void InternalSettingsGenerated::setAntialiased2dCanvasEnabled(bool antialiased2dCanvasEnabled)
{
    GetSettings().SetAntialiased2dCanvasEnabled(antialiased2dCanvasEnabled);
}

void InternalSettingsGenerated::setAntialiasedClips2dCanvasEnabled(bool antialiasedClips2dCanvasEnabled)
{
    GetSettings().SetAntialiasedClips2dCanvasEnabled(antialiasedClips2dCanvasEnabled);
}

void InternalSettingsGenerated::setAriaModalPrunesAXTree(bool ariaModalPrunesAXTree)
{
    GetSettings().SetAriaModalPrunesAXTree(ariaModalPrunesAXTree);
}

void InternalSettingsGenerated::setAvailableHoverTypes(int availableHoverTypes)
{
    GetSettings().SetAvailableHoverTypes(availableHoverTypes);
}

void InternalSettingsGenerated::setAvailablePointerTypes(int availablePointerTypes)
{
    GetSettings().SetAvailablePointerTypes(availablePointerTypes);
}

void InternalSettingsGenerated::setBarrelButtonForDragEnabled(bool barrelButtonForDragEnabled)
{
    GetSettings().SetBarrelButtonForDragEnabled(barrelButtonForDragEnabled);
}

void InternalSettingsGenerated::setBypassCSP(bool bypassCSP)
{
    GetSettings().SetBypassCSP(bypassCSP);
}

void InternalSettingsGenerated::setCaretBrowsingEnabled(bool caretBrowsingEnabled)
{
    GetSettings().SetCaretBrowsingEnabled(caretBrowsingEnabled);
}

void InternalSettingsGenerated::setCookieEnabled(bool cookieEnabled)
{
    GetSettings().SetCookieEnabled(cookieEnabled);
}

void InternalSettingsGenerated::setDefaultFixedFontSize(int defaultFixedFontSize)
{
    GetSettings().SetDefaultFixedFontSize(defaultFixedFontSize);
}

void InternalSettingsGenerated::setDefaultFontSize(int defaultFontSize)
{
    GetSettings().SetDefaultFontSize(defaultFontSize);
}

void InternalSettingsGenerated::setDefaultTextEncodingName(const String& defaultTextEncodingName)
{
    GetSettings().SetDefaultTextEncodingName(defaultTextEncodingName);
}

void InternalSettingsGenerated::setDefaultVideoPosterURL(const String& defaultVideoPosterURL)
{
    GetSettings().SetDefaultVideoPosterURL(defaultVideoPosterURL);
}

void InternalSettingsGenerated::setDeviceScaleAdjustment(double deviceScaleAdjustment)
{
    GetSettings().SetDeviceScaleAdjustment(deviceScaleAdjustment);
}

void InternalSettingsGenerated::setDisableReadingFromCanvas(bool disableReadingFromCanvas)
{
    GetSettings().SetDisableReadingFromCanvas(disableReadingFromCanvas);
}

void InternalSettingsGenerated::setDisallowFetchForDocWrittenScriptsInMainFrame(bool disallowFetchForDocWrittenScriptsInMainFrame)
{
    GetSettings().SetDisallowFetchForDocWrittenScriptsInMainFrame(disallowFetchForDocWrittenScriptsInMainFrame);
}

void InternalSettingsGenerated::setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G)
{
    GetSettings().SetDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G);
}

void InternalSettingsGenerated::setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(
    bool disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections)
{
    GetSettings().SetDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections);
}

void InternalSettingsGenerated::setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled)
{
    GetSettings().SetDNSPrefetchingEnabled(dnsPrefetchingEnabled);
}

void InternalSettingsGenerated::setDoHtmlPreloadScanning(bool doHtmlPreloadScanning)
{
    GetSettings().SetDoHtmlPreloadScanning(doHtmlPreloadScanning);
}

void InternalSettingsGenerated::setDoNotUpdateSelectionOnMutatingSelectionRange(bool doNotUpdateSelectionOnMutatingSelectionRange)
{
    GetSettings().SetDoNotUpdateSelectionOnMutatingSelectionRange(doNotUpdateSelectionOnMutatingSelectionRange);
}

void InternalSettingsGenerated::setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled)
{
    GetSettings().SetDownloadableBinaryFontsEnabled(downloadableBinaryFontsEnabled);
}

void InternalSettingsGenerated::setDynamicSafeAreaInsetsEnabled(bool dynamicSafeAreaInsetsEnabled)
{
    GetSettings().SetDynamicSafeAreaInsetsEnabled(dynamicSafeAreaInsetsEnabled);
}

void InternalSettingsGenerated::setEmbeddedMediaExperienceEnabled(bool embeddedMediaExperienceEnabled)
{
    GetSettings().SetEmbeddedMediaExperienceEnabled(embeddedMediaExperienceEnabled);
}

void InternalSettingsGenerated::setForceAndroidOverlayScrollbar(bool forceAndroidOverlayScrollbar)
{
    GetSettings().SetForceAndroidOverlayScrollbar(forceAndroidOverlayScrollbar);
}

void InternalSettingsGenerated::setForceDarkModeEnabled(bool forceDarkModeEnabled)
{
    GetSettings().SetForceDarkModeEnabled(forceDarkModeEnabled);
}

void InternalSettingsGenerated::setForceMainWorldInitialization(bool forceMainWorldInitialization)
{
    GetSettings().SetForceMainWorldInitialization(forceMainWorldInitialization);
}

void InternalSettingsGenerated::setForceTouchEventFeatureDetectionForInspector(bool forceTouchEventFeatureDetectionForInspector)
{
    GetSettings().SetForceTouchEventFeatureDetectionForInspector(forceTouchEventFeatureDetectionForInspector);
}

void InternalSettingsGenerated::setForceZeroLayoutHeight(bool forceZeroLayoutHeight)
{
    GetSettings().SetForceZeroLayoutHeight(forceZeroLayoutHeight);
}

void InternalSettingsGenerated::setFullscreenSupported(bool fullscreenSupported)
{
    GetSettings().SetFullscreenSupported(fullscreenSupported);
}

void InternalSettingsGenerated::setHideDownloadUI(bool hideDownloadUI)
{
    GetSettings().SetHideDownloadUI(hideDownloadUI);
}

void InternalSettingsGenerated::setHideScrollbars(bool hideScrollbars)
{
    GetSettings().SetHideScrollbars(hideScrollbars);
}

void InternalSettingsGenerated::setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled)
{
    GetSettings().SetHyperlinkAuditingEnabled(hyperlinkAuditingEnabled);
}

void InternalSettingsGenerated::setIgnoreMainFrameOverflowHiddenQuirk(bool ignoreMainFrameOverflowHiddenQuirk)
{
    GetSettings().SetIgnoreMainFrameOverflowHiddenQuirk(ignoreMainFrameOverflowHiddenQuirk);
}

void InternalSettingsGenerated::setImagesEnabled(bool imagesEnabled)
{
    GetSettings().SetImagesEnabled(imagesEnabled);
}

void InternalSettingsGenerated::setImmersiveModeEnabled(bool immersiveModeEnabled)
{
    GetSettings().SetImmersiveModeEnabled(immersiveModeEnabled);
}

void InternalSettingsGenerated::setInForcedColors(bool inForcedColors)
{
    GetSettings().SetInForcedColors(inForcedColors);
}

void InternalSettingsGenerated::setInvertedColors(bool invertedColors)
{
    GetSettings().SetInvertedColors(invertedColors);
}

void InternalSettingsGenerated::setIsForcedColorsDisabled(bool isForcedColorsDisabled)
{
    GetSettings().SetIsForcedColorsDisabled(isForcedColorsDisabled);
}

void InternalSettingsGenerated::setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard)
{
    GetSettings().SetJavaScriptCanAccessClipboard(javaScriptCanAccessClipboard);
}

void InternalSettingsGenerated::setLazyLoadEnabled(bool lazyLoadEnabled)
{
    GetSettings().SetLazyLoadEnabled(lazyLoadEnabled);
}

void InternalSettingsGenerated::setLazyLoadingFrameMarginPx2G(int lazyLoadingFrameMarginPx2G)
{
    GetSettings().SetLazyLoadingFrameMarginPx2G(lazyLoadingFrameMarginPx2G);
}

void InternalSettingsGenerated::setLazyLoadingFrameMarginPx3G(int lazyLoadingFrameMarginPx3G)
{
    GetSettings().SetLazyLoadingFrameMarginPx3G(lazyLoadingFrameMarginPx3G);
}

void InternalSettingsGenerated::setLazyLoadingFrameMarginPx4G(int lazyLoadingFrameMarginPx4G)
{
    GetSettings().SetLazyLoadingFrameMarginPx4G(lazyLoadingFrameMarginPx4G);
}

void InternalSettingsGenerated::setLazyLoadingFrameMarginPxOffline(int lazyLoadingFrameMarginPxOffline)
{
    GetSettings().SetLazyLoadingFrameMarginPxOffline(lazyLoadingFrameMarginPxOffline);
}

void InternalSettingsGenerated::setLazyLoadingFrameMarginPxSlow2G(int lazyLoadingFrameMarginPxSlow2G)
{
    GetSettings().SetLazyLoadingFrameMarginPxSlow2G(lazyLoadingFrameMarginPxSlow2G);
}

void InternalSettingsGenerated::setLazyLoadingFrameMarginPxUnknown(int lazyLoadingFrameMarginPxUnknown)
{
    GetSettings().SetLazyLoadingFrameMarginPxUnknown(lazyLoadingFrameMarginPxUnknown);
}

void InternalSettingsGenerated::setLazyLoadingImageMarginPx2G(int lazyLoadingImageMarginPx2G)
{
    GetSettings().SetLazyLoadingImageMarginPx2G(lazyLoadingImageMarginPx2G);
}

void InternalSettingsGenerated::setLazyLoadingImageMarginPx3G(int lazyLoadingImageMarginPx3G)
{
    GetSettings().SetLazyLoadingImageMarginPx3G(lazyLoadingImageMarginPx3G);
}

void InternalSettingsGenerated::setLazyLoadingImageMarginPx4G(int lazyLoadingImageMarginPx4G)
{
    GetSettings().SetLazyLoadingImageMarginPx4G(lazyLoadingImageMarginPx4G);
}

void InternalSettingsGenerated::setLazyLoadingImageMarginPxOffline(int lazyLoadingImageMarginPxOffline)
{
    GetSettings().SetLazyLoadingImageMarginPxOffline(lazyLoadingImageMarginPxOffline);
}

void InternalSettingsGenerated::setLazyLoadingImageMarginPxSlow2G(int lazyLoadingImageMarginPxSlow2G)
{
    GetSettings().SetLazyLoadingImageMarginPxSlow2G(lazyLoadingImageMarginPxSlow2G);
}

void InternalSettingsGenerated::setLazyLoadingImageMarginPxUnknown(int lazyLoadingImageMarginPxUnknown)
{
    GetSettings().SetLazyLoadingImageMarginPxUnknown(lazyLoadingImageMarginPxUnknown);
}

void InternalSettingsGenerated::setLoadWithOverviewMode(bool loadWithOverviewMode)
{
    GetSettings().SetLoadWithOverviewMode(loadWithOverviewMode);
}

void InternalSettingsGenerated::setLoadsImagesAutomatically(bool loadsImagesAutomatically)
{
    GetSettings().SetLoadsImagesAutomatically(loadsImagesAutomatically);
}

void InternalSettingsGenerated::setLocalStorageEnabled(bool localStorageEnabled)
{
    GetSettings().SetLocalStorageEnabled(localStorageEnabled);
}

void InternalSettingsGenerated::setLogDnsPrefetchAndPreconnect(bool logDnsPrefetchAndPreconnect)
{
    GetSettings().SetLogDnsPrefetchAndPreconnect(logDnsPrefetchAndPreconnect);
}

void InternalSettingsGenerated::setLogPreload(bool logPreload)
{
    GetSettings().SetLogPreload(logPreload);
}

void InternalSettingsGenerated::setMainFrameClipsContent(bool mainFrameClipsContent)
{
    GetSettings().SetMainFrameClipsContent(mainFrameClipsContent);
}

void InternalSettingsGenerated::setMainFrameResizesAreOrientationChanges(bool mainFrameResizesAreOrientationChanges)
{
    GetSettings().SetMainFrameResizesAreOrientationChanges(mainFrameResizesAreOrientationChanges);
}

void InternalSettingsGenerated::setMaxTouchPoints(int maxTouchPoints)
{
    GetSettings().SetMaxTouchPoints(maxTouchPoints);
}

void InternalSettingsGenerated::setMediaControlsEnabled(bool mediaControlsEnabled)
{
    GetSettings().SetMediaControlsEnabled(mediaControlsEnabled);
}

void InternalSettingsGenerated::setMediaTypeOverride(const String& mediaTypeOverride)
{
    GetSettings().SetMediaTypeOverride(mediaTypeOverride);
}

void InternalSettingsGenerated::setMinimumFontSize(int minimumFontSize)
{
    GetSettings().SetMinimumFontSize(minimumFontSize);
}

void InternalSettingsGenerated::setMinimumLogicalFontSize(int minimumLogicalFontSize)
{
    GetSettings().SetMinimumLogicalFontSize(minimumLogicalFontSize);
}

void InternalSettingsGenerated::setMockGestureTapHighlightsEnabled(bool mockGestureTapHighlightsEnabled)
{
    GetSettings().SetMockGestureTapHighlightsEnabled(mockGestureTapHighlightsEnabled);
}

void InternalSettingsGenerated::setModalContextMenu(bool modalContextMenu)
{
    GetSettings().SetModalContextMenu(modalContextMenu);
}

void InternalSettingsGenerated::setMultiTargetTapNotificationEnabled(bool multiTargetTapNotificationEnabled)
{
    GetSettings().SetMultiTargetTapNotificationEnabled(multiTargetTapNotificationEnabled);
}

void InternalSettingsGenerated::setNavigateOnDragDrop(bool navigateOnDragDrop)
{
    GetSettings().SetNavigateOnDragDrop(navigateOnDragDrop);
}

void InternalSettingsGenerated::setNavigatorPlatformOverride(const String& navigatorPlatformOverride)
{
    GetSettings().SetNavigatorPlatformOverride(navigatorPlatformOverride);
}

void InternalSettingsGenerated::setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds)
{
    GetSettings().SetPasswordEchoDurationInSeconds(passwordEchoDurationInSeconds);
}

void InternalSettingsGenerated::setPasswordEchoEnabled(bool passwordEchoEnabled)
{
    GetSettings().SetPasswordEchoEnabled(passwordEchoEnabled);
}

void InternalSettingsGenerated::setPictureInPictureEnabled(bool pictureInPictureEnabled)
{
    GetSettings().SetPictureInPictureEnabled(pictureInPictureEnabled);
}

void InternalSettingsGenerated::setPlaceRTLScrollbarsOnLeftSideInMainFrame(bool placeRTLScrollbarsOnLeftSideInMainFrame)
{
    GetSettings().SetPlaceRTLScrollbarsOnLeftSideInMainFrame(placeRTLScrollbarsOnLeftSideInMainFrame);
}

void InternalSettingsGenerated::setPluginsEnabled(bool pluginsEnabled)
{
    GetSettings().SetPluginsEnabled(pluginsEnabled);
}

void InternalSettingsGenerated::setPreferHiddenVolumeControls(bool preferHiddenVolumeControls)
{
    GetSettings().SetPreferHiddenVolumeControls(preferHiddenVolumeControls);
}

void InternalSettingsGenerated::setPrefersDefaultScrollbarStyles(bool prefersDefaultScrollbarStyles)
{
    GetSettings().SetPrefersDefaultScrollbarStyles(prefersDefaultScrollbarStyles);
}

void InternalSettingsGenerated::setPrefersReducedMotion(bool prefersReducedMotion)
{
    GetSettings().SetPrefersReducedMotion(prefersReducedMotion);
}

void InternalSettingsGenerated::setPrefersReducedTransparency(bool prefersReducedTransparency)
{
    GetSettings().SetPrefersReducedTransparency(prefersReducedTransparency);
}

void InternalSettingsGenerated::setPresentationReceiver(bool presentationReceiver)
{
    GetSettings().SetPresentationReceiver(presentationReceiver);
}

void InternalSettingsGenerated::setPresentationRequiresUserGesture(bool presentationRequiresUserGesture)
{
    GetSettings().SetPresentationRequiresUserGesture(presentationRequiresUserGesture);
}

void InternalSettingsGenerated::setReportScreenSizeInPhysicalPixelsQuirk(bool reportScreenSizeInPhysicalPixelsQuirk)
{
    GetSettings().SetReportScreenSizeInPhysicalPixelsQuirk(reportScreenSizeInPhysicalPixelsQuirk);
}

void InternalSettingsGenerated::setRequireTransientActivationAndAuthorizationForSubAppsAPI(bool requireTransientActivationAndAuthorizationForSubAppsAPI)
{
    GetSettings().SetRequireTransientActivationAndAuthorizationForSubAppsAPI(requireTransientActivationAndAuthorizationForSubAppsAPI);
}

void InternalSettingsGenerated::setRequireTransientActivationForGetDisplayMedia(bool requireTransientActivationForGetDisplayMedia)
{
    GetSettings().SetRequireTransientActivationForGetDisplayMedia(requireTransientActivationForGetDisplayMedia);
}

void InternalSettingsGenerated::setRequireTransientActivationForShowFileOrDirectoryPicker(bool requireTransientActivationForShowFileOrDirectoryPicker)
{
    GetSettings().SetRequireTransientActivationForShowFileOrDirectoryPicker(requireTransientActivationForShowFileOrDirectoryPicker);
}

void InternalSettingsGenerated::setResizable(bool resizable)
{
    GetSettings().SetResizable(resizable);
}

void InternalSettingsGenerated::setRubberBandingOnCompositorThread(bool rubberBandingOnCompositorThread)
{
    GetSettings().SetRubberBandingOnCompositorThread(rubberBandingOnCompositorThread);
}

void InternalSettingsGenerated::setScriptEnabled(bool scriptEnabled)
{
    GetSettings().SetScriptEnabled(scriptEnabled);
}

void InternalSettingsGenerated::setScrollAnimatorEnabled(bool scrollAnimatorEnabled)
{
    GetSettings().SetScrollAnimatorEnabled(scrollAnimatorEnabled);
}

void InternalSettingsGenerated::setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled)
{
    GetSettings().SetSelectTrailingWhitespaceEnabled(selectTrailingWhitespaceEnabled);
}

void InternalSettingsGenerated::setSelectionClipboardBufferAvailable(bool selectionClipboardBufferAvailable)
{
    GetSettings().SetSelectionClipboardBufferAvailable(selectionClipboardBufferAvailable);
}

void InternalSettingsGenerated::setSelectionIncludesAltImageText(bool selectionIncludesAltImageText)
{
    GetSettings().SetSelectionIncludesAltImageText(selectionIncludesAltImageText);
}

void InternalSettingsGenerated::setShouldClearDocumentBackground(bool shouldClearDocumentBackground)
{
    GetSettings().SetShouldClearDocumentBackground(shouldClearDocumentBackground);
}

void InternalSettingsGenerated::setShouldPrintBackgrounds(bool shouldPrintBackgrounds)
{
    GetSettings().SetShouldPrintBackgrounds(shouldPrintBackgrounds);
}

void InternalSettingsGenerated::setShouldProtectAgainstIpcFlooding(bool shouldProtectAgainstIpcFlooding)
{
    GetSettings().SetShouldProtectAgainstIpcFlooding(shouldProtectAgainstIpcFlooding);
}

void InternalSettingsGenerated::setShouldReuseGlobalForUnownedMainFrame(bool shouldReuseGlobalForUnownedMainFrame)
{
    GetSettings().SetShouldReuseGlobalForUnownedMainFrame(shouldReuseGlobalForUnownedMainFrame);
}

void InternalSettingsGenerated::setShowContextMenuOnMouseUp(bool showContextMenuOnMouseUp)
{
    GetSettings().SetShowContextMenuOnMouseUp(showContextMenuOnMouseUp);
}

void InternalSettingsGenerated::setShrinksViewportContentToFit(bool shrinksViewportContentToFit)
{
    GetSettings().SetShrinksViewportContentToFit(shrinksViewportContentToFit);
}

void InternalSettingsGenerated::setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled)
{
    GetSettings().SetSmartInsertDeleteEnabled(smartInsertDeleteEnabled);
}

void InternalSettingsGenerated::setSmoothScrollForFindEnabled(bool smoothScrollForFindEnabled)
{
    GetSettings().SetSmoothScrollForFindEnabled(smoothScrollForFindEnabled);
}

void InternalSettingsGenerated::setSpatialNavigationEnabled(bool spatialNavigationEnabled)
{
    GetSettings().SetSpatialNavigationEnabled(spatialNavigationEnabled);
}

void InternalSettingsGenerated::setSpellCheckEnabledByDefault(bool spellCheckEnabledByDefault)
{
    GetSettings().SetSpellCheckEnabledByDefault(spellCheckEnabledByDefault);
}

void InternalSettingsGenerated::setStrictMixedContentChecking(bool strictMixedContentChecking)
{
    GetSettings().SetStrictMixedContentChecking(strictMixedContentChecking);
}

void InternalSettingsGenerated::setStrictMixedContentCheckingForPlugin(bool strictMixedContentCheckingForPlugin)
{
    GetSettings().SetStrictMixedContentCheckingForPlugin(strictMixedContentCheckingForPlugin);
}

void InternalSettingsGenerated::setStrictPowerfulFeatureRestrictions(bool strictPowerfulFeatureRestrictions)
{
    GetSettings().SetStrictPowerfulFeatureRestrictions(strictPowerfulFeatureRestrictions);
}

void InternalSettingsGenerated::setStrictlyBlockBlockableMixedContent(bool strictlyBlockBlockableMixedContent)
{
    GetSettings().SetStrictlyBlockBlockableMixedContent(strictlyBlockBlockableMixedContent);
}

void InternalSettingsGenerated::setSupportsMultipleWindows(bool supportsMultipleWindows)
{
    GetSettings().SetSupportsMultipleWindows(supportsMultipleWindows);
}

void InternalSettingsGenerated::setSyncXHRInDocumentsEnabled(bool syncXHRInDocumentsEnabled)
{
    GetSettings().SetSyncXHRInDocumentsEnabled(syncXHRInDocumentsEnabled);
}

void InternalSettingsGenerated::setTargetBlankImpliesNoOpenerEnabledWillBeRemoved(bool targetBlankImpliesNoOpenerEnabledWillBeRemoved)
{
    GetSettings().SetTargetBlankImpliesNoOpenerEnabledWillBeRemoved(targetBlankImpliesNoOpenerEnabledWillBeRemoved);
}

void InternalSettingsGenerated::setTextAreasAreResizable(bool textAreasAreResizable)
{
    GetSettings().SetTextAreasAreResizable(textAreasAreResizable);
}

void InternalSettingsGenerated::setTextAutosizingEnabled(bool textAutosizingEnabled)
{
    GetSettings().SetTextAutosizingEnabled(textAutosizingEnabled);
}

void InternalSettingsGenerated::setTextTrackBackgroundColor(const String& textTrackBackgroundColor)
{
    GetSettings().SetTextTrackBackgroundColor(textTrackBackgroundColor);
}

void InternalSettingsGenerated::setTextTrackFontFamily(const String& textTrackFontFamily)
{
    GetSettings().SetTextTrackFontFamily(textTrackFontFamily);
}

void InternalSettingsGenerated::setTextTrackFontStyle(const String& textTrackFontStyle)
{
    GetSettings().SetTextTrackFontStyle(textTrackFontStyle);
}

void InternalSettingsGenerated::setTextTrackFontVariant(const String& textTrackFontVariant)
{
    GetSettings().SetTextTrackFontVariant(textTrackFontVariant);
}

void InternalSettingsGenerated::setTextTrackMarginPercentage(double textTrackMarginPercentage)
{
    GetSettings().SetTextTrackMarginPercentage(textTrackMarginPercentage);
}

void InternalSettingsGenerated::setTextTrackTextColor(const String& textTrackTextColor)
{
    GetSettings().SetTextTrackTextColor(textTrackTextColor);
}

void InternalSettingsGenerated::setTextTrackTextShadow(const String& textTrackTextShadow)
{
    GetSettings().SetTextTrackTextShadow(textTrackTextShadow);
}

void InternalSettingsGenerated::setTextTrackTextSize(const String& textTrackTextSize)
{
    GetSettings().SetTextTrackTextSize(textTrackTextSize);
}

void InternalSettingsGenerated::setTextTrackWindowColor(const String& textTrackWindowColor)
{
    GetSettings().SetTextTrackWindowColor(textTrackWindowColor);
}

void InternalSettingsGenerated::setTextTrackWindowRadius(const String& textTrackWindowRadius)
{
    GetSettings().SetTextTrackWindowRadius(textTrackWindowRadius);
}

void InternalSettingsGenerated::setTouchDragDropEnabled(bool touchDragDropEnabled)
{
    GetSettings().SetTouchDragDropEnabled(touchDragDropEnabled);
}

void InternalSettingsGenerated::setTouchDragEndContextMenu(bool touchDragEndContextMenu)
{
    GetSettings().SetTouchDragEndContextMenu(touchDragEndContextMenu);
}

void InternalSettingsGenerated::setTouchEditingEnabled(bool touchEditingEnabled)
{
    GetSettings().SetTouchEditingEnabled(touchEditingEnabled);
}

void InternalSettingsGenerated::setUseAXMenuList(bool useAXMenuList)
{
    GetSettings().SetUseAXMenuList(useAXMenuList);
}

void InternalSettingsGenerated::setUseWideViewport(bool useWideViewport)
{
    GetSettings().SetUseWideViewport(useWideViewport);
}

void InternalSettingsGenerated::setValidationMessageTimerMagnification(int validationMessageTimerMagnification)
{
    GetSettings().SetValidationMessageTimerMagnification(validationMessageTimerMagnification);
}

void InternalSettingsGenerated::setViewportEnabled(bool viewportEnabled)
{
    GetSettings().SetViewportEnabled(viewportEnabled);
}

void InternalSettingsGenerated::setViewportMetaEnabled(bool viewportMetaEnabled)
{
    GetSettings().SetViewportMetaEnabled(viewportMetaEnabled);
}

void InternalSettingsGenerated::setViewportMetaMergeContentQuirk(bool viewportMetaMergeContentQuirk)
{
    GetSettings().SetViewportMetaMergeContentQuirk(viewportMetaMergeContentQuirk);
}

void InternalSettingsGenerated::setViewportMetaZeroValuesQuirk(bool viewportMetaZeroValuesQuirk)
{
    GetSettings().SetViewportMetaZeroValuesQuirk(viewportMetaZeroValuesQuirk);
}

void InternalSettingsGenerated::setWebAppScope(const String& webAppScope)
{
    GetSettings().SetWebAppScope(webAppScope);
}

void InternalSettingsGenerated::setWebGL1Enabled(bool webGL1Enabled)
{
    GetSettings().SetWebGL1Enabled(webGL1Enabled);
}

void InternalSettingsGenerated::setWebGL2Enabled(bool webGL2Enabled)
{
    GetSettings().SetWebGL2Enabled(webGL2Enabled);
}

void InternalSettingsGenerated::setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled)
{
    GetSettings().SetWebGLErrorsToConsoleEnabled(webGLErrorsToConsoleEnabled);
}

void InternalSettingsGenerated::setWebSecurityEnabled(bool webSecurityEnabled)
{
    GetSettings().SetWebSecurityEnabled(webSecurityEnabled);
}

void InternalSettingsGenerated::setWideViewportQuirkEnabled(bool wideViewportQuirkEnabled)
{
    GetSettings().SetWideViewportQuirkEnabled(wideViewportQuirkEnabled);
}

void InternalSettingsGenerated::Trace(Visitor* visitor) const
{
    ScriptWrappable::Trace(visitor);
    InternalSettingsPageSupplementBase::Trace(visitor);
}

Settings& InternalSettingsGenerated::GetSettings()
{
    CHECK(GetSupplementable());
    return GetSupplementable()->GetSettings();
}

} // namespace blink
