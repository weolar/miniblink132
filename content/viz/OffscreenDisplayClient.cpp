// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/viz/OffscreenDisplayClient.h"

#include "content/browser/MbWebview.h"
#include "content/common/ThreadCall.h"
#include "content/common/LiveIdDetect.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"

#if BUILDFLAG(IS_APPLE)
#include "ui/accelerated_widget_mac/ca_layer_frame_sink.h"
#endif

#if 1 // BUILDFLAG(IS_WIN)
#include <windows.h>

#include "components/viz/common/display/use_layered_window.h"
#include "components/viz/common/resources/resource_sizes.h"
#include "components/viz/host/layered_window_updater_impl.h"
//#include "ui/base/win/internal_constants.h"
#include "skia/ext/platform_canvas.h"
#include "skia/ext/skia_utils_win.h"
#include "skia/ext/legacy_display_globals.h"
#endif
#include "base/rand_util.h"

#if !BUILDFLAG(IS_WIN)
#include <cairo.h>
#endif

namespace content {

class OffscreenWindowUpdater : public viz::mojom::LayeredWindowUpdater {
public:
    OffscreenWindowUpdater(int64_t mbwebviewId, HWND hwnd, bool isAutoDrawToHwnd, mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver)
        : m_hwnd(hwnd)
        , m_mbwebviewId(mbwebviewId)
        , m_receiver(this, std::move(receiver))
    {
        m_isLayeredWnd = (WS_EX_LAYERED == (WS_EX_LAYERED & GetWindowLongW(m_hwnd, GWL_EXSTYLE)));
        m_isAutoDrawToHwnd = isAutoDrawToHwnd;
    }

    OffscreenWindowUpdater(const OffscreenWindowUpdater&) = delete;
    OffscreenWindowUpdater& operator=(const OffscreenWindowUpdater&) = delete;

    ~OffscreenWindowUpdater() override;

    // mojom::LayeredWindowUpdater implementation.
    void OnAllocatedSharedMemory(const gfx::Size& pixelSize, base::UnsafeSharedMemoryRegion region, void* lock) override;
    void OnAllocatedBitmapMemory(const gfx::Size& pixelSize, void* skcanvas, unsigned char* bitmap, void* lock) override;
    bool HasTransparent();
    uint32_t GetBackgroundColor(bool* has_background_color) override;
    void Draw(const gfx::Rect& damageRect, DrawCallback drawCallback) override;

private:
#if 1 // BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
    gfx::AcceleratedWidget m_hwnd = NULL;
    bool m_isLayeredWnd = false;
#endif
    int64_t m_mbwebviewId;
    mojo::Receiver<viz::mojom::LayeredWindowUpdater> m_receiver;
    SkCanvas* m_canvas = nullptr;
    bool m_isAutoDrawToHwnd = true;

#if BUILDFLAG(IS_LINUX)
    cairo_surface_t* m_surface = nullptr;
    std::unique_ptr<SkCanvas> m_memCanvasForUi;
#endif
    gfx::Size m_pixelSize;
    unsigned char* m_bitmapByte = nullptr;
    base::Lock* m_canvasLock = nullptr;

    bool m_isWebWindowMode = true;
};

OffscreenWindowUpdater::~OffscreenWindowUpdater()
{
#if !defined(OS_WIN)
    if (m_surface)
        cairo_surface_destroy(m_surface);
#endif
}

void runDrawCallback(int64_t mbwebviewId, viz::mojom::LayeredWindowUpdater::DrawCallback drawCallback)
{
    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE,
        base::BindOnce(
            [](int64_t mbwebviewId, viz::mojom::LayeredWindowUpdater::DrawCallback drawCallback) {
                MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(mbwebviewId);
                if (!webview)
                    return;
                std::move(drawCallback).Run();
                common::LiveIdDetect::getMbWebviewIds()->unlock(mbwebviewId, webview);
            },
            mbwebviewId, std::move(drawCallback)));
}

void OffscreenWindowUpdater::OnAllocatedBitmapMemory(const gfx::Size& pixelSize, void* skcanvas, unsigned char* bitmap, void* lock)
{
    m_bitmapByte = bitmap;
    m_pixelSize = pixelSize;
    m_canvasLock = (base::Lock*)lock;
    m_canvas = (SkCanvas*)skcanvas;

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(m_mbwebviewId);
    if (!webview)
        return;

    void* surface = nullptr;
#if !defined(OS_WIN)
    if (m_surface)
        cairo_surface_destroy(m_surface);
    m_surface = LinuxGdiCreateSurfaceByHwnd(m_hwnd, pixelSize.width(), pixelSize.height());
    surface = m_surface;

    unsigned char* byteData = cairo_image_surface_get_data(m_surface);
    m_memCanvasForUi = skia::CreatePlatformCanvasWithPixels(pixelSize.width(), pixelSize.height(), true, byteData, skia::RETURN_NULL_ON_FAILURE);
#else
    surface = skia::GetNativeDrawingContext(m_canvas);
#endif
    webview->onAllocatedBitmapMemory(pixelSize, surface, bitmap, lock);
    common::LiveIdDetect::getMbWebviewIds()->unlock(m_mbwebviewId, webview);
}

bool OffscreenWindowUpdater::HasTransparent()
{
    return m_isLayeredWnd;
}

uint32_t OffscreenWindowUpdater::GetBackgroundColor(bool* has_background_color)
{
    *has_background_color = true;
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(m_mbwebviewId);
    if (!webview)
        return 0xffffffff;
    uint32_t c = webview->getBackgroundColor();
    common::LiveIdDetect::getMbWebviewIds()->unlock(m_mbwebviewId, webview);
    *has_background_color = !m_isLayeredWnd;
    return c;
}

void OffscreenWindowUpdater::OnAllocatedSharedMemory(const gfx::Size& pixelSize, base::UnsafeSharedMemoryRegion region, void* lock)
{
#if defined(WIN32)
//     m_canvas.reset();
//     m_canvasLock = (base::Lock*)lock;
//
//     if (!region.IsValid())
//         return;
//
//     // Make sure |pixelSize| is sane.
//     size_t expectedBytes;
//     bool sizeResult = viz::ResourceSizes::MaybeSizeInBytes(pixelSize, viz::ResourceFormat::RGBA_8888, &expectedBytes);
//     if (!sizeResult)
//         return;
//
//     // The SkCanvas maps shared memory on creation and unmaps on destruction.
//     m_canvas = skia::CreatePlatformCanvasWithSharedSection(pixelSize.width(), pixelSize.height(), true, region.GetPlatformHandle(), skia::RETURN_NULL_ON_FAILURE);
//
//     HDC memoryDC = skia::GetNativeDrawingContext(m_canvas.get());
//     // |region|'s handle will close when it goes out of scope.
//     MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(m_mbwebviewId);
//     if (webview)
//         webview->onAllocatedSharedMemory(pixelSize, memoryDC, lock);
//     common::LiveIdDetect::getMbWebviewIds()->unlock(m_mbwebviewId, webview);
#endif
}

// bool SaveHDCToBitmap(HDC hdc, int width, int height, const char* filename)
// {
//     // 创建一个兼容的内存DC
//     HDC hdcMem = CreateCompatibleDC(hdc);
//     if (!hdcMem)
//         return false;
//
//     // 创建一个兼容的位图
//     HBITMAP hbmMem = CreateCompatibleBitmap(hdc, width, height);
//     if (!hbmMem) {
//         DeleteDC(hdcMem);
//         return false;
//     }
//
//     // 选择位图到内存DC中
//     HGDIOBJ hbmOld = SelectObject(hdcMem, hbmMem);
//
//     // 将HDC的内容复制到内存DC
//     BitBlt(hdcMem, 0, 0, width, height, hdc, 0, 0, SRCCOPY);
//
//     // 获取位图信息
//     BITMAP bm;
//     GetObject(hbmMem, sizeof(BITMAP), &bm);
//
//     BITMAPFILEHEADER bmfHeader;
//     BITMAPINFOHEADER bi;
//
//     bi.biSize = sizeof(BITMAPINFOHEADER);
//     bi.biWidth = bm.bmWidth;
//     bi.biHeight = bm.bmHeight;
//     bi.biPlanes = 1;
//     bi.biBitCount = 32;
//     bi.biCompression = BI_RGB;
//     bi.biSizeImage = 0;
//     bi.biXPelsPerMeter = 0;
//     bi.biYPelsPerMeter = 0;
//     bi.biClrUsed = 0;
//     bi.biClrImportant = 0;
//
//     DWORD dwBmpSize = ((bm.bmWidth * bi.biBitCount + 31) / 32) * 4 * bm.bmHeight;
//
//     char* lpbitmap = new char[dwBmpSize];
//
//     // 获取位图像素数据
//     GetDIBits(hdcMem, hbmMem, 0, (UINT)bm.bmHeight, lpbitmap, (BITMAPINFO*)&bi, DIB_RGB_COLORS);
//
//     // 创建位图文件头
//     bmfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
//     bmfHeader.bfSize = dwBmpSize + bmfHeader.bfOffBits;
//     bmfHeader.bfType = 0x4D42;
//
//     // 创建文件并写入数据
//     HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
//     if (hFile == INVALID_HANDLE_VALUE) {
//         delete[] lpbitmap;
//         SelectObject(hdcMem, hbmOld);
//         DeleteObject(hbmMem);
//         DeleteDC(hdcMem);
//         return false;
//     }
//
//     DWORD dwBytesWritten;
//     WriteFile(hFile, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, nullptr);
//     WriteFile(hFile, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, nullptr);
//     WriteFile(hFile, lpbitmap, dwBmpSize, &dwBytesWritten, nullptr);
//
//     // 关闭文件
//     CloseHandle(hFile);
//
//     // 释放资源
//     delete[] lpbitmap;
//     SelectObject(hdcMem, hbmOld);
//     DeleteObject(hbmMem);
//     DeleteDC(hdcMem);
//
//     return true;
// }

DWORD g_lastOffscreenWindowUpdaterTime = 0;

// 本函数是在合成线程
void OffscreenWindowUpdater::Draw(const gfx::Rect& damageRect, DrawCallback drawCallback)
{
    //     DWORD time = ::GetTickCount();
    //     if (time - g_lastOffscreenWindowUpdaterTime > 400)
    //     {
    //         char* output = (char*)malloc(400);
    //         sprintf_s(output, 399, "OffscreenWindowUpdater::Draw: %d %d, %d\n", damageRect.width(), damageRect.height(), time - g_lastOffscreenWindowUpdaterTime);
    //         OutputDebugStringA(output);
    //         free(output);
    //     }
    //     g_lastOffscreenWindowUpdaterTime = time;

    if (!m_canvas) {
        runDrawCallback(m_mbwebviewId, std::move(drawCallback));
        return;
    }

    if (0 == m_pixelSize.width() * m_pixelSize.height()) {
        runDrawCallback(m_mbwebviewId, std::move(drawCallback));
        return;
    }

#if defined(OS_WIN)
    if (m_isLayeredWnd) { // Set WS_EX_LAYERED extended window style if not already set.
        DWORD style = GetWindowLong(m_hwnd, GWL_EXSTYLE);
        DCHECK(!(style & WS_EX_COMPOSITED));
        if (!(style & WS_EX_LAYERED))
            SetWindowLong(m_hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);
    }

    // Draw to the HWND. If |m_canvas| size doesn't match HWND size then it will be
    // clipped or guttered accordingly.
    HDC memoryDC = skia::GetNativeDrawingContext(m_canvas);

    if (m_isAutoDrawToHwnd && m_isLayeredWnd) {
        RECT wr;
        ::GetWindowRect(m_hwnd, &wr);

        //SIZE size = { wr.right - wr.left, wr.bottom - wr.top };
        SIZE size = { m_pixelSize.width(), m_pixelSize.height() };
        POINT position = { wr.left, wr.top };
        POINT zero = { 0, 0 };
        BLENDFUNCTION blend = { AC_SRC_OVER, 0x00, 0xFF, AC_SRC_ALPHA };
        ::UpdateLayeredWindow(m_hwnd, nullptr, &position, &size, memoryDC, &zero, RGB(0xFF, 0xFF, 0xFF), &blend, ULW_ALPHA);
    } else if (m_isAutoDrawToHwnd && m_hwnd) {
        RECT srcRect = damageRect.ToRECT();
        HDC hdc = ::GetDC(m_hwnd);
        m_canvasLock->Acquire();
        //--
        //         HBRUSH hBrush = ::CreateSolidBrush(RGB(255, 0, 0));
        //         RECT rect = { 100, 100, 3000, 200 };
        //         ::FillRect(memoryDC, &rect, hBrush);
        //         ::DeleteObject(hBrush);

        //         static int count = 0;
        //         char* filename = (char*)malloc(400);
        //         sprintf_s(filename, 399, "W:\\test\\exe_test\\yunci\\bmp\\bmp_%d.bmp", count);
        //         SaveHDCToBitmap(memoryDC, srcRect.right - srcRect.left, srcRect.bottom - srcRect.top, filename);
        //         free(filename);
        //         count++;
        //--
        //         SkPaint skPaint;
        //         skPaint.setColor(SK_ColorBLUE);
        //         skPaint.setStyle(SkPaint::kFill_Style);
        //
        //         SkRect r = SkRect::MakeLTRB(5, 5, 200, 200);
        //         m_canvas->drawRect(r, skPaint);
        //         base::RandBytes(m_bitmapByte, m_pixelSize.width() * m_pixelSize.height() * 4);
        //--
        skia::CopyHDC(memoryDC, hdc, damageRect.x(), damageRect.y(), m_canvas->imageInfo().isOpaque(), srcRect, m_canvas->getTotalMatrix());
        m_canvasLock->Release();
        ::ReleaseDC(m_hwnd, hdc);
    }
#else
    if (!m_isWebWindowMode)
        return;
    m_canvasLock->Acquire();

    if (m_canvas && m_memCanvasForUi.get()) {
        //unsigned char* byteData = cairo_image_surface_get_data(m_surface);
        //memcpy(byteData, m_bitmapByte, 4 * pixelSize.width(), pixelSize.height());
        SkBitmap bitmap;
        SkImageInfo info = SkImageInfo::MakeN32(m_pixelSize.width(), m_pixelSize.height(), m_isLayeredWnd ? kPremul_SkAlphaType : kOpaque_SkAlphaType);

        bitmap.installPixels(info, m_bitmapByte, /*cairo_image_surface_get_stride(m_surface)*/ m_pixelSize.width() * 4, nullptr, nullptr);
        SkRect isrc = SkRect::MakeXYWH(damageRect.x(), damageRect.y(), damageRect.width(), damageRect.height());
        SkRect dst = isrc;

        //---
        //         unsigned __int32* sourceData = (unsigned __int32*)m_bitmapByte;
        //         int stride = cairo_image_surface_get_stride(m_surface) / 4;
        //
        //         for (int y = 0; y < 30; y++) {
        //             for (int x = 0; x < 30; x++) {
        //                 sourceData[y * stride + x] = 0xff1122ff;
        //             }
        //         }
        //+++

        sk_sp<SkImage> image = SkImage::MakeFromBitmap(bitmap);
        m_memCanvasForUi->drawImageRect(image.get(), isrc, dst, SkSamplingOptions(), /*const SkPaint**/ nullptr, SkCanvas::kStrict_SrcRectConstraint);

        //---
        //SkRect rect = SkRect::MakeXYWH(30, 30, 100, 100);
        //SkPaint paint;
        //paint.setColor(SK_ColorRED);
        //m_memCanvasForUi->drawRect(rect, paint);
        //+++

        //         char output[100] = { 0 };
        //         sprintf(output, "OffscreenWindowUpdater.Draw!! %p, %d %d (%d %d %d %d)\n",
        //             m_bitmapByte, m_pixelSize.width(), m_pixelSize.height(), damageRect.x(), damageRect.y(), damageRect.width(), damageRect.height());
        //         OutputDebugStringA(output);
    }

    m_canvasLock->Release();
    RECT rc = { damageRect.x(), damageRect.y(), damageRect.right(), damageRect.bottom() };
    ::InvalidateRect(m_hwnd, &rc, false);
#endif

#if defined(OS_WIN)
    int64_t webviewId = m_mbwebviewId;
    OffscreenWindowUpdater* self = this;
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [webviewId, damageRect, self] {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(webviewId);
        if (!webview)
            return;
        common::LiveIdDetect::getMbWebviewIds()->unlock(webviewId, webview);

        self->m_hwnd = webview->getHostWnd();

        self->m_canvasLock->Acquire();
        HDC memoryDC = skia::GetNativeDrawingContext(self->m_canvas);
        if (webview)
            webview->onPaintUpdatedInUiThread(memoryDC, damageRect.x(), damageRect.y(), damageRect.width(), damageRect.height());
        self->m_canvasLock->Release();
    });
#endif

    runDrawCallback(m_mbwebviewId, std::move(drawCallback));
}

//-----
OffscreenDisplayClient::OffscreenDisplayClient(MbWebView* mbwebview)
{
#if 1 // BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN)
    m_hwnd = mbwebview->getHostWnd();
#endif
    m_mbwebviewId = mbwebview->getId();
    m_isAutoDrawToHwnd = mbwebview->getIsAutoDrawToHwnd();
}

OffscreenDisplayClient::~OffscreenDisplayClient() = default;

mojo::PendingRemote<viz::mojom::DisplayClient> OffscreenDisplayClient::GetBoundRemote(scoped_refptr<base::SingleThreadTaskRunner> task_runner)
{
    return m_receiver.BindNewPipeAndPassRemote(task_runner);
}

#if BUILDFLAG(IS_APPLE)
// void OffscreenDisplayClient::OnDisplayReceivedCALayerParams(const gfx::CALayerParams& ca_layer_params)
// {
//     ui::CALayerFrameSink* ca_layer_frame_sink = ui::CALayerFrameSink::FromAcceleratedWidget(widget_);
//     if (ca_layer_frame_sink)
//         ca_layer_frame_sink->UpdateCALayerTree(ca_layer_params);
//     else
//         DLOG(WARNING) << "Received frame for non-existent widget.";
// }
#endif

#if 1 // BUILDFLAG(IS_WIN)
void OffscreenDisplayClient::CreateLayeredWindowUpdater(mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver)
{
    //     if (!NeedsToUseLayerWindow(m_hwnd)) {
    //         DLOG(ERROR) << "HWND shouldn't be using a layered window";
    //         return;
    //     }

    m_offscreenWindowUpdater = std::make_unique<OffscreenWindowUpdater>(m_mbwebviewId, m_hwnd, m_isAutoDrawToHwnd, std::move(receiver));
}
#endif

void OffscreenDisplayClient::AddChildWindowToBrowser(::gpu::SurfaceHandle child_window)
{
    NOTIMPLEMENTED();
}

// TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
// of lacros-chrome is complete.
#if 0 // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
void OffscreenDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size)
{
    NOTIMPLEMENTED();
}
#endif

} // namespace viz
