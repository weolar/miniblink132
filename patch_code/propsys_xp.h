#ifndef patch_code_propsys_xp_h
#define patch_code_propsys_xp_h

#include <propvarutil.h>

#ifdef SUPPORT_XP_CODE

inline HRESULT VariantCompareXp(REFVARIANT var1, REFVARIANT var2)
{
    typedef HRESULT(WINAPI * PFN_VariantCompare)(REFVARIANT var1, REFVARIANT var2);
    static PFN_VariantCompare s_VariantCompare = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Propsys.dll");
        s_VariantCompare = (PFN_VariantCompare)GetProcAddress(hmod, "VariantCompare");
        s_is_init = TRUE;
    }

    if (s_VariantCompare)
        return s_VariantCompare(var1, var2);

    HRESULT hr = ::VarCmp((LPVARIANT)(&var1), (LPVARIANT)(&var2), LOCALE_USER_DEFAULT, NORM_IGNORECASE);
    int ret = 0;

    switch (hr) {
    case VARCMP_LT:
        ret = -1;
        break;

    case VARCMP_GT:
    case VARCMP_NULL:
        ret = 1;
        break;

    default:
        // Equal.
        break;
    }

    return ret;
}

inline HRESULT PSGetPropertyKeyFromNameXp(PCWSTR pszName, PROPERTYKEY* ppropkey)
{
    typedef HRESULT(WINAPI * PFN_PSGetPropertyKeyFromName)(PCWSTR pszName, PROPERTYKEY * ppropkey);
    static PFN_PSGetPropertyKeyFromName s_PSGetPropertyKeyFromName = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Propsys.dll");
        s_PSGetPropertyKeyFromName = (PFN_PSGetPropertyKeyFromName)GetProcAddress(hmod, "PSGetPropertyKeyFromName");
        s_is_init = TRUE;
    }

    if (s_PSGetPropertyKeyFromName)
        return s_PSGetPropertyKeyFromName(pszName, ppropkey);
    return -1;
}

#else

#define VariantCompareXp VariantCompare
#define PSGetPropertyKeyFromNameXp PSGetPropertyKeyFromName

#endif
#endif