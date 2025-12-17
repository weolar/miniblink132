#ifndef content_ui_ContextMeun_h
#define content_ui_ContextMeun_h

#include "content/browser/MbWebview.h"
#include "content/common/ThreadCall.h"
#include "third_party/blink/renderer/core/exported/web_view_impl.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/common/context_menu_data/untrustworthy_context_menu_params.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include "base/strings/string_util.h"
#include <windows.h>

extern bool g_isElectronMode;

#if defined(OS_WIN)

namespace content {

uint32_t g_contextMenuItemMask = kMbMenuSelectedAllId | kMbMenuSelectedTextId | kMbMenuUndoId | kMbMenuCopyImageId | kMbMenuSaveImageId |
kMbMenuInspectElementAtId | kMbMenuCutId | kMbMenuPasteId;

#define kContextMenuClassName L"_ContextMenu_"
//extern WebPageImpl* g_saveImageingWebPage;

// 本类是个单例，所有webview共用一个菜单
class ContextMenu {
public:
    ContextMenu()
    {
        m_popMenu = nullptr;
        m_hWnd = nullptr;
        m_webview = nullptr;
        m_isDestroyed = 0;

        ContextMenu* self = this;
        asyncCallUiThread([self] { self->initImpl(); });
    }

    static ContextMenu* get()
    {
        if (!m_inst)
            m_inst = new ContextMenu();
        return m_inst;
    }

    void setCurrentWebview(MbWebView* webview)
    {
        m_webview = webview;
    }

    MbWebView* getCurrentWebview() const
    {
        return m_webview;
    }

    void initImpl()
    {
        if (m_hWnd)
            return;

        registerClass();
        m_hWnd = CreateWindowExW(WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE, kContextMenuClassName, kContextMenuClassName, WS_POPUP, 0, 0, 1, 1, HWND_DESKTOP, NULL, nullptr, this);
        ::ShowWindow(m_hWnd, SW_HIDE);
        ::SetPropW(m_hWnd, kContextMenuClassName, (HANDLE)this);
        ::SetForegroundWindow(m_hWnd);
    }

    ~ContextMenu()
    {
        m_mutex.lock();
        _InterlockedIncrement(&m_isDestroyed);

        HWND hWnd = m_hWnd;
        HMENU popMenu = m_popMenu;
        asyncCallUiThread([hWnd, popMenu] {
            ::SetPropW(hWnd, kContextMenuClassName, (HANDLE) nullptr);
            ::DestroyWindow(hWnd);

            if (popMenu)
                ::DestroyMenu(popMenu);
        });
        m_mutex.unlock();
    }

    bool registerClass()
    {
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
        wcex.lpszClassName = kContextMenuClassName;
        wcex.hIconSm = nullptr;
        return !!RegisterClassExW(&wcex);
    }

    enum MenuId {
        kSelectedAllId = 1 << 1,
        kSelectedTextId = 1 << 2,
        kUndoId = 1 << 3,
        kCopyImageId = 1 << 4,
        kInspectElementAtId = 1 << 5,
        kCutId = 1 << 6,
        kPasteId = 1 << 7,
        kPrintId = 1 << 8,
        kGoForwardId = 1 << 9,
        kGoBackId = 1 << 10,
        kReloadId = 1 << 11,
        kSaveImageId = 1 << 12,
        //////////////////////////////////////////////////////////////////////////
        kElectronDeclareId = 1 << 30,
    };

    void asyncCallUiThread(std::function<void()>&& func)
    {
        ThreadCall::callUiThreadAsync(MB_FROM_HERE, std::move(func));
    }

    class UiTaskCall {
    public:
        UiTaskCall(WTF::RecursiveMutex* mutex, std::function<void()>&& func)
            : m_mutex(mutex)
            , m_func(func)
        {
        }

        ~UiTaskCall()
        {
        }

    private:
        WTF::RecursiveMutex* m_mutex;
        std::function<void()> m_func;

    public:
        static void asyncFunc(HWND hWnd, void* param)
        {
            UiTaskCall* self = (UiTaskCall*)param;

            self->m_mutex->lock();
            (self->m_func)();
            self->m_mutex->unlock();

            delete self;
        }
    };

    void show(const blink::UntrustworthyContextMenuParams& data, int64_t frameId)
    {
        if (!m_webview->isContextMenuEnable())
            return;
        ContextMenu* self = this;
        m_data = data;
        m_frameId = frameId;

        UINT actionFlags = 0;
        if ((!data.selection_text.empty()))
            actionFlags |= kSelectedTextId;

        if (data.has_image_contents) {
            actionFlags |= kCopyImageId;
            actionFlags |= kSaveImageId;
            m_imagePos = gfx::Point(data.x, data.y);
        }

        //if (m_webview->isDevtoolsConneted())
        //    actionFlags |= kInspectElementAtId;

        if (data.is_editable) {
            actionFlags |= kCutId;
            actionFlags |= kPasteId;
            actionFlags |= kSelectedAllId;
            actionFlags |= kUndoId;
        }

        if (m_webview->canGoForward())
            actionFlags |= kGoForwardId;
        if (m_webview->canGoBack())
            actionFlags |= kGoBackId;
        actionFlags |= kReloadId;

        bool needCreatePrintItem = false;
        //         mbOnContextMenuItemClickCallback clickCallback = m_webview->wkeHandler().contextMenuItemClickCallback;
        //         void* callbackParam = m_webview->wkeHandler().contextMenuItemClickCallbackParam;
        //         if (clickCallback)
        //             needCreatePrintItem = clickCallback(m_webview->wkeWebView(), callbackParam, kWkeContextMenuItemClickTypePrint, kWkeContextMenuItemClickStepShow, (wkeWebFrameHandle)m_frameId, nullptr);

        if (needCreatePrintItem)
            actionFlags |= kPrintId;

        std::string lang = base::ToLowerASCII(m_webview->getSetLanguage());

        asyncCallUiThread([self, actionFlags, lang] {
            if (0 < ContextMenu::m_isDestroyed)
                return;
            self->showImpl(actionFlags, lang);
        });
    }

    static bool canShowItem(UINT actionFlags, MenuId id)
    {
        if ((actionFlags & id) && (g_contextMenuItemMask & id))
            return true;
        return false;
    }

    void appendMenuText(UINT actionFlags, const std::string& lang)
    {
        //         if (!wke::g_language.get())
        //             return appendMenuTextZhcn(actionFlags);
        //
        //         if (std::string::npos != wke::g_language->find("zh-cn"))
        //             return appendMenuTextZhcn(actionFlags);

        if (lang == "zh-cn")
            return appendMenuTextZhcn(actionFlags);
        return appendMenuTextEn(actionFlags);
    }

    void appendMenuTextZhcn(UINT actionFlags)
    {
        if (canShowItem(actionFlags, kSelectedTextId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedTextId, L"复制");

        if (canShowItem(actionFlags, kCopyImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCopyImageId, L"复制图片");
        if (canShowItem(actionFlags, kSaveImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSaveImageId, L"图片另存为");

        if (canShowItem(actionFlags, kInspectElementAtId))
            ::AppendMenuW(m_popMenu, MF_STRING, kInspectElementAtId, L"检查");

        if (canShowItem(actionFlags, kCutId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCutId, L"剪切");

        if (canShowItem(actionFlags, kPasteId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPasteId, L"粘贴");

        if (canShowItem(actionFlags, kSelectedAllId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedAllId, L"全选");

        if (canShowItem(actionFlags, kUndoId))
            ::AppendMenuW(m_popMenu, MF_STRING, kUndoId, L"撤销");

        if (canShowItem(actionFlags, kGoForwardId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoForwardId, L"前进");

        if (canShowItem(actionFlags, kGoBackId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoBackId, L"后退");

        if (canShowItem(actionFlags, kReloadId))
            ::AppendMenuW(m_popMenu, MF_STRING, kReloadId, L"刷新");

        if (canShowItem(actionFlags, kPrintId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPrintId, L"打印");

        if (g_isElectronMode)
            ::AppendMenuW(m_popMenu, MF_STRING, kElectronDeclareId, L"本框架仅供测试、学习");
    }

    void appendMenuTextEn(UINT actionFlags)
    {
        if (canShowItem(actionFlags, kSelectedTextId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedTextId, L"Copy");

        if (canShowItem(actionFlags, kCopyImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCopyImageId, L"CopyImage");
        if (canShowItem(actionFlags, kSaveImageId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSaveImageId, L"Save as..");

        if (canShowItem(actionFlags, kInspectElementAtId))
            ::AppendMenuW(m_popMenu, MF_STRING, kInspectElementAtId, L"InspectElementAt");

        if (canShowItem(actionFlags, kCutId))
            ::AppendMenuW(m_popMenu, MF_STRING, kCutId, L"Cut");

        if (canShowItem(actionFlags, kPasteId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPasteId, L"Paste");

        if (canShowItem(actionFlags, kSelectedAllId))
            ::AppendMenuW(m_popMenu, MF_STRING, kSelectedAllId, L"SelectedAll");

        if (canShowItem(actionFlags, kUndoId))
            ::AppendMenuW(m_popMenu, MF_STRING, kUndoId, L"Undo");

        if (canShowItem(actionFlags, kGoForwardId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoForwardId, L"GoForward");

        if (canShowItem(actionFlags, kGoBackId))
            ::AppendMenuW(m_popMenu, MF_STRING, kGoBackId, L"GoBack");

        if (canShowItem(actionFlags, kReloadId))
            ::AppendMenuW(m_popMenu, MF_STRING, kReloadId, L"Reload");

        if (canShowItem(actionFlags, kPrintId))
            ::AppendMenuW(m_popMenu, MF_STRING, kPrintId, L"Print");

        if (g_isElectronMode)
            ::AppendMenuW(m_popMenu, MF_STRING, kElectronDeclareId, L"this framework only for test");
    }

    void showImpl(UINT actionFlags, const std::string& lang)
    {
        POINT screenPt = { 0 };
        ::GetCursorPos(&screenPt);

        POINT clientPt = screenPt;
        ::ScreenToClient(m_hWnd, &clientPt);

        if (m_popMenu)
            ::DestroyMenu(m_popMenu);
        m_popMenu = ::CreatePopupMenu();

        //m_data = blink::WebContextMenuData();
        appendMenuText(actionFlags, lang);

        if (0 == ::GetMenuItemCount(m_popMenu)) {
            ::DestroyMenu(m_popMenu);
            m_popMenu = nullptr;
            return;
        }

        //m_data = data;

        //::ShowWindow(m_hWnd, SW_SHOWMINNOACTIVE);
        //::SetForegroundWindow(m_hWnd);
        ::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREPOSITION | SWP_NOACTIVATE);

        UINT flags = TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_VERPOSANIMATION | TPM_HORIZONTAL | TPM_LEFTALIGN | TPM_HORPOSANIMATION;
        ::TrackPopupMenuEx(m_popMenu, flags, clientPt.x, clientPt.y, m_hWnd, 0);
    }

    void onCommand(UINT itemID)
    {
        if (0 < ContextMenu::m_isDestroyed)
            return;

        ThreadCall::wake();

        if (kSelectedTextId == itemID) {
            m_webview->getWebView()->FocusedFrame()->ExecuteCommand("Copy");
        } else if (kSelectedAllId == itemID) {
            m_webview->getWebView()->FocusedFrame()->ExecuteCommand("SelectAll");
        } else if (kUndoId == itemID) {
            m_webview->getWebView()->FocusedFrame()->ExecuteCommand("Undo");
        } else if (kCopyImageId == itemID) {
            m_webview->getWebView()->FocusedFrame()->CopyImageAtForTesting(m_imagePos);
        } else if (kSaveImageId == itemID) {
            //             if (!g_saveImageingWebPage) {
            //                 g_saveImageingWebPage = m_webview->webPageImpl();
            //                 m_webview->getWebView()->FocusedFrame()->CopyImageAt(m_imagePos);
            //             }
        } else if (kInspectElementAtId == itemID) {
            //m_webview->InspectElementAt(m_data.mousePosition.x, m_data.mousePosition.y);
        } else if (kCutId == itemID) {
            m_webview->getWebView()->FocusedFrame()->ExecuteCommand("Cut");
        } else if (kPasteId == itemID) {
            m_webview->getWebView()->FocusedFrame()->ExecuteCommand("Paste");
        } else if (kGoForwardId == itemID) {
            //m_webview->goForward();
            m_webview->navigateBackForwardSoon(1);
        } else if (kGoBackId == itemID) {
            //m_webview->goBack();
            m_webview->navigateBackForwardSoon(-1);
        } else if (kReloadId == itemID) {
            m_webview->getMainFrame()->ToWebLocalFrame()->StartReload(blink::WebFrameLoadType::kReload);
        } else if (kPrintId == itemID) {
            //             wkeOnContextMenuItemClickCallback clickCallback = m_webview->wkeHandler().contextMenuItemClickCallback;
            //             void* callbackParam = m_webview->wkeHandler().contextMenuItemClickCallbackParam;
            //             if (clickCallback)
            //                 clickCallback(m_webview->wkeWebView(), callbackParam, kWkeContextMenuItemClickTypePrint, kWkeContextMenuItemClickStepClick, (wkeWebFrameHandle)m_frameId, nullptr);
        }
    }

    static LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        //String output = String::Format("ContextMenu.wndProc: %d\n", uMsg);
        //OutputDebugStringA(output.Utf8().c_str());

        PAINTSTRUCT ps;
        HDC hdc = nullptr;
        ContextMenu* self = (ContextMenu*)GetPropW(hWnd, kContextMenuClassName);

        switch (uMsg) {
        case WM_TIMER:
            //self->hide();
            break;

        case WM_PAINT:
            hdc = ::BeginPaint(hWnd, &ps);
            self->onPaint(hWnd, hdc);
            ::EndPaint(hWnd, &ps);
            break;
        case WM_COMMAND: {
            UINT itemID = LOWORD(wParam);
            ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self, itemID] { self->onCommand(itemID); });
        } break;
        case WM_CLOSE:
            break;
        case WM_EXITMENULOOP:
            //::ShowWindow(self->m_hWnd, SW_HIDE);
            break;
        }

        return ::DefWindowProcW(hWnd, uMsg, wParam, lParam);
    }

    void onPaint(HWND hWnd, HDC hdc)
    {
    }

    HWND m_hWnd;
    HMENU m_popMenu;
    blink::UntrustworthyContextMenuParams m_data;

    gfx::Point m_imagePos;

    int m_lastX;
    int m_lastY;

    WTF::RecursiveMutex m_mutex;

    MbWebView* m_webview = nullptr;

    int64_t m_frameId;

    static ContextMenu* m_inst;

public:
    static volatile long m_isDestroyed;
};

volatile long ContextMenu::m_isDestroyed = 0;
ContextMenu* ContextMenu::m_inst = nullptr;

} // content
#endif // OS_WIN

namespace content {
void clearMbWebViewInContextMenuIfNeeded(MbWebView* webview)
{
#if defined(OS_WIN)
    if (ContextMenu::get()->getCurrentWebview() == webview)
        ContextMenu::get()->setCurrentWebview(nullptr);
#endif // OS_WIN
}
} // content

#endif // content_browser_ContextMeun_h