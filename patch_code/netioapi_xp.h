#ifndef patch_code_xp_netioapi_xp_h
#define patch_code_xp_netioapi_xp_h

#ifdef SUPPORT_XP_CODE

DWORD GetIfTable2Xp(void* table)
{
    typedef DWORD(__stdcall * PFN_GetIfTable2)(void* table);
    static PFN_GetIfTable2 s_GetIfTable2 = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"IPHLPAPI.dll");
        s_GetIfTable2 = (PFN_GetIfTable2)GetProcAddress(handle, "GetIfTable2");
        s_is_init = TRUE;
    }

    if (s_GetIfTable2)
        return s_GetIfTable2(table);

    return -1;
}

inline void FreeMibTableXp(PVOID Memory)
{
    typedef void(__stdcall * PFN_FreeMibTable)(PVOID Memory);
    static PFN_FreeMibTable s_FreeMibTable = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WS2_32.dll");
        s_FreeMibTable = (PFN_FreeMibTable)GetProcAddress(handle, "FreeMibTable");
        s_is_init = TRUE;
    }

    if (s_FreeMibTable)
        s_FreeMibTable(Memory);
}

#else

#define GetIfTable2Xp GetIfTable2
#define FreeMibTableXp FreeMibTable

#endif // SUPPORT_XP_CODE
#endif // patch_code_xp_netioapi_xp_h