
#include "mbnet/DownloadBlobUrl.h"

#include "mbnet/WebURLLoaderManager.h"
#include "mbnet/WebURLLoaderInternal.h"
#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "content/renderer/BlobURLStoreImpl.h"
#include "content/renderer/BlobRegistryImpl.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "third_party/blink/public/mojom/blob/blob.mojom-blink.h"
#include "third_party/blink/renderer/platform/wtf/wtf.h"
#include "base/task/sequenced_task_runner.h"
#include <functional>

namespace mbnet {

bool parseDataURL(const GURL& kurl, String& mimeType, String& charset, Vector<char>& out);
bool dispatchDownloadToWke(content::MbWebView* webview, WebURLLoaderInternal* job, const utf8* url, const AtomicString& contentType, String* downloadName);

static void finishHandleBlobUrl(bool isSync, std::function<void(void)>&& closure)
{
    CHECK(WTF::IsMainThread());
    if (isSync) {
        closure();
        return;
    }
    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](std::function<void(void)>&& closure) { closure(); }, std::move(closure)));
}

static void onFinishHandleBlobUrl(int jobId, const GURL& gurl, blink::URLLoaderClient* client, blink::WebURLResponse* response)
{
    WebURLLoaderManager* manager = WebURLLoaderManager::sharedInstance();
    WebURLLoaderInternal* job = (WebURLLoaderInternal*)manager->checkJob(jobId);
    bool isOk = false;
    do {
        if (!job || job->isCancelled())
            break;

        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)job->m_mbwebviewId);
        if (!webview)
            break;

        dispatchDownloadToWke(webview, job, job->m_url.c_str(), AtomicString("application/octet-stream"), job->m_downloadName.get());
        if (WebURLLoaderInternal::kCacheForDownloadYes != job->m_cacheForDownloadOpt)
            break;

        uint32_t numBytes = 0;
        const char* bufData = nullptr;
        Vector<char> blinkBuffer;
        std::vector<char> buffer;
        if (gurl.SchemeIs("data")) {
            String mimeType;
            String charset;
            
            isOk = parseDataURL(gurl, mimeType, charset, blinkBuffer);
            if (!isOk)
                break;
            response->SetMimeType(mimeType);
            bufData = blinkBuffer.data();
            numBytes = (uint32_t)blinkBuffer.size();
        } else {
            ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(gurl.possibly_invalid_spec());
            if (!blob)
                break;

            std::string* uuidStr = nullptr;
            (*blob)->GetInternalUUID(base::BindOnce([](std::string** uuidStr, const WTF::String& uid) { *uuidStr = new std::string(uid.Ascii()); }, &uuidStr));
            content::BlobEntry* blobEntry = content::BlobEntry::findByUuid(*uuidStr);
            delete uuidStr;

            if (!blobEntry)
                break;

            int64_t allSize = 0;
            blobEntry->read(&buffer, 0, -1, &allSize);
            response->SetMimeType(blink::WebString::FromUTF8(blobEntry->m_contentType));
            numBytes = (uint32_t)buffer.size();
            bufData = (char*)buffer.data();
        }
       
        response->SetExpectedContentLength(numBytes);
        absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer> body;
        client->DidReceiveResponse(*response, std::move(body), std::nullopt);

        if (job->m_dataBind) {
            job->m_dataCacheForDownload.insert(job->m_dataCacheForDownload.end(), bufData, bufData + numBytes);
            job->m_dataBind->recvCallback(job->m_dataBind->param, job, job->m_dataCacheForDownload.data(), job->m_dataCacheForDownload.size());
            job->m_dataCacheForDownload.clear();
            job->m_dataBind->finishCallback(job->m_dataBind->param, job, MB_LOADING_SUCCEEDED);
        }

        //client->DidReceiveData(buffer.data(), numBytes);
        client->DidFinishLoading(base::TimeTicks::Now(), numBytes, numBytes, numBytes);
        isOk = true;
    } while (false);

    if (!isOk) {
        if (job->m_dataBind) {
            job->m_dataBind->finishCallback(job->m_dataBind->param, job, MB_LOADING_FAILED);
        }
        blink::WebURLError error(net::ERR_ABORTED, blink::KURL(gurl));
        client->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
    }

    delete job;
    manager->removeLiveJobs(jobId);

    delete response;
}

void handleDownloadBlobOrDataUrl(WebURLLoaderInternal* job, const GURL& gurl, bool isSync)
{
    blink::URLLoader* handle = job->loader();
    blink::URLLoaderClient* client = job->client();
    blink::WebURLResponse* response = new blink::WebURLResponse();
    //response->SetMimeType(WTF::String::FromUTF8("application/octet-stream"));
    //response->SetTextEncodingName(charset);
    response->SetCurrentRequestUrl(blink::KURL(gurl));
    //
    response->SetHttpStatusCode(200);
    response->SetHttpStatusText(blink::WebString::FromLatin1("OK"));

    int jobId = job->m_jobId;
    finishHandleBlobUrl(isSync, [jobId, gurl, client, response] { onFinishHandleBlobUrl(jobId, gurl, client, response); });
}

}