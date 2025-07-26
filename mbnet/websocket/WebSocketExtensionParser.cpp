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

#include "mbnet/websocket/WebSocketExtensionParser.h"

#include "third_party/blink/renderer/platform/wtf/text/ascii_ctype.h"

namespace mbnet {

bool WebSocketExtensionParser::finished()
{
    return m_current >= m_end;
}

bool WebSocketExtensionParser::parsedSuccessfully()
{
    return m_current == m_end;
}

static bool isSeparator(char character)
{
    static const char* separatorCharacters = "()<>@,;:\\\"/[]?={} \t";
    const char* p = strchr(separatorCharacters, character);
    return p && *p;
}

void WebSocketExtensionParser::skipSpaces()
{
    while (m_current < m_end && (*m_current == ' ' || *m_current == '\t'))
        ++m_current;
}

bool WebSocketExtensionParser::consumeToken()
{
    skipSpaces();
    const char* start = m_current;
    while (m_current < m_end && IsASCIIPrintable(*m_current) && !isSeparator(*m_current))
        ++m_current;
    if (start < m_current) {
        m_currentToken = String(base::span<const char>(start, (size_t)(m_current - start)));
        return true;
    }
    return false;
}

bool WebSocketExtensionParser::consumeQuotedString()
{
    skipSpaces();
    if (m_current >= m_end || *m_current != '"')
        return false;

    Vector<char> buffer;
    ++m_current;
    while (m_current < m_end && *m_current != '"') {
        if (*m_current == '\\' && ++m_current >= m_end)
            return false;
        buffer.push_back(*m_current);
        ++m_current;
    }
    if (m_current >= m_end || *m_current != '"')
        return false;
    m_currentToken = String::FromUTF8(std::string_view(buffer.data(), buffer.size()));
    if (m_currentToken.empty())
        return false;
    ++m_current;
    return true;
}

bool WebSocketExtensionParser::consumeQuotedStringOrToken()
{
    // This is ok because consumeQuotedString() doesn't update m_current or
    // makes it same as m_end on failure.
    return consumeQuotedString() || consumeToken();
}

bool WebSocketExtensionParser::consumeCharacter(char character)
{
    skipSpaces();
    if (m_current < m_end && *m_current == character) {
        ++m_current;
        return true;
    }
    return false;
}

bool WebSocketExtensionParser::parseExtension(String& extensionToken, HashMap<String, String>& extensionParameters)
{
    // Parse extension-token.
    if (!consumeToken())
        return false;

    extensionToken = currentToken();

    // Parse extension-parameters if exists.
    while (consumeCharacter(';')) {
        if (!consumeToken())
            return false;

        String parameterToken = currentToken();
        if (consumeCharacter('=')) {
            if (consumeQuotedStringOrToken())
                extensionParameters.insert(parameterToken, currentToken());
            else
                return false;
        } else
            extensionParameters.insert(parameterToken, String());
    }
    if (!finished() && !consumeCharacter(','))
        return false;

    return true;
}

} // namespace net
