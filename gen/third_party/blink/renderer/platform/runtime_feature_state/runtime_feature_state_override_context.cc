// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_feature_state_override_context.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_feature.mojom-shared.h"
#include "third_party/blink/public/common/thread_safe_browser_interface_broker_proxy.h"
#include "third_party/blink/public/mojom/origin_trials/origin_trial_state_host.mojom-blink.h"
#include "third_party/blink/public/platform/platform.h"
#include "third_party/blink/renderer/core/frame/web_feature.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"
#include "third_party/blink/renderer/platform/runtime_feature_state/runtime_feature_state_override_context.h"

namespace blink {

void RuntimeFeatureStateOverrideContext::ApplyOverrideValuesFromParams(const base::flat_map<mojom::RuntimeFeature, bool>& values_from_params)
{
    for (const auto& override_value : values_from_params) {
        override_values_[override_value.first] = override_value.second;
    }
}

bool RuntimeFeatureStateOverrideContext::IsBlinkExtensionChromeOSForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kBlinkExtensionChromeOS);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsBlinkExtensionChromeOSForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kBlinkExtensionChromeOS);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetBlinkExtensionChromeOSForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kBlinkExtensionChromeOS] = false;
}

void RuntimeFeatureStateOverrideContext::SetBlinkExtensionChromeOSForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kBlinkExtensionChromeOS] = true;
}

bool RuntimeFeatureStateOverrideContext::IsBlinkExtensionChromeOSKioskForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kBlinkExtensionChromeOSKiosk);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsBlinkExtensionChromeOSKioskForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kBlinkExtensionChromeOSKiosk);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetBlinkExtensionChromeOSKioskForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kBlinkExtensionChromeOSKiosk] = false;
}

void RuntimeFeatureStateOverrideContext::SetBlinkExtensionChromeOSKioskForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kBlinkExtensionChromeOSKiosk] = true;
}

bool RuntimeFeatureStateOverrideContext::IsBlinkExtensionDiagnosticsForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kBlinkExtensionDiagnostics);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsBlinkExtensionDiagnosticsForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kBlinkExtensionDiagnostics);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetBlinkExtensionDiagnosticsForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kBlinkExtensionDiagnostics] = false;
}

void RuntimeFeatureStateOverrideContext::SetBlinkExtensionDiagnosticsForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kBlinkExtensionDiagnostics] = true;
}

bool RuntimeFeatureStateOverrideContext::IsDisableThirdPartyStoragePartitioning2ForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsDisableThirdPartyStoragePartitioning2ForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetDisableThirdPartyStoragePartitioning2ForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2] = false;
}

void RuntimeFeatureStateOverrideContext::SetDisableThirdPartyStoragePartitioning2ForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2] = true;
}

bool RuntimeFeatureStateOverrideContext::SetDisableThirdPartyStoragePartitioning2Enabled(const WTF::Vector<WTF::String>& tokens)
{
    UseCounter::Count(use_counter_, WebFeature::kDisableThirdPartyStoragePartitioning2);
    // If the base::Feature for the deprecation trial is disabled, we should
    // not send any overrides to the browser, so we return false immediately,
    // skipping any mojom messaging.
    if (!base::FeatureList::IsEnabled(blink::features::kDisableThirdPartyStoragePartitioningDeprecationTrial2)) {
        return false;
    }
    // Origin Trial feature values should not override any sent from
    // the browser, so we only add a value if has not already been set
    // in the override_values_ map with an identical token set. Return
    // whether the override was successful.
    auto value = mojom::blink::OriginTrialFeatureState::New(true, tokens);
    if (!override_values_.contains(mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2)
        || origin_trial_overrides_[mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2] != value) {
        // Update the state of all feature overrides in this class.
        override_values_[mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2] = true;
        // Add successful overrides to the list of features we sent back
        // to the browser process.
        origin_trial_overrides_[mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2] = std::move(value);
        return true;
    }
    return false;
}
bool RuntimeFeatureStateOverrideContext::IsFedCmAuthzForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kFedCmAuthz);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsFedCmAuthzForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kFedCmAuthz);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetFedCmAuthzForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kFedCmAuthz] = false;
}

void RuntimeFeatureStateOverrideContext::SetFedCmAuthzForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kFedCmAuthz] = true;
}

bool RuntimeFeatureStateOverrideContext::SetFedCmAuthzEnabled(const WTF::Vector<WTF::String>& tokens)
{
    // Origin Trial feature values should not override any sent from
    // the browser, so we only add a value if has not already been set
    // in the override_values_ map with an identical token set. Return
    // whether the override was successful.
    auto value = mojom::blink::OriginTrialFeatureState::New(true, tokens);
    if (!override_values_.contains(mojom::RuntimeFeature::kFedCmAuthz) || origin_trial_overrides_[mojom::RuntimeFeature::kFedCmAuthz] != value) {
        // Update the state of all feature overrides in this class.
        override_values_[mojom::RuntimeFeature::kFedCmAuthz] = true;
        // Add successful overrides to the list of features we sent back
        // to the browser process.
        origin_trial_overrides_[mojom::RuntimeFeature::kFedCmAuthz] = std::move(value);
        return true;
    }
    return false;
}
bool RuntimeFeatureStateOverrideContext::IsFedCmIdpSigninStatusForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kFedCmIdpSigninStatus);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsFedCmIdpSigninStatusForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kFedCmIdpSigninStatus);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetFedCmIdpSigninStatusForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kFedCmIdpSigninStatus] = false;
}

void RuntimeFeatureStateOverrideContext::SetFedCmIdpSigninStatusForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kFedCmIdpSigninStatus] = true;
}

bool RuntimeFeatureStateOverrideContext::IsFedCmWithStorageAccessAPIForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kFedCmWithStorageAccessAPI);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsFedCmWithStorageAccessAPIForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kFedCmWithStorageAccessAPI);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetFedCmWithStorageAccessAPIForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kFedCmWithStorageAccessAPI] = false;
}

void RuntimeFeatureStateOverrideContext::SetFedCmWithStorageAccessAPIForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kFedCmWithStorageAccessAPI] = true;
}

bool RuntimeFeatureStateOverrideContext::SetFedCmWithStorageAccessAPIEnabled(const WTF::Vector<WTF::String>& tokens)
{
    // Origin Trial feature values should not override any sent from
    // the browser, so we only add a value if has not already been set
    // in the override_values_ map with an identical token set. Return
    // whether the override was successful.
    auto value = mojom::blink::OriginTrialFeatureState::New(true, tokens);
    if (!override_values_.contains(mojom::RuntimeFeature::kFedCmWithStorageAccessAPI)
        || origin_trial_overrides_[mojom::RuntimeFeature::kFedCmWithStorageAccessAPI] != value) {
        // Update the state of all feature overrides in this class.
        override_values_[mojom::RuntimeFeature::kFedCmWithStorageAccessAPI] = true;
        // Add successful overrides to the list of features we sent back
        // to the browser process.
        origin_trial_overrides_[mojom::RuntimeFeature::kFedCmWithStorageAccessAPI] = std::move(value);
        return true;
    }
    return false;
}
bool RuntimeFeatureStateOverrideContext::IsOriginTrialsSampleAPIBrowserReadWriteForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsOriginTrialsSampleAPIBrowserReadWriteForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetOriginTrialsSampleAPIBrowserReadWriteForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite] = false;
}

void RuntimeFeatureStateOverrideContext::SetOriginTrialsSampleAPIBrowserReadWriteForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite] = true;
}

bool RuntimeFeatureStateOverrideContext::SetOriginTrialsSampleAPIBrowserReadWriteEnabled(const WTF::Vector<WTF::String>& tokens)
{
    // Origin Trial feature values should not override any sent from
    // the browser, so we only add a value if has not already been set
    // in the override_values_ map with an identical token set. Return
    // whether the override was successful.
    auto value = mojom::blink::OriginTrialFeatureState::New(true, tokens);
    if (!override_values_.contains(mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite)
        || origin_trial_overrides_[mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite] != value) {
        // Update the state of all feature overrides in this class.
        override_values_[mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite] = true;
        // Add successful overrides to the list of features we sent back
        // to the browser process.
        origin_trial_overrides_[mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite] = std::move(value);
        return true;
    }
    return false;
}
bool RuntimeFeatureStateOverrideContext::IsTestFeatureForceDisabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kTestFeature);
    if (it != override_values_.end() && it->second == false)
        return true;

    return false;
}

bool RuntimeFeatureStateOverrideContext::IsTestFeatureForceEnabled() const
{
    auto it = override_values_.find(mojom::RuntimeFeature::kTestFeature);
    if (it != override_values_.end() && it->second == true)
        return true;

    return false;
}

void RuntimeFeatureStateOverrideContext::SetTestFeatureForceDisabled()
{
    override_values_[mojom::RuntimeFeature::kTestFeature] = false;
}

void RuntimeFeatureStateOverrideContext::SetTestFeatureForceEnabled()
{
    override_values_[mojom::RuntimeFeature::kTestFeature] = true;
}

void RuntimeFeatureStateOverrideContext::ApplyOriginTrialOverride(
    const blink::mojom::blink::OriginTrialFeature& origin_trial_feature, const WTF::Vector<WTF::String>& tokens)
{
    // Determine which of the overrideable features has been set
    // via Origin Trial.
    bool overridden = false;
    if (origin_trial_feature == blink::mojom::blink::OriginTrialFeature::kDisableThirdPartyStoragePartitioning2) {
        overridden = SetDisableThirdPartyStoragePartitioning2Enabled(tokens);
    }
    if (origin_trial_feature == blink::mojom::blink::OriginTrialFeature::kFedCmAuthz) {
        overridden = SetFedCmAuthzEnabled(tokens);
    }
    if (origin_trial_feature == blink::mojom::blink::OriginTrialFeature::kFedCmWithStorageAccessAPI) {
        overridden = SetFedCmWithStorageAccessAPIEnabled(tokens);
    }
    if (origin_trial_feature == blink::mojom::blink::OriginTrialFeature::kOriginTrialsSampleAPIBrowserReadWrite) {
        overridden = SetOriginTrialsSampleAPIBrowserReadWriteEnabled(tokens);
    }
    // Send the newly overriden values to the browser via IPC.
    if (overridden) {
        // We must convert from std:: types to WTF:: types.
        // TODO(https://crbug.com/1377000): make origin_trial_overrides_ a
        // WTF:: type in a follow-up CL.
        WTF::HashMap<mojom::blink::RuntimeFeature, mojom::blink::OriginTrialFeatureStatePtr> blink_overrides;
        for (auto& o : origin_trial_overrides_) {
            blink_overrides.insert(o.first, std::move(o.second));
        }
        // Feature overrides and origin trial information should only be
        // sent to the browser process if the corresponding base::Feature
        // is enabled.
        if (base::FeatureList::IsEnabled(blink::features::kOriginTrialStateHostApplyFeatureDiff)) {
            GetOrBindOriginTrialStateHost()->ApplyFeatureDiffForOriginTrial(std::move(blink_overrides));
        }
        // TODO(https://crbug.com/1377000): when we convert to WTF:: types,
        // we use std::move, so we have to do some cleanup.
        origin_trial_overrides_.clear();
    }
}

void RuntimeFeatureStateOverrideContext::EnablePersistentTrial(
    const WTF::String& raw_token, const WTF::Vector<scoped_refptr<const blink::SecurityOrigin>>& script_origins)
{
    GetOrBindOriginTrialStateHost()->EnablePersistentTrial(raw_token, script_origins);
}

mojom::blink::OriginTrialStateHost* RuntimeFeatureStateOverrideContext::GetOrBindOriginTrialStateHost()
{
    // It's possible that the prior interface we bound is no longer available
    // in which case we should reset the connection and re-bind a new one.
    if (origin_trial_state_host_remote_.is_bound() && !origin_trial_state_host_remote_.is_connected()) {
        origin_trial_state_host_remote_.reset();
    }
    // TODO(https://crbug.com/1410817): add support for workers/non-frames that
    // are enabling origin trials to send their information to the browser too.
    if (!origin_trial_state_host_remote_.is_bound()) {
        CHECK(send_runtime_features_to_browser_);
        binding_context_->GetBrowserInterfaceBroker().GetInterface(
            origin_trial_state_host_remote_.BindNewPipeAndPassReceiver(binding_context_->GetTaskRunner(TaskType::kInternalDefault)));
    }
    return origin_trial_state_host_remote_.get();
}

void RuntimeFeatureStateOverrideContext::Trace(Visitor* visitor) const
{
    visitor->Trace(binding_context_);
    visitor->Trace(use_counter_);
    visitor->Trace(origin_trial_state_host_remote_);
}

} // namespace blink
