
#include "content/browser/LocalFrameHostImpl.h"

#include "content/browser/MbWebview.h"
#include "content/browser/MbWebview.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/common.h"
#include "content/common/CreateAndBindTempl.h"
#include "content/common/ThreadCall.h"
#include "content/ui/ContextMeun.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/mojom/frame/remote_frame.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/frame_owner_properties.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/fullscreen.mojom-blink.h"
#include "third_party/blink/public/mojom/timing/resource_timing.mojom-blink.h"
#include "third_party/blink/public/mojom/scroll/scroll_into_view_params.mojom-blink.h"
#include "third_party/blink/public/mojom/choosers/popup_menu.mojom-blink.h"
#include "third_party/blink/public/mojom/favicon/favicon_url.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/keep_alive_handle.mojom-blink.h"
#include "third_party/blink/public/mojom/loader/keep_alive_handle_factory.mojom-blink.h"
#include "base/notreached.h"
#include "base/strings/utf_string_conversions.h"

bool blink::mojom::blink::LocalFrameHost::RunModalAlertDialog(class WTF::String const&, bool)
{
    NOTREACHED();
    return false;
}

bool blink::mojom::blink::LocalFrameHost::RunModalConfirmDialog(class WTF::String const&, bool, bool*)
{
    NOTREACHED();
    return false;
}

bool blink::mojom::blink::LocalFrameHost::RunModalPromptDialog(class WTF::String const&, class WTF::String const&, bool, bool*, class WTF::String*)
{
    NOTREACHED();
    return false;
}

bool blink::mojom::blink::LocalFrameHost::RunBeforeUnloadConfirm(bool, bool*)
{
    NOTREACHED();
    return false;
}

namespace content {

LocalFrameHostImpl::LocalFrameHostImpl(WebLocalFrameClientImpl* frameClient)
    : m_frameClient(frameClient)
{
    base::SequencedTaskRunner::GetCurrentDefault()->PostNonNestableDelayedTask(MB_FROM_HERE,
        base::BindOnce([]() { ContextMenu::get();}), base::Seconds(3)); // 延迟后初始化一下，这样真正弹出菜单的时候不会抢焦点了

}

LocalFrameHostImpl::~LocalFrameHostImpl()
{
}

void LocalFrameHostImpl::EnterFullscreen(
    ::blink::mojom::blink::FullscreenOptionsPtr options, ::blink::mojom::blink::LocalFrameHost::EnterFullscreenCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::ExitFullscreen()
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::FullscreenStateChanged(bool is_fullscreen, ::blink::mojom::blink::FullscreenOptionsPtr options)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::RegisterProtocolHandler(const WTF::String& scheme, const ::blink::KURL& url, bool user_gesture)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::UnregisterProtocolHandler(const WTF::String& scheme, const ::blink::KURL& url, bool user_gesture)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidDisplayInsecureContent()
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidContainInsecureFormAction()
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::MainDocumentElementAvailable(bool uses_temporary_zoom_level)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SetNeedsOcclusionTracking(bool needs_tracking)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::SetVirtualKeyboardMode(::ui::mojom::blink::VirtualKeyboardMode type)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::VisibilityChanged(::blink::mojom::blink::FrameVisibility visibility)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidChangeThemeColor(absl::optional<::SkColor> theme_color)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidChangeBackgroundColor(const ::SkColor4f& background_color, bool color_adjust)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidFailLoadWithError(const ::blink::KURL& url, int32_t error_code)
{
    printFuncName(__FUNCTION__, true, false);
    if (!m_frameClient)
        return;
    mbWebView webviewHandle = m_frameClient->getMbwebviewId();
    intptr_t id = m_frameClient->getFrameId();
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview || !webview->getClosure().m_LoadingFinishCallback)
        return;

    std::string* urlStr = new std::string(url.GetString().Utf8());
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webviewHandle, urlStr, id]() {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview)
            webview->getClosure().m_LoadingFinishCallback(
                webviewHandle, webview->getClosure().m_LoadingFinishParam, (mbWebFrameHandle)id, urlStr->c_str(), MB_LOADING_FAILED, "");
        delete urlStr;
    });
}

void LocalFrameHostImpl::DidFocusFrame()
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidCallFocus()
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::EnforceInsecureRequestPolicy(::blink::mojom::blink::InsecureRequestPolicy policy_bitmap)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::EnforceInsecureNavigationsSet(const WTF::Vector<uint32_t>& set)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SuddenTerminationDisablerChanged(bool present, ::blink::mojom::blink::SuddenTerminationDisablerType disabler_type)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::HadStickyUserActivationBeforeNavigationChanged(bool has_gesture)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::ScrollRectToVisibleInParentFrame(const ::gfx::RectF& rect_to_scroll, ::blink::mojom::blink::ScrollIntoViewParamsPtr params)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::BubbleLogicalScrollInParentFrame(::blink::mojom::blink::ScrollDirection direction, ::ui::ScrollGranularity granularity)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidBlockNavigation(
    const ::blink::KURL& blocked_url, const ::blink::KURL& initiator_url, ::blink::mojom::blink::NavigationBlockedReason reason)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidChangeLoadProgress(double load_progress)
{
    char* output = (char*)malloc(0x100);
    sprintf(output, "LocalFrameHostImpl::DidChangeLoadProgress: %f\n", (float)load_progress);
    OutputDebugStringA(output);
    free(output);
}

void LocalFrameHostImpl::DidFinishLoad(const ::blink::KURL& validatedUrl)
{
    printFuncName(__FUNCTION__, false, false);
    if (!m_frameClient)
        return;

    //     mbWebView webviewHandle = m_frameClient->getMbwebviewId();
    //     mb::MbWebView* webview = (mb::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_frameClient->getMbwebviewId());
    //     if (!webview)
    //         return;
    //     webview->getClosure().m_URLChangedCallback(
    //         webviewHandle,
    //         webview->getClosure().m_URLChangedParam, validatedUrl.GetString().Utf8().c_str(), FALSE/*canGoBack*/, FALSE/*canGoForward*/);
}

void LocalFrameHostImpl::DispatchLoad()
{
    printFuncName(__FUNCTION__, true, false);
}

MbWebView* LocalFrameHostImpl::getMbWebView() const
{
    if (!m_frameClient)
        return nullptr;

    mbWebView webviewHandle = m_frameClient->getMbwebviewId();
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    return webview;
}

void LocalFrameHostImpl::GoToEntryAtOffset(int32_t offset, bool has_user_gesture, std::optional<::blink::scheduler::TaskAttributionId> soft_navigation_heuristics_task_id)
{
    //printFuncName(__FUNCTION__, true, false);
    MbWebView* webview = getMbWebView();
    if (webview)
        webview->navigateBackForwardSoon(offset);
}

void LocalFrameHostImpl::NavigateToNavigationApiKey(const WTF::String& key, bool has_user_gesture, std::optional<::blink::scheduler::TaskAttributionId> soft_navigation_heuristics_task_id)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::UpdateTitle(const ::WTF::String& title, ::base::i18n::TextDirection titleDirection)
{
    printFuncName(__FUNCTION__, false, false);
    if (!m_frameClient)
        return;

    mbWebView webviewHandle = m_frameClient->getMbwebviewId();
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    std::string* titleStr = new std::string(title.Utf8());
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webviewHandle, titleStr]() {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview) {
            webview->setWindowTitle(*titleStr);
            if (webview->getClosure().m_TitleChangedCallback)
                webview->getClosure().m_TitleChangedCallback(webviewHandle, webview->getClosure().m_TitleChangedParam, titleStr->c_str());
        }
        delete titleStr;
    });
}

void LocalFrameHostImpl::UpdateUserActivationState(
    ::blink::mojom::blink::UserActivationUpdateType update_type, ::blink::mojom::blink::UserActivationNotificationType notification_type)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::HandleAccessibilityFindInPageResult(::blink::mojom::blink::FindInPageResultAXParamsPtr params)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::HandleAccessibilityFindInPageTermination()
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DocumentOnLoadCompleted()
{
    printFuncName(__FUNCTION__, false, false);
    if (!m_frameClient)
        return;
    mbWebView webviewHandle = m_frameClient->getMbwebviewId();
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview)
        return;

    blink::LocalFrameToken token = m_frameClient->getFrame()->GetLocalFrameToken();
    mbWebFrameHandle frameId = (void*)(blink::LocalFrameToken::Hasher()(token));

    if (webview->getClosure().m_DocumentReadyInBlinkCallback)
        webview->getClosure().m_DocumentReadyInBlinkCallback(webviewHandle, webview->getClosure().m_DocumentReadyInBlinkParam, frameId);

    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webviewHandle, frameId]() {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview && webview->getClosure().m_DocumentReadyCallback)
            webview->getClosure().m_DocumentReadyCallback(webviewHandle, webview->getClosure().m_DocumentReadyParam, frameId);
    });
}

void LocalFrameHostImpl::ForwardResourceTimingToParent(::blink::mojom::blink::ResourceTimingInfoPtr timing)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidDispatchDOMContentLoadedEvent()
{
    printFuncName(__FUNCTION__, false, false);
}

bool LocalFrameHostImpl::RunModalAlertDialog(const ::WTF::String& alertMsg, bool disable_third_party_subframe_suppresion)
{
    std::string* txt = new std::string(alertMsg.Utf8());
    bool needPopupNativeMsgBox = true;
    do {
        if (!m_frameClient)
            break;
        mbWebView webviewHandle = m_frameClient->getMbwebviewId();
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (!webview || !webview->getClosure().m_AlertBoxCallback)
            break;

        ThreadCall::callUiThreadSync(MB_FROM_HERE, [webviewHandle, txt]() {
            MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
            if (webview)
                webview->getClosure().m_AlertBoxCallback(webviewHandle, webview->getClosure().m_AlertBoxParam, txt->c_str());
        });
        needPopupNativeMsgBox = false;
    } while (false);

#ifdef _WIN32
    if (needPopupNativeMsgBox)
        MessageBoxW(0, (const WCHAR*)(base::UTF8ToUTF16(*txt).c_str()), L"Alert", 0);
#endif // _WIN32
    delete txt;
    return true;
}

void LocalFrameHostImpl::RunModalAlertDialog(
    const ::WTF::String& alertMsg, bool disable_third_party_subframe_suppresion, ::blink::mojom::blink::LocalFrameHost::RunModalAlertDialogCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

bool LocalFrameHostImpl::RunModalConfirmDialog(const ::WTF::String& alertMsg, bool disable_third_party_subframe_suppresion, bool* outSuccess)
{
    std::string* txt = new std::string(alertMsg.Utf8());
    bool needPopupNativeMsgBox = true;
    BOOL ret = TRUE;

    do {
        if (!m_frameClient)
            break;
        mbWebView webviewHandle = m_frameClient->getMbwebviewId();
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (!webview || !webview->getClosure().m_ConfirmBoxCallback)
            break;

        ThreadCall::callUiThreadSync(MB_FROM_HERE, [webviewHandle, txt, &ret]() {
            MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
            if (webview)
                ret = webview->getClosure().m_ConfirmBoxCallback(webviewHandle, webview->getClosure().m_ConfirmBoxParam, txt->c_str());
        });
        needPopupNativeMsgBox = false;
    } while (false);

    if (needPopupNativeMsgBox)
        ret = MessageBoxA(0, txt->c_str(), "Confirm", MB_YESNO) == IDYES;

    delete txt;
    *outSuccess = ret;
    return false;
}

void LocalFrameHostImpl::RunModalConfirmDialog(
    const ::WTF::String& alertMsg, bool disable_third_party_subframe_suppresion, ::blink::mojom::blink::LocalFrameHost::RunModalConfirmDialogCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

bool LocalFrameHostImpl::RunModalPromptDialog(
    const ::WTF::String& alertMsg, const ::WTF::String& defaultVal, bool disableThirdPartySubframeSuppresion, bool* outSuccess, ::WTF::String* outResult)
{
    std::string* txt = new std::string(alertMsg.Utf8());
    std::string* defaultValue = new std::string(defaultVal.Utf8());
    mbStringPtr ret = nullptr;
    BOOL isOk = TRUE;

    do {
        if (!m_frameClient)
            break;
        mbWebView webviewHandle = m_frameClient->getMbwebviewId();
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (!webview || !webview->getClosure().m_PromptBoxCallback)
            break;

        ThreadCall::callUiThreadSync(MB_FROM_HERE, [webviewHandle, txt, defaultValue, &ret, &isOk]() {
            MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
            if (webview)
                ret = webview->getClosure().m_PromptBoxCallback(
                    webviewHandle, webview->getClosure().m_PromptBoxParam, txt->c_str(), defaultValue->c_str(), &isOk);
        });
    } while (false);

    delete txt;
    delete defaultValue;

    if (ret) {
        *outResult = ::WTF::String::FromUTF8(std::string_view(mbGetString(ret), mbGetStringLen(ret)));
        mbDeleteString(ret);
        *outSuccess = isOk;
        return true;
    }

    *outSuccess = isOk;
    return false;
}

void LocalFrameHostImpl::RunModalPromptDialog(const ::WTF::String& alertMsg, const ::WTF::String& defaultVal, bool disable_third_party_subframe_suppresion,
    ::blink::mojom::blink::LocalFrameHost::RunModalPromptDialogCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

// Sync method. This signature is used by the client side; the service side
// should implement the signature with callback below.
bool LocalFrameHostImpl::RunBeforeUnloadConfirm(bool is_reload, bool* outSuccess)
{
    printFuncName(__FUNCTION__, true, false);
    return false;
}

void LocalFrameHostImpl::RunBeforeUnloadConfirm(bool is_reload, RunBeforeUnloadConfirmCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::UpdateFaviconURL(WTF::Vector<::blink::mojom::blink::FaviconURLPtr> favicon_urls)
{
    printFuncName(__FUNCTION__, true, false);
}

void beginNavigation(std::unique_ptr<blink::WebNavigationInfo> info, blink::WebNavigationControl* navigationControl, int64_t mbwebviewId,
    MojoHandle dataPipeProducerHandle, blink::WebLocalFrame* frame);

void LocalFrameHostImpl::DownloadURL(::blink::mojom::blink::DownloadURLParamsPtr params)
{
    printFuncName(__FUNCTION__, false, false);

    std::unique_ptr<blink::WebNavigationInfo> info = std::make_unique<blink::WebNavigationInfo>();
    info->url_request.SetUrl(blink::WebURL(params->url));
    info->url_request.SetReferrerString(params->referrer->url.GetString());
    info->url_request.SetReferrerPolicy(params->referrer->policy);
    //info->navigation_policy = blink::kWebNavigationPolicyDownload;
    m_frameClient->beginDownload(std::move(info), std::make_unique<String>(params->suggested_name));
}

void LocalFrameHostImpl::FocusedElementChanged(bool is_editable_element, bool is_richly_editable_element, const ::gfx::Rect& bounds_in_frame_widget, ::blink::mojom::blink::FocusType focus_type)
{
    //printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::TextSelectionChanged(const ::WTF::String& text, uint32_t offset, const ::gfx::Range& range)
{
    //printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::ShowPopupMenu(::mojo::PendingRemote<::blink::mojom::blink::PopupMenuClient> popup_client, const ::gfx::Rect& bounds,
    int32_t item_height, double font_size, int32_t selected_item, WTF::Vector<::blink::mojom::blink::MenuItemPtr> menu_items, bool right_aligned,
    bool allow_multiple_selection)

{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::CreateNewPopupWidget(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> popupHost,
    ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::WidgetHost> blinkWidgetHost,
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::Widget> blinkWidget)
{
    //printFuncName(__FUNCTION__, true, false);
    mbWebView parentWebviewId = m_frameClient->getMbwebviewId();
    MbWebView* newWebview = new MbWebView(true);
    newWebview->initPopupWidgetModeInBlinkThread(parentWebviewId, std::move(popupHost), std::move(blinkWidgetHost), std::move(blinkWidget));
}

void LocalFrameHostImpl::ShowContextMenu(
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::ContextMenuClient> client, const ::blink::UntrustworthyContextMenuParams& params)
{
#if defined(OS_WIN)
    //if (m_contextMenuClient)
    //    delete m_contextMenuClient;
    //m_contextMenuClient->Bind(std::move(client));

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_frameClient->getMbwebviewId());
    ContextMenu::get()->setCurrentWebview(webview);
    ContextMenu::get()->show(params, getFrameIdByWebLocalFrame(m_frameClient->getFrame()));
#endif
}

void LocalFrameHostImpl::DidLoadResourceFromMemoryCache(const ::blink::KURL& url, const WTF::String& http_method, const WTF::String& mime_type,
    ::network::mojom::blink::RequestDestination request_destination, bool include_credentials)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidChangeFrameOwnerProperties(
    const ::blink::FrameToken& child_frame_token, ::blink::mojom::blink::FrameOwnerPropertiesPtr frame_owner_properties)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidChangeOpener(const absl::optional<::blink::LocalFrameToken>& opener_frame)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidChangeFramePolicy(const ::blink::FrameToken& child_frame_token, const ::blink::FramePolicy& frame_policy)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidChangeIframeAttributes(const ::blink::FrameToken& child_frame_token, ::blink::mojom::blink::IframeAttributesPtr attributes)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::CapturePaintPreviewOfSubframe(const ::gfx::Rect& clip_rect, const ::base::UnguessableToken& guid)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SetCloseListener(::mojo::PendingRemote<::blink::mojom::blink::CloseListener> listener)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::Detach()
{
    printFuncName(__FUNCTION__, true, false);
}

class KeepAliveHandleImpl : public blink::mojom::blink::KeepAliveHandle {
public:
    KeepAliveHandleImpl()
    {
    }

    ~KeepAliveHandleImpl() override
    {
    }
};

class KeepAliveHandleFactoryImpl : public blink::mojom::blink::KeepAliveHandleFactory {
public:
    KeepAliveHandleFactoryImpl()
    {
    }

    void IssueKeepAliveHandle(::mojo::PendingReceiver<::blink::mojom::blink::KeepAliveHandle> keepAliveHandle) override
    {
        createAndBindInterface<::blink::mojom::blink::KeepAliveHandle, KeepAliveHandleImpl>(keepAliveHandle.PassPipe());
    }
};

void LocalFrameHostImpl::GetKeepAliveHandleFactory(::mojo::PendingReceiver<::blink::mojom::blink::KeepAliveHandleFactory> factory)
{
    printFuncName(__FUNCTION__, false, false);
    createAndBindInterface<::blink::mojom::blink::KeepAliveHandleFactory, KeepAliveHandleFactoryImpl>(factory.PassPipe());
}

void LocalFrameHostImpl::DidAddMessageToConsole(::blink::mojom::blink::ConsoleMessageLevel log_level, const ::WTF::String& msg, uint32_t line_number,
    const ::WTF::String& source_id, const ::WTF::String& untrusted_stack_trace)
{
    std::string output = "DidAddMessageToConsole:[";
    output += msg.Utf8();
    output += "],[";
    output += source_id.Utf8();
    output += "]\n";
    OutputDebugStringA(output.c_str());
}

void LocalFrameHostImpl::FrameSizeChanged(const ::gfx::Size& size)
{
    //printFuncName(__FUNCTION__, true, false);

    //     char* output = (char*)malloc(0x100);
    //     sprintf_s(output, 0x99, "LocalFrameHostImpl::FrameSizeChanged not impl: %d %d\n", size.width(), size.height());
    //     OutputDebugStringA(output);
    //     free(output);
}

void LocalFrameHostImpl::DidInferColorScheme(::blink::mojom::blink::PreferredColorScheme color_scheme)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidChangeSrcDoc(const ::blink::FrameToken& child_frame_token, const WTF::String& srcdoc_value)
{
    printFuncName(__FUNCTION__, false, false);
}

void LocalFrameHostImpl::DidChangeBaseURL(const ::blink::KURL& base_url)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::ReceivedDelegatedCapability(::blink::mojom::blink::DelegatedCapability delegated_capability)
{
    printFuncName(__FUNCTION__, true, false);
}

// bool LocalFrameHostImpl::CreatePortal(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::Portal> portal,
//     ::mojo::PendingAssociatedRemote<::blink::mojom::blink::PortalClient> client,
//     ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces,
//     ::blink::mojom::blink::FrameReplicationStatePtr* out_initial_replicated_state, ::blink::PortalToken* out_portal_token,
//     ::blink::RemoteFrameToken* out_frame_token, ::base::UnguessableToken* out_devtools_frame_token)
// {
//     printFuncName(__FUNCTION__, true, false);
//     return false;
// }
// 
// void LocalFrameHostImpl::CreatePortal(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::Portal> portal,
//     ::mojo::PendingAssociatedRemote<::blink::mojom::blink::PortalClient> client,
//     ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, CreatePortalCallback callback)
// 
// {
//     printFuncName(__FUNCTION__, true, false);
// }

// bool LocalFrameHostImpl::AdoptPortal(const ::blink::PortalToken& portal_token,
//     ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, ::blink::mojom::blink::FrameReplicationStatePtr* out_replicated_state,
//     ::blink::RemoteFrameToken* out_frame_token, ::base::UnguessableToken* out_devtools_frame_token)
// {
//     printFuncName(__FUNCTION__, true, false);
//     return false;
// }
// 
// void LocalFrameHostImpl::AdoptPortal(
//     const ::blink::PortalToken& portal_token, ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, AdoptPortalCallback callback)
// 
// {
//     printFuncName(__FUNCTION__, true, false);
// }

void LocalFrameHostImpl::CreateFencedFrame(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::FencedFrameOwnerHost> fenced_frame,
    ::blink::mojom::blink::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, const ::blink::RemoteFrameToken& frame_token,
    const ::base::UnguessableToken& devtools_frame_token)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::StartLoadingForAsyncNavigationApiCommit()
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::NavigateEventHandlerPresenceChanged(bool present)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::UpdateAppTitle(const ::WTF::String& app_title) 
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DidConsumeHistoryUserActivation()
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SendFencedFrameReportingBeacon(const WTF::String& event_data, const WTF::String& event_type,
    const WTF::Vector<::blink::FencedFrame::ReportingDestination>& destinations, bool cross_origin_exposed)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SendFencedFrameReportingBeaconToCustomURL(const ::blink::KURL& destination_url, bool cross_origin_exposed)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::DisableUntrustedNetworkInFencedFrame(DisableUntrustedNetworkInFencedFrameCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::ExemptUrlFromNetworkRevocationForTesting(const ::blink::KURL& exempted_url, ExemptUrlFromNetworkRevocationForTestingCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SendLegacyTechEvent(const WTF::String& type, ::blink::mojom::blink::LegacyTechEventCodeLocationPtr code_location)
{
    printFuncName(__FUNCTION__, true, false);
}


void LocalFrameHostImpl::SetFencedFrameAutomaticBeaconReportEventData(::blink::mojom::blink::AutomaticBeaconType event_type, const WTF::String& event_data,
    const WTF::Vector<::blink::FencedFrame::ReportingDestination>& destinations, bool once, bool cross_origin_exposed)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::SendPrivateAggregationRequestsForFencedFrameEvent(const WTF::String& event_type)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::ForwardFencedFrameEventAndUserActivationToEmbedder(const WTF::String& event_type)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::OnViewTransitionOptInChanged(::blink::mojom::blink::ViewTransitionSameOriginOptIn view_transition_opt_in)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::StartDragging(const ::blink::WebDragData& drag_data, ::blink::DragOperationsMask operations_allowed, const ::SkBitmap& image,
    const ::gfx::Vector2d& cursor_offset_in_dip, const ::gfx::Rect& drag_obj_rect_in_dip, ::blink::mojom::blink::DragEventSourceInfoPtr event_info)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::IssueKeepAliveHandle(::mojo::PendingReceiver<::blink::mojom::blink::NavigationStateKeepAliveHandle> receiver)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::NotifyStorageAccessed(::blink::mojom::blink::StorageTypeAccessed storageType, bool blocked)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::RecordWindowProxyUsageMetrics(const ::blink::FrameToken& target_frame_token, ::blink::mojom::blink::WindowProxyAccessType access_type)
{
    printFuncName(__FUNCTION__, true, false);
}

void LocalFrameHostImpl::NotifyDocumentInteractive()
{
    printFuncName(__FUNCTION__, true, false);
}

}