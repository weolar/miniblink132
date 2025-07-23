// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/no_destructor.h"
#include "base/feature_list.h"
#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/common/permissions_policy/document_policy_features.h"
#include "third_party/blink/public/common/permissions_policy/policy_value.h"
#include "third_party/blink/public/mojom/permissions_policy/policy_value.mojom.h"
#include "third_party/blink/public/mojom/permissions_policy/document_policy_feature.mojom.h"

namespace blink {

const DocumentPolicyFeatureInfoMap& GetDocumentPolicyFeatureInfoMap()
{
    static const base::NoDestructor<DocumentPolicyFeatureInfoMap> feature_info_map([] {
        DocumentPolicyFeatureInfoMap map({
            { mojom::DocumentPolicyFeature::kDefault, { "*", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kForceLoadAtTop, { "force-load-at-top", PolicyValue::CreateBool(false) } },
            { mojom::DocumentPolicyFeature::kJSProfiling, { "js-profiling", PolicyValue::CreateBool(false) } },
            { mojom::DocumentPolicyFeature::kSyncXHR, { "sync-xhr", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kIncludeJSCallStacksInCrashReports, { "include-js-call-stacks-in-crash-reports", PolicyValue::CreateBool(false) } },
            { mojom::DocumentPolicyFeature::kExpectNoLinkedResources, { "expect-no-linked-resources", PolicyValue::CreateBool(false) } },
        });
        return map;
    }());
    return *feature_info_map;
}

const DocumentPolicyNameFeatureMap& GetDocumentPolicyNameFeatureMap()
{
    static const base::NoDestructor<DocumentPolicyNameFeatureMap> name_feature_map([] {
        DocumentPolicyNameFeatureMap map;
        for (const auto& entry : GetDocumentPolicyFeatureInfoMap())
            map.emplace(entry.second.feature_name, entry.first);
        return map;
    }());
    return *name_feature_map;
}

} // namespace blink
