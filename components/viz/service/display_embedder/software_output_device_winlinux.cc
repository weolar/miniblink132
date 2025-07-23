// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/viz/service/display_embedder/software_output_device_winlinux.h"

#include <utility>

#include "base/bind.h"
#include "base/memory/unsafe_shared_memory_region.h"
#include "base/trace_event/trace_event.h"
//#include "base/win/windows_version.h"
#include "components/viz/common/display/use_layered_window.h"
#include "components/viz/common/resources/resource_format.h"
#include "components/viz/common/resources/resource_sizes.h"
#include "mojo/public/cpp/bindings/pending_remote.h"
#include "mojo/public/cpp/system/platform_handle.h"
#include "services/viz/privileged/mojom/compositing/layered_window_updater.mojom.h"
#include "third_party/skia/src/core/SkImagePriv.h"
#include "skia/ext/platform_canvas.h"
#if BUILDFLAG(IS_WIN)
#include "skia/ext/skia_utils_win.h"
#include "ui/gfx/gdi_util.h"
#endif
#include "ui/gfx/geometry/skia_conversions.h"
#if BUILDFLAG(IS_WIN)
#include "ui/gfx/win/hwnd_util.h"
#include "ui/gl/vsync_provider_win.h"
#endif

#if defined(USE_OZONE)
#include <cairo.h>
#endif
#include "base/rand_util.h"

namespace content {
bool SaveHDCToBitmap(HDC hdc, int width, int height, const char* filename);
}

namespace viz {

SoftwareOutputDeviceWinOrLinuxBase::SoftwareOutputDeviceWinOrLinuxBase(HWND hwnd)
    : hwnd_(hwnd)
{
#if BUILDFLAG(IS_WIN)
    //vsync_provider_ = std::make_unique<gl::VSyncProviderWin>(hwnd); // -> SoftwareOutputSurface::SwapBuffers
#endif
}

SoftwareOutputDeviceWinOrLinuxBase::~SoftwareOutputDeviceWinOrLinuxBase()
{
    DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
    DCHECK(!in_paint_);
}

void SoftwareOutputDeviceWinOrLinuxBase::Resize(const gfx::Size& viewport_pixel_size, float scale_factor)
{
    DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
    DCHECK(!in_paint_);

    if (viewport_pixel_size_ == viewport_pixel_size)
        return;

    viewport_pixel_size_ = viewport_pixel_size;
    ResizeDelegated();
}

SkCanvas* SoftwareOutputDeviceWinOrLinuxBase::BeginPaint(const gfx::Rect& damage_rect)
{
    DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
    DCHECK(!in_paint_);

    damage_rect_ = damage_rect;
    in_paint_ = true;
    return BeginPaintDelegated();
}

void SoftwareOutputDeviceWinOrLinuxBase::EndPaint()
{
    DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
    DCHECK(in_paint_);

    in_paint_ = false;

    gfx::Rect intersected_damage_rect = damage_rect_;
    intersected_damage_rect.Intersect(gfx::Rect(viewport_pixel_size_));
    if (intersected_damage_rect.IsEmpty())
        return;

    EndPaintDelegated(intersected_damage_rect);
}

SoftwareOutputDeviceWinOrLinux::SoftwareOutputDeviceWinOrLinux(HWND hwnd, mojo::PendingRemote<mojom::LayeredWindowUpdater> layered_window_updater)
    : SoftwareOutputDeviceWinOrLinuxBase(hwnd)
    , layered_window_updater_(std::move(layered_window_updater))
{
    DCHECK(layered_window_updater_.is_bound());
    has_transparent_background_canvas_ = layered_window_updater_->HasTransparent();

    uint32_t c = layered_window_updater_->GetBackgroundColor(&has_background_color_);
    if (has_background_color_)
        background_color_ = c;
}

SoftwareOutputDeviceWinOrLinux::~SoftwareOutputDeviceWinOrLinux()
{
    base::AutoLock lock(canvas_lock_);
    canvas_.reset();
#if !defined(WIN32)
    if (bitmap_pixels_)
        free(bitmap_pixels_);
#endif
}

void SoftwareOutputDeviceWinOrLinux::OnSwapBuffers(SwapBuffersCallback swap_ack_callback, gfx::FrameData data)
{
    DCHECK(swap_ack_callback_.is_null());

    // We aren't waiting on DrawAck() and can immediately run the callback.
    if (!waiting_on_draw_ack_) {
        task_runner_->PostTask(FROM_HERE, base::BindOnce(std::move(swap_ack_callback), viewport_pixel_size_));
        return;
    }

    swap_ack_callback_ = base::BindOnce(std::move(swap_ack_callback), viewport_pixel_size_);
}

static void CopyCanvasContent(uint8_t* src_bitmap_pixels, SkCanvas* dst_canvase, int width, int height)
{
    *(int*)1 = 1;
//     if (!src_bitmap_pixels || !dst_canvase)
//         return;
// 
//     SkBitmap bitmap;
//     SkAlphaType alpha = kOpaque_SkAlphaType;
//     SkImageInfo info = SkImageInfo::MakeN32(width, height, alpha);
//     bitmap.installPixels(info, src_bitmap_pixels, width * 4, nullptr, nullptr);
// 
//     sk_sp<SkImage> img = SkImage::MakeFromBitmap(bitmap);
//     dst_canvase->drawImage(img, 0, 0);
}

void SoftwareOutputDeviceWinOrLinux::ResizeDelegated()
{
    base::AutoLock lock(canvas_lock_);

    size_t required_bytes;
    if (!ResourceSizes::MaybeSizeInBytes<size_t>(viewport_pixel_size_, SinglePlaneFormat::kRGBA_8888, &required_bytes)) {
        canvas_.reset();
        DLOG(ERROR) << "Invalid viewport size " << viewport_pixel_size_.ToString();
        return;
    }

    // The SkCanvas maps shared memory on creation and unmaps on destruction.
    uint8_t* bitmap_pixels = nullptr;
#if !defined(WIN32)
    bitmap_pixels = (uint8_t*)malloc(required_bytes);
    std::unique_ptr<SkCanvas> new_canvase
        = skia::CreatePlatformCanvasWithPixels(viewport_pixel_size_.width(), viewport_pixel_size_.height(), true, bitmap_pixels, skia::CRASH_ON_FAILURE);
    //CopyCanvasContent(bitmap_pixels_, new_canvase.get(), bitmap_pixels_size_.width(), bitmap_pixels_size_.height());

    if (bitmap_pixels_)
        free(bitmap_pixels_);
#else
    std::unique_ptr<SkCanvas> new_canvase = skia::CreatePlatformCanvasReturnPixels(
        viewport_pixel_size_.width(), viewport_pixel_size_.height(), !has_transparent_background_canvas_, &bitmap_pixels);
    //CopyCanvasContent(bitmap_pixels_, new_canvase.get(), bitmap_pixels_size_.width(), bitmap_pixels_size_.height());

    if (has_transparent_background_canvas_) {
        transparent_background_pixels_ = nullptr;
        transparent_background_canvas_
            = skia::CreatePlatformCanvasReturnPixels(viewport_pixel_size_.width(), viewport_pixel_size_.height(), false, &transparent_background_pixels_);
    }
#endif
    bitmap_pixels_size_ = viewport_pixel_size_;
    bitmap_pixels_ = bitmap_pixels;
    canvas_.reset(new_canvase.release());
    //--
    //     SkPaint mPaint;
    //     mPaint.setColor(0xff1162ff);
    //     mPaint.setStyle(SkPaint::kFill_Style); // 空心的，只有边框
    //
    //     SkRect r = SkRect::MakeLTRB(0, 0, 200, 200);
    //     canvas_->drawRect(r, mPaint);
    //base::RandBytes(bitmap_pixels_, required_bytes);
    //--
    //     HDC memoryDC = skia::GetNativeDrawingContext(canvas_.get());
    //     static int count = 0;
    //     char* filename = (char*)malloc(400);
    //     sprintf_s(filename, 399, "W:\\test\\exe_test\\yunci\\bmp\\bmp_%d.bmp", count);
    //     content::SaveHDCToBitmap(memoryDC, bitmap_pixels_size_.width(), bitmap_pixels_size_.height(), filename);
    //     free(filename);
    //     count++;
    //--

    if (has_transparent_background_canvas_) {
        transparent_background_canvas_->clear(has_background_color_ ? SkColor4f::FromColor(background_color_) : SkColors::kTransparent);
        canvas_->clear(has_background_color_ ? SkColor4f::FromColor(background_color_) : SkColors::kTransparent);
    } else if (has_background_color_) {
        canvas_->clear(background_color_);
    }

    // Transfer region ownership to the browser process.
    layered_window_updater_->OnAllocatedBitmapMemory(viewport_pixel_size_, canvas_.get(), bitmap_pixels_, &canvas_lock_);
}

SkCanvas* SoftwareOutputDeviceWinOrLinux::BeginPaintDelegated()
{
    canvas_lock_.Acquire();

    if (transparent_background_canvas_) {
        transparent_background_canvas_->clear(has_background_color_ ? SkColor4f::FromColor(background_color_) : SkColors::kTransparent);
        return transparent_background_canvas_.get();
    }

    return canvas_.get();
}

void SoftwareOutputDeviceWinOrLinux::EndPaintDelegated(const gfx::Rect& damage_rect)
{
    DCHECK(!waiting_on_draw_ack_);
    if (!canvas_) {
        canvas_lock_.Release();
        return;
    }

    if (transparent_background_canvas_.get()) {
        SkBitmap bitmap;
        SkAlphaType alpha = kPremul_SkAlphaType;
        SkImageInfo info = SkImageInfo::MakeN32(bitmap_pixels_size_.width(), bitmap_pixels_size_.height(), alpha);
        bitmap.installPixels(info, transparent_background_pixels_, bitmap_pixels_size_.width() * 4, nullptr, nullptr);
        
        sk_sp<SkImage> img = SkMakeImageFromRasterBitmap(bitmap, kIfMutable_SkCopyPixelsMode);
        //sk_sp<SkImage> img = SkImage::MakeFromBitmap(bitmap);
        SkRect r = gfx::RectToSkRect(damage_rect);

        SkPaint paint;
        paint.setColor(has_background_color_ ? SkColor4f::FromColor(background_color_) : SkColors::kTransparent);
        paint.setBlendMode(SkBlendMode::kSrc);
        paint.setStyle(SkPaint::Style::kFill_Style);
        canvas_->drawRect(r, paint);

        canvas_->drawImageRect(img.get(), r, r, SkSamplingOptions(), nullptr, SkCanvas::kFast_SrcRectConstraint);
    }
    canvas_lock_.Release();

    if (layered_window_updater_.is_bound() && layered_window_updater_.get())
        layered_window_updater_->Draw(damage_rect, base::BindOnce(&SoftwareOutputDeviceWinOrLinux::DrawAck, base::Unretained(this)));
    waiting_on_draw_ack_ = true;

    TRACE_EVENT_ASYNC_BEGIN0("viz", "SoftwareOutputDeviceWinOrLinux::Draw", this);
}

void SoftwareOutputDeviceWinOrLinux::DrawAck()
{
    DCHECK(waiting_on_draw_ack_);

    TRACE_EVENT_ASYNC_END0("viz", "SoftwareOutputDeviceWinOrLinux::Draw", this);

    waiting_on_draw_ack_ = false;

    // It's possible the display compositor won't call SwapBuffers() so there will
    // be no callback to run.
    if (swap_ack_callback_)
        std::move(swap_ack_callback_).Run();
}

std::unique_ptr<SoftwareOutputDevice> CreateSoftwareOutputDeviceWinOrLinux(HWND hwnd, mojom::DisplayClient* display_client)
{
    DCHECK(display_client);

    // Setup mojom::LayeredWindowUpdater implementation in the browser process
    // to draw to the HWND.
    mojo::PendingRemote<mojom::LayeredWindowUpdater> layered_window_updater;
    display_client->CreateLayeredWindowUpdater(layered_window_updater.InitWithNewPipeAndPassReceiver());

    return std::make_unique<SoftwareOutputDeviceWinOrLinux>(hwnd, std::move(layered_window_updater));
}

} // namespace viz
