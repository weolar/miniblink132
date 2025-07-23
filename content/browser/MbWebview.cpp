
#include "content/browser/MbWebview.h"

#include "content/renderer/WebViewClientImpl.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/renderer/PolicyContainerHostImpl.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/renderer/BlinkInterfaceRegistryImpl.h"
#include "content/renderer/PlatformEventHandler.h"
#include "content/browser/RenderWidgetHostImpl.h"
#include "content/browser/WebFrameMain.h"
#include "content/common/BindJsQuery.h"
#include "content/common/mbchar.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/ThreadCall.h"
#include "content/viz/VizService.h"
#include "content/viz/VizHost.h"
#include "mbnet/PageNetExtraData.h"
#include "mbnet/WebURLLoaderManager.h"
#include "mbvip/core/MbJsValue.h"
#include "mbvip/core/MbInternalApi.h"
#include "third_party/blink/renderer/core/loader/document_loader.h"
#include "third_party/blink/renderer/platform/scheduler/public/compositor_thread_scheduler.h"
#include "third_party/blink/public/web/web_settings.h"
#include "third_party/blink/public/web/web_navigation_control.h"
#include "third_party/blink/public/web/web_frame_widget.h"
#include "third_party/blink/public/web/web_navigation_params.h"
#include "third_party/blink/public/web/web_draggable_region.h"
#include "third_party/blink/public/platform/web_policy_container.h"
#include "third_party/blink/public/platform/web_security_origin.h"
#include "third_party/blink/public/platform/cross_variant_mojo_util.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/public/web/web_script_source.h"
#include "third_party/blink/public/common/page/browsing_context_group_info.h"
#include "third_party/blink/renderer/core/exported/web_view_impl.h"
#include "third_party/blink/renderer/core/frame/page_scale_constraints_set.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/settings.h"
#include "third_party/blink/renderer/core/page/page.h"
#include "third_party/blink/renderer/core/testing/internal_runtime_flags.h"
#include "third_party/blink/renderer/platform/wtf/casting.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "mojo/public/cpp/bindings/pending_associated_remote.h"
#include "gen/ui/base/cursor/mojom/cursor_type.mojom-shared.h"
#include "gen/third_party/blink/public/mojom/partitioned_popins/partitioned_popin_params.mojom.h"
#include "gen/third_party/blink/public/mojom/page/prerender_page_param.mojom.h"
#include "gen/third_party/blink/public/mojom/frame/policy_container.mojom-blink.h"
#include "gen/services/viz/privileged/mojom/compositing/frame_sink_manager.mojom.h"
#include "third_party/abseil-cpp/absl/types/optional.h"
#if defined(USE_OZONE)
#include <cairo.h>
#include "linux/linuxgl.h"
#endif
#include "content/common/StringUtil.h"
// test
#include "content/common/Util.h"
#include <shellapi.h>

namespace mbnet {
extern std::vector<char>* s_htmlData;
}
// test==========

namespace blink {
LocalFrame* FromFrameTokenHash(const size_t& frame_token_hash);
}

namespace content {

const WCHAR* kClassWndName = mbu16("mbWebWindowClass");
extern unsigned int g_mbMask;
bool g_enableNativeSetCapture = true;
bool g_enableNativeSetFocus = true;

void freeTempCharStrings();
void clearMbWebViewInContextMenuIfNeeded(MbWebView* webview);

MbWebView::MbWebView(bool isPopup)
{
    m_id = common::LiveIdDetect::getMbWebviewIds()->constructed(this);
    m_clientSize.cx = 0;
    m_clientSize.cy = 0;

    m_offset.x = 0;
    m_offset.y = 0;

    m_isPopup = isPopup;

#if !defined(OS_WIN)
    //::InitializeCriticalSection(&m_memoryCanvasLock);
    //m_memoryCanvasLock = new base::Lock();
#endif
    ::InitializeCriticalSection(&m_mouseMsgQueueLock);
    ::InitializeCriticalSection(&m_dirtyRectLock);
    ::InitializeCriticalSection(&m_clientSizeLock);
    ::InitializeCriticalSection(&m_userKeyValuesLock);

    char output[100] = { 0 };
    sprintf_s(output, 99, "MbWebView: %p\n", this);
    OutputDebugStringA(output);
}

// 本函数在blink线程
MbWebView::~MbWebView()
{
    char output[100] = { 0 };
    sprintf_s(output, 99, "~MbWebView: %p %p\n", m_hWnd, this);
    OutputDebugStringA(output);

    m_renderWidgetHostImpl.reset();
}

// void MbWebView::destroy()
// {
//     mbWebView webviewHandle = (mbWebView)m_id;
//     ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](MbWebView* self) { delete self; });
// }

// 此函数可运行在ui和blink线程
static void clearUiHwnd(HWND hWnd, UINT_PTR self)
{
    ::KillTimer(hWnd, self);
    ::RemovePropW(hWnd, kClassWndName);
}

void MbWebView::preDestroyOnBlinkThread()
{
    CHECK(ThreadCall::isBlinkThread());
#if !defined(OS_WIN)
    //delete m_memoryCanvasLock;
#endif
    m_navigationController = nullptr;

    m_state = kPageDestroyed;

    if (m_renderWidgetHostImpl)
        m_renderWidgetHostImpl->destroy(); // 这里面AsyncLayerTreeFrameSink同步销毁
    //m_renderWidgetHostImpl.release(); // TODO:暂时不析构

    MbWebView* self = this;
    int* aysnCount = (int*)malloc(sizeof(int));
    *aysnCount = 2;
    auto destroyCb = [self, aysnCount] {
        OutputDebugStringA("MbWebView::preDestroyOnBlinkThread, aysnCount\n");
        *aysnCount -= 1;
        if (0 != *aysnCount)
            return;
        ThreadCall::delayDestroySelf(self, RenderThreadImpl::get()->getTaskRunner(), 2000);
        free(aysnCount);
    };

    m_host->destroy(destroyCb);
    m_host.release(); // TODO:

    m_platformEventHandler->destroy();
    m_platformEventHandler.release();

    m_service->destroy(destroyCb);
    m_service.release(); // TODO:

    int count = 0;
    while (m_hWnd && ::IsWindow(m_hWnd)) {
        ++count;
        ::Sleep(100);
#ifndef _DEBUG
        if (count > 6)
            break;
#endif // DEBUG
    }

    char output[100] = { 0 };
    sprintf(output, "MbWebView::preDestroyOnBlinkThread: %p %p\n", m_hWnd, this);
    OutputDebugStringA(output);

    clearUiHwnd(m_hWnd, (UINT_PTR)this);
    m_hWnd = nullptr;
#if defined(OS_WIN)
    if (m_memoryBMP)
        ::DeleteObject(m_memoryBMP);

        // if (m_memoryDC)
        //     ::DeleteDC(m_memoryDC);

        //if (m_draggableRegion)
        //  ::DeleteObject(m_draggableRegion);
#else
    if (m_bitmap)
        delete m_bitmap;
    if (m_memoryCanvas)
        delete m_memoryCanvas;
        //if (m_surface)
        //   cairo_surface_destroy((cairo_surface_t*)m_surface); // ~OffscreenWindowUpdater里会释放这个m_surface
#endif
    //::DeleteCriticalSection(&m_memoryCanvasLock);
    ::DeleteCriticalSection(&m_mouseMsgQueueLock);
    ::DeleteCriticalSection(&m_dirtyRectLock);
    ::DeleteCriticalSection(&m_clientSizeLock);
    ::DeleteCriticalSection(&m_userKeyValuesLock);
}

void MbWebView::preDestroyOnUiThread()
{
    char output[100] = { 0 };
    sprintf(output, "MbWebView::preDestroyOnUiThread: %p %p\n", m_hWnd, this);
    OutputDebugStringA(output);

    clearMbWebViewInContextMenuIfNeeded(this);

    //m_renderWidgetHostImpl->destroy();
    //m_host->destroy();
    //m_service.reset();

    common::LiveIdDetect::getMbWebviewIds()->deconstructed(m_id);
    m_state = kPageDestroying;
    ::RevokeDragDrop(m_hWnd);
    //::SetPropW(m_hWnd, kClassWndName, NULL);
    //::SetWindowLongPtrW(m_hWnd, GWLP_USERDATA, 0);

#ifdef OS_LINUX
    // 在linux下，窗口句柄有可能是LinuxGdiBindWindowByGtk创建的，此时是收不到窗口关闭的消息（因为外部手动关闭了），所以要手动来一次
    ::DestroyWindow(m_hWnd);
#endif
}

// 本函数在webkit线程
void MbWebView::initializeCompositorInBlinkThread(/*gfx::AcceleratedWidget hwnd*/ bool isTransparent)
{
    //m_hWnd = hwnd;

    //DCHECK(m_hWnd != gfx::kNullAcceleratedWidget);

    // We finally have a valid gfx::AcceleratedWidget. We can now start the
    // actual process of setting up the viz host and the service.
    // First, set up the mojo message-pipes that the host and the service will
    // use to communicate with each other.
    mojo::PendingRemote<viz::mojom::FrameSinkManager> frameSinkManager;
    mojo::PendingReceiver<viz::mojom::FrameSinkManager> frameSinkManagerReceiver = frameSinkManager.InitWithNewPipeAndPassReceiver();
    mojo::PendingRemote<viz::mojom::FrameSinkManagerClient> frameSinkManagerClient;
    mojo::PendingReceiver<viz::mojom::FrameSinkManagerClient> frameSinkManagerClientReceiver = frameSinkManagerClient.InitWithNewPipeAndPassReceiver();

    // Next, create the host and the service, and pass them the right ends of
    // the message-pipes.
    m_service = std::make_unique<content::VizService>(std::move(frameSinkManagerReceiver), std::move(frameSinkManagerClient));

    m_host = std::make_unique<content::VizHost>(this,
        //m_hWnd,
        isTransparent, gfx::Size(1, 1), // 先随便写一个假的大小，这会产生一个小黑色长方形
        std::move(frameSinkManagerClientReceiver), std::move(frameSinkManager), content::RenderThreadImpl::get()->m_hostThread.task_runner(),
        m_service->GetCompositorThreadRunner());

    if (m_renderWidgetHostImpl)
        m_renderWidgetHostImpl->setSinkHost(m_host.get());
}

void MbWebView::setHostWnd(HWND hWnd)
{
    m_hWnd = hWnd;

    if (!m_isTransparent)
        m_isTransparent = !!(::GetWindowLongW(hWnd, GWL_EXSTYLE) & WS_EX_LAYERED);

    mbWebView webviewHandle = (mbWebView)m_id;
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](MbWebView* self) { self->setIsTransparent(self->m_isTransparent); });
}

void MbWebView::createWebWindowImplInUiThread(HWND parent, DWORD style, DWORD styleEx, int x, int y, int width, int height)
{
    const WCHAR* szClassName = mbu16("MtMbWebWindow");
    WNDCLASSEXW wndClass = { 0 };
    static bool isFirstRegister = true;
    if (isFirstRegister) {
        isFirstRegister = false;
        wndClass.cbSize = sizeof(WNDCLASSEXW);
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = &MbWebView::windowProc;
        wndClass.cbClsExtra = 200;
        wndClass.cbWndExtra = 200;
        wndClass.hInstance = GetModuleHandleW(NULL);
        wndClass.hIcon = LoadIconW(NULL, IDI_APPLICATION);
        wndClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
        wndClass.hbrBackground = NULL;
        wndClass.lpszMenuName = NULL;
        wndClass.lpszClassName = szClassName;
        RegisterClassExW(&wndClass);
    }

    m_hWnd = CreateWindowExW(styleEx, // window ex-style
        szClassName, // window class name
        kClassWndName, // window caption
        style, // window style
        x, // initial x position
        y, // initial y position
        width, // initial x size
        height, // initial y size
        parent, // parent window handle
        NULL, // window menu handle
        GetModuleHandleW(NULL), // program instance handle
        this); // creation parameters

    if (!IsWindow(m_hWnd))
        return;

    if (m_isShow)
        mbShowWindowImpl(getWebviewHandle(), true);

    m_isWebWindowMode = true;
}

void MbWebView::bindGtkWindow(void* rootWindow, void* drawingArea, bool isGl, DWORD style, DWORD styleEx, int width, int height)
{
#if !defined(WIN32)
    const WCHAR* szClassName = mbu16("MtMbWebWindow");
    WNDCLASSEXW wndClass = { 0 };
    static bool isFirstRegister = true;
    if (isFirstRegister) {
        isFirstRegister = false;
        wndClass.cbSize = sizeof(WNDCLASSEXW);
        wndClass.style = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc = &MbWebView::windowProc;
        wndClass.cbClsExtra = 200;
        wndClass.cbWndExtra = 200;
        wndClass.hInstance = GetModuleHandleW(NULL);
        wndClass.hIcon = LoadIconW(NULL, IDI_APPLICATION);
        wndClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
        wndClass.hbrBackground = NULL;
        wndClass.lpszMenuName = NULL;
        wndClass.lpszClassName = szClassName;
        RegisterClassExW(&wndClass);
    }

    m_hWnd = LinuxGdiBindWindowByGtk(rootWindow, drawingArea, isGl,
        styleEx, // window ex-style
        szClassName, // window class name
        style, // window style
        width, // initial x size
        height, // initial y size
        this); // creation parameters

    if (!IsWindow(m_hWnd))
        return;

    if (m_isShow)
        mbShowWindowImpl(getWebviewHandle(), true);

    m_isWebWindowMode = true;
#endif
}

blink::WebView* MbWebView::createWebWindowOrViewInBlinkThread(blink::WebView* opener, blink::WebFrame* openerWebFrame, bool isWebWindowMode, bool isTransparent)
{
    if (m_service.get())
        return m_renderWidgetHostImpl->m_webWiew;

    initializeCompositorInBlinkThread(isTransparent);
    return initializeViewInBlinkThread(opener, openerWebFrame);
}

// 当本MbWebView作为下拉框的外部容器时走到这里
void MbWebView::initPopupWidgetModeInBlinkThread(mbWebView parentWebviewId, ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> popupHost,
    ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::WidgetHost> blinkWidgetHost,
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::Widget> blinkWidget)
{
    m_isPopupWidgetMode = true;
    initializeCompositorInBlinkThread(/*m_hWnd*/ false);
    m_sessionStorageNamespaceId = blink::AllocateSessionStorageNamespaceId();

    m_renderWidgetHostImpl = std::make_unique<RenderWidgetHostImpl>(parentWebviewId, base::SequencedTaskRunner::GetCurrentDefault());
    m_renderWidgetHostImpl->setHostFrameSinkManager(m_host->host_frame_sink_manager());
    m_renderWidgetHostImpl->setSinkHost(m_host.get());

    m_platformEventHandler = std::make_unique<content::PlatformEventHandler>(m_id, nullptr, (blink::WebViewImpl*)nullptr);
    m_renderWidgetHostImpl->m_platformEventHandler = m_platformEventHandler.get();

    m_host->getRootClient()->setWidgetHost(m_renderWidgetHostImpl.get());

    m_renderWidgetHostImpl->m_mainFrame = nullptr;
    m_renderWidgetHostImpl->m_webWiew = nullptr;
    m_renderWidgetHostImpl->m_mbWebView = this;
    m_renderWidgetHostImpl->m_webFrameWidget = nullptr;
    m_renderWidgetHostImpl->bindPopupWidget(std::move(popupHost), std::move(blinkWidgetHost), std::move(blinkWidget));
}

blink::WebView* MbWebView::initializeViewInBlinkThread(blink::WebView* opener, blink::WebFrame* openerWebFrame)
{
    if (!m_navigationController)
        m_navigationController = blink::MakeGarbageCollected<content::PageNavController>(this);

    m_sessionStorageNamespaceId = blink::AllocateSessionStorageNamespaceId();

    blink::BrowsingContextGroupInfo browsingContextGroupInfo = blink::BrowsingContextGroupInfo::CreateUnique();
    blink::WebView* webWiew = blink::WebView::Create(
        new content::WebViewClientImpl(this), 
        false, // is_hidden
        nullptr, // blink::mojom::PrerenderParamPtr prerender_param 
        absl::nullopt, // std::optional<blink::FencedFrame::DeprecatedFencedFrameMode> fenced_frame_mode, 
        /*compositing_enabled=*/true, 
        false, // widgets_never_composited
        opener, 
        blink::CrossVariantMojoAssociatedReceiver<blink::mojom::PageBroadcastInterfaceBase>(),
        *(content::RenderThreadImpl::get()->m_agentGroupScheduler), 
        m_sessionStorageNamespaceId, 
        absl::optional<SkColor>(0xffffffff),
        browsingContextGroupInfo,
        nullptr, // const ColorProviderColorMaps * color_provider_colors,
        nullptr // blink::mojom::PartitionedPopinParamsPtr partitioned_popin_params
        );

    mojo::PendingAssociatedRemote<blink::mojom::blink::PolicyContainerHost> policyContainerRemote;
    mojo::PendingAssociatedReceiver<blink::mojom::blink::PolicyContainerHost> policyContainerReceiver
        = policyContainerRemote.InitWithNewEndpointAndPassReceiver();

    mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>* blinkPolicyContainerHostReceiver
        = new mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>(new content::PolicyContainerHostImpl());
    blinkPolicyContainerHostReceiver->Bind(std::move(policyContainerReceiver)); // TODO: 内存泄露

    std::unique_ptr<blink::WebPolicyContainer> policyContainer = std::make_unique<blink::WebPolicyContainer>(
        blink::WebPolicyContainerPolicies(), blink::ToCrossVariantAssociatedMojoType(std::move(policyContainerRemote)));

    m_frameClient = new WebLocalFrameClientImpl(m_id);
    BlinkInterfaceRegistryImpl* blinkInterfaceRegistryImpl = new BlinkInterfaceRegistryImpl(m_frameClient);
    m_frameClient->m_blinkInterfaceRegistryImpl = blinkInterfaceRegistryImpl;

    mojo::PendingRemote<blink::mojom::BrowserInterfaceBroker> browserInterfaceBroker = m_frameClient->getBrowserInterfaceBrokerProxyReceiver().BindNewPipeAndPassRemote();

    blink::WebLocalFrame* webframe
        = blink::WebLocalFrame::CreateMainFrame(
            webWiew, 
            m_frameClient, 
            blinkInterfaceRegistryImpl, 
            // CrossVariantMojoRemote<mojom::BrowserInterfaceBrokerInterfaceBase>
            blink::CrossVariantMojoRemote<blink::mojom::BrowserInterfaceBrokerInterfaceBase>(std::move(browserInterfaceBroker)),
            blink::LocalFrameToken(), 
            blink::DocumentToken(),
            std::move(policyContainer), 
            openerWebFrame, 
            blink::WebString::FromUTF8("MbWebView_hahaha"), 
            network::mojom::WebSandboxFlags::kNone, blink::WebURL());
    //--
    if (openerWebFrame) {
        blink::WebLocalFrameImpl* webframeimpl = (blink::WebLocalFrameImpl*)webframe;
        blink::LocalFrame* localFrame = webframeimpl->GetFrame();
        blink::LocalDOMWindow* domwin = localFrame->DomWindow();
        blink::SecurityContext& securityContext = domwin->GetSecurityContext();
        securityContext.SetSecurityOriginForTesting(nullptr);
        securityContext.SetSecurityOrigin(blink::SecurityOrigin::CreateFromString(openerWebFrame->GetSecurityOrigin().ToString()));
    }
    //--
    m_frameClient->setFrame(webframe);
    new WebFrameMain(blink::LocalFrameToken::Hasher()(webframe->GetLocalFrameToken()), 0, true);

    m_frameClient->m_blinkPolicyContainerHostReceiver = blinkPolicyContainerHostReceiver;
    m_frameClient->m_isMainFrame = true;

    m_renderWidgetHostImpl = std::make_unique<RenderWidgetHostImpl>(NULL_WEBVIEW, base::SequencedTaskRunner::GetCurrentDefault());
    m_renderWidgetHostImpl->setHostFrameSinkManager(m_host->host_frame_sink_manager());
    m_renderWidgetHostImpl->setSinkHost(m_host.get());

    m_platformEventHandler = std::make_unique<content::PlatformEventHandler>(m_id, nullptr, (blink::WebViewImpl*)webWiew);
    m_renderWidgetHostImpl->m_platformEventHandler = m_platformEventHandler.get();

    m_host->getRootClient()->setWidgetHost(m_renderWidgetHostImpl.get());

    std::unique_ptr<CreateFrameWidgetParams> createFrameWidgetParams = m_renderWidgetHostImpl->bindAndGenerateCreateFrameWidgetParams();
    m_renderWidgetHostImpl->m_mainFrame = webframe;
    m_renderWidgetHostImpl->m_webWiew = webWiew;
    m_renderWidgetHostImpl->m_mbWebView = this;

    setDefaultPreferences((blink::WebViewImpl*)webWiew);

    blink::DocumentLoader::DisableCodeCacheForTesting();

    //constexpr viz::FrameSinkId root_frame_sink_id(0xdead, 0xbeef);
    //m_renderWidgetHostImpl->setFrameSinkId(root_frame_sink_id);
    //m_renderWidgetHostImpl->bindLocalSurfaceId();

    blink::WebFrameWidget* webFrameWidget
        = webframe->InitializeFrameWidget(blink::ToCrossVariantAssociatedMojoType(std::move(createFrameWidgetParams->frameWidgetHost)),
            blink::ToCrossVariantAssociatedMojoType(std::move(createFrameWidgetParams->frameWidget)),
            blink::ToCrossVariantAssociatedMojoType(std::move(createFrameWidgetParams->widgetHost)),
            blink::ToCrossVariantAssociatedMojoType(std::move(createFrameWidgetParams->blinkWidget)),
            viz::FrameSinkId(/*RenderThread::Get()->GetClientId()*/ 1, /*params->widget_params->routing_id*/ 2),
            /*is_for_nested_main_frame*/ false, /*is_for_scalable_page*/ true,
            /*hidden=*/true);
    webFrameWidget->InitializeCompositing(
        /**m_renderWidgetHostImpl->m_agentGroupScheduler, */createFrameWidgetParams->visualProperties.screen_infos, /*settings=*/nullptr);

    m_renderWidgetHostImpl->m_webFrameWidget = webFrameWidget;

    webWiew->DidAttachLocalMainFrame();

    if (m_isTransparent)
        setIsTransparent(m_isTransparent);
    return webWiew;
}

void MbWebView::setPaintUpdatedCallback(mbPaintUpdatedCallback callback, void* param)
{
    getClosure().setPaintUpdatedCallback(callback, param);
    //m_hasSetPaintUpdatedCallback = true;
}

void MbWebView::handlePopup(UINT message)
{
    if (m_isPopup || !m_renderWidgetHostImpl || !m_renderWidgetHostImpl->m_webWiew)
        return;
    switch (message) {
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        //     case WM_LBUTTONDBLCLK:
        //     case WM_MBUTTONDBLCLK:
        //     case WM_RBUTTONDBLCLK:
        //     case WM_LBUTTONUP:
        //     case WM_MBUTTONUP:
        //     case WM_RBUTTONUP:

    case WM_NCLBUTTONDOWN:
        //     case WM_NCLBUTTONUP:
        //     case WM_NCLBUTTONDBLCLK:
    case WM_NCRBUTTONDOWN:
        //     case WM_NCRBUTTONUP:
        //     case WM_NCRBUTTONDBLCLK:
        //     case WM_NCMBUTTONDOWN:
        //     case WM_NCMBUTTONUP:
        //     case WM_NCMBUTTONDBLCLK:
        break;
    default:
        return;
    }

    mbWebView webviewHandle = (mbWebView)m_id;
    ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [](content::MbWebView* self) {
        if (self->m_renderWidgetHostImpl && self->m_renderWidgetHostImpl->m_webWiew) {
            blink::WebViewImpl* webview = (blink::WebViewImpl*)self->m_renderWidgetHostImpl->m_webWiew;
            webview->CancelPagePopup();
        }
    });
}

void MbWebView::setBackgroundColor(COLORREF c)
{
    m_backgroundColor = c;
    m_hasBackgroundColor = true;

    mbWebView webviewHandle = (mbWebView)m_id;
    ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [c](content::MbWebView* self) {
        if (self->m_renderWidgetHostImpl && self->m_renderWidgetHostImpl->m_webWiew) {
            blink::WebViewImpl* webview = (blink::WebViewImpl*)self->m_renderWidgetHostImpl->m_webWiew;
            absl::optional<SkColor> color(c);
            webview->SetPageBaseBackgroundColor(color);
        }
    });
}

void MbWebView::setDefaultPreferences(blink::WebViewImpl* webWiew)
{
    LANGID langId = GetUserDefaultUILanguage();
    if (0x0804 == langId) {
        setSetLanguage("zh-cn");
    }

    webWiew->SetPageAttributionSupport(network::mojom::AttributionSupport::kWeb);
    webWiew->SetSupportsDraggableRegions(true);

    blink::WebSettings* websettings = webWiew->GetSettings();
    websettings->SetDefaultFontSize(16);
    websettings->SetDefaultFixedFontSize(16);
    websettings->SetJavaScriptEnabled(true);
    websettings->SetLoadsImagesAutomatically(true);
    websettings->SetLocalStorageEnabled(true);
    websettings->SetAllowScriptsToCloseWindows(true);
    websettings->SetJavaScriptCanAccessClipboard(true);
    websettings->SetDOMPasteAllowed(true);

//     blink::Page* page = webWiew->GetPage();
//     page->GetSettings().SetAcceleratedCompositingEnabled(false);
    blink::InternalRuntimeFlags* internalRuntimeFlags = blink::InternalRuntimeFlags::create();
    internalRuntimeFlags->setAccelerated2dCanvasEnabled(false);

    blink::RendererPreferences preferences;
    preferences.accept_languages = "cn-ZH,cn";
#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
    //preferences.system_font_family_name;
#endif
#if BUILDFLAG(IS_WIN)
    //const char16_t* fontStr = u"宋体";
    const char16_t* fontStr = u"Microsoft YaHei";

    preferences.caption_font_family_name = fontStr;
    preferences.caption_font_height = 16;
    preferences.small_caption_font_family_name = fontStr;
    preferences.small_caption_font_height = 12;
    preferences.menu_font_family_name = fontStr;
    preferences.menu_font_height = 12;
    preferences.status_font_family_name = fontStr;
    preferences.status_font_height = 12;
    preferences.message_font_family_name = fontStr;
    preferences.message_font_height = 12;
    preferences.vertical_scroll_bar_width_in_dips = 23;
    preferences.horizontal_scroll_bar_height_in_dips = 23;
    preferences.arrow_bitmap_height_vertical_scroll_bar_in_dips = 17;
    preferences.arrow_bitmap_width_horizontal_scroll_bar_in_dips = 17;
    preferences.accept_languages = "zh-CN";
#endif
    //(preferences.local_storage_enabled);
    webWiew->UpdateRendererPreferences(preferences);

    float zoom = RenderThreadImpl::get()->getZoom();
    //     blink::PageScaleConstraints pageScaleCons = webWiew->GetPageScaleConstraintsSet().UserAgentConstraints();
    //     pageScaleCons.initial_scale = zoom;
    //     pageScaleCons.maximum_scale = 5;
    //     webWiew->GetPageScaleConstraintsSet().SetUserAgentConstraints(pageScaleCons);
    webWiew->SetZoomFactorForDeviceScaleFactor(zoom);
}

void MbWebView::setZoomFactor(float factor)
{
    if (factor < 0.2 || factor > 3 || !m_renderWidgetHostImpl || !m_renderWidgetHostImpl->m_webWiew)
        return;
    m_hasSetZoomFactor = true;
    m_zoomFactor = factor;
    blink::WebViewImpl* webWiew = (blink::WebViewImpl*)m_renderWidgetHostImpl->m_webWiew;
    webWiew->SetInitialPageScaleOverride(factor);
    webWiew->SetZoomFactorForDeviceScaleFactor(factor);
    webWiew->SetPageScaleFactor(factor);
}

float MbWebView::getZoomFactor() const
{
    return m_zoomFactor;
}

void MbWebView::propagatedZoomFactor()
{
    float zoom = RenderThreadImpl::get()->getZoom();
    if (hasSetZoomFactor())
        zoom = getZoomFactor();
    //zoom = 1;

    if (!m_renderWidgetHostImpl || !m_renderWidgetHostImpl->m_webWiew)
        return;
    blink::WebViewImpl* webWiew = (blink::WebViewImpl*)m_renderWidgetHostImpl->m_webWiew;

    //setZoomFactor(zoom);
    //     blink::PageScaleConstraints pageScaleCons = webWiew->GetPageScaleConstraintsSet().UserAgentConstraints();
    //     pageScaleCons.initial_scale = zoom;
    //     pageScaleCons.maximum_scale = 5;
    //     webWiew->GetPageScaleConstraintsSet().SetUserAgentConstraints(pageScaleCons);
    webWiew->SetZoomFactorForDeviceScaleFactor(zoom);
}

void MbWebView::createWebWindowInUiThread(mbWindowType type, HWND parent, int x, int y, int width, int height)
{
    if (IsWindow(m_hWnd))
        return;

    DWORD style = 0;
    DWORD styleEx = 0;
    switch (type) {
    case MB_WINDOW_TYPE_CONTROL:
        style = WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
        styleEx = 0;
        //wkeSetTransparent(this, false);
        break;

    case MB_WINDOW_TYPE_TRANSPARENT:
        m_isTransparent = true;
        style = WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
        styleEx = WS_EX_LAYERED;
        break;

    case MB_WINDOW_TYPE_POPUP:
    default:
        style = WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
        styleEx = 0;
        //wkeSetTransparent(this, false);
    }

    createWebWindowImplInUiThread(parent, style, styleEx, x, y, width, height);
}

LRESULT MbWebView::windowProcImpl(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_NCPAINT:
        break;

    case WM_ERASEBKGND:
        break;
    case WM_GETDLGCODE: // 使得MB控件作为对话框子窗口时可接收到键盘消息
        return DLGC_WANTARROWS | DLGC_WANTALLKEYS | DLGC_WANTCHARS;

    case WM_CREATE:
        ::DragAcceptFiles(hWnd, TRUE);
        ::SetTimer(hWnd, (UINT_PTR)this, 20, NULL);
        break;

    case WM_CLOSE:
        if (mbCloseCallback closingCallback = getClosure().m_ClosingCallback) {
            getClosure().m_ClosingCallback = nullptr;
            if (!closingCallback(getWebviewHandle(), getClosure().m_ClosingParam, nullptr))
                return 0;
        }
        ::ShowWindow(hWnd, SW_HIDE);
        ::DestroyWindow(hWnd);
        return 0;

    case WM_NCDESTROY:
        clearUiHwnd(hWnd, (UINT_PTR)this);
        m_state = kPageDestroying;
        mbDestroyWebViewImpl(getWebviewHandle());
        break;

    case WM_TIMER:
        break;

    case WM_PAINT:
        onPaint(hWnd, wParam);
        break;

    case WM_SIZE: {
        RECT rc = { 0 };
        ::GetClientRect(hWnd, &rc);
        int width = rc.right - rc.left;
        int height = rc.bottom - rc.top;

        onResize(width, height, false);
        content::ThreadCall::wake();
        return 0;
    }
    case WM_DROPFILES:
        return 0;

    case WM_SYSKEYDOWN: // no break
    case WM_KEYDOWN: {
        unsigned int virtualKeyCode = (unsigned int)wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= MB_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= MB_EXTENDED;

        if (mbFireKeyDownEventImpl(getWebviewHandle(), virtualKeyCode, flags, false))
            return 0;
        break;
    }
    case WM_SYSKEYUP:
    case WM_KEYUP: {
        unsigned int virtualKeyCode = (unsigned int)wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= MB_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= MB_EXTENDED;

        if (mbFireKeyUpEventImpl(getWebviewHandle(), virtualKeyCode, flags, false))
            return 0;
        break;
    }
    case WM_NCMOUSEMOVE:
    case WM_NCMOUSEHOVER:
        m_isInNotClient = true;
        break;

    case WM_NCLBUTTONDOWN:
    case WM_NCLBUTTONUP:
    case WM_NCLBUTTONDBLCLK:
    case WM_NCRBUTTONDOWN:
    case WM_NCRBUTTONUP:
    case WM_NCRBUTTONDBLCLK:
    case WM_NCMBUTTONDOWN:
    case WM_NCMBUTTONUP:
    case WM_NCMBUTTONDBLCLK:
        handlePopup(message);
        break;
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_LBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MOUSEMOVE: {
        m_isInNotClient = false;
        handlePopup(message);

        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= MB_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= MB_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= MB_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= MB_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= MB_RBUTTON;
        if (mbFireMouseEventImpl(getWebviewHandle(), message, x, y, flags))
            return 0;
        break;
    }
    case WM_TOUCH: {
        //         LRESULT result = 0;
        //         if (mbFireWindowsMessage(getWebviewHandle(), hWnd, message, wParam, lParam, &result))
        //             return 0;
        break;
    }
    case WM_CONTEXTMENU: {
        //         POINT pt;
        //         pt.x = LOWORD(lParam);
        //         pt.y = HIWORD(lParam);
        //
        //         if (pt.x != -1 && pt.y != -1)
        //             ScreenToClient(hWnd, &pt);
        //
        //         unsigned int flags = 0;
        //
        //         if (wParam & MK_CONTROL)
        //             flags |= WKE_CONTROL;
        //         if (wParam & MK_SHIFT)
        //             flags |= WKE_SHIFT;
        //
        //         if (wParam & MK_LBUTTON)
        //             flags |= WKE_LBUTTON;
        //         if (wParam & MK_MBUTTON)
        //             flags |= WKE_MBUTTON;
        //         if (wParam & MK_RBUTTON)
        //             flags |= WKE_RBUTTON;
        //
        //         if (mbFireContextMenuEvent(getWebviewHandle(), pt.x, pt.y, flags))
        //             return 0;
        break;
    }
    case WM_MOUSEWHEEL: {
        POINT pt;
        pt.x = LOWORD(lParam);
        pt.y = HIWORD(lParam);
        ::ScreenToClient(hWnd, &pt);

        int delta = GET_WHEEL_DELTA_WPARAM(wParam);

        unsigned int flags = 0;

        if (wParam & MK_CONTROL)
            flags |= MB_CONTROL;
        if (wParam & MK_SHIFT)
            flags |= MB_SHIFT;

        if (wParam & MK_LBUTTON)
            flags |= MB_LBUTTON;
        if (wParam & MK_MBUTTON)
            flags |= MB_MBUTTON;
        if (wParam & MK_RBUTTON)
            flags |= MB_RBUTTON;

        if (mbFireMouseWheelEventImpl(getWebviewHandle(), pt.x, pt.y, delta, flags))
            return 0;
        break;
    }
    case WM_CAPTURECHANGED:
        break;
    case WM_SETFOCUS:
        //mbSetFocus(getWebviewHandle());
        return 0;

    case WM_KILLFOCUS:
        //mbKillFocus(getWebviewHandle());
        return 0;

    case WM_SETCURSOR:
        if (mbFireWindowsMessageImpl(getWebviewHandle(), hWnd, WM_SETCURSOR, 0, 0, nullptr))
            return 0;
        break;

    case WM_NCHITTEST:
#ifndef _WIN32
        return onNcHittest(lParam); // 只在linux版本下处理
#endif // _WIN32
        break;
    case WM_CHAR:
    {
        unsigned int charCode = (unsigned int)wParam;
        unsigned int flags = 0;
        if (HIWORD(lParam) & KF_REPEAT)
            flags |= MB_REPEAT;
        if (HIWORD(lParam) & KF_EXTENDED)
            flags |= MB_EXTENDED;

        // if (message == WM_IME_CHAR)
        //     OutputDebugStringA("WM_IME_CHAR\n");
        // else
        //     OutputDebugStringA("WM_CHAR\n");
        if (mbFireKeyPressEventImpl(getWebviewHandle(), charCode, flags, WM_IME_CHAR == message))
            return 0;
        break;
    }
    case WM_IME_CHAR: {
        mbFireWindowsMessageImpl(getWebviewHandle(), hWnd, WM_IME_CHAR, wParam, lParam, nullptr);
        return 0; // 这里必须返回0，否则会在WM_IME_STARTCOMPOSITION等消息期间收到WM_CHAR，导致重复显示汉字
    }
    case WM_IME_STARTCOMPOSITION:
        if (mbFireWindowsMessageImpl(getWebviewHandle(), hWnd, WM_IME_STARTCOMPOSITION, wParam, lParam, nullptr))
            return 0;
        break;
    case WM_IME_COMPOSITION: // 这个是输入法有字符时的消息。如果输入法按了空格，就会有WM_IME_CHAR表示确定有字符写入了
        if (mbFireWindowsMessageImpl(getWebviewHandle(), hWnd, WM_IME_COMPOSITION, wParam, lParam, nullptr))
            return 0;
        break;
    case WM_IME_ENDCOMPOSITION:
        if (mbFireWindowsMessageImpl(getWebviewHandle(), hWnd, WM_IME_ENDCOMPOSITION, wParam, lParam, nullptr))
            return 0;
        break;
    }

    return ::DefWindowProcW(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK MbWebView::windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    MbWebView* self = (MbWebView*)GetPropW(hWnd, kClassWndName);
    if (!self) {
        if (message == WM_CREATE) {
            LPCREATESTRUCTW cs = (LPCREATESTRUCTW)lParam;
            self = (MbWebView*)cs->lpCreateParams;
            ((MbWebView*)cs->lpCreateParams)->setHostWnd(hWnd);
            ::SetPropW(hWnd, kClassWndName, (HANDLE)self);
        }
    }

    if (self)
        return self->windowProcImpl(hWnd, message, wParam, lParam);
    else
        return ::DefWindowProcW(hWnd, message, wParam, lParam);
}

void MbWebView::setClientSizeLocked(int w, int h)
{
    ::EnterCriticalSection(&m_clientSizeLock);
    m_clientSize.cx = w;
    m_clientSize.cy = h;
    m_clientSizeDirty = true;
    m_clientResizeRepaintDirty = true;
    ::LeaveCriticalSection(&m_clientSizeLock);

    char output[100] = { 0 };
    sprintf(output, "setClientSizeLocked: %d, %d\n", w, h);
    OutputDebugStringA(output);
}

SIZE MbWebView::getClientSizeLocked()
{
    SIZE size = { 0 };
    ::EnterCriticalSection(&m_clientSizeLock);
    size = m_clientSize;
    ::LeaveCriticalSection(&m_clientSizeLock);
    return size;
}

void MbWebView::setCaretPos(const gfx::Point& pos)
{
    ::EnterCriticalSection(&m_clientSizeLock);
    m_caretPos = pos;
    ::LeaveCriticalSection(&m_clientSizeLock);
}

gfx::Point MbWebView::getCaretPos() const
{
    ::EnterCriticalSection(&m_clientSizeLock);
    gfx::Point pos = m_caretPos;
    ::LeaveCriticalSection(&m_clientSizeLock);
    return pos;
}

void MbWebView::setFocus()
{
    if (m_renderWidgetHostImpl && m_renderWidgetHostImpl->m_webFrameWidget)
        m_renderWidgetHostImpl->m_webFrameWidget->SetFocus(true);
}

void MbWebView::killFocus()
{
    if (m_renderWidgetHostImpl && m_renderWidgetHostImpl->m_webFrameWidget)
        m_renderWidgetHostImpl->m_webFrameWidget->SetFocus(false);
}

void MbWebView::debugShowDomNode()
{
#if !defined(NDEBUG)
    blink::WebLocalFrame* frame = (blink::WebLocalFrame*)(m_renderWidgetHostImpl->m_webWiew->MainFrame());
    if (!frame)
        return;
    blink::WebDocument doc = frame->GetDocument();
    blink::Document* document = (doc);
    std::string out = "debugShowDomNode: " + document->ToTreeStringForThis().Utf8();
    out += "\n";
    OutputDebugStringA(out.c_str());

    //common::writeFile((const WCHAR*)L"G:\\test\\web_test\\Adeds\\360doc.htm", *mbnet::s_htmlData);
#endif
}

blink::WebFrame* MbWebView::getMainFrame() const
{
    if (!m_renderWidgetHostImpl || !m_renderWidgetHostImpl->m_webWiew)
        return nullptr;
    blink::WebLocalFrame* frame = (blink::WebLocalFrame*)(m_renderWidgetHostImpl->m_webWiew->MainFrame());
    return frame;
}

void MbWebView::draggableRegionsChanged(blink::WebVector<blink::WebDraggableRegion> regions)
{
    m_draggableRegion = regions;
}

void MbWebView::onPaintUpdatedInUiThread(const HDC hdc, int x, int y, int cx, int cy)
{
#if defined(OS_WIN)
    mbPaintUpdatedCallback paintUpdatedCallback = getClosure().m_PaintUpdatedCallback;
    if (paintUpdatedCallback) {
        paintUpdatedCallback(getWebviewHandle(), getClosure().m_PaintUpdatedParam, (const HDC)m_surface, x, y, cx, cy);
    }
#endif

#if 0 // defined(OS_WIN)
    mbPaintBitUpdatedCallback paintBitUpdatedCallback = getClosure().m_PaintBitUpdatedCallback;
    if (paintBitUpdatedCallback) {
        mbRect r = { x, y, cx, cy };
        paintBitUpdatedCallback(getWebviewHandle(), getClosure().m_PaintBitUpdatedParam, m_bits, &r, clientSize.cx, clientSize.cy);
    }
#endif

    ::EnterCriticalSection(&m_clientSizeLock);
    m_clientSizeDirty = false;
    ::LeaveCriticalSection(&m_clientSizeLock);
}

void MbWebView::updataBlinkSize()
{
    mbWebView webviewHandle = (mbWebView)m_id;
    if (m_isAsynResizing)
        return;
    m_isAsynResizing = true;

    ThreadCall::callBlinkThreadAsyncWithValidDelayed(MB_FROM_HERE, webviewHandle, 600, [](MbWebView* self) {
        self->m_isAsynResizing = false;
        SIZE clientSize = self->getClientSizeLocked();
        if (self->m_host && self->m_renderWidgetHostImpl && self->m_renderWidgetHostImpl->isSinkReady()
            && self->m_renderWidgetHostImpl /*m_host*/->isAllowResize()) {
            self->m_renderWidgetHostImpl->resizeOnBlinkThread(clientSize.cx, clientSize.cy);
        } else
            self->updataBlinkSize();
    });
}

LRESULT MbWebView::onNcHittest(LPARAM lParam)
{
#ifndef _WIN32
    if (0 == m_ncHittestPadding)
        return HTCLIENT;

    POINT pt;
    pt.x = ((int)(short)LOWORD(lParam));
    pt.y = ((int)(short)HIWORD(lParam));
    ScreenToClient(m_hWnd, &pt);
    RECT rc;
    GetClientRect(m_hWnd, &rc);

    if (pt.y < m_ncHittestPadding) {
        if (pt.x < m_ncHittestPadding)
            return HTTOPLEFT;
        if (pt.x > rc.right - m_ncHittestPadding)
            return HTTOPRIGHT;
        return HTTOP;
    }
    if (pt.y > rc.bottom - m_ncHittestPadding) {
        if (pt.x < m_ncHittestPadding)
            return HTBOTTOMLEFT;
        if (pt.x > rc.right - m_ncHittestPadding)
            return HTBOTTOMRIGHT;
        return HTBOTTOM;
    }
    if (pt.x < m_ncHittestPadding)
        return HTLEFT;

    if (pt.x > rc.right - m_ncHittestPadding)
        return HTRIGHT;
#endif
    return HTCLIENT;
}

// in ui thread
void MbWebView::onResize(int w, int h, bool needSetHostWnd)
{
    if (0 >= w * h)
        return;
    SIZE clientSize = getClientSizeLocked();
    if (clientSize.cx == w && clientSize.cy == h)
        return;

    setClientSizeLocked(w, h);
    updataBlinkSize();

    //copyBitmapWhenResize(w, h, clientSize);

    if (m_isWebWindowMode && needSetHostWnd) {
        HWND hWnd = m_hWnd;
        content::ThreadCall::callUiThreadAsync(FROM_HERE, [hWnd, w, h] { ::SetWindowPos(hWnd, NULL, 0, 0, w, h, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE); });
    }
}

::blink::WebView* MbWebView::getWebView() const
{
    if (!m_renderWidgetHostImpl)
        return nullptr;
    return m_renderWidgetHostImpl->m_webWiew;
}

// bool MbWebView::isDraggableRegionNcHitTest(HWND hWnd)
// {
//     bool handle = false;
//     if (!m_draggableRegion)
//         return handle;
//
//     POINT pos;
//     ::GetCursorPos(&pos);
//     ::ScreenToClient(hWnd, &pos);
//
//     handle = !!::PtInRegion(m_draggableRegion, pos.x, pos.y);
//     return handle;
// }

bool MbWebView::doDraggableRegionNcHitTest(HWND hWnd, int x, int y)
{
    bool handle = PlatformEventHandler::isDraggableRegionNcHitTest(hWnd, gfx::Point(x, y), m_draggableRegion);
    if (handle) {
        HWND hRootWnd = hWnd;
#ifdef _WIN32
        while (true) {
            hWnd = ::GetParent(hWnd);
            if (!hWnd)
                break;
            hRootWnd = hWnd;
        }
#endif // _WIN32
        if (hRootWnd) {
            ::ReleaseCapture();
            ::PostMessageW(hRootWnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
        }
    }
    return handle;
}

void MbWebView::onImeComposition(ImeCompositioType type, WCHAR c)
{
    int64_t id = (int64_t)getWebviewHandle();
    blink::CompositorThreadScheduler* compositingThread = blink::ThreadScheduler::CompositorThreadScheduler();
    scoped_refptr<base::SingleThreadTaskRunner> runner = compositingThread->InputTaskRunner();

    runner->PostTask(FROM_HERE, base::BindOnce([](int64_t id, ImeCompositioType type, WCHAR c) {
        MbWebView* self = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(id);
        if (!self)
            return;
        self->m_platformEventHandler->fireImeComposition((PlatformEventHandler::ImeCompositioHandleType)type, c);
        common::LiveIdDetect::getMbWebviewIds()->unlock(id, self);
    }, id, type, c));
}

void MbWebView::onMouseMessage(unsigned int message, int x, int y, unsigned int flags)
{
    if (!m_enableMouseKeyMessage)
        return;

    if (message == WM_LBUTTONDOWN || message == WM_MBUTTONDOWN || message == WM_RBUTTONDOWN) {
        content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, getWebviewHandle(), [](MbWebView* self) {
            blink::WebViewImpl* webWiew = (blink::WebViewImpl*)(self->m_renderWidgetHostImpl->m_webWiew);
            if (webWiew) {
                webWiew->Focus();
                webWiew->SetIsActive(true);
            }
        });

        bool isNotInDraggableRegion = !doDraggableRegionNcHitTest(m_hWnd, x, y);
        if (::GetFocus() != m_hWnd && isNotInDraggableRegion && g_enableNativeSetFocus) {
            ::SetFocus(m_hWnd);
        }
        if (isNotInDraggableRegion && g_enableNativeSetCapture)
            ::SetCapture(m_hWnd);
    } else if (message == WM_LBUTTONUP || message == WM_MBUTTONUP || message == WM_RBUTTONUP) {
        ::ReleaseCapture();
    }

    //onCursorChange();

    bool needCommit = true;
    ::EnterCriticalSection(&m_mouseMsgQueueLock);
    needCommit = m_mouseMsgQueue.size() == 0;
    m_mouseMsgQueue.push_back(new MouseMsg(message, x, y, flags));
    ::LeaveCriticalSection(&m_mouseMsgQueueLock);

    if (!needCommit)
        return;

#if 1
    int64_t id = (int64_t)getWebviewHandle();
    blink::CompositorThreadScheduler* compositingThread = blink::ThreadScheduler::CompositorThreadScheduler();
    scoped_refptr<base::SingleThreadTaskRunner> runner = compositingThread->InputTaskRunner();
    if (m_isPopupWidgetMode) { // 弹出的下拉框直接在blink线程里响应消息
        runner = RenderThreadImpl::get()->getTaskRunner();
    }

    runner->PostTask(FROM_HERE, base::BindOnce([](int64_t id) {
        MbWebView* self = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(id);
        if (!self)
            return;
        self->delayDoMouseMsgInCompositorThread();
        common::LiveIdDetect::getMbWebviewIds()->unlock(id, self);
    }, id));
#else
    content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, getWebviewHandle(), [](MbWebView* self) { self->delayDoMouseMsgInCompositorThread(); });
#endif
}

bool MbWebView::onKeyUp(unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    WPARAM wParam = virtualKeyCode;
    LPARAM lParam = 0;

    if (flags & MB_REPEAT)
        lParam |= ((KF_REPEAT) >> 16);
    if (flags & MB_EXTENDED)
        lParam |= ((KF_EXTENDED) >> 16);

    blink::WebKeyboardEvent keyEvent = content::PlatformEventHandler::buildKeyboardEvent(blink::WebInputEvent::Type::kKeyUp, WM_KEYUP, wParam, lParam);
    if (m_platformEventHandler.get())
        m_platformEventHandler->fireInputEventToCompositingThread(keyEvent);
    return true;
}

bool MbWebView::onKeyDown(unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey)
{
    //     CHECK_FOR_REENTER(this, false);
    //     freeV8TempObejctOnOneFrameBefore();

    WPARAM wParam = virtualKeyCode;
    LPARAM lParam = flags;
#if defined(OS_WIN)
//     if (m_popup && m_popup->isVisible())
//         return m_popup->fireKeyUpEvent(message, wParam, lParam);
#endif
    //WTF::TemporaryChange<bool> temporaryChange(g_isBackKeyDown, true);

    blink::WebKeyboardEvent keyEvent = content::PlatformEventHandler::buildKeyboardEvent(blink::WebInputEvent::Type::kRawKeyDown, WM_KEYDOWN, wParam, lParam);
    if (m_platformEventHandler.get())
        m_platformEventHandler->fireInputEventToCompositingThread(keyEvent);
    bool systemKey = false;
    // These events cannot be canceled, and we have no default handling for them.
    // FIXME: match IE list more closely, see <http://msdn2.microsoft.com/en-us/library/ms536938.aspx>.
    if (systemKey && virtualKeyCode != VK_RETURN)
        return false;

    return true;
}

bool MbWebView::onKeyPress(unsigned int charCode, unsigned int flags, BOOL isSystemKey)
{
    //     if (fireImeEventToNpPlugin(message, wParam, m_webViewImpl->focusedCoreFrame(), m_webViewImpl->focusedElement()))
    //         return true;

    WPARAM wParam = charCode;
    LPARAM lParam = flags;
    UINT message = WM_CHAR;
    if (isSystemKey)
        message = WM_IME_CHAR;

    blink::WebKeyboardEvent keyEvent = content::PlatformEventHandler::buildKeyboardEvent(blink::WebInputEvent::Type::kChar, message, wParam, lParam);
    if (m_platformEventHandler.get())
        m_platformEventHandler->fireInputEventToCompositingThread(keyEvent);
    return true;
}

void MbWebView::delayDoMouseMsgInCompositorThread()
{
    ::EnterCriticalSection(&m_mouseMsgQueueLock);
    if (0 == m_mouseMsgQueue.size()) {
        ::LeaveCriticalSection(&m_mouseMsgQueueLock);
        return;
    }

    std::list<MouseMsg*> mouseMsgQueue;
    bool hasMouseMove = false;
    MouseMsg* mouseMsg = nullptr;
    std::list<MouseMsg*>::reverse_iterator it = m_mouseMsgQueue.rbegin();
    for (; it != m_mouseMsgQueue.rend(); ++it) {
        mouseMsg = *it;
        if (WM_MOUSEMOVE != (*it)->message) {
            mouseMsgQueue.push_back(new MouseMsg(mouseMsg->message, mouseMsg->x, mouseMsg->y, mouseMsg->flags));
        } else if (!hasMouseMove) {
            hasMouseMove = true;
            mouseMsgQueue.push_back(new MouseMsg(mouseMsg->message, mouseMsg->x, mouseMsg->y, mouseMsg->flags));
        }
        delete mouseMsg;
    }
    m_mouseMsgQueue.clear();
    ::LeaveCriticalSection(&m_mouseMsgQueueLock);

    for (it = mouseMsgQueue.rbegin(); it != mouseMsgQueue.rend(); ++it) {
        mouseMsg = *it;
        //wkeFireMouseEvent(m_wkeWebview, mouseMsg->message, mouseMsg->x /*+ m_offset.x*/, mouseMsg->y /*+ m_offset.y*/, mouseMsg->flags);

        if (mouseMsg->message == WM_MOUSELEAVE) {
            mouseMsg->x = MINSHORT;
            mouseMsg->y = MINSHORT;
        }

        BOOL handled = TRUE;
        WPARAM wParam = 0;
        LPARAM lParam = MAKELPARAM(mouseMsg->x, mouseMsg->y);
        if (mouseMsg->flags & MB_CONTROL)
            wParam |= MK_CONTROL;
        if (mouseMsg->flags & MB_SHIFT)
            wParam |= MK_SHIFT;

        if (mouseMsg->flags & MB_LBUTTON)
            wParam |= MK_LBUTTON;
        if (mouseMsg->flags & MB_MBUTTON)
            wParam |= MK_MBUTTON;
        if (mouseMsg->flags & MB_RBUTTON)
            wParam |= MK_RBUTTON;

        content::PlatformEventHandler::MouseEvtInfo info = { true, false /*pagePreDestroy <= m_state*/, m_draggableRegion, m_renderWidgetHostImpl.get() };
        if (m_platformEventHandler.get())
            m_platformEventHandler->fireMouseEvent(m_hWnd, mouseMsg->message, wParam, lParam, info, &handled);

        delete mouseMsg;
    }
}

bool MbWebView::setCursorInfoTypeByCache()
{
    m_isCursorInfoTypeAsynChanged = false;
    if (m_isInNotClient)
        return false;

    HCURSOR hCur = NULL;
    switch (m_cursor.type()) {
    case ui::mojom::CursorType::kPointer:
        hCur = ::LoadCursorW(NULL, IDC_ARROW);
        break;
    case ui::mojom::CursorType::kIBeam:
        hCur = ::LoadCursorW(NULL, IDC_IBEAM);
        break;
    case ui::mojom::CursorType::kProgress: //
        hCur = ::LoadCursorW(NULL, IDC_APPSTARTING);
        break;
    case ui::mojom::CursorType::kCross:
        hCur = ::LoadCursorW(NULL, IDC_CROSS);
        break;
    case ui::mojom::CursorType::kMove:
        hCur = ::LoadCursorW(NULL, IDC_SIZEALL);
        break;
    case ui::mojom::CursorType::kColumnResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZEWE);
        break;
    case ui::mojom::CursorType::kRowResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZENS);
        break;
    case ui::mojom::CursorType::kHand:
        hCur = ::LoadCursorW(NULL, IDC_HAND);
        break;
    case ui::mojom::CursorType::kWait:
        hCur = ::LoadCursorW(NULL, IDC_WAIT);
        break;
    case ui::mojom::CursorType::kHelp:
        hCur = ::LoadCursorW(NULL, IDC_HELP);
        break;
    case ui::mojom::CursorType::kEastResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZEWE);
        break;
    case ui::mojom::CursorType::kNorthResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZENS);
        break;
    case ui::mojom::CursorType::kSouthWestResize:
    case ui::mojom::CursorType::kNorthEastResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZENESW);
        break;
    case ui::mojom::CursorType::kSouthResize:
    case ui::mojom::CursorType::kNorthSouthResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZENS);
        break;
    case ui::mojom::CursorType::kNorthWestResize:
    case ui::mojom::CursorType::kSouthEastResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZENWSE);
        break;
    case ui::mojom::CursorType::kWestResize:
    case ui::mojom::CursorType::kEastWestResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZEWE);
        break;
    case ui::mojom::CursorType::kNorthEastSouthWestResize:
    case ui::mojom::CursorType::kNorthWestSouthEastResize:
        hCur = ::LoadCursorW(NULL, IDC_SIZEALL);
        break;
    case ui::mojom::CursorType::kNoDrop:
    case ui::mojom::CursorType::kNotAllowed:
        hCur = ::LoadCursorW(NULL, IDC_NO);
        break;
    case ui::mojom::CursorType::kCustom:
    {
#ifdef _WIN32
        base::win::ScopedHICON customHicon = IconUtil_CreateCursorFromSkBitmap(m_cursor.custom_bitmap(), m_cursor.custom_hotspot());
        ::SetCursor(customHicon.get());
        return true;
#endif
    }
        break;
    default:
        break;
    }

    if (hCur) {
#if defined(WIN32)
        ::SetCursor(hCur);
#else
        ::linuxSetCursor(m_hWnd, hCur);
#endif
        return true;
    }

    return false;
}

void MbWebView::setCursor(const ::ui::Cursor& cursor)
{
    if (m_cursor == cursor)
        return;
    m_cursor = cursor;

    if (m_hWnd)
        ::PostMessageW(m_hWnd, WM_SETCURSOR, (WPARAM)m_hWnd, MAKELONG(HTCLIENT, 0)); // COleControl::OnSetCursor
}

int MbWebView::getCursorInfoType() const
{
    return (int)(m_cursor.type());
}

HDC MbWebView::getViewDC()
{
#if 1 // defined(OS_WIN)
    if (!m_memoryCanvasLock)
        return nullptr;

    if (m_memoryCanvasLockCount > 0)
        MessageBoxA(0, "MbWebView::getViewDC lock is not matching", 0, 0);
    m_memoryCanvasLockCount++;
    m_memoryCanvasLock->Acquire();
    return (HDC)m_surface;
#else
    return nullptr;
#endif
}

void MbWebView::unlockViewDC()
{
#if 1 // defined(OS_WIN)
    if (m_memoryCanvasLock) {
        --m_memoryCanvasLockCount;
        m_memoryCanvasLock->Release();
    }
#endif
}

void MbWebView::onAllocatedBitmapMemory(const gfx::Size& pixelSize, void* surface, unsigned char* bitmap, void* lock)
{
    if (!m_memoryCanvasLock)
        m_memoryCanvasLock = (base::Lock*)lock;
    else
        CHECK(m_memoryCanvasLock == lock);

    m_bitmapByteSize = pixelSize;
    m_bitmapByte = bitmap;
    m_surface = surface;
}

void MbWebView::onAllocatedSharedMemory(const gfx::Size& pixelSize, HDC dibDC, void* lock)
{
#if defined(OS_WIN)
    m_surface = dibDC;

    if (!m_memoryCanvasLock)
        m_memoryCanvasLock = (base::Lock*)lock;
    else
        CHECK(m_memoryCanvasLock == lock);
#endif
}

void MbWebView::onPaint(HWND hWnd, WPARAM wParam)
{
    if (WS_EX_LAYERED == (WS_EX_LAYERED & GetWindowLongW(hWnd, GWL_EXSTYLE)))
        return;

    PAINTSTRUCT ps = { 0 };
    HDC hdc = ::BeginPaint(hWnd, &ps);

    RECT rcClip = ps.rcPaint;

    RECT rcClient;
    ::GetClientRect(hWnd, &rcClient);

    RECT rcInvalid = rcClient;
    if (rcClip.right != rcClip.left && rcClip.bottom != rcClip.top)
        ::IntersectRect(&rcInvalid, &rcClip, &rcClient);

    int srcX = rcInvalid.left - rcClient.left;
    int srcY = rcInvalid.top - rcClient.top;
    int destX = rcInvalid.left;
    int destY = rcInvalid.top;
    int width = rcInvalid.right - rcInvalid.left;
    int height = rcInvalid.bottom - rcInvalid.top;

    if (0 != width && 0 != height) {
#if defined(OS_WIN)
        if (m_clientResizeRepaintDirty) {
            ::FillRect(hdc, &ps.rcPaint, (HBRUSH)::GetStockObject(LTGRAY_BRUSH)); // resize的时候设置这个
            m_clientResizeRepaintDirty = false;
        }

        HDC hMbDC = getViewDC();
        if (hMbDC) {
            ::BitBlt(hdc, destX, destY, width, height, hMbDC, srcX, srcY, SRCCOPY);
        } else if (m_hasBackgroundColor) {
            HBRUSH br = ::CreateSolidBrush(m_backgroundColor & 0x00ffffff);
            ::FillRect(hdc, &ps.rcPaint, br);
            ::DeleteObject(br);
        } else
            ::FillRect(hdc, &ps.rcPaint, (HBRUSH)::GetStockObject(WHITE_BRUSH));

        //         RECT rcPaintxx = { 10, 10, 200, 150 };
        //         HBRUSH brush = CreateSolidBrush(0xff0000 | (RGB(0xff, 0x22, 0x34)));
        //         ::FillRect(hMbDC, &rcPaintxx, brush); // !!!
        //         ::DeleteObject(brush);

        unlockViewDC();
#else
        if (IsLinuxOpenglDraw() && m_bitmapByte) {
            m_memoryCanvasLock->Acquire();
            //unsigned int glTexture = (unsigned int)wParam;
            //glBindTexture(GL_TEXTURE_2D, glTexture);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_bitmapByteSize.width(), m_bitmapByteSize.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_bitmapByte);
            glGenerateMipmap(GL_TEXTURE_2D);

            m_memoryCanvasLock->Release();
        } else if (m_surface) { // m_surface from OffscreenWindowUpdater::OnAllocatedBitmapMemory
            m_memoryCanvasLock->Acquire();
            cairo_t* cr = (cairo_t*)wParam;

            cairo_surface_t* surface = (cairo_surface_t*)m_surface;
            cairo_surface_flush(surface);
            //--
            //unsigned char* byteData = cairo_image_surface_get_data(surface);
            //unsigned __int32* sourceData = (unsigned __int32*)byteData;
            //int stride = cairo_image_surface_get_stride(surface) / 4;
            //
            //for (int y = 0; y < 10; y++) {
            //    for (int x = 0; x < 10; x++) {
            //        sourceData[y * stride + x] = 0xff112233;
            //    }
            //}
            //--
            cairo_surface_mark_dirty(surface);
            cairo_set_source_surface(cr, surface, 0, 0);
            m_memoryCanvasLock->Release();
        }
#endif
    }

    ::EndPaint(hWnd, &ps);
}

void MbWebView::setIsTransparent(bool b)
{
    m_isTransparent = b;

    if (ThreadCall::isBlinkThread()) {
        if (m_renderWidgetHostImpl && m_renderWidgetHostImpl->m_webWiew) {
            blink::WebViewImpl* webview = (blink::WebViewImpl*)m_renderWidgetHostImpl->m_webWiew;
            webview->SetBaseBackgroundColorOverrideTransparent(b);
            return;
        }
    }

    mbWebView webviewHandle = (mbWebView)m_id;
    ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [b](content::MbWebView* webview) { webview->setIsTransparent(b); });
}

void MbWebView::setContextMenuEnable(bool b)
{
    m_isContextMenuEnable = b;
}

void MbWebView::setShow(int nCmdShow /*, bool isActivate*/)
{
    m_isShow = nCmdShow == 1;
    ::ShowWindow(m_hWnd, nCmdShow);
}

static void setWindowTitleImpl(content::MbWebView* webview, int count)
{
    int64_t id = webview->getId();
    base::SequencedTaskRunner::GetCurrentDefault()->PostNonNestableDelayedTask(MB_FROM_HERE,
        base::BindOnce(
            [](int64_t id, int count) {
                count++;
                content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
                if (!webview || count > 3)
                    return;
                if (webview->setWindowTitle(webview->getWindowTitle()))
                    return;
                setWindowTitleImpl(webview, count);
            }, id, count),
        base::Microseconds(1000));
}

bool MbWebView::setWindowTitle(const std::string& title)
{
    m_windowTitle = title;

    if (m_hWnd) {
        std::u16string titleW = utf8ToUtf16(m_windowTitle);
        ::SetWindowTextW(m_hWnd, (LPCWSTR)titleW.c_str());
        return true;
    }

    int count = 0;
    setWindowTitleImpl(this, count);
    return false;
}

void setRequestHead(blink::WebLocalFrame* webFrame, blink::WebURLRequest& request);

extern const char* kAcceptHeader;
extern const char* kDefaultAcceptHeader;

void MbWebView::loadUrl(const char* urlStr)
{
    if (!m_frameClient) { // gtk模式下，有可能要等到s_gtkActivate以后才有m_frameClient
        mbWebView webviewHandle = (mbWebView)m_id;
        std::string* urlString = new std::string(urlStr);
        content::ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewHandle, [urlString](MbWebView* self) {
            self->loadUrl(urlString->c_str());
            delete urlString;
        });
        return;
    }

    blink::WebNavigationControl* navigationControl = m_frameClient->m_navigationControl;

    blink::KURL url(WTF::String::FromUTF8(urlStr));
    if (!url.IsValid()) {
        String protocol = url.Protocol();
        if (protocol.empty() && protocol != "about:blank") {
            std::string urlTemp = urlStr;
            urlTemp = "http://" + urlTemp;
            url = blink::KURL(WTF::String::FromUTF8(urlTemp.c_str()));
        }
    }

    blink::WebNavigationInfo info;
    info.url_request.SetUrl(url);
    if (!navigationControl->WillStartNavigation(info))
        DebugBreak();

    blink::WebURLRequest urlRequest;
    urlRequest.SetUrl(url);
    urlRequest.AddHttpHeaderField(blink::WebString::FromLatin1(kAcceptHeader), blink::WebString::FromLatin1(kDefaultAcceptHeader));

    setRequestHead((blink::WebLocalFrame*)navigationControl, urlRequest);
    navigationControl->Load(urlRequest, blink::WebFrameLoadType::kStandard, blink::WebHistoryItem());
}

bool MbWebView::loadHTMLString(const std::string& html, const std::string& baseUrl)
{
    if (!m_renderWidgetHostImpl)
        return false;

    blink::WebLocalFrameImpl* impl = blink::To<blink::WebLocalFrameImpl>(m_renderWidgetHostImpl->m_mainFrame);
    if (!impl)
        return false;

    std::unique_ptr<blink::WebNavigationParams> navigationParams
        = blink::WebNavigationParams::CreateWithHTMLStringForTesting(base::span<const char>(html.c_str(), html.size()),
            blink::WebURL(blink::KURL(String::FromUTF8(baseUrl))));
    impl->CommitNavigation(std::move(navigationParams), nullptr /* extra_data */);

    return true;
}

void MbWebView::reload(bool force)
{
    if (!m_renderWidgetHostImpl || !m_renderWidgetHostImpl->m_mainFrame)
        return;
    m_renderWidgetHostImpl->m_mainFrame->StartReload(force ? blink::WebFrameLoadType::kReload : blink::WebFrameLoadType::kReloadBypassingCache);
}

LRESULT MbWebView::fireWheelEventOnUiThread(WPARAM wParam, LPARAM lParam)
{
    if (m_platformEventHandler.get())
        m_platformEventHandler->fireWheelEvent(m_hWnd, wParam, lParam);
    return 0;
}

scoped_refptr<mbnet::PageNetExtraData> MbWebView::getPageNetExtraData()
{
    if (m_pageNetExtraData)
        return m_pageNetExtraData;
    return nullptr;
}

mbnet::WebCookieJarImpl* MbWebView::getWebCookieJarImpl()
{
    mbnet::WebCookieJarImpl* ret = nullptr;
    if (m_pageNetExtraData)
        ret = m_pageNetExtraData->getCookieJar();
    if (ret)
        return ret;
    return mbnet::WebURLLoaderManager::sharedInstance()->getShareCookieJar();
}

void MbWebView::setCookieJarFullPath(const char* path)
{
    if (!m_pageNetExtraData)
        m_pageNetExtraData = new mbnet::PageNetExtraData();
    m_pageNetExtraData->setCookieJarFullPath(path);
}

void MbWebView::setLocalStorageFullPath(const char* path)
{
    if (!m_pageNetExtraData)
        m_pageNetExtraData = new mbnet::PageNetExtraData();
    m_pageNetExtraData->setLocalStorageDir(path);
}

base::FilePath MbWebView::getLocalStorageDir()
{
    if (!m_pageNetExtraData)
        m_pageNetExtraData = new mbnet::PageNetExtraData();
    return m_pageNetExtraData->getLocalStorageDir();
}

base::FilePath MbWebView::getDownloadDirPath()
{
    if (!m_pageNetExtraData)
        m_pageNetExtraData = new mbnet::PageNetExtraData();
    return m_pageNetExtraData->getDownloadDirPath();
}

void MbWebView::dispatchUrlCheanged(const std::string& url)
{
    BOOL canGoBack = historyBackListCount() > 0;
    BOOL canGoForward = historyForwardListCount() > 0;

    m_url = url;

    if (!(getClosure().m_URLChangedCallback))
        return;

    mbWebView webviewHandle = m_frameClient->getMbwebviewId();
    std::string* urlStr = new std::string(url);

    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webviewHandle, urlStr, canGoBack, canGoForward]() {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
        if (webview)
            webview->getClosure().m_URLChangedCallback(webviewHandle, webview->getClosure().m_URLChangedParam, urlStr->c_str(), canGoBack, canGoForward);
        delete urlStr;
    });
}

bool MbWebView::canGoForward() const
{
    return historyForwardListCount() > 0;
}

bool MbWebView::canGoBack() const
{
    return historyBackListCount() > 0;
}

void MbWebView::didCommitProvisionalLoad(
    blink::WebLocalFrame* frame, const blink::WebHistoryItem& history, blink::WebHistoryCommitType type, bool isSameDocument)
{
    m_hasDispatchWillCommitProvisionalLoad = true; // 有第一个数据来到的时候会调用
    m_navigationController->insertOrReplaceEntry(frame, history, type, isSameDocument);

    if ((m_renderWidgetHostImpl && m_renderWidgetHostImpl->m_mainFrame == frame) || frame->Top() == frame) {
        blink::WebDocument doc = frame->GetDocument();
        blink::WebURL url = doc.Url();
        dispatchUrlCheanged(url.GetString().Utf8());
    }
}

blink::WebHistoryItem MbWebView::historyItemForNewChildFrame(blink::WebFrame* frame)
{
    return m_navigationController->historyItemForNewChildFrame(frame);
}

void MbWebView::navigateBackForwardSoon(int offset)
{
    m_navigationController->navigateBackForwardSoon(offset);
}

int MbWebView::historyBackListCount() const
{
    return m_navigationController->historyBackListCount();
}

int MbWebView::historyForwardListCount() const
{
    return m_navigationController->historyForwardListCount();
}

void MbWebView::navigateToIndex(int index)
{
    m_navigationController->navigateToIndex(index);
}

void MbWebView::onDidCreateScriptContext(v8::Local<v8::Context> context, int32_t worldId, const blink::LocalFrameToken& token)
{
    BindJsQuery::bindFun(context, getClosure().m_jsQueryClosure, getClosure().m_jsQueryClosure2, this, token); // !!!!!!!

#if ENABLE_IN_MB_MAIN
#if ENABLE_NODEJS
    //TODO old onDidCreateScriptContext
    v8::Local<v8::Context>& v8context = *(v8::Local<v8::Context>*)context;
    if (self->m_isEnableNode)
        self->startupNodejsEnv(v8context);
#endif
#endif

    void* param = getClosure().m_DidCreateScriptContextParam;
    mbDidCreateScriptContextCallback callback = getClosure().m_DidCreateScriptContextCallback;
    if (callback)
        callback((mbWebView)m_id, param, (mbWebFrameHandle)(blink::LocalFrameToken::Hasher()(token)), &context, 0, worldId);
}

void MbWebView::onWillReleaseScriptContext(v8::Local<v8::Context> context, int32_t worldId, const blink::LocalFrameToken& token)
{
    void* param = getClosure().m_WillReleaseScriptContextParam;
    mbWillReleaseScriptContextCallback callback = getClosure().m_WillReleaseScriptContextCallback;
    if (callback)
        callback((mbWebView)m_id, param, (mbWebFrameHandle)(blink::LocalFrameToken::Hasher()(token)), &context, worldId);
}

mb::MbJsValue* MbWebView::runJsOnBlinkThreadImpl(
    mbWebFrameHandle frameId, int worldId, std::string* codeStr, BOOL isInClosure, mbRunJsCallback callback, void* param)
{
    //RefPtr<blink::UserGestureToken> userGestureToken = blink::UserGestureIndicator::currentToken();
    blink::WebLocalFrame* frame = nullptr;
    if ((mbWebFrameHandle)-2 != frameId) {
        blink::LocalFrame* blinkFrame = blink::FromFrameTokenHash((size_t)(frameId));
        if (!blinkFrame)
            return nullptr;
        frame = blink::WebLocalFrameImpl::FromFrame(blinkFrame);
    } else {
        if (!m_renderWidgetHostImpl)
            return nullptr;
        frame = m_renderWidgetHostImpl->m_mainFrame;
    }

    if (base::StartsWith(*codeStr, "javascript:", base::CompareCase::INSENSITIVE_ASCII))
        //scriptString->Remove(0, sizeof("javascript:") - 1);
        codeStr->erase(codeStr->end() - (sizeof("javascript:") - 1));

    if (isInClosure) {
        codeStr->insert(0, "(function(){");
        codeStr->append("})();");
    }
    blink::WebScriptSource code(blink::WebString::FromUTF8(*codeStr), blink::KURL("http://CWebView_runJS.com/"));

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope handleScope(isolate);

    v8::Local<v8::Context> context;
    v8::Local<v8::Value> result;
    if (0 == worldId) {
        context = frame->MainWorldScriptContext();
        v8::Context::Scope contextScope(context);
        result = frame->ExecuteScriptAndReturnValue(code);
    } else {
        context = frame->GetScriptContextFromWorldId(isolate, worldId);
        v8::Context::Scope contextScope(context);
        result = frame->ExecuteScriptInIsolatedWorldAndReturnValue(worldId, code, blink::BackForwardCacheAware::kAllow);
    }

    //wke::AutoAllowRecordJsExceptionInfo autoAllowRecordJsExceptionInfo;
    return mb::MbJsValue::v8ValueToMb(isolate, context, result);
}

static void callRunJsCallbackOnUiThread(mbWebView webviewHandle, void* param, mbRunJsCallback callback, void* es, mb::MbJsValue* mbVal)
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (webview)
        callback(webviewHandle, param, es, mbVal->getId());
    mbVal->deref();

    freeTempCharStrings();
}

void runJsOnBlinkThread(
    mbWebView webviewHandle, mbWebFrameHandle frameId, int worldId, std::string* scriptString, BOOL isInClosure, mbRunJsCallback callback, void* param)
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewHandle);
    if (!webview) {
        delete scriptString;
        return;
    }

    mb::MbJsValue* mbVal = webview->runJsOnBlinkThreadImpl(frameId, worldId, scriptString, isInClosure, callback, param);

    if (callback) {
        content::ThreadCall::callUiThreadAsync(
            MB_FROM_HERE, [webviewHandle, param, callback, mbVal] { callRunJsCallbackOnUiThread(webviewHandle, param, callback, nullptr, mbVal); });
    }
    delete scriptString;
}

void MbWebView::setUserKeyValue(const char* key, void* value)
{
    ::EnterCriticalSection(&m_userKeyValuesLock);
    m_userKeyValues[key] = value;
    ::LeaveCriticalSection(&m_userKeyValuesLock);
}

void* MbWebView::getUserKeyValue(const char* key) const
{
    ::EnterCriticalSection(&m_userKeyValuesLock);
    std::map<std::string, void*>::const_iterator it = m_userKeyValues.find(key);
    if (m_userKeyValues.end() == it) {
        ::LeaveCriticalSection(&m_userKeyValuesLock);
        return nullptr;
    }
    void* ret = it->second;
    ::LeaveCriticalSection(&m_userKeyValuesLock);
    return ret;
}

void onWebviewDidFirstVisuallyNonEmptyPaint(int64_t webviewId)
{
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webviewId] {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewId);
        if (!webview || !webview->getFrameClient())
            return;
        webview->getFrameClient()->onLoadingSucceeded();
    });
}

void MbWebView::setProxy(const mbProxy* proxy)
{
    if (!m_pageNetExtraData)
        m_pageNetExtraData = new mbnet::PageNetExtraData();
    m_pageNetExtraData->setProxy(proxy);
}

const mbProxy* MbWebView::getProxy() const
{
    if (!m_pageNetExtraData)
        return nullptr;
    return m_pageNetExtraData->getProxy();
}

void MbWebView::setSetLanguage(const std::string& lang)
{
    blink::RendererPreferences pref = m_renderWidgetHostImpl->m_webWiew->GetRendererPreferences();
    pref.accept_languages = lang;// WTF::String::FromUTF8((const uint8_t*)lang.c_str(), lang.size());
    m_renderWidgetHostImpl->m_webWiew->SetRendererPreferences(pref);
}

std::string MbWebView::getSetLanguage() const
{
    std::string result = "en";
    if (!m_renderWidgetHostImpl || !m_renderWidgetHostImpl->m_webWiew)
        return result;
    const blink::RendererPreferences& pref = m_renderWidgetHostImpl->m_webWiew->GetRendererPreferences();
    if (pref.accept_languages.empty())
        return result;
    return pref.accept_languages;
}

}