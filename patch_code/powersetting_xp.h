#ifndef patch_code_powersetting_xp_h
#define patch_code_powersetting_xp_h

#include <powersetting.h>

#ifdef SUPPORT_XP_CODE

inline DWORD PowerGetActiveSchemeXp(HKEY UserRootPowerKey, GUID** ActivePolicyGuid)
{
    typedef DWORD(WINAPI * PFN_PowerGetActiveScheme)(HKEY UserRootPowerKey, GUID * *ActivePolicyGuid);
    static PFN_PowerGetActiveScheme s_PowerGetActiveScheme = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod = LoadLibraryW(L"PowrProf.dll");
        s_PowerGetActiveScheme = (PFN_PowerGetActiveScheme)GetProcAddress(mod, "PowerGetActiveScheme");
        s_is_init = TRUE;
    }

    if (s_PowerGetActiveScheme)
        return s_PowerGetActiveScheme(UserRootPowerKey, ActivePolicyGuid);
    return -1;
}

inline DWORD PowerReadACValueXp(HKEY RootPowerKey, CONST GUID* SchemeGuid, CONST GUID* SubGroupOfPowerSettingsGuid, CONST GUID* PowerSettingGuid, PULONG Type,
    LPBYTE Buffer, LPDWORD BufferSize)
{
    typedef DWORD(WINAPI * PFN_PowerReadACValue)(HKEY RootPowerKey, CONST GUID * SchemeGuid, CONST GUID * SubGroupOfPowerSettingsGuid,
        CONST GUID * PowerSettingGuid, PULONG Type, LPBYTE Buffer, LPDWORD BufferSize);
    static PFN_PowerReadACValue s_PowerReadACValue = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"PowrProf.dll");
        s_PowerReadACValue = (PFN_PowerReadACValue)GetProcAddress(hmod, "PowerReadACValue");
        s_is_init = TRUE;
    }

    if (s_PowerReadACValue)
        return s_PowerReadACValue(RootPowerKey, SchemeGuid, SubGroupOfPowerSettingsGuid, PowerSettingGuid, Type, Buffer, BufferSize);
    return -1;
}

inline DWORD PowerReadDCValueXp(HKEY RootPowerKey, CONST GUID* SchemeGuid, CONST GUID* SubGroupOfPowerSettingsGuid, CONST GUID* PowerSettingGuid, PULONG Type,
    LPBYTE Buffer, LPDWORD BufferSize)
{
    typedef DWORD(WINAPI * PFN_PowerReadDCValue)(HKEY RootPowerKey, CONST GUID * SchemeGuid, CONST GUID * SubGroupOfPowerSettingsGuid,
        CONST GUID * PowerSettingGuid, PULONG Type, LPBYTE Buffer, LPDWORD BufferSize);
    static PFN_PowerReadDCValue s_PowerReadDCValue = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"PowrProf.dll");
        s_PowerReadDCValue = (PFN_PowerReadDCValue)GetProcAddress(hmod, "PowerReadDCValue");
        s_is_init = TRUE;
    }

    if (s_PowerReadDCValue)
        return s_PowerReadDCValue(RootPowerKey, SchemeGuid, SubGroupOfPowerSettingsGuid, PowerSettingGuid, Type, Buffer, BufferSize);
    return -1;
}

#else

#define PowerGetActiveSchemeXp PowerGetActiveScheme
#define PowerReadACValueXp PowerReadACValue
#define PowerReadDCValueXp PowerReadDCValue

#endif // SUPPORT_XP_CODE
#endif // patch_code_powersetting_xp_h