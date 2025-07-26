/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

#ifndef mbnet_BlobResourceLoader_h
#define mbnet_BlobResourceLoader_h

#include "url/gurl.h"
#include <memory>

namespace blink {
class WebURLRequest;
class WebURLResponse;
class URLLoaderClient;
class WebURLLoader;
struct WebURLError;
}

namespace mbnet {

class BlobResourceLoader {
public:
    static BlobResourceLoader* createAsync(int64_t mbwebviewId, const GURL& url, blink::URLLoaderClient* client);

    //static void loadSynchronously(BlobDataWrap*, const blink::WebURLRequest&, blink::WebURLLoader*, blink::WebURLError&, blink::WebURLResponse&, Vector<char>& data);

    void start();
    int readSync(char*, int);

    ~BlobResourceLoader();

private:
    BlobResourceLoader(int64_t mbwebviewId, const GURL& url, blink::URLLoaderClient* client, bool async);

    void doNotifyFinish();
    void doStart();
    void failed(int errorCode);

    void notifyResponse();
    void notifyResponseOnSuccess();
    void notifyResponseOnError();
    void notifyReceiveData(const char*, int);
    void notifyFail(int errorCode);
    void notifyFinish();

    int m_id;
    int m_webviewId;

    blink::URLLoaderClient* m_client;
    GURL m_url;
    bool m_async;
};

} // namespace WebCore

#endif // mbnet_BlobResourceLoader_h
