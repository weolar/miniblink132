// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/network/public/cpp/is_potentially_trustworthy.h"

#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

#include "base/command_line.h"
#include "base/containers/contains.h"
#include "base/logging.h"
#include "base/metrics/histogram_macros.h"
#include "base/no_destructor.h"
#include "base/numerics/checked_math.h"
#include "base/sequence_checker.h"
#include "base/strings/pattern.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include "base/strings/stringprintf.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
#include "net/base/ip_address.h"
#include "net/base/registry_controlled_domains/registry_controlled_domain.h"
#include "net/base/url_util.h"
#include "services/network/public/cpp/network_switches.h"
#include "third_party/abseil-cpp/absl/types/optional.h"
#include "url/origin.h"
#include "url/scheme_host_port.h"
#include "url/url_canon.h"
#include "url/url_canon_ip.h"
#include "url/url_canon_stdstring.h"
#include "url/url_constants.h"
#include "url/url_util.h"

namespace network {

namespace {

bool IsSchemeConsideredAuthenticated(std::string_view scheme)
{
    // The code below is based on the specification at
    // https://w3c.github.io/webappsec-secure-contexts/#potentially-trustworthy-origin

    // 7. If origin’s scheme component is one which the user agent considers to be
    //    authenticated, return "Potentially Trustworthy".
    //    Note: See §7.1 Packaged Applications for detail here.
    //
    // Note that this ignores some schemes that are considered trustworthy by
    // higher layers (e.g. see GetSchemesBypassingSecureContextCheck in //chrome).
    //
    // See also
    // - content::ContentClient::AddAdditionalSchemes and
    //   content::ContentClient::Schemes::local_schemes and
    //   content::ContentClient::Schemes::secure_schemes
    // - url::AddLocalScheme
    // - url::AddSecureScheme
    return base::Contains(url::GetSecureSchemes(), scheme) || base::Contains(url::GetLocalSchemes(), scheme);
}

}

bool IsOriginPotentiallyTrustworthy(const url::Origin& origin)
{
    // The code below is based on the specification at
    // https://w3c.github.io/webappsec-secure-contexts/#potentially-trustworthy-origin

    // 1. If origin is an opaque origin, return "Not Trustworthy".
    if (origin.opaque())
        return false;

    // 2. Assert: origin is a tuple origin.
    DCHECK(!origin.opaque());

    // 3. If origin’s scheme is either "https" or "wss", return "Potentially
    //    Trustworthy".
    // This is somewhat redundant with the GetSecureSchemes()-based check below.
    if (GURL::SchemeIsCryptographic(origin.scheme()))
        return true;

    // 4. If origin’s host component matches one of the CIDR notations 127.0.0.0/8
    //    or ::1/128 [RFC4632], return "Potentially Trustworthy".
    // 5. If origin’s host component is "localhost" or falls within ".localhost",
    //    and the user agent conforms to the name resolution rules in
    //    [let-localhost-be-localhost], return "Potentially Trustworthy".
    if (net::IsLocalhost(origin.GetURL()))
        return true;

    // 6. If origin’s scheme component is file, return "Potentially Trustworthy".
    //
    // This is somewhat redundant with the GetLocalSchemes-based
    // IsSchemeConsideredAuthenticated check below.
    if (origin.scheme() == url::kFileScheme)
        return true;

    // 7. If origin’s scheme component is one which the user agent considers to be
    //    authenticated, return "Potentially Trustworthy".
    //    Note: See §7.1 Packaged Applications for detail here.
    if (IsSchemeConsideredAuthenticated(origin.scheme()))
        return true;

    // 8. If origin has been configured as a trustworthy origin, return
    //    "Potentially Trustworthy".
    //    Note: See §7.2 Development Environments for detail here.
    //     if (SecureOriginAllowlist::GetInstance().IsOriginAllowlisted(origin))
    //         return true;

    // 9. Return "Not Trustworthy".
    return false;
}

bool IsUrlPotentiallyTrustworthy(const GURL& url)
{
    // The code below is based on the specification at
    // https://w3c.github.io/webappsec-secure-contexts/#potentially-trustworthy-url

    // 1. If url is "about:blank" or "about:srcdoc", return "Potentially
    //    Trustworthy".
    if (url.IsAboutBlank() || url.IsAboutSrcdoc())
        return true;

    // 2. If url’s scheme is "data", return "Potentially Trustworthy".
    if (url.SchemeIs(url::kDataScheme))
        return true;

    // 3. Return the result of executing §3.2 Is origin potentially trustworthy?
    //    on url’s origin.
    //    Note: The origin of blob: and filesystem: URLs is the origin of the
    //    context in which they were created. Therefore, blobs created in a
    //    trustworthy origin will themselves be potentially trustworthy.
    url::Origin origin = url::Origin::Create(url);
    if (origin.opaque() && IsSchemeConsideredAuthenticated(url.scheme_piece())) {
        // Authenticated schemes should be treated as trustworthy, even if they
        // translate into an opaque origin (e.g. because some of them might also be
        // registered as a no-access, like the //content-layer chrome-error:// or
        // the //chrome-layer chrome-native://).
        return true;
    }
    return IsOriginPotentiallyTrustworthy(origin);
}

} // namespace network
