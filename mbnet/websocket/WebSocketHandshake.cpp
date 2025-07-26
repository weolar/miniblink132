/*
 * Copyright (C) 2011 Google Inc.  All rights reserved.
 * Copyright (C) Research In Motion Limited 2011. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "mbnet/websocket/WebSocketHandshake.h"

#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/platform/weborigin/security_origin.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/local_frame_client.h"
//#include "third_party/smhasher/src/sha1.h"
#include <openssl/sha.h>
#include "base/rand_util.h"
#include "base/base64.h"

static const size_t maxInputSampleSize = 128;
static const UChar horizontalEllipsis = 0x2026;

std::string trimInputSample(const char* p, size_t len)
{
    std::string s(p, std::min<size_t>(len, maxInputSampleSize));
    if (len > maxInputSampleSize) {
        //s.push_back(horizontalEllipsis);
        s.push_back(0x20);
        s.push_back(0x26);
    }
    return s;
}

namespace mbnet {

static std::string resourceName(const blink::KURL& url)
{
    StringBuilder name;
    name.Append(url.GetPath());
    if (name.empty())
        name.Append('/');
    if (!url.Query().empty()) {
        name.Append('?');
        name.Append(url.Query());
    }
    String result = name.ToString();
    DCHECK(!result.empty());
    DCHECK(!result.Contains(' '));
    return result.Utf8();
}

static std::string hostName(const blink::KURL& url, bool secure)
{
    DCHECK(url.ProtocolIs("wss") == secure);
    StringBuilder builder;
    builder.Append(url.Host().ToString().LowerASCII());
    if (url.Port() && ((!secure && url.Port() != 80) || (secure && url.Port() != 443))) {
        builder.Append(':');
        builder.AppendNumber(url.Port());
    }
    return builder.ToString().Utf8();
}

static std::string generateSecWebSocketKey()
{
    static const size_t nonceSize = 16;
    uint8_t key[nonceSize];
    //     cryptographicallyRandomValues(key, nonceSize);
    //     return base64Encode((const char*)key, nonceSize, Base64DoNotInsertLFs);

    base::RandBytes(base::span<uint8_t>(key, nonceSize));
    return base::Base64Encode(base::make_span(key, nonceSize));
}

std::string WebSocketHandshake::getExpectedWebSocketAccept(const std::string& secWebSocketKey)
{
    static const char* const webSocketKeyGUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
    std::string keyData = secWebSocketKey;
    //     SkSHA1 sha1;
    //
    //     sha1.write(reinterpret_cast<const uint8_t*>(keyData.data()), keyData.length());
    //     sha1.write(reinterpret_cast<const uint8_t*>(webSocketKeyGUID), strlen(webSocketKeyGUID));
    //     SkSHA1::Digest hash;
    //     sha1.finish(hash);

    SHA_CTX context = { 0 };
    uint8_t digest[SHA_DIGEST_LENGTH] = { 0 };
    SHA1_Init(&context);
    SHA1_Update(&context, reinterpret_cast<const uint8_t*>(keyData.data()), keyData.length());
    SHA1_Update(&context, reinterpret_cast<const uint8_t*>(webSocketKeyGUID), strlen(webSocketKeyGUID));
    SHA1_Final(digest, &context);

    return base::Base64Encode(std::string_view((const char*)digest, SHA_DIGEST_LENGTH));
}

WebSocketHandshake::WebSocketHandshake(const blink::KURL& url, const String& protocol, blink::ExecutionContext* context)
    : m_url(url)
    , m_clientProtocol(protocol.Utf8())
    , m_secure(m_url.ProtocolIs("wss"))
    , m_context(context)
    , m_mode(Incomplete)
{
    m_secWebSocketKey = generateSecWebSocketKey();
    m_expectedAccept = getExpectedWebSocketAccept(m_secWebSocketKey);
}

WebSocketHandshake::~WebSocketHandshake()
{
}

const blink::KURL& WebSocketHandshake::url() const
{
    return m_url;
}

void WebSocketHandshake::setURL(const blink::KURL& url)
{
    m_url = url;
}

const std::string WebSocketHandshake::host() const
{
    return m_url.Host().ToString().LowerASCII().Utf8();
}

const std::string& WebSocketHandshake::clientProtocol() const
{
    return m_clientProtocol;
}

void WebSocketHandshake::setClientProtocol(const std::string& protocol)
{
    m_clientProtocol = protocol;
}

bool WebSocketHandshake::secure() const
{
    return m_secure;
}

std::string WebSocketHandshake::clientOrigin() const
{
    return m_context->GetSecurityOrigin()->ToString().Utf8();
}

std::string WebSocketHandshake::clientLocation() const
{
    std::string builder;
    builder.append(m_secure ? "wss" : "ws");
    builder.append("://");
    builder.append(hostName(m_url, m_secure));
    builder.append(resourceName(m_url));
    return builder;
}

static WebCookieJarImpl* toCookieJar(const blink::LocalDOMWindow& window)
{
    blink::LocalFrame* frame = window.GetFrame();
    if (!frame)
        return nullptr;

    blink::LocalFrameClient* client = frame->Client();
    if (!client)
        return nullptr;

    blink::WebLocalFrame* localFrame = client->GetWebFrame();
    if (!localFrame)
        return nullptr;

    content::WebLocalFrameClientImpl* clientImpl = (content::WebLocalFrameClientImpl*)localFrame->Client();
    int64_t id = clientImpl->getMbwebviewId();

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
    if (!webview)
        return nullptr;
    return webview->getWebCookieJarImpl();
}

std::string cookieRequestHeaderFieldValue(const blink::LocalDOMWindow& window, const blink::KURL& url)
{
    WebCookieJarImpl* cookieJar = (WebCookieJarImpl*)toCookieJar(window);
    if (!cookieJar)
        return "";
    return cookieJar->cookieRequestHeaderFieldValue(url, /*document.FirstPartyForCookies()*/ blink::WebURL());
}

std::string WebSocketHandshake::clientHandshakeMessage() const
{
    // Keep the following consistent with clientHandshakeRequest().
    std::string builder;

    builder.append("GET ");
    builder.append(resourceName(m_url));
    builder.append(" HTTP/1.1\r\n");

    std::vector<std::string> fields;
    fields.push_back("Upgrade: websocket");
    fields.push_back("Connection: Upgrade");
    fields.push_back("Host: " + hostName(m_url, m_secure));
    fields.push_back("Origin: " + clientOrigin());

    fields.push_back("Accept-Encoding: gzip, deflate, br"); //weolar!!!!
    fields.push_back("Accept-Language: zh-CN,zh;q=0.9");

    if (!m_clientProtocol.empty())
        fields.push_back("Sec-WebSocket-Protocol: " + m_clientProtocol);

    blink::KURL url = httpURLForAuthenticationAndCookies();
    if (m_context->IsWindow()) {
        //Document& document = blink::To(m_context);
        //String cookie = cookieRequestHeaderFieldValue(document, url);
        blink::LocalDOMWindow* window = blink::To<blink::LocalDOMWindow>(m_context);
        std::string cookie = cookieRequestHeaderFieldValue(*window, url);

        if (!cookie.empty())
            fields.push_back("Cookie: " + cookie);
        // Set "Cookie2: <cookie>" if cookies 2 exists for url?
    }

    // Add no-cache headers to avoid compatibility issue.
    // There are some proxies that rewrite "Connection: upgrade"
    // to "Connection: close" in the response if a request doesn't contain
    // these headers.
    fields.push_back("Pragma: no-cache");
    fields.push_back("Cache-Control: no-cache");

    fields.push_back("Sec-WebSocket-Key: " + m_secWebSocketKey);
    fields.push_back("Sec-WebSocket-Version: 13");
    const std::string extensionValue = m_extensionDispatcher.createHeaderValue().Utf8();
    if (extensionValue.length())
        fields.push_back("Sec-WebSocket-Extensions: " + extensionValue);

    // Add a User-Agent header.
    std::string ua = "User-Agent: ";
    ua += m_context->UserAgent(/*m_context->url()*/).Utf8();
    fields.push_back(ua);

    // Fields in the handshake are sent by the client in a random order; the
    // order is not meaningful.  Thus, it's ok to send the order we constructed
    // the fields.

    for (auto& field : fields) {
        builder.append(field);
        builder.append("\r\n");
    }

    builder.append("\r\n");

    return builder;
}

static void addHeaderField(network::mojom::blink::WebSocketHandshakeRequest* request, const std::string& key, const std::string& value)
{
    request->headers.push_back(network::mojom::blink::HttpHeader::New(String(key), String(value)));
}

static void addHeaderFieldToResponse(network::mojom::blink::WebSocketHandshakeResponse* response, const AtomicString& key, const AtomicString& value)
{
    for (size_t i = 0; i < response->headers.size(); ++i) {
        network::mojom::blink::HttpHeaderPtr& header = response->headers[i];
        if (0 == WTF::CodeUnitCompareIgnoringASCIICase(header->name.Impl(), key.GetString().Impl())) {
            header->value = (value);
            return;
        }
    }

    network::mojom::blink::HttpHeaderPtr newHeader = network::mojom::blink::HttpHeader::New();
    newHeader->name = key;
    newHeader->value = value;
    response->headers.push_back(std::move(newHeader));
}

network::mojom::blink::WebSocketHandshakeRequestPtr WebSocketHandshake::clientHandshakeRequest() const
{
    if (!m_context)
        return nullptr;

    network::mojom::blink::WebSocketHandshakeRequestPtr request = network::mojom::blink::WebSocketHandshakeRequest::New();
    request->url = m_url;
    addHeaderField(request.get(), "Connection", "Upgrade");
    addHeaderField(request.get(), "Host", hostName(m_url, m_secure));
    addHeaderField(request.get(), "Origin", clientOrigin());

    if (!m_clientProtocol.empty())
        addHeaderField(request.get(), "Sec-WebSocket-Protocol", m_clientProtocol);
    blink::KURL url = httpURLForAuthenticationAndCookies();
    if (m_context->IsWindow()) {
        //Document* document = toDocument(m_context);
        //String cookie = cookieRequestHeaderFieldValue(*document, url);
        blink::LocalDOMWindow* window = blink::To<blink::LocalDOMWindow>(m_context);
        std::string cookie = cookieRequestHeaderFieldValue(*window, url);

        if (!cookie.empty())
            addHeaderField(request.get(), "Cookie", cookie);
        //         // Set "Cookie2: <cookie>" if cookies 2 exists for url?
    }

    addHeaderField(request.get(), "Pragma", "no-cache");
    addHeaderField(request.get(), "CacheControl", "no-cache");

    addHeaderField(request.get(), "Sec-WebSocket-Key", m_secWebSocketKey);
    addHeaderField(request.get(), "Sec-WebSocket-Version", "13");
    const String extensionValue = m_extensionDispatcher.createHeaderValue();
    if (extensionValue.length())
        addHeaderField(request.get(), "Sec-WebSocket-Extensions", extensionValue.Utf8());

    // Add a User-Agent header.
    addHeaderField(request.get(), "User-Agent", m_context->UserAgent(/*m_context->url()*/).Utf8());

    return std::move(request);
}

void WebSocketHandshake::reset()
{
    m_mode = Incomplete;
    m_extensionDispatcher.reset();
}

void WebSocketHandshake::clearScriptExecutionContext()
{
    m_context = nullptr;
}

inline char* strnstr(const char* buffer, const char* target, size_t bufferLength)
{
    size_t targetLength = strlen(target);
    if (targetLength == 0)
        return const_cast<char*>(buffer);
    for (const char* start = buffer; *start && start + targetLength <= buffer + bufferLength; start++) {
        if (*start == *target && strncmp(start + 1, target + 1, targetLength - 1) == 0)
            return const_cast<char*>(start);
    }
    return 0;
}

int WebSocketHandshake::readServerHandshake(const char* header, size_t len)
{
    m_mode = Incomplete;
    int statusCode;
    String statusText;
    int lineLength = readStatusLine(header, len, statusCode, statusText);
    if (lineLength == -1)
        return -1;
    if (statusCode == -1) {
        m_mode = Failed; // m_failureReason is set inside readStatusLine().
        return len;
    }
    //WTF_LOG(Network, "WebSocketHandshake %p readServerHandshake() Status code is %d", this, statusCode);

    m_serverHandshakeResponse = network::mojom::blink::WebSocketHandshakeResponse::New();
    m_serverHandshakeResponse->status_code = (statusCode);
    m_serverHandshakeResponse->status_text = (statusText);

    if (statusCode != 101) {
        m_mode = Failed;
        String failureReason = "Unexpected response code: " + String::Number(statusCode);
        m_failureReason = failureReason.Utf8();
        return len;
    }
    m_mode = Normal;
    if (!strnstr(header, "\r\n\r\n", len)) {
        // Just hasn't been received fully yet.
        m_mode = Incomplete;
        return -1;
    }
    const char* p = readHTTPHeaders(header + lineLength, header + len);
    if (!p) {
        //WTF_LOG(Network, "WebSocketHandshake %p readServerHandshake() readHTTPHeaders() failed", this);
        m_mode = Failed; // m_failureReason is set inside readHTTPHeaders().
        return len;
    }
    if (!checkResponseHeaders()) {
        //WTF_LOG(Network, "WebSocketHandshake %p readServerHandshake() checkResponseHeaders() failed", this);
        m_mode = Failed;
        return p - header;
    }

    m_mode = Connected;
    return p - header;
}

WebSocketHandshake::Mode WebSocketHandshake::mode() const
{
    return m_mode;
}

String WebSocketHandshake::failureReason() const
{
    return String(m_failureReason);
}

static String getHeaderFields(network::mojom::blink::WebSocketHandshakeResponse* response, const char* key)
{
    for (size_t i = 0; i < response->headers.size(); ++i) {
        const network::mojom::blink::HttpHeaderPtr& header = response->headers[i];
        if (0 == WTF::CodeUnitCompareIgnoringASCIICase(header->name, key)) {
            return header->value;
        }
    }
    return "";
}

String WebSocketHandshake::serverWebSocketProtocol() const
{
    return getHeaderFields(m_serverHandshakeResponse.get(), "Sec-WebSocket-Protocol");
}

String WebSocketHandshake::serverSetCookie() const
{
    return getHeaderFields(m_serverHandshakeResponse.get(), "Set-Cookie");
}

String WebSocketHandshake::serverSetCookie2() const
{
    return getHeaderFields(m_serverHandshakeResponse.get(), "Set-Cookie2");
}

String WebSocketHandshake::serverUpgrade() const
{
    return getHeaderFields(m_serverHandshakeResponse.get(), "Upgrade");
}

String WebSocketHandshake::serverConnection() const
{
    return getHeaderFields(m_serverHandshakeResponse.get(), "Connection");
}

String WebSocketHandshake::serverWebSocketAccept() const
{
    return getHeaderFields(m_serverHandshakeResponse.get(), "Sec-WebSocket-Accept");
}

String WebSocketHandshake::acceptedExtensions() const
{
    return m_extensionDispatcher.acceptedExtensions();
}

const network::mojom::blink::WebSocketHandshakeResponse& WebSocketHandshake::serverHandshakeResponse() const
{
    return *(m_serverHandshakeResponse.get());
}

void WebSocketHandshake::addExtensionProcessor(std::unique_ptr<WebSocketExtensionProcessor> processor)
{
    m_extensionDispatcher.addProcessor(std::move(processor));
}

blink::KURL WebSocketHandshake::httpURLForAuthenticationAndCookies() const
{
    blink::KURL url = m_url;
    bool couldSetProtocol = url.SetProtocol(m_secure ? "https" : "http");
    //ASSERT_UNUSED(couldSetProtocol, couldSetProtocol);
    return url;
}

// Returns the header length (including "\r\n"), or -1 if we have not received enough data yet.
// If the line is malformed or the status code is not a 3-digit number,
// statusCode and statusText will be set to -1 and a null string, respectively.
int WebSocketHandshake::readStatusLine(const char* header, size_t headerLength, int& statusCode, String& statusText)
{
    // Arbitrary size limit to prevent the server from sending an unbounded
    // amount of data with no newlines and forcing us to buffer it all.
    static const int maximumLength = 1024;

    statusCode = -1;
    statusText = String();

    const char* space1 = nullptr;
    const char* space2 = nullptr;
    const char* p;
    size_t consumedLength;

    for (p = header, consumedLength = 0; consumedLength < headerLength; p++, consumedLength++) {
        if (*p == ' ') {
            if (!space1)
                space1 = p;
            else if (!space2)
                space2 = p;
        } else if (*p == '\0') {
            // The caller isn't prepared to deal with null bytes in status
            // line. WebSockets specification doesn't prohibit this, but HTTP
            // does, so we'll just treat this as an error.
            m_failureReason = "Status line contains embedded null";
            return p + 1 - header;
        } else if (*p == '\n')
            break;
    }
    if (consumedLength == headerLength)
        return -1; // We have not received '\n' yet.

    const char* end = p + 1;
    int lineLength = end - header;
    if (lineLength > maximumLength) {
        m_failureReason = "Status line is too long";
        return maximumLength;
    }

    // The line must end with "\r\n".
    if (lineLength < 2 || *(end - 2) != '\r') {
        m_failureReason = "Status line does not end with CRLF";
        return lineLength;
    }

    if (!space1 || !space2) {
        m_failureReason = "No response code found: " + trimInputSample(header, lineLength - 2);
        return lineLength;
    }

    String statusCodeString(base::span<const char>(space1 + 1, (size_t)(space2 - space1 - 1)));
    if (statusCodeString.length() != 3) // Status code must consist of three digits.
        return lineLength;
    for (int i = 0; i < 3; ++i)
        if (statusCodeString[i] < '0' || statusCodeString[i] > '9') {
            m_failureReason = "Invalid status code: " + statusCodeString.Utf8();
            return lineLength;
        }

    bool ok = false;
    statusCode = statusCodeString.ToInt(&ok);
    DCHECK(ok);

    statusText = String(base::span<const char>(space2 + 1, (size_t)(end - space2 - 3))); // Exclude "\r\n".
    return lineLength;
}

static bool parseHTTPHeaderName(const char* s, size_t start, size_t size, std::string& failureReason, size_t* position, AtomicString* name)
{
    size_t nameBegin = start;
    for (size_t i = start; i < size; ++i) {
        switch (s[i]) {
        case '\r':
            failureReason = "Unexpected CR in name at " + trimInputSample(&s[nameBegin], i - nameBegin);
            return false;
        case '\n':
            failureReason = "Unexpected LF in name at " + trimInputSample(&s[nameBegin], i - nameBegin);
            return false;
        case ':':
            if (i == nameBegin) {
                failureReason = "Header name is missing";
                return false;
            }
            *name = AtomicString::FromUTF8(&s[nameBegin], i - nameBegin);
            if (name->empty()) {
                failureReason = "Invalid UTF-8 sequence in header name";
                return false;
            }
            *position = i;
            return true;
        default:
            break;
        }
    }
    failureReason = "Unterminated header name";
    return false;
}

static bool parseHTTPHeaderValue(const char* s, size_t start, size_t size, std::string& failureReason, size_t* position, AtomicString* value)
{
    size_t i = start;
    for (; i < size && s[i] == ' '; ++i) {
    }
    size_t valueBegin = i;

    for (; i < size && s[i] != '\r'; ++i) {
        if (s[i] == '\n') {
            failureReason = "Unexpected LF in value at " + trimInputSample(&s[valueBegin], i - valueBegin);
            return false;
        }
    }
    if (i == size) {
        failureReason = "Unterminated header value";
        return false;
    }

    DCHECK(i < size && s[i] == '\r');
    if (i + 1 >= size || s[i + 1] != '\n') {
        failureReason = "LF doesn't follow CR after value at " + trimInputSample(&s[i + 1], size - i - 1);
        return false;
    }

    *value = AtomicString::FromUTF8(&s[valueBegin], i - valueBegin);
    if (i != valueBegin && value->empty()) {
        failureReason = "Invalid UTF-8 sequence in header value";
        return false;
    }

    // 2 for strlen("\r\n")
    *position = i + 2;
    return true;
}

// Note that the header is already parsed and re-formatted in chromium side.
// We assume that the input is more restricted than RFC2616.
size_t parseHTTPHeader(const char* s, size_t size, std::string& failureReason, AtomicString& name, AtomicString& value)
{
    name = AtomicString();
    value = AtomicString();
    if (size >= 1 && s[0] == '\r') {
        if (size >= 2 && s[1] == '\n') {
            // Skip an empty line.
            return 2;
        }
        failureReason = "LF doesn't follow CR at " + trimInputSample(0, size);
        return 0;
    }
    size_t current = 0;
    if (!parseHTTPHeaderName(s, current, size, failureReason, &current, &name)) {
        return 0;
    }
    DCHECK(s[current] == ':');
    ++current;

    if (!parseHTTPHeaderValue(s, current, size, failureReason, &current, &value))
        return 0;

    return current;
}

// Upgrade: websocket
// Connection: Upgrade
// Sec-WebSocket-Accept: g8czhIr28cKzDoHrMk1o1fevpcA=
// Server: server
// Access-Control-Allow-Credentials: false
// Access-Control-Allow-Methods: GET
// Access-Control-Allow-Headers: content-type
// Access-Control-Allow-Origin: file://
// Date: Sun, 19 May 2024 17:12:22 GMT

const char* WebSocketHandshake::readHTTPHeaders(const char* start, const char* end)
{
    AtomicString name;
    AtomicString value;
    bool sawSecWebSocketExtensionsHeaderField = false;
    bool sawSecWebSocketAcceptHeaderField = false;
    bool sawSecWebSocketProtocolHeaderField = false;
    const char* p = start;

    for (; p < end; /*p++*/) {
        size_t consumedLength = parseHTTPHeader(p, end - p, m_failureReason, name, value);
        if (!consumedLength)
            return 0;
        p += consumedLength;

        // Stop once we consumed an empty line.
        if (name.empty())
            break;

        if (0 == WTF::CodeUnitCompareIgnoringASCIICase(name, "sec-websocket-extensions")) {
            if (sawSecWebSocketExtensionsHeaderField) {
                m_failureReason = "The Sec-WebSocket-Extensions header MUST NOT appear more than once in an HTTP response";
                return 0;
            }
            if (!m_extensionDispatcher.processHeaderValue(value)) {
                m_failureReason = m_extensionDispatcher.failureReason().Utf8();
                return 0;
            }
            sawSecWebSocketExtensionsHeaderField = true;
        } else if (0 == WTF::CodeUnitCompareIgnoringASCIICase(name, "Sec-WebSocket-Accept")) {
            if (sawSecWebSocketAcceptHeaderField) {
                m_failureReason = "The Sec-WebSocket-Accept header MUST NOT appear more than once in an HTTP response";
                return 0;
            }
            addHeaderFieldToResponse(m_serverHandshakeResponse.get(), name, value);
            sawSecWebSocketAcceptHeaderField = true;
        } else if (0 == WTF::CodeUnitCompareIgnoringASCIICase(name, "Sec-WebSocket-Protocol")) {
            if (sawSecWebSocketProtocolHeaderField) {
                m_failureReason = "The Sec-WebSocket-Protocol header MUST NOT appear more than once in an HTTP response";
                return 0;
            }
            addHeaderFieldToResponse(m_serverHandshakeResponse.get(), name, value);
            sawSecWebSocketProtocolHeaderField = true;
        } else
            addHeaderFieldToResponse(m_serverHandshakeResponse.get(), name, value);
    }
    return p;
}

bool WebSocketHandshake::checkResponseHeaders()
{
    const String& serverWebSocketProtocol = this->serverWebSocketProtocol();
    const String& serverUpgrade = this->serverUpgrade();
    const String& serverConnection = this->serverConnection();
    const String& serverWebSocketAccept = this->serverWebSocketAccept();

    if (serverUpgrade.empty()) {
        m_failureReason = "Error during WebSocket handshake: 'Upgrade' header is missing";
        return false;
    }
    if (serverConnection.empty()) {
        m_failureReason = "Error during WebSocket handshake: 'Connection' header is missing";
        return false;
    }
    if (serverWebSocketAccept.empty()) {
        m_failureReason = "Error during WebSocket handshake: 'Sec-WebSocket-Accept' header is missing";
        return false;
    }

    if (0 != WTF::CodeUnitCompareIgnoringASCIICase(serverUpgrade, "websocket")) {
        m_failureReason = "Error during WebSocket handshake: 'Upgrade' header value is not 'WebSocket'";
        return false;
    }
    if (0 != WTF::CodeUnitCompareIgnoringASCIICase(serverConnection, "upgrade")) {
        m_failureReason = "Error during WebSocket handshake: 'Connection' header value is not 'Upgrade'";
        return false;
    }

    if (serverWebSocketAccept != String(m_expectedAccept)) {
        m_failureReason = "Error during WebSocket handshake: Sec-WebSocket-Accept mismatch";
        return false;
    }
    if (!serverWebSocketProtocol.empty()) {
        if (m_clientProtocol.empty()) {
            m_failureReason = "Error during WebSocket handshake: Sec-WebSocket-Protocol mismatch";
            return false;
        }
        Vector<String> result;
        static const char* subProtocolSeperator = ", ";
        String clientProtocol(m_clientProtocol.c_str());
        clientProtocol.Split(String(subProtocolSeperator), result);
        if (!result.Contains(serverWebSocketProtocol)) {
            m_failureReason = "Error during WebSocket handshake: Sec-WebSocket-Protocol mismatch";
            return false;
        }
    }
    return true;
}

} // namespace net
