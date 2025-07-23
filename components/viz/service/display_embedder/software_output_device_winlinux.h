// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_SOFTWARE_OUTPUT_DEVICE_LINUX_H_
#define COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_SOFTWARE_OUTPUT_DEVICE_LINUX_H_

#include <windows.h>

#include <memory>

#include "base/memory/raw_ptr.h"
#include "base/threading/thread_checker.h"
#include "base/synchronization/lock.h"
#include "components/viz/service/display/software_output_device.h"
#include "components/viz/service/display_embedder/output_device_backing.h"
#include "components/viz/service/viz_service_export.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "services/viz/privileged/mojom/compositing/display_private.mojom.h"
#include "services/viz/privileged/mojom/compositing/layered_window_updater.mojom.h"
#include "third_party/skia/include/core/SkCanvas.h"

namespace viz {

// Shared base class for Linux SoftwareOutputDevice implementations.
class VIZ_SERVICE_EXPORT SoftwareOutputDeviceWinOrLinuxBase : public SoftwareOutputDevice {
public:
    explicit SoftwareOutputDeviceWinOrLinuxBase(HWND hwnd);
    SoftwareOutputDeviceWinOrLinuxBase(const SoftwareOutputDeviceWinOrLinuxBase& other) = delete;
    SoftwareOutputDeviceWinOrLinuxBase& operator=(const SoftwareOutputDeviceWinOrLinuxBase& other) = delete;
    ~SoftwareOutputDeviceWinOrLinuxBase() override;

    HWND hwnd() const
    {
        return hwnd_;
    }

    // SoftwareOutputDevice implementation.
    void Resize(const gfx::Size& viewport_pixel_size, float scale_factor) override;
    SkCanvas* BeginPaint(const gfx::Rect& damage_rect) override;
    void EndPaint() override;

    // Called from Resize() if |viewport_pixel_size_| has changed.
    virtual void ResizeDelegated() = 0;

    // Called from BeginPaint() and should return an SkCanvas.
    virtual SkCanvas* BeginPaintDelegated() = 0;

    // Called from EndPaint() if there is damage.
    virtual void EndPaintDelegated(const gfx::Rect& damage_rect) = 0;

private:
    const HWND hwnd_;
    bool in_paint_ = false;

    THREAD_CHECKER(thread_checker_);
};

// SoftwareOutputDevice implementation that uses layered window API to draw
// indirectly. Since UpdateLayeredLinuxdow() is blocked by the GPU sandbox an
// implementation of mojom::LayeredLinuxdowUpdater in the browser process handles
// calling UpdateLayeredLinuxdow. Pixel backing is in a SharedMemoryRegion so no
// copying between processes is required.
class VIZ_SERVICE_EXPORT SoftwareOutputDeviceWinOrLinux : public SoftwareOutputDeviceWinOrLinuxBase {
public:
    SoftwareOutputDeviceWinOrLinux(HWND hwnd, mojo::PendingRemote<mojom::LayeredWindowUpdater> layered_window_updater);
    ~SoftwareOutputDeviceWinOrLinux() override;

    // SoftwareOutputDevice implementation.
    void OnSwapBuffers(SwapBuffersCallback swap_ack_callback, gfx::FrameData data) override;

    // SoftwareOutputDeviceWinOrLinuxBase implementation.
    void ResizeDelegated() override;
    SkCanvas* BeginPaintDelegated() override;
    void EndPaintDelegated(const gfx::Rect& rect) override;

private:
    // Runs |swap_ack_callback_| after draw has happened.
    void DrawAck();

    mojo::Remote<mojom::LayeredWindowUpdater> layered_window_updater_;

    std::unique_ptr<SkCanvas> canvas_;

    std::unique_ptr<SkCanvas> transparent_background_canvas_;
    uint8_t* transparent_background_pixels_ = nullptr;
    bool has_transparent_background_canvas_ = true;
    uint32_t background_color_ = 0xffffffff;
    bool has_background_color_ = false;

    uint8_t* bitmap_pixels_ = nullptr;
    gfx::Size bitmap_pixels_size_;

    bool waiting_on_draw_ack_ = false;
    base::OnceClosure swap_ack_callback_;

    base::Lock canvas_lock_;
};

// Creates an appropriate SoftwareOutputDevice implementation.
VIZ_SERVICE_EXPORT std::unique_ptr<SoftwareOutputDevice> CreateSoftwareOutputDeviceWinOrLinux(HWND hwnd, mojom::DisplayClient* display_client);

} // namespace viz

#endif // COMPONENTS_VIZ_SERVICE_DISPLAY_EMBEDDER_SOFTWARE_OUTPUT_DEVICE_WIN_H_
