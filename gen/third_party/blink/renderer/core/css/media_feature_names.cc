// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/media_feature_names.json5

#include "third_party/blink/renderer/core/css/media_feature_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace media_feature_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kDevicePixelRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kMaxDevicePixelRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kMinDevicePixelRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kTransform3dMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kAnyHoverMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kAnyPointerMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kAspectRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kBlockSizeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kColorMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kColorGamutMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kColorIndexMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kDeviceAspectRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kDeviceHeightMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kDevicePostureMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kDeviceWidthMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kDisplayModeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kDisplayStateMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kDynamicRangeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kForcedColorsMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kGridMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kHeightMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kHorizontalViewportSegmentsMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kHoverMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kInlineSizeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kInvertedColorsMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kMaxAspectRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kMaxBlockSizeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kMaxColorMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[27];
const AtomicString& kMaxColorIndexMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[28];
const AtomicString& kMaxDeviceAspectRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[29];
const AtomicString& kMaxDeviceHeightMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[30];
const AtomicString& kMaxDeviceWidthMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[31];
const AtomicString& kMaxHeightMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[32];
const AtomicString& kMaxInlineSizeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[33];
const AtomicString& kMaxMonochromeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[34];
const AtomicString& kMaxResolutionMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[35];
const AtomicString& kMaxWidthMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[36];
const AtomicString& kMinAspectRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[37];
const AtomicString& kMinBlockSizeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[38];
const AtomicString& kMinColorMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[39];
const AtomicString& kMinColorIndexMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[40];
const AtomicString& kMinDeviceAspectRatioMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[41];
const AtomicString& kMinDeviceHeightMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[42];
const AtomicString& kMinDeviceWidthMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[43];
const AtomicString& kMinHeightMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[44];
const AtomicString& kMinInlineSizeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[45];
const AtomicString& kMinMonochromeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[46];
const AtomicString& kMinResolutionMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[47];
const AtomicString& kMinWidthMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[48];
const AtomicString& kMonochromeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[49];
const AtomicString& kNavigationControlsMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[50];
const AtomicString& kOrientationMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[51];
const AtomicString& kOriginTrialTestMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[52];
const AtomicString& kOverflowBlockMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[53];
const AtomicString& kOverflowInlineMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[54];
const AtomicString& kOverflowingMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[55];
const AtomicString& kPointerMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[56];
const AtomicString& kPrefersColorSchemeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[57];
const AtomicString& kPrefersContrastMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[58];
const AtomicString& kPrefersReducedDataMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[59];
const AtomicString& kPrefersReducedMotionMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[60];
const AtomicString& kPrefersReducedTransparencyMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[61];
const AtomicString& kResizableMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[62];
const AtomicString& kResolutionMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[63];
const AtomicString& kScanMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[64];
const AtomicString& kScriptingMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[65];
const AtomicString& kSnappedMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[66];
const AtomicString& kStuckMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[67];
const AtomicString& kUpdateMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[68];
const AtomicString& kVerticalViewportSegmentsMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[69];
const AtomicString& kVideoDynamicRangeMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[70];
const AtomicString& kWidthMediaFeature = reinterpret_cast<AtomicString*>(&names_storage)[71];

void Init()
{
    static bool is_loaded = false;
    if (is_loaded)
        return;
    is_loaded = true;

    struct NameEntry {
        const char* name;
        unsigned char length;
    };

    static const NameEntry kNames[] = {
        { "-webkit-device-pixel-ratio", 26 },
        { "-webkit-max-device-pixel-ratio", 30 },
        { "-webkit-min-device-pixel-ratio", 30 },
        { "-webkit-transform-3d", 20 },
        { "any-hover", 9 },
        { "any-pointer", 11 },
        { "aspect-ratio", 12 },
        { "block-size", 10 },
        { "color", 5 },
        { "color-gamut", 11 },
        { "color-index", 11 },
        { "device-aspect-ratio", 19 },
        { "device-height", 13 },
        { "device-posture", 14 },
        { "device-width", 12 },
        { "display-mode", 12 },
        { "display-state", 13 },
        { "dynamic-range", 13 },
        { "forced-colors", 13 },
        { "grid", 4 },
        { "height", 6 },
        { "horizontal-viewport-segments", 28 },
        { "hover", 5 },
        { "inline-size", 11 },
        { "inverted-colors", 15 },
        { "max-aspect-ratio", 16 },
        { "max-block-size", 14 },
        { "max-color", 9 },
        { "max-color-index", 15 },
        { "max-device-aspect-ratio", 23 },
        { "max-device-height", 17 },
        { "max-device-width", 16 },
        { "max-height", 10 },
        { "max-inline-size", 15 },
        { "max-monochrome", 14 },
        { "max-resolution", 14 },
        { "max-width", 9 },
        { "min-aspect-ratio", 16 },
        { "min-block-size", 14 },
        { "min-color", 9 },
        { "min-color-index", 15 },
        { "min-device-aspect-ratio", 23 },
        { "min-device-height", 17 },
        { "min-device-width", 16 },
        { "min-height", 10 },
        { "min-inline-size", 15 },
        { "min-monochrome", 14 },
        { "min-resolution", 14 },
        { "min-width", 9 },
        { "monochrome", 10 },
        { "navigation-controls", 19 },
        { "orientation", 11 },
        { "origin-trial-test", 17 },
        { "overflow-block", 14 },
        { "overflow-inline", 15 },
        { "overflowing", 11 },
        { "pointer", 7 },
        { "prefers-color-scheme", 20 },
        { "prefers-contrast", 16 },
        { "prefers-reduced-data", 20 },
        { "prefers-reduced-motion", 22 },
        { "prefers-reduced-transparency", 28 },
        { "resizable", 9 },
        { "resolution", 10 },
        { "scan", 4 },
        { "scripting", 9 },
        { "snapped", 7 },
        { "stuck", 5 },
        { "update", 6 },
        { "vertical-viewport-segments", 26 },
        { "video-dynamic-range", 19 },
        { "width", 5 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace media_feature_names
} // namespace blink
