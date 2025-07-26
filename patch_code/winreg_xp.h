#ifndef patch_code_xp_winreg_xp_h
#define patch_code_xp_winreg_xp_h

#ifdef SUPPORT_XP_CODE

inline LSTATUS RegGetValueWXp(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData)
{
    typedef LSTATUS(WINAPI * PFN_RegGetValueW)(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
    static PFN_RegGetValueW s_RegGetValueW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE user32 = GetModuleHandle(L"Advapi32.dll");
        s_RegGetValueW = (PFN_RegGetValueW)GetProcAddress(user32, "RegGetValueW");
        s_is_init = TRUE;
    }

    if (s_RegGetValueW)
        return s_RegGetValueW(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
    return ERROR_FILE_NOT_FOUND;
}

#else

#define RegGetValueWXp RegGetValueW

#endif

#endif // patch_code_xp_winreg_xp_h