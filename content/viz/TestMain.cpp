
#include "content/browser/LocalFrameHostImpl.h"

#include "content/renderer/RendererBlinkPlatformImpl.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/renderer/AssociatedInterfaceProviderImpl.h"
#include "content/renderer/BlinkInterfaceRegistryImpl.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/browser/RenderWidgetHostImpl.h"
#include "content/browser/LocalMainFrameHostImpl.h"
#include "content/browser/BackForwardCacheControllerHostImpl.h"
#include "content/browser/RestrictedCookieManagerImpl.h"
#include "third_party/blink/public/web/web_view_client.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/public/web/win/web_font_rendering.h"
#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/blink.h"
#include "third_party/blink/public/web/web_navigation_control.h"
#include "third_party/blink/public/web/web_frame_widget.h"
#include "third_party/blink/public/web/web_settings.h"
#include "third_party/blink/public/web/web_console_message.h"
#include "third_party/blink/public/platform/cross_variant_mojo_util.h"
#include "third_party/blink/public/platform/scheduler/web_thread_scheduler.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/public/platform/interface_registry.h"
#include "third_party/blink/public/common/tokens/tokens.h"
#include "third_party/blink/public/common/associated_interfaces/associated_interface_provider.h"
#include "third_party/blink/public/common/browser_interface_broker_proxy.h"
#include "third_party/blink/public/mojom/frame/policy_container.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "third_party/blink/public/mojom/associated_interfaces/associated_interfaces.mojom.h"
#include "third_party/blink/public/mojom/browser_interface_broker.mojom.h"
#include "third_party/blink/public/mojom/loader/resource_load_info_notifier.mojom.h"
#include "third_party/blink/public/platform/weak_wrapper_resource_load_info_notifier.h"
#include "third_party/blink/public/platform/web_url_loader.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/navigation_body_loader.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/core/loader/document_loader.h"
#include "third_party/blink/public/platform/web_back_forward_cache_loader_helper.h"
#include "third_party/blink/public/platform/scheduler/web_resource_loading_task_runner_handle.h"
#include "third_party/blink/public/platform/web_url_loader_client.h"
#include "third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"
#include "services/viz/privileged/mojom/compositing/frame_sink_manager.mojom.h"
#include "services/network/public/mojom/url_response_head.mojom.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"
#include "services/network/public/cpp/resource_request.h"
#include "components/viz/common/gpu/context_provider.h"
#include "components/viz/host/renderer_settings_creation.h"
#include "cc/mojo_embedder/async_layer_tree_frame_sink.h"
#include "third_party/skia/include/ports/SkTypeface_win.h"
#include "mojo/public/cpp/bindings/binder_map.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "content/demo/DemoHost.h"
#include "content/demo/DemoClient.h"
#include "content/demo/DemoService.h"
#include "mbvip/core/mb.h"
#include "mbnet/LoaderFactoryImpl.h"
#include "mbnet/WebURLLoaderImplCurl.h"
#include "base/run_loop.h"
#include "base/command_line.h"
#include "base/message_loop/message_pump_type.h"
#include "base/task/single_thread_task_executor.h"
#include "base/task/thread_pool/thread_pool_instance.h"
#include "base/threading/platform_thread.h"
#include "base/win/scoped_com_initializer.h"
#include "base/strings/utf_string_conversions.h"
#include "base/at_exit.h"
#include "base/memory/discardable_memory_allocator.h"
#include "third_party/icu/source/common/unicode/udata.h"
#include <windows.h>

HWND g_hRootWnd = nullptr;
const LPCWSTR kClassName = L"WebBrowserContainer";
SIZE g_wndSize = { 900, 600 };

void readFileToBuf(const char* path, std::vector<char>* buffer)
{
    const char kHead[] = "file:///";
    std::string url = path;
    if (0 == url.find(kHead))
        url = url.substr(sizeof(kHead) - 1);
    std::u16string urlW = base::UTF8ToUTF16(url);

    buffer->clear();
    HANDLE hFile = CreateFileW((const WCHAR*)urlW.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile)
        return;

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (0 == bufferSize)
        return;

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
}

LRESULT CALLBACK ieWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    //     if (WM_MOUSEMOVE != message && WM_TIMER != message && WM_NCHITTEST != message && WM_SETCURSOR != message) {
    //         char* output = (char*)malloc(0x100);
    //         sprintf_s(output, 0x99, "WndProc: %x\n", message);
    //         OutputDebugStringA(output);
    //         free(output);
    //     }

    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_INITMENUPOPUP:
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//blink::scheduler::WebAgentGroupScheduler* g_agentGroupScheduler = nullptr;
//
// class TestHost : public viz::HostFrameSinkClient {
// public:
//     content::RenderWidgetHostImpl* m_renderWidgetHostImpl = nullptr;
//     demo::DemoService* m_service;
//
//     mojo::AssociatedRemote<viz::mojom::DisplayPrivate> m_displayPrivate;
//     std::unique_ptr<viz::HostDisplayClient> m_displayClient;
//     viz::HostFrameSinkManager m_hostFrameSinkManager;
//
//     std::unique_ptr<cc::mojo_embedder::AsyncLayerTreeFrameSink> m_frameSink;
//
//     TestHost(
//         content::RenderWidgetHostImpl* renderWidgetHostImpl,
//         demo::DemoService* service,
//         mojo::PendingReceiver<viz::mojom::FrameSinkManagerClient> frameSinkManagerClientReceiver,
//         mojo::PendingRemote<viz::mojom::FrameSinkManager> frameSinkManager
//         )
//     {
//         m_renderWidgetHostImpl = renderWidgetHostImpl;
//         m_service = service;
//
//         m_displayClient = std::make_unique<viz::HostDisplayClient>(g_hRootWnd);
//         viz::mojom::RootCompositorFrameSinkParamsPtr root_params = viz::mojom::RootCompositorFrameSinkParams::New();
//
//         ::mojo::PendingAssociatedRemote<viz::mojom::CompositorFrameSink> sink_remote;
//         root_params->compositor_frame_sink = sink_remote.InitWithNewEndpointAndPassReceiver();
//
//         ::mojo::PendingReceiver<::viz::mojom::CompositorFrameSinkClient> client_receiver = root_params->compositor_frame_sink_client.InitWithNewPipeAndPassReceiver();
//         root_params->display_private = m_displayPrivate.BindNewEndpointAndPassReceiver();
//         root_params->display_client = m_displayClient->GetBoundRemote(nullptr);
//
//         constexpr viz::FrameSinkId root_frame_sink_id(0xdead, 0xbeef);
//         root_params->frame_sink_id = root_frame_sink_id;
//         root_params->widget = g_hRootWnd;
//         root_params->gpu_compositing = false;
//         root_params->renderer_settings = viz::CreateRendererSettings();
//
//         //m_renderWidgetHostImpl->setFrameSinkId(root_frame_sink_id);
//
//         m_hostFrameSinkManager.SetServiceRunner(m_service->GetCompositorThreadRunner());
//         m_hostFrameSinkManager.BindAndSetManager(std::move(frameSinkManagerClientReceiver), nullptr, std::move(frameSinkManager));
//         m_hostFrameSinkManager.RegisterFrameSinkId(root_params->frame_sink_id, this, viz::ReportFirstSurfaceActivation::kNo);
//         m_hostFrameSinkManager.CreateRootCompositorFrameSink(std::move(root_params));
//
//         m_service->GetCompositorThreadRunner()->PostTask(FROM_HERE, base::BindOnce([](TestHost* self, const gfx::Size& size) {
//             self->m_displayPrivate->Resize(size);
//             self->m_displayPrivate->SetDisplayVisible(true);
//         }, base::Unretained(this), gfx::Size(g_wndSize.cx, g_wndSize.cy)));
//
//         scoped_refptr<viz::ContextProvider> context_provider;
//         scoped_refptr<cc::RasterContextProviderWrapper> worker_context_provider_wrapper;
//
//         // Create LayerTreeFrameSink with the browser end of CompositorFrameSink.
//         cc::mojo_embedder::AsyncLayerTreeFrameSink::InitParams params;
//         params.compositor_task_runner = base::ThreadTaskRunnerHandle::Get();
//         //params.gpu_memory_buffer_manager;
//         params.pipes.compositor_frame_sink_associated_remote = std::move(sink_remote);
//         params.pipes.client_receiver = std::move(client_receiver);
//         m_frameSink = std::make_unique<cc::mojo_embedder::AsyncLayerTreeFrameSink>(
//             std::move(context_provider),
//             std::move(worker_context_provider_wrapper), &params);
//     }
//
//     viz::HostFrameSinkManager* host_frame_sink_manager()
//     {
//         return &m_hostFrameSinkManager;
//     }
//
//     void OnFirstSurfaceActivation(const viz::SurfaceInfo& surface_info) override
//     {
//     }
//
//     void OnFrameTokenChanged(uint32_t frame_token, base::TimeTicks activation_time) override
//     {
//     }
// };

void readFile(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        //         std::vector<WCHAR> filenameBuffer;
        //         filenameBuffer.resize(MAX_PATH + 3);
        //         ::GetModuleFileNameW(NULL, filenameBuffer.data(), MAX_PATH);
        //         ::PathRemoveFileSpecW(filenameBuffer.data());
        //
        //         ::PathAppendW(filenameBuffer.data(), L"mtmb.exp");
        //         if (::PathFileExistsW(filenameBuffer.data())) {
        // #ifdef _DEBUG
        //             DebugBreak();
        // #endif
        //         }
        DebugBreak();
        return;
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
    if (0 == bufferSize)
        return;

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

static bool hookUrl(void* job, const char* url, const char* hookedUrl, const wchar_t* localFile, const char* mime, const char* contentType)
{
    if (0 == strstr(url, hookedUrl))
        return false;

    std::vector<char> buffer;
    readFile(localFile, &buffer);
    if (0 == buffer.size())
        return false;

    mbNetSetData(job, &buffer[0], buffer.size());
    mbNetSetMIMEType(job, mime);
    mbNetSetHTTPHeaderFieldUtf8(job, "Content-Type", contentType, TRUE);

    OutputDebugStringA("hookUrl:");
    OutputDebugStringA(url);
    OutputDebugStringA("\n");

    return true;
}

static BOOL MB_CALL_TYPE handleLoadUrlBegin(mbWebView webView, void* param, const char* url, void* job)
{
    //     std::string urlStrDebug("handleLoadUrlBegin:");
    //     urlStrDebug += url;
    //     urlStrDebug += "\n";
    //     OutputDebugStringA(urlStrDebug.c_str());

    //     if (hookUrl(job, url, "main.120724.js", L"G:\\test\\web_test\\51iwifi\\main.120724.js", "text/html"))
    //         return true;

    //     if (hookUrl(job, url, "passport.weibo.com/js/visitor/mini_original.js", L"G:\\test\\web_test\\aola\\mini_original.js", "text/javascript"))
    //         return true;

    //     if (hookUrl(job, url, "act/webcc/link-pk-game/v1.9.1/index.js", L"D:\\test\\web\\cc_163\\webcc_191_index.js", "text/javascript"))
    //         return true;
    //
    //     if (hookUrl(job, url, "act/webcc/performance-reporter/v1.2.0/index.js", L"D:\\test\\web\\cc_163\\performance-reporter.js", "text/javascript"))
    //         return true;
    //
    //     if (hookUrl(job, url, "vendors.7000f260.js", L"G:\\test\\web_test\\51iwifi\\vendors.7000f260.js", "text/javascript"))
    //         return true;
    //
    //     if (hookUrl(job, url, "mini_original.js", L"G:\\test\\web_test\\51iwifi\\mini_original.js", "text/javascript"))
    //         return true;
    if (hookUrl(job, url, "gtm.js?id=GTM-WXXJ8PZ", L"G:\\test\\web_test\\51iwifi\\gtm_id=GTM-WXXJ8PZ.js", "text/javascript", "application/javascript"))
        return true;

    std::string urlStr = url;
    if (urlStr.find("a7fe1df1") != std::string::npos)
        OutputDebugStringA("");

    //     if (strstr(url, "daxiansheng/images/header.png")) {
    //         //mbNetSetData(job, " ", 1);
    //         OutputDebugStringA("trackMi.tml!!!!!!!!!!!!!!!!!!\n");
    //         return false;
    //     }

    //     std::vector<char> buffer;
    //     readFile(L"E:\\test_code\\bemo\\res\\1.asar", &buffer);
    //
    //     static void* s_packetMgr = nullptr;
    //     if (!s_packetMgr)
    //         s_packetMgr = wkeCreateResPacketMgr(buffer.data(), buffer.size());
    //
    //     wkeOnUrlBeginResPacketMgr(s_packetMgr, url, job);

    //     if (hookUrl(job, url, "wangeditor@3.1.1/release/wangEditor.min.js", L"G:\\test\\web_test\\wangeditor\\wangeditor.js", "text/javascript"))
    //         return true;

    //      if (0 != strstr(url, "ecpm.tanx.com/ex?i=mm_"))
    //      {
    //          mbNetHookRequest(job);
    //      }
    //      if (0 != strstr(url, "mguser.api.max.mgtv.com/user/getArtistsByMediaId")) {
    //          mbNetHookRequest(job);
    //      }

    //     if (0 != strstr(url, "video.webm")) {
    //         mbNetChangeRequestUrl(job, "file:///G:/test/web_test/icoc/index-4.mp4");
    //     }

    return false;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    mbInit(nullptr);

    mbWebView mbView = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);

    ::mbOnLoadUrlBegin(mbView, handleLoadUrlBegin, nullptr);

    const char* url = "https://geek-docs.com/html/html-ask-answer/810_html_this_document_requires_trustedscripturl_assignment.html";
    "https://gitee.com/weolar_admin/mininodejs20/pulls/9/files";
    "file:///G:/test/web_test/51iwifi/insertbefore.html";
    "https://www.net-usb.com/cn/usb-over-wi-fi/wireless-usb-connection/";
    "https://source.chromium.org/search?q=SupportedPrefixesStruct&sq=";
    "https://finance.sina.com.cn/stock/usstock/c/2023-12-08/doc-imzxiprr0450628.shtml";
    "https://servo.org/blog/2023/10/26/css-filters-testing-tauri/";
    "https://www.aardio.com/";
    "http://192.168.10.2:8091/aardio.htm";
    "view-source:https://www.baidu.com";
    u8"view-source:/home/euweb/桌面/mini_electron/linux/main4.htm";
    "https://www.qidian.com/chapter/1038152211/768723838/";
    "https://www.qidian.com/";
    "https://www.baidu.com/";
    "file:///G:/test/sln_test/QueueByMiniBlink/dist/test_vite.htm";
    "file:///G:/test/web_test/51iwifi/1.htm";
    "file:///G:/test/web_test/58/svgimage.htm"; // 测试LoaderFactoryForFrame::LoaderFactoryForFrame里的svgimage产生的崩溃

    ::mbLoadURL(mbView, url);
    ::mbShowWindow(mbView, TRUE);

    //::mbWebView mbView2 = mbCreateWebWindow(MB_WINDOW_TYPE_POPUP, NULL, 100, 50, 600, 700);
    //::mbLoadURL(mbView2, "https://www.baidu.com/");
    //::mbShowWindow(mbView2, TRUE);

    mbRunMessageLoop();
    return 0;
}

int WINAPI wWinMain2(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = ieWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszClassName = kClassName;

    RegisterClassEx(&wcex);

    g_hRootWnd = (HWND)5907800;
    ::SetWindowLong(g_hRootWnd, GWL_EXSTYLE, 0);

    if (!IsWindow(g_hRootWnd)) {
        g_hRootWnd = CreateWindowW(kClassName, L"Miniblink108 Sample",
            /*WS_CHILD |*/ WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, //WS_OVERLAPPEDWINDOW,
            0, 0, g_wndSize.cx, g_wndSize.cy, (HWND) nullptr, nullptr, hInstance, nullptr);
    }

    if (g_hRootWnd == nullptr)
        return 0;

    ::ShowWindow(g_hRootWnd, nCmdShow);
    ::UpdateWindow(g_hRootWnd);

    base::AtExitManager atExitManager;
    base::win::ScopedCOMInitializer comInitializer;

    base::CommandLine::Init(0, nullptr);

    content::RenderThreadImpl::get()->initializeWebKit();

    //createTestView();

    {
        base::SingleThreadTaskExecutor mainThreadTaskExecutor(base::MessagePumpType::UI);
        base::PlatformThread::SetName("Mb108UiThread");
        base::RunLoop runLoop;
        runLoop.Run();
    }

    //     MSG msg = {};
    //     while (GetMessage(&msg, nullptr, 0, 0)) {
    //
    //         if (!TranslateAccelerator(msg.hwnd, 0, &msg)) {
    //             TranslateMessage(&msg);
    //             DispatchMessage(&msg);
    //         }
    //     }

    return 0;
}