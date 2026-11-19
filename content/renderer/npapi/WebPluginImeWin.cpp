// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/WebPluginImeWin.h"

#include <algorithm>
#include <cstring>
#include <iterator>

#include "base/strings/string_util.h"

#if defined(_WIN32)
#pragma comment(lib, "imm32.lib")
#endif

namespace content {

WebPluginIMEWin* WebPluginIMEWin::s_instance = nullptr;

namespace {
#if defined(_WIN32)
struct ImeCriticalSection {
    CRITICAL_SECTION cs;
    ImeCriticalSection() { ::InitializeCriticalSection(&cs); }
    ~ImeCriticalSection() { ::DeleteCriticalSection(&cs); }
};

CRITICAL_SECTION* getWebPluginImeLock()
{
    static ImeCriticalSection s_lock;
    return &s_lock.cs;
}

class ScopedImeCsLock {
public:
    ScopedImeCsLock() { ::EnterCriticalSection(getWebPluginImeLock()); }
    ~ScopedImeCsLock() { ::LeaveCriticalSection(getWebPluginImeLock()); }
    ScopedImeCsLock(const ScopedImeCsLock&) = delete;
    ScopedImeCsLock& operator=(const ScopedImeCsLock&) = delete;
};

DWORD WINAPI immGetPropertyStub(HKL, DWORD)
{
    return 0xd000a;
}

BOOL WINAPI immIsIMEStub(HKL)
{
    return FALSE;
}

bool patchSingleIatEntry(HMODULE hModule, const char* const* targetDllNames, size_t targetDllCount,
    LPCSTR targetFuncName, LPCVOID targetFuncAddr, LPCVOID replaceFuncAddr)
{
    if (!hModule || !replaceFuncAddr)
        return false;

    auto* baseAddr = reinterpret_cast<BYTE*>(hModule);
    auto* dosHdr = reinterpret_cast<IMAGE_DOS_HEADER*>(baseAddr);
    if (dosHdr->e_magic != IMAGE_DOS_SIGNATURE || dosHdr->e_lfanew <= 0)
        return false;

    auto* ntHdr = reinterpret_cast<IMAGE_NT_HEADERS*>(baseAddr + dosHdr->e_lfanew);
    if (ntHdr->Signature != IMAGE_NT_SIGNATURE)
        return false;

    DWORD importRva = ntHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
    if (!importRva)
        return false;

    auto* importDesc = reinterpret_cast<IMAGE_IMPORT_DESCRIPTOR*>(baseAddr + importRva);
    bool patchedAny = false;

    while (importDesc->Name != 0 && importDesc->FirstThunk != 0) {
        const char* dllName = reinterpret_cast<const char*>(baseAddr + importDesc->Name);
        bool dllMatched = false;
        for (size_t i = 0; i < targetDllCount; ++i) {
            if (base::EqualsCaseInsensitiveASCII(dllName, targetDllNames[i])) {
                dllMatched = true;
                break;
            }
        }
        if (dllMatched) {
            auto* thunkData = reinterpret_cast<IMAGE_THUNK_DATA*>(baseAddr + importDesc->FirstThunk);
            IMAGE_THUNK_DATA* origThunk = importDesc->OriginalFirstThunk
                ? reinterpret_cast<IMAGE_THUNK_DATA*>(baseAddr + importDesc->OriginalFirstThunk)
                : nullptr;

            while (thunkData->u1.Function) {
                auto* funcSlot = reinterpret_cast<ULONG_PTR*>(&thunkData->u1.Function);
                if (*funcSlot == reinterpret_cast<ULONG_PTR>(replaceFuncAddr)) {
                    patchedAny = true;
                } else {
                    bool matched = false;
                    if (origThunk && targetFuncName && !IMAGE_SNAP_BY_ORDINAL(origThunk->u1.Ordinal)) {
                        const auto* importByName = reinterpret_cast<const IMAGE_IMPORT_BY_NAME*>(
                            baseAddr + origThunk->u1.AddressOfData);
                        if (strcmp(reinterpret_cast<const char*>(importByName->Name), targetFuncName) == 0)
                            matched = true;
                    }
                    if (!matched && targetFuncAddr && *funcSlot == reinterpret_cast<ULONG_PTR>(targetFuncAddr))
                        matched = true;

                    if (matched) {
                        DWORD oldProtect = 0;
                        if (::VirtualProtect(funcSlot, sizeof(ULONG_PTR), PAGE_READWRITE, &oldProtect)) {
                            *funcSlot = reinterpret_cast<ULONG_PTR>(replaceFuncAddr);
                            ::VirtualProtect(funcSlot, sizeof(ULONG_PTR), oldProtect, &oldProtect);
                            patchedAny = true;
                        }
                    }
                }
                ++thunkData;
                if (origThunk)
                    ++origThunk;
            }
        }
        ++importDesc;
    }
    return patchedAny;
}
#endif
} // namespace

WebPluginIMEWin::WebPluginIMEWin() = default;

void WebPluginIMEWin::compositionUpdated(
    const std::u16string& text, const std::vector<int>& clauses, const std::vector<int>& target, int cursorPosition)
{
#if defined(_WIN32)
    NPEvent npEvent {};
    if (!m_composingText) {
        m_composingText = true;
        m_resultText.clear();
        npEvent.event = WM_IME_STARTCOMPOSITION;
        m_events.push_back(npEvent);
    }

    npEvent.event = WM_IME_COMPOSITION;
    npEvent.wParam = 0;
    npEvent.lParam = GCS_COMPSTR | GCS_COMPATTR | GCS_COMPCLAUSE | GCS_CURSORPOS | GCS_DELTASTART;
    m_events.push_back(npEvent);

    m_compositionText = text;
    m_compositionClauses.assign(clauses.begin(), clauses.end());

    if (target.size() == 2) {
        m_compositionAttributes.assign(text.size(), ATTR_CONVERTED);
        for (int i = target[0]; i < target[1] && i < static_cast<int>(text.size()); ++i) {
            if (i >= 0)
                m_compositionAttributes[i] = ATTR_TARGET_CONVERTED;
        }
    } else {
        m_compositionAttributes.assign(text.size(), ATTR_INPUT);
    }

    m_cursorPosition = cursorPosition;
    m_deltaStart = cursorPosition;
#endif
}

void WebPluginIMEWin::compositionCompleted(const std::u16string& text)
{
#if defined(_WIN32)
    m_composingText = false;
    m_resultText = text;
    m_resultClauses[0] = 0;
    m_resultClauses[1] = static_cast<uint32_t>(m_resultText.size());
    m_cursorPosition = m_resultClauses[1];
    m_deltaStart = m_resultClauses[1];

    NPEvent npEvent {};
    npEvent.event = WM_IME_COMPOSITION;
    npEvent.lParam = GCS_CURSORPOS | GCS_DELTASTART | GCS_RESULTSTR | GCS_RESULTCLAUSE;
    m_events.push_back(npEvent);

    npEvent.event = WM_IME_ENDCOMPOSITION;
    npEvent.lParam = 0;
    m_events.push_back(npEvent);

    // Defer WM_CHAR fallback until after WM_IME_COMPOSITION has been delivered
    // in sendEvents() so m_supportImeMessages is accurately detected on the first commit.
    m_hasPendingFallbackResult = true;
#endif
}

bool WebPluginIMEWin::sendEvents(NPP instance, NPP_HandleEventProcPtr eventPtr)
{
    if (!eventPtr)
        return false;

    std::vector<NPEvent> pendingEvents;
    pendingEvents.swap(m_events);

    ScopedLock lock(this);
    bool ret = true;
    for (auto& ev : pendingEvents) {
        if (!eventPtr(instance, &ev))
            ret = false;
    }

#if defined(_WIN32)
    if (m_hasPendingFallbackResult) {
        m_hasPendingFallbackResult = false;
        if (!m_supportImeMessages && !m_resultText.empty()) {
            NPEvent charEvent {};
            charEvent.event = WM_CHAR;
            charEvent.lParam = 0;
            for (char16_t ch : m_resultText) {
                charEvent.wParam = ch;
                if (!eventPtr(instance, &charEvent))
                    ret = false;
            }
        }
    }
#endif
    return ret;
}

bool WebPluginIMEWin::getStatus(int* inputType, gfx::Rect* caretRect) const
{
    *inputType = m_inputType;
    *caretRect = m_caretRect;
    return true;
}

WebPluginIMEWin* WebPluginIMEWin::lock()
{
#if defined(_WIN32)
    ::EnterCriticalSection(getWebPluginImeLock());
#endif
    WebPluginIMEWin* previous = s_instance;
    s_instance = this;
    return previous;
}

void WebPluginIMEWin::unlock(WebPluginIMEWin* previousInstance)
{
    s_instance = previousInstance;
#if defined(_WIN32)
    ::LeaveCriticalSection(getWebPluginImeLock());
#endif
}

bool WebPluginIMEWin::hookGetProcAddress(HMODULE module)
{
#if defined(_WIN32)
    if (!module)
        return false;

    bool patched = false;

    static const char* const kLoaderDlls[] = {
        "kernel32.dll",
        "kernelbase.dll",
        "api-ms-win-core-libraryloader-l1-2-0.dll",
        "api-ms-win-core-libraryloader-l1-1-0.dll",
    };
    FARPROC origGetProcAddress = nullptr;
    if (HMODULE kernel32 = ::GetModuleHandleA("kernel32.dll"))
        origGetProcAddress = ::GetProcAddress(kernel32, "GetProcAddress");
    if (patchSingleIatEntry(module, kLoaderDlls, std::size(kLoaderDlls), "GetProcAddress",
            reinterpret_cast<LPCVOID>(origGetProcAddress), reinterpret_cast<LPCVOID>(&WebPluginIMEWin::GetProcAddressPatch))) {
        patched = true;
    }

    // Also patch direct imm32.dll IAT entries (used by 64-bit NPSWF64.dll builds).
    static const char* const kImmDlls[] = { "imm32.dll" };
    static const struct {
        const char* name;
        FARPROC replacement;
    } kDirectImmHooks[] = {
        { "ImmAssociateContextEx", reinterpret_cast<FARPROC>(&immAssociateContextEx) },
        { "ImmGetCompositionStringW", reinterpret_cast<FARPROC>(&immGetCompositionStringW) },
        { "ImmGetContext", reinterpret_cast<FARPROC>(&immGetContext) },
        { "ImmReleaseContext", reinterpret_cast<FARPROC>(&immReleaseContext) },
        { "ImmSetCandidateWindow", reinterpret_cast<FARPROC>(&immSetCandidateWindow) },
        { "ImmSetOpenStatus", reinterpret_cast<FARPROC>(&immSetOpenStatus) },
        { "ImmIsIME", reinterpret_cast<FARPROC>(&immIsIMEStub) },
        { "ImmGetProperty", reinterpret_cast<FARPROC>(&immGetPropertyStub) },
    };
    HMODULE imm32 = ::GetModuleHandleA("imm32.dll");
    for (const auto& entry : kDirectImmHooks) {
        FARPROC origImmFn = imm32 ? ::GetProcAddress(imm32, entry.name) : nullptr;
        if (patchSingleIatEntry(module, kImmDlls, std::size(kImmDlls), entry.name,
                reinterpret_cast<LPCVOID>(origImmFn), reinterpret_cast<LPCVOID>(entry.replacement))) {
            patched = true;
        }
    }
    return patched;
#else
    return false;
#endif
}

#if defined(_WIN32)
FARPROC WebPluginIMEWin::getProcAddress(LPCSTR name)
{
    static const struct {
        const char* name;
        FARPROC function;
    } kImm32Functions[] = {
        { "ImmAssociateContextEx", reinterpret_cast<FARPROC>(&immAssociateContextEx) },
        { "ImmGetCompositionStringW", reinterpret_cast<FARPROC>(&immGetCompositionStringW) },
        { "ImmGetContext", reinterpret_cast<FARPROC>(&immGetContext) },
        { "ImmReleaseContext", reinterpret_cast<FARPROC>(&immReleaseContext) },
        { "ImmSetCandidateWindow", reinterpret_cast<FARPROC>(&immSetCandidateWindow) },
        { "ImmSetOpenStatus", reinterpret_cast<FARPROC>(&immSetOpenStatus) },
        { "ImmIsIME", reinterpret_cast<FARPROC>(&immIsIMEStub) },
        { "ImmGetProperty", reinterpret_cast<FARPROC>(&immGetPropertyStub) },
    };

    if (reinterpret_cast<ULONG_PTR>(name) <= 0xFFFF)
        return nullptr;

    for (const auto& entry : kImm32Functions) {
        if (!::lstrcmpiA(name, entry.name))
            return entry.function;
    }
    return nullptr;
}

FARPROC WINAPI WebPluginIMEWin::GetProcAddressPatch(HMODULE module, LPCSTR name)
{
    if (FARPROC immFn = getProcAddress(name))
        return immFn;
    return ::GetProcAddress(module, name);
}

WebPluginIMEWin* WebPluginIMEWin::getInstance(HIMC context)
{
    return (s_instance && context == reinterpret_cast<HIMC>(s_instance)) ? s_instance : nullptr;
}

BOOL WINAPI WebPluginIMEWin::immAssociateContextEx(HWND window, HIMC context, DWORD flags)
{
    {
        ScopedImeCsLock csLock;
        WebPluginIMEWin* instance = s_instance;
        if (instance && (!context || context == reinterpret_cast<HIMC>(instance))) {
            instance->m_inputType = (!context && !flags) ? 0 : 1;
            instance->m_statusUpdated = true;
            return TRUE;
        }
    }
    return ::ImmAssociateContextEx(window, context, flags);
}

LONG WINAPI WebPluginIMEWin::immGetCompositionStringW(HIMC context, DWORD index, LPVOID dstData, DWORD dstSize)
{
    {
        ScopedImeCsLock csLock;
        WebPluginIMEWin* instance = getInstance(context);
        if (instance) {
            const void* srcData = nullptr;
            DWORD srcSize = 0;
            switch (index) {
            case GCS_COMPSTR:
                srcData = instance->m_compositionText.data();
                srcSize = static_cast<DWORD>(instance->m_compositionText.size() * sizeof(char16_t));
                break;
            case GCS_COMPATTR:
                srcData = instance->m_compositionAttributes.data();
                srcSize = static_cast<DWORD>(instance->m_compositionAttributes.size());
                break;
            case GCS_COMPCLAUSE:
                srcData = instance->m_compositionClauses.data();
                srcSize = static_cast<DWORD>(instance->m_compositionClauses.size() * sizeof(uint32_t));
                break;
            case GCS_CURSORPOS:
                return instance->m_cursorPosition;
            case GCS_DELTASTART:
                return instance->m_deltaStart;
            case GCS_RESULTSTR:
                srcData = instance->m_resultText.data();
                srcSize = static_cast<DWORD>(instance->m_resultText.size() * sizeof(char16_t));
                break;
            case GCS_RESULTCLAUSE:
                srcData = &instance->m_resultClauses[0];
                srcSize = sizeof(instance->m_resultClauses);
                break;
            default:
                return IMM_ERROR_NODATA;
            }

            if (!srcData || srcSize == 0)
                return 0;
            if (!dstData || dstSize == 0)
                return static_cast<LONG>(srcSize);
            DWORD copySize = std::min(dstSize, srcSize);
            memcpy(dstData, srcData, copySize);
            return static_cast<LONG>(copySize);
        }
    }
    return ::ImmGetCompositionStringW(context, index, dstData, dstSize);
}

HIMC WINAPI WebPluginIMEWin::immGetContext(HWND window)
{
    if (::IsWindow(window)) {
        wchar_t name[128] = { 0 };
        ::GetClassNameW(window, name, 128);
        if (!wcscmp(name, L"NativeWindowClass"))
            return ::ImmGetContext(window);
    }

    {
        ScopedImeCsLock csLock;
        if (s_instance) {
            s_instance->m_supportImeMessages = true;
            return reinterpret_cast<HIMC>(s_instance);
        }
    }
    return ::ImmGetContext(window);
}

BOOL WINAPI WebPluginIMEWin::immReleaseContext(HWND window, HIMC context)
{
    {
        ScopedImeCsLock csLock;
        if (getInstance(context))
            return TRUE;
    }
    return ::ImmReleaseContext(window, context);
}

BOOL WINAPI WebPluginIMEWin::immSetCandidateWindow(HIMC context, CANDIDATEFORM* candidate)
{
    {
        ScopedImeCsLock csLock;
        WebPluginIMEWin* instance = getInstance(context);
        if (instance) {
            if (candidate) {
                gfx::Rect rect(candidate->rcArea.left, candidate->rcArea.top,
                    candidate->rcArea.right - candidate->rcArea.left, candidate->rcArea.bottom - candidate->rcArea.top);
                if (rect.IsEmpty())
                    rect = gfx::Rect(candidate->ptCurrentPos.x, candidate->ptCurrentPos.y, 1, 1);
                if (instance->m_caretRect != rect) {
                    instance->m_caretRect = rect;
                    instance->m_statusUpdated = true;
                }
            }
            return TRUE;
        }
    }
    return ::ImmSetCandidateWindow(context, candidate);
}

BOOL WINAPI WebPluginIMEWin::immSetOpenStatus(HIMC context, BOOL open)
{
    {
        ScopedImeCsLock csLock;
        WebPluginIMEWin* instance = getInstance(context);
        if (instance) {
            int inputType = open ? 1 : 0;
            if (instance->m_inputType != inputType) {
                instance->m_inputType = inputType;
                instance->m_statusUpdated = true;
            }
            return TRUE;
        }
    }
    return ::ImmSetOpenStatus(context, open);
}
#endif // defined(_WIN32)

} // namespace content
