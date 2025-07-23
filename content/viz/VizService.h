// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VIZ_DEMO_SERVICE_DEMO_SERVICE_H_
#define COMPONENTS_VIZ_DEMO_SERVICE_DEMO_SERVICE_H_

#include <memory>

#include "base/threading/thread.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/pending_remote.h"
#include "services/viz/privileged/mojom/compositing/frame_sink_manager.mojom.h"

namespace viz {
class VizCompositorThreadRunnerImpl;
} // namespace viz

namespace content {

// VizService sets up the display compositor, and connects to the host over the
// mojom API. The host communicates with the FrameSinkManagerImpl over the
// mojom.FrameSinkManager API, and the FrameSinkManagerImpl communicates with
// the host over the mojom.FrameSinkManagerClient API.
class VizService {
public:
    VizService(mojo::PendingReceiver<viz::mojom::FrameSinkManager> receiver, mojo::PendingRemote<viz::mojom::FrameSinkManagerClient> client);

    VizService(const VizService&) = delete;
    VizService& operator=(const VizService&) = delete;

    ~VizService();

    void destroy(std::function<void(void)>&& callback);

    scoped_refptr<base::SingleThreadTaskRunner> GetCompositorThreadRunner();

private:
    std::unique_ptr<viz::VizCompositorThreadRunnerImpl> m_runner;
};

} // namespace demo

#endif // COMPONENTS_VIZ_DEMO_SERVICE_DEMO_SERVICE_H_
