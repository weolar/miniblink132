
#include "content/renderer/BlobURLStoreImpl.h"

#include "content/common/ThreadCall.h"
#include "content/common/CreateAndBindTempl.h"
#include "content/renderer/BlobRegistryImpl.h"
#include "third_party/blink/public/platform/web_url_response.h"
#include "third_party/blink/renderer/platform/network/http_names.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"
#include "services/network/public/cpp/resource_request.h"
#include "gen/services/network/public/mojom/url_loader_factory.mojom-blink.h"
#include "gen/services/network/public/mojom/url_response_head.mojom-blink-forward.h"
#include "gen/services/network/public/mojom/url_response_head.mojom-blink.h"
#include "gen/services/network/public/mojom/url_response_head.mojom.h"
#include "gen/services/network/public/mojom/url_loader.mojom.h"
#include "gen/services/network/public/mojom/url_loader.mojom-blink.h"
#include "base/functional/bind.h"

bool blink::mojom::blink::BlobURLStore::Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, const ::blink::KURL& url,
    const ::base::UnguessableToken& unsafe_agent_cluster_id, const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site)
{
    return false;
}

namespace content {

BlobURLStoreSet* BlobURLStoreSet::get()
{
    static BlobURLStoreSet* s_inst = nullptr;
    if (s_inst)
        return s_inst;
    s_inst = new BlobURLStoreSet();
    return s_inst;
}

void BlobURLStoreSet::addUrlBlob(const std::string& url, const std::string& securityOriginToken, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob)
{
    UrlToBlobs::iterator it = m_urlToBlobs.find(url);
    CHECK(it == m_urlToBlobs.end());

    SecurityOriginAndBlob* securityOriginAndBlob = new SecurityOriginAndBlob();
    securityOriginAndBlob->securityOriginToken = securityOriginToken;

    //::mojo::Remote<::blink::mojom::blink::Blob>* blobRemote = new ::mojo::Remote<::blink::mojom::blink::Blob>();
    securityOriginAndBlob->blob.Bind(std::move(blob));
    securityOriginAndBlob->blob.set_disconnect_handler(base::BindOnce([](const std::string& url) { BlobURLStoreSet::get()->removeUrlBlob(url); }, url));
    m_urlToBlobs[url] = securityOriginAndBlob;
}

void BlobURLStoreSet::removeUrlBlob(const std::string& url)
{
    base::SequencedTaskRunner::GetCurrentDefault()->PostDelayedTask(FROM_HERE, base::BindOnce([](BlobURLStoreSet* self, const std::string& url) {
        UrlToBlobs::iterator it = self->m_urlToBlobs.find(url);
        if (it == self->m_urlToBlobs.end())
            return;
        SecurityOriginAndBlob* securityOriginAndBlob = it->second;
        delete securityOriginAndBlob;

        self->m_urlToBlobs.erase(it);
    }, base::Unretained(this), url), base::Seconds(6));
}

void BlobURLStoreSet::removeBySecurityOriginToken(const std::string& securityOriginToken)
{
    for (UrlToBlobs::iterator it = m_urlToBlobs.begin(); it != m_urlToBlobs.end();) {
        SecurityOriginAndBlob* securityOriginAndBlob = it->second;
        if (securityOriginAndBlob->securityOriginToken == securityOriginToken) {
            SecurityOriginAndBlob* securityOriginAndBlob = it->second;
            m_urlToBlobs.erase(it++);
            delete securityOriginAndBlob;
        } else {
            ++it;
        }
    }
}

::mojo::Remote<::blink::mojom::blink::Blob>* BlobURLStoreSet::getBlobByUrl(const std::string& url)
{
    UrlToBlobs::iterator it = m_urlToBlobs.find(url);
    if (it == m_urlToBlobs.end())
        return nullptr;
    //::mojo::Remote<::blink::mojom::blink::Blob>* ret = it->second;
    SecurityOriginAndBlob* securityOriginAndBlob = it->second;
    return &securityOriginAndBlob->blob;
}

//-----

BlobURLStoreImpl::BlobURLStoreImpl(const std::string& origin)
    : m_origin(origin)
{
}

BlobURLStoreImpl::~BlobURLStoreImpl()
{
    BlobURLStoreSet::get()->removeBySecurityOriginToken(m_origin);
}

bool BlobURLStoreImpl::Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, const ::blink::KURL& url,
    const ::base::UnguessableToken& unsafe_agent_cluster_id, const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site)
{
//     std::string urlStr = "BlobURLStoreImpl::Register, url: ";
//     urlStr += url.GetString().Utf8();
//     urlStr += ",,,,,";
//     urlStr += m_origin->ToString().Utf8();
//     urlStr += "\n";
//     OutputDebugStringA(urlStr.c_str());

    BlobURLStoreSet::get()->addUrlBlob(url.GetString().Utf8(), m_origin, std::move(blob));

    //     BlobURLStoreImpl* self = this;
    //     ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] {
    //         std::string* uuid = nullptr;
    //         self->m_blobRemote->GetInternalUUID(base::BindOnce([](std::string** uuid, const WTF::String& uid) {
    //             *uuid = new std::string(uid.Ascii());
    //         }, &uuid));
    //
    //         std::string output = "BlobURLStoreImpl::Register, uuid: ";
    //         output += *uuid;
    //         output += "\n";
    //         delete uuid;
    //         OutputDebugStringA(output.c_str());
    //     });
    //
    //     m_blobRemote.Bind(std::move(blob));
    return true;
}

//using RegisterCallback = base::OnceCallback<void()>;

void BlobURLStoreImpl::Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, const ::blink::KURL& url,
    const ::base::UnguessableToken& unsafe_agent_cluster_id, const ::absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site,
    ::blink::mojom::blink::BlobURLStore::RegisterCallback callback)
{
    DebugBreak();
    BlobURLStoreSet::get()->addUrlBlob(url.GetString().Utf8(), m_origin, std::move(blob));
}

void BlobURLStoreImpl::Revoke(const ::blink::KURL& url)
{
    BlobURLStoreSet::get()->removeUrlBlob(url.GetString().Utf8());
}

class BlobURLStoreLoader : public network::mojom::URLLoader {
public:
    BlobURLStoreLoader(::mojo::PendingReceiver<::network::mojom::URLLoader> loader, int32_t requestId, uint32_t options,
        const ::network::ResourceRequest& request, ::mojo::PendingRemote<::network::mojom::URLLoaderClient> client,
        const ::net::MutableNetworkTrafficAnnotationTag& trafficAnnotation)
    {
        m_urlLoadClient.Bind(std::move(client));
        m_receiver.Bind(std::move(loader));
        m_request = request;
        BlobURLStoreLoader* self = this;
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](BlobURLStoreLoader* self) {
            self->start();
        }, self));
    }

    ~BlobURLStoreLoader() = default;

    void start()
    {
        ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(m_request.url.possibly_invalid_spec());
        if (!blob) {
            ::network::URLLoaderCompletionStatus status(-1);
            m_urlLoadClient->OnComplete(status);
            return;
        }

        BlobURLStoreLoader* self = this;
        std::string* uuid = nullptr;
        (*blob)->GetInternalUUID(base::BindOnce([](std::string** uuid, const WTF::String& uid) {
            *uuid = new std::string(uid.Ascii());
        }, &uuid));
        BlobEntry* blobEntry = BlobEntry::findByUuid(*uuid);
        delete uuid;

        if (!blobEntry) {
            ::network::URLLoaderCompletionStatus status(-1);
            m_urlLoadClient->OnComplete(status);
            return;
        }

        uint16_t major = 1; uint16_t minor = 1;
        net::HttpVersion ver(major, minor);
        std::string statusTxt = "200";//response.HttpStatusText();

        net::HttpResponseHeaders::Builder builder(ver, std::string_view(statusTxt));

        //HeadersVisitor headersVisitor(&builder);
        //response.VisitHttpHeaderFields(&headersVisitor);
        builder.AddHeader(std::string_view("Content-Type"), std::string_view(blobEntry->m_contentType));

        ::network::mojom::URLResponseHeadPtr responseHead = ::network::mojom::URLResponseHead::New();
        responseHead->headers = builder.Build();
        responseHead->mime_type = blobEntry->m_contentType;
        //responseHead->content_length = response.ExpectedContentLength();

        std::vector<char> buffer;
        int64_t allSize = 0;
        blobEntry->read(&buffer, 0, -1, &allSize);
        uint32_t numBytes = (uint32_t)buffer.size();

        MojoHandle dataPipeProducerHandle = 0;
        MojoHandle dataPipeConsumerHandle = 0;
        MojoCreateDataPipeOptions createDataOptions;
        createDataOptions.element_num_bytes = 1;
        createDataOptions.capacity_num_bytes = -1;
        MojoCreateDataPipe(&createDataOptions, &dataPipeProducerHandle, &dataPipeConsumerHandle);

        mojo::DataPipeConsumerHandle dataPipeConsumer(dataPipeConsumerHandle);
        mojo::ScopedDataPipeConsumerHandle responseBodyHandld(std::move(dataPipeConsumer));

        if (0 != numBytes)
            MojoWriteData(dataPipeProducerHandle, buffer.data(), &numBytes, nullptr);
        MojoClose(dataPipeProducerHandle);

        //network::mojom::blink::URLResponseHeadPtr responseHead = convertWebURLResponseToHttpResponseHeaders(response);
        m_urlLoadClient->OnReceiveResponse(std::move(responseHead), std::move(responseBodyHandld), absl::nullopt);

        ::network::URLLoaderCompletionStatus status(0);
        m_urlLoadClient->OnComplete(status);
    }

    // network::mojom::blink::URLLoader:
    /*virtual*/ void FollowRedirect(const std::vector<std::string>& removed_headers, const ::net::HttpRequestHeaders& modified_headers,
        const ::net::HttpRequestHeaders& modified_cors_exempt_headers, const std::optional<::GURL>& new_url) override
    {
    }

    /*virtual*/ void SetPriority(::net::RequestPriority priority, int32_t intra_priority_value) override
    {
    }

    /*virtual*/ void PauseReadingBodyFromNet() override
    {
    }

    /*virtual*/ void ResumeReadingBodyFromNet() override
    {
    }
    //----
private:
    ::network::ResourceRequest m_request;
    mojo::Remote<network::mojom::URLLoaderClient> m_urlLoadClient;
    mojo::Receiver<network::mojom::URLLoader> m_receiver{ this };
};

class BlobURLStoreLoaderFactoryImpl : public ::network::mojom::URLLoaderFactory {
public:
    BlobURLStoreLoaderFactoryImpl(const ::blink::KURL& url)
    {
        m_url = url;
    }

    void CreateLoaderAndStart(::mojo::PendingReceiver<::network::mojom::URLLoader> loader, int32_t requestId, uint32_t options,
        const ::network::ResourceRequest& request, ::mojo::PendingRemote<::network::mojom::URLLoaderClient> client,
        const ::net::MutableNetworkTrafficAnnotationTag& trafficAnnotation) override
    {
        new BlobURLStoreLoader(std::move(loader), requestId, options, request, std::move(client), trafficAnnotation);
    }

    // LoaderFactoryForWorker::CreateURLLoader会走到这个函数
    void Clone(::mojo::PendingReceiver<network::mojom::URLLoaderFactory> factory) override
    {
        createAndBindInterface<::network::mojom::URLLoaderFactory, BlobURLStoreLoaderFactoryImpl>(factory.PassPipe(), m_url);
    }

    ::blink::KURL m_url;
};

//using ResolveAsURLLoaderFactoryCallback = base::OnceCallback<void(const absl::optional<::base::UnguessableToken>&, const absl::optional<::blink::BlinkSchemefulSite>&)>;
void BlobURLStoreImpl::ResolveAsURLLoaderFactory(const ::blink::KURL& url, ::mojo::PendingReceiver<::network::mojom::blink::URLLoaderFactory> factory,
    ::blink::mojom::blink::BlobURLStore::ResolveAsURLLoaderFactoryCallback callback)
{
    // 这里要注意了，从blink的GetBlobURLStore().ResolveAsURLLoaderFactory传过来的居然是::network::mojom::blink::URLLoaderFactory，
    // 但在真正使用时（LoaderFactoryForFrame::CreateURLLoader里），又是::network::mojom::URLLoaderFactory了
    createAndBindInterface<::network::mojom::URLLoaderFactory, BlobURLStoreLoaderFactoryImpl>(factory.PassPipe(), url);
    absl::optional<::base::UnguessableToken> token;
    absl::optional<::blink::BlinkSchemefulSite> site;
    std::move(callback).Run(token, site);
}

#ifdef _DEBUG
static int s_BlobURLTokenImpl = 0;
#endif

class BlobURLTokenImpl : public ::blink::mojom::blink::BlobURLToken {
public:
    BlobURLTokenImpl()
    {
#ifdef _DEBUG
        s_BlobURLTokenImpl++;
        char output[100] = { 0 };
        sprintf_s(output, 99, "BlobURLTokenImpl: %d\n", s_BlobURLTokenImpl);
        OutputDebugStringA(output);
#endif
    }
    ~BlobURLTokenImpl()
    {
#ifdef _DEBUG
        --s_BlobURLTokenImpl;
        char output[100] = { 0 };
        sprintf_s(output, 99, "~BlobURLTokenImpl: %d\n", s_BlobURLTokenImpl);
        OutputDebugStringA(output);
#endif
    }

    /*virtual*/ void Clone(::mojo::PendingReceiver<::blink::mojom::blink::BlobURLToken> token) override
    {
        createAndBindInterface<::blink::mojom::blink::BlobURLToken, BlobURLTokenImpl>(token.PassPipe());
    }

    //using GetTokenCallback = base::OnceCallback<void(const ::base::UnguessableToken&)>;
    /*virtual*/ void GetToken(GetTokenCallback callback) override
    {
        DebugBreak();
    }
};

//using ResolveForNavigationCallback = base::OnceCallback<void(const absl::optional<::base::UnguessableToken>&)>;
void BlobURLStoreImpl::ResolveForNavigation(const ::blink::KURL& url, ::mojo::PendingReceiver<::blink::mojom::blink::BlobURLToken> token,
    ::blink::mojom::blink::BlobURLStore::ResolveForNavigationCallback callback)
{
    createAndBindInterface<::blink::mojom::blink::BlobURLToken, BlobURLTokenImpl>(token.PassPipe());
    std::move(callback).Run(absl::nullopt);
}

void BlobURLStoreImpl::ResolveForWorkerScriptFetch(const ::blink::KURL& url, ::mojo::PendingReceiver< blink::mojom::blink::BlobURLToken> token, ResolveForWorkerScriptFetchCallback callback)
{
    createAndBindInterface<::blink::mojom::blink::BlobURLToken, BlobURLTokenImpl>(token.PassPipe());
    //absl::optional<::base::UnguessableToken> token;
    std::move(callback).Run(absl::nullopt);
}

}