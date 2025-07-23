// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/viz/service/frame_sinks/compositor_frame_sink_impl.h"

#include <memory>
#include <utility>
#include <vector>

#include "base/containers/flat_set.h"
#include "base/functional/bind.h"
#include "base/functional/callback_helpers.h"
#include "base/memory/raw_ref.h"
#include "base/threading/platform_thread.h"
#include "base/synchronization/waitable_event.h"
#include "build/build_config.h"
#include "components/viz/service/frame_sinks/frame_sink_bundle_impl.h"
#include "components/viz/service/frame_sinks/frame_sink_manager_impl.h"
#include "services/viz/public/mojom/compositing/layer_context.mojom.h"
#include "ui/gfx/overlay_transform.h"

namespace viz {

namespace {

// Helper class which implements the CompositorFrameSinkClient interface so it
// can route CompositorFrameSinkSupport client messages to a local
// FrameSinkBundleImpl for batching, rather than having them go directly to the
// remote client.
class BundleClientProxy : public mojom::CompositorFrameSinkClient {
public:
    BundleClientProxy(FrameSinkManagerImpl& manager, FrameSinkId frame_sink_id, FrameSinkBundleId bundle_id)
        : manager_(manager)
        , frame_sink_id_(frame_sink_id)
        , bundle_id_(bundle_id)
    {
    }

    BundleClientProxy(const BundleClientProxy&) = delete;
    BundleClientProxy& operator=(const BundleClientProxy&) = delete;
    ~BundleClientProxy() override = default;

    // mojom::CompositorFrameSinkClient implementation:
    void DidReceiveCompositorFrameAck(std::vector<ReturnedResource> resources) override
    {
        if (auto* bundle = GetBundle()) {
            bundle->EnqueueDidReceiveCompositorFrameAck(frame_sink_id_.sink_id(), std::move(resources));
        }
    }

    void OnBeginFrame(const BeginFrameArgs& args, const FrameTimingDetailsMap& timing_details, bool frame_ack, std::vector<ReturnedResource> resources) override
    {
        if (auto* bundle = GetBundle()) {
            bundle->EnqueueOnBeginFrame(frame_sink_id_.sink_id(), args, timing_details, frame_ack, std::move(resources));
        }
    }

    void ReclaimResources(std::vector<ReturnedResource> resources) override
    {
        if (auto* bundle = GetBundle()) {
            bundle->EnqueueReclaimResources(frame_sink_id_.sink_id(), std::move(resources));
        }
    }

    void OnBeginFramePausedChanged(bool paused) override
    {
        if (auto* bundle = GetBundle()) {
            bundle->SendOnBeginFramePausedChanged(frame_sink_id_.sink_id(), paused);
        }
    }

    void OnCompositorFrameTransitionDirectiveProcessed(uint32_t sequence_id) override
    {
        if (auto* bundle = GetBundle()) {
            bundle->SendOnCompositorFrameTransitionDirectiveProcessed(frame_sink_id_.sink_id(), sequence_id);
        }
    }

    void OnSurfaceEvicted(const LocalSurfaceId& local_surface_id) override
    {
    }

private:
    FrameSinkBundleImpl* GetBundle()
    {
        return manager_->GetFrameSinkBundle(bundle_id_);
    }

    const raw_ref<FrameSinkManagerImpl> manager_;
    const FrameSinkId frame_sink_id_;
    const FrameSinkBundleId bundle_id_;
};

} // namespace

CompositorFrameSinkImpl::CompositorFrameSinkImpl(FrameSinkManagerImpl* frame_sink_manager, const FrameSinkId& frame_sink_id,
    std::optional<FrameSinkBundleId> bundle_id, mojo::PendingReceiver<mojom::CompositorFrameSink> receiver,
    mojo::PendingRemote<mojom::CompositorFrameSinkClient> client)
    : compositor_frame_sink_client_(std::move(client))
   
    , proxying_client_(bundle_id.has_value() ? std::make_unique<BundleClientProxy>(*frame_sink_manager, frame_sink_id, *bundle_id) : nullptr)
    , compositor_frame_sink_receiver_(this, std::move(receiver))
    , support_(std::make_unique<CompositorFrameSinkSupport>(
          proxying_client_ ? proxying_client_.get() : compositor_frame_sink_client_.get(), frame_sink_manager, frame_sink_id, false /* is_root */))
    , runner_(base::SingleThreadTaskRunner::GetCurrentDefault())
{
    compositor_frame_sink_receiver_.set_disconnect_handler(base::BindOnce(&CompositorFrameSinkImpl::OnClientConnectionLost, base::Unretained(this)));
    if (bundle_id.has_value()) {
        support_->SetBundle(*bundle_id);
    }

    char output[100] = { 0 };
    sprintf_s(output, 99, "CompositorFrameSinkImpl: %p\n", this);
    OutputDebugStringA(output);

    compositor_frame_sink_client_->OnBindCompositorFrameSinkClient();
}

CompositorFrameSinkImpl::~CompositorFrameSinkImpl()
{
    char output[100] = { 0 };
    sprintf_s(output, 99, "~CompositorFrameSinkImpl: %p\n", this);
    OutputDebugStringA(output);
}

void CompositorFrameSinkImpl::SetNeedsBeginFrame(bool needs_begin_frame)
{
    if (runner_->BelongsToCurrentThread()) {
        support_->SetNeedsBeginFrame(needs_begin_frame);
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self, bool needs_begin_frame) { self->support_->SetNeedsBeginFrame(needs_begin_frame); },
                base::Unretained(this), needs_begin_frame));
    }
}

void CompositorFrameSinkImpl::SetWantsAnimateOnlyBeginFrames()
{
    if (runner_->BelongsToCurrentThread()) {
        support_->SetWantsAnimateOnlyBeginFrames();
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self) { self->support_->SetWantsAnimateOnlyBeginFrames(); },
                base::Unretained(this)));
    }
}

void CompositorFrameSinkImpl::SetWantsBeginFrameAcks()
{
    if (runner_->BelongsToCurrentThread()) {
        support_->SetWantsBeginFrameAcks();
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self) { self->support_->SetWantsBeginFrameAcks(); },
                base::Unretained(this)));
    }
}

void CompositorFrameSinkImpl::SetAutoNeedsBeginFrame()
{
    if (runner_->BelongsToCurrentThread()) {
        support_->SetAutoNeedsBeginFrame();
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self) { self->support_->SetAutoNeedsBeginFrame(); },
                base::Unretained(this)));
    }
}

void CompositorFrameSinkImpl::SubmitCompositorFrame(
    const LocalSurfaceId& local_surface_id, CompositorFrame frame, std::optional<HitTestRegionList> hit_test_region_list, uint64_t submit_time)
{
    // Non-root surface frames should not have display transform hint.
    DCHECK_EQ(gfx::OVERLAY_TRANSFORM_NONE, frame.metadata.display_transform_hint);
    SubmitCompositorFrameInternal(local_surface_id, std::move(frame), std::move(hit_test_region_list), submit_time, SubmitCompositorFrameSyncCallback());
}

void CompositorFrameSinkImpl::SubmitCompositorFrameSync(const LocalSurfaceId& local_surface_id, CompositorFrame frame,
    std::optional<HitTestRegionList> hit_test_region_list, uint64_t submit_time, SubmitCompositorFrameSyncCallback callback)
{
    SubmitCompositorFrameInternal(local_surface_id, std::move(frame), std::move(hit_test_region_list), submit_time, std::move(callback));
}

void CompositorFrameSinkImpl::SubmitCompositorFrameInternal(const LocalSurfaceId& local_surface_id, CompositorFrame frame,
    std::optional<HitTestRegionList> hit_test_region_list, uint64_t submit_time, mojom::CompositorFrameSink::SubmitCompositorFrameSyncCallback callback)
{
//     const auto result
//         = support_->MaybeSubmitCompositorFrame(local_surface_id, std::move(frame), std::move(hit_test_region_list), submit_time, std::move(callback));
//     if (result == SubmitResult::ACCEPTED)
//         return;

    SubmitResult result = (SubmitResult)-1;
    base::WaitableEvent wait_evt;
    if (runner_->BelongsToCurrentThread()) {
        result = support_->MaybeSubmitCompositorFrame(local_surface_id, std::move(frame), std::move(hit_test_region_list), submit_time, std::move(callback));
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce(
                [](CompositorFrameSinkImpl* self, SubmitResult* res, const LocalSurfaceId& local_surface_id, CompositorFrame frame,
                    absl::optional<HitTestRegionList> hit_test_region_list, uint64_t submit_time,
                    mojom::CompositorFrameSink::SubmitCompositorFrameSyncCallback callback, base::WaitableEvent* evt) {
                        *res = self->support_->MaybeSubmitCompositorFrame(local_surface_id, std::move(frame), std::move(hit_test_region_list), submit_time, std::move(callback));
            evt->Signal();
        }, base::Unretained(this), &result, local_surface_id, std::move(frame), std::move(hit_test_region_list), submit_time, std::move(callback), &wait_evt));

        wait_evt.Wait();
    }

//     if (result == SubmitResult::ACCEPTED)
//         return;
// 
//     *(int*)1 = 1;
//     const char* reason = CompositorFrameSinkSupport::GetSubmitResultAsString(result);
//     DLOG(ERROR) << "SubmitCompositorFrame failed for " << local_surface_id << " because " << reason;
//     compositor_frame_sink_receiver_.ResetWithReason(static_cast<uint32_t>(result), reason);
}

void CompositorFrameSinkImpl::DidNotProduceFrame(const BeginFrameAck& begin_frame_ack)
{
    if (runner_->BelongsToCurrentThread()) {
        support_->DidNotProduceFrame(begin_frame_ack);
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self, const BeginFrameAck& begin_frame_ack) { self->support_->DidNotProduceFrame(begin_frame_ack); },
                base::Unretained(this), begin_frame_ack));
    }
}

void CompositorFrameSinkImpl::DidAllocateSharedBitmap(base::ReadOnlySharedMemoryRegion region, const SharedBitmapId& id)
{
//     if (!support_->DidAllocateSharedBitmap(std::move(region), id)) {
//         DLOG(ERROR) << "DidAllocateSharedBitmap failed for duplicate "
//                     << "SharedBitmapId";
//         compositor_frame_sink_receiver_.reset();
//     }

    bool ok = false;
    if (runner_->BelongsToCurrentThread()) {
        ok = support_->DidAllocateSharedBitmap(std::move(region), id);
    } else {
        base::WaitableEvent wait_evt;
        runner_->PostTask(FROM_HERE,
            base::BindOnce(
                [](CompositorFrameSinkImpl* self, base::ReadOnlySharedMemoryRegion region, const SharedBitmapId& id, bool* ok, base::WaitableEvent* evt) {
                    *ok = self->support_->DidAllocateSharedBitmap(std::move(region), id);
                    if (!(*ok))
                        CHECK(false);
                    evt->Signal();
                }, base::Unretained(this), std::move(region), id, &ok, &wait_evt));
        wait_evt.Wait();
    }

    if (!ok) {
        DLOG(ERROR) << "DidAllocateSharedBitmap failed for duplicate "
            << "SharedBitmapId";
        compositor_frame_sink_receiver_.reset();
        OnClientConnectionLost();
    }
}

void CompositorFrameSinkImpl::DidDeleteSharedBitmap(const SharedBitmapId& id)
{
    if (runner_->BelongsToCurrentThread()) {
        support_->DidDeleteSharedBitmap(id);
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self, const SharedBitmapId& id) { self->support_->DidDeleteSharedBitmap(id); },
                base::Unretained(this), id));
    }
}

void CompositorFrameSinkImpl::InitializeCompositorFrameSinkType(mojom::CompositorFrameSinkType type)
{
    if (runner_->BelongsToCurrentThread()) {
        support_->InitializeCompositorFrameSinkType(type);
    } else {
        runner_->PostTask(FROM_HERE,
            base::BindOnce([](CompositorFrameSinkImpl* self, mojom::CompositorFrameSinkType type) { self->support_->InitializeCompositorFrameSinkType(type); },
                base::Unretained(this), type));
    }
}

void CompositorFrameSinkImpl::BindLayerContext(mojom::PendingLayerContextPtr context)
{
    *(int*)1 = 1;
    support_->BindLayerContext(*context);
}

#if BUILDFLAG(IS_ANDROID)
void CompositorFrameSinkImpl::SetThreads(const std::vector<Thread>& threads)
{
    support_->SetThreads(/*from_untrusted_client=*/true, threads);
}
#endif

void CompositorFrameSinkImpl::OnClientConnectionLost()
{
    // The client that owns this CompositorFrameSink is either shutting down or
    // has done something invalid and the connection to the client was terminated.
    // Destroy |this| to free up resources as it's no longer useful.
    FrameSinkId frame_sink_id = support_->frame_sink_id();
    support_->frame_sink_manager()->DestroyCompositorFrameSink(frame_sink_id, base::DoNothing());
}

} // namespace viz
