// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/internal_settings_generated.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/frame/settings.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_SETTINGS_GENERATED_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_SETTINGS_GENERATED_H_

#include "base/memory/scoped_refptr.h"
#include "third_party/blink/renderer/core/frame/settings.h"
#include "third_party/blink/renderer/core/page/page.h"
#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/heap/member.h"
#include "third_party/blink/renderer/platform/wtf/ref_counted.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class InternalSettingsGenerated : public ScriptWrappable, public InternalSettingsPageSupplementBase {
    DEFINE_WRAPPERTYPEINFO();

public:
    explicit InternalSettingsGenerated(Page&);
    virtual ~InternalSettingsGenerated();

    void setDOMPasteAllowed(bool DOMPasteAllowed);
    void setDontSendKeyEventsToJavascript(bool DontSendKeyEventsToJavascript);
    void setHighlightAds(bool HighlightAds);
    void setNetworkQuietTimeout(double NetworkQuietTimeout);
    void setWebXRImmersiveArAllowed(bool WebXRImmersiveArAllowed);
    void setAccelerated2dCanvasMSAASampleCount(int accelerated2dCanvasMSAASampleCount);
    void setAcceleratedCompositingEnabled(bool acceleratedCompositingEnabled);
    void setAccessibilityAlwaysShowFocus(bool accessibilityAlwaysShowFocus);
    void setAccessibilityFontScaleFactor(double accessibilityFontScaleFactor);
    void setAccessibilityFontWeightAdjustment(int accessibilityFontWeightAdjustment);
    void setAccessibilityIncludeSvgGElement(bool accessibilityIncludeSvgGElement);
    void setAccessibilityPasswordValuesEnabled(bool accessibilityPasswordValuesEnabled);
    void setAccessibilityTextSizeContrastFactor(int accessibilityTextSizeContrastFactor);
    void setAllowCustomScrollbarInMainFrame(bool allowCustomScrollbarInMainFrame);
    void setAllowFileAccessFromFileURLs(bool allowFileAccessFromFileURLs);
    void setAllowGeolocationOnInsecureOrigins(bool allowGeolocationOnInsecureOrigins);
    void setAllowNonEmptyNavigatorPlugins(bool allowNonEmptyNavigatorPlugins);
    void setAllowRunningOfInsecureContent(bool allowRunningOfInsecureContent);
    void setAllowScriptsToCloseWindows(bool allowScriptsToCloseWindows);
    void setAllowUniversalAccessFromFileURLs(bool allowUniversalAccessFromFileURLs);
    void setAlwaysShowContextMenuOnTouch(bool alwaysShowContextMenuOnTouch);
    void setAntialiased2dCanvasEnabled(bool antialiased2dCanvasEnabled);
    void setAntialiasedClips2dCanvasEnabled(bool antialiasedClips2dCanvasEnabled);
    void setAriaModalPrunesAXTree(bool ariaModalPrunesAXTree);
    void setAvailableHoverTypes(int availableHoverTypes);
    void setAvailablePointerTypes(int availablePointerTypes);
    void setBarrelButtonForDragEnabled(bool barrelButtonForDragEnabled);
    void setBypassCSP(bool bypassCSP);
    void setCaretBrowsingEnabled(bool caretBrowsingEnabled);
    void setCookieEnabled(bool cookieEnabled);
    void setDefaultFixedFontSize(int defaultFixedFontSize);
    void setDefaultFontSize(int defaultFontSize);
    void setDefaultTextEncodingName(const String& defaultTextEncodingName);
    void setDefaultVideoPosterURL(const String& defaultVideoPosterURL);
    void setDeviceScaleAdjustment(double deviceScaleAdjustment);
    void setDisableReadingFromCanvas(bool disableReadingFromCanvas);
    void setDisallowFetchForDocWrittenScriptsInMainFrame(bool disallowFetchForDocWrittenScriptsInMainFrame);
    void setDisallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G(bool disallowFetchForDocWrittenScriptsInMainFrameIfEffectively2G);
    void setDisallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections(bool disallowFetchForDocWrittenScriptsInMainFrameOnSlowConnections);
    void setDNSPrefetchingEnabled(bool dnsPrefetchingEnabled);
    void setDoHtmlPreloadScanning(bool doHtmlPreloadScanning);
    void setDoNotUpdateSelectionOnMutatingSelectionRange(bool doNotUpdateSelectionOnMutatingSelectionRange);
    void setDownloadableBinaryFontsEnabled(bool downloadableBinaryFontsEnabled);
    void setDynamicSafeAreaInsetsEnabled(bool dynamicSafeAreaInsetsEnabled);
    void setEmbeddedMediaExperienceEnabled(bool embeddedMediaExperienceEnabled);
    void setForceAndroidOverlayScrollbar(bool forceAndroidOverlayScrollbar);
    void setForceDarkModeEnabled(bool forceDarkModeEnabled);
    void setForceMainWorldInitialization(bool forceMainWorldInitialization);
    void setForceTouchEventFeatureDetectionForInspector(bool forceTouchEventFeatureDetectionForInspector);
    void setForceZeroLayoutHeight(bool forceZeroLayoutHeight);
    void setFullscreenSupported(bool fullscreenSupported);
    void setHideDownloadUI(bool hideDownloadUI);
    void setHideScrollbars(bool hideScrollbars);
    void setHyperlinkAuditingEnabled(bool hyperlinkAuditingEnabled);
    void setIgnoreMainFrameOverflowHiddenQuirk(bool ignoreMainFrameOverflowHiddenQuirk);
    void setImagesEnabled(bool imagesEnabled);
    void setImmersiveModeEnabled(bool immersiveModeEnabled);
    void setInForcedColors(bool inForcedColors);
    void setInvertedColors(bool invertedColors);
    void setIsForcedColorsDisabled(bool isForcedColorsDisabled);
    void setJavaScriptCanAccessClipboard(bool javaScriptCanAccessClipboard);
    void setLazyLoadEnabled(bool lazyLoadEnabled);
    void setLazyLoadingFrameMarginPx2G(int lazyLoadingFrameMarginPx2G);
    void setLazyLoadingFrameMarginPx3G(int lazyLoadingFrameMarginPx3G);
    void setLazyLoadingFrameMarginPx4G(int lazyLoadingFrameMarginPx4G);
    void setLazyLoadingFrameMarginPxOffline(int lazyLoadingFrameMarginPxOffline);
    void setLazyLoadingFrameMarginPxSlow2G(int lazyLoadingFrameMarginPxSlow2G);
    void setLazyLoadingFrameMarginPxUnknown(int lazyLoadingFrameMarginPxUnknown);
    void setLazyLoadingImageMarginPx2G(int lazyLoadingImageMarginPx2G);
    void setLazyLoadingImageMarginPx3G(int lazyLoadingImageMarginPx3G);
    void setLazyLoadingImageMarginPx4G(int lazyLoadingImageMarginPx4G);
    void setLazyLoadingImageMarginPxOffline(int lazyLoadingImageMarginPxOffline);
    void setLazyLoadingImageMarginPxSlow2G(int lazyLoadingImageMarginPxSlow2G);
    void setLazyLoadingImageMarginPxUnknown(int lazyLoadingImageMarginPxUnknown);
    void setLoadWithOverviewMode(bool loadWithOverviewMode);
    void setLoadsImagesAutomatically(bool loadsImagesAutomatically);
    void setLocalStorageEnabled(bool localStorageEnabled);
    void setLogDnsPrefetchAndPreconnect(bool logDnsPrefetchAndPreconnect);
    void setLogPreload(bool logPreload);
    void setMainFrameClipsContent(bool mainFrameClipsContent);
    void setMainFrameResizesAreOrientationChanges(bool mainFrameResizesAreOrientationChanges);
    void setMaxTouchPoints(int maxTouchPoints);
    void setMediaControlsEnabled(bool mediaControlsEnabled);
    void setMediaTypeOverride(const String& mediaTypeOverride);
    void setMinimumFontSize(int minimumFontSize);
    void setMinimumLogicalFontSize(int minimumLogicalFontSize);
    void setMockGestureTapHighlightsEnabled(bool mockGestureTapHighlightsEnabled);
    void setModalContextMenu(bool modalContextMenu);
    void setMultiTargetTapNotificationEnabled(bool multiTargetTapNotificationEnabled);
    void setNavigateOnDragDrop(bool navigateOnDragDrop);
    void setNavigatorPlatformOverride(const String& navigatorPlatformOverride);
    void setPasswordEchoDurationInSeconds(double passwordEchoDurationInSeconds);
    void setPasswordEchoEnabled(bool passwordEchoEnabled);
    void setPictureInPictureEnabled(bool pictureInPictureEnabled);
    void setPlaceRTLScrollbarsOnLeftSideInMainFrame(bool placeRTLScrollbarsOnLeftSideInMainFrame);
    void setPluginsEnabled(bool pluginsEnabled);
    void setPreferHiddenVolumeControls(bool preferHiddenVolumeControls);
    void setPrefersDefaultScrollbarStyles(bool prefersDefaultScrollbarStyles);
    void setPrefersReducedMotion(bool prefersReducedMotion);
    void setPrefersReducedTransparency(bool prefersReducedTransparency);
    void setPresentationReceiver(bool presentationReceiver);
    void setPresentationRequiresUserGesture(bool presentationRequiresUserGesture);
    void setReportScreenSizeInPhysicalPixelsQuirk(bool reportScreenSizeInPhysicalPixelsQuirk);
    void setRequireTransientActivationAndAuthorizationForSubAppsAPI(bool requireTransientActivationAndAuthorizationForSubAppsAPI);
    void setRequireTransientActivationForGetDisplayMedia(bool requireTransientActivationForGetDisplayMedia);
    void setRequireTransientActivationForShowFileOrDirectoryPicker(bool requireTransientActivationForShowFileOrDirectoryPicker);
    void setResizable(bool resizable);
    void setRubberBandingOnCompositorThread(bool rubberBandingOnCompositorThread);
    void setScriptEnabled(bool scriptEnabled);
    void setScrollAnimatorEnabled(bool scrollAnimatorEnabled);
    void setSelectTrailingWhitespaceEnabled(bool selectTrailingWhitespaceEnabled);
    void setSelectionClipboardBufferAvailable(bool selectionClipboardBufferAvailable);
    void setSelectionIncludesAltImageText(bool selectionIncludesAltImageText);
    void setShouldClearDocumentBackground(bool shouldClearDocumentBackground);
    void setShouldPrintBackgrounds(bool shouldPrintBackgrounds);
    void setShouldProtectAgainstIpcFlooding(bool shouldProtectAgainstIpcFlooding);
    void setShouldReuseGlobalForUnownedMainFrame(bool shouldReuseGlobalForUnownedMainFrame);
    void setShowContextMenuOnMouseUp(bool showContextMenuOnMouseUp);
    void setShrinksViewportContentToFit(bool shrinksViewportContentToFit);
    void setSmartInsertDeleteEnabled(bool smartInsertDeleteEnabled);
    void setSmoothScrollForFindEnabled(bool smoothScrollForFindEnabled);
    void setSpatialNavigationEnabled(bool spatialNavigationEnabled);
    void setSpellCheckEnabledByDefault(bool spellCheckEnabledByDefault);
    void setStrictMixedContentChecking(bool strictMixedContentChecking);
    void setStrictMixedContentCheckingForPlugin(bool strictMixedContentCheckingForPlugin);
    void setStrictPowerfulFeatureRestrictions(bool strictPowerfulFeatureRestrictions);
    void setStrictlyBlockBlockableMixedContent(bool strictlyBlockBlockableMixedContent);
    void setSupportsMultipleWindows(bool supportsMultipleWindows);
    void setSyncXHRInDocumentsEnabled(bool syncXHRInDocumentsEnabled);
    void setTargetBlankImpliesNoOpenerEnabledWillBeRemoved(bool targetBlankImpliesNoOpenerEnabledWillBeRemoved);
    void setTextAreasAreResizable(bool textAreasAreResizable);
    void setTextAutosizingEnabled(bool textAutosizingEnabled);
    void setTextTrackBackgroundColor(const String& textTrackBackgroundColor);
    void setTextTrackFontFamily(const String& textTrackFontFamily);
    void setTextTrackFontStyle(const String& textTrackFontStyle);
    void setTextTrackFontVariant(const String& textTrackFontVariant);
    void setTextTrackMarginPercentage(double textTrackMarginPercentage);
    void setTextTrackTextColor(const String& textTrackTextColor);
    void setTextTrackTextShadow(const String& textTrackTextShadow);
    void setTextTrackTextSize(const String& textTrackTextSize);
    void setTextTrackWindowColor(const String& textTrackWindowColor);
    void setTextTrackWindowRadius(const String& textTrackWindowRadius);
    void setTouchDragDropEnabled(bool touchDragDropEnabled);
    void setTouchDragEndContextMenu(bool touchDragEndContextMenu);
    void setTouchEditingEnabled(bool touchEditingEnabled);
    void setUseAXMenuList(bool useAXMenuList);
    void setUseWideViewport(bool useWideViewport);
    void setValidationMessageTimerMagnification(int validationMessageTimerMagnification);
    void setViewportEnabled(bool viewportEnabled);
    void setViewportMetaEnabled(bool viewportMetaEnabled);
    void setViewportMetaMergeContentQuirk(bool viewportMetaMergeContentQuirk);
    void setViewportMetaZeroValuesQuirk(bool viewportMetaZeroValuesQuirk);
    void setWebAppScope(const String& webAppScope);
    void setWebGL1Enabled(bool webGL1Enabled);
    void setWebGL2Enabled(bool webGL2Enabled);
    void setWebGLErrorsToConsoleEnabled(bool webGLErrorsToConsoleEnabled);
    void setWebSecurityEnabled(bool webSecurityEnabled);
    void setWideViewportQuirkEnabled(bool wideViewportQuirkEnabled);

    void Trace(Visitor*) const override;

protected:
    Settings& GetSettings();

    // Resets all settings to be the initial state when this is constructed.
    // This also includes settings without an idl type (thus without an
    // automatically generated setter method in this class), in case the settings
    // are changed by custom methods defined in InternalSettings.
    void ResetToConsistentState();

private:
    Settings backup_;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_TESTING_INTERNAL_SETTINGS_GENERATED_H_
