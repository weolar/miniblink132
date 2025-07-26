#ifndef patch_code_esent_xp_h
#define patch_code_esent_xp_h

#include <esent.h>

#ifdef SUPPORT_XP_CODE

inline JET_ERR JetBeginSessionWXp(JET_INSTANCE instance, JET_SESID* psesid, JET_PCWSTR szUserName, JET_PCWSTR szPassword)
{
    typedef JET_ERR(WINAPI * PFN_JetBeginSessionW)(JET_INSTANCE instance, JET_SESID * psesid, JET_PCWSTR szUserName, JET_PCWSTR szPassword);
    static PFN_JetBeginSessionW s_JetBeginSessionW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE user32 = LoadLibraryW(L"ESENT.dll");
        s_JetBeginSessionW = (PFN_JetBeginSessionW)GetProcAddress(user32, "JetBeginSessionW");
        s_is_init = TRUE;
    }

    if (s_JetBeginSessionW)
        return s_JetBeginSessionW(instance, psesid, szUserName, szPassword);
    return -1;
}

inline JET_ERR JetGetTableColumnInfoWXp(
    JET_SESID sesid, JET_TABLEID tableid, JET_PCWSTR szColumnName, void* pvResult, unsigned long cbMax, unsigned long InfoLevel)
{
    typedef JET_ERR(WINAPI * PFN_JetGetTableColumnInfoW)(
        JET_SESID sesid, JET_TABLEID tableid, JET_PCWSTR szColumnName, void* pvResult, unsigned long cbMax, unsigned long InfoLevel);
    static PFN_JetGetTableColumnInfoW s_JetGetTableColumnInfoW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetGetTableColumnInfoW = (PFN_JetGetTableColumnInfoW)GetProcAddress(hmod, "JetGetTableColumnInfoW");
        s_is_init = TRUE;
    }

    if (s_JetGetTableColumnInfoW)
        return s_JetGetTableColumnInfoW(sesid, tableid, szColumnName, pvResult, cbMax, InfoLevel);
    return -1;
}

inline JET_ERR JetSetSystemParameterWXp(JET_INSTANCE* pinstance, JET_SESID sesid, unsigned long paramid, JET_API_PTR lParam, JET_PCWSTR szParam)
{
    typedef JET_ERR(WINAPI * PFN_JetSetSystemParameterW)(
        JET_INSTANCE * pinstance, JET_SESID sesid, unsigned long paramid, JET_API_PTR lParam, JET_PCWSTR szParam);
    static PFN_JetSetSystemParameterW s_JetSetSystemParameterW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetSetSystemParameterW = (PFN_JetSetSystemParameterW)GetProcAddress(hmod, "JetSetSystemParameterW");
        s_is_init = TRUE;
    }

    if (s_JetSetSystemParameterW)
        return s_JetSetSystemParameterW(pinstance, sesid, paramid, lParam, szParam);
    return -1;
}

inline JET_ERR JetOpenTableWXp(
    JET_SESID sesid, JET_DBID dbid, JET_PCWSTR szTableName, const void* pvParameters, unsigned long cbParameters, JET_GRBIT grbit, JET_TABLEID* ptableid)
{
    typedef JET_ERR(WINAPI * PFN_JetOpenTableW)(
        JET_SESID sesid, JET_DBID dbid, JET_PCWSTR szTableName, const void* pvParameters, unsigned long cbParameters, JET_GRBIT grbit, JET_TABLEID* ptableid);
    static PFN_JetOpenTableW s_JetOpenTableW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetOpenTableW = (PFN_JetOpenTableW)GetProcAddress(hmod, "JetOpenTableW");
        s_is_init = TRUE;
    }

    if (s_JetOpenTableW)
        return s_JetOpenTableW(sesid, dbid, szTableName, pvParameters, cbParameters, grbit, ptableid);
    return -1;
}

inline JET_ERR JetOpenDatabaseWXp(JET_SESID sesid, JET_PCWSTR szFilename, JET_PCWSTR szConnect, JET_DBID* pdbid, JET_GRBIT grbit)
{
    typedef JET_ERR(WINAPI * PFN_JetOpenDatabaseW)(JET_SESID sesid, JET_PCWSTR szFilename, JET_PCWSTR szConnect, JET_DBID * pdbid, JET_GRBIT grbit);
    static PFN_JetOpenDatabaseW s_JetOpenDatabaseW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetOpenDatabaseW = (PFN_JetOpenDatabaseW)GetProcAddress(hmod, "JetOpenDatabaseW");
        s_is_init = TRUE;
    }

    if (s_JetOpenDatabaseW)
        return s_JetOpenDatabaseW(sesid, szFilename, szConnect, pdbid, grbit);
    return -1;
}

inline JET_ERR JetCreateInstanceWXp(JET_INSTANCE* pinstance, JET_PCWSTR szInstanceName)
{
    typedef JET_ERR(WINAPI * PFN_JetCreateInstanceW)(JET_INSTANCE * pinstance, JET_PCWSTR szInstanceName);
    static PFN_JetCreateInstanceW s_JetCreateInstanceW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetCreateInstanceW = (PFN_JetCreateInstanceW)GetProcAddress(hmod, "JetCreateInstanceW");
        s_is_init = TRUE;
    }

    if (s_JetCreateInstanceW)
        return s_JetCreateInstanceW(pinstance, szInstanceName);
    return -1;
}

inline JET_ERR JetAttachDatabase2WXp(JET_SESID sesid, JET_PCWSTR szFilename, const unsigned long cpgDatabaseSizeMax, JET_GRBIT grbit)
{
    typedef JET_ERR(WINAPI * PFN_JetAttachDatabase2W)(JET_SESID sesid, JET_PCWSTR szFilename, const unsigned long cpgDatabaseSizeMax, JET_GRBIT grbit);
    static PFN_JetAttachDatabase2W s_JetAttachDatabase2W = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetAttachDatabase2W = (PFN_JetAttachDatabase2W)GetProcAddress(hmod, "JetAttachDatabase2W");
        s_is_init = TRUE;
    }

    if (s_JetAttachDatabase2W)
        return s_JetAttachDatabase2W(sesid, szFilename, cpgDatabaseSizeMax, grbit);
    return -1;
}

inline JET_ERR JetGetSystemParameterWXp(
    JET_INSTANCE instance, JET_SESID sesid, unsigned long paramid, JET_API_PTR* plParam, JET_PWSTR szParam, unsigned long cbMax)
{
    typedef JET_ERR(WINAPI * PFN_JetGetSystemParameterW)(
        JET_INSTANCE instance, JET_SESID sesid, unsigned long paramid, JET_API_PTR* plParam, JET_PWSTR szParam, unsigned long cbMax);
    static PFN_JetGetSystemParameterW s_JetGetSystemParameterW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetGetSystemParameterW = (PFN_JetGetSystemParameterW)GetProcAddress(hmod, "JetGetSystemParameterW");
        s_is_init = TRUE;
    }

    if (s_JetGetSystemParameterW)
        return s_JetGetSystemParameterW(instance, sesid, paramid, plParam, szParam, cbMax);
    return -1;
}

inline JET_ERR JetCloseTableXp(JET_SESID sesid, JET_TABLEID tableid)
{
    typedef JET_ERR(WINAPI * PFN_JetCloseTable)(JET_SESID sesid, JET_TABLEID tableid);
    static PFN_JetCloseTable s_JetCloseTable = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetCloseTable = (PFN_JetCloseTable)GetProcAddress(hmod, "JetCloseTable");
        s_is_init = TRUE;
    }

    if (s_JetCloseTable)
        return s_JetCloseTable(sesid, tableid);
    return -1;
}

inline JET_ERR JetMoveXp(JET_SESID sesid, JET_TABLEID tableid, long cRow, JET_GRBIT grbit)
{
    typedef JET_ERR(WINAPI * PFN_JetMove)(JET_SESID sesid, JET_TABLEID tableid, long cRow, JET_GRBIT grbit);
    static PFN_JetMove s_JetMove = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetMove = (PFN_JetMove)GetProcAddress(hmod, "JetMove");
        s_is_init = TRUE;
    }

    if (s_JetMove)
        return s_JetMove(sesid, tableid, cRow, grbit);
    return -1;
}

inline JET_ERR JetRetrieveColumnXp(JET_SESID sesid, JET_TABLEID tableid, JET_COLUMNID columnid, void* pvData, unsigned long cbData, unsigned long* pcbActual,
    JET_GRBIT grbit, JET_RETINFO* pretinfo)
{
    typedef JET_ERR(WINAPI * PFN_JetRetrieveColumn)(JET_SESID sesid, JET_TABLEID tableid, JET_COLUMNID columnid, void* pvData, unsigned long cbData,
        unsigned long* pcbActual, JET_GRBIT grbit, JET_RETINFO* pretinfo);
    static PFN_JetRetrieveColumn s_JetRetrieveColumn = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetRetrieveColumn = (PFN_JetRetrieveColumn)GetProcAddress(hmod, "JetRetrieveColumn");
        s_is_init = TRUE;
    }

    if (s_JetRetrieveColumn)
        return s_JetRetrieveColumn(sesid, tableid, columnid, pvData, cbData, pcbActual, grbit, pretinfo);
    return -1;
}

inline JET_ERR JetTermXp(JET_INSTANCE instance)
{
    typedef JET_ERR(WINAPI * PFN_JetTerm)(JET_INSTANCE instance);
    static PFN_JetTerm s_JetTerm = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetTerm = (PFN_JetTerm)GetProcAddress(hmod, "JetTerm");
        s_is_init = TRUE;
    }

    if (s_JetTerm)
        return s_JetTerm(instance);
    return -1;
}

inline JET_ERR JetInitXp(JET_INSTANCE* instance)
{
    typedef JET_ERR(WINAPI * PFN_JetInit)(JET_INSTANCE * instance);
    static PFN_JetInit s_JetInit = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"ESENT.dll");
        s_JetInit = (PFN_JetInit)GetProcAddress(hmod, "JetInit");
        s_is_init = TRUE;
    }

    if (s_JetInit)
        return s_JetInit(instance);
    return -1;
}

#else

#define JetBeginSessionWXp JetBeginSessionW
#define JetGetTableColumnInfoWXp JetGetTableColumnInfoW
#define JetSetSystemParameterWXp JetSetSystemParameterW
#define JetOpenTableWXp JetOpenTableW
#define JetOpenDatabaseWXp JetOpenDatabaseW
#define JetCreateInstanceWXp JetCreateInstanceW
#define JetAttachDatabase2WXp JetAttachDatabase2W
#define JetGetSystemParameterWXp JetGetSystemParameterW
#define JetCloseTableXp JetCloseTable
#define JetMoveXp JetMove
#define JetRetrieveColumnXp JetRetrieveColumn
#define JetTermXp JetTerm
#define JetInitXp JetInit

#endif // SUPPORT_XP_CODE
#endif // patch_code_esent_xp_h