#ifndef content_browser_ToolTip_h
#define content_browser_ToolTip_h

//#include "wke/wkeGlobalVar.h"
//#include "third_party/WebKit/Source/platform/Timer.h"
#include "base/timer/timer.h"
#include <xstring>
#include <windows.h>

typedef void (*TipPaintCallback) (HWND hWnd, HDC hdc, const WCHAR* text, size_t textLength);

namespace content {

#define kToolTipClassName L"MbToolTip"

class ToolTip {
public:
    ToolTip(bool isToolsTip, double repeatInterval)
        //: m_delayShowTimer(this, &ToolTip::delayShowTimerFired)
        //, m_delayHideTimer(this, &ToolTip::delayHideTimerFired)
        : m_isToolsTip(isToolsTip)
        , m_delayShowCount(0)
        , m_delayHideCount(0)
        , m_isShow(false)
        , m_hTipWnd(nullptr)
        , m_hFont(nullptr)
        , m_repeatInterval(repeatInterval)
    {
        init();
    }

    void init()
    {
        registerClass();
        m_hTipWnd = CreateWindowExW(WS_EX_TOOLWINDOW, (const WCHAR*)kToolTipClassName, (const WCHAR*)kToolTipClassName,
            WS_POPUP | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 225, 140, HWND_DESKTOP, NULL, nullptr, this);
        ::SetPropW(m_hTipWnd, kToolTipClassName, (HANDLE)this);

        int fontHeight = m_dpi * 18;

        m_hFont = CreateFontW(fontHeight, 0, 0, 0, FW_THIN, FALSE, FALSE, FALSE,
            GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, FIXED_PITCH | FF_MODERN, L"微软雅黑");
    }

    ~ToolTip()
    {
        ::SetPropW(m_hTipWnd, kToolTipClassName, (HANDLE)nullptr);
        ::DeleteObject(m_hFont);
        ::DestroyWindow(m_hTipWnd);
    }

    bool registerClass()
    {
        HDC screen = ::GetDC(nullptr);
        int dpiX = ::GetDeviceCaps(screen, LOGPIXELSX);
        m_dpi = dpiX * 100.0 / 96;
        m_dpi /= 100;
        ::ReleaseDC(0, screen);

        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEXW);
        wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
        wcex.lpfnWndProc = wndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = nullptr;
        wcex.hIcon = nullptr;
        wcex.hCursor = LoadCursorW(0, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = 0;
        wcex.lpszClassName = kToolTipClassName;
        wcex.hIconSm = nullptr;
        return !!RegisterClassExW(&wcex);
    }

    void show(const WCHAR* text, POINT* pos)
    {
        if (!text) {
            if (m_isToolsTip)
                hide();
            return;
        }
        std::u16string textString = (const char16_t*)text;
        if (0 == textString.size()) {
            if (m_isToolsTip) {
                OutputDebugStringA("hTipWnd hide 3\n");
                hide();
            }
            return;
        }

        bool isSameText = textString == m_text;
        if (!isSameText || !m_isToolsTip) {
            m_text = textString;

            HDC hScreenDc = ::GetDC(m_hTipWnd);
            HFONT hOldFont = (HFONT)::SelectObject(hScreenDc, m_hFont);
            ::GetTextExtentPoint32W(hScreenDc, (const WCHAR*)m_text.c_str(), m_text.size(), &m_size);
            ::SelectObject(hScreenDc, hOldFont);
            ::ReleaseDC(m_hTipWnd, hScreenDc);

            if (pos)
                m_pos = *pos;
            else
                ::GetCursorPos(&m_pos);

            resetShowState();
        }
    }

    static LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        PAINTSTRUCT ps;
        HDC hdc = nullptr;
        ToolTip* self = (ToolTip*)GetPropW(hWnd, kToolTipClassName);

        switch (uMsg) {
            case WM_TIMER:
                //self->hide();
                break;

            case WM_PAINT:
                hdc = ::BeginPaint(hWnd, &ps);
                self->onPaint(hWnd, hdc);
                ::EndPaint(hWnd, &ps);
                break;

            case WM_CLOSE:
                break;
        }

        return ::DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }

    void onPaint(HWND hWnd, HDC hdc)
    {
        //         if (wke::g_tipPaintCallback) {
        //             TipPaintCallback fun = (TipPaintCallback)wke::g_tipPaintCallback;
        //             fun(hWnd, hdc, m_text.c_str(), m_text.size());
        //             return;
        //         }

        RECT rc = { 0 };
        ::GetClientRect(hWnd, &rc);

        HPEN hCurrentPen = ::CreatePen(PS_SOLID, 1, RGB(126, 126, 126));
        HGDIOBJ hOldPen = SelectObject(hdc, hCurrentPen);
        ::Rectangle(hdc, 0, 0, rc.right - rc.left, rc.bottom - rc.top);
        ::SelectObject(hdc, hOldPen);
        ::DeleteObject(hCurrentPen);

        ::SelectObject(hdc, m_hFont);
        ::SetTextColor(hdc, RGB(86, 86, 86));
        ::SetBkColor(hdc, RGB(255, 255, 255));
        ::TextOutW(hdc, 4, 2, (const WCHAR*)m_text.c_str(), m_text.size());
    }

    std::u16string getText() const { return m_text; }

private:
    void resetShowState()
    {
        m_delayShowTimer.Stop();
        m_delayShowCount = 0;
        m_delayShowTimer.Start(FROM_HERE, base::Seconds(0.4), base::BindRepeating(&ToolTip::delayShowTimerFired, m_weakPtrFactory.GetWeakPtr()));
    }

    bool isNearPos(const POINT& a, const POINT& b)
    {
        return std::abs((int)(a.x - b.x)) + std::abs((int)(a.y - b.y)) < 15;
    }

    void delayShowTimerFired(/*blink::TimerBase**/)
    {
        // 把间隔改成m_repeatInterval。因为start的间隔是另外个数字
        m_delayShowTimer.Stop();
        m_delayShowTimer.Start(FROM_HERE, base::Seconds(m_repeatInterval),
            base::BindRepeating(&ToolTip::delayShowTimerFired, m_weakPtrFactory.GetWeakPtr()));

        ++m_delayShowCount;

        POINT point;
        ::GetCursorPos(&point);
        if (!isNearPos(point, m_pos) && m_isToolsTip) {
            OutputDebugStringA("hTipWnd hide 1\n");
            return hide();
        }

        if (!m_isToolsTip)
            point = m_pos;

        if (!m_isShow) {
            m_isShow = true;

            ::SetWindowPos(m_hTipWnd, HWND_TOPMOST, point.x + 15, point.y + 15, m_size.cx + 7, m_size.cy + 5, SWP_NOACTIVATE);
            ::ShowWindow(m_hTipWnd, SW_SHOWNOACTIVATE);

            if (m_isFirstSetForegroundWindow == false)
                ::SetForegroundWindow(m_hTipWnd);
            m_isFirstSetForegroundWindow = true;
            ::UpdateWindow(m_hTipWnd);

            OutputDebugStringA("hTipWnd show\n");
        }

        if (!m_isToolsTip && 3 < m_delayShowCount * m_repeatInterval) {
            OutputDebugStringA("hTipWnd hide 2\n");
            hide();
        }
    }

    void delayHideTimerFired(/*blink::TimerBase**/)
    {
        ++m_delayHideCount;

        POINT point;
        ::GetCursorPos(&point);
        if (!isNearPos(point, m_pos) || 30 < m_delayHideCount)
            return hide();
    }

    void hide()
    {
        m_text.clear();
        m_isShow = false;
        ::ShowWindow(m_hTipWnd, SW_HIDE);

        m_delayShowTimer.Stop();
        m_delayShowCount = 0;

        m_delayHideTimer.Stop();
        m_delayHideCount = 0;
    }

    HWND m_hTipWnd;
    HFONT m_hFont;
    bool m_isShow;
    std::u16string m_text;

    base::RepeatingTimer m_delayShowTimer;
    int m_delayShowCount;
    base::RepeatingTimer m_delayHideTimer;
    int m_delayHideCount;
    POINT m_pos;
    SIZE m_size;
    bool m_isToolsTip;
    double m_repeatInterval;
    bool m_isFirstSetForegroundWindow = false; // 只调用一次SetForegroundWindow，不然不知道为啥会弹不出窗口到最上层

    base::WeakPtrFactory<ToolTip> m_weakPtrFactory{ this };
    static double m_dpi;
};

double ToolTip::m_dpi = 1;

}

#endif // content_browser_ToolTip_h