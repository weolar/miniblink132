/*
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2013 Intel Corporation. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

// Generated from template:
//   core/css/templates/style_property_shorthand.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/style_property_shorthand.h"

#include <iterator>

#include "third_party/blink/renderer/core/css/properties/longhands.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

static const StylePropertyShorthand* alternativeAnimationWithTimelineShorthand1()
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAnimationDuration(),
        &GetCSSPropertyAnimationTimingFunction(),
        &GetCSSPropertyAnimationDelay(),
        &GetCSSPropertyAnimationIterationCount(),
        &GetCSSPropertyAnimationDirection(),
        &GetCSSPropertyAnimationFillMode(),
        &GetCSSPropertyAnimationPlayState(),
        &GetCSSPropertyAnimationName(),
        &GetCSSPropertyAnimationTimeline(),
        &GetCSSPropertyAnimationRangeStart(),
        &GetCSSPropertyAnimationRangeEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kAlternativeAnimationWithTimeline, longhands);
    return &shorthand;
}

const StylePropertyShorthand& alternativeAnimationWithTimelineShorthand()
{
    if (const auto* s = alternativeAnimationWithTimelineShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::ScrollTimelineEnabled());

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAnimationDuration(),
        &GetCSSPropertyAnimationTimingFunction(),
        &GetCSSPropertyAnimationDelay(),
        &GetCSSPropertyAnimationIterationCount(),
        &GetCSSPropertyAnimationDirection(),
        &GetCSSPropertyAnimationFillMode(),
        &GetCSSPropertyAnimationPlayState(),
        &GetCSSPropertyAnimationName(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kAlternativeAnimationWithTimeline, longhands);
    return shorthand;
}

const StylePropertyShorthand& animationShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAnimationDuration(),
        &GetCSSPropertyAnimationTimingFunction(),
        &GetCSSPropertyAnimationDelay(),
        &GetCSSPropertyAnimationIterationCount(),
        &GetCSSPropertyAnimationDirection(),
        &GetCSSPropertyAnimationFillMode(),
        &GetCSSPropertyAnimationPlayState(),
        &GetCSSPropertyAnimationName(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kAnimation, longhands);
    return shorthand;
}

static const StylePropertyShorthand* animationRangeShorthand1()
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAnimationRangeStart(),
        &GetCSSPropertyAnimationRangeEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kAnimationRange, longhands);
    return &shorthand;
}

const StylePropertyShorthand& animationRangeShorthand()
{
    if (const auto* s = animationRangeShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::ScrollTimelineEnabled());

    static StylePropertyShorthand empty_shorthand;
    return empty_shorthand;
}

const StylePropertyShorthand& backgroundShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBackgroundImage(),
        &GetCSSPropertyBackgroundPositionX(),
        &GetCSSPropertyBackgroundPositionY(),
        &GetCSSPropertyBackgroundSize(),
        &GetCSSPropertyBackgroundRepeat(),
        &GetCSSPropertyBackgroundAttachment(),
        &GetCSSPropertyBackgroundOrigin(),
        &GetCSSPropertyBackgroundClip(),
        &GetCSSPropertyBackgroundColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBackground, longhands);
    return shorthand;
}

const StylePropertyShorthand& backgroundPositionShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBackgroundPositionX(),
        &GetCSSPropertyBackgroundPositionY(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBackgroundPosition, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderTopColor(),
        &GetCSSPropertyBorderTopStyle(),
        &GetCSSPropertyBorderTopWidth(),
        &GetCSSPropertyBorderRightColor(),
        &GetCSSPropertyBorderRightStyle(),
        &GetCSSPropertyBorderRightWidth(),
        &GetCSSPropertyBorderBottomColor(),
        &GetCSSPropertyBorderBottomStyle(),
        &GetCSSPropertyBorderBottomWidth(),
        &GetCSSPropertyBorderLeftColor(),
        &GetCSSPropertyBorderLeftStyle(),
        &GetCSSPropertyBorderLeftWidth(),
        &GetCSSPropertyBorderImageSource(),
        &GetCSSPropertyBorderImageSlice(),
        &GetCSSPropertyBorderImageWidth(),
        &GetCSSPropertyBorderImageOutset(),
        &GetCSSPropertyBorderImageRepeat(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorder, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBlockShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBlockStartColor(),
        &GetCSSPropertyBorderBlockStartStyle(),
        &GetCSSPropertyBorderBlockStartWidth(),
        &GetCSSPropertyBorderBlockEndColor(),
        &GetCSSPropertyBorderBlockEndStyle(),
        &GetCSSPropertyBorderBlockEndWidth(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBlock, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBlockColorShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBlockStartColor(),
        &GetCSSPropertyBorderBlockEndColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBlockColor, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBlockEndShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBlockEndWidth(),
        &GetCSSPropertyBorderBlockEndStyle(),
        &GetCSSPropertyBorderBlockEndColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBlockEnd, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBlockStartShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBlockStartWidth(),
        &GetCSSPropertyBorderBlockStartStyle(),
        &GetCSSPropertyBorderBlockStartColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBlockStart, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBlockStyleShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBlockStartStyle(),
        &GetCSSPropertyBorderBlockEndStyle(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBlockStyle, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBlockWidthShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBlockStartWidth(),
        &GetCSSPropertyBorderBlockEndWidth(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBlockWidth, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderBottomShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderBottomWidth(),
        &GetCSSPropertyBorderBottomStyle(),
        &GetCSSPropertyBorderBottomColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderBottom, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderColorShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderTopColor(),
        &GetCSSPropertyBorderRightColor(),
        &GetCSSPropertyBorderBottomColor(),
        &GetCSSPropertyBorderLeftColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderColor, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderImageShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderImageSource(),
        &GetCSSPropertyBorderImageSlice(),
        &GetCSSPropertyBorderImageWidth(),
        &GetCSSPropertyBorderImageOutset(),
        &GetCSSPropertyBorderImageRepeat(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderImage, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderInlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderInlineStartColor(),
        &GetCSSPropertyBorderInlineStartStyle(),
        &GetCSSPropertyBorderInlineStartWidth(),
        &GetCSSPropertyBorderInlineEndColor(),
        &GetCSSPropertyBorderInlineEndStyle(),
        &GetCSSPropertyBorderInlineEndWidth(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderInline, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderInlineColorShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderInlineStartColor(),
        &GetCSSPropertyBorderInlineEndColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderInlineColor, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderInlineEndShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderInlineEndWidth(),
        &GetCSSPropertyBorderInlineEndStyle(),
        &GetCSSPropertyBorderInlineEndColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderInlineEnd, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderInlineStartShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderInlineStartWidth(),
        &GetCSSPropertyBorderInlineStartStyle(),
        &GetCSSPropertyBorderInlineStartColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderInlineStart, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderInlineStyleShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderInlineStartStyle(),
        &GetCSSPropertyBorderInlineEndStyle(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderInlineStyle, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderInlineWidthShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderInlineStartWidth(),
        &GetCSSPropertyBorderInlineEndWidth(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderInlineWidth, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderLeftShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderLeftWidth(),
        &GetCSSPropertyBorderLeftStyle(),
        &GetCSSPropertyBorderLeftColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderLeft, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderRadiusShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderTopLeftRadius(),
        &GetCSSPropertyBorderTopRightRadius(),
        &GetCSSPropertyBorderBottomRightRadius(),
        &GetCSSPropertyBorderBottomLeftRadius(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderRadius, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderRightShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderRightWidth(),
        &GetCSSPropertyBorderRightStyle(),
        &GetCSSPropertyBorderRightColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderRight, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderSpacingShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyWebkitBorderHorizontalSpacing(),
        &GetCSSPropertyWebkitBorderVerticalSpacing(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderSpacing, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderStyleShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderTopStyle(),
        &GetCSSPropertyBorderRightStyle(),
        &GetCSSPropertyBorderBottomStyle(),
        &GetCSSPropertyBorderLeftStyle(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderStyle, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderTopShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderTopWidth(),
        &GetCSSPropertyBorderTopStyle(),
        &GetCSSPropertyBorderTopColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderTop, longhands);
    return shorthand;
}

const StylePropertyShorthand& borderWidthShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBorderTopWidth(),
        &GetCSSPropertyBorderRightWidth(),
        &GetCSSPropertyBorderBottomWidth(),
        &GetCSSPropertyBorderLeftWidth(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kBorderWidth, longhands);
    return shorthand;
}

const StylePropertyShorthand& columnRuleShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyColumnRuleWidth(),
        &GetCSSPropertyColumnRuleStyle(),
        &GetCSSPropertyColumnRuleColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kColumnRule, longhands);
    return shorthand;
}

const StylePropertyShorthand& columnsShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyColumnWidth(),
        &GetCSSPropertyColumnCount(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kColumns, longhands);
    return shorthand;
}

const StylePropertyShorthand& containIntrinsicSizeShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyContainIntrinsicWidth(),
        &GetCSSPropertyContainIntrinsicHeight(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kContainIntrinsicSize, longhands);
    return shorthand;
}

const StylePropertyShorthand& containerShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyContainerName(),
        &GetCSSPropertyContainerType(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kContainer, longhands);
    return shorthand;
}

const StylePropertyShorthand& flexShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFlexGrow(),
        &GetCSSPropertyFlexShrink(),
        &GetCSSPropertyFlexBasis(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFlex, longhands);
    return shorthand;
}

const StylePropertyShorthand& flexFlowShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFlexDirection(),
        &GetCSSPropertyFlexWrap(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFlexFlow, longhands);
    return shorthand;
}

static const StylePropertyShorthand* fontShorthand1()
{
    if (!RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled())
        return nullptr;
    if (RuntimeEnabledFeatures::FontVariantEmojiEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontStyle(),
        &GetCSSPropertyFontVariantLigatures(),
        &GetCSSPropertyFontVariantCaps(),
        &GetCSSPropertyFontVariantNumeric(),
        &GetCSSPropertyFontVariantEastAsian(),
        &GetCSSPropertyFontVariantAlternates(),
        &GetCSSPropertyFontVariantPosition(),
        &GetCSSPropertyFontWeight(),
        &GetCSSPropertyFontStretch(),
        &GetCSSPropertyFontSize(),
        &GetCSSPropertyLineHeight(),
        &GetCSSPropertyFontFamily(),
        &GetCSSPropertyFontOpticalSizing(),
        &GetCSSPropertyFontSizeAdjust(),
        &GetCSSPropertyFontKerning(),
        &GetCSSPropertyFontFeatureSettings(),
        &GetCSSPropertyFontVariationSettings(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFont, longhands);
    return &shorthand;
}

static const StylePropertyShorthand* fontShorthand2()
{
    if (RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled())
        return nullptr;
    if (!RuntimeEnabledFeatures::FontVariantEmojiEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontStyle(),
        &GetCSSPropertyFontVariantLigatures(),
        &GetCSSPropertyFontVariantCaps(),
        &GetCSSPropertyFontVariantNumeric(),
        &GetCSSPropertyFontVariantEastAsian(),
        &GetCSSPropertyFontVariantAlternates(),
        &GetCSSPropertyFontVariantPosition(),
        &GetCSSPropertyFontVariantEmoji(),
        &GetCSSPropertyFontWeight(),
        &GetCSSPropertyFontStretch(),
        &GetCSSPropertyFontSize(),
        &GetCSSPropertyLineHeight(),
        &GetCSSPropertyFontFamily(),
        &GetCSSPropertyFontOpticalSizing(),
        &GetCSSPropertyFontKerning(),
        &GetCSSPropertyFontFeatureSettings(),
        &GetCSSPropertyFontVariationSettings(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFont, longhands);
    return &shorthand;
}

static const StylePropertyShorthand* fontShorthand3()
{
    if (!RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled())
        return nullptr;
    if (!RuntimeEnabledFeatures::FontVariantEmojiEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontStyle(),
        &GetCSSPropertyFontVariantLigatures(),
        &GetCSSPropertyFontVariantCaps(),
        &GetCSSPropertyFontVariantNumeric(),
        &GetCSSPropertyFontVariantEastAsian(),
        &GetCSSPropertyFontVariantAlternates(),
        &GetCSSPropertyFontVariantPosition(),
        &GetCSSPropertyFontVariantEmoji(),
        &GetCSSPropertyFontWeight(),
        &GetCSSPropertyFontStretch(),
        &GetCSSPropertyFontSize(),
        &GetCSSPropertyLineHeight(),
        &GetCSSPropertyFontFamily(),
        &GetCSSPropertyFontOpticalSizing(),
        &GetCSSPropertyFontSizeAdjust(),
        &GetCSSPropertyFontKerning(),
        &GetCSSPropertyFontFeatureSettings(),
        &GetCSSPropertyFontVariationSettings(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFont, longhands);
    return &shorthand;
}

const StylePropertyShorthand& fontShorthand()
{
    if (const auto* s = fontShorthand1())
        return *s;
    if (const auto* s = fontShorthand2())
        return *s;
    if (const auto* s = fontShorthand3())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled());
    DCHECK(!RuntimeEnabledFeatures::FontVariantEmojiEnabled());

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontStyle(),
        &GetCSSPropertyFontVariantLigatures(),
        &GetCSSPropertyFontVariantCaps(),
        &GetCSSPropertyFontVariantNumeric(),
        &GetCSSPropertyFontVariantEastAsian(),
        &GetCSSPropertyFontVariantAlternates(),
        &GetCSSPropertyFontVariantPosition(),
        &GetCSSPropertyFontWeight(),
        &GetCSSPropertyFontStretch(),
        &GetCSSPropertyFontSize(),
        &GetCSSPropertyLineHeight(),
        &GetCSSPropertyFontFamily(),
        &GetCSSPropertyFontOpticalSizing(),
        &GetCSSPropertyFontKerning(),
        &GetCSSPropertyFontFeatureSettings(),
        &GetCSSPropertyFontVariationSettings(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFont, longhands);
    return shorthand;
}

const StylePropertyShorthand& fontSynthesisShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontSynthesisWeight(),
        &GetCSSPropertyFontSynthesisStyle(),
        &GetCSSPropertyFontSynthesisSmallCaps(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFontSynthesis, longhands);
    return shorthand;
}

static const StylePropertyShorthand* fontVariantShorthand1()
{
    if (!RuntimeEnabledFeatures::FontVariantEmojiEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontVariantLigatures(),
        &GetCSSPropertyFontVariantCaps(),
        &GetCSSPropertyFontVariantAlternates(),
        &GetCSSPropertyFontVariantNumeric(),
        &GetCSSPropertyFontVariantEastAsian(),
        &GetCSSPropertyFontVariantPosition(),
        &GetCSSPropertyFontVariantEmoji(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFontVariant, longhands);
    return &shorthand;
}

const StylePropertyShorthand& fontVariantShorthand()
{
    if (const auto* s = fontVariantShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::FontVariantEmojiEnabled());

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyFontVariantLigatures(),
        &GetCSSPropertyFontVariantCaps(),
        &GetCSSPropertyFontVariantAlternates(),
        &GetCSSPropertyFontVariantNumeric(),
        &GetCSSPropertyFontVariantEastAsian(),
        &GetCSSPropertyFontVariantPosition(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kFontVariant, longhands);
    return shorthand;
}

const StylePropertyShorthand& gapShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyRowGap(),
        &GetCSSPropertyColumnGap(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kGap, longhands);
    return shorthand;
}

const StylePropertyShorthand& gridShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyGridTemplateRows(),
        &GetCSSPropertyGridTemplateColumns(),
        &GetCSSPropertyGridTemplateAreas(),
        &GetCSSPropertyGridAutoFlow(),
        &GetCSSPropertyGridAutoRows(),
        &GetCSSPropertyGridAutoColumns(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kGrid, longhands);
    return shorthand;
}

const StylePropertyShorthand& gridAreaShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyGridRowStart(),
        &GetCSSPropertyGridColumnStart(),
        &GetCSSPropertyGridRowEnd(),
        &GetCSSPropertyGridColumnEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kGridArea, longhands);
    return shorthand;
}

const StylePropertyShorthand& gridColumnShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyGridColumnStart(),
        &GetCSSPropertyGridColumnEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kGridColumn, longhands);
    return shorthand;
}

const StylePropertyShorthand& gridRowShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyGridRowStart(),
        &GetCSSPropertyGridRowEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kGridRow, longhands);
    return shorthand;
}

const StylePropertyShorthand& gridTemplateShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyGridTemplateRows(),
        &GetCSSPropertyGridTemplateColumns(),
        &GetCSSPropertyGridTemplateAreas(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kGridTemplate, longhands);
    return shorthand;
}

const StylePropertyShorthand& insetShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTop(),
        &GetCSSPropertyRight(),
        &GetCSSPropertyBottom(),
        &GetCSSPropertyLeft(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kInset, longhands);
    return shorthand;
}

const StylePropertyShorthand& insetBlockShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyInsetBlockStart(),
        &GetCSSPropertyInsetBlockEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kInsetBlock, longhands);
    return shorthand;
}

const StylePropertyShorthand& insetInlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyInsetInlineStart(),
        &GetCSSPropertyInsetInlineEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kInsetInline, longhands);
    return shorthand;
}

const StylePropertyShorthand& listStyleShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyListStylePosition(),
        &GetCSSPropertyListStyleImage(),
        &GetCSSPropertyListStyleType(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kListStyle, longhands);
    return shorthand;
}

const StylePropertyShorthand& marginShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyMarginTop(),
        &GetCSSPropertyMarginRight(),
        &GetCSSPropertyMarginBottom(),
        &GetCSSPropertyMarginLeft(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMargin, longhands);
    return shorthand;
}

const StylePropertyShorthand& marginBlockShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyMarginBlockStart(),
        &GetCSSPropertyMarginBlockEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMarginBlock, longhands);
    return shorthand;
}

const StylePropertyShorthand& marginInlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyMarginInlineStart(),
        &GetCSSPropertyMarginInlineEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMarginInline, longhands);
    return shorthand;
}

const StylePropertyShorthand& markerShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyMarkerStart(),
        &GetCSSPropertyMarkerMid(),
        &GetCSSPropertyMarkerEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMarker, longhands);
    return shorthand;
}

const StylePropertyShorthand& maskShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyMaskImage(),
        &GetCSSPropertyWebkitMaskPositionX(),
        &GetCSSPropertyWebkitMaskPositionY(),
        &GetCSSPropertyMaskSize(),
        &GetCSSPropertyMaskRepeat(),
        &GetCSSPropertyMaskOrigin(),
        &GetCSSPropertyMaskClip(),
        &GetCSSPropertyMaskComposite(),
        &GetCSSPropertyMaskMode(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMask, longhands);
    return shorthand;
}

const StylePropertyShorthand& maskPositionShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyWebkitMaskPositionX(),
        &GetCSSPropertyWebkitMaskPositionY(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMaskPosition, longhands);
    return shorthand;
}

static const StylePropertyShorthand* masonryTrackShorthand1()
{
    if (!RuntimeEnabledFeatures::CSSMasonryLayoutEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyMasonryTrackStart(),
        &GetCSSPropertyMasonryTrackEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kMasonryTrack, longhands);
    return &shorthand;
}

const StylePropertyShorthand& masonryTrackShorthand()
{
    if (const auto* s = masonryTrackShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::CSSMasonryLayoutEnabled());

    static StylePropertyShorthand empty_shorthand;
    return empty_shorthand;
}

const StylePropertyShorthand& offsetShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyOffsetPosition(),
        &GetCSSPropertyOffsetPath(),
        &GetCSSPropertyOffsetDistance(),
        &GetCSSPropertyOffsetRotate(),
        &GetCSSPropertyOffsetAnchor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kOffset, longhands);
    return shorthand;
}

const StylePropertyShorthand& outlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyOutlineColor(),
        &GetCSSPropertyOutlineStyle(),
        &GetCSSPropertyOutlineWidth(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kOutline, longhands);
    return shorthand;
}

const StylePropertyShorthand& overflowShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyOverflowX(),
        &GetCSSPropertyOverflowY(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kOverflow, longhands);
    return shorthand;
}

const StylePropertyShorthand& overscrollBehaviorShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyOverscrollBehaviorX(),
        &GetCSSPropertyOverscrollBehaviorY(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kOverscrollBehavior, longhands);
    return shorthand;
}

const StylePropertyShorthand& paddingShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyPaddingTop(),
        &GetCSSPropertyPaddingRight(),
        &GetCSSPropertyPaddingBottom(),
        &GetCSSPropertyPaddingLeft(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPadding, longhands);
    return shorthand;
}

const StylePropertyShorthand& paddingBlockShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyPaddingBlockStart(),
        &GetCSSPropertyPaddingBlockEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPaddingBlock, longhands);
    return shorthand;
}

const StylePropertyShorthand& paddingInlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyPaddingInlineStart(),
        &GetCSSPropertyPaddingInlineEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPaddingInline, longhands);
    return shorthand;
}

const StylePropertyShorthand& pageBreakAfterShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBreakAfter(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPageBreakAfter, longhands);
    return shorthand;
}

const StylePropertyShorthand& pageBreakBeforeShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBreakBefore(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPageBreakBefore, longhands);
    return shorthand;
}

const StylePropertyShorthand& pageBreakInsideShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBreakInside(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPageBreakInside, longhands);
    return shorthand;
}

const StylePropertyShorthand& placeContentShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAlignContent(),
        &GetCSSPropertyJustifyContent(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPlaceContent, longhands);
    return shorthand;
}

const StylePropertyShorthand& placeItemsShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAlignItems(),
        &GetCSSPropertyJustifyItems(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPlaceItems, longhands);
    return shorthand;
}

const StylePropertyShorthand& placeSelfShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyAlignSelf(),
        &GetCSSPropertyJustifySelf(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPlaceSelf, longhands);
    return shorthand;
}

const StylePropertyShorthand& positionTryShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyPositionTryOrder(),
        &GetCSSPropertyPositionTryFallbacks(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kPositionTry, longhands);
    return shorthand;
}

const StylePropertyShorthand& scrollMarginShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollMarginTop(),
        &GetCSSPropertyScrollMarginRight(),
        &GetCSSPropertyScrollMarginBottom(),
        &GetCSSPropertyScrollMarginLeft(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollMargin, longhands);
    return shorthand;
}

const StylePropertyShorthand& scrollMarginBlockShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollMarginBlockStart(),
        &GetCSSPropertyScrollMarginBlockEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollMarginBlock, longhands);
    return shorthand;
}

const StylePropertyShorthand& scrollMarginInlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollMarginInlineStart(),
        &GetCSSPropertyScrollMarginInlineEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollMarginInline, longhands);
    return shorthand;
}

const StylePropertyShorthand& scrollPaddingShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollPaddingTop(),
        &GetCSSPropertyScrollPaddingRight(),
        &GetCSSPropertyScrollPaddingBottom(),
        &GetCSSPropertyScrollPaddingLeft(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollPadding, longhands);
    return shorthand;
}

const StylePropertyShorthand& scrollPaddingBlockShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollPaddingBlockStart(),
        &GetCSSPropertyScrollPaddingBlockEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollPaddingBlock, longhands);
    return shorthand;
}

const StylePropertyShorthand& scrollPaddingInlineShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollPaddingInlineStart(),
        &GetCSSPropertyScrollPaddingInlineEnd(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollPaddingInline, longhands);
    return shorthand;
}

static const StylePropertyShorthand* scrollStartShorthand1()
{
    if (!RuntimeEnabledFeatures::CSSScrollStartEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollStartBlock(),
        &GetCSSPropertyScrollStartInline(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollStart, longhands);
    return &shorthand;
}

const StylePropertyShorthand& scrollStartShorthand()
{
    if (const auto* s = scrollStartShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::CSSScrollStartEnabled());

    static StylePropertyShorthand empty_shorthand;
    return empty_shorthand;
}

static const StylePropertyShorthand* scrollTimelineShorthand1()
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyScrollTimelineName(),
        &GetCSSPropertyScrollTimelineAxis(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kScrollTimeline, longhands);
    return &shorthand;
}

const StylePropertyShorthand& scrollTimelineShorthand()
{
    if (const auto* s = scrollTimelineShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::ScrollTimelineEnabled());

    static StylePropertyShorthand empty_shorthand;
    return empty_shorthand;
}

static const StylePropertyShorthand* textBoxShorthand1()
{
    if (!RuntimeEnabledFeatures::CSSTextBoxTrimEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTextBoxTrim(),
        &GetCSSPropertyTextBoxEdge(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTextBox, longhands);
    return &shorthand;
}

const StylePropertyShorthand& textBoxShorthand()
{
    if (const auto* s = textBoxShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::CSSTextBoxTrimEnabled());

    static StylePropertyShorthand empty_shorthand;
    return empty_shorthand;
}

const StylePropertyShorthand& textDecorationShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTextDecorationLine(),
        &GetCSSPropertyTextDecorationThickness(),
        &GetCSSPropertyTextDecorationStyle(),
        &GetCSSPropertyTextDecorationColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTextDecoration, longhands);
    return shorthand;
}

const StylePropertyShorthand& textEmphasisShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTextEmphasisStyle(),
        &GetCSSPropertyTextEmphasisColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTextEmphasis, longhands);
    return shorthand;
}

static const StylePropertyShorthand* textSpacingShorthand1()
{
    if (!RuntimeEnabledFeatures::CSSTextAutoSpaceEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTextAutospace(),
        &GetCSSPropertyTextSpacingTrim(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTextSpacing, longhands);
    return &shorthand;
}

const StylePropertyShorthand& textSpacingShorthand()
{
    if (const auto* s = textSpacingShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::CSSTextAutoSpaceEnabled());

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTextSpacingTrim(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTextSpacing, longhands);
    return shorthand;
}

const StylePropertyShorthand& textWrapShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTextWrapMode(),
        &GetCSSPropertyTextWrapStyle(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTextWrap, longhands);
    return shorthand;
}

const StylePropertyShorthand& transitionShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyTransitionProperty(),
        &GetCSSPropertyTransitionDuration(),
        &GetCSSPropertyTransitionTimingFunction(),
        &GetCSSPropertyTransitionDelay(),
        &GetCSSPropertyTransitionBehavior(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kTransition, longhands);
    return shorthand;
}

static const StylePropertyShorthand* viewTimelineShorthand1()
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled())
        return nullptr;

    static const CSSProperty* longhands[] = {
        &GetCSSPropertyViewTimelineName(),
        &GetCSSPropertyViewTimelineAxis(),
        &GetCSSPropertyViewTimelineInset(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kViewTimeline, longhands);
    return &shorthand;
}

const StylePropertyShorthand& viewTimelineShorthand()
{
    if (const auto* s = viewTimelineShorthand1())
        return *s;

    DCHECK(!RuntimeEnabledFeatures::ScrollTimelineEnabled());

    static StylePropertyShorthand empty_shorthand;
    return empty_shorthand;
}

const StylePropertyShorthand& webkitColumnBreakAfterShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBreakAfter(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kWebkitColumnBreakAfter, longhands);
    return shorthand;
}

const StylePropertyShorthand& webkitColumnBreakBeforeShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBreakBefore(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kWebkitColumnBreakBefore, longhands);
    return shorthand;
}

const StylePropertyShorthand& webkitColumnBreakInsideShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyBreakInside(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kWebkitColumnBreakInside, longhands);
    return shorthand;
}

const StylePropertyShorthand& webkitMaskBoxImageShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyWebkitMaskBoxImageSource(),
        &GetCSSPropertyWebkitMaskBoxImageSlice(),
        &GetCSSPropertyWebkitMaskBoxImageWidth(),
        &GetCSSPropertyWebkitMaskBoxImageOutset(),
        &GetCSSPropertyWebkitMaskBoxImageRepeat(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kWebkitMaskBoxImage, longhands);
    return shorthand;
}

const StylePropertyShorthand& webkitTextStrokeShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyWebkitTextStrokeWidth(),
        &GetCSSPropertyWebkitTextStrokeColor(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kWebkitTextStroke, longhands);
    return shorthand;
}

const StylePropertyShorthand& whiteSpaceShorthand()
{
    static const CSSProperty* longhands[] = {
        &GetCSSPropertyWhiteSpaceCollapse(),
        &GetCSSPropertyTextWrapMode(),
    };

    static const StylePropertyShorthand shorthand(CSSPropertyID::kWhiteSpace, longhands);
    return shorthand;
}

// Returns an empty list if the property is not a shorthand
const StylePropertyShorthand& shorthandForProperty(CSSPropertyID propertyID)
{
    // FIXME: We shouldn't switch between shorthand/not shorthand based on a runtime flag
    static StylePropertyShorthand empty_shorthand;

    switch (propertyID) {
    case CSSPropertyID::kAlternativeAnimationWithTimeline:
        return alternativeAnimationWithTimelineShorthand();
    case CSSPropertyID::kAnimation:
        return animationShorthand();
    case CSSPropertyID::kAnimationRange:
        return animationRangeShorthand();
    case CSSPropertyID::kBackground:
        return backgroundShorthand();
    case CSSPropertyID::kBackgroundPosition:
        return backgroundPositionShorthand();
    case CSSPropertyID::kBorder:
        return borderShorthand();
    case CSSPropertyID::kBorderBlock:
        return borderBlockShorthand();
    case CSSPropertyID::kBorderBlockColor:
        return borderBlockColorShorthand();
    case CSSPropertyID::kBorderBlockEnd:
        return borderBlockEndShorthand();
    case CSSPropertyID::kBorderBlockStart:
        return borderBlockStartShorthand();
    case CSSPropertyID::kBorderBlockStyle:
        return borderBlockStyleShorthand();
    case CSSPropertyID::kBorderBlockWidth:
        return borderBlockWidthShorthand();
    case CSSPropertyID::kBorderBottom:
        return borderBottomShorthand();
    case CSSPropertyID::kBorderColor:
        return borderColorShorthand();
    case CSSPropertyID::kBorderImage:
        return borderImageShorthand();
    case CSSPropertyID::kBorderInline:
        return borderInlineShorthand();
    case CSSPropertyID::kBorderInlineColor:
        return borderInlineColorShorthand();
    case CSSPropertyID::kBorderInlineEnd:
        return borderInlineEndShorthand();
    case CSSPropertyID::kBorderInlineStart:
        return borderInlineStartShorthand();
    case CSSPropertyID::kBorderInlineStyle:
        return borderInlineStyleShorthand();
    case CSSPropertyID::kBorderInlineWidth:
        return borderInlineWidthShorthand();
    case CSSPropertyID::kBorderLeft:
        return borderLeftShorthand();
    case CSSPropertyID::kBorderRadius:
        return borderRadiusShorthand();
    case CSSPropertyID::kBorderRight:
        return borderRightShorthand();
    case CSSPropertyID::kBorderSpacing:
        return borderSpacingShorthand();
    case CSSPropertyID::kBorderStyle:
        return borderStyleShorthand();
    case CSSPropertyID::kBorderTop:
        return borderTopShorthand();
    case CSSPropertyID::kBorderWidth:
        return borderWidthShorthand();
    case CSSPropertyID::kColumnRule:
        return columnRuleShorthand();
    case CSSPropertyID::kColumns:
        return columnsShorthand();
    case CSSPropertyID::kContainIntrinsicSize:
        return containIntrinsicSizeShorthand();
    case CSSPropertyID::kContainer:
        return containerShorthand();
    case CSSPropertyID::kFlex:
        return flexShorthand();
    case CSSPropertyID::kFlexFlow:
        return flexFlowShorthand();
    case CSSPropertyID::kFont:
        return fontShorthand();
    case CSSPropertyID::kFontSynthesis:
        return fontSynthesisShorthand();
    case CSSPropertyID::kFontVariant:
        return fontVariantShorthand();
    case CSSPropertyID::kGap:
        return gapShorthand();
    case CSSPropertyID::kGrid:
        return gridShorthand();
    case CSSPropertyID::kGridArea:
        return gridAreaShorthand();
    case CSSPropertyID::kGridColumn:
        return gridColumnShorthand();
    case CSSPropertyID::kGridRow:
        return gridRowShorthand();
    case CSSPropertyID::kGridTemplate:
        return gridTemplateShorthand();
    case CSSPropertyID::kInset:
        return insetShorthand();
    case CSSPropertyID::kInsetBlock:
        return insetBlockShorthand();
    case CSSPropertyID::kInsetInline:
        return insetInlineShorthand();
    case CSSPropertyID::kListStyle:
        return listStyleShorthand();
    case CSSPropertyID::kMargin:
        return marginShorthand();
    case CSSPropertyID::kMarginBlock:
        return marginBlockShorthand();
    case CSSPropertyID::kMarginInline:
        return marginInlineShorthand();
    case CSSPropertyID::kMarker:
        return markerShorthand();
    case CSSPropertyID::kMask:
        return maskShorthand();
    case CSSPropertyID::kMaskPosition:
        return maskPositionShorthand();
    case CSSPropertyID::kMasonryTrack:
        return masonryTrackShorthand();
    case CSSPropertyID::kOffset:
        return offsetShorthand();
    case CSSPropertyID::kOutline:
        return outlineShorthand();
    case CSSPropertyID::kOverflow:
        return overflowShorthand();
    case CSSPropertyID::kOverscrollBehavior:
        return overscrollBehaviorShorthand();
    case CSSPropertyID::kPadding:
        return paddingShorthand();
    case CSSPropertyID::kPaddingBlock:
        return paddingBlockShorthand();
    case CSSPropertyID::kPaddingInline:
        return paddingInlineShorthand();
    case CSSPropertyID::kPageBreakAfter:
        return pageBreakAfterShorthand();
    case CSSPropertyID::kPageBreakBefore:
        return pageBreakBeforeShorthand();
    case CSSPropertyID::kPageBreakInside:
        return pageBreakInsideShorthand();
    case CSSPropertyID::kPlaceContent:
        return placeContentShorthand();
    case CSSPropertyID::kPlaceItems:
        return placeItemsShorthand();
    case CSSPropertyID::kPlaceSelf:
        return placeSelfShorthand();
    case CSSPropertyID::kPositionTry:
        return positionTryShorthand();
    case CSSPropertyID::kScrollMargin:
        return scrollMarginShorthand();
    case CSSPropertyID::kScrollMarginBlock:
        return scrollMarginBlockShorthand();
    case CSSPropertyID::kScrollMarginInline:
        return scrollMarginInlineShorthand();
    case CSSPropertyID::kScrollPadding:
        return scrollPaddingShorthand();
    case CSSPropertyID::kScrollPaddingBlock:
        return scrollPaddingBlockShorthand();
    case CSSPropertyID::kScrollPaddingInline:
        return scrollPaddingInlineShorthand();
    case CSSPropertyID::kScrollStart:
        return scrollStartShorthand();
    case CSSPropertyID::kScrollTimeline:
        return scrollTimelineShorthand();
    case CSSPropertyID::kTextBox:
        return textBoxShorthand();
    case CSSPropertyID::kTextDecoration:
        return textDecorationShorthand();
    case CSSPropertyID::kTextEmphasis:
        return textEmphasisShorthand();
    case CSSPropertyID::kTextSpacing:
        return textSpacingShorthand();
    case CSSPropertyID::kTextWrap:
        return textWrapShorthand();
    case CSSPropertyID::kTransition:
        return transitionShorthand();
    case CSSPropertyID::kViewTimeline:
        return viewTimelineShorthand();
    case CSSPropertyID::kWebkitColumnBreakAfter:
        return webkitColumnBreakAfterShorthand();
    case CSSPropertyID::kWebkitColumnBreakBefore:
        return webkitColumnBreakBeforeShorthand();
    case CSSPropertyID::kWebkitColumnBreakInside:
        return webkitColumnBreakInsideShorthand();
    case CSSPropertyID::kWebkitMaskBoxImage:
        return webkitMaskBoxImageShorthand();
    case CSSPropertyID::kWebkitTextStroke:
        return webkitTextStrokeShorthand();
    case CSSPropertyID::kWhiteSpace:
        return whiteSpaceShorthand();
    default: {
        return empty_shorthand;
    }
    }
}

void getMatchingShorthandsForLonghand(CSSPropertyID propertyID, Vector<StylePropertyShorthand, 4>* result)
{
    DCHECK(!result->size());
    switch (propertyID) {
    case CSSPropertyID::kAnimationDuration: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationTimingFunction: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationDelay: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationIterationCount: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationDirection: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationFillMode: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationPlayState: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationName: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
            result->UncheckedAppend(animationShorthand());
        break;
    }
    case CSSPropertyID::kAnimationTimeline: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        break;
    }
    case CSSPropertyID::kAnimationRangeStart: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimationRange).IsWebExposed())
            result->UncheckedAppend(animationRangeShorthand());
        break;
    }
    case CSSPropertyID::kAnimationRangeEnd: {
        if (CSSProperty::Get(CSSPropertyID::kAlternativeAnimationWithTimeline).IsWebExposed())
            result->UncheckedAppend(alternativeAnimationWithTimelineShorthand());
        if (CSSProperty::Get(CSSPropertyID::kAnimationRange).IsWebExposed())
            result->UncheckedAppend(animationRangeShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundImage: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundPositionX: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackgroundPosition).IsWebExposed());
        result->UncheckedAppend(backgroundPositionShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundPositionY: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackgroundPosition).IsWebExposed());
        result->UncheckedAppend(backgroundPositionShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundSize: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundRepeat: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundAttachment: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundOrigin: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundClip: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBackgroundColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed());
        result->UncheckedAppend(backgroundShorthand());
        break;
    }
    case CSSPropertyID::kBorderTopColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed());
        result->UncheckedAppend(borderColorShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderTop).IsWebExposed());
        result->UncheckedAppend(borderTopShorthand());
        break;
    }
    case CSSPropertyID::kBorderTopStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed());
        result->UncheckedAppend(borderStyleShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderTop).IsWebExposed());
        result->UncheckedAppend(borderTopShorthand());
        break;
    }
    case CSSPropertyID::kBorderTopWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed());
        result->UncheckedAppend(borderWidthShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderTop).IsWebExposed());
        result->UncheckedAppend(borderTopShorthand());
        break;
    }
    case CSSPropertyID::kBorderRightColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed());
        result->UncheckedAppend(borderColorShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRight).IsWebExposed());
        result->UncheckedAppend(borderRightShorthand());
        break;
    }
    case CSSPropertyID::kBorderRightStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed());
        result->UncheckedAppend(borderStyleShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRight).IsWebExposed());
        result->UncheckedAppend(borderRightShorthand());
        break;
    }
    case CSSPropertyID::kBorderRightWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed());
        result->UncheckedAppend(borderWidthShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRight).IsWebExposed());
        result->UncheckedAppend(borderRightShorthand());
        break;
    }
    case CSSPropertyID::kBorderBottomColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed());
        result->UncheckedAppend(borderColorShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBottom).IsWebExposed());
        result->UncheckedAppend(borderBottomShorthand());
        break;
    }
    case CSSPropertyID::kBorderBottomStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed());
        result->UncheckedAppend(borderStyleShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBottom).IsWebExposed());
        result->UncheckedAppend(borderBottomShorthand());
        break;
    }
    case CSSPropertyID::kBorderBottomWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed());
        result->UncheckedAppend(borderWidthShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBottom).IsWebExposed());
        result->UncheckedAppend(borderBottomShorthand());
        break;
    }
    case CSSPropertyID::kBorderLeftColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed());
        result->UncheckedAppend(borderColorShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderLeft).IsWebExposed());
        result->UncheckedAppend(borderLeftShorthand());
        break;
    }
    case CSSPropertyID::kBorderLeftStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed());
        result->UncheckedAppend(borderStyleShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderLeft).IsWebExposed());
        result->UncheckedAppend(borderLeftShorthand());
        break;
    }
    case CSSPropertyID::kBorderLeftWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed());
        result->UncheckedAppend(borderWidthShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderLeft).IsWebExposed());
        result->UncheckedAppend(borderLeftShorthand());
        break;
    }
    case CSSPropertyID::kBorderImageSource: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed());
        result->UncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyID::kBorderImageSlice: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed());
        result->UncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyID::kBorderImageWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed());
        result->UncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyID::kBorderImageOutset: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed());
        result->UncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyID::kBorderImageRepeat: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed());
        result->UncheckedAppend(borderShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed());
        result->UncheckedAppend(borderImageShorthand());
        break;
    }
    case CSSPropertyID::kBorderBlockStartColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed());
        result->UncheckedAppend(borderBlockShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockStart).IsWebExposed());
        result->UncheckedAppend(borderBlockStartShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockColor).IsWebExposed());
        result->UncheckedAppend(borderBlockColorShorthand());
        break;
    }
    case CSSPropertyID::kBorderBlockStartStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed());
        result->UncheckedAppend(borderBlockShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockStart).IsWebExposed());
        result->UncheckedAppend(borderBlockStartShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockStyle).IsWebExposed());
        result->UncheckedAppend(borderBlockStyleShorthand());
        break;
    }
    case CSSPropertyID::kBorderBlockStartWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed());
        result->UncheckedAppend(borderBlockShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockStart).IsWebExposed());
        result->UncheckedAppend(borderBlockStartShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockWidth).IsWebExposed());
        result->UncheckedAppend(borderBlockWidthShorthand());
        break;
    }
    case CSSPropertyID::kBorderBlockEndColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed());
        result->UncheckedAppend(borderBlockShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockEnd).IsWebExposed());
        result->UncheckedAppend(borderBlockEndShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockColor).IsWebExposed());
        result->UncheckedAppend(borderBlockColorShorthand());
        break;
    }
    case CSSPropertyID::kBorderBlockEndStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed());
        result->UncheckedAppend(borderBlockShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockEnd).IsWebExposed());
        result->UncheckedAppend(borderBlockEndShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockStyle).IsWebExposed());
        result->UncheckedAppend(borderBlockStyleShorthand());
        break;
    }
    case CSSPropertyID::kBorderBlockEndWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed());
        result->UncheckedAppend(borderBlockShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockEnd).IsWebExposed());
        result->UncheckedAppend(borderBlockEndShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderBlockWidth).IsWebExposed());
        result->UncheckedAppend(borderBlockWidthShorthand());
        break;
    }
    case CSSPropertyID::kBorderInlineStartColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed());
        result->UncheckedAppend(borderInlineShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineStart).IsWebExposed());
        result->UncheckedAppend(borderInlineStartShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineColor).IsWebExposed());
        result->UncheckedAppend(borderInlineColorShorthand());
        break;
    }
    case CSSPropertyID::kBorderInlineStartStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed());
        result->UncheckedAppend(borderInlineShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineStart).IsWebExposed());
        result->UncheckedAppend(borderInlineStartShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineStyle).IsWebExposed());
        result->UncheckedAppend(borderInlineStyleShorthand());
        break;
    }
    case CSSPropertyID::kBorderInlineStartWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed());
        result->UncheckedAppend(borderInlineShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineStart).IsWebExposed());
        result->UncheckedAppend(borderInlineStartShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineWidth).IsWebExposed());
        result->UncheckedAppend(borderInlineWidthShorthand());
        break;
    }
    case CSSPropertyID::kBorderInlineEndColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed());
        result->UncheckedAppend(borderInlineShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineEnd).IsWebExposed());
        result->UncheckedAppend(borderInlineEndShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineColor).IsWebExposed());
        result->UncheckedAppend(borderInlineColorShorthand());
        break;
    }
    case CSSPropertyID::kBorderInlineEndStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed());
        result->UncheckedAppend(borderInlineShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineEnd).IsWebExposed());
        result->UncheckedAppend(borderInlineEndShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineStyle).IsWebExposed());
        result->UncheckedAppend(borderInlineStyleShorthand());
        break;
    }
    case CSSPropertyID::kBorderInlineEndWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed());
        result->UncheckedAppend(borderInlineShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineEnd).IsWebExposed());
        result->UncheckedAppend(borderInlineEndShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderInlineWidth).IsWebExposed());
        result->UncheckedAppend(borderInlineWidthShorthand());
        break;
    }
    case CSSPropertyID::kBorderTopLeftRadius: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed());
        result->UncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyID::kBorderTopRightRadius: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed());
        result->UncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyID::kBorderBottomRightRadius: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed());
        result->UncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyID::kBorderBottomLeftRadius: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed());
        result->UncheckedAppend(borderRadiusShorthand());
        break;
    }
    case CSSPropertyID::kWebkitBorderHorizontalSpacing: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderSpacing).IsWebExposed());
        result->UncheckedAppend(borderSpacingShorthand());
        break;
    }
    case CSSPropertyID::kWebkitBorderVerticalSpacing: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kBorderSpacing).IsWebExposed());
        result->UncheckedAppend(borderSpacingShorthand());
        break;
    }
    case CSSPropertyID::kColumnRuleWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kColumnRule).IsWebExposed());
        result->UncheckedAppend(columnRuleShorthand());
        break;
    }
    case CSSPropertyID::kColumnRuleStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kColumnRule).IsWebExposed());
        result->UncheckedAppend(columnRuleShorthand());
        break;
    }
    case CSSPropertyID::kColumnRuleColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kColumnRule).IsWebExposed());
        result->UncheckedAppend(columnRuleShorthand());
        break;
    }
    case CSSPropertyID::kColumnWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kColumns).IsWebExposed());
        result->UncheckedAppend(columnsShorthand());
        break;
    }
    case CSSPropertyID::kColumnCount: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kColumns).IsWebExposed());
        result->UncheckedAppend(columnsShorthand());
        break;
    }
    case CSSPropertyID::kContainIntrinsicWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kContainIntrinsicSize).IsWebExposed());
        result->UncheckedAppend(containIntrinsicSizeShorthand());
        break;
    }
    case CSSPropertyID::kContainIntrinsicHeight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kContainIntrinsicSize).IsWebExposed());
        result->UncheckedAppend(containIntrinsicSizeShorthand());
        break;
    }
    case CSSPropertyID::kContainerName: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kContainer).IsWebExposed());
        result->UncheckedAppend(containerShorthand());
        break;
    }
    case CSSPropertyID::kContainerType: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kContainer).IsWebExposed());
        result->UncheckedAppend(containerShorthand());
        break;
    }
    case CSSPropertyID::kFlexGrow: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFlex).IsWebExposed());
        result->UncheckedAppend(flexShorthand());
        break;
    }
    case CSSPropertyID::kFlexShrink: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFlex).IsWebExposed());
        result->UncheckedAppend(flexShorthand());
        break;
    }
    case CSSPropertyID::kFlexBasis: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFlex).IsWebExposed());
        result->UncheckedAppend(flexShorthand());
        break;
    }
    case CSSPropertyID::kFlexDirection: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFlexFlow).IsWebExposed());
        result->UncheckedAppend(flexFlowShorthand());
        break;
    }
    case CSSPropertyID::kFlexWrap: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFlexFlow).IsWebExposed());
        result->UncheckedAppend(flexFlowShorthand());
        break;
    }
    case CSSPropertyID::kFontStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantLigatures: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantCaps: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantNumeric: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantEastAsian: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantAlternates: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantPosition: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontVariantEmoji: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed());
        result->UncheckedAppend(fontVariantShorthand());
        break;
    }
    case CSSPropertyID::kFontWeight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontStretch: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontSize: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kLineHeight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontFamily: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontOpticalSizing: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontSizeAdjust: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontKerning: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontFeatureSettings: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontVariationSettings: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed());
        result->UncheckedAppend(fontShorthand());
        break;
    }
    case CSSPropertyID::kFontSynthesisWeight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontSynthesis).IsWebExposed());
        result->UncheckedAppend(fontSynthesisShorthand());
        break;
    }
    case CSSPropertyID::kFontSynthesisStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontSynthesis).IsWebExposed());
        result->UncheckedAppend(fontSynthesisShorthand());
        break;
    }
    case CSSPropertyID::kFontSynthesisSmallCaps: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kFontSynthesis).IsWebExposed());
        result->UncheckedAppend(fontSynthesisShorthand());
        break;
    }
    case CSSPropertyID::kRowGap: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGap).IsWebExposed());
        result->UncheckedAppend(gapShorthand());
        break;
    }
    case CSSPropertyID::kColumnGap: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGap).IsWebExposed());
        result->UncheckedAppend(gapShorthand());
        break;
    }
    case CSSPropertyID::kGridTemplateRows: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed());
        result->UncheckedAppend(gridShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridTemplate).IsWebExposed());
        result->UncheckedAppend(gridTemplateShorthand());
        break;
    }
    case CSSPropertyID::kGridTemplateColumns: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed());
        result->UncheckedAppend(gridShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridTemplate).IsWebExposed());
        result->UncheckedAppend(gridTemplateShorthand());
        break;
    }
    case CSSPropertyID::kGridTemplateAreas: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed());
        result->UncheckedAppend(gridShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridTemplate).IsWebExposed());
        result->UncheckedAppend(gridTemplateShorthand());
        break;
    }
    case CSSPropertyID::kGridAutoFlow: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed());
        result->UncheckedAppend(gridShorthand());
        break;
    }
    case CSSPropertyID::kGridAutoRows: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed());
        result->UncheckedAppend(gridShorthand());
        break;
    }
    case CSSPropertyID::kGridAutoColumns: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed());
        result->UncheckedAppend(gridShorthand());
        break;
    }
    case CSSPropertyID::kGridRowStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed());
        result->UncheckedAppend(gridAreaShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridRow).IsWebExposed());
        result->UncheckedAppend(gridRowShorthand());
        break;
    }
    case CSSPropertyID::kGridColumnStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed());
        result->UncheckedAppend(gridAreaShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridColumn).IsWebExposed());
        result->UncheckedAppend(gridColumnShorthand());
        break;
    }
    case CSSPropertyID::kGridRowEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed());
        result->UncheckedAppend(gridAreaShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridRow).IsWebExposed());
        result->UncheckedAppend(gridRowShorthand());
        break;
    }
    case CSSPropertyID::kGridColumnEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed());
        result->UncheckedAppend(gridAreaShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kGridColumn).IsWebExposed());
        result->UncheckedAppend(gridColumnShorthand());
        break;
    }
    case CSSPropertyID::kTop: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed());
        result->UncheckedAppend(insetShorthand());
        break;
    }
    case CSSPropertyID::kRight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed());
        result->UncheckedAppend(insetShorthand());
        break;
    }
    case CSSPropertyID::kBottom: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed());
        result->UncheckedAppend(insetShorthand());
        break;
    }
    case CSSPropertyID::kLeft: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed());
        result->UncheckedAppend(insetShorthand());
        break;
    }
    case CSSPropertyID::kInsetBlockStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInsetBlock).IsWebExposed());
        result->UncheckedAppend(insetBlockShorthand());
        break;
    }
    case CSSPropertyID::kInsetBlockEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInsetBlock).IsWebExposed());
        result->UncheckedAppend(insetBlockShorthand());
        break;
    }
    case CSSPropertyID::kInsetInlineStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInsetInline).IsWebExposed());
        result->UncheckedAppend(insetInlineShorthand());
        break;
    }
    case CSSPropertyID::kInsetInlineEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kInsetInline).IsWebExposed());
        result->UncheckedAppend(insetInlineShorthand());
        break;
    }
    case CSSPropertyID::kListStylePosition: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kListStyle).IsWebExposed());
        result->UncheckedAppend(listStyleShorthand());
        break;
    }
    case CSSPropertyID::kListStyleImage: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kListStyle).IsWebExposed());
        result->UncheckedAppend(listStyleShorthand());
        break;
    }
    case CSSPropertyID::kListStyleType: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kListStyle).IsWebExposed());
        result->UncheckedAppend(listStyleShorthand());
        break;
    }
    case CSSPropertyID::kMarginTop: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed());
        result->UncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyID::kMarginRight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed());
        result->UncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyID::kMarginBottom: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed());
        result->UncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyID::kMarginLeft: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed());
        result->UncheckedAppend(marginShorthand());
        break;
    }
    case CSSPropertyID::kMarginBlockStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarginBlock).IsWebExposed());
        result->UncheckedAppend(marginBlockShorthand());
        break;
    }
    case CSSPropertyID::kMarginBlockEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarginBlock).IsWebExposed());
        result->UncheckedAppend(marginBlockShorthand());
        break;
    }
    case CSSPropertyID::kMarginInlineStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarginInline).IsWebExposed());
        result->UncheckedAppend(marginInlineShorthand());
        break;
    }
    case CSSPropertyID::kMarginInlineEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarginInline).IsWebExposed());
        result->UncheckedAppend(marginInlineShorthand());
        break;
    }
    case CSSPropertyID::kMarkerStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarker).IsWebExposed());
        result->UncheckedAppend(markerShorthand());
        break;
    }
    case CSSPropertyID::kMarkerMid: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarker).IsWebExposed());
        result->UncheckedAppend(markerShorthand());
        break;
    }
    case CSSPropertyID::kMarkerEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMarker).IsWebExposed());
        result->UncheckedAppend(markerShorthand());
        break;
    }
    case CSSPropertyID::kMaskImage: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskPositionX: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kMaskPosition).IsWebExposed());
        result->UncheckedAppend(maskPositionShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskPositionY: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kMaskPosition).IsWebExposed());
        result->UncheckedAppend(maskPositionShorthand());
        break;
    }
    case CSSPropertyID::kMaskSize: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kMaskRepeat: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kMaskOrigin: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kMaskClip: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kMaskComposite: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kMaskMode: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kMask).IsWebExposed());
        result->UncheckedAppend(maskShorthand());
        break;
    }
    case CSSPropertyID::kMasonryTrackStart: {
        if (CSSProperty::Get(CSSPropertyID::kMasonryTrack).IsWebExposed())
            result->UncheckedAppend(masonryTrackShorthand());
        break;
    }
    case CSSPropertyID::kMasonryTrackEnd: {
        if (CSSProperty::Get(CSSPropertyID::kMasonryTrack).IsWebExposed())
            result->UncheckedAppend(masonryTrackShorthand());
        break;
    }
    case CSSPropertyID::kOffsetPosition: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed());
        result->UncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyID::kOffsetPath: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed());
        result->UncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyID::kOffsetDistance: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed());
        result->UncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyID::kOffsetRotate: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed());
        result->UncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyID::kOffsetAnchor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed());
        result->UncheckedAppend(offsetShorthand());
        break;
    }
    case CSSPropertyID::kOutlineColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOutline).IsWebExposed());
        result->UncheckedAppend(outlineShorthand());
        break;
    }
    case CSSPropertyID::kOutlineStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOutline).IsWebExposed());
        result->UncheckedAppend(outlineShorthand());
        break;
    }
    case CSSPropertyID::kOutlineWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOutline).IsWebExposed());
        result->UncheckedAppend(outlineShorthand());
        break;
    }
    case CSSPropertyID::kOverflowX: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOverflow).IsWebExposed());
        result->UncheckedAppend(overflowShorthand());
        break;
    }
    case CSSPropertyID::kOverflowY: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOverflow).IsWebExposed());
        result->UncheckedAppend(overflowShorthand());
        break;
    }
    case CSSPropertyID::kOverscrollBehaviorX: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOverscrollBehavior).IsWebExposed());
        result->UncheckedAppend(overscrollBehaviorShorthand());
        break;
    }
    case CSSPropertyID::kOverscrollBehaviorY: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kOverscrollBehavior).IsWebExposed());
        result->UncheckedAppend(overscrollBehaviorShorthand());
        break;
    }
    case CSSPropertyID::kPaddingTop: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed());
        result->UncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyID::kPaddingRight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed());
        result->UncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyID::kPaddingBottom: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed());
        result->UncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyID::kPaddingLeft: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed());
        result->UncheckedAppend(paddingShorthand());
        break;
    }
    case CSSPropertyID::kPaddingBlockStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPaddingBlock).IsWebExposed());
        result->UncheckedAppend(paddingBlockShorthand());
        break;
    }
    case CSSPropertyID::kPaddingBlockEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPaddingBlock).IsWebExposed());
        result->UncheckedAppend(paddingBlockShorthand());
        break;
    }
    case CSSPropertyID::kPaddingInlineStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPaddingInline).IsWebExposed());
        result->UncheckedAppend(paddingInlineShorthand());
        break;
    }
    case CSSPropertyID::kPaddingInlineEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPaddingInline).IsWebExposed());
        result->UncheckedAppend(paddingInlineShorthand());
        break;
    }
    case CSSPropertyID::kBreakAfter: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitColumnBreakAfter).IsWebExposed());
        result->UncheckedAppend(webkitColumnBreakAfterShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kPageBreakAfter).IsWebExposed());
        result->UncheckedAppend(pageBreakAfterShorthand());
        break;
    }
    case CSSPropertyID::kBreakBefore: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitColumnBreakBefore).IsWebExposed());
        result->UncheckedAppend(webkitColumnBreakBeforeShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kPageBreakBefore).IsWebExposed());
        result->UncheckedAppend(pageBreakBeforeShorthand());
        break;
    }
    case CSSPropertyID::kBreakInside: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitColumnBreakInside).IsWebExposed());
        result->UncheckedAppend(webkitColumnBreakInsideShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kPageBreakInside).IsWebExposed());
        result->UncheckedAppend(pageBreakInsideShorthand());
        break;
    }
    case CSSPropertyID::kAlignContent: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPlaceContent).IsWebExposed());
        result->UncheckedAppend(placeContentShorthand());
        break;
    }
    case CSSPropertyID::kJustifyContent: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPlaceContent).IsWebExposed());
        result->UncheckedAppend(placeContentShorthand());
        break;
    }
    case CSSPropertyID::kAlignItems: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPlaceItems).IsWebExposed());
        result->UncheckedAppend(placeItemsShorthand());
        break;
    }
    case CSSPropertyID::kJustifyItems: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPlaceItems).IsWebExposed());
        result->UncheckedAppend(placeItemsShorthand());
        break;
    }
    case CSSPropertyID::kAlignSelf: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPlaceSelf).IsWebExposed());
        result->UncheckedAppend(placeSelfShorthand());
        break;
    }
    case CSSPropertyID::kJustifySelf: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPlaceSelf).IsWebExposed());
        result->UncheckedAppend(placeSelfShorthand());
        break;
    }
    case CSSPropertyID::kPositionTryOrder: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPositionTry).IsWebExposed());
        result->UncheckedAppend(positionTryShorthand());
        break;
    }
    case CSSPropertyID::kPositionTryFallbacks: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kPositionTry).IsWebExposed());
        result->UncheckedAppend(positionTryShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginTop: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed());
        result->UncheckedAppend(scrollMarginShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginRight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed());
        result->UncheckedAppend(scrollMarginShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginBottom: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed());
        result->UncheckedAppend(scrollMarginShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginLeft: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed());
        result->UncheckedAppend(scrollMarginShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginBlockStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMarginBlock).IsWebExposed());
        result->UncheckedAppend(scrollMarginBlockShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginBlockEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMarginBlock).IsWebExposed());
        result->UncheckedAppend(scrollMarginBlockShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginInlineStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMarginInline).IsWebExposed());
        result->UncheckedAppend(scrollMarginInlineShorthand());
        break;
    }
    case CSSPropertyID::kScrollMarginInlineEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollMarginInline).IsWebExposed());
        result->UncheckedAppend(scrollMarginInlineShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingTop: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed());
        result->UncheckedAppend(scrollPaddingShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingRight: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed());
        result->UncheckedAppend(scrollPaddingShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingBottom: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed());
        result->UncheckedAppend(scrollPaddingShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingLeft: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed());
        result->UncheckedAppend(scrollPaddingShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingBlockStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPaddingBlock).IsWebExposed());
        result->UncheckedAppend(scrollPaddingBlockShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingBlockEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPaddingBlock).IsWebExposed());
        result->UncheckedAppend(scrollPaddingBlockShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingInlineStart: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPaddingInline).IsWebExposed());
        result->UncheckedAppend(scrollPaddingInlineShorthand());
        break;
    }
    case CSSPropertyID::kScrollPaddingInlineEnd: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kScrollPaddingInline).IsWebExposed());
        result->UncheckedAppend(scrollPaddingInlineShorthand());
        break;
    }
    case CSSPropertyID::kScrollStartBlock: {
        if (CSSProperty::Get(CSSPropertyID::kScrollStart).IsWebExposed())
            result->UncheckedAppend(scrollStartShorthand());
        break;
    }
    case CSSPropertyID::kScrollStartInline: {
        if (CSSProperty::Get(CSSPropertyID::kScrollStart).IsWebExposed())
            result->UncheckedAppend(scrollStartShorthand());
        break;
    }
    case CSSPropertyID::kScrollTimelineName: {
        if (CSSProperty::Get(CSSPropertyID::kScrollTimeline).IsWebExposed())
            result->UncheckedAppend(scrollTimelineShorthand());
        break;
    }
    case CSSPropertyID::kScrollTimelineAxis: {
        if (CSSProperty::Get(CSSPropertyID::kScrollTimeline).IsWebExposed())
            result->UncheckedAppend(scrollTimelineShorthand());
        break;
    }
    case CSSPropertyID::kTextBoxTrim: {
        if (CSSProperty::Get(CSSPropertyID::kTextBox).IsWebExposed())
            result->UncheckedAppend(textBoxShorthand());
        break;
    }
    case CSSPropertyID::kTextBoxEdge: {
        if (CSSProperty::Get(CSSPropertyID::kTextBox).IsWebExposed())
            result->UncheckedAppend(textBoxShorthand());
        break;
    }
    case CSSPropertyID::kTextDecorationLine: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed());
        result->UncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyID::kTextDecorationThickness: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed());
        result->UncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyID::kTextDecorationStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed());
        result->UncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyID::kTextDecorationColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed());
        result->UncheckedAppend(textDecorationShorthand());
        break;
    }
    case CSSPropertyID::kTextEmphasisStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextEmphasis).IsWebExposed());
        result->UncheckedAppend(textEmphasisShorthand());
        break;
    }
    case CSSPropertyID::kTextEmphasisColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextEmphasis).IsWebExposed());
        result->UncheckedAppend(textEmphasisShorthand());
        break;
    }
    case CSSPropertyID::kTextAutospace: {
        if (CSSProperty::Get(CSSPropertyID::kTextSpacing).IsWebExposed())
            result->UncheckedAppend(textSpacingShorthand());
        break;
    }
    case CSSPropertyID::kTextSpacingTrim: {
        if (CSSProperty::Get(CSSPropertyID::kTextSpacing).IsWebExposed())
            result->UncheckedAppend(textSpacingShorthand());
        break;
    }
    case CSSPropertyID::kTextWrapMode: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextWrap).IsWebExposed());
        result->UncheckedAppend(textWrapShorthand());
        DCHECK(CSSProperty::Get(CSSPropertyID::kWhiteSpace).IsWebExposed());
        result->UncheckedAppend(whiteSpaceShorthand());
        break;
    }
    case CSSPropertyID::kTextWrapStyle: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTextWrap).IsWebExposed());
        result->UncheckedAppend(textWrapShorthand());
        break;
    }
    case CSSPropertyID::kTransitionProperty: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed());
        result->UncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyID::kTransitionDuration: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed());
        result->UncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyID::kTransitionTimingFunction: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed());
        result->UncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyID::kTransitionDelay: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed());
        result->UncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyID::kTransitionBehavior: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed());
        result->UncheckedAppend(transitionShorthand());
        break;
    }
    case CSSPropertyID::kViewTimelineName: {
        if (CSSProperty::Get(CSSPropertyID::kViewTimeline).IsWebExposed())
            result->UncheckedAppend(viewTimelineShorthand());
        break;
    }
    case CSSPropertyID::kViewTimelineAxis: {
        if (CSSProperty::Get(CSSPropertyID::kViewTimeline).IsWebExposed())
            result->UncheckedAppend(viewTimelineShorthand());
        break;
    }
    case CSSPropertyID::kViewTimelineInset: {
        if (CSSProperty::Get(CSSPropertyID::kViewTimeline).IsWebExposed())
            result->UncheckedAppend(viewTimelineShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageSource: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed());
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageSlice: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed());
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed());
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageOutset: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed());
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageRepeat: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed());
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
        break;
    }
    case CSSPropertyID::kWebkitTextStrokeWidth: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitTextStroke).IsWebExposed());
        result->UncheckedAppend(webkitTextStrokeShorthand());
        break;
    }
    case CSSPropertyID::kWebkitTextStrokeColor: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWebkitTextStroke).IsWebExposed());
        result->UncheckedAppend(webkitTextStrokeShorthand());
        break;
    }
    case CSSPropertyID::kWhiteSpaceCollapse: {
        DCHECK(CSSProperty::Get(CSSPropertyID::kWhiteSpace).IsWebExposed());
        result->UncheckedAppend(whiteSpaceShorthand());
        break;
    }
    default:
        break;
    }
}

} // namespace blink
