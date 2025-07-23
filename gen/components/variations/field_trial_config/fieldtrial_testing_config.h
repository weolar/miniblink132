// Copyright 2025 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE SCHEMA DEFINITION AND DESCRIPTION IN
//   field_trial_testing_config_schema.json
//   fieldtrial_testing_config.json
// DO NOT EDIT.

#ifndef FIELDTRIAL_TESTING_CONFIG_H_
#define FIELDTRIAL_TESTING_CONFIG_H_

#include <cstddef>

#include <optional>

#include "base/containers/span.h"
#include "components/variations/proto/study.pb.h"

namespace variations {

struct OverrideUIString {
    const int name_hash;
    const char* const value;
};

struct FieldTrialTestingExperimentParams {
    const char* const key;
    const char* const value;
};

struct FieldTrialTestingExperiment {
    const char* const name;
    const base::span<const Study::Platform> platforms;
    const base::span<const Study::FormFactor> form_factors;
    const std::optional<bool> is_low_end_device;
    const char* const min_os_version;
    const base::span<const FieldTrialTestingExperimentParams> params;
    const base::span<const char* const> enable_features;
    const base::span<const char* const> disable_features;
    const char* const forcing_flag;
    const base::span<const OverrideUIString> override_ui_string;
    const base::span<const char* const> hardware_classes;
    const base::span<const char* const> exclude_hardware_classes;
};

struct FieldTrialTestingStudy {
    const char* const name;
    const base::span<const FieldTrialTestingExperiment> experiments;
};

struct FieldTrialTestingConfig {
    const base::span<const FieldTrialTestingStudy> studies;
};

extern const FieldTrialTestingConfig kFieldTrialConfig;

} // namespace variations

#endif // FIELDTRIAL_TESTING_CONFIG_H_
