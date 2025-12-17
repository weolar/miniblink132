
#ifndef content_renderer_WebLocalFrameClientImpl_h
#define content_renderer_WebLocalFrameClientImpl_h

#include "mbnet/LoaderFactoryImpl.h"
#include "third_party/blink/public/mojom/associated_interfaces/associated_interfaces.mojom.h"
#include "third_party/blink/public/mojom/browser_interface_broker.mojom.h"
#include "third_party/blink/public/mojom/loader/content_security_notifier.mojom-blink.h"
#include "third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"
#include "third_party/blink/public/mojom/choosers/file_chooser.mojom-blink.h"
#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/public/platform/browser_interface_broker_proxy.h"
#include "third_party/blink/public/platform/web_policy_container.h"
#include "third_party/blink/public/common/associated_interfaces/associated_interface_provider.h"
#include "third_party/blink/public/mojom/frame/policy_container.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "services/network/public/mojom/restricted_cookie_manager.mojom.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"

namespace blink {
class WebFrameWidget;
}

namespace network {
class SharedURLLoaderFactory;
}

namespace content {

class PolicyContainerHostImpl;
class AssociatedInterfaceProviderImpl;
class BlinkInterfaceRegistryImpl;

intptr_t getFrameIdByWebLocalFrame(blink::WebLocalFrame* frame);
intptr_t getParentFrameId(intptr_t frame);

class WebLocalFrameClientImpl : public blink::WebLocalFrameClient, public blink::mojom::BrowserInterfaceBroker {
public:
    WebLocalFrameClientImpl(int64_t mbwebviewId);
    ~WebLocalFrameClientImpl();

    void DidCreateDocumentLoader(blink::WebDocumentLoader*) override;
    std::optional<blink::WebURL> WillSendRequest(
        //blink::WebURLRequest& req, blink::WebLocalFrameClient::ForRedirect
        const blink::WebURL& target, const blink::WebSecurityOrigin& security_origin, const net::SiteForCookies& site_for_cookies,
        blink::WebLocalFrameClient::ForRedirect for_redirect, const blink::WebURL& upstream_url
    ) override;

    void FinalizeRequest(blink::WebURLRequest& reg) override;

    void BeginNavigation(std::unique_ptr<blink::WebNavigationInfo> info) override;
    ::blink::AssociatedInterfaceProvider* GetRemoteNavigationAssociatedInterfaces() override;
    void DidAddMessageToConsole(
        const blink::WebConsoleMessage& message, const blink::WebString& source_name, unsigned source_line, const blink::WebString& stack_trace) override;

    //     std::unique_ptr<blink::WebURLLoaderFactory> CreateURLLoaderFactory() override
    //     {
    //         return std::make_unique<mbnet::LoaderFactoryImpl>();
    //     }

    blink::WebLocalFrame* CreateChildFrame(
        blink::mojom::TreeScopeType scope, 
        const blink::WebString& name, 
        const blink::WebString& fallback_name, 
        const blink::FramePolicy&,
        const blink::WebFrameOwnerProperties&, 
        blink::FrameOwnerElementType, 
        blink::WebPolicyContainerBindParams policy_container_bind_params, 
        ukm::SourceId document_ukm_source_id,
        blink::WebLocalFrameClient::FinishChildFrameCreationFn complete_creation
    ) override;

    // blink::mojom::BrowserInterfaceBroker
    void GetInterface(::mojo::GenericPendingReceiver receiver) override;

    //--- blink::WebLocalFrameClient
//     ::blink::BrowserInterfaceBrokerProxy* GetBrowserInterfaceBroker() /*override*/
//     {
//         return &m_browserInterfaceBrokerProxy;
//     }

    mojo::Receiver<blink::mojom::BrowserInterfaceBroker>& getBrowserInterfaceBrokerProxyReceiver()
    {
        return m_browserInterfaceBrokerProxyReceiver;
    }

    void BindToFrame(blink::WebNavigationControl* control) override;

    void DidCommitNavigation(blink::WebHistoryCommitType commit_type, bool should_reset_browser_interface_broker,
        const blink::ParsedPermissionsPolicy& permissions_policy_header, const blink::DocumentPolicyFeatureState& document_policy_header) override;

    void DidCommitDocumentReplacementNavigation(blink::WebDocumentLoader*) override;

    void DidFinishSameDocumentNavigation(
        blink::WebHistoryCommitType type, 
        bool is_synchronously_committed, 
        blink::mojom::SameDocumentNavigationType, 
        bool is_client_redirect,
        const std::optional<blink::SameDocNavigationScreenshotDestinationToken>& screenshot_destination
    ) override;

    void DidStartLoading() override;

    blink::WebView* CreateNewWindow(
        const blink::WebURLRequest& request, 
        const blink::WebWindowFeatures& features, 
        const blink::WebString& name,
        blink::WebNavigationPolicy policy, 
        network::mojom::WebSandboxFlags, 
        const blink::SessionStorageNamespaceId& session_storage_namespace_id,
        bool& consumed_user_gesture, 
        const absl::optional<blink::Impression>&,
        const absl::optional<blink::WebPictureInPictureWindowOptions>& pip_options,
        const blink::WebURL& base_url) override;

    void FrameDetached(blink::DetachReason detach_reason) override;

    scoped_refptr<blink::WebWorkerFetchContext> CreateWorkerFetchContextForPlzDedicatedWorker(blink::WebDedicatedWorkerHostFactoryClient*) override;
    scoped_refptr<blink::WebWorkerFetchContext> CreateWorkerFetchContext() override;

    void DidCreateScriptContext(v8::Local<v8::Context>, int32_t worldId) override;
    void WillReleaseScriptContext(v8::Local<v8::Context>, int32_t world_id) override;

    void DidFinishLoad() override;
    void onLoadingSucceeded();

    void WasHidden() override;
    void WasShown() override;

    scoped_refptr<network::SharedURLLoaderFactory> GetURLLoaderFactory() override;

    //Geometry notifications
    void DraggableRegionsChanged() /*override*/;

    //---
    void setFrame(blink::WebLocalFrame* frame)
    {
        m_frame = frame;
    }
    blink::WebLocalFrame* getFrame() const
    {
        return m_frame;
    }
    intptr_t getFrameId() const
    {
        return getFrameIdByWebLocalFrame(m_frame);
    }
    int64_t getMbwebviewId() const
    {
        return m_mbwebviewId;
    }
    blink::WebNavigationControl* getNavigationControl() const
    {
        return m_navigationControl;
    }

    void beginDownload(std::unique_ptr<blink::WebNavigationInfo> info, std::unique_ptr<String> downloadName);

    void updateStateForCommit(blink::WebHistoryCommitType commitType, bool should_ReplaceCurrentEntry);
    void didCommitNavigationInternal(blink::WebHistoryCommitType commitType, bool should_ReplaceCurrentEntry);
    void updateNavigationHistory(blink::WebHistoryCommitType commitType, bool should_ReplaceCurrentEntry);

    static void loadHistoryItem(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, bool isSameDocument);
    static void loadUrl(blink::WebLocalFrame* frame, const blink::KURL& url);

    bool isLocalRoot() const;
    blink::WebFrameWidget* getLocalRootWebFrameWidget();

    mojo::Remote<blink::mojom::blink::LocalFrame>& getLocalFrameRemote()
    {
        return m_localFrameRemote;
    }

    int64_t m_mbwebviewId = 0;

    bool m_isMainFrame = false;

    int m_onLoadingSucceededCount = 0;

    blink::WebLocalFrame* m_frame = nullptr;
    bool m_hidden = false;

    WTF::String m_srcdoc;

    AssociatedInterfaceProviderImpl* m_associatedInterfaceProviderImpl = nullptr;
    mojo::AssociatedReceiver<::blink::mojom::AssociatedInterfaceProvider> m_interfaceProviderReceiver;
    std::unique_ptr<::blink::AssociatedInterfaceProvider> m_associatedInterfaceProvider;

    std::unique_ptr<PolicyContainerHostImpl> m_blinkPolicyContainerHost;
    mojo::AssociatedReceiver<blink::mojom::blink::PolicyContainerHost>* m_blinkPolicyContainerHostReceiver = nullptr;

    blink::WebNavigationControl* m_navigationControl = nullptr;

    friend class BlinkInterfaceRegistryImpl;
    BlinkInterfaceRegistryImpl* m_blinkInterfaceRegistryImpl = nullptr;

    mojo::Remote<blink::mojom::blink::LocalFrame> m_localFrameRemote;

    //blink::BrowserInterfaceBrokerProxy m_browserInterfaceBrokerProxy;
    mojo::Receiver<blink::mojom::BrowserInterfaceBroker> m_browserInterfaceBrokerProxyReceiver { this };
};

}

#endif // content_renderer_WebLocalFrameClientImpl_h