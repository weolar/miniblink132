
#ifndef mbnet_PageNetExtraData_h
#define mbnet_PageNetExtraData_h

#include "base/memory/ref_counted.h"
#include "base/files/file_path.h"
#include "mbnet/StorageDef.h"
#include <string>

typedef void CURL;
typedef void CURLSH;
typedef struct _mbProxy mbProxy;

namespace blink {
class WebStorageNamespace;
}

namespace mbnet {

class WebCookieJarImpl;
class WebStorageNamespaceImpl;

class PageNetExtraData : public base::RefCountedThreadSafe<PageNetExtraData> {
public:
    PageNetExtraData();
    ~PageNetExtraData();

    void setCookieJarFullPath(const std::string& fullPathUtf8);
    CURLSH* getCurlShareHandle();
    std::string getCookieJarFullPath();
    base::FilePath getDownloadDirPath();

    WebCookieJarImpl* getCookieJar() const
    {
        return m_cookieJar;
    }

    void setLocalStorageDir(const std::string& localStorageDir);
    base::FilePath getLocalStorageDir();

    void setProxy(const mbProxy* proxy);
    const mbProxy* getProxy() const;

private:
    mbProxy* m_proxy = nullptr;

    WebCookieJarImpl* m_cookieJar;
    base::FilePath m_localStotageFullPath;
    base::FilePath m_downloadDirPath;
};

}

#endif // net_PageCookie_h