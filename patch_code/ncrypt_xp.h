
#include <ncrypt.h>

#ifdef SUPPORT_XP_CODE

typedef SECURITY_STATUS(WINAPI* NCryptFreeObjectFunc)(NCRYPT_HANDLE);
typedef SECURITY_STATUS(WINAPI* NCryptSignHashFunc)(NCRYPT_KEY_HANDLE, // hKey
    VOID*, // pPaddingInfo
    BYTE*, // pbHashValue
    DWORD, // cbHashValue
    BYTE*, // pbSignature
    DWORD, // cbSignature
    DWORD*, // pcbResult
    DWORD); // dwFlags

typedef SECURITY_STATUS(WINAPI* NCryptGetPropertyFunc)(
    NCRYPT_HANDLE hObject, LPCWSTR pszProperty, PBYTE pbOutput, DWORD cbOutput, DWORD* pcbResult, DWORD dwFlags);

class CNGFunctions {
public:
    CNGFunctions()
        : ncrypt_free_object_(dummyNCryptFreeObjectFunc)
        , ncrypt_sign_hash_(dummyNCryptSignHashFunc)
        , ncrypt_get_prop_(dummyNCryptGetPropertyFunc)
    {
        HMODULE ncrypt = LoadLibraryW(L"ncrypt.dll");
        if (ncrypt != nullptr) {
            ncrypt_free_object_ = reinterpret_cast<NCryptFreeObjectFunc>(GetProcAddress(ncrypt, "NCryptFreeObject"));
            ncrypt_sign_hash_ = reinterpret_cast<NCryptSignHashFunc>(GetProcAddress(ncrypt, "NCryptSignHash"));
            ncrypt_get_prop_ = reinterpret_cast<NCryptGetPropertyFunc>(GetProcAddress(ncrypt, "NCryptGetProperty"));
        }
    }

    static SECURITY_STATUS WINAPI dummyNCryptSignHashFunc(NCRYPT_KEY_HANDLE, VOID*, BYTE*, DWORD, BYTE*, DWORD, DWORD*, DWORD)
    {
        return E_FAIL;
    }

    static SECURITY_STATUS WINAPI dummyNCryptFreeObjectFunc(NCRYPT_HANDLE)
    {
        return E_FAIL;
    }

    static SECURITY_STATUS WINAPI dummyNCryptGetPropertyFunc(
        NCRYPT_HANDLE hObject, LPCWSTR pszProperty, PBYTE pbOutput, DWORD cbOutput, DWORD* pcbResult, DWORD dwFlags)
    {
        return E_FAIL;
    }

    NCryptFreeObjectFunc ncrypt_free_object() const
    {
        return ncrypt_free_object_;
    }

    NCryptSignHashFunc ncrypt_sign_hash() const
    {
        return ncrypt_sign_hash_;
    }

    NCryptGetPropertyFunc ncrypt_get_prop() const
    {
        return ncrypt_get_prop_;
    }

private:
    NCryptFreeObjectFunc ncrypt_free_object_;
    NCryptSignHashFunc ncrypt_sign_hash_;
    NCryptGetPropertyFunc ncrypt_get_prop_;
};

base::LazyInstance<CNGFunctions>::Leaky g_cng_functions = LAZY_INSTANCE_INITIALIZER;

#define NCryptFreeObjectXp(key) g_cng_functions.Get().ncrypt_free_object()(key)
#define NCryptSignHashXp(a1, a2, a3, a4, a5, a6, a7, a8) g_cng_functions.Get().ncrypt_sign_hash()(a1, a2, a3, a4, a5, a6, a7, a8)
#define NCryptGetPropertyXp(a1, a2, a3, a4, a5, a6) g_cng_functions.Get().ncrypt_get_prop()(a1, a2, a3, a4, a5, a6)

#else

#define NCryptFreeObjectXp NCryptFreeObject
#define NCryptSignHashXp NCryptSignHash
#define NCryptGetPropertyXp NCryptGetProperty

#endif // SUPPORT_XP_CODE