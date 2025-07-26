
#ifndef net_WebURLLoaderManagerUtil_h
#define net_WebURLLoaderManagerUtil_h

// #include "third_party/WebKit/Source/wtf/RefCountedLeakCounter.h"
// #include "third_party/WebKit/Source/wtf/text/CString.h"
// #include "third_party/WebKit/Source/wtf/text/WTFStringUtil.h"
#include "third_party/libcurl/include/curl/curl.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
// #include "wke/wkedefine.h"

namespace base {
class Lock;
}

namespace WTF {
class RecursiveMutex;
}

namespace mbnet {

const int selectTimeoutMS = 5;
const double pollTimeSeconds = 0.05;
const int maxRunningJobs = 5;

const bool ignoreSSLErrors = true; //  ("WEBKIT_IGNORE_SSL_ERRORS");
const int kAllowedProtocols = CURLPROTO_FILE | CURLPROTO_FTP | CURLPROTO_FTPS | CURLPROTO_HTTP | CURLPROTO_HTTPS;

//CString certificatePath();

// libcurl does not implement its own thread synchronization primitives.
// these two functions provide mutexes for cookies, and for the global DNS
// cache.
WTF::RecursiveMutex* sharedResourceMutex(curl_lock_data data);

void curl_lock_callback(CURL* /* handle */, curl_lock_data data, curl_lock_access /* access */, void* /* userPtr */);
void curl_unlock_callback(CURL* /* handle */, curl_lock_data data, void* /* userPtr */);

inline static bool isHttpInfo(int statusCode)
{
    return 100 <= statusCode && statusCode < 200;
}

inline static bool isHttpRedirect(int statusCode)
{
    return 300 <= statusCode && statusCode < 400 && statusCode != 304;
}

inline static bool isHttpAuthentication(int statusCode)
{
    return statusCode == 401;
}

inline static bool isHttpNotModified(int statusCode)
{
    return statusCode == 304;
}

bool isAppendableHeader(const String& key);

#if ENABLE_WKE == 1
int getFavicon(wkeWebView webView, wkeOnNetGetFaviconCallback callback, void* param);
#endif
}

#endif // net_WebURLLoaderManagerUtil_h