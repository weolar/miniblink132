// Copyright (C) 2006-2010 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_WEB_PLUGIN_IMPL_H_
#define CONTENT_RENDERER_NPAPI_WEB_PLUGIN_IMPL_H_

#include <memory>
#include <set>
#include <string>
#include <vector>

#include "base/memory/ref_counted.h"
#include "base/memory/scoped_refptr.h"
#include "base/timer/timer.h"
#include "content/renderer/npapi/PluginPackage.h"
#include "content/renderer/npapi/PluginStream.h"
#include "services/network/public/cpp/resource_request.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/web_plugin.h"
#include "third_party/blink/public/web/web_plugin_params.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/npapi/bindings/npruntime.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/rect.h"
#include <windows.h>

namespace blink {
class WebInputEvent;
class WebMouseEvent;
class WebKeyboardEvent;
}

namespace content {

enum PluginStatus {
    PluginStatusCanNotFindPlugin,
    PluginStatusCanNotLoadPlugin,
    PluginStatusLoadedSuccessfully
};

class PluginMessageThrottlerWin;
class WebPluginIMEWin;

struct PluginRequest {
    std::unique_ptr<network::ResourceRequest> request;
    std::string targetFrameName;
    void* notifyData = nullptr;
    bool sendNotification = false;
    bool shouldAllowPopups = false;
};

class WebPluginImpl : public base::RefCounted<WebPluginImpl>,
                      public blink::WebPlugin,
                      public PluginStreamClient {
public:
    WebPluginImpl(blink::WebLocalFrame* parentFrame, const blink::WebPluginParams& params,
        int64_t mbwebviewId, HWND parentWidget, POINT widgetOffset);

    // blink::WebPlugin overrides
    bool Initialize(blink::WebPluginContainer* container) override;
    void Destroy() override;
    blink::WebPluginContainer* Container() const override { return m_pluginContainer; }
    v8::Local<v8::Object> V8ScriptableObject(v8::Isolate* isolate) override;

    bool SupportsKeyboardFocus() const override { return true; }
    bool SupportsInputMethod() const override { return true; }
    bool CanProcessDrag() const override { return false; }

    void UpdateAllLifecyclePhases(blink::DocumentUpdateReason) override { }
    void Paint(cc::PaintCanvas* canvas, const gfx::Rect& rect) override;
    void UpdateGeometry(const gfx::Rect& windowRect, const gfx::Rect& clipRect,
        const gfx::Rect& unobscuredRect, bool isVisible) override;
    void UpdateFocus(bool focused, blink::mojom::FocusType focusType) override;
    void UpdateVisibility(bool isVisible) override;

    blink::WebInputEventResult HandleInputEvent(
        const blink::WebCoalescedInputEvent& event, ui::Cursor* cursor) override;

    void DidReceiveResponse(const blink::WebURLResponse& response) override;
    void DidReceiveData(base::span<const char> data) override;
    void DidFinishLoading() override;
    void DidFailLoading(const blink::WebURLError& error) override;

    bool SetComposition(const blink::WebString& text, const blink::WebVector<ui::ImeTextSpan>& imeTextSpans,
        const blink::WebRange& replacementRange, int selectionStart, int selectionEnd) override;
    bool CommitText(const blink::WebString& text, const blink::WebVector<ui::ImeTextSpan>& imeTextSpans,
        const blink::WebRange& replacementRange, int relativeCaretPosition) override;
    bool FinishComposingText(blink::WebInputMethodController::ConfirmCompositionBehavior selectionBehavior) override;

    // PluginStreamClient
    void streamDidFinishLoading(PluginStream* stream) override { disconnectStream(stream); }

    // NPN_* callbacks
    NPError getURLNotify(const char* url, const char* target, void* notifyData);
    NPError getURL(const char* url, const char* target);
    NPError postURLNotify(const char* url, const char* target, uint32_t len, const char* buf, NPBool file, void* notifyData);
    NPError postURL(const char* url, const char* target, uint32_t len, const char* buf, NPBool file);
    NPError newStream(NPMIMEType type, const char* target, NPStream** stream);
    int32_t write(NPStream* stream, int32_t len, void* buffer);
    NPError destroyStream(NPStream* stream, NPReason reason);

    const char* userAgent();
    static const char* userAgentStatic();
    void status(const char* message);

    NPError getValue(NPNVariable variable, void* value);
    static NPError getValueStatic(NPNVariable variable, void* value);
    NPError setValue(NPPVariable variable, void* value);
    NPError getValueForURL(NPNURLVariable variable, const char* url, char** value, uint32_t* len);
    NPError setValueForURL(NPNURLVariable variable, const char* url, const char* value, uint32_t len);
    NPError getAuthenticationInfo(const char* protocol, const char* host, int32_t port, const char* scheme,
        const char* realm, char** username, uint32_t* ulen, char** password, uint32_t* plen);

    void invalidateRect(NPRect* rect);
    void invalidateRect(const gfx::Rect& rect);
    void invalidateRegion(NPRegion region);
    void forceRedraw();

    void pushPopupsEnabledState(bool state);
    void popPopupsEnabledState();
    bool arePopupsAllowed() const;

    bool handleKeyboardCharEventForEmulateIme(int windowsKeyCode);
    bool getImeStatus(int* inputType, gfx::Rect* caretRect);

    bool isStarted() const { return m_isStarted; }
    WNDPROC pluginWndProc() const { return m_pluginWndProc; }
    static LRESULT CALLBACK PluginViewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    class ScopedCurrentPluginView {
    public:
        explicit ScopedCurrentPluginView(WebPluginImpl* view)
            : m_previous(s_currentPluginView)
        {
            s_currentPluginView = view;
        }
        ~ScopedCurrentPluginView()
        {
            s_currentPluginView = m_previous;
        }
        ScopedCurrentPluginView(const ScopedCurrentPluginView&) = delete;
        ScopedCurrentPluginView& operator=(const ScopedCurrentPluginView&) = delete;

    private:
        WebPluginImpl* m_previous;
    };

    static WebPluginImpl* currentPluginView();
    static WebPluginImpl* fromInstance(NPP instance);
    static bool isAlive(NPP instance);
    static void notifyManualLoadFinishedForFrame(blink::WebLocalFrame* frame);

private:
    friend class base::RefCounted<WebPluginImpl>;
    ~WebPluginImpl() override;

    void registerManualPlugin();
    void unregisterManualPlugin();

    void init();
    bool start();
    void stop();
    bool platformStart();
    void platformDestroy();
    static void setCurrentPluginView(WebPluginImpl* view);
    void setCallingPlugin(bool calling) const;

    void findVirtualPluginByMime();
    void setParameters(const blink::WebVector<blink::WebString>& paramNames,
        const blink::WebVector<blink::WebString>& paramValues);
    static void freeStringArray(char** stringArray, int length);

    NPObject* npObject();
    NPObject* windowScriptNPObject();
    NPObject* pluginElementNPObject();

    NPError loadRequest(std::unique_ptr<network::ResourceRequest> request,
        const char* target, bool sendNotification, void* notifyData);
    NPError handlePost(const char* url, const char* target, uint32_t len, const char* buf,
        bool file, void* notifyData, bool sendNotification, bool allowHeaders);
    NPError handlePostReadFile(std::vector<char>& buffer, uint32_t len, const char* buf);
    void scheduleRequest(std::unique_ptr<PluginRequest> request);
    void requestTimerFired();
    void performRequest(std::unique_ptr<PluginRequest> request);
    void disconnectStream(PluginStream* stream);

    void invalidateTimerFired();
    void popPopupsStateTimerFired();
    void visibilityTimerFired();

    bool platformGetValue(NPNVariable variable, void* value, NPError* result);
    static bool platformGetValueStatic(NPNVariable variable, void* value, NPError* result);

    // Painting & window helpers (implemented in WebPluginImplPaintWin.cpp)
    void ensureBackingDib(int width, int height);
    void releaseBackingDib();
    void updatePluginWidget(const gfx::Rect& windowRect, const gfx::Rect& clipRect, bool isVisible);
    void setRgnIfNeeded(const gfx::Rect& windowRect, const gfx::Rect& oldWindowRect, const gfx::Rect& oldClipRect);
    void setNPWindowRect(const gfx::Rect& rect);
    void paintIntoTransformedContext(HDC hdc);
    bool dispatchNPEvent(NPEvent& npEvent);
    static HDC WINAPI hookedBeginPaint(HWND hWnd, PAINTSTRUCT* lpPaint);
    static BOOL WINAPI hookedEndPaint(HWND hWnd, const PAINTSTRUCT* lpPaint);

    // Input helpers (implemented in WebPluginImplInputWin.cpp)
    bool handleMouseEvent(const blink::WebInputEvent& rawEvent, ui::Cursor* cursor);
    bool handleKeyboardEvent(const blink::WebKeyboardEvent& evt);
    void syncImeCaretPos();
    void ensureInstanceAllocated();

    blink::WebPluginContainer* m_pluginContainer = nullptr;
    blink::WebLocalFrame* m_webFrame = nullptr;
    int64_t m_mbwebviewId = 0;

    scoped_refptr<PluginPackage> m_plugin;
    PluginStatus m_status = PluginStatusLoadedSuccessfully;
    blink::KURL m_url;
    std::string m_mimeType;
    std::string m_userAgent;
    WTF::String m_pluginsPage;

    int m_mode = NP_EMBED;
    int m_paramCount = 0;
    char** m_paramNames = nullptr;
    char** m_paramValues = nullptr;

    NPP m_instance = nullptr;
    NPWindow m_npWindow {};
    NPObject* m_windowNPObject = nullptr;
    NPObject* m_pluginElementNPObject = nullptr;

    bool m_haveInitialized = false;
    bool m_isDestroyed = false;
    bool m_hasLoadedPlugin = false;
    bool m_isStarted = false;
    bool m_isWindowed = true;
    bool m_isTransparent = false;
    bool m_loadManually = false;
    bool m_haveCalledSetWindow = false;
    bool m_haveUpdatedPluginWidget = false;
    bool m_isVisible = true;

    scoped_refptr<PluginStream> m_manualStream;
    std::set<scoped_refptr<PluginStream>> m_streams;
    std::vector<std::unique_ptr<PluginRequest>> m_requests;
    std::vector<gfx::Rect> m_invalidRects;
    std::vector<bool> m_popupStateStack;

    base::OneShotTimer m_requestTimer;
    base::OneShotTimer m_invalidateTimer;
    base::OneShotTimer m_popPopupsStateTimer;
    base::OneShotTimer m_visibilityTimer;

    HWND m_widget = nullptr;
    HWND m_parentWidget = nullptr;
    gfx::Point m_widgetOffset;
    gfx::Rect m_windowRect;
    gfx::Rect m_clipRect;

    HDC m_memoryDC = nullptr;
    HBITMAP m_memoryBitmap = nullptr;
    HGDIOBJ m_oldBitmap = nullptr;
    void* m_memoryPixels = nullptr;
    SIZE m_memoryCanvasSize { 0, 0 };
    HDC m_lastPaintHDC = nullptr;
    gfx::Size m_lastSetWindowSize;

    std::unique_ptr<PluginMessageThrottlerWin> m_messageThrottler;
    WNDPROC m_pluginWndProc = nullptr;
    UINT m_lastMessage = 0;
    bool m_isCallingPluginWndProc = false;
    HDC m_wmPrintHDC = nullptr;
    int m_pluginViewWndProcReentryCount = 0;

    std::unique_ptr<WebPluginIMEWin> m_pluginIme;

    static WebPluginImpl* s_currentPluginView;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_WEB_PLUGIN_IMPL_H_
