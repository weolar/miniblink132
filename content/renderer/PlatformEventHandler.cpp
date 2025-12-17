
#include "content/renderer/PlatformEventHandler.h"

#include "content/browser/MbWebview.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/browser/RenderWidgetHostImpl.h"
#include "content/common/ThreadCall.h"
#include "third_party/blink/renderer/platform/scheduler/worker/compositor_thread_scheduler_impl.h"

#include "third_party/blink/renderer/core/exported/web_view_impl.h"
#include "third_party/blink/public/common/input/web_gesture_event.h"
#include "third_party/blink/public/common/input/web_coalesced_input_event.h"
#include "third_party/blink/public/common/input/web_mouse_wheel_event.h"
#include "third_party/blink/public/web/web_widget.h"
#include "third_party/blink/public/mojom/input/input_handler.mojom-blink.h"
#include "third_party/blink/public/mojom/page/widget.mojom-blink.h"
#include "ui/latency/latency_info.h"
#include "ui/events/keycodes/dom/dom_code.h"
#include "ui/events/keycodes/dom/dom_key.h"
#include <windowsx.h>

namespace content {

static const unsigned short HIGH_BIT_MASK_SHORT = 0x8000;

// Source\WebCore\platform\win\KeyEventWin.cpp
static bool isKeypadEvent(WPARAM code, LPARAM keyData, blink::WebInputEvent::Type type)
{
    if (blink::WebInputEvent::Type::kRawKeyDown != type && blink::WebInputEvent::Type::kKeyUp != type)
        return false;

    switch (code) {
    case VK_NUMLOCK:
    case VK_NUMPAD0:
    case VK_NUMPAD1:
    case VK_NUMPAD2:
    case VK_NUMPAD3:
    case VK_NUMPAD4:
    case VK_NUMPAD5:
    case VK_NUMPAD6:
    case VK_NUMPAD7:
    case VK_NUMPAD8:
    case VK_NUMPAD9:
    case VK_MULTIPLY:
    case VK_ADD:
    case VK_SEPARATOR:
    case VK_SUBTRACT:
    case VK_DECIMAL:
    case VK_DIVIDE:
        return true;
    case VK_RETURN:
        return HIWORD(keyData) & KF_EXTENDED;
    case VK_INSERT:
    case VK_DELETE:
    case VK_PRIOR:
    case VK_NEXT:
    case VK_END:
    case VK_HOME:
    case VK_LEFT:
    case VK_UP:
    case VK_RIGHT:
    case VK_DOWN:
        return !(HIWORD(keyData) & KF_EXTENDED);
    default:
        return false;
    }
}

int verticalScrollLines()
{
    static ULONG scrollLines = 0;
    if (!scrollLines && !SystemParametersInfoW(SPI_GETWHEELSCROLLLINES, 0, &scrollLines, 0))
        scrollLines = 3;
    return scrollLines;
}

int horizontalScrollChars()
{
    static ULONG scrollChars = 0;
    if (!scrollChars && !SystemParametersInfoW(SPI_GETWHEELSCROLLCHARS, 0, &scrollChars, 0))
        scrollChars = 1;
    return scrollChars;
}

static bool isNearPos(const gfx::Point& a, const gfx::Point& b)
{
    return std::abs(a.x() - b.x()) + std::abs(a.y() - b.y()) < 15;
}

static void postDragMessageImpl(HWND hWnd, void* param)
{
    ::ReleaseCapture();
    ::PostMessageW(hWnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
}

PlatformEventHandler::PlatformEventHandler(int64_t webviewid, blink::WebWidget* webWidget, blink::WebViewImpl* webViewImpl)
//     : m_checkMouseLeaveTimer(this, &PlatformEventHandler::checkMouseLeave)
//     , m_touchEmulator(webWidget)
{
    m_isDispatchDirectlyToWidget = !webViewImpl;
    m_isDraggableRegionNcHitTest = false;
    m_postMouseLeave = false;
    m_mouseInWindow = false;
    m_isAlert = false;
    m_webviewid = webviewid;
    m_isDraggableNodeMousedown = false;
    m_isLeftMousedown = false;
    m_lastTimeMouseDown = 0;
    m_isValidLastTouchDownPoint = false;
    m_webWidget = webWidget;
    m_webViewImpl = webViewImpl;
    m_enableTouchSimulate = false;
    m_enableSystemTouch = false;
}

PlatformEventHandler::~PlatformEventHandler()
{
    m_checkMouseLeaveTimer.reset();
}

void PlatformEventHandler::destroy()
{
    m_lock.Acquire();
    m_webWidget = nullptr;
    m_webViewImpl = nullptr;
    m_blinkWidgetInputHandler.reset();
    m_hostReceiver.reset();
    m_lock.Release();

    if (m_isDispatchDirectlyToWidget) {
        delete this;
    } else {
        scoped_refptr<base::SingleThreadTaskRunner> runner = blink::ThreadScheduler::CompositorThreadScheduler()->InputTaskRunner();
        runner->PostTask(FROM_HERE, base::BindOnce([](PlatformEventHandler* self) { delete self; }, base::Unretained(this)));
    }
}

bool PlatformEventHandler::isDraggableRegionNcHitTest(HWND hWnd, const gfx::Point& pos, const blink::WebVector<blink::WebDraggableRegion>& draggableRegion)
{
    // 单线程情况下，直接在mb内部处理拖拽。多线程渲染时，必须在ui线程处理，否则blink线程卡了，会导致拖拽也很卡
    //if (!/*blink::RuntimeEnabledFeatures::updataInOtherThreadEnabled()*/true)
    //    return m_isDraggableNodeMousedown;
    //return false;

    bool draggable = false;
    for (size_t i = 0; i < draggableRegion.size(); ++i) {
        blink::WebDraggableRegion r = draggableRegion[i];
        if (r.bounds.Contains(pos)) {
            if (!r.draggable)
                return false;
            draggable = true;
        }
    }
    return draggable;
}

void PlatformEventHandler::fireWheelEventOnCompositorThread(int x, int y, bool shiftKey, bool ctrlKey, float delta, float deltaX, float deltaY, int modifiers)
{
    if (!m_blinkWidgetInputHandler.is_bound())
        return;
    blink::WebMouseWheelEvent mouseWheelEvent;

    mouseWheelEvent.SetType(blink::mojom::EventType::kMouseWheel);
    mouseWheelEvent.SetPositionInWidget(gfx::PointF(x, y));
    mouseWheelEvent.SetPositionInScreen(gfx::PointF(x, y));
    mouseWheelEvent.SetTimeStamp(base::TimeTicks::Now());

    mouseWheelEvent.delta_x = deltaX;
    mouseWheelEvent.delta_y = deltaY;

    mouseWheelEvent.wheel_ticks_x = (shiftKey) ? delta : 0;
    mouseWheelEvent.wheel_ticks_y = (!shiftKey) ? delta : 0;

    mouseWheelEvent.phase = blink::WebMouseWheelEvent::kPhaseNone;
    mouseWheelEvent.dispatch_type = blink::WebMouseWheelEvent::DispatchType::kBlocking;
    mouseWheelEvent.event_action = blink::WebMouseWheelEvent::EventAction::kPageZoom;

    std::unique_ptr<blink::WebCoalescedInputEvent> mouseWheelCoalescedEvent
        = std::make_unique<blink::WebCoalescedInputEvent>(mouseWheelEvent, ui::LatencyInfo());
    m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::move(mouseWheelCoalescedEvent));

    blink::WebGestureEvent webGestureEvent;
    webGestureEvent.SetType(blink::mojom::EventType::kGestureScrollBegin);
    webGestureEvent.SetSourceDevice(blink::mojom::GestureDevice::kTouchpad);
    webGestureEvent.SetPositionInWidget(gfx::PointF(x, y));
    webGestureEvent.SetPositionInScreen(gfx::PointF(x, y));
    webGestureEvent.SetTimeStamp(base::TimeTicks::Now());
    webGestureEvent.data.scroll_begin.delta_x_hint = deltaX;
    webGestureEvent.data.scroll_begin.delta_y_hint = deltaY;
    webGestureEvent.data.scroll_begin.delta_hint_units = ui::ScrollGranularity::kScrollByPixel;
    webGestureEvent.data.scroll_begin.target_viewport = false;
    webGestureEvent.data.scroll_begin.inertial_phase = blink::mojom::InertialPhaseState::kNonMomentum;
    webGestureEvent.data.scroll_begin.synthetic = true;
    webGestureEvent.data.scroll_begin.pointer_count = 1;
    m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::make_unique<blink::WebCoalescedInputEvent>(webGestureEvent, ui::LatencyInfo()));

    webGestureEvent.SetType(blink::mojom::EventType::kGestureScrollUpdate);
    webGestureEvent.data.scroll_update.delta_x = deltaX;
    webGestureEvent.data.scroll_update.delta_y = deltaY;
//     webGestureEvent.data.scroll_update.velocity_x = deltaX;
//     webGestureEvent.data.scroll_update.velocity_y = deltaY;
    webGestureEvent.data.scroll_update.inertial_phase = blink::mojom::InertialPhaseState::kNonMomentum;
    webGestureEvent.data.scroll_update.delta_units = ui::ScrollGranularity::kScrollByPixel;
    m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::make_unique<blink::WebCoalescedInputEvent>(webGestureEvent, ui::LatencyInfo()));

    webGestureEvent.SetType(blink::mojom::EventType::kGestureScrollEnd);
    webGestureEvent.data.scroll_end.inertial_phase = blink::mojom::InertialPhaseState::kNonMomentum;
    webGestureEvent.data.scroll_end.synthetic = true;
    webGestureEvent.data.scroll_end.generated_by_fling_controller = true;
    webGestureEvent.data.scroll_end.delta_units = ui::ScrollGranularity::kScrollByPixel;
    m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::make_unique<blink::WebCoalescedInputEvent>(webGestureEvent, ui::LatencyInfo()));
}

LRESULT PlatformEventHandler::fireWheelEvent(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    int x = GET_X_LPARAM(lParam);
    int y = GET_Y_LPARAM(lParam);
    POINT point = { x, y };
    ::ScreenToClient(hWnd, &point);
    x = point.x;
    y = point.y;

    int wheelDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    int modifiers = 0;
    static const float cScrollbarPixelsPerLine = 100.0f / 3.0f;
    float delta = wheelDelta / static_cast<float>(WHEEL_DELTA);

    float deltaX = 0.f;
    float deltaY = 0.f;

    bool shiftKey = wParam & MK_SHIFT;
    bool ctrlKey = wParam & MK_CONTROL;

    if (delta < 0)
        delta = -1;
    if (delta > 0)
        delta = 1;

    if (shiftKey) {
        deltaX = delta * static_cast<float>(horizontalScrollChars()) * cScrollbarPixelsPerLine;
        deltaY = 0;
        //granularity = blink::ScrollByPixelWheelEvent;
        modifiers |= blink::WebInputEvent::kShiftKey;
    } else {
        deltaX = 0;
        deltaY = delta;
        int verticalMultiplier = verticalScrollLines();
        //         granularity = (verticalMultiplier == WHEEL_PAGESCROLL) ? blink::ScrollByPageWheelEvent : blink::ScrollByPixelWheelEvent;
        //         if (granularity == blink::ScrollByPixelWheelEvent)
        if (verticalMultiplier != WHEEL_PAGESCROLL)
            deltaY *= static_cast<float>(verticalMultiplier) * cScrollbarPixelsPerLine;
    }

    if (ctrlKey)
        modifiers |= blink::WebInputEvent::kControlKey;

    CHECK(this);
    blink::CompositorThreadScheduler* compositingThreadScheduler = blink::ThreadScheduler::CompositorThreadScheduler();
    scoped_refptr<base::SingleThreadTaskRunner> runner = compositingThreadScheduler->InputTaskRunner();
    if (m_isDispatchDirectlyToWidget)
        runner = RenderThreadImpl::get()->getTaskRunner();

    runner->PostTask(FROM_HERE,
        base::BindOnce(
            [](PlatformEventHandler* self, int x, int y, bool shiftKey, bool ctrlKey, float delta, float deltaX, float deltaY, int modifiers) {
                //self->m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::move(evt)); // TODO: 没考虑跨进程被析构的情况
                self->m_lock.Acquire();
                self->fireWheelEventOnCompositorThread(x, y, shiftKey, ctrlKey, delta, deltaX, deltaY, modifiers);
                self->m_lock.Release();
            },
            /*m_weakPtr.GetWeakPtr()*/ base::Unretained(this), x, y, shiftKey, ctrlKey, delta, deltaX, deltaY, modifiers));

    //     std::unique_ptr<blink::WebCoalescedInputEvent> evtToBlink = std::make_unique<blink::WebCoalescedInputEvent>(mouseWheelEvent, ui::LatencyInfo());
    //     RenderThreadImpl::get()->getTaskRunner()->PostNonNestableTask(FROM_HERE,
    //         base::BindOnce([](/*base::WeakPtr<PlatformEventHandler>*/PlatformEventHandler* self, std::unique_ptr<blink::WebCoalescedInputEvent> evt) {
    //             self->m_webWidget->HandleInputEvent(*evt); // TODO: 没考虑跨进程被析构的情况
    //     }, /*m_weakPtr.GetWeakPtr()*/base::Unretained(this), std::move(evtToBlink)));

    //     webGestureEvent.setType(WebInputEvent::GestureScrollUpdate);
    //     webGestureEvent.data.scrollUpdate.deltaX = deltaX;
    //     webGestureEvent.data.scrollUpdate.deltaY = deltaY;
    //     webGestureEvent.data.scrollUpdate.velocityX = x;
    //     webGestureEvent.data.scrollUpdate.velocityY = y;
    //     webGestureEvent.data.scrollUpdate.previousUpdateInSequencePrevented = false;
    //     webGestureEvent.data.scrollUpdate.preventPropagation = false;
    //     webGestureEvent.data.scrollUpdate.inertialPhase = WebGestureEvent::NonMomentumPhase;
    //     m_webWidget->handleInputEvent(webGestureEvent);
    //
    //     webGestureEvent.setType(WebInputEvent::GestureScrollEnd);
    //     webGestureEvent.data.scrollEnd.synthetic = true;
    //     webGestureEvent.data.scrollEnd.inertialPhase = WebGestureEvent::NonMomentumPhase;
    //     webGestureEvent.data.scrollEnd.deltaUnits = WebGestureEvent::Pixels;
    //     m_webWidget->handleInputEvent(webGestureEvent);

    return 0;
}

void PlatformEventHandler::buildMousePosInfo(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, bool* handle, gfx::Point* pos, gfx::Point* globalPos)
{
    if (WM_MOUSELEAVE == message) {
        *handle = true;
        m_postMouseLeave = true;

        POINT ptCursor;
        ::GetCursorPos(&ptCursor);
        *globalPos = gfx::Point(ptCursor.x, ptCursor.y);
        ::ScreenToClient(hWnd, &ptCursor);

        if (ptCursor.x < 2)
            ptCursor.x = -1;
        else if (ptCursor.x > 10)
            ptCursor.x += 2;

        if (ptCursor.y < 2)
            ptCursor.y = -1;
        else if (ptCursor.y > 10)
            ptCursor.y += 2;

        *pos = gfx::Point(ptCursor.x, ptCursor.y);

        lParam = MAKELPARAM(ptCursor.x, ptCursor.y);
    } else {
        m_postMouseLeave = false;
        pos->set_x(/*m_offset.x() +*/ ((int)(short)LOWORD(lParam)));
        pos->set_y(/*m_offset.y() +*/ ((int)(short)HIWORD(lParam)));

        POINT widgetPoint = { pos->x(), pos->y() };
#if defined(WIN32)
        ::ClientToScreen(hWnd, &widgetPoint);
#endif
        *globalPos = gfx::Point(widgetPoint.x, widgetPoint.y);
    }
}

// 中文输入法下，按下两个ww键，会有如下消息：
// WM_IME_STARTCOMPOSITION
// WM_IME_COMPOSITION : 77
// WM_IME_COMPOSITION : 77
// WM_IME_COMPOSITION : 5916
// WM_IME_CHAR : 5916
// WM_IME_CHAR : 7f51
// WM_IME_ENDCOMPOSITION
// 说明先来两个'w'的WM_IME_COMPOSITION消息，然后是两个WM_IME_CHAR中文消息（UTF16外网），最后是WM_IME_ENDCOMPOSITION
void PlatformEventHandler::fireImeComposition(ImeCompositioHandleType type, WCHAR c)
{
    gfx::Range range((size_t)(0xffffffff), (size_t)(0xffffffff));

    m_lock.Acquire();
    if (!(m_blinkWidgetInputHandler.is_bound() && m_blinkWidgetInputHandler.is_connected())) {
        m_lock.Release();
        return;
    }

    if (kImeCompositioHandleTypeStart == type && c != 0) {
        m_imeTextCache.clear();
    } else if (kImeCompositioHandleTypeCom == type && c != 0) {
        ui::ImeTextSpan textSpan(
            ui::ImeTextSpan::Type::kComposition,
            /*size_t start_offset =*/ 0,
            /*size_t end_offset =*/ 1,
            ui::ImeTextSpan::Thickness::kThin,
            ui::ImeTextSpan::UnderlineStyle::kSolid,
            SK_ColorTRANSPARENT,
            SK_ColorTRANSPARENT,
            std::vector<std::string>(),
            SK_ColorTRANSPARENT);
        WTF::Vector<::ui::ImeTextSpan> imeTextSpans;
        imeTextSpans.push_back(textSpan);

        int32_t selectionStart = 1;
        int32_t selectionEnd = 1;

        WTF::String imeText(base::span<const UChar>((const UChar*)(&c), (size_t)1));
        m_blinkWidgetInputHandler->ImeSetComposition(imeText, imeTextSpans, range, selectionStart, selectionEnd, base::BindOnce([] {}));
    } else if (kImeCompositioHandleTypeEnd == type && !m_imeTextCache.empty()) {
        WTF::Vector<::ui::ImeTextSpan> imeTextSpans2;

        WTF::String imeText(base::span<const UChar>((const UChar*)m_imeTextCache.data(), m_imeTextCache.size()));
        m_blinkWidgetInputHandler->ImeCommitText(imeText, imeTextSpans2, range, 0, base::BindOnce([] {}));
        m_imeTextCache.clear();
    } else if (kImeCompositioHandleTypeChar == type) {
        m_imeTextCache.push_back(c);
    }

    m_lock.Release();
}

void PlatformEventHandler::fireInputEventToCompositingThread(const blink::WebInputEvent& evt)
{
    if (evt.GetType() == blink::WebInputEvent::Type::kKeyDown)
        OutputDebugStringA("kKeyDown\n");

    scoped_refptr<base::SingleThreadTaskRunner> runner = blink::ThreadScheduler::CompositorThreadScheduler()->InputTaskRunner();
    std::unique_ptr<blink::WebInputEvent> newEvt = evt.Clone();

    if (m_isDispatchDirectlyToWidget || runner->BelongsToCurrentThread()) {
        std::unique_ptr<blink::WebCoalescedInputEvent> event = std::make_unique<blink::WebCoalescedInputEvent>(std::move(evt), ui::LatencyInfo());
        m_lock.Acquire();
        if (m_blinkWidgetInputHandler.is_bound() && m_blinkWidgetInputHandler.is_connected())
            m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::move(event)); // TODO: 没考虑跨进程被析构的情况
        m_lock.Release();
    } else {
        runner->PostTask(FROM_HERE,
            base::BindOnce(
                [](PlatformEventHandler* self, std::unique_ptr<blink::WebInputEvent> evt) {
                    std::unique_ptr<blink::WebCoalescedInputEvent> event = std::make_unique<blink::WebCoalescedInputEvent>(std::move(evt), ui::LatencyInfo());
                    self->m_lock.Acquire();
                    if (self->m_blinkWidgetInputHandler.is_bound() && self->m_blinkWidgetInputHandler.is_connected())
                        self->m_blinkWidgetInputHandler->DispatchNonBlockingEvent(std::move(event)); // TODO: 没考虑跨进程被析构的情况
                    self->m_lock.Release();
                },
                base::Unretained(this), std::move(newEvt)));
    }
}

// src\ui\events\blink\blink_event_util.cc
// src\ui\events\win\events_win.cc
// src\ui\events\keycodes\dom\keycode_converter.cc
static void buildModifiers(blink::WebInputEvent* evt)
{
    // weolar
    //     if (GetKeyState(VK_SHIFT) & HIGH_BIT_MASK_SHORT)
    //         evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::ShiftKey));
    if (GetKeyState(VK_CONTROL) & HIGH_BIT_MASK_SHORT)
        evt->SetModifiers(evt->GetModifiers() | ((int)blink::WebInputEvent::kControlKey));
    //     if (GetKeyState(VK_MENU) & HIGH_BIT_MASK_SHORT)
    //         evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::AltKey));
    //     if (isCapsLockOn())
    //         evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::CapsLockOn));
    //     if (isNumLockOn())
    //         evt->setModifiers(evt->modifiers() | ((int)WebInputEvent::NumLockOn));
}

static void postDragMessage(HWND hWnd)
{
    HWND hRootWnd = hWnd;
    while (true) {
        hWnd = ::GetParent(hWnd);
        if (!hWnd)
            break;
        hRootWnd = hWnd;
    }

    if (!hRootWnd)
        return;

    if (!/*blink::RuntimeEnabledFeatures::updataInOtherThreadEnabled()*/ true) {
        postDragMessageImpl(hRootWnd, nullptr);
        return;
    }

    //     if (wke::g_wkeUiThreadPostTaskCallback)
    //         wke::g_wkeUiThreadPostTaskCallback(hRootWnd, postDragMessageImpl, nullptr);
}

void PlatformEventHandler::checkMouseLeave()
{
    if (!m_hWnd || !::IsWindow(m_hWnd)) {
        m_checkMouseLeaveTimer->Stop();
        return;
    }

    POINT pt = { 0 };
    ::GetCursorPos(&pt);

    RECT rc;
    ::GetClientRect(m_hWnd, &rc);
    ::ScreenToClient(m_hWnd, &pt);

    if ((!::PtInRect(&rc, pt) || !::IsWindowVisible(m_hWnd))) {
        if (!m_isLeftMousedown) {
            MouseEvtInfo info = { true, false };
            LPARAM lParam = MAKELONG(pt.x, pt.y);

            //             if (m_enableTouchSimulate)
            //                 fireTouchEvent(m_hWnd, WM_MOUSELEAVE, lParam, 0);

            fireMouseEvent(m_hWnd, WM_MOUSELEAVE, 0, lParam, info, nullptr);
        }
        m_checkMouseLeaveTimer->Stop();
    }
}

// 鼠标点击标题栏时，收不到up消息，所以要模拟一次
bool PlatformEventHandler::fireMouseUpEventIfNeeded(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle)
{
    if ((WM_MOUSEMOVE != message && WM_MOUSELEAVE != message) || !m_isLeftMousedown)
        return false;

    if ((wParam & MK_LBUTTON))
        return false;

    fireMouseEvent(hWnd, WM_LBUTTONUP, 0, lParam, info, nullptr);
    if (bHandle)
        *bHandle = true;
    return true;
}

static void setFocusOnBlinkThread(int64_t webviewid, HWND hWnd, blink::WebViewImpl* webViewImpl)
{
    ThreadCall::callBlinkThreadAsyncWithValid(MB_FROM_HERE, webviewid, [hWnd, webViewImpl](MbWebView* self) {
        ::SetFocus(hWnd);
        webViewImpl->MainFrameWidget()->SetFocus(true);
        webViewImpl->SetIsActive(true);
    });
}

// 本函数执行在合成线程
LRESULT PlatformEventHandler::fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle)
{
    m_hWnd = hWnd;
    bool handle = false;

    m_isDraggableRegionNcHitTest = false;
    if (true == m_isAlert)
        return 0;

    bool isValideWindow = ::IsWindow(hWnd) && !info.isWillDestroy;

    if (fireMouseUpEventIfNeeded(hWnd, message, wParam, lParam, info, bHandle))
        return 0;

    bool shift = false, ctrl = false, alt = false, meta = false;
    int clickCount = 0;

    gfx::Point pos;
    gfx::Point globalPos;

    buildMousePosInfo(hWnd, message, wParam, lParam, &handle, &pos, &globalPos);

#if defined(WIN32)
    if (WM_MOUSELEAVE != message) {
        if (!m_checkMouseLeaveTimer)
            m_checkMouseLeaveTimer = std::make_unique<base::RepeatingTimer>();
        m_checkMouseLeaveTimer->Stop();
        m_checkMouseLeaveTimer->Start(FROM_HERE, base::Microseconds(200), base::BindRepeating(&PlatformEventHandler::checkMouseLeave, base::Unretained(this)));
    }
#endif

    base::TimeTicks time = base::TimeTicks::Now();

    blink::WebMouseEvent webMouseEvent;
    webMouseEvent.SetModifiers(0);
    webMouseEvent.SetPositionInWidget(gfx::PointF(pos.x(), pos.y()));
    webMouseEvent.SetPositionInScreen(gfx::PointF(globalPos.x(), globalPos.y()));
    webMouseEvent.SetTimeStamp(time);
    webMouseEvent.pointer_type = blink::WebPointerProperties::PointerType::kMouse;
    webMouseEvent.movement_x = pos.x() - m_lastPosMouseMove.x();
    webMouseEvent.movement_y = pos.y() - m_lastPosMouseMove.y();
    m_lastPosMouseMove = pos;

    webMouseEvent.click_count = 1;
    buildModifiers(&webMouseEvent);

    if (WM_LBUTTONDOWN == message || WM_MBUTTONDOWN == message || WM_RBUTTONDOWN == message || WM_LBUTTONDBLCLK == message) {
        handle = true;

        const static int64_t minInterval = GetDoubleClickTime() * 360;
        int64_t ticks = time.ToInternalValue() - m_lastTimeMouseDown;

        if (ticks < minInterval && isNearPos(m_lastPosMouseDown, pos))
            webMouseEvent.click_count = 2;

        m_lastTimeMouseDown = time.ToInternalValue();
        m_lastPosMouseDown = pos;

        if (hWnd && info.isNeedSetFocus) {
            if (m_webViewImpl && isValideWindow && ::GetFocus() != hWnd) {
                setFocusOnBlinkThread(m_webviewid, hWnd, m_webViewImpl);
            }
            //             if (wke::g_enableNativeSetCapture && isValideWindow)
            //                 ::SetCapture(hWnd);
        }
        switch (message) {
        case WM_LBUTTONDOWN:
        case WM_LBUTTONDBLCLK:
            m_isLeftMousedown = true;
            webMouseEvent.button = blink::WebPointerProperties::Button::kLeft;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebMouseEvent::kLeftButtonDown);
            break;
        case WM_MBUTTONDOWN:
            webMouseEvent.button = blink::WebPointerProperties::Button::kMiddle;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebMouseEvent::kMiddleButtonDown);
            break;
        case WM_RBUTTONDOWN:
            webMouseEvent.button = blink::WebPointerProperties::Button::kRight;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebMouseEvent::kRightButtonDown);
            break;
        }
        m_isDraggableRegionNcHitTest = false;
        webMouseEvent.SetType(blink::mojom::EventType::kMouseDown);
        fireInputEventToCompositingThread(webMouseEvent);

#if 0 // def _WIN32
        bool isDraggable = false;
        if (WM_LBUTTONDOWN == message)
            isDraggable = isDraggableRegionNcHitTest(hWnd, pos, info.draggableRegion);

        if (isValideWindow && isDraggable)
            postDragMessage(hWnd);
#endif
        m_isDraggableNodeMousedown = false;
    } else if (WM_LBUTTONUP == message || WM_MBUTTONUP == message || WM_RBUTTONUP == message) {
        handle = true;

        switch (message) {
        case WM_LBUTTONUP:
            m_isLeftMousedown = false;
            webMouseEvent.button = blink::WebPointerProperties::Button::kLeft;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebMouseEvent::kLeftButtonDown);
            break;
        case WM_MBUTTONUP:
            webMouseEvent.button = blink::WebPointerProperties::Button::kMiddle;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebMouseEvent::kMiddleButtonDown);
            break;
        case WM_RBUTTONUP:
            webMouseEvent.button = blink::WebPointerProperties::Button::kRight;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebMouseEvent::kRightButtonDown);
            break;
        }
        if (isValideWindow)
            ::ReleaseCapture();
        if (info.renderWidgetHost && info.renderWidgetHost->m_frameWidget) {
            info.renderWidgetHost->m_frameWidget->DragSourceSystemDragEnded();
        }
        webMouseEvent.SetType(blink::mojom::EventType::kMouseUp);
        fireInputEventToCompositingThread(webMouseEvent);
    } else if (WM_MOUSEMOVE == message || WM_MOUSELEAVE == message) {
        handle = true;
        if (wParam & MK_LBUTTON) {
            webMouseEvent.button = blink::mojom::Button::kLeft;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebInputEvent::kLeftButtonDown);
        } else if (wParam & MK_MBUTTON) {
            webMouseEvent.button = blink::mojom::Button::kMiddle;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebInputEvent::kMiddleButtonDown);
        } else if (wParam & MK_RBUTTON) {
            webMouseEvent.button = blink::mojom::Button::kRight;
            webMouseEvent.SetModifiers(webMouseEvent.GetModifiers() | blink::WebInputEvent::kRightButtonDown);
        } else {
            CHECK(!m_isLeftMousedown);
            webMouseEvent.button = blink::mojom::Button::kEraser;
        }

        bool b = false;
        switch (message) {
        case WM_MOUSEMOVE:
            if (!m_mouseInWindow) {
                webMouseEvent.SetType(blink::mojom::EventType::kMouseEnter);
                m_mouseInWindow = true;
            } else
                webMouseEvent.SetType(blink::mojom::EventType::kMouseMove);

            fireInputEventToCompositingThread(webMouseEvent);
            break;
        case WM_MOUSELEAVE:
            webMouseEvent.SetType(blink::mojom::EventType::kMouseLeave);

            if (info.renderWidgetHost && info.renderWidgetHost->m_frameWidget) {
                info.renderWidgetHost->m_frameWidget->DragSourceSystemDragEnded(
                    //                     gfx::PointF(pos.x(), pos.y()),
                    //                     gfx::PointF(globalPos.x(), globalPos.y()),
                    //                     ::ui::mojom::blink::DragOperation::kNone,
                    //                     blink::mojom::blink::FrameWidget::DragSourceEndedAtCallback()
                );
            }
            fireInputEventToCompositingThread(webMouseEvent);
            m_mouseInWindow = false;
            break;
        }
    }

    if (bHandle)
        *bHandle = handle;
    return 0;
}

static void buildDomCode(blink::WebKeyboardEvent* keyEvent)
{
    int domCode = keyEvent->dom_code;
    if (VK_CONTROL == domCode) {
        keyEvent->dom_code = (int)ui::DomCode::CONTROL_LEFT;
    } else if (VK_SHIFT == domCode) {
        keyEvent->dom_code = (int)ui::DomCode::SHIFT_LEFT;
    } else if (VK_MENU == domCode) {
        keyEvent->dom_code = (int)ui::DomCode::ALT_LEFT;
    } else if (VK_TAB == domCode) {
        keyEvent->dom_code = (int)ui::DomCode::TAB;
    } else if (VK_CAPITAL == domCode) {
        keyEvent->dom_code = (int)ui::DomCode::CAPS_LOCK;
    } else if (0x30 <= domCode && domCode <= 0x39) {
        keyEvent->dom_code = domCode - 0x31 + (int)ui::DomCode::DIGIT1;
    } else if (0x41 <= domCode && domCode <= 0x5A) {
        keyEvent->dom_code = domCode + (int)ui::DomCode::US_A - (int)'A';
    } else if (VK_NUMPAD0 <= domCode && domCode <= VK_NUMPAD9) {
        keyEvent->dom_code = domCode - VK_NUMPAD0 - 1 + (int)ui::DomCode::NUMPAD1;
    } else if (VK_F1 <= domCode && domCode <= VK_F12) {
        keyEvent->dom_code = domCode - VK_F1 + (int)ui::DomCode::F1;
    } else if (VK_F13 <= domCode && domCode <= VK_F24) {
        keyEvent->dom_code = domCode - VK_F13 + (int)ui::DomCode::F13;
    }
}

static uint32_t windowsKeyCodeToDomKey(int windowsKeyCode)
{
    if (0x0008 == windowsKeyCode || 0x0009 == windowsKeyCode ||
        0x000D == windowsKeyCode || 0x001B == windowsKeyCode || 0x001B == 0x007F)
        return windowsKeyCode | 0x400000;
    return  windowsKeyCode | 0x200000;
}

blink::WebKeyboardEvent PlatformEventHandler::buildKeyboardEvent(blink::WebInputEvent::Type type, UINT message, WPARAM wParam, LPARAM lParam)
{
    base::TimeTicks time = base::TimeTicks::Now();
    LPARAM keyData = lParam; // MAKELPARAM(0, (WORD)flags);
    blink::WebKeyboardEvent keyEvent;
    keyEvent.windows_key_code = (type == blink::WebInputEvent::Type::kRawKeyDown || type == blink::WebInputEvent::Type::kKeyUp) ? wParam : 0;
    keyEvent.native_key_code = wParam;
    keyEvent.dom_code = (keyEvent.windows_key_code);
    keyEvent.dom_key = windowsKeyCodeToDomKey(keyEvent.windows_key_code);
    buildDomCode(&keyEvent);
    keyEvent.SetTimeStamp(time);
    //keyEvent.SetSize(sizeof(WebKeyboardEvent));
    keyEvent.SetType(type);

    buildModifiers(&keyEvent);

    if (isKeypadEvent(wParam, keyData, type))
        keyEvent.SetModifiers(keyEvent.GetModifiers() | blink::WebInputEvent::kIsKeyPad);

        //printf("PlatformEventHandler::buildKeyboardEvent: %x\n", keyEvent.modifiers());

        //     char* output = (char*)malloc(0x100);
        //     sprintf(output, "PlatformEventHandler::buildKeyboardEvent: modifiers:%x, windows_key_code:%x\n", keyEvent.GetModifiers(), keyEvent.windows_key_code);
        //     OutputDebugStringA(output);
        //     free(output);

#if defined(OS_WIN)
    if (VK_LEFT == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"Left");
    else if (VK_UP == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"Up");
    else if (VK_RIGHT == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"Right");
    else if (VK_DOWN == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"Down");

    else if (VK_NEXT == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"PageDown");
    else if (VK_PRIOR == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"PageUp");

    else if (VK_HOME == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"Home");
    else if (VK_END == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"End");

    else if (VK_TAB == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"U+0009");
    else if (VK_BACK == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"U+0008");
    else if (VK_ESCAPE == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"U+001B");
    else if (VK_RETURN == keyEvent.windows_key_code)
        wcscpy((WCHAR*)keyEvent.text.data(), L"Enter");
#endif
    memset((WCHAR*)keyEvent.text.data(), 0, sizeof(char16_t) * blink::WebKeyboardEvent::kTextLengthCap);
    keyEvent.text[0] = (char16_t)wParam;
    return keyEvent;
}

}