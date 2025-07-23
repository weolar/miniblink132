// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/web_origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/web/web_origin_trials.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_feature.mojom-shared.h"
#include "third_party/blink/public/common/origin_trials/origin_trials.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/web/web_document.h"
#include "v8/include/v8.h"

namespace blink {

// static
bool WebOriginTrials::IsAdInterestGroupAPIEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::AdInterestGroupAPIEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsAdInterestGroupAPIEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::AdInterestGroupAPIEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsAIPromptAPIForExtensionEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::AIPromptAPIForExtensionEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsAIPromptAPIForExtensionEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::AIPromptAPIForExtensionEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsAISummarizationAPIEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::AISummarizationAPIEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsAISummarizationAPIEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::AISummarizationAPIEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsDatabaseEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::DatabaseEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsDatabaseEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::DatabaseEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsDigitalGoodsEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::DigitalGoodsEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsDigitalGoodsEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::DigitalGoodsEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsDocumentPolicyNegotiationEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::DocumentPolicyNegotiationEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsDocumentPolicyNegotiationEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::DocumentPolicyNegotiationEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsFedCmAuthzEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::FedCmAuthzEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsFedCmAuthzEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::FedCmAuthzEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsFedCmButtonModeEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::FedCmButtonModeEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsFedCmButtonModeEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::FedCmButtonModeEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsFedCmMultipleIdentityProvidersEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::FedCmMultipleIdentityProvidersEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsFedCmMultipleIdentityProvidersEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::FedCmMultipleIdentityProvidersEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsGetAllScreensMediaEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::GetAllScreensMediaEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsGetAllScreensMediaEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::GetAllScreensMediaEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsMutationEventsEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::MutationEventsEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsMutationEventsEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::MutationEventsEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsOriginTrialsSampleAPIEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsOriginTrialsSampleAPIEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsOriginTrialsSampleAPIDeprecationEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsOriginTrialsSampleAPIDeprecationEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsPermissionElementEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::PermissionElementEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsPermissionElementEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::PermissionElementEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsPNaClEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::PNaClEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsPNaClEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::PNaClEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsPrivateNetworkAccessPermissionPromptEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::PrivateNetworkAccessPermissionPromptEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsPrivateNetworkAccessPermissionPromptEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::PrivateNetworkAccessPermissionPromptEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsPrivateStateTokensEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::PrivateStateTokensEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsPrivateStateTokensEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::PrivateStateTokensEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsServiceWorkerStaticRouterEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::ServiceWorkerStaticRouterEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsServiceWorkerStaticRouterEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::ServiceWorkerStaticRouterEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsTextFragmentIdentifiersEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsTextFragmentIdentifiersEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsTouchEventFeatureDetectionEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsTouchEventFeatureDetectionEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsViewportSegmentsEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::ViewportSegmentsEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsViewportSegmentsEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::ViewportSegmentsEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsWebIdentityDigitalCredentialsEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::WebIdentityDigitalCredentialsEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsWebIdentityDigitalCredentialsEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::WebIdentityDigitalCredentialsEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsWebXRImageTrackingEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::WebXRImageTrackingEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsWebXRImageTrackingEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::WebXRImageTrackingEnabled(ExecutionContext::From(context));
}

// static
bool WebOriginTrials::IsWebXRPlaneDetectionEnabled(const WebDocument* web_document)
{
    if (!web_document)
        return false;
    Document* document = *web_document;
    return RuntimeEnabledFeatures::WebXRPlaneDetectionEnabled(document->GetExecutionContext());
}

// static
bool WebOriginTrials::IsWebXRPlaneDetectionEnabled(const v8::Local<v8::Context> context)
{
    return RuntimeEnabledFeatures::WebXRPlaneDetectionEnabled(ExecutionContext::From(context));
}

} // namespace blink
