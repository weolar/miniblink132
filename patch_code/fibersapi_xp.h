
#ifndef patch_code_fibersapi_xp_h
#define patch_code_fibersapi_xp_h

#ifdef SUPPORT_XP_CODE
inline DWORD FlsAllocXp(PFLS_CALLBACK_FUNCTION lpCallback)
{
    typedef DWORD(WINAPI * PFN_FlsAlloc)(PFLS_CALLBACK_FUNCTION lpCallback);
    static PFN_FlsAlloc s_FlsAlloc = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Kernel32.dll");
        s_FlsAlloc = (PFN_FlsAlloc)GetProcAddress(hmod, "FlsAlloc");
        s_is_init = TRUE;
    }

    if (s_FlsAlloc)
        return s_FlsAlloc(lpCallback);
    return FLS_OUT_OF_INDEXES;
}

inline BOOL FlsSetValueXp(DWORD dwFlsIndex, PVOID lpFlsData)
{
    typedef BOOL(WINAPI * PFN_FlsSetValue)(DWORD dwFlsIndex, PVOID lpFlsData);
    static PFN_FlsSetValue s_FlsSetValue = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Kernel32.dll");
        s_FlsSetValue = (PFN_FlsSetValue)GetProcAddress(hmod, "FlsSetValue");
        s_is_init = TRUE;
    }

    if (s_FlsSetValue)
        return s_FlsSetValue(dwFlsIndex, lpFlsData);
    return FALSE;
}

inline PVOID FlsGetValueXp(DWORD dwFlsIndex)
{
    typedef PVOID(WINAPI * PFN_FlsGetValue)(DWORD dwFlsIndex);
    static PFN_FlsGetValue s_FlsGetValue = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Kernel32.dll");
        s_FlsGetValue = (PFN_FlsGetValue)GetProcAddress(hmod, "FlsGetValue");
        s_is_init = TRUE;
    }

    if (s_FlsGetValue)
        return s_FlsGetValue(dwFlsIndex);
    return NULL;
}

#else

#define FlsAllocXp FlsAlloc
#define FlsSetValueXp FlsSetValue
#define FlsGetValueXp FlsGetValue

#endif
#endif // patch_code_fibersapi_xp_h