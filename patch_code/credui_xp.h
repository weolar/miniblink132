#ifndef patch_code_credui_api_h
#define patch_code_credui_api_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>

inline DWORD CredUIPromptForCredentialsWXp(PCREDUI_INFOW pUiInfo, PCWSTR pszTargetName, PCtxtHandle pContext, DWORD dwAuthError, PWSTR pszUserName,
    ULONG ulUserNameBufferSize, PWSTR pszPassword, ULONG ulPasswordBufferSize, BOOL* save, DWORD dwFlags)
{
    typedef DWORD(__stdcall * PFN_CredUIPromptForCredentialsW)(PCWSTR pszTargetName, PCtxtHandle pContext, DWORD dwAuthError, PWSTR pszUserName,
        ULONG ulUserNameBufferSize, PWSTR pszPassword, ULONG ulPasswordBufferSize, BOOL * save, DWORD dwFlags);
    static PFN_CredUIPromptForCredentialsW s_CredUIPromptForCredentialsW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"CREDUI.dll");
        s_CredUIPromptForCredentialsW = (PFN_CredUIPromptForCredentialsW)GetProcAddress(mod_handle, "CredUIPromptForCredentialsW");
        s_is_init = TRUE;
    }

    if (s_CredUIPromptForCredentialsW)
        return s_CredUIPromptForCredentialsW(
            pszTargetName, pContext, dwAuthError, pszUserName, ulUserNameBufferSize, pszPassword, ulPasswordBufferSize, save, dwFlags);

    return ERROR_ACCESS_DENIED;
}

inline DWORD CredUIPromptForWindowsCredentialsWXp(PCREDUI_INFOW pUiInfo, DWORD dwAuthError, ULONG* pulAuthPackage, LPCVOID pvInAuthBuffer,
    ULONG ulInAuthBufferSize, LPVOID* ppvOutAuthBuffer, ULONG* pulOutAuthBufferSize, BOOL* pfSave, DWORD dwFlags)
{
    typedef POWER_PLATFORM_ROLE(__stdcall * PFN_CredUIPromptForWindowsCredentialsW)(PCREDUI_INFOW pUiInfo, DWORD dwAuthError, ULONG * pulAuthPackage,
        LPCVOID pvInAuthBuffer, ULONG ulInAuthBufferSize, LPVOID * ppvOutAuthBuffer, ULONG * pulOutAuthBufferSize, BOOL * pfSave, DWORD dwFlags);
    static PFN_CredUIPromptForWindowsCredentialsW s_CredUIPromptForWindowsCredentialsW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"CREDUI.dll");
        s_CredUIPromptForWindowsCredentialsW = (PFN_CredUIPromptForWindowsCredentialsW)GetProcAddress(mod_handle, "CredUIPromptForWindowsCredentialsW");
        s_is_init = TRUE;
    }

    if (s_CredUIPromptForWindowsCredentialsW)
        return s_CredUIPromptForWindowsCredentialsW(
            pUiInfo, dwAuthError, pulAuthPackage, pvInAuthBuffer, ulInAuthBufferSize, ppvOutAuthBuffer, pulOutAuthBufferSize, pfSave, dwFlags);

    return ERROR_ACCESS_DENIED;
}

#else

#define CredUIPromptForCredentialsWXp CredUIPromptForCredentialsW
#define CredUIPromptForWindowsCredentialsWXp CredUIPromptForWindowsCredentialsW

#endif // SUPPORT_XP_CODE

#endif // patch_code_credui_api_h
