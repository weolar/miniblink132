// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_viz_OffscreenDisplayClient_h
#define content_viz_OffscreenDisplayClient_h

#include <memory>

#include "base/task/single_thread_task_runner.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
#include "components/viz/host/viz_host_export.h"
#include "mojo/public/cpp/bindings/pending_remote.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "services/viz/privileged/mojom/compositing/display_private.mojom.h"
#include "ui/gfx/native_widget_types.h"

namespace content {

class OffscreenWindowUpdater;
class MbWebView;

// mojom::DisplayClient implementation that relays calls to platform specific
// functions.
class OffscreenDisplayClient : public viz::mojom::DisplayClient {
public:
    explicit OffscreenDisplayClient(MbWebView* mbwebview);

    OffscreenDisplayClient(const OffscreenDisplayClient&) = delete;
    OffscreenDisplayClient& operator=(const OffscreenDisplayClient&) = delete;

    ~OffscreenDisplayClient() override;

    mojo::PendingRemote<viz::mojom::DisplayClient> GetBoundRemote(scoped_refptr<base::SingleThreadTaskRunner> task_runner);

private:
    // mojom::DisplayClient implementation:
#if BUILDFLAG(IS_APPLE)
    void OnDisplayReceivedCALayerParams(const gfx::CALayerParams& ca_layer_params) override;
#endif

#if 1 // BUILDFLAG(IS_WIN)
    void CreateLayeredWindowUpdater(mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver) override;
#endif

// TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
// of lacros-chrome is complete.
#if 0 // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
    void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
#endif

    void AddChildWindowToBrowser(::gpu::SurfaceHandle child_window) override;

    mojo::Receiver<viz::mojom::DisplayClient> m_receiver { this };

    int64_t m_mbwebviewId;
#if 1 // BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
    gfx::AcceleratedWidget m_hwnd = nullptr;
#endif

    bool m_isAutoDrawToHwnd = true;

#if 1 // BUILDFLAG(IS_WIN)
    std::unique_ptr<OffscreenWindowUpdater> m_offscreenWindowUpdater;
#endif
};

} // namespace content

#endif // content_viz_OffscreenDisplayClient_h
