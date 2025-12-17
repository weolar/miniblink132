
#include "mbvip/download/SimpleDownload.h"

#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "mbvip/download/DownloadUtil.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/files/file.h"
#include "base/files/file_util.h"
#include <process.h>
#include <shlwapi.h>
#include <commdlg.h>

namespace download {

size_t c16len(const char16_t* s)
{
    const char16_t* s_orig = s;
    while (*s) {
        ++s;
    }
    return s - s_orig;
}

int SimpleDownload::getDialogCount()
{
    return m_dialogCount;
}

void SimpleDownload::onDataRecv(void* param, mbNetJob job, const char* data, int length)
{
    SimpleDownload* self = (SimpleDownload*)param;
    self->onDataRecvImpl(job, data, length);
}

void SimpleDownload::onDataFinish(void* param, mbNetJob job, mbLoadingResult result)
{
    SimpleDownload* self = (SimpleDownload*)param;
    self->onDataFinishImpl(job, result);
}

int SimpleDownload::m_dialogCount = 0;

SimpleDownload::SimpleDownload(mbWebView mbView, size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job,
    mbNetJobDataBind* dataBind, mbDownloadBind* callbackBind)
{
    m_totalSize = expectedContentLength;
    m_url = url;
    m_mime = mime;
    m_contentDisposition = disposition;
    m_handleOfSave = nullptr;
    m_mbView = mbView;
    m_hadCallDataFinish = false;
    m_loadingResult = (mbLoadingResult)-1;

    dataBind->param = this;
    dataBind->recvCallback = onDataRecv;
    dataBind->finishCallback = onDataFinish;

    memset(&m_callbackBind, 0, sizeof(mbDownloadBind));

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)m_mbView);
    m_saveTempFullPath = webview->getDownloadDirPath();

    char temp[100] = { 0 };
    sprintf(temp, "%p%p.tmp", &mbView, &expectedContentLength);
    m_saveTempFullPath = m_saveTempFullPath.AppendASCII(temp);

    if (callbackBind)
        m_callbackBind = *callbackBind;
}

SimpleDownload::~SimpleDownload()
{
}

SimpleDownload* SimpleDownload::create(mbWebView webView, const WCHAR* savePath, const mbDialogOptions* dialogOpt, const mbDownloadOptions* downloadOpt,
    size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
    if (m_dialogCount > 0)
        return nullptr;

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webView);
    base::FilePath saveTempFullPath = webview->getDownloadDirPath();

    if (!base::PathExists(saveTempFullPath)) {
        base::File::Error error;
        if (!base::CreateDirectoryAndGetError(saveTempFullPath, &error)) {
            std::string temp = "CreateDirectoryAndGetError fail:";
            temp += saveTempFullPath.AsUTF8Unsafe();
            temp += "\n";
            OutputDebugStringA(temp.c_str());
            return nullptr;
        }
    }

    SimpleDownload* self = new SimpleDownload(webView, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);

    if (dialogOpt && dialogOpt->magic == 'mbdo' && dialogOpt->defaultPath)
        self->dialogOpt.defaultPath = dialogOpt->defaultPath;

    if (savePath) {
        webview->setIsMouseKeyMessageEnable(true);

        std::vector<WCHAR>* fileResult = nullptr;
        size_t pathLen = c16len((const char16_t*)savePath);
        if (pathLen == 0) {
            delete self;
            return nullptr;
        }

        fileResult = new std::vector<WCHAR>();
        fileResult->resize(MAX_PATH * 2);

        memcpy(fileResult->data(), savePath, pathLen * sizeof(WCHAR));

        if (!(downloadOpt && downloadOpt->magic == 'mbdo' && downloadOpt->saveAsPathAndName)) {
            std::u16string defaultSaveName = getSaveName(self->m_contentDisposition, self->m_url);
            PathAppendW((LPWSTR)(fileResult->data()), (LPCWSTR)(defaultSaveName.c_str()));
        }
        
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] { self->startSave(true); });

        self->m_saveFullPathLock.Acquire();
        self->m_saveFullPath = (const char16_t*)fileResult->data();
        self->m_saveFullPathLock.Release();
        delete fileResult;
    } else {
        base::subtle::Barrier_AtomicIncrement(&m_dialogCount, 1);

        unsigned int threadIdentifier = 0;
        HANDLE hHandle = reinterpret_cast<HANDLE>(_beginthreadex(0, 0, SimpleDownload::dialogThread, self, 0, &threadIdentifier));
        ::CloseHandle(hHandle);
    }

    return self;
}

bool SimpleDownload::canSave()
{
    if (m_hadCallDataFinish && (MB_LOADING_FAILED == m_loadingResult || MB_LOADING_CANCELED == m_loadingResult))
        return false;
    return true;
}

base::FilePath changeStrToFilePath(const std::u16string& str)
{
#ifdef OS_LINUX
    return base::FilePath(base::UTF16ToUTF8(str));
#else
    return base::FilePath::FromUTF16Unsafe(std::u16string_view(str));
#endif
}

void SimpleDownload::onBeginSaveCallback()
{
    base::AutoLock locker(m_saveFullPathLock);
    if (!m_callbackBind.beginSaveCallback)
        return;

    base::FilePath savePath = changeStrToFilePath(m_saveFullPath);
    std::string savePathStr = base::UTF16ToUTF8(m_saveFullPath);
    // 这个回调会改变存储的路径和名字
    mbStringPtr newPath = m_callbackBind.beginSaveCallback(m_callbackBind.param, savePathStr.c_str(), base::PathExists(savePath));
    if (!newPath || mbGetStringLen(newPath) == 0)
        return;

    m_saveFullPath.clear();
    if (!base::UTF8ToUTF16(mbGetString(newPath), mbGetStringLen(newPath), &m_saveFullPath)) {
        m_loadingResult = MB_LOADING_FAILED;

        if (m_callbackBind.finishCallback)
            m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
        return;
    }
}

// 检测是否有重名，如果有，就加个数字
base::FilePath checkAndRenameSaveFullPath(const base::FilePath& path)
{
    if (!base::PathExists(path))
        return path;

    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo = localtime(&currentTime);
    char timeString[20]; // 足够存放 "YYYY-MM-DD HH:MM:SS\0"

    static int s_count = 1;
    strftime(timeString, sizeof(timeString), "%Y-%m-%d-%H-%M-%S", timeInfo);
    char temp[150];
    snprintf(temp, sizeof(temp), "[%s](%d)", timeString, s_count++);

    base::FilePath newPath = path.InsertBeforeExtensionASCII(base::StringPiece(temp));
    if (!base::PathExists(newPath))
        return newPath;

    return path;
}

// 本函数会在还没收到正确的文件名的时候就开始下载，反正下载的内容也是先存在temp路径里
void SimpleDownload::doSave()
{
    if (!m_handleOfSave) {
        onBeginSaveCallback();

        base::File* hFile = new base::File(m_saveTempFullPath, base::File::FLAG_WRITE | base::File::FLAG_CREATE_ALWAYS);
        if (!hFile || !hFile->IsValid()) {
            std::string output = "SimpleDownload::doSave fail:";
            output += m_saveTempFullPath.AsUTF8Unsafe();
            output += "\n";
            OutputDebugStringA(output.c_str());

            m_loadingResult = MB_LOADING_FAILED;

            if (m_callbackBind.finishCallback)
                m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
            return;
        }
        m_handleOfSave = hFile;

        if (m_callbackBind.saveNameCallback) {
            base::AutoLock locker(m_saveFullPathLock);
            m_callbackBind.saveNameCallback(m_callbackBind.param, (const WCHAR*)m_saveFullPath.c_str());
        }
    }

    if (!m_handleOfSave) {
        CHECK(MB_LOADING_FAILED == m_loadingResult);
        OutputDebugStringA("SimpleDownload::doSave, m_handleOfSave fail\n");
        return;
    }

#ifdef OS_LINUX
//     char* output = (char*)malloc(0x1000);
//     sprintf(output, "SimpleDownload::doSave: %p %d, %d, %s\n", m_callbackBind.recvCallback, canSave(), m_cacheData.size(),
//         base::UTF16ToUTF8(m_saveFullPath).c_str());
//     OutputDebugStringA(output);
//     free(output);
#endif
    if (m_callbackBind.recvCallback && canSave() && 0 != m_cacheData.size())
        m_callbackBind.recvCallback(m_callbackBind.param, nullptr, &m_cacheData[0], (int)m_cacheData.size());

    if (0 != m_cacheData.size()) {
        m_handleOfSave->WriteAtCurrentPos(&m_cacheData[0], (DWORD)m_cacheData.size());
    }
    m_cacheData.clear();

    // 有时候下载完了，下载对话框还没打开，或者下载完了还没调用startSave
    if (!m_hadCallDataFinish || m_dialogCount > 0 || !m_hasStartSave)
        return;

    // 下载成功
    m_handleOfSave->Close();
    delete m_handleOfSave;
    m_handleOfSave = nullptr;

    m_saveFullPathLock.Acquire();
    base::FilePath saveFullPath = changeStrToFilePath(m_saveFullPath);
    m_saveFullPathLock.Release();
    base::FilePath savePathDir = saveFullPath.DirName();
    base::CreateDirectory(savePathDir);

    saveFullPath = checkAndRenameSaveFullPath(saveFullPath);

    if (!base::internal::MoveUnsafe(m_saveTempFullPath, saveFullPath))
        m_loadingResult = MB_LOADING_FAILED;
    base::DeleteFile(m_saveTempFullPath);

    if (m_callbackBind.finishCallback)
        m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);

    SimpleDownload* self = this;
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self] { delete self; });
}

void SimpleDownload::startSave(/*std::vector<WCHAR>* path*/bool ok)
{
    if (/*!path || 0 == path->size()*/!ok) {
        m_loadingResult = MB_LOADING_FAILED;
        if (m_callbackBind.finishCallback)
            m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
        return;
    }

    m_hasStartSave = true;
    doSave();
}

void SimpleDownload::onDataRecvImpl(mbNetJob job, const char* data, int length)
{
    if (0 == length)
        return;

    if ((mbLoadingResult)-1 == m_loadingResult) { // 就算mbNetCancelRequest依然会反复进入本函数
        size_t oldSize = m_cacheData.size();
        m_cacheData.resize(oldSize + length);
        memcpy(&m_cacheData[oldSize], data, length);

        m_downloadedSize += length;

        doSave();
    }

    if (MB_LOADING_FAILED == m_loadingResult)
        mbNetCancelRequest(job);
}

void SimpleDownload::onDataFinishImpl(mbNetJob job, mbLoadingResult result)
{
    m_hadCallDataFinish = true;
    m_loadingResult = result;
    doSave();
}

unsigned int SimpleDownload::dialogThread(void* param)
{
#ifdef OS_LINUX
    __debugbreak();
#else
    SimpleDownload* self = (SimpleDownload*)param;

    OPENFILENAMEW ofn = { 0 };
    std::vector<WCHAR>* fileResult = new std::vector<WCHAR>();
    fileResult->resize(4 * MAX_PATH + 1);

    std::u16string defaultSaveName = getSaveName(self->m_contentDisposition, self->m_url);
    if (defaultSaveName.size() > 150)
        defaultSaveName = defaultSaveName.substr(0, 150);
    wcscpy(fileResult->data(), (const WCHAR*)defaultSaveName.c_str());

    HWND hwndOwner = nullptr;
    mbWebView mbWebview = self->m_mbView;
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)mbWebview);
    if (webview)
        hwndOwner = webview->getHostWnd();

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwndOwner;
    ofn.lpstrFile = (LPWSTR)(fileResult->data());
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"All\0*.*\0\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = base::UTF8ToWide(self->dialogOpt.defaultPath).c_str();
    ofn.Flags = OFN_SHOWHELP | OFN_OVERWRITEPROMPT;

    if (!GetSaveFileNameW(&ofn)) {
        delete fileResult;
        fileResult = nullptr;
    }

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [mbWebview] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)mbWebview);
        if (!webview)
            return;
        webview->setIsMouseKeyMessageEnable(true);
    });

    self->m_saveFullPathLock.Acquire();
    if (fileResult)
        self->m_saveFullPath = (const char16_t*)fileResult->data();
    self->m_saveFullPathLock.Release();

    bool ok = !!fileResult;
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self, ok] { self->startSave(ok); });

    delete fileResult;

    base::subtle::Barrier_AtomicIncrement(&m_dialogCount, -1);
#endif
    return 0;
}

}