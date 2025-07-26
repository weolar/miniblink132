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

#include "mbnet/websocket/WebSocketExtensionDispatcher.h"

#include "mbnet/websocket/WebSocketExtensionParser.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hash.h"

namespace mbnet {

void WebSocketExtensionDispatcher::reset()
{
    m_processors.clear();
}

void WebSocketExtensionDispatcher::addProcessor(std::unique_ptr<WebSocketExtensionProcessor> processor)
{
    for (auto& extensionProcessor : m_processors) {
        if (extensionProcessor->extensionToken() == processor->extensionToken())
            return;
    }
    DCHECK(processor->handshakeString().length());
    DCHECK(!processor->handshakeString().Contains('\n'));
    DCHECK(!processor->handshakeString().Contains(static_cast<UChar>('\0')));
    m_processors.push_back(std::move(processor));
}

const String WebSocketExtensionDispatcher::createHeaderValue() const
{
    size_t numProcessors = m_processors.size();
    if (!numProcessors)
        return String();

    StringBuilder builder;
    builder.Append(m_processors[0]->handshakeString());
    for (size_t i = 1; i < numProcessors; ++i) {
        builder.Append(", ");
        builder.Append(m_processors[i]->handshakeString());
    }
    return builder.ToString();
}

void WebSocketExtensionDispatcher::appendAcceptedExtension(const String& extensionToken, HashMap<String, String>& extensionParameters)
{
    if (!m_acceptedExtensionsBuilder.empty())
        m_acceptedExtensionsBuilder.Append(", ");
    m_acceptedExtensionsBuilder.Append(extensionToken);
    // FIXME: Should use ListHashSet to keep the order of the parameters.
    for (auto& parameter : extensionParameters) {
        m_acceptedExtensionsBuilder.Append("; ");
        m_acceptedExtensionsBuilder.Append(parameter.key);
        if (!parameter.value.empty()) {
            m_acceptedExtensionsBuilder.Append('=');
            m_acceptedExtensionsBuilder.Append(parameter.value);
        }
    }
}

void WebSocketExtensionDispatcher::fail(const String& reason)
{
    m_failureReason = reason;
    m_acceptedExtensionsBuilder.Clear();
}

bool WebSocketExtensionDispatcher::processHeaderValue(const String& headerValue)
{
    if (!headerValue.length())
        return true;

    // If we don't send Sec-WebSocket-Extensions header, the server should not return the header.
    if (!m_processors.size()) {
        fail("Received unexpected Sec-WebSocket-Extensions header");
        return false;
    }

    const std::string headerValueData = headerValue.Utf8();
    WebSocketExtensionParser parser(headerValueData.data(), headerValueData.data() + headerValueData.length());
    while (!parser.finished()) {
        String extensionToken;
        HashMap<String, String> extensionParameters;
        if (!parser.parseExtension(extensionToken, extensionParameters)) {
            fail("Sec-WebSocket-Extensions header is invalid");
            return false;
        }

        size_t index = 0;
        for (auto& processor : m_processors) {
            if (extensionToken == processor->extensionToken()) {
                if (processor->processResponse(extensionParameters)) {
                    appendAcceptedExtension(extensionToken, extensionParameters);
                    break;
                }
                fail(processor->failureReason());
                return false;
            }
            ++index;
        }
        // There is no extension which can process the response.
        if (index == m_processors.size()) {
            fail("Received unexpected extension: " + extensionToken);
            return false;
        }
    }
    return parser.parsedSuccessfully();
}

String WebSocketExtensionDispatcher::acceptedExtensions() const
{
    if (m_acceptedExtensionsBuilder.empty())
        return String();

    StringBuilder builder;
    builder.Append(m_acceptedExtensionsBuilder);
    return builder.ToString();
}

String WebSocketExtensionDispatcher::failureReason() const
{
    return m_failureReason;
}

} // namespace net
