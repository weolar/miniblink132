
#ifndef patch_code_dbghelp_xp_h
#define patch_code_dbghelp_xp_h

#ifdef SUPPORT_XP_CODE

inline BOOL SymGetSearchPathWXp(HANDLE process, PWSTR search_path, DWORD search_path_length)
{
    typedef BOOL(WINAPI * PFN_SymGetSearchPathW)(HANDLE process, PWSTR search_path, DWORD search_path_length);
    static PFN_SymGetSearchPathW s_SymGetSearchPathW;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE shell32 = LoadLibraryW(L"Dbghelp.dll");
        s_SymGetSearchPathW = (PFN_SymGetSearchPathW)(GetProcAddress(shell32, "SymGetSearchPathW"));
        s_is_init = TRUE;
    }
    if (s_SymGetSearchPathW)
        return s_SymGetSearchPathW(process, search_path, search_path_length);

    return FALSE;
}

inline BOOL SymSetSearchPathWXp(HANDLE process, PCWSTR search_path)
{
    typedef BOOL(WINAPI * PFN_SymSetSearchPathW)(HANDLE process, PCWSTR search_path);
    static PFN_SymSetSearchPathW s_SymSetSearchPathW;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE shell32 = LoadLibraryW(L"Dbghelp.dll");
        s_SymSetSearchPathW = (PFN_SymSetSearchPathW)(GetProcAddress(shell32, "SymSetSearchPathW"));
        s_is_init = TRUE;
    }
    if (s_SymSetSearchPathW)
        return s_SymSetSearchPathW(process, search_path);

    return FALSE;
}

#else

#define SymGetSearchPathWXp SymGetSearchPathW
#define SymSetSearchPathWXp SymSetSearchPathW

#endif // SUPPORT_XP_CODE

#endif