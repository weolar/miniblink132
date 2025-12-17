
#include "content/renderer/WebLocalFrameClientImpl.h"

#include "content/renderer/AssociatedInterfaceProviderImpl.h"
#include "content/renderer/ContentSecurityNotifierImpl.h"
#include "content/renderer/ReportingServiceProxyImpl.h"
#include "content/renderer/BlinkInterfaceRegistryImpl.h"
#include "content/renderer/PolicyContainerHostImpl.h"
#include "content/renderer/WebWorkerFetchContextImpl.h"
#include "content/renderer/ClipboardHostImpl.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/renderer/NoStatePrefetchProcessorImpl.h"
#include "content/renderer/DevicePostureProviderImpl.h"
#include "content/renderer/PermissionServiceImpl.h"
#include "content/renderer/SpeculationHostImpl.h"
#include "content/browser/QuotaManagerHostImpl.h"
#include "content/browser/FileChooserImpl.h"
#include "content/browser/RestrictedCookieManagerImpl.h"
#include "content/browser/MbWebview.h"
#include "content/browser/WebFrameMain.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/CreateAndBindTempl.h"
#include "content/common/ThreadCall.h"
#include "services/network/public/cpp/resource_request.h"
#include "services/network/public/cpp/single_request_url_loader_factory.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/public/platform/platform.h"
//#include "third_party/blink/public/platform/web_url_loader_mock_factory.h"
#include "third_party/blink/renderer/core/loader/document_loader.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/exported/web_view_impl.h"
#include "third_party/blink/public/platform/weak_wrapper_resource_load_info_notifier.h"
#include "third_party/blink/public/platform/web_url_request_extra_data.h"
#include "third_party/blink/public/platform/web_http_header_visitor.h"
#include "third_party/blink/public/platform/scheduler/web_agent_group_scheduler.h"
#include "third_party/blink/public/platform/web_url_request_util.h"
#include "third_party/blink/public/web/web_console_message.h"
#include "third_party/blink/public/web/web_navigation_control.h"
#include "third_party/blink/renderer/platform/network/network_utils.h"
#include "third_party/blink/renderer/platform/loader/fetch/url_loader/navigation_body_loader.h"
#include "gen/third_party/blink/public/mojom/loader/navigation_predictor.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/preloading/anchor_element_interaction_host.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/preloading/anchor_element_interaction_host.mojom-blink-forward.h"
#include "gen/third_party/blink/public/mojom/worker/shared_worker_connector.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/worker/shared_worker_info.mojom-blink.h"
#include "gin/public/gin_embedders.h"
#include "mbnet/LoaderFactoryImpl.h"
#include "mbnet/SingleRequestURLLoader.h"
#include "mbnet/WebURLLoaderImplCurl.h"
#include "mbnet/WebURLRequestExtraDataWrap.h"
#include "base/strings/utf_string_conversions.h"

network::DocumentIsolationPolicy::~DocumentIsolationPolicy(void)
{
    *(int*)1 = 1;
}

std::string ui::AXTreeData::ToString(void) const
{
    *(int*)1 = 1;
    return "";
}

ui::AXRelativeBounds::~AXRelativeBounds(void)
{
    *(int*)1 = 1;
}

ui::AXTreeUpdate::~AXTreeUpdate(void)
{
    *(int*)1 = 1;
}

ui::AXEvent::~AXEvent(void)
{
    *(int*)1 = 1;
}

ui::AXLocationAndScrollUpdates::~AXLocationAndScrollUpdates(void)
{
    *(int*)1 = 1;
}

ui::AXTreeData::~AXTreeData(void)
{
    *(int*)1 = 1;
}

ui::AXEventIntent::~AXEventIntent(void)
{
    *(int*)1 = 1;
}

ui::AXScrollChange::~AXScrollChange(void)
{
    *(int*)1 = 1;
}

ui::AXLocationChange::~AXLocationChange(void)
{
    *(int*)1 = 1;
}

namespace content {

WebLocalFrameClientImpl::WebLocalFrameClientImpl(int64_t mbwebviewId)
    : m_mbwebviewId(mbwebviewId)
    , m_associatedInterfaceProviderImpl(new AssociatedInterfaceProviderImpl(this))
    , m_interfaceProviderReceiver(m_associatedInterfaceProviderImpl)
{
}

WebLocalFrameClientImpl::~WebLocalFrameClientImpl()
{
    if (m_associatedInterfaceProviderImpl)
        delete m_associatedInterfaceProviderImpl;

    if (m_blinkPolicyContainerHostReceiver)
        delete m_blinkPolicyContainerHostReceiver;

    if (m_blinkInterfaceRegistryImpl)
        delete m_blinkInterfaceRegistryImpl;

    WebFrameMain::destroy(getFrameIdByWebLocalFrame(m_frame));
}

::blink::AssociatedInterfaceProvider* WebLocalFrameClientImpl::GetRemoteNavigationAssociatedInterfaces()
{
    if (m_associatedInterfaceProvider.get())
        return m_associatedInterfaceProvider.get();

    mojo::PendingAssociatedRemote<::blink::mojom::AssociatedInterfaceProvider> associatedInterfaceProviderRemote;
    mojo::PendingAssociatedReceiver<::blink::mojom::AssociatedInterfaceProvider> associatedInterfacePendingReceiver
        = associatedInterfaceProviderRemote.InitWithNewEndpointAndPassReceiver();

    m_interfaceProviderReceiver.Bind(std::move(associatedInterfacePendingReceiver));

    m_associatedInterfaceProvider = std::make_unique<::blink::AssociatedInterfaceProvider>(std::move(associatedInterfaceProviderRemote));
    return m_associatedInterfaceProvider.get();
}

intptr_t getFrameIdByWebLocalFrame(blink::WebLocalFrame* frame)
{
    if (!frame)
        return 0;
    const blink::LocalFrameToken& token = frame->GetLocalFrameToken();
    return (blink::LocalFrameToken::Hasher()(token));
}

blink::WebLocalFrame* WebLocalFrameClientImpl::CreateChildFrame(
    blink::mojom::TreeScopeType scope, 
    const blink::WebString& name,
    const blink::WebString& fallbackName, 
    const blink::FramePolicy&, 
    const blink::WebFrameOwnerProperties&, 
    blink::FrameOwnerElementType,
    blink::WebPolicyContainerBindParams policyContainerBindParams, 
    ukm::SourceId document_ukm_source_id, 
    blink::WebLocalFrameClient::FinishChildFrameCreationFn completeCreation)
{
    blink::LocalFrameToken frameToken;
    blink::DocumentToken documentToken;

    WebLocalFrameClientImpl* newClinet = new WebLocalFrameClientImpl(m_mbwebviewId);
    newClinet->m_blinkInterfaceRegistryImpl = new BlinkInterfaceRegistryImpl(newClinet);
    blink::WebLocalFrame* webframe = m_navigationControl->CreateLocalChild(scope, newClinet,
        newClinet->m_blinkInterfaceRegistryImpl, // child_render_frame->blink_interface_registry_.get(),
        frameToken);
    newClinet->setFrame(webframe);
    new WebFrameMain(getFrameIdByWebLocalFrame(webframe), getFrameIdByWebLocalFrame(m_frame), false);

    {
        mojo::PendingAssociatedReceiver<blink::mojom::PolicyContainerHostInterfaceBase> policyContainerReceiverBase
            = mojo::PendingAssociatedReceiverConverter<blink::CrossVariantMojoAssociatedReceiver<blink::mojom::PolicyContainerHostInterfaceBase>>::To<
                blink::mojom::PolicyContainerHostInterfaceBase>(std::move(policyContainerBindParams.receiver));

        mojo::PendingAssociatedReceiver<blink::mojom::blink::PolicyContainerHost> policyContainerReceiver(policyContainerReceiverBase.PassHandle());

        newClinet->m_blinkPolicyContainerHost.reset(new PolicyContainerHostImpl());
        newClinet->m_blinkPolicyContainerHostReceiver
            = new mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>(newClinet->m_blinkPolicyContainerHost.get());
        newClinet->m_blinkPolicyContainerHostReceiver->Bind(std::move(policyContainerReceiver)); // TODO: 内存泄露
    }

    //     CreateFrameWidgetParams* createFrameWidgetParams = m_renderWidgetHostImpl->bindAndGenerateCreateFrameWidgetParams();
    //     m_renderWidgetHostImpl->m_mainFrame = webFrame;
    //     m_renderWidgetHostImpl->m_webWiew = webWiew;
    //
    //     blink::WebFrameWidget* webFrameWidget = webframe->InitializeFrameWidget(
    //             blink::ToCrossVariantMojoType(std::move(createFrameWidgetParams->frameWidgetHost)),
    //             blink::ToCrossVariantMojoType(std::move(createFrameWidgetParams->frameWidget)),
    //             blink::ToCrossVariantMojoType(std::move(createFrameWidgetParams->widgetHost)),
    //             blink::ToCrossVariantMojoType(std::move(createFrameWidgetParams->widget)),
    //             viz::FrameSinkId(/*RenderThread::Get()->GetClientId()*/ 1, /*params->widget_params->routing_id*/ 2),
    //             /*is_for_nested_main_frame*/ false, /*is_for_scalable_page*/ true,
    //             /*hidden=*/true);
    //     webFrameWidget->InitializeCompositing(
    //         *m_renderWidgetHostImpl->m_agentGroupScheduler, createFrameWidgetParams->visualProperties.screen_infos, /*settings=*/nullptr);
    //
    //     const char* urlStr =
    //         //"file:///G:/test/web_test/monaco-editor/m3u8-downloader-master/index.html";
    //         //"file:///G:/mycode/mb108/content/demo/res/jiqimao2.htm";
    //         //"file:///G:/mycode/mb108/content/demo/test.htm";
    //         //"http://windbg.org/";
    //         //"https://mycaht.top/";
    //         //"http://192.168.0.102:8091/index.html";
    //         //"https://foundation.mozilla.org/en/";
    //         //"https://vuejs.org/";
    //         "file:///W:/test/web_test/message_test/3.htm";
    //
    //     loadUrl(urlStr, frameClient->m_navigationControl);

    mojo::PendingRemote<blink::mojom::BrowserInterfaceBroker> browserInterfaceBroker = newClinet->getBrowserInterfaceBrokerProxyReceiver().BindNewPipeAndPassRemote();
    completeCreation(webframe, documentToken, blink::CrossVariantMojoRemote<blink::mojom::BrowserInterfaceBrokerInterfaceBase>(std::move(browserInterfaceBroker)));

    return webframe;
}

void WebLocalFrameClientImpl::DidCreateDocumentLoader(blink::WebDocumentLoader* loader)
{
    //     MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    //     if (!webview)
    //         return;
    //
    //     webview->dispatchUrlCheanged(loader->GetUrl().GetString().Utf8());
}

// W:\chromium\liebao57\chrome_57_b2987_8003\src\content\browser\loader\mime_sniffing_resource_handler.cc
const char* kAcceptHeader = "Accept";
const char kFrameAcceptHeader[] = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8";
const char kStylesheetAcceptHeader[] = "text/css,*/*;q=0.1";
const char kImageAcceptHeader[] = "image/webp,image/*,*/*;q=0.8";
const char kDefaultAllAcceptHeader[] = "*/*";
const char* kDefaultAcceptHeader = "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8";

void setNetworkRequestHead(blink::WebLocalFrame* webFrame, network::ResourceRequest* request)
{
    //request->headers.SetHeaderIfMissing("Accept-Language", "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6,ja;q=0.5");
    //request->headers.SetHeaderIfMissing(kAcceptHeader, blink::WebString::FromLatin1(acceptValue));
    request->headers.SetHeaderIfMissing("Accept-Language", "zh-CN,zh;q=0.9");
    //request->headers.SetHeaderIfMissing(kAcceptHeader, "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
    request->headers.SetHeaderIfMissing(
        kAcceptHeader, "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
    request->headers.SetHeaderIfMissing("Upgrade-Insecure-Requests", "1");
    request->headers.SetHeaderIfMissing("Connection", "keep-alive");
    request->headers.SetHeaderIfMissing("Accept-Encoding", "gzip, deflate, br");
    request->headers.SetHeaderIfMissing("User-Agent", blink::Platform::Current()->UserAgent().Utf8());
    //  
    //request->headers.SetHeaderIfMissing("cache-control", "max-age=0");
    //request->headers.SetHeaderIfMissing("host", "data.10jqka.com.cn");
    //request->headers.SetHeaderIfMissing("sec-fetch-site", "same-origin");
    //  
    request->headers.SetHeaderIfMissing("sec-ch-ua", "\"Not ? A_Brand\";v=\"8\", \"Chromium\";v=\"132\"");
    request->headers.SetHeaderIfMissing("sec-ch-ua-mobile", "?0");
    request->headers.SetHeaderIfMissing("sec-ch-ua-platform", "Windows");
    request->headers.SetHeaderIfMissing("sec-fetch-dest", "document");
    request->headers.SetHeaderIfMissing("sec-fetch-mode", "navigate");
    request->headers.SetHeaderIfMissing("sec-fetch-site", "none");
    request->headers.SetHeaderIfMissing("sec-fetch-user", "?1");
}

static void addHeaderIfMissing(blink::WebURLRequest& request, const std::string& name, const std::string& value)
{
    String val = request.HttpHeaderField(blink::WebString::FromLatin1(name));
    if (val.empty())
        request.AddHttpHeaderField(blink::WebString::FromLatin1(name), blink::WebString::FromLatin1(value));
}

void setRequestHead(blink::WebLocalFrame* webFrame, blink::WebURLRequest& request)
{
    const char* acceptValue = nullptr;
    blink::mojom::RequestContextType requestContext = request.GetRequestContext();
    switch (requestContext) {
    case blink::mojom::RequestContextType::FRAME:
        acceptValue = kFrameAcceptHeader;
        break;
    case blink::mojom::RequestContextType::STYLE:
        acceptValue = kStylesheetAcceptHeader;
        break;
    case blink::mojom::RequestContextType::FAVICON:
    case blink::mojom::RequestContextType::IMAGE:
    case blink::mojom::RequestContextType::IMAGE_SET:
        acceptValue = kImageAcceptHeader;
        break;
    default:
        acceptValue = kDefaultAllAcceptHeader; // kDefaultAcceptHeader
        break;
    }

    std::string url = request.Url().GetString().Utf8();
    addHeaderIfMissing(request, kAcceptHeader, acceptValue);
    addHeaderIfMissing(request, "Accept-Language", /*webPage->webPageImpl()->acceptLanguages()*/ "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6,ja;q=0.5");
    addHeaderIfMissing(request, "Upgrade-Insecure-Requests", "1");
    addHeaderIfMissing(request, "Connection", "keep-alive");
    addHeaderIfMissing(request, "Accept-Encoding", "gzip, deflate, br");

    //     blink::WebSecurityOrigin origin = request.RequestorOrigin();
    //     if (origin.IsNull()) {
    //         blink::WebString referr = request.ReferrerString();
    //         if (!referr.IsNull())
    //             origin = blink::WebSecurityOrigin::CreateFromString(referr);
    //     }
    //     request.SetRequestorOrigin(origin);

    String ua = request.HttpHeaderField("User-Agent");
    if (ua.empty())
        request.AddHttpHeaderField("User-Agent", AtomicString(String(blink::Platform::Current()->UserAgent())));
    //request.AddHttpHeaderField("Cache-Control", "max-age=0");

    //     WebViewImpl* viewImpl = m_webPage->webViewImpl();
    //     if (!viewImpl)
    //         return;
    //     Page* page = viewImpl->page();
    //     if (!page)
    //         return;
    //
    //     Settings& setting = page->settings();
    //     headerFieldValue = "GBK"; // setting.defaultTextEncodingName();
    //     headerFieldValue.append(",utf-8;q=0.7,*;q=0.3");
    //     value = headerFieldValue.latin1().data();
    //     request.AddHttpHeaderField("Accept-Charset", WebString::fromLatin1((const WebLChar*)value.data(), value.length()));

    // Set the first party for cookies url if it has not been set yet (new
    // requests). For redirects, it is updated by WebURLLoaderImpl.
    //     if (request.firstPartyForCookies().isEmpty()) {
    //         if (request.getFrameType() == blink::WebURLRequest::FrameTypeTopLevel) {
    //             request.setFirstPartyForCookies(request.url());
    //         } else if (webFrame) {
    //             // TODO(nasko): When the top-level frame is remote, there is no document.
    //             // This is broken and should be fixed to propagate the first party.
    //             WebFrame* top = webFrame->top();
    //             if (!top)
    //                 top = webFrame;
    //             if (top->isWebLocalFrame())
    //                 request.SetFirstPartyForCookies(webFrame->top()->document().firstPartyForCookies());
    //         }
    //     }

    //     WebDataSource* provisionalDataSource = webFrame->provisionalDataSource();
    //     WebDataSource* dataSource = provisionalDataSource ? provisionalDataSource : webFrame->dataSource();

    // The request's extra data may indicate that we should set a custom user
    // agent. This needs to be done here, after WebKit is through with setting the
    // user agent on its own. Similarly, it may indicate that we should set an
    // X-Requested-With header. This must be done here to avoid breaking CORS
    // checks.
    // PlzNavigate: there may also be a stream url associated with the request.

    // Add the default accept header for frame request if it has not been set
    // already.
    //     if ((request.GetFrameType() == blink::WebURLRequest::FrameTypeTopLevel ||
    //         request.getFrameType() == blink::WebURLRequest::FrameTypeNested) && request.httpHeaderField(blink::WebString::FromUTF8(kAcceptHeader)).isEmpty()) {
    //         request.AddHttpHeaderField(blink::WebString::FromUTF8(kAcceptHeader), blink::WebString::FromUTF8(kDefaultAcceptHeader));
    //     }

    // Add an empty HTTP origin header for non GET methods if none is currently
    // present.
    //request.addHTTPOriginIfNeeded(blink::WebSecurityOrigin());

    // This is an instance where we embed a copy of the routing id
    // into the data portion of the message. This can cause problems if we
    // don't register this id on the browser side, since the download manager
    // expects to find a RenderViewHost based off the id.
    //request.SetHasUserGesture(blink::WebUserGestureIndicator::isProcessingUserGesture());
}

std::optional<blink::WebURL> WebLocalFrameClientImpl::WillSendRequest(
    //blink::WebURLRequest& req, blink::WebLocalFrameClient::ForRedirect
    const blink::WebURL& target, const blink::WebSecurityOrigin& security_origin, const net::SiteForCookies& site_for_cookies,
    blink::WebLocalFrameClient::ForRedirect for_redirect, const blink::WebURL& upstream_url
)
{
    return target;
}

void WebLocalFrameClientImpl::FinalizeRequest(blink::WebURLRequest& req)
{
    scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData = base::MakeRefCounted<mbnet::WebURLRequestExtraDataWrap>();
    extraData->mbwebviewId = m_mbwebviewId;
    req.SetURLRequestExtraData(extraData);

    setRequestHead(m_frame, req);
}

scoped_refptr<network::SharedURLLoaderFactory> CreateURLLoaderFactoryByMbWebview(int64_t id)
{
    scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData = base::MakeRefCounted<mbnet::WebURLRequestExtraDataWrap>();
    extraData->mbwebviewId = id;

    scoped_refptr<base::SingleThreadTaskRunner> runner = base::SingleThreadTaskRunner::GetCurrentDefault();
    mbnet::SingleRequestURLLoader* loader = new mbnet::SingleRequestURLLoader(runner, runner, nullptr, extraData);

    return base::MakeRefCounted<mbnet::SingleReqURLLoaderFactory>(base::BindOnce(&mbnet::SingleRequestURLLoader::startLoader,
        base::Unretained(loader)));
}

// third_party\blink\renderer\core\editing\serializers\serialization.cc
scoped_refptr<network::SharedURLLoaderFactory> WebLocalFrameClientImpl::GetURLLoaderFactory()
{
    return CreateURLLoaderFactoryByMbWebview(m_mbwebviewId);
}

class WebHTTPHeaderVisitorimpl : public blink::WebHTTPHeaderVisitor {
public:
    void VisitHeader(const blink::WebString& name, const blink::WebString& value) override
    {
        m_request->headers.SetHeader(name.Utf8(), value.Utf8());
    }
    network::ResourceRequest* m_request = nullptr;
};

bool decidePolicyForNavigation(int64_t mbwebviewId, blink::WebLocalFrame* frame, const blink::WebNavigationInfo& info)
{
#if 1 // ENABLE_WKE == 1
    MbWebView* self = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(mbwebviewId);
    if (!self)
        return true;
    if (!self->getClosure().m_NavigationCallback)
        return true;

    GURL gurl = (GURL)(blink::KURL)info.url_request.Url();

    mbNavigationType navigationType;
    switch (info.navigation_type) {
    case blink::kWebNavigationTypeLinkClicked:
        navigationType = MB_NAVIGATION_TYPE_LINKCLICK;
        break;
    case blink::kWebNavigationTypeFormSubmitted:
        navigationType = MB_NAVIGATION_TYPE_FORMSUBMITTE;
        break;
    case blink::kWebNavigationTypeBackForward:
        navigationType = MB_NAVIGATION_TYPE_BACKFORWARD;
        break;
    case blink::kWebNavigationTypeReload:
        navigationType = MB_NAVIGATION_TYPE_RELOAD;
        break;
    case blink::kWebNavigationTypeFormResubmittedReload:
        navigationType = MB_NAVIGATION_TYPE_FORMRESUBMITT;
        break;
    case blink::kWebNavigationTypeOther:
        navigationType = MB_NAVIGATION_TYPE_OTHER;
        break;
    case blink::kWebNavigationTypeRestore:
    case blink::kWebNavigationTypeFormResubmittedBackForward:
        navigationType = MB_NAVIGATION_TYPE_OTHER;
        break;
    }

    BOOL result = TRUE;
    std::string urlStr = gurl.possibly_invalid_spec().c_str();
    const char* url = urlStr.c_str();
    ThreadCall::callUiThreadSync(FROM_HERE, [&result, mbwebviewId, navigationType, url] {
        MbWebView* self = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(mbwebviewId);
        if (!self)
            return;
        result = self->getClosure().m_NavigationCallback(mbwebviewId, self->getClosure().m_NavigationParam, navigationType, url);
    });
#endif
    return !!result;
}

static void beginNavigation(
    std::unique_ptr<blink::WebNavigationInfo> info, 
    blink::WebNavigationControl* navigationControl, 
    int64_t mbwebviewId,
    MojoHandle dataPipeProducerHandle, 
    blink::WebLocalFrame* frame, 
    std::unique_ptr<String> downloadName
    )
{
    if (!decidePolicyForNavigation(mbwebviewId, frame, *info))
        return;

    const blink::FrameToken& token = frame->GetFrameToken();
    ::network::mojom::URLResponseHeadPtr urlResponseHead = ::network::mojom::URLResponseHead::New();

    scoped_refptr<base::SingleThreadTaskRunner> freezableRunner = base::SingleThreadTaskRunner::GetCurrentDefault();
    scoped_refptr<base::SingleThreadTaskRunner> unfreezableRunner = base::SingleThreadTaskRunner::GetCurrentDefault();

    std::unique_ptr<mbnet::WebURLLoaderImplCurl> loader
        = std::make_unique<mbnet::WebURLLoaderImplCurl>(std::move(freezableRunner), std::move(unfreezableRunner), nullptr, mbwebviewId);
    loader->setNotAutoDestroy();

    std::unique_ptr<network::ResourceRequest> request = std::make_unique<network::ResourceRequest>();
    request->url = (GURL)(blink::KURL)info->url_request.Url();
    request->method = info->url_request.HttpMethod().Utf8();

    const blink::WebHTTPBody& httpBody = info->url_request.HttpBody();
    if (!httpBody.IsNull())
        request->request_body = blink::GetRequestBodyForWebHTTPBody(httpBody);

    if ((info->frame_type == blink::mojom::RequestContextFrameType::kTopLevel || info->frame_type == blink::mojom::RequestContextFrameType::kNested)
        && info->url_request.HttpHeaderField(blink::WebString::FromUTF8(kAcceptHeader)).IsEmpty()) {
        info->url_request.AddHttpHeaderField(blink::WebString::FromUTF8(kAcceptHeader), blink::WebString::FromUTF8(kDefaultAcceptHeader));
    }

    WebHTTPHeaderVisitorimpl visitor;
    visitor.m_request = request.get();
    info->url_request.VisitHttpHeaderFields(&visitor);

    request->referrer = GURL(base::StringPiece(info->url_request.ReferrerString().Utf8()));
    setNetworkRequestHead(frame, request.get());

    blink::WeakWrapperResourceLoadInfoNotifier* resourceLoadInfoNotifier
        = new blink::WeakWrapperResourceLoadInfoNotifier(mbnet::ResourceLoadInfoNotifierImpl::get());

    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrap
        = std::make_unique<blink::ResourceLoadInfoNotifierWrapper>(resourceLoadInfoNotifier->AsWeakPtr());
    resourceLoadInfoNotifierWrap->NotifyResourceLoadInitiated((int64_t)resourceLoadInfoNotifierWrap.get() /*request_id*/, (GURL)(request->url), request->method,
        GURL(info->url_request.ReferrerString().Utf8()) /*referrer*/, network::mojom::RequestDestination::kDocument, net::RequestPriority::DEFAULT_PRIORITY, false);

    bool isDownload = downloadName.get() && !downloadName->empty();
    scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData = base::MakeRefCounted<mbnet::WebURLRequestExtraDataWrap>();
    extraData->mbwebviewId = mbwebviewId;
    extraData->dataPipeProducerHandle = dataPipeProducerHandle;
    extraData->frameType = info->frame_type;
    extraData->setIsDownload(std::move(downloadName));

    scoped_refptr<const blink::SecurityOrigin> topFrameOrigin;
    mbnet::BodyLoaderClient* client = new mbnet::BodyLoaderClient(isDownload, std::move(info), navigationControl->GetLocalFrameToken(), token);
    loader->LoadAsynchronouslyEx(std::move(request), topFrameOrigin, false, std::move(resourceLoadInfoNotifierWrap), nullptr, extraData, client);
}

void WebLocalFrameClientImpl::BeginNavigation(std::unique_ptr<blink::WebNavigationInfo> info)
{
    WTF::String url = info->url_request.Url().GetString();
    if (url == "about:srcdoc") {
        std::string newUrl = "data:text/plain;charset=utf-8,";
        newUrl += m_srcdoc.Utf8();
        info->url_request.SetUrl(blink::KURL(String::FromUTF8(newUrl)));
    }
    beginNavigation(std::move(info), m_navigationControl, m_mbwebviewId, 0, m_frame, nullptr);
}

void WebLocalFrameClientImpl::beginDownload(
    std::unique_ptr<blink::WebNavigationInfo> info, 
    std::unique_ptr<String> downloadName)
{
    beginNavigation(std::move(info), m_navigationControl, m_mbwebviewId, 0, m_frame, std::move(downloadName));
}

void WebLocalFrameClientImpl::BindToFrame(blink::WebNavigationControl* control)
{
    m_navigationControl = control;
}

void WebLocalFrameClientImpl::WasHidden()
{
    m_hidden = true;
    WebFrameMain::updataHiddenOnRenderProcess(m_frame, m_hidden);
}

void WebLocalFrameClientImpl::WasShown()
{
    m_hidden = false;
    WebFrameMain::updataHiddenOnRenderProcess(m_frame, m_hidden);
}

void WebLocalFrameClientImpl::updateNavigationHistory(blink::WebHistoryCommitType commitType, bool shouldReplaceCurrentEntry)
{
    m_frame->UpdateCurrentHistoryItem();
    //m_frame->SetTargetToCurrentHistoryItem(blink::WebString::FromUTF8(unique_name_helper_.value()));

    blink::WebView* webview = m_frame->View();

    bool isNewNavigation = commitType == blink::kWebStandardCommit;

    // 见FrameLoader::HandleInitialEmptyDocumentReplacementIfNeeded，第一次的标准kWebStandardCommit会被替换成kReplaceCurrentItem
    int32_t backListCount = webview->HistoryBackListCount();
    int32_t forwardListCount = webview->HistoryForwardListCount();
    if (0 == backListCount && -1 == forwardListCount)
        isNewNavigation = true;

    WebFrameMain::updataFrameStateOnRenderProcess(m_frame);

    if (false /*commit_params.should_clear_history_list*/) {
        webview->SetHistoryListFromNavigation(/*history_offset*/ 0, /*history_length*/ 1);
    } else if (isNewNavigation) {
        DCHECK(/*!navigation_state->common_params().should_replace_current_entry ||*/ !shouldReplaceCurrentEntry
            || (webview->HistoryBackListCount() + webview->HistoryForwardListCount() + 1) > 0);
        if (/*!navigation_state->common_params().should_replace_current_entry*/ !shouldReplaceCurrentEntry)
            webview->IncreaseHistoryListFromNavigation();
    } else if (false /*commit_params.nav_entry_id != 0 && !commit_params.intended_as_new_entry*/) {
        //webview->SetHistoryListFromNavigation(navigation_state->commit_params().pending_history_list_offset, {});
    }
}

bool WebLocalFrameClientImpl::isLocalRoot() const
{
    return !(m_frame->Parent() && m_frame->Parent()->IsWebLocalFrame());
}

blink::WebFrameWidget* WebLocalFrameClientImpl::getLocalRootWebFrameWidget()
{
    return m_frame->LocalRoot()->FrameWidget();
}

void WebLocalFrameClientImpl::updateStateForCommit(blink::WebHistoryCommitType commitType, bool shouldReplaceCurrentEntry)
{
    updateNavigationHistory(commitType, shouldReplaceCurrentEntry);

    if (isLocalRoot()) {
        // This forces zoom factor to be propagated to the blink core frame.
        //blink::WebFrameWidget* widget = /*CHECK_DEREF*/(getLocalRootWebFrameWidget());
        //widget->SetZoomLevel(widget->GetZoomLevel());
        //blink::WebView* webview = m_frame->View();
        //webview->SetZoomLevel(webview->ZoomLevel());
        int64_t mbwebviewId = m_mbwebviewId;

        MbWebView* mbwebview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(mbwebviewId);
        if (!mbwebview)
            return;
        mbwebview->propagatedZoomFactor();
    }
}

void WebLocalFrameClientImpl::didCommitNavigationInternal(blink::WebHistoryCommitType commitType, bool shouldReplaceCurrentEntry)
{
    updateStateForCommit(commitType, shouldReplaceCurrentEntry);
}

void WebLocalFrameClientImpl::DidCommitNavigation(blink::WebHistoryCommitType commitType, bool should_reset_browser_interface_broker,
    const blink::ParsedPermissionsPolicy& permissions_policy_header, const blink::DocumentPolicyFeatureState& document_policy_header)
{
    updateStateForCommit(commitType, false);

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return;

    webview->didCommitProvisionalLoad(m_frame, m_frame->GetCurrentHistoryItem(), commitType, false);
}

void WebLocalFrameClientImpl::DidCommitDocumentReplacementNavigation(blink::WebDocumentLoader* loader)
{
    //updateStateForCommit(commitType, true);
}

void WebLocalFrameClientImpl::DidStartLoading()
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return;

    webview->resetState();
}

void WebLocalFrameClientImpl::DidFinishSameDocumentNavigation(
    blink::WebHistoryCommitType commitType, 
    bool is_synchronously_committed, 
    blink::mojom::SameDocumentNavigationType, 
    bool is_client_redirect,
    const std::optional<blink::SameDocNavigationScreenshotDestinationToken>& screenshot_destination)
{
    updateStateForCommit(commitType, false);
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return;

    webview->didCommitProvisionalLoad(m_frame, m_frame->GetCurrentHistoryItem(), commitType, true);
}

void WebLocalFrameClientImpl::FrameDetached(blink::DetachReason detach_reason)
{
    // We need to clean up subframes by removing them from the map and deleting
    // the RenderFrameImpl.  In contrast, the main frame is owned by its
    // containing RenderViewHost (so that they have the same lifetime), so only
    // removal from the map is needed and no deletion.
    //     auto it = g_frame_map.Get().find(frame_);
    //     CHECK(it != g_frame_map.Get().end());
    //     CHECK_EQ(it->second, this);
    //     g_frame_map.Get().erase(it);
    //
    //     // RenderAccessibilityManager keeps a reference to the RenderFrame that owns
    //     // it, so we need to clear the pointer to prevent invalid access after the
    //     // frame gets closed and deleted.
    //     render_accessibility_manager_.reset();

    // |frame_| may not be referenced after this, so clear the pointer since
    // the actual WebLocalFrame may not be deleted immediately and other methods
    // may try to access it.
    m_frame->Close(blink::DetachReason::kFrameDeletion);
    m_frame = nullptr;

    //     if (mhtml_body_loader_client_) {
    //         mhtml_body_loader_client_->Detach();
    //         mhtml_body_loader_client_.reset();
    //     }

    delete this;
    // Object is invalid after this point.
}

scoped_refptr<blink::WebWorkerFetchContext> WebLocalFrameClientImpl::CreateWorkerFetchContextForPlzDedicatedWorker(blink::WebDedicatedWorkerHostFactoryClient*)
{
    return CreateWorkerFetchContext();
}

scoped_refptr<blink::WebWorkerFetchContext> WebLocalFrameClientImpl::CreateWorkerFetchContext()
{
    blink::WebSecurityOrigin orig = m_frame->GetSecurityOrigin();
    return base::AdoptRef(new WebWorkerFetchContextImpl(orig, m_mbwebviewId));

    //     mojo::PendingReceiver<blink::mojom::RendererPreferenceWatcher>
    //         watcher_receiver;
    //     GetWebView()->RegisterRendererPreferenceWatcher(
    //         watcher_receiver.InitWithNewPipeAndPassRemote());
    //
    //     mojo::PendingRemote<blink::mojom::ResourceLoadInfoNotifier>
    //         pending_resource_load_info_notifier;
    //     resource_load_info_notifier_receivers_.Add(
    //         this,
    //         pending_resource_load_info_notifier.InitWithNewPipeAndPassReceiver(),
    //         agent_scheduling_group_.agent_group_scheduler().DefaultTaskRunner());
    //
    //     std::vector<std::string> cors_exempt_header_list =
    //         RenderThreadImpl::current()->cors_exempt_header_list();
    //     blink::WebVector<blink::WebString> web_cors_exempt_header_list(
    //         cors_exempt_header_list.size());
    //     std::transform(cors_exempt_header_list.begin(), cors_exempt_header_list.end(),
    //         web_cors_exempt_header_list.begin(), [](const std::string& h) {
    //             return blink::WebString::FromLatin1(h);
    //         });
    //
    //     // |pending_subresource_loader_updater| and
    //     // |pending_resource_load_info_notifier| are not used for
    //     // non-PlzDedicatedWorker and worklets.
    //     scoped_refptr<blink::WebDedicatedOrSharedWorkerFetchContext>
    //         web_dedicated_or_shared_worker_fetch_context =
    //         blink::WebDedicatedOrSharedWorkerFetchContext::Create(
    //             provider->context(), GetWebView()->GetRendererPreferences(),
    //             std::move(watcher_receiver), GetLoaderFactoryBundle()->Clone(),
    //             GetLoaderFactoryBundle()->Clone(),
    //             /*pending_subresource_loader_updater=*/mojo::NullReceiver(),
    //             web_cors_exempt_header_list,
    //             std::move(pending_resource_load_info_notifier));
    //
    //     web_dedicated_or_shared_worker_fetch_context->set_ancestor_frame_id(
    //         routing_id_);
    //     web_dedicated_or_shared_worker_fetch_context->set_frame_request_blocker(
    //         frame_request_blocker_);
    //     web_dedicated_or_shared_worker_fetch_context->set_site_for_cookies(
    //         frame_->GetDocument().SiteForCookies());
    //     web_dedicated_or_shared_worker_fetch_context->set_top_frame_origin(
    //         frame_->GetDocument().TopFrameOrigin());
    //
    //     for (auto& observer : observers_) {
    //         observer.WillCreateWorkerFetchContext(
    //             web_dedicated_or_shared_worker_fetch_context.get());
    //     }
    //     return web_dedicated_or_shared_worker_fetch_context;
}

static void fillNavigationParamsResponse(blink::WebNavigationParams* params)
{
    blink::KURL kurl(params->url);
    // Empty documents and srcdoc will be handled by DocumentLoader.
    if (blink::DocumentLoader::WillLoadUrlAsEmpty(kurl) || kurl.IsAboutSrcdocURL())
        return;

    //     blink::ResourceResponse response;
    //     scoped_refptr<WTF::SharedBuffer> buffer;
    //     int result;
    //     std::tie(result, response, buffer) = blink::network_utils::ParseDataURL(kurl, params->http_method);
    //     DCHECK(buffer);
    //     DCHECK_EQ(net::OK, result);
    //     params->response = blink::WrappedResourceResponse(response);

    //     blink::WebURLLoaderMockFactory::GetSingletonInstance()->FillNavigationParamsResponse(params);

    // Parse Content Security Policy response headers into the policy container,
    // simulating what the browser does.
    //     WTF::Vector<network::mojom::blink::ContentSecurityPolicyPtr> policies = blink::ParseContentSecurityPolicies(
    //         params->response.HttpHeaderField("Content-Security-Policy"),
    //         blink::network::mojom::blink::ContentSecurityPolicyType::kEnforce,
    //         blink::network::mojom::blink::ContentSecurityPolicySource::kHTTP,
    //         params->response.ResponseUrl());
    //     for (auto& csp : policies) {
    //         params->policy_container->policies.sandbox_flags |= csp->sandbox;
    //         params->policy_container->policies.content_security_policies.emplace_back(ConvertToPublic(std::move(csp)));
    //     }
}

void WebLocalFrameClientImpl::loadHistoryItem(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, bool isSameDocument)
{
    blink::WebLocalFrameImpl* impl = blink::To<blink::WebLocalFrameImpl>(frame);
    blink::HistoryItem* historyItem = item;

    std::unique_ptr<blink::WebNavigationParams> params = std::make_unique<blink::WebNavigationParams>();

    params->response.SetMimeType("text/html"); // TODO: 这个要在上次WebHistoryItem里记录下来
    params->url = historyItem->Url();

    mojo::PendingAssociatedRemote<blink::mojom::blink::PolicyContainerHost> policyContainerRemote;
    mojo::PendingAssociatedReceiver<blink::mojom::blink::PolicyContainerHost> policyContainerReceiver
        = policyContainerRemote.InitWithNewEndpointAndPassReceiver();

    mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>* blinkPolicyContainerHostReceiver
        = new mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>(new PolicyContainerHostImpl());
    blinkPolicyContainerHostReceiver->Bind(std::move(policyContainerReceiver)); // TODO: 内存泄露

    ::network::mojom::URLResponseHeadPtr urlResponseHead = ::network::mojom::URLResponseHead::New();

    MojoHandle dataPipeProducerHandle;
    MojoHandle dataPipeConsumerHandle;
    MojoCreateDataPipeOptions createDataOptions;
    createDataOptions.element_num_bytes = 1;
    createDataOptions.capacity_num_bytes = -1;
    MojoCreateDataPipe(&createDataOptions, &dataPipeProducerHandle, &dataPipeConsumerHandle);

    mojo::DataPipeConsumerHandle dataPipeConsumer(dataPipeConsumerHandle);
    mojo::ScopedDataPipeConsumerHandle responseBody(std::move(dataPipeConsumer));

    urlResponseHead->mime_type = params->response.MimeType().Ascii();
    urlResponseHead->charset = "utf-8"; // m_response->HttpHeaderField(blink::WebString::FromASCII("charset")).Ascii();
    urlResponseHead->content_length = 0; // m_response->ExpectedContentLength();
    urlResponseHead->encoded_data_length = 0; // m_response->ExpectedContentLength();
    urlResponseHead->encoded_body_length = 0; // m_response->ExpectedContentLength();

    mbnet::URLLoaderImpl* urlLoaderImpl = new mbnet::URLLoaderImpl(nullptr); // TODO: 内存泄露

    ::network::mojom::URLLoaderClientEndpointsPtr urlLoaderClientEndpoints = ::network::mojom::URLLoaderClientEndpoints::New(
        urlLoaderImpl->m_urlLoader.BindNewPipeAndPassRemote(), urlLoaderImpl->m_urlLoaderClient.BindNewPipeAndPassReceiver());

    blink::WeakWrapperResourceLoadInfoNotifier* resourceLoadInfoNotifier
        = new blink::WeakWrapperResourceLoadInfoNotifier(mbnet::ResourceLoadInfoNotifierImpl::get());

    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrap
        = std::make_unique<blink::ResourceLoadInfoNotifierWrapper>(resourceLoadInfoNotifier->AsWeakPtr());
    resourceLoadInfoNotifierWrap->NotifyResourceLoadInitiated((int64_t)resourceLoadInfoNotifierWrap.get() /*request_id*/, (GURL)(blink::KURL)(params->url),
        "GET", GURL() /*referrer*/, network::mojom::RequestDestination::kDocument, net::RequestPriority::DEFAULT_PRIORITY, false);

//     const KURL& original_url, network::mojom::URLResponseHeadPtr response_head, mojo::ScopedDataPipeConsumerHandle response_body,
//         network::mojom::URLLoaderClientEndpointsPtr url_loader_client_endpoints, scoped_refptr<base::SingleThreadTaskRunner> task_runner,
//         std::unique_ptr<ResourceLoadInfoNotifierWrapper> resource_load_info_notifier_wrapper

    params->body_loader = std::make_unique<blink::NavigationBodyLoader>(params->url, std::move(urlResponseHead), std::move(responseBody),
        std::move(urlLoaderClientEndpoints), base::SingleThreadTaskRunner::GetCurrentDefault(), std::move(resourceLoadInfoNotifierWrap));

    params->policy_container = std::make_unique<blink::WebPolicyContainer>(
        blink::WebPolicyContainerPolicies(), blink::ToCrossVariantAssociatedMojoType(std::move(policyContainerRemote)));

    params->frame_load_type = blink::WebFrameLoadType::kBackForward;
    params->history_item = item;
    params->navigation_timings.navigation_start = base::TimeTicks::Now();
    params->navigation_timings.fetch_start = base::TimeTicks::Now();
    params->response.SetCurrentRequestUrl(params->url);

    fillNavigationParamsResponse(params.get());

    WebLocalFrameClientImpl* client = (WebLocalFrameClientImpl*)impl->Client();

    // 记得让WebURLLoaderManager::handlReceiveData不要调用BodyLoaderClient::DidStartLoadingResponseBody
    std::unique_ptr<blink::WebNavigationInfo> info = std::make_unique<blink::WebNavigationInfo>();
    info->url_request.SetUrl(params->url);
    info->frame_load_type = blink::WebFrameLoadType::kBackForward;
    beginNavigation(std::move(info), impl, client->m_mbwebviewId, dataPipeProducerHandle, frame, nullptr);

    if (!isSameDocument) {
        impl->CommitNavigation(std::move(params), nullptr /* extra_data */);
    } else {
        impl->CommitSameDocumentNavigation(historyItem->Url(), blink::WebFrameLoadType::kBackForward, item, false /*is_client_redirect*/,
            false /*has_transient_user_activation*/, blink::WebSecurityOrigin(), /*is_browser_initiated*/ true, /*has_ua_visual_transition*/false,
            std::nullopt);
    }
}

void WebLocalFrameClientImpl::loadUrl(blink::WebLocalFrame* frame, const blink::KURL& url)
{
    blink::WebLocalFrameImpl* impl = blink::To<blink::WebLocalFrameImpl>(frame);

    std::unique_ptr<blink::WebNavigationParams> params = std::make_unique<blink::WebNavigationParams>();

    params->response.SetMimeType("text/html"); // TODO: 这个要在上次WebHistoryItem里记录下来
    params->url = url;
#if 1
    mojo::PendingAssociatedRemote<blink::mojom::blink::PolicyContainerHost> policyContainerRemote;
    mojo::PendingAssociatedReceiver<blink::mojom::blink::PolicyContainerHost> policyContainerReceiver
        = policyContainerRemote.InitWithNewEndpointAndPassReceiver();

    mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>* blinkPolicyContainerHostReceiver
        = new mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>(new PolicyContainerHostImpl());
    blinkPolicyContainerHostReceiver->Bind(std::move(policyContainerReceiver)); // TODO: 内存泄露

    ::network::mojom::URLResponseHeadPtr urlResponseHead = ::network::mojom::URLResponseHead::New();

    MojoHandle dataPipeProducerHandle;
    MojoHandle dataPipeConsumerHandle;
    MojoCreateDataPipeOptions createDataOptions;
    createDataOptions.element_num_bytes = 1;
    createDataOptions.capacity_num_bytes = -1;
    MojoCreateDataPipe(&createDataOptions, &dataPipeProducerHandle, &dataPipeConsumerHandle);

    mojo::DataPipeConsumerHandle dataPipeConsumer(dataPipeConsumerHandle);
    mojo::ScopedDataPipeConsumerHandle responseBody(std::move(dataPipeConsumer));

    urlResponseHead->mime_type = params->response.MimeType().Ascii();
    urlResponseHead->charset = "utf-8"; // m_response->HttpHeaderField(blink::WebString::FromASCII("charset")).Ascii();
    urlResponseHead->content_length = 0; // m_response->ExpectedContentLength();
    urlResponseHead->encoded_data_length = 0; // m_response->ExpectedContentLength();
    urlResponseHead->encoded_body_length = 0; // m_response->ExpectedContentLength();

    mbnet::URLLoaderImpl* urlLoaderImpl = new mbnet::URLLoaderImpl(nullptr); // TODO: 内存泄露

    ::network::mojom::URLLoaderClientEndpointsPtr urlLoaderClientEndpoints = ::network::mojom::URLLoaderClientEndpoints::New(
        urlLoaderImpl->m_urlLoader.BindNewPipeAndPassRemote(), urlLoaderImpl->m_urlLoaderClient.BindNewPipeAndPassReceiver());

    blink::WeakWrapperResourceLoadInfoNotifier* resourceLoadInfoNotifier
        = new blink::WeakWrapperResourceLoadInfoNotifier(mbnet::ResourceLoadInfoNotifierImpl::get());

    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrap
        = std::make_unique<blink::ResourceLoadInfoNotifierWrapper>(resourceLoadInfoNotifier->AsWeakPtr());
    resourceLoadInfoNotifierWrap->NotifyResourceLoadInitiated((int64_t)resourceLoadInfoNotifierWrap.get() /*request_id*/, (GURL)(blink::KURL)(params->url),
        "GET", GURL() /*referrer*/, network::mojom::RequestDestination::kDocument, net::RequestPriority::DEFAULT_PRIORITY, false);

    params->body_loader = std::make_unique<blink::NavigationBodyLoader>(params->url, std::move(urlResponseHead), std::move(responseBody),
        std::move(urlLoaderClientEndpoints), base::SingleThreadTaskRunner::GetCurrentDefault(), std::move(resourceLoadInfoNotifierWrap));

    params->policy_container = std::make_unique<blink::WebPolicyContainer>(
        blink::WebPolicyContainerPolicies(), blink::ToCrossVariantAssociatedMojoType(std::move(policyContainerRemote)));
#endif

    params->frame_load_type = blink::WebFrameLoadType::kStandard;
    params->navigation_timings.navigation_start = base::TimeTicks::Now();
    params->navigation_timings.fetch_start = base::TimeTicks::Now();
    params->response.SetCurrentRequestUrl(params->url);

    fillNavigationParamsResponse(params.get());

    WebLocalFrameClientImpl* client = (WebLocalFrameClientImpl*)impl->Client();

    // 记得让WebURLLoaderManager::handlReceiveData不要调用BodyLoaderClient::DidStartLoadingResponseBody
    std::unique_ptr<blink::WebNavigationInfo> info = std::make_unique<blink::WebNavigationInfo>();
    info->url_request.SetUrl(params->url);
    info->frame_load_type = blink::WebFrameLoadType::kBackForward;
    beginNavigation(std::move(info), impl, client->m_mbwebviewId, dataPipeProducerHandle, frame, nullptr);

    impl->CommitNavigation(std::move(params), nullptr /* extra_data */);
}

blink::WebView* WebLocalFrameClientImpl::CreateNewWindow(
    const blink::WebURLRequest& request,
    const blink::WebWindowFeatures& features,
    const blink::WebString& name, 
    blink::WebNavigationPolicy policy, 
    network::mojom::WebSandboxFlags,
    const blink::SessionStorageNamespaceId& sessionStorageNamespaceId, 
    bool& consumedUserGesture, 
    const absl::optional<blink::Impression>&,
    const absl::optional<blink::WebPictureInPictureWindowOptions>& pipOptions, 
    const blink::WebURL& base_url)
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return nullptr;

    std::string url = request.Url().GetString().Utf8();
    const utf8* urlString = url.c_str();
    mbWebView result = NULL_WEBVIEW;
    int64_t mbwebviewId = m_mbwebviewId;

    ThreadCall::callUiThreadSync(FROM_HERE, [&result, mbwebviewId, policy, urlString, features] {
        MbWebView* self = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(mbwebviewId);
        if (!self)
            return;

        mbWebView webviewHandle = (mbWebView)mbwebviewId;
        mbNavigationType type = (mbNavigationType)policy;
        if (self->getClosure().m_CreateViewCallback)
            result = self->getClosure().m_CreateViewCallback(
                webviewHandle, self->getClosure().m_CreateViewParam, type, urlString, (const mbWindowFeatures*)&features);

        return;
    });

    if (!result)
        return nullptr;
    MbWebView* newWebview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(result);
    if (!newWebview)
        return nullptr;
    newWebview->setSessionStorageNamespaceId(sessionStorageNamespaceId);

    MbWebView* self = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!self)
        return nullptr;

    blink::WebView* newBlinkWebview = newWebview->createWebWindowOrViewInBlinkThread(self->getWebView(), m_frame, false, newWebview->isTransparent());

    ThreadCall::wake(); // 让ui线程调用的api同步执行一遍，防止例如set cookit path这种异步设置会导致漏掉网络请求没被设置path的情况

    return newBlinkWebview;
}

void WebLocalFrameClientImpl::DidCreateScriptContext(v8::Local<v8::Context> context, int32_t worldId)
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return;
    webview->onDidCreateScriptContext(context, worldId, m_frame->GetLocalFrameToken());
}

void WebLocalFrameClientImpl::WillReleaseScriptContext(v8::Local<v8::Context> context, int32_t worldId)
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return;
    webview->onWillReleaseScriptContext(context, worldId, m_frame->GetLocalFrameToken());
}

void WebLocalFrameClientImpl::onLoadingSucceeded()
{
    if (m_onLoadingSucceededCount >= 0 && m_onLoadingSucceededCount < 5) {
        m_onLoadingSucceededCount++;
        return;
    }
    if (-1 == m_onLoadingSucceededCount)
        return;
    m_onLoadingSucceededCount = -1;

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!m_isMainFrame || !webview)
        return;

    const blink::LocalFrameToken& token = m_frame->GetLocalFrameToken();
    blink::WebDocument doc = m_frame->GetDocument();
    blink::KURL url = doc.Url();
    const String& urlStr = url.GetString();

    void* param = webview->getClosure().m_LoadingFinishParam;
    mbLoadingFinishCallback callback = webview->getClosure().m_LoadingFinishCallback;
    if (callback) {
        callback((mbWebView)m_mbwebviewId, param, (mbWebFrameHandle)(blink::LocalFrameToken::Hasher()(token)), urlStr.Utf8().c_str(), MB_LOADING_SUCCEEDED, "");
    }
}

void WebLocalFrameClientImpl::DidFinishLoad()
{
    OutputDebugStringA(m_isMainFrame ? "WebLocalFrameClientImpl::DidFinishLoad main\n" : "WebLocalFrameClientImpl::DidFinishLoad not main\n");
}

void WebLocalFrameClientImpl::DraggableRegionsChanged()
{
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview)
        return;

    blink::WebFrame* frame = webview->getMainFrame();
    if (!frame)
        return;
    blink::WebDocument doc = frame->ToWebLocalFrame()->GetDocument();
    blink::WebVector<blink::WebDraggableRegion> regions = doc.DraggableRegions();
    webview->draggableRegionsChanged(regions);
}

// 有可能在web worker线程，或者nodejs worker
mbWebFrameHandle v8ContextToMbWebFrameHandle(v8::Local<v8::Context> context)
{
    v8::Isolate* isolate = context->GetIsolate();
    if (!isolate->GetData(gin::kEmbedderBlink))
        return nullptr;
    blink::WebLocalFrame* frame = blink::WebLocalFrame::FrameForContext(context);
    if (!frame)
        return nullptr;
    const blink::LocalFrameToken& token = frame->GetLocalFrameToken();
    mbWebFrameHandle frameId = (mbWebFrameHandle)(blink::LocalFrameToken::Hasher()(token));
    return frameId;
}

bool s_needPrintCallstack = false;
void printCallstack();

void WebLocalFrameClientImpl::DidAddMessageToConsole(
    const blink::WebConsoleMessage& message, const blink::WebString& source_name, unsigned source_line, const blink::WebString& stack_trace)
{
    const blink::LocalFrameToken& token = m_frame->GetLocalFrameToken();
    mbWebFrameHandle frameId = (mbWebFrameHandle)(blink::LocalFrameToken::Hasher()(token));

    char temp[256] = { 0 };
    sprintf(temp, "Console(%p):[", frameId);

    std::string text = temp; // "Console:[";
    text += message.text.Utf8();
    text += "][";
    text += source_name.Utf8();
    text += "][";

    sprintf(temp, "%d", source_line);
    text += temp;
    text += "]\n";

#ifndef OS_WIN
    OutputDebugStringA(text.c_str());
#else
    std::u16string textW = base::UTF8ToUTF16(text);
    OutputDebugStringW((const WCHAR*)textW.c_str());
#endif

    if (s_needPrintCallstack)
        content::printCallstack();

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(m_mbwebviewId);
    if (!webview || !(webview->getClosure().m_ConsoleCallback))
        return;

    webview->getClosure().m_ConsoleCallback(m_mbwebviewId, webview->getClosure().m_ConsoleParam, mbLevelLog, message.text.Utf8().c_str(),
        source_name.Utf8().c_str(), source_line, stack_trace.Utf8().c_str());
}

class NonAssociatedLocalFrameHostImpl : public ::blink::mojom::blink::NonAssociatedLocalFrameHost {
public:
    NonAssociatedLocalFrameHostImpl()
    {

    }
    void MaybeStartOutermostMainFrameNavigation(const WTF::Vector<::blink::KURL>& urls) override
    {

    }
};

class AnchorElementInteractionHostImpl : public ::blink::mojom::blink::AnchorElementInteractionHost {
    void OnPointerDown(const ::blink::KURL& target) override
    {
        OutputDebugStringA("AnchorElementInteractionHostImpl::OnPointerDown not impl\n");
    }

    void OnPointerHover(const ::blink::KURL& target, blink::mojom::blink::AnchorElementPointerDataPtr mouseData) override
    {
        OutputDebugStringA("AnchorElementInteractionHostImpl::OnPointerHover not impl\n");
    }

    void OnViewportHeuristicTriggered(const ::blink::KURL& target) override
    {
        OutputDebugStringA("AnchorElementInteractionHostImpl::OnViewportHeuristicTriggered not impl\n");
    }
};

class AnchorElementMetricsHostImpl : public ::blink::mojom::blink::AnchorElementMetricsHost {
    ~AnchorElementMetricsHostImpl() override = default;

    void ReportAnchorElementClick(::blink::mojom::blink::AnchorElementClickPtr clicked) override {}

    void ReportNewAnchorElements(WTF::Vector<::blink::mojom::blink::AnchorElementMetricsPtr> metrics, const WTF::Vector<uint32_t>& removed_elements) override {}

    void ReportAnchorElementsEnteredViewport(WTF::Vector<::blink::mojom::blink::AnchorElementEnteredViewportPtr> elements) override {}

    void ReportAnchorElementsLeftViewport(WTF::Vector<::blink::mojom::blink::AnchorElementLeftViewportPtr> elements) override {}

    void ReportAnchorElementsPositionUpdate(WTF::Vector<::blink::mojom::blink::AnchorElementPositionUpdatePtr> elements) override {}

    void ReportAnchorElementPointerOver(::blink::mojom::blink::AnchorElementPointerOverPtr pointer_over_event) override {}

    void ReportAnchorElementPointerOut(::blink::mojom::blink::AnchorElementPointerOutPtr hover_event) override {}

    void ReportAnchorElementPointerDown(::blink::mojom::blink::AnchorElementPointerDownPtr pointer_down_event) override {}

    void ReportAnchorElementPointerDataOnHoverTimerFired(::blink::mojom::blink::AnchorElementPointerDataOnHoverTimerFiredPtr pointer_data) override {}

    void ProcessPointerEventUsingMLModel(::blink::mojom::blink::AnchorElementPointerEventForMLModelPtr pointer_event) override {}

    //using ShouldSkipUpdateDelaysCallback = base::OnceCallback<void(bool)>;
    void ShouldSkipUpdateDelays(::blink::mojom::blink::AnchorElementMetricsHost::ShouldSkipUpdateDelaysCallback callback) override
    {
        base::SequencedTaskRunner::GetCurrentDefault()->PostTask(MB_FROM_HERE, base::BindOnce([](
            ::blink::mojom::blink::AnchorElementMetricsHost::ShouldSkipUpdateDelaysCallback cb) {
            std::move(cb).Run(true);
        }, std::move(callback)));
    }
};

class SharedWorkerConnectorImpl : public ::blink::mojom::blink::SharedWorkerConnector {
    void Connect(::blink::mojom::blink::SharedWorkerInfoPtr info, ::mojo::PendingRemote<::blink::mojom::blink::SharedWorkerClient> client,
        ::blink::mojom::blink::SharedWorkerCreationContextType creation_context_type, ::blink::MessagePortDescriptor message_port,
        ::mojo::PendingRemote<::blink::mojom::blink::BlobURLToken> blob_url_token, int64_t client_ukm_source_id) override
    {
        OutputDebugStringA("SharedWorkerConnectorImpl::Connect\n");
    }
};

void WebLocalFrameClientImpl::GetInterface(::mojo::GenericPendingReceiver receiver)
{
    std::string output("WebLocalFrameClientImpl::GetInterface: ");
    std::string name = receiver.interface_name().has_value() ? receiver.interface_name().value() : "no-name";
    output += name;
    output += "\n";
    OutputDebugStringA(output.c_str());

    if ("blink.mojom.BackForwardCacheControllerHost" == name) {
        //             mojo::PendingAssociatedReceiver<::blink::mojom::blink::BackForwardCacheControllerHost> pendingReceiver(receiver.PassHandle());
        //             m_backForwardCacheControllerHostReceiver.Bind(std::move(pendingReceiver));
        DebugBreak();
    } else if ("blink.mojom.LocalFrameHost" == name) {
        //             mojo::PendingAssociatedReceiver<::blink::mojom::blink::LocalFrameHost> pendingReceiver(receiver.PassHandle());
        //             m_localFrameHostReceiver.Bind(std::move(pendingReceiver));
        DebugBreak();
    } else if ("blink.mojom.CodeCacheHost" == name) {

    } else if ("blink.mojom.ContentSecurityNotifier" == name) {
        //mojo::PendingReceiver<::blink::mojom::blink::ContentSecurityNotifier> pendingReceiver(receiver.PassPipe());
        //m_contentSecurityNotifierImplReceiver.Bind(std::move(pendingReceiver));
        createAndBindInterface<::blink::mojom::blink::ContentSecurityNotifier, ContentSecurityNotifierImpl>(receiver.PassPipe(), m_mbwebviewId);
    } else if ("blink.mojom.ReportingServiceProxy" == name) {
        //mojo::PendingReceiver<::blink::mojom::blink::ReportingServiceProxy> pendingReceiver(receiver.PassPipe());
        //m_reportingServiceProxyImplReceiver.Bind(std::move(pendingReceiver));
        createAndBindInterface<::blink::mojom::blink::ReportingServiceProxy, ReportingServiceProxyImpl>(receiver.PassPipe(), m_mbwebviewId);
    } else if ("network.mojom.RestrictedCookieManager" == name) {
        //mojo::PendingReceiver<::network::mojom::RestrictedCookieManager> pendingReceiver(receiver.PassPipe());
        //m_restrictedCookieImplManagerReceiver.Bind(std::move(pendingReceiver));
        createAndBindInterface<::network::mojom::blink::RestrictedCookieManager, RestrictedCookieManagerImpl>(receiver.PassPipe(), m_mbwebviewId);
    } else if ("blink.mojom.FileChooser" == name) {
        //         mojo::PendingReceiver<::blink::mojom::blink::FileChooser> pendingReceiver(receiver.PassPipe());
        //         mojo::Receiver<::blink::mojom::blink::FileChooser>* fileChooserImplReceiver = new mojo::Receiver<::blink::mojom::blink::FileChooser>(new FileChooserImpl(m_mbwebviewId));
        //         fileChooserImplReceiver->Bind(std::move(pendingReceiver));
        //         fileChooserImplReceiver->set_disconnect_handler(base::BindOnce([](mojo::Receiver<::blink::mojom::blink::FileChooser>* fileChooserImplReceiver) {
        //             delete fileChooserImplReceiver->internal_state()->impl();
        //             delete fileChooserImplReceiver;
        //         }, base::Unretained(fileChooserImplReceiver)));
        createAndBindInterface<::blink::mojom::blink::FileChooser, FileChooserImpl>(receiver.PassPipe(), m_mbwebviewId);

    } else if ("blink.mojom.QuotaManagerHost" == name) {
        createAndBindInterface<::blink::mojom::blink::QuotaManagerHost, QuotaManagerHostImpl>(receiver.PassPipe());
        //mojo::MakeSelfOwnedReceiver
    } else if ("blink.mojom.ClipboardHost" == name) {
        createAndBindInterface<::blink::mojom::blink::ClipboardHost, ClipboardHostImpl>(receiver.PassPipe());
    } else if ("blink.mojom.NoStatePrefetchProcessor" == name) {
        createAndBindInterface<::blink::mojom::blink::NoStatePrefetchProcessor, NoStatePrefetchProcessorImpl>(receiver.PassPipe());
    } else if ("blink.mojom.WebSocketConnector" == name) {
        //createAndBindInterface<::blink::mojom::blink::WebSocketConnector, NoStatePrefetchProcessorImpl>(receiver.PassPipe());
        DebugBreak();
    } else if ("blink.mojom.blink.NonAssociatedLocalFrameHost" == name) {
        createAndBindInterface<::blink::mojom::blink::NonAssociatedLocalFrameHost, NonAssociatedLocalFrameHostImpl>(receiver.PassPipe());
    } else if ("blink.mojom.AnchorElementInteractionHost" == name) {
        createAndBindInterface<::blink::mojom::blink::AnchorElementInteractionHost, AnchorElementInteractionHostImpl>(receiver.PassPipe());
    } else if ("blink.mojom.blink.DevicePostureProvider" == name) {
        createAndBindInterface<::blink::mojom::blink::DevicePostureProvider, DevicePostureProviderImpl>(receiver.PassPipe());
    } else if ("blink.mojom.AnchorElementMetricsHost" == name) {
        createAndBindInterface<::blink::mojom::blink::AnchorElementMetricsHost, AnchorElementMetricsHostImpl>(receiver.PassPipe());
    } else if ("blink.mojom.SpeculationHost" == name) {
        createAndBindInterface<::blink::mojom::blink::SpeculationHost, SpeculationHostImpl>(receiver.PassPipe());
    } else if ("blink.mojom.PermissionService" == name) {
        createAndBindInterface<::blink::mojom::blink::PermissionService, PermissionServiceImpl>(receiver.PassPipe());
    } else if ("blink.mojom.SharedWorkerConnector" == name) {
        createAndBindInterface<::blink::mojom::blink::SharedWorkerConnector, SharedWorkerConnectorImpl>(receiver.PassPipe());
    } else
        DebugBreak();
}

}