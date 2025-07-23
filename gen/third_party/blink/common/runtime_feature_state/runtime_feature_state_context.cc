// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_feature_state_context.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/common/runtime_feature_state/runtime_feature_state_context.h"

#include "base/containers/flat_map.h"
#include "third_party/blink/public/mojom/runtime_feature_state/runtime_feature.mojom-shared.h"
#include "third_party/blink/public/common/runtime_feature_state/runtime_feature_state_read_context.h"
#include "third_party/blink/public/common/storage_key/storage_key.h"

namespace blink {

void RuntimeFeatureStateContext::PopulateInitialValues()
{
    // Write access implies read, so we are populating all inital values
    initial_values_.reserve(9);

    initial_values_.insert({ blink::mojom::RuntimeFeature::kBlinkExtensionChromeOS, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kBlinkExtensionChromeOSKiosk, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kBlinkExtensionDiagnostics, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kDisableThirdPartyStoragePartitioning2, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kFedCmAuthz, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kFedCmIdpSigninStatus, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kFedCmWithStorageAccessAPI, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kOriginTrialsSampleAPIBrowserReadWrite, false });
    initial_values_.insert({ blink::mojom::RuntimeFeature::kTestFeature, false });
}

} // namespace blink
