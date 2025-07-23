// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/svg/svg_attribute_names.json5
//   ../../third_party/blink/renderer/core/svg/svg_tag_names.json5

#include "third_party/blink/renderer/core/svg_names.h"

#include <memory>

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/static_constructors.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace svg_names {

DEFINE_GLOBAL(AtomicString, kNamespaceURI);

// Tags

void* tag_storage[kTagsCount * ((sizeof(SVGQualifiedName) + sizeof(void*) - 1) / sizeof(void*))];
const SVGQualifiedName& kATag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[0];
const SVGQualifiedName& kAnimateTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[1];
const SVGQualifiedName& kAnimateColorTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[2];
const SVGQualifiedName& kAnimateMotionTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[3];
const SVGQualifiedName& kAnimateTransformTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[4];
const SVGQualifiedName& kCircleTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[5];
const SVGQualifiedName& kClipPathTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[6];
const SVGQualifiedName& kDefsTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[7];
const SVGQualifiedName& kDescTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[8];
const SVGQualifiedName& kEllipseTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[9];
const SVGQualifiedName& kFEBlendTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[10];
const SVGQualifiedName& kFEColorMatrixTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[11];
const SVGQualifiedName& kFEComponentTransferTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[12];
const SVGQualifiedName& kFECompositeTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[13];
const SVGQualifiedName& kFEConvolveMatrixTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[14];
const SVGQualifiedName& kFEDiffuseLightingTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[15];
const SVGQualifiedName& kFEDisplacementMapTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[16];
const SVGQualifiedName& kFEDistantLightTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[17];
const SVGQualifiedName& kFEDropShadowTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[18];
const SVGQualifiedName& kFEFloodTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[19];
const SVGQualifiedName& kFEFuncATag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[20];
const SVGQualifiedName& kFEFuncBTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[21];
const SVGQualifiedName& kFEFuncGTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[22];
const SVGQualifiedName& kFEFuncRTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[23];
const SVGQualifiedName& kFEGaussianBlurTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[24];
const SVGQualifiedName& kFEImageTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[25];
const SVGQualifiedName& kFEMergeTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[26];
const SVGQualifiedName& kFEMergeNodeTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[27];
const SVGQualifiedName& kFEMorphologyTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[28];
const SVGQualifiedName& kFEOffsetTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[29];
const SVGQualifiedName& kFEPointLightTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[30];
const SVGQualifiedName& kFESpecularLightingTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[31];
const SVGQualifiedName& kFESpotLightTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[32];
const SVGQualifiedName& kFETileTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[33];
const SVGQualifiedName& kFETurbulenceTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[34];
const SVGQualifiedName& kFilterTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[35];
const SVGQualifiedName& kForeignObjectTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[36];
const SVGQualifiedName& kGTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[37];
const SVGQualifiedName& kImageTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[38];
const SVGQualifiedName& kLineTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[39];
const SVGQualifiedName& kLinearGradientTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[40];
const SVGQualifiedName& kMarkerTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[41];
const SVGQualifiedName& kMaskTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[42];
const SVGQualifiedName& kMetadataTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[43];
const SVGQualifiedName& kMPathTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[44];
const SVGQualifiedName& kPathTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[45];
const SVGQualifiedName& kPatternTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[46];
const SVGQualifiedName& kPolygonTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[47];
const SVGQualifiedName& kPolylineTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[48];
const SVGQualifiedName& kRadialGradientTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[49];
const SVGQualifiedName& kRectTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[50];
const SVGQualifiedName& kScriptTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[51];
const SVGQualifiedName& kSetTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[52];
const SVGQualifiedName& kStopTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[53];
const SVGQualifiedName& kStyleTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[54];
const SVGQualifiedName& kSVGTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[55];
const SVGQualifiedName& kSwitchTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[56];
const SVGQualifiedName& kSymbolTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[57];
const SVGQualifiedName& kTextTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[58];
const SVGQualifiedName& kTextPathTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[59];
const SVGQualifiedName& kTitleTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[60];
const SVGQualifiedName& kTSpanTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[61];
const SVGQualifiedName& kUseTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[62];
const SVGQualifiedName& kViewTag = reinterpret_cast<SVGQualifiedName*>(&tag_storage)[63];

std::unique_ptr<const SVGQualifiedName*[]> GetTags()
{
    auto tags = std::make_unique<const SVGQualifiedName*[]>(kTagsCount);
    for (size_t i = 0; i < kTagsCount; ++i)
        tags[i] = reinterpret_cast<SVGQualifiedName*>(&tag_storage) + i;
    return tags;
}

// Attributes

void* attr_storage[kAttrsCount * ((sizeof(QualifiedName) + sizeof(void*) - 1) / sizeof(void*))];

const QualifiedName& kAccumulateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[0];
const QualifiedName& kAdditiveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[1];
const QualifiedName& kAlignmentBaselineAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[2];
const QualifiedName& kAmplitudeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[3];
const QualifiedName& kAnimateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[4];
const QualifiedName& kAttributeNameAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[5];
const QualifiedName& kAttributeTypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[6];
const QualifiedName& kAutofocusAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[7];
const QualifiedName& kAzimuthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[8];
const QualifiedName& kBaseFrequencyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[9];
const QualifiedName& kBaseProfileAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[10];
const QualifiedName& kBaselineShiftAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[11];
const QualifiedName& kBeginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[12];
const QualifiedName& kBiasAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[13];
const QualifiedName& kBufferedRenderingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[14];
const QualifiedName& kByAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[15];
const QualifiedName& kCalcModeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[16];
const QualifiedName& kClipAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[17];
const QualifiedName& kClipPathAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[18];
const QualifiedName& kClipRuleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[19];
const QualifiedName& kClipPathUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[20];
const QualifiedName& kColorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[21];
const QualifiedName& kColorInterpolationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[22];
const QualifiedName& kColorInterpolationFiltersAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[23];
const QualifiedName& kColorRenderingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[24];
const QualifiedName& kCrossoriginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[25];
const QualifiedName& kCursorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[26];
const QualifiedName& kCxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[27];
const QualifiedName& kCyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[28];
const QualifiedName& kDAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[29];
const QualifiedName& kDecodingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[30];
const QualifiedName& kDiffuseConstantAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[31];
const QualifiedName& kDirectionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[32];
const QualifiedName& kDisplayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[33];
const QualifiedName& kDivisorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[34];
const QualifiedName& kDominantBaselineAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[35];
const QualifiedName& kDurAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[36];
const QualifiedName& kDxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[37];
const QualifiedName& kDyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[38];
const QualifiedName& kEdgeModeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[39];
const QualifiedName& kElevationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[40];
const QualifiedName& kEndAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[41];
const QualifiedName& kExponentAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[42];
const QualifiedName& kFillAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[43];
const QualifiedName& kFillOpacityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[44];
const QualifiedName& kFillRuleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[45];
const QualifiedName& kFilterAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[46];
const QualifiedName& kFilterUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[47];
const QualifiedName& kFloodColorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[48];
const QualifiedName& kFloodOpacityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[49];
const QualifiedName& kFocusgroupAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[50];
const QualifiedName& kFontFamilyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[51];
const QualifiedName& kFontSizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[52];
const QualifiedName& kFontSizeAdjustAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[53];
const QualifiedName& kFontStretchAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[54];
const QualifiedName& kFontStyleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[55];
const QualifiedName& kFontVariantAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[56];
const QualifiedName& kFontWeightAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[57];
const QualifiedName& kFormatAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[58];
const QualifiedName& kFrAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[59];
const QualifiedName& kFromAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[60];
const QualifiedName& kFxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[61];
const QualifiedName& kFyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[62];
const QualifiedName& kG1Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[63];
const QualifiedName& kG2Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[64];
const QualifiedName& kGlyphRefAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[65];
const QualifiedName& kGradientTransformAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[66];
const QualifiedName& kGradientUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[67];
const QualifiedName& kHeightAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[68];
const QualifiedName& kHrefAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[69];
const QualifiedName& kImageRenderingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[70];
const QualifiedName& kInAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[71];
const QualifiedName& kIn2Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[72];
const QualifiedName& kInterceptAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[73];
const QualifiedName& kInterestactionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[74];
const QualifiedName& kInteresttargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[75];
const QualifiedName& kKAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[76];
const QualifiedName& kK1Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[77];
const QualifiedName& kK2Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[78];
const QualifiedName& kK3Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[79];
const QualifiedName& kK4Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[80];
const QualifiedName& kKernelMatrixAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[81];
const QualifiedName& kKernelUnitLengthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[82];
const QualifiedName& kKeyPointsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[83];
const QualifiedName& kKeySplinesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[84];
const QualifiedName& kKeyTimesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[85];
const QualifiedName& kLangAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[86];
const QualifiedName& kLengthAdjustAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[87];
const QualifiedName& kLetterSpacingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[88];
const QualifiedName& kLightingColorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[89];
const QualifiedName& kLimitingConeAngleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[90];
const QualifiedName& kLocalAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[91];
const QualifiedName& kMarkerEndAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[92];
const QualifiedName& kMarkerMidAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[93];
const QualifiedName& kMarkerStartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[94];
const QualifiedName& kMarkerHeightAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[95];
const QualifiedName& kMarkerUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[96];
const QualifiedName& kMarkerWidthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[97];
const QualifiedName& kMaskAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[98];
const QualifiedName& kMaskTypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[99];
const QualifiedName& kMaskContentUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[100];
const QualifiedName& kMaskUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[101];
const QualifiedName& kMaxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[102];
const QualifiedName& kMediaAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[103];
const QualifiedName& kMethodAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[104];
const QualifiedName& kMinAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[105];
const QualifiedName& kModeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[106];
const QualifiedName& kNameAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[107];
const QualifiedName& kNumOctavesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[108];
const QualifiedName& kOffsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[109];
const QualifiedName& kOnactivateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[110];
const QualifiedName& kOnbeginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[111];
const QualifiedName& kOnendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[112];
const QualifiedName& kOnfocusinAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[113];
const QualifiedName& kOnfocusoutAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[114];
const QualifiedName& kOnrepeatAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[115];
const QualifiedName& kOpacityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[116];
const QualifiedName& kOperatorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[117];
const QualifiedName& kOrderAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[118];
const QualifiedName& kOrientAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[119];
const QualifiedName& kOriginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[120];
const QualifiedName& kOverflowAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[121];
const QualifiedName& kPaintOrderAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[122];
const QualifiedName& kPathAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[123];
const QualifiedName& kPathLengthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[124];
const QualifiedName& kPatternContentUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[125];
const QualifiedName& kPatternTransformAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[126];
const QualifiedName& kPatternUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[127];
const QualifiedName& kPointerEventsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[128];
const QualifiedName& kPointsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[129];
const QualifiedName& kPointsAtXAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[130];
const QualifiedName& kPointsAtYAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[131];
const QualifiedName& kPointsAtZAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[132];
const QualifiedName& kPreserveAlphaAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[133];
const QualifiedName& kPreserveAspectRatioAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[134];
const QualifiedName& kPrimitiveUnitsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[135];
const QualifiedName& kRAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[136];
const QualifiedName& kRadiusAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[137];
const QualifiedName& kRefXAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[138];
const QualifiedName& kRefYAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[139];
const QualifiedName& kRepeatCountAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[140];
const QualifiedName& kRepeatDurAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[141];
const QualifiedName& kRequiredExtensionsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[142];
const QualifiedName& kRequiredFeaturesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[143];
const QualifiedName& kRestartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[144];
const QualifiedName& kResultAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[145];
const QualifiedName& kRotateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[146];
const QualifiedName& kRxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[147];
const QualifiedName& kRyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[148];
const QualifiedName& kScaleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[149];
const QualifiedName& kSeedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[150];
const QualifiedName& kShapeRenderingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[151];
const QualifiedName& kSlopeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[152];
const QualifiedName& kSpacingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[153];
const QualifiedName& kSpecularConstantAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[154];
const QualifiedName& kSpecularExponentAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[155];
const QualifiedName& kSpreadMethodAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[156];
const QualifiedName& kStartOffsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[157];
const QualifiedName& kStdDeviationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[158];
const QualifiedName& kStitchTilesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[159];
const QualifiedName& kStopColorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[160];
const QualifiedName& kStopOpacityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[161];
const QualifiedName& kStrokeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[162];
const QualifiedName& kStrokeDasharrayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[163];
const QualifiedName& kStrokeDashoffsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[164];
const QualifiedName& kStrokeLinecapAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[165];
const QualifiedName& kStrokeLinejoinAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[166];
const QualifiedName& kStrokeMiterlimitAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[167];
const QualifiedName& kStrokeOpacityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[168];
const QualifiedName& kStrokeWidthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[169];
const QualifiedName& kStyleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[170];
const QualifiedName& kSurfaceScaleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[171];
const QualifiedName& kSystemLanguageAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[172];
const QualifiedName& kTableValuesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[173];
const QualifiedName& kTargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[174];
const QualifiedName& kTargetXAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[175];
const QualifiedName& kTargetYAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[176];
const QualifiedName& kTextAnchorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[177];
const QualifiedName& kTextDecorationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[178];
const QualifiedName& kTextRenderingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[179];
const QualifiedName& kTextLengthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[180];
const QualifiedName& kTitleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[181];
const QualifiedName& kToAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[182];
const QualifiedName& kTransformAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[183];
const QualifiedName& kTransformOriginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[184];
const QualifiedName& kTypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[185];
const QualifiedName& kU1Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[186];
const QualifiedName& kU2Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[187];
const QualifiedName& kUnicodeBidiAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[188];
const QualifiedName& kValuesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[189];
const QualifiedName& kVectorEffectAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[190];
const QualifiedName& kVersionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[191];
const QualifiedName& kViewBoxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[192];
const QualifiedName& kVisibilityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[193];
const QualifiedName& kWidthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[194];
const QualifiedName& kWordSpacingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[195];
const QualifiedName& kWritingModeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[196];
const QualifiedName& kXAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[197];
const QualifiedName& kX1Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[198];
const QualifiedName& kX2Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[199];
const QualifiedName& kXChannelSelectorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[200];
const QualifiedName& kYAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[201];
const QualifiedName& kY1Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[202];
const QualifiedName& kY2Attr = reinterpret_cast<QualifiedName*>(&attr_storage)[203];
const QualifiedName& kYChannelSelectorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[204];
const QualifiedName& kZAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[205];
const QualifiedName& kZoomAndPanAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[206];

std::unique_ptr<const QualifiedName*[]> GetAttrs()
{
    auto attrs = std::make_unique<const QualifiedName*[]>(kAttrsCount);
    for (size_t i = 0; i < kAttrsCount; ++i)
        attrs[i] = reinterpret_cast<QualifiedName*>(&attr_storage) + i;
    return attrs;
}

void Init()
{
    struct NameEntry {
        const char* name;
        unsigned char length;
        unsigned char is_tag;
        unsigned char is_attr;
    };

    // Namespace
    // Use placement new to initialize the globals.
    AtomicString ns_uri("http://www.w3.org/2000/svg");
    new ((void*)&kNamespaceURI) AtomicString(ns_uri);

    static const NameEntry kNames[] = {
        { "a", 1, 1, 0 },
        { "accumulate", 10, 0, 1 },
        { "additive", 8, 0, 1 },
        { "alignment-baseline", 18, 0, 1 },
        { "amplitude", 9, 0, 1 },
        { "animate", 7, 1, 1 },
        { "animateColor", 12, 1, 0 },
        { "animateMotion", 13, 1, 0 },
        { "animateTransform", 16, 1, 0 },
        { "attributeName", 13, 0, 1 },
        { "attributeType", 13, 0, 1 },
        { "autofocus", 9, 0, 1 },
        { "azimuth", 7, 0, 1 },
        { "baseFrequency", 13, 0, 1 },
        { "baseProfile", 11, 0, 1 },
        { "baseline-shift", 14, 0, 1 },
        { "begin", 5, 0, 1 },
        { "bias", 4, 0, 1 },
        { "buffered-rendering", 18, 0, 1 },
        { "by", 2, 0, 1 },
        { "calcMode", 8, 0, 1 },
        { "circle", 6, 1, 0 },
        { "clip", 4, 0, 1 },
        { "clip-path", 9, 0, 1 },
        { "clip-rule", 9, 0, 1 },
        { "clipPath", 8, 1, 0 },
        { "clipPathUnits", 13, 0, 1 },
        { "color", 5, 0, 1 },
        { "color-interpolation", 19, 0, 1 },
        { "color-interpolation-filters", 27, 0, 1 },
        { "color-rendering", 15, 0, 1 },
        { "crossorigin", 11, 0, 1 },
        { "cursor", 6, 0, 1 },
        { "cx", 2, 0, 1 },
        { "cy", 2, 0, 1 },
        { "d", 1, 0, 1 },
        { "decoding", 8, 0, 1 },
        { "defs", 4, 1, 0 },
        { "desc", 4, 1, 0 },
        { "diffuseConstant", 15, 0, 1 },
        { "direction", 9, 0, 1 },
        { "display", 7, 0, 1 },
        { "divisor", 7, 0, 1 },
        { "dominant-baseline", 17, 0, 1 },
        { "dur", 3, 0, 1 },
        { "dx", 2, 0, 1 },
        { "dy", 2, 0, 1 },
        { "edgeMode", 8, 0, 1 },
        { "elevation", 9, 0, 1 },
        { "ellipse", 7, 1, 0 },
        { "end", 3, 0, 1 },
        { "exponent", 8, 0, 1 },
        { "feBlend", 7, 1, 0 },
        { "feColorMatrix", 13, 1, 0 },
        { "feComponentTransfer", 19, 1, 0 },
        { "feComposite", 11, 1, 0 },
        { "feConvolveMatrix", 16, 1, 0 },
        { "feDiffuseLighting", 17, 1, 0 },
        { "feDisplacementMap", 17, 1, 0 },
        { "feDistantLight", 14, 1, 0 },
        { "feDropShadow", 12, 1, 0 },
        { "feFlood", 7, 1, 0 },
        { "feFuncA", 7, 1, 0 },
        { "feFuncB", 7, 1, 0 },
        { "feFuncG", 7, 1, 0 },
        { "feFuncR", 7, 1, 0 },
        { "feGaussianBlur", 14, 1, 0 },
        { "feImage", 7, 1, 0 },
        { "feMerge", 7, 1, 0 },
        { "feMergeNode", 11, 1, 0 },
        { "feMorphology", 12, 1, 0 },
        { "feOffset", 8, 1, 0 },
        { "fePointLight", 12, 1, 0 },
        { "feSpecularLighting", 18, 1, 0 },
        { "feSpotLight", 11, 1, 0 },
        { "feTile", 6, 1, 0 },
        { "feTurbulence", 12, 1, 0 },
        { "fill", 4, 0, 1 },
        { "fill-opacity", 12, 0, 1 },
        { "fill-rule", 9, 0, 1 },
        { "filter", 6, 1, 1 },
        { "filterUnits", 11, 0, 1 },
        { "flood-color", 11, 0, 1 },
        { "flood-opacity", 13, 0, 1 },
        { "focusgroup", 10, 0, 1 },
        { "font-family", 11, 0, 1 },
        { "font-size", 9, 0, 1 },
        { "font-size-adjust", 16, 0, 1 },
        { "font-stretch", 12, 0, 1 },
        { "font-style", 10, 0, 1 },
        { "font-variant", 12, 0, 1 },
        { "font-weight", 11, 0, 1 },
        { "foreignObject", 13, 1, 0 },
        { "format", 6, 0, 1 },
        { "fr", 2, 0, 1 },
        { "from", 4, 0, 1 },
        { "fx", 2, 0, 1 },
        { "fy", 2, 0, 1 },
        { "g", 1, 1, 0 },
        { "g1", 2, 0, 1 },
        { "g2", 2, 0, 1 },
        { "glyphRef", 8, 0, 1 },
        { "gradientTransform", 17, 0, 1 },
        { "gradientUnits", 13, 0, 1 },
        { "height", 6, 0, 1 },
        { "href", 4, 0, 1 },
        { "image", 5, 1, 0 },
        { "image-rendering", 15, 0, 1 },
        { "in", 2, 0, 1 },
        { "in2", 3, 0, 1 },
        { "intercept", 9, 0, 1 },
        { "interestaction", 14, 0, 1 },
        { "interesttarget", 14, 0, 1 },
        { "k", 1, 0, 1 },
        { "k1", 2, 0, 1 },
        { "k2", 2, 0, 1 },
        { "k3", 2, 0, 1 },
        { "k4", 2, 0, 1 },
        { "kernelMatrix", 12, 0, 1 },
        { "kernelUnitLength", 16, 0, 1 },
        { "keyPoints", 9, 0, 1 },
        { "keySplines", 10, 0, 1 },
        { "keyTimes", 8, 0, 1 },
        { "lang", 4, 0, 1 },
        { "lengthAdjust", 12, 0, 1 },
        { "letter-spacing", 14, 0, 1 },
        { "lighting-color", 14, 0, 1 },
        { "limitingConeAngle", 17, 0, 1 },
        { "line", 4, 1, 0 },
        { "linearGradient", 14, 1, 0 },
        { "local", 5, 0, 1 },
        { "marker", 6, 1, 0 },
        { "marker-end", 10, 0, 1 },
        { "marker-mid", 10, 0, 1 },
        { "marker-start", 12, 0, 1 },
        { "markerHeight", 12, 0, 1 },
        { "markerUnits", 11, 0, 1 },
        { "markerWidth", 11, 0, 1 },
        { "mask", 4, 1, 1 },
        { "mask-type", 9, 0, 1 },
        { "maskContentUnits", 16, 0, 1 },
        { "maskUnits", 9, 0, 1 },
        { "max", 3, 0, 1 },
        { "media", 5, 0, 1 },
        { "metadata", 8, 1, 0 },
        { "method", 6, 0, 1 },
        { "min", 3, 0, 1 },
        { "mode", 4, 0, 1 },
        { "mpath", 5, 1, 0 },
        { "name", 4, 0, 1 },
        { "numOctaves", 10, 0, 1 },
        { "offset", 6, 0, 1 },
        { "onactivate", 10, 0, 1 },
        { "onbegin", 7, 0, 1 },
        { "onend", 5, 0, 1 },
        { "onfocusin", 9, 0, 1 },
        { "onfocusout", 10, 0, 1 },
        { "onrepeat", 8, 0, 1 },
        { "opacity", 7, 0, 1 },
        { "operator", 8, 0, 1 },
        { "order", 5, 0, 1 },
        { "orient", 6, 0, 1 },
        { "origin", 6, 0, 1 },
        { "overflow", 8, 0, 1 },
        { "paint-order", 11, 0, 1 },
        { "path", 4, 1, 1 },
        { "pathLength", 10, 0, 1 },
        { "pattern", 7, 1, 0 },
        { "patternContentUnits", 19, 0, 1 },
        { "patternTransform", 16, 0, 1 },
        { "patternUnits", 12, 0, 1 },
        { "pointer-events", 14, 0, 1 },
        { "points", 6, 0, 1 },
        { "pointsAtX", 9, 0, 1 },
        { "pointsAtY", 9, 0, 1 },
        { "pointsAtZ", 9, 0, 1 },
        { "polygon", 7, 1, 0 },
        { "polyline", 8, 1, 0 },
        { "preserveAlpha", 13, 0, 1 },
        { "preserveAspectRatio", 19, 0, 1 },
        { "primitiveUnits", 14, 0, 1 },
        { "r", 1, 0, 1 },
        { "radialGradient", 14, 1, 0 },
        { "radius", 6, 0, 1 },
        { "rect", 4, 1, 0 },
        { "refX", 4, 0, 1 },
        { "refY", 4, 0, 1 },
        { "repeatCount", 11, 0, 1 },
        { "repeatDur", 9, 0, 1 },
        { "requiredExtensions", 18, 0, 1 },
        { "requiredFeatures", 16, 0, 1 },
        { "restart", 7, 0, 1 },
        { "result", 6, 0, 1 },
        { "rotate", 6, 0, 1 },
        { "rx", 2, 0, 1 },
        { "ry", 2, 0, 1 },
        { "scale", 5, 0, 1 },
        { "script", 6, 1, 0 },
        { "seed", 4, 0, 1 },
        { "set", 3, 1, 0 },
        { "shape-rendering", 15, 0, 1 },
        { "slope", 5, 0, 1 },
        { "spacing", 7, 0, 1 },
        { "specularConstant", 16, 0, 1 },
        { "specularExponent", 16, 0, 1 },
        { "spreadMethod", 12, 0, 1 },
        { "startOffset", 11, 0, 1 },
        { "stdDeviation", 12, 0, 1 },
        { "stitchTiles", 11, 0, 1 },
        { "stop", 4, 1, 0 },
        { "stop-color", 10, 0, 1 },
        { "stop-opacity", 12, 0, 1 },
        { "stroke", 6, 0, 1 },
        { "stroke-dasharray", 16, 0, 1 },
        { "stroke-dashoffset", 17, 0, 1 },
        { "stroke-linecap", 14, 0, 1 },
        { "stroke-linejoin", 15, 0, 1 },
        { "stroke-miterlimit", 17, 0, 1 },
        { "stroke-opacity", 14, 0, 1 },
        { "stroke-width", 12, 0, 1 },
        { "style", 5, 1, 1 },
        { "surfaceScale", 12, 0, 1 },
        { "svg", 3, 1, 0 },
        { "switch", 6, 1, 0 },
        { "symbol", 6, 1, 0 },
        { "systemLanguage", 14, 0, 1 },
        { "tableValues", 11, 0, 1 },
        { "target", 6, 0, 1 },
        { "targetX", 7, 0, 1 },
        { "targetY", 7, 0, 1 },
        { "text", 4, 1, 0 },
        { "text-anchor", 11, 0, 1 },
        { "text-decoration", 15, 0, 1 },
        { "text-rendering", 14, 0, 1 },
        { "textLength", 10, 0, 1 },
        { "textPath", 8, 1, 0 },
        { "title", 5, 1, 1 },
        { "to", 2, 0, 1 },
        { "transform", 9, 0, 1 },
        { "transform-origin", 16, 0, 1 },
        { "tspan", 5, 1, 0 },
        { "type", 4, 0, 1 },
        { "u1", 2, 0, 1 },
        { "u2", 2, 0, 1 },
        { "unicode-bidi", 12, 0, 1 },
        { "use", 3, 1, 0 },
        { "values", 6, 0, 1 },
        { "vector-effect", 13, 0, 1 },
        { "version", 7, 0, 1 },
        { "view", 4, 1, 0 },
        { "viewBox", 7, 0, 1 },
        { "visibility", 10, 0, 1 },
        { "width", 5, 0, 1 },
        { "word-spacing", 12, 0, 1 },
        { "writing-mode", 12, 0, 1 },
        { "x", 1, 0, 1 },
        { "x1", 2, 0, 1 },
        { "x2", 2, 0, 1 },
        { "xChannelSelector", 16, 0, 1 },
        { "y", 1, 0, 1 },
        { "y1", 2, 0, 1 },
        { "y2", 2, 0, 1 },
        { "yChannelSelector", 16, 0, 1 },
        { "z", 1, 0, 1 },
        { "zoomAndPan", 10, 0, 1 },
    };

    size_t tag_i = 0;
    size_t attr_i = 0;
    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        if (kNames[i].is_tag) {
            void* address = reinterpret_cast<SVGQualifiedName*>(&tag_storage) + tag_i;
            QualifiedName::CreateStatic(address, impl, ns_uri);
            ++tag_i;
        }

        if (!kNames[i].is_attr)
            continue;
        void* address = reinterpret_cast<QualifiedName*>(&attr_storage) + attr_i;
        QualifiedName::CreateStatic(address, impl);
        ++attr_i;
    }
    DCHECK_EQ(tag_i, kTagsCount);
    DCHECK_EQ(attr_i, kAttrsCount);
}

} // namespace svg_names
} // namespace blink
