#ifndef mbnet_SingleRequestURLLoader_h
#define mbnet_SingleRequestURLLoader_h

#include "mbnet/WebURLRequestExtraDataWrap.h"
#include "mbnet/WebURLLoaderImplCurl.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "services/network/public/cpp/shared_url_loader_factory.h"
#include "services/network/public/mojom/url_loader.mojom.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "mojo/public/cpp/bindings/receiver_set.h"

namespace base {
class WaitableEvent;
}

namespace mbnet {

class SingleRequestURLLoader 
    : public blink::URLLoaderClient
    , public network::mojom::URLLoader {
public:
    SingleRequestURLLoader(
        scoped_refptr<base::SingleThreadTaskRunner> freezableTaskRunnerHandle,
        scoped_refptr<base::SingleThreadTaskRunner> unfreezableTaskRunnerHandle, 
        base::WaitableEvent* terminateSyncLoadEvent,
        scoped_refptr<WebURLRequestExtraDataWrap> extraData);

    // blink::URLLoaderClient:
    /*virtual*/ bool WillFollowRedirect(const blink::WebURL& new_url, const net::SiteForCookies& new_site_for_cookies, const blink::WebString& new_referrer,
        network::mojom::ReferrerPolicy new_referrer_policy, const blink::WebString& new_method, const blink::WebURLResponse& passed_redirect_response,
        bool& report_raw_headers, std::vector<std::string>* removed_headers, net::HttpRequestHeaders& modified_headers, bool insecure_scheme_was_upgraded) override;

    /*virtual*/ void DidSendData(uint64_t bytes_sent, uint64_t total_bytes_to_be_sent) override;

    /*virtual*/ void DidReceiveResponse(
        const blink::WebURLResponse&, absl::variant<mojo::ScopedDataPipeConsumerHandle, SegmentedBuffer>, std::optional<mojo_base::BigBuffer> cachedMetadata) override;

    /*virtual*/ void DidReceiveDataForTesting(base::span<const char> data) override;

    /*virtual*/ void DidReceiveTransferSizeUpdate(int transfer_size_diff) override;

    /*virtual*/ void DidFinishLoading(
        base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length, int64_t total_decoded_body_length) override;

    /*virtual*/ void DidFail(const blink::WebURLError&, base::TimeTicks finish_time, int64_t total_encoded_data_length, uint64_t total_encoded_body_length,
        int64_t total_decoded_body_length) override;

    /*virtual*/ void CountFeature(blink::mojom::WebFeature) override;

    // network::mojom::URLLoader:
    /*virtual*/ ~SingleRequestURLLoader() override;

    /*virtual*/ void FollowRedirect(const std::vector<std::string>& removed_headers, const ::net::HttpRequestHeaders& modified_headers,
        const ::net::HttpRequestHeaders& modified_cors_exempt_headers, const std::optional<::GURL>& new_url) override;

    /*virtual*/ void SetPriority(::net::RequestPriority priority, int32_t intra_priority_value) override;

    /*virtual*/ void PauseReadingBodyFromNet() override;

    /*virtual*/ void ResumeReadingBodyFromNet() override;
    //----

    void startLoader(bool isSync, const network::ResourceRequest& resourceRequest,
        mojo::PendingReceiver<network::mojom::URLLoader> receiver,
        mojo::PendingRemote<network::mojom::URLLoaderClient> client);

private:
    mojo::Remote<network::mojom::URLLoaderClient> m_urlLoadClient;
    mojo::Receiver<network::mojom::URLLoader> m_receiver{this};

    std::unique_ptr<WebURLLoaderImplCurl> m_loader;
    scoped_refptr<WebURLRequestExtraDataWrap> m_extraData;

    int m_didReceiveResponseCount = 0;
};

class SingleReqURLLoaderFactory : public network::SharedURLLoaderFactory {
public:
    using RequestHandler = base::OnceCallback<void(
        bool isSync,
        const network::ResourceRequest& resourceRequest, 
        mojo::PendingReceiver<network::mojom::URLLoader>,
        mojo::PendingRemote<network::mojom::URLLoaderClient>)>;

    explicit SingleReqURLLoaderFactory(RequestHandler handler);

    SingleReqURLLoaderFactory(const SingleReqURLLoaderFactory&) = delete;
    SingleReqURLLoaderFactory& operator=(const SingleReqURLLoaderFactory&) = delete;

    // SharedURLLoaderFactory:
    void CreateLoaderAndStart(mojo::PendingReceiver<network::mojom::URLLoader> loader, int32_t request_id, uint32_t options,
        const network::ResourceRequest& request, mojo::PendingRemote<network::mojom::URLLoaderClient> client,
        const net::MutableNetworkTrafficAnnotationTag& traffic_annotation) override;
    void Clone(mojo::PendingReceiver<network::mojom::URLLoaderFactory> receiver) override;
    std::unique_ptr<network::PendingSharedURLLoaderFactory> Clone() override;

private:
    class PendingFactory;
    class HandlerState;

    explicit SingleReqURLLoaderFactory(scoped_refptr<HandlerState> state);
    ~SingleReqURLLoaderFactory() override;

    scoped_refptr<HandlerState> state_;

    mojo::ReceiverSet<network::mojom::URLLoaderFactory, scoped_refptr<SingleReqURLLoaderFactory>> receivers_;
};

} // mbnet

#endif // mbnet_SingleRequestURLLoader_h
