// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_feature_state_override_context.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_FEATURE_STATE_RUNTIME_FEATURE_STATE_OVERRIDE_CONTEXT_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_FEATURE_STATE_RUNTIME_FEATURE_STATE_OVERRIDE_CONTEXT_H_

#include "base/containers/flat_map.h"
#include "mojo/public/cpp/bindings/remote.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_feature.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_state_host.mojom-blink.h"
#include "third_party/blink/public/mojom/runtime_feature_state/runtime_feature.mojom-shared.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
#include "third_party/blink/renderer/platform/mojo/heap_mojo_remote.h"
#include "third_party/blink/renderer/platform/mojo/mojo_binding_context.h"
#include "third_party/blink/renderer/platform/platform_export.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

// This class coalesces browser side runtime feature state into a final value
// which is then used to determine whether a given Blink runtime feature is
// enabled.
//
// Use `Is*ForceEnabled()` or `Is*ForceDisabled()` to query the final value.
class PLATFORM_EXPORT RuntimeFeatureStateOverrideContext : public GarbageCollected<RuntimeFeatureStateOverrideContext> {
public:
    RuntimeFeatureStateOverrideContext(MojoBindingContext* binding_context, UseCounter* use_counter, bool send_runtime_features_to_browser)
        : binding_context_(binding_context)
        , use_counter_(use_counter)
        , origin_trial_state_host_remote_(binding_context)
        , send_runtime_features_to_browser_(send_runtime_features_to_browser)
    {
        DCHECK(binding_context);
        DCHECK(use_counter);
        override_values_.reserve(9);
        origin_trial_overrides_.reserve(9);
    }

    void ApplyOverrideValuesFromParams(const base::flat_map<mojom::RuntimeFeature, bool>& values_from_params);

    void ApplyOriginTrialOverride(const blink::mojom::blink::OriginTrialFeature& origin_trial_feature, const WTF::Vector<WTF::String>& tokens);

    bool IsBlinkExtensionChromeOSForceDisabled() const;

    bool IsBlinkExtensionChromeOSForceEnabled() const;

    void SetBlinkExtensionChromeOSForceDisabled();

    void SetBlinkExtensionChromeOSForceEnabled();

    bool IsBlinkExtensionChromeOSKioskForceDisabled() const;

    bool IsBlinkExtensionChromeOSKioskForceEnabled() const;

    void SetBlinkExtensionChromeOSKioskForceDisabled();

    void SetBlinkExtensionChromeOSKioskForceEnabled();

    bool IsBlinkExtensionDiagnosticsForceDisabled() const;

    bool IsBlinkExtensionDiagnosticsForceEnabled() const;

    void SetBlinkExtensionDiagnosticsForceDisabled();

    void SetBlinkExtensionDiagnosticsForceEnabled();

    bool IsDisableThirdPartyStoragePartitioning2ForceDisabled() const;

    bool IsDisableThirdPartyStoragePartitioning2ForceEnabled() const;

    void SetDisableThirdPartyStoragePartitioning2ForceDisabled();

    void SetDisableThirdPartyStoragePartitioning2ForceEnabled();

    bool SetDisableThirdPartyStoragePartitioning2Enabled(const WTF::Vector<WTF::String>& tokens);
    bool IsFedCmAuthzForceDisabled() const;

    bool IsFedCmAuthzForceEnabled() const;

    void SetFedCmAuthzForceDisabled();

    void SetFedCmAuthzForceEnabled();

    bool SetFedCmAuthzEnabled(const WTF::Vector<WTF::String>& tokens);
    bool IsFedCmIdpSigninStatusForceDisabled() const;

    bool IsFedCmIdpSigninStatusForceEnabled() const;

    void SetFedCmIdpSigninStatusForceDisabled();

    void SetFedCmIdpSigninStatusForceEnabled();

    bool IsFedCmWithStorageAccessAPIForceDisabled() const;

    bool IsFedCmWithStorageAccessAPIForceEnabled() const;

    void SetFedCmWithStorageAccessAPIForceDisabled();

    void SetFedCmWithStorageAccessAPIForceEnabled();

    bool SetFedCmWithStorageAccessAPIEnabled(const WTF::Vector<WTF::String>& tokens);
    bool IsOriginTrialsSampleAPIBrowserReadWriteForceDisabled() const;

    bool IsOriginTrialsSampleAPIBrowserReadWriteForceEnabled() const;

    void SetOriginTrialsSampleAPIBrowserReadWriteForceDisabled();

    void SetOriginTrialsSampleAPIBrowserReadWriteForceEnabled();

    bool SetOriginTrialsSampleAPIBrowserReadWriteEnabled(const WTF::Vector<WTF::String>& tokens);
    bool IsTestFeatureForceDisabled() const;

    bool IsTestFeatureForceEnabled() const;

    void SetTestFeatureForceDisabled();

    void SetTestFeatureForceEnabled();

    void EnablePersistentTrial(const WTF::String& raw_token, const WTF::Vector<scoped_refptr<const blink::SecurityOrigin>>& script_origins);

    const base::flat_map<mojom::RuntimeFeature, bool>& GetOverrideValuesForTesting() const
    {
        return override_values_;
    }

    void Trace(Visitor*) const;

private:
    mojom::blink::OriginTrialStateHost* GetOrBindOriginTrialStateHost();

    base::flat_map<mojom::RuntimeFeature, bool> override_values_;
    base::flat_map<mojom::RuntimeFeature, mojom::blink::OriginTrialFeatureStatePtr> origin_trial_overrides_;
    Member<MojoBindingContext> binding_context_;
    Member<UseCounter> use_counter_;
    blink::HeapMojoRemote<mojom::blink::OriginTrialStateHost> origin_trial_state_host_remote_;

    // TODO(https://crbug.com/1410817): add support for workers/non-frames that
    // are enabling origin trials to send their information to the browser too.
    bool send_runtime_features_to_browser_ = false;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_FEATURE_STATE_RUNTIME_FEATURE_STATE_OVERRIDE_CONTEXT_H_
