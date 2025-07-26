
#ifndef patch_code_user_api_xp_h
#define patch_code_user_api_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>

inline void* RegisterPowerSettingNotificationXp(HANDLE hRecipient, LPCGUID PowerSettingGuid, DWORD Flags)
{
    typedef void*(WINAPI * PFN_RegisterPowerSettingNotification)(HANDLE hRecipient, LPCGUID PowerSettingGuid, DWORD Flags);
    static PFN_RegisterPowerSettingNotification s_RegisterPowerSettingNotification = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = GetModuleHandle(L"User32.dll");
        s_RegisterPowerSettingNotification = (PFN_RegisterPowerSettingNotification)(GetProcAddress(mod_handle, "RegisterPowerSettingNotification"));
        s_is_init = TRUE;
    }

    if (!s_RegisterPowerSettingNotification)
        return NULL;

    return s_RegisterPowerSettingNotification(hRecipient, PowerSettingGuid, Flags);
}

inline BOOL UpdateLayeredWindowIndirectXp(HWND hWnd, const UPDATELAYEREDWINDOWINFO* ulw)
{
    typedef BOOL(WINAPI * PFN_UpdateLayeredWindowIndirect)(HWND hWnd, const UPDATELAYEREDWINDOWINFO* ulw);
    static PFN_UpdateLayeredWindowIndirect s_UpdateLayeredWindowIndirect = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE user32 = GetModuleHandle(L"User32.dll");
        s_UpdateLayeredWindowIndirect = (PFN_UpdateLayeredWindowIndirect)GetProcAddress(user32, "UpdateLayeredWindowIndirect");
        s_is_init = TRUE;
    }

    if (s_UpdateLayeredWindowIndirect)
        return s_UpdateLayeredWindowIndirect(hWnd, ulw);

    POINT ptDst = *(ulw->pptDst);
    SIZE size = *(ulw->psize);
    POINT ptSrc = *(ulw->pptSrc);
    BLENDFUNCTION blend = *(ulw->pblend);
    return UpdateLayeredWindow(hWnd, ulw->hdcDst, &ptDst, &size, ulw->hdcSrc, &ptSrc, ulw->crKey, &blend, ulw->dwFlags);
}

inline BOOL UnregisterPowerSettingNotificationXp(HPOWERNOTIFY Handle)
{
    typedef BOOL(WINAPI * PFN_UnregisterPowerSettingNotification)(HPOWERNOTIFY Handle);
    static PFN_UnregisterPowerSettingNotification s_UnregisterPowerSettingNotification = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = GetModuleHandle(L"User32.dll");
        s_UnregisterPowerSettingNotification = (PFN_UnregisterPowerSettingNotification)(GetProcAddress(mod_handle, "UnregisterPowerSettingNotification"));
        s_is_init = TRUE;
    }

    if (!s_UnregisterPowerSettingNotification)
        return FALSE;

    return s_UnregisterPowerSettingNotification(Handle);
}

#else

#define UpdateLayeredWindowIndirectXp UpdateLayeredWindowIndirect
#define RegisterPowerSettingNotificationXp RegisterPowerSettingNotification
#define UnregisterPowerSettingNotificationXp UnregisterPowerSettingNotification

#endif // SUPPORT_XP_CODE
#endif // patch_code_shell_api_h