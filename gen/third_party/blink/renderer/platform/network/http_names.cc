// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/network/http_names.json5

#include "third_party/blink/renderer/platform/network/http_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace http_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kAccept = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kAcceptCH = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kAcceptLanguage = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kAccessControlAllowCredentials = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kAccessControlAllowExternal = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kAccessControlAllowHeaders = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kAccessControlAllowMethods = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kAccessControlAllowOrigin = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kAccessControlExposeHeaders = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kAccessControlMaxAge = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kAccessControlRequestExternal = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kAccessControlRequestHeaders = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kAccessControlRequestMethod = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kAllowCSPFrom = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kAttributionReportingInfo = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kAttributionReportingRegisterOSSource = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kAttributionReportingRegisterOSTrigger = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kAttributionReportingRegisterSource = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kAttributionReportingRegisterTrigger = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kAuthorization = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kCacheControl = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kContentDPR = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kContentDisposition = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kContentEncoding = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kContentLanguage = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kContentSecurityPolicy = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kContentSecurityPolicyReportOnly = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kContentType = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kDELETE = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kDate = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kDelegateCH = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kDocumentPolicy = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kDocumentPolicyReportOnly = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kETag = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kExpectCT = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kExpires = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kFeaturePolicy = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kFeaturePolicyReportOnly = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kGET = reinterpret_cast<AtomicString*>(&names_storage)[38];
const AtomicString& kHEAD = reinterpret_cast<AtomicString*>(&names_storage)[39];
const AtomicString& kIfMatch = reinterpret_cast<AtomicString*>(&names_storage)[40];
const AtomicString& kIfModifiedSince = reinterpret_cast<AtomicString*>(&names_storage)[41];
const AtomicString& kIfNoneMatch = reinterpret_cast<AtomicString*>(&names_storage)[42];
const AtomicString& kIfRange = reinterpret_cast<AtomicString*>(&names_storage)[43];
const AtomicString& kIfUnmodifiedSince = reinterpret_cast<AtomicString*>(&names_storage)[44];
const AtomicString& kLastEventID = reinterpret_cast<AtomicString*>(&names_storage)[45];
const AtomicString& kLastModified = reinterpret_cast<AtomicString*>(&names_storage)[46];
const AtomicString& kLink = reinterpret_cast<AtomicString*>(&names_storage)[47];
const AtomicString& kLocation = reinterpret_cast<AtomicString*>(&names_storage)[48];
const AtomicString& kNoVarySearch = reinterpret_cast<AtomicString*>(&names_storage)[49];
const AtomicString& kOPTIONS = reinterpret_cast<AtomicString*>(&names_storage)[50];
const AtomicString& kOrigin = reinterpret_cast<AtomicString*>(&names_storage)[51];
const AtomicString& kOriginAgentCluster = reinterpret_cast<AtomicString*>(&names_storage)[52];
const AtomicString& kOriginTrial = reinterpret_cast<AtomicString*>(&names_storage)[53];
const AtomicString& kPOST = reinterpret_cast<AtomicString*>(&names_storage)[54];
const AtomicString& kPUT = reinterpret_cast<AtomicString*>(&names_storage)[55];
const AtomicString& kPermissionsPolicy = reinterpret_cast<AtomicString*>(&names_storage)[56];
const AtomicString& kPermissionsPolicyReportOnly = reinterpret_cast<AtomicString*>(&names_storage)[57];
const AtomicString& kPingFrom = reinterpret_cast<AtomicString*>(&names_storage)[58];
const AtomicString& kPingTo = reinterpret_cast<AtomicString*>(&names_storage)[59];
const AtomicString& kPragma = reinterpret_cast<AtomicString*>(&names_storage)[60];
const AtomicString& kRange = reinterpret_cast<AtomicString*>(&names_storage)[61];
const AtomicString& kReferer = reinterpret_cast<AtomicString*>(&names_storage)[62];
const AtomicString& kReferrerPolicy = reinterpret_cast<AtomicString*>(&names_storage)[63];
const AtomicString& kRefresh = reinterpret_cast<AtomicString*>(&names_storage)[64];
const AtomicString& kRequireDocumentPolicy = reinterpret_cast<AtomicString*>(&names_storage)[65];
const AtomicString& kResourceFreshness = reinterpret_cast<AtomicString*>(&names_storage)[66];
const AtomicString& kSaveData = reinterpret_cast<AtomicString*>(&names_storage)[67];
const AtomicString& kSecPurpose = reinterpret_cast<AtomicString*>(&names_storage)[68];
const AtomicString& kSecSharedStorageWritable = reinterpret_cast<AtomicString*>(&names_storage)[69];
const AtomicString& kServerTiming = reinterpret_cast<AtomicString*>(&names_storage)[70];
const AtomicString& kSourceMap = reinterpret_cast<AtomicString*>(&names_storage)[71];
const AtomicString& kSpeculationRules = reinterpret_cast<AtomicString*>(&names_storage)[72];
const AtomicString& kTimingAllowOrigin = reinterpret_cast<AtomicString*>(&names_storage)[73];
const AtomicString& kUpgradeInsecureRequests = reinterpret_cast<AtomicString*>(&names_storage)[74];
const AtomicString& kUserAgent = reinterpret_cast<AtomicString*>(&names_storage)[75];
const AtomicString& kVary = reinterpret_cast<AtomicString*>(&names_storage)[76];
const AtomicString& kXContentTypeOptions = reinterpret_cast<AtomicString*>(&names_storage)[77];
const AtomicString& kXDNSPrefetchControl = reinterpret_cast<AtomicString*>(&names_storage)[78];
const AtomicString& kXFrameOptions = reinterpret_cast<AtomicString*>(&names_storage)[79];
const AtomicString& kXSourceMap = reinterpret_cast<AtomicString*>(&names_storage)[80];
const AtomicString& kXXSSProtection = reinterpret_cast<AtomicString*>(&names_storage)[81];
const AtomicString& kLowerAge = reinterpret_cast<AtomicString*>(&names_storage)[82];
const AtomicString& kLowerCacheControl = reinterpret_cast<AtomicString*>(&names_storage)[83];
const AtomicString& kLowerContentDisposition = reinterpret_cast<AtomicString*>(&names_storage)[84];
const AtomicString& kLowerContentLength = reinterpret_cast<AtomicString*>(&names_storage)[85];
const AtomicString& kLowerContentRange = reinterpret_cast<AtomicString*>(&names_storage)[86];
const AtomicString& kLowerContentType = reinterpret_cast<AtomicString*>(&names_storage)[87];
const AtomicString& kLowerCrossOriginEmbedderPolicy = reinterpret_cast<AtomicString*>(&names_storage)[88];
const AtomicString& kDark = reinterpret_cast<AtomicString*>(&names_storage)[89];
const AtomicString& kLowerDate = reinterpret_cast<AtomicString*>(&names_storage)[90];
const AtomicString& kDeviceMemory_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[91];
const AtomicString& kDownlink_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[92];
const AtomicString& kDpr_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[93];
const AtomicString& kEct_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[94];
const AtomicString& kLowerETag = reinterpret_cast<AtomicString*>(&names_storage)[95];
const AtomicString& kLowerExpires = reinterpret_cast<AtomicString*>(&names_storage)[96];
const AtomicString& kLowerLastModified = reinterpret_cast<AtomicString*>(&names_storage)[97];
const AtomicString& kLight = reinterpret_cast<AtomicString*>(&names_storage)[98];
const AtomicString& kNoPreference = reinterpret_cast<AtomicString*>(&names_storage)[99];
const AtomicString& kOn = reinterpret_cast<AtomicString*>(&names_storage)[100];
const AtomicString& kLowerPragma = reinterpret_cast<AtomicString*>(&names_storage)[101];
const AtomicString& kLowerRange = reinterpret_cast<AtomicString*>(&names_storage)[102];
const AtomicString& kReduce = reinterpret_cast<AtomicString*>(&names_storage)[103];
const AtomicString& kRtt_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[104];
const AtomicString& kDeviceMemory = reinterpret_cast<AtomicString*>(&names_storage)[105];
const AtomicString& kDpr = reinterpret_cast<AtomicString*>(&names_storage)[106];
const AtomicString& kPrefersColorScheme = reinterpret_cast<AtomicString*>(&names_storage)[107];
const AtomicString& kPrefersReducedMotion = reinterpret_cast<AtomicString*>(&names_storage)[108];
const AtomicString& kPrefersReducedTransparency = reinterpret_cast<AtomicString*>(&names_storage)[109];
const AtomicString& kUA = reinterpret_cast<AtomicString*>(&names_storage)[110];
const AtomicString& kUAArch = reinterpret_cast<AtomicString*>(&names_storage)[111];
const AtomicString& kUABitness = reinterpret_cast<AtomicString*>(&names_storage)[112];
const AtomicString& kUAFormFactors = reinterpret_cast<AtomicString*>(&names_storage)[113];
const AtomicString& kUAFullVersion = reinterpret_cast<AtomicString*>(&names_storage)[114];
const AtomicString& kUAFullVersionList = reinterpret_cast<AtomicString*>(&names_storage)[115];
const AtomicString& kUAMobile = reinterpret_cast<AtomicString*>(&names_storage)[116];
const AtomicString& kUAModel = reinterpret_cast<AtomicString*>(&names_storage)[117];
const AtomicString& kUAPlatform = reinterpret_cast<AtomicString*>(&names_storage)[118];
const AtomicString& kUAPlatformVersion = reinterpret_cast<AtomicString*>(&names_storage)[119];
const AtomicString& kUAWoW64 = reinterpret_cast<AtomicString*>(&names_storage)[120];
const AtomicString& kViewportHeight = reinterpret_cast<AtomicString*>(&names_storage)[121];
const AtomicString& kViewportWidth = reinterpret_cast<AtomicString*>(&names_storage)[122];
const AtomicString& kResourceWidth = reinterpret_cast<AtomicString*>(&names_storage)[123];
const AtomicString& kLowerSetCookie = reinterpret_cast<AtomicString*>(&names_storage)[124];
const AtomicString& kViewportWidth_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[125];
const AtomicString& kResourceWidth_DEPRECATED = reinterpret_cast<AtomicString*>(&names_storage)[126];

void Init()
{
    static bool is_loaded = false;
    if (is_loaded)
        return;
    is_loaded = true;

    struct NameEntry {
        const char* name;
        unsigned char length;
    };

    static const NameEntry kNames[] = {
        { "Accept", 6 },
        { "Accept-CH", 9 },
        { "Accept-Language", 15 },
        { "Access-Control-Allow-Credentials", 32 },
        { "Access-Control-Allow-External", 29 },
        { "Access-Control-Allow-Headers", 28 },
        { "Access-Control-Allow-Methods", 28 },
        { "Access-Control-Allow-Origin", 27 },
        { "Access-Control-Expose-Headers", 29 },
        { "Access-Control-Max-Age", 22 },
        { "Access-Control-Request-External", 31 },
        { "Access-Control-Request-Headers", 30 },
        { "Access-Control-Request-Method", 29 },
        { "Allow-CSP-From", 14 },
        { "Attribution-Reporting-Info", 26 },
        { "Attribution-Reporting-Register-OS-Source", 40 },
        { "Attribution-Reporting-Register-OS-Trigger", 41 },
        { "Attribution-Reporting-Register-Source", 37 },
        { "Attribution-Reporting-Register-Trigger", 38 },
        { "Authorization", 13 },
        { "Cache-Control", 13 },
        { "Content-DPR", 11 },
        { "Content-Disposition", 19 },
        { "Content-Encoding", 16 },
        { "Content-Language", 16 },
        { "Content-Security-Policy", 23 },
        { "Content-Security-Policy-Report-Only", 35 },
        { "Content-Type", 12 },
        { "DELETE", 6 },
        { "Date", 4 },
        { "Delegate-CH", 11 },
        { "Document-Policy", 15 },
        { "Document-Policy-Report-Only", 27 },
        { "ETag", 4 },
        { "Expect-CT", 9 },
        { "Expires", 7 },
        { "Feature-Policy", 14 },
        { "Feature-Policy-Report-Only", 26 },
        { "GET", 3 },
        { "HEAD", 4 },
        { "If-Match", 8 },
        { "If-Modified-Since", 17 },
        { "If-None-Match", 13 },
        { "If-Range", 8 },
        { "If-Unmodified-Since", 19 },
        { "Last-Event-ID", 13 },
        { "Last-Modified", 13 },
        { "Link", 4 },
        { "Location", 8 },
        { "No-Vary-Search", 14 },
        { "OPTIONS", 7 },
        { "Origin", 6 },
        { "Origin-Agent-Cluster", 20 },
        { "Origin-Trial", 12 },
        { "POST", 4 },
        { "PUT", 3 },
        { "Permissions-Policy", 18 },
        { "Permissions-Policy-Report-Only", 30 },
        { "Ping-From", 9 },
        { "Ping-To", 7 },
        { "Pragma", 6 },
        { "Range", 5 },
        { "Referer", 7 },
        { "Referrer-Policy", 15 },
        { "Refresh", 7 },
        { "Require-Document-Policy", 23 },
        { "Resource-Freshness", 18 },
        { "Save-Data", 9 },
        { "Sec-Purpose", 11 },
        { "Sec-Shared-Storage-Writable", 27 },
        { "Server-Timing", 13 },
        { "SourceMap", 9 },
        { "Speculation-Rules", 17 },
        { "Timing-Allow-Origin", 19 },
        { "Upgrade-Insecure-Requests", 25 },
        { "User-Agent", 10 },
        { "Vary", 4 },
        { "X-Content-Type-Options", 22 },
        { "X-DNS-Prefetch-Control", 22 },
        { "X-Frame-Options", 15 },
        { "X-SourceMap", 11 },
        { "X-XSS-Protection", 16 },
        { "age", 3 },
        { "cache-control", 13 },
        { "content-disposition", 19 },
        { "content-length", 14 },
        { "content-range", 13 },
        { "content-type", 12 },
        { "cross-origin-embedder-policy", 28 },
        { "dark", 4 },
        { "date", 4 },
        { "device-memory", 13 },
        { "downlink", 8 },
        { "dpr", 3 },
        { "ect", 3 },
        { "etag", 4 },
        { "expires", 7 },
        { "last-modified", 13 },
        { "light", 5 },
        { "no-preference", 13 },
        { "on", 2 },
        { "pragma", 6 },
        { "range", 5 },
        { "reduce", 6 },
        { "rtt", 3 },
        { "sec-ch-device-memory", 20 },
        { "sec-ch-dpr", 10 },
        { "sec-ch-prefers-color-scheme", 27 },
        { "sec-ch-prefers-reduced-motion", 29 },
        { "sec-ch-prefers-reduced-transparency", 35 },
        { "sec-ch-ua", 9 },
        { "sec-ch-ua-arch", 14 },
        { "sec-ch-ua-bitness", 17 },
        { "sec-ch-ua-form-factors", 22 },
        { "sec-ch-ua-full-version", 22 },
        { "sec-ch-ua-full-version-list", 27 },
        { "sec-ch-ua-mobile", 16 },
        { "sec-ch-ua-model", 15 },
        { "sec-ch-ua-platform", 18 },
        { "sec-ch-ua-platform-version", 26 },
        { "sec-ch-ua-wow64", 15 },
        { "sec-ch-viewport-height", 22 },
        { "sec-ch-viewport-width", 21 },
        { "sec-ch-width", 12 },
        { "set-cookie", 10 },
        { "viewport-width", 14 },
        { "width", 5 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace http_names
} // namespace blink
