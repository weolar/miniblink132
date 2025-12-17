
#ifndef content_browser_MbWebview_h
#define content_browser_MbWebview_h

#include "content/viz/VizService.h"
#include "content/viz/VizHost.h"
#include "content/browser/PageNavController.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/base/cursor/cursor.h"
#include "mbvip/core/mb.h"
#include "mbvip/common/CallbackClosure.h"
#include "mbnet/PageNetExtraData.h"
#include "third_party/blink/public/web/web_draggable_region.h"
#include "third_party/blink/public/mojom/page/widget.mojom-blink.h"
#include "v8.h"
#include <memory>

namespace blink {
class WebNavigationControl;
class WebViewImpl;
class WebView;
}

namespace mb {
class MbJsValue;
void* getWindowScreenshotSync(void* webview);
}

namespace content {

class RenderWidgetHostImpl;
class WebLocalFrameClientImpl;
class PlatformEventHandler;
class OffscreenWindowUpdater;
class MbJsValue;

const uint32_t kUnusedColor = 0xFFA8456B;

class MbWebView {
public:
    MbWebView(bool isPopup);
    ~MbWebView();
    bool preDestroyOnUiThread();
    void preDestroyOnBlinkThread();

    void setHostWnd(HWND hWnd);
    HWND getHostWnd() const
    {
        return m_hWnd;
    }
    void setAutoDrawToHwnd(bool b)
    {
        m_isAutoDrawToHwnd = b;
    }
    bool getIsAutoDrawToHwnd() const
    {
        return m_isAutoDrawToHwnd;
    }

    int64_t getId() const
    {
        return m_id;
    }
    mbWebView getWebviewHandle() const
    {
        return (mbWebView)m_id;
    }
    blink::WebFrame* getMainFrame() const;

    void initializeCompositorInBlinkThread(/*gfx::AcceleratedWidget hwnd*/ bool isTransparent);
    void createWebWindowInUiThread(mbWindowType type, HWND parent, int x, int y, int width, int height);

    void onPaintUpdatedInUiThread(const HDC hdc, int x, int y, int cx, int cy);

    void setIsMouseKeyMessageEnable(bool b)
    {
        m_enableMouseKeyMessage = b;
    }

    void setShow(int nCmdShow /*, bool isActivate*/);
    bool setWindowTitle(const std::string& title);
    const std::string& getWindowTitle() const
    {
        return m_windowTitle;
    }
    const std::string& getUrl() const
    {
        return m_url;
    }

    void setIsTransparent(bool b);
    bool isTransparent() const
    {
        return m_isTransparent;
    }
    void setContextMenuEnable(bool b);
    bool isContextMenuEnable() const
    {
        return m_isContextMenuEnable;
    }

#ifndef _WIN32
    void setNcHittestPadding(int ncHittestPadding)
    {
        m_ncHittestPadding = ncHittestPadding;
    }
#endif
    void setZoomFactor(float factor);
    float getZoomFactor() const;
    bool hasSetZoomFactor() const
    {
        return m_hasSetZoomFactor;
    }
    void propagatedZoomFactor();

    blink::WebView* createWebWindowOrViewInBlinkThread(blink::WebView* opener, blink::WebFrame* openerWebFrame, bool isWebWindowMode, bool isTransparent);
    void createWebWindowImplInUiThread(HWND parent, DWORD style, DWORD styleEx, int x, int y, int width, int height);
    void initPopupWidgetModeInBlinkThread(mbWebView parentWebviewId, ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::PopupWidgetHost> popupHost,
        ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::WidgetHost> blinkWidgetHost,
        ::mojo::PendingAssociatedRemote<::blink::mojom::blink::Widget> blinkWidget);

    void loadUrl(const char* urlStr);
    bool loadHTMLString(const std::string& html, const std::string& baseUrl);
    void reload(bool force);

    void setBackgroundColor(COLORREF c);
    COLORREF getBackgroundColor() const
    {
        return m_backgroundColor;
    }
    void navigateBackForwardSoon(int offset);
    int historyBackListCount() const;
    int historyForwardListCount() const;
    void navigateToIndex(int index);
    bool canGoForward() const;
    bool canGoBack() const;

    bool hasDispatchWillCommitProvisionalLoad() const
    {
        return m_hasDispatchWillCommitProvisionalLoad;
    }
    void resetState()
    {
        m_hasDispatchWillCommitProvisionalLoad = false;
    } // 有url load的时候会调用

    mb::MbJsValue* runJsOnBlinkThreadImpl(
        mbWebFrameHandle frameId, int worldId, std::string* scriptString, BOOL isInClosure, mbRunJsCallback callback, void* param);

    LRESULT fireWheelEventOnUiThread(WPARAM wParam, LPARAM lParam);
    void onMouseMessage(unsigned int message, int x, int y, unsigned int flags);
    bool onKeyUp(unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);
    bool onKeyDown(unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);
    bool onKeyPress(unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);

    enum ImeCompositioType {
        kImeCompositioTypeStart,
        kImeCompositioTypeCom,
        kImeCompositioTypeEnd,
        kImeCompositioTypeChar
    };
    void onImeComposition(ImeCompositioType type, WCHAR c);

    bool setCursorInfoTypeByCache();
    void setCursor(const ::ui::Cursor& cursor);
    void setCaretPos(const gfx::Point& pos);
    gfx::Point getCaretPos() const;

    void setOffset(int x, int y)
    {
        m_offset.x = x;
        m_offset.y = y;
    }
    POINT getOffset() const
    {
        return m_offset;
    }

    void setFocus();
    void killFocus();

    void debugShowDomNode();

    bool isWebWindowMode() const
    {
        return m_isWebWindowMode;
    }

    void onDidCreateScriptContext(v8::Local<v8::Context>, int32_t worldId, const blink::LocalFrameToken& token);
    void onWillReleaseScriptContext(v8::Local<v8::Context>, int32_t worldId, const blink::LocalFrameToken& token);

    mb::CallbackClosure& getClosure()
    {
        return m_closure;
    }

    void setCookieJarFullPath(const char* path);
    void setLocalStorageFullPath(const char* path);
    base::FilePath getLocalStorageDir();
    base::FilePath getDownloadDirPath();

    void onResize(int w, int h, bool needSetHostWnd);
    LRESULT onNcHittest(LPARAM lParam);

    void didCommitProvisionalLoad(blink::WebLocalFrame* frame, const blink::WebHistoryItem& history, blink::WebHistoryCommitType type, bool isSameDocument);

    blink::WebHistoryItem historyItemForNewChildFrame(blink::WebFrame* frame);

    void dispatchUrlCheanged(const std::string& url);

    ::blink::WebView* getWebView() const;

    HDC getViewDC();
    void unlockViewDC();

    void onAllocatedSharedMemory(const gfx::Size& pixelSize, HDC dibDC, void* lock);
    void onAllocatedBitmapMemory(const gfx::Size& pixelSize, void* surface, unsigned char* bitmap, void* lock);

    void setSessionStorageNamespaceId(const std::string& sessionStorageNamespaceId)
    {
        m_sessionStorageNamespaceId = sessionStorageNamespaceId;
    }

    void bindGtkWindow(void* rootWindow, void* drawingArea, bool isGl, DWORD style, DWORD styleEx, int width, int height);

    scoped_refptr<mbnet::PageNetExtraData> getPageNetExtraData();
    mbnet::WebCookieJarImpl* getWebCookieJarImpl();
    std::string getCookie();
    void setCookie(const std::string& ck);

    std::map<std::string, void*>& getUserKeyValues()
    {
        return m_userKeyValues;
    }
    void setUserKeyValue(const char* key, void* value);
    void* getUserKeyValue(const char* key) const;

    SIZE getClientSizeLocked();
    int getCursorInfoType() const; // { return m_cursorInfoType; }
    WebLocalFrameClientImpl* getFrameClient() const
    {
        return m_frameClient;
    }

    void setProxy(const mbProxy* proxy);
    const mbProxy* getProxy() const;

    void setSetLanguage(const std::string& lang);
    std::string getSetLanguage() const;

    void draggableRegionsChanged(blink::WebVector<blink::WebDraggableRegion> regions);

private:
    friend class RenderWidgetHostImpl;
    friend class OffscreenWindowUpdater;
    friend class WebLocalFrameClientImpl;
    void destroy();

    void handlePopup(UINT message);

    void setDefaultPreferences(blink::WebViewImpl* webWiew);
    blink::WebView* initializeViewInBlinkThread(blink::WebView* opener, blink::WebFrame* openerWebFrame);

    void setClientSizeLocked(int w, int h);

    friend class LocalFrameHostImpl;

    static LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT windowProcImpl(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    void onPaint(HWND hWnd, WPARAM wParam);

    void updataBlinkSize();

    void delayDoMouseMsgInCompositorThread();
    bool isDraggableRegionNcHitTest(HWND hWnd);
    bool doDraggableRegionNcHitTest(HWND hWnd, int x, int y);

    int64_t m_id;

    std::string m_sessionStorageNamespaceId;
    HWND m_hWnd = nullptr;
    std::unique_ptr<VizService> m_service;
    std::unique_ptr<VizHost> m_host;
    std::unique_ptr<RenderWidgetHostImpl> m_renderWidgetHostImpl;
    std::unique_ptr<PlatformEventHandler> m_platformEventHandler;

    WebLocalFrameClientImpl* m_frameClient = nullptr;

    mb::CallbackClosure m_closure;

    bool m_isPopup = false;
    bool m_hasDispatchWillCommitProvisionalLoad = false;
    bool m_isTransparent = false;
    bool m_isContextMenuEnable = true;
    bool m_isShow = false;
    bool m_isWebWindowMode = false;
    bool m_isPopupWidgetMode = false;
    bool m_isEnableNode = false;
    bool m_isAutoDrawToHwnd = true;
    //int m_cursorInfoType = 0;
    bool m_isCursorInfoTypeAsynGetting = false;
    bool m_isCursorInfoTypeAsynChanged = false;

    //CRITICAL_SECTION m_memoryCanvasLock;
    base::Lock* m_memoryCanvasLock = nullptr;
    int m_memoryCanvasLockCount = 0;

#if defined(OS_WIN)
    HBITMAP m_memoryBMP = nullptr;
    COLORREF* m_bits = nullptr;
#else
    SkBitmap* m_bitmap = nullptr;
#endif
    gfx::Size m_bitmapByteSize;
    unsigned char* m_bitmapByte = nullptr;
    void* m_surface = nullptr;
    SkCanvas* m_memoryCanvas = nullptr;
    friend void* mb::getWindowScreenshotSync(void* webview);

    COLORREF m_backgroundColor = 0xffffffff;
    bool m_hasBackgroundColor = false;

    gfx::Point m_caretPos;

    CRITICAL_SECTION m_mouseMsgQueueLock;
    struct MouseMsg {
        MouseMsg(const MouseMsg& other)
        {
            init(other.message, other.x, other.y, other.flags);
        }

        MouseMsg(unsigned int message, int x, int y, unsigned int flags)
        {
            init(message, x, y, flags);
        }

        void init(unsigned int message, int x, int y, unsigned int flags)
        {
            this->message = message;
            this->x = x;
            this->y = y;
            this->flags = flags;
        }
        unsigned int message;
        int x;
        int y;
        unsigned int flags;
    };
    std::list<MouseMsg*> m_mouseMsgQueue;

    std::vector<mbRect*> m_dirtyRect;
    mutable CRITICAL_SECTION m_dirtyRectLock;

    mutable CRITICAL_SECTION m_clientSizeLock;
    SIZE m_clientSize;
    SIZE m_clientSizeCache;
    bool m_clientSizeDirty = true;
    bool m_clientResizeRepaintDirty = true;
    bool m_isAsynResizing = false;
    bool m_updataBlinkSizeAsyn = false;

    bool m_isLayerWindow = false;
    POINT m_offset;
    blink::WebVector<blink::WebDraggableRegion> m_draggableRegion;
    bool m_enableMouseKeyMessage = true;
    float m_zoomFactor = 1.0f;
    bool m_hasSetZoomFactor = false;

    bool m_isInNotClient = false; // 是否在非客户区

    long m_navigateIndex = 0;

    ::ui::Cursor m_cursor;

    enum PageState { kPageInited, kPageDestroying, kPageDestroyed };
    PageState getState() const
    {
        return m_state;
    }

    PageState m_state = kPageInited;

#ifndef _WIN32
    int m_ncHittestPadding = 0;
#endif
    std::string m_windowTitle;
    std::string m_title;
    std::string m_url;

    std::map<std::string, void*> m_userKeyValues;
    mutable CRITICAL_SECTION m_userKeyValuesLock;

    long m_createWebViewRequestCount;

    blink::Persistent<content::PageNavController> m_navigationController;

    scoped_refptr<mbnet::PageNetExtraData> m_pageNetExtraData;
};

}

#endif // content_browser_MbWebview_h