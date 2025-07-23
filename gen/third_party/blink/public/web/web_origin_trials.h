// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/web_origin_trials.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#ifndef THIRD_PARTY_BLINK_PUBLIC_WEB_WEB_ORIGIN_TRIALS_H_
#define THIRD_PARTY_BLINK_PUBLIC_WEB_WEB_ORIGIN_TRIALS_H_

#include "third_party/blink/public/platform/web_common.h"
#include "v8/include/v8.h"

namespace blink {

class WebDocument;

class BLINK_EXPORT WebOriginTrials {
public:
    static bool IsAdInterestGroupAPIEnabled(const WebDocument* web_document);
    static bool IsAdInterestGroupAPIEnabled(const v8::Local<v8::Context> context);
    static bool IsAIPromptAPIForExtensionEnabled(const WebDocument* web_document);
    static bool IsAIPromptAPIForExtensionEnabled(const v8::Local<v8::Context> context);
    static bool IsAISummarizationAPIEnabled(const WebDocument* web_document);
    static bool IsAISummarizationAPIEnabled(const v8::Local<v8::Context> context);
    static bool IsDatabaseEnabled(const WebDocument* web_document);
    static bool IsDatabaseEnabled(const v8::Local<v8::Context> context);
    static bool IsDigitalGoodsEnabled(const WebDocument* web_document);
    static bool IsDigitalGoodsEnabled(const v8::Local<v8::Context> context);
    static bool IsDocumentPolicyNegotiationEnabled(const WebDocument* web_document);
    static bool IsDocumentPolicyNegotiationEnabled(const v8::Local<v8::Context> context);
    static bool IsFedCmAuthzEnabled(const WebDocument* web_document);
    static bool IsFedCmAuthzEnabled(const v8::Local<v8::Context> context);
    static bool IsFedCmButtonModeEnabled(const WebDocument* web_document);
    static bool IsFedCmButtonModeEnabled(const v8::Local<v8::Context> context);
    static bool IsFedCmMultipleIdentityProvidersEnabled(const WebDocument* web_document);
    static bool IsFedCmMultipleIdentityProvidersEnabled(const v8::Local<v8::Context> context);
    static bool IsGetAllScreensMediaEnabled(const WebDocument* web_document);
    static bool IsGetAllScreensMediaEnabled(const v8::Local<v8::Context> context);
    static bool IsMutationEventsEnabled(const WebDocument* web_document);
    static bool IsMutationEventsEnabled(const v8::Local<v8::Context> context);
    static bool IsOriginTrialsSampleAPIEnabled(const WebDocument* web_document);
    static bool IsOriginTrialsSampleAPIEnabled(const v8::Local<v8::Context> context);
    static bool IsOriginTrialsSampleAPIDeprecationEnabled(const WebDocument* web_document);
    static bool IsOriginTrialsSampleAPIDeprecationEnabled(const v8::Local<v8::Context> context);
    static bool IsPermissionElementEnabled(const WebDocument* web_document);
    static bool IsPermissionElementEnabled(const v8::Local<v8::Context> context);
    static bool IsPNaClEnabled(const WebDocument* web_document);
    static bool IsPNaClEnabled(const v8::Local<v8::Context> context);
    static bool IsPrivateNetworkAccessPermissionPromptEnabled(const WebDocument* web_document);
    static bool IsPrivateNetworkAccessPermissionPromptEnabled(const v8::Local<v8::Context> context);
    static bool IsPrivateStateTokensEnabled(const WebDocument* web_document);
    static bool IsPrivateStateTokensEnabled(const v8::Local<v8::Context> context);
    static bool IsServiceWorkerStaticRouterEnabled(const WebDocument* web_document);
    static bool IsServiceWorkerStaticRouterEnabled(const v8::Local<v8::Context> context);
    static bool IsTextFragmentIdentifiersEnabled(const WebDocument* web_document);
    static bool IsTextFragmentIdentifiersEnabled(const v8::Local<v8::Context> context);
    static bool IsTouchEventFeatureDetectionEnabled(const WebDocument* web_document);
    static bool IsTouchEventFeatureDetectionEnabled(const v8::Local<v8::Context> context);
    static bool IsViewportSegmentsEnabled(const WebDocument* web_document);
    static bool IsViewportSegmentsEnabled(const v8::Local<v8::Context> context);
    static bool IsWebIdentityDigitalCredentialsEnabled(const WebDocument* web_document);
    static bool IsWebIdentityDigitalCredentialsEnabled(const v8::Local<v8::Context> context);
    static bool IsWebXRImageTrackingEnabled(const WebDocument* web_document);
    static bool IsWebXRImageTrackingEnabled(const v8::Local<v8::Context> context);
    static bool IsWebXRPlaneDetectionEnabled(const WebDocument* web_document);
    static bool IsWebXRPlaneDetectionEnabled(const v8::Local<v8::Context> context);

    WebOriginTrials() = delete;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_PUBLIC_WEB_WEB_ORIGIN_TRIALS_H_
