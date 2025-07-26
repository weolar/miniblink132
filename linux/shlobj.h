#ifndef windows_for_linux_ShlObj_h
#define windows_for_linux_ShlObj_h

#include "windows.h"
#include "shlwapi.h"
#include "unknwn.h"

#define BIF_BROWSEINCLUDEFILES 0x00004000

typedef enum tagCLSCTX {
    CLSCTX_INPROC_SERVER = 0x1,
    CLSCTX_INPROC_HANDLER = 0x2,
    CLSCTX_LOCAL_SERVER = 0x4,
    CLSCTX_INPROC_SERVER16 = 0x8,
    CLSCTX_REMOTE_SERVER = 0x10,
    CLSCTX_INPROC_HANDLER16 = 0x20,
    CLSCTX_RESERVED1 = 0x40,
    CLSCTX_RESERVED2 = 0x80,
    CLSCTX_RESERVED3 = 0x100,
    CLSCTX_RESERVED4 = 0x200,
    CLSCTX_NO_CODE_DOWNLOAD = 0x400,
    CLSCTX_RESERVED5 = 0x800,
    CLSCTX_NO_CUSTOM_MARSHAL = 0x1000,
    CLSCTX_ENABLE_CODE_DOWNLOAD = 0x2000,
    CLSCTX_NO_FAILURE_LOG = 0x4000,
    CLSCTX_DISABLE_AAA = 0x8000,
    CLSCTX_ENABLE_AAA = 0x10000,
    CLSCTX_FROM_DEFAULT_CONTEXT = 0x20000,
    CLSCTX_ACTIVATE_32_BIT_SERVER = 0x40000,
    CLSCTX_ACTIVATE_64_BIT_SERVER = 0x80000,
    CLSCTX_ENABLE_CLOAKING = 0x100000,
    CLSCTX_PS_DLL = (int)0x80000000
} CLSCTX;

#define CLSCTX_ALL (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER)

#define E_POINTER (0x80000005L)
#define S_OK ((HRESULT)0L)

// typedef struct tagFORMATETC {
//     CLIPFORMAT cfFormat;
//     DVTARGETDEVICE* ptd;
//     DWORD dwAspect;
//     LONG lindex;
//     DWORD tymed;
// } FORMATETC;

typedef struct tagFORMATETC* LPFORMATETC;
typedef struct uSTGMEDIUM STGMEDIUM;
typedef tagFORMATETC FORMATETC;

class IDataObject : public IUnknown {
public:
    virtual /* [local] */ HRESULT GetData(
        /* [unique][in] */ FORMATETC* pformatetcIn,
        /* [out] */ STGMEDIUM* pmedium)
        = 0;

    virtual /* [local] */ HRESULT GetDataHere(
        /* [unique][in] */ FORMATETC* pformatetc,
        /* [out][in] */ STGMEDIUM* pmedium)
        = 0;

    virtual HRESULT QueryGetData(
        /* [unique][in] */ FORMATETC* pformatetc)
        = 0;

    virtual HRESULT GetCanonicalFormatEtc(
        /* [unique][in] */ FORMATETC* pformatectIn,
        /* [out] */ FORMATETC* pformatetcOut)
        = 0;

    virtual /* [local] */ HRESULT SetData(
        /* [unique][in] */ FORMATETC* pformatetc,
        /* [unique][in] */ STGMEDIUM* pmedium,
        /* [in] */ BOOL fRelease)
        = 0;

    virtual HRESULT EnumFormatEtc(
        /* [in] */ DWORD dwDirection,
        /* [out] */ /*IEnumFORMATETC*/ void** ppenumFormatEtc)
        = 0;

    virtual HRESULT DAdvise(
        /* [in] */ FORMATETC* pformatetc,
        /* [in] */ DWORD advf,
        /* [unique][in] */ /*IAdviseSink*/ void* pAdvSink,
        /* [out] */ DWORD* pdwConnection)
        = 0;

    virtual HRESULT DUnadvise(
        /* [in] */ DWORD dwConnection)
        = 0;

    virtual HRESULT EnumDAdvise(
        /* [out] */ /*IEnumSTATDATA*/ void** ppenumAdvise)
        = 0;
};

class IDropTarget : public IUnknown {
public:
    virtual HRESULT DragEnter(
        /* [unique][in] */ IDataObject* pDataObj,
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD* pdwEffect)
        = 0;

    virtual HRESULT DragOver(
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD* pdwEffect)
        = 0;

    virtual HRESULT DragLeave(void) = 0;

    virtual HRESULT Drop(
        /* [unique][in] */ IDataObject* pDataObj,
        /* [in] */ DWORD grfKeyState,
        /* [in] */ POINTL pt,
        /* [out][in] */ DWORD* pdwEffect)
        = 0;
};

class IDropTargetHelper : public IUnknown {
public:
    virtual HRESULT DragEnter(
        /* [annotation][in] */
        HWND hwndTarget,
        /* [annotation][in] */
        IDataObject* pDataObject,
        /* [annotation][in] */
        POINT* ppt,
        /* [annotation][in] */
        DWORD dwEffect)
        = 0;

    virtual HRESULT DragLeave(void) = 0;

    virtual HRESULT DragOver(
        /* [annotation][in] */
        POINT* ppt,
        /* [annotation][in] */
        DWORD dwEffect)
        = 0;

    virtual HRESULT Drop(
        /* [annotation][in] */
        IDataObject* pDataObject,
        /* [annotation][in] */
        POINT* ppt,
        /* [annotation][in] */
        DWORD dwEffect)
        = 0;

    virtual HRESULT Show(
        /* [annotation][in] */ BOOL fShow)
        = 0;
};

typedef struct _SHITEMID {
    USHORT cb;
    BYTE abID[1];
} SHITEMID;

typedef struct _ITEMIDLIST {
    SHITEMID mkid;
} ITEMIDLIST;

typedef int (*BFFCALLBACK)(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);
typedef const ITEMIDLIST* LPCITEMIDLIST;

typedef struct _browseinfoW {
    HWND hwndOwner;
    const ITEMIDLIST* pidlRoot;
    LPWSTR pszDisplayName; // Return display name of item selected.
    LPCWSTR lpszTitle; // text to go in the banner over the tree.
    UINT ulFlags; // Flags that control the return stuff
    BFFCALLBACK lpfn;
    LPARAM lParam; // extra info that's passed back in callbacks
    int iImage; // output var: where to return the Image index.
} BROWSEINFOW, *PBROWSEINFOW, *LPBROWSEINFOW;

typedef ITEMIDLIST* LPITEMIDLIST;

ITEMIDLIST* SHBrowseForFolderW(LPBROWSEINFOW lpbi);
BOOL SHGetPathFromIDListW(const ITEMIDLIST* pidl, LPWSTR pszPath);

BOOL GetOpenFileNameW(LPOPENFILENAMEW);

HRESULT CoCreateInstance(const IID& rclsid, IUnknown* pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID* ppv);

#endif // windows_for_linux_ShlObj_h