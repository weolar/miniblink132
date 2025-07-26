
#ifndef mbvip_download_SimpleDownload_h
#define mbvip_download_SimpleDownload_h

#include "content/common/ThreadCall.h"
#include "base/files/file_path.h"
#include "base/synchronization/lock.h"
#include <process.h>
#include <shlwapi.h>

namespace base {
class File;
}

namespace download {

class SimpleDownload {
public:
    static SimpleDownload* create(mbWebView webView, const WCHAR* savePath, const mbDialogOptions* dialogOpt, const mbDownloadOptions* downloadOpt,
        size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind,
        mbDownloadBind* callbackBind);

    ~SimpleDownload();

    static unsigned int WINAPI dialogThread(void* param);

    static int getDialogCount();

private:
    SimpleDownload(mbWebView mbView, size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job,
        mbNetJobDataBind* dataBind, mbDownloadBind* callbackBind);

    void startSave(/*std::vector<WCHAR>* path*/bool ok);
    void doSave();
    bool canSave();
    void onBeginSaveCallback();

    //     static void WKE_CALL_TYPE onSimpleDownloadWillRedirectCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr oldRequest, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr redirectResponse);
    //     static void WKE_CALL_TYPE onSimpleDownloadDidReceiveResponseCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr response);
    //     static void WKE_CALL_TYPE onSimpleDownloadDidReceiveDataCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const char* data, int dataLength);
    //     static void WKE_CALL_TYPE onSimpleDownloadDidFailCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const utf8* error);
    //     static void WKE_CALL_TYPE onSimpleDownloadDidFinishLoadingCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, double finishTime);
    static void MB_CALL_TYPE onDataRecv(void* param, mbNetJob job, const char* data, int length);
    static void MB_CALL_TYPE onDataFinish(void* param, mbNetJob job, mbLoadingResult result);

    void onDataRecvImpl(mbNetJob job, const char* data, int length);
    void onDataFinishImpl(mbNetJob job, mbLoadingResult result);

    static int m_dialogCount;

    std::string m_url;
    std::string m_mime;
    std::string m_contentDisposition;

    base::Lock m_saveFullPathLock; // m_saveFullPath会被多线程使用
    std::u16string m_saveFullPath; // 用户设置的全路径
    
    base::FilePath m_saveTempFullPath; // 先放到临时路径，再改名成m_savePath

    base::File* m_handleOfSave;
    size_t m_totalSize;
    size_t m_downloadedSize;

    mbWebView m_mbView;

    std::vector<char> m_cacheData;
    bool m_hadCallDataFinish; // 是否调用过onDataFinishImpl
    mbLoadingResult m_loadingResult;

    struct DialogOptions {
        std::string title;
        std::string defaultPath;
        std::string buttonLabel;
    };
    DialogOptions dialogOpt;

    mbDownloadBind m_callbackBind;
};

}

#endif // download_SimpleDownload_h