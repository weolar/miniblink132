
#ifndef content_browser_local_frame_host_impl_h
#define content_browser_local_frame_host_impl_h

#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/frame.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/context_menu/context_menu.mojom-blink.h"
#include "mojo/public/cpp/bindings/remote.h"

namespace content {

class WebLocalFrameClientImpl;
class MbWebView;

class LocalFrameHostImpl : public ::blink::mojom::blink::LocalFrameHost {
public:
    LocalFrameHostImpl(WebLocalFrameClientImpl* frameClient);
    ~LocalFrameHostImpl();

    virtual void EnterFullscreen(
        ::blink::mojom::blink::FullscreenOptionsPtr options, ::blink::mojom::blink::LocalFrameHost::EnterFullscreenCallback callback) override;

    virtual void ExitFullscreen() override;

    virtual void FullscreenStateChanged(bool is_fullscreen, ::blink::mojom::blink::FullscreenOptionsPtr options) override;

    virtual void RegisterProtocolHandler(const WTF::String& scheme, const ::blink::KURL& url, bool user_gesture) override;

    virtual void UnregisterProtocolHandler(const WTF::String& scheme, const ::blink::KURL& url, bool user_gesture) override;

    virtual void DidDisplayInsecureContent() override;

    virtual void DidContainInsecureFormAction() override;

    virtual void MainDocumentElementAvailable(bool uses_temporary_zoom_level) override;

    virtual void SetNeedsOcclusionTracking(bool needs_tracking) override;

    virtual void SetVirtualKeyboardMode(::ui::mojom::blink::VirtualKeyboardMode type) override;

    virtual void VisibilityChanged(::blink::mojom::blink::FrameVisibility visibility) override;

    virtual void DidChangeThemeColor(absl::optional<::SkColor> theme_color) override;

    virtual void DidChangeBackgroundColor(const ::SkColor4f& background_color, bool color_adjust) override;

    virtual void DidFailLoadWithError(const ::blink::KURL& url, int32_t error_code) override;

    virtual void DidFocusFrame() override;

    virtual void DidCallFocus() override;

    virtual void EnforceInsecureRequestPolicy(::blink::mojom::blink::InsecureRequestPolicy policy_bitmap) override;

    virtual void EnforceInsecureNavigationsSet(const WTF::Vector<uint32_t>& set) override;

    virtual void SuddenTerminationDisablerChanged(bool present, ::blink::mojom::blink::SuddenTerminationDisablerType disabler_type) override;

    virtual void HadStickyUserActivationBeforeNavigationChanged(bool has_gesture) override;

    virtual void ScrollRectToVisibleInParentFrame(const ::gfx::RectF& rect_to_scroll, ::blink::mojom::blink::ScrollIntoViewParamsPtr params) override;

    virtual void BubbleLogicalScrollInParentFrame(::blink::mojom::blink::ScrollDirection direction, ::ui::ScrollGranularity granularity) override;

    virtual void DidBlockNavigation(
        const ::blink::KURL& blocked_url, const ::blink::KURL& initiator_url, ::blink::mojom::blink::NavigationBlockedReason reason) override;

    virtual void DidChangeLoadProgress(double load_progress) override;

    virtual void DidFinishLoad(const ::blink::KURL& validated_url) override;

    virtual void DispatchLoad() override;

    virtual void GoToEntryAtOffset(int32_t offset, bool has_user_gesture, 
        std::optional<::blink::scheduler::TaskAttributionId> soft_navigation_heuristics_task_id) override;

    virtual void NavigateToNavigationApiKey(const WTF::String& key, bool has_user_gesture,
        std::optional<::blink::scheduler::TaskAttributionId> soft_navigation_heuristics_task_id) override;

    virtual void UpdateTitle(const ::WTF::String& title, ::base::i18n::TextDirection title_direction) override;

    virtual void UpdateUserActivationState(
        ::blink::mojom::blink::UserActivationUpdateType update_type, ::blink::mojom::blink::UserActivationNotificationType notification_type) override;

    virtual void HandleAccessibilityFindInPageResult(::blink::mojom::blink::FindInPageResultAXParamsPtr params) override;

    virtual void HandleAccessibilityFindInPageTermination() override;

    virtual void DocumentOnLoadCompleted() override;

    virtual void ForwardResourceTimingToParent(::blink::mojom::blink::ResourceTimingInfoPtr timing) override;

    virtual void DidDispatchDOMContentLoadedEvent() override;

    virtual bool RunModalAlertDialog(const ::WTF::String& alert_message, bool disable_third_party_subframe_suppresion) override;

    virtual void RunModalAlertDialog(const ::WTF::String& alert_message, bool disable_third_party_subframe_suppresion,
        ::blink::mojom::blink::LocalFrameHost::RunModalAlertDialogCallback callback) override;

    // Sync method. This signature is used by the client side; the service side
    // should implement the signature with callback below.

    virtual bool RunModalConfirmDialog(const ::WTF::String& alert_message, bool disable_third_party_subframe_suppresion, bool* out_success) override;

    virtual void RunModalConfirmDialog(const ::WTF::String& alert_message, bool disable_third_party_subframe_suppresion,
        ::blink::mojom::blink::LocalFrameHost::RunModalConfirmDialogCallback callback) override;

    // Sync method. This signature is used by the client side; the service side
    // should implement the signature with callback below.

    virtual bool RunModalPromptDialog(const ::WTF::String& alert_message, const ::WTF::String& default_value, bool disable_third_party_subframe_suppresion,
        bool* out_success, ::WTF::String* out_result) override;

    virtual void RunModalPromptDialog(const ::WTF::String& alert_message, const ::WTF::String& default_value, bool disable_third_party_subframe_suppresion,
        ::blink::mojom::blink::LocalFrameHost::RunModalPromptDialogCallback callback) override;

    // Sync method. This signature is used by the client side; the service side
    // should implement the signature with callback below.

    virtual bool RunBeforeUnloadConfirm(bool is_reload, bool* out_success) override;

    virtual void RunBeforeUnloadConfirm(bool is_reload, ::blink::mojom::blink::LocalFrameHost::RunBeforeUnloadConfirmCallback callback) override;

    virtual void UpdateFaviconURL(WTF::Vector<::blink::mojom::blink::FaviconURLPtr> favicon_urls) override;

    virtual void DownloadURL(::blink::mojom::blink::DownloadURLParamsPtr params) override;

    virtual void FocusedElementChanged(
        bool is_editable_element, bool is_richly_editable_element, const ::gfx::Rect& bounds_in_frame_widget, ::blink::mojom::blink::FocusType focus_type) override;

    virtual void TextSelectionChanged(const ::WTF::String& text, uint32_t offset, const ::gfx::Range& range) override;

    virtual void ShowPopupMenu(::mojo::PendingRemote<::blink::mojom::blink::PopupMenuClient> popup_client, const ::gfx::Rect& bounds, int32_t item_height,
        double font_size, int32_t selected_item, WTF::Vector<::blink::mojom::blink::MenuItemPtr> menu_items, bool right_aligned,
        bool allow_multiple_selection) override;

    virtual void CreateNewPopupWidget(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> popup_host,
        ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::WidgetHost> blink_widget_host,
        ::mojo::PendingAssociatedRemote<::blink::mojom::blink::Widget> blink_widget) override;

    virtual void ShowContextMenu(
        ::mojo::PendingAssociatedRemote<::blink::mojom::blink::ContextMenuClient> client, const ::blink::UntrustworthyContextMenuParams& params) override;

    virtual void DidLoadResourceFromMemoryCache(const ::blink::KURL& url, const WTF::String& http_method, const WTF::String& mime_type,
        ::network::mojom::blink::RequestDestination request_destination, bool include_credentials) override;

    virtual void DidChangeFrameOwnerProperties(
        const ::blink::FrameToken& child_frame_token, ::blink::mojom::blink::FrameOwnerPropertiesPtr frame_owner_properties) override;

    virtual void DidChangeOpener(const absl::optional<::blink::LocalFrameToken>& opener_frame) override;

    virtual void DidChangeFramePolicy(const ::blink::FrameToken& child_frame_token, const ::blink::FramePolicy& frame_policy) override;

    virtual void DidChangeIframeAttributes(const ::blink::FrameToken& child_frame_token, ::blink::mojom::blink::IframeAttributesPtr attributes) override;

    virtual void CapturePaintPreviewOfSubframe(const ::gfx::Rect& clip_rect, const ::base::UnguessableToken& guid) override;

    virtual void SetCloseListener(::mojo::PendingRemote<::blink::mojom::blink::CloseListener> listener) override;

    virtual void Detach() override;

    virtual void GetKeepAliveHandleFactory(::mojo::PendingReceiver<::blink::mojom::blink::KeepAliveHandleFactory> factory) override;

    virtual void DidAddMessageToConsole(::blink::mojom::blink::ConsoleMessageLevel log_level, const ::WTF::String& msg, uint32_t line_number,
        const ::WTF::String& source_id, const ::WTF::String& untrusted_stack_trace) override;

    virtual void FrameSizeChanged(const ::gfx::Size& size) override;

    virtual void DidInferColorScheme(::blink::mojom::blink::PreferredColorScheme color_scheme) override;

    virtual void DidChangeSrcDoc(const ::blink::FrameToken& child_frame_token, const WTF::String& srcdoc_value) override;

    virtual void DidChangeBaseURL(const ::blink::KURL& base_url) /*override*/;

    virtual void ReceivedDelegatedCapability(::blink::mojom::blink::DelegatedCapability delegated_capability) override;

//     virtual bool CreatePortal(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::Portal> portal,
//         ::mojo::PendingAssociatedRemote<::blink::mojom::blink::PortalClient> client,
//         ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces,
//         ::blink::mojom::blink::FrameReplicationStatePtr* out_initial_replicated_state, ::blink::PortalToken* out_portal_token,
//         ::blink::RemoteFrameToken* out_frame_token, ::base::UnguessableToken* out_devtools_frame_token) override;
// 
//     virtual void CreatePortal(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::Portal> portal,
//         ::mojo::PendingAssociatedRemote<::blink::mojom::blink::PortalClient> client,
//         ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, CreatePortalCallback callback) override;

//     virtual bool AdoptPortal(const ::blink::PortalToken& portal_token, ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces,
//         ::blink::mojom::blink::FrameReplicationStatePtr* out_replicated_state, ::blink::RemoteFrameToken* out_frame_token,
//         ::base::UnguessableToken* out_devtools_frame_token) override;
// 
//     virtual void AdoptPortal(const ::blink::PortalToken& portal_token, ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces,
//         AdoptPortalCallback callback) override;

    virtual void CreateFencedFrame(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::FencedFrameOwnerHost> fenced_frame,
        ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, const ::blink::RemoteFrameToken& frame_token,
        const ::base::UnguessableToken& devtools_frame_token) override;

    virtual void StartLoadingForAsyncNavigationApiCommit() override;
    virtual void NavigateEventHandlerPresenceChanged(bool present) override;
    virtual void UpdateAppTitle(const ::WTF::String& app_title) override;
    virtual void DidConsumeHistoryUserActivation() override;
    virtual void SendFencedFrameReportingBeacon(const WTF::String& event_data, const WTF::String& event_type,
        const WTF::Vector<::blink::FencedFrame::ReportingDestination>& destinations, bool cross_origin_exposed) override;
    virtual void SendFencedFrameReportingBeaconToCustomURL(const ::blink::KURL& destination_url, bool cross_origin_exposed) override;
    virtual void DisableUntrustedNetworkInFencedFrame(DisableUntrustedNetworkInFencedFrameCallback callback) override;
    virtual void ExemptUrlFromNetworkRevocationForTesting(const ::blink::KURL& exempted_url, ExemptUrlFromNetworkRevocationForTestingCallback callback) override;
    virtual void SendLegacyTechEvent(const WTF::String& type, ::blink::mojom::blink::LegacyTechEventCodeLocationPtr code_location) override;
    virtual void SetFencedFrameAutomaticBeaconReportEventData(::blink::mojom::blink::AutomaticBeaconType event_type, const WTF::String& event_data,
        const WTF::Vector<::blink::FencedFrame::ReportingDestination>& destinations, bool once, bool cross_origin_exposed) override;
    virtual void SendPrivateAggregationRequestsForFencedFrameEvent(const WTF::String& event_type) override;
    virtual void ForwardFencedFrameEventAndUserActivationToEmbedder(const WTF::String& event_type) override;
    virtual void OnViewTransitionOptInChanged(::blink::mojom::blink::ViewTransitionSameOriginOptIn view_transition_opt_in) override;

    virtual void StartDragging(const ::blink::WebDragData& drag_data, ::blink::DragOperationsMask operations_allowed, const ::SkBitmap& image,
        const ::gfx::Vector2d& cursor_offset_in_dip, const ::gfx::Rect& drag_obj_rect_in_dip, ::blink::mojom::blink::DragEventSourceInfoPtr event_info)
        override;

    virtual void IssueKeepAliveHandle(::mojo::PendingReceiver<::blink::mojom::blink::NavigationStateKeepAliveHandle> receiver) override;

    virtual void NotifyStorageAccessed(::blink::mojom::blink::StorageTypeAccessed storageType, bool blocked) override;

    virtual void RecordWindowProxyUsageMetrics(const ::blink::FrameToken& target_frame_token, ::blink::mojom::blink::WindowProxyAccessType access_type) override;

    virtual void NotifyDocumentInteractive() override;

private:
    MbWebView* getMbWebView() const;
    WebLocalFrameClientImpl* m_frameClient;

    mojo::AssociatedRemote<::blink::mojom::blink::ContextMenuClient>* m_contextMenuClient = nullptr;
};
}

#endif