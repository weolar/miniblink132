// Copyright 2012 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_HTTP_HTTP_UTIL_H_
#define NET_HTTP_HTTP_UTIL_H_

#include "net/http/http_util.h"

#include <algorithm>

#include "base/check_op.h"
#include "base/containers/cxx20_erase.h"
#include "base/strings/strcat.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_piece.h"
#include "base/strings/string_split.h"
#include "base/strings/string_tokenizer.h"
#include "base/strings/string_util.h"
#include "base/strings/stringprintf.h"
#include "base/time/time.h"
#include "net/base/features.h"
#include "net/base/mime_util.h"
#include "net/base/parse_number.h"
#include "net/base/url_util.h"
#include "net/http/http_response_headers.h"

namespace net {
static size_t LocateEndOfHeadersHelper(const char* buf, size_t buf_len, size_t i, bool accept_empty_header_list)
{
    char last_c = '\0';
    bool was_lf = false;
    if (accept_empty_header_list) {
        // Normally two line breaks signal the end of a header list. An empty header
        // list ends with a single line break at the start of the buffer.
        last_c = '\n';
        was_lf = true;
    }

    for (; i < buf_len; ++i) {
        char c = buf[i];
        if (c == '\n') {
            if (was_lf)
                return i + 1;
            was_lf = true;
        } else if (c != '\r' || last_c != '\n') {
            was_lf = false;
        }
        last_c = c;
    }
    return std::string::npos;
}

size_t HttpUtil::LocateEndOfAdditionalHeaders(const char* buf, size_t buf_len, size_t i)
{
    return LocateEndOfHeadersHelper(buf, buf_len, i, true);
}

size_t HttpUtil::LocateEndOfHeaders(const char* buf, size_t buf_len, size_t i)
{
    return LocateEndOfHeadersHelper(buf, buf_len, i, false);
}
}

#endif
