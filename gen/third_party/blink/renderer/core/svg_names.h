// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/svg/svg_attribute_names.json5
//   ../../third_party/blink/renderer/core/svg/svg_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SVG_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SVG_NAMES_H_

#include <memory>

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/qualified_name.h"

namespace blink {

class SVGQualifiedName : public QualifiedName { };

namespace svg_names {

// Namespace
CORE_EXPORT extern const WTF::AtomicString& kNamespaceURI;

// Tags

CORE_EXPORT extern const blink::SVGQualifiedName& kATag;
CORE_EXPORT extern const blink::SVGQualifiedName& kAnimateTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kAnimateColorTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kAnimateMotionTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kAnimateTransformTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kCircleTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kClipPathTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kDefsTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kDescTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kEllipseTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEBlendTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEColorMatrixTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEComponentTransferTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFECompositeTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEConvolveMatrixTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEDiffuseLightingTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEDisplacementMapTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEDistantLightTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEDropShadowTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEFloodTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEFuncATag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEFuncBTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEFuncGTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEFuncRTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEGaussianBlurTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEImageTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEMergeTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEMergeNodeTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEMorphologyTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEOffsetTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFEPointLightTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFESpecularLightingTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFESpotLightTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFETileTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFETurbulenceTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kFilterTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kForeignObjectTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kGTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kImageTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kLineTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kLinearGradientTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kMarkerTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kMaskTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kMetadataTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kMPathTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kPathTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kPatternTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kPolygonTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kPolylineTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kRadialGradientTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kRectTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kScriptTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kSetTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kStopTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kStyleTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kSVGTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kSwitchTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kSymbolTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kTextTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kTextPathTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kTitleTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kTSpanTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kUseTag;
CORE_EXPORT extern const blink::SVGQualifiedName& kViewTag;

// Attributes
CORE_EXPORT extern const blink::QualifiedName& kAccumulateAttr;
CORE_EXPORT extern const blink::QualifiedName& kAdditiveAttr;
CORE_EXPORT extern const blink::QualifiedName& kAlignmentBaselineAttr;
CORE_EXPORT extern const blink::QualifiedName& kAmplitudeAttr;
CORE_EXPORT extern const blink::QualifiedName& kAnimateAttr;
CORE_EXPORT extern const blink::QualifiedName& kAttributeNameAttr;
CORE_EXPORT extern const blink::QualifiedName& kAttributeTypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kAutofocusAttr;
CORE_EXPORT extern const blink::QualifiedName& kAzimuthAttr;
CORE_EXPORT extern const blink::QualifiedName& kBaseFrequencyAttr;
CORE_EXPORT extern const blink::QualifiedName& kBaseProfileAttr;
CORE_EXPORT extern const blink::QualifiedName& kBaselineShiftAttr;
CORE_EXPORT extern const blink::QualifiedName& kBeginAttr;
CORE_EXPORT extern const blink::QualifiedName& kBiasAttr;
CORE_EXPORT extern const blink::QualifiedName& kBufferedRenderingAttr;
CORE_EXPORT extern const blink::QualifiedName& kByAttr;
CORE_EXPORT extern const blink::QualifiedName& kCalcModeAttr;
CORE_EXPORT extern const blink::QualifiedName& kClipAttr;
CORE_EXPORT extern const blink::QualifiedName& kClipPathAttr;
CORE_EXPORT extern const blink::QualifiedName& kClipRuleAttr;
CORE_EXPORT extern const blink::QualifiedName& kClipPathUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kColorAttr;
CORE_EXPORT extern const blink::QualifiedName& kColorInterpolationAttr;
CORE_EXPORT extern const blink::QualifiedName& kColorInterpolationFiltersAttr;
CORE_EXPORT extern const blink::QualifiedName& kColorRenderingAttr;
CORE_EXPORT extern const blink::QualifiedName& kCrossoriginAttr;
CORE_EXPORT extern const blink::QualifiedName& kCursorAttr;
CORE_EXPORT extern const blink::QualifiedName& kCxAttr;
CORE_EXPORT extern const blink::QualifiedName& kCyAttr;
CORE_EXPORT extern const blink::QualifiedName& kDAttr;
CORE_EXPORT extern const blink::QualifiedName& kDecodingAttr;
CORE_EXPORT extern const blink::QualifiedName& kDiffuseConstantAttr;
CORE_EXPORT extern const blink::QualifiedName& kDirectionAttr;
CORE_EXPORT extern const blink::QualifiedName& kDisplayAttr;
CORE_EXPORT extern const blink::QualifiedName& kDivisorAttr;
CORE_EXPORT extern const blink::QualifiedName& kDominantBaselineAttr;
CORE_EXPORT extern const blink::QualifiedName& kDurAttr;
CORE_EXPORT extern const blink::QualifiedName& kDxAttr;
CORE_EXPORT extern const blink::QualifiedName& kDyAttr;
CORE_EXPORT extern const blink::QualifiedName& kEdgeModeAttr;
CORE_EXPORT extern const blink::QualifiedName& kElevationAttr;
CORE_EXPORT extern const blink::QualifiedName& kEndAttr;
CORE_EXPORT extern const blink::QualifiedName& kExponentAttr;
CORE_EXPORT extern const blink::QualifiedName& kFillAttr;
CORE_EXPORT extern const blink::QualifiedName& kFillOpacityAttr;
CORE_EXPORT extern const blink::QualifiedName& kFillRuleAttr;
CORE_EXPORT extern const blink::QualifiedName& kFilterAttr;
CORE_EXPORT extern const blink::QualifiedName& kFilterUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kFloodColorAttr;
CORE_EXPORT extern const blink::QualifiedName& kFloodOpacityAttr;
CORE_EXPORT extern const blink::QualifiedName& kFocusgroupAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontFamilyAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontSizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontSizeAdjustAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontStretchAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontStyleAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontVariantAttr;
CORE_EXPORT extern const blink::QualifiedName& kFontWeightAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormatAttr;
CORE_EXPORT extern const blink::QualifiedName& kFrAttr;
CORE_EXPORT extern const blink::QualifiedName& kFromAttr;
CORE_EXPORT extern const blink::QualifiedName& kFxAttr;
CORE_EXPORT extern const blink::QualifiedName& kFyAttr;
CORE_EXPORT extern const blink::QualifiedName& kG1Attr;
CORE_EXPORT extern const blink::QualifiedName& kG2Attr;
CORE_EXPORT extern const blink::QualifiedName& kGlyphRefAttr;
CORE_EXPORT extern const blink::QualifiedName& kGradientTransformAttr;
CORE_EXPORT extern const blink::QualifiedName& kGradientUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kHeightAttr;
CORE_EXPORT extern const blink::QualifiedName& kHrefAttr;
CORE_EXPORT extern const blink::QualifiedName& kImageRenderingAttr;
CORE_EXPORT extern const blink::QualifiedName& kInAttr;
CORE_EXPORT extern const blink::QualifiedName& kIn2Attr;
CORE_EXPORT extern const blink::QualifiedName& kInterceptAttr;
CORE_EXPORT extern const blink::QualifiedName& kInterestactionAttr;
CORE_EXPORT extern const blink::QualifiedName& kInteresttargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kKAttr;
CORE_EXPORT extern const blink::QualifiedName& kK1Attr;
CORE_EXPORT extern const blink::QualifiedName& kK2Attr;
CORE_EXPORT extern const blink::QualifiedName& kK3Attr;
CORE_EXPORT extern const blink::QualifiedName& kK4Attr;
CORE_EXPORT extern const blink::QualifiedName& kKernelMatrixAttr;
CORE_EXPORT extern const blink::QualifiedName& kKernelUnitLengthAttr;
CORE_EXPORT extern const blink::QualifiedName& kKeyPointsAttr;
CORE_EXPORT extern const blink::QualifiedName& kKeySplinesAttr;
CORE_EXPORT extern const blink::QualifiedName& kKeyTimesAttr;
CORE_EXPORT extern const blink::QualifiedName& kLangAttr;
CORE_EXPORT extern const blink::QualifiedName& kLengthAdjustAttr;
CORE_EXPORT extern const blink::QualifiedName& kLetterSpacingAttr;
CORE_EXPORT extern const blink::QualifiedName& kLightingColorAttr;
CORE_EXPORT extern const blink::QualifiedName& kLimitingConeAngleAttr;
CORE_EXPORT extern const blink::QualifiedName& kLocalAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarkerEndAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarkerMidAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarkerStartAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarkerHeightAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarkerUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarkerWidthAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaskAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaskTypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaskContentUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaskUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaxAttr;
CORE_EXPORT extern const blink::QualifiedName& kMediaAttr;
CORE_EXPORT extern const blink::QualifiedName& kMethodAttr;
CORE_EXPORT extern const blink::QualifiedName& kMinAttr;
CORE_EXPORT extern const blink::QualifiedName& kModeAttr;
CORE_EXPORT extern const blink::QualifiedName& kNameAttr;
CORE_EXPORT extern const blink::QualifiedName& kNumOctavesAttr;
CORE_EXPORT extern const blink::QualifiedName& kOffsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnactivateAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeginAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnfocusinAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnfocusoutAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnrepeatAttr;
CORE_EXPORT extern const blink::QualifiedName& kOpacityAttr;
CORE_EXPORT extern const blink::QualifiedName& kOperatorAttr;
CORE_EXPORT extern const blink::QualifiedName& kOrderAttr;
CORE_EXPORT extern const blink::QualifiedName& kOrientAttr;
CORE_EXPORT extern const blink::QualifiedName& kOriginAttr;
CORE_EXPORT extern const blink::QualifiedName& kOverflowAttr;
CORE_EXPORT extern const blink::QualifiedName& kPaintOrderAttr;
CORE_EXPORT extern const blink::QualifiedName& kPathAttr;
CORE_EXPORT extern const blink::QualifiedName& kPathLengthAttr;
CORE_EXPORT extern const blink::QualifiedName& kPatternContentUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kPatternTransformAttr;
CORE_EXPORT extern const blink::QualifiedName& kPatternUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kPointerEventsAttr;
CORE_EXPORT extern const blink::QualifiedName& kPointsAttr;
CORE_EXPORT extern const blink::QualifiedName& kPointsAtXAttr;
CORE_EXPORT extern const blink::QualifiedName& kPointsAtYAttr;
CORE_EXPORT extern const blink::QualifiedName& kPointsAtZAttr;
CORE_EXPORT extern const blink::QualifiedName& kPreserveAlphaAttr;
CORE_EXPORT extern const blink::QualifiedName& kPreserveAspectRatioAttr;
CORE_EXPORT extern const blink::QualifiedName& kPrimitiveUnitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kRAttr;
CORE_EXPORT extern const blink::QualifiedName& kRadiusAttr;
CORE_EXPORT extern const blink::QualifiedName& kRefXAttr;
CORE_EXPORT extern const blink::QualifiedName& kRefYAttr;
CORE_EXPORT extern const blink::QualifiedName& kRepeatCountAttr;
CORE_EXPORT extern const blink::QualifiedName& kRepeatDurAttr;
CORE_EXPORT extern const blink::QualifiedName& kRequiredExtensionsAttr;
CORE_EXPORT extern const blink::QualifiedName& kRequiredFeaturesAttr;
CORE_EXPORT extern const blink::QualifiedName& kRestartAttr;
CORE_EXPORT extern const blink::QualifiedName& kResultAttr;
CORE_EXPORT extern const blink::QualifiedName& kRotateAttr;
CORE_EXPORT extern const blink::QualifiedName& kRxAttr;
CORE_EXPORT extern const blink::QualifiedName& kRyAttr;
CORE_EXPORT extern const blink::QualifiedName& kScaleAttr;
CORE_EXPORT extern const blink::QualifiedName& kSeedAttr;
CORE_EXPORT extern const blink::QualifiedName& kShapeRenderingAttr;
CORE_EXPORT extern const blink::QualifiedName& kSlopeAttr;
CORE_EXPORT extern const blink::QualifiedName& kSpacingAttr;
CORE_EXPORT extern const blink::QualifiedName& kSpecularConstantAttr;
CORE_EXPORT extern const blink::QualifiedName& kSpecularExponentAttr;
CORE_EXPORT extern const blink::QualifiedName& kSpreadMethodAttr;
CORE_EXPORT extern const blink::QualifiedName& kStartOffsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kStdDeviationAttr;
CORE_EXPORT extern const blink::QualifiedName& kStitchTilesAttr;
CORE_EXPORT extern const blink::QualifiedName& kStopColorAttr;
CORE_EXPORT extern const blink::QualifiedName& kStopOpacityAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeDasharrayAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeDashoffsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeLinecapAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeLinejoinAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeMiterlimitAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeOpacityAttr;
CORE_EXPORT extern const blink::QualifiedName& kStrokeWidthAttr;
CORE_EXPORT extern const blink::QualifiedName& kStyleAttr;
CORE_EXPORT extern const blink::QualifiedName& kSurfaceScaleAttr;
CORE_EXPORT extern const blink::QualifiedName& kSystemLanguageAttr;
CORE_EXPORT extern const blink::QualifiedName& kTableValuesAttr;
CORE_EXPORT extern const blink::QualifiedName& kTargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kTargetXAttr;
CORE_EXPORT extern const blink::QualifiedName& kTargetYAttr;
CORE_EXPORT extern const blink::QualifiedName& kTextAnchorAttr;
CORE_EXPORT extern const blink::QualifiedName& kTextDecorationAttr;
CORE_EXPORT extern const blink::QualifiedName& kTextRenderingAttr;
CORE_EXPORT extern const blink::QualifiedName& kTextLengthAttr;
CORE_EXPORT extern const blink::QualifiedName& kTitleAttr;
CORE_EXPORT extern const blink::QualifiedName& kToAttr;
CORE_EXPORT extern const blink::QualifiedName& kTransformAttr;
CORE_EXPORT extern const blink::QualifiedName& kTransformOriginAttr;
CORE_EXPORT extern const blink::QualifiedName& kTypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kU1Attr;
CORE_EXPORT extern const blink::QualifiedName& kU2Attr;
CORE_EXPORT extern const blink::QualifiedName& kUnicodeBidiAttr;
CORE_EXPORT extern const blink::QualifiedName& kValuesAttr;
CORE_EXPORT extern const blink::QualifiedName& kVectorEffectAttr;
CORE_EXPORT extern const blink::QualifiedName& kVersionAttr;
CORE_EXPORT extern const blink::QualifiedName& kViewBoxAttr;
CORE_EXPORT extern const blink::QualifiedName& kVisibilityAttr;
CORE_EXPORT extern const blink::QualifiedName& kWidthAttr;
CORE_EXPORT extern const blink::QualifiedName& kWordSpacingAttr;
CORE_EXPORT extern const blink::QualifiedName& kWritingModeAttr;
CORE_EXPORT extern const blink::QualifiedName& kXAttr;
CORE_EXPORT extern const blink::QualifiedName& kX1Attr;
CORE_EXPORT extern const blink::QualifiedName& kX2Attr;
CORE_EXPORT extern const blink::QualifiedName& kXChannelSelectorAttr;
CORE_EXPORT extern const blink::QualifiedName& kYAttr;
CORE_EXPORT extern const blink::QualifiedName& kY1Attr;
CORE_EXPORT extern const blink::QualifiedName& kY2Attr;
CORE_EXPORT extern const blink::QualifiedName& kYChannelSelectorAttr;
CORE_EXPORT extern const blink::QualifiedName& kZAttr;
CORE_EXPORT extern const blink::QualifiedName& kZoomAndPanAttr;

constexpr unsigned kTagsCount = 64;
CORE_EXPORT std::unique_ptr<const SVGQualifiedName*[]> GetTags();

constexpr unsigned kAttrsCount = 207;
std::unique_ptr<const QualifiedName*[]> GetAttrs();

void Init();

} // namespace svg_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_SVG_NAMES_H_
