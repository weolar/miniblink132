
#include "mbnet/SingleRequestURLLoader.h"

#include "content/common/ThreadCall.h"
#include "services/network/public/mojom/url_response_head.mojom.h"
#include "third_party/blink/renderer/platform/weborigin/security_origin.h"
#include "third_party/blink/public/platform/web_url_response.h"
#include "third_party/blink/public/platform/web_http_header_visitor.h"
#include "third_party/blink/public/platform/web_url_error.h"

#include "base/strings/string_number_conversions.h"
#include <windows.h>

namespace mbnet {

SingleRequestURLLoader::SingleRequestURLLoader(
    scoped_refptr<base::SingleThreadTaskRunner> freezableTaskRunnerHandle,
    scoped_refptr<base::SingleThreadTaskRunner> unfreezableTaskRunnerHandle,
    base::WaitableEvent* terminateSyncLoadEvent,
    scoped_refptr<WebURLRequestExtraDataWrap> extraData)
{
    m_extraData = extraData;
    m_loader = std::make_unique<WebURLLoaderImplCurl>(freezableTaskRunnerHandle, unfreezableTaskRunnerHandle, terminateSyncLoadEvent, m_extraData->mbwebviewId);
}

SingleRequestURLLoader::~SingleRequestURLLoader()
{
}

void SingleRequestURLLoader::startLoader(bool isSync, const network::ResourceRequest& request,
    mojo::PendingReceiver<network::mojom::URLLoader> receiver,
    mojo::PendingRemote<network::mojom::URLLoaderClient> client)
{
    m_urlLoadClient.Bind(std::move(client));
    m_receiver.Bind(std::move(receiver));

    std::unique_ptr<network::ResourceRequest> requestCopy = std::make_unique<network::ResourceRequest>(request);
    if (1/*!isSync*/) {
        m_loader->LoadAsynchronouslyEx(std::move(requestCopy), scoped_refptr<const blink::SecurityOrigin>(),
            true, nullptr, nullptr, m_extraData, this);
    } else {
//         std::unique_ptr<network::ResourceRequest> request, 
//         scoped_refptr<const blink::SecurityOrigin> top_frame_origin,
//         bool download_to_blob,
//         bool no_mime_sniffing, 
//         base::TimeDelta timeout_interval, 
//         blink::URLLoaderClient* client, 
//         blink::WebURLResponse& response,
//         std::optional<blink::WebURLError>& error, 
//         scoped_refptr<WTF::SharedBuffer>& data, 
//         int64_t& encoded_data_length, 
//         uint64_t& encoded_body_length,
//         scoped_refptr<blink::BlobDataHandle>& downloaded_blob, 
//         std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resource_load_info_notifier_wrapper
// 
//         m_loader->LoadSynchronously(
//             std::move(requestCopy),
//             scoped_refptr<const blink::SecurityOrigin>(),
//             false, /*download_to_blob,*/
//             false /*no_mime_sniffing*/,
//             base::TimeDelta() /*timeoutInterval*/,
//             blink::WebURLLoaderClient * client,
//             blink::WebURLResponse & response,
//             absl::optional<blink::WebURLError>&error,
//             blink::WebData & data,
//             int64_t & encodedDataLength,
//             int64_t & encodedBodyLength,
//             blink::WebBlobInfo & downloadedBlob,
//             std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper
//         );
    }
}

bool SingleRequestURLLoader::WillFollowRedirect(const blink::WebURL& new_url, const net::SiteForCookies& new_site_for_cookies, const blink::WebString& new_referrer,
    network::mojom::ReferrerPolicy new_referrer_policy, const blink::WebString& new_method, const blink::WebURLResponse& passed_redirect_response,
    bool& report_raw_headers, std::vector<std::string>* removed_headers, net::HttpRequestHeaders& modified_headers, bool insecure_scheme_was_upgraded)
{
    return true;
}

void SingleRequestURLLoader::DidSendData(uint64_t bytes_sent, uint64_t total_bytes_to_be_sent)
{
}

class HeadersVisitor : public blink::WebHTTPHeaderVisitor {
public:
    HeadersVisitor(net::HttpResponseHeaders::Builder* builder) 
    {
        m_builder = builder;
    }
    ~HeadersVisitor() override
    {
    }

    void VisitHeader(const blink::WebString& name, const blink::WebString& value) override
    {
#if 0 // def _DEBUG
        std::string temp = "VisitHeader:[";
        temp += name.Utf8();
        temp += "]:[";
        temp += value.Utf8();
        temp += "]\n";
        OutputDebugStringA(temp.c_str());
#endif // DEBUG

        String nameLow = ((String)name).LowerASCII();
        std::unique_ptr<std::string> nameUtf8(new std::string(nameLow.Utf8()));
        if (*nameUtf8 == "set-cookie" || *nameUtf8 == "set-cookie2" || *nameUtf8 == "clear-site-data")
            return;

        std::unique_ptr<std::string> vauleUtf8(new std::string(value.Utf8()));
        m_builder->AddHeader(std::string_view(*(nameUtf8.get())), std::string_view(*(vauleUtf8.get())));

        m_cache.push_back(std::move(nameUtf8));
        m_cache.push_back(std::move(vauleUtf8));
    }

private:
    std::vector<std::unique_ptr<std::string>> m_cache;
    net::HttpResponseHeaders::Builder* m_builder;
};

network::mojom::URLResponseHeadPtr convertWebURLResponseToHttpResponseHeaders(const blink::WebURLResponse& response)
{
    network::mojom::URLResponseHeadPtr responseHead = network::mojom::URLResponseHead::New();
//     scoped_refptr<net::HttpResponseHeaders> headers;
//         base::MakeRefCounted<net::HttpResponseHeaders>(
//             net::HttpUtil::AssembleRawHeaders(raw_headers));

    uint16_t major = 1; uint16_t minor = 0;
    blink::WebURLResponse::HTTPVersion version = response.HttpVersion();
    if (blink::WebURLResponse::HTTPVersion::kHTTPVersion_1_1 == version) {
        major = 1; 
        minor = 0;
    } else if (blink::WebURLResponse::HTTPVersion::kHTTPVersion_0_9 == version) {
        major = 0;
        minor = 9;
    } else if (blink::WebURLResponse::HTTPVersion::kHTTPVersion_1_0 == version) {
        major = 1;
        minor = 0;
    } else if (blink::WebURLResponse::HTTPVersion::kHTTPVersion_2_0 == version) {
        major = 2;
        minor = 0;
    }
    net::HttpVersion ver(major, minor);
    blink::WebString statusTxt = response.HttpStatusText();
    std::string statusText = base::NumberToString(response.HttpStatusCode());
    statusText += " ";
    statusText += statusTxt.Utf8();
    net::HttpResponseHeaders::Builder builder(ver, std::string_view(statusText));

    HeadersVisitor headersVisitor(&builder);
    response.VisitHttpHeaderFields(&headersVisitor);
    responseHead->headers = builder.Build();

    responseHead->mime_type = response.MimeType().Utf8();
    //responseHead->charset = response.MimeType().Utf8();
    responseHead->content_length = response.ExpectedContentLength();
    // encoded_data_length(-1)
    // encoded_body_length()
        
    return responseHead;
}

void SingleRequestURLLoader::DidReceiveResponse(
    const blink::WebURLResponse& response, 
    absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer> responseBodyConsumerVar, 
    std::optional<mojo_base::BigBuffer> cachedMetadata)
{
    CHECK(m_didReceiveResponseCount == 0);
    m_didReceiveResponseCount++;
    mojo::ScopedDataPipeConsumerHandle* responseBodyConsumer = absl::get_if<mojo::ScopedDataPipeConsumerHandle>(&responseBodyConsumerVar);
    CHECK(responseBodyConsumer);

//     responseHead->headers = base::MakeRefCounted<net::HttpResponseHeaders>(
//         net::HttpUtil::AssembleRawHeaders(headers));
    network::mojom::URLResponseHeadPtr responseHead = convertWebURLResponseToHttpResponseHeaders(response);

    if (m_urlLoadClient.get())
        m_urlLoadClient->OnReceiveResponse(std::move(responseHead), std::move(*responseBodyConsumer), absl::nullopt);
}

void SingleRequestURLLoader::DidReceiveDataForTesting(base::span<const char> data)
{
    *(int*)1 = 1;
}

void SingleRequestURLLoader::DidReceiveTransferSizeUpdate(int transfer_size_diff)
{
    *(int*)1 = 1;
}

void SingleRequestURLLoader::DidFinishLoading(
    base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length, int64_t total_decoded_body_length)
{
    ::network::URLLoaderCompletionStatus status(0);
    if (m_urlLoadClient.get())
        m_urlLoadClient->OnComplete(status); 

    content::ThreadCall::delayDestroySelf(this, base::SingleThreadTaskRunner::GetCurrentDefault(), 0);
}

void SingleRequestURLLoader::DidFail(const blink::WebURLError& err, base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length,
    int64_t total_decoded_body_length)
{
    ::network::URLLoaderCompletionStatus status(err.reason());
    if (m_urlLoadClient.get())
        m_urlLoadClient->OnComplete(status);

    content::ThreadCall::delayDestroySelf(this, base::SingleThreadTaskRunner::GetCurrentDefault(), 0);
}

void SingleRequestURLLoader::CountFeature(blink::mojom::WebFeature)
{
    *(int*)1 = 1;
}

//---

void SingleRequestURLLoader::FollowRedirect(const std::vector<std::string>& removed_headers, const ::net::HttpRequestHeaders& modified_headers,
    const ::net::HttpRequestHeaders& modified_cors_exempt_headers, const std::optional<::GURL>& new_url)
{
    *(int*)1 = 1;
}

void SingleRequestURLLoader::SetPriority(::net::RequestPriority priority, int32_t intra_priority_value)
{
}

void SingleRequestURLLoader::PauseReadingBodyFromNet()
{
    *(int*)1 = 1;
}

void SingleRequestURLLoader::ResumeReadingBodyFromNet()
{
    *(int*)1 = 1;
}

//////////////////////////////////////////////////////////////////////////

class SingleReqURLLoaderFactory::HandlerState : public base::RefCountedThreadSafe<SingleReqURLLoaderFactory::HandlerState> {
public:
    explicit HandlerState(RequestHandler handler)
        : m_handler(std::move(handler))
        , m_handlerTaskRunner(base::SequencedTaskRunner::GetCurrentDefault())
    {
    }

    HandlerState(const HandlerState&) = delete;
    HandlerState& operator=(const HandlerState&) = delete;

    void HandleRequest(
        const network::ResourceRequest& resourceRequest, mojo::PendingReceiver<network::mojom::URLLoader> loader, mojo::PendingRemote<network::mojom::URLLoaderClient> client)
    {
        // 如果不在同一线程，有可能是同步请求
//         if (!m_handlerTaskRunner->RunsTasksInCurrentSequence()) {
//             m_handlerTaskRunner->PostTask(
//                 FROM_HERE, base::BindOnce(&HandlerState::HandleRequest, this, resourceRequest, std::move(loader), std::move(client)));
//             return;
//         }

        DCHECK(m_handler);
        std::move(m_handler).Run(!m_handlerTaskRunner->RunsTasksInCurrentSequence(), resourceRequest, std::move(loader), std::move(client));
    }

private:
    friend class base::RefCountedThreadSafe<HandlerState>;

    ~HandlerState()
    {
        if (m_handler) {
            m_handlerTaskRunner->PostTask(FROM_HERE, base::BindOnce(&DropHandlerOnHandlerSequence, std::move(m_handler)));
        }
    }

    static void DropHandlerOnHandlerSequence(RequestHandler handler)
    {
    }

    RequestHandler m_handler;
    const scoped_refptr<base::SequencedTaskRunner> m_handlerTaskRunner;
};

class SingleReqURLLoaderFactory::PendingFactory : public network::PendingSharedURLLoaderFactory {
public:
    explicit PendingFactory(scoped_refptr<HandlerState> state)
        : state_(std::move(state))
    {
    }

    PendingFactory(const PendingFactory&) = delete;
    PendingFactory& operator=(const PendingFactory&) = delete;

    ~PendingFactory() override = default;

    // PendingSharedURLLoaderFactory:
    scoped_refptr<network::SharedURLLoaderFactory> CreateFactory() override
    {
        return new SingleReqURLLoaderFactory(std::move(state_));
    }

private:
    scoped_refptr<HandlerState> state_;
};

SingleReqURLLoaderFactory::SingleReqURLLoaderFactory(RequestHandler handler)
    : state_(base::MakeRefCounted<HandlerState>(std::move(handler)))
{
}

void SingleReqURLLoaderFactory::CreateLoaderAndStart(mojo::PendingReceiver<network::mojom::URLLoader> loader, int32_t request_id, uint32_t options,
    const network::ResourceRequest& request, mojo::PendingRemote<network::mojom::URLLoaderClient> client, const net::MutableNetworkTrafficAnnotationTag& traffic_annotation)
{
    state_->HandleRequest(request, std::move(loader), std::move(client));
}

void SingleReqURLLoaderFactory::Clone(mojo::PendingReceiver<network::mojom::URLLoaderFactory> receiver)
{
    // Pass |this| as the recevier context to make sure this object stays alive
    // while it still has receivers.
    receivers_.Add(this, std::move(receiver), this);
}

std::unique_ptr<network::PendingSharedURLLoaderFactory> SingleReqURLLoaderFactory::Clone()
{
    return std::make_unique<PendingFactory>(state_);
}

SingleReqURLLoaderFactory::SingleReqURLLoaderFactory(scoped_refptr<HandlerState> state)
    : state_(std::move(state))
{
}

SingleReqURLLoaderFactory::~SingleReqURLLoaderFactory() = default;


}