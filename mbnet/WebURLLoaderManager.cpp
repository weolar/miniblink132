/*
 * Copyright (C) 2004, 2006 Apple Inc.  All rights reserved.
 * Copyright (C) 2006 Michael Emmel mike.emmel@gmail.com
 * Copyright (C) 2007 Alp Toker <alp@atoker.com>
 * Copyright (C) 2007 Holger Hans Peter Freyther
 * Copyright (C) 2008 Collabora Ltd.
 * Copyright (C) 2008 Nuanti Ltd.
 * Copyright (C) 2009 Appcelerator Inc.
 * Copyright (C) 2009 Brent Fulgham <bfulgham@webkit.org>
 * Copyright (C) 2013 Peter Gal <galpeter@inf.u-szeged.hu>, University of Szeged
 * Copyright (C) 2013 Alex Christensen <achristensen@webkit.org>
 * Copyright (C) 2013 University of Szeged
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if USING_VC6RT == 1
#define PURE = 0
#endif

#include <shlobj.h>
#include <shlwapi.h>
#include <shellapi.h>

#include "mbnet/WebURLLoaderManager.h"

#include "mbnet/WebURLLoaderInternal.h"
#include "mbnet/DataURL.h"
#include "mbnet/RequestExtraData.h"
#include "mbnet/BlobResourceLoader.h"
#include "mbnet/SharedMemoryDataConsumerHandle.h"
#include "mbnet/FixedReceivedData.h"
#include "mbnet/WebURLLoaderManagerUtil.h"
#include "mbnet/WebURLLoaderManagerMainTask.h"
#include "mbnet/FlattenHTTPBodyElement.h"
#include "mbnet/WebURLLoaderManagerSetupInfo.h"
#include "mbnet/WebURLLoaderManagerAsynTask.h"
#include "mbnet/InitializeHandleInfo.h"
#include "mbnet/HeaderVisitor.h"
#include "mbnet/PageNetExtraData.h"
#include "mbnet/DefaultLocalStorageDir.h"
#include "mbnet/CurlCacheManager.h"
#include "mbnet/DownloadFileBlobCache.h"
#include "mbnet/LoaderFactoryImpl.h"
#include "mbnet/DownloadBlobUrl.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "mbnet/cookies/CookieJarMgr.h"
#include "content/common/LiveIdDetect.h"
#include "content/browser/MbWebview.h"
#include "services/network/public/cpp/resource_request.h"
#include "third_party/blink/renderer/platform/network/mime/mime_type_registry.h"
#include "third_party/blink/renderer/platform/wtf/text/string_utf8_adaptor.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include "services/network/public/cpp/resource_request_body.h"
#include "base/strings/utf_string_conversions.h"
#include "base/strings/string_util.h"
#include "base/containers/flat_set.h"
#include "base/base64.h"
#include "base/path_service.h"
#include "url/gurl.h"
#include "net/base/net_errors.h"
#include <errno.h>
#include <stdio.h>

#if ENABLE_WKE == 1
#include "wke/wkeNetHook.h"
#include "wke/wkeWebView.h"
#include "wke/wkeGlobalVar.h"
#endif

extern "C" MojoResult MojoMakeDelayCloseFlag(MojoHandle handle);
extern "C" MojoResult MojoSetDebugMojoHandleStr(MojoHandle handle, const std::string& str);

namespace mbnet {

MainTaskRunner* MainTaskRunner::m_inst = nullptr;

void WebURLLoaderManager::initializeMultiHandleOnIoThread(int* waitCount)
{
    if (getCurrentThreadCurlMultiHandle())
        return;
    CURLM* curlMultiHandle = curl_multi_init();
    m_curlMultiHandles.insert(std::pair<DWORD, CURLM*>(::GetCurrentThreadId(), curlMultiHandle));
    base::subtle::NoBarrier_AtomicIncrement(waitCount, -1);
}

CURLM* WebURLLoaderManager::getCurrentThreadCurlMultiHandle() const
{
    std::map<DWORD, CURLM*>::const_iterator it = m_curlMultiHandles.find(::GetCurrentThreadId());
    if (it == m_curlMultiHandles.end())
        return nullptr;
    CURLM* handle = it->second;
    return handle;
}

static base::Thread* createIoThread(const char* threadName)
{
    base::Thread* thread = new base::Thread(threadName);
    thread->Start();
    return thread;
}

std::vector<base::Thread*> WebURLLoaderManager::getIoThreads()
{
    if (0 == m_ioThreads.size()) {
        for (size_t i = 0; i < 4; ++i) {
            base::Thread* threadPtr = createIoThread("ioThread");
            m_ioThreads.push_back(threadPtr);
        }
    }

    return m_ioThreads;
}

static size_t writeCallbackTest(void* ptr, size_t size, size_t nmemb, void* data)
{
    return size * nmemb;
}
static size_t headerCallbackTest(char* ptr, size_t size, size_t nmemb, void* data)
{
    return size * nmemb;
}

char s_curlErrorBuffer[CURL_ERROR_SIZE];

int testCURL(const char* url)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    //curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:82.0) Gecko/20100101 Firefox/82.0");
    //curl_easy_setopt(curl, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_GM);
    //curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, DebugCallback);

    curl_slist* clist = nullptr;
    //clist = curl_slist_append(clist, "Content-Type: application/json;charset=utf8");
    clist = curl_slist_append(clist,
        "accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
    clist = curl_slist_append(clist, "accept-encoding: gzip, deflate, br");
    clist = curl_slist_append(clist, "accept-language: zh-CN,zh;q=0.9");
    clist = curl_slist_append(clist, "cache-control: max-age=0");
    clist = curl_slist_append(
        clist, "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.71 Safari/537.36 Core/1.94.233.400/12.3.5574.400");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, clist);

    // error:1000042e:SSL routines:OPENSSL_internal:TLSV1_ALERT_PROTOCOL_VERSION
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 1);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, s_curlErrorBuffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallbackTest);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, headerCallbackTest);

    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false); // ignoreSSLErrors
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10);
    curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
    curl_easy_setopt(curl, CURLOPT_BUFFERSIZE, 32768); // 32KB of FFmpeg
    curl_easy_setopt(curl, CURLOPT_DNS_CACHE_TIMEOUT, 60 * 5); // 5 minutes
    curl_easy_setopt(curl, CURLOPT_PROTOCOLS, kAllowedProtocols);
    curl_easy_setopt(curl, CURLOPT_REDIR_PROTOCOLS, kAllowedProtocols);
    curl_easy_setopt(curl, CURLOPT_ENCODING, "");
    curl_easy_setopt(curl, CURLOPT_HTTPGET, TRUE);
    //curl_easy_setopt(curl, CURLOPT_URL, "https://ebssec.boc.cn/boc15/login.html");
    //curl_easy_setopt(curl, CURLOPT_URL, "https://demo.gmssl.cn:1443");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    res = curl_easy_perform(curl);

    if (CURLE_OK == res) {
        char* ct;
        /* ask for the content-type */
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);

        if ((CURLE_OK == res) && ct)
            printf("We received Content-Type: %s\n", ct);
    }

    /* always cleanup */
    curl_easy_cleanup(curl);
    return 0;
}

WebURLLoaderManager::WebURLLoaderManager(const char* cookieJarFullPath)
    : m_certificatePath(/*certificatePath()*/ "")
    , m_runningJobs(0)
    , m_isShutdown(false)
    , m_newestJobId(1)
{
#if 0
    content::BlinkPlatformImpl* platform = (content::BlinkPlatformImpl*)Platform::current();
    if (wke::g_diskCacheEnable && CurlCacheManager::getInstance()->cacheDirectory().isEmpty()) {
        String path = net::getDefaultLocalStorageFullPath();
        path.append(L"cache");
        CurlCacheManager::getInstance()->setCacheDirectory(path);
    }
#endif
    m_mainTasksBegin = nullptr;
    m_mainTasksEnd = nullptr;
    m_syncIoThread = nullptr;
    m_mainThreadRunner = base::SingleThreadTaskRunner::GetCurrentDefault();
    m_threads = getIoThreads();

    for (size_t i = 0; i < m_threads.size(); ++i) {
        int waitCount = 1;
        m_threads[i]->task_runner()->PostTask(
            FROM_HERE, base::BindOnce(&WebURLLoaderManager::initializeMultiHandleOnIoThread, base::Unretained(this), &waitCount));
        while (waitCount) {
            ::Sleep(10);
        }
    }

    //     testCURL("https://www.hao123.com/?tn=48021271_79_hao_pg");
    //     testCURL("https://ebssec.boc.cn/boc15/login.html");
    //     testCURL("https://demo.gmssl.cn:1443");
    //     testCURL("https://demo.gmssl.cn:2443");
    //testCURL("https://web-platform.test:8443/resources/testharness.js");

    curl_global_init(CURL_GLOBAL_ALL);

    initCookieSession(cookieJarFullPath);
}

WebURLLoaderManager::~WebURLLoaderManager()
{
    for (std::map<DWORD, CURLM*>::iterator it = m_curlMultiHandles.begin(); it != m_curlMultiHandles.end(); ++it) {
        CURLM* handle = it->second;
        curl_multi_cleanup(handle);
    }
    curl_global_cleanup();
}

void WebURLLoaderManager::shutdown()
{
    m_isShutdown = true;

    //WTF::Locker<WTF::Mutex> locker(m_shutdownMutex);
    m_shutdownLock.waitForWrite();

#if 0
    CurlCacheManager::getInstance()->shutdown();
#endif

    m_liveJobsMutex.lock();
    std::map<int, JobHead*> liveJobs = m_liveJobs;
    m_liveJobs.clear();
    m_liveJobsMutex.unlock();

    MainTaskRunner::destroy();

    std::map<int, JobHead*>::iterator it = liveJobs.begin();
    for (; it != liveJobs.end(); ++it) {
        JobHead* job = it->second;
        if (!job)
            continue;

        while (true) {
            m_liveJobsMutex.lock();
            if (0 < job->getRefCount()) {
                m_liveJobsMutex.unlock();
                ::Sleep(20);
                continue;
            }

            delete job;
            m_liveJobsMutex.unlock();
            break;
        }
    }

    m_threads.clear();
}

void WebURLLoaderManager::initCookieSession(const char* cookieJarFullPath)
{
    // Curl saves both persistent cookies, and session cookies to the cookie file.
    // The session cookies should be deleted before starting a new session.
    //初始化共享curl句柄,用于共享cookies和dns等缓存
    m_shareCookieJar = CookieJarMgr::getInst()->createOrGet(cookieJarFullPath);
}

CURLSH* WebURLLoaderManager::getCurlShareHandle() const
{
    return m_shareCookieJar->getCurlShareHandle();
}

WebCookieJarImpl* WebURLLoaderManager::getShareCookieJar() const
{
    return m_shareCookieJar;
}

WebURLLoaderManager* WebURLLoaderManager::m_sharedInstance = nullptr;

static std::string getDefaultCookiesFullpath()
{
#if 0 // defined(OS_WIN)
    std::vector<WCHAR> path;
    path.resize(MAX_PATH + 1);
    memset(&path[0], 0, sizeof(WCHAR) * (MAX_PATH + 1));
    ::GetModuleFileNameW(nullptr, &path[0], MAX_PATH);
    ::PathRemoveFileSpecW(&path[0]);
    ::PathAppendW(&path[0], L"cookies.dat");
    return base::UTF16ToUTF8((const char16_t*)path.data());
#else
    base::FilePath path;
    base::PathService::Get(base::DIR_MODULE, &path);
    path = path.AppendASCII("cookies.dat");
    std::string ret = path.AsUTF8Unsafe();
    return ret;
#endif
}

WebURLLoaderManager* WebURLLoaderManager::sharedInstance()
{
    if (!m_sharedInstance) {
        std::string defaultCookiesFullpath = getDefaultCookiesFullpath();
        m_sharedInstance = new WebURLLoaderManager(defaultCookiesFullpath.c_str());
    }
    if (m_sharedInstance->isShutdown())
        return nullptr;
    return m_sharedInstance;
}

void WebURLLoaderManager::setCookieJarFullPath(const char* path)
{
    if (!m_sharedInstance) {
        m_sharedInstance = new WebURLLoaderManager(path);
    } else {
        WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
        WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

        WebCookieJarImpl* cookieJar = CookieJarMgr::getInst()->createOrGet(path);
        m_sharedInstance->m_shareCookieJar = cookieJar;
    }
    DCHECK(m_sharedInstance->m_shareCookieJar);
}

// https://rbt.guorenpcic.com/api/grecar/print/transcriptPrintNew?policyNo=6191515000518004167&loginComCode=151515HH&userCode=W1500227 pdf没有mime，强行设置
static void parseMimeIfNeeded(WebURLLoaderManager* manager, WebURLLoaderInternal* job, const char* data, int dataLengt)
{
    String mime = job->m_response.MimeType();
    if (!job->m_needParseMime || (!mime.IsNull() && !mime.empty()))
        return;
    job->m_needParseMime = false;

    if (dataLengt > 6 && 0 == memcmp(data, "%PDF-", 5)) {
        job->m_response.SetMimeType(blink::WebString::FromUTF8("application/pdf"));
    }
}

void WebURLLoaderManager::handleDidSentData(WebURLLoaderInternal* job, unsigned long long bytesSent, unsigned long long totalBytesToBeSent)
{
    blink::URLLoaderClient* client = job->client();
    if (job->m_hadHandleDidSentData)
        return;
    job->m_hadHandleDidSentData = true;
    client->DidSendData(bytesSent, totalBytesToBeSent);
}

static void startLoadingResponseBody(WebURLLoaderInternal* job)
{
    const blink::WebURLResponse& response = job->m_response;
    if (job->m_isSynchronous) {// 同步请求不用管道了，直接用老的DidReceiveDataForTesting。因为同步请求的client都是mbnet::BlinkSynchronousLoader
        WTF::SegmentedBuffer buf;
        absl::variant<mojo::ScopedDataPipeConsumerHandle, WTF::SegmentedBuffer> body = std::move(buf);
        job->client()->DidReceiveResponse(response, std::move(body), std::nullopt);
        return;
    }

    if (0 == job->m_dataPipeProducerHandle) {
        MojoHandle dataPipeConsumerHandle;
        MojoCreateDataPipeOptions createDataOptions;
        createDataOptions.element_num_bytes = 1;
        createDataOptions.capacity_num_bytes = -1;
        MojoCreateDataPipe(&createDataOptions, &job->m_dataPipeProducerHandle, &dataPipeConsumerHandle);
        MojoSetDebugMojoHandleStr(job->m_dataPipeProducerHandle, "startLoadingResponseBody");

        mojo::DataPipeConsumerHandle dataPipeConsumer(dataPipeConsumerHandle);
        mojo::ScopedDataPipeConsumerHandle responseBody(std::move(dataPipeConsumer));

        absl::variant<mojo::ScopedDataPipeConsumerHandle, WTF::SegmentedBuffer> body = std::move(responseBody);
        job->client()->DidReceiveResponse(response, std::move(body), std::nullopt);
    } else {
        mojo::ScopedDataPipeConsumerHandle responseBody;
        absl::variant<mojo::ScopedDataPipeConsumerHandle, WTF::SegmentedBuffer> body = std::move(responseBody);
        job->client()->DidReceiveResponse(response, std::move(body), std::nullopt);
    }
}

void WebURLLoaderManager::handlReceiveData(WebURLLoaderInternal* job, const char* data, int dataLength, int encodedDataLength)
{
    blink::URLLoaderClient* client = job->client();
    uint32_t numBytes = (uint32_t)dataLength;

    if (0 == job->m_dataPipeProducerHandle) {
        if (job->m_isSynchronous) {
            client->DidReceiveDataForTesting(base::span<const char>(data, (size_t)dataLength));
            //CurlCacheManager::getInstance()->didReceiveData(*job, data, dataLength);
        } else {
            //startLoadingResponseBody(job, data, dataLength);
        }
    } else {
        MojoWriteData(job->m_dataPipeProducerHandle, data, &numBytes, /*const MojoWriteDataOptions**/ nullptr);
    }

    //client->DidReceiveData(data, dataLength);
    //CurlCacheManager::getInstance()->didReceiveData(*job, data, dataLength);
}

void WebURLLoaderManager::didReceiveDataOrDownload(WebURLLoaderInternal* job, const char* data, int dataLength, int encodedDataLength)
{
    job->m_dataLength += dataLength;

#if 0
    if (job->firstRequest()->useStreamOnResponse()) {
        // We don't support ftp_listening_delegate_ and multipart_delegate_ for now.
        // TODO(yhirano): Support ftp listening and multipart.
        *(int*)1 = 1;
        //job->m_bodyStreamWriter->addData(adoptPtr(new FixedReceivedData(data, dataLength, encodedDataLength)));
    }
#endif

    if (true /*!job->firstRequest()->downloadToFile()*/) {
        if (WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt) {
            parseMimeIfNeeded(this, job, data, dataLength);

            //if (job->m_response.HttpStatusCode() <= 400)
            {
                handlReceiveData(job, data, dataLength, encodedDataLength);
            }
        }
        return;
    }

    // DownloadFileBlobCache::inst()->appendDataToBlobCache(client, loader, String(job->m_url), data, dataLength, encodedDataLength);
}

String WebURLLoaderManager::handleHeaderForBlobOnMainThread(WebURLLoaderInternal* job, size_t totalSize)
{
    //     String url(job->m_url);
    //     String result = DownloadFileBlobCache::inst()->createBlobTempFileInfoByUrlIfNeeded(url);
    //     return result;
    *(int*)1 = 1;
    return "";
}

#if ENABLE_WKE == 1
static void dispatchWkeLoadUrlFinishCallback(WebURLLoaderInternal* job, int64_t totalEncodedDataLength)
{
    RequestExtraData* requestExtraData = reinterpret_cast<RequestExtraData*>(job->firstRequest()->extraData());
    if (!requestExtraData)
        return;

    WebPage* page = requestExtraData->page;
    if (!page)
        return;

    wkeLoadUrlFinishCallback loadUrlFinishCallback = page->wkeHandler().loadUrlFinishCallback;
    void* loadUrlFinishCallbackParam = page->wkeHandler().loadUrlFinishCallbackParam;
    Vector<char> urlBuf = WTF::ensureStringToUTF8(job->firstRequest()->url().string(), true);
    if (loadUrlFinishCallback)
        loadUrlFinishCallback(page->wkeWebView(), loadUrlFinishCallbackParam, urlBuf.data(), job, (int)totalEncodedDataLength);
}
#endif

// 之所以要搞个异步的，是因为hook url的逻辑下，
// W:\mycode\mb108\third_party\blink\renderer\bindings\core\v8\script_streamer.cc
// 会触发ResourceScriptStreamer::OnDataPipeReadable的断言。因为这里收到arm的回调，但BeginReadData却因MojoClose断开导致MOJO_RESULT_FAILED_PRECONDITION
void asynMojoClose(MojoHandle handle)
{
    //     WebURLLoaderManager::sharedInstance()->getMainRunner()->PostDelayedTask(FROM_HERE, base::BindOnce([](MojoHandle handle) {
    //         ::MojoClose(handle);
    //     }, handle), base::Seconds(3));

    //     WebURLLoaderManager::sharedInstance()->getMainRunner()->PostTask(FROM_HERE, base::BindOnce([](MojoHandle handle) {
    //         ::MojoClose(handle);
    //     }, handle));

    ::MojoMakeDelayCloseFlag(handle);
}

void WebURLLoaderManager::handleDidFinishLoading(WebURLLoaderInternal* job, int64_t finishTime, int64_t totalEncodedDataLength)
{
    //     if (job->m_bodyStreamWriter) {
    //         delete job->m_bodyStreamWriter;
    //         job->m_bodyStreamWriter = nullptr;
    //     }

    GURL url = job->firstRequest()->url;
#if 0
    setBlobDataLengthByTempPath(job);
#endif
    if (WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt) {
        // mb108好像不能在这调用。didsenddata是表示上传数据的
        // handleDidSentData(job, job->m_totalBytesToBeSent, job->m_totalBytesToBeSent);

#if ENABLE_WKE == 1
        dispatchWkeLoadUrlFinishCallback(job, totalEncodedDataLength);
#endif
        if (0 == job->m_dataPipeProducerHandle && !job->m_isSynchronous) {
            DebugBreak(); // 按理不会出现没读取response就finish的情况
            CHECK(!job->responseFired());            
            job->m_response.SetExpectedContentLength(0);
            job->m_response.SetCurrentRequestUrl(blink::KURL(url));
            job->m_response.SetHttpStatusCode(200);
            startLoadingResponseBody(job); // 必须搞个假的，不然FetchManager::Loader::DidFinishLoading会断言错误
        }

        if (!job->isCancelled()) {
            job->client()->DidFinishLoading(
                base::TimeTicks::Now(), totalEncodedDataLength, totalEncodedDataLength, totalEncodedDataLength);
            job->resetClient();
        }
        asynMojoClose(job->m_dataPipeProducerHandle);
        job->m_dataPipeProducerHandle = 0;
//         } else {
//             blink::WebURLError error(-3, blink::KURL(String(job->m_url)));
//             job->client()->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
//         }
#if 0
        CurlCacheManager::getInstance()->didFinishLoading(*job);
#endif
    } else {
        if (!job->isCancelled()) {
            job->client()->DidFinishLoading(
                base::TimeTicks::Now(), totalEncodedDataLength, totalEncodedDataLength, totalEncodedDataLength);
            job->resetClient();
        }
        CHECK(0 == job->m_dataPipeProducerHandle);
    }
}

static void handleExternalProtocol(const GURL& url)
{
    if (!url.SchemeIs("tencent") && !url.SchemeIs("xunlei"))
        return;

    curl_version_info_data* curlVer = curl_version_info(CURLVERSION_FIRST);

    for (int i = 0; curlVer->protocols[i]; ++i) {
        const char* protocol = curlVer->protocols[i];
        if (!url.SchemeIs(protocol))
            continue;
        return;
    }
    ShellExecuteA(NULL, NULL, url.spec().c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void WebURLLoaderManager::handleDidFail(WebURLLoaderInternal* job, const blink::WebURLError& error)
{
#if 0
    if (job->m_bodyStreamWriter) {
        job->m_bodyStreamWriter->fail();
        delete job->m_bodyStreamWriter;
        job->m_bodyStreamWriter = nullptr;
    }
#endif
    GURL url = job->firstRequest()->url;

    handleExternalProtocol(url);

#if 0
    setBlobDataLengthByTempPath(job);
#endif
    if (WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt) {
        job->client()->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
        job->resetClient();
        asynMojoClose(job->m_dataPipeProducerHandle);
        job->m_dataPipeProducerHandle = 0;
#if 0
        CurlCacheManager::getInstance()->didFail(*job);
#endif
    } else {
        job->client()->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
        job->resetClient();
        CHECK(0 == job->m_dataPipeProducerHandle);
    }

#if 0
    RequestExtraData* requestExtraData = reinterpret_cast<RequestExtraData*>(job->firstRequest()->extraData());
    if (!requestExtraData)
        return;

    WebPage* page = requestExtraData->page;
    if (!page)
        return;

#if ENABLE_WKE == 1
    wkeLoadUrlFailCallback loadUrlFailCallback = page->wkeHandler().loadUrlFailCallback;
    void* loadUrlFailCallbackParam = page->wkeHandler().loadUrlFailCallbackParam;
    Vector<char> urlBuf = WTF::ensureStringToUTF8(job->firstRequest()->url().string(), true);
    if (loadUrlFailCallback)
        loadUrlFailCallback(page->wkeWebView(), loadUrlFailCallbackParam, urlBuf.data(), job);
#endif
#endif
}

static void cancelBodyStreaming(int jobId)
{
    AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job)
        return;
#if 0
    if (job->m_bodyStreamWriter) {
        job->m_bodyStreamWriter->fail();
        delete job->m_bodyStreamWriter;
        job->m_bodyStreamWriter = nullptr;
    }
#endif
    if (job->client() && WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt) {
        // TODO(yhirano): Set |stale_copy_in_cache| appropriately if possible.
        blink::WebURLError error(net::ERR_ABORTED, blink::KURL(String(job->m_url)));
        job->client()->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
        job->resetClient();
#if 0
        CurlCacheManager::getInstance()->didFail(*job);
#endif
    }

    // Notify the browser process that the request is canceled.
    WebURLLoaderManager::sharedInstance()->cancel(jobId);
}

#if ENABLE_WKE == 1
static void dispatchWkeLoadUrlHeadersReceivedCallback(WebURLLoaderInternal* job)
{
    RequestExtraData* requestExtraData = reinterpret_cast<RequestExtraData*>(job->firstRequest()->extraData());
    if (!requestExtraData)
        return;

    WebPage* page = requestExtraData->page;
    if (!page)
        return;

    wkeLoadUrlHeadersReceivedCallback loadUrlHeadersReceivedCallback = page->wkeHandler().loadUrlHeadersReceivedCallback;
    void* loadUrlHeadersReceivedCallbackParam = page->wkeHandler().loadUrlHeadersReceivedCallbackParam;
    Vector<char> urlBuf = WTF::ensureStringToUTF8(job->firstRequest()->url().string(), true);
    if (loadUrlHeadersReceivedCallback)
        loadUrlHeadersReceivedCallback(page->wkeWebView(), loadUrlHeadersReceivedCallbackParam, urlBuf.data(), job);
}
#endif

void WebURLLoaderManager::handleDidReceiveResponse(WebURLLoaderInternal* job)
{
    const blink::WebURLResponse& response = job->m_response;
#if 0
    WebDataConsumerHandle* readHandle = nullptr;
    if (job->firstRequest() && job->firstRequest()->useStreamOnResponse()) {
        SharedMemoryDataConsumerHandle::BackpressureMode mode = SharedMemoryDataConsumerHandle::kDoNotApplyBackpressure;

        String cacheControl = response.httpHeaderField("Cache-Control");
        if (cacheControl == "no-store")
            mode = SharedMemoryDataConsumerHandle::kApplyBackpressure;

        readHandle = new SharedMemoryDataConsumerHandle(mode, WTF::bind(&cancelBodyStreaming, job->m_id), &job->m_bodyStreamWriter);

        // Here |body_stream_writer_| has an indirect reference to |this| and that
        // creates a reference cycle, but it is not a problem because the cycle
        // will break if one of the following happens:
        //  1) The body data transfer is done (with or without an error).
        //  2) |readHandle| (and its reader) is detached.

        // The client takes |readHandle|'s ownership.
        // TODO(yhirano): Support ftp listening and multipart
    }
#endif

    if (WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt) {
#if ENABLE_WKE == 1
        dispatchWkeLoadUrlHeadersReceivedCallback(job);
#endif
        handleDidSentData(job, job->m_totalBytesToBeSent, job->m_totalBytesToBeSent); // 这次mb108新加的逻辑，要小心了

//         if (0 == job->m_dataPipeProducerHandle) {
//             if (job->m_isSynchronous) {
//                 DebugBreak();
//                 //client->DidReceiveData(data, dataLength);
//                 //CurlCacheManager::getInstance()->didReceiveData(*job, data, dataLength);
//             } else
//                 startLoadingResponseBody(job, data, dataLength);
//         }
        startLoadingResponseBody(job);
    }
}

static std::vector<char>* s_dump = nullptr;

bool isAscii(char c)
{
    return ('a' <= c && c < 'z' || 'A' <= c && c < 'Z' || '0' <= c && c < '9');
}

// called with data after all headers have been processed via headerCallbackOnIoThread
static size_t writeCallbackOnIoThread(void* ptr, size_t size, size_t nmemb, void* data)
{
    int jobId = (int)data;
    AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job || job->isCancelled())
        return 0;

    // We should never be called when deferred loading is activated.
    DCHECK(!job->m_defersLoading);

    size_t totalSize = size * nmemb;
    job->m_recvTotalSize += totalSize;

//     std::vector<char> dump;
//     dump.resize(totalSize);
//     memcpy(dump.data(), ptr, totalSize);
//     dump.push_back('\0');
//     const char* addr = strstr(dump.data(), "wlfstk_smdl");
//     if (nullptr != addr /*&& !isAscii(addr[2])*/) {
//         std::string catchUrl = "catchUrl:";
//         catchUrl += job->m_url;
//         catchUrl += "\n";
//         OutputDebugStringA(catchUrl.c_str());
//     }

    //     if (!s_dump)
    //         s_dump = new std::vector<char>();
    //
    //if (std::string::npos != job->m_url.find("api.m.jd.com/?h5st=")) {
    //    OutputDebugStringA("");
    // #ifdef OS_WIN
    //         std::vector<char> temp;
    //         temp.resize(totalSize /*+ 1*/);
    //         memcpy(temp.data(), ptr, totalSize);
    // //         temp[totalSize] = '\0';
    // //         const char* addr = temp.data();
    // //         if (nullptr != strstr(addr, "caplist")) {
    // //             OutputDebugStringA("");
    // //         }
    // //
    // //         size_t oldSize = s_dump->size();
    // //         s_dump->resize(oldSize + totalSize);
    // //         memcpy(s_dump->data() + oldSize, ptr, totalSize);
    //
    //         static int s_count = 0;
    //
    //         char filename[150] = { 0 };
    //         sprintf(filename, "G:\\test\\web_test\\chinaac\\node_modules\\area_array_c_%d.js", s_count++);
    //
    //         HANDLE hFile = CreateFileA(filename, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    //         if (INVALID_HANDLE_VALUE != hFile) {
    //             DWORD numberOfBytesWrite = 0;
    //             BOOL b = ::WriteFile(hFile, temp.data(), temp.size(), &numberOfBytesWrite, nullptr);
    //             ::CloseHandle(hFile);
    //         }
    // #else
    //         printf("area_array_c::::::::::::::::::::::%d\n", totalSize);
    // #endif
    //}

    // this shouldn't be necessary but apparently is. CURL writes the data
    // of html page even if it is a redirect that was handled internally
    // can be observed e.g. on gmail.com
    long httpCode = 0;
    CURLcode err = curl_easy_getinfo(job->m_handle, !job->m_isProxyConnect ? CURLINFO_RESPONSE_CODE : CURLINFO_HTTP_CONNECTCODE, &httpCode);
    if (CURLE_OK == err && httpCode >= 300 && httpCode < 400)
        return totalSize;

    WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kWriteCallback, ptr, size, nmemb, totalSize);
    return totalSize;
}

static bool checkIsProxyHead(WebURLLoaderInternal* job, char* ptr, size_t size)
{
    if (0 == size || !job->m_isProxy)
        return false;

    Vector<char> buffer;
    buffer.resize(size + 1);
    memset(buffer.data(), 0, buffer.size());
    memcpy(buffer.data(), ptr, size);

    if ((2 == size && buffer[0] == '\r' && buffer[1] == '\n') || (1 == size && buffer[0] == '\n')) {
        job->m_isProxyHeadRequest = false;
        return true;
    }

    if (job->m_isProxyHeadRequest)
        return true;

    job->m_isProxyHeadRequest = (0 != strstr(buffer.data(), "Connection Established"));
    return job->m_isProxyHeadRequest;
}

static size_t headerCallbackOnIoThread(char* ptr, size_t size, size_t nmemb, void* data)
{
    int jobId = (int)data;
    AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job || job->isCancelled())
        return 0;

    // We should never be called when deferred loading is activated.
    DCHECK(!job->m_defersLoading);

    size_t totalSize = size * nmemb;
    if (checkIsProxyHead(job, ptr, totalSize))
        return totalSize;

    if (0 == size * nmemb)
        DCHECK(false);

    job->m_hasCallResponse = true;
    WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kHeaderCallback, ptr, size, nmemb, totalSize);
    return totalSize;
}

static curlioerr ioctlCallbackOnIoThread(CURL* handle, int cmd, void* data)
{
    int jobId = (int)data;
    AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job || job->isCancelled() || !job->m_formDataStream)
        return CURLIOE_UNKNOWNCMD;

    if (cmd == CURLIOCMD_RESTARTREAD) {
        job->m_formDataStream->reset();
        return CURLIOE_OK;
    }
    return CURLIOE_UNKNOWNCMD;
}

size_t readCallbackOnIoThread(void* ptr, size_t size, size_t nmemb, void* data)
{
    int jobId = (int)data;
    AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job || job->isCancelled() || !job->m_formDataStream)
        return 0;

    // We should never be called when deferred loading is activated.
    DCHECK(!job->m_defersLoading);

    if (!size || !nmemb)
        return 0;

    if (!job->m_formDataStream->hasMoreElements()) {
        delete job->m_formDataStream;
        job->m_formDataStream = nullptr;
        return 0;
    }

    size_t sent = job->m_formDataStream->read(ptr, size, nmemb, nullptr);

    // Something went wrong so cancel the job.
    if (!sent && WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt)
        WebURLLoaderManager::sharedInstance()->doCancel(job, kNormalCancelled);

    WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kDidSentData, nullptr, size, nmemb, 0);

    return sent;
}

bool WebURLLoaderManager::downloadOnIoThread()
{
    if (m_isShutdown)
        return false;

    CURLM* curlMultiHandle = getCurrentThreadCurlMultiHandle();

    fd_set fdread;
    fd_set fdwrite;
    fd_set fdexcep;
    int maxfd = 0;

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = selectTimeoutMS * 1000; // select waits microseconds
        // Retry 'select' if it was interrupted by a process signal.
    int rc = 0;
    do {
        FD_ZERO(&fdread);
        FD_ZERO(&fdwrite);
        FD_ZERO(&fdexcep);
        curl_multi_fdset(curlMultiHandle, &fdread, &fdwrite, &fdexcep, &maxfd);
        // When the 3 file descriptors are empty, winsock will return -1
        // and bail out, stopping the file download. So make sure we
        // have valid file descriptors before calling select.
        if (maxfd >= 0)
            rc = ::select(maxfd + 1, &fdread, &fdwrite, &fdexcep, &timeout);
    } while (rc == -1 && errno == EINTR);

    if (-1 == rc) {
#ifndef NDEBUG
        perror("bad: select() returned -1: ");
#endif
        return false;
    }

    int runningHandles = 0;
    while (curl_multi_perform(curlMultiHandle, &runningHandles) == CURLM_CALL_MULTI_PERFORM) {
    }

    // check the curl messages indicating completed transfers
    // and free their resources
    while (true) {
        int messagesInQueue;
        CURLMsg* msg = curl_multi_info_read(curlMultiHandle, &messagesInQueue);
        if (!msg)
            break;

        // find the node which has same job->m_handle as completed transfer
        CURL* handle = msg->easy_handle;
        DCHECK(handle);
        char* info = NULL;
        CURLcode err = curl_easy_getinfo(handle, CURLINFO_PRIVATE, &info);
        int jobId = (int)info;
        DCHECK(/*err,*/ CURLE_OK == err);
        DCHECK(jobId > 0);
        AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
        WebURLLoaderInternal* job = autoLockJob.lock();
        if (!job)
            continue;

        DCHECK(job->m_handle == handle);
        if (job->isCancelled()) {
            removeFromCurlOnIoThread(jobId);
            continue;
        }

        if (CURLMSG_DONE != msg->msg)
            continue;

        if (CURLE_OK == msg->data.result) {
            if (!job->responseFired()) {
                WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kHandleLocalReceiveResponse, nullptr, 0, 0, 0);
                if (job->isCancelled()) {
                    removeFromCurlOnIoThread(jobId);
                    continue;
                }
            }

            if (job->m_isHookRequest)
                WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kHandleHookRequest, nullptr, 0, 0, 0);
#if 0
            if (job->m_multipartHandle) {
                WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kContentEnded, nullptr, 0, 0, 0);
            } else
#endif
            if (job->client() && job->loader()) {
                WebURLLoaderManagerMainTask::createAndPushTask(jobId, WebURLLoaderManagerMainTask::TaskType::kDidFinishLoading, nullptr, 0, 0, 0);
            }
        } else {
            const char* url = nullptr;
            curl_easy_getinfo(job->m_handle, CURLINFO_EFFECTIVE_URL, &url);
            if (!url)
                url = "url is empty";
            if (job->client() && job->loader()) {
                URLError* resourceError = new URLError();
                resourceError->reason = -3; // 不能像老版本那样写成msg->data.result了。因为这个reason会变成net/base里的错误码
                resourceError->domain = url;
                resourceError->unreachableURL = url;
                resourceError->localizedDescription = curl_easy_strerror(msg->data.result);

                char* output = (char*)malloc(0x300 + strlen(url));
                sprintf(output, "kDidFail on io Thread:%d, %s\n", msg->data.result, url);
                OutputDebugStringA(output);
                free(output); // !!!!!!!!!!!!!!!!!!!!

                WebURLLoaderManagerMainTask::createAndPushResErrTask(jobId, resourceError);
            }
        }

        removeFromCurlOnIoThread(jobId);
    }

    return (runningHandles > 0); // 如果还有请求未处理则返回true,下个timer继续处理
}

void WebURLLoaderManager::setProxyInfo(const String& host, unsigned long port, ProxyType type, const String& username, const String& password)
{
    m_proxyType = type;

    if (!host.length()) {
        m_proxy = base::EmptyString();
    } else {
        std::string userPass;
        if (username.length() || password.length())
            userPass = username.Utf8() + ":" + password.Utf8() + "@";

        m_proxy = userPass + host.Utf8() + ":" + base::NumberToString(port);
        if (!base::StartsWith(m_proxy, "https://") && !base::StartsWith(m_proxy, "http://"))
            m_proxy.insert(0, "http://");
    }
}

void WebURLLoaderManager::removeFromCurlOnIoThread(int jobId)
{
    AutoLockJob autoLockJob(this, jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job)
        return;

    WTF::Locker<WTF::RecursiveMutex> locker(*(job->m_destroingMutex.get()));

    WebURLLoaderInternal::State state = job->m_state;
    DCHECK(WebURLLoaderInternal::kDestroyed != state);

    job->m_state = WebURLLoaderInternal::kDestroying;
    if (WebURLLoaderInternal::kNormal == state) {
        m_runningJobs--;

        if (/*!job->m_isWkeNetSetDataBeSetted && !job->m_isBlackList && !job->m_isDataUrl*/ job->m_handle) {
            //DCHECK(job->m_handle);

            if (job->m_handle) {
                curl_multi_remove_handle(getCurrentThreadCurlMultiHandle(), job->m_handle);
                curl_easy_cleanup(job->m_handle);
            }
            job->m_handle = nullptr;
            WebURLLoaderManagerMainTask* task
                = WebURLLoaderManagerMainTask::createTask(jobId, WebURLLoaderManagerMainTask::TaskType::kRemoveFromCurl, nullptr, 0, 0, 0);
            //             if (task) // 退出时候，这里可能为null
            //                 Platform::current()->mainThread()->scheduler()->postLoadingTask(FROM_HERE, task); // postLoadingTask
            WebURLLoaderManagerMainTask::pushTask(nullptr, getMainRunner(), task);
        }
    }
}

static inline size_t getFormElementsCount(WebURLLoaderInternal* job)
{
    scoped_refptr<network::ResourceRequestBody> httpBody = job->firstRequest()->request_body;
    if (!httpBody.get() || !httpBody->elements())
        return 0;

    // Resolve the blob elements so the formData can correctly report it's size.
    //formData = formData->resolveBlobReferences();
    //job->firstRequest().setHTTPBody(httpBody);

    return httpBody->elements()->size();
}

static void setupReadAndIoctlCallbackOnIoThread(WebURLLoaderInternal* job)
{
    curl_easy_setopt(job->m_handle, CURLOPT_READFUNCTION, readCallbackOnIoThread);
    curl_easy_setopt(job->m_handle, CURLOPT_READDATA, job->m_id);

    curl_easy_setopt(job->m_handle, CURLOPT_IOCTLFUNCTION, ioctlCallbackOnIoThread);
    curl_easy_setopt(job->m_handle, CURLOPT_IOCTLDATA, job->m_id);
}

static void setupFormDataOnIoThread(WebURLLoaderInternal* job, SetupDataInfo* info)
{
    if (info && !info->chunkedTransfer) {
        if (info->islongLong)
            curl_easy_setopt(job->m_handle, info->sizeOption, (long long)info->size);
        else
            curl_easy_setopt(job->m_handle, info->sizeOption, (int)info->size);
    }

    DCHECK(!job->m_formDataStream);
    job->m_formDataStream = new FlattenHTTPBodyElementStream(info->flattenElements, info->size);
    setupReadAndIoctlCallbackOnIoThread(job);
}

static void dispatchPostBodyToWke(WebURLLoaderInternal* job, WTF::Vector<FlattenHTTPBodyElement*>* flattenElements)
{
    //     RequestExtraData* requestExtraData = reinterpret_cast<RequestExtraData*>(job->firstRequest()->extraData());
    //     if (!requestExtraData)
    //         return;
    //
    //     WebPage* page = requestExtraData->page;
    //     if (!page->wkeHandler().otherLoadCallback)
    //         return;
    //
    //     wkeTempCallbackInfo* tempInfo = wkeGetTempCallbackInfo(page->wkeWebView());
    //     Vector<char> urlBuf = WTF::ensureStringToUTF8(job->firstRequest()->url().string(), true);
    //     tempInfo->url = urlBuf.data();
    //
    //     tempInfo->postBody = wke::flattenHTTPBodyElementToWke(*flattenElements);
    //
    //     page->wkeHandler().otherLoadCallback(page->wkeWebView(), page->wkeHandler().otherLoadCallbackParam, WKE_DID_POST_REQUEST, tempInfo);
    //     if (tempInfo->postBody->isDirty)
    //         wke::wkeflattenElementToBlink(*tempInfo->postBody, flattenElements);
    //     else
    //         wkeNetFreePostBodyElements(tempInfo->postBody);
}

static SetupDataInfo* setupFormDataOnMainThread(WebURLLoaderInternal* job, CURLoption sizeOption, struct curl_slist** headers)
{
    scoped_refptr<network::ResourceRequestBody> httpBody = job->firstRequest()->request_body;
    if (!httpBody.get() || nullptr == httpBody->elements())
        return nullptr;
    size_t elementCount = httpBody->elements()->size();

    // The size of a curl_off_t could be different in WebKit and in cURL depending on
    // compilation flags of both.
    static int expectedSizeOfCurlOffT = 0;
    if (!expectedSizeOfCurlOffT) {
        curl_version_info_data* infoData = curl_version_info(CURLVERSION_NOW);
        if (infoData->features & CURL_VERSION_LARGEFILE)
            expectedSizeOfCurlOffT = sizeof(long long);
        else
            expectedSizeOfCurlOffT = sizeof(int);

        expectedSizeOfCurlOffT = sizeof(int); // weolar
    }

    static const long long maxCurlOffT = (1LL << (expectedSizeOfCurlOffT * 8 - 1)) - 1;
    // Obtain the total size of the form data
    curl_off_t size = 0;
    SetupDataInfo* result = new SetupDataInfo();
    result->chunkedTransfer = false;

    int64_t fileSizeResult = 0;
    for (size_t i = 0; i < elementCount; ++i) {
        const network::DataElement& element = httpBody->elements()->at(i);

        FlattenHTTPBodyElement* flattenElement = nullptr;
        if (network::DataElement::Tag::kFile == element.type()) {
            DebugBreak();
            //             const network::DataElementFile& fileEle = element.As<network::DataElementFile>();
            //
            //             if (base::GetFileSize(fileEle, fileSizeResult)) {
            //                 if (fileSizeResult > maxCurlOffT) {
            //                     // File size is too big for specifying it to cURL
            //                     result->chunkedTransfer = true;
            //                     break;
            //                 }
            //             } else {
            //                 result->chunkedTransfer = true;
            //                 break;
            //             }
            //
            //             long long offset = element.offset();
            //             long long length = element.length();
            //             FlattenHTTPBodyElementStream::clampSliceOffsets(fileSizeResult, &offset, &length);
            //             size += length;
            //
            //             flattenElement = new FlattenHTTPBodyElement();
            //             flattenElement->type = FlattenHTTPBodyElement::Type::TypeFile;
            //             Vector<UChar> filePath = WTF::ensureUTF16UChar(element.path(), true);
            //             flattenElement->filePath = filePath.data();
            //             flattenElement->fileStart = offset;
            //             flattenElement->fileLength = length;
            //             result->flattenElements.append(flattenElement);
        } else if (network::DataElement::Tag::kBytes == element.type()) {
            const network::DataElementBytes& bytesEle = element.As<network::DataElementBytes>();
            size += bytesEle.bytes().size();

            flattenElement = new FlattenHTTPBodyElement();
            flattenElement->type = FlattenHTTPBodyElement::Type::TypeData;
            //flattenElement->data.Append(bytesEle.bytes().data(), bytesEle.bytes().size());
            flattenElement->data.insert(flattenElement->data.end(), bytesEle.bytes().begin(), bytesEle.bytes().end());

            result->flattenElements.push_back(flattenElement);
        } else if (network::DataElement::Tag::kDataPipe == element.type()) {
            flattenElement = new FlattenHTTPBodyElement();
            flattenElement->type = FlattenHTTPBodyElement::Type::TypeData;

            const network::DataElementDataPipe& dataPipe = element.As<network::DataElementDataPipe>();
            //FlattenHTTPBodyElementStream::flatten(element.blobUUID, &size, &result->flattenElements, 0, -1, true, 1);
            FlattenHTTPBodyElementStream::readFromDatePipe(flattenElement, dataPipe);

            size += flattenElement->data.size();
            result->flattenElements.push_back(flattenElement);
        } else if (network::DataElement::Tag::kChunkedDataPipe == element.type()) {
            DebugBreak();
        } else {
            DebugBreak();
        }
    }

    // dispatchPostBodyToWke(job, &result->flattenElements);

    // cURL guesses that we want chunked encoding as long as we specify the header
    if (result->chunkedTransfer)
        *headers = curl_slist_append(*headers, "Transfer-Encoding: chunked");
    else {
        result->sizeOption = sizeOption;
        result->size = size;
        result->islongLong = (sizeof(long long) == expectedSizeOfCurlOffT);
    }

    job->m_totalBytesToBeSent = size;

    return result;
}

static void setupPutOnIoThread(WebURLLoaderInternal* job, SetupPutInfo* info)
{
    if (!info)
        return;

    curl_easy_setopt(job->m_handle, CURLOPT_UPLOAD, TRUE); // CURLOPT_PUT
    curl_easy_setopt(job->m_handle, CURLOPT_INFILESIZE, 0);

    if (info->data)
        setupFormDataOnIoThread(job, info->data);
}

static SetupPutInfo* setupPutOnMainThread(WebURLLoaderInternal* job, struct curl_slist** headers)
{
    *headers = curl_slist_append(*headers, "Expect:"); // Disable the Expect: 100 continue header

    size_t numElements = getFormElementsCount(job);
    if (!numElements)
        return nullptr;

    SetupPutInfo* result = new SetupPutInfo();
    result->data = setupFormDataOnMainThread(job, CURLOPT_INFILESIZE, headers);
    return result;
}

static void setupPostOrPutOnIoThread(WebURLLoaderInternal* job, bool isPost, SetupDataInfo* data)
{
    if (isPost) {
        curl_easy_setopt(job->m_handle, CURLOPT_POST, TRUE);
    } else {
        curl_easy_setopt(job->m_handle, CURLOPT_POST, FALSE);
        curl_easy_setopt(job->m_handle, CURLOPT_UPLOAD, TRUE);
        curl_easy_setopt(job->m_handle, CURLOPT_PUT, TRUE);
    }

    if (!data) {
        curl_easy_setopt(job->m_handle, CURLOPT_POSTFIELDSIZE, 0);
        setupReadAndIoctlCallbackOnIoThread(job);
        return;
    }

    if (isPost && data && 1 == data->flattenElements.size()) {
        FlattenHTTPBodyElement* element = data->flattenElements[0];
        if (FlattenHTTPBodyElement::TypeData == element->type || FlattenHTTPBodyElement::TypeBlob == element->type) {
            curl_easy_setopt(job->m_handle, CURLOPT_POSTFIELDSIZE, element->data.size());
            curl_easy_setopt(job->m_handle, CURLOPT_COPYPOSTFIELDS, element->data.data());

            //InterlockedExchangeAdd(reinterpret_cast<long volatile*>(&job->m_sentDataBytes), static_cast<long>(element->data.size()));
            base::subtle::NoBarrier_AtomicIncrement((base::subtle::Atomic32 volatile*)(&job->m_sentDataBytes), (base::subtle::Atomic32)(element->data.size()));

            delete element;
            return;
        }
    }

    if (data)
        setupFormDataOnIoThread(job, data);
}

static SetupPostInfo* setupPostOnMainThread(WebURLLoaderInternal* job, struct curl_slist** headers)
{
    // *headers = curl_slist_append(*headers, "Expect:100-continue"); // Disable the Expect: 100 continue header
    *headers = curl_slist_append(*headers, "Expect:"); // https://blog.csdn.net/pzqingchong/article/details/70196092
    size_t numElements = getFormElementsCount(job);
    if (!numElements)
        return nullptr;

    SetupPostInfo* result = new SetupPostInfo();
    result->data = setupFormDataOnMainThread(job, CURLOPT_POSTFIELDSIZE, headers); // CURLOPT_POSTFIELDSIZE_LARGE
    return result;
}

AutoLockJob::AutoLockJob(WebURLLoaderManager* manager, int jobId)
{
    m_manager = manager;
    m_jobId = jobId;
    m_isNotDerefForDelete = false;
}

WebURLLoaderInternal* AutoLockJob::lock()
{
    if (!m_manager)
        return nullptr;

    JobHead* jobHead = m_manager->checkJob(m_jobId);
    if (!jobHead)
        return nullptr;
    if (JobHead::kLoaderInternal != jobHead->getType())
        return nullptr;

    jobHead->ref();
    WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobHead;
    return job;
}

JobHead* AutoLockJob::lockJobHead()
{
    if (!m_manager)
        return nullptr;

    JobHead* jobHead = m_manager->checkJob(m_jobId);
    if (!jobHead)
        return nullptr;

    jobHead->ref();
    return jobHead;
}

void AutoLockJob::setNotDerefForDelete()
{
    m_isNotDerefForDelete = true;
}

AutoLockJob::~AutoLockJob()
{
    if (m_isNotDerefForDelete || !m_manager)
        return;
    JobHead* job = m_manager->checkJob(m_jobId);
    if (job)
        job->deref();
}

JobHead* WebURLLoaderManager::checkJob(int jobId)
{
    WTF::Locker<WTF::RecursiveMutex> locker(m_liveJobsMutex);
    std::map<int, JobHead*>::iterator it = m_liveJobs.find(jobId);
    if (it == m_liveJobs.end())
        return nullptr;
    return it->second;
}

int WebURLLoaderManager::addLiveJobs(JobHead* job)
{
    //CHECK(WTF::IsMainThread());
    if (m_isShutdown)
        return 0;
    WTF::Locker<WTF::RecursiveMutex> locker(m_liveJobsMutex);

    int jobId = (++m_newestJobId);
    //m_liveJobs.insert_or_assign(jobId, job);
    m_liveJobs[jobId] = job;
    DCHECK(0 == job->m_id);
    job->m_id = jobId;
    return jobId;
}

void WebURLLoaderManager::removeLiveJobs(int jobId)
{
    //CHECK(WTF::IsMainThread());
    if (m_isShutdown)
        return;
    WTF::Locker<WTF::RecursiveMutex> locker(m_liveJobsMutex);
    m_liveJobs.erase(jobId);
}

bool isBlackListUrl(const std::string& url)
{
    char* blackList[] = { //         ".woff2",
        nullptr
    };

    const char* blackFile = nullptr;
    int i = 0;
    for (blackFile = blackList[0]; blackFile; blackFile = blackList[i]) {
        if (std::string::npos != url.find(blackFile))
            return true;
        ++i;
    }

    return false;
}

class HandleDataURLTask {
public:
    HandleDataURLTask(WebURLLoaderManager* manager, int jobId, bool useStreamOnResponse)
    {
        m_manager = manager;
        m_jobId = jobId;
        m_useStreamOnResponse = useStreamOnResponse;
    }

    ~HandleDataURLTask() = default;

    void run() /*override*/
    {
        JobHead* jobHead = m_manager->checkJob(m_jobId);
        if (!jobHead || JobHead::kLoaderInternal != jobHead->getType())
            return;

        WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobHead;
        if (!job || job->isCancelled())
            return;

        GURL url = job->firstRequest()->url;
        handleDataURL(m_jobId, job->loader(), job->client(), blink::KURL(url), m_useStreamOnResponse, false);
    }

private:
    WebURLLoaderManager* m_manager;
    int m_jobId;
    bool m_useStreamOnResponse;
};

class HandleDownloadBlobOrDataURLTask {
public:
    HandleDownloadBlobOrDataURLTask(WebURLLoaderManager* manager, int jobId)
    {
        m_manager = manager;
        m_jobId = jobId;
    }

    ~HandleDownloadBlobOrDataURLTask() = default;

    void run() /*override*/
    {
        JobHead* jobHead = m_manager->checkJob(m_jobId);
        if (!jobHead || JobHead::kLoaderInternal != jobHead->getType())
            return;

        WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobHead;
        if (!job || job->isCancelled())
            return;

        GURL url = job->firstRequest()->url;
        handleDownloadBlobOrDataUrl(job, url, false);
    }

private:
    WebURLLoaderManager* m_manager;
    int m_jobId;
};

static bool isLocalFileNotExist(const char* urlTrim, WebURLLoaderInternal* job)
{
    return false;

    // 有外部hook，则不走快速判断流程
    //     if (g_pfnOpen)
    //         return false;
    //
    //     RequestExtraData* requestExtraData = reinterpret_cast<RequestExtraData*>(job->firstRequest()->extraData());
    //     if (!requestExtraData)
    //         return false;
    //
    //     WebPage* page = requestExtraData->page;
    //     if (!page->wkeHandler().loadUrlBeginCallback)
    //         return false;
    //
    //     String url(urlTrim);
    //     if (url.startsWith("file:///"))
    //         url.remove(0, sizeof("file:///") - 1);
    //     url.replace("/", "\\");
    //
    //     size_t questionMarkPos = url.find("?");
    //     if (WTF::kNotFound != questionMarkPos)
    //         url = url.substring(0, questionMarkPos);
    //
    //     bool result = false;
    //     Vector<UChar> buf = WTF::ensureUTF16UChar(url, true);
    //     result = !::PathFileExistsW(buf.data());
    //     if (!result)
    //         return false;
    //
    //     String outString = String::format("isLocalFileNotExist: %s\n", WTF::ensureStringToUTF8(url, true).data());
    //     OutputDebugStringW(outString.charactersWithNullTermination().data());
    //
    //     return result;
}

int WebURLLoaderManager::addAsynchronousJob(WebURLLoaderInternal* job)
{
    //DCHECK(WTF::IsMainThread()); // 有可能在web worker线程

    GURL kurl = job->firstRequest()->url;
    std::string url = kurl.possibly_invalid_spec();

#if 0
    //if (WTF::kNotFound != url.find("/v_1"))
    //    OutputDebugStringA("");
    
    String outString = String::Format("addAsynchronousJob: %d, %s\n", m_liveJobs.size(), url.c_str());
    OutputDebugStringA(outString.Utf8().c_str());
#endif

#if 0
    if (wke::g_isDecodeUrlRequest && !kurl.protocolIsData()) {
        url = blink::decodeURLEscapeSequences(url);
        job->firstRequest()->setURL((blink::KURL(blink::ParsedURLString, url)));
    }
#endif
    job->m_manager = this;

    int jobId = 0;
    if (isBlackListUrl(url)) {
        jobId = addLiveJobs(job);

        m_mainThreadRunner->PostTask(FROM_HERE,
            base::BindOnce(
                [](BlackListCancelTask* task) {
                    task->run();
                    delete task;
                },
                new BlackListCancelTask(this, jobId)));
        return jobId;
    }

    if ((kurl.SchemeIs("blob") || kurl.SchemeIs("data")) && job->m_downloadName.get() && !(job->m_downloadName->empty())) {
        jobId = addLiveJobs(job);
        m_mainThreadRunner->PostTask(FROM_HERE,
            base::BindOnce(
                [](HandleDownloadBlobOrDataURLTask* task) {
                    task->run();
                    delete task;
                },
                new HandleDownloadBlobOrDataURLTask(this, jobId)));

        return jobId;
    }

    if (kurl.SchemeIs("data")) {
        jobId = addLiveJobs(job);
        job->m_isDataUrl = true;
        bool useStreamOnResponse = false; // job->firstRequest()->useStreamOnResponse();
        m_mainThreadRunner->PostTask(FROM_HERE,
            base::BindOnce(
                [](HandleDataURLTask* task) {
                    task->run();
                    delete task;
                },
                new HandleDataURLTask(this, jobId, useStreamOnResponse)));

        return jobId;
    }

    jobId = initializeHandleOnMainThread(job);
    if (0 == jobId)
        return 0;

    if (job->m_isWkeNetSetDataBeSetted || job->m_isHoldJobToAsynCommit || job->m_isBlackList)
        return jobId;

    continueJob(job);
    return jobId;
}

base::Thread* WebURLLoaderManager::getSyncIoThread() // 单独给某些垃圾网页使用同步io开个线程
{
    if (m_syncIoThread)
        return m_syncIoThread;

    m_syncIoThread = createIoThread("SyncIoThread");

    int waitCount = 1;
    m_syncIoThread->task_runner()->PostTask(
        FROM_HERE, base::BindOnce(&WebURLLoaderManager::initializeMultiHandleOnIoThread, base::Unretained(this), &waitCount));
    while (waitCount) {
        ::Sleep(10);
    }
    return m_syncIoThread;
}

base::Thread* WebURLLoaderManager::getIoThread(IoThreadType type)
{
    if (kIoThreadTypeRes == type || m_threads.size() == 1)
        return m_threads[0];

    if (kIoThreadTypeSync == type)
        return getSyncIoThread();

    int index = rand() % (m_threads.size() - 1);
    return m_threads[index + 1];
}

void WebURLLoaderManager::continueJob(WebURLLoaderInternal* job)
{
    //     if (job->m_isWkeNetSetDataBeSetted) {
    //         Platform::current()->currentThread()->scheduler()->postLoadingTask(FROM_HERE, new HookAsynTask(this, job->m_id));
    //         return;
    //     }

    base::Thread* ioThread = job->m_ioThread;
    ioThread->task_runner()->PostTask(
        FROM_HERE, base::BindOnce(&WebURLLoaderManager::initializeHandleOnIoThread, base::Unretained(this), job->m_id, job->m_initializeHandleInfo));
    ioThread->task_runner()->PostTask(FROM_HERE, base::BindOnce(&WebURLLoaderManager::startOnIoThread, base::Unretained(this), job->m_id));

    IoTask* task = new IoTask(this, ioThread, false);
    ioThread->task_runner()->PostTask(FROM_HERE,
        base::BindOnce(
            [](IoTask* task) {
                task->run();
                //delete task;
            },
            task));
}

void WebURLLoaderManager::cancelWithHookRedirect(WebURLLoaderInternal* job)
{
    doCancel(job, kHookRedirectCancelled);
}

bool WebURLLoaderManager::doCancel(JobHead* jobHead, CancelledReason cancelledReason)
{
    if (JobHead::kLoaderInternal != jobHead->getType()) {
        jobHead->cancel();
        return true;
    }

    WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobHead;
    WTF::Locker<WTF::RecursiveMutex> locker(*(job->m_destroingMutex.get()));
    bool cancelled = job->isCancelled();

    CHECK(kNoCancelled != cancelledReason);
    //RELEASE_ASSERT(!(kHookRedirectCancelled == job->m_cancelledReason && kNormalCancelled == cancelledReason));

    if (!(kHookRedirectCancelled == job->m_cancelledReason && kHookRedirectCancelled != cancelledReason))
        job->m_cancelledReason = cancelledReason;

    //     if (job->m_isWkeNetSetDataBeSetted && kHookRedirectCancelled != cancelledReason && ::IsDebuggerPresent()) {
    //         RELEASE_ASSERT(!job->m_handle);
    //     }

    if (job->m_handle && WebURLLoaderInternal::kDestroying != job->m_state && !cancelled)
        job->m_ioThread->task_runner()->PostTask(FROM_HERE, base::BindOnce(&WebURLLoaderManager::removeFromCurlOnIoThread, base::Unretained(this), job->m_id));

    return false;
}

void WebURLLoaderManager::cancel(int jobId)
{
    //DCHECK(WTF::IsMainThread());
    AutoLockJob autoLockJob(this, jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job || WebURLLoaderInternal::kCacheForDownloadYes == job->m_cacheForDownloadOpt)
        return;

    doCancel(job, kNormalCancelled);
}

void WebURLLoaderManager::cancelAllJobsOfWebview(int webviewId)
{
    m_liveJobsMutex.lock();

    int jobId = -1;
    base::flat_set<int> removedSet;
    std::map<int, JobHead*>::iterator it = m_liveJobs.begin();
    for (; it != m_liveJobs.end(); ++it) {
        JobHead* jobHead = it->second;
        jobId = it->first;

        if (-1 != webviewId && JobHead::kLoaderInternal == jobHead->getType()) {
            WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobHead;
            if (job->m_mbwebviewId != webviewId)
                continue;
        }

        m_liveJobsMutex.unlock();
        if (doCancel(jobHead, kNormalCancelled))
            removedSet.insert(jobId);
        m_liveJobsMutex.lock();
    }

    base::flat_set<int>::iterator itor = removedSet.begin();
    for (; itor != removedSet.end(); ++itor) {
        jobId = *itor;
        m_liveJobs.erase(jobId);
    }
    m_liveJobsMutex.unlock();
}

void WebURLLoaderManager::cancelAll()
{
    cancelAllJobsOfWebview(-1);
}

struct SyncJob {
    SyncJob(WebURLLoaderInternal* job, int jobId)
    {
        this->job = job;
        this->jobId = jobId;
    }
    ~SyncJob()
    {
        job->m_manager->removeLiveJobs(jobId);
        delete job;
    }

    void release()
    {
        --ref;
        if (0 == ref)
            delete this;
    }

    CURLcode ret = CURLE_OK;
    int isCallFinish = 0;
    int ref = 2;
    WebURLLoaderInternal* job = nullptr;
    int jobId = 0;
};

void WebURLLoaderManager::dispatchSynchronousJob(WebURLLoaderInternal* job, base::WaitableEvent* terminateSyncLoadEvent)
{
    job->m_manager = this;
    job->m_isSynchronous = true;

    int jobId = addLiveJobs(job);

    GURL url = job->firstRequest()->url;
    if (url.SchemeIs("data") && job->client()) {
        handleDataURL(jobId, job->loader(), job->client(), blink::KURL(url), false /*job->firstRequest()->useStreamOnResponse()*/, true);
        return;
    }

    InitializeHandleInfo* info = preInitializeHandleOnMainThread(job);
    job->m_initializeHandleInfo = info;

#if 0 // ENABLE_WKE == 1
    Vector<char> urlBuf = WTF::ensureStringToUTF8(job->firstRequest()->url().string(), true);
    RequestExtraData* requestExtraData = reinterpret_cast<RequestExtraData*>(job->firstRequest()->extraData());
    WebPage* page = requestExtraData->page;
    wkeLoadUrlBeginCallback loadUrlBeginCallback = page->wkeHandler().loadUrlBeginCallback;
    if (loadUrlBeginCallback) {
        loadUrlBeginCallback(page->wkeWebView(), page->wkeHandler().loadUrlBeginCallbackParam, urlBuf.data(), job);
            
        // 同步请求，不考虑wkeNetHoldJobToAsynCommit
        if (job->m_asynWkeNetSetData && kNormalCancelled != job->m_cancelledReason) {
            size_t size = job->m_asynWkeNetSetData->size();
            if (job->firstRequest()->downloadToFile() && size > 0) {
                String tempPath = handleHeaderForBlobOnMainThread(job, size);
                job->m_response.setDownloadFilePath(tempPath);
            }
            job->m_response.setURL(url);
            job->m_response.setHTTPStatusCode(200);
            job->m_response.setHTTPStatusText(blink::WebString::fromUTF8("OK"));
            handleDidReceiveResponse(job);

            didReceiveDataOrDownload(job, job->m_asynWkeNetSetData->data(), job->m_asynWkeNetSetData->size(), 0);
            handleDidFinishLoading(job, WTF::currentTime(), 0);
            removeLiveJobs(jobId);
            delete job;
            return;
        }
    }
#endif

    // If defersLoading is true and we call curl_easy_perform
    // on a paused handle, libcURL would do the transfert anyway
    // and we would assert so force defersLoading to be false.
    job->m_defersLoading = false;
    job->m_ioThread->task_runner()->PostTask(FROM_HERE, base::BindOnce(&WebURLLoaderManager::initializeHandleOnIoThread, base::Unretained(this), jobId, info));

    SyncJob* syncJob = new SyncJob(job, jobId);
    job->m_ioThread->task_runner()->PostTask(
        FROM_HERE, base::BindOnce(&WebURLLoaderManager::dispatchSynchronousJobOnIoThread, base::Unretained(this), job, info, syncJob));
    while (!syncJob->isCallFinish) {
        if (terminateSyncLoadEvent && terminateSyncLoadEvent->IsSignaled()) {
            AutoLockJob autoLockJob(this, jobId);
            autoLockJob.lock();
            job->m_cancelledReason = kNormalCancelled;
            syncJob->ret = CURLE_FAILED_INIT;
            break;
        }
        ::Sleep(10);
    }

    for (size_t i = 0; i < job->m_syncTasks.size(); ++i) {
        WebURLLoaderManagerMainTask* task = job->m_syncTasks[i];
        if (!(terminateSyncLoadEvent && terminateSyncLoadEvent->IsSignaled()))
            task->run();
        delete task;
    }

    if (syncJob->ret != CURLE_OK) {
        if (job->client() && job->loader()) {
            blink::WebURLError error(net::ERR_ABORTED, (int)syncJob->ret, net::ResolveErrorInfo(), blink::WebURLError::HasCopyInCache::kFalse,
                blink::WebURLError::IsWebSecurityViolation::kFalse, blink::KURL(String(job->m_url)), blink::WebURLError::ShouldCollapseInitiator::kFalse);
            WebURLLoaderManager::sharedInstance()->handleDidFail(job, error);
        }
    } else {
        if (job->client() && job->loader())
            handleDidReceiveResponse(job);

// #if 0
//         void* hookBuf = job->m_hookBufForEndHook ? job->m_hookBufForEndHook->data() : nullptr;
//         int hookLength = job->m_hookBufForEndHook ? job->m_hookBufForEndHook->size() : 0;
// 
//         wkeLoadUrlEndCallback loadUrlEndCallback = page->wkeHandler().loadUrlEndCallback;
//         void* loadUrlEndCallbackParam = page->wkeHandler().loadUrlEndCallbackParam;
//         if (1 == job->m_isHookRequest && loadUrlEndCallback)
//             loadUrlEndCallback(page->wkeWebView(), loadUrlEndCallbackParam, urlBuf.data(), job, hookBuf, hookLength);
// 
//         if (job->m_hookBufForEndHook)
//             didReceiveDataOrDownload(job, static_cast<char*>(job->m_hookBufForEndHook->data()), hookLength, 0);
// #endif
//         handleDidFinishLoading(job, base::TimeTicks::Now().ToInternalValue(), 0);
    }

    syncJob->release();
}

void WebURLLoaderManager::dispatchSynchronousJobOnIoThread(WebURLLoaderInternal* job, InitializeHandleInfo* info, SyncJob* syncJob)
{
    CURL* handle = job->m_handle;
    // curl_easy_perform blocks until the transfert is finished.
    syncJob->ret = curl_easy_perform(handle);
    curl_easy_cleanup(handle);

    syncJob->isCallFinish = true;
    syncJob->release();
}

void onNetSetMIMEType(mbNetJob jobPtr, const char* type)
{
    //wke::checkThreadCallIsValid(__FUNCTION__);
    WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobPtr;
    job->m_response.SetMimeType(blink::WebString::FromUTF8(type));
}

void onNetSetHTTPHeaderField(mbNetJob jobPtr, const utf8* key, const utf8* value, BOOL response)
{
    WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobPtr;
    if (response) {
        job->m_response.SetHttpHeaderField(String(key), String(value));
    } else {
//         WTF::String keyString(key);
//         if (equalIgnoringCase(keyString, "referer"))
//             job->firstRequest()->setHTTPReferrer(String(value), WebReferrerPolicyDefault);
//         else
//             job->firstRequest()->headers.SetHeader(keyString, String(value));
        job->firstRequest()->headers.SetHeader(std::string_view(key), value);

        if (job->m_initializeHandleInfo) { // setHttpResponseDataToJobWhenDidReceiveResponseOnMainThread里m_initializeHandleInfo为空
            curl_slist* headers = job->m_initializeHandleInfo->headers;
            curl_slist_free_all(headers);
            headers = nullptr;

            net::HttpRequestHeaders::Iterator it(job->firstRequest()->headers);
            bool next = true;
            for (; next; next = it.GetNext()) {
                std::string builder(it.name());
                builder += ":";
                builder += it.value();

                headers = curl_slist_append(headers, builder.c_str());
            }
            job->m_initializeHandleInfo->headers = headers;
        }
    }
}

void onNetSetHTTPHeaderFieldCommon(mbNetJob jobPtr, const utf8* key, const utf8* value, BOOL response)
{
    onNetSetHTTPHeaderField(jobPtr, key, value, response);
}

void changeRequestUrl(mbNetJob jobPtr, const char* url)
{
    WebURLLoaderInternal* job = (WebURLLoaderInternal*)jobPtr;
    blink::KURL newUrl(WTF::String::FromUTF8(url));
    job->m_response.SetCurrentRequestUrl(newUrl);
    job->firstRequest()->url = (GURL)(newUrl);
    //job->m_url = url;
    job->m_initializeHandleInfo->url = url;
    CHECK(job->m_url.empty());
}

void onNetSetData(mbNetJob jobPtr, void* buf, int len)
{
    if (0 == len) {
        len = 1;
        buf = (void*)" ";
    }

    mbnet::WebURLLoaderInternal* job = (mbnet::WebURLLoaderInternal*)jobPtr;
    mbnet::WebURLLoaderImplCurl* loader = job->loader();

    if (job->m_hookBufForEndHook) {
        job->m_hookBufForEndHook->resize(len);
        memcpy(job->m_hookBufForEndHook->data(), buf, len);
        return;
    }

    if (!job->m_asynWkeNetSetData)
        job->m_asynWkeNetSetData = new Vector<char>();
    job->m_asynWkeNetSetData->resize(len);
    memcpy(job->m_asynWkeNetSetData->data(), buf, len);

    job->m_isHoldJobToAsynCommit = false;
    job->m_isWkeNetSetDataBeSetted = true;
}

static bool dispatchWkeLoadUrlBegin(WebURLLoaderInternal* job, InitializeHandleInfo* info)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)job->m_mbwebviewId);
    if (!webview)
        return false;
    if (!webview->getClosure().m_LoadUrlBeginCallback)
        return false;

    void* param = webview->getClosure().m_LoadUrlBeginParam;

    job->m_isUrlBegining = true;
    webview->getClosure().m_LoadUrlBeginCallback(job->m_mbwebviewId, param, 
        /*job->firstRequest()->url.spec().c_str()*/job->m_url.c_str(), job);
    job->m_isUrlBegining = false;
    return job->m_isWkeNetSetDataBeSetted;
}

static void applyProxyToRequest(WebURLLoaderInternal* job, InitializeHandleInfo* info)
{
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)job->m_mbwebviewId);
    if (!webview || !webview->getProxy())
        return;
    const mbProxy* proxy = webview->getProxy();
    char buf[101] = { 0 };

    memcpy(buf, proxy->hostname, 100);
    std::string hostname = buf;

    memset(buf, 0, 101);
    memcpy(buf, proxy->username, 50);
    std::string username = buf;

    memset(buf, 0, 101);
    memcpy(buf, proxy->password, 50);
    std::string password = buf;

    std::string userPass;
    if (username.length() || password.length())
        userPass = username + ":" + password;

    info->proxy = hostname + ":" + base::NumberToString(proxy->port);
    info->proxyUserNamePassword = userPass;
    if (proxy->type == MB_PROXY_HTTP) {
        info->proxyType = kProxyTypeHTTP;
    } else if (proxy->type == MB_PROXY_SOCKS4) {
        info->proxyType = kProxyTypeSocks4;
    } else if (proxy->type == MB_PROXY_SOCKS5) {
        info->proxyType = kProxyTypeSocks5;
    } else if (proxy->type == MB_PROXY_SOCKS5HOSTNAME) {
        info->proxyType = kProxyTypeSocks5Hostname;
    }
}

void WebURLLoaderManager::applyAuthenticationToRequest(WebURLLoaderInternal* handle)
{
    // m_user/m_pass are credentials given manually, for instance, by the arguments passed to XMLHttpRequest.open().
    WebURLLoaderInternal* job = handle;

    std::string user = job->m_user;
    std::string password = job->m_pass;

    if (user.empty())
        return;

    //     if (!job->m_initialCredential.isEmpty()) {
    //         user = job->m_initialCredential.user();
    //         password = job->m_initialCredential.password();
    //         curl_easy_setopt(job->m_handle, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    //     }

    // It seems we need to set CURLOPT_USERPWD even if username and password is empty.
    // Otherwise cURL will not automatically continue with a new request after a 401 response.

    // curl CURLOPT_USERPWD expects username:password
    //std::string userpass = user + ":" + password;
    //curl_easy_setopt(job->m_handle, CURLOPT_USERPWD, userpass.c_str());
    //curl_easy_setopt(job->m_handle, CURLOPT_USERPWD, ":");
}

String getMIMETypeForPath(const String& path)
{
    int pos = path.ReverseFind('.');
    if (pos < 0)
        return "application/octet-stream";
    String extension = path.Substring(pos + 1);
    String mimeType = blink::MIMETypeRegistry::GetMIMETypeForExtension(extension);
    //     if (mimeType.empty()) {
    //         // If there's no mimetype registered for the extension, check to see
    //         // if a plugin can handle the extension.
    //         mimeType = GetPluginMimeTypeFromExtension(extension);
    //     }
    if (mimeType.empty())
        return "application/octet-stream";
    return mimeType;
}

static bool checkNeedFixMime(const blink::KURL& url)
{
    if (url.ProtocolIsJavaScript() || url.ProtocolIsInHTTPFamily() || url.IsAboutBlankURL() || url.IsAboutSrcdocURL())
        return false;
    return true;
}

InitializeHandleInfo* WebURLLoaderManager::preInitializeHandleOnMainThread(WebURLLoaderInternal* job)
{
    InitializeHandleInfo* info = new InitializeHandleInfo();

    if (job->firstRequest()->url.SchemeIsFile()) {
        info->url = job->firstRequest()->url.spec();
        size_t pos = info->url.find("?__base64__=");
        if (std::string::npos != pos) {
            std::string realPath = info->url.substr(pos + 12);
            if (!base::Base64Decode(std::string_view(realPath), &info->url)) {
                info->url = "";
            }
        }
    }

    blink::KURL url(job->firstRequest()->url);

    // Remove any fragment part, otherwise curl will send it as part of the request.
    url.RemoveFragmentIdentifier();
    String urlString = url.GetString();
    if (checkNeedFixMime(url)) {
        // Remove any query part sent to a local file.
        if (!url.Query().empty()) {
            // By setting the query to a null string it'll be removed.
            url.SetQuery(String());
            urlString = url.GetString();
        }

        size_t questionMaskPos = urlString.find('?');
        if (WTF::kNotFound != questionMaskPos)
            urlString = urlString.Substring(0, questionMaskPos);

        // Determine the MIME type based on the path.
        String mime = getMIMETypeForPath(urlString);
        job->m_response.SetMimeType(mime);
        job->m_response.AddHttpHeaderField(blink::WebString::FromASCII("Content-Type"), mime); // for ModuleScriptFetcher::WasModuleLoadSuccessful
    }

    WTF::StringUTF8Adaptor urlStringUtf8(urlString);
    if (info->url.empty())
        info->url = std::string(urlStringUtf8.data(), urlStringUtf8.size());
    info->method = job->firstRequest()->method;

    DCHECK(job->m_url.empty()); // url must remain valid through the request
    job->m_url = /*fastStrDup*/(info->url); // url is in ASCII so latin1() will only convert it to char* without character translation.

    //     String contentType = job->firstRequest()->headers.GetHeader("Content-Type");
    //     if (WTF::kNotFound != url.host().find("huobi.pro") && "POST" == info->method && job->firstRequest()->httpBody().isNull())
    //         job->firstRequest()->setHTTPHeaderField("Content-Type", ""); // 修复火币网登录不了的bug

    std::string range;
    std::optional<std::string> rangeOpt = job->firstRequest()->headers.GetHeader("Range");
    if (rangeOpt.has_value()) {
        range = rangeOpt.value();
        if (base::StartsWith(range, "bytes=", base::CompareCase::INSENSITIVE_ASCII)) {
            range = range.substr(sizeof("bytes=") - 1);
        }
    }
    info->range = range;

    curl_slist* headers = nullptr;

    //if (std::string::npos != info->url.find("r.m.jd.com/show?appid"))
    //    OutputDebugStringA("preInitializeHandleOnMainThread\n");

    if (job->firstRequest()->referrer.is_valid()) {
        GURL referrerUrl = job->firstRequest()->referrer;
        const std::string& referrerUrlStr = referrerUrl.spec();

        // blink会设置成"about:client"，但有些网站例如yiyan.baidu.com会拒绝访问
        if (referrerUrlStr != "about:client") { // third_party\blink\renderer\platform\weborigin\referrer.h
            std::string referrer = "Referer: ";
            referrer += referrerUrlStr;
            headers = curl_slist_append(headers, referrer.c_str());

            // 在以下情况中添加 Origin 请求标头：1,跨源请求。
            // 2,除 GET 和 HEAD 以外的同源请求（即它会被添加到同源的 POST、OPTIONS、PUT、PATCH 和 DELETE 请求中）。
            //std::string origin = "Origin: ";
            //origin += referrerUrl.scheme();
            //origin += "://";
            //origin += referrerUrl.host();
            //if (referrerUrl.has_port()) {
            //    origin += ":";
            //    origin += referrerUrl.port();
            //}
            //
            //headers = curl_slist_append(headers, origin.c_str());
        }
    }

    if (!job->firstRequest()->headers.IsEmpty()) {
        net::HttpRequestHeaders::Iterator it(job->firstRequest()->headers);
        while (it.GetNext()) {
            std::string key = it.name();
            std::string value = it.value();
            std::string headerString(key);
            if (value.empty()) {
                // Insert the ; to tell curl that this header has an empty value.
                headerString.append(";");
            } else {
                headerString.append(": ");
                headerString.append(value);
            }
            headers = curl_slist_append(headers, headerString.c_str());
        }
    }

    if ("GET" == info->method) {

    } else if ("POST" == info->method) {
        info->methodInfo = new SetupHttpMethodInfo();
        info->methodInfo->post = setupPostOnMainThread(job, &headers);
    } else if ("PUT" == info->method) {
        info->methodInfo = new SetupHttpMethodInfo();
        info->methodInfo->put = setupPutOnMainThread(job, &headers);
    } else if ("HEAD" == info->method) {

    } else {
        info->methodInfo = new SetupHttpMethodInfo();
        info->methodInfo->put = setupPutOnMainThread(job, &headers);
    }
    info->headers = headers;

    // Set proxy options if we have them.
    if (m_proxy.length()) {
        info->proxy = m_proxy.c_str();
        info->proxyType = m_proxyType;
    }

#if 0 //(defined ENABLE_WKE) && (ENABLE_WKE == 1)
    if (!requestExtraData) // 在退出时候js调用同步XHR请求，会导致ExtraData为0情况
        return info;

    WebPage* page = requestExtraData->page;
    if (!page->wkeWebView())
        return info;

    String wkeProxy = page->wkeWebView()->getProxy();
    if (0 != wkeProxy.length()) {
        info->proxy = wkeProxy.utf8().data();
        info->proxyType = page->wkeWebView()->getProxyType();
    }

    String wkeNetInterface = page->wkeWebView()->getNetInterface();
    if (0 != wkeNetInterface.length()) {
        info->wkeNetInterface = wkeNetInterface.utf8().data();
    }
    RefPtr<net::PageNetExtraData> pageNetExtraData = page->getPageNetExtraData();
    info->pageNetExtraData = pageNetExtraData;
#else
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(job->m_mbwebviewId);
    if (webview)
        info->pageNetExtraData = webview->getPageNetExtraData();

    applyProxyToRequest(job, info);
#endif

    return info;
}

extern "C" CURLcode curl_ssl_cert_verify(CURL* curl, void* sslctx, void* parm);

void setCookiePath(CURL* handle, std::string cookieJarPath);

static int debugCallback(CURL* handle, curl_infotype type, char* data, size_t size, void* clientp)
{
//     int jobId = (int)clientp;
//     AutoLockJob autoLockJob(WebURLLoaderManager::sharedInstance(), jobId);
//     WebURLLoaderInternal* job = autoLockJob.lock();
//     if (!job || job->isCancelled())
//         return 0;
// 
//     if (std::string::npos != job->m_url.find("api.m.jd.com/?h5st=")) 
//     {
//         std::string output(data, size);
//         output.insert(0, "debugCallback:[");
//         output += "]\n";
//         OutputDebugStringA(output.c_str());
//     }

    return 0;
}

void WebURLLoaderManager::initializeHandleOnIoThread(int jobId, InitializeHandleInfo* info)
{
    AutoLockJob autoLockJob(this, jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job)
        return;
    job->m_handle = curl_easy_init();

    if (job->m_defersLoading) {
        CURLcode error = curl_easy_pause(job->m_handle, CURLPAUSE_ALL);
        // If we did not pause the handle, we would DCHECK in the
        // header callback. So just assert here.
        DCHECK(/*error,*/ error == CURLE_OK);
    }
    curl_easy_setopt(job->m_handle, CURLOPT_VERBOSE, 1);
    // 请求从开始到完结的时间。如果请求不停有数据来，超过这个时间也被认为是超时。时间是60 * 10 = 10分钟
    curl_easy_setopt(job->m_handle, CURLOPT_TIMEOUT, 60 * 1);
    curl_easy_setopt(job->m_handle, CURLOPT_CONNECTTIMEOUT, 30);
    curl_easy_setopt(job->m_handle, CURLOPT_SSL_VERIFYPEER, false); // ignoreSSLErrors
    curl_easy_setopt(job->m_handle, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_easy_setopt(job->m_handle, CURLOPT_PRIVATE, jobId);
    curl_easy_setopt(job->m_handle, CURLOPT_ERRORBUFFER, m_curlErrorBuffer);
    curl_easy_setopt(job->m_handle, CURLOPT_WRITEFUNCTION, writeCallbackOnIoThread);
    curl_easy_setopt(job->m_handle, CURLOPT_WRITEDATA, jobId);
    curl_easy_setopt(job->m_handle, CURLOPT_HEADERFUNCTION, headerCallbackOnIoThread);
    curl_easy_setopt(job->m_handle, CURLOPT_FORBID_REUSE, 1);
    curl_easy_setopt(job->m_handle, CURLOPT_FRESH_CONNECT, 1);
    curl_easy_setopt(job->m_handle, CURLOPT_DEBUGFUNCTION, debugCallback);
    curl_easy_setopt(job->m_handle, CURLOPT_DEBUGDATA, jobId);
    curl_easy_setopt(job->m_handle, CURLOPT_WRITEHEADER, jobId);
    curl_easy_setopt(job->m_handle, CURLOPT_AUTOREFERER, 1);
    curl_easy_setopt(job->m_handle, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(job->m_handle, CURLOPT_MAXREDIRS, 30);
    curl_easy_setopt(job->m_handle, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
    curl_easy_setopt(job->m_handle, CURLOPT_BUFFERSIZE, 32768); // 32KB of FFmpeg

    if (!info->range.empty()) {
        curl_easy_setopt(job->m_handle, CURLOPT_RANGE, info->range.c_str());
    }

#if ENABLE_WKE
    if (wke::g_DNS)
        curl_easy_setopt(job->m_handle, CURLOPT_DNS_SERVERS, wke::g_DNS->c_str());
#endif
    if (info->pageNetExtraData && info->pageNetExtraData->getCurlShareHandle()) {
        curl_easy_setopt(job->m_handle, CURLOPT_SHARE, info->pageNetExtraData->getCurlShareHandle());
        job->m_pageNetExtraData = info->pageNetExtraData;
    } else
        curl_easy_setopt(job->m_handle, CURLOPT_SHARE, m_shareCookieJar->getCurlShareHandle());
    curl_easy_setopt(job->m_handle, CURLOPT_DNS_CACHE_TIMEOUT, 60 * 5); // 5 minutes
    curl_easy_setopt(job->m_handle, CURLOPT_PROTOCOLS, kAllowedProtocols);
    curl_easy_setopt(job->m_handle, CURLOPT_REDIR_PROTOCOLS, kAllowedProtocols);

    //curl_easy_setopt(job->m_handle, CURLOPT_HTTPPROXYTUNNEL, true); // TODO

    if (!m_certificatePath.empty())
        curl_easy_setopt(job->m_handle, CURLOPT_CAINFO, m_certificatePath.data());

    curl_easy_setopt(job->m_handle, CURLOPT_ENCODING, ""); // enable gzip and deflate through Accept-Encoding:

    DCHECK(job->m_url.empty() || job->m_url == info->url); // url must remain valid through the request
    //job->m_url = /*fastStrDup*/ (info->url); // url is in ASCII so latin1() will only convert it to char* without character translation.

    curl_easy_setopt(job->m_handle, CURLOPT_URL, job->m_url.c_str());

    if (job->m_url.find("api.m.jd.com") != std::string::npos) // 京东某些链接要强制TLSv1.2才能访问，不知道为啥
        curl_easy_setopt(job->m_handle, CURLOPT_SSLVERSION, CURL_SSLVERSION_TLSv1_2 | CURL_SSLVERSION_MAX_TLSv1_2);

    {
        // 这里必须对每个job都设置cookie路径，否则curl会认为这个job->m_handle不需要cookie
        WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
        WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

        std::string cookieJarFullPath;

        if (job->m_pageNetExtraData) {
            cookieJarFullPath = job->m_pageNetExtraData->getCookieJarFullPath();
        } else
            cookieJarFullPath = m_shareCookieJar->getCookieJarFullPath();

        setCookiePath(job->m_handle, cookieJarFullPath);
    }

    if ("GET" == info->method) {
        curl_easy_setopt(job->m_handle, CURLOPT_HTTPGET, TRUE);
    } else if ("POST" == info->method) {
        setupPostOrPutOnIoThread(job, true, info->methodInfo->post ? info->methodInfo->post->data : nullptr);
    } else if ("PUT" == info->method) {
        setupPostOrPutOnIoThread(job, false, info->methodInfo->put ? info->methodInfo->put->data : nullptr);
    } else if ("HEAD" == info->method) {
        curl_easy_setopt(job->m_handle, CURLOPT_NOBODY, TRUE);
    } else if ("OPTIONS" == info->method) {
        curl_easy_setopt(job->m_handle, CURLOPT_CUSTOMREQUEST, "OPTIONS");
    } else {
        curl_easy_setopt(job->m_handle, CURLOPT_CUSTOMREQUEST, info->method.c_str());
        setupPutOnIoThread(job, info->methodInfo->put);
    }

    //     if (false && job->m_url == "https://m.ctrip.com/restapi/soa2/12216/json/queryFormatNum") {
    //         OutputDebugStringA("setupPostOrPutOnIoThread\n");

    //         curl_slist* headers = info->headers;
    //         while (headers) {
    //             OutputDebugStringA(headers->data);
    //             OutputDebugStringA("\n");
    //             headers = headers->next;
    //         }

    //         curl_slist_free_all(info->headers);
    //         info->headers = nullptr;

    //         info->headers = curl_slist_append(info->headers, "Accept: */*");
    //         info->headers = curl_slist_append(info->headers, "Accept-Encoding: gzip, deflate, br");
    //         info->headers = curl_slist_append(info->headers, "Accept-Language: zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6,ja;q=0.5");
    //         info->headers = curl_slist_append(info->headers, "Content-Length: 160");
    //         info->headers = curl_slist_append(info->headers, "content-type: application/json");
    //         info->headers = curl_slist_append(info->headers, "Referer: https://vacations.ctrip.com/");
    //         info->headers = curl_slist_append(info->headers, "Origin: https://vacations.ctrip.com/");
    //         info->headers = curl_slist_append(info->headers, "Priority: u=1, i");
    //         //info->headers = curl_slist_append(info->headers, "sec-ch-ua: \"Not\\ / A)Brand\";v=\"92\", \"Chromium\";v=\"108\", \"Google Chrome\";v=\"108\"");
    //         info->headers = curl_slist_append(info->headers, "sec-ch-ua-mobile: ?0");
    //         info->headers = curl_slist_append(info->headers, "sec-ch-ua-platform: \"Windows\"");
    //         info->headers = curl_slist_append(info->headers, "Upgrade-Insecure-Requests: 1");
    //         info->headers = curl_slist_append(info->headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36");
    //         //info->headers = curl_slist_append(info->headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0");
    //         //info->headers = curl_slist_append(info->headers, "CookieOrigin: https://vacations.ctrip.com");
    //         //info->headers = curl_slist_append(info->headers, "Connection: keep-alive");
    //         info->headers = curl_slist_append(info->headers, "Sec-Fetch-Dest: empty");
    //         info->headers = curl_slist_append(info->headers, "Sec-Fetch-Mode: cors");
    //         info->headers = curl_slist_append(info->headers, "Sec-Fetch-Site: same-site");
    //         info->headers = curl_slist_append(info->headers, "Expect:");
    //-----

    //         info->headers = curl_slist_append(info->headers, "Accept: */*");
    //         info->headers = curl_slist_append(info->headers, "Accept-Encoding: gzip, deflate, br");
    //         info->headers = curl_slist_append(info->headers, "Accept-Language: zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6,ja;q=0.5");
    //         info->headers = curl_slist_append(info->headers, "Content-Length: 160");
    //         info->headers = curl_slist_append(info->headers, "Content-Type: application/json");
    //         info->headers = curl_slist_append(info->headers, "Cookieorigin: https://vacations.ctrip.com");
    //         info->headers = curl_slist_append(info->headers, "Cookie: ibulanguage = CN; ibulocale = zh_cn; cookiePricesDisplayed = CNY");
    //         info->headers = curl_slist_append(info->headers, "Origin: https://vacations.ctrip.com");
    //         info->headers = curl_slist_append(info->headers, "Priority: u=1, i");
    //         info->headers = curl_slist_append(info->headers, "Referer: https://vacations.ctrip.com/");
    //         info->headers = curl_slist_append(info->headers, "sec-ch-ua-mobile: ?0");
    //         info->headers = curl_slist_append(info->headers, "Sec-Ch-Ua-Platform: \"Windows\"");
    //         info->headers = curl_slist_append(info->headers, "Sec-Fetch-Dest: empty");
    //         info->headers = curl_slist_append(info->headers, "Sec-Fetch-Mode: cors");
    //         info->headers = curl_slist_append(info->headers, "Sec-Fetch-Site: same-site");
    //         info->headers = curl_slist_append(info->headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0");
    //
    //     }

    if (info->headers) {
        curl_easy_setopt(job->m_handle, CURLOPT_HTTPHEADER, info->headers);
        job->m_customHeaders = info->headers;
#if ENABLE_WKE == 1
        CHECK(!job->m_asynWkeNetSetData);
#endif
    }

    //applyAuthenticationToRequest(job);

    if (info->proxy.size()) {
        job->m_isProxy = true;
        curl_easy_setopt(job->m_handle, CURLOPT_PROXY, info->proxy.c_str()); // "161.77.0.109:50100"
        curl_easy_setopt(job->m_handle, CURLOPT_PROXYTYPE, info->proxyType);
        curl_easy_setopt(job->m_handle, CURLOPT_PROXYUSERPWD, info->proxyUserNamePassword.c_str()); // "ipProxy:BarZEkqTn"
        curl_easy_setopt(job->m_handle, CURLOPT_PROXYAUTH, CURLAUTH_ANY);
    }
    //
    //     if (info->wkeNetInterface.size())
    //         curl_easy_setopt(job->m_handle, CURLOPT_INTERFACE, info->wkeNetInterface.c_str());

    // CURLOPT_SSL_VERIFYPEER： cURL 是否验证对等证书（peer's certificate），值为 1，则验证，为 0 则不验证。要验证的交换证书可以在 CURLOPT_CAINFO 选项中设置，或在 CURLOPT_CAPATH中设置证书目录。
    // CURLOPT_SSL_VERIFYHOST：值为1 ： cURL 检查服务器SSL证书中是否存在一个公用名(common name)；值为2： cURL 会检查公用名是否存在，并且是否与提供的主机名匹配；0 为不检查名称。这里的 common name 是在创建证书过程中指定，例如 subj 选项值中的 / CN 值； openssl req - subj "/C=CN/ST=IL/L=ShenZhen/O=Tencent/OU=Tencent/CN=luffichen_server.tencent.com/emailAddress=luffichen@www.tencent.com" ...
    // CURLOPT_CAINFO：一个保存着1个或多个用来让服务端验证的证书的文件名。这个参数仅仅在和CURLOPT_SSL_VERIFYPEER一起使用时才有意义。
    // CURLOPT_CAPATH：一个保存着多个CA证书的目录。这个选项是和CURLOPT_SSL_VERIFYPEER一起使用的。
    // 与 SSL 双向认证相关的 curl_easy_setopt 选项有以下几个：
    //
    // CURLOPT_SSLCERT：客户端证书路径
    // CURLOPT_SSLCERTTYPE：证书的类型。支持的格式有"PEM" (默认值), "DER"和"ENG"。
    // CURLOPT_SSLKEY：客户端私钥的文件路径
    // CURLOPT_SSLKEYTYPE：客户端私钥类型，支持的私钥类型为"PEM"(默认值)、"DER"和"ENG"。
    // CURLOPT_KEYPASSWD：客户端私钥密码，私钥在创建时可以选择加密。
    // 见curl_ssl_cert_verify

    //     curl_easy_setopt(job->m_handle, CURLOPT_CAINFO, NULL);
    //     curl_easy_setopt(job->m_handle, CURLOPT_CAPATH, NULL);
    //
    //     curl_easy_setopt(job->m_handle, CURLOPT_SSL_CTX_FUNCTION, curl_ssl_cert_verify);
    //     curl_easy_setopt(job->m_handle, CURLOPT_SSLCERTTYPE, "PEM");
    //
    //     curl_easy_setopt(job->m_handle, CURLOPT_SSL_VERIFYPEER, 1L);
    //     curl_easy_setopt(job->m_handle, CURLOPT_SSL_VERIFYHOST, 2L);

#if ENABLE_WKE == 1
    if (wke::g_curlSetoptCallback)
        wke::g_curlSetoptCallback(job->m_handle, wke::curlSetopt);
#endif
    job->m_initializeHandleInfo = nullptr;
    delete info;
}

void WebURLLoaderManager::timeoutOnMainThread(int jobId)
{
    AutoLockJob autoLockJob(this, jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job)
        return;

    GURL kUrl = job->firstRequest()->url;
    std::string url = kUrl.possibly_invalid_spec();
    url += "\n";
    OutputDebugStringA(url.c_str());

    BlackListCancelTask::cancel(this, job, kBlackListCancelJobId);
    cancel(jobId);
}

int WebURLLoaderManager::initializeHandleOnMainThread(WebURLLoaderInternal* job)
{
    int jobId = addLiveJobs(job);

    GURL gurl = job->firstRequest()->url;
    if (gurl.SchemeIsFile())
        job->decodeUrlRequest();
    InitializeHandleInfo* info = preInitializeHandleOnMainThread(job);
    job->m_initializeHandleInfo = info;

    bool needDeleteInfo = false;
#if 1 // ENABLE_WKE == 1
    // 不再区分返回值，而是根据各种bool变量来判断未来是否需要继续网络层工作。
    dispatchWkeLoadUrlBegin(job, info);

    if (job->m_isWkeNetSetDataBeSetted) {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce(&HookAsynTask::run, base::Unretained(new HookAsynTask(this, jobId))));

        CHECK(!job->m_isHoldJobToAsynCommit);
        job->m_initializeHandleInfo = nullptr;
        needDeleteInfo = true;
    }
#endif

    blink::KURL kurl(gurl);

#if 1 // ENABLE_WKE == 1
    bool needFastCheckLocalFilePath = !job->m_isWkeNetSetDataBeSetted && !job->m_isHoldJobToAsynCommit;
    if (needFastCheckLocalFilePath && kurl.IsLocalFile() && isLocalFileNotExist(info->url.c_str(), job) || job->m_isWkeCanceled) {
        m_mainThreadRunner->PostTask(FROM_HERE, base::BindOnce(&BlackListCancelTask::run, base::Unretained(new BlackListCancelTask(this, jobId))));
        needDeleteInfo = true;
    }
#endif

    WTF::StringUTF8Adaptor utf8Adaptor(kurl.FragmentIdentifier());
    String fragment(base::span<const char>(utf8Adaptor.data(), utf8Adaptor.size()));
    job->m_fragment = std::string((const char*)fragment.Characters8(), fragment.length());

    if (needDeleteInfo)
        delete info;
    return jobId;
}

void WebURLLoaderManager::startOnIoThread(int jobId)
{
    AutoLockJob autoLockJob(this, jobId);
    WebURLLoaderInternal* job = autoLockJob.lock();
    if (!job)
        return;

    //Platform::current()->mainThread()->postDelayedTask(FROM_HERE, WTF::bind(&WebURLLoaderManager::timeoutOnMainThread, this, jobId), 5000);

    m_runningJobs++;
    CURLMcode ret = curl_multi_add_handle(getCurrentThreadCurlMultiHandle(), job->m_handle);
    // don't call perform, because events must be async
    // timeout will occur and do curl_multi_perform
    if (ret && ret != CURLM_CALL_MULTI_PERFORM) {
#ifndef NDEBUG
        //         WTF::String outstr = String::format("Error %job starting job %s\n", ret, encodeWithURLEscapeSequences(job->firstRequest()->url().string()).latin1().data());
        //         OutputDebugStringW(outstr.charactersWithNullTermination().data());
#endif
        WTF::Locker<WTF::RecursiveMutex> locker(*(job->m_destroingMutex.get()));
        job->m_cancelledReason = kNormalCancelled;
        removeFromCurlOnIoThread(jobId);

        curl_easy_setopt(job->m_handle, CURLOPT_PRIVATE, nullptr);
        curl_easy_setopt(job->m_handle, CURLOPT_ERRORBUFFER, nullptr);
        curl_easy_setopt(job->m_handle, CURLOPT_WRITEDATA, nullptr);
        curl_easy_setopt(job->m_handle, CURLOPT_WRITEHEADER, nullptr);
        curl_easy_setopt(job->m_handle, CURLOPT_SHARE, nullptr);
    }
}

InitializeHandleInfo::~InitializeHandleInfo()
{
    if (methodInfo) {
        delete methodInfo;
    }
}

#ifndef NDEBUG
//DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, webURLLoaderInternalCounter, ("WebURLLoaderInternal"));
#endif

WebURLLoaderInternal::WebURLLoaderInternal(base::Thread* ioThread, WebURLLoaderImplCurl* loader, std::unique_ptr<network::ResourceRequest> request,
    blink::URLLoaderClient* client, bool defersLoading, bool shouldContentSniff)
    : m_isSynchronous(false)
    , m_client(client)
    , m_lastHTTPMethod(request->method)
    , m_status(0)
    , m_defersLoading(defersLoading)
    , m_shouldContentSniff(shouldContentSniff)
    , m_responseFired(false)
    , m_handle(0)
    //, m_url()
    , m_customHeaders(0)
    , m_cancelledReason(kNoCancelled)
    //, m_formDataStream(loader)
    , m_scheduledFailureType(NoFailure)
    , m_loader(loader)
    , m_state(kNormal)
#if 1 // ENABLE_WKE == 1
    , m_hookBufForEndHook(nullptr)
    , m_isHookRequest(false)
    , m_asynWkeNetSetData(nullptr)
    , m_isWkeNetSetDataBeSetted(false)
#endif
//, m_bodyStreamWriter(nullptr)
{
    m_ref = 0;
    m_id = 0;
    m_mbwebviewId = 0;
    m_type = kLoaderInternal;
    m_firstRequest.reset(request.release());
    GURL url = m_firstRequest->url;
    m_user = url.username();
    m_pass = url.password();

    m_destroingMutex = std::make_unique<WTF::RecursiveMutex>();

    //m_response.initialize();

    m_dataLength = 0;
    m_isBlackList = false;
    m_isDataUrl = false;
    m_isProxy = false;
    m_isProxyHeadRequest = false;
    m_isProxyConnect = false;
#if 1 // ENABLE_WKE == 1
    m_isWkeCanceled = false;
    //m_formDataStream = nullptr;
#endif
    m_isHoldJobToAsynCommit = false;
    m_isRedirection = false;
    m_initializeHandleInfo = nullptr;
    m_needParseMime = true;
    m_sentDataBytes = 0;
    m_totalBytesToBeSent = 0;

    m_hasCallResponse = false;
    m_cacheForDownloadOpt = kCacheForDownloadUnknow;

    m_taskRunner = base::SequencedTaskRunner::GetCurrentDefault();
    m_ioThread = ioThread;

    // 如果当前线程和主线程不同，一般是同步请求。但和web worker的同步请求又不一样。
    m_isCrossThread = m_taskRunner != WebURLLoaderManager::sharedInstance()->getMainRunner();

#ifndef NDEBUG
    //`webURLLoaderInternalCounter.increment();
#endif
}

WebURLLoaderInternal::~WebURLLoaderInternal()
{
    m_state = kDestroyed;

#if 1 // ENABLE_WKE == 1
    if (m_hookBufForEndHook)
        delete m_hookBufForEndHook;

    if (m_asynWkeNetSetData) {
        CHECK(!m_customHeaders);
        delete m_asynWkeNetSetData;
    }
#endif

    //delete m_firstRequest;
    //fastFree(m_url);

    if (m_customHeaders)
        curl_slist_free_all(m_customHeaders);

#if 0
    if (m_bodyStreamWriter) {
        delete m_bodyStreamWriter;
        m_bodyStreamWriter = nullptr;
    }

    if (m_formDataStream)
        delete m_formDataStream;

    if (m_dataBind)
        delete m_dataBind;
#endif

#ifndef NDEBUG
        //webURLLoaderInternalCounter.decrement();
#endif
    //CHECK(!m_destroingMutex.get());
}

void WebURLLoaderInternal::decodeUrlRequest()
{
//     GURL gurl = m_firstRequest->url;
//     const std::string& url = gurl.spec();
//     WTF::String newUrl = blink::DecodeURLEscapeSequences(WTF::String(base::span<const char>(url.c_str(), url.size())), blink::DecodeURLMode::kUTF8);
//     m_firstRequest->url = GURL(newUrl.Utf8());
}

void WebURLLoaderInternal::resetFirstRequest(std::unique_ptr<network::ResourceRequest>&& newRequest)
{
    CHECK(/*WTF::IsMainThread() &&*/ m_firstRequest);
    m_firstRequest = std::move(newRequest);
}

} // namespace net
;