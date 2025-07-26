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

#include "mbnet/BlobResourceLoader.h"

#include "content/renderer/BlobRegistryImpl.h"
#include "content/renderer/BlobURLStoreImpl.h"
#include "content/common/LiveIdDetect.h"
#include "content/browser/MbWebview.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/public/platform/web_url_response.h"
#include "third_party/blink/public/platform/web_url.h"
#include "third_party/blink/public/platform/web_url_error.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "net/base/net_errors.h"

namespace mbnet {

///////////////////////////////////////////////////////////////////////////////
// BlobResourceSynchronousLoader

namespace {

// class BlobResourceSynchronousLoader : public blink::WebURLLoaderClient {
// public:
//     BlobResourceSynchronousLoader(blink::WebURLError&, blink::WebURLResponse&, Vector<char>&);
//
//     virtual void didReceiveResponse(blink::WebURLLoader*, const blink::WebURLResponse&) override;
//     virtual void didReceiveData(blink::WebURLLoader*, const char* data, int dataLength, int encodedDataLength) override;
//     virtual void didFinishLoading(blink::WebURLLoader*, double finishTime, int64_t totalEncodedDataLength) override;
//     virtual void didFail(blink::WebURLLoader*, const blink::WebURLError&) override;
//
// private:
//     blink::WebURLError m_error;
//     blink::WebURLResponse m_response;
//     Vector<char>& m_data;
// };
//
// BlobResourceSynchronousLoader::BlobResourceSynchronousLoader(blink::WebURLError& error, blink::WebURLResponse& response, Vector<char>& data)
//     : m_error(error)
//     , m_response(response)
//     , m_data(data)
// {
// }
//
// void BlobResourceSynchronousLoader::didReceiveResponse(blink::WebURLLoader* handle, const blink::WebURLResponse& response)
// {
//     // We cannot handle the size that is more than maximum integer.
//     if (response.expectedContentLength() > INT_MAX) {
//         m_error.domain = blink::WebString::fromUTF8(webKitBlobResourceDomain);
//         m_error.reason = notReadableError;
//         m_error.unreachableURL = response.url();
//         m_error.localizedDescription = blink::WebString::fromUTF8("File is too large");
//         return;
//     }
//
//     m_response = response;
//
//     // Read all the data.
//     m_data.resize(static_cast<size_t>(response.expectedContentLength()));
//     //static_cast<BlobResourceLoader*>(handle)->readSync(m_data.data(), static_cast<int>(m_data.size()));
//     // TODO
// }
//
// void BlobResourceSynchronousLoader::didReceiveData(blink::WebURLLoader*, const char* data, int dataLength, int)
// {
//     m_data.append(data, dataLength);
// }
//
// void BlobResourceSynchronousLoader::didFinishLoading(blink::WebURLLoader*, double, int64_t)
// {
// }
//
// void BlobResourceSynchronousLoader::didFail(blink::WebURLLoader*, const blink::WebURLError& error)
// {
//     m_error = error;
// }

}

///////////////////////////////////////////////////////////////////////////////
// BlobResourceLoader

// xhr.open(URL.createObjectURL(inputFile))的时候会走到这里。
// fileReader.readAsArrayBuffer(blob);的时候也会走到这里。
// 下面是个经典的场景，会出现两次BlobResourceLoader：
// function objectURLToBlob(url, callback) {
//   var xhr = new XMLHttpRequest();
//   xhr.open("GET", url, true);
//   xhr.responseType = "blob";
//   xhr.onload = function(e) {
//     if (this.status == 200 || this.status == = 0) {
//       callback(this.response);
//     }
//   };
//   xhr.send();
// }
//
// var fileReader = new FileReader();
// fileReader.onload = function(e) {
//   handleBinaryFile(e.target.result);
// };
// var img = new Image();
// img.src = URL.createObjectURL(file);
// objectURLToBlob(img.src, function(blob) {
//   fileReader.readAsArrayBuffer(blob);
// }
// https://newimage.chinahuanong.com.cn:8001/SunECM/ecm-view/image/webScan/js/uploadify/AjaxUpload.js
// https://newimage.chinahuanong.com.cn:8001/SunECM/ecm-view/image/webScan/js/uploadify/exif.js
// https://newimage.chinahuanong.com.cn:8001/SunECM/ecm-view/image/webScan/js/uploadify/lrz.js
BlobResourceLoader* BlobResourceLoader::createAsync(int64_t mbwebviewId, const GURL& url, blink::URLLoaderClient* client)
{
    BlobResourceLoader* ret = new BlobResourceLoader(mbwebviewId, url, client, true);
    return ret;
}

BlobResourceLoader::BlobResourceLoader(int64_t mbwebviewId, const GURL& url, blink::URLLoaderClient* client, bool async)
{
    m_webviewId = mbwebviewId;
    m_url = url;
    m_client = client;
    m_async = async;
}

BlobResourceLoader::~BlobResourceLoader()
{
}

void BlobResourceLoader::start()
{
    if (!m_async) {
        doStart();
    } else {
        BlobResourceLoader* self = this;
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](BlobResourceLoader* self) { self->doStart(); }, base::Unretained(this)));
    }
}

void BlobResourceLoader::doStart()
{
    blink::WebURLResponse response;
    blink::KURL kurl(m_url);
    response.SetCurrentRequestUrl((blink::WebURL)kurl);

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_webviewId);
    if (!webview)
        return;

    blink::WebURLError error(net::ERR_ABORTED, kurl);
    ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(m_url.possibly_invalid_spec());
    if (!blob) {
        m_client->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
        return;
    }

    BlobResourceLoader* self = this;
    std::string* uuid = nullptr;
    (*blob)->GetInternalUUID(base::BindOnce([](std::string** uuid, const WTF::String& uid) { *uuid = new std::string(uid.Ascii()); }, &uuid));
    content::BlobEntry* blobEntry = content::BlobEntry::findByUuid(*uuid);
    delete uuid;

    if (!blobEntry) {
        m_client->DidFail(error, base::TimeTicks::Now(), 0, 0, 0);
        return;
    }

    response.SetMimeType(blink::WebString::FromUTF8(blobEntry->m_contentType));
    response.SetHttpStatusCode(200);
    response.SetHttpStatusText(blink::WebString::FromUTF8("OK"));

    std::vector<char> buffer;
    int64_t allSize = 0;
    blobEntry->read(&buffer, 0, -1, &allSize);
    uint32_t numBytes = (uint32_t)buffer.size();

    if (m_async) {
        MojoHandle dataPipeProducerHandle = 0;
        MojoHandle dataPipeConsumerHandle = 0;
        MojoCreateDataPipeOptions createDataOptions;
        createDataOptions.element_num_bytes = 1;
        createDataOptions.capacity_num_bytes = -1;
        MojoCreateDataPipe(&createDataOptions, &dataPipeProducerHandle, &dataPipeConsumerHandle);

        mojo::DataPipeConsumerHandle dataPipeConsumer(dataPipeConsumerHandle);
        mojo::ScopedDataPipeConsumerHandle responseBodyHandld(std::move(dataPipeConsumer));

        if (0 != numBytes)
            MojoWriteData(dataPipeProducerHandle, buffer.data(), &numBytes, nullptr);
        MojoClose(dataPipeProducerHandle);

        // 这个会触发 fetcher_->GetBlobRegistry()->RegisterFromStream -》
        // BlobBytesProvider::Bind，然后跑在一个worker thread。这块还不知道怎么处理
        //m_client->DidStartLoadingResponseBody(std::move(responseBodyHandld));
        m_client->DidReceiveResponse(response, std::move(responseBodyHandld), absl::nullopt);
    } else {
        //m_client->DidReceiveData(buffer.data(), numBytes);
        DebugBreak();
    }

    m_client->DidFinishLoading(base::TimeTicks::Now(), numBytes, numBytes, numBytes);
}

} // namespace net
