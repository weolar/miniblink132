// Copyright (C) 2006, 2007, 2008 Apple Inc. All Rights Reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_PLUGIN_MESSAGE_THROTTLER_WIN_H_
#define CONTENT_RENDERER_NPAPI_PLUGIN_MESSAGE_THROTTLER_WIN_H_

#include "base/timer/timer.h"
#include <windows.h>

namespace content {

class WebPluginImpl;

struct PluginMessage {
    HWND hWnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    PluginMessage* next;
};

class PluginMessageThrottlerWin {
public:
    explicit PluginMessageThrottlerWin(WebPluginImpl* pluginView);
    ~PluginMessageThrottlerWin();

    void appendMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
    void messageThrottleTimerFired();
    PluginMessage* allocateMessage();
    void freeMessage(PluginMessage* message);

    WebPluginImpl* m_pluginView;
    PluginMessage* m_back;
    PluginMessage* m_front;

    static const int kNumInlineMessages = 4;
    PluginMessage m_inlineMessages[kNumInlineMessages];
    PluginMessage* m_freeInlineMessages;

    base::OneShotTimer m_messageThrottleTimer;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_PLUGIN_MESSAGE_THROTTLER_WIN_H_
