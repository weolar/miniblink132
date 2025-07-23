// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   /instrumenting_probes_inl.h.tmpl
// and input files:
//   core_probes.pidl

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CORE_PROBES_INL_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CORE_PROBES_INL_H_

#include "third_party/blink/renderer/platform/heap/collection_support/heap_vector.h"
#include "base/containers/span_or_size.h"
#include "third_party/blink/public/mojom/loader/same_document_navigation_type.mojom-shared.h"
#include "third_party/blink/public/web/web_media_inspector.h"
#include "third_party/blink/renderer/core/animation/animation.h"
#include "third_party/blink/renderer/core/core_probe_sink.h"
#include "third_party/blink/renderer/core/dom/character_data.h"
#include "third_party/blink/renderer/core/dom/pseudo_element.h"
#include "third_party/blink/renderer/core/frame/csp/content_security_policy.h"
#include "third_party/blink/renderer/core/html/html_slot_element.h"
#include "third_party/blink/renderer/core/loader/frame_loader_types.h"
#include "third_party/blink/renderer/core/page/chrome_client.h"
#include "third_party/blink/renderer/core/probe/core_probes.h"
#include "third_party/blink/renderer/core/speculation_rules/speculation_rule_set.h"

namespace blink {

class ClassicScript;
class ConsoleMessage;
class FontCustomPlatformData;
class FontFace;
class HTMLDocumentParser;
class HTMLInputElement;
class JSBasedEventListener;
class PerformanceEntry;
class Script;
class ScriptState;
class SpeculationCandidate;
class XMLHttpRequest;
using PropertyName = std::variant<const char*, String>;

namespace probe {

CORE_EXPORT void DidClearDocumentOfWindowObjectImpl(LocalFrame*);
inline void DidClearDocumentOfWindowObject(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorAnimationAgent))
        return;

    DidClearDocumentOfWindowObjectImpl(param_local_frame);
}

CORE_EXPORT void DidCreateMainWorldContextImpl(LocalFrame*);
inline void DidCreateMainWorldContext(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    DidCreateMainWorldContextImpl(param_local_frame);
}

CORE_EXPORT void WillInsertDOMNodeImpl(Node*);
inline void WillInsertDOMNode(Node* parent)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMDebuggerAgent))
        return;

    WillInsertDOMNodeImpl(parent);
}

CORE_EXPORT void DidInsertDOMNodeImpl(Node*);
inline void DidInsertDOMNode(Node* param_node)
{
    if (!CoreProbeSink::HasAgentsGlobal(
            CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorDOMDebuggerAgent | CoreProbeSink::kInspectorDOMSnapshotAgent))
        return;

    DidInsertDOMNodeImpl(param_node);
}

CORE_EXPORT void WillRemoveDOMNodeImpl(Node*);
inline void WillRemoveDOMNode(Node* param_node)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    WillRemoveDOMNodeImpl(param_node);
}

CORE_EXPORT void WillModifyDOMAttrImpl(Element*, const AtomicString&, const AtomicString&);
inline void WillModifyDOMAttr(Element* param_element, const AtomicString& old_value, const AtomicString& new_value)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorDOMDebuggerAgent))
        return;

    WillModifyDOMAttrImpl(param_element, old_value, new_value);
}

CORE_EXPORT void DidModifyDOMAttrImpl(Element*, const QualifiedName&, const AtomicString&);
inline void DidModifyDOMAttr(Element* param_element, const QualifiedName& name, const AtomicString& value)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    DidModifyDOMAttrImpl(param_element, name, value);
}

CORE_EXPORT void DidRemoveDOMAttrImpl(Element*, const QualifiedName&);
inline void DidRemoveDOMAttr(Element* param_element, const QualifiedName& name)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    DidRemoveDOMAttrImpl(param_element, name);
}

CORE_EXPORT void WillChangeStyleElementImpl(Element*);
inline void WillChangeStyleElement(Element* param_element)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    WillChangeStyleElementImpl(param_element);
}

CORE_EXPORT void CharacterDataModifiedImpl(CharacterData*);
inline void CharacterDataModified(CharacterData* param_character_data)
{
    if (!CoreProbeSink::HasAgentsGlobal(
            CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorDOMDebuggerAgent | CoreProbeSink::kInspectorDOMSnapshotAgent))
        return;

    CharacterDataModifiedImpl(param_character_data);
}

CORE_EXPORT void DidInvalidateStyleAttrImpl(Node*);
inline void DidInvalidateStyleAttr(Node* param_node)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorDOMDebuggerAgent))
        return;

    DidInvalidateStyleAttrImpl(param_node);
}

CORE_EXPORT void DidPerformSlotDistributionImpl(HTMLSlotElement*);
inline void DidPerformSlotDistribution(HTMLSlotElement* param_html_slot_element)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    DidPerformSlotDistributionImpl(param_html_slot_element);
}

CORE_EXPORT void DocumentDetachedImpl(Document*);
inline void DocumentDetached(Document* param_document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    DocumentDetachedImpl(param_document);
}

CORE_EXPORT void ActiveStyleSheetsUpdatedImpl(Document*);
inline void ActiveStyleSheetsUpdated(Document* param_document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    ActiveStyleSheetsUpdatedImpl(param_document);
}

CORE_EXPORT void FontsUpdatedImpl(ExecutionContext*, const FontFace*, const String&, const FontCustomPlatformData*);
inline void FontsUpdated(
    ExecutionContext* param_execution_context, const FontFace* face, const String& src, const FontCustomPlatformData* font_custom_platform_data)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    FontsUpdatedImpl(param_execution_context, face, src, font_custom_platform_data);
}

CORE_EXPORT void MediaQueryResultChangedImpl(Document*);
inline void MediaQueryResultChanged(Document* param_document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    MediaQueryResultChangedImpl(param_document);
}

CORE_EXPORT void DidPushShadowRootImpl(Element*, ShadowRoot*);
inline void DidPushShadowRoot(Element* host, ShadowRoot* param_shadow_root)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    DidPushShadowRootImpl(host, param_shadow_root);
}

CORE_EXPORT void WillPopShadowRootImpl(Element*, ShadowRoot*);
inline void WillPopShadowRoot(Element* host, ShadowRoot* param_shadow_root)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    WillPopShadowRootImpl(host, param_shadow_root);
}

CORE_EXPORT void WillSendXMLHttpOrFetchNetworkRequestImpl(ExecutionContext*, const String&);
inline void WillSendXMLHttpOrFetchNetworkRequest(ExecutionContext* param_execution_context, const String& url)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMDebuggerAgent))
        return;

    WillSendXMLHttpOrFetchNetworkRequestImpl(param_execution_context, url);
}

CORE_EXPORT void DidCreateCanvasContextImpl(Document*);
inline void DidCreateCanvasContext(Document* param_document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidCreateCanvasContextImpl(param_document);
}

CORE_EXPORT void DidCreateOffscreenCanvasContextImpl(OffscreenCanvas*);
inline void DidCreateOffscreenCanvasContext(OffscreenCanvas* param_offscreen_canvas)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidCreateOffscreenCanvasContextImpl(param_offscreen_canvas);
}

CORE_EXPORT void DidFireWebGLErrorImpl(Element*, const String&);
inline void DidFireWebGLError(Element* param_element, const String& error_name)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidFireWebGLErrorImpl(param_element, error_name);
}

CORE_EXPORT void DidFireWebGLWarningImpl(Element*);
inline void DidFireWebGLWarning(Element* param_element)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidFireWebGLWarningImpl(param_element);
}

CORE_EXPORT void DidFireWebGLErrorOrWarningImpl(Element*, const String&);
inline void DidFireWebGLErrorOrWarning(Element* param_element, const String& message)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidFireWebGLErrorOrWarningImpl(param_element, message);
}

CORE_EXPORT void DidResizeMainFrameImpl(LocalFrame*);
inline void DidResizeMainFrame(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    DidResizeMainFrameImpl(param_local_frame);
}

CORE_EXPORT void ApplyAcceptLanguageOverrideImpl(ExecutionContext*, String*);
inline void ApplyAcceptLanguageOverride(ExecutionContext* param_execution_context, String* accept_language)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    ApplyAcceptLanguageOverrideImpl(param_execution_context, accept_language);
}

CORE_EXPORT void ApplyAcceptLanguageOverrideImpl(CoreProbeSink*, String*);
inline void ApplyAcceptLanguageOverride(CoreProbeSink* param_core_probe_sink, String* accept_language)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    ApplyAcceptLanguageOverrideImpl(param_core_probe_sink, accept_language);
}

CORE_EXPORT void ApplyHardwareConcurrencyOverrideImpl(CoreProbeSink*, unsigned int&);
inline void ApplyHardwareConcurrencyOverride(CoreProbeSink* param_core_probe_sink, unsigned int& hardware_concurrency)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    ApplyHardwareConcurrencyOverrideImpl(param_core_probe_sink, hardware_concurrency);
}

CORE_EXPORT void ApplyUserAgentOverrideImpl(CoreProbeSink*, String*);
inline void ApplyUserAgentOverride(CoreProbeSink* param_core_probe_sink, String* user_agent)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    ApplyUserAgentOverrideImpl(param_core_probe_sink, user_agent);
}

CORE_EXPORT void ApplyUserAgentMetadataOverrideImpl(CoreProbeSink*, std::optional<blink::UserAgentMetadata>*);
inline void ApplyUserAgentMetadataOverride(CoreProbeSink* param_core_probe_sink, std::optional<blink::UserAgentMetadata>* ua_metadata_override)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    ApplyUserAgentMetadataOverrideImpl(param_core_probe_sink, ua_metadata_override);
}

CORE_EXPORT void DidBlockRequestImpl(
    CoreProbeSink*, const ResourceRequest&, DocumentLoader*, const KURL&, const ResourceLoaderOptions&, ResourceRequestBlockedReason, ResourceType);
inline void DidBlockRequest(CoreProbeSink* param_core_probe_sink, const ResourceRequest& param_resource_request, DocumentLoader* param_document_loader,
    const KURL& fetch_context_url, const ResourceLoaderOptions& param_resource_loader_options,
    ResourceRequestBlockedReason param_resource_request_blocked_reason, ResourceType param_resource_type)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidBlockRequestImpl(param_core_probe_sink, param_resource_request, param_document_loader, fetch_context_url, param_resource_loader_options,
        param_resource_request_blocked_reason, param_resource_type);
}

CORE_EXPORT void DidChangeResourcePriorityImpl(LocalFrame*, DocumentLoader*, uint64_t, ResourceLoadPriority);
inline void DidChangeResourcePriority(
    LocalFrame* param_local_frame, DocumentLoader* param_document_loader, uint64_t identifier, ResourceLoadPriority load_priority)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidChangeResourcePriorityImpl(param_local_frame, param_document_loader, identifier, load_priority);
}

CORE_EXPORT void PrepareRequestImpl(CoreProbeSink*, DocumentLoader*, ResourceRequest&, ResourceLoaderOptions&, ResourceType);
inline void PrepareRequest(CoreProbeSink* param_core_probe_sink, DocumentLoader* param_document_loader, ResourceRequest& param_resource_request,
    ResourceLoaderOptions& param_resource_loader_options, ResourceType param_resource_type)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent | CoreProbeSink::kInspectorNetworkAgent))
        return;

    PrepareRequestImpl(param_core_probe_sink, param_document_loader, param_resource_request, param_resource_loader_options, param_resource_type);
}

CORE_EXPORT void WillSendRequestImpl(ExecutionContext*, DocumentLoader*, const KURL&, const ResourceRequest&, const ResourceResponse&,
    const ResourceLoaderOptions&, ResourceType, RenderBlockingBehavior, base::TimeTicks);
inline void WillSendRequest(ExecutionContext* param_execution_context, DocumentLoader* param_document_loader, const KURL& fetch_context_url,
    const ResourceRequest& param_resource_request, const ResourceResponse& redirect_response, const ResourceLoaderOptions& param_resource_loader_options,
    ResourceType param_resource_type, RenderBlockingBehavior param_render_blocking_behavior, base::TimeTicks timestamp)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    WillSendRequestImpl(param_execution_context, param_document_loader, fetch_context_url, param_resource_request, redirect_response,
        param_resource_loader_options, param_resource_type, param_render_blocking_behavior, timestamp);
}

CORE_EXPORT void WillSendNavigationRequestImpl(CoreProbeSink*, uint64_t, DocumentLoader*, const KURL&, const AtomicString&, EncodedFormData*);
inline void WillSendNavigationRequest(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, const KURL& param_kurl,
    const AtomicString& http_method, EncodedFormData* param_encoded_form_data)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    WillSendNavigationRequestImpl(param_core_probe_sink, identifier, param_document_loader, param_kurl, http_method, param_encoded_form_data);
}

CORE_EXPORT void MarkResourceAsCachedImpl(LocalFrame*, DocumentLoader*, uint64_t);
inline void MarkResourceAsCached(LocalFrame* param_local_frame, DocumentLoader* param_document_loader, uint64_t identifier)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    MarkResourceAsCachedImpl(param_local_frame, param_document_loader, identifier);
}

CORE_EXPORT void DidReceiveResourceResponseImpl(CoreProbeSink*, uint64_t, DocumentLoader*, const ResourceResponse&, const Resource*);
inline void DidReceiveResourceResponse(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader,
    const ResourceResponse& param_resource_response, const Resource* param_resource)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    DidReceiveResourceResponseImpl(param_core_probe_sink, identifier, param_document_loader, param_resource_response, param_resource);
}

CORE_EXPORT void DidReceiveDataImpl(CoreProbeSink*, uint64_t, DocumentLoader*, base::SpanOrSize<const char>);
inline void DidReceiveData(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, base::SpanOrSize<const char> data)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    DidReceiveDataImpl(param_core_probe_sink, identifier, param_document_loader, data);
}

CORE_EXPORT void DidReceiveBlobImpl(CoreProbeSink*, uint64_t, DocumentLoader*, BlobDataHandle*);
inline void DidReceiveBlob(
    CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, BlobDataHandle* param_blob_data_handle)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveBlobImpl(param_core_probe_sink, identifier, param_document_loader, param_blob_data_handle);
}

CORE_EXPORT void DidReceiveEncodedDataLengthImpl(CoreProbeSink*, DocumentLoader*, uint64_t, size_t);
inline void DidReceiveEncodedDataLength(CoreProbeSink* param_core_probe_sink, DocumentLoader* loader, uint64_t identifier, size_t encoded_data_length)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveEncodedDataLengthImpl(param_core_probe_sink, loader, identifier, encoded_data_length);
}

CORE_EXPORT void DidFinishLoadingImpl(CoreProbeSink*, uint64_t, DocumentLoader*, base::TimeTicks, int64_t, int64_t);
inline void DidFinishLoading(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader, base::TimeTicks finish_time,
    int64_t encoded_data_length, int64_t decoded_body_length)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    DidFinishLoadingImpl(param_core_probe_sink, identifier, param_document_loader, finish_time, encoded_data_length, decoded_body_length);
}

CORE_EXPORT void DidReceiveCorsRedirectResponseImpl(ExecutionContext*, uint64_t, DocumentLoader*, const ResourceResponse&, Resource*);
inline void DidReceiveCorsRedirectResponse(ExecutionContext* param_execution_context, uint64_t identifier, DocumentLoader* param_document_loader,
    const ResourceResponse& param_resource_response, Resource* param_resource)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveCorsRedirectResponseImpl(param_execution_context, identifier, param_document_loader, param_resource_response, param_resource);
}

CORE_EXPORT void DidFailLoadingImpl(CoreProbeSink*, uint64_t, DocumentLoader*, const ResourceError&, const base::UnguessableToken&);
inline void DidFailLoading(CoreProbeSink* param_core_probe_sink, uint64_t identifier, DocumentLoader* param_document_loader,
    const ResourceError& param_resource_error, const base::UnguessableToken& param_base)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorIssueReporter | CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    DidFailLoadingImpl(param_core_probe_sink, identifier, param_document_loader, param_resource_error, param_base);
}

CORE_EXPORT void WillSendEventSourceRequestImpl(ExecutionContext*);
inline void WillSendEventSourceRequest(ExecutionContext* param_execution_context)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WillSendEventSourceRequestImpl(param_execution_context);
}

CORE_EXPORT void WillDispatchEventSourceEventImpl(ExecutionContext*, uint64_t, const AtomicString&, const AtomicString&, const String&);
inline void WillDispatchEventSourceEvent(
    ExecutionContext* param_execution_context, uint64_t identifier, const AtomicString& event_name, const AtomicString& event_id, const String& data)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WillDispatchEventSourceEventImpl(param_execution_context, identifier, event_name, event_id, data);
}

CORE_EXPORT void WillLoadXHRImpl(ExecutionContext*, const AtomicString&, const KURL&, bool, const HTTPHeaderMap&, bool);
inline void WillLoadXHR(
    ExecutionContext* param_execution_context, const AtomicString& method, const KURL& url, bool async, const HTTPHeaderMap& headers, bool include_credentials)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WillLoadXHRImpl(param_execution_context, method, url, async, headers, include_credentials);
}

CORE_EXPORT void DidFinishXHRImpl(ExecutionContext*, XMLHttpRequest*);
inline void DidFinishXHR(ExecutionContext* param_execution_context, XMLHttpRequest* xhr)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidFinishXHRImpl(param_execution_context, xhr);
}

CORE_EXPORT void DidFinishSyncXHRImpl(ExecutionContext*, const base::TimeDelta);
inline void DidFinishSyncXHR(ExecutionContext* context, const base::TimeDelta blocking_time)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor))
        return;

    DidFinishSyncXHRImpl(context, blocking_time);
}

CORE_EXPORT void ScriptImportedImpl(ExecutionContext*, uint64_t, const String&);
inline void ScriptImported(ExecutionContext* param_execution_context, uint64_t identifier, const String& source_string)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    ScriptImportedImpl(param_execution_context, identifier, source_string);
}

CORE_EXPORT void ScriptExecutionBlockedByCSPImpl(ExecutionContext*, const String&);
inline void ScriptExecutionBlockedByCSP(ExecutionContext* param_execution_context, const String& directive_text)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    ScriptExecutionBlockedByCSPImpl(param_execution_context, directive_text);
}

CORE_EXPORT void DidReceiveScriptResponseImpl(ExecutionContext*, uint64_t);
inline void DidReceiveScriptResponse(ExecutionContext* param_execution_context, uint64_t identifier)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveScriptResponseImpl(param_execution_context, identifier);
}

CORE_EXPORT void DomContentLoadedEventFiredImpl(LocalFrame*);
inline void DomContentLoadedEventFired(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(
            CoreProbeSink::kDevToolsSession | CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorIssueReporter | CoreProbeSink::kInspectorPageAgent))
        return;

    DomContentLoadedEventFiredImpl(param_local_frame);
}

CORE_EXPORT void LoadEventFiredImpl(LocalFrame*);
inline void LoadEventFired(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    LoadEventFiredImpl(param_local_frame);
}

CORE_EXPORT void FrameAttachedToParentImpl(LocalFrame*, const std::optional<AdScriptIdentifier>&);
inline void FrameAttachedToParent(LocalFrame* param_local_frame, const std::optional<AdScriptIdentifier>& ad_script_on_stack)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    FrameAttachedToParentImpl(param_local_frame, ad_script_on_stack);
}

CORE_EXPORT void FrameDetachedFromParentImpl(LocalFrame*, FrameDetachType);
inline void FrameDetachedFromParent(LocalFrame* param_local_frame, FrameDetachType param_frame_detach_type)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    FrameDetachedFromParentImpl(param_local_frame, param_frame_detach_type);
}

CORE_EXPORT void FrameSubtreeWillBeDetachedImpl(LocalFrame*, Frame*);
inline void FrameSubtreeWillBeDetached(LocalFrame* param_local_frame, Frame* param_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    FrameSubtreeWillBeDetachedImpl(param_local_frame, param_frame);
}

CORE_EXPORT void DidStartProvisionalLoadImpl(LocalFrame*);
inline void DidStartProvisionalLoad(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kDevToolsSession))
        return;

    DidStartProvisionalLoadImpl(param_local_frame);
}

CORE_EXPORT void DidFailProvisionalLoadImpl(LocalFrame*);
inline void DidFailProvisionalLoad(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kDevToolsSession))
        return;

    DidFailProvisionalLoadImpl(param_local_frame);
}

CORE_EXPORT void WillCommitLoadImpl(LocalFrame*, DocumentLoader*);
inline void WillCommitLoad(LocalFrame* param_local_frame, DocumentLoader* param_document_loader)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent | CoreProbeSink::kInspectorPageAgent))
        return;

    WillCommitLoadImpl(param_local_frame, param_document_loader);
}

CORE_EXPORT void DidCommitLoadImpl(LocalFrame*, DocumentLoader*);
inline void DidCommitLoad(LocalFrame* param_local_frame, DocumentLoader* param_document_loader)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kDevToolsSession | CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidCommitLoadImpl(param_local_frame, param_document_loader);
}

CORE_EXPORT void DidNavigateWithinDocumentImpl(LocalFrame*, blink::mojom::SameDocumentNavigationType);
inline void DidNavigateWithinDocument(LocalFrame* param_local_frame, blink::mojom::SameDocumentNavigationType param_blink)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    DidNavigateWithinDocumentImpl(param_local_frame, param_blink);
}

CORE_EXPORT void DidRestoreFromBackForwardCacheImpl(LocalFrame*);
inline void DidRestoreFromBackForwardCache(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent | CoreProbeSink::kInspectorPageAgent))
        return;

    DidRestoreFromBackForwardCacheImpl(param_local_frame);
}

CORE_EXPORT void DidOpenDocumentImpl(LocalFrame*, DocumentLoader*);
inline void DidOpenDocument(LocalFrame* param_local_frame, DocumentLoader* param_document_loader)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    DidOpenDocumentImpl(param_local_frame, param_document_loader);
}

CORE_EXPORT void WillCreateDocumentParserImpl(Document*, bool&);
inline void WillCreateDocumentParser(Document* param_document, bool& force_sync_parsing)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    WillCreateDocumentParserImpl(param_document, force_sync_parsing);
}

CORE_EXPORT void FrameDocumentUpdatedImpl(LocalFrame*);
inline void FrameDocumentUpdated(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    FrameDocumentUpdatedImpl(param_local_frame);
}

CORE_EXPORT void FrameOwnerContentUpdatedImpl(LocalFrame*, HTMLFrameOwnerElement*);
inline void FrameOwnerContentUpdated(LocalFrame* param_local_frame, HTMLFrameOwnerElement* param_html_frame_owner_element)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    FrameOwnerContentUpdatedImpl(param_local_frame, param_html_frame_owner_element);
}

CORE_EXPORT void FrameStartedLoadingImpl(LocalFrame*);
inline void FrameStartedLoading(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorTraceEvents))
        return;

    FrameStartedLoadingImpl(param_local_frame);
}

CORE_EXPORT void FrameStoppedLoadingImpl(LocalFrame*);
inline void FrameStoppedLoading(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    FrameStoppedLoadingImpl(param_local_frame);
}

CORE_EXPORT void FrameRequestedNavigationImpl(LocalFrame*, Frame*, const KURL&, ClientNavigationReason, NavigationPolicy);
inline void FrameRequestedNavigation(
    LocalFrame* param_local_frame, Frame* target_frame, const KURL& url, ClientNavigationReason reason, NavigationPolicy policy)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    FrameRequestedNavigationImpl(param_local_frame, target_frame, url, reason, policy);
}

CORE_EXPORT void FrameScheduledNavigationImpl(LocalFrame*, const KURL&, base::TimeDelta, ClientNavigationReason);
inline void FrameScheduledNavigation(LocalFrame* param_local_frame, const KURL& url, base::TimeDelta delay, ClientNavigationReason reason)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorPageAgent))
        return;

    FrameScheduledNavigationImpl(param_local_frame, url, delay, reason);
}

CORE_EXPORT void FrameClearedScheduledNavigationImpl(LocalFrame*);
inline void FrameClearedScheduledNavigation(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent | CoreProbeSink::kInspectorPageAgent))
        return;

    FrameClearedScheduledNavigationImpl(param_local_frame);
}

CORE_EXPORT void WillCreateWebSocketImpl(ExecutionContext*, uint64_t, const KURL&, const String&, std::optional<base::UnguessableToken>*);
inline void WillCreateWebSocket(ExecutionContext* param_execution_context, uint64_t identifier, const KURL& request_url, const String& protocol,
    std::optional<base::UnguessableToken>* devtools_token)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WillCreateWebSocketImpl(param_execution_context, identifier, request_url, protocol, devtools_token);
}

CORE_EXPORT void WillSendWebSocketHandshakeRequestImpl(ExecutionContext*, uint64_t, network::mojom::blink::WebSocketHandshakeRequest*);
inline void WillSendWebSocketHandshakeRequest(
    ExecutionContext* param_execution_context, uint64_t identifier, network::mojom::blink::WebSocketHandshakeRequest* request)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WillSendWebSocketHandshakeRequestImpl(param_execution_context, identifier, request);
}

CORE_EXPORT void DidReceiveWebSocketHandshakeResponseImpl(
    ExecutionContext*, uint64_t, network::mojom::blink::WebSocketHandshakeRequest*, network::mojom::blink::WebSocketHandshakeResponse*);
inline void DidReceiveWebSocketHandshakeResponse(ExecutionContext* param_execution_context, uint64_t identifier,
    network::mojom::blink::WebSocketHandshakeRequest* request, network::mojom::blink::WebSocketHandshakeResponse* response)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveWebSocketHandshakeResponseImpl(param_execution_context, identifier, request, response);
}

CORE_EXPORT void DidCloseWebSocketImpl(ExecutionContext*, uint64_t);
inline void DidCloseWebSocket(ExecutionContext* param_execution_context, uint64_t identifier)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidCloseWebSocketImpl(param_execution_context, identifier);
}

CORE_EXPORT void DidReceiveWebSocketMessageImpl(ExecutionContext*, uint64_t, int, bool, const Vector<base::span<const char>>&);
inline void DidReceiveWebSocketMessage(
    ExecutionContext* param_execution_context, uint64_t identifier, int opcode, bool masked, const Vector<base::span<const char>>& data)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveWebSocketMessageImpl(param_execution_context, identifier, opcode, masked, data);
}

CORE_EXPORT void DidSendWebSocketMessageImpl(ExecutionContext*, uint64_t, int, bool, base::span<const char>);
inline void DidSendWebSocketMessage(ExecutionContext* param_execution_context, uint64_t identifier, int opcode, bool masked, base::span<const char> payload)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidSendWebSocketMessageImpl(param_execution_context, identifier, opcode, masked, payload);
}

CORE_EXPORT void DidReceiveWebSocketMessageErrorImpl(ExecutionContext*, uint64_t, const String&);
inline void DidReceiveWebSocketMessageError(ExecutionContext* param_execution_context, uint64_t identifier, const String& error_message)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    DidReceiveWebSocketMessageErrorImpl(param_execution_context, identifier, error_message);
}

CORE_EXPORT void WebTransportCreatedImpl(ExecutionContext*, uint64_t, const KURL&);
inline void WebTransportCreated(ExecutionContext* param_execution_context, uint64_t transport_id, const KURL& request_url)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WebTransportCreatedImpl(param_execution_context, transport_id, request_url);
}

CORE_EXPORT void WebTransportConnectionEstablishedImpl(ExecutionContext*, uint64_t);
inline void WebTransportConnectionEstablished(ExecutionContext* param_execution_context, uint64_t transport_id)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WebTransportConnectionEstablishedImpl(param_execution_context, transport_id);
}

CORE_EXPORT void WebTransportClosedImpl(ExecutionContext*, uint64_t);
inline void WebTransportClosed(ExecutionContext* param_execution_context, uint64_t transport_id)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WebTransportClosedImpl(param_execution_context, transport_id);
}

CORE_EXPORT void WillCreateP2PSocketUdpImpl(ExecutionContext*, std::optional<base::UnguessableToken>*);
inline void WillCreateP2PSocketUdp(ExecutionContext* param_execution_context, std::optional<base::UnguessableToken>* devtools_token)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    WillCreateP2PSocketUdpImpl(param_execution_context, devtools_token);
}

CORE_EXPORT void LayerTreeDidChangeImpl(LocalFrame*);
inline void LayerTreeDidChange(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorLayerTreeAgent))
        return;

    LayerTreeDidChangeImpl(param_local_frame);
}

CORE_EXPORT void LayerTreePaintedImpl(LocalFrame*);
inline void LayerTreePainted(LocalFrame* param_local_frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorLayerTreeAgent))
        return;

    LayerTreePaintedImpl(param_local_frame);
}

CORE_EXPORT void PseudoElementCreatedImpl(PseudoElement*);
inline void PseudoElementCreated(PseudoElement* param_pseudo_element)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    PseudoElementCreatedImpl(param_pseudo_element);
}

CORE_EXPORT void TopLayerElementsChangedImpl(Document*);
inline void TopLayerElementsChanged(Document* param_document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    TopLayerElementsChangedImpl(param_document);
}

CORE_EXPORT void PseudoElementDestroyedImpl(PseudoElement*);
inline void PseudoElementDestroyed(PseudoElement* param_pseudo_element)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    PseudoElementDestroyedImpl(param_pseudo_element);
}

CORE_EXPORT void DidCreateAnimationImpl(Document*, unsigned);
inline void DidCreateAnimation(Document* param_document, unsigned param_unsigned)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorAnimationAgent))
        return;

    DidCreateAnimationImpl(param_document, param_unsigned);
}

CORE_EXPORT void AnimationUpdatedImpl(Document*, Animation*);
inline void AnimationUpdated(Document* param_document, Animation* param_animation)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorAnimationAgent))
        return;

    AnimationUpdatedImpl(param_document, param_animation);
}

CORE_EXPORT void WindowOpenImpl(ExecutionContext*, const KURL&, const AtomicString&, const WebWindowFeatures&, bool);
inline void WindowOpen(
    ExecutionContext* param_execution_context, const KURL& url, const AtomicString& window_name, const WebWindowFeatures& window_features, bool user_gestrue)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    WindowOpenImpl(param_execution_context, url, window_name, window_features, user_gestrue);
}

CORE_EXPORT void ConsoleMessageAddedImpl(ExecutionContext*, ConsoleMessage*);
inline void ConsoleMessageAdded(ExecutionContext* param_execution_context, ConsoleMessage* param_console_message)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorLogAgent))
        return;

    ConsoleMessageAddedImpl(param_execution_context, param_console_message);
}

CORE_EXPORT void InspectorIssueAddedImpl(CoreProbeSink*, protocol::Audits::InspectorIssue*);
inline void InspectorIssueAdded(CoreProbeSink* param_core_probe_sink, protocol::Audits::InspectorIssue* param_protocol)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorAuditsAgent))
        return;

    InspectorIssueAddedImpl(param_core_probe_sink, param_protocol);
}

CORE_EXPORT void WillRunJavaScriptDialogImpl(LocalFrame*);
inline void WillRunJavaScriptDialog(LocalFrame* frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    WillRunJavaScriptDialogImpl(frame);
}

CORE_EXPORT void DidRunJavaScriptDialogImpl(LocalFrame*);
inline void DidRunJavaScriptDialog(LocalFrame* frame)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor | CoreProbeSink::kInspectorPageAgent))
        return;

    DidRunJavaScriptDialogImpl(frame);
}

CORE_EXPORT void DocumentWriteFetchScriptImpl(Document*);
inline void DocumentWriteFetchScript(Document* param_document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kPerformanceMonitor))
        return;

    DocumentWriteFetchScriptImpl(param_document);
}

CORE_EXPORT void DidChangeViewportImpl(LocalFrame*);
inline void DidChangeViewport(LocalFrame* document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    DidChangeViewportImpl(document);
}

CORE_EXPORT void BreakableLocationImpl(ExecutionContext*, const char*);
inline void BreakableLocation(ExecutionContext* context, const char* name)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    BreakableLocationImpl(context, name);
}

CORE_EXPORT void WillHandlePromiseImpl(ExecutionContext*, ScriptState*, bool, const char*, PropertyName, const String&);
inline void WillHandlePromise(ExecutionContext* context, ScriptState* script_state, bool resolving, const char* class_like_name,
    PropertyName property_like_name, const String& script_url)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kAnimationFrameTimingMonitor))
        return;

    WillHandlePromiseImpl(context, script_state, resolving, class_like_name, property_like_name, script_url);
}

class CORE_EXPORT RecalculateStyle : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit RecalculateStyle(Document*);
    ~RecalculateStyle();
    CoreProbeSink* probe_sink = nullptr;
    Document* document;
};

class CORE_EXPORT UpdateLayout : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit UpdateLayout(Document*);
    ~UpdateLayout();
    CoreProbeSink* probe_sink = nullptr;
    Document* document;
};

class CORE_EXPORT EvaluateScriptBlock : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit EvaluateScriptBlock(
        std::reference_wrapper<std::remove_reference_t<ScriptState&>>, std::reference_wrapper<std::remove_reference_t<const KURL&>>, bool, bool);
    ~EvaluateScriptBlock();
    CoreProbeSink* probe_sink = nullptr;
    ScriptState& script_state;
    const KURL& source_url;
    bool is_module;
    bool sanitize;
};

class CORE_EXPORT ExecuteScript : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit ExecuteScript(ExecutionContext*, v8::Local<v8::Context>, std::reference_wrapper<std::remove_reference_t<const String&>>, int);
    ~ExecuteScript();
    CoreProbeSink* probe_sink = nullptr;
    ExecutionContext* context;
    v8::Local<v8::Context> v8_context;
    const String& script_url;
    int script_id;
};

class CORE_EXPORT CallFunction : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit CallFunction(ExecutionContext*, v8::Local<v8::Context>, v8::Local<v8::Function>, int = 0);
    ~CallFunction();
    CoreProbeSink* probe_sink = nullptr;
    ExecutionContext* context;
    v8::Local<v8::Context> v8_context;
    v8::Local<v8::Function> function;
    int depth;
};

class CORE_EXPORT UserCallback : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit UserCallback(ExecutionContext*, const char*, AtomicString, bool, EventTarget* = nullptr, Event* = nullptr, EventListener* = nullptr);
    ~UserCallback();
    CoreProbeSink* probe_sink = nullptr;
    ExecutionContext* context;
    const char* name;
    AtomicString atomic_name;
    bool recurring;
    EventTarget* event_target;
    Event* event;
    EventListener* listener;
};

class CORE_EXPORT InvokeCallback : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit InvokeCallback(std::reference_wrapper<std::remove_reference_t<ScriptState&>>, const char*, CallbackFunctionBase*,
        v8::MaybeLocal<v8::Value> = v8::MaybeLocal<v8::Value>());
    ~InvokeCallback();
    CoreProbeSink* probe_sink = nullptr;
    ScriptState& script_state;
    const char* name;
    CallbackFunctionBase* callback;
    v8::MaybeLocal<v8::Value> function;
};

class CORE_EXPORT InvokeEventHandler : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit InvokeEventHandler(std::reference_wrapper<std::remove_reference_t<ScriptState&>>, Event* = nullptr, JSBasedEventListener* = nullptr);
    ~InvokeEventHandler();
    CoreProbeSink* probe_sink = nullptr;
    ScriptState& script_state;
    Event* event;
    JSBasedEventListener* listener;
};

class CORE_EXPORT V8Compile : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit V8Compile(ExecutionContext*, std::reference_wrapper<std::remove_reference_t<const String&>>, int, int);
    ~V8Compile();
    CoreProbeSink* probe_sink = nullptr;
    ExecutionContext* context;
    const String& file_name;
    int line;
    int column;
};

class CORE_EXPORT ParseHTML : public ProbeBase {
    STACK_ALLOCATED();

public:
    explicit ParseHTML(Document*, HTMLDocumentParser*);
    ~ParseHTML();
    CoreProbeSink* probe_sink = nullptr;
    Document* document;
    HTMLDocumentParser* parser;
};

CORE_EXPORT void ForcePseudoStateImpl(Element*, CSSSelector::PseudoType, bool*);
inline void ForcePseudoState(Element* element, CSSSelector::PseudoType pseudo_state, bool* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    ForcePseudoStateImpl(element, pseudo_state, result);
}

CORE_EXPORT void ShouldForceCorsPreflightImpl(ExecutionContext*, bool*);
inline void ShouldForceCorsPreflight(ExecutionContext* param_execution_context, bool* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    ShouldForceCorsPreflightImpl(param_execution_context, result);
}

CORE_EXPORT void ShouldBlockRequestImpl(CoreProbeSink*, const KURL&, bool*);
inline void ShouldBlockRequest(CoreProbeSink* param_core_probe_sink, const KURL& param_kurl, bool* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    ShouldBlockRequestImpl(param_core_probe_sink, param_kurl, result);
}

CORE_EXPORT void ShouldBypassServiceWorkerImpl(ExecutionContext*, bool*);
inline void ShouldBypassServiceWorker(ExecutionContext* context, bool* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    ShouldBypassServiceWorkerImpl(context, result);
}

CORE_EXPORT void ConsoleTimeStampImpl(v8::Isolate*, v8::Local<v8::String>);
inline void ConsoleTimeStamp(v8::Isolate* isolate, v8::Local<v8::String> label)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPerformanceAgent))
        return;

    ConsoleTimeStampImpl(isolate, label);
}

CORE_EXPORT void WillStartDebuggerTaskImpl(CoreProbeSink*);
inline void WillStartDebuggerTask(CoreProbeSink* param_core_probe_sink)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPerformanceAgent))
        return;

    WillStartDebuggerTaskImpl(param_core_probe_sink);
}

CORE_EXPORT void DidFinishDebuggerTaskImpl(CoreProbeSink*);
inline void DidFinishDebuggerTask(CoreProbeSink* param_core_probe_sink)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPerformanceAgent))
        return;

    DidFinishDebuggerTaskImpl(param_core_probe_sink);
}

CORE_EXPORT void LifecycleEventImpl(LocalFrame*, DocumentLoader*, const char*, double);
inline void LifecycleEvent(LocalFrame* param_local_frame, DocumentLoader* param_document_loader, const char* name, double timestamp)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    LifecycleEventImpl(param_local_frame, param_document_loader, name, timestamp);
}

CORE_EXPORT void PaintTimingImpl(Document*, const char*, double);
inline void PaintTiming(Document* param_document, const char* name, double timestamp)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kDevToolsSession | CoreProbeSink::kInspectorPageAgent | CoreProbeSink::kInspectorTraceEvents))
        return;

    PaintTimingImpl(param_document, name, timestamp);
}

CORE_EXPORT void DidCreateAudioContextImpl(ExecutionContext*);
inline void DidCreateAudioContext(ExecutionContext* param_execution_context)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidCreateAudioContextImpl(param_execution_context);
}

CORE_EXPORT void DidCloseAudioContextImpl(ExecutionContext*);
inline void DidCloseAudioContext(ExecutionContext* param_execution_context)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidCloseAudioContextImpl(param_execution_context);
}

CORE_EXPORT void DidResumeAudioContextImpl(ExecutionContext*);
inline void DidResumeAudioContext(ExecutionContext* param_execution_context)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidResumeAudioContextImpl(param_execution_context);
}

CORE_EXPORT void DidSuspendAudioContextImpl(ExecutionContext*);
inline void DidSuspendAudioContext(ExecutionContext* param_execution_context)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEventBreakpointsAgent))
        return;

    DidSuspendAudioContextImpl(param_execution_context);
}

CORE_EXPORT void DidProduceCompilationCacheImpl(CoreProbeSink*, const ClassicScript&, v8::Local<v8::Script>);
inline void DidProduceCompilationCache(CoreProbeSink* param_core_probe_sink, const ClassicScript& param_classic_script, v8::Local<v8::Script> script)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    DidProduceCompilationCacheImpl(param_core_probe_sink, param_classic_script, script);
}

CORE_EXPORT void ApplyCompilationModeOverrideImpl(
    ExecutionContext*, const ClassicScript&, v8::ScriptCompiler::CachedData**, v8::ScriptCompiler::CompileOptions*);
inline void ApplyCompilationModeOverride(ExecutionContext* param_execution_context, const ClassicScript& param_classic_script,
    v8::ScriptCompiler::CachedData** cached_data, v8::ScriptCompiler::CompileOptions* param_v8)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    ApplyCompilationModeOverrideImpl(param_execution_context, param_classic_script, cached_data, param_v8);
}

CORE_EXPORT void NodeCreatedImpl(Node*);
inline void NodeCreated(Node* node)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    NodeCreatedImpl(node);
}

CORE_EXPORT void FileChooserOpenedImpl(LocalFrame*, HTMLInputElement*, bool, bool*);
inline void FileChooserOpened(LocalFrame* frame, HTMLInputElement* element, bool multiple, bool* intercepted)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPageAgent))
        return;

    FileChooserOpenedImpl(frame, element, multiple, intercepted);
}

CORE_EXPORT void PlayerErrorsRaisedImpl(ExecutionContext*, String, const Vector<InspectorPlayerError>&);
inline void PlayerErrorsRaised(ExecutionContext* context, String player_id, const Vector<InspectorPlayerError>& errors)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorMediaAgent))
        return;

    PlayerErrorsRaisedImpl(context, player_id, errors);
}

CORE_EXPORT void PlayerEventsAddedImpl(ExecutionContext*, String, const Vector<InspectorPlayerEvent>&);
inline void PlayerEventsAdded(ExecutionContext* context, String player_id, const Vector<InspectorPlayerEvent>& events)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorMediaAgent))
        return;

    PlayerEventsAddedImpl(context, player_id, events);
}

CORE_EXPORT void PlayerMessagesLoggedImpl(ExecutionContext*, String, const Vector<InspectorPlayerMessage>&);
inline void PlayerMessagesLogged(ExecutionContext* context, String player_id, const Vector<InspectorPlayerMessage>& messages)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorMediaAgent))
        return;

    PlayerMessagesLoggedImpl(context, player_id, messages);
}

CORE_EXPORT void PlayerPropertiesChangedImpl(ExecutionContext*, String, const Vector<InspectorPlayerProperty>&);
inline void PlayerPropertiesChanged(ExecutionContext* context, String player_id, const Vector<InspectorPlayerProperty>& properties)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorMediaAgent))
        return;

    PlayerPropertiesChangedImpl(context, player_id, properties);
}

CORE_EXPORT void PlayersCreatedImpl(ExecutionContext*, const Vector<WebString>&);
inline void PlayersCreated(ExecutionContext* context, const Vector<WebString>& players)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorMediaAgent))
        return;

    PlayersCreatedImpl(context, players);
}

CORE_EXPORT void SetDevToolsIdsImpl(CoreProbeSink*, ResourceRequest&, const FetchInitiatorInfo&);
inline void SetDevToolsIds(CoreProbeSink* param_core_probe_sink, ResourceRequest& request, const FetchInitiatorInfo& param_fetch_initiator_info)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    SetDevToolsIdsImpl(param_core_probe_sink, request, param_fetch_initiator_info);
}

CORE_EXPORT void DidMutateStyleSheetImpl(Document*, CSSStyleSheet*);
inline void DidMutateStyleSheet(Document* param_document, CSSStyleSheet* style_sheet)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    DidMutateStyleSheetImpl(param_document, style_sheet);
}

CORE_EXPORT void DidReplaceStyleSheetTextImpl(Document*, CSSStyleSheet*, const String&);
inline void DidReplaceStyleSheetText(Document* param_document, CSSStyleSheet* style_sheet, const String& text)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    DidReplaceStyleSheetTextImpl(param_document, style_sheet, text);
}

CORE_EXPORT void GetTextPositionImpl(Document*, wtf_size_t, const String*, TextPosition*);
inline void GetTextPosition(Document* param_document, wtf_size_t offset, const String* text, TextPosition* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    GetTextPositionImpl(param_document, offset, text, result);
}

CORE_EXPORT void LocalFontsEnabledImpl(ExecutionContext*, bool*);
inline void LocalFontsEnabled(ExecutionContext* param_execution_context, bool* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    LocalFontsEnabledImpl(param_execution_context, result);
}

CORE_EXPORT void DidUpdateComputedStyleImpl(Element*, const ComputedStyle*, const ComputedStyle*);
inline void DidUpdateComputedStyle(Element* param_element, const ComputedStyle* old_style, const ComputedStyle* new_style)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorCSSAgent))
        return;

    DidUpdateComputedStyleImpl(param_element, old_style, new_style);
}

CORE_EXPORT void GetDisabledImageTypesImpl(ExecutionContext*, HashSet<String>*);
inline void GetDisabledImageTypes(ExecutionContext* param_execution_context, HashSet<String>* result)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    GetDisabledImageTypesImpl(param_execution_context, result);
}

CORE_EXPORT void OnContentSecurityPolicyViolationImpl(ExecutionContext*, const blink::ContentSecurityPolicyViolationType);
inline void OnContentSecurityPolicyViolation(ExecutionContext* context, const blink::ContentSecurityPolicyViolationType violationType)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMDebuggerAgent))
        return;

    OnContentSecurityPolicyViolationImpl(context, violationType);
}

CORE_EXPORT void IsCacheDisabledImpl(ExecutionContext*, bool*);
inline void IsCacheDisabled(ExecutionContext* param_execution_context, bool* is_cache_disabled)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorNetworkAgent))
        return;

    IsCacheDisabledImpl(param_execution_context, is_cache_disabled);
}

CORE_EXPORT void PerformanceEntryAddedImpl(ExecutionContext*, PerformanceEntry*);
inline void PerformanceEntryAdded(ExecutionContext* param_execution_context, PerformanceEntry* param_performance_entry)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPerformanceTimelineAgent))
        return;

    PerformanceEntryAddedImpl(param_execution_context, param_performance_entry);
}

CORE_EXPORT void ApplyAutomationOverrideImpl(ExecutionContext*, bool&);
inline void ApplyAutomationOverride(ExecutionContext* param_execution_context, bool& enabled)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorEmulationAgent))
        return;

    ApplyAutomationOverrideImpl(param_execution_context, enabled);
}

CORE_EXPORT void DidAddSpeculationRuleSetImpl(Document&, const SpeculationRuleSet&);
inline void DidAddSpeculationRuleSet(Document& param_document, const SpeculationRuleSet& rule_set)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPreloadAgent))
        return;

    DidAddSpeculationRuleSetImpl(param_document, rule_set);
}

CORE_EXPORT void DidRemoveSpeculationRuleSetImpl(Document&, const SpeculationRuleSet&);
inline void DidRemoveSpeculationRuleSet(Document& param_document, const SpeculationRuleSet& rule_set)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPreloadAgent))
        return;

    DidRemoveSpeculationRuleSetImpl(param_document, rule_set);
}

CORE_EXPORT void SpeculationCandidatesUpdatedImpl(Document&, const HeapVector<Member<SpeculationCandidate>>&);
inline void SpeculationCandidatesUpdated(Document& param_document, const HeapVector<Member<SpeculationCandidate>>& candidates)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorPreloadAgent))
        return;

    SpeculationCandidatesUpdatedImpl(param_document, candidates);
}

CORE_EXPORT void DidInitializeFrameWidgetImpl(LocalFrame*);
inline void DidInitializeFrameWidget(LocalFrame* document)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorOverlayAgent))
        return;

    DidInitializeFrameWidgetImpl(document);
}

CORE_EXPORT void UpdateScrollableFlagImpl(Node*, std::optional<bool>);
inline void UpdateScrollableFlag(Node* node, std::optional<bool> param_std)
{
    if (!CoreProbeSink::HasAgentsGlobal(CoreProbeSink::kInspectorDOMAgent))
        return;

    UpdateScrollableFlagImpl(node, param_std);
}

} // namespace probe
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_CORE_PROBES_INL_H_
