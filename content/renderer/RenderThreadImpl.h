
#ifndef content_renderer_RenderThreadImpl_h
#define content_renderer_RenderThreadImpl_h

#include "base/threading/thread.h"
#include "third_party/blink/public/platform/scheduler/web_thread_scheduler.h"
#include "ui/gfx/native_widget_types.h"
#include "base/task/single_thread_task_executor.h"

namespace blink {
class WebNavigationControl;
class AssociatedInterfaceProvider;
}

namespace content {

class TestHost;
class RendererBlinkPlatformImpl;
class RenderWidgetHostImpl;

class VizService;
class VizHost;

class EmptyAssociatedInterfaceProvider;

class RenderThreadImpl {
public:
    class ThreadDelegate : public base::Thread::Delegate {
    public:
        ThreadDelegate(RenderThreadImpl* parent);
        scoped_refptr<base::SingleThreadTaskRunner> GetDefaultTaskRunner() override;
        void BindToCurrentThread() override;

        RenderThreadImpl* m_parent;
    };

    RenderThreadImpl();

    static RenderThreadImpl* get();

    void initializeWebKit(/*mojo::BinderMap* binders*/)
    {
        //         m_thread.task_runner()->PostTask(
        //             FROM_HERE, base::BindOnce(&RenderThreadImpl::initializeWebKitOnThread, base::Unretained(this)));

        //         m_thread.task_runner()->PostTask(
        //             FROM_HERE, base::BindOnce(&RenderThreadImpl::createTestView, base::Unretained(this)));
    }

    void initializeWebKitOnThread(/*mojo::BinderMap* binders*/);
    void initializeCompositorThread();
    void initializeDemo();
    void OverrideEmptyAssociatedInterfaceProvider();

    void onRendererBackgrounded();
    void onRendererForegrounded();
    void garbageCollectionDelay(size_t millisecond);

    bool isCurrentThread() const;
    base::PlatformThreadId GetBlinkThreadId() const;

    float getZoom() const
    {
        return m_zoom;
    }
    void setZoom(float f)
    {
        m_zoom = f;
    }

    scoped_refptr<base::SingleThreadTaskRunner> getTaskRunner() const
    {
        return m_thread.task_runner();
    }

    scoped_refptr<base::SingleThreadTaskRunner> getCompositorTaskRunner() const
    {
        return m_compositorTaskRunner;
    }

    void OverrideAssociatedInterfaceProvider(blink::AssociatedInterfaceProvider* associatedInterfaceProvider);

    void createTestView();
    void loadTestUrl(const char* urlStr, blink::WebNavigationControl* navigationControl);

    RendererBlinkPlatformImpl* m_blinkPlatformImpl;
    std::unique_ptr<blink::scheduler::WebThreadScheduler> m_mainThreadScheduler;

    scoped_refptr<base::SingleThreadTaskRunner> m_compositorTaskRunner;

    gfx::AcceleratedWidget m_widget;
    std::unique_ptr<VizService> m_service;
    std::unique_ptr<VizHost> m_host;
    // std::unique_ptr<TestHost> m_testHost;

    RenderWidgetHostImpl* m_renderWidgetHostImpl = nullptr;
    blink::scheduler::WebAgentGroupScheduler* m_agentGroupScheduler = nullptr;

    bool m_inited = false;
    base::Thread m_thread;
    base::Thread m_hostThread;

    float m_zoom = 1.0;

    std::unique_ptr<base::SingleThreadTaskExecutor> m_uiThreadTask;

    EmptyAssociatedInterfaceProvider* m_emptyAssociatedInterfaceProvider = nullptr;

    static RenderThreadImpl* s_inst;
};

}

#endif // content_renderer_RenderThreadImpl_h