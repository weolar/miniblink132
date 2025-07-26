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

#ifndef mbnet_WebSocketChannelCurl_h
#define mbnet_WebSocketChannelCurl_h

#include "mbnet/websocket/SocketStreamHandleClient.h"
#include "mbnet/websocket/WebSocketDeflateFramer.h"
#include "mbnet/websocket/WebSocketOneFrame.h"
#include "mbnet/websocket/WebSocketHandshake.h"
#include "third_party/blink/renderer/modules/websockets/websocket_channel.h"
#include "third_party/blink/renderer/platform/heap/prefinalizer.h"
#include "third_party/blink/renderer/platform/timer.h"
#include "third_party/blink/renderer/platform/wtf/deque.h"

#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
#include "wke/wkeWebView.h"
#include "wke/wkeString.h"
#endif

namespace blink {
class KURL;
class Document;
class FileReaderLoader;
class SocketStreamError;
class WebSocketChannelClient;
class ExecutionContext;
}

namespace mbnet {

class WebSocketChannelCurl : public blink::WebSocketChannel,
                             public SocketStreamHandleClient
//, public blink::ContextLifecycleObserver
{
    //USING_GARBAGE_COLLECTED_MIXIN(WebSocketChannelCurl);
    USING_PRE_FINALIZER(WebSocketChannelCurl, dispose);

public:
    static WebSocketChannelCurl* create(
        blink::ExecutionContext* context, blink::WebSocketChannelClient* client, std::unique_ptr<blink::SourceLocation> location);
    virtual ~WebSocketChannelCurl();

    WebSocketChannelCurl(blink::ExecutionContext* context, blink::WebSocketChannelClient* client, std::unique_ptr<blink::SourceLocation> location);

    void dispose();

    bool send(const char* data, int length, bool hook);

    // old WebSocketChannel functions.
    void send(const std::string&, bool isHook, base::OnceClosure completionCallback);
    //     /*virtual*/ void send(PassRefPtr<blink::BlobDataHandle>) /*override*/;
    //     /*virtual*/ void send(const blink::DOMArrayBuffer&, unsigned byteOffset, unsigned byteLength) /*override*/;
    /*virtual*/ unsigned long bufferedAmount() const /*override*/;
    /*virtual*/ void fail(const String& reason /*, blink::MessageLevel, std::unique_ptr<blink::SourceLocation>*/) /*override*/;
    /*virtual*/ void sendTextAsCharVector(std::unique_ptr<Vector<char>> data) /*override*/;
    /*virtual*/ void sendBinaryAsCharVector(std::unique_ptr<Vector<char>> data) /*override*/;

    //     void fail(const String& reason, blink::MessageLevel level, const String& sourceURL, unsigned lineNumber)
    //     {
    //         fail(reason, level, blink::SourceLocation::capture(sourceURL, lineNumber, 0));
    //     }
    //
    //     void failAsError(const String& reason)
    //     {
    //         fail(reason, blink::ErrorMessageLevel, blink::SourceLocation::capture(m_sourceURLAtConstruction, m_lineNumberAtConstruction, 0));
    //     }

    /*virtual*/ void suspend() /*override*/;
    /*virtual*/ void resume() /*override*/;

    // blink::WebSocketChannel functions.
    bool Connect(const blink::KURL&, const String& protocol) override;
    SendResult Send(const std::string& message, base::OnceClosure completionCallback) override;
    SendResult Send(const blink::DOMArrayBuffer&, size_t byteOffset, size_t byteLength, base::OnceClosure completionCallback) override;
    void Send(scoped_refptr<blink::BlobDataHandle>) override;
    // Start closing handshake. Use the CloseEventCodeNotSpecified for the code
    // argument to omit payload.
    void Close(int code, const String& reason) override; // Start closing handshake.
    void Fail(const String& reason, blink::mojom::ConsoleMessageLevel, std::unique_ptr<blink::SourceLocation>) override;
    void Disconnect() override;
    void CancelHandshake() override;
    void ApplyBackpressure() override;
    void RemoveBackpressure() override;

    // SocketStreamHandleClient functions.
    virtual void willOpenSocketStream(SocketStreamHandle*) override;
    virtual void didOpenSocketStream(SocketStreamHandle*) override;
    virtual void didCloseSocketStream(SocketStreamHandle*) override;
    virtual void didReceiveSocketStreamData(SocketStreamHandle*, const char*, int) override;
    virtual void didUpdateBufferedAmount(SocketStreamHandle*, size_t bufferedAmount) override;
    virtual void didFailSocketStream(SocketStreamHandle*, const SocketStreamError&) override;
    virtual void didReceiveAuthenticationChallenge(SocketStreamHandle*, const blink::AuthenticationChallenge&) override;
    virtual void didCancelAuthenticationChallenge(SocketStreamHandle*, const blink::AuthenticationChallenge&) override;
    virtual int64_t getId() const override
    {
        return m_id;
    }

    enum CloseEventCode {
        CloseEventCodeNotSpecified = -1,
        CloseEventCodeNormalClosure = 1000,
        CloseEventCodeGoingAway = 1001,
        CloseEventCodeProtocolError = 1002,
        CloseEventCodeUnsupportedData = 1003,
        CloseEventCodeFrameTooLarge = 1004,
        CloseEventCodeNoStatusRcvd = 1005,
        CloseEventCodeAbnormalClosure = 1006,
        CloseEventCodeInvalidFramePayloadData = 1007,
        CloseEventCodePolicyViolation = 1008,
        CloseEventCodeMessageTooBig = 1009,
        CloseEventCodeMandatoryExt = 1010,
        CloseEventCodeInternalError = 1011,
        CloseEventCodeTLSHandshake = 1015,
        CloseEventCodeMinimumUserDefined = 3000,
        CloseEventCodeMaximumUserDefined = 4999
    };

    void didFail(/*blink::FileError::ErrorCode*/ int32_t errorCode);

    //DECLARE_VIRTUAL_TRACE();
    void Trace(blink::Visitor* visitor) const;

    void ref();
    void deref();
#if (defined ENABLE_WKE) && (ENABLE_WKE == 1)
    //     //hook
    //     bool(WKE_CALL_TYPE* m_onConnected)(wkeWebView webView, void* param, WebSocketChannelCurl* job);
    //     bool(WKE_CALL_TYPE* m_onReceive)(wkeWebView webView, void* param, WebSocketChannelCurl* job, int OpCode, const char* buf, size_t len, wkeString new_data);
    //     bool(WKE_CALL_TYPE* m_onSend)(wkeWebView webView, void* param, WebSocketChannelCurl* job, int OpCode, const char* buf, size_t len, wkeString new_data);
    //     void(WKE_CALL_TYPE* m_onError)(wkeWebView webView, void* param, WebSocketChannelCurl* job);
    //     void* m_hookUserParam;
    struct WebsocketHookInfo {
        WebsocketHookInfo()
        {
            param = nullptr;
            onConnected = nullptr;
            onReceive = nullptr;
            onSend = nullptr;
            onError = nullptr;
        }
        void* param;
        bool(WKE_CALL_TYPE* onConnected)(wkeWebView webView, void* param, WebSocketChannelCurl* channel);
        bool(WKE_CALL_TYPE* onReceive)(
            wkeWebView webView, void* param, WebSocketChannelCurl* channel, int opCode, const char* buf, size_t len, wkeString newData);
        bool(WKE_CALL_TYPE* onSend)(wkeWebView webView, void* param, WebSocketChannelCurl* channel, int opCode, const char* buf, size_t len, wkeString newData);
        void(WKE_CALL_TYPE* onError)(wkeWebView webView, void* param, WebSocketChannelCurl* channel);
    };

private:
    WebsocketHookInfo m_hookInfo;

public:
    void setHookInfo(const WebsocketHookInfo& info)
    {
        m_hookInfo = info;
    }
#endif

private:
    bool appendToBuffer(const char* data, size_t len);
    void skipBuffer(size_t len);
    bool processBuffer();
    void resumeTimerFired(blink::TimerBase*);
    void startClosingHandshake(int code, const String& reason);
    void closingTimerFired(blink::TimerBase*);

    bool processFrame();

    // It is allowed to send a Blob as a binary frame if hybi-10 protocol is in use. Sending a Blob
    // can be delayed because it must be read asynchronously. Other types of data (String or
    // ArrayBuffer) may also be blocked by preceding sending request of a Blob.
    //
    // To address this situation, messages to be sent need to be stored in a queue. Whenever a new
    // data frame is going to be sent, it first must go to the queue. Items in the queue are processed
    // in the order they were put into the queue. Sending request of a Blob blocks further processing
    // until the Blob is completely read and sent to the socket stream.
    enum QueuedFrameType { QueuedFrameTypeString, QueuedFrameTypeVector, QueuedFrameTypeBlob };
    struct QueuedFrame {
        WebSocketOneFrame::OpCode opCode;
        QueuedFrameType frameType;
        // Only one of the following items is used, according to the value of frameType.
        std::string stringData;
        Vector<char> vectorData;
        //scoped_refptr<blink::BlobDataHandle> blobData;
        base::OnceClosure completionCallback;
        bool isFromHook;
    };
    void enqueueTextFrame(const std::string&, bool isFromHook, base::OnceClosure completionCallback);
    void enqueueRawFrame(WebSocketOneFrame::OpCode, const char* data, size_t dataLength, bool isFromHook);
    //void enqueueBlobFrame(WebSocketOneFrame::OpCode, PassRefPtr<blink::BlobDataHandle>);

    void processOutgoingFrameQueue();
    void abortOutgoingFrameQueue();

    enum OutgoingFrameQueueStatus {
        // It is allowed to put a new item into the queue.
        OutgoingFrameQueueOpen,
        // Close frame has already been put into the queue but may not have been sent yet;
        // m_handle->close() will be called as soon as the queue is cleared. It is not
        // allowed to put a new item into the queue.
        OutgoingFrameQueueClosing,
        // Close frame has been sent or the queue was aborted. It is not allowed to put
        // a new item to the queue.
        OutgoingFrameQueueClosed
    };

    // If you are going to send a hybi-10 frame, you need to use the outgoing frame queue
    // instead of call sendFrame() directly.
    bool sendFrame(WebSocketOneFrame::OpCode, const char* data, size_t dataLength, bool isFromHook);

    enum BlobLoaderStatus { BlobLoaderNotStarted, BlobLoaderStarted, BlobLoaderFinished, BlobLoaderFailed };

    blink::Document* document();

    // Methods for BlobLoader.
    class BlobLoader;
    //     void didFinishLoadingBlob(blink::DOMArrayBuffer*);
    //     void didFailLoadingBlob(blink::FileError::ErrorCode);
    int m_ref;

    blink::Member<blink::WebSocketChannelClient> m_client;
    std::unique_ptr<WebSocketHandshake> m_handshake;
    scoped_refptr<SocketStreamHandle> m_handle;
    int64_t m_handleId;

    std::vector<char> m_buffer;

    blink::HeapTaskRunnerTimer<WebSocketChannelCurl> m_resumeTimer;
    bool m_suspended;
    bool m_closing;
    bool m_receivedClosingHandshake;
    blink::HeapTaskRunnerTimer<WebSocketChannelCurl> m_closingTimer;
    bool m_closed;
    bool m_shouldDiscardReceivedData;
    unsigned long m_unhandledBufferedAmount;

    int64_t m_id; // m_identifier == 0 means that we could not obtain a valid identifier.

    // Private members only for hybi-10 protocol.
    bool m_hasContinuousFrame;
    WebSocketOneFrame::OpCode m_continuousFrameOpCode;
    std::vector<char> m_continuousFrameData;
    unsigned short m_closeEventCode;
    String m_closeEventReason;

    WTF::Deque<QueuedFrame*> m_outgoingFrameQueue;
    OutgoingFrameQueueStatus m_outgoingFrameQueueStatus;

    const blink::Member<blink::ExecutionContext> m_executionContext;

    // FIXME: Load two or more Blobs simultaneously for better performance.
    //     blink::Member<BlobLoader> m_blobLoader;
    //     BlobLoaderStatus m_blobLoaderStatus;

    WebSocketDeflateFramer m_deflateFramer;

    String m_sourceURLAtConstruction;
    unsigned m_lineNumberAtConstruction;

    bool m_isClosing;
};

} // namespace net

#endif // WebSocketChannelImpl_h
