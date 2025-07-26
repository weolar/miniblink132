/*
 * Copyright (C) 2012 Google Inc.  All rights reserved.
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

#define WTF_USE_ZLIB

#include "mbnet/websocket/WebSocketDeflateFramer.h"

#include "mbnet/websocket/WebSocketExtensionProcessor.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hash.h"

namespace mbnet {

class WebSocketExtensionDeflateFrame : public WebSocketExtensionProcessor {
    USING_FAST_MALLOC(WebSocketExtensionDeflateFrame);

public:
    explicit WebSocketExtensionDeflateFrame(WebSocketDeflateFramer*);
    virtual ~WebSocketExtensionDeflateFrame()
    {
    }

    virtual String handshakeString() override;
    virtual bool processResponse(const HashMap<String, String>&) override;
    virtual String failureReason() override
    {
        return m_failureReason;
    }

private:
    WebSocketDeflateFramer* m_framer;
    bool m_responseProcessed;
    String m_failureReason;
};

// FXIME: Remove vendor prefix after the specification matured.
WebSocketExtensionDeflateFrame::WebSocketExtensionDeflateFrame(WebSocketDeflateFramer* framer)
    : WebSocketExtensionProcessor("x-webkit-deflate-frame")
    , m_framer(framer)
    , m_responseProcessed(false)
{
    DCHECK(m_framer);
}

String WebSocketExtensionDeflateFrame::handshakeString()
{
    return extensionToken(); // No parameter
}

bool WebSocketExtensionDeflateFrame::processResponse(const HashMap<String, String>& serverParameters)
{
#if 1 // USE(ZLIB)
    if (m_responseProcessed) {
        m_failureReason = "Received duplicate deflate-frame response";
        return false;
    }
    m_responseProcessed = true;

    unsigned expectedNumParameters = 0;
    int windowBits = 15;
    WTF::HashMap<String, String>::const_iterator parameter = serverParameters.find("max_window_bits");
    if (parameter != serverParameters.end()) {
        windowBits = parameter->value.ToInt();
        if (windowBits < 8 || windowBits > 15) {
            m_failureReason = "Received invalid max_window_bits parameter";
            return false;
        }
        expectedNumParameters++;
    }

    WebSocketDeflater::ContextTakeOverMode mode = WebSocketDeflater::TakeOverContext;
    parameter = serverParameters.find("no_context_takeover");
    if (parameter != serverParameters.end()) {
        if (!parameter->value.empty()) {
            m_failureReason = "Received invalid no_context_takeover parameter";
            return false;
        }
        mode = WebSocketDeflater::DoNotTakeOverContext;
        expectedNumParameters++;
    }

    if (expectedNumParameters != serverParameters.size()) {
        m_failureReason = "Received unexpected deflate-frame parameter";
        return false;
    }

    m_framer->enableDeflate(windowBits, mode);
    return true;
#else
    ASSERT_NOT_REACHED();
    return false;
#endif
}

DeflateResultHolder::DeflateResultHolder(WebSocketDeflateFramer* framer)
    : m_framer(framer)
    , m_succeeded(true)
{
    DCHECK(m_framer);
}

DeflateResultHolder::~DeflateResultHolder()
{
    m_framer->resetDeflateContext();
}

void DeflateResultHolder::fail(const String& failureReason)
{
    m_succeeded = false;
    m_failureReason = failureReason;
}

InflateResultHolder::InflateResultHolder(WebSocketDeflateFramer* framer)
    : m_framer(framer)
    , m_succeeded(true)
{
    DCHECK(m_framer);
}

InflateResultHolder::~InflateResultHolder()
{
    m_framer->resetInflateContext();
}

void InflateResultHolder::fail(const String& failureReason)
{
    m_succeeded = false;
    m_failureReason = failureReason;
}

WebSocketDeflateFramer::WebSocketDeflateFramer()
    : m_enabled(false)
{
}

std::unique_ptr<WebSocketExtensionProcessor> WebSocketDeflateFramer::createExtensionProcessor()
{
    return std::make_unique<WebSocketExtensionDeflateFrame>(this);
}

bool WebSocketDeflateFramer::canDeflate() const
{
#if 1 // USE(ZLIB)
    return true;
#else
    return false;
#endif
}

#if 1 // USE(ZLIB)
void WebSocketDeflateFramer::enableDeflate(int windowBits, WebSocketDeflater::ContextTakeOverMode mode)
{
    m_deflater.reset(new WebSocketDeflater(windowBits, mode));
    m_inflater.reset(new WebSocketInflater());
    if (!m_deflater->initialize() || !m_inflater->initialize()) {
        m_deflater = nullptr;
        m_inflater = nullptr;
        return;
    }
    m_enabled = true;
}
#endif

std::unique_ptr<DeflateResultHolder> WebSocketDeflateFramer::deflate(WebSocketOneFrame& frame)
{
#if 1 // USE(ZLIB)
    std::unique_ptr<DeflateResultHolder> result(new DeflateResultHolder(this));
    if (!enabled() || !WebSocketOneFrame::isNonControlOpCode(frame.m_opCode) || !frame.m_payloadLength)
        return result;
    if (!m_deflater->addBytes(frame.m_payload, frame.m_payloadLength) || !m_deflater->finish()) {
        result->fail("Failed to compress frame");
        return result;
    }
    frame.m_compress = true;
    frame.m_payload = m_deflater->data();
    frame.m_payloadLength = m_deflater->size();
    return result;
#else
    return std::make_unique<DeflateResultHolder>(this);
#endif
}

void WebSocketDeflateFramer::resetDeflateContext()
{
#if 1 // USE(ZLIB)
    if (m_deflater)
        m_deflater->reset();
#endif
}

std::unique_ptr<InflateResultHolder> WebSocketDeflateFramer::inflate(WebSocketOneFrame& frame)
{
    std::unique_ptr<InflateResultHolder> result(new InflateResultHolder(this));
    if (!enabled() && frame.m_compress) {
        result->fail("Compressed bit must be 0 if no negotiated deflate-frame extension");
        return result;
    }
#if 1 // USE(ZLIB)
    if (!frame.m_compress)
        return result;
    if (!WebSocketOneFrame::isNonControlOpCode(frame.m_opCode)) {
        result->fail("Received unexpected compressed frame");
        return result;
    }
    if (!m_inflater->addBytes(frame.m_payload, frame.m_payloadLength) || !m_inflater->finish()) {
        result->fail("Failed to decompress frame");
        return result;
    }
    frame.m_compress = false;
    frame.m_payload = m_inflater->data();
    frame.m_payloadLength = m_inflater->size();
    return result;
#else
    return result;
#endif
}

void WebSocketDeflateFramer::resetInflateContext()
{
#if 1 // USE(ZLIB)
    if (m_inflater)
        m_inflater->reset();
#endif
}

void WebSocketDeflateFramer::didFail()
{
    resetDeflateContext();
    resetInflateContext();
}

} // namespace net
