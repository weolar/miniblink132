// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/gpu_driver_bug_list_autogen.h"

#include <array>
#include <iterator>

#include "gpu/config/gpu_driver_bug_workaround_type.h"

namespace gpu {

const std::array<GpuControlList::Entry, 85>& GetGpuDriverBugListEntries()
{

#include "gpu/config/gpu_driver_bug_list_arrays_and_structs_autogen.h"
#include "gpu/config/gpu_driver_bug_list_exceptions_autogen.h"

    static const std::array<GpuControlList::Entry, 85> kGpuDriverBugListEntries = { {
        {
            17, // id
            "Some drivers are unable to reset the D3D device in the GPU process sandbox",
            base::span(kFeatureListForWorkaroundsEntry17), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span<const uint32_t>(), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            19, // id
            "Disable depth textures on older Adreno 2xx Qualcomm GPUs (legacy blocklist entry, original problem unclear)",
            base::span(kFeatureListForWorkaroundsEntry19), // features
            base::span(kDisabledExtensionsForEntry19), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry19), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                &kGLStringsForWorkaroundsEntry19, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            70, // id
            "Disable D3D11 on older nVidia drivers",
            base::span(kFeatureListForWorkaroundsEntry70), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry70), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry70, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            86, // id
            "Disable use of Direct3D 11 on Matrox video cards",
            base::span(kFeatureListForWorkaroundsEntry86), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry86), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x102b, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            87, // id
            "Disable use of Direct3D 11 on older AMD drivers",
            base::span(kFeatureListForWorkaroundsEntry87), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry87), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry87, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            92, // id
            "Old Intel drivers cannot reliably support D3D11",
            base::span(kFeatureListForWorkaroundsEntry92), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry92), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry92, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            132, // id
            "On Intel GPUs MSAA performance is not acceptable for GPU rasterization",
            base::span(kFeatureListForWorkaroundsEntry132), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry132), // CrBugs
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
            base::span(kExceptionsForEntry132), // exceptions
        },
        {
            165, // id
            "Unpacking overlapping rows from unpack buffers is unstable on NVIDIA GL driver",
            base::span(kFeatureListForWorkaroundsEntry165), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry165), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                &kGLStringsForWorkaroundsEntry165, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            185, // id
            "Zero-copy NV12 video displays incorrect colors on NVIDIA drivers.",
            base::span(kFeatureListForWorkaroundsEntry185), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry185), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry185, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            206, // id
            "Disable KHR_blend_equation_advanced until cc shaders are updated",
            base::span<const int>(), // features
            base::span(kDisabledExtensionsForEntry206), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry206), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            215, // id
            "Fake no-op GPU driver bug workaround for testing",
            base::span(kFeatureListForWorkaroundsEntry215), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry215), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                &kMoreForEntry215_619971032, // more data
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            219, // id
            "Zero-copy DXGI video hangs or displays incorrect colors on older AMD drivers",
            base::span(kFeatureListForWorkaroundsEntry219), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry219), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry219, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            220, // id
            "NV12 DXGI video displays incorrect colors on older AMD drivers",
            base::span(kFeatureListForWorkaroundsEntry220), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry220), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry220, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            224, // id
            "VPx decoding isn't supported well before Windows 10 creators update.",
            base::span(kFeatureListForWorkaroundsEntry224), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry224), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0.15063", nullptr }, // os_version
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            225, // id
            "VP9 decoding is too slow on Intel Broadwell, Skylake, and CherryTrail",
            base::span(kFeatureListForWorkaroundsEntry225), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry225), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry225_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            226, // id
            "Accelerated VP9 decoding is hanging on some videos.",
            base::span(kFeatureListForWorkaroundsEntry226), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry226), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry226, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            249, // id
            "Full screen video overlays causes slow presents on old Nvidia GPUs",
            base::span(kFeatureListForWorkaroundsEntry249), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry249), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span(kDevicesForWorkaroundsEntry249), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            256, // id
            "Expose WebGL's disjoint_timer_query extensions on platforms with site isolation",
            base::span(kFeatureListForWorkaroundsEntry256), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry256), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
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
            base::span(kExceptionsForEntry256), // exceptions
        },
        {
            257, // id
            "Fake entry for testing disabling of WebGL extensions",
            base::span<const int>(), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span(kDisabledWebGLExtensionsForEntry257), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry257), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                &kMoreForEntry257_619971032, // more data
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            277, // id
            "Video overlay path is buggy on certain AMD devices/drivers",
            base::span(kFeatureListForWorkaroundsEntry277), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry277), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry277, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            278, // id
            "Video overlay path is buggy on certain AMD devices/drivers",
            base::span(kFeatureListForWorkaroundsEntry278), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry278), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry278), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            286, // id
            "Video corruption on Intel HD 530 without hardware overlay support",
            base::span(kFeatureListForWorkaroundsEntry286), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry286), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForWorkaroundsEntry286), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry286, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                &kMoreForEntry286_619971032, // more data
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            300, // id
            "Direct composition causes rendering issues on Intel SandyBridge and IvyBridge GPUs on early versions of RS3",
            base::span(kFeatureListForWorkaroundsEntry300), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry300), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0.16299.0",
                    "10.0.16299.214" }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry300_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            303, // id
            "Dynamic texture map crashes on Intel drivers less than version 24",
            base::span(kFeatureListForWorkaroundsEntry303), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry303), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry303, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            304, // id
            "Per NVIDIA, software and hardware overlays don't work properly prior to this driver.",
            base::span(kFeatureListForWorkaroundsEntry304), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry304), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry304, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            309, // id
            "Don't use video processor scaling on non-Intel, non-NVIDIA GPUs and older AMD GPUs",
            base::span(kFeatureListForWorkaroundsEntry309), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry309), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span(kExceptionsForEntry309), // exceptions
        },
        {
            315, // id
            "Disable GL_MESA_framebuffer_flip_y for desktop GL",
            base::span<const int>(), // features
            base::span(kDisabledExtensionsForEntry315), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry315), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            318, // id
            "Full screen video overlays caused performance issues on AMD GPUs",
            base::span(kFeatureListForWorkaroundsEntry318), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry318), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry318), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            321, // id
            "Zero-copy DXGI video hangs or displays incorrect colors on older AMD drivers",
            base::span(kFeatureListForWorkaroundsEntry321), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry321), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry321), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry321, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            322, // id
            "Hardware overlays fail to work on older AMD drivers",
            base::span(kFeatureListForWorkaroundsEntry322), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry322), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry322, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            323, // id
            "Hardware overlays fail to work on older AMD drivers",
            base::span(kFeatureListForWorkaroundsEntry323), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry323), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry323), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry323, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            324, // id
            "dynamic textures fail to work on AMD GPUs",
            base::span(kFeatureListForWorkaroundsEntry324), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry324), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            328, // id
            "Disable D3D11VideoDecoder due to crashes on NVIDIA on older drivers",
            base::span(kFeatureListForWorkaroundsEntry328), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry328), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry328, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            329, // id
            "Limit D3D11VideoDecoder to 11.0 due to crashes on AMD",
            base::span(kFeatureListForWorkaroundsEntry329), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry329), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            337, // id
            "Disable hardware MFT H.264 encoder on older NVIDIA drivers",
            base::span(kFeatureListForWorkaroundsEntry337), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry337), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry337, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            338, // id
            "Disable hardware overlay on icelake with older Intel drivers",
            base::span(kFeatureListForWorkaroundsEntry338), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry338), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry338, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry338_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            339, // id
            "Binding video decoder textures triggers crash on Intel driver 20.19.15.*",
            base::span(kFeatureListForWorkaroundsEntry339), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry339), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry339, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry339_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            340, // id
            "Binding video decoder textures triggers crash on Intel driver 10.18.15.*",
            base::span(kFeatureListForWorkaroundsEntry340), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry340), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry340, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry340_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            343, // id
            "Disable using GPU backed resource for imageBitmap from video on d3d9",
            base::span(kFeatureListForWorkaroundsEntry343), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry343), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                &kGLStringsForWorkaroundsEntry343, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            344, // id
            "VP8 decoding crashes before Windows 10 Fall Creators Update.",
            base::span(kFeatureListForWorkaroundsEntry344), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry344), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0.16299", nullptr }, // os_version
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            345, // id
            "Disable DecodeSwapChain for Intel Gen9 and older devices",
            base::span(kFeatureListForWorkaroundsEntry345), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry345), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry345_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            346, // id
            "Enable HDR video playing through overlay on Intel",
            base::span(kFeatureListForWorkaroundsEntry346), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry346), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry346_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            347, // id
            "Intel GPUs fail to report BGRA8 overlay support",
            base::span(kFeatureListForWorkaroundsEntry347), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry347), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            352, // id
            "Intel device 0x1066 can't use d3d11 video decoder",
            base::span(kFeatureListForWorkaroundsEntry352), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry352), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForWorkaroundsEntry352), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            353, // id
            "Intel device 0x8a56 with specific drivers can't use d3d11 video decoder",
            base::span(kFeatureListForWorkaroundsEntry353), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry353), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForWorkaroundsEntry353), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry353, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            354, // id
            "AMD device 98e4 with specific drivers can't use d3d11 video decoder",
            base::span(kFeatureListForWorkaroundsEntry354), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry354), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry354), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry354, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            360, // id
            "8x MSAA for WebGL contexts is slow on Win Intel",
            base::span(kFeatureListForWorkaroundsEntry360), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry360), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            362, // id
            "Promote 2 videos to hardware overlays on Windows Intel platforms",
            base::span(kFeatureListForWorkaroundsEntry362), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry362), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry362_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            364, // id
            "Software overlays fail to work reliably on AMD devices",
            base::span(kFeatureListForWorkaroundsEntry364), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry364), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            371, // id
            "Disable software overlays for Intel GPUs. All Skylake+ devices support hw overlays, older devices peform poorly.",
            base::span(kFeatureListForWorkaroundsEntry371), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry371), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            372, // id
            "Check YCbCr_Studio_G22_Left_P709 color space for NV12 overlay support on Intel",
            base::span(kFeatureListForWorkaroundsEntry372), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry372), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry372_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            376, // id
            "Don't use Media Foundation hardware security on Turing-architecture NVIDIA GPUs.",
            base::span(kFeatureListForWorkaroundsEntry376), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry376), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span(kDevicesForWorkaroundsEntry376), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry376, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            377, // id
            "Don't use Media Foundation hardware security on Pascal-architecture NVIDIA GPUs.",
            base::span(kFeatureListForWorkaroundsEntry377), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry377), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span(kDevicesForWorkaroundsEntry377), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry377, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            380, // id
            "Intel GPUs do not promote downscaled overlays",
            base::span(kFeatureListForWorkaroundsEntry380), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry380), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0", nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry380_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            387, // id
            "Windows hardware decoding doesn't support a set of legacy AMD GPUs",
            base::span(kFeatureListForWorkaroundsEntry387), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry387), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry387), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            388, // id
            "Windows hardware decoding doesn't support a set of legacy Intel GPUs",
            base::span(kFeatureListForWorkaroundsEntry388), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry388), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForWorkaroundsEntry388), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            390, // id
            "AVC/AV1 hardware encoder MFT output bitrate incorrect upon framerate update on Intel GPUs.",
            base::span(kFeatureListForWorkaroundsEntry390), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry390), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry390, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            391, // id
            "Skia ReduceOpsTaskSplitting causes artifacts on Intel Skylake",
            base::span(kFeatureListForWorkaroundsEntry391), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry391), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry391_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            394, // id
            "Only enable video processor super resolution on Intel Gen10+ GPUs and NVIDIA GPUs with 530+ drivers",
            base::span(kFeatureListForWorkaroundsEntry394), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry394), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span(kExceptionsForEntry394), // exceptions
        },
        {
            395, // id
            "Don't use MPO on Intel TigerLake GPUs with old drivers due to VideoProcessorBlt crash.",
            base::span(kFeatureListForWorkaroundsEntry395), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry395), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry395, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry395_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            397, // id
            "VPx decoding crashes due to a buggy driver / chipset combo.",
            base::span(kFeatureListForWorkaroundsEntry397), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry397), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForWorkaroundsEntry397), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry397, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            398, // id
            "On pre-Ice Lake Intel GPUs MSAA performance is not acceptable for GPU rasterization",
            base::span(kFeatureListForWorkaroundsEntry398), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry398), // CrBugs
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
                &kIntelConditionsForEntry398_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span(kExceptionsForEntry398), // exceptions
        },
        {
            403, // id
            "Disable hardware MFT Av1 encoder on machines with multiple GPUs except Intel alchemist GPUs",
            base::span(kFeatureListForWorkaroundsEntry403), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry403), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                &kMoreForEntry403_619971032, // more data
            },
            base::span(kExceptionsForEntry403), // exceptions
        },
        {
            406, // id
            "VP9 decoder rejects submitted bitstream buffer on some old Intel drivers.",
            base::span(kFeatureListForWorkaroundsEntry406), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry406), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry406, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            408, // id
            "Disable Media Foundation Clear Playback on older AMD drivers.",
            base::span(kFeatureListForWorkaroundsEntry408), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span<const uint32_t>(), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry408, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            411, // id
            "Disable VP9 HW encode on Intel GPU with old drivers",
            base::span(kFeatureListForWorkaroundsEntry411), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry411), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry411, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            412, // id
            "Disable VP9 HW encode on Intel GPUs preceding Ice Lake",
            base::span(kFeatureListForWorkaroundsEntry412), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry412), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry412_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            413, // id
            "Force to use the triple buffer video swap chain of direct composition",
            base::span(kFeatureListForWorkaroundsEntry413), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry413), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry413_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            414, // id
            "Only enable video processor auto HDR on NVIDIA GPUs with 550.50+ driver",
            base::span(kFeatureListForWorkaroundsEntry414), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry414), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span(kExceptionsForEntry414), // exceptions
        },
        {
            417, // id
            "Limit D3D11VideoDecoder to 11.0 due to failures on QC chipsets.",
            base::span(kFeatureListForWorkaroundsEntry417), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span<const uint32_t>(), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x4d4f4351, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            419, // id
            "Corruption when consecutive VP9 keyframes are requested from MFVEA on Intel.",
            base::span(kFeatureListForWorkaroundsEntry419), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry419), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            420, // id
            "GPU process crash when decoding HEVC on Intel with specific drivers.",
            base::span(kFeatureListForWorkaroundsEntry420), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry420), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry420, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            424, // id
            "Disable SVC video encoding on AMD GPUs that can't change bitrate in SVC mode",
            base::span(kFeatureListForWorkaroundsEntry424), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry424), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry424, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            426, // id
            "Disable VP9 k-SVC video decoding on non-Intel GPUs",
            base::span(kFeatureListForWorkaroundsEntry426), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry426), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span(kExceptionsForEntry426), // exceptions
        },
        {
            427, // id
            "Disable encoding frame size change on Intel Kaby Lake G devices with old Radeon Pro WX Vega M GL graphics drivers",
            base::span(kFeatureListForWorkaroundsEntry427), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span<const uint32_t>(), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry427), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry427, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            428, // id
            "Don't use Media Foundation hardware security on Polaris-architecture AMD GPUs.",
            base::span(kFeatureListForWorkaroundsEntry428), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry428), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForWorkaroundsEntry428), // Devices
                GpuControlList::kMultiGpuCategoryActive, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            429, // id
            "Updating multiplanar textures crashes in UpdateSubresourc1() with old Intel driver",
            base::span(kFeatureListForWorkaroundsEntry429), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry429), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry429, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            430, // id
            "Block all NPU drivers except Intel driver versions >= 32.0.100.3053 for WebNN",
            base::span(kFeatureListForWorkaroundsEntry430), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry430), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNpu, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span(kExceptionsForEntry430), // exceptions
        },
        {
            431, // id
            "Disable VP9 temporal layer encoding acceleration on Intel GPUs preceding Rocket Lake",
            base::span(kFeatureListForWorkaroundsEntry431), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry431), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry431_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            432, // id
            "Disable VP9 temporal layer encoding acceleration on Intel GPUs with older drivers",
            base::span(kFeatureListForWorkaroundsEntry432), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry432), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry432, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            433, // id
            "Qualcomm GPUs have driver bugs preventing WebNN from working correctly",
            base::span(kFeatureListForWorkaroundsEntry433), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry433), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x4d4f4351, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            434, // id
            "Disable CBR encoding of HEVC on Intel GPUs with older drivers",
            base::span(kFeatureListForWorkaroundsEntry434), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry434), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry434, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            436, // id
            "Disable overlay promotion for clear video quads when their MPO quads would move",
            base::span(kFeatureListForWorkaroundsEntry436), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry436), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
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
            base::span(kExceptionsForEntry436), // exceptions
        },
        {
            437, // id
            "AV1 RTC decoding may crash driver on some of the Intel devices",
            base::span(kFeatureListForWorkaroundsEntry437), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry437), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                &kIntelConditionsForEntry437_619971032, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            438, // id
            "Disable DirectML execution of metacommands on Intel GPUs with driver version between 31.0.101.5518 and 32.0.101.6083 due to stability bugs",
            base::span(kFeatureListForWorkaroundsEntry438), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForWorkaroundsEntry438), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForWorkaroundsEntry438, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
    } };
    return kGpuDriverBugListEntries;
}
} // namespace gpu
