// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/viz/VizClient.h"

#include <memory>
#include <utility>
#include <vector>

#include "components/viz/common/quads/compositor_frame.h"
#include "components/viz/common/quads/solid_color_draw_quad.h"
#include "components/viz/common/quads/surface_draw_quad.h"
#include "components/viz/service/frame_sinks/compositor_frame_sink_support.h"
#include "content/browser/RenderWidgetHostImpl.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/common/ThreadCall.h"
#include "content/common/LiveIdDetect.h"

namespace content {

static base::Thread* s_vizClientThread = nullptr;

VizClient::VizClient(const viz::FrameSinkId& frameSinkId, const viz::LocalSurfaceId& localSurfaceId, const gfx::Rect& bounds,
    scoped_refptr<base::SingleThreadTaskRunner> servicRrunner)
    //: m_thread(frameSinkId.ToString()) // 用m_vizCompositorRunner线程了
    : m_frameSinkId(frameSinkId)
    , m_hostLocalSurfaceId(localSurfaceId)
    , m_bounds(bounds)
    , m_vizCompositorRunner(servicRrunner)
{
    if (!s_vizClientThread) {
        s_vizClientThread = new base::Thread("VizClient");
        CHECK(s_vizClientThread->Start());
    }

    m_id = common::LiveIdDetect::get()->constructed(this);

    //*(int*)1 = 1; //SetServer\OnServerDestroy not impl!
}

VizClient::~VizClient()
{
    common::LiveIdDetect::get()->deconstructed(m_id);
}

void VizClient::destroy(std::function<void(void)>&& callback)
{
    CHECK(!m_sink.is_bound());
    m_canCommitFrame = false;

    viz::CompositorFrameSinkSupport* sink = (viz::CompositorFrameSinkSupport*)m_vizServer;
    m_vizServer = nullptr;
    if (sink)
        sink->OnClientDestroy();

    s_vizClientThread->task_runner()->PostTask(FROM_HERE,
        base::BindOnce(
            [](VizClient* self, std::function<void(void)>&& callback) {
                //         int waitCount = 0;
                //
                //         self->m_receiver.set_disconnect_handler(base::BindOnce([](int* waitCount) {
                //             *waitCount = 1; // 发送端也关闭了，就走到这里
                //         }, &waitCount));
                //         self->m_receiver.set_connection_error_handler_is_sync();
                //
                //         while (0 == waitCount) {
                //             base::PlatformThread::Sleep(base::Milliseconds(1));
                //         }
                self->m_receiver.reset();

                self->m_associatedSink.reset();
                self->m_sink.reset();
                //delete self; // TODO

                ThreadCall::delayDestroySelf(self, s_vizClientThread->task_runner(), 2000);

                (callback)();
                OutputDebugStringA("VizClient::destroy\n");
            },
            base::Unretained(this), std::move(callback)));
}

void VizClient::initialize(
    mojo::PendingReceiver<viz::mojom::CompositorFrameSinkClient> receiver, mojo::PendingAssociatedRemote<viz::mojom::CompositorFrameSink> sink_remote)
{
    s_vizClientThread->task_runner()->PostTask(
        FROM_HERE, base::BindOnce(&VizClient::initializeOnThread, base::Unretained(this), std::move(receiver), std::move(sink_remote), mojo::NullRemote()));
}

// void VizClient::initialize(
//     mojo::PendingReceiver<viz::mojom::CompositorFrameSinkClient> receiver, mojo::PendingRemote<viz::mojom::CompositorFrameSink> sink_remote)
// {
//     m_thread.task_runner()->PostTask(FROM_HERE,
//         base::BindOnce(&VizClient::initializeOnThread, base::Unretained(this), std::move(receiver), mojo::NullAssociatedRemote(), std::move(sink_remote)));
// }

viz::LocalSurfaceId VizClient::embedOnBlinkThread(const viz::FrameSinkId& frameSinkId, const gfx::Rect& bounds, const viz::LocalSurfaceId& newLocalSurfaceId)
{
    // |m_embeds| is used on the client-thread in CreateFrame(). So this needs to
    // be mutated under a lock.
    base::AutoLock lock(m_lock);
    //m_allocator.GenerateId();
    //viz::LocalSurfaceId newLocalSurfaceId = m_allocator.GetCurrentLocalSurfaceId();
    m_embeds[frameSinkId] = { newLocalSurfaceId, bounds };
    m_firstSetEmbeds = false; // 下一次的OnBeginFrame暂时不允许绘制真实内容，而是推迟一帧绘制，这样可以让surfaceid设置到viz线程

    //     char* output = (char*)malloc(0x500);
    //     sprintf_s(output, 0x499, "VizClient::Embed: %p (newLocalSurfaceId:%d)(m_hostLocalSurfaceId:%d)(width:%d)(tid:%d)\n",
    //         this,
    //         newLocalSurfaceId.hash(),
    //         m_hostLocalSurfaceId.hash(),
    //         m_bounds.width(),
    //         ::GetCurrentThreadId()
    //     );
    //     OutputDebugStringA(output);
    //     free(output);

    return newLocalSurfaceId;
}

viz::LocalSurfaceId VizClient::GetLocalSurfaceId()
{
    DebugBreak();
    base::AutoLock lock(m_lock);
    return m_hostLocalSurfaceId;
}

viz::LocalSurfaceId VizClient::GenLocalSurfaceId()
{
    DebugBreak();
    base::AutoLock lock(m_lock);
    m_allocator.GenerateId();
    return m_allocator.GetCurrentLocalSurfaceId();
}

bool g_canSetNeedsBeginFrame = true;

void VizClient::resizeOnHostThread(const gfx::Size& size, const viz::LocalSurfaceId& localSurfaceId)
{
    // |m_bounds| and |m_hostLocalSurfaceId| are used on the client-thread in
    // createFrame(). So these need to be mutated under a lock.
    base::AutoLock lock(m_lock);
    m_bounds.set_size(size);
    m_hostLocalSurfaceId = localSurfaceId; // 这个是根surfaceid，作为SubmitCompositorFrame的参数
    //m_forbidResize = true;
    //m_canCommitFrame = false;// 现在改成一直允许
    scoped_refptr<base::SequencedTaskRunner> runner = base::SequencedTaskRunner::GetCurrentDefault();

    // Request for begin-frames.
    m_vizCompositorRunner->PostTask(FROM_HERE,
        base::BindOnce(
            [](scoped_refptr<base::SequencedTaskRunner> runner, int64_t id) {
                VizClient* self = (VizClient*)common::LiveIdDetect::get()->getPtr(id);
                if (!self)
                    return;
                if (!self->getPtr())
                    return;

                if (g_canSetNeedsBeginFrame)
                    self->getPtr()->SetNeedsBeginFrame(true);
                else
                    self->allowResize();

                runner->PostTask(FROM_HERE,
                    base::BindOnce(
                        [](int64_t id) {
                            VizClient* self = (VizClient*)common::LiveIdDetect::get()->getPtr(id);
                            if (!self)
                                return;
                            self->m_canCommitFrame = true;
                        },
                        id));
            },
            std::move(runner), m_id));
}

viz::mojom::CompositorFrameSink* VizClient::getPtrImpl()
{
    if (m_associatedSink.is_bound())
        return m_associatedSink.TryGet();
    if (m_sink.is_bound())
        return m_sink.TryGet();
    return nullptr;
}

viz::mojom::CompositorFrameSink* VizClient::getPtr()
{
    viz::mojom::CompositorFrameSink* ret = getPtrImpl();
    for (int count = 0; !ret; ret = getPtrImpl(), ++count) {
        if (1 == (count % 11)) {
            void* webview = common::LiveIdDetect::getMbWebviewIds()->getPtr(m_webviewId);
            if (!webview)
                return nullptr;
        }
        base::PlatformThread::Sleep(base::Milliseconds(5));
    }
    return ret;
}

void VizClient::initializeOnThread(mojo::PendingReceiver<viz::mojom::CompositorFrameSinkClient> receiver,
    mojo::PendingAssociatedRemote<viz::mojom::CompositorFrameSink> associated_sink_remote, mojo::PendingRemote<viz::mojom::CompositorFrameSink> sink_remote)
{
    m_receiver.Bind(std::move(receiver));

    if (associated_sink_remote)
        m_associatedSink.Bind(std::move(associated_sink_remote));
    else
        m_sink.Bind(std::move(sink_remote));

    // 等resize再调用SetNeedsBeginFrame(true);
}

void VizClient::DidReceiveCompositorFrameAck(std::vector<viz::ReturnedResource> resources)
{
    // See documentation in mojom for how this can be used.
    //     char* output = (char*)malloc(0x500);
    //     sprintf_s(output, 0x499, "VizClient::DidReceiveCompositorFrameAck: %p (%d), tid:%d\n",
    //         this, m_hostLocalSurfaceId.hash(), ::GetCurrentThreadId());
    //     OutputDebugStringA(output);
    //     free(output);

    RenderThreadImpl::get()->getCompositorTaskRunner()->PostTask(FROM_HERE,
        base::BindOnce(
            [](int64_t id) {
                VizClient* self = (VizClient*)common::LiveIdDetect::get()->getPtr(id);
                if (self)
                    self->allowResize();

                //         char* output = (char*)malloc(0x500);
                //         sprintf_s(output, 0x499, "VizClient::DidReceiveCompositorFrameAck on Compositor: %p,tid:%d\n",
                //             self.get(), ::GetCurrentThreadId());
                //         OutputDebugStringA(output);
                //         free(output);
            },
            m_id));

    //     m_vizCompositorRunner->PostTask(FROM_HERE, base::BindOnce([](int64_t id) {
    //         VizClient* self = (VizClient*)common::LiveIdDetect::get()->getPtr(id);
    //         if (!self)
    //             return;
    //         self->getPtr()->SetNeedsBeginFrame(false);
    //     }, m_id));
}

bool g_canCommitFrame = true;

viz::CompositorFrame VizClient::createFrame(const viz::BeginFrameArgs& args)
{
    viz::CompositorFrame frame;

    frame.metadata.begin_frame_ack = viz::BeginFrameAck(args, true);
    frame.metadata.device_scale_factor = content::RenderThreadImpl::get()->getZoom();
    frame.metadata.frame_token = ++m_nextFrameToken;

    //     char* output = (char*)malloc(0x500);
    //     sprintf_s(output, 0x499, "VizClient::createFrame on viz compos thread: %p (%d), w:%d tid:%d\n",
    //         this, m_hostLocalSurfaceId.hash(), m_bounds.width(), ::GetCurrentThreadId());
    //     OutputDebugStringA(output);
    //     free(output);

    const viz::CompositorRenderPassId kRenderPassId { 10010 };
    const gfx::Rect& outputRect = m_bounds;
    const gfx::Rect& damageRect = gfx::Rect(0, 0, 0, 0); // gfx::Rect(0, 0, 0, 0);//outputRect
    std::unique_ptr<viz::CompositorRenderPass> renderPass = viz::CompositorRenderPass::Create();
    renderPass->SetNew(kRenderPassId, outputRect, damageRect, gfx::Transform());

    //     renderPass->SetAll(kRenderPassId, outputRect, damageRect, gfx::Transform(),
    //         cc::FilterOperations(), cc::FilterOperations(), absl::optional<gfx::RRectF>(),
    //         viz::SubtreeCaptureId(), gfx::Size(), viz::SharedElementResourceId(), true /*has_transparent_background*/,
    //         false /*cache_render_pass*/, false /*has_damage_from_contributing_content*/, false /*generate_mipmap*/, false /*per_quad_damage*/);

#if 1
    // The content of the client is one big solid-color rectangle, which includes
    // the other clients above it (in z-order). The embedded clients are first
    // added to the CompositorFrame using their SurfaceId (i.e. the FrameSinkId
    // and LocalSurfaceId), and then the big rectangle is added afterwards.
    for (std::map<viz::FrameSinkId, EmbedInfo>::const_iterator iter = m_embeds.begin(); iter != m_embeds.end(); ++iter) {
        if (!g_canCommitFrame)
            continue;
        if (!m_firstSetEmbeds)
            continue;

        const gfx::Rect& childBounds = iter->second.bounds;
        const gfx::Vector2dF center(childBounds.width() / 2, childBounds.height() / 2);

        // Apply a rotation so there's visual-update every frame in the demo.
        gfx::Transform transform;
        //         transform.Translate(center + childBounds.OffsetFromOrigin());
        //         transform.Rotate(iter.second.degrees);
        //         iter.second.degrees += 0.3;
        //         transform.Translate(-center);

        viz::SharedQuadState* quadState1 = renderPass->CreateAndAppendSharedQuadState();
        quadState1->SetAll(transform,
            /*quad_layer_rect=*/childBounds,
            /*visible_layer_rect=*/childBounds,
            /*mask_filter_info=*/gfx::MaskFilterInfo(),
            /*clip_rect=*/absl::nullopt,
            /*are_contents_opaque=*/false,
            /*opacity=*/1.f,
            /*blend_mode=*/SkBlendMode::kSrcOver,
            /*sorting_context_id=*/0,
            /*layer_id*/0,
            /*fast_rounded_corner*/false);

        viz::SurfaceDrawQuad* embedSurfaceDrawquad = renderPass->CreateAndAppendDrawQuad<viz::SurfaceDrawQuad>();

        viz::SurfaceId surfaceId(iter->first, iter->second.lsid);
        // |rect| and |visible_rect| needs to be in the quad's coord-space, so to draw the whole quad, it needs to use origin (0, 0).
        embedSurfaceDrawquad->SetNew(quadState1,
            /*rect=*/gfx::Rect(childBounds.size()),
            /*visible_rect=*/gfx::Rect(childBounds.size()), viz::SurfaceRange(surfaceId),
            SkColors::kGray, //SkColors::kTransparent, // 初始化界面的那个灰色
            /*stretch_content_to_fill_bounds=*/false);
    }
#endif

#if 0
    const SkColor4f colors[] = { SkColors::kWhite/*, SkColors::kGreen, SkColors::kYellow*/ };
    // Add a solid-color draw-quad for the big rectangle covering the entire content-area of the client.
    viz::SharedQuadState* quadState = renderPass->CreateAndAppendSharedQuadState();
    gfx::Rect emptyRc = outputRect;
    emptyRc.set_width(emptyRc.width());
    quadState->SetAll(gfx::Transform(),
        /*quad_layer_rect=*/emptyRc,
        /*visible_layer_rect=*/emptyRc,
        /*mask_filter_info=*/gfx::MaskFilterInfo(),
        /*clip_rect=*/absl::nullopt, /*are_contents_opaque=*/false,
        /*opacity=*/1.f,
        /*blend_mode=*/SkBlendMode::kSrcOver,
        /*sorting_context_id=*/0);

    viz::SolidColorDrawQuad* colorQuad = renderPass->CreateAndAppendDrawQuad<viz::SolidColorDrawQuad>();
    colorQuad->SetNew(quadState, emptyRc, emptyRc, colors[(++m_frameCount / 60) % std::size(colors)], false);
#endif
    frame.render_pass_list.push_back(std::move(renderPass));

    return frame;
}

DWORD g_lastBeginFrameTime = 0;

void onWebviewDidFirstVisuallyNonEmptyPaint(int64_t webviewId);

void VizClient::OnBeginFrame(const ::viz::BeginFrameArgs& args, const base::flat_map<uint32_t, ::viz::FrameTimingDetails>& details, bool frame_ack,
    std::vector<::viz::ReturnedResource> resources)
{
    base::AutoLock lock(m_lock);

    if (!m_canCommitFrame)
        return;

    // Generate a new compositor-frame for each begin-frame. This demo client
    // generates and submits the compositor-frame immediately. But it is possible
    // for the client to delay sending the compositor-frame. |args| includes the
    // deadline for the client before it needs to submit the compositor-frame.
    viz::CompositorFrame frame = createFrame(args);
    viz::LocalSurfaceId localSurfaceId = m_hostLocalSurfaceId;

    onWebviewDidFirstVisuallyNonEmptyPaint(m_webviewId);

    m_vizCompositorRunner->PostTask(FROM_HERE,
        base::BindOnce(
            [](VizClient* self, viz::CompositorFrame frame, viz::LocalSurfaceId localSurfaceId) {
                viz::mojom::CompositorFrameSink* ptr = self->getPtrImpl();
                // 会走到SurfaceManager::GetOrCreateAllocationGroupForSurfaceId
                if (self->m_canCommitFrame && ptr)
                    ptr->SubmitCompositorFrame(localSurfaceId, std::move(frame), absl::optional<viz::HitTestRegionList>(), /*trace_time=*/0);
                else
                    self->allowResize();

                //         DWORD time = ::GetTickCount();
                //         if (time - g_lastBeginFrameTime > 400) {
                //             char* output = (char*)malloc(0x500);
                //             sprintf(output, "VizClient::OnBeginFrame on viz compos thread: (%d), w:%d %d tid:%d\n",
                //                 self->m_hostLocalSurfaceId.hash(), self->m_bounds.width(), self->m_firstSetEmbeds, ::GetCurrentThreadId());
                //             OutputDebugStringA(output);
                //             free(output);
                //         }
                //         g_lastBeginFrameTime = time;

                if (!self->getPtr())
                    return;

                if (!self->m_firstSetEmbeds) { // 预热一帧，下一帧才有真实内容
                    //self->m_firstSetEmbeds = true;
                    //self->allowResize(); // 这一次只是预热，所以可能走不到DidReceiveCompositorFrameAck
                    self->getPtr()->SetNeedsBeginFrame(true); // 再触发一次OnBeginFrame
                } else {
                    self->getPtr()->SetNeedsBeginFrame(false);
                }
            },
            base::Unretained(this), std::move(frame), localSurfaceId));
}

void VizClient::OnBeginFramePausedChanged(bool paused)
{
}

void VizClient::ReclaimResources(std::vector<viz::ReturnedResource> resources)
{
}

void VizClient::OnCompositorFrameTransitionDirectiveProcessed(uint32_t sequence_id)
{
}

void VizClient::OnSurfaceEvicted(const ::viz::LocalSurfaceId& local_surface_id)
{

}

bool VizClient::SetServer(void* self)
{
    m_vizServer = self;
    return true;
}

void VizClient::OnServerDestroy()
{
    m_vizServer = nullptr;
}

} // namespace demo
