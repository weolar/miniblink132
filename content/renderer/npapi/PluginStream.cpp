// Copyright (C) 2006, 2007, 2008 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#include "content/renderer/npapi/PluginStream.h"

#include <algorithm>
#include <cstring>
#include <map>

#include "base/files/file_util.h"
#include "base/functional/bind.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"
#include "base/task/single_thread_task_runner.h"
#include "content/renderer/npapi/WebPluginImpl.h"
#include "mbnet/WebURLLoaderImplCurl.h"
#include "third_party/blink/public/mojom/loader/resource_load_info.mojom-shared.h"
#include "third_party/blink/public/platform/web_http_header_visitor.h"

namespace content {

namespace {

constexpr NPReason kWebReasonNone = -2;

std::string filePathToPluginAnsi(const base::FilePath& path)
{
#if defined(_WIN32)
    const std::wstring& wide = path.value();
    if (wide.empty())
        return std::string();

    std::wstring pathForAnsi = wide;
    DWORD shortLen = ::GetShortPathNameW(wide.c_str(), nullptr, 0);
    if (shortLen > 0) {
        std::wstring shortBuf(shortLen, L'\0');
        DWORD written = ::GetShortPathNameW(wide.c_str(), shortBuf.data(), shortLen);
        if (written > 0 && written < shortLen) {
            shortBuf.resize(written);
            pathForAnsi = std::move(shortBuf);
        }
    }

    int ansiLen = ::WideCharToMultiByte(CP_ACP, 0, pathForAnsi.c_str(), -1, nullptr, 0, nullptr, nullptr);
    if (ansiLen > 1) {
        std::string ansi(static_cast<size_t>(ansiLen), '\0');
        int written = ::WideCharToMultiByte(CP_ACP, 0, pathForAnsi.c_str(), -1, ansi.data(), ansiLen, nullptr, nullptr);
        if (written > 1) {
            ansi.resize(static_cast<size_t>(written - 1));
            return ansi;
        }
    }
#endif
    return path.AsUTF8Unsafe();
}

std::map<NPStream*, NPP>& streamMap()
{
    static auto* s_streams = new std::map<NPStream*, NPP>();
    return *s_streams;
}

class ResponseHeaderBuilder : public blink::WebHTTPHeaderVisitor {
public:
    explicit ResponseHeaderBuilder(std::string* out)
        : m_out(out)
    {
    }
    void VisitHeader(const blink::WebString& name, const blink::WebString& value) override
    {
        m_out->append(name.Utf8());
        m_out->append(": ");
        m_out->append(value.Utf8());
        m_out->push_back('\n');
    }

private:
    std::string* m_out;
};

} // namespace

scoped_refptr<PluginStream> PluginStream::create(PluginStreamClient* client, int64_t mbwebviewId,
    std::unique_ptr<network::ResourceRequest> request, scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
    bool sendNotification, void* notifyData, scoped_refptr<PluginPackage> pluginPackage,
    const NPPluginFuncs* pluginFuncs, NPP instance, const PluginQuirkSet& quirks)
{
    return base::WrapRefCounted(new PluginStream(client, mbwebviewId, std::move(request),
        std::move(topFrameOrigin), sendNotification, notifyData, std::move(pluginPackage), pluginFuncs, instance, quirks));
}

PluginStream::PluginStream(PluginStreamClient* client, int64_t mbwebviewId, std::unique_ptr<network::ResourceRequest> request,
    scoped_refptr<const blink::SecurityOrigin> topFrameOrigin, bool sendNotification, void* notifyData,
    scoped_refptr<PluginPackage> pluginPackage, const NPPluginFuncs* pluginFuncs, NPP instance, const PluginQuirkSet& quirks)
    : m_client(client)
    , m_mbwebviewId(mbwebviewId)
    , m_request(std::move(request))
    , m_topFrameOrigin(std::move(topFrameOrigin))
    , m_notifyData(notifyData)
    , m_sendNotification(sendNotification)
    , m_pluginPackage(std::move(pluginPackage))
    , m_pluginFuncs(pluginFuncs)
    , m_instance(instance)
    , m_reason(kWebReasonNone)
    , m_quirks(quirks)
    , m_keepAlive(this)
{
    if (m_request) {
        m_requestUrlSpec = m_request->url.possibly_invalid_spec();
        m_requestMethod = m_request->method;
    }
    memset(&m_stream, 0, sizeof(m_stream));
    streamMap()[&m_stream] = m_instance;
}

PluginStream::~PluginStream()
{
    streamMap().erase(&m_stream);
}

NPP PluginStream::ownerForStream(NPStream* stream)
{
    auto it = streamMap().find(stream);
    return (it == streamMap().end()) ? nullptr : it->second;
}

void PluginStream::setDefersLoading(bool defers)
{
    if (m_loader) {
        m_loader->Freeze(defers ? blink::LoaderFreezeMode::kStrict : blink::LoaderFreezeMode::kNone);
    }
}

void PluginStream::start()
{
    if (m_loadManually || !m_request)
        return;

    // Never let plugin stream fetches default to ResourceType::kMainFrame (0),
    // otherwise mbnet treats binary game assets (e.g. .data/.bin) as frame downloads.
    if (m_request->resource_type == static_cast<int>(blink::mojom::ResourceType::kMainFrame)
        || m_request->resource_type == static_cast<int>(blink::mojom::ResourceType::kSubFrame)) {
        m_request->resource_type = static_cast<int>(blink::mojom::ResourceType::kPluginResource);
    }

    scoped_refptr<base::SingleThreadTaskRunner> runner = base::SingleThreadTaskRunner::GetCurrentDefault();
    m_loader = std::make_unique<mbnet::WebURLLoaderImplCurl>(runner, runner, nullptr, m_mbwebviewId);
    m_loader->LoadAsynchronously(std::move(m_request), m_topFrameOrigin, /*noMimeSniffing=*/true, nullptr, nullptr, this);
}

void PluginStream::stop()
{
    scoped_refptr<PluginStream> protect(this);
    m_streamState = StreamStopped;
    m_stream.ndata = nullptr;
    m_delayDeliveryTimer.Stop();
    if (m_bodyWatcher) {
        m_bodyWatcher->Cancel();
        m_bodyWatcher.reset();
    }
    m_bodyPipe.reset();
    m_loader.reset();
    m_deliveryData.clear();
    if (m_tempFile.IsValid())
        m_tempFile.Close();
    if (!m_tempFilePath.empty()) {
        base::DeleteFile(m_tempFilePath);
        m_tempFilePath.clear();
    }
    m_client = nullptr;
    m_keepAlive.reset();
}

void PluginStream::startStream()
{
    if (m_streamState != StreamBeforeStarted || !m_pluginFuncs || !m_pluginFuncs->newstream || !WebPluginImpl::isAlive(m_instance))
        return;

    blink::KURL responseURL(m_resourceResponse.CurrentRequestUrl());
    m_streamUrlStorage = responseURL.IsEmpty() ? m_requestUrlSpec : responseURL.GetString().Utf8();
    m_stream.url = m_streamUrlStorage.c_str();

    std::string mimeTypeStr = m_resourceResponse.MimeType().Utf8();
    if (mimeTypeStr.empty() && m_streamUrlStorage.size() >= 4
        && base::EndsWith(m_streamUrlStorage, ".swf", base::CompareCase::INSENSITIVE_ASCII)) {
        mimeTypeStr = "application/x-shockwave-flash";
    }

    int64_t expectedContentLength = m_resourceResponse.ExpectedContentLength();
    if (responseURL.ProtocolIsInHTTPFamily()) {
        std::string statusText = m_resourceResponse.HttpStatusText().Utf8();
        if (statusText.empty())
            statusText = (m_resourceResponse.HttpStatusCode() == 200) ? "OK" : "Status";
        m_headersStorage = "HTTP/1.1 " + base::NumberToString(m_resourceResponse.HttpStatusCode()) + " " + statusText + "\n";
        ResponseHeaderBuilder visitor(&m_headersStorage);
        m_resourceResponse.VisitHttpHeaderFields(&visitor);

        std::string contentEncoding = m_resourceResponse.HttpHeaderField(blink::WebString::FromASCII("Content-Encoding")).Utf8();
        if (!contentEncoding.empty() && !base::EqualsCaseInsensitiveASCII(contentEncoding, "identity"))
            expectedContentLength = -1;
    }

    m_stream.headers = m_headersStorage.empty() ? nullptr : m_headersStorage.c_str();
    m_stream.pdata = nullptr;
    m_stream.ndata = this;
    m_stream.end = static_cast<uint32_t>(std::max<int64_t>(expectedContentLength, 0));
    m_stream.lastmodified = static_cast<uint32_t>(m_resourceResponse.ResponseTime().InSecondsFSinceUnixEpoch());
    m_stream.notifyData = m_notifyData;

    m_transferMode = NP_NORMAL;
    m_offset = 0;
    m_reason = kWebReasonNone;

    scoped_refptr<PluginStream> protect(this);

    setDefersLoading(true);
    NPError npErr = NPERR_GENERIC_ERROR;
    {
        WebPluginImpl::ScopedCurrentPluginView currentGuard(WebPluginImpl::fromInstance(m_instance));
        npErr = m_pluginFuncs->newstream(
            m_instance, const_cast<NPMIMEType>(mimeTypeStr.c_str()), &m_stream, false, &m_transferMode);
    }
    setDefersLoading(false);

    // Reentrancy during NPP_NewStream may have stopped/destroyed the stream or plugin instance.
    if (m_streamState == StreamStopped || m_reason != kWebReasonNone || !WebPluginImpl::isAlive(m_instance))
        return;

    if (npErr != NPERR_NO_ERROR) {
        cancelAndDestroyStream(npErr);
        return;
    }

    m_streamState = StreamStarted;

    if (m_transferMode == NP_NORMAL)
        return;

    if (!base::CreateTemporaryFile(&m_tempFilePath)) {
        cancelAndDestroyStream(NPRES_NETWORK_ERR);
        return;
    }
    m_tempFile.Initialize(m_tempFilePath, base::File::FLAG_OPEN_ALWAYS | base::File::FLAG_WRITE);
    if (!m_tempFile.IsValid())
        cancelAndDestroyStream(NPRES_NETWORK_ERR);
}

void PluginStream::cancelAndDestroyStream(NPReason reason)
{
    scoped_refptr<PluginStream> protect(this);
    destroyStream(reason);
    stop();
}

void PluginStream::destroyStream(NPReason reason)
{
    m_reason = reason;
    if (m_reason != NPRES_DONE) {
        m_deliveryData.clear();
    } else if (!m_deliveryData.empty()) {
        return;
    }
    destroyStreamImpl();
}

void PluginStream::destroyStreamImpl()
{
    if (m_streamState == StreamStopped)
        return;

    scoped_refptr<PluginStream> protect(this);
    m_keepAlive.reset();

    if (m_tempFile.IsValid())
        m_tempFile.Close();

    bool newStreamCalled = (m_stream.ndata != nullptr);
    if (newStreamCalled && m_pluginFuncs && WebPluginImpl::isAlive(m_instance)) {
        if (m_reason == NPRES_DONE && (m_transferMode == NP_ASFILE || m_transferMode == NP_ASFILEONLY)
            && !m_tempFilePath.empty() && m_pluginFuncs->asfile) {
            setDefersLoading(true);
            std::string ansiTempPath = filePathToPluginAnsi(m_tempFilePath);
            {
                WebPluginImpl::ScopedCurrentPluginView currentGuard(WebPluginImpl::fromInstance(m_instance));
                m_pluginFuncs->asfile(m_instance, &m_stream, ansiTempPath.c_str());
            }
            setDefersLoading(false);
        }

        if (m_streamState == StreamStarted && m_pluginFuncs->destroystream && WebPluginImpl::isAlive(m_instance)) {
            setDefersLoading(true);
            {
                WebPluginImpl::ScopedCurrentPluginView currentGuard(WebPluginImpl::fromInstance(m_instance));
                m_pluginFuncs->destroystream(m_instance, &m_stream, m_reason);
            }
            setDefersLoading(false);
        }
        m_stream.ndata = nullptr;
    }

    if (m_streamState != StreamStopped && m_sendNotification && m_pluginFuncs && m_pluginFuncs->urlnotify && WebPluginImpl::isAlive(m_instance)) {
        setDefersLoading(true);
        {
            WebPluginImpl::ScopedCurrentPluginView currentGuard(WebPluginImpl::fromInstance(m_instance));
            if (!newStreamCalled && m_quirks.contains(PluginQuirkFlashURLNotifyBug)
                && base::EqualsCaseInsensitiveASCII(m_requestMethod, "POST")) {
                m_transferMode = NP_NORMAL;
                m_stream.url = "";
                m_stream.notifyData = m_notifyData;
                static char kEmptyMimeType[] = "";
                if (m_pluginFuncs->newstream)
                    m_pluginFuncs->newstream(m_instance, kEmptyMimeType, &m_stream, false, &m_transferMode);
                if (m_streamState != StreamStopped && WebPluginImpl::isAlive(m_instance) && m_pluginFuncs->destroystream)
                    m_pluginFuncs->destroystream(m_instance, &m_stream, m_reason);
                m_stream.url = nullptr;
            }
            if (m_streamState != StreamStopped && WebPluginImpl::isAlive(m_instance))
                m_pluginFuncs->urlnotify(m_instance, m_requestUrlSpec.c_str(), m_reason, m_notifyData);
        }
        setDefersLoading(false);
    }

    m_streamState = StreamStopped;

    if (!m_loadManually && m_client)
        m_client->streamDidFinishLoading(this);

    if (!m_tempFilePath.empty()) {
        base::DeleteFile(m_tempFilePath);
        m_tempFilePath.clear();
    }
}

void PluginStream::delayDeliveryTimerFired()
{
    deliverData();
}

void PluginStream::deliverData()
{
    if (m_isDeliveringData || m_streamState == StreamStopped || !m_stream.ndata || m_deliveryData.empty()
        || !m_pluginFuncs || !m_pluginFuncs->write || !WebPluginImpl::isAlive(m_instance)) {
        return;
    }

    scoped_refptr<PluginStream> protect(this);
    m_isDeliveringData = true;
    setDefersLoading(true);

    while (m_streamState != StreamStopped && m_stream.ndata && !m_deliveryData.empty() && WebPluginImpl::isAlive(m_instance)) {
        int32_t totalBytes = static_cast<int32_t>(m_deliveryData.size());
        int32_t deliveryBytes = totalBytes;
        if (m_pluginFuncs->writeready) {
            WebPluginImpl::ScopedCurrentPluginView currentGuard(WebPluginImpl::fromInstance(m_instance));
            deliveryBytes = m_pluginFuncs->writeready(m_instance, &m_stream);
        }
        if (m_streamState == StreamStopped || !m_stream.ndata || !WebPluginImpl::isAlive(m_instance))
            break;

        if (deliveryBytes <= 0) {
            if (!m_delayDeliveryTimer.IsRunning()) {
                m_delayDeliveryTimer.Start(FROM_HERE, base::TimeDelta(),
                    base::BindOnce(&PluginStream::delayDeliveryTimerFired, base::Unretained(this)));
            }
            break;
        }

        int32_t dataLength = std::min(deliveryBytes, static_cast<int32_t>(m_deliveryData.size()));
        std::vector<char> chunk(m_deliveryData.begin(), m_deliveryData.begin() + dataLength);

        int32_t written = -1;
        {
            WebPluginImpl::ScopedCurrentPluginView currentGuard(WebPluginImpl::fromInstance(m_instance));
            written = m_pluginFuncs->write(m_instance, &m_stream, m_offset, dataLength, chunk.data());
        }
        if (m_streamState == StreamStopped || !m_stream.ndata || !WebPluginImpl::isAlive(m_instance))
            break;

        if (written < 0) {
            setDefersLoading(false);
            m_isDeliveringData = false;
            cancelAndDestroyStream(NPRES_NETWORK_ERR);
            return;
        }
        if (written == 0) {
            if (!m_delayDeliveryTimer.IsRunning()) {
                m_delayDeliveryTimer.Start(FROM_HERE, base::TimeDelta(),
                    base::BindOnce(&PluginStream::delayDeliveryTimerFired, base::Unretained(this)));
            }
            break;
        }

        written = std::min(written, dataLength);
        m_offset += written;
        if (static_cast<size_t>(written) >= m_deliveryData.size()) {
            m_deliveryData.clear();
        } else {
            m_deliveryData.erase(m_deliveryData.begin(), m_deliveryData.begin() + written);
        }
    }

    setDefersLoading(false);
    m_isDeliveringData = false;

    if (m_streamState != StreamStopped && m_deliveryData.empty() && m_reason != kWebReasonNone)
        destroyStreamImpl();
}

void PluginStream::sendJavaScriptStream(const blink::KURL& requestURL, const std::string& resultString)
{
    blink::WebURLResponse response(requestURL);
    response.SetExpectedContentLength(static_cast<int64_t>(resultString.size()));
    response.SetMimeType(blink::WebString::FromASCII("text/plain"));
    didReceiveResponseManual(response);

    if (m_streamState == StreamStopped)
        return;

    if (!resultString.empty()) {
        didReceiveDataManual(base::span<const char>(resultString.data(), resultString.size()));
        if (m_streamState == StreamStopped)
            return;
    }

    m_loader.reset();
    destroyStream(NPRES_DONE);
}

void PluginStream::didReceiveResponseManual(const blink::WebURLResponse& response)
{
    m_resourceResponse = response;
    startStream();
}

void PluginStream::didReceiveDataManual(base::span<const char> data)
{
    if (m_streamState != StreamStarted || data.empty())
        return;

    scoped_refptr<PluginStream> protect(this);

    if (m_transferMode != NP_ASFILEONLY) {
        size_t oldSize = m_deliveryData.size();
        m_deliveryData.resize(oldSize + data.size());
        memcpy(m_deliveryData.data() + oldSize, data.data(), data.size());
        deliverData();
    }

    if (m_streamState != StreamStopped && m_tempFile.IsValid()) {
        int written = m_tempFile.WriteAtCurrentPos(data.data(), static_cast<int>(data.size()));
        if (written != static_cast<int>(data.size()))
            cancelAndDestroyStream(NPRES_NETWORK_ERR);
    }
}

void PluginStream::didFinishLoadingManual()
{
    if (m_streamState == StreamStopped || m_reason != kWebReasonNone)
        return;
    scoped_refptr<PluginStream> protect(this);
    destroyStream(NPRES_DONE);
    if (m_bodyWatcher) {
        m_bodyWatcher->Cancel();
        m_bodyWatcher.reset();
    }
    m_bodyPipe.reset();
    m_loader.reset();
}

void PluginStream::didFailManual(const blink::WebURLError&)
{
    scoped_refptr<PluginStream> protect(this);
    destroyStream(NPRES_NETWORK_ERR);
    if (m_bodyWatcher) {
        m_bodyWatcher->Cancel();
        m_bodyWatcher.reset();
    }
    m_bodyPipe.reset();
    m_loader.reset();
}

void PluginStream::DidReceiveResponse(const blink::WebURLResponse& response,
    absl::variant<mojo::ScopedDataPipeConsumerHandle, WTF::SegmentedBuffer> body,
    std::optional<mojo_base::BigBuffer>)
{
    didReceiveResponseManual(response);
    if (m_streamState == StreamStopped)
        return;

    if (auto* pipe = absl::get_if<mojo::ScopedDataPipeConsumerHandle>(&body)) {
        if (pipe->is_valid()) {
            m_bodyPipe = std::move(*pipe);
            drainBodyPipe();
            if (m_streamState != StreamStopped && m_bodyPipe.is_valid()) {
                m_bodyWatcher = std::make_unique<mojo::SimpleWatcher>(
                    FROM_HERE, mojo::SimpleWatcher::ArmingPolicy::AUTOMATIC, base::SingleThreadTaskRunner::GetCurrentDefault());
                m_bodyWatcher->Watch(m_bodyPipe.get(), MOJO_HANDLE_SIGNAL_READABLE | MOJO_HANDLE_SIGNAL_PEER_CLOSED,
                    base::BindRepeating(&PluginStream::onBodyPipeReadable, base::Unretained(this)));
            }
        }
    } else if (auto* segBuf = absl::get_if<WTF::SegmentedBuffer>(&body)) {
        for (const auto& span : *segBuf) {
            didReceiveDataManual(span);
            if (m_streamState == StreamStopped)
                return;
        }
    }
}

void PluginStream::DidReceiveDataForTesting(base::span<const char> data)
{
    didReceiveDataManual(data);
}

void PluginStream::onBodyPipeReadable(MojoResult)
{
    drainBodyPipe();
}

void PluginStream::drainBodyPipe()
{
    if (!m_bodyPipe.is_valid() || m_streamState == StreamStopped)
        return;

    scoped_refptr<PluginStream> protect(this);
    while (m_bodyPipe.is_valid() && m_streamState != StreamStopped) {
        base::span<const uint8_t> buffer;
        MojoResult rv = m_bodyPipe->BeginReadData(MOJO_READ_DATA_FLAG_NONE, buffer);
        if (rv == MOJO_RESULT_OK) {
            size_t numBytes = buffer.size();
            std::vector<char> copy;
            if (numBytes > 0) {
                copy.resize(numBytes);
                memcpy(copy.data(), buffer.data(), numBytes);
            }
            m_bodyPipe->EndReadData(numBytes);
            if (!copy.empty()) {
                didReceiveDataManual(base::span<const char>(copy.data(), copy.size()));
            }
        } else if (rv == MOJO_RESULT_FAILED_PRECONDITION) {
            if (m_bodyWatcher) {
                m_bodyWatcher->Cancel();
                m_bodyWatcher.reset();
            }
            m_bodyPipe.reset();
            break;
        } else {
            break;
        }
    }
}

void PluginStream::DidFinishLoading(base::TimeTicks, int64_t, uint64_t, int64_t)
{
    scoped_refptr<PluginStream> protect(this);
    drainBodyPipe();
    if (m_streamState != StreamStopped)
        didFinishLoadingManual();
}

void PluginStream::DidFail(const blink::WebURLError& error, base::TimeTicks, int64_t, uint64_t, int64_t)
{
    didFailManual(error);
}

} // namespace content
