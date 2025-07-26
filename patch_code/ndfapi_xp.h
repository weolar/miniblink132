#ifndef patch_code_ndfapi_xp_h
#define patch_code_ndfapi_xp_h

#ifdef SUPPORT_XP_CODE

#include <ndfapi.h>
#include <windows.h>

inline HRESULT NdfExecuteDiagnosisXp(NDFHANDLE handle, HWND hwnd)
{
    typedef HRESULT(__stdcall * PFN_NdfExecuteDiagnosis)(NDFHANDLE handle, HWND hwnd);
    static PFN_NdfExecuteDiagnosis s_NdfExecuteDiagnosis = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle_mod = GetModuleHandle(L"NDFAPI.dll");
        s_NdfExecuteDiagnosis = (PFN_NdfExecuteDiagnosis)GetProcAddress(handle_mod, "NdfExecuteDiagnosis");
        s_is_init = TRUE;
    }

    if (s_NdfExecuteDiagnosis)
        return s_NdfExecuteDiagnosis(handle, hwnd);

    return E_FAIL;
}

inline HRESULT NdfCreateWebIncidentXp(LPCWSTR url, NDFHANDLE* handle)
{
    typedef HRESULT(__stdcall * PFN_NdfCreateWebIncident)(LPCWSTR url, NDFHANDLE * handle);
    static PFN_NdfCreateWebIncident s_NdfCreateWebIncident = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle_mod = GetModuleHandle(L"NDFAPI.dll");
        s_NdfCreateWebIncident = (PFN_NdfCreateWebIncident)GetProcAddress(handle_mod, "NdfCreateWebIncident");
        s_is_init = TRUE;
    }

    if (s_NdfCreateWebIncident)
        return s_NdfCreateWebIncident(url, handle);

    return E_FAIL;
}

inline HRESULT NdfCloseIncidentXp(NDFHANDLE handle)
{
    typedef HRESULT(__stdcall * PFN_NdfCloseIncident)(NDFHANDLE handle);
    static PFN_NdfCloseIncident s_NdfCloseIncident = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle_mod = GetModuleHandle(L"NDFAPI.dll");
        s_NdfCloseIncident = (PFN_NdfCloseIncident)GetProcAddress(handle_mod, "NdfCloseIncident");
        s_is_init = TRUE;
    }

    if (s_NdfCloseIncident)
        return s_NdfCloseIncident(handle);

    return E_FAIL;
}

#else

#define NdfCloseIncidentXp NdfCloseIncident
#define NdfCreateWebIncidentXp NdfCreateWebIncident
#define NdfExecuteDiagnosisXp NdfExecuteDiagnosis

#endif
#endif