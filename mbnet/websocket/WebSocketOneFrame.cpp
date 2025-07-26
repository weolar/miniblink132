/*
 * Copyright (C) 2011 Google Inc.  All rights reserved.
 * Copyright (C) Research In Motion Limited 2011. All rights reserved.
 * Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this program; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "mbnet/websocket/WebSocketOneFrame.h"

#include "net/websockets/websocket_frame.h"
#include "base/rand_util.h"

namespace mbnet {

// Constants for hybi-10 frame format.
const unsigned char kFinalBit = 0x80;
const unsigned char kCompressBit = 0x40;
const unsigned char kReserved2Bit = 0x20;
const unsigned char kReserved3Bit = 0x10;
const unsigned char kOpCodeMask = 0xF;
const unsigned char kMaskBit = 0x80;
const unsigned char kPayloadLengthMask = 0x7F;
const size_t kMaxPayloadLengthWithoutExtendedLengthField = 125;
const size_t kPayloadLengthWithTwoByteExtendedLengthField = 126;
const size_t kPayloadLengthWithEightByteExtendedLengthField = 127;
const size_t kMaskingKeyWidthInBytes = 4;

bool WebSocketOneFrame::needsExtendedLengthField(size_t payloadLength)
{
    return payloadLength > kMaxPayloadLengthWithoutExtendedLengthField;
}

WebSocketOneFrame::ParseFrameResult WebSocketOneFrame::parseFrame(
    char* data, size_t dataLength, WebSocketOneFrame& frame, const char*& frameEnd, String& errorString)
{
    char* p = data;
    const char* bufferEnd = data + dataLength;

    if (dataLength < 2)
        return FrameIncomplete;

    unsigned char firstByte = *p++;
    unsigned char secondByte = *p++;

    bool final = firstByte & kFinalBit;
    bool compress = firstByte & kCompressBit;
    bool reserved2 = firstByte & kReserved2Bit;
    bool reserved3 = firstByte & kReserved3Bit;
    unsigned char opCode = firstByte & kOpCodeMask;

    bool masked = secondByte & kMaskBit;
    uint64_t payloadLength64 = secondByte & kPayloadLengthMask;
    if (payloadLength64 > kMaxPayloadLengthWithoutExtendedLengthField) {
        int extendedPayloadLengthSize;
        if (payloadLength64 == kPayloadLengthWithTwoByteExtendedLengthField)
            extendedPayloadLengthSize = 2;
        else {
            DCHECK(payloadLength64 == kPayloadLengthWithEightByteExtendedLengthField);
            extendedPayloadLengthSize = 8;
        }
        if (bufferEnd - p < extendedPayloadLengthSize)
            return FrameIncomplete;
        payloadLength64 = 0;
        for (int i = 0; i < extendedPayloadLengthSize; ++i) {
            payloadLength64 <<= 8;
            payloadLength64 |= static_cast<unsigned char>(*p++);
        }
        if (extendedPayloadLengthSize == 2 && payloadLength64 <= kMaxPayloadLengthWithoutExtendedLengthField) {
            errorString = "The minimal number of bytes MUST be used to encode the length";
            return FrameError;
        }
        if (extendedPayloadLengthSize == 8 && payloadLength64 <= 0xFFFF) {
            errorString = "The minimal number of bytes MUST be used to encode the length";
            return FrameError;
        }
    }

    static const uint64_t maxPayloadLength = UINT64_C(0x7FFFFFFFFFFFFFFF);
    size_t maskingKeyLength = masked ? kMaskingKeyWidthInBytes : 0;
    if (payloadLength64 > maxPayloadLength || payloadLength64 + maskingKeyLength > std::numeric_limits<size_t>::max()) {
        errorString = "WebSocket frame length too large: " + String::Number(payloadLength64) + " bytes";
        return FrameError;
    }
    size_t payloadLength = static_cast<size_t>(payloadLength64);

    if (static_cast<size_t>(bufferEnd - p) < maskingKeyLength + payloadLength)
        return FrameIncomplete;

    if (masked) {
        const char* maskingKey = p;
        char* payload = p + kMaskingKeyWidthInBytes;
        for (size_t i = 0; i < payloadLength; ++i)
            payload[i] ^= maskingKey[i % kMaskingKeyWidthInBytes]; // Unmask the payload.
    }

    frame.m_opCode = static_cast<WebSocketOneFrame::OpCode>(opCode);
    frame.m_final = final;
    frame.m_compress = compress;
    frame.m_reserved2 = reserved2;
    frame.m_reserved3 = reserved3;
    frame.m_masked = masked;
    frame.m_payload = p + maskingKeyLength;
    frame.m_payloadLength = payloadLength;
    frameEnd = p + maskingKeyLength + payloadLength;
    return FrameOK;
}

static void appendFramePayload(const WebSocketOneFrame& frame, Vector<char>& frameData)
{
    size_t maskingKeyStart = 0;
    if (frame.m_masked) {
        maskingKeyStart = frameData.size();
        frameData.Grow(frameData.size() + kMaskingKeyWidthInBytes); // Add placeholder for masking key. Will be overwritten.
    }

    size_t payloadStart = frameData.size();
    frameData.Append(frame.m_payload, frame.m_payloadLength);

    if (frame.m_masked) {
        //cryptographicallyRandomValues(frameData.data() + maskingKeyStart, kMaskingKeyWidthInBytes);
        base::RandBytes(base::span<uint8_t>(((uint8_t*)frameData.data() + maskingKeyStart), kMaskingKeyWidthInBytes));

        for (size_t i = 0; i < frame.m_payloadLength; ++i)
            frameData[payloadStart + i] ^= frameData[maskingKeyStart + i % kMaskingKeyWidthInBytes];
    }
}

#if 0
std::string encodeFrame(std::string& message, net::WebSocketFrameHeader::OpCodeEnum opCode, bool mask, bool finish)
{
    net::WebSocketFrameHeader header(opCode);
    header.final = finish;
    header.masked = mask;
    header.payload_length = message.size();
    const int header_size = GetWebSocketFrameHeaderSize(header);
    std::string frameHeader;
    frameHeader.resize(header_size);
    if (mask) {
        net::WebSocketMaskingKey maskingKey = net::GenerateWebSocketMaskingKey();
        net::WriteWebSocketFrameHeader(header, &maskingKey, &frameHeader[0], header_size);
        net::MaskWebSocketFramePayload(maskingKey, 0, &message[0], message.size());
    } else {
        net::WriteWebSocketFrameHeader(header, nullptr, &frameHeader[0], header_size);
    }
    return frameHeader + message;
}
#endif

void WebSocketOneFrame::makeFrameData(Vector<char>& frameData)
{
    DCHECK(!(m_opCode & ~kOpCodeMask)); // Checks whether "opCode" fits in the range of opCodes.
#if 1
    frameData.resize(2);
    frameData.at(0) = (m_final ? kFinalBit : 0) | (m_compress ? kCompressBit : 0) | m_opCode;
    frameData.at(1) = m_masked ? kMaskBit : 0;

    if (m_payloadLength <= kMaxPayloadLengthWithoutExtendedLengthField) {
        frameData.at(1) |= m_payloadLength;
    } else if (m_payloadLength <= 0xFFFF) {
        frameData.at(1) |= kPayloadLengthWithTwoByteExtendedLengthField;
        frameData.push_back((char)((m_payloadLength & 0xFF00) >> 8));
        frameData.push_back((char)(m_payloadLength & 0xFF));
    } else {
        frameData.at(1) |= kPayloadLengthWithEightByteExtendedLengthField;
        char extendedPayloadLength[8];
        size_t remaining = m_payloadLength;
        // Fill the length into extendedPayloadLength in the network byte order.
        for (int i = 0; i < 8; ++i) {
            extendedPayloadLength[7 - i] = remaining & 0xFF;
            remaining >>= 8;
        }
        DCHECK(!remaining);
        frameData.Append(extendedPayloadLength, 8);
    }

    appendFramePayload(*this, frameData);
#else
    std::string message(m_payload, m_payloadLength);
    std::string frame = encodeFrame(message, (net::WebSocketFrameHeader::OpCodeEnum)m_opCode, m_masked, m_final);
    frameData.resize(frame.size());
    memcpy(frameData.data(), frame.data(), frame.size());
#endif
}

WebSocketOneFrame::WebSocketOneFrame(OpCode opCode, bool final, bool compress, bool masked, const char* payload, size_t payloadLength)
    : m_opCode(opCode)
    , m_final(final)
    , m_compress(compress)
    , m_reserved2(false)
    , m_reserved3(false)
    , m_masked(masked)
    , m_payload(payload)
    , m_payloadLength(payloadLength)
{
}

} // namespace net
