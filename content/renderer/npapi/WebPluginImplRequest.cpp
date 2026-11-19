// Copyright (C) 2006-2010 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/WebPluginImpl.h"

#include <algorithm>
#include <cstring>
#include <string_view>

#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/functional/bind.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "content/renderer/npapi/npruntime_priv.h"
#include "net/http/http_request_headers.h"
#include "services/network/public/cpp/data_element.h"
#include "services/network/public/cpp/resource_request_body.h"
#include "third_party/blink/public/mojom/loader/resource_load_info.mojom-shared.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/public/platform/web_data.h"
#include "third_party/blink/public/platform/web_http_body.h"
#include "third_party/blink/public/platform/web_url_request.h"
#include "third_party/blink/public/web/web_document.h"
#include "third_party/blink/public/web/web_plugin_container.h"
#include "url/gurl.h"

namespace content {

namespace {

int hexCharToInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    return -1;
}

std::string percentDecode(std::string_view input)
{
    std::string out;
    out.reserve(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '%' && i + 2 < input.size()) {
            int hi = hexCharToInt(input[i + 1]);
            int lo = hexCharToInt(input[i + 2]);
            if (hi >= 0 && lo >= 0) {
                out.push_back(static_cast<char>((hi << 4) | lo));
                i += 2;
                continue;
            }
        }
        out.push_back(input[i]);
    }
    return out;
}

blink::KURL makePluginURL(const blink::KURL& baseURL, const char* relativeURLString)
{
    std::string raw = relativeURLString ? relativeURLString : "";
    std::erase(raw, '\n');
    std::erase(raw, '\r');
    return blink::KURL(baseURL, WTF::String::FromUTF8(raw));
}

bool isHttpHeaderTokenChar(unsigned char c)
{
    if (c <= 0x20 || c >= 0x7F)
        return false;
    switch (c) {
    case '(': case ')': case '<': case '>': case '@':
    case ',': case ';': case ':': case '\\': case '"':
    case '/': case '[': case ']': case '?': case '=':
    case '{': case '}':
        return false;
    default:
        return true;
    }
}

bool isValidPostHeaderBlock(std::string_view sv, size_t headerEnd)
{
    if (headerEnd == 0 || headerEnd > sv.size())
        return false;

    size_t pos = 0;
    size_t headerLineCount = 0;
    while (pos < headerEnd) {
        size_t eol = sv.find_first_of("\r\n", pos);
        size_t lineEnd = (eol == std::string_view::npos || eol > headerEnd) ? headerEnd : eol;
        std::string_view line = sv.substr(pos, lineEnd - pos);
        pos = lineEnd;
        if (pos < headerEnd && sv[pos] == '\r')
            ++pos;
        if (pos < headerEnd && sv[pos] == '\n')
            ++pos;

        if (line.empty())
            break;

        size_t colon = line.find(':');
        if (colon == std::string_view::npos || colon == 0)
            return false;
        for (size_t i = 0; i < colon; ++i) {
            if (!isHttpHeaderTokenChar(static_cast<unsigned char>(line[i])))
                return false;
        }
        for (size_t i = colon + 1; i < line.size(); ++i) {
            unsigned char ch = static_cast<unsigned char>(line[i]);
            if (ch == 0 || (ch < 0x20 && ch != '\t') || ch == 0x7F)
                return false;
        }
        ++headerLineCount;
    }
    return headerLineCount > 0;
}

int locationAfterFirstBlankLine(const std::vector<char>& buffer)
{
    std::string_view sv(buffer.data(), buffer.size());
    if (sv.empty())
        return -1;
    if (sv.size() >= 2 && sv[0] == '\r' && sv[1] == '\n')
        return 2;
    if (sv[0] == '\n')
        return 1;

    size_t posCRLF = sv.find("\r\n\r\n");
    size_t posLF = sv.find("\n\n");
    size_t posCRLF_LF = sv.find("\r\n\n");

    size_t bestHeaderEnd = std::string_view::npos;
    size_t bestBodyStart = std::string_view::npos;
    auto consider = [&](size_t pos, size_t sepLen) {
        if (pos != std::string_view::npos && pos < bestHeaderEnd) {
            bestHeaderEnd = pos;
            bestBodyStart = pos + sepLen;
        }
    };
    consider(posCRLF, 4);
    consider(posLF, 2);
    consider(posCRLF_LF, 3);

    if (bestBodyStart == std::string_view::npos)
        return -1;
    if (!isValidPostHeaderBlock(sv, bestHeaderEnd))
        return -1;
    return static_cast<int>(bestBodyStart);
}

void setPluginRequestReferer(blink::WebLocalFrame* webFrame, network::ResourceRequest* req)
{
    if (!webFrame || !req)
        return;
    blink::KURL docUrl = webFrame->GetDocument().Url();
    if (docUrl.ProtocolIsInHTTPFamily())
        req->headers.SetHeader("Referer", docUrl.GetString().Utf8());
}

bool isPathWithinTempDirectory(const base::FilePath& filePath)
{
    if (filePath.empty() || filePath.ReferencesParent())
        return false;
    base::FilePath tempDir;
    if (!base::GetTempDir(&tempDir) || tempDir.empty())
        return false;

#if defined(_WIN32)
    auto toNormalizedFullPath = [](const std::wstring& raw) -> std::wstring {
        DWORD needed = ::GetFullPathNameW(raw.c_str(), 0, nullptr, nullptr);
        if (needed == 0)
            return std::wstring();
        std::wstring buf(needed, L'\0');
        DWORD len = ::GetFullPathNameW(raw.c_str(), needed, buf.data(), nullptr);
        if (len == 0 || len >= needed)
            return std::wstring();
        buf.resize(len);
        for (wchar_t& ch : buf) {
            if (ch == L'/')
                ch = L'\\';
            else if (ch >= L'A' && ch <= L'Z')
                ch = static_cast<wchar_t>(ch - L'A' + L'a');
        }
        return buf;
    };

    std::wstring normTemp = toNormalizedFullPath(tempDir.value());
    std::wstring normFile = toNormalizedFullPath(filePath.value());
    if (normTemp.empty() || normFile.empty())
        return false;
    if (normTemp.back() != L'\\')
        normTemp.push_back(L'\\');
    return normFile.size() > normTemp.size() && normFile.compare(0, normTemp.size(), normTemp) == 0;
#else
    return tempDir.IsParent(filePath);
#endif
}

void parsePostHeaderFields(const char* bytes, size_t length, net::HttpRequestHeaders* outHeaders)
{
    std::string headerBlock(bytes, length);
    size_t pos = 0;
    while (pos < headerBlock.size()) {
        size_t eol = headerBlock.find_first_of("\r\n", pos);
        size_t lineEnd = (eol == std::string::npos) ? headerBlock.size() : eol;
        std::string line = headerBlock.substr(pos, lineEnd - pos);
        pos = lineEnd;
        if (pos < headerBlock.size() && headerBlock[pos] == '\r')
            ++pos;
        if (pos < headerBlock.size() && headerBlock[pos] == '\n')
            ++pos;
        if (line.empty())
            break;
        size_t colon = line.find(':');
        if (colon == std::string::npos)
            continue;
        std::string key = std::string(base::TrimWhitespaceASCII(line.substr(0, colon), base::TRIM_ALL));
        std::string val = std::string(base::TrimWhitespaceASCII(line.substr(colon + 1), base::TRIM_ALL));
        if (!key.empty())
            outHeaders->SetHeader(key, val);
    }
}

} // namespace

NPError WebPluginImpl::loadRequest(
    std::unique_ptr<network::ResourceRequest> request, const char* target, bool sendNotification, void* notifyData)
{
    if (!m_webFrame || !request || !request->url.is_valid())
        return NPERR_INVALID_URL;

    auto req = std::make_unique<PluginRequest>();
    req->request = std::move(request);
    if (target)
        req->targetFrameName = target;
    req->sendNotification = sendNotification;
    req->notifyData = notifyData;
    req->shouldAllowPopups = arePopupsAllowed();
    scheduleRequest(std::move(req));
    return NPERR_NO_ERROR;
}

void WebPluginImpl::scheduleRequest(std::unique_ptr<PluginRequest> request)
{
    m_requests.push_back(std::move(request));
    if (!m_requestTimer.IsRunning()) {
        m_requestTimer.Start(FROM_HERE, base::TimeDelta(),
            base::BindOnce(&WebPluginImpl::requestTimerFired, base::Unretained(this)));
    }
}

void WebPluginImpl::requestTimerFired()
{
    if (m_requests.empty())
        return;
    std::unique_ptr<PluginRequest> req = std::move(m_requests.front());
    m_requests.erase(m_requests.begin());

    if (!m_requests.empty() && !m_requestTimer.IsRunning()) {
        m_requestTimer.Start(FROM_HERE, base::TimeDelta(),
            base::BindOnce(&WebPluginImpl::requestTimerFired, base::Unretained(this)));
    }
    performRequest(std::move(req));
}

void WebPluginImpl::performRequest(std::unique_ptr<PluginRequest> req)
{
    if (!m_isStarted || !m_webFrame || !req || !req->request)
        return;

    scoped_refptr<WebPluginImpl> protect(this);
    std::string urlSpec = req->request->url.possibly_invalid_spec();

    if (base::StartsWith(urlSpec, "javascript:", base::CompareCase::INSENSITIVE_ASCII)) {
        std::string jsCode = percentDecode(std::string_view(urlSpec).substr(11));
        NPString npScript { jsCode.c_str(), static_cast<uint32_t>(jsCode.size()) };
        NPVariant evalResult;
        VOID_TO_NPVARIANT(evalResult);
        _NPN_EvaluateHelper(m_instance, req->shouldAllowPopups, windowScriptNPObject(), &npScript, &evalResult);

        if (m_isStarted && m_plugin && m_instance) {
            if (req->targetFrameName.empty()) {
                std::string jsStr;
                if (NPVARIANT_IS_STRING(evalResult)) {
                    NPString s = NPVARIANT_TO_STRING(evalResult);
                    if (s.UTF8Characters && s.UTF8Length > 0)
                        jsStr.assign(s.UTF8Characters, s.UTF8Length);
                }
                blink::KURL kurl(WTF::String::FromUTF8(urlSpec));
                auto stream = PluginStream::create(this, m_mbwebviewId, std::move(req->request), nullptr,
                    req->sendNotification, req->notifyData, m_plugin, m_plugin->pluginFuncs(), m_instance, m_plugin->quirks());
                m_streams.insert(stream);
                stream->sendJavaScriptStream(kurl, jsStr);
            } else if (req->sendNotification && m_plugin->pluginFuncs()->urlnotify) {
                ScopedCurrentPluginView currentGuard(this);
                setCallingPlugin(true);
                m_plugin->pluginFuncs()->urlnotify(m_instance, urlSpec.c_str(), NPRES_DONE, req->notifyData);
                setCallingPlugin(false);
            }
        }
        _NPN_ReleaseVariantValue(&evalResult);
        return;
    }

    if (req->targetFrameName.empty()) {
        scoped_refptr<const blink::SecurityOrigin> origin = blink::SecurityOrigin::CreateFromString(
            m_webFrame->GetDocument().Url().GetString());
        auto stream = PluginStream::create(this, m_mbwebviewId, std::move(req->request), std::move(origin),
            req->sendNotification, req->notifyData, m_plugin, m_plugin->pluginFuncs(), m_instance, m_plugin->quirks());
        m_streams.insert(stream);
        stream->start();
    } else if (m_pluginContainer) {
        if (req->shouldAllowPopups && m_webFrame)
            m_webFrame->NotifyUserActivation(blink::mojom::UserActivationNotificationType::kInteraction);
        blink::WebURLRequest webReq(blink::KURL(WTF::String::FromUTF8(urlSpec)));
        webReq.SetHttpMethod(blink::WebString::FromUTF8(req->request->method));
        net::HttpRequestHeaders::Iterator headerIt(req->request->headers);
        while (headerIt.GetNext()) {
            webReq.AddHttpHeaderField(
                blink::WebString::FromUTF8(headerIt.name()),
                blink::WebString::FromUTF8(headerIt.value()));
        }
        if (req->request->request_body && req->request->request_body->elements()) {
            blink::WebHTTPBody httpBody;
            httpBody.Initialize();
            bool hasBody = false;
            for (const network::DataElement& elem : *req->request->request_body->elements()) {
                if (elem.type() == network::DataElement::Tag::kBytes) {
                    std::string_view sv = elem.As<network::DataElementBytes>().AsStringPiece();
                    httpBody.AppendData(blink::WebData(sv.data(), sv.size()));
                    hasBody = true;
                }
            }
            if (hasBody)
                webReq.SetHttpBody(httpBody);
        }
        m_pluginContainer->LoadFrameRequest(webReq, blink::WebString::FromUTF8(req->targetFrameName));
        if (m_isStarted && req->sendNotification && m_plugin && m_plugin->pluginFuncs()->urlnotify && m_instance) {
            ScopedCurrentPluginView currentGuard(this);
            setCallingPlugin(true);
            m_plugin->pluginFuncs()->urlnotify(m_instance, urlSpec.c_str(), NPRES_DONE, req->notifyData);
            setCallingPlugin(false);
        }
    }
}

NPError WebPluginImpl::getURLNotify(const char* url, const char* target, void* notifyData)
{
    if (!m_webFrame || !url)
        return NPERR_INVALID_URL;
    blink::KURL resolved = makePluginURL(m_webFrame->GetDocument().BaseURL(), url);
    auto req = std::make_unique<network::ResourceRequest>();
    req->method = "GET";
    req->url = GURL(resolved.GetString().Utf8());
    req->resource_type = static_cast<int>(blink::mojom::ResourceType::kPluginResource);
    req->headers.SetHeader("User-Agent", blink::Platform::Current()->UserAgent().Utf8());
    setPluginRequestReferer(m_webFrame, req.get());
    return loadRequest(std::move(req), target, true, notifyData);
}

NPError WebPluginImpl::getURL(const char* url, const char* target)
{
    if (!m_webFrame || !url)
        return NPERR_INVALID_URL;
    blink::KURL resolved = makePluginURL(m_webFrame->GetDocument().BaseURL(), url);
    auto req = std::make_unique<network::ResourceRequest>();
    req->method = "GET";
    req->url = GURL(resolved.GetString().Utf8());
    req->resource_type = static_cast<int>(blink::mojom::ResourceType::kPluginResource);
    req->headers.SetHeader("User-Agent", blink::Platform::Current()->UserAgent().Utf8());
    setPluginRequestReferer(m_webFrame, req.get());
    return loadRequest(std::move(req), target, false, nullptr);
}

NPError WebPluginImpl::postURLNotify(const char* url, const char* target, uint32_t len, const char* buf, NPBool file, void* notifyData)
{
    return handlePost(url, target, len, buf, file != 0, notifyData, true, true);
}

NPError WebPluginImpl::postURL(const char* url, const char* target, uint32_t len, const char* buf, NPBool file)
{
    return handlePost(url, target, len, buf, file != 0, nullptr, false, file != 0);
}

NPError WebPluginImpl::handlePostReadFile(std::vector<char>& buffer, uint32_t len, const char* buf)
{
    if (!buf || len == 0)
        return NPERR_INVALID_PARAM;
    std::string filename(buf, len);
    while (!filename.empty() && filename.back() == '\0')
        filename.pop_back();
    if (base::StartsWith(filename, "file:///", base::CompareCase::INSENSITIVE_ASCII)) {
        filename.erase(0, 8);
        filename = percentDecode(filename);
    }

    base::FilePath path = base::FilePath::FromUTF8Unsafe(filename);
    // Security: disallow arbitrary local file exfiltration via NPN_PostURL(file=TRUE);
    // only allow temporary files under the OS temp directory.
    if (!isPathWithinTempDirectory(path))
        return NPERR_FILE_NOT_FOUND;

    std::string contents;
    if (!base::ReadFileToString(path, &contents))
        return NPERR_FILE_NOT_FOUND;
    buffer.assign(contents.begin(), contents.end());
    return NPERR_NO_ERROR;
}

NPError WebPluginImpl::handlePost(
    const char* url, const char* target, uint32_t len, const char* buf, bool file, void* notifyData, bool sendNotification, bool allowHeaders)
{
    if (!m_webFrame || !url || (len > 0 && !buf))
        return NPERR_INVALID_PARAM;

    std::vector<char> buffer;
    if (file) {
        NPError readErr = handlePostReadFile(buffer, len, buf);
        if (readErr != NPERR_NO_ERROR)
            return readErr;
    } else if (len > 0) {
        buffer.assign(buf, buf + len);
    }

    const char* postData = buffer.empty() ? "" : buffer.data();
    size_t postDataLen = buffer.size();

    auto req = std::make_unique<network::ResourceRequest>();
    req->method = "POST";
    blink::KURL resolved = makePluginURL(m_webFrame->GetDocument().BaseURL(), url);
    req->url = GURL(resolved.GetString().Utf8());
    req->resource_type = static_cast<int>(blink::mojom::ResourceType::kPluginResource);
    req->headers.SetHeader("User-Agent", blink::Platform::Current()->UserAgent().Utf8());
    setPluginRequestReferer(m_webFrame, req.get());

    if (allowHeaders && !buffer.empty()) {
        int loc = locationAfterFirstBlankLine(buffer);
        if (loc != -1) {
            if (loc > 2)
                parsePostHeaderFields(buffer.data(), static_cast<size_t>(loc), &req->headers);
            req->headers.RemoveHeader("Content-Length");
            postData = buffer.data() + loc;
            postDataLen = buffer.size() - static_cast<size_t>(loc);
        }
    }

    req->request_body = network::ResourceRequestBody::CreateFromBytes(postData, postDataLen);
    return loadRequest(std::move(req), target, sendNotification, notifyData);
}

NPError WebPluginImpl::newStream(NPMIMEType, const char*, NPStream**)
{
    return NPERR_GENERIC_ERROR;
}

int32_t WebPluginImpl::write(NPStream*, int32_t, void*)
{
    return -1;
}

NPError WebPluginImpl::destroyStream(NPStream* stream, NPReason reason)
{
    if (!stream || !stream->ndata || PluginStream::ownerForStream(stream) != m_instance)
        return NPERR_INVALID_INSTANCE_ERROR;
    static_cast<PluginStream*>(stream->ndata)->cancelAndDestroyStream(reason);
    return NPERR_NO_ERROR;
}

void WebPluginImpl::disconnectStream(PluginStream* stream)
{
    for (auto it = m_streams.begin(); it != m_streams.end(); ++it) {
        if (it->get() == stream) {
            m_streams.erase(it);
            break;
        }
    }
}

void WebPluginImpl::DidReceiveResponse(const blink::WebURLResponse& response)
{
    if (m_status != PluginStatusLoadedSuccessfully || !m_plugin)
        return;

    registerManualPlugin();

    auto req = std::make_unique<network::ResourceRequest>();
    req->method = "GET";
    req->url = GURL(response.CurrentRequestUrl().GetString().Utf8());
    req->resource_type = static_cast<int>(blink::mojom::ResourceType::kObject);
    m_manualStream = PluginStream::create(
        this, m_mbwebviewId, std::move(req), nullptr, false, nullptr, m_plugin, m_plugin->pluginFuncs(), m_instance, m_plugin->quirks());
    m_manualStream->setLoadManually(true);
    m_manualStream->didReceiveResponseManual(response);
}

void WebPluginImpl::DidReceiveData(base::span<const char> data)
{
    if (m_status == PluginStatusLoadedSuccessfully && m_manualStream)
        m_manualStream->didReceiveDataManual(data);
}

void WebPluginImpl::DidFinishLoading()
{
    if (m_status == PluginStatusLoadedSuccessfully && m_manualStream)
        m_manualStream->didFinishLoadingManual();
}

void WebPluginImpl::DidFailLoading(const blink::WebURLError& error)
{
    if (m_status == PluginStatusLoadedSuccessfully && m_manualStream)
        m_manualStream->didFailManual(error);
}

} // namespace content
