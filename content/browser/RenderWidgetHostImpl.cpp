
#include "content/browser/RenderWidgetHostImpl.h"
#include "content/renderer/PlatformEventHandler.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/viz/VizHost.h"
#include "content/browser/MbWebview.h"
#include "content/common/ThreadCall.h"
#include "content/common/LiveIdDetect.h"
#if defined(OS_WIN)
#include "content/ui/ToolTip.h"
#include "base/strings/utf_string_conversions.h"
#endif
#include "third_party/blink/public/web/web_frame_widget.h"
#include "ui/display/screen.h"
#if !defined(OS_WIN)
#include "ui/display/screen_fake.h"
#endif

extern "C" MojoResult MojoMakeIsMessageChannelFlag(MojoHandle handle);

namespace content {

void RenderFrameMetadataObserverClientImpl::OnRenderFrameMetadataChanged(uint32_t frame_token, const ::cc::RenderFrameMetadata& metadata)
{
    m_parent->allowResize();
    if (m_parent->m_sinkClient)
        m_parent->m_sinkClient->m_firstSetEmbeds = true;

    if (m_parent->m_visualProperties.local_surface_id == metadata.local_surface_id)
        return;

    m_parent->m_visualProperties.local_surface_id = metadata.local_surface_id;

    m_parent->m_runner->PostTask(FROM_HERE,
        base::BindOnce(
            [](base::WeakPtr<RenderWidgetHostImpl> self) {
                if (self->m_blinkWidget.get())
                    self->m_blinkWidget->UpdateVisualProperties(self->m_visualProperties);
            },
            m_parent->m_weakPtr.GetWeakPtr()));
}

void RenderFrameMetadataObserverClientImpl::OnFrameSubmissionForTesting(uint32_t frame_token)
{
    OutputDebugStringA("RenderFrameMetadataObserverClient::OnFrameSubmissionForTesting impl\n");
}

RenderWidgetHostImpl::RenderWidgetHostImpl(__int64 parentWebviewId, scoped_refptr<base::SequencedTaskRunner> runner)
    : m_parentWebviewId(parentWebviewId)
    , m_runner(runner)
{
    uint64_t rand = base::RandUint64();
    viz::FrameSinkId frameSinkId(rand >> 32, rand & 0xffffffff);
    m_frameSinkId = frameSinkId;

    char output[100] = { 0 };
    sprintf(output, "RenderWidgetHostImpl: %p\n", this);
    OutputDebugStringA(output);
}

void RenderWidgetHostImpl::destroy()
{
    if (m_webWiew)
        m_webWiew->Close(); // 这里面AsyncLayerTreeFrameSink同步销毁
    m_webWiew = nullptr;

    if (getHostFrameSinkManager()) {
        viz::FrameSinkId rootFrameSinkId(0xdead, 0xbeef);
        getHostFrameSinkManager()->InvalidateFrameSinkId(rootFrameSinkId, m_sinkHost);
        if (isSinkReady())
            getHostFrameSinkManager()->InvalidateFrameSinkId(m_frameSinkId, this);
    }
}

RenderWidgetHostImpl::~RenderWidgetHostImpl()
{
    if (m_toolTip)
        delete m_toolTip;

    char output[100] = { 0 };
    sprintf(output, "~RenderWidgetHostImpl: %p\n", this);
    OutputDebugStringA(output);
}

bool RenderWidgetHostImpl::isSinkReady() const
{
    return !!m_sinkClient;
}

void RenderWidgetHostImpl::allowResize()
{
    m_allowResize = true;
}

void RenderWidgetHostImpl::resizeOnBlinkThread(int w, int h)
{
    if (!m_sinkClient)
        return;

    disallowResize();
    gfx::Rect viewportRect(0, 0, w, h);
    m_visualProperties.new_size = viewportRect.size();
    m_visualProperties.visible_viewport_size = viewportRect.size();
    m_visualProperties.compositor_viewport_pixel_rect = viewportRect;

    viz::LocalSurfaceId newLocalSurfaceId;
    gfx::Rect bounds = m_visualProperties.compositor_viewport_pixel_rect;

    m_allocator.GenerateId();
    newLocalSurfaceId = m_allocator.GetCurrentLocalSurfaceId();
    newLocalSurfaceId = m_sinkClient->embedOnBlinkThread(m_frameSinkId, bounds, newLocalSurfaceId);
    // 这是每一帧embedSurfaceDrawquad的surfaceid，另外还有个root的surfaceid作为SubmitCompositorFrame的参数
    m_visualProperties.local_surface_id = newLocalSurfaceId;

    time_t now;
    struct tm* current;
    now = time(NULL);
    current = localtime(&now);

    char* output = (char*)malloc(400);
    sprintf(output, "RenderWidgetHostImpl::resizeOnBlinkThread: hash:%d w:%d, (%02d:%02d)\n", 
        newLocalSurfaceId.hash(), w, current->tm_min, current->tm_sec);
    OutputDebugStringA(output);
    free(output);

    if (m_blinkWidget.get())
        m_blinkWidget->UpdateVisualProperties(m_visualProperties);

    if (m_webWiew) {
        m_webWiew->MainFrameWidget()->Resize(gfx::Size(w, h));
        gfx::Rect widgetScreenRect(0, 0, w, h);
        m_webWiew->MainFrameWidget()->SetScreenRects(widgetScreenRect, widgetScreenRect);
    }
    m_sinkHost->resizeOnBlinkThread(viewportRect.size());
}

void RenderWidgetHostImpl::bindPopupWidget(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> popupHost,
    ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::WidgetHost> blinkWidgetHost,
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::Widget> blinkWidget)
{
    m_agentGroupScheduler = blink::scheduler::WebThreadScheduler::MainThreadScheduler().CreateWebAgentGroupScheduler();
    m_popupWidgetHost.Bind(std::move(popupHost));
    m_blinkWidgetHostReceiver.Bind(std::move(blinkWidgetHost));
    m_blinkWidget.Bind(std::move(blinkWidget));

    //m_popupWidgetHost.set_disconnect_handler(base::BindOnce(&RenderWidgetHostImpl::onClientConnectionLost, base::Unretained(this)));
    m_blinkWidgetHostReceiver.set_disconnect_handler(base::BindOnce(&RenderWidgetHostImpl::onClientConnectionLost, base::Unretained(this)));
    //m_blinkWidget.set_disconnect_handler(base::BindOnce(&RenderWidgetHostImpl::onClientConnectionLost, base::Unretained(this)));

    initVisualProperties();
}

display::Screen* getScreenOrCreate()
{
    display::Screen* screen = display::Screen::GetScreen();
    if (!screen) {
#if defined(OS_WIN)
        display::win::ScreenWin* screenNew = new display::win::ScreenWin();
#else
        display::ScreenFake* screenNew = new display::ScreenFake();
#endif // OS_WIN
        display::Screen::SetScreenInstance(screenNew, base::Location::Current());
        screen = display::Screen::GetScreen();
    }
    return screen;
}

void RenderWidgetHostImpl::initVisualProperties()
{
    display::Screen* screen = getScreenOrCreate();
    std::vector<display::Display> displays = screen->GetAllDisplays();
    if (displays.size() == 0)
        DebugBreak();
    for (size_t i = 0; i < displays.size(); ++i) {
        const display::Display& dis = displays[i];
        display::ScreenInfo screenInfo;
        display::DisplayUtil::DisplayToScreenInfo(&screenInfo, dis);

        m_visualProperties.screen_infos.screen_infos.push_back(screenInfo);
    }

    gfx::Rect viewportRect(/*displays[0].work_area()*/ 0, 0, 960, 480);
    m_visualProperties.screen_infos.current_display_id = displays[0].id();
    m_visualProperties.display_mode = blink::mojom::DisplayMode::kBrowser;
    m_visualProperties.new_size = viewportRect.size();
    m_visualProperties.visible_viewport_size = viewportRect.size();
    m_visualProperties.compositor_viewport_pixel_rect = viewportRect;

    // 只有调了WasShown才会有
    // ProxyMain::SetVisible
    // -> SchedulerStateMachine::ShouldBeginLayerTreeFrameSinkCreation
    // -> CreateFrameSink
    wasShown();
}

std::unique_ptr<CreateFrameWidgetParams> RenderWidgetHostImpl::bindAndGenerateCreateFrameWidgetParams()
{
    m_agentGroupScheduler = blink::scheduler::WebThreadScheduler::MainThreadScheduler().CreateWebAgentGroupScheduler();

    std::unique_ptr<CreateFrameWidgetParams> params = std::make_unique<CreateFrameWidgetParams>();
    initVisualProperties();
    params->blinkWidget = m_blinkWidget.BindNewEndpointAndPassReceiver();
    params->frameWidget = m_frameWidget.BindNewEndpointAndPassReceiver();
    params->visualProperties = m_visualProperties;

    m_blinkFrameWidgetHostReceiver.Bind(params->frameWidgetHost.InitWithNewEndpointAndPassReceiver());
    m_blinkWidgetHostReceiver.Bind(params->widgetHost.InitWithNewEndpointAndPassReceiver());

    return std::move(params);
}

void RenderWidgetHostImpl::bindLocalSurfaceId()
{
    gfx::Rect bounds = m_visualProperties.compositor_viewport_pixel_rect;
    if (bounds.IsEmpty())
        bounds.set_size(gfx::Size(1, 1));

        // bounds.set_width(bounds.width() / 2  + 600);
        // bounds.set_height(bounds.height() / 2 + 800);

#if 0
    viz::LocalSurfaceId newLocalSurfaceId;
    //m_surfaceIdAllocator.UpdateFromParent(m_sinkClient->GetLocalSurfaceId());
//     m_surfaceIdAllocator.GenerateId();
//     newLocalSurfaceId = m_surfaceIdAllocator.GetCurrentLocalSurfaceId();
#else
    //newLocalSurfaceId = m_sinkClient->embedOnBlinkThread(m_frameSinkId, bounds);
    m_allocator.GenerateId();
    m_localSurfaceId = m_allocator.GetCurrentLocalSurfaceId();
#endif
    //m_visualProperties.local_surface_id = m_sinkClient->GetLocalSurfaceId(); // root client的surface
    m_visualProperties.local_surface_id = m_localSurfaceId;

    m_blinkWidget->UpdateVisualProperties(m_visualProperties);

    m_sinkClient->embedOnBlinkThread(m_frameSinkId, bounds, m_localSurfaceId);
}

void RenderWidgetHostImpl::CreateFrameSink(
    ::mojo::PendingReceiver<::viz::mojom::blink::CompositorFrameSink> receiver, ::mojo::PendingRemote<::viz::mojom::blink::CompositorFrameSinkClient> client)
{
#if 1
    while (/*!m_sinkClient ||*/ !m_sinkHost || !m_sinkHost->getRootClient()) {
        base::PlatformThread::Sleep(base::Milliseconds(10));
    }
    m_sinkClient = m_sinkHost->getRootClient();
    m_sinkClient->setWebviewId(m_mbWebView->getId());
#endif

    getHostFrameSinkManager()->RegisterFrameSinkId(m_frameSinkId, this, viz::ReportFirstSurfaceActivation::kNo);
    getHostFrameSinkManager()->RegisterFrameSinkHierarchy(m_sinkClient->frameSinkId(), m_frameSinkId);
    //viz::FrameSinkId rootGrameSinkId(0xdead, 0xbeef);
    //getHostFrameSinkManager()->RegisterFrameSinkHierarchy(rootGrameSinkId/*m_sinkClient->frame_sink_id()*/, m_frameSinkId);
    //m_frameSinkId = rootGrameSinkId;

    mojo::ScopedMessagePipeHandle h = receiver.PassPipe();
    //MojoMakeIsMessageChannelFlag(h->value());

    getHostFrameSinkManager()->CreateCompositorFrameSink(m_frameSinkId,
        mojo::PendingReceiver<viz::mojom::CompositorFrameSink>(std::move(h) /*receiver.PassPipe()*/),
        mojo::PendingRemote<viz::mojom::CompositorFrameSinkClient>(client.PassPipe(), 0));

    bindLocalSurfaceId();
    //     gfx::Rect bounds = m_visualProperties.compositor_viewport_pixel_rect;
    //     if (bounds.IsEmpty())
    //         bounds.set_size(gfx::Size(1, 1));
    //     m_sinkClient->embedOnBlinkThread(m_frameSinkId, bounds, m_localSurfaceId);

    mojo::PendingReceiver<blink::mojom::blink::RenderInputRouterClient> vizReceiver = mojo::NullReceiver();
    mojo::PendingRemote<blink::mojom::blink::RenderInputRouterClient> browserRemotePending;
    m_blinkWidget->SetupRenderInputRouterConnections(browserRemotePending.InitWithNewPipeAndPassReceiver(), std::move(vizReceiver));
    m_browserRemote.Bind(std::move(browserRemotePending));

    m_browserRemote->GetWidgetInputHandler(
        m_platformEventHandler->m_blinkWidgetInputHandler.BindNewPipeAndPassReceiver(base::SequencedTaskRunner::GetCurrentDefault()),
        m_platformEventHandler->m_hostReceiver.BindNewPipeAndPassRemote(base::SequencedTaskRunner::GetCurrentDefault()));

    if (m_webWiew) {
        m_webWiew->MainFrameWidget()->SetFocus(true);
        m_webWiew->SetIsActive(true);
    }
}

void RenderWidgetHostImpl::SetCursor(const ::ui::Cursor& cursor)
{
    m_mbWebView->setCursor(cursor);
}

void RenderWidgetHostImpl::TextInputStateChanged(::ui::mojom::blink::TextInputStatePtr state)
{
    if (!m_mbWebView->getWebView())
        return;
    blink::WebLocalFrame* focusedFrame = m_mbWebView->getWebView()->FocusedFrame();
    if (!focusedFrame)
        return;
    gfx::Rect rect;
    focusedFrame->FirstRectForCharacterRange(0, state->selection.end(), rect);

    gfx::Point p = rect.origin();
    p.Offset(rect.width(), 0);

    m_mbWebView->setCaretPos(p);
}

void RenderWidgetHostImpl::onClientConnectionLost()
{
    MbWebView* webview = m_mbWebView;
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webview] {
        webview->preDestroyOnUiThread();

        ::PostMessageW(webview->getHostWnd(), WM_CLOSE, 0, 0);
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [webview] { webview->preDestroyOnBlinkThread(); });
    });
}

void RenderWidgetHostImpl::RequestClosePopup()
{
    DCHECK(kHasPopup == m_popupState);
    if (kRequestClosePopup == m_popupState)
        return;
    m_popupState = kRequestClosePopup;

    m_popupWidgetHost.Unbind();

    MbWebView* webview = m_mbWebView;
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webview] { webview->setShow(SW_HIDE /*false, false*/); });
}

void RenderWidgetHostImpl::ShowPopup(const ::gfx::Rect& initialRect, const ::gfx::Rect& anchor_rect, ShowPopupCallback callback)
{
    DCHECK(kNoPopup == m_popupState);
    if (m_popupState != kNoPopup)
        return;
    m_popupState = kHasPopup;

    mbWebView parentWebviewId = m_parentWebviewId;
    int64_t id = m_mbWebView->getId();
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [parentWebviewId, id, initialRect] {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
        MbWebView* parentWebview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(parentWebviewId);
        if (!webview || !parentWebview)
            return;

        POINT point = { 0 };
        ::ClientToScreen(parentWebview->getHostWnd(), &point);
        webview->createWebWindowImplInUiThread(nullptr, WS_POPUP | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, /*WS_EX_NOACTIVATE*/ 0x08000000L,
            initialRect.x() + point.x, initialRect.y() + point.y, initialRect.width(), initialRect.height());
        webview->setShow(SW_SHOWNOACTIVATE /*true, false*/);
    });

    RenderThreadImpl::get()->getTaskRunner()->PostNonNestableTask(
        MB_FROM_HERE, base::BindOnce([](ShowPopupCallback&& callback) { std::move(callback).Run(); }, std::move(callback)));
}

void RenderWidgetHostImpl::SetPopupBounds(const ::gfx::Rect& bounds, SetPopupBoundsCallback callback)
{
    RenderThreadImpl::get()->getTaskRunner()->PostNonNestableTask(
        MB_FROM_HERE, base::BindOnce([](SetPopupBoundsCallback&& callback) { std::move(callback).Run(); }, std::move(callback)));
}

void RenderWidgetHostImpl::RegisterRenderFrameMetadataObserver(::mojo::PendingReceiver<::cc::mojom::blink::RenderFrameMetadataObserverClient> receiver,
    ::mojo::PendingRemote<::cc::mojom::blink::RenderFrameMetadataObserver> render_frame_metadata_observer)
{
    m_renderFrameMetadataObserverClient = new RenderFrameMetadataObserverClientImpl(this);
    m_renderFrameMetadataObserverClient->m_receiver.Bind(std::move(receiver));

    m_renderFrameMetadataObserverClient->m_receiver.set_disconnect_handler(
        base::BindOnce([](RenderFrameMetadataObserverClientImpl* ptr) { delete ptr; }, base::Unretained(m_renderFrameMetadataObserverClient)));
}

void RenderWidgetHostImpl::UpdateTooltipUnderCursor(const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint)
{
#if defined(OS_WIN)
    if (!m_toolTip)
        m_toolTip = new ToolTip(true, 0.02);

    std::string txt = tooltip_text.Utf8();
    std::u16string u16txt = base::UTF8ToUTF16(txt);
    m_toolTip->show((const WCHAR*)u16txt.c_str(), nullptr);
#endif
}

}