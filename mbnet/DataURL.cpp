/*
 * Copyright (C) 2007 Alp Toker <alp@atoker.com>
 * Copyright (C) 2010 Patrick Gansterer <paroga@paroga.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "mbnet/DataURL.h"

#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "third_party/blink/public/platform/web_url_error.h"
#include "third_party/blink/public/platform/web_url.h"
#include "third_party/blink/public/platform/web_url_response.h"
#include "third_party/blink/renderer/platform/network/http_parsers.h"
#include "third_party/blink/renderer/platform/wtf/wtf.h"
#include "third_party/blink/renderer/platform/wtf/text/text_codec.h"
#include "third_party/blink/renderer/platform/wtf/text/text_encoding.h"
#include "third_party/blink/renderer/platform/wtf/text/base64.h"
#include "base/task/sequenced_task_runner.h"
#include "net/base/net_errors.h"
#include "mbnet/WebURLLoaderInternal.h"
#include "mbnet/WebURLLoaderManager.h"
#include <windows.h>

namespace mbnet {

void finishHandleDataURL(bool isSync, std::function<void(void)>&& closure)
{
    CHECK(WTF::IsMainThread());
    if (isSync) {
        closure();
        return;
    }
    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](std::function<void(void)>&& closure) { closure(); }, std::move(closure)));
}

void handleDataURL(int jobId, blink::URLLoader* handle, blink::URLLoaderClient* client, const blink::KURL& kurl, bool useStreamOnResponse, bool isSync)
{
    Vector<char>* data = new Vector<char>();
    String mimeType;
    String charset;
    bool ok = parseDataURL((GURL)kurl, mimeType, charset, *data);
    if (!ok) {
        blink::WebURLError error(net::ERR_INVALID_ARGUMENT, kurl);
        //error.domain = blink::WebString(kurl);
        //error.localizedDescription = blink::WebString::fromUTF8("Cannot show DataURL\n");
        client->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
        return;
    }

    blink::WebURLResponse* response = new blink::WebURLResponse();
    //response->initialize();
    response->SetMimeType(mimeType);
    response->SetTextEncodingName(charset);
    response->SetCurrentRequestUrl(blink::WebURL(kurl));
    response->SetExpectedContentLength(data->size());
    response->SetHttpStatusCode(200);
    response->SetHttpStatusText(blink::WebString::FromLatin1("OK"));

    if (useStreamOnResponse) {
        OutputDebugStringA("handleDataURL, useStreamOnResponse\n");
    }

    //     SharedMemoryDataConsumerHandle::BackpressureMode mode = SharedMemoryDataConsumerHandle::kDoNotApplyBackpressure;
    //     SharedMemoryDataConsumerHandle::Writer* bodyStreamWriter = nullptr;
    //     SharedMemoryDataConsumerHandle* readHandle = new SharedMemoryDataConsumerHandle(mode, WTF::bind(&cancelBodyStreaming, bodyStreamWriter), &bodyStreamWriter);

    finishHandleDataURL(isSync, [jobId, client, /*readHandle,*/ response, data] {
//         client->DidReceiveResponse(*response);
//         client->DidReceiveData(data->data(), data->size());
        DebugBreak();

        client->DidFinishLoading(base::TimeTicks::Now(), data->size(), data->size(), data->size());

        WebURLLoaderManager* manager = WebURLLoaderManager::sharedInstance();
        JobHead* jobHead = manager->checkJob(jobId);
        delete jobHead;
        manager->removeLiveJobs(jobId);

        delete response;
        delete data;
    });
}

std::string extractCharset(const WTF::String& contentType);

bool shouldIgnoreCharacter(UChar c)
{
    if (c == u8' ' || c == u8'\n')
        return true;
    return false;
}

bool parseDataURL(const GURL& kurl, String& mimeType, String& charset, Vector<char>& out)
{
    out.clear();
    String url(kurl.possibly_invalid_spec());

    int index = url.find(',');
    if (index == -1)
        return false;

    String mediaType = url.Substring(5, index - 5);
    String data = url.Substring(index + 1);

    bool base64 = mediaType.EndsWith(";base64", WTF::kTextCaseASCIIInsensitive);
    if (base64)
        mediaType = mediaType.Left(mediaType.length() - 7);

    if (mediaType.empty())
        mediaType = "text/plain";

    mimeType = blink::ExtractMIMETypeFromMediaType(WTF::AtomicString(mediaType));
    charset = extractCharset(WTF::AtomicString(mediaType)).c_str();

    if (charset.empty())
        charset = "US-ASCII";

    int64_t totalEncodedDataLength = 0;
    if (base64) {
        data = /*WTF::ensureStringToUTF8String*/ (blink::DecodeURLEscapeSequences(data, url::DecodeURLMode::kUTF8));
        if (!(WTF::Base64Decode(data, out/*, shouldIgnoreCharacter*/) && out.size() > 0))
            return false;

        totalEncodedDataLength = out.size();
    } else {
        WTF::TextEncoding encoding(charset);
        data = /*WTF::ensureStringToUTF8String*/ (blink::DecodeURLEscapeSequences(data, /*encoding*/ url::DecodeURLMode::kUTF8));

        std::string encodedData = encoding.Encode(data, WTF::kURLEncodedEntitiesForUnencodables);
        if (0 == encodedData.length())
            return false;

        out.Append(encodedData.data(), encodedData.length());
        totalEncodedDataLength = encodedData.length();
    }

    return true;
}

} // namespace WebCore
