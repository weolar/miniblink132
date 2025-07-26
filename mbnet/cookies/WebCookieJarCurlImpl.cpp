
#include "mbnet/cookies/WebCookieJarCurlImpl.h"

#include "mbnet/WebURLLoaderManagerUtil.h"
#include "mbnet/WebURLLoaderManager.h"
#include "third_party/libcurl/include/curl/curl.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/date_math.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "base/strings/string_util.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_split.h"
#include <windows.h>

namespace mbnet {

static void readCurlCookieToken(const char*& cookie, std::string& token)
{
    // Read the next token from a cookie with the Netscape cookie format.
    // Curl separates each token in line with tab character.
    const char* cookieStart = cookie;
    while (cookie && cookie[0] && cookie[0] != '\t')
        cookie++;
    token = std::string(cookieStart, cookie - cookieStart);
    if (cookie[0] == '\t')
        cookie++;
}

static bool domainMatch(const std::string& cookieDomain, const std::string& host)
{
    size_t index = host.find(cookieDomain);

    bool tailMatch = (index != std::string::npos && index + cookieDomain.length() == host.length());

    // Check if host equals cookie domain.
    if (tailMatch && !index)
        return true;

    // Check if host is a subdomain of the domain in the cookie.
    // Curl uses a '.' in front of domains to indicate it's valid on subdomains.
    if (tailMatch && index > 0 && host[index] == '.')
        return true;

    // Check the special case where host equals the cookie domain, except for a leading '.' in the cookie domain.
    // E.g. cookie domain is .apple.com and host is apple.com.
    if (cookieDomain[0] == '.' && cookieDomain.find(host) == 1)
        return true;

    return false;
}

static const char* equalDelimiters = "__curlequal__";

static void appendDotIfNeeded(std::string* domain)
{
    // According to RFC6265 we should add dot.
#if 0
    std::string domainBuffer = domain->c_str();
    int dotCount = 0;
    for (size_t i = 0; i < domainBuffer.size(); ++i) {
        if ('.' == domainBuffer[i])
            ++dotCount;
    }

    if (1 == dotCount)
        domain->insert(0, ".");
#else
    if (!domain->empty() && domain->at(0) != '.')
        domain->insert(0, ".");
#endif
}

static void addMatchingCurlCookie(const char* cookie, const std::string& domain, const std::string& path, std::string& cookies, bool httponly)
{
    // Check if the cookie matches domain and path, and is not expired.
    // If so, add it to the list of cookies.
    //
    // Description of the Netscape cookie file format which Curl uses:
    //
    // .netscape.com     TRUE   /  FALSE  946684799   NETSCAPE_ID  100103
    //
    // Each line represents a single piece of stored information. A tab is inserted between each of the fields.
    //
    // From left-to-right, here is what each field represents:
    //
    // domain - The domain that created AND that can read the variable.
    // flag - A TRUE/FALSE value indicating if all machines within a given domain can access the variable. This value is set automatically by the browser, depending on the value you set for domain.
    // path - The path within the domain that the variable is valid for.
    // secure - A TRUE/FALSE value indicating if a secure connection with the domain is needed to access the variable.
    // expiration - The UNIX time that the variable will expire on. UNIX time is defined as the number of seconds since Jan 1, 1970 00:00:00 GMT.
    // name - The name of the variable.
    // value - The value of the variable.

    if (!cookie)
        return;

    std::string cookieDomain;
    readCurlCookieToken(cookie, cookieDomain);

    bool subDomain = false;

    // HttpOnly cookie entries begin with "#HttpOnly_".
    if (base::StartsWith(cookieDomain, "#HttpOnly_")) {
        if (httponly)
            cookieDomain.erase(0, 10);
        else
            return;
    }

    if (!domainMatch(cookieDomain, domain))
        return;

    std::string strBoolean;
    readCurlCookieToken(cookie, strBoolean);

    std::string strPath;
    readCurlCookieToken(cookie, strPath);

    // Check if path matches
    //if (!path.isEmpty())
    {
        int index = path.find(strPath);
        if (index)
            return;
    }

    std::string strSecure;
    readCurlCookieToken(cookie, strSecure);

    std::string strExpires;
    readCurlCookieToken(cookie, strExpires);

    int expires = 0;
    base::StringToInt(strExpires, &expires);
    //int expires = strExpires.toInt();

    time_t now = 0;
    time(&now);

    // Check if cookie has expired
    if (expires != 0 && (now > expires))
        return;

    std::string strName;
    readCurlCookieToken(cookie, strName);

    std::string strValue;
    readCurlCookieToken(cookie, strValue);

    // The cookie matches, add it to the cookie list.

    if (cookies.length() > 0)
        cookies.append("; ");

    cookies.append(strName);
    cookies.append("=");
    cookies.append(strValue);
}

const char replaceEqualSing = (char)0x6;

static std::string fixEqualSignInValue(std::string* value)
{
    bool isOver = false;
    for (size_t i = 0; i < value->size() && !isOver; ++i) {
        char c = value->at(i);
        if ('\"' != c)
            continue;

        for (size_t j = i + 1; j < value->size(); ++j) {
            c = value->at(j);
            if ('=' == c) {
                (*value)[j] = replaceEqualSing;
            } else if ('\"' == c) {
                isOver = true;
                break;
            }
        }
    }
    return std::string(value->c_str(), value->size());
}

static std::string restoreEqualSignInValue(const std::string& value)
{
    std::vector<char> result;
    for (size_t i = 0; i < value.length(); ++i) {
        char c = value[i];
        result.push_back(replaceEqualSing == c ? '=' : c);
    }
    return std::string(result.data(), result.size());
}

static std::vector<std::string> splitAttribute(const std::string& attribute)
{
    std::vector<std::string> keyValuePair;
    if (attribute.empty())
        return keyValuePair;

    if (attribute.length() < 2)
        return keyValuePair;

    size_t pos = attribute.find('=');
    if (std::string::npos == pos)
        return keyValuePair;

    if (attribute.length() - 1 == pos)
        return keyValuePair;

    std::string key = attribute.substr(0, pos);
    std::string value = attribute.substr(pos + 1);

    if (key.empty() || value.empty())
        return keyValuePair;

    keyValuePair.push_back(key);
    keyValuePair.push_back(value);

    return keyValuePair;
}

static std::string getNetscapeCookieFormat(const blink::KURL& url, const std::string& value)
{
    // Constructs a cookie string in Netscape Cookie file format.
    if (value.empty())
        return "";

    std::string valueBuf = value;
    std::string valueStr = fixEqualSignInValue(&valueBuf);

    std::vector<std::string_view> attributes;
    //valueStr.split(';', false, attributes);
    attributes = base::SplitStringPiece(std::string_view(valueStr), std::string_view(";"), base::KEEP_WHITESPACE, base::SPLIT_WANT_NONEMPTY);

    if (0 == attributes.size())
        return "";

    // First attribute should be <cookiename>=<cookievalue>
    std::string cookieName, cookieValue;
    std::vector<std::string_view>::iterator attribute = attributes.begin();
    std::string attr = (std::string)(*attribute);

    int equalCount = 0;
    int firstEqualPos = -1;
    for (unsigned int i = 0; i < attr.length(); ++i) {
        if (attr[i] == '=') {
            ++equalCount;
            if (-1 == firstEqualPos)
                firstEqualPos = i;
        }
    }

    if (equalCount > 0) { // ssxmod_itna=xxx=xxxx;
        if (firstEqualPos == 0) // 如果等于号在第一位，直接判断为无效cookie
            return "";

        cookieName = attr.substr(0, firstEqualPos);
        if (attr.length() - 1 != firstEqualPos) { // 如果等于号在最末尾，则判断value是空的
            cookieValue = attr.substr(firstEqualPos + 1);
        }

        //         int lastIsEqualCount = 0;
        //         if (1 < equalCount) { // X_HTTP_TOKEN=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;
        //             for (int i = 0; i < 2; ++i) {
        //                 if (attr[attr.length() - 1] == '=') {
        //                     attr.remove(attr.length() - 1, 1);
        //                     lastIsEqualCount++;
        //                 }
        //             }
        //         }
        //
        //         Vector<std::string> nameValuePair;
        //         attr.split('=', true, nameValuePair);
        //         cookieName = nameValuePair[0];
        //
        //         if (2 < nameValuePair.size() && 0 == lastIsEqualCount) {
        //             for (size_t i = 1; i < nameValuePair.size() - 1; ++i) {
        //                 cookieName.append('='); // equalDelimiters
        //                 cookieName.append(nameValuePair[i]);
        //             }
        //         }
        //         cookieValue = nameValuePair.last();
        //         for (int i = 0; i < lastIsEqualCount; ++i)
        //             cookieValue.append('=');
    } else {
        // According to RFC6265 we should ignore the entire
        // set-cookie string now, but other browsers appear
        // to treat this as <cookiename>=<empty>
        cookieName = (std::string)(*attribute);
    }

    int expires = 0;
    std::string secure = "FALSE";
    std::string path = url.BaseAsString().ToString().Substring(url.PathStart()).Utf8();
    if (path.length() > 1 && base::EndsWith(path, "/"))
        path.erase(path.length() - 1);
    std::string domain = url.Host().Utf8();

    // Iterate through remaining attributes
    for (++attribute; attribute != attributes.end(); ++attribute) {
        std::vector<std::string> keyValuePair = splitAttribute((std::string)(*attribute));
        if (/*attribute->contains('=')*/ keyValuePair.size() == 2) {
            //attribute->split('=', true, keyValuePair);

            //             std::string key = keyValuePair[0].stripWhiteSpace().lower();
            //             std::string val = keyValuePair[1].stripWhiteSpace();
            std::string key;
            std::string val;
            base::TrimWhitespaceASCII(keyValuePair[0], base::TRIM_ALL, &key);
            key = base::ToLowerASCII(key);

            base::TrimWhitespaceASCII(keyValuePair[1], base::TRIM_ALL, &val);

            if (key == "expires") {
                std::optional<base::Time> expiresTime = WTF::ParseDateFromNullTerminatedCharacters(val.c_str());
                double expiresDouble = 0;
                if (expiresTime.has_value())
                    expiresDouble = expiresTime->InSecondsFSinceUnixEpoch();
                //expiresDouble = expiresDouble / WTF::kMsPerSecond;
                expires = (int)expiresDouble;

            } else if (key == "max-age") {
                int valInt = 0;
                base::StringToInt(val, &valInt);
                expires = time(0) + valInt;
            } else if (key == "domain")
                domain = val;
            else if (key == "path")
                path = val;
        } else {
            //std::string key = attribute->stripWhiteSpace().lower();
            std::string keyStr;
            base::TrimWhitespaceASCII(*attribute, base::TRIM_ALL, &keyStr);
            keyStr = base::ToLowerASCII(keyStr);

            if (keyStr == "secure")
                secure = "TRUE";
        }
    }

    if (expires < 0)
        expires = std::numeric_limits<__int32>::max();

    appendDotIfNeeded(&domain);
    std::string allowSubdomains = base::StartsWith(domain, ".") ? "TRUE" : "FALSE";
    std::string expiresStr = base::NumberToString(expires);

    int finalStringLength = domain.length() + path.length() + expiresStr.length() + cookieName.length();
    finalStringLength += cookieValue.length() + secure.length() + allowSubdomains.length();
    finalStringLength += 6; // Account for \t separators.

    std::string cookieStr;
    //cookieStr.reserveCapacity(finalStringLength);
    cookieStr += (/*StringView*/ (domain));
    cookieStr += ("\t");
    cookieStr += (/*StringView*/ (allowSubdomains));
    cookieStr += ("\t");
    cookieStr += (/*StringView*/ (path));
    cookieStr += ("\t");
    cookieStr += (/*StringView*/ (secure));
    cookieStr += ("\t");
    cookieStr += (/*StringView*/ (expiresStr));
    cookieStr += ("\t");
    cookieStr += (/*StringView*/ (cookieName));
    cookieStr += ("\t");
    cookieStr += (/*StringView*/ (restoreEqualSignInValue(cookieValue)));

    return cookieStr /*.toString()*/;
}

void WebCookieJarImpl::setCookiesFromDOM(const blink::KURL&, const blink::KURL& url, const std::string& value)
{
    // CURL accepts cookies in either Set-Cookie or Netscape file format.
    // However with Set-Cookie format, there is no way to specify that we
    // should not allow cookies to be read from subdomains, which is the
    // required behavior if the domain field is not explicity specified.
    std::string cookie = getNetscapeCookieFormat(url, value);
    //cookie = WTF::ensureStringToUTF8String(cookie);
    //CString strCookie(reinterpret_cast<const char*>(cookie.characters8()), cookie.length());

    CURL* curl = curl_easy_init();
    CURLSH* curlsh = m_curlShareHandle;
    curl_easy_setopt(curl, CURLOPT_SHARE, curlsh);
    curl_easy_setopt(curl, CURLOPT_COOKIELIST, cookie.c_str());
    curl_easy_cleanup(curl);

    m_dirty = true;
}

const curl_slist* WebCookieJarImpl::getAllCookiesBegin()
{
    CURL* curl = curl_easy_init();
    if (!curl)
        return nullptr;

    flushCurlCookie(curl);
    CURLSH* curlsh = m_curlShareHandle;

    curl_easy_setopt(curl, CURLOPT_SHARE, curlsh);

    curl_slist* list = nullptr;
    curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &list);
    curl_easy_cleanup(curl);
    return list;
}

void WebCookieJarImpl::getAllCookiesEnd(const curl_slist* list)
{
    curl_slist_free_all((curl_slist*)list);
}

void WebCookieJarImpl::visitAllCookie(void* params, CookieVisitor visit)
{
    if (!mbnet::WebURLLoaderManager::sharedInstance())
        return;

    CURL* curl = curl_easy_init();
    if (!curl)
        return;

    flushCurlCookie(curl);

    CURLSH* curlsh = m_curlShareHandle;
    curl_easy_setopt(curl, CURLOPT_SHARE, curlsh);

    curl_slist* list = nullptr;
    curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &list);

    if (!list) {
        curl_easy_cleanup(curl);
        return;
    }

    std::vector<std::string> needDeleteCookies;

    struct curl_slist* item = list;
    while (item) {
        const char* cookie = item->data;

        std::string cookieDomain;
        std::string domain;
        readCurlCookieToken(cookie, cookieDomain);
        domain = cookieDomain;
        bool isHttponly = base::StartsWith(cookieDomain, "#HttpOnly_");
        if (isHttponly)
            domain.erase(0, 10);

        std::string strBoolean;
        readCurlCookieToken(cookie, strBoolean);

        std::string strPath;
        readCurlCookieToken(cookie, strPath);

        std::string strSecure;
        readCurlCookieToken(cookie, strSecure);

        std::string strExpires;
        readCurlCookieToken(cookie, strExpires);

        int expires = 0;
        base::StringToInt(strExpires, &expires);
        //int expires = strExpires.toInt();
        int secure = (strSecure == "TRUE" ? 1 : 0);

        std::string strName;
        readCurlCookieToken(cookie, strName);

        std::string strValue;
        readCurlCookieToken(cookie, strValue);

        bool isDelete
            = visit(params, strName.c_str(), strValue.c_str(), domain.c_str(), strPath.c_str(), secure, isHttponly, strExpires.empty() ? nullptr : &expires);
        if (isDelete) {
            //std::string deleteCooie = "Set-cookie: " + strName + "=none;expires=Monday, 13-Jun-1988 03:04:55 GMT; domain=" + cookieDomain + "; path=/;";
            std::string deleteCooie = cookieDomain;
            deleteCooie.append("\t");
            deleteCooie.append(strBoolean);
            deleteCooie.append("\t");
            deleteCooie.append(strPath);
            deleteCooie.append("\t");
            deleteCooie.append(strSecure);
            deleteCooie.append("\t");
            deleteCooie.append("123");
            deleteCooie.append("\t");
            deleteCooie.append(strName);
            deleteCooie.append("\t");
            deleteCooie.append("none");
            needDeleteCookies.push_back(deleteCooie);
        }

        item = item->next;
    }

    for (size_t i = 0; i < needDeleteCookies.size(); ++i) {
        std::string deleteCooie = needDeleteCookies[i];
        curl_easy_setopt(curl, CURLOPT_COOKIELIST, deleteCooie.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_COOKIELIST, "Set-cookie: __deleteCookie__=none;expires=Monday, 13-Jun-1988 03:04:55 GMT; domain=testmbcookie.com");

    curl_slist_free_all(list);
    curl_easy_cleanup(curl);
}

struct CookieVisitorForDeleteInfo {
    blink::KURL url;
    std::string cookieName;
};

static bool cookieVisitorForDelete(
    void* params, const char* name, const char* value, const char* domain, const char* path, int secure, int httpOnly, int* expires)
{
    CookieVisitorForDeleteInfo* info = (CookieVisitorForDeleteInfo*)params;
    if (domainMatch(domain, info->url.Host().Utf8()))
        return true;
    return false;
}

void WebCookieJarImpl::deleteCookies(const blink::KURL& url, const std::string& cookieName)
{
    CookieVisitorForDeleteInfo info;
    info.url = url;
    info.cookieName = cookieName;
    visitAllCookie(&info, cookieVisitorForDelete);
}

void WebCookieJarImpl::flushCurlCookie(CURL* curl)
{
    if (!m_dirty)
        return;
    m_dirty = false;

    bool needCleanup = false;
    if (!curl) {
        needCleanup = true;
        curl = curl_easy_init();
    }
    std::string cookieJarFullPath = getCookieJarFullPath();
    if (cookieJarFullPath.empty())
        return;

    curl_easy_setopt(curl, CURLOPT_SHARE, m_curlShareHandle);
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, cookieJarFullPath.c_str());
    curl_easy_setopt(curl, CURLOPT_COOKIELIST, "FLUSH");

    if (needCleanup)
        curl_easy_cleanup(curl);
}

void WebCookieJarImpl::getAllCookies(const ::blink::KURL& url, const ::net::SiteForCookies& siteForCookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& topFrameOrigin, ::net::StorageAccessApiStatus storageAccessApiStatus,
    ::network::mojom::blink::CookieManagerGetOptionsPtr options,
    bool partitionedCookiesRuntimeFeatureEnabled, bool isAdTagged, 
    network::mojom::blink::RestrictedCookieManager::GetAllForUrlCallback callback)
{
    CURL* curl = curl_easy_init();
    if (!curl)
        return;

    flushCurlCookie(curl);

    CURLSH* curlsh = m_curlShareHandle;

    curl_easy_setopt(curl, CURLOPT_SHARE, curlsh);

    curl_slist* list = nullptr;
    curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &list);

    WTF::Vector<::network::mojom::blink::CookieWithAccessResultPtr> results;

    if (list) {
        std::string domain = url.Host().Utf8();
        std::string path = url.GetPath().Utf8();
        std::string cookiesBuilder;

        struct curl_slist* item = list;
        while (item) {
            const char* cookieLine = item->data;
            addMatchingCurlCookie(cookieLine, domain, path, cookiesBuilder, true);
            item = item->next;
            if (cookiesBuilder.empty())
                continue;

            network::mojom::blink::CookieWithAccessResultPtr result = network::mojom::blink::CookieWithAccessResult::New();

            net::CookieInclusionStatus status;
            std::unique_ptr<net::CanonicalCookie> canonCookie = ::net::CanonicalCookie::Create(
                (GURL)url, cookiesBuilder, base::Time::Now(),
                std::nullopt, std::nullopt, net::CookieSourceType::kHTTP, &status);
            if (!canonCookie.get())
                continue;
            result->cookie = *(canonCookie.get());
            result->access_result = ::network::mojom::blink::CookieAccessResult::New();
            results.push_back(std::move(result));
        }

        curl_slist_free_all(list);
    }

    curl_easy_cleanup(curl);

    std::move(callback).Run(std::move(results));
}

std::string WebCookieJarImpl::getCookiesForSession(const blink::KURL& kurl, const blink::KURL& url, bool httponly)
{
    std::string cookies;
    CURL* curl = curl_easy_init();
    if (!curl)
        return cookies;

    flushCurlCookie(curl);

    CURLSH* curlsh = m_curlShareHandle;

    curl_easy_setopt(curl, CURLOPT_SHARE, curlsh);

    curl_slist* list = nullptr;
    curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &list);

    if (list) {
        std::string domain = url.Host().Utf8();
        std::string path = url.GetPath().Utf8();
        std::string cookiesBuilder;

        struct curl_slist* item = list;
        while (item) {
            const char* cookie = item->data;
            addMatchingCurlCookie(cookie, domain, path, cookiesBuilder, httponly);
            item = item->next;
        }

        cookies = cookiesBuilder;
        curl_slist_free_all(list);
    }

    curl_easy_cleanup(curl);

    return cookies;
}

WebCookieJarImpl* WebCookieJarImpl::create(const std::string& cookieJarFullPath)
{
    return new WebCookieJarImpl(cookieJarFullPath);
}

WebCookieJarImpl::WebCookieJarImpl(const std::string& cookieJarFullPath)
{
    m_curlShareHandle = curl_share_init();
    curl_share_setopt(m_curlShareHandle, CURLSHOPT_SHARE, CURL_LOCK_DATA_COOKIE);
    curl_share_setopt(m_curlShareHandle, CURLSHOPT_SHARE, CURL_LOCK_DATA_DNS);
    curl_share_setopt(m_curlShareHandle, CURLSHOPT_LOCKFUNC, curl_lock_callback);
    curl_share_setopt(m_curlShareHandle, CURLSHOPT_UNLOCKFUNC, curl_unlock_callback);

    m_cookieJarFileName = cookieJarFullPath;
    m_dirty = false;
}

WebCookieJarImpl::~WebCookieJarImpl()
{
    if (m_curlShareHandle)
        curl_share_cleanup(m_curlShareHandle);
}

// void WebCookieJarImpl::setCookieJarFullPath(const char* path)
// {
//     WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
//     WTF::Locker<WTF::RecursiveMutex> locker(*mutex);
//
//     if (!path)
//         return;
//
//     m_cookieJarFileName = path;// std::string(&jarPathA[0], jarPathA.size());
//     m_dirty = true;
// }

std::string WebCookieJarImpl::getCookieJarFullPath()
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    flushCurlCookie(nullptr);
    return m_cookieJarFileName;
}

//----WebCookieJar----

// void WebCookieJarImpl::setCookie(const WebURL& webUrl, const WebURL& webFirstPartyForCookies, const WebString& webCookie)
// {
//     setCookiesFromDOM(webFirstPartyForCookies, webUrl, webCookie);
// }
//
// WebString WebCookieJarImpl::cookies(const WebURL& webUrl, const WebURL& webFirstPartyForCookies)
// {
//     return getCookiesForSession(webFirstPartyForCookies, webUrl, false);
// }
//
std::string WebCookieJarImpl::cookieRequestHeaderFieldValue(const blink::WebURL& webUrl, const blink::WebURL& webFirstPartyForCookies)
{
    return getCookiesForSession(webFirstPartyForCookies, webUrl, false);
}
//
// void WebCookieJarImpl::setToRecordFromRawHeads(const KURL& url, const std::string& rawHeadsString)
// {
//     DebugBreak();
// }
//
// void WebCookieJarImpl::setCookieFromWinINet(const KURL& url, const Vector<char>& cookiesLine)
// {
//     DebugBreak();
// }

} // namespace content