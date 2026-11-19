// Copyright (C) 2005, 2006, 2007 Apple Inc. All rights reserved.
// Ported and adapted for miniblink132.

#ifndef CONTENT_RENDERER_NPAPI_PLUGIN_STREAM_H_
#define CONTENT_RENDERER_NPAPI_PLUGIN_STREAM_H_

#include <memory>
#include <string>
#include <vector>

#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/memory/ref_counted.h"
#include "base/memory/scoped_refptr.h"
#include "base/timer/timer.h"
#include "content/renderer/npapi/PluginPackage.h"
#include "content/renderer/npapi/PluginQuirkSet.h"
#include "mojo/public/cpp/system/data_pipe.h"
#include "mojo/public/cpp/system/simple_watcher.h"
#include "services/network/public/cpp/resource_request.h"
#include "third_party/blink/public/platform/web_url_error.h"
#include "third_party/blink/public/platform/web_url_response.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/url_loader_client.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/weborigin/security_origin.h"
#include "third_party/npapi/bindings/npapi.h"
#include "third_party/npapi/bindings/npfunctions.h"

namespace mbnet {
class WebURLLoaderImplCurl;
}

namespace content {

enum PluginStreamState {
    StreamBeforeStarted,
    StreamStarted,
    StreamStopped
};

class PluginStream;

class PluginStreamClient {
public:
    virtual ~PluginStreamClient() = default;
    virtual void streamDidFinishLoading(PluginStream*) { }
};

class PluginStream : public base::RefCounted<PluginStream>,
                     public blink::URLLoaderClient {
public:
    static scoped_refptr<PluginStream> create(PluginStreamClient* client, int64_t mbwebviewId,
        std::unique_ptr<network::ResourceRequest> request, scoped_refptr<const blink::SecurityOrigin> topFrameOrigin,
        bool sendNotification, void* notifyData, scoped_refptr<PluginPackage> pluginPackage,
        const NPPluginFuncs* pluginFuncs, NPP instance, const PluginQuirkSet& quirks);

    void start();
    void stop();

    void sendJavaScriptStream(const blink::KURL& requestURL, const std::string& resultString);
    void cancelAndDestroyStream(NPReason reason);

    void setLoadManually(bool loadManually) { m_loadManually = loadManually; }

    // Manual stream entry points (used by PluginDocument / WebPlugin::DidReceive*)
    void didReceiveResponseManual(const blink::WebURLResponse& response);
    void didReceiveDataManual(base::span<const char> data);
    void didFinishLoadingManual();
    void didFailManual(const blink::WebURLError& error);

    // blink::URLLoaderClient
    void DidReceiveResponse(const blink::WebURLResponse& response,
        absl::variant<mojo::ScopedDataPipeConsumerHandle, WTF::SegmentedBuffer> body,
        std::optional<mojo_base::BigBuffer> cachedMetadata) override;
    void DidReceiveDataForTesting(base::span<const char> data) override;
    void DidFinishLoading(base::TimeTicks finishTime, int64_t totalEncodedDataLength,
        uint64_t totalEncodedBodyLength, int64_t totalDecodedBodyLength) override;
    void DidFail(const blink::WebURLError& error, base::TimeTicks finishTime,
        int64_t totalEncodedDataLength, uint64_t totalEncodedBodyLength, int64_t totalDecodedBodyLength) override;

    static NPP ownerForStream(NPStream* stream);

private:
    friend class base::RefCounted<PluginStream>;
    PluginStream(PluginStreamClient* client, int64_t mbwebviewId, std::unique_ptr<network::ResourceRequest> request,
        scoped_refptr<const blink::SecurityOrigin> topFrameOrigin, bool sendNotification, void* notifyData,
        scoped_refptr<PluginPackage> pluginPackage, const NPPluginFuncs* pluginFuncs, NPP instance, const PluginQuirkSet& quirks);
    ~PluginStream() override;

    void startStream();
    void deliverData();
    void delayDeliveryTimerFired();
    void destroyStream(NPReason reason);
    void destroyStreamImpl();
    void setDefersLoading(bool defers);
    void onBodyPipeReadable(MojoResult result);
    void drainBodyPipe();

    PluginStreamClient* m_client = nullptr;
    int64_t m_mbwebviewId = 0;
    std::unique_ptr<network::ResourceRequest> m_request;
    std::string m_requestUrlSpec;
    std::string m_requestMethod;
    scoped_refptr<const blink::SecurityOrigin> m_topFrameOrigin;

    blink::WebURLResponse m_resourceResponse;
    std::unique_ptr<mbnet::WebURLLoaderImplCurl> m_loader;
    mojo::ScopedDataPipeConsumerHandle m_bodyPipe;
    std::unique_ptr<mojo::SimpleWatcher> m_bodyWatcher;

    void* m_notifyData = nullptr;
    bool m_sendNotification = false;
    PluginStreamState m_streamState = StreamBeforeStarted;
    bool m_loadManually = false;
    bool m_isDeliveringData = false;

    std::vector<char> m_deliveryData;
    base::OneShotTimer m_delayDeliveryTimer;

    base::FilePath m_tempFilePath;
    base::File m_tempFile;

    scoped_refptr<PluginPackage> m_pluginPackage;
    const NPPluginFuncs* m_pluginFuncs = nullptr;
    NPP m_instance = nullptr;
    uint16_t m_transferMode = NP_NORMAL;
    int32_t m_offset = 0;
    NPStream m_stream {};
    std::string m_streamUrlStorage;
    std::string m_headersStorage;
    NPReason m_reason = -2;
    PluginQuirkSet m_quirks;
    scoped_refptr<PluginStream> m_keepAlive;
};

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_PLUGIN_STREAM_H_
