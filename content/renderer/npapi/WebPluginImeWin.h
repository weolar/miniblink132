// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_WEB_PLUGIN_IME_WIN_H_
#define CONTENT_RENDERER_NPAPI_WEB_PLUGIN_IME_WIN_H_

#include <string>
#include <vector>

#include "third_party/npapi/bindings/npapi.h"
#include "third_party/npapi/bindings/npfunctions.h"
#include "ui/gfx/geometry/rect.h"
#include <windows.h>

#if defined(_WIN32)
#include <imm.h>
#else
using HIMC = void*;
struct CANDIDATEFORM;
#endif

namespace content {

class WebPluginIMEWin {
public:
    class ScopedLock {
    public:
        explicit ScopedLock(WebPluginIMEWin* instance)
            : m_instance(instance)
        {
            if (m_instance)
                m_previousInstance = m_instance->lock();
        }
        ~ScopedLock()
        {
            if (m_instance)
                m_instance->unlock(m_previousInstance);
        }
        ScopedLock(const ScopedLock&) = delete;
        ScopedLock& operator=(const ScopedLock&) = delete;

    private:
        WebPluginIMEWin* m_instance;
        WebPluginIMEWin* m_previousInstance = nullptr;
    };

    WebPluginIMEWin();
    ~WebPluginIMEWin() = default;

    void compositionUpdated(const std::u16string& text, const std::vector<int>& clauses, const std::vector<int>& target, int cursorPosition);
    void compositionCompleted(const std::u16string& text);
    bool sendEvents(NPP instance, NPP_HandleEventProcPtr eventPtr);
    bool getStatus(int* inputType, gfx::Rect* caretRect) const;

    static bool hookGetProcAddress(HMODULE module);

private:
    WebPluginIMEWin* lock();
    void unlock(WebPluginIMEWin* previousInstance);

#if defined(_WIN32)
    static FARPROC getProcAddress(LPCSTR name);
    static FARPROC WINAPI GetProcAddressPatch(HMODULE module, LPCSTR name);
    static WebPluginIMEWin* getInstance(HIMC context);

    static BOOL WINAPI immAssociateContextEx(HWND window, HIMC context, DWORD flags);
    static LONG WINAPI immGetCompositionStringW(HIMC context, DWORD index, LPVOID dstData, DWORD dstSize);
    static HIMC WINAPI immGetContext(HWND window);
    static BOOL WINAPI immReleaseContext(HWND window, HIMC context);
    static BOOL WINAPI immSetCandidateWindow(HIMC context, CANDIDATEFORM* candidate);
    static BOOL WINAPI immSetOpenStatus(HIMC context, BOOL open);
#endif

    std::vector<NPEvent> m_events;
    std::u16string m_compositionText;
    std::u16string m_resultText;
    std::vector<uint32_t> m_compositionClauses;
    std::string m_compositionAttributes;
    int m_cursorPosition = 0;
    int m_deltaStart = 0;
    uint32_t m_resultClauses[2] = { 0, 0 };
    bool m_composingText = false;
    bool m_supportImeMessages = false;
    bool m_hasPendingFallbackResult = false;
    bool m_statusUpdated = false;
    int m_inputType = 1;
    gfx::Rect m_caretRect;

    static WebPluginIMEWin* s_instance;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_WEB_PLUGIN_IME_WIN_H_
