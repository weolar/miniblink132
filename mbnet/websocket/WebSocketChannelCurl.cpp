/*
 * Copyright (C) 2011, 2012 Google Inc.  All rights reserved.
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

#include "mbnet/websocket/WebSocketChannelCurl.h"

#include "content/common/LiveIdDetect.h"
#include "mbnet/websocket/SocketStreamError.h"
#include "mbnet/websocket/SocketStreamHandle.h"
#include "mbnet/websocket/WebSocketHandshake.h"

#include "third_party/blink/renderer/core/inspector/console_message.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/blob/blob_data.h"
#include "third_party/blink/renderer/core/typed_arrays/dom_array_buffer.h"
#include "third_party/blink/renderer/modules/websockets/websocket_channel_client.h"

#include "base/task/single_thread_task_runner.h"

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
#include "wke/wkeWebView.h"
#include "wke/wkeString.h"
#include "wke/wkeGlobalVar.h"
#endif

namespace mbnet {

const double TCPMaximumSegmentLifetime = 2 * 60.0;

// class WebSocketChannelCurl::BlobLoader final : public GarbageCollectedFinalized<WebSocketChannelCurl::BlobLoader>, public FileReaderLoaderClient {
// public:
//     BlobLoader(PassRefPtr<BlobDataHandle>, WebSocketChannelCurl*);
//     ~BlobLoader() override { }
//
//     void cancel();
//
//     // FileReaderLoaderClient functions.
//     void didStartLoading() override { }
//     void didReceiveData() override { }
//     void didFinishLoading() override;
//     void didFail(FileError::ErrorCode) override;
//
//     DOMArrayBuffer* arrayBufferResult() /*const*/
//     {
//         return m_loader->arrayBufferResult();
//     }
//
//     DEFINE_INLINE_TRACE()
//     {
//         visitor->trace(m_channel);
//     }
//
// private:
//     Member<WebSocketChannelCurl> m_channel;
//     std::unique_ptr<FileReaderLoader> m_loader;
// };
//
// WebSocketChannelCurl::BlobLoader::BlobLoader(PassRefPtr<BlobDataHandle> blobDataHandle, WebSocketChannelCurl* channel)
//     : m_channel(channel)
//     , m_loader(blink::FileReaderLoader::create(FileReaderLoader::ReadAsArrayBuffer, this))
// {
//     m_loader->start(channel->getExecutionContext(), adoptRef(blobDataHandle.leakRef()));
// }
//
// void WebSocketChannelCurl::BlobLoader::cancel()
// {
//     m_loader->cancel();
//     // didFail will be called immediately.
//     // |this| is deleted here.
// }
//
// void WebSocketChannelCurl::BlobLoader::didFinishLoading()
// {
//     m_channel->didFinishLoadingBlob(m_loader->arrayBufferResult());
//     // |this| is deleted here.
// }
//
// void WebSocketChannelCurl::BlobLoader::didFail(FileError::ErrorCode errorCode)
// {
//     m_channel->didFailLoadingBlob(errorCode);
//     // |this| is deleted here.
// }
// -------------------------
// typedef bool(WKE_CALL_TYPE* wkeWebSocketWillConnectCallback)(wkeWebView webView, void* param, void* channel, wkeString url);
//
// void WKE_CALL_TYPE WSCI_setHook(void* channel, void* hookInfo)
// {
//     if (!channel || !hookInfo)
//         return;
//     WebSocketChannelCurl::WebsocketHookInfo* hookInfoPtr = (WebSocketChannelCurl::WebsocketHookInfo*)hookInfo;
//     WebSocketChannelCurl* channelPtr = (WebSocketChannelCurl*)channel;
//     channelPtr->setHookInfo(*hookInfoPtr);
// }
//
// void WKE_CALL_TYPE WSCI_sendText(void* channel, char* buf, size_t len)
// {
//     if (channel && buf && len) {
//         WebSocketChannelCurl* channelPtr = (WebSocketChannelCurl*)channel;
//         channelPtr->send(CString(buf, len), true);
//     }
// }
//
// void WKE_CALL_TYPE WSCI_sendBlob(void* channel, char* buf, size_t len)
// {
//     if (channel && buf && len) {
//         WebSocketChannelCurl* channelPtr = (WebSocketChannelCurl*)channel;
//         channelPtr->send(buf, len, true);
//     }
// }

WebSocketChannelCurl* WebSocketChannelCurl::create(
    blink::ExecutionContext* context, blink::WebSocketChannelClient* client, std::unique_ptr<blink::SourceLocation> location)
{
    WebSocketChannelCurl* channel = blink::MakeGarbageCollected<WebSocketChannelCurl>(context, client, std::move(location));
    return channel;
}

WebSocketChannelCurl::WebSocketChannelCurl(
    blink::ExecutionContext* context, blink::WebSocketChannelClient* client, std::unique_ptr<blink::SourceLocation> location)
    //: ContextLifecycleObserver(context)
    : m_ref(0)
    , m_client(client)
    , m_resumeTimer(base::SingleThreadTaskRunner::GetCurrentDefault(), this, &WebSocketChannelCurl::resumeTimerFired)
    , m_suspended(false)
    , m_closing(false)
    , m_receivedClosingHandshake(false)
    , m_closingTimer(base::SingleThreadTaskRunner::GetCurrentDefault(), this, &WebSocketChannelCurl::closingTimerFired)
    , m_closed(false)
    , m_shouldDiscardReceivedData(false)
    , m_unhandledBufferedAmount(0)
    , m_id(0)
    , m_hasContinuousFrame(false)
    , m_closeEventCode(CloseEventCodeAbnormalClosure)
    , m_outgoingFrameQueueStatus(OutgoingFrameQueueOpen)
    , m_executionContext(context)
    //, m_blobLoaderStatus(BlobLoaderNotStarted)
    , m_sourceURLAtConstruction(location->Url())
    , m_lineNumberAtConstruction(location->LineNumber())
    , m_isClosing(false)
{
    m_id = common::LiveIdDetect::get()->constructed(this);
    m_handleId = 0;

    //WTF_LOG(Network, "WebSocketChannelCurl %p ctor, identifier %lu", this, m_id);
}

WebSocketChannelCurl::~WebSocketChannelCurl()
{
    //DCHECK(!m_blobLoader);
    //DCHECK(0 == m_ref);
    //WTF_LOG(Network, "WebSocketChannelCurl %p dtor", this);
    common::LiveIdDetect::get()->deconstructed(m_id);
}

void WebSocketChannelCurl::dispose()
{
}

// Document* WebSocketChannelCurl::document()
// {
//     DCHECK(m_id);
//     ExecutionContext* context = getExecutionContext();
//     if (!context)
//         return nullptr;
//     DCHECK(context->isDocument());
//     return toDocument(context);
// }

void WebSocketChannelCurl::send(const std::string& message, bool isFromHook, base::OnceClosure completionCallback)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p send() Sending String '%s'", this, message.data());
    enqueueTextFrame(message, isFromHook, std::move(completionCallback));
    processOutgoingFrameQueue();
    // According to WebSocket API specification, WebSocket.send() should return void instead
    // of boolean. However, our implementation still returns boolean due to compatibility
    // concern (see bug 65850).
    // m_channel->send() may happen later, thus it's not always possible to know whether
    // the message has been sent to the socket successfully. In this case, we have no choice
    // but to return true.
}

// void WebSocketChannelCurl::send(const DOMArrayBuffer& binaryData, unsigned byteOffset, unsigned byteLength)
// {
//     //WTF_LOG(Network, "WebSocketChannelCurl %p send() Sending ArrayBuffer %p byteOffset=%u byteLength=%u", this, &binaryData, byteOffset, byteLength);
//     enqueueRawFrame(WebSocketOneFrame::OpCodeBinary, static_cast<const char*>(binaryData.data()) + byteOffset, byteLength, false);
//     processOutgoingFrameQueue();
// }
//
// void WebSocketChannelCurl::send(PassRefPtr<BlobDataHandle> blobDataHandle)
// {
//     //WTF_LOG(Network, "DocumentWebSocketChannel %p sendBlob(%s, %s, %llu)", this, blobDataHandle->uuid().utf8().data(), blobDataHandle->type().utf8().data(), blobDataHandle->size());
//     enqueueBlobFrame(WebSocketOneFrame::OpCodeBinary, adoptRef(blobDataHandle.leakRef()));
//     processOutgoingFrameQueue();
// }

bool WebSocketChannelCurl::send(const char* data, int length, bool isFromHook)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p send() Sending char* data=%p length=%d", this, data, length);
    enqueueRawFrame(WebSocketOneFrame::OpCodeBinary, data, length, isFromHook);
    processOutgoingFrameQueue();
    return true;
}

unsigned long WebSocketChannelCurl::bufferedAmount() const
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p bufferedAmount()", this);
    DCHECK(m_handle);
    DCHECK(!m_suspended);

    DebugBreak();
    //     if (common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
    //         return m_handle->bufferedAmount();
    return 0;
}

void WebSocketChannelCurl::fail(const String& reason /*, MessageLevel, std::unique_ptr<blink::SourceLocation>*/)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p fail() reason='%s'", this, reason.utf8().data());
    DCHECK(!m_suspended);
    if (m_executionContext) {
        //InspectorInstrumentation::didReceiveWebSocketFrameError(document(), m_id, reason);

        String consoleMessage;
        if (m_handshake)
            consoleMessage
                = String::Format("WebSocket connection to '%s %s %s", m_handshake->url().GetString().Utf8().c_str(), "' failed: ", reason.Utf8().c_str());
        else
            consoleMessage = String::Format("WebSocket connection failed: %s", reason.Utf8().c_str());

        m_executionContext->AddConsoleMessage(blink::MakeGarbageCollected<blink::ConsoleMessage>(
            blink::mojom::blink::ConsoleMessageSource::kNetwork, blink::mojom::blink::ConsoleMessageLevel::kError, consoleMessage));
    }
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    if (m_hookInfo.onError) {
        WebViewImpl* view = (WebViewImpl*)document()->page()->chromeClient().webView();
        if (view) {
            content::WebPageImpl* pageImpl = (content::WebPageImpl*)view->client();
            if (pageImpl) {
                content::WebPage* page = pageImpl->m_pagePtr;
                m_hookInfo.onError(page->wkeWebView(), m_hookInfo.param, this);
            }
        }
    }
#endif
    // Hybi-10 specification explicitly states we must not continue to handle incoming data
    // once the WebSocket connection is failed (section 7.1.7).
    //scoped_refptr<WebSocketChannelCurl> protect(*this); // The client can close the channel, potentially removing the last reference.

    m_shouldDiscardReceivedData = true;
    if (!m_buffer.empty())
        skipBuffer(m_buffer.size()); // Save memory.
    m_deflateFramer.didFail();
    m_hasContinuousFrame = false;
    m_continuousFrameData.clear();
    m_client->DidError();

    if (m_handle && !m_closed && common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
        m_handle->disconnect(); // Will call didClose().

    // We should be closed by now, but if we never got a handshake then we never even opened.
    DCHECK(m_closed || !m_handshake);
}

void WebSocketChannelCurl::sendTextAsCharVector(std::unique_ptr<Vector<char>> data)
{
    ////WTF_LOG(Network, "DocumentWebSocketChannel %p sendTextAsCharVector(%p, %llu)", this, data.get(), static_cast<unsigned long long>(data->size()));
    if (m_id) {
        // FIXME: Change the inspector API to show the entire message instead
        // of individual frames.
        //InspectorInstrumentation::didSendWebSocketFrame(document(), m_id, WebSocketOneFrame::OpCodeText, true, data->data(), data->size());
    }
    send(data->data(), data->size(), false);
}

void WebSocketChannelCurl::sendBinaryAsCharVector(std::unique_ptr<Vector<char>> data)
{
    ////WTF_LOG(Network, "DocumentWebSocketChannel %p sendBinaryAsCharVector(%p, %llu)", this, data.get(), static_cast<unsigned long long>(data->size()));
    if (m_id) {
        // FIXME: Change the inspector API to show the entire message instead
        // of individual frames.
        //InspectorInstrumentation::didSendWebSocketFrame(document(), m_id, WebSocketOneFrame::OpCodeBinary, true, data->data(), data->size());
    }
    send(data->data(), data->size(), false);
}

void WebSocketChannelCurl::suspend()
{
    m_suspended = true;
}

void WebSocketChannelCurl::resume()
{
    m_suspended = false;
    if ((!m_buffer.empty() || m_closed) && m_client && !m_resumeTimer.IsActive())
        m_resumeTimer.StartOneShot(base::Seconds(0), FROM_HERE);
}

void WebSocketChannelCurl::willOpenSocketStream(SocketStreamHandle*)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p willOpenSocketStream()", this);
}

void WebSocketChannelCurl::didOpenSocketStream(SocketStreamHandle* handle)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p didOpenSocketStream()", this);
    DCHECK(handle == m_handle);
    if (!m_executionContext)
        return;
    //     if (m_id) {
    //         std::unique_ptr<network::mojom::blink::WebSocketHandshakeRequest> requeset = m_handshake->clientHandshakeRequest();
    //         if (!requeset)
    //             return;
    //         InspectorInstrumentation::willSendWebSocketHandshakeRequest(document(), m_id, requeset.get());
    //     }
    std::string handshakeMessage = m_handshake->clientHandshakeMessage();
    if (!handle->send(handshakeMessage.data(), handshakeMessage.length()))
        fail("Failed to send WebSocket handshake." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
}

void WebSocketChannelCurl::didCloseSocketStream(SocketStreamHandle* handle)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p didCloseSocketStream()", this);
    //     if (m_id && document())
    //         InspectorInstrumentation::didCloseWebSocket(document(), m_id);
    //ASSERT_UNUSED(handle, handle == m_handle || !m_handle);
    m_closed = true;
    if (m_closingTimer.IsActive())
        m_closingTimer.Stop();
    if (m_outgoingFrameQueueStatus != OutgoingFrameQueueClosed)
        abortOutgoingFrameQueue();
    if (m_handle) {
        if (common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
            m_unhandledBufferedAmount = m_handle->bufferedAmount();

        if (m_suspended)
            return;
        blink::WebSocketChannelClient* client = m_client;
        m_client = nullptr;
        m_handle = nullptr;
        m_handleId = 0;
        if (client && !m_isClosing)
            client->DidClose(m_receivedClosingHandshake ? blink::WebSocketChannelClient::kClosingHandshakeComplete
                                                        : blink::WebSocketChannelClient::kClosingHandshakeIncomplete,
                m_closeEventCode, m_closeEventReason);
    }
    deref();
}

void WebSocketChannelCurl::didReceiveSocketStreamData(SocketStreamHandle* handle, const char* data, int len)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p didReceiveSocketStreamData() Received %d bytes", this, len);
    //RefPtr<WebSocketChannelCurl> protect(*this); // The client can close the channel, potentially removing the last reference.
    DCHECK(handle == m_handle);
    if (!m_executionContext) {
        return;
    }
    if (len <= 0) {
        handle->disconnect();
        return;
    }
    if (!m_client) {
        m_shouldDiscardReceivedData = true;
        handle->disconnect();
        return;
    }
    if (m_shouldDiscardReceivedData)
        return;
    if (!appendToBuffer(data, len)) {
        m_shouldDiscardReceivedData = true;
        fail("Ran out of memory while receiving WebSocket data." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return;
    }
    while (!m_suspended && m_client && !m_buffer.empty()) {
        if (!processBuffer())
            break;
    }
}

void WebSocketChannelCurl::didUpdateBufferedAmount(SocketStreamHandle*, size_t bufferedAmount)
{
    if (m_client)
        m_client->DidConsumeBufferedAmount(bufferedAmount);
}

void WebSocketChannelCurl::didFailSocketStream(SocketStreamHandle* handle, const SocketStreamError& error)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p didFailSocketStream()", this);
    DCHECK(handle == m_handle || !m_handle);
    //     if (m_executionContext) {
    //         String message;
    //         if (error.isNull())
    //             message = "WebSocket network error";
    //         else if (error.localizedDescription().isNull())
    //             message = "WebSocket network error: error code " + String::number(error.errorCode());
    //         else
    //             message = "WebSocket network error: " + error.localizedDescription();
    //         //InspectorInstrumentation::didReceiveWebSocketFrameError(document(), m_id, message);
    //         document()->AddConsoleMessage(ConsoleMessage::create(NetworkMessageSource, ErrorMessageLevel, message));
    //         execution_context_->AddConsoleMessage(MakeGarbageCollected<ConsoleMessage>(mojom::ConsoleMessageSource::kNetwork, level, message, std::move(location)));
    //     }
    m_shouldDiscardReceivedData = true;
    handle->disconnect();
}

// void WebSocketChannelCurl::didReceiveAuthenticationChallenge(SocketStreamHandle*, const AuthenticationChallenge&)
// {
// }
//
// void WebSocketChannelCurl::didCancelAuthenticationChallenge(SocketStreamHandle*, const AuthenticationChallenge&)
// {
// }
//
// void WebSocketChannelCurl::didFinishLoadingBlob(DOMArrayBuffer* buffer)
// {
//     DCHECK(m_handle);
//     // The loaded blob is always placed on m_messages[0].
//     DCHECK(m_outgoingFrameQueue.size() > 0 && m_outgoingFrameQueue.first()->frameType == QueuedFrameTypeBlob);
//     // We replace it with the loaded blob.
//     QueuedFrame* frame = m_outgoingFrameQueue.first();
//     frame->opCode = WebSocketOneFrame::OpCodeBinary;
//     frame->isFromHook = false;
//     frame->frameType = QueuedFrameTypeVector;
//     frame->vectorData.resize(buffer->byteLength());
//     if (buffer->byteLength())
//         memcpy(frame->vectorData.data(), buffer->data(), buffer->byteLength());
//
//     processOutgoingFrameQueue();
//     m_blobLoader = nullptr;
// }
//
// void WebSocketChannelCurl::didFailLoadingBlob(FileError::ErrorCode errorCode)
// {
//     if (errorCode == FileError::kAbortErr) {
//         m_blobLoader = nullptr;
//         // The error is caused by cancel().
//         return;
//     }
//     // FIXME: Generate human-friendly reason message.
//     failAsError("Failed to load Blob: error code = " + String::number(errorCode));
//     // |this| can be deleted here.
//     m_blobLoader = nullptr;
// }

bool WebSocketChannelCurl::appendToBuffer(const char* data, size_t len)
{
    size_t newBufferSize = m_buffer.size() + len;
    if (newBufferSize < m_buffer.size()) {
        ////WTF_LOG(Network, "WebSocketChannelCurl %p appendToBuffer() Buffer overflow (%lu bytes already in receive buffer and appending %lu bytes)", this, static_cast<unsigned long>(m_buffer.size()), static_cast<unsigned long>(len));
        return false;
    }
    //m_buffer.append(data, len);
    pushBackToBuffer(&m_buffer, data, len);
    return true;
}

void WebSocketChannelCurl::skipBuffer(size_t len)
{
    //ASSERT_WITH_SECURITY_IMPLICATION(len <= m_buffer.size());
    memmove(m_buffer.data(), m_buffer.data() + len, m_buffer.size() - len);
    m_buffer.resize(m_buffer.size() - len);
}

bool WebSocketChannelCurl::processBuffer()
{
    DCHECK(!m_suspended);
    DCHECK(m_client);
    DCHECK(!m_buffer.empty());
    //WTF_LOG(Network, "WebSocketChannelCurl %p processBuffer() Receive buffer has %lu bytes", this, static_cast<unsigned long>(m_buffer.size()));

    if (m_shouldDiscardReceivedData)
        return false;

    if (m_receivedClosingHandshake) {
        skipBuffer(m_buffer.size());
        return false;
    }

    //RefPtr<WebSocketChannelCurl> protect(*this); // The client can close the channel, potentially removing the last reference.

    if (m_handshake->mode() == WebSocketHandshake::Incomplete) {
        int headerLength = m_handshake->readServerHandshake(m_buffer.data(), m_buffer.size());
        if (headerLength <= 0)
            return false;
        if (m_handshake->mode() == WebSocketHandshake::Connected) {
            bool isHooked = false;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
            if (m_hookInfo.onConnected) {
                WebViewImpl* view = (WebViewImpl*)document()->page()->chromeClient().webView();
                if (view) {
                    content::WebPageImpl* pageImpl = (content::WebPageImpl*)view->client();
                    if (pageImpl) {
                        content::WebPage* page = pageImpl->m_pagePtr;
                        isHooked = m_hookInfo.onConnected(page->wkeWebView(), m_hookInfo.param, this);
                    }
                }
            }
#endif
            if (!isHooked) {
                //                 if (m_id)
                //                     InspectorInstrumentation::didReceiveWebSocketHandshakeResponse(document(), m_id, m_handshake->clientHandshakeRequest().get(), &m_handshake->serverHandshakeResponse());
                if (!m_handshake->serverSetCookie().empty()) {
                    //                     if (cookiesEnabled(document())) {
                    //                         // Exception (for sandboxed documents) ignored.
                    //                         document()->setCookie(m_handshake->serverSetCookie(), IGNORE_EXCEPTION_FOR_TESTING);
                    //                     }
                }
                // FIXME: handle set-cookie2.
                //WTF_LOG(Network, "WebSocketChannelCurl %p Connected", this);
                skipBuffer(headerLength);
                m_client->DidConnect("", "");
                //WTF_LOG(Network, "WebSocketChannelCurl %p %lu bytes remaining in m_buffer", this, static_cast<unsigned long>(m_buffer.size()));
                return !m_buffer.empty();
            }
        }
        DCHECK(m_handshake->mode() == WebSocketHandshake::Failed);
        //WTF_LOG(Network, "WebSocketChannelCurl %p Connection failed", this);
        skipBuffer(headerLength);
        m_shouldDiscardReceivedData = true;
        fail(m_handshake->failureReason() /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }
    if (m_handshake->mode() != WebSocketHandshake::Connected)
        return false;

    return processFrame();
}

void WebSocketChannelCurl::resumeTimerFired(blink::TimerBase*)
{
    //RefPtr<WebSocketChannelCurl> protect(*this); // The client can close the channel, potentially removing the last reference.
    while (!m_suspended && m_client && !m_buffer.empty())
        if (!processBuffer())
            break;
    if (!m_suspended && m_client && m_closed && m_handle)
        didCloseSocketStream(m_handle.get());
}

void WebSocketChannelCurl::startClosingHandshake(int code, const String& reason)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p startClosingHandshake() code=%d m_receivedClosingHandshake=%d", this, m_closing, m_receivedClosingHandshake);
    DCHECK(!m_closed);
    if (m_closing)
        return;
    DCHECK(m_handle);

    std::vector<char> buf;
    if (!m_receivedClosingHandshake && code != CloseEventCodeNotSpecified) {
        unsigned char highByte = code >> 8;
        unsigned char lowByte = code;
        buf.push_back(static_cast<char>(highByte));
        buf.push_back(static_cast<char>(lowByte));
        //buf.push_back(reason.Utf8().data(), reason.Utf8().length());
        pushBackToBuffer(&buf, reason.Utf8().data(), reason.Utf8().length());
    }
    enqueueRawFrame(WebSocketOneFrame::OpCodeClose, buf.data(), buf.size(), false);
    //RefPtr<WebSocketChannelCurl> protect(*this); // An attempt to send closing handshake may fail, which will get the channel closed and dereferenced.
    processOutgoingFrameQueue();

    if (m_closed) {
        // The channel got closed because processOutgoingFrameQueue() failed.
        return;
    }

    m_closing = true;
    if (m_client)
        m_client->DidStartClosingHandshake();
}

void WebSocketChannelCurl::closingTimerFired(blink::TimerBase*)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p closingTimerFired()", this);
    if (m_handle && common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
        m_handle->disconnect();
}

void getView(std::unique_ptr<std::vector<char>> segments, Vector<base::span<const char>>* out)
{
    if (segments->empty())
        return;
    out->push_back(base::make_span(segments->data(), segments->size()));
}

bool WebSocketChannelCurl::processFrame()
{
    DCHECK(!m_buffer.empty());

    WebSocketOneFrame frame;
    const char* frameEnd;
    String errorString;
    WebSocketOneFrame::ParseFrameResult result = WebSocketOneFrame::parseFrame(m_buffer.data(), m_buffer.size(), frame, frameEnd, errorString);
    if (result == WebSocketOneFrame::FrameIncomplete)
        return false;
    if (result == WebSocketOneFrame::FrameError) {
        fail(errorString /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    DCHECK(m_buffer.data() < frameEnd);
    DCHECK(frameEnd <= m_buffer.data() + m_buffer.size());

    auto inflateResult = m_deflateFramer.inflate(frame);
    if (!inflateResult->succeeded()) {
        fail(inflateResult->failureReason() /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    // Validate the frame data.
    if (WebSocketOneFrame::isReservedOpCode(frame.m_opCode)) {
        fail("Unrecognized frame opcode: "
            + String::Number((int32_t)frame.m_opCode) /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    if (frame.m_reserved2 || frame.m_reserved3) {
        fail("One or more reserved bits are on: reserved2 = " + String::Number((int32_t)frame.m_reserved2)
            + ", reserved3 = " + String::Number((int32_t)frame.m_reserved3)
            //, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction
        );
        return false;
    }

    if (frame.m_masked) {
        fail("A server must not mask any frames that it sends to the client." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    // All control frames must not be fragmented.
    if (WebSocketOneFrame::isControlOpCode(frame.m_opCode) && !frame.m_final) {
        fail(String::Format(
            "Received fragmented control frame: opcode = %d", frame.m_opCode) /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    // All control frames must have a payload of 125 bytes or less, which means the frame must not contain
    // the "extended payload length" field.
    if (WebSocketOneFrame::isControlOpCode(frame.m_opCode) && WebSocketOneFrame::needsExtendedLengthField(frame.m_payloadLength)) {
        fail(String::Format("Received control frame having too long payload: %ud bytes", frame.m_payloadLength)
            /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    // A new data frame is received before the previous continuous frame finishes.
    // Note that control frames are allowed to come in the middle of continuous frames.
    if (m_hasContinuousFrame && frame.m_opCode != WebSocketOneFrame::OpCodeContinuation && !WebSocketOneFrame::isControlOpCode(frame.m_opCode)) {
        fail(
            "Received new data frame but previous continuous frame is unfinished." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }
    const char* payload = frame.m_payload;
    size_t payloadLength = frame.m_payloadLength;
#if 0 // (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::CString newData("", 0, true);
    if (m_hookInfo.onReceive) {
        WebViewImpl* view = (WebViewImpl*)document()->page()->chromeClient().webView();
        if (view) {
            content::WebPageImpl* pageImpl = (content::WebPageImpl*)view->client();
            if (pageImpl) {
                content::WebPage* page = pageImpl->m_pagePtr;
                if (m_hookInfo.onReceive(page->wkeWebView(), m_hookInfo.param, this, frame.opCode, frame.payload, frame.payloadLength, &newData)) {
                    return !m_buffer.empty();
                }
            }
        }
    }
    if (newData.length() > 0) {
        payload = newData.string();
        payloadLength = newData.length();
    }
#endif
    //InspectorInstrumentation::didReceiveWebSocketFrame(document(), m_id, frame.opCode, frame.masked, payload, payloadLength);

    switch (frame.m_opCode) {
    case WebSocketOneFrame::OpCodeContinuation:
        // An unexpected continuation frame is received without any leading frame.
        if (!m_hasContinuousFrame) {
            fail("Received unexpected continuation frame." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
            return false;
        }
        //m_continuousFrameData.append(payload, payloadLength);
        pushBackToBuffer(&m_continuousFrameData, payload, payloadLength);
        skipBuffer(frameEnd - m_buffer.data());
        if (frame.m_final) {
            // onmessage handler may eventually call the other methods of this channel,
            // so we should pretend that we have finished to read this frame and
            // make sure that the member variables are in a consistent state before
            // the handler is invoked.
            std::unique_ptr<std::vector<char>> continuousFrameData(new std::vector<char>());
            //continuousFrameData->appendVector(m_continuousFrameData);
            pushBackToBuffer(continuousFrameData.get(), m_continuousFrameData.data(), m_continuousFrameData.size());

            m_continuousFrameData.clear();
            m_hasContinuousFrame = false;
            if (m_continuousFrameOpCode == WebSocketOneFrame::OpCodeText) {
                String message;
                if (continuousFrameData->size())
                    message = String::FromUTF8(std::string_view(continuousFrameData->data(), continuousFrameData->size()));

                if (message.empty())
                    fail("Could not decode a text frame as UTF-8." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
                else
                    m_client->DidReceiveTextMessage(message);
            } else if (m_continuousFrameOpCode == WebSocketOneFrame::OpCodeBinary) {
                Vector<base::span<const char>> data;
                if (!continuousFrameData->empty()) {
                    data.push_back(base::make_span(continuousFrameData->data(), continuousFrameData->size()));
                    m_client->DidReceiveBinaryMessage(data);
                    continuousFrameData.reset();
                }
            }
        }
        break;

    case WebSocketOneFrame::OpCodeText:
        if (frame.m_final) {
            String message;
            if (payloadLength)
                message = String::FromUTF8(std::string_view(payload, payloadLength));
            skipBuffer(frameEnd - m_buffer.data());
            if (message.empty())
                fail("Could not decode a text frame as UTF-8." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
            else
                m_client->DidReceiveTextMessage(message);
        } else {
            m_hasContinuousFrame = true;
            m_continuousFrameOpCode = WebSocketOneFrame::OpCodeText;
            DCHECK(m_continuousFrameData.empty());
            //m_continuousFrameData.append(payload, payloadLength);
            pushBackToBuffer(&m_continuousFrameData, payload, payloadLength);
            skipBuffer(frameEnd - m_buffer.data());
        }
        break;

    case WebSocketOneFrame::OpCodeBinary:
        if (frame.m_final) {
            Vector<char> binaryData(payloadLength); // 复制一份，就怕原数据在skipBuffer里失效了
            memcpy(binaryData.data(), payload, payloadLength);

            Vector<base::span<const char>> data;
            data.push_back(base::make_span(binaryData.data(), payloadLength));

            skipBuffer(frameEnd - m_buffer.data());

            m_client->DidReceiveBinaryMessage(data);
        } else {
            m_hasContinuousFrame = true;
            m_continuousFrameOpCode = WebSocketOneFrame::OpCodeBinary;
            DCHECK(m_continuousFrameData.empty());
            //m_continuousFrameData.append(payload, payloadLength);
            pushBackToBuffer(&m_continuousFrameData, payload, payloadLength);
            skipBuffer(frameEnd - m_buffer.data());
        }
        break;

    case WebSocketOneFrame::OpCodeClose:
        if (!payloadLength)
            m_closeEventCode = CloseEventCodeNoStatusRcvd;
        else if (payloadLength == 1) {
            m_closeEventCode = CloseEventCodeAbnormalClosure;
            fail(
                "Received a broken close frame containing an invalid size body." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
            return false;
        } else {
            unsigned char highByte = static_cast<unsigned char>(payload[0]);
            unsigned char lowByte = static_cast<unsigned char>(payload[1]);
            m_closeEventCode = highByte << 8 | lowByte;
            if (m_closeEventCode == CloseEventCodeNoStatusRcvd || m_closeEventCode == CloseEventCodeAbnormalClosure
                || m_closeEventCode == CloseEventCodeTLSHandshake) {
                m_closeEventCode = CloseEventCodeAbnormalClosure;
                fail(
                    "Received a broken close frame containing a reserved status code." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
                return false;
            }
        }
        if (payloadLength >= 3)
            m_closeEventReason = String::FromUTF8(std::string_view(&payload[2], payloadLength - 2));
        else
            m_closeEventReason = "";
        skipBuffer(frameEnd - m_buffer.data());
        m_receivedClosingHandshake = true;
        startClosingHandshake(m_closeEventCode, m_closeEventReason);
        if (m_closing) {
            if (m_outgoingFrameQueueStatus == OutgoingFrameQueueOpen)
                m_outgoingFrameQueueStatus = OutgoingFrameQueueClosing;
            processOutgoingFrameQueue();
        }
        break;

    case WebSocketOneFrame::OpCodePing:
        enqueueRawFrame(WebSocketOneFrame::OpCodePong, payload, payloadLength, false);
        skipBuffer(frameEnd - m_buffer.data());
        processOutgoingFrameQueue();
        break;

    case WebSocketOneFrame::OpCodePong:
        // A server may send a pong in response to our ping, or an unsolicited pong which is not associated with
        // any specific ping. Either way, there's nothing to do on receipt of pong.
        skipBuffer(frameEnd - m_buffer.data());
        break;

    default:
        DCHECK(false);
        skipBuffer(frameEnd - m_buffer.data());
        break;
    }

    return !m_buffer.empty();
}

void WebSocketChannelCurl::enqueueTextFrame(const std::string& string, bool isFromHook, base::OnceClosure completionCallback)
{
    DCHECK(m_outgoingFrameQueueStatus == OutgoingFrameQueueOpen);
    QueuedFrame* frame = (new QueuedFrame());
    frame->opCode = WebSocketOneFrame::OpCodeText;
    frame->isFromHook = isFromHook;
    frame->frameType = QueuedFrameTypeString;
    frame->stringData = string;
    frame->completionCallback = std::move(completionCallback);
    m_outgoingFrameQueue.push_back(frame);
}

void WebSocketChannelCurl::enqueueRawFrame(WebSocketOneFrame::OpCode opCode, const char* data, size_t dataLength, bool isFromHook)
{
    DCHECK(m_outgoingFrameQueueStatus == OutgoingFrameQueueOpen);
    QueuedFrame* frame = (new QueuedFrame());
    frame->opCode = opCode;
    frame->isFromHook = isFromHook;
    frame->frameType = QueuedFrameTypeVector;
    frame->vectorData.resize(dataLength);
    if (dataLength)
        memcpy(frame->vectorData.data(), data, dataLength);
    m_outgoingFrameQueue.push_back(frame);
}

// void WebSocketChannelCurl::enqueueBlobFrame(WebSocketOneFrame::OpCode opCode, PassRefPtr<BlobDataHandle> blob)
// {
//     DCHECK(m_outgoingFrameQueueStatus == OutgoingFrameQueueOpen);
//     QueuedFrame* frame = (new QueuedFrame());
//     frame->opCode = opCode;
//     frame->isFromHook = false;
//     frame->frameType = QueuedFrameTypeBlob;
//     frame->blobData = blob;
//     m_outgoingFrameQueue.append(frame);
// }

void WebSocketChannelCurl::processOutgoingFrameQueue()
{
    if (m_outgoingFrameQueueStatus == OutgoingFrameQueueClosed)
        return;

    //RefPtr<WebSocketChannelCurl> protect(*this); // Any call to fail() will get the channel closed and dereferenced.

    while (!m_outgoingFrameQueue.empty()) {
        std::unique_ptr<QueuedFrame> frame(m_outgoingFrameQueue.TakeFirst());
        switch (frame->frameType) {
        case QueuedFrameTypeString: {
            if (!sendFrame(frame->opCode, frame->stringData.data(), frame->stringData.length(), frame->isFromHook))
                fail("Failed to send WebSocket frame." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);

            if (!frame->completionCallback.is_null())
                std::move(frame->completionCallback).Run();
            break;
        }

        case QueuedFrameTypeVector:
            if (!sendFrame(frame->opCode, frame->vectorData.data(), frame->vectorData.size(), frame->isFromHook))
                fail("Failed to send WebSocket frame." /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
            if (!frame->completionCallback.is_null())
                std::move(frame->completionCallback).Run();
            break;

        case QueuedFrameTypeBlob: {
            //             switch (m_blobLoaderStatus) {
            //             case BlobLoaderNotStarted:
            // //                 ref(); // Will be derefed after didFinishLoading() or didFail().
            // //                 DCHECK(!m_blobLoader);
            // //                 m_blobLoader = new BlobLoader(frame->blobData, this);
            // //                 m_blobLoaderStatus = BlobLoaderStarted;
            // //                 m_outgoingFrameQueue.prepend(frame.release());
            //                 DebugBreak();
            //                 return;
            //
            //             case BlobLoaderStarted:
            //             case BlobLoaderFailed:
            //                 m_outgoingFrameQueue.prepend(frame.release());
            //                 return;
            //
            //             case BlobLoaderFinished: {
            //                 DOMArrayBuffer* result = m_blobLoader->arrayBufferResult();
            //                 m_blobLoaderStatus = BlobLoaderNotStarted;
            //                 if (!sendFrame(frame->opCode, static_cast<const char*>(result->data()), result->byteLength(), frame->isFromHook))
            //                     fail("Failed to send WebSocket frame.", ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction);
            //                 m_blobLoader = nullptr;
            //                 break;
            //             }
            //             }
            DebugBreak();
            break;
        }

        default:
            CHECK(false);
            break;
        }
    }

    DCHECK(m_outgoingFrameQueue.empty());
    if (m_outgoingFrameQueueStatus == OutgoingFrameQueueClosing) {
        m_outgoingFrameQueueStatus = OutgoingFrameQueueClosed;
        if (common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
            m_handle->close();
    }
}

void WebSocketChannelCurl::abortOutgoingFrameQueue()
{
    for (Deque<QueuedFrame*>::iterator it = m_outgoingFrameQueue.begin(); it != m_outgoingFrameQueue.end(); ++it) {
        QueuedFrame* ptr = *it;
        delete ptr;
    }
    m_outgoingFrameQueue.clear();
    m_outgoingFrameQueueStatus = OutgoingFrameQueueClosed;
    //     if (m_blobLoaderStatus == BlobLoaderStarted) {
    //         if (m_blobLoader)
    //             m_blobLoader->cancel();
    //         didFail(FileError::kAbortErr);
    //     }
}

void WebSocketChannelCurl::didFail(/*FileError::ErrorCode*/ int32_t errorCode)
{
    //WTF_LOG(Network, "WebSocketChannel %p didFail() errorCode=%d", this, errorCode);
    //     DCHECK(m_blobLoader);
    //     DCHECK(m_blobLoaderStatus == BlobLoaderStarted);
    //     m_blobLoader = nullptr;
    //     m_blobLoaderStatus = BlobLoaderFailed;

    // FIXME: Generate human-friendly reason message.
    fail(String::Format("Failed to load Blob: error code = %d", errorCode) /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);

    deref();
}

bool WebSocketChannelCurl::sendFrame(WebSocketOneFrame::OpCode opCode, const char* data, size_t dataLength, bool isFromHook)
{
    DCHECK(m_handle);
    DCHECK(!m_suspended);
#if 0 // (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    wke::CString newData("", 0, true);
    if (!isFromHook && m_hookInfo.onSend) {
        WebViewImpl* view = (WebViewImpl*)document()->page()->chromeClient().webView();
        if (view) {
            content::WebPageImpl* pageImpl = (content::WebPageImpl*)view->client();
            if (pageImpl) {
                content::WebPage* page = pageImpl->m_pagePtr;
                if (m_hookInfo.onSend(page->wkeWebView(), m_hookInfo.param, this, opCode, data, dataLength, &newData)) {
                    return true;
                }
            }
        }
    }
    if (newData.length() > 0) {
        data = newData.string();
        dataLength = newData.length();
    }
#endif
    WebSocketOneFrame frame(opCode, true, false, true, data, dataLength);
    //InspectorInstrumentation::didSendWebSocketFrame(document(), m_id, frame.opCode, frame.masked, frame.payload, frame.payloadLength);

    auto deflateResult = m_deflateFramer.deflate(frame);
    if (!deflateResult->succeeded()) {
        fail(deflateResult->failureReason() /*, ErrorMessageLevel, m_sourceURLAtConstruction, m_lineNumberAtConstruction*/);
        return false;
    }

    Vector<char> frameData;
    frame.makeFrameData(frameData);

    if (common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
        return m_handle->send(frameData.data(), frameData.size());
    return false;
}

blink::Document* WebSocketChannelCurl::document()
{
    DebugBreak();
    return nullptr;
}

//-----
bool WebSocketChannelCurl::Connect(const blink::KURL& url, const String& protocol)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p connect()", this);
    DCHECK(!m_handle);
    DCHECK(!m_suspended);
    blink::KURL kurl = url;
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    WebViewImpl* view = (WebViewImpl*)document()->page()->chromeClient().webView();
    if (view) {
        content::WebPageImpl* pageImpl = (content::WebPageImpl*)view->client();
        if (pageImpl) {
            content::WebPage* page = pageImpl->m_pagePtr;
            if (page && page->wkeHandler().wsCallback) {
                wke::CString urlString(url.string());
                wkeWebSocketWillConnectCallback callback = (wkeWebSocketWillConnectCallback)page->wkeHandler().wsCallback;
                void* param = page->wkeHandler().wsCallbackParam;
                if (callback(page->wkeWebView(), param, this, &urlString)) {
                    kurl = KURL(blink::ParsedURLString, urlString.string());
                }
            }
        }
    }
#endif
    m_handshake.reset(new WebSocketHandshake(kurl, protocol, /*document()*/ m_executionContext.Get()));
    m_handshake->reset();
    if (m_deflateFramer.canDeflate())
        m_handshake->addExtensionProcessor(m_deflateFramer.createExtensionProcessor());
    //     if (m_id)
    //         InspectorInstrumentation::didCreateWebSocket(document(), m_id, kurl, protocol);

    // if (Frame* frame = document()->frame()) // 似乎这个判断没啥用
    {
        ref();
        m_handle = SocketStreamHandle::create(m_handshake->url(), this);
        m_handleId = m_handle->getId();
    }
    //     if (!document()->frame())
    //         OutputDebugStringA("WebSocketChannelCurl::connect, document()->frame() is empty\n");
    return true;
}

blink::WebSocketChannel::SendResult WebSocketChannelCurl::Send(const std::string& message, base::OnceClosure completionCallback)
{
    send(message, false, std::move(completionCallback));
    return blink::WebSocketChannel::SendResult::kCallbackWillBeCalled;
}

blink::WebSocketChannel::SendResult WebSocketChannelCurl::Send(
    const blink::DOMArrayBuffer& buf, size_t byteOffset, size_t byteLength, base::OnceClosure completionCallback)
{
    size_t allByteLen = buf.ByteLength();
    if (byteOffset >= allByteLen)
        return blink::WebSocketChannel::SendResult::kSentSynchronously;

    size_t realByteLength = byteLength;
    if (byteOffset + byteLength > allByteLen) {
        realByteLength = allByteLen - byteOffset;
    }
    if (0 == realByteLength)
        return blink::WebSocketChannel::SendResult::kSentSynchronously;

    send(((const char*)buf.Data()) + byteOffset, realByteLength, false);
    return blink::WebSocketChannel::SendResult::kSentSynchronously;
}

void WebSocketChannelCurl::Send(scoped_refptr<blink::BlobDataHandle>)
{
    DebugBreak();
}

void WebSocketChannelCurl::Close(int code, const String& reason)
{
    //WTF_LOG(Network, "WebSocketChannelCurl %p close() code=%d reason='%s'", this, code, reason.utf8().data());
    DCHECK(!m_suspended);
    if (!m_handle)
        return;
    m_isClosing = true;
    //RefPtr<WebSocketChannelCurl> protect(*this); // An attempt to send closing handshake may fail, which will get the channel closed and dereferenced.
    startClosingHandshake(code, reason);

    // 原版不知道为啥那么长，这里为了防止断网后在js里用WebSocket.close关不掉这个连接，把超时时间改小一点
    if (m_closing && !m_closingTimer.IsActive())
        m_closingTimer.StartOneShot(/*2 * TCPMaximumSegmentLifetime*/ base::Minutes(1), FROM_HERE);
    m_isClosing = false;
}

void WebSocketChannelCurl::Fail(const String& reason, blink::mojom::ConsoleMessageLevel, std::unique_ptr<blink::SourceLocation>)
{
    fail(reason /*, MessageLevel, std::unique_ptr<blink::SourceLocation>*/);
}

void WebSocketChannelCurl::Disconnect()
{
    if (m_handshake)
        m_handshake->clearScriptExecutionContext();
    m_client = nullptr;
    if (m_handle && common::LiveIdDetect::get()->getPtr((intptr_t)m_handleId))
        m_handle->disconnect();
}

void WebSocketChannelCurl::CancelHandshake()
{
    DebugBreak();
}

void WebSocketChannelCurl::ApplyBackpressure()
{
    DebugBreak();
}

void WebSocketChannelCurl::RemoveBackpressure()
{
    DebugBreak();
}

void WebSocketChannelCurl::didReceiveAuthenticationChallenge(SocketStreamHandle*, const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

void WebSocketChannelCurl::didCancelAuthenticationChallenge(SocketStreamHandle*, const blink::AuthenticationChallenge&)
{
    DebugBreak();
}

void WebSocketChannelCurl::ref()
{
    m_ref++;
}

void WebSocketChannelCurl::deref()
{
    m_ref--;
}

// DEFINE_TRACE(WebSocketChannelCurl)
// {
//     visitor->trace(m_blobLoader);
//     visitor->trace(m_client);
//     WebSocketChannel::trace(visitor);
//     ContextLifecycleObserver::trace(visitor);
// }

void WebSocketChannelCurl::Trace(blink::Visitor* visitor) const
{
    visitor->Trace(m_client);
    blink::WebSocketChannel::Trace(visitor);
}

} // namespace net
