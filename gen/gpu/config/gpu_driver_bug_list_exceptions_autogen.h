// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#ifndef GPU_CONFIG_GPU_DRIVER_BUG_LIST_EXCEPTIONS_AUTOGEN_H_
#define GPU_CONFIG_GPU_DRIVER_BUG_LIST_EXCEPTIONS_AUTOGEN_H_

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry132 = { {
    {
        GpuControlList::kOsFuchsia, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x00, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry256 = { {
    {
        GpuControlList::kOsAndroid, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x00, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 3> kExceptionsForEntry309 = { {
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x8086, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x10de, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x1002, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry309Exception2, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 2> kExceptionsForEntry394 = { {
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x8086, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry394Exception0, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        &kIntelConditionsForEntry394_619971032Exception0, // Intel conditions
        nullptr, // more conditions
    },
    {
        GpuControlList::kOsWin, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x10de, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry394Exception1, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry398 = { {
    {
        GpuControlList::kOsFuchsia, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x00, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry403 = { {
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x8086, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry403Exception0, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        &kIntelConditionsForEntry403_619971032Exception0, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry414 = { {
    {
        GpuControlList::kOsWin, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x10de, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry414Exception0, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry426 = { {
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x8086, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryActive, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 1> kExceptionsForEntry430 = { {
    {
        GpuControlList::kOsAny, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x8086, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNpu, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry430Exception0, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

static const std::array<GpuControlList::Conditions, 2> kExceptionsForEntry436 = { {
    {
        GpuControlList::kOsWin, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x8086, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        &kDriverInfoForWorkaroundsEntry436Exception0, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
    {
        GpuControlList::kOsWin, // os_type
        { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
        0x10de, // vendor_id
        base::span<const GpuControlList::Device>(), // Devices
        GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
        GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
        nullptr, // driver info
        nullptr, // GL strings
        nullptr, // machine model info
        nullptr, // Intel conditions
        nullptr, // more conditions
    },
} };

#endif // GPU_CONFIG_GPU_DRIVER_BUG_LIST_EXCEPTIONS_AUTOGEN_H_
