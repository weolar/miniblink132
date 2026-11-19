// Copyright (C) 2006-2013 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132 (Mouse / Wheel / Keyboard / IME input).

#include "content/renderer/npapi/WebPluginImpl.h"

#include <algorithm>
#include <cmath>

#include "base/strings/utf_string_conversions.h"
#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "content/renderer/npapi/WebPluginImeWin.h"
#include "third_party/blink/public/common/input/web_coalesced_input_event.h"
#include "third_party/blink/public/common/input/web_input_event.h"
#include "third_party/blink/public/common/input/web_keyboard_event.h"
#include "third_party/blink/public/common/input/web_mouse_event.h"
#include "third_party/blink/public/common/input/web_mouse_wheel_event.h"
#include "third_party/blink/public/web/web_plugin_container.h"
#include "ui/base/cursor/cursor.h"
#include "ui/base/cursor/mojom/cursor_type.mojom-shared.h"
#include "ui/base/ime/ime_text_span.h"

namespace content {

namespace {

#if defined(_WIN32)
ui::Cursor hcursorToUiCursor(HCURSOR hCursor)
{
    static const struct {
        LPCWSTR idc;
        ui::mojom::CursorType type;
    } kCursorMap[] = {
        { IDC_HAND, ui::mojom::CursorType::kHand },
        { IDC_IBEAM, ui::mojom::CursorType::kIBeam },
        { IDC_WAIT, ui::mojom::CursorType::kWait },
        { IDC_APPSTARTING, ui::mojom::CursorType::kProgress },
        { IDC_CROSS, ui::mojom::CursorType::kCross },
        { IDC_SIZEALL, ui::mojom::CursorType::kMove },
        { IDC_SIZEWE, ui::mojom::CursorType::kEastWestResize },
        { IDC_SIZENS, ui::mojom::CursorType::kNorthSouthResize },
        { IDC_SIZENWSE, ui::mojom::CursorType::kNorthWestSouthEastResize },
        { IDC_SIZENESW, ui::mojom::CursorType::kNorthEastSouthWestResize },
        { IDC_NO, ui::mojom::CursorType::kNotAllowed },
        { IDC_HELP, ui::mojom::CursorType::kHelp },
        { IDC_ARROW, ui::mojom::CursorType::kPointer },
    };
    if (hCursor) {
        for (const auto& entry : kCursorMap) {
            if (hCursor == ::LoadCursorW(nullptr, entry.idc))
                return ui::Cursor(entry.type);
        }
    }
    return ui::Cursor(ui::mojom::CursorType::kPointer);
}
#endif

} // namespace

void WebPluginImpl::syncImeCaretPos()
{
    if (!m_pluginIme || !m_pluginContainer || !m_mbwebviewId)
        return;
    int inputType = 0;
    gfx::Rect caretRect;
    if (!m_pluginIme->getStatus(&inputType, &caretRect) || caretRect.IsEmpty())
        return;
    auto* webview = static_cast<MbWebView*>(common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId));
    if (!webview)
        return;
    gfx::Point rootPt = m_pluginContainer->LocalToRootFramePoint(caretRect.origin());
    webview->setCaretPos(rootPt);
}

void WebPluginImpl::UpdateFocus(bool focused, blink::mojom::FocusType)
{
    if (!m_plugin || !m_plugin->pluginFuncs()->event || !m_instance)
        return;

#if defined(_WIN32)
    scoped_refptr<WebPluginImpl> protect(this);
    NPEvent focusEvent {};
    focusEvent.event = focused ? WM_SETFOCUS : WM_KILLFOCUS;
    focusEvent.wParam = 0;
    focusEvent.lParam = 0;

    if (!m_pluginIme && m_plugin->quirks().contains(PluginQuirkEmulateIme))
        m_pluginIme = std::make_unique<WebPluginIMEWin>();

    WebPluginIMEWin::ScopedLock imeLock(m_pluginIme.get());
    dispatchNPEvent(focusEvent);
    if (focused)
        syncImeCaretPos();
#endif
}

bool WebPluginImpl::handleMouseEvent(const blink::WebInputEvent& rawEvent, ui::Cursor* cursor)
{
#if defined(_WIN32)
    if (!m_plugin || m_isWindowed)
        return false;

    scoped_refptr<WebPluginImpl> protect(this);
    const auto& evt = static_cast<const blink::WebMouseEvent&>(rawEvent);
    NPEvent npEvent {};

    // paintIntoTransformedContext positions windowless Flash at local (0, 0),
    // and WebPluginContainerImpl delivers PositionInWidget() in plugin-local coordinates.
    blink::WebInputEvent::Type type = evt.GetType();
    int x = -1;
    int y = -1;
    if (type != blink::WebInputEvent::Type::kMouseLeave) {
        gfx::PointF localPt = evt.PositionInWidget();
        x = static_cast<int>(localPt.x());
        y = static_cast<int>(localPt.y());
    }
    npEvent.lParam = MAKELPARAM(x, y);
    npEvent.wParam = 0;

    int mods = evt.GetModifiers();
    if (mods & blink::WebInputEvent::kControlKey)
        npEvent.wParam |= MK_CONTROL;
    if (mods & blink::WebInputEvent::kShiftKey)
        npEvent.wParam |= MK_SHIFT;
    if (mods & blink::WebInputEvent::kLeftButtonDown)
        npEvent.wParam |= MK_LBUTTON;
    if (mods & blink::WebInputEvent::kMiddleButtonDown)
        npEvent.wParam |= MK_MBUTTON;
    if (mods & blink::WebInputEvent::kRightButtonDown)
        npEvent.wParam |= MK_RBUTTON;

    if (type == blink::WebInputEvent::Type::kMouseMove
        || type == blink::WebInputEvent::Type::kMouseLeave
        || type == blink::WebInputEvent::Type::kMouseEnter) {
        npEvent.event = WM_MOUSEMOVE;
    } else if (type == blink::WebInputEvent::Type::kMouseDown) {
        bool isDoubleClick = (evt.click_count >= 2);
        switch (evt.button) {
        case blink::WebPointerProperties::Button::kLeft:
            npEvent.event = isDoubleClick ? WM_LBUTTONDBLCLK : WM_LBUTTONDOWN;
            break;
        case blink::WebPointerProperties::Button::kMiddle:
            npEvent.event = isDoubleClick ? WM_MBUTTONDBLCLK : WM_MBUTTONDOWN;
            break;
        case blink::WebPointerProperties::Button::kRight:
            if (m_plugin->quirks().contains(PluginQuirkIgnoreRightClickInWindowlessMode))
                return false;
            npEvent.event = isDoubleClick ? WM_RBUTTONDBLCLK : WM_RBUTTONDOWN;
            break;
        default:
            return false;
        }
    } else if (type == blink::WebInputEvent::Type::kMouseUp) {
        switch (evt.button) {
        case blink::WebPointerProperties::Button::kLeft:
            npEvent.event = WM_LBUTTONUP;
            break;
        case blink::WebPointerProperties::Button::kMiddle:
            npEvent.event = WM_MBUTTONUP;
            break;
        case blink::WebPointerProperties::Button::kRight:
            npEvent.event = WM_RBUTTONUP;
            break;
        default:
            return false;
        }
    } else if (type == blink::WebInputEvent::Type::kMouseWheel) {
        const auto& wheelEvt = static_cast<const blink::WebMouseWheelEvent&>(rawEvent);
        npEvent.event = WM_MOUSEWHEEL;
        int wheelDeltaInt = 0;
        if (wheelEvt.wheel_ticks_y != 0.0f) {
            wheelDeltaInt = static_cast<int>(std::lround(wheelEvt.wheel_ticks_y * WHEEL_DELTA));
        } else if (wheelEvt.delta_y != 0.0f) {
            wheelDeltaInt = (wheelEvt.delta_y > 0.0f)
                ? std::max<int>(WHEEL_DELTA, static_cast<int>(std::lround(wheelEvt.delta_y)))
                : std::min<int>(-WHEEL_DELTA, static_cast<int>(std::lround(wheelEvt.delta_y)));
        }
        short wheelDelta = static_cast<short>(std::clamp(wheelDeltaInt, -32768, 32767));
        npEvent.wParam = MAKEWPARAM(LOWORD(npEvent.wParam), static_cast<WORD>(wheelDelta));
    } else {
        return false;
    }

    if (!m_pluginIme && m_plugin->quirks().contains(PluginQuirkEmulateIme))
        m_pluginIme = std::make_unique<WebPluginIMEWin>();
    WebPluginIMEWin::ScopedLock imeLock(m_pluginIme.get());

    bool handled = dispatchNPEvent(npEvent);

    if (cursor && m_isStarted && type != blink::WebInputEvent::Type::kMouseWheel
        && type != blink::WebInputEvent::Type::kMouseLeave) {
        HCURSOR beforeCursor = ::GetCursor();
        NPEvent cursorEvent {};
        cursorEvent.event = WM_SETCURSOR;
        cursorEvent.wParam = reinterpret_cast<uintptr_t>(m_parentWidget);
        cursorEvent.lParam = MAKELPARAM(HTCLIENT, npEvent.event);
        bool cursorHandled = dispatchNPEvent(cursorEvent);
        HCURSOR afterCursor = ::GetCursor();
        if (cursorHandled || afterCursor != beforeCursor) {
            *cursor = hcursorToUiCursor(afterCursor);
        }
    }

    if (type == blink::WebInputEvent::Type::kMouseDown || type == blink::WebInputEvent::Type::kMouseUp)
        syncImeCaretPos();

    return handled;
#else
    return false;
#endif
}

bool WebPluginImpl::handleKeyboardCharEventForEmulateIme(int windowsKeyCode)
{
#if defined(_WIN32)
    if (!m_plugin || !m_instance)
        return false;
    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);
    if (!m_pluginIme && m_plugin->quirks().contains(PluginQuirkEmulateIme))
        m_pluginIme = std::make_unique<WebPluginIMEWin>();
    if (!m_pluginIme)
        return false;

    char16_t ch = static_cast<char16_t>(windowsKeyCode);
    std::u16string text(1, ch);
    std::vector<int> clauses { 0, 1 };
    std::vector<int> target;
    m_pluginIme->compositionUpdated(text, clauses, target, 1);
    m_pluginIme->compositionCompleted(text);
    m_pluginIme->sendEvents(m_instance, m_plugin->pluginFuncs()->event);
    syncImeCaretPos();
    return true;
#else
    return false;
#endif
}

bool WebPluginImpl::handleKeyboardEvent(const blink::WebKeyboardEvent& evt)
{
#if defined(_WIN32)
    if (!m_plugin || m_isWindowed)
        return false;

    scoped_refptr<WebPluginImpl> protect(this);
    if (!m_pluginIme && m_plugin->quirks().contains(PluginQuirkEmulateIme))
        m_pluginIme = std::make_unique<WebPluginIMEWin>();
    WebPluginIMEWin::ScopedLock lock(m_pluginIme.get());

    blink::WebInputEvent::Type type = evt.GetType();
    int mods = evt.GetModifiers();
    bool isAltDown = (mods & blink::WebInputEvent::kAltKey) != 0;
    bool isSysKey = isAltDown && !(mods & blink::WebInputEvent::kControlKey);

    NPEvent npEvent {};
    if (type == blink::WebInputEvent::Type::kChar) {
        int charCode = evt.text[0] ? evt.text[0] : evt.windows_key_code;
        if (m_plugin->quirks().contains(PluginQuirkEmulateIme) && charCode > 0x7F) {
            return handleKeyboardCharEventForEmulateIme(charCode);
        }
        SHORT vkScan = ::VkKeyScanW(static_cast<WCHAR>(charCode));
        UINT scanCode = (vkScan != -1) ? (::MapVirtualKeyW(static_cast<UINT>(vkScan & 0xFF), MAPVK_VK_TO_VSC) & 0xFF) : 0;
        uintptr_t charLParam = 1u | (static_cast<uintptr_t>(scanCode) << 16);
        if (isAltDown)
            charLParam |= (1u << 29);
        npEvent.event = isSysKey ? WM_SYSCHAR : WM_CHAR;
        npEvent.wParam = charCode;
        npEvent.lParam = charLParam;
        bool handled = dispatchNPEvent(npEvent);
        syncImeCaretPos();
        return handled;
    }

    UINT scanCode = ::MapVirtualKeyW(static_cast<UINT>(evt.windows_key_code), MAPVK_VK_TO_VSC) & 0xFF;
    uintptr_t baseLParam = 1u | (static_cast<uintptr_t>(scanCode) << 16);
    if ((mods & blink::WebInputEvent::kIsKeyPad) && evt.windows_key_code == VK_RETURN)
        baseLParam |= (1u << 24);
    switch (evt.windows_key_code) {
    case VK_PRIOR:
    case VK_NEXT:
    case VK_END:
    case VK_HOME:
    case VK_LEFT:
    case VK_UP:
    case VK_RIGHT:
    case VK_DOWN:
    case VK_INSERT:
    case VK_DELETE:
    case VK_RCONTROL:
    case VK_RMENU:
    case VK_DIVIDE:
    case VK_NUMLOCK:
    case VK_SNAPSHOT:
    case VK_LWIN:
    case VK_RWIN:
    case VK_APPS:
        baseLParam |= (1u << 24);
        break;
    default:
        break;
    }
    if (isAltDown)
        baseLParam |= (1u << 29);

    npEvent.wParam = evt.windows_key_code;
    if (type == blink::WebInputEvent::Type::kRawKeyDown || type == blink::WebInputEvent::Type::kKeyDown) {
        npEvent.event = isSysKey ? WM_SYSKEYDOWN : WM_KEYDOWN;
        npEvent.lParam = baseLParam;
        if (mods & blink::WebInputEvent::kIsAutoRepeat)
            npEvent.lParam |= (1u << 30);
    } else if (type == blink::WebInputEvent::Type::kKeyUp) {
        npEvent.event = isSysKey ? WM_SYSKEYUP : WM_KEYUP;
        npEvent.lParam = baseLParam | 0xC0000000u;
    } else {
        return false;
    }

    bool handled = dispatchNPEvent(npEvent);
    syncImeCaretPos();
    return handled;
#else
    return false;
#endif
}

blink::WebInputEventResult WebPluginImpl::HandleInputEvent(
    const blink::WebCoalescedInputEvent& coalescedEvent, ui::Cursor* cursor)
{
    if (m_isWindowed)
        return blink::WebInputEventResult::kNotHandled;

    const blink::WebInputEvent& evt = coalescedEvent.Event();
    blink::WebInputEvent::Type type = evt.GetType();

    if (blink::WebInputEvent::IsMouseEventType(type) || type == blink::WebInputEvent::Type::kMouseWheel) {
        return handleMouseEvent(evt, cursor)
            ? blink::WebInputEventResult::kHandledApplication
            : blink::WebInputEventResult::kNotHandled;
    }

    if (blink::WebInputEvent::IsKeyboardEventType(type)) {
        return handleKeyboardEvent(static_cast<const blink::WebKeyboardEvent&>(evt))
            ? blink::WebInputEventResult::kHandledApplication
            : blink::WebInputEventResult::kNotHandled;
    }

    return blink::WebInputEventResult::kNotHandled;
}

bool WebPluginImpl::getImeStatus(int* inputType, gfx::Rect* caretRect)
{
    if (!m_pluginIme)
        return false;
    return m_pluginIme->getStatus(inputType, caretRect);
}

bool WebPluginImpl::SetComposition(const blink::WebString& text, const blink::WebVector<ui::ImeTextSpan>& imeTextSpans,
    const blink::WebRange& /*replacementRange*/, int /*selectionStart*/, int selectionEnd)
{
    if (!m_plugin || !m_instance)
        return false;
    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);
    if (!m_pluginIme && m_plugin->quirks().contains(PluginQuirkEmulateIme))
        m_pluginIme = std::make_unique<WebPluginIMEWin>();
    if (!m_pluginIme)
        return false;

    std::u16string text16 = text.Utf16();
    std::vector<int> clauses;
    std::vector<int> target;
    auto pushClause = [&clauses](int offset) {
        if (clauses.empty() || clauses.back() < offset)
            clauses.push_back(offset);
    };
    pushClause(0);
    for (const auto& span : imeTextSpans) {
        pushClause(static_cast<int>(span.start_offset));
        pushClause(static_cast<int>(span.end_offset));
        if (span.thickness == ui::ImeTextSpan::Thickness::kThick) {
            target = { static_cast<int>(span.start_offset), static_cast<int>(span.end_offset) };
        }
    }
    pushClause(static_cast<int>(text16.size()));

    m_pluginIme->compositionUpdated(text16, clauses, target, selectionEnd);
    m_pluginIme->sendEvents(m_instance, m_plugin->pluginFuncs()->event);
    syncImeCaretPos();
    return true;
}

bool WebPluginImpl::CommitText(const blink::WebString& text, const blink::WebVector<ui::ImeTextSpan>& /*imeTextSpans*/,
    const blink::WebRange& /*replacementRange*/, int /*relativeCaretPosition*/)
{
    if (!m_plugin || !m_instance)
        return false;
    scoped_refptr<WebPluginImpl> protect(this);
    ScopedCurrentPluginView currentGuard(this);
    if (!m_pluginIme && m_plugin->quirks().contains(PluginQuirkEmulateIme))
        m_pluginIme = std::make_unique<WebPluginIMEWin>();
    if (!m_pluginIme)
        return false;

    m_pluginIme->compositionCompleted(text.Utf16());
    m_pluginIme->sendEvents(m_instance, m_plugin->pluginFuncs()->event);
    syncImeCaretPos();
    return true;
}

bool WebPluginImpl::FinishComposingText(blink::WebInputMethodController::ConfirmCompositionBehavior)
{
    return true;
}

} // namespace content
