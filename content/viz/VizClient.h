// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VIZ_DEMO_CLIENT_DEMO_CLIENT_H_
#define COMPONENTS_VIZ_DEMO_CLIENT_DEMO_CLIENT_H_

#include <map>
#include <vector>

#include "base/synchronization/lock.h"
#include "base/threading/thread.h"
#include "components/viz/common/frame_timing_details_map.h"
#include "components/viz/common/quads/compositor_frame_metadata.h"
#include "components/viz/common/surfaces/parent_local_surface_id_allocator.h"
#include "mojo/public/cpp/bindings/associated_remote.h"
#include "mojo/public/cpp/bindings/pending_associated_remote.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/pending_remote.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "services/viz/public/mojom/compositing/compositor_frame_sink.mojom.h"

namespace viz {
class CompositorFrame;
}

namespace content {
class RenderWidgetHostImpl;
}

namespace content {

// VizClient is responsible for communicating with the display-compositor. It
// sends messages to the service over the mojom.CompositorFrameSink interface,
// and receives messages through the mojom.CompositorFrameSinkClient interface.
//
// The client needs to have an identifier, FrameSinkId, which doesn't change
// during the lifetime of the client. The embedder of the client needs to know
// about this FrameSinkId. The 'host', when it itself is not the embedder, also
// needs to know about this FrameSinkId, so that it can set up the
// frame-hierarchy correctly in the service.
//
// The client also needs to have a LocalSurfaceId, which represents an embedding
// of the client in a particular state. If, for example, the size of the client
// changes (or other attributes, like device scale factor), then a new
// LocalSurfaceId needs to be allocated. The LocalSurfaceId is used to submit
// the CompositorFrame. Both the embedder and the embedded clients need to know
// the LocalSurfaceId. It is possible for both the embedder and the embedded
// client to generate new LocalSurfaceId (typically using a
// ParentLocalSurfaceIdAllocator and ChildLocalSurfaceIdAllocator respectively).
// In this demo, only the embedder allocates the LocalSurfaceId.
class VizClient : public viz::mojom::CompositorFrameSinkClient {
public:
    VizClient(const viz::FrameSinkId& frame_sink_id, const viz::LocalSurfaceId& localSurfaceId, const gfx::Rect& bounds,
        scoped_refptr<base::SingleThreadTaskRunner> service_runner);

    VizClient(const VizClient&) = delete;
    VizClient& operator=(const VizClient&) = delete;

    ~VizClient() override;
    void destroy(std::function<void(void)>&& callback);

    const viz::FrameSinkId& frameSinkId() const
    {
        return m_frameSinkId;
    }
    const viz::LocalSurfaceId& localSurfaceId() const
    {
        return m_hostLocalSurfaceId;
    }

    // Initializes the mojo connection to the service.
    //void initialize(
    //    mojo::PendingReceiver<viz::mojom::CompositorFrameSinkClient> receiver, mojo::PendingAssociatedRemote<viz::mojom::CompositorFrameSink> sink_remote);
    void initialize(mojo::PendingReceiver<viz::mojom::CompositorFrameSinkClient> receiver, mojo::PendingRemote<viz::mojom::CompositorFrameSink> sink_remote);

    // This prepares for this client to embed another client (i.e. this client
    // acts as the embedder). Since this client is the embedder, it allocates the
    // LocalSurfaceId, and returns that. The client that should be embedded (i.e.
    // the client represented by |frame_sink_id|) should use the returned
    // LocalSurfaceId to submit visual content (CompositorFrame).
    viz::LocalSurfaceId embedOnBlinkThread(const viz::FrameSinkId& frame_sink_id, const gfx::Rect& bounds, const viz::LocalSurfaceId& newLocalSurfaceId);

    // When this client is resized, it is important that it also receives a new
    // LocalSurfaceId with the new size.
    void resizeOnHostThread(const gfx::Size& size, const viz::LocalSurfaceId& localSurfaceId);

    viz::LocalSurfaceId GenLocalSurfaceId();
    viz::LocalSurfaceId GetLocalSurfaceId();

    void setIsRootClient()
    {
        m_isRootClient = true;
    }

    void setWidgetHost(content::RenderWidgetHostImpl* widget_host)
    {
        m_widgetHost = widget_host;
    }

    bool isAllowResize() const
    {
        return m_allowResize;
    }
    void allowResize()
    {
        m_allowResize = true;
    }
    void disallowResize()
    {
        m_allowResize = false;
    }

    void setWebviewId(int64_t id)
    {
        m_webviewId = id;
    } // 抛一些回调给webview

private:
    friend class RenderFrameMetadataObserverClientImpl;

    struct EmbedInfo {
        viz::LocalSurfaceId lsid;
        gfx::Rect bounds;
        float degrees = 0.f;
    };

    viz::CompositorFrame createFrame(const viz::BeginFrameArgs& args) EXCLUSIVE_LOCKS_REQUIRED(m_lock);
    viz::CompositorFrame createEmptyFrame(const viz::BeginFrameArgs& args);

    viz::mojom::CompositorFrameSink* getPtr();
    viz::mojom::CompositorFrameSink* getPtrImpl();

    void initializeOnThread(mojo::PendingReceiver<viz::mojom::CompositorFrameSinkClient> receiver,
        mojo::PendingAssociatedRemote<viz::mojom::CompositorFrameSink> associated_sink_remote,
        mojo::PendingRemote<viz::mojom::CompositorFrameSink> sink_remote);

    // viz::mojom::CompositorFrameSinkClient:
    void DidReceiveCompositorFrameAck(std::vector<viz::ReturnedResource> resources) override;
    void OnBeginFrame(const ::viz::BeginFrameArgs& args, const base::flat_map<uint32_t, ::viz::FrameTimingDetails>& details, bool frame_ack,
        std::vector<::viz::ReturnedResource> resources) override;
    void OnBeginFramePausedChanged(bool paused) override;
    void ReclaimResources(std::vector<viz::ReturnedResource> resources) override;
    void OnCompositorFrameTransitionDirectiveProcessed(uint32_t sequence_id) override;
    void OnSurfaceEvicted(const ::viz::LocalSurfaceId& local_surface_id) override;

    bool SetServer(void* self) override;
    void OnServerDestroy() override;



    int64_t m_id;

    // This thread is created solely to demonstrate that the client can live in
    // its own thread (or even in its own process). A viz client does not need to
    // have its own thread.
    //base::Thread m_thread;

    const viz::FrameSinkId m_frameSinkId;
    viz::LocalSurfaceId m_hostLocalSurfaceId /*GUARDED_BY(m_lock)*/;
    gfx::Rect m_bounds /*GUARDED_BY(m_lock)*/;

    mojo::Receiver<viz::mojom::CompositorFrameSinkClient> m_receiver { this };
    mojo::AssociatedRemote<viz::mojom::CompositorFrameSink> m_associatedSink;
    mojo::Remote<viz::mojom::CompositorFrameSink> m_sink;
    viz::FrameTokenGenerator m_nextFrameToken;
    uint32_t m_frameCount = 0;

    base::Lock m_lock;
    // The |m_allocator| is used only when this client acts as an embedder, and
    // embeds other clients.
    viz::ParentLocalSurfaceIdAllocator m_allocator;
    std::map<viz::FrameSinkId, EmbedInfo> m_embeds /*GUARDED_BY(m_lock)*/;
    bool m_firstSetEmbeds = false;

    bool m_isRootClient = false;
    content::RenderWidgetHostImpl* m_widgetHost = nullptr;

    int64_t m_webviewId = 0;

    bool m_canCommitFrame = true;
    bool m_allowResize = true;

    void* m_vizServer = nullptr;

    scoped_refptr<base::SingleThreadTaskRunner> m_vizCompositorRunner;
    base::WeakPtrFactory<VizClient> m_weakPtrFactory { this };
};

} // namespace demo

#endif // COMPONENTS_VIZ_DEMO_CLIENT_DEMO_CLIENT_H_
