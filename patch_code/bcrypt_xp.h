#ifndef patch_code_bcrypt_xp_h
#define patch_code_bcrypt_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>
#include <bcrypt.h>
#include <NTSecAPI.h>

inline NTSTATUS BCryptGenRandomXp(BCRYPT_ALG_HANDLE hAlgorithm, PUCHAR pbBuffer, ULONG cbBuffer, ULONG dwFlags)
{
    typedef NTSTATUS(__stdcall * PFN_BCryptGenRandom)(BCRYPT_ALG_HANDLE hAlgorithm, PUCHAR pbBuffer, ULONG cbBuffer, ULONG dwFlags);
    static PFN_BCryptGenRandom s_BCryptGenRandom = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Bcrypt.dll");
        s_BCryptGenRandom = (PFN_BCryptGenRandom)GetProcAddress(handle, "BCryptGenRandom");
        s_is_init = TRUE;
    }

    if (s_BCryptGenRandom)
        return s_BCryptGenRandom(hAlgorithm, pbBuffer, cbBuffer, dwFlags);

    RtlGenRandom(pbBuffer, cbBuffer);
    return S_OK;
}

inline NTSTATUS BCryptOpenAlgorithmProviderXp(BCRYPT_ALG_HANDLE* phAlgorithm, LPCWSTR pszAlgId, LPCWSTR pszImplementation, ULONG dwFlags)
{
    typedef NTSTATUS(__stdcall * PFN_BCryptOpenAlgorithmProvider)(BCRYPT_ALG_HANDLE * phAlgorithm, LPCWSTR pszAlgId, LPCWSTR pszImplementation, ULONG dwFlags);
    static PFN_BCryptOpenAlgorithmProvider s_BCryptOpenAlgorithmProvider = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Bcrypt.dll");
        s_BCryptOpenAlgorithmProvider = (PFN_BCryptOpenAlgorithmProvider)GetProcAddress(handle, "BCryptOpenAlgorithmProvider");
        s_is_init = TRUE;
    }

    if (s_BCryptOpenAlgorithmProvider)
        return s_BCryptOpenAlgorithmProvider(phAlgorithm, pszAlgId, pszImplementation, dwFlags);

    return S_OK;
}

inline NTSTATUS BCryptCloseAlgorithmProviderXp(BCRYPT_ALG_HANDLE hAlgorithm, ULONG dwFlags)
{
    typedef NTSTATUS(__stdcall * PFN_BCryptCloseAlgorithmProvider)(BCRYPT_ALG_HANDLE hAlgorithm, ULONG dwFlags);
    static PFN_BCryptCloseAlgorithmProvider s_BCryptCloseAlgorithmProvider = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Bcrypt.dll");
        s_BCryptCloseAlgorithmProvider = (PFN_BCryptCloseAlgorithmProvider)GetProcAddress(handle, "BCryptCloseAlgorithmProvider");
        s_is_init = TRUE;
    }

    if (s_BCryptCloseAlgorithmProvider)
        return s_BCryptCloseAlgorithmProvider(hAlgorithm, dwFlags);

    return S_OK;
}

#else

#define BCryptGenRandomXp BCryptGenRandom
#define BCryptOpenAlgorithmProviderXp BCryptOpenAlgorithmProvider
#define BCryptCloseAlgorithmProviderXp BCryptCloseAlgorithmProvider

#endif
#endif