// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/templates/cssom_keywords.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/css/cssom/cssom_keywords.h"

#include "third_party/blink/renderer/core/css/cssom/css_keyword_value.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/core/css/properties/css_parsing_utils.h"

namespace blink {

bool CSSOMKeywords::ValidKeywordForProperty(CSSPropertyID id, const CSSKeywordValue& keyword)
{
    CSSValueID valueID = keyword.KeywordValueID();
    if (!IsValidCSSValueID(valueID)) {
        return false;
    }

    if (css_parsing_utils::IsCSSWideKeyword(valueID)) {
        // TODO(crbug.com/1310761): Support CSS-wide keywords in custom props.
        return id != CSSPropertyID::kVariable;
    }

    switch (id) {
    case CSSPropertyID::kForcedColorAdjust: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
        case CSSValueID::kPreserveParentColor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPosition: {
        switch (valueID) {
        case CSSValueID::kStatic:
        case CSSValueID::kRelative:
        case CSSValueID::kAbsolute:
        case CSSValueID::kFixed:
        case CSSValueID::kSticky:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPositionAnchor: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextSizeAdjust: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kDirection: {
        switch (valueID) {
        case CSSValueID::kLtr:
        case CSSValueID::kRtl:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontFeatureSettings: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontKerning: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNormal:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontOpticalSizing: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontPalette: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kLight:
        case CSSValueID::kDark:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontSize: {
        switch (valueID) {
        case CSSValueID::kXxSmall:
        case CSSValueID::kXSmall:
        case CSSValueID::kSmall:
        case CSSValueID::kMedium:
        case CSSValueID::kLarge:
        case CSSValueID::kXLarge:
        case CSSValueID::kXxLarge:
        case CSSValueID::kXxxLarge:
        case CSSValueID::kLarger:
        case CSSValueID::kSmaller:
        case CSSValueID::kWebkitXxxLarge:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontSizeAdjust: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kExHeight:
        case CSSValueID::kCapHeight:
        case CSSValueID::kChWidth:
        case CSSValueID::kIcWidth:
        case CSSValueID::kIcHeight:
        case CSSValueID::kFromFont:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontStretch: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kUltraCondensed:
        case CSSValueID::kExtraCondensed:
        case CSSValueID::kCondensed:
        case CSSValueID::kSemiCondensed:
        case CSSValueID::kSemiExpanded:
        case CSSValueID::kExpanded:
        case CSSValueID::kExtraExpanded:
        case CSSValueID::kUltraExpanded:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontStyle: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kItalic:
        case CSSValueID::kOblique:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontSynthesisSmallCaps: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontSynthesisStyle: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontSynthesisWeight: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantAlternates: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantCaps: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kSmallCaps:
        case CSSValueID::kAllSmallCaps:
        case CSSValueID::kPetiteCaps:
        case CSSValueID::kAllPetiteCaps:
        case CSSValueID::kUnicase:
        case CSSValueID::kTitlingCaps:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantEastAsian: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kJis78:
        case CSSValueID::kJis83:
        case CSSValueID::kJis90:
        case CSSValueID::kJis04:
        case CSSValueID::kSimplified:
        case CSSValueID::kTraditional:
        case CSSValueID::kFullWidth:
        case CSSValueID::kProportionalWidth:
        case CSSValueID::kRuby:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantEmoji: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kText:
        case CSSValueID::kEmoji:
        case CSSValueID::kUnicode:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantLigatures: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kNone:
        case CSSValueID::kCommonLigatures:
        case CSSValueID::kNoCommonLigatures:
        case CSSValueID::kDiscretionaryLigatures:
        case CSSValueID::kNoDiscretionaryLigatures:
        case CSSValueID::kHistoricalLigatures:
        case CSSValueID::kNoHistoricalLigatures:
        case CSSValueID::kContextual:
        case CSSValueID::kNoContextual:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantNumeric: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kLiningNums:
        case CSSValueID::kOldstyleNums:
        case CSSValueID::kProportionalNums:
        case CSSValueID::kTabularNums:
        case CSSValueID::kDiagonalFractions:
        case CSSValueID::kStackedFractions:
        case CSSValueID::kOrdinal:
        case CSSValueID::kSlashedZero:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariantPosition: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kSub:
        case CSSValueID::kSuper:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontVariationSettings: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFontWeight: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kBold:
        case CSSValueID::kBolder:
        case CSSValueID::kLighter:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kInsetArea: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kTop:
        case CSSValueID::kBottom:
        case CSSValueID::kCenter:
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
        case CSSValueID::kXStart:
        case CSSValueID::kXEnd:
        case CSSValueID::kYStart:
        case CSSValueID::kYEnd:
        case CSSValueID::kStart:
        case CSSValueID::kEnd:
        case CSSValueID::kSelfStart:
        case CSSValueID::kSelfEnd:
        case CSSValueID::kAll:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPositionArea: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kTop:
        case CSSValueID::kBottom:
        case CSSValueID::kCenter:
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
        case CSSValueID::kXStart:
        case CSSValueID::kXEnd:
        case CSSValueID::kYStart:
        case CSSValueID::kYEnd:
        case CSSValueID::kStart:
        case CSSValueID::kEnd:
        case CSSValueID::kSelfStart:
        case CSSValueID::kSelfEnd:
        case CSSValueID::kAll:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextOrientation: {
        switch (valueID) {
        case CSSValueID::kSideways:
        case CSSValueID::kMixed:
        case CSSValueID::kUpright:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextRendering: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kOptimizespeed:
        case CSSValueID::kOptimizelegibility:
        case CSSValueID::kGeometricprecision:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextSpacingTrim: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kSpaceAll:
        case CSSValueID::kSpaceFirst:
        case CSSValueID::kTrimStart:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kWritingMode: {
        switch (valueID) {
        case CSSValueID::kHorizontalTb:
        case CSSValueID::kVerticalRl:
        case CSSValueID::kVerticalLr:
        case CSSValueID::kSidewaysRl:
        case CSSValueID::kSidewaysLr:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAccentColor: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAlignmentBaseline: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kBaseline:
        case CSSValueID::kAlphabetic:
        case CSSValueID::kIdeographic:
        case CSSValueID::kMiddle:
        case CSSValueID::kCentral:
        case CSSValueID::kMathematical:
        case CSSValueID::kBeforeEdge:
        case CSSValueID::kTextBeforeEdge:
        case CSSValueID::kAfterEdge:
        case CSSValueID::kTextAfterEdge:
        case CSSValueID::kHanging:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnchorName: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnchorScope: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAll:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationComposition: {
        switch (valueID) {
        case CSSValueID::kReplace:
        case CSSValueID::kAdd:
        case CSSValueID::kAccumulate:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationDirection: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kReverse:
        case CSSValueID::kAlternate:
        case CSSValueID::kAlternateReverse:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationFillMode: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kForwards:
        case CSSValueID::kBackwards:
        case CSSValueID::kBoth:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationIterationCount: {
        switch (valueID) {
        case CSSValueID::kInfinite:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationName: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationPlayState: {
        switch (valueID) {
        case CSSValueID::kRunning:
        case CSSValueID::kPaused:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationTimeline: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kAnimationTimingFunction: {
        switch (valueID) {
        case CSSValueID::kLinear:
        case CSSValueID::kEase:
        case CSSValueID::kEaseIn:
        case CSSValueID::kEaseOut:
        case CSSValueID::kEaseInOut:
        case CSSValueID::kJumpBoth:
        case CSSValueID::kJumpEnd:
        case CSSValueID::kJumpNone:
        case CSSValueID::kJumpStart:
        case CSSValueID::kStepStart:
        case CSSValueID::kStepEnd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackdropFilter: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackfaceVisibility: {
        switch (valueID) {
        case CSSValueID::kVisible:
        case CSSValueID::kHidden:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundAttachment: {
        switch (valueID) {
        case CSSValueID::kScroll:
        case CSSValueID::kFixed:
        case CSSValueID::kLocal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundBlendMode: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kMultiply:
        case CSSValueID::kScreen:
        case CSSValueID::kOverlay:
        case CSSValueID::kDarken:
        case CSSValueID::kLighten:
        case CSSValueID::kColorDodge:
        case CSSValueID::kColorBurn:
        case CSSValueID::kHardLight:
        case CSSValueID::kSoftLight:
        case CSSValueID::kDifference:
        case CSSValueID::kExclusion:
        case CSSValueID::kHue:
        case CSSValueID::kSaturation:
        case CSSValueID::kColor:
        case CSSValueID::kLuminosity:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundClip: {
        switch (valueID) {
        case CSSValueID::kBorderBox:
        case CSSValueID::kPaddingBox:
        case CSSValueID::kContentBox:
        case CSSValueID::kText:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundImage: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundOrigin: {
        switch (valueID) {
        case CSSValueID::kBorderBox:
        case CSSValueID::kPaddingBox:
        case CSSValueID::kContentBox:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBackgroundSize: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kCover:
        case CSSValueID::kContain:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBaselineShift: {
        switch (valueID) {
        case CSSValueID::kBaseline:
        case CSSValueID::kSub:
        case CSSValueID::kSuper:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBaselineSource: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFirst:
        case CSSValueID::kLast:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBlockSize: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderBottomColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderBottomStyle: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kHidden:
        case CSSValueID::kInset:
        case CSSValueID::kGroove:
        case CSSValueID::kOutset:
        case CSSValueID::kRidge:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderBottomWidth: {
        switch (valueID) {
        case CSSValueID::kThin:
        case CSSValueID::kMedium:
        case CSSValueID::kThick:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderCollapse: {
        switch (valueID) {
        case CSSValueID::kSeparate:
        case CSSValueID::kCollapse:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderImageRepeat: {
        switch (valueID) {
        case CSSValueID::kStretch:
        case CSSValueID::kRepeat:
        case CSSValueID::kRound:
        case CSSValueID::kSpace:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderImageSource: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderImageWidth: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderLeftColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderLeftStyle: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kHidden:
        case CSSValueID::kInset:
        case CSSValueID::kGroove:
        case CSSValueID::kOutset:
        case CSSValueID::kRidge:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderLeftWidth: {
        switch (valueID) {
        case CSSValueID::kThin:
        case CSSValueID::kMedium:
        case CSSValueID::kThick:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderRightColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderRightStyle: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kHidden:
        case CSSValueID::kInset:
        case CSSValueID::kGroove:
        case CSSValueID::kOutset:
        case CSSValueID::kRidge:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderRightWidth: {
        switch (valueID) {
        case CSSValueID::kThin:
        case CSSValueID::kMedium:
        case CSSValueID::kThick:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderTopColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderTopStyle: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kHidden:
        case CSSValueID::kInset:
        case CSSValueID::kGroove:
        case CSSValueID::kOutset:
        case CSSValueID::kRidge:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBorderTopWidth: {
        switch (valueID) {
        case CSSValueID::kThin:
        case CSSValueID::kMedium:
        case CSSValueID::kThick:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBottom: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBoxShadow: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBoxSizing: {
        switch (valueID) {
        case CSSValueID::kContentBox:
        case CSSValueID::kBorderBox:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBreakAfter: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kAvoid:
        case CSSValueID::kAvoidColumn:
        case CSSValueID::kAvoidPage:
        case CSSValueID::kColumn:
        case CSSValueID::kLeft:
        case CSSValueID::kPage:
        case CSSValueID::kRecto:
        case CSSValueID::kRight:
        case CSSValueID::kVerso:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBreakBefore: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kAvoid:
        case CSSValueID::kAvoidColumn:
        case CSSValueID::kAvoidPage:
        case CSSValueID::kColumn:
        case CSSValueID::kLeft:
        case CSSValueID::kPage:
        case CSSValueID::kRecto:
        case CSSValueID::kRight:
        case CSSValueID::kVerso:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kBreakInside: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kAvoid:
        case CSSValueID::kAvoidColumn:
        case CSSValueID::kAvoidPage:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCaptionSide: {
        switch (valueID) {
        case CSSValueID::kTop:
        case CSSValueID::kBottom:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCaretAnimation: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kManual:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCaretColor: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kClear: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
        case CSSValueID::kBoth:
        case CSSValueID::kInlineStart:
        case CSSValueID::kInlineEnd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kClip: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kClipPath: {
        switch (valueID) {
        case CSSValueID::kBorderBox:
        case CSSValueID::kPaddingBox:
        case CSSValueID::kContentBox:
        case CSSValueID::kMarginBox:
        case CSSValueID::kFillBox:
        case CSSValueID::kStrokeBox:
        case CSSValueID::kViewBox:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kClipRule: {
        switch (valueID) {
        case CSSValueID::kNonzero:
        case CSSValueID::kEvenodd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColorInterpolation: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kSRGB:
        case CSSValueID::kLinearrgb:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColorInterpolationFilters: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kSRGB:
        case CSSValueID::kLinearrgb:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColorRendering: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kOptimizespeed:
        case CSSValueID::kOptimizequality:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnCount: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnFill: {
        switch (valueID) {
        case CSSValueID::kBalance:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnGap: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnRuleColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnRuleStyle: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kHidden:
        case CSSValueID::kInset:
        case CSSValueID::kGroove:
        case CSSValueID::kOutset:
        case CSSValueID::kRidge:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnRuleWidth: {
        switch (valueID) {
        case CSSValueID::kThin:
        case CSSValueID::kMedium:
        case CSSValueID::kThick:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnSpan: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAll:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kColumnWidth: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kContain: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kStrict:
        case CSSValueID::kContent:
        case CSSValueID::kSize:
        case CSSValueID::kLayout:
        case CSSValueID::kStyle:
        case CSSValueID::kPaint:
        case CSSValueID::kInlineSize:
        case CSSValueID::kBlockSize:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kContainerName: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kContainerType: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kInlineSize:
        case CSSValueID::kSize:
        case CSSValueID::kScrollState:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kContentVisibility: {
        switch (valueID) {
        case CSSValueID::kVisible:
        case CSSValueID::kAuto:
        case CSSValueID::kHidden:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCounterIncrement: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCounterReset: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCounterSet: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kCursor: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kDefault:
        case CSSValueID::kNone:
        case CSSValueID::kContextMenu:
        case CSSValueID::kHelp:
        case CSSValueID::kPointer:
        case CSSValueID::kProgress:
        case CSSValueID::kWait:
        case CSSValueID::kCell:
        case CSSValueID::kCrosshair:
        case CSSValueID::kText:
        case CSSValueID::kVerticalText:
        case CSSValueID::kAlias:
        case CSSValueID::kCopy:
        case CSSValueID::kMove:
        case CSSValueID::kNoDrop:
        case CSSValueID::kNotAllowed:
        case CSSValueID::kEResize:
        case CSSValueID::kNResize:
        case CSSValueID::kNeResize:
        case CSSValueID::kNwResize:
        case CSSValueID::kSResize:
        case CSSValueID::kSeResize:
        case CSSValueID::kSwResize:
        case CSSValueID::kWResize:
        case CSSValueID::kEwResize:
        case CSSValueID::kNsResize:
        case CSSValueID::kNeswResize:
        case CSSValueID::kNwseResize:
        case CSSValueID::kColResize:
        case CSSValueID::kRowResize:
        case CSSValueID::kAllScroll:
        case CSSValueID::kZoomIn:
        case CSSValueID::kZoomOut:
        case CSSValueID::kGrab:
        case CSSValueID::kGrabbing:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kD: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kDisplay: {
        switch (valueID) {
        case CSSValueID::kInline:
        case CSSValueID::kBlock:
        case CSSValueID::kListItem:
        case CSSValueID::kInlineBlock:
        case CSSValueID::kTable:
        case CSSValueID::kInlineTable:
        case CSSValueID::kTableRowGroup:
        case CSSValueID::kTableHeaderGroup:
        case CSSValueID::kTableFooterGroup:
        case CSSValueID::kTableRow:
        case CSSValueID::kTableColumnGroup:
        case CSSValueID::kTableColumn:
        case CSSValueID::kTableCell:
        case CSSValueID::kTableCaption:
        case CSSValueID::kWebkitBox:
        case CSSValueID::kWebkitInlineBox:
        case CSSValueID::kFlex:
        case CSSValueID::kInlineFlex:
        case CSSValueID::kGrid:
        case CSSValueID::kInlineGrid:
        case CSSValueID::kContents:
        case CSSValueID::kFlowRoot:
        case CSSValueID::kNone:
        case CSSValueID::kFlow:
        case CSSValueID::kMath:
        case CSSValueID::kRuby:
        case CSSValueID::kRubyText:
        case CSSValueID::kMasonry:
        case CSSValueID::kInlineMasonry:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kDominantBaseline: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kAlphabetic:
        case CSSValueID::kIdeographic:
        case CSSValueID::kMiddle:
        case CSSValueID::kCentral:
        case CSSValueID::kMathematical:
        case CSSValueID::kHanging:
        case CSSValueID::kUseScript:
        case CSSValueID::kNoChange:
        case CSSValueID::kResetSize:
        case CSSValueID::kTextAfterEdge:
        case CSSValueID::kTextBeforeEdge:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kDynamicRangeLimit: {
        switch (valueID) {
        case CSSValueID::kStandard:
        case CSSValueID::kHigh:
        case CSSValueID::kConstrainedHigh:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kEmptyCells: {
        switch (valueID) {
        case CSSValueID::kShow:
        case CSSValueID::kHide:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFieldSizing: {
        switch (valueID) {
        case CSSValueID::kFixed:
        case CSSValueID::kContent:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFillRule: {
        switch (valueID) {
        case CSSValueID::kNonzero:
        case CSSValueID::kEvenodd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFilter: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFlexBasis: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFitContent:
        case CSSValueID::kMinContent:
        case CSSValueID::kMaxContent:
        case CSSValueID::kContent:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFlexDirection: {
        switch (valueID) {
        case CSSValueID::kRow:
        case CSSValueID::kRowReverse:
        case CSSValueID::kColumn:
        case CSSValueID::kColumnReverse:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFlexWrap: {
        switch (valueID) {
        case CSSValueID::kNowrap:
        case CSSValueID::kWrap:
        case CSSValueID::kWrapReverse:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFloat: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
        case CSSValueID::kInlineStart:
        case CSSValueID::kInlineEnd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kFloodColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridAutoColumns: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kMinContent:
        case CSSValueID::kMaxContent:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridAutoFlow: {
        switch (valueID) {
        case CSSValueID::kRow:
        case CSSValueID::kColumn:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridAutoRows: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kMinContent:
        case CSSValueID::kMaxContent:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridColumnEnd: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridColumnStart: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridRowEnd: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridRowStart: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridTemplateAreas: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridTemplateColumns: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kGridTemplateRows: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kHeight: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFitContent:
        case CSSValueID::kMinContent:
        case CSSValueID::kMaxContent:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kHyphens: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kManual:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kImageRendering: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kOptimizespeed:
        case CSSValueID::kOptimizequality:
        case CSSValueID::kWebkitOptimizeContrast:
        case CSSValueID::kPixelated:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kInlineSize: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kInteractivity: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kInert:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kInterpolateSize: {
        switch (valueID) {
        case CSSValueID::kNumericOnly:
        case CSSValueID::kAllowKeywords:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kIsolation: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kIsolate:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kLeft: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kLetterSpacing: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kLightingColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kLineBreak: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kLoose:
        case CSSValueID::kNormal:
        case CSSValueID::kStrict:
        case CSSValueID::kAnywhere:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kLineHeight: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kListStyleImage: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kListStylePosition: {
        switch (valueID) {
        case CSSValueID::kOutside:
        case CSSValueID::kInside:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarginBottom: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarginLeft: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarginRight: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarginTop: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarkerEnd: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarkerMid: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMarkerStart: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMaskType: {
        switch (valueID) {
        case CSSValueID::kLuminance:
        case CSSValueID::kAlpha:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMasonryTrackEnd: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMasonryTrackStart: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMathShift: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kCompact:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMathStyle: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kCompact:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMaxBlockSize: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMaxHeight: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMaxInlineSize: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMaxWidth: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kMixBlendMode: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kMultiply:
        case CSSValueID::kScreen:
        case CSSValueID::kOverlay:
        case CSSValueID::kDarken:
        case CSSValueID::kLighten:
        case CSSValueID::kColorDodge:
        case CSSValueID::kColorBurn:
        case CSSValueID::kHardLight:
        case CSSValueID::kSoftLight:
        case CSSValueID::kDifference:
        case CSSValueID::kExclusion:
        case CSSValueID::kHue:
        case CSSValueID::kSaturation:
        case CSSValueID::kColor:
        case CSSValueID::kLuminosity:
        case CSSValueID::kPlusLighter:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kObjectFit: {
        switch (valueID) {
        case CSSValueID::kFill:
        case CSSValueID::kContain:
        case CSSValueID::kCover:
        case CSSValueID::kNone:
        case CSSValueID::kScaleDown:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kObjectViewBox: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOffsetAnchor: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOffsetPath: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOffsetPosition: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOffsetRotate: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kReverse:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOriginTrialTestProperty: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOutlineColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOutlineStyle: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kHidden:
        case CSSValueID::kInset:
        case CSSValueID::kGroove:
        case CSSValueID::kOutset:
        case CSSValueID::kRidge:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOutlineWidth: {
        switch (valueID) {
        case CSSValueID::kThin:
        case CSSValueID::kMedium:
        case CSSValueID::kThick:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverflowAnchor: {
        switch (valueID) {
        case CSSValueID::kVisible:
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverflowWrap: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kBreakWord:
        case CSSValueID::kAnywhere:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverflowX: {
        switch (valueID) {
        case CSSValueID::kVisible:
        case CSSValueID::kHidden:
        case CSSValueID::kScroll:
        case CSSValueID::kAuto:
        case CSSValueID::kOverlay:
        case CSSValueID::kClip:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverflowY: {
        switch (valueID) {
        case CSSValueID::kVisible:
        case CSSValueID::kHidden:
        case CSSValueID::kScroll:
        case CSSValueID::kAuto:
        case CSSValueID::kOverlay:
        case CSSValueID::kClip:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverlay: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverscrollBehaviorX: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kContain:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kOverscrollBehaviorY: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kContain:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPage: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPaintOrder: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kFill:
        case CSSValueID::kStroke:
        case CSSValueID::kMarkers:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPerspective: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPointerEvents: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
        case CSSValueID::kStroke:
        case CSSValueID::kFill:
        case CSSValueID::kPainted:
        case CSSValueID::kVisible:
        case CSSValueID::kVisiblestroke:
        case CSSValueID::kVisiblefill:
        case CSSValueID::kVisiblepainted:
        case CSSValueID::kBoundingBox:
        case CSSValueID::kAll:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPositionTryFallbacks: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kFlipBlock:
        case CSSValueID::kFlipInline:
        case CSSValueID::kFlipStart:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPositionTryOrder: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kMostWidth:
        case CSSValueID::kMostHeight:
        case CSSValueID::kMostBlockSize:
        case CSSValueID::kMostInlineSize:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kPositionVisibility: {
        switch (valueID) {
        case CSSValueID::kAlways:
        case CSSValueID::kAnchorsVisible:
        case CSSValueID::kNoOverflow:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kQuotes: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kReadingFlow: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kFlexVisual:
        case CSSValueID::kFlexFlow:
        case CSSValueID::kGridRows:
        case CSSValueID::kGridColumns:
        case CSSValueID::kGridOrder:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kResize: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kBoth:
        case CSSValueID::kHorizontal:
        case CSSValueID::kVertical:
        case CSSValueID::kBlock:
        case CSSValueID::kInline:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kRight: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kRowGap: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kRx: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kRy: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollBehavior: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kSmooth:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollMarkerGroup: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAfter:
        case CSSValueID::kBefore:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingBlockEnd: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingBlockStart: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingBottom: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingInlineEnd: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingInlineStart: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingLeft: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingRight: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollPaddingTop: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollSnapAlign: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kStart:
        case CSSValueID::kEnd:
        case CSSValueID::kCenter:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollSnapStop: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kAlways:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollSnapType: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kX:
        case CSSValueID::kY:
        case CSSValueID::kBlock:
        case CSSValueID::kInline:
        case CSSValueID::kBoth:
        case CSSValueID::kMandatory:
        case CSSValueID::kProximity:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollbarGutter: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kStable:
        case CSSValueID::kBothEdges:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kScrollbarWidth: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kThin:
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kShapeOutside: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kShapeRendering: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kOptimizespeed:
        case CSSValueID::kCrispedges:
        case CSSValueID::kGeometricprecision:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kStopColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kStrokeDasharray: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kStrokeLinecap: {
        switch (valueID) {
        case CSSValueID::kButt:
        case CSSValueID::kRound:
        case CSSValueID::kSquare:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kStrokeLinejoin: {
        switch (valueID) {
        case CSSValueID::kMiter:
        case CSSValueID::kBevel:
        case CSSValueID::kRound:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTableLayout: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFixed:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextAlign: {
        switch (valueID) {
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
        case CSSValueID::kCenter:
        case CSSValueID::kJustify:
        case CSSValueID::kWebkitLeft:
        case CSSValueID::kWebkitRight:
        case CSSValueID::kWebkitCenter:
        case CSSValueID::kStart:
        case CSSValueID::kEnd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextAlignLast: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kStart:
        case CSSValueID::kEnd:
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
        case CSSValueID::kCenter:
        case CSSValueID::kJustify:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextAnchor: {
        switch (valueID) {
        case CSSValueID::kStart:
        case CSSValueID::kMiddle:
        case CSSValueID::kEnd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextAutospace: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kNoAutospace:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextBoxTrim: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kTrimStart:
        case CSSValueID::kTrimEnd:
        case CSSValueID::kTrimBoth:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextCombineUpright: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAll:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextDecorationColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextDecorationLine: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kUnderline:
        case CSSValueID::kOverline:
        case CSSValueID::kLineThrough:
        case CSSValueID::kBlink:
        case CSSValueID::kSpellingError:
        case CSSValueID::kGrammarError:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextDecorationSkipInk: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextDecorationStyle: {
        switch (valueID) {
        case CSSValueID::kSolid:
        case CSSValueID::kDouble:
        case CSSValueID::kDotted:
        case CSSValueID::kDashed:
        case CSSValueID::kWavy:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextDecorationThickness: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFromFont:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextEmphasisColor: {
        switch (valueID) {
        case CSSValueID::kCurrentcolor:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextOverflow: {
        switch (valueID) {
        case CSSValueID::kClip:
        case CSSValueID::kEllipsis:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextShadow: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextTransform: {
        switch (valueID) {
        case CSSValueID::kCapitalize:
        case CSSValueID::kUppercase:
        case CSSValueID::kLowercase:
        case CSSValueID::kNone:
        case CSSValueID::kMathAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextUnderlineOffset: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextUnderlinePosition: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFromFont:
        case CSSValueID::kUnder:
        case CSSValueID::kLeft:
        case CSSValueID::kRight:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextWrapMode: {
        switch (valueID) {
        case CSSValueID::kWrap:
        case CSSValueID::kNowrap:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTextWrapStyle: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kBalance:
        case CSSValueID::kPretty:
        case CSSValueID::kStable:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTop: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTouchAction: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
        case CSSValueID::kPanX:
        case CSSValueID::kPanLeft:
        case CSSValueID::kPanRight:
        case CSSValueID::kPanY:
        case CSSValueID::kPanUp:
        case CSSValueID::kPanDown:
        case CSSValueID::kPinchZoom:
        case CSSValueID::kManipulation:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTransform: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTransformBox: {
        switch (valueID) {
        case CSSValueID::kContentBox:
        case CSSValueID::kBorderBox:
        case CSSValueID::kFillBox:
        case CSSValueID::kStrokeBox:
        case CSSValueID::kViewBox:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTransformStyle: {
        switch (valueID) {
        case CSSValueID::kFlat:
        case CSSValueID::kPreserve3d:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTransitionBehavior: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kAllowDiscrete:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTransitionProperty: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kTransitionTimingFunction: {
        switch (valueID) {
        case CSSValueID::kLinear:
        case CSSValueID::kEase:
        case CSSValueID::kEaseIn:
        case CSSValueID::kEaseOut:
        case CSSValueID::kEaseInOut:
        case CSSValueID::kJumpBoth:
        case CSSValueID::kJumpEnd:
        case CSSValueID::kJumpNone:
        case CSSValueID::kJumpStart:
        case CSSValueID::kStepStart:
        case CSSValueID::kStepEnd:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kUnicodeBidi: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kEmbed:
        case CSSValueID::kBidiOverride:
        case CSSValueID::kIsolate:
        case CSSValueID::kPlaintext:
        case CSSValueID::kIsolateOverride:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kUserSelect: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kNone:
        case CSSValueID::kText:
        case CSSValueID::kAll:
        case CSSValueID::kContain:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kVectorEffect: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kNonScalingStroke:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kVerticalAlign: {
        switch (valueID) {
        case CSSValueID::kBaseline:
        case CSSValueID::kSub:
        case CSSValueID::kSuper:
        case CSSValueID::kTextTop:
        case CSSValueID::kTextBottom:
        case CSSValueID::kMiddle:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kViewTransitionCaptureMode: {
        switch (valueID) {
        case CSSValueID::kFlat:
        case CSSValueID::kLayered:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kViewTransitionClass: {
        switch (valueID) {
        case CSSValueID::kNone:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kViewTransitionGroup: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kContain:
        case CSSValueID::kNearest:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kViewTransitionName: {
        switch (valueID) {
        case CSSValueID::kNone:
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kVisibility: {
        switch (valueID) {
        case CSSValueID::kVisible:
        case CSSValueID::kHidden:
        case CSSValueID::kCollapse:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kWhiteSpaceCollapse: {
        switch (valueID) {
        case CSSValueID::kCollapse:
        case CSSValueID::kPreserve:
        case CSSValueID::kPreserveBreaks:
        case CSSValueID::kBreakSpaces:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kWidth: {
        switch (valueID) {
        case CSSValueID::kAuto:
        case CSSValueID::kFitContent:
        case CSSValueID::kMinContent:
        case CSSValueID::kMaxContent:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kWillChange: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kWordBreak: {
        switch (valueID) {
        case CSSValueID::kNormal:
        case CSSValueID::kBreakAll:
        case CSSValueID::kKeepAll:
        case CSSValueID::kBreakWord:
        case CSSValueID::kAutoPhrase:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kWordSpacing: {
        switch (valueID) {
        case CSSValueID::kNormal:
            return true;
        default:
            return false;
        }
    }
    case CSSPropertyID::kZIndex: {
        switch (valueID) {
        case CSSValueID::kAuto:
            return true;
        default:
            return false;
        }
    }
    default:
        return false;
    }
}

} // namespace blink
