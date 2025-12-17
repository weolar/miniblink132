
#ifndef content_browser_RenderWidgetHostImpl_h
#define content_browser_RenderWidgetHostImpl_h

#include "content/viz/VizClient.h"
#include "content/common/common.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/mojom/frame/intrinsic_sizing_info.mojom-blink.h"
#include "third_party/blink/public/mojom/page/widget.mojom-blink.h"
#include "third_party/blink/public/mojom/widget/platform_widget.mojom-blink.h"
#include "third_party/blink/public/mojom/widget/record_content_to_visible_time_request.mojom-blink.h"
#include "third_party/blink/public/mojom/input/touch_event.mojom-blink.h"
#include "third_party/blink/public/mojom/input/input_handler.mojom.h"
#include "third_party/blink/public/mojom/input/input_handler.mojom-blink.h"
#include "ui/base/ime/mojom/text_input_state.mojom-blink.h"
#include "cc/mojom/render_frame_metadata.mojom-blink.h"
#include "third_party/blink/public/common/widget/visual_properties.h"
#include "third_party/blink/public/platform/scheduler/web_thread_scheduler.h"
#include "third_party/blink/public/mojom/widget/platform_widget.mojom-blink.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"
#include "mojo/public/cpp/bindings/associated_remote.h"
#include "components/viz/host/host_frame_sink_manager.h"
#include "components/viz/host/host_frame_sink_client.h"
#include "services/viz/public/mojom/compositing/compositor_frame_sink.mojom.h"
#include "services/viz/public/mojom/compositing/compositor_frame_sink.mojom-blink.h"
#include "components/viz/common/surfaces/child_local_surface_id_allocator.h"

#if defined(OS_WIN)
#include "ui/display/win/screen_win.h"
#endif
#include "ui/display/screen_info.h"
#include "ui/display/display_util.h"
#include "base/rand_util.h"
#include "base/task/sequenced_task_runner.h"

namespace blink {
class WebFrameWidget;
}

namespace content {

class VizClient;
class VizHost;
class RenderWidgetHostImpl;
class PlatformEventHandler;
class MbWebView;
class ToolTip;

class RenderFrameMetadataObserverClientImpl : public ::cc::mojom::blink::RenderFrameMetadataObserverClient {
public:
    RenderFrameMetadataObserverClientImpl(RenderWidgetHostImpl* parent)
    {
        m_parent = parent;
    }
    virtual void OnRenderFrameMetadataChanged(uint32_t frame_token, const ::cc::RenderFrameMetadata& metadata) override;

    virtual void OnFrameSubmissionForTesting(uint32_t frame_token) override;

    RenderWidgetHostImpl* m_parent = nullptr;

    ::mojo::Receiver<::cc::mojom::blink::RenderFrameMetadataObserverClient> m_receiver { this };
};

class CreateFrameWidgetParams {
public:
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::FrameWidgetHost> frameWidgetHost;
    ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::FrameWidget> frameWidget;
    ::mojo::PendingAssociatedRemote<::blink::mojom::blink::WidgetHost> widgetHost;
    ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::Widget> blinkWidget;
    ::blink::VisualProperties visualProperties;
};

class RenderWidgetHostImpl : public blink::mojom::blink::FrameWidgetHost,
                             public blink::mojom::blink::PopupWidgetHost,
                             public blink::mojom::blink::WidgetHost,
                             public viz::HostFrameSinkClient {
public:
    RenderWidgetHostImpl(__int64 parentWebviewId, scoped_refptr<base::SequencedTaskRunner> runner);
    ~RenderWidgetHostImpl();

    std::unique_ptr<CreateFrameWidgetParams> bindAndGenerateCreateFrameWidgetParams();
    void bindPopupWidget(::mojo::PendingAssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> popupHost,
        ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::WidgetHost> blinkWidgetHost,
        ::mojo::PendingAssociatedRemote<::blink::mojom::blink::Widget> blinkWidget);
    void resizeOnBlinkThread(int w, int h);

    bool isSinkReady() const;

    void destroy();

    void wasShown()
    {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
            FROM_HERE, base::BindOnce([](base::WeakPtr<RenderWidgetHostImpl> self) { self->wasShownImpl(); }, m_weakPtr.GetWeakPtr()));
    }

    void wasShownImpl()
    {
        if (!m_blinkWidget.get()) {
            wasShown();
            return;
        }
        m_blinkWidget->WasShown(false /*was_evicted*/, ::blink::mojom::blink::RecordContentToVisibleTimeRequestPtr());
    }

    void setHostFrameSinkManager(viz::HostFrameSinkManager* hostFrameSinkManager)
    {
        CHECK(!m_hostFrameSinkManager);
        m_hostFrameSinkManager = hostFrameSinkManager;
    }

    viz::HostFrameSinkManager* getHostFrameSinkManager()
    {
        CHECK(m_hostFrameSinkManager);
        return m_hostFrameSinkManager;
    }

    void setSinkHost(VizHost* host)
    {
        m_sinkHost = host;
    }

    void bindLocalSurfaceId();

    // FrameWidgetHost:
    virtual void AnimateDoubleTapZoomInMainFrame(const ::gfx::Point& tap_point, const ::gfx::Rect& rect_to_zoom) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::AnimateDoubleTapZoomInMainFrame not impl \n");
    }

    virtual void ZoomToFindInPageRectInMainFrame(const ::gfx::Rect& rect_to_zoom) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::ZoomToFindInPageRectInMainFrame not impl \n");
    }

    virtual void SetHasTouchEventConsumers(::blink::mojom::blink::TouchEventConsumersPtr touch_event_consumers) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::SetHasTouchEventConsumers not impl \n");
    }

    virtual void IntrinsicSizingInfoChanged(::blink::mojom::blink::IntrinsicSizingInfoPtr sizing_info) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::IntrinsicSizingInfoChanged not impl \n");
    }

    virtual void AutoscrollStart(const ::gfx::PointF& position) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::AutoscrollStart not impl \n");
    }

    virtual void AutoscrollFling(const ::gfx::Vector2dF& velocity) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::AutoscrollFling not impl \n");
    }

    virtual void AutoscrollEnd() override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::AutoscrollEnd not impl \n");
    }

    /*virtual*/ void StartDragging(const ::blink::WebDragData& drag_data, ::blink::DragOperationsMask operations_allowed, const ::SkBitmap& image,
        const ::gfx::Vector2d& cursor_offset_in_dip, const ::gfx::Rect& drag_obj_rect_in_dip, ::blink::mojom::blink::DragEventSourceInfoPtr event_info) /*override*/
    {
        //OutputDebugStringA("RenderWidgetHostImpl::StartDragging not impl \n");
    }
    // FrameWidgetHost end

    // PopupWidgetHost:
    virtual void RequestClosePopup() override;
    virtual void ShowPopup(const ::gfx::Rect& initial_rect, const ::gfx::Rect& anchor_rect, ShowPopupCallback callback) override;
    virtual void SetPopupBounds(const ::gfx::Rect& bounds, SetPopupBoundsCallback callback) override;

    // WidgetHost
    virtual void CreateFrameSink(::mojo::PendingReceiver<::viz::mojom::blink::CompositorFrameSink> receiver,
        ::mojo::PendingRemote<::viz::mojom::blink::CompositorFrameSinkClient> client) override;

    virtual void SetCursor(const ::ui::Cursor& cursor) override;

    virtual void UpdateTooltipUnderCursor(const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint) override;

    virtual void UpdateTooltipFromKeyboard(
        const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint, const ::gfx::Rect& bounds) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::UpdateTooltipFromKeyboard not impl \n");
    }

    virtual void ClearKeyboardTriggeredTooltip() override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::ClearKeyboardTriggeredTooltip not impl \n");
    }

    virtual void TextInputStateChanged(::ui::mojom::blink::TextInputStatePtr state) override;

    virtual void SelectionBoundsChanged(const ::gfx::Rect& anchor_rect, ::base::i18n::TextDirection anchor_dir, const ::gfx::Rect& focus_rect,
        ::base::i18n::TextDirection focus_dir, const ::gfx::Rect& bounding_box_rect, bool is_anchor_first) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::SelectionBoundsChanged not impl \n");
    }

    virtual void RegisterRenderFrameMetadataObserver(::mojo::PendingReceiver<::cc::mojom::blink::RenderFrameMetadataObserverClient> receiver,
        ::mojo::PendingRemote<::cc::mojom::blink::RenderFrameMetadataObserver> render_frame_metadata_observer) override;

    // HostFrameSinkClient
    virtual void OnFirstSurfaceActivation(const viz::SurfaceInfo& surface_info) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::OnFirstSurfaceActivation not impl \n");
    }

    virtual void OnFrameTokenChanged(uint32_t frame_token, base::TimeTicks activation_time) override
    {
        //OutputDebugStringA("RenderWidgetHostImpl::OnFrameTokenChanged not impl \n");
    }

    bool isAllowResize() const
    {
        return m_allowResize;
    }
    void allowResize();
    void disallowResize()
    {
        m_allowResize = false;
    }

    void initVisualProperties();
    void onClientConnectionLost();

    viz::LocalSurfaceId m_localSurfaceId;
    viz::ParentLocalSurfaceIdAllocator m_allocator;

    ::blink::WebLocalFrame* m_mainFrame = nullptr;
    ::blink::WebView* m_webWiew = nullptr;

    mojo::AssociatedReceiver<::blink::mojom::blink::FrameWidgetHost> m_blinkFrameWidgetHostReceiver { this };
    mojo::AssociatedReceiver<::blink::mojom::blink::WidgetHost> m_blinkWidgetHostReceiver { this };

    mojo::AssociatedRemote<::blink::mojom::blink::Widget> m_blinkWidget;
    mojo::AssociatedRemote<::blink::mojom::blink::FrameWidget> m_frameWidget;
    mojo::AssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> m_popupWidgetHost { this };

    //mojo::Receiver<viz::mojom::CompositorFrameSinkClient> m_compositorFrameSinkClientReceiver{ this };
    //mojo::AssociatedRemote<viz::mojom::CompositorFrameSink> m_associatedCompositorFrameSink;

    std::unique_ptr<blink::scheduler::WebAgentGroupScheduler> m_agentGroupScheduler;

    viz::HostFrameSinkManager* m_hostFrameSinkManager = nullptr;

    PlatformEventHandler* m_platformEventHandler = nullptr;

    viz::FrameSinkId m_frameSinkId;

    ::blink::VisualProperties m_visualProperties;

    MbWebView* m_mbWebView = nullptr;

    blink::WebFrameWidget* m_webFrameWidget = nullptr;

    friend class RenderFrameMetadataObserverClientImpl;
    RenderFrameMetadataObserverClientImpl* m_renderFrameMetadataObserverClient = nullptr;

    __int64 m_parentWebviewId = 0;
    bool m_allowResize = true;

    enum PopupState { kNoPopup = 0, kHasPopup, kRequestClosePopup };
    PopupState m_popupState = kNoPopup;

    mojo::Remote<blink::mojom::blink::RenderInputRouterClient> m_browserRemote;

    viz::ParentLocalSurfaceIdAllocator m_surfaceIdAllocator;
    //viz::ChildLocalSurfaceIdAllocator m_surfaceIdAllocator;

    VizClient* m_sinkClient = nullptr;
    VizHost* m_sinkHost = nullptr;

    ToolTip* m_toolTip = nullptr;

    scoped_refptr<base::SequencedTaskRunner> m_runner;
    base::WeakPtrFactory<RenderWidgetHostImpl> m_weakPtr { this };
};

}

#endif // content_browser_RenderWidgetHostImpl_h