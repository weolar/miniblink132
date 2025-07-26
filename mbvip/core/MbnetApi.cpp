
#include <stdlib.h>
#include <crtdbg.h>
#include "mbvip/core/mb.h"
#include "mbvip/download/SimpleDownload.h"
#include "mbvip/core/MbJsValue.h"
#include "content/browser/MbWebview.h"
#include "content/browser/SharedTimerWin.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/ThreadCall.h"
#include "content/common/mbchar.h"
#include "content/renderer/RenderThreadImpl.h"
#include "mbnet/WebURLLoaderInternal.h"
#include "mbnet/WebURLLoaderManager.h"
#include "mbnet/InitializeHandleInfo.h"
#include "mbnet/FlattenHTTPBodyElement.h"
#include "mbnet/WebURLLoaderManagerSetupInfo.h"
#include "mbnet/DefaultLocalStorageDir.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/platform/wtf/allocator/partitions.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/public/platform/web_http_header_visitor.h"
#include "services/network/public/cpp/resource_request.h"
#include "base/command_line.h"
#include "base/run_loop.h"
#include "base/strings/utf_string_conversions.h"
#include "base/task/single_thread_task_executor.h"
#include "base/at_exit.h"
#include "v8.h"

bool checkThreadCallIsValid(const char* funcName);

mbRequestType MB_CALL_TYPE mbNetGetRequestMethod(void* jobPtr)
{
    checkThreadCallIsValid(__FUNCTION__);
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    mbnet::InitializeHandleInfo* info = job->m_initializeHandleInfo;
    std::string method;
    if (!info) {
        method = job->firstRequest()->method;
        if (method.empty())
            return kMbRequestTypeInvalidation;
    } else
        method = info->method;

    if ("POST" == method) {
        return kMbRequestTypePost;
    } else if ("PUT" == method) {
        return kMbRequestTypePut;
    } else if ("GET" == method) {
        return kMbRequestTypeGet;
    }
    return kMbRequestTypeInvalidation;
}

const mbSlist* MB_CALL_TYPE mbNetGetRawHttpHeadInBlinkThread(mbNetJob jobPtr)
{
    if (content::ThreadCall::isBlinkThread())
        checkThreadCallIsValid(__FUNCTION__);
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    if (!job->m_initializeHandleInfo)
        return nullptr;
    return (const mbSlist*)job->m_initializeHandleInfo->headers;
}

class HTTPHeaderVisitor : public blink::WebHTTPHeaderVisitor {
public:
    HTTPHeaderVisitor(curl_slist** result)
    {
        m_result = result;
    }

    virtual void VisitHeader(const blink::WebString& name, const blink::WebString& value) override
    {
        *m_result = curl_slist_append(*m_result, name.Utf8().c_str());
        *m_result = curl_slist_append(*m_result, value.Utf8().c_str());
    }

private:
    curl_slist** m_result;
};

const mbSlist* MB_CALL_TYPE mbNetGetRawResponseHeadInBlinkThread(mbNetJob jobPtr)
{
    if (content::ThreadCall::isBlinkThread()) {
        mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
        mbSlist* result = nullptr;
        HTTPHeaderVisitor visitor((curl_slist**)&result);
        job->m_response.VisitHttpHeaderFields(&visitor);

        content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [result] {
            curl_slist_free_all((curl_slist*)result);
        });

        return result;
    }
    return nullptr;
}

mbPostBodyElements* MB_CALL_TYPE mbNetCreatePostBodyElements(mbWebView webView, size_t length)
{
    checkThreadCallIsValid(__FUNCTION__);
    if (0 == length)
        return nullptr;

    mbPostBodyElements* result = new mbPostBodyElements();
    result->size = sizeof(mbPostBodyElements);
    result->isDirty = true;

    size_t allocLength = sizeof(mbPostBodyElement*) * length;
    result->element = (mbPostBodyElement**)malloc(allocLength);
    memset(result->element, 0, allocLength);

    result->elementSize = length;

    return result;
}

void MB_CALL_TYPE wkeNetFreePostBodyElements(mbPostBodyElements* elements)
{
    checkThreadCallIsValid(__FUNCTION__);
    for (size_t i = 0; i < elements->elementSize; ++i) {
        mbNetFreePostBodyElement(elements->element[i]);
    }
    free(elements->element);
    delete elements;
}

struct mbString {
    mbString(const utf8* utfString, size_t length)
    {
        str = utfString;
        len = length;
        freeStrFunc = nullptr;
    }

    ~mbString()
    {
        if (freeStrFunc)
            freeStrFunc((utf8*)str, len);
    }

    static void defaultFreeStr(utf8* str, size_t len)
    {
        free(str);
    }

    const utf8* str;
    size_t len;
    void (*freeStrFunc)(utf8* str, size_t len);
};

mbStringPtr MB_CALL_TYPE mbCreateString(const utf8* str, size_t len)
{
    mbStringPtr mbStr = new mbString(str, len);
    return mbStr;
}

mbStringPtr MB_CALL_TYPE mbCreateStringWithCopy(const utf8* str, size_t len)
{
    if (!str || 0 == len)
        return nullptr;

    utf8* strCopy = (utf8*)malloc(len + 1);
    memcpy(strCopy, str, len);
    strCopy[len] = 0;

    mbStringPtr mbStr = new mbString(strCopy, len);
    mbStr->freeStrFunc = mbString::defaultFreeStr;
    return mbStr;
}

mbStringPtr MB_CALL_TYPE mbCreateStringWithoutNullTermination(const utf8* str, size_t len)
{
    return mbCreateStringWithCopy(str, len);
}

void MB_CALL_TYPE mbDeleteString(mbStringPtr str)
{
    delete str;
}

const utf8* MB_CALL_TYPE mbGetString(mbStringPtr s)
{
    return s ? s->str : "";
}

size_t MB_CALL_TYPE mbGetStringLen(mbStringPtr s)
{
    return s ? s->len : 0;
}

void MB_CALL_TYPE mbNetFreePostBodyElement(mbPostBodyElement* element)
{
    mbFreeMemBuf(element->data);
    mbDeleteString(element->filePath);
    delete element;
}

mbPostBodyElement* MB_CALL_TYPE mbNetCreatePostBodyElement(mbWebView webView)
{
    checkThreadCallIsValid(__FUNCTION__);
    mbPostBodyElement* wkeElement = new mbPostBodyElement();
    wkeElement->size = sizeof(mbPostBodyElement);
    return wkeElement;
}

static mbPostBodyElements* flattenHTTPBodyElementToWke(const std::vector<mbnet::FlattenHTTPBodyElement*>& body)
{
#if 1 // defined(OS_WIN)
    if (0 == body.size())
        return nullptr;

    mbPostBodyElements* result = mbNetCreatePostBodyElements(NULL_WEBVIEW, body.size());
    result->isDirty = false;
    for (size_t i = 0; i < result->elementSize; ++i) {
        mbPostBodyElement* wkeElement = mbNetCreatePostBodyElement(NULL_WEBVIEW);
        result->element[i] = wkeElement;
        const mbnet::FlattenHTTPBodyElement* element = body[i];

        if (mbnet::FlattenHTTPBodyElement::TypeFile == element->type
            /*|| mbnet::FlattenHTTPBodyElement::TypeFileSystemURL == element->type*/) {

            wkeElement->type = mbHttBodyElementTypeFile;

            std::string filePathUtf8;
            base::UTF16ToUTF8(element->filePath.c_str(), element->filePath.size(), &filePathUtf8);

            wkeElement->filePath = mbCreateString(filePathUtf8.c_str(), filePathUtf8.size());
            wkeElement->fileLength = element->fileLength;
            wkeElement->fileStart = element->fileStart;
            wkeElement->data = nullptr;
        } else {
            wkeElement->type = mbHttBodyElementTypeData;
            wkeElement->filePath = nullptr;
            wkeElement->fileLength = 0;
            wkeElement->fileStart = 0;
            wkeElement->data = mbCreateMemBuf(NULL_WEBVIEW, (void*)element->data.data(), element->data.size());
        }
    }
    return result;
#else
    DebugBreak();
    return nullptr;
#endif
}

mbPostBodyElements* MB_CALL_TYPE mbNetGetPostBody(void* jobPtr)
{
    checkThreadCallIsValid(__FUNCTION__);
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    mbnet::InitializeHandleInfo* info = job->m_initializeHandleInfo;
    if (!info)
        return nullptr;

    std::vector<mbnet::FlattenHTTPBodyElement*>* flattenElements = nullptr;
    if ("POST" == info->method) {
        if (!info->methodInfo || !info->methodInfo->post || !info->methodInfo->post->data)
            return nullptr;
        flattenElements = &(info->methodInfo->post->data->flattenElements);
    } else if ("PUT" == info->method) {
        if (!info->methodInfo || !info->methodInfo->put || !info->methodInfo->put->data)
            return nullptr;
        flattenElements = &info->methodInfo->put->data->flattenElements;
    }
    if (!flattenElements)
        return nullptr;

    mbPostBodyElements* postBody = flattenHTTPBodyElementToWke(*flattenElements);
    return postBody;
}

static BOOL netHoldJobToAsynCommit(mbNetJob jobPtr)
{
    checkThreadCallIsValid(__FUNCTION__);
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    if (job->m_isRedirection || job->m_isSynchronous || job->m_isHoldJobToAsynCommit)
        return FALSE;

    job->m_isWkeNetSetDataBeSetted = false;
    if (job->m_asynWkeNetSetData)
        delete job->m_asynWkeNetSetData;
    job->m_asynWkeNetSetData = nullptr;

    if (job->m_hookBufForEndHook)
        delete job->m_hookBufForEndHook;
    job->m_hookBufForEndHook = nullptr;
    job->m_isHookRequest &= (~((unsigned int)1));
    job->m_isHoldJobToAsynCommit = true;

    return TRUE;
}

void MB_CALL_TYPE mbNetHoldJobToAsynCommit(mbNetJob jobPtr)
{
    if (content::ThreadCall::isBlinkThread()) {
        netHoldJobToAsynCommit(jobPtr);
    } else {
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [jobPtr] { netHoldJobToAsynCommit(jobPtr); });
    }
}

static void netContinueJob(mbNetJob jobPtr)
{
    checkThreadCallIsValid(__FUNCTION__);
    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    mbnet::WebURLLoaderManager::sharedInstance()->continueJob(job);
}

void MB_CALL_TYPE mbNetContinueJob(mbNetJob jobPtr)
{
    if (content::ThreadCall::isBlinkThread()) {
        netContinueJob(jobPtr);
    } else {
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [jobPtr] { netContinueJob(jobPtr); });
    }
}

static void setCookieJarFullPathImpl(mbWebView webView, const std::u16string& path)
{
    std::string jarPathA = base::UTF16ToUTF8(std::u16string_view(path));
    mbnet::WebURLLoaderManager::setCookieJarFullPath(jarPathA.c_str());
}

static void setLocalStorageFullPathImpl(mbWebView webView, const std::u16string& path)
{
    std::string pathA = base::UTF16ToUTF8(path);
    mbnet::setDefaultLocalStorageDir(pathA);
}

static void setFullPathOnBlinkThread(mbWebView webviewHandle, std::u16string* pathString, bool isCookiePath)
{
    if (!pathString)
        return;

    if (!webviewHandle) {
        isCookiePath ? setCookieJarFullPathImpl(NULL_WEBVIEW, *pathString) : setLocalStorageFullPathImpl(NULL_WEBVIEW, *pathString);
    } else {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webviewHandle);
        if (webview) {
            std::string pathUtf8 = base::UTF16ToUTF8(pathString->c_str());
            //wkeSetDebugConfig(webview->getWkeWebView(), isCookiePath ? "setCookieJarFullPath" : "setLocalStorageFullPath", pathUtf8.c_str());
            if (isCookiePath)
                webview->setCookieJarFullPath(pathUtf8.c_str());
            else
                webview->setLocalStorageFullPath(pathUtf8.c_str());
        }
    }
    delete pathString;
}

void setFullPath(mbWebView webviewHandle, const WCHAR* path, bool isCookiePath)
{
    if (!path)
        return;
    std::u16string* pathString = new std::u16string((const char16_t*)path);
    if (0 == pathString->size()) {
        delete pathString;
        return;
    }

    if (content::ThreadCall::isBlinkThread()) {
        setFullPathOnBlinkThread(webviewHandle, pathString, isCookiePath);
    } else {
        content::ThreadCall::callBlinkThreadAsync(
            MB_FROM_HERE, [webviewHandle, pathString, isCookiePath] { setFullPathOnBlinkThread(webviewHandle, pathString, isCookiePath); });
    }
}
