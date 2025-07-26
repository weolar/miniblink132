
#ifndef net_ProxyType_h
#define net_ProxyType_h

#include "third_party/libcurl/include/curl/curl.h"

namespace mbnet {

enum ProxyType {
    kProxyTypeHTTP = CURLPROXY_HTTP,
    kProxyTypeSocks4 = CURLPROXY_SOCKS4,
    kProxyTypeSocks4A = CURLPROXY_SOCKS4A,
    kProxyTypeSocks5 = CURLPROXY_SOCKS5,
    kProxyTypeSocks5Hostname = CURLPROXY_SOCKS5_HOSTNAME
};

}

#endif // net_ProxyType_h