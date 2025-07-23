// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/software_rendering_list_autogen.h"

#include <array>
#include <iterator>

#include "gpu/config/gpu_feature_type.h"

namespace gpu {

const std::array<GpuControlList::Entry, 39>& GetSoftwareRenderingListEntries()
{

#include "gpu/config/software_rendering_list_arrays_and_structs_autogen.h"
#include "gpu/config/software_rendering_list_exceptions_autogen.h"

    static const std::array<GpuControlList::Entry, 39> kSoftwareRenderingListEntries = { {
        {
            4, // id
            "The Intel Mobile 945 Express family of chipsets is not compatible with WebGL",
            base::span(kFeatureListForSoftwareEntry4), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry4), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForSoftwareEntry4), // Devices
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
            8, // id
            "NVIDIA GeForce FX Go5200 is assumed to be buggy",
            base::span(kFeatureListForSoftwareEntry8), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry8), // CrBugs
            {
                GpuControlList::kOsAny, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span(kDevicesForSoftwareEntry8), // Devices
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
            34, // id
            "S3 Trio (used in Virtual PC) is not compatible",
            base::span(kFeatureListForSoftwareEntry34), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry34), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x5333, // vendor_id
                base::span(kDevicesForSoftwareEntry34), // Devices
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
            45, // id
            "Parallels drivers older than 7 are buggy",
            base::span(kFeatureListForSoftwareEntry45), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry45), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1ab8, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry45, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            46, // id
            "ATI FireMV 2400 cards on Windows are buggy",
            base::span(kFeatureListForSoftwareEntry46), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry46), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span(kDevicesForSoftwareEntry46), // Devices
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
            59, // id
            "NVidia driver 185.93 is crashy on Windows",
            base::span(kFeatureListForSoftwareEntry59), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry59), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry59, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            68, // id
            "Do not use GPU accelerated rendering with VMware on Windows",
            base::span(kFeatureListForSoftwareEntry68), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry68), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x15ad, // vendor_id
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
            72, // id
            "NVIDIA GeForce 6200 LE is buggy with WebGL",
            base::span(kFeatureListForSoftwareEntry72), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry72), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span(kDevicesForSoftwareEntry72), // Devices
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
            74, // id
            "GPU access is blocked if users don't have proper graphics driver installed after Windows installation",
            base::span(kFeatureListForSoftwareEntry74), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry74), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1414, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span(kExceptionsForEntry74), // exceptions
        },
        {
            78, // id
            "Accelerated video decode interferes with GPU sandbox on older Intel drivers",
            base::span(kFeatureListForSoftwareEntry78), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry78), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry78, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            86, // id
            "Intel Graphics Media Accelerator 3150 causes the GPU process to hang running WebGL",
            base::span(kFeatureListForSoftwareEntry86), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry86), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForSoftwareEntry86), // Devices
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
            "Accelerated video decode on Intel driver 10.18.10.3308 is incompatible with the GPU sandbox",
            base::span(kFeatureListForSoftwareEntry87), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry87), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry87, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            90, // id
            "Accelerated video decode interferes with GPU sandbox on certain NVIDIA drivers",
            base::span(kFeatureListForSoftwareEntry90), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry90), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry90, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            91, // id
            "Accelerated video decode interferes with GPU sandbox on certain NVIDIA drivers",
            base::span(kFeatureListForSoftwareEntry91), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry91), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry91, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            92, // id
            "Accelerated video decode does not work with the discrete GPU on AMD switchables",
            base::span(kFeatureListForSoftwareEntry92), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry92), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x00, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleAMDSwitchableDiscrete, // multi_gpu_style
                nullptr, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            94, // id
            "Intel driver version 8.15.10.1749 causes GPU process hangs.",
            base::span(kFeatureListForSoftwareEntry94), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry94), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry94, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            122, // id
            "GPU rasterization should only be enabled on NVIDIA, Intel, AMD RX-R2 GPUs with DX11+, certain QC devices+drivers or any GPU using ANGLE's GL "
            "backend.",
            base::span(kFeatureListForSoftwareEntry122), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry122), // CrBugs
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
            base::span(kExceptionsForEntry122), // exceptions
        },
        {
            124, // id
            "Some AMD drivers have rendering glitches with GPU Rasterization",
            base::span(kFeatureListForSoftwareEntry124), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry124), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry124, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span(kExceptionsForEntry124), // exceptions
        },
        {
            136, // id
            "GPU rasterization is blocklisted on NVidia Fermi architecture for now.",
            base::span(kFeatureListForSoftwareEntry136), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry136), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span(kDevicesForSoftwareEntry136), // Devices
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
            139, // id
            "GPU Rasterization is disabled on pre-GCN AMD cards",
            base::span(kFeatureListForSoftwareEntry139), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry139), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry139, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            142, // id
            "Disable D3D11/WebGL2 on older nVidia drivers",
            base::span(kFeatureListForSoftwareEntry142), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry142), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry142, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            143, // id
            "Disable use of D3D11/WebGL2 on Matrox video cards",
            base::span(kFeatureListForSoftwareEntry143), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry143), // CrBugs
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
            144, // id
            "Disable use of D3D11/WebGL2 on older AMD drivers",
            base::span(kFeatureListForSoftwareEntry144), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry144), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry144, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            145, // id
            "Old Intel drivers cannot reliably support D3D11/WebGL2",
            base::span(kFeatureListForSoftwareEntry145), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry145), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry145, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            152, // id
            "Test entry where all features except WebGL blocklisted",
            base::span(kFeatureListForSoftwareEntry152), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span<const uint32_t>(), // CrBugs
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
                &kMoreForEntry152_1043157500, // more data
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            153, // id
            "Test entry where WebGL is blocklisted",
            base::span(kFeatureListForSoftwareEntry153), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span<const uint32_t>(), // CrBugs
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
                &kMoreForEntry153_1043157500, // more data
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            163, // id
            "Intel drivers older than 2010 on Windows are possibly unreliable",
            base::span(kFeatureListForSoftwareEntry163), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry163), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry163, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            164, // id
            "NVidia drivers older than 2010 on Windows are possibly unreliable",
            base::span(kFeatureListForSoftwareEntry164), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry164), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry164, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            165, // id
            "Accelerated video decode is broken with some older Intel drivers.",
            base::span(kFeatureListForSoftwareEntry165), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry165), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry165, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            166, // id
            "8.17.10.* AMD drivers are buggy Please update your graphics driver via this link: "
            "https://www.amd.com/en/support/apu/amd-series-processors/amd-a8-series-apu-for-laptops/a8-5550m-radeon-hd-8550g",
            base::span(kFeatureListForSoftwareEntry166), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry166), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry166, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span(kExceptionsForEntry166), // exceptions
        },
        {
            167, // id
            "8.17.10.* AMD drivers trigger hangs in video stack",
            base::span(kFeatureListForSoftwareEntry167), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry167), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x1002, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry167, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            170, // id
            "Disable hardware MFT video encoder on older Intel drivers",
            base::span(kFeatureListForSoftwareEntry170), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry170), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry170, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            171, // id
            "Disable hardware MFT video encoder on older Intel drivers",
            base::span(kFeatureListForSoftwareEntry171), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry171), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry171, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            172, // id
            "Disable hardware MFT video encoder on older Intel drivers",
            base::span(kFeatureListForSoftwareEntry172), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry172), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry172, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            173, // id
            "Disable hardware MFT video encoder on older Intel drivers",
            base::span(kFeatureListForSoftwareEntry173), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry173), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry173, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            175, // id
            "Disable video encoding on NVidia drivers older than summer 2018",
            base::span(kFeatureListForSoftwareEntry175), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry175), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry175, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            181, // id
            "Corrupted browser/webpage rendering on Win10/Intel HD Graphics 4400",
            base::span(kFeatureListForSoftwareEntry181), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry181), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
                0x8086, // vendor_id
                base::span(kDevicesForSoftwareEntry181), // Devices
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
            182, // id
            "Accelerated video decoding fails with SkiaGraphite on win10+nvidia",
            base::span(kFeatureListForSoftwareEntry182), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry182), // CrBugs
            {
                GpuControlList::kOsWin, // os_type
                { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0.22621", nullptr }, // os_version
                0x10de, // vendor_id
                base::span<const GpuControlList::Device>(), // Devices
                GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
                GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
                &kDriverInfoForSoftwareEntry182, // driver info
                nullptr, // GL strings
                nullptr, // machine model info
                nullptr, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
        {
            183, // id
            "Analytic clipping is not implemented in Graphite",
            base::span(kFeatureListForSoftwareEntry183), // features
            base::span<const char* const>(), // DisabledExtensions
            base::span<const char* const>(), // DisabledWebGLExtensions
            base::span(kCrBugsForSoftwareEntry183), // CrBugs
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
                &kIntelConditionsForEntry183_1043157500, // Intel conditions
                nullptr, // more conditions
            },
            base::span<const GpuControlList::Conditions>(), // exceptions
        },
    } };
    return kSoftwareRenderingListEntries;
}
} // namespace gpu
