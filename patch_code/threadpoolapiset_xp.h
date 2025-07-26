#ifndef patch_code_threadpoolapiset_xp_h
#define patch_code_threadpoolapiset_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>
#include <threadpoolapiset.h>

inline BOOL GetThreadGroupAffinityXp(HANDLE hThread, void* GroupAffinity)
{
    typedef BOOL(__stdcall * PFN_GetThreadGroupAffinity)(HANDLE hThread, void* GroupAffinity);
    static PFN_GetThreadGroupAffinity s_GetThreadGroupAffinity = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetThreadGroupAffinity = (PFN_GetThreadGroupAffinity)GetProcAddress(handle, "GetThreadGroupAffinity");
        s_is_init = TRUE;
    }

    if (s_GetThreadGroupAffinity)
        return s_GetThreadGroupAffinity(hThread, GroupAffinity);
    return FALSE;
}

inline BOOL CallbackMayRunLongXp(void* ptr)
{
    typedef BOOL(WINAPI * PFN_CallbackMayRunLong)(void* ptr);
    static PFN_CallbackMayRunLong s_CallbackMayRunLong;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_CallbackMayRunLong = (PFN_CallbackMayRunLong)(GetProcAddress(handle, "CallbackMayRunLong"));
        s_is_init = TRUE;
    }
    if (s_CallbackMayRunLong)
        return s_CallbackMayRunLong(ptr);

    return FALSE;
}

inline void DestroyThreadpoolEnvironmentXp(PTP_CALLBACK_ENVIRON pcbe)
{
    typedef void(__stdcall * PFN_DestroyThreadpoolEnvironment)(PTP_CALLBACK_ENVIRON pcbe);
    static PFN_DestroyThreadpoolEnvironment s_DestroyThreadpoolEnvironment = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_DestroyThreadpoolEnvironment = (PFN_DestroyThreadpoolEnvironment)GetProcAddress(handle, "DestroyThreadpoolEnvironment");
        s_is_init = TRUE;
    }

    if (s_DestroyThreadpoolEnvironment)
        return s_DestroyThreadpoolEnvironment(pcbe);
}

inline void CloseThreadpoolWorkXp(PTP_WORK pwk)
{
    typedef void(__stdcall * PFN_CloseThreadpoolWork)(PTP_WORK pwk);
    static PFN_CloseThreadpoolWork s_CloseThreadpoolWork = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_CloseThreadpoolWork = (PFN_CloseThreadpoolWork)GetProcAddress(handle, "CloseThreadpoolWork");
        s_is_init = TRUE;
    }

    if (s_CloseThreadpoolWork)
        return s_CloseThreadpoolWork(pwk);
}

inline void CloseThreadpoolXp(PTP_POOL ptpp)
{
    typedef void(__stdcall * PFN_CloseThreadpool)(PTP_POOL ptpp);
    static PFN_CloseThreadpool s_CloseThreadpool = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_CloseThreadpool = (PFN_CloseThreadpool)GetProcAddress(handle, "CloseThreadpool");
        s_is_init = TRUE;
    }

    if (s_CloseThreadpool)
        return s_CloseThreadpool(ptpp);
}

inline void InitializeThreadpoolEnvironmentXp(PTP_CALLBACK_ENVIRON pcbe)
{
    typedef void(__stdcall * PFN_InitializeThreadpoolEnvironment)(PTP_CALLBACK_ENVIRON pcbe);
    static PFN_InitializeThreadpoolEnvironment s_InitializeThreadpoolEnvironment = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_InitializeThreadpoolEnvironment = (PFN_InitializeThreadpoolEnvironment)GetProcAddress(handle, "InitializeThreadpoolEnvironment");
        s_is_init = TRUE;
    }

    if (s_InitializeThreadpoolEnvironment)
        return s_InitializeThreadpoolEnvironment(pcbe);
}

inline BOOL SetThreadpoolThreadMinimumXp(PTP_POOL ptpp, DWORD cthrdMic)
{
    typedef BOOL(__stdcall * PFN_SetThreadpoolThreadMinimum)(PTP_POOL ptpp, DWORD cthrdMic);
    static PFN_SetThreadpoolThreadMinimum s_SetThreadpoolThreadMinimum = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_SetThreadpoolThreadMinimum = (PFN_SetThreadpoolThreadMinimum)GetProcAddress(handle, "SetThreadpoolThreadMinimum");
        s_is_init = TRUE;
    }

    if (s_SetThreadpoolThreadMinimum)
        return s_SetThreadpoolThreadMinimum(ptpp, cthrdMic);
    return FALSE;
}

inline void SetThreadpoolThreadMaximumXp(PTP_POOL ptpp, DWORD cthrdMic)
{
    typedef void(__stdcall * PFN_SetThreadpoolThreadMaximum)(PTP_POOL ptpp, DWORD cthrdMic);
    static PFN_SetThreadpoolThreadMaximum s_SetThreadpoolThreadMaximum = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_SetThreadpoolThreadMaximum = (PFN_SetThreadpoolThreadMaximum)GetProcAddress(handle, "SetThreadpoolThreadMaximum");
        s_is_init = TRUE;
    }

    if (s_SetThreadpoolThreadMaximum)
        return s_SetThreadpoolThreadMaximum(ptpp, cthrdMic);
}

inline void WaitForThreadpoolWorkCallbacksXp(PTP_WORK pwk, BOOL fCancelPendingCallbacks)
{
    typedef void(__stdcall * PFN_WaitForThreadpoolWorkCallbacks)(PTP_WORK pwk, BOOL fCancelPendingCallbacks);
    static PFN_WaitForThreadpoolWorkCallbacks s_WaitForThreadpoolWorkCallbacks = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_WaitForThreadpoolWorkCallbacks = (PFN_WaitForThreadpoolWorkCallbacks)GetProcAddress(handle, "WaitForThreadpoolWorkCallbacks");
        s_is_init = TRUE;
    }

    if (s_WaitForThreadpoolWorkCallbacks)
        return s_WaitForThreadpoolWorkCallbacks(pwk, fCancelPendingCallbacks);
}

inline void SubmitThreadpoolWorkXp(PTP_WORK pwk)
{
    typedef void(__stdcall * PFN_SubmitThreadpoolWork)(PTP_WORK pwk);
    static PFN_SubmitThreadpoolWork s_SubmitThreadpoolWork = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_SubmitThreadpoolWork = (PFN_SubmitThreadpoolWork)GetProcAddress(handle, "SubmitThreadpoolWork");
        s_is_init = TRUE;
    }

    if (s_SubmitThreadpoolWork)
        return s_SubmitThreadpoolWork(pwk);
}

inline PTP_WORK CreateThreadpoolWorkXp(PTP_WORK_CALLBACK pfnwk, PVOID pv, PTP_CALLBACK_ENVIRON pcbe)
{
    typedef PTP_WORK(__stdcall * PFN_CreateThreadpoolWork)(PTP_WORK_CALLBACK pfnwk, PVOID pv, PTP_CALLBACK_ENVIRON pcbe);
    static PFN_CreateThreadpoolWork s_CreateThreadpoolWork = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_CreateThreadpoolWork = (PFN_CreateThreadpoolWork)GetProcAddress(handle, "CreateThreadpoolWork");
        s_is_init = TRUE;
    }

    if (s_CreateThreadpoolWork)
        return s_CreateThreadpoolWork(pfnwk, pv, pcbe);
    return NULL;
}

inline PTP_POOL CreateThreadpoolXp(PVOID reserved)
{
    typedef PTP_POOL(__stdcall * PFN_CreateThreadpool)(PVOID reserved);
    static PFN_CreateThreadpool s_CreateThreadpool = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_CreateThreadpool = (PFN_CreateThreadpool)GetProcAddress(handle, "CreateThreadpool");
        s_is_init = TRUE;
    }

    if (s_CreateThreadpool)
        return s_CreateThreadpool(reserved);
    return NULL;
}

inline void SetThreadpoolCallbackPoolXp(PTP_CALLBACK_ENVIRON pcbe, PTP_POOL ptpp)
{
    typedef void(__stdcall * PFN_SetThreadpoolCallbackPool)(PTP_CALLBACK_ENVIRON pcbe, PTP_POOL ptpp);
    static PFN_SetThreadpoolCallbackPool s_SetThreadpoolCallbackPool = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_SetThreadpoolCallbackPool = (PFN_SetThreadpoolCallbackPool)GetProcAddress(handle, "SetThreadpoolCallbackPool");
        s_is_init = TRUE;
    }

    if (s_SetThreadpoolCallbackPool)
        return s_SetThreadpoolCallbackPool(pcbe, ptpp);
}

#else

#define CallbackMayRunLongXp CallbackMayRunLong
#define DestroyThreadpoolEnvironmentXp DestroyThreadpoolEnvironment
#define CloseThreadpoolWorkXp CloseThreadpoolWork
#define CloseThreadpoolXp CloseThreadpool
#define InitializeThreadpoolEnvironmentXp InitializeThreadpoolEnvironment
#define SetThreadpoolThreadMinimumXp SetThreadpoolThreadMinimum
#define SetThreadpoolThreadMaximumXp SetThreadpoolThreadMaximum
#define WaitForThreadpoolWorkCallbacksXp WaitForThreadpoolWorkCallbacks
#define SubmitThreadpoolWorkXp SubmitThreadpoolWork
#define CreateThreadpoolWorkXp CreateThreadpoolWork
#define CreateThreadpoolXp CreateThreadpool
#define SetThreadpoolCallbackPoolXp SetThreadpoolCallbackPool

#endif
#endif // patch_code_threadpoolapiset_xp_h