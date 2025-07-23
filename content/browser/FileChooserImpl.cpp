
#include "content/browser/FileChooserImpl.h"
#include "content/browser/MbWebview.h"
#include "content/common/ThreadCall.h"
#include "content/common/WebMimeRegistryImpl.h"
#include "content/common/LiveIdDetect.h"
#include "third_party/blink/public/platform/web_string.h"
#include "base/strings/utf_string_conversions.h"
#include "base/files/file.h"
#include <vector>
#include <shlwapi.h>
#include <shlobj.h>
#include <process.h>
#include <commdlg.h>

namespace content {

static void appendStringToVector(std::vector<char>* result, const Vector<char>& str)
{
    result->reserve(result->size() + str.size());
    const char* p = str.data();
    const char* end = p + str.size();
    while (p < end) {
        result->push_back(*p);
        ++p;
    }
}

static void appendStringToVector(std::vector<char>* result, const std::vector<char>& str)
{
    result->reserve(result->size() + str.size());
    const char* p = str.data();
    const char* end = p + str.size();
    while (p < end) {
        result->push_back(*p);
        ++p;
    }
}

static void appendStringToVector(std::vector<char>* result, const std::string& str)
{
    Vector<char> strBuf;
    strBuf.resize(str.size());
    memcpy(strBuf.data(), str.c_str(), str.size());
    appendStringToVector(result, strBuf);
}

std::string extentionForMimeType(const Vector<char>& mimeType)
{
    const char* end = mimeType.data() + mimeType.size();
    const char* p = end - 1;
    while (p > mimeType.data()) {
        if ('/' == *p) {
            return std::string(p + 1, end);
        }
        --p;
    }
    return "*";
}

std::string extentionForMimeType(const std::string& mimeType)
{
    Vector<char> mimeTypeBuf;
    mimeTypeBuf.resize(mimeType.size());
    memcpy(mimeTypeBuf.data(), mimeType.c_str(), mimeType.size());
    return extentionForMimeType(mimeTypeBuf);
}

// 现在把所有项都归并到一个项了
static void addForExtensions2(const WTF::Vector<blink::WebString>& exts, std::vector<char>* filter)
{
    if (exts.empty())
        return;

    for (Vector<blink::WebString>::const_iterator it = exts.begin(); it != exts.end(); ++it) {
        std::string str = "*.";
        str += it->Utf8();

        appendStringToVector(filter, str);
        filter->push_back(';');
    }
}

#if defined(OS_WIN)
class OpenFileNameWrap {
public:
    OpenFileNameWrap(::blink::mojom::blink::FileChooserParamsPtr params)
    {
        m_isDirectory = params->mode == blink::mojom::FileChooserParams_Mode::kUploadFolder;

        // image/gif, image/jpeg, image/*
        // Image Files(*.gif;*.jpeg;*.png)\0*.gif;*.jpeg;*.png\0All Files(*.*)\0*.*\0\0
        std::vector<char> filter;

        Vector<blink::WebString> exts;
        for (size_t i = 0; i < params->accept_types.size(); ++i) {
            String mimeType = params->accept_types[i];
            if (mimeType.empty())
                continue;
            if ('.' == mimeType[0])
                mimeType.Remove(0, 1);
            mimeType = mimeType.LowerASCII();

            WebMimeRegistryImpl* mimeRegistry = WebMimeRegistryImpl::get();
            Vector<blink::WebString> tempExts = mimeRegistry->extensionsForMimeType(mimeType);

            for (size_t j = 0; j < tempExts.size(); ++j) {
                exts.push_back(tempExts[j]);
            }
        }

        std::vector<char> filterItem;
        addForExtensions2(exts, &filterItem);

        if (filterItem.size() > 0) {
            appendStringToVector(&filter, "Custom Files(");
            appendStringToVector(&filter, filterItem); // 第一遍是描述
            filter.push_back(')');
            filter.push_back('\0');
            appendStringToVector(&filter, filterItem); // 第二遍是给系统看的
            filter.push_back('\0');
        }

        appendStringToVector(&filter, "All Files");
        filter.push_back('\0');
        appendStringToVector(&filter, "*.*");
        filter.push_back('\0');
        filter.push_back('\0');

        m_titleBuf = base::UTF8ToUTF16(params->title.Utf8());
        if (m_titleBuf.empty())
            m_titleBuf = (const char16_t*)(u"选择文件(Select File)");

        const int kFileNameBufLen = 8192;
        m_fileNameBuf.resize(kFileNameBufLen);
        memset(&m_fileNameBuf[0], 0, sizeof(wchar_t) * kFileNameBufLen);

        ::base::FilePath initialValue = params->default_file_name;
        //Vector<UChar> initialValueBuf;
        if (!initialValue.empty()) {
            //initialValueBuf = WTF::ensureUTF16UChar(initialValue, true);
            std::u16string initialValueW = initialValue.AsUTF16Unsafe();

            if (initialValueW.size() < kFileNameBufLen - 1)
                wcscpy(m_fileNameBuf.data(), (const wchar_t*)initialValueW.c_str());
        }
        filter.push_back('\0');

        base::UTF8ToUTF16(filter.data(), filter.size() - 1, &m_filterW);

        memset(&m_ofn, 0, sizeof(OPENFILENAMEW));
        m_ofn.lStructSize = sizeof(OPENFILENAMEW);
        m_ofn.hwndOwner = nullptr;
        m_ofn.hInstance = nullptr;
        m_ofn.lpstrFilter = (LPCWSTR)(m_filterW.c_str());
        m_ofn.lpstrFile = &m_fileNameBuf[0];
        m_ofn.nMaxFile = kFileNameBufLen - 2;
        m_ofn.lpstrTitle = (LPCWSTR)(m_titleBuf.data());
        m_ofn.Flags = OFN_EXPLORER | OFN_LONGNAMES | OFN_NOCHANGEDIR;
    }

    OPENFILENAMEW* getInfo()
    {
        return &m_ofn;
    }

    const WCHAR* getFileNameBuf()
    {
        return &m_fileNameBuf[0];
    }

    bool isDirectory() const
    {
        return m_isDirectory;
    }

private:
    OPENFILENAMEW m_ofn;
    std::vector<WCHAR> m_fileNameBuf;
    std::u16string m_filterW;
    std::u16string m_titleBuf;

    bool m_isDirectory;
};

class ResponseOpenFileInfoTask {
public:
    ResponseOpenFileInfoTask(::blink::mojom::blink::FileChooser::OpenFileChooserCallback completion, int webviewId, OpenFileNameWrap* wrap, BOOL retVal,
        std::function<void(void)>* completionCallback)
        : m_completion(std::move(completion))
    {
        m_webviewId = webviewId;
        m_wrap = wrap;
        m_retVal = retVal;
        m_completionCallback = completionCallback;
    }

    ~ResponseOpenFileInfoTask()
    {
        delete m_wrap;

        (*m_completionCallback)();
        delete m_completionCallback;
    }

    void run()
    {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_webviewId);
        if (!webview)
            return;

        std::vector<std::u16string> selectedFiles;
        std::vector<std::u16string> selectedFilesRef;

        ::blink::mojom::blink::FileChooserResultPtr fileChooserResult = ::blink::mojom::blink::FileChooserResult::New();

        if (m_retVal) {
            // Figure out if the user selected multiple files.  If fileNameBuf is a directory, then multiple files were selected!
            if ((m_wrap->getInfo()->Flags & OFN_ALLOWMULTISELECT) && (::GetFileAttributesW(m_wrap->getFileNameBuf()) & FILE_ATTRIBUTE_DIRECTORY)) {
                std::u16string dirName = (const char16_t*)m_wrap->getFileNameBuf();
                const WCHAR* p = m_wrap->getFileNameBuf() + wcslen(m_wrap->getFileNameBuf()) + 1;
                while (*p) {
                    selectedFiles.push_back(dirName);
                    selectedFiles.back().append((const char16_t*)L"\\");
                    selectedFiles.back().append((const char16_t*)p);
                    p += wcslen(p) + 1;
                }
                selectedFilesRef.resize(selectedFiles.size());
                for (size_t i = 0; i < selectedFiles.size(); ++i) {
                    selectedFilesRef[i] = selectedFiles[i];
                }
            } else {
                std::u16string name((const char16_t*)m_wrap->getFileNameBuf());
                selectedFilesRef.push_back(name);
            }
        }

        if (0 == selectedFilesRef.size()) {
            std::move(m_completion).Run(std::move(fileChooserResult));
            return;
        }

        for (size_t i = 0; i < selectedFilesRef.size(); ++i) {
            ::blink::mojom::blink::FileChooserFileInfoPtr info(absl::in_place);
            const std::u16string& filePathStr = selectedFilesRef[i];

            int64_t fileSizeResult = 0;
            base::FilePath filePath((const base::FilePath::CharType*)filePathStr.c_str());
            base::File fileObj(filePath, base::File::FLAG_OPEN_ALWAYS | base::File::FLAG_READ);
            base::File::Info fileObjInfo;
            if (!fileObj.GetInfo(&fileObjInfo))
                fileSizeResult = 0;
            else
                fileSizeResult = fileObjInfo.size;

            //info.displayName = blink::Platform::current()->fileUtilities()->baseName(info.path);
            std::u16string fileSystemURL = (const char16_t*)L"file:///" + filePathStr;
            if (m_wrap->isDirectory()) {
                ::base::FilePath filePath = ::base::FilePath::FromUTF16Unsafe(std::u16string_view(filePathStr));
                ::blink::mojom::blink::NativeFileInfoPtr nativeFile(absl::in_place, filePath, ::WTF::String(), WTF::Vector<::WTF::String>());
                info->set_native_file(std::move(nativeFile));
            } else {
                blink::KURL url(WTF::String(fileSystemURL.c_str()));
                ::blink::mojom::blink::FileSystemFileInfoPtr systemFileInfo(absl::in_place, url, fileObjInfo.last_modified, fileSizeResult);
                info->set_file_system(std::move(std::move(systemFileInfo)));
            }

            fileChooserResult->files.push_back(std::move(info));
        }
        std::move(m_completion).Run(std::move(fileChooserResult));
    }

    BOOL m_retVal;

private:
    ::blink::mojom::blink::FileChooser::OpenFileChooserCallback m_completion;
    int m_webviewId;
    OpenFileNameWrap* m_wrap;
    std::function<void(void)>* m_completionCallback;
};

static DWORD __stdcall getOpenFileNameThread(void* param)
{
    std::function<void(void)>* callback = (std::function<void(void)>*)param;
    (*callback)();

    int count = 0;
    MSG msg = { 0 };
    while (true) {
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }
        if (++count > 100)
            break;
        ::Sleep(5);
    }

    delete callback;
    return 0;
}

static HWND createHideWindow()
{
    const WCHAR* s_fileChooserClassName = L"ChooserClass";
    static bool hasRegister = false;
    if (!hasRegister) {
        WNDCLASS wc = { 0 };
        wc.style = 0;
        wc.lpfnWndProc = ::DefWindowProcW;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = NULL;
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.lpszClassName = s_fileChooserClassName;
        ::RegisterClass(&wc);
        hasRegister = true;
    }

    HWND hWnd = ::CreateWindowW(s_fileChooserClassName, s_fileChooserClassName, WS_OVERLAPPEDWINDOW, 2, 2, 1, 1, NULL, NULL, NULL, NULL);

    ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    ::ShowWindow(hWnd, SW_HIDE);

    return hWnd;
}
#endif

static bool runFileChooserImpl(HWND hWnd, ::blink::mojom::blink::FileChooserParamsPtr params,
    ::blink::mojom::blink::FileChooser::OpenFileChooserCallback completion, int webviewId, std::function<void(void)>* completionCallback)
{
#if defined(OS_WIN)
    bool saveAs = params->mode == blink::mojom::FileChooserParams_Mode::kSave;
    bool multiSelect = params->mode == blink::mojom::FileChooserParams_Mode::kOpenMultiple;

    OpenFileNameWrap* wrap = new OpenFileNameWrap(std::move(params));
    ResponseOpenFileInfoTask* task = new ResponseOpenFileInfoTask(std::move(completion), webviewId, wrap, FALSE, completionCallback);

    std::function<void(void)>* callback = new std::function<void(void)>([hWnd, wrap, saveAs, multiSelect, task] {
        BOOL retVal = FALSE;
        HWND hwndOwner = hWnd; //  createHideWindow(); // ::GetActiveWindow();

        if (wrap->isDirectory()) {
            LPITEMIDLIST pil = NULL;
            INITCOMMONCONTROLSEX InitCtrls = { 0 };
            BROWSEINFO bi = { 0 };
            bi.hwndOwner = hwndOwner;
            bi.iImage = 0;
            bi.lParam = NULL;
            bi.lpfn = NULL;
            bi.lpszTitle = (const WCHAR*)(u"请选择文件路径");
            bi.pszDisplayName = wrap->getInfo()->lpstrFile;
            bi.ulFlags = BIF_BROWSEINCLUDEFILES;

            //InitCommonControlsEx(&InitCtrls); // 在调用函数SHBrowseForFolder之前需要调用该函数初始化相关环境
            pil = ::SHBrowseForFolder(&bi);
            if (NULL != pil) {
                ::SHGetPathFromIDList(pil, wrap->getInfo()->lpstrFile); //获取用户选择的文件路径
                retVal = TRUE;
            }
        } else {
            wrap->getInfo()->hwndOwner = hwndOwner;

            if (saveAs) {
                wrap->getInfo()->Flags = OFN_OVERWRITEPROMPT;
                retVal = ::GetSaveFileNameW(wrap->getInfo());
            } else if (multiSelect) {
                wrap->getInfo()->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_ALLOWMULTISELECT;
                retVal = ::GetOpenFileNameW(wrap->getInfo());
            } else {
                wrap->getInfo()->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
                retVal = ::GetOpenFileNameW(wrap->getInfo());
            }
        }
        task->m_retVal = retVal;

        ThreadCall::callBlinkThreadAsync(FROM_HERE, [task]() {
            task->run();
            delete task;
        });
    });

    DWORD threadId = 0;
    HANDLE threadHandle = ::CreateThread(0, 0, getOpenFileNameThread, callback, 0, &threadId);
    if (threadHandle != INVALID_HANDLE_VALUE && threadHandle != NULL)
        ::CloseHandle(threadHandle);
    return true;
#else
    return false;
#endif
}

FileChooserImpl::FileChooserImpl(int64_t webviewId)
{
    m_webviewId = webviewId;
}

void FileChooserImpl::OpenFileChooser(
    ::blink::mojom::blink::FileChooserParamsPtr params, ::blink::mojom::blink::FileChooser::OpenFileChooserCallback completion)
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_webviewId);
    if (!webview)
        return;

    std::function<void(void)>* callback = new std::function<void(void)>([/*self, id*/] {
        //         if (net::ActivatingObjCheck::inst()->isActivating(id))
        //         self->setIsMouseKeyMessageEnable(true);
    });

    runFileChooserImpl(webview->getHostWnd(), std::move(params), std::move(completion), m_webviewId, callback);
}

void FileChooserImpl::EnumerateChosenDirectory(
    const ::base::FilePath& directory_path, ::blink::mojom::blink::FileChooser::EnumerateChosenDirectoryCallback callback)
{
    DebugBreak();
}

}
