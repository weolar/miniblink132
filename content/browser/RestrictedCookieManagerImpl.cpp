
#include "content/browser/RestrictedCookieManagerImpl.h"

#include "content/browser/MbWebview.h"
#include "content/common/common.h"
#include "content/common/LiveIdDetect.h"
#include "services/network/public/mojom/restricted_cookie_manager.mojom.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "mbnet/WebURLLoaderManager.h"

// bool network::mojom::RestrictedCookieManager::SetCookieFromString(::GURL const&,
//     net::SiteForCookies const&, url::Origin const&,
//     std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > const&, bool, bool*, bool*)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }
//
// bool network::mojom::RestrictedCookieManager::GetCookiesString(class ::GURL const&, class net::SiteForCookies const&, class url::Origin const&, bool,
//     class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> >*)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }
//
// bool network::mojom::RestrictedCookieManager::CookiesEnabledFor(class GURL const&, class net::SiteForCookies const&, class url::Origin const&, bool*)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }

bool network::mojom::blink::RestrictedCookieManager::SetCookieFromString(
    const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    const WTF::String& cookie)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

bool network::mojom::blink::RestrictedCookieManager::GetCookiesString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    bool get_version_shared_memory, bool is_ad_tagged, bool force_disable_third_party_cookies, uint64_t* out_version,
    ::base::ReadOnlySharedMemoryRegion* out_version_buffer, WTF::String* out_cookies)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

void network::mojom::blink::RestrictedCookieManager::CookiesEnabledFor(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    CookiesEnabledForCallback callback)
{
    content::printFuncName(__FUNCTION__, true, true);
}

const char network::mojom::RestrictedCookieManager::Name_[] = "network.mojom.RestrictedCookieManager";

namespace content {

class VisitAllCookies {
public:
    VisitAllCookies()
    {
    }
    ~VisitAllCookies()
    {
    }

    static bool cookieVisitor(void* params, const char* name, const char* value, const char* domain, const char* path, int secure, int httpOnly, int* expires)
    {
        VisitAllCookies* self = (VisitAllCookies*)params;
        return true;
    }

private:
};

RestrictedCookieManagerImpl::RestrictedCookieManagerImpl(int64_t webviewId)
{
    m_webviewId = webviewId;
}

static mbnet::WebCookieJarImpl* getCookieJar(int64_t webviewId)
{
    mbnet::WebCookieJarImpl* cookieJar = mbnet::WebURLLoaderManager::sharedInstance()->getShareCookieJar();

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewId);
    if (!webview)
        return cookieJar;
    cookieJar = webview->getWebCookieJarImpl();
    return cookieJar;
}

void RestrictedCookieManagerImpl::GetAllForUrl(const ::blink::KURL& url, const ::net::SiteForCookies& siteForCookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& topFrameOrigin, ::net::StorageAccessApiStatus storageAccessApiStatus,
    ::network::mojom::blink::CookieManagerGetOptionsPtr options,
    bool partitionedCookiesRuntimeFeatureEnabled, bool isAdTagged,
    network::mojom::blink::RestrictedCookieManager::GetAllForUrlCallback callback)
{
    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](
        int64_t webviewId,
        const ::blink::KURL& url, const ::net::SiteForCookies& siteForCookies,
        const ::scoped_refptr<const ::blink::SecurityOrigin>& topFrameOrigin, ::net::StorageAccessApiStatus storageAccessApiStatus,
        ::network::mojom::blink::CookieManagerGetOptionsPtr options,
        bool partitionedCookiesRuntimeFeatureEnabled, bool isAdTagged,
        network::mojom::blink::RestrictedCookieManager::GetAllForUrlCallback callback) {
        mbnet::WebCookieJarImpl* cookieJar = getCookieJar(webviewId);
        cookieJar->getAllCookies(url, siteForCookies, topFrameOrigin, storageAccessApiStatus, std::move(options), partitionedCookiesRuntimeFeatureEnabled,
            isAdTagged, std::move(callback));
        }, 
    m_webviewId, url, siteForCookies, topFrameOrigin, storageAccessApiStatus, std::move(options), partitionedCookiesRuntimeFeatureEnabled,
    isAdTagged, std::move(callback)));
}

void RestrictedCookieManagerImpl::SetCanonicalCookie(const ::net::CanonicalCookie& cookie, const ::blink::KURL& url,
    const ::net::SiteForCookies& site_for_cookies, const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, 
    ::net::StorageAccessApiStatus storage_access_api_status,
    ::net::CookieInclusionStatus status, SetCanonicalCookieCallback callback)
{
    std::string ckLine = net::CanonicalCookie::BuildCookieAttributesLine(cookie);

    mbnet::WebCookieJarImpl* cookieJar = getCookieJar(m_webviewId);
    cookieJar->setCookiesFromDOM(blink::KURL(), url, ckLine);

    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](SetCanonicalCookieCallback callback) {
        std::move(callback).Run(true);
    }, std::move(callback)));
}

void RestrictedCookieManagerImpl::AddChangeListener(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status, ::mojo::PendingRemote<::network::mojom::blink::CookieChangeListener> listener,
    AddChangeListenerCallback callback)
{
    printFuncName(__FUNCTION__, true, false);
}

bool RestrictedCookieManagerImpl::SetCookieFromString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status, 
    const WTF::String& cookie)
{
    mbnet::WebCookieJarImpl* cookieJar = getCookieJar(m_webviewId);

    //     std::string temp = "RestrictedCookieManagerImpl::SetCookieFromString:";
    //     temp += cookie.Utf8().c_str();
    //     temp += "\n";
    //     OutputDebugStringA(temp.c_str());

    cookieJar->setCookiesFromDOM(blink::KURL(), url, cookie.Utf8());
    return true;
}

void RestrictedCookieManagerImpl::SetCookieFromString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status, 
    const WTF::String& cookie,
    SetCookieFromStringCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

bool RestrictedCookieManagerImpl::GetCookiesString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    bool get_version_shared_memory, bool is_ad_tagged, bool force_disable_third_party_cookies, uint64_t* out_version,
    ::base::ReadOnlySharedMemoryRegion* out_version_buffer, WTF::String* out_cookies)
{
    mbnet::WebCookieJarImpl* cookieJar = getCookieJar(m_webviewId);
    std::string result = cookieJar->getCookiesForSession(/*blink::KURL(),*/ url, /*bool httponly*/ false);
    *out_cookies = WTF::String::FromUTF8((const uint8_t*)result.c_str(), result.size());
    return true;
}

void RestrictedCookieManagerImpl::GetCookiesString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    bool get_version_shared_memory, bool is_ad_tagged, bool force_disable_third_party_cookies, GetCookiesStringCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

bool RestrictedCookieManagerImpl::CookiesEnabledFor(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    bool* out_cookies_enabled)
{
    printFuncName(__FUNCTION__, false, false);
    *out_cookies_enabled = true;
    return true;
}

void RestrictedCookieManagerImpl::CookiesEnabledFor(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, ::net::StorageAccessApiStatus storage_access_api_status,
    CookiesEnabledForCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}
}
