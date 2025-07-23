// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#ifndef GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_
#define GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_

static const std::array<int, 1> kFeatureListForWorkaroundsEntry17 = {
    EXIT_ON_CONTEXT_LOST,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry19 = {
    DISABLE_DEPTH_TEXTURE,
};

static const std::array<const char* const, 1> kDisabledExtensionsForEntry19 = {
    "GL_OES_depth_texture",
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry19 = {
    682075,
    1042214,
};

static const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry19 = {
    nullptr,
    "Adreno \\(TM\\) 2.*",
    nullptr,
    nullptr,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry70 = {
    DISABLE_D3D11,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry70 = {
    349929,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry70 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.17.12.6973", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry86 = {
    DISABLE_D3D11,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry86 = {
    395861,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry87 = {
    DISABLE_D3D11,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry87 = {
    402134,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry87 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.17.10.1070", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry92 = {
    DISABLE_D3D11,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry92 = {
    363721,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry92 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9.18.0.0", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry132 = {
    MSAA_IS_SLOW,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry132 = {
    527565,
    1298585,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry165 = {
    UNPACK_OVERLAPPING_ROWS_SEPARATELY_UNPACK_BUFFER,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry165 = {
    596774,
};

static const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry165 = {
    "NVIDIA.*",
    nullptr,
    nullptr,
    nullptr,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry185 = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry185 = {
    635319,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry185 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.21.13.7576", nullptr }, // driver_version
};

static const std::array<const char* const, 2> kDisabledExtensionsForEntry206 = {
    "GL_KHR_blend_equation_advanced",
    "GL_KHR_blend_equation_advanced_coherent",
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry206 = {
    661715,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry215 = {
    USE_GPU_DRIVER_WORKAROUND_FOR_TESTING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry215 = {
    682912,
};

static const GpuControlList::More kMoreForEntry215_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    1, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry219 = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry219 = {
    623029,
    1025427,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry219 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "23.20.826.5120", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry220 = {
    DISABLE_NV12_DXGI_VIDEO,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry220 = {
    644293,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry220 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.19.519.2", nullptr }, // driver_version
};

static const std::array<int, 2> kFeatureListForWorkaroundsEntry224 = {
    DISABLE_ACCELERATED_VP8_DECODE,
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry224 = {
    616318,
    667532,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry225 = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry225 = {
    616318,
};

static const std::array<IntelGpuSeriesType, 3> kIntelGpuSeriesForEntry225 = { {
    IntelGpuSeriesType::kBroadwell,
    IntelGpuSeriesType::kSkylake,
    IntelGpuSeriesType::kCherrytrail,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry225_619971032 = {
    base::span(kIntelGpuSeriesForEntry225), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry226 = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry226 = {
    654111,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry226 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.20.16.4542", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry249 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry249 = {
    775898,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry249 = { {
    { 0x10d8, 0x0 },
} };

static const std::array<int, 1> kFeatureListForWorkaroundsEntry256 = {
    ENABLE_WEBGL_TIMER_QUERY_EXTENSIONS,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry256 = {
    808744,
    870491,
};

static const std::array<const char* const, 1> kDisabledWebGLExtensionsForEntry257 = {
    "WEBGL_lose_context",
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry257 = {
    808744,
};

static const GpuControlList::More kMoreForEntry257_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    2, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry277 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry277 = {
    800950,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry277 = {
    nullptr, // driver_vendor
    { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.17.10.1129", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry278 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry278 = {
    800950,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry278 = { {
    { 0x6900, 0x0 },
} };

static const std::array<int, 1> kFeatureListForWorkaroundsEntry286 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry286 = {
    908069,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry286 = { {
    { 0x1912, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry286 = {
    nullptr, // driver_vendor
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaIntelDriver, "0.0.100.0", nullptr }, // driver_version
};

static const GpuControlList::More kMoreForEntry286_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kUnsupported, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry300 = {
    DISABLE_DIRECT_COMPOSITION,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry300 = {
    775898,
    785648,
};

static const std::array<IntelGpuSeriesType, 2> kIntelGpuSeriesForEntry300 = { {
    IntelGpuSeriesType::kSandybridge,
    IntelGpuSeriesType::kIvybridge,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry300_619971032 = {
    base::span(kIntelGpuSeriesForEntry300), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry303 = {
    DISABLE_NV12_DYNAMIC_TEXTURES,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry303 = {
    890227,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry303 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaIntelDriver, "0.0.99.9999", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry304 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry304 = {
    911349,
    1113893,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry304 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaNvidiaDriver, "456.38", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry309 = {
    DISABLE_VP_SCALING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry309 = {
    993233,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry309Exception2 = {
    nullptr, // driver_vendor
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "31.0.14001.45012", nullptr }, // driver_version
};

static const std::array<const char* const, 1> kDisabledExtensionsForEntry315 = {
    "GL_MESA_framebuffer_flip_y",
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry315 = {
    964010,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry318 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry318 = {
    995396,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry318 = { {
    { 0x694c, 0x0 },
} };

static const std::array<int, 1> kFeatureListForWorkaroundsEntry321 = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry321 = {
    623029,
    1025427,
};

static const std::array<GpuControlList::Device, 3> kDevicesForWorkaroundsEntry321 = { {
    { 0x9870, 0x0 },
    { 0x9874, 0x0 },
    { 0x98E4, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry321 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.15000.37", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry322 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry322 = {
    932879,
    1025427,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry322 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "23.20.826.5120", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry323 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry323 = {
    932879,
    1025427,
};

static const std::array<GpuControlList::Device, 3> kDevicesForWorkaroundsEntry323 = { {
    { 0x9870, 0x0 },
    { 0x9874, 0x0 },
    { 0x98E4, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry323 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.15000.37", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry324 = {
    DISABLE_NV12_DYNAMIC_TEXTURES,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry324 = {
    1029855,
    1050666,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry328 = {
    DISABLE_D3D11_VIDEO_DECODER,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry328 = {
    1041166,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry328 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaNvidiaDriver, "451.48", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry329 = {
    LIMIT_D3D11_VIDEO_DECODER_TO_11_0,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry329 = {
    1012464,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry337 = {
    DISABLE_ACCELERATED_H264_ENCODE,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry337 = {
    1058583,
    1263058,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry337 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "24.21.13.9858", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry338 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry338 = {
    1062653,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry338 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.100.7755", nullptr }, // driver_version
};

static const std::array<IntelGpuSeriesType, 1> kIntelGpuSeriesForEntry338 = { {
    IntelGpuSeriesType::kIcelake,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry338_619971032 = {
    base::span(kIntelGpuSeriesForEntry338), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry339 = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry339 = {
    971952,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry339 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "20.19.15.4285",
        "20.19.15.4380" }, // driver_version
};

static const std::array<IntelGpuSeriesType, 1> kIntelGpuSeriesForEntry339 = { {
    IntelGpuSeriesType::kSkylake,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry339_619971032 = {
    base::span(kIntelGpuSeriesForEntry339), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry340 = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry340 = {
    971952,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry340 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.18.15.4256",
        "10.18.15.4293" }, // driver_version
};

static const std::array<IntelGpuSeriesType, 1> kIntelGpuSeriesForEntry340 = { {
    IntelGpuSeriesType::kSkylake,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry340_619971032 = {
    base::span(kIntelGpuSeriesForEntry340), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry343 = {
    DISABLE_IMAGEBITMAP_FROM_VIDEO_USING_GPU,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry343 = {
    1098445,
    1105923,
};

static const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry343 = {
    nullptr,
    ".*Direct3D9.*",
    nullptr,
    nullptr,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry344 = {
    DISABLE_ACCELERATED_VP8_DECODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry344 = {
    1094840,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry345 = {
    DISABLE_DECODE_SWAP_CHAIN,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry345 = {
    1107403,
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry345_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry346 = {
    FORCE_RGB10A2_OVERLAY_SUPPORT,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry346 = {
    1062184,
};

static const std::array<IntelGpuSeriesType, 10> kIntelGpuSeriesForEntry346 = { {
    IntelGpuSeriesType::kIcelake,
    IntelGpuSeriesType::kTigerlake,
    IntelGpuSeriesType::kRocketlake,
    IntelGpuSeriesType::kAlderlake,
    IntelGpuSeriesType::kAlchemist,
    IntelGpuSeriesType::kRaptorlake,
    IntelGpuSeriesType::kMeteorlake,
    IntelGpuSeriesType::kArrowlake,
    IntelGpuSeriesType::kLunarlake,
    IntelGpuSeriesType::kBattlemage,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry346_619971032 = {
    base::span(kIntelGpuSeriesForEntry346), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry347 = {
    ENABLE_BGRA8_OVERLAYS_WITH_YUV_OVERLAY_SUPPORT,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry347 = {
    1119491,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry352 = {
    DISABLE_D3D11_VIDEO_DECODER,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry352 = {
    1038006,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry352 = { {
    { 0x0166, 0x0 },
} };

static const std::array<int, 1> kFeatureListForWorkaroundsEntry353 = {
    DISABLE_D3D11_VIDEO_DECODER,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry353 = {
    1038006,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry353 = { {
    { 0x8a56, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry353 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26", "27" }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry354 = {
    DISABLE_D3D11_VIDEO_DECODER,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry354 = {
    1126834,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry354 = { {
    { 0x98e4, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry354 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "24", "27" }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry360 = {
    MAX_MSAA_SAMPLE_COUNT_4,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry360 = {
    1145793,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry362 = {
    SUPPORTS_TWO_YUV_HARDWARE_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry362 = {
    1105618,
};

static const std::array<IntelGpuSeriesType, 11> kIntelGpuSeriesForEntry362 = { {
    IntelGpuSeriesType::kIcelake,
    IntelGpuSeriesType::kTigerlake,
    IntelGpuSeriesType::kRocketlake,
    IntelGpuSeriesType::kDG1,
    IntelGpuSeriesType::kAlderlake,
    IntelGpuSeriesType::kAlchemist,
    IntelGpuSeriesType::kRaptorlake,
    IntelGpuSeriesType::kMeteorlake,
    IntelGpuSeriesType::kArrowlake,
    IntelGpuSeriesType::kLunarlake,
    IntelGpuSeriesType::kBattlemage,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry362_619971032 = {
    base::span(kIntelGpuSeriesForEntry362), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry364 = {
    DISABLE_DIRECT_COMPOSITION_SW_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry364 = {
    1161215,
    1160217,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry371 = {
    DISABLE_DIRECT_COMPOSITION_SW_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry371 = {
    1192748,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry372 = {
    CHECK_YCBCR_STUDIO_G22_LEFT_P709_FOR_NV12_SUPPORT,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry372 = {
    1103852,
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry372_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry376 = {
    DISABLE_MEDIA_FOUNDATION_HARDWARE_SECURITY,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry376 = {
    1219028,
};

static const std::array<GpuControlList::Device, 33> kDevicesForWorkaroundsEntry376 = { {
    { 0x1f82, 0x0 },
    { 0x1f92, 0x0 },
    { 0x2182, 0x0 },
    { 0x2184, 0x0 },
    { 0x21d1, 0x0 },
    { 0x2191, 0x0 },
    { 0x1f08, 0x0 },
    { 0x1f06, 0x0 },
    { 0x1f47, 0x0 },
    { 0x1f42, 0x0 },
    { 0x1f51, 0x0 },
    { 0x1f11, 0x0 },
    { 0x1f02, 0x0 },
    { 0x1f07, 0x0 },
    { 0x1ec2, 0x0 },
    { 0x1ec7, 0x0 },
    { 0x1e84, 0x0 },
    { 0x1f50, 0x0 },
    { 0x1f10, 0x0 },
    { 0x1e82, 0x0 },
    { 0x1e87, 0x0 },
    { 0x1e81, 0x0 },
    { 0x1ed0, 0x0 },
    { 0x1e90, 0x0 },
    { 0x1e07, 0x0 },
    { 0x1e04, 0x0 },
    { 0x1eb1, 0x0 },
    { 0x1eb6, 0x0 },
    { 0x1eb0, 0x0 },
    { 0x1eb5, 0x0 },
    { 0x1e02, 0x0 },
    { 0x1e30, 0x0 },
    { 0x1eb8, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry376 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.21.14.4140", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry377 = {
    DISABLE_MEDIA_FOUNDATION_HARDWARE_SECURITY,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry377 = {
    1219028,
};

static const std::array<GpuControlList::Device, 31> kDevicesForWorkaroundsEntry377 = { {
    { 0x1d01, 0x0 },
    { 0x1d10, 0x0 },
    { 0x1d12, 0x0 },
    { 0x1c81, 0x0 },
    { 0x1c82, 0x0 },
    { 0x1c83, 0x0 },
    { 0x1c8c, 0x0 },
    { 0x1c8d, 0x0 },
    { 0x1c8f, 0x0 },
    { 0x1c92, 0x0 },
    { 0x1c02, 0x0 },
    { 0x1c03, 0x0 },
    { 0x1c20, 0x0 },
    { 0x1c23, 0x0 },
    { 0x1c60, 0x0 },
    { 0x1c61, 0x0 },
    { 0x1c62, 0x0 },
    { 0x1b81, 0x0 },
    { 0x1b82, 0x0 },
    { 0x1b83, 0x0 },
    { 0x1b84, 0x0 },
    { 0x1ba0, 0x0 },
    { 0x1ba1, 0x0 },
    { 0x1ba2, 0x0 },
    { 0x1be0, 0x0 },
    { 0x1be1, 0x0 },
    { 0x1b06, 0x0 },
    { 0x1b00, 0x0 },
    { 0x1b02, 0x0 },
    { 0x17e4, 0x0 },
    { 0x174d, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry377 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.21.14.4140", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry380 = {
    NO_DOWNSCALED_OVERLAY_PROMOTION,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry380 = {
    1245835,
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry380_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
};

static const std::array<int, 3> kFeatureListForWorkaroundsEntry387 = {
    DISABLE_ACCELERATED_AV1_DECODE,
    DISABLE_ACCELERATED_VP8_DECODE,
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry387 = {
    822644,
    1187900,
};

static const std::array<GpuControlList::Device, 314> kDevicesForWorkaroundsEntry387 = { {
    { 0x130f, 0x0 },
    { 0x6700, 0x0 },
    { 0x6701, 0x0 },
    { 0x6702, 0x0 },
    { 0x6703, 0x0 },
    { 0x6704, 0x0 },
    { 0x6705, 0x0 },
    { 0x6706, 0x0 },
    { 0x6707, 0x0 },
    { 0x6708, 0x0 },
    { 0x6709, 0x0 },
    { 0x6718, 0x0 },
    { 0x6719, 0x0 },
    { 0x671c, 0x0 },
    { 0x671d, 0x0 },
    { 0x671f, 0x0 },
    { 0x6720, 0x0 },
    { 0x6721, 0x0 },
    { 0x6722, 0x0 },
    { 0x6723, 0x0 },
    { 0x6724, 0x0 },
    { 0x6725, 0x0 },
    { 0x6726, 0x0 },
    { 0x6727, 0x0 },
    { 0x6728, 0x0 },
    { 0x6729, 0x0 },
    { 0x6738, 0x0 },
    { 0x6739, 0x0 },
    { 0x673e, 0x0 },
    { 0x6740, 0x0 },
    { 0x6741, 0x0 },
    { 0x6742, 0x0 },
    { 0x6743, 0x0 },
    { 0x6744, 0x0 },
    { 0x6745, 0x0 },
    { 0x6746, 0x0 },
    { 0x6747, 0x0 },
    { 0x6748, 0x0 },
    { 0x6749, 0x0 },
    { 0x674a, 0x0 },
    { 0x6750, 0x0 },
    { 0x6751, 0x0 },
    { 0x6758, 0x0 },
    { 0x6759, 0x0 },
    { 0x675b, 0x0 },
    { 0x675d, 0x0 },
    { 0x675f, 0x0 },
    { 0x6760, 0x0 },
    { 0x6761, 0x0 },
    { 0x6762, 0x0 },
    { 0x6763, 0x0 },
    { 0x6764, 0x0 },
    { 0x6765, 0x0 },
    { 0x6766, 0x0 },
    { 0x6767, 0x0 },
    { 0x6768, 0x0 },
    { 0x6770, 0x0 },
    { 0x6771, 0x0 },
    { 0x6772, 0x0 },
    { 0x6778, 0x0 },
    { 0x6779, 0x0 },
    { 0x677b, 0x0 },
    { 0x6798, 0x0 },
    { 0x67b1, 0x0 },
    { 0x6821, 0x0 },
    { 0x683d, 0x0 },
    { 0x6840, 0x0 },
    { 0x6841, 0x0 },
    { 0x6842, 0x0 },
    { 0x6843, 0x0 },
    { 0x6849, 0x0 },
    { 0x6850, 0x0 },
    { 0x6858, 0x0 },
    { 0x6859, 0x0 },
    { 0x6880, 0x0 },
    { 0x6888, 0x0 },
    { 0x6889, 0x0 },
    { 0x688a, 0x0 },
    { 0x688c, 0x0 },
    { 0x688d, 0x0 },
    { 0x6898, 0x0 },
    { 0x6899, 0x0 },
    { 0x689b, 0x0 },
    { 0x689c, 0x0 },
    { 0x689d, 0x0 },
    { 0x689e, 0x0 },
    { 0x68a0, 0x0 },
    { 0x68a1, 0x0 },
    { 0x68a8, 0x0 },
    { 0x68a9, 0x0 },
    { 0x68b0, 0x0 },
    { 0x68b8, 0x0 },
    { 0x68b9, 0x0 },
    { 0x68ba, 0x0 },
    { 0x68be, 0x0 },
    { 0x68bf, 0x0 },
    { 0x68c0, 0x0 },
    { 0x68c1, 0x0 },
    { 0x68c7, 0x0 },
    { 0x68c8, 0x0 },
    { 0x68c9, 0x0 },
    { 0x68d8, 0x0 },
    { 0x68d9, 0x0 },
    { 0x68da, 0x0 },
    { 0x68de, 0x0 },
    { 0x68e0, 0x0 },
    { 0x68e1, 0x0 },
    { 0x68e4, 0x0 },
    { 0x68e5, 0x0 },
    { 0x68e8, 0x0 },
    { 0x68e9, 0x0 },
    { 0x68f1, 0x0 },
    { 0x68f2, 0x0 },
    { 0x68f8, 0x0 },
    { 0x68f9, 0x0 },
    { 0x68fa, 0x0 },
    { 0x68fe, 0x0 },
    { 0x9400, 0x0 },
    { 0x9401, 0x0 },
    { 0x9402, 0x0 },
    { 0x9403, 0x0 },
    { 0x9405, 0x0 },
    { 0x940a, 0x0 },
    { 0x940b, 0x0 },
    { 0x940f, 0x0 },
    { 0x9440, 0x0 },
    { 0x9441, 0x0 },
    { 0x9442, 0x0 },
    { 0x9443, 0x0 },
    { 0x9444, 0x0 },
    { 0x9446, 0x0 },
    { 0x944a, 0x0 },
    { 0x944b, 0x0 },
    { 0x944c, 0x0 },
    { 0x944e, 0x0 },
    { 0x9450, 0x0 },
    { 0x9452, 0x0 },
    { 0x9456, 0x0 },
    { 0x945a, 0x0 },
    { 0x945b, 0x0 },
    { 0x945e, 0x0 },
    { 0x9460, 0x0 },
    { 0x9462, 0x0 },
    { 0x946a, 0x0 },
    { 0x946b, 0x0 },
    { 0x947a, 0x0 },
    { 0x947b, 0x0 },
    { 0x9480, 0x0 },
    { 0x9487, 0x0 },
    { 0x9488, 0x0 },
    { 0x9489, 0x0 },
    { 0x948a, 0x0 },
    { 0x948f, 0x0 },
    { 0x9490, 0x0 },
    { 0x9491, 0x0 },
    { 0x9495, 0x0 },
    { 0x9498, 0x0 },
    { 0x949c, 0x0 },
    { 0x949e, 0x0 },
    { 0x949f, 0x0 },
    { 0x94a0, 0x0 },
    { 0x94a1, 0x0 },
    { 0x94a3, 0x0 },
    { 0x94b1, 0x0 },
    { 0x94b3, 0x0 },
    { 0x94b4, 0x0 },
    { 0x94b5, 0x0 },
    { 0x94b9, 0x0 },
    { 0x94c0, 0x0 },
    { 0x94c1, 0x0 },
    { 0x94c3, 0x0 },
    { 0x94c4, 0x0 },
    { 0x94c5, 0x0 },
    { 0x94c6, 0x0 },
    { 0x94c7, 0x0 },
    { 0x94c8, 0x0 },
    { 0x94c9, 0x0 },
    { 0x94cb, 0x0 },
    { 0x94cc, 0x0 },
    { 0x94cd, 0x0 },
    { 0x9500, 0x0 },
    { 0x9501, 0x0 },
    { 0x9504, 0x0 },
    { 0x9505, 0x0 },
    { 0x9506, 0x0 },
    { 0x9507, 0x0 },
    { 0x9508, 0x0 },
    { 0x9509, 0x0 },
    { 0x950f, 0x0 },
    { 0x9511, 0x0 },
    { 0x9515, 0x0 },
    { 0x9517, 0x0 },
    { 0x9519, 0x0 },
    { 0x9540, 0x0 },
    { 0x9541, 0x0 },
    { 0x9542, 0x0 },
    { 0x954e, 0x0 },
    { 0x954f, 0x0 },
    { 0x9552, 0x0 },
    { 0x9553, 0x0 },
    { 0x9555, 0x0 },
    { 0x9557, 0x0 },
    { 0x955f, 0x0 },
    { 0x9580, 0x0 },
    { 0x9581, 0x0 },
    { 0x9583, 0x0 },
    { 0x9586, 0x0 },
    { 0x9587, 0x0 },
    { 0x9588, 0x0 },
    { 0x9589, 0x0 },
    { 0x958a, 0x0 },
    { 0x958b, 0x0 },
    { 0x958c, 0x0 },
    { 0x958d, 0x0 },
    { 0x958e, 0x0 },
    { 0x958f, 0x0 },
    { 0x9590, 0x0 },
    { 0x9591, 0x0 },
    { 0x9593, 0x0 },
    { 0x9595, 0x0 },
    { 0x9596, 0x0 },
    { 0x9597, 0x0 },
    { 0x9598, 0x0 },
    { 0x9599, 0x0 },
    { 0x959b, 0x0 },
    { 0x95c0, 0x0 },
    { 0x95c2, 0x0 },
    { 0x95c4, 0x0 },
    { 0x95c5, 0x0 },
    { 0x95c6, 0x0 },
    { 0x95c7, 0x0 },
    { 0x95c9, 0x0 },
    { 0x95cc, 0x0 },
    { 0x95cd, 0x0 },
    { 0x95ce, 0x0 },
    { 0x95cf, 0x0 },
    { 0x9610, 0x0 },
    { 0x9611, 0x0 },
    { 0x9612, 0x0 },
    { 0x9613, 0x0 },
    { 0x9614, 0x0 },
    { 0x9615, 0x0 },
    { 0x9616, 0x0 },
    { 0x9640, 0x0 },
    { 0x9641, 0x0 },
    { 0x9642, 0x0 },
    { 0x9643, 0x0 },
    { 0x9644, 0x0 },
    { 0x9645, 0x0 },
    { 0x9647, 0x0 },
    { 0x9648, 0x0 },
    { 0x9649, 0x0 },
    { 0x964a, 0x0 },
    { 0x964b, 0x0 },
    { 0x964c, 0x0 },
    { 0x964e, 0x0 },
    { 0x964f, 0x0 },
    { 0x9710, 0x0 },
    { 0x9711, 0x0 },
    { 0x9712, 0x0 },
    { 0x9713, 0x0 },
    { 0x9714, 0x0 },
    { 0x9715, 0x0 },
    { 0x9802, 0x0 },
    { 0x9803, 0x0 },
    { 0x9804, 0x0 },
    { 0x9805, 0x0 },
    { 0x9806, 0x0 },
    { 0x9807, 0x0 },
    { 0x9808, 0x0 },
    { 0x9809, 0x0 },
    { 0x980a, 0x0 },
    { 0x9830, 0x0 },
    { 0x983d, 0x0 },
    { 0x9850, 0x0 },
    { 0x9851, 0x0 },
    { 0x9874, 0x0 },
    { 0x9900, 0x0 },
    { 0x9901, 0x0 },
    { 0x9903, 0x0 },
    { 0x9904, 0x0 },
    { 0x9905, 0x0 },
    { 0x9906, 0x0 },
    { 0x9907, 0x0 },
    { 0x9908, 0x0 },
    { 0x9909, 0x0 },
    { 0x990a, 0x0 },
    { 0x990b, 0x0 },
    { 0x990c, 0x0 },
    { 0x990d, 0x0 },
    { 0x990e, 0x0 },
    { 0x990f, 0x0 },
    { 0x9910, 0x0 },
    { 0x9913, 0x0 },
    { 0x9917, 0x0 },
    { 0x9918, 0x0 },
    { 0x9919, 0x0 },
    { 0x9990, 0x0 },
    { 0x9991, 0x0 },
    { 0x9992, 0x0 },
    { 0x9993, 0x0 },
    { 0x9994, 0x0 },
    { 0x9995, 0x0 },
    { 0x9996, 0x0 },
    { 0x9997, 0x0 },
    { 0x9998, 0x0 },
    { 0x9999, 0x0 },
    { 0x999a, 0x0 },
    { 0x999b, 0x0 },
    { 0x999c, 0x0 },
    { 0x999d, 0x0 },
    { 0x99a0, 0x0 },
    { 0x99a2, 0x0 },
    { 0x99a4, 0x0 },
} };

static const std::array<int, 3> kFeatureListForWorkaroundsEntry388 = {
    DISABLE_ACCELERATED_AV1_DECODE,
    DISABLE_ACCELERATED_VP8_DECODE,
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry388 = {
    822644,
    1187900,
};

static const std::array<GpuControlList::Device, 14> kDevicesForWorkaroundsEntry388 = { {
    { 0x102, 0x0 },
    { 0x106, 0x0 },
    { 0x116, 0x0 },
    { 0x126, 0x0 },
    { 0x152, 0x0 },
    { 0x156, 0x0 },
    { 0x166, 0x0 },
    { 0x402, 0x0 },
    { 0x406, 0x0 },
    { 0x416, 0x0 },
    { 0x41e, 0x0 },
    { 0xa06, 0x0 },
    { 0xa16, 0x0 },
    { 0xf31, 0x0 },
} };

static const std::array<int, 1> kFeatureListForWorkaroundsEntry390 = {
    DISABLE_DYNAMIC_VIDEO_ENCODE_FRAMERATE_UPDATE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry390 = {
    1295815,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry390 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "30.0.101.1340", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry391 = {
    DISABLE_SKIA_REDUCE_OPS_TASK_SPLITTING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry391 = {
    1298809,
};

static const std::array<IntelGpuSeriesType, 1> kIntelGpuSeriesForEntry391 = { {
    IntelGpuSeriesType::kSkylake,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry391_619971032 = {
    base::span(kIntelGpuSeriesForEntry391), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry394 = {
    DISABLE_VP_SUPER_RESOLUTION,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry394 = {
    1318380,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry394Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "27.20.100.8681", nullptr }, // driver_version
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry394_619971032Exception0 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry394Exception1 = {
    nullptr, // driver_vendor
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaNvidiaDriver, "530.00", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry395 = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry395 = {
    1327088,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry395 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "27.20.100.9168", nullptr }, // driver_version
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry395_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "12", nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry397 = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry397 = {
    1333299,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry397 = { {
    { 0x591B, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry397 = {
    nullptr, // driver_vendor
    { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.100.6998", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry398 = {
    MSAA_IS_SLOW_2,
};

static const std::array<uint32_t, 3> kCrBugsForWorkaroundsEntry398 = {
    527565,
    1298585,
    1341830,
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry398_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "11", nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry403 = {
    DISABLE_ACCELERATED_AV1_ENCODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry403 = {
    1367038,
};

static const GpuControlList::More kMoreForEntry403_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "1", nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry403Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "31.0.101.4146", nullptr }, // driver_version
};

static const std::array<IntelGpuSeriesType, 1> kIntelGpuSeriesForEntry403Exception0 = { {
    IntelGpuSeriesType::kAlchemist,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry403_619971032Exception0 = {
    base::span(kIntelGpuSeriesForEntry403Exception0), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry406 = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry406 = {
    1376513,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry406 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "23.20.16.4974",
        "23.20.16.5044" }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry408 = {
    DISABLE_MEDIA_FOUNDATION_CLEAR_PLAYBACK,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry408 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.15002.61", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry411 = {
    DISABLE_ACCELERATED_VP9_ENCODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry411 = {
    1433287,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry411 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "30.0.100.9667", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry412 = {
    DISABLE_ACCELERATED_VP9_ENCODE,
};

static const std::array<uint32_t, 2> kCrBugsForWorkaroundsEntry412 = {
    1217298,
    1107331,
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry412_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "11", nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry413 = {
    FORCE_DCOMP_TRIPLE_BUFFER_VIDEO_SWAP_CHAIN,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry413 = {
    1447972,
};

static const GpuControlList::IntelConditions kIntelConditionsForEntry413_619971032 = {
    base::span<const IntelGpuSeriesType>(), // intel_gpu_series_list
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "12", nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry414 = {
    DISABLE_VP_AUTO_HDR,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry414 = {
    1445741,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry414Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaNvidiaDriver, "550.50", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry417 = {
    LIMIT_D3D11_VIDEO_DECODER_TO_11_0,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry419 = {
    AVOID_CONSECUTIVE_KEYFRAMES_FOR_VP9,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry419 = {
    1473665,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry420 = {
    DISABLE_ACCELERATED_HEVC_DECODE,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry420 = {
    1475546,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry420 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "20.19.15.4284",
        "20.19.15.5172" }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry424 = {
    DISABLE_SVC_ENCODING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry424 = {
    1439689,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry424 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "31.0.21029.6002", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry426 = {
    DISABLE_D3D11_VP9_KSVC_DECODING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry426 = {
    1508379,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry427 = {
    DISABLE_MEDIA_FOUNDATION_FRAME_SIZE_CHANGE,
};

static const std::array<GpuControlList::Device, 1> kDevicesForWorkaroundsEntry427 = { {
    { 0x694c, 0x0 },
} };

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry427 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "30.0.13025.1000", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry428 = {
    DISABLE_MEDIA_FOUNDATION_HARDWARE_SECURITY,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry428 = {
    1401061,
};

static const std::array<GpuControlList::Device, 23> kDevicesForWorkaroundsEntry428 = { {
    { 0x67c7, 0x0 },
    { 0x67df, 0x0 },
    { 0x67ff, 0x0 },
    { 0x6fdf, 0x0 },
    { 0x67ef, 0x0 },
    { 0x6981, 0x0 },
    { 0x6987, 0x0 },
    { 0x699f, 0x0 },
    { 0x67c2, 0x0 },
    { 0x67d0, 0x0 },
    { 0x6900, 0x0 },
    { 0x6984, 0x0 },
    { 0x67c0, 0x0 },
    { 0x67c1, 0x0 },
    { 0x67e0, 0x0 },
    { 0x67e3, 0x0 },
    { 0x67e8, 0x0 },
    { 0x67eb, 0x0 },
    { 0x6980, 0x0 },
    { 0x6985, 0x0 },
    { 0x6986, 0x0 },
    { 0x6995, 0x0 },
    { 0x6997, 0x0 },
} };

static const std::array<int, 1> kFeatureListForWorkaroundsEntry429 = {
    DISABLE_D3D11_UPDATE_SUBRESOURCE1,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry429 = {
    344109884,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry429 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.20.16.4551", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry430 = {
    DISABLE_WEBNN_FOR_NPU,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry430 = {
    341327464,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry430Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "32.0.100.3053", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry431 = {
    DISABLE_VP9_HMFT_TEMPORAL_ENCODING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry431 = {
    1501767,
};

static const std::array<IntelGpuSeriesType, 5> kIntelGpuSeriesForEntry431 = { {
    IntelGpuSeriesType::kIcelake,
    IntelGpuSeriesType::kElkhartlake,
    IntelGpuSeriesType::kJasperlake,
    IntelGpuSeriesType::kTigerlake,
    IntelGpuSeriesType::kDG1,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry431_619971032 = {
    base::span(kIntelGpuSeriesForEntry431), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry432 = {
    DISABLE_VP9_HMFT_TEMPORAL_ENCODING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry432 = {
    1501767,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry432 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "31.0.101.5590", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry433 = {
    DISABLE_WEBNN_FOR_GPU,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry433 = {
    325123735,
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry434 = {
    DISABLE_HEVC_HMFT_CBR_ENCODING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry434 = {
    41480904,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry434 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "32.0.101.5762", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry436 = {
    DISABLE_VIDEO_OVERLAY_IF_MOVING,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry436 = {
    40677119,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry436Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "31.0.101.4471", nullptr }, // driver_version
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry437 = {
    USE_CURRENT_PICTURE_FOR_AV1_INVALID_REF,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry437 = {
    372358970,
};

static const std::array<IntelGpuSeriesType, 4> kIntelGpuSeriesForEntry437 = { {
    IntelGpuSeriesType::kMeteorlake,
    IntelGpuSeriesType::kArrowlake,
    IntelGpuSeriesType::kLunarlake,
    IntelGpuSeriesType::kBattlemage,
} };

static const GpuControlList::IntelConditions kIntelConditionsForEntry437_619971032 = {
    base::span(kIntelGpuSeriesForEntry437), // intel_gpu_series_list
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
};

static const std::array<int, 1> kFeatureListForWorkaroundsEntry438 = {
    DISABLE_DML_META_COMMANDS_FOR_GPU,
};

static const std::array<uint32_t, 1> kCrBugsForWorkaroundsEntry438 = {
    377047083,
};

static const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry438 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaIntelDriver, "31.0.101.5518",
        "32.0.101.6083" }, // driver_version
};

#endif // GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_
