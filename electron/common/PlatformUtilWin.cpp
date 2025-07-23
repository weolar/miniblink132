// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/PlatformUtil.h"

#include "electron/common/gin_helper/arguments.h"
#include "electron/common/BaseMacros.h"
#include "base/files/file_path.h"
#include "base/logging.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/win/scoped_co_mem.h"
#include "base/win/scoped_com_initializer.h"
//#include "base/win/scoped_comptr.h"
#include "base/win/windows_version.h"
#include "base/win/registry.h"
#include "ui/base/win/shell.h"
#include "base/memory/scoped_refptr.h"

#include "v8.h"
#include <windows.h>
#include <commdlg.h>
#include <comdef.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <cstdint>
#include <vector>
#include <algorithm>
#include "third_party/skia/include/core/SkBitmap.h"
#include "ui/gfx/image/image.h"  // 用于 gfx::Image::CreateFrom1xPNGBytes

namespace {

// Old ShellExecute crashes the process when the command for a given scheme
// is empty. This function tells if it is.

bool ValidateShellCommandForScheme(const std::string& scheme)
{
    base::win::RegKey key;
    std::u16string registry_path = base::ASCIIToUTF16(scheme) + u"\\shell\\open\\command";
    key.Open(HKEY_CLASSES_ROOT, (const WCHAR*)registry_path.c_str(), KEY_READ);
    if (!key.Valid())
        return false;
    DWORD size = 0;
    key.ReadValue(NULL, NULL, &size, NULL);
    if (size <= 2)
        return false;
}

// Required COM implementation of IFileOperationProgressSink so we can
// precheck files before deletion to make sure they can be move to the
// Recycle Bin.
class DeleteFileProgressSink : public IFileOperationProgressSink {
public:
    DeleteFileProgressSink();

private:
    ULONG STDMETHODCALLTYPE AddRef(void);
    ULONG STDMETHODCALLTYPE Release(void);
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, LPVOID* ppvObj);
    HRESULT STDMETHODCALLTYPE StartOperations(void);
    HRESULT STDMETHODCALLTYPE FinishOperations(HRESULT);
    HRESULT STDMETHODCALLTYPE PreRenameItem(DWORD, IShellItem*, LPCWSTR);
    HRESULT STDMETHODCALLTYPE PostRenameItem(DWORD, IShellItem*, LPCWSTR, HRESULT, IShellItem*);
    HRESULT STDMETHODCALLTYPE PreMoveItem(DWORD, IShellItem*, IShellItem*, LPCWSTR);
    HRESULT STDMETHODCALLTYPE PostMoveItem(DWORD, IShellItem*, IShellItem*, LPCWSTR, HRESULT, IShellItem*);
    HRESULT STDMETHODCALLTYPE PreCopyItem(DWORD, IShellItem*, IShellItem*, LPCWSTR);
    HRESULT STDMETHODCALLTYPE PostCopyItem(DWORD, IShellItem*, IShellItem*, LPCWSTR, HRESULT, IShellItem*);
    HRESULT STDMETHODCALLTYPE PreDeleteItem(DWORD, IShellItem*);
    HRESULT STDMETHODCALLTYPE PostDeleteItem(DWORD, IShellItem*, HRESULT, IShellItem*);
    HRESULT STDMETHODCALLTYPE PreNewItem(DWORD, IShellItem*, LPCWSTR);
    HRESULT STDMETHODCALLTYPE PostNewItem(DWORD, IShellItem*, LPCWSTR, LPCWSTR, DWORD, HRESULT, IShellItem*);
    HRESULT STDMETHODCALLTYPE UpdateProgress(UINT, UINT);
    HRESULT STDMETHODCALLTYPE ResetTimer(void);
    HRESULT STDMETHODCALLTYPE PauseTimer(void);
    HRESULT STDMETHODCALLTYPE ResumeTimer(void);

    ULONG m_cRef;
};

DeleteFileProgressSink::DeleteFileProgressSink()
{
    m_cRef = 0;
}

HRESULT DeleteFileProgressSink::PreDeleteItem(DWORD dwFlags, IShellItem*)
{
    if (!(dwFlags & TSF_DELETE_RECYCLE_IF_POSSIBLE)) {
        // TSF_DELETE_RECYCLE_IF_POSSIBLE will not be set for items that cannot be
        // recycled.  In this case, we abort the delete operation.  This bubbles
        // up and stops the Delete in IFileOperation.
        return E_ABORT;
    }
    // Returns S_OK if successful, or an error value otherwise. In the case of an
    // error value, the delete operation and all subsequent operations pending
    // from the call to IFileOperation are canceled.
    return S_OK;
}

HRESULT DeleteFileProgressSink::QueryInterface(REFIID riid, LPVOID* ppvObj)
{
    // Always set out parameter to NULL, validating it first.
    if (!ppvObj)
        return E_INVALIDARG;
    *ppvObj = nullptr;
    DebugBreak();

    //     if (riid == IID_IUnknown || riid == IID_IFileOperationProgressSink) {
    //         // Increment the reference count and return the pointer.
    //         *ppvObj = reinterpret_cast<IUnknown*>(this);
    //         AddRef();
    //         return NOERROR;
    //     }
    return E_NOINTERFACE;
}

ULONG DeleteFileProgressSink::AddRef()
{
    //InterlockedIncrement(&m_cRef);
    DebugBreak();
    return m_cRef;
}

ULONG DeleteFileProgressSink::Release()
{
    // Decrement the object's internal counter.
    //     ULONG ulRefCount = InterlockedDecrement(&m_cRef);
    //     if (0 == m_cRef) {
    //         delete this;
    //     }
    //    return ulRefCount;
    DebugBreak();
    return 0;
}

HRESULT DeleteFileProgressSink::StartOperations()
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::FinishOperations(HRESULT)
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::PreRenameItem(DWORD, IShellItem*, LPCWSTR)
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::PostRenameItem(DWORD, IShellItem*, LPCWSTR, HRESULT, IShellItem*)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::PreMoveItem(DWORD, IShellItem*, IShellItem*, LPCWSTR)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::PostMoveItem(DWORD, IShellItem*, IShellItem*, LPCWSTR, HRESULT, IShellItem*)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::PreCopyItem(DWORD, IShellItem*, IShellItem*, LPCWSTR)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::PostCopyItem(DWORD, IShellItem*, IShellItem*, LPCWSTR, HRESULT, IShellItem*)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::PostDeleteItem(DWORD, IShellItem*, HRESULT, IShellItem*)
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::PreNewItem(DWORD dwFlags, IShellItem*, LPCWSTR)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::PostNewItem(DWORD, IShellItem*, LPCWSTR, LPCWSTR, DWORD, HRESULT, IShellItem*)
{
    return E_NOTIMPL;
}

HRESULT DeleteFileProgressSink::UpdateProgress(UINT, UINT)
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::ResetTimer()
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::PauseTimer()
{
    return S_OK;
}

HRESULT DeleteFileProgressSink::ResumeTimer()
{
    return S_OK;
}

} // namespace

namespace platform_util {

void showItemInFolder(const base::FilePath& full_path)
{
    base::win::ScopedCOMInitializer com_initializer;
    if (!com_initializer.Succeeded())
        return;

    base::FilePath dir = full_path.DirName().AsEndingWithSeparator();
    // ParseDisplayName will fail if the directory is "C:", it must be "C:\\".
    if (dir.empty())
        return;

    typedef HRESULT(WINAPI * SHOpenFolderAndSelectItemsFuncPtr)(ITEMIDLIST * pidl_Folder, UINT cidl, const ITEMIDLIST** pidls, DWORD flags);

    static SHOpenFolderAndSelectItemsFuncPtr open_folder_and_select_itemsPtr = NULL;
    static bool initialize_open_folder_proc = true;
    if (initialize_open_folder_proc) {
        initialize_open_folder_proc = false;
        // The SHOpenFolderAndSelectItems API is exposed by shell32 version 6
        // and does not exist in Win2K. We attempt to retrieve this function export
        // from shell32 and if it does not exist, we just invoke ShellExecute to
        // open the folder thus losing the functionality to select the item in
        // the process.
        HMODULE shell32_base = GetModuleHandle(L"shell32.dll");
        if (!shell32_base) {
            //NOTREACHED() << " " << __FUNCTION__ << "(): Can't open shell32.dll";
            return;
        }
        open_folder_and_select_itemsPtr = reinterpret_cast<SHOpenFolderAndSelectItemsFuncPtr>(GetProcAddress(shell32_base, "SHOpenFolderAndSelectItems"));
    }
    if (!open_folder_and_select_itemsPtr) {
        ui::win::OpenFolderViaShell(dir);
        return;
    }

    //base::win::ScopedComPtr<IShellFolder> desktop;
    IShellFolder* ptr = nullptr;
    HRESULT hr = SHGetDesktopFolder(&ptr);
    if (FAILED(hr))
        return;
    scoped_refptr<IShellFolder> desktop(ptr);
    ptr->Release(); // 这里引用技术不知道对不对
    *(int*)1 = 1;

    base::win::ScopedCoMem<ITEMIDLIST> dir_item;
    hr = desktop->ParseDisplayName(NULL, NULL, const_cast<wchar_t*>(dir.value().c_str()), NULL, &dir_item, NULL);
    if (FAILED(hr)) {
        ui::win::OpenFolderViaShell(dir);
        return;
    }

    base::win::ScopedCoMem<ITEMIDLIST> file_item;
    hr = desktop->ParseDisplayName(NULL, NULL, const_cast<wchar_t*>(full_path.value().c_str()), NULL, &file_item, NULL);
    if (FAILED(hr)) {
        ui::win::OpenFolderViaShell(dir);
        return;
    }

    const ITEMIDLIST* highlight[] = { file_item };

    hr = (*open_folder_and_select_itemsPtr)(dir_item, arraysize(highlight), highlight, NULL);

    if (FAILED(hr)) {
        // On some systems, the above call mysteriously fails with "file not
        // found" even though the file is there.  In these cases, ShellExecute()
        // seems to work as a fallback (although it won't select the file).
        if (hr == ERROR_FILE_NOT_FOUND) {
            ui::win::OpenFolderViaShell(dir);
        } else {
            LPTSTR message = NULL;
            DWORD message_length
                = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 0, hr, 0, reinterpret_cast<LPTSTR>(&message), 0, NULL);
            //            LOG(WARNING) << " " << __FUNCTION__
            //                << "(): Can't open full_path = \""
            //                 << full_path.value() << "\""
            //                 << " hr = " << hr
            //                 << " " << reinterpret_cast<LPTSTR>(&message);
            if (message)
                LocalFree(message);

            ui::win::OpenFolderViaShell(dir);
        }
    }
}

void openItem(const base::FilePath& full_path)
{
    if (::PathIsDirectoryW(full_path.value().c_str()))
        ui::win::OpenFolderViaShell(full_path);
    else
        ui::win::OpenFileViaShell(full_path);
}

class OpenExternal {
public:
    OpenExternal(const std::u16string& url, bool activate)
        : m_url(url)
        , m_activate(activate)
        , m_wait(0)
    {
    }

    bool call()
    {
        bool retVal = false;
        m_retVal = &retVal;
        ::CreateThread(nullptr, 0, &OpenExternal::threadEnter, this, 0, 0);
        while (0 == m_wait) {
            ::Sleep(10);
        }
        return retVal;
    }

    static DWORD WINAPI threadEnter(LPVOID lpThreadParameter)
    {
        OpenExternal* self = (OpenExternal*)lpThreadParameter;
        *(self->m_retVal) = self->openExternalImpl(self->m_url, self->m_activate);
        self->m_wait = 1;
        return 0;
    }

    bool openExternalImpl(const std::u16string& url, bool activate)
    {
        // Quote the input scheme to be sure that the command does not have
        // parameters unexpected by the external program. This url should already
        // have been escaped.
        std::u16string escaped_url = (const char16_t*)L"\"" + url + (const char16_t*)L"\"";

        if (reinterpret_cast<ULONG_PTR>(ShellExecuteW(NULL, L"open", (LPCWSTR)escaped_url.c_str(), NULL, NULL, SW_SHOWNORMAL)) <= 32) {
            // We fail to execute the call. We could display a message to the user.
            // TODO(nsylvain): we should also add a dialog to warn on errors. See
            // bug 1136923.
            return false;
        }
        return true;
    }

private:
    std::u16string m_url;
    bool m_activate;
    bool* m_retVal;
    int m_wait;
};

bool openExternal(const std::u16string& url, bool activate)
{
    OpenExternal threader(url, activate);
    return threader.call();
}

void moveToCenter(HWND hWnd)
{
    int width = 0;
    int height = 0;

    RECT rect = { 0 };
    ::GetWindowRect(hWnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;

    int parentWidth = 0;
    int parentHeight = 0;

    parentWidth = ::GetSystemMetrics(SM_CXSCREEN);
    parentHeight = ::GetSystemMetrics(SM_CYSCREEN);

    int x = (parentWidth - width) / 2;
    int y = (parentHeight - height) / 2;

    ::MoveWindow(hWnd, x, y, width, height, TRUE);
}

#define FOFX_ADDUNDORECORD 0x20000000
#define FOFX_RECYCLEONDELETE 0x00080000

bool moveItemToTrash(const base::FilePath& path)
{
    DebugBreak();
    return false;
    //     base::win::ScopedCOMInitializer com_initializer;
    //     if (!com_initializer.succeeded())
    //         return false;
    //
    //     SkTScopedComPtr<IFileOperation> pfo;
    //     //     if (FAILED(pfo.CreateInstance(CLSID_FileOperation)))
    //     //         return false;
    //
    //     // Elevation prompt enabled for UAC protected files.  This overrides the
    //     // SILENT, NO_UI and NOERRORUI flags.
    //
    //     if (base::win::GetVersion() >= base::win::VERSION_WIN8) {
    //         // Windows 8 introduces the flag RECYCLEONDELETE and deprecates the
    //         // ALLOWUNDO in favor of ADDUNDORECORD.
    //         if (FAILED(pfo->SetOperationFlags(FOF_NO_UI | FOFX_ADDUNDORECORD | FOF_NOERRORUI | FOF_SILENT | FOFX_SHOWELEVATIONPROMPT | FOFX_RECYCLEONDELETE)))
    //             return false;
    //     } else {
    //         // For Windows 7 and Vista, RecycleOnDelete is the default behavior.
    //         if (FAILED(pfo->SetOperationFlags(FOF_NO_UI | FOF_ALLOWUNDO | FOF_NOERRORUI | FOF_SILENT | FOFX_SHOWELEVATIONPROMPT)))
    //             return false;
    //     }
    //
    //     // Create an IShellItem from the supplied source path.
    //     SkTScopedComPtr<IShellItem> delete_item;
    //     //     if (FAILED(SHCreateItemFromParsingName(path.value().c_str(), NULL, IID_PPV_ARGS(delete_item.Receive()))))
    //     //         return false;
    //
    //     // https://stackoverflow.com/questions/20885556/replacement-for-shcreateitemfromparsingname-on-windows-xp
    //     // http://blog.csdn.net/infoworld/article/details/54574953
    //     IFileDialog* pfd = nullptr;
    //     LPITEMIDLIST pidl = nullptr;
    //     HRESULT hresult = ::SHParseDisplayName(path.value().c_str(), 0, &pidl, SFGAO_FOLDER, 0);
    //     if (SUCCEEDED(hresult)) {
    //         IShellFolder* psf = nullptr;
    //         hresult = ::SHGetDesktopFolder(&psf);
    //         if (SUCCEEDED(hresult)) {
    //             hresult = psf->BindToObject(pidl, 0, IID_IShellFolder, (void**)delete_item.Receive());
    //             if (SUCCEEDED(hresult)) {
    //                 pfd->SetFolder(delete_item.get());
    //             }
    //         }
    //     }
    //
    //     SkTScopedComPtr<IFileOperationProgressSink> delete_sink(new DeleteFileProgressSink);
    //     if (!delete_sink)
    //         return false;
    //
    //     // Processes the queued command DeleteItem. This will trigger
    //     // the DeleteFileProgressSink to check for Recycle Bin.
    //     bool b = SUCCEEDED(pfo->DeleteItem(delete_item.get(), delete_sink.get())) && SUCCEEDED(pfo->PerformOperations());
    //     return b;
}

void beep()
{
    MessageBeep(MB_OK);
}

#pragma pack(push)
#pragma pack(2)
// 定义 ICO 头结构
struct IconDir {
    uint16_t idReserved;  // 必须为 0
    uint16_t idType;      // 必须为 1（图标）
    uint16_t idCount;     // 图标数量
};

// 定义图标目录项结构
struct IconDirEntry {
    uint8_t bWidth;          // 宽度（0 表示 256）
    uint8_t bHeight;         // 高度（0 表示 256）
    uint8_t bColorCount;     // 颜色数（0 表示 24/32 位）
    uint8_t bReserved;       // 保留，必须为 0
    uint16_t wPlanes;        // 颜色平面数（通常为 1）
    uint16_t wBitCount;      // 每像素位数（如 32）
    uint32_t dwBytesInRes;   // 图像数据大小
    uint32_t dwImageOffset;  // 图像数据偏移量
};

// ICONDIRENTRY contains meta data for an individual icon image within a
// .ico file.
struct ICONDIRENTRY {
    BYTE bWidth;
    BYTE bHeight;
    BYTE bColorCount;
    BYTE bReserved;
    WORD wPlanes;
    WORD wBitCount;
    DWORD dwBytesInRes;
    DWORD dwImageOffset;
};

// ICONDIR Contains information about all the icon images contained within a
// single .ico file.
struct ICONDIR {
    WORD idReserved;
    WORD idType;
    WORD idCount;
    ICONDIRENTRY idEntries[1];
};

// GRPICONDIRENTRY contains meta data for an individual icon image within a
// RT_GROUP_ICON resource in an .exe or .dll.
struct GRPICONDIRENTRY {
    BYTE bWidth;
    BYTE bHeight;
    BYTE bColorCount;
    BYTE bReserved;
    WORD wPlanes;
    WORD wBitCount;
    DWORD dwBytesInRes;
    WORD nID;
};

// GRPICONDIR Contains information about all the icon images contained within
// a RT_GROUP_ICON resource in an .exe or .dll.
struct GRPICONDIR {
    WORD idReserved;
    WORD idType;
    WORD idCount;
    GRPICONDIRENTRY idEntries[1];
};

// Contains the actual icon image.
struct ICONIMAGE {
    BITMAPINFOHEADER icHeader;
    RGBQUAD icColors[1];
    BYTE icXOR[1];
    BYTE icAND[1];
};
#pragma pack(pop)

bool parseBMPToSkBitmap(const uint8_t* bmpData, size_t bmpSize, SkBitmap* outBitmap);

// 函数：从二进制 ICO 数据加载为 SkBitmap
bool loadIconFromICOToSkBitmap(const uint8_t* data, size_t dataSize, SkBitmap* outBitmap)
{
    if (!data || dataSize < sizeof(IconDir) || !outBitmap) {
        return false;
    }

    // Step 1: 解析 ICO 头
    const IconDir* iconDir = reinterpret_cast<const IconDir*>(data);
    if (iconDir->idReserved != 0 || iconDir->idType != 1) {
        return false; // 不是有效的 ICO 文件
    }

    if (iconDir->idCount == 0) {
        return false; // 没有图标
    }

    // Step 2: 遍历图标目录项，找到第一个支持的图像（比如 32x32 的 32 位）
    const IconDirEntry* entries = reinterpret_cast<const IconDirEntry*>(data + sizeof(IconDir));
    for (uint16_t i = 0; i < iconDir->idCount; ++i) {
        const IconDirEntry& entry = entries[i];

        // 跳过无效条目（如宽度/高度为 0）
        if (entry.bWidth == 0 || entry.bHeight == 0)
            continue;

        // 检查是否支持该格式（这里我们只支持 32 位色深的图标）
        //if (entry.wBitCount != 32)
        //    continue;

        // 检查偏移量是否在数据范围内
        if (entry.dwImageOffset + entry.dwBytesInRes > dataSize)
            continue;

        // 获取图像数据
        const uint8_t* imageData = data + entry.dwImageOffset;
        size_t imageSize = entry.dwBytesInRes;

        ICONIMAGE* iconHead = (ICONIMAGE*)imageData;

        char output[120] = { 0 };
        sprintf(output, "biSize: (%d, %d)%d(%d, %d)\n", 
            entry.bWidth, entry.bHeight,
            entry.wBitCount,
            iconHead->icHeader.biWidth, iconHead->icHeader.biHeight);
        OutputDebugStringA(output);

        bool isPng = iconHead->icHeader.biCompression;

        DebugBreak();
//         if (isPng) {
//             // Step 4: 如果是 PNG，直接使用 gfx::Image::CreateFrom1xPNGBytes 加载
//             *outBitmap = gfx::Image::CreateFrom1xPNGBytes(base::span<const uint8_t>(imageData, imageSize)).AsBitmap();
//             return !outBitmap->isNull();
//         } else {
//             // Step 4: 如果是 BMP，手动解析 BMP 数据并填充 SkBitmap
//             if (!parseBMPToSkBitmap(imageData, imageSize, outBitmap)) {
//                 continue;  // 解析失败，尝试下一个图标
//             }
//             return !outBitmap->isNull();
//         }
    }

    return false;  // 没有找到支持的图标
}

// 手动解析 BMP 数据并填充 SkBitmap
bool parseBMPToSkBitmap(const uint8_t* bmpData, size_t bmpSize, SkBitmap* outBitmap)
{
    if (!bmpData || bmpSize < sizeof(BITMAPINFOHEADER) || !outBitmap) {
        return false;
    }

    // Step 1: 解析 BITMAPINFOHEADER
    const BITMAPINFOHEADER* bmiHeader = reinterpret_cast<const BITMAPINFOHEADER*>(bmpData);
    if (bmiHeader->biSize != sizeof(BITMAPINFOHEADER))
        return false;  // 不支持的 BMP 格式

    // 只支持 32 位 BMP
    if (bmiHeader->biBitCount != 32)
        return false;

    int width = bmiHeader->biWidth;
    int height = abs(bmiHeader->biHeight);  // BMP 高度可能是负数（表示从上到下存储）

    // Step 2: 创建 SkImageInfo
    SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);

    // Step 3: 分配 SkBitmap 像素
    if (!outBitmap->tryAllocPixels(info))
        return false;

    // Step 4: 计算 BMP 数据的起始位置（跳过 BITMAPINFOHEADER）
    const uint8_t* pixelData = bmpData + bmiHeader->biSize;

    // 如果有颜色表（biBitCount <= 8），需要跳过颜色表
    if (bmiHeader->biBitCount <= 8) {
        int colorTableSize = bmiHeader->biClrUsed * 4;  // 每个颜色项 4 字节
        if (colorTableSize == 0) {
            colorTableSize = 1 << bmiHeader->biBitCount * 4;
        }
        pixelData += colorTableSize;
    }

    // Step 5: BMP 数据可能是从下到上存储的，需要垂直翻转
    // 计算每行的字节数（包括填充）
    int rowBytes = (width * 4 + 3) & ~3;  // 4 字节对齐
    //std::vector<uint8_t> row_buffer(rowBytes);

    uint8_t* dstPixels = static_cast<uint8_t*>(outBitmap->getPixels());
    for (int y = 0; y < height; ++y) {
        // 计算当前行的起始位置
        const uint8_t* srcRow = pixelData + (height - 1 - y) * rowBytes;
        uint8_t* dstRow = dstPixels + y * outBitmap->rowBytes();

        // 复制一行数据
        memcpy(dstRow, srcRow, rowBytes);
    }

    return true;
}

static HRESULT createStreamOnMemory(const BYTE* pData, DWORD dwSize, IStream** ppStream)
{
    if (!pData || dwSize == 0 || !ppStream)
        return E_INVALIDARG;

    // 分配全局内存
    HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, dwSize);
    if (!hGlobal)
        return E_OUTOFMEMORY;

    // 锁定内存并复制数据
    void* pGlobalData = GlobalLock(hGlobal);
    if (!pGlobalData) {
        GlobalFree(hGlobal);
        return E_OUTOFMEMORY;
    }
    memcpy(pGlobalData, pData, dwSize);
    GlobalUnlock(hGlobal);

    // 创建流
    HRESULT hr = CreateStreamOnHGlobal(hGlobal, TRUE, ppStream); // 自动释放 hGlobal
    if (FAILED(hr))
        GlobalFree(hGlobal);

    return hr;
}

void* loadIconFromMemory(const uint8_t* pData, size_t dwSize, void* hIcon)
{
    if (!pData || dwSize == 0)
        return nullptr;

//     HICON xx = CreateIconFromResourceEx(
//         (PBYTE)pData,
//         (DWORD)dwSize,
//         TRUE,
//         0x00030000,
//         0,
//         0,
//         LR_DEFAULTSIZE | LR_SHARED);

    IStream* pStream = nullptr;
    HRESULT hr = createStreamOnMemory(pData, dwSize, &pStream);
    if (FAILED(hr))
        return nullptr;

    // 使用 OleLoadPicture 加载 IPicture
    IPicture* pPicture = nullptr;
    hr = OleLoadPicture(pStream, dwSize, FALSE, IID_IPicture, (void**)&pPicture);
    pStream->Release(); // 释放流，因为 OleLoadPicture 已经增加了引用计数
    if (FAILED(hr))
        return nullptr;

    SHORT type = 0;
    pPicture->get_Type(&type);
    if (PICTYPE_ICON != type) {
        pPicture->Release();
        return nullptr;
    }

    // 从 IPicture 获取 HICON
    OLE_HANDLE hIconHandle = 0;
    hr = pPicture->get_Handle((OLE_HANDLE*)&hIconHandle);
    if (FAILED(hr)) {
        pPicture->Release();
        return nullptr;
    }

    // OLE_HANDLE 实际上是一个 UINT_PTR，在 Windows 中就是 HICON
    *(HICON*)hIcon = (HICON)hIconHandle;
    return pPicture;
}

void loadIconFromMemoryFree(void* picture)
{
    IPicture* pPicture = (IPicture*)picture;
    //pPicture->Release();
}

} // namespace platform_util
