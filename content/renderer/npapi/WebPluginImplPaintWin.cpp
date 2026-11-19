// Copyright (C) 2006-2013 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132 (Windowless DIB -> cc::PaintCanvas + Windowed fallback).

#include "content/renderer/npapi/WebPluginImpl.h"

#include <algorithm>
#include <cstring>
#include <vector>

#include "base/functional/bind.h"
#include "base/task/single_thread_task_runner.h"
#include "base/time/time.h"
#include "cc/paint/paint_canvas.h"
#include "cc/paint/paint_image.h"
#include "cc/paint/paint_image_builder.h"
#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "content/renderer/npapi/PluginMessageThrottlerWin.h"
#include "third_party/blink/public/web/web_plugin_container.h"
#include "third_party/skia/include/core/SkImage.h"
#include "third_party/skia/include/core/SkImageInfo.h"
#include "third_party/skia/include/core/SkPixmap.h"

namespace content {

namespace {

#if defined(_WIN32)
const LPCWSTR kWebPluginViewClassName = L"MbWebPluginView";
const LPCWSTR kWebPluginViewProperty = L"MbWebPluginViewProperty";

using PtrBeginPaint = HDC(WINAPI*)(HWND, PAINTSTRUCT*);
using PtrEndPaint = BOOL(WINAPI*)(HWND, const PAINTSTRUCT*);
using PtrIsDebuggerPresent = BOOL(WINAPI*)();

PtrBeginPaint s_origBeginPaint = &::BeginPaint;
PtrEndPaint s_origEndPaint = &::EndPaint;
PtrIsDebuggerPresent s_origIsDebuggerPresent = nullptr;

BOOL WINAPI hookedIsDebuggerPresent()
{
    return FALSE;
}

BOOL hookByHotpatch(LPCWSTR dllName, LPCSTR funcName, void* newFunc, void** oldFunc)
{
#if defined(_M_IX86)
    HMODULE mod = ::LoadLibraryW(dllName);
    if (!mod)
        return FALSE;
    auto* pByte = reinterpret_cast<BYTE*>(::GetProcAddress(mod, funcName));
    if (!pByte || pByte[0] != 0x8B || pByte[1] != 0xFF)
        return FALSE;

    DWORD oldProtect = 0;
    if (!::VirtualProtect(pByte - 5, 7, PAGE_EXECUTE_READWRITE, &oldProtect))
        return FALSE;

    if (oldFunc)
        *oldFunc = pByte + 2;

    DWORD relOffset = static_cast<DWORD>(reinterpret_cast<uintptr_t>(newFunc) - reinterpret_cast<uintptr_t>(pByte));
    BYTE jmpLong[5] = { 0xE9, 0, 0, 0, 0 };
    memcpy(&jmpLong[1], &relOffset, 4);
    memcpy(pByte - 5, jmpLong, 5);

    BYTE jmpShort[2] = { 0xEB, 0xF9 };
    memcpy(pByte, jmpShort, 2);

    ::VirtualProtect(pByte - 5, 7, oldProtect, &oldProtect);
    return TRUE;
#else
    (void)dllName;
    (void)funcName;
    (void)newFunc;
    (void)oldFunc;
    return FALSE;
#endif
}

void setUpOffscreenPaintingHooks(PtrBeginPaint beginPaintHook, PtrEndPaint endPaintHook)
{
    static bool s_haveHooked = false;
    if (s_haveHooked)
        return;
    s_haveHooked = true;

    hookByHotpatch(L"user32.dll", "BeginPaint", reinterpret_cast<void*>(beginPaintHook), reinterpret_cast<void**>(&s_origBeginPaint));
    hookByHotpatch(L"user32.dll", "EndPaint", reinterpret_cast<void*>(endPaintHook), reinterpret_cast<void**>(&s_origEndPaint));
    hookByHotpatch(L"kernel32.dll", "IsDebuggerPresent", reinterpret_cast<void*>(&hookedIsDebuggerPresent), reinterpret_cast<void**>(&s_origIsDebuggerPresent));
}

bool registerPluginViewWindowClass()
{
    static bool s_registered = false;
    if (s_registered)
        return true;
    s_registered = true;

    WNDCLASSEXW wcex {};
    wcex.cbSize = sizeof(WNDCLASSEXW);
    wcex.style = CS_DBLCLKS;
    wcex.lpfnWndProc = ::DefWindowProcW;
    wcex.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
    wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
    wcex.lpszClassName = kWebPluginViewClassName;
    return !!::RegisterClassExW(&wcex);
}

LRESULT CALLBACK destroyNullWndProc(HWND, UINT, WPARAM, LPARAM)
{
    return 0;
}

void destroyPluginWindowAsync(intptr_t widgetAddr)
{
    HWND widget = reinterpret_cast<HWND>(widgetAddr);
    if (!widget || !::IsWindow(widget))
        return;
    if (::IsWindowUnicode(widget))
        ::SetWindowLongPtrW(widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&destroyNullWndProc));
    else
        ::SetWindowLongPtrA(widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&destroyNullWndProc));
    ::DestroyWindow(widget);
}
#endif // defined(_WIN32)

bool isWindowsMessageUserGesture(UINT message)
{
#if defined(_WIN32)
    return message == WM_LBUTTONUP || message == WM_MBUTTONUP || message == WM_RBUTTONUP || message == WM_KEYUP;
#else
    return false;
#endif
}

void forceOpaqueAlphaChannel(void* pixels, size_t byteLength)
{
    if (!pixels || (byteLength % 4) != 0)
        return;
    auto* ptr = static_cast<uint32_t*>(pixels);
    size_t count = byteLength / 4;
    for (size_t i = 0; i < count; ++i)
        ptr[i] |= 0xFF000000u;
}

} // namespace

HDC WINAPI WebPluginImpl::hookedBeginPaint(HWND hWnd, PAINTSTRUCT* lpPaint)
{
#if defined(_WIN32)
    auto* view = reinterpret_cast<WebPluginImpl*>(::GetPropW(hWnd, kWebPluginViewProperty));
    if (view && view->m_wmPrintHDC) {
        memset(lpPaint, 0, sizeof(PAINTSTRUCT));
        lpPaint->hdc = view->m_wmPrintHDC;
        ::GetClientRect(hWnd, &lpPaint->rcPaint);
        return view->m_wmPrintHDC;
    }
    if (s_origBeginPaint)
        return s_origBeginPaint(hWnd, lpPaint);
#endif
    return nullptr;
}

BOOL WINAPI WebPluginImpl::hookedEndPaint(HWND hWnd, const PAINTSTRUCT* lpPaint)
{
#if defined(_WIN32)
    auto* view = reinterpret_cast<WebPluginImpl*>(::GetPropW(hWnd, kWebPluginViewProperty));
    if (view && view->m_wmPrintHDC)
        return TRUE;
    if (s_origEndPaint)
        return s_origEndPaint(hWnd, lpPaint);
#endif
    return TRUE;
}

LRESULT CALLBACK WebPluginImpl::PluginViewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
#if defined(_WIN32)
    auto* view = reinterpret_cast<WebPluginImpl*>(::GetPropW(hWnd, kWebPluginViewProperty));
    if (!view)
        return ::DefWindowProcW(hWnd, message, wParam, lParam);
    scoped_refptr<WebPluginImpl> protect(view);
    ++view->m_pluginViewWndProcReentryCount;
    if (view->m_pluginViewWndProcReentryCount > 10) {
        --view->m_pluginViewWndProcReentryCount;
        return 0;
    }
    LRESULT ret = view->wndProc(hWnd, message, wParam, lParam);
    --view->m_pluginViewWndProcReentryCount;
    return ret;
#else
    return 0;
#endif
}

LRESULT WebPluginImpl::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
#if defined(_WIN32)
    switch (message) {
    case WM_LBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        ::SetCapture(hWnd);
        break;
    case WM_LBUTTONUP:
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
        ::ReleaseCapture();
        break;
    }

    if (message == m_lastMessage
        && m_plugin && m_plugin->quirks().contains(PluginQuirkDontCallWndProcForSameMessageRecursively)
        && m_isCallingPluginWndProc) {
        return 1;
    }

    if (message == WM_USER + 1 && m_plugin && m_plugin->quirks().contains(PluginQuirkThrottleWMUserPlusOneMessages)) {
        if (!m_messageThrottler)
            m_messageThrottler = std::make_unique<PluginMessageThrottlerWin>(this);
        m_messageThrottler->appendMessage(hWnd, message, wParam, lParam);
        return 0;
    }

    UINT prevLastMessage = m_lastMessage;
    bool prevCallingWndProc = m_isCallingPluginWndProc;
    HDC prevWmPrintHDC = m_wmPrintHDC;

    m_lastMessage = message;
    m_isCallingPluginWndProc = true;

    if (m_plugin && m_plugin->pluginFuncs()->version < NPVERS_HAS_POPUPS_ENABLED_STATE
        && isWindowsMessageUserGesture(message) && !m_popPopupsStateTimer.IsRunning()) {
        pushPopupsEnabledState(true);
        m_popPopupsStateTimer.Start(FROM_HERE, base::TimeDelta(),
            base::BindOnce(&WebPluginImpl::popPopupsStateTimerFired, base::Unretained(this)));
    }

    if (message == WM_PRINTCLIENT) {
        message = WM_PAINT;
        m_wmPrintHDC = reinterpret_cast<HDC>(wParam);
    }

    LRESULT result = m_pluginWndProc ? ::CallWindowProcW(m_pluginWndProc, hWnd, message, wParam, lParam) : 0;
    m_wmPrintHDC = prevWmPrintHDC;
    m_isCallingPluginWndProc = prevCallingWndProc;
    m_lastMessage = prevLastMessage;
    return result;
#else
    return 0;
#endif
}

void WebPluginImpl::ensureBackingDib(int width, int height)
{
    if (width <= 0 || height <= 0)
        return;
    if (m_memoryBitmap && m_memoryCanvasSize.cx == width && m_memoryCanvasSize.cy == height)
        return;

    releaseBackingDib();

#if defined(_WIN32)
    m_memoryDC = ::CreateCompatibleDC(nullptr);
    if (!m_memoryDC)
        return;

    ::SetGraphicsMode(m_memoryDC, GM_ADVANCED);

    BITMAPINFO bmi {};
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height; // Top-down BGRA DIB matching Skia N32 layout
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    m_memoryBitmap = ::CreateDIBSection(m_memoryDC, &bmi, DIB_RGB_COLORS, &m_memoryPixels, nullptr, 0);
    if (!m_memoryBitmap || !m_memoryPixels) {
        releaseBackingDib();
        return;
    }

    m_oldBitmap = ::SelectObject(m_memoryDC, m_memoryBitmap);
    m_memoryCanvasSize.cx = width;
    m_memoryCanvasSize.cy = height;
#endif
}

void WebPluginImpl::releaseBackingDib()
{
#if defined(_WIN32)
    if (m_memoryDC && m_oldBitmap) {
        ::SelectObject(m_memoryDC, m_oldBitmap);
        m_oldBitmap = nullptr;
    }
    if (m_memoryBitmap) {
        ::DeleteObject(m_memoryBitmap);
        m_memoryBitmap = nullptr;
    }
    if (m_memoryDC) {
        ::DeleteDC(m_memoryDC);
        m_memoryDC = nullptr;
    }
#endif
    m_memoryPixels = nullptr;
    m_memoryCanvasSize = { 0, 0 };
    m_lastPaintHDC = nullptr;
}

void WebPluginImpl::setRgnIfNeeded(const gfx::Rect& windowRect, const gfx::Rect& oldWindowRect, const gfx::Rect& oldClipRect)
{
    if (!m_plugin)
        return;

    if (m_mbwebviewId) {
        if (auto* webview = static_cast<MbWebView*>(common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId))) {
            POINT latestOffset = webview->getOffset();
            m_widgetOffset.SetPoint(latestOffset.x, latestOffset.y);
            if (!m_parentWidget)
                m_parentWidget = webview->getHostWnd();
        }
    }

    if (m_haveUpdatedPluginWidget && m_windowRect == oldWindowRect && m_clipRect == oldClipRect)
        return;

    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);
    setCallingPlugin(true);
#if defined(_WIN32)
    if (m_widget) {
        bool clipToZeroRect = !m_plugin->quirks().contains(PluginQuirkDontClipToZeroRectWhenScrolling);
        if (clipToZeroRect) {
            HRGN zeroRgn = ::CreateRectRgn(0, 0, 0, 0);
            ::SetWindowRgn(m_widget, zeroRgn, FALSE);
        } else {
            HRGN clipRgn = ::CreateRectRgn(m_clipRect.x(), m_clipRect.y(), m_clipRect.right(), m_clipRect.bottom());
            ::SetWindowRgn(m_widget, clipRgn, TRUE);
        }

        if (!m_haveUpdatedPluginWidget || m_windowRect != oldWindowRect) {
            ::MoveWindow(m_widget, m_windowRect.x() + m_widgetOffset.x(), m_windowRect.y() + m_widgetOffset.y(),
                m_windowRect.width(), m_windowRect.height(), TRUE);
        }

        if (clipToZeroRect) {
            HRGN clipRgn = ::CreateRectRgn(m_clipRect.x(), m_clipRect.y(), m_clipRect.right(), m_clipRect.bottom());
            ::SetWindowRgn(m_widget, clipRgn, TRUE);
        }
    }
#endif
    setNPWindowRect(windowRect);
    setCallingPlugin(false);
    m_haveUpdatedPluginWidget = true;
}

void WebPluginImpl::updatePluginWidget(const gfx::Rect& windowRect, const gfx::Rect& clipRect, bool isVisible)
{
    gfx::Rect oldWindowRect = m_windowRect;
    gfx::Rect oldClipRect = m_clipRect;
    m_windowRect = windowRect;
    m_clipRect = clipRect;
    m_isVisible = isVisible;

    setRgnIfNeeded(windowRect, oldWindowRect, oldClipRect);

#if defined(_WIN32)
    if (m_widget)
        ::ShowWindow(m_widget, isVisible ? SW_SHOWNA : SW_HIDE);
#endif

    if (!m_isWindowed && m_windowRect.width() > 0 && m_windowRect.height() > 0)
        ensureBackingDib(m_windowRect.width(), m_windowRect.height());
}

void WebPluginImpl::UpdateGeometry(
    const gfx::Rect& windowRect, const gfx::Rect& clipRect, const gfx::Rect& /*unobscuredRect*/, bool isVisible)
{
    updatePluginWidget(windowRect, clipRect, isVisible);
}

void WebPluginImpl::visibilityTimerFired()
{
#if defined(_WIN32)
    if (m_widget)
        ::ShowWindow(m_widget, m_isVisible ? SW_SHOWNA : SW_HIDE);
#endif
}

void WebPluginImpl::UpdateVisibility(bool isVisible)
{
    m_isVisible = isVisible;
    if (!m_visibilityTimer.IsRunning()) {
        m_visibilityTimer.Start(FROM_HERE, base::TimeDelta(),
            base::BindOnce(&WebPluginImpl::visibilityTimerFired, base::Unretained(this)));
    }
}

bool WebPluginImpl::dispatchNPEvent(NPEvent& npEvent)
{
#if defined(_WIN32)
    if (!m_plugin || !m_plugin->pluginFuncs()->event || !m_instance)
        return true;

    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);

    bool shouldPop = false;
    if (m_plugin->pluginFuncs()->version < NPVERS_HAS_POPUPS_ENABLED_STATE && isWindowsMessageUserGesture(npEvent.event)) {
        pushPopupsEnabledState(true);
        shouldPop = true;
    }

    setCallingPlugin(true);
    bool accepted = (m_plugin->pluginFuncs()->event(m_instance, &npEvent) != 0);
    setCallingPlugin(false);

    if (shouldPop)
        popPopupsEnabledState();

    return accepted;
#else
    return false;
#endif
}

void WebPluginImpl::setNPWindowRect(const gfx::Rect& rect)
{
    if (!m_isStarted || !m_plugin || !m_instance)
        return;

    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);

    int w = std::max(0, rect.width());
    int h = std::max(0, rect.height());

    if (!m_isWindowed) {
        // Windowless backing DIB always starts at local (0, 0). Keeping m_npWindow and
        // WM_WINDOWPOSCHANGED at (0, 0) avoids port/clipRect mismatch and negative-coord underflow.
        m_npWindow.x = 0;
        m_npWindow.y = 0;
        m_npWindow.width = static_cast<uint32_t>(w);
        m_npWindow.height = static_cast<uint32_t>(h);
        m_npWindow.clipRect.left = 0;
        m_npWindow.clipRect.top = 0;
        m_npWindow.clipRect.right = static_cast<uint16_t>(std::min(w, 0xFFFF));
        m_npWindow.clipRect.bottom = static_cast<uint16_t>(std::min(h, 0xFFFF));
    } else {
        m_npWindow.x = rect.x();
        m_npWindow.y = rect.y();
        m_npWindow.width = static_cast<uint32_t>(w);
        m_npWindow.height = static_cast<uint32_t>(h);
        m_npWindow.clipRect.left = static_cast<uint16_t>(std::clamp(m_clipRect.x(), 0, 0xFFFF));
        m_npWindow.clipRect.top = static_cast<uint16_t>(std::clamp(m_clipRect.y(), 0, 0xFFFF));
        m_npWindow.clipRect.right = static_cast<uint16_t>(std::clamp(m_clipRect.right(), 0, 0xFFFF));
        m_npWindow.clipRect.bottom = static_cast<uint16_t>(std::clamp(m_clipRect.bottom(), 0, 0xFFFF));
    }

    if (m_plugin->pluginFuncs()->setwindow) {
        if (m_haveCalledSetWindow && m_plugin->quirks().contains(PluginQuirkDontCallSetWindowMoreThanOnce))
            return;

        setCallingPlugin(true);
        bool needSetWindow = (m_npWindow.width != 1 || m_npWindow.height != 1)
            || (m_plugin->name().Utf8().find("GZBank") == std::string::npos);
        if (needSetWindow) {
            m_plugin->pluginFuncs()->setwindow(m_instance, &m_npWindow);
            m_lastSetWindowSize = gfx::Size(w, h);
        }
        setCallingPlugin(false);
        m_haveCalledSetWindow = true;

#if defined(_WIN32)
        if (m_isWindowed && m_widget) {
            WNDPROC currentWndProc = reinterpret_cast<WNDPROC>(::GetWindowLongPtrW(m_widget, GWLP_WNDPROC));
            if (needSetWindow && currentWndProc != PluginViewWndProc) {
                m_pluginWndProc = reinterpret_cast<WNDPROC>(
                    ::SetWindowLongPtrW(m_widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(PluginViewWndProc)));
            }
        }
#endif
    }
}

void WebPluginImpl::paintIntoTransformedContext(HDC hdc)
{
#if defined(_WIN32)
    if (m_isWindowed || !hdc || !m_isStarted)
        return;

    m_npWindow.type = NPWindowTypeDrawable;
    m_npWindow.window = hdc;

    int w = m_memoryCanvasSize.cx > 0 ? m_memoryCanvasSize.cx : (m_windowRect.width() > 0 ? m_windowRect.width() : 1);
    int h = m_memoryCanvasSize.cy > 0 ? m_memoryCanvasSize.cy : (m_windowRect.height() > 0 ? m_windowRect.height() : 1);
    gfx::Size targetSize(w, h);

    if (!m_haveCalledSetWindow || m_lastPaintHDC != hdc || m_lastSetWindowSize != targetSize) {
        WINDOWPOS windowpos {};
        windowpos.x = 0;
        windowpos.y = 0;
        windowpos.cx = w;
        windowpos.cy = h;

        NPEvent posEvent {};
        posEvent.event = WM_WINDOWPOSCHANGED;
        posEvent.lParam = reinterpret_cast<uintptr_t>(&windowpos);
        posEvent.wParam = 0;
        dispatchNPEvent(posEvent);

        if (!m_isStarted)
            return;
        setNPWindowRect(gfx::Rect(0, 0, w, h));
        m_lastPaintHDC = hdc;
    }

    if (!m_isStarted)
        return;

    NPEvent paintEvent {};
    paintEvent.event = WM_PAINT;
    paintEvent.wParam = reinterpret_cast<uintptr_t>(hdc);
    paintEvent.lParam = 0;
    dispatchNPEvent(paintEvent);
#endif
}

void WebPluginImpl::Paint(cc::PaintCanvas* canvas, const gfx::Rect& rect)
{
    if (!m_isStarted || !canvas || !m_pluginContainer)
        return;

    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);

    if (!m_haveCalledSetWindow) {
        gfx::Rect initRect = m_windowRect.IsEmpty() ? rect : m_windowRect;
        setNPWindowRect(initRect);
        if (!m_isStarted)
            return;
    }

    if (m_isWindowed)
        return;

    int width = m_windowRect.width() > 0 ? m_windowRect.width() : rect.width();
    int height = m_windowRect.height() > 0 ? m_windowRect.height() : rect.height();
    if (width <= 0 || height <= 0)
        return;

    ensureBackingDib(width, height);
    if (!m_memoryDC || !m_memoryPixels)
        return;

    size_t byteSize = static_cast<size_t>(width) * static_cast<size_t>(height) * 4;
    if (m_isTransparent) {
        memset(m_memoryPixels, 0, byteSize);
    } else {
        memset(m_memoryPixels, 0xFF, byteSize);
    }

#if defined(_WIN32)
    paintIntoTransformedContext(m_memoryDC);
    if (!m_isStarted || !m_memoryPixels || !m_pluginContainer)
        return;

    if (m_isTransparent) {
        auto* pixels = static_cast<uint32_t*>(m_memoryPixels);
        size_t pixelCount = static_cast<size_t>(width) * static_cast<size_t>(height);
        bool hasNonZeroAlpha = false;
        for (size_t i = 0; i < pixelCount; ++i) {
            if (pixels[i] & 0xFF000000u) {
                hasNonZeroAlpha = true;
                break;
            }
        }
        // Standard Win32 GDI calls leave the alpha byte 0 in 32-bit DIBs.
        // Recover true premultiplied alpha via a second pass on a white backdrop.
        if (!hasNonZeroAlpha) {
            std::vector<uint32_t> blackPixels(pixels, pixels + pixelCount);
            memset(m_memoryPixels, 0xFF, byteSize);
            paintIntoTransformedContext(m_memoryDC);
            if (!m_isStarted || !m_memoryPixels || !m_pluginContainer)
                return;
            pixels = static_cast<uint32_t*>(m_memoryPixels);
            for (size_t i = 0; i < pixelCount; ++i) {
                uint32_t bPx = blackPixels[i];
                uint32_t wPx = pixels[i];
                int bB = static_cast<int>(bPx & 0xFFu);
                int bG = static_cast<int>((bPx >> 8) & 0xFFu);
                int bR = static_cast<int>((bPx >> 16) & 0xFFu);
                int wB = static_cast<int>(wPx & 0xFFu);
                int wG = static_cast<int>((wPx >> 8) & 0xFFu);
                int wR = static_cast<int>((wPx >> 16) & 0xFFu);
                int aB = std::clamp(255 - (wB - bB), 0, 255);
                int aG = std::clamp(255 - (wG - bG), 0, 255);
                int aR = std::clamp(255 - (wR - bR), 0, 255);
                int a = (aR + aG + aB + 1) / 3;
                int outR = std::min(bR, a);
                int outG = std::min(bG, a);
                int outB = std::min(bB, a);
                pixels[i] = (static_cast<uint32_t>(a) << 24)
                    | (static_cast<uint32_t>(outR) << 16)
                    | (static_cast<uint32_t>(outG) << 8)
                    | static_cast<uint32_t>(outB);
            }
        }
    } else {
        forceOpaqueAlphaChannel(m_memoryPixels, byteSize);
    }
#else
    if (!m_isTransparent)
        forceOpaqueAlphaChannel(m_memoryPixels, byteSize);
#endif

    SkImageInfo imgInfo = SkImageInfo::MakeN32Premul(width, height);
    SkPixmap pixmap(imgInfo, m_memoryPixels, static_cast<size_t>(width) * 4);
    sk_sp<SkImage> skImage = SkImages::RasterFromPixmapCopy(pixmap);
    if (!skImage)
        return;

    cc::PaintImage paintImage = cc::PaintImageBuilder::WithDefault()
        .set_id(cc::PaintImage::GetNextId())
        .set_image(std::move(skImage), cc::PaintImage::GetNextContentId())
        .TakePaintImage();

    gfx::Point rootOrigin = m_pluginContainer->LocalToRootFramePoint(gfx::Point(0, 0));
    canvas->drawImage(paintImage, static_cast<SkScalar>(rootOrigin.x()), static_cast<SkScalar>(rootOrigin.y()));
}

bool WebPluginImpl::platformGetValueStatic(NPNVariable, void*, NPError*)
{
    return false;
}

bool WebPluginImpl::platformGetValue(NPNVariable variable, void* value, NPError* result)
{
    switch (variable) {
    case NPNVnetscapeWindow: {
        if (!m_widget && !m_parentWidget && m_mbwebviewId) {
            if (auto* webview = static_cast<MbWebView*>(common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId)))
                m_parentWidget = webview->getHostWnd();
        }
        *reinterpret_cast<HWND*>(value) = m_widget ? m_widget : m_parentWidget;
        *result = NPERR_NO_ERROR;
        return true;
    }
    case NPNVSupportsWindowless:
        *reinterpret_cast<NPBool*>(value) = TRUE;
        *result = NPERR_NO_ERROR;
        return true;
    default:
        return false;
    }
}

void WebPluginImpl::invalidateRect(const gfx::Rect& rect)
{
#if defined(_WIN32)
    if (m_isWindowed) {
        if (m_widget) {
            RECT invalidRect { rect.x(), rect.y(), rect.right(), rect.bottom() };
            ::InvalidateRect(m_widget, &invalidRect, FALSE);
        }
        return;
    }
#endif
    if (m_pluginContainer) {
        m_pluginContainer->Invalidate();
        m_pluginContainer->ScheduleAnimation();
    }
}

void WebPluginImpl::invalidateTimerFired()
{
    if (!m_invalidRects.empty()) {
        m_invalidRects.clear();
        if (m_pluginContainer) {
            m_pluginContainer->Invalidate();
            m_pluginContainer->ScheduleAnimation();
        }
    }
}

void WebPluginImpl::invalidateRect(NPRect* rect)
{
    if (!m_pluginContainer)
        return;

    if (!rect) {
        invalidateRect(gfx::Rect(0, 0, m_windowRect.width(), m_windowRect.height()));
        return;
    }

    gfx::Rect r(rect->left, rect->top, rect->right - rect->left, rect->bottom - rect->top);
    if (m_isWindowed) {
        invalidateRect(r);
    } else if (m_plugin && m_plugin->quirks().contains(PluginQuirkThrottleInvalidate)) {
        m_invalidRects.push_back(r);
        if (!m_invalidateTimer.IsRunning()) {
            m_invalidateTimer.Start(FROM_HERE, base::Milliseconds(1),
                base::BindOnce(&WebPluginImpl::invalidateTimerFired, base::Unretained(this)));
        }
    } else {
        invalidateRect(r);
    }
}

void WebPluginImpl::invalidateRegion(NPRegion region)
{
    if (m_isWindowed || !m_pluginContainer)
        return;
#if defined(_WIN32)
    RECT r {};
    if (region && ::GetRgnBox(static_cast<HRGN>(region), &r) != 0) {
        invalidateRect(gfx::Rect(r.left, r.top, r.right - r.left, r.bottom - r.top));
        return;
    }
#endif
    invalidateRect(gfx::Rect(0, 0, m_windowRect.width(), m_windowRect.height()));
}

void WebPluginImpl::forceRedraw()
{
#if defined(_WIN32)
    if (m_isWindowed && m_widget) {
        ::UpdateWindow(m_widget);
        return;
    }
#endif
    if (m_pluginContainer) {
        m_pluginContainer->Invalidate();
        m_pluginContainer->ScheduleAnimation();
    }
}

bool WebPluginImpl::platformStart()
{
    if (!m_pluginContainer)
        return false;

#if defined(_WIN32)
    if (m_isWindowed) {
        registerPluginViewWindowClass();
        setUpOffscreenPaintingHooks(&WebPluginImpl::hookedBeginPaint, &WebPluginImpl::hookedEndPaint);

        DWORD flags = WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
        if (m_isVisible)
            flags |= WS_VISIBLE;

        m_widget = ::CreateWindowExW(0, kWebPluginViewClassName, nullptr, flags, 0, 0, 0, 0, m_parentWidget, nullptr, nullptr, nullptr);
        if (m_widget) {
            ::EnableWindow(m_widget, TRUE);
            ::SetWindowLongPtrW(m_widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(::DefWindowProcW));
            ::SetPropW(m_widget, kWebPluginViewProperty, this);
        }
        m_npWindow.type = NPWindowTypeWindow;
        m_npWindow.window = m_widget;
    } else
#endif
    {
        m_npWindow.type = NPWindowTypeDrawable;
        m_npWindow.window = nullptr;
    }

    gfx::Rect initialRect = m_windowRect.IsEmpty() ? gfx::Rect(0, 0, 1, 1) : m_windowRect;
    gfx::Rect initialClip = m_clipRect.IsEmpty() ? initialRect : m_clipRect;
    updatePluginWidget(initialRect, initialClip, true);
    return true;
}

void WebPluginImpl::platformDestroy()
{
    releaseBackingDib();

#if defined(_WIN32)
    if (m_widget) {
        HWND widget = m_widget;
        m_widget = nullptr;
        ::RemovePropW(widget, kWebPluginViewProperty);
        if (::IsWindowUnicode(widget))
            ::SetWindowLongPtrW(widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&destroyNullWndProc));
        else
            ::SetWindowLongPtrA(widget, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&destroyNullWndProc));
        ::ShowWindow(widget, SW_HIDE);
        base::SingleThreadTaskRunner::GetCurrentDefault()->PostTask(
            FROM_HERE, base::BindOnce(&destroyPluginWindowAsync, reinterpret_cast<intptr_t>(widget)));
    }
#endif
}

} // namespace content
