
#include "gen/third_party/blink/public/mojom/blob/blob.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/blob/blob_url_store.mojom-blink.h"
#include "mojo/public/cpp/bindings/remote.h"
#include <map>

namespace content {

class BlobURLStoreSet {
public:
    struct SecurityOriginAndBlob {
        ::mojo::Remote<::blink::mojom::blink::Blob> blob;
        std::string securityOriginToken;
    };
    using UrlToBlobs = std::map<std::string, SecurityOriginAndBlob*>;

    static BlobURLStoreSet* get();

    void addUrlBlob(const std::string& url, const std::string& securityOriginToken, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob);
    void removeUrlBlob(const std::string& url);
    void removeBySecurityOriginToken(const std::string& securityOriginToken);
    ::mojo::Remote<::blink::mojom::blink::Blob>* getBlobByUrl(const std::string& url);

private:
    UrlToBlobs m_urlToBlobs;
};

class BlobURLStoreImpl : public ::blink::mojom::blink::BlobURLStore {
public:
    BlobURLStoreImpl(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin);
    ~BlobURLStoreImpl();

    bool Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, const ::blink::KURL& url, const ::base::UnguessableToken& unsafe_agent_cluster_id,
        const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site) override;

    //using RegisterCallback = base::OnceCallback<void()>;
    void Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, const ::blink::KURL& url, const ::base::UnguessableToken& unsafe_agent_cluster_id,
        const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site, ::blink::mojom::blink::BlobURLStore::RegisterCallback callback) override;

    void Revoke(const ::blink::KURL& url) override;

    void ResolveAsURLLoaderFactory(const ::blink::KURL& url, ::mojo::PendingReceiver<::network::mojom::blink::URLLoaderFactory> factory,
        ResolveAsURLLoaderFactoryCallback callback) override;

    void ResolveForNavigation(
        const ::blink::KURL& url, ::mojo::PendingReceiver<blink::mojom::blink::BlobURLToken> token, ResolveForNavigationCallback callback) override;

    void ResolveForWorkerScriptFetch(const ::blink::KURL& url, ::mojo::PendingReceiver< blink::mojom::blink::BlobURLToken> token, ResolveForWorkerScriptFetchCallback callback) override;

    ::scoped_refptr<const ::blink::SecurityOrigin> m_origin;

private:
    ::mojo::Remote<::blink::mojom::blink::Blob> m_blobRemote;
};

}
