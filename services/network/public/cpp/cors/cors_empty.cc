// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/network/public/cpp/cors/cors.h"

#include <cctype>
#include <set>
#include <vector>

#include "base/strings/string_util.h"
// #include "base/containers/contains.h"
// #include "base/containers/fixed_flat_set.h"
// #include "base/metrics/histogram_functions.h"
// #include "base/ranges/algorithm.h"
// #include "base/strings/string_piece.h"
// #include "base/strings/string_util.h"
// #include "net/base/mime_util.h"
// #include "net/http/http_byte_range.h"
// #include "net/http/http_request_headers.h"
// #include "net/http/http_util.h"
// #include "services/network/public/cpp/is_potentially_trustworthy.h"
// #include "services/network/public/cpp/request_mode.h"
#include "url/gurl.h"
#include "url/origin.h"
#include "url/url_constants.h"
#include "url/url_util.h"

// String conversion from blink::String to std::string for header name/value
// should be latin-1, not utf-8, as per HTTP. Note that as we use ByteString
// as the IDL types of header name/value, a character whose code point is
// greater than 255 has already been blocked.

namespace network {

namespace cors {

bool ShouldCheckCors(const GURL& request_url, const std::optional<url::Origin>& request_initiator, mojom::RequestMode request_mode)
{
    if (request_mode == network::mojom::RequestMode::kNavigate || request_mode == network::mojom::RequestMode::kNoCors) {
        return false;
    }

    // CORS needs a proper origin (including a unique opaque origin). If the
    // request doesn't have one, CORS should not work.
    DCHECK(request_initiator);

    if (request_initiator->IsSameOriginWith(request_url))
        return false;
    return true;
}

std::vector<std::string> CorsUnsafeRequestHeaderNames(std::vector<net::HttpRequestHeaders::HeaderKeyValuePair> const&)
{
    return std::vector<std::string>();
}

std::vector<std::string> PrivilegedNoCorsHeaderNames(void)
{
    return std::vector<std::string>();
}

bool IsCorsCrossOriginResponseType(network::mojom::FetchResponseType)
{
    *(int*)1 = 1;
    return false;
}

bool IsCorsEnabledRequestMode(network::mojom::RequestMode mode)
{
    return mode == mojom::RequestMode::kCors ||
        mode == mojom::RequestMode::kCorsWithForcedPreflight;
}

bool IsCorsSafelistedContentType(std::string const&)
{
    *(int*)1 = 1;
    return false;
}

bool IsCorsSafelistedHeader(std::string const&, std::string const&)
{
    *(int*)1 = 1;
    return false;
}

bool IsCorsSafelistedMethod(std::string const&) // "https://www.runoob.com/http/http-content-type.html"; // 测试案例
{
    return true;
}

bool IsCorsSameOriginResponseType(network::mojom::FetchResponseType)
{
    //     static bool s_once = false;
    //     if (!s_once)
    //         OutputDebugStringA("IsCorsSameOriginResponseType not impl\n");
    //     s_once = true;
    return true;
}

bool IsForbiddenMethod(const std::string& method)
{
    //     if (base::EqualsCaseInsensitiveASCII(method, "get"))
    //         return false;
    //     return true;
    return false;
}
bool IsNoCorsSafelistedHeader(std::string const&, std::string const&)
{
    return true;
}
bool IsNoCorsSafelistedHeaderName(std::string const&)
{
    *(int*)1 = 1;
    return false;
}
bool IsPrivilegedNoCorsHeaderName(std::string const&)
{
    *(int*)1 = 1;
    return false;
}

} // namespace cors

} // namespace network
