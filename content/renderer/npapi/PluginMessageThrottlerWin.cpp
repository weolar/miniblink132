// Copyright (C) 2006, 2007, 2008 Apple Inc. All Rights Reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/PluginMessageThrottlerWin.h"

#include "base/functional/bind.h"
#include "base/time/time.h"
#include "content/renderer/npapi/WebPluginImpl.h"
#include <stdlib.h>

namespace content {

// Limit continuous messages before yielding to the Blink run loop.
static const unsigned kMaxContinuousMessages = 20;
static const int kMessageThrottleTimeMicroseconds = 1;

PluginMessageThrottlerWin::PluginMessageThrottlerWin(WebPluginImpl* pluginView)
    : m_pluginView(pluginView)
    , m_back(nullptr)
    , m_front(nullptr)
    , m_freeInlineMessages(nullptr)
{
    for (int i = 0; i < kNumInlineMessages - 1; ++i)
        m_inlineMessages[i].next = &m_inlineMessages[i + 1];
    m_inlineMessages[kNumInlineMessages - 1].next = nullptr;
    m_freeInlineMessages = &m_inlineMessages[0];
}

PluginMessageThrottlerWin::~PluginMessageThrottlerWin()
{
    m_messageThrottleTimer.Stop();
    PluginMessage* next = nullptr;
    for (PluginMessage* message = m_front; message; message = next) {
        next = message->next;
        freeMessage(message);
    }
}

void PluginMessageThrottlerWin::appendMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    PluginMessage* message = allocateMessage();
    message->hWnd = hWnd;
    message->message = msg;
    message->wParam = wParam;
    message->lParam = lParam;
    message->next = nullptr;

    if (m_back)
        m_back->next = message;
    m_back = message;
    if (!m_front)
        m_front = message;

    if (!m_messageThrottleTimer.IsRunning()) {
        m_messageThrottleTimer.Start(FROM_HERE, base::Microseconds(kMessageThrottleTimeMicroseconds),
            base::BindOnce(&PluginMessageThrottlerWin::messageThrottleTimerFired, base::Unretained(this)));
    }
}

void PluginMessageThrottlerWin::messageThrottleTimerFired()
{
    if (!m_pluginView || !m_pluginView->isStarted())
        return;

    scoped_refptr<WebPluginImpl> protect(m_pluginView);
    for (unsigned i = 0; i < kMaxContinuousMessages; ++i) {
        if (!m_front || !protect->isStarted())
            break;

        PluginMessage* message = m_front;
        m_front = message->next;
        if (message == m_back)
            m_back = nullptr;

        PluginMessage msgCopy = *message;
        freeMessage(message);

#if defined(_WIN32)
        if (WNDPROC proc = protect->pluginWndProc())
            ::CallWindowProcW(proc, msgCopy.hWnd, msgCopy.message, msgCopy.wParam, msgCopy.lParam);
#endif
        // m_messageThrottler may have been destroyed inside CallWindowProcW -> WebPluginImpl::stop().
        if (!protect->isStarted())
            return;

        if (!m_front)
            break;
    }

    if (m_front && protect->isStarted() && !m_messageThrottleTimer.IsRunning()) {
        m_messageThrottleTimer.Start(FROM_HERE, base::Microseconds(kMessageThrottleTimeMicroseconds),
            base::BindOnce(&PluginMessageThrottlerWin::messageThrottleTimerFired, base::Unretained(this)));
    }
}

PluginMessage* PluginMessageThrottlerWin::allocateMessage()
{
    PluginMessage* message = nullptr;
    if (m_freeInlineMessages) {
        message = m_freeInlineMessages;
        m_freeInlineMessages = message->next;
    } else {
        message = static_cast<PluginMessage*>(malloc(sizeof(PluginMessage)));
    }
    return message;
}

void PluginMessageThrottlerWin::freeMessage(PluginMessage* message)
{
    if (message >= &m_inlineMessages[0] && message <= &m_inlineMessages[kNumInlineMessages - 1]) {
        message->next = m_freeInlineMessages;
        m_freeInlineMessages = message;
    } else {
        free(message);
    }
}

} // namespace content
