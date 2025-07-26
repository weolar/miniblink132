
#include "mbnet/WebURLLoaderImplCurl.h"

#include "mbnet/WebURLLoaderInternal.h"
#include "mbnet/WebURLRequestExtraDataWrap.h"
#include "mbnet/WebURLLoaderManager.h"
#include "mbnet/BlobResourceLoader.h"
#include "content/renderer/BlobURLStoreImpl.h"

#include "third_party/blink/public/platform/web_url_request_extra_data.h"
#include "third_party/blink/public/platform/resource_load_info_notifier_wrapper.h"
#include "third_party/blink/public/platform/web_data.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "services/network/public/cpp/resource_request.h"
#include "base/strings/string_util.h"
#include "base/task/sequenced_task_runner.h"
#include <windows.h>

#ifndef NDEBUG
//DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, webURLLoaderImplCurlCount, ("WebURLLoaderImplCurl"));
#endif

namespace mbnet {

class BlinkSynchronousLoader : public blink::URLLoaderClient {
public:
    BlinkSynchronousLoader(absl::optional<blink::WebURLError>&, blink::WebURLResponse&, std::vector<char>*);
    ~BlinkSynchronousLoader();

    void DidReceiveResponse(const blink::WebURLResponse& response,
        absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer>, std::optional<mojo_base::BigBuffer> cached_metadata) override;
    void DidReceiveDataForTesting(base::span<const char> data) override;
    void DidFinishLoading(base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length, int64_t total_decoded_body_length) override;
    void DidFail(const blink::WebURLError&, base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length,
        int64_t total_decoded_body_length) override;

    //void DidStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle responseBodyConsumer) override;
private:
    std::optional<blink::WebURLError>& m_error;
    blink::WebURLResponse& m_response;
    std::vector<char>* m_data;
};

BlinkSynchronousLoader::BlinkSynchronousLoader(absl::optional<blink::WebURLError>& error, blink::WebURLResponse& response, std::vector<char>* data)
    : m_error(error)
    , m_response(response)
    , m_data(data)
{
}

BlinkSynchronousLoader::~BlinkSynchronousLoader()
{
}

void BlinkSynchronousLoader::DidReceiveResponse(
    const blink::WebURLResponse& response,
    absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer>, 
    std::optional<mojo_base::BigBuffer> cached_metadata)
{
    m_response = response;
}

void BlinkSynchronousLoader::DidReceiveDataForTesting(base::span<const char> data)
{
    m_data->insert(m_data->end(), data.data(), data.data() + data.size());
}

void BlinkSynchronousLoader::DidFinishLoading(base::TimeTicks finishTime, 
    int64_t totalEncodedDataLength, uint64_t totalEncodedBodyLength, int64_t totalDecodedBodyLength)
{

}

void BlinkSynchronousLoader::DidFail(const blink::WebURLError& error, base::TimeTicks finishTime, int64_t totalEncodedDataLength, uint64_t totalEncodedBodyLength,
    int64_t totalDecodedBodyLength)
{
    m_error = error;
}

//------

WebURLLoaderImplCurl::WebURLLoaderImplCurl(
    scoped_refptr<base::SingleThreadTaskRunner> freezableTaskRunnerHandle, 
    scoped_refptr<base::SingleThreadTaskRunner> unfreezableTaskRunnerHandle, 
    base::WaitableEvent* terminateSyncLoadEvent,
    int64_t mbwebviewId)
    : m_freezableTaskRunner(std::move(freezableTaskRunnerHandle))
    , m_unfreezableTaskRunner(std::move(unfreezableTaskRunnerHandle))
    , m_terminateSyncLoadEvent(terminateSyncLoadEvent)
    , m_mbwebviewId(mbwebviewId)
{
    CHECK(m_mbwebviewId > 0);
    m_jobId = -1;
#ifndef NDEBUG
    //webURLLoaderImplCurlCount.increment();
#endif
    const scoped_refptr<base::SingleThreadTaskRunner> currentRunner = base::SingleThreadTaskRunner::GetCurrentDefault();
    scoped_refptr<base::SingleThreadTaskRunner> runner = m_freezableTaskRunner;
    if (runner->BelongsToCurrentThread())
        m_freezableTaskRunner = currentRunner; // 有时候就算runner是本线程的，但和ThreadTaskRunnerHandle::Get还不是同一个实例
    else
        m_freezableTaskRunner = runner;
}

WebURLLoaderImplCurl::~WebURLLoaderImplCurl()
{
#ifndef NDEBUG
    //webURLLoaderImplCurlCount.decrement();
#endif

    mbnet::WebURLLoaderManager* mgr = mbnet::WebURLLoaderManager::sharedInstance();
    if (!mgr)
        return;
    if (m_isAutoDestroy)
        mgr->cancel(m_jobId);
}

void WebURLLoaderImplCurl::init()
{
    m_hadDestroied = nullptr;
    m_jobId = 0;
}

static bool shouldContentSniffURL(const GURL& url)
{
    // We shouldn't content sniff file URLs as their MIME type should be established via their extension.
    return !url.SchemeIs("file");
}

static bool checkIsResURL(const GURL& url)
{
    std::string urlStr = url.possibly_invalid_spec();
    urlStr = base::ToLowerASCII(urlStr);

    if (std::string::npos != urlStr.find("jpg") || std::string::npos != urlStr.find("gif") || std::string::npos != urlStr.find("bmp")
        || std::string::npos != urlStr.find("png") || std::string::npos != urlStr.find("mp3") || std::string::npos != urlStr.find("mp4"))
        return true;
    return false;
}

// 本函数一般是在web worker的xhr里调用
void WebURLLoaderImplCurl::LoadAsynchronously(
    std::unique_ptr<network::ResourceRequest> request, 
    scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
    bool noMimeSniffing, 
    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper,
    blink::CodeCacheHost* codeCacheHost,
    blink::URLLoaderClient* client
    )
{
    mbnet::WebURLLoaderManager* netManager = mbnet::WebURLLoaderManager::sharedInstance();
    //WebURLRequestExtraDataWrap* extraDataWrap = (WebURLRequestExtraDataWrap*)extraData.get();
    if (!netManager) {
        //MojoClose(extraDataWrap->dataPipeProducerHandle);
        return;
    }

    init();

    GURL url = request->url;
    mbnet::WebURLLoaderManager::IoThreadType type = checkIsResURL(url) ? mbnet::WebURLLoaderManager::kIoThreadTypeRes : mbnet::WebURLLoaderManager::kIoThreadTypeOther;

    int64_t mbwebviewId = m_mbwebviewId;//extraDataWrap->mbwebviewId;
    if (url.SchemeIs("blob") /*&& !extraDataWrap->isDownload()*/) {
        ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(url.possibly_invalid_spec());
        if (!blob)
            return;

        m_blobLoader = mbnet::BlobResourceLoader::createAsync(mbwebviewId, url, client);
        m_blobLoader->start();
        return;
    }

    WebURLLoaderInternal* job = new WebURLLoaderInternal(netManager->getIoThread(type), this, std::move(request), client, false, shouldContentSniffURL(url));
    job->m_mbwebviewId = mbwebviewId;
    //job->m_dataPipeProducerHandle = extraDataWrap->dataPipeProducerHandle;
    job->m_frameType = blink::mojom::RequestContextFrameType::kTopLevel;//extraDataWrap->frameType;
    //job->m_downloadName = extraDataWrap->releaseDownloadName();

    int jobIds = 0;
    jobIds = netManager->addAsynchronousJob(job);
    if (0 == jobIds)
        return;
    m_jobId = jobIds;
    job->m_jobId = m_jobId;

    // 执行完add后，this可能被销毁，当dataurl的时候
#if 0
//     blink::KURL url = (blink::KURL)requestNew.url();
//     Vector<UChar> host = WTF::ensureUTF16UChar(url.host());
// 
//     if (!url.isValid() || !url.protocolIsData()) {
//         WTF::String outstr = String::format("WebURLLoaderImpl.loadAsynchronously: %p %ws\n", this, WTF::ensureUTF16UChar(url.string()).data());
//         OutputDebugStringW(outstr.charactersWithNullTermination().data());
//     }
#endif
}

// 本函数也是在web worker的xhr里调用
void WebURLLoaderImplCurl::LoadSynchronously(
    std::unique_ptr<network::ResourceRequest> request,
    scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
    bool downloadToBlob, 
    bool noMimeSniffing, 
    base::TimeDelta timeoutInterval, 
    blink::URLLoaderClient* client, 
    blink::WebURLResponse& response,
    std::optional<blink::WebURLError>& error,
    scoped_refptr<WTF::SharedBuffer>& data, 
    int64_t& encodedDataLength, 
    uint64_t& encodedBodyLength,
    scoped_refptr<blink::BlobDataHandle>& downloadedBlob, 
    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper)
{
    if (!mbnet::WebURLLoaderManager::sharedInstance())
        return;

    init();

    GURL url = request->url;
    if (url.SchemeIs("blob")) {
        //         ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(url.possibly_invalid_spec());
        //         if (!blob)
        //             return;
        //
        //         m_blobLoader = mbnet::BlobResourceLoader::createAsync(url, client);
        //         m_blobLoader->start();
        DebugBreak();
        return;
    }

    mbnet::WebURLLoaderManager* netManager = mbnet::WebURLLoaderManager::sharedInstance();
    mbnet::WebURLLoaderManager::IoThreadType type = mbnet::WebURLLoaderManager::kIoThreadTypeSync;
    // checkIsResURL(url) ? mbnet::WebURLLoaderManager::kIoThreadTypeRes : mbnet::WebURLLoaderManager::kIoThreadTypeOther;

    std::vector<char> buffer;
    mbnet::BlinkSynchronousLoader syncLoader(error, response, &buffer);
    mbnet::WebURLLoaderInternal* job
        = new mbnet::WebURLLoaderInternal(netManager->getIoThread(type), this, std::move(request), &syncLoader, false, shouldContentSniffURL(url));
    netManager->dispatchSynchronousJob(job, m_terminateSyncLoadEvent);
    data = WTF::SharedBuffer::Create(base::span<const unsigned char>((const unsigned char*)buffer.data(), buffer.size()));
    memset(buffer.data(), 0, buffer.size());
}

void WebURLLoaderImplCurl::LoadAsynchronouslyEx(
    std::unique_ptr<network::ResourceRequest> request,
    scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
    bool noMimeSniffing, 
    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper,
    blink::CodeCacheHost* codeCacheHost,
    scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData,
    blink::URLLoaderClient* client)
{
    mbnet::WebURLLoaderManager* netManager = mbnet::WebURLLoaderManager::sharedInstance();
    WebURLRequestExtraDataWrap* extraDataWrap = (WebURLRequestExtraDataWrap*)extraData.get();
    if (!netManager) {
        MojoClose(extraDataWrap->dataPipeProducerHandle);
        return;
    }

    init();

    GURL url = request->url;
    mbnet::WebURLLoaderManager::IoThreadType type
        = checkIsResURL(url) ? mbnet::WebURLLoaderManager::kIoThreadTypeRes : mbnet::WebURLLoaderManager::kIoThreadTypeOther;

    int64_t mbwebviewId = extraDataWrap->mbwebviewId;
    if (url.SchemeIs("blob") && !extraDataWrap->isDownload()) {
        ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(url.possibly_invalid_spec());
        if (!blob)
            return;

        m_blobLoader = mbnet::BlobResourceLoader::createAsync(mbwebviewId, url, client);
        m_blobLoader->start();
        return;
    }

    WebURLLoaderInternal* job = new WebURLLoaderInternal(netManager->getIoThread(type), this, std::move(request), client, false, shouldContentSniffURL(url));
    job->m_mbwebviewId = mbwebviewId;
    job->m_dataPipeProducerHandle = extraDataWrap->dataPipeProducerHandle;
    job->m_frameType = extraDataWrap->frameType;
    job->m_downloadName = extraDataWrap->releaseDownloadName();

    int jobIds = 0;
    //     if (WTF::IsMainThread()) {
    //         jobIds = netManager->addAsynchronousJob(job);
    //     } else {
    //         content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [] {
    //
    //         });
    //     }
    jobIds = netManager->addAsynchronousJob(job);
    if (0 == jobIds)
        return;
    m_jobId = jobIds;
    job->m_jobId = m_jobId;

    // 执行完add后，this可能被销毁，当dataurl的时候
}

void WebURLLoaderImplCurl::DidChangePriority(blink::WebURLRequest::Priority, int intra_priority_value)
{
}

scoped_refptr<base::SingleThreadTaskRunner> WebURLLoaderImplCurl::GetTaskRunnerForBodyLoader()
{
    return m_freezableTaskRunner;
}

void WebURLLoaderImplCurl::Freeze(blink::LoaderFreezeMode mode)
{
    m_mode = mode;
    //     if (m_mode != blink::LoaderFreezeMode::kNone || !m_client)
    //         return;
    //     m_freezableTaskRunner->GetTaskRunner()->PostTask(FROM_HERE, WTF::BindOnce(&WebURLLoaderImplCurl::fail, m_weakPtr.GetWeakPtr()));
}

} // content