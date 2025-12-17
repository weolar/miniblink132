// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/fetch/fetch_response_data.h"

#include "base/numerics/safe_conversions.h"
//#include "storage/common/quota/padding_key.h"
#include "third_party/blink/public/common/storage_key/storage_key.h"
#include "third_party/blink/public/mojom/fetch/fetch_api_response.mojom-blink.h"
#include "third_party/blink/renderer/core/fetch/fetch_header_list.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/platform/bindings/exception_state.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "third_party/blink/renderer/platform/loader/cors/cors.h"
#include "third_party/blink/renderer/platform/loader/fetch/fetch_utils.h"
#include "third_party/blink/renderer/platform/network/http_names.h"
#include "third_party/blink/renderer/platform/network/http_parsers.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"

#include "third_party/openssl/openssl/include/openssl/types.h"
#include "third_party/openssl/openssl/include/openssl/evp.h"
#include "third_party/openssl/openssl/include/openssl/hmac.h"
#include "base/numerics/byte_conversions.h"
#include "base/rand_util.h"
#include "base/strings/stringprintf.h"
#include <inttypes.h>

using Type = network::mojom::FetchResponseType;
using ResponseSource = network::mojom::FetchResponseSource;

namespace crypto::hash {
// If you do need to be generic, you can use the Hash() function and pass a
// HashKind instead.
enum HashKind {
    kSha1,
    kSha256,
    kSha512,
};

inline constexpr size_t kSha1Size = 20;
inline constexpr size_t kSha256Size = 32;
inline constexpr size_t kSha512Size = 64;

} // hash

namespace storage {

namespace {

// The range of the padding added to response sizes for opaque resources.
// Increment the CacheStorage padding version if changed.
constexpr uint64_t kPaddingRange = 14431 * 1024;

const EVP_MD* EVPMDForHashKind(crypto::hash::HashKind kind) 
{
    switch (kind) {
        case crypto::hash::HashKind::kSha1:
            return EVP_sha1();
        case crypto::hash::HashKind::kSha256:
            return EVP_sha256();
        case crypto::hash::HashKind::kSha512:
            return EVP_sha512();
    }
    NOTREACHED();
}

}  // namespace

bool ShouldPadResponseType(network::mojom::FetchResponseType type)
{
    return type == network::mojom::FetchResponseType::kOpaque || type == network::mojom::FetchResponseType::kOpaqueRedirect;
}

int64_t ComputeRandomResponsePadding()
{
    uint64_t raw_random = (uint64_t)(&raw_random);
    //crypto::RandBytes(base::byte_span_from_ref(raw_random));
    return raw_random % kPaddingRange;
}

// Simplistic helper that wraps a call to a deleter function. In a C++11 world,
// this would be std::function<>. An alternative would be to re-use
// base::internal::RunnableAdapter<>, but that's far too heavy weight.
template <typename Type, void (*Destroyer)(Type*)>
struct OpenSSLDestroyer {
    void operator()(Type* ptr) const { Destroyer(ptr); }
};


template <typename PointerType, void (*Destroyer)(PointerType*)>
using ScopedOpenSSL = std::unique_ptr<PointerType, OpenSSLDestroyer<PointerType, Destroyer>>;
using ScopedHMAC_CTX = ScopedOpenSSL<HMAC_CTX, HMAC_CTX_free>;

void Sign(crypto::hash::HashKind kind,
    base::span<const uint8_t> key,
    base::span<const uint8_t> data,
    base::span<uint8_t> hmac)
{
    const EVP_MD* md = EVPMDForHashKind(kind);
    CHECK_EQ(hmac.size(), EVP_MD_size(md));

    ScopedHMAC_CTX ctx;
    CHECK(HMAC_Init_ex(ctx.get(), key.data(), key.size(), EVPMDForHashKind(kind), nullptr));
    CHECK(HMAC_Update(ctx.get(), data.data(), data.size()));
    CHECK(HMAC_Final(ctx.get(), hmac.data(), nullptr));
}

std::array<uint8_t, crypto::hash::kSha256Size> SignSha256(
    base::span<const uint8_t> key,
    base::span<const uint8_t> data) 
{
    std::array<uint8_t, crypto::hash::kSha256Size> result;
    Sign(crypto::hash::HashKind::kSha256, key, data, base::span<uint8_t>(result.data(), result.size()));
    return result;
}

int64_t ComputeStableResponsePadding(const blink::StorageKey& storage_key,
    const std::string& response_url,
    const base::Time& response_time,
    const std::string& request_method,
    int64_t side_data_size = 0)
{
    static std::array<uint8_t, 16> s_padding_key;
    static bool s_padding_key_generated = false;

    if (!s_padding_key_generated) {
        // This just needs to be consistent within a single browser session, so we
        // generate it the first time we need it.
        base::RandBytes(base::span<uint8_t>(s_padding_key.data(), s_padding_key.size()));
        s_padding_key_generated = true;
    }

    DCHECK(!response_url.empty());

    net::SchemefulSite site(storage_key.origin());

    DCHECK_GT(response_time, base::Time::UnixEpoch());
    int64_t microseconds = (response_time - base::Time::UnixEpoch()).InMicroseconds();

    // It should only be possible to have a CORS safe-listed method here since
    // the spec does not permit other methods for no-cors requests.
    DCHECK(request_method == net::HttpRequestHeaders::kGetMethod ||
        request_method == net::HttpRequestHeaders::kHeadMethod ||
        request_method == net::HttpRequestHeaders::kPostMethod);

    std::string key = base::StringPrintf(
        "%s-%" PRId64 "-%s-%s-%" PRId64, response_url.c_str(), microseconds,
        site.Serialize().c_str(), request_method.c_str(), side_data_size);

    std::array<uint8_t, crypto::hash::kSha256Size> hmac = SignSha256(base::span<uint8_t>(s_padding_key.data(), s_padding_key.size()), base::as_byte_span(key));
    return base::U64FromNativeEndian(std::span<const uint8_t, 8u>(hmac.data(), hmac.size()).first<8>()) % kPaddingRange;
}

} // namespace storage

namespace blink {

namespace {

Vector<String> HeaderSetToVector(const HTTPHeaderSet& headers)
{
    Vector<String> result;
    result.ReserveInitialCapacity(base::checked_cast<wtf_size_t>(headers.size()));
    // HTTPHeaderSet stores headers using Latin1 encoding.
    for (const auto& header : headers)
        result.push_back(String(header));
    return result;
}

} // namespace

FetchResponseData* FetchResponseData::Create()
{
    // "Unless stated otherwise, a response's url is null, status is 200, status
    // message is the empty byte sequence, header list is an empty header list,
    // and body is null."
    return MakeGarbageCollected<FetchResponseData>(Type::kDefault, ResponseSource::kUnspecified, 200, g_empty_atom);
}

FetchResponseData* FetchResponseData::CreateNetworkErrorResponse()
{
    // "A network error is a response whose status is always 0, status message
    // is always the empty byte sequence, header list is aways an empty list,
    // and body is always null."
    return MakeGarbageCollected<FetchResponseData>(Type::kError, ResponseSource::kUnspecified, 0, g_empty_atom);
}

FetchResponseData* FetchResponseData::CreateWithBuffer(BodyStreamBuffer* buffer)
{
    FetchResponseData* response = FetchResponseData::Create();
    response->buffer_ = buffer;
    return response;
}

FetchResponseData* FetchResponseData::CreateBasicFilteredResponse() const
{
    DCHECK_EQ(type_, Type::kDefault);
    // "A basic filtered response is a filtered response whose type is |basic|,
    // header list excludes any headers in internal response's header list whose
    // name is `Set-Cookie` or `Set-Cookie2`."
    FetchResponseData* response = MakeGarbageCollected<FetchResponseData>(Type::kBasic, response_source_, status_, status_message_);
    response->SetURLList(url_list_);
    for (const auto& header : header_list_->List()) {
        if (FetchUtils::IsForbiddenResponseHeaderName(header.first))
            continue;
        response->header_list_->Append(header.first, header.second);
    }
    response->buffer_ = buffer_;
    response->mime_type_ = mime_type_;
    response->internal_response_ = const_cast<FetchResponseData*>(this);
    return response;
}

FetchResponseData* FetchResponseData::CreateCorsFilteredResponse(const HTTPHeaderSet& exposed_headers) const
{
    DCHECK_EQ(type_, Type::kDefault);
    // "A CORS filtered response is a filtered response whose type is |CORS|,
    // header list excludes all headers in internal response's header list,
    // except those whose name is either one of `Cache-Control`,
    // `Content-Language`, `Content-Type`, `Expires`, `Last-Modified`, and
    // `Pragma`, and except those whose name is one of the values resulting from
    // parsing `Access-Control-Expose-Headers` in internal response's header
    // list."
    FetchResponseData* response = MakeGarbageCollected<FetchResponseData>(Type::kCors, response_source_, status_, status_message_);
    response->SetURLList(url_list_);
    for (const auto& header : header_list_->List()) {
        const String& name = header.first;
        if (cors::IsCorsSafelistedResponseHeader(name)
            || (exposed_headers.find(name.Ascii()) != exposed_headers.end() && !FetchUtils::IsForbiddenResponseHeaderName(name))) {
            response->header_list_->Append(name, header.second);
        }
    }
    response->cors_exposed_header_names_ = exposed_headers;
    response->buffer_ = buffer_;
    response->mime_type_ = mime_type_;
    response->internal_response_ = const_cast<FetchResponseData*>(this);
    return response;
}

FetchResponseData* FetchResponseData::CreateOpaqueFilteredResponse() const
{
    DCHECK_EQ(type_, Type::kDefault);
    // "An opaque filtered response is a filtered response whose type is
    // 'opaque', url list is the empty list, status is 0, status message is the
    // empty byte sequence, header list is the empty list, body is null, and
    // cache state is 'none'."
    //
    // https://fetch.spec.whatwg.org/#concept-filtered-response-opaque
    FetchResponseData* response = MakeGarbageCollected<FetchResponseData>(Type::kOpaque, response_source_, 0, g_empty_atom);
    response->internal_response_ = const_cast<FetchResponseData*>(this);
    return response;
}

FetchResponseData* FetchResponseData::CreateOpaqueRedirectFilteredResponse() const
{
    DCHECK_EQ(type_, Type::kDefault);
    // "An opaque filtered response is a filtered response whose type is
    // 'opaqueredirect', status is 0, status message is the empty byte sequence,
    // header list is the empty list, body is null, and cache state is 'none'."
    //
    // https://fetch.spec.whatwg.org/#concept-filtered-response-opaque-redirect
    FetchResponseData* response = MakeGarbageCollected<FetchResponseData>(Type::kOpaqueRedirect, response_source_, 0, g_empty_atom);
    response->SetURLList(url_list_);
    response->internal_response_ = const_cast<FetchResponseData*>(this);
    return response;
}

const KURL* FetchResponseData::Url() const
{
    // "A response has an associated url. It is a pointer to the last response URL
    // in response’s url list and null if response’s url list is the empty list."
    if (url_list_.empty())
        return nullptr;
    return &url_list_.back();
}

uint16_t FetchResponseData::InternalStatus() const
{
    if (internal_response_) {
        return internal_response_->Status();
    }
    return Status();
}

FetchHeaderList* FetchResponseData::InternalHeaderList() const
{
    if (internal_response_) {
        return internal_response_->HeaderList();
    }
    return HeaderList();
}

String FetchResponseData::MimeType() const
{
    return mime_type_;
}

BodyStreamBuffer* FetchResponseData::InternalBuffer() const
{
    if (internal_response_) {
        return internal_response_->buffer_.Get();
    }
    return buffer_.Get();
}

String FetchResponseData::InternalMIMEType() const
{
    if (internal_response_) {
        return internal_response_->MimeType();
    }
    return mime_type_;
}

bool FetchResponseData::RequestIncludeCredentials() const
{
    return internal_response_ ? internal_response_->RequestIncludeCredentials() : request_include_credentials_;
}

void FetchResponseData::SetURLList(const Vector<KURL>& url_list)
{
    url_list_ = url_list;
}

const Vector<KURL>& FetchResponseData::InternalURLList() const
{
    if (internal_response_) {
        return internal_response_->url_list_;
    }
    return url_list_;
}

FetchResponseData* FetchResponseData::Clone(ScriptState* script_state, ExceptionState& exception_state)
{
    FetchResponseData* new_response = Create();
    new_response->type_ = type_;
    new_response->padding_ = padding_;
    new_response->response_source_ = response_source_;
    if (termination_reason_) {
        new_response->termination_reason_ = std::make_unique<TerminationReason>();
        *new_response->termination_reason_ = *termination_reason_;
    }
    new_response->SetURLList(url_list_);
    new_response->status_ = status_;
    new_response->status_message_ = status_message_;
    new_response->header_list_ = header_list_->Clone();
    new_response->mime_type_ = mime_type_;
    new_response->request_method_ = request_method_;
    new_response->response_time_ = response_time_;
    new_response->cache_storage_cache_name_ = cache_storage_cache_name_;
    new_response->cors_exposed_header_names_ = cors_exposed_header_names_;
    new_response->connection_info_ = connection_info_;
    new_response->alpn_negotiated_protocol_ = alpn_negotiated_protocol_;
    new_response->was_fetched_via_spdy_ = was_fetched_via_spdy_;
    new_response->has_range_requested_ = has_range_requested_;
    new_response->request_include_credentials_ = request_include_credentials_;
    if (auth_challenge_info_) {
        new_response->auth_challenge_info_ = std::make_unique<net::AuthChallengeInfo>(*auth_challenge_info_);
    }

    switch (type_) {
    case Type::kBasic:
    case Type::kCors:
        DCHECK(internal_response_);
        DCHECK_EQ(buffer_, internal_response_->buffer_);
        DCHECK_EQ(internal_response_->type_, Type::kDefault);
        new_response->internal_response_ = internal_response_->Clone(script_state, exception_state);
        if (exception_state.HadException())
            return nullptr;
        buffer_ = internal_response_->buffer_;
        new_response->buffer_ = new_response->internal_response_->buffer_;
        break;
    case Type::kDefault: {
        DCHECK(!internal_response_);
        if (buffer_) {
            BodyStreamBuffer* new1 = nullptr;
            BodyStreamBuffer* new2 = nullptr;
            buffer_->Tee(&new1, &new2, exception_state);
            if (exception_state.HadException())
                return nullptr;
            buffer_ = new1;
            new_response->buffer_ = new2;
        }
        break;
    }
    case Type::kError:
        DCHECK(!internal_response_);
        DCHECK(!buffer_);
        break;
    case Type::kOpaque:
    case Type::kOpaqueRedirect:
        DCHECK(internal_response_);
        DCHECK(!buffer_);
        DCHECK_EQ(internal_response_->type_, Type::kDefault);
        new_response->internal_response_ = internal_response_->Clone(script_state, exception_state);
        if (exception_state.HadException())
            return nullptr;
        break;
    }
    return new_response;
}

mojom::blink::FetchAPIResponsePtr FetchResponseData::PopulateFetchAPIResponse(const KURL& request_url)
{
    if (internal_response_) {
        mojom::blink::FetchAPIResponsePtr response = internal_response_->PopulateFetchAPIResponse(request_url);
        response->response_type = type_;
        response->response_source = response_source_;
        response->cors_exposed_header_names = HeaderSetToVector(cors_exposed_header_names_);
        return response;
    }
    mojom::blink::FetchAPIResponsePtr response = mojom::blink::FetchAPIResponse::New();
    response->url_list = url_list_;
    response->status_code = status_;
    response->status_text = status_message_;
    response->response_type = type_;
    response->padding = padding_;
    response->response_source = response_source_;
    response->mime_type = mime_type_;
    response->request_method = request_method_;
    response->response_time = response_time_;
    response->cache_storage_cache_name = cache_storage_cache_name_;
    response->cors_exposed_header_names = HeaderSetToVector(cors_exposed_header_names_);
    response->connection_info = connection_info_;
    response->alpn_negotiated_protocol = alpn_negotiated_protocol_;
    response->was_fetched_via_spdy = was_fetched_via_spdy_;
    response->has_range_requested = has_range_requested_;
    response->request_include_credentials = request_include_credentials_;
    for (const auto& header : HeaderList()->List())
        response->headers.insert(header.first, header.second);
    response->parsed_headers = ParseHeaders(HeaderList()->GetAsRawString(status_, status_message_), request_url);
    if (auth_challenge_info_) {
        response->auth_challenge_info = *auth_challenge_info_;
    }
    return response;
}

void FetchResponseData::InitFromResourceResponse(ExecutionContext* context, network::mojom::FetchResponseType response_type,
    const Vector<KURL>& request_url_list, const AtomicString& request_method, network::mojom::CredentialsMode request_credentials,
    const ResourceResponse& response)
{
    SetStatus(response.HttpStatusCode());
    if (response.CurrentRequestUrl().ProtocolIsAbout() || response.CurrentRequestUrl().ProtocolIsData() || response.CurrentRequestUrl().ProtocolIs("blob")) {
        SetStatusMessage(AtomicString("OK"));
    } else {
        SetStatusMessage(response.HttpStatusText());
    }

    for (auto& it : response.HttpHeaderFields())
        HeaderList()->Append(it.key, it.value);

    // Corresponds to https://fetch.spec.whatwg.org/#main-fetch step:
    // "If |internalResponse|’s URL list is empty, then set it to a clone of
    // |request|’s URL list."
    if (response.UrlListViaServiceWorker().empty()) {
        // Note: |UrlListViaServiceWorker()| is empty, unless the response came from
        // a service worker, in which case it will only be empty if it was created
        // through new Response().
        SetURLList(request_url_list);
    } else {
        DCHECK(response.WasFetchedViaServiceWorker());
        SetURLList(response.UrlListViaServiceWorker());
    }

    SetMimeType(response.MimeType());
    SetRequestMethod(request_method);
    SetResponseTime(response.ResponseTime());
    SetCacheStorageCacheName(response.CacheStorageCacheName());

    if (response.WasCached()) {
        SetResponseSource(network::mojom::FetchResponseSource::kHttpCache);
    } else if (!response.WasFetchedViaServiceWorker()) {
        SetResponseSource(network::mojom::FetchResponseSource::kNetwork);
    }

    SetConnectionInfo(response.ConnectionInfo());

    // Some non-http responses, like data: url responses, will have a null
    // |alpn_negotiated_protocol|.  In these cases we leave the default
    // value of "unknown".
    if (!response.AlpnNegotiatedProtocol().IsNull())
        SetAlpnNegotiatedProtocol(response.AlpnNegotiatedProtocol());

    SetWasFetchedViaSpdy(response.WasFetchedViaSPDY());

    SetHasRangeRequested(response.HasRangeRequested());

    // Use the explicit padding in the response provided by a service worker
    // or compute a new padding if necessary.
    if (response.GetPadding()) {
        SetPadding(response.GetPadding());
    } else {
        if (storage::ShouldPadResponseType(response_type)) {
            int64_t padding = response.WasCached() ? 
                storage::ComputeStableResponsePadding(
                    // TODO(https://crbug.com/1199077): Investigate the need to
                    // have a specified storage key within the ExecutionContext
                    // and if warranted change this to use the actual storage
                    // key instead.
                    blink::StorageKey::CreateFirstParty(context->GetSecurityOrigin()->ToUrlOrigin()),
                    Url()->GetString().Utf8(), 
                    ResponseTime(), 
                    request_method.Utf8()) 
                : storage::ComputeRandomResponsePadding();
            SetPadding(padding);
        }
    }

    SetAuthChallengeInfo(response.AuthChallengeInfo());
    SetRequestIncludeCredentials(response.RequestIncludeCredentials());
}

FetchResponseData::FetchResponseData(Type type, network::mojom::FetchResponseSource source, uint16_t status, AtomicString status_message)
    : type_(type)
    , padding_(0)
    , response_source_(source)
    , status_(status)
    , status_message_(status_message)
    , header_list_(MakeGarbageCollected<FetchHeaderList>())
    , response_time_(base::Time::Now())
    , alpn_negotiated_protocol_("unknown")
    , was_fetched_via_spdy_(false)
    , has_range_requested_(false)
    , request_include_credentials_(true)
{
}

void FetchResponseData::SetAuthChallengeInfo(const std::optional<net::AuthChallengeInfo>& auth_challenge_info)
{
    if (auth_challenge_info) {
        auth_challenge_info_ = std::make_unique<net::AuthChallengeInfo>(*auth_challenge_info);
    }
}

void FetchResponseData::SetRequestIncludeCredentials(bool request_include_credentials)
{
    DCHECK(!internal_response_);
    request_include_credentials_ = request_include_credentials;
}

void FetchResponseData::ReplaceBodyStreamBuffer(BodyStreamBuffer* buffer)
{
    if (type_ == Type::kBasic || type_ == Type::kCors) {
        DCHECK(internal_response_);
        internal_response_->buffer_ = buffer;
        buffer_ = buffer;
    } else if (type_ == Type::kDefault) {
        DCHECK(!internal_response_);
        buffer_ = buffer;
    }
}

void FetchResponseData::Trace(Visitor* visitor) const
{
    visitor->Trace(header_list_);
    visitor->Trace(internal_response_);
    visitor->Trace(buffer_);
}

} // namespace blink
